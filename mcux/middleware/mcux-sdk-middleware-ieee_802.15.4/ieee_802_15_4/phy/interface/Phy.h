/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2018, 2023-2025 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef __PHY_H__
#define __PHY_H__

/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */
#include "EmbeddedTypes.h"
#include "PhyInterface.h"
#include "PhyTime.h"
#include "fsl_os_abstraction.h"
#include "PhyPlatform.h"


/*! *********************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
********************************************************************************** */
#define mFrameCtrlLo_d       (0)
#define mFrameCtrlHi_d       (1)
#define mAddressingFields_d  (3)

#define mShortAddr_d         (2)
#define mExtAddr_d           (3)
#define mNoAddr_d            (0)
#define mPanIdCompression_d  (1 << 6)
#define mDstAddrModeMask_d   (0x0C)
#define mDstAddrModeShift_d  (2)
#define mSrcAddrModeMask_d   (0xC0)
#define mSrcAddrModeShift_d  (6)



/*! *********************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
********************************************************************************** */

#ifdef __cplusplus
extern "C" {
#endif


#undef CTX_NO

#ifdef CTX_SCHED
#define CTX_NO 2
#else
#define CTX_NO 1
#endif


#ifdef CTX_SCHED

typedef enum
{
    NONE_OP = 0,
    RX_OP = 1,
    CCA_OP = 2,
    TX_OP = 3
} proto_op;

typedef enum
{
    E_SCHED_PROTO_OFF,      /* disabled */
    E_SCHED_PROTO_INACTIVE, /* waiting for radio ownership */
    E_SCHED_PROTO_PAUSING,  /* interrupted by switch timer */
    E_SCHED_PROTO_ACTIVE    /* current radio owner */
} proto_state;

#endif /* CTX_SCHED */


#define PHY_TEN_SYMBOLS_US 160
#define PHY_SYMBOLS_US 16

#define INV_IDX ((uint32_t)(-1))


enum
{
    PHY_IMM_ACK_LENGTH               = 5,  /* Size of a Imm-ACK in bytes */
    PHY_ENH_ACK_LENGTH               = 50, /* Size of a Enh-ACK in bytes */
    PHY_IE_HEADER_SIZE               = 2,  /* Size of IE header in bytes */
    PHY_CSL_IE_SIZE                  = 4,  /* Size of CSL IE content in bytes */
    PHY_CSL_TOTAL_SIZE               = 6,  /* Total size of CSL IE in bytes */
    PHY_ACK_IE_MAX_SIZE              = 16, /* Max length for header IE in ACK */
    PHY_LEN_SIZE_BYTES               = 1,  /* Size of LEN field in bytes */
    PHY_ASH_SEC_CTRL_SIZE            = 1,  /* Size of ASH security control field in bytes */
    PHY_ASH_FRAME_CNT_SIZE           = 4,  /* Size of ASH frame counter field in bytes */
    PHY_ASH_KEY_IDX_SIZE             = 1,  /* Size of key index from ASH key identifier in bytes */
    PHY_ASH_TOTAL_SIZE               = 6,  /* Total size of the ASH using key id mode 1, no frame counter suppression */
    PHY_MAC_CMD_ID_SIZE              = 1   /* Size of CMD ID in MAC Command packet */
};

/*! Structure used to keep IE data for a specific peer */
typedef struct phyIeData_tag
{
    uint8_t         ieData[PHY_ACK_IE_MAX_SIZE];
    uint8_t         extAddr[8];
    uint16_t        shortAddr;
    uint32_t        ieParam;  // MSB: =1 if ieData has valid data including valid Data Length in IE Header Data (first 2 data bytes)
                              // Rest of the bits hold eventual params (IE Specific)
} phyIeData_t;


static volatile uint8_t * const RX_PB = (uint8_t *)(TX_PACKET_RAM_BASE + 0x80U);
static volatile uint8_t * const TX_PB = (uint8_t *)(TX_PACKET_RAM_BASE);

#ifndef TX_PB_TRY_CNT
#define TX_PB_TRY_CNT 10
#endif

static const uint32_t RX_WTMRK_START = 3;  /* frame length + FCF */


/* XCVR idle power mode */
#define gPhyDefaultIdlePwrMode_c   gPhyPwrIdle_c

/*! *********************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
********************************************************************************** */
/* PHY states */
enum
{
    gIdle_c,
    gRX_c,
    gTX_c,
    gCCA_c,
    gTR_c,
    gCCCA_c,
};

/* ZSM STATE */
enum
{
    g_ZSM_SEQ_IDLE  = 0x0,
    g_ZSM_RX_WU     = 0x10,
    g_ZSM_RX_PRE    = 0x14,
    g_ZSM_RX_PKT    = 0x15,
    g_ZSM_RX2ACK    = 0x16,
    g_ZSM_RX_CYC    = 0x17,
    g_ZSM_RX_PAN1   = 0x1D,
    g_ZSM_RX_PAN2   = 0x1E,
    g_ZSM_RX_CCA1   = 0x18,
    g_ZSM_CCA2_WAIT = 0x19,
    g_ZSM_RX_CCA2   = 0x1A,
    g_ZSM_RX_CCCA   = 0x1C,
    g_ZSM_RX2TX     = 0x1B,
    g_ZSM_TX_WU     = 0x01,
    g_ZSM_TX_PKT    = 0x05,
    g_ZSM_TX_ACK    = 0x06,
    g_ZSM_TX_SLOT   = 0x07,
    g_ZSM_TX_WD     = 0x08,
    g_ZSM_TX_PA_OFF = 0x09,
    g_ZSM_XTRA_CLK1 = 0x0A,
    g_ZSM_TX2RX     = 0x0B,
    g_ZSM_TSM_WD    = 0x1F
};

/* PHY channel state */
enum
{
    gChannelIdle_c,
    gChannelBusy_c
};

/* PANCORDNTR bit in PP */
enum
{
    gMacRole_DeviceOrCoord_c,
    gMacRole_PanCoord_c
};

/* Cca types */
enum
{
    gCcaED_c,         /* energy detect - CCA bit not active, not to be used for T and CCCA sequences */
    gCcaCCA_MODE1_c,  /* energy detect - CCA bit ACTIVE */
    gCcaCCA_MODE2_c,  /* 802.15.4 compliant signal detect - CCA bit ACTIVE */
    gCcaCCA_MODE3_c,  /* 802.15.4 compliant signal detect and energy detect - CCA bit ACTIVE */
    gInvalidCcaType_c /* illegal type */
};

enum
{
    gNormalCca_c,
    gContinuousCca_c
};



#ifdef CTX_SCHED

typedef enum
{
    E_SCHED_NO_POLICY,  /* Internal use reserved */
    E_SCHED_DUTY_CYCLE, /* Round robin manner with a configured time slice for each protocol */
    E_SCHED_LOCKED,     /* Locking only one protocol until the policy is changed or timeout */
    E_SCHED_PRIORITY,   /* Defines a priority for each protocol and scheduler will select the highest priority to run
                           based on pending operations*/
} sched_policy;

#endif

typedef enum
{
    ENH_ACK_INVALID,
    ENH_ACK_RESET,
    ENH_ACK_READY
} enh_ack_state_t;

#if defined(FFU_DEVICE_LIMIT_VISIBILITY)

#ifndef N_FILTER_DEVICES
#define N_FILTER_DEVICES 6
#endif

/*
   8-bytes address (long device address / little endian) base type
 */
typedef uint8_t ieee_64bit_addr_t[8];

/*
  External (64-bit) device address
 */
typedef ieee_64bit_addr_t ext_addr_t;

/*
  Device Filtering Context
 */
typedef struct
{
  uint8_t        nVisibleDevice;
  ext_addr_t     aVisibleExtAddr[N_FILTER_DEVICES];
  uint8_t        nInvisibleDevice;
  uint16_t       aInvisibleLocalAddr[N_FILTER_DEVICES];
  uint16_t       aVisibleLocalAddr[N_FILTER_DEVICES];
  bool_t         bDisableBeaconFrame;
} visible_filter_t;
#endif

typedef struct Phy_PhyLocalStruct_tag
{
    instanceId_t id;

    PD_MAC_SapHandler_t         PD_MAC_SapHandler;
    PLME_MAC_SapHandler_t       PLME_MAC_SapHandler;

#ifndef MEM_USE_ZEPHYR
    messaging_t                 macPhyInputQueue;
#endif /* MEM_USE_ZEPHYR */

    phyTxParams_t               txParams;
    phyRxParams_t               rxParams;
    phyCcaParams_t              ccaParams;

    phyChannelParams_t          channelParams;

    volatile uint8_t            flags;

    uint8_t                     mPhyLastRxLQI;
    int8_t                      mPhyLastRxRSSI;

    uint8_t                     trx_buff[gMaxPHYPacketSize_c + PHY_LEN_SIZE_BYTES];     /* trx PBs are 128 bytes */

    uint32_t phyCslPeriod;
    uint32_t phyCslSampleTimeUs;

    uint8_t ackIeDataAndHdr[PHY_CSL_IE_SIZE + PHY_IE_HEADER_SIZE];

    phyIeData_t phyIeDataTable[gPhyIeDataTableSize];

    bool_t phySecurity;

    uint8_t prevKey[PHY_SEC_KEY_SIZE];
    uint8_t currKey[PHY_SEC_KEY_SIZE];
    uint8_t nextKey[PHY_SEC_KEY_SIZE];

    uint8_t  keyId;
    uint32_t frameCounter;
    uint32_t updateFrameCounter;

    bool_t efp;     /* Enhanced FP */

    phyMessageId_t delayed_msg;     /* for postponed operations due to no memory */

    uint8_t filter_fail;

    enh_ack_state_t enh_ack_state;
    bool_t neighbourTblEnabled;

#if defined(FFU_DEVICE_LIMIT_VISIBILITY)
    visible_filter_t sFilter;
#endif

#ifdef CTX_SCHED
    proto_state state;
    proto_op op;   /* rx / tx / CCA */

    bool_t tx_cca_pending;
    bool_t rx_ongoing;

    pdDataReq_t tx_data_req;

    /* Policy related members */
    uint8_t priority;
    uint32_t slice;
    uint32_t lock_timeout;
    uint32_t tstp;              /* trx request timestamp */
#endif /* CTX_SCHED */
} Phy_PhyLocalStruct_t;

#if (WEIGHT_IN_LQI_CALCULATION == 1)
typedef struct Phy_nbRssiCtrl_tag
{
    uint8_t wt_snr;
    uint8_t wt_rssi;
    uint8_t lqi_bias;
    uint8_t lqi_rssi_sens;
}Phy_nbRssiCtrl_t;
#endif

/*! *********************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
********************************************************************************** */

/* PHY Packet Processor */

/*! *********************************************************************************
 * \brief  Initialize the XCVR HW
 *
 ********************************************************************************** */
void PhyHwInit(void);

#if defined(MFG_OT_RCP)
/*! *********************************************************************************
 * \brief  Update the XCVR HW
 *
 ********************************************************************************** */
void PhyHwUpdate(void);
#endif

/*! *********************************************************************************
 * \brief  Enable/Disable the XCVR promiscuous mode.
 *         In promiscuous mode, all filtering except CRC are disabled
 *
 * \param[in] mode  TRUE - Promiscuous On
 *                  FALSE - Promiscous Off
 *
 ********************************************************************************** */
void PhyPpSetPromiscuous(bool_t mode);

/*! *********************************************************************************
 * \brief  Enable/Disable the XCVR active promiscuous mode.
 *         In active promiscuous mode, all filtering except CRC are disabled.
 *         Also, the XCVR will send ACK to frames with destination address equal to
 *         the device's address
 *
 * \param[in] sate  TRUE - Promiscuous On
 *                  FALSE - Promiscous Off
 *
********************************************************************************** */
void PhySetActivePromiscuous(bool_t state);

/*! *********************************************************************************
* \brief Returns the state of the Active Promiscuous feature
*
********************************************************************************** */
bool_t PhyGetActivePromiscuous(void);

/*! *********************************************************************************
 * \brief Set the device's PAN Id
 *
 * \param
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPpSetPanId(uint8_t *pPanId, uint8_t pan);

/*! *********************************************************************************
 * \brief Set the device's Short Address
 *
 * \param
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPpSetShortAddr(uint8_t *pShortAddr, uint8_t pan);

/*! *********************************************************************************
 * \brief Set the device's IEEE Address
 *
 * \param
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPpSetLongAddr(uint8_t *pLongAddr, uint8_t pan);

/*! *********************************************************************************
 * \brief Get the device's IEEE Address
 *
 * \param
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPpGetLongAddr(uint8_t *pLongAddr, uint8_t pan);

/*! *********************************************************************************
 * \brief Set the device's role: Pan coordinator or not
 *
 * \param
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPpSetMacRole(bool_t macRole, uint8_t pan);

/*! *********************************************************************************
 * \brief Get the state of the FP bit sent in last ACK frame
 *
 * \return state of FP bit
 *
 ********************************************************************************** */
bool_t PhyPpIsTxAckDataPending(void);

/*! *********************************************************************************
 * \brief Get the state of the FP bit of the last received ACK frame
 *
 * \return state of FP bit
 *
 ********************************************************************************** */
bool_t PhyPpIsRxAckDataPending(void);

/*! *********************************************************************************
 * \brief Set the value of the FP bit for the next ACK frame
 *
 * \param[in] FP value of FP bit
 *
 ********************************************************************************** */
void PhyPpSetFpManually(bool_t FP);

/*! *********************************************************************************
 * \brief Check if the lasr received packet was a Poll Request
 *
 * \return TRUE if the received packet is a Poll Request
 *
 ********************************************************************************** */
bool_t PhyPpIsPollIndication(void);

/*! *********************************************************************************
 * \brief Enable/Disable Source Addressing Match feature
 *
 * \param[in] state of the SAM feature
 *
 ********************************************************************************** */
void PhyPpSetSAMState(instanceId_t instanceId, bool_t state);

/*! *********************************************************************************
 * \brief Add a new entry into the Neighbour table
 *
 * \param[in] index The table position
 * \param[in] checkSum The device hash code
 * \param[in] instanceId The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPp_AddNeighbour(uint32_t index, uint16_t checkSum, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief Remove an entry from Neighbour table
 *
 * \param[in] index The table position
 * \param[in] instanceId The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPp_RemoveNeighbour(uint32_t index, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief Clear every entry in the Neighbour table
 *
 * \param[in] instanceId The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPp_ClearNeighbourTbl(instanceId_t instanceId);
/*! *********************************************************************************
 * \brief Add a new entry into the HW indirect queue
 *
 * \param[in] index The table position
 * \param[in] checkSum The device hash code
 * \param[in] instanceId The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPp_IndirectQueueInsert(uint32_t index, uint16_t checkSum, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief Remove an entry from the HW indirect queue
 *
 * \param[in] index The table position
 * \param[in] instanceId The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPp_RemoveFromIndirect(uint32_t index, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief Get the current state of the XCVR
 *
 * \return state
 *
 ********************************************************************************** */
uint8_t PhyPpGetState(void);

/*! *********************************************************************************
 * \brief Abort the current XCVR sequence
 *
 ********************************************************************************** */
void PhyAbort(void);

bool_t PHY_graceful_idle();

/* PHY PLME & DATA primitives */

/*! *********************************************************************************
 * \brief Start a TX sequence
 *
 * \param[in] pTxPacket Pointer to the PD request
 * \param[in] pRxParams Pointer to the Rx parameters
 * \param[in] pTxParams Pointer to the Tx parameters
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPdDataRequest(Phy_PhyLocalStruct_t *ctx);

/*! *********************************************************************************
 * \brief Start an RX sequence
 *
 * \param[in] phyRxMode Slotted/Unslotted
 * \param[in] pRxParams Pointer to the Rx parameters
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeRxRequest(Phy_PhyLocalStruct_t *ctx);

/*! *********************************************************************************
 * \brief Start a immed RX sequence
 *
 * \param[in] pRxParams Pointer to the Rx parameters
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeTimmedRxRequest(phyRxParams_t *pRxParams);

/*! *********************************************************************************
 * \brief Start a CCA or ED sequence
 *
 * \param[in] ccaParam  type of CCA
 * \param[in] cccaMode  continuous or single operation
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeCcaEdRequest(Phy_PhyLocalStruct_t *ctx);

/*! *********************************************************************************
 * \brief Set the current 802.15.4 channel
 *
 * \param[in] channel number [11-26]
 * \param[in] pan index of the PAN
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeSetCurrentChannelRequest(uint8_t channel, uint8_t pan);

/*! *********************************************************************************
 * \brief Get the current 802.15.4 channel
 *
 * \param[in] pan index of the PAN
 *
 * \return status
 *
 ********************************************************************************** */
uint8_t PhyPlmeGetCurrentChannelRequest(uint8_t pan);

/*! *********************************************************************************
 * \brief Set the TX ouput power level in dBm signed value
 *
 * \param[in] pwr_dbm Tx output power in dBm signed value
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeSetPwrLevelRequest(int8_t pwr_dbm);

/*! *********************************************************************************
 * \brief Get the TX output power level in dBm signed value
 *
 * \return current TX output power in dBm signed value
 *
 ********************************************************************************** */
int8_t PhyPlmeGetPwrLevelRequest(void);

/*! *********************************************************************************
 * \brief Set a PHY PIB
 *
 * \param[in] pibId           The Id of the PIB
 * \param[in] pibValue        The value of the PIB
 * \param[in] phyRegistrySet  The index of the PAN
 * \param[in] instanceId      The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeSetPIBRequest(phyPibId_t pibId, uint64_t pibValue, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief Get a PHY PIB
 *
 * \param[in] pibId           The Id of the PIB
 * \param[in] pibValue        Pointer to a location where the value will be stored
 * \param[in] phyRegistrySet  The index of the PAN
 * \param[in] instanceId      The instance of the PHY
 *
 * \return status
 *
 ********************************************************************************** */
phyStatus_t PhyPlmeGetPIBRequest(phyPibId_t pibId, uint8_t *pibValue, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief Set the value of the CCA Threshold
 *
 * \param[in] ccaThreshold  the threshold value
 *
 * \return status
 *
 ********************************************************************************** */

phyStatus_t PhyPpSetCcaThreshold(uint8_t ccaThreshold);

/* PHY Time */
/*! *********************************************************************************
 * \brief Get the absolute end time of the next sequence
 *
 * \return the sequence timeout
 *
 ********************************************************************************** */
phyTime_t PhyTimeGetEventTimeout(void);

/*! *********************************************************************************
 * \brief Read the XCVR timer
 *
 * \return value of the timer
 *
 ********************************************************************************** */
phyTime_t PhyTime_ReadClock();

/* PHY ISR */

/*! *********************************************************************************
* \brief  This function forces the PHY IRQ to be triggered to run the ISR
*
********************************************************************************** */
void PHY_ForceIrqPending(void);

/*! *********************************************************************************
 * \brief This is the XCVR ISR
 *
 ********************************************************************************** */
void PHY_InterruptHandler();

/*! *********************************************************************************
* \brief Set the state of the Dual PAN automatic mode
*
* \param[in] mode of the Dual PAN automatic mode
*
********************************************************************************** */
void PhyPpSetDualPanAuto(bool_t mode);

/*! *********************************************************************************
* \brief Get the state of the Dual PAN automatic mode
*
* \return the state of the Dual PAN automatic mode
*
********************************************************************************** */
bool_t PhyPpGetDualPanAuto(void);

/*! *********************************************************************************
* \brief Set the Dual PAN Dwell switch time
*
********************************************************************************** */
void PhyPpSetDualPanDwell(uint8_t dwell);

/*! *********************************************************************************
* \brief Get the Dual PAN Dwell switch time
*
* \return dwell time
*
********************************************************************************** */
uint8_t PhyPpGetDualPanDwell(void);

/*! *********************************************************************************
* \brief Get the remaining time until a channel switch will occure
*
* \return remaining time until PAN switch wil occur
*
********************************************************************************** */
uint8_t PhyPpGetDualPanRemain(void);

/*! *********************************************************************************
* \brief Set the active PAN
*
* \param[in] the index of the PAN
*
********************************************************************************** */
void PhyPpSetDualPanActiveNwk(uint8_t nwk);

/*! *********************************************************************************
* \brief Returns the current NWK on which the PHY is operating
*
* \return the index of the active PAN
*
********************************************************************************** */
uint8_t PhyPpGetDualPanActiveNwk(void);

/*! *********************************************************************************
* \brief Return the PAN on which the packet was received (can be receiced on both PANs)
*
* \return the PAN index
*
********************************************************************************** */
uint8_t PhyPpGetPanOfRxPacket(void);

/*! *********************************************************************************
* \brief Return the LQI value for the last received packet
*
* \return LQI
*
********************************************************************************** */
uint8_t PhyGetLastRxLqiValue(instanceId_t id);

/*! *********************************************************************************
* \brief Returns the RSSI value for the last received packet
*
* \return RSSI
*
********************************************************************************** */
uint8_t PhyGetLastRxRssiValue(instanceId_t id);

/*! *********************************************************************************
* \brief  This function converts the LQI reported by the PHY into an signed RSSI value
*
* \param[in]  LQI  the LQI reported by the PHY
*
* \return  the RSSI value in dbm
*
********************************************************************************** */
int8_t PhyConvertLQIToRSSI(uint8_t lqi);

/*! *********************************************************************************
* \brief Enable the FAD function (FAD_EN bit)
*
* \param[in] state , the state of the FAD feature
*
* \return gPhySuccess
*
********************************************************************************** */
uint8_t PhyPlmeSetFADStateRequest(bool_t state);

/*! *********************************************************************************
* \brief Correlator threshold at which the FAD will select the antenna
*
* \return gPhySuccess
*
********************************************************************************** */
uint8_t PhyPlmeSetFADThresholdRequest(uint8_t FADThreshold);

/*! *********************************************************************************
* \brief Enable the ANT pads
*
* \param[in] antAB_on -
* \param[in] rxtxSwitch_on -
*
* \return gPhySuccess
*
********************************************************************************** */
uint8_t PhyPlmeSetANTPadStateRequest(bool_t antAB_on, bool_t rxtxSwitch_on);

/*! *********************************************************************************
* \brief Invert the logic of the ANT pads
*
* \param[in] invAntA - invert the ANT_A pad
* \param[in] invAntB - invert the ANT_A pad
* \param[in] invTx   - invert the ANT_TX pad
* \param[in] invRx   - invert the ANT_RX pad
*
* \return gPhySuccess
*
********************************************************************************** */
uint8_t PhyPlmeSetANTPadInvertedRequest(bool_t invAntA, bool_t invAntB, bool_t invTx, bool_t invRx);

/*! *********************************************************************************
* \brief Set FAD Antenna start when FAD_EN = 1 or antenna selected when FAD_EN=0
*
* \return gPhySuccess
*
********************************************************************************** */
uint8_t PhyPlmeSetANTXStateRequest(bool_t state);

/*! *********************************************************************************
* \brief Antenna selected in FAD of non-FAD mode
*
* \return Chosen antenna by the FAD (FAD_EN = 1) or copy of ANTX_IN
*
********************************************************************************** */
uint8_t PhyPlmeGetANTXStateRequest(void);

/*! *********************************************************************************
* \brief  This function will return the CCA Type
*
* \return  phyCCAType_t :
*          gPhyEnergyDetectMode_c = 0x00,
*          gPhyCCAMode1_c         = 0x01,  Energy above a threshold
*          gPhyCCAMode2_c         = 0x02,  Carrier sense only
*          gPhyCCAMode3_c         = 0x03,  CCA mode 1 + CCA mode 2
*\
********************************************************************************** */
phyCCAType_t PhyPlmeGetCCATypeRequest(void);

/*! *********************************************************************************
* \brief Choose CCA3 Mode: 1 - CCA1 AND CCA2,
*                          0 - CCA1 OR CCA2
*
* \return gPhySuccess
*
********************************************************************************** */
phyStatus_t PhyPlmeSetCCA3ModeRequest(phyCCA3Mode_t cca3Mode);

/*! *********************************************************************************
* \brief Returns the CCA3 Mode value
*
* \return phyCCA3Mode_t. 1 - CCA1 AND CCA2, 0 - CCA1 OR CCA2
*
********************************************************************************** */
phyCCA3Mode_t PhyPlmeGetCCA3ModeRequest(void);

/*! *********************************************************************************
* \brief Returns the RSSI level value, refreshed every 125us
*
* \param[in] instanceId - the instance of the PHY
*
* \return RSSI level [dbm]
*
********************************************************************************** */
uint8_t PhyPlmeGetRSSILevelRequest(instanceId_t instanceId);

int8_t PHY_handle_get_RSSI(Phy_PhyLocalStruct_t *ctx);

/*! *********************************************************************************
* \brief  This function will return the promiscuous state
*
* \return  bool_t
*
********************************************************************************** */
bool_t PhyPlmeGetPromiscuousRequest(void);

/*! *********************************************************************************
* \brief Informs the PHY if it should start an RX when entering IDLE or not
*
* \param[in] state      - if TRUE the XCVR will start an Rx when Idle
* \param[in] instanceId - the instance of the PHY
*
********************************************************************************** */
void PhyPlmeSetRxOnWhenIdle(bool_t state, instanceId_t instanceId);

/*! *********************************************************************************
* \brief Set the start time and end time for an XCVR sequence
*
* \param[in] startTime   - absolute start time in symbols
* \param[in] seqDuration - sequence duration in symbols
*
********************************************************************************** */
void Phy_SetSequenceTiming(phyTime_t *startTime, uint32_t seqDuration, uint32_t overhead);

/*! *********************************************************************************
* \brief  Scales energy level to 0-255
*
* \param[in]  energyLevel  the energy level reported by HW
*
* \return  uint8_t  the energy level scaled in 0x00-0xFF
*
********************************************************************************** */
uint8_t Phy_GetEnergyLevel(uint8_t energyLevel);

/*! *********************************************************************************
* \brief  Disable the XCVR interrupts
*
********************************************************************************** */
void ProtectFromXcvrInterrupt(void);

/*! *********************************************************************************
* \brief  Enable the XCVR interrupts
*
********************************************************************************** */
void UnprotectFromXcvrInterrupt(void);

#if (AUTO_ACK_DISABLE_SUPPORT == 1)
/*! *********************************************************************************
* \brief  Enable the 802.15.4 radio Auto Acknowledge
*
********************************************************************************** */
void PhyEnableAutoAck(void);

/*! *********************************************************************************
* \brief  Disable the 802.15.4 radio Auto Acknowledge
*
********************************************************************************** */
void PhyDisableAutoAck(void);
#endif

#if (TX_POWER_LIMIT_FEATURE == 1)
/*! *********************************************************************************
 * \brief This function will set max tx power limit as per txPowerLimit byte.
 *
 * \param txPowerLimit
 * txPowerLimit (0 or default value), No power backoff is applied
 * txPowerLimit = 1 to 44, force TX power back off to txPowerLimit
 * (txPowerLimit = 0.5dBm step, TX power back off : 0.5dBm step )
 * If > 44 : gPhyMaxTxPowerLevel_d is used.
 * \return txPowerLimit really stored in gPhyChannelTxPowerLimits
 */
uint8_t PhySetTxPowerLimit(uint8_t txPowerLimit);

/*! *********************************************************************************
 * \brief This function will get tx power limit
 *
 * \return txPowerLimit stored in gPhyChannelTxPowerLimits
 */
uint8_t PhyGetTxPowerLimit(void);

#endif

/*! *********************************************************************************
 * \brief This function will get CCA Configuration Values
 * \param[in]  aCca1Threshold       pointer to CCA1 Threshold value
 * \param[in]  aCca2CorrThreshold   pointer to CCA2 Correlation Threshold value
 * \param[in]  aCca2MinNumOfCorrTh  pointer to CCA2 Minimum number of Correlation peaks
 *
 * \return void
 */
void PhyGetCcaConfig(uint8_t *aCca1Threshold, uint8_t *aCca2CorrThreshold, uint8_t *aCca2MinNumOfCorrTh);

/*! *********************************************************************************
 * \brief This function will set CCA Configuration Values
 * \param[in]  aCca1Threshold       CCA1 Threshold value
 * \param[in]  aCca2CorrThreshold   CCA2 Correlation Threshold value
 * \param[in]  aCca2MinNumOfCorrTh  CCA2 Minimum number of Correlation peaks
 *
 * \return void
 */
void PhySetCcaConfig(uint8_t aCca1Threshold, uint8_t aCca2CorrThreshold, uint8_t aCca2MinNumOfCorrTh);

/* utils */
uint16_t PHY_TransformArrayToUint16(uint8_t *pArray);

uint16_t PhyGetChecksum(uint8_t *pAddr, uint8_t addrMode, uint16_t PanId);

/* Indirect queue table functions */
uint32_t PhyGetIndexOf(Phy_PhyLocalStruct_t *ctx, uint16_t checksum);

uint8_t PhyRemoveFromSamTable(instanceId_t instanceId, uint8_t *pAddr, uint8_t addrMode, uint16_t PanId);

uint8_t PhyAddToSapTable(instanceId_t instanceId, uint8_t *pAddr, uint8_t addrMode, uint16_t PanId);

/* Neighbour table functions */
uint32_t PhyNbTblIndexOf(Phy_PhyLocalStruct_t *ctx, uint16_t checksum);

uint8_t PhyNbTblRemove(instanceId_t instanceId, uint8_t *pAddr, uint8_t addrMode, uint16_t PanId);

uint8_t PhyNbTblAdd(instanceId_t instanceId, uint8_t *pAddr, uint8_t addrMode, uint16_t PanId);

/* RADIO EVENTS */

void Radio_Phy_PdDataConfirm(Phy_PhyLocalStruct_t *ctx, bool_t framePending);

void Radio_Phy_TimeRxTimeoutIndication(Phy_PhyLocalStruct_t *ctx);

void Radio_Phy_AbortIndication(Phy_PhyLocalStruct_t *ctx);

void Radio_Phy_PdDataIndication(Phy_PhyLocalStruct_t *ctx);

void Radio_Phy_TimeStartEventIndication(Phy_PhyLocalStruct_t *ctx);

void Radio_Phy_PlmeCcaConfirm(phyStatus_t phyChannelStatus, Phy_PhyLocalStruct_t *ctx);

void Radio_Phy_PlmeEdConfirm(Phy_PhyLocalStruct_t *ctx, int8_t energyLeveldB);

void Radio_Phy_PlmeSyncLossIndication(Phy_PhyLocalStruct_t *ctx);

void Radio_Phy_PlmeRxWatermark(uint32_t frameLength, uint16_t fcf);

void Radio_Phy_PlmeFilterFailRx(Phy_PhyLocalStruct_t *ctx);

bool_t PhyIsIdleRx(instanceId_t instanceId);

void Radio_Phy_Notify(Phy_PhyLocalStruct_t *ctx);


void ctx_init();
void ctx_init_single(uint8_t id);
Phy_PhyLocalStruct_t *ctx_get(instanceId_t id);
Phy_PhyLocalStruct_t *ctx_get_current();

#ifdef CTX_SCHED
/* should it be in private include? */
void sched_reschedule();

void ctx_set_pending(Phy_PhyLocalStruct_t *ctx);

bool_t ctx_is_active(Phy_PhyLocalStruct_t *ctx);
bool_t ctx_is_paused(Phy_PhyLocalStruct_t *ctx);

void ctx_data_ind_all(Phy_PhyLocalStruct_t *ctx);

void ctx_set_rx_ongoing(Phy_PhyLocalStruct_t *ctx, bool_t status);

void ctx_set_rx(Phy_PhyLocalStruct_t *ctx);
void ctx_set_tx(Phy_PhyLocalStruct_t *ctx, macToPdDataMessage_t *pMsg);
void ctx_set_cca(Phy_PhyLocalStruct_t *ctx);
void ctx_set_none(Phy_PhyLocalStruct_t *ctx);

bool_t PHY_ctx_can_sleep();
bool_t PHY_ctx_all_disabled();

#else /* CTX_SCHED */

#define sched_reschedule()
#define ctx_set_pending(ctx)
#define ctx_is_active(ctx) TRUE
#define ctx_is_paused(ctx) FALSE
#define ctx_data_ind_all(ctx)
#define ctx_set_rx_ongoing(ctx, status)
#define ctx_set_rx(ctx)
#define ctx_set_tx(ctx, pMsg)
#define ctx_set_cca(ctx)
#define ctx_set_none(ctx)
#define PHY_ctx_can_sleep() TRUE
#define PHY_ctx_all_disabled() TRUE

#endif /* CTX_SCHED */

#ifdef __cplusplus
}
#endif

#endif /* __PHY_H__ */
