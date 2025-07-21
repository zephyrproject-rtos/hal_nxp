/*
 * Copyright 2024 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_IPMQ_H
#define _FSL_IPMQ_H

#include "fsl_common.h"
#include "fsl_mu.h"

/*!
 * @addtogroup ipmq
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief ipmq driver version 2.0.0 */
#define FSL_IPMQ_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define IPMQ_MSG_HEADER_SYNC_CODE  (0x5AU)
#define IPMQ_MSG_PHY_CHANNEL_COUNT (MU_TR_COUNT)

#define IPMQ_USELESS_VALUE (0x5A5A5A5AUL)

/*!
 * @brief Defines the enumeration type for IPMQ return values
 *
 * @details This enumeration type defines various return values for IPMQ message queue operations,
 * indicating the status of these operations.
 */
typedef enum _ipmq_ret_value
{
    kIPMQ_Ret_Error = 0U,              /*!< Operation error */
    kIPMQ_Ret_ReceiveUnkownMsg,        /*!< Received unknown message */
    kIPMQ_Ret_ReceiveOpcodeMismatch,   /*!< Received a message with mismatched opcode */
    kIPMQ_Ret_ReceiveUserDataMismatch, /*!< Received a message with mismatched user data */
    kIPMQ_Ret_ReceiveAck,              /*!< Successfully received an acknowledgement message */
    kIPMQ_Ret_ReceiveNACK,             /*!< Successfully received a negative acknowledgement message */
} ipmq_ret_value_t;

/*!
 * @brief Defines an enumeration for IPMQ message types
 *
 * @details This enumeration defines various message types within the message queue,
 * used to distinguish different categories of messages.
 */
typedef enum _ipmq_msg_type
{
    kIPMQ_MsgType_Message = 0U, /*!< Regular message type */
    kIPMQ_MsgType_ACK,          /*!< Acknowledgement message type */
    kIPMQ_MsgType_NACK,         /*!< Negative acknowledgement message type */
    kIPMQ_MsgType_Reserved,     /*!< Reserved message type for future use */
} ipmq_msg_type_t;

/*!
 * @brief Enumeration of IPMQ Message Opcodes
 *
 * @details This enumeration lists the different message opcodes supported by the IPMQ messaging system,
 * which define the specific actions or operations to be performed on the target device.
 */
