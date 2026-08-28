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
 * @file  mcuxCsslMemory_Internal_SecureCompare_arm_asm.S
 */

#include <mcuxCsslMemory_AssemblyHeader.h>
#include <internal/mcuxCsslPrng_AssemblyMacros.h>
#include <internal/mcuxCsslMemory_Internal_AssemblyMacros.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h>
#include <mcuxCsslDataIntegrity_AssemblyMacros.h>


#define rPlhs r0              /* pLhs, current pointer to left-hand side buffer */
#define rPrhs r1              /* pRhs, current pointer to right-hand side buffer */
#define rI    r2              /* loop index */
#define rT    r3
#define rE    r4              /* current position */
#define rS    r5              /* step size */
#define rOftX r6              /* offsetX (current offset) = 0 or offset */
#define rN    r7              /* number of blocks (byte or word) */
#define rT0   r8
#define rT1   r9
#define rEL   r10             /* last e of current cyclic subgroup */
#define rOft  r11             /* offset for 2nd half of blocks */
#define rSc   r12             /* Secure Counter */
#define rCyc  lr              /* Use lr for cyclic subgroup */

#define rHLenSPOffset 0       /* half length offset on stack */
#define rAcc1SPOffset 4       /* acc1 offset on stack */
#define rAcc2SPOffset 8      /* acc2 offset on stack */
#define rTempOnStack  12      /* Temp variable on stack */

#ifdef __IASMARM__
        NAME mcuxCsslMemory_Int_SecComp_arm_asm
        PUBLIC mcuxCsslMemory_Int_SecComp_arm_asm
        SECTION .text:CODE(2)
        THUMB
#else /* armclang */
.syntax unified
.align 2
.section .text.mcuxCsslMemory_Int_SecComp_arm_asm, "ax"
.global        mcuxCsslMemory_Int_SecComp_arm_asm
.type          mcuxCsslMemory_Int_SecComp_arm_asm, %function
.thumb
#endif


/*
 * mcuxCsslMemory_Status_t mcuxCsslMemory_Int_SecComp_arm_asm(uint8_t * pLhs, const uint8_t * pRhs, uint32_t length);
 * r0 = pLhs    (rPLhs)
 * r1 = pRhs    (rPRhs)
 * r2 = length  (rI)
 */
