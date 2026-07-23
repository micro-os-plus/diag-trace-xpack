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
 * @brief C header file with the declarations for the C trace API.
 *
 * @details
 * Empty inline stubs (used when tracing is disabled) are located in
 * @ref trace-c-api-inlines.h, included at the bottom of this file.
 * This file is included by `<micro-os-plus/diag/trace.h>`, which
 * should be used instead of including this file directly.
 */

// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_DIAG_TRACE_H_)
#error "Do not include this file directly; use <micro-os-plus/diag/trace.h>."
#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

#ifndef MICRO_OS_PLUS_DIAG_TRACE_C_API_H_
#define MICRO_OS_PLUS_DIAG_TRACE_C_API_H_

// ----------------------------------------------------------------------------

// #include <stdint.h>
#include <stdarg.h>
// #include <stdlib.h>

#include <sys/types.h>

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-implementation
   * @brief Initialise the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   *
   * @details
   * This function is called during startup, as early as possible, to
   * enable the trace channel. The user must provide a definition of
   * this function that configures the underlying output device
   * (e.g. a semihosting channel, or an ITM port).
   */
  void
  micro_os_plus_trace_initialise (void);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-implementation
   * @brief Write the given number of bytes to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param buf An array of bytes.
   * @param nbyte The number of bytes in the array.
   * @return  The number of bytes actually written, or -1 if error.
   *
   * @details
   * This is the core output primitive. The user must provide a
   * definition of this function. The return value must reflect the
   * number of bytes actually transferred to the output device, which
   * may be less than @p nbyte if the device is full or an error
   * occurs. A return value of -1 signals an error; any non-negative
   * value is treated as a byte count by the higher-level functions.
   */
  ssize_t
  micro_os_plus_trace_write (const void* buf, size_t nbyte);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-implementation
   * @brief Flush the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   *
   * @details
   * For buffered output channels, this function must drain any
   * internally buffered data to the output device. For unbuffered
   * or character-mode channels (e.g. ITM), the body can be
   * left empty. No assumptions are made about thread safety or
   * re-entrancy; the caller is responsible for ensuring that
   * concurrent calls do not occur.
   */
  void
  micro_os_plus_trace_flush (void);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write a formatted string to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param format A null terminated string with the format.
   * @param ... Additional arguments matching the format specifiers.
   * @return The number of bytes written, or -1 if an error occurred.
   *
   * @details
   * Formatting is performed into a fixed-size stack buffer of
   * `MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER`
   * bytes (default: 200). If the formatted output exceeds this
   * limit, it is silently truncated before being passed to
   * `micro_os_plus_trace_write`. The return value reflects the
   * number of bytes actually written, not the number that the
   * format string would have produced.
   */
  int
  micro_os_plus_trace_printf (const char* format, ...)
      __attribute__ ((format (printf, 1, 2)));

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write a formatted variable arguments list to the trace
   * output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param format A null terminated string with the format.
   * @param arguments A variable arguments list.
   * @return The number of bytes written, or -1 if an error occurred.
   *
   * @details
   * Equivalent to `micro_os_plus_trace_printf`, but accepts a
   * `va_list` instead of a variadic argument list. Subject to the
   * same fixed-size stack buffer constraint and truncation behaviour.
   * Typically called by `micro_os_plus_trace_printf`.
   */
  int
  micro_os_plus_trace_vprintf (const char* format, va_list arguments);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write the string and a line terminator to the trace
   * output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param s A null terminated string.
   * @return The total number of bytes written (string + newline),
   *  or EOF (-1) if an error occurred.
   *
   * @details
   * Writes the characters of @p s followed by a single newline
   * character (`'\n'`). Unlike the standard C `puts()`, this
   * function returns the total byte count written, not merely a
   * non-negative indicator. If writing the newline fails after
   * the string has been written successfully, EOF is returned.
   */
  int
  micro_os_plus_trace_puts (const char* s);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write the single character to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param c A single byte character, passed as an `int`.
   * @return The written character as an `int`, or EOF (-1) if an
   *  error occurred.
   *
   * @details
   * Converts @p c to `char` and passes it as a one-byte buffer to
   * `micro_os_plus_trace_write`. On success, returns the original
   * value of @p c; on failure, returns EOF.
   */
  int
  micro_os_plus_trace_putchar (int c);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-extra
   * @brief Write the `argv[]` array to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param argc The number of `argv[]` strings.
   * @param argv An array of pointers to argument strings.
   * @par Returns
   *  Nothing.
   *
   * @details
   * Formats and writes the argument list in the form
   * `main(argc=N, argv=["arg0", "arg1", ...])`, followed by a
   * newline. The prefix is always the literal string `"main"`;
   * for a configurable prefix, use the C++ API
   * `micro_os_plus::trace::dump_args()`. Intended to be called
   * at the start of `main()` to record the process arguments in
   * the trace output. Each argument string is quoted; no escaping
   * is applied to the string content.
   */
  void
  micro_os_plus_trace_dump_args (int argc, char* argv[]);

  // --------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/trace-c-api-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_C_API_H_

// ----------------------------------------------------------------------------
