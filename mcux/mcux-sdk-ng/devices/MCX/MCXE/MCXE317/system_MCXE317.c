/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXE31 RM Rev1
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
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
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MCXE317
 * @version 1.0
 * @date 2025-05-12
 * @brief Device specific configuration file for MCXE317 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include <stdbool.h>
#include "fsl_device_registers.h"

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
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));    /* set CP10, CP11 Full Access */
#endif                                                    /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    /* Enable flash controller code and data line read and prefetch buffers */
    PFLASH->PFCR[0] =
        PFLASH_PFCR_P0_CBFEN_MASK | PFLASH_PFCR_P0_CPFEN_MASK | PFLASH_PFCR_P0_DBFEN_MASK | PFLASH_PFCR_P0_DPFEN_MASK;
    PFLASH->PFCR[1] =
        PFLASH_PFCR_P1_CBFEN_MASK | PFLASH_PFCR_P1_CPFEN_MASK | PFLASH_PFCR_P1_DBFEN_MASK | PFLASH_PFCR_P1_DPFEN_MASK;

    /* Enable instruction cache */
    if (SCB_CCR_IC_Msk != (SCB_CCR_IC_Msk & SCB->CCR))
    {
        SCB_EnableICache();
    }

    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */
void SystemCoreClockUpdate(void)
{
    uint32_t div  = 0U;
    uint32_t freq = 0U;
    uint32_t temp = 0U;
    uint64_t temp64 = 0U;

    switch (MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK)
    {
        case MC_CGM_MUX_0_CSS_SELSTAT(0U):
            freq = CLK_FIRC_CLOCK_FREQ;
            break;
        case MC_CGM_MUX_0_CSS_SELSTAT(8U):
            if (((PLL->PLLCR & PLL_PLLCR_PLLPD_MASK) == 0U) && ((PLL->PLLODIV[0] & PLL_PLLODIV_DE_MASK) != 0U))
            {
                div = (PLL->PLLDV & PLL_PLLDV_RDIV_MASK) >> PLL_PLLDV_RDIV_SHIFT;
                div = (div == 0U) ? 1U : div;

                if ((PLL->PLLFD & PLL_PLLFD_SDMEN_MASK) != 0U) /* Fractional mode. */
                {
                    freq = CLK_XTAL_OSC_CLK / 1000U / div;
                    temp = (PLL->PLLDV & PLL_PLLDV_MFI_MASK) >> PLL_PLLDV_MFI_SHIFT;
                    temp64 = (uint64_t)temp * 18432U + (uint64_t)(PLL->PLLFD & PLL_PLLFD_MFN_MASK);
                    temp64 = temp64 * 1000U / 18432U;
                    freq   = (uint32_t)((uint64_t)freq * temp64);
                }
                else
                {
                    freq = CLK_XTAL_OSC_CLK * ((PLL->PLLDV & PLL_PLLDV_MFI_MASK) >> PLL_PLLDV_MFI_SHIFT) / div;
                }
                freq /= (PLL->PLLDV & PLL_PLLDV_ODIV2_MASK) >> PLL_PLLDV_ODIV2_SHIFT;
                freq /= ((PLL->PLLODIV[0] & PLL_PLLODIV_DIV_MASK) >> PLL_PLLODIV_DIV_SHIFT) + 1U;
            }
            else
            {
                freq = 0U;
            }
            break;
        default:
            break;
    }

    SystemCoreClock = freq / (((MC_CGM->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DIV_MASK) >> MC_CGM_MUX_0_DC_0_DIV_SHIFT) + 1U);
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}
