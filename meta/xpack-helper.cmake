#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

if(micro-os-plus-diag-trace-included)
  return()
endif()

set(micro-os-plus-diag-trace-included TRUE)

message(STATUS "Including micro-os-plus-diag-trace...")

# -----------------------------------------------------------------------------

function(target_sources_micro_os_plus_diag_trace target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PUBLIC
      ${xpack_current_folder}/src/trace.cpp
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_include_directories_micro_os_plus_diag_trace target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${xpack_current_folder}/include
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_compile_definitions_micro_os_plus_diag_trace target)

  # None

endfunction()

# =============================================================================

function(add_libraries_micro_os_plus_diag_trace)

  # ---------------------------------------------------------------------------

  if (NOT TARGET micro-os-plus::diag-trace)

    add_library(micro-os-plus-diag-trace-objects OBJECT EXCLUDE_FROM_ALL)

    target_sources_micro_os_plus_diag_trace(micro-os-plus-diag-trace-objects)
    target_include_directories_micro_os_plus_diag_trace(micro-os-plus-diag-trace-objects)
    target_compile_definitions_micro_os_plus_diag_trace(micro-os-plus-diag-trace-objects)

    add_library(micro-os-plus::diag-trace ALIAS micro-os-plus-diag-trace-objects)
    message(STATUS "micro-os-plus::diag-trace")

    target_link_libraries(
      micro-os-plus-diag-trace-objects

      PUBLIC
        micro-os-plus::common
    )

  endif()

  # ---------------------------------------------------------------------------

if(true)
  if(NOT TARGET micro-os-plus-diag-trace-static)

    add_library(micro-os-plus-diag-trace-static STATIC EXCLUDE_FROM_ALL)

    target_sources_micro_os_plus_diag_trace(micro-os-plus-diag-trace-static)
    target_include_directories_micro_os_plus_diag_trace(micro-os-plus-diag-trace-static)
    target_compile_definitions_micro_os_plus_diag_trace(micro-os-plus-diag-trace-static)

    add_library(micro-os-plus::diag-trace-static ALIAS micro-os-plus-diag-trace-static)

    target_link_libraries(
      micro-os-plus-diag-trace-static
      
      PUBLIC
        micro-os-plus::common
    )

  endif()
endif()

  # ---------------------------------------------------------------------------

endfunction()

# -----------------------------------------------------------------------------
