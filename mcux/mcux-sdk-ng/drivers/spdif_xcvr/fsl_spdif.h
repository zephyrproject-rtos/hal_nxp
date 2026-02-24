/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SPDIF_H_
#define FSL_SPDIF_H_

#include "fsl_common.h"

/*!
 * @addtogroup spdif
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief SPDIF driver version. */
#define FSL_SPDIF_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*! @brief SPDIF transfer queue size, user can refine it according to use case. */
#define SPDIF_XFER_QUEUE_SIZE (4U)

/*! @brief SPDIF FIFO depth */
#define SPDIF_FIFO_SIZE (128U)

/*! @brief SPDIF maximum sample rate */
#define SPDIF_MAX_SAMPLE_RATE (192000U)

/*! @brief SPDIF minimum sample rate */
#define SPDIF_MIN_SAMPLE_RATE (32000U)

/*! @brief SPDIF maximum clock divider */
#define SPDIF_MAX_CLOCK_DIVIDER (1023U)

/*! @brief SPDIF maximum FIFO watermark */
#define SPDIF_MAX_FIFO_WATERMARK (127U)

/*! @brief SPDIF interrupt enable flags
 *
 * These flags are used to enable specific interrupts in the SPDIF transceiver.
 * Multiple flags can be combined using bitwise OR operations.
 */
enum _spdif_interrupt_enable
{
    kSPDIF_NewChannelStatusInterrupt =
        SPDIF_EXT_IER0_NEW_CS_IE_0_MASK,                             /*!< New channel status received interrupt */
    kSPDIF_UserDataInterrupt   = SPDIF_EXT_IER0_UD_IE_0_MASK,   /*!< User data received interrupt */
    kSPDIF_MuteDetectInterrupt = SPDIF_EXT_IER0_MUTE_IE_0_MASK, /*!< Mute condition detected interrupt */
    kSPDIF_PreambleMismatchInterrupt =
        SPDIF_EXT_IER0_PREAMBLE_MISMATCH_IE_0_MASK,                  /*!< Preamble mismatch detected interrupt */
    kSPDIF_FifoOverflowUnderflowInterrupt =
        SPDIF_EXT_IER0_FIFO_OFLOW_UFLOW_ERR_IE_0_MASK,               /*!< FIFO overflow or underflow error interrupt */
    kSPDIF_RxNoDataInterrupt = SPDIF_EXT_IER0_RX_NO_DATA_REC_IE_0_MASK,    /*!< No data received on RX interrupt */
    kSPDIF_DmaReadRequestInterrupt  = SPDIF_EXT_IER0_DMA_RD_REQ_IE_0_MASK, /*!< DMA read request interrupt */
    kSPDIF_DmaWriteRequestInterrupt = SPDIF_EXT_IER0_DMA_WR_REQ_IE_0_MASK, /*!< DMA write request interrupt */
    kSPDIF_RxBmeErrorInterrupt =
        SPDIF_EXT_IER0_RX_DATA_BME_ERR_IE_0_MASK,  /*!< RX data BME (Bi-phase Mark Encoding) error interrupt */
    kSPDIF_PreambleMatchInterrupt =
        SPDIF_EXT_IER0_PREAMBLE_MATCH_IE_0_MASK,   /*!< Preamble match detected interrupt */
    kSPDIF_MWPreambleMismatchInterrupt =
        SPDIF_EXT_IER0_M_W_PRE_MISMATCH_IE_0_MASK, /*!< M/W preamble mismatch interrupt */
    kSPDIF_BPreambleMismatchInterrupt =
        SPDIF_EXT_IER0_B_PRE_MISMATCH_IE_0_MASK,   /*!< B preamble mismatch interrupt */
    kSPDIF_UnexpectedPreambleInterrupt =
        SPDIF_EXT_IER0_UNEXP_PRE_REC_IE_0_MASK,    /*!< Unexpected preamble received interrupt */
    kSPDIF_ChannelStatusOverflowInterrupt =
        SPDIF_EXT_IER0_CS_UD_OFLOW_IE_0_MASK,      /*!< Channel status or user data overflow interrupt */
    kSPDIF_NewBlockReceivedInterrupt = SPDIF_EXT_IER0_NEW_BLK_RCVD_IE_0_MASK, /*!< New block received interrupt */
    kSPDIF_WakeupInterrupt           = SPDIF_EXT_IER0_SPDIF_WAKEUP_IE_0_MASK, /*!< SPDIF wakeup interrupt */
    kSPDIF_AllInterrupt              = 0x1DEFFE7U,                            /*!< All interrupts combined mask */
};

