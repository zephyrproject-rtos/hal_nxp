/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_PWM_H_
#define _FSL_PWM_H_

#include "fsl_common.h"

/*!
 * @addtogroup pwm_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
#define FSL_PWM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0 */
/*@}*/

/*! @brief PWM clock source select. */
typedef enum _pwm_clock_source
{
    kPWM_PeripheralClock = 1U, /*!< The Peripheral clock is used as the clock */
    kPWM_HighFrequencyClock,   /*!< High-frequency reference clock is used as the clock */
    kPWM_LowFrequencyClock     /*!< Low-frequency reference clock(32KHz) is used as the clock */
} pwm_clock_source_t;

/*!
 * @brief PWM FIFO water mark select.
 * Sets the data level at which the FIFO empty flag will be set
 */
typedef enum _pwm_fifo_water_mark
{
    kPWM_FIFOWaterMark_1 = 0U, /*!< FIFO empty flag is set when there are more than or equal to 1 empty slots */
    kPWM_FIFOWaterMark_2,      /*!< FIFO empty flag is set when there are more than or equal to 2 empty slots */
    kPWM_FIFOWaterMark_3,      /*!< FIFO empty flag is set when there are more than or equal to 3 empty slots */
    kPWM_FIFOWaterMark_4       /*!< FIFO empty flag is set when there are more than or equal to 4 empty slots */
} pwm_fifo_water_mark_t;

/*!
 * @brief PWM byte data swap select.
 * It determines the byte ordering of the 16-bit data when it goes into the FIFO from the sample register.
 */
typedef enum _pwm_byte_data_swap
{
    kPWM_ByteNoSwap = 0U, /*!< byte ordering remains the same */
    kPWM_ByteSwap         /*!< byte ordering is reversed */
} pwm_byte_data_swap_t;

/*! @brief PWM half-word data swap select. */
typedef enum _pwm_half_word_data_swap
{
    kPWM_HalfWordNoSwap = 0U, /*!< Half word swapping does not take place */
    kPWM_HalfWordSwap         /*!< Half word from write data bus are swapped */
} pwm_half_word_data_swap_t;

/*! @brief PWM Output Configuration */
typedef enum _pwm_output_configuration
{
    kPWM_SetAtRolloverAndClearAtcomparison = 0U, /*!< Output pin is set at rollover and cleared at comparison */
    kPWM_ClearAtRolloverAndSetAtcomparison,      /*!< Output pin is cleared at rollover and set at comparison */
    kPWM_NoConfigure                             /*!< PWM output is disconnected */
} pwm_output_configuration_t;

/*!
 * @brief PWM FIFO sample repeat
 * It determines the number of times each sample from the FIFO is to be used.
 */
typedef enum _pwm_sample_repeat
{
    kPWM_EachSampleOnce = 0u, /*!< Use each sample once */
    kPWM_EachSampletwice,     /*!< Use each sample twice */
    kPWM_EachSampleFourTimes, /*!< Use each sample four times */
    kPWM_EachSampleEightTimes /*!< Use each sample eight times */
} pwm_sample_repeat_t;

/*! @brief List of PWM interrupt options */
typedef enum _pwm_interrupt_enable
{
    kPWM_FIFOEmptyInterruptEnable = (1U << 0), /*!< This bit controls the generation of the FIFO Empty interrupt. */
    kPWM_RolloverInterruptEnable  = (1U << 1), /*!< This bit controls the generation of the Rollover interrupt. */
    kPWM_CompareInterruptEnable   = (1U << 2)  /*!< This bit controls the generation of the Compare interrupt */
} pwm_interrupt_enable_t;

/*! @brief List of PWM status flags */
typedef enum _pwm_status_flags
{
    kPWM_FIFOEmptyFlag = (1U << 3), /*!< This bit indicates the FIFO data level in comparison to the water
                                         level set by FWM field in the control register. */
    kPWM_RolloverFlag = (1U << 4),  /*!< This bit shows that a roll-over event has occurred. */
    kPWM_CompareFlag  = (1U << 5),  /*!< This bit shows that a compare event has occurred. */
    kPWM_FIFOWriteErrorFlag =
        (1U << 6) /*!< This bit shows that an attempt has been made to write FIFO when it is full. */
} pwm_status_flags_t;

/*! @brief List of PWM FIFO available */
typedef enum _pwm_fifo_available
{
    kPWM_NoDataInFIFOFlag = 0U, /*!< No data available */
    kPWM_OneWordInFIFOFlag,     /*!< 1 word of data in FIFO */
    kPWM_TwoWordsInFIFOFlag,    /*!< 2 word of data in FIFO */
    kPWM_ThreeWordsInFIFOFlag,  /*!< 3 word of data in FIFO */
    kPWM_FourWordsInFIFOFlag    /*!< 4 word of data in FIFO */
} pwm_fifo_available_t;

