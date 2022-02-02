
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
# `subdir('xpacks/micro-os-plus-micro-test-plus')`
#
# The result is a dependency that can be refered as:
#
# `dependencies: [micro_os_plus_diag_trace_dependency],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @micro-os-plus/diag-trace...')

# https://mesonbuild.com/Reference-manual.html#declare_dependency
micro_os_plus_diag_trace_dependency = declare_dependency(
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/trace.cpp',
  ),
)

message('+ -I include')
message('+ src/trace.cpp')
message('> micro_os_plus_diag_trace_dependency')

# -----------------------------------------------------------------------------
