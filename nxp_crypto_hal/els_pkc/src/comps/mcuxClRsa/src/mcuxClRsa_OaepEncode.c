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

/** @file  mcuxClRsa_OaepEncode.c
 *  @brief mcuxClRsa: function, which is called to execute RSAES-OAEP-ENCRYPT
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClPkc_Types.h>
#include <mcuxClMemory.h>
#include <mcuxClHash.h>
#include <mcuxClRandom.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClBuffer_Internal.h>


/*
* Implementation of OAEP encoding according to PKCS#1v2.2
*/

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_oaepEncode, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_oaepEncode(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_oaepEncode);
  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  uint8_t *pOutputPointer = MCUXCLBUFFER_GET(pOutput);

  /*
  1a.If the length of L is greater than the input limitation
    for the hash function, output "label too long" and stop.
    <No real need to do this check, saltlabelLength is uint32_t, so the same as the input length for mcuxClHash_compute>
  */

  /*
  1b. If mLen > k - 2hLen - 2, output "message too long" and
    stop.
  */

  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(pHashAlgo->hashSize, MCUXCLHASH_OUTPUT_SIZE_MD5, MCUXCLHASH_MAX_OUTPUT_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(keyByteLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  uint32_t keyByteLength = keyBitLength / 8u;
  if ( inputLength > (keyByteLength - (2u * pHashAlgo->hashSize) - 2u) )
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /*
  2a. If the label L is not provided, let L be the empty string.
    Let lHash = Hash(pLabel), an octet string of length hLen.
  */
  uint32_t hashOutputSize = 0u;
  uint32_t psLen = keyByteLength - inputLength - (pHashAlgo->hashSize * 2u) - 2u;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(inputLength, 0u, (pHashAlgo->hashSize * 2u), MCUXCLRSA_STATUS_INVALID_INPUT)
  uint32_t dbLen = pHashAlgo->hashSize + 1u + inputLength + psLen;

  const uint32_t pkcWaSizeWord = MCUXCLRSA_INTERNAL_OAEPENCODE_WAPKC_SIZE_WO_MGF1(keyByteLength) / sizeof(uint32_t);
  uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord);
  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  uint32_t usedPkcWorkarea = 0;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Because 'usedPkcWorkarea' is less than PKC RAM size, the access will be not out of bounds")
  uint8_t *db = &pPkcWorkarea[usedPkcWorkarea];
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  usedPkcWorkarea += MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(dbLen);

  MCUXCLBUFFER_INIT(dbBuf, pSession, db, pHashAlgo->hashSize);
  MCUX_CSSL_FP_FUNCTION_CALL(hash_result,
      mcuxClHash_compute(pSession, pHashAlgo, pLabel, saltlabelLength, dbBuf, &hashOutputSize) );

  if(MCUXCLHASH_STATUS_OK != hash_result)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_ERROR);
  }

  /*
  2b. Generate a padding string PS consisting of k - mLen -
    2hLen - 2 zero octets. The length of PS may be zero.
  */

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_set( &db[pHashAlgo->hashSize], 0x00u, psLen, psLen));

  /*
  3c. DB = lHash || PS || 0x01 || M.
  */
  db[pHashAlgo->hashSize + psLen] = 0x01;
  //TODO CLNS-6350 or CLNS-4506: secure (robust) copy shall be used when available
  MCUX_CSSL_FP_FUNCTION_CALL(read_result, mcuxClBuffer_read(pInput, 0u, &db[pHashAlgo->hashSize + psLen + 1u], inputLength));
  if(MCUXCLBUFFER_STATUS_OK != read_result)
  {
      mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, read_result,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read));
  }

/*
d. Generate a random octet string seed of length hLen.
*/
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Because 'usedPkcWorkarea' is less than PKC RAM size, the access will be not out of bounds")
  uint8_t *seed = &pPkcWorkarea[usedPkcWorkarea];
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  usedPkcWorkarea += MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(pHashAlgo->hashSize);
  MCUXCLBUFFER_INIT(pBufSeed, NULL, seed, pHashAlgo->hashSize);
  MCUX_CSSL_FP_FUNCTION_CALL(ret_Random_ncGenerate, mcuxClRandom_ncGenerate(pSession, pBufSeed , pHashAlgo->hashSize));
  if(MCUXCLRANDOM_STATUS_OK != ret_Random_ncGenerate)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_ERROR);
  }

/*
e. Let dbMask = MGF(seed, k - hLen - 1).
*/
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Because 'usedPkcWorkarea' is less than PKC RAM size, the access will be not out of bounds")
  uint8_t *dbMask = &pPkcWorkarea[usedPkcWorkarea];
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  usedPkcWorkarea += MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(dbLen);
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_mcuxClRsa_mgf1, mcuxClRsa_mgf1(pSession, pHashAlgo, seed, pHashAlgo->hashSize, dbLen, dbMask));
  if(MCUXCLRSA_STATUS_INTERNAL_MGF_OK != retVal_mcuxClRsa_mgf1)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_ERROR);
  }

/*
  f. Let maskedDB = DB \xor dbMask.
*/
  for(uint32_t i = 0u; i < dbLen ; i++)
  {
    /*maskedDB*/pOutputPointer[1u + pHashAlgo->hashSize+ i] = dbMask[i] ^ db[i];
  }

/*
g. Let seedMask = MGF(maskedDB, hLen).
h. Let maskedSeed = seed \xor seedMask.
i. Concatenate a single octet with hexadecimal value 0x00,
    maskedSeed, and maskedDB to form an encoded message EM of length k octets as
    EM = 0x00 || maskedSeed || maskedDB.
*/
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Because 'usedPkcWorkarea' is less than PKC RAM size, the access will be not out of bounds")
  uint8_t *seedMask = &pPkcWorkarea[usedPkcWorkarea];
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  usedPkcWorkarea += MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(pHashAlgo->hashSize);

  MCUX_CSSL_FP_FUNCTION_CALL(retVal_mcuxClRsa_mgf1_2, mcuxClRsa_mgf1(pSession, pHashAlgo, &pOutputPointer[1ULL + pHashAlgo->hashSize], dbLen, pHashAlgo->hashSize, seedMask));
  if(MCUXCLRSA_STATUS_INTERNAL_MGF_OK != retVal_mcuxClRsa_mgf1_2)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_ERROR);
  }

  for(uint32_t i = 0u; i < pHashAlgo->hashSize ; i++)
  {
    /*maskedSeed*/pOutputPointer[1u + i] = seedMask[i] ^ seed[i];
  }

  pOutputPointer[0] = 0x00u;
  mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_set),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1)
                            );
}
