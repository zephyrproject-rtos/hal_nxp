/*
 * Copyright 2020 NXP
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
#define FSL_COMPONENT_ID "platform.drivers.dsc_opamp"
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

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to OPAMP bases for each instance. */
static OPAMP_Type *const s_opampBases[] = OPAMP_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to OPAMP clocks for each instance. */
static const clock_ip_name_t s_opampClocks[] = OPAMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*! @brief Default rotation configuration set. */
static const opamp_config_set_t s_opampDefaultConfigSet = {
    kOPAMP_WorkModeBufferMode, /* eWorkMode */
    kOPAMP_VNEG0,              /* eVNEG */
    kOPAMP_VPOS0,              /* eVPOS */
    15,                        /* u8PreviousConfigSetWindow */
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

static uint16_t OPAMP_GetConfigSetRegFromStruct(const opamp_config_set_t *psSet)
{
    return (uint16_t)psSet->eWorkMode | ((uint16_t)psSet->eVNEG << OPAMP_OPAMP_CONFIG_SET0_VNEG_SEL_SHIFT) |
           ((uint16_t)psSet->eVPOS << OPAMP_OPAMP_CONFIG_SET0_VPOS_SEL_SHIFT) |
           OPAMP_OPAMP_CONFIG_SET0_WINDOW_VAL(psSet->u8PreviousConfigSetWindow);
}

/*
 * brief Initializes the OPAMP module.
 *
 * This function enables the OPAMP IP bus clock (optional, controlled by
 * macro FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL), sets the configuration to
 * OPAMP and triggers the load.
 *
 * param base   OPAMP peripheral base address.
 * param psConfig Pointer to configuration structure.
 */
void OPAMP_Init(OPAMP_Type *base, const opamp_config_t *psConfig)
{
    assert(psConfig != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enables Clock. */
    CLOCK_EnableClock(s_opampClocks[OPAMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    OPAMP_ClearLoadCompletionFlag(base);

    while (kStatus_Success != OPAMP_UpdateModuleConfig(base, psConfig))
    {
    }
}

/*
 * brief Get default configuration for OPAMP.
 *
 * The default value:
 * code
    psConfig->bEnableLoadCompletionInterrupt = false;
    psConfig->bEnableWriteProtection = false;
    psConfig->eLoadMode = kOPAMP_LoadModeDelayLoad;
    psConfig->ePowerMode = kOPAMP_PowerModeLowPower;
    psConfig->eRotateNumber = kOPAMP_RotateConfigSet0;

    psConfig->sConfigSet0.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet0.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet0.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet0.u8PreviousConfigSetWindow = 15;

    psConfig->sConfigSet1.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet1.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet1.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet1.u8PreviousConfigSetWindow = 15;

    psConfig->sConfigSet2.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet2.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet2.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet2.u8PreviousConfigSetWindow = 15;

    psConfig->sConfigSet3.eWorkMode = kOPAMP_WorkModeBufferMode;
    psConfig->sConfigSet3.eVNEG = kOPAMP_VNEG0;
    psConfig->sConfigSet3.eVPOS = kOPAMP_VPOS0;
    psConfig->sConfigSet3.u8PreviousConfigSetWindow = 15;
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
    psConfig->eRotateNumber                  = kOPAMP_RotateConfigSet0;
    psConfig->sConfigSet0                    = s_opampDefaultConfigSet;
    psConfig->sConfigSet1                    = s_opampDefaultConfigSet;
    psConfig->sConfigSet2                    = s_opampDefaultConfigSet;
    psConfig->sConfigSet3                    = s_opampDefaultConfigSet;
}

/*
 * De-initializes the OPAMP module.
 *
 * This function only disables the OPAMP IP bus clock (optional, controlled by
 * the macro FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL).
 *
 * param base OPAMP peripheral base address.
 */
void OPAMP_Deinit(OPAMP_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable Clock. */
    CLOCK_DisableClock(s_opampClocks[OPAMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*
 * brief Configure the OPAMP module and enable the configuration load.
 *
 * This function sets the new configuration, and enables the configuration load.
 * If previous old configuration has not been loaded, this function returns
 * kStatus_Fail. Application could use OPAMP_GetLoadCompletionFlag
 * to check whether the old configuration has been loaded.
 *
 * After calling this function, the new configuration will be loaed at the
 * time decided by ::opamp_config_t::eLoadMode.
 *
 * param base OPAMP peripheral base address.
 * param psConfig Pointer to the configuration.
 * retval kStatus_Success The configuration is set.
 * retval kStatus_Fail Could not set configuration because old configuration
 * has not been loaded.
 */
status_t OPAMP_UpdateModuleConfig(OPAMP_Type *base, const opamp_config_t *psConfig)
{
    uint16_t u16CTR = 0U;

    if (0U != (base->OPAMP_CTR & OPAMP_OPAMP_CTR_CONFIG_LOAD_MASK))
    {
        return kStatus_Fail;
    }

    /* If registers locked, unlock it. */
    if (0U != (base->OPAMP_CTR & OPAMP_OPAMP_CTR_WP_MASK))
    {
        base->OPAMP_CTR = 0U;
    }

    base->OPAMP_CONFIG_SET0 = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet0);
    base->OPAMP_CONFIG_SET1 = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet1);
    base->OPAMP_CONFIG_SET2 = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet2);
    base->OPAMP_CONFIG_SET3 = OPAMP_GetConfigSetRegFromStruct(&psConfig->sConfigSet3);

    if (psConfig->bEnableLoadCompletionInterrupt)
    {
        u16CTR |= OPAMP_OPAMP_CTR_LDCMIE_MASK;
    }

    if (psConfig->bEnableWriteProtection)
    {
        u16CTR |= OPAMP_OPAMP_CTR_WP_MASK;
    }

    if (kOPAMP_LoadModeRealTimeLoad == psConfig->eLoadMode)
    {
        u16CTR |= OPAMP_OPAMP_CTR_FAST_LOAD_MASK;
    }

    if (kOPAMP_PowerModeHighSpeed == psConfig->ePowerMode)
    {
        u16CTR |= OPAMP_OPAMP_CTR_PMD_MASK;
    }

    u16CTR |= OPAMP_OPAMP_CTR_CONFIG_NUM(psConfig->eRotateNumber);

    base->OPAMP_CTR = u16CTR | OPAMP_OPAMP_CTR_CONFIG_LOAD_MASK;

    return kStatus_Success;
}

/*
 * brief Set the rotation configuration set.
 *
 * This function only sets the rotation configuration set, application should
 * call OPAMP_EnableConfigLoad to enable the load after set all desired configuration sets.
 *
 * param base OPAMP peripheral base address.
 * param eIndex Index of configuration set.
 * param psConfigSet Pointer to the configure structure.
 */
void OPAMP_SetOneConfigSet(OPAMP_Type *base, opamp_config_set_index_t eIndex, const opamp_config_set_t *psConfigSet)
{
    uint16_t u16Reg = OPAMP_GetConfigSetRegFromStruct(psConfigSet);

    switch (eIndex)
    {
        case kOPAMP_ConfigSet0:
            base->OPAMP_CONFIG_SET0 = u16Reg;
            break;

        case kOPAMP_ConfigSet1:
            base->OPAMP_CONFIG_SET1 = u16Reg;
            break;

        case kOPAMP_ConfigSet2:
            base->OPAMP_CONFIG_SET2 = u16Reg;
            break;

        case kOPAMP_ConfigSet3:
            base->OPAMP_CONFIG_SET3 = u16Reg;
            break;

        default:
            /* Empty. */
            break;
    }
}
