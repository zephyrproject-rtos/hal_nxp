/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_HOSTIF_H_
#define FSL_HOSTIF_H_

#include "fsl_common.h"

/*!
 * @addtogroup hostif
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief HOSTIF driver version 2.0.1. */
#define FSL_HOSTIF_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))

#define HOSTIF_GET_REG(regAddr)           (*((volatile uint32_t *)(regAddr)))
#define HOSTIF_SET_REG(regAddr, bitPos)   (HOSTIF_GET_REG(regAddr) |= (1UL << (bitPos)))
#define HOSTIF_CLEAR_REG(regAddr, bitPos) (HOSTIF_GET_REG(regAddr) &= ~(1UL << (bitPos)))
#define HOSTIF_SET_MASK(regAddr, regMask, regValue) \
    ((HOSTIF_GET_REG(regAddr)) =                    \
         (((HOSTIF_GET_REG(regAddr)) & (~((uint32_t)(regMask)))) | (((uint32_t)(regValue)) & ((uint32_t)(regMask)))))
#define HOSTIF_SET_FIELD(regAddr, regValue) ((HOSTIF_GET_REG(regAddr)) = ((uint32_t)(regValue)))

/*! @brief hostif status */
enum
{
    kHOSTIF_RxBufferBusy      = MAKE_STATUS(kStatusGroup_HOSTIF, 1), /*!< RX Buffer is busy */
    kHOSTIF_EndOfReception    = MAKE_STATUS(kStatusGroup_HOSTIF, 2), /*!< End of reception */
    kHOSTIF_EndOfTransmit     = MAKE_STATUS(kStatusGroup_HOSTIF, 3), /*!< End of transmit */
    kHOSTIF_ReachedWaterLevel = MAKE_STATUS(kStatusGroup_HOSTIF, 4), /*!< Water level reached*/
    kHOSTIF_TransferError     = MAKE_STATUS(kStatusGroup_HOSTIF, 5), /*!< Transfer error*/
    kHOSTIF_UnknownInterrupt  = MAKE_STATUS(kStatusGroup_HOSTIF, 6), /*!< Unknown interrupt*/
    kHOSTIF_TxPrefetchFailed  = MAKE_STATUS(kStatusGroup_HOSTIF, 7), /*!< TX prefetch failed */
    kHOSTIF_TxBufferBusy      = MAKE_STATUS(kStatusGroup_HOSTIF, 8), /*!< TX Buffer is busy */
    kHOSTIF_InvalidArgument   = MAKE_STATUS(kStatusGroup_HOSTIF, 9), /*!< Invalid argument */
};

/*! @brief hostif controller status */
enum _hostif_controller_status
{
    kHOSTIF_Rx0BufferLocked = HOSTIF_STATUS_RX0_BUFFER_LOCK_MASK, /*!< RX0 Buffer is locked by the H/w */
    kHOSTIF_Rx1BufferLocked = HOSTIF_STATUS_RX1_BUFFER_LOCK_MASK, /*!< RX1 Buffer is locked by the H/w */
    kHOSTIF_Rx2BufferLocked = HOSTIF_STATUS_RX2_BUFFER_LOCK_MASK, /*!< RX2 Buffer is locked by the H/w */
    kHOSTIF_Rx3BufferLocked = HOSTIF_STATUS_RX3_BUFFER_LOCK_MASK, /*!< RX3 Buffer is locked by the H/w */
    kHOSTIF_TxBufferLocked  = HOSTIF_STATUS_TX_BUFFER_LOCK_MASK,  /*!< TX Buffer is locked by the H/w */
    kHOSTIF_TxBufferPrefetchOk =
        HOSTIF_STATUS_TX_BUFFER_PREFETCH_OK_MASK, /*!< Prefetch Failed while initiating transmission */
    kHOSTIF_CommunicationOngoing = HOSTIF_STATUS_HOSTCOMM_ONGOING_MASK, /*!< Communication ongoing */
};

