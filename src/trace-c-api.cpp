/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2015-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with the definitions for the C trace API.
 *
 * @details
 * Definitions for the C-linkage wrapper
 * functions (`micro_os_plus_trace_printf()`, etc.) that forward to
 * the corresponding C++ internal `tracer<implementation>` functions.
 *
 * The empty inline stubs (used when tracing is disabled) are located in
 * @ref trace-c-api-inlines.h, included at the bottom of
 * @ref trace-c-api.h.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/diag/trace.h"

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

namespace detail = micro_os_plus::trace::detail;

// The C API is always bound to the `tracer<implementation>` policy class;
// extern "C" does not support templates, so it cannot expose other
// instances. Code that needs custom instances must call the C++
// API directly.

void
micro_os_plus_trace_initialise (void)
{
  detail::tracer<detail::implementation>::initialise ();
}

ssize_t
micro_os_plus_trace_write (const void* buf, size_t nbyte)
{
  return detail::tracer<detail::implementation>::write (buf, nbyte);
}

void
micro_os_plus_trace_flush (void)
{
  detail::tracer<detail::implementation>::flush ();
}

// ----------------------------------------------------------------------------

int
micro_os_plus_trace_printf (const char* format, ...)
{
  std::va_list arguments;
  va_start (arguments, format);

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  int ret
      = detail::tracer<detail::implementation>::vprintf (format, arguments);
#pragma GCC diagnostic pop

  va_end (arguments);
  return ret;
}

int
micro_os_plus_trace_vprintf (const char* format, va_list arguments)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return detail::tracer<detail::implementation>::vprintf (format, arguments);
#pragma GCC diagnostic pop
}

int
micro_os_plus_trace_puts (const char* s)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return detail::tracer<detail::implementation>::puts (s);
#pragma GCC diagnostic pop
}

int
micro_os_plus_trace_putchar (int c)
{
  return detail::tracer<detail::implementation>::putchar (c);
}

void
micro_os_plus_trace_dump_args (int argc, char* argv[])
{
  detail::tracer<detail::implementation>::dump_args (argc, argv);
}

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------
