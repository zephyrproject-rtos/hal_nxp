/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_opamp.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.opamp_1"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to OPAMP bases for each instance. */
static OPAMP_Type *const s_opampBases[] = OPAMP_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to OPAMP clocks for each instance. */
static const clock_ip_name_t s_opampClocks[] = OPAMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(OPAMP_RSTS)
static const reset_ip_name_t s_opampResets[] = OPAMP_RSTS;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Get the instance for OPAMP module.
 *
 * @param base OPAMP peripheral base address.
 * @return OPAMP instance number.
 */
uint32_t OPAMP_GetInstance(OPAMP_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0UL; instance < ARRAY_SIZE(s_opampBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_opampBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    if (instance == ARRAY_SIZE(s_opampBases))
    {
        instance = 0xFFFFFFFFU; /* Return 0xFFFFFFFF if invalid base address is provided. */
    }

    return instance;
}

/*!
 * @brief Initialize OPAMP instance.
 *
 * @param base OPAMP peripheral base address.
 * @param config The pointer to opamp_config_t.
 * @retval kStatus_Success if initialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t OPAMP_Init(OPAMP_Type *base, const opamp_config_t *config)
{
    assert(config != NULL);

    uint32_t instance = OPAMP_GetInstance(base);
    uint32_t reg;

    if (instance >= ARRAY_SIZE(s_opampBases))
    {
        /* Invalid instance, do not attempt to initialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_opampClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(OPAMP_RSTS)
    RESET_ReleasePeripheralReset(s_opampResets[instance]);
#endif

    /* Disable OPAMP output before configuration. */
    base->CTRL &= MCUX_MASK_INVERT_32(OPAMP_CTRL_ENA_MASK);

    /* Configure CTRL: bias current, offset voltage trim, gain, capacitance compensation, offset reference. */
    reg = base->CTRL;
    reg &= MCUX_MASK_INVERT_32(OPAMP_CTRL_IREF_CONFIG_MASK | OPAMP_CTRL_VOS_TRIM_MASK |
                               OPAMP_CTRL_GAIN_CONFIG_MASK | OPAMP_CTRL_CC_CONFIG_MASK |
                               OPAMP_CTRL_OFFSET_SEL_MASK);
    reg |= OPAMP_CTRL_IREF_CONFIG(config->biasCurrent) |
           OPAMP_CTRL_VOS_TRIM(config->vosTrim) |
           OPAMP_CTRL_GAIN_CONFIG(config->gain) |
           OPAMP_CTRL_CC_CONFIG(config->capCompensation) |
           OPAMP_CTRL_OFFSET_SEL(config->offsetSel);
    base->CTRL = reg;

    return kStatus_Success;
}

/*!
 * @brief De-initialize OPAMP instance.
 *
 * @param base OPAMP peripheral base address.
 * @retval kStatus_Success if deinitialization is successful.
 * @retval kStatus_InvalidArgument if the base address is invalid.
 */
status_t OPAMP_Deinit(OPAMP_Type *base)
{
    uint32_t instance = OPAMP_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_opampBases))
    {
        /* Invalid instance, do not attempt to deinitialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_opampClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(OPAMP_RSTS)
    RESET_PeripheralReset(s_opampResets[instance]);
#endif

    return kStatus_Success;
}

/*!
 * @brief Fill an opamp_config_t with safe default values.
 *
 * @param config Pointer to configuration structure; must not be NULL.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *config)
{
    assert(config != NULL);

    config->biasCurrent     = kOPAMP_BiasCurrentRatio1;
    config->vosTrim         = kOPAMP_VosTrim0mV;
    config->gain            = kOPAMP_Gain3;
    config->capCompensation = kOPAMP_CapCompensationGain3;
    config->offsetSel       = kOPAMP_OffsetSelVddaDiv2;
}
