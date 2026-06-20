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

#if !defined(MICRO_OS_PLUS_DIAG_TRACE_H_)
#error "Do not include this file directly; use <micro-os-plus/diag/trace.h>."
#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

/**
 * @file
 * @brief C++ header file with the inline implementations for the
 * `tracer` class template.
 *
 * @details
 * Class definitions are located in @ref trace-cpp-api.h.
 * Inline methods are separated into this file to improve project
 * structure and maintainability.
 */

#ifndef MICRO_OS_PLUS_DIAG_TRACE_CPP_API_INLINES_H_
#define MICRO_OS_PLUS_DIAG_TRACE_CPP_API_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_TRACE)

#include <cstring>
#include <algorithm>

// ----------------------------------------------------------------------------

#ifndef MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE
#define MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE (200)
#endif

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif

namespace micro_os_plus::trace
{
  namespace detail
  {

    // --------------------------------------------------------------------------
    // Out-of-class definitions of the tracer<T> member function
    // templates declared in trace.h. Each is parameterised on the policy
    // class (`implementation`, or any user-defined policy class)
    // and shares no state across policy classes, so tracer<implementation> and
    // tracer<Testing> (or any further user-defined policy class)
    // can coexist in the same binary.
    // --------------------------------------------------------------------------

    template <trace_policy T>
    int
    tracer<T>::printf (const char* format, ...) noexcept
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

    template <trace_policy T>
    int
    tracer<T>::vprintf (const char* format, std::va_list arguments) noexcept
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
          // Clamp to actual buffer size if output was truncated.
          ret = write (buf,
                       static_cast<size_t> (std::min (
                           ret, static_cast<ssize_t> (sizeof (buf) - 1))));
        }
#pragma GCC diagnostic push
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
      // Cast required on 64-bit.
      return static_cast<int> (ret);
#pragma GCC diagnostic pop
    }

    template <trace_policy T>
    int
    tracer<T>::puts (const char* s) noexcept
    {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
      ssize_t ret = write (s, strlen (s));
#pragma GCC diagnostic pop
      if (ret >= 0)
        {
          ssize_t ret2 = write ("\n", 1); // Add a line terminator
          if (ret2 < 0)
            {
              ret = ret2; // Propagate the error.
            }
          else
            {
              ret += ret2; // Return total bytes written.
            }
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

    template <trace_policy T>
    int
    tracer<T>::putchar (int c) noexcept
    {
      char ch = static_cast<char> (c);
      ssize_t ret = write (&ch, 1);
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
    template <trace_policy T>
    void
    tracer<T>::dump_args (int argc, char* argv[], const char* name) noexcept
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

  } // namespace detail

  // --------------------------------------------------------------------------
  // Non-template free functions bound to `tracer<implementation>`. These
  // preserve the original call syntax (`micro_os_plus::trace::printf(...)`) so
  // that existing call sites throughout the codebase do not need to change.
  // --------------------------------------------------------------------------

  inline void
  initialise (void) noexcept
  {
    detail::tracer<detail::implementation>::initialise ();
  }

  inline ssize_t
  write (const void* buf, std::size_t nbyte) noexcept
  {
    return detail::tracer<detail::implementation>::write (buf, nbyte);
  }

  inline void
  flush (void) noexcept
  {
    detail::tracer<detail::implementation>::flush ();
  }

  inline int
  printf (const char* format, ...) noexcept
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

  inline int
  vprintf (const char* format, std::va_list arguments) noexcept
  {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    return detail::tracer<detail::implementation>::vprintf (format, arguments);
#pragma GCC diagnostic pop
  }

  inline int
  puts (const char* s) noexcept
  {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    return detail::tracer<detail::implementation>::puts (s);
#pragma GCC diagnostic pop
  }

  inline int
  putchar (int c) noexcept
  {
    return detail::tracer<detail::implementation>::putchar (c);
  }

  inline void
  dump_args (int argc, char* argv[], const char* name) noexcept
  {
    detail::tracer<detail::implementation>::dump_args (argc, argv, name);
  }

} // namespace micro_os_plus::trace

#pragma GCC diagnostic pop

#else // !defined(MICRO_OS_PLUS_TRACE)

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif

namespace micro_os_plus::trace
{
  // ------------------------------------------------------------------------
  // Empty definitions.

  inline __attribute__ ((always_inline)) void
  initialise (void) noexcept
  {
  }

  inline __attribute__ ((always_inline)) ssize_t
  write (const void* /* buf */, std::size_t nbyte) noexcept
  {
    return static_cast<ssize_t> (nbyte);
  }

  inline __attribute__ ((always_inline)) void
  flush (void) noexcept
  {
  }

  // --------------------------------------------------------------------------

  inline __attribute__ ((always_inline)) int
  printf (const char* /* format */, ...) noexcept
  {
    return 0;
  }

  inline __attribute__ ((always_inline)) int
  vprintf (const char* /* format */, std::va_list /* arguments */) noexcept
  {
    return 0;
  }

  inline __attribute__ ((always_inline)) int
  puts (const char* /* s */) noexcept
  {
    return 0;
  }

  inline __attribute__ ((always_inline)) int
  putchar (int c) noexcept
  {
    return c;
  }

  inline __attribute__ ((always_inline)) void
  dump_args (int /* argc */, char* /* argv */[],
             const char* /* name */) noexcept
  {
  }

} // namespace micro_os_plus::trace

#pragma GCC diagnostic pop

#endif // defined(MICRO_OS_PLUS_TRACE)

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_CPP_API_INLINES_H_

// ----------------------------------------------------------------------------
