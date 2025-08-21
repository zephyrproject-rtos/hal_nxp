/*
 * Copyright 2017-2025 NXP
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

void MU_Tx3EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Tx2EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Tx1EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Tx0EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Rx3FullFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Rx2FullFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Rx1FullFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_Rx0FullFlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_GenInt3FlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_GenInt2FlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_GenInt1FlagISR(MU_Type *base, mcmgr_core_t coreNum);
void MU_GenInt0FlagISR(MU_Type *base, mcmgr_core_t coreNum);

__attribute__((weak)) void MU_Tx3EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Tx2EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Tx1EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Tx0EmptyFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Rx3FullFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Rx2FullFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Rx1FullFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_Rx0FullFlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_GenInt3FlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_GenInt2FlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_GenInt1FlagISR(MU_Type *base, mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_GenInt0FlagISR(MU_Type *base, mcmgr_core_t coreNum){};

#if (defined(MIMXRT1186_cm7_SERIES) || defined(MIMXRT1186_cm33_SERIES) ||                                   \
     defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1189_cm7_SERIES) || \
     defined(MIMXRT1189_cm33_SERIES) || defined(MIMXRT735S_cm33_core0_SERIES) ||                            \
     defined(MIMXRT735S_cm33_core1_SERIES) || defined(MIMXRT758S_cm33_core0_SERIES) ||                      \
     defined(MIMXRT758S_cm33_core1_SERIES) || defined(MIMXRT798S_cm33_core0_SERIES) ||                      \
     defined(MIMXRT798S_cm33_core1_SERIES) ||                                                               \
     defined(MIMXRT735S_hifi4_SERIES) || defined(MIMXRT758S_hifi4_SERIES) ||                                \
     defined(MIMXRT798S_hifi4_SERIES) ||                                                                    \
     defined(MIMXRT735S_hifi1_SERIES) || defined(MIMXRT758S_hifi1_SERIES) ||                                \
     defined(MIMXRT798S_hifi1_SERIES) ||                                                                    \
     defined(KW43B43ZC7_SERIES) || defined(KW43B43ZC7_NBU_SERIES) ||                                        \
     defined(MCXL255_cm0plus_SERIES) || defined(MCXL255_cm33_SERIES))

/* MU ISR table */
static void (*const MU_interrupts[MU_ISR_COUNT])(MU_Type *base, mcmgr_core_t coreNum) = {
    MU_Tx0EmptyFlagISR, MU_Tx1EmptyFlagISR, MU_Tx2EmptyFlagISR, MU_Tx3EmptyFlagISR,
    MU_Rx0FullFlagISR,  MU_Rx1FullFlagISR,  MU_Rx2FullFlagISR,  MU_Rx3FullFlagISR,
    MU_GenInt0FlagISR,  MU_GenInt1FlagISR,  MU_GenInt2FlagISR,  MU_GenInt3FlagISR,
};
#else
/* MU ISR table */
static void (*const MU_interrupts[MU_ISR_COUNT])(MU_Type *base, mcmgr_core_t coreNum) = {
    MU_Tx3EmptyFlagISR, MU_Tx2EmptyFlagISR, MU_Tx1EmptyFlagISR, MU_Tx0EmptyFlagISR,
    MU_Rx3FullFlagISR,  MU_Rx2FullFlagISR,  MU_Rx1FullFlagISR,  MU_Rx0FullFlagISR,
    MU_GenInt3FlagISR,  MU_GenInt2FlagISR,  MU_GenInt1FlagISR,  MU_GenInt0FlagISR,
};
#endif

/* MU ISR router */
static void mu_isr(MU_Type *base, mcmgr_core_t coreNum)
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
                coreNum, 0, MCMGR_eventTable[kMCMGR_RemoteCoreDownEvent].callbackData);
        }
        return;
    }
#endif

    /* Traverse all TE/RF/GIP status flags and call respective callbacks for pending flags */

    /* Start with Transmit Empty status flags, these are all set after the reset so do not call callback unless
       the respective Transmit Interrupt Enable flag in the CR/TCR register is set. */
#if (defined(MIMXRT1186_cm7_SERIES) || defined(MIMXRT1186_cm33_SERIES) ||                                   \
     defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1189_cm7_SERIES) || \
     defined(MIMXRT1189_cm33_SERIES) || defined(MIMXRT735S_cm33_core0_SERIES) ||                            \
     defined(MIMXRT735S_cm33_core1_SERIES) || defined(MIMXRT758S_cm33_core0_SERIES) ||                      \
     defined(MIMXRT758S_cm33_core1_SERIES) || defined(MIMXRT798S_cm33_core0_SERIES) ||                      \
     defined(MIMXRT798S_cm33_core1_SERIES) ||                                                               \
     defined(MIMXRT735S_hifi4_SERIES) || defined(MIMXRT758S_hifi4_SERIES) ||                                \
     defined(MIMXRT798S_hifi4_SERIES) ||                                                                    \
     defined(MIMXRT735S_hifi1_SERIES) || defined(MIMXRT758S_hifi1_SERIES) ||                                \
     defined(MIMXRT798S_hifi1_SERIES) ||                                                                    \
     defined(KW43B43ZC7_SERIES) || defined(KW43B43ZC7_NBU_SERIES) ||                                        \
     defined(MCXL255_cm0plus_SERIES) || defined(MCXL255_cm33_SERIES))

    uint32_t tcr_tie_idx = 0;
    for (i = MU_ISR_FLAG_BASE; i < (MU_ISR_FLAG_BASE + MU_TR_COUNT); i++)
    {
        if ((0UL != (flags & (1UL << i))) && (0UL != (base->TCR & (1UL << tcr_tie_idx))))
        {
            MU_interrupts[i - MU_ISR_FLAG_BASE](base, coreNum);
        }
        tcr_tie_idx++;
    }
