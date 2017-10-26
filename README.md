## The µOS++ `trace::printf()` tracing infrastructure

This project provides support for a separate tracing channel, different from the standard output or error streams. The API is similar to the standard functions:

### C++ API

All functions have C equivalents:

`int 	os::trace::printf (const char *format,...)`
 Write a formatted string to the trace device.
 
`int 	os::trace::putchar (int c)`
 Write the single character to the trace device.
 
`int 	os::trace::puts (const char *s)`
 Write the string and a line terminator to the trace device.
 
`int 	os::trace::vprintf (const char *format, std::va_list args)`
 Write a formatted variable arguments list to the trace device.
 
 ### C API

The following functions are available:

`int 	trace_printf (const char *format,...)`
 Write a formatted string to the trace device.
 
`int 	trace_putchar (int c)`
 Write the single character to the trace device.
 
`int 	trace_puts (const char *s)`
 Write the string and a line terminator to the trace device.
 
`int 	trace_vprintf (const char *format, std::va_list args)`
 Write a formatted variable arguments list to the trace device.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Easy install

The source files are available from [GitHub](https://github.com/micro-os-plus/diag-trace-xpack):

```console
$ git clone https://github.com/micro-os-plus/diag-trace-xpack.git diag-trace-xpack.git
```

The library will shortly be available from the npm registry:

```console
$ npm install @micro-os-plus/diag-trace
```

### Implementation

The application should provide an implementation for the following basic functions.

```c++
namespace os
{
  namespace trace
  {
    // ------------------------------------------------------------------------

    void
    initialize (void)
    {
      // TODO: open the trace device.
    }

    // ------------------------------------------------------------------------

    ssize_t
    write (const void* buf, std::size_t nbyte)
    {
      if (buf == nullptr || nbyte == 0)
        {
          return 0;
        }

      // TODO: write chars from buffer.

      // All characters successfully sent.
      return (ssize_t) nbyte;
    }

    // ------------------------------------------------------------------------

    void
    flush (void)
    {
      ; // TODO flush port
    }

  // --------------------------------------------------------------------------
  } /* namespace trace */
} /* namespace os */
```

Without them the application still compiles, but there is no functionality, by default all the above are implemented as weak empty functions.

### Prerequisites

The source code require a modern C++ compiler, preferably GCC 5 or higher, but was also compiled with GCC 4.8. 

### How to publish

* commit all changes
* update `CHANGELOG.md`; commit with a message like _prepare v0.1.2_
* `npm version patch`
* push all changes to GitHub
* `npm publish`

## License

The original content is released under the MIT License, with all rights reserved to Liviu Ionescu.
