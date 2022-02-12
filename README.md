[![license](https://img.shields.io/github/license/micro-os-plus/diag-trace-xpack)](https://github.com/micro-os-plus/diag-trace-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/diag-trace-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/diag-trace-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source xPack with the µOS++ `trace::printf()` tracing infrastructure

This project provides support for a separate tracing channel, different
from the standard output or error streams. The API is similar to the
standard functions.

The project is hosted on GitHub as
[micro-os-plus/diag-trace-xpack](https://github.com/micro-os-plus/diag-trace-xpack).

## Developer info

This section is intended to developers who plan to include this library
in their own projects.

## Install

As a source xPacks, the easiest way to add it to a project is via **xpm**,
but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

For details please follow the instructions in the
[install](https://xpack.github.io/install/) page.

### xpm

This package will be available as
[`@micro-os-plus/diag-trace`](https://www.npmjs.com/package/@micro-os-plus/diag-trace)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/diag-trace@latest
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/diag-trace-xpack.git \
  xpacks/micro-os-plus-diag-trace
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## User info

### Status

The tracing infrastructure is fully functional.

### C++ API

The following C++ functions are available:

`int micro_os_plus::trace::printf (const char *format, ...)`
 Write a formatted string to the trace device.

`int micro_os_plus::trace::putchar (int c)`
 Write the single character to the trace device.

`int micro_os_plus::trace::puts (const char *s)`
 Write the string and a line terminator to the trace device.

`int micro_os_plus::trace::vprintf (const char *format, std::va_list arguments)`
 Write a formatted variable arguments list to the trace device.

`void dump_args (int argc, char* argv[], const char* name = "main")`
 Write the argv[] array to the trace device.

`void flush(void)`
 Flush the output.

`void initialize (void)`
 Intialize the trace device.

`ssize_t write (const void* buf, std::size_t nbyte)`
 Write the given number of bytes to the trace output channel.

### C API

The following C functions are available:

`int micro_os_plus_trace_printf (const char *format,...)`
 Write a formatted string to the trace device.

`int micro_os_plus_trace_putchar (int c)`
 Write the single character to the trace device.

`int micro_os_plus_trace_puts (const char *s)`
 Write the string and a line terminator to the trace device.

`int micro_os_plus_trace_vprintf (const char *format, std::va_list arguments)`
 Write a formatted variable arguments list to the trace device.

`void micro_os_plus_dump_args (int argc, char* argv[])`
 Write the argv[] array to the trace device.

`void micro_os_plus_flush(void)`
 Flush the output.

`void micro_os_plus_initialize (void)`
 Intialize the trace device.

`ssize_t micro_os_plus_write (const void* buf, std::size_t nbyte)`
 Write the given number of bytes to the trace output channel.

### Implementation

The application must provide an implementation for the following
basic functions:

```c++
namespace micro_os_plus
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
      // TODO flush port
    }

  // --------------------------------------------------------------------------
  }
}
```

Enabling `MICRO_OS_PLUS_TRACE` without having these functions defined
results in missing symbols during link.

### Build & integration info

To ease the integration of this package into user projects, there
are already made CMake and meson configuration files (see below).

For other build systems, consider the following details:

#### Source files

The source files to be added to the build are:

- `src/trace.cpp`

#### Include folders

The folders to be included in the build are:

- `include`

The header file to be included in user code is:

```c++
#include <micro-os-plus/diag/trace.h>
```

#### Preprocessor definitions

The macro used to configure this library are:

- `MICRO_OS_PLUS_TRACE` - enable support for tracing

If not defined, all functions are defined as empty inlines, so that
it is not necessary to brace the calls with `#if/#endif`.

This macro is usually
passed on the compiler line for debug configurations.

#### Compiler options

- `-std=c++17` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- `micro_os_plus::trace`

`micro_os_plus` is the top µOS++ namespace, and `trace` is the
library namespace.

#### C++ Classes

- None

#### CMake

To integrate the µOS++ diag-trace source library into a CMake application,
add this folder to the build:

```cmake
add_subdirectory("xpacks/micro-os-plus-diag-trace")`
```

The result is an interface library that can be added as an application
dependency with:

```cmake
target_link_libraries(your-target PRIVATE
    ...
    micro-os-plus::diag-trace
)
```

#### meson

To integrate the µOS++ diag-trace source library into a meson application,
add this folder to the build:

```meson
subdir('xpacks/micro-os-plus-diag-trace')
```

The result is a dependency object that can be added as an application
dependency with:

```meson
exe = executable(
  your-target,

  dependencies: [
    ...
    micro_os_plus_diag_trace_dependency
  ]
)
```

### Examples

A simple example showing how to use the µTest++ framework is
presented below and is also available in
[tests/sample-test.cpp](tests/sample-test.cpp).

```c++
#include <micro-os-plus/diag/trace.h>
#include <unistd.h>

using namespace micro_os_plus;

int
main (int argc, char* argv[])
{
  trace::initialize ();

  trace::dump_args (argc, argv);

  trace::printf ("Hello %s!\n", "World");
  trace::puts ("one line");
  trace::putchar ('*');

  trace::flush ();

  return 0;
}
```

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/diag-trace-xpack/actions/)
on each push.
The tests run on GNU/Linux, macOS and Windows, are compiled with GCC,
clang and arm-none-eabi-gcc and run natively or via QEMU.

There are two set of tests, one that runs on every push, with a
limited set of tests, and a set that is triggered manually,
usually before releases, and runs on all tests on all supported
platforms.

The full set can be run manually with the following commands:

```sh
cd ~Work/diag-trace-xpack.git

xpm run install-all
xpm run test-all
```

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).
