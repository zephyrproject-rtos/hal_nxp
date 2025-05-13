/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_TRUSTEDFUNCTIONS_H
#define CLOCK_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Clock_Ip_TrustedFunctions.h
*   @version    2.0.1
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
#include "Std_Types.h"
#include "Clock_Ip_Cfg.h"
#include "Clock_Ip_Specific.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h  and Std_Types.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Cfg.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_TYPES_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file are of the same Autosar version */
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
/* Clock start rom section code */
#define MCU_START_SEC_CODE_AC
#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)


#if (defined(CLOCK_IP_HAS_SYSTEM_DIV2_CLK) || defined(CLOCK_IP_HAS_SYSTEM_DIV4_MON1_CLK) || defined(CLOCK_IP_HAS_SYSTEM_DIV4_MON2_CLK))
/**
 * @brief        This function will enable writing in User mode by configuring REG_PROT
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_SpecificSetUserAccessAllowed(void);
#endif /* (defined(CLOCK_IP_HAS_SYSTEM_DIV2_CLK) || defined(CLOCK_IP_HAS_SYSTEM_DIV4_MON1_CLK) || defined(CLOCK_IP_HAS_SYSTEM_DIV4_MON2_CLK)) */

#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES
/**
 * @brief        Set Ram waitstate value base on core_clk
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_SRAMControllerSetRamIWS(uint32 SmuM33CoreClk_IwsSetting,
                                             uint32 Rtu0CoreClk_IwsSetting,
                                             uint32 Rtu1CoreClk_IwsSetting,
                                             uint32 CeM33CoreClk_IwsSetting);
#endif

#ifdef CLOCK_IP_MC_ME_AE_GS_S_SYSCLK
/**
 * @brief        Reset configuration for MC_ME_AE_GS_S_SYSCLK
 *
 * @param        Config - pointer to configuration of MC_ME_AE selector
 * @return       None
 *
 */
extern void Clock_Ip_ResetMcMeAeGssSysclk_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
/**
 * @brief        Set configuration for MC_ME_AE_GS_S_SYSCLK
 *
 * @param        Config - pointer to configuration of MC_ME_AE selector
 * @return       None
 *
 */
extern void Clock_Ip_SetMcMeAeGssSysclk_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif


  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */


/* Clock stop rom section code */
#define MCU_STOP_SEC_CODE_AC
#include "Mcu_MemMap.h"



#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TRUSTEDFUNCTIONS_H */


