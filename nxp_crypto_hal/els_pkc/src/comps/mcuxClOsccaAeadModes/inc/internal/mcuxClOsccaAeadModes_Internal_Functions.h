/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

/** @file  mcuxClOsccaAeadModes_Internal_Functions.h
 *  @brief Internal function declaration for the mcuxClOsccaAeadModes component */

#ifndef MCUXCLOSCCAAEADMODES_INTERNAL_FUNCTIONS_H_
#define MCUXCLOSCCAAEADMODES_INTERNAL_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClAead.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession_Types.h>
#include <internal/mcuxClAead_Ctx.h>
#include <internal/mcuxClOsccaAeadModes_Internal_Types.h>

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_init, mcuxClAead_init_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClOsccaAeadModes_init(
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


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_process_adata, mcuxClAead_process_aad_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClOsccaAeadModes_process_adata(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_process, mcuxClAead_process_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClOsccaAeadModes_process(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_finish, mcuxClAead_finish_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClOsccaAeadModes_finish(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  mcuxCl_Buffer_t pTag
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_verify, mcuxClAead_verify_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_verify(
  mcuxClSession_Handle_t session,
  mcuxClAead_Context_t * const pContext,
  mcuxCl_InputBuffer_t pTag,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_crypt, mcuxClAead_crypt_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t)  mcuxClOsccaAeadModes_crypt(
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


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_SkeletonCcm, mcuxClOsccaAeadModes_Skeleton_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_SkeletonCcm(
    mcuxClSession_Handle_t session,
    mcuxClOsccaAeadModes_Context_t * const pContext,
    mcuxCl_InputBuffer_t pNonce,
    uint32_t nonceLength,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_InputBuffer_t pAdata,
    uint32_t adataLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength,
    mcuxCl_Buffer_t pTag,
    uint32_t tagLength,
    uint32_t options //!< options is a bitmask with one bit reserved for each of the operations
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_EngineCcm, mcuxClOsccaAeadModes_Engine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_EngineCcm (
  mcuxClSession_Handle_t session,
  mcuxClOsccaAeadModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength,
  uint32_t options  //!< options is a bitmask with one bit reserved for each of the operations
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_SM4_Crypt_Internal_Ctr(
    uint32_t* roundKeys, mcuxCl_InputBuffer_t pIn, uint32_t inputLen, uint8_t* pIV, mcuxCl_Buffer_t pOut);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_Ccm_Internal_Init)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_Ccm_Internal_Init(
    mcuxClSession_Handle_t session,
    mcuxClOsccaAeadModes_Context_t * const pCtx,
    mcuxCl_InputBuffer_t pNonce,
    uint32_t nonceLength,
    uint32_t inLength,
    uint32_t adataLength,
    uint32_t tagLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_Ccm_Internal_ProcessAad)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_Ccm_Internal_ProcessAad(
    mcuxClSession_Handle_t session,
    mcuxClOsccaAeadModes_Context_t * const pCtx,
    mcuxCl_InputBuffer_t pAdata,
    uint32_t adataLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_Ccm_Internal_Process)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_Ccm_Internal_Process(
    mcuxClSession_Handle_t session,
    mcuxClOsccaAeadModes_Context_t * const pCtx,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t * const pOutLength
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaAeadModes_Ccm_Internal_Finish)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClAead_Status_t) mcuxClOsccaAeadModes_Ccm_Internal_Finish(
    mcuxClSession_Handle_t session,
    mcuxClOsccaAeadModes_Context_t * const pCtx,
    mcuxCl_Buffer_t pTag,
    uint32_t options //!< options is a bitmask with one bit reserved for each of the operations
);

#endif /*MCUXCLOSCCAAEADMODES_INTERNAL_FUNCTIONS_H_*/
