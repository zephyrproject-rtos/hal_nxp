/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClOsccaSm2_Keyagreement.c
 *  @brief mcuxClOsccaSm2: implementation of SM2 Sign function
 */
#include <mcuxClSession.h>
#include <mcuxClOsccaSm2.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslSecureCounter.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm2_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClKey_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm2_key_agreement, mcuxClKey_AgreementFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClOsccaSm2_key_agreement(
    mcuxClSession_Handle_t session,
    mcuxClKey_Agreement_t agreement,
    mcuxClKey_Handle_t key,
    mcuxClKey_Handle_t otherKey,
    mcuxClKey_Agreement_AdditionalInput_t additionalInputs[],
    uint32_t numberOfInputs,
    uint8_t * pOut,
    uint32_t * const pOutLength
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm2_key_agreement);

    /*****************************************************/
    /* Perform key agreement operation                   */
    /*****************************************************/
    /* Setup the parameters used by SM2 internal functions */

    /* Set up SM2 key, to be used internally in SM2 functions */
    /* Set up domain parameters, to be used internally in SM2 functions */
    uint8_t* privateKey = mcuxClKey_getKeyData(key);
    uint8_t* publicKeyParty2 = mcuxClKey_getKeyData(otherKey);
    mcuxClOsccaSm2_DomainParam_t *pSm2DomainParams = (mcuxClOsccaSm2_DomainParam_t *) mcuxClKey_getTypeInfo(key);

    /* Setup the parameters used by SM2 internal functions, based on the protocol descriptor */
    uint16_t options = ((const mcuxClOsccaSm2_AgreementProtocolDescriptor_t*)agreement->pProtocolDescriptor)->options;

    /****************************************************************/
    /* OSCCA SM2 key agreement                                      */
    /****************************************************************/
    /* Create parameter structure for function mcuxClOsccaSm2_KeyExchange */
    mcuxClOsccaSm2_KeyExchange_Param_t param;
    MCUXCLOSCCASM2_FP_DOMAINPARAMETER_COPY(param.domainParameters, (*pSm2DomainParams));
    param.pPrivateKey = privateKey;
    param.pPublicKeyParty2 = publicKeyParty2;
    param.pCommonSecret = pOut;
    param.commonSecretLength = *pOutLength;

    if (numberOfInputs != MCUXCLOSCCASM2_KEYAGREEMENT_NUM_OF_ADDITIONAL_INPUTS)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_key_agreement, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }
    param.pPreHashInfoInitiator = additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_PREHASH_INITIATOR].input;
    param.pPreHashInfoResponder = additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_PREHASH_RESPONDER].input;
    param.pPrivateEphemeralScalar = additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_PRIVATEEPHEMERALKEY].input;
    param.pPublicEphemeralPoint = additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_PUBLICEPHEMERALPOINT].input;
    param.pPublicEphemeralPointParty2 = additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_PUBLICEPHEMERALPOINT_PARTY2].input;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to set the generic pointer.")
    param.pConfirmationFromResponderToInitiator = (mcuxCl_Buffer_t)(additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_CONFIRMATION_R2I].input);
    param.pConfirmationFromInitiatorToResponder = (mcuxCl_Buffer_t)(additionalInputs[MCUXCLOSCCASM2_KEYAGREEMENT_CONFIRMATION_I2R].input);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
    param.options = options;

    /* Call function mcuxClOsccaSm2_KeyExchange */
    MCUX_CSSL_FP_FUNCTION_CALL(SM2KeyExchgRet, mcuxClOsccaSm2_KeyExchange(session, &param));
    if (MCUXCLOSCCASM2_STATUS_KEYEXCHANGE_OK != SM2KeyExchgRet)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_key_agreement, MCUXCLKEY_STATUS_FAILURE, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_KeyExchange));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_key_agreement, MCUXCLKEY_STATUS_OK,
                                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_KeyExchange));

}
