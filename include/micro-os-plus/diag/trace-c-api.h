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

  /*
   * Called from startup.
   */
  /**
   * @ingroup micro-os-plus-diag-trace-c-api-implementation
   * @brief Initialize the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   */
  void
  micro_os_plus_trace_initialise (void);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-implementation
   * @brief Write the given number of bytes to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param [in] buf An array of bytes.
   * @param [in] nbyte The number of bytes in the array.
   * @return  The number of characters actually written, or -1 if error.
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
   */
  void
  micro_os_plus_trace_flush (void);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write a formatted string to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param [in] format A null terminate string with the format.
   * @return A nonnegative number for success.
   */
  int
  micro_os_plus_trace_printf (const char* format, ...);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write a formatted variable arguments list to the trace output
   * channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param [in] format A null terminate string with the format.
   * @param [in] arguments A variable arguments list.
   * @return A nonnegative number for success.
   */
  int
  micro_os_plus_trace_vprintf (const char* format, va_list arguments);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write the string and a line terminator to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param [in] s A null terminated string.
   * @return A nonnegative number for success.
   */
  int
  micro_os_plus_trace_puts (const char* s);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-main
   * @brief Write the single character to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param [in] c A single byte character.
   * @return The written character.
   */
  int
  micro_os_plus_trace_putchar (int c);

  /**
   * @ingroup micro-os-plus-diag-trace-c-api-extra
   * @brief Write the argv[] array to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @param [in] argc The number of argv[] strings.
   * @param [in] argv An array of pointer to arguments.
   */
  void
  micro_os_plus_trace_dump_args (int argc, char* argv[]);

  // --------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)


// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_C_API_H_

// ----------------------------------------------------------------------------
