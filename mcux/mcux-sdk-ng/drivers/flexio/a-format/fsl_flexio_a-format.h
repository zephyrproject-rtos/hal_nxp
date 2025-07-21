/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FLEXIO_A_FORMAT_H_
#define FSL_FLEXIO_A_FORMAT_H_

#include "fsl_common.h"
#include "fsl_flexio.h"

/*!
 * @addtogroup flexio_a-format
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief FlexIO A_Format driver version. */
#define FSL_FLEXIO_A_FORMAT_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/*! @brief Retry times for waiting flag. */
#ifndef A_FORMAT_RETRY_TIMES
#define A_FORMAT_RETRY_TIMES 0U /* Defining to zero means to keep waiting for the flag until it is assert/deassert. */
#endif

/*! @brief Maximum number of encoders on an A-format bus. */
#define A_FORMAT_ENCODER_MAX_NUM 8U
/*! @brief The number of bits per frame without start and stop bits. */
#define A_FORMAT_BITS_PER_FRAME_DATA 16U
/*! @brief The number of bits per frame with start and stop bits. */
#define A_FORMAT_BITS_PER_FRAME_WHOLE (A_FORMAT_BITS_PER_FRAME_DATA + 2U)
/*! @brief Calculate the value of the FlexIO timer compare register. */
#define A_FORMAT_TIMER_COMPARE_VALUE(cmp) (((A_FORMAT_BITS_PER_FRAME_DATA * 2U - 1U) << 8U) | cmp)

/*! @name A-format protocol */
/*@{*/
/*! @brief The command data frame sync code of A-format */
#define A_FORMAT_SYNC_CODE_CMD 2U
/*! @brief The encoder information field sync code of A-format */
#define A_FORMAT_SYNC_CODE_IF  4U

/*! @brief A-format CDF frame code */
#define A_FORMAT_FRAME_CODE_CDF  0U
/*! @brief A-format MDF frame code */
#define A_FORMAT_FRAME_CODE_MDF0 1U
#define A_FORMAT_FRAME_CODE_MDF1 2U
#define A_FORMAT_FRAME_CODE_MDF2 3U

/*! @brief A-format command code */
#define A_FORMAT_CDF(x)    (x)
/*!
 * brief Give the command code an alias
 *
 * IT: Individual Transmission
 * MT: Multiple Transmission
 */
#define A_FORMAT_REQ_IT_ABS_FULL_40BIT       A_FORMAT_CDF(0)
#define A_FORMAT_REQ_IT_ABS_LOWER_24BIT      A_FORMAT_CDF(1)
#define A_FORMAT_REQ_IT_ABS_UPPER_24BIT      A_FORMAT_CDF(2)
#define A_FORMAT_REQ_IT_ENCODER_STAT         A_FORMAT_CDF(3)
#define A_FORMAT_REQ_MT_ABS_FULL_40BIT       A_FORMAT_CDF(4)
#define A_FORMAT_REQ_MT_ABS_LOWER_24BIT      A_FORMAT_CDF(5)
#define A_FORMAT_REQ_MT_ABS_UPPER_24BIT      A_FORMAT_CDF(6)
#define A_FORMAT_REQ_MT_ENCODER_STAT         A_FORMAT_CDF(7)
#define A_FORMAT_REQ_IT_CLEAR_STAT_FLAG      A_FORMAT_CDF(8)
#define A_FORMAT_REQ_IT_CLEAR_MULTI_TURN     A_FORMAT_CDF(9)
#define A_FORMAT_REQ_IT_CLEAR_STAT_MULTI     A_FORMAT_CDF(10)
#define A_FORMAT_REQ_IT_SET_ENCODER_ADDR1    A_FORMAT_CDF(11)
#define A_FORMAT_REQ_IT_PRESET_SINGLE_TURN_0 A_FORMAT_CDF(12)
#define A_FORMAT_REQ_IT_MEMORY_READ          A_FORMAT_CDF(13)
#define A_FORMAT_REQ_IT_MEMORY_WRITE         A_FORMAT_CDF(14)
#define A_FORMAT_REQ_IT_TEMPERATURE_10BIT    A_FORMAT_CDF(15)
#define A_FORMAT_REQ_IT_ID_CODE_READ1        A_FORMAT_CDF(16)
#define A_FORMAT_REQ_IT_ID_CODE_READ2        A_FORMAT_CDF(17)
#define A_FORMAT_REQ_IT_ID_CODE_WRITE1       A_FORMAT_CDF(18)
#define A_FORMAT_REQ_IT_ID_CODE_WRITE2       A_FORMAT_CDF(19)
#define A_FORMAT_REQ_IT_SET_ENCODER_ADDR2    A_FORMAT_CDF(20)
#define A_FORMAT_REQ_IT_ABS_LOWER_17BIT      A_FORMAT_CDF(21)
#define A_FORMAT_REQ_MT_ABS_LOWER_17BIT      A_FORMAT_CDF(22)
#define A_FORMAT_REQ_IT_ABS_LOWER_24BIT_STAT A_FORMAT_CDF(27)
#define A_FORMAT_REQ_MT_ABS_LOWER_24BIT_STAT A_FORMAT_CDF(28)
#define A_FORMAT_REQ_IT_ABS_LOWER_24BIT_TEMP A_FORMAT_CDF(29)
#define A_FORMAT_REQ_MT_ABS_LOWER_24BIT_TEMP A_FORMAT_CDF(30)

