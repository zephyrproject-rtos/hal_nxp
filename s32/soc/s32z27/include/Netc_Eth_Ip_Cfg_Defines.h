/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_CFG_DEFINES_H
#define NETC_ETH_IP_CFG_DEFINES_H

/**
*   @file Netc_Eth_Ip_Cfg_Defines.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
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
#include "S32Z2_ENETC_PORT.h"
#include "S32Z2_NETC_F3_SI0.h"
#include "S32Z2_NETC_F3_SI1.h"
#include "S32Z2_NETC_F3_SI2.h"
#include "S32Z2_NETC_F3_SI3.h"
#include "S32Z2_NETC_F3_SI4.h"
#include "S32Z2_NETC_F3_SI5.h"
#include "S32Z2_NETC_F3_SI6.h"
#include "S32Z2_NETC_F3_SI7.h"

#include "S32Z2_NETC_VF1_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_VF2_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_VF3_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_VF4_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_VF5_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_VF6_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_VF7_PCI_HDR_TYPE0.h"

#include "S32Z2_NETC_F3.h"
#include "S32Z2_NETC_F0_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_F1_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_F2_PCI_HDR_TYPE0.h"
#include "S32Z2_NETC_F3_PCI_HDR_TYPE0.h"
#include "S32Z2_ENETC_PORT.h"
#include "S32Z2_NETC_F3_COMMON.h"

#include "S32Z2_TMR0_BASE.h"
#include "S32Z2_SW_ETH_MAC_PORT0.h"
#include "S32Z2_SW_ETH_MAC_PORT1.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_CFG_DEFINES_VENDOR_ID                    43
#define NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_CFG_DEFINES_SW_MAJOR_VERSION             0
#define NETC_ETH_IP_CFG_DEFINES_SW_MINOR_VERSION             9
#define NETC_ETH_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (NETC_ETH_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Cfg_Defines.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/** TODO: This must be generated in function of what user is using in configuration.
 *        LIMITATION: must be multiple of 8.
 */
/** @brief Total number of command BDRs. */
#define NETC_ETH_IP_COMMAND_BDR_LENGTH          (8U)

/** @brief Development error enable/disable. */
#define NETC_ETH_IP_DEV_ERROR_DETECT            (STD_OFF)
/*! @brief Extended buffer support enable/disable */
#define NETC_ETH_IP_EXTENDED_BUFF            (STD_OFF)

/** @brief Minimum number of bytes supported by a frame. */
#define NETC_ETH_IP_MIN_FRAME_LENGTH         (16U)

/** @brief Number of traffic classes. */
#define NETC_ETH_IP_NUMBER_OF_PRIORITIES        (8U)

/** @brief TX buffer descriptor final bit mask. */
#define NETC_ETH_IP_TXBD_FINAL_MASK             (0x80000000UL)
/** @brief TX buffer descriptor extended bit mask. */
#define NETC_ETH_IP_TXBD_EXTENDED_BUFFER_MASK   (0x40000000UL)
/** @brief TX buffer descriptor writeback bit mask. */
#define NETC_ETH_IP_TXBD_WRITEBACK_MASK         (0x04000000UL)
/** @brief TX buffer descriptor frame interrupt bit mask. */
#define NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK   (0x20000000UL)

/** @brief TX frame buffer interrupt enable bit mask. */
#define NETC_ETH_IP_TBIER_TXFIE_MASK            (0x00000002UL)

/** @brief TX threshold(coalescing) interrupt enable bit mask. */
#define NETC_ETH_IP_TBIER_TXTIE_MASK            (0x00000001UL)

/* RX buffer descriptor information. */
/** @brief RX buffer descriptor priority code point mask. */
#define NETC_ETH_IP_RXBD_PCP_MASK               (0xE0000000UL)
/** @brief RX buffer descriptor priority code point shift value. */
#define NETC_ETH_IP_RXBD_PCP_SHIFT              (29UL)
/** @brief RX buffer descriptor drop eligible indicator mask. */
#define NETC_ETH_IP_RXBD_DEI_MASK               (0x10000000UL)
/** @brief RX buffer descriptor drop eligible indicator shift value. */
#define NETC_ETH_IP_RXBD_DEI_SHIFT              (28UL)
/** @brief RX buffer descriptor VLAN identifier mask. */
#define NETC_ETH_IP_RXBD_VID_MASK               (0x0FFF0000UL)
/** @brief RX buffer descriptor VLAN identifier shift value. */
#define NETC_ETH_IP_RXBD_VID_SHIFT              (16UL)
/** @brief RX buffer descriptor VLAN tag protocol identifier mask. */
#define NETC_ETH_IP_RXBD_TPID_MASK               (0x00000003UL)
/** @brief RX buffer descriptor final mask. */
#define NETC_ETH_IP_RXBD_FINAL_MASK             (0x80000000UL)
/** @brief RX buffer descriptor ready mask. */
#define NETC_ETH_IP_RXBD_READY_MASK             (0x40000000UL)
/** @brief RX buffer descriptor length mask. */
#define NETC_ETH_IP_RXBD_LENGTH_MASK            (0x0000FFFFUL)
/** @brief RX buffer descriptor error mask. */
#define NETC_ETH_IP_RXBD_ERROR_MASK             (0x00FF0000UL)
/** @brief RX buffer descriptor error shift value. */
#define NETC_ETH_IP_RXBD_ERROR_SHIFT            (16UL)
/** @brief RX buffer descriptor L4 flag mask. */
#define NETC_ETH_IP_RXBD_L4_FLAG_MASK           (0x00001000UL)
/** @brief RX buffer descriptor L3 flag mask. */
#define NETC_ETH_IP_RXBD_L3_FLAG_MASK           (0x00000800UL)
/** @brief RX buffer descriptor timespamp flag mask. */
#define NETC_ETH_IP_RXBD_TIMESTAMP_FLAG_MASK    (0x00000400UL)
/** @brief RX buffer descriptor VLAN head flag mask. */
#define NETC_ETH_IP_RXBD_VLAN_HEAD_FLAG_MASK    (0x00000200UL)
/** @brief RX buffer descriptor host reason mask. */
#define NETC_ETH_IP_RXBD_HOST_REASON_MASK       (0x0000003CUL)
/** @brief RX buffer descriptor host reason shift value. */
#define NETC_ETH_IP_RXBD_HOST_REASON_SHIFT            (2UL)
/** @brief Receive threshold interrupt enable mask. */
#define NETC_ETH_IP_RBIER_RXTIE_MASK            (0x00000001UL)

