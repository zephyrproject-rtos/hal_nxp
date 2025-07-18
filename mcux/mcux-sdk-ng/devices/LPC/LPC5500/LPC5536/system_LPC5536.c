/*
** ###################################################################
**     Processors:          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC55S3x Reference Manual Rev. DraftG, 07/2021
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
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC5536
 * @version 2.0
 * @date 2024-10-29
 * @brief Device specific configuration file for LPC5536 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"

#if __has_include("fsl_clock.h")
#include "fsl_clock.h"
#endif


/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInit (void) {
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Secure mode */
  #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  SCB_NS->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Non-secure mode */
  #endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

  SCB->CPACR |= ((3UL << 0*2) | (3UL << 1*2));    /* set CP0, CP1 Full Access in Secure mode (enable PowerQuad) */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  SCB_NS->CPACR |= ((3UL << 0*2) | (3UL << 1*2));    /* set CP0, CP1 Full Access in Normal mode (enable PowerQuad) */
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

  SCB->NSACR |= ((3UL << 0) | (3UL << 10));   /* enable CP0, CP1, CP10, CP11 Non-secure Access */

#if defined(__MCUXPRESSO)
    extern void(*const g_pfnVectors[]) (void);
    SCB->VTOR = (uint32_t) &g_pfnVectors;
#else
    extern void *__Vectors;
    SCB->VTOR = (uint32_t) &__Vectors;
#endif
    SYSCON->TRACECLKDIV = 0;
/* Optionally enable RAM banks that may be off by default at reset */
#if !defined(DONT_ENABLE_DISABLED_RAMBANKS)
    SYSCON->AHBCLKCTRLSET[0] = SYSCON_AHBCLKCTRL0_SRAM_CTRL1_MASK | SYSCON_AHBCLKCTRL0_SRAM_CTRL2_MASK
                          | SYSCON_AHBCLKCTRL0_SRAM_CTRL3_MASK | SYSCON_AHBCLKCTRL0_SRAM_CTRL4_MASK;
#endif
    /* enable the flash cache LPCAC */
    SYSCON->LPCAC_CTRL &= ~SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK;
  SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {
#if __has_include("fsl_clock.h")
    /* Get frequency of Core System */
    SystemCoreClock = CLOCK_GetCoreSysClkFreq();
#endif
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInitHook (void) {
  /* Void implementation of the weak function. */
}
