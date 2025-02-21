/*
 * Copyright 2020-2021 NXP
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
/*! @brief CRC driver version. Version. */
#define FSL_CRC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup crc_driver_log The Driver Change Log
 * @ingroup crc
 * @{
 * The current CRC driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
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
 * ==================================================
 * The cyclic redundancy check (CRC) module generates 16/32-bit CRC code for error detection.
 *
 * Features
 * ---------
 *  + The CRC module provides a programmable polynomial and other parameters required to implement a 16-bit or
 *    32-bit CRC standard.
 *    - Hardware CRC generator circuit using a 16-bit or 32-bit programmable shift register.
 *    - Programmable initial seed value and polynomial.
 *    - 32-bit CPU register programming interface.
 *    - In 16-bit and 32-bit CRC modes, data values can be programmed 8 bits, 16 bits, or 32 bits at a time, provided
 *      all bytes are contiguous.
 *
 *  + Option to transpose input data or output data (the CRC result) bitwise or bytewise.
 *    - This option is required for certain CRC standards. A bytewise transpose operation is not possible when
 *	    accessing the CRC data register via 8-bit accesses. In this case, the user's software must perform the bytewise
 *	    transpose function.
 *
 *  + Option for inversion of final CRC result.
 *
 *  + Various MCU modes affect the CRC module's functionality.
 *    - Run mode is the basic mode of operation.
 *    - Any CRC calculation in progress stops when the MCU enters a low-power mode (Wait or Stop) that disables the
 *      module clock. It resumes after the clock is enabled or via the system reset for exiting the low-power mode.
 *      Clock gating for this module is dependent on the MCU.
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
 *    - The APIs in this function group can be used to separately configure the CRC polynomial and other parameters
 *      required for the CRC calculation.
 *
 *  + CRC Write/Read Data Interfaces
 *    - The CRC Data register contains the value of the seed, data, and checksum. The APIs in this function group
 *      can be used to write the value of the seed and the data for error detection, reads the 16-bit/32-bit checksum
 *      from the CRC module.
 *
 *  How to use this driver
 *  =======================
 *  + Initialize the CRC module with expected polynomial and other parameters required.
 *    - Provides the configuration of commonly used CRC protocols in CRC_GetDefaultConfig() function. refer
 *      to @ref crc_protocol_type_t to use expected CRC protocol.
 *
 *  + Configure the CRC polynomial and other parameters required for the CRC calculation.
 *    - Just use when expecting to change the parameters separately.
 *
 *  + Write the data for error detection.
 *
 *  + Get the 16-bit or 32-bit checksum.
 *
 *  Typical Use Case
 *  ================
 *  + CRC Initialization:
 *    @code
           crc_config_t sConfig;
           //Load CRC-16/MAXIM protocol configuration.
           CRC_GetDefaultConfig(&sConfig, kCRC_Crc16);
           CRC_Init(CRC, &sConfig);
 *    @endcode
 *  + Change CRC module configuration:
 *    @code
           //take CRC-16/CCITT-FALSE protocol as example.
           CRC_EnableComplementChecksum(CRC, false);
           CRC_SetPolynomial(CRC, 0x1021);
           CRC_SetProtocolWidth(CRC, kCRC_Bits16);
           CRC_SetWriteTransposeType(CRC, kCRC_TransposeBytes);
           CRC_SetReadTransposeType(CRC, kCRC_TransposeNone);
           CRC_SetSeedValue(CRC, 0xFFFF);
 *    @endcode
 *
 *  + Write data to the CRC module:
 *    @code
           char testData[]  = "123456789";
           CRC_WriteData(CRC, (uint8_t *)&testData[0], sizeof(testData) - 1);
 *    @endcode
 *
 *  + Read the 16-bit checksum from the CRC module:
 *    @code
           uint16_t checksum16;
           checksum32 = CRC_Get16bitResult(CRC);
 *    @endcode
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief CRC protocol type. */
typedef enum _crc_protocol_type
{
    kCRC_Crc16       = 0U, /*!< CRC-16/MAXIM protocol. */
    kCRC_Crc16CCITT  = 1U, /*!< CRC-16-CCITT protocol. */
    kCRC_Crc16Kermit = 2U, /*!< CRC-16/KERMIT protocol. */
    kCRC_Crc32       = 3U, /*!< CRC-32 protocol. */
    kCRC_Crc32Posix  = 4U, /*!< CRC-32/POSIX protocol. */
} crc_protocol_type_t;

/*! @brief CRC protocol bit width. */
typedef enum _crc_bits
{
    kCRC_Bits16 = 0U, /*!< Generate 16-bit CRC code. */
    kCRC_Bits32 = 1U  /*!< Generate 32-bit CRC code. */
} crc_bits_t;

/*! @brief CRC type of transpose of read/write data. */
typedef enum _crc_transpose_type
{
    kCRC_TransposeNone         = 0U, /*!< No transpose. */
    kCRC_TransposeBits         = 1U, /*!< Transpose bits in bytes. */
    kCRC_TransposeBitsAndBytes = 2U, /*!< Transpose bytes and bits in bytes. */
    kCRC_TransposeBytes        = 3U, /*!< Transpose bytes. */
} crc_transpose_type_t;

/*!
 * @brief CRC protocol configuration.
 *
 * This structure holds the configuration for the CRC protocol.
 *
 */
typedef struct _crc_config
{
    uint32_t u32CrcPolynomial; /*!< CRC Polynomial, MSBit first.
                                  Example polynomial: 0x1021 = 1_0000_0010_0001 = x^12+x^5+1 */
    uint32_t u32CrcSeedValue;  /*!< Starting checksum value */

    bool bEnableComplementChecksum : 1; /*!< Enable/Disable complement of read CRC checksum. */

    crc_transpose_type_t eTransposeIn : 2;  /*!< Select type of transpose of input data. */
    crc_transpose_type_t eTransposeOut : 2; /*!< Select type of transpose of output data. */

    crc_bits_t eCrcBits : 1; /*!< Select 16-bit or 32-bit CRC protocol.*/
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
 * @param psConfig CRC module configuration structure.
 */
void CRC_Init(CRC_Type *base, const crc_config_t *psConfig);

/*!
 * @brief Disables the CRC peripheral module.
 *
 * This function disables the clock gate in the SIM module for the CRC peripheral.
 *
 * @param base CRC peripheral address.
 */
void CRC_Deinit(CRC_Type *base);

/*!
 * @brief Provide default CRC protocol configuration.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref CRC_Init
 * to use. Provides the configuration of commonly used CRC protocols. refer to @ref crc_protocol_type_t.
 *
 * This is an example:
 * @code
        crc_config_t sConfig;
        //LoadCRC-16/MAXIM protocol configuration.
        CRC_GetDefaultConfig(&sConfig, kCRC_Crc16);
        CRC_Init(CRC, &sConfig);
 * @endcode
 *
 * @param psConfig     CRC protocol configuration structure.
 * @param eCrcProtocol CRC protocol type. refer to @ref crc_protocol_type_t
 */
static inline void CRC_GetDefaultConfig(crc_config_t *psConfig, crc_protocol_type_t eCrcProtocol)
{
    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    switch (eCrcProtocol)
    {
        case kCRC_Crc16: /* CRC-16/MAXIM protocol. */

            psConfig->u32CrcPolynomial          = 0x8005U;
            psConfig->u32CrcSeedValue           = 0x0000U;
            psConfig->eTransposeIn              = kCRC_TransposeBitsAndBytes;
            psConfig->eTransposeOut             = kCRC_TransposeBitsAndBytes;
            psConfig->bEnableComplementChecksum = true;
            psConfig->eCrcBits                  = kCRC_Bits16;

            break;

        case kCRC_Crc16CCITT: /* CRC-16-CCITT protocol. */

            psConfig->u32CrcPolynomial          = 0x1021U;
            psConfig->u32CrcSeedValue           = 0xFFFFU;
            psConfig->eTransposeIn              = kCRC_TransposeBytes;
            psConfig->eTransposeOut             = kCRC_TransposeNone;
            psConfig->bEnableComplementChecksum = false;
            psConfig->eCrcBits                  = kCRC_Bits16;

            break;

        case kCRC_Crc16Kermit: /* CRC-16/KERMIT protocol. */

            psConfig->u32CrcPolynomial          = 0x1021U;
            psConfig->u32CrcSeedValue           = 0x0000U;
            psConfig->eTransposeIn              = kCRC_TransposeBitsAndBytes;
            psConfig->eTransposeOut             = kCRC_TransposeBitsAndBytes;
            psConfig->bEnableComplementChecksum = false;
            psConfig->eCrcBits                  = kCRC_Bits16;

            break;

        case kCRC_Crc32: /* CRC-32 protocol. */

            psConfig->u32CrcPolynomial          = 0x04C11DB7U;
            psConfig->u32CrcSeedValue           = 0xFFFFFFFFU;
            psConfig->eTransposeIn              = kCRC_TransposeBitsAndBytes;
            psConfig->eTransposeOut             = kCRC_TransposeBitsAndBytes;
            psConfig->bEnableComplementChecksum = true;
            psConfig->eCrcBits                  = kCRC_Bits32;

            break;

        case kCRC_Crc32Posix: /* CRC-32/POSIX protocol. */

            psConfig->u32CrcPolynomial          = 0x04C11DB7U;
            psConfig->u32CrcSeedValue           = 0x00000000U;
            psConfig->eTransposeIn              = kCRC_TransposeBytes;
            psConfig->eTransposeOut             = kCRC_TransposeNone;
            psConfig->bEnableComplementChecksum = true;
            psConfig->eCrcBits                  = kCRC_Bits32;

            break;

        default:
            assert(false);
            break;
    }
}
/*! @} */

/*!
 * @name CRC Configuration Interfaces
 * @{
 */

/*!
 * @brief Set the CRC seed value.
 *
 * This function is help to write a 16/32 bit CRC seed value.
 *
 * @param base            CRC peripheral address.
 * @param u32CrcSeedValue The value of seed.
 */
static inline void CRC_SetSeedValue(CRC_Type *base, uint32_t u32CrcSeedValue)
{
    /*  Make sure WAS bit is asserted before writing a seed value. */
    base->CTRL |= CRC_CTRL_WAS_MASK;

    /* write seed (initial checksum). */
#if defined(FSL_FEATURE_CRC_HAS_CRC_REGISTER) && FSL_FEATURE_CRC_HAS_CRC_REGISTER
    base->CRC32 = u32CrcSeedValue;
#else
    base->DATA32 = u32CrcSeedValue;
#endif

    /* Deassert WAS bit. */
    base->CTRL &= ~CRC_CTRL_WAS_MASK;
}

/*!
 * @brief Set the value of the polynomial for the CRC calculation.
 *
 * Write a 16-bit or 32-bit polynomial to CRC Polynomial register for the CRC calculation.
 *
 * @param base             CRC peripheral address.
 * @param u32CrcPolynomial The CRC polynomial.
 */
static inline void CRC_SetPolynomial(CRC_Type *base, uint32_t u32CrcPolynomial)
{
    base->GPOLY = u32CrcPolynomial;
}

/*!
 * @brief Set CRC type of transpose of write data.
 *
 * This function help to configure CRC type of transpose of write data.
 *
 * @param base         CRC peripheral address.
 * @param eTransposeIn Type Of transpose for input. See @ref crc_transpose_type_t
 */
static inline void CRC_SetWriteTransposeType(CRC_Type *base, crc_transpose_type_t eTransposeIn)
{
    base->CTRL = (base->CTRL & (~CRC_CTRL_TOT_MASK)) | ((uint32_t)eTransposeIn << CRC_CTRL_TOT_SHIFT);
}

/*!
 * @brief Set CRC type of transpose of read data.
 *
 * This function help to configure CRC type of transpose of read data.
 *
 * @param base          CRC peripheral address.
 * @param eTransposeOut Type Of transpose for output. See @ref crc_transpose_type_t
 */
static inline void CRC_SetReadTransposeType(CRC_Type *base, crc_transpose_type_t eTransposeOut)
{
    base->CTRL = (base->CTRL & (~CRC_CTRL_TOTR_MASK)) | ((uint32_t)eTransposeOut << CRC_CTRL_TOTR_SHIFT);
}

/*!
 * @brief Enable/Disable complement of read CRC checksum.
 *
 * Set complement of read CRC checksum. Some CRC protocols require the final checksum to be XORed with
 * 0xFFFFFFFF or 0xFFFF.
 *
 * @param base    CRC peripheral address.
 * @param bEnable True or false. True if the result shall be complement of the actual checksum.
 */
static inline void CRC_EnableComplementChecksum(CRC_Type *base, bool bEnable)
{
    if (bEnable == true)
    {
        base->CTRL |= CRC_CTRL_FXOR_MASK;
    }
    else
    {
        base->CTRL &= ~CRC_CTRL_FXOR_MASK;
    }
}

/*!
 * @brief Set bit width of CRC protocol.
 *
 * Selects 16-bit or 32-bit CRC protocol.
 *
 * @param base      CRC peripheral address.
 * @param eCrcBits  16 or 32 bit CRC protocol. See @ref crc_bits_t
 */
static inline void CRC_SetProtocolWidth(CRC_Type *base, crc_bits_t eCrcBits)
{
    if (kCRC_Bits32 == eCrcBits)
    {
        base->CTRL |= CRC_CTRL_TCRC_MASK;
    }
    else
    {
        base->CTRL &= ~CRC_CTRL_TCRC_MASK;
    }
}

/*! @} */

/*!
 * @name CRC Write/Read Data Interfaces
 * @{
 */

/*!
 * @brief Writes data to the CRC module.
 *
 * Writes input data buffer bytes to the CRC data register.
 * The configured type of transpose is applied.
 *
 * @param base        CRC peripheral address.
 * @param pu8Data     Input data stream, MSByte in data[0].
 * @param u32DataSize Size in bytes of the input data buffer.
 */
void CRC_WriteData(CRC_Type *base, const uint8_t *pu8Data, uint32_t u32DataSize);

/*!
 * @brief Reads the 32-bit checksum from the CRC module.
 *
 * Reads the CRC data register (either an intermediate or the final checksum).
 * The configured type of transpose and complement is applied.
 *
 * @param base CRC peripheral address.
 * @return An intermediate or the final 32-bit checksum, after transpose and complement operations configured.
 */
static inline uint32_t CRC_Get32bitResult(CRC_Type *base)
{
#if defined(FSL_FEATURE_CRC_HAS_CRC_REGISTER) && FSL_FEATURE_CRC_HAS_CRC_REGISTER
    return base->CRC32;
#else
    return base->DATA32;
#endif
}

/*!
 * @brief Reads a 16-bit checksum from the CRC module.
 *
 * Reads the CRC data register (either an intermediate or the final checksum).
 * The configured type of transpose and complement is applied.
 *
 * @param base CRC peripheral address.
 * @return An intermediate or the final 16-bit checksum, after transpose and complement operations configured.
 */
uint16_t CRC_Get16bitResult(CRC_Type *base);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* FSL_CRC_H_ */
