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
 * @file  mcuxCsslMemory_Compare_arm_asm.S
 * @brief Assembly implementation of the robust memory compare function for ARM Cortex-M3/33.
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
#define rDoubleWordLoopCtr r3
#define rTmp0           r4
#define rTmp1           r5
#define rAcc            r6
#define rInvAcc         r7
#define rAccXnorInvAcc  r7
#define rDiff           r8
#define rTmp2           r8
#define rSc             r9 /* Only used when CSSL_SC_USE_SW_LOCAL is enabled */
#define rTmp3           r10 /* Additional temp register for double word loop */
#define rTmp4           r11 /* Additional temp register for double word loop */

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

#define FA              (MCUXCSSLMEMORY_STATUS_ASM_FAULT    )
#define EQ              (MCUXCSSLMEMORY_STATUS_ASM_EQUAL    )
#define NOT_EQ          (MCUXCSSLMEMORY_STATUS_ASM_NOT_EQUAL)
#define EQ_MIN_NOT_EQ   (EQ - NOT_EQ                       )
#define NOT_EQ_MIN_FA   (NOT_EQ - FA                       )

/**
  * MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Compare_arm_asm(
  *    uint8_t const * pLhs,     ; := r0
  *    uint8_t const * pRhs,     ; := r1
  *    uint32_t length,          ; := r2
  * );
  *
  * Data Integrity: Record(status) + Expunge(pLhs + pRhs + length)
  */

#ifdef __IASMARM__
        NAME mcuxCsslMemory_Compare_arm_asm
        PUBLIC mcuxCsslMemory_Compare_arm_asm
        SECTION .text:CODE(2)
        THUMB
#else /* armclang */
.syntax unified
.align 2
.section  .text.mcuxCsslMemory_Compare_arm_asm, "ax"
.global   mcuxCsslMemory_Compare_arm_asm
.type     mcuxCsslMemory_Compare_arm_asm, %function
#endif
mcuxCsslMemory_Compare_arm_asm:
        push    {r4-r11, lr}
        MCUX_CSSL_FP_ASM_FUNCTION_ENTRY  rSc, rTmp0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Compare_arm_asm
        MCUX_CSSL_SC_ASM_ADD       rSc, rLength         /* Record(length) to make end pointer match caller record */
        eor     rAcc, rAcc, rAcc                       /* init acc = 0x0 */
        mvn     rInvAcc, rAcc                          /* init inverse acc = 0xffffffff */
        mov     rWordLoopCtr, rLength, lsr #2          /* Compute div = length / 4 */
        cbz     rLength, mcuxCsslMemory_Compare_end_near

mcuxCsslMemory_Int_Copy_arm_asm_CheckAlignment:
        orr   rTmp0, rPLhs, rPRhs
        ands  rTmp0, rTmp0, #3
        bne   mcuxCsslMemory_Compare_single_word_check

        /* Check if we have enough length for double word processing (8 bytes minimum) */
        cmp     rLength, #8
        blo     mcuxCsslMemory_Compare_single_word_check

        /* Calculate double word loop counter */
        mov     rDoubleWordLoopCtr, rLength, lsr #3    /* Compute div = length / 8 */

mcuxCsslMemory_Compare_DoubleWord_loop:
        ldmia   rPLhs, {rBulk0, rBulk1}                /* Load 2 words from LHS with increment */
        ldmia   rPRhs, {rBulk2, rBulk3}                /* Load 2 words from RHS with increment */

        eor     rDiff, rBulk0, rBulk2                  /* Compare first words */
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[0] ^ b[0]) */
        eor     rDiff, rBulk1, rBulk3                  /* Compare second words */
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[1] ^ b[1]) */

        ldmia   rPLhs!, {rBulk0, rBulk1}               /* Load 2 words from LHS with increment */
        ldmia   rPRhs!, {rBulk2, rBulk3}               /* Load 2 words from RHS with increment */

        eor     rDiff, rBulk0, rBulk2                  /* Redundant XOR for security */
        bic     rInvAcc, rInvAcc, rDiff                /* accInv &= ~(a[0] ^ b[0]) */
        eor     rDiff, rBulk1, rBulk3                  /* Redundant XOR for security */
        bic     rInvAcc, rInvAcc, rDiff                /* accInv &= ~(a[1] ^ b[1]) */

        subs    rDoubleWordLoopCtr, #1
        bne     mcuxCsslMemory_Compare_DoubleWord_loop
        and     rLength, rLength, #7                   /* Compute rem = length % 8 */

