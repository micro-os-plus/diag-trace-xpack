/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#if defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/startup/hooks.h>
#include <micro-os-plus/device.h>

// ----------------------------------------------------------------------------

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
extern unsigned int __vectors_start;
#endif

// ----------------------------------------------------------------------------

/**
 * @details
 * This is the default early hardware initialisation routine.
 *
 * It is called right at the beginning of `_start()`, to switch clocks
 * to higher frequencies and have the rest of the initialisations run faster.
 *
 * The application can redefine it
 * for more complex cases that requires inits before DATA and BSS init.
 *
 * It is mandatory on platforms like Kinetis, which start with the
 * watch dog enabled and require an early sequence to disable it.
 *
 * Also useful on platform with external RAM, that need to be
 * initialised before filling the BSS section.
 */
void __attribute__ ((weak))
micro_os_plus_startup_initialize_hardware_early (void)
{
  // Call the CSMSIS system initialisation routine.
  SystemInit ();

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

  // Set VTOR to the actual address, provided by the linker script.
  // Override the manual, possibly wrong, SystemInit() setting.
  SCB->VTOR = (uint32_t) (&__vectors_start);
  // Ensure all subsequence instructions use the new configuration.
  __DSB ();

#endif // defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

  // The current version of SystemInit() leaves the value of the clock
  // in a RAM variable (SystemCoreClock), which will be cleared shortly,
  // so it needs to be recomputed after the RAM initialisations
  // are completed.

#if defined(MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_FP) || defined(__ARM_FP)

  // Normally FP init is done by SystemInit(). In case this is not done
  // there, it is possible to force its inclusion by defining
  // MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_FP.

  // Enable the Cortex-M4 FPU only when -mfloat-abi=hard or -mfloat-abi=softfp.
  // Code taken from Section 7.1, Cortex-M4 TRM (DDI0439C)

  // Set bits 20-23 to enable CP10 and CP11 coprocessor.
  SCB->CPACR |= (0xF << 20);

  // Lazy save.
  FPU->FPCCR |= FPU_FPCCR_ASPEN_Msk | FPU_FPCCR_LSPEN_Msk;

#endif // defined(MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_FP) || defined (__ARM_FP)

#if defined(MICRO_OS_PLUS_DEBUG_SEMIHOSTING_FAULTS)

  SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;

#endif
}

// ----------------------------------------------------------------------------

#endif // defined(__ARM_EABI__)

// ----------------------------------------------------------------------------
