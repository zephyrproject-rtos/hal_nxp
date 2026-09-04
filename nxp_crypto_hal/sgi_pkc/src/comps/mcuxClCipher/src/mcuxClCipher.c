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

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_castToCipherModeFunctions)
static const mcuxClCipher_ModeFunctions_t* mcuxClCipher_castToCipherModeFunctions(const void* pModeFunctions)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (const mcuxClCipher_ModeFunctions_t*) pModeFunctions;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_encrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_encrypt(
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
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_encrypt, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  const mcuxClCipher_ModeFunctions_t *pModeFunctions = mcuxClCipher_castToCipherModeFunctions(mode->pModeFunctions);

  *pOutLength = 0U;
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->encrypt(
    session,
    key,
    mode,
    pIv,
    ivLength,
    pIn,
    inLength,
    pOut,
    pOutLength));

  MCUXCLSESSION_EXIT(session, mcuxClCipher_encrypt, diRefValue, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK, pModeFunctions->protection_token_encrypt);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_decrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_decrypt(
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
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_decrypt, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  const mcuxClCipher_ModeFunctions_t *pModeFunctions = mcuxClCipher_castToCipherModeFunctions(mode->pModeFunctions);

  *pOutLength = 0U;
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->decrypt(
    session,
    key,
    mode,
    pIv,
    ivLength,
    pIn,
    inLength,
    pOut,
    pOutLength));

  /* Only STATUS_OK is protected */
  if(MCUXCLCIPHER_STATUS_OK == status)
  {
    MCUX_CSSL_DI_EXPUNGE(cipherDecryptRetCode, status);
  }

  MCUXCLSESSION_EXIT(session, mcuxClCipher_decrypt, diRefValue, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK, pModeFunctions->protection_token_decrypt);
}

#ifdef MCUXCL_FEATURE_CIPHER_SELFTEST
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_selftest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_selftest(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Mode_t mode,
  mcuxClCipher_Test_t test
)
{
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_selftest, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(test->selftest(session, mode));

  MCUXCLSESSION_EXIT(session, mcuxClCipher_selftest, diRefValue, MCUXCLCIPHER_STATUS_OK, MCUXCLCIPHER_STATUS_FAULT_ATTACK, test->protection_token_selftest);
}
#endif /* MCUXCL_FEATURE_CIPHER_SELFTEST */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_init_encrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_init_encrypt(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
)
{
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_init_encrypt, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  /* Store mode in common context */
  pContext->pMode = mode;
  pContext->blockBufferUsed = 0U;
  pContext->totalInputLength = 0U;

  const mcuxClCipher_ModeFunctions_t *pModeFunctions = mcuxClCipher_castToCipherModeFunctions(pContext->pMode->pModeFunctions);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pModeFunctions->initEncrypt(
    session,
    pContext,
    key,
    pIv,
    ivLength));

  MCUXCLSESSION_EXIT(session, mcuxClCipher_init_encrypt, diRefValue, MCUXCLCIPHER_STATUS_OK, MCUXCLCIPHER_STATUS_FAULT_ATTACK, pModeFunctions->protection_token_initencrypt);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_init_decrypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_init_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
)
{
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_init_decrypt, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  /* Store mode in common context */
  pContext->pMode = mode;
  pContext->blockBufferUsed = 0U;
  pContext->totalInputLength = 0U;

  const mcuxClCipher_ModeFunctions_t *pModeFunctions = mcuxClCipher_castToCipherModeFunctions(pContext->pMode->pModeFunctions);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pModeFunctions->initDecrypt(
    session,
    pContext,
    key,
    pIv,
    ivLength));

  MCUXCLSESSION_EXIT(session, mcuxClCipher_init_decrypt, diRefValue, MCUXCLCIPHER_STATUS_OK, MCUXCLCIPHER_STATUS_FAULT_ATTACK, pModeFunctions->protection_token_initdecrypt);

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
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_process, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  const mcuxClCipher_ModeFunctions_t *pModeFunctions = mcuxClCipher_castToCipherModeFunctions(pContext->pMode->pModeFunctions);

  *pOutLength = 0U;
  MCUX_CSSL_FP_FUNCTION_CALL(status, pModeFunctions->process(
    session,
    pContext,
    pIn,
    inLength,
    pOut,
    pOutLength));

  MCUXCLSESSION_EXIT(session, mcuxClCipher_process, diRefValue, status, MCUXCLCIPHER_STATUS_FAULT_ATTACK, pModeFunctions->protection_token_process);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipher_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipher_finish(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
  MCUXCLSESSION_ENTRY(session, mcuxClCipher_finish, diRefValue, MCUXCLCIPHER_STATUS_FAULT_ATTACK);

  const mcuxClCipher_ModeFunctions_t *pModeFunctions = mcuxClCipher_castToCipherModeFunctions(pContext->pMode->pModeFunctions);

  *pOutLength = 0U;
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(pModeFunctions->finish(
    session,
    pContext,
    pOut,
    pOutLength));

  MCUXCLSESSION_EXIT(session, mcuxClCipher_finish, diRefValue, MCUXCLCIPHER_STATUS_OK, MCUXCLCIPHER_STATUS_FAULT_ATTACK, pModeFunctions->protection_token_finish);
}

