/*
** ###################################################################
**     Processors:          MCXL254VDF_cm33
**                          MCXL254VLL_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXL25x RM Rev.1 RC
**     Version:             rev. 1.1, 2026-01-02
**     Build:               b260320
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-06-13)
**         Generated based on Rev1 DraftH.
**     - rev. 1.1 (2026-01-02)
**         Generated based on Rev.1 RC.
**
** ###################################################################
*/

/*!
 * @file MCXL254_cm33
 * @version 1.1
 * @date 2026-01-02
 * @brief Device specific configuration file for MCXL254_cm33 (implementation
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

__attribute__ ((weak)) void SystemInit (void) {
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Secure mode */
  #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  SCB_NS->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access in Non-secure mode */
  #endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

#if !defined(__ZEPHYR__)
    uint32_t tmp32;
#if defined(__MCUXPRESSO)
    extern void(*const g_pfnVectors[]) (void);
    SCB->VTOR = (uint32_t) &g_pfnVectors;
#else
    extern void *__Vectors;
    SCB->VTOR = (uint32_t) &__Vectors;
#endif
    /* Disable the High Voltage Glitch Detect Control */
    AON__PMU->AGDET_HV_CTRL &= ~PMU_AGDET_HV_CTRL_AGDET_HV_EN_MASK;
    /* Disable the Low Voltage Glitch Detect Control  */
    AON__PMU->AGDET_LV_CTRL &= ~PMU_AGDET_LV_CTRL_AGDET_LV_EN_MASK;
    /* Do the handshake between PMU and PAC */
    tmp32 = AON__PMU->AWK_UP_TIME;
    AON__PMU->AWK_UP_TIME = tmp32;
    /* If the 96 MHz is selected after reset (selected by the BOOT_SPEED field in the CMPA). */
    if (((SCG0->FIRCCFG & SCG_FIRCCFG_FREQ_SEL_MASK) >> SCG_FIRCCFG_FREQ_SEL_SHIFT) == 7)
    {
        /* Delay time 400 us with default Core clock is 96 MHz: 96000000/1000000*400 = 38400 instruction cycles */
        /* Loop iteration count = 38400 / 4 = 9600 */
        __ASM volatile("    MOV    R0, #9600");
    }
    else
    { /* If the 48 MHz is selected after reset (selected by the BOOT_SPEED field in the CMPA). */
        /* Delay time 400 us with default Core clock is 48 MHz: 48000000/1000000*400 = 19200 instruction cycles */
        /* Loop iteration count = 19200 / 4 = 4800 */
        __ASM volatile("    MOV    R0, #4800");
    }
    __ASM volatile(
        "loop%=:                        \n"
#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
        "    SUB    R0, R0, #1          \n"
#else
        "    SUBS   R0, R0, #1          \n"
#endif
        "    CMP    R0, #0              \n"

        "    BNE    loop%=              \n"
        :
        :
        : "r0");
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
