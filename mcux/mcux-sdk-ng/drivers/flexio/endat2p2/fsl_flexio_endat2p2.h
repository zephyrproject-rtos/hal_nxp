/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FLEXIO_ENDAT2P2_H_
#define FSL_FLEXIO_ENDAT2P2_H_

#include "fsl_common.h"
#include "fsl_flexio.h"

/*!
 * @addtogroup flexio_endat2p2
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief FlexIO Endat2.2 driver version 1.0.0. */
#define FSL_FLEXIO_CAMERA_EDMA_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*! @brief Define the Shifters and Timer for RX.*/
#define SHIFTER_RX_INDEX             4
#define SHIFTER_RX_NUM               2
#define TIMER_RX_ACTIVE_INDEX        0
#define TIMER_RX_INDEX               1

/*! @brief Define the Timer index for the transaction timer.*/
#define TIMER_TRANS_INDEX            3

/*! @brief Define the Shifters and Timer for CLK.*/
#define SHIFTER_CLK_INDEX            0
#define SHIFTER_CLK_NUM              4
#define TIMER_CLK_INDEX              4

/*! @brief Define the Shifters and Timer for TX.*/
#define SHIFTER_TX_INDEX            7
#define SHIFTER_TX_NUM              1
#define TIMER_TX_INDEX              2

/*! @brief Define the Timer index for DIR.*/
#define TIMER_DIR_INDEX             5

/*! @brief Define the lenght for the bisic endat2 frames.*/
#define FLEXIO_ENDAT2_CMD_LEN           6u
#define FLEXIO_ENDAT2_CMD_CLK_LEN       (1u + FLEXIO_ENDAT2_CMD_LEN + 1)
#define FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB (32u - FLEXIO_ENDAT2_CMD_LEN)
#define FLEXIO_ENDAT2_CRC_LEN           5u
#define FLEXIO_ENDAT2_CMD_NUM           2u
#define FLEXIO_ENDAT2_RECV_EX_LEN        (FLEXIO_ENDAT2_CRC_LEN + 2) // CRC:5bits + start Bit + Error Bit

