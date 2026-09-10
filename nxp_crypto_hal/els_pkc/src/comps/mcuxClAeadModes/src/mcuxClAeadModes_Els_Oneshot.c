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

/** @file  mcuxClAeadModes_Els_Oneshot.c
 *  @brief implementation of the oneshot functions of the mcuxClAeadModes component */

#include <mcuxClAead.h>
#include <internal/mcuxClAeadModes_Els_Types.h>
#include <internal/mcuxClAeadModes_Els_Functions.h>
#include <internal/mcuxClAeadModes_Common_Functions.h>
#include <internal/mcuxClAeadModes_Common.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAeadModes_crypt)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAeadModes_crypt(
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
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAeadModes_crypt);
    /* [Design]
        - allocate a context in the session
        - initialize the context:
            - copy mode to mode in context
            - copy key to key in context
            - copy inLength to dataLength in context
            - copy adataLength to aadLength in context
            - copy tagLength to tagLength in context
            - initialize processedDataLength in context to zero
        - call the Skeleton with
            - context
            - options = 15: oneshot
            - all other arguments
            - unused arguments = NULL/0
        - clean up session
    */

    /* Allocate context */
    const uint32_t cpuCtxSizeInWords = MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClAeadModes_Context_t));
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    mcuxClAeadModes_Context_t *pCtx = (mcuxClAeadModes_Context_t *) mcuxClSession_allocateWords_cpuWa(session, cpuCtxSizeInWords);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    if(NULL == pCtx)
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_crypt, MCUXCLAEAD_STATUS_ERROR);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("pCtx has compatible type and cast was valid")
    pCtx->common.mode = mode;
    pCtx->key = key;
    pCtx->dataLength = inLength;
    pCtx->aadLength = adataLength;
    pCtx->tagLength = tagLength;
    pCtx->processedDataLength = 0u;
    pCtx->partialDataLength = 0u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

    MCUX_CSSL_FP_FUNCTION_CALL(ret_Skeleton, mode->algorithm->pSkeleton(
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ pCtx,
      /* mcuxCl_InputBuffer_t pNonce,           */ pNonce,
      /* uint32_t nonceLength,                 */ nonceLength,
      /* mcuxCl_InputBuffer_t pIn,              */ pIn,
      /* uint32_t inLength,                    */ inLength,
      /* mcuxCl_InputBuffer_t pAdata,           */ pAdata,
      /* uint32_t adataLength,                 */ adataLength,
      /* mcuxCl_Buffer_t pOut,                  */ pOut,
      /* uint32_t * const pOutLength,          */ pOutLength,
      /* mcuxCl_Buffer_t pTag,                  */ pTag,
      /* uint32_t tagLength,                   */ tagLength,
      /* uint32_t options                      */ (MCUXCLELS_AEAD_ENCRYPT == mode->algorithm->direction) ? MCUXCLAEADMODES_OPTION_ONESHOT_ENCRYPT : MCUXCLAEADMODES_OPTION_ONESHOT_DECRYPT
    ));

    if((MCUXCLAEAD_STATUS_OK != ret_Skeleton) && (MCUXCLAEAD_STATUS_INVALID_TAG != ret_Skeleton))
    {
      MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_crypt, ret_Skeleton,
                                mode->algorithm->protection_token_skeleton);
    }

    mcuxClSession_freeWords_cpuWa(session, cpuCtxSizeInWords);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClAeadModes_crypt, ret_Skeleton,
                                        mode->algorithm->protection_token_skeleton);
}

