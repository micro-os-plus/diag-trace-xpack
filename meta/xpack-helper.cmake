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

function(add_libraries_micro_os_plus_diag_trace)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  # ---------------------------------------------------------------------------

  if(NOT TARGET micro-os-plus-diag-trace-static)

    add_library(micro-os-plus-diag-trace-static STATIC EXCLUDE_FROM_ALL)

    # -------------------------------------------------------------------------

    target_sources(
      micro-os-plus-diag-trace-static
  
      PRIVATE
        ${xpack_current_folder}/src/trace.cpp
    )
  
    target_include_directories(
      micro-os-plus-diag-trace-static
  
      PUBLIC
        ${xpack_current_folder}/include
    )

    # -------------------------------------------------------------------------
    # Aliases

    add_library(micro-os-plus::diag-trace-static ALIAS micro-os-plus-diag-trace-static)
    message(STATUS "micro-os-plus::diag-trace-static")

  endif()

  # ---------------------------------------------------------------------------

endfunction()

# -----------------------------------------------------------------------------
