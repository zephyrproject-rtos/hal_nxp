/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_VBATCON_H_
#define _FSL_VBATCON_H_

#include "fsl_common.h"

/*!
 * @addtogroup vbatcon
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief VBATCON driver version 1.0.0. */
#define FSL_VBATCON_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*!
 * @brief VBATCON button-press timeout selection.
 *
 * Selects how long the on/off button must be held to request a power-down.
 * Maps to CTRL[BTN_TIMEOUT].
 */
typedef enum _vbatcon_btn_timeout
{
    kVBATCON_BtnTimeout5s       = 0U, /*!< 5 seconds. */
    kVBATCON_BtnTimeout10s      = 1U, /*!< 10 seconds. */
    kVBATCON_BtnTimeout15s      = 2U, /*!< 15 seconds. */
    kVBATCON_BtnTimeoutDisabled = 3U, /*!< Timeout disabled; long button presses do not trigger a power-down. */
} vbatcon_btn_timeout_t;

/*!
 * @brief VBATCON button debounce time selection.
 *
 * Maps to CTRL[DEBOUNCE]. Values are in milliseconds.
 */
typedef enum _vbatcon_debounce
{
    kVBATCON_Debounce50ms  = 0U, /*!< 50 ms debounce. */
    kVBATCON_Debounce100ms = 1U, /*!< 100 ms debounce. */
    kVBATCON_Debounce500ms = 2U, /*!< 500 ms debounce. */
    kVBATCON_Debounce0ms   = 3U, /*!< 0 ms (no debounce). */
} vbatcon_debounce_t;

/*!
 * @brief VBATCON turn-on time selection.
 *
 * Time the button must be pressed before pmic_mode is asserted.
 * Maps to CTRL[TURN_ON_TIME]. Values are in milliseconds unless noted.
 */
typedef enum _vbatcon_turn_on_time
{
    kVBATCON_TurnOnTime500ms = 0U, /*!< 500 ms turn-on time. */
    kVBATCON_TurnOnTime50ms  = 1U, /*!< 50 ms turn-on time. */
    kVBATCON_TurnOnTime100ms = 2U, /*!< 100 ms turn-on time. */
    kVBATCON_TurnOnTime0ms   = 3U, /*!< 0 ms; requires already in DPD and press > 50 us. */
} vbatcon_turn_on_time_t;

/*!
 * @brief VBATCON PMU no-ACK timeout selection.
 *
 * Timeout (in ms) after the system requests deep-power-down.
 * Maps to CTRL[NAT].
 */
typedef enum _vbatcon_no_ack_time
{
    kVBATCON_NoAckTime1000ms = 0U, /*!< 1000 ms PMU no-ACK timeout. */
    kVBATCON_NoAckTime500ms  = 1U, /*!< 500 ms PMU no-ACK timeout. */
} vbatcon_no_ack_time_t;

/*!
 * @brief VBATCON ULP32K clock source.
 *
 * Maps to CLOCK_CTRL[SW_SEL].
 */
typedef enum _vbatcon_ulp32k_source
{
    kVBATCON_Ulp32kSourceFro32k = 0U, /*!< FRO32K is selected as ULP32K clock source. */
    kVBATCON_Ulp32kSourceOsc32k = 1U, /*!< OSC32K is selected as ULP32K clock source. */
} vbatcon_ulp32k_source_t;

/*!
 * @brief VBATCON event/interrupt flags.
 *
 * These flags can be used as a mask for the event-flag and interrupt-enable APIs.
 * They live in the lower 8 bits of the EVENTS register (status, write-1-to-clear).
 */
enum _vbatcon_event_flags
{
    kVBATCON_EventEmergencyOff = VBATCON_EVENTS_EMG_OFF_MASK,  /*!< Emergency power-off requested. */
    kVBATCON_EventPowerOff     = VBATCON_EVENTS_PWR_OFF_MASK,  /*!< Power-off interrupt requested. */
    kVBATCON_EventPowerOn      = VBATCON_EVENTS_PWR_ON_MASK,   /*!< Power-on interrupt requested. */
    kVBATCON_EventOscError     = VBATCON_EVENTS_OSC_ERROR_MASK,/*!< OSC32K error interrupt requested. */
    kVBATCON_EventAll          = VBATCON_EVENTS_EMG_OFF_MASK |
                                 VBATCON_EVENTS_PWR_OFF_MASK |
                                 VBATCON_EVENTS_PWR_ON_MASK  |
                                 VBATCON_EVENTS_OSC_ERROR_MASK, /*!< All event flags. */
};

/*!
 * @brief VBATCON interrupt-enable flags.
 *
 * These flags can be OR'ed and passed to VBATCON_EnableInterrupts /
 * VBATCON_DisableInterrupts. They live in bits [23:20] of the EVENTS register.
 */
