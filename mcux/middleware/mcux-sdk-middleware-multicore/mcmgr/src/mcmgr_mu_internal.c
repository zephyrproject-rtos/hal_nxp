/*
 * Copyright 2017-2023 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_mu.h"
#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"

#define MU_ISR_FLAG_BASE (20U)
#define MU_ISR_COUNT     (12U)

/* Weak MU ISR stubs */
/* implement these in your application to override */

void MU_Tx3EmptyFlagISR(void);
void MU_Tx2EmptyFlagISR(void);
void MU_Tx1EmptyFlagISR(void);
void MU_Tx0EmptyFlagISR(void);
void MU_Rx3FullFlagISR(void);
void MU_Rx2FullFlagISR(void);
void MU_Rx1FullFlagISR(void);
void MU_Rx0FullFlagISR(void);
void MU_GenInt3FlagISR(void);
void MU_GenInt2FlagISR(void);
void MU_GenInt1FlagISR(void);
void MU_GenInt0FlagISR(void);

__attribute__((weak)) void MU_Tx3EmptyFlagISR(void){};
__attribute__((weak)) void MU_Tx2EmptyFlagISR(void){};
__attribute__((weak)) void MU_Tx1EmptyFlagISR(void){};
__attribute__((weak)) void MU_Tx0EmptyFlagISR(void){};
__attribute__((weak)) void MU_Rx3FullFlagISR(void){};
__attribute__((weak)) void MU_Rx2FullFlagISR(void){};
__attribute__((weak)) void MU_Rx1FullFlagISR(void){};
__attribute__((weak)) void MU_Rx0FullFlagISR(void){};
__attribute__((weak)) void MU_GenInt3FlagISR(void){};
__attribute__((weak)) void MU_GenInt2FlagISR(void){};
__attribute__((weak)) void MU_GenInt1FlagISR(void){};
__attribute__((weak)) void MU_GenInt0FlagISR(void){};

#if (defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1189_cm7_SERIES) || \
     defined(MIMXRT1189_cm33_SERIES))
/* MU ISR table */
static void (*const MU_interrupts[MU_ISR_COUNT])(void) = {
    MU_Tx0EmptyFlagISR, MU_Tx1EmptyFlagISR, MU_Tx2EmptyFlagISR, MU_Tx3EmptyFlagISR,
    MU_Rx0FullFlagISR,  MU_Rx1FullFlagISR,  MU_Rx2FullFlagISR,  MU_Rx3FullFlagISR,
    MU_GenInt0FlagISR,  MU_GenInt1FlagISR,  MU_GenInt2FlagISR,  MU_GenInt3FlagISR,
};
#else
/* MU ISR table */
static void (*const MU_interrupts[MU_ISR_COUNT])(void) = {
    MU_Tx3EmptyFlagISR, MU_Tx2EmptyFlagISR, MU_Tx1EmptyFlagISR, MU_Tx0EmptyFlagISR,
    MU_Rx3FullFlagISR,  MU_Rx2FullFlagISR,  MU_Rx1FullFlagISR,  MU_Rx0FullFlagISR,
    MU_GenInt3FlagISR,  MU_GenInt2FlagISR,  MU_GenInt1FlagISR,  MU_GenInt0FlagISR,
};
#endif

