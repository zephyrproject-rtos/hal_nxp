/**
*   @file    hse_srv_publish_sys_img.h
*
*   @brief   HSE Publish SYS-IMG service definition.
*   @details This file contains the Publish SYS-IMG service definition.
*
*   @addtogroup hse_srv_publish_sysimg HSE Publish SYS-IMG Service
*   @ingroup class_admin_services
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
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_PUBLISH_SYSIMG_H
#define HSE_SRV_PUBLISH_SYSIMG_H

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
/** @brief  Publish SYS-IMAGE options. */
typedef uint8_t hsePublishOptions_t;
#define HSE_PUBLISH_RESERVED                 ((hsePublishOptions_t)1U << 0U)  /**< @brief Unsupported publish method */
#define HSE_PUBLISH_ALL_DATA_SETS            ((hsePublishOptions_t)1U << 1U)  /**< @brief Publish all data sets. */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** @brief   HSE Publish SYS-IMAGE (only for HSE_H/M devices).
 *  @details Publish the SYS-IMAGE to be stored on an external RAM memory (controlled by application).
 *           The host application uses this service to request the SYS-IMAGE.
 *           The SYS-IMAGE is built from three Data Sets:
 *           - a Main Header (one flash page is allocated)
 *           - SMR/CR/OTFAD/NVM/IEE_DDR(if supported) attributes Data set; max size is 8KB (or 12KB on S32ZE).
 *           - NVM Key Store Data Set; it can be <= 32KB (28KB on SAF8XXX) <br>
 *           If the rollback protection is enabled (refer to #hseOtpRollbackProtectionPolicy_t attribute), 
 *           the last two data sets are protected against reply attacks using a version counter stored in fuses.
 *           The SYS-IMAGE size depends on the flash page size configured in the IVT (if set zero in IVT, HSE used 4KB as the default flash page size);
 *           The maximum SYS-IMG size is:
 *           - 44KB for S32G2/G3/R45/R41
 *           - 48KB for S32ZE
 *           - 40KB for SAF8XXX
 *           For more details, refer to HSE Firmware Reference Manual provide on nxp.com > My NXP > Secure Files.  <br>
 *
 *      @note
 *           - The rollback protection for SYS-IMG can be disabled using #HSE_OTP_ROLLBACK_PROTECTION_POLICY_ATTR_ID attribute
 *           - If the OTP rollback protection is not disabled (refer to #HSE_OTP_ROLLBACK_PROTECTION_POLICY_ATTR_ID attribute),
 *             to be able to update fuse counter, the VDD_EFUSE supply must be powered before fuses
 *             are written (refer to HSE FW Reference Manual).
 *           - If the OTP rollback protection is not disabled
 *              - if the host requests to publish the Data Sets, and none of the Data Sets wasn't updated,
 *                the anti-rollback counter will not be updated in fuses. If one of the Data Sets is updated,
 *                the counter is incremented (fuse counter+1) in image header. The counter will be updated also in fuses
 *                (when sys-image is loaded during start-up).
 *              - The value of the anti-rollback counter is incremented in fuses with a maximum value of 1. The fuse counter 
 *                can be updated at start-up or on demand, depending on the #hseOtpRollbackProtectionPolicy_t attribute configuration.
 *                (multiple update-publish requests in one power cycle will not burn more than one fuse).
 *                The VDD_EFUSE state is checked before the fuse write by reading the NCSPD_STAT register of the on-chip PMC module.
 *                The application shall provide read-only access (xRDC restriction) to HSE to read the NCSPD_STAT register.
 *           - Depending on the size of the DataSet, not the entire flash page(s) is used. An empty space is reserved at the end of
 *             the DataSet (end of the last flash page of the DataSet) for further extention of the DataSet. These reserved empty
 *             spaces are not authenticated during SYS-IMG loading (e.g only relevant data is authenticated and encrypted).
 */
typedef struct
{
    /** @brief   INPUT: Publish SYS-IMAGE options:
                - #HSE_PUBLISH_RESERVED - unsupported publish method.
                - #HSE_PUBLISH_ALL_DATA_SETS - publish all Data Sets.*/
    hsePublishOptions_t    publishOptions;
    uint8_t                reserved[3];
    /** @brief   OUTPUT: The address where to store the Data Set offset (a uint32_t value). <br>
     *                   This offset specifies where the provided output buffer needs to be stored in the external flash SYS-IMAGE
     *                   (e.g. the buffer of size #pBuffLength shall be copied in the external flash starting from address specified
     *                   by "SYS_IMAGE_BASE_ADDR + PublishOffset").
     *                   Since the only supported publish method is for all data sets at the same time, the offset is always set to zero. */
    HOST_ADDR              pPublishOffset;
    /** @brief   INPUT/OUTPUT: As input, it specifies the length (a uint32_t value) of the output buffer provided by the application. <br>
     *                         This needs to be at least greater or equal to the size returned by get the SYS_IMG size request (see hseGetSysImageSizeSrv_t).
     *                         The uint32_t value pointed by #pBuffLength will be overwritten by HSE with the number of bytes that were written into the pBuff buffer. */
    HOST_ADDR              pBuffLength;
    /** @brief   OUTPUT: The address of the output buffer. */
    HOST_ADDR              pBuff;
} hsePublishSysImageSrv_t;

/** @brief   HSE Get SYS_IMAGE size (only for HSE_H/M devices).
 *  @details Return the total length of SYS_IMAGE in bytes.
 */
typedef struct
{
    /** @brief   OUTPUT: The address where to store the size of the SYS_IMAGE (a uint32_t value). */
    HOST_ADDR              pSysImageSize;
} hseGetSysImageSizeSrv_t;

/** @brief   HSE Verify SYS_IMAGE (only for HSE_H/M devices).
 *  @details This service can be used to verify the SYS_IMAGE integrity after it is written in external flash.
 */
typedef struct
{
    /** @brief   INPUT: The address where SYS_IMAGE is stored. Must point to the start of the entire SYS_IMAGE. Cannot be in SD/eMMC external flash. */
    HOST_ADDR              pSysImageAddr;
} hseVerifySysImageSrv_t;

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

#endif /* HSE_SRV_PUBLISH_SYSIMG_H */

/** @} */
