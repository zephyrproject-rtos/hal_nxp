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

/** @file  mcuxClCipherModes_Els_Types.h
 *  @brief Internal type definitions for the mcuxClCipherModes component
 */

#ifndef MCUXCLCIPHERMODES_ELS_TYPES_H_
#define MCUXCLCIPHERMODES_ELS_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClAes.h>
#include <internal/mcuxClAes_Internal_Constants.h>
#include <internal/mcuxClAes_Ctx.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession.h>

#include <internal/mcuxClPadding_Types_Internal.h>
#include <internal/mcuxClCipherModes_Common_Constants.h>
#include <internal/mcuxClCipherModes_Common_Wa.h>
#include <mcuxClCipher_Types.h>
#include <internal/mcuxClCipher_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Cipher context structure for ELS modes
 *
 * This structure is used to store the information about the current operation
 * and the relevant internal ELS state.
 */
typedef struct mcuxClCipherModes_Context_Aes_Els
{
  mcuxClCipher_Context_t   common;

  mcuxClKey_Descriptor_t * pKey;
  uint8_t     blockBuffer[MCUXCLAES_BLOCK_SIZE];   /* Buffer used when not enough data for full block */
  uint32_t    ivState[MCUXCLAES_BLOCK_SIZE_IN_WORDS]; /* IV and internal state */
} mcuxClCipherModes_Context_Aes_Els_t;

/**
 * @brief Engine function type for ELS modes
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) (*mcuxClCipherModes_EngineFunc_AesEls_t) (
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_Context_Aes_Els_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut
);

/**
 * @brief Cipher mode algorithm descriptor structure for AES algorithms using ELS
 *
 * This structure captures all the information that the Cipher interfaces need
 * to know about an ELS AES Cipher mode algorithm.
 */
typedef struct mcuxClCipherModes_AlgorithmDescriptor_Aes_Els
{
  mcuxClCipherModes_EngineFunc_AesEls_t    cryptEngine;
  mcuxClPadding_addPaddingMode_t           addPadding;
  mcuxClPadding_removePaddingMode_t        removePaddingEnc;
  uint32_t                    protection_token_engine;
  uint32_t                    protection_token_addPadding;
  uint32_t                    protection_token_removePaddingEnc;
  uint32_t                    mode;
  uint32_t                    direction;
  uint32_t                    blockLength;
  uint32_t                    ivLength;
  uint32_t                    granularity;
} mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t;

/**
 * @brief Cipher mode algorithm type for AES algorithms using ELS
 *
 * This type is used to refer to an ELS AES Cipher mode algorithm.
 */
typedef const mcuxClCipherModes_AlgorithmDescriptor_Aes_Els_t * const mcuxClCipherModes_Algorithm_Aes_Els_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_ELS_TYPES_H_ */
