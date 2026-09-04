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
 * @file  mcuxCsslMemory_Internal_SecureXORRev_arm_asm.S
 */

#include <internal/mcuxCsslPrng_AssemblyMacros.h>
#include <mcuxCsslMemory_AssemblyHeader.h>
#include <mcuxCsslDataIntegrity_AssemblyMacros.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h>
#include <mcuxCsslDataIntegrity_AssemblyMacros.h>

#define rPTgt           r0    /* pTarget,  current pointer to target buffer */
#define rPSrc           r8    /* pSource1, current pointer to source1 buffer */
#define rPSrc2          r9    /* pSource2, current pointer to source2 buffer */
#define rI              r3    /* loop index */

#define rT0             r1
#define rT1             r2
#define rT2             r4
#define rEL             r5    /* last e of current cyclic subgroup */
#define rOftX           r6    /* offsetX (current offset) = 0 or offset */
#define rN              r7    /* number of blocks (byte or word) */

#define rE              r10   /* current position */
#define rS              r11   /* step size */
#define rSc             r12   /* base address of hardware SFR */

/* Stack variables */
#define oHLenSPOffset         0     /* offset on the stack for the half length */
#define oOftSpOffset          4     /* offset on the stack for the offset of 2nd half of blocks */
#define oLenFpSpOffset        8     /* offset on the stack for the length for FP usecase */
#define TOTAL_SP_OFFSET_SIZE  12    /* total stack buffers size */

/* FP defines */
#define SECXOR_FP_ZERO_LENGTH_BRANCH              0x7F80
#define SECXOR_FP_INCOMPLETE_WORD_LENGTH_BRANCH   0x647C
#define SECXOR_FP_WORD_OR_MORE_LENGTH_BRANCH      0x529B
#define SECXOR_FP_BYTE_LOOP_ITERATION             0x33CC
#define SECXOR_FP_WORD_LOOP_ITERATION             0x478B


#ifdef __IASMARM__
    NAME mcuxCsslMemory_Int_SecXORRev
    SECTION .text:CODE(2)
    PUBLIC  mcuxCsslMemory_Int_SecXORRev
#else
.syntax unified
.align 2
.section .text.mcuxCsslMemory_Int_SecXORRev, "ax"
.global        mcuxCsslMemory_Int_SecXORRev
.type          mcuxCsslMemory_Int_SecXORRev, %function
#endif


  /**
  * void mcuxCsslMemory_Int_SecXORRev(pTarget, pSource, pSource2, length)
  * Initial register layout (will be modifled to free up some lower regs)
  * r0 = pTarget  (rPTgt)
  * r1 = pSource  (will be moved to rPSrc)
  * r2 = pSource2 (will be moved to rPSrc2)
  * r3 = length   (rI)
  */
