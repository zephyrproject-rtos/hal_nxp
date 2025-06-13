/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SRX_IP_DEFINES_H
#define SRX_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup FLEXIO_SENT_DRIVER_CONFIGURATION Flexio_Sent Driver Configurations
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

#include "Mcal.h"

#include <zephyr/devicetree.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SRX_IP_DEFINES_VENDOR_ID                     43
#define SRX_IP_DEFINES_AR_RELEASE_MAJOR_VERSION      4
#define SRX_IP_DEFINES_AR_RELEASE_MINOR_VERSION      7
#define SRX_IP_DEFINES_AR_RELEASE_REVISION_VERSION   0
#define SRX_IP_DEFINES_SW_MAJOR_VERSION              2
#define SRX_IP_DEFINES_SW_MINOR_VERSION              0
#define SRX_IP_DEFINES_SW_PATCH_VERSION              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((SRX_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SRX_IP_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Srx_Ip_Defines.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
/*
* @brief          Support for User Mode feature.
* @details        This parameter is enabled only in order to support the write access to some registers are protected in user mode.
*/
#define SRX_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == SRX_IP_ENABLE_USER_MODE_SUPPORT)
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running SRX in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == SRX_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*
* @brief          Switches the Development Error Detection and Notification ON or OFF.
* @details        Shall activate or deactivate the detection of all development errors.
*
*/
#define SRX_IP_DEV_ERROR_DETECT    (STD_OFF)

/*
* @brief          Switches the DMA Feature ON or OFF.
* @details        Shall activate or deactivate the DMA feature.
*
*/

#define SRX_IP_DMA_FEATURE_ENABLE    (STD_OFF)
/*
* @brief          Switches the Timestamp Feature ON or OFF.
* @details        Shall activate or deactivate the timestamp feature.
*
*/

#define SRX_IP_TIMESTAMP_FEATURE_ENABLE    (STD_ON)
/**
* @brief      Specifies the timeout for  this module instance.
*
*/
#define SRX_IP_TIMEOUT    (uint32)100000U

/**
* @brief      TIMEOUT for sync transmissions
*/
#define SRX_IP_TIMEOUT_TYPE    (OSIF_COUNTER_DUMMY)

/**
* @brief      Interrupt combine enabled
*/
#define SRX_IP_INTERRUPT_COMBINED    (STD_ON)

/*
* @brief         Number of configured controllers
* @details       Number of configured controllers as defined by user in configuration tool
*
*/
#define SRX_IP_INSTANCE_COUNT    DT_NUM_INST_STATUS_OKAY(nxp_s32_sent)

#define SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_COMBINED

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

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

#endif /* SRX_IP_DEFINES_H */

