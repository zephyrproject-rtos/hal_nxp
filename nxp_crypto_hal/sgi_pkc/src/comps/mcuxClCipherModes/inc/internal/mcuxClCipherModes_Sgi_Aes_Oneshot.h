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

#ifndef MCUXCLCIPHERMODES_SGI_AES_ONESHOT_H_
#define MCUXCLCIPHERMODES_SGI_AES_ONESHOT_H_

#include <mcuxClCore_Platform.h>

#include <mcuxClBuffer.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession.h>

#include <internal/mcuxClCipherModes_Sgi_Types.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>

/**
 * @brief Oneshot encryption with SGI
 *
 * This function starts a normal oneshot encryption operation with the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_CryptFunc_t.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pKey       Handle for the used key (word-aligned)
 * @param[in]  mode       Cipher mode to use for encryption operation
 * @param[in]  pIv        Pointer to initialization vector
 * @param[in]  ivLength   Length of initialization vector
 * @param[in]  pIn        Pointer to the input buffer
 * @param[in]  inLength   Length of the input buffer
 * @param[out] pOut       Pointer to the output buffer
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_encrypt_Sgi, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_encrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutLength
);

/**
 * @brief Oneshot decryption with SGI
 *
 * This function starts a normal oneshot decryption operation with the SGI.
 * It implements the mode function pointer type @ref mcuxClCipher_CryptFunc_t.
 *
 * @param      session    Handle for the current CL session.
 * @param[in]  pKey       Handle for the used key (word-aligned)
 * @param[in]  mode       Cipher mode to use for encryption operation
 * @param[in]  pIv        Pointer to initialization vector
 * @param[in]  ivLength   Length of initialization vector
 * @param[in]  pIn        Pointer to the input buffer
 * @param[in]  inLength   Length of the input buffer
 * @param[out] pOut       Pointer to the output buffer
 * @param[out] pOutLength Pointer to write/update the amount of written output bytes
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_decrypt_Sgi, mcuxClCipher_CryptFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClCipher_Status_t) mcuxClCipherModes_decrypt_Sgi(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t pKey,
  mcuxClCipher_Mode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  mcuxCl_Buffer_t pOut,
  uint32_t* const pOutLength
);

#endif /* MCUXCLCIPHERMODES_SGI_AES_ONESHOT_H_ */
