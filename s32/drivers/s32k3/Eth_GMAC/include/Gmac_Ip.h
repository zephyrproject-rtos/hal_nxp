/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GMAC_IP_H
#define GMAC_IP_H

/**
*   @file
*
*   @addtogroup GMAC_DRIVER GMAC Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip_Types.h"
#include "Gmac_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_VENDOR_ID                      43
#define GMAC_IP_AR_RELEASE_MAJOR_VERSION       4
#define GMAC_IP_AR_RELEASE_MINOR_VERSION       7
#define GMAC_IP_AR_RELEASE_REVISION_VERSION    0
#define GMAC_IP_SW_MAJOR_VERSION               3
#define GMAC_IP_SW_MINOR_VERSION               0
#define GMAC_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip_Types.h */
#if (GMAC_IP_VENDOR_ID != GMAC_IP_TYPES_VENDOR_ID)
    #error "Gmac_Ip.h and Gmac_Ip_Types.h have different vendor ids"
#endif
#if (( GMAC_IP_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_MINOR_VERSION    != GMAC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_REVISION_VERSION != GMAC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip.h and Gmac_Ip_Types.h are different"
#endif
#if (( GMAC_IP_SW_MAJOR_VERSION != GMAC_IP_TYPES_SW_MAJOR_VERSION) || \
     ( GMAC_IP_SW_MINOR_VERSION != GMAC_IP_TYPES_SW_MINOR_VERSION) || \
     ( GMAC_IP_SW_PATCH_VERSION != GMAC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip.h and Gmac_Ip_Types.h are different"
#endif

/* Checks against Gmac_Ip_Cfg.h */
#if (GMAC_IP_VENDOR_ID != GMAC_IP_CFG_VENDOR_ID)
    #error "Gmac_Ip.h and Gmac_Ip_Cfg.h have different vendor ids"
#endif
#if (( GMAC_IP_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_MINOR_VERSION    != GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_AR_RELEASE_REVISION_VERSION != GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip.h and Gmac_Ip_Cfg.h are different"
#endif
#if (( GMAC_IP_SW_MAJOR_VERSION != GMAC_IP_CFG_SW_MAJOR_VERSION) || \
     ( GMAC_IP_SW_MINOR_VERSION != GMAC_IP_CFG_SW_MINOR_VERSION) || \
     ( GMAC_IP_SW_PATCH_VERSION != GMAC_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip.h and Gmac_Ip_Cfg.h are different"
#endif


/*******************************************************************************
 * GLOBAL VARIABLE DECLARATIONS
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

GMAC_CONFIG_EXT

#define ETH_43_GMAC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*******************************************************************************
 * API
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

/*!
 * @name Initialization and De-initialization
 * @{
 */

/*!
 * @brief Initializes the GMAC module
 *
 * This function initializes and enables the GMAC module, configuring receive and transmit control
 * settings, the receive and transmit descriptors rings, and the MAC physical address.
 *
 * Note: All untagged packets will be received by ring 0 (zero). VLAN tagged
 * packets are routed depending on the VLAN Tag Priority field according to
 * the provided configuration.
 *
 * @param[in] instance Instance number
 * @param[in] config Pointer to the module configuration structure
 *
 * @retval GMAC_STATUS_SUCCESS The initialization was successful.
 * @retval GMAC_STATUS_TIMEOUT The DMA subsystem reset could not complete.
 */
Gmac_Ip_StatusType Gmac_Ip_Init(uint8 Instance,
                                const Gmac_CtrlConfigType *Config);

/*!
 * @brief Deinitializes the GMAC module
 *
 * This function disables the interrupts and then disables the GMAC module.
 *
 * @param[in] instance Instance number
 */
void Gmac_Ip_Deinit(uint8 Instance);

/*!
 * @brief Gets the current power state of the GMAC module
 *
 * @param[in] instance Instance number
 * @return Gmac_Ip_PowerStateType The power state of the controller
 */
Gmac_Ip_PowerStateType Gmac_Ip_GetPowerState(uint8 Instance);

/*!
 * @brief Sets the power state of the GMAC module
 *
 * @param[in] instance   Instance number
 * @param[in] powerState Power state to transition into
 */
void Gmac_Ip_SetPowerState(uint8 Instance, Gmac_Ip_PowerStateType PowerState);

/*!
 * @brief Enables all configured transmit and receive buffers and then enables the controller
 *
 * @param[in] instance   Instance number
 */
void Gmac_Ip_EnableController(uint8 Instance);

/*!
 * @brief Disables the controller and resets all the configured transmit and receive buffers
 *
 * Warning: This function ignores all pending transmission and reception requests
 *
 * @param[in] instance   Instance number
 *
 * @retval GMAC_STATUS_SUCCESS Tthe controller was successfully disabled.
 * @retval GMAC_STATUS_TIMEOUT Tthe underlying MTL queues could not be flushed.
 */
Gmac_Ip_StatusType Gmac_Ip_DisableController(uint8 Instance);

/*!
 * @brief Sets the speed of the MII interface
 *
 * @param[in] instance Instance number
 * @param[in] speed MII speed
 */
void Gmac_Ip_SetSpeed(uint8 Instance, Gmac_Ip_SpeedType Speed);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function provides an internal buffer which can further be used by the application
 * to store the transmit data.
 *
 * Note: The buffer will be marked as locked and won't be released until after a call to
 * Gmac_Ip_GetTransmitStatus for the same buffer returns GMAC_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to get a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]     instance Instance number
 * @param[in]     ring   Ring number
 * @param[in,out] buff   In:  Buffer containing the desired length
 *                       Out: Buffer containing the granted length or available length in case of overflow.
 * @param[out]    buffId Index of the buffer (descriptor) within the ring.
 *                       If this information is not needed, this parameter should be NULL_PTR.
 * @retval GMAC_STATUS_SUCCESS The buffer has been successfully locked.
 * @retval GMAC_STATUS_TX_BUFF_BUSY All buffers are currently in use.
 * @retval GMAC_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 */
Gmac_Ip_StatusType Gmac_Ip_GetTxBuff(uint8 Instance,
                                     uint8 Ring,
                                     Gmac_Ip_BufferType * Buff,
                                     uint16 * BuffId);

/*!
 * @brief Sends an Ethernet frame
 *
 * This function sends an Ethernet frame, contained in the buffer received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffer until after a call
 * to Gmac_Ip_GetTransmitStatus for the same buffer returns GMAC_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] instance Instance number
 * @param[in] ring The ring number
 * @param[in] buff The buffer containing the frame
 * @param[in] options Configuration options applicable to this buffer's transmission only.
 * Can be NULL_PTR, if no special option is required.
 * @retval GMAC_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval GMAC_STATUS_TX_QUEUE_FULL There is no available space for the frame in the queue.
 */
Gmac_Ip_StatusType Gmac_Ip_SendFrame(uint8 Instance,
                                     uint8 Ring,
                                     const Gmac_Ip_BufferType * Buff,
                                     const Gmac_Ip_TxOptionsType * Options);

/*!
 * @brief Sends an Ethernet frame composed out of multiple buffers (not necessarily contiguous)
 *
 * This function sends an Ethernet frame contained in the buffers received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffers until after a call
 * to Gmac_Ip_GetTransmitStatus for the same buffer returns GMAC_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] Instance   Instance number
 * @param[in] Ring       The ring number
 * @param[in] Buffers    The contiguous buffer array composing the frame
 * @param[in] Options    Configuration options applied to the transmitted frame.
 *                       Must be different from NULL_PTR.
 * @param[in] NumBuffers The size of the Buffers array
 * @retval GMAC_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval GMAC_STATUS_TX_QUEUE_FULL There is no available space for the frame in the queue.
 */
Gmac_Ip_StatusType Gmac_Ip_SendMultiBufferFrame(uint8 Instance,
                                                uint8 Ring,
                                                const Gmac_Ip_BufferType Buffers[],
                                                const Gmac_Ip_TxOptionsType *Options,
                                                uint32 NumBuffers);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function will verify if there are enough descriptors free and that each of
 * the descriptors can hold the parts of the frame to be send using Gmac_Ip_SendMultiBufferFrame.
 *
 * Note: This function will only return the first buffer descriptor index starting with which the
 * multi buffer frame can be sent.
 *
 * Important: This function is meant for internal use only and will be called from an upper layer to get
 * the first buffer descriptor index from a sequence of buffers that will be used for sending a
 * multi buffer frame.
 *
 * @param[in]     Instance     Instance number
 * @param[in]     ring          Ring number
 * @param[in]     NumBuffers    Number of buffers
 * @param[in]     BufferLength  List with the length of each chunk of the frame
 * @param[out]    buffId        Index of the buffer (descriptor) within the ring.
 * @retval GMAC_STATUS_SUCCESS The buffer has been successfully locked.
 * @retval GMAC_STATUS_TX_BUFF_BUSY All buffers are currently in use for the current ring.
 * @retval GMAC_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 * @retval GMAC_STATUS_INVALID_FRAME_LENGTH The buffer length is smaller than minium of frame length.
 */
Gmac_Ip_StatusType Gmac_Ip_GetTxMultiBuff(uint8 Instance,
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
 * driver for further receptions by invoking Gmac_Ip_ProvideRxBuff.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to read a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]  instance Instance number
 * @param[in]  ring The ring number
 * @param[out] buff The buffer containing the frame
 * @param[out] info Enhanced information related to the data contained by this receive buffer.
 * If this information is not needed, this parameter should be NULL_PTR.
 * @retval GMAC_STATUS_SUCCESS        A frame was successfully read.
 * @retval GMAC_STATUS_RX_QUEUE_EMPTY There is no available frame in the queue.
 */
Gmac_Ip_StatusType Gmac_Ip_ReadFrame(uint8 Instance,
                                     uint8 Ring,
                                     Gmac_Ip_BufferType * Buff,
                                     Gmac_Ip_RxInfoType * Info);

/*!
 * @brief Provides a receive buffer to be used by the driver for reception.
 *
 * This function provides a buffer which can further be used by the reception mechanism
 * in order to store the received data.
 *
 * Note: The application can either provide a buffer previously obtained in a Gmac_Ip_ReadFrame
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
 * stat = Gmac_Ip_ReadFrame(INST_GMAC1, 0U, &rxBuff);
 *
 * if (stat == GMAC_STATUS_SUCCESS)
 * {
 *     process_buffer(&rxBuff);
 *     Gmac_Ip_ProvideRxBuff(INST_GMAC1, 0U, &rxBuff);
 * }
 *
 * @param[in] instance Instance number
 * @param[in] ring The ring number
 * @param[in] buff The buffer to be added to the reception ring
 */
void Gmac_Ip_ProvideRxBuff(uint8 Instance,
                           uint8 Ring,
                           const Gmac_Ip_BufferType * Buff);

/*!
 * @brief Checks if there are more frames available in the given queue
 *
 * This function takes a peek at the given Rx queue to check if there are more Ethernet
 * frames to be received. Its intended usage is to provide this information without
 * also extracting the frame as "Gmac_Ip_ReadFrame".
 *
 * @param[in]  instance Instance number
 * @param[in]  ring The ring number
 * @retval TRUE  There is an available frame in the queue.
 * @retval FALSE There is no available frame in the queue.
 */
boolean Gmac_Ip_IsFrameAvailable(uint8 Instance,
                                 uint8 Ring);

/*!
 * @brief Checks if the transmission of a buffer is complete.
 *
 * This function checks if the transmission of the given buffer is complete.
 *
 * Note: If the buffer is not found in the Tx ring, the function will return GMAC_STATUS_BUFF_NOT_FOUND.
 *
 * @param[in]  instance Instance number
 * @param[in]  ring The ring number
 * @param[in]  buff The transmit buffer for which the status shall be checked
 * @param[out] info Extended information related to the buffer. If this information is not needed,
 * this parameter should be NULL_PTR.
 * @retval GMAC_STATUS_BUSY            The frame is still enqueued for transmission.
 * @retval GMAC_STATUS_BUFF_NOT_FOUND  The buffer was not found in the Tx queue.
 * @retval GMAC_STATUS_SUCCESS         Otherwise.
 */
Gmac_Ip_StatusType Gmac_Ip_GetTransmitStatus(uint8 Instance,
                                             uint8 Ring,
                                             const Gmac_Ip_BufferType * Buff,
                                             Gmac_Ip_TxInfoType * Info);
void Gmac_Ip_SetRxExternalBuffer(uint8 Instance,
                           uint8 Ring,
                           const Gmac_Ip_BufferType * Buff);
/*!
 * @brief Gets statistics from the specified counter
 *
 * @param[in] instance Instance number
 * @param[in] counter The counter to be read
 * @return The value of the requested counter
 */
uint32 Gmac_Ip_GetCounter(uint8 Instance,
                          Gmac_Ip_CounterType Counter);

/*!
 * @brief Enables the MDIO interface
 *
 * @param[in] instance Instance number
 * @param[in] miiPreambleDisabled Enables/disables prepending a preamble to the MII management frame.
 * @param[in] clock provide module
 */
void Gmac_Ip_EnableMDIO(uint8 Instance,
                        boolean MiiPreambleDisabled,
                        uint32 ModuleClk);

/*!
 * @brief Reads the selected register of the PHY
 *
 * @param[in]  instance Instance number
 * @param[in]  phyAddr PHY device address
 * @param[in]  phyReg PHY register address
 * @param[out] data Data read from the PHY
 * @param[in] timeoutMs Timeout for the read operation (in milliseconds)
 * @retval GMAC_STATUS_SUCCESS The operation completed successfully.
 * @retval GMAC_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Gmac_Ip_StatusType Gmac_Ip_MDIORead(uint8 Instance,
                                    uint8 PhyAddr,
                                    uint8 PhyReg,
                                    uint16 *Data,
                                    uint32 TimeoutMs);

/*!
 * @brief Writes the selected register of the PHY
 *
 * @param[in] instance Instance number
 * @param[in] phyAddr PHY device address
 * @param[in] phyReg PHY register address
 * @param[in] data Data to be written in the specified register of the PHY
 * @param[in] timeoutMs Timeout for the write operation (in milliseconds)
 * @retval GMAC_STATUS_SUCCESS The operation completed successfully.
 * @retval GMAC_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Gmac_Ip_StatusType Gmac_Ip_MDIOWrite(uint8 Instance,
                                     uint8 PhyAddr,
                                     uint8 PhyReg,
                                     uint16 Data,
                                     uint32 TimeoutMs);

/*!
 * @brief Reads a register of the specified MMD in a PHY device
 *
 * @param[in]  instance Instance number
 * @param[in]  phyAddr PHY device address
 * @param[in]  mmd The MMD index of the target register
 * @param[in]  phyReg PHY register address
 * @param[out] data Data read from the PHY
 * @param[in] timeoutMs Timeout for the read operation (in milliseconds)
 * @retval GMAC_STATUS_SUCCESS The operation completed successfully.
 * @retval GMAC_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Gmac_Ip_StatusType Gmac_Ip_MDIOReadMMD(uint8 Instance,
                                       uint8 PhyAddr,
                                       uint8 Mmd,
                                       uint16 PhyReg,
                                       uint16 *Data,
                                       uint32 TimeoutMs);

/*!
 * @brief Writes a register of the specified MMD in a PHY device
 *
 * @param[in] instance Instance number
 * @param[in] phyAddr PHY device address
 * @param[in] mmd The MMD index of the target register
 * @param[in] phyReg PHY register address
 * @param[in] data Data to be written in the specified register of the PHY
 * @param[in] timeoutMs Timeout for the write operation (in milliseconds)
 * @retval GMAC_STATUS_SUCCESS The operation completed successfully.
 * @retval GMAC_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Gmac_Ip_StatusType Gmac_Ip_MDIOWriteMMD(uint8 Instance,
                                        uint8 PhyAddr,
                                        uint8 Mmd,
                                        uint16 PhyReg,
                                        uint16 Data,
                                        uint32 TimeoutMs);

/*!
 * @brief Configures the physical address of the MAC
 *
 * @param[in] instance Instance number
 * @param[in] macAddr The MAC address to be configured
 */
void Gmac_Ip_SetMacAddr(uint8 Instance,
                        const uint8 *MacAddr);

/*!
 * @brief Gets the physical address of the MAC
 *
 * @param[in]  instance Instance number
 * @param[out] macAddr The physical address of the MAC
 */
void Gmac_Ip_GetMacAddr(uint8 Instance,
                        uint8 *MacAddr);
/*!
 * @brief Initialize time aware shaper
 *
 * @param[in]  instance Instance number
 * @param[in]  Parameters of controller will be used.
 * return GMAC_STATUS_SUCCESS write/read to Gate control registers successfully
 * return GMAC_STATUS_TIMEOUT write/read to Gate control registers failed
 */
Gmac_Ip_StatusType Gmac_Ip_TxTimeAwareShaperInit(uint8 Instance,
                                                const Gmac_CtrlConfigType *Config);

/*!
 * @brief Gets a mask of the common interrupt events which occurred.
 *
 * @param[in] instance Instance number
 * @return A logical OR of "Gmac_Ip_InterruptType"
 */
uint32 Gmac_Ip_GetInterruptFlags(uint8 Instance);


/*!
 * @brief Gets a mask of the interrupt events associated to a channel which occurred.
 *
 * @param[in] instance Instance number
 * @param[in] channel Channel number
 * @return A logical OR of "Gmac_Ip_ChInterruptType"
 */
uint32 Gmac_Ip_GetChInterruptFlags(uint8 Instance,
                                   uint8 Channel);

/*!
 * @brief Enables/Disables forwarding of the broadcast traffic.
 *
 * @param[in]  instance Instance number
 * @param[in]  enable   If true, the application will receive all the broadcast
 * traffic; if false, it stops forwarding this kind of traffic.
 */
void Gmac_Ip_SetBroadcastForwardAll(uint8 Instance,
                                    boolean Enable);

/*!
 * @brief Enables/Disables forwarding of the multicast traffic, irrespective of
 * the destination MAC address.
 *
 * @param[in]  instance Instance number
 * @param[in]  enable If true, the application will receive all the multicast
 * traffic; if false, stops forwarding this kind of traffic.
 */
void Gmac_Ip_SetMulticastForwardAll(uint8 Instance,
                                    boolean Enable);

/*!
 * @brief Enables/Disables hash filtering for unicast traffic.
 *
 * Note: When the hash filter is disabled, the addresses are passed through the
 * perfect filter. By default, the perfect filter contains the hardware address
 * configured when the MAC module is initialized. This address is always used
 * for destination address filtering. Optionally, a second filter can be enabled
 * by the means of Gmac_Ip_SetAddrPerfectFilter() function.
 *
 * @param[in]  instance Instance number
 * @param[in]  enable   If true, the hash filtering for unicast destination
 * addresses is enabled; if false, the hash filtering for such traffic is
 * disabled.
 */
void Gmac_Ip_SetUnicastHashFilter(uint8 Instance,
                                  boolean Enable);

/*!
 * @brief Enables/Disables hash filtering for multicast traffic.
 *
 * Note: When the hash filter is disabled, the addresses are passed through the
 * perfect filter. By default, the perfect filter contains the hardware address
 * configured when the MAC module is initialized. This address is always used
 * for destination address filtering. Optionally, a second filter can be enabled
 * by the means of Gmac_Ip_SetAddrPerfectFilter() function.
 *
 * @param[in]  instance Instance number
 * @param[in]  enable   If true, the hash filtering for multicast destination
 * addresses is enabled; if false, the hash filtering for such traffic is
 * disabled.
 */
void Gmac_Ip_SetMulticastHashFilter(uint8 Instance,
                                    boolean Enable);

/*!
 * @brief Enables/Disables either hash or perfect filters. If the destination
 * address of an incoming packet passes either the perfect filter or the hash
 * filter, the packet is forwarded to the application.
 *
 * Note: When the hash filter is disabled, the addresses are passed through the
 * perfect filter. By default, the perfect filter contains the hardware address
 * configured when the MAC module is initialized. This address is always used
 * for destination address filtering. Optionally, a second filter can be enabled
 * by the means of Gmac_Ip_SetAddrPerfectFilter() function.
 *
 * @param[in]  instance Instance number
 * @param[in]  enable   If true, the hash filtering and perfect filtering for
 * destination addresses are enabled; if false, only one filtering option is
 * enabled, depending on unicast/multicast hash filter settings.
 */
void Gmac_Ip_SetHashOrPerfectFilter(uint8 Instance,
                                    boolean Enable);

/*!
 * @brief Adds a hardware address to the hash filter. The destination address of
 * an incoming packet is passed through CRC logic and then compared to the
 * entries in the hash table.
 *
 * @param[in]  instance Instance number
 * @param[in]  macAddr  The physical address
 */
void Gmac_Ip_AddDstAddrToHashFilter(uint8 Instance,
                                    const uint8 *MacAddr);

/*!
 * @brief Removes a hardware address from the hash filter. The destination
 * address of an incoming packet is passed through CRC logic and then compared
 * to the entries in the hash table.
 *
 * @param[in]  instance Instance number
 * @param[in]  macAddr  The physical address
 */
void Gmac_Ip_RemoveDstAddrFromHashFilter(uint8 Instance,
                                         const uint8 *MacAddr);

/*!
 * @brief Sets the second destination/source address perfect filter.
 *
 * Note: By default, the perfect filter contains the hardware address
 * configured when the MAC module is initialized. This address is always used
 * for destination address filtering. Optionally, a second filter
 * can be enabled by the means of this function. This filter allows the
 * selection of destination or source address checking and group filtering.
 * Only one address can be configured and it's respective mask for group
 * filtering. The mask is 6 bits long and is used for comparing each of the MAC
 * Address bytes. When set high, the MAC does not compare the corresponding byte
 * of received destination address or source address with the configured MAC
 * address. You can filter a group of addresses by masking one or more bytes of
 * the address. When configuring the source address inverse filter, all the traffic
 * that matches the configured source address will be rejected and the traffic that
 * does not match the configured source address is accepted. The source address filter
 * (either normal or inverse) result and the destination address filter result are
 * AND'ed to decide whether the packet to be accepted. This means that the packet is
 * dropped if either filter fails. The packet is accepted only if the packet passes
 * both filters.
 *
 * @param[in]  instance  Instance number
 * @param[in]  macAddr   The physical address
 * @param[in]  mask      Group filter mask
 * @param[in]  addrType  Selects between destination address filter, source
 * address filter or source address inverse filter
 * @param[in]  enable    If true, the application will receive all the traffic
 * matching the selected filter; if false, it stops forwarding this kind of traffic.
 */
void Gmac_Ip_SetAddrPerfectFilter(uint8 Instance,
                                  const uint8 *MacAddr,
                                  const uint8 Mask,
                                  const Gmac_Ip_MacAddrFilterType AddrType,
                                  boolean Enable);

#if FEATURE_GMAC_ARP_EN
/*!
 * @brief Enables/Disables ARP offloading.
 *
 * @param[in]  instance Instance number
 * @param[in]  dstAddr The IPv4 destination address used for ARP offloading
 * @param[in]  enable If true, the MAC can recognize an incoming ARP request and
 * schedules the ARP response for transmission. It also forwards the ARP packet
 * to the application; if false, the MAC receiver does not recognize any ARP
 * packet and indicates them as Type frame.
 */
void Gmac_Ip_SetArpOffloading(uint8 Instance,
                              const uint8 *DstAddr,
                              boolean Enable);
#endif /* FEATURE_GMAC_ARP_EN */

/*!
 * @brief Enable and set VLAN control for transmitted and received packets.
 *
 * @param[in]  instance      Instance number
 * @param[in]  vlanConfig    VLAN configuration structure
 */
void Gmac_Ip_EnableVlan(uint8 Instance,
                        const Gmac_Ip_VlanConfigType * VlanConfig);

/*!
 * @brief Sets outer VLAN type and tag to be inserted by a particular
 * transmission ring.
 *
 * @param[in]  instance            Instance number
 * @param[in]  ring                Ring number
 * @param[in]  vlanType            VLAN type (S-VLAN or C-VLAN) to be used
 * @param[in]  vlanTag             Value for the VLAN tag to be used
 * @retval GMAC_STATUS_SUCCESS     The ring was successfully configured.
 * @retval GMAC_STATUS_BUSY        The resource is busy and the ring could not be
 *                                 configured.
 * @retval GMAC_STATUS_TIMEOUT     The ring configuration could not complete before
 *                                 expiration of timeout.
 * @retval GMAC_STATUS_UNSUPPORTED The function was called when VLAN replacement
 *                                 option was configured.
 */
Gmac_Ip_StatusType Gmac_Ip_SetTxOuterVlanTagForInsertion(uint8 Instance,
                                                         uint8 Ring,
                                                         Gmac_Ip_VlanType VlanType,
                                                         uint16 VlanTag);

/*!
 * @brief Sets outer VLAN tag to be replaced for all transmission rings.
 *
 * @param[in]  instance            Instance number
 * @param[in]  vlanType            VLAN type (S-VLAN or C-VLAN) to be used
 * @param[in]  vlanTag             Value for the VLAN tag to be used
 * @retval GMAC_STATUS_SUCCESS     The rings were successfully configured.
 * @retval GMAC_STATUS_UNSUPPORTED The function was called when VLAN insertion
 *                                 option was configured.
 */
Gmac_Ip_StatusType Gmac_Ip_SetTxOuterVlanTagForReplacement(uint8 Instance,
                                                           Gmac_Ip_VlanType VlanType,
                                                           uint16 VlanTag);

/*!
 * @brief Sets inner VLAN type and tag to be inserted/replaced on transmission.
 *
 * @param[in]  instance      Instance number
 * @param[in]  vlanType      VLAN type (S-VLAN or C-VLAN) to be used
 * @param[in]  vlanTag       Value for the VLAN tag to be used
 */
void Gmac_Ip_SetTxInnerVlanTag(uint8 Instance,
                               Gmac_Ip_VlanType VlanType,
                               uint16 VlanTag);

#if (FEATURE_GMAC_VLAN_RX_FILTERS_NUM > 0U)
/*!
 * @brief Enables/disables and configures the Rx filters for VLAN tag.
 *
 * @param[in]  instance      Instance number
 * @param[in]  enable        Enables/Disables the Rx filter for VLAN tag
 * @param[in]  rxFilter      Rx filter options for VLAN tag comparison
 */
void Gmac_Ip_SetVlanTagRxFilter(uint8 Instance,
                                boolean Enable,
                                const Gmac_Ip_VlanRxFilterType * RxFilter);

/*!
 * @brief Adds a VLAN Tag to the Rx filter.
 *
 * @param[in]  instance           Instance number
 * @param[in]  filterIdx          Index of the VLAN filter
 * @param[in]  vlanTag            Vlan Tag to be added to the Rx filter
 * @retval GMAC_STATUS_SUCCESS    The filter was successfully configured.
 * @retval GMAC_STATUS_TIMEOUT    The filter configuration could not complete
 *                                before expiration of timeout.
 */
Gmac_Ip_StatusType Gmac_Ip_AddVlanTagToRxFilter(uint8 Instance,
                                                uint8 FilterIdx,
                                                uint16 VlanTag);

/*!
 * @brief Read a VLAN Tag Rx filter.
 *
 * @param[in]  instance           Instance number
 * @param[in]  filterIdx          Index of the VLAN filter
 * @param[out] vlanTag            Vlan Tag configured for the selcted Rx filter
 * @retval GMAC_STATUS_SUCCESS    The filter was successfully read.
 * @retval GMAC_STATUS_TIMEOUT    The filter could not be read before expiration
 *                                of timeout.
 */
Gmac_Ip_StatusType Gmac_Ip_ReadVlanTagRxFilter(uint8 Instance,
                                               uint8 FilterIdx,
                                               uint16 * VlanTag);

/*!
 * @brief Clear a VLAN Tag Rx filter.
 *
 * @param[in]  instance           Instance number
 * @param[in]  filterIdx          Index of the VLAN filter
 * @retval GMAC_STATUS_SUCCESS    The filter was successfully cleared.
 * @retval GMAC_STATUS_TIMEOUT    The filter could not be cleared before
 *                                expiration of timeout.
 */
Gmac_Ip_StatusType Gmac_Ip_ClearVlanTagRxFilter(uint8 Instance,
                                                uint8 FilterIdx);
#endif

/*!
 * @brief Adds a VLAN Tag to the Hash Table filter.
 *
 * @param[in]  instance      Instance number
 * @param[in]  vlanTag       Vlan Tag to be added to the hash table
 */
void Gmac_Ip_AddVlanTagToHashTable(uint8 Instance,
                                   uint16 VlanTag);

/*!
 * @brief Removes a VLAN Tag from the hash table filter.
 *
 * @param[in]  instance      Instance number
 * @param[in]  vlanTag       Vlan Tag to be removed from the hash table
 */
void Gmac_Ip_RemoveVlanTagFromHashTable(uint8 Instance,
                                        uint16 VlanTag);

/*!
 * @brief Initialize system time.
 *
 * @param[in]  instance       Instance number
 * @param[in]  sysTimeConfig  Pointer to a structure representing the configuration
 *                            of the system time
 */
void Gmac_Ip_InitSysTime(uint8 Instance,
                         const Gmac_Ip_SysTimeConfigType * SysTimeConfig);

/*!
 * @brief Set system time correction.
 *
 * @param[in]  instance           Instance number
 * @param[in]  offset             Chooses between negative and positive correction
 * @param[in]  secondsUpdate      The seconds part of the update
 * @param[in]  nanosecondsUpdate  The nanoseconds part of the update
 * @retval GMAC_STATUS_SUCCESS    The correction was set with no error.
 * @retval GMAC_STATUS_TIMEOUT    The correction could not be set before
 *                                expiration of timeout.
 */
Gmac_Ip_StatusType Gmac_Ip_SetSysTimeCorr(uint8 Instance,
                                          Gmac_Ip_SysTimeCorrOffsetType Offset,
                                          uint32 SecondsUpdate,
                                          uint32 NanoSecondsUpdate);

/*!
 * @brief Set system time correction.
 *
 * @param[in]  instance           Instance number
 * @param[in]  rateRatio          Rate ratio is used to sync
 * @retval GMAC_STATUS_SUCCESS    The correction was set with no error.
 * @retval GMAC_STATUS_TIMEOUT    The correction could not be set before
 *                                expiration of timeout.
 */
Gmac_Ip_StatusType Gmac_Ip_SetRateRatioCorr(uint8 Instance,
                                            float64 RateRatio
                                           );

/*!
 * @brief Gets the current system time.
 *
 * @param[in]  instance      Instance number
 * @param[out] timestamp     Pointer to a structure representing the current
 *                           system time
 */
void Gmac_Ip_GetSysTime(uint8 Instance, Gmac_Ip_TimestampType * Timestamp);

/*!
 * @brief Sets the transmitter scheduling algorithm.
 *
 * @param[in] instance Instance number
 * @param[in] scheme   Transmitter scheduling algorithm.
 */
void Gmac_Ip_SetTxSchedAlgo(uint8 Instance, Gmac_Ip_TxSchedAlgoType SchedAlgo);

/*!
 * @brief Sets the weight (in WRR scheduling algorithm) for a particular Tx ring.
 *
 * Note: If multiple rings are configured and the WWR scheduling algorithm is
 * selected, the weight must be programmed with a non-zero value. The maximum
 * value for the weight is 0x64.
 *
 * @param[in] instance Instance number
 * @param[in] ring     Tx ring
 * @param[in] weight   Tx ring weight
 */
void Gmac_Ip_SetTxRingWeight(uint8 Instance, uint8 Ring, uint32 Weight);

/*!
 * @brief Enables the store and forward feature on the transmit path.
 *
 * When the store and forward feature is enabled, the MAC starts to transmit
 * data only when a complete packet is stored in the Transmit Queue.
 *
 * @param[in] instance Instance number
 * @param[in] ring     Tx ring
 */
void Gmac_Ip_EnableTxStoreAndForward(uint8 Instance, uint8 Ring);

/*!
 * @brief Sets transmit threshold levels.
 *
 * @param[in] instance       Instance number
 * @param[in] ring           Tx ring
 * @param[in] thresholdValue The threshold value
 */
void Gmac_Ip_SetTxThreshold(uint8 Instance,
                            uint8 Ring,
                            Gmac_Ip_TxThresholdType ThresholdValue);

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_H */

