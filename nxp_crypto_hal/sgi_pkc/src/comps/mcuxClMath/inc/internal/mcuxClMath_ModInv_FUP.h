/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024, 2026 NXP                                 */
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
 * @file  mcuxClMath_ModInv_FUP.h
 * @brief defines FUP program byte arrays for mcuxClMath_ModInv
 */

#ifndef MCUXCLMATH_MODINV_FUP_H_
#define MCUXCLMATH_MODINV_FUP_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClPkc_FupMacros.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
/*
 * FUP program declaration mcuxClMath_ModInv_Fup1
 */
#define mcuxClMath_ModInv_Fup1_LEN  7u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_ModInv_Fup1,
  mcuxClMath_ModInv_Fup1_LEN
);


/*
 * FUP program declaration mcuxClMath_ModInv_Fup2
 */
#define mcuxClMath_ModInv_Fup2a_LEN  4u
#define mcuxClMath_ModInv_Fup2b_LEN  5u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_ModInv_Fup2a,
  mcuxClMath_ModInv_Fup2a_LEN
);

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_ModInv_Fup2b,
  mcuxClMath_ModInv_Fup2b_LEN
);


/*
 * FUP program declaration mcuxClMath_ModInv_Fup3
 */
#define mcuxClMath_ModInv_Fup3_LEN 3u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_ModInv_Fup3a,
  mcuxClMath_ModInv_Fup3_LEN
);

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_ModInv_Fup3b,
  mcuxClMath_ModInv_Fup3_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMATH_MODINV_FUP_H_ */
