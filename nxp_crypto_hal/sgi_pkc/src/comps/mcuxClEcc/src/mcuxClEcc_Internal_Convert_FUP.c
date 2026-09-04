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
 * @file  mcuxClEcc_Internal_Convert_FUP.c
 * @brief mcuxClEcc: FUP programs for generic ECC coordinate conversion
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Internal_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClEcc_FUP_ConvertHomToAffine[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x4eu,0xd7u,0xe8u,0x4cu},{0x80u,0x00u,0x19u,0x16u,0x00u,0x1bu},{0x80u,0x2au,0x00u,0x1bu,0x00u,0x1bu},{0x80u,0x00u,0x1bu,0x20u,0x00u,0x19u},{0x80u,0x2au,0x00u,0x19u,0x00u,0x20u},{0x80u,0x00u,0x1bu,0x21u,0x00u,0x19u},{0x80u,0x2au,0x00u,0x19u,0x00u,0x21u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/* Prerequisites:
 *  - Homogeneous X- and Y-coordinates are stored in ECC_COORD00 and ECC_COORD01 in MR
 *  - (Z*R)^(-1), where Z is the homogeneous Z-coordinate is stored in ECC_T0
 *
 * Result:
 *  - The affine coordinates x and y are stored in buffers ECC_COORD00 and ECC_COORD01 in NR in range [0,p-1]. */
