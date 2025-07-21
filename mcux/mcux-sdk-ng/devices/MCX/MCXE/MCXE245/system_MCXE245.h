/*
** ###################################################################
**     Processors:          MCXE245VLF
**                          MCXE245VLH
**                          MCXE245VLL
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXE24x RM Rev.1
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250429
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
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file MCXE245
 * @version 1.0
 * @date 2025-02-21
 * @brief Device specific configuration file for MCXE245 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef _SYSTEM_MCXE245_H_
#define _SYSTEM_MCXE245_H_                       /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#ifndef DISABLE_WDOG
  #define DISABLE_WDOG  1
#endif

/* Define clock source values */
#define CPU_XTAL_CLK_HZ                8000000U            /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_INT_FAST_CLK_HZ            48000000U           /* Value of the fast internal oscillator clock frequency in Hz */
#define CPU_INT_IRC_CLK_HZ             48000000U           /* Value of the 48M internal oscillator clock frequency in Hz */

/* Low power mode enable */
/* SMC_PMPROT: AHSRUN=1, AVLP=1 */
#define SYSTEM_SMC_PMPROT_VALUE        0xA0U               /* SMC_PMPROT */
#define SYSTEM_SMC_PMCTRL_VALUE        0x0U                /* SMC_PMCTRL */

#define DEFAULT_SYSTEM_CLOCK           48000000U           /* Default System clock value */
#define CPU_INT_SLOW_CLK_HZ            8000000U            /* Value of the slow internal oscillator clock frequency in Hz */

#define FPSCR_FZ_MASK                  (0x1000000U)        /* FPU Flush-to-zero mode bit */


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

/**
 * @brief Custom low level initialization for IAR.
 *
 * Function for adaptation of system initialization in IAR toolchain.
 * The function is called from IAR's cmain.s if the function is implemented.
 *
 * @retval 0 to omit seg_init
 * @retval 1 to run seg_init
 */
int __low_level_init(void);

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MCXE245_H_ */
