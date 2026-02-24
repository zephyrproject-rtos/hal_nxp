/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_FLEXIO_BISS_H_
#define FSL_FLEXIO_BISS_H_

#include "fsl_flexio.h"

/*!
 * @addtogroup flexio_biss
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief FlexIO BiSS driver version. */
#define FSL_FLEXIO_BISS_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/*! @brief Retry times for waiting flag. */
#ifndef BISS_RETRY_TIMES
#define BISS_RETRY_TIMES 0U
#endif

#define BISS_SHIFTER_NUM       6
#define BISS_TIMER_NUM         2
#define BISS_FRAME_BUFFER_NUM  2

#define BISS_FRAME_MASK(len)   ((1U << (len)) - 1)

/*! @brief FlexIO BiSS user modes. */
typedef enum _flexio_biss_user_modes
{
    kFLEXIO_BISS_USERMODE_ONESHOT  = 0U, /*!< User mode is oneshot */
    kFLEXIO_BISS_USERMODE_SYNC     = 1U, /*!< User mode is sync */
} flexio_biss_user_modes_t;

/*! @brief Define FlexIO BiSS status mask. */
enum _flexio_biss_status_flags
{
    kFLEXIO_BISS_RxDataRegFullFlag  = 1U, /*!< Receive buffer full flag. */
    kFLEXIO_BISS_RxOverRunFlag      = 2U, /*!< Receive buffer over run flag. */
};

/*! @brief The field flag of the BiSS frame */
typedef enum _flexio_biss_frame_field
{
    kFLEXIO_BISS_FIELD_HD  = 0x0U,    /*!< Clock ready flag */
    kFLEXIO_BISS_FIELD_MT  = 0x1U,    /*!< Data ready flag */
    kFLEXIO_BISS_FIELD_ST  = 0x2U,    /*!< Error flag */
    kFLEXIO_BISS_FIELD_CRC = 0x3U,    /*!< Clock ready flag */
    kFLEXIO_BISS_FIELD_CDM = 0x4U,    /*!< Data ready flag */
} flexio_biss_frame_field_t;

/*! @brief BiSS frame structure */
typedef struct _flexio_biss_frame
{
    uint8_t headBits;      /*!< Header length */
    uint8_t mtBits;        /*!< Multi-turn position data */
    uint8_t stBits;        /*!< Single-turn position data */
    uint8_t erWrBits;      /*!< Error and Warning bits */
    uint8_t crcBits;       /*!< CRC bit */
    uint8_t stopBits;      /*!< Stop bit (should be 0) */
    uint8_t cdmBits;       /*!< CDM bit */
    uint8_t dataBits;      /*!< The bits of the data field without crc */
    uint8_t totalBits;     /*!< Total number of bits without cdm */
    uint8_t wholeBits;     /*!< Total number of bits with cdm */
} flexio_biss_frame_t;

/*! @brief BiSS master type */
typedef struct _flexio_biss_master
{
    FLEXIO_Type *flexioBase;    /*!< FlexIO base pointer */
    flexio_biss_frame_t *frame;
    uint8_t clockDivider;
    uint8_t dataPin;            /*!< Data pin resource */
    uint8_t clockPin;           /*!< Clock pin resource */
    uint8_t shifterBaseIndex;
    uint8_t shifterCount;
    uint8_t timerBaseIndex;
    uint8_t timerCount;
    uint8_t triggerIn;          /*!< Trigger signal for sync mode. */
} FLEXIO_BISS_Type;

