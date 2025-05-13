/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CANEXCEL_IP_H_
#define CANEXCEL_IP_H_

/**
*   @file CanEXCEL_Ip.h
*
*   @addtogroup CanEXCEL
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
#include "CanEXCEL_Ip_DevReg.h"
#include "CanEXCEL_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_VENDOR_ID_H                      43
#define CANEXCEL_IP_AR_RELEASE_MAJOR_VERSION_H       4
#define CANEXCEL_IP_AR_RELEASE_MINOR_VERSION_H       7
#define CANEXCEL_IP_AR_RELEASE_REVISION_VERSION_H    0
#define CANEXCEL_IP_SW_MAJOR_VERSION_H               2
#define CANEXCEL_IP_SW_MINOR_VERSION_H               0
#define CANEXCEL_IP_SW_PATCH_VERSION_H               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip_Types.h are of the same vendor */
#if (CANEXCEL_IP_VENDOR_ID_H != CANEXCEL_IP_TYPES_VENDOR_ID_H)
    #error "CanEXCEL_Ip.h and CanEXCEL_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip_Types.h are of the same Autosar version */
#if ((CANEXCEL_IP_AR_RELEASE_MAJOR_VERSION_H    != CANEXCEL_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_AR_RELEASE_MINOR_VERSION_H    != CANEXCEL_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_AR_RELEASE_REVISION_VERSION_H != CANEXCEL_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
)
    #error "AutoSar Version Numbers of CanEXCEL_Ip.h and CanEXCEL_Ip_Types.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_Types.h are of the same Software version */
#if ((CANEXCEL_IP_SW_MAJOR_VERSION_H != CANEXCEL_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_SW_MINOR_VERSION_H != CANEXCEL_IP_TYPES_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_SW_PATCH_VERSION_H != CANEXCEL_IP_TYPES_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of CanEXCEL_Ip.h and CanEXCEL_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define CANEXCEL_IP_MB_RXFIFO    255U
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_43_CANEXCEL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"
/* Calling the external Configuration symbols defined by CanExcel_Ip_Cfg.h */
CANEXCEL_IP_CONFIG_EXT
#define CAN_43_CANEXCEL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"

#define CAN_43_CANEXCEL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"
CANEXCEL_IP_STATE_EXT
#define CAN_43_CANEXCEL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_CANEXCEL_START_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"
/**
 *  @brief Initializes the CanEXCEL peripheral.
 *  @details This function will config CanEXCEL module and will leave the module in freeze mode.
 *  @param[in] instance              A CanEXCEL instance number
 *  @param[in\out] pState            Pointer to the CanEXCEL driver state structure.
 *  @param[in] Config                The CanEXCEL platform configuration data
 *  @return CANEXCEL_STATUS_SUCCESS if successfull;<br>
 *          CANEXCEL_STATUS_ERROR if other error occurred;<br>
 *          CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_Init(uint8 instance, const Canexcel_Ip_ConfigType * Config, Canexcel_Ip_StateType * pState);
/**
 *  @brief     Sets the CanEXCEL Rx individual mask for descriptor
 *  @details   This function will set directly the mask value as is provided.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] descNo    Index of the message descriptor
 *  @param[in] frameType Message format type
 *  @param[in] mask      Mask value
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @return    none
 */
void Canexcel_Ip_SetRxIndividualMask(uint8 instance, uint8 descNo, Canexcel_Ip_FrameType frameType, uint32 mask);
/**
 *  @brief     CanEXCEL config XL Message for Tx with Id, SDT, VCAN, length
 *  @details   This function will config transmit parameters form Canexcel_DataInfoType and
 *             the message Id
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] mbIdx     Index of the message descriptor
 *  @param[in] id        ID of the message to transmit
 *  @param[in] info      Data info
 *  @param[in\out] TxMsg The CanEXCEL transmit message buffer pointer.
 *  @return    none
 */
