/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/** @file  mcuxClMacModes_Sgi_Functions.h
 *  @brief Internal header for MAC functions for modes using the SGI HW
 */


#ifndef MCUXCLMACMODES_SGI_FUNCTIONS_H_
#define MCUXCLMACMODES_SGI_FUNCTIONS_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClMac_Types.h>
#include <internal/mcuxClMacModes_Common_Functions.h>
#include <internal/mcuxClMacModes_Common_Constants.h>
#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>
#include <mcuxClBuffer.h>
#include <mcuxClDma_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

/*
 * Internal MAC helper functions
 */

/**
 * Internal function, which generates a random seed in the MacModes context,
 * and initializes in the context a null pre-tag that is masked with SGI SFR masking.
 *
 * @param[in]  pContext    Pointer to the MacModes context (word-aligned), contains the masked preTag and the seed.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_initMaskedPreTag)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_initMaskedPreTag(mcuxClMacModes_Context_t * pContext);

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_castToMacModesAlgorithm)
static inline mcuxClMacModes_Algorithm_t mcuxClMacModes_castToMacModesAlgorithm(void* pAlgorithm)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClMacModes_Algorithm_t) pAlgorithm;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_castToMacModesWorkArea)
static inline mcuxClMacModes_WorkArea_t* mcuxClMacModes_castToMacModesWorkArea(uint32_t* pWa)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClMacModes_WorkArea_t* ) pWa;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_castToMacModesContext)
static inline mcuxClMacModes_Context_t* mcuxClMacModes_castToMacModesContext(mcuxClMac_Context_t* pContext)
{
  MCUX_CSSL_ANALYSIS_START_CAST_TO_MORE_SPECIFIC_TYPE()
  return (mcuxClMacModes_Context_t* ) pContext;
  MCUX_CSSL_ANALYSIS_STOP_CAST_TO_MORE_SPECIFIC_TYPE()
}

/**
 * Internal function, which processes the preTag calculation for Multipart computations.
 * The SFR seed from key context is used to mask the preTag as it is already generated.
 *
 * @param[in]  session     Handle for the current CL session.
 * @param[in]  pWa         Pointer to workarea (word-aligned).
 * @param[in]  pContext    Pointer to the MacModes context (word-aligned), contains the masked preTag.
 * @param[in]  pInput      Pointer to the input data.
 * @param[in]  inputLength Number of bytes of data in the @p pInput buffer.
 * @param[in]  operation   SGI operation configuration
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_process_preTag_calculation)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_process_preTag_calculation(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *pWa,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pInput,
  uint32_t inputLength,
  uint32_t operation);

/**
 * Internal function, which copies out the result from the SGI to the output buffer.
 *
 * @param[in]  session         Handle for the current CL session.
 * @param[in]  dataProcessed   rfu
 * @param[out] pMac            Pointer to result buffer, which the MAC result will be written to.
 * @param[out] pOutLength      Pointer to length of output data.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_CopyOutNormal, mcuxClMacModes_CopyOutputFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_CopyOutNormal(
  mcuxClSession_Handle_t session,
  uint32_t dataProcessed,
  mcuxCl_Buffer_t pMac,
  uint32_t *const pOutLength);

/**
 * Internal function, which copies out the result from the SGI to the output buffer using the DMA.
 *
 * @param[in]  session         Handle for the current CL session.
 * @param[in]  workArea        Pointer to workarea (word-aligned).
 * @param[in]  dataProcessed   rfu
 * @param[out] pMac            Pointer to result buffer, which the MAC result will be written to.
 * @param[out] pOutLength      Pointer to length of output data.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_CopyOutDma, mcuxClMacModes_CopyOutputFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_CopyOutDma(
  mcuxClSession_Handle_t session,
  uint32_t dataProcessed,
  mcuxCl_Buffer_t pMac,
  uint32_t *const pOutLength
);



/*
 * Common Helpers
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_loadZeroIV)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_loadZeroIV(void);

/*
 * Interrupt Service Routines and error handlers for non-blocking operations
 */
