/*
** ###################################################################
**     Processors:          MIMX94398AVKE_cm33_core0
**                          MIMX94398AVKJ_cm33_core0
**                          MIMX94398AVKM_cm33_core0
**                          MIMX94398AVME_cm33_core0
**                          MIMX94398AVMJ_cm33_core0
**                          MIMX94398AVMM_cm33_core0
**                          MIMX94398CVKE_cm33_core0
**                          MIMX94398CVKJ_cm33_core0
**                          MIMX94398CVKM_cm33_core0
**                          MIMX94398CVME_cm33_core0
**                          MIMX94398CVMJ_cm33_core0
**                          MIMX94398CVMM_cm33_core0
**                          MIMX94398DVKE_cm33_core0
**                          MIMX94398DVKJ_cm33_core0
**                          MIMX94398DVKM_cm33_core0
**                          MIMX94398DVME_cm33_core0
**                          MIMX94398DVMJ_cm33_core0
**                          MIMX94398DVMM_cm33_core0
**                          MIMX94398XVKE_cm33_core0
**                          MIMX94398XVKJ_cm33_core0
**                          MIMX94398XVKM_cm33_core0
**                          MIMX94398XVME_cm33_core0
**                          MIMX94398XVMJ_cm33_core0
**                          MIMX94398XVMM_cm33_core0
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX943RM rev1 draftK
**     Version:             rev. 1.0, 2023-11-01
**     Build:               b250109
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


#include "fsl_common.h"
#include "system_MIMX94398_cm33_core0.h"
#include "fsl_cache.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */
uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit(void)
{
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Secure mode */
    #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    SCB_NS->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Non-secure mode */
    #endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    XCACHE_EnableCache(M33_CACHE_CTRLPC); /* enable code bus cache(I-Cache) */

    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate(void)
{
}

/* ----------------------------------------------------------------------------
   -- SystemTimeDelay(usec)
   ---------------------------------------------------------------------------- */
void SystemTimeDelay(uint32_t usec)
{
    SDK_DelayAtLeastUs(usec, SystemCoreClock);
}


