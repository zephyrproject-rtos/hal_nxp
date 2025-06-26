/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETHSWT_IP_CFG_DEFINES_H
#define NETC_ETHSWT_IP_CFG_DEFINES_H

/**
 *   @file Netc_EthSwt_Ip_Cfg_Defines.h
 *   @addtogroup NETC_ETHSWT_IP NETC_ETHSWT Driver
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
#include "Mcal.h"
#include "S32Z2_NETC_F3_COMMON.h"
#include "S32Z2_ENETC_PORT.h"
#include "S32Z2_NETC_F3_SI0.h"
#include "S32Z2_NETC_F3.h"
#include "S32Z2_NETC_F0_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_F1_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_F2_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_F3_PCI_HDR_TYPE0.h"
#include "S32Z2_SW_PORT0.h"
#include "S32Z2_SW_PORT1.h"
#include "S32Z2_SW_PORT2.h"
#include "S32Z2_SW_ETH_MAC_PORT0.h"
#include "S32Z2_SW_ETH_MAC_PORT1.h"
#include "S32Z2_SW_PSEUDO_MAC_PORT2.h"
#include "S32Z2_NETC_IERB.h"
#include "S32Z2_NETC_F2.h"
#include "S32Z2_NETC_F2_GLOBAL.h"
#include "S32Z2_NETC_F2_COMMON.h"
#include "S32Z2_NETC_PRIV.h"
#include "S32Z2_NETC_F1.h"
#include "S32Z2_GPR1.h"
#include "S32Z2_TMR0_BASE.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_CFG_DEFINES_VENDOR_ID                    43
#define NETC_ETHSWT_IP_CFG_DEFINES_MODULE_ID                    89
#define NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETHSWT_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define NETC_ETHSWT_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define NETC_ETHSWT_IP_CFG_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (NETC_ETHSWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Cfg_Defines.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define NETC_NUMBER_OF_PRIORITIES (8U) /*!< Number of priorities.*/

#define NETC_TXBD_BUF_LEN_MASK           (0x0000FFFFUL) /*!< TX buffer length mask.*/
#define NETC_TXBD_FINAL_MASK             (0x80000000UL) /*!< TX final mask.*/
#define NETC_TXBD_EXTENDED_BUFFER_MASK   (0x40000000UL) /*!< TX extended buffer mask.*/
#define NETC_TXBD_WRITTEN_MASK           (0x08000000UL) /*!< TX written mask.*/

#define NETC_RXBD_FINAL_MASK             (0x80000000UL) /*!< RX final mask.*/

#define Netc_EthSwt_Ip_PortBaseType      SW_ETH_MAC_PORT0_Type  /*!< Port base type.*/
#define Netc_EthSwt_Ip_PseudoPortBaseType      SW_PSEUDO_MAC_PORT2_Type  /*!< Pseudo base type.*/

#define FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS	(1U) /*!< Number of switchs.*/

#define NETC_ETHSWT_IP_FDBTABLE_REQBUFFER_LEN                   (48U)     /*!< the length of request data buffer in bytes for FDB and other small tables */
#define NETC_ETHSWT_IP_EGRESSTREAMENTTABLE_RESBUFFER_LEN        (20U)     /*!< 20 bytes is response buffer lenth*/
#define NETC_ETHSWT_IP_FDBTABLE_QUERY_REQBUFFER_LEN             (36U)     /*!< 36 bytes is request buffer lenth for query and delete cmd of FDB table*/
#define NETC_ETHSWT_IP_FDBTABLE_RESBUFFER_LEN                   (36U)     /*!< 36 bytes is response buffer lenth*/
#define NETC_ETHSWT_IP_VLANFILTERTABLE_REQBUFFER_LEN            (24U)      /*!< the length of request data buffer in bytes for vlan filter table */
#define NETC_ETHSWT_IP_VLANFILTERTABLE_RESBUFFER_LEN            (28U)     /*!< 28 bytes is response buffer lenth*/

#define NETC_ETHSWT_IP_RATEPOLICERTABLE_REQBUFFER_LEN           (27U)     /*!< the length of request data buffer in bytes for add cmd for rate policer table */
#define NETC_ETHSWT_IP_RATEPOLICERTABLE_RSPBUFFER_LEN           (108U)    /*!< the length of response data buffer in bytes for rate policer table */

#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_RSPBUFFER_LEN           (20U)     /*!< the length of response data buffer in bytes for Egress Count table */

#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN     (224U)    /*!< the length of request data buffer in bytes for Ingress Port Filter table */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN     (236U)    /*!< the length of response data buffer in bytes for Ingress Port Filter table */

