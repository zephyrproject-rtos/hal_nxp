/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_CFG_H
#define EMIOS_PWM_IP_CFG_H

/**
*   @file       Emios_Pwm_Ip_Cfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <zephyr/devicetree.h>

/* Standard Types */
#include "Std_Types.h"

/* DevAssert implementation */
#include "Devassert.h"

/* Register definitions */
#include "S32K344_EMIOS.h"

/* Include all variants header files. */
#include "Emios_Pwm_Ip_Init_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_CFG_VENDOR_ID                    43
#define EMIOS_PWM_IP_CFG_MODULE_ID                    121
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION             3
#define EMIOS_PWM_IP_CFG_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Cfg.h and Std_Types.h are different"
    #endif

    /* Check if header file and Devassert.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif

    /* Check if header file and Emios_Pwm_Ip_Init_Pbcfg header file are of the same vendor */
#if (EMIOS_PWM_IP_CFG_VENDOR_ID != EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Init_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Init_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Init_Pbcfg.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DT_DRV_COMPAT   nxp_s32_emios_pwm

#define NUM_CHANNEL_USED(node_id)           COND_CODE_1(DT_ENUM_HAS_VALUE(node_id, pwm_mode, saic), (+ 0), (+ 1))
#define EMIOS_NUM_CHANNELS_USED(n)          DT_INST_FOREACH_CHILD_STATUS_OKAY(n, NUM_CHANNEL_USED)

#define SET_INITIAL_MODE(node_id)           IF_ENABLED(UTIL_NOT(DT_ENUM_HAS_VALUE(node_id, pwm_mode, saic)),    \
                                                       (EMIOS_PWM_IP_MODE_NODEFINE,))
#define EMIOS_PWM_IP_SET_INITIAL_MODE(n)    DT_INST_FOREACH_CHILD_STATUS_OKAY(n, SET_INITIAL_MODE)

/** @brief      Enable the Emios Ip */
#define EMIOS_PWM_IP_USED                   ((DT_INST_FOREACH_STATUS_OKAY(EMIOS_NUM_CHANNELS_USED)) || 0)

/** @brief      Switch to enable the development error detection. */
#define EMIOS_PWM_IP_DEV_ERROR_DETECT           (STD_OFF)

/** @brief      The number of Emios instances available on platform */
#define EMIOS_PWM_IP_INSTANCE_COUNT                (eMIOS_INSTANCE_COUNT)
/** @brief      The number of channels available on each Emios instance */
#define EMIOS_PWM_IP_CHANNEL_COUNT                 (eMIOS_CH_UC_UC_COUNT)

/** @brief      The number of PWM modes implemented in hardware */
#define EMIOS_PWM_IP_MODES                         (5U)
/** @brief      Mapping between available channels and the PWM mode supported by each of them */
#define EMIOS_PWM_IP_CHANNEL_MODES                 {\
                                                    {0x00C101FFUL, 0x000000FEUL, 0x00FFFFFFUL, 0x00FFFFFFUL, 0x0000FEFEUL},\
                                                    {0x00C10101UL, 0x00000000UL, 0x00FFFFFFUL, 0x00FFFFFFUL, 0x0000FEFEUL},\
                                                    {0x00C10101UL, 0x00000000UL, 0x00FFFFFFUL, 0x00FFFFFFUL, 0x0000FEFEUL},\
                                                }
/** @brief Min counter value for PWM modes */
#define EMIOS_PWM_IP_MIN_CNT_VAL                   (0x0001UL)
/** @brief Max counter value for PWM modes */
#define EMIOS_PWM_IP_MAX_CNT_VAL                   (0xFFFFUL)

/** @brief      Counter bus channel number */
#define EMIOS_PWM_IP_COUNTER_BUS_A                 (23U)
#define EMIOS_PWM_IP_COUNTER_BUS_BCDE              (248U)
#define EMIOS_PWM_IP_COUNTER_BUS_F                 (22U)

/** @brief Arrays to store the channel logic Index State */
#define EMIOS_PWM_IP_USED_CHANNELS                 {\
{255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U},  \
{255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U},  \
{255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}  \
}

#define EMIOS_PWM_IP_NUM_OF_CHANNELS_USED   0 DT_INST_FOREACH_STATUS_OKAY(EMIOS_NUM_CHANNELS_USED)

#define EMIOS_PWM_IP_INITIAL_MODES                                                \
{                                                                                 \
    DT_INST_FOREACH_STATUS_OKAY(EMIOS_PWM_IP_SET_INITIAL_MODE)                    \
}

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Redefine eMIOS_Type from header file to comply with coding guidelines */
typedef eMIOS_Type Emios_Pwm_Ip_HwAddrType;
/**
* @brief        PWM Period type (the value of the period is platform dependent and thus configurable)
*/
typedef uint16 Emios_Pwm_Ip_PeriodType;

/**
* @brief        PWM Duty type (the value of the period is platform dependent and thus configurable)
*/
typedef uint16 Emios_Pwm_Ip_DutyType;

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

#endif /* EMIOS_PWM_IP_CFG_H */