enum _vbatcon_interrupt_enable
{
    kVBATCON_IrqEmergencyOff = VBATCON_EVENTS_EMG_OFF_EN_MASK,   /*!< Emergency power-off enable. */
    kVBATCON_IrqPowerOff     = VBATCON_EVENTS_PWR_OFF_EN_MASK,   /*!< Power-off interrupt enable. */
    kVBATCON_IrqPowerOn      = VBATCON_EVENTS_PWR_ON_EN_MASK,    /*!< Power-on interrupt enable. */
    kVBATCON_IrqOscError     = VBATCON_EVENTS_OSC_ERROR_EN_MASK, /*!< OSC32K error interrupt enable. */
    kVBATCON_IrqAll          = VBATCON_EVENTS_EMG_OFF_EN_MASK |
                               VBATCON_EVENTS_PWR_OFF_EN_MASK |
                               VBATCON_EVENTS_PWR_ON_EN_MASK  |
                               VBATCON_EVENTS_OSC_ERROR_EN_MASK, /*!< All interrupt sources. */
};

/*!
 * @brief VBATCON clock status flags (read-only from CLOCK_CTRL).
 */
enum _vbatcon_clock_status_flags
{
    kVBATCON_ClockStatusOscReady = VBATCON_CLOCK_CTRL_OSC_RDY_MASK, /*!< OSC32K is ready. */
    kVBATCON_ClockStatusFroReady = VBATCON_CLOCK_CTRL_FRO_RDY_MASK, /*!< FRO32K is ready. */
    kVBATCON_ClockStatusOscScxoStable = VBATCON_CLOCK_CTRL_OSS_MASK, /*!< OSC32K SCXO stable. */
    kVBATCON_ClockStatusOscTcxoStable = VBATCON_CLOCK_CTRL_OTS_MASK, /*!< OSC32K TCXO stable. */
};

/*!
 * @brief VBATCON configuration structure.
 *
 * Used by VBATCON_GetDefaultConfig and VBATCON_Init to bring the whole
 * module (CTRL, CLOCK_CTRL, EVENTS) to a known state in one call. GPRs
 * hold user data and are not touched by Init.
 */
