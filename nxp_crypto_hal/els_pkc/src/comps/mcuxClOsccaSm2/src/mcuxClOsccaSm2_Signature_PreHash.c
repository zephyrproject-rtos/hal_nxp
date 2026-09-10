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

/** @file  mcuxClOsccaSm2_Signature_PreHash.c
 *  @brief mcuxClOsccaSm2: implementation of SM2 prehash function
 */

#include <mcuxClOsccaSm3.h>
#include <mcuxClOsccaSm2.h>
#include <mcuxClSession.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaSm2_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClKey_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm2_Signature_PreHash)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_Signature_PreHash(
    mcuxClSession_Handle_t             session,
    mcuxClKey_Handle_t                 key,
    mcuxCl_InputBuffer_t               pIdentifier,
    uint16_t                          identifierSize,
    mcuxCl_Buffer_t                    pPrehash,
    uint32_t * const                  prehashSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm2_Signature_PreHash);

    /****************************************************************/
    /* Preparation: setup SM2 key                                   */
    /****************************************************************/
    /* Set up SM2 key, to be used internally in SM2 functions */
    /* Set up domain parameters, to be used internally in SM2 functions */
    uint8_t* pPublicKey = mcuxClKey_getKeyData(key);
    mcuxClOsccaSm2_DomainParam_t *pSm2DomainParams = (mcuxClOsccaSm2_DomainParam_t *) mcuxClKey_getTypeInfo(key);

    /****************************************************************/
    /* OSCCA SM2 prehash compute                                    */
    /****************************************************************/

    /* Create parameter structure for function mcuxClOsccaSm2_ComputePrehash */
    mcuxClOsccaSm2_ComputePrehash_Param_t paramsPreHash;

    MCUXCLOSCCASM2_FP_DOMAINPARAMETER_COPY(paramsPreHash.domainParameters, (*pSm2DomainParams));
    paramsPreHash.pIdentifier = pIdentifier;
    paramsPreHash.identifierLength = identifierSize;
    paramsPreHash.pPublicKey = pPublicKey;
    paramsPreHash.pPrehash = pPrehash;

    /* Call function mcuxClOsccaSm2_ComputePrehash */
    MCUX_CSSL_FP_FUNCTION_CALL(SM2PreHashRet, mcuxClOsccaSm2_ComputePrehash(session, &paramsPreHash));
    if(MCUXCLOSCCASM2_STATUS_COMPUTE_PREHASH_OK != SM2PreHashRet)
    {
        /* FA is the only negative return code from mcuxClOsccaSm2_ComputePrehash. */
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Signature_PreHash, MCUXCLOSCCASM2_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Caller should set *prehashSize properly to make sure not wrap.")
    *prehashSize += MCUXCLOSCCASM3_OUTPUT_SIZE_SM3;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm2_Signature_PreHash, MCUXCLOSCCASM2_STATUS_OK,
                                              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm2_ComputePrehash));

}
