/*
** ###################################################################
**     Processors:          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    iMXRT2660RM Rev.1 DraftN, 08/2026
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMXRT2663_cm85
 * @version 1.0
 * @date 2026-08-18
 * @brief Device specific configuration file for MIMXRT2663_cm85
 *  (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include "fsl_device_registers.h"
#include "fsl_clock.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

#if defined(__ARMCC_VERSION)
__attribute__((section("InRoot$$Sections"), __noinline__))
#elif defined(__GNUC__)
__attribute__((used, section(".text.startup")))
#elif defined(__ICCARM__)
__attribute__((section(".text.startup")))
#endif
__attribute__((weak)) void SystemInit(void)
{
#if defined(ENABLE_RAM_VECTOR_TABLE)

#ifdef __VECTOR_TABLE
#undef __VECTOR_TABLE
#endif

/* Addresses for VECTOR_TABLE and VECTOR_RAM come from the linker file */
#if defined(__ARMCC_VERSION)
    extern uint32_t Image$$VECTOR_ROM$$Base[];
    extern uint32_t Image$$VECTOR_RAM$$Base[];
    extern uint32_t Image$$VECTOR_RAM$$ZI$$Limit[];

#define __VECTOR_TABLE          Image$$VECTOR_ROM$$Base
#define __VECTOR_RAM            Image$$VECTOR_RAM$$Base
#define __RAM_VECTOR_TABLE_SIZE (((uint32_t)Image$$VECTOR_RAM$$ZI$$Limit - (uint32_t)Image$$VECTOR_RAM$$Base))
#elif defined(__ICCARM__)
    extern uint32_t __RAM_VECTOR_TABLE_SIZE[];
    extern uint32_t __VECTOR_TABLE[];
    extern uint32_t __VECTOR_RAM[];
#elif defined(__GNUC__)
    extern uint32_t __VECTOR_TABLE[];
    extern uint32_t __VECTOR_RAM[];
    extern uint32_t __RAM_VECTOR_TABLE_SIZE_BYTES[];
    uint32_t __RAM_VECTOR_TABLE_SIZE = (uint32_t)(__RAM_VECTOR_TABLE_SIZE_BYTES);
#endif /* defined(__ARMCC_VERSION) */

    uint32_t n;
    if ((SCB->VTOR != (uint32_t)__VECTOR_RAM) && ((uint32_t)__VECTOR_RAM != (uint32_t)__VECTOR_TABLE) && (__RAM_VECTOR_TABLE_SIZE > 0U))
    {
        /* Copy the vector table from ROM to RAM */
        for (n = 0; n < ((uint32_t)__RAM_VECTOR_TABLE_SIZE) / sizeof(uint32_t); n++)
        {
            __VECTOR_RAM[n] = __VECTOR_TABLE[n];
        }
        /* Point the VTOR to the position of vector table */
        SCB->VTOR = (uint32_t)__VECTOR_RAM;
    }
#endif /* defined(ENABLE_RAM_VECTOR_TABLE) */

    SCB->CCR |= SCB_CCR_LOB_Msk | SCB_CCR_TRD_Msk;

    BOARD_EarlyInit();

    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

#if defined(__ARMCC_VERSION)
__attribute__((section("InRoot$$Sections"), __noinline__))
#elif defined(__GNUC__)
__attribute__((used, section(".text.startup")))
#elif defined(__ICCARM__)
__attribute__((section(".text.startup")))
#endif
__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}

/* ----------------------------------------------------------------------------
   -- BOARD_EarlyInit()
   ---------------------------------------------------------------------------- */

#if defined(__ARMCC_VERSION)
__attribute__((section("InRoot$$Sections"), __noinline__))
#elif defined(__GNUC__)
__attribute__((used, section(".text.startup")))
#elif defined(__ICCARM__)
__attribute__((section(".text.startup")))
#endif
__attribute__((weak)) void BOARD_EarlyInit(void)
{
    /* Void implementation of the weak function. Boards override this to
     * configure caches and MPU regions before SystemInitHook runs. */
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */
void SystemCoreClockUpdate(void)
{
    SystemCoreClock = CLOCK_GetRootClockFreq(kCLOCK_Root_CMPT_cpu_clk);
}
