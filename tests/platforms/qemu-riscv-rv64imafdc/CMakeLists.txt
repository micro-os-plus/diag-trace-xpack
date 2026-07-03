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

message (VERBOSE "Processing 'tests/platforms/qemu-riscv-rv64imafdc'...")

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_NULL_TEST)
  add_cross_test_executable (null-test)
  target_link_cross_test_libraries (null-test tests::null)

  xpack_display_target_lists (null-test)
  message (VERBOSE "A> null-test")

  add_test (
    NAME "null-test"
    COMMAND
      qemu-system-riscv64${extension} --machine virt --cpu rv64 --kernel
      null-test.elf -smp 1 -bios none --nographic -d unimp,guest_errors
      --semihosting-config enable=on,target=native
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_cross_test_executable (sample-test)
  target_link_cross_test_libraries (sample-test tests::sample)

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  add_test (
    NAME "sample-test"
    COMMAND
      qemu-system-riscv64${extension} --machine virt --cpu rv64 --kernel
      sample-test.elf -smp 1 -bios none --nographic -d unimp,guest_errors
      --semihosting-config
      enable=on,target=native,arg=sample-test,arg=one,arg=two
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_cross_test_executable (unit-test)
  target_link_cross_test_libraries (unit-test tests::unit)

  xpack_display_target_lists (unit-test)
  message (VERBOSE "A> unit-test")

  add_test (
    NAME "unit-test"
    COMMAND
      qemu-system-riscv64${extension} --machine virt --cpu rv64 --kernel
      unit-test.elf --nographic -smp 1 -bios none -d unimp,guest_errors
      --semihosting-config enable=on,target=native,arg=unit-test
  )
endif ()

# -----------------------------------------------------------------------------
