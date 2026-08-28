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

/** @file  mcuxClRsa_OaepDecode.c
 *  @brief mcuxClRsa: function, which is called to execute RSAES-OAEP-DECRYPT
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClMemory_CompareSecure_Internal.h>
#include <internal/mcuxClMemory_XORSecure_Internal.h>
#include <internal/mcuxClMemory_XORSecureWithConst_Internal.h>

#include <mcuxClHash.h>
#include <mcuxClBuffer.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClPrng_Internal_Functions.h>
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

  /************************************************************************************************/
  /* Step 1: Setup lengths and validate parameters                                                */
  /************************************************************************************************/
  const uint32_t keyByteLength = keyBitLength / 8U; /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  const uint32_t hLen = pHashAlgo->hashSize;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hLen, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keyByteLength, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t dbLen = keyByteLength - hLen - 1U;

  /* Check key length and hash length.
   * Note that this function will always be called after RSA private exponentiation, and saltlabelLength is uint32_t,
   * so other length checks from PKCS#1v2.2 standard are not required here */
  if(keyByteLength < ((2U * hLen) + 2U))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /************************************************************************************************/
  /* Step 2: Extract encoded message components                                                   */
  /************************************************************************************************/
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Pointer offset arithmetic requires operating on abstract types of pointers.")
  /* Extract plain pointer from buffer type (this buffer has been created in internal memory by the calling function, for compatibility purposes) */
  uint8_t * pY = (uint8_t *)MCUXCLBUFFER_GET(pInput);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
  uint8_t * pMaskedSeed = pY + 1U;
  uint8_t * pMaskedDB = pMaskedSeed + hLen;

  /************************************************************************************************/
  /* Step 3: Allocate workarea and setup buffer pointers                                          */
  /************************************************************************************************/
  /* Setup session.
   * Note that this function is used in combination with an exponentiation function that uses mostly PKC WA.
   * Therefore, buffers in this functions are also allocated in PKC WA, in order to re-use memory. */
  const uint32_t wordSizeWa = MCUXCLRSA_INTERNAL_OAEPDECODE_WAPKC_SIZE_WO_MGF1(keyByteLength) / (sizeof(uint32_t));
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, wordSizeWa));

  /*
   * Set buffers in workarea
   * WA = | pSeedMask (hLen) || Y' (1 byte) || pDbMask (dbLen)  || pPsMask (dbLen - hLen) |
   * So workarea usage (without MGF1) = dbLen + hLen + 1 + dbLen - hLen = keyByteLength + dbLen - hLen
   */
  uint8_t * pSeedMask = pWorkarea;  // contains the masked seed, and the seed (XOR in-place)
  uint8_t * pDbMask = pSeedMask + hLen + 1U;  // this is shifted by 1 byte after pSeedMask buffer, so the comparison buffer starts at pSeedMask + hLen
  uint8_t * pPS = pDbMask + hLen;  // located in DB after lHash'
  uint8_t * pPsMask = pWorkarea + keyByteLength; // located after DB

  /************************************************************************************************/
  /* Step 4: Compute seedMask and recover seed                                                    */
  /************************************************************************************************/
  /* Let seedMask = MGF(maskedDB, hLen) */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_mgf1(pSession, pHashAlgo, pMaskedDB, dbLen, hLen, pSeedMask));

  /* Let seed = maskedSeed xor seedMask.
   * This is done in-place in pSeedMask buffer
   */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pSeedMask);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pSeedMask);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pMaskedSeed);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, hLen);
  MCUXCLMEMORY_XOR_SECURE_INT(pSeedMask, pSeedMask, pMaskedSeed, hLen);

  /************************************************************************************************/
  /* Step 5: Compute dbMask and recover DB                                                        */
  /************************************************************************************************/
  /* Let dbMask = MGF(seed, k - hLen - 1)
   * Note that the seed is in the buffer pSeedMask */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_mgf1(pSession, pHashAlgo, pSeedMask, hLen, dbLen, pDbMask));

  /* Let DB = maskedDB xor dbMask.
   * This is done in-place in pDbMask buffer. DB should contain: lHash' || PS || 0x01 || M */
  uint32_t offsetForWordAlign = (dbLen % 4U) == 0U ? 0U : 4U - (dbLen % 4U);
  /* The in-place xor call only works if the length is word size aligned. It is safe to use at most 3 bytes before pDbMask and pMaskedDB */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pDbMask - offsetForWordAlign);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pDbMask - offsetForWordAlign);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, pMaskedDB - offsetForWordAlign);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_secure_int, dbLen + offsetForWordAlign);
  MCUXCLMEMORY_XOR_SECURE_INT((pDbMask - offsetForWordAlign), (pDbMask - offsetForWordAlign),
                            (pMaskedDB - offsetForWordAlign), (dbLen + offsetForWordAlign));

  /************************************************************************************************/
  /* Step 6: Mask PS and count padding length                                                     */
  /************************************************************************************************/
  /* Generate a random byte */
  MCUX_CSSL_FP_FUNCTION_CALL(random32, mcuxClPrng_generate_word());
  uint8_t rndByte = (uint8_t)(random32 & 0xFFU);

  /* Mask PS || 0x01 || M */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XORWithConst_secure_int, pPsMask);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XORWithConst_secure_int, pPS);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XORWithConst_secure_int, dbLen - hLen);
  MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pPsMask, pPS, rndByte, dbLen - hLen);

  /* Count the length of the zero-padding PS in a masked way */
  uint32_t psLen = 0U;
  while((pPsMask[psLen] == rndByte) && (psLen < (dbLen - hLen - 1U)))
  {
    psLen++;
  }

  /************************************************************************************************/
  /* Step 7: Compute label hash                                                                   */
  /************************************************************************************************/
  /* Calculate the hash of the label: lHash.
   * It partly overwrites the input encoded message, and immediately follows the first byte Y */
  uint32_t hashOutputSize = 0U;

  uint8_t * pLHash = pY + 1U;

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
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_ERROR);
  }

  /************************************************************************************************/
  /* Step 8: Verify Y byte and lHash match                                                        */
  /************************************************************************************************/
  /* Set up the comparison buffer: it starts 1 byte before lHash' (in DB), and its first byte is set to zero */
  uint8_t * pComparison = pDbMask - 1U;
  pComparison[0U] = 0x0U;

  mcuxClMemory_Status_t compare_result = MCUXCLMEMORY_STATUS_NOT_EQUAL;
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, pY);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, pComparison);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, hLen + 1U);
  MCUXCLMEMORY_COMPARE_SECURE_INT(compare_result, pY, pComparison, (hLen + 1U));
  if (MCUXCLMEMORY_STATUS_NOT_EQUAL == compare_result)
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }
  else if (MCUXCLMEMORY_STATUS_EQUAL != compare_result)
  {
    MCUXCLSESSION_FAULT(pSession, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }
  else
  {
     /* Do nothing to meet MISRA */
  }

  /************************************************************************************************/
  /* Step 9: Verify separator byte                                                                */
  /************************************************************************************************/
  /* Check that the separator byte is equal to 0x01 in a masked way */
  if(pPsMask[psLen] != (1U ^ rndByte))
  {
    mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /************************************************************************************************/
  /* Step 10: Extract message and write to output                                                 */
  /************************************************************************************************/
  uint8_t * pM = pPS + psLen + 1U;
  uint32_t outLength = dbLen - hLen - psLen - 1U;
  *pOutLength = outLength;

  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure, pOutput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure, pM);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure, outLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write_secure(pOutput, 0U, pM, outLength));

  /************************************************************************************************/
  /* Step 11: Cleanup and clear sensitive data                                                   */
  /************************************************************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, wordSizeWa);

  /* Clear buffer pM */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(pM, outLength));

  /************************************************************************************************/
  /* Function exit                                                                                 */
  /************************************************************************************************/

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_oaepDecode, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    /* Step 3 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    /* Step 4 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
    MCUXCLMEMORY_XOR_SECURE_INT_FP_EXPECT,
    /* Step 5 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
    MCUXCLMEMORY_XOR_SECURE_INT_FP_EXPECT,
    /* Step 6 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT,
    /* Step 7 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
    /* Step 8 */
    MCUXCLMEMORY_COMPARE_SECURE_INT_FP_EXPECT,
    /* Step 10 */
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_secure),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal)
  );
}
