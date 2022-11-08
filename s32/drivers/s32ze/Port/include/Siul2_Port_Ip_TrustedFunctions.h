/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Siul2_Port_Ip_TrustedFunctions.h
*
*   @addtogroup Port_IPL Port IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                0
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                9
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Siul2_Port_Ip_TrustedFunctions.h and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_Port_Ip_TrustedFunctions.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H */