void Canexcel_Ip_ConfigXlTx(uint8 instance, uint8 mbIdx, uint32 id,const Canexcel_Ip_DataInfoType * info, Canexcel_TxXlMsgType * TxMsg);
/**
 *  @brief     CanEXCEL receive message descriptor field configuration
 *  @details   This function will config receive parameters form Canexcel_DataInfoType and
 *             the message Id, and can overwritte another MB status.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] descNo   Index of the message descriptor
 *  @param[in] info     Data info
 *  @param[in] msg_id   ID of the message to transmit
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_BUSY if the descriptor is full.
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRx(uint8 instance, uint8 descNo, uint32 msgId,const Canexcel_Ip_DataInfoType * info);
/**
 *  @brief     Set the CanEXCEL message buffer storage pointer for the descriptor
 *  @details   This function will config receive message address for the descriptor where the CanEXCEL to store the received data.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] descNo   Index of the message descriptor
 *  @param[in] rxPtrList Pointer to the message buffer
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if the descriptor is not empty or inactive.
 */
Canexcel_Ip_StatusType Canexcel_Ip_RxDescriptor(uint8 instance, uint8 descNo, uint32 rxPtrList);

/**
 *  @brief     Set the CanEXCEL message buffer storage pointer for the descriptor
 *  @details   This function will config transmit message address for the descriptor where the CanEXCEL data to be sent are stored.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] descNo   Index of the message descriptor
 *  @param[in] txPtrList Pointer to the message buffer in ram
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if the descriptor is not empty or inactive.
 */
Canexcel_Ip_StatusType Canexcel_Ip_TxDescriptor(uint8 instance, uint8 descNo, uint32 txPtrList);
/**
 *  @brief Receives a CAN Classic or FD frame using the specified message buffer.
 *  @details This function receives a CAN frame using a configured message descriptor. The function
 *           returns immediately.
 *  @param[in] instance  A CanEXCEL instance number
 *  @param[in] descNo    Index of the message descriptor
 *  @param[out] RxMsg    The CanEXCEL receive message buffer pointer.
 *  @param[in] isPolling If the message will be received using pooling(true) or interrupt(false).
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if the descriptor is not empty or inactive.
 */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveFD(uint8 instance, uint8 descNo, const Canexcel_RxFdMsg * RxMsg, boolean isPolling);
/**
 *  @brief Receives a CAN XL frame using the specified message buffer.
 *  @details This function receives a CAN frame using a configured message descriptor. The function
 *           returns immediately.
 *  @param[in] instance  A CanEXCEL instance number
 *  @param[in] descNo    Index of the message descriptor
 *  @param[out] RxMsg    The CanEXCEL receive message buffer pointer.
 *  @param[in] isPolling If the message will be received using pooling(true) or interrupt(false).
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if the descriptor is not empty or inactive.
 */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveXL(uint8 instance, uint8 descNo, const Canexcel_RxXlMsg * RxMsg, boolean isPolling);
/**
 *  @brief     Sends a CAN Classic or FD frame using the specified message buffer.
 *  @details   This function configure parameters form Canexcel_DataInfoType, ID and sends data as CAN frame using a specified message buffer.
 *  @note      This function doesn't support to work with Transceiver mode PWM.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] mbIdx   Index of the message descriptor
 *  @param[in] info  Data info
 *  @param[in] id   ID of the message to transmit
 *  @param[in] dataPtr  Data Bytes of the CAN message .
 *  @param[in] TxMsg    Pointer of the FD Tx Message.
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if listen only mode or PWM transceiver mode is active.
 */
Canexcel_Ip_StatusType Canexcel_Ip_SendFDMsg(uint8 instance, uint8 mbIdx,const Canexcel_Ip_DataInfoType * info, uint32 id,const uint8 * dataPtr, Canexcel_TxFdMsgType * TxMsg);
/**
 *  @brief     Sends a CAN XL frame using the specified message buffer.
 *  @details   This function configure parameters form Canexcel_DataInfoType, ID and sends data as CAN frame using a specified message buffer.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] mbIdx   Index of the message descriptor
 *  @param[in] info  Data info
 *  @param[in] id   ID of the message to transmit
 *  @param[in] dataPtr  Data Bytes of the CAN message .
 *  @param[in] TxMsg    Pointer of the XL Tx Message.
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if listen only mode is active.
 */
