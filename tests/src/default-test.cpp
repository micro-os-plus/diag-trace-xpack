/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2022 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

/*
 * This test checks if the library compiles when MICRO_OS_PLUS_TRACE is defined,
 * and only write() is implemented.
 */

#include <micro-os-plus/diag/trace.h>
#include <unistd.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  trace::initialize ();

  trace::dump_args (argc, argv);

  trace::printf ("Hello %s!\n", "World");
  trace::puts ("one line");
  trace::putchar ('*');

  trace::flush ();

  return 0;
}

// ----------------------------------------------------------------------------

namespace micro_os_plus
{
  namespace trace
  {
    // ------------------------------------------------------------------------

    ssize_t
    write (const void* buf, std::size_t nbyte)
    {
      // 1=STDOUT
      return ::write (1, buf, nbyte);
    }

    // ------------------------------------------------------------------------
  } // namespace trace
} // namespace micro_os_plus

// ----------------------------------------------------------------------------
