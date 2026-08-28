/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_PlainPtrSelectML.c
 * @brief Function to set the virtual pointers of coordinates of accumulated ladder points
 *  to be used by the upcoming Montgomery Ladder step depending on the current scalar bit b
 */

#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <internal/mcuxClPkc_Macros.h>

#include <mcuxClEcc.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>

/**
 * Plain pointer selection function
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_TwEd_PlainPtrSelectML)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_TwEd_PlainPtrSelectML(
    mcuxClSession_Handle_t pSession,
    uint32_t scalarWord,
    uint8_t scalarBitOffset
)
{
    (void)pSession;

    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_TwEd_PlainPtrSelectML);

    /* Select bit b */
    uint32_t b = (scalarWord >> scalarBitOffset) & 0x01u;

    /* Select the pointers for the accumulated Montgomery ladder points.
     * As TWED_ML_Y1, ... TWED_ML_Z2 are four consecutive offsets in the UPTR table, the selection of
     * (TWED_ML_Y1, TWED_ML_Z1) or (TWED_ML_Y2, TWED_ML_Z2) can be done based on the value of the bit b,
     * to achieve the following:
     *     if (1u == b)
     *     {
     *         pOperands[TWED_VY1] = pOperands[TWED_ML_Y2];
     *         pOperands[TWED_VZ1] = pOperands[TWED_ML_Z2];
     *         pOperands[TWED_VY2] = pOperands[TWED_ML_Y1];
     *         pOperands[TWED_VZ2] = pOperands[TWED_ML_Z1];
     *     }
     *     else
     *     {
     *         pOperands[TWED_VY1] = pOperands[TWED_ML_Y1];
     *         pOperands[TWED_VZ1] = pOperands[TWED_ML_Z1];
     *         pOperands[TWED_VY2] = pOperands[TWED_ML_Y2];
     *         pOperands[TWED_VZ2] = pOperands[TWED_ML_Z2];
     *     };
     */
    uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("32-bit aligned UPTRT table is assigned in CPU workarea")
    uint32_t *pOperands32 = (uint32_t *) pOperands;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    uint32_t offsets_VY1_VZ1 = pOperands32[(TWED_ML_Y1 / 2u) + b];
    uint32_t offsets_VY2_VZ2 = pOperands32[(TWED_ML_Y2 / 2u) - b];

    /* Write offsets_VY1_VZ1 and offsets_VY2_VZ2 to pOperands[TWED_VY1] || pOperands[TWED_VZ1] and pOperands[TWED_VY2] || pOperands[TWED_VZ2] */
    MCUXCLPKC_WAITFORREADY();
    MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, TWED_VY1, offsets_VY1_VZ1);
    MCUXCLECC_STORE_PKCOFFSETPAIR_ALIGNED(pOperands32, TWED_VY2, offsets_VY2_VZ2);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_TwEd_PlainPtrSelectML);
}
