# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/@micro-os-plus/libs-cpp')`
#
# The result is a dependency that can be referred as:
#
# `dependencies: [micro_os_plus_libs_cpp_dependency],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing local libs-cpp...')

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_libs_cpp_dependency = declare_dependency(
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/cxx.cpp',
    'src/system-error.cpp',
  ),
  compile_args: [
    # None.
  ],
  dependencies: [
    # micro_os_plus_diag_trace_dependency,
  ]
)

message('+ -I include')
message('+ src/cxx.cpp')
message('+ src/system-error.cpp')
message('> micro_os_plus_libs_cpp_dependency')

# -----------------------------------------------------------------------------
