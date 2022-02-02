#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `find_package(micro-os-plus-diag-trace REQUIRED)`
#
# or, if CMake packages are not used, manually with:
#
# `add_subdirectory("xpacks/micro-os-plus-diag-trace")`
#
# The result is a library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::diag-trace)`
#
# To avoid poluting this file with test related details, there is a separate
# CMake configuration in the `tests` folder.

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(
  micro-os-plus-diag-trace
  DESCRIPTION "µOS++ tracing infrastructure"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

add_library(micro-os-plus-diag-trace-static STATIC EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_sources(
  micro-os-plus-diag-trace-static

  PRIVATE
    "src/trace.cpp"
)

message(VERBOSE "+ src/trace.cpp")

target_include_directories(
  micro-os-plus-diag-trace-static

  PUBLIC
    "include"
)

message(VERBOSE "+ include")

target_compile_options(
  micro-os-plus-diag-trace-static

  PRIVATE
    # ...
)

# -----------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::diag-trace ALIAS micro-os-plus-diag-trace-static)
message(VERBOSE "> micro-os-plus::diag-trace -> micro-os-plus-diag-trace-static")

# -----------------------------------------------------------------------------
