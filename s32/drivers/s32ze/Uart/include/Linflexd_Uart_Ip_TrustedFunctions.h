/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_H
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Linflexd_Uart_Ip_TrustedFunctions.h
*
*
*   @brief   LINFLEXD_UART IP driver header file.
*   @details LINFLEXD_UART IP driver header file.

*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
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
#include "Linflexd_Uart_Ip_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Linflexd_Uart_Ip_TrustedFunctions.h header file and Linflexd_Uart_Ip_Defines.h configuration header file are of the same vendor */
#if (LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_VENDOR_ID != LINFLEXD_UART_IP_DEFINES_VENDOR_ID)
    #error "Linflexd_Uart_Ip_TrustedFunctions.h and Linflexd_Uart_Ip_Defines.h have different vendor IDs"
#endif
    /* Check if Linflexd_Uart_Ip_TrustedFunctions.h header file and Linflexd_Uart_Ip_Defines.h configuration header file are of the same Autosar version */
#if ((LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Linflexd_Uart_Ip_TrustedFunctions.h and Linflexd_Uart_Ip_Defines.h are different"
#endif
/* Check if Linflexd_Uart_Ip_TrustedFunctions.h header file and Linflexd_Uart_Ip_Defines.h configuration header file are of the same software version */
#if ((LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != LINFLEXD_UART_IP_DEFINES_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != LINFLEXD_UART_IP_DEFINES_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != LINFLEXD_UART_IP_DEFINES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Linflexd_Uart_Ip_TrustedFunctions.h and Linflexd_Uart_Ip_Defines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

#ifdef LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
#if (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/**
* @brief            This function will set UAA bit in REG_PROT for UART unit
* @details          This function will set UAA bit in REG_PROT for UART unit
*
* @param[in]        Instance - LINFLEXD_UART peripheral instance number.
*
* @return           void.
*/
extern void Linflexd_Uart_Ip_SetUserAccess(const uint8 Instance);

#endif /* (STD_ON == LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE) */
#endif /* ifdef LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_TRUSTEDFUNCTIONS_H */
