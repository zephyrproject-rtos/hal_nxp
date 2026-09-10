/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClHmac_Functions.c
 *  @brief Intermediate layer mcuxClHmac functions
 */

#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClSession.h>
#include <mcuxClMac.h>
#include <mcuxClMemory.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClHmac_MemoryConsumption.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClHmac_Internal_Functions.h>
#include <internal/mcuxClHmac_Internal_Types.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_compute, mcuxClMac_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_compute(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    mcuxClMac_Mode_t mode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pMac,
    uint32_t * const pMacLength)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC Algorithm types")
    mcuxClHmac_Algorithm_t pAlgo = (mcuxClHmac_Algorithm_t) mode->common.pAlgorithm;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_compute, pAlgo->protectionToken_engineOneshot);

    uint32_t contextBuffer[MCUXCLHMAC_MAX_CONTEXT_SIZE_IN_WORDS];
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Generic_t *context = (mcuxClHmac_Context_Generic_t *)contextBuffer;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer is of the right type (mcuxClHmac_Context_Generic_t *)")
    context->common.pMode = mode;
    context->key = (mcuxClKey_Descriptor_t *) key;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineOneshot(session, context, pIn, inLength, pMac, pMacLength));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_compute, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_init, mcuxClMac_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_init(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxClKey_Handle_t key)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Generic_t * const pCtx = (mcuxClHmac_Context_Generic_t *) pContext;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pCtx is of the right type (mcuxClHmac_Context_Generic_t * const)")
    mcuxClHmac_Algorithm_t pAlgo = (mcuxClHmac_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_init, pAlgo->protectionToken_engineInit);

    pCtx->key = (mcuxClKey_Descriptor_t *) key;
    MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineInit(session, pCtx));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_init, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_process, mcuxClMac_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_process(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Generic_t * const pCtx = (mcuxClHmac_Context_Generic_t *) pContext;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pCtx is of the right type (mcuxClHmac_Context_Generic_t * const)")
    mcuxClHmac_Algorithm_t pAlgo = (mcuxClHmac_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_process, pAlgo->protectionToken_engineUpdate);

    MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineUpdate(session, pCtx, pIn, inLength));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_process, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_finish, mcuxClMac_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_finish(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxCl_Buffer_t pMac,
    uint32_t * const pMacLength)
{
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Reinterpret structure for different HMAC context types")
    mcuxClHmac_Context_Generic_t * const pCtx = (mcuxClHmac_Context_Generic_t *) pContext;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pCtx is of the right type (mcuxClHmac_Context_Generic_t * const)")
    mcuxClHmac_Algorithm_t pAlgo = (mcuxClHmac_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_finish, pAlgo->protectionToken_engineFinalize);

    MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineFinalize(session, pCtx, pMac, pMacLength));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHmac_finish, result);
}

