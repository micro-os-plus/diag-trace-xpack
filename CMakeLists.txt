# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from xcdl-package.jsonc.
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# This file is intended to be used by applications via:
#
# `add_subdirectory("xpacks/@micro-os-plus/diag-trace")`
#
# This creates libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC micro-os-plus::diag-trace)
# target_link_libraries(your-target PUBLIC micro-os-plus::diag-trace-static-library)
# target_link_libraries(your-target PUBLIC micro-os-plus::diag-trace-objects-library)
# ~~~

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required (VERSION 3.20)
project (
  micro-os-plus-diag-trace
  DESCRIPTION
    "A source code library with the µOS++ trace::printf() tracing infrastructure"
  LANGUAGES CXX
)

# To access the optional functions, include the
# `cmake/micro-os-plus-build-helper.cmake` file from the
# `@micro-os-plus/build-helper` package.

if (COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version (
    "${CMAKE_CURRENT_SOURCE_DIR}/package.json"
  )
  message (VERBOSE
           "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}..."
  )
endif ()

# -----------------------------------------------------------------------------

# The interface library is the main target of this package, which consumers
# (like embedded applications) link against. It defines the public API and
# properties of the library; sources are propagated to and compiled by each
# consumer.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (micro-os-plus-diag-trace-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (
  micro-os-plus-diag-trace-interface INTERFACE "include"
)

target_sources (
  micro-os-plus-diag-trace-interface INTERFACE "src/trace-cpp-api.cpp"
                                               "src/trace-c-api.cpp"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-diag-trace-interface)
endif ()

# -----------------------------------------------------------------------------
# Alias.

# Export an alias target using namespaced syntax (Project::Target). This is the
# canonical pattern for consumption via target_link_libraries(), whether the
# dependency is added via add_subdirectory(), FetchContent, or an installed
# package via find_package(). Using "::" lets CMake detect an invalid or
# misspelled target name at configure time, rather than silently passing it
# through to the linker as a plain string or flag. Note: alias targets are
# read-only; properties must be set on the underlying target, not on the alias
# itself.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (micro-os-plus::diag-trace ALIAS micro-os-plus-diag-trace-interface)
message (VERBOSE
         "> micro-os-plus::diag-trace -> micro-os-plus-diag-trace-interface"
)

# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#object-libraries
# Optional OBJECT library: compiles the library sources once and shares the
# resulting object files across all test executables, rather than recompiling
# them per consumer.
#
# Include directories are managed explicitly instead of using PRIVATE linkage to
# the interface library. PRIVATE linkage would cause dependency sources to be
# compiled into this OBJECT library via transitive propagation, which conflicts
# with the separate dependency compilation in each executable. Consumers of this
# OBJECT library are expected to link separately to all dependencies and to the
# platform-specific library.
add_library (micro-os-plus-diag-trace-objects-library OBJECT EXCLUDE_FROM_ALL)

# Use PUBLIC so that the include directories are available both for the OBJECT
# library's own sources and for consumers of the library.
target_include_directories (
  micro-os-plus-diag-trace-objects-library PUBLIC "include"
)

# Use PRIVATE to avoid propagating the sources to consumers of the OBJECT
# library, which would cause duplicate symbol errors at link time.
target_sources (
  micro-os-plus-diag-trace-objects-library PRIVATE "src/trace-cpp-api.cpp"
                                                   "src/trace-c-api.cpp"
)

# Propagate the compiled object files to consumers via INTERFACE_SOURCES so that
# CMake includes them in the final link even when this OBJECT library is
# referenced only transitively through an INTERFACE library chain. Without this,
# CMake does not automatically inject $<TARGET_OBJECTS:...> for indirect OBJECT
# library dependencies reached via INTERFACE libraries.
target_sources (
  micro-os-plus-diag-trace-objects-library
  INTERFACE "$<TARGET_OBJECTS:micro-os-plus-diag-trace-objects-library>"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-diag-trace-objects-library)
endif ()

# -----------------------------------------------------------------------------
# Alias.

# Namespaced alias for downstream consumption (find_package- and
# add_subdirectory-compatible). "::" ensures CMake validates the target name at
# configure time. Aliases are read-only.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::diag-trace-objects-library ALIAS
  micro-os-plus-diag-trace-objects-library
)
message (
  VERBOSE
  "> micro-os-plus::diag-trace-objects-library -> micro-os-plus-diag-trace-objects-library"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# Optional STATIC library: compiles the library sources into an archive that is
# linked into each consumer executable, rather than sharing object files.
#
# Include directories are managed explicitly instead of using PRIVATE linkage to
# the interface library. PRIVATE linkage would cause dependency sources to be
# compiled into this STATIC library via transitive propagation, which conflicts
# with the separate dependency compilation in each executable. Consumers of this
# STATIC library are expected to link separately to all dependencies and to the
# platform-specific library.
add_library (micro-os-plus-diag-trace-static-library STATIC EXCLUDE_FROM_ALL )

set_target_properties (
  micro-os-plus-diag-trace-static-library PROPERTIES OUTPUT_NAME diag-trace
)

# Use PUBLIC so that the include directories are available both for the STATIC
# library's own sources and for consumers of the library.
target_include_directories (
  micro-os-plus-diag-trace-static-library PUBLIC "include"
)

# Use PRIVATE to avoid propagating the sources to consumers of the STATIC
# library, which would cause duplicate symbol errors at link time.
target_sources (
  micro-os-plus-diag-trace-static-library PRIVATE "src/trace-cpp-api.cpp"
                                                  "src/trace-c-api.cpp"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-diag-trace-static-library)
endif ()

# -----------------------------------------------------------------------------
# Alias.

# Namespaced alias for downstream consumption (find_package- and
# add_subdirectory-compatible). "::" ensures CMake validates the target name at
# configure time. Aliases are read-only.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::diag-trace-static-library ALIAS
  micro-os-plus-diag-trace-static-library
)
message (
  VERBOSE
  "> micro-os-plus::diag-trace-static-library -> micro-os-plus-diag-trace-static-library"
)

# -----------------------------------------------------------------------------
