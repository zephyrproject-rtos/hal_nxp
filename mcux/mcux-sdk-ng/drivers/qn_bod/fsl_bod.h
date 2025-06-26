/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_BOD_H_
#define FSL_BOD_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_bod
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name BOD Driver version */
/*! @{ */
/*! @brief BOD driver version */
#define FSL_BOD_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief BOD interrupt threshold voltages */
typedef enum _bod_interrupt_threshold
{
    kBOD_InterruptThreshold0 = 0U, /*!< trigger at 2.06V*/
    kBOD_InterruptThreshold1,      /*!< trigger at 2.45V*/
    kBOD_InterruptThreshold2,      /*!< trigger at 2.72V*/
    kBOD_InterruptThreshold3,      /*!< trigger at 3.04V*/
} bod_interrupt_threshold_t;

/*! @brief BOD reset threshold voltages */
typedef enum _bod_reset_threshold
{
    kBOD_ResetThreshold0 = 0U, /*!< trigger at 1.5V*/
    kBOD_ResetThreshold1,      /*!< trigger at 1.85V*/
    kBOD_ResetThreshold2,      /*!< trigger at 2.0V*/
    kBOD_ResetThreshold3,      /*!< trigger at 3.0V*/
} bod_reset_threshold_t;

typedef enum _bod_mode
{
    kBOD_InterruptEnable = 1U, /*!< interrupt enable*/
    kBOD_ResetEnable     = 2U  /*!< reset enable*/
} bod_mode_t;

/*! @brief Describes BOD configuration structure. */
typedef struct _bod_config
{
    bod_interrupt_threshold_t int_thr;
    bod_reset_threshold_t reset_thr;
} bod_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*!
 * @brief Initializes the BOD with configuration.
 *
 * This function configures the BOD module with the user-defined settings.
 * @param base BOD peripheral base address.
 * @param config pointer to configuration structure
 */
void BOD_Init(SYSCON_Type *base, const bod_config_t *config);

/*!
 * @brief Disable the BOD module
 *
 * This function disable the BOD module.
 * @param base BOD peripheral base address.
 */
void BOD_Deinit(SYSCON_Type *base);

/*!
 * @brief Enable the BOD module.
 *
 * This function enable the ACMP module.
 * @param base BOD peripheral base address.
 * @param mode  Specified the work mode to be enabled.The mode is a logical OR of
 * the enumeration members. see @ref bod_mode_t
 */
void BOD_Enable(SYSCON_Type *base, uint8_t mode);

/*!
 * @brief Disable the BOD module.
 *
 * This function enable the BOD module.
 * @param base BOD peripheral base address.
 * @param mode  Specified the work mode to be disabled.The mode is a logical OR of
 * the enumeration members. see @ref bod_mode_t
 */
void BOD_Disable(SYSCON_Type *base, uint8_t mode);

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the BOD configuration structure to a default value. The default
 * values are:
 *   config->int_thr = kBOD_InterruptThreshold2;
 *   config->reset_thr = kBOD_ResetThreshold2;
 * @param config Pointer to configuration structure.
 */
void BOD_GetDefaultConfig(bod_config_t *config);
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_BOD_H_*/
