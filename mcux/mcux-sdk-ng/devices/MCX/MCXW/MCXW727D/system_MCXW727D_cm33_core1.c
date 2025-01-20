/*
** ###################################################################
**     Processor:           MCXW727DMFTA_cm33_core1
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    Rev. 1, 2024-10-13
**     Version:             rev. 1.0, 2024-10-13
**     Build:               b241128
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**
** ###################################################################
*/

/*!
 * @file MCXW727D_cm33_core1
 * @version 1.0
 * @date 2024-10-13
 * @brief Device specific configuration file for MCXW727D_cm33_core1
 *        (implementation file)
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

__attribute__ ((weak)) void SystemInit (void) {

#if (DISABLE_WDOG)
  while ((WDOG0->CS & WDOG_CS_RCS_MASK) != WDOG_CS_RCS_MASK)
  {
  }

  if ((WDOG0->CS & WDOG_CS_CMD32EN_MASK) != 0U)
  {
      WDOG0->CNT = 0xD928C520U;
  }
  else
  {
      WDOG0->CNT = 0xC520U;
      WDOG0->CNT = 0xD928U;
  }

  while ((WDOG0->CS & WDOG_CS_ULK_MASK) != WDOG_CS_ULK_MASK)
  {
  }

  WDOG0->TOVAL = 0xFFFF;
  WDOG0->CS = (uint32_t) ((WDOG0->CS) & ~WDOG_CS_EN_MASK) | WDOG_CS_UPDATE_MASK;

  while ((WDOG0->CS & WDOG_CS_RCS_MASK) != WDOG_CS_RCS_MASK)
  {
  }
#endif /* (DISABLE_WDOG) */

#if defined(__MCUXPRESSO)
    extern void(*const g_pfnVectors[]) (void);
    SCB->VTOR = (uint32_t) &g_pfnVectors;
#endif

  SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {

}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInitHook (void) {
  /* Void implementation of the weak function. */
}
