/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024 NXP                                       */
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
 * @file  mcuxClEcc_Weier_Internal_ConvertPoint_FUP.c
 * @brief FUP program for Weierstrass curve internal point conversion
 */


#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_ConvertAffinePoint_ToJacobian[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x5bu,0xa9u,0x51u,0x00u},{0x80u,0x00u,0x20u,0x16u,0x00u,0x24u},{0x80u,0x00u,0x21u,0x16u,0x00u,0x25u},{0x00u,0x09u,0x00u,0x00u,0x00u,0x23u},{0x00u,0x09u,0x00u,0x00u,0x00u,0x22u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_ConvertAffinePointsToJac[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x10u,0x8cu,0x25u,0x66u},{0x80u,0x00u,0x26u,0x16u,0x00u,0x20u},{0x80u,0x00u,0x27u,0x16u,0x00u,0x21u},{0x00u,0x09u,0x00u,0x00u,0x00u,0x22u},{0x80u,0x00u,0x28u,0x16u,0x00u,0x24u},{0x80u,0x00u,0x29u,0x16u,0x00u,0x25u},{0x00u,0x09u,0x00u,0x00u,0x00u,0x23u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_ConvertJacToAffine[10] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x3au,0x69u,0xc7u,0x7cu},{0x80u,0x00u,0x19u,0x16u,0x00u,0x1bu},{0x80u,0x00u,0x1bu,0x16u,0x00u,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x19u,0x00u,0x1fu},{0x80u,0x00u,0x20u,0x1du,0x00u,0x19u},{0x80u,0x33u,0x19u,0x19u,0x00u,0x24u},{0x80u,0x2au,0x00u,0x24u,0x00u,0x24u},{0x80u,0x00u,0x21u,0x1fu,0x00u,0x19u},{0x80u,0x33u,0x19u,0x19u,0x00u,0x25u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_ConvertPoint_ToAffine[11] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xd3u,0xe0u,0x07u,0x9au},{0x80u,0x00u,0x19u,0x16u,0x00u,0x1bu},{0x80u,0x00u,0x1bu,0x16u,0x00u,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x19u,0x00u,0x1fu},{0x80u,0x00u,0x24u,0x1du,0x00u,0x19u},{0x80u,0x00u,0x25u,0x1fu,0x00u,0x1bu},{0x80u,0x33u,0x19u,0x19u,0x00u,0x20u},{0x80u,0x33u,0x1bu,0x1bu,0x00u,0x21u},{0x80u,0x2au,0x00u,0x20u,0x00u,0x20u},{0x80u,0x2au,0x00u,0x21u,0x00u,0x21u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_SecureConvertPoint_JacToAffine[18] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xcau,0xbbu,0x76u,0xceu},{0x80u,0x00u,0x19u,0x16u,0x00u,0x1bu},{0x80u,0x00u,0x1bu,0x16u,0x00u,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x19u,0x00u,0x1fu},{0x80u,0x21u,0x10u,0x1du,0x21u,0x1du},{0x80u,0x21u,0x10u,0x1fu,0x21u,0x1fu},{0x80u,0x00u,0x24u,0x21u,0x00u,0x19u},{0x80u,0x00u,0x24u,0x1du,0x00u,0x1bu},{0x80u,0x33u,0x1bu,0x1bu,0x00u,0x20u},{0x80u,0x2au,0x00u,0x20u,0x00u,0x20u},{0x80u,0x33u,0x19u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x20u,0x1bu,0x20u},{0x80u,0x00u,0x25u,0x21u,0x00u,0x19u},{0x80u,0x00u,0x25u,0x1fu,0x00u,0x1bu},{0x80u,0x33u,0x1bu,0x1bu,0x00u,0x21u},{0x80u,0x33u,0x19u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x21u,0x1bu,0x21u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/* FUP program: Securely convert point P from Jacobian in MR to affine coordinates  */
/*              in NR by blinding the final conversion additively.                  */
/* Input:                                                                           */
/*   P = (X,Y,Z) in (WEIER_X0,WEIER_Y0,-), Jacobian coordinates                     */
/*   ECC_T0 = z^(-1) * 256^(-LEN) \equiv z^(-1) * 256^(-2LEN) in MR                 */
/*   WEIER_YA = rnd (random data) in MR                                             */
/* Output:                                                                          */
/*   P = (x,y)     in (WEIER_XA,WEIER_YA), affine coordinates                       */

/* FUP program: convert points P1 and P2 from affine coordinates        */
/* to Jacobian coordinates in MR                                        */
/* Input: P1 = (x,y) in NR in (WEIER_X1,WEIER_Y1)                       */
/*        P2 = (x,y) in NR in (WEIER_X2,WEIER_Y2)                       */
/* Output: P1 = (X,Y,Z) in MR in (WEIER_XA,WEIER_YA,WEIER_ZA)           */
/*         P2 = (X,Y,Z) in MR in (WEIER_X0,WEIER_Y0,WEIER_Z)            */

/* FUP program: convert point P from affine coordinates         */
/* to Jacobian coordinates in MR                                */
/* Input: P = (x,y) in NR in (XA,YA)                            */
/* Output: P = (X,Y,Z) in MR in (WEIER_X0, WEIER_Y0, WEIER_Z)   */

/* FUP program: convert point P from Jacobian in MR to affine coordinates in NR     */
/* Input:                                                                           */
/*   P = (X,Y,Z) in (WEIER_XA,WEIER_YA,-), Jacobian coordinates                     */
/*   ECC_T0 = (z*z')^(-1) * 256^(-LEN), with z is Z coordinate in P relative to z'  */
/* Output:                                                                          */
/*   P = (x,y)     in (WEIER_X0,WEIER_Y0), affine coordinates                       */
