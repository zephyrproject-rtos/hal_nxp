/*
** ###################################################################
**     Processors:          MIMXRT1151DHM8B
**                          MIMXRT1151DVM8B
**                          MIMXRT1151XHM8B
**                          MIMXRT1151XVM8B
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1150RM, Rev 1, 01/2026
**     Version:             rev. 0.2, 2026-02-26
**     Build:               b260701
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
**     - rev. 0.1 (2026-01-09)
**         Initial version.
**     - rev. 0.2 (2026-02-26)
**         Update header file based on RM Rev1.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1151
 * @version 1.0
 * @date 2026-07-01
 * @brief Device specific configuration file for MIMXRT1151 (implementation file)
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

 * @brief Early SoC initialization, called before the C runtime startup.
 *
 * WARNING: Runs before .data/.bss are initialized. Any code added here
 * must follow the same constraints as SystemInitHook() �� see the full
 * rules on that function below.
   ---------------------------------------------------------------------------- */

void SystemInit (void) {
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

#if defined(__MCUXPRESSO)
    extern uint32_t g_pfnVectors[];  // Vector table defined in startup code
    SCB->VTOR = (uint32_t)g_pfnVectors;
#endif

/* Watchdog disable */

#if (DISABLE_WDOG)
    if ((WDOG1->WCR & WDOG_WCR_WDE_MASK) != 0U)
    {
        WDOG1->WCR &= ~(uint16_t) WDOG_WCR_WDE_MASK;
    }
    if ((WDOG2->WCR & WDOG_WCR_WDE_MASK) != 0U)
    {
        WDOG2->WCR &= ~(uint16_t) WDOG_WCR_WDE_MASK;
    }
    if ((RTWDOG3->CS & RTWDOG_CS_CMD32EN_MASK) != 0U)
    {
        RTWDOG3->CNT = 0xD928C520U; /* 0xD928C520U is the update key */
    }
    else
    {
        RTWDOG3->CNT = 0xC520U;
        RTWDOG3->CNT = 0xD928U;
    }
    RTWDOG3->TOVAL = 0xFFFF;
    RTWDOG3->CS = (uint32_t) ((RTWDOG3->CS) & ~RTWDOG_CS_EN_MASK) | RTWDOG_CS_UPDATE_MASK;
#endif /* (DISABLE_WDOG) */

    /* Disable Systick which might be enabled by bootrom */
    if ((SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) != 0U)
    {
        SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    BOARD_EarlyInit();

    /* Clear bit 13 to its reset value since it might be set by ROM. */
    IOMUXC_GPR->GPR28 &= ~IOMUXC_GPR_GPR28_CACHE_USB_MASK;

#if defined(ROM_ECC_ENABLED)
    /* When ECC is enabled, SRC->SRSR need to be cleared since only correct SRSR value can trigger ROM ECC preload procedure.
       Save SRSR to SRC->GPR[10] so that application can still check SRSR value from SRC->GPR[10]. */
    SRC->GPR[10] = SRC->SRSR;
    /* clear SRSR */
    SRC->SRSR = 0xFFFFFFFFU;
#endif

    /* Enable entry to thread mode when divide by zero */
    SCB->CCR |= SCB_CCR_DIV_0_TRP_Msk;
    __DSB();
    __ISB();

  SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {

/* TBD */

}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()

 * @brief Weak hook called from SystemInit(), very early in boot.
 *
 * WARNING: Runs BEFORE the C runtime startup. At this point .data has not
 * been copied from flash to RAM and .bss has not been zeroed, so:
 *   - Do NOT read/write any global or static variable (.data/.bss are
 *     indeterminate).
 *   - Do NOT call libc / printf / malloc or anything that relies on
 *     initialized global state.
 *   - Only touch CPU registers, peripheral registers, and stack locals.
 *
 * Typical use: SoC errata workarounds or clock/memory-controller setup
 * that must happen before RAM is usable.
   ---------------------------------------------------------------------------- */

__attribute__ ((weak)) void SystemInitHook (void) {
  /* Void implementation of the weak function. */
}

/* ----------------------------------------------------------------------------
   -- BOARD_EarlyInit()
   ---------------------------------------------------------------------------- */
/**
 * @brief BOARD_EarlyInit function.
 *
 * This weak function allows board to initialize MPU or memory at early stage before .data,
 * .bss initialization.
 * It minimizes the risk of speculative access to uninitialized memory allowed by default
 * MPU attributes. Meanwhile it also make it possible to enable I/D caches to boost boot up
 * speed.
 * NOTE: No global/static data access is allowed in this function since they have not been
 * initialized yet.
 */
__attribute__((weak)) void BOARD_EarlyInit(void)
{
    /* Void implementation of the weak function. */
}