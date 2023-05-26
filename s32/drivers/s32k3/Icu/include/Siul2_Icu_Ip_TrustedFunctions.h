/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_TRUSTEDFUNCTIONS_H
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_H

/**
 *     @file
 *
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Siul2_Icu_Ip_Defines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             3
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_VENDOR_ID != SIUL2_ICU_IP_DEFINES_VENDOR_ID)
    #error "Siul2_Icu_Ip_TrustedFunctions.h and Siul2_Icu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_TrustedFunctions.h and Siul2_Icu_Ip_Defines.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_TrustedFunctions.h and Siul2_Icu_Ip_Defines.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
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
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Siul2_Icu_SetUserAccessAllowed
 * @details    This function is called externally by OS Application
 * @param[in]  siul2BaseAddr - The base address of Siul2 module.
 */
#if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
    extern void Siul2_Icu_SetUserAccessAllowed(uint32 siul2BaseAddr);
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_TRUSTEDFUNCTIONS_H */

