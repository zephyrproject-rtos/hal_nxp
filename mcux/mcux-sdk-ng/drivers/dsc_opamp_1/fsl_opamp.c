/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_opamp.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_opamp_1"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * @brief Get instance number for OPAMP module.
 *
 * @param base OPAMP peripheral base address
 */
static uint32_t OPAMP_GetInstance(OPAMP_Type *base);
#endif

/*!
 * @brief Get the configuration register value based on configuration set structure.
 *
 * @param psSet Pointer to the configuration set structure.
 * @return The OPAMP configuration set register value.
 */
static uint16_t OPAMP_GetConfigSetRegFromStruct(const opamp_config_set_t *psSet);

/*!
 * @brief Gets Current effective Config register.
 *
 * @param base OPAMP peripheral base address.
 * @return  Current effective Config register.
 */
static uint16_t GetCurrentEffectiveConfigReg(OPAMP_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to OPAMP bases for each instance. */
static OPAMP_Type *const s_opampBases[] = OPAMP_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to OPAMP clocks for each instance. */
static const clock_ip_name_t s_opampClocks[] = OPAMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Default configuration register set. */
static const opamp_config_set_t s_opampDefaultConfigSet = {
    kOPAMP_WorkModeBufferMode, /* eWorkMode */
    kOPAMP_NegChannel0,        /* eNegChannel.*/
    kOPAMP_PosChannel0,        /* ePosChannel.*/
};

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t OPAMP_GetInstance(OPAMP_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0; u32Instance < ARRAY_SIZE(s_opampBases); u32Instance++)
    {
        if (s_opampBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_opampBases));

    return u32Instance;
}

/*!
 * @brief Get the configuration register value based on configuration set structure.
 *
 * @param psSet Pointer to the configuration set structure.
 * @return The OPAMP configuration set register value.
 */
static uint16_t OPAMP_GetConfigSetRegFromStruct(const opamp_config_set_t *psSet)
{
    return (uint16_t)psSet->eWorkMode | ((uint16_t)psSet->eNegChannel << OPAMP_CFG_VNEG_SEL_SHIFT) |
           ((uint16_t)psSet->ePosChannel << OPAMP_CFG_VPOS_SEL_SHIFT);
}

/*!
 * @brief Gets Current effective Config register.
 *
 * @param base OPAMP peripheral base address.
 * @return  Current effective Config register.
 */
static uint16_t GetCurrentEffectiveConfigReg(OPAMP_Type *base)
{
    return (uint16_t)((base->STAT & OPAMP_STAT_CURRENT_CFG_MASK) >> OPAMP_STAT_CURRENT_CFG_SHIFT);
}

/*
 * brief Initializes the OPAMP module.
 *
 * This function does initialization when using OPAMP module.
 * The operations are:
 *  - Enable the clock for OPAMP.
 *  - Enable the write protection.
 *  - Enable the load completion interrupt.
 *  - Set configuration register for OPAMP.
 *  - Set Positive channel and Negative channel.
 *  - Set the power mode.
 *  - Set the gain value.
 *  - Set the load mode.
 *  - Enable the OPAMP.
 *
 * param base   OPAMP peripheral base address.
 * param psConfig Pointer to configuration structure.
 */
void OPAMP_Init(OPAMP_Type *base, const opamp_config_t *psConfig)
{
    assert(psConfig != NULL);

    uint16_t u16Tmp = 0U;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enables Clock. */
    CLOCK_EnableClock(s_opampClocks[OPAMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Clear load completion flag*/
    OPAMP_ClearLoadCompletionFlag(base);

    /* Check if write protection is enable.*/
    if (0U != (base->CTRL & OPAMP_CTRL_WP_MASK))
    {
        base->CTRL = 0U;
    }

    base->CFG[0] = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet0);
    base->CFG[1] = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet1);
    base->CFG[2] = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet2);
    base->CFG[3] = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet3);

    /*Enable the opamp.*/
    OPAMP_EnableOPAMP(base, true);

    /*Select configuration register */
    u16Tmp = ((uint16_t)(psConfig->eConfigRegSel)) << 8U;

    /*Enable write protection. */
    if (psConfig->bEnableWriteProtection)
    {
        u16Tmp |= OPAMP_CTRL_WP_MASK;
    }
    /*Enable load completion interrupt.*/
    if (psConfig->bEnableLoadCompletionInterrupt)
    {
        u16Tmp |= OPAMP_CTRL_LDCMIE_MASK;
    }
    /*Enable high speed mode.*/
    if (psConfig->ePowerMode == kOPAMP_PowerModeHighSpeed)
    {
        u16Tmp |= OPAMP_CTRL_PMOD_MASK;
    }
    /*Enable fast load mode.*/
    if (psConfig->eLoadMode == kOPAMP_LoadModeImmediatelyLoad)
    {
        base->CTRL |= u16Tmp | OPAMP_CTRL_LDMOD_MASK | OPAMP_CTRL_LDOK_MASK;
    }
    else
    {
        if ((psConfig->eConfigRegSel == kOPAMP_ConfigRegSelCFG0) || (psConfig->eConfigRegSel > kOPAMP_ConfigRegSelCFG3))
        {
            base->CTRL |= OPAMP_CTRL_CONFIG_SEL(1U);
        }

        base->CTRL = (base->CTRL & ~(uint16_t)OPAMP_CTRL_CONFIG_SEL_MASK) | u16Tmp | OPAMP_CTRL_LDOK_MASK;
    }

    /*Until the bit is automatically cleared, the loading is complete.*/
    while (OPAMP_CTRL_LDOK_MASK == (base->CTRL & OPAMP_CTRL_LDOK_MASK))
    {
    }
}

