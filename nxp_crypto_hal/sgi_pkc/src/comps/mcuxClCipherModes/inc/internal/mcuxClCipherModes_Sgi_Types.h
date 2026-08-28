/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/** @file  mcuxClCipherModes_Sgi_Types.h
 *  @brief Internal type definitions for the mcuxClCipherModes component
 */

#ifndef MCUXCLCIPHERMODES_SGI_TYPES_H_
#define MCUXCLCIPHERMODES_SGI_TYPES_H_

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
 * @brief Engine function type for "normal" blocking SGI modes
 * For stream ciphers (CTR), the engine is capable of processing incomplete blocks,
 * where only the actual amount of input bytes is copied to the @p pOut. The incomplete block is assumed to be the first one,
 * which means that a separate call to the engine for the last (potentially padded) block handling is needed.
 * @pre The provided @p inLength should be non-zero.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClCipherModes_EngineFunc_AesSgi_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t)(*mcuxClCipherModes_EngineFunc_AesSgi_t) (
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t *pIvOut,
  uint32_t * const pOutLength
));

#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
/**
 * @brief Engine function type for SGI modes that handles the wrap-up of AUTO mode (non-blocking)
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClCipherModes_completeAutoModeFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void)(*mcuxClCipherModes_completeAutoModeFunc_t) (
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa
));
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief Finish function type for SGI modes
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClCipherModes_FinishFunc_AesSgi_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void)(*mcuxClCipherModes_FinishFunc_AesSgi_t) (
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
));

/**
 * @brief SetupIv function type for SGI modes
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClCipherModes_SetupIvFunc_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void)(*mcuxClCipherModes_SetupIvFunc_t) (
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIv
));

/**
 * @brief Function for checking length of the IV
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClCipherModes_CheckIvLength_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void)(*mcuxClCipherModes_CheckIvLength_t) (
  mcuxClSession_Handle_t session,
  uint32_t ivLength
));

#define MCUXCLCIPHERMODES_INTEGRITY_PROTECTION_CONTEXT                                                    \
  mcuxClCipher_Context_t common;                                                                          \
  uint8_t blockBuffer[MCUXCLAES_BLOCK_SIZE];       /* Buffer used when not enough data for full block */  \
  uint32_t ivState[MCUXCLAES_BLOCK_SIZE_IN_WORDS]; /* IV and internal state */                            \
  mcuxClAes_KeyContext_Sgi_t keyContext;                                                                  \
  uint32_t direction; /* to differentiate between encryption and decryption */

/**
 * @brief CipherModes integrity protected context structure for SGI modes
 *
 * This struct is used to calculate the size of the integrity protected context
 */
typedef struct
{
  MCUXCLCIPHERMODES_INTEGRITY_PROTECTION_CONTEXT
} mcuxClCipherModes_IntegrityProtectionContext_Aes_Sgi_t;

#define MCUXCLCIPHERMODES_INTEGRITY_PROTECTED_CONTEXT_SIZE  (sizeof(mcuxClCipherModes_IntegrityProtectionContext_Aes_Sgi_t))

/**
 * @brief Cipher context structure for SGI modes
 *
 * This structure is used in the mult-part interfaces to store the
 * information about the current operation and the relevant internal state.
 */
typedef struct mcuxClCipherModes_Context_Aes_Sgi
{
  /* Integrity protected Context */
  MCUXCLCIPHERMODES_INTEGRITY_PROTECTION_CONTEXT

  mcuxClCipherModes_SetupIvFunc_t        setupIV;
  uint32_t                              protectionToken_setupIV;
  mcuxClCipherModes_EngineFunc_AesSgi_t  processEngine;
  uint32_t                              protectionToken_processEngine;
  mcuxClCipherModes_FinishFunc_AesSgi_t  finishSkeleton;
  uint32_t                              protectionToken_finishSkeleton;
} mcuxClCipherModes_Context_Aes_Sgi_t;

/**
 * @brief Cipher mode algorithm descriptor structure for AES algorithms using SGI
 *
 * This structure captures all the information that the Cipher interfaces need
 * to know about a SGI AES Cipher mode algorithm.
 */
typedef struct mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi
{
  mcuxClCipherModes_EngineFunc_AesSgi_t encryptEngine;
  uint32_t                             protectionToken_encryptEngine;
  mcuxClCipherModes_EngineFunc_AesSgi_t decryptEngine;
  uint32_t                             protectionToken_decryptEngine;
#ifdef MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING
  mcuxClCipherModes_completeAutoModeFunc_t completeAutoModeEngine;
  uint32_t                                protectionToken_completeAutoModeEngine;
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */
  mcuxClCipherModes_SetupIvFunc_t       setupIVEncrypt;
  uint32_t                             protectionToken_setupIVEncrypt;
  mcuxClCipherModes_SetupIvFunc_t       setupIVDecrypt;
  uint32_t                             protectionToken_setupIVDecrypt;
  mcuxClCipherModes_CheckIvLength_t     checkIvLength;
  uint32_t                             protectionToken_checkIvLength;
  mcuxClPadding_addPaddingMode_t        addPadding;
  uint32_t                             protectionToken_addPadding;
  mcuxClPadding_removePaddingMode_t     removePadding;
  uint32_t                             protectionToken_removePadding;
  uint32_t                             granularityEnc;
  uint32_t                             granularityDec;
} mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t;

/**
 * @brief Cipher mode algorithm type for "normal" blocking AES algorithms using SGI
 *
 * This type is used to refer to a SGI AES Cipher mode algorithm.
 */
typedef const mcuxClCipherModes_AlgorithmDescriptor_Aes_Sgi_t * const mcuxClCipherModes_Algorithm_Aes_Sgi_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHERMODES_SGI_TYPES_H_ */
