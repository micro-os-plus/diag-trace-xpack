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

#if (!(defined(__APPLE__) || defined(__linux__) || defined(__unix__))) \
    || defined(__DOXYGEN__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if !defined(MICRO_OS_PLUS_BOOL_USE_TRACE)
#define MICRO_OS_PLUS_BOOL_USE_TRACE (true)
#endif

#if MICRO_OS_PLUS_BOOL_USE_TRACE
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE

#include <micro-os-plus/architecture.h>
#include <micro-os-plus/startup/hooks.h>
#include <micro-os-plus/startup/defines.h>
#include <micro-os-plus/version.h>

#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <sys/types.h>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------
// This file defines the startup code for a portable embedded
// C/C++ application, built with newlib.
//
// Control reaches `_start()` from the reset handler.
//
// The actual steps performed are:
// - copy the initialized data region(s)
// - clear the BSS region(s)
// - initialize the system
// - run the preinit/init array (for the C++ static constructors)
// - initialize the arc/argv
// - call main()
// - run the fini array (for the C++ static destructors)
// - call _exit(), directly or via exit()
//
// If MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS is defined, the
// code is capable of initializing multiple regions.
//
// Note: External memory with variable size (size known after reading the
// chip type) cannot be initialized via these linker script static tables
// and need to be processed in the
// `micro_os_plus_startup_initialize_hardware_early ()` hook.
//
// The normal configuration is standalone, with all support
// functions implemented locally.
//
// For this to included by the linker, the project linker must be configured
// without the startup sequence (-nostartfiles).
// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_INCLUDE_STARTUP_GUARD_CHECKS)
#define MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS (true)
#endif // !defined(MICRO_OS_PLUS_INCLUDE_STARTUP_GUARD_CHECKS)

// ----------------------------------------------------------------------------

// All following symbols should be defined in the linker script.
#if !defined(MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS)

// Begin address for the initialization values of the .data section.
extern std::uintptr_t __data_load_addr__;
// Begin address for the .data section.
extern std::uintptr_t __data_begin__;
// End address for the .data section.
extern std::uintptr_t __data_end__;

// Begin address for the .bss section.
extern std::uintptr_t __bss_begin__;
// End address for the .bss section.
extern std::uintptr_t __bss_end__;

#else

// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Memory regions initialization
// arrays". These arrays are created by the linker via the managed linker
// script of each RW data mechanism. It contains the load address, execution
// address and length section and the execution and length of each BSS (zero
// initialized) section.
extern uint32_t __data_regions_array_begin__;
extern uint32_t __data_regions_array_end__;

extern uint32_t __bss_regions_array_begin__;
extern uint32_t __bss_regions_array_end__;

#endif // MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS

extern uint32_t __heap_begin__;
extern uint32_t __heap_end__;

// Note: Strictly speaking, according to the recent C/C++ standards,
// using symbols defined in the linker scripts rely on undefined
// behaviour, since comparing pointers that do not point to elements
// of the same area or members of the same object is undefined.
// The danger is that compilers that perform very aggressive
// optimizations may completely remove such code.
// If this happens, the workaround is to disable the specific
// optimization that caused it, or reduce the optimization level
// for this file only.

extern "C" int
main (int argc, char* argv[]);

// ----------------------------------------------------------------------------

// Forward declarations

extern "C"
{
  void
  _start (void);

  static void
  micro_os_plus_initialize_data (std::uintptr_t* from,
                                 std::uintptr_t* region_begin,
                                 std::uintptr_t* region_end);

  static void
  micro_os_plus_initialize_bss (std::uintptr_t* region_begin,
                                std::uintptr_t* region_end);

  static void
  micro_os_plus_run_init_array (void);

  // Not static since it is called from exit()
  void
  micro_os_plus_run_fini_array (void);

  // Specific to newlib libgloss.
  void
  initialise_monitor_handles (void);
}

// ----------------------------------------------------------------------------

inline __attribute__ ((always_inline)) void
micro_os_plus_initialize_data (std::uintptr_t* from,
                               std::uintptr_t* region_begin,
                               std::uintptr_t* region_end)
{
  // Iterate and copy word by word.
  // Assume that the pointers are word aligned.
  std::uintptr_t* p = region_begin;
  while (p < region_end)
    {
      *p++ = *from++;
    }
}

inline __attribute__ ((always_inline)) void
micro_os_plus_initialize_bss (std::uintptr_t* region_begin,
                              std::uintptr_t* region_end)
{
  // Iterate and clear word by word.
  // Assume that the pointers are word aligned.
  std::uintptr_t* p = region_begin;
  while (p < region_end)
    {
      *p++ = 0;
    }
}

typedef void (*function_ptr_t) (void);

// These magic symbols are provided by the linker. newlib standard.
extern function_ptr_t __attribute__ ((weak)) __preinit_array_begin__[];
extern function_ptr_t __attribute__ ((weak)) __preinit_array_end__[];

extern function_ptr_t __attribute__ ((weak)) __init_array_begin__[];
extern function_ptr_t __attribute__ ((weak)) __init_array_end__[];

extern function_ptr_t __attribute__ ((weak)) __fini_array_begin__[];
extern function_ptr_t __attribute__ ((weak)) __fini_array_end__[];

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

// Iterate over all the preinit/init routines (mainly static constructors).
inline __attribute__ ((always_inline)) void
micro_os_plus_run_init_array (void)
{
#if MICRO_OS_PLUS_BOOL_USE_TRACE
  trace::printf ("%s()\n", __func__);
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE

  std::for_each (__preinit_array_begin__, __preinit_array_end__,
                 [] (const function_ptr_t pf) { pf (); } //
  );

  // If the application needs to run the code in the .init section,
  // please use the startup files, since this requires the code in
  // crti.o and crtn.o to add the function prologue/epilogue.
  //_init(); // DO NOT ENABLE THIS!

  std::for_each (__init_array_begin__, __init_array_end__,
                 [] (const function_ptr_t pf) { pf (); } //
  );
}

// Run all the cleanup routines (mainly the static destructors).
void
micro_os_plus_run_fini_array (void)
{
#if MICRO_OS_PLUS_BOOL_USE_TRACE
  trace::printf ("%s()\n", __func__);
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE

  std::for_each (__fini_array_begin__, __fini_array_end__,
                 [] (const function_ptr_t pf) { pf (); } //
  );

  // If the application needs to run the code in the .fini section,
  // please use the startup files, since this requires the code in
  // crti.o and crtn.o to add the function prologue/epilogue.
  //_fini(); // DO NOT ENABLE THIS!
}

#pragma GCC diagnostic pop

#if defined(MICRO_OS_PLUS_DEBUG) && (MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS)

// These definitions are used to check if the routines used to
// clear the BSS and to copy the initialized DATA perform correctly.

#define BSS_GUARD_BAD_VALUE (0xCADEBABA)

static uint32_t volatile __attribute__ ((section (".bss_begin")))
__bss_begin_guard;

static uint32_t volatile __attribute__ ((section (".bss_end")))
__bss_end_guard;

#define DATA_GUARD_BAD_VALUE (0xCADEBABA)
#define DATA_BEGIN_GUARD_VALUE (0x12345678)
#define DATA_END_GUARD_VALUE (0x98765432)

static uint32_t volatile __attribute__ ((section (".data_begin")))
__data_begin_guard
    = DATA_BEGIN_GUARD_VALUE; // 305419896

static uint32_t volatile __attribute__ ((section (".data_end")))
__data_end_guard
    = DATA_END_GUARD_VALUE; // 2557891634

#endif // defined(MICRO_OS_PLUS_DEBUG) && (MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS)

/**
 * @details
 * This is the place where the MCU will go immediately
 * after reset (on Cortex-M the `Reset_Handler` calls this function,
 * on RISC-V there is a small assembly stub).
 *
 * To reach this location, the reset stack must point to a valid
 * internal RAM area.
 *
 * Debugging new startup configurations usually begins with placing
 * a breakpoint at `_start()`, and stepping through the routine.
 */
void __attribute__ ((noreturn, weak)) _start (void)
{
  // --------------------------------------------------------------------------

  // Initialize hardware right after reset, to switch clock to higher
  // frequency and have the rest of the initializations run faster.
  //
  // Also useful on platform with external RAM, that need to be
  // initialized before filling the BSS section.
  //
  // Note: External RAM whose size is known only after reading the
  // chip type, cannot be initialized via these linker script static tables
  // and need to be handled by this hook.
  //
  // On devices with an active watchdog, configure or disable it
  // to accommodate for the initializations duration.

  micro_os_plus_startup_initialize_hardware_early ();

  // Use Old Style DATA and BSS section initialization,
  // that will manage a single BSS sections.

#if defined(MICRO_OS_PLUS_DEBUG) && (MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS)

  __data_begin_guard = DATA_GUARD_BAD_VALUE;
  __data_end_guard = DATA_GUARD_BAD_VALUE;

#endif // MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS

#if !defined(MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS)

  // Copy the DATA segment from flash to RAM (inlined).
  micro_os_plus_initialize_data (&__data_load_addr__, &__data_begin__,
                                 &__data_end__);

  // Alternate solution in case the compiler complains about
  // undefined behaviour of the linker script pointers.
  // memcpy (&__data_begin__, &__data_load_addr__,
  //        static_cast<size_t> (reinterpret_cast<char*> (&__data_end__)
  //                             - reinterpret_cast<char*> (&__data_begin__)));

#else

  // Copy all DATA sections from flash to RAM.
  for (uint32_t* p = &__data_regions_array_begin__;
       p < &__data_regions_array_end__;)
    {
      uint32_t* from = (uint32_t*)(*p++);
      uint32_t* region_begin = (uint32_t*)(*p++);
      uint32_t* region_end = (uint32_t*)(*p++);

      micro_os_plus_initialize_data (from, region_begin, region_end);
    }

#endif // MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS

#if defined(MICRO_OS_PLUS_DEBUG) && (MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS)

  if ((__data_begin_guard != DATA_BEGIN_GUARD_VALUE)
      || (__data_end_guard != DATA_END_GUARD_VALUE))
    {
      // Oops, DATA guard checks failed.
      architecture::brk ();
      while (true)
        {
          architecture::wfi ();
        }
    }

#endif // MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS

#if defined(MICRO_OS_PLUS_DEBUG) && (MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS)

  __bss_begin_guard = BSS_GUARD_BAD_VALUE;
  __bss_end_guard = BSS_GUARD_BAD_VALUE;

#endif

#if !defined(MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS)

  // Zero fill the BSS section (inlined).
  micro_os_plus_initialize_bss (&__bss_begin__, &__bss_end__);

#else

  // Zero fill all BSS segments.
  // Note: the linker script uses LONG() and generates 32-bits pointers.
  // This is not a problem if RAM is in the first 4 GB part, but for
  // 64-bits devices it might not be true and requires QUAD().
  for (uint32_t* p = &__bss_regions_array_begin__;
       p < &__bss_regions_array_end__;)
    {
      uint32_t* region_begin = (uint32_t*)(*p++);
      uint32_t* region_end = (uint32_t*)(*p++);

      micro_os_plus_initialize_bss (region_begin, region_end);
    }

#endif // MICRO_OS_PLUS_INCLUDE_STARTUP_INIT_MULTIPLE_RAM_SECTIONS

#if defined(MICRO_OS_PLUS_DEBUG) && (MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS)

  if ((__bss_begin_guard != 0) || (__bss_end_guard != 0))
    {
      // Oops, BSS guard checks failed.
      architecture::brk ();
      while (true)
        {
          architecture::wfi ();
        }
    }

#endif // MICRO_OS_PLUS_BOOL_STARTUP_GUARD_CHECKS

#if MICRO_OS_PLUS_BOOL_USE_TRACE
  // Initialize the trace output device. From this moment on,
  // trace::printf() calls are available (including in static
  // constructors).
  trace::initialize ();
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE

  // Hook to continue the initializations. Usually compute and store the
  // clock frequency in a global variable, cleared above.
  micro_os_plus_startup_initialize_hardware ();

#if MICRO_OS_PLUS_BOOL_USE_TRACE
  trace::printf ("Hardware initialized.\n");
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE

#if defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)
  initialise_monitor_handles ();
#endif

  // Must be done before `micro_os_plus_run_init_array()`, in case
  // dynamic memory is needed in constructors.
  micro_os_plus_startup_initialize_free_store (
      &__heap_begin__, static_cast<std::size_t> (
                           (reinterpret_cast<char*> ((&__heap_end__))
                            - reinterpret_cast<char*> ((&__heap_begin__)))));

  // Warning: `malloc()` may need `errno` which may depend on knowing
  // the current thread.

  // Call the standard library initialization (mandatory for C++ to
  // execute the static objects constructors).
  micro_os_plus_run_init_array ();

  // Get the argc/argv (useful in semihosting configurations).
  int argc;
  char** argv;
  micro_os_plus_startup_initialize_args (&argc, &argv);

#if MICRO_OS_PLUS_BOOL_USE_TRACE
  trace::dump_args (argc, argv);

  trace::printf (
      "\nµOS++ IIIe version " MICRO_OS_PLUS_STRING_MICRO_OS_PLUS_VERSION
      ".\n");
  trace::printf ("Copyright (c) 2007-" MICRO_OS_PLUS_STRING_MICRO_OS_PLUS_YEAR
                 " Liviu Ionescu.\n");
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE

#pragma GCC diagnostic push

// ISO C++ forbids taking address of function '::main' [-Wpedantic]
#pragma GCC diagnostic ignored "-Wpedantic"

  // Call the main entry point, and save the exit code.
  int code = main (argc, argv);

#pragma GCC diagnostic pop

  // Standard program termination;
  // `atexit()` and C++ static destructors are executed.
  exit (code);

  // Oops, should not get here.
#if defined(MICRO_OS_PLUS_DEBUG)
  architecture::brk ();
#endif // defined(MICRO_OS_PLUS_DEBUG)
  while (true)
    {
      architecture::wfi ();
    }
  /* NOTREACHED */
}

// ----------------------------------------------------------------------------

#if !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

// Semihosting uses a more elaborate version of
// micro_os_plus_startup_initialize_args() to parse arguments received from
// host.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

// This is the standard default implementation for the routine to
// process arguments. It returns a single empty arg.
//
// For semihosting applications, this is redefined to get the real
// arguments from the debugger.
//
// The application can redefine it to fetch some arguments from a
// non-volatile memory.

void __attribute__ ((weak))
micro_os_plus_startup_initialize_args (int* p_argc, char*** p_argv)
{
  // By the time we reach this, the data and bss should have been initialized.

  // The strings pointed to by the argv array shall be modifiable by the
  // program, and retain their last-stored values between program startup
  // and program termination. (static, no const)
  static char name[] = "";

  // The string pointed to by argv[0] represents the program name;
  // argv[0][0] shall be the null character if the program name is not
  // available from the host environment. argv[argc] shall be a null pointer.
  // (static, no const)
  static char* argv[2] = { name, NULL };

  *p_argc = 1;
  *p_argv = &argv[0];

  return;
}

#pragma GCC diagnostic pop

#endif // !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

// Redefine this function to initialise the free store.
void __attribute__ ((weak))
micro_os_plus_startup_initialize_free_store (void* heap_address,
                                             std::size_t heap_size_bytes)
{
#if MICRO_OS_PLUS_BOOL_USE_TRACE
  trace::printf ("Heap: @0x%08X (%dK)\n", heap_address,
                 heap_size_bytes / 1024);
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE
}

// Redefine this function to display memory allocator reports or
// other statistics.
void __attribute__ ((weak)) micro_os_plus_terminate_goodbye (void)
{
#if MICRO_OS_PLUS_BOOL_USE_TRACE
  trace::printf ("\nHasta la Vista!\n");
  trace::flush ();
#endif // MICRO_OS_PLUS_BOOL_USE_TRACE
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

#endif // !Unix

// ----------------------------------------------------------------------------
