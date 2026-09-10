/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023 NXP                                                 */
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
 * @file  mcuxClEcc_Mont_Internal_MontDhX_FUP.c
 * @brief FUP programs for MontDhX functions
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Mont_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Mont_Internal_FUP.h>


/* The algorithm implemented by this FUP program to decode an encoded Curve25519 or Curve448 private key
 * only works if:
 *    c < 8*pkcWordSize
 *    0 < 8*operandSize - t + c < 8*pkcWordSize-1
 *
 *  For the use cases Curve25519 and Curve448 these conditions are met. */
MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_MontDhDecodeScalar[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x72u,0xa5u,0xf5u,0xefu},{0x00u,0x15u,0x1cu,0x1cu,0x04u,0x1eu},{0x00u,0x14u,0x1eu,0x1eu,0x05u,0x1eu},{0x00u,0x1au,0x1eu,0x1eu,0x02u,0x1eu},{0x00u,0x17u,0x1eu,0x1eu,0x06u,0x1eu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_MontDhX_CalcAffineX[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x94u,0x31u,0x49u,0x04u},{0x80u,0x00u,0x1bu,0x16u,0x00u,0x19u},{0x80u,0x00u,0x20u,0x19u,0x00u,0x1bu},{0x80u,0x33u,0x1bu,0x1bu,0x00u,0x20u},{0x80u,0x2au,0x00u,0x20u,0x00u,0x20u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()

