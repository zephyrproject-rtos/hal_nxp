/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 * @file  mcuxClEcc_ECDSA_GenerateProtocolDescriptor.c
 * @brief Implementation of ECDSA protocol descriptor generation functionality
 */


#include <mcuxClCore_Platform.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>
#include <mcuxClMac.h>

#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_ECDSA_Internal.h>


#ifdef MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_ECDSA_GenerateProtocolDescriptor_Deterministic)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_ECDSA_GenerateProtocolDescriptor_Deterministic(
    mcuxClSession_Handle_t session,
    mcuxClEcc_ECDSA_SignatureProtocolDescriptor_t * const pProtocolDescriptor,
    mcuxClMac_Mode_t hmacMode )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_ECDSA_GenerateProtocolDescriptor_Deterministic);
    pProtocolDescriptor->pBlindedEphemeralKeyGenFct = mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic;
    pProtocolDescriptor->pBlindedEphemeralKeyGenFct_FP_FuncId = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_ECDSA_BlindedEphemeralKeyGen_Deterministic);
    pProtocolDescriptor->pHmacModeDesc = hmacMode;
    pProtocolDescriptor->keyGenCtxSizeInWords = sizeof(mcuxClEcc_ECDSA_Deterministic_KeyGenCtx_t) / sizeof(uint32_t);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClEcc_ECDSA_GenerateProtocolDescriptor_Deterministic, MCUXCLECC_STATUS_OK, MCUXCLECC_STATUS_FAULT_ATTACK);
}
#endif /* MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC */
