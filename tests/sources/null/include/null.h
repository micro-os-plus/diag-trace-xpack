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

#ifndef NULL_H_
#define NULL_H_

// ----------------------------------------------------------------------------

#include <micro-os-plus/diag/trace.h>

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif // defined(__cplusplus)

  // ----------------------------------------------------------------------------

  int
  c_api (int argc, char* argv[]);

  // ----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // NULL_H_

// ----------------------------------------------------------------------------
