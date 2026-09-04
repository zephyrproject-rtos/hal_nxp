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

/**
 * @file  mcuxClEcc_Mont_Internal_SecureScalarMult_XZMontLadder_FUP.c
 * @brief mcuxClEcc: FUP programs for implementation of ECC internal secure scalar multiplication function montgomery ladder based
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Mont_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Mont_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Mont_SecureScalarMult_UpdateAccCoords[9] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x22u,0xefu,0xc3u,0x1au},{0x80u,0x00u,0x19u,0x20u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x20u},{0x80u,0x00u,0x19u,0x21u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x21u},{0x80u,0x00u,0x19u,0x22u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x22u},{0x80u,0x00u,0x19u,0x23u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x23u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_SecureScalarMult_XZMontLadder_LadderStep[22] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xcau,0x18u,0x98u,0x4bu},{0x80u,0x21u,0x10u,0x0cu,0x0du,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x1du},{0x80u,0x2au,0x10u,0x0cu,0x0du,0x1bu},{0x80u,0x00u,0x1bu,0x1bu,0x00u,0x1fu},{0x80u,0x00u,0x1du,0x1fu,0x00u,0x0cu},{0x80u,0x2au,0x10u,0x1du,0x1fu,0x1du},{0x80u,0x00u,0x12u,0x1du,0x00u,0x0du},{0x80u,0x21u,0x10u,0x1fu,0x0du,0x1fu},{0x80u,0x00u,0x1du,0x1fu,0x00u,0x0du},{0x80u,0x21u,0x10u,0x0eu,0x0fu,0x1du},{0x80u,0x00u,0x1du,0x1bu,0x00u,0x1fu},{0x80u,0x2au,0x10u,0x0eu,0x0fu,0x1bu},{0x80u,0x00u,0x1bu,0x19u,0x00u,0x1du},{0x80u,0x2au,0x10u,0x1du,0x1fu,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x1bu},{0x80u,0x00u,0x24u,0x1bu,0x00u,0x0fu},{0x80u,0x21u,0x10u,0x1du,0x1fu,0x19u},{0x80u,0x00u,0x19u,0x19u,0x00u,0x0eu},{0x10u,0x00u,0x10u,0xe4u,0x5bu,0x48u},{0x00u,0x1eu,0x0eu,0x0eu,0x03u,0x1bu},{0x80u,0x00u,0x25u,0x1bu,0x00u,0x0eu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/* FUP program:
 *   - Update P1(x1,z1) and P2(x2,z2) in MR
 *
 * Input:
 *   P1 = (x1,z1) in MR with x1, z1 < p
 *   P2 = (x2,z2) in MR with x2, z2 < p
 * Output:
 *   Updated P1 = (x1',z1') in MR with x1', z1' < p
 *   Updated P2 = (x2',z2') in MR with x2', z2' < p
 *
 */

