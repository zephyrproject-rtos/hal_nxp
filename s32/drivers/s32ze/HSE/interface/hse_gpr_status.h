/**
*   @file    hse_gpr_status.h
*
*   @brief   HSE GPR Status
*   @details This file contains the HSE GPR Status
*
*   @addtogroup hse_gpr HSE GPR Status
*   @ingroup class_interface
*   @{
*/
/*==================================================================================================
*
*   Copyright 2022-2024 NXP
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
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_GPR_STATUS_H
#define HSE_GPR_STATUS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "std_typedefs.h"
#include "hse_platform.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

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


#if defined(HSE_H)
    #if (HSE_PLATFORM == HSE_S32ZE) || (HSE_PLATFORM == HSE_S32Z1XX)
    #define HSE_GPR_STATUS_ADDRESS                 (0x42280028UL)   /**< @brief HSE-GPR REG3 is in Security subsystem registers Description (refer to #hseTamperConfigStatus_t) */
    #else
    #define HSE_GPR_STATUS_ADDRESS                 (0x4007C928UL)   /**< @brief HSE-GPR REG3 is in Security subsystem registers Description (refer to #hseTamperConfigStatus_t)*/
    #endif
#endif /* HSE_H */

#if defined(HSE_M)

    #if (HSE_PLATFORM == HSE_S32R41X)
    #define HSE_GPR_STATUS_ADDRESS                 (0x400D8928UL)   /**< @brief HSE-GPR REG3 is in Security subsystem registers Description (refer to #hseTamperConfigStatus_t)*/
    #else
    #define HSE_TMU_BIST_MODE_TEST_BJT_CORE_SEQ1   (0x400D8940UL)   /**< @brief HSE-GPR REG9 is in Security subsystem registers Description, <br>
                                                                                Sequence 1 - To get the XOUT value in BIST mode BJT Core,
                                                                                             This result is denoted as XOUTbist. */
    #define HSE_TMU_BIST_MODE_TEST_BJT_CORE_SEQ2   (0x400D8944UL)   /**< @brief HSE-GPR REG10 is in Security subsystem registers Description, <br>
                                                                                Sequence 2 - To get the XOUT value in temperature acquisition mode.
                                                                                             This result is denoted as XOUT. */
    #define HSE_TMU_BIST_MODE_TEST_ADC_OUTPUT      (0x400D8948UL)   /**< @brief HSE-GPR REG11 is in Security subsystem registers Description, <br>
                                                                                Read the adcout data for BIST mode test ADC, <br>
                                                                                The obtained (ADCout / 32768.0) has to be approximately equal to 0.4 */
    #endif /* HSE_S32R41X */

    #if (HSE_PLATFORM == HSE_SAF85XX)
    /** @brief    HSE XOSC Switch Status bits (register address is #HSE_GPR_XOSC_CLK_SWITCH_STATUS_ADDRESS) */
    #define HSE_GPR_XOSC_CLK_SWITCH_STATUS_ADDRESS (0x400D8950UL)   /**< @brief HSE-GPR REG13 is in Security subsystem registers Description */

    typedef uint32_t hseXoscClkSwitchStatus_t;
    #define HSE_XOSC_CLK_SWITCH_NOT_RUN_STATUS     ((hseXoscClkSwitchStatus_t)0U)       /**< @brief HSE-GPR REG13[2:1] = 00b when XOSC clock switch not run */
    #define HSE_XOSC_CLK_SWITCH_FAIL_STATUS        ((hseXoscClkSwitchStatus_t)1U << 1U) /**< @brief HSE-GPR REG13[2:1] = 01b; this bit is set when the XOSC clock switch is failed */
    #define HSE_XOSC_CLK_SWITCH_SUCCESS_STATUS     ((hseXoscClkSwitchStatus_t)1U << 2U) /**< @brief HSE-GPR REG13[2:1] = 10b; this bit is set when the XOSC clock switch is successful */
    #endif /* HSE_PLATFORM == HSE_SAF85XX */
#endif /* HSE_M */