mcuxCsslMemory_Int_SecComp_arm_asm:
  push {r4-r11, lr}              /* Save registers on the stack */

  MCUX_CSSL_FP_ASM_FUNCTION_ENTRY  rSc, rT0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecComp_arm_asm

  /*
   * Reserve stack for:
   *   rHLen - half length = length / 2
   *   rAcc1 - acc1, accumulated diff
   *   rAcc2 - acc2, accumulated diff
   *   rTempOnStack - temp variable on stack
   */
  sub      sp,     sp, #16

  /* Initialize rAcc1 and rAcc2 */
  mov    rT0, #0                    /* Initialize rAcc1 to 0 */
  str    rT0, [sp, #rAcc1SPOffset]
  mov    rT0, #0xFFFFFFFF           /* Initialize rAcc2 to 0xFFFFFFFF */
  str    rT0, [sp, #rAcc2SPOffset]
mcuxCsslMemory_Int_SecComp_arm_asm_CheckZeroLength:
  cmp      r2,     #0
  beq      mcuxCsslMemory_Int_SecComp_arm_asm_Check_Equal

  /* Fetch random numbers for e and s. */
  MCUXCSSLPRNG_INIT_ADDR  rT0           /* Load PRNG SFR address. */
  MCUXCSSLPRNG_GET_PRNG   rT0, rE       /* rE = random number */
  MCUXCSSLPRNG_GET_PRNG   rT0, rS       /* rS = random number */

mcuxCsslMemory_Int_SecComp_arm_asm_CheckLength:
  cmp      rI,     #4
  blo      mcuxCsslMemory_Int_SecComp_arm_asm_Byte

mcuxCsslMemory_Int_SecComp_arm_asm_Word:
  /* Calculate initial position (e), step (s), number of blocks (n), and offset in 2nd half of buffer. */
  lsrs     rT0,    rI, #1                /* rHLen = length / 2 */
  str      rT0,    [sp, #rHLenSPOffset]

  /* Check the length is power of 2, if power of 2 rT1 = 0 at the end */
  mov      rT1,    rI
  sub      rT1,    rT1, #1
  and      rT1,    rT1, rI

  /* Prepare rI (n) =  (len+3)/4 */
  add      rN,     rI, #3
  and      rN,     rN, #0xFFFFFFFC       /* 4n = (length + 3) & 0xFFFFFFFC */
  sub      rOft,   rI, rN                /* Offset = len - 4n, in {-3,-2,-1,0} */
  lsr      rI,     rN, #2                /* Loop iteration, n = (len+3)/4 */
  /* Jump if not power of 2 */
  cmp      rT1,    #0
  bne      mcuxCsslMemory_Int_SecComp_arm_asm_LengthNotPowerOfTwo

mcuxCsslMemory_Int_SecComp_arm_asm_LengthIsPowerOfTwo:
  sub      rT0,    rI, #1                /* n - 1 */
  and      rE,     rE, rT0               /* e = GetLqRngWord() & (n-1) -> e in [0..n-1] */
  and      rS,     rS, rT0               /* s = GetLqRngWord() & (n-1) */
  orr      rS,     rS, #1                /* s = 1 | s -> s in [1..n-1]  */

  subs     rT,     rI, #1
  adc      rT,     rT, #0                /* Avoid calculating "mod 0" (when len = 4) */
  b        mcuxCsslMemory_Int_SecComp_arm_asm_LengthNotPowerOfTwo_End

mcuxCsslMemory_Int_SecComp_arm_asm_LengthNotPowerOfTwo:
  /* e =  (n * (random & 0xFFFF)) >> 16 ==>  in [0..1] */
  ldr      rT0,    =0xFFFF
  and      rE,     rT0, rE               /* rE = (random & 0xFFFF) */
  mul      rE,     rE, rI                /* rE = (n * (random & 0xFFFF)) */
  lsr      rE,     #16                   /* rE = rE >> 16 */
  /* s = 1 + (((n-1) * (random >> 16)) >> 16) ==> in [1, n-1]  */
  lsr      rS,     rS, #16               /* rS = (random >> 16) */
  sub      rT,     rI, #1                /* rT = n - 1 */
  mul      rS,     rT, rS                /* rS = (n - 1) * (random >> 16) */
  lsr      rS,     rS, #16               /* rS = rS >> 16 */
  add      rS,     rS, #1                /* rS = 1 + rS */

mcuxCsslMemory_Int_SecComp_arm_asm_LengthNotPowerOfTwo_End:
  lsl      rE,     rE, #2                /* rE = random number * 4 */
  lsl      rS,     rS, #2                /* rS = random number * 4 */
  /*
   * DI -= (length - 8(initial e)).
   * (pLhs + 4(initial e)) and (pRhs + 4(initial e)) will be EXPUNGE after the loop
   */
  add      rT,     rOft, rN              /* length */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rT
  MCUX_CSSL_DI_ASM_RECORD  rSc, rE
  MCUX_CSSL_DI_ASM_RECORD  rSc, rE

  /*
   * eL (last e in current cyclic subgroup) = (e < s) ? (e-s+n) : (e-s).
   * CAUTION: if len=4, then e=0, s=1, eL = 0.
   */
  subs     rEL,    rE, rS                /* rEL = rE - rS, and set flags */
  it       lo
  addlo    rEL,    rEL, rN               /* If rE < rS (unsigned), rEL += rN */

  /* offsetX (offset for current e) = (len/2 < 4e) ? offset : 0. */
  ldr      rT0,    [sp, #rHLenSPOffset]
  cmp      rT0,    rE
  ite      lo
  movlo    rOftX,  rOft
  movhs    rOftX,  #0


  mov      rCyc, #0

  /* Calculate initial pointers, according to e and offsetX. */
  add      rT,     rE, rOftX             /* 4e + offsetX */
  add      rPlhs,  rPlhs, rT             /* rPlhs -> pLhs[4e+offsetX] */
  add      rPrhs,  rPrhs, rT             /* rPrhs -> pRhs[4e+offsetX] */

  /* for (i = n; i > 0; i--) */
mcuxCsslMemory_Int_SecComp_arm_asm_WordLoop:

  /* Fetch an odd random number r in rT. */
  MCUXCSSLPRNG_INIT_ADDR    rT0         /* Load PRNG address */
  MCUXCSSLPRNG_GET_PRNG     rT0, rT     /* rT = random number */
  orr                      rT, rT, #1  /* r is odd */

  /* Load and blind left-/right-hand side. */
  ldr    rT0, [rPlhs]         /* load left-hand side */
  ldr    rT1, [rPrhs]         /* load right-hand side */
  add    rT0, rT0, rT
  add    rT1, rT1, rT
  mul    rT0, rT0, rT
  mul    rT1, rT1, rT

  /* Accumuluate difference. */
  eor    rT, rT0, rT1                /* diff = rA ^ rB */
  str    rT0, [sp, #rTempOnStack]    /* Save rT0 on stack */
  ldr    rT0, [sp, #rAcc1SPOffset]   /* Load rAcc1 from stack */
  orr    rT0, rT0, rT                /* rAcc1 = rAcc1 ^ rT */
  str    rT0, [sp, #rAcc1SPOffset]   /* Store rAcc1 on stack */
  ldr    rT0, [sp, #rTempOnStack]    /* Load saved value of rT0 from stack */
  eor    rT, rT0, rT1                /* diff = rA ^ (~rB) */
  mvn    rT, rT
  ldr    rT0, [sp, #rAcc2SPOffset]   /* Load rAcc2 from stack */
  and    rT0, rT0, rT
  str    rT0, [sp, #rAcc2SPOffset]   /* Store rAcc2 on stack */
  ldr    rT0, [sp, #rTempOnStack]    /* Load saved value of rT0 from stack */
  /* Check if reach the last element of the current cyclic group. */
  cmp      rE,     rEL
  ite      eq
  moveq    rT0,    #4
  movne    rT0,    #0

  add      rCyc,   rCyc, rT0


  /*
   * Update the last element eL = (eL+s') mod n = eL or (eL+1) or 0.
   * CAUTION: if len=4, then eL=0, s'=1, n=1, and new eL = 0.
   */
  adds     rEL,    rEL, rT0              /* rEL += sp4, set flags */
  cmp      rEL,    rN                    /* Compare rEL to n */
  it       hs                            /* If rEL >= n (unsigned), execute next */
  movhs    rEL,    #0                    /* Reset rEL to 0 if out of bounds */


  /*
   * diff = (new e) - (old e) = ((e+s+s') mod n) - e = s+s' or s+s'-n.
   * CAUTION: if len=4, then e=0, s=1, s'=1, n=1, and diff = 1 and (new e) = 1.
   */
  add      rT0,    rT0, rS               /* 4s' + 4s */
  add      rT,     rE, rT0               /* 4e + 4s + 4s' */
  cmp      rT,     rN                    /* (4(e+s+s') < 4n) ? 1 : 0 */
  ite      lo
  movlo    rT,     #1                    /* If (4(e+s+s') < 4n), set rT to 1 */
  movhs    rT,     #0                    /* If (4(e+s+s') >= 4n), set rT to 0 */
  sub      rT,     rT, #1                /* 0 or -1 (0xFFFFFFFF) */
  and      rT,     rT, rN                /* 0 or 4n */
  sub      rT,     rT0, rT               /* 4diff */
  add      rE,     rE, rT                /* new 4e */
  sub      rT,     rT, rOftX             /* 4diff -= (old offsetX) */

  /* offsetX = (Len/2 < 4e) ? offset : 0. */
  ldr      rT0,    [sp, #rHLenSPOffset]  /* load rHLen from stack into rT0 */
  cmp      rE,     rT0                   /* check if 4e > Len/2 */
  ite      hi                            /* if 4e > Len/2, then... */
  movhi    rOftX,  rOft                  /* rOftX = offset */
  movls    rOftX,  #0                    /* else: rOftX = 0 */
  subs     rI,     rI, #1                /* i-- */
  adds     rT,     rT, rOftX             /* rT = 4diff += new offsetX */
  add      rPrhs,  rPrhs, rT             /* pRhs[(new 4e) + (new offsetX)] */
  add      rPlhs,  rPlhs, rT             /* pLhs[(new 4e) + (new offsetX)] */

mcuxCsslMemory_Int_SecComp_arm_asm_WordLoopCond:
  cmp      rI,     #0
  bne      mcuxCsslMemory_Int_SecComp_arm_asm_WordLoop

  /*
   * After all iterations of WordLoop, rPlhs/rPrhs shall point to
   * pLhs[4e + offsetX] / pRhs[4e + offsetX],
   * where e = (initial e) + cyc mod n.
   */
  /*
   * Calculate the difference between 4(initial e) and 4e + offsetX.
   * e = (initial e) + cyc - n, if e < cyc; or = (initial e) + cyc, otherwise.
   * So, (initial e) - e = n - cyc, if e < cyc; or = -cyc, otherwise.
   */
  cmp      rE,     rCyc                   /* (e < cyc) ? 1 : 0 */
  ite      lo
  movlo    rT,     rN                    /* If (e < cyc), set rT to N */
  movhs    rT,     #0                    /* If (e < cyc), set rT to 0 */
  sub      rT,     rT, rCyc              /* 4n-4cyc or -4cyc */
  sub      rT,     rT, rOftX             /* 4n-4cyc - offsetX or -4cyc - offsetX */

  add      rPlhs,  rPlhs, rT             /* -> pLhs[4*(initial e)] */
  add      rPrhs,  rPrhs, rT             /* -> pRhs[4*(initial e)] */


mcuxCsslMemory_Int_SecComp_arm_asm_Check_Equal:
  /* DI -= ((pLhs + 4*(initial e)) + (pRhs + 4*(initial e))), for length >= 4 (WordLoop case). */
  /* DI -= ((pLhs + e) + (pRhs + e)), for length < 4 (ByteLoop case). */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPlhs
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPrhs

  /*
   * Calculate return value
   * ret1 = ((((acc1 == 0)?1:0) * (EQ - NOT_EQ)) + (NOT_EQ - FA)) = (EQ - FA) or (NOT_EQ - FA)
   * ret = FA + (((acc1 == ~acc2)?1:0) * ret1)
   */
  ldr    r0, =MCUXCSSLMEMORY_STATUS_ASM_FAULT   /* Default return */
  ldr    rT0, [sp, #rAcc1SPOffset]             /* Load rAcc1 from stack */
  cmp    rT0, #0                               /* (acc1 == 0 ? 1 : 0) */
  ite    eq
  moveq  rT, #1
  movne  rT, #0
  ldr    rT0, =(MCUXCSSLMEMORY_STATUS_ASM_EQUAL - MCUXCSSLMEMORY_STATUS_ASM_NOT_EQUAL)
  ldr    rT1, =(MCUXCSSLMEMORY_STATUS_ASM_NOT_EQUAL - MCUXCSSLMEMORY_STATUS_ASM_FAULT)
  mul    rT, rT, rT0                           /* (EQ - NOT_EQ) or 0 */
  add    rT, rT, rT1                           /* (EQ - FA) or (NOT_EQ - FA) */

  ldr    rT0, [sp, #rAcc1SPOffset]   /* Load rAcc1 from stack */
  ldr    rT1, [sp, #rAcc2SPOffset]   /* Load rAcc2 from stack */
  eor    rT1, rT0, rT1
  mvn    rT1, rT1
  cmp    rT1, #0                               /* (acc1 == ~acc2 ? 1 : 0) */
  ite    eq
  moveq  rT0, #1
  movne  rT0, #0
  mul    rT0, rT0, rT
  add    r0, r0, rT0

  MCUX_CSSL_SC_ASM_ADD    rSc, r0         /* Record(status) */

mcuxCsslMemory_Int_SecComp_arm_asm_Return:
  add      sp,     sp, #16               /* Restore stack pointer */
  MCUX_CSSL_FP_ASM_FUNCTION_EXIT  rSc, rT0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecComp_arm_asm
  mov      r1,     rSc                   /* Return SC in r1 */
  pop      {r4-r11, pc}                  /* Restore registers from the stack */

mcuxCsslMemory_Int_SecComp_arm_asm_Byte:
  /* Calculate initial position (e) and step (s). */
  mov      rN,     rI                    /* rN = length */
  subs     rT1,    rI, #1                /* rN-1 = length-1 */
  clz      rT,     rT1
  lsr      rT,     #5
  add      rT,     rT, rT1               /* Avoid calculating "mod 0" (when len=1) */
  udiv     rT0,    rE, rI                /* e in [0, n-1] */
  mls      rE,     rT0, rI, rE           /* rE = rE % rI */
  udiv     rT0,    rS, rT
  mls      rS,     rT0, rT, rS           /* rS = rS % rT */
  add      rS,     rS, #1                /* s in [1, n-1] if n > 1; s = 1 if n = 1 */

  /*
   * DI -= (length - 2e).
   * (pLhs + e) and (pRhs + e) will be EXPUNGE after the loop.
   */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rI
  MCUX_CSSL_DI_ASM_RECORD  rSc, rE
  MCUX_CSSL_DI_ASM_RECORD  rSc, rE

  /* Calculate initial pointers, according to e. */
  add   rPlhs, rPlhs, rE      /* rPlhs -> pLhs[e] */
  add   rPrhs, rPrhs, rE      /* rPrhs -> pRhs[e] */

  /* for (i = n; i > 0; i--) */
mcuxCsslMemory_Int_SecComp_arm_asm_ByteLoop:
  /* Fetch an odd random number r. */
  MCUXCSSLPRNG_INIT_ADDR     rT0        /* Load PRNG address */
  MCUXCSSLPRNG_GET_PRNG      rT0, rT    /* rT = random number */
  orr    rT, r0, #1                    /* r is odd */

  /* Load and blind left-/right-hand side. */
  ldrb   rT0, [rPlhs]         /* load left-hand side */
  ldrb   rT1, [rPrhs]         /* load right-hand side */
  add    rT0, rT0, rT
  add    rT1, rT1, rT
  mul    rT0, rT0, rT
  mul    rT1, rT1, rT

  /* Accumuluate difference. */
  eor    rT, rT0, rT1                 /* diff = rA ^ rB */
  str    rT0, [sp, #rTempOnStack]     /* Save rT0 on stack */
  ldr    rT0, [sp, #rAcc1SPOffset]    /* Load rAcc1 from stack */
  orr    rT0, rT0, rT
  str    rT0, [sp, #rAcc1SPOffset]    /* Store rAcc1 on stack */
  ldr    rT0, [sp, #rTempOnStack]     /* Load saved value of rT0 from stack */
  eor    rT, rT0, rT1                 /* diff = rA ^ (~rB) */
  mvn    rT, rT
  ldr    rT0, [sp, #rAcc2SPOffset]    /* Load rAcc2 from stack */
  and    rT0, rT0, rT
  str    rT0, [sp, #rAcc2SPOffset]    /* Store rAcc2 on stack */
  ldr    rT0, [sp, #rTempOnStack]     /* Load saved value of rT0 from stack */

  /*
   * diff = (new e) - (old e) = ((e+s) mod n) - e = s or s-n.
   * CAUTION: if len=1, then e=0, s=1, and diff = 0.
   */
  add    rT, rE, rS            /* e + s */
  cmp    rT, rN                /* ((e+s) < n) ? 1 : 0 */
  ite    lo
  movlo  rT, #1
  movhs  rT, #0

  sub    rT, rT, #1            /* 0 or -1 (0xFFFFFFFF) */
  and    rT, rT, rN            /* 0 or  n */

  sub    rT1, rS, rT           /* diff */

  sub    rI, rI, #1
  add    rE, rE, rT1           /* new e */

  adds   rPrhs, rPrhs, rT1     /* pRhs[new e] */
  adds   rPlhs, rPlhs, rT1     /* pLhs[new e] */

mcuxCsslMemory_Int_SecComp_arm_asm_ByteLoopCond:
  cmp   rI, #0
  bne   mcuxCsslMemory_Int_SecComp_arm_asm_ByteLoop

  /*
   * After all iterations of ByteLoop, rPlhs/rPrhs shall point to
   * original pLhs[e]/pRhs[e] before ByteLoop.
   */
  b    mcuxCsslMemory_Int_SecComp_arm_asm_Check_Equal

#ifdef __IASMARM__
        END
#endif
