/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * @file  mcuxClMath_QDash_FUP.c
 * @brief mcuxClMath: FUP programs used in mcuxClMath_QDash
 */


#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClMath_QDash_FUP.h>
#include <internal/mcuxClMath_Internal_QDash.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClMath_QDash_Fup_Init[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x21u,0xccu,0x17u,0x06u},{0x00u,0x09u,0x01u,0x01u,0x01u,0x00u},{0x80u,0x21u,0x02u,0x00u,0x00u,0x03u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_QDash_Fup_Loop0[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xddu,0x52u,0x99u,0x5du},{0x80u,0x00u,0x03u,0x03u,0x01u,0x00u},{0x00u,0x1eu,0x00u,0x00u,0x04u,0x03u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_QDash_Fup_Loop1[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xa1u,0xc5u,0x15u,0x04u},{0x80u,0x00u,0x03u,0x03u,0x01u,0x00u},{0x80u,0x21u,0x02u,0x00u,0x00u,0x03u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()



/* ps1Len = (          -, operandSize) */


/**
 * [DESIGN] Square only
 * CAUTION:
 * According to PKC specification, when calculating MM (Modular Multiplication)
 * with OPLEN = MCUXCLPKC_WORDSIZE, PKC will read the least significant PKC word
 * of the result buffer in PKC workarea (T[0] in this FUP program) before writing
 * any intermediate result to it. This behavior will not affect the correctness,
 * but the PKC word T[0] needs to be initialized before this FUP program,
 * if the platform requires explicit memory initialization.
 *
 * ps, T[0] has been initialized when calling the FUP program above (QDash_Fup_init).
 */
/* ps1Len = (operandSize, operandSize) */


/**
 * [DESIGN] Square and multiply
 * CAUTION: see the above FUP program, mcuxClMath_QDash_Fup_Loop0.
 */
/* ps1Len = (operandSize, operandSize) */
