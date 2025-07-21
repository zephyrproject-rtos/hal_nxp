/*
 * Copyright 2025 NXP.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_wkpu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.wkpu"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static wkpu_callback_t s_WkpuCallback;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Fills in the WKPU external wake up source config struct with the default settings.
 *
 * The default values are as follows.
 * code
 *     config->event               = kWKPU_WakeUp;
 *     config->edge                       = kWKPU_PinRisingEdge;
 *     config->enableFilter               = false;
 * endcode
 *
 * param config Pointer to the user defined WKPU configuration structure.
 */
void WKPU_GetDefaultExternalWakeUpSourceConfig(wkpu_external_wakeup_source_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->event        = kWKPU_WakeUp;
    config->edge         = kWKPU_PinRisingEdge;
    config->enableFilter = true;
}

/*!
 * brief Enable and config the external wakeup source.
 *
 * This function enables/disables the external wake up source as the wake up input. The wake up sources are mostly wake
 * up pins with several internal wakeup modules.
 *
 * param base         WKPU peripheral base address.
 * param mask         The wake up source to used. This is a logical OR of members of the enumeration ::wkpu_source_t
 * param config       Pointer to wkpu_external_wakeup_source_config_t structure.
 */
void WKPU_SetExternalWakeUpSourceConfig(WKPU_Type *base,
                                        uint64_t mask,
                                        const wkpu_external_wakeup_source_config_t *config)
{
    assert(config != NULL);

    uint32_t lowBitMask  = (uint32_t)(uint64_t)(mask & 0xFFFFFFFF);
    uint32_t highBitMask = (uint32_t)(uint64_t)(mask >> 32);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(kCLOCK_Wkup);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Clear wakeup and interrupt flags */
    base->WISR    = 0xFFFFFFFF;
    base->WISR_64 = 0xFFFFFFFF;

    if (config->event == kWKPU_Interrupt)
    {
        base->IRER |= lowBitMask;
        base->IRER_64 |= highBitMask;
    }
    else if (config->event == kWKPU_WakeUp)
    {
        base->WRER |= lowBitMask;
        base->WRER_64 |= highBitMask;
    }
    else if (config->event == kWKPU_InterruptAndWakeUp)
    {
        base->IRER |= lowBitMask;
        base->IRER_64 |= highBitMask;

        base->WRER |= lowBitMask;
        base->WRER_64 |= highBitMask;
    }

    if (config->edge == kWKPU_PinRisingEdge)
    {
        base->WIREER |= lowBitMask;
        base->WIREER_64 |= highBitMask;
    }
    else if (config->edge == kWKPU_PinFallingEdge)
    {
        base->WIFEER |= lowBitMask;
        base->WIFEER_64 |= highBitMask;
    }
    else if (config->edge == kWKPU_PinAnyEdge)
    {
        base->WIREER |= lowBitMask;
        base->WIREER_64 |= highBitMask;
        base->WIFEER |= lowBitMask;
        base->WIFEER_64 |= highBitMask;
    }

    if (config->enableFilter)
    {
        base->WIFER |= lowBitMask;
        base->WIFER_64 |= highBitMask;
    }
}

/*!
 * brief Disable and clear external wakeup source settings.
 *
 * param base         WKPU peripheral base address.
 * param mask         The wake up source to used. This is a logical OR of members of the enumeration ::wkpu_source_t
 */
void WKPU_ClearExternalWakeupSourceConfig(WKPU_Type *base, uint64_t mask)
{
    uint32_t lowBitMask  = (uint32_t)(uint64_t)(mask & 0xFFFFFFFF);
    uint32_t highBitMask = (uint32_t)(uint64_t)(mask >> 32);

    /* Clear wakeup and interrupt flags */
    base->WISR    = 0xFFFFFFFF;
    base->WISR_64 = 0xFFFFFFFF;

    base->IRER &= ~lowBitMask;
    base->IRER_64 &= ~highBitMask;

    base->WRER &= ~lowBitMask;
    base->WRER_64 &= ~highBitMask;

    base->WIREER &= ~lowBitMask;
    base->WIREER_64 &= ~highBitMask;

    base->WIFEER &= ~lowBitMask;
    base->WIFEER_64 &= ~highBitMask;

    base->WIFER &= ~lowBitMask;
    base->WIFER_64 &= ~highBitMask;
}

/*!
 * brief Fills in the NMI wake up source config struct with the default settings.
 *
 * The default values are as follows.
 * code
 *    config->edge                       = kWKPU_PinRisingEdge;
 *    config->enableFilter               = true;
 *    config->enableWakeup               = true;
 *    config->lockRegister               = false;
 * endcode
 *
 * param config Pointer to the user defined WKPU configuration structure.
 */
void WKPU_GetDefaultNMIWakeUpConfig(wkpu_nmi_wakeup_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->edge         = kWKPU_PinRisingEdge;
    config->enableFilter = true;
    config->enableWakeup = true;
    config->lockRegister = false;
}

/*!
 * brief Config NMI event as the wake up soures.
 *
 * This function configs the NMI as wake up source.
 *
 * param base      WKPU peripheral base address.
 * param config    Pointer to wkpu_external_wakeup_source_config_t structure.
 */
void WKPU_SetNMIWakeupConfig(WKPU_Type *base, const wkpu_nmi_wakeup_config_t *config)
{
    assert(config != NULL);
    /* Disabling both rising and falling edge disables the NMI functionality completely */
    assert(config->edge != kWKPU_PinDisable);
    /* The NCR register shall not be locked  */
    assert((base->NCR & (uint32_t)WKPU_NCR_NLOCK0_MASK) == 0U);

    uint32_t reg = 0;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(kCLOCK_Wkup);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    if (config->edge == kWKPU_PinRisingEdge)
    {
        reg |= (uint32_t)WKPU_NCR_NREE0_MASK;
    }
    else if (config->edge == kWKPU_PinFallingEdge)
    {
        reg |= (uint32_t)WKPU_NCR_NFEE0_MASK;
    }
    else if (config->edge == kWKPU_PinAnyEdge)
    {
        reg |= (uint32_t)WKPU_NCR_NREE0_MASK;
        reg |= (uint32_t)WKPU_NCR_NFEE0_MASK;
    }

    if (config->enableFilter)
    {
        reg |= (uint32_t)WKPU_NCR_NFE0_MASK;
    }

    if (config->enableWakeup)
    {
        reg |= (uint32_t)WKPU_NCR_NWRE0_MASK;
    }

    base->NCR = reg;

    if (config->lockRegister)
    {
        base->NCR |= (uint32_t)WKPU_NCR_NLOCK0_MASK;
    }
}

/*!
 * brief Disable and clear NMI settings.
 *
 * param base WKPU peripheral base address.
 */
void WKPU_ClearNMIWakeupConfig(WKPU_Type *base)
{
    base->NCR = 0;
}

/*!
 * brief Register callback.
 *
 * param cb_func   callback function
 */
void WKPU_RegisterCallBack(wkpu_callback_t cb_func)
{
    s_WkpuCallback = cb_func;
}

void WKPU_DriverIRQHandler(void);

void WKPU_DriverIRQHandler(void)
{
    register uint64_t wakeup_interrupt_flag = 0U;
    wakeup_interrupt_flag                   = WKPU_GetExternalWakeUpSourceFlag(WKPU);
    WKPU_ClearExternalWakeUpSourceFlag(WKPU, wakeup_interrupt_flag);
    if (s_WkpuCallback != NULL)
    {
        s_WkpuCallback(wakeup_interrupt_flag);
    }
    SDK_ISR_EXIT_BARRIER;
}