/*! @brief hostif data ready status */
enum _hostif_data_ready_status
{
    kHOSTIF_Rx0DataReady = HOSTIF_DATA_READY_STATUS_RX0_DATA_READY_MASK,
    /*!< Frame valid bit for RX buffer 0.
         1 - buffer contains a frame received from Host
         0 - frame has been processed by FW and buffer is free to receive a new frame. */
    kHOSTIF_Rx1DataReady = HOSTIF_DATA_READY_STATUS_RX1_DATA_READY_MASK,
    /*!< Frame valid bit for RX buffer 0.
         1 - buffer contains a frame received from Host
         0 - frame has been processed by FW and buffer is free to receive a new frame. */
    kHOSTIF_Rx2DataReady = HOSTIF_DATA_READY_STATUS_RX2_DATA_READY_MASK,
    /*!< Frame valid bit for RX buffer 0.
         1 - buffer contains a frame received from Host
         0 - frame has been processed by FW and buffer is free to receive a new frame. */
    kHOSTIF_Rx3DataReady = HOSTIF_DATA_READY_STATUS_RX3_DATA_READY_MASK,
    /*!< Frame valid bit for RX buffer 0.
         1 - buffer contains a frame received from Host
         0 - frame has been processed by FW and buffer is free to receive a new frame. */
    kHOSTIF_TxDataReady = HOSTIF_DATA_READY_STATUS_TX_DATA_READY_MASK,
    /*!< Frame valid bit for TX buffer.
         1 - buffer loaded with frame by FW to be sent to Host
         0 - frame successfully sent to Host. */
};

/*! @brief hostif interrupt status */
enum _hostif_interrupt_status
{
    kHOSTIF_Rx0EorStatus               = HOSTIF_INT_STATUS_RX0_EOR_STATUS_MASK,
    kHOSTIF_Rx1EorStatus               = HOSTIF_INT_STATUS_RX1_EOR_STATUS_MASK,
    kHOSTIF_Rx2EorStatus               = HOSTIF_INT_STATUS_RX2_EOR_STATUS_MASK,
    kHOSTIF_Rx3EorStatus               = HOSTIF_INT_STATUS_RX3_EOR_STATUS_MASK,
    kHOSTIF_EotStatus                  = HOSTIF_INT_STATUS_EOT_STATUS_MASK,
    kHOSTIF_RxBufferNotAvaliableStatus = HOSTIF_INT_STATUS_RX_BUFFER_NOT_AVAILABLE_STATUS_MASK,
    kHOSTIF_TxBufferNotAvaliableStatus = HOSTIF_INT_STATUS_TX_FRAME_NOT_AVAILABLE_STATUS_MASK,
    kHOSTIF_FifoTimeoutStatus          = HOSTIF_INT_STATUS_FIFO_TIMEOUT_STATUS_MASK,
    kHOSTIF_FifoOverFlowStatus         = HOSTIF_INT_STATUS_FIFO_OVERFLOW_STATUS_MASK,
    kHOSTIF_TimeOutStatus              = HOSTIF_INT_STATUS_TIMEOUT_STATUS_MASK,
    kHOSTIF_Rx0BufferOverflowStatus    = HOSTIF_INT_STATUS_RX0_BUFFER_OVERFLOW_STATUS_MASK,
    kHOSTIF_Rx1BufferOverflowStatus    = HOSTIF_INT_STATUS_RX1_BUFFER_OVERFLOW_STATUS_MASK,
    kHOSTIF_Rx2BufferOverflowStatus    = HOSTIF_INT_STATUS_RX2_BUFFER_OVERFLOW_STATUS_MASK,
    kHOSTIF_Rx3BufferOverflowStatus    = HOSTIF_INT_STATUS_RX3_BUFFER_OVERFLOW_STATUS_MASK,
    kHOSTIF_WaterLevelReachedStatus    = HOSTIF_INT_STATUS_WATERLEVEL_REACHED_STATUS_MASK,
    kHOSTIF_HsuRxFerStatus             = HOSTIF_INT_STATUS_HSU_RX_FER_STATUS_MASK,
    kHOSTIF_PrefetchOkIntStatus        = HOSTIF_INT_STATUS_PREFETCH_OK_INT_STATUS_MASK,
    kHOSTIF_TxDataReadyIntStatus       = HOSTIF_INT_STATUS_TX_DATA_READY_INT_STATUS_MASK,
    kHOSTIF_I3cStartStatus             = HOSTIF_INT_STATUS_I3C_START_STATUS_MASK,
    kHOSTIF_I3cMatchedStatus           = HOSTIF_INT_STATUS_I3C_MATCHED_STATUS_MASK,
    kHOSTIF_I3cStopStatus              = HOSTIF_INT_STATUS_I3C_STOP_STATUS_MASK,
    kHOSTIF_I3cRxEndStatus             = HOSTIF_INT_STATUS_I3C_RXPEND_STATUS_MASK,
    kHOSTIF_I3cTxNotFullStatus         = HOSTIF_INT_STATUS_I3C_TXNOTFULL_STATUS_MASK,
    kHOSTIF_I3cDachgStatus             = HOSTIF_INT_STATUS_I3C_DACHG_STATUS_MASK,
    kHOSTIF_I3cCccStatus               = HOSTIF_INT_STATUS_I3C_CCC_STATUS_MASK,
    kHOSTIF_I3cErrorStatus             = HOSTIF_INT_STATUS_I3C_ERROR_STATUS_MASK,
    kHOSTIF_I3cHdMatchStatus           = HOSTIF_INT_STATUS_I3C_HDRMATCH_STATUS_MASK,
    kHOSTIF_I3cChandledStatus          = HOSTIF_INT_STATUS_I3C_HDRMATCH_STATUS_MASK,
    kHOSTIF_I3cEventStatus             = HOSTIF_INT_STATUS_I3C_EVENT_STATUS_MASK,
};

