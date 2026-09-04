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
 * @file  mcuxCsslMemory_Internal_Copy_arm_asm.S
 */


#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h>
#include <mcuxCsslDataIntegrity_AssemblyMacros.h>

#define rPTgt        r0              /* pTargetX, current pointer to target buffer */
#define rPSrc        r1              /* pSourceX, current pointer to source buffer */
#define rN           r2              /* length, length of the data to be copied */
#define rSc          r3              /* SC register */
#define rT           r4              /* data, temporary register to hold loaded data */
#define rX           r5              /* X, loop condition */
#define rBulk0       r4              /* Bulk copy register 0 */
#define rBulk1       r5              /* Bulk copy register 1 */
#define rBulk2       r6              /* Bulk copy register 2 */
#define rBulk3       r7              /* Bulk copy register 3 */
#define rBulk4       r8              /* Bulk copy register 4 */
#define rBulk5       r9              /* Bulk copy register 5 */
#define rBulk6       r10             /* Bulk copy register 6 */
#define rBulk7       r11             /* Bulk copy register 7 */

#ifdef __IASMARM__
        NAME mcuxCsslMemory_Int_Copy_arm_asm
        PUBLIC mcuxCsslMemory_Int_Copy_arm_asm
        SECTION .text:CODE(2)
        THUMB
#else /* armclang */
.syntax unified
.align 2
.section .text.mcuxCsslMemory_Int_Copy_arm_asm, "ax"
.global        mcuxCsslMemory_Int_Copy_arm_asm
.type          mcuxCsslMemory_Int_Copy_arm_asm, %function
#endif

/**
 * void mcuxCsslMemory_Int_Copy_arm_asm(pTarget, pSource, length)
 * r0 = pTarget
 * r1 = pSource
 * r2 = length
 */
mcuxCsslMemory_Int_Copy_arm_asm:
  push {r3-r11, lr}

  MCUX_CSSL_FP_ASM_FUNCTION_ENTRY  rSc, rT, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_Copy_arm_asm

mcuxCsslMemory_Int_Copy_arm_asm_CheckZeroLength:
  cbz   rN, mcuxCsslMemory_Int_Copy_arm_asm_Return_Near  /* If length is zero */

  /*
   * After all iterations, pTgt/pSrc shall point to pTarget[length]/pSource[length]
   * pTgt/pSrc will be subtract from DI at the end, so we add length to DI first,
   * such that at the end we can do DI -= pTgt + pSrc = (pTarget + len) + (pSource + len)
   */
  MCUX_CSSL_DI_ASM_RECORD   rSc, rN

  /* Count unaligned byte(s) in head of pTarget[]. */
  rsb   rX, rPTgt, #0
  ands  rX, rX, #3                   /* Number of unaligned byte(s) */
  beq   mcuxCsslMemory_Int_Copy_arm_asm_Aligned

  cmp   rN, rX                      /* min(len, number of unaligned bytes) */
  it    lo
  movlo rX, rN

  /*
   * Copy unaligned byte(s) to head of pTarget[]
   * for (i = x; i > 0; i-=1)
   */
mcuxCsslMemory_Int_Copy_arm_asm_LoopHeadUnAligned:
  ldrb  rT, [rPSrc], #1             /* Increase rPSrc after ldrb by 1 (post-index) */
  strb  rT, [rPTgt], #1             /* Increase rPTgt after strb by 1 (post-index) */
  subs  rN, rN, #1                  /* Decrease remaining length */
  subs  rX, rX, #1                  /* Decrease loop iterator */
  bne   mcuxCsslMemory_Int_Copy_arm_asm_LoopHeadUnAligned

mcuxCsslMemory_Int_Copy_arm_asm_Aligned:

mcuxCsslMemory_Int_Copy_arm_asm_CheckBulk:
  /* Check if source is also 4-byte aligned */
  ands  rT, rPSrc, #3               /* Check alignment of source */
  bne   mcuxCsslMemory_Int_Copy_arm_asm_CheckRemaining  /* Skip bulk copy if source unaligned */

  cmp   rN, #32                     /* Check if we have at least 32 bytes */
  blo   mcuxCsslMemory_Int_Copy_arm_asm_24Check

