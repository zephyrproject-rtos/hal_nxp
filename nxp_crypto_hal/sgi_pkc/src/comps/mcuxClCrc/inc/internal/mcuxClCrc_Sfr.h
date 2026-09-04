/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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
 * @file  mcuxClCrc_Sfr.h
 * @brief SFR-layer of the mcuxClCrc component
 */

#ifndef MCUXCLCRC_SFR_H_
#define MCUXCLCRC_SFR_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <platform_specific_headers.h>
#include <internal/mcuxClCrc_SfrAccess.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClCrc_Sfr mcuxClCrc_Sfr
 * @brief Defines the SFR layer of the @ref mcuxClCrc component
 * @ingroup mcuxClCrc
 * @{
 */

/**
 * @defgroup mcuxClCrc_Sfr_Defines mcuxClCrc_Sfr_Defines
 * @brief Defines for the SFR layer of the @ref mcuxClCrc component
 * @ingroup mcuxClCrc_Sfr
 * @{
 */

#define MCUXCLCRC_SFR_CTRL_CRC16 (((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,TCRC)) \
                                 | ((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,WAS))  \
                                 | ((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,FXOR)))   ///< Configuration of CRC-16 operation

#define MCUXCLCRC_SFR_CTRL_CRC32 (((uint32_t)1u << MCUXCLCRC_SFR_BITPOS(CTRL,TCRC)) \
                                 | ((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,WAS))  \
                                 | ((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,FXOR)))   ///< Configuration of CRC-32 operation

#define MCUXCLCRC_SFR_CTRL_BIT_WRITE_SEED   ((uint32_t)1u << MCUXCLCRC_SFR_BITPOS(CTRL,WAS))     ///< Set control to write seed value

#define MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_BYTES_NO_BITS   ((uint32_t)3u << MCUXCLCRC_SFR_BITPOS(CTRL,TOT))     ///< Only bytes are transposed; no bits in a byte are transposed
#define MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_BYTES_AND_BITS  ((uint32_t)2u << MCUXCLCRC_SFR_BITPOS(CTRL,TOT))     ///< Both bits in bytes and bytes are transposed
#define MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_BITS_NO_BYTES   ((uint32_t)1u << MCUXCLCRC_SFR_BITPOS(CTRL,TOT))     ///< Bits in bytes are transposed; bytes are not transposed
#define MCUXCLCRC_SFR_CTRL_WRITE_TRANSPOSE_NONE            ((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,TOT))     ///< No transposition

#define MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_BYTES_NO_BITS    ((uint32_t)3u << MCUXCLCRC_SFR_BITPOS(CTRL,TOTR))     ///< Only bytes are transposed; no bits in a byte are transposed
#define MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_BYTES_AND_BITS   ((uint32_t)2u << MCUXCLCRC_SFR_BITPOS(CTRL,TOTR))     ///< Both bits in bytes and bytes are transposed
#define MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_BITS_NO_BYTES    ((uint32_t)1u << MCUXCLCRC_SFR_BITPOS(CTRL,TOTR))     ///< Bits in bytes are transposed; bytes are not transposed
#define MCUXCLCRC_SFR_CTRL_READ_TRANSPOSE_NONE             ((uint32_t)0u << MCUXCLCRC_SFR_BITPOS(CTRL,TOTR))     ///< No transposition

#define MCUXCLCRC_SFR_CTRL_BIT_COMPLEMENT_RESULT   ((uint32_t)1u << MCUXCLCRC_SFR_BITPOS(CTRL,FXOR))     ///< Set control to complement checksum result

/**
 * @}
 */ /* mcuxClCrc_Sfr_Defines */

/**
 * @defgroup mcuxClCrc_Sfr_Functions mcuxClCrc_Sfr_Functions
 * @brief Functions of the SFR layer of the @ref mcuxClCrc component
 * @ingroup mcuxClCrc_Sfr
 * @{
 */

/**
 * @brief Read the CRC control register
 *
 * @return 32-bit value of CRC control
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_readControl)
static inline uint32_t mcuxClCrc_Sfr_readControl(void)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  return MCUXCLCRC_SFR_READ(CTRL);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Read the CRC data register
 *
 * @return 32-bit value of CRC data
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_readData)
static inline uint32_t mcuxClCrc_Sfr_readData(void)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  return MCUXCLCRC_SFR_READ(DATA);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Read the CRC polynomial register
 *
 * @return 32-bit value of CRC polynomial
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_readPolynomial)
static inline uint32_t mcuxClCrc_Sfr_readPolynomial(void)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  return MCUXCLCRC_SFR_READ(GPOLY);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Write to the CRC control register
 *
 * @param[in] control  32-bit control word
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_writeControl)
static inline void mcuxClCrc_Sfr_writeControl(uint32_t control)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  MCUXCLCRC_SFR_WRITE(CTRL, control);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Write a byte to the CRC data register
 *
 * @param[in] data  8-bit value
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_writeData8)
static inline void mcuxClCrc_Sfr_writeData8(uint8_t data)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  MCUXCLCRC_SFR_WRITE8(DATA, data);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Write a 16-bit word to the CRC data register
 *
 * @param[in] data  16-bit value
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_writeData16)
static inline void mcuxClCrc_Sfr_writeData16(uint16_t data)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  MCUXCLCRC_SFR_WRITE16(DATA, data);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Write a 32-bit word to the CRC data register
 *
 * @param[in] data  32-bit value
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_writeData32)
static inline void mcuxClCrc_Sfr_writeData32(uint32_t data)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  MCUXCLCRC_SFR_WRITE(DATA, data);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @brief Write to the CRC polynomial register
 *
 * @param poly  16-bit or 32-bit polynomial (padding to 32-bit word)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Sfr_writePolynomial)
static inline void mcuxClCrc_Sfr_writePolynomial(uint32_t poly)
{
#ifdef __COVERITY__
#pragma coverity compliance block deviate "MISRA C-2012 Rule 11.8" "MISRA Ex. 2 - Rule 11.8 - Remove volatile qualifier in hardware interface"
#endif

  MCUXCLCRC_SFR_WRITE(GPOLY, poly);

#ifdef __COVERITY__
#pragma coverity compliance end_block "MISRA C-2012 Rule 11.8"
#endif
}

/**
 * @}
 */ /* mcuxClCrc_Sfr_Functions */

/**
 * @}
 */ /* mcuxClCrc_Sfr */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCRC_SFR_H_ */

