/*
 * Copyright 2019-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __ELEMU_DRIVER_H__
#define __ELEMU_DRIVER_H__

#include "fsl_common.h"
#include "fsl_device_registers.h"

#define MU_MSG_HEADER_SIZE (1U)

#define MESSAGING_TAG_COMMAND (0x17u)
#define MESSAGING_TAG_REPLY   (0x0Cu)
#define STATIC_CHECK_BITS     (0xD7u)

/*!
 * @addtogroup elemu
 * @{
 */
 
enum
{
    kStatus_ELEMU_AgumentOutOfRange =
        MAKE_STATUS(kStatusGroup_ELEMU, 0x1u), /*!< ELEMU status for out of range access. */
    kStatus_ELEMU_InvalidArgument =
        MAKE_STATUS(kStatusGroup_ELEMU, 0x2u), /*!< ELEMU status for invalid argument check. */
    kStatus_ELEMU_RequestTimeout = MAKE_STATUS(kStatusGroup_ELEMU, 0x3u), /*!< ELEMU status for timeout. */
    kStatus_ELEMU_Busy = MAKE_STATUS(kStatusGroup_ELEMU, 0x4u), /*!< ELEMU status for reservation by other core. */
};

typedef enum
{
    kStatus_ELEMU_Unknown       = 0x0u, /*!< Unexpected ELEMU ownership. */
    kStatus_ELEMU_LockedByMe    = 0x1u, /*!< ELEMU reserved for current core. */
    kStatus_ELEMU_LockedByOther = 0x2u, /*!< ELEMU reserved for other core. */
    kStatus_ELEMU_Free          = 0x3u, /*!< ELEMU not reserved. */
} elemu_ownership_status_t;

typedef struct mu_hdr
{
    uint8_t tag_sts;
    uint8_t check_bits;
    uint8_t size;
    uint8_t command;
} mu_hdr_t;

/*!
 * @brief Send one word of data to specified transmit register.
 *
 * This function waits until the transmit register is ready and writes one word of data.
 *
 * @param mu ELEMU peripheral base address
 * @param regid Transmit register index
 * @param data Pointer to data to be sent
 */
void ELEMU_mu_hal_send_data(ELEMU_Type *mu, uint8_t regid, uint32_t *data);

/*!
 * @brief Receive one word of data from specified receive register.
 *
 * This function waits until data is available in the receive register and reads it.
 *
 * @param mu ELEMU peripheral base address
 * @param regid Receive register index
 * @param data Pointer to store received data
 */
void ELEMU_mu_hal_receive_data(ELEMU_Type *mu, uint8_t regid, uint32_t *data);

/*!
 * @brief Wait for data availability and receive one word from specified register.
 *
 * @param mu ELEMU peripheral base address
 * @param regid Receive register index
 * @param data Pointer to store received data
 * @param wait Maximum wait iterations
 *
 * @return kStatus_Success if successful, kStatus_ELEMU_RequestTimeout if timeout
 */
status_t ELEMU_mu_hal_receive_data_wait(ELEMU_Type *mu, uint8_t regid, uint32_t *data, uint32_t wait);
/*!
 * @brief Read a message from ELEMU receive registers.
 *
 * This function reads a message from ELEMU including header and payload.
 *
 * @param mu ELEMU peripheral base address
 * @param buf Pointer to buffer to store message
 * @param size Pointer to size variable
 * @param read_header Flag to indicate if header should be read
 *
 * @return kStatus_Success if successful, kStatus_ELEMU_InvalidArgument if buf or size is NULL
 */
status_t ELEMU_mu_read_message(ELEMU_Type *mu, uint32_t *buf, uint8_t *size, uint8_t read_header);
/*!
 * @brief Wait and read data from ELEMU receive registers.
 *
 * This function waits for data availability and reads the specified number of words.
 *
 * @param mu ELEMU peripheral base address
 * @param buf Pointer to buffer to store data
 * @param size Pointer to size variable
 * @param wait Maximum wait iterations
 *
 * @return kStatus_Success if successful, kStatus_ELEMU_InvalidArgument if buf or size is NULL,
 *         kStatus_ELEMU_RequestTimeout if timeout
 */
status_t ELEMU_mu_read_data_wait(ELEMU_Type *mu, uint32_t buf[], uint8_t *size, uint32_t wait);

/*!
 * @brief Send a message to ELEMU using transmit registers.
 *
 * This function sends a message buffer to ELEMU by writing words to transmit registers.
 *
 * @param mu ELEMU peripheral base address
 * @param buf Pointer to message buffer
 * @param wordCount Number of words to send
 *
 * @return kStatus_Success if successful, kStatus_ELEMU_InvalidArgument if buf is NULL,
 *         kStatus_ELEMU_AgumentOutOfRange if wordCount exceeds register count
 */
