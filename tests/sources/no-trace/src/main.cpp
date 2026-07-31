/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/*
 * This test checks that the environment no longer has references to trace
 * function.
 */

#if !defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)
#error "MICRO_OS_PLUS_DIAG_TRACE_ENABLED should be defined"
#endif // !defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

#include <stdio.h>

int
main ()
{
  printf ("Hello %s!\n", "World");

  return 0;
}

// ----------------------------------------------------------------------------
