/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023 NXP                                                 */
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
#include <internal/mcuxClRsa_TestPrimeCandidate_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClRsa_TestPrimeCandidate_Steps2_FUP[6] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xb2u,0xb8u,0x30u,0xebu},{0x00u,0x1eu,0x01u,0x01u,0x07u,0x05u},{0x00u,0x3eu,0x06u,0x06u,0x07u,0x06u},{0x40u,0x1eu,0x04u,0x04u,0x07u,0x06u},{0x80u,0xa7u,0x05u,0x05u,0x06u,0x06u},{0x00u,0x1bu,0x06u,0x06u,0x09u,0x05u}};
const mcuxClPkc_FUPEntry_t mcuxClRsa_TestPrimeCandidate_Steps3_FUP[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x33u,0x9eu,0xfeu,0x9au},{0x00u,0x1bu,0x01u,0x01u,0x08u,0x05u},{0x00u,0x1eu,0x00u,0x00u,0x07u,0x06u},{0x80u,0xa7u,0x05u,0x05u,0x06u,0x06u},{0x00u,0x1bu,0x06u,0x06u,0x09u,0x05u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/*
 * FUP to check the candidate is coprime with the product of first 9
 * prime.
 */

/*
 * FUP to check the candidate is coprime with the public E
 */
