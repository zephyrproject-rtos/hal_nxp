/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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
 * @file  mcuxClEcc_Weier_Internal_SetupEnvironment.c
 * @brief Weierstrass curve internal setup environment
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClPkc.h>
#include <mcuxClMath.h>
#include <mcuxClMemory.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClEcc_Weier_Internal.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Weier_SetupEnvironment(
        mcuxClSession_Handle_t pSession,
        const mcuxClEcc_DomainParam_t *pWeierDomainParams,
        uint8_t noOfBuffers )
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_SetupEnvironment);

    /**********************************************************/
    /* Initialization                                         */
    /**********************************************************/
    const uint32_t byteLenP = (pWeierDomainParams->misc & mcuxClEcc_DomainParam_misc_byteLenP_mask) >> mcuxClEcc_DomainParam_misc_byteLenP_offset;
    const uint32_t byteLenN = (pWeierDomainParams->misc & mcuxClEcc_DomainParam_misc_byteLenN_mask) >> mcuxClEcc_DomainParam_misc_byteLenN_offset;
    const uint32_t byteLenMax = ((byteLenP > byteLenN) ? byteLenP : byteLenN);
    const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenMax);
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;

    /* Setup CPU workarea and PKC buffer. */
    const uint32_t byteLenOperandsTable = (sizeof(uint16_t)) * (ECC_NO_OF_VIRTUALS + (uint32_t) noOfBuffers);
    const uint32_t alignedByteLenCpuWa = (sizeof(mcuxClEcc_CpuWa_t)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(byteLenOperandsTable);
    const uint32_t wordNumCpuWa = alignedByteLenCpuWa / (sizeof(uint32_t));
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_allocateWords_cpuWa(pSession, wordNumCpuWa));
    const uint32_t wordNumPkcWa = (bufferSize * noOfBuffers) / (sizeof(uint32_t));
    const uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordNumPkcWa);

    if ((NULL == pCpuWorkarea) || (NULL == pPkcWorkarea))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SetupEnvironment, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    pCpuWorkarea->wordNumCpuWa = wordNumCpuWa;
    pCpuWorkarea->wordNumPkcWa = wordNumPkcWa;

    MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, &pCpuWorkarea->pkcStateBackup, mcuxClEcc_Weier_SetupEnvironment, MCUXCLECC_STATUS_FAULT_ATTACK);

    /* Set PS1 MCLEN and LEN. */
    MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);

    /* Setup uptr table. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting a pointer to a pointer of a less strictly aligned type is allowed.")
    uint16_t *pOperands = (uint16_t *) pCpuWorkarea->pOperands32;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    MCUXCLPKC_FP_GENERATEUPTRT(& pOperands[ECC_NO_OF_VIRTUALS],
                              pPkcWorkarea,
                              (uint16_t) bufferSize,
                              noOfBuffers);
    MCUXCLPKC_SETUPTRT(pOperands);

    /* Setup virtual offsets to prime p and curve order n. */
    pOperands[ECC_P] = (uint16_t) (pOperands[ECC_PFULL] + MCUXCLPKC_WORDSIZE);
    pOperands[ECC_N] = (uint16_t) (pOperands[ECC_NFULL] + MCUXCLPKC_WORDSIZE);

    /* Initialize constants ONE = 0x0001 and ZERO = 0x0000 in uptr table. */
    pOperands[ECC_ONE]  = 0x0001u;
    pOperands[ECC_ZERO] = 0x0000u;


    /**********************************************************/
    /* Import / prepare curve parameters                      */
    /**********************************************************/

    /* Import prime p and order n. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_SetupEnvironment, ECC_P, pWeierDomainParams->pP, byteLenP);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_SetupEnvironment, ECC_N, pWeierDomainParams->pN, byteLenN);

    /* Check p and n are odd (Math functions assume modulus is odd). */
    /* TODO (CLNS-5401) Once this function gets removed it must be ensured that the check if p and n are odd is still executed by mcuxClEcc_WeierECC_GenerateDomainParams as this is a requirement for this function. */
    const volatile uint32_t * ptrP = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_P]);
    const volatile uint32_t * ptrN = MCUXCLPKC_OFFSET2PTRWORD(pOperands[ECC_N]);
    uint32_t p0 = ptrP[0];
    uint32_t n0 = ptrN[0];
    if (0x01u != (0x01u & p0 & n0))
    {
        mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
        MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession, &pCpuWorkarea->pkcStateBackup,
            mcuxClEcc_Weier_SetupEnvironment, MCUXCLECC_STATUS_FAULT_ATTACK);

        mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SetupEnvironment, MCUXCLECC_STATUS_INVALID_PARAMS,
            MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_GenerateUPTRT),
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
            MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE);
    }

    /* Calculate NDash of p and n, ShiftModulus of p and n, QSquared of p. */
    MCUXCLMATH_FP_NDASH(ECC_P, ECC_T0);
    MCUXCLMATH_FP_NDASH(ECC_N, ECC_T0);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_PS, ECC_P);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_NS, ECC_N);
    MCUXCLMATH_FP_QSQUARED(ECC_PQSQR, ECC_PS, ECC_P, ECC_T0);

    /* Import coefficients a and b, and convert a to MR. */
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_SetupEnvironment, ECC_T0, pWeierDomainParams->pA, byteLenP);
    MCUXCLPKC_FP_CALC_MC1_MM(WEIER_A, ECC_T0, ECC_PQSQR, ECC_P);
    MCUXCLPKC_FP_IMPORTBIGENDIANTOPKC_BUFFER(mcuxClEcc_Weier_SetupEnvironment, WEIER_B, pWeierDomainParams->pB, byteLenP);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_Weier_SetupEnvironment, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_GenerateUPTRT),
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_NDash),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QSquared),
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER,
        MCUXCLPKC_FP_CALLED_CALC_MC1_MM,
        MCUXCLPKC_FP_CALLED_IMPORTBIGENDIANTOPKC_BUFFER );
}
