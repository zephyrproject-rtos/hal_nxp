/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_QDEC_H_
#define FSL_QDEC_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_qdec
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name QDEC Driver version */
/*! @{ */
/*! @brief QDEC driver version*/
#define FSL_QDEC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/** @defgroup qdec_sample_clock */
typedef enum _qdec_sample_clock_divider
{
    kQDEC_SampleClockDivider1       = 0U,  /*!< Sample clock divider 1*/
    kQDEC_SampleClockDivider2       = 1U,  /*!< Sample clock divider 2*/
    kQDEC_SampleClockDivider4       = 2U,  /*!< Sample clock divider 4*/
    kQDEC_SampleClockDivider8       = 3U,  /*!< Sample clock divider 8*/
    kQDEC_SampleClockDivider16      = 4U,  /*!< Sample clock divider 16*/
    kQDEC_SampleClockDivider32      = 5U,  /*!< Sample clock divider 32*/
    kQDEC_SampleClockDivider64      = 6U,  /*!< Sample clock divider 64*/
    kQDEC_SampleClockDivider128     = 7U,  /*!< Sample clock divider 128*/
    kQDEC_SampleClockDivider256     = 8U,  /*!< Sample clock divider 256*/
    kQDEC_SampleClockDivider512     = 9U,  /*!< Sample clock divider 512*/
    kQDEC_SampleClockDivider1024    = 10U, /*!< Sample clock divider 1024*/
    kQDEC_SampleClockDivider2048    = 11U, /*!< Sample clock divider 2048*/
    kQDEC_SampleClockDivider4096    = 12U, /*!< Sample clock divider 4096*/
    kQDEC_SampleClockDivider8192    = 13U, /*!< Sample clock divider 8192*/
    kQDEC_SampleClockDivider16384   = 14U, /*!< Sample clock divider 16384*/
    kQDEC_SampleClockDivider32768   = 15U, /*!< Sample clock divider 32768*/
    kQDEC_SampleClockDivider65536   = 16U, /*!< Sample clock divider 65536*/
    kQDEC_SampleClockDivider131072  = 17U, /*!< Sample clock divider 131072*/
    kQDEC_SampleClockDivider262144  = 18U, /*!< Sample clock divider 262144*/
    kQDEC_SampleClockDivider524288  = 19U, /*!< Sample clock divider 524288*/
    kQDEC_SampleClockDivider1048576 = 20U, /*!< Sample clock divider 1048576*/
} qdec_sample_clock_divider_t;

/*! @brief qdec_debounce_filter_div */
typedef enum _qdec_debounce_filter_divider
{
    kQDEC_DebounceFilterDivider1  = 0U, /*!< Debounce filter sample clock divider 1*/
    kQDEC_DebounceFilterDivider2  = 1U, /*!< Debounce filter sample clock divider 2*/
    kQDEC_DebounceFilterDivider4  = 2U, /*!< Debounce filter sample clock divider 4*/
    kQDEC_DebounceFilterDivider8  = 3U, /*!< Debounce filter sample clock divider 8 */
    kQDEC_DebounceFilterDivider16 = 4U, /*!< Debounce filter sample clock divider 16 */
    kQDEC_DebounceFilterDivider32 = 5U, /*!< Debounce filter sample clock divider 32 */
    kQDEC_DebounceFilterDivider64 = 6U, /*!< Debounce filter sample clock divider 64 */
    kQDEC_DebounceFilterDivNone   = 7U  /*!< Debounce filter sample clock divide */
} qdec_debounce_filter_divider_t;

/*! @brief qdec_sample_point */
typedef enum _qdec_sample_point
{
    kQDEC_SamplePoint1   = 12U, /*!< Total sample points 1 */
    kQDEC_SamplePoint5   = 0U,  /*!< Total sample points 5 */
    kQDEC_SamplePoint10  = 1U,  /*!< Total sample points 10 */
    kQDEC_SamplePoint40  = 2U,  /*!< Total sample points 40 */
    kQDEC_SamplePoint80  = 3U,  /*!< Total sample points 80 */
    kQDEC_SamplePoint120 = 4U,  /*!< Total sample points 120 */
    kQDEC_SamplePoint160 = 5U,  /*!< Total sample points 160 */
    kQDEC_SamplePoint200 = 6U,  /*!< Total sample points 200 */
    kQDEC_SamplePoint240 = 7U,  /*!< Total sample points 240 */
    kQDEC_SamplePoint280 = 8U,  /*!< Total sample points 280 */
    kQDEC_SamplePoint320 = 9U,  /*!< Total sample points 320 */
    kQDEC_SamplePoint360 = 10U, /*!< Total sample points 360 */
    kQDEC_SamplePoint400 = 11U  /*!< Total sample points 400 */
} qdec_sample_point_t;

/*!
 * @brief QDEC interrupt configuration structure, default settings all disabled.
 */