typedef struct _vbatcon_config
{
    /* CTRL */
    vbatcon_btn_timeout_t  buttonTimeout;       /*!< Long-press timeout to request power-down. */
    vbatcon_debounce_t     debounceTime;        /*!< Button input debounce time. */
    vbatcon_turn_on_time_t turnOnTime;          /*!< Press duration before pmic_mode is asserted. */
    vbatcon_no_ack_time_t  noAckTime;           /*!< PMU no-ACK timeout for DPD entry. */
    bool                   enableLongPress;     /*!< true: enable long-press power-on/off. */
    bool                   enableAbnormalCheck; /*!< true: enable abnormal-entry deadlock protection. */

    /* CLOCK_CTRL */
    bool                   enableBBSMClockGate;  /*!< true: gate BBSM functional clock. */
    bool                   enableLPTMRClockGate; /*!< true: gate VBAT_LPTIMER functional clock. */
    bool                   enableUlp32kSwitch;   /*!< true: enable software override of ULP32K source. */
    vbatcon_ulp32k_source_t ulp32kSource;        /*!< ULP32K source (only effective when SW switch is enabled). */

    /* EVENTS */
    uint32_t               interruptEnable;     /*!< OR'ed ::_vbatcon_interrupt_enable mask. 0 = all disabled. */
} vbatcon_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and version
 * @{
 */

/*!
 * @brief Populate a configuration structure with hardware reset defaults.
 *
 * Mirrors the per-register reset values from RM Chapter 105:
 *   - CTRL          = 0x0100_0000 -> LONG_PRESS_EN = 1, AEC = 0,
 *                     BTN_TIMEOUT/DEBOUNCE/TURN_ON_TIME/NAT = 0
 *   - CLOCK_CTRL    = 0x0000_0000 -> all gates off, SW switch off
 *   - EVENTS        = 0x0000_0000 -> all interrupts disabled
 *
 * Resulting fields:
 *   - buttonTimeout        = kVBATCON_BtnTimeout5s
 *   - debounceTime         = kVBATCON_Debounce50ms
 *   - turnOnTime           = kVBATCON_TurnOnTime500ms
 *   - noAckTime            = kVBATCON_NoAckTime1000ms
 *   - enableLongPress      = true
 *   - enableAbnormalCheck  = false
 *   - enableBBSMClockGate  = false
 *   - enableLPTMRClockGate = false
 *   - enableUlp32kSwitch   = false
 *   - ulp32kSource         = kVBATCON_Ulp32kSourceFro32k
 *   - interruptEnable      = 0
 *
 * @param config  Pointer to configuration to fill; must not be NULL.
 */
void VBATCON_GetDefaultConfig(vbatcon_config_t *config);

/*!
 * @brief Initialize the entire VBATCON module from a configuration.
 *
 * Writes CTRL, CLOCK_CTRL, and EVENTS to the configured state in three
 * full-word writes. Any pending W1C event-status bits in EVENTS are
 * cleared. GPRs are left untouched (they retain user data across power
 * cycles).
 *
 * @param base    VBATCON peripheral base.
 * @param config  Pointer to configuration; must not be NULL.
 */
void VBATCON_Init(VBATCON_Type *base, const vbatcon_config_t *config);

/*!
 * @brief Reset VBATCON CTRL/CLOCK_CTRL/EVENTS to their hardware defaults.
 *
 * Restores CTRL to 0x0100_0000, CLOCK_CTRL to 0, and EVENTS to 0
 * (interrupts disabled, all pending status cleared via W1C). GPRs are
 * left untouched.
 *
 * @param base  VBATCON peripheral base.
 */
void VBATCON_Deinit(VBATCON_Type *base);

/*!
 * @brief Get the VBATCON version-ID register value.
 *
 * @param base  VBATCON peripheral base.
 * @return  Raw VERID value (VERSION | REVISION | IPID).
 */
static inline uint32_t VBATCON_GetVersionId(VBATCON_Type *base)
{
    return base->VERID;
}

/*!
 * @brief Get the size of the GPR array implemented by hardware.
 *
 * @param base  VBATCON peripheral base.
 * @return  Number of 32-bit GPR words (0 if not implemented).
 */
static inline uint32_t VBATCON_GetGprArraySize(VBATCON_Type *base)
{
    return (base->FEATURES & VBATCON_FEATURES_GPR_SZ_MASK) >> VBATCON_FEATURES_GPR_SZ_SHIFT;
}

/*! @} */

/*!
 * @name Control configuration
 * @{
 */

/*!
 * @brief Set the long button-press timeout.
 *
 * @param base     VBATCON peripheral base.
 * @param timeout  Selected timeout, see ::vbatcon_btn_timeout_t.
 */
void VBATCON_SetButtonTimeout(VBATCON_Type *base, vbatcon_btn_timeout_t timeout);

/*!
 * @brief Set the button debounce time.
 *
 * @param base       VBATCON peripheral base.
 * @param debounce   Selected debounce, see ::vbatcon_debounce_t.
 */
void VBATCON_SetDebounceTime(VBATCON_Type *base, vbatcon_debounce_t debounce);

/*!
 * @brief Set the turn-on time (press duration before pmic_mode asserts).
 *
 * @param base   VBATCON peripheral base.
 * @param time   Selected turn-on time, see ::vbatcon_turn_on_time_t.
 */
void VBATCON_SetTurnOnTime(VBATCON_Type *base, vbatcon_turn_on_time_t time);

/*!
 * @brief Set the PMU no-acknowledge timeout for DPD entry.
 *
 * @param base   VBATCON peripheral base.
 * @param time   Selected no-ACK time, see ::vbatcon_no_ack_time_t.
 */
void VBATCON_SetNoAckTime(VBATCON_Type *base, vbatcon_no_ack_time_t time);

/*!
 * @brief Enable or disable long-press power-on/off.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void VBATCON_EnableLongPress(VBATCON_Type *base, bool enable);

/*!
 * @brief Enable or disable abnormal-entry deadlock protection.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void VBATCON_EnableAbnormalEntryCheck(VBATCON_Type *base, bool enable);

/*! @} */

/*!
 * @name Events and interrupts
 * @{
 */

/*!
 * @brief Enable VBATCON interrupt sources.
 *
 * EVENTS[7:4] are W1C status bits; the implementation writes 0 to those
 * positions so a concurrently-pending event is not silently cleared.
 *
 * @param base  VBATCON peripheral base.
 * @param mask  OR'ed mask of ::_vbatcon_interrupt_enable values.
 */
static inline void VBATCON_EnableInterrupts(VBATCON_Type *base, uint32_t mask)
{
    uint32_t enables = base->EVENTS & (uint32_t)kVBATCON_IrqAll;
    enables |= (mask & (uint32_t)kVBATCON_IrqAll);
    base->EVENTS = enables;
}

/*!
 * @brief Disable VBATCON interrupt sources.
 *
 * EVENTS[7:4] are W1C status bits; the implementation writes 0 to those
 * positions so a concurrently-pending event is not silently cleared.
 *
 * @param base  VBATCON peripheral base.
 * @param mask  OR'ed mask of ::_vbatcon_interrupt_enable values.
 */
static inline void VBATCON_DisableInterrupts(VBATCON_Type *base, uint32_t mask)
{
    uint32_t enables = base->EVENTS & (uint32_t)kVBATCON_IrqAll;
    enables &= ~(mask & (uint32_t)kVBATCON_IrqAll);
    base->EVENTS = enables;
}

/*!
 * @brief Get the asserted event flags.
 *
 * @param base  VBATCON peripheral base.
 * @return  OR'ed ::_vbatcon_event_flags currently set.
 */
static inline uint32_t VBATCON_GetEventFlags(VBATCON_Type *base)
{
    return base->EVENTS & (uint32_t)kVBATCON_EventAll;
}

/*!
 * @brief Clear event flags (write-1-to-clear).
 *
 * Only the lower 8 status bits are W1C; enable bits are preserved.
 *
 * @param base  VBATCON peripheral base.
 * @param mask  OR'ed mask of ::_vbatcon_event_flags to clear.
 */
void VBATCON_ClearEventFlags(VBATCON_Type *base, uint32_t mask);

/*! @} */

/*!
 * @name Clock control
 * @{
 */

/*!
 * @brief Enable or disable the BBSM functional-clock gate.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable clock gate; false: disable.
 */
void VBATCON_EnableBBSMClockGate(VBATCON_Type *base, bool enable);

/*!
 * @brief Enable or disable the VBAT_LPTIMER functional-clock gate.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: enable clock gate; false: disable.
 */
void VBATCON_EnableLPTMRClockGate(VBATCON_Type *base, bool enable);

/*!
 * @brief Enable or disable software override of the ULP32K source.
 *
 * @param base    VBATCON peripheral base.
 * @param enable  true: software-controlled ULP32K source; false: hardware default.
 */
void VBATCON_EnableUlp32kSwitch(VBATCON_Type *base, bool enable);

/*!
 * @brief Select the ULP32K clock source (only effective when SW switch is enabled).
 *
 * @param base    VBATCON peripheral base.
 * @param source  Source selection, see ::vbatcon_ulp32k_source_t.
 */
void VBATCON_SelectUlp32kSource(VBATCON_Type *base, vbatcon_ulp32k_source_t source);

/*!
 * @brief Switch the ULP32K clock source with readiness polling.
 *
 * Polls the corresponding ready flag (OSC_RDY for OSC32K, FRO_RDY for
 * FRO32K) before enabling the software override and committing the
 * source selection in a single CLOCK_CTRL write.
 *
 * @param base     VBATCON peripheral base.
 * @param source   Target clock source.
 * @param timeout  Maximum number of polling iterations.
 *                 0 = check current state only, no wait.
 * @retval kStatus_Success  Source was ready and the switch was committed.
 * @retval kStatus_Timeout  Source did not become ready within @p timeout iterations.
 */
status_t VBATCON_SwitchUlp32kSource(VBATCON_Type *base, vbatcon_ulp32k_source_t source, uint32_t timeout);

/*!
 * @brief Get clock-status flags from CLOCK_CTRL.
 *
 * @param base  VBATCON peripheral base.
 * @return  OR'ed ::_vbatcon_clock_status_flags currently asserted.
 */
static inline uint32_t VBATCON_GetClockStatusFlags(VBATCON_Type *base)
{
    return base->CLOCK_CTRL & (VBATCON_CLOCK_CTRL_OSC_RDY_MASK |
                               VBATCON_CLOCK_CTRL_FRO_RDY_MASK |
                               VBATCON_CLOCK_CTRL_OSS_MASK     |
                               VBATCON_CLOCK_CTRL_OTS_MASK);
}

/*! @} */

/*!
 * @name General-purpose registers
 * @{
 */

/*!
 * @brief Write a 32-bit value to a VBATCON GPR.
 *
 * @param base   VBATCON peripheral base.
 * @param index  GPR index (0 .. VBATCON_GPR_COUNT - 1).
 * @param value  32-bit value to store.
 */
static inline void VBATCON_WriteGPR(VBATCON_Type *base, uint8_t index, uint32_t value)
{
    assert(index < VBATCON_GPR_COUNT);
    base->GPR[index] = value;
}

/*!
 * @brief Read a 32-bit value from a VBATCON GPR.
 *
 * @param base   VBATCON peripheral base.
 * @param index  GPR index (0 .. VBATCON_GPR_COUNT - 1).
 * @return  Stored 32-bit value.
 */
static inline uint32_t VBATCON_ReadGPR(VBATCON_Type *base, uint8_t index)
{
    assert(index < VBATCON_GPR_COUNT);
    return base->GPR[index];
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_VBATCON_H_ */