#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_REQBUFFER_LEN         (46U)     /*!< the length of request data buffer in bytes for add and update cmd for ingress stream table */
#define NETC_ETHSWT_IP_INGRESSSTREAMTABLE_RSPBUFFER_LEN         (42U)     /*!< the length of response data buffer in bytes for ingress stream table */

#define NETC_ETHSWT_IP_ISFILTERTABLE_REQBUFFER_LEN              (28U)      /*!< the length of request data buffer in bytes for add and update cmd for ingress stream filter table */
#define NETC_ETHSWT_IP_ISFILTERTABLE_OTHER_REQBUFFER_LEN        (12U)      /*!< the length of request data buffer in bytes for query (search) and delete cmd for ingress stream filter table */
#define NETC_ETHSWT_IP_ISFILTERTABLE_RSPBUFFER_LEN              (32U)      /*!< the length of response data buffer in bytes for ingress stream filter table */

#define NETC_ETHSWT_IP_SGITABLE_REQBUFFER_LEN                   (26U)      /*!< the length of request data buffer in bytes for add and update cmd for stream gate instance table */
#define NETC_ETHSWT_IP_SGITABLE_RSPBUFFER_LEN                   (48U)      /*!< the length of response data buffer in bytes for stream gate instance table */

#define NETC_ETHSWT_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN         (8U)       /*!< 8 bytes request data buffer length for query and delete cmd for tables */
#define NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN         (0U)       /*!< 0 bytes response data buffer length for add, update and delete cmd for tables */
#define NETC_ETHSWT_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN         (4U)       /*!< 4 bytes response data buffer length for add, update and delete cmd for tables */

#define NETC_ETHSWT_IP_TGSTABLE_RSPBUFFER_LEN                   (12U)     /*!< the length of response data buffer in bytes for time gate scheduling table */
#define NETC_ETHSWT_IP_FRMTABLE_REQBUFFER_LEN                   (32U)     /*!< the length of request data buffer in bytes for frame modification table */
#define NETC_ETHSWT_IP_FRMTABLE_RSPBUFFER_LEN                   (28U)     /*!< the length of response data buffer in bytes for frame modification table */
#define NETC_ETHSWT_IP_ETMTABLE_REQBUFFER_LEN                   (24U)     /*!< the length of request data buffer in bytes for egress treatment table */

#define NETC_ETHSWT_IP_ISQGTABLE_REQBUFFER_LEN                  (9U)     /*!< the length of request data buffer in bytes for add and update cmd for ingress sequence generation table */
#define NETC_ETHSWT_IP_ISQGTABLE_RSPBUFFER_LEN                  (8U)     /*!< the length of response data buffer in bytes for query cmd for ingress sequence generation table */

#define NETC_ETHSWT_IP_EGRSQRTABLE_REQBUFFER_LEN                (16U)     /*!< the length of request data buffer in bytes for update  and query cmd for Egress sequence recovery table */
#define NETC_ETHSWT_IP_EGRSQRTABLE_RSPBUFFER_LEN                (84U)     /*!< the length of response data buffer in bytes for query cmd for Egress sequence recovery table */
#define NETC_ETHSWT_IP_ISITABLE_ADD_REQBUFFER_LEN               (28U)     /*!< the length of request data buffer in bytes for add and update cmd for ingress stream identification table */
#define NETC_ETHSWT_IP_ISITABLE_QUERY_REQBUFFER_LEN             (24U)     /*!< the length of request data buffer in bytes for query and delete cmd for ingress stream identification table */
#define NETC_ETHSWT_IP_ISITABLE_RSQBUFFER_LEN                   (32U)     /*!< the length of response data buffer in bytes for query cmd for ingress stream identification table */

#define NETC_ETHSWT_IP_EGRSCHTABLE_REQBUFFER_LEN                (20U)     /*!< the length of request data buffer in bytes for update cmd for Egress scheduler table */
#define NETC_ETHSWT_IP_EGRSCHTABLE_RSPBUFFER_LEN                (16U)     /*!< the length of response data buffer in bytes for query cmd for Egress scheduler table */

#define NETC_ETHSWT_IP_ISCTABLE_RSPBUFFER_LEN                   (36U)     /*!< the lenght of response data buffer in bytes for query cmd for ingress stream count table */

/* The maximum number of Weighted Fair Share Queues */
#define NETC_ETHSWT_WBFS_QUEUES_NB (8U)

