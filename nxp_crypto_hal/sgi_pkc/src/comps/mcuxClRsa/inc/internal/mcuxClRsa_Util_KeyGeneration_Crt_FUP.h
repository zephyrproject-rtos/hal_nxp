/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024, 2026 NXP                                      */
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

/** @file  mcuxClRsa_Util_KeyGeneration_Crt_FUP.h
*  @brief defines FUP programs byte arrays for mcuxClRsa_Util_KeyGeneration_Crt
*/
#ifndef MCUXCLRSA_UTIL_KEYGENERATION_CRT_FUP_H_
#define MCUXCLRSA_UTIL_KEYGENERATION_CRT_FUP_H_
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>

#define mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP_LEN  4U
#define mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP_LEN  4U
#define mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP_LEN  3U
#define mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP_LEN  3U

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP,
  mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDP_FUP_LEN
);

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP,
  mcuxClRsa_Util_KeyGeneration_Crt_ParamsForDQ_FUP_LEN
);

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP,
  mcuxClRsa_Util_KeyGeneration_Crt_BlindPQ_FUP_LEN
);

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP,
  mcuxClRsa_Util_KeyGeneration_Crt_ComputeNbAndRandSquare_FUP_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#endif /* MCUXCLRSA_UTIL_KEYGENERATION_CRT_FUP_H_ */
