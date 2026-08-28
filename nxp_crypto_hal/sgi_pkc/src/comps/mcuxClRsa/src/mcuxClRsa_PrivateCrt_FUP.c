/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023, 2026 NXP                                           */
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

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClRsa_PrivateCrt_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClRsa_PrivateCrt_CalcM1_FUP[4] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x10u,0x7du,0x59u,0x76u},{0xc0u,0x33u,0x0eu,0x0eu,0x10u,0x0fu},{0x80u,0x00u,0x0cu,0x0fu,0x10u,0x0eu},{0x80u,0x2au,0x10u,0x0eu,0x10u,0x0bu}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_PrivateCrt_CalcM_b_FUP[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x11u,0x17u,0x00u,0xe2u},{0x80u,0x13u,0x03u,0x04u,0x03u,0x0fu},{0x40u,0x3eu,0x10u,0x10u,0x11u,0x10u},{0x00u,0x1eu,0x06u,0x06u,0x11u,0x10u},{0x40u,0x0au,0x0fu,0x0fu,0x10u,0x0eu}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_PrivateCrt_T1mb_FUP[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xf7u,0x3au,0x71u,0x0au},{0x80u,0x00u,0x07u,0x06u,0x02u,0x03u},{0xc0u,0x2au,0x02u,0x09u,0x03u,0x0au}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_PrivateCrt_T2T3T4mb_FUP[6] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x2du,0x85u,0x77u,0xe6u},{0x80u,0x00u,0x07u,0x05u,0x02u,0x03u},{0x80u,0x00u,0x07u,0x04u,0x02u,0x05u},{0xc0u,0x2au,0x02u,0x03u,0x05u,0x04u},{0xc0u,0x00u,0x0au,0x04u,0x02u,0x03u},{0xc0u,0x33u,0x03u,0x03u,0x02u,0x04u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/*
 * FUP to calculate Mp_bm - Mq_bm mod p_b
 * PS1 len: (qDashAlignLen, blindedPrimeAlignLen)
 * PS2 len: (blindedPrimeAlignLen, blindedPrimeAlignLen)
 */

/*
 * FUP to calculate T2_mb, T3_mb, qInv_bm, T4_mb, T4_b
 * PS1 len: (qDashAlignLen, blindedPrimeAlignLen)
 * PS2 len: (blindedPrimeAlignLen, blindedPrimeAlignLen)
 */

/*
 * FUP to calculate the masked message M_b
 * PS1 len: (primeAlignLen, blindedPrimeAlignLen)
 * PS2 len: (0U, blindedMessageAlignLen)
 */

/*
 * FUP to calculate and normalized the message M1
 * PS1 len: (modAlignLen, modAlignLen)
 * PS2 len: (blindedMessageAlignLen, modAlignLen)
 */
