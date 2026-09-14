/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClPadding.c
 *  @brief implementation of padding functions for different components */

#include <mcuxClToolchain.h>
#include <internal/mcuxClPadding_Internal.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClPadding.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClPrng_Internal.h>

#define MCUXCLPADDING_ISO_PADDING_BYTE (0x80u)


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_None, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_None(
  uint32_t blockLength UNUSED_PARAM,
  const uint8_t * const pIn UNUSED_PARAM,
  uint32_t lastBlockLength,
  uint32_t totalInputLength UNUSED_PARAM,
  uint8_t * const pOut UNUSED_PARAM,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_None);

  if(0u != lastBlockLength)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_None, MCUXCLPADDING_STATUS_ERROR);
  }

  *pOutLength = 0u;
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_None, MCUXCLPADDING_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_Default)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_removePadding_Default(
  uint32_t blockLength UNUSED_PARAM,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_Default);

  /* Copy all bytes in the last block to the output buffer, no removal to be done */
  MCUXCLMEMORY_FP_MEMORY_COPY(pOut, pIn, lastBlockLength);


  *pOutLength = lastBlockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_removePadding_Default, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_None, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_removePadding_None(
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength UNUSED_PARAM,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_None);

  /* If no special padding is set - return the full last block */
  MCUX_CSSL_FP_FUNCTION_CALL(removePaddingResult, mcuxClPadding_removePadding_Default(blockLength, pIn, blockLength, pOut, pOutLength));

  if(MCUXCLPADDING_STATUS_OK != removePaddingResult)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_removePadding_None, removePaddingResult,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_removePadding_None, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_ISO9797_1_Method1, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_ISO9797_1_Method1(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_ISO9797_1_Method1);

  if((0u != totalInputLength) /* special case for zero-padding: add a padding block if totalInputLength is 0 */
       && (0u == lastBlockLength))
  {
    /* No padding needed */
    *pOutLength = 0;
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_ISO9797_1_Method1, MCUXCLPADDING_STATUS_OK);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0u, blockLength, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength;

  MCUXCLMEMORY_FP_MEMORY_SET(pOut + lastBlockLength, 0x00u, paddingBytes);

  MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pOut, pIn, lastBlockLength, blockLength);

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_ISO9797_1_Method1, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set));
}


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_ISO9797_1_Method2, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_ISO9797_1_Method2 (
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength UNUSED_PARAM,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_ISO9797_1_Method2);

  uint8_t *pOutPtr = (uint8_t *) pOut;

  pOutPtr += lastBlockLength;

  *pOutPtr = MCUXCLPADDING_ISO_PADDING_BYTE;
  pOutPtr++;

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(blockLength, 1u, UINT32_MAX, MCUXCLPADDING_STATUS_ERROR)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0u, blockLength - 1u, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength - 1u;

  MCUXCLMEMORY_FP_MEMORY_SET((uint8_t *) pOutPtr, 0x00u, paddingBytes);

  MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pOut, pIn, lastBlockLength, blockLength);

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_ISO9797_1_Method2, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_MAC_ISO9797_1_Method2(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2);
  if(blockLength == lastBlockLength)
  {
    /* No padding needed */
    *pOutLength = 0;
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2, MCUXCLPADDING_STATUS_OK);
  }

  MCUX_CSSL_FP_FUNCTION_CALL(padResult, mcuxClPadding_addPadding_ISO9797_1_Method2(blockLength, pIn, lastBlockLength, totalInputLength, pOut, pOutLength));

  if(MCUXCLPADDING_STATUS_OK != padResult)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2, MCUXCLPADDING_STATUS_ERROR,
                                 MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2));
  }
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2));
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_PKCS7, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t)  mcuxClPadding_addPadding_PKCS7 (
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength UNUSED_PARAM,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_PKCS7);

  if((blockLength <= 1u ) || (blockLength > 255u))
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_PKCS7, MCUXCLPADDING_STATUS_ERROR);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0u, blockLength, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength;

  /*The value of paddingBytes is between 0 and 255, so that it always fits in a uint8_t data type*/
  MCUXCLMEMORY_FP_MEMORY_SET(pOut + lastBlockLength, (uint8_t)(paddingBytes & 0xFFu), paddingBytes);

  MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pOut, pIn, lastBlockLength, blockLength);

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_PKCS7, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set));
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_Random, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_addPadding_Random(
  uint32_t blockLength,
  const uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_Random);

  /* Empty input - return */
  if(0u == totalInputLength)
  {
    *pOutLength = 0u;
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_Random, MCUXCLPADDING_STATUS_OK);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0u, blockLength, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength;

  if(0u != paddingBytes)
  {
    // TODO CLNS-11297: improve this if possible.
    MCUXCLBUFFER_INIT(pOutBuf, NULL, pOut + lastBlockLength, paddingBytes);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_Prng_generate, mcuxClPrng_generate(pOutBuf, paddingBytes));

    if(MCUXCLPRNG_STATUS_OK != ret_Prng_generate)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_Random, MCUXCLPADDING_STATUS_NOT_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate)
        );
    }
  }

  MCUXCLMEMORY_FP_MEMORY_COPY_WITH_BUFF(pOut, pIn, lastBlockLength, blockLength);

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_addPadding_Random, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_Stream, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPadding_Status_t) mcuxClPadding_removePadding_Stream(
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_Stream);

  /* For stream ciphers - return only lastBlockLength */
  MCUX_CSSL_FP_FUNCTION_CALL(removePaddingResult, mcuxClPadding_removePadding_Default(blockLength, pIn, lastBlockLength, pOut, pOutLength));

  if(MCUXCLPADDING_STATUS_OK != removePaddingResult)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_removePadding_Stream, removePaddingResult,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClPadding_removePadding_Stream, MCUXCLPADDING_STATUS_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
}
