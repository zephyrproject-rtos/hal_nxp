/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_TYPES_H
#define NETC_ETH_IP_TYPES_H

/**
*   @file Netc_Eth_Ip_Types.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Netc_Eth_Ip_Cfg_Defines.h"
#include "Netc_Eth_Ip_Features.h"
#include "Netc_Eth_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_TYPES_VENDOR_ID                    43
#define NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_TYPES_SW_MAJOR_VERSION             2
#define NETC_ETH_IP_TYPES_SW_MINOR_VERSION             0
#define NETC_ETH_IP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Cfg_Defines.h */
#if (NETC_ETH_IP_TYPES_VENDOR_ID != NETC_ETH_IP_CFG_DEFINES_VENDOR_ID)
    #error "Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg_Defines.h are different"
#endif
#if ((NETC_ETH_IP_TYPES_SW_MAJOR_VERSION != NETC_ETH_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_MINOR_VERSION != NETC_ETH_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_PATCH_VERSION != NETC_ETH_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg_Defines.h are different"
#endif

/* Checks against Netc_Eth_Ip_Features.h */
#if (NETC_ETH_IP_TYPES_VENDOR_ID != NETC_ETH_IP_FEATURES_VENDOR_ID)
    #error "Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Features.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Features.h are different"
#endif
#if ((NETC_ETH_IP_TYPES_SW_MAJOR_VERSION != NETC_ETH_IP_FEATURES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_MINOR_VERSION != NETC_ETH_IP_FEATURES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_PATCH_VERSION != NETC_ETH_IP_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Features.h are different"
#endif

/* Checks against Netc_Eth_Ip_Cfg.h */
#if (NETC_ETH_IP_TYPES_VENDOR_ID != NETC_ETH_IP_CFG_VENDOR_ID)
    #error "Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg.h are different"
#endif
#if ((NETC_ETH_IP_TYPES_SW_MAJOR_VERSION != NETC_ETH_IP_CFG_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_MINOR_VERSION != NETC_ETH_IP_CFG_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_TYPES_SW_PATCH_VERSION != NETC_ETH_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Types.h and Netc_Eth_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#if (NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES > 0)
#ifdef NETC_ETH_0_USED
/*!
 *  @brief SI enablement check for SI bitmap.
 */
#define NETC_ETH_IP_CHECK_SI_BITMAP_VALUE(SiBitmap, CtrlIndex)      ((boolean)((SiBitmap >> CtrlIndex) & 0x01U))
#endif
#endif

/*!
 * @brief CMBDR requeste length field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_REQUEST_LENGTH_SHIFT               (20U)
/*!
 * @brief CMBDR requeste length field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_REQUEST_LENGTH_MASK                (0xFFF00000UL)
/*!
 * @brief CMBDR requeste lengtht.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_REQUEST_LENGTH(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_REQUEST_LENGTH_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_REQUEST_LENGTH_MASK)

/*!
 * @brief CMBDR response length field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_RESPONSE_LENGTH_SHIFT               (0U)
/*!
 * @brief CMBDR response length field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_RESPONSE_LENGTH_MASK                (0x000FFFFFUL)
/*!
 * @brief CMBDR response length.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_RESPONSE_LENGTH(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_RESPONSE_LENGTH_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_RESPONSE_LENGTH_MASK)

/** @brief CMD field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_SHIFT              (0U)
/** @brief CMD field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_MASK               (0x0000000FUL)
/** @brief CMD field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD_MASK)

/*!
 * @brief CMBDR request config access method field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_SHIFT    (12U)
/*!
 * @brief CMBDR request config access method field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_MASK     (0x00003000UL)
/*!
 * @brief CMBDR request config field access method.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD(x)       (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD_MASK)

/*!
 * @brief CMBDR request config field table id.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_SHIFT         (16U)
/*!
 * @brief CMBDR request config field table id mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_MASK          (0x00FF0000UL)
/*!
 * @brief CMBDR request config table id.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID(x)            (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID_MASK)

/*!
 * @brief CMBDR request version field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_SHIFT          (24U)
/*!
 * @brief CMBDR request version field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_MASK           (0x3F000000UL)
/*!
 * @brief CMBDR request version.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION_MASK)

/*!
 * @brief CMBDR request config field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_SHIFT              (30U)
/*!
 * @brief CMBDR request config field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_MASK               (0x4F000000UL)
/*!
 * @brief CMBDR request config.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI_MASK)

/*!
 * @brief CMBDR request RR field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_SHIFT                (31U)
/*!
 * @brief CMBDR request RR field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_MASK                 (0x80000000UL)
/*!
 * @brief CMBDR request RR.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RR(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RR_MASK)

/*!
 * @brief CMBDR request NPF field.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_NPF_FIELD_SHIFT                      (15U)
/*!
 * @brief CMBDR request NPF field mask.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_NPF_FIELD_MASK                       (0x00008000UL)
/*!
 * @brief CMBDR request NPF.
 */
#define NETC_ETH_IP_CMDBD_REQFMT_NPF_FIELD(x)                         (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_NPF_FIELD_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_NPF_FIELD_MASK)

#define NETC_ETH_IP_RSPHEADER_STATUS_FIELD_INDEX        (0x3U)  /*!< status field includes RR bit, ERROR field and NUM_MATCHED field in Response Header Format */

/* +++definitions for NTMP response message+++ */
/*!
 * @brief CMBDR RR status field.
 */
#define NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_SHIFT             (31U)
/*!
 * @brief CMBDR RR status field mask.
 */
#define NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_MASK              (0x80000000UL)

/*!
 * @brief CMBDR error status field.
 */
#define NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_SHIFT          (16U)
/*!
 * @brief CMBDR error status field mask.
 */
#define NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_MASK           (0x0FFF0000UL)

/*!
 * @brief CMBDR status field num matched.
 */
#define NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_SHIFT     (0U)
/*!
 * @brief CMBDR status field num matched mask.
 */
#define NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_MASK      (0x0000FFFFUL)
/* ---definitions for NTMP response message--- */

/* +++definitions for NTMP V1.0 CBD fields+++ */
/** @brief EN field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN_SHIFT              (31U)
/** @brief EN field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN_MASK               (0xF0000000UL)
/** @brief EN field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN_MASK)

/** @brief SF field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF_SHIFT              (31U)
/** @brief SF field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF_MASK               (0xF0000000UL)
/** @brief SF field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF_MASK)

/** @brief CI field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI_SHIFT              (30U)
/** @brief CI field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI_MASK               (0xF0000000UL)
/** @brief CI field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI_MASK)

/** @brief STATUS field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_SHIFT              (24U)
/** @brief STATUS field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_MASK               (0xFF000000UL)
/** @brief STATUS field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_MASK)

/** @brief CLASS field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS_SHIFT              (8U)
/** @brief CLASS field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS_MASK               (0xFFFFFF00UL)
/** @brief CLASS field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS_MASK)

/** @brief COMMAND field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND_SHIFT              (0U)
/** @brief COMMAND field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND_MASK               (0xFFFFFFFFUL)
/** @brief COMMAND field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND_MASK)

/** @brief STATUS field shift */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_LEFT_SHIFT              (3U)
/** @brief STATUS field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_RIGHT_SHIFT             (27U)
/** @brief STATUS field get */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_GET_STATUS(x)                 (uint8)(((x) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_LEFT_SHIFT) >> NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_RIGHT_SHIFT)

/** @brief STATUS field shift */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_RFS_LEFT_SHIFT              (4U)
/** @brief STATUS field mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_RFS_RIGHT_SHIFT             (28U)
/** @brief STATUS field get */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RFS_GET_STATUS(x)                 (uint8)(((x) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_RFS_LEFT_SHIFT) >> NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS_RFS_RIGHT_SHIFT)

/** @brief TPID field */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_SHIFT                  (16U)
/** @brief TPID field set mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_SET_MASK               (0x00030000UL)
/** @brief TPID field get mask */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_GET_MASK               (0x00000003UL)
/** @brief TPID field set */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SET_TPID(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_SET_MASK)
/** @brief TPID field get */
#define NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_GET_TPID(x)                 (((uint32)(((uint32)(x)) >> NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_SHIFT)) & NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TPID_GET_MASK)
/* ---definitions for NTMP V1.0 CBD fields--- */


#define NETC_ETH_RFS_ENTRY_SET_DATA_BUFFER_SIZE             (29U)  /*there are a total of 116bytes for RFS table which will be loaded into a uint32 array*/
/*!
 * @brief Time Gate Scheduling Table CFGE_DATA field.
 */
/* Administrative Traffic Class Gate States for Gate Entry */
#define NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_SHIFT          (0U)
#define NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_MASK           (0x000000FFUL)
#define NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_TC_STATES(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_SHIFT)) & NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_TC_STATES_MASK)

/* Administrative gate operation type (as per IEEE 802.1Q-2018) field for gate control list entry */
#define NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_HR_CB_SHIFT              (16U)
#define NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_HR_CB_MASK               (0x000F0000UL)
#define NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_HR_CB(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_HR_CB_SHIFT)) & NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_HR_CB_MASK)

/*!
 * @brief Tables Request Data Buffer CFGEU field.
 */
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU_SHIFT         (0U)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU_MASK          (0x00000001UL)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU(x)            (((uint32)(((uint32)(x)) << NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU_SHIFT)) & NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU_MASK)

/*!
 * @brief Tables Request Data Buffer QUERY_ACTIONS field.
 */
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_SHIFT (24U)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_MASK  (0x0F000000UL)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(x)    (((uint32)(((uint32)(x)) << NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_SHIFT)) & NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS_MASK)

/*!
 * @brief Tables Request Data Buffer TABLE_VERSION field.
 */
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_SHIFT (28U)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_MASK  (0xF0000000UL)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(x)   (((uint32)(((uint32)(x)) << NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_SHIFT)) & NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSION_MASK)

#if (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0)
/*!
 * @brief Eth Rate Policer Table Request Data Buffer FEEU field.
 */
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_FEEU_SHIFT          (1U)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_FEEU_MASK           (0x00000002UL)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_FEEU(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_FEEU_SHIFT)) & NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_FEEU_MASK)

/*!
 * @brief Eth Rate Policer Table Request Data Buffer PSEU field.
 */
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_PSEU_SHIFT          (2U)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_PSEU_MASK           (0x00000004UL)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_PSEU(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_PSEU_SHIFT)) & NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_PSEU_MASK)


/*!
 * @brief Eth Rate Policer Table Request Data Buffer STSEU field.
 */
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT          (3U)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK           (0x00000008UL)
#define NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
* @brief Eth Rate Policer Table FEE_DATA Format
*/
#define NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN_SHIFT              (0U)
#define NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN_MASK               (0x00000001UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN_MASK)

/*!
* @brief Eth Rate Policer Table CFGE_DATA config bits Format
*/
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_SHIFT            (0U)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK             (0x00000001UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK)

#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_SHIFT             (1U)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_MASK              (0x00000002UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_MASK)

#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM_SHIFT              (2U)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM_MASK               (0x00000004UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM_MASK)

#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF_SHIFT              (3U)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF_MASK               (0x00000008UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF_MASK)

#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_SHIFT            (4U)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_MASK             (0x00000010UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_MASK)

#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_SHIFT        (5U)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_MASK         (0x00000060UL)
#define NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE(x)           (((uint32)(((uint32)(x)) << NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_SHIFT)) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_MASK)
#endif /* (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0) */

/*!
 * @brief Ingress Port Filter table CFGE_DATA config field.
 */
/* IPV field */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV_SHIFT             (0U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV_MASK              (0x0000000FUL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV_MASK)

/* OIPV */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV_SHIFT            (4U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV_MASK             (0x00000010UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV_MASK)

/* DR */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR_SHIFT              (5U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR_MASK               (0x00000060UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR_MASK)

/* ODR */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR_SHIFT             (7U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR_MASK              (0x00000080UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR_MASK)

/* FLTFA */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA_SHIFT            (8U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA_MASK             (0x00000300UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA_MASK)

/* WOLTE */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE_SHIFT            (12U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE_MASK             (0x00001000UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE_MASK)
/* FLTA */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA_SHIFT              (13U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA_MASK               (0x00006000UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA_MASK)

/* RPR */
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR_SHIFT               (15U)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR_MASK                (0x00018000UL)
#define NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR_SHIFT)) & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR_MASK)

/*!
 * @brief Ingress Port Filter table KEYE_DATA field.
 */
/* DSCP field */
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP_SHIFT               (0U)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP_MASK                (0x0000003FUL)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP_SHIFT)) & NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP_MASK)

/* DSCP Mask field */
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK_SHIFT           (6U)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK_MASK            (0x00000FC0UL)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK(x)              (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK_SHIFT)) & NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK_MASK)

/* SRC_PORT field */
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPRTID_SHIFT             (16U)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPRTID_MASK              (0x001F0000UL)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPRTID(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPRTID_SHIFT)) & NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPRTID_MASK)

/* SRC_PORT Mask field */
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_SHIFT         (21U)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_MASK          (0x03E00000UL)
#define NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK(x)            (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_SHIFT)) & NETC_ETH_IP_IPFTABLE_KEYE_DATA_SRCPORTMASK_MASK)

/*!
 * @brief Ingress Port Filter table Request Data Buffer STSEU field.
 */
#define NETC_ETH_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT    (1U)
#define NETC_ETH_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK     (0x00000002UL)
#define NETC_ETH_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU(x)       (((uint32)(((uint32)(x)) << NETC_ETH_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_SHIFT)) & NETC_ETH_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU_MASK)

/*!
 * @brief Filter Forwarding Action data type definitions for Ingress Port Filter Table.
 */
typedef uint32 Netc_Eth_Ip_CfgeFilterForwardingActionDataType;
#define NETC_ETH_IP_INGRESSPORTFILTERTABLE_DISCARDFRAMES     (0x0U)           /*!< discard frames */
#define NETC_ETH_IP_INGRESSPORTFILTERTABLE_PERMITFRAMES      (0x1U)           /*!< permit frames */

/*!
 * @brief Filter Action data type definitions for Ingress Port Filter Table.
 */
typedef uint32 Netc_Eth_Ip_CfgeFilterActionDataType;
#define NETC_ETH_IP_INGRESSPORTFILTERTABLE_NOACTION                              (0x0U) /*!< no action */
#define NETC_ETH_IP_INGRESSPORTFILTERTABLE_RATEACTION                            (0x1U) /*!< Rate action with the Rate Policer Entry ID (RP_EID) set to the value configured in the FLTA_TGT field of this entry */
#define NETC_ETH_IP_INGRESSPORTFILTERTABLE_INGRESSSTREAMIDENTIFICATIONACTION     (0x2U) /*!< Ingress stream identification action where the Ingress Stream Entry ID (IS_EID) is set to the value configured in the FLTA_TGT field of this entry */
#define NETC_ETH_IP_INGRESSPORTFILTERTABLE_SETTINGL2FILTERINGSIBITMAP            (0x3U) /*!< valid on ENETC side. Setting a pre L2 filtering SI bitmap that will be used by the L2 filtering function to determine the final SI bitmap */

typedef uint32 Netc_Eth_Ip_EnetcForwardingActionDataType;
#define NETC_ETH_IP_ENETC_DISCARDFRAMES                (0x0U)           /*!< discard frames */
#define NETC_ETH_IP_ENETC_ALLOWWITHOUTSIBITMAP         (0x1U)           /*!< Allow without setting the pre L2 filtering SI bitmap. */
#define NETC_ETH_IP_SWT_ALLOWWITHSIBITMAP              (0x2U)           /*!< Allow with setting the pre L2 filtering SI bitmap to the value configured in the SI_MAP field of this entry. */

/*!
* @brief Ingres Stream Identification (ISI) Table KEYE_DATA bits Format
*/
#define NETC_ETH_IP_ISITABLE_KEYE_KEYTYPE_SHIFT          (0U)
#define NETC_ETH_IP_ISITABLE_KEYE_KEYTYPE_MASK           (0x00000003UL)
#define NETC_ETH_IP_ISITABLE_KEYE_KEYTYPE(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_ISITABLE_KEYE_KEYTYPE_SHIFT)) & NETC_ETH_IP_ISITABLE_KEYE_KEYTYPE_MASK)

#define NETC_ETH_IP_ISITABLE_KEYE_SRCPORTID_SHIFT        (2U)
#define NETC_ETH_IP_ISITABLE_KEYE_SRCPORTID_MASK         (0x0000007CUL)
#define NETC_ETH_IP_ISITABLE_KEYE_SRCPORTID(x)           (((uint32)(((uint32)(x)) << NETC_ETH_IP_ISITABLE_KEYE_SRCPORTID_SHIFT)) & NETC_ETH_IP_ISITABLE_KEYE_SRCPORTID_MASK)

#define NETC_ETH_IP_ISITABLE_KEYE_SPM_SHIFT              (7U)
#define NETC_ETH_IP_ISITABLE_KEYE_SPM_MASK               (0x00000080UL)
#define NETC_ETH_IP_ISITABLE_KEYE_SPM(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_ISITABLE_KEYE_SPM_SHIFT)) & NETC_ETH_IP_ISITABLE_KEYE_SPM_MASK)



typedef uint32 Netc_Eth_Ip_KeyTypeIdxType;
#define NETC_ETH_IP_ENETC_KEYTYPE_0                      (0x00U)         /* Enetc function, key construction is specified in ISIDKC0CR0 */
#define NETC_ETH_IP_ENETC_KEYTYPE_1                      (0x01U)         /* Enetc function, key construction is specified in ISIDKC1CR0 */

#if ((NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U) || (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U))
/*!
 * @brief Stream Gate Instance Table Request Data Buffer ACFGEU (Admin Configuration Element Update.) field.
 */
