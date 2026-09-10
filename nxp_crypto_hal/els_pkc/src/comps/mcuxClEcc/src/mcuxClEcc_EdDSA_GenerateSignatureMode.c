/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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
#include <mcuxClSession.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClEcc_EdDSA_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_GenerateProtocolDescriptor)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_GenerateProtocolDescriptor(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *pProtocolDescriptor,
    uint32_t phflag,
    mcuxCl_InputBuffer_t pContext,
    uint32_t contextLen)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_GenerateProtocolDescriptor);

    (void) pSession;

    /* Create pHashPrefix buffer after the protocol descriptor. */
    /* It is assumed that sufficient space was allocated by users with the macro MCUXCLECC_EDDSA_SIZE_HASH_PREFIX */
    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    uint8_t *pHashPrefix = (uint8_t*)pProtocolDescriptor + sizeof(mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY()

    /* Generate the hash prefix */
    MCUX_CSSL_FP_FUNCTION_CALL(retVal_GenHashPrefix, mcuxClEcc_EdDSA_GenerateHashPrefix(pDomainParams, phflag, pContext, contextLen, pHashPrefix));
    if (MCUXCLECC_STATUS_OK != retVal_GenHashPrefix)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_EdDSA_GenerateProtocolDescriptor, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    pProtocolDescriptor->generateOption = 0u;
    pProtocolDescriptor->verifyOption = 0u;
    pProtocolDescriptor->phflag = phflag;
    pProtocolDescriptor->pHashPrefix = pHashPrefix;
    pProtocolDescriptor->hashPrefixLen = MCUXCLECC_EDDSA_SIZE_HASH_PREFIX(pDomainParams->domPrefixLen, contextLen);

    MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(mcuxClEcc_EdDSA_GenerateProtocolDescriptor, MCUXCLECC_STATUS_OK, MCUXCLECC_STATUS_FAULT_ATTACK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_EdDSA_GenerateHashPrefix) );
}

