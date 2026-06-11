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

#if __has_include(<micro-os-plus/project-config.h>)
#include <micro-os-plus/project-config.h>
#elif __has_include(<micro-os-plus/config.h>)
#pragma message "micro-os-plus/config.h is deprecated, rename to micro-os-plus/project-config.h and include it instead of micro-os-plus/config.h"
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/project-config.h>)

#include <micro-os-plus/diag/trace.h>
#include <unistd.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  trace_testing::initialize ();

  trace_testing::dump_args (argc, argv);

  trace_testing::printf ("Hello %s!\n", "World");
  trace_testing::puts ("one line");
  trace_testing::putchar ('*');

  trace_testing::flush ();

  return 0;
}

// ----------------------------------------------------------------------------
// The full implementation of the trace system API.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif

namespace micro_os_plus::trace_testing

#if defined(__clang__)
#pragma clang diagnostic pop
#endif
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
// warning: conversion from 'std::size_t' {aka 'long long unsigned int'} to
// 'unsigned int' may change value [-Wconversion]
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    return ::write (1, buf, nbyte);
#pragma GCC diagnostic pop
  }

  void
  flush (void)
  {
#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
    fsync (1); // Sync STDOUT.
#endif
  }
} // namespace micro_os_plus::trace_testing

// ----------------------------------------------------------------------------
