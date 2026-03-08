/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
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
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wunused-value"
#elif defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
// Silence warnings on buffer[], they are asserted.
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif

// Ensure the asserts are always enabled.
#undef NDEBUG

static char buffer[1024];
static std::size_t count;

static constexpr std::size_t initial_count = 999999;
static constexpr char flush_mark = -17;

namespace micro_os_plus::trace_testing
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
    assert (count + nbyte < sizeof (buffer));
    ::memcpy (&buffer[count], buf, nbyte);

    count += nbyte;

    return static_cast<ssize_t> (nbyte);
  }

  void
  flush (void)
  {
    assert (count < sizeof (buffer));
    buffer[count] = flush_mark;
  }
} // namespace micro_os_plus::trace_testing

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  using namespace micro_test_plus;

  initialize (argc, argv, "diag::trace");

  count = initial_count;
  strcpy (buffer, "xxx");

  test_case ("Check trace_testing::initialize", [] {
    expect (eq (count, initial_count)) << "initial count";
    expect (eq (buffer[0], 'x')) << "initial content x";

    trace_testing::initialize ();
    expect (eq (count, 0)) << "count initialised";
    expect (eq (buffer[0], '\0')) << "initial content cleared";
  });

  test_case ("Check trace_testing::putchar", [] {
    std::size_t prev_count = count;
    trace_testing::putchar ('c');

    expect (eq ((count - prev_count), 1)) << "count increased by 1";

    assert (prev_count < sizeof (buffer));
    expect (eq (buffer[prev_count], 'c')) << "buffer has c";
  });

  test_case ("Check trace_testing::puts", [] {
    std::size_t prev_count = count;
    trace_testing::puts ("s");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";

    assert (prev_count + 1 < sizeof (buffer));
    expect (eq (buffer[prev_count], 's')) << "buffer has s";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check trace_testing::printf", [] {
    std::size_t prev_count = count;
    trace_testing::printf ("%s", "p");

    expect (eq ((count - prev_count), 1)) << "count increased by 1";

    assert (prev_count < sizeof (buffer));
    expect (eq (buffer[prev_count], 'p')) << "buffer has p";

    prev_count = count;
    trace_testing::printf ("%s\n", "q");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";

    assert (prev_count + 1 < sizeof (buffer));
    expect (eq (buffer[prev_count], 'q')) << "buffer has q";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check trace_testing::dump_args", [] {
    const char* argv_[3];
    argv_[0] = "n";
    argv_[1] = "1";
    argv_[2] = "2";

    std::size_t prev_count = count;
    trace_testing::dump_args (3, const_cast<char**> (argv_));

    std::string_view expected_main{
      "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_main.length ()))
        << "count increased correctly";

    assert (prev_count + expected_main.size () < sizeof (buffer));
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_main))
        << "buffer has main";

    prev_count = count;
    trace_testing::dump_args (3, const_cast<char**> (argv_), "args");

    std::string_view expected_args{
      "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_args.length ()))
        << "count increased correctly";

    assert (prev_count + expected_args.size () < sizeof (buffer));
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_args))
        << "buffer has main";
  });

  test_case ("Check trace_testing::flush", [] {
    trace_testing::flush ();

    assert (count < sizeof (buffer));
    expect (eq (buffer[count], flush_mark)) << "flush mark found";
  });

  count = initial_count;
  strcpy (buffer, "xxx");

  test_case ("Check micro_os_plus_trace_initialize", [] {
    expect (eq (count, initial_count)) << "initial count";
    expect (eq (buffer[0], 'x')) << "initial content x";

    micro_os_plus_trace_initialize_testing ();
    expect (eq (count, 0)) << "count initialised";
    expect (eq (buffer[0], '\0')) << "initial content cleared";
  });

  test_case ("Check micro_os_plus_trace_putchar", [] {
    std::size_t prev_count = count;
    micro_os_plus_trace_putchar_testing ('c');

    expect (eq ((count - prev_count), 1)) << "count increased by 1";

    assert (prev_count < sizeof (buffer));
    expect (eq (buffer[prev_count], 'c')) << "buffer has c";
  });

  test_case ("Check micro_os_plus_trace_puts", [] {
    std::size_t prev_count = count;
    micro_os_plus_trace_puts_testing ("s");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";

    assert (prev_count + 1 < sizeof (buffer));
    expect (eq (buffer[prev_count], 's')) << "buffer has s";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check micro_os_plus_trace_printf", [] {
    std::size_t prev_count = count;
    micro_os_plus_trace_printf_testing ("%s", "p");

    expect (eq ((count - prev_count), 1)) << "count increased by 1";

    assert (prev_count < sizeof (buffer));
    expect (eq (buffer[prev_count], 'p')) << "buffer has p";

    prev_count = count;
    micro_os_plus_trace_printf_testing ("%s\n", "q");

    expect (eq ((count - prev_count), 2)) << "count increased by 2";

    assert (prev_count + 1 < sizeof (buffer));
    expect (eq (buffer[prev_count], 'q')) << "buffer has q";
    expect (eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
  });

  test_case ("Check micro_os_plus_trace_dump_args", [] {
    const char* argv_[3];
    argv_[0] = "n";
    argv_[1] = "1";
    argv_[2] = "2";

    std::size_t prev_count = count;
    trace_testing::dump_args (3, const_cast<char**> (argv_));

    std::string_view expected_main{
      "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_main.length ()))
        << "count increased correctly";

    assert (prev_count + expected_main.size () < sizeof (buffer));
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_main))
        << "buffer has main";

    prev_count = count;
    trace_testing::dump_args (3, const_cast<char**> (argv_), "args");

    std::string_view expected_args{
      "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
    };
    expect (eq ((count - prev_count), expected_args.length ()))
        << "count increased correctly";

    assert (prev_count + expected_args.size () < sizeof (buffer));
    expect (eq (std::string_view{ &buffer[prev_count] }, expected_args))
        << "buffer has main";
  });

  test_case ("Check micro_os_plus_trace_flush", [] {
    micro_os_plus_trace_flush_testing ();

    assert (count < sizeof (buffer));
    expect (eq (buffer[count], flush_mark)) << "flush mark found";
  });

  return exit_code ();
}

// ----------------------------------------------------------------------------