/*! @brief The command data CRC polynomial of A-format */
#define A_FORMAT_CRC_POLY_COMMAND_DATA 0x03U
/*! @brief The encoder data CRC polynomial of A-format */
#define A_FORMAT_CRC_POLY_ENCODER_DATA 0x1DU

/*! @brief The mask of the CDF sync code */
#define A_FORMAT_CDF_MASK_SYNC_CODE    0x0007U
/*! @brief The mask of the CDF frame code */
#define A_FORMAT_CDF_MASK_FRAME_CODE   0x0018U
/*! @brief The mask of the CDF encoder address */
#define A_FORMAT_CDF_MASK_ENCODER_ADDR 0x00E0U
/*! @brief The mask of the CDF command code */
#define A_FORMAT_CDF_MASK_COMMAND_CODE 0x1F00U
/*! @brief The mask of the CDF CRC code */
#define A_FORMAT_CDF_MASK_CRC_CODE     0xE000U

/*! @brief The mask of the MDF sync code */
#define A_FORMAT_MDF_MASK_SYNC_CODE    A_FORMAT_CDF_MASK_SYNC_CODE
/*! @brief The mask of the MDF frame code */
#define A_FORMAT_MDF_MASK_FRAME_CODE   A_FORMAT_CDF_MASK_FRAME_CODE
/*! @brief The mask of the MDF data bit */
#define A_FORMAT_MDF_MASK_DATA_BIT     0x1FE0U
/*! @brief The mask of the MDF CRC code */
#define A_FORMAT_MDF_MASK_CRC_CODE     A_FORMAT_CDF_MASK_CRC_CODE

/*! @brief The mask of the IF encoder address */
#define A_FORMAT_IF_MASK_ENCODER_ADDR 0x0038U
/*! @brief The mask of the IF command code */
#define A_FORMAT_IF_MASK_COMMAND_CODE 0x07C0U
/*! @brief The mask of the IF encoder status */
#define A_FORMAT_IF_MASK_ENCODER_STAT 0xF000U

/*! @brief Shift the sync code for command data frame */
#define A_FORMAT_CDF_SHIFT_SYNC_CODE(x)    (((uint16_t)(x)) & A_FORMAT_CDF_MASK_SYNC_CODE)
/*! @brief Shift the frame code for command data frame */
#define A_FORMAT_CDF_SHIFT_FRAME_CODE(x)   (((uint16_t)(x) << 3) & A_FORMAT_CDF_MASK_FRAME_CODE)
/*! @brief Shift the encoder address for command data frame */
#define A_FORMAT_CDF_SHIFT_ENCODER_ADDR(x) (((uint16_t)(x) << 5) & A_FORMAT_CDF_MASK_ENCODER_ADDR)
/*! @brief Shift the command code for command data frame */
#define A_FORMAT_CDF_SHIFT_COMMAND_CODE(x) (((uint16_t)(x) << 8) & A_FORMAT_CDF_MASK_COMMAND_CODE)
/*! @brief Shift the CRC code for command data frame */
#define A_FORMAT_CDF_SHIFT_CRC_CODE(x)     (((uint16_t)(x) << 13) & A_FORMAT_CDF_MASK_CRC_CODE)

