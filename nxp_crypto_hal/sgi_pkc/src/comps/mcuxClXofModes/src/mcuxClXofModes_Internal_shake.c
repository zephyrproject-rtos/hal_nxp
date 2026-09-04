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
#include <mcuxClMemory.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <mcuxClXof.h>
#include <mcuxClXofModes.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClXof_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClXofModes_Internal_Algorithms.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

/**
 *  @brief Wrapper for mcuxClHashModes internal oneshot functions.
 *         Extracts Hash algo from algorithm and translates return values.
 *
 *  @post Data Integrity: Expunge(pIn + inSize + pOut + outSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXofModes_oneshot_shake, mcuxClXof_AlgoSkeleton_oneshot_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXofModes_oneshot_shake(
  mcuxClSession_Handle_t session,
  mcuxClXof_Algo_t algorithm,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_InputBuffer_t pCustomization UNUSED_PARAM,
  uint32_t customizationSize UNUSED_PARAM,
  mcuxCl_Buffer_t pOut,
  uint32_t outSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXofModes_oneshot_shake);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    mcuxClHash_Algo_t pHashAlgo = (mcuxClHash_Algo_t) (algorithm->algoDetails);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_FP_FUNCTION_CALL(result, pHashAlgo->oneShotSkeleton (session,
                                                                  pHashAlgo,
                                                                  pIn,
                                                                  inSize,
                                                                  pOut,
                                                                  &outSize
                                                                  ));
    (void) result; /* pHashAlgo->oneShotSkeleton always return OK */

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXofModes_oneshot_shake, pHashAlgo->protection_token_oneShotSkeleton);
}

/* Initializes Hash context within Xof context. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXofModes_init_shake, mcuxClXof_AlgoSkeleton_init_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXofModes_init_shake(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClXof_Context_t pContext,
  mcuxCl_InputBuffer_t pCustomization UNUSED_PARAM,
  uint32_t customizationSize UNUSED_PARAM)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXofModes_init_shake);

    /* Initialize Hash context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Hash context is located behind Xof context, memory is reserved with this in mind.")
    mcuxClHash_Context_t pHashContext = (mcuxClHash_Context_t) (((uint8_t *)pContext) + sizeof(mcuxClXof_ContextDescriptor_t));
    pHashContext->unprocessedLength = 0u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    pHashContext->processedLength[0] = 0ULL;
    pHashContext->processedLength[1] = 0ULL;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    pHashContext->algo = (mcuxClHash_Algo_t) pContext->algo->algoDetails;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXofModes_init_shake);
}

/* Wrapper for mcuxClHashModes internal process functions. Extracts Hash context and algo from pContext and translates return values. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXofModes_process_shake, mcuxClXof_AlgoSkeleton_process_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXofModes_process_shake(
  mcuxClSession_Handle_t session,
  mcuxClXof_Context_t pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXofModes_process_shake);

    /* Extract the Hash context and Hash algo from the Xof context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Hash context is located behind Xof context, memory is reserved with this in mind.")
    mcuxClHash_Context_t pHashContext = (mcuxClHash_Context_t) (((uint8_t *)pContext) + sizeof(mcuxClXof_ContextDescriptor_t));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
    mcuxClHash_Algo_t pHashAlgo = (mcuxClHash_Algo_t) (pContext->algo->algoDetails);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

    MCUX_CSSL_DI_RECORD(processSkeletonParams, pHashContext);

    MCUX_CSSL_FP_FUNCTION_CALL(result, pHashAlgo->processSkeleton(session, pHashContext, pIn, inSize));
    (void) result; /* pHashAlgo->processSkeleton always return OK */
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXofModes_process_shake, pHashAlgo->protection_token_processSkeleton);
}


#if defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256)
/**
 * @brief Used to generate output from the keccak state. Can be called several times.
 *
 * @post Data Integrity: Expunge(pOut + outSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXofModes_C_generate_shake, mcuxClXof_AlgoSkeleton_generate_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXofModes_C_generate_shake(
  mcuxClSession_Handle_t session,
  mcuxClXof_Context_t pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t outSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXofModes_C_generate_shake);

    /* Extract the Hash context from the Xof context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Hash context is located behind Xof context, memory is reserved with this in mind.")
    mcuxClHash_Context_t pHashContext = (mcuxClHash_Context_t) (((uint8_t *)pContext) + sizeof(mcuxClXof_ContextDescriptor_t));

    MCUX_CSSL_DI_RECORD(sumOfKeccakSqueezeParams, pHashContext);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClHashModes_C_generate_shake(session, pHashContext, pOut, &outSize));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /**************************************************************************************/
    /*                          Exit + FP balancing                                       */
    /**************************************************************************************/
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXofModes_C_generate_shake,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_generate_shake)
    );
}
#endif /* defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256) */



/* Used to cleanup Hash context within the Xof context. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClXofModes_finish_shake, mcuxClXof_AlgoSkeleton_finish_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClXofModes_finish_shake(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClXof_Context_t pContext)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClXofModes_finish_shake);
    /* Extract the Hash context and Hash algo from the Xof context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Hash context is located behind Xof context, memory is reserved with this in mind.")
    mcuxClHash_Context_t pHashContext = (mcuxClHash_Context_t) (((uint8_t *)pContext) + sizeof(mcuxClXof_ContextDescriptor_t));

    /* Clear context */
    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(mcuxClHash_getContextWordSize(pHashContext->algo), 0u, MCUXCLHASHMODES_CONTEXT_MAX_SIZE_INTERNAL, MCUXCLXOF_STATUS_FAILURE)
    MCUX_CSSL_DI_RECORD(clearContext, (uint32_t)pHashContext);
    MCUX_CSSL_DI_RECORD(clearContext, mcuxClHash_getContextWordSize(pHashContext->algo) * sizeof(uint32_t));
    MCUXCLMEMORY_CLEAR_INT((uint8_t*)pHashContext, mcuxClHash_getContextWordSize(pHashContext->algo) * sizeof(uint32_t));

    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClXofModes_finish_shake, MCUXCLMEMORY_CLEAR_INT_FP_EXPECT);
}

