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
#include <internal/mcuxClRsa_Util_KeyGeneration_Crt_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xc5u,0x58u,0x1cu,0x63u},{0xc0u,0x9du,0x01u,0x0au,0x01u,0x0bu},{0xc0u,0x9du,0x02u,0x0au,0x02u,0x0cu}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x78u,0x60u,0x80u,0xa5u},{0xc0u,0x13u,0x0bu,0x0cu,0x0bu,0x0du},{0x00u,0x00u,0x0au,0x0au,0x0au,0x0eu}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP[4] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x61u,0xbdu,0xacu,0x80u},{0x00u,0x1bu,0x01u,0x01u,0x10u,0x08u},{0xc0u,0x9du,0x08u,0x0au,0x08u,0x06u},{0x00u,0x1eu,0x00u,0x00u,0x0fu,0x07u}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP[4] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x61u,0xbdu,0xafu,0x83u},{0x00u,0x1bu,0x02u,0x02u,0x10u,0x08u},{0xc0u,0x9du,0x08u,0x0au,0x08u,0x06u},{0x00u,0x1eu,0x00u,0x00u,0x0fu,0x07u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/*
 * FUP to compute (p-1)*b and copy E
 */

/*
 * FUP to compute (q-1)*b and copy E
 */

/*
 * FUP to blind p and q
 */

/*
 * FUP to compute Nb and RandSquare
 */

