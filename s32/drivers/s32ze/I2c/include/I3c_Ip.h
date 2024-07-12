/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_H
#define I3C_IP_H

/**
*   @file
*
*   @addtogroup i3c_ip
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
#include "I3c_Ip_Cfg.h"
#include "I3c_Ip_Types.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_VENDOR_ID                    43
#define I3C_IP_MODULE_ID                    255
#define I3C_IP_AR_RELEASE_MAJOR_VERSION     4
#define I3C_IP_AR_RELEASE_MINOR_VERSION     7
#define I3C_IP_AR_RELEASE_REVISION_VERSION  0
#define I3C_IP_SW_MAJOR_VERSION             1
#define I3C_IP_SW_MINOR_VERSION             0
#define I3C_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and I3c_Ip_Cfg header file are of the same vendor */
#if (I3C_IP_VENDOR_ID != I3C_IP_VENDOR_ID_CFG)
    #error "I3c_Ip.h and I3c_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip_Cfg header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION     != I3C_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION     != I3C_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION  != I3C_IP_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of I3c_Ip.h and I3c_Ip_Cfg.h are different"
#endif

/* Check if current file and I3c_Ip_Cfg header file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION != I3C_IP_SW_MAJOR_VERSION_CFG) || \
     (I3C_IP_SW_MINOR_VERSION != I3C_IP_SW_MINOR_VERSION_CFG) || \
     (I3C_IP_SW_PATCH_VERSION != I3C_IP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of I3c_Ip.h and I3c_Ip_Cfg.h are different"
#endif

/* Check if current file and I3c_Ip_Types header file are of the same vendor */
#if (I3C_IP_VENDOR_ID != I3C_IP_VENDOR_ID_TYPES)
    #error "I3c_Ip.h and I3c_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip_Types header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION     != I3C_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION     != I3C_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION  != I3C_IP_AR_RELEASE_REVISION_VERSION_TYPES))
    #error "AutoSar Version Numbers of I3c_Ip.h and I3c_Ip_Types.h are different"
#endif

/* Check if current file and I3c_Ip_Types header file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION != I3C_IP_SW_MAJOR_VERSION_TYPES) || \
     (I3C_IP_SW_MINOR_VERSION != I3C_IP_SW_MINOR_VERSION_TYPES) || \
     (I3C_IP_SW_PATCH_VERSION != I3C_IP_SW_PATCH_VERSION_TYPES))
    #error "Software Version Numbers of I3c_Ip.h and I3c_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

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
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief   Initialize the I3C master module.
*
* @details This function initializes the I3C master module.
*
* @param[in] Instance  I3C instance
* @param[in] Config    Pointer to the configuration structure
*
*/
void I3c_Ip_MasterInit(const uint8 Instance,
                       const I3c_Ip_MasterConfigType * const Config);

/**
* @brief   Deinitialize the I3C master module.
*
* @details This function deinitializes the master module. The driver can't be used until initialized again.
*
* @param[in] Instance   I3C instance
*
*/
void I3c_Ip_MasterDeInit(const uint8 Instance);

/**
* @brief   Return the current status of the I3C master transfer.
*
* @details Return the current status of the I3C master transfer.
*          This function can be called during a non-blocking transmission to check the status of the transfer.
*          In addition, if the transfer is still in progress, this functions returns the remaining bytes to be transferred,
*          only if BytesRemaining pointer is different than NULL_PTR.
*
* @param[in]  Instance            I3C instance
* @param[out]  BytesRemaining     Remaining bytes to be transferred
*/
I3c_Ip_StatusType I3c_Ip_MasterGetTransferStatus(const uint8 Instance,
                                                 uint32 * const BytesRemaining);

/**
* @brief   Perform a blocking send transaction on the I3C bus.
*
* @details This function is used to send a block of data to the configured slave's address.
*          It only returns when the transfer is complete.
*
* @param[in] Instance       I3C instance
* @param[in] TxBuffer       Pointer to the Data buffer
* @param[in] TxBufferSize   Buffer size in bytes
* @param[in] TransferOption Transfer options
*
*/
I3c_Ip_StatusType I3c_Ip_MasterSendBlocking(const uint8 Instance,
                                            const uint8 * TxBuffer,
                                            const uint32 TxBufferSize,
                                            const I3c_Ip_TransferConfigType * const TransferOption);

/**
* @brief   Perform a blocking receive transaction on the I3C bus.
*
* @details This function is used to receive a block of data from the configured slave's address.
*          It only returns when the transfer is complete.
*
* @param[in] Instance       I3C instance
* @param[in] RxBuffer       Pointer to the Data buffer
* @param[in] RxBufferSize   Buffer size in bytes
* @param[in] TransferOption Transfer options
*
*/
I3c_Ip_StatusType I3c_Ip_MasterReceiveBlocking(const uint8 Instance,
                                               uint8 * RxBuffer,
                                               const uint32 RxBufferSize,
                                               const I3c_Ip_TransferConfigType * const TransferOption);

