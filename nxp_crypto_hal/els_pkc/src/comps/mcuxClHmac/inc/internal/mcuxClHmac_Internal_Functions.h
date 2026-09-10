/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

#ifdef __cplusplus
extern "C" {
#endif


/****************************/
/* Skeleton functions       */
/****************************/

/**
 * @brief HMAC Oneshot Compute function
 *
 * This function acts as an intermediate layer between the mcuxClMac_compute API and specific HMAC algorithm cores
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
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_init, mcuxClMac_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_init(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxClKey_Handle_t key
);

/**
 * @brief HMAC Multipart Process function
 *
 * This function acts as an intermediate layer between the mcuxClMac_process API and specific HMAC algorithm cores
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
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_finish, mcuxClMac_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_finish(
    mcuxClSession_Handle_t session,
    mcuxClMac_Context_t * const pContext,
    mcuxCl_Buffer_t pMac,
    uint32_t * const pMacLength
);



/****************************/
/* Helper functions         */
/****************************/

/**
 * Prepares the given HMAC key by hashing and/or padding it to a length of MCUXCLELS_HMAC_PADDED_KEY_SIZE bytes.
 * Both the input key and the output padded key are taken from/written to the context.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_prepareHMACKey)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClHmac_prepareHMACKey(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t key,
    uint32_t * preparedHmacKey
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHMAC_INTERNAL_FUNCTIONS_H_ */
