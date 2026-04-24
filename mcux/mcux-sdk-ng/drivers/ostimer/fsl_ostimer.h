/*
 * Copyright 2018-2021, 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_OSTIMER_H_
#define FSL_OSTIMER_H_

#include "fsl_common.h"

/*!
 * @addtogroup ostimer
 * @{
 */

/*! @file*/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief OSTIMER driver version. */
#define FSL_OSTIMER_DRIVER_VERSION (MAKE_VERSION(2, 3, 0))
/*! @} */


/*!
 * @brief OSTIMER status flags.
 */
enum _ostimer_flags
{
    kOSTIMER_MatchInterruptFlag = (OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_MASK), /*!< Match interrupt flag bit, sets if
                                                                                   the match value was reached. */
};

/*! @brief ostimer callback function. */
typedef void (*ostimer_callback_t)(void);

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes an OSTIMER by turning its bus clock on
 *
 */
void OSTIMER_Init(OSTIMER_Type *base);

/*!
 * @brief Deinitializes a OSTIMER instance.
 *
 * This function shuts down OSTIMER bus clock
 *
 * @param base OSTIMER peripheral base address.
 */
void OSTIMER_Deinit(OSTIMER_Type *base);

/*!
 * @brief Translate the value from gray-code to decimal.
 *
 * @param gray The gray value input.
 * @return The decimal value.
 */
uint64_t OSTIMER_GrayToDecimal(uint64_t gray);

/*!
 * @brief Translate the value from decimal to gray-code.
 *
 * @param dec The decimal value.
 * @return The gray code of the input value.
 */
static inline uint64_t OSTIMER_DecimalToGray(uint64_t dec)
{
    return (dec ^ (dec >> 1U));
}

/*!
 * @brief Get OSTIMER status Flags.
 *
 * This returns the status flag.
 * Currently, only match interrupt flag can be got.
 *
 * @param base OSTIMER peripheral base address.
 * @return status register value
 */
uint32_t OSTIMER_GetStatusFlags(OSTIMER_Type *base);

/*!
 * @brief Clear Status Interrupt Flags.
 *
 * This clears interrupt status flag.
 * Currently, only match interrupt flag can be cleared.
 *
 * @param base OSTIMER peripheral base address.
 * @param mask Clear bit mask.
 * @return none
 */
void OSTIMER_ClearStatusFlags(OSTIMER_Type *base, uint32_t mask);

/*!
 * @brief Set the match raw value for OSTIMER.
 *
 * This function will set a match value for OSTIMER with an optional callback. And this callback
 * will be called while the data in dedicated pair match register is equals to the value of central EVTIMER.
 * Please note that, the data format may be gray-code, if so, please use OSTIMER_SetMatchValue().
 *
 * @param base   OSTIMER peripheral base address.
 * @param count  OSTIMER timer match value.(Value may be gray-code format)
 *
 * @param cb     OSTIMER callback (can be left as NULL if none, otherwise should be a void func(void)).
 * @retval kStatus_Success  Match raw value written and interrupt enabled successfully.
 */
status_t OSTIMER_SetMatchRawValue(OSTIMER_Type *base, uint64_t count, ostimer_callback_t cb);

/*!
 * @brief Set the match value for OSTIMER.
 *
 * This function will set a match value for OSTIMER with an optional callback. And this callback
 * will be called while the data in dedicated pair match register is equals to the value of central EVTIMER.
 *
 * The function disables the match interrupt before writing the match registers and re-enables it
 * immediately after. This function is suitable when the delta between the current timer value and @p count is
 * comfortably larger than the match-register synchronisation latency (more than 7 OSTimer ticks).
 * However, it does NOT wait for OSEVENT_CTRL[MATCH_WR_RDY]) after writing MATCH, and it does NOT check whether
 * the requested match time has already passed. If there is any possibility that @p count is close to or has already
 * passed the current timer value, use @ref OSTIMER_SetMatchValueSafe() instead, which polls MATCH_WR_RDY and checks
 * whether the match moment has been missed.
 *
 * @param base   OSTIMER peripheral base address.
 * @param count  Match value in decimal (binary) format. The driver converts to Gray code internally
 *               when the hardware counter is Gray-encoded.
 * @param cb     OSTIMER callback (can be left as NULL if none, otherwise should be a void func(void)).
 * @retval kStatus_Success  Match value written and interrupt enabled successfully.
 */
