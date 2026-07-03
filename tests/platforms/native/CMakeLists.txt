# -----------------------------------------------------------------------------
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

if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID STREQUAL
                                          "AppleClang"
)
  # Enable it temporarily to check the coverage on macOS.
  set (XPACK_ENABLE_COVERAGE true)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_NO_TRACE_TEST)
  add_native_test_executable (no-trace-test)
  target_link_native_test_libraries (no-trace-test tests::no-trace)
  target_compile_definitions (no-trace-test PRIVATE "MICRO_OS_PLUS_TRACE")

  xpack_display_target_lists (no-trace-test)
  message (VERBOSE "A> no-trace-test")

  add_test (NAME "no-trace-test" COMMAND no-trace-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_NULL_TEST)
  add_native_test_executable (null-test)
  target_link_native_test_libraries (null-test tests::null)

  # MICRO_OS_PLUS_TRACE must **not** be defined
  xpack_display_target_lists (null-test)
  message (VERBOSE "A> null-test")

  add_test (NAME "null-test" COMMAND null-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test tests::sample)
  target_compile_definitions (sample-test PRIVATE "MICRO_OS_PLUS_TRACE")

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  add_test (NAME "sample-test" COMMAND sample-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_native_test_executable (unit-test)
  target_link_native_test_libraries (unit-test tests::unit)
  target_compile_definitions (unit-test PUBLIC "MICRO_OS_PLUS_TRACE")

  target_link_libraries (unit-test PRIVATE micro-os-plus::micro-test-plus)

  if (XPACK_ENABLE_COVERAGE)
    # Otherwise only the library cpp and its inline are shown.
    add_compile_coverage_private_options (unit-test)
    add_link_coverage_private_options (unit-test)
  endif ()

  xpack_display_target_lists (unit-test)
  message (VERBOSE "A> unit-test")

  add_test (NAME "unit-test" COMMAND unit-test)

  if (XPACK_ENABLE_COVERAGE)
    set_tests_properties (
      "unit-test" PROPERTIES ENVIRONMENT "LLVM_PROFILE_FILE=unit-test.profraw"
    )

    add_test (
      NAME "unit-test-coverage"
      COMMAND
        bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/show-coverage.sh"
        unit-test unit-test
        # "../../../../include/micro-os-plus/utils/inlines/intrusive-list-inlines.h"
    )
    set_tests_properties ("unit-test-coverage" PROPERTIES DEPENDS "unit-test")
  endif ()

endif ()

# -----------------------------------------------------------------------------
