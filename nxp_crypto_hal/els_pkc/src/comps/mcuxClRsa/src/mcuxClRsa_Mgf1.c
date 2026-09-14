/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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

/** @file  mcuxClRsa_Mgf1.c
 *  @brief mcuxClRsa: function, which is called to execute the mask generation function MGF1 of PKCS #1 v2.2.
 */

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClMemory.h>
#include <mcuxClHash.h>
#include <internal/mcuxClHash_Internal.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_mgf1)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_mgf1(
  mcuxClSession_Handle_t     pSession,
  mcuxClHash_Algo_t          pHashAlgo,
  const uint8_t *           pInput,
  const uint32_t            inputLength,
  const uint32_t            outputLength,
  uint8_t *                 pOutput)
{

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_mgf1);

  const uint32_t hLen = pHashAlgo->hashSize;

  /* Update PKC workarea */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(hLen, MCUXCLHASH_OUTPUT_SIZE_MD5, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(inputLength, 0u, MCUXCLPKC_RAM_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t wordSizePkcWa = (MCUXCLRSA_INTERNAL_MGF1_WAPKC_SIZE(inputLength, hLen) / (sizeof(uint32_t)));
  uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa);
  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_mgf1, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /* Pointer to the hash output */
  uint8_t * pHashOutput = pPkcWorkarea;

  /* Set up hash input */
  uint8_t * pHashInput = pHashOutput + hLen;

  MCUXCLMEMORY_FP_MEMORY_COPY(pHashInput, pInput, inputLength);

  /* counter = UPPER_BOUND(outputLength / pHashAlgo->hashSize) */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(outputLength, 0u, MCUXCLPKC_RAM_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t mxCounter = ((outputLength + hLen - 1U) / hLen);

  /* concatenated size of T */
  uint32_t tLen = 0U;

  for(uint32_t counter = 0U; counter < mxCounter; counter++)
  {
    /* Convert counter to a byte string C of length 4. */
    pHashInput[inputLength]      = (uint8_t) ((counter >> 24) & 0xFFU);
    pHashInput[inputLength + 1U] = (uint8_t) ((counter >> 16) & 0xFFU);
    pHashInput[inputLength + 2U] = (uint8_t) ((counter >>  8) & 0xFFU);
    pHashInput[inputLength + 3U] = (uint8_t) (counter);

    /* Append Hash(pInput || C) to T */

    /* Compute Hash */
    uint32_t hashOutputSize = 0u;

    MCUXCLBUFFER_INIT(pHashInputBuf, pSession, pHashInput, inputLength);
    MCUXCLBUFFER_INIT(pHashOutputBuf, pSession, pHashOutput, hLen);
    MCUX_CSSL_FP_FUNCTION_CALL(hash_result, mcuxClHash_compute(pSession,
                                                             pHashAlgo,
                                                             pHashInputBuf,
                                                             inputLength + 4U,
                                                             pHashOutputBuf,
                                                             &hashOutputSize) );
    if(MCUXCLHASH_STATUS_OK != hash_result)
    {
      mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_mgf1, MCUXCLRSA_STATUS_ERROR);
    }

    /* Concatenate the hash of the seed pInput and C to the T */
    uint32_t concatenateLen = (tLen + hLen > outputLength) ? (outputLength - tLen) : hLen;
    MCUXCLMEMORY_FP_MEMORY_COPY((uint8_t *) pOutput + tLen, pHashOutput, concatenateLen);

    tLen += concatenateLen;
  }

  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

/* Check define outside of macro so the MISRA rule 20.6 does not get violated */
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_mgf1, MCUXCLRSA_STATUS_INTERNAL_MGF_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute) * mxCounter,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy) * mxCounter);
}
