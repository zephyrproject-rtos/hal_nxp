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
 * @file  mcuxClEcc_Weier_BooleanToArithmeticMasking_FUP.c
 * @brief FUP program for converting boolean masking to arithmetic masking
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_Weier_BooleanToArithmeticMasking[8] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x2cu,0x70u,0xbeu,0x2eu},{0x40u,0x0fu,0x1cu,0x1cu,0x1au,0x18u},{0x40u,0x0bu,0x18u,0x18u,0x1au,0x18u},{0x40u,0x0fu,0x18u,0x18u,0x1cu,0x18u},{0x40u,0x0fu,0x1au,0x1au,0x1eu,0x1au},{0x40u,0x0fu,0x1cu,0x1cu,0x1au,0x1cu},{0x40u,0x0bu,0x1cu,0x1cu,0x1au,0x1cu},{0x40u,0x0fu,0x1cu,0x1cu,0x18u,0x1cu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/**
 * Prerequisites: 
 * S0 - Buffer for temporary value
 * S1 - Temporary mask t
 * S2 - Masked value v
 * S3 - Mask r
 *
 * Masked value will be updated with new value
 *
 * Function psi(x, r) = x ^ r - r, and is affine over F2, see paper for details.
 *
 * The correctness of the algorithm is shown in the following paper:
 * https:(doulbe slashes)doi.org/10.1007/978-3-662-48116-5_7
 */

