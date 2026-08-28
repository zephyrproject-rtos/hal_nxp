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
 * @file  mcuxClEcc_EdDSA_GenerateKeyPair_FUP.c
 * @brief FUP programs for EdDSA Signature Generation
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_EdDSA_GenerateSignature_Compute_S[13] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x0du,0x1fu,0xd8u,0xcfu},{0xc0u,0x00u,0x1au,0x18u,0x01u,0x19u},{0xc0u,0x00u,0x1fu,0x1cu,0x01u,0x1au},{0x80u,0x21u,0x11u,0x1au,0x19u,0x1au},{0x80u,0x21u,0x11u,0x18u,0x1cu,0x19u},{0xc0u,0x00u,0x1du,0x19u,0x01u,0x18u},{0x80u,0x2au,0x11u,0x1au,0x18u,0x18u},{0x00u,0x3eu,0x19u,0x19u,0x03u,0x19u},{0x00u,0x1au,0x04u,0x04u,0x02u,0x04u},{0x80u,0x00u,0x18u,0x17u,0x01u,0x1au},{0x80u,0x00u,0x1au,0x17u,0x01u,0x18u},{0x80u,0x00u,0x18u,0x19u,0x01u,0x1au},{0x80u,0x2au,0x01u,0x1au,0x01u,0x19u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/**
 * FUP program to securely compute the EdDSA signature value S
 *
 * Prerequisites:
 *  - ECC_T3 contains the blinding s + rnd of the secret scalar s (considered as of size 2*operandSize)
 *  - ECC_T2 contains the blinding rnd (considered as of size 2*operandSize) with MSByte set to 0
 *  - ECC_S2 contains e := H(prefix || R^{enc} || Q^{enc} || m') mod n
 *  - ECC_S0 contains phi
 *  - ECC_S1 contains the secret scalar sigma + rnd
 *  - PS2 lengths set to (bufferSize, operandSize)
 *  - ECC_V0 points to ECC_T0 with offset pkcWordSize bytes.
 *
 * Result:
 *  - ECC_T0 contains S in NR
 */
