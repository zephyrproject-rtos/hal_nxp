/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClMacModes_Els_Functions.c
 *  @brief Implementation of mcuxClMacModes functions for ELS-based modes
 */

#include <mcuxClMac.h>
#include <mcuxClMemory.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMacModes_Common_Functions.h>
#include <internal/mcuxClMacModes_Els_Ctx.h>
#include <internal/mcuxClMacModes_Els_Types.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_compute)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_compute(
mcuxClSession_Handle_t session,
mcuxClKey_Handle_t key,
mcuxClMac_Mode_t mode,
mcuxCl_InputBuffer_t pIn,
uint32_t inLength,
mcuxCl_Buffer_t pMac,
uint32_t * const pMacLength)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) mode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_compute, pAlgo->protectionToken_engineOneshot);
  mcuxClMacModes_Context_t context = {0u};
  context.common.pMode = mode;
  context.key = (mcuxClKey_Descriptor_t *) key;
  MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineOneshot(session, &context, pIn, inLength, pMac, pMacLength));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_compute, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_init(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxClKey_Handle_t key)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  mcuxClMacModes_Context_t * const pCtx = (mcuxClMacModes_Context_t *) pContext;
  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_init, pAlgo->protectionToken_engineInit);
  pCtx->key = (mcuxClKey_Descriptor_t *) key;
  MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineInit(session, pCtx));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_init, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_process(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  mcuxClMacModes_Context_t * const pCtx = (mcuxClMacModes_Context_t *) pContext;
  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_process, pAlgo->protectionToken_engineUpdate);
  MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineUpdate(session, pCtx, pIn, inLength));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_process, result);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_finish(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  mcuxClMacModes_Context_t * const pCtx = (mcuxClMacModes_Context_t *) pContext;
  mcuxClMacModes_Algorithm_t pAlgo = (mcuxClMacModes_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMacModes_finish, pAlgo->protectionToken_engineFinalize);
  MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineFinalize(session, pCtx, pMac, pMacLength));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMacModes_finish, result);
}
