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
    uint32_t eim_cnt = ARRAY_SIZE(s_eimBases);

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < eim_cnt; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_eimBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < eim_cnt);

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
    (void)CLOCK_EnableClock(s_eimClocks[EIM_GetInstance(base)]);
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
    (void)CLOCK_DisableClock(s_eimClocks[EIM_GetInstance(base)]);
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
    EIM_InjectDataWordBitError(base, channel, mask, 1U);
}

uint32_t EIM_GetDataBitMask(EIM_Type *base, uint32_t channel)
{
    return EIM_GetDataWordBitMask(base, channel, 1U);
}

/* EIM channel may have 8 words, currently the maximum support is 6. */
#define INJECT_CHANNEL(ch) \
    switch(word) { \
        SET_##ch##_1 \
        SET_##ch##_2 \
        SET_##ch##_3 \
        SET_##ch##_4 \
        SET_##ch##_5 \
        SET_##ch##_6 \
        default: assert(false); break; \
    } \
    break;

void EIM_InjectDataWordBitError(EIM_Type *base, uint32_t channel, uint32_t mask, uint32_t word)
{
    switch (channel)
    {
        case(0): { INJECT_CHANNEL(0) }
#ifdef EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK
        case(1): { INJECT_CHANNEL(1) }
#endif
#ifdef EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK
        case(2): { INJECT_CHANNEL(2) }
#endif
#ifdef EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK
        case(3): { INJECT_CHANNEL(3) }
#endif
#ifdef EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK
        case(4): { INJECT_CHANNEL(4) }
#endif
#ifdef EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK
        case(5): { INJECT_CHANNEL(5) }
#endif
#ifdef EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK
        case(6): { INJECT_CHANNEL(6) }
#endif
#ifdef EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK
        case(7): { INJECT_CHANNEL(7) }
#endif
#ifdef EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK
        case(8): { INJECT_CHANNEL(8) }
#endif
#ifdef EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK
        case(9): { INJECT_CHANNEL(9) }
#endif
#ifdef EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK
        case(10): { INJECT_CHANNEL(10) }
#endif
#ifdef EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK
        case(11): { INJECT_CHANNEL(11) }
#endif
#ifdef EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK
        case(12): { INJECT_CHANNEL(12) }
#endif
#ifdef EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK
        case(13): { INJECT_CHANNEL(13) }
#endif
#ifdef EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK
        case(14): { INJECT_CHANNEL(14) }
#endif
#ifdef EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK
        case(15): { INJECT_CHANNEL(15) }
#endif
#ifdef EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK
        case(16): { INJECT_CHANNEL(16) }
#endif
#ifdef EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK
        case(17): { INJECT_CHANNEL(17) }
#endif
#ifdef EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK
        case(18): { INJECT_CHANNEL(18) }
#endif
#ifdef EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK
        case(19): { INJECT_CHANNEL(19) }
#endif
#ifdef EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK
        case(20): { INJECT_CHANNEL(20) }
#endif
#ifdef EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK
        case(21): { INJECT_CHANNEL(21) }
#endif
#ifdef EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK
        case(22): { INJECT_CHANNEL(22) }
#endif
#ifdef EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK
        case(23): { INJECT_CHANNEL(23) }
#endif
#ifdef EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK
        case(24): { INJECT_CHANNEL(24) }
#endif
#ifdef EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK
        case(25): { INJECT_CHANNEL(25) }
#endif
#ifdef EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK
        case(26): { INJECT_CHANNEL(26) }
#endif
#ifdef EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK
        case(27): { INJECT_CHANNEL(27) }
#endif
#ifdef EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK
        case(28): { INJECT_CHANNEL(28) }
#endif
#ifdef EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK
        case(29): { INJECT_CHANNEL(29) }
#endif
#ifdef EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK
        case(30): { INJECT_CHANNEL(30) }
#endif
        default:
            assert(false);
            break;
    }
}


#define GET_CHANNEL(ch) \
    switch(word) { \
        GET_##ch##_1 \
        GET_##ch##_2 \
        GET_##ch##_3 \
        GET_##ch##_4 \
        GET_##ch##_5 \
        GET_##ch##_6 \
        default: assert(false); break; \
    } \
    break;

uint32_t EIM_GetDataWordBitMask(EIM_Type *base, uint32_t channel, uint32_t word)
{
    uint32_t mask = 0x00U;

    switch (channel)
    {
        case(0): { GET_CHANNEL(0) }
#ifdef EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK
        case(1): { GET_CHANNEL(1) }
#endif
#ifdef EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK
        case(2): { GET_CHANNEL(2) }
#endif
#ifdef EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK
        case(3): { GET_CHANNEL(3) }
#endif
#ifdef EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK
        case(4): { GET_CHANNEL(4) }
#endif
#ifdef EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK
        case(5): { GET_CHANNEL(5) }
#endif
#ifdef EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK
        case(6): { GET_CHANNEL(6) }
#endif
#ifdef EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK
        case(7): { GET_CHANNEL(7) }
#endif
#ifdef EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK
        case(8): { GET_CHANNEL(8) }
#endif
#ifdef EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK
        case(9): { GET_CHANNEL(9) }
#endif
#ifdef EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK
        case(10): { GET_CHANNEL(10) }
#endif
#ifdef EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK
        case(11): { GET_CHANNEL(11) }
#endif
#ifdef EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK
        case(12): { GET_CHANNEL(12) }
#endif
#ifdef EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK
        case(13): { GET_CHANNEL(13) }
#endif
#ifdef EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK
        case(14): { GET_CHANNEL(14) }
#endif
#ifdef EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK
        case(15): { GET_CHANNEL(15) }
#endif
#ifdef EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK
        case(16): { GET_CHANNEL(16) }
#endif
#ifdef EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK
        case(17): { GET_CHANNEL(17) }
#endif
#ifdef EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK
        case(18): { GET_CHANNEL(18) }
#endif
#ifdef EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK
        case(19): { GET_CHANNEL(19) }
#endif
#ifdef EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK
        case(20): { GET_CHANNEL(20) }
#endif
#ifdef EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK
        case(21): { GET_CHANNEL(21) }
#endif
#ifdef EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK
        case(22): { GET_CHANNEL(22) }
#endif
#ifdef EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK
        case(23): { GET_CHANNEL(23) }
#endif
#ifdef EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK
        case(24): { GET_CHANNEL(24) }
#endif
#ifdef EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK
        case(25): { GET_CHANNEL(25) }
#endif
#ifdef EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK
        case(26): { GET_CHANNEL(26) }
#endif
#ifdef EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK
        case(27): { GET_CHANNEL(27) }
#endif
#ifdef EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK
        case(28): { GET_CHANNEL(28) }
#endif
#ifdef EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK
        case(29): { GET_CHANNEL(29) }
#endif
#ifdef EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK
        case(30): { GET_CHANNEL(30) }
#endif
        default:
            assert(false);
            break;
    }

    return mask;
}
