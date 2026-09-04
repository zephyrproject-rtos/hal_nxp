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
 * @file  mcuxClEcc_EdDSA_Internal_CalcHashModN_FUP.c
 * @brief FUP programs for EdDSA Signature Verification
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_EdDSA_Internal_CalcHashModN_ModN[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xccu,0x51u,0x28u,0x13u},{0x00u,0x3eu,0x1bu,0x1bu,0x03u,0x1bu},{0x00u,0x1au,0x04u,0x04u,0x02u,0x04u},{0x80u,0x00u,0x1bu,0x17u,0x01u,0x1fu},{0xc0u,0x00u,0x1cu,0x1fu,0x01u,0x1bu},{0x80u,0x00u,0x1bu,0x17u,0x01u,0x1fu},{0x80u,0x2au,0x01u,0x1fu,0x01u,0x1cu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()




/**
 * FUP program to compute Hash mod N
 *
 * Prerequisites:
 *  - ECC_V0 points to the second PKC word of ECC_T1
 *  - ECC_S2 contains the hash h (of size (operandSize + bufferSize))
 *  - PS2 lengths set to (operandSize + bufferSize, operandSize)
 *
 * Result:
 *  - ECC_S2 contains Hash mod N in NR
 */
