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
 * @file  mcuxClEcc_Weier_BooleanToArithmeticMasking.c
 * @brief Function for converting boolean mask to arithmetic mask
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClPrng_Internal_Functions.h>

 /**
 * Function for converting from boolean to arithmetic masking.
 *
 * PS2 Oplen need to be set at least to length of the expected arithmetic masking
 * Masked value will be updated with new value.
 * Input and temporary buffers are considered double-sized thererfore buffers ECC_Sx are used instead of ECC_Tx
 *
 * Inputs in PKC workarea:
 *   S2 - Boolean Masked value
 *   S3 - Mask
 *
 * Results in PKC workarea:
 *   S2 - Arithmetic masked value
 * Other modifications:
 *   buffers S0 and S1 (as temp) are modified
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_Weier_BooleanToArithmeticMasking)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Weier_BooleanToArithmeticMasking(void)

{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_Weier_BooleanToArithmeticMasking);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint32_t operandSize = MCUXCLPKC_PS2_GETOPLEN();


    uint8_t * const ptrRnd = MCUXCLPKC_OFFSET2PTR(pOperands[ECC_S1]);
    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPrng_generate_Internal(ptrRnd, operandSize));

    MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking,
                        mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking_LEN);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_Weier_BooleanToArithmeticMasking,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_Internal),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
}
