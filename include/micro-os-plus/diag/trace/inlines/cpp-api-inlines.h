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
 * @brief C++ header file with the inline implementations for the
 * `tracer` class template.
 *
 * @details
 * Class definitions are located in @ref cpp-api.h.
 * Inline methods are separated into this file to improve project
 * structure and maintainability.
 */

// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_DIAG_TRACE_H_)
#error "Do not include this file directly; use "micro-os-plus/diag/trace.h"."
#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

#ifndef MICRO_OS_PLUS_DIAG_TRACE_INLINES_CPP_API_INLINES_H_
#define MICRO_OS_PLUS_DIAG_TRACE_INLINES_CPP_API_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#include <cstring>
#include <algorithm>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

namespace micro_os_plus::trace
{
  namespace detail
  {

    // ------------------------------------------------------------------------
    // Out-of-class definitions of the tracer<T> member function
    // templates declared in trace.h. Each is parameterised on the policy
    // class (`implementation`, or any user-defined policy class)
    // and shares no state across policy classes, so tracer<implementation> and
    // tracer<Testing> (or any further user-defined policy class)
    // can coexist in the same binary.
    // ------------------------------------------------------------------------

    template <trace_policy T>
    int
    tracer<T>::printf (const char* format, ...) noexcept
    {
      std::va_list arguments;
      va_start (arguments, format);

      int ret = vprintf (format, arguments);

      va_end (arguments);
      return ret;
    }

    template <trace_policy T>
    int
    tracer<T>::vprintf (const char* format, std::va_list arguments) noexcept
    {
      // Caution: allocated on the stack!
      char buf[MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER];

      // TODO: possibly rewrite it to no longer use newlib,
      // (although the nano version is no longer very heavy).

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif // defined(__GNUC__)

      // Print to the local buffer
      ssize_t ret = ::vsnprintf (buf, sizeof (buf), format, arguments);

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

      if (ret > 0)
        {
          // Clamp to actual buffer size if output was truncated.
          // Note: on truncation the return value becomes the byte count
          // written to the channel, not the total length vsnprintf
          // computed. Callers cannot use the return value to detect
          // truncation.
          ret = write (buf,
                       static_cast<size_t> (std::min (
                           ret, static_cast<ssize_t> (sizeof (buf) - 1))));
        }

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

      // Cast required on 64-bit.
      return static_cast<int> (ret);

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    }

    template <trace_policy T>
    int
    tracer<T>::puts (const char* s) noexcept
    {
      std::size_t len = std::strlen (s);
      ssize_t ret = write (s, len);
      // Only append the line terminator if the string was written in
      // full; a partial write (including a zero-byte write, which is
      // not itself an error) must not be followed by a bare newline.
      if (ret >= 0 && static_cast<std::size_t> (ret) == len)
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
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

          // Cast required on 64-bit.
          return static_cast<int> (ret);

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
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
      auto ch = static_cast<unsigned char> (c);
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

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

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

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
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

    int ret
        = detail::tracer<detail::implementation>::vprintf (format, arguments);

    va_end (arguments);
    return ret;
  }

  inline int
  vprintf (const char* format, std::va_list arguments) noexcept
  {
    return detail::tracer<detail::implementation>::vprintf (format, arguments);
  }

  inline int
  puts (const char* s) noexcept
  {
    return detail::tracer<detail::implementation>::puts (s);
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

// ----------------------------------------------------------------------------

#else // !defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

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

  inline __attribute__ ((always_inline, format (printf, 1, 2))) int
  printf (const char* /* format */, ...) noexcept
  {
    return 0;
  }

  inline __attribute__ ((always_inline, format (printf, 1, 0))) int
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

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_INLINES_CPP_API_INLINES_H_

// ----------------------------------------------------------------------------
