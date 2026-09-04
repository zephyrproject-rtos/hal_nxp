/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
#include <mcuxClCore_Macros.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClPadding.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClPadding_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClPrng_Internal.h>

#define MCUXCLPADDING_ISO_PADDING_BYTE (0x80U)

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_None, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_addPadding_None(
  mcuxClSession_Handle_t session,
  uint32_t blockLength UNUSED_PARAM,
  mcuxCl_InputBuffer_t pIn UNUSED_PARAM,
  uint32_t inOffset UNUSED_PARAM,
  uint32_t lastBlockLength,
  uint32_t totalInputLength UNUSED_PARAM,
  uint8_t * const pOut UNUSED_PARAM,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_None);

  if(0U != lastBlockLength)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  *pOutLength = 0U;
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_None);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_Default, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_removePadding_Default(
  mcuxClSession_Handle_t session,
  uint32_t blockLength UNUSED_PARAM,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_Default);

  /* Copy all bytes in the last block to the output buffer, no removal to be done */
  MCUX_CSSL_DI_RECORD(bufferWrite, (uint32_t) pOut);
  MCUX_CSSL_DI_RECORD(bufferWrite, outOffset);
  MCUX_CSSL_DI_RECORD(bufferWrite, (uint32_t) pIn);
  MCUX_CSSL_DI_RECORD(bufferWrite, lastBlockLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, outOffset, pIn, lastBlockLength));

  *pOutLength = lastBlockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_removePadding_Default,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_None, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_removePadding_None(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength UNUSED_PARAM,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_None);

  /* If no special padding is set - return the full last block */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPadding_removePadding_Default(
    session,
    blockLength,
    pIn,
    blockLength,
    pOut,
    outOffset,
    pOutLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_removePadding_None,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_ISO9797_1_Method1, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_addPadding_ISO9797_1_Method1(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_ISO9797_1_Method1);

  if((0U != totalInputLength) /* special case for zero-padding: add a padding block if totalInputLength is 0 */
       && (0U == lastBlockLength))
  {
    /* No padding needed */
    *pOutLength = 0;
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_ISO9797_1_Method1);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(blockLength, 1U, 16U, MCUXCLPADDING_STATUS_ERROR)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0U, blockLength - 1U, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength;

  MCUX_CSSL_DI_RECORD(memorySet, pOut + lastBlockLength);
  MCUX_CSSL_DI_RECORD(memorySet, paddingBytes);
  MCUXCLMEMORY_SET_INT(pOut + lastBlockLength, 0x00U, paddingBytes);

  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pIn);
  MCUX_CSSL_DI_RECORD(bufferRead, inOffset);
  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pOut);
  MCUX_CSSL_DI_RECORD(bufferRead, lastBlockLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pOut, lastBlockLength));

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_ISO9797_1_Method1,
    MCUXCLMEMORY_SET_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_ISO9797_1_Method1, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_removePadding_ISO9797_1_Method1(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_ISO9797_1_Method1);

  if(lastBlockLength != blockLength)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  /* ISO9797_1_Method1 padding cannot be removed - return full block */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPadding_removePadding_Default(
    session,
    blockLength,
    pIn,
    blockLength,
    pOut,
    outOffset,
    pOutLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_removePadding_ISO9797_1_Method1,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_START_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is defined indeed")
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_ISO9797_1_Method2, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_addPadding_ISO9797_1_Method2 (
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockLength,
  uint32_t totalInputLength UNUSED_PARAM,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_ISO9797_1_Method2);

  uint8_t *pOutPtr = (uint8_t *) pOut;

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(blockLength, 1U, 16U, MCUXCLPADDING_STATUS_ERROR)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0U, blockLength - 1U, MCUXCLPADDING_STATUS_ERROR)

  pOutPtr += lastBlockLength;
  *pOutPtr = MCUXCLPADDING_ISO_PADDING_BYTE;
  pOutPtr++;

  uint32_t paddingBytes = blockLength - lastBlockLength - 1U;

  MCUX_CSSL_DI_RECORD(memorySet, pOutPtr);
  MCUX_CSSL_DI_RECORD(memorySet, paddingBytes);
  MCUXCLMEMORY_SET_INT((uint8_t *) pOutPtr, 0x00U, paddingBytes);
  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pIn);
  MCUX_CSSL_DI_RECORD(bufferRead, inOffset);
  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pOut);
  MCUX_CSSL_DI_RECORD(bufferRead, lastBlockLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pOut, lastBlockLength));

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_ISO9797_1_Method2,
    MCUXCLMEMORY_SET_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_addPadding_MAC_ISO9797_1_Method2(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
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
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2);
  }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPadding_addPadding_ISO9797_1_Method2(
    session,
    blockLength,
    pIn,
    inOffset,
    lastBlockLength,
    totalInputLength,
    pOut,
    pOutLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_MAC_ISO9797_1_Method2,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_ISO9797_1_Method2));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_ISO9797_1_Method2, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_removePadding_ISO9797_1_Method2(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_ISO9797_1_Method2);

  /* DI balance the calls to the memory functions */
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, (uint32_t)pOut);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, outOffset);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, 5U * (uint32_t)pIn);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(blockLength));

  if(lastBlockLength != blockLength)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(blockLength, 1U, 16U, MCUXCLPADDING_STATUS_ERROR)
  MCUX_CSSL_FP_FUNCTION_CALL(random32, mcuxClPrng_generate_word());
  const uint8_t randomMaskByte = (uint8_t)(random32 & 0xFFU);

  MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pIn, pIn, randomMaskByte, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(blockLength));

  /* check the last bytes of the block, there must be all zero bytes until we reach the padding byte */
  uint32_t remainingBytes = blockLength;
  for(; remainingBytes > 0U; --remainingBytes)
  {
    uint8_t currentByte = pIn[remainingBytes - 1U];
    if((MCUXCLPADDING_ISO_PADDING_BYTE ^ randomMaskByte) == currentByte)
    {
      break;
    }

    if(randomMaskByte != currentByte)
    {
      /* padding error detected */
      MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
    }
  }

  if(0U == remainingBytes)
  {
    /* padding error detected - padding byte not found */
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("the remainingBytes does not overflow as 1U <= remainingBytes <= blockLength")
  /* one more decrease for the padding byte */
  remainingBytes--;
  /* DI balance the use remainingBytes in the called memory functions*/
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, remainingBytes);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(remainingBytes));

  MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pIn, pIn, randomMaskByte, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(remainingBytes));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  /* copy remaining bytes to output */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, outOffset, pIn, remainingBytes));

  *pOutLength = remainingBytes;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_removePadding_ISO9797_1_Method2,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT,
    MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_PKCS7, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void)  mcuxClPadding_addPadding_PKCS7 (
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockLength,
  uint32_t totalInputLength UNUSED_PARAM,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_PKCS7);

  if((blockLength <= 1U) || (blockLength > 255U))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0U, blockLength, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength;

  /*The value of paddingBytes is between 0 and 255, so that it always fits in a uint8_t data type*/
  MCUX_CSSL_DI_RECORD(memorySet, pOut + lastBlockLength);
  MCUX_CSSL_DI_RECORD(memorySet, paddingBytes);
  MCUXCLMEMORY_SET_INT(pOut + lastBlockLength, (uint8_t)(paddingBytes & 0xFFU), paddingBytes);
  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pIn);
  MCUX_CSSL_DI_RECORD(bufferRead, inOffset);
  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pOut);
  MCUX_CSSL_DI_RECORD(bufferRead, lastBlockLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pOut, lastBlockLength));

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_PKCS7,
    MCUXCLMEMORY_SET_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_PKCS7, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_removePadding_PKCS7(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_PKCS7);

  /* DI balance the calls to the memory functions */
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, (uint32_t)pOut);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, outOffset);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, 5U * (uint32_t)pIn);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(blockLength));

  if(lastBlockLength != blockLength)
  {
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(blockLength, 1U, 16U, MCUXCLPADDING_STATUS_ERROR)
  MCUX_CSSL_FP_FUNCTION_CALL(random32, mcuxClPrng_generate_word());
  const uint8_t randomMaskByte = (uint8_t) (random32 & 0xFFU);

  MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pIn, pIn, randomMaskByte, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(blockLength));

  /* last byte of the block - the amount of padding bytes to remove. Masked with mask. */
  uint8_t byteCheckMasked = pIn[blockLength - 1U];
  uint8_t byteCheck = byteCheckMasked ^ randomMaskByte;

  /* Padding byte must be in [1, blockLength] as PKCS7 padding adds at least one byte, and at most one block of padding. */
  if((0U == byteCheck) || (byteCheck > blockLength))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
  }

  /* check that the last byteCheck bytes in the last block are equal to byteCheck */
  for(uint8_t i = byteCheck; i > 0U; i--)
  {
    if(pIn[blockLength - i] != byteCheckMasked)
    {
      MCUXCLSESSION_ERROR(session, MCUXCLPADDING_STATUS_ERROR);
    }
  }

  /* copy remaining bytes to output */
  uint32_t remainingBytes = blockLength - (uint32_t)byteCheck;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(remainingBytes, 0U, blockLength, MCUXCLPADDING_STATUS_ERROR)
  /* DI balance the use remainingBytes in the called memory functions*/
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, remainingBytes);
  MCUX_CSSL_DI_RECORD(memoryFunctionCalls, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(remainingBytes));

  MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pIn, pIn, randomMaskByte, MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(remainingBytes));

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOut, outOffset, pIn, remainingBytes));

  *pOutLength = remainingBytes;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_removePadding_PKCS7,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT,
    MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_Random, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_addPadding_Random(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_Random);

  /* Empty input - return */
  if(0U == totalInputLength)
  {
    *pOutLength = 0U;
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_Random);
  }

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(lastBlockLength, 0U, blockLength, MCUXCLPADDING_STATUS_ERROR)
  uint32_t paddingBytes = blockLength - lastBlockLength;

  if(0U != paddingBytes)
  {
    MCUXCLBUFFER_INIT(pOutBuf, NULL, pOut + lastBlockLength, paddingBytes);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate(session, pOutBuf, paddingBytes));
  }

  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pIn);
  MCUX_CSSL_DI_RECORD(bufferRead, inOffset);
  MCUX_CSSL_DI_RECORD(bufferRead, (uint32_t) pOut);
  MCUX_CSSL_DI_RECORD(bufferRead, lastBlockLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pIn, inOffset, pOut, lastBlockLength));

  *pOutLength = blockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_Random,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_removePadding_Stream, mcuxClPadding_removePaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_removePadding_Stream(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  uint8_t * const pIn,
  uint32_t lastBlockLength,
  mcuxCl_Buffer_t pOut,
  uint32_t outOffset,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_removePadding_Stream);

  /* For stream ciphers - return only lastBlockLength */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPadding_removePadding_Default(
    session,
    blockLength,
    pIn,
    lastBlockLength,
    pOut,
    outOffset,
    pOutLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_removePadding_Stream,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_removePadding_Default));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPadding_addPadding_Stream, mcuxClPadding_addPaddingMode_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPadding_addPadding_Stream(
  mcuxClSession_Handle_t session,
  uint32_t blockLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t lastBlockLength,
  uint32_t totalInputLength,
  uint8_t * const pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPadding_addPadding_Stream);

  if(0U == lastBlockLength)
  {
    *pOutLength = 0U;
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_Stream);
  }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPadding_addPadding_Random(
    session,
    blockLength,
    pIn,
    inOffset,
    lastBlockLength,
    totalInputLength,
    pOut,
    pOutLength));

  *pOutLength = lastBlockLength;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPadding_addPadding_Stream,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPadding_addPadding_Random));
}
