/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_I2C_GPDMA_H_
#define FSL_I2C_GPDMA_H_

#include "fsl_i2c.h"
#include "fsl_gpdma.h"

/*!
 * @addtogroup i2c_gpdma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief I2C GPDMA driver version. */
#define FSL_I2C_GPDMA_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*! @brief Maximum lenght of single GPDMA transfer (determined by capability of the GPDMA engine) */
#define I2C_MAX_GPDMA_TRANSFER_COUNT 1024

/* Forward declaration of the transfer descriptor and handle typedefs. */
/*! @brief I2C master transfer typedef */
typedef struct _i2c_master_transfer i2c_master_transfer_t;

/*!
 * @brief Transfer option flags.
 *
 * @note These enumerations are intended to be OR'd together to form a bit mask of options for
 * the #_i2c_master_transfer::flags field.
 */
enum _i2c_master_transfer_flags
{
    kI2C_TransferDefaultFlag       = 0x00U, /*!< Transfer starts with a start signal, stops with a stop signal. */
    kI2C_TransferNoStartFlag       = 0x01U, /*!< Don't send a start condition, address, and sub address */
    kI2C_TransferRepeatedStartFlag = 0x02U, /*!< Send a repeated start condition */
    kI2C_TransferNoStopFlag        = 0x04U, /*!< Don't send a stop condition. */
};

/*! @brief States for the state machine used by transactional APIs. */
enum _i2c_transfer_states
{
    kIdleState = 0,
    kTransmitSubaddrState,
    kTransmitDataState,
    kReceiveDataState,
    kStartState,
    kStopState,
    kWaitForCompletionState
};

/*!
 * @brief Non-blocking transfer descriptor structure.
 *
 * This structure is used to pass transaction parameters to the I2C_MasterTransferNonBlocking() API.
 */
struct _i2c_master_transfer
{
    uint32_t flags; /*!< Bit mask of options for the transfer. See enumeration #_i2c_master_transfer_flags for available
                       options. Set to 0 or #kI2C_TransferDefaultFlag for normal transfers. */
    uint16_t slaveAddress;     /*!< The 7-bit slave address. */
    i2c_direction_t direction; /*!< Either #kI2C_Read or #kI2C_Write. */
    uint32_t subaddress;       /*!< Sub address. Transferred MSB first. */
    size_t subaddressSize;     /*!< Length of sub address to send in bytes. Maximum size is 4 bytes. */
    void *data;                /*!< Pointer to data to transfer. */
    size_t dataSize;           /*!< Number of bytes to transfer. */
};

/*! @brief I2C master gpdma handle typedef. */
typedef struct _i2c_master_gpdma_handle i2c_master_gpdma_handle_t;

/*! @brief I2C master gpdma transfer callback typedef. */
typedef void (*i2c_master_gpdma_transfer_callback_t)(I2C_Type *base,
                                                     i2c_master_gpdma_handle_t *handle,
                                                     status_t status,
                                                     void *userData);

/*! @brief I2C master gpdma transfer structure. */
struct _i2c_master_gpdma_handle
{
    uint8_t state;                /*!< Transfer state machine current state. */
    uint32_t remainingBytesGPDMA; /*!< Remaining byte count to be transferred using GPDMA. */
    uint8_t *buf;                 /*!< Buffer pointer for current state. */
    uint32_t remainingSubaddr;
    uint8_t subaddrBuf[4];
    bool checkAddrNack;             /*!< Whether to check the nack signal is detected during addressing. */
    gpdma_handle_t *gpdmaHandle;    /*!< The GPDMA handler used. */
    i2c_master_transfer_t transfer; /*!< Copy of the current transfer info. */
    i2c_master_gpdma_transfer_callback_t
        completionCallback; /*!< Callback function called after gpdma transfer finished. */
    void *userData;         /*!< Callback parameter passed to callback function. */
};

/*!
 * @brief Set of events sent to the callback for non blocking slave transfers.
 *
 * These event enumerations are used for two related purposes. First, a bit mask created by OR'ing together
 * events is passed to I2C_SlaveTransferNonBlocking() in order to specify which events to enable.
 * Then, when the slave callback is invoked, it is passed the current event through its @a transfer
 * parameter.
 *
 * @note These enumerations are meant to be OR'd together to form a bit mask of events.
 */
