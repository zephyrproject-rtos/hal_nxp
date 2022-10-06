/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM_IP_TYPES_H
#define STM_IP_TYPES_H

/**
*   @file       Stm_Ip_Types.h
*
*   @addtogroup stm_ip Stm IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Stm_Ip_Cfg_Defines.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define STM_IP_TYPES_VENDOR_ID                       43
#define STM_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define STM_IP_TYPES_AR_RELEASE_MINOR_VERSION        4
#define STM_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define STM_IP_TYPES_SW_MAJOR_VERSION                0
#define STM_IP_TYPES_SW_MINOR_VERSION                8
#define STM_IP_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (STM_IP_TYPES_VENDOR_ID != STM_IP_DEFINES_VENDOR_ID_CFG)
    #error "Stm_Ip_Types.h and Stm_Ip_Cfg_Defines.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((STM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (STM_IP_TYPES_AR_RELEASE_MINOR_VERSION != STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (STM_IP_TYPES_AR_RELEASE_REVISION_VERSION != STM_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Stm_Ip_Types.h and Stm_Ip_Cfg_Defines.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((STM_IP_TYPES_SW_MAJOR_VERSION != STM_IP_DEFINES_SW_MAJOR_VERSION_CFG) || \
     (STM_IP_TYPES_SW_MINOR_VERSION != STM_IP_DEFINES_SW_MINOR_VERSION_CFG) || \
     (STM_IP_TYPES_SW_PATCH_VERSION != STM_IP_DEFINES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Stm_Ip_Types.h and Stm_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                                      CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (STM_IP_USED == STD_ON)

/**
* @internal
* @brief STM Channels defines
*
*/
#define PREDEF                ((uint8)0)

#endif /*STM_IP_USED == STD_ON */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (STM_IP_SET_CLOCK_MODE == STD_ON)
/**
* @brief    Prescaler type. Indicates of whether the clock channel mode is "NORMAL" or "ALTERNATE".
* @details  This enumeration specifies the possible types of prescalers used to configure base-clock timers
*/
typedef enum
{
    STM_IP_CLOCKMODE_NORMAL    = 0x0U,  /**< @brief Selected value is the NORMAL configured prescaler    */
    STM_IP_CLOCKMODE_ALTERNATE = 0x1U   /**< @brief Selected value is the ALTERNATE configured prescaler */
} Stm_Ip_ClockModeType;
#endif /* STM_IP_SET_CLOCK_MODE */


/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    STM_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief channel mode -  continuous mode */
    STM_IP_CH_MODE_ONESHOT    = 1U       /**< @brief channel mode -  one-shot mode.  */
} Stm_Ip_ChannelModeType;
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @internal
* @brief    Callback type for each channel
* @details  Stm_Ip_CallbackType
*
*/
typedef void (*Stm_Ip_CallbackType)(uint8 callbackParam);

/**
* @internal
* @brief       Structure to configure the STM
* @details     This structure holds the configuration settings Stm_Ip_InstanceConfigType
*
*/
typedef struct
{
    boolean stopInDebugMode;                /**< @brief Allows the timer counter to be stopped in debug mode */
#if(STM_IP_SET_CLOCK_MODE == STD_ON)
    uint8 clockAlternatePrescaler;          /**< @brief Clock divide value for the AlternatePrescaler        */
#endif
    uint8 clockPrescaler;                   /**< @brief Clock divide value for the clockPrescaler            */
} Stm_Ip_InstanceConfigType;

/**
* @internal
* @brief       Structure to configure the STM
* @details     This structure holds the configuration settings for the ChannelConfigType
*
*/
typedef struct
{
    uint8 hwChannel;                                /**< @brief Timer channel number */
    Stm_Ip_CallbackType        callback;            /**< @brief callback             */
    uint8                      callbackParam;       /**< @brief callbackParam        */
    Stm_Ip_ChannelModeType     channelMode;         /**< @brief channelMode          */
} Stm_Ip_ChannelConfigType;

/**
* @internal
* @brief       internal context structure
* @details     This structure is used by the IPL driver for internal logic.
*              The content is populated on InitChannel
*
*/
typedef struct
{
    boolean                    chInit;          /**< @brief chInit           */
    Stm_Ip_CallbackType        callback;        /**< @brief callback         */
    uint8                      callbackParam;   /**< @brief callbackParam    */
    Stm_Ip_ChannelModeType     channelMode;         /**< @brief channelMode  */
} Stm_Ip_ChState;

/**
* @internal
* @brief       internal context structure
* @details     This structure is used by the IPL driver for internal logic.
*              The content is populated on Init
*
*/
typedef struct
{
    uint8       clockPrescaler;                /**< @brief Clock divide value for the NormalPrescaler    */
    uint8       clockAlternatePrescaler;       /**< @brief Clock divide value for the AlternatePrescaler */
} Stm_Ip_InstanceState;
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif/*STM_IP_TYPES_H*/
