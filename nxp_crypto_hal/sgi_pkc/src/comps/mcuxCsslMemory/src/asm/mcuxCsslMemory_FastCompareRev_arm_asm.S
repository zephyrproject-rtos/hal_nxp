/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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
 * @file  mcuxCsslMemory_FastCompareRev_arm_asm.S
 * @brief Assembly implementation of the reverse order memory compare function for ARM Cortex-M3/33.
 */

#include <mcuxCsslMemory_AssemblyHeader.h>
#include <internal/mcuxCsslMemory_Internal_AssemblyMacros.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h>
#include <mcuxCsslDataIntegrity_AssemblyMacros.h>

#define rPLhs           r0
#define rPRhs           r1
#define rLength         r2
#define rWordLoopCtr    r3
#define rTmp0           r4
#define rTmp1           r5
#define rAcc            r6
#define rDiff           r8
#define rTmp2           r8
#define rSc             r9 /* Only used when CSSL_SC_USE_SW_LOCAL is enabled */

/* ARM calling convention to return flow-protected (64-bit) return value: */
/* Status code is the LSW, goes into r0 (always).                         */
/* FP token is MSW, if flow protection is enabled, goes into r1.          */
#define rStatus         r0
#define rToken          r1 /* Only used when CSSL_SC_USE_SW_LOCAL is enabled */

/* Register defines for bulk compare operations */
#define rBulk0          r4              /* Bulk compare register 0 */
#define rBulk1          r5              /* Bulk compare register 1 */
#define rBulk2          r10             /* Bulk compare register 2 */
#define rBulk3          r11             /* Bulk compare register 3 */
#define rBulk4          r7              /* Bulk compare register 4 */
#define rBulk5          r14             /* Bulk compare register 5 */

#define FA              (MCUXCSSLMEMORY_STATUS_ASM_FAULT    )
#define EQ              (MCUXCSSLMEMORY_STATUS_ASM_EQUAL    )
#define NOT_EQ          (MCUXCSSLMEMORY_STATUS_ASM_NOT_EQUAL)
#define EQ_MIN_NOT_EQ   (EQ - NOT_EQ                       )
#define NOT_EQ_MIN_FA   (NOT_EQ - FA                       )

/**
  * MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_FastCompareRev_arm_asm(
  *    uint8_t const * pLhs,     ; := r0
  *    uint8_t const * pRhs,     ; := r1
  *    uint32_t length,          ; := r2
  * );
  *
  * Data Integrity: Record(status) + Expunge(pLhs + pRhs + length)
  */

#ifdef __IASMARM__
        NAME mcuxCsslMemory_FastCompareRev_arm_asm
        PUBLIC mcuxCsslMemory_FastCompareRev_arm_asm
        SECTION .text:CODE(2)
        THUMB
#else /* armclang */
.syntax unified
.align 2
.section  .text.mcuxCsslMemory_FastCompareRev_arm_asm, "ax"
.global   mcuxCsslMemory_FastCompareRev_arm_asm
.type     mcuxCsslMemory_FastCompareRev_arm_asm, %function
#endif
mcuxCsslMemory_FastCompareRev_arm_asm:
        push    {r4-r11, lr}
        MCUX_CSSL_FP_ASM_FUNCTION_ENTRY  rSc, rTmp0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_FastCompareRev_arm_asm
        eor     rAcc, rAcc, rAcc                       /* init acc = 0x0 */
        cbz     rLength, mcuxCsslMemory_Compare_end_near
        add     rPLhs, rPLhs, rLength                  /* Set left side to the end of rPLhs: rPLhs -> rPLhs[len] */

mcuxCsslMemory_CompareRev_CheckAlignment:
        /* Check if both pointers are 4-byte aligned for bulk operations */
        orr     rTmp0, rPLhs, rPRhs
        ands    rTmp0, rTmp0, #3
        bne     mcuxCsslMemory_CompareRev_single_word_check

        /* Check if we have enough length for triple word processing (12 bytes minimum) */
        cmp     rLength, #12
        blo     mcuxCsslMemory_CompareRev_single_word_check

