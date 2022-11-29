/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_H
#define NETC_ETH_IP_H

/**
*   @file Netc_Eth_Ip.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
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
#include "Netc_Eth_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_VENDOR_ID                    43
#define NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_SW_MAJOR_VERSION             0
#define NETC_ETH_IP_SW_MINOR_VERSION             9
#define NETC_ETH_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Types.h */
#if (NETC_ETH_IP_VENDOR_ID != NETC_ETH_IP_TYPES_VENDOR_ID)
    #error "Netc_Eth_Ip.h and Netc_Eth_Ip_Types.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip.h and Netc_Eth_Ip_Types.h are different"
#endif
#if ((NETC_ETH_IP_SW_MAJOR_VERSION != NETC_ETH_IP_TYPES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_SW_MINOR_VERSION != NETC_ETH_IP_TYPES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_SW_PATCH_VERSION != NETC_ETH_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip.h and Netc_Eth_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define ETH_43_NETC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

NETC_ETH_IP_CONFIG_EXT

#define ETH_43_NETC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

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
#define ETH_43_NETC_START_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

/*!
 * @brief Initializes the ENETC station interface
 *
 * This function initializes and enables the ENETC station instance, configuring receive and transmit control
 * settings, the receive and transmit descriptors rings and the MAC physical address.
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] config Pointer to the instance configuration structure
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS The initialization was successful.
 * @retval NETC_ETH_IP_STATUS_TIMEOUT The initialization returned a timeout.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_Init(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);

/*!
 * @brief Gets the current power state of the NETC instance
 *
 * @param[in] CtrlIndex Instance number
 * @return Netc_Eth_Ip_PowerStateType The power state of the controller
 */
Netc_Eth_Ip_PowerStateType Netc_Eth_Ip_GetPowerState(uint8 CtrlIndex);

