/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CRC_H_
#define FSL_CRC_H_

#include "fsl_common.h"

/*!
 * @addtogroup crc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief CRC driver version 2.0.0. */
#define FSL_CRC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))

/*! @brief CRC type.
 * CRC-16:
 *   poly:0x1021
 * CRC-32:
 *   poly:0x04C11DB7
 */
typedef enum _crc_type
{
    kCRC_Crc16 = CRC_CONTROL_CRCMOD(0), /*!< CRC-16     protocol. */
    kCRC_Crc32 = CRC_CONTROL_CRCMOD(1), /*!< CRC-32     protocol. */
} crc_type_t;

/*!
 * @brief CRC INV selection.
 */
typedef enum _crc_endian
{
    kCRC_MsbFirst = CRC_CONTROL_CRCINV(0), /*!< MSB, in this mode, refIn = false, refOut = false.*/
    kCRC_LsbFirst = CRC_CONTROL_CRCINV(1), /*!< LSB, in this mode, refIn = true, refOut = true.  */
} crc_endian_t;

/*!
 * @brief CRC protocol configuration.
 *
 * This structure holds the configuration for the CRC protocol.
 *
 */
typedef struct _crc_config
{
    bool crcEnable : 1; /*!< Block Enable or Disable. */

    crc_type_t crcMode; /*!< Select CRC protocol.*/

    crc_endian_t crcEndian; /*!< Select MSB or ILSB first data processing.*/
} crc_config_t;
/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Enables the CRC peripheral module.
 *
 * This function enables the clock gate for the CRC peripheral.
 * @param base     CRC peripheral address.
 */
void CRC_Init(CRC_Type *base);

/*!
 * @brief Disables the CRC peripheral module.
 *
 * This function disables the clock gate for the CRC peripheral.
 * @param base     CRC peripheral address.
 */
void CRC_Deinit(CRC_Type *base);

/*!
 * @brief Provide default CRC protocol configuration.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref
 * CRC_SetConfig to use. Provides the configuration of commonly used CRC protocols.
 * The default configuration is:
 * @code
     config->enable = true;
     config->crcMode = kCRC_Crc16;
     config->crcEndian = kCRC_LsbFirst;
 * @endcode
 * This is an example:
 * @code
        crc_config_t crc16Config;
        //Load CRC-16 protocol configuration.
        CRC_GetDefaultConfig(&crc16Config);
        CRC_SetConfig(CRC, crc16Config);
 * @endcode
 *
 * @param config     CRC protocol configuration structure.
 */
void CRC_GetDefaultConfig(crc_config_t *config);

/*!
 * @brief Configures the CRC peripheral module.
 *
 * This function configures the CRC module and starts a checksum computation by writing the seed.
 *
 * @param base     CRC peripheral address.
 * @param config   CRC module configuration structure.
 */
void CRC_SetConfig(CRC_Type *base, const crc_config_t *config);

/*!
 * @brief Set the CRC seed value.
 *
 * This function is help to write a 16/32 bit CRC seed value.
 *
 * @param base            CRC peripheral address.
 * @param crcPreload      The value of seed.
 */
static inline void CRC_SetSeed(CRC_Type *base, uint32_t crcPreload)
{
    base->DAT_PRELOAD = crcPreload;
}

/*!
 * @brief Set CRC type of transpose of write data.
 *
 * This function writes data to CRC.
 *
 * @param base      CRC peripheral address.
 * @param buffer    data message to be checked.
 * @param len       length of buffer.
 */
void CRC_WriteData(CRC_Type *base, const uint8_t *buffer, uint32_t len);

/*!
 * @brief Reads the checksum from the CRC module.
 *
 * Reads the CRC data register (either an intermediate or the final checksum).
 *
 * @param base CRC peripheral address.
 * @return An intermediate or the final checksum, after transpose and complement operations configured.
 */
static inline uint32_t CRC_GetResult(CRC_Type *base)
{
    return base->DAT_CALC;
}

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* FSL_CRC_H_ */
