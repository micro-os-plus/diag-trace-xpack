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

#if defined(MICRO_OS_PLUS_TRACE)

// ----------------------------------------------------------------------------

#include <micro-os-plus/diag/trace.h>

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <algorithm>

#ifndef MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE
#define MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE (200)
#endif

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

namespace micro_os_plus::trace
{
  // --------------------------------------------------------------------------
  // Function templates, parameterised on the instance tag (Default,
  // Testing, or any user-defined tag). Each tag is given its own set
  // of object-code instances via the explicit instantiations at the
  // bottom of this file; the templates here share no state across
  // tags, so Default and Testing can coexist in the same binary.
  // --------------------------------------------------------------------------

  template <typename Tag>
  int
  printf (const char* format, ...)
  {
    std::va_list arguments;
    va_start (arguments, format);

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    int ret = vprintf<Tag> (format, arguments);
#pragma GCC diagnostic pop

    va_end (arguments);
    return ret;
  }

  template <typename Tag>
  int
  vprintf (const char* format, std::va_list arguments)
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
        ret = write<Tag> (
            buf, static_cast<size_t> (
                     std::min (ret, static_cast<ssize_t> (sizeof (buf) - 1))));
      }
#pragma GCC diagnostic push
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
    // Cast required on 64-bit.
    return static_cast<int> (ret);
#pragma GCC diagnostic pop
  }

  template <typename Tag>
  int
  puts (const char* s)
  {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    ssize_t ret = write<Tag> (s, strlen (s));
#pragma GCC diagnostic pop
    if (ret >= 0)
      {
        ret = write<Tag> ("\n", 1); // Add a line terminator
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

  template <typename Tag>
  int
  putchar (int c)
  {
    ssize_t ret = write<Tag> (reinterpret_cast<const char*> (&c), 1);
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
  template <typename Tag>
  void
  dump_args (int argc, char* argv[], const char* name)
  {
    printf<Tag> ("%s(argc=%d, argv=[", name, argc);
    for (int i = 0; i < argc; ++i)
      {
        if (i != 0)
          {
            printf<Tag> (", ");
          }
        printf<Tag> ("\"%s\"", argv[i]);
      }
    printf<Tag> ("])\n");
  }
#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------
  // Explicit instantiations. Add a line here for any further tag that
  // needs to be usable from other translation units; without an
  // explicit instantiation (or a definition visible at the call site)
  // the linker will not find these symbols for that tag.
  // --------------------------------------------------------------------------

  template int
  printf<Default> (const char* format, ...);
  template int
  vprintf<Default> (const char* format, std::va_list arguments);
  template int
  puts<Default> (const char* s);
  template int
  putchar<Default> (int c);
  template void
  dump_args<Default> (int argc, char* argv[], const char* name);

  template int
  printf<Testing> (const char* format, ...);
  template int
  vprintf<Testing> (const char* format, std::va_list arguments);
  template int
  puts<Testing> (const char* s);
  template int
  putchar<Testing> (int c);
  template void
  dump_args<Testing> (int argc, char* argv[], const char* name);

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::trace

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// These cannot be aliased, since they usually are defined
// in a different translation unit.
//
// The C API is always bound to the `Default` tag; it has no template
// parameter (extern "C" does not support templates), so it cannot
// expose the `Testing` instance. Code that needs the `Testing`
// instance must call the C++ template API directly.

void
micro_os_plus_trace_initialize (void)
{
  trace::initialize<trace::Default> ();
}

ssize_t
micro_os_plus_trace_write (const void* buf, std::size_t nbyte)
{
  return trace::write<trace::Default> (buf, nbyte);
}

void
micro_os_plus_trace_flush (void)
{
  return trace::flush<trace::Default> ();
}

// ----------------------------------------------------------------------------

// For non-embedded platforms, to remain compatible with OS X which does
// not support aliases, redefine the C functions to call the C++ versions.

int
micro_os_plus_trace_printf (const char* format, ...)
{
  std::va_list arguments;
  va_start (arguments, format);

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  int ret = trace::vprintf<trace::Default> (format, arguments);
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
  return trace::vprintf<trace::Default> (format, arguments);
#pragma GCC diagnostic pop
}

int
micro_os_plus_trace_puts (const char* s)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return trace::puts<trace::Default> (s);
#pragma GCC diagnostic pop
}

int
micro_os_plus_trace_putchar (int c)
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  return trace::putchar<trace::Default> (c);
#pragma GCC diagnostic pop
}

void
micro_os_plus_trace_dump_args (int argc, char* argv[])
{
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  trace::dump_args<trace::Default> (argc, argv);
#pragma GCC diagnostic pop
}

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_TRACE)

// ----------------------------------------------------------------------------
