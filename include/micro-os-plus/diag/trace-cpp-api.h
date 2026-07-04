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

#ifndef MICRO_OS_PLUS_DIAG_TRACE_CPP_API_H_
#define MICRO_OS_PLUS_DIAG_TRACE_CPP_API_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <sys/types.h>

// #include <cstdint>
#include <cstddef>
#include <cstdarg>
// #include <cstdlib>
#include <concepts>

// ----------------------------------------------------------------------------

/**
 * @brief Tracing support namespace.
 *
 * @details
 * The trace channel functions as a standalone output device designed
 * specifically for diagnostic purposes.
 *
 * The API is straightforward and emulates the standard C output calls:
 * - `micro_os_plus::trace::printf()` / `micro_os_plus_trace_printf()`
 * - `micro_os_plus::trace::puts()` / `micro_os_plus_trace_puts()`
 * - `micro_os_plus::trace::putchar()` / `micro_os_plus_trace_putchar()`
 *
 * The C++ API is implemented as a class template,
 * @ref micro_os_plus::trace::tracer, parameterised on a policy class
 * that supplies the low-level primitives. One such policy
 * class is declared here: @ref micro_os_plus::trace::implementation for
 * production use. `tracer<implementation>` is an independent class
 * instantiation: it is already instantiated and is used internally;
 * it shares no mutable state.
 *
 * The free functions (`micro_os_plus::trace::printf()` etc.) are a thin
 * alias for `tracer<implementation>`, so existing call sites do not need
 * to change.
 *
 * The user is required to provide implementations of the following
 * static methods, once per policy class actually used:
 * - `micro_os_plus::trace::detail::implementation::initialise()`
 * - `micro_os_plus::trace::detail::implementation::write()`
 * - `micro_os_plus::trace::detail::implementation::flush()`
 *
 * Trace support is activated by adding the `MICRO_OS_PLUS_TRACE`
 * macro definition to the compiler line.
 *
 * When `MICRO_OS_PLUS_TRACE` is not defined, all functions are
 * inlined to empty bodies.
 * This approach eliminates the need for trace calls to be conditionally
 * compiled using
 * `#if defined(MICRO_OS_PLUS_TRACE)` and `#endif`.
 * However, the drawback is that the associated header file must always be
 * included.
 */

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif

namespace micro_os_plus::trace
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

  // Declarations.
  void
  initialise (void) noexcept;

  ssize_t
  write (const void* buf, std::size_t nbyte) noexcept;

  void
  flush (void) noexcept;

  // --------------------------------------------------------------------------

  int
  printf (const char* format, ...) noexcept;

  int
  vprintf (const char* format, std::va_list arguments) noexcept;

  int
  puts (const char* s = "") noexcept;

  int
  putchar (int c) noexcept;

  void
  dump_args (int argc, char* argv[], const char* name = "main") noexcept;

