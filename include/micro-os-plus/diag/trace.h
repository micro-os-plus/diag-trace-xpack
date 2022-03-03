/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#ifndef MICRO_OS_PLUS_DIAG_TRACE_H_
#define MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdarg>
#include <cstdlib>
#else
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#endif // __cplusplus

#include <sys/types.h>

#if defined(__cplusplus)

// To be effective, <stdio.h> must be included *before* this patch.
#include <stdio.h>

// This is a very annoying issue, some very old libraries still
// define putchar() as a macro. This is abusive, since it prevents
// the use of putchar() in other name spaces.
#if defined(putchar)
#undef putchar
#endif // defined(putchar)

#endif // __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_TRACE)

#if defined(__cplusplus)

namespace micro_os_plus
{
  /**
   * @brief Tracing support namespace.
   * @ingroup micro-os-plus-diag
   * @details
   * The trace device is an independent output channel, intended
   * for diagnostic purposes.
   *
   * The API is simple, and mimics the standard C output calls:
   * - `micro_os_plus::trace::printf()` / `micro_os_plus_trace_printf()`
   * - `micro_os_plus::trace::puts()` / `micro_os_plus_trace_puts()`
   * - `micro_os_plus::trace::putchar()` / `micro_os_plus_trace_putchar()`
   *
   * The user must provide implementations for:
   * - micro_os_plus::trace::initialize()
   * - micro_os_plus::trace::write()
   * - micro_os_plus::trace::flush()
   *
   * Trace support is enabled by adding the `MICRO_OS_PLUS_TRACE`
   * macro definition to the compiler line.
   *
   * When `MICRO_OS_PLUS_TRACE` is not defined, all functions are
   * inlined to empty bodies.
   * This has the advantage that the trace calls do not need to be
   * conditionally compiled with
   * <tt> \#if defined(MICRO_OS_PLUS_TRACE) </tt> / <tt> \#endif </tt>
   * The disadvantage is that this header must be always included.
   */
  namespace trace
  {
    // ------------------------------------------------------------------------

    /**
     * @brief Intialize the trace device.
     * @par Parameters
     *  None.
     * @par Returns
     *  Nothing.
     *
     * Must be implemented by the application.
     */
    void
    initialize (void);

    /**
     * @brief Write the given number of bytes to the trace output channel.
     * @param [in] buf An array of bytes.
     * @param [in] nbyte The number of bytes in the array.
     * @return  The number of characters actually written, or -1 if error.
     *
     * Must be implemented by the application.
     */
    ssize_t
    write (const void* buf, std::size_t nbyte);

    // ------------------------------------------------------------------------

    /**
     * @brief Write a formatted string to the trace device.
     * @param [in] format A null terminate string with the format.
     * @return A nonnegative number for success.
     *
     * @ingroup micro-os-plus-diag
     */
    int
    printf (const char* format, ...);

    /**
     * @brief Write a formatted variable arguments list to the trace device.
     * @param [in] format A null terminate string with the format.
     * @param [in] arguments A variable arguments list.
     * @return A nonnegative number for success.
     *
     * @ingroup micro-os-plus-diag
     */
    int
    vprintf (const char* format, std::va_list arguments);

    /**
     * @brief Write the string and a line terminator to the trace device.
     * @param [in] s A null terminated string.
     * @return A nonnegative number for success.
     *
     * @ingroup micro-os-plus-diag
     */
    int
    puts (const char* s);

    /**
     * @brief Write the single character to the trace device.
     * @param [in] c A single byte character.
     * @return The written character.
     *
     * @ingroup micro-os-plus-diag
     */
    int
    putchar (int c);

    /**
     * @brief Write the argv[] array to the trace device.
     * @param [in] argc The number of argv[] strings.
     * @param [in] argv An array of pointer to arguments.
     *
     * @ingroup micro-os-plus-diag
     */
    void
    dump_args (int argc, char* argv[], const char* name = "main");

    /**
     * @brief Flush the output.
     * @par Parameters
     *  None.
     * @par Returns
     *  Nothing.
     */
    void
    flush (void);

    // ------------------------------------------------------------------------
  } // namespace trace
} // namespace micro_os_plus

