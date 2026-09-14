/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

/** @file  mcuxClRsa_OaepDecode.c
 *  @brief mcuxClRsa: function, which is called to execute RSAES-OAEP-DECRYPT
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslMemory.h>
#include <mcuxClMemory.h>
#include <mcuxClHash.h>
#include <mcuxClBuffer.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_oaepDecode, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_oaepDecode(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength UNUSED_PARAM,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_oaepDecode);

  /* Setup lengths */
  const uint32_t keyByteLength = keyBitLength / 8u; /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  const uint32_t hLen = pHashAlgo->hashSize;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(hLen, MCUXCLHASH_OUTPUT_SIZE_MD5, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(keyByteLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t dbLen = keyByteLength - hLen - 1u;

  /* Check key length and hash length.
   * Note that this function will always be called after RSA private exponentiation, and saltlabelLength is uint32_t,
   * so other length checks from PKCS#1v2.2 standard are not required here */
  if(keyByteLength < ((2u * hLen) + 2u))
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Pointer offset arithmetic requires operating on abstract types of pointers.")
  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  uint8_t * pY = (uint8_t *)MCUXCLBUFFER_GET(pInput);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  uint8_t * pMaskedSeed = pY + 1u;
  uint8_t * pMaskedDB = pMaskedSeed + hLen;

  /* Setup session.
   * Note that this function is used in combination with an exponentiation function that uses mostly PKC WA.
   * Therefore, buffers in this functions are also allocated in PKC WA, in order to re-use memory. */
  const uint32_t wordSizeWa = MCUXCLRSA_INTERNAL_OAEPDECODE_WAPKC_SIZE_WO_MGF1(keyByteLength) / (sizeof(uint32_t));
  uint8_t *pWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordSizeWa);
  if (NULL == pWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /*
   * Set buffers in workarea
   * WA = | pSeedMask (hLen) || Y' (1 byte) || pDbMask (dbLen) |
   * So workarea usage (without MGF1) = dbLen + hLen + 1 = keyByteLength
   */
  uint8_t * pSeedMask = pWorkarea;  // contains the masked seed, and the seed (XOR in-place)
  uint8_t * pDbMask = pSeedMask + hLen + 1u;  // this is shifted by 1 byte after pSeedMask buffer, so the comparison buffer starts at pSeedMask + hLen
  uint8_t * pPS = pDbMask + hLen;  // located in DB after lHash'

  /* Let seedMask = MGF(maskedDB, hLen) */
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_mcuxClRsa_mgf1_1, mcuxClRsa_mgf1(pSession, pHashAlgo, pMaskedDB, dbLen, hLen, pSeedMask));
  if(MCUXCLRSA_STATUS_INTERNAL_MGF_OK != retVal_mcuxClRsa_mgf1_1)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_ERROR);
  }

  /* Let seed = maskedSeed xor seedMask.
   * This is done in-place in pSeedMask buffer */
  MCUX_CSSL_FP_LOOP_DECL(loop1);
  for(uint32_t i = 0u; i < hLen; ++i)
  {
    *(pSeedMask + i) ^= *(pMaskedSeed + i);
     MCUX_CSSL_FP_LOOP_ITERATION(loop1);
  }

  /* Let dbMask = MGF(seed, k - hLen - 1)
   * Note that the seed is in the buffer pSeedMask */
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_mcuxClRsa_mgf1_2, mcuxClRsa_mgf1(pSession, pHashAlgo, pSeedMask, hLen, dbLen, pDbMask));
  if(MCUXCLRSA_STATUS_INTERNAL_MGF_OK != retVal_mcuxClRsa_mgf1_2)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_ERROR);
  }

  /* Let DB = maskedDB xor dbMask.
   * This is done in-place in pDbMask buffer. DB should contain: lHash' || PS || 0x01 || M */
  MCUX_CSSL_FP_LOOP_DECL(loop2);
  for(uint32_t i = 0u; i < dbLen; ++i)
  {
    *(pDbMask + i) ^= *(pMaskedDB + i);
     MCUX_CSSL_FP_LOOP_ITERATION(loop2);
  }

  /* Count the length of the zero-padding PS, and check that the separator byte is equal to 0x01 */
  uint32_t psLen = 0u;
  while((pPS[psLen] == 0u) && (psLen < (dbLen - hLen - 1u)))
  {
    psLen++;
  }

  if(pPS[psLen] != 1u)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_INVALID_INPUT,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
      MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, hLen),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
      MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, dbLen)
      );
  }

  /* Calculate the hash of the label: lHash.
   * It partly overwrites the input encoded message, and immediately follows the first byte Y */
  uint32_t hashOutputSize = 0u;

  uint8_t * pLHash = pY + 1u;

  MCUXCLBUFFER_INIT(pLHashBuf, pSession, pLHash, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL(hash_result, mcuxClHash_compute(pSession,
                                                           pHashAlgo,
                                                           pLabel,
                                                           saltlabelLength,
                                                           pLHashBuf,
                                                           &hashOutputSize
                                                           ));
  if(MCUXCLHASH_STATUS_OK != hash_result)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_ERROR);
  }

  /* Set up the comparison buffer: it starts 1 byte before lHash' (in DB), and its first byte is set to zero */
  uint8_t * pComparison = pDbMask - 1u;
  pComparison[0u] = 0x0u;

  MCUX_CSSL_FP_FUNCTION_CALL(compare_result, mcuxCsslMemory_Compare(mcuxCsslParamIntegrity_Protect(3u, pY, pComparison, hLen + 1u),
                                                                  pY,
                                                                  pComparison,
                                                                  hLen + 1u));
  if(compare_result != MCUXCSSLMEMORY_STATUS_EQUAL)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_INVALID_INPUT,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
      MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, hLen),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
      MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, dbLen),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)
      );
  }

  uint8_t * pM = pPS + psLen + 1u;
  uint32_t outLength = dbLen - hLen - psLen - 1u;
  *pOutLength = outLength;

/* Check define outside of macro so the MISRA rule 20.6 does not get violated */
  #define CSSL_MEMORY_ENABLE_COMPARE_CALLED MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)

  /* TODO Shall be replaced under CLNS-6350 or CLNS-4506: secure (robust) copy shall be used when available */
  MCUX_CSSL_FP_FUNCTION_CALL(write_result, mcuxClBuffer_write(pOutput, 0u, pM, outLength));

  mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
  if(MCUXCLBUFFER_STATUS_OK != write_result)
  {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, write_result,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, hLen),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, dbLen),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
        CSSL_MEMORY_ENABLE_COMPARE_CALLED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write));
  }

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
    MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, hLen),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
    MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, dbLen),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
    CSSL_MEMORY_ENABLE_COMPARE_CALLED,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write)

    );
}