/**********************************************************
 * Algorithm descriptor implementations
 **********************************************************/
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
#ifdef MCUXCL_FEATURE_XOF_C_SHAKE_128
/* Hash algorithm descriptor used by the Xof algorithm descriptor */
static const mcuxClHash_AlgorithmDescriptor_t mcuxClXof_AlgorithmDescriptor_C_Shake_128_Hash = {
    .oneShotSkeleton                  = mcuxClHashModes_C_oneShot_xof_shake,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_oneShot_xof_shake),
#ifdef MCUXCL_FEATURE_HASH_COMPARE
    .oneShotCompareSkeleton           = NULL,
#endif /* MCUXCL_FEATURE_HASH_COMPARE */
    .processSkeleton                  = mcuxClHashModes_C_process_sha3_shake,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_process_sha3_shake),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA3,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA3_SHAKE_128,
    .hashSize                         = 0u, /* Given as input */
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA3,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA3,
#ifdef MCUXCL_FEATURE_HASH_OIDS
    .pOid                             = mcuxClHash_oidSha3_shake_128,
    .oidSize                          = sizeof(mcuxClHash_oidSha3_shake_128),
#endif
};
/* Xof algorithm descriptors exported to the user */
const mcuxClXof_AlgorithmDescriptor_t mcuxClXof_AlgorithmDescriptor_C_Shake_128 = {
    .oneShotSkeleton                    = mcuxClXofModes_oneshot_shake,
    .protection_token_oneShotSkeleton   = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_oneshot_shake),
    .initSkeleton                       = mcuxClXofModes_init_shake,
    .protection_token_initSkeleton      = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_init_shake),
    .processSkeleton                    = mcuxClXofModes_process_shake,
    .protection_token_processSkeleton   = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_process_shake),
    .generateSkeleton                   = mcuxClXofModes_C_generate_shake,
    .protection_token_generateSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_C_generate_shake),
    .finishSkeleton                     = mcuxClXofModes_finish_shake,
    .protection_token_finishSkeleton    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_finish_shake),
    .algoDetails                        = (const void *)&mcuxClXof_AlgorithmDescriptor_C_Shake_128_Hash
};
#endif /* MCUXCL_FEATURE_XOF_C_SHAKE_128 */

#ifdef MCUXCL_FEATURE_XOF_C_SHAKE_256
/* Hash algorithm descriptor used by the Xof algorithm descriptor */
const mcuxClHash_AlgorithmDescriptor_t mcuxClXof_AlgorithmDescriptor_C_Shake_256_Hash = {
    .oneShotSkeleton                  = mcuxClHashModes_C_oneShot_xof_shake,
    .protection_token_oneShotSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_oneShot_xof_shake),
#ifdef MCUXCL_FEATURE_HASH_COMPARE
    .oneShotCompareSkeleton           = NULL,
#endif /* MCUXCL_FEATURE_HASH_COMPARE */
    .processSkeleton                  = mcuxClHashModes_C_process_sha3_shake,
    .protection_token_processSkeleton = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClHashModes_C_process_sha3_shake),
    .processedLengthCheckMask         = MCUXCLHASH_PROCESSED_LENGTH_CHECK_MASK_SHA3,
    .blockSize                        = MCUXCLHASH_BLOCK_SIZE_SHA3_SHAKE_256,
    .hashSize                         = 0u, /* Given as input */
    .stateSize                        = MCUXCLHASH_STATE_SIZE_SHA3,
    .counterSize                      = MCUXCLHASH_COUNTER_SIZE_SHA3,
#ifdef MCUXCL_FEATURE_HASH_OIDS
    .pOid                             = mcuxClHash_oidSha3_shake_256,
    .oidSize                          = sizeof(mcuxClHash_oidSha3_shake_256),
#endif
};
/* Xof algorithm descriptor exported to the user */
const mcuxClXof_AlgorithmDescriptor_t mcuxClXof_AlgorithmDescriptor_C_Shake_256 = {
    .oneShotSkeleton                    = mcuxClXofModes_oneshot_shake,
    .protection_token_oneShotSkeleton   = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_oneshot_shake),
    .initSkeleton                       = mcuxClXofModes_init_shake,
    .protection_token_initSkeleton      = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_init_shake),
    .processSkeleton                    = mcuxClXofModes_process_shake,
    .protection_token_processSkeleton   = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_process_shake),
    .generateSkeleton                   = mcuxClXofModes_C_generate_shake,
    .protection_token_generateSkeleton  = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_C_generate_shake),
    .finishSkeleton                     = mcuxClXofModes_finish_shake,
    .protection_token_finishSkeleton    = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClXofModes_finish_shake),
    .algoDetails                        = (const void *)&mcuxClXof_AlgorithmDescriptor_C_Shake_256_Hash
};
#endif /* MCUXCL_FEATURE_XOF_C_SHAKE_256 */





MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
