/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>
#include <micro-os-plus/diag/trace.h>

#include <cassert>
#include <cstring>
#include <string_view>
#include <stdio.h>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

static char buffer[1024];
static int count;

static constexpr int initial_count = -1;
static constexpr char flush_mark = -17;

namespace micro_os_plus
{
  namespace trace
  {
    void
    initialize (void)
    {
      count = 0;
      ::memset (buffer, 0, sizeof (buffer));
    }

    ssize_t
    write (const void* buf, std::size_t nbyte)
    {
      assert (count >= 0);
      assert (static_cast<std::size_t> (count) + nbyte < sizeof (buffer));
      ::memcpy (&buffer[count], buf, nbyte);
      count += static_cast<int> (nbyte);

      return static_cast<ssize_t> (nbyte);
    }

    void
    flush (void)
    {
      buffer[count] = flush_mark;
    }
  } // namespace trace
} // namespace micro_os_plus

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  using namespace micro_test_plus;

  initialize (argc, argv, "diag::trace");

  count = initial_count;
  strcpy (buffer, "xxx");

  test_case ("Check trace::initialize", [] {
    expect (eq (count, initial_count)) << "initial count";
    expect (eq (buffer[0], 'x')) << "initial content x";

    trace::initialize ();
    expect (eq (count, 0)) << "count initialised";
    expect (eq (buffer[0], '\0')) << "initial content cleared";
  });

  test_case ("Check trace::putchar", [] {
    int prev_count = count;
    trace::putchar ('c');

    expect (eq ((count - prev_count), 1)) << "count increased by 1";
    expect (eq (buffer[prev_count], 'c')) << "buffer has c";
  });

  test_case ("Check trace::puts", [] {
    int prev_count = count;
    trace::puts ("s");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";
    expect (eq (buffer[prev_count], 's')) << "buffer has s";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check trace::printf", [] {
    int prev_count = count;
    trace::printf ("%s", "p");

    expect (eq ((count - prev_count), 1)) << "count increased by 1";
    expect (eq (buffer[prev_count], 'p')) << "buffer has p";

    prev_count = count;
    trace::printf ("%s\n", "q");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";
    expect (eq (buffer[prev_count], 'q')) << "buffer has q";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check trace::dump_args", [] {
    const char* argv_[3];
    argv_[0] = "n";
    argv_[1] = "1";
    argv_[2] = "2";

    int prev_count = count;
    trace::dump_args (3, const_cast<char**> (argv_));

    std::string_view expected_main{
      "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_main.length ()))
        << "count increased correctly";
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_main))
        << "buffer has main";

    prev_count = count;
    trace::dump_args (3, const_cast<char**> (argv_), "args");

    std::string_view expected_args{
      "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_args.length ()))
        << "count increased correctly";
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_args))
        << "buffer has main";
  });

  test_case ("Check trace::flush", [] {
    trace::flush ();
    expect (eq (buffer[count], flush_mark)) << "flush mark found";
  });

  count = initial_count;
  strcpy (buffer, "xxx");

  test_case ("Check micro_os_plus_trace_initialize", [] {
    expect (eq (count, initial_count)) << "initial count";
    expect (eq (buffer[0], 'x')) << "initial content x";

    micro_os_plus_trace_initialize ();
    expect (eq (count, 0)) << "count initialised";
    expect (eq (buffer[0], '\0')) << "initial content cleared";
  });

  test_case ("Check micro_os_plus_trace_putchar", [] {
    int prev_count = count;
    micro_os_plus_trace_putchar ('c');

    expect (eq ((count - prev_count), 1)) << "count increased by 1";
    expect (eq (buffer[prev_count], 'c')) << "buffer has c";
  });

  test_case ("Check micro_os_plus_trace_puts", [] {
    int prev_count = count;
    micro_os_plus_trace_puts ("s");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";
    expect (eq (buffer[prev_count], 's')) << "buffer has s";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check micro_os_plus_trace_printf", [] {
    int prev_count = count;
    micro_os_plus_trace_printf ("%s", "p");

    expect (eq ((count - prev_count), 1)) << "count increased by 1";
    expect (eq (buffer[prev_count], 'p')) << "buffer has p";

    prev_count = count;
    micro_os_plus_trace_printf ("%s\n", "q");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";
    expect (eq (buffer[prev_count], 'q')) << "buffer has q";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check micro_os_plus_trace_dump_args", [] {
    const char* argv_[3];
    argv_[0] = "n";
    argv_[1] = "1";
    argv_[2] = "2";

    int prev_count = count;
    trace::dump_args (3, const_cast<char**> (argv_));

    std::string_view expected_main{
      "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_main.length ()))
        << "count increased correctly";
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_main))
        << "buffer has main";

    prev_count = count;
    trace::dump_args (3, const_cast<char**> (argv_), "args");

    std::string_view expected_args{
      "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_args.length ()))
        << "count increased correctly";
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_args))
        << "buffer has main";
  });

  test_case ("Check micro_os_plus_trace_flush", [] {
    micro_os_plus_trace_flush ();
    expect (eq (buffer[count], flush_mark)) << "flush mark found";
  });

  return exit_code ();
}

// ----------------------------------------------------------------------------
