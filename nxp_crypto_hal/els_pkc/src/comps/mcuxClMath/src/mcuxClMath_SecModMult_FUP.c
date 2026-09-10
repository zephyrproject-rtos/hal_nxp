/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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
 * @file  mcuxClMath_SecModMult_FUP.c
 * @brief mcuxClMath: FUP programs of secure modular multiplication
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClMath_SecModMult_FUP.h>
#include <internal/mcuxClMath_Internal_SecModMult.h>
#include <internal/mcuxClPkc_FupMacros.h>

/**
 * [DESIGN]
 * Calculates secure modular multiplication in Montgomery representation: [R] = [X] * [Y] * Q-1 mod N.
 *
 * Prerequisites:
 *  - MCUXCLMATH_MODMULT_X contains the input of X
 *  - MCUXCLMATH_MODMULT_Y contains the input of Y
 *  - MCUXCLMATH_MODMULT_N contains the input of N
 *  - MCUXCLMATH_MODMULT_T1 contains PRNG with length of N
 *  - MCUXCLMATH_MODMULT_T2 buffer with length of N
 *  - For PS1 length, OPLEN = MCLEN = len(N) = len(X) = len(Y), which is a multiple of PKC word size
 *  - For the length of T1 & R, it is len(N) + 1 PKC word
 *
 * Result:
 *  - MCUXCLMATH_MODMULT_R contains result in Montgomery representation
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClMath_Fup_SecModMult[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xceu,0xaeu,0x2bu,0x35u},{0x80u,0x33u,0x04u,0x04u,0x02u,0x03u},{0x80u,0x00u,0x01u,0x03u,0x02u,0x04u},{0x80u,0x21u,0x02u,0x00u,0x03u,0x05u},{0x80u,0x00u,0x05u,0x01u,0x02u,0x03u},{0x80u,0x2au,0x02u,0x03u,0x02u,0x03u},{0x80u,0x2au,0x02u,0x03u,0x04u,0x03u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


