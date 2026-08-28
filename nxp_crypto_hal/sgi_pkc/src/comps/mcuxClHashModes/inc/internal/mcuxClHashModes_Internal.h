/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/** @file  mcuxClHashModes_Internal.h
 *  @brief Definitions and declarations of the *INTERNAL* layer of the
 *         @ref mcuxClHashModes component
 */

#ifndef MCUXCLHASHMODES_INTERNAL_H_
#define MCUXCLHASHMODES_INTERNAL_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClHash_Types.h>
#include <mcuxClToolchain.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal_Memory.h>
#include <internal/mcuxClHashModes_Internal_sgi_sha2.h>
#include <internal/mcuxClSgi_Utils.h>
#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE)
#include <internal/mcuxClHashModes_Internal_Algorithms.h>
#endif /* defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) */
#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * CONSTANTS
 **********************************************/


#define MCUXCLHASHMODES_SHAKE_PHASE_INIT       (0x00000000u) /* Initialization phase of Shake: buffer will be cleared */
#define MCUXCLHASHMODES_SHAKE_PHASE_ABSORB     (0x0F0F0F0Fu) /* Absorb phase of Shake: don't clear any more, but also don't add padding yet */
#define MCUXCLHASHMODES_SHAKE_PHASE_SQUEEZE    (0xF0F0F0F0u) /* Squeeze phase of Shake: padding has been added, from now on only permute on the state */

/**********************************************
 * Type declarations
 **********************************************/

/**
 * @brief Internal Hash Algorithm structure
 *
 */
typedef struct mcuxClHashModes_Internal_AlgorithmDescriptor
{
  mcuxClSgi_Utils_initHash sgiUtilsInitHash;
  uint32_t protectionToken_sgiUtilsInitHash;
  uint32_t dummyValue;                                          ///< needed in the absense of any algorithm using internal algorithm properties
} mcuxClHashModes_Internal_AlgorithmDescriptor_t;
/**@}*/

/**********************************************
 * Function declarations
 **********************************************/

#define MCUXCLHASHMODES_SWITCH_4BYTE_ENDIANNESS(val)   \
        ((((val) & 0xFFu)       << 24)   \
        | (((val) & 0xFF00u)     << 8)   \
        | (((val) & 0xFF0000u)   >> 8)   \
        | (((val) & 0xFF000000u) >> 24))   ///< Macro to switch the endianness of a CPU word

#define MCUXCLHASHMODES_SWITCH_8BYTE_ENDIANNESS(val)      \
         ((((val) << 56u) & 0xFF00000000000000u) |  \
          (((val) << 40u) & 0x00FF000000000000u) |  \
          (((val) << 24u) & 0x0000FF0000000000u) |  \
          (((val) << 8u ) & 0x000000FF00000000u) |  \
          (((val) >> 8u ) & 0x00000000FF000000u) |  \
          (((val) >> 24u) & 0x0000000000FF0000u) |  \
          (((val) >> 40u) & 0x000000000000FF00u) |  \
          (((val) >> 56u) & 0x00000000000000FFu))


#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256)

#if defined(MCUXCL_FEATURE_HASH_C_SHA3)
/**
 * @brief Oneshot Skeleton implementation for Sha3 in SW
 *
 * @post
 *  - Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 *
 * @param[in]       session    Handle for the current CL session.
 * @param[in]       algorithm  Hash algorithm that should be used during the computation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data
 *                             that needs to be hashed.
 * @param[in]       inSize     Number of bytes of data in the pIn buffer.
 * @param[in,out]   pOut       Pointer to the output buffer where the computed hash
 *                             value is written.
 * @param[in,out]   pOutSize   Pointer to the number of bytes, which shall be computed.
 *                             After the function call, it contains the number of bytes written to the pOut buffer.
 *
 * @retval #MCUXCLHASH_STATUS_OK                        operation is successful
 * @return Error code (see @ref mcuxClHashModes, @ref mcuxClBuffer) in case of other failures.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_C_oneShot_sha3, mcuxClHash_AlgoSkeleton_OneShot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_oneShot_sha3(
                                mcuxClSession_Handle_t session,
                                mcuxClHash_Algo_t algorithm,
                                mcuxCl_InputBuffer_t pIn,
                                uint32_t inSize,
                                mcuxCl_Buffer_t pOut,
                                uint32_t *const pOutSize);
#endif /* if defined(MCUXCL_FEATURE_HASH_C_SHA3) */