mcuxCsslMemory_CompareRev_TripleWord_loop:
        /* Load 3 words from LHS (reverse order) */
        sub     rPLhs, rPLhs, #12                      /* Move LHS pointer back by 12 bytes */
        ldmia   rPLhs, {rBulk0, rBulk1, rBulk4}        /* Load 3 words from LHS */
        rev     rTmp2, rBulk0                          /* Reverse first word and store into rTmp2 */
        rev     rBulk0, rBulk4                         /* Reverse third word and move in place of the first word  */
        mov     rBulk4, rTmp2                          /* Move the reversed first word into the third word */
        rev     rBulk1, rBulk1                         /* Reverse middle word in place */

        /* Load 3 words from RHS (forward order) */
        ldmia   rPRhs!, {rBulk2, rBulk3, rBulk5}       /* Load 3 words from RHS, with increment */

        /* Process first word pair */
        eor     rDiff, rBulk0, rBulk2                  /* Compare first words */
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[0] ^ b[0]) */
        /* Process second word pair */
        eor     rDiff, rBulk1, rBulk3                  /* Compare second words */
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[1] ^ b[1]) */
        /* Process third word pair */
        eor     rDiff, rBulk4, rBulk5                  /* Compare third words */
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[2] ^ b[2]) */

        subs    rLength, rLength, #12
        cmp     rLength, #12
        bhs     mcuxCsslMemory_CompareRev_TripleWord_loop

mcuxCsslMemory_Compare_end_near:
        cbz     rLength, mcuxCsslMemory_Compare_end  /* Exit if no remaining bytes */

mcuxCsslMemory_CompareRev_single_word_check:
        mov     rWordLoopCtr, rLength, lsr #2          /* Compute div = length / 4 */
        cbz     rWordLoopCtr, mcuxCsslMemory_Compare_byte_loop

mcuxCsslMemory_Compare_word_loop:
        ldr     rTmp0, [rPLhs, #-4]!                   /* Load left once, pre-decrement */
        rev     rTmp0, rTmp0                           /* Reverse */
        ldr     rTmp1, [rPRhs], #4                     /* Load right once, post-increment */
        eor     rDiff, rTmp0, rTmp1
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[i] ^ b[i]) */
        subs    rWordLoopCtr, #1
        bne     mcuxCsslMemory_Compare_word_loop
        and     rLength, rLength, #3                   /* Compute rem = length % 4 */
        cbz     rLength, mcuxCsslMemory_Compare_end

mcuxCsslMemory_Compare_byte_loop:
        ldrb    rTmp0, [rPLhs, #-1]!                   /* Load left once, pre-decrement */
        ldrb    rTmp1, [rPRhs], #1                     /* Load right once, post-increment */
        eor     rDiff, rTmp0, rTmp1
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[i] ^ b[i]) */
        subs    rLength, #1
        bne     mcuxCsslMemory_Compare_byte_loop

mcuxCsslMemory_Compare_end:
        MCUX_CSSL_SC_ASM_ADD    rSc, rLength            /* Record(rLength) to DI (should be zero at this point) */
        MCUX_CSSL_SC_ASM_SUB    rSc, rPLhs              /* Expunge(rPLhs) (should be start + length now) */
        MCUX_CSSL_SC_ASM_SUB    rSc, rPRhs              /* Expunge(rPLhs) (should be start now) */
        ldr    rStatus, =FA                            /* Prepare FA into return status */

        /* acc == 0 check */
        MCUX_CSSL_MEMORY_ASM_SEQZ  rTmp2, rAcc, rTmp0   /* rTmp2 is 1 iff acc == 0 */
        ldr     rTmp0, =EQ_MIN_NOT_EQ                  /* Load (EQ - NOT_EQ) */
        ldr     rTmp1, =NOT_EQ_MIN_FA                  /* Load (NOT_EQ - FA) */
        mul     rTmp2, rTmp2, rTmp0
        add     rTmp2, rTmp2, rTmp1
        add     rStatus, rStatus, rTmp2

        MCUX_CSSL_SC_ASM_ADD    rSc, rStatus            /* Record(status) */
        MCUX_CSSL_FP_ASM_FUNCTION_EXIT rSc, rTmp0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_FastCompareRev_arm_asm
        mov     rToken, rSc
        pop     {r4-r11, pc}

#ifdef __IASMARM__
        END
#endif
