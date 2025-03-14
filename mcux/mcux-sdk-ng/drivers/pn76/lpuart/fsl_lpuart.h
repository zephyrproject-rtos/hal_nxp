/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LPUART_H_
#define FSL_LPUART_H_

#include "fsl_common.h"

/*!
 * @addtogroup lpuart
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @brief Defines LPUART driver version 2.0.1. */
#define FSL_LPUART_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))

#define LPUART_BITMSK(bit)                (1UL << (bit))
#define LPUART_GET_REG(regAddr)           (*((volatile uint32_t *)(regAddr)))
#define LPUART_SET_REG(regAddr, regValue) ((LPUART_GET_REG(regAddr)) = ((uint32_t)(regValue)))
#define LPUART_SET_FIELD(regAddr, regMask, regValue) \
    ((LPUART_GET_REG(regAddr)) =                     \
         (((LPUART_GET_REG(regAddr)) & (~((uint32_t)(regMask)))) | (((uint32_t)(regValue)) & ((uint32_t)(regMask)))))
#define LPUART_SET_BITN(regAddr, bitPos)   ((LPUART_GET_REG(regAddr)) |= LPUART_BITMSK(bitPos))
#define LPUART_CLEAR_BITN(regAddr, bitPos) ((LPUART_GET_REG(regAddr)) &= ~LPUART_BITMSK(bitPos))

/*! @brief Error codes for the LPUART driver. */
enum
{
    kStatus_LPUART_TxBusy                  = MAKE_STATUS(kStatusGroup_LPUART, 0), /*!< TX busy */
    kStatus_LPUART_RxBusy                  = MAKE_STATUS(kStatusGroup_LPUART, 1), /*!< RX busy */
    kStatus_LPUART_TxIdle                  = MAKE_STATUS(kStatusGroup_LPUART, 2), /*!< LPUART transmitter is idle. */
    kStatus_LPUART_RxIdle                  = MAKE_STATUS(kStatusGroup_LPUART, 3), /*!< LPUART receiver is idle. */
    kStatus_LPUART_TxWatermarkTooLarge     = MAKE_STATUS(kStatusGroup_LPUART, 4), /*!< TX FIFO watermark too large  */
    kStatus_LPUART_RxWatermarkTooLarge     = MAKE_STATUS(kStatusGroup_LPUART, 5), /*!< RX FIFO watermark too large  */
    kStatus_LPUART_FlagCannotClearManually = MAKE_STATUS(kStatusGroup_LPUART, 6), /*!< Some flag can't manually clear */
    kStatus_LPUART_Error                   = MAKE_STATUS(kStatusGroup_LPUART, 7), /*!< Error happens on LPUART. */
    kStatus_LPUART_RxRingBufferOverrun =
        MAKE_STATUS(kStatusGroup_LPUART, 8), /*!< LPUART RX software ring buffer overrun. */
    kStatus_LPUART_RxHardwareOverrun = MAKE_STATUS(kStatusGroup_LPUART, 9),  /*!< LPUART RX receiver overrun. */
    kStatus_LPUART_NoiseError        = MAKE_STATUS(kStatusGroup_LPUART, 10), /*!< LPUART noise error. */
    kStatus_LPUART_FramingError      = MAKE_STATUS(kStatusGroup_LPUART, 11), /*!< LPUART framing error. */
    kStatus_LPUART_ParityError       = MAKE_STATUS(kStatusGroup_LPUART, 12), /*!< LPUART parity error. */
    kStatus_LPUART_BaudrateNotSupport =
        MAKE_STATUS(kStatusGroup_LPUART, 13), /*!< Baudrate is not support in current clock source */
    kStatus_LPUART_IdleLineDetected = MAKE_STATUS(kStatusGroup_LPUART, 14), /*!< IDLE flag. */
    kStatus_LPUART_Timeout          = MAKE_STATUS(kStatusGroup_LPUART, 15), /*!< LPUART times out. */
};

