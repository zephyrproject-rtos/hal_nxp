/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FLEXIO_T_FORMAT_H_
#define FSL_FLEXIO_T_FORMAT_H_

#include "fsl_common.h"
#include "fsl_flexio.h"

/*!
 * @addtogroup flexio_t-format
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief FlexIO T_Format driver version. */
#define FSL_FLEXIO_T_FORMAT_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/*! @brief Retry times for waiting flag. */
#ifndef T_FORMAT_RETRY_TIMES
#define T_FORMAT_RETRY_TIMES 0U /* Defining to zero means to keep waiting for the flag until it is assert/deassert. */
#endif

/*! @brief Maximum number of encoders on an T-format bus. */
#define T_FORMAT_ENCODER_MAX_NUM 1U
/*! @brief The number of bits per frame without start and stop bits. */
#define T_FORMAT_BITS_PER_FRAME_DATA 8U
/*! @brief The number of bits per frame with start and stop bits. */
#define T_FORMAT_BITS_PER_FRAME_WHOLE (T_FORMAT_BITS_PER_FRAME_DATA + 2U)
/*! @brief Calculate the value of the FlexIO timer compare register. */
#define T_FORMAT_TIMER_COMPARE_VALUE(cmp) (((T_FORMAT_BITS_PER_FRAME_DATA * 2U - 1U) << 8U) | cmp)

/*! @name T-format protocol */
/*@{*/
/*! @brief The Sink code of the control field of T-format */
#define T_FORMAT_SINK_CODE_CF 2U

/*! @brief The mask of the CF sink code */
#define T_FORMAT_CF_MASK_SINK_CODE    0x07U
/*! @brief The mask of the CF data ID code */
#define T_FORMAT_CF_MASK_DATA_ID_CODE 0x78U
/*! @brief The mask of the CF ID parity */
#define T_FORMAT_CF_MASK_ID_PARITY    0x80U

/*! @brief Data ID code for the control field */
#define T_FORMAT_CF_DATA_ID_CODE(x)   (((uint8_t)(x) << 3) & T_FORMAT_CF_MASK_DATA_ID_CODE)
/*! @brief ID parity for the control field */
#define T_FORMAT_CF_ID_PARITY(x)      (((uint8_t)(x) << 7) & T_FORMAT_CF_MASK_ID_PARITY)

/*! @brief The DATA ID Code of the T-format */
#define T_FORMAT_DATA_ID(code, parity) \
        (T_FORMAT_CF_DATA_ID_CODE(code) |\
         T_FORMAT_CF_ID_PARITY(parity))

/*! @brief The control field of T-format */
#define T_FORMAT_CF(DataID)  \
        (T_FORMAT_SINK_CODE_CF | DataID)

/*! @brief List of the control field value */
#define T_FORMAT_CF_GET_ABS         T_FORMAT_CF(T_FORMAT_DATA_ID(0x0, 0))
#define T_FORMAT_CF_GET_ABM         T_FORMAT_CF(T_FORMAT_DATA_ID(0x1, 1))
#define T_FORMAT_CF_GET_ENCID       T_FORMAT_CF(T_FORMAT_DATA_ID(0x2, 1))
#define T_FORMAT_CF_GET_ALL         T_FORMAT_CF(T_FORMAT_DATA_ID(0x3, 0))
#define T_FORMAT_CF_RESET_ALL_ERROR T_FORMAT_CF(T_FORMAT_DATA_ID(0x7, 1))
#define T_FORMAT_CF_RESET_ABS       T_FORMAT_CF(T_FORMAT_DATA_ID(0x8, 1))
#define T_FORMAT_CF_RESET_ABM_ERROR T_FORMAT_CF(T_FORMAT_DATA_ID(0xC, 0))
#define T_FORMAT_CF_EEPROM_WRITE    T_FORMAT_CF(T_FORMAT_DATA_ID(0x6, 0))
#define T_FORMAT_CF_EEPROM_READOUT  T_FORMAT_CF(T_FORMAT_DATA_ID(0xD, 1))

