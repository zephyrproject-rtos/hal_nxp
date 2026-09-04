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

/** @file  mcuxClHash_Internal.h
 *  @brief Definitions and declarations of the *INTERNAL* layer of the
 *         @ref mcuxClHash component
 */

#ifndef MCUXCLHASH_INTERNAL_H_
#define MCUXCLHASH_INTERNAL_H_

#include <mcuxClHash_Types.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * Type declarations
 **********************************************/
 /**
 * @defgroup mcuxClHash_Internal_Types mcuxClHash_Internal_Types
 * @brief Defines all internal types of the @ref mcuxClHash component
 * @ingroup mcuxClHash_Types
 * @{
 */

/**
 * @brief Hash Context structure
 *
 * Maintains the state of a hash computation when using the streaming API.
 *
 * This structure only holds metadata, and the actual hash algorithm's state is part of the context but stored behind this structure.
 *
 * See #mcuxClHash_init for information about the streaming API.
 */
struct mcuxClHash_ContextDescriptor
{
  uint64_t processedLength[2];
  uint32_t unprocessedLength;
  const mcuxClHash_AlgorithmDescriptor_t * algo;
};

#define MCUXCLHASH_CONTEXT_DATA_OFFSET             (sizeof(mcuxClHash_ContextDescriptor_t)) ///< Offset of data buffers from the start of the context
#define MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET    (7u) ///< Start of data buffers is moved at most 7 Bytes back to ensure 64 Bit alignment of pState.


/**
 * @brief Hash one-shot skeleton function type
 *
 * This function will accumulate, pad, etc. the input message and then process it with the Hash core function (mcuxClHash_AlgoCore_t)
 *
 * Data Integrity: All functions of this type expunge pIn + inSize + pOut + pOutSize.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHash_AlgoSkeleton_OneShot_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) (*mcuxClHash_AlgoSkeleton_OneShot_t)(
                                    mcuxClSession_Handle_t session,
                                    mcuxClHash_Algo_t algorithm,
                                    mcuxCl_InputBuffer_t pIn,
                                    uint32_t inSize,
                                    mcuxCl_Buffer_t pOut,
                                    uint32_t *const pOutSize));


/**
 * @brief Hash process skeleton function type
 *
 * This function will accumulate the input message and then process it with the Hash core function (mcuxClHash_AlgoEngine_t)
 *
 * Data Integrity: All functions of this type expunge context + pIn + inSize.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHash_AlgoSkeleton_Process_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) (*mcuxClHash_AlgoSkeleton_Process_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_InputBuffer_t pIn,
                        uint32_t inSize));

/**
 * @brief Hash multi-part skeleton function type
 *
 * This function will accumulate, padd, etc. the input message and then process it with the Hash core function (mcuxClHash_AlgoCore_t)
 *
 * Data Integrity: All functions of this type expunge context + pOut + pOutSize.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHash_AlgoSkeleton_Finish_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClHash_AlgoSkeleton_Finish_t)(
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize));

#ifdef MCUXCL_FEATURE_HASH_SELFTEST
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHash_SelfTestFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) (*mcuxClHash_SelfTestFunc_t) (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Algo_t algorithm));

/**
 * @brief Hash selftest mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Hash selftest interfaces need
 * to know about a particular Hash selftest mode/algorithm.
 */
struct mcuxClHash_TestDescriptor
{
  mcuxClHash_SelfTestFunc_t    selftest;
  uint32_t                    protection_token_selftest;
};
#endif /* MCUXCL_FEATURE_HASH_SELFTEST */

/**
 * @brief Hash Algorithm OIDs
 *
 */
#define MCUXCLHASH_OID_SHA2SHA3_LEN    19u
#define MCUXCLHASH_OID_SHA1_LEN        18u