/**
* @brief   Perform a non-blocking send transaction on the I3C bus.
*
* @details This function is used to send a block of data to the configured slave's address.
*          It returns immediately. The rest of the transfer is handled by the interrupt service routine.
*          Use I3c_Ip_MasterGetTransferStatus() to check the progress of the transfer.
*
* @param[in] Instance       I3C instance
* @param[in] TxBuffer       Pointer to the Data buffer
* @param[in] TxBufferSize   Buffer size in bytes
* @param[in] TransferOption Transfer options
*
*/
I3c_Ip_StatusType I3c_Ip_MasterSend(const uint8 Instance,
                                    const uint8 * TxBuffer,
                                    const uint32 TxBufferSize,
                                    const I3c_Ip_TransferConfigType * const TransferOption);

/**
* @brief   Perform a non-blocking receive transaction on the I3C bus.
*
* @details This function is used to receive a block of data from the configured slave's address.
*          It returns immediately. The rest of the transfer is handled by the interrupt service routine.
*          Use I3c_Ip_MasterGetTransferStatus() to check the progress of the transfer.
*
* @param[in] Instance       I3C instance
* @param[in] RxBuffer       Pointer to the Data buffer
* @param[in] RxBufferSize   Buffer size in bytes
* @param[in] TransferOption Transfer options
*
*/
I3c_Ip_StatusType I3c_Ip_MasterReceive(const uint8 Instance,
                                       uint8 * RxBuffer,
                                       const uint32 RxBufferSize,
                                       const I3c_Ip_TransferConfigType * const TransferOption);

/**
* @brief   Initialize the I3C slave module.
*
* @details This function initializes the I3C slave module.
*
* @param[in] Instance   I3C instance
* @param[in] Config     Pointer to the configuration structure
*
*/
void I3c_Ip_SlaveInit(const uint8 Instance,
                      const I3c_Ip_SlaveConfigType * const Config);

/**
* @brief   Deinitialize the I3C slave module.
*
* @details This function deinitializes the slave module. The driver can't be used until initialized again.
*
* @param[in] Instance  I3C instance
*
*/
void I3c_Ip_SlaveDeInit(const uint8 Instance);

/**
* @brief   Return the current status of the I3C slave transfer.
*
* @details Return the current status of the I3C slave transfer.
*          This function can be called during a non-blocking transmission to check the status of the transfer.
*          In addition, if the transfer is still in progress, this functions returns the remaining bytes to be transferred,
*          only if BytesRemaining pointer is different than NULL_PTR.
*
* @param[in] Instance             I3C instance
* @param[out] BytesRemaining      Remaining bytes to be transferred
*
*/
I3c_Ip_StatusType I3c_Ip_SlaveGetTransferStatus(const uint8 Instance,
                                                uint32 * const BytesRemaining);

/**
* @brief   Returns the master error register.
*
* @details This function is used to get the entire error/warning register for the current master.
*          This may be called from the Error/Warning notification and dedicated defines should be used
*          to filter the errors/warnings which occurred.
*          Defines that can be used:
*                   - I3C_IP_MASTER_ERROR_NACK
*                   - I3C_IP_MASTER_ERROR_WRITE_ABORT
*                   - I3C_IP_MASTER_ERROR_TERM
*                   - I3C_IP_MASTER_ERROR_PARITY
*                   - I3C_IP_MASTER_ERROR_CRC
*                   - I3C_IP_MASTER_ERROR_OREAD
*                   - I3C_IP_MASTER_ERROR_OWRITE
*                   - I3C_IP_MASTER_ERROR_MSG
*                   - I3C_IP_MASTER_ERROR_INVALID_REQUEST
*                   - I3C_IP_MASTER_ERROR_TIMEOUT
*
* @param[in] Instance   I3C instance
* @return               Master error register
*
*/
uint32 I3c_Ip_MasterGetError(const uint8 Instance);

