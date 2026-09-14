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
 * @file  mcuxClEcc_Internal_PointComparison_FUP.c
 * @brief FUP programs for EdDSA Signature Verification
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>

/**
 * FUP program to check if two projective points P1 = (X1:Y1:Z1) and P2 = (X2:Y2:Z2) with Z1,Z2 != 0 are equal.
 * The comparison is done by first bringing P1 and P2 to the same Z-coordinate Z1*Z2, i.e. 
 * 
 *   P1 = (X1':Y1':Z1') = (X1*Z2:Y1*Z2:Z1*Z2) and P2 = (X2':Y2':Z2') = (X2*Z1:Y2*Z1:Z2*Z1)
 *
 * and then computing ((X1'-X2') mod p) | ((Y1'-Y2') mod p) and checking if the ZERO flag is set or not in the
 * calling function.
 *
 * Prerequisites:
 *  - ECC_V0 contains the X-coordinate of point P1
 *  - ECC_V1 contains the Y-coordinate of point P1
 *  - ECC_V2 contains the Z-coordinate of point P1
 *  - ECC_COORD00 contains the X-coordinate of point P2
 *  - ECC_COORD01 contains the Y-coordinate of point P2
 *  - ECC_COORD02 contains the Z-coordinate of point P2
 *
 * Result:
 *  - The zero flag is set if and only if the two points are equal.
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_PointComparisonHom[12] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xdcu,0x89u,0xdeu,0x3fu},{0x80u,0x00u,0x04u,0x22u,0x00u,0x19u},{0x80u,0x00u,0x05u,0x22u,0x00u,0x1bu},{0x80u,0x00u,0x20u,0x06u,0x00u,0x1du},{0x80u,0x00u,0x21u,0x06u,0x00u,0x1fu},{0x80u,0x2au,0x10u,0x19u,0x1du,0x19u},{0x80u,0x33u,0x19u,0x19u,0x00u,0x1du},{0x80u,0x2au,0x00u,0x1du,0x00u,0x19u},{0x80u,0x2au,0x10u,0x1bu,0x1fu,0x1bu},{0x80u,0x33u,0x1bu,0x1bu,0x00u,0x1fu},{0x80u,0x2au,0x00u,0x1fu,0x00u,0x1bu},{0x00u,0x0eu,0x19u,0x19u,0x1bu,0x1bu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()

