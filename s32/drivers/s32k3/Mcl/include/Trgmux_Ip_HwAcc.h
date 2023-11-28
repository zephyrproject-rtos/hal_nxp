/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#if !defined(TRGMUX_IP_HWACC_H_)
#define TRGMUX_IP_HWACC_H_

/**
*   @file    Trgmux_Ip_HwAcc.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver source file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
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
#include "Trgmux_Ip_Devassert.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_HWACC_VENDOR_ID                    43
#define TRGMUX_IP_HWACC_MODULE_ID                    255
#define TRGMUX_IP_HWACC_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_HWACC_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_HWACC_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_HWACC_SW_MAJOR_VERSION             3
#define TRGMUX_IP_HWACC_SW_MINOR_VERSION             0
#define TRGMUX_IP_HWACC_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Trgmux_Ip_HwAcc.h file and Trgmux_Ip_Devassert.h file are of the same vendor */
#if (TRGMUX_IP_HWACC_VENDOR_ID != TRGMUX_IP_DEVASSERT_VENDOR_ID)
    #error "Trgmux_Ip_HwAcc.h and Trgmux_Ip_Devassert.h have different vendor ids"
#endif

/* Check if Trgmux_Ip_HwAcc.h file and Trgmux_Ip_Devassert.h file are of the same Autosar version */
#if ((TRGMUX_IP_HWACC_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_HWACC_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_HWACC_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_HwAcc.h and Trgmux_Ip_Devassert.h are different"
#endif

/* Check if Trgmux_Ip_HwAcc.h file and Trgmux_Ip_Devassert.h file are of the same Software version */
#if ((TRGMUX_IP_HWACC_SW_MAJOR_VERSION != TRGMUX_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_HWACC_SW_MINOR_VERSION != TRGMUX_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (TRGMUX_IP_HWACC_SW_PATCH_VERSION != TRGMUX_IP_DEVASSERT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_HwAcc.h and Trgmux_Ip_Devassert.h are different"
#endif

#if (STD_ON == TRGMUX_IP_IS_AVAILABLE)
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
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

Trgmux_Ip_StatusType hwAcc_Init(TRGMUX_Type * const pTrgmux, uint8 TrgmuxCount);

void hwAcc_SetInputForOutput(TRGMUX_Type * const pTrgmux, uint8 Instance, const uint32 Input, const uint32 Output);

void hwAcc_SetLockForOutput(TRGMUX_Type * const pTrgmux, const uint32 Output);

boolean hwAcc_GetLockForOutput(const TRGMUX_Type * const pTrgmux, const uint32 Output);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* TRGMUX_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #if !defined(TRGMUX_IP_HWACC_H_) */
