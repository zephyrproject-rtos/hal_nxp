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

/** @file  mcuxClRsa_PssEncode.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PSS-ENCODE
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClBuffer.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClRandom_Internal_Functions.h>

#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pssEncode, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pssEncode(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength UNUSED_PARAM,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pssEncode);

  /* Length of the encoded message. */
  const uint32_t emLen = keyBitLength / 8U; /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  /* Length of padding with 8 zero bytes. */
  const uint32_t padding1Length = MCUXCLRSA_PSS_PADDING1_LEN;
  /* Length of the output of hash function. */
  const uint32_t hLen = pHashAlgo->hashSize;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hLen, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  /* Length of the EMSA-PSS salt. */
  const uint32_t sLen = saltlabelLength;

  /* Step 3: If emLen < hLen + sLen + 2, output "encoding error" and stop. */
  /*
   * Here: If BYTE_LENGTH(keyBitLength) < (pHashAlgo->hashSize + saltlabelLength + 2)
   *  return MCUXCLRSA_STATUS_INVALID_INPUT else continue operation.
   *
   * Note: The check in Step 3 is moved here at the top of the function, since all lengths are already known.
   * Thus, no unnecessary hashing is performed in case of invalid input.
   * In addition, this ensures that this check is done before any operation on checked arguments is performed.
   *
   * Note: The additional check on salt-length for FIPS 186-5 compliance is also done here.
   */

  if((hLen < sLen) || (emLen < (hLen + sLen + 2U)))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /* Length of M' */
  const uint32_t mprimLen = padding1Length + hLen + sLen;
  /* Length of DB (and maskedDB). */
  const uint32_t dbLen = emLen - hLen - 1U;
  /* Length of PS padding */
  const uint32_t padding2Length = emLen - hLen - sLen - 2U;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(padding2Length, 0U, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)
  /* Length of PS padding plus one 0x01 byte */
  const uint32_t padding3Length = padding2Length + 1U;

  /*
   * Set buffers in the PKC workarea
   * PKC = | M' | EM | H
   * M' = | M'= (padding | mHash | salt) |
   */
  const uint32_t wordSizePkcWa = MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WAPKC_SIZE_WO_MGF1(emLen) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pMprim, mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa));

  /* Pointer to the buffer for the mHash in the M'*/
  uint8_t *pMHash = pMprim + padding1Length;
  /* Pointer to the buffer for the salt in the M'*/
  uint8_t *pSalt = pMHash + hLen;

  /* Pointer to the encoded message */
  uint8_t *pEm = pSalt + sLen;
  /* Pointer to the hash */
  uint8_t *pH = pEm + dbLen;

  /* Note: Step 1 from EMSA-PSS-VERIFY in PKCS #1 v2.2 can be avoided because messageLength
   * of function mcuxClRsa_sign is of type uint32_t and thus limited to 32 bits.
   */

  /* Step 2: Let mHash = Hash(M), an octet string of length hLen.
   * Copy pInput to buffer mHash */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pInput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pMHash);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pInput, 0U, pMHash, hLen));

  /* Step 4: Generate a random octet string salt of length sLen; if sLen = 0, then salt is the empty string. */
  MCUXCLBUFFER_INIT(pBufSalt, NULL, pSalt, sLen);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, pSession);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, pBufSalt);
  MCUX_CSSL_DI_RECORD(randomGenerateParams, sLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandom_generate_internal(pSession, pBufSalt, sLen, NULL));

  /* Step 5: Let M' = (0x)00 00 00 00 00 00 00 00 || mHash || salt; */
  /* M' is an octet string of length 8 + hLen + sLen with eight initial zero octets. */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_mPrim, pMprim);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_mPrim, padding1Length);
  MCUXCLMEMORY_CLEAR_INT(pMprim, padding1Length);

  /* Step 6: Let H = Hash(M'), an octet string of length hLen. */
  uint32_t hashOutputSize = 0U;

  MCUXCLBUFFER_INIT_RO(pMprimBuf, NULL, pMprim, padding1Length);
  MCUXCLBUFFER_INIT(pHBuf, NULL, pH, hLen);
  MCUX_CSSL_FP_FUNCTION_CALL(hash_result_2, mcuxClHash_compute(pSession,
                                                             pHashAlgo,
                                                             pMprimBuf,
                                                             mprimLen,
                                                             pHBuf,
                                                             &hashOutputSize
                                                             ));
  /* mcuxClHash_compute is an public function. Hence check session error/fault and handle accordingly */
  MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, hash_result_2);

  /* Step 9: Let dbMask = MGF(H, emLen - hLen - 1). */
  /* Note: Step 9 has been moved up. Compute the MGF first and store the resulting mask directly in the
   * output buffer, where it is adjusted afterwards. This saves temporary buffer space and copy operations.
   */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_mgf1(pSession, pHashAlgo, pH, hLen, dbLen, pEm));

  /* Step 7: Generate an octet string PS consisting of emLen - sLen - hLen - 2 zero octets. */
  /* The length of PS may be 0. */
  /* Step 8: Let DB = PS || 0x01 || salt; DB is an octet string of length emLen - hLen - 1. */
  /* Step 10:  Let maskedDB = DB \xor dbMask. */

  /* PS consists of zeros only, so the first len(PS) bytes in the output buffer can be left as
   * they are because XOR with zero does not change the values.
   * The other items in DB, 0x01 and the salt, will be XORed directly onto the output buffer.
   */

  /* XOR 0x01 to the output buffer at the corresponding position. */
  *(pEm + padding2Length) ^= 0x01U;

  /* XOR the salt to the output buffer at the corresponding positions. */
  MCUX_CSSL_DI_RECORD(memXORintParams, pEm + padding3Length);
  MCUX_CSSL_DI_RECORD(memXORintParams, pEm + padding3Length);
  MCUX_CSSL_DI_RECORD(memXORintParams, pSalt);
  MCUX_CSSL_DI_RECORD(memXORintParams, sLen);
  MCUXCLMEMORY_XOR_INT(pEm + padding3Length, pEm + padding3Length, pSalt, sLen);

  /* Step 11:  Set the leftmost 8emLen - emBits bits of the leftmost octet in maskedDB to zero. */
  /* Since we assume the key length to be a multiple of 8, this becomes simply the leftmost bit. */

  *(pEm) &= 0x7fU;

  /* Step 12:  Let EM = maskedDB || H || 0xbc. */

  *(pEm + emLen - 1U) = 0xbcU;

  /* Step 13:  Output EM. */
  /* Write pEm in little-endian byte order to pOutput. */
  MCUX_CSSL_DI_RECORD(memCopyRevintParams, pOutput);
  MCUX_CSSL_DI_RECORD(memCopyRevintParams, pEm);
  MCUX_CSSL_DI_RECORD(memCopyRevintParams, emLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write_reverse(pOutput, 0U, pEm, emLen));

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pssEncode, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate_internal),
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_compute),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_mgf1),
    MCUXCLMEMORY_XOR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_reverse));

#undef TMP_FEATURE_ELS_RNG
}