#endif // defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

  // ----- Implementation -----------------------------------------------------
  // These functions must be implemented for a specific trace channel.

  /**
   * Called from startup.
   */
  void
  micro_os_plus_trace_initialize (void);

  ssize_t
  micro_os_plus_trace_write (const void* buf, size_t nbyte);

  void
  micro_os_plus_trace_flush (void);

  // ----- Portable -----

  int
  micro_os_plus_trace_printf (const char* format, ...);

  int
  micro_os_plus_trace_vprintf (const char* format, va_list arguments);

  int
  micro_os_plus_trace_puts (const char* s);

  int
  micro_os_plus_trace_putchar (int c);

  void
  micro_os_plus_trace_dump_args (int argc, char* argv[]);

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#else /* !defined(MICRO_OS_PLUS_TRACE) */

// Empty definitions when trace is not defined

#if defined(__cplusplus)

namespace micro_os_plus
{
  namespace trace
  {
    // ------------------------------------------------------------------------

    inline void
    initialize (void);

    inline ssize_t
    write (const void* buf, std::size_t nbyte);

    // ------------------------------------------------------------------------

    inline int
    printf (const char* format, ...);

    inline int
    vprintf (const char* format, std::va_list arguments);

    inline int
    puts (const char* s);

    inline int
    putchar (int c);

    inline void
    dump_args (int argc, char* argv[], const char* name = "main");

    // ------------------------------------------------------------------------

    inline __attribute__ ((always_inline)) void
    initialize (void)
    {
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    inline __attribute__ ((always_inline)) ssize_t
    write (const void* buf, std::size_t nbyte)
    {
      return static_cast<ssize_t> (nbyte);
    }

    inline __attribute__ ((always_inline)) void
    flush (void)
    {
    }

    inline __attribute__ ((always_inline)) int
    printf (const char* format, ...)
    {
      return 0;
    }

    inline __attribute__ ((always_inline)) int
    vprintf (const char* format, std::va_list arguments)
    {
      return 0;
    }

    inline __attribute__ ((always_inline)) int
    puts (const char* s)
    {
      return 0;
    }

    inline __attribute__ ((always_inline)) int
    putchar (int c)
    {
      return c;
    }

    inline __attribute__ ((always_inline)) void
    dump_args (int argc, char* argv[], const char* name)
    {
    }

#pragma GCC diagnostic pop

  } // namespace trace
} // namespace micro_os_plus

#endif // defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

  inline void
  micro_os_plus_trace_initialize (void);

  // Implementation dependent
  inline ssize_t
  micro_os_plus_trace_write (const void* buf, size_t nbyte);

  inline void
  micro_os_plus_trace_flush (void);

  inline int
  micro_os_plus_trace_printf (const char* format, ...);

  inline int
  micro_os_plus_trace_vprintf (const char* format, va_list arguments);

  inline int
  micro_os_plus_trace_puts (const char* s);

  inline int
  micro_os_plus_trace_putchar (int c);

  inline void
  micro_os_plus_trace_dump_args (int argc, char* argv[]);

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

inline __attribute__ ((always_inline)) void
micro_os_plus_trace_initialize (void)
{
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#pragma GCC diagnostic push
#if defined(__cplusplus)
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // defined(__cplusplus)

inline __attribute__ ((always_inline)) ssize_t
micro_os_plus_trace_write (const void* buf, size_t nbyte)
{
  return (ssize_t)(nbyte);
}

inline __attribute__ ((always_inline)) void
micro_os_plus_trace_flush (void)
{
}

#pragma GCC diagnostic pop

inline __attribute__ ((always_inline)) int
micro_os_plus_trace_printf (const char* format, ...)
{
  return 0;
}

inline __attribute__ ((always_inline)) int
micro_os_plus_trace_vprintf (const char* format, va_list arguments)
{
  return 0;
}

inline __attribute__ ((always_inline)) int
micro_os_plus_trace_puts (const char* s)
{
  return 0;
}

inline __attribute__ ((always_inline)) int
micro_os_plus_trace_putchar (int c)
{
  return c;
}

inline __attribute__ ((always_inline)) void
micro_os_plus_trace_dump_args (int argc, char* argv[])
{
}

#pragma GCC diagnostic pop

#endif // defined(MICRO_OS_PLUS_TRACE)

// ----------------------------------------------------------------------------
// Compatibility definitions.

#define trace_initialize micro_os_plus_trace_initialize
#define trace_write micro_os_plus_trace_write
#define trace_flush micro_os_plus_trace_flush

#define trace_printf micro_os_plus_trace_printf
#define trace_vprintf micro_os_plus_trace_vprintf
#define trace_puts micro_os_plus_trace_puts
#define trace_putchar micro_os_plus_trace_putchar
#define trace_dump_args micro_os_plus_trace_dump_args

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------
