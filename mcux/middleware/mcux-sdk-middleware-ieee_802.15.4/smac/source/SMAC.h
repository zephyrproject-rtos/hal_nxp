/*! *********************************************************************************
* Copyright (c) 2004 - 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2024,2026 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef SMAC_H_
#define SMAC_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "Phy.h"
#include "PhyInterface.h"
#include "SMAC_Interface.h"
#ifndef __ZEPHYR__
#include "fsl_component_timer_manager.h"
#include "fsl_adapter_rng.h"
#include "ModuleInfo.h"
#else
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>
#endif
#if gSmacUseSecurity_c
#include "SecLib.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/*smacParametersValidation_d:
TRUE :  SMAC primitives validate their incoming parameters.
FALSE:  SMAC primitives do their stuff without validating their incoming 
parameters
*Note: Setting this as FALSE will compile a smaller foot print SMAC.
*/
#define smacParametersValidation_d      	TRUE

/*smacInitializationValidation_d:
TRUE :  SMAC primitives validate whether SMAC is initialized or not.
FALSE:  SMAC primitives don't care about SMAC's initialization.
*Note: Setting this as FALSE will compile a smaller foot print SMAC.
*/
#define smacInitializationValidation_d  	TRUE

#define gFrameCtrlAckReqMsk_c                  (1 << 5)

/*!
 * \brief SMAC build version
 */
#define gSmacVerMajor_c   3
#define gSmacVerMinor_c   3
#define gSmacVerPatch_c   3
#define gSmacBuildNo_c    0

#define gSmacModuleId_c  0xD1

#ifndef __ZEPHYR__
#define gSmacVerString_c "SMAC v" \
                        QUH(gSmacVerMajor_c) "." \
                        QUH(gSmacVerMinor_c) "." \
                        QUH(gSmacVerPatch_c) "." \
                        QUH(gSmacBuildNo_c)
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

#if gSmacUseSecurity_c

typedef struct smacEncryptionKeyIV_tag
{
    uint8_t IV[16];
    uint8_t KEY[16];
#if (defined(FSL_FEATURE_SOC_LTC_COUNT) && (FSL_FEATURE_SOC_LTC_COUNT > 0))
    uint8_t DKEY[16];
#endif
} smacEncryptionKeyIV_t;

#endif

typedef enum smacStates_tag {
    mSmacStateIdle_c,
    mSmacStateTransmitting_c,
    mSmacStateReceiving_c,
    mSmacStateScanningChannels_c,
    mSmacStatePerformingCca_c,
    mSmacStatePerformingEd_c,
    mSmacStatePerformingTest_c,
    mSmacStateHibernate_c, 
    mSmacStateDoze_c    
} smacStates_t;

typedef union prssPacketPtr_tag
{
    uint8_t*    smacScanResultsPointer;     
    rxPacket_t  *smacRxPacketPointer;
    pdDataReq_t *smacTxPacketPointer;
} prssPacketPtr_t;

typedef phyStatus_t ( * PD_SMAC_SapHandler_t)(pdDataToMacMessage_t * pMsg, instanceId_t instanceId);

typedef phyStatus_t ( * PLME_SMAC_SapHandler_t)(plmeToMacMessage_t * pMsg, instanceId_t instanceId);

typedef struct smacInternalAttrib_tag
{
    smacStates_t smacState;
    instanceId_t phy_context_id;
    prssPacketPtr_t smacProccesPacketPtr;
    phyRxParams_t   smacLastDataRxParams;
    txContextConfig_t txConfigurator;
    macToPdDataMessage_t * gSmacDataMessage;
    macToPlmeMessage_t *   gSmacMlmeMessage;
    SMAC_APP_MCPS_SapHandler_t gSMAC_APP_MCPS_SapHandler;
    SMAC_APP_MLME_SapHandler_t gSMAC_APP_MLME_SapHandler;

    address_size_t u16PanID;
    address_size_t u16ShortSrcAddress;
    uint64_t       u64ExtendedSrcAddress;

    uint8_t u8AckRetryCounter;
    uint8_t u8CCARetryCounter;
    uint8_t mSmacTimeoutAsked;
#ifndef __ZEPHYR__
    TIMER_MANAGER_HANDLE_DEFINE(u8BackoffTimerId);
#else
    struct k_timer u8BackoffTimerId;
#endif
    uint8_t u8SmacSeqNo;
#if (gSmacUseSecurity_c)
    smacEncryptionKeyIV_t secInit;
#endif
} smacInternalAttrib_t;


#endif /* SMAC_H_ */
