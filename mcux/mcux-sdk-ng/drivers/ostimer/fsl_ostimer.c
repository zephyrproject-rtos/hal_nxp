/*
 * Copyright 2018-2021, 2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_ostimer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.ostimer"
#endif

#if defined(OSTIMER_RSTS)
#define OSTIMER_RESETS_ARRAY OSTIMER_RSTS
#endif

/* Typedef for interrupt handler. */
typedef void (*ostimer_isr_t)(OSTIMER_Type *base, ostimer_callback_t cb);

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address
 *
 * @param base OSTIMER peripheral base address
 *
 * @return The OSTIMER instance
 */
static uint32_t OSTIMER_GetInstance(OSTIMER_Type *base);

#if (defined(FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY) && FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY)
/* @brief Translate the value from gray-code to decimal by the Code Gray in SYSCTL.
 *
 * @param gray The gray value input.
 *
 * @return the decimal value.
 */
static uint64_t OSTIMER_GrayToDecimalbyCodeGray(uint64_t gray);
#endif /* FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY. */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Array of OSTIMER handle. */
static ostimer_callback_t s_ostimerHandle[FSL_FEATURE_SOC_OSTIMER_COUNT];
/* Array of OSTIMER peripheral base address. */
static OSTIMER_Type *const s_ostimerBases[] = OSTIMER_BASE_PTRS;
/* Array of OSTIMER IRQ number. */
static const IRQn_Type s_ostimerIRQ[] = OSTIMER_IRQS;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of OSTIMER clock name. */
static const clock_ip_name_t s_ostimerClock[] = OSTIMER_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/* OSTIMER ISR for transactional APIs. */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
static ostimer_isr_t s_ostimerIsr = (ostimer_isr_t)DefaultISR;
#else
static ostimer_isr_t s_ostimerIsr;
#endif

#if defined(OSTIMER_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_ostimerResets[] = OSTIMER_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/* @brief Function for getting the instance number of OS timer. */
static uint32_t OSTIMER_GetInstance(OSTIMER_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_ostimerBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_ostimerBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_ostimerBases));

    return instance;
}

#if (defined(FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY) && FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY)
/* @brief Translate the value from gray-code to decimal by the Code Gray in SYSCTL.
 *
 * @param gray The gray value input.
 *
 * @return the decimal value.
 */
static uint64_t OSTIMER_GrayToDecimalbyCodeGray(uint64_t gray)
{
    uint64_t decOut;

    SYSCTL->CODE_GRAY_LSB = (uint32_t)(gray & 0xFFFFFFFFU);
    SYSCTL->CODE_GRAY_MSB = (uint32_t)((gray >> 32U) & 0x3FFU); // limit to 42bits as OSevent timer
    __NOP();
    decOut = ((uint64_t)(SYSCTL->CODE_BIN_MSB) & 0x3FFU) << 32U;
    decOut |= (uint64_t)(SYSCTL->CODE_BIN_LSB);

    return decOut;
}
#endif /* FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY. */

/* @brief Translate the value from gray-code to decimal. */
/*
 * @param gray The gray value input.
 *
 * @return the decimal value.
 */
uint64_t OSTIMER_GrayToDecimal(uint64_t gray)
{
#if (defined(FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY) && FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY)
    return OSTIMER_GrayToDecimalbyCodeGray(gray);
#else
    gray ^= gray >> 32U;
    gray ^= gray >> 16U;
    gray ^= gray >> 8U;
    gray ^= gray >> 4U;
    gray ^= gray >> 2U;
    gray ^= gray >> 1U;

    return gray;
#endif /* FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY. */
}

/* @brief Enable the OSTIMER interrupt.
 *
 * After calling this function, the OSTIMER driver will enable/disable the IRQ and module interrupt enablement.
 *
 * @param base OSTIMER peripheral base address.
 * @param enable enable/disable the IRQ and module interrupt enablement.
 *               - true: Disable the IRQ and module interrupt enablement.
 *               - false: Disable the IRQ and module interrupt enablement.
 * @return none
 */
static void OSTIMER_EnableInterrupt(OSTIMER_Type *base, bool enable)
{
    assert(NULL != base);

    if (enable)
    {
        /* Enable the IRQ and module interrupt enablement. */
        (void)EnableIRQ(s_ostimerIRQ[OSTIMER_GetInstance(base)]);
        base->OSEVENT_CTRL |= OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK;
    }
    else
    {
        /* Clear interrupt flag, disable the IRQ and module interrupt enablement. */
        (void)DisableIRQ(s_ostimerIRQ[OSTIMER_GetInstance(base)]);
        base->OSEVENT_CTRL &= ~OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK; /* Clear interrupt flag by writing 1. */
    }
}

/*!
 * @brief Initializes an OSTIMER by turning it's clock on.
 *
 */
