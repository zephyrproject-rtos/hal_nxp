/*! *********************************************************************************
* \defgroup PhyTypes PHY Data Types
* @{
********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2025 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _PHY_TYPES_H
#define _PHY_TYPES_H

#if defined(__ARMCC_VERSION)
#pragma push
#pragma anon_unions
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined(__IAR_SYSTEMS_ICC__)
#pragma language=extended
#else
#error Not supported compiler type
#endif

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#include "EmbeddedTypes.h"

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

/*! This define is used to set the number of symbols per octet for the current PHY. */
#define gPhySymbolsPerOctet_c     (2u)
/*! The duration of the Clear Channel Assessment (in symbols) */
#define gCCATime_c                8u
/*! RX-to-TX or TX-to-RX maximum turnaround time (in symbols) */
#define gPhyTurnaroundTime_c      12u
/*! Maximum number of bytes that the PHY can transmit or receive */
#define gMaxPHYPacketSize_c       (127u)
/*! This define is used to set the duration of the synchronization header [symbols] */
#define gPhySHRDuration_c         (10u)
/*! This define is used to set the duration of the PHY header (PHR) (in symbols) */
#define gPhyPHRDuration_c         (1u * gPhySymbolsPerOctet_c)
/*! Number of bytes forming the CRC field */
#define gPhyFCSSize_c             (2u)
/*! The maximum over-the-air duration of a frame (in symbols) */
#define gPhyMaxFrameDuration_c    (gPhySHRDuration_c + (gMaxPHYPacketSize_c + 1) * gPhySymbolsPerOctet_c)
/*! The duration of a Back-off period (in symbols) */
#define gUnitBackoffPeriod_c      (20u)

/*! PHY flag that reflects the state of the RxOnWhenIdle function */
#define gPhyFlagRxOnWhenIdle_c  (1u << 0)
/*! PHY flag that indicate that an automatic RX sequence is ongoing */
#define gPhyFlagIdleRx_c        (1u << 1)
/*! PHY flag that reflects the state of the FP bit of the last ACK frame received */
#define gPhyFlagRxFP_c          (1u << 2)
/*! PHY flag that reflects the state of the FP bit of the last ACK frame transmitted */
#define gPhyFlagTxAckFP_c       (1u << 3)
/*! If set, a TX operation may be postponed if a packet reception is in progress */
#define gPhyFlagDeferTx_c       (1u << 4)
/*! PHY flag that indicate that the requested TX has been postponed */
#define gPhyFlaqReqPostponed_c  (1u << 5)
/*! PHY flag that indicate CSL RX: allow multipurpose frames, send Enh-ACKs */
#define gPhyFlagCslRx_c         (1u << 6)
/*! PHY flag that indicates FP was set as result of no neighbour table entry found */
#define gPhyFlagNbTblRxAckFP_c  (1u << 7)


/*! This constant defines the identification value of an invalid timer. */
#define gInvalidTimerId_c (0xFF)

#define gPhyTimeShift_c   (24)          /* 24bit hw timer */
#define gPhyTimeMask_c    (0x00FFFFFF)

/* Security defines */
#ifndef gSmacUseInlineDecrypt
#define gSmacUseInlineDecrypt       (0)
#else
#define gSmacUseSecurity_c          (1)
#endif

#ifndef gSmacUseSecurity_c
#define gSmacUseSecurity_c         (0)
#endif

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

