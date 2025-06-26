/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_DEFINES_H
#define EMIOS_ICU_IP_DEFINES_H

/**
 *   @file
 *   @implements Emios_Icu_Ip_Defines.h_Artifact
 *   @addtogroup emios_icu_ip EMIOS IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Std_Types.h"
/* Include platform header file. */
#include "S32Z2_EMIOS.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_ICU_IP_DEFINES_VENDOR_ID                       43
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_ICU_IP_DEFINES_SW_MAJOR_VERSION                2
#define EMIOS_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define EMIOS_ICU_IP_DEFINES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define EMIOS_ICU_IP_USED                        (STD_ON)

#if (STD_ON == EMIOS_ICU_IP_USED)

/** @brief The number of EMIOS instances available on platform */
#define EMIOS_ICU_IP_INSTANCE_COUNT               (2U)

/** @brief The number of channels available on each EMIOS instance */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS              (32U)

/** @brief The number of eMios channels are used in configuration */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS_USED         ((uint8)48U)

#define EMIOS_ICU_IP_CHANNEL_NOT_USED             ((uint8)0xFF)

#define EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED       ((uint8)0xFE)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define EMIOS_ICU_IP_DEV_ERROR_DETECT             (STD_OFF)
#define EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL         (EMIOS_ICU_IP_DEV_ERROR_DETECT)


/** @brief Adds or removes all services related to the timestamp functionality. */
#define EMIOS_ICU_IP_TIMESTAMP_API                (STD_ON)
/** @brief Adds or removes all services related to the edge detect functionality. */
#define EMIOS_ICU_IP_EDGE_DETECT_API              (STD_ON)
/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API       (STD_ON)
/** @brief Adds or removes all services related to the input level. */
#define EMIOS_ICU_IP_GET_INPUT_LEVEL_API          (STD_ON)
/** @brief Adds or removes all services related to the deinitialization functionality. */
#define EMIOS_ICU_IP_DEINIT_API                   (STD_ON)
/** @brief Adds or removes all services related to edge count functionality. */
#define EMIOS_ICU_IP_EDGE_COUNT_API               (STD_ON)

#define EMIOS_ICU_IP_CAPTURERGISTER_API           (STD_ON)

/** @brief Adds or Removes the code related to overflow notification */
#define EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API    (STD_ON)

/** @brief Define if global variables need to be placed in non-cache area or not */
#define EMIOS_ICU_IP_NO_CACHE_USED                (STD_OFF)

/** @brief define SAIC mode if any channels not supporting IPWM or IPM mode is configured. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE  (STD_ON)

/** @brief Adds or removes the service set Max Counter for eMios. */
#define EMIOS_ICU_IP_SET_MAX_COUNTER              (STD_ON)

/** @brief Adds or removes the service set Initial Counter for eMios. */
#define EMIOS_ICU_IP_SET_INITIAL_COUNTER          (STD_ON)

/** @brief Adds or removes all services related to input state functionality. */
#define EMIOS_ICU_IP_GET_INPUT_STATE_API          (STD_ON)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define EMIOS_ICU_IP_DUAL_CLOCK_MODE_API          (STD_ON)

/** @brief Adds or removes the support measurement with DMA. */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA   (STD_OFF)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA           (STD_OFF)

/** @brief Adds or removes the support measurement with DMA in IPL */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL   (STD_OFF)
#define EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT              (2U)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL           (STD_OFF)

#define EMIOS_ICU_IP_GET_PULSE_WIDTH_API          (STD_ON)

#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
/** @brief Maximum value of A shadow register in Emios IPL */
#define EMIOS_ICU_IP_SHADOW_REGISTER_MAX_MASK     (0xFFFFFFU)
#endif
    #define EMIOS_ICU_IP_WSC_SUPPORT                  (STD_ON)

#if (STD_ON == EMIOS_ICU_IP_WSC_SUPPORT)
#define EMIOS_ICU_IP_WSC_CHANNEL_OFFSET           (4U)

#define EMIOS_ICU_IP_WSC_NUM_OF_CHANNELS          (4U)
#endif

/** @brief Support for User mode.
 *  If this parameter has been configured to STD_ON, the EMIOS driver code
 *  can be executed from both supervisor and user mode. */
#define EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == EMIOS_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#define EMIOS_ICU_USES_MCL_DRIVER          (STD_OFF)

#if ((EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON) || (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON))
#define EMIOS_ICU_IP_COUNTER_MASK              ((uint32)16777215)
#endif

/** @brief Adds or removes SAIC with edge capturing support. */
#define EMIOS_ICU_IP_SAIC_EDGE_CAPTURING_SUPPORT                  (STD_OFF)

#define EMIOS_ICU_IP_INITIAL_INDEX_OF_CHANNELS \
    { \
        {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U}, \
        {24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U} \
    } \

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 eMios_Icu_ValueType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_DEFINES_H */

