/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_DCM_GPR_TYPES_H
#define POWER_IP_DCM_GPR_TYPES_H

/**
*   @file       Power_Ip_DCM_GPR_Types.h
*   @version    3.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif




/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Specific.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_DCM_GPR_TYPES_VENDOR_ID                       43
#define POWER_IP_DCM_GPR_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_DCM_GPR_TYPES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_DCM_GPR_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_DCM_GPR_TYPES_SW_MAJOR_VERSION                3
#define POWER_IP_DCM_GPR_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_DCM_GPR_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_DCM_GPR_Types.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_DCM_GPR_TYPES_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_DCM_GPR_Types.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_DCM_GPR_Types.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_DCM_GPR_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_DCM_GPR_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_DCM_GPR_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_DCM_GPR_Types.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_DCM_GPR_Types.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_DCM_GPR_TYPES_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_DCM_GPR_TYPES_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_DCM_GPR_TYPES_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_DCM_GPR_Types.h and Power_Ip_Specific.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define POWER_IP_GLOBAL_PADKEEPING_ENABLED      (0U)
#define POWER_IP_GLOBAL_PADKEEPING_DISABLED     (1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration for DCM_GPR.
* @details          The power control unit (DCM_GPR) acts as a bridge for mapping the DCM_GPR peripheral
 *                  to the DCM_GPR address space.
*/
typedef struct
{
    boolean DcmGprUnderMcuControl;   /**< @brief Specifies whether the the DCM_GPR registers is under MCU control. */
    uint8  BootMode;               /**< @brief The boot mode after exiting Standby mode. */
    uint32 BootAddress;            /**< @brief Cortex-M7_0 base address of vector table. */
    uint32 ConfigRegister;         /**< @brief DCM_GPR configuration register (DCMRWF2) */
    boolean GlobalPadkeeping;      /**< @brief Global Padkeeping enablement (DCMRWF1[STANBY_IO_CONFIG]) */
} Power_Ip_DCM_GPR_ConfigType;

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
#endif /* POWER_IP_DCM_GPR_TYPES_H */

