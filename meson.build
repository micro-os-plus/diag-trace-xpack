# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2021 Liviu Ionescu
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
# `subdir('xpacks/micro-os-plus-diag-trace')`
#
# The result is a dependency that can be refered as:
#
# `dependencies: [micro_os_plus_diag_trace_dependency],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @micro-os-plus/diag-trace...')

xpack_common_args = []
xpack_c_args = []
xpack_cpp_args = []
xpack_include_directories = []
xpack_sources = []
xpack_compile_definitions = []

xpack_include_directories += [
  'include',
]

xpack_sources += [
  'src/trace.cpp',
]

# https://mesonbuild.com/Reference-manual.html#declare_dependency
micro_os_plus_diag_trace_dependency = declare_dependency(
  include_directories: include_directories(xpack_include_directories),
  compile_args: xpack_common_args,
  sources: files(xpack_sources),
)

# Dependencies cannot store language specific definitions, the only
# way is to pass them via global variables. All applications including
# this dependency must also consider them.
# micro_os_plus_diag_trace_dependency_c_args = xpack_c_args
# micro_os_plus_diag_trace_dependency_cpp_args = xpack_cpp_args

foreach name : xpack_include_directories
  message('+ -I ' + name)
endforeach
foreach name : xpack_sources + xpack_common_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_diag_trace_dependency')

# -----------------------------------------------------------------------------
