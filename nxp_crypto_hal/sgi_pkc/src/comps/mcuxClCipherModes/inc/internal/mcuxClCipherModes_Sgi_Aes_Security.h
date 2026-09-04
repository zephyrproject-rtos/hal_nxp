/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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

#ifndef MCUXCLCIPHERMODES_SGI_AES_SECURITY_H_
#define MCUXCLCIPHERMODES_SGI_AES_SECURITY_H_

#include <mcuxClCore_Platform.h>

#include <mcuxClBuffer.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession.h>

#include <internal/mcuxClCipherModes_Sgi_Types.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_Functions.h>


/**
 * @brief Function used for DFA protection.
 *
 * This function is capable of computing en/decryption multiple times (depends on security setting
 * and feature SESSION_SECURITYOPTIONS_ADDITIONAL_SWCOMP) and comparing CRC result
 * of each calculation with each other to determine if any fault was injected in between calculations
 *
 * This function fulfills SREQI_BCIPHER_11
 * Code flow is described in detail in SREQI_BCIPHER_11
 *
 * @param      session      Handle for the current CL session.
 * @param[in]  pWa          Pointer to cpu workarea (word-aligned)
 * @param[in]  pIn          Buffer which holds the input data
 * @param[in]  pOut         Buffer to hold the output data
 * @param[in]  inLength     Length of input data
 * @param[in]  pIvOut       Pointer for the updated Iv
 * @param[in]  pOutLength   Pointer to length of output data
 * @param[in]  pKeyChecksum Pointer to mcuxClKey_KeyChecksum_t
 * @param[in]  cryptEngine  Engine function to do the specified crypt operation
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_crypt)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_crypt(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIn,
  mcuxCl_Buffer_t pOut,
  uint32_t inLength,
  uint32_t* pIvOut,
  uint32_t* const pOutLength,
  mcuxClKey_KeyChecksum_t* pKeyChecksum,
  mcuxClCipherModes_EngineFunc_AesSgi_t cryptEngine,
  uint32_t protectionToken_cryptEngine
);

#endif /* MCUXCLCIPHERMODES_SGI_AES_SECURITY_H_ */
