/*! *********************************************************************************
* \defgroup PhyInterface PHY Interface
*
* The PHY sublayer provides two services: the PHY data service, and the PHY management service interfacing to the PHY sublayer management entity (PLME) service access point (SAP) (known as PLME-SAP).
* The PHY data service enables the transmission and reception of PHY protocol data units (PSDUs) over the media (radio).
* The PHY Layer interfaces to the MAC Layer through function calls and function callbacks.
* If the interface primitives are implemented as function calls, the MAC Layer calls the exposed functions (provided by the PHY Layer) to issue commands / requests.
*
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

#ifndef _PHY_INTERFACE_H
#define _PHY_INTERFACE_H


/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#include <stdbool.h>
#include "PhyTypes.h"
#include "PhyMessages.h"

/*! *********************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
********************************************************************************** */
#define CONCAT_EXPAND(a,b) CONCAT(a, b) // expand then paste

_Static_assert(sizeof(phyMessageId_t) == sizeof(uint8_t), "phyMessageId_t bigger than 1 byte");

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

/*! Number of PHY instances (Only for PHYs which support multiple instances) */
#ifndef gPhyInstancesCnt_c
#define gPhyInstancesCnt_c  1
#endif

/*! The PHY task stack size (Only for PHYs which use OS task) */
#ifndef gPhyTaskStackSize_c
#define gPhyTaskStackSize_c 600
#endif

/*! The PHY task priority (Only for PHYs which use OS task)
    The PHY Task must have the highest priority! */
#ifndef gPhyTaskPriority_c
#define gPhyTaskPriority_c  0
#endif

/*! The following define is used to enable the Automatic Frequency Correction (MKW01 only) */
#ifndef gAfcEnabled_d
#define gAfcEnabled_d		0
#endif

/*! Configure the maximum number of PHY timers/events */
#ifndef gMaxPhyTimers_c
#define gMaxPhyTimers_c                 (8)
#endif

/*! Configure the HW Auto Dual PAN Mode */
#ifndef gHwAutoDualPanMode_c
#define gHwAutoDualPanMode_c            (TRUE)
#endif

/*! This define is used as a start time to signal that a current sequence is handled as soon as possible by the PHY layer.  */
#define gPhySeqStartAsap_c              ((phyTime_t)(-1))

/*! \cond DOXY_SKIP_TAG */
#define Phy_BufferAlloc(size) MSG_Alloc(size)
/*! \endcond */

/*! These defines are used when using OpenThread Vendor Specific IE  */
#define IeData_LinkMarginThreshold_c (-102) /* -102 dBm receiver sensitivity from datasheet */
#define IeData_Lqi_c                 0x02   /* corelated with IE Data Elements in OT Link metrics */
#define IeData_LinkMargin_c          0x04   /* corelated with IE Data Elements in OT Link metrics */
#define IeData_Rssi_c                0x08   /* corelated with IE Data Elements in OT Link metrics */
#define IeData_MSB_VALID_DATA  0x80000000   /* IE has valid data in data buffer including data lenght in IE Header (first 2 bytes)*/
#define IeVendorOuiThreadCompanyId   0xeab89b

#define PHY_SEC_KEY_SIZE 16
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
#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#endif

/*! PHY power states. These modes are hardware specific.
    Some modes may not be available on certain HW platforms. */
typedef enum{
    gPhyPwrIdle_c,
    gPhyPwrAutodoze_c,
    gPhyPwrDoze_c,
    gPhyPwrHibernate_c,
    gPhyPwrDSM_c,
    gPhyPwrReset_c
}phyPwrMode_t;

/*! The PD-DATA.request primitive is generated by the MAC Layer when a MAC data frame (MPDU) is ready to be transferred to the PHY Layer, becoming payload for the PHY frame (PSDU). 
    Upon the reception of this primitive, the PHY Layer will arm either a T or TRxAck sequence, depending on the Acknowledgement Request sub-field bit included in the Frame Control field, which is part of the MHR. */
