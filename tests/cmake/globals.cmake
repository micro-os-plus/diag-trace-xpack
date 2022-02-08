#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Add definitions for all source files compiled in the `tests` folder.
message(VERBOSE "Including global definitions...")

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_compile_definitions.html

add_compile_definitions(
  # NDEBUG is provided by the toolchain definitions on release.

  # DO NOT use CMAKE_BUILD_TYPE
  $<$<CONFIG:Debug>:DEBUG>
  MICRO_OS_PLUS_HAS_CONFIG_H
)

include_directories(
  # Folders are relative to `tests`.
  "platform-${PLATFORM_NAME}/include-config"
)

# When `-flto` is used, the compile options must be passed to the linker too.
# add_compile_options()
# add_link_options()

# -----------------------------------------------------------------------------
