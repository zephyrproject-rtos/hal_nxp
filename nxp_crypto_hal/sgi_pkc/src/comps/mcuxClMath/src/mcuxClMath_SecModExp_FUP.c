/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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
 * @file  mcuxClMath_SecModExp_FUP.c
 * @brief mcuxClMath: FUP programs of secure modular exponentiation
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClMath_SecModExp_FUP.h>
#include <internal/mcuxClMath_Internal_SecModExp.h>
#include <internal/mcuxClPkc_FupMacros.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_CalcQAndInterleave[6] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x18u,0xdbu,0x13u,0x5fu},{0x40u,0x0bu,0x04u,0x04u,0x05u,0x11u},{0x00u,0x04u,0x0bu,0x0bu,0x0bu,0x0du},{0x00u,0x14u,0x0du,0x0du,0x10u,0x06u},{0x00u,0x14u,0x0eu,0x0eu,0x10u,0x0au},{0x00u,0x06u,0x0cu,0x0cu,0x06u,0x06u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_EuclideanSplit_1[8] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x31u,0x43u,0xf3u,0x1eu},{0xc0u,0x00u,0x04u,0x00u,0x0bu,0x01u},{0xc0u,0x00u,0x05u,0x00u,0x0bu,0x03u},{0x80u,0x33u,0x01u,0x01u,0x0bu,0x00u},{0x80u,0x33u,0x03u,0x03u,0x0bu,0x01u},{0x80u,0x2au,0x0bu,0x00u,0x0bu,0x00u},{0x80u,0x2au,0x0bu,0x01u,0x0bu,0x01u},{0x80u,0x2au,0x0bu,0x00u,0x01u,0x0cu}};
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_EuclideanSplit_2[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x62u,0x89u,0xd5u,0x15u},{0x40u,0x09u,0x04u,0x04u,0x04u,0x04u},{0x40u,0x6au,0x04u,0x04u,0x01u,0x04u},{0x40u,0x6au,0x04u,0x04u,0x0cu,0x04u},{0x40u,0x09u,0x05u,0x05u,0x05u,0x05u},{0x40u,0x6au,0x05u,0x05u,0x01u,0x05u},{0x40u,0x3eu,0x00u,0x00u,0x0fu,0x00u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_ExactDivideLoop[9] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xfcu,0xadu,0xefu,0xa0u},{0x00u,0x00u,0x08u,0x0au,0x08u,0x0du},{0x00u,0x00u,0x0du,0x0bu,0x0du,0x00u},{0x40u,0x0au,0x08u,0x08u,0x00u,0x08u},{0x00u,0x1eu,0x0du,0x0du,0x0fu,0x08u},{0x00u,0x00u,0x09u,0x0au,0x09u,0x0du},{0x00u,0x00u,0x0du,0x0bu,0x0du,0x00u},{0x40u,0x0au,0x09u,0x09u,0x00u,0x09u},{0x00u,0x1eu,0x0du,0x0du,0x0fu,0x09u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_Init[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xf4u,0x36u,0x82u,0x42u},{0x80u,0x00u,0x02u,0x01u,0x07u,0x03u},{0x00u,0x09u,0x07u,0x07u,0x07u,0x04u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_PrepareFirstExp[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xa8u,0x33u,0xe6u,0x4fu},{0x00u,0x22u,0x0cu,0x07u,0x02u,0x04u},{0x80u,0x00u,0x04u,0x04u,0x07u,0x01u},{0x80u,0x2au,0x07u,0x01u,0x07u,0x01u},{0x80u,0x33u,0x05u,0x05u,0x07u,0x00u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_Rerandomize[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xfcu,0xe9u,0xf6u,0xcbu},{0x00u,0x22u,0x0bu,0x07u,0x00u,0x00u},{0x00u,0x22u,0x0cu,0x07u,0x02u,0x02u},{0x00u,0x22u,0x0du,0x07u,0x01u,0x01u},{0x00u,0x22u,0x0eu,0x07u,0x03u,0x03u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/**
 * [DESIGN]
 * Prepare base number M3 and Accumulator (A0) of exponentiation.
 */
/* PS1 length = (          pkcLenN,           pkcLenN) */

/**
 * [DESIGN]
 * Re-randomize base numbers M0, M1, M2 and M3, by adding in-place random multiples of the modulus.
 *
 * PKC MACC operation is used. It takes the carry into account, to calculate: R = X0 * Y + {c, Z}.
 * The carry is written into the extra PKC word on top of pkcLenN.
 * Thus, even the carry flag is 1, this will affect only the extra PKC word, and will not be used
 * in the following MM on length pkcLenN.
 *
 * In addition, in order to ensure that the result does not overflow beyond pkcLenN, and given that
 * operations are done in-place in each buffer in a loop, the following should hold:
 * log2(iter) + bitLenR <= leadingZeroesN,
 * where leadingZeroesN is the number of leading zero bits in N, iter is the total number of re-randomization
 * iterations, and bitLenR is the bit length of the random number.
 *
 */
/* PS1 length = (          pkcLenN,           pkcLenN) */

/**
 * [DESIGN]
 * Euclidean splitting part #1: calculate "exponent mod b" on both shares of exponent.
 *
 * The modular reduction is implemented based on PKC MR (Modular Reduction).
 * The two shares of exponent are converted to their Montgomery representation
 * modulo b (length = MCUXCLPKC_WORDSIZE) by multiplying them with M0 = QDash.
 * They are converted back to their normal representation by PKC MR, and
 * results are in the range [0, b]. The PKC MS (Modular Subtraction) guarantees
 * the proper results in the range [0, b-1].
 *
 * CAUTION:
 * According to PKC specification, when calculating MM (Modular Multiplication)
 * with OPLEN = MCUXCLPKC_WORDSIZE, PKC will read the least significant PKC word
 * of the result buffer in PKC workarea (M2[0] and M3[0] in this FUP program)
 * before writing any intermediate result to it.
 * This pre-fetch will not affect the result, but caller shall ensure that
 * both PKC words M2[0] and M3[0] are initialized before this FUP program,
 * if the platform requires explicit memory initialization.
 *
 * ps, M2[0] and M3[0] have been initialized (used as temp buffer) when calculating
 * NDash and QDash before this FUP program.
 */
/* PS1 length = (MCUXCLPKC_WORDSIZE, MCUXCLPKC_WORDSIZE) */
/* PS2 length = (    pkcLenExpPlus, MCUXCLPKC_WORDSIZE) */

/**
 * [DESIGN]
 * Euclidean splitting part #2: prepare to calculate exact division:
 * "(exponent - (exponent mod b)) / b", on both shares of exponent.
 *
 * Exact division, x/b = q, assumes the dividend x must be exactly a multiple of
 * divisor b. So there is the quotient q satisfying (-x) + b*q = 0.
 */
/* PS2 length = (                -,     pkcLenExpPlus) */

/**
 * [DESIGN]
 * One iteration of exact division, where the divisor b is of the size, MCUXCLPKC_WORDSIZE.
 *
 * The algorithm of exact division q = x/b is to find q satisfying (-x) + b*q = 0.
 * Let y = -x mod 256^(pkcLenExpPlus), and y[i] and q[i] are the i-th PKC word of y and q.
 *
 * y + b*q[0] \equiv 0 mod Q, where Q = 256^(MCUXCLPKC_WORDSIZE).
 * q[0] = y * (-b)^(-1) mod Q = y[0] * NDash mod Q.
 * Assume for i > 0, y + b*q[i-1 ~ 0] \equiv 0 mod Q^i.
 * Then, q[i] = ((y + b*q[i-1 ~ 0])/(Q^i)) * NDash mod Q.
 *
 * In this implementation, the negative dividend (-x) will be overwritten by
 * quotient q word-wisely.
 */
/* PS1 length = (                -, MCUXCLPKC_WORDSIZE) */
/* PS2 length = (                -,      remainLength) */

/**
 * [DESIGN]
 * Prepare q, and interleaved b and r.
 *
 * First part: calculate q, using PS2.
 * EXPT = q = A0 - A1 = ((expA - expB) - ((expA - expB) mod b)) / b = (exp - (exp mod b)) / b
 *
 * Second part: interleave R0 = b and R1 = r, using PS1.
 * The interleaved data is written over two consecutive PKC words in TE and NDASH.
 * The result space of MAC_GF2 takes one extra PKC word and thus also overwrites R0.
 * The 2-FW buffer R2 is used as temp buffer.
 */
/* PS1 length = (                -, MCUXCLPKC_WORDSIZE) */
/* PS2 length = (                -,     pkcLenExpPlus) */

/**
 * [DESIGN]
 * Prepare base numbers for the first exponentiation.
 *
 * First part: randomized calculation of M2 = (m + (r16 * N))^2 mod N = m^2 mod N.
 * PKC MACC operation is used to calculate A0 = R1 * N + M1.
 * MACC takes the carry into account, which is written into the extra PKC word on top of pkcLenN.
 * This extra PKC word is not used in the following MM on length pkcLenN.
 *
 * Second part: prepare M0 = 1 in MR, M0 < N, with a Montgomery reduction of QSquared.
 */
/* PS1 length = (          pkcLenN,           pkcLenN) */
