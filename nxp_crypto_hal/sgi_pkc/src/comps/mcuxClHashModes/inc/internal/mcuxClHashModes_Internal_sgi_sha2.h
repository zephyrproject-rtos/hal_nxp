/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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

/** @file  mcuxClHashModes_Internal_sgi_sha2.h
 *  @brief Internal definitions and declarations of the *INTERNAL* layer dedicated to SGI
 */

#ifndef MCUXCLHASHMODES_INTERNAL_SGI_SHA2_H_
#define MCUXCLHASHMODES_INTERNAL_SGI_SHA2_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLHASHMODES_INTERNAL_SGI_SHA2_FIRST_SGI_OP (0xa5a5U)
#define MCUXCLHASHMODES_INTERNAL_SGI_SHA2_SUBSEQUENT_SGI_OP (0x5a5aU)

#define MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE         (0xFFFFUL)
#define MCUXCLHASHMODES_INTERNAL_SGI_COUNT_MAX_VALUE_IN_LOOP (0xFFFEUL)

/**
 * @brief Oneshot Skeleton implementation for Sha2 with SGI support
 *
 * Data Integrity: Expunge(pIn + inSize + pOut + pOutSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FAILURE - If the hash counter value is different from the expected value or
            if there's a failure when copying hash digest to output buffer.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_Sgi_oneShot_Sha2, mcuxClHash_AlgoSkeleton_OneShot_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Sgi_oneShot_Sha2(mcuxClSession_Handle_t session,
                                                   mcuxClHash_Algo_t algorithm,
                                                   mcuxCl_InputBuffer_t pIn,
                                                   uint32_t inSize,
                                                   mcuxCl_Buffer_t pOut,
                                                   uint32_t *const pOutSize);

/**
 * @brief Process Skeleton implementation for Sha2 with SGI support
 *
 * Data Integrity: Expunge(context + pIn + inSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FULL - when the total input size exceeds the upper limit.
 *       - MCUXCLHASH_STATUS_FAILURE - If the hash counter value is different from the expected value.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_Sgi_process_Sha2, mcuxClHash_AlgoSkeleton_Process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_Sgi_process_Sha2(mcuxClSession_Handle_t session UNUSED_PARAM,
                                                   mcuxClHash_Context_t context,
                                                   mcuxCl_InputBuffer_t pIn,
                                                   uint32_t inSize);

/**
 * @brief Finish Skeleton implementation for Sha2 with SGI support
 *
 * Data Integrity: Expunge(context + pOut + pOutSize)
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FULL - when the total input size exceeds the upper limit.
 *       - MCUXCLHASH_STATUS_FAULT_ATTACK - if the context->unprocessedLength exceeds the upper limit.
 *       - MCUXCLHASH_STATUS_FAILURE - If the hash counter value is different from the expected value or
 *                                       if there's a failure when copying hash digest to output buffer.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_Sgi_finish_Sha2, mcuxClHash_AlgoSkeleton_Finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_finish_Sha2(mcuxClSession_Handle_t session UNUSED_PARAM,
                                                  mcuxClHash_Context_t context,
                                                  mcuxCl_Buffer_t pOut,
                                                  uint32_t *const pOutSize);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_INTERNAL_SGI_SHA2_H_ */
