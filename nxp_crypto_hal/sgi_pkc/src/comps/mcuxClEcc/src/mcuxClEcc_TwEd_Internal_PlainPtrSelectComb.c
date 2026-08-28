/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_PrecPointImportAndValidate.c
 * @brief Function to import, convert and validate the coordinates of a pre-computed point
 */

#include <mcuxClToolchain.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>


/**
 * For a given 4 bit scalar digit (i3 i2 i1 i0)_2, this function sets TWED_PP_VX0 to the buffer
 * storing the X-coordinate of PP = P_{(i3 i2 i1)_2 ^ (i0 i0 i0)_2 ^ (1 1 1)_2} and
 *  - if i0 = 1, copy X- and T-coordinates to buffers ECC_T1 and ECC_T2
 *  - if i0 = 0, computer the negative X- and T-coordinates of PP in buffers ECC_T1 and ECC_T2.
 * Finally, sets TWED_PP_VX0 and TWED_PP_VT0 to the buffers ECC_T1 and ECC_T2
 *
 * The function is not implemented to protect against side-channel attacks.
 *
 * Parameters:
 *  - pSession              Handle for the current CL session
 *  - scalarWord            CPU word containing the digit (i3 i2 i1 i0)_2
 *  - scalarDigitOffset     Bit offset in scalarWord of the digit (i3 i2 i1 i0)_2
 *
 * Prerequisites:
 *  - ps1Len = (operandSize, operandSize)
 *  - Buffer ECC_PFULL contains p'||p
 *  - Buffer ECC_PS contains the shifted modulus associated to p
 *
 * Result:
 *  - Virtual pointers TWED_PP_VX0, TWED_PP_VY0 and TWED_PP_VT0 as well as buffers ECC_T1 and ECC_T2 are prepared as described above.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_PlainPtrSelectComb)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainPtrSelectComb(
    mcuxClSession_Handle_t pSession UNUSED_PARAM,
    uint32_t scalarWord,
    uint8_t scalarDigitOffset
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_PlainPtrSelectComb);

    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();

    /* Step 1: Derive digit (i3 i2 i1 i0)_2 from scalarWord. */
    uint32_t nibble = (scalarWord >> scalarDigitOffset) & MCUXCLECC_TWED_FIXSCALARMULT_DIGITMASK;

    /* Step 2: Derive table index tiX of buffer storing the X-coordinate of PP = P_{(i3 i2 i1)_2 ^ (i0 i0 i0)_2 ^ (1 1 1)_2}. */
    uint32_t tiX = TWED_PP_X0 + 3u * ( ((nibble & 0xEu)>>1) ^ (7u * (nibble & 0x1u)) ^ (0x7u));

    /* Step 3: Set virtual pointers TWED_PP_VX0, TWED_PP_VY0 and TWED_PP_VT0 to the pointer table entries with indices tiX, tiX+1 and tiX+2. */
    MCUXCLPKC_WAITFORREADY();
    pOperands[TWED_PP_VX0] = (uint16_t) pOperands[tiX];
    pOperands[TWED_PP_VY0] = (uint16_t) pOperands[tiX + 1u];
    pOperands[TWED_PP_VT0] = (uint16_t) pOperands[tiX + 2u];

    /* Step 4: If i0 == 0:
     *   - Compute ECC_T1 = ECC_P - TWED_PP_VX0 and ECC_T2 = ECC_P - TWED_PP_VT0
     *         Else:
     *   - Copy TWED_PP_VX0 and TWED_PP_VT0 to ECC_T1 and ECC_T2
     */
    MCUX_CSSL_FP_BRANCH_DECL(nibbleBranch);
    if(0u == (nibble & 0x1u))
    {
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T1, ECC_P, TWED_PP_VX0);
        MCUXCLPKC_FP_CALC_OP1_SUB(ECC_T2, ECC_P, TWED_PP_VT0);

        MCUX_CSSL_FP_BRANCH_POSITIVE(nibbleBranch,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB,
            MCUXCLPKC_FP_CALLED_CALC_OP1_SUB);
    }
    else
    {
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_T1, TWED_PP_VX0, 0u);
        MCUXCLPKC_FP_CALC_OP1_OR_CONST(ECC_T2, TWED_PP_VT0, 0u);

        MCUX_CSSL_FP_BRANCH_NEGATIVE(nibbleBranch,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST,
            MCUXCLPKC_FP_CALLED_CALC_OP1_OR_CONST);

    }
    /* Set virtual pointers TWED_PP_VX0 and TWED_PP_VT0 to buffers ECC_T1 and ECC_T2. */
    MCUXCLPKC_WAITFORREADY();
    pOperands[TWED_PP_VX0] = (uint16_t)pOperands[ECC_T1];
    pOperands[TWED_PP_VT0] = (uint16_t)pOperands[ECC_T2];

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_PlainPtrSelectComb,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(nibbleBranch, 0u == (nibble & 0x1u)),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(nibbleBranch, 0u != (nibble & 0x1u)));
}