mcuxCsslMemory_Compare_end_near:
        cbz     rLength, mcuxCsslMemory_Compare_end     /* Exit if no remaining bytes */

mcuxCsslMemory_Compare_single_word_check:
        mov     rWordLoopCtr, rLength, lsr #2          /* Compute div = length / 4 */
        cbz     rWordLoopCtr, mcuxCsslMemory_Compare_byte_loop

mcuxCsslMemory_Compare_word_loop:
        ldr     rTmp0, [rPLhs]                         /* Load once, no increment */
        ldr     rTmp1, [rPRhs]
        eor     rDiff, rTmp0, rTmp1
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[i] ^ b[i]) */
        ldr     rTmp0, [rPLhs], #4                     /* Load twice, post-increment */
        ldr     rTmp1, [rPRhs], #4
        eor     rDiff, rTmp0, rTmp1
        bic     rInvAcc, rInvAcc, rDiff                /* accInv &= ~(a[i] ^ b[i]) */
        subs    rWordLoopCtr, #1
        bne     mcuxCsslMemory_Compare_word_loop
        and     rLength, rLength, #3                   /* Compute rem = length % 4 */
        cbz     rLength, mcuxCsslMemory_Compare_end

mcuxCsslMemory_Compare_byte_loop:
        ldrb    rTmp0, [rPLhs]
        ldrb    rTmp1, [rPRhs]
        eor     rDiff, rTmp0, rTmp1
        orr     rAcc, rAcc, rDiff                      /* acc |= (a[i] ^ b[i]) */
        ldrb    rTmp0, [rPLhs], #1                     /* Load with increment */
        ldrb    rTmp1, [rPRhs], #1
        eor     rDiff, rTmp0, rTmp1
        bic     rInvAcc, rInvAcc, rDiff                /* accInv &= ~(a[i] ^ b[i]) */
        subs    rLength, #1
        bne     mcuxCsslMemory_Compare_byte_loop

mcuxCsslMemory_Compare_end:
        MCUX_CSSL_SC_ASM_ADD    rSc, rLength            /* Record(rLength) to DI (should be zero at this point) */
        MCUX_CSSL_SC_ASM_ADD    rSc, rWordLoopCtr       /* Record(wordLoopCtr) to DI (should be zero at this point) */
        MCUX_CSSL_SC_ASM_SUB    rSc, rPLhs              /* Expunge(rPLhs) (should be start + length now) */
        MCUX_CSSL_SC_ASM_SUB    rSc, rPRhs              /* Expunge(rPLhs) (should be start + length now) */
        ldr    rStatus, =FA                            /* Prepare FA into return status */

        /* acc == 0 check */
        MCUX_CSSL_MEMORY_ASM_SEQZ  rTmp2, rAcc, rTmp0   /* rTmp2 is 1 iff acc == 0 */
        ldr     rTmp0, =EQ_MIN_NOT_EQ                  /* Load (EQ - NOT_EQ) */
        ldr     rTmp1, =NOT_EQ_MIN_FA                  /* Load (NOT_EQ - FA) */
        mul     rTmp2, rTmp2, rTmp0
        add     rTmp2, rTmp2, rTmp1

        /* acc == ~invAcc check */
        mvn     rAccXnorInvAcc, rInvAcc
        eor     rAccXnorInvAcc, rAccXnorInvAcc, rAcc
        MCUX_CSSL_SC_ASM_ADD    rSc, rAccXnorInvAcc     /* Record(acc ^ ~invAcc) (should be 0) */
        MCUX_CSSL_MEMORY_ASM_SEQZ  rTmp1, rAccXnorInvAcc, rTmp0 /* rTmp1 is 1 iff acc == ~invAcc */
        ldr     rTmp0, =EQ_MIN_NOT_EQ                  /* Reload again (EQ - NOT_EQ) */
        mul     rTmp2, rTmp2, rTmp1
        add     rStatus, rStatus, rTmp2

        MCUX_CSSL_SC_ASM_ADD    rSc, rStatus            /* Record(status) */
        MCUX_CSSL_FP_ASM_FUNCTION_EXIT rSc, rTmp0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Compare_arm_asm
        mov     rToken, rSc
        pop     {r4-r11, pc}

#ifdef __IASMARM__
        END
#endif
