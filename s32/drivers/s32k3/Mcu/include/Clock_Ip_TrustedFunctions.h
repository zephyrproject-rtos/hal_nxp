/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_TRUSTEDFUNCTIONS_H
#define CLOCK_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Clock_Ip_TrustedFunctions.h
*   @version    3.0.0
*
*   @brief   CLOCK IP type header file.
*   @details CLOCK IP type header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Clock_Ip_Cfg.h"
#include "Clock_Ip_Specific.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                3
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_TrustedFunctions.h file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and StandardTypes.h are different"
#endif
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_CFG_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file are of the same Software version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_CFG_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_CFG_SW_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_SPECIFIC_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file are of the same Software version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief        Set user access allowed for some clock register
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_SpecificSetUserAccessAllowed(void);

#ifdef CLOCK_IP_RTC_RTCC_CLKSELECT
/**
 * @brief        Write Config RTCCLKSEL to register
 *
 * @param        Config - pointer to configuration of RTC selector
 * @return       None
 *
 */
extern void Clock_Ip_SetRtcRtccClksel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif


#ifdef CLOCK_IP_GET_FREQUENCY_API
#if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)
/**
 * @brief        Return the frequency of RTC_CLK clock
 *
 * @param        None
 * @return       uint32
 *
 */
extern uint32 Clock_Ip_Get_RTC_CLK_Frequency_TrustedCall(void);
#endif
#endif

/**
 * @brief        Set user access allowed for some clock register
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_PowerClockIpModules(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/* Clock start rom section code */
#define MCU_START_SEC_CODE_AC
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES
/**
 * @brief        Set Ram waitstate value base on core_clk
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_PRAMCSetRamIWS(void);
#endif
/* Clock stop rom section code */
#define MCU_STOP_SEC_CODE_AC
#include "Mcu_MemMap.h"

  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */





#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TRUSTEDFUNCTIONS_H */


