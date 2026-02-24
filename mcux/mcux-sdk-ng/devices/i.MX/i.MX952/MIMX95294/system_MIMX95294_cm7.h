/*
** ###################################################################
**     Processors:          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_cm7
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX952RM rev1 draftM
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b241030
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
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX95294_cm7
 * @version 1.0
 * @date 2023-01-10
 * @brief Device specific configuration file for MIMX95294_cm7 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef _SYSTEM_MIMX95294_cm7_H_
#define _SYSTEM_MIMX95294_cm7_H_                 /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "fsl_common.h"
#include "scmi.h"
#include "scmi_internal.h"
#include "smt.h"

#define DEFAULT_SYSTEM_CLOCK 800000000u

/* MU5_MUA */
#define SYSTEM_PLATFORM_MU_INST 8

#define SCMI_A2P    0
#define SCMI_NOTIFY 1
#define SCMI_P2A    2

/* Pinctrl */
#define IOMUXC_PADCTL_BASE	(IOMUXC_BASE + 0x230) /* 0x443c0230 */
#define IOMUXC_DAISY_BASE 	(IOMUXC_BASE + 0x460) /* 0x443c0460 */
#define SYSTEM_PLATFORM_PINCTRL_MUX_MODE_MASK  (0x7U)
#define SYSTEM_PLATFORM_PINCTRL_MUX_MODE_SHIFT (0U)
#define SYSTEM_PLATFORM_PINCTRL_MUX_MODE(x) \
    (((uint32_t)(((uint32_t)(x)) << SYSTEM_PLATFORM_PINCTRL_MUX_MODE_SHIFT)) & SYSTEM_PLATFORM_PINCTRL_MUX_MODE_MASK)

#define SYSTEM_PLATFORM_PINCTRL_SION_MASK  (0x10U)
#define SYSTEM_PLATFORM_PINCTRL_SION_SHIFT (4U)
#define SYSTEM_PLATFORM_PINCTRL_SION(x) \
    (((uint32_t)(((uint32_t)(x)) << SYSTEM_PLATFORM_PINCTRL_SION_SHIFT)) & SYSTEM_PLATFORM_PINCTRL_SION_MASK)

#define SYSTEM_PLATFORM_PINCTRL_BASE         IOMUXC_BASE
#define SYSTEM_PLATFORM_PINCTRL_MUXREG_OFF   (SYSTEM_PLATFORM_PINCTRL_BASE)
#define SYSTEM_PLATFORM_PINCTRL_CFGREG_OFF   (SYSTEM_PLATFORM_PINCTRL_BASE + 0x230U) /* 0x443c0230 */
#define SYSTEM_PLATFORM_PINCTRL_DAISYREG_OFF (SYSTEM_PLATFORM_PINCTRL_BASE + 0x460U) /* 0x443c0460 */

/* Doorbell*/
#define SYSTEM_PLATFORM_DBIR_A2P      0  /* A2P channel */
#define SYSTEM_PLATFORM_DBIR_NOTIFY   1  /* P2A notify */
#define SYSTEM_PLATFORM_DBIR_PRIORITY 2U /* P2A priority */

#define SYSTEM_PLATFORM_SMA_ADDR 0

/* LMM */
#define SYSTEM_PLATFORM_LMID_M7  1
#define SYSTEM_PLATFORM_LMID_A55 2

/* BBM(RTC) */
#define SYSTEM_PLATFORM_RTC_ID 0

/* FUSA */
#define SYSTEM_PLATFORM_FAULT_ID_FIRST 6U
#define SYSTEM_PLATFORM_FAULT_MASK     0x1
#define SCMI_NOTIFY_ENABLE  0x1

#ifndef SCMI_LMM_POWER_CHANGE_PROCESSED
#define SCMI_LMM_POWER_CHANGE_PROCESSED (0)
#endif

#define SCMI_MU_IRQ_PRIORITY   (3U)

/* MISC */
#define SYSTEM_MISC_CTRL_SD3_WAKE    0U  /*!< PCAL6408A-0 */
#define SYSTEM_MISC_CTRL_M2E_WAKE    1U  /*!< PCAL6408A-4 */
#define SYSTEM_MISC_CTRL_BT_WAKE     2U  /*!< PCAL6408A-5 */
#define SYSTEM_MISC_CTRL_M2M_WAKE    3U  /*!< PCAL6408A-6 */
#define SYSTEM_MISC_CTRL_BUTTON      4U  /*!< PCAL6408A-7 */
#define SYSTEM_MISC_CTRL_TEST        5U  /*!< Test */
#define SYSTEM_MISC_CTRL_PCA2131     6U  /*!< PCA2131 raw access */
#define SYSTEM_MISC_CTRL_TEST_A      7U  /*!< Test action */

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

/*!
 * @brief Initialize MU interface for SM access.
 */
void SystemPlatformInit(void);

/*!
 * @brief Deinitialize MU interface for SM access.
 */
void SystemPlatformDeinit(void);

/*!
 * @brief SM Platform Set System State
 */
void SM_Platform_SetSystemState(uint32_t systemState);

/*!
 * @brief SM Platform Get System State
 */
uint32_t SM_Platform_GetSystemState(void);

/*!
 * @brief MU5_A IRQ Handler
 */
void MU5_A_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MIMX95294_cm7_H_ */
