/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @brief FUP programs for EdDSA Key Generation
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_EdDSA_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_EdDSA_GenerateKeyPair_Prepare_S[12] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xd2u,0x27u,0x91u,0x78u},{0x40u,0x0fu,0x04u,0x04u,0x1cu,0x1au},{0x40u,0x14u,0x1au,0x1au,0x06u,0x18u},{0x40u,0x14u,0x1cu,0x1cu,0x06u,0x19u},{0x00u,0x1au,0x18u,0x18u,0x02u,0x18u},{0x40u,0x17u,0x18u,0x18u,0x02u,0x04u},{0x40u,0x17u,0x19u,0x19u,0x02u,0x1au},{0x00u,0x15u,0x05u,0x05u,0x07u,0x18u},{0x00u,0x15u,0x09u,0x09u,0x07u,0x19u},{0x00u,0x14u,0x18u,0x18u,0x08u,0x1du},{0x00u,0x14u,0x19u,0x19u,0x08u,0x1au},{0x40u,0x0fu,0x1au,0x1au,0x1du,0x1cu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/**
 * [DESIGN]                                 Ed25519                   Ed448
 * PS1 LEN =                                256-bit                   448-bit (64-bit PkcWord) or 512-bit (128-bit PkcWord)
 * PS2 LEN =                                256-bit                   512-bit
 * v2 =                                     2                         9
 * v3 =                                     4                         2 (64-bit PkcWord) or 66 (128-bit PkcWord)
 * v4 =                                     3                         2
 *
 *                                          V0 = (h0..h255)                (?*56,h0..h455)
 * 1. XOR-mask the secret key:              S1 = (h0'...h255')             (?*56,h0'..h455')
 * 2. L-shift v2 bits:                      S0 = (0,0,h0'..h253')          (0,0*8,?*56,h0'..h446')
 * 3. +1:                                   S0 = (1,0,h0'..h253')          (1,0*8,?*56,h0'..h446')
 * 4. R-rotate 1 bit:                       V0 = (0,h0'..h253',1)          (0*8,?*56,h0'..h446',1)
 *                                          V1 = V0                        (h0'..h446',1)     if 64-bit PkcWord; or V0                    if 128-bit PkcWord
 * 5. R-shift v3 bits:                      S0 = (h3'..h253',1,0*4)        (h2'..h446',1,0*2) if 64-bit PkcWord; or (h2..h446,1,0*66)     if 128-bit PkcWord
 * 6. L-shift v4 bits:                      T2 = (0,0,0,h3'..h253',1,0)    (0,0,h2'..h446',1) if 64-bit PkcWord; or (0,0,h2..h446,1,0*64) if 128-bit PkcWord
 * 7. Unmask to obtain the sub-private key: S2 = (0,0,0,h3..h253,1,0)      (0,0,h2..h446,1)
 *
 * Note: The same calculations are performed for the mask with the exception of addition. That way mask and key bit remain aligned.
 *
 */