/*! This type enumerates all the possible statuses of primitives that require passing a status to the MAC Layer. */
typedef enum
{
    gPhyChannelBusy_c          = 0x00,    /*!< The CCA attempt has detected a busy channel.*/
    gPhyBusyRx_c               = 0x01,    /*!< The transceiver is asked to change its state while receiving.*/
    gPhyBusyTx_c               = 0x02,    /*!< The transceiver is asked to change its state while transmitting.*/
    gPhyChannelIdle_c          = 0x04,    /*!< The CCA attempt has detected an idle channel.*/
    gPhyInvalidParameter_c     = 0x05,    /*!< A SET request was issued with a parameter in the primitive that is out of the valid range.*/
    gPhyRxOn_c                 = 0x06,    /*!< The transceiver is in the receiver enabled state.*/
    gPhySuccess_c              = 0x07,    /*!< A SET/GET, an ED operation, a data request, an indirect queue insert, or a transceiver state change was successful.*/
    gPhyTRxOff_c               = 0x08,    /*!< The transceiver is in the transceiver disabled state.*/
    gPhyTxOn_c                 = 0x09,    /*!< The transceiver is in the transmitter enabled state.*/
    gPhyUnsupportedAttribute_c = 0x0a,    /*!< A SET/GET request was issued with the identifier of an attribute that is not supported.*/
    gPhyReadOnly_c             = 0x0b,    /*!< A SET request was issued with the identifier of an attribute that is read-only.*/
    gPhyIndexUsed_c            = 0x11,    /*!< The indirect queue insert operation has detected an used index.*/
    gPhyNoAck_c                = 0x14,    /*!< No ACK was received for the last transmission.*/
    gPhyFramePending_c         = 0x15,    /*!< The ACK of a Data Request frame indicates a pending frame in the coordinator's indirect TX queue.*/
    gPhyBusy_c                 = 0xF1,    /*!< The current request cannot be handled, because the PHY is busy. */
    gPhyInvalidPrimitive_c     = 0xF2,    /*!< The set was not completed, because the primitive is not in the valid range. */
    gPhyPendingOp                         /* dual PAN scheduler state */
} phyStatus_t;

/*! This type is used to indicate, whether the CCA type operations are required before the transmissions, and together with phySlottedTx_t to determine, whether there are more than one needed. */
typedef enum
{
    gPhyEnergyDetectMode_c = 0x00,
    gPhyCCAMode1_c         = 0x01, /*!< Energy above a threshold */
    gPhyCCAMode2_c         = 0x02, /*!< Carrier sense only */
    gPhyCCAMode3_c         = 0x03, /*!< CCA mode 1 + CCA mode 2 */
    gPhyNoCCABeforeTx_c    = 0x04
}phyCCAType_t;

/*! This type is used to indicate, whether the CCA3 mode operations are required before the transmissions. */
typedef enum
{
    gPhyCCAMode3_OR_c      = 0x00, /*!< CCA mode 1 OR CCA mode 2 */
    gPhyCCAMode3_AND_c     = 0x01  /*!< CCA mode 1 AND CCA mode 2 */
}phyCCA3Mode_t;

typedef enum
{
    gPhyContCcaEnabled     = 0x00,
    gPhyContCcaDisabled
}phyContCCAMode_t;

/*! This type is used to enumerate the possible states to set the transceiver to. \
    Setting the transceiver into any Tx state is done by issuing pdDataReq_t that does not use this type for any member. */
typedef enum
{
    gPhyForceTRxOff_c = 0x03,              /*!< The transceiver is to be switched off immediately.*/
    gPhySetRxOn_c     = 0x12,              /*!< The transceiver is to be configured into the receiver enabled state.*/
} phyState_t;

/*! This type is used to filter the next received frames, and to accept only Ack frames. */
typedef enum
{
    gPhyRxAckRqd_c     = 0x00,             /*!< A receive Ack frame is expected to follow the transmit frame (non-Ack frames are rejected)*/    
    gPhyNoAckRqd_c     = 0x01,             /*!< An ordinary receive frame (any type of frame) follows the transmit frame*/
    gPhyEnhancedAckReq = 0x02
}phyAckRequired_t;

typedef enum
{
    gPhyEncFrame = 0x1,     /* encrypt frame */
    gPhyUpdHDr   = 0x2      /* updated header with frame counter */
} phyTxFlags;

typedef enum {
    gPhyRxAckFpIndirect    = 0x0, /* ACK FP was set due to entries being in SAP, indirect packet available. */
    gPhyRxAckFpNoNeighbour = 0x1  /* ACK FP was set due to entries not being in SAA, no neighbours. */
} phyRxAckFpReason_t;

/*! This type enumerates all PHY PIB IDs. 
    The PIBs can be read and written to by the upper layer, and are used to configure certain parameters and modes of operation for the PHY Layer. 
    The PIBs that refer to physical parameters, such as carrier frequency or transmission power, are usually mirrored in hardware, but in case the 
    IEEE 802.15.4 hardware acceleration is used, there are protocol-oriented PIBs also stored in hardware, such as addresses, PAN ID, promiscuous mode setting, and so on. */
