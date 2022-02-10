/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
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
#include <stdio.h>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push
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

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

void
test_case_inits (micro_test_plus::session& t);

void
test_case_putchar (micro_test_plus::session& t);

void
test_case_puts (micro_test_plus::session& t);

void
test_case_printf (micro_test_plus::session& t);

void
test_case_dump_args (micro_test_plus::session& t);

void
test_case_flush (micro_test_plus::session& t);

void
test_case_inits_c (micro_test_plus::session& t);

void
test_case_putchar_c (micro_test_plus::session& t);

void
test_case_puts_c (micro_test_plus::session& t);

void
test_case_printf_c (micro_test_plus::session& t);

void
test_case_dump_args_c (micro_test_plus::session& t);

void
test_case_flush_c (micro_test_plus::session& t);

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  micro_test_plus::session t (argc, argv);

  t.start_suite ("diag::trace test");

  count = initial_count;
  strcpy (buffer, "xxx");

  t.run_test_case (test_case_inits, "Check trace::initialize");
  t.run_test_case (test_case_putchar, "Check trace::putchar");
  t.run_test_case (test_case_puts, "Check trace::puts");
  t.run_test_case (test_case_printf, "Check trace::printf");
  t.run_test_case (test_case_dump_args, "Check trace::dump_args");
  t.run_test_case (test_case_flush, "Check trace::flush");

  count = initial_count;
  strcpy (buffer, "xxx");

  t.run_test_case (test_case_inits_c, "Check micro_os_plus_trace_initialize");
  t.run_test_case (test_case_putchar_c, "Check micro_os_plus_trace_putchar");
  t.run_test_case (test_case_puts_c, "Check micro_os_plus_trace_puts");
  t.run_test_case (test_case_printf_c, "Check micro_os_plus_trace_printf");
  t.run_test_case (test_case_dump_args_c,
                   "Check micro_os_plus_trace_dump_args");
  t.run_test_case (test_case_flush, "Check micro_os_plus_trace_flush");

  return t.result ();
}

// ----------------------------------------------------------------------------

void
test_case_inits (micro_test_plus::session& t)
{
  MTP_EXPECT_EQ (t, count, initial_count, "initial count");
  MTP_EXPECT_EQ (t, buffer[0], 'x', "initial content x");

  trace::initialize ();
  MTP_EXPECT_EQ (t, count, 0, "count initialised");
  MTP_EXPECT_EQ (t, buffer[0], '\0', "initial content cleared");
}

void
test_case_inits_c (micro_test_plus::session& t)
{
  MTP_EXPECT_EQ (t, count, initial_count, "initial count");
  MTP_EXPECT_EQ (t, buffer[0], 'x', "initial content x");

  micro_os_plus_trace_initialize ();
  MTP_EXPECT_EQ (t, count, 0, "count initialised");
  MTP_EXPECT_EQ (t, buffer[0], '\0', "initial content cleared");
}

void
test_case_putchar (micro_test_plus::session& t)
{
  int prev_count = count;
  trace::putchar ('c');

  MTP_EXPECT_EQ (t, (count - prev_count), 1, "count increased by 1");
  MTP_EXPECT_EQ (t, buffer[prev_count], 'c', "buffer has c");
}

void
test_case_putchar_c (micro_test_plus::session& t)
{
  int prev_count = count;
  micro_os_plus_trace_putchar ('c');

  MTP_EXPECT_EQ (t, (count - prev_count), 1, "count increased by 1");
  MTP_EXPECT_EQ (t, buffer[prev_count], 'c', "buffer has c");
}

void
test_case_puts (micro_test_plus::session& t)
{
  int prev_count = count;
  trace::puts ("s");

  MTP_EXPECT_EQ (t, (count - prev_count), 2, "count increased by 2");
  MTP_EXPECT_EQ (t, buffer[prev_count], 's', "buffer has s");
  MTP_EXPECT_EQ (t, buffer[prev_count + 1], '\n', "buffer has \\n");
}