/*! @brief Define FlexIO BiSS user configuration structure. */
typedef struct _flexio_biss_config
{
    bool enableBiSS;          /*!< Enable/disable FlexIO BiSS */
    bool enableInDoze;        /*!< Enable/disable FlexIO operation in doze mode */
    bool enableInDebug;       /*!< Enable/disable FlexIO operation in debug mode */
    bool enableFastAccess;    /*!< Enable/disable fast access to FlexIO registers,
                                   fast access requires the FlexIO clock to be at least
                                   twice the frequency of the bus clock */
    uint32_t baudRate_bps;    /*!< Baud rate in bps. */
    flexio_biss_user_modes_t userMode;
} flexio_biss_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name FlexIO BiSS Clock.
 * @{
 */

/*!
 * @brief Shifters are used to emulate the BiSS clock
 *
 * @note After calling this function, the BiSS clock will be sent immediately in the
 * oneshot mode. In the sync mode, the shifter buffer will wait the external trigger.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param value The CDM field and clock.
 */
static inline void FLEXIO_BISS_GenClock(FLEXIO_BISS_Type *base, uint64_t value)
{
    base->flexioBase->SHIFTBUF[2] = 0xAAAAAAAA;
    base->flexioBase->SHIFTBUF[3] = 0xAAAAAAAA;
    base->flexioBase->SHIFTBUF[4] = (uint32_t)(value & 0x00000000FFFFFFFF);
    base->flexioBase->SHIFTBUF[5] = (uint32_t)(value >> 32);
}

/*!
 * @brief Calculates the number of the clock and the value of CDM
 *
 * @note The return value of this function is used to pass to the
 * FLEXIO_BISS_GenClock function.
 *
 * @param frame Pointer to the flexio_biss_frame_t structure.
 * @param cdmIsHigh The CDM field is high or low level.
 * @return An unsigned 64-bit value including the clock and the CDM
 */
uint64_t FLEXIO_BISS_CalClockValue(flexio_biss_frame_t *frame, bool cdmIsHigh);

/*! @} */

/*!
 * @name FlexIO BiSS initialization.
 * @{
 */

/*!
 * @brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO BiSS
 * hardware, and configures the FlexIO BiSS with FlexIO BiSS configuration.
 * The configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_BISS_GetDefaultConfig().
 *
 * Example
 * @code
 *    flexio_biss_frame_t frame_g;
 *    FLEXIO_BISS_Type base = {
 *      .flexioBase       = FLEXIO1,
 *      .frame            = &frame_g,
 *      .dataPin          = 0,
 *      .clockPin         = 2,
 *      .shifterBaseIndex = 0,
 *      .shifterCount     = BISS_SHIFTER_NUM,
 *      .timerBaseIndex   = 0,
 *      .timerCount       = BISS_TIMER_NUM
 *    };
 *    flexio_biss_config_t config = {
 *      .enableBiSS       = true,
 *      .enableInDoze     = false,
 *      .enableInDebug    = true,
 *      .enableFastAccess = false,
 *      .baudRate_bps     = 10000000,
 *      .userMode         = kFLEXIO_BISS_USERMODE_ONESHOT
 *    };
 *    FLEXIO_BISS_MasterInit(&base, &config, 80000000);
 * @endcode
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param masterConfig Pointer to the flexio_biss_config_t structure.
 * @param srcClock_Hz The FlexIO root clock frequency in Hz.
 * @retval kStatus_Success Configuration success.
 */
status_t FLEXIO_BISS_MasterInit(FLEXIO_BISS_Type *base, const flexio_biss_config_t *masterConfig, uint32_t srcClock_Hz);

/*!
 * @brief Updates the number of BiSS clocks to the FlexIO Timer register.
 *
 * note After the BiSS frame length has been updated, this function is called.
 * This function must be called after the FLEXIO_BISS_MasterInit function.
 *
 * @param base Pointer to FLEXIO_BISS_Type structure
 */
void FLEXIO_BISS_UpdateClockTimer(FLEXIO_BISS_Type *base);

/*!
 * @brief Updates the trigger mode for FlexIO BiSS receiving data.
 *
 * note After calling the FLEXIO_BISS_MasterInit function, this function is called.
 *
 * @param base Pointer to FLEXIO_BISS_Type structure
 * @param mode Oneshot or Sync(Other IP triggers) mode
 */
void FLEXIO_BISS_UpdateTriggerMode(FLEXIO_BISS_Type *base, flexio_biss_user_modes_t mode);

/*!
 * @brief Resets the FlexIO BiSS shifter and timer config.
 *
 * note After calling this API, call the FLEXIO_BISS_MasterInit to use the FlexIO BiSS module.
 *
 * @param base Pointer to FLEXIO_BISS_Type structure
 */
void FLEXIO_BISS_MasterDeinit(FLEXIO_BISS_Type *base);

/*!
 * @brief Gets the default configuration to configure the FlexIO BiSS. The
 * configuration can be used directly for calling the FLEXIO_BISS_MasterInit().
 * Example:
 * @code
 *    flexio_biss_config_t userConfig;
 *    FLEXIO_BISS_MasterGetDefaultConfig(&userConfig);
 * @endcode
 * param userConfig Pointer to the flexio_a_format_config_t structure.
 */
void FLEXIO_BISS_MasterGetDefaultConfig(flexio_biss_config_t *masterConfig);

/*! @} */

/*!
 * @name FlexIO BiSS Interrupts
 * @{
 */

/*!
 * @brief Enables the FlexIO BiSS interrupt.
 *
 * This function enables the FlexIO BiSS interrupt.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 */
void FLEXIO_BISS_EnableInterrupts(FLEXIO_BISS_Type *base);

/*!
 * @brief Disables the FlexIO BiSS interrupt.
 *
 * This function disables the FlexIO BiSS interrupt.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 */
void FLEXIO_BISS_DisableInterrupts(FLEXIO_BISS_Type *base);

/*! @} */

/*!
 * @name FlexIO BiSS Status
 * @{
 */

/*!
 * @brief Gets the FlexIO BiSS status flags.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @return FlexIO BiSS status flags.
 */
uint32_t FLEXIO_BISS_GetStatusFlags(FLEXIO_BISS_Type *base);

/*!
 * @brief Clears the FlexIO BiSS status flags.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param mask Status flag.
 *      The parameter can be any combination of the following values:
 *          arg kFLEXIO_BISS_RxDataRegFullFlag
 *          arg kFLEXIO_BISS_RxOverRunFlag
 */
void FLEXIO_BISS_ClearStatusFlags(FLEXIO_BISS_Type *base, uint32_t mask);

/*! @} */

/*!
 * @name FlexIO BiSS Operations
 * @{
 */

/*!
 * @brief Receives the buffer of one frame.
 *
 * note This function blocks using the polling method until one frame have been received.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of 32-bit buffer to be received.
 * @retval kStatus_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_BISS_ReadBlocking(FLEXIO_BISS_Type *base, uint32_t *rxData, uint8_t rxSize);

/*!
 * @brief Receives the buffer of one frame.
 *
 * note This function receives one frame in the nonblocking way.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of 32-bit buffer to be received.
 * @retval kStatus_Fail The length of the receive buffer is less than the minimum value.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_BISS_ReadNonBlocking(FLEXIO_BISS_Type *base, uint32_t *rxData, uint8_t rxSize);

/*! @} */

/*!
 * @name FlexIO BiSS Frame
 * @{
 */

/*!
 * @brief Updates the bit number of the corresponding field
 *
 * @param frame Pointer to the flexio_biss_frame_t structure.
 * @param field Specifies the BiSS field
 * @param bits Sets the new bit number to the corresponding field
 * @retval kStatus_Success Successfully updated the bit number
 * @retval kStatus_OutOfRange The update is failed
 */
status_t FLEXIO_BISS_UpdateFieldBit(flexio_biss_frame_t *frame, flexio_biss_frame_field_t field, uint8_t bits);

/*!
 * @brief Calculates the bit number of the header in one frame
 *
 * @param data The data receiced from the BiSS encoder
 * @return The bit number of the header in one frame
 */
uint8_t FLEXIO_BISS_CalFrameHeadLen(uint64_t *data);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* _FSL_FLEXIO_BISS_H_ */
