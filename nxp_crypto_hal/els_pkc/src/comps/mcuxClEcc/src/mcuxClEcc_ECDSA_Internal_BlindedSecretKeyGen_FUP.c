/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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
 * @file  mcuxClEcc_ECDSA_Internal_BlindedSecretKeyGen_FUP.c
 * @brief FUP programs for ECDSA related functionality
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_ECDSA_Internal_FUP.h>

#ifdef MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
/* FUP program to check in a blinded way if ephemeral key k is smaller than base point order n
 *
 * Prerequisites:
 *  - ECC_S2 = ephemeral key k (considered as of size bufferSize)
 *  - ECC_T2 = random blinding of size bufferSize-1
 *  - ECC_N  = base point order n
 *
 * Result:
 *  - The PKC CARRY flag is set after the FUP program, iff k is smaller than n. */
MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_CheckNSmallerK[6] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x84u,0xb3u,0x28u,0x9fu},{0x40u,0x0au,0x1cu,0x1cu,0x1du,0x1bu},{0x40u,0x3eu,0x19u,0x19u,0x03u,0x19u},{0x00u,0x1eu,0x01u,0x01u,0x03u,0x19u},{0x40u,0x0au,0x19u,0x19u,0x1du,0x1fu},{0x40u,0x4bu,0x1bu,0x1bu,0x1fu,0x1bu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/* FUP program to blind the ephemeral key k multiplicatively with a 64-bit random blinding k0 (with MSBit set to 1)
 * and check in blinded form if k is zero
 *
 * Prerequisites:
 *  - ECC_S2 = ephemeral key k
 *  - ECC_T0 = k0^(-1) mod n
 *  - ECC_T2 = rnd (operandSize)
 *  - ECC_N  = base point order n
 *  - ECC_NQSQR = Montgomery factor R^2 associated to n
 *
 * Result:
 *  - Buffer ECC_S1 contains k1 = k0^(-1) * k mod n
 *  - The PKC ZERO flag is set after the FUP program, iff k equals 0. */
MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_ECDSA_BlindedEphemeralKeyGen_Deterministic_BlindK_CheckZeroK[10] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xd4u,0xb7u,0x3fu,0x4bu},{0x80u,0x00u,0x19u,0x17u,0x01u,0x1bu},{0x80u,0x00u,0x1bu,0x17u,0x01u,0x19u},{0x80u,0x21u,0x01u,0x1cu,0x1du,0x1cu},{0x80u,0x00u,0x19u,0x1cu,0x01u,0x1au},{0x80u,0x00u,0x19u,0x1du,0x01u,0x1bu},{0x80u,0x33u,0x1au,0x1au,0x01u,0x1cu},{0x80u,0x33u,0x1bu,0x1bu,0x01u,0x1du},{0x80u,0x2au,0x01u,0x1cu,0x01u,0x1bu},{0x80u,0x2au,0x01u,0x1bu,0x1du,0x1au}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()

MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
#endif /* MCUXCL_FEATURE_ECC_ECDSA_DETERMINISTIC */