mcuxCsslMemory_Int_Copy_arm_asm_Loop32Bulk:
  ldmia rPSrc!, {rBulk0-rBulk7}  /* Load 8 words, increment rPSrc */
  stmia rPTgt!, {rBulk0-rBulk7}  /* Store 8 words, increment rPTgt */
  subs  rN, rN, #32      /* Decrease remaining length by 32 bytes */
  cmp   rN, #32
  bhs   mcuxCsslMemory_Int_Copy_arm_asm_Loop32Bulk

mcuxCsslMemory_Int_Copy_arm_asm_24Check:
  cmp   rN, #24                     /* Check if we have at least 24 bytes */
  blo   mcuxCsslMemory_Int_Copy_arm_asm_16Check

mcuxCsslMemory_Int_Copy_arm_asm_Loop24Bulk:
  ldmia rPSrc!, {rBulk0-rBulk5}  /* Load 6 words, increment rPSrc */
  stmia rPTgt!, {rBulk0-rBulk5}  /* Store 6 words, increment rPTgt */
  subs  rN, rN, #24      /* Decrease remaining length by 24 bytes */

mcuxCsslMemory_Int_Copy_arm_asm_Return_Near:
  cbz   rN, mcuxCsslMemory_Int_Copy_arm_asm_Return

mcuxCsslMemory_Int_Copy_arm_asm_16Check:
  cmp   rN, #16                     /* Check if we have at least 16 bytes */
  blo   mcuxCsslMemory_Int_Copy_arm_asm_CheckRemaining

mcuxCsslMemory_Int_Copy_arm_asm_Loop16Bulk:
  ldmia rPSrc!, {rBulk0-rBulk3}  /* Load 4 words, increment rPSrc */
  stmia rPTgt!, {rBulk0-rBulk3}  /* Store 4 words, increment rPTgt */
  subs  rN, rN, #16      /* Decrease remaining length by 16 bytes */

mcuxCsslMemory_Int_Copy_arm_asm_CheckRemaining:
  cmp   rN, #4
  blo   mcuxCsslMemory_Int_Copy_arm_asm_CheckEnd

  /*
   * Copy word(s). pTarget[] is written aligned, but pSource[] might be read unaligned.
   * for (i = n; i >= 4; i-=4)
   */
mcuxCsslMemory_Int_Copy_arm_asm_LoopAligned:
  ldr   rT, [rPSrc],  #4             /* load and then increase rPSrc by 4 */
  str   rT, [rPTgt],  #4             /* store and then increase rPSrc by 4 */
  subs  rN, rN, #4                   /* decrease remaining length */
  cmp   rN, #4
  bhs   mcuxCsslMemory_Int_Copy_arm_asm_LoopAligned

mcuxCsslMemory_Int_Copy_arm_asm_CheckEnd:
  cbz   rN, mcuxCsslMemory_Int_Copy_arm_asm_Return

  /*
   * Copy remaining unaligned byte(s) to tail of pTarget[].
   * for (i = n; i > 0; i-=1)
   */
mcuxCsslMemory_Int_Copy_arm_asm_LoopTailUnaligned:
  ldrb  rT, [rPSrc], #1
  strb  rT, [rPTgt], #1
  subs  rN, rN, #1   /* Decrease remaining length  */
  bne   mcuxCsslMemory_Int_Copy_arm_asm_LoopTailUnaligned

mcuxCsslMemory_Int_Copy_arm_asm_Return:
  /* DI -= (pTarget + length) + (pSource + length) */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPTgt
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPSrc
  MCUX_CSSL_FP_ASM_FUNCTION_EXIT  rSc, rT, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_Copy_arm_asm

  /* Return to caller with DI -= (pSource + pTarget + length) */
  mov  r1, rSc
  pop {r3-r11, pc}

#ifdef __IASMARM__
        END
#endif