/*!
 * @brief LPUART status flags.
 *
 * This provides constants for the LPUART status flags for use in the LPUART functions.
 */
enum _lpuart_flags
{
    kLPUART_TxDataRegEmptyFlag =
        (LPUART_STAT_TDRE_MASK), /*!< Transmit data register empty flag, sets when transmit buffer is empty. bit 23 */
    kLPUART_TransmissionCompleteFlag =
        (LPUART_STAT_TC_MASK), /*!< Transmission complete flag, sets when transmission activity complete. bit 22 */
    kLPUART_RxDataRegFullFlag = (LPUART_STAT_RDRF_MASK), /*!< Receive data register full flag, sets when the receive
                                                            data buffer is full. bit 21 */
    kLPUART_IdleLineFlag  = (LPUART_STAT_IDLE_MASK), /*!< Idle line detect flag, sets when idle line detected. bit 20 */
    kLPUART_RxOverrunFlag = (LPUART_STAT_OR_MASK),   /*!< Receive Overrun, sets when new data is received before data is
                                                        read from receive register. bit 19 */
    kLPUART_NoiseErrorFlag = (LPUART_STAT_NF_MASK),  /*!< Receive takes 3 samples of each received bit.  If any of these
                                                        samples differ, noise flag sets. bit 18 */
    kLPUART_FramingErrorFlag =
        (LPUART_STAT_FE_MASK), /*!< Frame error flag, sets if logic 0 was detected where stop bit expected. bit 17 */
    kLPUART_ParityErrorFlag = (LPUART_STAT_PF_MASK), /*!< If parity enabled, sets upon parity error detection. bit 16 */
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
    kLPUART_LinBreakFlag = (LPUART_STAT_LBKDIF_MASK), /*!< LIN break detect interrupt flag, sets when LIN break
                                                         char detected and LIN circuit enabled. bit 31 */
#endif
    kLPUART_RxActiveEdgeFlag = (LPUART_STAT_RXEDGIF_MASK), /*!< Receive pin active edge interrupt flag, sets when active
                                                              edge detected. bit 30 */
    kLPUART_RxActiveFlag =
        (LPUART_STAT_RAF_MASK), /*!< Receiver Active Flag (RAF), sets at beginning of valid start. bit 24 */
#if defined(FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING) && FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING
    kLPUART_DataMatch1Flag =
        LPUART_STAT_MA1F_MASK, /*!< The next character to be read from LPUART_DATA matches MA1. bit 15 */
    kLPUART_DataMatch2Flag =
        LPUART_STAT_MA2F_MASK, /*!< The next character to be read from LPUART_DATA matches MA2. bit 14 */
#endif
#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
    kLPUART_TxFifoEmptyFlag =
        (LPUART_FIFO_TXEMPT_MASK >> 16), /*!< TXEMPT bit, sets if transmit buffer is empty. bit 7 */
    kLPUART_RxFifoEmptyFlag =
        (LPUART_FIFO_RXEMPT_MASK >> 16), /*!< RXEMPT bit, sets if receive buffer is empty. bit 6 */
    kLPUART_TxFifoOverflowFlag =
        (LPUART_FIFO_TXOF_MASK >> 16), /*!< TXOF bit, sets if transmit buffer overflow occurred. bit 1 */
    kLPUART_RxFifoUnderflowFlag =
        (LPUART_FIFO_RXUF_MASK >> 16), /*!< RXUF bit, sets if receive buffer underflow occurred. bit 0 */
#endif

    kLPUART_AllClearFlags = kLPUART_RxActiveEdgeFlag | kLPUART_IdleLineFlag | kLPUART_RxOverrunFlag |
                            kLPUART_NoiseErrorFlag | kLPUART_FramingErrorFlag | kLPUART_ParityErrorFlag
#if defined(FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING) && FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING
                            | kLPUART_DataMatch1Flag | kLPUART_DataMatch2Flag
#endif
#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
                            | kLPUART_TxFifoOverflowFlag | kLPUART_RxFifoUnderflowFlag
#endif
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
                            | kLPUART_LinBreakFlag
#endif
    ,