/* MU ISR router */
static void mu_isr(MU_Type *base)
{
    uint32_t flags;
    uint32_t i;
    flags = MU_GetStatusFlags(base);

#if (defined(FSL_FEATURE_MU_HAS_RESET_ASSERT_INT) && FSL_FEATURE_MU_HAS_RESET_ASSERT_INT)
    /* The other core reset assert interrupt pending */
    if (0UL != (flags & (uint32_t)kMU_ResetAssertInterruptFlag))
    {
        MU_ClearStatusFlags(base, (uint32_t)kMU_ResetAssertInterruptFlag);
        if (MCMGR_eventTable[kMCMGR_RemoteCoreDownEvent].callback != ((void *)0))
        {
            MCMGR_eventTable[kMCMGR_RemoteCoreDownEvent].callback(
                0, MCMGR_eventTable[kMCMGR_RemoteCoreDownEvent].callbackData);
        }
        return;
    }
#endif

    /* Traverse all TE/RF/GIP status flags and call respective callbacks for pending flags */

    /* Start with Transmit Empty status flags, these are all set after the reset so do not call callback unless
       the respective Transmit Interrupt Enable flag in the CR/TCR register is set. */
#if (defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1189_cm7_SERIES) || \
     defined(MIMXRT1189_cm33_SERIES))
    uint32_t tcr_tie_idx = 0;
    for (i = MU_ISR_FLAG_BASE; i < (MU_ISR_FLAG_BASE + MU_TR_COUNT); i++)
    {
        if ((0UL != (flags & (1UL << i))) && (0UL != (base->TCR & (1UL << tcr_tie_idx))))
        {
            MU_interrupts[i - MU_ISR_FLAG_BASE]();
        }
        tcr_tie_idx++;
    }
#else
    for (i = MU_ISR_FLAG_BASE; i < (MU_ISR_FLAG_BASE + MU_TR_COUNT); i++)
    {
        if ((0UL != (flags & (1UL << i))) && (0UL != (base->CR & (1UL << i))))
        {
            MU_interrupts[i - MU_ISR_FLAG_BASE]();
        }
    }
#endif

    /* Continue with RF and GIP status flags. */
    for (i = MU_ISR_FLAG_BASE + MU_TR_COUNT; i < (MU_ISR_FLAG_BASE + MU_ISR_COUNT); i++)
    {
        if (0UL != (flags & (1UL << i)))
        {
            MU_ClearStatusFlags(base, (1UL << i));
            MU_interrupts[i - MU_ISR_FLAG_BASE]();
        }
    }
}

#if (defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1189_cm7_SERIES) || \
     defined(MIMXRT1189_cm33_SERIES))

#if defined(FSL_FEATURE_MU_SIDE_A)
int MU1_IRQHandler(void)
{
    mu_isr(MU1_MUA);
    /* ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
     * exception return operation might vector to incorrect interrupt.
     * For Cortex-M7, if core speed much faster than peripheral register write speed,
     * the peripheral interrupt flags may be still set after exiting ISR, this results to
     * the same error similar with errata 83869 */
#if (defined __CORTEX_M) && ((__CORTEX_M == 4U) || (__CORTEX_M == 7U))
    __DSB();
#endif
    return 0;
}
#elif defined(FSL_FEATURE_MU_SIDE_B)
int MU1_IRQHandler(void)
{
    mu_isr(MU1_MUB);
    /* ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
     * exception return operation might vector to incorrect interrupt.
     * For Cortex-M7, if core speed much faster than peripheral register write speed,
     * the peripheral interrupt flags may be still set after exiting ISR, this results to
     * the same error similar with errata 83869 */
#if (defined __CORTEX_M) && ((__CORTEX_M == 4U) || (__CORTEX_M == 7U))
    __DSB();
#endif
    return 0;
}
#endif
#else
#if defined(FSL_FEATURE_MU_SIDE_A)
int MUA_IRQHandler(void)
{
    mu_isr(MUA);
    /* ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
     * exception return operation might vector to incorrect interrupt.
     * For Cortex-M7, if core speed much faster than peripheral register write speed,
     * the peripheral interrupt flags may be still set after exiting ISR, this results to
     * the same error similar with errata 83869 */
#if (defined __CORTEX_M) && ((__CORTEX_M == 4U) || (__CORTEX_M == 7U))
    __DSB();
#endif
    return 0;
}
#elif defined(FSL_FEATURE_MU_SIDE_B)
int MUB_IRQHandler(void)
{
    mu_isr(MUB);
    /* ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
     * exception return operation might vector to incorrect interrupt.
     * For Cortex-M7, if core speed much faster than peripheral register write speed,
     * the peripheral interrupt flags may be still set after exiting ISR, this results to
     * the same error similar with errata 83869 */
#if (defined __CORTEX_M) && ((__CORTEX_M == 4U) || (__CORTEX_M == 7U))
    __DSB();
#endif
    return 0;
}
#endif
#endif
