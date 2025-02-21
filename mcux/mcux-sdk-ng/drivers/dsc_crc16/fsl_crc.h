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
 * @defgroup crc CRC: Cyclic Redundancy Check Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief CRC driver version. */
#define FSL_CRC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup crc_driver_log The Driver Change Log
 * @ingroup crc
 * @{
 * The current CRC driver version is 2.0.0.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup crc_intro CRC Peripheral and Driver Overview
 * @ingroup crc
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features
 * ===================
 *The Cyclic Redundancy Check (CRC) generator module uses the 16-bit CRC-CCITT polynomial, x16 + x12 + x5 + 1,
 *to generate a CRC code for error detection.
 *
 * Features
 * ---------
 *  + The CRC module calculates 8 bits at a time with a 16-bit code, and provides checks on all access locations, 
 *    whether they are in simple data or simply provided in RAM.
 *    - Hardware CRC generator circuit using 16-bit shift register.
 *    - CRC16-CCITT compliancy with x16 + x12 + x5 + 1 polynomial.
 *    - Programmable initial seed value.
 *
 *  + Optional ability to transpose input data and CRC result via transpose register, required on applications where bytes are in LSb (Least Significant bit) format.
 *
 *  + This section defines the CRC operation in run, wait, and stop modes.
 *    - Run Mode and Wait Mode is the basic mode of operation.
 *
 * How this driver is designed to make this peripheral work
 * ==========================================================
 * This driver provides multiple definitions/functions to enable and configure the CRC peripheral module. The CRC_Init()
 * function takes the argument in type of @ref crc_config_t, which contains all CRC features. After all the necessary
 * configuration is completed, the data for error detection can be written, then the CRC checksum value will be stored
 * in the CRC data register.The APIs this driver provides can be classified in 3 API groups:
 *
 *  + Initialization and De-initialization Interfaces
 *    - Functions to initialize or de-initialize the CRC module.
 *    - Configure the CRC to certain state with all feature covered.
 *
 *  + CRC Configuration Interfaces
 *    -This function group is used to separately configure other parameters required for CRC calculation.
 *
 *  + CRC Write/Read Data Interfaces
 *    - The CRC Data register contains the value of the seed, data, and checksum. The APIs in this function group
 *      can be used to write the value of the seed and the data for error detection, reads the 16-bit checksum
 *      from the CRC module.
 *
 *  How to use this driver
 *  =======================
 *  + Firstly initialize CRC module with @ref CRC_Init. In this step, you can optionally
 *    set the seed value by configure @ref crc_config_t::bSetSeed and
 *    @ref crc_config_t::u16CrcSeedValue.
 *
 *  + If @ref CRC_Init has set the seed value, you can call @ref CRC_WriteData directly,
 *    and CRC module will calculate the CRC result. If @ref CRC_Init does not set
 *    the seed value, then @ref CRC_SetSeedValue should be called before @ref CRC_WriteData.
 *
 *  + Call @ref CRC_Get16bitResult to get the CRC result.
 *
 *  + To start a new CRC calculation, call @ref CRC_SetSeedValue first, then @ref CRC_WriteData
 *    to feed data, and finally @ref CRC_Get16bitResult to read result.
 *
 *  Typical Use Case
 *  ================
 *  + CRC Initialization:
 *    - Initialization with seed, set seed value by configuring sConfig.
 *      @code
             char testData[]  = "123456789";
             crc_config_t sConfig;
             uint16_t checksum16;

             CRC_GetDefaultConfig(&sConfig);
             sConfig.bSetSeed = true;
             sConfig.u16CrcSeedValue = kCRC_Crc16CCITT;

             CRC_Init(CRC, &sConfig);
             CRC_WriteData(CRC, (uint8_t *)&testData[0], sizeof(testData) - 1, false);
             checksum16 = CRC_Get16bitResult(CRC, false);
        @endcode
 *
 *    - Initialization without seed, get seed value by call @ref CRC_SetSeedValue.
 *      @code
             char testData[]  = "123456789";
             crc_config_t sConfig;
             uint16_t checksum16;

             CRC_GetDefaultConfig(&sConfig);
             sConfig.bSetSeed = false;

             CRC_Init(CRC, &sConfig);
             CRC_SetSeedValue(CRC, kCRC_Crc16CCITT);
             CRC_WriteData(CRC, (uint8_t *)&testData[0], sizeof(testData) - 1, false);
             checksum16 = CRC_Get16bitResult(CRC, false);
        @endcode
 *
 *  + Calculate CRC for multiple data array.
 *    @code
          uint8_t testData1[] = {'a', 'b', 'c', 'd'};
          uint8_t testData2[] = {'A', 'B', 'C', 'D'};
          uint16_t crcResult1;
          uint16_t crcResult2;

          CRC_SetSeedValue(CRC, kCRC_Crc16Kermit);
          CRC_WriteData(CRC, testData1, sizeof(testData1), true);
          crcResult1 = CRC_Get16bitResult(CRC, true);

          CRC_SetSeedValue(CRC, kCRC_Crc16Kermit);
          CRC_WriteData(CRC, testData2, sizeof(testData2), true);
          crcResult2 = CRC_Get16bitResult(CRC, true);
 *    @endcode
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief CRC seed value. */
typedef enum _crc_seed_value
{
    kCRC_Crc16Kermit   = 0x0000U, /*!< CRC-16/KERMIT protocol. */
    kCRC_CrcA          = 0xC6C6U, /*!< CRC/CRCA protocol. */
    kCRC_Crc16Riello   = 0xB2AAU, /*!< CRC-16/RIELLO protocol. */
    kCRC_Crc16Tms37157 = 0x89ECU, /*!< CRC-16/TMS37157 protocol. */
    kCRC_Crc16Mcrf4xx  = 0xFFFFU, /*!< CRC-16-MCRF4XX protocol. */
    kCRC_Crc16CCITT    = 0xFFFFU, /*!< CRC-16-CCITT protocol. */
    kCRC_Crc16Augccitt = 0x1D0FU, /*!< CRC-16/AUG-CCITT protocol. */
    kCRC_Crc16Xmodem   = 0x0000U, /*!< CRC-16/XMODEM protocol. */
} crc_seed_value_t;

/*!
 * @brief CRC parameters configuration .
 *
 * This structure holds the configuration for the CRC required parameters.
 */
typedef struct _crc_config
{
    uint16_t u16CrcSeedValue; /*!< Starting checksum value */
    bool bSetSeed;            /*!< Set the seed value to registers only when this value is true */
} crc_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and De-initialization Interfaces
 * @{
 */

/*!
 * @brief Enables and configures the CRC peripheral module.
 *
 * This function enables the clock gate in the SIM module for the CRC peripheral.
 * It also configures the CRC module and starts a checksum computation by writing the seed.
 *
 * @param base     CRC peripheral address.
 * @param psConfig CRC module configuration structure
 */
void CRC_Init(CRC_Type *base, const crc_config_t *psConfig);

/*!
 * @brief Disables the CRC peripheral module.
 *
 * This function disables the clock gate in the SIM module for the CRC peripheral
 *
 * @param base     CRC peripheral address.
 */
void CRC_Deinit(CRC_Type *base);

/*!
 * @brief Provide default CRC seed value configuration.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref CRC_Init
 * to use. Provides the configuration of commonly used CRC seed values. refer to @ref crc_seed_value_t.
 *
 * @param psConfig CRC parameters configuration structure.
 */
void CRC_GetDefaultConfig(crc_config_t *psConfig);

/*! @} */

/*!
 * @name CRC Write/Read Data Interfaces
 * @{
 */

/*!
 * @brief Set the CRC seed value.
 *
 * This function is help to write a 16 bit CRC seed value.
 *
 * @param base            CRC peripheral address.
 * @param u16CrcSeedValue The value of seed.
 */
void CRC_SetSeedValue(CRC_Type *base, uint16_t u16CrcSeedValue);

/*!
 * @brief Writes data to the CRC module.
 *
 * Writes input data buffer bytes to the CRC data register.
 * The configured type of transpose is applied.
 *
 * @param base        CRC peripheral address.
 * @param pu8Data     Input data stream, MSByte in data[0].
 * @param u16DataSize Size in bytes of the input data buffer.
 * @param bRefin      Invert when input calculations.
 */
void CRC_WriteData(CRC_Type *base, const uint8_t *pu8Data, uint16_t u16DataSize, bool bRefin);

/*!
 * @brief Reads a 16-bit checksum from the CRC module.
 *
 * Reads the CRC data register (either an intermediate or the final checksum).
 * The configured type of transpose and complement is applied.
 *
 * @param base CRC peripheral address.
 * @param bRefOut Invert the calculated CRC value as a whole.
 * @return A 16-bit checksum with or without transposed configuration.
 */
uint16_t CRC_Get16bitResult(CRC_Type *base, bool bRefOut);

/*!
 * @brief CRC transpose module.
 *
 * The CRC module provides an additional feature to transpose data (invert bit order)
 *
 * @param base CRC peripheral address.
 * @param u8Input An 8-bit input data.
 */
static inline uint8_t CRC_TransposeByte(CRC_Type *base, uint8_t u8Input)
{
    base->TRANSPOSE = u8Input;

    return (uint8_t)(base->TRANSPOSE);
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* FSL_CRC_H_ */
