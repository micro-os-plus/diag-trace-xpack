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
 * Top-level umbrella header; the only file users need to include directly.
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

#if defined(__DOXYGEN__)

/**
 * @def MICRO_OS_PLUS_DIAG_TRACE_ENABLED
 * @ingroup micro-os-plus-diag-trace
 * @brief Enables the trace output channel implementation.
 *
 * @details
 * This configuration macro has no definition site within the library
 * sources; it is only ever tested with
 * `#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)`, never defined, by the
 * library itself. The definition seen here is compiled in only when
 * `__DOXYGEN__` is defined, which is the case only while this
 * documentation is being generated; it has no effect on actual builds.
 *
 * The macro is intended to be defined by the user, typically as a
 * compiler command-line definition (for example
 * `-DMICRO_OS_PLUS_DIAG_TRACE_ENABLED`), or in the project's own
 * `micro-os-plus/diag/trace-defines.h` configuration file.
 *
 * When `MICRO_OS_PLUS_DIAG_TRACE_ENABLED` is defined, the C++ and C
 * trace functions are compiled to their full implementations, declared
 * in @ref trace-cpp-api.h and @ref trace-c-api.h, which forward all
 * calls to
 * `micro_os_plus::trace::detail::tracer<micro_os_plus::trace::detail::implementation>`.
 *
 * When it is not defined, which is the usual case for release builds,
 * all trace functions are inlined to empty (or trivial pass-through)
 * bodies. This approach allows trace calls to remain in the code
 * unconditionally, without being wrapped in
 * `#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)` guards, while still
 * being fully eliminated from the generated binary.
 */
#define MICRO_OS_PLUS_DIAG_TRACE_ENABLED

#endif // defined(__DOXYGEN__)

// ----------------------------------------------------------------------------

/**
 * @def MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER
 * @ingroup micro-os-plus-diag-trace
 * @brief The size, in bytes, of the stack buffer used to format trace
 * messages.
 *
 * @details
 * This buffer is allocated on the stack by
 * @ref micro_os_plus::trace::detail::tracer::vprintf()
 * "tracer<T>::vprintf()" to hold the message formatted by `vsnprintf()`
 * before it is forwarded to the trace channel `write()` implementation.
 * Output that exceeds this size is silently truncated.
 *
 * The definition below only supplies the default value (200 bytes),
 * used when the macro has not already been defined; the actual value
 * may be overridden by the user, typically as a compiler command-line
 * definition (for example
 * `-DMICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER=512`),
 * or in the project's own `micro-os-plus/diag/trace-defines.h`
 * configuration file.
 */
#ifndef MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER
#define MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER (200)
#endif

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
