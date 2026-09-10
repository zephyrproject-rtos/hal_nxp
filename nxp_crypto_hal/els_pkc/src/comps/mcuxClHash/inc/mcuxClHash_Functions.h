/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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

/** @file  mcuxClHash_Functions.h
 *  @brief Top-level API of the mcuxClHash component */

#ifndef MCUXCLHASH_FUNCTIONS_H_
#define MCUXCLHASH_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxClHash_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClHash_Functions mcuxClHash_Functions
 * @brief Defines all functions of @ref mcuxClHash
 * @ingroup mcuxClHash
 * @{
 */

/**********************************************************************/
/* ONE-SHOT                                                           */
/**********************************************************************/

/**
 * @brief One-shot Hash computation function
 *
 * This function performs a hash computation over the input message \p pIn, using the hash function provided by the
 * \p algorithm input parameter, in one shot. Up to 2^32 bytes of data can be hashed with this function.
 *
 * For example, to perform a SHA256 computation, the following needs to be
 * provided:
 *  - SHA256 algorithm
 *  - Input data
 *  - Output hash buffer
 *
 * The input parameter \p session has to be initialized by the function mcuxClSession_init prior to
 * calling this function.
 * @if (MCUXCL_FEATURE_SESSION_HAS_RTF)
 * Certain \ref mcuxClHashAlgorithms support maintaining a Runtime Fingerprint (RTF).
 * Updating of the RTF has to be enabled/disabled by calling the mcuxClSession_setRtf function on the session
 * prior to calling this function.
 * @endif (MCUXCL_FEATURE_SESSION_HAS_RTF)
 *
 * @param[in/out]   session    Handle for the current CL session.
 * @param[in]       algorithm  Hash algorithm that should be used during the computation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data
 *                             that needs to be hashed.
 * @param[in]       inSize     Number of bytes of data in the \p pIn buffer.
 * @param[out]      pOut       Pointer to the output buffer where the computed hash
 *                             value is written.
 * @param[out]      pOutSize   Will be incremented by the number of bytes of data
 *                             that have been written to the \p pOut buffer.
 *
 * @return status
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 * @retval MCUXCLHASH_STATUS_FAILURE          Error occured during Hash operation
 * @retval MCUXCLHASH_STATUS_INVALID_PARAMS   The provided function parameters do not fulfill requirements
 * @retval MCUXCLHASH_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * @implements{REQ_2245974}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_compute)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_compute(
    mcuxClSession_Handle_t session,
    mcuxClHash_Algo_t algorithm,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutSize
); /* oneshot compute */



/**********************************************************************/
/* MULTIPART                                                          */
/**********************************************************************/

/**
 * @brief Multi-part Hash initialization function
 *
 * This function performs the initialization for a multi-part hash operation.
 *
 * @param[in/out]   session    Handle for the current CL session.
 * @param[out]      pContext   Hash context which is used to maintain the state and
 *                             store other relevant information about the operation.
 * @param[in]       algorithm  Hash algorithm that should be used during the
 *                             computation operation.
 *
 * @return status
 * @retval MCUXCLHASH_STATUS_OK        Initialization successful
 * @retval MCUXCLHASH_STATUS_FAILURE   Error occurred during initialization function
 *
 * @implements{REQ_2207116}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_init(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxClHash_Algo_t algorithm
); /* init */

/**
 * @brief Multi-part Hash processing function
 *
 * This function performs the processing of (a part of) a data stream for a
 * Hash operation. The algorithm to be used will be determined based on the
 * context that is provided.
 *
 * @param[in/out]   session    Handle for the current CL session.
 * @param[in/out]   pContext   Hash context which is used to maintain the state and
 *                             store other relevant information about the operation.
 * @param[in]       pIn        Pointer to the input buffer that contains the data that
 *                             needs to be processed.
 * @param[in]       inSize     Number of bytes of data in the \p pIn buffer.
 *
 * @return status
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 * @retval MCUXCLHASH_STATUS_FAILURE          Error occurred during Hash operation
 * @retval MCUXCLHASH_STATUS_INVALID_PARAMS   The provided function parameters do not fulfill requirements
 * @retval MCUXCLHASH_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * @implements{REQ_2207116}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_process(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
); /* update */

/**
 * @brief Multi-part Hash computation finalization function
 *
 * This function performs the finalization of a Hash computation operation.
 * The algorithm to be used will be determined based on the context that is
 * provided
 *
 * @param[in/out]   session    Handle for the current CL session.
 * @param[in/out]   pContext   Hash context which is used to maintain the state and
 *                             store other relevant information about the operation.
 * @param[out]      pOut       Pointer to the output buffer where the computed hash
 *                             value needs to be written.
 * @param[out]      pOutSize   Will be incremented by the number of bytes of data
 *                             that have been written to the \p pOut buffer.
 *
 * @return status
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 * @retval MCUXCLHASH_STATUS_FAILURE          Error occurred during Hash operation
 * @retval MCUXCLHASH_STATUS_INVALID_PARAMS   The provided function parameters do not fulfill requirements
 * @retval MCUXCLHASH_STATUS_FAULT_ATTACK     A fault attack was detected
 *
 * @implements{REQ_2207116}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHash_finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHash_finish(
    mcuxClSession_Handle_t session,
    mcuxClHash_Context_t pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t *const pOutSize
); /* finalize compute */



/**
 * @}
 */ /* mcuxClHash_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASH_FUNCTIONS_H_ */

