/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_H_
#define TRGMUX_IP_H_

/**
*   @file    Trgmux_Ip.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver header file.
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
#include "Trgmux_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_VENDOR_ID                    43
#define TRGMUX_IP_MODULE_ID                    255
#define TRGMUX_IP_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_SW_MAJOR_VERSION             3
#define TRGMUX_IP_SW_MINOR_VERSION             0
#define TRGMUX_IP_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Trgmux_Ip_Cfg.h file are of the same vendor */
#if (TRGMUX_IP_VENDOR_ID != TRGMUX_IP_CFG_VENDOR_ID)
    #error "Trgmux_Ip.h and Trgmux_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg.h file are of the same Autosar version */
#if ((TRGMUX_IP_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip.h and Trgmux_Ip_Cfg.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg.h file are of the same Software version */
#if ((TRGMUX_IP_SW_MAJOR_VERSION != TRGMUX_IP_CFG_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_SW_MINOR_VERSION != TRGMUX_IP_CFG_SW_MINOR_VERSION) || \
     (TRGMUX_IP_SW_PATCH_VERSION != TRGMUX_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip.h and Trgmux_Ip_Cfg.h are different"
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

/**
 * @brief This function initializes the Trgmux Ip Driver.
 * @details This service is a non reentrant function that shall initialize the Trgmux Ip driver.
 *
 * @param[in]  pxTrgmuxInit      Pointer to the initialization structure.
 *
 * @return     TRGMUX_IP_STATUS_LOCKED  The trigger is locked.
 *             TRGMUX_IP_STATUS_SUCCESS      The initialization was successful.
 *
 * @implements Trgmux_Ip_Init_Activity
 * */
Trgmux_Ip_StatusType Trgmux_Ip_Init(const Trgmux_Ip_InitType * const pxTrgmuxInit);

/**
 * @brief This function sets the Trgmux Ip Input.
 * @details This service is a reentrant function that shall set the Trgmux Ip Input.
 *
 * @param[in]  LogicTrigger      The logic trigger id.
 * @param[in]  Input             The input value.
 *
 * @return     TRGMUX_IP_STATUS_LOCKED  The trigger is locked.
 *             TRGMUX_IP_STATUS_SUCCESS      The initialization was successful.
 *
 * @implements Trgmux_Ip_SetInput_Activity
 * */
Trgmux_Ip_StatusType Trgmux_Ip_SetInput(const uint32 LogicTrigger, const uint32 Input);

/**
 * @brief This function locks the Trgmux Ip Trigger.
 * @details This service is a reentrant function that shall lock the Trgmux Ip Trigger.
 *
 * @param[in]  LogicTrigger      The logic trigger id.
 *
 * @return     TRGMUX_IP_STATUS_LOCKED  The trigger is locked.
 *             TRGMUX_IP_STATUS_SUCCESS      The initialization was successful.
 *
 * @implements Trgmux_Ip_SetLock_Activity
 * */
Trgmux_Ip_StatusType Trgmux_Ip_SetLock(const uint32 LogicTrigger);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* TRGMUX_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef TRGMUX_IP_H_ */