/*! @brief Shift the sync code for memory data frame */
#define A_FORMAT_MDF_SHIFT_SYNC_CODE(x)    A_FORMAT_CDF_SHIFT_SYNC_CODE(x)
/*! @brief Shift the frame code for memory data frame */
#define A_FORMAT_MDF_SHIFT_FRAME_CODE(x)   A_FORMAT_CDF_SHIFT_FRAME_CODE(x)
/*! @brief Shift the data bit for memory data frame */
#define A_FORMAT_MDF_SHIFT_DATA_BIT(x)     (((uint16_t)(x) << 5) & A_FORMAT_MDF_MASK_DATA_BIT)
/*! @brief Shift the CRC code for memory data frame */
#define A_FORMAT_MDF_SHIFT_CRC_CODE(x)     A_FORMAT_CDF_SHIFT_CRC_CODE(x)

/*! @brief Pack the command data frame */
#define A_FORMAT_PACK_CDF(EA, CC, CRC)     \
        (A_FORMAT_CDF_SHIFT_SYNC_CODE(A_FORMAT_SYNC_CODE_CMD) |\
         A_FORMAT_CDF_SHIFT_FRAME_CODE(A_FORMAT_FRAME_CODE_CDF) |\
         A_FORMAT_CDF_SHIFT_ENCODER_ADDR(EA) |\
         A_FORMAT_CDF_SHIFT_COMMAND_CODE(CC) |\
         A_FORMAT_CDF_SHIFT_CRC_CODE(CRC))
/*! @brief Pack the memory data frame */
#define A_FORMAT_PACK_MDF(FC, DA, CRC)     \
        (A_FORMAT_MDF_SHIFT_SYNC_CODE(A_FORMAT_SYNC_CODE_CMD) |\
         A_FORMAT_MDF_SHIFT_FRAME_CODE(FC) |\
         A_FORMAT_MDF_SHIFT_DATA_BIT(DA) |\
         A_FORMAT_MDF_SHIFT_CRC_CODE(CRC))

/*! @brief Get encoder address from the CDF frame */
#define A_FORMAT_GET_ENC_ADDR_CDF(x) ((uint8_t)(((x) & A_FORMAT_CDF_MASK_ENCODER_ADDR) >> 5))
/*! @brief Get command code from the CDF frame */
#define A_FORMAT_GET_CMD_CODE_CDF(x) ((uint8_t)(((x) & A_FORMAT_CDF_MASK_COMMAND_CODE) >> 8))
/*! @brief The mask of CRC-applied range in CDF frame */
#define A_FORMAT_CRC_RANGE_IN_CDF    (A_FORMAT_CDF_MASK_FRAME_CODE |\
                                      A_FORMAT_CDF_MASK_ENCODER_ADDR |\
                                      A_FORMAT_CDF_MASK_COMMAND_CODE)
/*! @brief Get CRC data from the CDF frame */
#define A_FORMAT_GET_CRC_DATA_CDF(x) (((x) & A_FORMAT_CRC_RANGE_IN_CDF) << 3)
/*! @brief Get CRC code from the CDF frame */
#define A_FORMAT_GET_CRC_CODE_CDF(x) ((uint8_t)(((x) & A_FORMAT_CDF_MASK_CRC_CODE) >> 13))
/*! @brief Set CRC code to the CDF frame */
#define A_FORMAT_SET_CRC_CODE_CDF(cdf, crc) (((cdf) & ~((uint16_t)A_FORMAT_CDF_MASK_CRC_CODE)) |\
                                             A_FORMAT_CDF_SHIFT_CRC_CODE(crc))

/*! @brief The mask of CRC-applied range in MDF frame */
#define A_FORMAT_CRC_RANGE_IN_MDF    (A_FORMAT_MDF_MASK_FRAME_CODE |\
                                      A_FORMAT_MDF_MASK_DATA_BIT)
/*! @brief Get CRC data from the MDF frame */
#define A_FORMAT_GET_CRC_DATA_MDF(x) (((x) & A_FORMAT_CRC_RANGE_IN_MDF) << 3)
/*! @brief Set CRC code to the MDF frame */
#define A_FORMAT_SET_CRC_CODE_MDF(mdf, crc) (((mdf) & ~((uint16_t)A_FORMAT_MDF_MASK_CRC_CODE)) |\
                                             A_FORMAT_MDF_SHIFT_CRC_CODE(crc))

/*! @brief Get encoder address from the IF frame */
#define A_FORMAT_GET_ENC_ADDR_IF(x) ((uint8_t)(((x) & A_FORMAT_IF_MASK_ENCODER_ADDR) >> 3))
/*! @brief Get command code from the IF frame */
#define A_FORMAT_GET_CMD_CODE_IF(x) ((uint8_t)(((x) & A_FORMAT_IF_MASK_COMMAND_CODE) >> 6))
/*! @brief Get encoder status from the IF frame */
#define A_FORMAT_GET_ENC_STAT_IF(x) ((uint8_t)(((x) & A_FORMAT_IF_MASK_ENCODER_STAT) >> 12))

