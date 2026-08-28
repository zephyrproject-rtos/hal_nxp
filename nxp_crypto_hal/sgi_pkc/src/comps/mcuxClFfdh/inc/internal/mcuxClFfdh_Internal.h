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
 * @file  mcuxClFfdh_Internal.h
 * @brief internal header of mcuxClFfdh functionalities
 */

#ifndef MCUXCLFFDH_INTERNAL_H
#define MCUXCLFFDH_INTERNAL_H

#include <mcuxClCore_Macros.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClBuffer.h>
#include <mcuxClFfdh_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClSession.h>

#include <internal/mcuxClKey_Types_Internal.h>


#ifdef __cplusplus
extern "C" {
#endif

/* Define for mcuxClFfdh_CpuWa_t size */
#define SIZEOF_FFDHCPUWA_T \
  (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(sizeof(mcuxClFfdh_CpuWa_t)) + sizeof(uint32_t) \
  ) /* Reserve 1 word for making UPTR table start from 64-bit aligned address */

/**********************************************************/
/*                                                        */
/* Definition of CPU workarea layout of FFDH APIs         */
/*                                                        */
/**********************************************************/
typedef struct
{
  uint32_t wordNumCpuWa;   /* number of words (uint32_t) used in CPU workarea */
  uint32_t wordNumPkcWa;   /* number of words (uint32_t) used in PKC workarea */
  uint32_t operandSize;    /* size of basic operand buffer */
  uint32_t expOperandSize; /* size of extended (exponentiation) operand buffer */
} mcuxClFfdh_CpuWa_t;

/*********************************************************/
/*                                                       */
/* Definition of FFDH domain parameters                  */
/*                                                       */
/*********************************************************/

/**
 * Domain FFDH parameter structure.
 */
struct mcuxClFfdh_DomainParams
{
  uint32_t lenP;   ///< byte length of prime p
  uint32_t lenQ;   ///< byte length of prime q
  uint8_t* pP;     ///< p (in little endian format)
  uint8_t* pPDash; ///< pDash = (-p)^-1 mod 256^(MCUXCLPKC_WORDSIZE)
};

/**
 * @brief This function sets up the general environment used by FFDH functions.
 * In particular, it sets up the utilized co-processors, prepares the PKC workarea layout,
 * and initializes it for Montgomery arithmetic modulo p
 *
 * @param[in] pSession          Handle for the current CL session
 * @param[in] pDomainParams     Pointer to domain parameter struct passed via API
 *
 * Result:
 *  - The pointer table has been properly setup in CPU workarea and PKC buffers have been allocated
 *  - The PKC state has been backed up in CPU workarea and the PKC has been enabled
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffers FFDH_PFULL contains p'||p
 *  - Buffers FFDH_PQSQR contains the R^2 values modulo p
 *  - Virtual pointers FFDH_P point to the second PKC word of FFDH_PFULL
 *  - Qsquared in T1
 *
 * @return void
 *
 * @note Function uses an early-exit mechanism with following return codes:
 *       - #MCUXCLRANDOM_STATUS_FAULT_ATTACK in case one of internal operations failed
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClFfdh_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClFfdh_SetupEnvironment(
  mcuxClSession_Handle_t pSession,
  mcuxClFfdh_DomainParams_t* pDomainParams
);

/**
 * @brief This function loads and validates public key.
 *
 * @param[in] pSession        Handle for the current CL session
 * @param[in] publicKey       Public key handle (word-aligned)
 * @param[in] pCpuWorkarea    Pointer to initialized Ffdh CPU workarea (via mcuxClFfdh_SetupEnvironment).
 * @param[in] pExpTemp        Pointer to the temporary buffer can be in either CPU or PKC workarea:
 *                            - If it is in CPU workarea: It shall be CPU word aligned, and its length
 *                              shall be a multiple of CPU word and greater than operandLength
 *                            - If it is in PKC workarea: It shall be PKC word aligned, and its length shall be
 *                              MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(operandLength + 1U)
 *
 * Prerequisites:
 * - ps1Len = (operandSize, operandSize)
 * - Buffer FFDH_UPTRTINDEX_PFULL contains p'||p
 * - Buffer FFDH_UPTRTINDEX_T1 contains Qdash (this buffer will be overwritten)
 * - Buffers FFDH_UPTRTINDEX_T2, FFDH_UPTRTINDEX_T3, FFDH_UPTRTINDEX_T4, FFDH_UPTRTINDEX_T5
 *   are temporary buffers and will be overwritten
 *
 * Result:
 *  - Buffer FFDH_UPTRTINDEX_BASE contains public key in MR
 *  - Buffer FFDH_UPTRTINDEX_T1 gets overwritten
 *
 * @note Caution Function will extend operand sizes ps1Len = (expOperandSize, expOperandSize),
 *       where expOperandSize is extended operand size specific to MCUXCLMATH_SECMODEXP operation.
 *
 * @return void
 *
 * @note Function uses an early-exit mechanism with following return codes:
 *       - MCUXCLKEY_STATUS_INVALID_INPUT in case provided public key is invalid
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClFfdh_PublicKeyLoadAndValidate)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClFfdh_PublicKeyLoadAndValidate(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Handle_t publicKey,
  mcuxClFfdh_CpuWa_t* pCpuWorkarea,
  uint32_t* pExpTemp
);
  /**
 * @brief Declaration of function to cast pointer to specific workarea type
 */
  MCUX_CSSL_FP_FUNCTION_DEF(mcuxClFfdh_castToFfdhCpuWorkArea
  ) static inline mcuxClFfdh_CpuWa_t* mcuxClFfdh_castToFfdhCpuWorkArea(uint32_t* pWa)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClFfdh_CpuWa_t*)pWa;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLFFDH_INTERNAL_H */
