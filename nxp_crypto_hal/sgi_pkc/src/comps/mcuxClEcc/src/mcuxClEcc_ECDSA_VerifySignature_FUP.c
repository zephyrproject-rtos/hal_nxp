/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023 NXP                                            */
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
 * @file  mcuxClEcc_ECDSA_VerifySignature_FUP.c
 * @brief FUP programs for Weierstrass curve ECDSA signature verification
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_Verify_Convert_G_PrecG_toMR[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x34u,0x74u,0xadu,0xfbu},{0x80u,0x00u,0x26u,0x16u,0x00u,0x20u},{0x80u,0x00u,0x27u,0x16u,0x00u,0x21u},{0x80u,0x00u,0x28u,0x16u,0x00u,0x2au},{0x80u,0x00u,0x29u,0x16u,0x00u,0x2bu}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_Fup_Verify_Convert_P1plusP2_toAffineNR_CalcR[10] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x8fu,0x95u,0xdbu,0xd7u},{0x80u,0x00u,0x1bu,0x16u,0x00u,0x19u},{0x80u,0x00u,0x19u,0x16u,0x00u,0x1bu},{0x80u,0x00u,0x1bu,0x1bu,0x00u,0x1du},{0x80u,0x00u,0x1du,0x19u,0x00u,0x1fu},{0x80u,0x00u,0x28u,0x1du,0x00u,0x26u},{0x80u,0x33u,0x26u,0x26u,0x00u,0x24u},{0x80u,0x2au,0x00u,0x24u,0x00u,0x24u},{0x80u,0x00u,0x29u,0x1fu,0x00u,0x25u},{0x80u,0x2au,0x01u,0x24u,0x01u,0x26u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_Fup_Verify_Convert_pubkeyQ_toJacobianMR[6] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x1fu,0x94u,0xd1u,0xbdu},{0x80u,0x00u,0x23u,0x16u,0x00u,0x1fu},{0x80u,0x00u,0x1fu,0x23u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x23u,0x00u,0x1fu},{0x80u,0x00u,0x26u,0x1du,0x00u,0x24u},{0x80u,0x00u,0x27u,0x1fu,0x00u,0x25u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_Fup_Verify_InitZ_CalcU1U2[6] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x6bu,0x39u,0x6cu,0xf6u},{0x00u,0x09u,0x00u,0x00u,0x00u,0x23u},{0x80u,0x00u,0x1cu,0x1bu,0x01u,0x18u},{0x80u,0x00u,0x1eu,0x1bu,0x01u,0x1au},{0x80u,0x2au,0x01u,0x1au,0x01u,0x1au},{0x80u,0x2au,0x01u,0x18u,0x01u,0x18u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_Fup_Verify_Update_G_to_Prec1[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x6bu,0x50u,0xcau,0x35u},{0x80u,0x00u,0x23u,0x23u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x23u,0x00u,0x1fu},{0x80u,0x00u,0x20u,0x1du,0x00u,0x26u},{0x80u,0x00u,0x21u,0x1fu,0x00u,0x27u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_Fup_Verify_Update_pubkeyQ_P1_z[9] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x8du,0x0eu,0xf5u,0x8cu},{0x80u,0x00u,0x22u,0x22u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x22u,0x00u,0x1fu},{0x80u,0x00u,0x24u,0x1du,0x00u,0x26u},{0x80u,0x00u,0x25u,0x1fu,0x00u,0x27u},{0x80u,0x00u,0x20u,0x1du,0x00u,0x24u},{0x80u,0x00u,0x21u,0x1fu,0x00u,0x25u},{0x00u,0x1eu,0x23u,0x23u,0x03u,0x19u},{0x80u,0x00u,0x19u,0x22u,0x00u,0x23u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/* FUP program: calculates the scalars u1 and u2:
 *   u1 = hash * s^(-1), in range [0, n-1];
 *   u2 = r    * s^(-1), in range [0, n-1].
 */

/* FUP program: converts x- and y-coordinates of G and PrecG from NR to MR */

/* FUP program: update G: (XA,YA, 1) -> Prec1: (X1,Y1, Z) Jacobian.*/

/* FUP program: convert Q: (X1,Y1) affine NR -> (X0,Y0, Z) Jacobian. */

/* FUP program: update Q:  (X0,Y0, old Z) -> (X1,Y1, new Z) Jacobian; */
/*                     P1: (XA,YA, old Z) -> (X0,Y0, new Z) Jacobian; */
/*              update z = z * z'.                                    */

/* FUP program: convert P1 + P2 (or P2 if u1 == 0) to affine NR; */
/*              calculate r = x mod n.                           */
