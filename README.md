[![GitHub package.json version](https://img.shields.io/github/package-json/v/micro-os-plus/diag-trace-xpack)](https://github.com/micro-os-plus/diag-trace-xpack/blob/xpack/package.json)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/micro-os-plus/diag-trace-xpack)](https://github.com/micro-os-plus/diag-trace-xpack/tags/)
[![npm (scoped)](https://img.shields.io/npm/v/@micro-os-plus/diag-trace.svg?color=blue)](https://www.npmjs.com/package/@micro-os-plus/diag-trace/)
[![license](https://img.shields.io/github/license/micro-os-plus/diag-trace-xpack)](https://github.com/micro-os-plus/diag-trace-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/diag-trace-xpack/actions/workflows/ci.yml/badge.svg)](https://github.com/micro-os-plus/diag-trace-xpack/actions/workflows/ci.yml)

# A source library xPack with the µOS++ `trace::printf()` tracing infrastructure

This project provides support for a tracing channel, separate
from the standard output or error streams. The API is similar to the
standard functions.

The code is written in C++, but there are C wrappers which can be
called from plain C source files as well.

The project is hosted on GitHub as
[micro-os-plus/diag-trace-xpack](https://github.com/micro-os-plus/diag-trace-xpack).

## Maintainer info

This page is addressed to developers who plan to include this source
library into their own projects.

For maintainer info, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Install

As a source library xPack, the easiest way to add it to a project is via
**xpm**, but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

It is recommended to update to the latest version with:

```sh
npm install --global xpm@latest
```

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

### xpm

This package is available as
[`@micro-os-plus/diag-trace`](https://www.npmjs.com/package/@micro-os-plus/diag-trace)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/diag-trace@latest

ls -l xpacks/@micro-os-plus/diag-trace
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/diag-trace-xpack.git \
  xpacks/@micro-os-plus/diag-trace
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## Developer info

### Overview

Temporarily adding `printf()` statements is
probably one of the oldest method to debug programs.

Modern debuggers,
which allow to single step and inspect variables, are very efficient tools,
but, in some cases, a carefully crafted sequence of messages can tell more
about how a program runs than a long debug session.

For embedded applications, it is even more preferable for the trace device
to be a separate output channel, as fast as possible, to minimise the
impact on the debugged target.

One of the fastest solutions is the
[SEGGER RTT (Real Time Transfer)](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/),
available with the J-Link probes.

Other solution, for Cortex-M devices that support it, is the
[Arm ITM (Instrumentation Trace Macrocell)](https://developer.arm.com/documentation/ddi0314/h/Instrumentation-Trace-Macrocell).

A slower solution, but still functional, is semihosting, either via
the DEBUG channel, or the OUTPUT channel.

µOS++ provides implementations for all those channels, in separate
packages.

### Status

The **diag-trace** source library is fully functional.

### C++ API

The following C++ functions are available:

```c++
// Write a formatted string to the trace device.
int micro_os_plus::trace::printf (const char *format, ...);

// Write the single character to the trace device.
int micro_os_plus::trace::putchar (int c);

// Write the string and a line terminator to the trace device.
int micro_os_plus::trace::puts (const char *s);

// Write a formatted variable arguments list to the trace device.
int micro_os_plus::trace::vprintf (const char *format, std::va_list arguments);

// Write the `argv[]` array to the trace device.
void dump_args (int argc, char* argv[], const char* name = "main");

// Flush the output.
void flush(void);

// Initialize the trace device; called by the startup code.
void initialize (void);

// Write the given number of bytes to the trace output channel.
ssize_t write (const void* buf, std::size_t nbyte);
```

### C API

The following C functions are available:

```c
// Write a formatted string to the trace device.
int micro_os_plus_trace_printf (const char *format,...);

// Write the single character to the trace device.
int micro_os_plus_trace_putchar (int c);

// Write the string and a line terminator to the trace device.
int micro_os_plus_trace_puts (const char *s);

// Write a formatted variable arguments list to the trace device.
int micro_os_plus_trace_vprintf (const char *format, std::va_list arguments);

// Write the argv[] array to the trace device.
void micro_os_plus_dump_args (int argc, char* argv[]);

// Flush the output.
void micro_os_plus_flush(void);

// Initialize the trace device.
void micro_os_plus_initialize (void);

// Write the given number of bytes to the trace output channel.
ssize_t micro_os_plus_write (const void* buf, std::size_t nbyte);
```

### Implementation

The application must provide implementations for the following
basic functions:

```c++
namespace micro_os_plus::trace
{
  // --------------------------------------------------------------------------

  void
  initialize (void)
  {
    // TODO: open the trace device.
  }

  // --------------------------------------------------------------------------

  ssize_t
  write (const void* buf, std::size_t nbyte)
  {
    if (buf == nullptr || nbyte == 0)
      {
        return 0;
      }

    // TODO: write chars from buffer to the trace channel.

    // Return the number of characters successfully sent.
    return (ssize_t) nbyte;
  }

  // --------------------------------------------------------------------------

  void
  flush (void)
  {
    // TODO the trace channel.
  }

// ----------------------------------------------------------------------------
}
```

Enabling `MICRO_OS_PLUS_TRACE` without having these functions defined,
results in missing symbols during link.

### Build & integration info

The project is written in C++ and it is expected
to be used in C and C++ projects.

The source code was compiled with GCC 11, clang 12, clang 13
arm-none-eabi-gcc 11, riscv-none-elf-gcc 12, and should be warning free.

To ease the integration of this package into user projects, there
are already made CMake and meson configuration files (see below).

For other build systems, consider the following details:

#### Include folders

The following folders should be passed to the compiler during the build:

- `include`

The header file to be included in user source files is:

```c++
#include <micro-os-plus/diag/trace.h>
```

#### Source files

The source files to be added to the build are:

- `src/trace.cpp`

#### Preprocessor definitions

There are several preprocessor definitions used to configure the build.

- `MICRO_OS_PLUS_INCLUDE_CONFIG_H` - to include `<micro-os-plus/config.h>`
- `MICRO_OS_PLUS_TRACE` - enable support for tracing

If not defined, all functions are defined as empty inlines; thus
it is not necessary to brace the calls with `#if/#endif`.

This definition is usually passed to the compiler on the command line,
generally for debug configurations.

#### Compiler options

- `-std=c++20` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- `micro_os_plus::trace`

`micro_os_plus` is the top µOS++ namespace, and `trace` is the
library namespace.

#### C++ Classes

- none

#### Dependencies

- none

#### CMake

To integrate the diag-trace source library into a CMake application,
add this folder to the build:

```cmake
add_subdirectory("xpacks/@micro-os-plus/diag-trace")`
```

The result is an interface library that can be added as an application
dependency with:

```cmake
target_link_libraries(your-target PRIVATE

  micro-os-plus::diag-trace
)
```

#### meson

To integrate the diag-trace source library into a meson application,
add this folder to the build:

```meson
subdir('xpacks/@micro-os-plus/diag-trace')
```

The result is a dependency object that can be added
to an application with:

```meson
exe = executable(
  your-target,
  link_with: [
    # Nothing, not static.
  ],
  dependencies: [
    micro_os_plus_diag_trace_dependency,
  ]
)
```

### Examples

A simple example showing how to use the `trace::printf()` functions is
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

The test platforms are GNU/Linux, macOS and Windows; native tests are
compiled with GCC and clang; tests for embedded platforms are compiled
with arm-none-eabi-gcc and risc-none-elf-gcc, and executed via QEMU.

There are two sets of tests, one that runs on every push, with a
limited number of tests, and a set that is triggered manually,
usually before releases, and runs all tests on all supported
platforms.

The full set can be run manually with the following commands:

```sh
xpm run install-all -C ~/Work/micro-os-plus/diag-trace-xpack.git
xpm run test-all -C ~/Work/micro-os-plus/diag-trace-xpack.git
```

## Change log - incompatible changes

According to [semver](https://semver.org) rules:

> Major version X (X.y.z | X > 0) MUST be incremented if any
backwards incompatible changes are introduced to the public API.

The incompatible changes, in reverse chronological order,
are:

- v4.x: rename `SYS_GET_CMDLINE` to `SYS_GETCMDLINE`
- v3.x: the weak attribute was removed from `initialize()` and `flush()`,
so there are no more defaults and both functions must be implemented by
the application;
- v2.x: the C++ namespace was renamed from `os` to `micro_os_plus`;
- v1.x: the code was extracted from the mono-repo µOS++ project.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