status_t ELEMU_mu_send_message(ELEMU_Type *mu, uint32_t buf[], size_t wordCount);
/*!
 * @brief Get response message from ELEMU.
 *
 * This function reads a response message from ELEMU using the read_message function.
 *
 * @param mu ELEMU peripheral base address
 * @param buf Pointer to buffer to store response
 * @param wordCount Expected number of words
 *
 * @return kStatus_Success if successful, kStatus_ELEMU_InvalidArgument if buf is NULL,
 *         kStatus_ELEMU_AgumentOutOfRange if wordCount exceeds register count
 */
status_t ELEMU_mu_get_response(ELEMU_Type *mu, uint32_t *buf, size_t wordCount);
/*!
 * @brief Wait for data availability and read from ELEMU.
 *
 * This function waits for data and reads the specified number of words.
 *
 * @param mu ELEMU peripheral base address
 * @param buf Pointer to buffer to store data
 * @param wordCount Expected number of words
 * @param wait Maximum wait iterations
 *
 * @return kStatus_Success if successful, kStatus_ELEMU_InvalidArgument if buf is NULL,
 *         kStatus_ELEMU_AgumentOutOfRange if wordCount exceeds register count
 */
status_t ELEMU_mu_wait_for_data(ELEMU_Type *mu, uint32_t *buf, size_t wordCount, uint32_t wait);

/*!
 * @brief Wait until ELEMU is ready for communication.
 *
 * This function checks the status register and waits until ELEMU is ready.
 *
 * @param mu ELEMU peripheral base address
 * @param wait Maximum wait iterations
 *
 * @return kStatus_Success if ready, kStatus_ELEMU_RequestTimeout if timeout
 */
status_t ELEMU_mu_wait_for_ready(ELEMU_Type *mu, uint32_t wait);

#if (defined(FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER) && FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER)
/*!
 * @brief Get current ownership status of ELEMU.
 *
 * @param mu ELEMU peripheral base address
 *
 * @return Ownership status enum value
 */
elemu_ownership_status_t ELEMU_mu_get_ownership_status(ELEMU_Type *mu);

/*!
 * @brief Attempt to acquire ownership of ELEMU.
 *
 * This function tries to acquire ownership of ELEMU using the semaphore register.
 *
 * @param mu ELEMU peripheral base address
 *
 * @return kStatus_Success if acquired, kStatus_ELEMU_Busy if locked by other,
 *         kStatus_Fail if acquisition failed
 */
status_t ELEMU_mu_get_ownership(ELEMU_Type *mu);

/*!
 * @brief Release ownership of ELEMU.
 *
 * This function releases ownership of ELEMU using the semaphore release register.
 *
 * @param mu ELEMU peripheral base address
 *
 * @return kStatus_Success if released, kStatus_ELEMU_Busy if locked by other,
 *         kStatus_Fail if release failed
 */
status_t ELEMU_mu_release_ownership(ELEMU_Type *mu);

/*!
 * @brief Release ownership of ELEMU.
 *
 * This function releases ownership of ELEMU using the semaphore release register.
 *
 * @param mu ELEMU peripheral base address
 *
 * @return kStatus_Success if released, kStatus_ELEMU_Busy if locked by other,
 *         kStatus_Fail if release failed
 */
status_t ELEMU_mu_release_ownership_force(ELEMU_Type *mu);
#endif /* FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER */

/*!
 * @brief Initialize ELEMU module.
 *
 * This function does nothing. ELEMU is initialized after leaving ROM.
 *
 * @param mu ELEMU peripheral base address
 */
void ELEMU_mu_init(ELEMU_Type *mu);

/*!
 * @brief Initialize low-power wakeup path for ELEMU.
 *
 * This function enables clocks and waits for ELEMU startup sequence.
 *
 * @param mu ELEMU peripheral base address
 *
 * @return kStatus_Success if successful, kStatus_Fail otherwise
 */
status_t ELEMU_LP_WakeupPathInit(ELEMU_Type *mu);

#if (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
/*!
 * @brief Load firmware into ELE.
 *
 * This function uploads firmware to ELEMU using secure tunnel.
 *
 * @param mu ELEMU peripheral base address
 * @param image Pointer to firmware image data
 *
 * @return kStatus_Success if successful, kStatus_Fail otherwise
 */
status_t ELEMU_loadFw(ELEMU_Type *mu, uint32_t image[]);
#endif /* ELEMU_HAS_LOADABLE_FW */

/** @}*/

#endif /* __ELEMU_DRIVER_H__ */
