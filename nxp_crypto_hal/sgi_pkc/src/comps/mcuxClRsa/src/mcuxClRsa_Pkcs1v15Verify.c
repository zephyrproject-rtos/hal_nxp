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

/** @file  mcuxClRsa_Pkcs1v15Verify.c
 *  @brief mcuxClRsa: function, which is called to execute EMSA-PKCS1-v1_5-VERIFY
 */

#include <stdint.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClMemory_CompareSecure_Internal.h>

#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClBuffer.h>
#include <mcuxClRsa.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>


#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_pkcs1v15Verify, mcuxClRsa_PadVerModeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRsa_Status_t) mcuxClRsa_pkcs1v15Verify(
  mcuxClSession_Handle_t       pSession,
  mcuxCl_InputBuffer_t         pInput,
  const uint32_t              inputLength UNUSED_PARAM,
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
  const uint32_t keyByteLength = keyBitLength/ 8U; /* only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8 */
  const uint32_t emLen = keyByteLength;
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(emLen, MCUXCLRSA_MIN_MODLEN, MCUXCLRSA_MAX_MODLEN, MCUXCLRSA_STATUS_INVALID_INPUT)

  const uint32_t wordSizePkcWa = MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_ENC_BUFF_WAPKC_SIZE(emLen) / (sizeof(uint32_t));

  /* Setup session with buffer for encoding result. */
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, wordSizePkcWa));

  /*****************************************************/
  /* Perform pkcs1v15Encode                            */
  /*****************************************************/
  MCUXCLBUFFER_INIT(pPkcWorkareaBuf, pSession, pPkcWorkarea, wopkcByteLenEm);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_encode_sign, mcuxClRsa_pkcs1v15Encode_sign(
    pSession,
    pInput,
    0U,
    NULL,
    pHashAlgo,
    pLabel,
    saltlabelLength,
    keyBitLength,
    options,
    pPkcWorkareaBuf,
    NULL
  ));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()

  (void) retVal_encode_sign;

  /* pInput must be recorded by the caller */
  MCUX_CSSL_DI_EXPUNGE(verifyInput, pInput);

  /*****************************************************/
  /* Compare results                                   */
  /*****************************************************/

  /* DI: pVerificationInput is recorded in the caller */
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, pPkcWorkarea);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_compare_secure_int, emLen);

  mcuxClRsa_Status_t verifyStatus1 = MCUXCLRSA_STATUS_FAULT_ATTACK;
  mcuxClMemory_Status_t compare_result = MCUXCLMEMORY_STATUS_NOT_EQUAL;
  MCUXCLMEMORY_COMPARE_SECURE_INT(compare_result, pPkcWorkarea, pVerificationInput, emLen);
  if (MCUXCLMEMORY_STATUS_EQUAL == compare_result)
  {
    verifyStatus1 = MCUXCLRSA_STATUS_VERIFY_OK;
  }
  else if (MCUXCLMEMORY_STATUS_NOT_EQUAL == compare_result)
  {
    verifyStatus1 = MCUXCLRSA_STATUS_VERIFY_FAILED;
  }
  else
  {
    MCUXCLSESSION_FAULT(pSession, MCUXCLRSA_STATUS_FAULT_ATTACK);
  }


  /* Protect VERIFY_OK and VERIFY_FAILED only. Functional errors or fault attack are not protected.*/
  MCUX_CSSL_DI_RECORD(verifyRetCode, verifyStatus1);

  /*****************************************************/
  /* Cleanup & Exit                                    */
  /*****************************************************/
  mcuxClSession_freeWords_pkcWa(pSession, wordSizePkcWa);

#define FP_RSA_PKCS1V15VERIFY_COMPARISON MCUXCLMEMORY_COMPARE_SECURE_INT_FP_EXPECT

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_pkcs1v15Verify, verifyStatus1,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_pkcs1v15Encode_sign),
    FP_RSA_PKCS1V15VERIFY_COMPARISON
  );
}