/*! @brief Define the common endat2 commands.*/
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVAL             (0x7 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_SELECTMEM                 (0x0E << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCRECVPARA               (0x1C << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPARA               (0x23 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCRECVRST                (0x2A << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDTESTVAL            (0x15 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCRECVTESTCMD            (0x31 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVALADDDAT       (0x38 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVALRECVSELMEM   (0x09 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVALRECVPARA     (0x1B << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVALSENDPARA     (0x24 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVALRECVERRRST   (0x2D << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCSENDPOSVALRECVTESTCMD  (0x36 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)
#define FLEXIO_ENDAT2_CMD_ENCRECVCOMMCMD            (0x12 << FLEXIO_ENDAT2_CMD_SHIFT_FOR_MSB)

/*! @brief Define the array index of endat2 commands.*/
typedef enum
{
    kFlexIO_ENDAT2_CmdIdxEncSendPosVal = 0u,
    kFlexIO_ENDAT2_CmdIdxEncRecvRst,
} flexio_endat2_cmd_index_t;

/*! @brief Define type of endat2 command cofiguration.*/
typedef struct _flexio_endat2_cmd_cfg_t
{
    uint32_t cmd_val;
    uint32_t timer_val;
} flexio_endat2_cmd_cfg_t;

/*! @brief Define type of the trigger source for endat2 transaction.*/
typedef enum _flexio_endat2_tx_trigger
{
    kFlexioEndat2_txTriggerHw = 0U,
    kFlexioEndat2_txTriggerSw
} flexio_endat2_tx_trigger_t;

/*! @brief Define FlexIO ENDAT2 access structure typedef. */
typedef struct _flexio_endat2_type
{
    FLEXIO_Type *flexio;       /*!< FlexIO base pointer. */
    uint8_t TxdPinIndex;       /*!< Pin select for data output. Initialized in the application layer. */
    uint8_t RxdPinIndex;       /*!< Pin select for data input. Initialized in the application layer. */
    uint8_t ClkPinIndex;       /*!< Pin select for clock. Initialized in the application layer. */
    uint8_t DirPinIndex;       /*!< Pin select for direction. Initialized in the application layer. */

    uint32_t preambleNum;

    uint16_t mtLen; /* Multi-Turn bit length. Initialized in the application layer. */
    uint16_t stLen; /* Single-Turn bit length. Initialized in the application layer. */

    flexio_endat2_tx_trigger_t txTrigger; /*!< FlexIO TX timer trigger source. */
    uint8_t triggerInput;  /*external trigger n input. */
    flexio_endat2_cmd_cfg_t cmd_cfg[FLEXIO_ENDAT2_CMD_NUM];
    flexio_endat2_cmd_index_t current_cmd_idx;

    uint32_t rxdBuffer[2];        /*!< Raw data received from SL. */
    volatile bool rxdBufferReady; /*!< RXD buffer ready or not. */

    uint32_t mt; /* Multi-Turn value */
    uint32_t st; /* Single-Turn value */
    uint32_t recoveryTimeIII /* Endat2.2 Recovery time III. Initialized in the application layer.*/;
    uint8_t error1Bit;
    bool crcMatch;
} FLEXIO_ENDAT2_Type;

/*! @brief Define FlexIO ENDAT2 configuration structure. */
typedef struct _flexio_endat2_config
{
    bool enable;           /*!< Enable/disable FlexIO ENDAT2 after configuration. */
    bool enableInDoze;     /*!< Enable/disable FlexIO operation in doze mode. */
    bool enableInDebug;    /*!< Enable/disable FlexIO operation in debug mode. */
    bool enableFastAccess; /*!< Enable/disable fast access to FlexIO registers,
                           fast access requires the FlexIO clock to be at least
                           twice the frequency of the bus clock. */
    uint32_t baudRate_Bps; /*!< Baud rate in Bps. */
} flexio_endat2_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C"
{
#endif /*_cplusplus*/

/*!
 * @brief Configures the FlexIO with a FlexIO configuration.
*/
status_t FLEXIO_ENDAT2_Init(FLEXIO_ENDAT2_Type *base, const flexio_endat2_config_t *config, uint32_t srcClock_Hz);

/*!
 * @brief Clean the FlexIO configuration.
*/
void FLEXIO_ENDAT2_Deinit(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Get the defalut FlexIO configuration.
*/
void FLEXIO_ENDAT2_GetDefaultConfig(flexio_endat2_config_t *config);

/*!
 * @brief Process the Endat2 response, and get the position data.
*/
status_t FLEXIO_ENDAT2_DataProcess(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Read the position data once. The function is blocking until the response received.
*/
 status_t FLEXIO_ENDAT2_ReadBlocking(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Set the endat2.2 command. In SW trigger mode, a new transaction will be launched.
*/
 void FLEXIO_ENDAT2_WriteCmd(FLEXIO_ENDAT2_Type *base, flexio_endat2_cmd_index_t cmd_idx);

/*!
 * @brief Get Rx status.
 * @return non-zero: transcation has been completed.
 *         zero： transcation is not completed yet.
*/
uint32_t FLEXIO_ENDAT2_GetRxStatusFlags(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Get Rx Error status.
 * @return non-zero: Rx Error occurred.
 *         zero： No Rx Error occurred.
*/
uint32_t FLEXIO_ENDAT2_GetRxErrFlags(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Clean Rx status.
*/
void FLEXIO_ENDAT2_ClearRxStatusFlags(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Clean Rx Error status.
*/
void FLEXIO_ENDAT2_ClearRxErrorFlags(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Enable Rx receive IRQ.
*/
void FLEXIO_ENDAT2_EnableInterrupts(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Disable Rx receive IRQ.
*/
void FLEXIO_ENDAT2_DisableInterrupts(FLEXIO_ENDAT2_Type *base);

/*!
 * @brief Switch Flexio to other trigger mode.
*/
void FLEXIO_ENDAT2_SetTrigMode(FLEXIO_ENDAT2_Type *base, flexio_endat2_tx_trigger_t txTrigger);

/*!
 * @brief Check whether the buadrate is match with the current configeration.
*/
status_t FLEXIO_ENDAT2_FlexIO_BuadrateVerify(uint32_t srcClock_Hz, uint32_t baudRate);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/*! @} */

#endif /*_FSL_FLEXIO_ENDAT2_H_*/
