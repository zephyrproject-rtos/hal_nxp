/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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

/** @file  mcuxClHashModes_Internal_Resource_Common.h
 *  @brief Internal declarations for Blocking modes
 */

#ifndef MCUXCLHASHMODES_INTERNAL_BLOCKING_COMMON_H_
#define MCUXCLHASHMODES_INTERNAL_BLOCKING_COMMON_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClHash_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Macro defines to be used with mcuxClHashModes_HwRequest,mcuxClHashModes_HwRelease,
 * mcuxClHashModes_Sgi_Sha2End, mcuxClHashModes_Sha2Nonblocking_CleanupAndTriggerUserCallback
 * functions.
 * Each define indicates which hardware resource shall be requested/released.
 * Multiple defines can be ORed together
 */
#define MCUXCLHASHMODES_REQ_DMA_INPUT    (1u << 0u)
#define MCUXCLHASHMODES_REQ_DMA_OUTPUT   (1u << 1u)
#define MCUXCLHASHMODES_REQ_SGI          (1u << 2u)
#define MCUXCLHASHMODES_REQ_LTC          (1u << 3u)

/**
 * @brief Hash modes hardware request function
 *
 * This function shall request hardware specified via request option
 *
 * @param[in]       session                       Handle for the current CL session
 * @param[in]       pHwIrqHandler                 Handler to be used when interrupt is triggered.
                                                  When NULL is provided no interrupt handler is installed.
 *                                                When MCUXCLHASHMODES_REQ_SGI is used callback will be set for DMA interrupt routine
 *                                                When MCUXCLHASHMODES_REQ_LTC is used callback will be set for LTC interrupt routine
 * @param[in]       protectionToken_pHwIrqHandler Protection token of pHwIrqHandler
 * @param[in]       requestOption                 Option from MCUXCLHASHMODES_REQ_* define set indicating which hardware shall be requested
 *                                                @note At one time only MCUXCLHASHMODES_REQ_SGI or MCUXCLHASHMODES_REQ_LTC shall be used
 *
 * @return void
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLRESOURCE_STATUS_UNAVAILABLE - if the resource request fails.
 *       - MCUXCLRESOURCE_STATUS_ERROR - if an error occurred during resource operation.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_HwRequest)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_HwRequest (
                        mcuxClSession_Handle_t session,
                        mcuxClSession_HwInterruptHandler_t pHwIrqHandler,
                        uint32_t protectionToken_pHwIrqHandler,
                        uint32_t requestOption);

/**
 * @brief Hash modes hardware release function
 *
 * This function shall release hardware specified via request option
 *
 * @param[in]       session                 Handle for the current CL session
 * @param[in]       releaseOption           Option from MCUXCLHASHMODES_REQ_* define set indicating which hardware shall be released
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_HwRelease)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_HwRelease (
                        mcuxClSession_Handle_t session,
                        uint32_t releaseOption);

/**
 * @brief Hash modes Sha2 ending and cleanup operations
 *
 * This function performs Sha2 cleanup operations and storing the result when output buffer is specified.
 *
 * @param[in]       session                Handle for the current CL session
 * @param[in]       algorithm              Hash algorithm that should be used during the operations
 * @param[in]       expectedSgiCounter     Counter value to be used in mcuxClSgi_Drv_checkHashCounter operation
 * @param[out]      pOut                   Pointer to output buffer where the result shall be stored
 *                                         when NULL is specificed store operation will not be performed
 * @param[out]      pOutSize               Hash output size buffer
 *                                         When NULL is specificed for pOut this operation will not be performed
 * @param[in]       releaseOption          Option from MCUXCLHASHMODES_REQ_* define set indicating which hardware shall be released.
 *
 * @return void
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FAILURE - Hash result failure when copying hash digest to output buffer.
 *       - MCUXCLHASH_STATUS_FAULT_ATTACK - if the hash counter value is different from the expected value.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_Sgi_Sha2End)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_Sha2End (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Algo_t algorithm,
                        uint32_t expectedSgiCounter,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize,
                        uint32_t releaseOption);


/**
 * @brief Finish Skeleton implementation for DMA blocking Sha2 with SGI support
 *
 * Data Integrity: Expunge(context + pOut + pOutSize)
 *
 * @return void
 *
 * @note Function uses early-exit mechanism with following return codes:
 *       - MCUXCLHASH_STATUS_FULL - when the total input size exceeds the upper limit.
 *       - MCUXCLHASH_STATUS_FAULT_ATTACK - if the context->unprocessedLength exceeds the upper limit.
 *       - MCUXCLHASH_STATUS_FAILURE - If the hash counter value is different from the expected value or
 *                                       if there's a failure when copying hash digest to output buffer.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking, mcuxClHash_AlgoSkeleton_Finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHashModes_Sgi_finish_Sha2_DmaBlocking (
                        mcuxClSession_Handle_t session,
                        mcuxClHash_Context_t context,
                        mcuxCl_Buffer_t pOut,
                        uint32_t *const pOutSize);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_INTERNAL_BLOCKING_COMMON_H_ */
