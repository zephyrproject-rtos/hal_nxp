/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_vbatcon.h"
#include "PERI_VBATCON.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.vbatcon"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief CTRL reset value (per RM Chapter 105: 0x0100_0000 -> LONG_PRESS_EN=1). */
#define VBATCON_CTRL_RESET_VALUE (VBATCON_CTRL_LONG_PRESS_EN_MASK)

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Populate a configuration structure with hardware reset defaults.
 *
 * @param config  Pointer to configuration to fill.
 */
void VBATCON_GetDefaultConfig(vbatcon_config_t *config)
{
    assert(config != NULL);

    /* CTRL = 0x0100_0000 */
    config->buttonTimeout        = kVBATCON_BtnTimeout5s;
    config->debounceTime         = kVBATCON_Debounce50ms;
    config->turnOnTime           = kVBATCON_TurnOnTime500ms;
    config->noAckTime            = kVBATCON_NoAckTime1000ms;
    config->enableLongPress      = true;
    config->enableAbnormalCheck  = false;

    /* CLOCK_CTRL = 0 */
    config->enableBBSMClockGate  = false;
    config->enableLPTMRClockGate = false;
    config->enableUlp32kSwitch   = false;
    config->ulp32kSource         = kVBATCON_Ulp32kSourceFro32k;

    /* EVENTS = 0 */
    config->interruptEnable      = 0U;
}

/*!
 * @brief Initialize the entire VBATCON module from a configuration.
 *
 * @param base    VBATCON peripheral base.
 * @param config  Pointer to configuration.
 */
void VBATCON_Init(VBATCON_Type *base, const vbatcon_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    base->CTRL = VBATCON_CTRL_BTN_TIMEOUT((uint32_t)config->buttonTimeout) |
                 VBATCON_CTRL_DEBOUNCE((uint32_t)config->debounceTime)     |
                 VBATCON_CTRL_TURN_ON_TIME((uint32_t)config->turnOnTime)   |
                 VBATCON_CTRL_NAT((uint32_t)config->noAckTime)             |
                 VBATCON_CTRL_LONG_PRESS_EN(config->enableLongPress ? 1U : 0U) |
                 VBATCON_CTRL_AEC(config->enableAbnormalCheck ? 1U : 0U);

    base->CLOCK_CTRL =
        VBATCON_CLOCK_CTRL_BBSM_CG_EN(config->enableBBSMClockGate ? 1U : 0U)        |
        VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN(config->enableLPTMRClockGate ? 1U : 0U) |
        VBATCON_CLOCK_CTRL_SW_SEL_EN(config->enableUlp32kSwitch ? 1U : 0U)          |
        VBATCON_CLOCK_CTRL_SW_SEL((uint32_t)config->ulp32kSource);

    /* Set initial interrupt enables and clear all pending W1C status bits. */
    base->EVENTS = (config->interruptEnable & (uint32_t)kVBATCON_IrqAll) |
                   (uint32_t)kVBATCON_EventAll;
}

/*!
 * @brief Reset VBATCON CTRL/CLOCK_CTRL/EVENTS to their hardware defaults.
 *
 * @param base  VBATCON peripheral base.
 */
void VBATCON_Deinit(VBATCON_Type *base)
{
    assert(base != NULL);

    base->CTRL       = VBATCON_CTRL_RESET_VALUE;
    base->CLOCK_CTRL = 0U;
    /* Disable all interrupts and W1C all pending status. */
    base->EVENTS     = (uint32_t)kVBATCON_EventAll;
}

/*!
 * @brief Set the long button-press timeout.
 *
 * @param base     VBATCON peripheral base.
 * @param timeout  Selected timeout.
 */
void VBATCON_SetButtonTimeout(VBATCON_Type *base, vbatcon_btn_timeout_t timeout)
{
    base->CTRL = (base->CTRL & ~VBATCON_CTRL_BTN_TIMEOUT_MASK) | VBATCON_CTRL_BTN_TIMEOUT((uint32_t)timeout);
}

/*!
 * @brief Set the button debounce time.
 *
 * @param base       VBATCON peripheral base.
 * @param debounce   Selected debounce.
 */
void VBATCON_SetDebounceTime(VBATCON_Type *base, vbatcon_debounce_t debounce)
{
    base->CTRL = (base->CTRL & ~VBATCON_CTRL_DEBOUNCE_MASK) | VBATCON_CTRL_DEBOUNCE((uint32_t)debounce);
}

/*!
 * @brief Set the turn-on time (press duration before pmic_mode asserts).
 *
 * @param base   VBATCON peripheral base.
 * @param time   Selected turn-on time.
 */
void VBATCON_SetTurnOnTime(VBATCON_Type *base, vbatcon_turn_on_time_t time)
{
    base->CTRL = (base->CTRL & ~VBATCON_CTRL_TURN_ON_TIME_MASK) | VBATCON_CTRL_TURN_ON_TIME((uint32_t)time);
}