#define NETC_ETHSWT_IP_HOSTREASON_REGULAR_FRAME (0x00000000UL)
#define NETC_ETHSWT_IP_HOSTREASON_INGR_MIRROR   (0x00000001UL)
#define NETC_ETHSWT_IP_HOSTREASON_MAC_LEARN     (0x00000002UL)
#define NETC_ETHSWT_IP_HOSTREASON_TIMESTAMP     (0x00000003UL)
#define NETC_ETHSWT_IP_HOSTREASON_RESERVEDx4    (0x00000004UL)
#define NETC_ETHSWT_IP_HOSTREASON_RESERVEDx5    (0x00000005UL)
#define NETC_ETHSWT_IP_HOSTREASON_RESERVEDx6    (0x00000006UL)
#define NETC_ETHSWT_IP_HOSTREASON_RESERVEDx7    (0x00000007UL)
#define NETC_ETHSWT_IP_HOSTREASON_SW_PTP        (0x00000008UL)
#define NETC_ETHSWT_IP_HOSTREASON_SWx9          (0x00000009UL)
#define NETC_ETHSWT_IP_HOSTREASON_SWxA          (0x0000000AUL)
#define NETC_ETHSWT_IP_HOSTREASON_SWxB          (0x0000000BUL)
#define NETC_ETHSWT_IP_HOSTREASON_SWxC          (0x0000000CUL)
#define NETC_ETHSWT_IP_HOSTREASON_SWxD          (0x0000000DUL)
#define NETC_ETHSWT_IP_HOSTREASON_SWxE          (0x0000000EUL)
#define NETC_ETHSWT_IP_HOSTREASON_SWxF          (0x0000000FUL)

/* The maximum number of gate control list */
#define NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES              (8U)

/*  NETC dev error detected. */
#define NETC_ETHSWT_IP_DEV_ERROR_DETECT         (STD_OFF)

/*!< The length of response data buffer in bytes for time gate scheduling table. */
#define NETC_ETHSWT_IP_TGSTABLE_ADD_REQBUFFER_LEN     (92U)
#define NETC_ETHSWT_IP_TABLEDATA_BUFFER_LENGTH  (59U)
 #define NETC_ETHSWT_IP_CONFIG_LINK_PROTOCOL    (STD_ON)

/** @brief Define used to enable/disable timer syncronization. */
#define NETC_ETHSWT_TIMER_SYNC_MASK            (0x1U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*!
 * @brief Netc_EthSwt counter enum Netc_EthSwt_Ip_SingleCounterType
 * @implements Netc_EthSwt_Ip_SingleCounterType_enum
 */
