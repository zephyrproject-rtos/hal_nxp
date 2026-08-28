/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/** @file  mcuxClRsa_PssVerify.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PSS-VERIFY
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClBuffer.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClMemory_Internal.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

#include <internal/mcuxClBuffer_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>


  #define FP_RSA_PSSVERIFY_COMPARISON MCUXCLMEMORY_COMPARE_SECURE_INT_FP_EXPECT

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pssVerify, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssVerify(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength UNUSED_PARAM,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput UNUSED_PARAM,
  uint32_t * const            pOutLength UNUSED_PARAM)
{

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pssVerify);
  (void)options;

  /* Setup session. */

  /* Length of the encoded message. */
  const uint32_t emLen = keyBitLength / 8U; /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  /* Length of padding with 8 zero bytes. */
  const uint32_t padding1Length = MCUXCLRSA_PSS_PADDING1_LEN;
  /* Length of the output of hash function. */
  const uint32_t hLen = pHashAlgo->hashSize;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hLen, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, hLen + 1U, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  /* Length of the EMSA-PSS salt. */
  const uint32_t sLen = saltlabelLength;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(sLen, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  /* Length of DB (and maskedDB). */
  const uint32_t dbLen = emLen - hLen - 1U;

  const uint16_t wordSizePkcWa = (uint16_t)(MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WAPKC_SIZE_WO_MGF1(emLen) / sizeof(uint32_t));
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa));

  /*
   * Set buffers in PKC workarea
   * PKC = | M'= (padding | mHash | salt) || dbMask (and DB) || H' | EM |
   */
  /* Pointer to the buffer for the M' = | padding_1 | mHash | salt | */
  uint8_t *pMprim = pPkcWorkarea;
  /* Pointer to the buffer for the mHash in the M'*/
  uint8_t *pMHash = pMprim + padding1Length;
  /* Pointer to the buffer for the salt in the M'*/
  uint8_t *pSalt = pMHash + hLen;

  /* Pointer to the buffer for the dbMask' (must be aligned to CPU word size)*/
  uint8_t *pDbMask = pSalt + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sLen);
  /* Pointer to the encoded message (must be aligned to CPU word size) */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("dbLen + hLen + 4U can't wrap because dbLen + hLen < emLen < MCUXCLRSA_MAX_MODLEN, and MCUXCLRSA_MAX_MODLEN < UINT32_MAX")
  uint8_t *pEm = &pDbMask[MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(dbLen + hLen)];
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
  /* Pointer to the buffer for the H' */
  uint8_t *pHprim = pDbMask + dbLen;

  const uint32_t mprimLen = padding1Length + hLen + sLen;

  /* Copy contents of pVerificationInput into pEm in big-endian byte order */
  MCUX_CSSL_DI_RECORD(memCopyRevintParams, pEm);
  MCUX_CSSL_DI_RECORD(memCopyRevintParams, pVerificationInput);
  MCUX_CSSL_DI_RECORD(memCopyRevintParams, emLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(pEm, pVerificationInput, emLen));

  /* Step 2: Let mHash = Hash(M), an octet string of length hLen.
   * Copy pInput to buffer mHash. */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pMHash);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pInput, 0U, pMHash, hLen));

  /* Step 3: If BYTE_LENGTH(keyBitLength) < (pHashAlgo->hashSize + saltlabelLength + 2)
   * return MCUXCLRSA_STATUS_VERIFY_FAILED else continue operation. */
  /* The constraint on sLen for FIPS186-5 is always met, so no additional check is needed. In step 10, we check that the zero-padding has the expected length w.r.t. sLen. */
  /* Step 4: Check if the rightmost octet of Em (after endianness switch) has hexadecimal value 0xbc.*/
  /* Step 6: Check if 8*emLen-emBits leftmost bits (after endianness switch) equal to zero. Note that, as keyBitLength is a multiple of 8, 8 * emLen - emBits = 1 bit.*/

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hLen, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, hLen + 1U, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  if(((hLen < sLen)) || (emLen < (hLen + sLen + 2U)) || (0xbcU != pEm[emLen - 1U]) || (0U != (pEm[0] & 0x80u)))
  {
    /* Normal exit with MCUXCLRSA_STATUS_VERIFY_FAILED */
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_DI_EXPUNGE(verifyPadMsg, pVerificationInput);
    MCUX_CSSL_DI_RECORD(verifyRetCode, MCUXCLRSA_STATUS_VERIFY_FAILED);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_VERIFY_FAILED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read)
    );
  }

  /* Step 5: Let maskedDB be the leftmost emLen-hLen-1 octets of EM and let H be the next hLen octets. */
  uint8_t *maskedDB = pEm;
  uint8_t *pH = pEm + dbLen;
  MCUX_CSSL_DI_RECORD(verifyMaskedDB, (uint32_t) pEm);
  MCUX_CSSL_DI_RECORD(verifyH, (uint32_t) pEm + dbLen);

  /* Step 7: dbMask = MGF(H, BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - 1) */

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_mgf1(pSession, pHashAlgo, pH, hLen, dbLen, pDbMask));

  /* Step 8: DB = pOutput(0 : BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - 1) XOR dbMask.*/
  uint8_t *pDB = pDbMask; // reuse the space of DbMask
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, pDB);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, maskedDB);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, pDbMask);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_XOR_int, dbLen);
  MCUXCLMEMORY_XOR_INT(pDB, maskedDB, pDbMask, dbLen);
  MCUX_CSSL_DI_EXPUNGE(verifyMaskedDB, (uint32_t) maskedDB);

  /* Step 9: Set the leftmost 8emLen - emBits bits of the leftmost octet in DB to zero. */
  pDB[0] &= 0x7FU;

  /* Step 10 */
  /* Check (DB(0 : BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - saltlabelLength - 2) == [0x00, ..., 0x00])
   * and that (DB(BYTE_LENGTH(keyBitLength) - pHashAlgo->hashSize - saltlabelLength - 1) == 0x01) ? */
  uint32_t counterZeros = 0U;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, (hLen + sLen + 2U), MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t padding2Length = emLen - hLen - sLen - 2U;
  MCUX_CSSL_FP_LOOP_DECL(loop2);
  for(uint32_t i = 0U; i < padding2Length; ++i)
  {
    if(0U == pDB[i])
    {
      MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(counterZeros, 0U, padding2Length, MCUXCLRSA_STATUS_INVALID_INPUT)
      ++counterZeros;
    }
    MCUX_CSSL_FP_LOOP_ITERATION(loop2);
    MCUX_CSSL_DI_RECORD(verifyPaddingLoop, 1U);
  }
  if((counterZeros != padding2Length) || (0x01U != pDB[padding2Length]))
  {
    /* Normal exit with MCUXCLRSA_STATUS_VERIFY_FAILED */
    mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

    MCUX_CSSL_DI_EXPUNGE(verifyPadMsg, (uint32_t) pVerificationInput);
    MCUX_CSSL_DI_EXPUNGE(verifyH, (uint32_t) pH);
    MCUX_CSSL_DI_EXPUNGE(verifyPaddingLoop, padding2Length);
    MCUX_CSSL_DI_RECORD(verifyRetCode, MCUXCLRSA_STATUS_VERIFY_FAILED);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, MCUXCLRSA_STATUS_VERIFY_FAILED,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
        MCUXCLMEMORY_XOR_INT_FP_EXPECT,
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, padding2Length)
    );
  }

  /* Step 11: Copy salt from DB to M' */
  MCUX_CSSL_DI_RECORD(memCopySalt, pSalt);
  MCUX_CSSL_DI_RECORD(memCopySalt, pDB + dbLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pSalt, pDB + dbLen - sLen, sLen));

  /* Step 12 */
  /* mPrime = [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 || mHash || DB(BYTE_LENGTH(keyBitLength) - saltlabelLength: BYTE_LENGTH(keyBitLength))] */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_mPrim, pMprim);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_mPrim, padding1Length);
  MCUXCLMEMORY_CLEAR_INT(pMprim, padding1Length);

  /* Step 13: HPrime = Hash(mPrime) */
  uint32_t hashOutputSize = 0U;
  MCUXCLBUFFER_INIT_RO(pMprimBuf, NULL, pMprim, padding1Length);
  MCUXCLBUFFER_INIT(pHprimBuf, NULL, pHprim, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL(
    hash_result_2,
    mcuxClHash_compute(pSession, pHashAlgo, pMprimBuf, mprimLen, pHprimBuf, &hashOutputSize)
  );
  /* mcuxClHash_compute is an public function. Hence check session error/fault and handle accordingly */
  MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, hash_result_2);

  /* Step 14 verify5 = (HPrime == H) ? true : false. */

  /* DI: pH has been recorded before */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, pHprim);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, hLen);

  mcuxClRsa_Status_t pssVerifyStatus1 = MCUXCLRSA_STATUS_FAULT_ATTACK;
  mcuxClMemory_Status_t compare_result = MCUXCLMEMORY_STATUS_NOT_EQUAL;
  MCUXCLMEMORY_COMPARE_SECURE_INT(compare_result, pH, pHprim, hLen);
  if (MCUXCLMEMORY_STATUS_EQUAL == compare_result)
  {
    pssVerifyStatus1 = MCUXCLRSA_STATUS_VERIFY_OK;
  }
  else if (MCUXCLMEMORY_STATUS_NOT_EQUAL == compare_result)
  {
    pssVerifyStatus1 = MCUXCLRSA_STATUS_VERIFY_FAILED;
  }
  else
  {
    MCUXCLSESSION_FAULT(pSession, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }


  /* Protect VERIFY_OK and VERIFY_FAILED only. Functional errors or fault attack are not protected.*/
  MCUX_CSSL_DI_RECORD(verifyRetCode, pssVerifyStatus1);

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

  MCUX_CSSL_DI_EXPUNGE(verifyPadMsg, (uint32_t) pVerificationInput);
  MCUX_CSSL_DI_EXPUNGE(verifyPaddingLoop, padding2Length);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssVerify, pssVerifyStatus1,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
      MCUXCLMEMORY_XOR_INT_FP_EXPECT,
      MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, padding2Length),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
      MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
      FP_RSA_PSSVERIFY_COMPARISON
  );

#undef FP_RSA_PSSVERIFY_COMPARISON

}
