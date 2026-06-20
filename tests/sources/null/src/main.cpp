/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

/*
 * This test checks if the library compiles when MICRO_OS_PLUS_TRACE is not
 * defined.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_TRACE)
#error "MICRO_OS_PLUS_TRACE should not be defined"
#endif

#include "null.h"

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  // --------------------------------------------------------------------------
  // Exercise the empty C++ API.

  trace::initialise ();

  trace::dump_args (argc, argv);

  trace::printf ("Hello %s!\n", "C++ World");
  trace::puts ("one line");
  trace::putchar ('*');

  trace::flush ();

  // --------------------------------------------------------------------------
  // Exercise the empty C API called from C++.

  micro_os_plus_trace_initialise ();
  micro_os_plus_trace_dump_args (argc, argv);

  micro_os_plus_trace_printf ("Hello %s!\n", "C World");
  micro_os_plus_trace_puts ("one line");
  micro_os_plus_trace_putchar ('*');

  micro_os_plus_trace_puts ("");
  micro_os_plus_trace_flush ();

  // --------------------------------------------------------------------------
  c_api (argc, argv);

  return 0;
}

// ----------------------------------------------------------------------------
