/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025 NXP                                                 */
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
 * @file  mcuxClEcc_EdDSA_GenerateSignatureMode.c
 * @brief implementation of signature modes
 */

#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClSignature.h>
#include <internal/mcuxClSignature_Internal.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClEcc_EdDSA_Internal.h>

/**
 * @brief This function implements the protocol descriptor generation for Ed25519ctx, Ed25519ph, Ed448 and Ed448ph
 *
 * @param[in]  pSession             Handle for the current CL session
 * @param[in]  pDomainParams        Pointer to domain parameters of the used curve
 * @param[in]  pProtocolDescriptor  Protocol descriptor specifying the EdDSA variant
 * @param[in]  phflag               Option whether pre-hashing is enabled
 * @param[in]  pContext             User input context for the hash prefix
 * @param[in]  contextLen           Length of the context
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK                EdDSA protocol descriptor generated successfully
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateProtocolDescriptor)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_GenerateProtocolDescriptor(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *pProtocolDescriptor,
    uint32_t phflag,
    mcuxCl_InputBuffer_t pContext,
    uint32_t contextLen)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_GenerateProtocolDescriptor);

    /* Create pHashPrefix buffer after the protocol descriptor. */
    /* It is assumed that sufficient space was allocated by users with the macro MCUXCLECC_EDDSA_SIZE_HASH_PREFIX */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    uint8_t *pHashPrefix = (uint8_t*)pProtocolDescriptor + sizeof(mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* Generate the hash prefix */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_GenerateHashPrefix(pSession, pDomainParams, phflag, pContext, contextLen, pHashPrefix));

    pProtocolDescriptor->generateOption = 0u;
    pProtocolDescriptor->verifyOption = 0u;
    pProtocolDescriptor->phflag = phflag;
    pProtocolDescriptor->pHashPrefix = pHashPrefix;
    pProtocolDescriptor->hashPrefixLen = MCUXCLECC_EDDSA_SIZE_HASH_PREFIX(pDomainParams->domPrefixLen, contextLen);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_GenerateProtocolDescriptor,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateHashPrefix) );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateSignatureModeDescriptor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_GenerateSignatureModeDescriptor(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxClSignature_ModeDescriptor_t *pSignatureMode,
    uint32_t phflag,
    mcuxCl_InputBuffer_t pContext,
    uint32_t contextLen)
{
    MCUXCLSESSION_ENTRY(pSession, mcuxClEcc_EdDSA_GenerateSignatureModeDescriptor, diRefValue, MCUXCLECC_STATUS_FAULT_ATTACK);

    /* Create protocol descriptor after the signature mode descriptor. */
    /* It is assumed that sufficient space was allocated by users, with the macro MCUXCLECC_EDDSA_SIGNATURE_MODE_SIZE */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Reinterpret structure for pProtocolDescriptor type, change uint8_t * to mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *")
    mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *pProtocolDescriptor = (mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *) ((uint8_t*)pSignatureMode + sizeof(mcuxClSignature_ModeDescriptor_t));

    /* Fill signature protocol parameters for EdDSA with the hash prefix */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_EdDSA_GenerateProtocolDescriptor(pSession, pDomainParams, pProtocolDescriptor, phflag, pContext, contextLen));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

    /* Fill signature mode parameters for EdDSA */
    pSignatureMode->pSignFct = mcuxClEcc_EdDSA_GenerateSignature;
    pSignatureMode->protection_token_sign = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateSignature);
    pSignatureMode->pVerifyFct = mcuxClEcc_EdDSA_VerifySignature;
    pSignatureMode->protection_token_verify = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_VerifySignature);
    pSignatureMode->pProtocolDescriptor = pProtocolDescriptor;

    MCUXCLSESSION_EXIT(pSession, mcuxClEcc_EdDSA_GenerateSignatureModeDescriptor, diRefValue, MCUXCLECC_STATUS_OK, MCUXCLECC_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateProtocolDescriptor));
}