#define ENCODER_ADDRESS_IT(x)    ((uint8_t)(x) & 0x7)
#define ENCODER_ADDRESS_MT(x)    (((uint8_t)(x) & 0x7) | 0x80)
#define ENCODER_ADDRESS_IS_MT(x) ((uint8_t)(x) & 0x80 ?  true : false)
#define ENCODER_ADDRESS(x)       ((uint8_t)(x) & 0x7F)

#define HALFWORD_NUM(x) (sizeof(x) / sizeof(uint16_t))

#define GET_TEMPERATURE_IS_BELOW_ZERO(x) ((x) & 0x0200)
#define GET_TEMPERATURE_DATA(x)          ((x) & 0x1FF)
#define GET_TEMPERATURE_VALUE(x)         (GET_TEMPERATURE_IS_BELOW_ZERO(x) ?\
                                          GET_TEMPERATURE_DATA(x) - 512 :\
                                          GET_TEMPERATURE_DATA(x)) * 0.25

#define GET_ENCODER_ID(x) ((x) & 0x00FFFFFF)
/*@}*/

#define A_FORMAT_TIMER_TX_INDEX       0
#define A_FORMAT_TIMER_TX_CLOCK_INDEX 1
#define A_FORMAT_TIMER_RX_INDEX       2
#define A_FORMAT_TIMER_RX_CLOCK_INDEX 3
#define A_FORMAT_TIMER_DR_INDEX       4

/*! @brief Error codes for the A_Format driver. */
enum
{
    kStatus_FLEXIO_A_FORMAT_TxBusy       = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 0), /*!< Transmitter is busy. */
    kStatus_FLEXIO_A_FORMAT_RxBusy       = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 1), /*!< Receiver is busy. */
    kStatus_FLEXIO_A_FORMAT_TxIdle       = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 2), /*!< Transmitter is idle. */
    kStatus_FLEXIO_A_FORMAT_RxIdle       = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 3), /*!< Receiver is idle. */
    kStatus_FLEXIO_A_FORMAT_NotSyncCMD   = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 4), /*!< This Command doesn't support sync mode. */
    kStatus_FLEXIO_A_FORMAT_OutOfIDRange = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 5), /*!< A-format encoder ID is out of range. */
    kStatus_FLEXIO_A_FORMAT_RxRingBufferOverrun =
        MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 6), /*!< A-format RX software ring buffer overrun. */
    kStatus_FLEXIO_A_FORMAT_RxHardwareOverrun  = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 7), /*!< A-format RX receiver overrun. */
    kStatus_FLEXIO_A_FORMAT_FrameErr           = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 8), /*!< Frame format error. */
    kStatus_FLEXIO_A_FORMAT_Timeout            = MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 9), /*!< A-format times out. */
    kStatus_FLEXIO_A_FORMAT_BaudrateNotSupport =
        MAKE_STATUS(kStatusGroup_FLEXIO_A_FORMAT, 10) /*!< Baudrate is not supported in current clock source */
};

typedef enum _flexio_a_format_encoder_status
{
    kFLEXIO_A_FORMAT_ES_NoErr                      = 0U,
    kFLEXIO_A_FORMAT_ES_Busy_MemBusy               = 1U,
    kFLEXIO_A_FORMAT_ES_Batt                       = 2U,
    kFLEXIO_A_FORMAT_ES_OvSpd_MemErr_OvTemp_OvFlow = 4U,
    kFLEXIO_A_FORMAT_ES_STErr_PSErr_MTErr_INCErr   = 8U,
    kFLEXIO_A_FORMAT_ES_FrameErr                   = 16U,
    kFLEXIO_A_FORMAT_ES_Anyone                     = 32U
} flexio_a_format_es_t;

/*! @brief FlexIO A_FORMAT baud rate. */
typedef enum _flexio_a_format_baud_rate_bps
{
    kFLEXIO_A_FORMAT_2_5MHZ  = 0U, /*!< Baud rate is 2.5Mbps */
    kFLEXIO_A_FORMAT_4MHZ    = 1U, /*!< Baud rate is 4Mbps */
    kFLEXIO_A_FORMAT_6_67MHZ = 2U, /*!< Baud rate is 6.67Mbps */
    kFLEXIO_A_FORMAT_8MHZ    = 3U, /*!< Baud rate is 8Mbps */
    kFLEXIO_A_FORMAT_16MHZ   = 4U, /*!< Baud rate is 16Mbps */
} flexio_a_format_baud_rate_bps_t;

