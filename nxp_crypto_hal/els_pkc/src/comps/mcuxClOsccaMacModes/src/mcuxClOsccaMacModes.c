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

/** @file  mcuxClOsccaMacModes.c
 *  @brief Implementation of mcuxClOsccaMacModes functions for SM4-based and SM3-HMAC modes
 */

#include <mcuxClMac.h>
#include <mcuxClMemory.h>
#include <mcuxClKey.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClOsccaMacModes_Internal_Functions.h>
#include <internal/mcuxClOsccaMacModes_Ctx.h>
#include <internal/mcuxClOsccaMacModes_Types.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_compute, mcuxClMac_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_compute(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClMac_Mode_t mode,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength
)
{
  mcuxClOsccaMacModes_Algorithm_t pAlgo = (mcuxClOsccaMacModes_Algorithm_t) mode->common.pAlgorithm;
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_compute, pAlgo->protectionToken_engineOneshot);


  MCUX_CSSL_FP_FUNCTION_CALL(result, pAlgo->engineOneshot(session, mode, key, pIn, inLength, pMac, pMacLength));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_compute, result);
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_init, mcuxClMac_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_init(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t * const pContext,
  mcuxClKey_Handle_t key)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  mcuxClOsccaMacModes_Context_t * const pCtx = (mcuxClOsccaMacModes_Context_t *) pContext;
  mcuxClOsccaMacModes_Algorithm_t pAlgo = (mcuxClOsccaMacModes_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_init, pAlgo->protectionToken_engineInit);

  pCtx->pKey = (mcuxClKey_Descriptor_t *) key;

  MCUX_CSSL_FP_FUNCTION_CALL(result1, pAlgo->engineInit(session, pCtx));
  if (MCUXCLMAC_STATUS_OK != result1)
  {
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCtx, sizeof(mcuxClOsccaMacModes_Context_t));
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_init, result1,
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_init, result1);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_process, mcuxClMac_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_process(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t *const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  mcuxClOsccaMacModes_Context_t * const pCtx = (mcuxClOsccaMacModes_Context_t *) pContext;
  mcuxClOsccaMacModes_Algorithm_t pAlgo = (mcuxClOsccaMacModes_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_process, pAlgo->protectionToken_engineUpdate);

  MCUX_CSSL_FP_FUNCTION_CALL(result2, pAlgo->engineUpdate(session, pCtx, pIn, inLength));
  if (MCUXCLMAC_STATUS_OK != result2)
  {
    MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCtx, sizeof(mcuxClOsccaMacModes_Context_t));
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_process, result2,
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));
  }
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_process, result2);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_finish, mcuxClMac_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClOsccaMacModes_finish(
  mcuxClSession_Handle_t session,
  mcuxClMac_Context_t *const pContext,
  mcuxCl_Buffer_t pMac,
  uint32_t * const pMacLength)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()
  mcuxClOsccaMacModes_Context_t * const pCtx = (mcuxClOsccaMacModes_Context_t *) pContext;
  mcuxClOsccaMacModes_Algorithm_t pAlgo = (mcuxClOsccaMacModes_Algorithm_t) pCtx->common.pMode->common.pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_CAST_TO_MORE_SPECIFIC_TYPE()

  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_finish, pAlgo->protectionToken_engineFinalize,
                                        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear));

  MCUX_CSSL_FP_FUNCTION_CALL(result3, pAlgo->engineFinalize(session, pCtx, pMac, pMacLength));

  MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)pCtx, sizeof(mcuxClOsccaMacModes_Context_t));
  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaMacModes_finish, result3);
}