#pragma GCC diagnostic pop
} // namespace micro_os_plus::trace

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::trace
{
#pragma GCC diagnostic push
#if defined(__clang__)
// #pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

  // --------------------------------------------------------------------------

  namespace detail
  {
    /**
     * @brief Policy class for the production trace instance.
     * @details
     * The user must provide a definition of `initialise()`, `write()`,
     * and `flush()` for this class (typically in a single .cpp file,
     * once per application/platform).
     *
     * `implementation` is not a template; it has no member data and is
     * never instantiated as an object. Its static methods are looked up
     * by `tracer<implementation>` and are otherwise ordinary, non-template
     * member functions, so there is no instantiation-order hazard
     * between their declaration here and their definition elsewhere.
     */
    class implementation
    {
    public:
      static void
      initialise (void) noexcept;

      static ssize_t
      write (const void* buf, std::size_t nbyte) noexcept;

      static void
      flush (void) noexcept;
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Concept constraining the policy class `T` used by `tracer<T>`.
     * @details
     * A conforming `T` must expose three static member functions with
     * the following exact signatures:
     * - `static void T::initialise()`
     * - `static ssize_t T::write(const void*, std::size_t)`
     * - `static void T::flush()`
     *
     * A clear diagnostic is emitted at the point of instantiation if
     * any of the required functions is absent or has the wrong signature.
     */
    template <typename T>
    concept trace_policy = requires (const void* buf, std::size_t n) {
      { T::initialise () } -> std::same_as<void>;
      { T::write (buf, n) } -> std::same_as<ssize_t>;
      { T::flush () } -> std::same_as<void>;
    };

    // ------------------------------------------------------------------------

    /**
     * @ingroup micro-os-plus-diag-trace-cpp-api-main
     * @brief Tracing API bound to a given policy class.
     * @headerfile trace.h <micro-os-plus/diag/trace.h>
     * @tparam T Policy class providing the static `initialise()`,
     * `write()`, and `flush()` primitives (e.g. @ref implementation).
     *
     * @details
     * All methods are static; `tracer` is never instantiated as an
     * object. Each distinct `T` produces an independent set of
     * methods with no shared state, so `tracer<implementation>`
     * (or any further user-defined policy class)
     * can coexist in the same translation unit and binary.
     */
    template <trace_policy T>
    class tracer
    {
    public:
      tracer () = delete;

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
       * @brief Initialize the trace output channel.
       * @par Parameters
       *  None.
       * @par Returns
       *  Nothing.
       *
       * @details
       * Delegates unconditionally to `T::initialise()`. Called
       * during startup, as early as possible, to enable the trace
       * channel. The `noexcept` specification mirrors that of the
       * policy method.
       */
      static void
      initialise (void) noexcept (noexcept (T::initialise ()))
      {
        T::initialise ();
      }

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
       * @brief Write the given number of bytes to the trace output channel.
       * @param [in] buf An array of bytes.
       * @param [in] nbyte The number of bytes in the array.
       * @return The number of bytes actually written, or -1 if error.
       *
       * @details
       * Delegates unconditionally to `T::write()`. The return value
       * must reflect the number of bytes actually transferred; a
       * return value of -1 signals an error. The `noexcept`
       * specification mirrors that of the policy method.
       */
      static ssize_t
      write (const void* buf,
             std::size_t nbyte) noexcept (noexcept (T::write (buf, nbyte)))
      {
        return T::write (buf, nbyte);
      }

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
       * @brief Flush the trace output channel.
       * @par Parameters
       *  None.
       * @par Returns
       *  Nothing.
       *
       * @details
       * Delegates unconditionally to `T::flush()`. For buffered
       * output channels, the policy method must drain any internally
       * buffered data to the output device. For unbuffered or
       * character-mode channels (e.g. UART, ITM), the policy method
       * body can be left empty. The `noexcept` specification mirrors
       * that of the policy method.
       */
      static void
      flush (void) noexcept (noexcept (T::flush ()))
      {
        T::flush ();
      }

      // ----------------------------------------------------------------------

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-main
       * @brief Write a formatted string to the trace output channel.
       * @param [in] format A null terminated string with the format.
       * @return The number of bytes written, or -1 if an error occurred.
       *
       * @details
       * Formatting is performed into a fixed-size stack buffer of
       * `MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER`
       * bytes (default: 200). Output that exceeds this limit is
       * silently truncated before being passed to `write()`. The
       * return value reflects the bytes actually written, not the
       * number that the format string would have produced.
       */
      static int
      printf (const char* format, ...) noexcept
          __attribute__ ((format (printf, 1, 2)));

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-main
       * @brief Write a formatted variable arguments list to the trace
       * output channel.
       * @param [in] format A null terminated string with the format.
       * @param [in] arguments A variable arguments list.
       * @return The number of bytes written, or -1 if an error occurred.
       *
       * @details
       * Equivalent to `printf()`, but accepts a `std::va_list`
       * instead of a variadic argument list. Subject to the same
       * fixed-size stack buffer constraint and truncation behaviour.
       * Typically called by `printf()`.
       */
      static int
      vprintf (const char* format, std::va_list arguments) noexcept;

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-main
       * @brief Write the string and a line terminator to the trace
       * output channel.
       * @param [in] s A null terminated string (default: empty string).
       * @return The total number of bytes written (string + newline),
       *  or EOF (-1) if an error occurred.
       *
       * @details
       * Writes the characters of @p s followed by a single newline
       * character (`'\n'`). Unlike the standard C `puts()`, this
       * function returns the total byte count written. If writing
       * the newline fails after the string has been written
       * successfully, EOF is returned.
       */
      static int
      puts (const char* s = "") noexcept;

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-main
       * @brief Write the single character to the trace output channel.
       * @param [in] c A single byte character, passed as an `int`.
       * @return The written character as an `int`, or EOF (-1) if an
       *  error occurred.
       *
       * @details
       * Converts @p c to `char` and passes it as a one-byte buffer
       * to `write()`. On success, returns the original value of
       * @p c; on failure, returns EOF.
       */
      static int
      putchar (int c) noexcept;

      /**
       * @ingroup micro-os-plus-diag-trace-cpp-api-extra
       * @brief Send the `argv[]` array to the trace output channel.
       * @param [in] argc The number of `argv[]` strings.
       * @param [in] argv An array of pointers to argument strings.
       * @param [in] name A null terminated string used as the
       *  function name prefix (default: `"main"`).
       *
       * @details
       * Formats and writes the argument list in the form
       * `name(argc=N, argv=["arg0", "arg1", ...])`, followed by a
       * newline. Intended to be called at the start of `main()` to
       * record the process arguments in the trace output. Each
       * argument string is quoted; no escaping is applied to the
       * string content.
       */
      static void
      dump_args (int argc, char* argv[], const char* name = "main") noexcept;
    };

    // ------------------------------------------------------------------------
    // Suppress implicit instantiation of the tracer member function bodies
    // in every TU that includes this header. The explicit instantiations in
    // trace.cpp are the sole ODR-defining instances.
    // ------------------------------------------------------------------------

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

    extern template class tracer<implementation>;

#pragma GCC diagnostic pop
  } // namespace detail

#pragma GCC diagnostic pop
} // namespace micro_os_plus::trace

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/trace-cpp-api-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_CPP_API_H_

// ----------------------------------------------------------------------------
