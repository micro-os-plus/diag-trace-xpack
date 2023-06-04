# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

message(VERBOSE "Processing 'tests/platform-qemu-mps2-an386'...")

# -----------------------------------------------------------------------------

set(xpack_platform_compile_definition "PLATFORM_QEMU_MPS2_AN386")

# set(xpack_create_listing true)
# set(xpack_create_hex true)

# -----------------------------------------------------------------------------

add_subdirectory("dependencies/semihosting")
add_subdirectory("dependencies/devices-cortexm")
add_subdirectory("dependencies/startup")
add_subdirectory("dependencies/libs-c")
add_subdirectory("dependencies/libs-cpp")
add_subdirectory("dependencies/devices-qemu-cortexm")

# -----------------------------------------------------------------------------
# Define the platform library.

add_library(platform-qemu-mps2-an386-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_include_directories(platform-qemu-mps2-an386-interface INTERFACE
  "include-platform"
)

target_sources(platform-qemu-mps2-an386-interface INTERFACE
  "src/initialize-hardware.cpp"
  "src/interrupts-handlers.cpp"
)

target_compile_definitions(platform-qemu-mps2-an386-interface INTERFACE
  "${xpack_platform_compile_definition}"
)

target_compile_options(platform-qemu-mps2-an386-interface INTERFACE
  # None.
)

target_link_libraries(platform-qemu-mps2-an386-interface INTERFACE
  micro-os-plus::devices-qemu-cortexm
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(platform-qemu-mps2-an386-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::platform ALIAS platform-qemu-mps2-an386-interface)
message(VERBOSE "> micro-os-plus::platform -> platform-qemu-mps2-an386-interface")

# =============================================================================
# Define the tests executables.

if("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
  set(extension ".cmd")
endif()

function(add_test_executable name)

  add_executable(${name})

  set_target_properties(${name}

    PROPERTIES
      OUTPUT_NAME "${name}"
  )

  # Include folders.
  # `tests/platform-qemu-mps2-an386/include` was added globally.
  target_include_directories(${name} PRIVATE
      "../include"
  )

  message(VERBOSE "A+ -I tests/include")

  # Application sources.
  target_sources(${name} PRIVATE
      "../src/${name}.cpp"
  )

  message(VERBOSE "A+ tests/src/${name}.cpp")

  target_compile_definitions(${name} PRIVATE
    # None
  )

  target_compile_options(${name} PRIVATE
    # None
  )

  target_link_options(${name} PRIVATE
    -nostartfiles

    # Force the linker to keep the interrupt vectors which otherwise
    # are not referred from anywhere.
    -u_interrupt_vectors

    # nano has no exceptions.
    # -specs=nano.specs

    -Wl,--gc-sections

    -Wl,-Map,platform-bin/${name}-map.txt
    # -v

    # Including files from other packages is not very nice, but functional.
    # Use absolute paths, otherwise set -L.
    -T${CMAKE_SOURCE_DIR}/platform-qemu-mps2-an386/dependencies/devices-qemu-cortexm/linker-scripts/mem.ld
    -T${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/architecture-cortexm/linker-scripts/sections.ld
  )

  target_link_libraries(${name}  PRIVATE
    # Tested library.
    micro-os-plus::diag-trace

    # Portable dependencies.
    # None.

    # Platform specific dependencies.
    micro-os-plus::platform # bring device & architecture too.

    micro-os-plus::libs-c
    micro-os-plus::libs-cpp
    micro-os-plus::semihosting
    micro-os-plus::startup
  )

  # TODO use add_custom_target()
  # https://cmake.org/cmake/help/v3.20/command/add_custom_command.html
  add_custom_command(TARGET ${name} POST_BUILD
    COMMAND ${CMAKE_SIZE} --format=berkeley "$<TARGET_FILE:${name}>"
  )

  if (xpack_create_hex)
    add_custom_command(TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} -O ihex "$<TARGET_FILE:${name}>" "$<TARGET_FILE:${name}>.hex"
    )
  endif()

  if(xpack_create_listing)
    add_custom_command(TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_OBJDUMP} --source --all-headers --demangle --line-numbers --wide "$<TARGET_FILE:${name}>" > ${name}-list.txt
      VERBATIM
    )
  endif()

  message(VERBOSE "A> ${name}")

endfunction()

# -----------------------------------------------------------------------------

if (ENABLE_NO_TRACE_TEST)

  add_test_executable(no-trace-test)

  target_compile_definitions(no-trace-test PRIVATE
    "MICRO_OS_PLUS_TRACE"
  )

  add_test(
    NAME "no-trace-test"

    COMMAND qemu-system-arm${extension}
      --machine mps2-an386
      --cpu cortex-m4
      --kernel no-trace-test.elf
      --nographic
      -d unimp,guest_errors
      --semihosting-config enable=on,target=native
      --semihosting-config arg=null-test
  )

endif()

# -----------------------------------------------------------------------------

if (ENABLE_NULL_TEST)

  add_test_executable(null-test)

  # This tests does not have MICRO_OS_PLUS_TRACE defined.

  add_test(
    NAME "null-test"

    COMMAND qemu-system-arm${extension}
      --machine mps2-an386
      --cpu cortex-m4
      --kernel null-test.elf
      --nographic
      -d unimp,guest_errors
      --semihosting-config enable=on,target=native
      --semihosting-config arg=null-test
  )

endif()

# -----------------------------------------------------------------------------

if (ENABLE_SAMPLE_TEST)

  add_test_executable(sample-test)

  target_compile_definitions(sample-test PRIVATE
    "MICRO_OS_PLUS_TRACE"
  )

  add_test(
    NAME "sample-test"

    COMMAND qemu-system-arm${extension}
      --machine mps2-an386
      --cpu cortex-m4
      --kernel sample-test.elf
      --nographic
      -d unimp,guest_errors
      --semihosting-config enable=on,target=native
      --semihosting-config arg=sample-test,arg=one,arg=two
  )

endif()

# -----------------------------------------------------------------------------

if (ENABLE_UNIT_TEST)

  add_test_executable(unit-test)

  target_compile_definitions(unit-test PRIVATE
    "MICRO_OS_PLUS_TRACE"
  )

  target_link_libraries(unit-test  PRIVATE
    micro-os-plus::micro-test-plus
  )

  add_test(
    NAME "unit-test"

    COMMAND qemu-system-arm${extension}
      --machine mps2-an386
      --cpu cortex-m4
      --kernel unit-test.elf
      --nographic
      -d unimp,guest_errors
      --semihosting-config enable=on,target=native
      --semihosting-config arg=unit-test
      # --semihosting-config arg=--verbose
  )

endif()

# -----------------------------------------------------------------------------

