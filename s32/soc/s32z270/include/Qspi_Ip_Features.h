/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#if !defined(QSPI_IP_FEATURES_H)
#define QSPI_IP_FEATURES_H

/**
*   @file Qspi_Ip_Features.h
*
*   @addtogroup IPV_QSPI
*   Qspi_Ip_Features.h_Artifact
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
#include "S32Z2_QUADSPI.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_FEATURES_VENDOR_ID_CFG                      43
#define QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG       4
#define QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG       7
#define QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG    0
#define QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG               2
#define QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG               0
#define QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG               1


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* QuadSPI module features */

/*! @brief First address of the serial flash device on the AHB bus for QuadSPI instances */
#define FEATURE_QSPI_AMBA_BASE                        {0x00000000UL,0x10000000UL}
/*! @brief Size of AHB buffer. */
#define FEATURE_QSPI_AHB_BUF_SIZE                     1024U
/*! @brief Size of Tx FIFO. */
#define FEATURE_QSPI_TX_BUF_SIZE                      1024U
/*! @brief Size of Rx FIFO. */
#define FEATURE_QSPI_RX_BUF_SIZE                      256U
/*! @brief Number of LUT registers that make up a LUT sequence */
#define FEATURE_QSPI_LUT_SEQUENCE_SIZE                5U
/* Minimum entries of 4 bytes fill needed to allow Tx operation to start */
#define FEATURE_QSPI_TX_MIN_BUF_FILL                  1U

/*! @brief Supports Double Data Rate operation */
#define FEATURE_QSPI_DDR                              1
/*! @brief QSPI side B is available */
#define FEATURE_QSPI_HAS_SIDE_B                       1
/*! @brief Configurable Idle Signal Drive */
#define FEATURE_QSPI_CONFIGURABLE_ISD                 1

/*! @brief Supports addr. config options (column address, word addressable) */
#define FEATURE_QSPI_ADDR_CFG                         1
/*! @brief Supports byte swap */
#define FEATURE_QSPI_BYTES_SWAP_ADDR                  1

/*! @brief Supports center-aligned read strobe */
#define FEATURE_QSPI_CENTER_ALIGNED_READ_STROBE       1
/*! @brief Supports differential clock */
#define FEATURE_QSPI_DIFFERENTIAL_CLOCK               1

/*! @brief Supports internal DQS sampling mode */
#define FEATURE_QSPI_INTERNAL_DQS                     0
/*! @brief Supports loopback sampling mode */
#define FEATURE_QSPI_LOOPBACK                         1
/*! @brief Supports DQS loopback sampling mode */
#define FEATURE_QSPI_LOOPBACK_DQS                     0
/*! @brief Supports external DQS sampling mode */
#define FEATURE_QSPI_EXTERNAL_DQS                     1
/*! @brief Supports DQS_FA_SEL/DQS_FB_SEL field in MCR register for DQS selection */
#define FEATURE_QSPI_SELECT_DQS                       1

/*! @brief Supports Dll feature */
#define FEATURE_QSPI_HAS_DLL                          1
/*! @brief Supports full DLL features (as opposed to bypass mode only) */
#define FEATURE_QSPI_EXTERNAL_DLL_FULL                1
/*! @brief Supports DLL reference counter and DLL resolution */
#define FEATURE_QSPI_DLL_LOOPCONTROL                  1

/*! @brief Supports secure flash protection feature */
#define FEATURE_QSPI_HAS_SFP                          1

/*! @brief The maximum size of manufacturer & device ID that flash memories can have */
#define FEATURE_EXFLS_FLASH_MDID_SIZE                  10U

/*! @brief AHB base pointers initializer for all QSPI units */
#define QuadSPI_AHB_PTRS                              FEATURE_QSPI_AMBA_BASE


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_FEATURES_H */


