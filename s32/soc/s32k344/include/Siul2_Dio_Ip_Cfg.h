/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_DIO_IP_CFG_H
#define SIUL2_DIO_IP_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32K344_SIUL2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_DIO_IP_VENDOR_ID_CFG_H                       43
#define SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H        7
#define SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define SIUL2_DIO_IP_SW_MAJOR_VERSION_CFG_H                3
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

/* Pre-processor switch to enable/disable development error detection for Dio Ip API */
#define SIUL2_DIO_IP_DEV_ERROR_DETECT            (STD_OFF)

/* GPIO - Peripheral instance base addresses */
/** Peripheral PTA base address */
#define PTA_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO0)))
#define PTA_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO1)))
/** Peripheral PTB base address */
#define PTB_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO2)))
#define PTB_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO3)))
/** Peripheral PTC base address */
#define PTC_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO4)))
#define PTC_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO5)))
/** Peripheral PTD base address */
#define PTD_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO6)))
#define PTD_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO7)))
/** Peripheral PTE base address */
#define PTE_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO8)))
#define PTE_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO9)))
/** Peripheral PTF base address */
#define PTF_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO10)))
#define PTF_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO11)))
/** Peripheral PTG base address */
#define PTG_L_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO12)))
#define PTG_H_HALF ((Siul2_Dio_Ip_GpioType *)(&(IP_SIUL2->PGPDO13)))
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

#endif /* SIUL2_DIO_IP_CFG_H */

/** @} */
