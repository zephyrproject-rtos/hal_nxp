/*--------------------------------------------------------------------------*/
/* Copyright 2018-2023 NXP                                                  */
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

/**
 * @file  mcuxClOsccaSm2_Internal_CryptoUtils.h
 * @brief mcuxClOsccaSm2: internal implementation of SM2 Ctypyo Utils function
 */


#ifndef MCUXCLOSCCASM2_INTERNAL_CRYPTOUTILS_H_
#define MCUXCLOSCCASM2_INTERNAL_CRYPTOUTILS_H_

#include <mcuxClOsccaSm2_Types.h>
#include <mcuxClSession_Types.h>
#include <internal/mcuxClOsccaSm2_Internal_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>


MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_KDF)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_KDF(mcuxClSession_Handle_t session, mcuxClOsccaSm2_KDF_Param_t *pKDFParam);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_SecondPartOfInitPhase)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_SecondPartOfInitPhase(
        mcuxClSession_Handle_t session,
        uint32_t primeLength,
        uint8_t const*pX2, mcuxClOsccaSm2_Internal_EncDecCtx_t *pCtx);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_EncDec_UpdatePhase)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_EncDec_UpdatePhase(
        mcuxClSession_Handle_t session,
        mcuxClOsccaSm2_EncDec_Common_Param_t *pParams,
        uint32_t functionCode);
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_ValidateEncDecCtx)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_ValidateEncDecCtx(
        mcuxClOsccaSm2_Internal_EncDecCtx_t *pCtx,
        uint32_t pLen);

#endif /* MCUXCLOSCCASM2_INTERNAL_CRYPTOUTILS_H_ */