/*! @brief The mask bit of ALMC(Encoder error) */
#define T_FORMAT_ALMC_MASK_OVER_SPEED           ((uint8_t)(1 << 0))
#define T_FORMAT_ALMC_MASK_FULL_ABSOLUTE_STATUS ((uint8_t)(1 << 1))
#define T_FORMAT_ALMC_MASK_COUNTING_ERROR       ((uint8_t)(1 << 2))
#define T_FORMAT_ALMC_MASK_COUNTER_OVERFLOW     ((uint8_t)(1 << 3))
#define T_FORMAT_ALMC_MASK_OVERHEAT             ((uint8_t)(1 << 4))
#define T_FORMAT_ALMC_MASK_MULTITURN_ERROR      ((uint8_t)(1 << 5))
#define T_FORMAT_ALMC_MASK_BATTERY_ERROR        ((uint8_t)(1 << 6))
#define T_FORMAT_ALMC_MASK_BATTERY_ALARM        ((uint8_t)(1 << 7))

/*! @brief The mask of the SF encoder error */
#define T_FORMAT_SF_MASK_ENCODER_ERROR       0x30U
/*! @brief The mask of the SF communication alarm */
#define T_FORMAT_SF_MASK_COMMUNICATION_ALARM 0xC0U

/*! @brief Get the SF encoder error */
#define T_FORMAT_SF_GET_ENCODER_ERROR(x)       (((x) & T_FORMAT_SF_MASK_ENCODER_ERROR) >> 4)
/*! @brief Get the SF communication alarm */
#define T_FORMAT_SF_GET_COMMUNICATION_ALARM(x) (((x) & T_FORMAT_SF_MASK_COMMUNICATION_ALARM) >> 6)

/*! @brief The mask of the ADF address */
#define T_FORMAT_ADF_MASK_ADDRESS    0x7FU
/*! @brief The mask of the ADF busy status */
#define T_FORMAT_SF_MASK_BUSY_STATUS 0x80U

/*! @brief The CRC polynomial */
#define T_FORMAT_CRC_POLYNOMIAL 0x01U

/*! @brief The number of the byte in the received data */
#define T_FORMAT_ABS_BYTE        6U
#define T_FORMAT_ABM_BYTE        6U
#define T_FORMAT_ENCODER_ID_BYTE 4U
#define T_FORMAT_ALL_INFO_BYTE   11U
#define T_FORMAT_EEPROM_BYTE     4U

/*! @brief Do not cause Over-heat */
#define T_FORMAT_OVER_HEAT_NOT_CAUSE 0U
#define T_FORMAT_OVER_HEAT_TEMPERATURE(x) (0x80U | (x))
/*@}*/

#define T_FORMAT_TIMER_TX_INDEX       0
#define T_FORMAT_TIMER_RX_INDEX       1
#define T_FORMAT_TIMER_DR_INDEX       2

/*! @brief Error codes for the T_Format driver. */
enum
{
    kStatus_FLEXIO_T_FORMAT_EncErr0_CountingErr  = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 0), /*!< Transmitter is busy. */
    kStatus_FLEXIO_T_FORMAT_EncErr1_LogicOR      = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 1), /*!< Encoder error: Logic-OR of Over-heat, Multi-turn error, Battery error and Battery alarm. */
    kStatus_FLEXIO_T_FORMAT_ComAlr0_ParityErr    = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 2), /*!< Communication alarm: Parity error. */
    kStatus_FLEXIO_T_FORMAT_ComAlr1_DelimiterErr = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 3), /*!< Communication alarm: Delimiter error. */

    kStatus_FLEXIO_T_FORMAT_EncErr_OS = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 4),  /*!< Over speed. */
    kStatus_FLEXIO_T_FORMAT_EncErr_FS = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 5),  /*!< Full absolute status. */
    kStatus_FLEXIO_T_FORMAT_EncErr_CE = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 6),  /*!< Countering error. */
    kStatus_FLEXIO_T_FORMAT_EncErr_OF = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 7),  /*!< Countering overflow. */
    kStatus_FLEXIO_T_FORMAT_EncErr_OH = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 8),  /*!< Over heat. */
    kStatus_FLEXIO_T_FORMAT_EncErr_ME = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 9),  /*!< Multi-turn error. */
    kStatus_FLEXIO_T_FORMAT_EncErr_BE = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 10), /*!< Battery error. */
    kStatus_FLEXIO_T_FORMAT_EncErr_BA = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 11), /*!< Battery alarm. */

    kStatus_FLEXIO_T_FORMAT_FrameErr  = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 12), /*!< Frame format error. */
    kStatus_FLEXIO_T_FORMAT_BaudrateNotSupport = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 13),
    kStatus_FLEXIO_T_FORMAT_Timeout   = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 14), /*!< T_FORMAT times out. */
    kStatus_FLEXIO_T_FORMAT_TxBusy    = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 15), /*!< Transmitter is busy. */
    kStatus_FLEXIO_T_FORMAT_RxBusy    = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 16), /*!< Receiver is busy. */
    kStatus_FLEXIO_T_FORMAT_TxIdle    = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 17), /*!< Transmitter is idle. */
    kStatus_FLEXIO_T_FORMAT_RxIdle    = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 18), /*!< Receiver is idle. */
    kStatus_FLEXIO_T_FORMAT_RxRingBufferOverrun =
        MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 19), /*!< A-format RX software ring buffer overrun. */
    kStatus_FLEXIO_T_FORMAT_RxHardwareOverrun  = MAKE_STATUS(kStatusGroup_FLEXIO_T_FORMAT, 20), /*!< A-format RX receiver overrun. */
};