typedef enum {
    NETC_ETHSWT_IP_RX_ETH_OCTETS_COUNT                      = 0x100U,  /*!< Port MAC 0 Receive Ethernet Octets Counter(etherStatsOctetsn) (PM0_REOCTn) */
    NETC_ETHSWT_IP_RX_OCTETS_COUNT                          = 0x108U,  /*!< Supported by pseudo port. Port MAC 0 Receive Octets Counter(iflnOctetsn) (PM0_ROCTn) */
    NETC_ETHSWT_IP_RX_ALIGN_ERR_COUNT                       = 0x110U,  /*!< Port MAC 0 Receive Alignment Error Counter Register(aAlignmentErrorsn) (PM0_RALNn)) */
    NETC_ETHSWT_IP_RX_VALID_PAUSE_FRM_COUNT                 = 0x118U,  /*!< Port MAC 0 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_RXPFn) */
    NETC_ETHSWT_IP_RX_FRM_COUNT                             = 0x120U,  /*!< Port MAC 0 Receive Frame Counter Register(aFramesReceivedOKn) (PM0_RFRMn)  */
    NETC_ETHSWT_IP_RX_FRM_CHK_SEQUENCE_COUNT                = 0x128U,  /*!< Port MAC 0 Receive Frame Check Sequence Error Counter Register() (PM0_RFCSn)  */
    NETC_ETHSWT_IP_RX_VLAN_FRM_COUNT                        = 0x130U,  /*!< Port MAC 0 Receive VLAN Frame Counter Register(VLANReceivedOKn) (PM0_RVLANn)  */
    NETC_ETHSWT_IP_RX_FRM_ERROR_COUNT                       = 0x138U,  /*!< Port MAC 0 Receive Frame Error Counter Register(ifInErrorsn) (PM0_RERRn)  */
    NETC_ETHSWT_IP_RX_UNICAST_FRM_COUNT                     = 0x140U,  /*!< Supported by pseudo port. Port MAC 0 Receive Unicast Frame Counter Register(ifInUcastPktsn) (PM0_RUCAn)  */
    NETC_ETHSWT_IP_RX_MULTICAST_FRM_COUNT                   = 0x148U,  /*!< Supported by pseudo port. Port MAC 0 Receive Multicast Frame Counter Register(ifInMulticastPktsn) (PM0_RMCAn)  */
    NETC_ETHSWT_IP_RX_BROADCAST_FRM_COUNT                   = 0x150U,  /*!< Supported by pseudo port. Port MAC 0 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) (PM0_RBCAn)  */
    NETC_ETHSWT_IP_RX_DROPPED_PKTS_COUNT                    = 0x158U,  /*!< Port MAC 0 Receive Dropped Packets Counter Register(etherStatsDropEventsn) (PM0_RDRPn)  */
    NETC_ETHSWT_IP_RX_PKTS_COUNT                            = 0x160U,  /*!< Port MAC 0 Receive Packets Counter Register(etherStatsPktsn) (PM0_RPKTn)  */
    NETC_ETHSWT_IP_RX_UNDERSIZED_PKT_COUNT                  = 0x168U,  /*!< Port MAC 0 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_RUNDn)  */
    NETC_ETHSWT_IP_RX_64_OCTETS_PKT_COUNT                   = 0x170U,  /*!< Port MAC 0 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) (PM0_R64n)  */
    NETC_ETHSWT_IP_RX_127_OCTETS_PKT_COUNT                  = 0x178U,  /*!< Port MAC 0 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) (PM0_R127n)  */
    NETC_ETHSWT_IP_RX_255_OCTETS_PKT_COUNT                  = 0x180U,  /*!< Port MAC 0 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) (PM0_R255n)  */
    NETC_ETHSWT_IP_RX_511_OCTETS_PKT_COUNT                  = 0x188U,  /*!< Port MAC 0 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) (PM0_R511n)  */
    NETC_ETHSWT_IP_RX_1023_OCTETS_PKT_COUNT                 = 0x190U,  /*!< Port MAC 0 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) (PM0_R1023n)  */
    NETC_ETHSWT_IP_RX_1522_OCTETS_PKT_COUNT                 = 0x198U,  /*!< Port MAC 0 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) (PM0_R1522n)  */
    NETC_ETHSWT_IP_RX_1523_TOMAXOCTETS_PKT_COUNT            = 0x1A0U,  /*!< Port MAC 0 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) (PM0_R1523Xn)  */
    NETC_ETHSWT_IP_RX_OVERSIZED_PKT_COUNT                   = 0x1A8U,  /*!< Port MAC 0 Receive Oversized Packet Counter Register(etherStatsOversizePktsn) (PM0_ROVRn)  */
    NETC_ETHSWT_IP_RX_JABBER_PKT_COUNT                      = 0x1B0U,  /*!< Port MAC 0 Receive Jabber Packet Counter Register(etherStatsJabbersn) (PM0_RJBRn)  */
    NETC_ETHSWT_IP_RX_FRAGMENT_PKT_COUNT                    = 0x1B8U,  /*!< Port MAC 0 Receive Fragment Packet Counter Register(etherStatsFragmentsn (PM0_RFRGn)  */
    NETC_ETHSWT_IP_RX_CONTROL_PKT_COUNT                     = 0x1C0U,  /*!< Port MAC 0 Receive Control Packet Counter Register (PM0_RCNPn)  */
    NETC_ETHSWT_IP_RX_DROPPED_NOT_TRUNCATED_PKT_COUNT       = 0x1C8U,  /*!< Port MAC 0 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) (PM0_RDRNTPn)  */
    NETC_ETHSWT_IP_RX_VALID_SMALL_PKT_COUNTER               = 0x5D0U,  /*!< Port MAC 0 Receive Valid Small Packet Counter Register (PM0_RMIN63n)  */

    NETC_ETHSWT_IP_TX_ETH_OCTETS_COUNT                      = 0x200U,  /*!< Port MAC 0 Transmit Ethernet Octets Counter(etherStatsOctetsn) (PM0_TEOCTn)  */
    NETC_ETHSWT_IP_TX_OCTETS_COUNT                          = 0x208U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Octets Counter Register(ifOutOctetsn) (PM0_TOCTn)  */
    NETC_ETHSWT_IP_TX_EXCESS_DEFER_ERR_COUNT                = 0x210U,  /*!< Port MAC 0 Excess Defer Error Counter Register(aFramesWithExccessiveDeferral) (PM0_TEDFRn))  */
    NETC_ETHSWT_IP_TX_VALID_PAUSE_FRM_COUNT                 = 0x218U,  /*!< Port MAC 0 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM0_TXPFn)  */
    NETC_ETHSWT_IP_TX_FRM_COUNT                             = 0x220U,  /*!< Port MAC 0 Transmit Frame Counter Register(aFramesTransmittedOKn) (PM0_TFRMn)  */
    NETC_ETHSWT_IP_TX_FRM_CHK_SEQUENCE_COUNT                = 0x228U,  /*!< Port MAC 0 Transmit Frame Check Sequence Error Counter Register() (PM0_TFCSn)  */
    NETC_ETHSWT_IP_TX_VLAN_FRM_COUNT                        = 0x230U,  /*!< Port MAC 0 Transmit VLAN Frame Counter Register(VLANTransmittedOKn) (PM0_TVLANn)  */
    NETC_ETHSWT_IP_TX_FRM_ERROR_COUNT                       = 0x238U,  /*!< Port MAC 0 Transmit Frame Error Counter Register(ifOutErrorsn) (PM0_TERRn)  */
    NETC_ETHSWT_IP_TX_UNICAST_FRM_COUNT                     = 0x240U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Unicast Frame Counter Register(ifOutUcastPktsn) (PM0_TUCAn)  */
    NETC_ETHSWT_IP_TX_MULTICAST_FRM_COUNT                   = 0x248U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) (PM0_TMCAn)  */
    NETC_ETHSWT_IP_TX_BROADCAST_FRM_COUNT                   = 0x250U,  /*!< Supported by pseudo port. Port MAC 0 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) (PM0_TBCAn)  */
    NETC_ETHSWT_IP_TX_PKTS_COUNT                            = 0x260U,  /*!< Port MAC 0 Transmit Packets Counter Register(etherStatsPktsn) (PM0_TPKTn)  */
    NETC_ETHSWT_IP_TX_UNDERSIZED_PKT_COUNT                  = 0x268U,  /*!< Port MAC 0 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM0_TUNDn)  */
    NETC_ETHSWT_IP_TX_64_OCTETS_PKT_COUNT                   = 0x270U,  /*!< Port MAC 0 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) (PM0_T64n)  */
    NETC_ETHSWT_IP_TX_127_OCTETS_PKT_COUNT                  = 0x278U,  /*!< Port MAC 0 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) (PM0_T127n)  */
    NETC_ETHSWT_IP_TX_255_OCTETS_PKT_COUNT                  = 0x280U,  /*!< Port MAC 0 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) (PM0_T255n)  */
    NETC_ETHSWT_IP_TX_511_OCTETS_PKT_COUNT                  = 0x288U,  /*!< Port MAC 0 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) (PM0_T511n)  */
    NETC_ETHSWT_IP_TX_1023_OCTETS_PKT_COUNT                 = 0x290U,  /*!< Port MAC 0 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) (PM0_T1023n)  */
    NETC_ETHSWT_IP_TX_1522_OCTETS_PKT_COUNT                 = 0x298U,  /*!< Port MAC 0 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) (PM0_T1522n)  */
    NETC_ETHSWT_IP_TX_1523_TOMAXOCTETS_PKT_COUNT            = 0x2A0U,  /*!< Port MAC 0 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) (PM0_T1523Xn)  */
    NETC_ETHSWT_IP_TX_CONTROL_PKT_COUNT                     = 0x2C0U,  /*!< Port MAC 0 Transmit Control Packet Counter Register (PM0_TCNPn)  */
    NETC_ETHSWT_IP_TX_DEFERRED_PKT_COUNT                    = 0x2D0U,  /*!< Port MAC 0 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) (PM0_TDFRn)  */
    NETC_ETHSWT_IP_TX_MULTIPLE_COLLISIONS_COUNT             = 0x2D8U,  /*!< Port MAC 0 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) (PM0_TMCOLn)  */
    NETC_ETHSWT_IP_TX_SINGLE_COLLISION_COUNT                = 0x2E0U,  /*!< Port MAC 0 Transmit Single Collision Counter(aSingleCollisionFrames) Register (PM0_TSCOLn)  */
    NETC_ETHSWT_IP_TX_LATE_COLLISION_COUNT                  = 0x2E8U,  /*!< Port MAC 0 Transmit Late Collision Counter(aLateCollisions) Register (PM0_TLCOLn)  */
    NETC_ETHSWT_IP_TX_EXCESSIVE_COLLISIONS_COUNT            = 0x2F0U,  /*!< Port MAC 0 Transmit Excessive Collisions Counter Register (PM0_TECOLn)  */
    
    /* MAC1(PMAC) extension*/
    NETC_ETHSWT_IP_RX_ETH_OCTETS_COUNT_MAC1                 = 0x500U,  /*!< Port MAC 1 Receive Ethernet Octets Counter(etherStatsOctetsn) (PM1_REOCTn) */
    NETC_ETHSWT_IP_RX_OCTETS_COUNT_MAC1                     = 0x508U,  /*!< Supported by pseudo port. Port MAC 0 Receive Octets Counter(iflnOctetsn) (PM1_ROCTn) */
    NETC_ETHSWT_IP_RX_ALIGN_ERR_COUNT_MAC1                  = 0x510U,  /*!< Port MAC 1 Receive Alignment Error Counter Register(aAlignmentErrorsn) (PM1_RALNn)) */
    NETC_ETHSWT_IP_RX_VALID_PAUSE_FRM_COUNT_MAC1            = 0x518U,  /*!< Port MAC 1 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM1_RXPFn) */
    NETC_ETHSWT_IP_RX_FRM_COUNT_MAC1                        = 0x520U,  /*!< Port MAC 1 Receive Frame Counter Register(aFramesReceivedOKn) (PM1_RFRMn)  */
    NETC_ETHSWT_IP_RX_FRM_CHK_SEQUENCE_COUNT_MAC1           = 0x528U,  /*!< Port MAC 1 Receive Frame Check Sequence Error Counter Register() (PM1_RFCSn)  */
    NETC_ETHSWT_IP_RX_VLAN_FRM_COUNT_MAC1                   = 0x530U,  /*!< Port MAC 1 Receive VLAN Frame Counter Register(VLANReceivedOKn) (PM1_RVLANn)  */
    NETC_ETHSWT_IP_RX_FRM_ERROR_COUNT_MAC1                  = 0x538U,  /*!< Port MAC 1 Receive Frame Error Counter Register(ifInErrorsn) (PM1_RERRn)  */
    NETC_ETHSWT_IP_RX_UNICAST_FRM_COUNT_MAC1                = 0x540U,  /*!< Supported by pseudo port. Port MAC 1 Receive Unicast Frame Counter Register(ifInUcastPktsn) (PM1_RUCAn)  */
    NETC_ETHSWT_IP_RX_MULTICAST_FRM_COUNT_MAC1              = 0x548U,  /*!< Supported by pseudo port. Port MAC 1 Receive Multicast Frame Counter Register(ifInMulticastPktsn) (PM1_RMCAn)  */
    NETC_ETHSWT_IP_RX_BROADCAST_FRM_COUNT_MAC1              = 0x550U,  /*!< Supported by pseudo port. Port MAC 1 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) (PM1_RBCAn)  */
    NETC_ETHSWT_IP_RX_DROPPED_PKTS_COUNT_MAC1               = 0x558U,  /*!< Port MAC 1 Receive Dropped Packets Counter Register(etherStatsDropEventsn) (PM1_RDRPn)  */
    NETC_ETHSWT_IP_RX_PKTS_COUNT_MAC1                       = 0x560U,  /*!< Port MAC 1 Receive Packets Counter Register(etherStatsPktsn) (PM1_RPKTn)  */
    NETC_ETHSWT_IP_RX_UNDERSIZED_PKT_COUNT_MAC1             = 0x568U,  /*!< Port MAC 1 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM1_RUNDn)  */
    NETC_ETHSWT_IP_RX_64_OCTETS_PKT_COUNT_MAC1              = 0x570U,  /*!< Port MAC 1 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) (PM1_R64n)  */
    NETC_ETHSWT_IP_RX_127_OCTETS_PKT_COUNT_MAC1             = 0x578U,  /*!< Port MAC 1 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) (PM1_R127n)  */
    NETC_ETHSWT_IP_RX_255_OCTETS_PKT_COUNT_MAC1             = 0x580U,  /*!< Port MAC 1 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) (PM1_R255n)  */
    NETC_ETHSWT_IP_RX_511_OCTETS_PKT_COUNT_MAC1             = 0x588U,  /*!< Port MAC 1 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) (PM1_R511n)  */
    NETC_ETHSWT_IP_RX_1023_OCTETS_PKT_COUNT_MAC1            = 0x590U,  /*!< Port MAC 1 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) (PM1_R1023n)  */
    NETC_ETHSWT_IP_RX_1522_OCTETS_PKT_COUNT_MAC1            = 0x598U,  /*!< Port MAC 1 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) (PM1_R1522n)  */
    NETC_ETHSWT_IP_RX_1523_TOMAXOCTETS_PKT_COUNT_MAC1       = 0x5A0U,  /*!< Port MAC 1 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) (PM1_R1523Xn)  */
    NETC_ETHSWT_IP_RX_OVERSIZED_PKT_COUNT_MAC1              = 0x5A8U,  /*!< Port MAC 1 Receive Oversized Packet Counter Register(etherStatsOversizePktsn) (PM1_ROVRn)  */
    NETC_ETHSWT_IP_RX_JABBER_PKT_COUNT_MAC1                 = 0x5B0U,  /*!< Port MAC 1 Receive Jabber Packet Counter Register(etherStatsJabbersn) (PM1_RJBRn)  */
    NETC_ETHSWT_IP_RX_FRAGMENT_PKT_COUNT_MAC1               = 0x5B8U,  /*!< Port MAC 1 Receive Fragment Packet Counter Register(etherStatsFragmentsn (PM1_RFRGn)  */
    NETC_ETHSWT_IP_RX_CONTROL_PKT_COUNT_MAC1                = 0x5C0U,  /*!< Port MAC 1 Receive Control Packet Counter Register (PM1_RCNPn)  */
    NETC_ETHSWT_IP_RX_DROPPED_NOT_TRUNCATED_PKT_COUNT_MAC1  = 0x5C8U,  /*!< Port MAC 1 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) (PM1_RDRNTPn)  */
    NETC_ETHSWT_IP_RX_VALID_SMALL_PKT_COUNTER_MAC1          = 0x5D0U,  /*!< Port MAC 1 Receive Valid Small Packet Counter Register (PM1_RMIN63n)  */

    NETC_ETHSWT_IP_TX_ETH_OCTETS_COUNT_MAC1                 = 0x600U,  /*!< Port MAC 1 Transmit Ethernet Octets Counter(etherStatsOctetsn) (PM1_TEOCTn)  */
    NETC_ETHSWT_IP_TX_OCTETS_COUNT_MAC1                     = 0x608U,  /*!< Supported by pseudo port. Port MAC 1 Transmit Octets Counter Register(ifOutOctetsn) (PM1_TOCTn)  */
    NETC_ETHSWT_IP_TX_EXCESS_DEFER_ERR_COUNT_MAC1           = 0x610U,  /*!< Port MAC 1 Excess Defer Error Counter Register(aFramesWithExccessiveDeferral) (PM1_TEDFRn))  */
    NETC_ETHSWT_IP_TX_VALID_PAUSE_FRM_COUNT_MAC1            = 0x618U,  /*!< Port MAC 1 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) (PM1_TXPFn)  */
    NETC_ETHSWT_IP_TX_FRM_COUNT_MAC1                        = 0x620U,  /*!< Port MAC 1 Transmit Frame Counter Register(aFramesTransmittedOKn) (PM1_TFRMn)  */
    NETC_ETHSWT_IP_TX_FRM_CHK_SEQUENCE_COUNT_MAC1           = 0x628U,  /*!< Port MAC 1 Transmit Frame Check Sequence Error Counter Register() (PM1_TFCSn)  */
    NETC_ETHSWT_IP_TX_VLAN_FRM_COUNT_MAC1                   = 0x630U,  /*!< Port MAC 1 Transmit VLAN Frame Counter Register(VLANTransmittedOKn) (PM1_TVLANn)  */
    NETC_ETHSWT_IP_TX_FRM_ERROR_COUNT_MAC1                  = 0x638U,  /*!< Port MAC 1 Transmit Frame Error Counter Register(ifOutErrorsn) (PM1_TERRn)  */
    NETC_ETHSWT_IP_TX_UNICAST_FRM_COUNT_MAC1                = 0x640U,  /*!< Supported by pseudo port. Port MAC 1 Transmit Unicast Frame Counter Register(ifOutUcastPktsn) (PM1_TUCAn)  */
    NETC_ETHSWT_IP_TX_MULTICAST_FRM_COUNT_MAC1              = 0x648U,  /*!< Supported by pseudo port. Port MAC 1 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) (PM1_TMCAn)  */
    NETC_ETHSWT_IP_TX_BROADCAST_FRM_COUNT_MAC1              = 0x650U,  /*!< Supported by pseudo port. Port MAC 1 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) (PM1_TBCAn)  */
    NETC_ETHSWT_IP_TX_PKTS_COUNT_MAC1                       = 0x660U,  /*!< Port MAC 1 Transmit Packets Counter Register(etherStatsPktsn) (PM1_TPKTn)  */
    NETC_ETHSWT_IP_TX_UNDERSIZED_PKT_COUNT_MAC1             = 0x668U,  /*!< Port MAC 1 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) (PM1_TUNDn)  */
    NETC_ETHSWT_IP_TX_64_OCTETS_PKT_COUNT_MAC1              = 0x670U,  /*!< Port MAC 1 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) (PM1_T64n)  */
    NETC_ETHSWT_IP_TX_127_OCTETS_PKT_COUNT_MAC1             = 0x678U,  /*!< Port MAC 1 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) (PM1_T127n)  */
    NETC_ETHSWT_IP_TX_255_OCTETS_PKT_COUNT_MAC1             = 0x680U,  /*!< Port MAC 1 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) (PM1_T255n)  */
    NETC_ETHSWT_IP_TX_511_OCTETS_PKT_COUNT_MAC1             = 0x688U,  /*!< Port MAC 1 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) (PM1_T511n)  */
    NETC_ETHSWT_IP_TX_1023_OCTETS_PKT_COUNT_MAC1            = 0x690U,  /*!< Port MAC 1 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) (PM1_T1023n)  */
    NETC_ETHSWT_IP_TX_1522_OCTETS_PKT_COUNT_MAC1            = 0x698U,  /*!< Port MAC 1 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) (PM1_T1522n)  */
    NETC_ETHSWT_IP_TX_1523_TOMAXOCTETS_PKT_COUNT_MAC1       = 0x6A0U,  /*!< Port MAC 1 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) (PM1_T1523Xn)  */
    NETC_ETHSWT_IP_TX_CONTROL_PKT_COUNT_MAC1                = 0x6C0U,  /*!< Port MAC 1 Transmit Control Packet Counter Register (PM1_TCNPn)  */
    NETC_ETHSWT_IP_TX_DEFERRED_PKT_COUNT_MAC1               = 0x6D0U,  /*!< Port MAC 1 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) (PM1_TDFRn)  */
    NETC_ETHSWT_IP_TX_MULTIPLE_COLLISIONS_COUNT_MAC1        = 0x6D8U,  /*!< Port MAC 1 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) (PM1_TMCOLn)  */
    NETC_ETHSWT_IP_TX_SINGLE_COLLISION_COUNT_MAC1           = 0x6E0U,  /*!< Port MAC 1 Transmit Single Collision Counter(aSingleCollisionFrames) Register (PM1_TSCOLn)  */
    NETC_ETHSWT_IP_TX_LATE_COLLISION_COUNT_MAC1             = 0x6E8U,  /*!< Port MAC 1 Transmit Late Collision Counter(aLateCollisions) Register (PM1_TLCOLn)  */
    NETC_ETHSWT_IP_TX_EXCESSIVE_COLLISIONS_COUNT_MAC1       = 0x6F0U   /*!< Port MAC 1 Transmit Excessive Collisions Counter Register (PM1_TECOLn)  */
} Netc_EthSwt_Ip_SingleCounterType;