Canexcel_Ip_StatusType Canexcel_Ip_SendXLMsg(uint8 instance, uint8 mbIdx,const Canexcel_Ip_DataInfoType * info, uint32 id,const uint8 * dataPtr, Canexcel_TxXlMsgType * TxMsg);
/**
 * @brief Returns whether the previous CanEXCEL transfer has finished.
 *
 * When performing an async transfer, call this function to ascertain the state of the
 * current transfer: in progress (or busy) or complete (success).
 *
 * @param[in] instance The CanEXCEL instance number.
 * @param[in] descIdx  The index of the message descriptor.
 * @return CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS if no transfer initiated;
 *         CANEXCEL_STATUS_BUSY if a resource is busy;
 *         CANEXCEL_STATUS_ERROR in case of a OverRun error transfer;
 *         CANEXCEL_STATUS_SUCCESS if a successful transfer finished.
 */
Canexcel_Ip_StatusType Canexcel_Ip_GetTransferStatus(uint8 instance, uint8 descIdx);
/**
 *  @brief     Enter CanEXCEL Module in Freeze Mode.
 *  @details   This function will suspend bus activity of CanEXCEL module and
 *             set it to Freeze Mode to allow module configuration.
 *  @param[in] instance A CanEXCEL instance number
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_EnterFreezeMode(uint8 instance);
/**
 *  @brief     Exit CanEXCEL Module from Freeze Mode.
 *  @details   This function will allow CanEXCEL module to participate to the BUS activity and
 *             restore normal opertaion of the driver.
 *  @param[in] instance A CanEXCEL instance number
 *  @note      This function should be called from FreezeMode.
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_ExitFreezeMode(uint8 instance);
/**
 *  @brief     Check a receive event.
 *  @details   This will check if message is received and read the message buffer or RxFifo.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] mb_idx   Index of the message buffer
 */
void Canexcel_Ip_MainFunctionRead(uint8 instance, uint8 mb_idx);
/**
 *  @brief     Check a Transmission event.
 *  @details   This function will check a specific Message Descriptor have been sent of CanEXCEL module and
 *             if was sent will reset the status of Mb and clear the status flag.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] mb_idx message buffer number
 *
 */
void Canexcel_Ip_MainFunctionWrite(uint8 instance, uint8 mb_idx);
/**
 *  @brief     CanEXCEL Rx FIFO field configuration
 *  @note This function requires the module to be in Stop or Freeze Mode.
 *  @param[in] instance        A CanEXCEL instance number
 *  @param[in] filterConfig Pointer to the filter configuration structure.
 *  @return CANEXCEL_STATUS_ERROR if the RxFifo wasn't activated by CanExcel_Init, or the CanExcel instance is not in freeze mode;
 *          CANEXCEL_STATUS_SUCCESS if successful.
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRxFifo(uint8 instance,const Canexcel_Ip_RxFifoFilter * filterConfig);
/**
 *  @brief     Set the CanEXCEL instance in STOP mode
 *  @details   Set the CanEXCEL instance in STOP mode, this will prevent instance to participate to
 *  bus transactions and allow configuration of the module.
 *  @param[in] instance A CanEXCEL instance number
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetStopMode(uint8 instance);
/**
 *  @brief     Get Stop Mode Status
 *  @details   Return if the instance is in Stop Mode
 *  @param[in] instance A CanEXCEL instance number
 *  @return    True instance is in STOP Mode
 *             False instance is not in STOP Mode
 */
boolean Canexcel_Ip_GetStopMode(uint8 instance);
/**
 *  @brief     Get Start Mode Status
 *  @details   Return if the instance is in Start Mode
 *  @param[in] instance A CanEXCEL instance number
 *  @return    True instance is in START Mode
 *             False instance is not in START Mode
 *
 */