typedef enum _ipmq_msg_opcode
{
    kIPMQ_MsgOpcode_BootReason = 0U,              /*!< Opcode for querying the reason of boot */
    kIPMQ_MsgOpcode_DataLoad,                     /*!< Opcode for loading data */
    kIPMQ_MsgOpcode_AdvcEnable,                   /*!< Opcode to enable ADVC functionality */
    kIPMQ_MsgOpcode_RegisterWrite,                /*!< Opcode to write to a register */
    kIPMQ_MsgOpcode_RegisterRead,                 /*!< Opcode to read from a register */
    kIPMQ_MsgOpcode_GpioInit,                     /*!< Opcode to initialize GPIO */
    kIPMQ_MsgOpcode_GpioSet,                      /*!< Opcode to set GPIO state */
    kIPMQ_MsgOpcode_GpioGet,                      /*!< Opcode to get GPIO state */
    kIPMQ_MsgOpcode_GpioDeinit,                   /*!< Opcode to deinitialize GPIO */
    kIPMQ_MsgOpcode_UartInit,                     /*!< Opcode to initialize UART */
    kIPMQ_MsgOpcode_UartPinsSelect,               /*!< Opcode to select UART pins */
    kIPMQ_MsgOpcode_UartRbInit,                   /*!< Opcode to initialize UART ring buffer */
    kIPMQ_MsgOpcode_UartRead,                     /*!< Opcode to read from UART */
    kIPMQ_MsgOpcode_UartRbDeinit,                 /*!< Opcode to deinitialize UART ring buffer */
    kIPMQ_MsgOpcode_UartDeinit,                   /*!< Opcode to deinitialize UART */
    kIPMQ_MsgOpcode_I2cPinsSelect,                /*!< Opcode to select I2C pins */
    kIPMQ_MsgOpcode_I2cMasterInit,                /*!< Opcode to initialize I2C master */
    kIPMQ_MsgOpcode_I2cMasterCreatehandle,        /*!< Opcode to create an I2C master handle */
    kIPMQ_MsgOpcode_I2cMasterTransfernonblocking, /*!< Opcode for non-blocking I2C master transfer */
    kIPMQ_MsgOpcode_I2cMasterDeinit,              /*!< Opcode to deinitialize I2C master */
    kIPMQ_MsgOpcode_I2cSlaveInit,                 /*!< Opcode to initialize I2C slave */
    kIPMQ_MsgOpcode_I2cSlaveCreatehandle,         /*!< Opcode to create an I2C slave handle */
    kIPMQ_MsgOpcode_I2cSlaveTransfernonblocking,  /*!< Opcode for non-blocking I2C slave transfer */
    kIPMQ_MsgOpcode_I2cRead,                      /*!< Opcode to read from I2C */
    kIPMQ_MsgOpcode_I2cSlaveDeinit,               /*!< Opcode to deinitialize I2C slave */
    kIPMQ_MsgOpcode_Ping,                         /*!< Opcode for ping operation */
    kIPMQ_MsgOpcode_ApiDeinit,                    /*!< Opcode to deinitialize API */
    kIPMQ_MsgOpcode_RegisterReadModifyWrite,      /*!< Opcode for reading, modifying, and writing to a register */
    kIPMQ_MsgOpcode_RtcIsAlive,                   /*!< Opcode to check if RTC is alive */
    kIPMQ_MsgOpcode_RtcSetAlarm,                  /*!< Opcode to set RTC alarm */
    kIPMQ_MsgOpcode_RtcClearAlarm,                /*!< Opcode to clear RTC alarm */
    kIPMQ_MsgOpcode_RtcGetCounter,                /*!< Opcode to get RTC counter value */
    kIPMQ_MsgOpcode_RtcLiveDetectorEnable,        /*!< Opcode to enable RTC live detector */
    kIPMQ_MsgOpcode_RtcAnalogDone,                /*!< Opcode for RTC analog done event */
    kIPMQ_MsgOpcode_SecuritySet,                  /*!< Opcode to set security settings */
    kIPMQ_MsgOpcode_ComparatorInit,               /*!< Opcode to initialize comparator */
    kIPMQ_MsgOpcode_ComparatorDeinit,             /*!< Opcode to deinitialize comparator */
    kIPMQ_MsgOpcode_ComparatorInterruptEn,        /*!< Opcode to enable comparator interrupt */
    kIPMQ_MsgOpcode_MemoryRead,                   /*!< Opcode to read memory */
    kIPMQ_MsgOpcode_MemoryWrite,                  /*!< Opcode to write to memory */
    kIPMQ_MsgOpcode_MemoryLock,                   /*!< Opcode to lock memory */
    kIPMQ_MsgOpcode_DebugEn,                      /*!< Opcode to enable debug mode */
    kIPMQ_MsgOpcode_AdvcEn,                       /*!< Opcode to enable ADV feature */
    kIPMQ_MsgOpcode_AdvcPreVoltageReqest,         /*!< Opcode for ADV pre-voltage request */
    kIPMQ_MsgOpcode_AdvcPostChangeFrequencyVoltageRequest, /*!< Opcode for ADV post-change frequency voltage request */
    kIPMQ_MsgOpcode_UpdateTemperature,                     /*!< Opcode to update temperature */
    kIPMQ_MsgOpcode_DeepPowerDown,                         /*!< Opcode to enter deep power down mode */
    kIPMQ_MsgOpcode_DeepPowerDownAbort,                    /*!< Opcode to abort deep power down mode */
    kIPMQ_MsgOpcode_RomDone,                               /*!< Opcode for ROM done event */
    kIPMQ_MsgOpcode_UartMode,                              /*!< Opcode to configure UART mode */
    kIPMQ_MsgOpcode_LogReset,                              /*!< Opcode to reset logs */
    kIPMQ_MsgOpcode_LogDump,                               /*!< Opcode to dump logs */
    kIPMQ_MsgOpcode_WakeupSource,                          /*!< Opcode related to wakeup source */
    kIPMQ_MsgOpcode_CommandsStub,                          /*!< Opcode for commands stub */
    kIPMQ_MsgOpcode_UartWrite,                             /*!< Opcode to write to UART */
} ipmq_msg_opcode_t;

