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

/** @file  mcuxClRsa_Pkcs1v15Encode_sign.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PKCS1-v1_5-ENCODE
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClBuffer.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>

#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_Set_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>

#include <mcuxClRsa.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Encode_sign, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Encode_sign(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength UNUSED_PARAM,
  uint8_t *                   pVerificationInput UNUSED_PARAM,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel UNUSED_PARAM,
  const uint32_t              saltlabelLength UNUSED_PARAM,
  const uint32_t              keyBitLength,
  const uint32_t              options UNUSED_PARAM,
  mcuxCl_Buffer_t              pOutput,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pkcs1v15Encode_sign);
  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Length of the encoded message. */
  const uint32_t emLen = keyBitLength / 8U;  /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  /* Length of the output of hash function. */
  const uint32_t hLength = pHashAlgo->hashSize;

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hLength, MCUXCLRSA_HASH_MIN_SIZE, MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_STATUS_INVALID_INPUT)
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  /* Length of the T-padding containing the hash algorithm identifier. */
  uint8_t const * phashAlgorithmIdentifier     = pHashAlgo->pOid;
  /* Length of the T-padding DigestInfo containing the hash algorithm identifier. */
  const uint32_t hashAlgorithmIdentifierLength = pHashAlgo->oidSize;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(hashAlgorithmIdentifierLength, MCUXCLHASH_OID_SHA1_LEN, MCUXCLHASH_OID_SHA2SHA3_LEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  /*****************************************************/
  /* If emLen < tLen + 11, return 'invalid input'.     */
  /*****************************************************/
  if(emLen < (hashAlgorithmIdentifierLength + hLength + 11U))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLRSA_STATUS_INVALID_INPUT);
  }

  /*****************************************************/
  /* Prepare the padding                               */
  /*****************************************************/
  /* Number of required padding bytes */
  const uint32_t paddingLength = emLen - hashAlgorithmIdentifierLength - hLength - 3U;

  /* Setup session. */
  const uint32_t wordSizePkcWa = MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WAPKC_SIZE(emLen) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa));

  /*
   * Set buffers in PKC workarea
   * PKC = | 0x00 || 0x01 || PS || 0x00 | T || H |
   */
  /* General pointer to encoded message at the beginning of the buffer */
  uint8_t *pEm = pPkcWorkarea;
  /* Pointer to the buffer for the padding bytes PS */
  uint8_t *pPs = pEm + 2U;
  /* Pointer to the buffer for the algorithm identifier T */
  uint8_t *pT = pPs + paddingLength + 1U;

  /* Pointer to the buffer for the hash H */
  uint8_t *pH = pT + hashAlgorithmIdentifierLength;


  /* Write 0x00 0x01 prefix */
  *(pEm)     = (uint8_t) 0x00;
  *(pEm + 1U) = (uint8_t) 0x01;

  /* Write padding bytes */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_set_int_ps, pPs);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_set_int_ps, paddingLength);
  MCUXCLMEMORY_SET_INT(pPs, 0xFFU, paddingLength);

  /* Write 0x00 divider */
  *(pPs + paddingLength) = (uint8_t) 0x00;

  /* Write DigestInfo T */
  MCUX_CSSL_DI_RECORD(memCopyT, pT);
  MCUX_CSSL_DI_RECORD(memCopyT, phashAlgorithmIdentifier);
  MCUX_CSSL_DI_RECORD(memCopyT, hashAlgorithmIdentifierLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pT, phashAlgorithmIdentifier, hashAlgorithmIdentifierLength));

  /*****************************************************/
  /* Copy the digest                                   */
  /*****************************************************/
  /* Copy pInput to buffer at pH (located at the end of the buffer) */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pInput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pH);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, hLength);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pInput, 0U, pH, hLength));

  /*****************************************************/
  /* Prepare the encoded message for output            */
  /*****************************************************/

  /* Copy encoded message to pOutput and switch the endianness */
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure_reverse, pOutput);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure_reverse, pPkcWorkarea);
  MCUX_CSSL_DI_RECORD(mcuxClBuffer_write_secure_reverse, emLen);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write_secure_reverse(pOutput, 0U, pPkcWorkarea, emLen));

  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

  /************************************************************************************************/
  /* Function exit                                                                                */
  /************************************************************************************************/
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Encode_sign, MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
      MCUXCLMEMORY_SET_INT_FP_EXPECT,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write_secure_reverse)
  );

}