typedef struct _pwm_config
{
    bool enableStopMode;                     /*!< True: PWM continues to run in stop mode;
                                                  False: PWM is paused in stop mode. */
    bool enableDozeMode;                     /*!< True: PWM continues to run in doze mode;
                                                  False: PWM is paused in doze mode. */
    bool enableWaitMode;                     /*!< True: PWM continues to run in wait mode;
                                                  False: PWM is paused in wait mode. */
    bool enableDebugMode;                    /*!< True: PWM continues to run in debug mode;
                                                  False: PWM is paused in debug mode. */
    uint16_t prescale;                       /*!< Pre-scaler to divide down the clock
                                                  The prescaler value is not more than 0xFFF. Divide by (value + 1)*/
    pwm_clock_source_t clockSource;          /*!< Clock source for the counter */
    pwm_output_configuration_t outputConfig; /*!< Set the mode of the PWM output on the output pin. */
    pwm_fifo_water_mark_t fifoWater;         /*!< Set the data level for FIFO. */
    pwm_sample_repeat_t sampleRepeat;        /*!< The number of times each sample from the FIFO is to be used. */
    pwm_byte_data_swap_t byteSwap; /*!< It determines the byte ordering of the 16-bit data when it goes into the
                                        FIFO from the sample register. */
    pwm_half_word_data_swap_t halfWordSwap; /*!< It determines which half word data from the 32-bit IP Bus interface is
                                                 written into the lower 16 bits of the sample register. */
} pwm_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Ungates the PWM clock and configures the peripheral for basic operation.
 *
 * @note This API should be called at the beginning of the application using the PWM driver.
 *
 * @param base      PWM peripheral base address
 * @param config    Pointer to user's PWM config structure.
 *
 * @return kStatus_Success means success; else failed.
 */
status_t PWM_Init(PWM_Type *base, const pwm_config_t *config);

/*!
 * @brief Gate the PWM submodule clock
 *
 * @param base      PWM peripheral base address
 */
void PWM_Deinit(PWM_Type *base);

/*!
 * @brief  Fill in the PWM config struct with the default settings
 *
 * The default values are:
 * @code
 *   config->enableStopMode = false;
 *   config->enableDozeMode = false;
 *   config->enableWaitMode = false;
 *   config->enableDozeMode = false;
 *   config->clockSource = kPWM_LowFrequencyClock;
 *   config->prescale = 0U;
 *   config->outputConfig = kPWM_SetAtRolloverAndClearAtcomparison;
 *   config->fifoWater = kPWM_FIFOWaterMark_2;
 *   config->sampleRepeat = kPWM_EachSampleOnce;
 *   config->byteSwap = kPWM_ByteNoSwap;
 *   config->halfWordSwap = kPWM_HalfWordNoSwap;
 * @endcode
 * @param config Pointer to user's PWM config structure.
 */
void PWM_GetDefaultConfig(pwm_config_t *config);

/*! @}*/

/*!
 * @name PWM start and stop.
 * @{
 */

/*!
 * @brief Starts the PWM counter when the PWM is enabled.
 *
 * When the PWM is enabled, it begins a new period, the output pin is set to start a new period while
 * the prescaler and counter are released and counting begins.
 *
 * @param base      PWM peripheral base address
 */
static inline void PWM_StartTimer(PWM_Type *base)
{
    base->PWMCR |= PWM_PWMCR_EN_MASK;
}

/*!
 * @brief Stops the PWM counter when the pwm is disabled.
 *
 * @param base      PWM peripheral base address
 */
static inline void PWM_StopTimer(PWM_Type *base)
{
    base->PWMCR &= ~(PWM_PWMCR_EN_MASK);
}

/*! @}*/

/*!
 * @brief Sofrware reset.
 *
 * PWM is reset when this bit is set to 1. It is a self clearing bit.
 * Setting this bit resets all the registers to their reset values except for the STOPEN,
 * DOZEN, WAITEN, and DBGEN bits in this control register.
 *
 * @param base      PWM peripheral base address
 */
static inline void PWM_SoftwareReset(PWM_Type *base)
{
    base->PWMCR |= PWM_PWMCR_SWR_MASK;
}

/*!
 * @name Interrupt Interface
 * @{
 */

/*!
 * @brief Enables the selected PWM interrupts.
 *
 * @param base PWM peripheral base address
 * @param mask The interrupts to enable. This is a logical OR of members of the
 *             enumeration ::pwm_interrupt_enable_t
 */