/*! @brief Define FlexIO T-format interrupt mask. */
enum _flexio_t_format_interrupt_enable
{
    kFLEXIO_T_FORMAT_TxDataRegEmptyInterruptEnable = 0x1U, /*!< Transmit buffer empty interrupt enable. */
    kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable  = 0x2U, /*!< Receive buffer full interrupt enable. */
};

enum _flexio_t_format_flags
{
    kFLEXIO_T_FORMAT_TxDataRegEmptyFlag = 1U, /*!< Transmit buffer empty flag. */
    kFLEXIO_T_FORMAT_RxDataRegFullFlag  = 2U, /*!< Receive buffer full flag. */
    kFLEXIO_T_FORMAT_RxOverRunFlag      = 4U, /*!< Receive buffer over run flag. */
};

/*! @brief FlexIO T_FORMAT user modes. */
typedef enum _flexio_t_format_user_modes
{
    kFLEXIO_T_FORMAT_USERMODE_ONESHOT  = 0U, /*!< User mode is oneshot */
    kFLEXIO_T_FORMAT_USERMODE_SYNC     = 1U, /*!< User mode is sync */
} flexio_t_format_user_modes_t;

/* Forward declaration of the handle typedef. */
typedef struct _flexio_t_format_handle flexio_t_format_handle_t;

/*! @brief Define FlexIO T_FORMAT access structure typedef. */
typedef struct _flexio_t_format_type
{
    FLEXIO_Type *flexioBase; /*!< FlexIO base pointer. */
    flexio_t_format_handle_t *hanlde;
    uint16_t timerDiv;       /*!< srcClock_Hz / baudRate_bps */
    uint16_t TxDR_Offset;    /*!< The offset between Tx and DR pins */
    uint16_t interval;       /*!< Interval between frames */
    uint8_t TxPinIndex;      /*!< Pin select for T_FORMAT_Tx. */
    uint8_t RxPinIndex;      /*!< Pin select for T_FORMAT_Rx. */
    uint8_t DRPinIndex;      /*!< Pin select for T_FORMAT_DR. */
    uint8_t shifterIndex[2]; /*!< Shifter index used in FlexIO T_FORMAT. */
    uint8_t timerIndex[3];   /*!< Timer index used in FlexIO T_FORMAT. */
    uint8_t triggerIn;       /*!< Trigger signal for sync mode. */
} FLEXIO_T_FORMAT_Type;

/*! @brief Define FlexIO T_FORMAT user configuration structure. */
typedef struct _flexio_t_format_config
{
    bool enableT_Format;                              /*!< Enable/disable FlexIO T_FORMAT TX & RX. */
    bool enableInDoze;                                /*!< Enable/disable FlexIO operation in doze mode*/
    bool enableInDebug;                               /*!< Enable/disable FlexIO operation in debug mode*/
    bool enableFastAccess;                            /*!< Enable/disable fast access to FlexIO registers,
                                                       fast access requires the FlexIO clock to be at least
                                                       twice the frequency of the bus clock. */
    uint8_t userMode;
} flexio_t_format_config_t;

