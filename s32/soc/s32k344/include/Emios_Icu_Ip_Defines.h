/*
 * Copyright 2023 NXP
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
#include "S32K344_EMIOS.h"

#include <zephyr/devicetree.h>

#define _PWM_NXP_S32_CAPTURE_USED(node_id)  \
        COND_CODE_1(DT_ENUM_HAS_VALUE(node_id, pwm_mode, saic), (+ 1), (+ 0))

#define PWM_NXP_S32_CAPTURE_USED(node_id)     \
        DT_FOREACH_CHILD_STATUS_OKAY(node_id, _PWM_NXP_S32_CAPTURE_USED)

#define QDEC_NXP_S32_MCB_USED  \
	COND_CODE_1(DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32), (+ 2), (+ 0))

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_ICU_IP_DEFINES_VENDOR_ID                    43
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_ICU_IP_DEFINES_SW_MAJOR_VERSION             3
#define EMIOS_ICU_IP_DEFINES_SW_MINOR_VERSION             0
#define EMIOS_ICU_IP_DEFINES_SW_PATCH_VERSION             0

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

#define EMIOS_ICU_IP_USED	   (0 || (DT_FOREACH_STATUS_OKAY(nxp_s32_emios_pwm, \
	PWM_NXP_S32_CAPTURE_USED)) || DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32))

#if (STD_ON == EMIOS_ICU_IP_USED)

#define EMIOS_ICU_IP_CHANNEL_24_USED               (STD_OFF)
/** @brief The number of EMIOS instances available on platform */
#define EMIOS_ICU_IP_INSTANCE_COUNT                (3U)

/** @brief The number of channels available on each EMIOS instance */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS               (24U)

/** @brief The number of eMios channels are used in configuration */
#define EMIOS_ICU_IP_NUM_OF_CHANNELS_USED	  0 DT_FOREACH_STATUS_OKAY(nxp_s32_emios_pwm, PWM_NXP_S32_CAPTURE_USED) + QDEC_NXP_S32_MCB_USED

#define EMIOS_ICU_IP_CHANNEL_NOT_USED             ((uint8)0xFF)

#define EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED       ((uint8)0xFE)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define EMIOS_ICU_IP_DEV_ERROR_DETECT             (STD_OFF)
#define EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL         (EMIOS_ICU_IP_DEV_ERROR_DETECT)


/** @brief Adds or removes all services related to the timestamp functionality. */
#define EMIOS_ICU_IP_TIMESTAMP_API                (STD_ON)
/** @brief Adds or removes all services related to the edge detect functionality. */
#define EMIOS_ICU_IP_EDGE_DETECT_API              (STD_OFF)
/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API	  (STD_OFF || DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32))
/** @brief Adds or removes all services related to the input level. */
#define EMIOS_ICU_IP_GET_INPUT_LEVEL_API          (STD_ON)
/** @brief Adds or removes all services related to the deinitialization functionality. */
#define EMIOS_ICU_IP_DEINIT_API                   (STD_OFF)
/** @brief Adds or removes all services related to edge count functionality. */
#define EMIOS_ICU_IP_EDGE_COUNT_API		  (STD_OFF || DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32))

#define EMIOS_ICU_IP_CAPTURERGISTER_API           (STD_OFF)

/** @brief Adds or Removes the code related to overflow notification */
#define EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API	  (STD_OFF || DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32))

/** @brief define SAIC mode if any channels not supporting IPWM or IPM mode is configured. */
#define EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE  (STD_OFF)

/** @brief Adds or removes the service set Max Counter for eMios. */
#define EMIOS_ICU_IP_SET_MAX_COUNTER		  (STD_OFF || DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32))

/** @brief Adds or removes the service set Initial Counter for eMios. */
#define EMIOS_ICU_IP_SET_INITIAL_COUNTER	  (STD_OFF || DT_HAS_COMPAT_STATUS_OKAY(nxp_qdec_s32))

/** @brief Adds or removes all services related to mode set functionality. */
#define EMIOS_ICU_IP_SET_MODE_API                 (STD_OFF)

/** @brief Adds or removes all services related to input state functionality. */
#define EMIOS_ICU_IP_GET_INPUT_STATE_API          (STD_OFF)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define EMIOS_ICU_IP_DUAL_CLOCK_MODE_API          (STD_OFF)

/** @brief Adds or removes the support measurement with DMA. */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA   (STD_OFF)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA           (STD_OFF)

/** @brief Adds or removes the support measurement with DMA in IPL */
#define EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL   (STD_OFF)
#define EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT              (2U)
#define EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL           (STD_OFF)

#define EMIOS_ICU_IP_GET_PULSE_WIDTH_API          (STD_OFF)
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

#define EMIOS_ICU_USES_MCL_DRIVER          (STD_ON)

#if ((EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON) || (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON))
#define EMIOS_ICU_IP_COUNTER_MASK              ((uint32)65535)
#endif
#define EMIOS_ICU_IP_INITIAL_INDEX_OF_CHANNELS \
  { \
      {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 255U}, \
      {23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 255U}, \
      {46U, 47U, 48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U, 64U, 65U, 66U, 67U, 68U, 255U} \
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

#endif /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_DEFINES_H */

