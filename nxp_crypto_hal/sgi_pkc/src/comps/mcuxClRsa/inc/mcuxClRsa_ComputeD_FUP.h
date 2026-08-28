/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024 NXP                                            */
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

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClRsa_ComputeD_FUP.h>

MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_ComputeD_Steps12_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Compute p-1 */
    FUP_OP1_SUB_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_P,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_CONSTANT),
    /* Compute (p-1)*b */
    FUP_MC2_PM_PATCH(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1_B, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_RND),
    /* Compute q-1 */
    FUP_OP1_SUB_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_Q,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_CONSTANT),
    /* Compute (q-1)*b */
    FUP_MC2_PM_PATCH(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1_B, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_RND),
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_ComputeD_Steps3_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Compute phi_b = ((p-1)*b)*((q-1)*b) */
    FUP_MC2_PM(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PHI_B, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1_B, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1_B),
    /* Compute gcd_b = gcd((p-1)*b,(q-1)*b) in QSUB1_B */
    FUP_MC2_GCD(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1_B, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1_B),
    /* for both operand are congruent 2 mod 4, the result should be left shift by 1 bit */
    FUP_OP2_SHL(MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1_B, MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_CONSTANT)
);
