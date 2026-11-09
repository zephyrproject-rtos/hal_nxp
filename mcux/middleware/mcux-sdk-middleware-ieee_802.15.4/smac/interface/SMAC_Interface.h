/*! *********************************************************************************
* Copyright (c) 2004 - 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2024,2026 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef SMAC_INTERFACE_H_
#define SMAC_INTERFACE_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"
#include "PhyTypes.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef gSmacUseExtendedAddr_c
#define gSmacUseExtendedAddr_c     (0)
#endif

#ifndef gEnhAckMode8
#define gEnhAckMode8                (0)
#endif

#define gSmacHeaderBytes_c	   ( sizeof(smacHeader_t) )

#if !gSmacUseSecurity_c
#define gMaxSmacSDULength_c        (gMaxPHYPacketSize_c -(sizeof(smacHeader_t) + 2) )
#else
#define gMaxSmacSDULength_c        (gMaxPHYPacketSize_c -(sizeof(smacHeader_t) + 2) - 16)
#endif

#define gMinSmacSDULength_c	   (0)

#define gNodeAddress_c         (0xBEAD)
#define gDefaultPanID_c        (0xFACE)
#define gBroadcastAddress_c	   (0xFFFF)

#if gSmacUseExtendedAddr_c
 #define gSmacDefaultFrameCtrl_c   (0xCC41)
#else
 #define gSmacDefaultFrameCtrl_c   (0x8841)
#endif

#define gSmacDefaultSeqNo_c        (0xAC)

/* -------------------------------------------------------------------------- */
/*                               Public memory                                */
/* -------------------------------------------------------------------------- */

extern uint8_t gTotalChannels;

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

typedef uint16_t address_size_t;

typedef enum smacMessageDefs_tag
{
    gMcpsDataCnf_c,
    gMcpsDataInd_c,
    gMlmeCcaCnf_c,
    gMlmeEdCnf_c,
    gMlmeSetReq_c,
    gMlmeSetCnf_c,
    gMlmeTimeoutInd_c,
    gMlme_UnexpectedRadioResetInd_c
} smacMessageDefs_t;

typedef uint64_t smacTime_t;

typedef struct smacPdu_tag
{
    uint8_t smacPdu[1];
} smacPdu_t;

typedef PACKED_STRUCT smacHeader_tag
{
    uint16_t frameControl;
    uint8_t seqNo;
#if !gEnhAckMode8
    address_size_t   panId;
#endif
#if gSmacUseExtendedAddr_c
    uint64_t        destAddr;
    uint64_t        srcAddr;
#else
    address_size_t  destAddr;
    address_size_t  srcAddr;
#endif  
} smacHeader_t;

typedef struct txPacket_tag
{
    uint8_t u8DataLength;
    smacHeader_t smacHeader;
    smacPdu_t smacPdu;
} txPacket_t;

typedef struct txContextConfig_tag
{
    bool_t ccaBeforeTx;
    bool_t autoAck;
    bool_t enhAck;
    uint8_t retryCountCCAFail;
    uint8_t retryCountAckFail;
} txContextConfig_t;

typedef enum rxStatus_tag
{
    rxInitStatus,
    rxProcessingReceptionStatus_c,
    rxSuccessStatus_c,
    rxTimeOutStatus_c,
    rxAbortedStatus_c,
    rxMaxStatus_c
} rxStatus_t;

typedef struct rxPacket_tag
{
    uint8_t      u8MaxDataLength;
    uint8_t      u8DataLength;
    rxStatus_t   rxStatus;
    smacHeader_t smacHeader;
    smacPdu_t    smacPdu;
} rxPacket_t;

typedef enum smacErrors_tag
{
    gErrorNoError_c = 0,
    gErrorBusy_c,
    gErrorChannelBusy_c,
    gErrorNoAck_c,
    gErrorOutOfRange_c,
    gErrorNoResourcesAvailable_c,
    gErrorNoValidCondition_c,
    gErrorCorrupted_c,
    gErrorMaxError_c
} smacErrors_t;

typedef enum channels_tag
{
    gChannel11_c = 0x0B,
    gChannel12_c,
    gChannel13_c,
    gChannel14_c,
    gChannel15_c,
    gChannel16_c,
    gChannel17_c,
    gChannel18_c,
    gChannel19_c,
    gChannel20_c,
    gChannel21_c,
    gChannel22_c,
    gChannel23_c,
    gChannel24_c,
    gChannel25_c,
    gChannel26_c,
    gChannelInvalid_c,
} channels_t;

