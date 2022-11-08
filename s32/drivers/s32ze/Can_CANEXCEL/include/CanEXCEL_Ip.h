/*
 * Copyright 2022 NXP
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
#define CANEXCEL_IP_SW_MAJOR_VERSION_H               0
#define CANEXCEL_IP_SW_MINOR_VERSION_H               9
#define CANEXCEL_IP_SW_PATCH_VERSION_H               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
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
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_ERROR if the instance is not in Freeze Mode.
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetRxIndividualMask(uint8 instance, uint8 descNo, Canexcel_Ip_FrameType frameType, uint32 mask);
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
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRx(uint8 instance, uint8 descNo, uint32 msgId, Canexcel_Ip_DataInfoType * info);
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
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveFD(uint8 instance, uint8 descNo, Canexcel_RxFdMsg * RxMsg, boolean isPolling);
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
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveXL(uint8 instance, uint8 descNo, Canexcel_RxXlMsg * RxMsg, boolean isPolling);
/**
 *  @brief     Sends a CAN Classic or FD frame using the specified message buffer.
 *  @details   This function configure parameters form Canexcel_DataInfoType, ID and sends data as CAN frame using a specified message buffer.
 *  @param[in] instance A CanEXCEL instance number
 *  @param[in] mbIdx   Index of the message descriptor
 *  @param[in] info  Data info
 *  @param[in] id   ID of the message to transmit
 *  @param[in] dataPtr  Data Bytes of the CAN message .
 *  @param[in] TxMsg    Pointer of the FD Tx Message.
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *             CANEXCEL_STATUS_ERROR if listen only mode is active.
 */
Canexcel_Ip_StatusType Canexcel_Ip_SendFDMsg(uint8 instance, uint8 mbIdx, Canexcel_Ip_DataInfoType * info, uint32 id, uint8 * dataPtr, Canexcel_TxFdMsgType * TxMsg);
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
Canexcel_Ip_StatusType Canexcel_Ip_SendXLMsg(uint8 instance, uint8 mbIdx, Canexcel_Ip_DataInfoType * info, uint32 id, uint8 * dataPtr,Canexcel_TxXlMsgType * TxMsg);
/**
 * @brief Returns whether the previous CanEXCEL transfer has finished.
 *
 * When performing an async transfer, call this function to ascertain the state of the
 * current transfer: in progress (or busy) or complete (success).
 *
 * @param[in] instance The CanEXCEL instance number.
 * @param[in] mbIdx   The index of the message descriptor.
 * @return CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS if no transfer initiated;
 *         CANEXCEL_STATUS_BUSY if a resource is busy;
 *         CANEXCEL_STATUS_ERROR in case of a OverRun error transfer;
 *         CANEXCEL_STATUS_SUCCESS if a successful transfer finished.
 */
Canexcel_Ip_StatusType Canexcel_Ip_GetTransferStatus(uint8 instance, uint8 mbIdx);
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
 *  @Note This function requires the module to be in Stop or Freeze Mode.
 *  @param[in] instance        A CanEXCEL instance number  
 *  @param[in] filterConfig Pointer to the filter configuration structure.
 *  @return CANEXCEL_STATUS_ERROR if the RxFifo wasn't activated by CanExcel_Init, or the CanExcel instance is not in freeze mode;
 *          CANEXCEL_STATUS_SUCCESS if successful.
 */ 
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRxFifo(uint8 instance, Canexcel_Ip_RxFifoFilter * filterConfig);
/**
 *  @brief     Set the CanEXCEL instance in STOP mode
 *  @details   Set the CanEXCEL instance in STOP mode, this will prevent instance to participate to
 *  bus transactions and allow configuration of the module.
 *  @param[in] instance A CanEXCEL instance number
 *  @return    CANEXCEL_STATUS_SUCCESS if successful;<br>
 *             CANEXCEL_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
Canexcel_Ip_StatusType Canexcel_Ip_SetStopMode(uint8 instance);
/**
 *  @brief     Get Stop Mode Status
 *  @details   Return if the instance is in Stop Mode
 *  @param[in] instance A CanEXCEL instance number
 *  @return    True instance is in STOP Mode
 *             False instance is not in STOP Mode
 *
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
 */
void Canexcel_Ip_EnableInterrupts(uint8 u8Instance);
/**
 * @brief Disable all interrupts.
 * @details Disable all interrupts.
 * @param[in]   u8Instance    A CanEXCEL instance number
 */
void Canexcel_Ip_DisableInterrupts(uint8 u8Instance);

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

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CANEXCEL_IP_H_ */
