/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023, 2026 NXP                                           */
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
 * @file  mcuxClMath_SecModExp_FUP.h
 * @brief defines FUP program byte arrays for mcuxClMath_SecModExp
 */

#ifndef MCUXCLMATH_SECMODEXP_FUP_H_
#define MCUXCLMATH_SECMODEXP_FUP_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClPkc_FupMacros.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_LINKAGE_FUP()
/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_Init
 */
#define mcuxClMath_SecModExp_Fup_Init_LEN  3u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_Init,
  mcuxClMath_SecModExp_Fup_Init_LEN
);


/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_Rerandomize
 */
#define mcuxClMath_SecModExp_Fup_Rerandomize_LEN  5u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_Rerandomize,
  mcuxClMath_SecModExp_Fup_Rerandomize_LEN
);


/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_EuclideanSplit_1
 */
#define mcuxClMath_SecModExp_Fup_EuclideanSplit_1_LEN  8u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_EuclideanSplit_1,
  mcuxClMath_SecModExp_Fup_EuclideanSplit_1_LEN
);


/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_EuclideanSplit_2
 */
#define mcuxClMath_SecModExp_Fup_EuclideanSplit_2_LEN  7u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_EuclideanSplit_2,
  mcuxClMath_SecModExp_Fup_EuclideanSplit_2_LEN
);


/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_ExactDivideLoop
 */
#define mcuxClMath_SecModExp_Fup_ExactDivideLoop_LEN  9u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_ExactDivideLoop,
  mcuxClMath_SecModExp_Fup_ExactDivideLoop_LEN
);


/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_CalcQAndInterleave
 */
#define mcuxClMath_SecModExp_Fup_CalcQAndInterleave_LEN  6u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_CalcQAndInterleave,
  mcuxClMath_SecModExp_Fup_CalcQAndInterleave_LEN
);


/*
 * FUP program declaration mcuxClMath_SecModExp_Fup_PrepareFirstExp
 */
#define mcuxClMath_SecModExp_Fup_PrepareFirstExp_LEN  5u

MCUXCLPKC_FUP_EXT_ROM_DECLARE(
  mcuxClMath_SecModExp_Fup_PrepareFirstExp,
  mcuxClMath_SecModExp_Fup_PrepareFirstExp_LEN
);

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_LINKAGE_FUP()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMATH_SECMODEXP_FUP_H_ */