typedef enum smacTestMode_tag
{
    gTestModeForceIdle_c = 0,
    gTestModeContinuousTxModulated_c,
    gTestModeContinuousTxUnmodulated_c,
    gTestModePRBS9_c,
    gTestModeContinuousRxBER_c,
    gMaxTestMode_c
} smacTestMode_t;

typedef  struct smacDataCnf_tag
{
    smacErrors_t status;
} smacDataCnf_t;

typedef  struct smacDataInd_tag
{
    uint8_t     u8LastRxRssi;
    rxPacket_t *pRxPacket;
} smacDataInd_t;

typedef  struct smacCcaCnf_tag
{
    smacErrors_t status;
} smacCcaCnf_t;

typedef struct smacEdCnf_tag
{
    smacErrors_t status;
    uint8_t      energyLevel;
    uint8_t      energyLeveldB;
    channels_t   scannedChannel;
} smacEdCnf_t;

typedef struct smacToAppMlmeMessage_tag
{
    smacMessageDefs_t msgType;
    uint8_t           appInstanceId;

    union
    {
        smacCcaCnf_t ccaCnf;
        smacEdCnf_t  edCnf;
    } msgData;

} smacToAppMlmeMessage_t;

typedef struct smacToAppDataMessage_tag
{
    smacMessageDefs_t msgType;
    uint8_t           appInstanceId;

    union
    {
        smacDataCnf_t   dataCnf;
        smacDataInd_t   dataInd;
    } msgData;

} smacToAppDataMessage_t;

typedef smacErrors_t ( * SMAC_APP_MCPS_SapHandler_t)(smacToAppDataMessage_t * pMsg, instanceId_t instanceId);

typedef smacErrors_t ( * SMAC_APP_MLME_SapHandler_t)(smacToAppMlmeMessage_t * pMsg, instanceId_t instanceId);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Registers the data and management callbacks to the application
 *
 * After calling this function and providing two function pointers, SMAC will call
 * one of these two, for each async request, based on request type (data or management)
 * Interface assumptions: the SMAC and radio driver have been initialized and are ready
 * to be used.
 *
 * \param[in] pSMAC_APP_MCPS_SapHandler pointer to the data application callback
 * \param[in] pSMAC_APP_MLME_SapHandler pointer to the management application callback
 * \param[in] smacInstanceId the SMAC instance these callbacks apply to
 * \return none
 */
void Smac_RegisterSapHandlers(SMAC_APP_MCPS_SapHandler_t pSMAC_APP_MCPS_SapHandler,
                              SMAC_APP_MLME_SapHandler_t pSMAC_APP_MLME_SapHandler,
                              instanceId_t smacInstanceId);

/*!
 * \brief Initialize SMAC layer
 *
 * \param[in] phy_context_id the ID of the phy that is going to server this SMAC instance.
 */
void InitSmac(instanceId_t phy_context_id);

/*!
 * \brief Send a packet over the air
 *
 * This is an asyncronous function: after returning from it the request is queued but
 * the packet may not be sent yet.
 *
 * \param[in] psTxPacket pointer to the packet data
 * \return gErrorNoError_c: everything is ok and the transmission will be performed.
 * \return gErrorOutOfRange_c: one of the members of the packet is out of range.
 * \return gErrorNoResourcesAvailable_c: the radio is performing another action.
 * \return gErrorNoValidCondition_c: the SMAC has not been initialized
 */
smacErrors_t MCPSDataRequest(txPacket_t *psTxPacket);

/*!
 * \brief Returns the radio to idle mode from Tx mode.
 *
 */
void MLMETXDisableRequest(void);

/*!
 * \brief Place the radio in receive mode
 *
 * \param[out] gsRxPacket pointer to the structure where the reception results will be stored
 * \param[in]  stTimeout: 64-bit timeout value, absolute time in symbols
 * \return gErrorNoError_c: Success
 * \return gErrorOutOfRange_c: no valid bufer size or data buffer pointer is NULL.
 * \return gErrorBusy_c: the radio is performing another action.
 * \return gErrorNoValidCondition_c: The SMAC has not been initialized.
 */
smacErrors_t MLMERXEnableRequest(rxPacket_t *gsRxPacket, smacTime_t stTimeout);

