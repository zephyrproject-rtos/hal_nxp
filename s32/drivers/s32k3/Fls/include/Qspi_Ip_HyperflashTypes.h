/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_HYPERFLASHTYPES_H
#define QSPI_IP_HYPERFLASHTYPES_H

/**
*   @file Qspi_Ip_HyperflashTypes.h
*
*   @addtogroup IPV_QSPI QSPI IPV Driver
*   @{
*/

/* implements Qspi_Ip_HyperflashTypes.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERFLASHTYPES_VENDOR_ID                    43
#define QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_MAJOR_VERSION     4
#define QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_MINOR_VERSION     7
#define QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_REVISION_VERSION  0
#define QSPI_IP_HYPERFLASHTYPES_SW_MAJOR_VERSION             3
#define QSPI_IP_HYPERFLASHTYPES_SW_MINOR_VERSION             0
#define QSPI_IP_HYPERFLASHTYPES_SW_PATCH_VERSION             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Qspi_Ip_HyperflashTypes header file and StandardTypes.h header file are of the same Autosar version */
    #if ((QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_HYPERFLASHTYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Qspi_Ip_HyperflashTypes.h and StandardTypes.h are different"
    #endif
#endif


/*******************************************************************************
* Definitions
******************************************************************************/

/* Address of the sector selected. Address bits AMAX-A17 for 256KB sectors and AMAX-A11 for 4KB parameter sectors
   Parameter-sectors need A[16:11] to identify the target address during erase and program command sequences
   Unused bits are "no matter" (memory device will ignore them), so just use the smallest size in both cases
 */
#define QSPI_IP_HYPERFLASH_SECTOR_SIZE    0x1000U  /* 4096-byte */


/* LUT entries used for hyperflash command sequences */
#define QSPI_IP_HF_LUT_COMMON_555_AA     0U  /* Pre-command with address 0x555 and operand 0xAA */
#define QSPI_IP_HF_LUT_COMMON_2AA_55     6U  /* Pre-command with address 0x2AA and operand 0x55 */
#define QSPI_IP_HF_LUT_READ             12U  /* Read data linear                                */
#define QSPI_IP_HF_LUT_WRITE            18U  /* Write data                                      */
#define QSPI_IP_HF_LUT_RDSR             23U  /* Read status register                            */
#define QSPI_IP_HF_LUT_RDSR_SEQ2        29U  /* Read status register second sequence            */
#define QSPI_IP_HF_LUT_WP               35U  /* Word Programming                                */
#define QSPI_IP_HF_LUT_WP_SEQ1          41U  /* Word Programming second sequence                */

#define QSPI_IP_HF_LUT_CMD_80           46U
#define QSPI_IP_HF_LUT_CMD_AA           52U
#define QSPI_IP_HF_LUT_CMD_55           58U
#define QSPI_IP_HF_LUT_SE               64U
#define QSPI_IP_HF_LUT_CE               70U
#define QSPI_IP_HF_LUT_RST              76U
#define QSPI_IP_HF_LUT_SRC              82U
#define QSPI_IP_HF_LUT_BC               88U
#define QSPI_IP_HF_LUT_CMD_25           94U
#define QSPI_IP_HF_LUT_WC               100U
#define QSPI_IP_HF_LUT_WB               106U
#define QSPI_IP_HF_LUT_PBF              111U
#define QSPI_IP_HF_LUT_PS               117U  /* Program suspend               */
#define QSPI_IP_HF_LUT_PR               123U  /* Program resume               */
#define QSPI_IP_HF_LUT_ES               129U  /* Erase suspend               */
#define QSPI_IP_HF_LUT_ER               135U  /* Erase resume               */
#define QSPI_IP_HF_LUT_RDNVCR           141U
#define QSPI_IP_HF_LUT_ENVCR            147U
#define QSPI_IP_HF_LUT_PNVCR            153U
#define QSPI_IP_HF_LUT_LDVCR            159U
#define QSPI_IP_HF_LUT_CMD_98           165U

#define QSPI_IP_HF_LUT_SIZE             171U
#define QSPI_IP_HF_LUT_NAME             Qspi_Ip_HyperflashLutTable

/* Number of commands in the software reset sequence */
#define QSPI_IP_HF_RST_CNT              1U


/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/*!
* @brief Parameter sector map
*
* This structure is used to configure how the Parameter-Sectors are used and how they are mapped into the address map.
*/
typedef enum 
{
    QSPI_IP_HF_PARAM_AND_PASSWORD_MAP_LOW            = 0x00U,
    QSPI_IP_HF_PARAM_AND_PASSWORD_MAP_HIGH           = 0x01U,
    QSPI_IP_HF_UNIFORM_SECTORS_READ_PASSWORD_LOW     = 0x02U,
    QSPI_IP_HF_UNIFORM_SECTORS_READ_PASSWORD_HIGH    = 0x03U
} Qspi_Ip_HyperflashParamSectorMapType;


