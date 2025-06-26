/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_ewm.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_ewm"
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map EDMA instance number to clock name. */
static const clock_ip_name_t s_ewmClockName[] = EWM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initializes the EWM peripheral.
 *
 * This function is used to initialize the EWM. After calling, the EWM
 * runs immediately according to the configuration.
 * Note that, except for the interrupt enable control bit, other control bits and registers are write once after a
 * CPU reset. Modifying them more than once generates a bus transfer error.
 *
 * This is an example.
 * code
 *   ewm_config_t config;
 *   EWM_GetDefaultConfig(&config);
 *   config.compareHighValue = 0xAAU;
 *   EWM_Init(ewm_base,&config);
 * endcode
 *
 * param base EWM peripheral base address
 * param psConfig The configuration of the EWM
 */
void EWM_Init(EWM_Type *base, const ewm_config_t *psConfig)
{
    assert(psConfig != NULL);

    uint16_t value = 0U;

#if !((defined(FSL_FEATURE_SOC_PCC_COUNT) && FSL_FEATURE_SOC_PCC_COUNT) && \
      (defined(FSL_FEATURE_PCC_SUPPORT_EWM_CLOCK_REMOVE) && FSL_FEATURE_PCC_SUPPORT_EWM_CLOCK_REMOVE))
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_ewmClockName[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#endif
    value = EWM_CTRL_EWMEN(psConfig->bEnableEWM) | EWM_CTRL_ASSIN((uint8_t)psConfig->eInputAssertState) |
            EWM_CTRL_INEN(psConfig->bEnableEWMInput) | EWM_CTRL_INTEN(psConfig->bEnableInterrupt);
#if defined(FSL_FEATURE_EWM_HAS_PRESCALER) && FSL_FEATURE_EWM_HAS_PRESCALER
    base->CLKPRESCALER = psConfig->u8ClockDivder;
#endif /* FSL_FEATURE_EWM_HAS_PRESCALER */

#if defined(FSL_FEATURE_EWM_HAS_CLOCK_SELECT) && FSL_FEATURE_EWM_HAS_CLOCK_SELECT
    base->CLKCTRL = (uint16_t)psConfig->eClockSource;
#endif /* FSL_FEATURE_EWM_HAS_CLOCK_SELECT*/

    base->CMPL = psConfig->u8CompareLowValue;
    base->CMPH = psConfig->u8CompareHighValue;
    base->CTRL = value;
}

/*!
 * brief Deinitializes the EWM peripheral.
 *
 * This function is used to shut down the EWM.
 *
 * param base EWM peripheral base address
 */
void EWM_Deinit(EWM_Type *base)
{
    EWM_DisableInterrupt(base);
#if !((defined(FSL_FEATURE_SOC_PCC_COUNT) && FSL_FEATURE_SOC_PCC_COUNT) && \
      (defined(FSL_FEATURE_PCC_SUPPORT_EWM_CLOCK_REMOVE) && FSL_FEATURE_PCC_SUPPORT_EWM_CLOCK_REMOVE))
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_ewmClockName[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#endif /* FSL_FEATURE_PCC_SUPPORT_EWM_CLOCK_REMOVE */
}

/*!
 * brief Initializes the EWM configuration structure.
 *
 * This function initializes the EWM configuration structure to default values. The default
 * values are as follows.
 * code
 *   ewmConfig->bEnableEWM = true;
 *   ewmConfig->bEnableEWMInput = false;
 *   ewmConfig->eSetInputAssertState = kEWM_EwmInZeroAssert;
 *   ewmConfig->bEnableInterrupt = false;
 *   ewmConfig->eClockSource = kEWM_LpoClockSource0;
 *   ewmConfig->u8ClockDivder = 0;
 *   ewmConfig->u8CompareLowValue = 0;
 *   ewmConfig->u8CompareHighValue = 0xFEU;
 * endcode
 *
 * param psConfig Pointer to the EWM configuration structure.
 * see ewm_config_t
 */
void EWM_GetDefaultConfig(ewm_config_t *psConfig)
{
    assert(psConfig != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->bEnableEWM        = 1U;
    psConfig->bEnableEWMInput   = 0U;
    psConfig->eInputAssertState = kEWM_EwmInZeroAssert;
    psConfig->bEnableInterrupt  = 0U;
#if defined(FSL_FEATURE_EWM_HAS_CLOCK_SELECT) && FSL_FEATURE_EWM_HAS_CLOCK_SELECT
    psConfig->eClockSource = kEWM_LpoClockSource0;
#endif /* FSL_FEATURE_EWM_HAS_CLOCK_SELECT*/
#if defined(FSL_FEATURE_EWM_HAS_PRESCALER) && FSL_FEATURE_EWM_HAS_PRESCALER
    psConfig->u8ClockDivder = 0U;
#endif /* FSL_FEATURE_EWM_HAS_PRESCALER */
    psConfig->u8CompareLowValue  = 0U;
    psConfig->u8CompareHighValue = 0xFEU;
}

/*!
 * brief Services the EWM.
 *
 * This function resets the EWM counter to zero.
 *
 * param base EWM peripheral base address
 */
void EWM_Refresh(EWM_Type *base)
{
    uint32_t u32PrimaskValue = 0U;

    /* Disable the global interrupt to protect refresh sequence */
    u32PrimaskValue = DisableGlobalIRQ();
    base->SERV      = (uint16_t)0xB4U;
    base->SERV      = (uint16_t)0x2CU;
    EnableGlobalIRQ(u32PrimaskValue);
}
