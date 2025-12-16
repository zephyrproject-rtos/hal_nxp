/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#if !defined(XSPI_IP_FEATURES_H)
#define XSPI_IP_FEATURES_H

/**
*   @file Xspi_Ip_Features.h
*
*   @addtogroup IPV_XSPI
*   @{
*/

/* implements Xspi_Ip_Features.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32K566_XSPI.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_FEATURES_VENDOR_ID_CFG                      43
#define XSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG       4
#define XSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG       9
#define XSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG    0
#define XSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG               0
#define XSPI_IP_FEATURES_SW_MINOR_VERSION_CFG               8
#define XSPI_IP_FEATURES_SW_PATCH_VERSION_CFG               0


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* XSPI module features */

/*! @brief First address of the serial flash device on the AHB bus for XSPI instances */
#define FEATURE_XSPI_AMBA_BASE                        0x81000000UL

/*! @brief XSPI side B is available */
#define FEATURE_XSPI_HAS_SIDE_B                       0
/*! @brief Supports Dll feature */
#define FEATURE_XSPI_HAS_DLL                          1

#define FEATURE_XSPI_EXT_DQS_LATENCY                  0

/*! @brief Size of Tx FIFO. */
#define FEATURE_XSPI_TX_BUF_SIZE                      1024U
/*! @brief Size of Rx FIFO. */
#define FEATURE_XSPI_RX_BUF_SIZE                      256U
/*! @brief Number of LUT registers that make up a LUT sequence */
#define FEATURE_XSPI_LUT_SEQUENCE_SIZE                5U

/*! @brief The maximum size of manufacturer & device ID that flash memories can have */
#define FEATURE_EXFLS_FLASH_MDID_SIZE                 10U

/*! @brief AHB base pointers initializer for all XSPI units */
#define XSPI_AHB_PTRS                                 {FEATURE_XSPI_AMBA_BASE}


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_FEATURES_H */


