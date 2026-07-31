/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/diag/trace.h"
#include "micro-os-plus/micro-test-plus.h"

#include <cassert>
#include <cstring>
#include <string_view>
#include <stdio.h>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
// Silence warnings on buffer[], they are asserted.
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-value"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// Ensure the asserts are always enabled.
#undef NDEBUG

// ----------------------------------------------------------------------------

namespace micro_os_plus::trace::detail
{
  /**
   * @brief Policy class for the production trace instance.
   * @details
   * The user must provide a definition of `initialise()`, `write()`,
   * and `flush()` for this class (typically in a single .cpp file,
   * once per application/platform).
   *
   * `implementation` is not a template; it has no member data and is
   * never instantiated as an object. Its static methods are looked up
   * by `tracer<implementation>` and are otherwise ordinary, non-template
   * member functions, so there is no instantiation-order hazard
   * between their declaration here and their definition elsewhere.
   */
  class testing_implementation
  {
  public:
    static void
    initialise (void) noexcept;

    static ssize_t
    write (const void* buf, std::size_t nbyte) noexcept;

    static void
    flush (void) noexcept;
  };

  template class tracer<testing_implementation>;

} // namespace micro_os_plus::trace::detail

// ----------------------------------------------------------------------------

static char buffer[1024];
static std::size_t count;

static constexpr std::size_t initial_count = 999999;
static constexpr char flush_mark = -17;

namespace micro_os_plus::trace::detail
{
  void
  testing_implementation::initialise (void) noexcept
  {
    count = 0;
    ::memset (buffer, 0, sizeof (buffer));
  }

  ssize_t
  testing_implementation::write (const void* buf, std::size_t nbyte) noexcept
  {
    assert (count + nbyte < sizeof (buffer));
    ::memcpy (&buffer[count], buf, nbyte);

    count += nbyte;

    return static_cast<ssize_t> (nbyte);
  }

  void
  testing_implementation::flush (void) noexcept
  {
    assert (count < sizeof (buffer));
    buffer[count] = flush_mark;
  }
} // namespace micro_os_plus::trace::detail

// ----------------------------------------------------------------------------

using trace_testing
    = trace::detail::tracer<trace::detail::testing_implementation>;

namespace mt = micro_os_plus::micro_test_plus;

int
main (int argc, char* argv[])
{
  mt::runner tr;
  auto& ts = tr.initialise (argc, argv, "diag::trace");

  count = initial_count;
  strcpy (buffer, "xxx");

  ts.test ("Check trace_testing::initialise", [] (auto& t)
    {
      t.expect (mt::eq (count, initial_count)) << "initial count";
      t.expect (mt::eq (buffer[0], 'x')) << "initial content x";

      trace_testing::initialise ();
      t.expect (mt::eq (count, 0)) << "count initialised";
      t.expect (mt::eq (buffer[0], '\0')) << "initial content cleared";
    });

  ts.test ("Check trace_testing::putchar", [] (auto& t)
    {
      std::size_t prev_count = count;
      trace_testing::putchar ('c');

      t.expect (mt::eq ((count - prev_count), 1)) << "count increased by 1";

      assert (prev_count < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 'c')) << "buffer has c";
    });

  ts.test ("Check trace_testing::puts", [] (auto& t)
    {
      std::size_t prev_count = count;
      trace_testing::puts ("s");

      t.expect (mt::eq ((count - prev_count), 2)) << "count increased by 2";

      assert (prev_count + 1 < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 's')) << "buffer has s";
      t.expect (mt::eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
    });

  ts.test ("Check trace_testing::printf", [] (auto& t)
    {
      std::size_t prev_count = count;
      trace_testing::printf ("%s", "p");

      t.expect (mt::eq ((count - prev_count), 1)) << "count increased by 1";

      assert (prev_count < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 'p')) << "buffer has p";

      prev_count = count;
      trace_testing::printf ("%s\n", "q");

      t.expect (mt::eq ((count - prev_count), 2)) << "count increased by 2";

      assert (prev_count + 1 < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 'q')) << "buffer has q";
      t.expect (mt::eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
    });

  ts.test ("Check trace_testing::dump_args", [] (auto& t)
    {
      const char* argv_[3];
      argv_[0] = "n";
      argv_[1] = "1";
      argv_[2] = "2";

      std::size_t prev_count = count;
      trace_testing::dump_args (3, const_cast<char**> (argv_));

      std::string_view expected_main{
        "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
      };
      t.expect (mt::eq ((count - prev_count), expected_main.length ()))
          << "count increased correctly";

      assert (prev_count + expected_main.size () < sizeof (buffer));
      t.expect (
          mt::eq (std::string_view{ &buffer[prev_count] }, expected_main))
          << "buffer has main";

      prev_count = count;
      trace_testing::dump_args (3, const_cast<char**> (argv_), "args");

      std::string_view expected_args{
        "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
      };
      t.expect (mt::eq ((count - prev_count), expected_args.length ()))
          << "count increased correctly";

      assert (prev_count + expected_args.size () < sizeof (buffer));
      t.expect (
          mt::eq (std::string_view{ &buffer[prev_count] }, expected_args))
          << "buffer has main";
    });

  ts.test ("Check trace_testing::flush", [] (auto& t)
    {
      trace_testing::flush ();

      assert (count < sizeof (buffer));
      t.expect (mt::eq (buffer[count], flush_mark)) << "flush mark found";
    });

