/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

#ifndef MCUXCLCIPHERMODES_ELS_FUNCTIONS_H_
#define MCUXCLCIPHERMODES_ELS_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey_Types.h>
#include <internal/mcuxClCipherModes_Els_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Skeleton init phase
 *
 * This function starts a init operation within Skeleton function
 *
 * @param[in]  pCtx       Pointer to the context
 * @param[in]  pkey       Handle for the used key
 * @param[in]  pMode      Cipher mode to use for encryption operation
 * @param[in]  pIv        Pointer to initialization vector
 * @param[in]  ivLength   Length of initialization vector
 * @return status
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_SkeletonAes_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_SkeletonAes_Init(
    mcuxClCipherModes_Context_Aes_Els_t *pCtx,
    mcuxClKey_Handle_t pKey,
    mcuxClCipher_Mode_t pMode,
    mcuxCl_InputBuffer_t pIv,
    uint32_t ivLength
);

/**
 * @brief Skeleton process phase
 *
 * This function starts a process operation within Skeleton function
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pCtx       Pointer to the context
 * @param[in]  pIn        Pointer to the input buffer
 * @param[in]  inLength   Length of the input buffer
 * @param[out] pOut       Pointer to the output buffer
 * @param      pOutLength Pointer to the length of the output buffer
 * @return status
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_SkeletonAes_Process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_SkeletonAes_Process(
    mcuxClSession_Handle_t session,
    mcuxClCipherModes_Context_Aes_Els_t *pCtx,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
);

/**
 * @brief Skeleton final phase
 *
 * This function starts a final operation within Skeleton function
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pCtx       Pointer to the context
 * @param[out] pOut       Pointer to the output buffer
 * @param      pOutLength Pointer to the length of the output buffer
 * @return status
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_SkeletonAes_Finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_SkeletonAes_Finish(
    mcuxClSession_Handle_t session,
    mcuxClCipherModes_Context_Aes_Els_t *pCtx,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
);

/*
 * Skeleton and Engine functions
 * */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_EngineEls)
  MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_EngineEls(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Context_Aes_Els_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_SkeletonAes)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_SkeletonAes(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t pMode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t steps //!< steps is a bitmask with one bit reserved for each of the steps below
);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_ELS_FUNCTIONS_H_ */