#if defined(MCUXCL_FEATURE_HASH_OIDS)
extern const uint8_t mcuxClHash_oidSha2_224[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha2_256[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha2_384[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha2_512[MCUXCLHASH_OID_SHA2SHA3_LEN];
#endif /*MCUXCL_FEATURE_HASH_OIDS*/

#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) || defined(MCUXCL_FEATURE_HASH_C_SHA3)
extern const uint8_t mcuxClHash_oidSha3_224[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha3_256[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha3_384[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha3_512[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha3_shake_128[MCUXCLHASH_OID_SHA2SHA3_LEN];
extern const uint8_t mcuxClHash_oidSha3_shake_256[MCUXCLHASH_OID_SHA2SHA3_LEN];
#endif /* MCUXCL_FEATURE_HASH_C_SHA3_SHAKE || MCUXCL_FEATURE_HASH_C_SHA3 */

/**
 * @brief Hash Algorithm structure
 *
 */
struct mcuxClHash_AlgorithmDescriptor
{
  mcuxClHash_AlgoSkeleton_OneShot_t oneShotSkeleton;        ///< One-shot hash skeleton function
  uint32_t protection_token_oneShotSkeleton;               ///< Protection token value for the used one-shot skeleton
  mcuxClHash_AlgoSkeleton_Process_t processSkeleton;        ///< Process hash skeleton function
  uint32_t protection_token_processSkeleton;               ///< Protection token value for the used process skeleton
  mcuxClHash_AlgoSkeleton_Finish_t finishSkeleton;          ///< Multi-part hash skeleton function
  uint32_t protection_token_finishSkeleton;                ///< Protection token value for the used multi-part skeleton
  uint8_t processedLengthCheckMask;                        ///< Mask of the highest byte of the processed length that cannot be set
  size_t blockSize;                                        ///< Size of the block used by the hash algorithm
  size_t hashSize;                                         ///< Size of the output of the hash algorithm
  size_t stateSize;                                        ///< Size of the state used by the hash algorithm
  uint32_t counterSize;                                    ///< Size of the counter used by the hash algorithm
#ifdef MCUXCL_FEATURE_HASH_OIDS
  const uint8_t *pOid;                                     ///< Pointer to the OID
  uint32_t oidSize;                                        ///< Size of the OID
#endif /* MCUXCL_FEATURE_HASH_OIDS */
  const void *pAlgorithmDetails;                           ///< Contains algorithm specific details not needed on API level
};

/**@}*/

/**********************************************
 * Function declarations
 **********************************************/
/**
 * @brief internal variant of the Hash compute API.
 *
 * To be used instead of mcuxClHash_compute when called from within the CL.
 *
 * Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_INVALID_PARAMS - When the input parameters are invalid.
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_compute_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_compute_internal(
    mcuxClSession_Handle_t session,
    mcuxClHash_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutSize
);

/**
 * @brief internal variant of the Hash process API.
 *
 * To be used instead of mcuxClHash_process when called from within the CL.
 *
 * Data Integrity: Expunge(pContext + pIn + inSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_INVALID_PARAMS - When the input parameters are invalid.
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_process_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_process_internal(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
);

/**
 * @brief internal variant of the Hash finish API.
 *
 * To be used instead of mcuxClHash_finish when called from within the CL.
 *
 * Data Integrity: Expunge(pContext + pOut + pOutSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_INVALID_PARAMS - When the input parameters are invalid.
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_finish_internal)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHash_finish_internal(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutSize
);

/**
 * @brief Adds a 64 Bit constant to an 128 Bit counter
 *
 * This function is used to support bigger input length up to 2^128 Bit
 *
 * @param[in out] pLen128 128 Bit counter to increment
 * @param[in] addLen 64 Bit constant to increment counter with
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_processedLength_add)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHash_processedLength_add(uint64_t *pLen128, uint64_t addLen);

/**
 * @brief Compares an 128 Bit counter value against a 64 Bit constant.
 *
 * @param[in] pLen128 128 Bit counter
 * @param[in] cmpLenLow32 64 Bit constant
 *
 * @return ternary value indicating greater, equal, smaller relationship
 * @retval 1    Counter value is bigger than constant
 * @retval 0    Counter and constant have equal value
 * @retval -1   Counter value is smaller than constant
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_processedLength_cmp)
MCUX_CSSL_FP_PROTECTED_TYPE (int) mcuxClHash_processedLength_cmp(uint64_t *pLen128, uint64_t cmpLenLow64);

/**
 * @brief convert 128 bit number of bytes to number of bits
 *
 * @param pLen128[in out] 128 Bit number represented as uint64_t array. Upper 3 bits need to be zero to avoid overflow.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_processedLength_toBits)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHash_processedLength_toBits(uint64_t *pLen128);

/**
 * @brief Computes the context size for a given hash algorithm.
 *
 * This allows usage of smaller context buffers and should be preferred over MCUXCLHASH_CONTEXT_SIZE
 * if the Hash algorithm is chosen by the user but the hash context is allocated within the CL.
 *
 * @param[in] algo Hash algorithm
 *
 * @return Byte size of a Hash context
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_getContextWordSize)
static inline uint32_t mcuxClHash_getContextWordSize(
  mcuxClHash_Algo_t algo
)
{
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Context size will never overflow.")
  return MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_ContextDescriptor_t)
                  + MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + algo->stateSize + algo->blockSize);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}

/**
 * @brief Returns the address of the state within the given context
 *
 * @param[in] pContext The given context which must be word-aligned
 *
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_getStatePtr)
static inline uint32_t* mcuxClHash_getStatePtr(
  mcuxClHash_Context_t pContext
)
{
  uint8_t *pState = (uint8_t *)pContext + MCUXCLHASH_CONTEXT_DATA_OFFSET;
  /* Align state to 64 Bit */
  size_t stateOffset = (size_t) ((uint32_t)pState % sizeof(uint64_t));
  if(0u != stateOffset)
  {
    pState += (sizeof(uint64_t) - stateOffset);
  }
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pState is now 64 Bit aligned")
  return (uint32_t *)pState;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
}


/**
 * @brief Returns the address of the unprocessed buffer within the given context
 *
 * @param[in] pContext The given context which must be word-aligned
 *
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_getUnprocessedPtr)
static inline uint32_t* mcuxClHash_getUnprocessedPtr(
  mcuxClHash_Context_t pContext
)
{
  uint8_t *pUnprocessed = (uint8_t *)mcuxClHash_getStatePtr(pContext) + pContext->algo->stateSize;
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pUnprocessed is 32 Bit aligned since the state pointer is 64 Bit aligned and the state size is at least 32 Bit aligned.")
  return (uint32_t *)pUnprocessed;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
}


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASH_INTERNAL_H_ */
