/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

/**
 * @file  mcuxClCrc_Drv.h
 * @brief CRC hardware driver of the mcuxClCrc component
 */

#ifndef MCUXCLCRC_DRV_H_
#define MCUXCLCRC_DRV_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClCrc_Sfr.h>

#define MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS     MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_BYTES_NO_BITS  ///< Only bytes are transposed; no bits in a byte are transposed
#define MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_AND_BITS    MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_BYTES_AND_BITS ///< Both bits in bytes and bytes are transposed
#define MCUXCLCRC_DRV_WRITE_TRANSPOSE_BITS_NO_BYTES     MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_BITS_NO_BYTES  ///< Bits in bytes are transposed; bytes are not transposed
#define MCUXCLCRC_DRV_WRITE_TRANSPOSE_NONE              MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_NONE           ///< No transposition

#define MCUXCLCRC_DRV_READ_TRANSPOSE_BYTES_NO_BITS      MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_BYTES_NO_BITS   ///< Only bytes are transposed; no bits in a byte are transposed
#define MCUXCLCRC_DRV_READ_TRANSPOSE_BYTES_AND_BITS     MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_BYTES_AND_BITS  ///< Both bits in bytes and bytes are transposed
#define MCUXCLCRC_DRV_READ_TRANSPOSE_BITS_NO_BYTES      MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_BITS_NO_BYTES   ///< Bits in bytes are transposed; bytes are not transposed
#define MCUXCLCRC_DRV_READ_TRANSPOSE_NONE               MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_NONE            ///< No transposition


#define MCUXCLCRC_DRV_BIT_COMPLEMENT_RESULT             MCUXCLCRC_SFR_CTRL_BIT_COMPLEMENT_RESULT          ///< Set control to complement checksum result

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClCrc_Drv mcuxClCrc_Drv
 * @brief Driver layer of the @ref mcuxClCrc component
 * @ingroup mcuxClCrc
 * @{
 */

/**
 * @defgroup mcuxClCrc_Drv_Functions mcuxClCrc_Drv_Functions
 * @brief Defines the CRC HW driver functions of component @ref mcuxClCrc
 * @ingroup mcuxClCrc_Drv
 * @{
 */

/**
 * @brief Configure CRC to be 16-bit CRC with a given polynomial and a given seed
 * Also configure the read write options.
 *
 * @param[in] poly16  16-bit polynomial
 * @param[in] seed16  16-bit seed
 * @param[in] rwCfg   read write configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Drv_configureCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_Drv_configureCRC16(uint16_t poly16, uint16_t seed16, uint32_t rwCfg);

/**
 * @brief Configure CRC to be 32-bit CRC with a given polynomial and a given seed.
 * Also configure the read write options.
 *
 * @param[in] poly32  32-bit polynomial
 * @param[in] seed32  32-bit seed
 * @param[in] rwCfg   read write configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCrc_Drv_configureCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_Drv_configureCRC32(uint32_t poly32, uint32_t seed32, uint32_t rwCfg);

/**
 * @brief Calculate/update CRC checksum over a given byte
 *
 * @param[in] data  8-bit value
 *
 * @return void
 *
 * @attention CRC shall be ready to accept data
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_writeData8bit)
static inline void mcuxClCrc_Drv_writeData8bit(uint8_t data)
{
  mcuxClCrc_Sfr_writeData8(data);
}

/**
 * Calculate/update CRC checksum over a given 16-bit word
 *
 * @param[in] data  16-bit value
 *
 * @return void
 *
 * @attention CRC shall be ready to accept data
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_writeData16bit)
static inline void mcuxClCrc_Drv_writeData16bit(uint16_t data)
{
  mcuxClCrc_Sfr_writeData16(data);
}

/**
 * Calculate/update CRC checksum over a given 32-bit word
 *
 * @param[in] data  32-bit value
 *
 * @return void
 *
 * @attention CRC shall be ready to accept data
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_writeData32bit)
static inline void mcuxClCrc_Drv_writeData32bit(uint32_t data)
{
  mcuxClCrc_Sfr_writeData32(data);
}

/**
 * Read the 16-bit or 32-bit CRC checksum
 *
 * @return 32-bit value of CRC checksum (without applying the output mask)
 *
 * @attention When calculaing 16-bit CRC, only lower 16 bits are valid, and
 *            higher 16 bits might contain nonzero values
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_readChecksum)
static inline uint32_t mcuxClCrc_Drv_readChecksum(void)
{
  return mcuxClCrc_Sfr_readData();
}

/**
 * @}
 */ /* mcuxClCrc_Drv_Functions */

/**
 * @}
 */ /* mcuxClCrc_Sfr */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCRC_DRV_H_ */