/** @brief Station interface(SI) type. */
#define Netc_Eth_Ip_SiBaseType               NETC_F3_SI0_Type

/** @brief Virtual station interface(VSI) type. */
#define Netc_Eth_Ip_VsiBaseType              NETC_F3_SI1_Type

/** @brief Virtual function(VF) type */
#define Netc_Eth_Ip_VfBaseType               NETC_F1_PCI_HDR_TYPE0_Type

/** @brief ENETC function struct type. */
#define Netc_Eth_Ip_EnetcBaseType            NETC_F3_Type

/* Descriptor options for normal buffer. */
/** @brief Flags shift value. */
#define NETC_ETH_IP_FL_SHIFT                 (27U)
/** @brief This field contains the only Flags Qualifier setting supported by NETCv3. */
/* It is used as a value because is the only one supported. If the next version support more, code will be updated. */
#define NETC_ETH_IP_FLQ_VALUE                (0x02U)
/** @brief Flags Qualifier shift value. */
#define NETC_ETH_IP_FLQ_SHIFT                (24U)
/** @brief Switch Management Sending Options shift value. */
#define NETC_ETH_IP_SMSO_SHIFT               (23U)
/** @brief Ingress/Egress switch port number this frame is to be injected towards/to be transmitted shift value. */
#define NETC_ETH_IP_INGR_EGRESS_PORT_SHIFT   (16U)
/** @brief Timestamp Reference Request shift value. */
#define NETC_ETH_IP_TSR_SHIFT                (22U)
/** @brief Internal Priority Value shift value. */
#define NETC_ETH_IP_IPV_SHIFT                (12U)
/** @brief Discard Resilience shift value. */
#define NETC_ETH_IP_DR_SHIFT                 (10U)

/* TX write-back fields. */
#define NETC_ETH_IP_HOSTREASON_WB_MASK       (0x0000003CUL)
#define NETC_ETH_IP_HOSTREASON_REGULAR_FRAME (0x00000000UL)
#define NETC_ETH_IP_HOSTREASON_TIMESTAMP     (0x0000000CUL)
#define NETC_ETH_IP_TX_WB_STATUS_MASK        (0x01FFU)

/* Descriptor options for extended buffer. */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    /** @brief Priority code point shift value. */
    #define NETC_ETH_IP_PCP_SHIFT                (29U)
    /** @brief Priority code point bit mask. */
    #define NETC_ETH_IP_PCP_MASK                 (0xE0000000UL)
    /** @brief Drop eligible indicator shift value. */
    #define NETC_ETH_IP_DEI_SHIFT                (28U)
    /** @brief Drop eligible indicator bit mask. */
    #define NETC_ETH_IP_DEI_MASK                 (0x10000000UL)
    /** @brief VLAN identifier shift value. */
    #define NETC_ETH_IP_VID_SHIFT                (16U)
    /** @brief VLAN identifier bit mask. */
    #define NETC_ETH_IP_VID_MASK                 (0x0FFF0000UL)
    /** @brief Tag protocol identifier shift value. */
    #define NETC_ETH_IP_TPID_SHIFT               (14U)
    /** @brief Tag protocol identifier bit mask. */
    #define NETC_ETH_IP_TPID_MASK                (0x0000C000UL)
    /** @brief Extension flags shift value. */
    #define NETC_ETH_IP_E_FLAGS_SHIFT            (16U)
    /** @brief Extension flags bit mask. */
    #define NETC_ETH_IP_E_FLAGS_MASK             (0x00FF0000UL)
#endif

/* VSI-to-PSI message used defines. */
/** @brief Define the bit used by VSI-to-PSI messaging to show if the process is still in progress. */
#define NETC_ETH_IP_VSI_MSG_PROGRESS_STATUS      (0x00000001UL)
/** @brief Define the bit used to show the message status. */
#define NETC_ETH_IP_VSI_MSG_STATUS               (0x00000002UL)
/** @brief Define used to code the 32 bytes message. */
#define NETC_ETH_IP_VSITOPSI_MSG_SIZE            (0x00000001UL)

#define NETC_ETH_IP_VLAN_SUPPORT          (STD_ON)
/*! @brief Enables/Disables internal cache management */
#define  NETC_ETH_IP_HAS_CACHE_MANAGEMENT       (STD_OFF)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* NETC_ETH_IP_CFG_DEFINES_H */
