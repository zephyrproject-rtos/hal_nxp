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

#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>

#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClCipher_Internal.h>

#include <mcuxCsslDataIntegrity.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_crypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_crypt(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipher_crypt);

  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION("The required fields in mcuxClCipherModFunctions_t are declared using the macro MCUXCLCIPHER_CRYPT_MODEFUNCTIONS");
  const mcuxClCipher_ModeFunctions_t *pModeFunctions = (const mcuxClCipher_ModeFunctions_t *)mode->pModeFunctions;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION();
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->crypt(
                                              session,
                                              NULL, /* pContext */
                                              key,
                                              mode,
                                              pIv,
                                              ivLength,
                                              pIn,
                                              inLength,
                                              pOut,
                                              pOutLength,
                                              MCUXCLCIPHER_OPTION_ONESHOT));
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClCipher_crypt, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK,
    pModeFunctions->protection_token_crypt);

}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_init(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipher_init);

  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION("The required fields in mcuxClCipherModFunctions_t are declared using the macro MCUXCLCIPHER_CRYPT_MODEFUNCTIONS");
  const mcuxClCipher_ModeFunctions_t *pModeFunctions = (const mcuxClCipher_ModeFunctions_t *)mode->pModeFunctions;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION();
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->crypt(
                                              session,
                                              pContext,
                                              key,
                                              mode,
                                              pIv,
                                              ivLength,
                                              NULL, /* pIn */
                                              0u,   /* inLength */
                                              NULL, /* pOut */
                                              0u,   /* pOutLength */
                                              MCUXCLCIPHER_OPTION_INIT));
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClCipher_init, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK,
    pModeFunctions->protection_token_crypt);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_process(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipher_process);

  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION("The required fields in mcuxClCipherModFunctions_t are declared using the macro MCUXCLCIPHER_CRYPT_MODEFUNCTIONS");
  const mcuxClCipher_ModeFunctions_t *pModeFunctions = (const mcuxClCipher_ModeFunctions_t *)pContext->pMode->pModeFunctions;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION();
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("NULL arguments are not dereferenced during process step MCUXCLCIPHER_OPTION_PROCESS")
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->crypt(
                                              session,
                                              pContext,
                                              NULL, /* pKey, is already stored in context */
                                              NULL, /* pMode, is already stored in context */
                                              NULL, /* pIv */
                                              0u,   /* ivLength */
                                              pIn,
                                              inLength,
                                              pOut,
                                              pOutLength,
                                              MCUXCLCIPHER_OPTION_PROCESS));
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClCipher_process, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK,
    pModeFunctions->protection_token_crypt);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_finish(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipher_finish);

  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION("The required fields in mcuxClCipherModFunctions_t are declared using the macro MCUXCLCIPHER_CRYPT_MODEFUNCTIONS");
  const mcuxClCipher_ModeFunctions_t *pModeFunctions = (const mcuxClCipher_ModeFunctions_t *)pContext->pMode->pModeFunctions;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_VOIDPTR_TO_FUNCTION();
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_ANALYSIS_START_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("NULL arguments are not dereferenced during finish step MCUXCLCIPHER_OPTION_FINISH")
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->crypt(
                                              session,
                                              pContext,
                                              NULL, /* pKey, is already stored in context */
                                              NULL, /* pMode, is already stored in context */
                                              NULL, /* pIv */
                                              0u,   /* ivLength */
                                              NULL, /* pIn */
                                              0u,   /* inLength */
                                              pOut,
                                              pOutLength,
                                              MCUXCLCIPHER_OPTION_FINISH));
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_NULL_POINTER_CONSTANT()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClCipher_finish, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK,
    pModeFunctions->protection_token_crypt);
}