enum _qdec_interrupt_enable
{
    kQDEC_DBOverflowInterruptEnable = (QDEC_INTEN_DB_OF_INTEN_MASK), /*!< Double transition accumulator overflow.*/
    kQDEC_ACCOverflowInterruptEnable =
        (QDEC_INTEN_ACC_OF_INTEN_MASK), /*!< Valid sample accumulator overflow or underflow */
    kQDEC_SampleEndInterruptEnable = (QDEC_INTEN_SAMPLE_END_INTEN_MASK), /*!< Sample end event triggered.*/
    kQDEC_SingleSampleInterruptEnable =
        (QDEC_INTEN_SINGLE_SAMPLE_INTEN_MASK), /*!< The interrupt will be generate When each normal sample is done*/
};

/*Flash configuration structure*/
typedef struct _qdec_config
{
    qdec_sample_clock_divider_t sampleClockDiv;       /*!< Sample clock divider*/
    qdec_sample_point_t samplePoint;                  /*!< Total sample points*/
    qdec_debounce_filter_divider_t debounceFilterDiv; /*!< Debounce filter sample clock divide */
    bool autoClearEnable; /*!< true - Software can get ACC value from ACC_R register directly. false - Software need to
                             set SOFT_CLR bit to grasp ACC to ACC_R.*/
} qdec_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*!
 * @brief Initializes the QDEC with configuration.
 *
 * This function configures the QDEC module with the user-defined settings.
 * @param base QDEC peripheral base address.
 * @param config  pointer to QDEC config structure
 */
void QDEC_Init(QDEC_Type *base, const qdec_config_t *config);

/*!
 * @brief Disable the QDEC module
 *
 * This function disable the QDEC module.
 * @param base QDEC peripheral base address.
 */
void QDEC_Deinit(QDEC_Type *base);

/*!
 * @brief  Gets the default configuration structure.
 *
 * This function initializes the QDEC configuration structure to a default value. The default
 * values are:
 *  config->samplePoint = kQDEC_SamplePoint40;
 *  config->sampleClockDiv = kQDEC_SampleClockDivider1;
 *  config->debounceFilterDiv = kQDEC_DebounceFilterDivider1;
 *  config->autoClearEnable = true;
 * @param config pointer to QDEC config structure
 */
void QDEC_GetDefaultConfig(qdec_config_t *config);

/*!
 * @brief Read QDEC accumulator result
 *
 * This function read  QDEC accumulator result.
 * @param base QDEC peripheral base address.
 */
static inline int16_t QDEC_ReadAccumulatorResult(QDEC_Type *base)
{
    return base->ACC_R;
}

/*!
 * @brief Start QDEC operation
 *
 * This function start QDEC operation.
 * @param base QDEC peripheral base address.
 */
static inline void QDEC_Start(QDEC_Type *base)
{
    base->CTRL |= QDEC_CTRL_START_MASK;
}

/*!
 * @brief Stop QDEC operation
 *
 * This function stop QDEC operation.
 * @param base QDEC peripheral base address.
 */
static inline void QDEC_Stop(QDEC_Type *base)
{
    base->CTRL |= QDEC_CTRL_STOP_MASK;
}

/*!
 * @brief Trigger a software clear operation
 *
 * This function trigger a software clear operation.
 * @param base QDEC peripheral base address.
 */
static inline void QDEC_SoftClear(QDEC_Type *base)
{
    base->CTRL |= QDEC_CTRL_SOFT_CLR_MASK;
}

/*!
 * @brief Get QDEC status flags.
 *
 * This function get QDEC status flags.
 * @param base QDEC peripheral base address.
 * @return FLASH status flags.
 */
static inline uint32_t QDEC_GetStatusFlags(QDEC_Type *base)
{
    return base->INT;
}

/*!
 * @brief Clears status flags with the provided mask.
 *
 * This function clears QDEC status flags with the provided mask.
 * @param base QDEC peripheral base address.
 * @param mask The status flags to be cleared
 */
static inline void QDEC_ClearStatusFlags(QDEC_Type *base, uint32_t mask)
{
    base->INT = mask;
}

/*!
 * @brief Enables the QDEC interrupt.
 *
 * This function enables the QDEC interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See @ref _qdec_interrupt_enable.
 *
 * @param base QDEC peripheral base address.
 * @param mask interrupt source.
 */
static inline void QDEC_EnableInterrupts(QDEC_Type *base, uint32_t mask)
{
    base->INTEN |= mask;
}

/*!
 * @brief Disables the QDEC interrupt.
 *
 * This function disables the QDEC interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See @ref _qdec_interrupt_enable.
 *
 * @param base QDEC peripheral base address.
 * @param mask interrupt source.
 */
static inline void QDEC_DisableInterrupts(QDEC_Type *base, uint32_t mask)
{
    base->INTEN &= ~mask;
}

/*!
 * @brief Get QDEC busy status flags.
 *
 * This function get QDEC busy status flags.
 * @param base QDEC peripheral base address.
 * @return QDEC busy status flags.
 */
static inline uint32_t QDEC_GetBusyStatusFlags(QDEC_Type *base)
{
    return base->STAT;
}

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_QDEC_H_*/
