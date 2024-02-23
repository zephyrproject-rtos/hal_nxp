/*
 * Copyright 2022-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_DIO_IP_CFG_H
#define SIUL2_DIO_IP_CFG_H

/**
*   @file Siul2_Dio_Ip_Cfg.h
*   @implements Siul2_Dio_Ip_Cfg.h_Artifact
*
*   @addtogroup DIO_CFG
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
#include "S32Z2_SIUL2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_DIO_IP_VENDOR_ID_CFG_H                       43
#define SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H        7
#define SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define SIUL2_DIO_IP_SW_MAJOR_VERSION_CFG_H                1
#define SIUL2_DIO_IP_SW_MINOR_VERSION_CFG_H                0
#define SIUL2_DIO_IP_SW_PATCH_VERSION_CFG_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Pre-processor switch to enable/disable VirtWrapper support */
#define DIO_VIRTWRAPPER_SUPPORT                 (STD_OFF)

/**
* @brief Support for User mode.
*        If this parameter has been configured to STD_ON, the Dio driver code can be executed from both supervisor and user mode.
*/
#define DIO_ENABLE_USER_MODE_SUPPORT          (STD_OFF)

/**
* @brief Support for REG_PROT in SIUL2 IP.
*        If the current platform implements REG_PROT for SIUL2 IP, this parameter will be defined, and will enable REG_PROT configuration for SIUL2 IP in DIO drvier
*/
#define DIO_SIUL2_REG_PROT_AVAILABLE    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef DIO_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Dio in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef DIO_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief          Pre-processor switch to enable/disable development error detection for Dio Ip API
*
* @implements     Siul2_Dio_Ip_ErrorDetect_define
*/
#define SIUL2_DIO_IP_DEV_ERROR_DETECT                         (STD_OFF)


/** SIUL2_0 */
/** Peripheral DIO_PTA base pointer */
#define DIO_PTA                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_0->PGPDO0)))
/** Peripheral DIO_PTB base pointer */
#define DIO_PTB                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_0->PGPDO1)))
/** SIUL2_1 */
/** Peripheral DIO_PTC base pointer */
#define DIO_PTC                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_1->PGPDO1)))
/** Peripheral DIO_PTD base pointer */
#define DIO_PTD                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_1->PGPDO2)))
/** Peripheral DIO_PTE base pointer */
#define DIO_PTE                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_1->PGPDO3)))
/** Peripheral DIO_PTF base pointer */
#define DIO_PTF                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_1->PGPDO4)))
/** Peripheral DIO_PTG base pointer */
#define DIO_PTG                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_1->PGPDO5)))
/** SIUL2_4 */
/** Peripheral DIO_PTH base pointer */
#define DIO_PTH                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_4->PGPDO5)))
/** Peripheral DIO_PTI base pointer */
#define DIO_PTI                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_4->PGPDO6)))
/** Peripheral DIO_PTJ base pointer */
#define DIO_PTJ                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_4->PGPDO7)))
/** Peripheral DIO_PTK base pointer */
#define DIO_PTK                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_4->PGPDO8)))
/** Peripheral DIO_PTL base pointer */
#define DIO_PTL                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_4->PGPDO9)))
/** SIUL2_5 */
/** Peripheral DIO_PTM base pointer */
#define DIO_PTM                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_5->PGPDO9)))
/** Peripheral DIO_PTN base pointer */
#define DIO_PTN                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_5->PGPDO10)))
/** SIUL2_0 */
/** Peripheral DIO_PTO base pointer */
#define DIO_PTO                            ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2_0->PGPDO10)))

/*==================================================================================================
*                                             ENUMS
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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_DIO_IP_CFG_H */
