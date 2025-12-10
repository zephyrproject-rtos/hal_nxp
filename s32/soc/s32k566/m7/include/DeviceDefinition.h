/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    DeviceDefinition.h
*   @version 0.8.0
*
*   @brief   BaseNXP - Project configuration.
*   @details Header file contains the specific derivative, sub derivative and platform definitions.
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/

#ifndef DEVICEDEFINITION_H
#define DEVICEDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEVICEDEFINITION_VENDOR_ID_H                    43
#define DEVICEDEFINITION_MODULE_ID_H                    0
#define DEVICEDEFINITION_AR_RELEASE_MAJOR_VERSION_H     4
#define DEVICEDEFINITION_AR_RELEASE_MINOR_VERSION_H     9
#define DEVICEDEFINITION_AR_RELEASE_REVISION_VERSION_H  0
#define DEVICEDEFINITION_SW_MAJOR_VERSION_H             0
#define DEVICEDEFINITION_SW_MINOR_VERSION_H             8
#define DEVICEDEFINITION_SW_PATCH_VERSION_H             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This macro define specific derivative and sub derivative.
*/

#ifndef S32K566
#define S32K566
#endif

#ifndef DERIVATIVE_S32K566
#define DERIVATIVE_S32K566
#endif
/** 
* @brief This macro define specific platform.
*/
#ifndef S32K5XX
#define S32K5XX
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* DEVICEDEFINITION_H */

/** @} */


