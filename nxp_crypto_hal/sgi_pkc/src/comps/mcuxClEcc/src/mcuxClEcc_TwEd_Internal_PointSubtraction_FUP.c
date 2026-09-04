/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025 NXP                                                 */
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
 * @file  mcuxClEcc_TwEd_Internal_PointSubtraction_FUP.c
 * @brief FUP programs used in ECC functions for Twisted Edwards curve Ed25519
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointSubtraction[22] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x88u,0x80u,0xb5u,0xf0u},{0x80u,0x2au,0x10u,0x10u,0x20u,0x20u},{0x80u,0x00u,0x3bu,0x22u,0x00u,0x18u},{0x80u,0x00u,0x18u,0x18u,0x00u,0x19u},{0x80u,0x00u,0x39u,0x20u,0x00u,0x1au},{0x80u,0x00u,0x3au,0x21u,0x00u,0x1bu},{0x80u,0x00u,0x1au,0x1bu,0x00u,0x1cu},{0x80u,0x00u,0x13u,0x1cu,0x00u,0x1eu},{0x80u,0x2au,0x10u,0x19u,0x1eu,0x1du},{0x80u,0x21u,0x10u,0x19u,0x1eu,0x19u},{0x80u,0x21u,0x10u,0x39u,0x3au,0x1cu},{0x80u,0x21u,0x10u,0x20u,0x21u,0x1eu},{0x80u,0x00u,0x1cu,0x1eu,0x00u,0x1fu},{0x80u,0x2au,0x10u,0x1fu,0x1au,0x1cu},{0x80u,0x2au,0x10u,0x1cu,0x1bu,0x1cu},{0x80u,0x00u,0x18u,0x1du,0x00u,0x1eu},{0x80u,0x00u,0x1eu,0x1cu,0x00u,0x20u},{0x80u,0x00u,0x12u,0x1au,0x00u,0x1cu},{0x80u,0x2au,0x10u,0x1bu,0x1cu,0x1bu},{0x80u,0x00u,0x18u,0x19u,0x00u,0x1au},{0x80u,0x00u,0x1au,0x1bu,0x00u,0x21u},{0x80u,0x00u,0x1du,0x19u,0x00u,0x22u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * FUP program to do point subtraction P1 - P2.
 * The source for algorithm used for addition is:
 *      2008 Bernstein--Birkner--Joye--Lange--Peters http://eprint.iacr.org/2008/013 Section 6
 *
 * Prerequisites:
 *  - TWED_PP_X7 contains the X-coordinate of point P1
 *  - TWED_PP_Y7 contains the Y-coordinate of point P1
 *  - TWED_PP_T7 contains the Z-coordinate of point P1
 *  - TWED_X contains the X-coordinate of point P2
 *  - TWED_Y contains the Y-coordinate of point P2
 *  - TWED_Z contains the Z-coordinate of point P2
 *  - ECC_CP0 contains domain parameter a
 *
 * Result:
 *  - Buffers TWED_X, TWED_Y, TWED_Z contain the result (X:Y:Z) in MR
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()

