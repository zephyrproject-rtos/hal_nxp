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
 * @file  mcuxClMath_SecModMult.c
 * @brief mcuxClMath: secure modular multiplication
 */


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslAnalysis.h>

#include <mcuxClBuffer.h>
#include <mcuxClRandom.h>
#include <mcuxClSession.h>
#include <mcuxClMath_Functions.h>

#include <internal/mcuxClPkc_Macros.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClMath_Internal_SecModMult.h>
#include <internal/mcuxClMath_SecModMult_FUP.h>
#include <internal/mcuxClMath_Internal_Functions.h>
#include <internal/mcuxClRandom_Internal_Functions.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClSession_Internal.h>


/**
 * [DESIGN]
 * Internal secure modular multiplication function.
 *
 * CAUTION: length of N should be a multiple of PKC word size.
 *
 * Data Integrity: Expunge(iR_iN_iY_iX)
 *
 * @param[in] pSession  handle for the current CL session.
 * @param[out,in,in,in] iR_iN_iY_iX  indices of PKC operands
 * @param[temp,temp] iT2_iT1  indices of temporary buffers for PKC operation
 * @param[in] length  length of N in bytes
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval #MCUXCLMATH_STATUS_OK     function executed successfully
 * @retval #MCUXCLMATH_STATUS_ERROR  error occurred during operation
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMath_SecModMult)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMath_Status_t) mcuxClMath_SecModMult(
    mcuxClSession_Handle_t pSession,
    uint32_t iR_iN_iY_iX,
    uint16_t iT2_iT1,
    uint16_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMath_SecModMult);

    /* Create local UPTR table. */
    /* Setup CPU workarea for local UPTRT. */
    const uint32_t byteLenOperandsTable = (sizeof(uint16_t)) * (uint32_t) MCUXCLMATH_MODMULT_NO_OF_BUFFERS;
    const uint32_t alignedByteLenCpuWa = MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(byteLenOperandsTable);
    const uint32_t wordNumCpuWa = alignedByteLenCpuWa / (sizeof(uint32_t));
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pCpuWorkarea are 16-bit aligned as Operands Table ")
    uint16_t *pCpuWorkarea = (uint16_t *) mcuxClSession_allocateWords_cpuWa(pSession, wordNumCpuWa);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    if (NULL == pCpuWorkarea)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMult, MCUXCLMATH_STATUS_ERROR);
    }
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_REINTERPRET_MEMORY("Create 16-bit UPTR table at CPU word (32-bit) aligned address.")
    uint16_t *pOperands = pCpuWorkarea;
    const uint16_t *backupPtrUptrt;
    /* Mapping to internal indices:                         R   N  Y  X            T2   T1 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMath_InitLocalUptrt(iR_iN_iY_iX, (uint32_t)iT2_iT1,
                                                            pOperands, MCUXCLMATH_MODMULT_UPTRT_SIZE, &backupPtrUptrt));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_REINTERPRET_MEMORY()
    /* PS1 length backup & set */
    const uint32_t ps1Len = (uint32_t) MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_WAITFORREADY();
    MCUXCLPKC_PS1_SETLENGTH(length, length);

    /* Generate random T1, size = len(N) */
    const uint16_t offsetT1 = pOperands[MCUXCLMATH_MODMULT_T1];
    uint8_t *pT1 = MCUXCLPKC_OFFSET2PTR(offsetT1);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_Random_ncGenerate1, mcuxClRandom_ncGenerate(pSession, pT1, length));
    if (MCUXCLRANDOM_STATUS_OK != ret_Random_ncGenerate1)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMult, MCUXCLMATH_STATUS_ERROR,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate));
    }

    /* Calculate secure modular multiplication. */

    MCUXCLPKC_FP_CALCFUP(mcuxClMath_Fup_SecModMult,
                        mcuxClMath_Fup_SecModMult_LEN);
    MCUXCLPKC_WAITFORFINISH();
    /* Restore UPTRT & PS1 length. */
    MCUXCLPKC_SETUPTRT(backupPtrUptrt);
    MCUXCLPKC_PS1_SETLENGTH_REG(ps1Len);

    /* Release CPU WA */
    mcuxClSession_freeWords_cpuWa(pSession, wordNumCpuWa);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMath_SecModMult, MCUXCLMATH_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_InitLocalUptrt),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}
