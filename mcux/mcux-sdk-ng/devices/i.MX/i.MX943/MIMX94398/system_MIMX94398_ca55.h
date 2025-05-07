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
 * @brief Device specific configuration file for MIMX94398_ca55 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef _SYSTEM_MIMX94398_ca55_H_
#define _SYSTEM_MIMX94398_ca55_H_                /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Define clock source values */
#define DEFAULT_SYSTEM_CLOCK   24000000U /* Default System clock value */

/**
 * @brief System clock frequency (core clock)
 *
 * The system clock frequency supplied to the SysTick timer and the processor
 * core clock. This variable can be used by the user application to setup the
 * SysTick timer or configure other parameters. It may also be used by debugger to
 * query the frequency of the debug timer or configure the trace clock speed
 * SystemCoreClock is initialized with a correct predefined value.
 */
extern uint32_t SystemCoreClock;

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator (PLL) that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit (void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate (void);

/**
 * @brief SystemInit function hook.
 *
 * This weak function allows to call specific initialization code during the
 * SystemInit() execution.This can be used when an application specific code needs
 * to be called as close to the reset entry as possible (for example the Multicore
 * Manager MCMGR_EarlyInit() function call).
 * NOTE: No global r/w variables can be used in this hook function because the
 * initialization of these variables happens after this function.
 */
void SystemInitHook (void);

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MIMX94398_ca55_H_ */
