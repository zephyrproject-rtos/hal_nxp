/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h
 * @brief Assembly macros for Counter based implementation for the flow protection mechanism, for a local security counter.
 */

#ifndef MCUXCSSLFLOWPROTECTION_SECURECOUNTER_LOCAL_ASSEMBLYMACROS_H_
#define MCUXCSSLFLOWPROTECTION_SECURECOUNTER_LOCAL_ASSEMBLYMACROS_H_

#include <mcuxCsslSecureCounter_AssemblyMacros.h>

/**
 * @def MCUX_CSSL_FP_FUNCTION_ID_ENTRY_EXIT_MASK
 * @brief Mask to be used to derive entry and exit parts from a function identifier
 * @ingroup csslFpCntFunction
 */
/* TODO: CLNS-18893 - Refactor header files to extract constants and prevent code duplication */
#define MCUX_CSSL_FP_FUNCTION_ID_ENTRY_EXIT_MASK  0x5A5A5A5A

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) || defined(__GNUC__)

.macro MCUX_CSSL_FP_ASM_FUNCTION_ENTRY rSc, rTmp, funcID
  MCUX_CSSL_SC_ASM_INIT_BASE \rSc
  ldr                       \rTmp, =(\funcID & MCUX_CSSL_FP_FUNCTION_ID_ENTRY_EXIT_MASK)
  MCUX_CSSL_SC_ASM_ADD       \rSc,  \rTmp
  .endm

.macro MCUX_CSSL_FP_ASM_FUNCTION_CALL rSc, func
  bl                        \func
  MCUX_CSSL_SC_ASM_ADD       \rSc, r1
  .endm

.macro MCUX_CSSL_FP_ASM_FUNCTION_EXIT rSc, rTmp, funcID
  ldr                       \rTmp, =(\funcID - (\funcID & MCUX_CSSL_FP_FUNCTION_ID_ENTRY_EXIT_MASK))
  MCUX_CSSL_SC_ASM_ADD       \rSc,  \rTmp   /* rSc = VALUE(fn_identifier) - VALUE(fn_identifier) & EXIT_MASK */
  .endm

#elif defined(__IASMARM__) || defined(__ICCARM__)

MCUX_CSSL_FP_ASM_FUNCTION_ENTRY macro rSc, rTmp, funcID
  MCUX_CSSL_SC_ASM_INIT_BASE rSc
  ldr                       rTmp, =(funcID & MCUX_CSSL_FP_FUNCTION_ID_ENTRY_EXIT_MASK)
  MCUX_CSSL_SC_ASM_ADD       rSc,  rTmp
  endm

MCUX_CSSL_FP_ASM_FUNCTION_CALL macro rSc, func
  bl                        func
  MCUX_CSSL_SC_ASM_ADD       rSc, r1
  endm

MCUX_CSSL_FP_ASM_FUNCTION_EXIT macro rSc, rTmp, funcID
  ldr                       rTmp, =(funcID - (funcID & MCUX_CSSL_FP_FUNCTION_ID_ENTRY_EXIT_MASK))
  MCUX_CSSL_SC_ASM_ADD       rSc,  rTmp   /* rSc = VALUE(fn_identifier) - VALUE(fn_identifier) & EXIT_MASK */
  endm

#endif /* defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) || defined(__GNUC__) */

#endif /* MCUXCSSLFLOWPROTECTION_SECURECOUNTER_LOCAL_ASSEMBLYMACROS_H_ */
