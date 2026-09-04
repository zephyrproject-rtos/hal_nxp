/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_IntegrityCheckPN.c
 * @brief mcuxClEcc: implementation of integrity check for p and n
 */


#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>

#include <internal/mcuxClEcc_Internal.h>

#include <internal/mcuxClSession_Internal.h>

/**
 * This function check integrity of base point order n, and modulus p, and their shifted counterparts
 *
 * Prerequisites:
 * Buffer ECC_P contains the modulus p
 * Buffer ECC_PS contains the shifted modulus associated to p
 * Buffer ECC_N contains the base point order n
 * Buffer ECC_NS contains the shifted base point order associated to n
 *
 * Input:
 * @param[in]     pCommonDomainParams       Pointer to domain parameter struct passed via API

 * @return status
 * @retval #MCUXCLECC_STATUS_OK              if integrity check passes.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_IntegrityCheckPN)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_IntegrityCheckPN(mcuxClSession_Handle_t pSession, mcuxClEcc_CommonDomainParams_t *pCommonDomainParams)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_IntegrityCheckPN);

    const uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    const uint32_t byteLenP = (uint32_t) pCommonDomainParams->byteLenP;
    const uint32_t byteLenN = (uint32_t) pCommonDomainParams->byteLenN;

    /* Import prime p and order n again. */
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T0, &(pCommonDomainParams->pFullModulusP[MCUXCLPKC_WORDSIZE]), byteLenP, operandSize);
    MCUXCLPKC_FP_IMPORTLITTLEENDIANTOPKC_DI_BALANCED(ECC_T1, &(pCommonDomainParams->pFullModulusN[MCUXCLPKC_WORDSIZE]), byteLenN, operandSize);

    /* Re-calculate shifted prime p and shifted order N */
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_T2, ECC_T0);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_T3, ECC_T1);

    /* Compare re-imported with existing values for p and n. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T0, ECC_P);
    uint32_t zeroFlag_checkP = MCUXCLPKC_WAITFORFINISH_GETZERO();
    MCUX_CSSL_DI_RECORD(sigValiditycheckP, (uint32_t)zeroFlag_checkP);

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T1, ECC_N);
    uint32_t zeroFlag_checkN = MCUXCLPKC_WAITFORFINISH_GETZERO();
    MCUX_CSSL_DI_RECORD(sigValiditycheckN, (uint32_t)zeroFlag_checkN);

    /* Compare re-imported with existing values for shifted p and shifted n. */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T2, ECC_PS);
    uint32_t zeroFlag_checkShiftedP = MCUXCLPKC_WAITFORFINISH_GETZERO();
    MCUX_CSSL_DI_RECORD(sigValiditycheckShiftedP, (uint32_t)zeroFlag_checkShiftedP);

    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T3, ECC_NS);
    uint32_t zeroFlag_checkShiftedN = MCUXCLPKC_WAITFORFINISH_GETZERO();
    MCUX_CSSL_DI_RECORD(sigValiditycheckShiftedN, (uint32_t)zeroFlag_checkShiftedN);

    /* Return FAULT_ATTACK if a check failed. */
    if ((MCUXCLPKC_FLAG_ZERO != zeroFlag_checkP)
        || (MCUXCLPKC_FLAG_ZERO != zeroFlag_checkN) || (MCUXCLPKC_FLAG_ZERO != zeroFlag_checkShiftedP) || (MCUXCLPKC_FLAG_ZERO != zeroFlag_checkShiftedN))
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_DI_EXPUNGE(sigValiditycheckN, MCUXCLPKC_FLAG_ZERO);
    MCUX_CSSL_DI_EXPUNGE(sigValiditycheckP, MCUXCLPKC_FLAG_ZERO);
    MCUX_CSSL_DI_EXPUNGE(sigValiditycheckShiftedN, MCUXCLPKC_FLAG_ZERO);
    MCUX_CSSL_DI_EXPUNGE(sigValiditycheckShiftedP, MCUXCLPKC_FLAG_ZERO);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_IntegrityCheckPN,
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTLITTLEENDIANTOPKC_BUFFER,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP,
        MCUXCLPKC_FP_CALLED_CALC_OP1_CMP);
}