/*!
 * \brief Returns the radio to idle mode from receive mode.
 *
 * \return gErrorNoError_c: Success
 * \return gErrorNoValidCondition_c If the Radio is not in Rx state.
 */
smacErrors_t MLMERXDisableRequest(void);

/*!
 * \brief Set the radio's channel
 *
 * \param[in] newChannel: the channel to be set
 * \return gErrorNoError_c
 * \return gErrorOutOfRange_c: channel requested is not valid
 * \return gErrorBusy_c: SMAC is busy doing Tx/Rx or doing channel scan
 */
smacErrors_t MLMESetChannelRequest (channels_t newChannel);

/*!
 * \brief return the current channel, if an error is detected it returns gChannelOutOfRange_c.
 *
 * \return the channel
 * \return gChannelOutOfRange_c in case of error
 */
channels_t MLMEGetChannelRequest(void);

/*!
 * \brief Set the radio's short address
 *
 * \param[in] nwShortAddress: the address to be set
 * \return gErrorNoError_c
 * \return gErrorBusy_c Radio busy doing Rx/Tx
 * \return gErrorNoResourcesAvailable_c Radio is not available
 */
smacErrors_t SMACSetShortSrcAddress(address_size_t nwShortAddress);

/*!
 * \brief Set the radio's extended address
 *
 * \param[in] nwExtendedAddress: the address to be set
 * \return gErrorNoError_c
 * \return gErrorBusy_c Radio is busy doing Rx/Tx
 * \return gErrorNoResourcesAvailable_c Radio is not available
 */
smacErrors_t SMACSetExtendedSrcAddress(uint64_t nwExtendedAddress);

/*!
 * \brief Set the radio's pan-id
 *
 * \param[in] nwShortPanId: the pan-id
 * \return gErrorNoError_c
 * \return gErrorBusy_c Radio is busy doing Rx/Tx
 * \return gErrorNoResourcesAvailable_c Radio is not available
 */
smacErrors_t SMACSetPanID(address_size_t nwShortPanID);

/*!
 * \brief Set the Power Amplifier's power
 *
 * \param[in] u8PaValue: the output power
 * \return gErrorNoError_c
 * \return gErrorBusy_c Radio is busy doing Rx/Tx
 * \return gErrorOutOfRange_c power value is out of range
 */
smacErrors_t MLMEPAOutputAdjust(uint8_t u8PaValue);

/*!
 * \brief returns the link quality from the last received packet.
 *
 * This  function  returns  an  integer  value  that is the link quality from the last
 * received packet of the form:  dBm = (-Link Quality/2).
 *
 * \return 8 bit value representing the link quality value in dBm.
 */
uint8_t MLMELinkQuality(void);

/*!
 * \brief This function performs a software reset on the radio, PHY and SMAC state machines.
 *
 * \return gErrorNoError_c
 * \return gErrorNoValidCondition_c SMAC is not initialized
 */
smacErrors_t MLMEPhySoftReset(void);

/*!
 * \brief Scan the channel passed as parameter using ED mode and return the RSSI
 *
 * \param[in] u8channeltoscan: the channel
 * \return gErrorNoError_c
 * \return gErrorBusy_c Radio busy doing Rx/Tx
 * \return gErrorNoValidCondition_c SMAC is not initialized
 * \return gErrorNoResourcesAvailable_c Radio is not available
 */
smacErrors_t MLMEScanRequest(channels_t u8ChannelToScan);

/*!
 * \brief Perform Clear Channel Assessment on the active channel
 *
 * \return gErrorNoError_c
 * \return gErrorBusy_c Radio busy doing Rx/Tx
 * \return gErrorNoValidCondition_c SMAC is not initialized
 * \return gErrorNoResourcesAvailable_c Radio is not available
 */
smacErrors_t MLMECcaRequest();

/*!
 * \brief Enable/Disable Auto Acknoledgement
 */
void SMACSetTxAutoAck(bool_t enable);

/*!
 * \brief Enable/Disable Enhanced Acknoledgement
 */
void SMACSetTxEnhAck(bool_t enable);

/*!
 * \brief Fills the SMAC header (short hardcoded MAC header) with the desired short
 * destination address.
 *
 * \param[out] pSmacHeader: the channel
 * \param[in]  destAddr: the channel
 */
void SMACFillHeader(smacHeader_t* pSmacHeader, address_size_t destAddr);


#endif /* SMAC_INTERFACE_H_ */
