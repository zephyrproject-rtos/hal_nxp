/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023, 2025 NXP                                            */
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
 * @file  mcuxClEcc_Weier_DecodePoint_FUP.c
 * @brief mcuxClEcc: FUP programs used in ECC functions for NIST curves
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_DecodePoint_SEC_CalcAlpha[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xc4u,0xc9u,0x8eu,0x11u},{0x80u,0x00u,0x13u,0x16u,0x00u,0x1bu},{0x80u,0x00u,0x20u,0x16u,0x00u,0x18u},{0x80u,0x00u,0x18u,0x18u,0x00u,0x19u},{0x80u,0x21u,0x10u,0x19u,0x12u,0x19u},{0x80u,0x00u,0x18u,0x19u,0x00u,0x1au},{0x80u,0x21u,0x10u,0x1au,0x1bu,0x1au}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_DecodePoint_SEC_VerifyBeta[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xacu,0x00u,0x33u,0x98u},{0x80u,0x33u,0x1cu,0x1cu,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x21u},{0x80u,0x00u,0x1cu,0x1cu,0x00u,0x1bu},{0x80u,0x2au,0x10u,0x1bu,0x1au,0x1bu},{0x80u,0x33u,0x1bu,0x1bu,0x00u,0x19u},{0x80u,0x2au,0x00u,0x19u,0x00u,0x19u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/* FUP program: Calculate alpha for point decoding.                     */
/*  Calculate alpha = x^3 + ax + b  in MR, will be stored in ECC_S1.    */
/*  Input: x in WEIER_XA, constant 2 in WEIER_VX0.                      */

/* FUP program: Prepare to verify the correctness of beta, i.e. verify beta^2 == alpha.  */
/*  Calculate beta in NR mod p, will be stored in WEIER_YA.                              */
/*  Calculate beta^2-alpha                                                               */
/*  Input: beta in MR in ECC_S2, alpha in MR in ECC_S1.                                  */