static inline void PWM_EnableInterrupts(PWM_Type *base, uint32_t mask)
{
    base->PWMIR |= (mask & (PWM_PWMIR_FIE_MASK | PWM_PWMIR_RIE_MASK | PWM_PWMIR_CIE_MASK));
}

/*!
 * @brief Disables the selected PWM interrupts.
 *
 * @param base PWM peripheral base address
 * @param mask The interrupts to disable. This is a logical OR of members of the
 *             enumeration ::pwm_interrupt_enable_t
 */
static inline void PWM_DisableInterrupts(PWM_Type *base, uint32_t mask)
{
    base->PWMIR &= ~(mask & (PWM_PWMIR_FIE_MASK | PWM_PWMIR_RIE_MASK | PWM_PWMIR_CIE_MASK));
}

/*!
 * @brief Gets the enabled PWM interrupts.
 *
 * @param base PWM peripheral base address
 *
 * @return The enabled interrupts. This is the logical OR of members of the
 *         enumeration ::pwm_interrupt_enable_t
 */
static inline uint32_t PWM_GetEnabledInterrupts(PWM_Type *base)
{
    return base->PWMIR;
}

/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Gets the PWM status flags.
 *
 * @param base PWM peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::pwm_status_flags_t
 */
static inline uint32_t PWM_GetStatusFlags(PWM_Type *base)
{
    uint32_t statusFlags = base->PWMSR;

    statusFlags &= (PWM_PWMSR_FE_MASK | PWM_PWMSR_ROV_MASK | PWM_PWMSR_CMP_MASK | PWM_PWMSR_FWE_MASK);
    return statusFlags;
}

/*!
 * @brief Clears the PWM status flags.
 *
 * @param base PWM peripheral base address
 * @param mask The status flags to clear. This is a logical OR of members of the
 *             enumeration ::pwm_status_flags_t
 */
static inline void PWM_clearStatusFlags(PWM_Type *base, uint32_t mask)
{
    base->PWMSR = (mask & (PWM_PWMSR_FE_MASK | PWM_PWMSR_ROV_MASK | PWM_PWMSR_CMP_MASK | PWM_PWMSR_FWE_MASK));
}

/*!
 * @brief Gets the PWM FIFO available.
 *
 * @param base PWM peripheral base address
 *
 * @return The status flags. This is the logical OR of members of the
 *         enumeration ::pwm_fifo_available_t
 */
static inline uint32_t PWM_GetFIFOAvailable(PWM_Type *base)
{
    return (base->PWMSR & PWM_PWMSR_FIFOAV_MASK);
}

/*! @}*/

/*!
 * @name Sample Interface
 * @{
 */

/*!
 * @brief Sets the PWM sample value.
 *
 * @param base PWM peripheral base address
 * @param value The sample value. This is the input to the 4x16 FIFO. The value in this register denotes
 *             the value of the sample being currently used.
 */
static inline void PWM_SetSampleValue(PWM_Type *base, uint32_t value)
{
    base->PWMSAR = (value & PWM_PWMSAR_SAMPLE_MASK);
}

/*!
 * @brief Gets the PWM sample value.
 *
 * @param base PWM peripheral base address
 *
 * @return The sample value. It can be read only when the PWM is enable.
 */
static inline uint32_t PWM_GetSampleValue(PWM_Type *base)
{
    return base->PWMSAR;
}

/*! @}*/

/*!
 * @brief Sets the PWM period value.
 *
 * @param base PWM peripheral base address
 * @param value The period value. The PWM period register (PWM_PWMPR) determines the period of
 *             the PWM output signal.
 *             Writing 0xFFFF to this register will achieve the same result as writing 0xFFFE.
 *             PWMO (Hz) = PCLK(Hz) / (period +2)
 */
static inline void PWM_SetPeriodValue(PWM_Type *base, uint32_t value)
{
    base->PWMPR = (value & PWM_PWMPR_PERIOD_MASK);
}

/*!
 * @brief Gets the PWM period value.
 *
 * @param base PWM peripheral base address
 *
 * @return The period value. The PWM period register (PWM_PWMPR) determines the period of
 *             the PWM output signal.
 */
static inline uint32_t PWM_GetPeriodValue(PWM_Type *base)
{
    return (base->PWMPR & PWM_PWMPR_PERIOD_MASK);
}

/*!
 * @brief Gets the PWM counter value.
 *
 * @param base PWM peripheral base address
 *
 * @return The counter value. The current count value.
 */
static inline uint32_t PWM_GetCounterValue(PWM_Type *base)
{
    return (base->PWMCNR & PWM_PWMCNR_COUNT_MASK);
}

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* _FSL_PWM_H_ */
