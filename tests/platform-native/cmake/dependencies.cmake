# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file adds the platform dependencies.

message (STATUS "${CMAKE_SOURCE_DIR}")

set(xpack_dependencies_folders
  # Project dependencies.
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/architecture-synthetic-posix"
  "${CMAKE_SOURCE_DIR}/../xpacks/@micro-os-plus/micro-test-plus"

  # Build configuration dependencies.
  # None
)

xpack_add_dependencies_subdirectories("${xpack_dependencies_folders}" "xpacks-bin")

# -----------------------------------------------------------------------------