#define NETC_ETH_IP_SGITABLE_REQFMT_ACFGEU_SHIFT                 (0U)
#define NETC_ETH_IP_SGITABLE_REQFMT_ACFGEU_MASK                  (0x00000001UL)
#define NETC_ETH_IP_SGITABLE_REQFMT_ACFGEU(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_REQFMT_ACFGEU_SHIFT)) & NETC_ETH_IP_SGITABLE_REQFMT_ACFGEU_MASK)

/*!
 * @brief Stream Gate Instance Table Request Data Buffer CFGEU (Configuration Element Update) field.
 */
#define NETC_ETH_IP_SGITABLE_REQFMT_CFGEU_SHIFT                  (1U)
#define NETC_ETH_IP_SGITABLE_REQFMT_CFGEU_MASK                   (0x00000002UL)
#define NETC_ETH_IP_SGITABLE_REQFMT_CFGEU(x)                     (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_REQFMT_CFGEU_SHIFT)) & NETC_ETH_IP_SGITABLE_REQFMT_CFGEU_MASK)

/*!
 * @brief Stream Gate Instance Table Request Data Buffer SGISEU (Stream Gate Instance State Element Update) field.
 */
#define NETC_ETH_IP_SGITABLE_REQFMT_SGISEU_SHIFT                 (2U)
#define NETC_ETH_IP_SGITABLE_REQFMT_SGISEU_MASK                  (0x00000004UL)
#define NETC_ETH_IP_SGITABLE_REQFMT_SGISEU(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_REQFMT_SGISEU_SHIFT)) & NETC_ETH_IP_SGITABLE_REQFMT_SGISEU_MASK)

/*!
* @brief Stream Gate Instance Table CFGE_DATA config bits Format
*/
/* Octets Exceeded Enable */
#define NETC_ETH_IP_SGITABLE_CFGE_OEXEN_SHIFT            (0U)
#define NETC_ETH_IP_SGITABLE_CFGE_OEXEN_MASK             (0x00000001UL)
#define NETC_ETH_IP_SGITABLE_CFGE_OEXEN(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_CFGE_OEXEN_SHIFT)) & NETC_ETH_IP_SGITABLE_CFGE_OEXEN_MASK)

/* Invalid Receive Enable */
#define NETC_ETH_IP_SGITABLE_CFGE_IRXEN_SHIFT            (1U)
#define NETC_ETH_IP_SGITABLE_CFGE_IRXEN_MASK             (0x00000002UL)
#define NETC_ETH_IP_SGITABLE_CFGE_IRXEN(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_CFGE_IRXEN_SHIFT)) & NETC_ETH_IP_SGITABLE_CFGE_IRXEN_MASK)

/* Protocol/Service Data Unit */
#define NETC_ETH_IP_SGITABLE_CFGE_SDUTYPE_SHIFT          (2U)
#define NETC_ETH_IP_SGITABLE_CFGE_SDUTYPE_MASK           (0x0000000CUL)
#define NETC_ETH_IP_SGITABLE_CFGE_SDUTYPE(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_CFGE_SDUTYPE_SHIFT)) & NETC_ETH_IP_SGITABLE_CFGE_SDUTYPE_MASK)

/*!
* @brief Stream Gate Instance Table ICFGE_DATA config bits Format
*/
#define NETC_ETH_IP_SGITABLE_ICFGE_IPV_SHIFT             (0U)
#define NETC_ETH_IP_SGITABLE_ICFGE_IPV_MASK              (0x0000000FUL)
#define NETC_ETH_IP_SGITABLE_ICFGE_IPV(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_ICFGE_IPV_SHIFT)) & NETC_ETH_IP_SGITABLE_ICFGE_IPV_MASK)

#define NETC_ETH_IP_SGITABLE_ICFGE_OIPV_SHIFT            (4U)
#define NETC_ETH_IP_SGITABLE_ICFGE_OIPV_MASK             (0x00000010UL)
#define NETC_ETH_IP_SGITABLE_ICFGE_OIPV(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_ICFGE_OIPV_SHIFT)) & NETC_ETH_IP_SGITABLE_ICFGE_OIPV_MASK)

/* Gate State */
#define NETC_ETH_IP_SGITABLE_ICFGE_GST_SHIFT             (5U)
#define NETC_ETH_IP_SGITABLE_ICFGE_GST_MASK              (0x00000020UL)
#define NETC_ETH_IP_SGITABLE_ICFGE_GST(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_ICFGE_GST_SHIFT)) & NETC_ETH_IP_SGITABLE_ICFGE_GST_MASK)

/* Cut Through Disabled */
#define NETC_ETH_IP_SGITABLE_ICFGE_CTD_SHIFT             (6U)
#define NETC_ETH_IP_SGITABLE_ICFGE_CTD_MASK              (0x00000040UL)
#define NETC_ETH_IP_SGITABLE_ICFGE_CTD(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_ICFGE_CTD_SHIFT)) & NETC_ETH_IP_SGITABLE_ICFGE_CTD_MASK)

/*!
 * @brief ICFGE_DATA Gate State data format enum type.
 * This field specifies the gate state to use before the administrative stream gate control list takes affect.
 */
typedef uint32 Netc_Eth_Ip_SGITABLE_GateStateType;
#define NETC_ETH_IP_SGITABLE_GATE_CLOSE                  (0x0U)      /*!< 0b = Closed; frames are not permitted to pass through. */
#define NETC_ETH_IP_SGITABLE_GATE_OPEN                   (0x1U)      /*!< 1b = Open; frames are permitted to pass through. */

/*!
* @brief Stream Gate Instance Table SGISE_DATA config bits Format
*/
#define NETC_ETH_IP_SGITABLE_SGISE_OEX_SHIFT                 (0U)
#define NETC_ETH_IP_SGITABLE_SGISE_OEX_MASK                  (0x00000001UL)
#define NETC_ETH_IP_SGITABLE_SGISE_OEX(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_SGISE_OEX_SHIFT)) & NETC_ETH_IP_SGITABLE_SGISE_OEX_MASK)

#define NETC_ETH_IP_SGITABLE_SGISE_IRX_SHIFT                 (1U)
#define NETC_ETH_IP_SGITABLE_SGISE_IRX_MASK                  (0x00000002UL)
#define NETC_ETH_IP_SGITABLE_SGISE_IRX(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_SGISE_IRX_SHIFT)) & NETC_ETH_IP_SGITABLE_SGISE_IRX_MASK)

#define NETC_ETH_IP_SGITABLE_SGISE_STATE_SHIFT               (2U)
#define NETC_ETH_IP_SGITABLE_SGISE_STATE_MASK                (0x0000001CUL)
#define NETC_ETH_IP_SGITABLE_SGISE_STATE(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGITABLE_SGISE_STATE_SHIFT)) & NETC_ETH_IP_SGITABLE_SGISE_STATE_MASK)
#endif /* ((NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U) || (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U)) */

#if (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U)
/*!
* @brief Stream Gate Control List Table CFGE_DATA config bits Format
*/
#define NETC_ETH_IP_SGCLTABLE_CFGE_LISTLEN_SHIFT             (0U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_LISTLEN_MASK              (0x000000FFUL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_LISTLEN(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_LISTLEN_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_LISTLEN_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTOIPV_SHIFT             (16U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTOIPV_MASK              (0x00010000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTOIPV(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_EXTOIPV_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_EXTOIPV_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTIPV_SHIFT              (17U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTIPV_MASK               (0x001E0000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTIPV(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_EXTIPV_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_EXTIPV_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTCTD_SHIFT              (21U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTCTD_MASK               (0x00200000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTCTD(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_EXTCTD_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_EXTCTD_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTGTST_SHIFT             (22U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTGTST_MASK              (0x00400000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_EXTGTST(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_EXTGTST_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_EXTGTST_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_IOM_SHIFT                 (0U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_IOM_MASK                  (0x00FFFFFFUL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_IOM(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_IOM_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_IOM_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_IPV_SHIFT                 (24U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_IPV_MASK                  (0x0F000000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_IPV(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_IPV_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_IPV_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_OIPV_SHIFT                (28U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_OIPV_MASK                 (0x10000000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_OIPV(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_OIPV_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_OIPV_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_CTD_SHIFT                 (29U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_CTD_MASK                  (0x20000000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_CTD(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_CTD_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_CTD_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_IOMEN_SHIFT               (30U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_IOMEN_MASK                (0x40000000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_IOMEN(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_IOMEN_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_IOMEN_MASK)

#define NETC_ETH_IP_SGCLTABLE_CFGE_GTST_SHIFT                (31U)
#define NETC_ETH_IP_SGCLTABLE_CFGE_GTST_MASK                 (0x80000000UL)
#define NETC_ETH_IP_SGCLTABLE_CFGE_GTST(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_CFGE_GTST_SHIFT)) & NETC_ETH_IP_SGCLTABLE_CFGE_GTST_MASK)

/*!
 * @brief Stream Gate Control List Table SGCLSE_DATA format enum type.
 * This field indicates whether or not a stream gate control list (SGCL) is in-use in a Stream Gate Instance (SGI).
 */
typedef uint32 Netc_Eth_Ip_SGCLTABLE_RefCountType;
#define NETC_ETH_IP_SGCLTABLE_NOT_INUSE_BYSGI                (0x00U)      /*!< Not in-use by an SGI. */
#define NETC_ETH_IP_SGCLTABLE_INUSE_BYSGI                    (0x01U)      /*!< In-use by an SGI. */
#define NETC_ETH_IP_SGCLTABLE_REFCOUNT_RESERVED              (0x02U)      /*!< others reserved. */

/*!
* @brief Stream Gate Control List Table SGCLSE_DATA Format*/
#define NETC_ETH_IP_SGCLTABLE_SGCLSE_REFCOUNT_SHIFT          (0U)
#define NETC_ETH_IP_SGCLTABLE_SGCLSE_REFCOUNT_MASK           (0x000000FFUL)
#define NETC_ETH_IP_SGCLTABLE_SGCLSE_REFCOUNT(x)             (((uint32)(((uint32)(x)) << NETC_ETH_IP_SGCLTABLE_SGCLSE_REFCOUNT_SHIFT)) & NETC_ETH_IP_SGCLTABLE_SGCLSE_REFCOUNT_MASK)
#endif /* (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U) */

