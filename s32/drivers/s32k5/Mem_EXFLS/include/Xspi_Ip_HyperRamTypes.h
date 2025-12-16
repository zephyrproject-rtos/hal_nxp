/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_HYPERRAMTYPES_H
#define XSPI_IP_HYPERRAMTYPES_H

/**
*   @file Xspi_Ip_HyperRamTypes.h
*
*   @addtogroup IPV_XSPI
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_HYPERRAMTYPES_VENDOR_ID                    43
#define XSPI_IP_HYPERRAMTYPES_AR_RELEASE_MAJOR_VERSION     4
#define XSPI_IP_HYPERRAMTYPES_AR_RELEASE_MINOR_VERSION     9
#define XSPI_IP_HYPERRAMTYPES_AR_RELEASE_REVISION_VERSION  0
#define XSPI_IP_HYPERRAMTYPES_SW_MAJOR_VERSION             0
#define XSPI_IP_HYPERRAMTYPES_SW_MINOR_VERSION             8
#define XSPI_IP_HYPERRAMTYPES_SW_PATCH_VERSION             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Xspi_Ip_HyperRamTypes header file and Std_Types.h header file are of the same Autosar version */
    #if ((XSPI_IP_HYPERRAMTYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (XSPI_IP_HYPERRAMTYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Xspi_Ip_HyperRamTypes.h and Std_Types.h are different"
    #endif
#endif


/*******************************************************************************
* Definitions
******************************************************************************/
#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)

/* LUT entries used for hyperflash command sequences */
#define XSPI_IP_HR_LUT_SIZE             23U

#define XSPI_IP_HR_LUT_READ             0U
#define XSPI_IP_HR_LUT_WRITE            6U
#define XSPI_IP_HR_LUT_READ_REG         12U
#define XSPI_IP_HR_LUT_WRITE_REG        18U

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/*!
* @brief Drive strength
*
* Hyperflash driver strength settings.
*/
typedef enum
{
    XSPI_IP_HR_DRV_STRENGTH_000 = 0x00U,  /*!< Typical Impedance for 1.8V: 27,  Typical Impedance 3V: 20 */
    XSPI_IP_HR_DRV_STRENGTH_001 = 0x01U,  /*!< Typical Impedance for 1.8V: 117, Typical Impedance 3V: 71 */
    XSPI_IP_HR_DRV_STRENGTH_002 = 0x02U,  /*!< Typical Impedance for 1.8V: 68,  Typical Impedance 3V: 40 */
    XSPI_IP_HR_DRV_STRENGTH_003 = 0x03U,  /*!< Typical Impedance for 1.8V: 45,  Typical Impedance 3V: 27 */
    XSPI_IP_HR_DRV_STRENGTH_004 = 0x04U,  /*!< Typical Impedance for 1.8V: 34,  Typical Impedance 3V: 20 */
    XSPI_IP_HR_DRV_STRENGTH_005 = 0x05U,  /*!< Typical Impedance for 1.8V: 27,  Typical Impedance 3V: 16 */
    XSPI_IP_HR_DRV_STRENGTH_006 = 0x06U,  /*!< Typical Impedance for 1.8V: 24,  Typical Impedance 3V: 14 */
    XSPI_IP_HR_DRV_STRENGTH_007 = 0x07U   /*!< Typical Impedance for 1.8V: 20,  Typical Impedance 3V: 12 */
} Xspi_Ip_HyperRamDrvStrengthType;


/*!
* @brief Initial latency
*
*/
typedef enum
{
    XSPI_IP_HR_INITIAL_LATENCY_5_CLOCKS  = 0U,  /*!< Read Initial 5 clocks  */
    XSPI_IP_HR_INITIAL_LATENCY_6_CLOCKS  = 1U,  /*!< Read Initial 6 clocks  */
    XSPI_IP_HR_INITIAL_LATENCY_7_CLOCKS  = 2U,  /*!< Read Initial 7 clocks  */
    XSPI_IP_HR_INITIAL_LATENCY_3_CLOCKS  = 14U, /*!< Read Initial 3 clocks */
    XSPI_IP_HR_INITIAL_LATENCY_4_CLOCKS  = 15U, /*!< Read Initial 4 clocks */
} Xspi_Ip_HyperRamInitialLatencyType;

/*******************************************************************************
* Structures
******************************************************************************/
/*!
* @brief Master Clock
*
*/
typedef enum
{
    XSPI_IP_HR_MASTER_CLOCK_TYPE_SINGLE_ENDED = 1U,
    XSPI_IP_HR_MASTER_CLOCK_TYPE_DIFFERENTIAL = 0U
} Xspi_Ip_HyperRamMasterClockType;

/*!
* @brief Array Refresh
*
*/
typedef enum
{
    XSPI_IP_HR_ARRAY_REFRESH_000 = 0U,
    XSPI_IP_HR_ARRAY_REFRESH_001 = 1U,
    XSPI_IP_HR_ARRAY_REFRESH_002 = 2U,
    XSPI_IP_HR_ARRAY_REFRESH_003 = 3U,
    XSPI_IP_HR_ARRAY_REFRESH_004 = 4U,
    XSPI_IP_HR_ARRAY_REFRESH_005 = 5U,
    XSPI_IP_HR_ARRAY_REFRESH_006 = 6U,
    XSPI_IP_HR_ARRAY_REFRESH_007 = 7U
} Xspi_Ip_HyperRamArrayRefreshType;

/*!
* @brief HyperRam configuration structure
*
 * This structure is used to provide configuration parameters for HyperRam
 * at initialization time.
*/
typedef struct
{
    Xspi_Ip_HyperRamDrvStrengthType       driveStrength;           /*!< Output driver level of the device                   */
    Xspi_Ip_HyperRamInitialLatencyType    initialLatency;          /*!< Initial latency                                     */
    Xspi_Ip_HyperRamMasterClockType       masterClockType;         /*!< Master Clock Type                                   */
    Xspi_Ip_HyperRamArrayRefreshType      arrayRefresh;            /*!< Array Refresh                                       */
    uint32                                deviceIdWordAddress;     /*!< The word address of the device Id in register space */
} Xspi_Ip_HyperRamConfigType;

#endif /* XSPI_IP_HYPERRAM_ENABLED == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_HYPERRAMTYPES_H */
