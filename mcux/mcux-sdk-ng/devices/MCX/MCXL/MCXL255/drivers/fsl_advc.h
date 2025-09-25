/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_ADVC_H
#define _FSL_ADVC_H

#include "fsl_common.h"

/*!
 * @addtogroup ADVC
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief advc driver version 2.0.1. */
#define FSL_ADVC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*!
 * @brief The enumeration of ADVC operation result.
 *
 */
typedef enum _advc_result
{
    kADVC_Stat_Ok                     = 0U,  /*!< ADVC Run Well. */
    kADVC_Stat_Init                   = 1U,  /*!< ADVC is initialized. */
    kADVC_Stat_SafeDoneFailed         = 2U,  /*!< Fail to set ADVC as safe mode. */
    kADVC_Stat_Timeout                = 3U,  /*!< ADVC status done condition was not set before timeout */
    kADVC_Stat_RingoMeasureFailed     = 4U,  /*!< Fail to measure ringo. */
    kADVC_Stat_FFMeasureFailed        = 5U,  /*!< First fail measurement failed. */
    kADVC_Stat_OptimalFailed          = 6U,  /*!< ADVC set optimal ended with error. */
    kADVC_Stat_BadSignature           = 7U,  /*!< Wrong ADVC table. */
    kADVC_Stat_NotEnabled             = 8U,  /*!< when trying to manipulate advc frequencies before it's enabled. */
    kADVC_Stat_PreVoltageReqestFailed = 9U,  /*!< when pre-voltage request change is reaching timeout. */
    kADVC_Stat_IllegalOperation       = 10U, /*!< When using illegal operation mode in ADVC_ENABLE. */
} advc_result_t;

/*!
 * @brief The enumeration of ADVC mode.
 *
 */
typedef enum _advc_mode
{
    kADVC_ModeSafe    = 0U, /*!< Set ADVC work as safe mode. */
    kADVC_ModeOptimal = 2U, /*!< Set ADVC work as optimal mode. */
} advc_mode_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif
#if __CORTEX_M == 33U
/*!
 * @brief Load advc configuration table and initialize ADVC.
 */
void ADVC_Init(void);
#endif /* __CORTEX_M == 33U */

/*!
 * @brief Check if ADVC is initialized.
 *
 * @retval false ADVC is not initialized.
 * @retval true ADVC is initialized.
 */
bool ADVC_IsInitialized(void);

/*!
 * @brief Enable ADVC
 *
 * @param[in] mode Specify the mode of advc, please refer to @ref advc_mode_t.
 * @param[out] vddCode The value of VDD_AON, NULL means do not care voltage of VDD_AON.
 *
 * @return The result outcome with enabling ADVC.
 */
advc_result_t ADVC_Enable(advc_mode_t mode, uint8_t *vddCode);

/*!
 * @brief Check if ADVC is enabled.
 *
 * @retval false ADVC is not enabled.
 * @retval true ADVC is enabled.
 */
bool ADVC_IsEnabled(void);

/*!
 * @brief Disable ADVC.
 */
void ADVC_Disable(void);

/*!
 * @brief Check if ADVC is disabled.
 *
 * @retval true ADVC is not disabled.
 * @retval false ADVC is enabled.
 */
bool ADVC_IsDisabled(void);

/*!
 * @brief Request to change frequency.
 *
 * @note This should be done every time we want to change frequency of any ADVC related clock.
 * @note  Pre Voltage request should be called before any clock change which is derived from CGU.
 * The paramter we pass is the the future cpu frequency, since we move to safe voltage according to that.
 *
 * @param aonCpuFreq The frequency of AON CPU, only 10MHz, 5MHz, 3.3MHz, 2.5MHz, 2MHz, 1MHz are allowed.
 *
 * @return The result outcome with requesting to change frequency.
 */
advc_result_t ADVC_PreVoltageChangeRequest(uint32_t aonCpuFreq);

/*!
 * @brief Move back to optimal after changing any ADVC related clock frequency.
 *
 * @return The observed result following the post-frequency change.
 */
advc_result_t ADVC_PostVoltageChangeRequest(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* __FSL_ADVC_H */
