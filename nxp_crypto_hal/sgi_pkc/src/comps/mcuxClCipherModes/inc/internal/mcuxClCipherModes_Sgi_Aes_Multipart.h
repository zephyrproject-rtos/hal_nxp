/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

#ifndef MCUXCLCIPHERMODES_SGI_AES_MULTIPART_H_
#define MCUXCLCIPHERMODES_SGI_AES_MULTIPART_H_


#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>

#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxClKey_Types.h>
#include <internal/mcuxClCipherModes_Sgi_Types.h>

/**
 * @brief Initialize multipart encryption with SGI
 *
 * This function performs a multipart init operation for encryption with the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_InitFunc_t.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[in]  pKey       Handle for the used key (word-aligned)
 * @param[in]  pIv        Pointer to initialization vector
 * @param[in]  ivLength   Length of initialization vector
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_init_encrypt_Sgi, mcuxClCipher_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_init_encrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
);

/**
 * @brief Initialize multipart decryption with SGI
 *
 * This function performs a multipart init operation for decryption with the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_InitFunc_t.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[in]  pKey       Handle for the used key (word-aligned)
 * @param[in]  pIv        Pointer to initialization vector
 * @param[in]  ivLength   Length of initialization vector
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_init_decrypt_Sgi, mcuxClCipher_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_init_decrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxClKey_Handle_t pKey,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
);

/**
 * @brief Initialize multipart decryption with SGI
 *
 * This function performs a multipart init operation for decryption with the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_InitFunc_t.
 *
 * @param      session    Handle for the current CL session.
 * @param      pWa        Handle for the workarea (word-aligned)
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[in]  pKey       Handle for the used key (word-aligned)
 * @param[in]  pIv        Pointer to initialization vector
 * @param[in]  ivLength   Length of initialization vector
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_init_internal_Sgi)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_init_internal_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxClCipherModes_Context_Aes_Sgi_t * const pCtx,
  mcuxClKey_Handle_t pKey,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
);

/**
 * @brief Multipart process with SGI
 *
 * This function starts a normal multipart process operation with the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_ProcessFunc_t.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[in]  pIn        Pointer to the input buffer
 * @param[in]  inLength   Length of the input buffer
 * @param[out] pOut       Pointer to the output buffer
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_process_Sgi, mcuxClCipher_ProcessFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_process_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Multipart finish with SGI
 *
 * This function performs the finish steps for normal Cipher multipart processing using the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_FinishFunc_t.
 *
 * This function calls @ref mcuxClCipherModes_finish_encrypt_Sgi or @ref mcuxClCipherModes_finish_decrypt_Sgi,
 * depending on the used multipart finish API function.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[out] pOut       Pointer to the output buffer to write the last block(s)
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_finish_Sgi, mcuxClCipher_FinishFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Multipart finish for encryption with SGI
 *
 * This function performs the finish steps for normal multipart encryption using the SGI.
 * It implements the context function pointer type @ref mcuxClCipherModes_FinishFunc_AesSgi_t.
 *
 * @param      session    Handle for the current CL session.
 * @param      pWa        Handle for the workarea (word-aligned)
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[out] pOut       Pointer to the output buffer to write the last block(s)
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_finish_encrypt_Sgi, mcuxClCipherModes_FinishFunc_AesSgi_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_encrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);

/**
 * @brief Multipart finish for decryption with SGI
 *
 * This function performs the finish steps for normal multipart decryption using the SGI.
 * It implements the context function pointer type @ref mcuxClCipherModes_FinishFunc_AesSgi_t.
 *
 * @param      session    Handle for the current CL session.
 * @param      pWa        Handle for the workarea (word-aligned)
 * @param[in]  pContext   Pointer to the multipart context (word-aligned)
 * @param[out] pOut       Pointer to the output buffer to write the last block(s)
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_finish_decrypt_Sgi, mcuxClCipherModes_FinishFunc_AesSgi_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_finish_decrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxClCipher_Context_t * const pContext,
  mcuxCl_Buffer_t pOut,
  uint32_t * const pOutLength
);


#endif /* MCUXCLCIPHERMODES_SGI_AES_MULTIPART_H_ */
