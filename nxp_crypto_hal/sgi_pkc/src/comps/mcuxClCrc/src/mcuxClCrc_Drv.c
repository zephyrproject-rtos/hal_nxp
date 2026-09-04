/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#include <mcuxClCore_Platform.h>
#include <internal/mcuxClCrc_Drv.h>
#include <internal/mcuxClCrc_Internal_Functions.h>
#include <internal/mcuxClCrc_Internal_Constants.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_configureCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_Drv_configureCRC16(uint16_t poly16, uint16_t seed16, uint32_t rwCfg)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Drv_configureCRC16);

  /* Configure CRC to perform 16-bit CRC computation */
  mcuxClCrc_Sfr_writeControl(MCUXCLCRC_SFR_CTRL_CRC16 | MCUXCLCRC_SFR_CTRL_BIT_WRITE_SEED);

  /* Write 16-bit polynomial */
  mcuxClCrc_Sfr_writePolynomial(poly16);

  /* Write 16-bit seed */
  mcuxClCrc_Sfr_writeData16(seed16);

  /* Configure read/write options */
  mcuxClCrc_Sfr_writeControl(MCUXCLCRC_SFR_CTRL_CRC16 | rwCfg);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCrc_Drv_configureCRC16);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Internal_updateCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Internal_updateCRC16(const uint8_t *pBytes, uint32_t length, uint16_t seed16)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Internal_updateCRC16);

  /* Configure CRC to perform 16-bit CRC computation with a given seed
   * and the platform-specified 16-bit CRC polynomial.
   * Also configure the writes to be transposed (byte-wise) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC16(
    MCUXCLCRC_DEFAULT_POLY_16,
    seed16,
    MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS));

  MCUX_CSSL_FP_FUNCTION_CALL(crcRet, mcuxClCrc_Drv_updateCRC16(pBytes, length));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Internal_updateCRC16, crcRet,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC16),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_updateCRC16));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_updateCRC16)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Drv_updateCRC16(const uint8_t *pBytes, uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Drv_updateCRC16);
  const uint8_t *pData = pBytes;

  /* Process byte-wise until word-size aligned buffer remains */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("pointer cast to integer for alignment check")
  while((0u < length) && (0u != (((uint32_t)pData) & (sizeof(uint32_t) - 1u))))
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
  {
    MCUX_CSSL_DI_DONOTOPTIMIZE(pData);
    mcuxClCrc_Drv_writeData8bit(*pData);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
    pData++;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    length--;
  }

  /* Process word-wise full words of remaining buffer */
  while(sizeof(uint32_t) <= length)
  {
    MCUX_CSSL_DI_DONOTOPTIMIZE(pData);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pData is 32-bit aligned")
    mcuxClCrc_Drv_writeData32bit(*(const uint32_t *)pData);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    pData += sizeof(uint32_t);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    length -= sizeof(uint32_t);
  }

  /* Process byte-wise until the end of Data */
  while(0u < length)
  {
    MCUX_CSSL_DI_DONOTOPTIMIZE(pData);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
    mcuxClCrc_Drv_writeData8bit(*pData);
    pData++;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    length--;
  }

  uint32_t crcResult = mcuxClCrc_Sfr_readData();

  /* Expunge resulting pData, which equals pBytes + (original) length. This mechanism protects loops iterations. */
  MCUX_CSSL_DI_EXPUNGE(identifier, (uint32_t)pData);
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Drv_updateCRC16, (uint16_t)(crcResult & 0xFFFFu));
}

