/**
*   @file    hse_srv_attr.h
*
*   @brief   HSE Set/Get attribute services definition.
*   @details This file contains the Set/Get attribute services definition.
*
*   @addtogroup hse_srv_attr HSE Set/Get Attribute Services
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
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_ATTR_H
#define HSE_SRV_ATTR_H

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

/** @brief    Activate or not a specific configuration.
 *  @details  Tells whether the HSE activate or not a specific configuration.
 */
typedef uint32_t hseAttrCfg_t;
#define HSE_CFG_NO       ((hseAttrCfg_t)(0x0UL))                    /**< @brief NO, deactivate the configuration */
#define HSE_CFG_YES      ((hseAttrCfg_t)(0xB7A5C365UL))             /**< @brief YES, activate the configuration  */

/**  @brief   HSE attribute IDs.
 *   @details   The following attribute types are defined:
 *            - RO-ATTR - Read-Only attribute
 *            - OTP-ATTR - One Time Programmable; can be written only once (set FUSE/UTEST area)
 *            - OTP-ADVANCE-ATTR - One Time Programmable attribute that can only be advanced (e.g. LifeCycle)
 *            - NVM-RW-ATTR - System NVM attributes; can be read or written.
 *            - SET-ONCE-ATTR- Once the attribute is set, it can not be changed until next reset (e.g. can be set once at initialization time)
 *
 * @note
 * - To set/update the OTP-ATTR or NVM-RW-ATTR attributes (except SET-ONCE-ATTR and OTP-ADVANCE-ATTR), the host needs SuperUser rights.
 * - After setting the HSE_SECURE_LIFECYCLE_ATTR_ID attribute, a destructive reset is needed.
 * - For HSE_H/M devices, if the NVM-RW-ATTR attributes were updated, the SYS-IMAGE must be published and stored in external flash.
 * - For HSE_H/M devices, in order to program fuses (OTP-ATTR and OTP-ADVANCE-ATTR) during development and potentially in the field, the application must supply power to the VDD_EFUSE pin of the device.
 *   This allows the programming operation to take place. If theVDD_EFUSE is not powered and the application tries to write a fuse, the HSE returns an error
 *   (HSE_SRV_RSP_FUSE_VDD_GND). The VDD_EFUSE state is checked before the fuse write by reading the NCSPD_STAT register of the on-chip PMC module.
 *   The application must provide read access (xRDC restriction) to HSE in order to be able to read the NCSPD_STAT register.
 *   For more details, refer to HSE FW Reference Manual.
*/
typedef uint16_t hseAttrId_t;

    /*----------------- Common (HSE_H/M/B) attributes ---------------------*/

    #define HSE_NONE_ATTR_ID                         ((hseAttrId_t)0U)
    /* RO-ATTR */
    #define HSE_FW_VERSION_ATTR_ID                   ((hseAttrId_t)1U)    /**< @brief RO-ATTR; HSE FW version (see #hseAttrFwVersion_t) */
    #define HSE_CAPABILITIES_ATTR_ID                 ((hseAttrId_t)2U)    /**< @brief RO-ATTR; HSE capabilities (see #hseAttrCapabilities_t) */
    #if defined(HSE_SPT_SMR_CR) || defined(HSE_SPT_BSB)
    #define HSE_SMR_CORE_BOOT_STATUS_ATTR_ID         ((hseAttrId_t)3U)    /**< @brief RO-ATTR;  SMR verification & Core-boot status (see #hseAttrSmrCoreStatus_t) */
    #endif  /* defined(HSE_SPT_SMR_CR) || defined(HSE_SPT_BSB) */
    #define HSE_FW_BUILD_INFO_ATTR_ID                ((hseAttrId_t)4U)    /**< @brief RO-ATTR; HSE FW Build information (see #hseFwBuildInfo_t) */

    #ifdef HSE_SPT_SENSOR_ARMING
    #define HSE_SENSORS_STATE_ATTR_ID                ((hseAttrId_t)5U)    /**< @brief RO-ATTR; Returns the list of sensors that can be armed or disarmed ( see #hseSensorsStateAttr_t ) */
    #endif /* HSE_SPT_SENSOR_ARMING */

    /* OTP-ATTR & OTP-ADVANCE-ATTR*/
    #define HSE_DEBUG_AUTH_MODE_ATTR_ID              ((hseAttrId_t)10U)   /**< @brief OTP-ATTR; Debug Authorization mode (see #hseAttrDebugAuthMode_t) */
    #define HSE_APP_DEBUG_KEY_ATTR_ID                ((hseAttrId_t)11U)   /**< @brief OTP-ATTR; Application Debug Key / Password (see #hseAttrApplDebugKey_t and #hseAttrSecureApplDebugKey_t) */
    #define HSE_SECURE_LIFECYCLE_ATTR_ID             ((hseAttrId_t)12U)   /**< @brief OTP-ADVANCE-ATTR; Secure Life-cycle (see #hseAttrSecureLifecycle_t) */
    #define HSE_ENABLE_BOOT_AUTH_ATTR_ID             ((hseAttrId_t)13U)   /**< @brief OTP-ATTR; IVT/ DCD Authentication bit for HSE H and IVT Authentication bit for HSE M (see #hseAttrConfigBootAuth_t)  */

    #ifdef HSE_SPT_CUST_SEC_POLICY
    #define HSE_EXTEND_CUST_SECURITY_POLICY_ATTR_ID  ((hseAttrId_t)14U)   /**< @brief OTP-ATTR & NVM-RW-ATTR; HSE security policies extension in CUST_DEL lifecycle for user with CUST SU rights (see #hseAttrExtendCustSecurityPolicy_t). \
                                                                                    Note that this attribute also enables the ADKPm in OTP (ADKP diversified with UID), along with the START_AS_USER setting for CUST_DEL lifecycle. */
    #endif /* HSE_SPT_CUST_SEC_POLICY */

    /* NVM-RW-ATTR */
    #define HSE_MU_CONFIG_ATTR_ID                    ((hseAttrId_t)20U)   /**< @brief NVM-RW-ATTR; MU configuration (see #hseAttrMUConfig_t) */

    #ifdef HSE_SPT_OEM_SEC_POLICY
    #define HSE_EXTEND_OEM_SECURITY_POLICY_ATTR_ID   ((hseAttrId_t)21U)   /**< @brief NVM-RW-ATTR; HSE security policies extension in OEM_PROD lifecycle for user with OEM SU rights  (see #hseAttrExtendOemSecurityPolicy_t) */
    #endif /* HSE_SPT_OEM_SEC_POLICY */

    #ifdef HSE_SPT_FAST_CMAC
    #define HSE_FAST_CMAC_MIN_TAG_BIT_LEN_ATTR_ID    ((hseAttrId_t)22U)   /**< @brief NVM-RW-ATTR; The minimum tag bit length that can be used for Fast CMAC verify/generate (see #hseAttrFastCmacMinTagBitLen_t) */
    #endif /* HSE_SPT_FAST_CMAC */

    #define HSE_CORE_RESET_RELEASE_ATTR_ID           ((hseAttrId_t)23U)   /**< @brief NVM-RW-ATTR; Specifies Core Reset table parsing strategy (see #hseAttrCoreResetRelease_t) */

    #ifdef HSE_SPT_KEY_MGMT_POLICIES
    #define HSE_RAM_PUB_KEY_IMPORT_POLICY_ATTR_ID    ((hseAttrId_t)24U)   /**< @brief NVM-RW-ATTR; Specifies RAM public keys import policy in advanced LCs (see #hseAttrRamPubKeyImportPolicy_t) */
    #endif /* HSE_SPT_KEY_MGMT_POLICIES */

    #ifdef HSE_SPT_RESET_SOC_ON_TAMPER_ATTR
    #define HSE_RESET_SOC_ON_TAMPER_ATTR_ID          ((hseAttrId_t)25U)   /**< @brief NVM-RW-ATTR; Reset Soc on tamper detection (see #hseResetSocOnTamper_t) */
    #endif /* HSE_SPT_RESET_SOC_ON_TAMPER_ATTR */

    #ifdef HSE_SPT_SENSOR_ARMING
    #define HSE_SENSOR_DISARMING_ON_STARTUP_ATTR_ID  ((hseAttrId_t)50U)   /**< @brief NVM-RW-ATTR; Keep the sensor armed or disarmed after booting ( see #hseSensorDisarmingAttr_t) */
    #endif /* HSE_SPT_SENSOR_ARMING */

    /*----------------- END  Common (HSE_H/M/B) attributes --------------------*/

#ifdef HSE_SPT_FLASHLESS_DEV

    #define HSE_OTP_ROLLBACK_PROTECTION_POLICY_ATTR_ID ((hseAttrId_t)26U) /**< @brief NVM-RW-ATTR; Disable or enable (default) the OTP rollback protection for FW Blue Image and SYS-IMG (see #hseOtpRollbackProtectionPolicy_t) */
