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
 * @file  mcuxClEcc_TwEd_Internal_UpdateExtHomCoords_FUP.c
 * @brief FUP programs used in ECC functions for Twisted Edwards curve
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_TwEd_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_TwEd_UpdateExtHomCoords[11] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x5cu,0x39u,0x86u,0x79u},{0x80u,0x00u,0x04u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x04u},{0x80u,0x00u,0x06u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x06u},{0x10u,0x00u,0xa7u,0xb6u,0xecu,0x95u},{0x80u,0x00u,0x05u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x05u},{0x10u,0x00u,0x94u,0xb4u,0x8cu,0xa7u},{0x80u,0x00u,0x07u,0x19u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x07u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * FUP program to update extend homogeneous coordinates of point with new random Z in [1, p-1]
 *
 * Prerequisites:
 *  - TWED_V0 contains the X-coordinate of point
 *  - TWED_V1 contains the Y-coordinate of point
 *  - TWED_V2 contains the T-coordinate of point
 *  - TWED_V3 contains the Z-coordinate of point
 *  - ECC_T0 contains random number in range [1, p-1] to update new Z = TWED_Z * ECC_T0
 *
 * Result:
 *  - Buffers TWED_V0, TWED_V1, TWED_V2, TWED_V3
 *    contain the new (X*ECC_T0:Y*ECC_T0:T*ECC_T0:Z*ECC_T0) all in range [1, p-1]
 *  - Buffers ECC_T1 corrupted
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()

