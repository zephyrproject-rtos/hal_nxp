/*
 * Copyright 2022, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_erm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.erm"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to ERM bases for each instance. */
static ERM_Type *const s_ermBases[] = ERM_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to ERM clocks for each instance. */
static const clock_ip_name_t s_ermClocks[] = ERM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(ERM_RSTS_N)
/*! @brief Pointers to ERM resets for each instance. */
static const reset_ip_name_t s_ermResets[] = ERM_RSTS_N;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t ERM_GetInstance(ERM_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_ermBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_ermBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_ermBases));

    return instance;
}

/*!
 * brief ERM module initialization function.
 *
 * param base ERM base address.
 */
void ERM_Init(ERM_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate ERM clock. */
    CLOCK_EnableClock(s_ermClocks[ERM_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(ERM_RSTS_N)
    /* Reset the ERM module */
    RESET_PeripheralReset(s_ermResets[ERM_GetInstance(base)]);
#endif

    base->CR0 = 0x00U;
#ifdef ERM_CR1_ENCIE8_MASK
    base->CR1 = 0x00U;
#endif
#ifdef ERM_CR2_ENCIE8_MASK
    base->CR2 = 0x00U;
#endif
    base->SR0 = 0xFFFFFFFFU;
#ifdef ERM_SR1_SBC8_MASK
    base->SR1 = 0xFFFFFFFFU;
#endif
#ifdef ERM_SR2_SBC16_MASK
    base->SR2 = 0xFFFFFFFFU;
#endif
}

/*!
 * brief Deinitializes the ERM.
 *
 */
void ERM_Deinit(ERM_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate ERM clock. */
    CLOCK_DisableClock(s_ermClocks[ERM_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

uint32_t ERM_GetMemoryErrorAddr(ERM_Type *base, uint32_t channel)
{
    uint32_t absoluteErrorAddress = 0x00U;

    switch (channel)
    {
        case 0U:
            absoluteErrorAddress = base->EAR0;
            break;
#ifdef ERM_EAR1_EAR_MASK
        case 1U:
            absoluteErrorAddress = base->EAR1;
            break;
#endif
#ifdef ERM_EAR2_EAR_MASK
        case 2U:
            absoluteErrorAddress = base->EAR2;
            break;
#endif
#ifdef ERM_EAR3_EAR_MASK
        case 3U:
            absoluteErrorAddress = base->EAR3;
            break;
#endif
#ifdef ERM_EAR4_EAR_MASK
        case 4U:
            absoluteErrorAddress = base->EAR4;
            break;
#endif
#ifdef ERM_EAR5_EAR_MASK
        case 5U:
            absoluteErrorAddress = base->EAR5;
            break;
#endif
#ifdef ERM_EAR6_EAR_MASK
        case 6U:
            absoluteErrorAddress = base->EAR6;
            break;
#endif
#ifdef ERM_EAR7_EAR_MASK
        case 7U:
            absoluteErrorAddress = base->EAR7;
            break;
#endif
#ifdef ERM_EAR8_EAR_MASK
        case 8U:
            absoluteErrorAddress = base->EAR8;
            break;
#endif
#ifdef ERM_EAR9_EAR_MASK
        case 9U:
            absoluteErrorAddress = base->EAR9;
            break;
#endif
#ifdef ERM_EAR10_EAR_MASK
        case 10U:
            absoluteErrorAddress = base->EAR10;
            break;
#endif
#ifdef ERM_EAR11_EAR_MASK
        case 11U:
            absoluteErrorAddress = base->EAR11;
            break;
#endif
#ifdef ERM_EAR12_EAR_MASK
        case 12U:
            absoluteErrorAddress = base->EAR12;
            break;
#endif
#ifdef ERM_EAR13_EAR_MASK
        case 13U:
            absoluteErrorAddress = base->EAR13;
            break;
#endif
#ifdef ERM_EAR14_EAR_MASK
        case 14U:
            absoluteErrorAddress = base->EAR14;
            break;
#endif
#ifdef ERM_EAR15_EAR_MASK
        case 15U:
            absoluteErrorAddress = base->EAR15;
            break;
#endif
#ifdef ERM_EAR16_EAR_MASK
        case 16U:
            absoluteErrorAddress = base->EAR16;
            break;
#endif
#ifdef ERM_EAR17_EAR_MASK
        case 17U:
            absoluteErrorAddress = base->EAR17;
            break;
#endif
#ifdef ERM_EAR18_EAR_MASK
        case 18U:
            absoluteErrorAddress = base->EAR18;
            break;
#endif
#ifdef ERM_EAR19_EAR_MASK
        case 19U:
            absoluteErrorAddress = base->EAR19;
            break;
#endif
#ifdef ERM_EAR20_EAR_MASK
        case 20U:
            absoluteErrorAddress = base->EAR20;
            break;
#endif
#ifdef ERM_EAR21_EAR_MASK
        case 21U:
            absoluteErrorAddress = base->EAR21;
            break;
#endif
#ifdef ERM_EAR22_EAR_MASK
        case 22U:
            absoluteErrorAddress = base->EAR22;
            break;
#endif
#ifdef ERM_EAR23_EAR_MASK
        case 23U:
            absoluteErrorAddress = base->EAR23;
            break;
#endif
        default:
            assert(false);
            break;
    }

    return absoluteErrorAddress;
}

uint32_t ERM_GetSyndrome(ERM_Type *base, uint32_t channel)
{
    uint32_t syndrome = 0x00U;

    switch (channel)
    {
        case 0U:
            syndrome = (base->SYN0 & ERM_SYN0_SYNDROME_MASK) >> ERM_SYN0_SYNDROME_SHIFT;
            break;
#ifdef ERM_SYN1_SYNDROME_MASK
        case 1U:
            syndrome = (base->SYN1 & ERM_SYN1_SYNDROME_MASK) >> ERM_SYN1_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN2_SYNDROME_MASK
        case 2U:
            syndrome = (base->SYN2 & ERM_SYN2_SYNDROME_MASK) >> ERM_SYN2_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN3_SYNDROME_MASK
        case 3U:
            syndrome = (base->SYN3 & ERM_SYN3_SYNDROME_MASK) >> ERM_SYN3_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN4_SYNDROME_MASK
        case 4U:
            syndrome = (base->SYN4 & ERM_SYN4_SYNDROME_MASK) >> ERM_SYN4_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN5_SYNDROME_MASK
        case 5U:
            syndrome = (base->SYN5 & ERM_SYN5_SYNDROME_MASK) >> ERM_SYN5_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN6_SYNDROME_MASK
        case 6U:
            syndrome = (base->SYN6 & ERM_SYN6_SYNDROME_MASK) >> ERM_SYN6_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN7_SYNDROME_MASK
        case 7U:
            syndrome = (base->SYN7 & ERM_SYN6_SYNDROME_MASK) >> ERM_SYN7_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN8_SYNDROME_MASK
        case 8U:
            syndrome = (base->SYN8 & ERM_SYN8_SYNDROME_MASK) >> ERM_SYN8_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN9_SYNDROME_MASK
        case 8U:
            syndrome = (base->SYN9 & ERM_SYN9_SYNDROME_MASK) >> ERM_SYN9_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN10_SYNDROME_MASK
        case 10U:
            syndrome = (base->SYN10 & ERM_SYN10_SYNDROME_MASK) >> ERM_SYN10_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN11_SYNDROME_MASK
        case 11U:
            syndrome = (base->SYN11 & ERM_SYN11_SYNDROME_MASK) >> ERM_SYN11_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN12_SYNDROME_MASK
        case 12U:
            syndrome = (base->SYN12 & ERM_SYN12_SYNDROME_MASK) >> ERM_SYN12_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN13_SYNDROME_MASK
        case 13U:
            syndrome = (base->SYN13 & ERM_SYN13_SYNDROME_MASK) >> ERM_SYN13_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN14_SYNDROME_MASK
        case 14U:
            syndrome = (base->SYN14 & ERM_SYN14_SYNDROME_MASK) >> ERM_SYN14_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN15_SYNDROME_MASK
        case 15U:
            syndrome = (base->SYN15 & ERM_SYN15_SYNDROME_MASK) >> ERM_SYN15_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN16_SYNDROME_MASK
        case 16U:
            syndrome = (base->SYN16 & ERM_SYN16_SYNDROME_MASK) >> ERM_SYN16_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN17_SYNDROME_MASK
        case 17U:
            syndrome = (base->SYN17 & ERM_SYN17_SYNDROME_MASK) >> ERM_SYN17_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN18_SYNDROME_MASK
        case 18U:
            syndrome = (base->SYN18 & ERM_SYN18_SYNDROME_MASK) >> ERM_SYN18_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN19_SYNDROME_MASK
        case 19U:
            syndrome = (base->SYN19 & ERM_SYN19_SYNDROME_MASK) >> ERM_SYN19_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN20_SYNDROME_MASK
        case 20U:
            syndrome = (base->SYN20 & ERM_SYN20_SYNDROME_MASK) >> ERM_SYN20_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN21_SYNDROME_MASK
        case 21U:
            syndrome = (base->SYN21 & ERM_SYN21_SYNDROME_MASK) >> ERM_SYN21_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN22_SYNDROME_MASK
        case 22U:
            syndrome = (base->SYN22 & ERM_SYN22_SYNDROME_MASK) >> ERM_SYN22_SYNDROME_SHIFT;
            break;
#endif
#ifdef ERM_SYN23_SYNDROME_MASK
        case 23U:
            syndrome = (base->SYN23 & ERM_SYN23_SYNDROME_MASK) >> ERM_SYN23_SYNDROME_SHIFT;
            break;
#endif
        default:
            assert(false);
            break;
    }

    return syndrome;
}

uint32_t ERM_GetErrorCount(ERM_Type *base, uint32_t channel)
{
    uint32_t count = 0x00U;

    switch (channel)
    {
        case 0U:
            count = (base->CORR_ERR_CNT0 & ERM_CORR_ERR_CNT0_COUNT_MASK) >> ERM_CORR_ERR_CNT0_COUNT_SHIFT;
            break;
#ifdef ERM_CORR_ERR_CNT1_COUNT_MASK
        case 1U:
            count = (base->CORR_ERR_CNT1 & ERM_CORR_ERR_CNT1_COUNT_MASK) >> ERM_CORR_ERR_CNT1_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT2_COUNT_MASK
        case 2U:
            count = (base->CORR_ERR_CNT2 & ERM_CORR_ERR_CNT2_COUNT_MASK) >> ERM_CORR_ERR_CNT2_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT3_COUNT_MASK
        case 3U:
            count = (base->CORR_ERR_CNT3 & ERM_CORR_ERR_CNT3_COUNT_MASK) >> ERM_CORR_ERR_CNT3_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT4_COUNT_MASK
        case 4U:
            count = (base->CORR_ERR_CNT4 & ERM_CORR_ERR_CNT4_COUNT_MASK) >> ERM_CORR_ERR_CNT4_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT5_COUNT_MASK
        case 5U:
            count = (base->CORR_ERR_CNT5 & ERM_CORR_ERR_CNT5_COUNT_MASK) >> ERM_CORR_ERR_CNT5_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT6_COUNT_MASK
        case 6U:
            count = (base->CORR_ERR_CNT6 & ERM_CORR_ERR_CNT6_COUNT_MASK) >> ERM_CORR_ERR_CNT6_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT7_COUNT_MASK
        case 7U:
            count = (base->CORR_ERR_CNT7 & ERM_CORR_ERR_CNT7_COUNT_MASK) >> ERM_CORR_ERR_CNT7_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT8_COUNT_MASK
        case 8U:
            count = (base->CORR_ERR_CNT8 & ERM_CORR_ERR_CNT8_COUNT_MASK) >> ERM_CORR_ERR_CNT8_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT9_COUNT_MASK
        case 9U:
            count = (base->CORR_ERR_CNT9 & ERM_CORR_ERR_CNT9_COUNT_MASK) >> ERM_CORR_ERR_CNT9_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT10_COUNT_MASK
        case 10U:
            count = (base->CORR_ERR_CNT10 & ERM_CORR_ERR_CNT10_COUNT_MASK) >> ERM_CORR_ERR_CNT10_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT11_COUNT_MASK
        case 11U:
            count = (base->CORR_ERR_CNT11 & ERM_CORR_ERR_CNT11_COUNT_MASK) >> ERM_CORR_ERR_CNT11_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT12_COUNT_MASK
        case 12U:
            count = (base->CORR_ERR_CNT12 & ERM_CORR_ERR_CNT12_COUNT_MASK) >> ERM_CORR_ERR_CNT12_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT13_COUNT_MASK
        case 13U:
            count = (base->CORR_ERR_CNT13 & ERM_CORR_ERR_CNT13_COUNT_MASK) >> ERM_CORR_ERR_CNT13_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT14_COUNT_MASK
        case 14U:
            count = (base->CORR_ERR_CNT14 & ERM_CORR_ERR_CNT14_COUNT_MASK) >> ERM_CORR_ERR_CNT14_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT15_COUNT_MASK
        case 15U:
            count = (base->CORR_ERR_CNT15 & ERM_CORR_ERR_CNT15_COUNT_MASK) >> ERM_CORR_ERR_CNT15_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT16_COUNT_MASK
        case 16U:
            count = (base->CORR_ERR_CNT16 & ERM_CORR_ERR_CNT16_COUNT_MASK) >> ERM_CORR_ERR_CNT16_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT17_COUNT_MASK
        case 17U:
            count = (base->CORR_ERR_CNT17 & ERM_CORR_ERR_CNT17_COUNT_MASK) >> ERM_CORR_ERR_CNT17_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT18_COUNT_MASK
        case 18U:
            count = (base->CORR_ERR_CNT18 & ERM_CORR_ERR_CNT18_COUNT_MASK) >> ERM_CORR_ERR_CNT18_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT19_COUNT_MASK
        case 19U:
            count = (base->CORR_ERR_CNT19 & ERM_CORR_ERR_CNT19_COUNT_MASK) >> ERM_CORR_ERR_CNT19_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT20_COUNT_MASK
        case 20U:
            count = (base->CORR_ERR_CNT20 & ERM_CORR_ERR_CNT20_COUNT_MASK) >> ERM_CORR_ERR_CNT20_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT21_COUNT_MASK
        case 21U:
            count = (base->CORR_ERR_CNT21 & ERM_CORR_ERR_CNT21_COUNT_MASK) >> ERM_CORR_ERR_CNT21_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT22_COUNT_MASK
        case 22U:
            count = (base->CORR_ERR_CNT22 & ERM_CORR_ERR_CNT22_COUNT_MASK) >> ERM_CORR_ERR_CNT22_COUNT_SHIFT;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT23_COUNT_MASK
        case 23U:
            count = (base->CORR_ERR_CNT23 & ERM_CORR_ERR_CNT23_COUNT_MASK) >> ERM_CORR_ERR_CNT23_COUNT_SHIFT;
            break;
#endif
        default:
            assert(false);
            break;
    }

    return count;
}

void ERM_ResetErrorCount(ERM_Type *base, uint32_t channel)
{
    switch (channel)
    {
        case 0U:
            base->CORR_ERR_CNT0 = 0x00U;
            break;

#ifdef ERM_CORR_ERR_CNT1_COUNT_MASK
        case 1U:
            base->CORR_ERR_CNT1 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT2_COUNT_MASK
        case 2U:
            base->CORR_ERR_CNT2 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT3_COUNT_MASK
        case 3U:
            base->CORR_ERR_CNT3 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT4_COUNT_MASK
        case 4U:
            base->CORR_ERR_CNT4 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT5_COUNT_MASK
        case 5U:
            base->CORR_ERR_CNT5 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT6_COUNT_MASK
        case 6U:
            base->CORR_ERR_CNT6 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT6_COUNT_MASK
        case 7U:
            base->CORR_ERR_CNT7 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT8_COUNT_MASK
        case 8U:
            base->CORR_ERR_CNT8 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT9_COUNT_MASK
        case 9U:
            base->CORR_ERR_CNT9 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT10_COUNT_MASK
        case 10U:
            base->CORR_ERR_CNT10 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT11_COUNT_MASK
        case 11U:
            base->CORR_ERR_CNT11 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT12_COUNT_MASK
        case 12U:
            base->CORR_ERR_CNT12 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT13_COUNT_MASK
        case 13U:
            base->CORR_ERR_CNT13 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT14_COUNT_MASK
        case 14U:
            base->CORR_ERR_CNT14 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT15_COUNT_MASK
        case 15U:
            base->CORR_ERR_CNT15 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT16_COUNT_MASK
        case 16U:
            base->CORR_ERR_CNT16 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT17_COUNT_MASK
        case 17U:
            base->CORR_ERR_CNT17 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT18_COUNT_MASK
        case 18U:
            base->CORR_ERR_CNT18 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT19_COUNT_MASK
        case 19U:
            base->CORR_ERR_CNT19 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT20_COUNT_MASK
        case 20U:
            base->CORR_ERR_CNT20 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT21_COUNT_MASK
        case 21U:
            base->CORR_ERR_CNT21 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT22_COUNT_MASK
        case 22U:
            base->CORR_ERR_CNT22 = 0x00U;
            break;
#endif
#ifdef ERM_CORR_ERR_CNT23_COUNT_MASK
        case 23U:
            base->CORR_ERR_CNT23 = 0x00U;
            break;
#endif
        default:
            assert(false);
            break;
    }
}
