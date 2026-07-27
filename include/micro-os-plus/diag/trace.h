/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2015-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ header file with the declarations for the µOS++ Tracing
 * Infrastructure.
 *
 * @details
 * Top-level umbrella header; the only file users need to  include directly.
 *
 * This header file includes the C++ and C API headers, which define the
 * functions that can be used to output trace messages.
 */

// ----------------------------------------------------------------------------

#ifndef MICRO_OS_PLUS_DIAG_TRACE_H_
#define MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
#if !(__cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#error "C++20 or higher is required"
#endif
#endif // defined(__cplusplus)

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/diag/trace-defines.h")
#include "micro-os-plus/diag/trace-defines.h"
#endif // __has_include("micro-os-plus/diag/trace-defines.h")

// ----------------------------------------------------------------------------
// `putchar()` hack.

// To be effective, <stdio.h> must be included *before* the putchar patch.
#include <stdio.h>

// This is a very annoying issue, some very old libraries still
// define putchar() as a macro. This is abusive, since it prevents
// the use of putchar() in other name spaces.
#if defined(putchar)
#undef putchar
#endif // defined(putchar)

// ----------------------------------------------------------------------------

// The headers are included even when tracing is disabled, as they define the
// empty inline functions needed for the trace calls to compile without
// requiring conditional compilation.

#include "trace-cpp-api.h"
#include "trace-c-api.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_DIAG_TRACE_H_

// ----------------------------------------------------------------------------
