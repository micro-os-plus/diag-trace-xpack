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
// The full implementation of the trace system API.

namespace micro_os_plus
{
  namespace trace
  {
    void
    initialize (void)
    {
      // STDOUT is always available.
    }

    ssize_t
    write (const void* buf, std::size_t nbyte)
    {
      // 1=STDOUT
#pragma GCC diagnostic push
#if defined(__MINGW32__)
// warning: conversion from 'std::size_t' {aka 'long long unsigned int'} to 'unsigned int' may change value [-Wconversion]
#pragma GCC diagnostic ignored "-Wconversion"
#endif
      return ::write (1, buf, nbyte);
#pragma GCC diagnostic pop
    }

    void
    flush (void)
    {
#if !defined(__MINGW32__)
      fsync (1); // Sync STDOUT.
#else
// error: 'fsync' was not declared in this scope
#endif
    }
  } // namespace trace
} // namespace micro_os_plus

// ----------------------------------------------------------------------------
