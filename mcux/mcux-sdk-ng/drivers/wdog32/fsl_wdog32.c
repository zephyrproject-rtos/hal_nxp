/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_wdog32.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.wdog32"
#endif

#if defined(WDOG_RSTS)
#define WDOG_RESETS_ARRAY WDOG_RSTS
#endif

/*
 * $Coverage Justification Reference$
 *
 * $Justification wdog32_c_ref_1$
 * Function not covered. Test unfeasible, the reset state is too short to catch.
 *
 */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if defined(WDOG_RESETS_ARRAY)
/*!
 * @brief Get instance number for WDOG32_ module.
 *
 * @param base WDOG32_ peripheral base address.
 */
static uint32_t WDOG32_GetInstance(WDOG_Type *base);
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(WDOG_RESETS_ARRAY)
static WDOG_Type *const s_wdogBases[] = WDOG_BASE_PTRS;

/* Reset array */
static const reset_ip_name_t s_wdogResets[] = WDOG_RESETS_ARRAY;
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(WDOG_RESETS_ARRAY)
static uint32_t WDOG32_GetInstance(WDOG_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_wdogBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_wdogBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_wdogBases));

    return instance;
}
#endif

void WDOG32_ClearStatusFlags(WDOG_Type *base, uint32_t mask)
{
    
    /* $Line Coverage Justification$ $ref wdog32_c_ref_1$. */
    /* $Branch Coverage Justification$ $ref wdog32_c_ref_1$. */
    if (0U != (mask & (uint32_t)kWDOG32_InterruptFlag))
    {
        base->CS |= WDOG_CS_FLG_MASK;
    }
}

/*!
 * brief Initializes the WDOG32 configuration structure.
 *
 * This function initializes the WDOG32 configuration structure to default values. The default
 * values are:
 * code
 *   wdog32Config->enableWdog32 = true;
 *   wdog32Config->clockSource = kWDOG32_ClockSource1;
 *   wdog32Config->prescaler = kWDOG32_ClockPrescalerDivide1;
 *   wdog32Config->workMode.enableWait = true;
 *   wdog32Config->workMode.enableStop = false;
 *   wdog32Config->workMode.enableDebug = false;
 *   wdog32Config->testMode = kWDOG32_TestModeDisabled;
 *   wdog32Config->enableUpdate = true;
 *   wdog32Config->enableInterrupt = false;
 *   wdog32Config->enableWindowMode = false;
 *   wdog32Config->windowValue = 0U;
 *   wdog32Config->timeoutValue = 0xFFFFU;
 * endcode
 *
 * param config Pointer to the WDOG32 configuration structure.
 * see wdog32_config_t
 */
void WDOG32_GetDefaultConfig(wdog32_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableWdog32         = true;
    config->clockSource          = kWDOG32_ClockSource1;
    config->prescaler            = kWDOG32_ClockPrescalerDivide1;
    config->workMode.enableWait  = true;
    config->workMode.enableStop  = false;
    config->workMode.enableDebug = false;
    config->testMode             = kWDOG32_TestModeDisabled;
    config->enableUpdate         = true;
    config->enableInterrupt      = false;
    config->enableWindowMode     = false;
    config->windowValue          = 0U;
    config->timeoutValue         = 0xFFFFU;
}

/*!
 * brief Initializes the WDOG32 module.
 *
 * This function initializes the WDOG32.
 * To reconfigure the WDOG32 without forcing a reset first, enableUpdate must be set to true
 * in the configuration.
 *
 * Example:
 * code
 *   wdog32_config_t config;
 *   WDOG32_GetDefaultConfig(&config);
 *   config.timeoutValue = 0x7ffU;
 *   config.enableUpdate = true;
 *   WDOG32_Init(wdog_base,&config);
 * endcode
 *
 * note If there is errata ERR010536 (FSL_FEATURE_WDOG_HAS_ERRATA_010536 defined as 1),
 * then after calling this function, user need delay at least 4 LPO clock cycles before
 * accessing other WDOG32 registers.
 *
 * param base   WDOG32 peripheral base address.
 * param config The configuration of the WDOG32.
 *
 * retval kStatus_Success The initialization was successful
 * retval kStatus_Timeout The initialization timed out
 */