/*! @brief hostif buffer id */
typedef enum _hostif_rx_buffer_id
{
    kHOSTIF_RxBufferId0 = 0, /*!< hostif rx0 buffer id */
    kHOSTIF_RxBufferId1,     /*!< hostif rx1 buffer id */
    kHOSTIF_RxBufferId2,     /*!< hostif rx2 buffer id */
    kHOSTIF_RxBufferId3,     /*!< hostif rx3 buffer id */
} hostif_rx_buffer_id_t;

/*! @brief hostif select config */
typedef enum _hostif_interface
{
    kHOSTIF_SelectNone = 0, /*!< hostif select none bus */
    kHOSTIF_SelectI2c  = 1, /*!< hostif select i2c bus */
    kHOSTIF_SelectSpi  = 2, /*!< hostif select spi bus */
} hostif_interface_t;

/*! @brief hostif i2c config */
typedef struct _hostif_i2c_config
{
    uint8_t slaveAddress : 2;   /*!< Slave address. */
    uint8_t enableHsMode : 1;   /*!< Enable HS mode. */
    uint8_t enableReset : 1;    /*!< Enable reset. */
    uint8_t enableDeviceID : 1; /*!< Enable device ID. */
    uint8_t revisionId : 3;     /*!< I2C revision ID. */
} hostif_i2c_config_t;

/*! @brief hostif spi config */
typedef struct _hostif_spi_config
{
    uint8_t clockPolarity : 1; /*!< SPI clockPolarity. */
    uint8_t clockPhase : 1;    /*!< SPI clockPhase. */
} hostif_spi_config_t;

/*! @brief hostif config*/
typedef struct _hostif_config
{
    union _hostif_interface_config
    {
        /*!< BIT 7-5 - I2C revision ID
             BIT 4   - Enable device ID
             BIT 3   - Enable reset
             BIT 2   - Enable HS mode
             BIT 0-1 - Slave address */
        hostif_i2c_config_t i2cConfig;

        /*!< BIT 1 - SPI clockPhase
             BIT 0 - SPI clockPolarity */
        hostif_spi_config_t spiConfig;

    } interfaceConfig;            /*!< Users need to configure according to their own needs. */
    hostif_interface_t interface; /*!< Select one of in I2C, SPI. */

    uint16_t timeOut;        /*!< Inter-character timeout in 5us steps (max delay 200ms).
                                  If set to 0, this feature is disabled when FIFO_MODE='0'.
                                  When FIFO_MODE='1' this defines the RX timeout value in 5us step. */
    uint16_t waterMarkLevel; /*!< Number of bytes received in incoming buffer before triggering an interrupt
                                (pre-empting EOR). If set to 0, this feature is disabled. FIFO Waterlvel when
                                FIFO_MODE='1' Must remain static. */

    bool enableCrc;        /*!< Enable CRC. */
    bool enableExtIrqCtrl; /*!< Enable Ext IRQ line asserted if PREFETCH_OK is set. */
} hostif_config_t;

