/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2022 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

/*
 * This test checks that the environment no longer has references to trace
 * function.
 */

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if !defined(MICRO_OS_PLUS_TRACE)
#error "MICRO_OS_PLUS_TRACE should be defined"
#endif

#if MICRO_OS_PLUS_BOOL_USE_TRACE
#error "MICRO_OS_PLUS_BOOL_USE_TRACE should not be defined"
#endif

#include <stdio.h>

int
main ()
{
  printf ("Hello %s!\n", "World");

  return 0;
}

// ----------------------------------------------------------------------------
