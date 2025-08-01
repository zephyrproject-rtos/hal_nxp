/*
** ###################################################################
**     Processors:          MIMX94398AVKE_cm33_core1
**                          MIMX94398AVKJ_cm33_core1
**                          MIMX94398AVKM_cm33_core1
**                          MIMX94398AVME_cm33_core1
**                          MIMX94398AVMJ_cm33_core1
**                          MIMX94398AVMM_cm33_core1
**                          MIMX94398CVKE_cm33_core1
**                          MIMX94398CVKJ_cm33_core1
**                          MIMX94398CVKM_cm33_core1
**                          MIMX94398CVME_cm33_core1
**                          MIMX94398CVMJ_cm33_core1
**                          MIMX94398CVMM_cm33_core1
**                          MIMX94398DVKE_cm33_core1
**                          MIMX94398DVKJ_cm33_core1
**                          MIMX94398DVKM_cm33_core1
**                          MIMX94398DVME_cm33_core1
**                          MIMX94398DVMJ_cm33_core1
**                          MIMX94398DVMM_cm33_core1
**                          MIMX94398XVKE_cm33_core1
**                          MIMX94398XVKJ_cm33_core1
**                          MIMX94398XVKM_cm33_core1
**                          MIMX94398XVME_cm33_core1
**                          MIMX94398XVMJ_cm33_core1
**                          MIMX94398XVMM_cm33_core1
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

#ifndef _SYSTEM_MIMX94398_cm33_core1_H_
#define _SYSTEM_MIMX94398_cm33_core1_H_                    /**< Symbol preventing repeated inclusion */

#include <stdint.h>
#include "fsl_device_registers.h"

#define DEFAULT_SYSTEM_CLOCK 266666666U

#define SYSTEM_INIT_MEMORY_REGIONS (1)

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/*
 * SCMI(IOMUXC) API using non-security address, so need to convert
 * security address to non-security address.
 * bit28 is flag of security address
 */
#define IOMUXC_SECURITY_MASK (0x10000000U)
#define PINCTRL_BASE         (IOMUXC_BASE & (~IOMUXC_SECURITY_MASK))
#else
#define PINCTRL_BASE         (IOMUXC_BASE)
#endif

#define IOMUXC_PADCTL_BASE   (PINCTRL_BASE + 0x304) /* 0x443c0304 */
#define IOMUXC_DAISY_BASE (PINCTRL_BASE + 0x608) /* 0x443c0608 */

/* SCMI config */
#ifndef SCMI_A2P
#define SCMI_A2P 0U
#endif
#ifndef SCMI_NOTIFY
#define SCMI_NOTIFY 1U
#endif
#ifndef SCMI_PRIORITY
#define SCMI_PRIORITY 2U
#endif

/* MU8_MUA (2*(8-1) = 14) */
#define SYSTEM_PLATFORM_MU_INST 14
#define SYSTEM_PLATFORM_MU_IRQ MU8_A_IRQn

/* Logical Machine */
#define SYSTEM_PLATFORM_LMID_A55 (4U)

/* Doorbell*/
#define SCMI_DBIR_A2P      0  /* A2P channel */
#define SCMI_DBIR_NOTIFY   1  /* P2A notify */
#define SCMI_DBIR_PRIORITY 2U /* P2A priority */

#define SYSTEM_PLATFORM_SMA_ADDR 0

/* BBM(RTC) */
#define SYSTEM_PLATFORM_RTC_ID 0

/* FUSA */
#define SYSTEM_PLATFORM_FAULT_ID_FIRST 6U
#define SYSTEM_PLATFORM_FAULT_MASK     0x1
#define SYSTEM_PLATFORM_NOTIFY_ENABLE  0x1

/* CPU Id */
#define SYSTEM_PLATFORM_AP_ID (2U)
#define SYSTEM_PLATFORM_M33S_ID (8U)
#define SYSTEM_PLATFORM_M70_ID (1U)
#define SYSTEM_PLATFORM_M71_ID (7U)

/* Domain id(same with components/power/porting/platform/imx943/hal_power_platform.h) */
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_ANA           0U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_AON           1U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_BBSM          2U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_M7_1          3U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_CCMSRCGPC     4U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_A55C0         5U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_A55C1         6U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_A55C2         7U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_A55C3         8U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_A55P          9U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_DDR           10U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_DISPLAY       11U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_M7_0          12U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_HSIO_TOP      13U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_HSIO_WAON     14U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_NETC          15U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_NOC           16U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_NPU           17U
#define SYSTEM_POWER_PLATFORM_MIX_SLICE_IDX_WAKEUP        18U

#ifndef SYSTEM_PLATFORM_RTC_NOTIFY
#define SYSTEM_PLATFORM_RTC_NOTIFY 0
#endif

#ifdef __cplusplus
extern "C" {
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

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate(void);

/**
 * @brief SystemTimeDelay
 *
 * Delays the specified number of usec.
 */
void SystemTimeDelay(uint32_t usec);

/**
 * @brief SystemInitMemoryRegions
 *
 * Init memory regions.
 */
void SystemInitMemoryRegions(void);

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
void SystemPlatformSetSystemState(uint32_t systemState);

/*!
 * @brief SM Platform Get System State
 */
uint32_t SystemPlatformGetSystemState(void);

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MIMX94398_cm33_core1_H_ */