#if 0
  count = initial_count;
  strcpy (buffer, "xxx");

  ts.test ("Check micro_os_plus_trace_initialise", [] (auto& t)
    {
      t.expect (mt::eq (count, initial_count)) << "initial count";
      t.expect (mt::eq (buffer[0], 'x')) << "initial content x";

      micro_os_plus_trace_initialise ();
      t.expect (mt::eq (count, 0)) << "count initialised";
      t.expect (mt::eq (buffer[0], '\0')) << "initial content cleared";
    });

  ts.test ("Check micro_os_plus_trace_putchar", [] (auto& t)
    {
      std::size_t prev_count = count;
      micro_os_plus_trace_putchar ('c');

      t.expect (mt::eq ((count - prev_count), 1)) << "count increased by 1";

      assert (prev_count < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 'c')) << "buffer has c";
    });

  ts.test ("Check micro_os_plus_trace_puts", [] (auto& t)
    {
      std::size_t prev_count = count;
      micro_os_plus_trace_puts_testing ("s");

      t.expect (mt::eq ((count - prev_count), 2)) << "count increased by 2";

      assert (prev_count + 1 < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 's')) << "buffer has s";
      t.expect (mt::eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
    });

  ts.test ("Check micro_os_plus_trace_printf", [] (auto& t)
    {
      std::size_t prev_count = count;
      micro_os_plus_trace_printf_testing ("%s", "p");

      t.expect (mt::eq ((count - prev_count), 1)) << "count increased by 1";

      assert (prev_count < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 'p')) << "buffer has p";

      prev_count = count;
      micro_os_plus_trace_printf_testing ("%s\n", "q");

      t.expect (mt::eq ((count - prev_count), 2)) << "count increased by 2";

      assert (prev_count + 1 < sizeof (buffer));
      t.expect (mt::eq (buffer[prev_count], 'q')) << "buffer has q";
      t.expect (mt::eq (buffer[prev_count + 1], '\n')) << "buffer has \\n";
    });

  ts.test ("Check micro_os_plus_trace_dump_args", [] (auto& t)
    {
      const char* argv_[3];
      argv_[0] = "n";
      argv_[1] = "1";
      argv_[2] = "2";

      std::size_t prev_count = count;
      trace_testing::dump_args (3, const_cast<char**> (argv_));

      std::string_view expected_main{
        "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
      };
      t.expect (mt::eq ((count - prev_count), expected_main.length ()))
          << "count increased correctly";

      assert (prev_count + expected_main.size () < sizeof (buffer));
      t.expect (mt::eq (std::string_view{ &buffer[prev_count] }, expected_main))
          << "buffer has main";

      prev_count = count;
      trace_testing::dump_args (3, const_cast<char**> (argv_), "args");

      std::string_view expected_args{
        "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n"
      };
      t.expect (mt::eq ((count - prev_count), expected_args.length ()))
          << "count increased correctly";

      assert (prev_count + expected_args.size () < sizeof (buffer));
      t.expect (mt::eq (std::string_view{ &buffer[prev_count] }, expected_args))
          << "buffer has main";
    });

  ts.test ("Check micro_os_plus_trace_flush", [] (auto& t)
    {
      micro_os_plus_trace_flush_testing ();

      assert (count < sizeof (buffer));
      t.expect (mt::eq (buffer[count], flush_mark)) << "flush mark found";
    });
#endif // 0-1

  return tr.exit_code ();
}

// ----------------------------------------------------------------------------
