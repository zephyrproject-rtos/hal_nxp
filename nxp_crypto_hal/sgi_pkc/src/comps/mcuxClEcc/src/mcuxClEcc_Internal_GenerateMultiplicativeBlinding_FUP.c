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
 * @file  mcuxClEcc_FUP_GenerateMultiplicativeBlinding_FUP.c
 * @brief mcuxClEcc: FUP program for internal GenerateMultiplicativeBlinding function
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_GenerateMultiplicativeBlinding[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x67u,0x1cu,0xa8u,0x8du},{0x00u,0x1eu,0x1fu,0x1fu,0x03u,0x04u},{0xc0u,0x00u,0x1au,0x19u,0x01u,0x1fu},{0x80u,0x00u,0x1fu,0x17u,0x01u,0x1bu},{0x80u,0x33u,0x1bu,0x1bu,0x01u,0x19u},{0x80u,0x2au,0x01u,0x19u,0x01u,0x19u},{0x80u,0x2au,0x01u,0x19u,0x04u,0x1au}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/**
 * Prerequisites:
 * T3 = phi^-1 * rnd (opLen)
 * T0 = phi^(-1)*2^(8*(scalarPkcAlignedSize + MCUXCLPKC_WORDSIZE) (operandSize)
 * S1 = s + rnd (scalarPkcAlignedSize + MCUXCLPKC_WORDSIZE bytes)
 * ps1Len = (operandSize, operandSize).
 * ps2Len = (scalarPkcAlignedSize + MCUXCLPKC_WORDSIZE, operandSize).
 *
 * Results:
 * the blinded scalar sigma is contained in buffer ECC_S1 (operandSize).
 */
