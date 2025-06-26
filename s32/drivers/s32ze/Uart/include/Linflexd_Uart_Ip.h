/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef LINFLEXD_UART_IP_H
#define LINFLEXD_UART_IP_H

/**
*   @file
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
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
#include "Linflexd_Uart_Ip_Types.h"
#include "Linflexd_Uart_Ip_Cfg.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_VENDOR_ID                    43
#define LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION     4
#define LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION     7
#define LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION  0
#define LINFLEXD_UART_IP_SW_MAJOR_VERSION             2
#define LINFLEXD_UART_IP_SW_MINOR_VERSION             0
#define LINFLEXD_UART_IP_SW_PATCH_VERSION             1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip_Types.h */
#if (LINFLEXD_UART_IP_VENDOR_ID != LINFLEXD_UART_IP_TYPES_VENDOR_ID)
    #error "Linflexd_Uart_Ip.h and Linflexd_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip.h and Linflexd_Uart_Ip_Types.h are different"
#endif
#if ((LINFLEXD_UART_IP_SW_MAJOR_VERSION != LINFLEXD_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_SW_MINOR_VERSION != LINFLEXD_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_SW_PATCH_VERSION != LINFLEXD_UART_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip.h and Linflexd_Uart_Ip_Types.h are different"
#endif

/* Checks against Linflexd_Uart_Ip_Cfg.h */
#if (LINFLEXD_UART_IP_VENDOR_ID != LINFLEXD_UART_IP_CFG_VENDOR_ID)
    #error "Linflexd_Uart_Ip.h and Linflexd_Uart_Ip_Cfg.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip.h and Linflexd_Uart_Ip_Cfg.h are different"
#endif
#if ((LINFLEXD_UART_IP_SW_MAJOR_VERSION != LINFLEXD_UART_IP_CFG_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_SW_MINOR_VERSION != LINFLEXD_UART_IP_CFG_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_SW_PATCH_VERSION != LINFLEXD_UART_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip.h and Linflexd_Uart_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"
/* Calling the external Configuration symbols defined by Linflexd_Uart_Ip_Cfg.h */
LINFLEXD_UART_IP_CONFIG_EXT
#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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

#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

/**
 * @brief Sets the baud rate for UART communication.
 *
 * @details This function computes the fractional and integer parts of the baud rate divisor
 *          to obtain the desired baud rate using the current protocol clock.
 *
 * @param[in] Instance     - LINFLEXD hardware instance number.
 * @param[in] DesiredBaudRate - Desired baud rate.
 * @param[in] ClockFrequency  - the current clock frequency used in the baud rate parameters calculations.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY    - A trasfer is ongoing, therefore a baurate value change can't be possible.
 * @retval LINFLEXD_UART_IP_STATUS_ERROR   - Error in changing the baudrate.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Baudrate value changed successfully.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_SetBaudrate(const uint8 Instance,
                                                         const Linflexd_Uart_Ip_BaudrateType DesiredBaudRate,
                                                         const uint32 ClockFrequency
                                                         );


/**
 * @brief Gets the baud rate for UART communication.
 *
 * @details This function returns the current UART baud rate, according to register values
 * and the protocol clock frequency.
 *
 * @param[in] Instance         - LINFLEXD hardware instance number.
 * @param[out] ConfiguredBaudRate - Pointer to a valid memory location where the current baudrate value will be provided.
 * @return void
 */
void Linflexd_Uart_Ip_GetBaudrate(const uint8 Instance, uint32 * ConfiguredBaudRate);


/**
 * @brief Initializes a LINFLEXD instance for UART operations.
 *
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param UserConfig[in]  - User configuration structure.
 * @return void
 */
void Linflexd_Uart_Ip_Init(const uint8 Instance, const Linflexd_Uart_Ip_UserConfigType * UserConfig);