void OSTIMER_Init(OSTIMER_Type *base)
{
    assert(NULL != base);

    uint32_t instance = OSTIMER_GetInstance(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if !(defined(FSL_FEATURE_PMC_HAS_NO_OSTIMER_REG) && FSL_FEATURE_PMC_HAS_NO_OSTIMER_REG)
    /* Enable the OSTIMER 32k clock in PMC module. */
    CLOCK_EnableOstimer32kClock();
#endif
    /* Enable clock for OSTIMER. */
    CLOCK_EnableClock(s_ostimerClock[instance]);
#if (defined(FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY) && FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY)
    CLOCK_EnableClock(kCLOCK_Sysctl);
#endif /* FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY. */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(OSTIMER_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_ostimerResets[OSTIMER_GetInstance(base)]);
#endif
}

/*!
 * @brief Deinitializes a OSTIMER instance.
 *
 * This function shuts down OSTIMER clock
 *
 * @param base OSTIMER peripheral base address.
 */
void OSTIMER_Deinit(OSTIMER_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable pending interrupts before disabling the OSTIMER clock
     to avoid interrupts being triggered when the clock is disabled. */
    OSTIMER_EnableInterrupt(base, false);
    /* Enable clock for OSTIMER. */
    CLOCK_DisableClock(s_ostimerClock[OSTIMER_GetInstance(base)]);
#if (defined(FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY) && FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY)
    CLOCK_DisableClock(kCLOCK_Sysctl);
#endif /* FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY. */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
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
uint32_t OSTIMER_GetStatusFlags(OSTIMER_Type *base)
{
    return base->OSEVENT_CTRL & OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_MASK;
}

/*!
 * @brief Clear Status Interrupt Flags.
 *
 * This clears intr status flag.
 * Currently, only match interrupt flag can be cleared.
 *
 * @param base OSTIMER peripheral base address.
 * @param mask Clear bit mask.
 * @return none
 */
void OSTIMER_ClearStatusFlags(OSTIMER_Type *base, uint32_t mask)
{
    base->OSEVENT_CTRL |= mask;
}

/*!
 * @brief Set the match raw value for OSTIMER.
 *
 * This function will set a match value for OSTIMER with an optional callback. And this callback
 * will be called while the data in dedicated pair match register is equals to the value of central EVTIMER.
 * Please note that, the data format may be gray-code, if so, please using OSTIMER_SetMatchValue().
 *
 * @param base   OSTIMER peripheral base address.
 * @param count  OSTIMER timer match value.(Value may be gray-code format)
 *
 * @param cb     OSTIMER callback (can be left as NULL if none, otherwise should be a void func(void)).
 * @retval kStatus_Success                    - Set match raw value and enable interrupt Successfully.
 */
status_t OSTIMER_SetMatchRawValue(OSTIMER_Type *base, uint64_t count, ostimer_callback_t cb)
{
    uint64_t tmp      = count;
    uint32_t instance = OSTIMER_GetInstance(base);

    /* Clear interrupt flag, disable the IRQ and module interrupt enablement. */
    OSTIMER_EnableInterrupt(base, false);

    s_ostimerIsr              = OSTIMER_HandleIRQ;
    s_ostimerHandle[instance] = cb;

    OSTIMER_SetMatchRegister(base, tmp);
    OSTIMER_EnableInterrupt(base, true);

    return kStatus_Success;
}

/*!
 * @brief Set the match value for OSTIMER.
 *
 * This function will set a match value for OSTIMER with an optional callback. And this callback
 * will be called while the data in dedicated pair match register is equals to the value of central EVTIMER.
 *
 * @param base   OSTIMER peripheral base address.
 * @param count  OSTIMER timer match value.(Value is decimal format, and this value will be translate to Gray code in
 * API if the IP counter is gray encoded. )
 * @param cb  OSTIMER callback (can be left as NULL if none, otherwise should be a void func(void)).
 * @retval kStatus_Success                    - Set match raw value and enable interrupt Successfully.
 */
status_t OSTIMER_SetMatchValue(OSTIMER_Type *base, uint64_t count, ostimer_callback_t cb)
{
#if (defined(FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER) && FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER)
    return OSTIMER_SetMatchRawValue(base, count, cb);
#else
    uint64_t tmp = OSTIMER_DecimalToGray(count);

    return OSTIMER_SetMatchRawValue(base, tmp, cb);
#endif /* FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER */
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
uint64_t OSTIMER_GetCurrentTimerValue(OSTIMER_Type *base)
{
    uint64_t tmp = 0U;

    tmp = OSTIMER_GetCurrentTimerRawValue(base);

#if (defined(FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER) && FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER)
    return tmp;
#else
    return OSTIMER_GrayToDecimal(tmp);
#endif /* FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER */
}

/*!
 * @brief Get the capture value from OSTIMER.
 *
 * This function will get a capture decimal-value from OSTIMER.
 * If the RAW value of timer count is gray code format, it will be translated to decimal data internally.
 *
 * @param base   OSTIMER peripheral base address.
 * @return       Value of capture register, data format is decimal.
 */
uint64_t OSTIMER_GetCaptureValue(OSTIMER_Type *base)
{
    uint64_t tmp = 0U;

    tmp = OSTIMER_GetCaptureRawValue(base);

#if (defined(FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER) && FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER)
    return tmp;
#else
    return OSTIMER_GrayToDecimal(tmp);
#endif /* FSL_FEATURE_OSTIMER_HAS_BINARY_ENCODED_COUNTER */
}

void OSTIMER_HandleIRQ(OSTIMER_Type *base, ostimer_callback_t cb)
{
    /* Clear interrupt flag, disable the IRQ and module interrupt enablement. */
    OSTIMER_EnableInterrupt(base, false);

    if (cb != NULL)
    {
        cb();
    }
}

void OS_EVENT_DriverIRQHandler(void);
void OS_EVENT_DriverIRQHandler(void)
{
    s_ostimerIsr(s_ostimerBases[0], s_ostimerHandle[0]);
    SDK_ISR_EXIT_BARRIER;
}