/*!
 * @brief Enumeration of IPMQ General Purpose Interrupts
 *
 * @details This enumeration defines the general-purpose interrupts used in the IPMQ (Inter-Process Messaging Queue).
 * These interrupts are triggered when specific events occur within the AON domain.
 */
typedef enum _ipmq_msg_general_purpose_interrupt
{
    kIPMQ_MsgGpi_NewMsg = (uint32_t)kMU_GeneralPurposeInterrupt0, /*!< Interrupt for new message arrival */
    kIPMQ_MsgGpi_Error  = (uint32_t)kMU_GeneralPurposeInterrupt1, /*!< Interrupt for error occurrence */

    /*! @todo Pending updates according to the AON SW specification */
} ipmq_msg_general_purpose_interrupt_t;

#define IPMQ_MSG_GPI_COUNT (20U)

/*! @brief Structure definition for IPMQ Interrupt Callbacks
 *
 * @details This structure holds function pointers for callback functions to be invoked when specific IPMQ
 * interrupt events occur.
 *
 * - `error()`: A pointer to a function that will be called when an error interrupt occurs within the AON domain.
 */
typedef struct _ipmq_interrupt_cb
{
    void (*error)(void); /*!< Callback function for error interrupts */

    /* @todo Depend on AON info */
} ipmq_interrupt_cb_t;

/*!
 * @brief IP Message Queue Configuration Structure.
 *
 * @details This structure is used to configure the behavior and parameters for the inter-processor message queue.
 */