/*! @brief SPDIF status flags
 *
 * These flags indicate the current status of various SPDIF transceiver conditions.
 * They can be read to determine the state of the hardware and are typically cleared
 * after being processed.
 */
enum _spdif_status_flag
{
    kSPDIF_RxNewChannelStatus = SPDIF_EXT_ISR_RX_NEW_CH_STAT_MASK,    /*!< New channel status received flag */
    kSPDIF_RxUserData         = SPDIF_EXT_ISR_RX_USR_DATA_MASK,       /*!< User data received flag */
    kSPDIF_MuteDetected       = SPDIF_EXT_ISR_MUTE_DET_MASK,          /*!< Mute condition detected flag */
    kSPDIF_PreambleMismatch   = SPDIF_EXT_ISR_PREAMBLE_MISMATCH_MASK, /*!< Preamble mismatch detected flag */
    kSPDIF_FifoOverflowUnderflow =
        SPDIF_EXT_ISR_FIFO_OFLOW_UFLOW_ERR_MASK,                           /*!< FIFO overflow or underflow error flag */
    kSPDIF_RxNoDataReceived = SPDIF_EXT_ISR_RX_NO_DATA_REC_MASK,      /*!< No data received on RX flag */
    kSPDIF_DmaReadRequest   = SPDIF_EXT_ISR_DMA_RD_REQ_MASK,          /*!< DMA read request flag */
    kSPDIF_DmaWriteRequest  = SPDIF_EXT_ISR_DMA_WR_REQ_MASK,          /*!< DMA write request flag */
    kSPDIF_RxBmeError = SPDIF_EXT_ISR_RX_BME_BIT_ERR_MASK, /*!< RX BME (Bi-phase Mark Encoding) bit error flag */
    kSPDIF_PreambleMatch      = SPDIF_EXT_ISR_PREAMBLE_MATCH_INT_MASK, /*!< Preamble match detected flag */
    kSPDIF_MWPreambleMismatch = SPDIF_EXT_ISR_M_W_PRE_MISMATCH_MASK,   /*!< M/W preamble mismatch flag */
    kSPDIF_BPreambleMismatch  = SPDIF_EXT_ISR_B_PRE_MISMATCH_MASK,     /*!< B preamble mismatch flag */
    kSPDIF_UnexpectedPreamble = SPDIF_EXT_ISR_UNEXP_PRE_REC_MASK,      /*!< Unexpected preamble received flag */
    kSPDIF_ChannelStatusOverflow =
        SPDIF_EXT_ISR_CS_OR_UD_OFLOW_MASK,                          /*!< Channel status or user data overflow flag */
    kSPDIF_NewBlockReceived = SPDIF_EXT_ISR_NEW_BLK_RCVD_MASK, /*!< New block received flag */
    kSPDIF_WakeupReceived   = SPDIF_EXT_ISR_SPDIF_WAKEUP_REC_MASK, /*!< SPDIF wakeup received flag */
};