#endif /* HSE_SPT_FLASHLESS_DEV */

    #ifdef HSE_SPT_APP_SPECIFIC_DATA_ATTR
    #define HSE_APP_SPECIFIC_DATA_ATTR_ID               ((hseAttrId_t)27U)    /**< @brief NVM-RW-ATTR; Set an application-specific data of maximum #HSE_APP_SPECIFIC_DATA_MAX_BUFFER_SIZE bytes (see #hseAppSpecificData_t) */

    #define HSE_DISABLE_APP_SPECIFIC_DATA_WRITE_ATTR_ID ((hseAttrId_t)28U)    /**< @brief SET-ONLY-ONCE-ATTR; Disable the write of APP_SPECIFIC_DATA attribute (see #hseDisableAppSpecificDataWrite_t) */
    #endif /* HSE_SPT_APP_SPECIFIC_DATA_ATTR */

    /* SET-ONCE-ATTR*/
    #ifdef HSE_SPT_PHYSICAL_TAMPER_CONFIG
    #define HSE_PHYSICAL_TAMPER_ATTR_ID              ((hseAttrId_t)30U)   /**< @brief SET-ONLY-ONCE-ATTR; Enables the physical tamper violation in HSE.
                                                                                Once the violation is enabled in HSE, it can not be cleared
                                                                                until next reset. There are two tamper related functions available on PADs: Input (TAMPER_IN), Output (TAMPER_OUT).
                                                                                To support protection against physical tampering, connect TAMPER_OUT to
                                                                                TAMPER_IN. Any physical tamper that breaks this connectivity sets off an alarm at
                                                                                HSE (if enabled using this attribute). User can optionally lock those pads
                                                                                configuration for further modification using virtual wrapper (refer to #hseAttrPhysicalTamper_t).
                                                                                The configuration status is provided by reading the HSE_GPR_STATUS_ADDRESS register (refer to #hseTamperConfigStatus_t). */
    #endif /* HSE_SPT_PHYSICAL_TAMPER_CONFIG */

    #ifdef HSE_SPT_MEM_REGION_PROTECT
    #define HSE_MEM_REGIONS_PROTECT_ATTR_ID          ((hseAttrId_t)31U)   /**< @brief SET-ONLY-ONCE-ATTR; Configures memory regions accessible through each MU (refer to #hseAttrAllMuMemRegions_t) */
    #endif /* HSE_SPT_MEM_REGION_PROTECT */

    #define HSE_DISABLE_PAIRWISE_CONSISTENCY_TEST_ATTR_ID  ((hseAttrId_t)32U)   /**< @brief SET-ONLY-ONCE-ATTR; Disable the pair wise consistency test when calling import RSA/ECC key pair (see #hseDisablePairWiseConsistencyTest_t) */


    /*------------------------ HSE_H/M specific attributes ------------------------*/
#if defined(HSE_SPT_FLASHLESS_DEV)

    /* RO-ATTR */
    #define HSE_FW_SIZE_ATTR_ID                      ((hseAttrId_t)100U)  /**< @brief RO-ATTR; HSE Firmware Size (see #hseAttrHseFwSize_t) */
    #define HSE_AVAIL_ANTI_ROLLBACK_COUNTER_ATTR_ID  ((hseAttrId_t)101U)  /**< @brief RO-ATTR; The anti-rollback counter updates left (see #hseAvailAntiRollbackCounter_t) */
    #define HSE_FW_PARTITION_ATTR_ID                 ((hseAttrId_t)102U)  /**< @brief RO-ATTR; The partition (primary or backup) used by BootRom to load the HSE Firmware (see #hseAttrFwPartition_t) */

    #ifdef HSE_SPT_OTFAD
    #define HSE_OTFAD_CTX_STATUS_ATTR_ID             ((hseAttrId_t)103U)  /**< @brief RO-ATTR; Otfad contexts status (see #hseOtfadContextStatus_t). */
    #endif /* HSE_SPT_OTFAD */

    #ifdef HSE_SPT_SMR_SECURE_LOGGING
    #define HSE_SLOG_STATUS_ATTR_ID                  ((hseAttrId_t)104U)  /**< @brief RO-ATTR; Get the secure logging status (see #hseSlogStatus_t) */
    #endif /* HSE_SPT_SMR_SECURE_LOGGING */

    #define HSE_RB_COUNTER_INFO_ATTR_ID             ((hseAttrId_t)105U)  /**< @brief RO-ATTR; Get the anti-rollback counters information (see #hseRbCounterInfo_t) */

    /* OTP-ATTR */
    #define HSE_APP_DEBUG_DIS_ATTR_ID                ((hseAttrId_t)200U)  /**< @brief OTP-ATTR; Disable Application Debug (see #hseAttrDisableAppDebug_t) */

    #ifdef HSE_SPT_OTP_BOOT_SEQ_ATTR
    #define HSE_OTP_BOOT_SEQ_ATTR_ID                 ((hseAttrId_t)201U)  /**< @brief OTP-ATTR; Configures OTP_BOOT_SEQ==1 (secure boot) (see #hseAttrOtpBootSeq_t) */
    #endif /* HSE_SPT_OTP_BOOT_SEQ_ATTR */

    /* NVM-RW-ATTR */
    #ifdef HSE_SPT_SMR_SECURE_LOGGING
    #define HSE_SLOG_SMR_CONFIG_ATTR_ID              ((hseAttrId_t)301U)   /**< @brief NVM-RW-ATTR; To configure the SMR(s) linked with the secure logging (see #hseAttrSlogSmrCfg_t) */
    #endif /* HSE_SPT_SMR_SECURE_LOGGING */

    /* SET-ONCE-ATTR*/
    #ifdef HSE_SPT_TEMP_SENS_VIO_CONFIG
    #define HSE_TEMP_SENSOR_VIO_CONFIG_ATTR_ID       ((hseAttrId_t)400U)  /**< @brief SET-ONLY-ONCE-ATTR; Enable the temperature sensor violation in HSE (see #hseTempSensVioConfig_t) */
    #endif /* HSE_SPT_TEMP_SENS_VIO_CONFIG */

#endif /* HSE_SPT_FLASHLESS_DEV */
    /*------------------------ END HSE_H/M specific attributes ---------------------*/

    /*------------------------ HSE_B specific attributes ---------------------------*/
#ifdef HSE_B

    /* SET-ONCE-ATTR*/
    #define HSE_FIRC_DIVIDER_CONFIG_ATTR_ID          ((hseAttrId_t)600U)  /**< @brief RAM-RW; FIRC Divider Configuration by HSE Firmware from HSE_GPR (see #hseFircDivConfig_t) */
    /* Secure Recovery */
    #define HSE_SECURE_RECOVERY_CONFIG_ATTR_ID       ((hseAttrId_t)601U)  /**< @brief OTP-ATTR; Secure Recovery Configuration by HSE Firmware (see #hseAttrConfigSecureRecovery_t) */
    /* Flash Optimization Config Attr */
    #if defined(HSE_SPT_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH)
    #define HSE_ENABLE_PUBLISH_KEY_STORE_RAM_TO_FLASH_ATTR_ID    ((hseAttrId_t)602U)  /**< @brief RAM-RW; Allow to publish the NVM keystore from secure NVM keystore into the data flash (see #hsePublishNvmKeystoreRamtToFlash_t) */
    #endif /* HSE_SPT_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH */

#endif /* HSE_B */
    /*------------------------ END HSE_B specific attributes ---------------------*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 HSE SET/GET ATTRIBUTE SERVICES
==================================================================================================*/

/** @brief Set HSE attribute service.
 *         @note SuperUser rights (for NVM Configuration) are needed to perform this service.
 */
typedef struct
{
    /** @brief   INPUT: Specifies the HSE attribute ID.*/
    hseAttrId_t   attrId;
    uint8_t       reserved[2];
    /** @brief   INPUT: Specifies the attribute length (in bytes). The size of the memory location
     *                   must be equal to the length of attribute structure */
    uint32_t      attrLen;
    /** @brief   INPUT: The address of the attribute.
     *                  The attribute must have the format of the corresponding attributes structure (see attributes definition)
     *                  @note
     *                  The comment for each attribute ID provides the name for the attribute data structure.
     *                  E.g:The #HSE_MU_CONFIG_ATTR_ID definition includes the following comment: "NVM-RW-ATTR; MU configuration (see #hseAttrMUConfig_t)". */
    HOST_ADDR     pAttr;
} hseSetAttrSrv_t;

/** @brief Get HSE attribute service. */
typedef struct
{
    /** @brief   INPUT: Specifies the HSE attribute ID.*/
    hseAttrId_t   attrId;
    uint8_t       reserved[2];
    /** @brief   INPUT: Specifies the attribute length (in bytes).The size of the memory location
     *                  must be bigger than or equal to the length of attribute structure */
    uint32_t      attrLen;
    /** @brief   OUTPUT: The address where the attribute will be stored.
     *                   The attribute must be stored in the format of the corresponding attribute Id (see the attributes definition).
     *                  @note
     *                  The comment for each attribute ID provides the name for the attribute data structure.
     *                   E.g: The #HSE_FW_VERSION_ATTR_ID definition includes the following comment: "RO-ATTR; HSE FW version (see #hseAttrFwVersion_t)". */
    HOST_ADDR     pAttr;
} hseGetAttrSrv_t;

/*==================================================================================================
                                 ATTRIBUTE DEFINITION
==================================================================================================*/

/*==================================================================================================
                                 HSE FW version
==================================================================================================*/
/**
* @brief          HSE FW version attribute (RO-ATTR attribute; refer to #hseAttrId_t).
*
*/
typedef struct
{
    uint8_t     reserved;       /**< @brief  For HSE_B, it is used for OTA Config: 0 = Full Mem Config; 1 = AB Swap Config.
                                             For other SOC type: Reserved, expected to be 0 */
    uint8_t     socTypeId;      /**< @brief  Identifies the SoC Type ID; same as HSE_PLATFORM from hse_target.h */
    uint16_t    fwTypeId;       /**< @brief  Identifies the FW type:
                                              - 0 - Standard FW targeting all customers
                                              - 1 - Premium  FW targeting all customers
                                              - 2-7 - Reserved
                                              - 8 >= Custom1, Custom2... etc */
    uint8_t     majorVersion;   /**< @brief  Major revision
                                              - 0 - Pre-stabilization releases
                                              - 1 - at first stable interface release, and increased later if breaking changes were introduced */
    uint8_t     minorVersion;   /**< @brief  Minor revision, bumped on new compatible changes added; <br>
                                             reset to 0 on majorVersion bump, if majorVersion > 0 */
    uint16_t    patchVersion;   /**< @brief  Hotfix release (patch version, bug fix releases).<br>
                                             After majorVersion > 0, reset to 0 on majorVersion or minorVersion bump. */
} hseAttrFwVersion_t;


/*==================================================================================================
                                 HSE capabilities
==================================================================================================*/
/** @brief    HSE capabilities bits definition (RO-ATTR attribute; refer to #hseAttrId_t).
 * @details   Provides information about the capabilities of HSE security blocks (list of what algorithms are supported).
 *            Each bit specifies an supported algorithm. The index for each bit in the attribute is defined by #hseAlgoCapIdx_t.
*/
typedef uint64_t hseAttrCapabilities_t;
/** @brief    Provided the bit (used in hseAttrCapabilities_t) based on the algorithm capability index (see #hseAlgoCapIdx_t) */
#define HSE_ALGO_CAP_MASK(capIdx)  (1ULL << (capIdx))

/*==================================================================================================
                                 HSE FW build info
==================================================================================================*/
/**
* @brief          HSE FW build information attribute (RO-ATTR attribute; refer to #hseAttrId_t).
*/
typedef struct
{
    uint64_t    buildUniqueIdentifier;          /**< @brief  Build unique identifier (8 bytes of SHA1 of the HEAD ) */
    uint32_t    buildDate;                      /**< @brief  Build date in hexadecimal (hex(YYYYMMDD)) */
    uint32_t    buildTime;                      /**< @brief  Build time in hexadecimal (hex(HHMMSS)) */
} hseFwBuildInfo_t;


/*==================================================================================================
                                 Get the sensors that can be armed or disarmed
==================================================================================================*/
#ifdef HSE_SPT_SENSOR_ARMING
/** @brief The sensor state; it can be armed or disarmed (one byte for each sensor).*/
typedef uint8_t hseSensorState_t;
#define HSE_SENSOR_STATE_UNUSED          ((hseSensorState_t)0x00U)  /**< @brief The sensor byte is unused. >**/
#define HSE_SENSOR_STATE_ARMED           ((hseSensorState_t)0xB5U)  /**< @brief The sensor is armed. When the sensor detects the violation, HSE goes to shutdown (for more details about HSE shutdown, refer HSE Firmware Reference Manual). >**/
#define HSE_SENSOR_STATE_DISARMED        ((hseSensorState_t)0x5AU)  /**< @brief The sensor is disarmed. Violations detected by the sensor will be ignored. >**/

/**
* @brief    Get the state of the sensors that can be disarmed/armed.
*           Each sensor has assigned a byte in the sensorList[] list as follow:
*           - sensorList[0]: the glitch detector sensor (GDET).
*           - sensorList[1 to 7]: Reserved for future use.
*
*           Only the sensor provided in sensorList[] list can be:
*              -  disarmed on startup using #hseSensorDisarmingAttr_t attribute,
*              -  armed/disarmed at runtime using the hseOnDemandSensorArming_t service (if enabled; refer to #hseSensorDisarmingAttr_t)
*
*           @note
*           - This is a READ-ONLY attribute.
*/
typedef struct
{
    /** @brief Returns a list with the state of each sensor; the sensors can be armed or disarmed (one byte for each sensor). */
    hseSensorState_t    sensorList[8U];
} hseSensorsStateAttr_t;
#endif /* HSE_SPT_SENSOR_ARMING */

/*==================================================================================================
                                 SMR verification & Core-boot status
==================================================================================================*/
/** @brief    The SMR and Core Boot status (RO-ATTR attribute; refer to #hseAttrId_t).
 * @details   Provides the following infomation:
 *            - SMR entry installation status corresponding to the entries present in SMR table (refer to #smrEntryInstallStatus)
 *            - SMR verification status corresponding to the entries present in SMR table (refer to #smrStatus[])
 *            - Provides Core Boot status (refer to #coreBootStatus[])
 *            - In case Basic Secure Boot (BSB) is performed, it provides the Core Boot status and the location of loaded application (primary/backup, refer to #coreBootStatus[])
 */
#if defined(HSE_SPT_SMR_CR) || defined(HSE_SPT_BSB)
typedef struct
{
    uint32_t smrStatus[2U];         /**< @brief  0-31 bit will represent 32 SMR table entries (applicable when SMR is present/enabled).
                                                - smrStatus[0].bit : 0 - SMR Not verified
                                                - smrStatus[0].bit : 1 - SMR verified
                                                - smrStatus[1].bit : 0 - SMR verification fail
                                                - smrStatus[1].bit : 1 - SMR verification pass */
    uint32_t coreBootStatus[2U];   /**< @brief   0-31 bit will represent CORE-ID (0-31):
                                                - coreBootStatus[0].bit : 1 - Core booted
                                                - coreBootStatus[0].bit : 0 - Core Not booted
                                                - coreBootStatus[1].bit : 1 - Core booted with pass/primary reset address
                                                - coreBootStatus[1].bit : 0 - Core booted with alternate/backup reset address */
    uint32_t smrEntryInstallStatus;/**< @brief   0-31 bit will represent 32 SMR table entries (applicable when SMR is present/enabled).
                                                - bit : 0 - SMR entry not installed
                                                - bit : 1 - SMR entry installed */
} hseAttrSmrCoreStatus_t;
#endif /*defined(HSE_SPT_SMR_CR) || defined(HSE_SPT_BSB) */

#ifdef HSE_SPT_SMR_SECURE_LOGGING
/** @brief    The secure logging SMR(s) configuration (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 * @details   This service configures the on-demand or periodic SMR(s) that must be verified for secure logging.
 *             Additionally, it enables the use of fuse or RAM for secure logging.
 * @note
 *   - The Application must have SU rights to configure this attribute.
 *   - The attribute can be read at any time without any restriction.
 *   - HSE logs the SMR failures and recoveries in a 8-bit secure logging status.
 *     Maximum 4 failures and 3 recoveries can be logged (7 bits in total, from 0 to 6; last bit is not used).
 *     For details, refer to #hseSlogStatus_t.
 *   - By default, HSE logs the secure logging status in RAM. Using this service, the application
 *     can enable the logging in fuses. The application must understand the criticality of the secure logging in fuses.
 *   - A failure is logged if one of the following conditions is met:
 *     1. At start-up, when BOOT_SEQ == 1 and the secure boot (SMR or BSB) fails
 *     2. If any of the on-demand/runtime SMR specified in smrPeriodicOnDemand flags failed.
 *   - IMPORTANT: if enableFuseUsage == HSE_CFG_YES and any periodic SMR is linked to SLOG, make sure VDD_EFUSE is always powered on.
 */
typedef struct
{
    uint32_t     slogSmrPeriodicOnDemand;           /**< @brief The on-demand or periodic SMR(s) that must be verified for secure logging. */
    hseAttrCfg_t enableFuseUsage;                   /**< @brief #HSE_CFG_NO -  the fuse bits are not used. The secure logging status is stored in internal RAM (is not persistent).<br>
                                                                #HSE_CFG_YES - the fuse bits are used. The secure logging status is persistent in fuse. */
    uint8_t      reserved[8];
} hseAttrSlogSmrCfg_t;

/** @brief   The secure logging status(RO-ATTR attribute; refer to #hseAttrId_t).
 * @details  It provides the SMR failures and recoveries in fuse (or RAM if enableFuseUsage == HSE_CFG_NO).
 *           The secure logging is configured using #hseAttrSlogSmrCfg_t attribute.
 *           By default, the secure logging is using the RAM (it is not persistent in fuses)
 *           The secure logging status is stored in 8 bits as follows:
 *           - Even bits signals a failure: sLog[bit#i (even)] == 1 means the secure boot failed (logging number i/2)
 *           - Odd bits signals a recovery: sLog[bit#i + 1]    == 1 means the secure boot failure number i/2 was recovered
 *           - bit #7 is not used
 *           @note
 *              - Example of logging the secure boot failures and recoveries in fuse (bit #7 not used)
 *
 * |  Bit position   |  b7 |  b6 |  b5 |  b4 |  b3 |  b2 |  b1 |  b0 |                        Remark                            |
 * |----------------:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---------------------------------------------------------|
 * | hseSlogStatus   |  X  |  0  |  0  |  0  |  0  |  0  |  0  |  0  | No secure boot failure logged                            |
 * | hseSlogStatus   |  X  |  0  |  0  |  0  |  0  |  0  |  0  |  1  | One secure boot failure logged                           |
 * | hseSlogStatus   |  X  |  0  |  0  |  0  |  0  |  0  |  1  |  1  | One secure boot failure logged but recovered             |
 * | hseSlogStatus   |  X  |  1  |  1  |  1  |  1  |  1  |  1  |  1  | Four secure boot failure logged, no further log possible |
 */
typedef uint8_t hseSlogStatus_t;

#endif /* HSE_SPT_SMR_SECURE_LOGGING */

/*==================================================================================================
                                 Core Release Strategy
==================================================================================================*/
/** @brief    The Core Reset release from reset method (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 * @details   Specifies the startup method for releasing the application core from reset. */
typedef uint32_t hseAttrCoreResetRelease_t;
#define HSE_CR_RELEASE_ALL_AT_ONCE        ((hseAttrCoreResetRelease_t)0xA5556933UL)  /**< @brief Cores are released all-at-once after the pre-boot verification phase is over */
#define HSE_CR_RELEASE_ONE_BY_ONE         ((hseAttrCoreResetRelease_t)0xA5557555UL)  /**< @brief Cores are released from reset one-by-one after their respective pre-boot phase has finalized successfully \
                                                                                                 (i.e. the SMR entries linked to the core via CR table have been loaded and verified). <br> \
                                                                                                 The cores are released in ascending order of their indicies in the Core Reset table. <br> \
                                                                                                 Flashless devices (e.g. HSE_H/M) limitations: \
                                                                                                  - Only the first Core Reset entry can be booted from SD/MMC. \
                                                                                                  - The system clocks and QSPI configurations shall not be changed by the core(s) booted until #HSE_STATUS_BOOT_OK status is set. */

/*==================================================================================================
                                 Debug Authorization Mode bit
==================================================================================================*/
/** @brief    Debug Authorization Mode bit (OTP-ATTR attribute; refer to #hseAttrId_t).
 * @details   Tells whether the Application debug authorization will be password based or challenge-response based.
*/
typedef uint8_t hseAttrDebugAuthMode_t;
#define HSE_DEBUG_AUTH_MODE_PW          ((hseAttrDebugAuthMode_t)0x0U)            /**< @brief Password based application debug authorization mode. \
                                                                                     - Read: Application debug authorization will be password based. \
                                                                                     - Write: Does not affect application debug authorization mode at all. */
#define HSE_DEBUG_AUTH_MODE_CR          ((hseAttrDebugAuthMode_t)0x1U)            /**< @brief Challenge-Response based application debug authorization mode. \
                                                                                     - Read: Application debug authorization will be challenge-response based. \
                                                                                     - Write: Enables challenge-response application debug authorization mode. \
                                                                                              Once this mode is enabled, it cannot be disabled. \
                                                                                              Operation allowed in CUST_DEL, OEM_PROD and IN_FIELD LCs only. */


/*==================================================================================================
                                 Application Debug Key/ Password definition-
==================================================================================================*/
/** @brief    Application Debug Key/ Password definition  (OTP-ATTR attribute; refer to #hseAttrId_t).
 * @details   It is an 128-bit Application Debug Key/ Password to be set by the host in CUST_DEL LifeCycle.
 *            - Read: Not allowed if ADKP has not been written yet. After it has been written, first 16 bytes of SHA2_224(ADKP) can be requested via get ADKP attribute service.
 *            - Write: ADKP can be updated only once. The operation allowed only in CUST_DEL LifeCycle.
 *
 * @note      Provided ADKP, if containing all 0x00 bytes or all 0xFF bytes will be rejected by HSE Firmware with the response #HSE_SRV_RSP_INVALID_PARAM.
 */
typedef uint8_t hseAttrApplDebugKey_t[16];

/** @brief    Secure Application Debug Key/ Password definition (OTP-ATTR attribute; refer to #hseAttrId_t).
 * @details   It is the key handle referencing a key already installed in HSE. It must be an AES 128-bits key from RAM or NVM key catalogs.
 *            - Read: Allowed only as the hash over the ADKP (see Read from #hseAttrApplDebugKey_t).
 *            - Write:
 *                  - ADKP can be updated only once. The operation allowed only in CUST_DEL LifeCycle.
 *                  - The key referenced must be installed in HSE a priori. After the key is written successfully in the fuse as ADK/P, it will be erased from the RAM/NVM key catalog.
 */
typedef hseKeyHandle_t hseAttrSecureApplDebugKey_t;


/*==================================================================================================
                                 HSE Secure Lifecycle
==================================================================================================*/
/** @brief    HSE secure lifecycle definition (OTP-ADVANCE-ATTR attribute; refer to #hseAttrId_t).
 * @details   Represents HSE secure lifecycle. The lifecycle can be advanced only in forward direction.
 *            Warnings:
 *            - The lifecycle is read/scanned by hardware during the reset phase. Hence, a reset is recommended
 *            after each LC write-advance operation.
 *            - The lifecycle can be advanced to OEM_PROD/IN_FIELD only if the #HSE_APP_DEBUG_KEY_ATTR_ID attribute was set before.
 */
typedef uint8_t hseAttrSecureLifecycle_t;
#define HSE_LC_CUST_DEL                 ((hseAttrSecureLifecycle_t)0x4U)    /**< @brief Customer Delivery Lifecycle. \
                                                                                - Read: The current LC is CUST_DEL. \
                                                                                - Write: Advancement to this LC is not allowed (through HSE Firmware). */
#define HSE_LC_OEM_PROD                 ((hseAttrSecureLifecycle_t)0x8U)    /**< @brief OEM Production Lifecycle. \
                                                                                - Read: The current LC is OEM_PROD. \
                                                                                - Write: Advancement to this LC is allowed only once (from CUST_DEL LC). \
                                                                                         The key catalogs MUST be configured before advancing to this lifecycle. */
#define HSE_LC_IN_FIELD                 ((hseAttrSecureLifecycle_t)0x10U)    /**< @brief In-Field Lifecycle. \
                                                                                - Read: The current LC is IN_FIELD. \
                                                                                - Write: Advancement to this LC is allowed only once (from CUST_DEL, OEM_PROD LCs). \
                                                                                         The key catalogs MUST be configured before advancing to this lifecycle. */
#define HSE_LC_PRE_FA                   ((hseAttrSecureLifecycle_t)0x14U)    /**< @brief Pre-Failure Analysis Lifecycle. \
                                                                                - Read: The current LC is Pre-FA. \
                                                                                - Write: Advancement from/to this LC is NOT allowed (through HSE Firmware).*/
#define HSE_LC_SIMULATED_OEM_PROD       ((hseAttrSecureLifecycle_t)0xA6U)   /**< @brief Simulated OEM_PROD to avoid writing in FUSE/UTEST. A system reset will revert LC to FUSE/UTEST value. \
                                                                                - Read: The current LC is OEM_PROD. \
                                                                                - Write: Advancement to this LC is allowed only once (from CUST_DEL LC). \
                                                                                         The key catalogs MUST be configured before advancing to this lifecycle. */
#define HSE_LC_SIMULATED_IN_FIELD       ((hseAttrSecureLifecycle_t)0xA7U)   /**< @brief Simulated IN_FIELD to avoid writing in FUSE/UTEST. A system reset will revert LC to FUSE/UTEST value. \
                                                                                - Read: The current LC is IN_FIELD. \
                                                                                - Write: Advancement to this LC is allowed only once (from CUST_DEL, SIMULATED_OEM_PROD LCs). \
                                                                                         The key catalogs MUST be configured before advancing to this lifecycle. */


/*==================================================================================================
                                 IVT Boot Authentication configuration
==================================================================================================*/
/** @brief    Boot Authentication bit (OTP-ATTR attribute; refer to #hseAttrId_t).
 * @details   Value used by Boot ROM to check whether the IVT data needs be authenticated.
*/
typedef uint8_t hseAttrConfigBootAuth_t;
#define HSE_IVT_NO_AUTH             ((hseAttrConfigBootAuth_t)0x0U)            /**< @brief \
                                                                                    For HSE_H/M, the IVT/DCD/ST is not authenticated by BootROM: \
                                                                                     - Read: IVT/DCD/ST is not authenticated by BootROM. \
                                                                                     - Write: Does not affect IVT/ DCD authentication value at all. \
                                                                                   \
                                                                                    For HSE_B, the IVT configuration is not authenticated by Secure BAF: \
                                                                                     - Read: IVT is not authenticated by Secure BAF. \
                                                                                     - Write: Does not affect IVT configuration authentication value at all. \
                                                                               */
#define HSE_IVT_AUTH                ((hseAttrConfigBootAuth_t)0x1U)            /**< @brief \
                                                                                    For HSE_H/M, the IVT/DCD/ST to be authenticated by BootROM: \
                                                                                    - Read: IVT/DCD/ST is authenticated by BootROM. \
                                                                                    - Write: Sets IVT/DCD/ST authentication value. \
                                                                                    Once this value is set, it cannot be cleared back. \
                                                                                    Operation allowed in CUST_DEL, OEM_PROD & IN_FIELD LCs only. \
                                                                                    \
                                                                                    For HSE_B, the IVT to be authenticated by Secure BAF: \
                                                                                     - Read: IVT will be authenticated by Secure BAF. \
                                                                                     - Write: Sets IVT authentication value. \
                                                                                    Once this value is set, it cannot be cleared back. \
                                                                                    Operation allowed in CUST_DEL, OEM_PROD & IN_FIELD LCs only. \
                                                                               */


/*==================================================================================================
                                 MU Configuration and XRDC configuration
==================================================================================================*/
/** @brief    MU configuration byte (HSE_H/M/B attribute).
 * @details   Tells whether the HSE enables the receive interrupt on the configured MU interface.
*/
typedef uint8_t hseMUConfig_t;
#define HSE_MU_ACTIVATED       ((hseMUConfig_t)(0xA5U))                   /**< @brief HSE enables the receive interrupt on the MU interface. */
#define HSE_MU_DEACTIVATED     ((hseMUConfig_t)(0x5AU))                   /**< @brief HSE disables the receive interrupt on the MU interface. */

/** @brief    MU Configuration and XRDC configuration definition for a MU interface.
 * @details   Configures a MU interface and XRDC configuration for the HOST Interface Memory.
 *            @note
 *                  If the device does have (or use) any Host Interface memory, the xrdcDomainId and
 *                  sharedMemChunkSize can be set zero.
 */
typedef struct
{
    hseMUConfig_t muConfig;                 /**< @brief    This value specifies MU interface state.
                                                           - #HSE_MU_ACTIVATED:      MU interface activated
                                                           - #HSE_MU_DEACTIVATED:    MU interface deactivated
                                                           @note It is not allowed to deactivate the MU0 interface */

    uint8_t xrdcDomainId;                   /**< @brief    Domain Id to access the Host Interface memory chunk reserved for
                                                           the MU interface. Must have a value between interval [0, 7].
                                                           The xrdcDomainId field is not taken into account when the
                                                           #sharedMemChunkSize field is equal to 0. */
    uint16_t sharedMemChunkSize;            /**< @brief    Specifies what chunk of host interface memory to reserve for
                                                           the specific MU interface.
                                                           For a value of 0 there is no memory reserved for the MU interface.
                                                           If the #sharedMemChunkSize field is equal to 0 for all MU interfaces,
                                                           the XRDC is disabled and there are no restrictions on the host
                                                           interface memory. */
    uint8_t reserved[60];
} hseAttrMUInstanceConfig_t;

/** @brief    MU Configurations and XRDC configuration definition (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 * @details   Configures the MU interfaces and XRDC configurations for the HOST Interface Memory.
 *
 *            @note:
 *            - SU rights are needed
 */
typedef struct
{
    hseAttrMUInstanceConfig_t muInstances[HSE_NUM_OF_MU_INSTANCES];   /**< @brief   Contains the configurations for all MU interfaces */
} hseAttrMUConfig_t;


/*==================================================================================================
                                 HSE Memory region
==================================================================================================*/
#ifdef HSE_SPT_MEM_REGION_PROTECT

/** @brief Access types for #HSE_SPT_MEM_REGION_PROTECT service regions */
typedef uint32_t hseMemRegAccess_t;
#define HSE_MEM_REG_ACCESS_MASK_IN     ((hseMemRegAccess_t)(0x00003C96UL))
#define HSE_MEM_REG_ACCESS_MASK_OUT    ((hseMemRegAccess_t)(0x5A690000UL))
#define HSE_MEM_REG_ACCESS_MASK_INOUT  ((hseMemRegAccess_t)(HSE_MEM_REG_ACCESS_MASK_IN | HSE_MEM_REG_ACCESS_MASK_OUT))

/**
* @brief        HSE Memory region.
* @details      Defines base address and length of a region
*/
typedef struct
{
    /** @brief     INPUT: Access type on which the region applies */
    hseMemRegAccess_t accessType;

    /** @brief     INPUT: Length of memory region */
    uint32_t          length;

    /** @brief     INPUT: Start address of memory region */
    HOST_ADDR         pBaseAddr;
} hseAttrMemRegion_t;

/**
* @brief        HSE Memory region attribute for a single MU.
* @details      Defines the number of regions and their start address
*               and sizes for a single MU
*/
typedef struct
{
    /** @brief     INPUT: Specify the number of memory regions for one MU.
     *             @note
     *             Set to zero if not used
     */
    uint8_t            numofMemRegions;

    uint8_t            reserved[3];

    /** @brief     INPUT: Specifies the memory regions for one MU */
    hseAttrMemRegion_t memRegionList[HSE_MAX_NUM_OF_MEM_REGIONS];
} hseAttrMuMemRegions_t;

/**
* @brief        HSE Memory regions protection attribute for all HSE MUs (SET-ONLY-ONCE-ATTR attribute; refer to #hseAttrId_t).
* @details      HSE Memory regions protection is a service used to prevent memory accesses
*               between disallowed bus masters through HSE MUs.
*               HSE uses these regions to validate the input/output parameters
*               for each service received on the corresponding MU.
*               @note
*                 - The attribute is not persistent and can only be set once. <br>
*                   A reset is necessary for this configuration to be settable again.
*                 - Input and output data linked via pointers in the service descriptor (these are typically pointers to
*                   SRAM or DRAM) can be isolated between hosts using the
*                   HSE_MEM_REGIONS_PROTECT_ATTR_ID attribute. The host can communicate to HSE the
*                   memory ranges that are associated with each MU instance. If provided, the HSE dismisses the data
*                   that falls outside the ranges for a particular MU instance.
*
*/
typedef struct
{
    /** @brief     INPUT: Array with memory regions for all MUs */
    hseAttrMuMemRegions_t muMemRegions[HSE_NUM_OF_MU_INSTANCES];
} hseAttrAllMuMemRegions_t;

#endif /* HSE_SPT_MEM_REGION_PROTECT */

/*==================================================================================================
                                HSE key management policies
==================================================================================================*/
#ifdef HSE_SPT_KEY_MGMT_POLICIES

/** @brief    HSE key management policy regarding RAM public keys import (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 *  @details  Determines whether public keys can be imported without authentication in advanced LCs. <br>
 *            Default value is HSE_KM_POLICY_DEFAULT, i.e. HSE does not allow public key import in RAM, when having User rights, if they are not an authenticated key container. <br>
 *            Otherwise, if set to HSE_KM_POLICY_ALLOW_RAM_PUB_KEY_IMPORT, RAM public keys are allowed to be imported without authentication, regardless of the access rights. <br>
 *            SU access rights with configuration privileges are required to update this attribute value.
 *
 *  @note:
 *            - SU rights are needed
*/
typedef uint32_t hseAttrRamPubKeyImportPolicy_t;
#define HSE_KM_POLICY_DEFAULT                   ((hseAttrRamPubKeyImportPolicy_t)(0x4E8BD124UL))
#define HSE_KM_POLICY_ALLOW_RAM_PUB_KEY_IMPORT  ((hseAttrRamPubKeyImportPolicy_t)(0xB1742EDBUL))

#endif /* HSE_SPT_KEY_MGMT_POLICIES */

/*==================================================================================================
                                 HSE extend CUST security policies
==================================================================================================*/
#ifdef HSE_SPT_CUST_SEC_POLICY

/** @brief    HSE extend CUST security policies attribute definition (OTP-ATTR & NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 * @details   Determines whether certain security policies are extended in HSE Firmware or not; applies only for CUST_DEL LC.
 *            - Read: Tells which extended security policies are set or not.
 *            - Write:
 *                   - If a given policy is not set to be TRUE, there is no change on security policy extension.
 *                   - If a given policy is set to be TRUE, security policy is extended on successful operation.
 *                   - Write operation is allowed only for users with CUST SU rights in CUST_DEL LC.
 */
typedef struct
{
    bool_t  enableADKm;      /**< @brief Application Debug Key/Password (attribute) diversified with UID before
                                        being written in fuse. The supplied 128-bit value for ADK/P attribute
                                        will be interpreted as ADKPm (customer's master key/ password). If needed,
                                        this policy must be set before setting ADK/P attribute. <br>
                                        If set, the following logic must be used at customer's end for debug-authorization:
                                         - hUID = SHA2_256(UID)
                                         - hADKPm = SHA2_256(ADKPm)
                                         - ADKP {for debugger} = AES256-ECB(hUID(16 bytes..0 to 15)), key = hADKPm;  {ADKPm = customer's master key/ password}.
                                         The hash of ADKPm (set using ADKP attribute) will be used as the key in the derivation of the application password.
                                         An error will be returned if the value of this attribute is given as 0 from host interface.
                                         @note For HSE_H/M, the UID is read by HSE from system fuses. The application must provide read access (xRDC restriction) to HSE in order to be able to read the UID.*/
    bool_t  startAsUser;     /**< @brief Host starts with User rights in LC = CUST_DEL.
                                        @note Setting this attribute will take effect only after publishing the SYS Image and issuing a reset. */
    uint8_t reserved[2];     /**< @brief HSE reserved */
} hseAttrExtendCustSecurityPolicy_t;

#endif /* HSE_SPT_CUST_SEC_POLICY */

/*==================================================================================================
                                 HSE extend OEM security policies
==================================================================================================*/
#ifdef HSE_SPT_OEM_SEC_POLICY

/** @brief    HSE extend OEM security policies attribute definition (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 * @details   Determines whether certain security policies are extended in HSE Firmware or not in OEM_PROD LC.
 *            - Read: Tells which extended security policies are set or not.
 *            - Write:
 *                   - If a given policy is not set to be TRUE, there is no change on security policy extension.
 *                   - If a given policy is set to be TRUE, security policy is extended on successful operation.
 *                   - Write operation is allowed only for users with OEM SU rights in OEM_PROD LC.
 */
typedef struct
{
    bool_t startAsUser;     /**< @brief Host starts with User rights in LC = OEM_PROD.
                                        @note Setting this attribute will take effect only after publishing the SYS Image and issuing a reset. */
    uint8_t reserved[3];    /**< @brief HSE reserved */
} hseAttrExtendOemSecurityPolicy_t;

#endif /* HSE_SPT_OEM_SEC_POLICY */


/*==================================================================================================
                                 Minimal tag bit length for Fast CMAC
==================================================================================================*/
#ifdef HSE_SPT_FAST_CMAC

/** @brief  Minimal tag bit length for Fast CMAC service (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 *  @details By default, the minimal tag bit length that can be used for the Fast CMAC service (see hseFastCMACSrv_t) is #HSE_DEFAULT_MIN_FAST_CMAC_TAG_BITLEN bits.
 *           This attribute can be set to be able to use the Fast CMAC service with the tag bit length less than #HSE_DEFAULT_MIN_FAST_CMAC_TAG_BITLEN bits.
 *           The value to be set must be provided in bits. */
typedef uint8_t hseAttrFastCmacMinTagBitLen_t;

#endif /* HSE_SPT_FAST_CMAC */


/*==================================================================================================
                                 External Tamper Configuration
==================================================================================================*/
#ifdef HSE_SPT_PHYSICAL_TAMPER_CONFIG

/** @brief    Activate or Deactivate a tamper
 * @details   Tells whether tamper needs to be activated or deactivated.
*/
typedef uint8_t hseTamperConfig_t;
#define HSE_TAMPER_CONFIG_DEACTIVATE        ((hseTamperConfig_t)(0U))            /**< @brief HSE Tamper Deactivate */
#define HSE_TAMPER_CONFIG_ACTIVATE          ((hseTamperConfig_t)(1U))            /**< @brief HSE Tamper Activate */

/** @brief    Tamper Polarity
 * @details   Specifies the polarity to activate the tamper. This configuration is applicable only
 * for passive tamper configuration. User must set the default state of the tamper input pin accordingly on the board.
 * For example: If the tamper polarity is set "ACTIVE_HIGH" then the default state on the tamper input pin must be "ACTIVE LOW".
*/
typedef uint8_t hseTamperPolarity_t;
#define HSE_TAMPER_POL_ACTIVE_LOW           ((hseTamperPolarity_t)(0U))           /**< @brief HSE Tamper Active low polarity*/
#define HSE_TAMPER_POL_ACTIVE_HIGH          ((hseTamperPolarity_t)(1U))           /**< @brief HSE Tamper Active high polarity*/

/** @brief     Filter Duration
  * @details   This macro describes the maximum filter duration that is possible for the physical tamper.
  *            The clock frequency used in the glitch filter is 32 KHz.
  */
#define HSE_FILTER_DURATION_MAX             ((uint32_t)128U)

/** @brief    Tamper routing configuration
 * @details   This configuration defines the type of tamper (i.e. active or passive).
 *  - In case of active tamper, the clock is derived on GPIO pad which should be routed back to
 * the input tamper pin on the ECU. User must configure the alternate functionality of
 * GPIO pin to tamper output so that the clock can be routed on that pin.
 *  - In case of passive tamper, HSE senses the change in polarity of the input pin. In this case, there is
 * no need to configure the active tamper pin. Only external tamper pin should be configured.
 *  - User is recommended to refer the SIUL chapter in SOC reference manual to configure the
 * correct GPIO pin.
 * For some SOC types, only one active tamper can be
 * supported. Please refer to #HSE_NUM_OF_PHYSICAL_TAMPER_INSTANCES to see how many active tamper are supported.
 * @note #HSE_TAMPER_ACTIVE_TWO is not valid for devices - S32G2, S32K3xx
 * */
typedef uint8_t hseOutputPinConfig_t;
#define HSE_TAMPER_PASSIVE                  ((hseOutputPinConfig_t)(0U))
#define HSE_TAMPER_ACTIVE_ONE               ((hseOutputPinConfig_t)(1U))
#define HSE_TAMPER_ACTIVE_TWO               ((hseOutputPinConfig_t)(2U))

/** @brief    Tamper clock that needs to be driven on the tamper output pad
 * @details   Tamper clock that needs to be driven on the tamper output pad.
 *  Please note that the alternate functionality of GPIO pin must be configured
 *  (for the tamper functionality) so that below the mentioned clock can be
 *  driven on that pad. Not applicable for passive tamper configuration
*/
typedef uint8_t hseTamperOutputClock_t;
#define HSE_TAMPER_ACTIVE_CLOCK_16HZ        ((hseTamperOutputClock_t)(0U))
#define HSE_TAMPER_ACTIVE_CLOCK_8HZ         ((hseTamperOutputClock_t)(1U))
#define HSE_TAMPER_ACTIVE_CLOCK_4HZ         ((hseTamperOutputClock_t)(2U))
#define HSE_TAMPER_ACTIVE_CLOCK_2HZ         ((hseTamperOutputClock_t)(3U))

/** @brief    Enables the tamper violation in HSE subsystem for all physical tampers supported by the SOC.
 * @details   This service only enables the  tamper violation in HSE subsystem for all physical tampers supported by the SOC.
 * Once violation is active it cannot be disabled until next reset. <br>
 * Physical tamper feature can be configured in following two ways:
 * 1. Active Tamper Configuration
 * 2. Passive tamper configuration
 *  @note User must configure the GPIO pins for tamper functionality before calling this service; otherwise,
 *        a false violation can be triggered by HSE. User is also recommended to protect the tamper GPIO configuration
 *        using register protection, virtual wrapper and XRDC configuration against further modification by any application running on host side.
 */
typedef struct
{
    hseTamperConfig_t   tamperConfig;               /**< @brief This field indicates the tamper configuration to be enable or not. */

    hseOutputPinConfig_t tamperOutputConfig;        /**< @brief This parameter tells which type (Active or Passive) of input is connected to external tamper input.
                                                            If it is an active input, up to 2 tamper options can be selected as input source for external
                                                            tamper input. Based on the value of this parameter, the clock will be driven on this pad by HSE */

    uint8_t filterDuration;                         /**< @brief Configures the length of the digital glitch filter for the external tamper
                                                            pin between 128 and 32640 SIRC clock cycles. Any assertion on external tamper that is
                                                            equal to or less than the value of the digital glitch filter is ignored.
                                                            The length of the glitches filtered out is:
                                                            -  128 + ((FilterDuration - 1) x 256), where FilterDuration = 1, ... , 128. <br>
                                                            If the FilterDuration value is 0, then the glitch filter will not be enabled.
                                                            Filter Duration is a must requirement for Active Tamper and optional for Passive Tamper. */

    hseTamperPolarity_t tamperPolarity;             /**< @brief This field indicates the polarity of the tamper to be be configured.
                                                            It can be "Active LOW" or "Active HIGH".  This parameter is
                                                            considered only when the tamper source in tamperOutputConfig is selected as passive */

    hseTamperOutputClock_t tamperActiveClock;       /**< @brief Determines the clock to be driven on the output pad of the tamper. This parameter is
                                                            considered only when the tamper source in tamperOutputConfig is selected as active */

    uint8_t reserved[3];                            /**< @brief HSE reserved */
} hseAttrPhysicalTamper_t;

/** @brief    Physical Tamper Configurations (SET-ONLY-ONCE-ATTR attribute; refer to #hseAttrId_t).
 * @details   Configures all available physical tamper instances.
 */
typedef struct
{
    hseAttrPhysicalTamper_t tamperInstances[HSE_NUM_OF_PHYSICAL_TAMPER_INSTANCES];   /**< @brief Contains the configuration for all the physical temper interfaces */
} hseAttrPhysicalTamperConfig_t;

#endif /* HSE_SPT_PHYSICAL_TAMPER_CONFIG */

/*==================================================================================================
                                 HSE_APP_SPECIFIC_DATA Attribute
==================================================================================================*/
#ifdef HSE_SPT_APP_SPECIFIC_DATA_ATTR

/** @brief   Application-Specific Data stored in SYS-IMG (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
*   @details It can be used to store persistent application data.
*
*   @note
*   - The attribute can be read at any time without any restriction. If the attribute is not set previously,
*     a read request will fail.
*   - If one of the following conditions is met the attribute cannot be set:
*     1. If writing was disabled previously (see #hseDisableAppSpecificDataWrite_t)
*     2. At start-up, when BOOT_SEQ == 1 and the secure boot (SMR or BSB) fails
*     3. If any of the on-demand/runtime SMR specified in smrPeriodicOnDemand flags failed.
*/
typedef struct
{
    /** @brief     The data to be stored in SYS-IMG.
     *             Note: All bytes must be specified; if some bytes are not used, those can be set zero. */
    uint8_t  specificData[252U];

    /**< @brief    The on-demand or periodic SMR(s) that can be used to restrict
     *             the writing of the attribute; if any of the smrPeriodicOnDemand SMR verification fails, the attribute can not be written.
     *             Note: Set this field to zero if the on-demand or periodic SMR are not used. */
    uint32_t smrPeriodicOnDemand;
}hseAppSpecificData_t;

/** @brief   Disable the writing of Application-Specific Data attribute (SET-ONLY-ONCE-ATTR attribute; refer to #hseAttrId_t).
*   @details The write of Application-Specific Data attribute can be disabled
*            by setting this attribute as #HSE_CFG_YES.
* @note
*            - When BOOT_SEQ ==1, if the secure boot at start-up and the on-demand or periodic SMR
*              check (configured using #hseAppSpecificData_t service) fails, this attribute is automatically
*              set to #HSE_CFG_YES (application specific data can not be written).
*            - At start-up, the default value of the attribute is #HSE_CFG_NO.
*              The attribute can only be modified from #HSE_CFG_NO to #HSE_CFG_YES,
*              using the set attribute service. The attribute can be set only once,
*              meaning that once the attribute is set to #HSE_CFG_YES, it cannot be
*              set back to #HSE_CFG_NO in the current power cycle.
*/
typedef hseAttrCfg_t hseDisableAppSpecificDataWrite_t;

#endif /* HSE_SPT_APP_SPECIFIC_DATA_ATTR */

/*==================================================================================================
                                 HSE_H/M specific attributes
==================================================================================================*/
#if defined(HSE_SPT_FLASHLESS_DEV)
/*==================================================================================================
                                 HSE-Firmware Size
==================================================================================================*/
/** @brief    HSE-Firmware Size (RO-ATTR attribute; refer to #hseAttrId_t).
 * @details   Size of HSE-Firmware in bytes.
 */
typedef uint32_t hseAttrHseFwSize_t;


/*==================================================================================================
                                 Anti-rollback counter updates left
==================================================================================================*/
/** @brief    Anti-rollback counter updates left (RO-ATTR attribute; refer to #hseAttrId_t).
 *  @details  There are available 158 (or 190 on S32ZE) anti-rollback counter updates (fuses) for the key store and HSE firmware.
 *            After 158 updates, the key store and HSE firmware are not protected against rollbacks.
 */
typedef uint32_t hseAvailAntiRollbackCounter_t;


/*==================================================================================================
                                 HSE-Firmware used partition on load
==================================================================================================*/
/** @brief    HSE-Firmware used partition on load (RO-ATTR attribute; refer to #hseAttrId_t).
 *  @details   Specified the partition (primary or backup) used by BootRom to load the HSE Firmware.
 */
typedef uint8_t hseAttrFwPartition_t;
#define HSE_FW_PARTITION_PRIMARY        ((hseAttrFwPartition_t)0x1U)           /**< @brief HSE firmware was loaded from primary partition */
#define HSE_FW_PARTITION_BACKUP         ((hseAttrFwPartition_t)0x2U)           /**< @brief HSE firmware was loaded from back-up partition */

/*==================================================================================================
                                 Anti-rollback counter Info
==================================================================================================*/
/** @brief    Provides details about SYS-IMG and FW Blue image anti-rollback counters (RBC) from fuses and image's headers (RO-ATTR attribute; refer to #hseAttrId_t).
 * @details   This attribute (read-only) can be read by the host to return:
 *            - the OTP counter for SYS-IMG (from fuses)
 *            - the OTP counter for HSE FW (from fuses)
 *            - the counter from the loaded SYS-IMG header (returns 0xFF if the SYS-IMG was not loaded)
 *            - the counter from the loaded Blue FW image header (returns 0xFF if the FW was loaded from pink FW image)
 */
typedef struct
{
    /** @brief   The OTP counter for SYS-IMG (from fuses) */
    uint8_t sysImgOtpCounter;
    /** @brief   The OTP counter for HSE FW (from fuses) */
    uint8_t fwImgOtpCounter;
    /** @brief   The counter from the loaded SYS-IMG header. If the SYS-IMG was not loaded, it returns 0xFF.  */
    uint8_t sysImgHeaderCounter;
    /** @brief   The counter from the loaded Blue FW image header. If the FW was loaded from pink FW image, it returns 0xFF. */
    uint8_t fwImgHeaderCounter;
} hseRbCounterInfo_t;


/*==================================================================================================
                                 Application debug disable
==================================================================================================*/
/** @brief    Application debug disable (OTP-ATTR attribute; refer to #hseAttrId_t).
 * @details   Tells if the Application debug is disabled or not for OEM_PROD and/or IN_FIELD life-cycles.
*/
typedef uint8_t hseAttrDisableAppDebug_t;
#define HSE_APP_DEBUG_DIS_NONE          ((hseAttrDisableAppDebug_t)0x0U)       /**< @brief Application Debug not disabled. \
                                                                                    - Read: Application Debug is not disabled for OEM_PROD/ IN_FIELD LC.\
                                                                                    Application debug can be opened in OEM_PROD/ IN_FIELD LC using the debug \
                                                                                    authorization mechanism. \
                                                                                    - Write: Does not disable the application debug. */
#define HSE_APP_DEBUG_DIS_OEM           ((hseAttrDisableAppDebug_t)0x1U)       /**< @brief Application Debug disabled for OEM_PROD LC. \
                                                                                    - Read: Application Debug is disabled for OEM_PROD LC. \
                                                                                    Application debug can never be opened in OEM_PROD LC. \
                                                                                    - Write: Disables application debug for OEM_PROD LC only. \
                                                                                    Operation allowed in CUST_DEL, OEM_PROD & IN_FIELD LCs only. */
#define HSE_APP_DEBUG_DIS_FLD           ((hseAttrDisableAppDebug_t)0x2U)       /**< @brief Application Debug disabled for IN_FIELD LC. \
                                                                                    - Read: Application Debug is disabled for IN_FIELD LC. \
                                                                                    Application debug can never be opened in IN_FIELD LC. \
                                                                                    - Write: Disables application debug for IN_FIELD LC only. \
                                                                                    Operation allowed in CUST_DEL, OEM_PROD & IN_FIELD LCs only. */
#define HSE_APP_DEBUG_DIS_OEM_FLD       ((hseAttrDisableAppDebug_t)0x3U)       /**< @brief Application Debug disabled for both OEM_PROD & IN_FIELD LCs. \
                                                                                    - Read: Application Debug is disabled for both OEM_PROD & IN_FIELD LCs. \
                                                                                    Application debug can never be opened in OEM_PROD & IN_FIELD LCs. \
                                                                                     -Write: Disables application debug for both OEM_PROD & IN_FIELD LCs. \
                                                                                    Operation allowed in CUST_DEL, OEM_PROD & IN_FIELD LCs only. */

/*==================================================================================================
                                 OTP_BOOT_SEQ configuration
==================================================================================================*/
#ifdef HSE_SPT_OTP_BOOT_SEQ_ATTR
#define HSE_OTP_BOOT_SEQ_MARKER  (0xCEDEADDAUL) /**< @brief The marker that must be used when setting #hseAttrOtpBootSeq_t attribute. */
#define HSE_OTP_BOOT_SEQ_NOT_SET (0x00000000UL) /**< @brief The OTP_BOOT_SEQ is not set in fuses.*/

/** @brief    Set BOOT_SEQ flag in OTP (called OTP_BOOT_SEQ below);
 *            this is an OTP-ATTR attribute; refer to #hseAttrId_t.
 * @details   This attribute complements the BOOT_SEQ flag in IVT with a flag in OTP.
 *            Setting this attribute enforces the IVT's BOOT_SEQ (IVT_BOOT_SEQ) to 1.
 *            When setting this attribute:
 *            - the #HSE_OTP_BOOT_SEQ_MARKER marker must be used
 *            - the IVT_BOOT_SEQ  must be 1
 *            On read, if the OTP_BOOT_SEQ in fuses is set, HSE returns the HSE_OTP_BOOT_SEQ_MARKER marker;
 *            otherwise, it returns HSE_OTP_BOOT_SEQ_NOT_SET.
 *
 *            When the HSE FW starts, it verifies the value of OTP_BOOT_SEQ (from fuses) against the value of IVT_BOOT_SEQ as follows:
 *            - If(LC == OEM_PROD or IN_FIELD) and (OTP_BOOT_SEQ == 1) and (OTP_BOOT_SEQ != IVT_BOOT_SEQ), apply a functional reset;
 *              Otherwise, continue the boot sequence.
 *
 *            @note:
 *            - After 8 functional resets, BootROM enters serial boot mode.
 * */
typedef uint32_t hseAttrOtpBootSeq_t;
#endif /* HSE_SPT_OTP_BOOT_SEQ_ATTR */

/*==================================================================================================
                                 Temperature Sensor violation configuration
==================================================================================================*/
#ifdef HSE_SPT_TEMP_SENS_VIO_CONFIG
/** @brief    Temperature Sensor violation configuration byte (SET-ONCE-ATTR attribute; refer to #hseAttrId_t).
 * @details   Once the violation is enabled in HSE, it can not be cleared
 *            until next reset. User must configure the Temperature Monitoring Unit (TMU)
 *            before giving the attribute. It can also be configured via DCD configuration.
 *            The HSE Firmware signals an Fatal error (see hseError_t bits) if this tamper is detected.
 *            User is recommended to protect the TMU Registers (see REG_PROT on Soc) after the configuration.
 *            The tamper configuration status is available by reading the HSE_GPR_STATUS_ADDRESS register (refer to #hseTamperConfigStatus_t).
 *            Four TMU Monitors are mapped to HSE: Average High Critical Temperature TMU Monitor,
 *            Average Low Critical Temperature TMU Monitor, Rising Rate Critical Temperature TMU Monitor,
 *            Falling Rate Critical Temperature TMU Monitor.
 *
*/
typedef uint8_t hseTempSensVioConfig_t;
#define HSE_TEMP_SENS_VIO_ACTIVATED       ((hseTempSensVioConfig_t)(0xA5U))  /**< @brief HSE enables the temperature sensor violation in SNVS. */
#define HSE_TEMP_SENS_VIO_DEACTIVATED     ((hseTempSensVioConfig_t)(0x5AU))  /**< @brief HSE disables the temperature sensor violation in SNVS.  */
#endif /* HSE_SPT_TEMP_SENS_VIO_CONFIG */


/*==================================================================================================
                                 OTFAD context status
==================================================================================================*/
#ifdef HSE_SPT_OTFAD
/** @brief   OTFAD context status.
 *  @details After installation of the otfad context, the OTFAD region may be activated or deactivated.
 *           The OTFAD region may be deactivated because the #HSE_OTFAD_CTX_ACTIVE_ON_BOOT flag is not set during
 *           installation or due to a configuration error. */
typedef uint8_t hseOtfadContextStatus_t;
#define HSE_OTFAD_CTX_NOT_INSTALLED       ((hseOtfadContextStatus_t)(0x00U))    /**< @brief OTFAD context not installed. */
#define HSE_OTFAD_CTX_INSTALLED           ((hseOtfadContextStatus_t)(0xCAU))    /**< @brief OTFAD context installed but not configured. */
#define HSE_OTFAD_CTX_ACTIVE              ((hseOtfadContextStatus_t)(0xACU))    /**< @brief OTFAD context configured and active. */
#define HSE_OTFAD_CTX_INACTIVE            ((hseOtfadContextStatus_t)(0xDEU))    /**< @brief OTFAD context configured but not active. */

/** @brief   OTFAD context status (RO-ATTR attribute; refer to #hseAttrId_t).
 *  @details The OTFAD context status for all OTFAD entries. */
typedef struct
{
    hseOtfadContextStatus_t OtfadCtxStatus[HSE_NUM_OF_OTFAD_INSTANCES][HSE_NUM_OF_OTFAD_ENTRIES];   /**< @brief Contains the status for all OTFAD region. */
    #ifdef HSE_SPT_IEE_DDR_FLASH
    hseOtfadContextStatus_t ieeDdrCtxStatus[HSE_NUM_OF_IEE_DDR_ENTRIES];                            /**< @brief Contains the status for all IEE_DDR region. */
    uint8_t                 reserved;
    #endif /* HSE_SPT_IEE_DDR_FLASH */
} hseOtfadCtxStatus_t;
#endif /* HSE_SPT_OTFAD */


/*==================================================================================================
                                OTP Rollback Protection Policy
==================================================================================================*/

/** @brief   Configuration option for anti-rollback counter (anti-RBC) handling.
 *  @details Tells if the rollback protection mechanism is active or not, or
 *           if the anti-RBC is updated in fuses at boot time or on-demand by calling the #hseOnDemandAntiRbcUpdateSrv_t service.
 */
typedef uint32_t hseDisableAntiRbcCfg_t;
#define HSE_DIS_ANTI_RBC_CFG_NO         ((hseDisableAntiRbcCfg_t)(HSE_CFG_NO))    /**< @brief The rollback protection mechanism is enabled, \
                                                                                              and the anti-RBC counter is updated automatically at start-up \
                                                                                              if LC != CUST_DEL or BOOT_SEQ == 1 and at least one core is booted. \
                                                                                              This is the default configuration. */
#define HSE_DIS_ANTI_RBC_CFG_YES        ((hseDisableAntiRbcCfg_t)(HSE_CFG_YES))   /**< @brief The rollback protection is disabled (the rollback
                                                                                              protection mechanism is disabled and anti-RBC is not updated in fuses). */
#define HSE_ON_DEMAND_ANTI_RBC_UPDATE   ((hseDisableAntiRbcCfg_t)(0x676E2064UL))  /**< @brief The rollback protection mechanism is enabled, \
                                                                                              and the anti-RBC is updated in fuses only \
                                                                                              on-demand by calling the #hseOnDemandAntiRbcUpdateSrv_t service. */

/** @brief   Disable the OTP rollback protection when updating the FW Blue Image and/or SYS-IMG (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 *  @details After updating the new FW Blue Image or SYS-IMG (NVM keystore) in external flash, a system reset is needed to update the anti-rollback
 *           counter in OTP area (fuses). To be able to update the fuse counter, the VDD_EFUSE must be always powered or
 *           can be powered at start-up by HSE FW (if the VDD_EFUSE configuration word from IVT is supported; refer to the HSE Firmware Reference Manual).
 *           @note
 *           - Anti-rollback protection on FW-IMG is provided only when it is re-encrypted with a device specific key
 *            (only when the so called FW Blue Image is used).
 *           - SuperUser rights are needed to configure this attribute. */
typedef struct
{
    /** @brief This field controls the rollback protection configuration for FW Blue Image and/or SYS-IMG update.
     *         Enables or disable the rollback protection; if enabled, it configures if the anti-RBC is updated in fuses at boot time or on-demand.
     *         See #hseDisableAntiRbcCfg_t for more details. */
    hseDisableAntiRbcCfg_t disableOtpRollbackProtect;

    /** @brief Prevents the firmware from running if it was loading from a Pink FW Image.
     *         This configuration is ignored for non-secure boot.
     *         - HSE_CFG_NO (default configuration): allow HSE to run if the firmware was loading from a Pink or Blue FW Image.
     *         - HSE_CFG_YES: disallow HSE to run if firmware was loading from a Pink FW Image.
     *           Only the FW Blue Image can be used after setting this field to HSE_CFG_YES.
     *         @note
     *         - Only the Blue FW image provides the rollback protection. Once the disallowRunningFromPinkFWImage attribute is set,
     *           no FW pink image shall be used in primary or back-up locations (only Blue FW image must be used).
     *         - For secure-boot use case, if disallowRunningFromPinkFWImage == HSE_CFG_YES and the firmware was loaded from PINK FW image ,
     *           HSE performs a function reset; otherwise, it will continue its execution.
     *         - For non-secure boot, this configuration is ignored. */
    hseAttrCfg_t disallowRunningFromPinkFWImage;
} hseOtpRollbackProtectionPolicy_t;

#endif /* HSE_SPT_FLASHLESS_DEV */



/*==================================================================================================
                                 HSE_B specific attributes
==================================================================================================*/
#ifdef HSE_B
/*==================================================================================================
                                 FIRC Divider Configuration
==================================================================================================*/
/** @brief  FIRC Divider Configuration by HSE Firmware from HSE GPR.*/
typedef uint8_t hseFircDivConfig_t;
#define HSE_FIRC_NO_CONFIG                ((hseFircDivConfig_t)0U)       /**< @brief No Configuration. */
#define HSE_FIRC_DIV_BY_1_CONFIG          ((hseFircDivConfig_t)1U)       /**< @brief HSE enables the FIRC divider by 1. */
#define HSE_FIRC_DIV_BY_2_CONFIG          ((hseFircDivConfig_t)2U)       /**< @brief HSE enables the FIRC divider by 2. */
#define HSE_FIRC_DIV_BY_16_CONFIG         ((hseFircDivConfig_t)16U)      /**< @brief HSE enables the FIRC divider by 16. */


/*==================================================================================================
                                 HSE_B Configure Secure Recovery
==================================================================================================*/
/** @brief    Secure Recovery bit (OTP-ATTR attribute).
 * @details   This setting is used by SecureBAF/HSE Firmware to check whether the firmware enters in the Secure Recovery state or not.
*/
typedef uint8_t hseAttrConfigSecureRecovery_t;
#define HSE_SECURE_RECOVERY_DISABLE             ((hseAttrConfigSecureRecovery_t)0x0U)            /**< @brief \
                                                                                                  * - Secure Recovery is disabled by HSE Firmware. \
                                                                                                  * - Write: It does not affect the value at all. \
                                                                                                  */

#define HSE_SECURE_RECOVERY_ENABLE              ((hseAttrConfigSecureRecovery_t)0x1U)            /**< @brief \
                                                                                                  * - Secure Recovery is enabled by HSE Firmware. \
                                                                                                  * - Write: It enables the Secure Recovery mode. \
                                                                                                  */


/*==================================================================================================
                                 HSE_B Publish NVM Keystore RAM to FLASH
==================================================================================================*/
#if defined(HSE_SPT_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH)

/** @brief HSE Publish NVM Keystore RAM to Flash
* @details This service can be used to reduce the number of write operations in the data flash, and increase the performance when the key store is updated.
* At start-up, the HSE FW loads the NVM key from data flash into the secure RAM (NVM keys are mirrored in RAM).
* After loading, the NVM keys are used only from RAM memory. At key update/erase, both the mirrored RAM area and the data flash for the keys are updated.
*
* - By default, the attribute is set to #HSE_CFG_NO; this means that during key import (or load key) service,
* HSE updates the NVM keys to both the mirrored RAM area and the data flash.
* - By setting this attribute to #HSE_CFG_YES, the HSE FW will update the NVM keys only in the mirror RAM memory.
* To perform the flash write operation, the application must call the #HSE_SRV_ID_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH service.
*
* @note
* This attribute is available in Cust-Del and Oem-Prod LC only.
*/
typedef hseAttrCfg_t hsePublishNvmKeystoreRamtToFlash_t;

#endif /* defined(HSE_SPT_PUBLISH_NVM_KEYSTORE_RAM_TO_FLASH) */

#endif /* HSE_B */


/*==================================================================================================
                                 RESET_SOC_ON_TAMPER Attribute
==================================================================================================*/
#ifdef HSE_SPT_RESET_SOC_ON_TAMPER_ATTR

/** @brief   HSE Reset Soc on tamper detection (NVM-RW-ATTR attribute; refer to #hseAttrId_t).
 *  @details By default HSE does not reset the Soc on tamper detection (this attribute is configured as #HSE_CFG_NO),
 *           Instead it signals an HSE error (see #hseError_t) and enter shutdown mode.
 *           To reset the Soc, the host application must set this attribute to #HSE_CFG_YES and publish SYS-IMG.
 *           On next boot, HSE configures the attribute.
 *  @note
 *  The Application must have SU rights to configure this attribute.*/
typedef hseAttrCfg_t hseResetSocOnTamper_t;

#endif /* HSE_SPT_RESET_SOC_ON_TAMPER_ATTR */

#ifdef HSE_SPT_SENSOR_ARMING
/**
 * @brief    Disarm the selected security sensors at start-up.
 * @details  For each available sensor a byte is assigned in the #sensorCfg[] parameter;
 *           each sensorCfg[sensor_index] can have the values specified by #hseSensorState_t.
 *           The host can read the #hseSensorsStateAttr_t to get the list with the state of each sensor that can be configured by the application.
 *           This attribute allows configuring the following behavior during start-up phase:
 *           1. if sensorCfg[sensor_index] == HSE_SENSOR_UNUSED, the state of the sensor is not changed and left in the state set by the hardware/BootROM.
 *           2. if BOOT_SEQ == 0 and sensorCfg[sensor_index] == HSE_SENSOR_DISARMED, the sensor is disarmed after loading/verifying SYS-IMG.
 *           3. if BOOT_SEQ == 1 and sensorCfg[sensor_index] == HSE_SENSOR_DISARMED, the sensor is disarmed after verifying the SMR/BSB and before
 *              releasing any application core from reset (based on Core Reset table). <br>
 *           Additionally, this attribute allows/disallows to use the #hseOnDemandSensorArming_t service during runtime.
 *
 *           Default configuration:
 *           - state of sensors is not changed and left in the state set by the hardware/BootROM
 *           - #hseOnDemandSensorArming_t service can NOT be used at runtime (allowOnDemandSensorArming == HSE_CFG_NO)
 *
 *           @note
 *           - SU right are needed to configure this attribute.
 *           - Only the sensors provided by #HSE_SENSORS_STATE_ATTR_ID attribute (read-only) can be disarmed.
 *             Otherwise, the HSE_SRV_RSP_NOT_ALLOWED status is returned.
 *           - This attribute allows to disarm sensors at start-up to mitigate the risk of HSE entering into shutdown mode due to customer execution environment.
 */
typedef struct
{
    /** @brief   INPUT: Specifies the list of sensor bytes (one byte of each sensor) to disarm the available
     *                  sensors at startup (refer to #hseSensorState_t).
     *                  Only HSE_SENSOR_DISARMED (disarmed) and HSE_SENSOR_UNUSED (keep it as it is) options can be used.
     *                  @note
     *                      - The sensor byte is ignored if it is set to #HSE_SENSOR_UNUSED.*/
    hseSensorState_t    sensorCfg[8U];
    /** @brief   INPUT: Allow/disallow to use the #hseOnDemandSensorArming_t service during runtime.
     *                  By default, this parameter is set to HSE_CFG_NO (#hseOnDemandSensorArming_t service can NOT be used) */
    hseAttrCfg_t        allowOnDemandSensorArming;
    uint8_t             reserved[8U];
} hseSensorDisarmingAttr_t;
#endif /* HSE_SPT_SENSOR_ARMING */

/** @brief   Disable the pair wise consistency test at import for RSA/ECC/DH key pairs (SET-ONLY-ONCE-ATTR attribute; refer to #hseAttrId_t).
 *  @details By default, when importing a RSA/ECC/DH key pair, HSE checks the pair wise consistency of the provided public and private keys.
 *           Since this operation is time consuming, the host can disable this check to speed up the key import operation.
 *           To disable the pair wise consistency test, the host must set this attribute to #HSE_CFG_YES.
 *           By default, this attribute is set to #HSE_CFG_NO (pair wise consistency is checked).
 *
 *           @note: This is a "SET-ONLY-ONCE-ATTR" attribute.
 *           The attribute can only be set from #HSE_CFG_NO to #HSE_CFG_YES,
 *           using the set attribute service. Once the attribute is set to #HSE_CFG_YES,
 *           it cannot be set back to #HSE_CFG_NO in the current power cycle.
 */
typedef hseAttrCfg_t hseDisablePairWiseConsistencyTest_t;

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

#endif /* HSE_SRV_ATTR_H */

/** @} */
