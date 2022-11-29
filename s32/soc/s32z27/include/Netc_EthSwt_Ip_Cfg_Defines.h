/*
 * Copyright 2022 NXP
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
#include "S32Z2_ENETC_PORT.h"
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
#define NETC_ETHSWT_IP_CFG_DEFINES_SW_MAJOR_VERSION             0
#define NETC_ETHSWT_IP_CFG_DEFINES_SW_MINOR_VERSION             9
#define NETC_ETHSWT_IP_CFG_DEFINES_SW_PATCH_VERSION             0

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

#define NETC_ETHSWT_IP_DEV_ERROR_DETECT STD_ON /*!< NETC dev error detected.*/

#define NETC_NUMBER_OF_PRIORITIES (8U) /*!< Number of priorities.*/

#define NETC_TXBD_BUF_LEN_MASK           (0x0000FFFFUL) /*!< TX buffer length mask.*/
#define NETC_TXBD_FINAL_MASK             (0x80000000UL) /*!< TX final mask.*/
#define NETC_TXBD_EXTENDED_BUFFER_MASK   (0x40000000UL) /*!< TX extended buffer mask.*/
#define NETC_TXBD_WRITTEN_MASK           (0x08000000UL) /*!< TX written mask.*/

#define NETC_RXBD_FINAL_MASK             (0x80000000UL) /*!< RX final mask.*/

#define Netc_EthSwt_Ip_PortBaseType      SW_ETH_MAC_PORT0_Type  /*!< Port base type.*/
#define Netc_EthSwt_Ip_PseudoPortBaseType      SW_PSEUDO_MAC_PORT2_Type  /*!< Pseudo base type.*/

#define FEATURE_NETC_ETHSWT_IP_NUMBER_OF_SWTS	(1U) /*!< Number of switchs.*/

#define NETC_ETHSWT_IP_TABLE_REQBUFFER_LEN   (48U)     /*!< the length of request data buffer in bytes for FDB and other small tables */
#define NETC_ETHSWT_IP_TABLE_RESBUFFER_LEN   (36U)     /*!< 36 bytes is buffer lenth*/

#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_REQBUFFER_LEN   (8U)      /*!< the length of request data buffer in bytes for Egress Count table, this size has to be 8 bytes. */
#define NETC_ETHSWT_IP_EGRESSCOUNTTABLE_RSPBUFFER_LEN   (20U)     /*!< the length of response data buffer in bytes for Egress Count table */

#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN   (224U)     /*!< the length of response data buffer in bytes for Ingress Port Filter table */
#define NETC_ETHSWT_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN   (236U)     /*!< the length of response data buffer in bytes for Ingress Port Filter table */

/* The maximum number of gate control list */
#define NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES              (8U)
#define NETC_ETHSWT_IP_TABLEDATA_BUFFER_LENGTH  ((236)/4)

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

#endif /* NETC_ETHSWT_IP_CFG_DEFINES_H */