/**
 * @brief Interrupt callback to complete a non-blocking Compute (oneshot) operation.
 *
 * This function wraps-up a non-blocking oneshot compute operation. It is installed as callback
 * to the DMA resource, and is called on DMA interrupt (on DONE, or on ERROR).
 *
 * This function triggers the installed user callback. After the callback is done,
 * the function returns back to the resource interrupt handler.
 *
 * @param      session    Handle for the current CL session
 *
 * @return     void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_ISR_completeNonBlocking_compute, mcuxClSession_HwInterruptHandler_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_ISR_completeNonBlocking_compute(
  mcuxClSession_Handle_t session
);


/**
 * @brief Interrupt callback to complete a non-blocking update (multipart) operation.
 *
 * This function wraps-up a non-blocking multipart process operation. It is installed as callback
 * to the DMA resource, and is called on DMA interrupt (on DONE, or on ERROR).
 *
 * This function triggers the installed user callback. After the callback is done,
 * the function returns back to the resource interrupt handler.
 *
 * @param      session    Handle for the current CL session.
 * @return     void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_ISR_completeNonBlocking_multipart, mcuxClSession_HwInterruptHandler_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_ISR_completeNonBlocking_multipart(
  mcuxClSession_Handle_t session
);


/**
 * @brief Function to request DMA input channel and to write the workarea into the session job context.
 *
 * @param session                           Session that requests the channels
 * @param pWa                               Pointer to the workarea to be written into the session job context (word-aligned)
 * @param callbackFunction                  Callback function to be written into the session job context
 * @param protectionToken_callbackFunction  Protection token of the callback function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_requestDmaInputChannelAndConfigureJobContext(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *pWa,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
);

/**
 * @brief This function handles the processing of the last block for CMAC(CBC-MAC) update (multipart).
 *
 * This function handles the processing of the last block (remaining bytes) for
 * a CMAC(CBC-MAC) multipart (update) operation. It completes the engine operation and updates the context.
 * Used for dma-driven blocking and non-blocking operations.
 *
 * @param[in]  session           Handle for the current CL session
 * @param[in]  pContext          Pointer to the context (word-aligned)
 * @param[in]  pIn               Pointer to last block input data
 * @param[in]  inOffset          Offset of the @p pIn buffer
 * @param[in]  remainingBytes    Number of remaining bytes in buffer @p pIn
 *
 * @pre Full input blocks were already processed (either blocking or non-blocking)
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_handleLastBlock_update)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_handleLastBlock_update(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_Context_t * pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t remainingBytes
);

/**
 * @brief Internal function handles full blocks data for all macmodes
 * @pre Expect pretag is loaded to DATOUT
 *
 * @param[in]  pInput         Pointer to the input buffer data to be authenticated
 * @param[in]  inOffset       Offset of the @p pInput buffer
 * @param[in]  inLength       Length of the data in the @p pInput buffer
 * @param[in]  operation      SGI operation configuration
 *
 * @post SGI XOR-on-write feature will be disabled at the end of this function
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_updateEngine, mcuxClMacModes_ComputePreTagFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_updateEngine(
  mcuxCl_InputBuffer_t pInput,
  uint32_t inOffset,
  uint32_t inLength,
  uint32_t operation);

/**
 * @brief Internal function handles last block data for cmac(cbc-mac/gmac)
 * @pre Expect pretag is loaded to DATOUT, last input data has been loaded to DATIN
 *
 * @param[in]  pIn            Pointer to the input buffer data to be authenticated
 * @param[in]  inOffset       Offset of the @p pIn buffer
 * @param[in]  inLength       unused parameter
 * @param[in]  operation      SGI operation configuration
 *
 * @pre Full input blocks were already processed
 *
 * @post SGI XOR-on-write feature will be disabled at the end of this function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_finalizeEngine, mcuxClMacModes_ComputePreTagFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeEngine(
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t inLength,
  uint32_t operation);

/**
 * @brief Internal wrapper function of updateEngine and finalizeEngine
 * @pre Expect pretag is loaded to DATOUT
 *
 * @param[in]  session                        Handle for the current CL session
 * @param[in]  pWa                            Pointer to workarea (word-aligned)
 * @param[in]  pContext                       Pointer to the context (word-aligned)
 * @param[in]  pIn                            Pointer to the input buffer data to be authenticated
 * @param[in]  inOffset                       Offset of the @p pIn buffer
 * @param[in]  inLength                       Length of the data in the @p pIn buffer
 * @param[in]  operation                      SGI operation configuration
 * @param[in]  macEngine                      function pointer to do engine
 * @param[in]  protectionToken_macEngine      protection token for the mac engine function
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMacModes_engine)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_engine(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *pWa,
  mcuxClMacModes_Context_t * pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inOffset,
  uint32_t inLength,
  uint32_t sfrSeed,
  uint32_t operation,
  mcuxClMacModes_ComputePreTagFunc_t macEngine,
  uint32_t protectionToken_macEngine);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_SGI_FUNCTIONS_H_ */