typedef struct _ipmq_config
{
    bool receiveByPolling;        /*!< Whether to receive messages through polling,
                                     if set as \b false the #kIPMQ_MsgGpi_NewMsg will be enabled,
                                     if set as \b true the code will polling the MU general purpose status. */
    bool enableErrorInterrupt;    /*!< Whether to enable/disable error interrupts, if enabled please note as
                                     set error callback function in #ptrCb. */
    bool recoveryQueueBeforeInit; /*!< Whether to recover the message queue before initialization.
                                       This option is used when an executable file is loaded directly into RAM,
                                       in which case the RAM executable resets local pointers while the AON ROM
                                       remains unaware. Set this to \b true to enable recovery. */
    uint32_t coreClock_Hz;        /*!< The core clock frequency required to recover the queue before
                                     initialization, if #recoveryQueueBeforeInit is set as false, this member
                                     will not be used. */
    ipmq_interrupt_cb_t *ptrCb;   /*!< Pointer to the interrupt callback functions. */
} ipmq_config_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* IPMQ interrupt callback structure. */
extern ipmq_interrupt_cb_t g_ipmCabllbacks;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and Deinitialization
 * @{
 */

/*!
 * @brief Initialize inter-processor message queue.
 *
 * @note Once initalized, please do not invoke this API repeatedly.
 * @note If \b recoveryQueueBeforeInit is set as \b true, this function execution might involve a considerable duration
 * due to the presence of an inlined delay function.
 *
 * @param[in] ptrConfig Pointer to @ref ipmq_config_t, used to set basic configuration of Message queue.
 *
 */
void IPMQ_Init(const ipmq_config_t *ptrConfig);

/*!
 * @brief De-initialize inter-processor message queue.
 *
 * @note This function should be invoked only after the IPMQ has been successfully initialized.
 */
void IPMQ_Deinit(void);

/*!
 * @brief Establish synchronization between the CM33 and AON domains through the recovery message queue mechanism.
 *
 * @details Used when an executable file is loaded directly into RAM,in which case the RAM executable resets local
 * pointers while the AON ROM remains unaware
 *
 * @note Please note that this function execution might involve a considerable duration due to the presence of
 * an inlined delay function.
 *
 * @param[in] coreClock_Hz The core clock frequency to delay servial micro seconds.
 */
void IPMQ_RecoveryQueue(uint32_t coreClock_Hz);

/*! @} */

/*!
 * @name General Purpose Interrupt Control
 * @{
 */

/*!
 * @brief Enable message general purpose interrupt.
 *
 * @param[in] mask The mask of interrupts to enable, should be the OR'ed
 *          value of @ref ipmq_msg_general_purpose_interrupt_t.
 */
void IPMQ_EnableMsgGeneralPurposeInterrupts(uint32_t mask);

/*!
 * @brief Disable message general purpose interrupt.
 *
 * @param[in] mask The mask of interrupts to disable, should be the OR'ed
 *          value of @ref ipmq_msg_general_purpose_interrupt_t.
 */
void IPMQ_DisableMsgGeneralPurposeInterrupts(uint32_t mask);

/*! @} */

/*!
 * @name Message Transfer
 * @{
 */

/*!
 * @brief Send message to AON with payload from single memory location.
 *
 * @param[in] opcode Message opcode, please refer to @ref ipmq_msg_opcode_t.
 * @param[in] userData User data send with the message, return with the ACK/NACK feedback, can be used by application
 *                       to match feedback to the message.
 * @param[in] payloadSize Size of payload to send.
 * @param[in] ptrPayload Pointer to the buffer of payload to send.
 */
void IPMQ_SendMessage(ipmq_msg_opcode_t opcode, uint8_t userData, uint8_t payloadSize, uint32_t *ptrPayload);

/*!
 * @brief Send message to AON with two different payload from different memory location, for example the first payload
 * may from RAM, and the second payload may from flash.
 *
 * @param[in] opcode Message opcode, please refer to @ref ipmq_msg_opcode_t.
 * @param[in] userData User data send with the message, return with the ACK/NACK feedback, can be used by application
 *                       to match feedback to the message.
 * @param[in] payload1Size Size of first payload to send.
 * @param[in] ptr1stPayload Pointer to the buffer of the first payload to send.
 * @param[in] payload2Size Size of second payload to send.
 * @param[in] ptr2ndPayload Pointer to the buffer of the second payload to send.
 */
void IPMQ_SendMessage2Payload(ipmq_msg_opcode_t opcode,
                              uint8_t userData,
                              uint8_t payload1Size,
                              uint32_t *ptr1stPayload,
                              uint8_t payload2Size,
                              uint32_t *ptr2ndPayload);

/*!
 * @brief Block receiving message until error detected or message finished.
 *
 * @note In case the return value of this function is anything other than #kIPMQ_Ret_ReceiveAck,
 * it is recommended for the user to examine the sent message according to the reported error and
 * resend the message accordingly
 *
 * @param[in] opcode Message opcode, please refer to @ref ipmq_msg_opcode_t.
 * @param[in] userData User data send with the message, return with the ACK/NACK feedback, can be used by application
 *                       to match feedback to the message.
 * @param[out] ptrResponsePayload Pointer to the buffer to store response message's payload.
 * @param[out] ptrResponsePayloadSize Pointer to the variable to store the size of response message's payload.
 *
 * @retval kIPMQ_Ret_ReceiveUnkownMsg  An unknown message was received
 * @retval kIPMQ_Ret_ReceiveOpcodeMismatch The received message does not match the expected message header
 * @retval kIPMQ_Ret_ReceiveUserDataMismatch The received user data does not match the input value.
 * @retval kIPMQ_Ret_ReceiveAck The message was received successfully and an acknowledgment (ACK) is returned
 * @retval kIPMQ_Ret_ReceiveNACK The message was received but there was a failure,
 *          a negative acknowledgment (NACK) is returned, and the NACK reason may contain in payload.
 */
ipmq_ret_value_t IPMQ_ReceiveMessage(ipmq_msg_opcode_t opcode,
                                     uint8_t userData,
                                     uint32_t *ptrResponsePayload,
                                     uint8_t *ptrResponsePayloadSize);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* _FSL_IPMQ_H */
