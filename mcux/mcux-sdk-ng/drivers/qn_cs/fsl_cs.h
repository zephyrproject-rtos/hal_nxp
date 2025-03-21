/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CS_H_
#define FSL_CS_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_cs
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_CS_DRIVER_VERSION (MAKE_VERSION(2, 0, 1)) /*!< Version 2.0.1 */

/*!
 * @brief CS mode
 */
typedef enum _cs_mode
{
    kCS_ActiveMode = 0U,
    kCS_WakeupMode,
} cs_mode_t;

/*!
 * @brief CS configuration
 */
typedef struct _cs_config
{
    uint16_t activeClockDivider; /*!< Active mode clock divider, occupy 9 bits, generates CLK_CS clock from CLK_APB
                                      clock using F(CS) = F(APB) / (clockDivider+1) */
    uint16_t activeDetectPeriod; /*!< Detect period (how many CLK_CS clock cycles to scan a channel, occupy 16 bits */
    uint16_t activeIdlePeriod; /*!< Idle period (how many clock cycles to wait between channel scans), occupy 16 bits */
    uint16_t activeOscFreq; /*!< Relaxation oscillator frequency configuration. The value will adjust the current being
                                 driven to input channels by equation: 0.4 + 0.2(OSC_FREQ+1) [uA], occupy 6 bits */
    uint8_t activeCounterGain; /*!< Can increase counter value by multiplication with this gain, cccupy 8 bits */
    uint8_t activeChannels;    /*!< Selects which capacitive sense channel is enabled for input scanning. A 1 in any
                                    bit of this field will cause the corresponding channel to be included for scanning */
    uint8_t
        lowPowerChannelNum; /*!< Indicates how many consecutive CLK_32K cycles need to meet the threshold value before
                                 the wake-up interrupt is triggered. The actual interpretation by the hardware of this
                                 value is such that one more than the value programmed here is used, occupy 4 bits */
    uint16_t lowPowerThreshold;  /*!< The value represents the upper bound of the counter output in terms of what is
                                      considered a valid touch event, occupy 16 bits*/
    uint16_t lowPowerDebonceNum; /*!< Selects which channel index to monitor while in LP mode, occupy 3 bits*/
    uint16_t
        lowPowerIdlePeriod;   /*!< Idle period between previous scanning end and next scanning start, occupy 16 bits */
    uint16_t lowPowerOscFreq; /*!< OSC bias select, occupy 6 bits */
} cs_config_t;

/*!
 * @brief interrupts
 */
typedef enum _cs_interrupt_enable
{
    kCS_InterruptFifoNotFullEnable  = CS_INTEN_FIFO_NOTEMPTY_INTEN_MASK, /*!< Enable Fifo not empty interrupt */
    kCS_InterruptFifoHalfFullEnable = CS_INTEN_FIFO_HFULL_INTEN_MASK,    /*!< Enable Fifo half full interrupt */
    kCS_InterruptFifoFullEnable     = CS_INTEN_FIFO_FULL_INTEN_MASK,     /*!< Enable Fifo full interrupt */
    kCS_InterruptScanCompleteEnable = CS_INTEN_SCAN_INTEN_MASK,          /*!< Enable Scan complete interrupt */
} cs_interrupt_enable_t;

/*!
 * @brief Flags
 */
typedef enum _cs_status_flags
{
    kCS_InterruptFifoNotEmptyFlag = CS_INT_FIFO_NOTEMPTY_INT_MASK, /*!< Fifo not empty interrupt flag */
    kCS_InterruptFifoHalfFullFlag = CS_INT_FIFO_HFULL_INT_MASK,    /*!< Fifo half full interrupt flag */
    kCS_InterruptFifoFullFlag     = CS_INT_FIFO_FULL_INT_MASK,     /*!< Fifo full interrupt flag */
    kCS_InterruptScanCompleteFlag = CS_INT_SCAN_INT_MASK,          /*!< Scan complete interrupt flag */
} cs_status_flags_t;

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
 * @brief Initialize the CS module.
 *
 * @param base CS peripheral base address.
 * @param config Pointer to configuration structure, see to cs_config_t.
 */
void CS_Init(CS_Type *base);