typedef enum {
    NETC_ETHSWT_IP_PPMROCR0 = 0x80U,  /*!< Port pseudo MAC receive octets counter PPMROCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMROCR1 = 0x84U,  /*!< Port pseudo MAC receive octets counter PPMROCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRUFCR0 = 0x88U, /*!< Port pseudo MAC receive unicast frame counter register PPMRUFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRUFCR1 = 0x8CU, /*!< Port pseudo MAC receive unicast frame counter register PPMRUFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRMFCR0 = 0x90U, /*!< Port pseudo MAC receive multicast frame counter register PPMRMFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRMFCR1 = 0x94U, /*!< Port pseudo MAC receive multicast frame counter register PPMRMFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRBFCR0 = 0x98U, /*!< Port pseudo MAC receive broadcast frame counter register PPMRBFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMRBFCR1 = 0x9CU, /*!< Port pseudo MAC receive broadcast frame counter register PPMRBFCR1. The upper 32bits of the counter.  */

    NETC_ETHSWT_IP_PPMTOCR0 = 0xC0U, /*!< Port pseudo MAC transmit octets counter PPMTOCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTOCR1 = 0xC4U, /*!< Port pseudo MAC transmit octets counter PPMTOCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTUFCR0 = 0xC8U, /*!< Port pseudo MAC transmit unicast frame counter register PPMTUFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTUFCR1 = 0xCCU, /*!< Port pseudo MAC transmit unicast frame counter register PPMTUFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTMFCR0 = 0xD0U, /*!< Port pseudo MAC transmit multicast frame counter register PPMTMFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTMFCR1 = 0xD4U, /*!< Port pseudo MAC transmit multicast frame counter register PPMTMFCR1. The upper 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTBFCR0 = 0xD8U, /*!< Port pseudo MAC transmit broadcast frame counter register PPMTBFCR0. The lower 32bits of the counter.  */
    NETC_ETHSWT_IP_PPMTBFCR1 = 0xDCU, /*!< Port pseudo MAC transmit broadcast frame counter register PPMTBFCR1. The upper 32bits of the counter.  */
} Netc_EthSwt_Ip_PseudoPortCounterType;


#if !defined(Netc_EthSwt_Ip_TimerBase)
#define Netc_EthSwt_Ip_TimerBase                   IP_NETC__TMR0_BASE
#endif


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

#endif /* NETC_ETHSWT_IP_CFG_DEFINES_H */
