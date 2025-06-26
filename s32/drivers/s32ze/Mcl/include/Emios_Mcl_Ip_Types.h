/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *   @file       Emios_Mcl_Ip_Types.h
 *
 *   @version    2.0.1
 *
 *   @brief      AUTOSAR Mcl - Emios Common driver header file.
 *
 *   @addtogroup EMIOS_IP_DRIVER EMIOS IP Driver
 *   @{
 */

#ifndef EMIOS_MCL_IP_TYPES_H
#define EMIOS_MCL_IP_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Emios_Mcl_Ip_Cfg_Defines.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_TYPES_VENDOR_ID                       43
#define EMIOS_MCL_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_TYPES_SW_MAJOR_VERSION                2
#define EMIOS_MCL_IP_TYPES_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_TYPES_SW_PATCH_VERSION                1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_TYPES_VENDOR_ID != EMIOS_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "Emios_Mcl_Ip_Types.h and Emios_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if  header file and Emios_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_TYPES_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_TYPES_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_TYPES_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Types.h and Emios_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((EMIOS_MCL_IP_TYPES_SW_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_TYPES_SW_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_TYPES_SW_PATCH_VERSION != EMIOS_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Types.h and Emios_Mcl_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and Std_Types.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Types.h and Std_Types.h are different"
    #endif

#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Channel mask maxim value. */
#define EMIOS_CHANNELMASK_MAXVAL             0x0FFFFFFFU

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum
{
    EMIOS_IP_COMMON_STATUS_SUCCESS    = E_OK,
    EMIOS_IP_COMMON_STATUS_FAIL       = E_NOT_OK,
#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    EMIOS_IP_COMMON_STATUS_WRONG_CORE = 2U
#endif
} Emios_Ip_CommonStatusType;

typedef enum
{
    EMIOS_IP_NO_MASTER_MODE      = 0U,
    EMIOS_IP_MC_UP_COUNTER_START = 16U,
    EMIOS_IP_MC_UP_COUNTER_END   = 18U,
    EMIOS_IP_MC_UP_DOWN_COUNTER  = 20U,
    EMIOS_IP_MCB_UP_COUNTER      = 80U,
    EMIOS_IP_MCB_UP_DOWN_COUNTER = 84U
} Emios_Ip_MasterBusModeType;

typedef struct
{
    const uint8                       hwChannel;
    const Emios_Ip_MasterBusModeType  masterMode;
    const uint32                      defaultPeriod;
    const uint32                      offsetStartValue;
    const uint8                       masterBusPrescaler;
    const uint8                       masterBusAltPrescaler;
    const boolean                     allowDebugMode;
} Emios_Ip_MasterBusConfigType;

typedef struct
{
    const boolean   allowDebugMode;         /**< Allow all channel in EMIOS group can enter debug mode */
    const uint8     clkDivVal;              /**< Select the clock divider value for the global prescaler in range (1-256) */
    const boolean   enableGlobalTimeBase;   /**< Enable global timebase or disable   */
} Emios_Ip_GlobalConfigType;

/** @brief EMIOS IP configuration structure. */
typedef struct
{
    const uint8                         channelsNumber;       /**< @brief Number of master buses used. */
#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    const uint8                         instanceCoreNumber;   /**< @brief Core number where EMIOS instance is used. */
#endif
    const Emios_Ip_GlobalConfigType     *emiosGlobalConfig;   /**< @brief Pointer to EMIOS configuration. */
    const Emios_Ip_MasterBusConfigType (*masterBusConfig)[];  /**< @brief Pointer to an array with all master buses used. */
} Emios_Mcl_Ip_ConfigType;

/** @brief Store EMIOS channel state. */
typedef struct 
{
    Emios_Ip_MasterBusModeType counterMode;      /* Current mode of the configured master bus. */
    boolean                    channelInitState; /* Store TRUE channel is initialized, FALSE otherwise. */
} Emios_Ip_ChStateType;


/** @brief Store EMIOS instance state. */
typedef struct 
{
    boolean instanceInitState; /* Store TRUE channel is initialized, FALSE otherwise. */
#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    uint8   runCore;           /* Store the core on which current EMIOS instance is running. */
#endif
} Emios_Ip_InstStateType;

typedef enum
{
    EMIOS_IP_PRESCALER                    = 0U,
    EMIOS_IP_ALTERNATIVE_PRESCALER        = 1U
} Emios_Ip_SelectPrescalerType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_MCL_IP_TYPES_H */

