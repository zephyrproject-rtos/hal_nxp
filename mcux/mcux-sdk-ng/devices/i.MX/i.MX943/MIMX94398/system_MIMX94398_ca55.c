/*
** ###################################################################
**     Processors:          MIMX94398AVKE_ca55
**                          MIMX94398AVKJ_ca55
**                          MIMX94398AVKM_ca55
**                          MIMX94398AVME_ca55
**                          MIMX94398AVMJ_ca55
**                          MIMX94398AVMM_ca55
**                          MIMX94398CVKE_ca55
**                          MIMX94398CVKJ_ca55
**                          MIMX94398CVKM_ca55
**                          MIMX94398CVME_ca55
**                          MIMX94398CVMJ_ca55
**                          MIMX94398CVMM_ca55
**                          MIMX94398DVKE_ca55
**                          MIMX94398DVKJ_ca55
**                          MIMX94398DVKM_ca55
**                          MIMX94398DVME_ca55
**                          MIMX94398DVMJ_ca55
**                          MIMX94398DVMM_ca55
**                          MIMX94398XVKE_ca55
**                          MIMX94398XVKJ_ca55
**                          MIMX94398XVKM_ca55
**                          MIMX94398XVME_ca55
**                          MIMX94398XVMJ_ca55
**                          MIMX94398XVMM_ca55
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX943RM rev1 draftK
**     Version:             rev. 1.0, 2023-11-01
**     Build:               b241210
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
**     - rev. 1.0 (2023-11-01)
**         Initial version.
**         core name and core alias name
**         +---------------------------------------------------------------------+
**         | core name  |                  core alias name                       |
**         +---------------------------------------------------------------------+
**         | cm33_core0 | m33, cm33                                              |
**         +---------------------------------------------------------------------+
**         | cm33_core1 | m33_2, cm33_2, cm33_sync, netcmix_cm33                 |
**         +---------------------------------------------------------------------+
**         | cm7_core0  | m7, cm7                                                |
**         +---------------------------------------------------------------------+
**         | cm7_core1  | m7_2, cm7_2                                            |
**         +---------------------------------------------------------------------+
**         | ca55_core0 | a55, ca55, a55_0, ca55_0                               |
**         +---------------------------------------------------------------------+
**         | ca55_core1 | a55, ca55, a55_1, ca55_1                               |
**         +---------------------------------------------------------------------+
**         | ca55_core2 | a55, ca55, a55_2, ca55_2                               |
**         +---------------------------------------------------------------------+
**         | ca55_core3 | a55, ca55, a55_3, ca55_3                               |
**         +---------------------------------------------------------------------+
**
** ###################################################################
*/

/*!
 * @file MIMX94398_ca55
 * @version 1.0
 * @date 2023-11-01
 * @brief Device specific configuration file for MIMX94398_ca55 (implementation
 *        file)
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
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  __ASM volatile("mov x0, #(3 << 20) \n\t"
                 "msr cpacr_el1, x0");
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */


  SystemInitHook();

  ARM_TIMER_GetFreq(&SystemCoreClock);
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
