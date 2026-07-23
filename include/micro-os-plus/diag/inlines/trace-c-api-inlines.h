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
 * @brief C header file with the empty inline stubs for the C trace
 * API when tracing is disabled.
 *
 * @details
 * Function declarations are located in @ref trace-c-api.h.
 * The stubs are separated into this file to improve project
 * structure and maintainability.
 */

// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_DIAG_TRACE_H_)
#error "Do not include this file directly; use <micro-os-plus/diag/trace.h>."
#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

#ifndef MICRO_OS_PLUS_DIAG_TRACE_INLINES_C_API_INLINES_H_
#define MICRO_OS_PLUS_DIAG_TRACE_INLINES_C_API_INLINES_H_

// ----------------------------------------------------------------------------

// When TRACE is not enabled, define all as empty.
#if !defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#include <stdarg.h>
#include <sys/types.h>

// ----------------------------------------------------------------------------
// Empty definitions.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

static inline __attribute__ ((always_inline)) void
micro_os_plus_trace_initialise (void)
{
}

#pragma GCC diagnostic push
#if defined(__cplusplus)
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // defined(__cplusplus)

static inline __attribute__ ((always_inline)) ssize_t
micro_os_plus_trace_write (const void* buf, size_t nbyte)
{
  return (ssize_t)(nbyte);
}

static inline __attribute__ ((always_inline)) void
micro_os_plus_trace_flush (void)
{
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

static inline __attribute__ ((always_inline)) int
micro_os_plus_trace_printf (const char* format, ...)
{
  return 0;
}

static inline __attribute__ ((always_inline)) int
micro_os_plus_trace_vprintf (const char* format, va_list arguments)
{
  return 0;
}

static inline __attribute__ ((always_inline)) int
micro_os_plus_trace_puts (const char* s)
{
  return 0;
}

static inline __attribute__ ((always_inline)) int
micro_os_plus_trace_putchar (int c)
{
  return c;
}

static inline __attribute__ ((always_inline)) void
micro_os_plus_trace_dump_args (int argc, char* argv[])
{
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

#endif // !defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_INLINES_C_API_INLINES_H_

// ----------------------------------------------------------------------------