    kLPUART_AllFlags =
        kLPUART_RxActiveEdgeFlag | kLPUART_IdleLineFlag | kLPUART_RxOverrunFlag | kLPUART_TxDataRegEmptyFlag |
        kLPUART_TransmissionCompleteFlag | kLPUART_RxDataRegFullFlag | kLPUART_RxActiveFlag | kLPUART_NoiseErrorFlag |
        kLPUART_FramingErrorFlag | kLPUART_ParityErrorFlag
#if defined(FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING) && FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING
        | kLPUART_DataMatch1Flag | kLPUART_DataMatch2Flag
#endif
#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
        | kLPUART_TxFifoOverflowFlag | kLPUART_RxFifoUnderflowFlag | kLPUART_TxFifoEmptyFlag | kLPUART_RxFifoEmptyFlag
#endif
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
        | kLPUART_LinBreakFlag
#endif
    ,
};

/*!
 * @brief LPUART interrupt configuration structure, default settings all disabled.
 *
 * This structure contains the settings for all LPUART interrupt configurations.
 */
enum _lpuart_interrupt_enable
{
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
    kLPUART_LinBreakInterruptEnable = (LPUART_BAUD_LBKDIE_MASK >> 8U), /*!< LIN break detect. bit 7 */
#endif
    kLPUART_RxActiveEdgeInterruptEnable         = (LPUART_BAUD_RXEDGIE_MASK >> 8U), /*!< Receive Active Edge. bit 6 */
    kLPUART_TxDataRegEmptyInterruptEnable       = (LPUART_CTRL_TIE_MASK),  /*!< Transmit data register empty. bit 23 */
    kLPUART_TransmissionCompleteInterruptEnable = (LPUART_CTRL_TCIE_MASK), /*!< Transmission complete. bit 22 */
    kLPUART_RxDataRegFullInterruptEnable        = (LPUART_CTRL_RIE_MASK),  /*!< Receiver data register full. bit 21 */
    kLPUART_IdleLineInterruptEnable             = (LPUART_CTRL_ILIE_MASK), /*!< Idle line. bit 20 */
    kLPUART_RxOverrunInterruptEnable            = (LPUART_CTRL_ORIE_MASK), /*!< Receiver Overrun. bit 27 */
    kLPUART_NoiseErrorInterruptEnable           = (LPUART_CTRL_NEIE_MASK), /*!< Noise error flag. bit 26 */
    kLPUART_FramingErrorInterruptEnable         = (LPUART_CTRL_FEIE_MASK), /*!< Framing error flag. bit 25 */
    kLPUART_ParityErrorInterruptEnable          = (LPUART_CTRL_PEIE_MASK), /*!< Parity error flag. bit 24 */
#if defined(FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING) && FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING
    kLPUART_Match1InterruptEnable = (LPUART_CTRL_MA1IE_MASK), /*!< Parity error flag. bit 15 */
    kLPUART_Match2InterruptEnable = (LPUART_CTRL_MA2E_MASK),  /*!< Parity error flag. bit 14 */
#endif
#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
    kLPUART_TxFifoOverflowInterruptEnable  = (LPUART_FIFO_TXOFE_MASK), /*!< Transmit FIFO Overflow. bit 9 */
    kLPUART_RxFifoUnderflowInterruptEnable = (LPUART_FIFO_RXUFE_MASK), /*!< Receive FIFO Underflow. bit 8 */
#endif