/*
 * brief Gets default configuration for OPAMP.
 *
 * The default value:
 * code
    psConfig->bEnableLoadCompletionInterrupt = false;
    psConfig->bEnableWriteProtection = false;
    psConfig->eLoadMode = kOPAMP_LoadModeDelayLoad;
    psConfig->ePowerMode = kOPAMP_PowerModeLowPower;
    psConfig->eConfigRegSel   = kOPAMP_ConfigRegSelCFG0;

    psConfig->sConfigSet0.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet0.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet0.ePosChannel = kOPAMP_PosChannel0;

    psConfig->sConfigSet1.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet1.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet1.ePosChannel = kOPAMP_PosChannel0;

    psConfig->sConfigSet2.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet2.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet2.ePosChannel = kOPAMP_PosChannel0;

    psConfig->sConfigSet3.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet3.eNegChannel = kOPAMP_NegChannel0;
    psConfig->sConfigSet3.ePosChannel = kOPAMP_PosChannel0;

   endcode
 *
 * param psConfig Pointer to configuration structure.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *psConfig)
{
    assert(NULL != psConfig);

    psConfig->bEnableLoadCompletionInterrupt = false;
    psConfig->bEnableWriteProtection         = false;
    psConfig->eLoadMode                      = kOPAMP_LoadModeDelayLoad;
    psConfig->ePowerMode                     = kOPAMP_PowerModeLowPower;
    psConfig->eConfigRegSel                  = kOPAMP_ConfigRegSelCFG0;
    psConfig->sConfigSet0                    = s_opampDefaultConfigSet;
    psConfig->sConfigSet1                    = s_opampDefaultConfigSet;
    psConfig->sConfigSet2                    = s_opampDefaultConfigSet;
    psConfig->sConfigSet3                    = s_opampDefaultConfigSet;
}

/*
 * De-initializes the OPAMP module.
 *
 * This function does de-initialization when using OPAMP module.
 * The operations are:
 *  - Disable the OPAMP.
 *  - Disable the clock for OPAMP.
 *
 * param base OPAMP peripheral base address.
 */
void OPAMP_Deinit(OPAMP_Type *base)
{
    /*Disable the opamp */
    OPAMP_EnableOPAMP(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable Clock. */
    CLOCK_DisableClock(s_opampClocks[OPAMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets configuration set.
 *
 * This function only sets the configuration set, application should
 * call OPAMP_EnableConfigLoad to enable the load after setting all desired configuration sets.
 *
 * param base OPAMP peripheral base address.
 * param eIndex Index of configuration set,please see @ref opamp_config_set_index_t for details.
 * param psConfigSet Pointer to the configure structure.
 */
void OPAMP_SetOneConfigSet(OPAMP_Type *base, opamp_config_set_index_t eIndex, const opamp_config_set_t *psConfigSet)
{
    uint16_t u16Reg = OPAMP_GetConfigSetRegFromStruct(psConfigSet);

    base->CFG[(uint8_t)eIndex] = u16Reg;

    if ((base->CTRL & OPAMP_CTRL_LDMOD_MASK) != OPAMP_CTRL_LDMOD_MASK)
    {
        uint16_t u16Value = GetCurrentEffectiveConfigReg(base);

        if (u16Value == 0U)
        {
            u16Value = (base->CTRL &
                        ~(uint16_t)(OPAMP_CTRL_CONFIG_SEL_MASK | OPAMP_CTRL_CFG_SLL_MASK | OPAMP_CTRL_CFG_SLH_MASK));

            if ((uint8_t)eIndex > 0U)
            {
                base->CTRL = u16Value | OPAMP_CTRL_CONFIG_SEL(0U);
            }
            else
            {
                base->CTRL = u16Value | OPAMP_CTRL_CONFIG_SEL(1U);
            }
        }
        else
        {
            base->CTRL = (base->CTRL & ~(uint16_t)OPAMP_CTRL_CONFIG_SEL_MASK) | OPAMP_CTRL_CONFIG_SEL(0U);
        }
    }
}

/*!
 * brief Changes configuration register selection.
 *
 * This function can configure the working registers of the software and external signal. When the
 * configuration set is updated using OPAMP_SetOneConfigSet and the external signal is not used, the software
 * working register should also select the corresponding software working register according to the update of the
 * configuration set.
 *
 * param base OPAMP peripheral base address.
 * param eConfigRegSel configuration register selection, please see @ref opamp_config_reg_sel_t for details.
 */
void OPAMP_SetConfigSelection(OPAMP_Type *base, opamp_config_reg_sel_t eConfigRegSel)
{
    uint16_t u16Tmp =
        base->CTRL & ~(uint16_t)(OPAMP_CTRL_CONFIG_SEL_MASK | OPAMP_CTRL_CFG_SLL_MASK | OPAMP_CTRL_CFG_SLH_MASK);

    u16Tmp |= ((uint16_t)eConfigRegSel) << 8U;
    base->CTRL = u16Tmp;
}
