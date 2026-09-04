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
 * @file  mcuxClEcc_TwEd_Internal_PointArithmetic_FUP.c
 * @brief mcuxClEcc: FUP programs used in ECC functions for Twisted Edwards curves
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_PointDouble[16] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xdeu,0x93u,0xadu,0xa3u},{0x80u,0x21u,0x00u,0x20u,0x21u,0x1bu},{0x80u,0x00u,0x1bu,0x1bu,0x00u,0x19u},{0x80u,0x00u,0x20u,0x20u,0x00u,0x1bu},{0x80u,0x00u,0x21u,0x21u,0x00u,0x1du},{0x80u,0x00u,0x12u,0x1bu,0x00u,0x1fu},{0x80u,0x21u,0x10u,0x1fu,0x1du,0x20u},{0x80u,0x2au,0x10u,0x1fu,0x1du,0x1fu},{0x80u,0x00u,0x20u,0x1fu,0x00u,0x21u},{0x80u,0x00u,0x22u,0x22u,0x00u,0x1fu},{0x80u,0x21u,0x10u,0x1fu,0x1fu,0x1fu},{0x80u,0x2au,0x10u,0x20u,0x1fu,0x1fu},{0x80u,0x00u,0x20u,0x1fu,0x00u,0x22u},{0x80u,0x2au,0x10u,0x19u,0x1bu,0x19u},{0x80u,0x2au,0x10u,0x19u,0x1du,0x19u},{0x80u,0x00u,0x19u,0x1fu,0x00u,0x20u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


MCUX_CSSL_ANALYSIS_START_SUPPRESS_NESTED_COMMENTS("Links are allowed in comments.")
/* FUP program to perform point doubling on a twisted Edwards curve in      */
/* homogeneous coordinates following https://eprint.iacr.org/2008/013.pdf.  */
/*                                                                          */
/* Prerequisites:                                                           */
/* - Buffers TWED_X, TWED_Y, TWED_Z contain the homogeneous coordinates     */
/*   (X:Y:Z) of P in MR                                                     */
/* - ps1Len = (operandSize, operandSize)                                    */
/* - Buffer ECC_PFULL contains p'||p                                        */
/* - Buffer ECC_PS contains the shifted modulus associated to p             */
/*                                                                          */
/* Result:                                                                  */
/* - The resulting coordinates (Xres:Yres:Zres) are stored in buffers       */
/*   TWED_X, TWED_Y and TWED_Z in MR.                                       */
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NESTED_COMMENTS()