/*! @brief FlexIO A_FORMAT user modes. */
typedef enum _flexio_a_format_user_modes
{
    kFLEXIO_A_FORMAT_USERMODE_ONESHOT  = 0U, /*!< User mode is oneshot */
    kFLEXIO_A_FORMAT_USERMODE_SYNC     = 1U, /*!< User mode is sync */
} flexio_a_format_user_modes_t;

/*! @brief Define FlexIO A-format interrupt mask. */
enum _flexio_a_format_interrupt_enable
{
    kFLEXIO_A_FORMAT_TxDataRegEmptyInterruptEnable = 0x1U, /*!< Transmit buffer empty interrupt enable. */
    kFLEXIO_A_FORMAT_RxDataRegFullInterruptEnable  = 0x2U, /*!< Receive buffer full interrupt enable. */
};

/*! @brief Define FlexIO A-format status mask. */
enum _flexio_a_format_status_flags
{
    kFLEXIO_A_FORMAT_TxDataRegEmptyFlag = 1U, /*!< Transmit buffer empty flag. */
    kFLEXIO_A_FORMAT_RxDataRegFullFlag  = 2U, /*!< Receive buffer full flag. */
    kFLEXIO_A_FORMAT_RxOverRunFlag      = 4U, /*!< Receive buffer over run flag. */
};

/* Forward declaration of the handle typedef. */
typedef struct _flexio_a_format_handle flexio_a_format_handle_t;

/*! @brief Define FlexIO A_FORMAT access structure typedef. */
typedef struct _flexio_a_format_type
{
    FLEXIO_Type *flexioBase; /*!< FlexIO base pointer. */
    flexio_a_format_handle_t *hanlde;
    uint16_t timerDiv;       /*!< srcClock_Hz / baudRate_bps */
    uint16_t TxDR_Offset;    /*!< The offset between Tx and DR pins */
    uint16_t interval;       /*!< Interval between frames */
    uint8_t TxPinIndex;      /*!< Pin select for A_FORMAT_Tx. */
    uint8_t RxPinIndex;      /*!< Pin select for A_FORMAT_Rx. */
    uint8_t DRPinIndex;      /*!< Pin select for A_FORMAT_DR. */
    uint8_t shifterIndex[2]; /*!< Shifter index used in FlexIO A_FORMAT. */
    uint8_t timerIndex[5];   /*!< Timer index used in FlexIO A_FORMAT. */
    uint8_t triggerIn;       /*!< Trigger signal for sync mode. */
} FLEXIO_A_FORMAT_Type;

/*! @brief Define FlexIO A_FORMAT user configuration structure. */
typedef struct _flexio_a_format_config
{
    bool enableA_Format;                              /*!< Enable/disable FlexIO A_FORMAT TX & RX. */
    bool enableInDoze;                                /*!< Enable/disable FlexIO operation in doze mode*/
    bool enableInDebug;                               /*!< Enable/disable FlexIO operation in debug mode*/
    bool enableFastAccess;                            /*!< Enable/disable fast access to FlexIO registers,
                                                       fast access requires the FlexIO clock to be at least
                                                       twice the frequency of the bus clock. */
    flexio_a_format_baud_rate_bps_t baudRate_bps;     /*!< Baud rate in bps. */
    uint8_t userMode;
} flexio_a_format_config_t;

/*! @brief Define FlexIO A-format transfer structure. */
typedef struct _flexio_a_format_transfer
{
    /*
     * Use separate TX and RX data pointer, because TX data is const data.
     * The member data is kept for backward compatibility.
     */
    union
    {
        uint16_t *data;         /*!< The buffer of data to be transfer.*/
        uint16_t *rxData;       /*!< The buffer to receive data. */
        const uint16_t *txData; /*!< The buffer of data to be sent. */
    };
    size_t dataSize; /*!< Transfer size*/
} flexio_a_format_transfer_t;

/*! @brief FlexIO UART transfer callback function. */
typedef void (*flexio_a_format_transfer_callback_t)(FLEXIO_A_FORMAT_Type *base,
                                                flexio_a_format_handle_t *handle,
                                                status_t status,
                                                void *userData);

