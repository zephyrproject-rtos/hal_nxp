/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClSignature_sign.c
 *  @brief mcuxClSignature: implementation of mcuxClSignature_sign function
 */


#include <mcuxClSignature.h>

#include <mcuxCsslAnalysis.h>

#include <mcuxClEcc_Types.h>
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
#include <mcuxClOsccaSm2_Types.h>
#endif

#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSignature_Internal.h>

#ifdef MCUXCL_FEATURE_SIGNATURE_ONESHOT
#ifdef MCUXCL_FEATURE_SIGNATURE_SIGN
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSignature_sign)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_sign(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pSignature,
  uint32_t * const pSignatureSize
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSignature_sign);

  MCUX_CSSL_FP_FUNCTION_CALL(sign_status, mode->pSignFct(
    /* mcuxClSession_Handle_t           session:          */  session,
    /* mcuxClKey_Handle_t               key:              */  key,
    /* mcuxClSignature_Mode_t           mode:             */  mode,
    /* mcuxCl_InputBuffer_t             pIn:              */  pIn,
    /* const uint32_t                  inSize:           */  inSize,
    /* mcuxCl_Buffer_t                  pSignature:       */  pSignature,
    /* uint32_t * const                pSignatureSize:   */  pSignatureSize));

  mcuxClSignature_Status_t sign_result_tmp = MCUXCLSIGNATURE_STATUS_FAILURE;

  MCUX_CSSL_ANALYSIS_COVERITY_START_DEVIATE(MISRA_C_2012_Rule_14_3, "intentional, this 'false' is a temporary solution")
  if(
    MCUXCLECC_STATUS_OK == sign_status ||
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
    MCUXCLOSCCASM2_STATUS_OK == sign_status ||
#endif
    false) // This causes a MISRA violation Rule 14.3
  {
    sign_result_tmp = MCUXCLSIGNATURE_STATUS_OK;
  }
  MCUX_CSSL_ANALYSIS_COVERITY_STOP_DEVIATE(MISRA_C_2012_Rule_14_3)


  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClSignature_sign, sign_result_tmp, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK,
    mode->protection_token_sign);
}
#endif /* MCUXCL_FEATURE_SIGNATURE_SIGN */


#ifdef MCUXCL_FEATURE_SIGNATURE_VERIFY
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSignature_verify)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_verify(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClSignature_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_InputBuffer_t pSignature,
  uint32_t signatureSize
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSignature_verify);

  MCUX_CSSL_FP_FUNCTION_CALL(verify_status, mode->pVerifyFct(
    /* mcuxClSession_Handle_t           session:           */  session,
    /* mcuxClKey_Handle_t               key:               */  key,
    /* mcuxClSignature_Mode_t           mode:              */  mode,
    /* mcuxCl_InputBuffer_t             pIn:               */  pIn,
    /* uint32_t                        inSize:            */  inSize,
    /* mcuxCl_InputBuffer_t             pSignature:        */  pSignature,
    /* uint32_t                        signatureSize:     */  signatureSize));

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(
    mcuxClSignature_verify,
    MCUXCLSIGNATURE_TRANSLATE_VERIFY_RETURN_CODE(verify_status),
    MCUXCLSIGNATURE_STATUS_FAULT_ATTACK,
    mode->protection_token_verify);

}
#endif /* MCUXCL_FEATURE_SIGNATURE_VERIFY */
#endif /* MCUXCL_FEATURE_SIGNATURE_ONESHOT */


#ifdef MCUXCL_FEATURE_SIGNATURE_SELFTEST
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSignature_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClSignature_selftest(
  mcuxClSession_Handle_t session,
  mcuxClSignature_Mode_t mode,
  mcuxClSignature_Test_t test
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSignature_selftest);

  MCUX_CSSL_FP_FUNCTION_CALL(selftest_status, test->pSelfTestFct(
    /* mcuxClSession_Handle_t            session:             */  session,
    /* mcuxClSignature_Mode_t            mode:                */  mode));

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClSignature_selftest, selftest_status, MCUXCLSIGNATURE_STATUS_FAULT_ATTACK,
    test->protection_token_selftest);
}
#endif /* MCUXCL_FEATURE_SIGNATURE_SELFTEST */