boolean Canexcel_Ip_GetStartMode(uint8 instance);
/**
 * @brief Enable all interrupts configured.
 * @details Enable all interrupts configured.
 * @param[in]   u8Instance    A CanEXCEL instance number
 * @return CANEXCEL_STATUS_SUCCESS if successful operation;<br>
 *         CANEXCEL_STATUS_ERROR if the module is not in freeze Mode;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_EnableInterrupts(uint8 u8Instance);
/**
 * @brief Disable all interrupts.
 * @details Disable all interrupts.
 * @param[in]   u8Instance    A CanEXCEL instance number
 * @return CANEXCEL_STATUS_SUCCESS if successful operation;<br>
 *         CANEXCEL_STATUS_ERROR if the module is not in freeze Mode;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_DisableInterrupts(uint8 u8Instance);
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
/*!
 * @brief This function configure the timestamp settings.
 *
 * This function will allow to set the timestamp timer source and config the
 * timer selected capture point for timestamp.
 * @note  Need enable clock counter for the source selected before use Time Stamp.
 *
 *  @param[in] instance  A CanEXCEL instance number
 *  @param[in] time_stamp A timestamp configuration structure
 *  @return CANEXCEL_STATUS_SUCCESS if successful operation;<br>
 *          CANEXCEL_STATUS_ERROR if the module is not in freeze Mode;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigTimeStamp(uint8 instance, const Canexcel_Ip_TimeStampConf_Type * time_stamp);
#endif
/**
 * @brief Check if the descriptor is configured for reception of XL frame or not.
 *
 * @param[in]   u8Instance    A CanEXCEL instance number
 * @param[in]   descNo        A CanEXCEL decriptor number
 */
boolean Canexcel_Ip_IsXLFrameType(uint8 instance, uint8 descNo);
/**
 * @brief Enable\Disable an Error Interrupt
 * @note This function need to be call after the CANXL Instance is in FreezeMode
 *
 * @param[in]   u8Instance    A CanEXCEL instance number
 * @param[in]   type          Error type for wich to cofig the Interrupt
 * @param[in]   enable        TRUE will Enable the interrupt\FALSE will disable the interrupt
 *
 * @return  CANEXCEL_STATUS_SUCCESS Configured successfully.<br>
 *          CANEXCEL_STATUS_ERROR   Either interface is not in Freeze mode or not a valid error type.<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetErrorInt(uint8 u8Instance, Canexcel_Ip_ErrorIntType type, boolean enable);
/**
 * @brief Get the TxError Counter
 *
 * @param[in]   instance    A CanEXCEL instance number
 * @param[out]  pValue      Pointer to a variable to return the TxError Counter Value
 * @return CANEXCEL_STATUS_ERROR    It can not update and get the TxError Status
 *         CANEXCEL_STATUS_TIMEOUT  The device fail to react in configured time
 *         CANEXCEL_STATUS_SUCCESS  Successfully get the TxError counter value
 */
Canexcel_Ip_StatusType Canexcel_Ip_GetControllerTxErrorCounter(uint8 instance, uint8 * pValue);
/**
 * @brief Get the RxError Counter.
 *
 * @param[in]   instance    A CanEXCEL instance number
 * @param[out]  pValue      Pointer to a variable to return the RxError Counter Value
 * @return CANEXCEL_STATUS_ERROR    It can not update and get the RxError Status
 *         CANEXCEL_STATUS_TIMEOUT  The device fail to react in configured time
 *         CANEXCEL_STATUS_SUCCESS  Successfully get the RxError counter value
 */
Canexcel_Ip_StatusType Canexcel_Ip_GetControllerRxErrorCounter(uint8 instance, uint8 * pValue);
/**
 * @brief Get the CanEXCEL Controller Status.
 *
 * @param[in]   instance    A CanEXCEL instance number
 * @param[out]  pValue      Pointer to a variable to return the Controller Status
 * @return CANEXCEL_STATUS_ERROR    It can not update and get the Status
 *         CANEXCEL_STATUS_TIMEOUT  The device fail to react in configured time
 *         CANEXCEL_STATUS_SUCCESS  Successfully update and get the Controller Status
 */
Canexcel_Ip_StatusType Canexcel_Ip_GetControllerStatus(uint8 instance, uint8 * pValue);
/**
 *  @brief      Clear Error Status of CanEXCEL
 *  @details    This function will clear the error status from SYSS register in SIC module.
 *              For exact mapping of errors please refere to RM(Reference Manual)
 *              on CanEXCEL SIC->SYSS register description.
 *  @param[in]  instance: A CanEXCEL instance number
 *  @param[in]  error: errors flags to be cleared
 */