typedef struct pdDataReq_tag
{ 
    phyTime_t               startTime;  /*!< The absolute start time of the preamble over the air. A value of gPhySeqStartAsap_c to start immediately.  */  
    uint32_t                txDuration; /*!< The computed duration for the Data Request frame. */
    phyCCAType_t            CCABeforeTx; /*!< Indicates, whether the CCA is used before this transmission. */
    phyAckRequired_t        ackRequired; /*!< Indicates, whether the ACK is required for this transmission. */
    uint8_t                 psduLength;  /*!< The number of octets contained in the PSDU to be transmitted by the PHY Layer, without the last two octets containing the FCS field. */
    uint8_t                 flags;       /* values from phyTxFlags */
    uint8_t *               pPsdu;       /*!< A pointer to the set of octets forming the PSDU to be transmitted by the PHY Layer. */
                                         /* The PSDU has to be right after the request - allocate everything together */
} pdDataReq_t;

/*! The PD-DATA.confirm primitive reports the result of a request to transfer a data MAC frame (MPDU). 
    The status returned by PD-DATA.confirm can be SUCCESS, indicating that the request to transmit was successful, an error code of BUSY if the PHY Layer 
    was not in the idle state (I sequence) when the PD-DATA.request was issued, or an error code of CHANNEL_BUSY if all CCA sequences indicated that the channel was busy. 
    If the transmission occurred successfully but no valid ACK frame was received (assuming that it was requested), then an error code of NO_ACK is used. */
typedef struct pdDataCnf_tag
{
    phyStatus_t             status;
    uint8_t                 ackLength;
    phyTime_t               timeStamp;
    uint8_t                 ppduLinkQuality;    /*!< Link quality (LQI) value measured during the reception of the ACK (if AR=1) */
    int8_t                  ppduRssi;           /*!< RSSI (signal strength indicator)value measured during the reception of the ACK (if AR=1) */
    uint8_t                *ackData;            /* The ACK has to be right after the confirmation - allocate everything together */
} pdDataCnf_t;

/*! The PD-DATA.indication primitive is generated by the PHY Layer when an MPDU is ready to be transferred to the MAC Layer. 
    Besides the PSDU itself, the primitive also returns the LQI value measured during the reception. */
typedef struct pdDataInd_tag
{
    phyTime_t               timeStamp;       /*!< The timestamp when the reception started. */
    uint8_t                 ppduLinkQuality; /*!< Link quality (LQI) value measured during the reception of the PPDU. */
    int8_t                  ppduRssi;        /*!< RSSI (signal strength indicator)value measured during the reception of the PPDU. */    
    bool_t                  rxAckFp;         /*!< True if the received pachet was acked with frame pending bit set to TRUE. */
    phyRxAckFpReason_t      rxAckFpReason;   /*!< Ack FP reason */
    bool_t                  ackedWithSecEnhAck;
    uint16_t                ackKeyId;
    uint16_t                psduLength;      /*!< The number of octets contained in the PSDU received by the PHY Layer. */
    uint32_t                ackFrameCounter;
    uint8_t *               pPsdu;           /*!< The pointer to the set of octets forming the PSDU received by the PHY Layer. */
                                             /* The PSDU has to be right after the indication - allocate everything together */
} pdDataInd_t;

/*! The PD-INDQUEUEINSERT.Request primitive is generated by the MAC Layer when a packet is inserted into the MAC indirect queue.
    A 16-bit checksum derived from the Destination Address and Destination PAN ID is passed to the PHY Layer.
    The PHY Layer, both in hardware implementations and emulated in software, must keep a database of checksums, and facilitate writing into it through the use of this primitive. */
typedef struct pdIndQueueInsertReq_tag
{
    uint8_t                 index;    /*!< Index into the indirect table */
    uint16_t                checksum;
} pdIndQueueInsertReq_t;

/*! Unused! The request is synchronous. */
typedef struct pdIndQueueInsertCnf_tag
{
    phyStatus_t             status;
} pdIndQueueInsertCnf_t;

/*! The PD-INDQUEUEREMOVE.Request primitive is generated by the MAC Layer when a packet is removed from the MAC indirect queue, and the index, at which the packets checksum is stored, gets passed on to the PHY Layer. 
    The PHY Layer, both in hardware implementations and emulated in software, must facilitate erasing entries from its database of checksums through the use of this primitive. */
typedef struct pdIndQueueRemoveReq_tag
{
    uint8_t                 index; /*!< Index into the indirect table */
} pdIndQueueRemoveReq_t;