/*! @brief SPDIF status return codes. */
enum _spdif_status
{
    kStatus_SPDIF_RxIdle          = MAKE_STATUS(kStatusGroup_SPDIF, 0),  /*!< SPDIF RX is idle */
    kStatus_SPDIF_TxIdle          = MAKE_STATUS(kStatusGroup_SPDIF, 1),  /*!< SPDIF TX is idle */
    kStatus_SPDIF_RxBusy          = MAKE_STATUS(kStatusGroup_SPDIF, 2),  /*!< SPDIF RX is busy */
    kStatus_SPDIF_TxBusy          = MAKE_STATUS(kStatusGroup_SPDIF, 3),  /*!< SPDIF TX is busy */
    kStatus_SPDIF_QueueFull       = MAKE_STATUS(kStatusGroup_SPDIF, 4),  /*!< SPDIF queue is full */
    kStatus_SPDIF_RxError         = MAKE_STATUS(kStatusGroup_SPDIF, 5),  /*!< SPDIF RX error */
    kStatus_SPDIF_RxFIFOError     = MAKE_STATUS(kStatusGroup_SPDIF, 6),  /*!< SPDIF RX FIFO error */
    kStatus_SPDIF_RxCnew          = MAKE_STATUS(kStatusGroup_SPDIF, 7),  /*!< SPDIF RX channel status new */
    kStatus_SPDIF_RxUserData      = MAKE_STATUS(kStatusGroup_SPDIF, 8),  /*!< SPDIF RX user data */
    kStatus_SPDIF_RxParityError   = MAKE_STATUS(kStatusGroup_SPDIF, 9),  /*!< SPDIF RX parity error */
    kStatus_SPDIF_RxIllegalSymbol = MAKE_STATUS(kStatusGroup_SPDIF, 10), /*!< SPDIF RX illegal symbol */
    kStatus_SPDIF_RxDPLLLocked    = MAKE_STATUS(kStatusGroup_SPDIF, 11), /*!< SPDIF RX DPLL locked */
};

/*! @brief SPDIF data format */
typedef enum _spdif_data_format
{
    kSPDIF_DataFormat_SubFrame = 0U, /*!< Raw sub-frame format */
    kSPDIF_DataFormat_24Bit    = 1U, /*!< 24-bit audio data */
    kSPDIF_DataFormat_20Bit    = 2U, /*!< 20-bit audio data */
    kSPDIF_DataFormat_16Bit    = 3U, /*!< 16-bit audio data */
} spdif_data_format_t;

/*! @brief SPDIF frame synchronization mode */
typedef enum _spdif_fsm_mode
{
    kSPDIF_FSM_SyncToB  = 0U, /*!< Sync to B preamble */
    kSPDIF_FSM_SyncToM  = 1U, /*!< Sync to M preamble */
    kSPDIF_FSM_SyncToMW = 2U, /*!< Sync to M/W preambles */
    kSPDIF_FSM_Reserved = 3U, /*!< Reserved */
} spdif_fsm_mode_t;

/*! @brief SPDIF transmit format */
typedef enum _spdif_tx_format
{
    kSPDIF_TxFormat_SubFrame = 0U, /*!< Complete sub-frame format */
    kSPDIF_TxFormat_24Bit    = 1U, /*!< 24-bit raw data */
    kSPDIF_TxFormat_20Bit    = 2U, /*!< 20-bit raw data */
    kSPDIF_TxFormat_16Bit    = 3U, /*!< 16-bit raw data */
} spdif_tx_format_t;

/*! @brief SPDIF wakeup toggle count */
typedef enum _spdif_wakeup_toggle_count
{
    kSPDIF_WakeupToggle_1 = 0U, /*!< 1 toggle */
    kSPDIF_WakeupToggle_2 = 1U, /*!< 2 toggles */
    kSPDIF_WakeupToggle_3 = 2U, /*!< 3 toggles */
    kSPDIF_WakeupToggle_4 = 3U, /*!< 4 toggles */
    kSPDIF_WakeupToggle_5 = 4U, /*!< 5 toggles */
    kSPDIF_WakeupToggle_6 = 5U, /*!< 6 toggles */
    kSPDIF_WakeupToggle_7 = 6U, /*!< 7 toggles */
    kSPDIF_WakeupToggle_8 = 7U, /*!< 8 toggles */
} spdif_wakeup_toggle_count_t;

/*! @brief SPDIF configuration structure */
typedef struct _spdif_config
{
    /* Receiver configuration */
    bool enableRx;                         /*!< Enable receiver */
    spdif_data_format_t rxDataFormat; /*!< Receiver data format */
    spdif_fsm_mode_t rxFsmMode;       /*!< Frame synchronization mode */
    bool rxStoreFormatReverse;             /*!< Store format in reverse bit order */
    bool enableRxParityCheck;              /*!< Enable parity check */
    bool rxMuteHwControl;                  /*!< Hardware mute control */
    uint8_t rxFifoWatermark;               /*!< RX FIFO watermark level */

    /* Transmitter configuration */
    bool enableTx;                   /*!< Enable transmitter */
    spdif_tx_format_t txFormat; /*!< Transmitter data format */
    bool txFrameFormatReverse;       /*!< Frame format in reverse bit order */
    bool enableTxPreamble;           /*!< Enable preamble insertion */
    bool enableTxParity;             /*!< Enable parity insertion */
    bool enableTxChannelStatus;      /*!< Enable channel status insertion */
    bool enableTxUserData;           /*!< Enable user data insertion */
    bool enableTxValidBit;           /*!< Enable valid bit insertion */
    bool txValidBitValue;            /*!< Valid bit value */
    uint8_t txFifoWatermark;         /*!< TX FIFO watermark level */

    /* Clock configuration */
    uint32_t clockDivider; /*!< Clock divider value */

    /* Wakeup configuration */
    bool enableWakeup;                                  /*!< Enable wakeup functionality */
    spdif_wakeup_toggle_count_t wakeupToggleCount; /*!< Wakeup toggle count */
} spdif_config_t;

/*! @brief SPDIF transfer structure */
typedef struct _spdif_transfer
{
    uint8_t *data;          /*!< Pointer to data buffer */
    uint8_t *channelStatus; /*!< Pointer to channel status data */
    uint8_t *userData;      /*!< Pointer to user data */
    size_t dataSize;        /*!< Size of data buffer in bytes */
} spdif_transfer_t;

/*! @brief SPDIF handle typedef */
typedef struct _spdif_handle spdif_handle_t;

/*! @brief SPDIF transfer callback typedef */
typedef void (*spdif_transfer_callback_t)(SPDIF_Type *base,
                                               spdif_handle_t *handle,
                                               status_t status,
                                               void *userData);