void Canexcel_Ip_ClearErrorStatus(uint8 instance, uint32 error);
/**
 *  @brief     Check a bus-off event.
 *  @details   This function will update the CanEXCEL Status and check bus activity of CanEXCEL module and
 *             if a bus off event is detected will report it through callback CANEXCEL_EVENT_BUSOFF.
 *  @param[in] instance A CanEXCEL instance number
 *  @return    CANEXCEL_STATUS_SUCCESS if successful busoff and sucessfully update the status<br>
 *             CANEXCEL_STATUS_ERROR if no busoff event detected;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to get the status in configured time<br>
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_MainFunctionBusOff(uint8 instance);
/*!
 * @brief Recover manually from bus-off if possible.
 * @note This function should be used when bus-off auto recovery disabled and controller is in START mode.
 * The function Canexcel_Ip_GetErrorStatus can be used to check FLTCONF bits to check if bus-off state is exited or not.
 *
 * @param[in]   instance A CanEXCEL instance number
 * @return CANEXCEL_STATUS_SUCCESS if successful operation or the controller wasn't in bus-off.<br>
 *         CANEXCEL_STATUS_ERROR if bus-off auto recovery enabled.<br>
 *         CANEXCEL_STATUS_TIMEOUT if fail to recover in configured time<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ManualBusOffRecovery(uint8 instance);
/**
 * @brief Sets the bit rate for the data phase of FD frames.
 * @details This function requests the CanExcel module to be Freeze Mode and FD mode enabled.
 * @param[in]   Instance            CanExcel instance number.
 * @param[in]   TimeSeg             Pointer to the bit rate settings.
 * @param[in]   BitRateSwitch       Enable/disable bit rate switching.
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetFDBaudRate(uint8 Instance, const Canexcel_Ip_TimeSegmentType * TimeSeg, boolean BitRateSwitch);
/**
 * @brief Sets the bit rate for the data phase of XL frames.
 * @details This function requests the CanExcel module to be Freeze Mode and XL mode enabled.
 * @param[in]   Instance    CanExcel instance number.
 * @param[in]   TimeSeg     Pointer to the bit rate settings.
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetXLBaudRate(uint8 Instance, const Canexcel_Ip_TimeSegmentType * TimeSeg);
/**
 * @brief Sets the bit rate for the nomimal phase of classical frame and in the arbitration phase of a FD or XL frame.
 * @details This function requests the CanExcel module to be Freeze Mode.
 * @param[in]   Instance    CanExcel instance number.
 * @param[in]   TimeSeg     Pointer to the bit rate settings.
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetBaudRate(uint8 Instance, const Canexcel_Ip_TimeSegmentType * TimeSeg);
/**
 * @brief Gets the bit rate for the data phase of FD frames.
 * @details Gets the bit rate for the data phase of FD frames.
 * @param[in]   Instance    CanExcel instance number.
 * @param[out]  TimeSeg     Pointer to the bit rate settings.
 */
void Canexcel_Ip_GetFDBaudRate(uint8 Instance, Canexcel_Ip_TimeSegmentType * TimeSeg);
/**
 * @brief Gets the bit rate for the data phase of XL frames.
 * @details Gets the bit rate for the data phase of XL frames.
 * @param[in]   Instance    CanExcel instance number.
 * @param[out]   TimeSeg     Pointer to the bit rate settings.
 */
void Canexcel_Ip_GetXLBaudRate(uint8 Instance, Canexcel_Ip_TimeSegmentType * TimeSeg);
/**
 * @brief Gets the bit rate for the nomimal phase of classical frame and in the arbitration phase of a FD or XL frame.
 * @details Gets the bit rate for the nomimal phase of classical frame and in the arbitration phase of a FD or XL frame.
 * @param[in]   Instance    CanExcel instance number.
 * @param[out]   TimeSeg     Pointer to the bit rate settings.
 */
void Canexcel_Ip_GetBaudRate(uint8 Instance, Canexcel_Ip_TimeSegmentType * TimeSeg);
/**
 *  @brief     Enable\Disable listen Only Mode
 *  @details   This function will Enable or Disable listen Only Mode.
 *  @note      This function should be called from FreezeMode.
 *  @param[in] Instance   Instance number
 *  @param[in] Enable     Enable\Disable Listen Only mode
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_ERROR if fail to set;<br>
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetListenOnlyMode(uint8 Instance, boolean Enable);
/**
 *  @brief     Get the Status of Listen Only Mode
 *  @details   This function will return True if Listen Only Mode
 *             is Enable or False if is Disable.
 *  @param[in] Instance   instance number
 *  @return    True if Listen Only Mode is Enabled
 *             False if Listen Only Mode is Disabled.
 *
 */