typedef enum _i2c_slave_transfer_event
{
    kI2C_SlaveAddressMatchEvent = 0x01U, /*!< Received the slave address after a start or repeated start. */
    kI2C_SlaveTransmitEvent     = 0x02U, /*!< Callback is requested to provide data to transmit
                                                (slave-transmitter role). */
    kI2C_SlaveReceiveEvent = 0x04U,      /*!< Callback is requested to provide a buffer in which to place received
                                                 data (slave-receiver role). */
    kI2C_SlaveGpdmaErrorEvent = 0x08U,   /*!< Error occured during GPDMA transfer caused by AHB bus error. */
    kI2C_SlaveCompletionEvent = 0x20U,   /*!< All data in the active transfer have been consumed. */
    kI2C_SlaveDeselectedEvent =
        0x40U, /*!< The slave function has become deselected (SLVSEL flag changing from 1 to 0. */

    /*! Bit mask of all available events. */
    kI2C_SlaveAllEvents = kI2C_SlaveAddressMatchEvent | kI2C_SlaveTransmitEvent | kI2C_SlaveReceiveEvent |
                          kI2C_SlaveCompletionEvent | kI2C_SlaveDeselectedEvent,
} i2c_slave_transfer_event_t;

/*!
 * @brief I2C slave software finite state machine states.
 */
typedef enum _i2c_slave_fsm
{
    kI2C_SlaveFsmAddressMatch = 0u,
    kI2C_SlaveFsmReceive      = 2u,
    kI2C_SlaveFsmTransmit     = 3u,
} i2c_slave_fsm_t;

/*! @brief I2C slave handle typedef. */
typedef struct _i2c_slave_gpdma_handle i2c_slave_gpdma_handle_t;

/*! @brief I2C slave transfer structure */
typedef struct _i2c_slave_transfer
{
    i2c_slave_gpdma_handle_t *handle; /*!< Pointer to handle that contains this transfer. */
    i2c_slave_transfer_event_t event; /*!< Reason the callback is being invoked. */
    uint8_t receivedAddress;          /*!< Matching address send by master. 7-bits plus R/nW bit0 */
    uint32_t eventMask;               /*!< Mask of enabled events. */
    uint8_t *rxData;                  /*!< Transfer buffer for receive data */
    const uint8_t *txData;            /*!< Transfer buffer for transmit data */
    size_t txSize;                    /*!< Transfer size */
    size_t rxSize;                    /*!< Transfer size */
    status_t completionStatus;        /*!< Success or error code describing how the transfer completed. Only applies for
                                         #kI2C_SlaveCompletionEvent. */
} i2c_slave_transfer_t;

/*!
 * @brief Slave event callback function pointer type.
 *
 * This callback is used only for the slave non-blocking transfer API. To install a callback,
 * use the I2C_SlaveSetCallback() function after you have created a handle.
 *
 * @param base Base address for the I2C instance on which the event occurred.
 * @param transfer Pointer to transfer descriptor containing values passed to and/or from the callback.
 * @param userData Arbitrary pointer-sized value passed from the application.
 */
typedef void (*i2c_slave_transfer_callback_t)(I2C_Type *base, volatile i2c_slave_transfer_t *transfer, void *userData);

/*!
 * @brief I2C slave handle structure.
 * @note The contents of this structure are private and subject to change.
 */
struct _i2c_slave_gpdma_handle
{
    volatile i2c_slave_transfer_t transfer; /*!< I2C slave transfer. */
    gpdma_handle_t *gpdmaHandle;            /*!< The GPDMA handler used. */
    gpdma_transfer_config_t dmaXferConfig;  /*!< Structure to store GPDMA transfer configuration. */
    volatile bool isBusy;                   /*!< Whether transfer is busy. */
    volatile i2c_slave_fsm_t slaveFsm;      /*!< slave transfer state machine. */
    i2c_slave_transfer_callback_t callback; /*!< Callback function called at transfer event. */
    void *userData;                         /*!< Callback parameter passed to callback. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus. */

/*!
 * @name I2C master GPDMA Transfer Operation
 * @{
 */

/*!
 * @brief Init the I2C handle which is used in transactional functions
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_gpdma_handle_t structure
 * @param callback pointer to user callback function
 * @param userData user param passed to the callback function
 * @param gpdmaHandle GPDMA handle pointer
 */
void I2C_MasterTransferCreateHandleGPDMA(I2C_Type *base,
                                         i2c_master_gpdma_handle_t *handle,
                                         i2c_master_gpdma_transfer_callback_t callback,
                                         void *userData,
                                         gpdma_handle_t *gpdmaHandle);

/*!
 * @brief Performs a master gpdma non-blocking transfer on the I2C bus
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_gpdma_handle_t structure
 * @param xfer pointer to transfer structure of i2c_master_transfer_t
 * @retval kStatus_Success Sucessully complete the data transmission.
 * @retval kStatus_I2C_Busy Previous transmission still not finished.
 * @retval kStatus_I2C_Timeout Transfer error, wait signal timeout.
 * @retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval kStataus_I2C_Nak Transfer error, receive Nak during transfer.
 */
status_t I2C_MasterTransferGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle, i2c_master_transfer_t *xfer);

/*!
 * @brief Get master transfer status during a gpdma non-blocking transfer
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_gpdma_handle_t structure
 * @param count Number of bytes transferred so far by the non-blocking transaction.
 */
