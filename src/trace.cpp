/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2015-2026 Liviu Ionescu. All rights reserved.
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

#if defined(MICRO_OS_PLUS_TRACE) || defined(MICRO_OS_PLUS_TRACE_TESTING)

// ----------------------------------------------------------------------------

#include <micro-os-plus/diag/trace.h>

#include <cstdarg>
#include <cstdio>
#include <cstring>

#ifndef MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE
#define MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE (200)
#endif

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

// For separation, use a separate naming space while testing.
namespace micro_os_plus::MICRO_OS_PLUS_TRACE_NAME_TESTING(trace)

{
  // --------------------------------------------------------------------------

  int
  printf (const char* format, ...)
  {
    std::va_list arguments;
    va_start (arguments, format);

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    int ret = vprintf (format, arguments);
#pragma GCC diagnostic pop

    va_end (arguments);
    return ret;
  }

  int
  vprintf (const char* format, std::va_list arguments)
  {
    // Caution: allocated on the stack!
    char buf[MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE];

    // TODO: possibly rewrite it to no longer use newlib,
    // (although the nano version is no longer very heavy).

    // Print to the local buffer
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    ssize_t ret = ::vsnprintf (buf, sizeof (buf), format, arguments);
#pragma GCC diagnostic pop
    if (ret > 0)
      {
        // Transfer the buffer to the device.
        ret = write (buf, static_cast<size_t> (ret));
      }
#pragma GCC diagnostic push
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
    // Cast required on 64-bit.
    return static_cast<int> (ret);
#pragma GCC diagnostic pop
  }

  int
  puts (const char* s)
  {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    ssize_t ret = write (s, strlen (s));
#pragma GCC diagnostic pop
    if (ret >= 0)
      {
        ret = write ("\n", 1); // Add a line terminator
      }
    if (ret > 0)
      {
#pragma GCC diagnostic push
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
        // Cast required on 64-bit.
        return static_cast<int> (ret);
#pragma GCC diagnostic pop
      }
    else
      {
        return EOF;
      }
  }

  int
  putchar (int c)
  {
    ssize_t ret = write (reinterpret_cast<const char*> (&c), 1);
    if (ret > 0)
      {
        return c;
      }
    else
      {
        return EOF;
      }
  }

  /**
   * @details
   * Generally it should match the prototype of `main()`, to simplify
   * forwarding the parameters.
   */
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
  void
  dump_args (int argc, char* argv[], const char* name)
  {
    printf ("%s(argc=%d, argv=[", name, argc);
    for (int i = 0; i < argc; ++i)
      {
        if (i != 0)
          {
            printf (", ");
          }
        printf ("\"%s\"", argv[i]);
      }
    printf ("])\n");
  }
#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::trace

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// These cannot be aliased, since they usually are defined
// in a different translation unit.

void
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_initialize) (void)
{
  MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::initialize ();
}

ssize_t
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_write) (
    const void* buf, std::size_t nbyte)
{
  return MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::write (buf, nbyte);
}

void
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_flush) (void)
{
  return MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::flush ();
}

// ----------------------------------------------------------------------------

// For non-embedded platforms, to remain compatible with OS X which does
// not support aliases, redefine the C functions to call the C++ versions.

int
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_printf) (
    const char* format, ...)
{
  std::va_list arguments;
  va_start (arguments, format);

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  int ret
      = MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::vprintf (format, arguments);
#pragma GCC diagnostic pop

  va_end (arguments);
  return ret;
}

int
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_vprintf) (
    const char* format, va_list arguments)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::vprintf (format, arguments);
#pragma GCC diagnostic pop
}

int
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_puts) (const char* s)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::puts (s);
#pragma GCC diagnostic pop
}

int
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_putchar) (int c)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::putchar (c);
#pragma GCC diagnostic pop
}

void
MICRO_OS_PLUS_TRACE_NAME_TESTING (micro_os_plus_trace_dump_args) (int argc,
                                                                  char* argv[])
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  MICRO_OS_PLUS_TRACE_NAME_TESTING (trace)::dump_args (argc, argv);
#pragma GCC diagnostic pop
}

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_TRACE)

// ----------------------------------------------------------------------------
