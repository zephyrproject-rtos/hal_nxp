/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ACMP_H_
#define FSL_ACMP_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_acmp
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief QN ACMP driver version*/
#define FSL_ACMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/**
 * @brief  Analog comparator channel
 */
typedef enum _acmp_channel
{
    kACMP_Channel0 = 0U, /*!< Analog comparator channel 0 */
    kACMP_Channel1 = 1U, /*!< Analog comparator channel 1 */
} acmp_channel_t;

/**
 * @brief  Analog comparator reference voltage source
 */
typedef enum _acmp_reference_voltage_source
{
    kACMP_ReferenceSourceBandGapVoltage = 0U, /* Analog comparator reference source internal band-gap voltage (VBG) */
    kACMP_ReferenceSourceVcc            = 1U, /* Analog comparator reference source Vcc */
    kACMP_ReferenceSourceExternalReferenceVoltage =
        2U /*Analog comparator reference source external reference voltage */
} acmp_reference_voltage_source_t;

/*!
 * @brief  Analog comparator hysteresis status
 */
typedef enum _acmp_hysteresis
{
    kACMP_HysteresisDisable = 0U, /*!< Analog comparator disable Hysteresis */
    kACMP_HysteresisEnable  = 1U  /*!< Analog comparator enable Hysteresis */
} acmp_hysteresis_t;

/*!
 * @brief  Analog comparator interrupt triger edge
 */
typedef enum _acmp_triger_edge
{
    kACMP_TrigerRising = 0U, /* Interrupt trigered rising edge,the interrupt will be generate while the analog input is
                 more than the user-defined. */
    kACMP_TrigerFailling = 1U, /* Interrupt trigered failing edge,the interrupt will be generate while the analog input
                   is less than the user-defined.*/
    kACMP_TrigerRisingFailling = 2U /* Interrupt trigered both rising and failing edge */
} acmp_triger_edge_t;

/**
 * @brief  Analog comparator reference voltage divider
 */
typedef enum _acmp_reference_voltage_divider
{
    kACMP_ReferenceVoltageDivider1 = 1U, /*!< Set reference valtage to 1/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider2,      /*!< Set reference valtage to 2/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider3,      /*!< Set reference valtage to 3/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider4,      /*!< Set reference valtage to 4/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider5,      /*!< Set reference valtage to 5/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider6,      /*!< Set reference valtage to 6/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider7,      /*!< Set reference valtage to 7/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider8,      /*!< Set reference valtage to 8/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider9,      /*!< Set reference valtage to 9/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider10,     /*!< Set reference valtage to 10/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider11,     /*!< Set reference valtage to 11/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider12,     /*!< Set reference valtage to 12/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider13,     /*!< Set reference valtage to 13/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider14,     /*!< Set reference valtage to 14/16 Band-Gap Voltage or Vcc */
    kACMP_ReferenceVoltageDivider15,     /*!< Set reference valtage to 15/16 Band-Gap Voltage or Vcc */
} acmp_reference_voltage_divider_t;

/*! @brief Describes ACMP configuration structure. */
typedef struct _acmp_config
{
    acmp_channel_t ch;                       /*!<Analog comparator channel */
    acmp_reference_voltage_source_t refSrc;  /*!<Analog comparator reference voltage source */
    acmp_reference_voltage_divider_t refDiv; /*!<Analog comparator reference voltage divider */
    acmp_hysteresis_t hystEn;                /*!<Analog comparator hysteresis */
    acmp_triger_edge_t trigerEdge;           /*!<Analog comparator channel */
} acmp_config_t;
/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*!
 * @brief Initializes the ACMP with configuration.
 *
 * This function configures the ACMP module with the user-defined settings.
 * @param base ACMP peripheral base address.
 * @param config pointer to configuration structure
 */
void ACMP_Init(SYSCON_Type *base, const acmp_config_t *config);

/*!
 * @brief Enable the ACMP module.
 *
 * This function enable the ACMP module.
 * @param base ACMP peripheral base address.
 * @param ch  Specified the channel to be enabled
 */
void ACMP_Enable(SYSCON_Type *base, acmp_channel_t ch);

/*!
 * @brief Disable the ACMP module.
 *
 * This function disable the ACMP module.
 * @param base ACMP peripheral base address.
 * @param ch  Specified the channel to be disabled
 */
void ACMP_Disable(SYSCON_Type *base, acmp_channel_t ch);

/*!
 * @brief Enables the ACMP interrupt.
 *
 * This function enables the ACMP interrupt.
 *
 * @param base ACMP peripheral base address.
 * @param ch  Specified the channel.
 */
void ACMP_EnableInterrupts(SYSCON_Type *base, acmp_channel_t ch);

/*!
 * @brief Disables the ACMP interrupt.
 *
 * This function disables the ACMP interrupt.
 *
 * @param base ACMP peripheral base address.
 * @param ch  Specified the channel
 */
void ACMP_DisableInterrupts(SYSCON_Type *base, acmp_channel_t ch);

/*!
 * @brief Get the ACMP value
 *
 * This function get ACMP output value.
 *
 * @param base ACMP peripheral base address.
 * @param ch  Specified the channel
 * @return acmp value
 */
uint8_t ACMP_GetValue(SYSCON_Type *base, acmp_channel_t ch);

/*!
 * @brief Disable the ACMP module
 *
 * This function disable the ACMP module.
 * @param base ACMP peripheral base address.
 */
static inline void ACMP_Deinit(SYSCON_Type *base)
{
    base->ANA_EN &= ~(SYSCON_ANA_EN_ACMP0_EN_MASK | SYSCON_ANA_EN_ACMP1_EN_MASK);
}

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the ACMP configuration structure to a default value. The default
 * values are:
 *   config->ch = kACMP_Channel0;
 *   config->refSrc = kACMP_ReferenceSourceExternalReferenceVoltage;
 *   config->hystEn = kACMP_HysteresisDisable;
 *   config->trigerEdge = kACMP_TrigerRising;
 *   config->refDiv = kACMP_ReferenceVoltageDivider1;
 * @param config Pointer to configuration structure.
 */
void ACMP_GetDefaultConfig(acmp_config_t *config);
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_ACMP_H_*/