/**
* @brief   Returns the slave error register.
*
* @details This function is used to get the entire error/warning register for the current slave.
*          This may be called from the Error/Warning notification and dedicated defines should be used
*          to filter the errors/warnings which occurred.
*          Defines that can be used:
*                   - I3C_IP_SLAVE_ERROR_RX_OVERRUN
*                   - I3C_IP_SLAVE_ERROR_TX_UNDERRUN
*                   - I3C_IP_SLAVE_ERROR_TX_UNDERRUN_NACK
*                   - I3C_IP_SLAVE_ERROR_TERM
*                   - I3C_IP_SLAVE_ERROR_INVALID_START
*                   - I3C_IP_SLAVE_ERROR_SDR_PARITY
*                   - I3C_IP_SLAVE_ERROR_HDR_PARITY_ERROR
*                   - I3C_IP_SLAVE_ERROR_HDR_CRC
*                   - I3C_IP_SLAVE_ERROR_S0S1
*                   - I3C_IP_SLAVE_ERROR_OREAD
*                   - I3C_IP_SLAVE_ERROR_OWRITE
*
* @param[in] Instance   I3C instance
* @return               Slave error register
*
*/
uint32 I3c_Ip_SlaveGetError(const uint8 Instance);

/**
* @brief   Provide a buffer for the slave's data transfer.
*
* @details This function is used to set the slave's buffer for the transfer data. It also set the default RX FIFO watermark.
*          It could be called from the user callback provided at initialization.
*
* @param[in] Instance   I3C instance
* @param[in] DataBuffer Pointer to the data buffer
* @param[in] BufferSize Data buffer size in bytes
*
*/
void I3c_Ip_SlaveSetBuffer(const uint8 Instance,
                           uint8 * DataBuffer,
                           const uint8 BufferSize);

/**
 * @brief Start listening
 *
 * @details This is used to enable slave events
 *
 * @param[in] Instance  I3C peripheral instance number
 * @return void
 */
/* @implements I3c_Ip_StartListening_Activity */
void I3c_Ip_StartListening(uint8 Instance);

/**
* @brief   Set the baud rate for all subsequent I3C communications.
*
* @details This function is used to set the baud rate for all subsequent I3C communications.
*          Using this function, the baud rates will be set as close as possible to the target ones.
*          After calling this function, I3c_Ip_MasterGetBaudRate() shall be called to check which baud rates were actually set.
*
* @param[in] Instance           I3C instance
* @param[in] FunctionalClock    Value of the Functional Clock (Hz)
* @param[in] BaudRates          Pointer to the Baud rates structure: PP, OD, I2C (Hz)
* @param[in] BusType            Type of the bus: I2C, SDR, DDR
*
*/
I3c_Ip_StatusType I3c_Ip_MasterSetBaudRate(const uint8 Instance,
                                           const uint32 FunctionalClock,
                                           const I3c_Ip_MasterBaudRateType * BaudRates,
                                           const I3c_Ip_BusType BusType);

/**
* @brief   Get the baud rates of the I3C module.
*
* @details This function is used to get the baud rates of the I3C module.
*
* @param[in]  Instance           I3C instance
* @param[in]  FunctionalClock    Value of the Functional Clock (Hz)
* @param[out] BaudRates          Pointer to the Baud rates structure: PP, OD, I2C (Hz)
*
*/
void I3c_Ip_MasterGetBaudRate(const uint8 Instance,
                              const uint32 FunctionalClock,
                              I3c_Ip_MasterBaudRateType * BaudRates);

/**
* @brief   Returns the master status register.
*
* @details This function is used to get the status register for the current master.
*          Dedicated defines can be used to filter and check each status bit field: I3C_IP_MASTER_STATUS
*          For I3C_IP_MASTER_STATUS_IBIADDR, I3C_IP_MASTER_STATUS_IBITYPE, and I3C_IP_MASTER_STATUS_STATE
*          the following defines can be used to shift the masked values to get the actual value of the bit
*          fields (they have more than 1 bit length):
*                   - I3C_IP_MASTER_STATUS_IBIADDR_SHIFT
*                   - I3C_IP_MASTER_STATUS_IBITYPE_SHIFT
*                   - I3C_IP_MASTER_STATUS_STATE_SHIFT
*
* @param[in] Instance   I3C instance
* @return               Master status register
*
*/
uint32 I3c_Ip_MasterGetStatus(const uint8 Instance);

/**
* @brief   Returns the master status register.
*
* @details This function is used to get the status register for the current slave device.
*          Dedicated defines can be used to filter and check each status bit field: I3C_IP_SLAVE_STATUS
*          For I3C_IP_SLAVE_STATUS_TIMECTRL, I3C_IP_SLAVE_STATUS_ACTSTATE, and I3C_IP_SLAVE_STATUS_EVDET
*          the following defines can be used to shift the masked values to get the actual value of the bit
*          fields (they have more than 1 bit length):
*                   - I3C_IP_SLAVE_STATUS_TIMECTRL_SHIFT
*                   - I3C_IP_SLAVE_STATUS_ACTSTATE_SHIFT
*                   - I3C_IP_SLAVE_STATUS_EVDET_SHIFT
*
* @param[in] Instance   I3C instance
* @return               Slave status register
*
*/
uint32 I3c_Ip_SlaveGetStatus(const uint8 Instance);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I3C_IP_H */