/*! The PLME-ED.request primitive is generated by the MAC Layer when an ED measurement must be performed by the PHY Layer. */
typedef struct plmeEdReq_tag
{
    phyTime_t               startTime;          /*!< Absolute time */
    uint32_t                measureDurationSym; /*!< Total time in symbols of the measurement, a channel sample takes 8 symbols (128us) and samples are performed continuously until the total time is reached */
} plmeEdReq_t;

/*! The PLME-CCA.request primitive is generated by the MAC Layer when a CCA operation must be performed, and it is passed to the PHY Layer. */
typedef struct plmeCcaReq_tag
{
    phyCCAType_t            ccaType;
    phyContCCAMode_t        contCcaMode; /*!< Enable continuous CCA mode */
} plmeCcaReq_t;

/*! The PLME-CCA.confirm primitive is generated by the PHY Layer after the C sequence completes, and returns the response of a previous PLME-CCA.request to the MAC Layer.
    The status returned can be IDLE if the channel is idle, RX_ON if the transceiver is receiving, or BUSY if there is an ongoing T sequence or the channel assessment process determined that the channel is busy. */
typedef struct plmeCcaCnf_tag
{
    phyStatus_t             status;
} plmeCcaCnf_t;

/*! The PLME-ED.confirm primitive is generated by the PHY Layer after the C sequence completes, and returns the response of a previous PLME-ED.request to the MAC Layer.
    The status returned can be SUCCESS if the measurement was successful, an error code of TX_ON if there is an ongoing T sequence, or RX_ON if the transceiver is receiving.
    The PLME-ED.confirm primitive returns the value of the ED measurement. */
typedef struct plmeEdCnf_tag
{
    phyStatus_t             status;
    uint8_t                 energyLevel;      /*!< The ED level for the current channel. If the status is not SUCCESS, the value of this parameter will be ignored. */
    uint8_t                 energyLeveldB;    /*!< The ED level for the current channel in dBm value. */
    int8_t                  maxEnergyLeveldB; /*!< The maximum ED level for the current channel in dBm value. This is used if multiple energy samples are requested */
} plmeEdCnf_t;

/*! The PLME-SET-TRX-STATE.request primitive is generated by the MAC Layer when the transceiver state must be changed by the PHY Layer, which then arms either an I or R sequence.
    This primitive is also used to cancel any ongoing sequence by setting the state to FORCE_TRX_OFF. If this primitive is issued with an RX_ON or TRX_OFF argument and the PHY is busy transmitting a PPDU, a state change will occur at the end of the transmission.
    If this primitive is issued with TRX_OFF, and the PHY is in the RX_ON state and has already received a valid SFD, the state change will occur at the end of reception of the PPDU. */
typedef struct plmeSetTRxStateReq_tag
{
    phyState_t              state;       /*!< The new state in which to configure the transceiver */
    phyTime_t               startTime;   /*!< Absolute time */
    uint32_t                rxDuration;  /*!< If the requested state is Rx, then Rx will be enabled for rxDuration symbols. */
} plmeSetTRxStateReq_t;

/*! PHY Event */
typedef struct phyTimeEvent_tag
{
    phyTime_t          timestamp; /*!< Absolute time of the event */
    phyTimeCallback_t  callback;  /*!< Callback function to handle the event */
    uint32_t           parameter; /*!< Parameter to be specified to the callback function */
}phyTimeEvent_t;

/*! The PLME-SET.request primitive is generated by the MAC Layer to modify a PIB attribute in the PHY Layer.
    This primitive requires the identifier of the PIB attribute to set its value.
    This request is synchronous. The PIB value will be set inside the call to the PLME SAP. */
typedef struct plmeSetReq_tag
{
    phyPibId_t              PibAttribute;
    uint64_t                PibAttributeValue;
} plmeSetReq_t;

/*! The PLME-GET.request primitive is generated by the MAC Layer to request information about a PIB attribute in the PHY Layer.
    This primitive requires the identifier of the PIB attribute to read.
    This request is synchronous. The PIB value will be available after the call to the PLME SAP. */
typedef struct plmeGetReq_tag
{
    phyPibId_t              PibAttribute;
    uint64_t                PibAttributeValue;
} plmeGetReq_t;

typedef PACKED_STRUCT deviceAddr_tag
{
    uint8_t addr[8];
    uint8_t mode;
    uint16_t panId;
} deviceAddr_t;

