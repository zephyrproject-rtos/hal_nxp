/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_bctu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.bctu"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to BCTU bases for each instance. */
static BCTU_Type *s_bctuBases[] = BCTU_BASE_PTRS;

/*! @brief Pointers to BCTU clocks for each instance. */
static const clock_ip_name_t s_bctuClocks[] = BCTU_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Codes
 ******************************************************************************/
static uint32_t BCTU_GetInstance(BCTU_Type *base)
{
    uint32_t instance = 0U;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_bctuBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_bctuBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_bctuBases));

    return instance;
}

/*!
 * brief Gets the default configuration for BCTU.
 *
 * param config Pointer to BCTU configuration structure.
 */
void BCTU_GetDefaultConfig(bctu_config_t *config)
{
    assert(NULL != config);
 
    (void)memset(config, 0, sizeof(*config));

    config->debugFreezeEn       = false;
    config->writeProtect        = kBCTU_ProtectEn;
}

/*!
 * brief Initializes the BCTU.
 *
 * param base BCTU peripheral base address.
 * param config Pointer to BCTU configuration structure.
 */
void BCTU_Init(BCTU_Type *base, const bctu_config_t *config)
{
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_bctuClocks[BCTU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    base->WRPROT = ((base->WRPROT & ~BCTU_WRPROT_PROTEC_CODE_MASK) | BCTU_WRPROT_PROTEC_CODE(config->writeProtect));
    base->MCR = ((base->MCR & ~BCTU_MCR_FRZ_MASK) | BCTU_MCR_FRZ(config->debugFreezeEn ? 1U : 0U));
}

/*!
 * brief Deinitializes the BCTU.
 *
 * param base BCTU peripheral base address.
 */
void BCTU_Deinit(BCTU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_bctuClocks[BCTU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief BCTU trigger configuration.
 *
 * param base BCTU peripheral base address.
 * param config Pointer to BCTU trigger configuration structure.
 */
void BCTU_SetTrigConfig(BCTU_Type *base, const bctu_trig_config_t *config)
{
    assert(NULL != config);

    base->TRGCFG[config->trigIndex] = ((base->TRGCFG[config->trigIndex] & ~(BCTU_TRGCFG_LOOP_MASK
        | BCTU_TRGCFG_DATA_DEST_MASK | BCTU_TRGCFG_TRS_MASK | BCTU_TRGCFG_ADC_SEL0_MASK
        | BCTU_TRGCFG_ADC_SEL1_MASK
#if defined(FSL_FEATURE_BCTU_ADCDR_COUNT) && (FSL_FEATURE_BCTU_ADCDR_COUNT == 3U)
        | BCTU_TRGCFG_ADC_SEL2_MASK
#endif /* FSL_FEATURE_BCTU_ADCDR_COUNT */
        | BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR_MASK))
        | (BCTU_TRGCFG_LOOP(config->enableLoop ? 1U : 0U) | BCTU_TRGCFG_DATA_DEST(config->dataDest)
        | BCTU_TRGCFG_TRS(config->trigRes) | BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR(config->chanAddr)
        | ((uint32_t)config->targetAdc << BCTU_TRGCFG_ADC_SEL0_SHIFT)));
}

/*!
 * brief BCTU conversion list configuration.
 *
 * param base BCTU peripheral base address.
 * param config Pointer to BCTU conversion list configuration structure.
 * param convListIndex conversion list index.
 */
void BCTU_SetConvListConfig(BCTU_Type *base, const bctu_convlist_config_t *config, uint8_t convListIndex)
{
    assert(NULL != config);

    base->LISTCHR[convListIndex] = ((base->LISTCHR[convListIndex] & ~(BCTU_LISTCHR_ADC_CHL_y_plus_1_MASK
        | BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1_MASK | BCTU_LISTCHR_LAST_y_plus_1_MASK
        | BCTU_LISTCHR_ADC_CH_y_MASK | BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_MASK | BCTU_LISTCHR_LAST_y_MASK))
        | (BCTU_LISTCHR_ADC_CHL_y_plus_1(config->adcChanPlusOne) | BCTU_LISTCHR_ADC_CH_y(config->adcChan)
        | BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1(config->waitTrigPlusOne ? 1U : 0U) | BCTU_LISTCHR_LAST_y(config->lastChan ? 1U : 0U)
        | BCTU_LISTCHR_LAST_y_plus_1(config->lastChanPlusOne ? 1U : 0U) | BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y(config->waitTrig ? 1U : 0U)));
}