status_t WDOG32_Init(WDOG_Type *base, const wdog32_config_t *config)
{
    assert(NULL != config);

    register uint32_t value                   = 0U;
    uint32_t primaskValue                     = 0U;
    register WDOG_Type *regBase               = base;
    register const wdog32_config_t *regConfig = config;
    uint32_t tempPrescaler                    = (uint32_t)regConfig->prescaler;
    status_t status                           = kStatus_Success;

#if defined(WDOG_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_wdogResets[WDOG32_GetInstance(base)]);
#endif

    value = WDOG_CS_EN((uint32_t)(regConfig->enableWdog32 ? 1: 0)) | WDOG_CS_CLK((uint32_t)regConfig->clockSource) |
            WDOG_CS_INT((uint32_t)(regConfig->enableInterrupt ? 1 : 0)) | WDOG_CS_WIN((uint32_t)(regConfig->enableWindowMode ? 1 : 0)) |
            WDOG_CS_UPDATE((uint32_t)(regConfig->enableUpdate ? 1 : 0)) | WDOG_CS_DBG((uint32_t)(regConfig->workMode.enableDebug ? 1 : 0)) |
            WDOG_CS_STOP((uint32_t)(regConfig->workMode.enableStop ? 1 : 0)) |
            WDOG_CS_WAIT((uint32_t)(regConfig->workMode.enableWait ? 1 : 0)) | WDOG_CS_PRES(tempPrescaler) |
            WDOG_CS_CMD32EN(1UL) | WDOG_CS_TST((uint32_t)regConfig->testMode);

    /* Disable the global interrupts. Otherwise, an interrupt could effectively invalidate the unlock sequence
     * and the WCT may expire. After the configuration finishes, re-enable the global interrupts. */
    primaskValue = DisableGlobalIRQ();
    status = WDOG32_Unlock(base);
    regBase->WIN   = regConfig->windowValue;
    regBase->TOVAL = regConfig->timeoutValue;
    regBase->CS    = value;
#ifdef WDOG_CS_RCS_MASK
#if WDOG32_RECONFIG_TIMEOUT
    uint32_t timeout = WDOG32_RECONFIG_TIMEOUT;
#endif /* WDOG32_RECONFIG_TIMEOUT */
    /* Waits until for new configuration to take effect. */
    while (0U == ((base->CS) & WDOG_CS_RCS_MASK))
    {
#if WDOG32_RECONFIG_TIMEOUT
        if ((--timeout) == 0U)
        {
            status = kStatus_Timeout; /* Reconfiguration timeout */
            break;
        }
#endif /* WDOG32_RECONFIG_TIMEOUT */
    }
#else
    /* When switches clock sources during reconfiguration, the watchdog hardware holds the counter at
       zero for 2.5 periods of the previous clock source and 2.5 periods of the new clock source
       after the configuration time period (128 bus clocks) ends.
       This delay ensures a smooth transition before restarting the counter with the new configuration. */
    for (uint8_t timeDelay = 0U; timeDelay < 128U; timeDelay++)
    {
        (void)base->CNT;
    }
#endif /* WDOG_CS_RCS_MASK */

    EnableGlobalIRQ(primaskValue);

    return status;
}

/*!
 * brief De-initializes the WDOG32 module.
 *
 * This function shuts down the WDOG32.
 * Ensure that the WDOG_CS.UPDATE is 1, which means that the register update is enabled.
 *
 * param base   WDOG32 peripheral base address.
 *
 * retval kStatus_Success The de-initialization was successful
 * retval kStatus_Timeout The de-initialization timed out
 */
status_t WDOG32_Deinit(WDOG_Type *base)
{
    uint32_t primaskValue = 0U;
    status_t status = kStatus_Success;

    /* Disable the global interrupts */
    primaskValue = DisableGlobalIRQ();
    status = WDOG32_Unlock(base);
    WDOG32_Disable(base);
    EnableGlobalIRQ(primaskValue);

    return status;
}

/*!
 * brief Unlocks the WDOG32 register written.
 *
 * This function unlocks the WDOG32 register written.
 *
 * Before starting the unlock sequence and following the configuration, disable the global interrupts.
 * Otherwise, an interrupt could effectively invalidate the unlock sequence and the WCT may expire.
 * After the configuration finishes, re-enable the global interrupts.
 *
 * param base WDOG32 peripheral base address
 * 
 * retval kStatus_Success The unlock sequence was successful
 * retval kStatus_Timeout The unlock sequence timed out
 */