/**
 * @brief Shuts down the UART functionality of the LINFLEXD module
 * by disabling interrupts and transmitter/receiver.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @retval LINFLEXD_UART_IP_STATUS_ERROR   - The current transfer processes are not finished completely
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation ended successfully.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_Deinit(const uint8 Instance);

/**
 * @brief Sets the internal driver reference to the tx buffer.
 *
 * @details This function can be called from the tx callback to provide the driver
 * with a new buffer, for continuous transmission.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param TxBuff[in]     - Source buffer containing 8-bit data chars to send.
 * @param TxSize[in]   - The number of bytes to send.
 * @return void
 */
void Linflexd_Uart_Ip_SetTxBuffer(const uint8 Instance, const uint8 * TxBuff, const uint32 TxSize);


/**
 * @brief Sets the internal driver reference to the rx buffer.
 *
 * @details This function can be called from the rx callback to provide the driver
 * with a new buffer, for continuous reception.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param TxBuff[in]     - Source buffer containing 8-bit data chars to receive.
 * @param TxSize[in]   - The number of bytes to receive.
 * @return void
*/
void Linflexd_Uart_Ip_SetRxBuffer(const uint8 Instance, uint8 * RxBuff, const uint32 RxSize);


/**
 * @brief Terminates a non-blocking receive early.
 *
 * @param Instance[in] - LINFLEXD hardware instance number
 *
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation has been successfully ended or no operation was on-going.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AbortReceivingData(const uint8 Instance);


/**
 * @brief Terminates a non-blocking transfer(send) early.
 *
 * @param Instance[in] - LINFLEXD hardware instance number
 *
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation has been successfully ended or no operation was on-going.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AbortSendingData(const uint8 Instance);


/**
 * @brief Sends data using LINFLEXD module in UART mode with polling method.
 *
 * @details Blocking means that the function does not return until the transmission is complete.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param TxBuff[in]     - Source buffer containing 8-bit data chars to send.
 * @param TxSize[in]   - TxBuff size.
 * @param Timeout[in]       Timeout value in microseconds.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY    - A trasfer is ongoing, therefore a new transfer can't begin.
 * @retval LINFLEXD_UART_IP_STATUS_ERROR   - Error in transmission.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation ended successfully.
 * @retval LINFLEXD_UART_IP_STATUS_TIMEOUT - Operation has timeout.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_SyncSend(const uint8 Instance, const uint8 *TxBuff, const uint32 TxSize, const uint32 Timeout);

/**
 * @brief Sends data using LINFLEXD module in UART mode with polling method.
 *
 * @details Blocking means that the function does not return until the transmission is complete.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param RxBuff[in]     - Source buffer containing 8-bit data chars to receive.
 * @param RxSize[in]   - RxBuff size.
 * @param Timeout[in]       Timeout value in microseconds.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY    - A trasfer is ongoing, therefore a new transfer can't begin.
 * @retval LINFLEXD_UART_IP_STATUS_ERROR   - Error in reception.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation ended successfully.
 * @retval LINFLEXD_UART_IP_STATUS_TIMEOUT - Operation has timeout.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_SyncReceive(const uint8 Instance, uint8 * RxBuff, const uint32 RxSize, const uint32 Timeout);

/**
 * @brief Starts data reception from the LINFLEXD module in UART mode with non-blocking method.
 * @details This enables an a-sync method for receiving data. When used with
 * a non-blocking transmission, the UART driver can perform a full duplex operation.
 * Non-blocking means that the function returns immediately.
 * The application has to get the receive status to know when the receive is complete.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param RxBuff[in]     - Buffer containing 8-bit read data chars to be received.
 * @param RxSize[in]   - Size of RxBuff.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY    - A trasfer is ongoing, therefore a new transfer can't begin.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation started successfully.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AsyncReceive(const uint8 Instance, uint8 * RxBuff, const uint32 RxSize);

/**
 * @brief Sends data using LINFLEXD module in UART mode with non-blocking method.
 *
 * @details This enables an a-sync method for transmitting data. When used with
 * a non-blocking receive, the UART driver can perform a full duplex operation.
 * Non-blocking  means that the function returns immediately.
 * The application has to get the transmit status to know when the transmission is complete.
 *
 * @param Instance[in] - LINFLEXD hardware instance number.
 * @param TxBuff[in]     - source buffer containing 8-bit data chars to send.
 * @param TxSize[in]   -  the number of bytes to send.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY    - A trasfer is ongoing, therefore a new transfer can't begin.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Operation started successfully.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_AsyncSend(const uint8 Instance, const uint8 * TxBuff, const uint32 TxSize);


/**
 * @brief Returns whether the status of the previous transmission.
 *
 * @param Instance[in]      - LINFLEXD hardware instance number.
 * @param BytesRemaining[out] - Pointer to value that is populated with the number of bytes that
 *                               have been sent in the active transfer.
 *        @note In DMA mode, this parameter may not be accurate, in case the transfer completes
 *              right after calling this function; in this edge-case, the parameter will reflect
 *              the initial transfer size, due to automatic reloading of the major loop count
 *              in the DMA transfer descriptor.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY    - A trasfer is ongoing.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS - Previous operation ended successfully.
 * @retval LINFLEXD_UART_IP_STATUS_ERROR   - Previous operation had a DMA error.
 * @retval LINFLEXD_UART_IP_STATUS_ABORTED - Previous transfer has been aborted
 * @retval LINFLEXD_UART_IP_STATUS_DMA_ERROR - Previous transfer has DMA errors.
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_GetTransmitStatus(const uint8 Instance, uint32 * BytesRemaining);


/**
 * @brief Returns whether the status of the previous reception.
 *
 * @param Instance[in]      - LINFLEXD hardware instance number
 * @param BytesRemaining[out] - Pointer to value that is filled  with the number of bytes that
 *                               still need to be received in the active transfer.
 *        @note The parameter BytesRemaining may not be accurate, in case the transfer completes
 *              right after calling this function; in this edge-case, this parameter will
 *              have the wrong value.
 * @return Linflexd_Uart_Ip_StatusType
 * @retval LINFLEXD_UART_IP_STATUS_BUSY          - A trasfer is ongoing.
 * @retval LINFLEXD_UART_IP_STATUS_SUCCESS       - Previous operation ended successfully.
 * @retval LINFLEXD_UART_IP_STATUS_RX_OVERRUN    - Previous operation had an overrun error.
 * @retval LINFLEXD_UART_IP_STATUS_FRAMING_ERROR - Previous operation had a framing  error.
 * @retval LINFLEXD_UART_IP_STATUS_DMA_ERROR - Previous transfer has DMA errors.
 * @retval LINFLEXD_UART_IP_STATUS_ABORTED - Previous transfer has been aborted
 * @retval LINFLEXD_UART_IP_STATUS_PARITY_ERROR - A parity error occured
 * @retval LINFLEXD_UART_IP_STATUS_NOISE_ERROR - A noise error occured
 */
Linflexd_Uart_Ip_StatusType Linflexd_Uart_Ip_GetReceiveStatus(const uint8 Instance, uint32 * BytesRemaining);

void Linflexd_Uart_Ip_IRQHandler(uint8 Instance);

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
/**
 * @internal
 * @brief   : Finish up a transmit by completing the process of sending
 * data and disabling the DMA requests. This is a part of callback for DMA major loop
 * completion, so it must match the DMA callback signature.
 * @param Instance LINFLEXD hardware instance number
 * @return void
 */
void Linflexd_Uart_Ip_CompleteSendUsingDma(uint8 Instance);

/**
 * @internal
 * @brief   : Finish up a receive by completing the process of receiving data
 * and disabling the DMA requests. This is a part of callback for DMA major loop
 * completion, so it must match the DMA callback signature.
 * @param Instance LINFLEXD hardware instance number
 * @return void
 */
void Linflexd_Uart_Ip_CompleteReceiveUsingDma(uint8 Instance);
#endif

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_DRIVER_H */
