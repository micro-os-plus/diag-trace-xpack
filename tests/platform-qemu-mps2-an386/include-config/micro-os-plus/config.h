/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

#ifndef MICRO_OS_PLUS_CONFIG_H_
#define MICRO_OS_PLUS_CONFIG_H_

// ----------------------------------------------------------------------------

// Disable references to trace functions, even if `MICRO_OS_PLUS_TRACE`
// is defined.
#define MICRO_OS_PLUS_BOOL_USE_TRACE (false)

// On bare-metal platforms, tests are semihosted applications.
#define MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS

// ----------------------------------------------------------------------------

#endif /* MICRO_OS_PLUS_CONFIG_H_ */

// ----------------------------------------------------------------------------
