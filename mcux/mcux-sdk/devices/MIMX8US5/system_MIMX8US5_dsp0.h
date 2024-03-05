/*
** ###################################################################
**     Processors:          MIMX8US5CVP08_dsp0
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVP08_dsp0
**
**     Compiler:            Xtensa Compiler
**     Reference manual:    IMX8ULPRM, Rev. D, December. 2022
**     Version:             rev. 5.0, 2023-04-27
**     Build:               b230927
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**
** ###################################################################
*/

/*!
 * @file MIMX8US5_dsp0
 * @version 1.0
 * @date 270923
 * @brief Device specific configuration file for MIMX8US5_cm33 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */
#ifndef _SYSTEM_MIMX8US5_dsp0_H_
#define _SYSTEM_MIMX8US5_dsp0_H_                    /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define DEFAULT_SYSTEM_CLOCK 192000000U /* Default System clock value */
#ifndef CLK_XTAL_OSC_CLK
#define CLK_XTAL_OSC_CLK 24000000U /* Default XTAL OSC clock */
#endif
#define CLK_RTC_32K_CLK 32768U     /* RTC oscillator 32 kHz (32k_clk) */
#define CLK_FRO_192MHZ  192000000U /* FRO 192 MHz (fro_192m) */
#define CLK_LPOSC_1MHZ  1000000U   /* LPOSC 1 MHz */
#ifndef CLK_LVDS_CLK
#define CLK_LVDS_CLK 0U /* Default LVDS clock */
#endif

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
void SystemInit(void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate(void);

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
void SystemInitHook(void);

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MIMX8US5_dsp0_H_ */