    kLPUART_AllInterruptEnable = kLPUART_RxActiveEdgeInterruptEnable | kLPUART_TxDataRegEmptyInterruptEnable |
                                 kLPUART_TransmissionCompleteInterruptEnable | kLPUART_RxDataRegFullInterruptEnable |
                                 kLPUART_IdleLineInterruptEnable | kLPUART_RxOverrunInterruptEnable |
                                 kLPUART_NoiseErrorInterruptEnable | kLPUART_FramingErrorInterruptEnable |
                                 kLPUART_ParityErrorInterruptEnable
#if defined(FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT) && FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT
                                 | kLPUART_LinBreakInterruptEnable
#endif
#if defined(FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING) && FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING
                                 | kLPUART_Match1InterruptEnable | kLPUART_Match2InterruptEnable
#endif
#if defined(FSL_FEATURE_LPUART_HAS_FIFO) && FSL_FEATURE_LPUART_HAS_FIFO
                                 | kLPUART_TxFifoOverflowInterruptEnable | kLPUART_RxFifoUnderflowInterruptEnable
#endif
    ,
};

/*! @brief LPUART driver source clock */
typedef enum _lpuart_source_clock
{
    kLPUART_SrcClkSys90Mhz      = 0,
    kLPUART_SrcClkUsb48Mhz      = 1,
    kLPUART_SrcClkXtal27_12Mhz  = 2,
    kLPUART_SrcClkXtal27_12Mhz1 = 3,
} lpuart_source_clock_t;

/*! @brief LPUART driver source clock */
typedef enum _lpuart_baudrate
{
    kLPUART_BaudRate9600   = 0, /*!< baudrate 9600 */
    kLPUART_BaudRate19200  = 1, /*!< baudrate 19200 */
    kLPUART_BaudRate38400  = 2, /*!< baudrate 38400 */
    kLPUART_BaudRate57600  = 3, /*!< baudrate 57600 */
    kLPUART_BaudRate115200 = 4, /*!< baudrate 115200 */
    kLPUART_BaudRate230400 = 5, /*!< baudrate 230400 */
    kLPUART_BaudRate460800 = 6, /*!< baudrate 460800 */
    kLPUART_BaudRate921600 = 7, /*!< baudrate 921600 */
} lpuart_baudrate_t;

/*! @brief LPUART driver baudrate configuration */
typedef struct
{
    uint32_t baudOsr;
    uint32_t baudSbr;
} lpuart_baud_t;

/*! @brief lpuart callback pointer. */
typedef void (*lpuartCallBack)(uint8_t *data, uint32_t length, status_t status);

/*! @brief lpuart data transfer configurations. */
typedef struct
{
    uint8_t *data;
    uint32_t bufferSize;
    uint32_t length;
    lpuartCallBack callBack;
} lpuart_data_t;

/**
  \brief  Union type to access the LPUART control bit configurations.
 */