/*!
* @brief Drive strength
*
* Hyperflash driver strength settings.
*/
typedef enum
{
    QSPI_IP_HF_DRV_STRENGTH_000 = 0x00U,  /*!< Typical Impedance for 1.8V: 27,  Typical Impedance 3V: 20 */
    QSPI_IP_HF_DRV_STRENGTH_001 = 0x01U,  /*!< Typical Impedance for 1.8V: 117, Typical Impedance 3V: 71 */
    QSPI_IP_HF_DRV_STRENGTH_002 = 0x02U,  /*!< Typical Impedance for 1.8V: 68,  Typical Impedance 3V: 40 */
    QSPI_IP_HF_DRV_STRENGTH_003 = 0x03U,  /*!< Typical Impedance for 1.8V: 45,  Typical Impedance 3V: 27 */
    QSPI_IP_HF_DRV_STRENGTH_004 = 0x04U,  /*!< Typical Impedance for 1.8V: 34,  Typical Impedance 3V: 20 */
    QSPI_IP_HF_DRV_STRENGTH_005 = 0x05U,  /*!< Typical Impedance for 1.8V: 27,  Typical Impedance 3V: 16 */
    QSPI_IP_HF_DRV_STRENGTH_006 = 0x06U,  /*!< Typical Impedance for 1.8V: 24,  Typical Impedance 3V: 14 */
    QSPI_IP_HF_DRV_STRENGTH_007 = 0x07U   /*!< Typical Impedance for 1.8V: 20,  Typical Impedance 3V: 12 */
} Qspi_Ip_HyperflashDrvStrengthType;


/*!
* @brief Read latency
*
*/
typedef enum
{
    QSPI_IP_HF_READ_LATENCY_5_CLOCKS  = 0U,  /*!< Read latency 5 clocks  */
    QSPI_IP_HF_READ_LATENCY_6_CLOCKS  = 1U,  /*!< Read latency 6 clocks  */
    QSPI_IP_HF_READ_LATENCY_7_CLOCKS  = 2U,  /*!< Read latency 7 clocks  */
    QSPI_IP_HF_READ_LATENCY_8_CLOCKS  = 3U,  /*!< Read latency 8 clocks  */
    QSPI_IP_HF_READ_LATENCY_9_CLOCKS  = 4U,  /*!< Read latency 9 clocks  */
    QSPI_IP_HF_READ_LATENCY_10_CLOCKS = 5U,  /*!< Read latency 10 clocks */
    QSPI_IP_HF_READ_LATENCY_11_CLOCKS = 6U,  /*!< Read latency 11 clocks */
    QSPI_IP_HF_READ_LATENCY_12_CLOCKS = 7U,  /*!< Read latency 12 clocks */
    QSPI_IP_HF_READ_LATENCY_13_CLOCKS = 8U,  /*!< Read latency 13 clocks */
    QSPI_IP_HF_READ_LATENCY_14_CLOCKS = 9U,  /*!< Read latency 14 clocks */
    QSPI_IP_HF_READ_LATENCY_15_CLOCKS = 10U, /*!< Read latency 15 clocks */
    QSPI_IP_HF_READ_LATENCY_16_CLOCKS = 11U  /*!< Read latency 16 clocks */
} Qspi_Ip_HyperflashReadLatencyType;


/* ASO entries */
typedef enum
{
    QSPI_IP_HF_PASSWORD_ASO_ENTRY = 0x60,  /*!< Password ASO Entry command                    */
    QSPI_IP_HF_PPB_ASO_ENTRY      = 0xC0,  /*!< PPB ASO Entry command                         */
    QSPI_IP_HF_PPB_LOCK_ASO_ENTRY = 0x50,  /*!< PPB Lock ASO Entry command                    */
    QSPI_IP_HF_DYB_ASO_ENTRY      = 0xE0,  /*!< DYB ASO Entry command                         */
    QSPI_IP_HF_ECC_ASO_ENTRY      = 0x75,  /*!< ECC ASO Entry command                         */
    QSPI_IP_HF_SSR_ASO_ENTRY      = 0x88,  /*!< Secure Silicon Region command                 */
    QSPI_IP_HF_CRC_ASO_ENTRY      = 0x78,  /*!< CRC ASO Entry command                         */
    QSPI_IP_HF_ASPR_ASO_ENTRY     = 0x40,  /*!< ASP Configuration Register ASO entry command  */
    QSPI_IP_HF_FLASH_MEMORY_ARRAY = 0x00   /*!< No ASO entry                                  */
} Qspi_Ip_HyperflashAsoEntryCommandsType;


/*!
* @brief Sector protection type
*
*/
typedef enum
{
    QSPI_IP_HF_SECTOR_UNLOCKED          = 1U,  /* Sector is not protected                   */
    QSPI_IP_HF_SECTOR_LOCKED_BY_PPB     = 2U,  /* Sector is protected by PPB bit            */
    QSPI_IP_HF_SECTOR_LOCKED_BY_DYB     = 3U,  /* Sector is protected by DYB bit            */
    QSPI_IP_HF_SECTOR_LOCKED_BY_PPB_DYB = 4U   /* Sector is protected by PPB and DYB bits   */
} Qspi_Ip_HyperflashSectorProtectionType;


/*******************************************************************************
* Structures
******************************************************************************/

/*!
* @brief Hyperflash configuration structure
*
 * This structure is used to provide configuration parameters for HyperFlash
 * at initialization time.
*/
typedef struct
{
    Qspi_Ip_HyperflashDrvStrengthType    outputDriverStrength;  /*!< Output driver level of the device                    */
    boolean                              RWDSLowOnDualError;    /*!< Specifies if RWDS will stall upon Dual Error Detect  */
    boolean                              secureRegionUnlocked;  /*!< If true, the secure silicon region will be locked    */
    Qspi_Ip_HyperflashReadLatencyType    readLatency;           /*!< Read latency                                         */
    Qspi_Ip_HyperflashParamSectorMapType paramSectorMap;        /*!< Parameter sector mapping                             */
    uint32                               deviceIdWordAddress;   /*!< The word address of the device Id in ASO             */
} Qspi_Ip_HyperFlashConfigType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_HYPERFLASHTYPES_H */
