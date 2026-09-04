/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
 * @file  mcuxCsslSecureCounter_AssemblyMacros.h
 * @brief Assembly macros for the secure counter
 */

#ifndef MCUXCSSLSECURECOUNTER_ASSEMBLYMACROS_H_
#define MCUXCSSLSECURECOUNTER_ASSEMBLYMACROS_H_


#if (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)) || defined(__GNUC__)

.macro MCUX_CSSL_SC_ASM_INIT_BASE baseReg
  mov \baseReg, #0
  .endm

.macro MCUX_CSSL_SC_ASM_VALUE  baseReg, valueReg
  mov  \valueReg, \baseReg
  .endm

.macro MCUX_CSSL_SC_ASM_ADD  baseReg, valueReg
  add  \baseReg, \baseReg, \valueReg
  .endm

.macro MCUX_CSSL_SC_ASM_SUB  baseReg, valueReg
  sub \baseReg, \baseReg, \valueReg
  .endm

#elif defined(__IASMARM__) || defined(__ICCARM__)

MCUX_CSSL_SC_ASM_INIT_BASE macro baseReg
  mov baseReg, #0
  endm

MCUX_CSSL_SC_ASM_VALUE macro baseReg, valueReg
  mov  valueReg, baseReg
  endm

MCUX_CSSL_SC_ASM_ADD macro baseReg, valueReg
  add  baseReg, baseReg, valueReg
  endm

MCUX_CSSL_SC_ASM_SUB macro baseReg, valueReg
  sub  baseReg, baseReg, valueReg
  endm

#endif /* defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) || defined(__GNUC__) */



#endif /* MCUXCSSLSECURECOUNTER_ASSEMBLYMACROS_H_ */