#if defined(HSE_B)
    /** @brief    CONFIG_REG4 is in Configuration GPR Description (refer to #hseTamperConfigStatus_t and #hseEccErrorStatus_t).
                  This register is to inform the application that there is a loss of data due to ECC error and user needs necessary action.
     */
    #define HSE_GPR_STATUS_ADDRESS                 (0x4039C02CUL)

    /** @brief    HSE SYS-IMG Dataset Erase Status bits (register address is #HSE_GPR_STATUS_ADDRESS)
     *  @details  This status is updated when a particular dataset has been erased by HSE Firmware because of
     *            corruption due to ECC error (this can happen if a reset occurred during a flash programming/erase operation),
     *            or because some invalid data was found.
     */
    typedef uint32_t hseEccErrorStatus_t;

    #define HSE_ECC_KEYSTORE_STATUS                 ((hseEccErrorStatus_t)1U << 16U) /**< @brief CONFIG_REG4[16] - This bit is set when the key store area is erased. */
    #define HSE_ECC_CONFIG_DATA_STATUS              ((hseEccErrorStatus_t)1U << 17U) /**< @brief CONFIG_REG4[17] - This bit is set when the config data area is erased. */
    #define HSE_ECC_MONOTONIC_COUNTER_STATUS        ((hseEccErrorStatus_t)1U << 18U) /**< @brief CONFIG_REG4[18] - This bit is set when the monotonic counter area is erased. */
#endif /* HSE_B */



#if (HSE_PLATFORM != HSE_SAF85XX)
    /** @brief    HSE Tamper Config Status bits (register address is #HSE_GPR_STATUS_ADDRESS)
     *  @details  This status is updated when a tamper is configured by HSE during initialization or via attribute.
     *            The host can get the HSE Tamper Config Status reading the #HSE_GPR_STATUS_ADDRESS register.
     *            In this way, the host to check what tampers are configured.
     *            The #HSE_GPR_STATUS_ADDRESS register is read-only.
     *            @note
     *            - For HSE_H/S32R41, HSE-GPR REG3 used.
     *            - For HSE_B,   CONFIG_REG4 used.
     */
    typedef uint32_t hseTamperConfigStatus_t;
    #if defined(HSE_SPT_CMU)
    #define HSE_CMU_TAMPER_CONFIG_STATUS        ((hseTamperConfigStatus_t)1U << 0U) /**< @brief HSE-GPR REG3[0]- this bit is set when the CMU tamper is configured:
                                                                                                - For HSE_H, the clock must be configured in this range:
                                                                                                    10Mhz < clock frequency < 420Mhz.
                                                                                                - For HSE_B, the clock must be configured in this range:
                                                                                                    3Mhz < clock frequency < 126Mhz.
                                                                                                - For HSE_M, the clock must be configured in this range:
                                                                                                    - s32r41x: 45.6Mhz < clock frequency < 420Mhz. */
    #endif /* HSE_SPT_CMU */

    #ifdef HSE_SPT_PHYSICAL_TAMPER_CONFIG
    #define HSE_PHYSICAL_TAMPER_CONFIG_STATUS    ((hseTamperConfigStatus_t)1U << 1U) /**< @brief HSE-GPR REG3[1]- this bit is set when the physical tamper is configured.
                                                                                                Note that the application must configure SIUL2 Pads before enabling the tamper. */
    #endif /* HSE_SPT_PHYSICAL_TAMPER_CONFIG */

    #if (defined(HSE_SPT_TEMP_SENS_VIO_CONFIG) || defined(HSE_SPT_TMU_REG_CONFIG))
    #define HSE_TEMP_SENSOR_VIO_CONFIG_STATUS    ((hseTamperConfigStatus_t)1U << 2U) /**< @brief HSE-GPR REG3[2] this bit is set when the
                                                                                                 temperature sensor violation is configured. */
    #endif /* HSE_SPT_TEMP_SENS_VIO_CONFIG || HSE_SPT_TMU_REG_CONFIG */

    #if defined(HSE_SPT_TMU_CMU)
    #define TMU_CMU_TAMPER_CONFIG_STATUS         ((hseTamperConfigStatus_t)1U << 3U) /**< @brief HSE-GPR REG3[3]- this bit is set when the TMU_CMU tamper is configured.
                                                                                                 The TMU clock must be configured in this range
                                                                                                 - s32r41x: 11.4Mhz  < clock frequency < 131.25Mhz. */
    #endif /* HSE_SPT_TMU_CMU */

    #if defined(HSE_SPT_LVDHVD)
    #define HSE_LVD_HVD_TAMPER_CONFIG_STATUS     ((hseTamperConfigStatus_t)1U << 4U) /**< @brief HSE-GPR REG3[4] this bit is set when the
                                                                                                 voltage tamper violation is configured. */
    #endif /* HSE_SPT_LVDHVD */

    #if defined(HSE_SPT_GDET)
    #define HSE_GDET_TAMPER_CONFIG_STATUS        ((hseTamperConfigStatus_t)1U << 5U) /**< @brief HSE-GPR REG3[5] this bit is set when the
                                                                                                 HW glitch detector(GDET) tamper violation is configured. */
    #endif /* HSE_SPT_GDET */

#endif /* (HSE_PLATFORM != HSE_SAF85XX) */

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

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_GPR_STATUS_H */

/** @} */
