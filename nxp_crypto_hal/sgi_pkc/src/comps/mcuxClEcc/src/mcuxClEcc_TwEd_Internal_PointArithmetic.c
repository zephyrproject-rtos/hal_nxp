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
 * @file  mcuxClEcc_TwEd_Internal_PointArithmetic.c
 * @brief Edwards curve internal point arithmetic
 */


#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>


MCUX_CSSL_ANALYSIS_START_SUPPRESS_NESTED_COMMENTS("Links are allowed in comments.")
/**
 * This function implements a repeated doubling operation of a twisted Edwards curve point in projective coordinates
 * P = (X:Y:Z) using the formulas provided in Section 6 of https://eprint.iacr.org/2008/013.pdf.
 *
 * Input:
 *  - noOfDoubles   Number of double operations to be performed
 *
 * Prerequisites:
 *  - Buffers TWED_X, TWED_Y and TWED_Z contain the homogeneous coordinates (X:Y:Z) of P in MR
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - The resulting coordinates are stored in buffers TWED_X, TWED_Y and TWED_Z in MR.
 *
 * @attention The PKC calculation might be still on-going, call #MCUXCLPKC_WAITFORFINISH before CPU accesses to the result.
 */
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NESTED_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_RepeatedDoubling)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_RepeatedDoubling(uint16_t noOfDoubles)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_RepeatedDoubling);

    MCUX_CSSL_FP_LOOP_DECL(whileLoop);
    for(uint32_t i = 0u; i < noOfDoubles; i++)
    {
        MCUXCLPKC_FP_CALCFUP(mcuxClEcc_FUP_TwEd_PointDouble, mcuxClEcc_FUP_TwEd_PointDouble_LEN);
        MCUX_CSSL_FP_LOOP_ITERATION(whileLoop, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_CalcFup));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_RepeatedDoubling,
         MCUX_CSSL_FP_LOOP_ITERATIONS(whileLoop, noOfDoubles));
}