/*! @brief Define FLEXIO A-format handle structure*/
struct _flexio_a_format_handle
{
    const uint16_t *volatile txData; /*!< Address of remaining data to send. */
    volatile size_t txDataSize;      /*!< Size of the remaining data to send. */
    uint16_t *volatile rxData;       /*!< Address of remaining data to receive. */
    volatile size_t rxDataSize;      /*!< Size of the remaining data to receive. */
    size_t txDataSizeAll;            /*!< Total bytes to be sent. */
    size_t rxDataSizeAll;            /*!< Total bytes to be received. */

    uint16_t *rxRingBuffer;             /*!< Start address of the receiver ring buffer. */
    size_t rxRingBufferSize;            /*!< Size of the ring buffer. */
    volatile uint16_t rxRingBufferHead; /*!< Index for the driver to store received data into ring buffer. */
    volatile uint16_t rxRingBufferTail; /*!< Index for the user to get data from the ring buffer. */

    flexio_a_format_transfer_callback_t callback; /*!< Callback function. */
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
 * @brief Writes one half word of data.
 *
 * @note This is a non-blocking API, which returns directly after the data is put into the
 * data register. Ensure that the TxEmptyFlag is asserted before calling this API.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param buffer The data bytes to send.
 */
static inline void FLEXIO_A_Format_WriteHalfWord(FLEXIO_A_FORMAT_Type *base, const uint16_t *buffer)
{
    base->flexioBase->SHIFTBUF[base->shifterIndex[0]] = *buffer;
}

#if defined(FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_HALF_WORD_SWAP) && FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_HALF_WORD_SWAP
/*!
 * @brief Reads one half word of data.
 *
 * @note This is a non-blocking API, which returns directly after the data is read from the
 * data register. Ensure that the RxFullFlag is asserted before calling this API.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param buffer The buffer to store the received bytes.
 */
static inline void FLEXIO_A_Format_ReadHalfWord(FLEXIO_A_FORMAT_Type *base, uint16_t *buffer)
{
    *buffer = (uint16_t)(base->flexioBase->SHIFTBUFHWS[base->shifterIndex[1]]);
}
#else
  #error FlexIO A-format driver is not supported
#endif

/*!
 * @brief The duration of the high level of the RS485 DR Pin is set
 *        according to the number of frames
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure
 * @param nFrames The number of frames (Each 16bit of data is one frame)
 */
void FLEXIO_A_Format_Config_DR_length(FLEXIO_A_FORMAT_Type *base, uint32_t nFrames);

/*!
 * @brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO A-Format
 * hardware, and configures the FlexIO A-Format with FlexIO A-Format configuration.
 * The configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_A_Format_GetDefaultConfig().
 *
 * Example
 * @code
 *    FLEXIO_A_FORMAT_Type base = {
 *    .flexioBase = FLEXIO,
 *    .TxPinIndex = 0,
 *    .RxPinIndex = 1,
 *    .shifterIndex = {0,1},
 *    .timerIndex = {0,1}
 *    };
 *    flexio_a_format_config_t config = {
 *    .enableInDoze = false,
 *    .enableInDebug = true,
 *    .enableFastAccess = false,
 *    .baudRate_bps = 2500000
 *    };
 *    FLEXIO_A_Format_Init(&base, &config, srcClock_Hz);
 * @endcode
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param userConfig Pointer to the flexio_a_format_config_t structure.
 * @param srcClock_Hz FlexIO source clock in Hz.
 * @retval kStatus_Success Configuration success.
 * @retval kStatus_FLEXIO_A_FORMAT_BaudrateNotSupport Baudrate is not supported for current clock source frequency.
 */
status_t FLEXIO_A_Format_Init(FLEXIO_A_FORMAT_Type *base, const flexio_a_format_config_t *userConfig, uint32_t srcClock_Hz);

/*!
 * @brief Resets the FlexIO A-Format shifter and timer config.
 *
 * note After calling this API, call the FLEXIO_A_Format_Init to use the FlexIO A_format module.
 *
 * @param base Pointer to FLEXIO_A_FORMAT_Type structure
 */
void FLEXIO_A_Format_Deinit(FLEXIO_A_FORMAT_Type *base);

/*!
 * @brief Gets the default configuration to configure the FlexIO A-format. The configuration
 * can be used directly for calling the FLEXIO_A_Format_Init().
 * Example:
 * @code
 *    flexio_a_format_config_t config;
 *    FLEXIO_A_Format_GetDefaultConfig(&userConfig);
 * @endcode
 * param userConfig Pointer to the flexio_a_format_config_t structure.
 */
void FLEXIO_A_Format_GetDefaultConfig(flexio_a_format_config_t *userConfig);

/*!
 * @brief Enables the FlexIO A-format interrupt.
 *
 * This function enables the FlexIO A-format interrupt.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param mask Interrupt source.
 */
void FLEXIO_A_Format_EnableInterrupts(FLEXIO_A_FORMAT_Type *base, uint32_t mask);

/*!
 * @brief Disables the FlexIO A-format interrupt.
 *
 * This function disables the FlexIO A-format interrupt.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param mask Interrupt source.
 */
void FLEXIO_A_Format_DisableInterrupts(FLEXIO_A_FORMAT_Type *base, uint32_t mask);

/*!
 * @brief Gets the FlexIO A-format status flags.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @return FlexIO A-format status flags.
 */
uint32_t FLEXIO_A_Format_GetStatusFlags(FLEXIO_A_FORMAT_Type *base);

/*!
 * @brief Clears the FlexIO A-format status flags.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param mask Status flag.
 *      The parameter can be any combination of the following values:
 *          arg kFLEXIO_A_FORMAT_TxDataRegEmptyFlag
 *          arg kFLEXIO_A_FORMAT_RxDataRegFullFlag
 *          arg kFLEXIO_A_FORMAT_RxOverRunFlag
 */
void FLEXIO_A_Format_ClearStatusFlags(FLEXIO_A_FORMAT_Type *base, uint32_t mask);

/*!
 * @brief Sends a buffer of data bytes.
 *
 * note This function blocks using the polling method until all bytes have been sent.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param txData The data bytes to send.
 * @param txSize The number of data bytes to send.
 * @retval kStatus_FLEXIO_A_FORMAT_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully wrote all data.
 */
status_t FLEXIO_A_Format_WriteBlocking(FLEXIO_A_FORMAT_Type *base, const uint16_t *txData, size_t txSize);

/*!
 * @brief Receives a buffer of bytes.
 *
 * note This function blocks using the polling method until all bytes have been received.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of data bytes to be received.
 * @retval kStatus_FLEXIO_A_FORMAT_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_A_Format_ReadBlocking(FLEXIO_A_FORMAT_Type *base, uint16_t *rxData, size_t rxSize);

/*!
 * @brief Initializes the A-format handle.
 *
 * This function initializes the FlexIO A-format handle, which can be used for other FlexIO
 * A-format transactional APIs. Call this API once to get the initialized handle.
 *
 * The A-format driver supports the "background" receiving, which means that users can set up
 * a RX ring buffer optionally. Data received is stored into the ring buffer even when
 * the user doesn't call the FLEXIO_A_Format_TransferReceiveNonBlocking() API. If there is already
 * data received in the ring buffer, users can get the received data from the ring buffer
 * directly. The ring buffer is disabled if passing NULL as p ringBuffer.
 *
 * @param base to FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 * @param callback The callback function.
 * @param userData The parameter of the callback function.
 * @retval kStatus_Success Successfully create the handle.
 * @retval kStatus_OutOfRange The FlexIO type/handle/ISR table out of range.
 */
status_t FLEXIO_A_Format_TransferCreateHandle(FLEXIO_A_FORMAT_Type *base,
                                          flexio_a_format_handle_t *handle,
                                          flexio_a_format_transfer_callback_t callback,
                                          void *userData);

/*!
 * @brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific A-format handle.
 *
 * When the RX ring buffer is used, data received is stored into the ring buffer even when
 * the user doesn't call the A_Format_ReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, users can get the received data from the ring buffer directly.
 *
 * note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if p ringBufferSize is 32, only 31 bytes are used for saving data.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 * @param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * @param ringBufferSize Size of the ring buffer.
 */
void FLEXIO_A_Format_TransferStartRingBuffer(FLEXIO_A_FORMAT_Type *base,
                                         flexio_a_format_handle_t *handle,
                                         uint16_t *ringBuffer,
                                         size_t ringBufferSize);

/*!
 * @brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 */
void FLEXIO_A_Format_TransferStopRingBuffer(FLEXIO_A_FORMAT_Type *base, flexio_a_format_handle_t *handle);

/*!
 * @brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using an interrupt method. This is a non-blocking function,
 * which returns directly without waiting for all data to be written to the TX register. When
 * all data is written to the TX register in ISR, the FlexIO A-format driver calls the callback
 * function and passes the ref kStatus_FLEXIO_A_FORMAT_TxIdle as status parameter.
 *
 * note The kStatus_FLEXIO_A_FORMAT_TxIdle is passed to the upper layer when all data is written
 * to the TX register. However, it does not ensure that all data is sent out.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 * @param xfer FlexIO A-format transfer structure. See #flexio_a_format_transfer_t.
 * @retval kStatus_Success Successfully starts the data transmission.
 * @retval kStatus_A_FORMAT_TxBusy Previous transmission still not finished, data not written to the TX register.
 */
status_t FLEXIO_A_Format_TransferSendNonBlocking(FLEXIO_A_FORMAT_Type *base,
                                             flexio_a_format_handle_t *handle,
                                             flexio_a_format_transfer_t *xfer);

/*!
 * @brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt-driven data sending. Get the remainHalfwords to find out
 * how many half-words are still not sent out.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 */
void FLEXIO_A_Format_TransferAbortSend(FLEXIO_A_FORMAT_Type *base, flexio_a_format_handle_t *handle);

/*!
 * @brief Gets the number of half-words sent.
 *
 * This function gets the number of half-words sent driven by interrupt.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 * @param count Number of half-words sent so far by the non-blocking transaction.
 * @retval kStatus_NoTransferInProgress transfer has finished or no transfer in progress.
 * @retval kStatus_Success Successfully return the count.
 */
status_t FLEXIO_A_Format_TransferGetSendCount(FLEXIO_A_FORMAT_Type *base, flexio_a_format_handle_t *handle, size_t *count);

/*!
 * @brief Receives a buffer of data using the interrupt method.
 *
 * This function receives data using the interrupt method. This is a non-blocking function,
 * which returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in ring buffer is copied and
 * the parameter p receivedHalfWords shows how many half-words are copied from the ring buffer.
 * After copying, if the data in ring buffer is not enough to read, the receive
 * request is saved by the A-format driver. When new data arrives, the receive request
 * is serviced first. When all data is received, the A-format driver notifies the upper layer
 * through a callback function and passes the status parameter ref kStatus_A_FORMAT_RxIdle.
 * For example, if the upper layer needs 10 half-words but there are only 5 half-words in the ring buffer,
 * the 5 half-words are copied to xfer->data. This function returns with the
 * parameter p receivedHalfWords set to 5. For the last 5 half-words, newly arrived data is
 * saved from the xfer->data[5]. When 5 half-words are received, the A-format driver notifies upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to xfer->data. When all data is received, the upper layer is notified.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 * @param xfer A-format transfer structure. See #flexio_a_format_transfer_t.
 * @param receivedHalfWords Half-words received from the ring buffer directly.
 * @retval kStatus_Success Successfully queue the transfer into the transmit queue.
 * @retval kStatus_FLEXIO_A_FORMAT_RxBusy Previous receive request is not finished.
 */
status_t FLEXIO_A_Format_TransferReceiveNonBlocking(FLEXIO_A_FORMAT_Type *base,
                                                flexio_a_format_handle_t *handle,
                                                flexio_a_format_transfer_t *xfer,
                                                size_t *receivedHalfWords);

/*!
 * @brief Aborts the receive data which was using IRQ.
 *
 * This function aborts the receive data which was using IRQ.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 */
void FLEXIO_A_Format_TransferAbortReceive(FLEXIO_A_FORMAT_Type *base, flexio_a_format_handle_t *handle);

/*!
 * @brief Gets the number of half-words received.
 *
 * This function gets the number of half-words received driven by interrupt.
 *
 * @param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param handle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 * @param count Number of half-words received so far by the non-blocking transaction.
 * @retval kStatus_NoTransferInProgress transfer has finished or no transfer in progress.
 * @retval kStatus_Success Successfully return the count.
 */
status_t FLEXIO_A_Format_TransferGetReceiveCount(FLEXIO_A_FORMAT_Type *base, flexio_a_format_handle_t *handle, size_t *count);

/*!
 * @brief FlexIO A-format IRQ handler function.
 *
 * This function processes the FlexIO A-format transmit and receives the IRQ request.
 *
 * @param uartType Pointer to the FLEXIO_A_FORMAT_Type structure.
 * @param uartHandle Pointer to the flexio_a_format_handle_t structure to store the transfer state.
 */
void FLEXIO_A_Format_TransferHandleIRQ(void *uartType, void *uartHandle);

/*!
 * brief Flush tx/rx shifters.
 *
 * param base Pointer to the FLEXIO_A_FORMAT_Type structure.
 */
void FLEXIO_A_Format_FlushShifters(FLEXIO_A_FORMAT_Type *base);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* @} */

#endif
