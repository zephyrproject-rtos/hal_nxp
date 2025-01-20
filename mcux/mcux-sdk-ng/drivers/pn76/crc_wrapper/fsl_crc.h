/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CRC_H_
#define FSL_CRC_H_

#include "fsl_common.h"
#include "PN76_CRC.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_crc_wrapper"
#endif

/*!
 * @addtogroup crc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief CRC driver version 2.0.0. */
#define FSL_CRC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))

/*! @brief CRC status */
enum
{
    kStatus_CRC_ParameterError = PN76_STATUS_PARAMETER_ERROR, /**< Value to be returned in case of wrong parameter. */
    kStatus_CRC_InternalError  = PN76_STATUS_INTERNAL_ERROR,  /**< Value to be returned in case of an internal error or
                                                            an error which is not specified in more detail. */
    kStatus_CRC_Busy = PN76_STATUS_BUSY,                      /**< Device or resource busy. */
};

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Enables the CRC peripheral module.
 */
static inline void CRC_Init(void)
{
    PN76_Sys_Hal_CRC_Init();
}

/*!
 * @brief Disables the CRC peripheral module.
 */
static inline void CRC_DeInit(void)
{
    PN76_Sys_Hal_Crc_DeInit();
}

/*!
 * @brief This function calculate CRC32 or CRC16 on selected data area.
 *
 * This function is protected by semaphore.
 * Functions that are protected by semaphores must not be called in interrupts.
 * CRC will always calculate MSB first, this will be set internally
 *
 * @param crcPreload : Value of pre-load DATA for CRC calculation
 * @param buffer :Pointer to data message structure on which CRC will be calculated.
 * @param dataLength : Length of \a buffer in bytes Note - Len must match with Buffer size.
 * @param crcValue : Pointer on calculated CRC value
 * @retval kStatus_Success Operation Successful.
 * @retval kStatus_CRC_ParameterError Unknown EEPROM address or address pointed by \p pDataToWrite is incorrect.
 * @retval kStatus_CRC_Busy
 * @retval kStatus_CRC_InternalError
 */
static inline status_t CRC_CalculateCrc(uint32_t crcPreload, uint8_t *buffer, uint32_t dataLength, uint32_t *crcValue)
{
    return (status_t)PN76_Sys_Hal_CRC_CalculateCrc32(crcPreload, buffer, dataLength, crcValue);
}

/*!
 * @brief This function check CRC16 calculation on buffer with calculated CRC value.
 * \note It is assumed that CRC16 result is part of the buffer (usually last two bytes, after data on which CRC is
 * calculated ) \note Function is protected by semaphore \note Functions that are protected by semaphores must not be
 * called in interrupts \note CRC will always calculate MSB first, this will be set internally
 * @param crcPreload : Value of pre-load DATA for CRC calculation
 * @param buffer :Pointer to data message structure on which CRC will be calculated.
 * @param dataLength : Length of \a buffer in bytes Note - Len must match with Buffer size.
 * @retval kStatus_Success Operation Successful.
 * @retval kStatus_CRC_ParameterError Unknown EEPROM address or address pointed by \p pDataToWrite is incorrect.
 * @retval kStatus_CRC_Busy
 * @retval kStatus_CRC_InternalError
 */
static inline status_t CRC_CheckCrc16(uint16_t crcPreload, uint8_t *buffer, uint32_t dataLength)
{
    return (status_t)PN76_Sys_Hal_CRC_CheckCrc16(crcPreload, buffer, dataLength);
}

/*!
 * @brief This function calculate CRC16 on selected FW buffer area.
 * \note Function is protected by semaphore
 * \note Functions that are protected by semaphores must not be called in interrupts
 * \note CRC will always calculate lsb first and byte by byte, but buffer doesn't have to be aligned
 * @param crcPreload : Value of pre-load DATA for CRC calculation
 * @param buffer :Pointer to data message structure on which CRC will be calculated.
 * @param dataLength : Length of \a buffer in bytes Note - Len must match with Buffer size.
 * @param crcValue : Pointer on calculated CRC value
 * @retval kStatus_Success Operation Successful.
 * @retval kStatus_CRC_ParameterError Unknown EEPROM address or address pointed by \p pDataToWrite is incorrect.
 * @retval kStatus_CRC_Busy
 * @retval kStatus_CRC_InternalError
 */
static inline status_t CRC_CalculateHDLLCrc16(uint16_t crcPreload,
                                              uint8_t *buffer,
                                              uint32_t dataLength,
                                              uint16_t *crcValue)
{
    return (status_t)PN76_Sys_Hal_CRC_CalculateHDLLCrc16(crcPreload, buffer, dataLength, crcValue);
}

/*!
 * @brief This function check CRC16 calculation on incoming frame buffer with calculated CRC value.
 * \note It is assumed that CRC16 result is part of the buffer (usually last two bytes, after data on which CRC is
 * calculated ) \note Function is protected by semaphore \note Functions that are protected by semaphores must not be
 * called in interrupts \note CRC will always calculate lsb first and byte by byte, but buffer doesn't have to be
 * aligned
 * @param crcPreload : Value of pre-load DATA for CRC calculation
 * @param buffer :Pointer to data message structure on which CRC will be calculated.
 * @param dataLength : Length of \a buffer in bytes Note - Len must match with Buffer size.
 * @retval kStatus_Success Operation Successful.
 * @retval kStatus_CRC_ParameterError Unknown EEPROM address or address pointed by \p pDataToWrite is incorrect.
 * @retval kStatus_CRC_Busy
 * @retval kStatus_CRC_InternalError
 */
static inline status_t CRC_CheckHDLLCrc16(uint16_t crcPreload, uint8_t *buffer, uint32_t dataLength)
{
    return (status_t)PN76_Sys_Hal_CRC_CheckHDLLCrc16(crcPreload, buffer, dataLength);
}

/*!
 * @brief This function calculates the CRC on selected FW buffer area using the CRC HW.
 * \note CRC will always calculate lsb first and byte by byte, but buffer doesn't have to be aligned
 * @param buffer :Pointer to data message structure on which CRC will be calculated.
 * @param length : Length of \a buffer in bytes Note - Len must match with Buffer size.
 * @retval kStatus_Success Operation Successful.
 * @retval kStatus_CRC_ParameterError Unknown EEPROM address or address pointed by \p pDataToWrite is incorrect.
 * @retval kStatus_CRC_Busy
 * @retval kStatus_CRC_InternalError
 */
static inline status_t CRC_Calc(uint8_t *buffer, uint32_t length)
{
    return (status_t)PN76_Sys_Hal_CRC_Calc(buffer, length);
}

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* FSL_CRC_H_ */
