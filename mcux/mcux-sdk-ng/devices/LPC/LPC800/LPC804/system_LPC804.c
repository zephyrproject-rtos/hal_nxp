/*
** ###################################################################
**     Processors:          LPC804M101JDH20
**                          LPC804M101JDH24
**                          LPC804M101JHI33
**                          LPC804M111JDH24
**                          LPC804UK
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC804 User manual Rev.1.0  24 Jan 2018
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-01-09)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC804
 * @version 2.0
 * @date 2024-10-29
 * @brief Device specific configuration file for LPC804 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"





/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit (void) {

#if defined(__MCUXPRESSO)
    extern void(*const g_pfnVectors[]) (void);
    SCB->VTOR = (uint32_t) &g_pfnVectors;
#else
    extern void *__Vectors;
    SCB->VTOR = (uint32_t) &__Vectors;
#endif
    SystemCoreClock = DEFAULT_SYSTEM_CLOCK;
  SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {


    switch (SYSCON->MAINCLKSEL & SYSCON_MAINCLKSEL_SEL_MASK)
    {
        case 0U: /* Free running oscillator (FRO / 2) */
            SystemCoreClock = (g_Fro_Osc_Freq >> 1U);
            break;
        case 1U: /* System oscillator */
            SystemCoreClock = CLK_OSC_IN;
            break;
        case 2U: /* lower power oscillator */
            SystemCoreClock = CLK_OSC_LP;
            break;
        case 3U: /* Free running oscillator ((FRO / 2) / 2) */
            SystemCoreClock = (g_Fro_Osc_Freq >> 2U);
            break;
        default:
            SystemCoreClock = 0U;
            break;
    }

  SystemCoreClock /= SYSCON->SYSAHBCLKDIV;
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInitHook (void) {
  /* Void implementation of the weak function. */
}
