#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

if(platform-native-included)
  return()
endif()

set(platform-native-included TRUE)

message(STATUS "Including platform-native...")

# -----------------------------------------------------------------------------

include("${CMAKE_CURRENT_LIST_DIR}/globals.cmake")

# -----------------------------------------------------------------------------
