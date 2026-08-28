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
 * @file  mcuxCsslMemory_Internal_Compare_arm_asm.h
 * @brief Internal header for assembly implementation of the robust memory compare function for ARM Cortex-M3/33.
 */


#ifndef MCUXCSSLMEMORY_INTERNAL_COMPARE_ARM_ASM_H_
#define MCUXCSSLMEMORY_INTERNAL_COMPARE_ARM_ASM_H_

#include <mcuxCsslMemory.h>

/**
 * @brief Memory compare function
 *
 * @param    pLhs      Left-hand side.
 * @param    pRhs      Right-hand side.
 * @param    length    Length (in bytes). Both Lhs and Rhs should be bounded by this length.
 *
 * Data Integrity: Record(status) + Expunge(&pLhs[length] + &pRhs[length])
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslMemory_FastCompare_arm_asm)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t)
mcuxCsslMemory_FastCompare_arm_asm(
  const uint8_t* pLhs,
  const uint8_t* pRhs,
  uint32_t length
);

/**
 * @brief Robust memory compare function
 *
 * @param    pLhs      Left-hand side.
 * @param    pRhs      Right-hand side.
 * @param    length    Length (in bytes). Both Lhs and Rhs should be bounded by this length.
 *
 * Data Integrity: Record(status) + Expunge(&pLhs[length] + &pRhs[length])
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslMemory_Compare_arm_asm)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t)
mcuxCsslMemory_Compare_arm_asm(
  const uint8_t* pLhs,
  const uint8_t* pRhs,
  uint32_t length
);

#endif /* MCUXCSSLMEMORY_INTERNAL_COMPARE_ARM_ASM_H_ */