/*!
 * @brief Deinitialize the CS module.
 *
 * @param base CS peripheral base address.
 */
void CS_DeInit(CS_Type *base);

/*!
 * @brief Gets an available pre-defined settings for initial configuration.
 *
 * This function initializes the initial configuration structure with an available settings. The default values are:
 * @code
 *  config->activeClockDivider = 99U;
 *  config->activeDetectPeriod = 350U;
 *  config->activeIdlePeriod   = 5U;
 *  config->activeOscFreq      = 25U;
 *  config->lowPowerChannelNum = 4U;
 *  config->lowPowerThreshold  = 3150U;
 *  config->lowPowerDebonceNum = 50U;
 *  config->lowPowerIdlePeriod = 20U;
 *  config->lowPowerOscFreq    = 30U;
 * @endcode
 * @param config Pointer to configuration structure.
 */

/*!
 * @brief Clear CS FIFO.
 *
 * @param base CS peripheral base address.
 */
static inline void CS_ClearFifo(CS_Type *base)
{
    base->CTRL0 |= CS_CTRL0_SRST_MASK;
    base->CTRL0 &= ~CS_CTRL0_SRST_MASK;
}

/*!
 * @brief Config CS with specified mode.
 *
 * @param base CS peripheral base address.
 * @param config Pointer to configuration structure, see to cs_config_t.
 * @param mode Choose CS work mode, see to cs_mode_t.
 */
void CS_Config(CS_Type *base, const cs_config_t *config, cs_mode_t mode);

/*!
 * @brief Enable CS.
 *
 * @param base CS peripheral base address.
 */
static inline void CS_Enable(CS_Type *base)
{
    /* Enable CS */
    base->CTRL0 |= CS_CTRL0_ENABLE_MASK;
}

/*!
 * @brief Disable CS.
 *
 * @param base CS peripheral base address.
 */
static inline void CS_Disable(CS_Type *base)
{
    /* Disable CS low power */
    base->LP_CTRL &= ~CS_LP_CTRL_LP_EN_MASK;
    /* Disable CS */
    base->CTRL0 &= ~CS_CTRL0_ENABLE_MASK;
}

/*! @} */

/*!
 * @name Data result.
 * @{
 */

/*!
 * @brief Read the data directly.
 *
 * @param base CS peripheral base address.
 *
 * @return The word read from CS data register.
 */
static inline uint32_t CS_ReadData(CS_Type *base)
{
    return base->DATA;
}

/*! @} */

/*!
 * @name Interrupts.
 * @{
 */

/*!
 * @brief Enables CS interrupts according to the provided mask.
 *
 * @param base CS peripheral base address.
 * @param mask The interrupts to enable. Logical OR of @ref cs_interrupt_enable_t.
 */
extern uint32_t cs_inten;
static inline void CS_EnableInterrupts(CS_Type *base, uint32_t mask)
{
    /*SCAN_INTEN register cannot be read back correctly*/
    cs_inten |= mask;

    base->INTEN = cs_inten;
}

/*!
 * @brief Disables CS interrupts according to a provided mask.
 *
 * @param base CS peripheral base address.
 * @param mask The interrupts to disable. Logical OR of @ref cs_interrupt_enable_t.
 */
static inline void CS_DisableInterrupts(CS_Type *base, uint32_t mask)
{
    /*SCAN_INTEN register cannot be read back correctly*/
    cs_inten &= ~mask;

    base->INTEN = cs_inten;
}

/*! @} */

/*!
 * @name Status.
 * @{
 */

/*!
 * @brief Get status flags of CS module.
 *
 * @param base CS peripheral base address.
 * @return CS status flags which are ORed by the enumerators in the @ref cs_status_flags_t.
 */
static inline uint32_t CS_GetStatusFlags(CS_Type *base)
{
    return base->INT;
}

/*!
 * @brief Clear the CS status flag
 *
 * @param base CS peripheral base address.
 * @param mask The status flags to be cleared, it is logical OR value of @ref cs_status_flags_t.
 */
static inline uint32_t CS_ClearStatusFlags(CS_Type *base, uint32_t mask)
{
    return base->INT = mask;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_CS_H_ */