/*!
* @brief Ingress Stream Table CFGE_DATA config bits Format
*/
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SFE_SHIFT                (0U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SFE_MASK                 (0x00000001UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SFE(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SFE_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SFE_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IPV_SHIFT                (4U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IPV_MASK                 (0x000000F0UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IPV(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IPV_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IPV_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OIPV_SHIFT               (8U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OIPV_MASK                (0x00000100UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OIPV(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OIPV_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OIPV_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_DR_SHIFT                 (9U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_DR_MASK                  (0x00000600UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_DR(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_DR_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_DR_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ODR_SHIFT                (11U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ODR_MASK                 (0x00000800UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ODR(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ODR_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ODR_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_SHIFT              (12U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_MASK               (0x00001000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IMIRE(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IMIRE_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_SHIFT           (13U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_MASK            (0x00002000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE(x)              (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_TIMECAPE_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SPPD_SHIFT               (15U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SPPD_MASK                (0x00008000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SPPD(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SPPD_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SPPD_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ISQA_SHIFT               (16U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ISQA_MASK                (0x00030000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ISQA(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ISQA_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ISQA_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ORP_SHIFT                (18U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ORP_MASK                 (0x00040000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ORP(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ORP_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_ORP_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OSGI_SHIFT               (19U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OSGI_MASK                (0x00080000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OSGI(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OSGI_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OSGI_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_HR_SHIFT                 (20U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_HR_MASK                  (0x00F00000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_HR(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_HR_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_HR_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_FA_SHIFT                 (24U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_FA_MASK                  (0x07000000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_FA(x)                    (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_FA_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_FA_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_SHIFT            (27U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_MASK             (0x18000000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE(x)               (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SDUTYPE_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_MSDU_SHIFT               (0U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_MSDU_MASK                (0x0000FFFFUL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_MSDU(x)                  (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_MSDU_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_MSDU_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_SHIFT         (16U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_MASK          (0x007F0000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG(x)            (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_IFMELENCHG_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EPORT_SHIFT              (23U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EPORT_MASK               (0x0F800000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EPORT(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EPORT_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EPORT_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OETEID_SHIFT             (28U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OETEID_MASK              (0x30000000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OETEID(x)                (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OETEID_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_OETEID_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_CTD_SHIFT                (30U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_CTD_MASK                 (0xC0000000UL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_CTD(x)                   (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_CTD_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_CTD_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_SHIFT      (0U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_MASK       (0x00FFFFFFUL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP(x)         (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_EGRESSPORTMAP_MASK)

#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_SHIFT              (0U)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_MASK               (0x0000FFFFUL)
#define NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SIMAP(x)                 (((uint32)(((uint32)(x)) << NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_SHIFT)) & NETC_ETH_IP_INGRESSSTREAMTABLE_CFGE_SIMAP_MASK)



/*!
 * @brief Receive Flow Steering Entry definitions.
 */
#define NETC_ETH_IP_RFS_ENTRY_MODE_FIELD_SHIFT                                   (16U)
#define NETC_ETH_IP_RFS_ENTRY_EN_FIELD_SHIFT                                     (31U)
#define NETC_ETH_IP_RFS_ENTRY_L4PROTMASK_FIELD_SHIFT                             (8U)
#define NETC_ETH_IP_RFS_ENTRY_IPPRESENT_FIELD_SHIFT                              (18U)
#define NETC_ETH_IP_RFS_ENTRY_IPPRESENTMASK_FIELD_SHIFT                          (19U)
#define NETC_ETH_IP_RFS_ENTRY_L4PROTPRESENT_FIELD_SHIFT                          (20U)
#define NETC_ETH_IP_RFS_ENTRY_L4PROTPRESENTMASK_FIELD_SHIFT                      (21U)
#define NETC_ETH_IP_RFS_ENTRY_TCPUDPPRESENT_FIELD_SHIFT                          (22U)
#define NETC_ETH_IP_RFS_ENTRY_TCPUDPPRESENTMASK_FIELD_SHIFT                      (23U)
#define NETC_ETH_IP_RFS_ENTRY_IPV4IPV6_FIELD_SHIFT                               (24U)
#define NETC_ETH_IP_RFS_ENTRY_IPV4IPV6MASK_FIELD_SHIFT                           (25U)
#define NETC_ETH_IP_RFS_ENTRY_UDPTCP_FIELD_SHIFT                                 (26U)
#define NETC_ETH_IP_RFS_ENTRY_UDPTCPMASK_FIELD_SHIFT                             (27U)
#define NETC_ETH_IP_RFS_ENTRY_L4DESTPORTMASK_FIELD_SHIFT                         (16U)
#define NETC_ETH_IP_RFS_ENTRY_L4SRCPORTMASK_FIELD_SHIFT                          (16U)

#define NETC_ETH_IP_64BYTE_TO_FIRST_WORD(x)                                      ((x) & 0x00000000FFFFFFFFULL)
#define NETC_ETH_IP_64BYTE_TO_SECOND_WORD(x)                                     (((x) & 0xFFFFFFFF00000000ULL) >> 32U)

/*! @brief Custom Rx Tag definitions */

/* Position of tag's first byte in a frame */
#define NETC_ETH_IP_RX_CUSTOM_TAG_START_BYTE        (12U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_NUM_BYTES         (6U)

/* Type Field */
#define NETC_ETH_IP_RX_CUSTOM_TAG_TYPE_SHIFT        (4U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_TYPE_MASK         (0xF0U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_TYPE(x)           (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_TYPE_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_TYPE_MASK)

/* Subtype Field */
#define NETC_ETH_IP_RX_CUSTOM_TAG_SUBTYPE_SHIFT     (0U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_SUBTYPE_MASK      (0x0FU)
#define NETC_ETH_IP_RX_CUSTOM_TAG_SUBTYPE(x)        (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_SUBTYPE_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_SUBTYPE_MASK)

/* Drop Resilience Field*/
#define NETC_ETH_IP_RX_CUSTOM_TAG_DR_SHIFT          (6U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_DR_MASK           (0xC0U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_DR(x)             (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_DR_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_DR_MASK)

/* Internal Priority Value Field */
#define NETC_ETH_IP_RX_CUSTOM_TAG_IPV_SHIFT          (2U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_IPV_MASK           (0x3CU)
#define NETC_ETH_IP_RX_CUSTOM_TAG_IPV(x)             (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_IPV_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_IPV_MASK)

/* Source Port Field */
#define NETC_ETH_IP_RX_CUSTOM_TAG_SRCPORT_SHIFT      (3U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_SRCPORT_MASK       (0xF1U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_SRCPORT(x)         (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_SRCPORT_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_SRCPORT_MASK)

/* Source Switch Field */
#define NETC_ETH_IP_RX_CUSTOM_TAG_SRCSWITCH_SHIFT    (0U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_SRCSWITCH_MASK     (0x07U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_SRCSWITCH(x)       (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_SRCSWITCH_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_SRCSWITCH_MASK)

/* Host Reason Field */
#define NETC_ETH_IP_RX_CUSTOM_TAG_HOSTREASON_SHIFT   (4U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_HOSTREASON_MASK    (0xF0U)
#define NETC_ETH_IP_RX_CUSTOM_TAG_HOSTREASON(x)      (((uint8)(((uint8)(x)) << NETC_ETH_IP_RX_CUSTOM_TAG_HOSTREASON_SHIFT)) & NETC_ETH_IP_RX_CUSTOM_TAG_HOSTREASON_MASK)

/*!
 * @brief VSI to PSI messaging definitions.
 */
#if defined(ERR_IPV_NETC_051247)
    #if (STD_ON == ERR_IPV_NETC_051247)

/* Data field position used to store the CRC byte obtained by removing 1 for Class field, 1 for Command field and 1 because of indexing starting with 0 */
#define NETC_ETH_IP_VSI_MSG_CRC_POS     (((uint8)(sizeof(Netc_Eth_Ip_VsiToPsiMsgType)) * (uint8)NETC_ETH_IP_VSITOPSI_MSG_SIZE) - (uint8) (3U))

#endif
#endif




/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/** @brief Controller power state indication.
*   implements Netc_Eth_Ip_PowerStateType_enum */
typedef enum
{
    NETC_ETH_STATE_INACTIVE = 0U, /*!< Controller is powered on and Transmitter/Receiver are disabled */
    NETC_ETH_STATE_ACTIVE   = 1U  /*!< Controller is powered on and Transmitter/Receiver are enabled */
} Netc_Eth_Ip_PowerStateType;

/** @brief Type of the SI. */
typedef enum
{
    NETC_ETH_IP_PHYSICAL_SI = 0U,   /*!< Phyisical SI. */
    NETC_ETH_IP_VIRTUAL_SI  = 1U    /*!< Virtual SI. */
} Netc_Eth_Ip_StationInterfaceType;

/** @brief Ingress congestion management priority. Used for congestion management.
 *  TODO: Not in use.
 */
typedef enum
{
    ICM_LOW_PRIORITY  = 0U,    /*!< ICM low priority */
    ICM_HIGH_PRIORITY = 1U     /*!< ICM high priority */
} Netc_Eth_Ip_ICMType;

/** @brief Return values.
*   implements Netc_Eth_Ip_StatusType_enum */
typedef enum
{
    /* Generic error codes */
    NETC_ETH_IP_STATUS_SUCCESS                 = 0x000U,   /*!< Generic operation success status */
    NETC_ETH_IP_STATUS_ERROR                   = 0x001U,   /*!< Generic operation failure status */
    NETC_ETH_IP_STATUS_TIMEOUT                 = 0x003U,   /*!< Generic operation timeout status */
    NETC_ETH_IP_STATUS_UNSUPPORTED             = 0x004U,   /*!< Generic operation unsupported status. */
    NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND      = 0x005U,   /*!< The current searched MAC address is not used. */
    NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL     = 0x006U,   /*!< Table of MAC address is full. */
    NETC_ETH_IP_STATUS_DELETE_MAC_ADDR         = 0x007U,   /*!< MAC address was removed with success. */
    NETC_ETH_IP_CBDRSTATUS_RINGFULL            = 0x008U,    /*!< Ring is full */
    NETC_ETH_CBDRSTATUS_ACCESSMETHOD_ERROR     = 0x009U,    /*!< Access method error (does not support) */
    NETC_ETH_IP_STATUS_HOSTREASON_UNKNOWN      = 0x100U,
    NETC_ETH_IP_STATUS_HOSTREASON_TIMESTAMP    = 0x101U,

    /*PSI user defined message codes */
    NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL         = 0x8000U, /*!< PSI sent positive response, VSI command executed succesful  */
    NETC_ETH_IP_PSITOVSI_PERMISSION_DENIED     = 0x8001U, /*!< PSI sent negative response - permission denied */
    NETC_ETH_IP_PSITOVSI_SYNC_STATUS_TRUE      = 0x8002U, /*!< PSI sent affirmative response to sync status request */
    NETC_ETH_IP_PSITOVSI_SYNC_STATUS_FALSE     = 0x8003U, /*!< PSI sent negative response to sync status request */
    NETC_ETH_IP_PSITOVSI_MSG_INTEGRITY_ERROR   = 0x8004U, /*!< PSI received erronous data */

    NETC_ETH_IP_STATUS_TX_MANAGEMENT_BUFF_BUSY = 0x904U,   /*!< All internal TX buffers are currently in use */
    /* Specific error codes */
    NETC_ETH_IP_STATUS_RX_QUEUE_EMPTY          = 0xA01U,   /*!< There is no available frame in the receive queue */
    NETC_ETH_IP_STATUS_TX_QUEUE_FULL           = 0xA02U,   /*!< There is no available space for the frame in the transmit queue */
    NETC_ETH_IP_STATUS_BUFF_NOT_FOUND          = 0xA03U,   /*!< The specified buffer was not found in the queue */
    NETC_ETH_IP_STATUS_TX_BUFF_BUSY            = 0xA04U,   /*!< All internal TX buffers are currently in use */
    NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW        = 0xA05U,   /*!< The requested TX buffer length is not supported. */
    NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH    = 0xA06U,   /*!< The length of the frame should be minimum 16 bytes. */
#if(NETC_ETH_IP_HAS_CACHE_MANAGEMENT == STD_ON)
    NETC_ETH_IP_STATUS_CACHE_ERROR             = 0xA07U,   /*!< Cache operation failed. */
#endif
    NETC_ETH_IP_STATUS_NOT_REAL_ERROR          = 0x8AU,     /*!< Error code 0x8A is not a real error. This need to be cover errata */

    /* Time scheduling table error code*/
    NETC_ETH_CBDRSTATUS_UPTATE_EXISTING_ADMIN_GATE_CONTROL     = 0x0D1U,   /* Update action attempted on an existing admin gate control. An existing admin gate control list cannot be modified, Delete admin gate control list first before creating a new admin list. (Use update action with ADMIN_CONTROL_LIST_LENGTH =0 to perform delete). */
    NETC_ETH_CBDRSTATUS_UPDATE_ACTION_EXCEED_MAX_GCL_LEN       = 0x0D2U,   /* Update action attempted exceeds TGSTCAPR[MAX_GCL_LEN]. */
    NETC_ETH_CBDRSTATUS_UPDATE_ACTION_EXCEED_NUM_WORDS         = 0x0D3U,   /* Update action attempted exceeds TGSTCAPR[NUM_WORDS]. */
    NETC_ETH_CBDRSTATUS_INSUFFICIENT_RESOURCES                 = 0x0D4U,   /* Insufficient resources to perform the requested operation (not enough free time gate list entries) */
    NETC_ETH_CBDRSTATUS_TRANSMITTING_TIME_NOT_SUFFICIENT       = 0x0D5U,   /* Update action attempted with ADMIN_CYCLE_TIME, ADMIN_TIME_INTERVAL_GE_i or truncated ADMIN_TIME_INTERVAL_GE_n due ADMIN_CYCLE_TIME specified is not sufficient to transmit 64 byte of frame data + header overhead. Where header overhead = PTXSDUOR[PTXSDUOR] + PTXSDUOR[PPDU_BCO]. */
    NETC_ETH_CBDRSTATUS_ADMIN_BASE_TIME_IS_MORE_THAN_1S        = 0x0D6U,   /* Update action attempted with ADMIN_BASE_TIME specified is more than one second in the past from tcs advance time. */
    NETC_ETH_CBDRSTATUS_ADMIN_CYCLE_TIME_OVERFLOW              = 0x0D7U,   /* Update action attempted with ADMIN_CYCLE_TIME + ADMIN_CYCLE_TIME_EXT is greater than 2^32-1. */
    NETC_ETH_CBDRSTATUS_RETRY_QUERY                            = 0x0D8U,   /* Query action issued when config change occurred. Retry query. */
    NETC_ETH_CBDRSTATUS_INVALID_ADMIN_HR_CB_GE                 = 0x0D9U   /* Update action attempted with ADMIN_HR_CB_GE_i set to an invalid value. */
} Netc_Eth_Ip_StatusType;

/** @brief
*/
typedef enum
{
    /* MAC Address Filtering class statuses */
    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_INVALID_MAC        = 0x0U, /* Invalid MAC address */
    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_DUPLICATE_MAC      = 0x1U, /* Duplicate MAC addr (set primary, add entry) */
    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_MAC_ADDR_NOT_FOUND = 0x2U, /* MAC addr not found (del entry) */
    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_NO_RESOURCE        = 0x3U, /* No resource (not enough exact-match entries available) */
    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_HT_MISMATCH        = 0x4U, /* Not supported: HT size mismatch */

    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_CMD_SUCCESFUL      = 0xFFU, /* Mac Address filtering command succesfully executed. - used with Netc_Eth_Ip_PsiToVsiGenericProtocolStatusType */
    NETC_ETH_IP_PSITOVSI_ADDR_FILTERING_PROTOCOL_PERMISION_DENIED   = 0xFEU  /* Mac Address filtering command execution denied - used with Netc_Eth_Ip_PsiToVsiGenericProtocolStatusType */
}Netc_Eth_Ip_MacAddressFilteringClassProtocolStatusType;

/** @briefs
*/
typedef enum
{
    NETC_ETH_IP_PSITOVSI_PROTOCOL_TIMER_SYNC_STATUS_NOT_SYNCHRONIZED = 0x0U,
    NETC_ETH_IP_PSITOVSI_PROTOCOL_TIMER_SYNC_STATUS_SYNCHRONIZED     = 0x1U
}Netc_Eth_Ip_GetTimerSyncClassProtocolStatusType;

/** @brief Netc_Eth_Ip_PsiToVsiGenericProtocolStatusType
*/
enum
{
    NETC_ETH_IP_PSITOVSI_PROTOCOL_CMD_SUCCESFUL               = 0x01U, /* CMD successful (successfully executed by PSI) */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_PERMISSION_DENIED           = 0x02U, /* Permission denied - command privilege level not met by VF */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_COMMAND_NOT_SUPPORTED       = 0x03U, /* CMD not supported */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_PSI_BUSY                    = 0x04U, /* PSI busy (message queue full or blocked) */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_MSG_INTEGRITY_ERROR         = 0x05U, /* MSG integrity error (CRC error) */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_PROTO_VERSION_NOT_SUPPORTED = 0x06U, /* PROTO version not supported */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_INVALID_MSG_LEN             = 0x07U, /* Invalid MSG LEN */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_CMD_TIMED_OUT               = 0x08U, /* CMD timed out */
    NETC_ETH_IP_PSITOVSI_PROTOCOL_CMD_DEFFERED                = 0x0FU  /* CMD deferred (needs cookie) - async mode only */
};


/** @brief Counters supported by ENETC.
 * implements Netc_Eth_Ip_CounterType_enum */
typedef enum
{
    NETC_ETH_IP_SIROCT = 0x300U,    /*!< Station interface receive octets counter(ifInOctets). All bytes received (without frame errors) by the SI except preamble,
                                    SFD and CRC (if the CRC has been removed from the frame by the MAC). */
    NETC_ETH_IP_SIRFRM = 0x308U,    /*!< Station interface receive frame counter (aFrameReceivedOK). Number of frames received by the SI without errors. */
    NETC_ETH_IP_SIRUCA = 0x310U,    /*!< Station interface receive unicast frame counter (ifInUcastPkts). Number of unicast frames received by the SI without errors. */
    NETC_ETH_IP_SIRMCA = 0x318U,    /*!< Station interface receive multicast frame counter (ifInMulticastPkts). Number of multicast frames received by the SI without errors. */
    NETC_ETH_IP_SITOCT = 0x320U,    /*!< Station interface transmit octets counter (ifOutOctets). All bytes transmitted (without errors) by the SI except preamble,
                                    SFD and CRC (if CRC has been appended to the frame by the MAC). */
    NETC_ETH_IP_SITFRM = 0x328U,    /*!< Station interface transmit frame counter (aFrameTransmittedOK). Number of frames transmitted by the SI without errors with the exception
                                    of frames with error (BD status code point) 0x020 (frame dropped due to port reset) or 0x0A0 (multi-bit ECC error), which will be counted in this counter.*/
    NETC_ETH_IP_SITUCA = 0x330U,    /*!< Station interface transmit unicast frame counter (ifOutUcastPkts). Number of unicast frames transmitted by the SI without errors. */
    NETC_ETH_IP_SITMCA = 0x338U,    /*!< Station interface transmit multicast frame counter (ifOutMulticastPkts). Number of multicast frames transmitted by the SI without errors. */
    NETC_ETH_IP_RBDCR = 0x8180U,    /*!< Rx BDR drop count register. Number of frames dropped due to lack of receive buffer descriptors available. */
} Netc_Eth_Ip_CounterType;

/** @brief VLAN Protocol Identifier, which can be inserted in transmission and are acceptable for VLAN removal in reception.
  * implements     Netc_Eth_Ip_VlanProtocolIdentifierType_enum
 */
typedef enum
{
    NETC_ETH_IP_STANDARD_CVLAN   = 0x00U,       /*!< Standard C-VLAN 0x8100 */
    NETC_ETH_IP_STANDARD_SVLAN   = 0x01U,       /*!< Standard S-VLAN 0x88A8 */
    NETC_ETH_IP_CUSTOM_VLAN1     = 0x02U,       /*!< Custom VLAN as defined by CVLANR1[ETYPE] */
    NETC_ETH_IP_CUSTOM_VLAN2     = 0x03U        /*!< Custom VLAN as defined by CVLANR2[ETYPE] */
} Netc_Eth_Ip_VlanProtocolIdentifierType;

/** @brief Error type returned when transmit status is unsuccessfully.
 * implements Netc_Eth_Ip_TxStatusType_enum */
typedef enum
{
    NETC_ETH_TX_NO_ERR                 = 0x000U, /*!< No error detected after transmit. */
    NETC_ETH_TX_PROGRM_ERR             = 0x001U, /*!< An error exists in either the Tx BD, the Tx ring registers, or some combination of these. */
    NETC_ETH_TX_TSDD                   = 0x002U, /*!< TSDD - Time specific departure drop. */
    NETC_ETH_TX_FRAME_SIZE_ERROR       = 0x008U, /*!< Frame size error - consult the RM to get all possibilities. */
    NETC_ETH_TX_NULL_ADDR              = 0x009U, /*!< Null address */
    NETC_ETH_TX_INVALID_FBC_LENGTH     = 0x00AU, /*!< Invalid frame/buffer/chain length */
    NETC_ETH_TX_MAC_SPOOFING           = 0x010U, /*!< Source MAC address spoofing detected */
    NETC_ETH_TX_FRM_DROP_PORT_RESET    = 0x020U, /*!< Frame dropped due to port reset. */
    NETC_ETH_TX_FRM_DROP_PORT_DISABLE  = 0x021U, /*!< Frame dropped due to port disabled. */
    NETC_ETH_TX_VLAN_TPID_NOTALLOWED   = 0x040U, /*!< VLAN TPID not allowed. */
    NETC_ETH_TX_PROGRM_ERR_IN_BDR      = 0x060U, /*!< Programming error in buffer descriptor used for direct switch enqueue */
    NETC_ETH_TX_FRM_TOO_LARGE          = 0x080U, /*!< Frame too large for time gating window.  */
    NETC_ETH_TX_AXI_READ_ERR           = 0x090U, /*!< Frame not transmitted (dropped) due to an AXI read error detected. */
    NETC_ETH_TX_AXI_WRITE_ERR          = 0x091U, /*!< Frame not transmitted (dropped) due to an AXI write error detected. */
    NETC_ETH_TX_MULTIBIT_ECC_ERR       = 0x0A0U, /*!< Frame not transmitted (dropped) due to a multi-bit ECC error detected. */
    NETC_ETH_TX_PARITY_ERR             = 0x0F0U, /*!< Frame not transmitted (dropped) due to a parity write error detected. */
    NETC_ETH_TX_FRM_DROP_SW_CONGESTION = 0x100U,  /*!< Frame dropped due to switch congestion */
    NETC_ETH_TX_NOT_SENT               = 0xFFFU  /*!< Frame not transmitted yet */
} Netc_Eth_Ip_TxStatusType;

/** @brief Low-level Tx management object status. */
typedef enum
{
    NETC_ETH_IP_TX_MGMT_FREE               = 0x00U, /*!< Object is unused. */
    NETC_ETH_IP_TX_MGMT_PREPARED           = 0x02U, /*!< Object is associated to a management frame ready to be sent. */
    NETC_ETH_IP_TX_MGMT_PREPARED_TIMESTAMP = 0x03U, /*!< Object is associated to a timestamp management frame ready to be sent. */
    NETC_ETH_IP_TX_MGMT_QUEUED             = 0x04U, /*!< Associated management frame is queued, pending confirmation. */
    NETC_ETH_IP_TX_MGMT_QUEUED_TIMESTAMP   = 0x05U, /*!< Associated timestamp frame is queued, pending confirmation. */
    NETC_ETH_IP_TX_MGMT_WAITING_TIMESTAMP  = 0x09U, /*!< Object is associated to a sent frame (confirmed) waiting for a timestamp reply. */
    NETC_ETH_IP_TX_MGMT_READY              = 0x10U  /*!< Associated frame is fully processed and the object is ready to use by higher levels. */
}Netc_Eth_Ip_TxManagementStateType;

/** @brief Error type returned when receive status is unsuccessfully.
* implements Netc_Eth_Ip_RxStatusType_enum */
typedef enum
{
    NETC_ETH_RX_NO_RECEIVE_ERR          = 0x00U, /*!< No error detected. */
    NETC_ETH_RX_FRM_CRC_FAIL            = 0x20U, /*!< Frame CRC (FCS) validation failed. */
    NETC_ETH_RX_L3_CKSUM_FAIL           = 0x40U, /*!< L3 (IPv4) Header Checksum validation failed. */
    NETC_ETH_RX_L4_CKSUM_FAIL           = 0x41U, /*!< L4 (TCP or UDP) Checksum validation failed. */
    NETC_ETH_RX_LGCPARITY_SRAM_MISMATCH = 0x80U, /*!< Internal logic parity or SRAM (ECC) mismatch detected. */
    NETC_ETH_RX_SYSBUS_READ_ERR         = 0x88U, /*!< System Bus Read Error detected during processing of the frame. */
    NETC_ETH_RX_SYSBUS_WRITE_ERR        = 0x89U  /*!< System Bus Write Error detected during processing of the frame. */
} Netc_Eth_Ip_RxStatusType;

/** @brief Shall represent the host reason for a received frame.
 *         Valid only in the first descriptor of a chain.
 * implements Netc_Eth_Ip_HostReasonType_enum */
typedef enum
{
    NETC_ETH_IP_REGULAR_FRAME          = 0U, /* Regular forwarded frame */
    NETC_ETH_IP_INGRESS_MIRRORING      = 1U, /* Ingress mirroring */
    NETC_ETH_IP_MAC_LEARNING           = 2U, /* MAC learning */
    NETC_ETH_IP_TIMESTAMP_RESPONSE     = 3U, /* Timestamp Response */
    NETC_ETH_IP_SW_DEFINED_HOST_REASON = 8U  /* Software defined Host Reason */
} Netc_Eth_Ip_HostReasonType;

/** @brief This flag will indicate the presence of what additional fields in TX descriptor.
 *         Valid only in the first descriptor of a chain.
 */
typedef enum
{
    NETC_ETH_IP_SWT_MANAGEMNT = 0x00U, /*!< Switch management optional fields are present. */
    NETC_ETH_IP_RESERVED_FLAG = 0x01U, /*!< Reserved value of the flag field. */
    NETC_ETH_IP_TXSTART       = 0x02U  /*!< TX_START field is present in the descriptor. */
} Netc_Eth_Ip_TxOptionsFlagType;

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
/** @brief This flag will indicate what offloads are enabled in the TX descriptor.
*/
typedef enum
{
    NETC_ETH_IP_E_FLAGS_NONE               = 0U, /* No extension flags */
    NETC_ETH_IP_E_FLAGS_VLAN_INSERT        = 1U, /* VLAN Insert offload */
    NETC_ETH_IP_E_FLAGS_ONE_STEP_TIMESTAMP = 2U, /* IEEE 1588 PTP one-step timestamp offload */
    NETC_ETH_IP_E_FLAGS_TWO_STEP_TIMESTAMP = 4U  /* IEEE 1588 PTP two-step timestamp offload */
}Netc_Eth_Ip_TxOptionsExtensionFlagType;
#endif

/**
 * @brief Action type which can be done through VSI to PSI messaging.
 *        0x1234 -> first byte(12)  - CLASS
 *               -> second byte(32) - COMMAND
 * @internal
 */
typedef enum
{
    NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET                            = 0x2000U, /*!< VSI sent a set MAC command. */
    NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_HASH_FILTER             = 0x2003U, /*!< VSI sent an add Hash filter for a MAC command. */
    NETC_ETH_IP_VSITOPSI_DELETE_ALL_RX_MAC_ADDR_HASH_FILTER      = 0x2004U, /*!< VSI delete(flush) command to remove all MAC addresses from the hash filter . */
    NETC_ETH_IP_VSITOPSI_DELETE_SINGLE_RX_MAC_ADDR_HASH_FILTER   = 0x2009U, /*!< VSI delete(flush) command to remove a specific MAC address from the hash filter . */

    /*!< VSI command to apply a specific action for Multicast MAC address from the hash filter . */
    NETC_ETH_IP_VSITOPSI_MULTICAST_ACTIONS                       = 0x2005U,
    /*!< VSI sent a request to enable multicast promiscuous mode. */
    NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST_PROMISCUOS             = NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_TYPE_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_TYPE_MC_ONLY_ACTION)  |
                                                                   NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_OP0_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_OP0_NO_FLUSH_ADDRESSES)|
                                                                   NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_OP1_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_OP1_ENABLE_PROMISC)    ,
    /*!< VSI sent a request to disable multicast promiscuous mode. */
    NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST_PROMISCUOUS           = NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_TYPE_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_TYPE_MC_ONLY_ACTION)  |
                                                                   NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_OP0_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_OP0_NO_FLUSH_ADDRESSES)|
                                                                   NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_OP1_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_OP1_DISABLE_PROMISC)   ,
    /*!< VSI sent a request to stop all multicast traffic. */
    NETC_ETH_IP_VSITOPSI_CLOSE_FILTER                            = NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_TYPE_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_TYPE_MC_ONLY_ACTION)|
                                                                   NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_OP0_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_OP0_FLUSH_ADDRESSES) |
                                                                   NETC_ETH_IP_VSITOPSI_PROMISCUOUS_FIELD_OP1_ACTION(NETC_ETH_IP_VSITOPSI_PROMISCUOUS_OP1_DISABLE_PROMISC) ,

    NETC_ETH_IP_VSITOPSI_GET_TIMER_SYNC_STATE                     = 0xE000U  /*!< VSI sent a request for the synchronization state */
} Netc_Eth_Ip_VsiToPsiMsgActionType;

typedef enum {
    NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD = 0U,           /*!< first uint32 item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD,                /*!< second uint32 item of Enetc Tables Request Data Buffer Format when ACCESS_METHOD = 0x0 (ENTRY_ID Match) */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA0,                    /*!< first item of CFGEDATA but third item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA1,                    /*!< second item of CFGEDATA but forth item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA2,                    /*!< third item of CFGEDATA but fifth item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA3,                    /*!< forth item of CFGEDATA but sixth item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA4,                    /*!< fifth item of CFGEDATA but seventh item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA5,                    /*!< sixth item of CFGEDATA but eighth item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA6,                    /*!< seventh item of CFGEDATA but ninth item of Enetc Tables Request Data Buffer Format */
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA7,
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA8,
    NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA9
} Netc_Eth_Ip_EnetcTableRequestDataIndexType;

/*!
 * @brief Query action enum types for tables in Enetc.
 */
typedef enum {
    NETC_ETH_TABLES_FULL_QUERY = 0x0U,               /*!< Full Query */
    NETC_ETH_TABLES_ENTRY_ID_QUERY = 0x1U            /*!< Entry_Id query only */
} Netc_Eth_Ip_TablesQueryActionType;

/*!
 * @brief defines access method type.
 */
typedef enum {
    NETC_ETH_ENTRY_ID_MATCH = 0x0U,                  /*!< if entry id match */
    NETC_ETH_EXACT_MATCH_KEY_ELEMENT_MATCH,          /*!< if exact match key element match */
    NETC_ETH_SEARCH_METHOD,                          /*!< search method */
    NETC_ETH_TERNARY_MATCH_KEY_ELEMENT_MATCH         /*!< if ternary match key element */
} Netc_Eth_Ip_AccessMethodType;

/*!
 * @brief defines commands type.
 *
 */
typedef enum {
    NETC_ETH_DELETE_CMD = 0x1U,                                  /*!< delete command */
    NETC_ETH_UPDATE_CMD = 0x2U,                                  /*!< update command */
    NETC_ETH_QUERY_CMD = 0x4U,                                   /*!< query command*/
    NETC_ETH_QUERY_FOLLOWEDBY_DELETE_CMD = 0x5U,                 /*!< query followed by delete command */
    NETC_ETH_QUERY_FOLLOWEDBY_UPDATE_CMD = 0x6U,                 /*!< query followed by update command */
    NETC_ETH_ADD_CMD = 0x8U,                                     /*!< add a command */
    NETC_ETH_ADD_OR_UPDATE_CMD = 0xAU,                           /*!< add or update a command */
    NETC_ETH_ADD_FOLLOWEDBY_QUERY_CMD = 0xCU,                    /*!< add followed by query command */
    NETC_ETH_ADD_FOLLOWEDBY_QUERY_FOLLOWEDBY_UPDATE_CMD = 0xEU   /*!< add followed by query followed by update command */
} Netc_Eth_Ip_CommandsType;

/*!
 * @brief NTMP request message header format index enum for buffer descriptors of command rings.
 */
typedef enum {
    NETC_ETH_IP_REQHEADER_ADDR_L = 0x0U,            /*!< a 16-byte aligned low part of memory address for a table, offset: 0x0 */
    NETC_ETH_IP_REQHEADER_ADDR_H = 0x1U,            /*!< a 16-byte aligned high part of memory address for a table, offset: 0x1 */
    NETC_ETH_IP_REQHEADER_LENGTHFIELD = 0x2U,       /*!< request and response buffer length in Request Header, offset: 0x2 */
    NETC_ETH_IP_REQHEADER_CONFIGFIELD = 0x3U,       /*!< config field includes Table id, access method, command etc. in Request Header, offset: 0x3 */
    NETC_ETH_IP_REQHEADER_NPFFIELD = 0x7U           /*!< NPF field in Request Header, offsext: 0x7 */
} Netc_Eth_Ip_NTMPReqHeaderFormatIndexType;

/*!
 * @brief NTMP1 command descriptor format index enum for buffer descriptors of command rings.
 */
typedef enum {
    NETC_ETH_IP_CBD_ADDR_L = 0x00U,
    NETC_ETH_IP_CBD_ADDR_H = 0x01U,
    NETC_ETH_IP_CBD_DATA_1 = 0x02U,
    NETC_ETH_IP_CBD_DATA_2 = 0x03U,
    NETC_ETH_IP_CBD_DATA_3 = 0x04U,
    NETC_ETH_IP_CBD_DATA_4 = 0x05U,
    NETC_ETH_IP_CBD_LENGTH_INDEX = 0x06U,
    NETC_ETH_IP_CBD_CMD = 0x07U
} Netc_Eth_Ip_ReqHeaderNTMP1TableOperationDataType;

/*!
 * @brief enum type for administrative gate operation type (as per IEEE 802.1Q-2018) field for gate control list entry.
 * implements     Netc_Eth_Ip_AdminGateOperationType_enum
 */
typedef enum {
    NETC_ETH_HOST_REQUEST_UNCHANGED,          /*!< 0x0: SetGateStates. HoldRequest is unchanged. */
    NETC_ETH_HOST_REQUEST_HOLD,               /*!< 0x1: Set-And-Hold-MAC. HoldRequest is set to value hold (1). */
    NETC_ETH_HOST_REQUEST_RELEASE             /*!< 0x2: Set-And-Release-MAC. HoldRequest is set to value release (0). */
} Netc_Eth_Ip_AdminGateOperationType;

/*!
 * @brief enum type for Administrative Traffic Class Gate States.
 */
typedef enum {
    NETC_ETH_TRAFFIC_CLASS_GATE_CLOSED,       /*!< 0x0: Gate closed. */
    NETC_ETH_TRAFFIC_CLASS_GATE_OPEN          /*!< 0x1: Gate open. */
} Netc_Eth_Ip_AdminTrafficClassGateStateType;

/*!
 * @brief Eth Rate policer Table Service Data Unit enum type.
 */
typedef enum
{
    NETC_ETH_IP_PPDU = 0U,       /*!< Physical Layer PDU */
    NETC_ETH_IP_MPDU = 1U,       /*!< MAC PDU */
    NETC_ETH_IP_MSDU = 2U,       /*!< MAC SDU */
    NETC_ETH_IP_RSDTYPE = 3U     /* reservered type */
}Netc_Eth_Ip_SDUType;

/*!
 * @brief Ingress Port Filter Table CFGE_DATA format enum type. Netc_Eth_Ip_IngressPortFilterTableCFGEDataIndexType
 */
typedef enum {
    NETC_ETH_IP_INGRESSPORTFILTER_CFGE_CONFIG_FIELD = 54U,             /*!< CONFIG field includes IPV, DR, FLTFA etc in Ingress Port Filter Table CFGE_DATA Format */
    NETC_ETH_IP_INGRESSPORTFILTER_CFGE_FLTATGT_FIELD = 55U             /*!< FLTA_TGT (Target For Selected Filter Action) field in Ingress Port Filter Table CFGE_DATA Format */
} Netc_Eth_Ip_IngressPortFilterTableCFGEDataIndexType;

/*!
 * @brief enum type for Filter Forwarding Action field data type of IPF table.
 */
typedef enum {
    NETC_ETH_IPF_DISCARDFRAMES,           /*!< 0x0: discard frames. */
    NETC_ETH_IPF_PERMITFRAMES             /*!< 0x1: permit frames. */
} Netc_Eth_Ip_IPFFilterForwardingActionDataType;

/*!
 * @brief enum type for Filter Action field data type of IPF table.
 */
typedef enum {
    NETC_ETH_IPF_NOACTION,                     /*!< 0x0: no actions. */
    NETC_ETH_IPF_SENDTOSPECIFICSIS = 3U        /*!< 0x3: sending to a specific SIs. */
} Netc_Eth_Ip_IPFFilterActionDataType;


/*!
 * @brief enum type for byte index of a specific field in command message for VSI-to-PSI messaging.
 * Netc_Eth_Ip_VsiToPsiMsgCommandFields
 */
enum
{
    NETC_ETH_IP_VSITOPSI_FIELD_CLASS            = 2U, /* The specific class to which a specific command belongs to. */
    NETC_ETH_IP_VSITOPSI_FIELD_COMMAND          = 3U, /* The specific command associated with the selected class. */
    NETC_ETH_IP_VSITOPSI_FIELD_PROTOCOL_VERSION = 4U, /* Should be 0 for the initial protocol release. To be incremented for future protocol extensions. */
    NETC_ETH_IP_VSITOPSI_FIELD_LENGTH           = 5U, /* Extended message body length in increments of 32B. */
    NETC_ETH_IP_VSITOPSI_FIELD_COOKIE           = 7U, /* Optional parameter, which, if not 0, indicates that the command should be executed asynchronously on PSI side. */
    NETC_ETH_IP_VSITOPSI_FIELD_DATA             = 16U,/* Holds the specific data for each command. */
};

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Callback function invoked when a general event is encountered. */
typedef void (*Netc_Eth_Ip_CallbackType)(uint8 Controller);

/** @brief Signature of the callback function invoked when a specific queue event is encountered */
typedef void (*Netc_Eth_Ip_ChCallbackType)(uint8 Controller, uint8 Ring);

/*!
 * @brief NTMP request and response message header format for buffer descriptors of command rings.
 */
typedef struct {
    uint32 MessageHeaderDataField[8U];                 /*!< used for both request and response message header data format */
} Netc_Eth_Ip_NTMPMessageHeaderFormatType;

/*!
 * @brief NTMP request message header format index enum for buffer descriptors of command rings.
 */
typedef struct {
    uint16 ReqBuffLength;                               /*!< Table Request data buffer length field of NTMP Request Message Header Data Format */
    uint16 RspBuffLength;                               /*!< Table Response data buffer length field of NTMP Request Message Header Data Format */
    uint8 CmdCompletionInt;                             /*!< CCI (Command Completion Interrupt) in config field of Request Message Header Data Format */
    uint8 Version;                                      /*!< Protocol Version in config field of Request Message Header Data Format */
    uint8 TableId;                                      /*!< TABLE_ID in config field of Request Message Header Data Format */
    Netc_Eth_Ip_AccessMethodType AccessMethod;          /*!< ACCESS_METHOD in config field of Request Message Header Data Format */
    Netc_Eth_Ip_CommandsType Cmd;                       /*!< COMMAND in config field of Request Message Header Data Format */
} Netc_Eth_Ip_ReqHeaderTableOperationDataType;

/*!
 * @brief NTMP V1.0 entry set message header format index enum for buffer descriptors of command rings.
 */
typedef struct {
    uint32 Data0;                               /*!<  */
    uint32 Data1;                               /*!<  */
    uint16 SI_Bitmap;                                      /*!<  */
    uint16 Index;                                      /*!<  */
    uint16 Length;                                      /*!<  */
    uint8 Format;                   /*!<  */
    uint8 Class;                             /*!<  */
    uint8 Command;                             /*!<  */
} Netc_Eth_Ip_SetMessageHeaderTableOperationDataType;


/** @brief  Station interface command buffer description. */
typedef struct
{
    Netc_Eth_Ip_NTMPMessageHeaderFormatType  *commandBDAddr; /*!< Address where command buffer descriptor will be saved. The address must be 128 byte aligned. */
    uint8 lengthCBDR;     /*!< Number of command buffer descriptors ring. */
} Netc_Eth_Ip_CommandBDType;

/** @brief Message configuration structure.Should be a multiple of 32 bytes. */
typedef struct
{
    uint16 CRC16;            /*!< Big Endian (BE) format: Standard CRC16 CCITT-FALSE */
    uint8  Class;            /*!< Class of the command. */
    uint8  Command;          /*!< Type of the command. */
    uint8  ProtocolVersion;  /*!< Supported VSI-PSI command protocol version, should be 0 for the initial protocol release.
                                  To be incremented for future protocol extensions. */
    uint8  Length;           /*!< Extended message body length in increments of 32B. The upper limit is given by the physical
                                  implementation of the NETC VSI-PSI Messaging mechanism that supports message sizes of
                                  up to 1024B (including headers), that are multiple of 32B. Length of 0 means that the total message size is 32B.

                                  Observation: If COUNT is greater than 2, then the extended message body has to be used, and LEN must
                                  be set accordingly in the header. */
    uint8  RESERVED_0;
    uint8  Cookie;           /*!< Optional parameter, which, if not 0, indicates that the command should be executed asynchronously on PSI side.
                                  If COOKIE is not 0 and the command cannot be executed instantly on the PSI side (it would take longer time to complete),
                                  the PSI may enqueue the request in a command queue of up to 15 entries per VSI and, later after command execution,
                                  the PSI returns the COOKIE to VSI as part of an asynchronous notification message that indicates the command completion status.
                                  If COOKIE is 0 then the command is considered as blocking, and the PSI will wait for the execution of the command to
                                  complete before updating the PSIMSGRR[MC] field with the corresponding return code.
                                  Rationale: may be required to optimize VSI probe time, or other time critical VSI driver paths, or to avoid possible stalls
                                  or even deadlocks for VSI commands that are executed inside critical sections (i.e. atomic context in Linux). */
    uint8  RESERVED_1[8];
    uint8  Data[16U];        /*!< Message body. */
    /* message extension */
} Netc_Eth_Ip_VsiToPsiMsgType;

#if (0U != NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES)
/** @brief SI multicast MAC filter configuration structure. */
typedef struct
{
    uint8 MulticastMacHashFilter_EID;
    uint8 SiBitmap;
    uint8 MacAddress[6U];
}Netc_Eth_Ip_SiMulticastMACHashFilterDataType;
#endif

/** @brief Transmit buffer descriptor. */
typedef struct
{
    uint32 dataBuffAddr;     /*!< Address where the data for transmit operation is stored. */
    uint32 RESERVED_0;       /*!< UNUSED! Only used for the system with address spaces on 64 bits. */
    uint32 length;           /*!< Length of data buffer(it will be in bytes). */
    uint32 buffConfig;       /*!< Buffer descriptor configuration for a normal descriptor. */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint32 timestamp;            /*!< Timestamp value used to update packet header field on transmission. */
    uint32 extendVlanBuffConfig; /*!< VLAN specific configuration. */
    const uint32 RESERVED_1;     /*!< UNUSED! Not configured by hardware! */
    uint32 extendBuffConfig;     /*!< Buffer descriptor configuration for an extended descriptor. */
#endif
} Netc_Eth_Ip_TxBDRType;

/** @brief Transmit buffer descriptor writeback. */
typedef struct
{
    const uint32 Timestamp;       /*!< Address where the data for transmit operation is stored. */
    const uint16 TxTimestampID;   /*!< UNUSED! Only used for the system with address spaces on 64 bits. */
    const uint16 RESERVED_0;      /*!< UNUSED! */
    const uint32 RESERVED_1;      /*!< UNUSED! */
    const uint16 RESERVED_2;      /*!< UNUSED! */
    const uint16 FlagsAndStatus;  /*!< Buffer descriptor configuration for a normal descriptor. */
} Netc_Eth_Ip_TxBDRWritebackType;


/** @brief Transmit Timestamp Reference Response Buffer Descriptor Format. */
typedef struct
{
    const uint32 Timestamp;          /*!< Timestamp; synchronized timestamp or a free running timestamp */
    const uint32 RESERVED_0;         /*!< UNUSED! */
    const uint16 TxTimestampID;      /*!< Transmit Timestamp Identifier. */
    const uint16 RESERVED_1;         /*!< UNUSED! */
    const uint16 HostReason;         /*!< Host Reason 0: Regular forwarded frame
                                                      1: Ingress mirroring
                                                      2: MAC learning
                                                      3: Timestamp Response
                                                      4-7: Reserved
                                                      8-15: Software defined Host Reason */
    const uint16 FlagsAndErrorStat;  /*!< Final flag + Ready flag + Error status code for the received frame. */
} Netc_Eth_Ip_TxTimestampResponseType;

/**
 * @brief   Transmit internal buffer descriptor.
 * @details The fildes of this stucture are generic.
 *  - at initialization the first 2 words are used to store the location in which the receive frame will be stored;
 *  - after a frame is received information will be conform with the reference manual.
 */
typedef struct
{
    uint32 configRxBD[4]; /*!< Generic configuration of a Rx BDR. */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint32 extendConfigRxBD[4]; /*!< Extended generic configuration of a Rx BDR. */
#endif
} Netc_Eth_Ip_RxBDRType;

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
/**
 * @brief VLAN specific configuration.
 */
typedef struct
{
    Netc_Eth_Ip_VlanProtocolIdentifierType ProtocolIdentifier; /*! Tag protocol identifier. */
    uint8  PriorityCodePoint; /*! Priority code. */
    boolean  DropIndicator;     /*! Indicate frames eligible to be dropped in the presence of congestion. */
    uint16 VlanIdentifier;    /*! The VLAN identifier is a 12-bit field specifying the VLAN to which the frame belongs. */
} Netc_Eth_Ip_VlanType;
#endif

/*!
 * @brief defines Gate Entry Admin Control List Data type for Time Gate Scheduling Table.
 * implements     Netc_Eth_Ip_GateEntryAdminControlListDataType_structure
 */
typedef struct
{
    uint32 AdminTimeInterval;                                           /*!< Administrative Time Interval for Gate Entry */
    uint8 AdminTrafficClassGateStates;                                  /*!< Administrative Traffic Class Gate States for Gate Entry */
    Netc_Eth_Ip_AdminGateOperationType AdminGateOperationType;          /*!< Administrative gate operation type (as per IEEE 802.1Q-2018) field for gate control list entry */
} Netc_Eth_Ip_GateEntryAdminControlListDataType;

/*!
 * @brief defines Time Gate Scheduling Table entries for ENETC.
 *   implements Netc_Eth_Ip_TimeGateSchedulingEntryDataType_structure
 */
typedef struct
{
    uint32 TimeGateSchedulingTable_EID;                 /*!< Time Gate Scheduling Table Entry ID, which is actually the port index of switch */
    uint64 AdminBaseTime;                               /*!< Administrative Base Time */
    uint32 AdminCycleTime;                              /*!< Administrative Cycle Time */
    uint32 AdminCycleTimeExt;                           /*!< Administrative Cycle Time Extension */
    uint16 AdminControlListLength;                      /*!< Administrative Control List Length */
    Netc_Eth_Ip_GateEntryAdminControlListDataType GateEntryAdminControlListData[NETC_ETH_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES];
} Netc_Eth_Ip_TimeGateSchedulingEntryDataType;

/*!
* @brief defines MAC Address Filter Table entries for ENETC.
* @details Structure used to define the attributes of a MAC Filter Table entry.
*/
typedef struct
{
    uint16 MacFilterTable_EID;                     /*!< Mac Filter Table Entry ID */
    uint16 SIBitmap;                                /*!< Bitmap of the SIs for which the filter is used */
    uint8 MacAdress[6];
} Netc_Eth_Ip_MacFilterTableEntryDataType;

/*!
 * @brief defines VLAN Address Filter Table entries for ENETC.
  * implements     Netc_Eth_Ip_VLANFilterTableEntryDataType_structure
 */
typedef struct
{
    uint16 VLANFilterTable_EID;                     /*!< VLAN Filter Table Entry ID */
    uint16 VLANId;                                  /*!< VLAN ID used for filtering */
    Netc_Eth_Ip_VlanProtocolIdentifierType TPID;    /*!< TPID used for filtering */
    uint16 SIBitmap;                                /*!< Bitmap of the SIs for which the filter is used */
} Netc_Eth_Ip_VLANFilterTableEntryDataType;

/**
 * @brief Receive Flow Steering configuration data type.
 * @details Structure used to define the attributes of a RFS entry.
 * implements     Netc_Eth_Ip_RfsEntryType_structure
 */
typedef struct
{
    uint8 RfsTableEntryId;     /*!< RFS Table Entry ID */
    uint8 Enable;               /*!< RFS Entry Enable bit. When set the entry is valid. */
    uint8 Mode;                 /*!< Defines the steering mode: Discard/drop, steer to group or steer to BDR (within an SI). */
    uint8 Result;               /*!< Represents either group or BDR, as defined by Mode attribute. */
    uint8 IpPresent;            /*!< If set, IP header is present */
    uint8 IpPresentMask;        /*!< Mask field programmable for comparison. */
    uint8 L4ProtPresent;        /*!< If set L4 protocol is present. */
    uint8 L4ProtPresentMask;    /*!< Mask field programmable for comparison. */
    uint8 TcpUdpPresent;        /*!< If set TCP header or UDP header is present. */
    uint8 TcpUdpPresentMask;    /*!< Mask field programmable for comparison. */
    uint8 Ipv4Ipv6;             /*!< If set (1) IP addresses are IPV4 addresses, if cleared (0) IP addresses are IPV6 addresses. */
    uint8 Ipv4Ipv6Mask;         /*!< Mask field programmable for comparison. */
    uint8 UdpTcp;               /*!< If set (1) UDP header, if cleared (0) TCP header. */
    uint8 UdpTcpMask;           /*!< Mask field programmable for comparison. */
    uint8 L4ProtocolMask;       /*!< Mask field programmable for comparison. */
    uint8 L4Protocol;           /*!< Indicates which L4 protocol is encapsulated. */
    uint32 L4DestPortMask;      /*!< Mask field programmable for comparison. */
    uint32 L4DestPort;          /*!< Destination port. Defined in network byte order (big-endian). MSB of port nb is stored at LSB offset of this field.*/
    uint32 L4SrcPortMask;       /*!< Mask field programmable for comparison. */
    uint32 L4SrcPort;           /*!< Source port. Defined in network byte order (big-endian). MSB of port nb is stored at LSB offset of this field.*/
    uint64 DestIpAddrMaskLow;   /*!< Mask field programmable for comparison. */
    uint64 DestIpAddrMaskHigh;  /*!< Mask field programmable for comparison. */
    uint64 DestIpAddrLow;       /*!< IPv4/IPv6 destination address. Defined in network byte order (big-endian). MSB of port nb is stored at LSB offset of this field.*/
    uint64 DestIpAddrHigh;      /*!< IPv4/IPv6 destination address. Defined in network byte order (big-endian). MSB of port nb is stored at LSB offset of this field.*/
    uint64 SrcIpAddrMaskLow;    /*!< Mask field programmable for comparison. */
    uint64 SrcIpAddrMaskHigh;   /*!< Mask field programmable for comparison. */
    uint64 SrcIpAddrLow;        /*!< IPv4/IPv6 source address. Defined in network byte order (big-endian). MSB of port nb is stored at LSB offset of this field.*/
    uint64 SrcIpAddrHigh;       /*!< IPv4/IPv6 source address. Defined in network byte order (big-endian). MSB of port nb is stored at LSB offset of this field.*/
} Netc_Eth_Ip_RfsEntryType;

#if (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0)
/*!
 * @brief Eth Rate Policer Table CFGE_DATA Format.
 */
typedef struct {
    uint32 Cfge_Cir;            /*!< Committed Information Rate (CIR) field */
    uint32 Cfge_Cbs;            /*!< Committed Burst SizeExpressed (CBS) field */
    uint32 Cfge_Eir;            /*!< Excess Information Rate (EIR) field */
    uint32 Cfge_Ebs;            /*!< Excess Burst Size (EBS) field */
    boolean Cfge_Mren;          /*!< Mark All Frames Red Enable, 0:disable, 1:enable */
    boolean Cfge_Doy;           /*!< Drop on Yellow, 0:not dropped, 1:dropped */
    boolean Cfge_Cm;            /*!< Color mode, 0:color blind, 1:color aware */
    boolean Cfge_Cf;            /*!< Coupling flag, 0:C and E token buckets are not coupled. 1:C and E token buckets are coupled*/
    boolean Cfge_Ndor;          /*!< No Drop on Red, 0:frames marded "red" are alwayts dropped, 1: not dropped */
    Netc_Eth_Ip_SDUType Cfge_SduType;     /*!< Service Data Unit Type */
} Netc_Eth_Ip_RatePolicerTableCFGEDataType;

/*!
 * @brief Rate Eth Policer Table STSE_DATA Format.
 */
typedef struct {
    uint64 Stse_ByteCount;            /*!< Number of bytes received by the rate policer instance */
    uint32 Stse_DropFrames;           /*!< Number of frames dropped by the rate policer instance */
    uint32 Stse_Dr0GrnFrames;         /*!< Number of frames marked green with DR=0 by the rate policer instance */
    uint32 Stse_Dr1GrnFrames;         /*!< Number of frames marked green with DR=1 by the rate policer instance */
    uint32 Stse_Dr2YlwFrames;         /*!< Number of frames marked yellow with DR=2 by the rate policer instance */
    uint32 Stse_RemarkYlwFrames;      /*!< Number of frames re-marked from green to yellow by the rate policer instance */
    uint32 Stse_Dr3RedFrames;         /*!< Number of frames marked red (DR=3) by the rate policer instance */
    uint32 Stse_RemarkRedFrames;      /*!< Number of frames re-marked from green or yellow to red by the rate policer instance */
    uint32 Stse_Lts;                  /*!< Last timestamp */
    uint32 Stse_CommittedTokenBucketInteger;    /*!< Committed token bucket contents, integer portion */
    uint32 Stse_CommittedTokenBucketFractional; /*!< Committed token bucket contents, fractional portion (31 bits) + sign bit (1 bit, BCS) */
    uint32 Stse_ExcessTokenBucketInteger;       /*!< Excess token bucket contents, integer portion (32 bits)*/
    uint32 Stse_ExcessTokenBucketFranctional;   /*!< Excess token bucket contents, fractional portion (31 bits) + sign bit (1 bit, BES) */
} Netc_Eth_Ip_RatePolicerTableSTSEDataType;

/*!
 * @brief defines Eth Rate Policer entries.
 *
 */
typedef struct
{
    uint32 RatePolicerEntryId;                  /* Entry ID */
    Netc_Eth_Ip_RatePolicerTableCFGEDataType RatePolicerCfgeData;    /* CFGE Data */
    boolean ConfigurationElementUpdate;         /* Update Actions, CFGEU */
    boolean FunctionalEnableElementUpdate;      /* Update Actions, FEEU */
    boolean PolicerStateElementUpdate;          /* Update Actions, PSEU */
    boolean StatisticsElementUpdate;            /* Update Actions, STSEU */
    boolean RatePolicerFunctionEnable;          /* False = The rate policer instance is disabled; True 1b = The rate policer instance is enabled */
} Netc_Eth_Ip_RatePolicerEntryDataType;

/*!
 * @brief defines Eth Rate Policer entry response data.
 *
 */
typedef struct
{
    uint32 RatePolicerEntryId;                  /* Entry ID */
    Netc_Eth_Ip_RatePolicerTableSTSEDataType RatePolicerStseData;    /* Statistics Element Data */
    Netc_Eth_Ip_RatePolicerTableCFGEDataType RatePolicerCfgeData;    /* CFGE Data */
    boolean RatePolicerFunctionEnable;          /* False = The rate policer instance is disabled; True 1b = The rate policer instance is enabled */
    boolean MarkRedFlag;                        /* 0b = Indicates that the rate policer blocking "mark all frames red" function has not been triggered */
                                                /* 1b = Indicates that all frames arriving at this rate policer are marked red by the rate policer blocking "mark all frames red" function. */
} Netc_Eth_Ip_RatePolicerEntryRspDataType;
#endif /* (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0) */

/*!
 * @brief Key Construction Rule
 * @implements : Netc_Eth_Ip_KeyConstructionRuleType_struct
*/
typedef struct
{
    uint32 EthKeyConstructionRegValue;  /**<  Value to be added in the Key Construction Register*/
    uint32 EthPayloadField0RegValue;  /**<  Value to be added in the Payload Field 0 Register*/
    uint32 EthPayloadField1RegValue;  /**<  Value to be added in the Payload Field 0 Register*/
} Netc_Eth_Ip_KeyConstructionRuleType;

/*!
 * @brief Ingress Stream Table CFGE_DATA Format.
 */
typedef struct {
    uint32 RatePolicer_EID;                                         /*!< Rate Policer Entry ID */
    uint32 StreamGateInstance_EID;                                  /*!< Stream Gate Instance Entry ID */
    uint32 IngressStreamCounter_EID;                                /*!< Ingress Stream counter Index */
    uint16 StationInterfaceMap;                                     /*!< Station Interface Map */
    uint16 MaximumServiceDataUnit;                                  /*!< Maximum Service Data Unit */
    Netc_Eth_Ip_SDUType SduType;                                    /*!< Service Data Unit type to use for MSDU (Maximum Service Data Unit) field. */
    Netc_Eth_Ip_EnetcForwardingActionDataType ForwardingActions;    /*!< Forwarding actions */
    uint8 DropResilience;                                           /*!< New Drop Resilience (DR) to be assigned to the frame, if ODR is 1. */
    uint8 InternalPriorityValue;                                    /*!< Internal Priority Value (IPV) */
    boolean OverrideStreamGateInstanceEID;                          /*!< Override Stream Gate Instance Entry ID */
    boolean OverrideRatePolicerInstanceEID;                         /*!< Override Rate Policer (instance) ID. */
    boolean OverrideDR;                                             /*!< Override Drop Resilience (DR) */
    boolean OverrideIPV;                                            /*!< Override Internal Priority Value (IPV) */
    boolean StreamFilteringEnable;                                  /*!< Stream Filtering Enable */
} Netc_Eth_Ip_IngressStreamTableCFGEDataType;

/*!
 * @brief defines Ingress Stream entries.
 *
 */
typedef struct
{
    uint32 IngressStreamEntryId;                  /* Entry ID */
    Netc_Eth_Ip_IngressStreamTableCFGEDataType IngressStreamCfgeData;    /* CFGE Data */
} Netc_Eth_Ip_IngressStreamEntryDataType;

/*!
 * @brief defines Ingress Stream Identification table request/response data type.
 *
 */
typedef struct
{
    uint32 IngrStreamIdenResumeEntryId;                             /* Ingress Stream Identification table Resume Entry ID */
    uint32 IngrStreamIdenEntryId;                                   /* Ingress Stream Identification table Entry ID */
    uint32 IngrStreamEntryId;                                       /* Ingress Stream table Entry ID */
    Netc_Eth_Ip_KeyTypeIdxType Keye_Keytype;                        /* Key type for key construction */
    uint32 Keye_FrmKey[4U];                                         /* Frame portion of the Key */
} Netc_Eth_Ip_IngrStremIdentificationTableDataType;

#if (NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U)
/*!
 * @brief defines Stream Gate Instance entries.
 *
 */
typedef struct
{
    uint32 SGIEntryId;                                      /* Stream Gate Instance Entry ID */
    uint32 AdminSGCLEntryId;                                /* Administrative Stream Gate Control List Entry ID */
    uint64 AdminBaseTime;                                   /* Admin Base Time */
    uint32 AdminCycleTimeExt;                               /* Admin Cycle Time Extension */
    Netc_Eth_Ip_SGITABLE_GateStateType Icfge_Gst;           /* Gate State */
    uint8 Icfge_Ipv;                                        /* Internal Priority Value (IPV) */
    Netc_Eth_Ip_SDUType SduType;                            /* Protocol/Service Data Unit) */
    boolean Icfge_Oipv;                                     /* Override Internal Priority Value (IPV) */
    boolean Cfge_Oexen;                                     /* Octets Exceeded Enable */
    boolean Cfge_Irxen;                                     /* Invalid Receive Enable */
} Netc_Eth_Ip_StreamGateInstanceEntryDataType;

/*!
 * @brief defines Stream Gate Instance entries response data type.
 *
 */
typedef struct
{
    uint32 SGIEntryId;                                      /* Stream Gate Instance Entry ID */
    uint32 OperationalSGCLEntryID;                          /* Operational Stream Gate Control List Entry ID */
    uint64 ConfigChangeTime;                                /* Configuration Change Time */
    uint64 OperationalBaseTime;                             /* Operational Base Time */
    uint32 OperationalCycleTimeExt;                         /* Oper Cycle Time Extension */
    uint8 SGISEOex;                                         /* Octets Exceeded Flag */
    uint8 SGISEIrx;                                         /* Invalid Receive Flag */
    uint8 SGISEState;                                       /* Current Gate Instance State */
    uint32 AdminSGCLEntryId;                                /* Administrative Stream Gate Control List Entry ID */
    uint64 AdminBaseTime;                                   /* Admin Base Time */
    uint32 AdminCycleTimeExt;                               /* Admin Cycle Time Extension */
    Netc_Eth_Ip_SGITABLE_GateStateType Icfge_Gst;           /* Gate State */
    uint8 Icfge_Ipv;                                        /* Internal Priority Value (IPV) */
    Netc_Eth_Ip_SDUType SduType;                            /* Protocol/Service Data Unit) */
    boolean Icfge_Oipv;                                     /* Override Internal Priority Value (IPV) */
    boolean Cfge_Oexen;                                     /* Octets Exceeded Enable */
    boolean Cfge_Irxen;                                     /* Invalid Receive Enable */
} Netc_Eth_Ip_StreamGateInstanceEntryRspDataType;
#endif /* (NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U) */

#if (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U)
/*!
 * @brief defines Stream Gate Control List entries data type.
 */
typedef struct
{
    uint32 SGCL_TimeInterval;                               /* Time Interval for Gate Entry i */
    uint32 SGCL_IntervalOctetsMax;                          /* Interval Octets Maximum for Gate Entry i, */
    uint8 SGCL_Ipv;                                         /* Internal Priority Value for Gate Entry i */
    boolean SGCL_Oipv;                                      /* Override Internal Priority Value for Gate Entry i */
    boolean SGCL_IntervalOctetMaxEnable;                    /* Interval Octet Maximum Enabled for Gate Entry i, */
    Netc_Eth_Ip_SGITABLE_GateStateType SGCL_GateState;   /* Gate State for Gate Entry i, */
} Netc_Eth_Ip_SGCLEntriesDataType;

/*!
 * @brief defines Stream Gate Control List table data type.
 *
 */
typedef struct
{
    uint32 SGCLEntryId;                                     /* Stream Gate Control List Entry ID */
    uint32 Cfge_CycleTime;                                  /* This field specifies the cycle time of the stream gate control list. */
    uint8 Cfge_ListLength;                                  /* This field indicates the number of entries in the stream gate control list. */
    uint8 Cfge_ExtIpv;                                      /* List Extension Internal Priority Value */
    boolean Cfge_ExtOIPV;                                   /* Extension Override Internal Priority Value */
    Netc_Eth_Ip_SGITABLE_GateStateType Cfge_ExtGtst;     /* Extension Gate State */
    Netc_Eth_Ip_SGCLEntriesDataType *ListEntries;        /* Stream Gate Control List entries pointer */
    Netc_Eth_Ip_SGCLTABLE_RefCountType Sgclse_RefCount;  /* Ref count, an element in response data buffer */
} Netc_Eth_Ip_SGCLTableDataType;
#endif /* (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U) */

/*!
 * @brief Request and Response Data Buffer Format of Tables supported by ENETC.
 */
typedef struct {
    uint32 TableDataField[NETC_ETH_IP_TABLEDATA_BUFFER_LENGTH];  /*!< the request and response data buffer share the same memory */
} Netc_Eth_Ip_EnetcTableDataType;

/**
 * @brief   Everything that can be configured by the PSI for itself(also Port) or for the VSIs.
 * @details This structure contains general configuration of the NETC for Ethernet driver.
 * This will affect also every VSI configured aftwareds in other projects. Please, be aware that this will affect all other cotrollers used.
 */
typedef struct
{
    /* General configurations of SI. */
    uint8 siId;          /*< The index of the SI */
    boolean enableSi;    /*< Enable/disable the SI. */
    uint8 NumberOfRxBDR; /*< The number of allowed RX BDR */
    uint8 NumberOfTxBDR; /*< The number of allowed TX BDR */
    uint8 SIBandwidthWeight; /*< SI Bandwidth Weight */
    uint8 numberOfMSIs;  /*< The number of assigned MSIs */
    uint8 VSITCtoTransmitTrafficClass[NETC_ETH_IP_NUMBER_OF_PRIORITIES]; /*< Port station interface a configuration register 1 (PSI1CFGR1 - PSI7CFGR1).
                                                                        The field will not be used for PSI0 */
    /** TODO: other fields from Port station interface 0 configuration register 0 (PSI0CFGR0) */
    /* MAC configurations */
    uint8   primaryMACAddress[6U];  /*< The primary MAC address of the SI. For PSI0 this actually gets written in PMAR0 and PMAR1 */
    /* TODO: Permission to change MAC address Boolean */
    /* TODO: MAC filtering configuration */

    /* VLAN configurations */
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    boolean EnableSIVlan;                 /*! SI-based VLAN information is added on transmit and removed on receive if matched (PSIaVLANR). */
    Netc_Eth_Ip_VlanType SiVLANConfig;              /*!< Vlan configuration for each SI-based */
    boolean EnableSoftwareVlanInsert;               /*!< Enable Software VLAN Insertion (PSICFGR0[SIVIE]) */
    uint8 SIVlanControl;   /*!< Determines which VLAN Ethertypes can be inserted by the SI driver (PSICFGR0[SIVC]) */
    boolean EnableVLANTagExtract; /*!< Controls whether SI-based VLAN tag is removed from the frame before delivery to the SI(PSICFGR0[VTE]) */
#endif
    boolean enableAntiSpoofing;  /*< Enable or disable the Anti-Spoofing */

    /*SI Runtime permissions */
    boolean changeMACAllowed;/* Permission to change VLAN membership Boolean */
    boolean hashFilterUpdateAllowed;/* Permission to update VLAN filtering configuration */
    boolean multicastPromiscuousChangeAllowed; /*Permission to enable Multicast Promiscuos mode */

    /* boolean enableMulticastVLANPromiscuosMode;  Enable or disable the Multicast VLAN Promiscuos Mode */
    /* boolean enableUnicastVLANPromiscuosMode;  Enable or disable the Unicast VLAN Promiscuos Mode */

    boolean enableSIPruning;

} Netc_Eth_Ip_GeneralSIConfigType;
/** @endcond DRIVER_INTERNAL_USE_ONLY */


/** @brief Each enum value will be guarded by a define if this is present on the platform
 * implements     Netc_Eth_Ip_PcieFunction_enum
 */
typedef enum
{
    TIMER = 0U, /* Timer Function */
    EMDIO, /* EMDIO Function */
    SWITCH, /* SWITCH Function */
    ENETC, /* This value can be ONLY given as a parameter to Netc_Eth_Ip_DumpErrorCapture to get the error counters statistics for ENETC module */
    PSI, /* Name according to NETC Reference Manual ENETC PF (SI0)*/
    VSI /* Name according to NETC Reference Manual  ENETC PF (SI+)*/
} Netc_Eth_Ip_PcieFunction;

/** @brief Structure that contain the name of PCIe function and the Error Status corresponding to this function.
 * For the StatusError, the first 3 bits are set based on the following rule:
 * - if a fatal error happened, bit number 0 is set.
 * - if a non fatal error happened, bit number 1 is set.
 * - if a correctable error happened, bit number 2 is set.
 */
typedef struct
{
    Netc_Eth_Ip_PcieFunction Function;
    uint8 StatusErrors;
} Netc_Eth_Ip_PcieFunctionErrorsReported;

/** @brief Signature of the callback function invoked when a specific error event is encountered in PCIE AER
 *
 * First parameter will always be returned as 0, since PSI0 is the only SI responsable with this feature.
 * The second pamameter is a list of fixed size of structures. Each structure has a function name(Netc_Eth_Ip_PcieFunction enum)
 * and a status corresponding to the function.
 * The codification of the status error is:
 * - if a fatal error happened, bit number 0 is set.
 * - if a non fatal error happened, bit number 1 is set.
 * - if a correctable error happened, bit number 2 is set.
*/
typedef void (*Netc_Eth_Ip_PcieAerErrorReportingCallbackType)(const uint8 ctrlIndex, const Netc_Eth_Ip_PcieFunctionErrorsReported *options);

/**
 * @brief Credit based shaper configuration.
 * @note Not supported yet.
 */
typedef struct
{
    /* To improve the speed of the init of the drivers, Bandwidth and hiCredit are calculated in the upper layes */
    boolean EthEgressCBShaperEnable; /*!< Enable the Credit-Based Shaper. */
    uint32 EthEgressCBShaperBandwidth; /*!< Bandwidth of the Credit-Based Shaper. Bandwidth = (idleSlope/portTxRate) * 100, Note: total CBS bandwidth should be less than 75% */
    uint32 EthEgressHiCredit; /*!< HiCredit if the Credit-Based Shaper. (hiCredit on credit) = maxSizedFrame * Bandwidth * (enetClockFrequency / portTxRate) */
    uint32 EthMaxSizedFrame; /*!< Max Frame Size, should be less the 1536 bytes */
} Netc_Eth_Ip_CreditBasedShaperConfigType;

/*!
 * @brief defines Ingress Port Filter Table CFGE_DATA type.
 */
typedef struct
{
    uint32 CfgeTargetForSelectedFilterAction;                                       /*!< FLTA_TGT filed in CFGE_DATA format */
    uint8 CfgeIpv;                                                                  /*!< IPV  (internal priority value) filed in CFGE_DATA format */
    uint8 CfgeDr;                                                                   /*!< DR (drop resilience) field in CFGE_DATA format */
    uint8 CfgeRelativePrecedentResolution;                                          /*!< RPR field in CFGE_DATA format */
    boolean CfgeOverrideIpv;                                                        /*!< OIPV (override internal priority value)  field in CFGE_DATA format*/
    boolean CfgeOverrideDr;                                                         /*!< ODR (override drop resilience) field in CFGE_DATA format */
    boolean CfgeWakeOnLanTriggerEnable;                                             /*!< WOLTE filed in CFGE_DATA format */
    Netc_Eth_Ip_CfgeFilterForwardingActionDataType CfgeFilterForwardingAction;      /*!< FLTFA field in CFGE_DATA format */
    Netc_Eth_Ip_CfgeFilterActionDataType CfgeFilterAction;                          /*!< FLTA field in CFGE_DATA format */
} Netc_Eth_Ip_IngressPortFilterCfgeDataType;

/*!
 * @brief defines Ingress Port Filter Table KEYE_DATA type.
 * implements     Netc_Eth_Ip_IngressPortFilterKeyeDataType_structure
 */
typedef struct
{
    uint16 KeyePrecedence;                                      /*!< Precedence field */
    uint16 keyeFrmAttributeFlags;                               /*!< Frame Attribute Flags field */
    uint16 KeyeFrmAttributeFlagsMask;                           /*!< Frame Attribute Flags Mask field */
    uint8 KeyeDifferentiatedServicesCodePoint;                  /*!< Differentiated Services Code Point field */
    uint8 KeyeDifferentiatedServicesCodePointMask;              /*!< Differentiated Services Code Point Mask field */
    uint16 KeyeOuterVLANTagControlInformation;                  /*!< Outer VLAN Tag Control Information field */
    uint16 KeyeOuterVLANTagControlInformationMask;              /*!< Outer VLAN Tag Control Information Mask field */
    uint8 KeyeDstMacAddr[6U];                                   /*!< Destination MAC Address field */
    uint8 KeyeDstMacAddrMask[6U];                               /*!< Destination MAC Address Mask field */
    uint8 KeyeSrcMacAddr[6U];                                   /*!< Source MAC Address field */
    uint8 KeyeSrcMacAddrMask[6U];                               /*!< Source MAC Address Mask field */
    uint16 KeyeInnerVLANTagControlInformation;                  /*!< Inner VLAN Tag Control Information field */
    uint16 KeyeInnerVLANTagControlInformationMask;              /*!< Inner VLAN Tag Control Information Mask field */
    uint16 KeyeEtherType;                                       /*!< EtherType field */
    uint16 KeyeEtherTypeMask;                                   /*!< EtherType Mask field */
    uint8 KeyeIPProtocol;                                       /*!< IP Protocol field */
    uint8 KeyeIPProtocolMask;                                   /*!< IP Protocol Mask field */
    uint32 KeyeIPSourceAddress[4U];                             /*!< IP Source Address field */
    uint32 KeyeIPSourceAddressMask[4U];                         /*!< IP Source Address Mask field */
    uint16 KeyeL4SourcePort;                                    /*!< L4 Source Port field */
    uint16 KeyeL4SourcePortMask;                                /*!< L4 Source Port Mask field */
    uint32 KeyeIPDestinationAddress[4U];                        /*!< IP Destination Address field */
    uint32 KeyeIPDestinationAddressMask[4U];                    /*!< IP Destination Address Mask field */
    uint16 KeyeL4DestinationPort;                               /*!< L4 Destination Port field */
    uint16 KeyeL4DestinationPortMask;                           /*!< L4 Destination Port Mask field */
    uint8 KeyePayloadBytes[24U];                                /*!< Payload Bytes field */
    uint8 KeyePayloadBytesMask[24U];                            /*!< Payload Bytes Mask field */
} Netc_Eth_Ip_IngressPortFilterKeyeDataType;

/*!
 * @brief defines Ingress Port Filter Table entries.
 * implements     Netc_Eth_Ip_IngressPortFilterEntryDataType_structure
 */
typedef struct
{
    uint32 IngressPortFilterEntryID;                                            /*!< Ingress Port Filter Table Entry ID */
    Netc_Eth_Ip_IngressPortFilterCfgeDataType IngressPortFilterCfgeData;        /*!< Ingress Port Filter Table CFGE_DATA format */
    Netc_Eth_Ip_IngressPortFilterKeyeDataType IngressPortFilterkeyeData;        /*!< Ingress Port Filter Table KEYE_DATA format */
    uint64 IngressPortFilterMatchCount;                                         /*!< Ingress Port Filter Table Match Count Data */
} Netc_Eth_Ip_IngressPortFilterEntryDataType;

/*! @brief Enetc general configuration. To be applied by the PSI for the whole Enetc controller part. */
typedef struct
{
    uint8 numberOfConfiguredSis; /*!< The number of enabled SIs */
    const Netc_Eth_Ip_GeneralSIConfigType (*stationInterfaceGeneralConfig)[FEATURE_NETC_ETH_NUMBER_OF_CTRLS]; /*!< The general configuration for all the enabled SIs */
    volatile Netc_Eth_Ip_VsiToPsiMsgType const *RxVsiMsgCmdToPsi[FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS]; /*!< Array of addresses where PSI will store the receive message from VSI. */
    /* boolean enablePortOuterVlan;              PONVLANR */ /** SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* boolean useNativePortOuterVlan;           PONVLANR - PNE bitfield */ /*! SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* Netc_Eth_Ip_VlanType *portInnerVLANConfig;   TODO: Decide if this will be used at runtime or given in configuration.  */
    /* boolean enableInnerOuterVlan;             PINVLANR */ /*! SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* boolean useNativePortInnerVlan;           PINVLANR - PNE bitfield */ /*! SI-based VLAN information is added on transmit and removed on receive if matched. */
                                                  /* TODO: Decide if this will be used at runtime or given in configuration.  */
    /* Netc_Eth_Ip_VlanType *portOuterVLANConfig;   TODO: Decide if this will be used at runtime or given in configuration.  */
    /* TBD: Port VLAN classification control register (PVCLCTR) */
    /* TBD: Parse configuration (several registers) */
    /* TBD: Port pause configuration */
    /* TBD: Port station interface VLAN filtering mode register (PSIVLANFMR) */
    Netc_Eth_Ip_ICMType priorityToICM[NETC_ETH_IP_NUMBER_OF_PRIORITIES];  /*!< Mapping of internal priority to ICM. Receive IPV to ICM priority mapping register 0 (IPV2ICMPMR0) */
    uint8 priorityToTrafficClass[NETC_ETH_IP_NUMBER_OF_PRIORITIES];     /*!< Mapping of transmit BD rings priority to traffic class. Transmit priority to traffic class mapping register 0 (PRIO2TCMR0) */
    uint8 pcpToIpv[NETC_ETH_IP_NUMBER_OF_PRIORITIES];                     /*!< Mapping of Pcp from VLAN Tag to internal priority. VLAN to IPV mapping profile a register 0 (VLANIPVMP0R0 - VLANIPVMP1R0) */
    /* TBD: VLAN to DR mapping profile a register (VLANDRMP0R - VLANDRMP1R) */
    /* TBD: All the tables */
    uint8 portPPDUByteCountOverhead;    /* PPDU Byte count overhead which includes IPG, SFD and Preamble. */
    uint8 portMACSecByteCountOverhead;  /* Number of bytes of overhead due to MACSec encapsulation */
    uint32 portTimeGateSchedulingAdvanceTimeOffsetReg;  /* This is the port time gate scheduling advance time offset register */
    boolean portTimeAwareShaperEnable;  /*!< If the data for time gate scheduling talbe is configured  */
    uint64 portEgressAdminBaseTime;  /*!< Administrative Base Time */
    uint32 portEgressAdminCycleTime; /*!< Administrative Cycle Time */
    uint32 portEgressAdminCycleTimeExt; /*!< Administrative Cycle Time Extension */
    uint8 numberOfGateControlListEntries; /*!< Number of entries in Administrative Gate Control list. */
    const Netc_Eth_Ip_GateEntryAdminControlListDataType (*TimeGateControlListEntries)[NETC_ETH_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES]; /*!< Pointer to an array containing the gate control list for port. */
#if (NETC_ETH_MAX_NUMBER_OF_IPFTABLE_LIST > 0U)
    uint8 numberOfIPFTableList; /*!< Number of ingress port filter table entries in list. */
    const Netc_Eth_Ip_IngressPortFilterEntryDataType (*IngressPortFilterTableList)[NETC_ETH_MAX_NUMBER_OF_IPFTABLE_LIST]; /*!< Pointer to an array containing the ingress port filter table entries list. */
#endif
    /* ------------ Port configuration ------------- */
    /* TBD: Port configuration register (PCR)   - low priority for basic driver */
    /* TBD: Port TPID acceptance register (PTAR) - low priority for basic driver */
    /* TBD: Port QoS mode register (PQOSMR) - low priority for basic driver */
    /* TBD: Port parser configuration register (PPCR) - low priority for basic driver */
    /* TBD: Port ingress port filter configuration register (PIPFCR) - low priority for basic driver */
    /* TBD: Port stream gate configuration register (PSGCR) - low priority for basic driver */
    /* TBD: A lot of other stream gate and frame preemption settings - low priority for basic driver */
    Netc_Eth_Ip_CreditBasedShaperConfigType (*cbsConfig)[NETC_ETH_IP_NUMBER_OF_PRIORITIES]; /*!< Configuration of each CBS used. */
    const Netc_Eth_Ip_KeyConstructionRuleType (*EthKeyConstruction)[2U];

#if (NETC_ETH_IP_NUMBER_OF_MAC_FILTER_TABLE_ENTRIES > 0)
    uint8 NumberOfMACFilterEntries; /*!< Number of MAC Filter Table entries. */
    const Netc_Eth_Ip_MacFilterTableEntryDataType (*MacTableEntries)[NETC_ETH_IP_NUMBER_OF_MAC_FILTER_TABLE_ENTRIES]; /*!< Pointer to an array containing the configured MAC Filter table entries. */
#endif
#if (NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES > 0)
    uint8 NumberOfVLANFilterEntries; /*!< Number of VLAN Filter Table entries. */
    const Netc_Eth_Ip_VLANFilterTableEntryDataType (*VLANTableEntries)[NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES]; /*!< Pointer to an array containing the configured VLAN Filter table entries. */
#endif
#if (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0)
    uint8 NumberOfRPTableEntries; /*!< Number of Rate Policer Table entries. */
    const Netc_Eth_Ip_RatePolicerEntryDataType (*RPTableEntries)[NETC_ETH_IP_NUMBER_OF_RP_ENTRIES]; /*!< Pointer to an array containing the configured Rate Policer table entries. */
#endif
#if (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U)
    uint8 NumberOfSGCLEntries; /*!< Number of Stream Gate Instance entries */
    const Netc_Eth_Ip_SGCLTableDataType (*StreamGateControlListEntries)[NETC_ETH_NUMBER_OF_SGCL_ENTRIES]; /*!< Pointer to an array containing configurations for Stream Gate Control Lists. */
#endif
#if (NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U)
    uint8 NumberOfSGIEntries; /*!< Number of Stream Gate Instance entries */
    const Netc_Eth_Ip_StreamGateInstanceEntryDataType (*StreamGateInstanceEntries)[NETC_ETH_NUMBER_OF_SGI_ENTRIES]; /*!< Pointer to an array containing configurations for Stream Gate Instances. */
#endif
#if (NETC_ETH_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
    uint8 NumberOfIsiEntries; /*!< Number of Ingress Stream Identification entries. */
    const Netc_Eth_Ip_IngrStremIdentificationTableDataType (*IsiEntries)[NETC_ETH_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES]; /*!< Pointer to an array containing the StreamIdentification configuration. */
#endif
#if (NETC_ETH_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
    uint8 NumberOfIngrStreamEntries; /*!< Number of Ingress Stream entries */
    const Netc_Eth_Ip_IngressStreamEntryDataType (*IngressStreamEntries)[NETC_ETH_NUMBER_OF_INGRESSSTREAM_ENTRIES]; /*!< Pointer to an array containing configurations for Ingress Stream. */
#endif
    uint16 maskMACPromiscuousMulticastEnable; /*!< Enable/Disable promiscuous multicast for all controllers. */
    uint16 maskMACPromiscuousUnicastEnable;   /*!< Enable/Disable promiscuous unicast for all controllers. */

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    uint32 CustomVlanEthertype1;              /*!< Configure for custom VLAN Ethertype 1 register (CVLANR1). */
    uint32 CustomVlanEthertype2;              /*!< Configure for custom VLAN Ethertype 1 register (CVLANR2). */
    uint16 maskMACVLANPromiscuousEnable;      /*!< Enable/Disable promiscuous VLAN for all controllers. */
    uint32 maskVLANAllowUntaggedEnable;       /*!< Enable/Disable permssion of the SI to receive untagged traffic
                                                   while the VLAN support is enabled for ENTC0. */
#endif
    uint8 rxCheckSumOffloadingTCPUDP;         /*!< Enable/Disable Rx Checksum offload for TCP/UDP. */
    uint8 rxCheckSumOffloadingIPV4;           /*!< Enable/Disable Rx Checksum offload for IPV4. */
    /** TODO: other fields from Port station interface 0 configuration register 0 (PSI0CFGR0) */

    boolean enableUncorrectableErrors;  /* Enable or disable the Uncorrectable Errors a PCIE level for all functions (SWITCH, ENETC, EMDIO, TIMER, PSI0, VSIx) */
    boolean enableCorrectableErrors;    /* Enable or disable the Correctable Errors a PCIE level for all functions (SWITCH, ENETC, EMDIO, TIMER, PSI0, VSIx) */
    uint8 errorReportigSingleECCErrorsThreshold; /* The number of Single bit EC Errors which will trigger the Error Reporting error. This threshold is set for all the functions */
    uint8 errorReportingMultiBitECCErrorsThreshold; /* The number of Multi bit ECC errors which will trigger the Error Reporting error. This threshold is set for all the functions */
    uint8 errorReportigIntegrityErrorsThreshold; /* The number of Integrity Errors which will trigger the Error Reporting error. This threshold is set for all the functions */
    uint8 errorReportingSystemBusErrorsThreshold; /* The number of System Bus Errors which will trigger the Error Reporting error. This threshold is set for all the functions */
    Netc_Eth_Ip_PcieAerErrorReportingCallbackType errorReportingCallback;
#if ((STD_ON == NETC_ETH_IP_EXTENDED_BUFF) && (STD_ON == NETC_ETH_IP_CUSTOM_TAG_SUPPORT))
    uint16 CustomTPID;
    uint8 CustomIPV;
    uint8 CustomDR;
#endif
    uint8 defaultIPV;                          /*!< PQOSMR[DDR] - set the default value of Drop Resilience which is used in following cases:
                                                    1. enableVlanToIpvMapping is disabled.
                                                    2. enableVlanToIpvMapping is enabled, but the incoming frame is not VLAN tagged. */
    uint8 defaultDR;                           /*!< PQOSMR[DIPV] - set the default value of Drop Resilience which is used in following cases:
                                                    1. enableVlanToIpvMapping is disabled.
                                                    2. enableVlanToIpvMapping is enabled, but the incoming frame is not VLAN tagged. */
#if(STD_ON == NETC_ETH_IP_MANAGEMENT_SUPPORT_API)
    uint8 ManagementIPV;
#endif
} Netc_Eth_Ip_EnetcGeneralConfigType;

/** @brief The station interface configuration. This applies to all SIs either PSI or VSI. */
typedef struct
{
    boolean enableVlanToIpvMapping;            /*!< V2IPVE - enables the mapping of PCP+DEI to IPV for each SI. */
    boolean discardBroadcastFrames;            /*!< RNBM - enables or disables discarding all broadcast frames */
    boolean discardMulticastFrames;            /*!< RNMM - enables or disables discarding all multicast frames */
    boolean discardUnicastFrames;              /*!< RNUM - enables or disables discarding all unicast frames */
    uint8 vlanToIpv[16U];                      /*!< Station interface VLAN to IPV mapping register 0 (SIVLANIPVMR0). PCP+DEI mapping to IPV */
    uint8 ipvToBDR[8U];                        /*!< Station interface IPV to ring mapping register (SIIPVBDRMR0). Mapping of IPV to BDR */
    uint8 NumberOfRxBDR;                       /*!< The number of configured RX BDR */
    uint8 NumberOfTxBDR;                       /*!< The number of configured TX BDR */
    Netc_Eth_Ip_CommandBDType commandBDConfig; /*!< This will store the configuration of the command BDR. */
    volatile Netc_Eth_Ip_VsiToPsiMsgType *VSItoPSIMsgCommand; /*!< Address of the command message sent from VSI to PSI. */
    uint8 CtrlLogicalIndex;                    /*!< This member keep the value of controller index for the callback function. */

    uint32 *txMruMailboxAddr;              /*!< Mailbox address for TX. */
    uint32 *rxMruMailboxAddr;              /*!< Mailbox address for RX. */
    uint32 *siMsgMruMailboxAddr;           /*!< Mailbox address for VSI to PSI messaging. */
    boolean EnableSIMsgInterrupt;          /*!< Interrupt SI support messaging enable. */

#if (0U != NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES)
    uint8 NumberOfConfiguredMulticastMacHashFilterEntries; /*< Number of Multicast Mac Hash filter entries */
    const Netc_Eth_Ip_SiMulticastMACHashFilterDataType (*MulticastMACFilterEntries)[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES]; /*< Pointer to an array containing the configured Multicast MAC Hash Filter entries. */
#endif

    uint32 RxInterrupts;                   /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
    uint32 TxInterrupts;                   /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
} Netc_Eth_Ip_StationInterfaceConfigType;

/** @brief Specialization of ring configuration for Tx Rings. */
typedef struct
{
    Netc_Eth_Ip_TxBDRType *RingDesc;     /*!< Buffer descriptor ring start address. */
    Netc_Eth_Ip_ChCallbackType Callback; /*!< Callback function for current channel. */
    uint8 *Buffer;                       /*!< Buffer data pool start address */
    uint16 ringSize;                     /*!< Number of buffers descriptors for the current ring. */
    uint16 maxRingSize;                  /*!< The maximum number of descriptors for the current ring between all variants.
                                              It is used for AUTOSAR specification. */
    uint16 bufferLen;                    /*!< Length of each individual buffer in a pool. */
    uint16 maxBuffLen;                   /*!< Maximum buffer size length supported by a transmit buffer for curent ring.
                                              This member is variant aware, it is used for AUTOSAR specification. */
    uint8 Weight;                        /*!< Weight value. (0 to 7) */
    uint8 Priority;                      /*!< Priority. 0 is lowest, 7 is highest */
    uint32 TimerThreshold;               /*!< Timer threshold, specified in units of NETC clock cycles.
                                              This value determines the maximum amount of
                                              time allowed between a first transmitted packet until the TBaICR0[ICPT]
                                              (no. of packets) threshold is reached. */
    uint8 PacketsThreshold;              /*!< This value determines the minimum number of packets transmitted before
                                              raising an interrupt. 2^(PacketsThreshold-1) packets*/
} Netc_Eth_Ip_TxRingConfigType;

/** @brief RX ring configuration */
typedef struct
{
    Netc_Eth_Ip_RxBDRType      *RingDesc; /*!< Buffer descriptor ring start address. */
    Netc_Eth_Ip_ChCallbackType Callback;  /*!< Callback function for current channel. */
    uint8 *Buffer;                        /*!< Buffer data pool start address */
    uint16 ringSize;                      /*!< Number of buffers descriptors for the current ring. */
    uint16 maxRingSize;                   /*!< The maximum number of descriptors for the current ring between all variants.
                                               It is used for AUTOSAR specification. */
    uint16 bufferLen;                     /*!< Length of each individual buffer in a pool */
    uint16 maxBuffLen;                    /*!< Maximum buffer size length supported by a receive buffer for curent ring.
                                               This member is variant aware, it is used for AUTOSAR specification. */
    uint32 TimerThreshold;               /*!< Timer threshold, specified in units of NETC clock cycles.
                                             This value determines the maximum amount of
                                             time allowed between a first received packet until RBaICR0[ICPT] (no. of packets)
                                             threshold is reached. */
    uint16 PacketsThreshold;              /*!< This value determines the minimum number of packets received before
                                              raising an interrupt. 1 -> 16384*/
} Netc_Eth_Ip_RxRingConfigType;

/**
 * @cond DRIVER_INTERNAL_USE_ONLY
 * @brief Internal driver state structure
 */
typedef struct
{
    const Netc_Eth_Ip_EnetcGeneralConfigType     *generalConfig;  /*!< ENETC Base Register configuration. Only used for PSI, NULL_PTR for VSI. */
    uint8 CtrlLogicalIndex;                    /*!< This member keep the value of controller index for the callback function. */
    Netc_Eth_Ip_CallbackType Callback;                      /*!< Callback function for general interrupts. */
    /* --------------------- RX ------------------- */
    Netc_Eth_Ip_ChCallbackType RxCallback[FEATURE_NETC_RX_BDR_COUNT]; /*!< Callback function for current Rx channel. */
    /** TODO: Make the value store in this pointer array a const, if there is any possibility. */
    Netc_Eth_Ip_RxBDRType *FirstRxRingDescAddr[FEATURE_NETC_RX_BDR_COUNT]; /*!< Array with starting address of each ring of descriptors for a SI. */
    Netc_Eth_Ip_RxBDRType *RxCurrentDesc[FEATURE_NETC_RX_BDR_COUNT];            /*!< The current available receive buffer descriptor pointer array. */
    uint8  *FirstRxDataBufferAddr[FEATURE_NETC_RX_BDR_COUNT];                   /*!< Array with starting address of each data buffer used to store RX data by ring. */
    uint16 RxRingSize[FEATURE_NETC_RX_BDR_COUNT];
    uint16 rxCurrentIndex[FEATURE_NETC_RX_BDR_COUNT];                           /*!< Index of the current decriptor in ring. */
    uint16 RxDataBuffMaxLenAddr[FEATURE_NETC_RX_BDR_COUNT];
    uint16 LogicRxConsumerIndex[FEATURE_NETC_RX_BDR_COUNT];                     /*!< Store reception consumer index for each ring. */

    /* --------------------- TX ------------------- */
    Netc_Eth_Ip_ChCallbackType TxCallback[FEATURE_NETC_TX_BDR_COUNT]; /*!< Callback function for current Tx channel. */
    uint16 LogicTxProducerIndex[FEATURE_NETC_TX_BDR_COUNT]; /*!< Store transmission producer index for each ring. */
    boolean LockTxBuffDescr[FEATURE_NETC_TX_BDR_COUNT][NETC_ETH_MAX_NUMBER_OF_TXBD]; /*!< This flag will show the state of the data buffer ready(= FALSE)/busy(= TRUE). */
    uint32  lastTxDataBuffAddrIdx[FEATURE_NETC_TX_BDR_COUNT];                        /*!< Last buffer address status checked. */
    uint8   *TxDataBuffAddr[FEATURE_NETC_TX_BDR_COUNT][NETC_ETH_MAX_NUMBER_OF_TXBD]; /*!< Store address of the transmitted buffer for each descriptor. */
    uint16 TxRingSize[FEATURE_NETC_TX_BDR_COUNT];                           /*!< Number of buffers descriptors for the current ring. */
    uint16 TxBufferLength[FEATURE_NETC_TX_BDR_COUNT];                       /*!< Length of each individual buffer in a pool. */
    Netc_Eth_Ip_TxBDRType *FirstTxRingDescAddr[FEATURE_NETC_TX_BDR_COUNT];  /*!< Buffer descriptor ring start address. */
    uint8 *FirstTxDataBufferAddr[FEATURE_NETC_TX_BDR_COUNT];                /*!< Array with starting address of each data buffer used to store TX data by ring. */
    uint16 TxDataBuffMaxLenAddr[FEATURE_NETC_TX_BDR_COUNT];                 /*!<  */

    volatile Netc_Eth_Ip_VsiToPsiMsgType *VSItoPSIMsgCommand;                   /*!< The VSI command sends to PSI. */
    uint8 NumberOfRxBDR;                       /*!< The number of configured RX BDR */
    uint8 NumberOfTxBDR;                       /*!< The number of configured TX BDR */
    Netc_Eth_Ip_StationInterfaceType SiType;          /*!< The type of the SI (PSI or VSI). */

    const Netc_Eth_Ip_GeneralSIConfigType (*SIGeneralConfig)[FEATURE_NETC_ETH_NUMBER_OF_CTRLS]; /*!< SI Runtime permissions. Valid only for PSI, NULL_PTR for VSI  */

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    uint32   *RxDataBuffAddr;                                         /*!< Store address of the received external buffer for each descriptor. */
#endif
    uint32 TxTimerThreshold[FEATURE_NETC_TX_BDR_COUNT];               /*!< Timer threshold, specified in units of NETC clock cycles.
                                              This value determines the maximum amount of
                                              time allowed between a first transmitted packet until the TBaICR0[ICPT]
                                              (no. of packets) threshold is reached. */
    uint8 TxPacketsThreshold[FEATURE_NETC_TX_BDR_COUNT];              /*!< This value determines the minimum number of packets transmitted before
                                              raising an interrupt. 2^(PacketsThreshold-1) packets*/
    uint32 RxTimerThreshold[FEATURE_NETC_RX_BDR_COUNT];               /*!< Timer threshold, specified in units of NETC clock cycles.
                                              This value determines the maximum amount of
                                              time allowed between a first transmitted packet until the TBaICR0[ICPT]
                                              (no. of packets) threshold is reached. */
    uint16 RxPacketsThreshold[FEATURE_NETC_RX_BDR_COUNT];              /*!< This value determines the minimum number of packets received before raising an interrupt. */
    uint32 RxInterrupts;                    /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
    uint32 TxInterrupts;                    /*!< Channel interrupt sources. A logical OR of "Netc_Eth_Ip_ChInterruptType". */
    Netc_Eth_Ip_CommandBDType EnetcCommandBDConfig; /*!< This will store the configuration of the command BDR. */
    boolean PcieAerUncorrectableErrEnabled; /*!< Uncorrectable error reporting enabled/disabled. */
    boolean PcieAerCorrectableErrEnabled;   /*!< Correctable error reporting enabled/disabled. */
    Netc_Eth_Ip_PcieAerErrorReportingCallbackType PcieAerErrorReportingCallback;
#if (0U != NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES)
    uint8 NumberOfConfiguredMulticastMacHashFilterEntries; /*< Number of Multicast Mac Hash filter entries */
    const Netc_Eth_Ip_SiMulticastMACHashFilterDataType (*MulticastMACFilterEntries)[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES]; /*< Pointer to an array containing the configured Multicast MAC Hash Filter entries. */
#endif
#if(STD_ON == NETC_ETH_IP_MANAGEMENT_SUPPORT_API)
    uint8 ManagementIPV;
#endif
} Netc_Eth_Ip_StateType;
/** @endcond DRIVER_INTERNAL_USE_ONLY */

/**
 * @brief Controller configuration for a SI from ENETC.
 * @details This will be used for Netc_Eth_Init. The SI type will generate the specific configuration.
 */
typedef struct
{
    Netc_Eth_Ip_StationInterfaceType             SiType;          /*!< The type of the SI (PSI or VSI). */
    const Netc_Eth_Ip_EnetcGeneralConfigType     *generalConfig;  /*!< ENETC Base Register configuration. Only used for PSI, NULL_PTR for VSI. */
    const Netc_Eth_Ip_StationInterfaceConfigType *siConfig;       /*!< ENETC Station Interface Register configuration. */
    Netc_Eth_Ip_StateType                        *stateStructure; /*!< State structure for current controller. */
    const Netc_Eth_Ip_RxRingConfigType           (*paCtrlRxRingConfig)[]; /*!< Address of the array where RX rings are configured. */
    const Netc_Eth_Ip_TxRingConfigType           (*paCtrlTxRingConfig)[]; /*!< Address of the array where TX rings are configured. */
    uint32 netcClockFrequency;  /*!< Netc system clock */
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    uint32 *rxExternalBuffersAddr;                                  /*!< Array that will keep the addresses of the external rx buffers. */
#endif
    uint32 RfsEntriesNb; /*!< Number of Receive Flow Steering Table entries */
    const Netc_Eth_Ip_RfsEntryType (*RfsConfigTable)[]; /*!< Receive Flow Steering configuration table pointer. */
} Netc_Eth_Ip_ConfigType;

/*!
 * @brief User buffer type.
 * @implements Netc_Eth_Ip_BufferType_structure
 */
typedef struct
{
    uint8  *data;   /*!< Pointer to data buffer */
    uint16 length;  /*!< Length of the data buffer */
} Netc_Eth_Ip_BufferType;

/*!
 * @brief Defines the timestamp.
 * @implements Netc_Eth_Ip_TimestampType_structure
 */
typedef struct
{
    uint32 nanoseconds;  /*!< Nanoseconds part of the time. */
    uint32 seconds;      /*!< The 32 least significant bits of the 48 bits seconds part of the time. */
    uint16 secondsHi;    /*!< The 16 most significant bits of the 48 bit seconds part of the time. */
} Netc_Eth_Ip_TimestampType;

/** @brief Transmit options for a particular frame. */
typedef struct
{
    Netc_Eth_Ip_TxOptionsFlagType Flag;                     /*!< This option will set the usage of the additional fields. */
    uint8 SwtMgSendingOpt;                                  /*!< Select between: 0 - Switch Port Masquerading
                                                                 1 - Direct Switch Enqueue */
    uint8 TimestampRefReq;                                  /*!< Valid when SwtMgSendingOpt = 1. Request to capture the timestamp
                                                                 when the frame's SFD is transmitted by the switch's Ethernet MAC. */
    uint8 IngrOrEgrPortNumber;                              /*!< Ingress or Egress switch port number this frame is to be injected towards.
                                                                 Ingress - SwtMgSendingOpt = 0; Egress - SwtMgSendingOpt = 1 */
    uint8 InternalPriority;                                 /*!< Used to determine switch egress queue and buffer pool. SwtMgSendingOpt = 1 */
    uint8 DiscardResilience;                                /*!< This field is used for congestion management handling within the switch. */
    uint8 TxStartEnable;                                    /*!< Transmit start enable */
    uint32 TxStartTime;                                     /*!< Transmit start time */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint8 PriorityCodePoint;                                /*!< Contains the PCP value of the VLAN tag to be inserted in the packet during transmission. */
    uint8 DropEligible;                                     /*!< Contains the DEI value of the VLAN tag to be inserted in the packet during transmission. */
    Netc_Eth_Ip_TxOptionsExtensionFlagType ExtensionFlags;  /*!< Indicates what offloads are enabled for this frame. */
    uint8 TagProtocolID;                                    /*!< Contains the TPID of the VLAN tag to be inserted in the packet during transmission. */
    uint16 VlanID;                                          /*!< Identifier of the VLAN tag to be inserted in the packet during transmission. */
    uint32 Timestamp;                                       /*!< Timestamp value used to update packet header field on transmission. */
#endif
} Netc_Eth_Ip_TxOptionsType;

/*!
 * @brief Detailed status of a transmit buffer descriptor.
 * TODO: Update when VLAN info will be added.
 * @implements Netc_Eth_Ip_TxInfoType_structure
 */
typedef struct
{
    Netc_Eth_Ip_TimestampType timestamp;  /*!< The timestamp of the transmitted packet. */
    Netc_Eth_Ip_TxStatusType  txStatus;   /*!< Error status in the descriptor to be transmitted. */
} Netc_Eth_Ip_TxInfoType;

/*!
 * @brief Structure to store detailed status of a receive buffer descriptor.
 * TODO: Update when VLAN info will be added.
 * @implements Netc_Eth_Ip_RxInfoType_structure
 */
typedef struct
{
    Netc_Eth_Ip_RxStatusType     rxStatus;          /*!< The error code in case of frame not received correct.*/
    boolean                      L4cksum;           /*!< L4 (TCP or UDP) Checksum was validated and found to be correct. */
    boolean                      L3cksum;           /*!< L3 (IPv4) Header Checksum was validated and found to be correct. */
    boolean                      timestampReceived; /*!< Timestamp received */
    boolean                      vlanHeaderAvl;     /*!< VLAN header extracted */
    uint16                       pktLen;            /*!< Length of the received packet. */
    Netc_Eth_Ip_HostReasonType   hostReason;        /*!< Host Reason.*/
    boolean                      finalDes;          /*!< Determines the last buffer descriptor in a chain.*/
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    Netc_Eth_Ip_VlanType         VlanInfo;          /*!< Informations of VLAN frames.*/
#endif
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    Netc_Eth_Ip_TimestampType    PacketTimestamp;   /*!< The timestamp of the received packet. */
#endif
} Netc_Eth_Ip_RxInfoType;

/** @brief MSI(message interrupt) table type. */
typedef struct
{
    /* this type of structure is saved in NETC device memory which not supports burst writes and it will rise a bus hardfault in that case
     * volatile was added because otherwise compiler optimize writes on memory */
    volatile uint32 *msgAddr;      /*!< Address of the mailbox. */
    volatile uint32 RESERVED_0;    /*!< NOT USED. */
    volatile uint32 msgData;       /*!< Data transmitted by the interrupt event. */
    volatile uint32 controlVector; /*!< */
} Netc_Eth_Ip_MSITableEntry;

/** @brief MSI table for each SI. */
typedef struct
{
    Netc_Eth_Ip_MSITableEntry msiTable[3U]; /*!< Array with all entries in table. */
} Netc_Eth_Ip_MSITable;

#if (NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES > 0)
/** @brief Entry type for MAC filter hash table. */
typedef struct
{
    boolean EntryStatus; /*!< Status of the entry. TRUE - entry in use; FALSE - entry not used yet or deleted. */
    uint8   HashValue;   /*!< Hash value for the MAC address. */
    uint8   MACAddr[6U]; /*!< MAC address. */
} Netc_Eth_Ip_MACFilterHashTableEntryType;
#endif /* (NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES > 0) */

/** @brief Store the counter values for time. */
typedef struct
{
    uint32 nanosecondsL;    /*!< Nanoseconds low part of the time. */
    uint32 nanosecondsH;    /*!< Nanoseconds high part of the time. */
} Netc_Eth_Ip_TimeType;

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
/** @brief Management information.
  * implements     Netc_Eth_Ip_TxManagementInfoType_structure  */
typedef struct
{
    Netc_Eth_Ip_TxManagementStateType State;
    uint8   CtrlIdx;
    uint8   SwitchIndex;
    uint8   PortIndex;
    uint16  TxTimeStampID;
    uint16  TxBuffId;
} Netc_Eth_Ip_TxManagementInfoType;

/** @brief Timestamp information.
  * implements     Netc_Eth_Ip_TxTimestampInfoType_structure */
typedef struct
{
    uint8   CtrlIdx;
    uint8   SwitchIndex;
    uint8   PortIndex;
    uint16  TxTimeStampID;
    Netc_Eth_Ip_TimeType   TimestampValue;
} Netc_Eth_Ip_TxTimestampInfoType;


#endif /* NETC_ETH_0_USED */

/** @brief Timestamp received frame information.
 * implements     Netc_Eth_Ip_RxTimestampInfoType_structure */
typedef struct
{
    uint8                RingIdx;
    uint8               *ReceivedDataPtr;
    uint8                SourcePort;
    boolean              TimestampValueInvalidForSwt;  /*!< Mark if the current timestamp is invalid. */
    uint32               TimestampID;                  /*!< This represents a uniq ID inside a Netc_Eth_Ip_RxTimestampInfo buffer. */
    Netc_Eth_Ip_TimeType TimestampValue;
} Netc_Eth_Ip_RxTimestampInfoType;

#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/**
 * @brief Structure that maps exactly on the upper layer structure Eth_43_NETC_axTxBufferIdxMapType.
 * It is used as in/out parameter for the Netc_Eth_Ip_GetMultipleTxFramesStatus in the HLD driver flow
 * to retrieve the transmission status for multiple frames.
 * Find a solution to use this API on IP driver as well. Right now for IP driver this structure is not useful.
 */
typedef struct Netc_Eth_Ip_axTxBufferIdxMapType
{
    uint8 FifoIdx;
    uint8* pu8BufferData;
    boolean bTxConfirmation;
    Netc_Eth_Ip_TxStatusType FrameHasError;
    struct Netc_Eth_Ip_axTxBufferIdxMapType *pNextBuffer;
} Netc_Eth_Ip_axTxBufferIdxMapType;

/* implements     Netc_Eth_Ip_ErrorCaptureRegLabel_enum */
typedef enum
{
    NETC_NONE,          /* Default unassigned value */
    SIUPESR,            /* This is the uncorrectable programming error status register.*/
    SIUPECTR,           /* This is the uncorrectable programming error count register which tracks how many received frames have been dropped by the station interface.*/
    CMESR,              /* This is the correctable memory error status register.*/
    SICMESR,            /* This is the correctable memory error status register.*/
    UNSBESR,            /* This is the uncorrectable non-fatal system bus error status register.*/
    UNSBECTR,           /* This is the uncorrectable non-fatal system bus error count register which tracks how many events have been detected.*/
    SIUNSBESR,          /* This is the uncorrectable non-fatal system bus error status register.*/
    SIUNSBECTR,         /* This is the uncorrectable non-fatal system bus error count register which tracks how many events have been detected.*/
    TBCIR,              /* Frame BD prefetching for the station interface ring is stalled. The frame BD consumer index will indicate the last successfully updated BD.*/
    PM0_RERR,           /* MAC Receive Frame Error Counter Register(ifInErrorsn)*/
    PM1_RERR,           /* MAC Receive Frame Error Counter Register(ifInErrorsn)*/
    PM0_EVENT,
    PM1_EVENT,
    MAC_MERGE_MMFSECR0, /* A count of received MAC frames / MAC frame fragments rejected due to unknown SMD value or arriving with an SMD-C when no frame is in progress*/
    MAC_MERGE_MMFSECR1, /* A count of received MAC frames / MAC frame fragments rejected due to unknown SMD value or arriving with an SMD-C when no frame is in progress*/
    MAC_MERGE_MMFAECR0, /* A count of MAC frames with reassembly errors.*/
    MAC_MERGE_MMFAECR1, /* A count of MAC frames with reassembly errors.*/
    UNMESR0,            /* This is the uncorrectable non-fatal memory error status register 0.*/
    UNMESR1,            /* This is the uncorrectable non-fatal memory error status register 1.*/
    UNMECTR,            /* This is the uncorrectable non-fatal memory error count register which tracks how many events have been detected.*/
    SIUNMESR0,          /* This is the uncorrectable non-fatal memory error status register 0.*/
    SIUNMESR1,          /* This is the uncorrectable memory error status register 1.*/
    SIUNMECTR,          /* This is the uncorrectable non-fatal memory error count register which tracks how many events have been detected. */
    EMDIOUNIESR,        /* This is the EMDIO uncorrectable non-fatal integrity error status register. */
    UNIESR,             /* This is the uncorrectable non-fatal integrity error status register. */
    UNIECTR,            /* This is the uncorrectable non-fatal integrity error count register which tracks how many events have been detected. */
    TUFSBESR,           /* This is the timer uncorrectable fatal system bus error status register. */
    EMDIOUFSBESR,       /* This is the EMDIO uncorrectable fatal system bus error status register.*/
    UFSBESR,            /* This is the uncorrectable fatal system bus error status register. */
    SIUFSBESR,          /* This is the uncorrectable fatal system bus error status register. */
    RBPIR,              /* Frame BD prefetching for the station interface ring is stalled. The frame BD producer index will indicate the last successfully updated BD.*/
    UFMESR0,            /* This is the uncorrectable fatal memory error status register 0. */
    UFMESR1,            /* This is the uncorrectable fatal memory error status register 1. */
    SIUFMESR0,          /* This is the uncorrectable fatal memory error status register 0. */
    SIUFMESR1,          /* This is the uncorrectable fatal memory error status register 1. */
    UFIESR,             /* This is the uncorrectable fatal integrity error status register. */
    SIUFIESR,           /* This is the uncorrectable fatal integrity error status register. */
    UNMACESR            /* This is the uncorrectable non-fatal MAC error status register.*/
} Netc_Eth_Ip_ErrorCaptureRegLabel;

/* implements     Netc_Eth_Ip_ErrorCaptureRegisterInformation_structure */
typedef struct
{
    uint32 RegRawValueLow; /* Error Capture Register Low part Raw value. The decoding must be done according to documentation 0-31 bits*/
    uint32 RegRawValueHigh; /* Error Capture Register High Raw value. The decoding must be done according to documentation 32-63 bits. For 32bit registers it is set to 0. */

    Netc_Eth_Ip_ErrorCaptureRegLabel RegName; /* Error Capture Register name */
} Netc_Eth_Ip_ErrorCaptureRegisterInformation;

#if defined(NETC_ETH_IP_FILL_LEVEL_API_ENABLE)
#if (NETC_ETH_IP_FILL_LEVEL_API_ENABLE == STD_ON)
typedef struct
{
    uint16 NumberOfUsedBuff;    /* Number of buffers currently used. */
    uint16 MaxNumberOfUsedBuff; /* Maximum number of buffers used since the last check. */
    uint16 TotalNumberOfBuff;   /* Buffers allocated in total for the current FIFO. */
}Netc_Eth_Ip_FillLevelInfo;
#endif  /* STD_ON == NETC_ETH_IP_FILL_LEVEL_API_ENABLE  */
#endif /* defined(NETC_ETH_IP_FILL_LEVEL_API_ENABLE) */


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