/*! @brief Define FlexIO T-format transfer structure. */
typedef struct _flexio_t_format_transfer
{
    /*
     * Use separate TX and RX data pointer, because TX data is const data.
     * The member data is kept for backward compatibility.
     */
    union
    {
        uint8_t *data;         /*!< The buffer of data to be transfer.*/
        uint8_t *rxData;       /*!< The buffer to receive data. */
        const uint8_t *txData; /*!< The buffer of data to be sent. */
    };
    size_t dataSize; /*!< Transfer size*/
} flexio_t_format_transfer_t;

/*! @brief FlexIO T-format transfer callback function. */
typedef void (*flexio_t_format_transfer_callback_t)(FLEXIO_T_FORMAT_Type *base,
                                                    flexio_t_format_handle_t *handle,
                                                    status_t status,
                                                    void *userData);

/*! @brief Define FLEXIO T-format handle structure*/
struct _flexio_t_format_handle
{
    const uint8_t *volatile txData; /*!< Address of remaining data to send. */
    volatile size_t txDataSize;      /*!< Size of the remaining data to send. */
    uint8_t *volatile rxData;       /*!< Address of remaining data to receive. */
    volatile size_t rxDataSize;      /*!< Size of the remaining data to receive. */
    size_t txDataSizeAll;            /*!< Total bytes to be sent. */
    size_t rxDataSizeAll;            /*!< Total bytes to be received. */

    uint8_t *rxRingBuffer;             /*!< Start address of the receiver ring buffer. */
    size_t rxRingBufferSize;            /*!< Size of the ring buffer. */
    volatile uint16_t rxRingBufferHead; /*!< Index for the driver to store received data into ring buffer. */
    volatile uint16_t rxRingBufferTail; /*!< Index for the user to get data from the ring buffer. */

    flexio_t_format_transfer_callback_t callback; /*!< Callback function. */
    void *userData;                               /*!< A-format callback function parameter.*/

