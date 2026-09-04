/*--------------------------------------------------------------------------*/
/* Copyright 2021-2022, 2024-2025 NXP                                       */
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
 * @file  mcuxClEcc_Mont_Internal_DhSetupEnvironment.c
 * @brief Montgomery curve internal setup environment
 */


#include <stdint.h>

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClMemory.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClEcc_Mont_Internal.h>

#include <internal/mcuxClSession_Internal.h>

/**
 * \brief This function sets up environment used by MontDH functions.
 *
 * On top of generic ECC environment setup function, mcuxClEcc_SetupEnvironment,
 * this function further imports the ladder constant A24 = (A+2)/4 mod p,
 * converts it to Montgomery representation, and stores in buffer ECC_CP0.
 *
 * Inputs:
 *  - pSession: pointer to session descriptor;
 *  - pDomainParams: pointer to MontDH domain parameter structure;
 *  - noOfBuffers: number of buffers in PKC workarea used by calling API.
 *
 * Results:
 *  - results of mcuxClEcc_SetupEnvironment;
 *  - Buffer ECC_CP0 contains the ladder constant (A+2)/4 mod p in MR.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_MontDH_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_SetupEnvironment(mcuxClSession_Handle_t pSession,
                                                                               mcuxClEcc_MontDH_DomainParams_t *pDomainParams,
                                                                               uint8_t noOfBuffers)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_MontDH_SetupEnvironment);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_SetupEnvironment(pSession, &(pDomainParams->common), noOfBuffers));

    /* Import ladder constant (A+2)/4 mod p. */
    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T0,
                                        pDomainParams->common.pLadderConst,
                                        (uint32_t) pDomainParams->common.byteLenP, operandSize);

    /* Convert ladder constant to Montgomery representation. */
    MCUXCLPKC_FP_CALC_MC1_MM(ECC_CP0, ECC_T0, ECC_PQSQR, ECC_P);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_MontDH_SetupEnvironment,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_SetupEnvironment),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_ImportLittleEndianToPkc),
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM );
}
