/*
 * Copyright 2022, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_eim.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.eim"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to EIM bases for each instance. */
static EIM_Type *const s_eimBases[] = EIM_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to EIM clocks for each instance. */
static const clock_ip_name_t s_eimClocks[] = EIM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(EIM_RSTS_N)
/*! @brief Pointers to EIM resets for each instance. */
static const reset_ip_name_t s_eimResets[] = EIM_RSTS_N;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t EIM_GetInstance(EIM_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_eimBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_eimBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_eimBases));

    return instance;
}

/*!
 * brief EIM module initialization function.
 *
 * param base EIM base address.
 */
void EIM_Init(EIM_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate EIM clock. */
    CLOCK_EnableClock(s_eimClocks[EIM_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#if defined(EIM_RSTS_N)
    /* Reset the EIM module */
    RESET_PeripheralReset(s_eimResets[EIM_GetInstance(base)]);
#endif
    base->EIMCR  = 0x00U;
    base->EICHEN = 0x00U;
}

/*!
 * brief Deinitializes the EIM.
 *
 */
void EIM_Deinit(EIM_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate EIM clock. */
    CLOCK_DisableClock(s_eimClocks[EIM_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void EIM_InjectCheckBitError(EIM_Type *base, uint32_t channel, uint32_t mask)
{
    switch (channel)
    {
        case 0U:
            base->EICHD0_WORD0 = EIM_EICHD0_WORD0_CHKBIT_MASK(mask);
            break;
#ifdef EIM_EICHD1_WORD0_CHKBIT_MASK_MASK
        case 1U:
            base->EICHD1_WORD0 = EIM_EICHD1_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD2_WORD0_CHKBIT_MASK_MASK
        case 2U:
            base->EICHD2_WORD0 = EIM_EICHD2_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD3_WORD0_CHKBIT_MASK_MASK
        case 3U:
            base->EICHD3_WORD0 = EIM_EICHD3_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD4_WORD0_CHKBIT_MASK_MASK
        case 4U:
            base->EICHD4_WORD0 = EIM_EICHD4_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD5_WORD0_CHKBIT_MASK_MASK
        case 5U:
            base->EICHD5_WORD0 = EIM_EICHD5_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD6_WORD0_CHKBIT_MASK_MASK
        case 6U:
            base->EICHD6_WORD0 = EIM_EICHD6_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD7_WORD0_CHKBIT_MASK_MASK
        case 7U:
            base->EICHD7_WORD0 = EIM_EICHD7_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD8_WORD0_CHKBIT_MASK_MASK
        case 8U:
            base->EICHD8_WORD0 = EIM_EICHD8_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD9_WORD0_CHKBIT_MASK_MASK
        case 9U:
            base->EICHD9_WORD0 = EIM_EICHD9_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD10_WORD0_CHKBIT_MASK_MASK
        case 10U:
            base->EICHD10_WORD0 = EIM_EICHD10_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD11_WORD0_CHKBIT_MASK_MASK
        case 11U:
            base->EICHD11_WORD0 = EIM_EICHD11_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD12_WORD0_CHKBIT_MASK_MASK
        case 12U:
            base->EICHD12_WORD0 = EIM_EICHD12_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD13_WORD0_CHKBIT_MASK_MASK
        case 13U:
            base->EICHD13_WORD0 = EIM_EICHD13_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD14_WORD0_CHKBIT_MASK_MASK
        case 14U:
            base->EICHD14_WORD0 = EIM_EICHD14_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD15_WORD0_CHKBIT_MASK_MASK
        case 15U:
            base->EICHD15_WORD0 = EIM_EICHD15_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD16_WORD0_CHKBIT_MASK_MASK
        case 16U:
            base->EICHD16_WORD0 = EIM_EICHD16_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD17_WORD0_CHKBIT_MASK_MASK
        case 17U:
            base->EICHD17_WORD0 = EIM_EICHD17_WORD0_CHKBIT_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD18_WORD0_CHKBIT_MASK_MASK
        case 18U:
            base->EICHD18_WORD0 = EIM_EICHD18_WORD0_CHKBIT_MASK(mask);
            break;
#endif
        default:
            assert(false);
            break;
    }
}

uint32_t EIM_GetCheckBitMask(EIM_Type *base, uint32_t channel)
{
    uint32_t mask = 0x00000000U;

    switch (channel)
    {
        case 0U:
            mask = (uint32_t)((base->EICHD0_WORD0 & EIM_EICHD0_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT);
            break;
#ifdef EIM_EICHD1_WORD0_CHKBIT_MASK_MASK
        case 1U:
            mask = (uint32_t)((base->EICHD1_WORD0 & EIM_EICHD1_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD2_WORD0_CHKBIT_MASK_MASK
        case 2U:
            mask = (uint32_t)((base->EICHD2_WORD0 & EIM_EICHD2_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD3_WORD0_CHKBIT_MASK_MASK
        case 3U:
            mask = (uint32_t)((base->EICHD3_WORD0 & EIM_EICHD3_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD4_WORD0_CHKBIT_MASK_MASK
        case 4U:
            mask = (uint32_t)((base->EICHD4_WORD0 & EIM_EICHD4_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD5_WORD0_CHKBIT_MASK_MASK
        case 5U:
            mask = (uint32_t)((base->EICHD5_WORD0 & EIM_EICHD5_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD6_WORD0_CHKBIT_MASK_MASK
        case 6U:
            mask = (uint32_t)((base->EICHD6_WORD0 & EIM_EICHD6_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD7_WORD0_CHKBIT_MASK_MASK
        case 7U:
            mask = (uint32_t)((base->EICHD7_WORD0 & EIM_EICHD7_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD8_WORD0_CHKBIT_MASK_MASK
        case 8U:
            mask = (uint32_t)((base->EICHD8_WORD0 & EIM_EICHD8_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD9_WORD0_CHKBIT_MASK_MASK
        case 9U:
            mask = (uint32_t)((base->EICHD9_WORD0 & EIM_EICHD9_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD10_WORD0_CHKBIT_MASK_MASK
        case 10U:
            mask = (uint32_t)((base->EICHD10_WORD0 & EIM_EICHD10_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD11_WORD0_CHKBIT_MASK_MASK
        case 11U:
            mask = (uint32_t)((base->EICHD11_WORD0 & EIM_EICHD11_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD12_WORD0_CHKBIT_MASK_MASK
        case 12U:
            mask = (uint32_t)((base->EICHD12_WORD0 & EIM_EICHD12_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD13_WORD0_CHKBIT_MASK_MASK
        case 13U:
            mask = (uint32_t)((base->EICHD13_WORD0 & EIM_EICHD13_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD13_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD14_WORD0_CHKBIT_MASK_MASK
        case 14U:
            mask = (uint32_t)((base->EICHD14_WORD0 & EIM_EICHD14_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD14_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD15_WORD0_CHKBIT_MASK_MASK
        case 15U:
            mask = (uint32_t)((base->EICHD15_WORD0 & EIM_EICHD15_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD15_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD16_WORD0_CHKBIT_MASK_MASK
        case 16U:
            mask = (uint32_t)((base->EICHD16_WORD0 & EIM_EICHD16_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD16_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD17_WORD0_CHKBIT_MASK_MASK
        case 17U:
            mask = (uint32_t)((base->EICHD17_WORD0 & EIM_EICHD17_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD17_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
#ifdef EIM_EICHD18_WORD0_CHKBIT_MASK_MASK
        case 18U:
            mask = (uint32_t)((base->EICHD18_WORD0 & EIM_EICHD18_WORD0_CHKBIT_MASK_MASK) >>
                              EIM_EICHD18_WORD0_CHKBIT_MASK_SHIFT);
            break;
#endif
        default:
            assert(false);
            break;
    }

    return mask;
}

void EIM_InjectDataBitError(EIM_Type *base, uint32_t channel, uint32_t mask)
{
    switch (channel)
    {
        case 0U:
            base->EICHD0_WORD1 = EIM_EICHD0_WORD1_B0_3DATA_MASK(mask);
            break;
#ifdef EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK
        case 1U:
            base->EICHD1_WORD1 = EIM_EICHD1_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK
        case 2U:
            base->EICHD2_WORD1 = EIM_EICHD2_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK
        case 3U:
            base->EICHD3_WORD1 = EIM_EICHD3_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK
        case 4U:
            base->EICHD4_WORD1 = EIM_EICHD4_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK
        case 5U:
            base->EICHD5_WORD1 = EIM_EICHD5_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK
        case 6U:
            base->EICHD6_WORD1 = EIM_EICHD6_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK
        case 7U:
            base->EICHD7_WORD1 = EIM_EICHD7_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK
        case 8U:
            base->EICHD8_WORD1 = EIM_EICHD8_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK
        case 9U:
            base->EICHD9_WORD1 = EIM_EICHD9_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK
        case 10U:
            base->EICHD10_WORD1 = EIM_EICHD10_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK
        case 11U:
            base->EICHD11_WORD1 = EIM_EICHD11_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK
        case 12U:
            base->EICHD12_WORD1 = EIM_EICHD12_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK
        case 13U:
            base->EICHD13_WORD1 = EIM_EICHD13_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK
        case 14U:
            base->EICHD14_WORD1 = EIM_EICHD14_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK
        case 15U:
            base->EICHD15_WORD1 = EIM_EICHD15_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK
        case 16U:
            base->EICHD16_WORD1 = EIM_EICHD16_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK
        case 17U:
            base->EICHD17_WORD1 = EIM_EICHD17_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK
        case 18U:
            base->EICHD18_WORD1 = EIM_EICHD18_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK
        case 19U:
            base->EICHD19_WORD1 = EIM_EICHD19_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK
        case 20U:
            base->EICHD20_WORD1 = EIM_EICHD20_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK
        case 21U:
            base->EICHD21_WORD1 = EIM_EICHD21_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK
        case 22U:
            base->EICHD22_WORD1 = EIM_EICHD22_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK
        case 23U:
            base->EICHD23_WORD1 = EIM_EICHD23_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK
        case 24U:
            base->EICHD24_WORD1 = EIM_EICHD24_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK
        case 25U:
            base->EICHD25_WORD1 = EIM_EICHD25_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK
        case 26U:
            base->EICHD26_WORD1 = EIM_EICHD26_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK
        case 27U:
            base->EICHD27_WORD1 = EIM_EICHD27_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK
        case 28U:
            base->EICHD28_WORD1 = EIM_EICHD28_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK
        case 29U:
            base->EICHD29_WORD1 = EIM_EICHD29_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
#ifdef EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK
        case 30U:
            base->EICHD30_WORD1 = EIM_EICHD30_WORD1_B0_3DATA_MASK(mask);
            break;
#endif
        default:
            assert(false);
            break;
    }
}

uint32_t EIM_GetDataBitMask(EIM_Type *base, uint32_t channel)
{
    uint32_t mask = 0x00U;

    switch (channel)
    {
        case 0U:
            mask = (base->EICHD0_WORD1 & EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#ifdef EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK
        case 1U:
            mask = (base->EICHD1_WORD1 & EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK
        case 2U:
            mask = (base->EICHD2_WORD1 & EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK
        case 3U:
            mask = (base->EICHD3_WORD1 & EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK
        case 4U:
            mask = (base->EICHD4_WORD1 & EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK
        case 5U:
            mask = (base->EICHD5_WORD1 & EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK
        case 6U:
            mask = (base->EICHD6_WORD1 & EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK
        case 7U:
            mask = (base->EICHD7_WORD1 & EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK
        case 8U:
            mask = (base->EICHD8_WORD1 & EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK
        case 9U:
            mask = (base->EICHD9_WORD1 & EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK
        case 10U:
            mask =
                (base->EICHD10_WORD1 & EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK
        case 11U:
            mask =
                (base->EICHD11_WORD1 & EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK
        case 12U:
            mask =
                (base->EICHD12_WORD1 & EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK
        case 13U:
            mask =
                (base->EICHD13_WORD1 & EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD13_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK
        case 14U:
            mask =
                (base->EICHD14_WORD1 & EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD14_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK
        case 15U:
            mask =
                (base->EICHD15_WORD1 & EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD15_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK
        case 16U:
            mask =
                (base->EICHD16_WORD1 & EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK
        case 17U:
            mask =
                (base->EICHD17_WORD1 & EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK
        case 18U:
            mask =
                (base->EICHD18_WORD1 & EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK
        case 19U:
            mask =
                (base->EICHD19_WORD1 & EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD19_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK
        case 20U:
            mask =
                (base->EICHD20_WORD1 & EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD20_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK
        case 21U:
            mask =
                (base->EICHD21_WORD1 & EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD21_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK
        case 22U:
            mask =
                (base->EICHD22_WORD1 & EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD22_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK
        case 23U:
            mask =
                (base->EICHD23_WORD1 & EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD23_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK
        case 24U:
            mask =
                (base->EICHD24_WORD1 & EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD24_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK
        case 25U:
            mask =
                (base->EICHD25_WORD1 & EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD25_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK
        case 26U:
            mask =
                (base->EICHD26_WORD1 & EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD26_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK
        case 27U:
            mask =
                (base->EICHD27_WORD1 & EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD27_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK
        case 28U:
            mask =
                (base->EICHD28_WORD1 & EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD28_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK
        case 29U:
            mask =
                (base->EICHD29_WORD1 & EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD29_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
#ifdef EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK
        case 30U:
            mask =
                (base->EICHD30_WORD1 & EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK) >> EIM_EICHD30_WORD1_B0_3DATA_MASK_SHIFT;
            break;
#endif
        default:
            assert(false);
            break;
    }

    return mask;
}
