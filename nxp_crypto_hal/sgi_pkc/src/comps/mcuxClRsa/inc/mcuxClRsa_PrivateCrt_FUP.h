/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023, 2026 NXP                                           */
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
#include <internal/mcuxClRsa_PrivateCrt_FUP.h>

MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_PrivateCrt_T1mb_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Calculate Mq_bm = Mq_b * QDash mod p_b */
    FUP_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0 /* Mq_bm */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET4 /* QDash */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET3 /* Mq_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */),
    /* Calculate T1_mb = Mp_bm - Mq_bm mod p_b */
    FUP_MC2_MS(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET5 /* T1_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_R /* Mp_bm */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0 /* Mq_bm */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */)
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_PrivateCrt_T2T3T4mb_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Calculate T2_mb = QDash*qInv_b mod p_b */
    FUP_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0 /* T2_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET4 /* QDash */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET2 /* qInv_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */),
    /* Calculate T3_mb = QDash*R_qInv mod p_b */
    FUP_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET2 /* T3_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET4 /* QDash */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET1 /* R_qInv */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */),
    /* Calculate qInv_bm = T2_mb-T3_mb mod p_b */
    FUP_MC2_MS(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET1 /* qInv_bm */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0 /* T2_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET2 /* T3_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */),
    /* Calculate T4_mb = T1_mb*qInv_bm mod p_b */
    FUP_MC2_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0 /* T4_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET5 /* T1_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET1 /* qInv_bm */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */),
    /* Convert back into normal representation: T4_b = T4_mb mod p_b */
    FUP_MC2_MR(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET1 /* T4_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0  /* T4_mb */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B /* p_b */)
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_PrivateCrt_CalcM_b_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Calculate T5_b = T4_b*q in MODT4 which has a size of
     * (primeAlignLen + blindedPrimeAlignLen = blindedMessageAlignLen)
     */
    FUP_MC1_PM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT4 /* T5_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0 /* q */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET1 /* T4_b */),
    /* For the following addition, move Mq_b to the bigger buffer N,
     * which is used as a temporary buffer
     */
    FUP_OP2_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_CONST0),
    FUP_OP1_OR_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N /* Mq_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET3  /* Mq_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_CONST0),
    /* Calculate masked message M_b = T5_b + Mq_b */
    FUP_OP2_ADD(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT3 /* M_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT4 /* T5_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N /* Mq_b */)
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_PrivateCrt_CalcM1_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Calculate reduction M_br of M_b mod N */
    FUP_MC2_MR(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT4 /* M_br */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT3 /* M_b */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N /* N */),
    /* Calculate message M1 = M_br * QDash mod N  */
    FUP_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT3 /* M1 */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT1 /* QDash */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT4 /* M_br */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N /* N */),
    /* Normalize result (case if M1 > N) */
    FUP_MC1_MS(MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_M /* M */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT3 /* M1 */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N /* N */,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N /* N */)
);
