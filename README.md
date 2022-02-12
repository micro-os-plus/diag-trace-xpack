[![license](https://img.shields.io/github/license/micro-os-plus/diag-trace-xpack)](https://github.com/micro-os-plus/diag-trace-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/diag-trace-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/diag-trace-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source xPack with the µOS++ `trace::printf()` tracing infrastructure

This project provides support for a separate tracing channel, different
from the standard output or error streams. The API is similar to the
standard functions:

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

Note: the package will be available from npmjs.com at a later date.

For now, it can be installed from GitHub:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install github:micro-os-plus/diag-trace-xpack
```

When ready, this package will be available as
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

All functions have C equivalents:

`int 	micro_os_plus::trace::printf (const char *format, ...)`
 Write a formatted string to the trace device.

`int 	micro_os_plus::trace::putchar (int c)`
 Write the single character to the trace device.

`int 	micro_os_plus::trace::puts (const char *s)`
 Write the string and a line terminator to the trace device.

`int 	micro_os_plus::trace::vprintf (const char *format, std::va_list arguments)`
 Write a formatted variable arguments list to the trace device.

### C API

The following functions are available:

`int 	trace_printf (const char *format,...)`
 Write a formatted string to the trace device.

`int 	trace_putchar (int c)`
 Write the single character to the trace device.

`int 	trace_puts (const char *s)`
 Write the string and a line terminator to the trace device.

`int 	trace_vprintf (const char *format, std::va_list arguments)`
 Write a formatted variable arguments list to the trace device.

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
      ; // TODO flush port
    }

  // --------------------------------------------------------------------------
  }
}
```

### Build & integration info

To include this package in a project, consider the following details.

#### Source folders

- `src`

#### Include folders

- `include`

TODO: list the available headeres

#### Preprocessor definitions

The

#### Compiler options

- `-std=c++17` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- `micro_os_plus::trace`

#### C++ Classes

- None

### Examples

TBD

### Known problems

- none

### Tests

TBD

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).
