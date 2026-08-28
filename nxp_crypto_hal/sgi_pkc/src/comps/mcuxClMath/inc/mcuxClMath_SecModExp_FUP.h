/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024 NXP                                                  */
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

/** @file  mcuxClMath_SecModExp_FUP.h
*  @brief defines FUP programs byte arrays
*/
#ifndef MCUXCLMATH_SECMODEXP_FUP_H_
#define MCUXCLMATH_SECMODEXP_FUP_H_
#include <internal/mcuxClPkc_FupMacros.h>

extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_CalcQAndInterleave[6];
extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_EuclideanSplit_1[8];
extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_EuclideanSplit_2[7];
extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_ExactDivideLoop[9];
extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_Init[3];
extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_PrepareFirstExp[5];
extern const mcuxClPkc_FUPEntry_t mcuxClMath_SecModExp_Fup_Rerandomize[5];

#endif /* MCUXCLMATH_SECMODEXP_FUP*/ 
