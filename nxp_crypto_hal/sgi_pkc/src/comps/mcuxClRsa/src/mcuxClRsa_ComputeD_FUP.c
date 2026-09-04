/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024 NXP                                            */
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
#include <internal/mcuxClRsa_ComputeD_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClRsa_ComputeD_Steps12_FUP[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x61u,0x83u,0xbeu,0x3fu},{0x00u,0x1bu,0x00u,0x00u,0x0du,0x07u},{0xc0u,0x9du,0x07u,0x06u,0x07u,0x09u},{0x00u,0x1bu,0x01u,0x01u,0x0du,0x08u},{0xc0u,0x9du,0x08u,0x06u,0x08u,0x0au}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_ComputeD_Steps3_FUP[4] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xbeu,0x07u,0x70u,0x06u},{0xc0u,0x13u,0x09u,0x0au,0x09u,0x05u},{0xc0u,0xa7u,0x09u,0x09u,0x0au,0x0au},{0x40u,0x14u,0x0au,0x0au,0x0du,0x0au}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/*
 * call the FUP code to do the below steps
 * 1. Compute (p-1)*b
 * 2. Compute (q-1)*b
 * 3. Compute lcm((p-1)*b,(q-1)*b) = (((p-1)*b)*((q-1)*b)) / gcd((p-1)*b,(q-1)*b)
 * 3.1 Compute phi_b = ((p-1)*b)*((q-1)*b)
 * 3.2 Compute gcd_b = gcd((p-1)*b,(q-1)*b)
 */



