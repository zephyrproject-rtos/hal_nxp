/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClEcc_EdDSA_Internal_SetupEnvironment.c
 * @brief EdDSA internal setup environment
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClEcc_EdDSA_Internal.h>

#include <internal/mcuxClSession_Internal.h>

/**
 * This function sets up the general environment used by EdDSA functions.
 * In particular, it sets up the utilized co-processors, prepares the PKC workarea layout,
 * and initializes it for Montgomery arithmetic modulo p and n.
 *
 * Input:
 *  - pSession              Handle for the current CL session
 *  - pCommonDomainParams   Pointer to domain parameter struct passed via API
 *  - noOfBuffers           Number of PKC buffers to be allocated
 *
 * Result:
 *  - The pointer table has been properly setup in CPU workarea and PKC buffers have been allocated
 *  - The PKC state has been backed up in CPU workarea and the PKC has been enabled
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers ECC_PFULL and ECC_NFULL contain p'||p and n'||n, respectively
 *  - Buffers ECC_PS and ECC_NS contain the p resp. n shifted to the PKC word boundary
 *  - Buffers ECC_PQSQR and ECC_NQSQR contain the R^2 values modulo p and n, respectively
 *  - Virtual pointers ECC_P and ECC_N point to the second PKC word of ECC_PFULL and ECC_NFULL, respectively
 *  - Virtual pointers ECC_ZERO and ECC_ONE have been initialized with 0 and 1, respecitvely
 *  - The domain parameters a and d are stored in buffers ECC_CP0 and ECC_CP1 in MR
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_EdDSA_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_SetupEnvironment(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    uint8_t noOfBuffers )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_EdDSA_SetupEnvironment);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SetupEnvironment(pSession, &(pDomainParams->common), noOfBuffers));

    /* Import curve parameters a and d, convert them to MR modulo p, and store them in buffers ECC_CP0 and ECC_CP1. */
    uint32_t byteLenP = (uint32_t) pDomainParams->common.byteLenP;
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T0, pDomainParams->common.pCurveParam1, byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T1, pDomainParams->common.pCurveParam2, byteLenP, operandSize);
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_CP0, ECC_T0, ECC_PQSQR, ECC_P);
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_CP1, ECC_T1, ECC_PQSQR, ECC_P);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_EdDSA_SetupEnvironment,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SetupEnvironment),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM );
}