/**
 * @brief Oneshot Skeleton implementation for Shake in SW
 *
 * @post
 *  - Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 *
 * @param[in]       session    Handle for the current CL session.
 * @param[in]       algorithm  Hash algorithm that should be used during the computation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data
 *                             that needs to be hashed.
 * @param[in]       inSize     Number of bytes of data in the pIn buffer.
 * @param[in,out]   pOut       Pointer to the output buffer where the computed hash
 *                             value is written.
 * @param[in,out]   pOutSize   Pointer to the number of bytes, which shall be computed.
 *                             After the function call, it contains the number of bytes written to the pOut buffer.
 *
 * @retval #MCUXCLHASH_STATUS_OK                        operation is successful
 * @return Error code (see @ref mcuxClHashModes, @ref mcuxClBuffer) in case of other failures.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_C_oneShot_xof_shake, mcuxClHash_AlgoSkeleton_OneShot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_oneShot_xof_shake(
    mcuxClSession_Handle_t session,
    mcuxClHash_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutSize);

/**
 * @brief Process Skeleton implementation for SHA3 shake process in SW
 *
 * Data Integrity: Expunge(pContext + pIn + inSize)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_C_process_sha3_shake, mcuxClHash_AlgoSkeleton_Process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_C_process_sha3_shake(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize);

/**
 * @brief Process finalize implementation for Shake in SW
 *
 * @param[in,out]   pContext     Handle for the current context (word-aligned).
 * @param[in]       paddingByte  Padding value.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_C_Sha3_shake_finishAbsorb_core)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_Sha3_shake_finishAbsorb_core(
    mcuxClHash_Context_t pContext,
    const uint8_t paddingByte);


/**
 * @brief Finish operation for Xof in SW
 *
 * @param[in]       session    Handle for the current CL session, it is UNUSED.
 * @param[in,out]   pContext   Handle for the current context (word-aligned).
 * @param[in,out]   pOut       Pointer to the input buffer that contains the data
 *                             that needs to be hashed.
 * @param[in]       pOutSize   Pointer to the number of bytes, which shall be computed.
 *                             After the function call, it contains the number of bytes written to the pOut buffer.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_C_generate_shake, mcuxClHash_AlgoSkeleton_Finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_C_generate_shake(mcuxClSession_Handle_t session,
                                                        mcuxClHash_Context_t pContext,
                                                        mcuxCl_Buffer_t pOut,
                                                        uint32_t *const pOutSize);


#endif /* defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_128) || defined(MCUXCL_FEATURE_XOF_C_SHAKE_256) */





/** Inline function to convert word-aligned pointer to specific context. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_castPointerToContext)
static inline mcuxClHash_Context_t mcuxClHashModes_castPointerToContext(uint32_t *pContext)
{
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    mcuxClHash_Context_t pCtx = (mcuxClHash_Context_t)pContext;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    return pCtx;
}

/**********************************************
 * Macros
 **********************************************/

/** @brief Macro to compute a % b given b is a power of two (MD5,SHA1,SHA2,SecSha1,SecSha2) */
#define MCUXCLHASH_MOD_BLOCK_SIZE(a, b)   \
  ((a) & ((b) - 1U))

/** @brief Macro to compute a / b given b is a block size in {64, 128} (SHA2) */
#define MCUXCLHASH_DIV_BLOCK_SIZE_SHA2(a, b)   \
  ((MCUXCLHASH_BLOCK_SIZE_SHA_256 == (b)) ? ((a) >> 6U) : ((a) >> 7U))

/** @brief Macro to compute a * b given b is a block size in {64, 128} (SHA2) */
#define MCUXCLHASH_MUL_BLOCK_SIZE_SHA2(a, b)  \
  ((MCUXCLHASH_BLOCK_SIZE_SHA_256 == (b)) ? ((a) << 6U) : ((a) << 7U))


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_INTERNAL_H_ */