/*! @brief SPDIF handle structure */
struct _spdif_handle
{
    spdif_transfer_t spdifQueue[SPDIF_XFER_QUEUE_SIZE]; /*!< Transfer queue */
    size_t transferSize[SPDIF_XFER_QUEUE_SIZE];              /*!< Transfer size */
    volatile uint8_t queueUser;                                   /*!< Queue user index */
    volatile uint8_t queueDriver;                                 /*!< Queue driver index */
    spdif_transfer_callback_t callback;                      /*!< Callback function */
    void *userData;                                               /*!< User data */
    uint8_t watermark;                                            /*!< Watermark level */
    volatile uint32_t state;                                      /*!< Transfer state */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes the SPDIF peripheral.
 *
 * @param base SPDIF base pointer
 * @param config SPDIF configuration structure.
 * @retval kStatus_Success Initialization successful
 * @retval kStatus_InvalidArgument Invalid argument passed
 */
status_t SPDIF_Init(SPDIF_Type *base, const spdif_config_t *config);

/*!
 * @brief De-initializes the SPDIF peripheral.
 *
 * @param base SPDIF base pointer
 */
void SPDIF_Deinit(SPDIF_Type *base);

/*!
 * @brief Sets the SPDIF configuration structure to default values.
 *
 * @param config pointer to configuration structure
 */
void SPDIF_GetDefaultConfig(spdif_config_t *config);

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the SPDIF status flag state.
 *
 * @param base SPDIF base pointer
 * @return The status flag, can be a single flag or several flags in _spdif_status_flag.
 */
static inline uint32_t SPDIF_GetStatusFlags(SPDIF_Type *base)
{
    assert(base != NULL);
    return base->EXT_ISR.RW;
}

/*!
 * @brief Clears the SPDIF status flags.
 *
 * @param base SPDIF base pointer
 * @param mask The status flags to clear, can be a single flag or several flags in _spdif_status_flag.
 */
static inline void SPDIF_ClearStatusFlags(SPDIF_Type *base, uint32_t mask)
{
    assert(base != NULL);
    base->EXT_ISR.CLR = mask;
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables SPDIF interrupts according to the provided mask.
 *
 * @param base SPDIF base pointer
 * @param mask The interrupts to enable, can be a single interrupt or several interrupts in
 * _spdif_interrupt_enable.
 */
static inline void SPDIF_EnableInterrupts(SPDIF_Type *base, uint32_t mask)
{
    assert(base != NULL);
    base->EXT_IER0.SET = mask;
}

/*!
 * @brief Disables SPDIF interrupts according to the provided mask.
 *
 * @param base SPDIF base pointer
 * @param mask The interrupts to disable, can be a single interrupt or several interrupts in
 * _spdif_interrupt_enable.
 */
static inline void SPDIF_DisableInterrupts(SPDIF_Type *base, uint32_t mask)
{
    assert(base != NULL);
    base->EXT_IER0.CLR = mask;
}

/*! @} */

/*!
 * @name DMA Control
 * @{
 */

/*!
 * @brief Gets the SPDIF TX FIFO address for DMA transfer.
 *
 * @param base SPDIF base pointer
 * @return TX FIFO address
 */
uint32_t SPDIF_GetTxFifoAddress(SPDIF_Type *base);

/*!
 * @brief Gets the SPDIF RX FIFO address for DMA transfer.
 *
 * @param base SPDIF base pointer
 * @return RX FIFO address
 */
uint32_t SPDIF_GetRxFifoAddress(SPDIF_Type *base);

/*! @} */

/*!
 * @name Bus Operations
 * @{
 */

/*!
 * @brief Enables/disables the SPDIF Tx.
 *
 * @param base SPDIF base pointer
 * @param enable True means enable SPDIF Tx, false means disable.
 */
void SPDIF_TxEnable(SPDIF_Type *base, bool enable);

/*!
 * @brief Enables/disables the SPDIF Rx.
 *
 * @param base SPDIF base pointer
 * @param enable True means enable SPDIF Rx, false means disable.
 */
void SPDIF_RxEnable(SPDIF_Type *base, bool enable);

/*!
 * @brief Configures the SPDIF Tx sample rate.
 *
 * @param base SPDIF base pointer.
 * @param sampleRate_Hz SPDIF sample rate frequency in Hz.
 * @param sourceClockFreq_Hz SPDIF tx clock source frequency in Hz.
 * @retval kStatus_Success Sample rate set successfully
 * @retval kStatus_InvalidArgument Invalid sample rate or clock frequency
 */
status_t SPDIF_TxSetSampleRate(SPDIF_Type *base, uint32_t sampleRate_Hz, uint32_t sourceClockFreq_Hz);

/*!
 * @brief Gets the SPDIF Rx sample rate.
 *
 * @param base SPDIF base pointer.
 * @param clockSourceFreq_Hz SPDIF system clock frequency in hz.
 * @return Sample rate in Hz.
 */
uint32_t SPDIF_GetRxSampleRate(SPDIF_Type *base, uint32_t clockSourceFreq_Hz);

/*!
 * @brief Sends data using a blocking method.
 *
 * @param base SPDIF base pointer.
 * @param buffer Pointer to the data to be written.
 * @param size Bytes to be written.
 * @retval kStatus_Success Data sent successfully
 * @retval kStatus_InvalidArgument Invalid buffer or size
 */
status_t SPDIF_WriteBlocking(SPDIF_Type *base, const uint8_t *buffer, uint32_t size);

/*!
 * @brief Receives data using a blocking method.
 *
 * @param base SPDIF base pointer.
 * @param buffer Pointer to the data to be read.
 * @param size Bytes to be read.
 * @retval kStatus_Success Data received successfully
 * @retval kStatus_InvalidArgument Invalid buffer or size
 */
status_t SPDIF_ReadBlocking(SPDIF_Type *base, uint8_t *buffer, uint32_t size);

/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Initializes the SPDIF Tx handle.
 *
 * @param base SPDIF base pointer
 * @param handle SPDIF handle pointer.
 * @param callback Pointer to the user callback function.
 * @param userData User parameter passed to the callback function
 */
void SPDIF_TransferTxCreateHandle(SPDIF_Type *base,
                                       spdif_handle_t *handle,
                                       spdif_transfer_callback_t callback,
                                       void *userData);

/*!
 * @brief Initializes the SPDIF Rx handle.
 *
 * @param base SPDIF base pointer.
 * @param handle SPDIF handle pointer.
 * @param callback Pointer to the user callback function.
 * @param userData User parameter passed to the callback function.
 */
void SPDIF_TransferRxCreateHandle(SPDIF_Type *base,
                                       spdif_handle_t *handle,
                                       spdif_transfer_callback_t callback,
                                       void *userData);

/*!
 * @brief Performs an interrupt non-blocking send transfer on SPDIF.
 *
 * @param base SPDIF base pointer.
 * @param handle Pointer to the spdif_handle_t structure which stores the transfer state.
 * @param xfer Pointer to the spdif_transfer_t structure.
 * @retval kStatus_Success Successfully started the data receive.
 * @retval kStatus_SPDIF_TxBusy Previous receive still not finished.
 * @retval kStatus_InvalidArgument The input parameter is invalid.
 */
status_t SPDIF_TransferSendNonBlocking(SPDIF_Type *base,
                                            spdif_handle_t *handle,
                                            const spdif_transfer_t *xfer);

/*!
 * @brief Performs an interrupt non-blocking receive transfer on SPDIF.
 *
 * @param base SPDIF base pointer
 * @param handle Pointer to the spdif_handle_t structure which stores the transfer state.
 * @param xfer Pointer to the spdif_transfer_t structure.
 * @retval kStatus_Success Successfully started the data receive.
 * @retval kStatus_SPDIF_RxBusy Previous receive still not finished.
 * @retval kStatus_InvalidArgument The input parameter is invalid.
 */
status_t SPDIF_TransferReceiveNonBlocking(SPDIF_Type *base,
                                               spdif_handle_t *handle,
                                               const spdif_transfer_t *xfer);

/*!
 * @brief Aborts the current send.
 *
 * @param base SPDIF base pointer.
 * @param handle Pointer to the spdif_handle_t structure which stores the transfer state.
 */
void SPDIF_TransferAbortSend(SPDIF_Type *base, spdif_handle_t *handle);

/*!
 * @brief Aborts the current receive.
 *
 * @param base SPDIF base pointer
 * @param handle Pointer to the spdif_handle_t structure which stores the transfer state.
 */
void SPDIF_TransferAbortReceive(SPDIF_Type *base, spdif_handle_t *handle);

/*!
 * @brief Gets a set byte count.
 *
 * @param base SPDIF base pointer.
 * @param handle Pointer to the spdif_handle_t structure which stores the transfer state.
 * @param count Bytes count sent.
 * @retval kStatus_Success Succeed get the transfer count.
 * @retval kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t SPDIF_TransferGetSendCount(SPDIF_Type *base, spdif_handle_t *handle, size_t *count);

/*!
 * @brief Gets a received byte count.
 *
 * @param base SPDIF base pointer.
 * @param handle Pointer to the spdif_handle_t structure which stores the transfer state.
 * @param count Bytes count received.
 * @retval kStatus_Success Succeed get the transfer count.
 * @retval kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t SPDIF_TransferGetReceiveCount(SPDIF_Type *base, spdif_handle_t *handle, size_t *count);

/*!
 * @brief Tx interrupt handler.
 *
 * @param base SPDIF base pointer.
 * @param handle Pointer to the spdif_handle_t structure.
 */
void SPDIF_TransferTxHandleIRQ(SPDIF_Type *base, spdif_handle_t *handle);

/*!
 * @brief Rx interrupt handler.
 *
 * @param base SPDIF base pointer.
 * @param handle Pointer to the spdif_handle_t structure.
 */
void SPDIF_TransferRxHandleIRQ(SPDIF_Type *base, spdif_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SPDIF_H_ */
