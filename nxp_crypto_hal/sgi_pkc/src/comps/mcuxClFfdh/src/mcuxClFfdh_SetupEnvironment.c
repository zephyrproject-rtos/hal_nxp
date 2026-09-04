/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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
 * @file  mcuxClFfdh_Internal_SetupEnvironment.c
 * @brief mcuxClFfdh: implementation of mcuxClFfdh_SetupEnvironment
 */


#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClFfdh.h>
#include <mcuxClKey.h>

#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMath_Internal.h>

#include <internal/mcuxClFfdh_Internal_PkcDefs.h>
#include <internal/mcuxClFfdh_Internal.h>


/**
 * @brief This function sets up the general environment used by FFDH.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClFfdh_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClFfdh_SetupEnvironment(mcuxClSession_Handle_t pSession,
                                                            mcuxClFfdh_DomainParams_t *pDomainParams)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClFfdh_SetupEnvironment);

  const uint32_t byteLenP = (uint32_t) pDomainParams->lenP;
  MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(byteLenP, 0U, MCUXCLFFDH_FFDHE8192_SIZE_PRIMEP);
  const uint32_t operandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenP); /* no need to consider lenQ as lenP > lenQ*/
  const uint32_t expOperandSize = MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(byteLenP + 4U); /* extra word is a requirement for exponentiation */
  const uint32_t bufferSize = expOperandSize + MCUXCLPKC_WORDSIZE;

  /* Setup CPU workarea and PKC buffer.
     Due to MCUXCLMATH_SECMODEXP function requirements buffers have to be artificially extended before exponentiation call.
     Special care must be taken to clear unneded upper words.
     Since all moduluses from RFC 7919 have oldest bit set no modulus shifting is needed. */
  const uint32_t byteLenOperandsTable = sizeof(uint16_t) * FFDH_UPTRT_COUNT;
  const uint32_t alignedByteLenCpuWa = SIZEOF_FFDHCPUWA_T + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(byteLenOperandsTable);

  uint32_t wordNumCpuWa = alignedByteLenCpuWa / (sizeof(uint32_t));
  MCUX_CSSL_FP_FUNCTION_CALL(mcuxClFfdh_CpuWa_t*, pCpuWorkarea, mcuxClSession_allocateWords_cpuWa(pSession, wordNumCpuWa));
  /* TODO: CLNS-17418 error handling */

  /* Setup mcuxClMath UPTRT buffer at beginning of CPU/PKC WA depending on MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM and update session info */
  MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pMathUptrt, mcuxClSession_allocateWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t)));
  /* Update session info for pMathUptrt location in WA */
  pSession->pMathUptrt = pMathUptrt;

  uint32_t wordNumPkcWa = (bufferSize * FFDH_NO_OF_BUFFERS) / sizeof(uint32_t);  /* PKC bufferSize is a multiple of CPU word size. */
  if(FFDH_EXPTMP_FAME_RAM_ONLY_MAX_LENGTH < byteLenP)
  {
    /* For field elements which are too large certain memory optimizations are in place otherwise they would not fit in PKC RAM.
     * First optimization is that one of the buffers provided to MCUXCLMATH_SECMODEXP uses only 6FW.
     * Second optimization is that one of the buffers will be placed in CPU WA.
     * This needs to be considered when calculating actual WA usage.
     */
    wordNumPkcWa = (bufferSize * (FFDH_NO_OF_BUFFERS - 2U) + (6U * MCUXCLPKC_WORDSIZE)) / sizeof(uint32_t);  /* PKC bufferSize is a multiple of CPU word size. */
  }

  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, wordNumPkcWa));

  wordNumCpuWa += (MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t));

  /* Initialize CPU */
  pCpuWorkarea->wordNumCpuWa = wordNumCpuWa;
  pCpuWorkarea->wordNumPkcWa = wordNumPkcWa;
  pCpuWorkarea->operandSize = operandSize;
  pCpuWorkarea->expOperandSize = expOperandSize;

  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, mcuxClFfdh_SetupEnvironment);

  /* Setup UPTR table. */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES("MISRA Ex. 9 - Rule 11.3 - Cast to 16-bit pointer table")
  uint16_t *pOperands = (uint16_t *)MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE((uint32_t)pCpuWorkarea + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClFfdh_CpuWa_t))); /* Make UPTR table start from 64-bit aligned address */
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY_BETWEEN_INAPT_ESSENTIAL_TYPES()

  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_SETUPTRT(pOperands);

  /* Set PS1 MCLEN and LEN. */
  MCUXCLPKC_WAITFORREADY();
  MCUXCLPKC_PS1_SETLENGTH(operandSize, operandSize);
  MCUXCLPKC_FP_GENERATEUPTRT(&pOperands[FFDH_NO_OF_VIRTUALS],
                            pPkcWorkarea,
                            (uint16_t) bufferSize,
                            FFDH_NO_OF_BUFFERS);

  /* Setup virtual offset to prime p  */
  pOperands[FFDH_UPTRTINDEX_P] = pOperands[FFDH_UPTRTINDEX_PFULL] + MCUXCLPKC_WORDSIZE;

  /* Import prime P */
  MCUXCLPKC_WAITFORFINISH();
  uint8_t *pP = MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_P]);
  MCUX_CSSL_DI_RECORD(sumOfMemParams, 2U * (uint32_t)pP + (uint32_t)pDomainParams->pP + byteLenP + bufferSize);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pP, (const uint8_t *)pDomainParams->pP, byteLenP));
  MCUXCLMEMORY_CLEAR_INT(pP + byteLenP, bufferSize - byteLenP);

  /* import precomputed PDash */
  MCUX_CSSL_DI_RECORD(sumOfMemCopyParams, (uint32_t)MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_PFULL]) + (uint32_t)pDomainParams->pPDash + MCUXCLPKC_WORDSIZE);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_PFULL]), (const uint8_t *)pDomainParams->pPDash, MCUXCLPKC_WORDSIZE));

  /* Calculate Qdash (QSquared w.r.t. expOperandSize) */
  MCUXCLMATH_FP_QDASH(pSession, FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_P, FFDH_UPTRTINDEX_P, FFDH_UPTRTINDEX_T2, (uint16_t)expOperandSize);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClFfdh_SetupEnvironment,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_GenerateUPTRT),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_QDash));
}
