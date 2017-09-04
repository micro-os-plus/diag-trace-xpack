## The µOS++ trace::printf() tracing infrastructure

This library provides support for a separate tracing channel, different from the standard output or error streams. The API is similar to the standard functions:

```c++
os::trace::printf("Hello %s\n", name);
```

All functions have a C equivalent:

```c
trace_printf("Hello %s\n", name);
```

## Developer info

This section is intended to developers that plan to include DRTM in their own GDB servers.

### Easy install

The source files are available from [GitHub](https://github.com/micro-os-plus/diag-trace):

```bash
$ git clone https://github.com/micro-os-plus/diag-trace.git diag-trace.git
```

The library will shortly be available from the npm registry:

```bash
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

## License

The original content is released under the MIT License, with
all rights reserved to Liviu Ionescu.
