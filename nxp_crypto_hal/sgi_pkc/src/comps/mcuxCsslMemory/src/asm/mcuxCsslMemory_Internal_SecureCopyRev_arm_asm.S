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
 * @file  mcuxCsslMemory_Internal_SecureCopy_arm_asm.S
 */


#include <internal/mcuxCsslPrng_AssemblyMacros.h>
#include <internal/mcuxCsslMemory_Internal_AssemblyMacros.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection_SecureCounter_Local_AssemblyMacros.h>
#include <mcuxCsslDataIntegrity_AssemblyMacros.h>
#include <mcuxCsslAssembly.h>

#define rPTgt r0              /* pTargetX, current pointer to target buffer */
#define rPSrc r1              /* pSourceX, current pointer to source buffer */
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

MCUX_CSSL_ASM_FILE_START()

MCUX_CSSL_ASM_FUNC_SYMBOL_GLOBAL(mcuxCsslMemory_Int_SecCopyRev)
MCUX_CSSL_ASM_FUNC_SYMBOL(mcuxCsslMemory_Int_SecCopyRev)
MCUX_CSSL_ASM_FUNC_SECTION(mcuxCsslMemory_Int_SecCopyRev)
MCUX_CSSL_ASM_FUNC_ALIGNMENT()

/*
 * void mcuxCsslMemory_Int_SecCopyRev(uint8_t * pTarget, const uint8_t * pSource, uint32_t length);
 * r0 = pTarget
 * r1 = pSource
 * r2 = length
 */
MCUX_CSSL_ASM_FUNC_START(mcuxCsslMemory_Int_SecCopyRev)
  push {r4-r11, lr}              /* Save registers on the stack */

  MCUX_CSSL_FP_ASM_FUNCTION_ENTRY  rSc, rT0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecCopyRev
  /*
   * Reserve stack for:
   *   rHLen - half length = length / 2
   */
  sub      sp,     sp, #8   /* It is recommended to align stack by 8 bytes */

mcuxCsslMemory_Int_SecCopyRev_CheckZeroLength:
  /* Copy nothing but only update DI when length=0. */
  cmp      r2,     #0
  beq      mcuxCsslMemory_Int_SecCopy_ZeroLenBalanceDI

  /* DI -= 2*pSource */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPSrc    /*  REV  */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPSrc    /*  REV  */
  /* Fetch random numbers for e and s. */
  MCUXCSSLPRNG_INIT_ADDR  rT0      /* Load PRNG SFR address. */
  MCUXCSSLPRNG_GET_PRNG   rT0, rE  /* rE = random number */
  MCUXCSSLPRNG_GET_PRNG   rT0, rS  /* rS = random number */

mcuxCsslMemory_Int_SecCopyRev_CheckLength:
  cmp   rI, #4
  blo   mcuxCsslMemory_Int_SecCopyRev_Byte

