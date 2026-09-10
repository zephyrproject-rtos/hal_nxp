/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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

#ifndef MCUXCLOSCCACIPHERMODES_FUNCTONS_INTERNAL_H_
#define MCUXCLOSCCACIPHERMODES_FUNCTONS_INTERNAL_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>

#include <mcuxClKey_Types.h>
#include <internal/mcuxClOsccaCipherModes_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Skeleton functions
 * */
#ifdef MCUXCL_FEATURE_CIPHERMODES_SM4

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaCipherModes_SkeletonSM4_Pre)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaCipherModes_SkeletonSM4_Pre(
    mcuxClOsccaCipherModes_Context_Sm4_t * pCtx,
    mcuxClCipher_Mode_t pMode
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaCipherModes_SkeletonSM4_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaCipherModes_SkeletonSM4_Init(
    mcuxClOsccaCipherModes_Context_Sm4_t * pCtx,
    mcuxClKey_Handle_t pKey,
    mcuxCl_InputBuffer_t pIv,
    uint32_t ivLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaCipherModes_SkeletonSM4_Process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaCipherModes_SkeletonSM4_Process(
    mcuxClOsccaCipherModes_Context_Sm4_t * pCtx,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaCipherModes_SkeletonSM4_Finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaCipherModes_SkeletonSM4_Finish(
    mcuxClOsccaCipherModes_Context_Sm4_t * pCtx,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaCipherModes_SkeletonSM4_OneShot)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaCipherModes_SkeletonSM4_OneShot(
    mcuxClSession_Handle_t session,
    mcuxClKey_Handle_t pKey,
    mcuxClCipher_Mode_t pMode,
    mcuxCl_InputBuffer_t pIv,
    uint32_t ivLength,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaCipherModes_SkeletonSM4, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClOsccaCipherModes_SkeletonSM4(
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


#endif /* MCUXCL_FEATURE_CIPHERMODES_SM4 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCACIPHERMODES_FUNCTONS_INTERNAL_H_ */
