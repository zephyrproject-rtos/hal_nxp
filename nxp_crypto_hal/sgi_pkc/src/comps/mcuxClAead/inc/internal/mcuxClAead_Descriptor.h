/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

/** @file  mcuxClAead_Descriptor.h
 *  @brief Internal definitions for the mcuxClAead component
 */

#ifndef MCUXCLAEAD_DESCRIPTOR_H_
#define MCUXCLAEAD_DESCRIPTOR_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClKey_Types.h>
#include <mcuxClAead_Types.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClResource_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_init_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAead_init_t)(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t *const pContext,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceLength,
  uint32_t inLength,
  uint32_t adataLength,
  uint32_t tagLength
  ));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_process_aad_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAead_process_aad_t)(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t *const pContext,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength
  ));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_process_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAead_process_t)(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
  ));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_finish_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAead_finish_t)(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t *const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutLength,
  mcuxCl_Buffer_t pTag
  ));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_verify_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) (*mcuxClAead_verify_t)(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t *const pContext,
  mcuxCl_InputBuffer_t pTag,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
  ));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_encrypt_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAead_encrypt_t)(
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
  uint32_t *const pOutLength,
  mcuxCl_Buffer_t pTag,
  uint32_t tagLength
  ));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_decrypt_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) (*mcuxClAead_decrypt_t)(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  mcuxClAead_Mode_t mode,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceSize,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataSize,
  mcuxCl_InputBuffer_t pTag,
  uint32_t tagSize,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutSize
  ));

struct mcuxClAead_ModeDescriptor
{
//------------OneShot

  mcuxClAead_encrypt_t encrypt;
  uint32_t protection_token_encrypt;
  mcuxClAead_decrypt_t decrypt;
  uint32_t protection_token_decrypt;



//------------MultiPart

  mcuxClAead_init_t init_enc;
  uint32_t protection_token_init_enc;
  mcuxClAead_init_t init_dec;
  uint32_t protection_token_init_dec;

  mcuxClAead_process_aad_t processAad;
  uint32_t protection_token_processAad;
  mcuxClAead_process_t process;
  uint32_t protection_token_process;
  mcuxClAead_finish_t finish;
  uint32_t protection_token_finish;
  mcuxClAead_verify_t verify;
  uint32_t protection_token_verify;


  //-------------Common
  const struct mcuxClAead_AlgorithmDescriptor *algorithm;

  mcuxClResource_HwStatus_t hwStatusOption;

};

#ifdef MCUXCL_FEATURE_AEAD_SELFTEST
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAead_SelfTestFct_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAead_SelfTestFct_t) (
  mcuxClSession_Handle_t session,
  mcuxClAead_Mode_t mode
));

struct mcuxClAead_TestDescriptor
{
  mcuxClAead_SelfTestFct_t pSelfTestFct;
  uint32_t                protection_token_selftest;
};
#endif /* MCUXCL_FEATURE_AEAD_SELFTEST */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAEAD_DESCRIPTOR_H_ */
