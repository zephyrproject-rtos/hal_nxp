/**
*   @file    hse_platform.h
*
*   @brief   HSE platform options.
*   @details This file contains macros used for platform compiler options.
*
*   @addtogroup hse_platform HSE Platform
*   @ingroup class_features_impl
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019-2024 NXP
*
*   Redistribution and use in source and binary forms, with or without modification,
*   are permitted provided that the following conditions are met:
*
*   1. Redistributions of source code must retain the above copyright notice, this list
*      of conditions and the following disclaimer.
*
*   2. Redistributions in binary form must reproduce the above copyright notice, this
*      list of conditions and the following disclaimer in the documentation and/or
*      other materials provided with the distribution.
*
*   3. Neither the name of the copyright holder nor the names of its
*      contributors may be used to endorse or promote products derived from this
*      software without specific prior written permission.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/

#ifndef HSE_PLATFORM_H
#define HSE_PLATFORM_H


#ifdef __cplusplus
extern "C"{
#endif

#include "hse_target.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* ENABLE SPECIFIC FEATURES HERE */
#if (HSE_PLATFORM == HSE_S32G2XX)
    #define HSE_H
    #define HSE_SPT_64BIT_ADDR                  /**< @brief HSE supports 64-bit address. */
    #define HSE_SPT_PHYSICAL_TAMPER_CONFIG      /**< @brief HSE supports the physical tamper configuration. */
    #define HSE_SPT_TEMP_SENS_VIO_CONFIG        /**< @brief HSE supports the temperature sensor configuration. */
    #define HSE_SPT_CMU                         /**< @brief Support for CMU tamper (clock integrity verification) */
    #define HSE_NUM_OF_OTFAD_INSTANCES    (1U)  /**< @brief The supported number of OTFAD Instances */

#elif (HSE_PLATFORM == HSE_S32G3XX)
    #define HSE_H
    #define HSE_SPT_64BIT_ADDR                  /**< @brief HSE supports 64-bit address. */
    #define HSE_SPT_HW_SHA3                     /**< @brief HSE supports SHA3 accelerated in HW. */
    #define HSE_SPT_PHYSICAL_TAMPER_CONFIG      /**< @brief HSE supports the physical tamper configuration. */
    #define HSE_SPT_TEMP_SENS_VIO_CONFIG        /**< @brief HSE supports the temperature sensor configuration. */
    #define HSE_SPT_CMU                         /**< @brief Support for CMU tamper (clock integrity verification) */
    #define HSE_NUM_OF_OTFAD_INSTANCES    (1U)  /**< @brief The supported number of OTFAD Instances */

#elif (HSE_PLATFORM == HSE_S32R45X)
    #define HSE_H
    #define HSE_SPT_64BIT_ADDR                  /**< @brief HSE supports 64-bit address. */
    #define HSE_SPT_TEMP_SENS_VIO_CONFIG        /**< @brief HSE supports the temperature sensor configuration. */
    #define HSE_SPT_CMU                         /**< @brief Support for CMU tamper (clock integrity verification) */
    #define HSE_NUM_OF_OTFAD_INSTANCES    (1U)  /**< @brief The supported number of OTFAD Instances */


#elif (HSE_PLATFORM == HSE_S32S2XX)
    #define HSE_H

#elif (HSE_PLATFORM == HSE_S32ZE)
    #define HSE_H
    #define HSE_SPT_HW_SHA3                          /**< @brief HSE supports SHA3 accelerated in HW. */
    #define HSE_NUM_OF_MU_INSTANCES       (8U)       /**< @brief The maxim number of MU interfaces */
    #define HSE_NUM_OF_OTFAD_INSTANCES    (2U)       /**< @brief The supported number of OTFAD Instances */
    #define HSE_SPT_MSC_KEYSTORE                     /**< @brief Support "Managed Security Component" (MSC) keystore (e.g. ACE key store)*/
    #define HSE_SPT_TRIM_PASSWORD_PROVISION          /**< @brief Support trim password provision */

    #define HSE_SPT_IEE_DDR_FLASH                    /**< @brief Support In Line Decryption of LPDDR4 Flash */

    #ifdef HSE_SPT_IEE_DDR_FLASH
    #define HSE_NUM_OF_IEE_DDR_ENTRIES    (7U)       /**< @brief The supported number of IEE_DDR entries/contexts */
    #endif /* HSE_SPT_IEE_DDR_FLASH */
    #define HSE_SPT_TEMP_SENS_VIO_CONFIG             /**< @brief HSE supports the temperature sensor configuration. */
    #define HSE_SPT_CMU                              /**< @brief Support for CMU tamper (clock integrity verification) */
    #define HSE_SPT_PHYSICAL_TAMPER_CONFIG           /**< @brief HSE supports the physical tamper configuration. */
    #define HSE_STREAM_COUNT              (2U)       /**< @brief HSE stream count per MU interface */
    #define HSE_SPT_SENSOR_ARMING                    /**< @brief Support Sensor Arming/Disarming using SYS_IMG Attribute and On-demand Service. */