/*!
 * @brief Set the PMU no-acknowledge timeout for DPD entry.
 *
 * @param base   VBATCON peripheral base.
 * @param time   Selected no-ACK time.
 */
void VBATCON_SetNoAckTime(VBATCON_Type *base, vbatcon_no_ack_time_t time)
{
    base->CTRL = (base->CTRL & ~VBATCON_CTRL_NAT_MASK) | VBATCON_CTRL_NAT((uint32_t)time);
}

/*!
 * @brief Enable or disable long-press power-on/off.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void VBATCON_EnableLongPress(VBATCON_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= VBATCON_CTRL_LONG_PRESS_EN_MASK;
    }
    else
    {
        base->CTRL &= ~VBATCON_CTRL_LONG_PRESS_EN_MASK;
    }
}

/*!
 * @brief Enable or disable abnormal-entry deadlock protection.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void VBATCON_EnableAbnormalEntryCheck(VBATCON_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= VBATCON_CTRL_AEC_MASK;
    }
    else
    {
        base->CTRL &= ~VBATCON_CTRL_AEC_MASK;
    }
}

/*!
 * @brief Clear event flags (write-1-to-clear).
 *
 * Only the lower 8 status bits are W1C; enable bits are preserved by
 * masking them out of the write so they are not modified.
 *
 * @param base  VBATCON peripheral base.
 * @param mask  Mask of event flags to clear.
 */
void VBATCON_ClearEventFlags(VBATCON_Type *base, uint32_t mask)
{
    /* Read-modify-write that preserves enable bits and writes 1 only to
     * the W1C status bits selected by mask. */
    uint32_t enableBits = base->EVENTS & (uint32_t)kVBATCON_IrqAll;
    base->EVENTS        = enableBits | (mask & (uint32_t)kVBATCON_EventAll);
}

/*!
 * @brief Enable or disable the BBSM functional-clock gate.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void VBATCON_EnableBBSMClockGate(VBATCON_Type *base, bool enable)
{
    if (enable)
    {
        base->CLOCK_CTRL |= VBATCON_CLOCK_CTRL_BBSM_CG_EN_MASK;
    }
    else
    {
        base->CLOCK_CTRL &= ~VBATCON_CLOCK_CTRL_BBSM_CG_EN_MASK;
    }
}

/*!
 * @brief Enable or disable the VBAT_LPTIMER functional-clock gate.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void VBATCON_EnableLPTMRClockGate(VBATCON_Type *base, bool enable)
{
    if (enable)
    {
        base->CLOCK_CTRL |= VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN_MASK;
    }
    else
    {
        base->CLOCK_CTRL &= ~VBATCON_CLOCK_CTRL_VBAT_LPTMR_CG_EN_MASK;
    }
}

/*!
 * @brief Enable or disable software override of the ULP32K source.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: software-controlled; false: hardware default.
 */
void VBATCON_EnableUlp32kSwitch(VBATCON_Type *base, bool enable)
{
    if (enable)
    {
        base->CLOCK_CTRL |= VBATCON_CLOCK_CTRL_SW_SEL_EN_MASK;
    }
    else
    {
        base->CLOCK_CTRL &= ~VBATCON_CLOCK_CTRL_SW_SEL_EN_MASK;
    }
}

/*!
 * @brief Select the ULP32K clock source.
 *
 * @param base    VBATCON peripheral base.
 * @param source  Source selection.
 */
void VBATCON_SelectUlp32kSource(VBATCON_Type *base, vbatcon_ulp32k_source_t source)
{
    base->CLOCK_CTRL = (base->CLOCK_CTRL & ~VBATCON_CLOCK_CTRL_SW_SEL_MASK) |
                       VBATCON_CLOCK_CTRL_SW_SEL((uint32_t)source);
}

/*!
 * @brief Switch the ULP32K clock source with readiness polling.
 *
 * @param base     VBATCON peripheral base.
 * @param source   Target clock source.
 * @param timeout  Maximum number of polling iterations (0 = no wait).
 */
status_t VBATCON_SwitchUlp32kSource(VBATCON_Type *base, vbatcon_ulp32k_source_t source, uint32_t timeout)
{
    assert(base != NULL);

    uint32_t readyMask = (source == kVBATCON_Ulp32kSourceOsc32k)
                             ? VBATCON_CLOCK_CTRL_OSC_RDY_MASK
                             : VBATCON_CLOCK_CTRL_FRO_RDY_MASK;

    while ((base->CLOCK_CTRL & readyMask) == 0U)
    {
        if (timeout == 0U)
        {
            return kStatus_Timeout;
        }
        --timeout;
    }

    /* Commit SW_SEL_EN and SW_SEL in one write; preserve other CLOCK_CTRL bits. */
    base->CLOCK_CTRL = (base->CLOCK_CTRL & ~VBATCON_CLOCK_CTRL_SW_SEL_MASK) |
                       VBATCON_CLOCK_CTRL_SW_SEL_EN_MASK                    |
                       VBATCON_CLOCK_CTRL_SW_SEL((uint32_t)source);

    return kStatus_Success;
}
