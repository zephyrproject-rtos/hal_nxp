/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClEcc_TwEd_Internal_PointValidation_FUP.c
 * @brief mcuxClEcc: FUP programs used in ECC functions for Twisted Edwards curves
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointValidation_AffineNR[14] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x33u,0x37u,0xb6u,0x27u},{0x80u,0x00u,0x20u,0x16u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x1du,0x00u,0x19u},{0x80u,0x00u,0x21u,0x16u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x1du,0x00u,0x1bu},{0x80u,0x00u,0x12u,0x19u,0x00u,0x1du},{0x80u,0x21u,0x10u,0x1du,0x1bu,0x1fu},{0x80u,0x00u,0x13u,0x19u,0x00u,0x1du},{0x80u,0x00u,0x1du,0x1bu,0x00u,0x19u},{0x80u,0x2au,0x10u,0x1fu,0x19u,0x1du},{0x00u,0x09u,0x00u,0x00u,0x00u,0x1fu},{0x80u,0x2au,0x10u,0x1du,0x1fu,0x19u},{0x80u,0x33u,0x19u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x19u}};
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointValidation_HomMR[13] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xc9u,0xc3u,0x5eu,0xf7u},{0x80u,0x00u,0x20u,0x20u,0x00u,0x19u},{0x80u,0x00u,0x21u,0x21u,0x00u,0x1bu},{0x80u,0x00u,0x12u,0x19u,0x00u,0x1du},{0x80u,0x21u,0x10u,0x1du,0x1bu,0x1du},{0x80u,0x00u,0x13u,0x19u,0x00u,0x1fu},{0x80u,0x00u,0x1fu,0x1bu,0x00u,0x19u},{0x80u,0x00u,0x22u,0x22u,0x00u,0x1fu},{0x80u,0x2au,0x10u,0x1du,0x1fu,0x1du},{0x80u,0x00u,0x1du,0x1fu,0x00u,0x1bu},{0x80u,0x2au,0x10u,0x1bu,0x19u,0x1du},{0x80u,0x33u,0x1du,0x1du,0x00u,0x1fu},{0x80u,0x2au,0x00u,0x1fu,0x00u,0x1fu}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/* FUP program: Validate twisted Edwards curve point in affine coordinates (x,y) */
/* Input: x and y are stored in (TWED_X, TWED_Y);                                */
/* Result: ECC_T0 = 0 and PKC_ZERO is set if and only (x,y) lies on the curve.   */



/* FUP program: calculate curve equation for given point         */
/* Prerequisites:                                                */
/* Input: P = (x,y,z) in (TWED_X,TWED_Y,TWED_Z);                 */
/* Output: ECC_T3 = 0 if input point is a valid point            */
