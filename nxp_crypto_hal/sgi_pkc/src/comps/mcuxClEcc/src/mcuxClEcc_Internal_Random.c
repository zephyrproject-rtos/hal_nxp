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
 * @file  mcuxClEcc_Internal_Random.c
 * @brief mcuxClEcc: implementation of ECC function mcuxClEcc_GenerateRandomModModulus
 */


#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClRandom.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>

#include <internal/mcuxClSession_Internal_EntryExit.h>

/**
 * This function generates low quality random and the value is in range [1, modulus-1].
 *
 * Inputs:
 *   - pSession         Handle for the current CL session
 *   - iModulus         Index of PKC buffer which contains the modulus
 *   - iDst             Index of PKC buffer which the random mod modulus will be written to
 *
 * Prerequisites: N/A.
 *
 * Result in PKC workarea:
 *   buffer iDst which the random mod modulus will be written to.
 *
 * Other modifications:
 *   buffers T0, T1, T2, V0, V1 are modified (as temp);
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_GenerateRandomModModulus)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_GenerateRandomModModulus(
    mcuxClSession_Handle_t pSession,
    uint8_t iModulus,
    uint8_t iDst
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_GenerateRandomModModulus);

    /* Determine pointer table pointer */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint32_t operandSize = MCUXCLPKC_PS1_GETOPLEN();
    MCUXCLPKC_WAITFORFINISH();
    pOperands[ECC_V0] = (uint16_t) pOperands[iModulus];
    pOperands[ECC_V1] = (uint16_t) pOperands[iDst];

    MCUXCLBUFFER_INIT(buffRandom, NULL, MCUXCLPKC_OFFSET2PTR(pOperands[ECC_T0]), operandSize);
    MCUX_CSSL_FP_FUNCTION_CALL(ret_Prng_GetRandom, mcuxClRandom_ncGenerate(pSession, buffRandom, operandSize));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret_Prng_GetRandom);

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_ReduceRandomModModulus, mcuxClEcc_FUP_ReduceRandomModModulus_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_GenerateRandomModModulus,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncGenerate),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}