#elif (HSE_PLATFORM == HSE_S32Z1XX)
    #define HSE_H
    #define HSE_SPT_HW_SHA3                          /**< @brief HSE supports SHA3 accelerated in HW. */
    #define HSE_NUM_OF_MU_INSTANCES       (8U)       /**< @brief The maxim number of MU interfaces */
    #define HSE_NUM_OF_OTFAD_INSTANCES    (2U)       /**< @brief The supported number of OTFAD Instances */
    #define HSE_SPT_MSC_KEYSTORE                     /**< @brief Support "Managed Security Component" (MSC) keystore (e.g. ACE key store)*/
    #define HSE_SPT_TRIM_PASSWORD_PROVISION          /**< @brief Support trim password provision */
    #define HSE_SPT_TEMP_SENS_VIO_CONFIG             /**< @brief HSE supports the temperature sensor configuration. */
    #define HSE_SPT_CMU                              /**< @brief Support for CMU tamper (clock integrity verification) */
    #define HSE_STREAM_COUNT              (2U)       /**< @brief HSE stream count per MU interface */
#elif (HSE_PLATFORM == HSE_S32R41X)
    #define HSE_M
    #define HSE_SPT_HW_SHA3                     /**< @brief HSE supports SHA3 accelerated in HW. */
    #define HSE_NUM_OF_OTFAD_INSTANCES    (1U)  /**< @brief The supported number of OTFAD Instances */
    #define HSE_SPT_TMU_REG_CONFIG              /**< @brief Support TMU registers configuration  */
    #define HSE_SPT_CMU                         /**< @brief Support for CMU tamper (clock integrity verification) */
    #define HSE_SPT_TMU_CMU                     /**< @brief Support CMU tamper for external TMU on CMU1 (clock integrity verification) */
#elif (HSE_PLATFORM == HSE_SAF85XX)
    #define HSE_M
    #define HSE_NUM_OF_OTFAD_INSTANCES    (1U)              /**< @brief The supported number of OTFAD Instances */
    #define HSE_SPT_HW_SHA3                                 /**< @brief HSE supports SHA3 accelerated in HW. */
    #define HSE_SPT_NXP_RFE_SW                              /**< @brief HSE supports proprietary SW loading to RFE. */
    #define HSE_SPT_TMU_REG_CONFIG                          /**< @brief Support TMU registers configuration. */
    #define HSE_SPT_CMU                                     /**< @brief Support CMU tamper for HSE on CMU0 (clock integrity verification) */
    #define HSE_SPT_TMU_CMU                                 /**< @brief Support CMU tamper for external TMU on CMU1 (clock integrity verification) */
#elif ((HSE_PLATFORM == HSE_S32K3X1)||(HSE_PLATFORM == HSE_S32K3X2)||(HSE_PLATFORM == HSE_S32K3X4)||(HSE_PLATFORM == HSE_S32K3X6)||(HSE_PLATFORM == HSE_S32K358)||(HSE_PLATFORM == HSE_S32K388))
    #define HSE_B
    #define HSE_SPT_CMU                         /**< @brief Support CMU tamper for HSE on CMU0 (clock integrity verification) */
#else
    #error "No platform is selected. At least one platform should be selected."
#endif


#if defined(HSE_H) /* HSE_H common features*/
    #define HSE_SPT_INDIRECT_SYSIMG_ACCESS      /**< @brief Support Indirect SYS-IMG access (refer to HSE FW Reference Manual) */
    #define HSE_SPT_OTP_BOOT_SEQ_ATTR           /**< @brief Enable support for #HSE_OTP_BOOT_SEQ_ATTR_ID attribute. */
#elif defined(HSE_M) /* HSE_M common features */
#elif defined(HSE_B) /* HSE_B common features */
#endif


#if defined(HSE_H)
    #include "hse_h_config.h"
#elif defined(HSE_M)
    #include "hse_m_config.h"
#elif defined(HSE_B)
    #include "hse_b_config.h"
#else
    #error "No HSE HW variant is selected. At least one HSE HW variant should be selected."
#endif


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* HSE_PLATFORM_H */

/** @} */
