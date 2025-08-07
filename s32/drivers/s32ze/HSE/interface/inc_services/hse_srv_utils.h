/**
*   @file    hse_srv_utils.h
*
*   @brief   HSE Utility services definition.
*   @details This file contains the HSE Utility services definition:
*            cancel, error logs etc
*
*   @addtogroup hse_srv_utils HSE Utility Services
*   @ingroup class_admin_services
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019 - 2024 NXP.
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

#ifndef HSE_SRV_UTILS_H
#define HSE_SRV_UTILS_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"
#include "hse_srv_attr.h"

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
#ifdef HSE_SPT_FLASHLESS_DEV /* HSE_H/M device */
/** @brief    Mask value that specifies the counterpart of the anti-rollback counter (SYS-IMG or FW-IMG).
 *  @details  Selects the counterpart of the anti-rollback counter that will be updated when calling
 *            #hseOnDemandAntiRbcUpdateSrv_t service.
 */
typedef uint32_t hseAntiRbcMask_t;
#define HSE_SYS_IMG_ANTI_RBC_MASK           ((hseAntiRbcMask_t)(0x00005F51UL))    /**< @brief SYS-IMG counter mask */
#define HSE_FW_IMG_ANTI_RBC_MASK            ((hseAntiRbcMask_t)(0xF31C0000UL))    /**< @brief FW-IMG counter mask */
#define HSE_SYS_FW_IMG_ANTI_RBC_MASK        ((hseAntiRbcMask_t)(0xF31C5F51UL))    /**< @brief Both SYS-IMG and FW-IMG counters mask */
#endif /* HSE_SPT_FLASHLESS_DEV */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef HSE_SPT_FLASHLESS_DEV /* HSE_H/M device */
/** @brief   On demand anti-rollback counter update service.
 *  @details The service can be used only if the anti-rollback counter policy disableOtpRollbackProtect (see #hseOtpRollbackProtectionPolicy_t)
 *           is set to #HSE_ON_DEMAND_ANTI_RBC_UPDATE (otherwise, it returns HSE_SRV_RSP_NOT_ALLOWED).
 *           If the anti-rollback counter is already updated, it returns HSE_SRV_RSP_OK.
 *           @note:
 *           The SYS-IMG should be properly stored to external flash, then sucessfully loaded and authenticated by HSE before calling this service.
 *           This ensures that the SYS-IMG was not corrupted before burning the fuses.
 *           The VDD_EFUSE must be powered before calling this service.
 */
typedef struct
{
    /** @brief   INPUT: Specifies the mask value that selects the counterpart of the anti-rollback counter
     *                  that will be updated (SYS-IMG or FW-IMG).
     *                  Select either one option or both simultaneously, depending on the use case.
     * */
    hseAntiRbcMask_t hseAntiRollbackCounterMask;
} hseOnDemandAntiRbcUpdateSrv_t ;
#endif /* HSE_SPT_FLASHLESS_DEV */

/** @brief HSE Cancel service.
 *  @details This service cancels a HSE one-pass and streaming service that was sent on a specific channel.
 *
 * @note
 *      - The requests with the service ID that starts with 0x00A5XXXX can not be canceled.
 *      - Cancel requests cannot be canceled (by a subsequent request);
 */
typedef struct
{
    /** @brief   INPUT: The channel Index of MU interface [0..#HSE_NUM_OF_CHANNELS_PER_MU). <br>
     *                  The muChannelIdx and the MU channel on which the service is sent, must belong to
     *                  the same MU Interface. Otherwise an #HSE_SRV_RSP_INVALID_PARAM error will be reported. */
    uint8_t  muChannelIdx;
    uint8_t  reserved[3];
} hseCancelSrv_t;

#ifdef HSE_SPT_STREAM_CTX_IMPORT_EXPORT

/** @brief The maximum size of the streaming context for any operation. */
#define MAX_STREAMING_CONTEXT_SIZE                (372UL)

/** @brief   Streaming Context Operation: Import/Export. */
typedef uint8_t hseStreamContextOp_t;
#define HSE_IMPORT_STREAMING_CONTEXT    ((hseStreamContextOp_t)1U)    /**< @brief Import streaming context */
#define HSE_EXPORT_STREAMING_CONTEXT    ((hseStreamContextOp_t)2U)    /**< @brief Export streaming context */

/** @brief   HSE Import/Export Streaming Context service.
 *  @details This service allows import/export of a streaming context used in an on-going streaming operation (e.g. Hash, MAC, Cipher, AEAD, etc). <br>
 *           The streaming context will be imported/exported as a blob (encrypted with a device specific key).
 */
