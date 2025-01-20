/*
 * Copyright 2024 NXP
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
#define FSL_COMPONENT_ID "platform.drivers.opamp_fast"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to ADC bases for each instance. */
static OPAMP_Type *const s_opampBases[] = OPAMP_BASE_PTRS;

/*! @brief Pointers to OPAMP clocks for each instance. */
static const clock_ip_name_t s_opampClocks[] = OPAMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(OPAMP_RSTS)
static const reset_ip_name_t s_opampResets[] = OPAMP_RSTS;
#endif /* OPAMP_RSTS */

/*******************************************************************************
 * Code
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief Initialize OPAMP instance.
 *
 * param base OPAMP peripheral base address.
 * return OPAMP instance number.
 */
static uint32_t OPAMP_GetInstance(OPAMP_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0UL; instance < ARRAY_SIZE(s_opampBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_opampBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_opampBases));

    return instance;
}
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*!
 * brief Initialize OPAMP instance.
 *
 * param base OPAMP peripheral base address.
 * param config The pointer to opamp_config_t.
 */
void OPAMP_Init(OPAMP_Type *base, const opamp_config_t *config)
{
    assert(config != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_opampClocks[OPAMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(OPAMP_RSTS)
    RESET_ReleasePeripheralReset(s_opampResets[OPAMP_GetInstance(base)]);
#endif /* OPAMP_RSTS */

    /* Configure OPAMP. */
    OPAMP_SetCompensationCapcitor(base, config->compCap);
    OPAMP_SetBiasCurrent(base, config->biasCurrent);
}

/*!
 * brief De-initialize OPAMP instance.
 *
 * param base OPAMP peripheral base address.
 */
void OPAMP_Deinit(OPAMP_Type *base)
{
    /* Disable OPAMP instance. */
    OPAMP_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_opampClocks[OPAMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    
#if defined(OPAMP_RSTS)
    RESET_PeripheralReset(s_opampResets[OPAMP_GetInstance(base)]);
#endif /* OPAMP_RSTS */
}

/*!
 * brief Get default configuration of OPAMP.
 *
 * code
 *     config->enable      = false;
 *     config->compCap     = kOPAMP_FitGain2x;
 *     config->biasCurrent = kOPAMP_NoChange;
 * endcode
 *
 * param config The pointer to @ref opamp_config_t.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *config)
{
    assert(config != NULL);

    config->enable      = false;
    config->compCap     = kOPAMP_FitGain2x;
    config->biasCurrent = kOPAMP_NoChange;
}