#ifdef MCUXCL_FEATURE_INTERNAL_CRC_BUFFER
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Internal_updateCRC16_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Internal_updateCRC16_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length, uint16_t seed16)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Internal_updateCRC16_buffer);

  /* Configure CRC to perform 16-bit CRC computation with a given seed
   * and the platform-specified 16-bit CRC polynomial.
   * Also configure the writes to be transposed (byte-wise) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC16(
    MCUXCLCRC_DEFAULT_POLY_16,
    seed16,
    MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS));

  MCUX_CSSL_FP_FUNCTION_CALL(crcRet, mcuxClCrc_Drv_updateCRC16_buffer(bufSrc, length));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Internal_updateCRC16_buffer, crcRet,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC16),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_updateCRC16_buffer));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_updateCRC16_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint16_t) mcuxClCrc_Drv_updateCRC16_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Drv_updateCRC16_buffer);

  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_WRITE()
  MCUX_CSSL_DI_RECORD(identifier /* Not used */, (uint32_t)(&CRC_SFR_BASE->DATA));
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_withoutDestIncrement(bufSrc, 0u, (uint8_t*)&CRC_SFR_BASE->DATA, length));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_WRITE()

  uint32_t crcResult = mcuxClCrc_Sfr_readData();

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Drv_updateCRC16_buffer, (uint16_t)(crcResult & 0xFFFFu),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_withoutDestIncrement));
}
#endif /* MCUXCL_FEATURE_INTERNAL_CRC_BUFFER */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_configureCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCrc_Drv_configureCRC32(uint32_t poly32, uint32_t seed32, uint32_t rwCfg)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Drv_configureCRC32);

  /* Configure CRC to perform 32-bit CRC computation */
  mcuxClCrc_Sfr_writeControl(MCUXCLCRC_SFR_CTRL_CRC32 | MCUXCLCRC_SFR_CTRL_BIT_WRITE_SEED);

  /* Write 32-bit polynomial */
  mcuxClCrc_Sfr_writePolynomial(poly32);

  /* Write 32-bit seed */
  mcuxClCrc_Sfr_writeData32(seed32);

  /* Configure read/write options */
  mcuxClCrc_Sfr_writeControl(MCUXCLCRC_SFR_CTRL_CRC32 | rwCfg);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCrc_Drv_configureCRC32);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Internal_updateCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Internal_updateCRC32(const uint8_t *pBytes, uint32_t length, uint32_t seed32)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Internal_updateCRC32);

  /* Configure CRC to perform 32-bit CRC computation with a given seed
   * and the platform-specified 32-bit CRC polynomial.
   * Also configure the writes to be transposed (byte-wise) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC32(
    MCUXCLCRC_DEFAULT_POLY_32,
    seed32,
    MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS));

  MCUX_CSSL_FP_FUNCTION_CALL(crcRet, mcuxClCrc_Drv_updateCRC32(pBytes, length));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Internal_updateCRC32, crcRet,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC32),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_updateCRC32));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_updateCRC32)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Drv_updateCRC32(const uint8_t *pBytes, uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Drv_updateCRC32);
  const uint8_t *pData = pBytes;

  /* Process byte-wise until word-size aligned buffer remains */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("pointer cast to integer for alignment check")
  while((0u < length) && (0u != (((uint32_t)pData) & (sizeof(uint32_t) - 1u))))
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()
  {
    MCUX_CSSL_DI_DONOTOPTIMIZE(pData);
    mcuxClCrc_Drv_writeData8bit(*pData);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
    pData++;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    length--;
  }

  /* Process word-wise full words of remaining buffer */
  while(sizeof(uint32_t) <= length)
  {
    MCUX_CSSL_DI_DONOTOPTIMIZE(pData);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pData is 32-bit aligned")
    mcuxClCrc_Drv_writeData32bit(*(const uint32_t *)pData);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    pData += sizeof(uint32_t);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    length -= sizeof(uint32_t);
  }

  /* Process byte-wise until the end of Data */
  while(0u < length)
  {
    MCUX_CSSL_DI_DONOTOPTIMIZE(pData);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer with valid address limited by length parameter. Length validity is ensured by the caller.")
    mcuxClCrc_Drv_writeData8bit(*pData);
    pData++;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    length--;
  }

  uint32_t crcResult = mcuxClCrc_Sfr_readData();

  /* Expunge resulting pData, which equals pBytes + (original) length. This mechanism protects loops iterations. */
  MCUX_CSSL_DI_EXPUNGE(identifier, (uint32_t)pData);
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Drv_updateCRC32, crcResult);
}

#ifdef MCUXCL_FEATURE_INTERNAL_CRC_BUFFER
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Internal_updateCRC32_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Internal_updateCRC32_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length, uint32_t seed32)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Internal_updateCRC32_buffer);

  /* Configure CRC to perform 32-bit CRC computation with a given seed
   * and the platform-specified 32-bit CRC polynomial.
   * Also configure the writes to be transposed (byte-wise) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClCrc_Drv_configureCRC32(
    MCUXCLCRC_DEFAULT_POLY_32,
    seed32,
    MCUXCLCRC_DRV_WRITE_TRANSPOSE_BYTES_NO_BITS));

  MCUX_CSSL_FP_FUNCTION_CALL(crcRet, mcuxClCrc_Drv_updateCRC32_buffer(bufSrc, length));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Internal_updateCRC32_buffer, crcRet,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_configureCRC32),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCrc_Drv_updateCRC32_buffer));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCrc_Drv_updateCRC32_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClCrc_Drv_updateCRC32_buffer(mcuxCl_InputBuffer_t bufSrc, uint32_t length)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCrc_Drv_updateCRC32_buffer);

  MCUX_CSSL_ANALYSIS_START_PATTERN_HW_WRITE()
  MCUX_CSSL_DI_RECORD(identifier /* Not used */, (uint32_t)(&CRC_SFR_BASE->DATA));
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_INTEGER_TO_POINTER("CRC SFR address")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_withoutDestIncrement(bufSrc, 0u, (uint8_t*)&CRC_SFR_BASE->DATA, length));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_INTEGER_TO_POINTER()
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_HW_WRITE()

  uint32_t crcResult = mcuxClCrc_Sfr_readData();

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClCrc_Drv_updateCRC32_buffer, crcResult,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_withoutDestIncrement));
}
#endif /* MCUXCL_FEATURE_INTERNAL_CRC_BUFFER */


