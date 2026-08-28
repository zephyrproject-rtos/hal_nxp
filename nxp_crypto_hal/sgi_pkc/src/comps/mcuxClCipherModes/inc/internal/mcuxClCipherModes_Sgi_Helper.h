/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

#ifndef MCUXCLCIPHERMODES_SGI_HELPER_H_
#define MCUXCLCIPHERMODES_SGI_HELPER_H_

#include <mcuxClSession_Types.h>
#include <internal/mcuxClCipherModes_Common_Wa.h>
#include <mcuxClSgi_Types.h>
#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
#include <mcuxClDma_Types.h>
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief Function used to copy data from SGI to user
 *
 * @param[in]     pWa         pointer to workarea used in cipher mode (word-aligned).
 * @param[in,out] outBuf      pointer to buffer of output data.
 * @param[in]     offset      offset in outBuf to write.
 * @param[in]     byteLength  length of data to copy in byte.
 *
 * @post
 *  - Data Integrity: Expunge(outBuf + offset + MCUXCLSGI_DRV_DATOUT_OFFSET + byteLength)
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_copyOut_toPtr, mcuxClSgi_copyOut_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_copyOut_toPtr(
  void* pWa,
  mcuxCl_Buffer_t outBuf,
  uint32_t offset,
  uint32_t byteLength);


#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
/**
 * @brief Function to request DMA input and output channels and to write the workarea into the session job context.
 *
 * @param[in] session                           Session that requests the channels
 * @param[in] pWa                               Pointer to the workarea (word-aligned) to be written into the session job context
 * @param[in] callbackFunction                  Callback function to be written into the session job context
 * @param[in] protectionToken_callbackFunction  Protection token of the callback function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_requestDmaChannelsAndConfigureJobContext(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
);
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief Internal function to load the key (SFR-masked) from the AES key context and IV to the SGI.
 *
 * If there is enough data to precess @p inLength together with data in context (pCtx->common.blockBufferUsed)
 * to process full block of data (MCUXCLAES_BLOCK_SIZE), this function will load the key (SFR-masked)
 * from the AES key context and IV to to the SGI.
 *
 * @param           session           Handle for the current session.
 * @param           pCtx              Pointer to AES context (word-aligned).
 * @param[in]       pWa               Pointer to cpu workarea (word-aligned)
 * @param[in]       inLength          Length of input data
 * @param[out]      pKeyChecksum      Will be set to loaded key checksum in key was loaded
 *
 * @return void
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_loadKeyAndIvtoSgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_loadKeyAndIvtoSgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Context_Aes_Sgi_t * pCtx,
  mcuxClCipherModes_WorkArea_t * pWa,
  uint32_t inLength,
  mcuxClKey_KeyChecksum_t** pKeyChecksum
);

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_castToCipherModesContextAesSgi)
static inline mcuxClCipherModes_Context_Aes_Sgi_t* mcuxClCipherModes_castToCipherModesContextAesSgi(mcuxClCipher_Context_t* pContext)
{
  MCUX_CSSL_ANALYSIS_START_CAST_TO_MORE_SPECIFIC_TYPE()
  return (mcuxClCipherModes_Context_Aes_Sgi_t*) pContext;
  MCUX_CSSL_ANALYSIS_STOP_CAST_TO_MORE_SPECIFIC_TYPE()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_castToCipherModesWorkArea)
static inline mcuxClCipherModes_WorkArea_t* mcuxClCipherModes_castToCipherModesWorkArea(uint32_t* pWa)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClCipherModes_WorkArea_t *) pWa;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_castToCipherModesAlgorithmAesSgi)
static inline mcuxClCipherModes_Algorithm_Aes_Sgi_t mcuxClCipherModes_castToCipherModesAlgorithmAesSgi(const void* pAlgorithm)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClCipherModes_Algorithm_Aes_Sgi_t) pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}


#endif /* MCUXCLCIPHERMODES_SGI_HELPER_H_ */