typedef union
{
    struct
    {
        /* clang-format off */
        /* Byte 0 settings */
        lpuart_baudrate_t BaudRate : 3; /** Byte 0, bit[2:0]: Baud rate selection:
                                            000 -> 9600,
                                            001 -> 19200,
                                            010 -> 38400,
                                            011 -> 57600,
                                            100 -> 115200,
                                            101 -> 230400,
                                            110 -> 460800,
                                            111 -> 921600 */
        uint32_t ParityEnable : 1; /** Byte 0, bit3: Parity Enable/Disable:
                                       0 -> Disable,
                                       1 -> Enable. */
        uint32_t ParityType : 1;   /** Byte 0, bit4: Parity Type:
                                       0 -> Even,
                                       1 -> Odd */
        uint32_t StopBits : 1;     /** Byte 0, bit5: Stop bits: Number of stop bits.
                                       0 -> 1 stop bit,
                                       1 -> 2 stop bits */
        uint32_t _reserved1 : 2;   /** Byte 0, bit[7:6]:    RFU */

        /* Byte 1 settings */
        uint32_t TXCTSE : 1;       /** Byte 1, bit[0] : TXCTSE :
                                       Transmitter clear-to-send enable, controls the operation of the transmitter.
                                       0-> CTS has no effect on the transmitter.
                                       1-> Enables clear-to-send operation.
                                       Transmitter checks the state of CTS each time
                                       it is ready to send a character. If CTS is asserted,
                                       the character is sent. If CTS is deasserted,
                                       remains in mark state and transmission is delayed until CTS is asserted.
                                       NOTE: Do not set both RXRTSE and TXRTSE */
        uint32_t TXRTSE : 1;       /** Byte 1, bit[1] : TXRTSE :
                                       Transmitter request-to-send enable. Controls RTS before and after a transmission.
                                       0-> Transmitter has no effect on RTS.
                                       1-> When a character is placed into an empty transmitter data buffer,
                                       RTS asserts one bit time before the start bit is transmitted.
                                       RTS deasserts one bit time after all characters are completely sent,
                                       including stop bit. */
        uint32_t TXRTSPOL : 1;     /** Byte 1, bit[2] : TXRTSPOL :
                                       Transmitter request-to-send polarity. Controls the polarity of
                                       the transmitter RTS. TXRTSPOL does not affect the polarity of the receiver RTS.
                                       RTS will remain negated in the active low state unless TXRTSE is set.
                                       0-> Transmitter RTS is active low.
                                       1-> Transmitter RTS is active high. */
        uint32_t RXRTSE : 1;       /** Byte 1, bit[3] : RXRTSE: Receiver request-to-send enable.
                                       Allows the RTS output to control the CTS input of the transmitting device
                                       to prevent receiver overrun.
                                       0-> Receiver has no effect on RTS.
                                       1-> RTS is deasserted if the receiver data register is full or
                                       a start bit has been detected that would cause receiver data reg to become full.
                                       RTS is asserted if the receiver data register is not full and has not detected
                                       a start bit that would cause the receiver data register to become full. */
        uint32_t TXCTSC : 1;       /** Byte 1, bit[4] : TXCTSC: Transmit CTS Configuration:
                                       configure if CTS state is checked at start of each character or
                                       only when the transmitter is idle.
                                       0-> CTS input is sampled at start of each character.
                                       1-> Sampled when the transmitter is idle. */
        uint32_t TXCTSSRC : 1;     /** Byte 1, bit[5] : TXCTSSRC: Transmit CTS Source:
                                       0-> CTS input is CTS_B pin.
                                       1-> CTS input is inverted Receiver Match result. */
        uint32_t RTSWATER : 2;     /** Byte 1, bit[7:6] : RTSWATER:
                                       Configures the assertion and negation of the RX RTS_B output. */

        /* Byte 2 settings */
        uint32_t TxWaterMark : 2; /** Byte 2, bit[1:0]: Transmit Watermark, when the number of datawords in the transmit
                                      FIFO/buffer is equal to or less than the TxWaterMark value, an interrupt or a DMA
                                      request is generated. */
        uint32_t RxWaterMark : 2; /** Byte 2, bit[3:2]: Receive Watermark, when the number of datawords in the receive
                                      FIFO/buffer is greater than the RxWaterMark value, an interrupt or a DMA request is
                                      generated. */
        /* clang-format on */
    } b;

    uint32_t dW; /** To use double word access */
} lpuart_config_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Initializes an LPUART instance with the user configuration structure and the peripheral clock.
 *
 * This function configures the LPUART module with user-defined settings, see the \ref lpuart_config_t.
 *
 * @param base LPUART peripheral base address.
 * @param lpuartConfig LPUART configuration pointer.
 * @param sourceClock LPUART source clock frequency.
 * @return kStatus_Success         LPUART initialize succeed
 */
status_t LPUART_Init(LPUART_Type *base, const lpuart_config_t *lpuartConfig, uint32_t sourceClock);

/*!
 * @brief Deinitializes a LPUART instance.
 *
 * This function waits for transmit to complete, disables TX and RX, and disables the LPUART clock.
 *
 * @param base LPUART peripheral base address.
 */