typedef PACKED_STRUCT AckIeData_tag
{
    uint8_t  data[16];
    uint8_t  extAddr[8];
    uint16_t shortAddr;
    uint32_t param; // MSB: =1 if data[16] has valid data including valid Data Length in IE Header Data (first 2 data bytes)
                    // Rest of the bits holds eventual params (IE Specific)
} AckIeData_t;

typedef PACKED_STRUCT MacKeyData_tag
{
    uint8_t keyId;
    uint8_t prevKey[PHY_SEC_KEY_SIZE];
    uint8_t currKey[PHY_SEC_KEY_SIZE];
    uint8_t nextKey[PHY_SEC_KEY_SIZE];
} MacKeyData_t;

typedef PACKED_STRUCT filterAddr_tag
{
    uint8_t  extAddr[8];
    uint16_t shortAddr;
    bool_t   block;
} filterAddr_t;

/*! PHY Management Requests messages */
typedef struct macToPlmeMessage_tag
{
    uint8_t                   msgType;
    uint8_t                   ctx_id;
    union
    {
        plmeEdReq_t           edReq;
        plmeCcaReq_t          ccaReq;
        plmeSetTRxStateReq_t  setTRxStateReq;
        plmeSetReq_t          setReq;
        plmeGetReq_t          getReq;

        bool_t                SAMState;
        deviceAddr_t          deviceAddr;
        filterAddr_t          filterAddr;

        bool_t                efpEnabled;
        bool_t                neighbourTblEnabled;
        uint32_t              cslPeriod;
        uint32_t              cslSampleTime;

        AckIeData_t           AckIeData;

        MacKeyData_t          MacKeyData;
        uint32_t              MacFrameCounter;
    } msgData;
} macToPlmeMessage_t;

/*! PHY Data Requests messages */
typedef struct macToPdDataMessage_tag
{
    uint8_t                    msgType;
    uint8_t                    ctx_id;
    union
    {
        pdDataReq_t             dataReq;
        pdIndQueueInsertReq_t   indQueueInsertReq;
        pdIndQueueRemoveReq_t   indQueueRemoveReq;
    } msgData;
} macToPdDataMessage_t;

/*! PHY Management Confirms/Indications messages */
typedef struct plmeToMacMessage_tag
{
    uint8_t                    msgType;
    uint8_t                    ctx_id;
    uint32_t                   fc;      /* last frame counter used */
    union
    {
        plmeCcaCnf_t            ccaCnf;
        plmeEdCnf_t             edCnf;
    } msgData;
} plmeToMacMessage_t;

/*! PHY Data Confirms/Indications messages */
typedef struct pdDataToMacMessage_tag
{
    uint8_t                    msgType;
    uint8_t                    ctx_id;
    uint32_t                   fc;      /* last frame counter used */
    union
    {
        pdDataCnf_t             dataCnf;
        pdDataInd_t             dataInd;
    } msgData;
} pdDataToMacMessage_t;

/*! Common PHY message header */
typedef struct phyMessageHeader_tag
{
    uint8_t                    msgType;     /* phyMessageId_t */
    uint8_t                    ctx_id;
} phyMessageHeader_t;

/*! PHY RX parameter */
typedef struct phyRxParams_tag
{
    phyTime_t   timeStamp;  /*!< [symbols] : Rx startTime / DataIndication timestamp */
    uint8_t     psduLength; /*!< bytes received */
    uint8_t     linkQuality;/*!< LQI value */
    int8_t      rssi;       /*!< RSSI value */
    bool_t      ackedWithSecEnhAck; /*!< Indicates if the rx packet was acked with a security */

    phyTime_t   startTime;
    uint32_t    duration;
} phyRxParams_t;

/*! PHY Channel parameters */
typedef struct phyChannelParams_tag
{
    union
    {
        phyStatus_t channelStatus;    /*!< Channel busy or idle */
        uint8_t     energyLeveldB;    /*!< Channel energy level in dBm */
        int8_t      maxEnergyLeveldB; /*!< MAX Channel energy level in dBm */
    };
} phyChannelParams_t;

/*! Passed by the MAC layer to specify that a standalone CCA must be used, or that the ACK is required for the sequence. */
typedef struct phyTxParams_tag
{
    pdDataReq_t *dataReq;
} phyTxParams_t;

