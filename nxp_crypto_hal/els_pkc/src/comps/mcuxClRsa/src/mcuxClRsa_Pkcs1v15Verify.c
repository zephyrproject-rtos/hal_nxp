/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClRsa_Pkcs1v15Verify.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PKCS1-v1_5-VERIFY
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslMemory.h>

#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClBuffer.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClSession_Internal.h>


#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>

/**********************************************************/
/* Specifications of PKCS#1 v1.5 mode structures          */
/**********************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_224 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Verify),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha224,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Verify
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_256 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Verify),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha256,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Verify
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_384 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Verify),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha384,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Verify
};

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClRsa_SignVerifyMode_t mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_512 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .EncodeVerify_FunId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Verify),
    .pHashAlgo1         = &mcuxClHash_AlgorithmDescriptor_Sha512,
    .pHashAlgo2         = NULL,
    .pPaddingFunction   = mcuxClRsa_pkcs1v15Verify
};

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Verify, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Verify(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength,
  uint8_t *                   pVerificationInput,
  mcuxClHash_Algo_t            pHashAlgo,
  mcuxCl_InputBuffer_t         pLabel,
  const uint32_t              saltlabelLength,
  const uint32_t              keyBitLength,
  const uint32_t              options,
  mcuxCl_Buffer_t              pOutput UNUSED_PARAM,
  uint32_t * const            pOutLength UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_pkcs1v15Verify);
  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Length of the encoded message. */
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT(keyBitLength, (MCUXCLKEY_SIZE_1024 / 8u), (MCUXCLKEY_SIZE_8192 / 8u), MCUXCLRSA_STATUS_INVALID_INPUT)
  const uint32_t keyByteLength = (keyBitLength + 7u) / 8u; /* byte length, rounded up */
  const uint32_t emLen = keyByteLength;

  const uint32_t pkcByteLenEm = MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(emLen);
  const uint32_t wordSizePkcWa = pkcByteLenEm / (sizeof(uint32_t));

  /* Setup session with buffer for encoding result. */
  uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa);

  if (NULL == pPkcWorkarea)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Verify, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }

  /*****************************************************/
  /* Perform pkcs1v15Encode                            */
  /*****************************************************/
  MCUXCLBUFFER_INIT(pPkcWorkareaBuf, pSession, pPkcWorkarea, wopkcByteLenEm);
  MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_FP_FUNCTION_CALL(encode_result, mcuxClRsa_pkcs1v15Encode_sign(pSession,
                                                                   pInput,
                                                                   inputLength,
                                                                   NULL,
                                                                   pHashAlgo,
                                                                   pLabel,
                                                                   saltlabelLength,
                                                                   keyBitLength,
                                                                   options,
                                                                   pPkcWorkareaBuf,
                                                                   NULL));
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
  if(MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK != encode_result)
  {
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Verify, MCUXCLRSA_STATUS_ERROR);
  }

  /*****************************************************/
  /* Compare results                                   */
  /*****************************************************/

  mcuxClRsa_Status_t verifyStatus1 = MCUXCLRSA_STATUS_FAULT_ATTACK;
  MCUX_CSSL_FP_FUNCTION_CALL(compare_result, mcuxCsslMemory_Compare(
    mcuxCsslParamIntegrity_Protect(3u, pPkcWorkarea, pVerificationInput, emLen),
      pPkcWorkarea,
      pVerificationInput,
      emLen
    ));

  if(MCUXCSSLMEMORY_STATUS_EQUAL != compare_result)
  {
    if(MCUXCSSLMEMORY_STATUS_NOT_EQUAL == compare_result)
    {
      verifyStatus1 = MCUXCLRSA_STATUS_VERIFY_FAILED;
    }
    else
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Verify, MCUXCLRSA_STATUS_ERROR);
    }
  } else {
    if(MCUXCSSLMEMORY_STATUS_NOT_EQUAL != compare_result)
    {
      verifyStatus1 = MCUXCLRSA_STATUS_VERIFY_OK;
    }
    else
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Verify, MCUXCLRSA_STATUS_ERROR);
    }
  }


  /*****************************************************/
  /* Cleanup & Exit                                    */
  /*****************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

  #define FP_RSA_PKCS1V15VERIFY_COMPARISON_1 \
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)

#define FP_RSA_PKCS1V15VERIFY_COMPARISON FP_RSA_PKCS1V15VERIFY_COMPARISON_1

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Verify, verifyStatus1,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign), \
    FP_RSA_PKCS1V15VERIFY_COMPARISON);

}