status_t OSTIMER_SetMatchValue(OSTIMER_Type *base, uint64_t count, ostimer_callback_t cb);

/*!
 * @brief Set the match value for OSTIMER with full synchronisation and missed-event detection.
 *
 * This function will set a match value for OSTIMER with an optional callback. And this callback
 * will be called while the data in dedicated pair match register is equals to the value of central EVTIMER.
 *
 * Unlike @ref OSTIMER_SetMatchValue(), this function performs the following additional steps after
 * writing the match registers:
 *
 * 1. Wait for write synchronisation (MATCH_WR_RDY).
 *    On devices that expose OSEVENT_CTRL[MATCH_WR_RDY], the function spins until that bit is
 *    cleared, which indicates that the written value has been transferred from the shadow registers
 *    to the active compare registers in the OSTimer clock domain. This eliminates the race condition
 *    where the timer advances past the match value before the hardware has latched it.
 *
 * 2. Check whether the match moment has already been missed.
 *    After MATCH_WR_RDY clears, the function reads the current timer value and compares it with @p count:
 *    - If the current timer value is still below @p count, the match has not yet occurred.
 *      The interrupt is enabled and the function returns @ref kStatus_Success.
 *    - If the current timer value has reached or passed @p count:
 *      - If the hardware interrupt flag (OSTIMER_INTRFLAG) is already set, the match event was
 *        captured by hardware. The interrupt is enabled so the pending flag triggers the ISR, and
 *        the function returns @ref kStatus_Success.
 *      - If the interrupt flag is NOT set, the match moment passed without the hardware
 *        capturing it (the compare logic had not yet latched the value when the timer advanced).
 *        The interrupt is left DISABLED and the function returns @ref kStatus_Fail. The caller
 *        is responsible for handling this missed event, for example by scheduling a new match
 *        immediately or executing the intended action directly.
 *
 * @note This function is recommended whenever the requested match delta is small or unpredictable
 *       relative to the OSTimer source clock period.
 *       If the overhead of polling MATCH_WR_RDY is unacceptable (e.g. at 32 KHz with tight
 *       real-time constraints), use @ref OSTIMER_SetMatchValue() and ensure the match delta is
 *       always large enough.
 *
 * @param base   OSTIMER peripheral base address.
 * @param count  Match value in decimal (binary) format. The driver converts to Gray code internally
 *               when the hardware counter is Gray-encoded.
 * @param cb     OSTIMER callback (can be left as NULL if none, otherwise should be a void func(void)).
 *
 * @retval kStatus_Success  Match value written and interrupt enabled. The match event will occur
 *                          in the future, or the hardware interrupt flag was already set and the
 *                          pending interrupt will fire immediately upon enabling.
 * @retval kStatus_Fail     Match time already passed and the hardware interrupt flag was not set.
 *                          The interrupt remains disabled. The caller must handle the missed event.
 */
status_t OSTIMER_SetMatchValueSafe(OSTIMER_Type *base, uint64_t count, ostimer_callback_t cb);

/*!
 * @brief Set value to OSTIMER MATCH register directly.
 *
 * This function writes the input value to OSTIMER MATCH register directly,
 * it does not touch any other registers. Note that, the data format is
 * gray-code if the hardware register is gray-encoded. The function
 * @ref OSTIMER_DecimalToGray could convert decimal value to gray code.
 *
 * @param base   OSTIMER peripheral base address.
 * @param value  OSTIMER timer match value (Value is gray-code format if the hardware register is gray-encoded).
 */
static inline void OSTIMER_SetMatchRegister(OSTIMER_Type *base, uint64_t value)
{
#ifdef OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_MASK
    /* Wait for MATCH register ready for write. */
    while (0U != (base->OSEVENT_CTRL & OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_MASK))
    {
    }
#endif

    base->MATCH_L = (uint32_t)(value & 0xFFFFFFFFU);
    base->MATCH_H = (uint32_t)(value >> 32U);
}

/*!
 * @brief Get the match value from OSTIMER.
 *
 * This function will get the match value from OSTIMER.
 * The value of timer match is gray code format if the hardware is Gray-encoded.
 *
 * @param base   OSTIMER peripheral base address.
 * @return Value of match register, data format is gray code if the register is Gray-encoded.
 */