typedef struct phyCcaParams_tag
{
    phyMessageId_t msgType;
    phyCCAType_t ccaParam;
    phyContCCAMode_t cccaMode;
    uint32_t edScanDurationSym;
    phyTimeTimerId_t timer;
} phyCcaParams_t;

/*! PHY data service callback type */
typedef phyStatus_t ( * PD_MAC_SapHandler_t)(pdDataToMacMessage_t * pMsg, instanceId_t instanceId);

/*! PHY management service callback type */
typedef phyStatus_t ( * PLME_MAC_SapHandler_t)(plmeToMacMessage_t * pMsg, instanceId_t instanceId);

typedef void (*phyTxAppCallback)(uint8_t* pTxData);

#if defined(__ARMCC_VERSION)
#pragma pop
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/

extern uint8_t gPhyTxWuTimeSym;  /*!< TSM TX warmup time in symbols(16us) */
extern uint8_t gPhyTxWdTimeSym;  /*!< TSM TX warmdown time in symbols(16us) */
extern uint8_t gPhyRxWuTimeSym;  /*!< TSM RX warmup time in symbols(16us) */ 
extern uint8_t gPhyRxWdTimeSym;  /*!< TSM RX warmdown time in symbols(16us) */ 

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
/*! *********************************************************************************
 * \brief initialize the PHY module
 *
 ********************************************************************************** */
void Phy_Init( void );

/*! *********************************************************************************
 * \brief get a free PHY ctx and initialize it
 *
 ********************************************************************************** */
uint8_t PHY_get_ctx();

/*! *********************************************************************************
 * \brief deinitialize a PHY ctx
 *
 ********************************************************************************** */
void PHY_release_ctx(uint8_t id);

/*! *********************************************************************************
 * \brief deinitialize the PHY module
 *
 ********************************************************************************** */
 void Phy_Deinit( void );

/*! *********************************************************************************
 * \brief Register upper layer callback function to handle the PHY confirms/indications
 *
 * \param pPD_MAC_SapHandler    Upper layer callback function for Data messages
 * \param pPLME_MAC_SapHandler  Upper layer callback function for Management messages
 * \param instanceId            Instance of the PHY layer
 *
 ********************************************************************************** */
void Phy_RegisterSapHandlers(PD_MAC_SapHandler_t pPD_MAC_SapHandler, PLME_MAC_SapHandler_t pPLME_MAC_SapHandler, instanceId_t instanceId);

/*! *********************************************************************************
 * \brief This is the entry point for the PHY data service requests
 *
 * \param pMsg        Pointer to the request
 * \param instanceId  Instance of the PHY layer
 *
 * \return phyStatus_t
 *
 ********************************************************************************** */
phyStatus_t MAC_PD_SapHandler(macToPdDataMessage_t * pMsg, instanceId_t phyInstance);

/*! *********************************************************************************
 * \brief This is the entry point for the PHY management service requests
 *
 * \param pMsg        Pointer to the request
 * \param instanceId  Instance of the PHY layer
 *
 * \return phyStatus_t
 *
 ********************************************************************************** */
phyStatus_t MAC_PLME_SapHandler(macToPlmeMessage_t * pMsg, instanceId_t phyInstance);

/*! *********************************************************************************
 * \brief This function will schedule the next event to expire
 *
 ********************************************************************************** */
void PhyTime_Maintenance ( void );

/*! *********************************************************************************
 * \brief This function will run the callback of the next event scheduled
 *
 ********************************************************************************** */
void PhyTime_RunCallback ( void );

/*! *********************************************************************************
 * \brief Function to be called from the PHY timer compare match ISR
 *
 ********************************************************************************** */
void PhyTime_ISR ( void );

/*! *********************************************************************************
 * \brief Initialize the PHY timer module
 *
 * \param cb Callback function used to handle a timer compare match event.
 *           If NULL, the PhyTime_RunCallback() and the PhyTime_Maintenance()
 *           functions will be called from ISR context
 *
 * \return phyTimeStatus_t
 *
 ********************************************************************************** */
phyTimeStatus_t    PhyTime_TimerInit ( void (*cb)(void) );

/*! *********************************************************************************
 * \brief Deinitialize the PHY timer module
 *
 ********************************************************************************** */
void PhyTime_TimerDeinit ( void );

