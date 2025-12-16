/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_CFG_H
#define XSPI_IP_CFG_H

/**
*   @file Xspi_Ip_Cfg.h
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip_Cfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Xspi_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_VENDOR_ID_CFG                    43
#define XSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define XSPI_IP_AR_RELEASE_MINOR_VERSION_CFG     9
#define XSPI_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define XSPI_IP_SW_MAJOR_VERSION_CFG             0
#define XSPI_IP_SW_MINOR_VERSION_CFG             8
#define XSPI_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Types.h header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_CFG != XSPI_IP_TYPES_VENDOR_ID)
    #error "Xspi_Ip_Cfg.h and Xspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG    != XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_CFG    != XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Cfg.h and Xspi_Ip_Types.h are different"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_CFG != XSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_SW_MINOR_VERSION_CFG != XSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_SW_PATCH_VERSION_CFG != XSPI_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_Cfg.h and Xspi_Ip_Types.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Number of serial flash devices */
#define XSPI_IP_MEM_INSTANCE_COUNT        (1U)

/* Maximum number of retries for Write Enable command */
#define XSPI_IP_MAX_RETRY                 (3U)

/* Development error detection for XSPI Ip API */
#define XSPI_IP_DEV_ERROR_DETECT          (STD_OFF)

/* Timeout for DLL lock sequence */
#define XSPI_IP_DLL_LOCK_TIMEOUT          (2147483647U)

/* Timeout for XSPI command completion */
#define XSPI_IP_CMD_COMPLETE_TIMEOUT      (2000000U)

/* Timeout for external flash software reset completion */
#define XSPI_IP_RESET_TIMEOUT             (2000000U)

/* Timeout for external flash startup initialization sequence completion */
#define XSPI_IP_FLS_INIT_TIMEOUT          (2000000U)

/* Timeout for a complete read operation */
#define XSPI_IP_READ_TIMEOUT              (2147483647U)

/* OsIf counter type used in timeout detection for XSPI IP operations  */
#define XSPI_IP_TIMEOUT_TYPE              (OSIF_COUNTER_DUMMY)

/* Delay after changing the value of the XSPI software reset bits */
#define XSPI_IP_SOFTWARE_RESET_DELAY      (276U)

/*! @brief Minimum delay in CPU cycles between Tx FIFO reset and Tx FIFO push */
#define XSPI_IP_TX_BUFFER_RESET_DELAY     (430U)

/* XSPI user mode support macro */
#define XSPI_IP_ENABLE_USER_MODE_SUPPORT  (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == XSPI_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_CFG_H */