boolean Canexcel_Ip_GetListenOnlyMode(uint8 Instance);
/**
 * @brief Enables/Disables the FD Transceiver Delay Compensation feature and sets
 * the FD Transceiver Delay Compensation Offset.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * When the transceiver delay measurement is enabled, the secondary sample point position is determined by the sum of the transceiver delay measurement plus the CAN XL TDC offset.
 * When the transceiver delay measurement is disabled, the secondary sample point position is determined CAN XL TDC offset only.
 * @param[in]   Instance        A CanExcel instance number
 * @param[in]   TDCEnable       Enable/Disable Transceiver Delay Compensation
 * @param[in]   TDCMEnable      Enable/Disable Transceiver Delay Compensation Measurement
 * @param[in]   Offset          Transceiver Delay Compensation Offset
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetTDCOffsetFD(uint8 Instance, boolean TDCEnable, boolean TDCMEnable, uint8 Offset);
/**
 * @brief Enables/Disables the XL Transceiver Delay Compensation feature and sets
 * the XL Transceiver Delay Compensation Offset.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * When the transceiver delay measurement is enabled, the secondary sample point position is determined by the sum of the transceiver delay measurement plus the CAN XL TDC offset.
 * When the transceiver delay measurement is disabled, the secondary sample point position is determined CAN XL TDC offset only.
 * @param[in]   Instance        A CanExcel instance number
 * @param[in]   TDCEnable       Enable/Disable Transceiver Delay Compensation
 * @param[in]   TDCMEnable      Enable/Disable Transceiver Delay Compensation Measurement
 * @param[in]   Offset          Transceiver Delay Compensation Offset
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetTDCOffsetXL(uint8 Instance, boolean TDCEnable, boolean TDCMEnable, uint8 Offset);
/**
 * @brief Configures Pwm phases for Pwm symbol.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * @note    When PWM mode enabled:
 *          -  protocol exception must be enabled also
 *          -  PWMS must be in range [1:63]
 *          -  PWML must be in range [1:63]
 *          -  PWMO must be in range [0:63]
 *
 * @param[in]   Instance         A CanExcel instance number
 * @param[in]   Config           Transceiver configuration data
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigTransceiverMode(uint8 Instance, const Canexcel_Ip_TransceiverModeType * Config);
/**
 * @brief Configures Acceptance Filters for MDs on FiltersBank0.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * @note    The filters are for every bank individualy set.
 *
 * @param[in]   Instance         A CanExcel instance number
 * @param[in]   Config           Filter configurations for AFs, SDUs and VCANs
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigAccFltBank0(uint8 Instance, const Canexcel_Ip_BankFilter * Config);
/**
 * @brief Configures Acceptance Filters for MDs on FiltersBank1.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * @note    The filters are for every bank individualy set.
 *
 * @param[in]   Instance         A CanExcel instance number
 * @param[in]   Config           Filter configurations for AFs, SDUs and VCANs
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigAccFltBank1(uint8 Instance, const Canexcel_Ip_BankFilter * Config);
/**
 * @brief Configures Rejection Filters for MDs on FiltersBank0.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * @note    The filters are for every bank individualy set.
 *
 * @param[in]   Instance         A CanExcel instance number
 * @param[in]   Config           Filter configurations for AFs, SDUs and VCANs
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRejFltBank0(uint8 Instance, const Canexcel_Ip_BankFilter * Config);
/**
 * @brief Configures Rejection Filters for MDs on FiltersBank1.
 * @details This function request the CanExcel module to be in Freeze Mode.
 * @note    The filters are for every bank individualy set.
 *
 * @param[in]   Instance         A CanExcel instance number
 * @param[in]   Config           Filter configurations for AFs, SDUs and VCANs
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_ERROR if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRejFltBank1(uint8 Instance, const Canexcel_Ip_BankFilter * Config);
/**
 * @brief   Configures Acceptance Address filter for a desired filter number
 * @details This function request the CanExcel module to be in Freeze Mode.
 * @note    If the filter position is higher than the 31 it measn it is alocated in filter bank1 and is position
 *          in the filter bank is (filterNo - 32). If is lower than 32 represents the filter position from bank0.
 *          This function requires CanEXCEL instance to be set in FreezeMode.
 * @param[in]       Instance         A CanExcel instance number
 * @param[in]       filterValue      Filter configurations for AFs
 * @param[in\out]   filterNo         The filer position allocated from memory filter bank
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_BUFF_OUT_OF_RANGE no available filter postion to set the filter.<br>
 *            CANEXCEL_STATUS_ERROR if fail to set; Because is not in freezeMode;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigAccAddrFilter(uint8 Instance,const Canexcel_Ip_RxFifoFilterID_ADDR * filterValue, uint8 * filterNo);
/**
 * @brief   This function return the HardWare status of a specific Message Descriptor
 * @param[in]       Instance         A CanExcel instance number
 * @param[in]       descNo           A descriptor Number
 * @param[in/out]   sysPoint         Pointer where to return the number of the Pushed Messages in the descriptor
 * @param[in/out]   hwPoint          Pointer where to return the number of the HW processed Messages already pushed.
 * @return   CANEXCEL_DESC_STATE_INACTIVE the descriptor is not used.
             CANEXCEL_DESC_STATE_EMPTY No pushed Messages in descriptor.
             CANEXCEL_DESC_STATE_NOTFULL Can be push more messages in descriptor
             CANEXCEL_DESC_STATE_FULL The descriptor is full no more Messages can't be push
             CANEXCEL_DESC_STATE_OVERRUN Have been pushed more messages than the Depth of the Descriptor.
 */
