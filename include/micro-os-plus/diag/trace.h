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

#ifndef MICRO_OS_PLUS_DIAG_TRACE_H_
#define MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

#if !(__cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#error "C++20 or higher is required"
#endif

#if __has_include(<micro-os-plus/project-config.h>)
#include <micro-os-plus/project-config.h>
#elif __has_include(<micro-os-plus/config.h>)
#pragma message \
    "micro-os-plus/config.h is deprecated, rename to micro-os-plus/project-config.h and include it instead of micro-os-plus/config.h"
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/project-config.h>)

#if __has_include(<micro-os-plus/diag/trace-defines.h>)
#include <micro-os-plus/diag/trace-defines.h>
#endif // __has_include(<micro-os-plus/diag/trace-defines.h>)

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

/**
 * @brief Tracing support namespace.
 *
 * @details
 * The trace channel functions as a standalone output device designed
specifically for diagnostic purposes.
 *
The API is straightforward and emulates the standard C output calls:
 * - `micro_os_plus::trace::printf()` / `micro_os_plus_trace_printf()`
 * - `micro_os_plus::trace::puts()` / `micro_os_plus_trace_puts()`
 * - `micro_os_plus::trace::putchar()` / `micro_os_plus_trace_putchar()`
 *
 * The C++ API is implemented as a function template parameterised on a
 * tag type (@ref micro_os_plus::trace::Default,
 * @ref micro_os_plus::trace::Testing). Each tag selects an independent,
 * statically-allocated instance: the two share no mutable state, and
 * instantiating both in the same translation unit is supported. The
 * non-template overloads (`micro_os_plus::trace::printf()` etc.) are a
 * thin alias bound to the `Default` tag, so existing call sites do not
 * need to change.
 *
 * The user is required to provide implementations for the following,
 * once per tag actually used (as explicit template specialisations):
 * - `micro_os_plus::trace::initialize<Tag>()`
 * - `micro_os_plus::trace::write<Tag>()`
 * - `micro_os_plus::trace::flush<Tag>()`
 *
 * Trace support is activated by adding the `MICRO_OS_PLUS_TRACE`
 * macro definition to the compiler line.
 *
 * When `MICRO_OS_PLUS_TRACE` is not defined, all functions are
 * inlined to empty bodies.
 * This approach eliminates the need for trace calls to be conditionally
compiled using
 * `#if defined(MICRO_OS_PLUS_TRACE)` and `#endif`.
 * However, the drawback is that the associated header file must always be
included.
 */
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
namespace micro_os_plus::trace
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
{
  // --------------------------------------------------------------------------

  /**
   * @brief Tag selecting the production trace instance.
   * @details
   * Bound to the non-template `printf()`/`puts()`/... overloads, so
   * existing call sites are unaffected by the introduction of the
   * `Default`/`Testing` tag templates.
   */
  struct Default
  {
  };

  /**
   * @brief Tag selecting an independent, isolated trace instance.
   * @details
   * Intended for use from test code, in the same binary as the
   * `Default` instance, with no shared mutable state between the two.
   */
  struct Testing
  {
  };

  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
   * @brief Initialize the trace output channel for the given instance.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to initialize (@ref Default, @ref Testing).
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   *
   * @note Must be implemented by the application, as an explicit
   * specialisation, for each tag actually used.
   */
  template <typename Tag>
  void
  initialize (void);

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
   * @brief Write the given number of bytes to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to write to (@ref Default, @ref Testing).
   * @param [in] buf An array of bytes.
   * @param [in] nbyte The number of bytes in the array.
   * @return  The number of characters actually written, or -1 if error.
   *
   * @note Must be implemented by the application, as an explicit
   * specialisation, for each tag actually used.
   *
   * @details
   * This function is called during startup, as early as possible, to
   * enable the tracing channel.
   *
   * After this function, all tracing functions are available.
   */
  template <typename Tag>
  ssize_t
  write (const void* buf, std::size_t nbyte);

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
   * @brief Flush the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to flush (@ref Default, @ref Testing).
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   *
   * @note Must be implemented by the application, as an explicit
   * specialisation, for each tag actually used.
   *
   * @details
   * For buffered trace channels, this function should guarantee that
   * the entire buffer is sent to the channel.
   *
   * For character mode channels, this function can be left empty.
   */
  template <typename Tag>
  void
  flush (void);

  // ------------------------------------------------------------------------

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write a formatted string to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to write to (@ref Default, @ref Testing).
   * @param [in] format A null terminate string with the format.
   * @return A nonnegative number for success.
   */
  template <typename Tag>
  int
  printf (const char* format, ...);

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write a formatted variable arguments list to the trace output
   * channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to write to (@ref Default, @ref Testing).
   * @param [in] format A null terminate string with the format.
   * @param [in] arguments A variable arguments list.
   * @return A nonnegative number for success.
   */
  template <typename Tag>
  int
  vprintf (const char* format, std::va_list arguments);

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write the string and a line terminator to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to write to (@ref Default, @ref Testing).
   * @param [in] s A null terminated string.
   * @return A nonnegative number for success.
   */
  template <typename Tag>
  int
  puts (const char* s = "");

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write the single character to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to write to (@ref Default, @ref Testing).
   * @param [in] c A single byte character.
   * @return The written character.
   */
  template <typename Tag>
  int
  putchar (int c);

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-extra
   * @brief Send the `argv[]` array to the trace output channel.
   * @headerfile trace.h <micro-os-plus/diag/trace.h>
   * @tparam Tag The instance to write to (@ref Default, @ref Testing).
   * @param [in] argc The number of `argv[]` strings.
   * @param [in] argv An array of pointer to arguments.
   * @param [in] name A null terminate string, default "main".
   */
  template <typename Tag>
  void
  dump_args (int argc, char* argv[], const char* name = "main");

  // --------------------------------------------------------------------------
  // Declare the `Default` and `Testing` specialisations / instantiations
  // before they are used anywhere in this header or in translation units
  // that include it.
  //
  // The three user-supplied primitives (`initialize`, `write`, `flush`)
  // are provided by the user as explicit specialisations (`template <>`),
  // so they are forward-declared here with `template <>`.
  //
  // The higher-level functions (`printf`, `vprintf`, `puts`, `putchar`,
  // `dump_args`) are explicitly instantiated in `trace.cpp`; the
  // `extern template` declarations here suppress implicit instantiation
  // in every other translation unit that includes this header, which
  // avoids the `-Wundefined-func-template` diagnostic and keeps the
  // object-code in exactly one place.
  // --------------------------------------------------------------------------

  template <>
  void
  initialize<Default> (void);

  template <>
  ssize_t
  write<Default> (const void* buf, std::size_t nbyte);

  template <>
  void
  flush<Default> (void);

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

  extern template int
  printf<Default> (const char* format, ...);

  extern template int
  vprintf<Default> (const char* format, std::va_list arguments);

  extern template int
  puts<Default> (const char* s);

  extern template int
  putchar<Default> (int c);

  extern template void
  dump_args<Default> (int argc, char* argv[], const char* name);

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

  // --------------------------------------------------------------------------
  // Same declarations for the `Testing` tag.
  // --------------------------------------------------------------------------

  template <>
  void
  initialize<Testing> (void);

  template <>
  ssize_t
  write<Testing> (const void* buf, std::size_t nbyte);

  template <>
  void
  flush<Testing> (void);

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

  extern template int
  printf<Testing> (const char* format, ...);

  extern template int
  vprintf<Testing> (const char* format, std::va_list arguments);

  extern template int
  puts<Testing> (const char* s);

  extern template int
  putchar<Testing> (int c);

  extern template void
  dump_args<Testing> (int argc, char* argv[], const char* name);

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

  // --------------------------------------------------------------------------
  // Non-template aliases bound to the `Default` tag. These preserve the
  // original call syntax (`micro_os_plus::trace::printf(...)`) so that
  // existing call sites throughout the codebase do not need to change.
  // A non-template overload is preferred over a function template
  // specialisation by overload resolution for an unqualified call, so
  // these always win for plain `trace::printf(...)` calls.
  // --------------------------------------------------------------------------

  inline void
  initialize (void)
  {
    initialize<Default> ();
  }

  inline ssize_t
  write (const void* buf, std::size_t nbyte)
  {
    return write<Default> (buf, nbyte);
  }

  inline void
  flush (void)
  {
    flush<Default> ();
  }

  inline int
  printf (const char* format, ...) __attribute__ ((format (printf, 1, 2)));

  inline int
  printf (const char* format, ...)
  {
    std::va_list arguments;
    va_start (arguments, format);
    int ret = vprintf<Default> (format, arguments);
    va_end (arguments);
    return ret;
  }

  inline int
  vprintf (const char* format, std::va_list arguments)
  {
    return vprintf<Default> (format, arguments);
  }

  inline int
  puts (const char* s)
  {
    return puts<Default> (s);
  }

  inline int
  putchar (int c)
  {
    return putchar<Default> (c);
  }

  inline void
  dump_args (int argc, char* argv[], const char* name = "main")
  {
    dump_args<Default> (argc, argv, name);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::trace

#endif // defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

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
  micro_os_plus_trace_initialize (void);

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

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

#endif /* defined(MICRO_OS_PLUS_TRACE) */

// When TRACE is not enabled, define empty definitions.
#if !defined(MICRO_OS_PLUS_TRACE)

#if defined(__cplusplus)

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

// The void definitions are always in the regular namespace.
namespace micro_os_plus::trace
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
  puts (const char* s = "");

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

} // namespace micro_os_plus::trace

#pragma GCC diagnostic pop

#endif // defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

  // The void definitions are always in the regular namespace.

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