    volatile uint8_t txState; /*!< TX transfer state. */
    volatile uint8_t rxState; /*!< RX transfer state */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Writes one byte of data.
 *
 * @note This is a non-blocking API, which returns directly after the data is put into the
 * data register. Ensure that the TxEmptyFlag is asserted before calling this API.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param buffer The data bytes to send.
 */
static inline void FLEXIO_T_Format_WriteByte(FLEXIO_T_FORMAT_Type *base, const uint8_t *buffer)
{
    base->flexioBase->SHIFTBUF[base->shifterIndex[0]] = *buffer;
}

/*!
 * @brief Reads one byte of data.
 *
 * @note This is a non-blocking API, which returns directly after the data is read from the
 * data register. Ensure that the RxFullFlag is asserted before calling this API.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param buffer The buffer to store the received bytes.
 */
static inline void FLEXIO_T_Format_ReadByte(FLEXIO_T_FORMAT_Type *base, uint8_t *buffer)
{
    *buffer = (uint8_t)(base->flexioBase->SHIFTBUFBYS[base->shifterIndex[1]]);
}

/*!
 * @brief The duration of the high level of the RS485 DR Pin is set
 *        according to the number of frames
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure
 * @param nFrames The number of frames (Each 8bit of data is one frame)
 */
void FLEXIO_T_Format_Config_DR_length(FLEXIO_T_FORMAT_Type *base, uint32_t nFrames);

/*!
 * @brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO T-Format
 * hardware, and configures the FlexIO T-Format with FlexIO T-Format configuration.
 * The configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_T_FORMAT_GetDefaultConfig().
 *
 * Example
 * @code
 *    FLEXIO_T_FORMAT_Type base = {
 *    .flexioBase = FLEXIO,
 *    .TxPinIndex = 0,
 *    .RxPinIndex = 1,
 *    .shifterIndex = {0,1},
 *    .timerIndex = {0,1}
 *    };
 *    flexio_t_format_config_t config = {
 *    .enableInDoze = false,
 *    .enableInDebug = true,
 *    .enableFastAccess = false,
 *    .baudRate_bps = 2500000
 *    };
 *    FLEXIO_T_Format_Init(&base, &config);
 * @endcode
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param userConfig Pointer to the flexio_t_format_config_t structure.
 * @retval kStatus_Success Configuration success.
 */
status_t FLEXIO_T_Format_Init(FLEXIO_T_FORMAT_Type *base, flexio_t_format_config_t *userConfig, uint32_t srcClock_Hz);

/*!
 * @brief Resets the FlexIO T-Format shifter and timer config.
 *
 * note After calling this API, call the FLEXIO_T_Format_Init to use the FlexIO T_format module.
 *
 * @param base Pointer to FLEXIO_T_FORMAT_Type structure
 */
void FLEXIO_T_Format_Deinit(FLEXIO_T_FORMAT_Type *base);

/*!
 * @brief Gets the default configuration to configure the FlexIO T-format. The configuration
 * can be used directly for calling the FLEXIO_T_Format_Init().
 * Example:
 * @code
 *    flexio_t_format_config_t config;
 *    FLEXIO_T_Format_GetDefaultConfig(&userConfig);
 * @endcode
 *
 * @param userConfig Pointer to the flexio_t_format_config_t structure.
 */
void FLEXIO_T_Format_GetDefaultConfig(flexio_t_format_config_t *userConfig);

/*!
 * @brief Enables the FlexIO T-format interrupt.
 *
 * This function enables the FlexIO T-format interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param mask Interrupt source.
 */
void FLEXIO_T_Format_EnableInterrupts(FLEXIO_T_FORMAT_Type *base, uint32_t mask);

/*!
 * @brief Disables the FlexIO T-format interrupt.
 *
 * This function disables the FlexIO T-format interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param mask Interrupt source.
 */
void FLEXIO_T_Format_DisableInterrupts(FLEXIO_T_FORMAT_Type *base, uint32_t mask);

/*!
 * @brief Gets the FlexIO T-format status flags.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @return FlexIO T-format status flags.
 */
uint32_t FLEXIO_T_Format_GetStatusFlags(FLEXIO_T_FORMAT_Type *base);

/*!
 * @brief Clears the FlexIO T-format status flags.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param mask Status flag.
 *      The parameter can be any combination of the following values:
 *          arg kFLEXIO_T_FORMAT_TxDataRegEmptyFlag
 *          arg kFLEXIO_T_FORMAT_RxDataRegFullFlag
 *          arg kFLEXIO_T_FORMAT_RxOverRunFlag
 */
void FLEXIO_T_Format_ClearStatusFlags(FLEXIO_T_FORMAT_Type *base, uint32_t mask);

/*!
 * @brief Sends a buffer of data bytes.
 *
 * note This function blocks using the polling method until all bytes have been sent.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param txData The data bytes to send.
 * @param txSize The number of data bytes to send.
 * @retval kStatus_FLEXIO_T_FORMAT_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully wrote all data.
 */
status_t FLEXIO_T_Format_WriteBlocking(FLEXIO_T_FORMAT_Type *base, const uint8_t *txData, size_t txSize);

/*!
 * @brief Receives a buffer of bytes.
 *
 * note This function blocks using the polling method until all bytes have been received.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of data bytes to be received.
 * @retval kStatus_FLEXIO_T_FORMAT_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_T_Format_ReadBlocking(FLEXIO_T_FORMAT_Type *base, uint8_t *rxData, size_t rxSize);

/*!
 * @brief Initializes the T-format handle.
 *
 * This function initializes the FlexIO T-format handle, which can be used for other FlexIO
 * T-format transactional APIs. Call this API once to get the initialized handle.
 *
 * The T-format driver supports the "background" receiving, which means that users can set up
 * a RX ring buffer optionally. Data received is stored into the ring buffer even when
 * the user doesn't call the FLEXIO_T_Format_TransferReceiveNonBlocking() API. If there is already
 * data received in the ring buffer, users can get the received data from the ring buffer
 * directly. The ring buffer is disabled if passing NULL as p ringBuffer.
 *
 * @param base to FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param callback The callback function.
 * @param userData The parameter of the callback function.
 * @retval kStatus_Success Successfully create the handle.
 * @retval kStatus_OutOfRange The FlexIO type/handle/ISR table out of range.
 */
status_t FLEXIO_T_Format_TransferCreateHandle(FLEXIO_T_FORMAT_Type *base,
                                              flexio_t_format_handle_t *handle,
                                              flexio_t_format_transfer_callback_t callback,
                                              void *userData);

/*!
 * @brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific T-format handle.
 *
 * When the RX ring buffer is used, data received is stored into the ring buffer even when
 * the user doesn't call the T_Format_ReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, users can get the received data from the ring buffer directly.
 *
 * note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if p ringBufferSize is 32, only 31 bytes are used for saving data.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * @param ringBufferSize Size of the ring buffer.
 */
void FLEXIO_T_Format_TransferStartRingBuffer(FLEXIO_T_FORMAT_Type *base,
                                             flexio_t_format_handle_t *handle,
                                             uint8_t *ringBuffer,
                                             size_t ringBufferSize);
/*!
 * @brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferStopRingBuffer(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle);

/*!
 * @brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using an interrupt method. This is a non-blocking function,
 * which returns directly without waiting for all data to be written to the TX register. When
 * all data is written to the TX register in ISR, the FlexIO T-format driver calls the callback
 * function and passes the ref kStatus_FLEXIO_T_FORMAT_TxIdle as status parameter.
 *
 * note The kStatus_FLEXIO_T_FORMAT_TxIdle is passed to the upper layer when all data is written
 * to the TX register. However, it does not ensure that all data is sent out.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param xfer FlexIO T-format transfer structure. See #flexio_t_format_transfer_t.
 * @retval kStatus_Success Successfully starts the data transmission.
 * @retval kStatus_T_FORMAT_TxBusy Previous transmission still not finished, data not written to the TX register.
 */
status_t FLEXIO_T_Format_TransferSendNonBlocking(FLEXIO_T_FORMAT_Type *base,
                                                 flexio_t_format_handle_t *handle,
                                                 flexio_t_format_transfer_t *xfer);

/*!
 * @brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt-driven data sending. Get the remainHalfwords to find out
 * how many half-words are still not sent out.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferAbortSend(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle);

/*!
 * @brief Gets the number of bytes sent.
 *
 * This function gets the number of bytes sent driven by interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param count Number of bytes sent so far by the non-blocking transaction.
 * @retval kStatus_NoTransferInProgress transfer has finished or no transfer in progress.
 * @retval kStatus_Success Successfully return the count.
 */
status_t FLEXIO_T_Format_TransferGetSendCount(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle, size_t *count);

/*!
 * @brief Receives a buffer of data using the interrupt method.
 *
 * This function receives data using the interrupt method. This is a non-blocking function,
 * which returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in ring buffer is copied and
 * the parameter p receivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in ring buffer is not enough to read, the receive
 * request is saved by the T-format driver. When new data arrives, the receive request
 * is serviced first. When all data is received, the T-format driver notifies the upper layer
 * through a callback function and passes the status parameter ref kStatus_T_FORMAT_RxIdle.
 * For example, if the upper layer needs 10 bytes but there are only 5 bytes in the ring buffer,
 * the 5 bytes are copied to xfer->data. This function returns with the
 * parameter p receivedBytes set to 5. For the last 5 bytes, newly arrived data is
 * saved from the xfer->data[5]. When 5 bytes are received, the T-format driver notifies upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to xfer->data. When all data is received, the upper layer is notified.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param xfer T-format transfer structure. See #flexio_t_format_transfer_t.
 * @param receivedBytes bytes received from the ring buffer directly.
 * @retval kStatus_Success Successfully queue the transfer into the transmit queue.
 * @retval kStatus_FLEXIO_T_FORMAT_RxBusy Previous receive request is not finished.
 */
status_t FLEXIO_T_Format_TransferReceiveNonBlocking(FLEXIO_T_FORMAT_Type *base,
                                                    flexio_t_format_handle_t *handle,
                                                    flexio_t_format_transfer_t *xfer,
                                                    size_t *receivedBytes);

/*!
 * @brief Aborts the receive data which was using IRQ.
 *
 * This function aborts the receive data which was using IRQ.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferAbortReceive(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle);

/*!
 * @brief Gets the number of bytes received.
 *
 * This function gets the number of bytes received driven by interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param count Number of bytes received so far by the non-blocking transaction.
 * @retval kStatus_NoTransferInProgress transfer has finished or no transfer in progress.
 * @retval kStatus_Success Successfully return the count.
 */
status_t FLEXIO_T_Format_TransferGetReceiveCount(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle, size_t *count);

/*!
 * @brief FlexIO T-format IRQ handler function.
 *
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param cf Sets commands to be sent in synchronous mode.
 * @return kStatus_Success
 */
status_t FLEXIO_T_Format_SendSyncReq(FLEXIO_T_FORMAT_Type *base, const uint8_t cf);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* @} */

#endif
