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

/** @file  mcuxClAeadModes_Common_Functions.h
 *  @brief Internal function declaration for the mcuxClAeadModes component */

#ifndef MCUXCLAEADMODES_COMMON_FUNCTIONS_H_
#define MCUXCLAEADMODES_COMMON_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClAeadModes_Sgi_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_process_adata, mcuxClAead_process_aad_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_process_adata(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_process, mcuxClAead_process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_process(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_finish, mcuxClAead_finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_finish(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_verify, mcuxClAead_verify_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClAeadModes_verify(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pTag,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_encrypt, mcuxClAead_encrypt_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_encrypt(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag,
  uint32_t tagLength
);


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_decrypt, mcuxClAead_decrypt_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClAeadModes_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength,
  mcuxCl_InputBuffer_t pTag,
  uint32_t tagLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_init_encrypt, mcuxClAead_init_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_init_encrypt(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClAeadModes_init_decrypt, mcuxClAead_init_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAeadModes_init_decrypt(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*MCUXCLAEADMODES_COMMON_FUNCTIONS_H_*/