/*!
 * @brief Enables the specified SI.
 *
 * @param[in] ctrlIndex SI number
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS The initialization was successful.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_EnableController(uint8 ctrlIndex);

/*!
 * @brief Disables the controller and resets all the configured transmit and receive buffers
 *
 * Warning: This function ignores all pending transmission and reception requests
 *
 * @param[in] ctrlIndex SI number
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS The controller was successfully disabled.
 * @retval NETC_ETH_IP_STATUS_ERROR   The controller cannot be disabled because of consuming pending ring.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DisableController(uint8 ctrlIndex);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function provides an internal buffer which can further be used by the application
 * to store the transmit data.
 *
 * Note: The buffer will be marked as locked and won't be released until after a call to
 * Netc_Eth_Ip_GetTransmitStatus for the same buffer returns NETC_ETH_IP_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to get a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]     ctrlIndex Instance number
 * @param[in]     ring   Ring number
 * @param[in,out] buff   In:  Buffer containing the desired length
 *                       Out: Buffer containing the granted length or available length in case of overflow.
 * @param[out]    buffId Index of the buffer (descriptor) within the ring.
 *                       If this information is not needed, this parameter should be NULL_PTR.
 * @retval NETC_ETH_IP_STATUS_SUCCESS The buffer has been successfully locked.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY All buffers are currently in use for the current ring.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH The buffer length is smaller than minium of frame length.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxBuff(uint8 ctrlIndex,
                                             uint8 ring,
                                             Netc_Eth_Ip_BufferType *buff,
                                             uint16 *buffId);

/*!
 * @brief Sends an Ethernet frame
 *
 * This function sends an Ethernet frame, contained in the buffer received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffer until after a call
 * to Netc_Eth_Ip_GetTransmitStatus for the same buffer returns NETC_ETH_IP_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] ring The ring number
 * @param[in] buff The buffer containing the frame
 * @param[in] options Configuration options applicable to this buffer's transmission only.
 * Can be NULL_PTR, if no special option is required.
 * @retval NETC_ETH_IP_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval NETC_ETH_IP_STATUS_TX_QUEUE_FULL There is no available space for the frame in the queue.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH Length of the external buffer is smaller than minium of frame length.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendFrame(uint8 ctrlIndex,
                                             uint8 ring,
                                            Netc_Eth_Ip_BufferType * buff,
                                             const Netc_Eth_Ip_TxOptionsType * options
                                            );


/*!
 * @brief Sends an Ethernet frame which is scattered in multiple buffers
 *
 * This function sends an Ethernet frame, contained in the buffers received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffer until after a call
 * to Netc_Eth_Ip_GetTransmitStatus for the same buffer returns NETC_ETH_IP_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] ring The ring number
 * @param[in] Buffers The list of buffers containing the frame
 * @param[in] options Configuration options applicable to this buffer's transmission only.
 *                    Can be NULL_PTR, if no special option is required.
 * @param[in] NumBuffers Number of buffers available in Buffers
 * @retval NETC_ETH_IP_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval NETC_ETH_IP_STATUS_TX_QUEUE_FULL There is no available space for the frame in the queue.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH Length of the external buffer is smaller than minium of frame length.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendMultiBufferFrame(uint8 ctrlIndex,
                                                        uint8 ring,
                                                        Netc_Eth_Ip_BufferType Buffers[],
                                                        const Netc_Eth_Ip_TxOptionsType *options,
                                                        uint16 NumBuffers);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function will verify if there are enough descriptors free and that each of
 * the descriptors can hold the parts of the frame to be send using Netc_Eth_Ip_SendMultiBufferFrame.
 *
 * Note: This function will only return the first buffer descriptor index starting with which the
 * multi buffer frame can be sent.
 *
 * Important: This function is meant for internal use only and will be called from an upper layer to get
 * the first buffer descriptor index from a sequence of buffers that will be used for sending a
 * multi buffer frame.
 *
 * @param[in]     ctrlIndex     Instance number
 * @param[in]     ring          Ring number
 * @param[in]     NumBuffers    Number of buffers
 * @param[in]     BufferLength  List with the length of each chunk of the frame
 * @param[out]    buffId        Index of the buffer (descriptor) within the ring.
 * @retval NETC_ETH_IP_STATUS_SUCCESS The buffer has been successfully locked.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY All buffers are currently in use for the current ring.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH The buffer length is smaller than minium of frame length.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxMultiBuff(uint8 ctrlIndex,
                                                  uint8 ring,
                                                  uint16 NumBuffers,
                                                  const uint16 BufferLength[],
                                                  uint16 *buffId);

/*!
 * @brief Reads a received Ethernet frame
 *
 * This function reads the first received Ethernet frame in the Rx queue. The buffer received
 * as parameter will be updated by the driver and the .data field will point to a memory area
 * containing the frame data.
 *
 * Note: Once the application finished processing the buffer, it could be reused by the
 * driver for further receptions by invoking Netc_Eth_Ip_ProvideRxBuff.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to read a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]  ctrlIndex Instance number
 * @param[in]  ring The ring number
 * @param[out] buff The buffer containing the frame
 * @param[out] info Enhanced information related to the data contained by this receive buffer.
 * If this information is not needed, this parameter should be NULL_PTR.
 * @retval NETC_ETH_IP_STATUS_SUCCESS        A frame was successfully read.
 * @retval NETC_ETH_IP_STATUS_RX_QUEUE_EMPTY There is no available frame in the queue.
 * @retval NETC_ETH_IP_STATUS_ERROR       There is at least an error in reception.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ReadFrame(uint8 ctrlIndex,
                                             uint8 ring,
                                             Netc_Eth_Ip_BufferType *buff,
                                             Netc_Eth_Ip_RxInfoType *info
                                            );

/*!
 * @brief Provides a receive buffer to be used by the driver for reception.
 *
 * This function provides a buffer which can further be used by the reception mechanism
 * in order to store the received data.
 *
 * Note: The application can either provide a buffer previously obtained in a Netc_Eth_Ip_ReadFrame
 * call (when it is no longer needed after being fully processed), or allocate a new buffer.
 * The former approach is recommended as it has a simpler usage model and re-uses the same initial
 * memory range for the entire driver lifetime operation. The later approach could provide more
 * flexibility, but since it involves constant memory free/alloc operations it is only recommended
 * with an efficient pool-based memory allocator.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to provide a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * Important: The application is responsible for providing one Rx buffer for every frame it
 * receives, otherwise the reception ring can fill-up, affecting further reception.
 *
 * Usage example:
 *
 * stat = Netc_Eth_Ip_ReadFrame(0U, 0U, &rxBuff);
 *
 * if (stat == NETC_ETH_IP_STATUS_SUCCESS)
 * {
 *     process_buffer(&rxBuff);
 *     Netc_Eth_Ip_ProvideRxBuff(0U, 0U, &rxBuff);
 * }
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] ring The ring number
 * @param[in] buff The buffer to be added to the reception ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ProvideRxBuff(uint8 ctrlIndex,
                                                 uint8 ring,
                                                 const Netc_Eth_Ip_BufferType *buff);

/**
 * @brief This function will be used when RX should be used at maximum capacity, instead of providing
 *        one by one buffer for reception, a batch of buffers will be provided
 *
 * @param[in] CtrlIndex Instance number.
 * @param[in] Ring      The ring number.
 * @param[in] BuffList  This should be NULL_PTR if internal buffers are used, otherwise this should respect
 *                  the follwing indications:
 *                   - List of the external buffers used for descriptor restauration;
 * @param[inout] BuffListSize [IN]  Number of buffers in list. When the internal buffers are in use, this parameter shall
 *                                  contain the number of BD which need to be restored after a reception of a more than one packet.
 *                            [OUT] Returns how many Buffer Descriptors have been released.
 * @retval NETC_ETH_IP_STATUS_SUCCESS Execution with success.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ProvideMultipleRxBuff(uint8 CtrlIndex,
                                                         uint8 Ring,
                                                         uint8* BuffList[],
                                                         uint16* BuffListSize);

/*!
 * @brief Checks if there are more frames available in the given queue
 *
 * This function takes a peek at the given Rx queue to check if there are more Ethernet
 * frames to be received. Its intended usage is to provide this information without
 * also extracting the frame as "Netc_Eth_Ip_ReadFrame".
 *
 * @param[in]  ctrlIndex Instance number
 * @param[in]  ring The ring number
 * @retval TRUE  There is an available frame in the queue.
 * @retval FALSE There is no available frame in the queue.
 */
