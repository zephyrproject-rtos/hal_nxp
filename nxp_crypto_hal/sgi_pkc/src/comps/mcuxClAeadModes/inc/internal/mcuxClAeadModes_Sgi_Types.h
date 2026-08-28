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

/** @file  mcuxClAeadModes_Sgi_Types.h
 *  @brief Internal defines of types for the mcuxClAeadModes component
*/

#ifndef MCUXCLAEADMODES_SGI_TYPES_H_
#define MCUXCLAEADMODES_SGI_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>

#include <internal/mcuxClAead_Descriptor.h>
#include <internal/mcuxClAeadModes_Common_Wa.h>

#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward Declarations for context struct types */
struct mcuxClAeadModes_Context;
typedef struct mcuxClAeadModes_Context mcuxClAeadModes_Context_t;

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAeadModes_alg_init_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAeadModes_alg_init_t)(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pNonce,
  uint32_t nonceSize,
  uint32_t inSize,
  uint32_t adataSize,
  uint32_t tagSize)
);

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAeadModes_alg_process_aad_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAeadModes_alg_process_aad_t)(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pAdata,
  uint32_t adataSize)
);

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAeadModes_alg_process_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAeadModes_alg_process_t)(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inSize,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutSize)
);

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAeadModes_ProcessFullBlocks_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAeadModes_ProcessFullBlocks_t)(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  const uint32_t inSize)
);

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClAeadModes_alg_finish_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClAeadModes_alg_finish_t)(
  mcuxClSession_Handle_t session,
  mcuxClAeadModes_Context_t *const pContext,
  mcuxClAeadModes_WorkArea_t *workArea,
  mcuxCl_Buffer_t pOut,
  uint32_t *const pOutSize,
  mcuxCl_Buffer_t pTag));

typedef struct mcuxClAead_AlgorithmDescriptor
{
  mcuxClAeadModes_alg_init_t init;
  uint32_t protectionToken_init;
  mcuxClAeadModes_alg_process_aad_t processAad;
  uint32_t protectionToken_processAad;
  mcuxClAeadModes_alg_process_t processEncDec;
  uint32_t protectionToken_processEncDec;
  mcuxClAeadModes_ProcessFullBlocks_t processFullBlocks;
  uint32_t protectionToken_processFullBlocks;
  mcuxClAeadModes_alg_finish_t finish;
  uint32_t protectionToken_finish;
  uint32_t mode;

  const mcuxClMacModes_AlgorithmDescriptor_t * macAlgo;
  const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t * cipherAlgo;
} mcuxClAeadModes_AlgorithmDescriptor_t;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAEADMODES_SGI_TYPES_H_ */