/*! *********************************************************************************
 * \brief Return a 64-bit time-stamp in symbols
 *
 * \return time-stamp
 *
 ********************************************************************************** */
phyTime_t          PhyTime_GetTimestamp ( void );

/*! *********************************************************************************
 * \brief This function schedules a timed event.
 *        The event context is given by the configuration structure.
 *
 * \param pEvent Pointer to the event data
 *
 * \return Id of the event, or gInvalidTimerId_c if the event cannot be scheduled
 *
 ********************************************************************************** */
phyTimeTimerId_t   PhyTime_ScheduleEvent( phyTimeEvent_t *pEvent );

/*! *********************************************************************************
 * \brief Cancel a specific scheduled event
 *
 * \param timerId The id of the event to schedule
 *
 * \return phyTimeStatus_t
 *
 ********************************************************************************** */
phyTimeStatus_t    PhyTime_CancelEvent  ( phyTimeTimerId_t timerId );

/*! *********************************************************************************
 * \brief Cancel all schedules events which has a specific parameter specified
 *
 * \param param Parameter to match the event(s) to be cancel
 *
 * \return phyTimeStatus_t
 *
 ********************************************************************************** */
phyTimeStatus_t    PhyTime_CancelEventsWithParam ( uint32_t param );

bool_t PhyTime_can_sleep();

/*! *********************************************************************************
 * \brief Set the low-power state of the PHY
 *
 * \param state  The new power state
 *
 * \return phyStatus_t
 *
 ********************************************************************************** */
phyStatus_t        PhyPlmeSetPwrState( uint8_t state );

/*! *********************************************************************************
* \brief  This function enables the Phy ISR
*
********************************************************************************** */
void PHY_Enable(void);

/*! *********************************************************************************
* \brief  This function disables the Phy ISR
*
********************************************************************************** */
void PHY_Disable(void);

/*! *********************************************************************************
* \brief  This function enables/disables(cslPeriod = 0) CSL IE inclusion in Enanced ACK
*
********************************************************************************** */
void PHY_EnableCsl(instanceId_t phyInstance, uint32_t cslPeriod);

void PHY_SetEfp(instanceId_t phyInstance, bool_t state);

void PHY_SetNbt(instanceId_t phyInstance, bool_t state);

/*! *********************************************************************************
* \brief  This function sets CSL sample time in PHY in us
*
********************************************************************************** */
void PHY_SetCslSampleTime(instanceId_t phyInstance, uint32_t cslSampleTimeUs);


/*! *********************************************************************************
* \brief  Copy data to/from packet ram in a safe manner
*
********************************************************************************** */
void PHY_MemCpy(uint8_t *dst, volatile uint8_t *src, uint32_t len);

void PHY_MemCpyVerify(volatile uint8_t *dst, uint8_t *src, uint32_t len);

/*! *********************************************************************************
* \brief  Confiure IE data that will be put in an Enhaced ack
*
* \param[in]  pIeData pointer to IE data
* \param[in]  ieDataLen IE data len, if > 0 add entry, if = 0 remove entry
* \param[in]  shortAddr short address of the peer device
* \param[in]  extAddr extended address of the peer device
*
********************************************************************************** */
void PHY_ConfigureAckIeData(instanceId_t phyInstance, uint8_t * pIeData, uint32_t ieDataParam, uint16_t shortAddr, uint8_t *extAddr);

/*! *********************************************************************************
* \brief  Clear IE data array
*
********************************************************************************** */
void PHY_ClearAckIeData(instanceId_t id);

/*! *********************************************************************************
* \brief  returns true if XCVR allow sleep, retruns false others ways
*
********************************************************************************** */
bool PHY_XCVR_AllowLowPower(void);

void PHY_allow_sleep();
void PHY_disallow_sleep();

#ifdef PHY_LP_TMR
phyTimeStatus_t phy_lp_time_init(void (*cb)());
void phy_lp_time_deinit();
phyTimeTimerId_t phy_lp_time_sched_ev(phyTimeEvent_t *ev);
phyTimeStatus_t phy_lp_time_cancel_ev(phyTimeTimerId_t id);
uint64_t phy_lp_time_get_timestamp();
#endif

#ifdef __cplusplus
}
#endif

#endif  /* _PHY_INTERFACE_H */
/*! *********************************************************************************
* @}
********************************************************************************** */