#else
    for (i = MU_ISR_FLAG_BASE; i < (MU_ISR_FLAG_BASE + MU_TR_COUNT); i++)
    {
        if ((0UL != (flags & (1UL << i))) && (0UL != (base->CR & (1UL << i))))
        {
            MU_interrupts[i - MU_ISR_FLAG_BASE](base, coreNum);
        }
    }
#endif

    /* Continue with RF and GIP status flags. */
    for (i = MU_ISR_FLAG_BASE + MU_TR_COUNT; i < (MU_ISR_FLAG_BASE + MU_ISR_COUNT); i++)
    {
        if (0UL != (flags & (1UL << i)))
        {
            MU_ClearStatusFlags(base, (1UL << i));
            MU_interrupts[i - MU_ISR_FLAG_BASE](base, coreNum);
        }
    }
}

#if (defined(MIMXRT1186_cm33_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1189_cm33_SERIES))
int MU1_IRQHandler(void)
{
    mu_isr(MU1_MUA, kMCMGR_Core1);
    return 0;
}
#elif (defined(MIMXRT1186_cm7_SERIES) || defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1189_cm7_SERIES))
int MU1_IRQHandler(void)
{
    mu_isr(MU1_MUB, kMCMGR_Core0);
    /* ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
     * exception return operation might vector to incorrect interrupt.
     * For Cortex-M7, if core speed much faster than peripheral register write speed,
     * the peripheral interrupt flags may be still set after exiting ISR, this results to
     * the same error similar with errata 83869 */
    __DSB();
    return 0;
}
#elif (defined(MIMXRT735S_cm33_core0_SERIES) || defined(MIMXRT758S_cm33_core0_SERIES) || \
       defined(MIMXRT798S_cm33_core0_SERIES))
int MU1_A_IRQHandler(void)
{
    mu_isr(MU1_MUA, kMCMGR_Core1);
    return 0;
}

int MU4_A_IRQHandler(void)
{
    mu_isr(MU4_MUA, kMCMGR_Core2);
    return 0;
}

int MU0_A_IRQHandler(void)
{
    mu_isr(MU0_MUA, kMCMGR_Core3);
    return 0;
}
#elif (defined(MIMXRT735S_cm33_core1_SERIES) || defined(MIMXRT758S_cm33_core1_SERIES) || \
       defined(MIMXRT798S_cm33_core1_SERIES))
int MU1_B_IRQHandler(void)
{
    mu_isr(MU1_MUB, kMCMGR_Core0);
    return 0;
}

int MU3_A_IRQHandler(void)
{
    mu_isr(MU3_MUA, kMCMGR_Core3);
    return 0;
}

int MU2_B_IRQHandler(void)
{
    mu_isr(MU2_MUB, kMCMGR_Core2);
    return 0;
}
#elif (defined(MIMXRT735S_hifi4_SERIES) || defined(MIMXRT758S_hifi4_SERIES) || \
       defined(MIMXRT798S_hifi4_SERIES))
// int MU4_B_IRQHandler(void)
void MU4_B_IRQHandler(void *arg)
{
    (void)arg;

    mu_isr(MU4_MUB, kMCMGR_Core0);
}

// int MU2_A_IRQHandler(void)
void MU2_A_IRQHandler(void *arg)
{
    (void)arg;

    mu_isr(MU2_MUA, kMCMGR_Core1);

}
#elif (defined(MIMXRT735S_hifi1_SERIES) || defined(MIMXRT758S_hifi1_SERIES) || \
       defined(MIMXRT798S_hifi1_SERIES))
// int MU3_B_IRQHandler(void)
void MU3_B_IRQHandler(void *arg)
{
    mu_isr(MU3_MUB, kMCMGR_Core1);
}

// int MU0_B_IRQHandler(void)
void MU0_B_IRQHandler(void *arg)
{
    mu_isr(MU0_MUB, kMCMGR_Core0);
}
#elif (defined(KW43B43ZC7_SERIES))
int MU0_IRQHandler(void)
{
    mu_isr(MU0_MUA, kMCMGR_Core1);
    return 0;
}
#elif (defined(KW43B43ZC7_NBU_SERIES))
int MU0_IRQHandler(void)
{
    mu_isr(MU0_MUB, kMCMGR_Core0);
    return 0;
}
#elif (defined(MCXL255_cm33_SERIES))
int MU_A_TX_IRQHandler(void)
{
    mu_isr(MUA, kMCMGR_Core1);
    return 0;
}
int MU_A_RX_IRQHandler(void)
{
    mu_isr(MUA, kMCMGR_Core1);
    return 0;
}
int MU_A_INT_IRQHandler(void)
{
    mu_isr(MUA, kMCMGR_Core1);
    return 0;
}
#elif (defined(MCXL255_cm0plus_SERIES))
int MU_B_TX_IRQHandler(void)
{
    mu_isr(MUB, kMCMGR_Core0);
    return 0;
}
int MU_B_RX_IRQHandler(void)
{
    mu_isr(MUB, kMCMGR_Core0);
    return 0;
}
int MU_B_INT_IRQHandler(void)
{
    mu_isr(MUB, kMCMGR_Core0);
    return 0;
}
#elif defined(FSL_FEATURE_MU_SIDE_A)
int MUA_IRQHandler(void)
{
    mu_isr(MUA, kMCMGR_Core1);
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
    mu_isr(MUB, kMCMGR_Core0);
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
