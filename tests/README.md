# Tests

## Overview

The difficulty of testing this package is that it is also referred in
multiple other packages used when running the tests on embedded platforms.

There are two ways to cope with this:

- set `MICRO_OS_PLUS_BOOL_USE_TRACE` to false, to disable references in
the run-time
- make local copies of the run-time with the trace calls disabled

For now the first solution is used, and if this becomes too difficult to
maintain, the second one will be used.

## Platforms

- native (as a process on the development machine)
- QEMU mps2-an386 emulated boars, an Arm Cortex-M4 development board

The tests are performed on GNU/Linux, macOS and GNU/Linux.

Exactly the same source files are used on both platforms, without
changes.

## Toolchains

For a better portability, the builds are repeated with multiple toolchains.

For native tests, the following toolchains are used:

- GCC 8 (not available on Apple Silicon)
- GCC 11
- clang 12

For Cortex-M tests, the toolchain is arm-none-eabi-gcc 11.

## CI

The CI workflow runs the tests on every push; for details see
[CI.yml](../.github/workflows/CI.yml).

## Tests details

## no-trace-test

Validate that the environment used for the bare-metal build
was properly configured to disable all references to trace.
Not necessary for native builds.

## null-test

Test that the build passes when the library is included, but
`MICRO_OS_PLUS_TRACE` is not defined, which is the usual case for
release configurations.

## sample-test

This is a simple example exercising the
few primitives available in the tracing framework.

## unit-test

Test if all functions in the tracing framework
work as expected. The source code uses the µTest++ framework.