Canexcel_Ip_DescState Canexcel_Ip_GetDescriptorStatus(uint8 Instance, uint8 descNo, uint8 * sysPoint, uint8 * hwPoint);
/**
 * @brief   This function Enable\Disable Interrput for a specific Message Descriptor
 * @param[in]       Instance         A CanExcel instance number
 * @param[in]       descNo           A descriptor Number to activate\deactivate interrupt
 * @param[in]       enable           TRUE  Enables Interrupt
 *                                   FALSE Disables Interrupt
 */
void Canexcel_Ip_SetMsgBuffInterrupt(uint8 instance, uint8 descNo, boolean enable);
/**
 * @brief   Return the Interrupt Status Flag of a Message Descriptor
 * @param[in]       instance         A CanExcel instance number
 * @param[in]       descNo           A descriptor Number to activate\deactivate interrupt
 * @return       The Interrupt Status Flag Value.
 */
uint8 Canexcel_Ip_GetMsgDescIntStatusFlag(uint8 instance, uint8 descNo);
/**
 * @brief De-activates the given Message Descriptor.
 * @details This function shall de-activate given Message descriptor and it can't participate in the message Tx or Rx process.
 * @note    The system pointer and hardware pointer of the Message descriptor equal to zero after de-activation.
 *
 * @param[in]   instance         A CanExcel instance number
 * @param[in]   descNo           the Message Descriptor index
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_TIMEOUT if fail to set;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_DeactivateMD(uint8 instance, uint8 descNo);

#if (CANXL_IP_HAS_ABORT == STD_ON)
/**
 * @brief Abort the given Message Descriptor.
 * @details This function shall abort given Message descriptor and move it to EMPTY state.
 * @note    The system pointer and hardware pointer of the Message descriptor equal to zero after abort.
 *
 * @param[in]   instance         A CanExcel instance number
 * @param[in]   descNo           the Message Descriptor index
 * @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *            CANEXCEL_STATUS_TIMEOUT if fail to set;<br>
 *            CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS if no transfer initiated before abort;<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_AbortMD(uint8 instance, uint8 descNo);
#endif

/**
 *  @brief DeInitializes the CanEXCEL peripheral.
 *  @details This function will reset CanEXCEL module at reset Values.
 *  @param[in] u8Instance            A CanEXCEL instance number
 *  @return CANEXCEL_STATUS_SUCCESS if successfull;<br>
 *          CANEXCEL_STATUS_ERROR if other error occurred;<br>
 *          CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
Canexcel_Ip_StatusType Canexcel_Ip_Deinit(uint8 u8Instance);

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CANEXCEL_IP_H_ */
