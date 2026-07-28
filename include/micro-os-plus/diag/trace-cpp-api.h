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
 * @brief C++ header file with the declarations for the C++ trace API
 *
 * @details
 * Declarations for the `tracer`
 * class template and the `trace_policy` concept.
 *
 * Inline method definitions are located in
 * @ref trace-cpp-api-inlines.h, included at the bottom of this
 * file. This file is included by
 * `"micro-os-plus/diag/trace.h"`, which should be used instead
 * of including this file directly.
 */

// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_DIAG_TRACE_H_)
#error "Do not include this file directly; use "micro-os-plus/diag/trace.h"."
#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

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
 * `micro_os_plus::trace::detail::tracer`, parameterised on a policy
 * class that supplies the low-level primitives. One such policy
 * class is declared here:
 * `micro_os_plus::trace::detail::implementation` for
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
 * Trace support is activated by adding the `MICRO_OS_PLUS_DIAG_TRACE_ENABLED`
 * macro definition to the `micro-os-plus/diag/trace-defines.h` file.
 *
 * When `MICRO_OS_PLUS_DIAG_TRACE_ENABLED` is not defined, all functions are
 * inlined to empty bodies.
 * This approach eliminates the need for trace calls to be conditionally
 * compiled using
 * `#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)` and `#endif`.
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

  // Free functions declarations.

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
   * @brief Initialise the trace output channel.
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::initialise()
   * "tracer<T>::initialise()". Called during startup to enable the trace
   * channel.
   */
  void
  initialise (void) noexcept;

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
   * @brief Write the given number of bytes to the trace output
   * channel.
   * @param buf An array of bytes.
   * @param nbyte The number of bytes in the array.
   * @return The number of bytes actually written, or -1 if error.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::write() "tracer<T>::write()".
   */
  ssize_t
  write (const void* buf, std::size_t nbyte) noexcept;

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-implementation
   * @brief Flush the trace output channel.
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::flush() "tracer<T>::flush()".
   */
  void
  flush (void) noexcept;

  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write a formatted string to the trace output channel.
   * @param format A null terminated string with the format.
   * @param ... Additional arguments matching the format specifiers.
   * @return The number of bytes written, or -1 if an error occurred.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::printf() "tracer<T>::printf()".
   * Subject to the same fixed-size stack buffer constraint and
   * truncation behaviour.
   */
  int
  printf (const char* format, ...) noexcept;

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write a formatted variable arguments list to the trace
   * output channel.
   * @param format A null terminated string with the format.
   * @param arguments A variable arguments list.
   * @return The number of bytes written, or -1 if an error occurred.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::vprintf()
   * "tracer<T>::vprintf()".
   */
  int
  vprintf (const char* format, std::va_list arguments) noexcept;

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write the string and a line terminator to the trace
   * output channel.
   * @param s A null terminated string (default: empty string).
   * @return The total number of bytes written (string + newline),
   *  or EOF (-1) if an error occurred.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::puts() "tracer<T>::puts()".
   */
  int
  puts (const char* s = "") noexcept;

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-main
   * @brief Write the single character to the trace output channel.
   * @param c A single byte character, passed as an `int`.
   * @return The written character as an `int`, or EOF (-1) if an
   *  error occurred.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::putchar()
   * "tracer<T>::putchar()".
   */
  int
  putchar (int c) noexcept;

  /**
   * @ingroup micro-os-plus-diag-trace-cpp-api-extra
   * @brief Send the `argv[]` array to the trace output channel.
   * @param argc The number of `argv[]` strings.
   * @param argv An array of pointers to argument strings.
   * @param name A null terminated string used as the
   *  function name prefix (default: `"main"`).
   * @par Returns
   *  Nothing.
   *
   * @details
   * Thin wrapper over
   * @ref micro_os_plus::trace::detail::tracer::dump_args()
   * "tracer<T>::dump_args()".
   */
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
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

  // --------------------------------------------------------------------------

  /**
   * @brief Implementation details namespace.
   * @details
   * The `detail` namespace contains internal implementation components
   * that are not part of the public API. It houses the `tracer` class
   * template and the `implementation` policy class, along with the
   * `trace_policy` concept used to constrain policy types.
   *
   * User code should not reference this namespace directly. The public
   * interface is the set of free functions in the enclosing
   * `micro_os_plus::trace` namespace.
   */
  namespace detail
  {
    /**
     * @brief Policy class for the production trace instance.
     * @headerfile trace.h "micro-os-plus/diag/trace.h"
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
      /**
       * @brief Initialise the trace output channel.
       * @par Parameters
       *  None.
       * @par Returns
       *  Nothing.
       *
       * @details
       * The user must provide a definition of this method, called
       * once during startup to configure the underlying output
       * device (e.g. a semihosting channel, or ITM port).
       */
      static void
      initialise (void) noexcept;

      /**
       * @brief Write the given number of bytes to the trace output
       * channel.
       * @param buf An array of bytes.
       * @param nbyte The number of bytes in the array.
       * @return The number of bytes actually transferred, or -1 if
       *  error. May be less than @p nbyte if the device is full.
       *
       * @details
       * The user must provide a definition of this method. It is the
       * core output primitive; all higher-level functions (`printf`,
       * `puts`, `putchar`) ultimately delegate to it.
       */
      static ssize_t
      write (const void* buf, std::size_t nbyte) noexcept;

      /**
       * @brief Flush the trace output channel.
       * @par Parameters
       *  None.
       * @par Returns
       *  Nothing.
       *
       * @details
       * The user must provide a definition of this method. For
       * buffered output channels, it must drain any internally
       * buffered data to the output device. For unbuffered or
       * character-mode channels (e.g. ITM), the body can
       * be left empty.
       */
      static void
      flush (void) noexcept;
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Concept constraining the policy class `T` used by `tracer<T>`.
     * @tparam T The policy class to be constrained.
     * @details
     * A conforming `T` must expose three static, `noexcept` member
     * functions with the following exact signatures:
     * - `static void T::initialise() noexcept`
     * - `static ssize_t T::write(const void*, std::size_t) noexcept`
     * - `static void T::flush() noexcept`
     *
     * The `noexcept` requirement is enforced by the concept so that a
     * non-conforming policy is rejected at instantiation time rather
     * than silently invoking `std::terminate` through the unconditionally
     * `noexcept` free-function wrappers. A clear diagnostic is emitted
     * at the point of instantiation if any required function is absent,
     * has the wrong signature, or is not `noexcept`.
     */
    template <typename T>
    concept trace_policy = requires (const void* buf, std::size_t n) {
      { T::initialise () } noexcept -> std::same_as<void>;
      { T::write (buf, n) } noexcept -> std::same_as<ssize_t>;
      { T::flush () } noexcept -> std::same_as<void>;
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Tracing API bound to a given policy class.
     * @headerfile trace.h "micro-os-plus/diag/trace.h"
     * @tparam T Policy class providing the static `initialise()`,
     * `write()`, and `flush()` primitives
     * (e.g. @ref micro_os_plus::trace::detail::implementation).
     *
     * @details
     * All methods are static; `tracer` is never instantiated as an
     * object. Each distinct `T` produces an independent set of
     * methods with no shared state, so `tracer<implementation>`
     * (or any further user-defined policy class)
     * can coexist in the same translation unit and binary.
     *
     * The main reason for using a class template rather than a namespace is
     * that it allows the policy class to be a template parameter, so that
     * multiple independent instances can coexist in the same binary, each
     * bound to a different policy class. This is used in testing, where a
     * `testing_implementation` policy class is defined to capture the output
     * for verification.
     */
    template <trace_policy T>
    class tracer
    {
    public:
      /**
       * @brief Deleted default constructor.
       * @details
       * `tracer` is a purely static utility class; all methods are
       * static and no instance is ever created. The default
       * constructor is explicitly deleted to enforce this intent and
       * prevent accidental instantiation.
       */
      tracer () = delete;

      /**
       * @brief Initialise the trace output channel.
       * @par Parameters
       *  None.
       * @par Returns
       *  Nothing.
       *
       * @details
       * Delegates unconditionally to `T::initialise()`.
       *
       * Called
       * during startup, as early as possible, to enable the trace
       * channel. Unconditionally `noexcept`, since the `trace_policy`
       * concept already requires `T::initialise()` to be `noexcept`.
       */
      static void
      initialise (void) noexcept
      {
        T::initialise ();
      }

      /**
       * @brief Write the given number of bytes to the trace output channel.
       * @param buf An array of bytes.
       * @param nbyte The number of bytes in the array.
       * @return The number of bytes actually written, or -1 if error.
       *
       * @details
       * Delegates unconditionally to `T::write()`.
       *
       * The return value
       * must reflect the number of bytes actually transferred; a
       * return value of -1 signals an error. Unconditionally
       * `noexcept`, since the `trace_policy` concept already requires
       * `T::write()` to be `noexcept`.
       */
      static ssize_t
      write (const void* buf, std::size_t nbyte) noexcept
      {
        return T::write (buf, nbyte);
      }

      /**
       * @brief Flush the trace output channel.
       * @par Parameters
       *  None.
       * @par Returns
       *  Nothing.
       *
       * @details
       * Delegates unconditionally to `T::flush()`.
       *
       * For buffered
       * output channels, the policy method must drain any internally
       * buffered data to the output device. For unbuffered or
       * character-mode channels (e.g. ITM), the policy method
       * body can be left empty. Unconditionally `noexcept`, since the
       * `trace_policy` concept already requires `T::flush()` to be
       * `noexcept`.
       */
      static void
      flush (void) noexcept
      {
        T::flush ();
      }

      // ----------------------------------------------------------------------

      /**
       * @brief Write a formatted string to the trace output channel.
       * @param format A null terminated string with the format.
       * @param ... Additional arguments matching the format specifiers.
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
       * @brief Write a formatted variable arguments list to the trace
       * output channel.
       * @param format A null terminated string with the format.
       * @param arguments A variable arguments list.
       * @return The number of bytes written to the output channel,
       *  or -1 if an error occurred.
       *
       * @details
       * Equivalent to `printf()`, but accepts a `std::va_list`
       * instead of a variadic argument list. Subject to the same
       * fixed-size stack buffer constraint. When the formatted output
       * exceeds the buffer size, the text is truncated silently; the
       * return value then reflects the bytes actually written to the
       * channel, not the total length that `vsnprintf` would have
       * produced. Typically called by `printf()`.
       */
      static int
      vprintf (const char* format, std::va_list arguments) noexcept;

      /**
       * @brief Write the string and a line terminator to the trace
       * output channel.
       * @param s A null terminated string (default: empty string).
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
       * @brief Write the single character to the trace output channel.
       * @param c A single byte character, passed as an `int`.
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
       * @brief Send the `argv[]` array to the trace output channel.
       * @param argc The number of `argv[]` strings.
       * @param argv An array of pointers to argument strings.
       * @param name A null terminated string used as the
       *  function name prefix (default: `"main"`).
       * @par Returns
       *  Nothing.
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
