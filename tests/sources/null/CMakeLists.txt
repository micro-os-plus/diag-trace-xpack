# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from sources/null/xcdl-test.jsonc.
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
# `add_subdirectory("sources/null")`
#
# This creates an interface library that can be linked to a target with:
#
# `target_link_libraries(your-target PUBLIC tests-null)`

# -----------------------------------------------------------------------------

# Check if the library compiles when MICRO_OS_PLUS_TRACE_ENABLED is not defined.
message (VERBOSE "Processing 'sources/null'...")

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (tests-null-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (tests-null-interface INTERFACE "include")

target_sources (tests-null-interface INTERFACE "src/main.cpp" "src/c-api.c")

target_link_libraries (
  tests-null-interface INTERFACE "micro-os-plus::diag-trace"
)

xpack_display_target_lists (tests-null-interface)

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
add_library (tests::null ALIAS tests-null-interface)
message (VERBOSE "> tests::null -> tests-null-interface")

# -----------------------------------------------------------------------------
