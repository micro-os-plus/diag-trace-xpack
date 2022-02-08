# Tests

There are two tests available, a unit test and a sample test.

The CI workflow runs several tests, both as native processes and as
semihosted applications emulated by QEMU; for details see
[CI.yml](../.github/workflows/CI.yml).

Exactly the same source files are built on both platforms, without
changes.

## Unit test

The `unit-test.cpp` file checks if all functions in the tracing framework
work as expected.

## Sample

The `sample-test.cpp` file is a simple example exercising the
few primitives available in the tracing framework.