static inline uint64_t OSTIMER_GetMatchRegister(OSTIMER_Type *base)
{
    uint64_t tmp = 0U;

    tmp = base->MATCH_L;
    tmp |= (uint64_t)(base->MATCH_H) << 32U;

    return tmp;
}

/*!
 * @brief Get the match value from OSTIMER.
 *
 * This function will get a match value from OSTIMER.
 *
 * @param base   OSTIMER peripheral base address.
 * @return Value of match register in decimal format.
 */
static inline uint64_t OSTIMER_GetMatchValue(OSTIMER_Type *base)
{
    uint64_t value = OSTIMER_GetMatchRegister(base);
#if (defined(FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER) && FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER)
    return value;
#else
    return OSTIMER_GrayToDecimal(value);
#endif /* FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER */
}

/*!
 * @brief Enable the OSTIMER counter match interrupt.
 *
 * Enable the timer counter match interrupt. The interrupt happens when OSTIMER
 * counter matches the value in MATCH registers.
 *
 * @param base OSTIMER peripheral base address.
 */
static inline void OSTIMER_EnableMatchInterrupt(OSTIMER_Type *base)
{
    base->OSEVENT_CTRL |= OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK;
}

/*!
 * @brief Disable the OSTIMER counter match interrupt.
 *
 * Disable the timer counter match interrupt. The interrupt happens when OSTIMER
 * counter matches the value in MATCH registers.
 *
 * @param base OSTIMER peripheral base address.
 */
static inline void OSTIMER_DisableMatchInterrupt(OSTIMER_Type *base)
{
    base->OSEVENT_CTRL &= ~OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK;
}

/*!
 * @brief Get current timer raw count value from OSTIMER.
 *
 * This function will get the timer count value from OS timer register.
 * The raw value of timer count may be gray code format.
 *
 * @param base   OSTIMER peripheral base address.
 * @return       Raw value of OSTIMER, may be gray code format if the hardware register is Gray-encoded.
 */
static inline uint64_t OSTIMER_GetCurrentTimerRawValue(OSTIMER_Type *base)
{
    uint64_t tmp = 0U;

    tmp = base->EVTIMERL;
    tmp |= (uint64_t)(base->EVTIMERH) << 32U;

    return tmp;
}

/*!
 * @brief Get current timer count value from OSTIMER.
 *
 * This function will get a decimal timer count value.
 * If the RAW value of timer count is gray code format, it will be translated to decimal data internally.
 *
 * @param base   OSTIMER peripheral base address.
 * @return       Value of OSTIMER which will be formated to decimal value.
 */
uint64_t OSTIMER_GetCurrentTimerValue(OSTIMER_Type *base);

/*!
 * @brief Get the capture value from OSTIMER.
 *
 * This function will get a captured value from OSTIMER.
 * The Raw value of timer capture may be gray code format if the hardware register is Gray-encoded.
 *
 * @param base   OSTIMER peripheral base address.
 * @return       Raw value of capture register, data format may be gray code if the hardware register is Gray-encoded.
 */
static inline uint64_t OSTIMER_GetCaptureRawValue(OSTIMER_Type *base)
{
    uint64_t tmp = 0U;

    tmp = base->CAPTURE_L;
    tmp |= (uint64_t)(base->CAPTURE_H) << 32U;

    return tmp;
}

/*!
 * @brief Get the capture value from OSTIMER.
 *
 * This function will get a capture decimal-value from OSTIMER.
 * If the RAW value of timer count is gray code format, it will be translated to decimal data internally.
 *
 * @param base   OSTIMER peripheral base address.
 * @return Value of capture register, data format is decimal.
 */
uint64_t OSTIMER_GetCaptureValue(OSTIMER_Type *base);

/*!
 * @brief OS timer interrupt Service Handler.
 *
 * This function handles the interrupt and refers to the callback array in the driver to callback user (as per request
 * in OSTIMER_SetMatchValue()).
 * if no user callback is scheduled, the interrupt will simply be cleared.
 *
 * @param base   OS timer peripheral base address.
 * @param cb     callback scheduled for this instance of OS timer
 * @return       none
 */
void OSTIMER_HandleIRQ(OSTIMER_Type *base, ostimer_callback_t cb);
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_OSTIMER_H_ */
