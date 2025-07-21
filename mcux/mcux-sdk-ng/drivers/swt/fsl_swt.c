/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_swt.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.swt"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate the module clock
 *
 * @param base SWT peripheral base address
 *
 * @return The SWT instance
 */
static uint32_t SWT_GetInstance(SWT_Type *base);
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to SWT bases for each instance. */
static SWT_Type *const s_swtBases[] = SWT_BASE_PTRS;

/*! @brief Pointers to SWT clocks for each instance. */
static const clock_ip_name_t s_swtClocks[] = SWT_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
static uint32_t SWT_GetInstance(SWT_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_swtBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_swtBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_swtBases));

    return instance;
}
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*!
 * brief Initializes the SWT module with configuration.
 *
 * This function initializes the SWT. When called, the SWT runs according to the configuration.
 * This is an example.
 * code
 *   swt_config_t config;
 *   SWT_GetDefaultConfig(&config);
 *   config.timeoutValue = 32000U;
 *   SWT_Init(swt_base, &config);
 * endcode
 *
 * param base   SWT peripheral base address
 * param config Pointer to the SWT configuration structure.
 */
void SWT_Init(SWT_Type *base, const swt_config_t *config)
{
    assert(NULL != config);
    uint32_t controlValue;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate the SWT clock*/
    CLOCK_EnableClock(s_swtClocks[SWT_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    controlValue = SWT_CR_SMD(config->serviceMode) | SWT_CR_RIA(config->resetOnInvalidAccess ? 1U : 0U) |
                SWT_CR_WND(config->enableWindowMode ? 1U : 0U) | SWT_CR_STP(config->enableRunInStop ? 0U : 1U) |
                SWT_CR_FRZ(config->enableRunInDebug ? 0U : 1U) | SWT_CR_ITR(config->interruptThenReset ? 1U : 0U);

    SWT_SoftUnlock(base);
    SWT_ClearTimeoutInterruptFlag(base);
    SWT_Disable(base);
    SWT_SetTimeoutValue(base, config->timeoutValue);
    SWT_SetWindowValue(base, config->windowValue);
    SWT_SetServiceKey(base, config->serviceKey);

    base->CR &= ~(SWT_CR_SMD_MASK | SWT_CR_RIA_MASK | SWT_CR_WND_MASK | SWT_CR_STP_MASK | SWT_CR_FRZ_MASK |
                  SWT_CR_ITR_MASK);
    base->CR |= controlValue;

    if (config->enableSwt)
    {
        SWT_Enable(base);
    }
}

/*!
 * brief De-initializes the SWT module.
 *
 * This function de-initializes the SWT.
 *
 * param base SWT peripheral base address
 */
void SWT_Deinit(SWT_Type *base)
{
    uint32_t primask;
    primask = DisableGlobalIRQ();
    SWT_SoftUnlock(base);
    SWT_Disable(base);
    EnableGlobalIRQ(primask);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate the SWT clock*/
    CLOCK_DisableClock(s_swtClocks[SWT_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration for SWT.
 *
 * This function initializes the SWT configuration structure to a default value. The default
 * values are as follows.
 * code
 *   config->enableSwt = true;
 *   config->enableRunInDebug = false;
 *   config->enableRunInStop = true;
 *   config->interruptThenReset = false;
 *   config->enableWindowMode = false;
 *   config->resetOnInvalidAccess = true;
 *   config->serviceMode = kSWT_FixedServiceSequence;
 *   config->timeoutValue = 0xFFFFU;
 *   config->windowValue = 0U;
 *   config->serviceKey = 0U;
 * endcode
 * param config Pointer to the configuration structure.
 */
void SWT_GetDefaultConfig(swt_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableSwt = true;
    config->enableRunInDebug = false;
    config->enableRunInStop = true;
    config->interruptThenReset = false;
    config->enableWindowMode = false;
    config->resetOnInvalidAccess = true;
    config->serviceMode = kSWT_FixedServiceSequence;
    config->timeoutValue = 0xFFFFU;
    config->windowValue = 0U;
    config->serviceKey = 0U;
}

/*!
 * brief SWT Refresh with Fixed Service Sequence
 *
 * This function will execute a fixed service sequence to refresh the SWT.
 * SWT shall work in fixed service sequence mode ref swt_service_mode_t.
 * 
 * param base SWT peripheral base address
 */
void SWT_RefreshWithFixedServiceSequence(SWT_Type *base)
{
    uint32_t primaskValue = 0U;

    /* Disable the global interrupt to protect refresh sequence */
    primaskValue  = DisableGlobalIRQ();
    base->SR = SWT_SR_WSC(SWT_FIRST_WORD_OF_FIXED_SERVICE);
    base->SR = SWT_SR_WSC(SWT_SECOND_WORD_OF_FIXED_SERVICE);
    EnableGlobalIRQ(primaskValue);
}

/*!
 * brief SWT Refresh with Keyed Service Sequence
 *
 * This function will excute a keyed service sequence to refresh the SWT.
 * SWT shall work in keyed service sequence mode ref swt_service_mode_t.
 * 
 * param base SWT peripheral base address
 */
void SWT_RefreshWithKeyedServiceSequence(SWT_Type *base)
{
    uint32_t primaskValue = 0U;

    /* Disable the global interrupt to protect refresh sequence */
    primaskValue  = DisableGlobalIRQ();
    base->SR = (17U * (base->SK & SWT_SR_WSC_MASK) + 3U) & SWT_SR_WSC_MASK;
    base->SR = (17U * (base->SK & SWT_SR_WSC_MASK) + 3U) & SWT_SR_WSC_MASK;
    EnableGlobalIRQ(primaskValue);
}

/*!
 * brief SWT Refresh with automatic service sequence
 *
 * This function will automatically select the service sequence to refresh the SWT.
 *
 * param base SWT peripheral base address
 */
void SWT_Refresh(SWT_Type *base)
{
    if (SWT_CR_SMD(kSWT_KeyedServiceSequence) == (base->CR & SWT_CR_SMD_MASK))
    {
        SWT_RefreshWithKeyedServiceSequence(base);
    }
    else if (SWT_CR_SMD(kSWT_FixedServiceSequence) == (base->CR & SWT_CR_SMD_MASK))
    {
        SWT_RefreshWithFixedServiceSequence(base);
    }
    else
    {
        assert(false);
    }
}

/*!
 * brief Unlock the soft lock
 *
 * This function will unlock the SWT registers locked by ref SWT_SoftLock.
 * 
 * param base SWT peripheral base address
 */
void SWT_SoftUnlock(SWT_Type *base)
{
    uint32_t primaskValue = 0U;

    /* Disable the global interrupt to protect refresh sequence */
    primaskValue  = DisableGlobalIRQ();
    base->SR = SWT_SR_WSC(SWT_FIRST_WORD_OF_SOFT_UNLOCK);
    base->SR = SWT_SR_WSC(SWT_SECOND_WORD_OF_SOFT_UNLOCK);
    EnableGlobalIRQ(primaskValue);
}

/*!
 * brief Set the timeout value
 *
 * This function will set the SWT timeout period in clock cycles.
 * 
 * param base SWT peripheral base address
 * param timeoutValue The timeout value
 */
void SWT_SetTimeoutValue(SWT_Type *base, uint32_t timeoutValue)
{
#if defined(FSL_FEATURE_SWT_HAS_ERRATA_052226) && FSL_FEATURE_SWT_HAS_ERRATA_052226
    SWT_Refresh(base);
#endif /* FSL_FEATURE_SWT_HAS_ERRATA_052226 */

    /* Now safe to update timeout value */
    base->TO = SWT_TO_WTO(timeoutValue);
}
