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

// clang-format off
// ----------------------------------------------------------------------------

#include <micro-os-plus/architecture.h>
#include <micro-os-plus/architecture-cortexm/exception-handlers.h>

// ----------------------------------------------------------------------------

void __attribute__((weak))
Default_Handler(void);

// ----------------------------------------------------------------------------

extern uint32_t _initial_main_stack_pointer;

typedef void
(*handler_ptr_t)(void);

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpedantic"

/**
 * The table of interrupt handlers. It has an explicit section name
 * and relies on the linker script to place it at the correct location
 * in memory, usually at the very beginning of the flash bank.
 */
__attribute__ ((section(".interrupt_vectors"),used))
handler_ptr_t _interrupt_vectors[] =
  {
    // Cortex-M Core Handlers
    (handler_ptr_t) &_initial_main_stack_pointer, // MSP
    Reset_Handler,                     // The reset handler

    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    MemManage_Handler,                 // The MPU fault handler
    BusFault_Handler,                  // The bus fault handler
    UsageFault_Handler,                // The usage fault handler
#else
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
#endif
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    DebugMon_Handler,                  // Debug monitor handler
#else
    0,                                 // Reserved
#endif
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // ------------------------------------------------------------------------
    // External Interrupts
    // Not used by the generic QEMU machine.
};

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

/**
 * The processor ends up here if an unexpected interrupt occurs or a
 * specific handler is not present in the application code.
 * When in DEBUG, trigger a debug exception to clearly notify
 * the user of the exception and help identify the cause.
 */
void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
#if defined(MICRO_OS_PLUS_DEBUG)
  micro_os_plus_architecture_brk();
#endif
  while (1)
    {
      ;
    }
}

// ----------------------------------------------------------------------------