mcuxCsslMemory_Int_SecXORRev:
  push {r4-r11}
  /* Allocate space for local variables */
  sub sp, sp, #TOTAL_SP_OFFSET_SIZE

  /* Some registers have to be moved to upper locations
  *  to make room for temporary registers used in conditional instruction blocks (it)
  *  where only lower register ranges are allowed (r0-r7) */
  mov rPSrc, r1
  mov rPSrc2, r2
  MCUX_CSSL_FP_ASM_FUNCTION_ENTRY  rSc, rT0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXORRev_asm
  /* Save length for FP calculations at an exit point */
  str rI, [sp, #oLenFpSpOffset]

  mov rT0, #SECXOR_FP_ZERO_LENGTH_BRANCH
  MCUX_CSSL_SC_ASM_ADD rSc, rT0

  /* Do nothing but only update DI when length=0. */
  cmp rI, #0
  beq .mcuxCsslMemory_Int_SecXORRev_Return

  /* Get PRNG SFR address. */
  MCUXCSSLPRNG_INIT_ADDR rT0

  /* Fetch random numbers for e and s. */
  MCUXCSSLPRNG_GET_PRNG rT0, rE
  lsr rS, rE, #16   // randomm >> 16
  uxth rE, rE       // random & 0xFFFF

  cmp rI, #4
  blo .mcuxCsslMemory_Int_SecXORRev_Byte

.mcuxCsslMemory_Int_SecXORRev_Word:
  mov rT0, #SECXOR_FP_WORD_OR_MORE_LENGTH_BRANCH
  sub rT0, rT0, #SECXOR_FP_ZERO_LENGTH_BRANCH
  MCUX_CSSL_SC_ASM_ADD rSc, rT0

  /* Calculate initial position (e), step (s), number of blocks (n), */
  /* and offset in 2nd half of buffer.                               */
  lsr rT1, rI, #1           /* hLen = len / 2 */

  str rT1, [sp, #oHLenSPOffset]
  add  rN, rI, #3
  bic rN, rN, #3              // 4n = (len+3) & 0xFFFFFFFC

  sub  rOftX, rI, rN         // offset = len - 4n, in {-3,-2,-1,0}
  str rOftX, [sp, #oOftSpOffset] // store offset on the stack

  add   rPTgt,rPTgt,rI        // **REV**

  lsr  rI, rN, #2             // loop iteration, n = (len+3)/4
  sub  rT0, rI, #1            // n - 1

  mul rE, rI, rE              // e in [0, n-1], e = ((n) * (random & 0xFFFF) >> 16)
  lsr rE, rE, #16
  lsl rE, rE, #2              // 4e

  mul rS, rT0, rS             // s in [1, n-1] if n > 1; s = 1 if n = 1, s = 1 + ((n-1) * (random & 0xFFFF) >> 16)
  lsr rS, #16
  add rS, rS, #1
  lsl rS, rS, #2              // 4s

  /* DI += (4e - 4) */
  sub   rT0, rE, #4           /* 4e - 4 */
  MCUX_CSSL_DI_ASM_RECORD rSc, rT0

  /* eL (last e in current cyclic group) = (e < s) ? (e-s+n) : (e-s). */
  /* CAUTION: if len=4, then e=0, s=1, eL = 0. */
  subs  rEL, rE, rS
  it lo
  addlo rEL, rEL, rN

  /* offsetX (offset for current e) = (len/2 < 4e) ? offset : 0. */
  cmp rT1, rE         // hLen, rE
  it hs
  movhs rOftX, #0

  mov    rT0, #0                    // 4diff (current difference)

  /* Calculate total offset, according to e, offsetX and the current difference. */
  add rT2, rT0, rOftX     // 4diff + offsetX
  add rT2, rE, rT2        // 4e + 4diff + offsetX

  add rPSrc, rPSrc, rT2
  add rPSrc2, rPSrc2, rT2
  sub rPTgt, rPTgt, #4
  sub rPTgt, rPTgt, rT2

  mov    rT2, #0    // inititalize rCyc

  /* for (i = n; i > 0; i--) */
.mcuxCsslMemory_Int_SecXORRev_WordLoop:
  mov rT0, #SECXOR_FP_WORD_LOOP_ITERATION
  MCUX_CSSL_SC_ASM_ADD rSc, rT0

  ldr rT0, [rPSrc]
  ldr rT1, [rPSrc2]
  eor rT1, rT0, rT1        // rT1 = rT0 ^ rT1
  rev rT1, rT1

  /* Check if reach the last element of the current cyclic group. */
  subs  rT0, rE, rEL
  mov rT0, #0
  it eq
  moveq rT0, #4               // 4s'
  add rT2, rT2, rT0

  str rT1, [rPTgt]

  /* Update the last element eL = (eL+s') mod n = eL or (eL+1) or 0. */
  /* CAUTION: if len=4, then eL=0, s'=1, n=1, and new eL = 0. */
  add rEL, rEL, rT0     // 4(eL + s')
  cmp rEL, rN
  it hs
  movhs rEL, #0           // 4(eL+s') or 0

  /* diff = (new e) - (old e) = ((e+s+s') mod n) - e = s+s' or s+s'-n. */
  /* CAUTION: if len=4, then e=0, s=1, s'=1, n=1, and diff = 1 and (new e) = 1. */
  add   rT0, rT0, rS          // 4s' + 4s
  add   rT1, rE, rT0          // 4e+4s+4s'
  cmp rT1, rN
  it hs
  subhs  rT0, rT0, rN         // 4diff

  add   rE, rE, rT0           // new 4e
  sub   rT1, rT0, rOftX       // 4diff -= (old offsetX)

  /* offsetX (offset for current e) = (len/2 < 4e) ? offset : 0. */
  ldr rT0, [sp, #oHLenSPOffset]
  cmp rT0, rE
  ite lo
  ldrlo rOftX, [sp, #oOftSpOffset]
  movhs rOftX, #0

  sub rI, rI, #1
  add rT0, rT1, rOftX         // 4diff += (new offsetX)

  add rPSrc, rPSrc, rT0
  add rPSrc2, rPSrc2, rT0
  sub rPTgt, rPTgt, rT0

.mcuxCsslMemory_Int_SecXORRev_WordLoopCond:
  cmp rI, #0
  bne .mcuxCsslMemory_Int_SecXORRev_WordLoop

  /* After all iterations of WordLoop, pTgt and pSrc/pSrc2 shall point to     */
  /* pTarget[(len-4) - 4e - offsetX] and pSource/pSource2[4e + offsetX]       */
  /* where e = (initial e) + cyc. */

  /* Calculate the difference between 4(initial e) and 4e + offsetX. */
  /* e = (initial e) + cyc - n, if e < cyc; or = (initial e) + cyc, otherwise. */
  /* So, (initial e) - e = n - cyc, if e < cyc; or = -cyc, otherwise.          */
  sub rT0, rN, rT2     // 4n - 4cyc
  cmp rE, rT2          // (e < cyc) ? 1 : 0 (on 1 add N)
  it hs
  subhs rT0, rT0, rN    // 4n - 4cyc or -4cyc
  sub rT0, rT0, rOftX   // 4n - 4cyc - offsetX or -4cyc - offsetX

  /* DI -= ((pTarget + (len-4) - 4*(initial e)) + (pSource + 4*(initial e)) + (pSource2 + 4*(initial e))). */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rT0 // 12 * (initial e)

  b .mcuxCsslMemory_Int_SecXORRev_Return

.mcuxCsslMemory_Int_SecXORRev_Byte:
  mov rT0, #SECXOR_FP_INCOMPLETE_WORD_LENGTH_BRANCH
  sub rT0, rT0, #SECXOR_FP_ZERO_LENGTH_BRANCH
  MCUX_CSSL_SC_ASM_ADD rSc, rT0

  /* Calculate initial position (e) and step (s). */
  mov    rN, rI               // n = len
  subs   rT0, rI, #1          // n-1 (= len-1)

  uxth rE, rE                 // e in [0, n-1], 4e = ( ((n) * (random & 0xFFFF) >> 16) ) >> 2
  mul rE, rI, rE
  lsr rE, rE, #16

  uxth rS, rS                 // s in [1, n-1] if n > 1; s = 1 if n = 1, s = 1 + ((n-1) * (random & 0xFFFF) >> 16)
  mul rS, rT0, rS
  lsr rS, #16
  add rS, rS, #1

  /* DI += (e - 1). */
  sub rT1, rE, #1
  MCUX_CSSL_DI_ASM_RECORD rSc, rT1

  /* Calculate initial pointers, according to e. */
  add rPSrc, rPSrc, rE
  add rPSrc2, rPSrc2, rE
  add rPTgt, rPTgt, rT0
  sub rPTgt, rPTgt, rE

  /* for (i = n; i > 0; i--) */
.mcuxCsslMemory_Int_SecXORRev_ByteLoop:
  mov rT0, #SECXOR_FP_BYTE_LOOP_ITERATION
  MCUX_CSSL_SC_ASM_ADD rSc, rT0

  ldrb  rT0, [rPSrc]
  ldrb  rT1, [rPSrc2]
  eor   rT1, rT1, rT0         // rT1 = rT1 ^ rT0
  strb  rT1, [rPTgt]

  /* diff = (new e) - (old e) = ((e+s) mod n) - e = s or s-n. */
  /* CAUTION: if len=1, then e=0, s=1, and diff = 0. */
  add rT0, rE, rS         // e + s
  cmp rT0, rN
  mov rT0, rS             // s
  it hs
  subhs rT0, rT0, rN      // diff (s or s-n)

  add rPSrc, rPSrc, rT0
  add rPSrc2, rPSrc2, rT0
  sub rPTgt, rPTgt, rT0

  sub  rI, rI, #1
  add rE, rE, rT0         // new e

.mcuxCsslMemory_Int_SecXORRev_ByteLoopCond:
  cmp rI, #0
  bne .mcuxCsslMemory_Int_SecXORRev_ByteLoop

  /* After all iterations of ByteLoop, pTgt, pSrc and pSrc2 shall point to */
  /* original pTarget[(len-1)-e], pSource[e] and pSource2[e] before ByteLoop.      */

.mcuxCsslMemory_Int_SecXORRev_Return:
  /* DI -= ((pTarget + (len-1) - e) + (pSource + e) + (pSource2 + e)). */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPTgt
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPSrc
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPSrc2

  b .mcuxCsslMemory_Int_SecXORRev_FP_Calculate_Expectations
.mcuxCsslMemory_Int_SecXORRev_FP_Subtract_Expectations:
  MCUX_CSSL_SC_ASM_SUB rSc, rT2

  MCUX_CSSL_FP_ASM_FUNCTION_EXIT rSc, rT0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecXORRev_asm
  /* ARM calling convention to return flow-protected (64-bit) return value: */
  /* FP token is MSW, if flow protection is enabled, goes into r1.          */
  mov r1, rSc
  mov r0, #0

  /* Return to caller with DI -= (pSource + pSource2 + pTarget + length). */
  add sp, sp, #TOTAL_SP_OFFSET_SIZE
  pop {r4-r11}
  bx lr

.mcuxCsslMemory_Int_SecXORRev_FP_Calculate_Expectations:
  ldr rT0, [sp, #oLenFpSpOffset]

  /* Zero length branch expectations */
  cmp rT0, #0
  itt eq
  moveq rT2, #SECXOR_FP_ZERO_LENGTH_BRANCH
  beq .mcuxCsslMemory_Int_SecXORRev_FP_Subtract_Expectations

  /* 1-3 bytes length branch expectations */
  cmp rT0, #4
  bhs .mcuxCsslMemory_Int_SecXORRev_FP_Calculate_Expectations_WordLoop
  mov rT2, #SECXOR_FP_INCOMPLETE_WORD_LENGTH_BRANCH
  mov rT1, #SECXOR_FP_BYTE_LOOP_ITERATION
  mla rT2, rT0, rT1, rT2      // fp_branch + n * fp_loop
  b .mcuxCsslMemory_Int_SecXORRev_FP_Subtract_Expectations

.mcuxCsslMemory_Int_SecXORRev_FP_Calculate_Expectations_WordLoop:
  mov rT2, #SECXOR_FP_WORD_OR_MORE_LENGTH_BRANCH
  mov rT1, #SECXOR_FP_WORD_LOOP_ITERATION
  add rT0, rT0, #3            // bytes rounded up to word sizes
  lsr rT0, rT0, #2            // iterations
  mla rT2, rT0, rT1, rT2      // fp_branch + n * fp_loop
  b .mcuxCsslMemory_Int_SecXORRev_FP_Subtract_Expectations

#ifdef __IASMARM__
    END
#else
.mcuxCsslMemory_Int_SecXORRev_End:
.size mcuxCsslMemory_Int_SecXORRev, . - mcuxCsslMemory_Int_SecXORRev
#endif
