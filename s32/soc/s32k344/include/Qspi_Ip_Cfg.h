/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_CFG_H
#define QSPI_IP_CFG_H

/**
*   @file Qspi_Ip_Cfg.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_Cfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Qspi_Ip_Init_PBcfg.h"
#include <zephyr/devicetree.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_CFG                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define QSPI_IP_SW_MAJOR_VERSION_CFG             3
#define QSPI_IP_SW_MINOR_VERSION_CFG             0
#define QSPI_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Init_PBcfg.h header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_CFG != QSPI_IP_INIT_PBCFG_VENDOR_ID)
    #error "Qspi_Ip_Cfg.h and Qspi_Ip_Init_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Init_PBcfg.h header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Qspi_Ip_Cfg.h and Qspi_Ip_Init_PBcfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Init_PBcfg.h header file are of the same software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_CFG != QSPI_IP_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (QSPI_IP_SW_MINOR_VERSION_CFG != QSPI_IP_INIT_PBCFG_SW_MINOR_VERSION) || \
     (QSPI_IP_SW_PATCH_VERSION_CFG != QSPI_IP_INIT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_Cfg.h and Qspi_Ip_Init_PBcfg.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Maximum number of retries for Write Enable command */
#define QSPI_IP_MAX_RETRY                 (3U)

/* Pre-processor switch to enable/disable development error detection for QSPI Ip API */
#define DEV_ASSERT_QSPI(x)
/* Number of serial flash devices */
#define QSPI_IP_MEM_INSTANCE_COUNT        (DT_NUM_INST_STATUS_OKAY(nxp_s32_qspi_nor))

/* Timeout for DLL lock sequence */
#define QSPI_IP_DLL_LOCK_TIMEOUT          (2147483647U)

/* Timeout for QSPI command completion */
#define QSPI_IP_CMD_COMPLETE_TIMEOUT      (2000000U)

/* After the FRAD checks pass we wait for QSPI to become idle */
#define QSPI_IP_QSPI_IDLE_TIMEOUT         (0U)

/* Timeout for external flash software reset completion */
#define QSPI_IP_RESET_TIMEOUT             (2000000U)

/* Timeout for external flash startup initialization sequence completion */
#define QSPI_IP_FLS_INIT_TIMEOUT          (2000000U)

/* Timeout for a complete read operation */
#define QSPI_IP_READ_TIMEOUT              (2147483647U)

/* OsIf counter type used in timeout detection for QSPI IP operations  */
#define QSPI_IP_TIMEOUT_TYPE              (OSIF_COUNTER_DUMMY)

/* Delay after changing the value of the QSPI software reset bits */
#define QSPI_IP_SOFTWARE_RESET_DELAY      (276U)

/*! @brief Minimum delay in CPU cycles between Tx FIFO reset and Tx FIFO push */
#define QSPI_IP_TX_BUFFER_RESET_DELAY     (430U)

/* QSPI user mode support macro */
#define QSPI_IP_ENABLE_USER_MODE_SUPPORT  (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == QSPI_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CFG_H */
