# Tests

There are two tests available, a unit test and a sample test.

The tests run only as native processes on macOS and GNU/Linux.

Running on bare-metal is more complicated, since the existing testing
environment also includes these trace functions, and would require
special measures to move them to a separate namespace.

The CI workflow runs all tests on GitHub Pages.

## Unit test

The `unit-test.cpp` file checks each function, in C++ and in C.

## Sample

The `sample-test.cpp` file is a simple example exercising the
few primitives available.
