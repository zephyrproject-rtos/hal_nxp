/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#include <mcuxClToolchain.h>
#include <mcuxClHash.h>
#include <internal/mcuxClHash_Internal.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslSecureCounter_Cfg.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHash_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_init(
    mcuxClSession_Handle_t session UNUSED_PARAM,
    mcuxClHash_Context_t pContext,
    mcuxClHash_Algo_t algorithm
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClHash_init, diRefValue, MCUXCLHASH_STATUS_FAULT_ATTACK);

    pContext->unprocessedLength = 0U;
    pContext->processedLength[0] = 0ULL;
    pContext->processedLength[1] = 0ULL;
    pContext->algo = algorithm;

    MCUXCLSESSION_EXIT(session, mcuxClHash_init, diRefValue, MCUXCLHASH_STATUS_OK, MCUXCLHASH_STATUS_FAULT_ATTACK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHash_process_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_process_internal(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHash_process_internal);

    if((NULL == pContext->algo) || (NULL == pContext->algo->processSkeleton))
    {
        MCUXCLSESSION_ERROR(session, MCUXCLHASH_STATUS_INVALID_PARAMS);
    }

    MCUX_CSSL_FP_FUNCTION_CALL(skeletonStatus, pContext->algo->processSkeleton(session, pContext, pIn, inSize));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHash_process_internal, skeletonStatus, pContext->algo->protection_token_processSkeleton);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHash_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_process(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClHash_process, diRefValue, MCUXCLHASH_STATUS_FAULT_ATTACK);

    /* DI balancing of processSkeleton */
    MCUX_CSSL_DI_RECORD(processSkeletonParams, pContext);
    MCUX_CSSL_DI_RECORD(processSkeletonParams, pIn);
    MCUX_CSSL_DI_RECORD(processSkeletonParams, inSize);

    MCUX_CSSL_FP_FUNCTION_CALL(result, mcuxClHash_process_internal(
        session,
        pContext,
        pIn,
        inSize));

    MCUXCLSESSION_EXIT(session,
        mcuxClHash_process,
        diRefValue,
        result,
        MCUXCLHASH_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHash_process_internal)
      );
}