typedef struct
{
    /** @brief   INPUT: Specifies the operation to be performed with the streaming context: Import/Export. */
    hseStreamContextOp_t    operation;
    /** @brief   INPUT: Specifies the stream to be exported or overwritten if imported. Note that each interface supports
     *                  up to #HSE_STREAM_COUNT streams per interface. */
    hseStreamId_t           streamId;
    uint8_t                 reserved[2];
    /** @brief   OUTPUT/INPUT: The output buffer where the streaming context will be copied (export) or
     *                         the input buffer from which HSE will copy the streaming context (import).
     *                         Length of the buffer should be at least #MAX_STREAMING_CONTEXT_SIZE bytes.
     *                         A streaming context can be imported or exported on the same MU instance on which the streaming START step was called
     *                         (e.g. the steaming context is allocated when the START step is called)."*/
    HOST_ADDR               pStreamContext;
} hseImportExportStreamCtxSrv_t;

#endif /* HSE_SPT_STREAM_CTX_IMPORT_EXPORT */

/**
 * @brief    Prepare the security subsytem (BootROM + HSE) for Stand-By.
 * @details  This service is used for updating the internal state of HSE before system goes in Stand-By mode.
 *           Applicable only for flashless devices (HSE_H/M variants).
 *           This service can be called only once per running state, otherwise HSE will return #HSE_SRV_RSP_NOT_ALLOWED.
 */
#if defined(HSE_SPT_FLASHLESS_DEV)
typedef struct
{
    uint8_t          reserved[4U];
} hsePrepareForStandBySrv_t;
#endif /* HSE_SPT_FLASHLESS_DEV */

#ifdef HSE_SPT_INTERNAL_FLASH_DEV
/**
 * @brief    Erase SYS-IMG in Data Flash.
 * @details  This service is used for erasing SYS-IMG in HSE Data Flash.
 *           The service is available for flash based devices only (HSE_B variant).
 *           Can be performed only in CUST_DEL life cycle, otherwise #HSE_SRV_RSP_NOT_ALLOWED error will be reported.
 */
typedef struct
{
    uint8_t          reserved[4];
} hseEraseNvmDataSrv_t;
#endif /* HSE_SPT_INTERNAL_FLASH_DEV */

#ifdef HSE_SPT_ERASE_FW
/**
 * @brief    Erase HSE Firmware from the device.
 * @details  This service is used for erasing the HSE Firmware.
 *           This service also erases the SYS-IMG and backup (if present) in the secure flash from the device.
 *           The service is available for flash based devices only (HSE_B variant).
 *           Can be performed only in CUST_DEL life cycle, otherwise #HSE_SRV_RSP_NOT_ALLOWED error will be reported.
 */
typedef struct
{
    uint8_t          reserved[4];
} hseEraseFwSrv_t;
#endif /* HSE_SPT_ERASE_FW */

#ifdef HSE_SPT_TRIM_PASSWORD_PROVISION
/** @brief A 32 bytes array that represents the trim password value. */
typedef uint8_t hseTrimPassword_t[32];

/**
 * @brief    Provide a password to enable read access of certain system fusemap.
 * @details  If the trim password is valid the HSE shall enable the read for system fuses that can not be read by default by customer.
 *           The customer shall contact NXP to receive the trim password.
 *           After reset, the read for system fuses should be enabled again by providing the same trim password.
 */
typedef struct
{
    /** @brief   INPUT: Specifies the trim password address. The trim password has a length of 32 bytes. */
    HOST_ADDR   pTrimPw;
} hseTrimPasswordProvision_t;
#endif /* HSE_SPT_TRIM_PASSWORD_PROVISION */

#ifdef HSE_SPT_SENSOR_ARMING
/**
 * @brief    On-demand disarming or arming sensors inside HSE.
 * @details  This service allows to disarm sensors at run time to mitigate the risk of HSE entering into shutdown mode due to customer execution environment.
 *           This service can be disabled/enabled configuring the #allowOnDemandSensorArming parameter in #hseSensorDisarmingAttr_t attribute.
 *           By default, this service is disabled.
 *           Each sensor has assigned one byte in sensorCfg[] list that can have the following values (refer to #hseSensorState_t):
 *           -  HSE_SENSOR_UNUSED: sensor configuration is not modified.
 *           -  HSE_SENSOR_ARMED: arm the sensor. when the sensor detects a violation, HSE goes to shutdown (for more details about HSE shutdown, refer HSE Firmware Reference Manual).
 *           -  HSE_SENSOR_DISARMED: disarm the sensor.  Violations detected by the sensor will be ignored. <br>
 *           The host can read the #hseSensorsStateAttr_t to get the list with the state of each sensor (armed or disarmed) that can be configured by the application.
 *
 *      @note
 *           - Only the sensors provided by the #HSE_SENSORS_STATE_ATTR_ID attribute (read-only) can be armed/disarmed.
 *             Otherwise, the HSE_SRV_RSP_NOT_ALLOWED status is returned.
 */
typedef struct
{
    /** @brief   INPUT: Specifies list of bytes to arm/disarm the available sensors (refer to #hseSensorState_t).
     *                  @note
     *                      - The sensor byte is ignored if it is set to #HSE_SENSOR_UNUSED.
     */
    hseSensorState_t    sensorCfg[8U];
    uint8_t             reserved[8U];
} hseOnDemandSensorArming_t;
#endif /* HSE_SPT_SENSOR_ARMING */

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

#endif /* HSE_SRV_UTILS_H */

/** @} */