typedef enum
{
    gPhyPibCurrentChannel_c  = 0x00,       /*!< The channel currently used.*/
    gPhyPibCurrentPage_c     = 0x01,       /*!< The channel page currently used.*/
    gPhyPibTransmitPower_c   = 0x02,       /*!< The power used for TX operations.*/
    gPhyPibLongAddress_c     = 0x03,       /*!< The MAC long address to be used by the PHY's source address matching feature.*/
    gPhyPibShortAddress_c    = 0x04,       /*!< The MAC short address to be used by the PHY's source address matching feature.*/
    gPhyPibPanId_c           = 0x05,       /*!< The MAC PAN ID to be used by the PHY's source address matching feature.*/
    gPhyPibPanCoordinator_c  = 0x06,       /*!< Indicates if the device is a PAN coordinator or not.*/
    gPhyPibSrcAddrEnable_c   = 0x07,       /*!< Enables or disables the PHY's source address matching feature.*/
    gPhyPibPromiscuousMode_c = 0x08,       /*!< Selects between normal, promiscuous and active promiscuous mode.*/
    gPhyPibAutoAckEnable_c   = 0x09,       /*!< Enables or disables automatic transmission of ACK frames.*/
    gPhyPibFrameVersion_c    = 0x0A,       /*!< Used in checking for allowed frame versions (0x00 - any version accepted, 0x01 - accept Frame Version 0 packets (2003 compliant), 0x02 - accept Frame Version 1 packets (2006 compliant), 0x03 - accept Frame Version 0 and 1 packets).*/
    gPhyPibFrameEnable_c     = 0x0B,       /*!< Used for enabling or disabling reception of MAC frames.*/
    gPhyPibAckFramePending_c = 0x0C,       /*!< Used to copy its contents to the outgoing ACK frame's Frame Pending field as a response to a received Data Request frame with Source Address Matching disabled.*/
    gPhyPibRxOnWhenIdle      = 0x0D,       /*!< Enable RX when the radio is IDLE*/  
    gPhyPibFrameWaitTime_c   = 0x0E,       /*!< The number of symbols the RX should be on after receiving an ACK with FP=1 */
    gPhyPibDeferTxIfRxBusy_c = 0x0F,       /*!< If a packet is being received, transmission is deferred */
    gPhyPibLastTxAckFP_c     = 0x10,       /*!< Indicates, whether the last ACK sent to the MAC Data Request had the frame pending flag set. */
    gPhyPibCCAType_c         = 0x11,       /*!< Set the CCA3 Type */
    gPhyPibCCA3Mode_c        = 0x12,       /*!< Determines the way CCA3 is required to be detected, "CCA1 and CCA2" or "CCA1 or CCA2". */
    gPhyPibCcaConfig_c       = 0x13,       /*!< Used to configure the CCA dynamically. */
    gPhyPibCSLRxEnabled_c    = 0x24,       /*!< Enable or disable the CSL mode for the RX sequences.  */

    gPhyGetRSSILevel_c,

    gPhyGetCtxId
} phyPibId_t;

typedef union phyFlags_tag
{
    uint32_t mask;
    struct{
        uint32_t     rxOnWhenIdle            :1;
        uint32_t     rxFramePending          :1;
        uint32_t     idleRx                  :1;
        uint32_t     phyState                :3;
        uint32_t     reserved                :26;
    };
}phyFlags_t;

/*!< PHY Time event Id */
typedef uint8_t  phyTimeTimerId_t;
/*!< PHY Time time-stamp */
typedef uint64_t phyTime_t;
/*!< PHY Time event callback type */
typedef void (*phyTimeCallback_t) ( uint32_t param );

typedef enum
{
    gPhyTimeOk_c               = 0x00, /*!< The request was performed successfully */
    gPhyTimeAlreadyPassed_c    = 0x01, /*!< Requested time for event trigger has already passed */
    gPhyTimeTooClose_c         = 0x02, /*!< Requested time for event trigger is too close to the current time to be processed */
    gPhyTimeTooMany_c          = 0x03, /*!< Too many requests have been addressed */
    gPhyTimeInvalidParameter_c = 0x04, /*!< The request was performed with an invalid parameter */
    gPhyTimeNotFound_c         = 0x05, /*!< The requested timer was not found */
    gPhyTimeError_c            = 0x06  /*!< The request encountered a hardware error */
}phyTimeStatus_t;


#if defined(__ARMCC_VERSION)
#pragma pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__IAR_SYSTEMS_ICC__)
#pragma language=default
#else
#error Not supported compiler type
#endif

#endif  /* _PHY_TYPES_H */
/*! *********************************************************************************
* @}
********************************************************************************** */
