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
 * @file  mcuxClEcc_Internal_SetupEnvironment.c
 * @brief mcuxClEcc: implementation of mcuxClEcc_SetupEnvironment
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClPkc.h>
#include <mcuxClMath.h>
#include <mcuxClMemory.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>

/**
 * This function sets up the general environment used by ECC functions.
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
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_SetupEnvironment(mcuxClSession_Handle_t pSession,
                                                                        mcuxClEcc_CommonDomainParams_t *pCommonDomainParams,
                                                                        uint8_t noOfBuffers)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_SetupEnvironment);

    const uint32_t byteLenP = (uint32_t) pCommonDomainParams->byteLenP;
    const uint32_t byteLenN = (uint32_t) pCommonDomainParams->byteLenN;
    const uint32_t byteLenMax = ((byteLenP > byteLenN) ? byteLenP : byteLenN);
    const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenMax);
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;

    /* Setup CPU workarea and PKC buffer. */
    const uint32_t byteLenOperandsTable = (sizeof(uint16_t)) * (ECC_NO_OF_VIRTUALS + (uint32_t) noOfBuffers);
    const uint32_t alignedByteLenCpuWa = (sizeof(mcuxClEcc_CpuWa_t)) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(byteLenOperandsTable);
    const uint32_t wordNumCpuWa = alignedByteLenCpuWa / (sizeof(uint32_t));
    mcuxClEcc_CpuWa_t *pCpuWorkarea = mcuxClEcc_castToEccCpuWorkarea(mcuxClSession_allocateWords_cpuWa(pSession, wordNumCpuWa));
    const uint32_t wordNumPkcWa = (bufferSize * (uint32_t) noOfBuffers) / (sizeof(uint32_t));  /* PKC bufferSize is a multiple of CPU word size. */
    const uint8_t *pPkcWorkarea = (uint8_t *) mcuxClSession_allocateWords_pkcWa(pSession, wordNumPkcWa);
    if ((NULL == pCpuWorkarea) || (NULL == pPkcWorkarea))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_SetupEnvironment, MCUXCLECC_STATUS_FAULT_ATTACK);
    }
    pCpuWorkarea->wordNumCpuWa = wordNumCpuWa;
    pCpuWorkarea->wordNumPkcWa = wordNumPkcWa;

    MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, &pCpuWorkarea->pkcStateBackup, mcuxClEcc_SetupEnvironment, MCUXCLECC_STATUS_FAULT_ATTACK);

    /* Set PS1 MCLEN and LEN. */
    MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);

    /* Setup UPTR table. */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Casting a pointer to a pointer of a less strictly aligned type is allowed.")
    uint16_t *pOperands = (uint16_t *) pCpuWorkarea->pOperands32;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    /* MISRA Ex. 22, while(0) is allowed */
    MCUXCLPKC_FP_GENERATEUPTRT(& pOperands[ECC_NO_OF_VIRTUALS],
                              pPkcWorkarea,
                              (uint16_t) bufferSize,
                              noOfBuffers);
    MCUXCLPKC_SETUPTRT(pOperands);

    /* Setup virtual offsets to prime p and curve order n. */
    pOperands[ECC_P] = pOperands[ECC_PFULL] + MCUXCLPKC_WORDSIZE;
    pOperands[ECC_N] = pOperands[ECC_NFULL] + MCUXCLPKC_WORDSIZE;

    /* Initialize constants ONE = 0x0001 and ZERO = 0x0000 in uptr table. */
    pOperands[ECC_ONE]  = 0x0001u;
    pOperands[ECC_ZERO] = 0x0000u;

    /* Clear buffers P, N, PQSQR and NQSQR. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_SetupEnvironment_ClearBuffers,
                        mcuxClEcc_FUP_SetupEnvironment_ClearBuffers_LEN);
    MCUXCLPKC_WAITFORFINISH();

    /* Import prime p and order n, and corresponding Montgomery parameter (NDash). */
    MCUXCLMEMORY_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR(pOperands[ECC_PFULL]), pCommonDomainParams->pFullModulusP, MCUXCLPKC_WORDSIZE + byteLenP);
    MCUXCLMEMORY_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR(pOperands[ECC_NFULL]), pCommonDomainParams->pFullModulusN, MCUXCLPKC_WORDSIZE + byteLenN);

    /* Import R^2 mod p and R^2 mod n. */
    MCUXCLMEMORY_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR(pOperands[ECC_PQSQR]), pCommonDomainParams->pR2P, byteLenP);
    MCUXCLMEMORY_FP_MEMORY_COPY(MCUXCLPKC_OFFSET2PTR(pOperands[ECC_NQSQR]), pCommonDomainParams->pR2N, byteLenN);

    /* Calculate shifted modulus of p and n. */
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_PS, ECC_P);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_NS, ECC_N);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClEcc_SetupEnvironment, MCUXCLECC_STATUS_OK,
        MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_GenerateUPTRT),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus) );
}