void LPUART_DeInit(LPUART_Type *base);

/*!
 * @brief Resets the LPUART using software.
 *
 * This function resets all internal logic and registers except the Global Register.
 * Remains set until cleared by software.
 *
 * @param base LPUART peripheral base address.
 */
static inline void LPUART_SoftwareReset(LPUART_Type *base)
{
    base->GLOBAL |= LPUART_GLOBAL_RST_MASK;
    base->GLOBAL &= ~LPUART_GLOBAL_RST_MASK;
}

/*!
 * @brief Enable Lpuart Receive operation in interrupt mode with callback registered.
 *
 * This function is non-blocking call, clears error flags, enables reception with FIFO enabled in half duplex mode.
 *
 * @param base LPUART peripheral base address.
 * @param data Pointer to memory to store received Lpuart data.
 * @param bufferSize Size of the Rx buffer Pointer. Data received beyond this size will lead to loss of data and
 * overflow error.
 * @param rxCallBack Pointer to callback function on completion/error during Lpuart communication.
 * @return kStatus_Success         LPUART receive succeed
 */
status_t LPUART_Receive(LPUART_Type *base, uint8_t *data, uint32_t bufferSize, lpuartCallBack rxCallBack);

/*!
 * @brief Perform Lpuart Transmit operation in interrupt mode with callback registered.
 *
 * This function is non-blocking call, clears error flags, enable FIFO, kisk start Transmit in half duplex mode.
 *
 * @param base LPUART peripheral base address.
 * @param data Pointer to memory to store received Lpuart data.
 * @param length Pointer to memory to store length of received Lpuart data.
 * @param txCallBack Pointer to callback function on completion/error during Lpuart communication.
 * @return kStatus_InvalidArgument    Parameter error
 * @return kStatus_Success            LPUART receive succeed
 */
status_t LPUART_Transmit(LPUART_Type *base, uint8_t *data, uint32_t length, lpuartCallBack txCallBack);

/*!
 * @brief Enable Lpuart Receive operation in polling mode.
 *
 * This function is blocking call, clears error flags, enables reception with FIFO enabled in half duplex mode.
 *
 * @param base LPUART peripheral base address.
 * @param data Pointer to memory to store received Lpuart data.
 * @param length Pointer to memory to store length of received Lpuart data.
 * @return kStatus_Success         LPUART receive succeed
 */
status_t LPUART_PollReceive(LPUART_Type *base, uint8_t *data, uint32_t *length);

/*!
 * @brief Enable Lpuart transmit operation in polling mode.
 *
 * This function is blocking call, clears error flags, enables transmission with FIFO enabled in half duplex mode.
 *
 * @param base LPUART peripheral base address.
 * @param data Pointer to memory to store received Lpuart data.
 * @param length Pointer to memory to store length of received Lpuart data.
 * @return kStatus_Success         LPUART transmit succeed
 */
status_t LPUART_PollTransmit(LPUART_Type *base, uint8_t *data, uint32_t length);

/*!
 * @brief Enables or disables the LPUART transmitter DMA request.
 *
 * This function enables or disables the transmit data register empty flag, STAT[TDRE], to generate DMA requests.
 *
 * @param base LPUART peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void LPUART_EnableTxGPDMA(LPUART_Type *base, bool enable)
{
    if (enable)
    {
        base->BAUD |= LPUART_BAUD_TDMAE_MASK;
    }
    else
    {
        base->BAUD &= ~LPUART_BAUD_TDMAE_MASK;
    }
}

/*!
 * @brief Enables or disables the LPUART receiver DMA.
 *
 * This function enables or disables the receiver data register full flag, STAT[RDRF], to generate DMA requests.
 *
 * @param base LPUART peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void LPUART_EnableRxGPDMA(LPUART_Type *base, bool enable)
{
    if (enable)
    {
        base->BAUD |= LPUART_BAUD_RDMAE_MASK;
    }
    else
    {
        base->BAUD &= ~LPUART_BAUD_RDMAE_MASK;
    }
}

/*!
 * @brief Enables or disables the LPUART transmitter.
 *
 * This function enables or disables the LPUART transmitter.
 *
 * @param base LPUART peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void LPUART_EnableTx(LPUART_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= LPUART_CTRL_TE_MASK;
    }
    else
    {
        base->CTRL &= ~LPUART_CTRL_TE_MASK;
    }
}

/*!
 * @brief Enables or disables the LPUART receiver.
 *
 * This function enables or disables the LPUART receiver.
 *
 * @param base LPUART peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void LPUART_EnableRx(LPUART_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= LPUART_CTRL_RE_MASK;
    }
    else
    {
        base->CTRL &= ~LPUART_CTRL_RE_MASK;
    }
}

/*!
 * @brief Clears LPUART TX interrupt flags.
 *
 * @param base LPUART peripheral base address.
 */
