/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_RemoveBlinding_FUP.h>

MCUXCLPKC_FUP_EXT_ROM(mcuxClRsa_RemoveBlinding_FUP,
    FUP_CRC_PLACEHOLDER,
    /* Set T2 = 0 */
    FUP_OP1_CONST(MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T2, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_ZERO),
    /* Compute T1 = T2 + B */
    FUP_OP1_ADD_Z0(MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T1, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T2, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_B),
    /* Compute T2 = T1 * X mod Nb (X in Montgomery representation, T2 and T1 in normal representation) */
    FUP_MC1_MM(MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T2, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T1, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_X, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_NB),
    /* Normalize the result T1 = (T2 – Nb) mod Nb */
    FUP_MC1_MS(MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T1, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T2, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_NB, MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_NB)
);
