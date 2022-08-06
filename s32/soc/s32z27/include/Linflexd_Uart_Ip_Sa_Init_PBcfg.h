/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LINFLEXD_UART_IP_SA_INIT_PBCFG_H
#define LINFLEXD_UART_IP_SA_INIT_PBCFG_H

/**
*   @file Linflexd_Uart_Ip_PBcfg.h
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Linflexd_Uart_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_VENDOR_ID                     43
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION      4
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_AR_RELEASE_MINOR_VERSION      4
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_AR_RELEASE_REVISION_VERSION   0
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_SW_MAJOR_VERSION              0
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_SW_MINOR_VERSION              8
#define LINFLEXD_UART_IP_SA_PBCFG_INIT_SW_PATCH_VERSION              0



/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip_Types.h */
#if (LINFLEXD_UART_IP_SA_PBCFG_INIT_VENDOR_ID != LINFLEXD_UART_IP_TYPES_VENDOR_ID)
    #error "Linflexd_Uart_Ip_Sa_Init_PBcfg.h and Linflexd_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_SA_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION   != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION)|| \
     (LINFLEXD_UART_IP_SA_PBCFG_INIT_AR_RELEASE_MINOR_VERSION   != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION)|| \
     (LINFLEXD_UART_IP_SA_PBCFG_INIT_AR_RELEASE_REVISION_VERSION!= LINFLEXD_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Sa_Init_PBcfg.h and Linflexd_Uart_Ip_Types.h are different"
#endif
#if ((LINFLEXD_UART_IP_SA_PBCFG_INIT_SW_MAJOR_VERSION!= LINFLEXD_UART_IP_TYPES_SW_MAJOR_VERSION)|| \
     (LINFLEXD_UART_IP_SA_PBCFG_INIT_SW_MINOR_VERSION!= LINFLEXD_UART_IP_TYPES_SW_MINOR_VERSION)|| \
     (LINFLEXD_UART_IP_SA_PBCFG_INIT_SW_PATCH_VERSION!= LINFLEXD_UART_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Linflexd_Uart_Ip_Sa_Init_PBcfg.h and Linflexd_Uart_Ip_Types.h are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL MACROS
==================================================================================================*/
/**
* @brief          Link Uart channels symbolic names with Uart hardware channel IDs.
* @details        Link Uart channels symbolic names with Uart hardware channel IDs.
*
* @api
*/

#ifndef LINFLEXD_UART_IP_INSTANCE_USING_0
#define LINFLEXD_UART_IP_INSTANCE_USING_0   0U
#endif
/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                        GLOBAL VARIABLES AND GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief    Declare callback functions if any .
*/

/**
* @brief    Hardware configuration for Linflexd Uart Hardware - Configuration.
*/
#define LINFLEXD_UART_IP_SA_CONFIG_INIT_PB \
extern const Linflexd_Uart_Ip_UserConfigType Linflexd_Uart_Ip_xHwConfigPB_0_INIT;

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

#endif /* LINFLEXD_UART_INIT_PBCFG_H */

