/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2015-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include <micro-os-plus/diag/trace.h>

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
// #pragma clang diagnostic ignored "-Wunknown-warning-option"
// #pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

namespace micro_os_plus::trace::detail
{
  // --------------------------------------------------------------------------
  // Explicit instantiation of the whole class, once per policy class.
  // This instantiates all member functions (printf, vprintf, puts,
  // putchar, dump_args) in one line, and makes them visible to the
  // linker from other translation units. Do the same in your project
  // for any user-defined policy class.
  // --------------------------------------------------------------------------

  template class tracer<implementation>;

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::trace::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

// ----------------------------------------------------------------------------