status_t WDOG32_Unlock(WDOG_Type *base)
{
    if (0U != ((base->CS) & WDOG_CS_CMD32EN_MASK))
    {
        base->CNT = WDOG_UPDATE_KEY;
    }
    else
    {
        base->CNT = WDOG_FIRST_WORD_OF_UNLOCK;
        base->CNT = WDOG_SECOND_WORD_OF_UNLOCK;
    }
#ifdef WDOG_CS_ULK_MASK
#if WDOG32_UNLOCK_TIMEOUT
    uint32_t timeout = WDOG32_UNLOCK_TIMEOUT;
#endif /* WDOG32_UNLOCK_TIMEOUT */
    /* Waited until for registers to be unlocked. */
    while (0U == ((base->CS) & WDOG_CS_ULK_MASK))
    {
#if WDOG32_UNLOCK_TIMEOUT
        if ((--timeout) == 0U)
        {
            return kStatus_Timeout; /* Unlock sequence timeout */
        }
#endif /* WDOG32_UNLOCK_TIMEOUT */
    }
#endif /* WDOG_CS_ULK_MASK */
    return kStatus_Success;
}

/*!
 * brief Enables the WDOG32 module.
 *
 * This function writes a value into the WDOG_CS register to enable the WDOG32.
 * The WDOG_CS register is a write-once register. Please check the enableUpdate is set to true for calling WDOG32_Init
 * to do wdog initialize, before call the re-configuration APIs, ensure that the WCT window is still open and
 * this register has not been written in this WCT while the function is called.
 *
 * param base WDOG32 peripheral base address.
 */
void WDOG32_Enable(WDOG_Type *base)
{
    base->CS |= WDOG_CS_EN_MASK;
}

/*!
 * brief Disables the WDOG32 module.
 *
 * This function writes a value into the WDOG_CS register to disable the WDOG32.
 * The WDOG_CS register is a write-once register. Please check the enableUpdate is set to true for calling WDOG32_Init
 * to do wdog initialize, before call the re-configuration APIs, ensure that the WCT window is still open and
 * this register has not been written in this WCT while the function is called.
 *
 * param base WDOG32 peripheral base address
 */
void WDOG32_Disable(WDOG_Type *base)
{
    base->CS &= ~WDOG_CS_EN_MASK;
}

/*!
 * brief Enables the WDOG32 interrupt.
 *
 * This function writes a value into the WDOG_CS register to enable the WDOG32 interrupt.
 * The WDOG_CS register is a write-once register. Please check the enableUpdate is set to true for calling WDOG32_Init
 * to do wdog initialize, before call the re-configuration APIs, ensure that the WCT window is still open and
 * this register has not been written in this WCT while the function is called.
 *
 * param base WDOG32 peripheral base address.
 * param mask The interrupts to enable.
 *        The parameter can be a combination of the following source if defined:
 *        arg kWDOG32_InterruptEnable
 */
void WDOG32_EnableInterrupts(WDOG_Type *base, uint32_t mask)
{
    base->CS |= mask;
}

/*!
 * brief Disables the WDOG32 interrupt.
 *
 * This function writes a value into the WDOG_CS register to disable the WDOG32 interrupt.
 * The WDOG_CS register is a write-once register. Please check the enableUpdate is set to true for calling WDOG32_Init
 * to do wdog initialize, before call the re-configuration APIs, ensure that the WCT window is still open and
 * this register has not been written in this WCT while the function is called.
 *
 * param base WDOG32 peripheral base address.
 * param mask The interrupts to disabled.
 *        The parameter can be a combination of the following source if defined:
 *        arg kWDOG32_InterruptEnable
 */
void WDOG32_DisableInterrupts(WDOG_Type *base, uint32_t mask)
{
    base->CS &= ~mask;
}

/*!
 * brief Sets the WDOG32 timeout value.
 *
 * This function writes a timeout value into the WDOG_TOVAL register.
 * The WDOG_TOVAL register is a write-once register. To ensure the reconfiguration fits the timing of WCT, unlock
 * function will be called in the function.
 *
 * param base WDOG32 peripheral base address
 * param timeoutCount WDOG32 timeout value, count of WDOG32 clock ticks.
 */
void WDOG32_SetTimeoutValue(WDOG_Type *base, uint16_t timeoutCount)
{
    base->TOVAL = timeoutCount;
}

/*!
 * brief Sets the WDOG32 window value.
 *
 * This function writes a window value into the WDOG_WIN register.
 * The WDOG_WIN register is a write-once register. Ensure that the WCT window is still open and
 * this register has not been written in this WCT while the function is called.
 *
 * param base WDOG32 peripheral base address.
 * param windowValue WDOG32 window value.
 */
void WDOG32_SetWindowValue(WDOG_Type *base, uint16_t windowValue)
{
    base->WIN = windowValue;
}
