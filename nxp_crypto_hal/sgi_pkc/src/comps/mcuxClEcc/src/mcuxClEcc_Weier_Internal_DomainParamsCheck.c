/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_DomainParamsCheck.c
 * @brief Weierstrass curve internal domain params check
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClSession.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_FP.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>


/**
 * This function performs basic domain parameters checks:
 * 1) |byteLenP - byteLenN| =< 1
 * 2) a < p
 * 3) b < p
 * 4) n != p
 * 5) n != all one bits
 * 6) check if curve is nonsingular
 * 7) base point on curve check
 *
 * Prerequisites:
 *   buffer WEIER_A contains curve coefficient a, Montgomery representation;
 *   buffer ECC_TO contains curve coefficient a, normal representation;
 *   buffer WEIER_B contains curve coefficient b, normal representation;
 *   ps1Len = (operandSize, operandSize);
 *   curve order p in P, NDash of p in PFULL,
 *   shifted modulus of p in PS, QSquare of p in PQSQR.
 *   buffer (ECC_S0, ECC_S1) contains imported base point
 *
 * Result in PKC workarea:
 *   buffer ECC_T1 contains discriminant 4*a^3 + 27*b^2 mod p, in the range [0, p-1].
 *
 * Other modifications:
 *   buffers ECC_S2, ECC_S3, ECC_T2 are modified (as temp)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_DomainParamsCheck)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_DomainParamsCheck(mcuxClSession_Handle_t pSession, const uint32_t byteLenP, const uint32_t byteLenN)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_DomainParamsCheck);

    /* 1) Check if |byteLenP - byteLenN| =< 1 */
    const uint32_t byteLenDiff = (byteLenP > byteLenN) ? (byteLenP - byteLenN) : (byteLenN - byteLenP);
    if (byteLenDiff > 1u)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }


    /* 2) Check if a < p */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_T0, ECC_P);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* 3) Check if b < p */
    MCUXCLPKC_FP_CALC_OP1_CMP(WEIER_B, ECC_P);
    if (MCUXCLPKC_FLAG_NOCARRY == MCUXCLPKC_WAITFORFINISH_GETCARRY())
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* 4) Check if n != p */
    MCUXCLPKC_FP_CALC_OP1_CMP(ECC_P, ECC_N);
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    const uint32_t nSizeInFW32 = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenN) / sizeof(uint32_t);
    /* 5) n is different than all ones */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint32_t * ptrNS = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_NS]);
    const uint32_t pkcLen32 = MCUXCLPKC_WORDSIZE / sizeof(uint32_t);
    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(pkcLen32, 0u, nSizeInFW32)
    const uint32_t shortenedOpLen32 = nSizeInFW32 - pkcLen32;
    uint32_t allOnes = MCUXCLECC_ALL_ONES_WORD;

    /* Check most significant pkc word of shifted modulus */
    for(uint32_t i = 0u; i < pkcLen32; ++i)
    {
        allOnes &= ptrNS[shortenedOpLen32 + i];
    }

    if(MCUXCLECC_ALL_ONES_WORD == allOnes)
    {
        /* Check pkc words of normal modulus excluding most significant pkc word */
        const uint32_t * ptrN = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_N]);
        for(uint32_t i = 0u; i < shortenedOpLen32; ++i)
        {
            allOnes &= ptrN[i];
        }

        if(MCUXCLECC_ALL_ONES_WORD == allOnes)
        {
            MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
        }
    }

    /* 6) Check if curve is nonsingular (does not have cusps or intersections) */
    /* Calculate 4*a^3 + 27*b^2 mod p */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_DiscriminantCalculate,
                        mcuxClEcc_FUP_Weier_DiscriminantCalculate_LEN);

    /* Check if result != 0. */
    if (MCUXCLPKC_FLAG_ZERO == MCUXCLPKC_WAITFORFINISH_GETZERO())
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }

    /* 7) Verify correctness of affine coordinates of G in NR */
    MCUX_CSSL_FP_FUNCTION_CALL(pointCheckBasePointStatus, mcuxClEcc_PointCheckAffineNR(pSession));
    if (MCUXCLECC_INTSTATUS_POINTCHECK_NOT_OK == pointCheckBasePointStatus)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLECC_STATUS_INVALID_PARAMS);
    }
    else if (MCUXCLECC_STATUS_OK != pointCheckBasePointStatus)
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    else
    {
        /* Do nothing. */
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Weier_DomainParamsCheck, MCUXCLECC_FP_WEIERECC_DOMAINPARAMSCHECK_FINAL);
}
