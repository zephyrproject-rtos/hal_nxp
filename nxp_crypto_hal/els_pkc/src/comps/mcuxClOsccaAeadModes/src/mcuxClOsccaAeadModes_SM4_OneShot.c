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

/** @file  mcuxClOsccaAeadModes_SM4_OneShot.c
 *  @brief implementation of the oneshot functions of the mcuxClOsccaAeadModes component */

#include <mcuxClAead.h>
#include <mcuxClSession.h>
#include <mcuxClBuffer.h>
#include <mcuxClMemory.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Types.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Functions.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaAeadModes_crypt, mcuxClAead_crypt_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClOsccaAeadModes_crypt(
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
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaAeadModes_crypt);
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
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("change mcuxClAead_algorithm const * to mcuxClOsccaAeadModes_algorithm_t const *")
    MCUX_CSSL_ANALYSIS_START_PATTERN_FALSE_POSITIVE_CAST_TYPES_WITH_SAME_ALIGNMENT()
    const mcuxClOsccaAeadModes_algorithm_t* pAlgo = (const mcuxClOsccaAeadModes_algorithm_t*) mode->algorithm;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_FALSE_POSITIVE_CAST_TYPES_WITH_SAME_ALIGNMENT()
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    // TODO: like this?
    mcuxClOsccaAeadModes_Context_t ctx; // = (mcuxClAead_Context_t) mcuxClSession_allocateWords_cpuWa(session, sizeInNumberOfWords)
    // also call mcuxClSession_freeWords_cpuWa(session, sizeInNumberOfWords) before returning to caller
    ctx.common.mode = mode;
    ctx.key = key;
    ctx.dataLength = inLength;
    ctx.aadLength = adataLength;
    ctx.tagLength = tagLength;
    ctx.processedDataLength = 0u;
    ctx.partialDataLength = 0u;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("change mcuxClAead_algorithm * to mcuxClOsccaAeadModes_algorithm_t *")
    ctx.direction = pAlgo->direction;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("change mcuxClAead_algorithm * to mcuxClOsccaAeadModes_algorithm_t *")
    MCUX_CSSL_FP_FUNCTION_CALL(ret_Skeleton, pAlgo->pSkeleton(
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
      /* mcuxClSession_Handle_t session,        */ session,
      /* mcuxClAead_Context_t * const pContext, */ &ctx,
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
      /* uint32_t options                      */ (MCUXCLOSCCASM4_ENCRYPT == pAlgo->direction) ? MCUXCLOSCCAAEADMODES_OPTION_ONESHOT_ENCRYPT : MCUXCLOSCCAAEADMODES_OPTION_ONESHOT_DECRYPT
    ));

    /* Clear the context */
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)&ctx, sizeof(ctx));
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaAeadModes_crypt, ret_Skeleton,
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear),
                                        pAlgo->protection_token_skeleton);
}

