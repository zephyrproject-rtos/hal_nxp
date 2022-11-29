/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_FEATURES_H
#define NETC_ETH_IP_FEATURES_H

/**
 * @file Netc_Eth_Ip_Features.h
 *
 * @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_FEATURES_VENDOR_ID                    43
#define NETC_ETH_IP_FEATURES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_FEATURES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_FEATURES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_FEATURES_SW_MAJOR_VERSION             0
#define NETC_ETH_IP_FEATURES_SW_MINOR_VERSION             9
#define NETC_ETH_IP_FEATURES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Total number of virtual ethernet controllers supported on NETC(VSIs). */
#define FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS       7

/** @brief Total number of physical ethernet controllers supported on NETC(PSIs). */
#define NETC_ETH_IP_NUM_OF_PHYSICAL_CTRLS           (1U)

/** @brief Total number of ethernet controllers supported on NETC(VSI + PSI). */
#define FEATURE_NETC_ETH_NUMBER_OF_CTRLS            (8U)

/** @brief Index of the physical SI. */
#define NETC_ETH_IP_PSI_INDEX                       (0U)

/** @brief Alignment for buffer descriptor. */
#define FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES      (128U)

/** @brief Alignment for buffer. */
#define FEATURE_NETC_BUFF_ALIGNMENT_BYTES           (64U)

/** @brief Alignment value for virtual station interface message send. */
#define FEATURE_NETC_ETH_VSI_MSG_ALIGNMENT          (64U)

/* TODO: Generate this from configuration. From all VSs take the bigger value. */
/** @brief Number of RX BDR used.*/
#define FEATURE_NETC_RX_BDR_COUNT (18U)
/** @brief Number of TX BDR used.*/
#define FEATURE_NETC_TX_BDR_COUNT (18U)

/** @brief MSI table base address of each SI. */
#define NETC_ETH_IP_MSI_BASE_PTRS { (uint32 *)(0x74BB0000U), (uint32 *)(0x74C30000U), (uint32 *)(0x74C40000U), (uint32 *)(0x74C50000U), \
                                    (uint32 *)(0x74C60000U), (uint32 *)(0x74C70000U), (uint32 *)(0x74C80000U), (uint32 *)(0x74C90000U) }

/** @brief Index in the MSI table of VSI to PSI interrupt. */
#define NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX  (0U)
/** @brief Index in the MSI table of TX interrupt. */
#define NETC_ETH_IP_TX_MSI_TABLE_INDEX              (1U)
/** @brief Index in the MSI table of RX interrupt. */
#define NETC_ETH_IP_RX_MSI_TABLE_INDEX              (2U)
/** @brief MSI message control enable mask. */
#define NETC_ETH_IP_MSI_MSG_CTL_ENABLE_MASK         (0x8000U)
/** @brief Number of entries for a MSI table of a SI. */
#define NETC_ETH_IP_NUM_OF_ENTRIES_MSITABLE         (3U)

/** @brief Extract a specific bit form a byte. */
#define NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(Byte)      ((Byte) & 1U)
#define NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(Byte)      (((Byte) >> 1U) & 0x01U)
#define NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(Byte)      (((Byte) >> 2U) & 0x01U)
#define NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(Byte)      (((Byte) >> 3U) & 0x01U)
#define NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(Byte)      (((Byte) >> 4U) & 0x01U)
#define NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(Byte)      (((Byte) >> 5U) & 0x01U)
#define NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(Byte)      (((Byte) >> 6U) & 0x01U)
#define NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(Byte)      (((Byte) >> 7U) & 0x01U)

/** @brief Number of bytes in a MAC address. */
#define NETC_ETH_IP_MAC_BYTES_SIZE                  (uint8)(6U)

/** @brief Select hash value register. */
#define NETC_ETH_IP_SELECT_HASH_REGISTER            (uint8)(0x20U)

/** @brief Select hash value register. */
#define NETC_ETH_IP_HASH_VALUE                      (uint8)(0x1FU)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif
