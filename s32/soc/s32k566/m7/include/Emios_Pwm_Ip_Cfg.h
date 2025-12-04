/*
 * Copyright 2024-2025 NXP
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
/* Standard Types */
#include "Std_Types.h"

/* DevAssert implementation */
#include "Devassert.h"

/* Register definitions */
#include "S32K566_EMIOS.h"

/* Include all variants header files. */
#include "Emios_Pwm_Ip_Sa_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_CFG_VENDOR_ID                    43
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     9
#define EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION             0
#define EMIOS_PWM_IP_CFG_SW_MINOR_VERSION             8
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

    /* Check if header file and Emios_Pwm_Ip_Sa_PBcfg header file are of the same vendor */
#if (EMIOS_PWM_IP_CFG_VENDOR_ID != EMIOS_PWM_IP_SA_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Sa_PBcfg.h are different."
#endif

    /* Check if header file and Emios_Pwm_Ip_Sa_PBcfg header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_SA_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_SA_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_SA_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Sa_PBcfg.h are different."
#endif

    /* Check if header file and Emios_Pwm_Ip_Sa_PBcfg header file are of the same software version */
#if ((EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_SA_PB_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_SA_PB_CFG_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_SA_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Cfg.h and Emios_Pwm_Ip_Sa_PBcfg.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief      Enable the Emios Ip */
#define EMIOS_PWM_IP_USED                          (STD_ON)

/** @brief      Switch to enable the development error detection. */
#define EMIOS_PWM_IP_DEV_ERROR_DETECT              (STD_OFF)

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
#define EMIOS_PWM_IP_MAX_CNT_VAL                   (0xFFFFFFUL)

/** @brief      Counter bus channel number */
#define EMIOS_PWM_IP_COUNTER_BUS_A                 (23U)
#define EMIOS_PWM_IP_COUNTER_BUS_BCDE              (248U)
#define EMIOS_PWM_IP_COUNTER_BUS_F                 (22U)

/* @brief Define if global variables need to be placed in non-cache area or not */
#define EMIOS_PWM_IP_NO_CACHE_NEEDED               (STD_OFF)


/** @brief Arrays to store the channel logic Index State */
#define EMIOS_PWM_IP_USED_CHANNELS \
{ \
    {0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, \
    {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, \
    {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U} \
}

/** @brief    Calculate the supported eMios channels */
#define EMIOS_PWM_IP_NUM_OF_CHANNELS_USED_U8       ((uint8)1U)

#define EMIOS_PWM_IP_INITIAL_MODES \
{\
        EMIOS_PWM_IP_MODE_NODEFINE\
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
typedef uint32 Emios_Pwm_Ip_PeriodType;

/**
* @brief        PWM Duty type (the value of the period is platform dependent and thus configurable)
*/
typedef uint32 Emios_Pwm_Ip_DutyType;

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