status_t I2C_MasterTransferGetCountGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle, size_t *count);

/*!
 * @brief Abort a master gpdma non-blocking transfer in a early time
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_gpdma_handle_t structure
 */
void I2C_MasterTransferAbortGPDMA(I2C_Type *base, i2c_master_gpdma_handle_t *handle);

/*! @} */

/*!
 * @name I2C slave GPDMA Transfer Operation
 * @{
 */
/*!
 * @brief Creates a new handle for the I2C slave GPDMA APIs.
 *
 * The creation of a handle is for use with the GPDMA APIs. Once a handle
 * is created, there is not a corresponding destroy handle. If the user wants to
 * terminate a transfer, the I2C_SlaveTransferAbort() API shall be called.
 *
 * @param base The I2C peripheral base address.
 * @param[out] handle Pointer to the I2C slave driver handle.
 * @param callback User provided pointer to the asynchronous callback function.
 * @param userData User provided pointer to the application callback data.
 * @param gpdmaHandle GPDMA handle pointer
 */
void I2C_SlaveTransferCreateHandleGPDMA(I2C_Type *base,
                                        i2c_slave_gpdma_handle_t *handle,
                                        i2c_slave_transfer_callback_t callback,
                                        void *userData,
                                        gpdma_handle_t *gpdmaHandle);

/*!
 * @brief Starts accepting slave transfers.
 *
 * Call this API after calling I2C_SlaveInit() and I2C_SlaveTransferCreateHandleGPDMA() to start processing
 * transactions driven by an I2C master. The slave monitors the I2C bus and pass events to the
 * callback that was passed into the call to I2C_SlaveTransferCreateHandleGPDMA(). The callback is always invoked
 * from the interrupt context.
 *
 * If no slave Tx transfer is busy, a master read from slave request invokes #kI2C_SlaveTransmitEvent callback.
 * If no slave Rx transfer is busy, a master write to slave request invokes #kI2C_SlaveReceiveEvent callback.
 *
 * The set of events received by the callback is customizable. To do so, set the @a eventMask parameter to
 * the OR'd combination of #i2c_slave_transfer_event_t enumerators for the events you wish to receive.
 * The #kI2C_SlaveTransmitEvent and #kI2C_SlaveReceiveEvent events are always enabled and do not need
 * to be included in the mask. Alternatively, you can pass 0 to get a default set of only the transmit and
 * receive events that are always enabled. In addition, the #kI2C_SlaveAllEvents constant is provided as
 * a convenient way to enable all events.
 *
 * @param base The I2C peripheral base address.
 * @param handle Pointer to i2c_slave_gpdma_handle_t structure which stores the transfer state.
 * @param eventMask Bit mask formed by OR'ing together #i2c_slave_transfer_event_t enumerators to specify
 *      which events to send to the callback. Other accepted values are 0 to get a default set of
 *      only the transmit and receive events, and #kI2C_SlaveAllEvents to enable all events.
 *
 * @retval kStatus_Success Slave transfers were successfully started.
 * @retval #kStatus_I2C_Busy Slave transfers have already been started on this handle.
 */
status_t I2C_SlaveTransferGPDMA(I2C_Type *base, i2c_slave_gpdma_handle_t *handle, uint32_t eventMask);

/*!
 * @brief Gets the count of how many bytes have been transfered.
 *
 * @param base I2C base pointer.
 * @param handle pointer to i2c_slave_gpdma_handle_t structure.
 * @param count Number of bytes transferred so far by the GPDMA transaction.
 * @retval kStatus_InvalidArgument count is Invalid.
 * @retval kStatus_Success Successfully return the count.
 */
status_t I2C_SlaveTransferGetCountGPDMA(I2C_Type *base, i2c_slave_gpdma_handle_t *handle, size_t *count);

/*!
 * @brief Aborts the slave GPDMA transfers.
 * @note This API could be called at any time to stop slave for handling the bus events.
 * @param base The I2C peripheral base address.
 * @param handle Pointer to i2c_slave_gpdma_handle_t structure which stores the transfer state.
 * @retval kStatus_Success
 * @retval #kStatus_I2C_Idle
 */
void I2C_SlaveTransferAbortGPDMA(I2C_Type *base, i2c_slave_gpdma_handle_t *handle);

/*!
 * @brief Reusable routine to handle slave interrupts.
 * @note This function does not need to be called unless you are reimplementing the
 *  GPDMA API's interrupt handler routines to add special functionality.
 * @param base The I2C peripheral base address.
 * @param i2cHandle Pointer to i2c_slave_gpdma_handle_t structure which stores the transfer state.
 */
void I2C_SlaveTransferGPDMAHandleIRQ(I2C_Type *base, void *i2cHandle);

/*! @} */

#if defined(__cplusplus)
}
#endif /*_cplusplus. */
/*! @} */
#endif /*FSL_I2C_GPDMA_H_*/
