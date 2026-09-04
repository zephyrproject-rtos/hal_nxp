/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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
 * @file  mcuxClMath_ExactDivideOdd_FUP.c
 * @brief mcuxClMath: implementation of exact divide with odd divisor
 */

#include <internal/mcuxClMath_ExactDivideOdd_FUP.h>
#include <internal/mcuxClMath_Internal_ExactDivideOdd.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClMath_Fup_ExactDivideOdd_DivideLoop[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x20u,0x50u,0xb3u,0x58u},{0x40u,0x20u,0x02u,0x00u,0x02u,0x02u},{0x40u,0x00u,0x02u,0x00u,0x02u,0x04u},{0x40u,0x1eu,0x04u,0x04u,0x08u,0x05u},{0x00u,0x62u,0x01u,0x01u,0x02u,0x02u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_Fup_ExactDivideOdd_NDashY[4] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x3du,0x63u,0xf6u,0xe8u},{0x40u,0x00u,0x00u,0x01u,0x00u,0x04u},{0x40u,0x1au,0x04u,0x04u,0x05u,0x04u},{0x40u,0x00u,0x04u,0x00u,0x04u,0x00u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/**
 * [DESIGN]
 * Suppose T \equiv (-Y)^(-1) (mod 2^(bit)).
 * Since (T*Y+1) \equiv 0 (mod 2^(bit)), so (T*Y+1)^2 = ((T*Y+2)*T*Y + 1) \equiv 0 (mod 2^(2*bit)).
 * This FUP program calculates: T := (T*Y+2)*T \equiv (-Y)^(-1) (mod 2^(2*bit)).
 */
/* PS2 length = (-, MCUXCLPKC_WORDSIZE) */
/* uptrt[DivOdd_Ri] = 2                */

/**
 * [DESIGN]
 * In iteration i (i = 0 ~ rPkcWord-1), this FUP program calculates R[i], and
 * X{i+1} = (Xi + R[i]*Y) / W = (X0 + R[i~0]*Y) / W^(i+1).
 *
 * CAUTION:
 * The MACCR in this FUP program will access to t+1 PKC words of X, where
 * t = min(yPkcWord, rPkcWord - i) = effectivePkcByteLenY / MCUXCLPKC_WORDSIZE.
 * In the boundary case, t = 1 (when xPkcByteLen = yPkcByteLen = MCUXCLPKC_WORDSIZE),
 * and 2 PKC words of X will be read (but xPkcByteLen = MCUXCLPKC_WORDSIZE).
 */
/* PS1 length = (-, effectivePkcByteLenY) */
/* PS2 length = (-, MCUXCLPKC_WORDSIZE) */
