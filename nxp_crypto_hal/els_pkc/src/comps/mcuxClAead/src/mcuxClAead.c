/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

/** @file  mcuxClAead.c
 *  @brief Implementation of the multipart and one shot functions of the mcuxClAead component */

#include <mcuxClAead.h>
#include <internal/mcuxClAead_Ctx.h>
#include <internal/mcuxClAead_Descriptor.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAead_crypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAead_crypt(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag,
  uint32_t tagLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAead_crypt, mode->protection_token_crypt);

    MCUX_CSSL_FP_FUNCTION_CALL(status, mode->crypt(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClKey_Handle_t key,                */ key,
      /* mcuxClAead_Mode_t mode,                */ mode,
      /* mcuxCl_InputBuffer_t pNonce,           */ pNonce,
      /* uint32_t nonceLength,                 */ nonceLength,
      /* mcuxCl_InputBuffer_t pIn,              */ pIn,
      /* uint32_t inLength,                    */ inLength,
      /* mcuxCl_InputBuffer_t pAdata,           */ pAdata,
      /* uint32_t adataLength,                 */ adataLength,
      /* mcuxCl_Buffer_t pOut,                  */ pOut,
      /* uint32_t * const pOutLength,          */ pOutLength,
      /* mcuxCl_Buffer_t pTag,                  */ pTag,
      /* uint32_t tagLength,                   */ tagLength
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClAead_crypt, status, MCUXCLAEAD_STATUS_FAULT_ATTACK);
}







MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAead_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAead_init(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAead_init, mode->protection_token_init);

    MCUX_CSSL_FP_FUNCTION_CALL(status, mode->init(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ pContext,
      /* mcuxClKey_Handle_t key,                */ key,
      /* mcuxClAead_Mode_t mode,                */ mode,
      /* mcuxCl_InputBuffer_t pNonce,           */ pNonce,
      /* uint32_t nonceLength,                 */ nonceLength,
      /* uint32_t inLength,                    */ inLength,
      /* uint32_t adataLength,                 */ adataLength,
      /* uint32_t tagLength,                   */ tagLength
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClAead_init, status, MCUXCLAEAD_STATUS_FAULT_ATTACK);
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAead_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAead_process(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAead_process, pContext->mode->protection_token_process);

    MCUX_CSSL_FP_FUNCTION_CALL(status, pContext->mode->process(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ pContext,
      /* mcuxCl_InputBuffer_t pIn,              */ pIn,
      /* uint32_t inLength,                    */ inLength,
      /* mcuxCl_Buffer_t pOut,                  */ pOut,
      /* uint32_t * const pOutLength,          */ pOutLength
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClAead_process, status, MCUXCLAEAD_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAead_process_adata)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAead_process_adata(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAead_process_adata, pContext->mode->protection_token_processAad);

    MCUX_CSSL_FP_FUNCTION_CALL(status, pContext->mode->processAad(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ pContext,
      /* mcuxCl_InputBuffer_t pAdata,           */ pAdata,
      /* uint32_t adataLength,                 */ adataLength
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClAead_process_adata, status, MCUXCLAEAD_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAead_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAead_finish(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAead_finish, pContext->mode->protection_token_finish);


    MCUX_CSSL_FP_FUNCTION_CALL(status, pContext->mode->finish(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ pContext,
      /* mcuxCl_Buffer_t pOut,                  */ pOut,
      /* uint32_t * const pOutLength,          */ pOutLength,
      /* mcuxCl_Buffer_t pTag,                  */ pTag
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClAead_finish, status, MCUXCLAEAD_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAead_verify)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAead_verify(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pTag,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAead_verify, pContext->mode->protection_token_verify);

    MCUX_CSSL_FP_FUNCTION_CALL(status, pContext->mode->verify(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ pContext,
      /* mcuxCl_InputBuffer_t pTag,             */ pTag,
      /* mcuxCl_Buffer_t pOut,                  */ pOut,
      /* uint32_t * const pOutLength,          */ pOutLength
    ));

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClAead_verify, status, MCUXCLAEAD_STATUS_FAULT_ATTACK);
}