boolean Netc_Eth_Ip_IsFrameAvailable(uint8 ctrlIndex,
                                     uint8 ring
                                    );
/*!
 * @brief Checks if the transmission of a buffer is complete.
 *
 * This function checks if the transmission of the given buffer is complete.
 *
 * TODO: Descrition should be improved to indicate that this is not normally
 * needed in regular transmit workflow since GetTxBuff already exposes HW
 * consumption of TX entries
 *
 * Note: If the buffer is not found in the Tx ring, the function will return NETC_ETH_IP_STATUS_BUFF_NOT_FOUND.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  ring The ring number
 * @param[in]  buff The transmit buffer for which the status shall be checked
 * @param[out] info Extended information related to the buffer. If this information is not needed,
 * this parameter should be NULL_PTR.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY    The frame is still enqueued for transmission.
 * @retval NETC_ETH_IP_STATUS_BUFF_NOT_FOUND  The buffer was not found in the Tx queue.
 * @retval NETC_ETH_IP_STATUS_ERROR        There is at least an error in transmission.
 * @retval NETC_ETH_IP_STATUS_SUCCESS         Otherwise.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTransmitStatus(uint8 ctrlIndex,
                                                     uint8 ring,
                                                     const Netc_Eth_Ip_BufferType * buff,
                                                     Netc_Eth_Ip_TxInfoType * info
                                                    );

/*!
 * @brief Configures the physical address of the MAC
 *
 * @param[in] CtrlIndex Instance number
 * @param[in] MacAddr The MAC address to be configured
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS Physical address of mac is configured successfully.
 * @retval NETC_ETH_IP_STATUS_TIMEOUT Changing the physical address was not changed because a timeout has occured.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMacAddr(uint8 CtrlIndex, const uint8 *MacAddr);

/**
 * @brief Gets the physical address of the MAC for a controller.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[out] MacAddr The physical address of the MAC
 */
void Netc_Eth_Ip_GetMacAddr(uint8 CtrlIndex, uint8 *MacAddr);

/**
 * @brief Gets statistics from the specified counter
 *
 * @param[in] CtrlIndex Instance number
 * @param[in] Counter The counter to be read
 * @return The value of the requested counter
 */
uint32 Netc_Eth_Ip_GetCounter(uint8 CtrlIndex, Netc_Eth_Ip_CounterType Counter);

