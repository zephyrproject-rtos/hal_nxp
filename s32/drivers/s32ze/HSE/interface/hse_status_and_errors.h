/**
    @file    hse_status_and_errors.h
*
*   @brief   HSE Status and Errors.
*   @details This file contains the HSE status and errors definition.
*
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

#ifndef HSE_STATUS_AND_ERRORS_H
#define HSE_STATUS_AND_ERRORS_H

#ifdef __cplusplus
extern "C"{
#endif

#include "hse_platform.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
*                                      HSE errors
==================================================================================================*/

/**  @addtogroup hse_interface_errors HSE Errors
 *   @ingroup    class_interface
 *   @{
 */

/** @page     errors HSE Errors Details
 *  @details  These error events are reported when some kind of intrusion/violation is detected in the system.
 *            The most significant 16 bits are reserved for NXP internal errors and less significant 16 bits indicate the source of violation as defined below.
 *
 *            @note
 *            - If the MU General Purpose Interrupt is enabled on the host-side, any bit set to "1" (on MUB_GSR register) triggers an interrupt.
 *            - The host must read the MUB_GSR register and write back the register value to clear the bits (W1C - write one to clear).
 *            - The bits[0..7] (listed below) are fatal errors that trigger an HSE shutdown (HSE enters in the secure failure state, all MU are disabled).
 *            - The bits[8..15] (listed below) are warning events (something failed, but it is not fatal).
 */
typedef uint32_t hseError_t;
/*LIST OF HSE FATAL ERRORS. Any fatal error triggers an HSE shutdown. */
#define HSE_ERR_GENERAL                    ((hseError_t)1UL << 0U)  /**< @brief Internal fatal error detected by HSE. The HSE system shutdowns. */

/* LiST OF HSE WARNING EVENTS. In this case, the HSE is still running (it doesn't shutdown). */
#define HSE_WA_SMR_PERIODIC_CHECK_FAILED    ((hseError_t)1UL << 8U) /**< @brief The verification of periodic check SMR (hseSmrEntry_t#checkPeriod !=0) failed. The application can read
                                                                                 #HSE_SMR_CORE_BOOT_STATUS_ATTR_ID attribute to see what SMR failed. */

#ifdef HSE_SPT_INTERNAL_FLASH_DEV /* HSE_B device specific warning bits */
#define HSE_WA_DATA_FLASH_INTEGRITY_FAIL    ((hseError_t)1UL << 9U) /**< @brief HSE Data flash memory integrity check failed. */
#endif /* HSE_SPT_INTERNAL_FLASH_DEV */

#define HSE_WA_RNG_NOT_INIT                 ((hseError_t)1UL << 10U) /**< @brief RNG is not initialized. Services depending on the RNG may be delayed as HSE attempts RNG re-initialization. */

#ifdef HSE_SPT_FLASHLESS_DEV /* HSE_H/M */
#define HSE_WA_PUBLISH_COUNTER_TBL             ((hseError_t)1UL << 11U) /**< @brief The application shall publish and store the monotonic counter table. */
#define HSE_WA_OTP_FUSE_WRITE_FAILURE_ON_BOOT  ((hseError_t)1UL << 12U) /**< @brief At start-up, the the fuse write operation (anti-rollback counter update) failed. A destructive reset is needed. */
#endif /*HSE_SPT_FLASHLESS_DEV*/

/**@}*/

/*==================================================================================================
*                                      Host Events To HSE
==================================================================================================*/
/**  @addtogroup hse_interface_host_events Host Events To HSE
 *   @ingroup class_interface
 *   @{
 */

#ifdef HSE_SPT_FLASHLESS_DEV /* HSE_H/M */
/** @page     host_events Host Events To HSE Details
 *  @brief    These events are sent by Host to notify HSE of actions that needs synchronization between the two.
 *            In order to signal HSE of these events, the host must write its value to MUB_GCR.
 *  @note     This is applicable only for MU0 instance.*/
typedef uint32_t hseHostEvent_t;

/** @brief This event is sent by the host to notify HSE after it configures the external peripherals at init-time.
 *  @note     This host event is applicable only at start-up:
 *           - When BOOT_SEQ == 0, until the HSE sets HSE_STATUS_INIT_OK
 *           - Or, when BOOT_SEQ == 1 and the POST_BOOT SMRs are used, after HSE sets #HSE_STATUS_BOOT_OK, until #HSE_STATUS_INIT_OK is set.
 *           - In the above cases,for HSE_B/H/M (except SAF85XX), if the #HSE_HOST_PERIPH_CONFIG_DONE is not received within 5 seconds (computed at maximum frequency), the HSE execution continues.
 *           - Or, for SAF85XX if the #HSE_HOST_PERIPH_CONFIG_DONE is not received within 240 milliseconds (computed at maximum frequency), the HSE execution continues.
 **/
#define HSE_HOST_PERIPH_CONFIG_DONE ((hseHostEvent_t)1UL << 0U)

#ifdef HSE_M
/** @brief This event is sent by the host to notify HSE to trigger TMU BIST selftest.
 *  @note     This host event is applicable only once and the #HSE_STATUS_INIT_OK bit must be set. <br>
 *            For S32R41X, the host must read the TRITSR[3-4]/TRATSR[3-4] register for the results. <br>
 *            For SAF85XX, the host must read the HSE-GPR register for the results <br>
 *                         #HSE_TMU_BIST_MODE_TEST_BJT_CORE_SEQ1, <br>
 *                         #HSE_TMU_BIST_MODE_TEST_BJT_CORE_SEQ2, <br>
 *                         #HSE_TMU_BIST_MODE_TEST_ADC_OUTPUT     <br>
 **/
#define HSE_TMU_BIST_SELFTEST       ((hseHostEvent_t)1UL << 1U)
#endif /* HSE_M */

#endif /* HSE_SPT_FLASHLESS_DEV */

/**@}*/

/*==================================================================================================
*                                      HSE Status
==================================================================================================*/

/**  @addtogroup hse_interface_status HSE Status
 *   @ingroup    class_interface
 *   @{
 */

/** @page   status HSE Status Details
 *  @details HSE status can be read by the HOST and represents the most significant 16 bits
 *           in MUB.FSR register. The least significant 16 bits in MUB.FSR register identifies
 *           the status of each channel:
 *             - 0b - channel idle and it can accept service requests
 *             - 1b - channel busy */
typedef uint16_t hseStatus_t;
/** @details This bit is set when the SHE based secure boot process has been started by HSE firmware.
 *           This bit is only set when SMR0 entry has been installed by the user and its authentication key is set as SHE based BOOT_MAC_KEY */
#define HSE_SHE_STATUS_SECURE_BOOT                          ((hseStatus_t)1U << 1U)

/** @details This bit is set when BOOT_MAC personalization has been completed by HSE firmware.
 *           It means that the BOOT_MAC slot was empty and SHE-based secure boot is performed the the first time.
 *           In that case, if BOOT_MAC_KEY is present, then HSE firmware calculates the BOOT_MAC of the SMR
 *           image present in the SMR0 (using the BOOT_MAC_KEY) and store it as part of sys image. */
#define HSE_SHE_STATUS_SECURE_BOOT_INIT                     ((hseStatus_t)1U << 2U)

/** @details This bit is set when the HSE firmware has completed the secure boot
 *           process with a failure status. (the image verification failed). */
#define HSE_SHE_STATUS_SECURE_BOOT_FINISHED                 ((hseStatus_t)1U << 3U)

/** @details This bit is set when the HSE firmware has successfully completed the secure boot
 *           process (the image verification was successful). */
#define HSE_SHE_STATUS_SECURE_BOOT_OK                       ((hseStatus_t)1U << 4U)

/** @brief This bit is set when HSE FW has successfully initiliazed the RNG. */
#define HSE_STATUS_RNG_INIT_OK                              ((hseStatus_t)1U << 5U)

/** @brief This bit is set when debugger on HOST side is active as well as enabled */
#define HSE_STATUS_HOST_DEBUGGER_ACTIVE                     ((hseStatus_t)1U << 6U)

/** @brief This bit is set when debugger on HSE side is active as well as enabled */
#define HSE_STATUS_HSE_DEBUGGER_ACTIVE                      ((hseStatus_t)1U << 7U)

/** @details This bit is set when the HSE initialization has been successfully completed (HSE service requests can be sent over MUs).
 *           If this bit is cleared, the host can NOT perform any service request (MUs are disabled). */
#define HSE_STATUS_INIT_OK                                  ((hseStatus_t)1U << 8U)

/** @details This flag signals the application that needs to format the key catalogs (NVM and RAM).
 *           - When it is clear, the application shall format the key catalogs;
 *           - When it is set, the HSE installation phase has been successfully completed.
 *             (e.g HSE is in normal state and the application can install the NVM key, configure the SMR entries etc).
 *             @note This step is MANDATORY.*/
#define HSE_STATUS_INSTALL_OK                                ((hseStatus_t)1U << 9U)

/** @details This bit is set when the HSE booting phase has been successfully completed.
 *           This bit is cleared if the HSE booting phase is still in execution or failed.
 *           @note
 *           - HSE set this bit only when the secure boot is configured (BOOT_SEQ = 1).
 *           - This bit represents the status of booting phase which includes the PRE_BOOT SMR verification (without POST_BOOT SMRs) and cores un-gating.
 *           - The HSE FW signals the end of the POST_BOOT phase along with additional peripherals initialization via #HSE_STATUS_INIT_OK flag. */
#define HSE_STATUS_BOOT_OK                                  ((hseStatus_t)1U << 10U)

/** @details After reset, if the Life Cycle = CUST_DEL, this bit is set (SuperUser rights are granted). <br>
*          During run-time:
*            - it is set if the authorization request for CUST SuperUser rights are granted using an CUST authorization key.
*            - it is cleared for USER rights.
*             @note  If CUST START_AS_USER policy attribute is set (TRUE), the device will always start having User rights. */
#define HSE_STATUS_CUST_SUPER_USER                          ((hseStatus_t)1U << 11U)

/** @details After reset: if the Life Cycle = OEM_PROD, this bit is set (SuperUser rights are granted). <br>
*             During run-time:
*            - it is set if the authorization request for OEM SuperUser rights are granted using an OEM authorization key.
*            - it is cleared for USER rights.
*             @note If OEM START_AS_USER policy attribute is set (TRUE), the device will always start having User rights. */
#define HSE_STATUS_OEM_SUPER_USER                           ((hseStatus_t)1U << 12U)


#ifdef HSE_SPT_FLASHLESS_DEV /* HSE_H/M device specific status bits */

/** @details This flag signals the application to publish the SYS-IMAGE.
 *            - When this flags is set, the host must trigger a PUBLISH_SYS_IMG request.
 *              @note This flag is set whenever the HSE SYS-IMAGE has been updated in the HSE internal RAM (e.g. after a key update, SMR update, etc.).
 *            - Once SYS-IMG is published to application RAM, this bit is cleared.*/
#define HSE_STATUS_PUBLISH_SYS_IMAGE                        ((hseStatus_t)1U << 13U)

/** @details This flag signals the application whether HSE FW has loaded or not the SYS-IMAGE from primary address.
 *           - If this flag is set, the primary SYS-IMAGE has been loaded.
 *           - If this flag is cleared, the primary SYS-IMAGE has NOT been loaded. This means that HSE either
 *             loaded the SYS-IMAGE from backup address (see #HSE_STATUS_BACKUP_SYS_IMAGE flag) or both primary and backup loads failed. */
#define HSE_STATUS_PRIMARY_SYS_IMAGE                        ((hseStatus_t)1U << 14U)

/** @details This flag signals the application whether HSE FW has loaded or not the SYS-IMAGE from backup address.
 *           - If this flag is set, the backup SYS-IMAGE has been loaded.
 *           - If this flag is cleared, the backup SYS-IMAGE has NOT been loaded. This means that HSE either
 *             loaded the SYS-IMAGE from primary address (see #HSE_STATUS_PRIMARY_SYS_IMAGE flag) or both primary and backup loads failed. */
#define HSE_STATUS_BACKUP_SYS_IMAGE                         ((hseStatus_t)1U << 15U)


#else /* HSE_B device specific status bits */

/** @details This bit is set when the HSE FW update is in progress.
 *           This bit is cleared after HSE FW update completion. */
#define HSE_STATUS_FW_UPDATE_IN_PROGRESS                    ((hseStatus_t)1U << 13U)

/** @details This flag signals the application to publish the NVM KEYSTORE to Secure flash Region.
 *            - This feature can be enabled via #HSE_ENABLE_PUBLISH_KEY_STORE_RAM_TO_FLASH_ATTR_ID attribute.
 *            - When this flags is set, the host must trigger a PUBLISH_KEYSTORE request via #HSE_SRV_ID_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH.
 *              @note This flag is set whenever the HSE NVM KEYSTORE has been updated in the HSE internal RAM indicating that it is not safe to reset the device.
 *            - Once NVM KEYSTORE via #HSE_SRV_ID_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH, it is written on secure region in data flash and this bit is cleared.
 *            - If this bit is set, the application must call the #HSE_SRV_ID_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH service before issuing the Firmware Update.
 *              Otherwise, the HSE_SRV_RSP_NOT_ALLOWED response status will be returned.
 */
#define HSE_STATUS_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH        ((hseStatus_t)1U << 14U)

#endif /* HSE_SPT_FLASHLESS_DEV */


#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /*  HSE_STATUS_AND_ERRORS_H */

/** @} */
