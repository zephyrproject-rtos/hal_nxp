/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXW23x User manual Rev.0.1  1 September 2022
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
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MCXW235
 * @version 2.0
 * @date 2024-10-29
 * @brief Device specific configuration file for MCXW235 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef _SYSTEM_MCXW235_H_
#define _SYSTEM_MCXW235_H_                       /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOSConfig.h"
#endif  

#define DEFAULT_SYSTEM_CLOCK           12000000u           /* Default System clock value */
#define CLK_RTC_32K_CLK                32768u              /* RTC oscillator 32 kHz output (32k_clk */
#define CLK_FRO_12MHZ                  12000000u           /* FRO 12 MHz (fro_12m) */
#define CLK_FRO_32MHZ                  32000000u           /* FRO 32 MHz (fro_32m) */
#define CLK_FRO_48MHZ                  48000000u           /* FRO 48 MHz (fro_48m) */
#define CLK_CLK_IN                     16000000u           /* Default CLK_IN pin clock */

/** The baseline priority level */
#if defined(SDK_OS_FREE_RTOS)
/* The interrupt may never be higher than configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY to prevent
 * memory corruption */
#define NVIC_PRIO_BASE configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY
#else  /* SDK_OS_FREE_RTOS */
#define NVIC_PRIO_BASE 0
#endif /* SDK_OS_FREE_RTOS */

#if defined(SUPPORT_MASTER_CONNECTION) || defined(SUPPORT_SLAVE_CONNECTION)
#ifndef NVIC_DEFAULT_PRIORITY
#define NVIC_DEFAULT_PRIORITY NVIC_PRIO_BASE + 3
#endif /* NVIC_DEFAULT_PRIORITY */
#ifndef NVIC_LL_IRQ_PRIORITY
#define NVIC_LL_IRQ_PRIORITY NVIC_PRIO_BASE + 2
#endif /* NVIC_LL_IRQ_DEFAULT_PRIORITY */
#ifndef HAL_TIMER_ISR_PRIORITY
#define HAL_TIMER_ISR_PRIORITY NVIC_DEFAULT_PRIORITY
#endif/* HAL_TIMER_ISR_PRIORITY */
#ifndef SERIAL_MANAGER_TASK_PRIORITY
#define SERIAL_MANAGER_TASK_PRIORITY NVIC_DEFAULT_PRIORITY
#endif/* SERIAL_MANAGER_TASK_PRIORITY */
#ifndef HAL_UART_ISR_PRIORITY
#define HAL_UART_ISR_PRIORITY NVIC_DEFAULT_PRIORITY
#endif/* HAL_UART_ISR_PRIORITY */
#ifndef HAL_GPIO_ISR_PRIORITY
#define HAL_GPIO_ISR_PRIORITY NVIC_DEFAULT_PRIORITY
#endif /* HAL_GPIO_ISR_PRIORITY */
#ifndef BUTTON_TASK_PRIORITY
#define BUTTON_TASK_PRIORITY NVIC_DEFAULT_PRIORITY
#endif /* BUTTON_TASK_PRIORITY */


#endif /* defined(SUPPORT_MASTER_CONNECTION) || defined(SUPPORT_SLAVE_CONNECTION) */

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
 * @brief Prints the expected and the actual value before calling the generic assert function.
 */
#ifdef NDEBUG
# define assert_equal(a,b) ((void)0)
#else
extern void __assert_equal_func(uint32_t a, uint32_t b);
# define assert_equal(a,b) do {if ((a)!=(b)) { __assert_equal_func((uint32_t)(a),(uint32_t)(b));assert(a==b);}} while(0)
#endif

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEM_MCXW235_H_ */