/*! @brief HOSTIF transfer structure */
typedef struct _hostif_transfer
{
    uint8_t *startAddress; /*!< Pointer to the Dword aligned buffer to which the data has to be saved. */
    uint16_t bufferLength; /*!< Length of the data in bytes which can be received by the buffer. */
} hostif_transfer_t;

/*! Forward declaration of the handle typedef. */
typedef struct _hostif_handle hostif_handle_t;

/*! @brief HOSTIF transfer callback function. */
typedef void (*hostif_transfer_callback_t)(hostif_handle_t *handle,
                                           void *userData,
                                           uint32_t transferredLength,
                                           uint32_t status);

/*! @brief HOSTIF handle structure. */
struct _hostif_handle
{
    hostif_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                      /*!< Callback function parameter. */
    HOSTIF_Type *base;                   /*!< HOSTIF base address. */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name HOSTIF Initialization and De-initialization interfaces
 * @{
 */

/*!
 * @brief HOSTIF initialization
 *
 * @param base HOSTIF base address.
 * @param config Pointer to the HOSTIF configuration structure, see @ref _hostif_config for detail.
 */
void HOSTIF_Init(HOSTIF_Type *base, const hostif_config_t *config);

/*!
 * @brief HOSTIF De-initialization
 *
 * @param base HOSTIF base address.
 */
void HOSTIF_Deinit(HOSTIF_Type *base);

/*! @} */

/*!
 * @name HOSTIF Functional Interfaces
 * @{
 */

/*!
 * @brief Gets HOSTIF default config
 *
 * @param config Pointer to the HOSTIF configuration structure, see @ref _hostif_config for detail.
 */
void HOSTIF_GetDefaultConfig(hostif_config_t *config);

/*!
 * @brief Sets HOSTIF tx buffer config
 *
 * @param base HOSTIF base address.
 * @param startAddress Pointer to double word (4 byte) aligned memory.
 * @param bufferLength Length of the buffer to be transmitted Maximum 1024 in for fixed format and 256 for free format.
 */
void HOSTIF_SetTxBufferConfig(HOSTIF_Type *base, uint8_t *startAddress, uint16_t bufferLength);

/*!
 * @brief Sets HOSTIF rx buffer config
 *
 * @param base HOSTIF base address.
 * @param startAddress Pointer to the Dword aligned buffer to which the data has to be saved.
 * @param maxSize Max Length of the data in bytes which can be received by the buffer.
 * @param bufferId Buffer ID of the register which should be configured.
 */
void HOSTIF_SetRxBufferConfig(HOSTIF_Type *base,
                              uint8_t *startAddress,
                              uint16_t maxSize,
                              hostif_rx_buffer_id_t bufferId);

/*!
 * @brief Enables HOSTIF rx buffer
 *
 * @param base HOSTIF base address.
 * @param bufferId Buffer ID of the register which should be enabled.
 */
static inline void HOSTIF_EnableRxBuffer(HOSTIF_Type *base, hostif_rx_buffer_id_t bufferId)
{
    HOSTIF_CLEAR_REG(((uint32_t)&base->BUFFER_RX0_CFG + ((uint32_t)bufferId * 4U)),
                     HOSTIF_BUFFER_RX0_CFG_RX0_BUFFER_DISABLE_SHIFT);
}

/*!
 * @brief Disables HOSTIF rx buffer
 *
 * @param base HOSTIF base address.
 * @param bufferId Buffer ID of the register which should be disabled.
 */
static inline void HOSTIF_DisableRxBuffer(HOSTIF_Type *base, hostif_rx_buffer_id_t bufferId)
{
    HOSTIF_SET_REG(((uint32_t)&base->BUFFER_RX0_CFG + ((uint32_t)bufferId * 4U)),
                   HOSTIF_BUFFER_RX0_CFG_RX0_BUFFER_DISABLE_SHIFT);
}

/*!
 * @brief Is HOSTIF rx buffer enabled
 *
 * @param base HOSTIF base address.
 * @param bufferId Buffer ID of the status to set.
 * @return true The rx buffer is enabled.
           false The rx buffer is disabled.
 */
static inline bool HOSTIF_IsRxBufferEnabled(HOSTIF_Type *base, hostif_rx_buffer_id_t bufferId)
{
    return ((HOSTIF_GET_REG((uint32_t)&base->BUFFER_RX0_CFG + ((uint32_t)bufferId * 4U)) & (0x1UL << 27U)) == 0U);
}

/*!
 * @brief Gets HOSTIF rx buffer length
 *
 * @param base HOSTIF base address.
 * @return bufferId Buffer ID of the length to get.
 */
static inline uint16_t HOSTIF_GetRxBufferLength(HOSTIF_Type *base, hostif_rx_buffer_id_t bufferId)
{
    return (uint16_t)(HOSTIF_GET_REG((uint32_t)&base->BUFFER_RX0_LEN + ((uint32_t)bufferId * 4U)) & 0x7FFU);
}

/*!
 * @brief Is HOSTIF rx buffer crc ok
 *
 * @param base HOSTIF base address.
 * @param bufferId Buffer ID of the status to set.
 * @return true The rx buffer crc is ok.
           false The rx buffer crc is not ok.
 */
static inline bool HOSTIF_IsRxBufferCrcOk(HOSTIF_Type *base, hostif_rx_buffer_id_t bufferId)
{
    return ((HOSTIF_GET_REG((uint32_t)&base->BUFFER_RX0_LEN + ((uint32_t)bufferId * 4UL)) & (0x1UL << 11UL)) != 0U);
}

/*!
 * @brief Sets HOSTIF water mark level
 *
 * @param base HOSTIF base address.
 * @param waterMarkLevel Number of bytes received in incoming buffer before triggering an interrupt.
 *        If set to 0, this feature is disabled. FIFO Waterlvel when FIFO_MODE='1' Must remain static.
 */
static inline void HOSTIF_SetWaterLevel(HOSTIF_Type *base, uint16_t waterMarkLevel)
{
    assert(waterMarkLevel != 0U);

    base->WATERLEVEL = (waterMarkLevel & 0x7FFUL);
}

/*!
 * @brief Sets HOSTIF timeout value
 *
 * @param base HOSTIF base address.
 * @param timeOut Inter-character timeout in 5us steps (max delay 200ms).
 *        If set to 0, this feature is disabled when FIFO_MODE='0'.
 *        When FIFO_MODE='1' this defines the rx timeout value in 5us step.
 */
static inline void HOSTIF_SetTimeOut(HOSTIF_Type *base, uint16_t timeOut)
{
    assert(timeOut != 0U);

    base->TIC_TIMEOUT = timeOut;
}

/*! @} */

/*!
 * @name HOSTIF Interrupt Interfaces
 * @{
 */

/*!
 * @brief Enables HOSTIF interrupts
 *
 * @param base HOSTIF base address.
 * @param interrupts The mask you enabled.
 */
static inline void HOSTIF_EnableInterrupts(HOSTIF_Type *base, uint32_t interrupts)
{
    base->INT_SET_ENABLE = interrupts;
}

/*!
 * @brief Disables HOSTIF interrupts
 *
 * @param base HOSTIF base address.
 * @param interrupts The mask you disabled.
 */
static inline void HOSTIF_DisableInterrupts(HOSTIF_Type *base, uint32_t interrupts)
{
    base->INT_CLR_ENABLE = interrupts;
}

/*! @} */

/*!
 * @name HOSTIF Status Interfaces
 * @{
 */

/*!
 * @brief Gets HOSTIF buffer status
 *
 * @param base HOSTIF base address.
 * @return status The status of HOSTIF, see @ref _hostif_controller_status for detail.
 */
static inline uint32_t HOSTIF_GetControlllerStatus(HOSTIF_Type *base)
{
    return base->STATUS;
}

/*!
 * @brief Gets HOSTIF data ready status
 *
 * @param base HOSTIF base address.
 * @return status The status of data ready, see @ref _hostif_data_ready_status for detail.
 */
static inline uint32_t HOSTIF_GetDataReadyStatus(HOSTIF_Type *base)
{
    return base->DATA_READY_STATUS;
}

/*!
 * @brief Sets HOSTIF data ready status
 *
 * @param base HOSTIF base address.
 * @param status The status of data ready, see @ref _hostif_data_ready_status for detail.
 */
static inline void HOSTIF_SetDataReady(HOSTIF_Type *base, uint32_t status)
{
    base->SET_DATA_READY = status;
}

/*!
 * @brief Clears HOSTIF data ready status
 *
 * @param base HOSTIF base address.
 * @param status The status of data ready, see @ref _hostif_data_ready_status for detail.
 */
static inline void HOSTIF_ClearDataReadyStatus(HOSTIF_Type *base, uint32_t status)
{
    base->CLR_DATA_READY = status;
}

/*!
 * @brief Gets HOSTIF interrupt status
 *
 * @param base HOSTIF base address.
 * @return status The status of interrupts, see @ref _hostif_interrupt_status for detail.
 */
static inline uint32_t HOSTIF_GetInterruptsStatus(HOSTIF_Type *base)
{
    return base->INT_STATUS;
}

/*!
 * @brief Sets HOSTIF interrupt status
 *
 * @param base HOSTIF base address.
 * @param interruptmasks The Mask of interrupts, see @ref _hostif_interrupt_status for detail.
 */
static inline void HOSTIF_SetInterruptsStatus(HOSTIF_Type *base, uint32_t interruptsMask)
{
    base->INT_SET_STATUS = interruptsMask;
}

/*!
 * @brief Clears HOSTIF interrupt status
 *
 * @param base HOSTIF base address.
 * @param interruptmasks The Mask of interrupts, see @ref _hostif_interrupt_status for detail.
 */
static inline void HOSTIF_ClearInterruptsStatus(HOSTIF_Type *base, uint32_t interruptsMask)
{
    base->INT_CLR_STATUS = interruptsMask;
}

/*! @} */

/*!
 * @name HOSTIF Transactional Interfaces
 * @{
 */

/*!
 * @brief This API sends a buffer of length over the previously selected.
 *
 * @param handle HOSTIF handle pointer.
 * @param transfer Tx transfer pointer, see @ref hostif_transfer for detail.
 * @return status Status of the HOSTIF send success or failure.
 */
status_t HOSTIF_SendNonBlocking(hostif_handle_t *handle, hostif_transfer_t *transfer);

/*!
 * @brief Aborts HOSTIF send
 *
 * @param handle HOSTIF handle pointer.
 * @retval kStatus_Success Abort succeed.
 * @retval kStatus_Timeout Timeout.
 */
status_t HOSTIF_AbortSend(hostif_handle_t *handle);

/*!
 * @brief This API will allocate and enable RX buffers for reception from host.
 *
 * @param handle HOSTIF handle pointer.
 * @param transfer Rx transfer pointer, see @ref hostif_transfer for detail.
 * @param count Count of the buffer, ransfer should be the first address of the array pointer.
 */
status_t HOSTIF_ReceiveNonBlocking(hostif_handle_t *handle, hostif_transfer_t *transfer, uint8_t count);

/*!
 * @brief Aborts HOSTIF receive
 *
 * @param handle HOSTIF handle pointer.
 */
void HOSTIF_AbortReceive(hostif_handle_t *handle);

/*!
 * @brief Creates the HOSTIF handle
 *
 * @param base HOSTIF base address.
 * @param handle HOSTIF handle pointer. The HOSTIF handle stores Callback function and parameters.
 * @param callback HOSTIF callback function pointer.
 * @param userData Parameter for callback function. If it is not needed, just set to NULL.
 *
 */
void HOSTIF_CreateHandle(HOSTIF_Type *base,
                         hostif_handle_t *handle,
                         hostif_transfer_callback_t callback,
                         void *userData);
/*!
 * @brief HOSTIF IRQ handle
 *
 * @param handle HOSTIF handle pointer. The HOSTIF handle stores Callback function and parameters.
 */
void HOSTIF_HandleIRQ(hostif_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /*FSL_HOSTIF_H_*/
