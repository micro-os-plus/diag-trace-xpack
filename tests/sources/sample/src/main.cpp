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

#if !defined(MICRO_OS_PLUS_TRACE_ENABLED)
#error "MICRO_OS_PLUS_TRACE_ENABLED should be defined"
#endif

#include <micro-os-plus/diag/trace.h>

#include <unistd.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  trace::initialise ();
  trace::dump_args (argc, argv);

  trace::printf ("Hello %s!\n", "C++ World");
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  trace::puts ("one line");
  trace::putchar ('*');

  trace::puts ();
#pragma GCC diagnostic pop
  trace::flush ();

  // --------------------------------------------------------------------------

  // Exercise the C API.
  micro_os_plus_trace_initialise ();
  micro_os_plus_trace_dump_args (argc, argv);

  micro_os_plus_trace_printf ("Hello %s!\n", "C World");
  micro_os_plus_trace_puts ("one line");
  micro_os_plus_trace_putchar ('*');

  micro_os_plus_trace_puts ("");
  micro_os_plus_trace_flush ();

  return 0;
}

// ----------------------------------------------------------------------------
