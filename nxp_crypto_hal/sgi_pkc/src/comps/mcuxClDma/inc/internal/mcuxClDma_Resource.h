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

#ifndef MCUXCLDMA_RESOURCE_H_
#define MCUXCLDMA_RESOURCE_H_

#include <mcuxClDma_Types.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClSession_Types.h>
#include <mcuxClResource_Types.h>
#include <internal/mcuxClResource_Internal_Types.h>
#include <internal/mcuxClSession_Internal_Functions.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Request a DMA channel as NON_INTERRUPTABLE, install the callback function.
 *
 * @param session                           Session that requests the channel
 * @param channel                           Channel to be requested
 * @param callbackFunction                  Callback function to be written into the session job context
 * @param protectionToken_callbackFunction  Protection token of the callback function
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_request)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_request(
  mcuxClSession_Handle_t session,
  mcuxClSession_Channel_t channel,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_request);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_request(
    session,
    MCUXCLRESOURCE_HWID_DMA(channel),
    MCUXCLRESOURCE_HWSTATUS_NON_INTERRUPTABLE,
    callbackFunction,
    protectionToken_callbackFunction
  ));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_request,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_request));
}

/**
 * @brief Release a DMA channel
 *
 * @param session Session that releases the channel
 * @param channel Channel to be released
 *
 * @pre
 *  - @p channel has previously been requested by @p session
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_release)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_release(
  mcuxClSession_Handle_t session,
  mcuxClSession_Channel_t channel
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_release);

  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(channel, 0u, DMA_CH_TOTAL-1u, MCUXCLRESOURCE_HWID_INVALID)
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_release(session->pResourceCtx, MCUXCLRESOURCE_HWID_DMA(channel)));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_release, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_release));
}

/**
 * @brief Request DMA input and output channels as NON_INTERRUPTABLE
 *
 * @param session Session that requests the channels
 * @param callbackFunction Callback function to be written into the session job context
 * @param protectionToken_callbackFunction Protection token of the callback function
 *
 * @pre
 *  - Input and output might or might not map to the same DMA channel.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_requestInputAndOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_requestInputAndOutput(
  mcuxClSession_Handle_t session,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
);

/**
 * @brief Release DMA input and output channels
 *
 * @param session Session that releases the channels
 *
 * @pre
 *  - Input and output might or might not map to the same DMA channel.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClDma_releaseInputAndOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_releaseInputAndOutput(
  mcuxClSession_Handle_t session
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLDMA_RESOURCE_H_ */
