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

/** @file  mcuxClHmac_Internal_Functions.h
 *  @brief Internal definitions of helper functions for the HMAC component
 */

#ifndef MCUXCLHMAC_INTERNAL_FUNCTIONS_H_
#define MCUXCLHMAC_INTERNAL_FUNCTIONS_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClBuffer.h>
#include <mcuxClMac_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession_Types.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClHmac_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/****************************/
/* ExitGate functions       */
/****************************/

/**
 * @brief Exit gate function for abnormal and OK returns.
 *
 * This function securely clears a given memory area and also frees the cpuWa.
 *
 * @param session                   Current CL session
 * @param pMemoryToClear            Pointer to sensitive data to be securely cleared
 * @param wordSizeMemoryToClear     Size of pMemoryToClear
 * @param wordSizeCpuWaBuffer       cpuWa usage of the calling function
 *
 * @return @p statusCode
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_cleanupOnExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_cleanupOnExit(
    mcuxClSession_Handle_t session,
    uint32_t *pMemoryToClear,
    size_t wordSizeMemoryToClear,
    size_t wordSizeCpuWaBuffer
);

/****************************/
/* Skeleton functions       */
/****************************/

/**
 * @brief HMAC Oneshot Compute function
 *
 * This function acts as an intermediate layer between the mcuxClMac_compute API and specific HMAC algorithm cores
 *
 * @param[in]  session      Handle for the current CL session.
 * @param[in]  key          Key to be used to authenticate the data (word-aligned).
 * @param[in]  mode         Mode that should be used during the MAC operation.
 * @param[in]  pIn          Input buffer that contains the data that needs to be authenticated.
 * @param[in]  inLength     Number of bytes of data in the @p pIn buffer.
 * @param[out] pMac         Output buffer where the MAC needs to be written.
 * @param[out] pMacLength   Will be incremented by the number of bytes of data that have been written to the @p pMac buffer.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_compute, mcuxClMac_ComputeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_compute(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    mcuxClMac_Mode_t mode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pMac,
    uint32_t * const pMacLength
);


/**
 * @brief HMAC Multipart Init function
 *
 * This function acts as an intermediate layer between the mcuxClMac_init API and specific HMAC algorithm cores
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  pContext  MAC context which is used to maintain the state and
 *                       store other relevant information about the operation (word-aligned).
 * @param[in]  key       Key to be used to authenticate the data (word-aligned).
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_init, mcuxClMac_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_init(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxClKey_Handle_t key
);

/**
 * @brief HMAC Multipart Process function
 *
 * This function acts as an intermediate layer between the mcuxClMac_process API and specific HMAC algorithm cores
 *
 * @param      session   Handle for the current CL session.
 * @param[in]  pContext  MAC context which is used to maintain the state and
 *                       store other relevant information about the operation (word-aligned).
 * @param[in]  pIn       Input buffer that contains the data that need to be processed.
 * @param[in]  inLength  Number of bytes of data in the @p pIn buffer.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_process, mcuxClMac_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_process(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength
);

/**
 * @brief HMAC Multipart Finish function
 *
 * This function acts as an intermediate layer between the mcuxClMac_finish API and specific HMAC algorithm cores
 *
 * @param[in]  session     Handle for the current CL session.
 * @param[in]  pContext    MAC context which is used to maintain the state and
 *                         store other relevant information about the operation (word-aligned).
 * @param[out] pMac        Output buffer where the MAC needs to be written.
 * @param[out] pMacLength  Will be incremented by the number of bytes of data that
 *                         have been written to the @p pMac buffer.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_finish, mcuxClMac_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_finish(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxCl_Buffer_t pMac,
    uint32_t * const pMacLength
);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHMAC_INTERNAL_FUNCTIONS_H_ */
