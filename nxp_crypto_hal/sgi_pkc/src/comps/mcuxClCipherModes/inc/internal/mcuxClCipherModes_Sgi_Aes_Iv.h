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

#ifndef MCUXCLCIPHERMODES_SGI_AES_IV_H_
#define MCUXCLCIPHERMODES_SGI_AES_IV_H_

#include <mcuxClSession_Types.h>
#include <internal/mcuxClCipherModes_Common_Wa.h>
#include <mcuxClSgi_Types.h>
#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
#include <mcuxClDma_Types.h>
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief Function used to load IV
 *
 * @param[in]     session     Handle for the current CL session.
 * @param[in,out] pWa         pointer to workarea used in cipher mode (word-aligned).
 * @param[in,out] pIv         pointer to buffer of IV.
 *
 * @post
 *  - pWa->pIV and pWa->ctrSize will be updated.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_IV, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv
);

/**
 * @brief Function sets pointer to inital vector to NULL for modes where it is not needed.
 *
 * @param[in]     session     Handle for the current CL session.
 * @param[in,out] pWa         pointer to workarea used in cipher mode (word-aligned).
 * @param[in]     pIv         pointer to buffer of IV, it is UNUSED.
 *
 * @post
 *  - pWa->pIV is set to NULL
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_No_IV, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_No_IV(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t* pWa,
  mcuxCl_InputBuffer_t pIv
);

#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
/**
 * @brief Function copies IV to SGI DATIN0.
 *
 * @param[in]     session     Handle for the current CL session.
 * @param[in,out] pWa         pointer to workarea used in cipher mode (word-aligned).
 * @param[in]     pIv         pointer to buffer of IV.
 * 
 * @post
 *   - pWa->pIV will be updated.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_IV_AutoMode_Ctr, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV_AutoMode_Ctr(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv
);

/**
 * @brief Function copies IV to SGI DATOUT.
 *
 * @param[in]     session     Handle for the current CL session.
 * @param[in,out] pWa         pointer to workarea used in cipher mode (word-aligned).
 * @param[in]     pIv         pointer to buffer of IV.
 *
 * @post
 *   - pWa->pIV will be updated.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_IV_to_DATOUT_DMA, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV_to_DATOUT_DMA(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv
);

/**
 * @brief Function copies IV to SGI DATIN2.
 *
 * @param[in]     session     Handle for the current CL session.
 * @param[in,out] pWa         pointer to workarea used in cipher mode (word-aligned).
 * @param[in]     pIv         pointer to buffer of IV.
 *
 * @post
 *   - pWa->pIV will be updated.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_IV_AutoMode_Cbc_Dec, mcuxClCipherModes_SetupIvFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_IV_AutoMode_Cbc_Dec(
  mcuxClSession_Handle_t session,
  mcuxClCipherModes_WorkArea_t *pWa,
  mcuxCl_InputBuffer_t pIv
);
#endif /* MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING */

/**
 * @brief Function checks length of the IV for modes where inital vector is not needed.
 *
 * @param[in] ivLength          Length of the IV
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_checkIvLen_noIv, mcuxClCipherModes_CheckIvLength_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_checkIvLen_noIv(
  mcuxClSession_Handle_t session,
  uint32_t ivLength);

/**
 * @brief Function checks length of the IV for modes where inital vector is needed.
 *
 * @param[in] ivLength          Length of the IV
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClCipherModes_checkIvLen, mcuxClCipherModes_CheckIvLength_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_checkIvLen(
  mcuxClSession_Handle_t session,
  uint32_t ivLength);

#endif /* MCUXCLCIPHERMODES_SGI_AES_IV_H_ */
