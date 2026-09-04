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
#include <internal/mcuxClRsa_Util_KeyGeneration_Crt_FUP.h>

MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP,
    FUP_CRC_PLACEHOLDER,
    FUP_OP1_SUB_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT1),
    FUP_MC2_PM_PATCH(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND),
    FUP_OP1_OR_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_E,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT0)
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP,
    FUP_CRC_PLACEHOLDER,
    FUP_OP1_SUB_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT1),
    FUP_MC2_PM_PATCH(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND),
    FUP_OP1_OR_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_E,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT0)
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP,
    FUP_CRC_PLACEHOLDER,
    FUP_MC2_PM_PATCH(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND),
    FUP_MC2_PM_PATCH(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND)
);
MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP,
    FUP_CRC_PLACEHOLDER,
    FUP_MC2_PM(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q_B),
    FUP_OP1_MUL(MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND_SQUARE,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND,
        MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND)
);