/**
 * @brief Adds a hardware address to the hash filter. The destination address of
 * an incoming packet is passed through hash function and then is added as an
 * entry in the hash table.
 *
 * @param[in] CtrlIndex Instance number.
 * @param[in] MacAddr   Destination MAC address to be added in hash filter.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL - MAC table used for hash filter is full
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMulticastDstAddrToHashFilter(uint8 CtrlIndex, const uint8 *MacAddr);

/**
 * @brief Removes a hardware address from the hash filter. The destination address of
 * an incoming packet is passed through hash function and then is removed from
 * hash table.
 *
 * @param[in] CtrlIndex Instance number.
 * @param[in] MacAddr   Destination MAC address to be removed from hash filer.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND - the current destination MAC was not
 *                                found in the hash filter table
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter(uint8 CtrlIndex, const uint8 *MacAddr);

/**
 * @brief Enables/Disables forwarding of the multicast traffic.
 *
 * @param[in]  CtrlIdx Instance number
 * @param[in]  Enable  TRUE -> cotroller will receive all the multicast traffic;
 *                     FALSE-> cotroller will stop receive all the multicast traffic;
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMulticastForwardAll(uint8 CtrlIndex, boolean EnableMulticast);

/**
 * @brief Disable multicast promiscuous and delete all entries in multicast MAC filter table.
 *
 * @param[in] CtrlIdx Instance number.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_CloseMulticastReceiving(uint8 CtrlIndex);
/**
 * @brief Realease multiple transmission buffers at once.
 *
 * @param CtrlIdx Instance number.
 * @param Ring    Ring number.
 */
void Netc_Eth_Ip_ReleaseTxBuffers(uint8 CtrlIdx, uint8 Ring);

/**
 * @brief Set the threshold values for Rx coalescing interrupt.
 *
 * @param[in]  CtrlIdx  Controller number
 * @param[in]  RingIdx  Ring Index on which the settings will be applied.
 * @param[in]  PacketsThreshold  No of packets after which the ISR will be triggered. Must be different than 0 in order to set the value.
 * @param[in]  TimerThreshold  No of ticks after which the ISR will be triggered. Must be different than 0 in order to set the value.
 *
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR - Either the coalescing interrupt is not enabled or the No of packets passed exceedes the
 *                                                        size of the ring.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetRxCoalescingThresholds(uint8 CtrlIdx, uint8 RingIdx, uint16 PacketsThreshold, uint32 TimerThreshold);

/**
 * @brief Set the threshold values for Tx coalescing interrupt.
 *
 * @param[in]  CtrlIdx  Controller number
 * @param[in]  RingIdx  Ring Index on which the settings will be applied.
 * @param[in]  PacketsThreshold  No of packets after which the ISR will be triggered. Must be different than 0 in order to set the value.
 * @param[in]  TimerThreshold  No of ticks after which the ISR will be triggered. Must be different than 0 in order to set the value.
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR - Either the coalescing interrupt is not enabled or the No of packets passed exceedes the
 *                                                        size of the ring.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetTxCoalescingThresholds(uint8 CtrlIdx, uint8 RingIdx, uint16 PacketsThreshold, uint32 TimerThreshold);

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
/**
 * @brief Set management information for a frame which will be send using management.
 *
 * @param CtrlIdx Instance number
 * @param BuffIdx Uniq buffer index id.
 * @param ManagementInfo Pointer to the timestamp information for frame identified by BuffIdx.
 * @param Status Enable/Disable management transmission on this frame.
 */
void Netc_Eth_Ip_ManagementFrame(uint8 CtrlIdx, uint16 BuffIdx, const Netc_Eth_Ip_TxTimestampInfoType *ManagementInfo, boolean Status);

/**
 * @brief
 *
 * @param CtrlIndex Instance number
 * @param Ring
 * @return void
 */
void Netc_Eth_Ip_ReleaseUnusedTxBuff(uint8 CtrlIndex, uint8 Ring);

/**
 * @brief
 *
 * @param CtrlIdx Instance number
 * @param BuffIdx Uniq buffer index id.
 * @return Netc_Eth_Ip_StatusType
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxTimestampInfo(const uint8 CtrlIdx, const uint32 BuffIdx, Netc_Eth_Ip_TxTimestampInfoType **TimestampInfo);

#endif /* NETC_ETH_0_USED */

/**
 * @brief
 *
 * @param CtrlIdx
 * @param DataPtr
 * @param RxTimestampInfo
 * @return Netc_Eth_Ip_StatusType
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetRxTimestampInfo(uint8 CtrlIdx, const uint8 *DataPtr, Netc_Eth_Ip_RxTimestampInfoType **RxTimestampInfo);

#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/**
 * @brief
 *
 * @param ctrlIndex
 * @param TimePtr
 */
void Netc_Eth_Ip_GetCurrentTime(uint8 ctrlIndex, Netc_Eth_Ip_TimeType *TimePtr);

#define ETH_43_NETC_STOP_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif
