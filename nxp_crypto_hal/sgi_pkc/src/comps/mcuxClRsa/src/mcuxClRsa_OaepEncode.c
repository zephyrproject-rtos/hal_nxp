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

/** @file  mcuxClRsa_OaepEncode.c
 *  @brief mcuxClRsa: function, which is called to execute RSAES-OAEP-ENCRYPT
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClHash.h>
#include <mcuxClBuffer.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClMemory_XORSecure_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>


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
  1b. If mLen > k - 2hLen - 2, output "message too long" and stop.
      Implicitly, we should also have k > 2hLen + 2 since we are using unsigned integers.
  */
  const uint32_t keyByteLength = keyBitLength / 8U;
  const uint32_t hLen = pHashAlgo->hashSize;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hLen, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keyByteLength, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  if ((keyByteLength < (2U * hLen) + 2U) || (inputLength > keyByteLength - (2U * hLen) - 2U))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /*
   * Set buffers in workarea
   * WA = | db (dbLen) || seed (hLen) || dbMask (dbLen)  || seedMask (hLen) |
   */
  const uint32_t psLen = keyByteLength - inputLength - (hLen * 2U) - 2U;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(psLen, 0U, (keyByteLength - (2U * hLen) - 2U), MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t dbLen = keyByteLength - hLen - 1U;

  const uint32_t pkcWaSizeWord = MCUXCLRSA_INTERNAL_OAEPENCODE_WAPKC_SIZE_WO_MGF1(keyByteLength) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaSizeWord));
  uint8_t *pDb = pPkcWorkarea;
  uint8_t *pSeed = pDb + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(dbLen);
  uint8_t *pDbMask = pSeed + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(hLen);
  uint8_t *pSeedMask = pDbMask + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(dbLen);

  /*
  2a. If the label L is not provided, let L be the empty string.
    Let lHash = Hash(pLabel), an octet string of length hLen.
  */
  uint32_t hashOutputSize = 0U;
  MCUXCLBUFFER_INIT(dbBuf, pSession, pDb, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL(hash_result,
      mcuxClHash_compute(pSession, pHashAlgo, pLabel, saltlabelLength, dbBuf, &hashOutputSize) );

  if(MCUXCLHASH_STATUS_OK != hash_result)
  {
    mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_ERROR);
  }

  /*
  2b. Generate a padding string PS consisting of k - mLen -
    2hLen - 2 zero octets. The length of PS may be zero.
  */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_setPSdst, &pDb[hLen]);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_setPSlen, psLen);
  MCUXCLMEMORY_SET_INT(&pDb[hLen], 0x00U, psLen);

  /*
  2c. DB = lHash || PS || 0x01 || M.
  */
  pDb[hLen + psLen] = 0x01;
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, pInput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, &pDb[hLen + psLen + 1U]);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read_secure, inputLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read_secure(pInput, 0U, &pDb[hLen + psLen + 1U], inputLength));

  /*
  2d. Generate a random octet string seed of length hLen.
  */
  MCUXCLBUFFER_INIT(pBufSeed, NULL, pSeed, hLen);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, pSession);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, pBufSeed);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_generate_internal(pSession, pBufSeed, hLen, NULL));

  /*
  2e. Let dbMask = MGF(seed, k - hLen - 1).
  */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_mgf1(pSession, pHashAlgo, pSeed, hLen, dbLen, pDbMask));

  /*
  2f. Let maskedDB = DB \xor dbMask.
  */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, &pOutputPointer[1U + hLen]);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pDbMask);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pDb);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, dbLen);
  MCUXCLMEMORY_XOR_SECURE_INT(&pOutputPointer[1U + hLen], pDbMask, pDb, dbLen);

  /*
  2g. Let seedMask = MGF(maskedDB, hLen).
  2h. Let maskedSeed = seed \xor seedMask.
  2i. Concatenate a single octet with hexadecimal value 0x00,
      maskedSeed, and maskedDB to form an encoded message EM of length k octets as
      EM = 0x00 || maskedSeed || maskedDB.
  */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_mgf1(pSession, pHashAlgo, &pOutputPointer[1ULL + hLen], dbLen, hLen, pSeedMask));

  MCUX_CSSL_DI_RECORD(memXORintParams, &pOutputPointer[1U]);
  MCUX_CSSL_DI_RECORD(memXORintParams, pSeedMask);
  MCUX_CSSL_DI_RECORD(memXORintParams, pSeed);
  MCUX_CSSL_DI_RECORD(memXORintParams, hLen);
  MCUXCLMEMORY_XOR_INT(&pOutputPointer[1U], pSeedMask, pSeed, hLen);

  pOutputPointer[0] = 0x00U;
  mcuxClSession_freeWords_pkcWa(pSession, pkcWaSizeWord);
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepEncode, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
                            MCUXCLMEMORY_SET_INT_FP_EXPECT,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read_secure),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal),
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
                            MCUXCLMEMORY_XOR_SECURE_INT_FP_EXPECT,
                            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
                            MCUXCLMEMORY_XOR_INT_FP_EXPECT
  );
}
