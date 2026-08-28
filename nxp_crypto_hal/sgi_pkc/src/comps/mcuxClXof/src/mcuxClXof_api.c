/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
#include <mcuxClXof.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslSecureCounter_Cfg.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClXof_Internal.h>
#include <internal/mcuxClMemory_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_compute_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_compute_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXof_compute_internal);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(algorithm->oneShotSkeleton (session,
                                                                  algorithm,
                                                                  pIn,
                                                                  inSize,
                                                                  pCustomization,
                                                                  customizationSize,
                                                                  pOut,
                                                                  outSize
                                                                  ));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXof_compute_internal, algorithm->protection_token_oneShotSkeleton);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_compute)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_compute(
    mcuxClSession_Handle_t session,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClXof_compute, diRefValue, MCUXCLXOF_STATUS_FAULT_ATTACK);

    /* DI protect parameters of pXofAlgo->oneShotSkeleton */
    MCUX_CSSL_DI_RECORD(xofOneshotSkeleton, pIn);
    MCUX_CSSL_DI_RECORD(xofOneshotSkeleton, inSize);
    MCUX_CSSL_DI_RECORD(xofOneshotSkeleton, pOut);
    MCUX_CSSL_DI_RECORD(xofOneshotSkeleton, outSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClXof_compute_internal(session, algorithm, pIn, inSize, pCustomization, customizationSize, pOut, outSize));

    MCUXCLSESSION_EXIT(session,
        mcuxClXof_compute,
        diRefValue,
        MCUXCLXOF_STATUS_OK,
        MCUXCLXOF_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXof_compute_internal)
    );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_init_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_init_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXof_init_internal);

    /* Initialize Xof context */
    pContext->algo = algorithm;

    /* Initialize Hash context */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(algorithm->initSkeleton(session, pContext, pCustomization, customizationSize));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXof_init_internal, algorithm->protection_token_initSkeleton);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_init(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClXof_init, diRefValue, MCUXCLXOF_STATUS_FAULT_ATTACK);

    /* Initialize Hash context */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClXof_init_internal(session, pContext, algorithm, pCustomization, customizationSize));

    MCUXCLSESSION_EXIT(session,
        mcuxClXof_init,
        diRefValue,
        MCUXCLXOF_STATUS_OK,
        MCUXCLXOF_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXof_init_internal)
    );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_process_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_process_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXof_process_internal);

    mcuxClXof_Algo_t pXofAlgo = pContext->algo;

    /* ProcessSkeleton needs to check whether it is called the first time or not, by checking processedLength.
        On its first call, the state needs to be initialized.
    */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pXofAlgo->processSkeleton(session, pContext, pIn, inSize));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXof_process_internal, pXofAlgo->protection_token_processSkeleton);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_process(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClXof_process, diRefValue, MCUXCLXOF_STATUS_FAULT_ATTACK);

    MCUX_CSSL_DI_RECORD(processSkeletonParams, pIn);
    MCUX_CSSL_DI_RECORD(processSkeletonParams, inSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClXof_process_internal(session, pContext, pIn, inSize));

    MCUXCLSESSION_EXIT(session,
        mcuxClXof_process,
        diRefValue,
        MCUXCLXOF_STATUS_OK,
        MCUXCLXOF_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXof_process_internal)
    );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_generate_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_generate_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXof_generate_internal);

    mcuxClXof_Algo_t pXofAlgo = pContext->algo;

    /*  GenerateSkeleton needs to check whether it is called the first time.
        On its first call, the unprocessedBuffer needs to be processed.
    */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pXofAlgo->generateSkeleton(session, pContext, pOut, outSize));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXof_generate_internal, pXofAlgo->protection_token_generateSkeleton);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_generate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_generate(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClXof_generate, diRefValue, MCUXCLXOF_STATUS_FAULT_ATTACK);

    /* DI protect parameters of pXofAlgo->generateSkeleton */
    MCUX_CSSL_DI_RECORD(xofGenerateSkeleton, pOut);
    MCUX_CSSL_DI_RECORD(xofGenerateSkeleton, outSize);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClXof_generate_internal(session, pContext, pOut, outSize));

    MCUXCLSESSION_EXIT(session,
        mcuxClXof_generate,
        diRefValue,
        MCUXCLXOF_STATUS_OK,
        MCUXCLXOF_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXof_generate_internal)
    );
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_finish_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_finish_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXof_finish_internal,
        pContext->algo->protection_token_finishSkeleton,
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT
    );

    mcuxClXof_Algo_t pXofAlgo = pContext->algo;

    MCUX_CSSL_DI_RECORD(clearContext, (uint32_t)pContext);
    MCUX_CSSL_DI_RECORD(clearContext, sizeof(mcuxClXof_ContextDescriptor_t));

    /* Handle algorithm specific cleanup */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(pXofAlgo->finishSkeleton(session, pContext));

    /* Clear context */
    MCUXCLMEMORY_CLEAR_INT((uint8_t*)pContext, sizeof(mcuxClXof_ContextDescriptor_t));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXof_finish_internal);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXof_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClXof_Status_t) mcuxClXof_finish(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext
)
{
    MCUXCLSESSION_ENTRY(session, mcuxClXof_finish, diRefValue, MCUXCLXOF_STATUS_FAULT_ATTACK); /* Balance FP now, as context will be cleared below. */

    /* Handle algorithm specific cleanup */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClXof_finish_internal(session, pContext));

    MCUXCLSESSION_EXIT(session,
        mcuxClXof_finish,
        diRefValue,
        MCUXCLXOF_STATUS_OK,
        MCUXCLXOF_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXof_finish_internal)
    );
}
