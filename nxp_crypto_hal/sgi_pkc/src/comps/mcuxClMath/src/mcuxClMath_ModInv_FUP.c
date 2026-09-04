/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClMath_ModInv_FUP.c
 * @brief mcuxClMath: modular inversion implementation
 */


#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClMath_Internal_ModInv.h>
#include <internal/mcuxClMath_ModInv_FUP.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_FUP_PROGRAM()
const mcuxClPkc_FUPEntry_t mcuxClMath_ModInv_Fup1[7] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xfeu,0xadu,0x01u,0x21u},{0x40u,0x3eu,0x00u,0x00u,0x06u,0x00u},{0x00u,0x1au,0x00u,0x00u,0x05u,0x03u},{0x80u,0x5du,0x01u,0x02u,0x03u,0x04u},{0x00u,0x1eu,0x03u,0x03u,0x06u,0x01u},{0x00u,0x3eu,0x03u,0x03u,0x06u,0x03u},{0x80u,0x2au,0x01u,0x01u,0x04u,0x02u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_ModInv_Fup2a[4] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xcbu,0x58u,0x81u,0xf1u},{0x40u,0x3eu,0x00u,0x00u,0x06u,0x00u},{0x00u,0x1au,0x00u,0x00u,0x05u,0x03u},{0x80u,0x5du,0x01u,0x02u,0x03u,0x04u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_ModInv_Fup2b[5] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x0fu,0x3bu,0xdbu,0xabu},{0xc0u,0x53u,0x01u,0x03u,0x01u,0x02u},{0x00u,0x1eu,0x02u,0x02u,0x06u,0x01u},{0x00u,0x3eu,0x03u,0x03u,0x06u,0x03u},{0x80u,0x2au,0x01u,0x01u,0x04u,0x02u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_ModInv_Fup3a[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0xc9u,0x51u,0x7au,0xe2u},{0x80u,0x00u,0x02u,0x03u,0x01u,0x00u},{0x00u,0x1eu,0x00u,0x00u,0x06u,0x03u}};
const mcuxClPkc_FUPEntry_t mcuxClMath_ModInv_Fup3b[3] MCUX_FUP_ATTRIBUTE = {{0x10u,0x00u,0x00u,0xf6u,0x90u,0xd4u},{0x80u,0x00u,0x02u,0x03u,0x01u,0x00u},{0x80u,0x33u,0x00u,0x00u,0x01u,0x03u}};
MCUX_CSSL_ANALYSIS_STOP_PATTERN_FUP_PROGRAM()


/* For the case that x and n are coprime.                      */
/* ps1Len = (31*MCUXCLPKC_WORDSIZE, operandSize), i.e., LC = 31 */
/* ps2Len = (                   -, operandSize + PKC wordsize) */

/* For the case that x and n are not coprime.                  */
/* ps1Len = (31*MCUXCLPKC_WORDSIZE, operandSize), i.e., LC = 31 */
/* ps2Len = (                   -, operandSize + PKC wordsize) */

/* For the case that x and n are not coprime.                  */
/* ps1Len = (     -     , operandSize)                         */
/* ps2Len = (operandSize, operandSize)                         */

/* ps1Len = (operandSize, operandSize) */

/* ps1Len = (operandSize, operandSize) */
