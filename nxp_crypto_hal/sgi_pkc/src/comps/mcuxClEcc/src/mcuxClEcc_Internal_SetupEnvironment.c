/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
#include <mcuxClMemory.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMemory_Copy_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>
#include <internal/mcuxClEcc_Internal_MemoryConsumption.h>

/**
 * This function sets up the CPU and PKC environment for ECC operations.
 * It allocates CPU and PKC workareas, initializes the UPTRT table, and sets up virtual offsets.
 *
 * Input:
 *  - pSession              Handle for the current CL session
 *  - operandSize           Size of PKC operand in bytes
 *  - noOfBuffers           Number of PKC buffers to be allocated
 *  - ppCpuWorkarea         Pointer to receive the allocated CPU workarea
 *  - ppPkcWorkarea         Pointer to receive the allocated PKC workarea
 *  - ppOperands            Pointer to receive the UPTRT table pointer
 *
 * Result:
 *  - CPU and PKC workareas allocated
 *  - UPTRT table initialized
 *  - Virtual offsets ECC_P, ECC_N, ECC_ONE, ECC_ZERO set up
 *  - ps1Len = (operandSize, operandSize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_InitializeEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_InitializeEnvironment(
    mcuxClSession_Handle_t pSession,
    uint32_t operandSize,
    uint8_t noOfBuffers,
    mcuxClEcc_CpuWa_t **ppCpuWorkarea,
    uint8_t **ppPkcWorkarea,
    uint16_t **ppOperands)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_InitializeEnvironment);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The result does not wrap. The bufferSize can't be larger than UINT32_MAX.")
    const uint32_t bufferSize = operandSize + MCUXCLPKC_WORDSIZE;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* The CPU WA layout is:
    * +-------------+-------------+------------------------+
    * | Math UPTRT  | ECC UPTRT   | ECC Allocated Memory   |
    * +-------------+-------------+------------------------+
    */

    /* Compute CPU and PKC WA sizes to allocate */
    const uint32_t byteLenOperandsTable = SIZEOF_ECC_UPTRT_WA((uint32_t)noOfBuffers, ECC_NO_OF_VIRTUALS);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("bufferSize*noOfBuffers won't wrap because bufferSize < 88 and noOfBuffers < ECC_COORD28(=0x3C)")
    const uint32_t alignedByteLenEccBuffers = bufferSize * (uint32_t) noOfBuffers;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

    /* Setup CPU workarea. */
    const uint32_t alignedByteLenCpuWa = SIZEOF_ECCCPUWA_T;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("MISRA Ex. 9 to Rule 11.3 - mcuxClEcc_CpuWa_t is 32 bit aligned")
    MCUX_CSSL_FP_FUNCTION_CALL(mcuxClEcc_CpuWa_t*, pCpuWorkarea, mcuxClSession_allocateWords_cpuWa(pSession, alignedByteLenCpuWa  / sizeof(uint32_t)));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

    /* Setup mcuxClMath UPTRT buffer at beginning of CPU/PKC WA depending on MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM and update session info */
    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pMathUptrt, mcuxClSession_allocateWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t)));
    /* Update session info for pMathUptrt location in WA */
    pSession->pMathUptrt = pMathUptrt;

    /* Setup ECC UPTRT buffer after Math UPTRT */
    MCUX_CSSL_FP_FUNCTION_CALL(uint16_t*, pOperands, mcuxClSession_allocateWords_uptrt(pSession, byteLenOperandsTable / sizeof(uint32_t)));

    /* Setup PKC buffer. */
    MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, alignedByteLenEccBuffers  / sizeof(uint32_t)));

    const uint32_t wordNumCpuWa = (alignedByteLenCpuWa +
                                   MCUXCLECC_SIZEOF_UPTRT_CPUWA((uint32_t)noOfBuffers, ECC_NO_OF_VIRTUALS)) / sizeof(uint32_t);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("The addition cannot wrap because wordNumPkcWa < MAX(PKC_RAM) < UINT32_MAX")
    const uint32_t wordNumPkcWa = (alignedByteLenEccBuffers +
                                   MCUXCLECC_SIZEOF_UPTRT_PKCWA((uint32_t)noOfBuffers, ECC_NO_OF_VIRTUALS)) / sizeof(uint32_t);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    pCpuWorkarea->wordNumCpuWa = wordNumCpuWa;
    pCpuWorkarea->wordNumPkcWa = wordNumPkcWa;

    MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, mcuxClEcc_InitializeEnvironment);

    /* Set PS1 MCLEN and LEN. */
    MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);

    /* MISRA Ex. 22, while(0) is allowed */
    MCUXCLPKC_FP_GENERATEUPTRT(& pOperands[ECC_NO_OF_VIRTUALS],
                              pPkcWorkarea,
                              (uint16_t) (bufferSize & 0xffffU),
                              noOfBuffers);
    MCUXCLPKC_SETUPTRT(pOperands);

    /* Setup virtual offsets to prime p and curve order n. */
    pOperands[ECC_P] = (pOperands[ECC_PFULL] + MCUXCLPKC_WORDSIZE) & 0xFFFFu;
    pOperands[ECC_N] = (pOperands[ECC_NFULL] + MCUXCLPKC_WORDSIZE) & 0xFFFFU;

    /* Initialize constants ONE = 0x0001 and ZERO = 0x0000 in uptr table. */
    pOperands[ECC_ONE]  = 0x0001u;
    pOperands[ECC_ZERO] = 0x0000u;

    /* Return allocated pointers */
    *ppCpuWorkarea = pCpuWorkarea;
    *ppPkcWorkarea = pPkcWorkarea;
    *ppOperands = pOperands;

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_InitializeEnvironment,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
        MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_GenerateUPTRT));
}

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
 * - The local UPTRT of Math has been put in the beginning of the PKC/CPU RAM depending on MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM.
 * - Hence, the local UPRTRT of Math (to be used by mcuxClMath_InitLocalUptrt) is setup before the ECC UPTRT in the PKC/CPU WA.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_SetupEnvironment(mcuxClSession_Handle_t pSession,
                                                                        mcuxClEcc_CommonDomainParams_t *pCommonDomainParams,
                                                                        uint8_t noOfBuffers)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_SetupEnvironment);

    const uint32_t byteLenP = (uint32_t) pCommonDomainParams->byteLenP;
    const uint32_t byteLenN = (uint32_t) pCommonDomainParams->byteLenN;
    const uint32_t byteLenMax = ((byteLenP > byteLenN) ? byteLenP : byteLenN);
    const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenMax);

    /* Initialize CPU and PKC environment */
    mcuxClEcc_CpuWa_t *pCpuWorkarea;
    uint8_t *pPkcWorkarea;
    uint16_t *pOperands;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClEcc_InitializeEnvironment(
        pSession, operandSize, noOfBuffers,
        &pCpuWorkarea, &pPkcWorkarea, &pOperands
    ));

    /* Clear buffers P, N, PQSQR and NQSQR. */
    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_SetupEnvironment_ClearBuffers,
                        mcuxClEcc_FUP_SetupEnvironment_ClearBuffers_LEN);
    MCUXCLPKC_WAITFORFINISH();

    /* Import prime p and order n, and corresponding Montgomery parameter (NDash). */

    MCUX_CSSL_DI_RECORD(sumOfMemCopyParams, (uint32_t)MCUXCLPKC_OFFSET2PTR(pOperands[ECC_PFULL]) + (uint32_t)pCommonDomainParams->pFullModulusP + MCUXCLPKC_WORDSIZE + byteLenP
                                    + (uint32_t)MCUXCLPKC_OFFSET2PTR(pOperands[ECC_NFULL]) + (uint32_t)pCommonDomainParams->pFullModulusN + MCUXCLPKC_WORDSIZE + byteLenN
                                    + (uint32_t)MCUXCLPKC_OFFSET2PTR(pOperands[ECC_PQSQR]) + (uint32_t)pCommonDomainParams->pR2P + byteLenP
                                    + (uint32_t)MCUXCLPKC_OFFSET2PTR(pOperands[ECC_NQSQR]) + (uint32_t)pCommonDomainParams->pR2N + byteLenN);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
      MCUXCLPKC_OFFSET2PTR(pOperands[ECC_PFULL]),
      (const uint8_t*)pCommonDomainParams->pFullModulusP,
      MCUXCLPKC_WORDSIZE + byteLenP
    ));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
      MCUXCLPKC_OFFSET2PTR(pOperands[ECC_NFULL]),
      (const uint8_t*)pCommonDomainParams->pFullModulusN,
      MCUXCLPKC_WORDSIZE + byteLenN
    ));

    /* Check p and n are odd (Math functions assume modulus is odd). */
    const volatile uint8_t * ptrP = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_P]);
    const volatile uint8_t * ptrN = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_N]);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("PKC buffer is CPU word aligned")
    uint32_t p0 = ((const volatile uint32_t *) ptrP)[0];
    uint32_t n0 = ((const volatile uint32_t *) ptrN)[0];
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    if (0x01u != (0x01u & p0 & n0))
    {
        MCUXCLSESSION_FAULT(pSession, MCUXCLECC_STATUS_FAULT_ATTACK);
    }

    /* Import R^2 mod p and R^2 mod n. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
      MCUXCLPKC_OFFSET2PTR(pOperands[ECC_PQSQR]),
      (const uint8_t*)pCommonDomainParams->pR2P,
      byteLenP
    ));

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(
      MCUXCLPKC_OFFSET2PTR(pOperands[ECC_NQSQR]),
      (const uint8_t*)pCommonDomainParams->pR2N,
      byteLenN
    ));

    /* Calculate shifted modulus of p and n. */
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_PS, ECC_P);
    MCUXCLMATH_FP_SHIFTMODULUS(ECC_NS, ECC_N);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_SetupEnvironment,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEcc_InitializeEnvironment),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_ShiftModulus) );
}
