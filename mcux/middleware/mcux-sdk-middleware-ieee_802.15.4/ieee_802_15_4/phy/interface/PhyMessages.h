/*! *********************************************************************************
* \defgroup PhyMessages PHY Messages
* @{
********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2017, 2024-2025 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _PHY_MESSAGES_H
#define _PHY_MESSAGES_H

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

/*! 802.15.4-2006 standard PHY PD and PLME API messages */
typedef enum
{
    gPdDataReq_c,           /*!< Data Request */
    gPdDataCnf_c,           /*!< Data Confirm */
    gPdDataInd_c,           /*!< Data Indication */

    gPdIndQueueInsertReq_c, /*!< Insert checksum into indirect table */
    gPdIndQueueInsertCnf_c, /*!< Unused */
    gPdIndQueueRemoveReq_c, /*!< Remove checksum from indirect table */

    gPlmeCcaReq_c,          /*!< Clear Channel Assessment request */
    gPlmeCcaCnf_c,          /*!< Clear Channel Assessment confirm */

    gPlmeEdReq_c,           /*!< Channel Energy Detect request */
    gPlmeEdCnf_c,           /*!< Channel Energy Detect Confirm */

    gPlmeSetTRxStateReq_c,  /*!< Set Transceiver State request */

    gPlmeSetReq_c,          /*!< Set PHY PIB request */
    gPlmeSetCnf_c,          /*!< Unused */

    gPlmeGetReq_c,          /*!< Get PHY PIB request */
    gPlmeGetCnf_c,          /*!< Unused */

    gPlmeTimeoutInd_c,      /*!< PHY sequence time-out indication */

    gPlme_StartEventInd_c,  /*!< PHY sequence start indication */
    gPlme_SyncLossInd_c,    /*!< PHY synchronisation lost indication */
    gPlme_RxSfdDetectInd_c, /*!< Receiver SFD indication */
    gPlme_FilterFailInd_c,  /*!< Receiver Filtering Fail indication */
    gPlme_UnexpectedRadioResetInd_c, /*!< XCVR reset */

    gPlmeAbortInd_c,      /*!< PHY sequence Abort indication */

    gPlmeSetSAMState_c,
    gPlmeAddToSapTable_c,
    gPlmeRemoveFromSAMTable_c,

    gPlmeCslEnable_c,
    gPlmeCslSetSampleTime_c,

    gPlmeConfigureAckIeData_c,

    gPlmeSetMacKey_c,
    gPlmeEnableEncryption_c,
    gPlmeSetMacFrameCounter_c,
    gPlmeSetMacFrameCounterIfLarger_c,

    gPlmeEfpSet_c,  /*!< Enable/Disable Enhanced Frame Pending feature */

    gPlmeNeighbourTblSet_c,         /* Enable/Disable NBT, OFF by default */
    gPlmeNeighbourTblAdd_c,         /* Add entry to neighbour table */
    gPlmeNeighbourTblRemove_c,       /* Remove entry from neighbour table */

    gPlmeAddVisibleExtAddr_c,          /* Add ieee 64bits address in visible array */
    gPlmeAddInvisibleLocalAddr_c,      /* Add short address in invisible array     */
    gPlmeRemoveInvisibleLocalAddr_c,   /* Remove short address in invisible array  */
    gPlmeClearVisibleFilters_c,        /* Clear all filters                        */
    gPlmeSetBeaconFiltering_c,         /* Filter beacon frame                      */
    gPlmeUpdateLocalWithExtAddr_c,     /* Link short address with ieee 64b address */

} phyMessageId_t;

#endif  /* _PHY_MESSAGES_H */
/*! *********************************************************************************
* @}
********************************************************************************** */
