# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from build-helper/templates/*.
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# Create the platform specific test executables.

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/platforms/native'...")

# -----------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID STREQUAL
                                          "AppleClang"
)
  # Enable it temporarily to check the coverage on macOS.
  set (XPACK_ENABLE_COVERAGE false)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_NO_TRACE_TEST)
  add_native_test_executable (no-trace-test)
  target_link_native_test_libraries (no-trace-test tests::no-trace)

  xpack_display_target_lists (no-trace-test)
  message (VERBOSE "A> no-trace-test")

  add_test (NAME "no-trace-test" COMMAND no-trace-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_NULL_TEST)
  add_native_test_executable (null-test)
  target_link_native_test_libraries (null-test tests::null)

  xpack_display_target_lists (null-test)
  message (VERBOSE "A> null-test")

  add_test (NAME "null-test" COMMAND null-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test tests::sample)

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  add_test (NAME "sample-test" COMMAND sample-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_native_test_executable (unit-test)
  target_link_native_test_libraries (unit-test tests::unit)

  if (XPACK_ENABLE_COVERAGE)
    add_compile_coverage_private_options (unit-test)
    add_link_coverage_private_options (unit-test)
  endif ()

  xpack_display_target_lists (unit-test)
  message (VERBOSE "A> unit-test")

  add_test (NAME "unit-test" COMMAND unit-test one two)

  if (XPACK_ENABLE_COVERAGE)
    set_tests_properties (
      "unit-test" PROPERTIES ENVIRONMENT "LLVM_PROFILE_FILE=unit-test.profraw"
    )

    add_test (
      NAME "unit-test-coverage"
      COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/show-coverage.sh"
              unit-test unit-test
    )
    set_tests_properties ("unit-test-coverage" PROPERTIES DEPENDS "unit-test")
  endif ()
endif ()

# -----------------------------------------------------------------------------