void LPUART_ClearTxFlagsInterrupts(LPUART_Type *base);

/*!
 * @brief Clears LPUART RX interrupt flags.
 *
 * @param base LPUART peripheral base address.
 */
void LPUART_ClearRxFlagsInterrupts(LPUART_Type *base);

/*!
 * @brief Gets the LPUART data register address.
 *
 * This function returns the LPUART data register address, which is mainly used by the GPDMA.
 *
 * @param base LPUART peripheral base address.
 * @return LPUART data register addresses which are used both by the transmitter and receiver.
 */
static inline uint32_t LPUART_GetDataRegisterAddress(LPUART_Type *base)
{
    return (uint32_t) & (base->DATA);
}

/*!
 * @brief Enables LPUART interrupts according to a provided mask.
 *
 * This function enables the LPUART interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See the @ref _lpuart_interrupt_enable.
 *
 * @param base LPUART peripheral base address.
 * @param mask The interrupts to enable. Logical OR of @ref _lpuart_interrupt_enable.
 */
void LPUART_EnableInterrupts(LPUART_Type *base, uint32_t mask);

/*!
 * @brief Disables  LPUART interrupts according to a provided mask.
 *
 * This function disables the LPUART interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See @ref _lpuart_interrupt_enable.
 *
 * @param base LPUART peripheral base address.
 * @param mask The interrupts to disable. Logical OR of @ref _lpuart_interrupt_enable.
 */
void LPUART_DisableInterrupts(LPUART_Type *base, uint32_t mask);

/*!
 * @brief Gets LPUART status flags.
 *
 * This function gets all LPUART status flags. The flags are returned as the logical
 * OR value of the enumerators @ref _lpuart_flags. To check for a specific status,
 * compare the return value with enumerators in the @ref _lpuart_flags.
 *
 * @param base LPUART peripheral base address.
 * @return LPUART status flags which are ORed by the enumerators in the _lpuart_flags.
 */
uint32_t LPUART_GetStatusFlags(LPUART_Type *base);

/*!
 * @brief Register the RX callback.
 *
 * This function can be used to monitor the error status during DMA transfer, note that
 * in this case, the callback parameter data and length are invalid.
 *
 * @param base LPUART peripheral base address.
 * @param rxCallBack Callback to register.
 * @retval kStatus_Success Register succeed.
 * @retval kStatus_InvalidArgument Invalid parameter.
 */
status_t LPUART_RegisterRXCallBack(LPUART_Type *base, lpuartCallBack rxCallBack);

/*!
 * @brief Register the TX callback.
 *
 * This function can be used to monitor the error status during DMA transfer.
 *
 * @param base LPUART peripheral base address.
 * @param txCallBack Callback to register.
 * @retval kStatus_Success Register succeed.
 * @retval kStatus_InvalidArgument Invalid parameter.
 */
status_t LPUART_RegisterTXCallBack(LPUART_Type *base, lpuartCallBack txCallBack);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_LPUART_H_ */