void
test_case_puts_c (micro_test_plus::session& t)
{
  int prev_count = count;
  micro_os_plus_trace_puts ("s");

  MTP_EXPECT_EQ (t, (count - prev_count), 2, "count increased by 2");
  MTP_EXPECT_EQ (t, buffer[prev_count], 's', "buffer has s");
  MTP_EXPECT_EQ (t, buffer[prev_count + 1], '\n', "buffer has \\n");
}

void
test_case_printf (micro_test_plus::session& t)
{
  int prev_count = count;
  trace::printf ("%s", "p");

  MTP_EXPECT_EQ (t, (count - prev_count), 1, "count increased by 1");
  MTP_EXPECT_EQ (t, buffer[prev_count], 'p', "buffer has p");

  prev_count = count;
  trace::printf ("%s\n", "q");

  MTP_EXPECT_EQ (t, (count - prev_count), 2, "count increased by 2");
  MTP_EXPECT_EQ (t, buffer[prev_count], 'q', "buffer has q");
  MTP_EXPECT_EQ (t, buffer[prev_count + 1], '\n', "buffer has \\n");
}

void
test_case_printf_c (micro_test_plus::session& t)
{
  int prev_count = count;
  micro_os_plus_trace_printf ("%s", "p");

  MTP_EXPECT_EQ (t, (count - prev_count), 1, "count increased by 1");
  MTP_EXPECT_EQ (t, buffer[prev_count], 'p', "buffer has p");

  prev_count = count;
  micro_os_plus_trace_printf ("%s\n", "q");

  MTP_EXPECT_EQ (t, (count - prev_count), 2, "count increased by 2");
  MTP_EXPECT_EQ (t, buffer[prev_count], 'q', "buffer has q");
  MTP_EXPECT_EQ (t, buffer[prev_count + 1], '\n', "buffer has \\n");
}

void
test_case_dump_args (micro_test_plus::session& t)
{
  const char* argv[3];
  argv[0] = "n";
  argv[1] = "1";
  argv[2] = "2";

  int prev_count = count;
  trace::dump_args (3, const_cast<char**> (argv));

  const char expected_main[] = "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n";
  MTP_EXPECT_EQ (t, (count - prev_count),
                 static_cast<int> (strlen (expected_main)),
                 "count increased correctly");
  MTP_EXPECT_EQ (t, &buffer[prev_count], expected_main, "buffer has main");

  prev_count = count;
  trace::dump_args (3, const_cast<char**> (argv), "args");

  const char expected_args[] = "args(argc=3, argv=[\"n\", \"1\", \"2\"])\n";
  MTP_EXPECT_EQ (t, (count - prev_count),
                 static_cast<int> (strlen (expected_args)),
                 "count increased correctly");
  MTP_EXPECT_EQ (t, &buffer[prev_count], expected_args, "buffer has main");
}

void
test_case_dump_args_c (micro_test_plus::session& t)
{
  const char* argv[3];
  argv[0] = "n";
  argv[1] = "1";
  argv[2] = "2";

  int prev_count = count;
  micro_os_plus_trace_dump_args (3, const_cast<char**> (argv));

  const char expected_main[] = "main(argc=3, argv=[\"n\", \"1\", \"2\"])\n";
  MTP_EXPECT_EQ (t, (count - prev_count),
                 static_cast<int> (strlen (expected_main)),
                 "count increased correctly");
  MTP_EXPECT_EQ (t, &buffer[prev_count], expected_main, "buffer has main");
}

void
test_case_flush (micro_test_plus::session& t)
{
  trace::flush ();
  MTP_EXPECT_EQ (t, buffer[count], flush_mark, "flush mark found");
}

void
test_case_flush_c (micro_test_plus::session& t)
{
  micro_os_plus_trace_flush ();
  MTP_EXPECT_EQ (t, buffer[count], flush_mark, "flush mark found");
}

// ----------------------------------------------------------------------------
