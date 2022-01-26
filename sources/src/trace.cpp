/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#if defined(TRACE)

// ----------------------------------------------------------------------------

#include <micro-os-plus/diag/trace.h>

#include <cstdarg>
#include <cstdio>
#include <cstring>

#ifndef MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE
#define MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE (200)
#endif

// ----------------------------------------------------------------------------

namespace micro_os_plus
{
  namespace trace
  {
    // ------------------------------------------------------------------------

    // Weak empty defaults, in case no output is defined.
    void __attribute__ ((weak)) initialize (void)
    {
      ;
    }

    /**
     * @brief Write the given number of bytes to the trace output channel.
     * @return  The number of characters actually written, or -1 if error.
     */
    ssize_t __attribute__ ((weak))
    write (const void* buf __attribute__ ((unused)), std::size_t nbyte)
    {
      return static_cast<ssize_t> (nbyte);
    }

    void __attribute__ ((weak)) flush (void)
    {
      ;
    }

    // ------------------------------------------------------------------------

    int __attribute__ ((weak)) printf (const char* format, ...)
    {
      std::va_list arguments;
      va_start (arguments, format);

      int ret = vprintf (format, arguments);

      va_end (arguments);
      return ret;
    }

    int __attribute__ ((weak))
    vprintf (const char* format, std::va_list arguments)
    {
      // Caution: allocated on the stack!
      char buf[MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE];

      // TODO: possibly rewrite it to no longer use newlib,
      // (although the nano version is no longer very heavy).

      // Print to the local buffer
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
      ssize_t ret = ::vsnprintf (buf, sizeof (buf), format, arguments);
#pragma GCC diagnostic pop
      if (ret > 0)
        {
          // Transfer the buffer to the device.
          ret = write (buf, static_cast<size_t> (ret));
        }
#pragma GCC diagnostic push
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
      // Cast required on 64-bit.
      return static_cast<int> (ret);
#pragma GCC diagnostic pop
    }

    int __attribute__ ((weak)) puts (const char* s)
    {
      ssize_t ret = write (s, strlen (s));
      if (ret >= 0)
        {
          ret = write ("\n", 1); // Add a line terminator
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

    int __attribute__ ((weak)) putchar (int c)
    {
      ssize_t ret = write (reinterpret_cast<const char*> (&c), 1);
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
    void __attribute__ ((weak))
    dump_args (int argc, char* argv[], const char* name)
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

    // ------------------------------------------------------------------------
  } // namespace trace
} // namespace micro_os_plus

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// These cannot be aliased, since they usually are defined
// in a different translation unit.

void __attribute__ ((weak)) micro_os_plus_trace_initialize (void)
{
  trace::initialize ();
}

ssize_t __attribute__ ((weak))
micro_os_plus_trace_write (const void* buf, std::size_t nbyte)
{
  return trace::write (buf, nbyte);
}

void __attribute__ ((weak)) micro_os_plus_trace_flush (void)
{
  return trace::flush ();
}

// ----------------------------------------------------------------------------

// For non-embedded platforms, to remain compatible with OS X which does
// not support aliases, redefine the C functions to call the C++ versions.

int
micro_os_plus_trace_printf (const char* format, ...)
{
  std::va_list arguments;
  va_start (arguments, format);

  int ret = trace::vprintf (format, arguments);

  va_end (arguments);
  return ret;
}

int
micro_os_plus_trace_vprintf (const char* format, va_list arguments)
{
  return trace::vprintf (format, arguments);
}

int
micro_os_plus_trace_puts (const char* s)
{
  return trace::puts (s);
}

int
micro_os_plus_trace_putchar (int c)
{
  return trace::putchar (c);
}

void
micro_os_plus_trace_dump_args (int argc, char* argv[])
{
  trace::dump_args (argc, argv);
}

// ----------------------------------------------------------------------------

#endif // defined(TRACE)

// ----------------------------------------------------------------------------
