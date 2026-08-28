/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025-2026 NXP                                            */
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

/** @file  mcuxClXof_Internal.h
 *  @brief Internal header for use with the mcuxClXof component */

#ifndef MCUXCLXOF_INTERNAL_H_
#define MCUXCLXOF_INTERNAL_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClXof_Types.h>

#define MCUXCLXOF_STATE_SIZE_SHAKE         (200U) ///< SHAKE all variants state size: 1600 bits (200 bytes)
#define MCUXCLXOF_BLOCK_SIZE_SHAKE_128     (168U) ///< SHAKE-128 block size: 1344 bit (168 bytes)
#define MCUXCLXOF_BLOCK_SIZE_SHAKE_256     (136U) ///< SHAKE-256 block size: 1088 bit (136 bytes)

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClXof_AlgoSkeleton_oneshot_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClXof_AlgoSkeleton_oneshot_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClXof_Algo_t algorithm,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize,
                        mcuxCl_InputBuffer_t pCustomization,
                        uint32_t customizationSize,
                        mcuxCl_Buffer_t pOut,
                        uint32_t outSize));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClXof_AlgoSkeleton_init_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClXof_AlgoSkeleton_init_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClXof_Context_t pContext,
                        mcuxCl_InputBuffer_t pCustomization,
                        uint32_t customizationSize));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClXof_AlgoSkeleton_process_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClXof_AlgoSkeleton_process_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClXof_Context_t pContext,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClXof_AlgoSkeleton_generate_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClXof_AlgoSkeleton_generate_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClXof_Context_t pContext,
                        mcuxCl_Buffer_t pOut,
                        uint32_t outSize));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClXof_AlgoSkeleton_finish_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClXof_AlgoSkeleton_finish_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClXof_Context_t pContext));

/**
 * @brief Xof Algorithm structure
 *
 */
struct mcuxClXof_AlgorithmDescriptor
{
    mcuxClXof_AlgoSkeleton_oneshot_t oneShotSkeleton;                                            /* Oneshot skeleton function */
    uint32_t protection_token_oneShotSkeleton;                                                  /* Protection token value for the used oneshot skeleton */
    mcuxClXof_AlgoSkeleton_init_t initSkeleton;                                                  /* Init skeleton function */
    uint32_t protection_token_initSkeleton;                                                     /* Protection token value for the used init skeleton */
    mcuxClXof_AlgoSkeleton_process_t processSkeleton;                                            /* Process skeleton function */
    uint32_t protection_token_processSkeleton;                                                  /* Protection token value for the used process skeleton */
    mcuxClXof_AlgoSkeleton_generate_t generateSkeleton;                                          /* Generate skeleton function */
    uint32_t protection_token_generateSkeleton;                                                 /* Protection token value for the used generate skeleton */
    mcuxClXof_AlgoSkeleton_finish_t finishSkeleton;                                              /* Finish skeleton function */
    uint32_t protection_token_finishSkeleton;                                                   /* Protection token value for the used finish skeleton */
    const void *algoDetails;                                                                    /* Contains a additional algorithm-dependent details */
};

struct mcuxClXof_ContextDescriptor
{
    const mcuxClXof_AlgorithmDescriptor_t *algo;
    /* Might be extended by additional algorithm-specific data */
};

/**
 * @brief Internal One-shot Xof computation function without session entry and DI balancing (see mcuxClXof_compute() for more details).
 *
 * @post Data Integrity: Expunge(pIn + inSize + pOut + outSize)
 *
 * @param[in,out]   session             Handle for the current CL session.
 * @param[in]       algorithm           Xof algorithm that should be used during the computation.
 * @param[in]       pIn                 Pointer to the input buffer that contains the data that needs to be handled.
 * @param[in]       inSize              Number of bytes of data in the \p pIn buffer.
 * @param[in]       pCustomization      Pointer to the customization buffer that contains additional data to be used in the computation (Optional)
 * @param[in]       customizationSize   Number of bytes of data in the \p pCustomization buffer.
 * @param[out]      pOut                Pointer to the output buffer where the computed Xof value is written.
 * @param[in]       outSize             Indicates the requested byte length of the output
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_compute_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_compute_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
);
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()

/**
 * @brief Internal multi-part Xof initialization function without session entry.
 *
 * This function performs the initialization for a multi-part Xof operation.
 *
 * @param[in,out]   session             Handle for the current CL session.
 * @param[out]      pContext            Xof context (word-aligned) which is used to maintain the state and store other relevant information about the operation.
 * @param[in]       algorithm           Xof algorithm that should be used during the computation operation.
 * @param[in]       pCustomization      Pointer to the customization buffer that contains additional data to be used in the computation (Optional)
 * @param[in]       customizationSize   Number of bytes of data in the \p pCustomization buffer.
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_init_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_init_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxClXof_Algo_t algorithm,
    mcuxCl_InputBuffer_t pCustomization,
    uint32_t customizationSize
);
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()

 /**
 * @brief Internal multi-part Xof processing function without session entry and DI balacing (see mcuxClXof_process() for more details).
 *
 * @post Data Integrity: Expunge(pIn + inSize)
 *
 * @param[in,out]   session    Handle for the current CL session.
 * @param[in,out]   pContext   Xof context (word-aligned) which is used to maintain the state and
 *                             store other relevant information about the operation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data that
 *                             needs to be processed.
 * @param[in]       inSize     Number of bytes of data in the \p pIn buffer.
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_process_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_process_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
);
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()

/**
 * @brief Internal multi-part Xof generation function without session entry and DI balacing (see mcuxClXof_generate() for more details).
 *
 * @post Data Integrity: Expunge(pOut + outSize)
 *
 * @param[in,out]   session         Handle for the current CL session.
 * @param[in,out]   pContext        Xof context (word-aligned) which is used to maintain the state and store other relevant information about the operation.
 * @param[out]      pOut            Pointer to the output buffer where the computed Xof value is written.
 * @param[in]       outSize         Indicates the requested byte length of the output
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_generate_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_generate_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t outSize
);
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()

/**
 * @brief Internal multi-part Xof computation cleanup function without session entry (see mcuxClXof_finish() for more details).
 *
 * @param[in,out]   session    Handle for the current CL session.
 * @param[in,out]   pContext   Xof context (word-aligned) which is used to maintain the state and
 *                             store other relevant information about the operation.
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClXof_finish_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXof_finish_internal(
    mcuxClSession_Handle_t session,
    mcuxClXof_Context_t pContext
);
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_SYMBOL_DECLARED_MORE_THAN_ONCE()


#endif /* MCUXCLXOF_INTERNAL_H_ */