mcuxCsslMemory_Int_SecCopyRev_Word:
  /* Calculate initial position (e), step (s), number of blocks (n), and offset in 2nd half of buffer. */
  lsrs   rT0, rI, #1            /* rHLen = length / 2 */
  str    rT0, [sp, #rHLenSPOffset]

  /* Check the length is power of 2, if power of 2 rT1 = 0 at the end */
  mov      rT1,    rI
  sub      rT1,    rT1, #1
  and      rT1,    rT1, rI

  /* Prepare rI (n) =  (len+3)/4 */
  add      rN,     rI, #3
  and      rN,     rN, #0xFFFFFFFC     /* 4n = (length + 3) & 0xFFFFFFFC */
  sub      rOft,   rI, rN              /* Offset = len - 4n, in {-3,-2,-1,0} */
  sub      rT0,    rI, #4              /* len-4                                   **REV** */
  lsr      rI,     rN, #2              /* Loop iteration, n = (len+3)/4 */
  /* Jump if not power of 2 */
  cmp      rT1,    #0
  mov      rT1,    rT0
  bne      mcuxCsslMemory_Int_SecCopy_LengthNotPowerOfTwo

mcuxCsslMemory_Int_SecCopy_LengthIsPowerOfTwo:
  sub      rT0,    rI, #1                /* n - 1 */
  and      rE,     rE, rT0               /* e = GetLqRngWord() & (n-1) -> e in [0..n-1] */
  and      rS,     rS, rT0               /* s = GetLqRngWord() & (n-1) */
  orr      rS,     rS, #1                /* s = 1 | s -> s in [1..n-1]  */

  subs     rT,     rI, #1
  adc      rT,     rT, #0              /* Avoid calculating "mod 0" (when len = 4) */
  b        mcuxCsslMemory_Int_SecCopy_LengthNotPowerOfTwo_End

mcuxCsslMemory_Int_SecCopy_LengthNotPowerOfTwo:
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

mcuxCsslMemory_Int_SecCopy_LengthNotPowerOfTwo_End:
  lsl      rE,     rE, #2              /* rE = random number * 4 */
  lsl      rS,     rS, #2              /* rS = random number * 4 */

  /*
   * DI -= (8(initial e) + 4).
   * (2 * pSource) has been EXPUNGE.
   * (pTarget + length-4 - 4(initial e)) and -(pSource + 4(initial e)) will be EXPUNGE after the loop.
   */
  add      rT,     rE, #4              /* REV */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rE      /* REV */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rT      /* REV */
  /*
   * eL (last e in current cyclic subgroup) = (e < s) ? (e-s+n) : (e-s).
   * CAUTION: if len=4, then e=0, s=1, eL = 0.
   */
  subs     rEL,    rE, rS              /* rEL = rE - rS, and set flags */
  it       lo
  addlo    rEL,    rEL, rN             /* If rE < rS (unsigned), rEL += rN */

  /* offsetX (offset for current e) = (len/2 < 4e) ? offset : 0. */
  ldr      rT0,    [sp, #rHLenSPOffset]
  movs     rOftX,  #0
  cmp      rT0,    rE
  it       lo
  movlo    rOftX,  rOft

  mov      rCyc, #0

  /* Calculate initial pointers, according to e and offsetX. */
  add      rT,     rE,    rOftX        /* 4e + offsetX */
  add      rPTgt,  rPTgt, rT1          /* REV */
  sub      rPTgt,  rPTgt, rT           /* rPTgt -> pTarget[(len - 4) - 4e+offsetX]   REV */
  add      rPSrc,  rPSrc, rT           /* pSrc  -> pSource[4e+offsetX] */

  /* for (i = n; i > 0; i--) */
mcuxCsslMemory_Int_SecCopyRev_WordLoop:

  /* Check if reach the last element of the current cyclic group. */
  cmp      rE,     rEL
  ite      eq
  moveq    rT0,    #4
  movne    rT0,    #0

  add      rCyc,   rCyc, rT0

  ldr      rT,     [rPSrc]

  /*
   * Update the last element eL = (eL+s') mod n = eL or (eL+1) or 0.
   * CAUTION: if len=4, then eL=0, s'=1, n=1, and new eL = 0.
   */
  adds     rEL,    rEL, rT0            /* rEL += sp4, set flags */
  cmp      rEL,    rN                  /* Compare rEL to n */
  it       hs                          /* If rEL >= n (unsigned), execute next */
  movhs    rEL,    #0                  /* Reset rEL to 0 if out of bounds */
  rev      rT,     rT                  /*  REV  */
  str      rT,     [rPTgt]

  /*
   * diff = (new e) - (old e) = ((e+s+s') mod n) - e = s+s' or s+s'-n.
   * CAUTION: if len=4, then e=0, s=1, s'=1, n=1, and diff = 1 and (new e) = 1.
   */
  add      rT0,    rT0, rS             /* 4s' + 4s */
  add      rT,     rE,  rT0            /* 4e + 4s + 4s' */
  cmp      rT,     rN                  /* (4(e+s+s') < 4n) ? 1 : 0 */
  ite      lo
  movlo    rT,     #1                  /* If (4(e+s+s') < 4n), set rT to 1 */
  movhs    rT,     #0                  /* If (4(e+s+s') >= 4n), set rT to 0 */
  sub      rT,     rT,  #1             /* 0 or -1 (0xFFFFFFFF) */
  and      rT,     rT,  rN             /* 0 or 4n */
  sub      rT,     rT0, rT             /* 4diff */

  add      rE,     rE,  rT             /* new 4e */
  sub      rT,     rT,  rOftX          /* 4diff -= (old offsetX)   REV  */

  /* offsetX = (Len/2 < 4e) ? offset : 0. */
  ldr      rT0,    [sp, #rHLenSPOffset]  /* load rHLen from stack into rT0 */
  cmp      rE,     rT0                   /* check if 4e > Len/2 */
  ite      hi                            /* if 4e > Len/2, then... */
  movhi    rOftX,  rOft                  /* rOftX = offset */
  movls    rOftX,  #0                    /* else: rOftX = 0 */

  sub      rI,     rI, #1                /* i-- */
  add      rT,     rT, rOftX             /* rT = 4diff += new offsetX */

  add      rPSrc,  rPSrc, rT             /* pSource[(new 4e) + (new offsetX)] */
  sub      rPTgt,  rPTgt, rT             /* pTarget[(len-4)-(new 4e)-(new offsetX)]   REV */

mcuxCsslMemory_Int_SecCopyRev_WordLoopCond:
  cmp    rI, #0
  bne    mcuxCsslMemory_Int_SecCopyRev_WordLoop

  /*
   * After all iterations of WordLoop, pTgt and pSrc shall point to
 * pTarget[(len-4) - 4e - offsetX] and pSource[4e + offsetX],
   * where e = (initial e) + cyc mod n.
   */
  /*
   * Calculate the difference between 4(initial e) and 4e + offsetX.
   * e = (initial e) + cyc - n, if e < cyc; or = (initial e) + cyc, otherwise.
   * So, (initial e) - e = n - cyc, if e < cyc; or = -cyc, otherwise.
   */
  cmp      rE,     rCyc                   /* (e < cyc) ? 1 : 0 */
  ite      lo
  movlo    rT,     rN                    /* If (e < cyc),  set rT to 4n */
  movhs    rT,     #0                    /* If (e >= cyc), set rT to 0 */
  sub      rT,     rT, rCyc              /* 4n-4cyc or -4cyc */
  sub      rT,     rT, rOftX             /* 4n-4cyc - offsetX or -4cyc - offsetX */

  /* DI -= ((pTarget + (len-4) - 4(initial e)) - (pSource + 4(initial e))). */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPTgt   /*  REV  */
  MCUX_CSSL_DI_ASM_RECORD  rSc, rT      /*  REV  */
  MCUX_CSSL_DI_ASM_RECORD  rSc, rPSrc   /*  REV  */
  MCUX_CSSL_DI_ASM_RECORD  rSc, rT      /*  REV  */

  /* Return to caller with DI -= (pSource + pTarget + length). */
mcuxCsslMemory_Int_SecCopyRev_Return:
  add      sp,     sp, #8              /* Restore stack pointer */
  MCUX_CSSL_FP_ASM_FUNCTION_EXIT  rSc, rT0, MCUX_CSSL_FP_FUNCID_mcuxCsslMemory_Int_SecCopyRev
  mov      r1,     rSc                 /* Return SC in r1 */
  pop      {r4-r11, pc}                /* Restore registers from the stack  and return */

mcuxCsslMemory_Int_SecCopy_ZeroLenBalanceDI:
  /* Even in case of len = 0 we need to maintain DI */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPTgt
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPSrc
  b        mcuxCsslMemory_Int_SecCopyRev_Return

mcuxCsslMemory_Int_SecCopyRev_Byte:
  /* Calculate initial position (e) and step (s). */
  mov      rN,     rI                  /* rN = length */
  subs     rT1,    rI,  #1             /* rN-1 = length-1 */
  clz      rT,     rT1
  lsr      rT,     #5
  add      rT,     rT,  rT1            /* Avoid calculating "mod 0" (when len=1) */
  udiv     rT0,    rE,  rI             /* e in [0, n-1] */
  mls      rE,     rT0, rI, rE         /* rE = rE % rI */
  udiv     rT0,    rS,  rT
  mls      rS,     rT0, rT, rS         /* rS = rS % rT */
  add      rS,     rS,  #1             /* s in [1, n-1] if n > 1; s = 1 if n = 1 */

  /*
   * DI -= (2e + 1).
   * (2 * pSource) has been EXPUNGE.
   * (pTarget + length-1 - e) and -(pSource + e) will be EXPUNGE after the loop.
   */
  add                      rT,  rE, #1   /*  REV  */
  MCUX_CSSL_DI_ASM_EXPUNGE  rSc, rE       /*  REV  */
  MCUX_CSSL_DI_ASM_EXPUNGE  rSc, rT       /*  REV  */

  /* Calculate initial pointers, according to e. */
  add      rPTgt,  rPTgt, rT1          /* pTgt -> pTarget[e]          REV */
  sub      rPTgt,  rPTgt, rE           /* pTgt -> pTarget[(len-1)-e]  REV */
  add      rPSrc,  rPSrc, rE           /* pSrc -> pSource[e] */

  /* for (i = n; i > 0; i--) */
mcuxCsslMemory_Int_SecCopyRev_ByteLoop:

  /*
   * diff = (new e) - (old e) = ((e+s) mod n) - e = s or s-n.
   * CAUTION: if len=1, then e=0, s=1, and diff = 0.
   */
  add      rT,     rE, rS              /* e + s */
  cmp      rT,     rN                  /* ((e+s) < n) ? 1 : 0 */
  ite      lo
  movlo    rT,     #1
  movhs    rT,     #0

  ldrb     rT1,    [rPSrc, #0]

  sub      rT,     rT, #1              /* 0 or -1 (0xFFFFFFFF) */
  and      rT,     rT, rN              /* 0 or  n */

  strb     rT1,    [rPTgt, #0]

  sub      rT1, rS, rT                 /* diff */

  sub      rI,     rI,    #1
  add      rE,     rE,    rT1          /* new e */
  add      rPSrc,  rPSrc, rT1          /* pSrc += diff */
  sub      rPTgt,  rPTgt, rT1          /* pTgt[(len-1) - (new e)]   REV */

mcuxCsslMemory_Int_SecCopyRev_ByteLoopCond:
  cmp      rI,     #0
  bne      mcuxCsslMemory_Int_SecCopyRev_ByteLoop


  /* DI -= ((pTarget + e) + (pSource + e)). */
  /*
   * After all iterations of ByteLoop, pTgt and pSrc shall point to
   * original pTarget[(len-1)-e] and pSource[e] before ByteLoop.
   * DI -= ((pTarget + (len-1) - e) - (pSource + e)).
   */
  MCUX_CSSL_DI_ASM_EXPUNGE rSc, rPTgt
  MCUX_CSSL_DI_ASM_RECORD  rSc, rPSrc     /*  REV  */

  /* Return to caller with DI -= (pSource + pTarget + length). */
  b        mcuxCsslMemory_Int_SecCopyRev_Return

MCUX_CSSL_ASM_FILE_END()
