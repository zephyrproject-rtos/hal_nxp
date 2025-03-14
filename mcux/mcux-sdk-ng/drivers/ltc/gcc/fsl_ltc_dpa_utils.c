/*;
;* Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
;* All rights reserved.
;*
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ltc_decrementer(uint32_t count) __attribute__((naked));
uint32_t getRandomWord(void *aRngContext) __attribute__((naked));
void secureCopy(void *dstPtr, const void *srcPtr, int nBytes, uint32_t random32bits) __attribute__((naked));
uint32_t getRandomIndex(uint32_t n, uint32_t random32bits) __attribute__((naked));
void *securePointerSelect(uint32_t index,
                          uint32_t referenceIndex,
                          void *ptrEqual,
                          void *ptrDifferent,
                          uint32_t random32bits) __attribute__((naked));
void secureCopy_wordsInterleaved(void *dstPtr, void *srcPtr, int nBytes, uint32_t random32bits) __attribute__((naked));
void secureCopy_wordsCombine(volatile uint32_t *dstPtr, void *srcPtr, int nBytes, uint32_t random32bits)
    __attribute__((naked));

void ltc_gate_off(volatile uint32_t *scgc2, uint32_t gateOffRandom, uint32_t gateOffRepeat, uint32_t gateOffCycles)
    __attribute__((naked));

/*; =============================================================================
; getRandomWord
; =============================================================================
; input:
;   r0: ptr to RNG context A, B, C, D
; output:
;   r0: random number
; globbered:
;   RNG context updated
;   registers r0 - r3 modified
; register organization:
;   r0:         ptr to RNG context A, B, C, D / retVal
;   r1 - r4:    A, B, C, D
;   r5:         const 0x9e3779b9
; =============================================================================*/
uint32_t getRandomWord(void *aRngContext)
{
    __asm volatile(
        "	PUSH    {r4 - r5, lr}               \n" /* backup registers */
        "	LDM     r0, {r1-r4}                 \n" /* r1 - r4 = A, B, C, D */
        "	LDR     r5, =0x9e3779b9             \n" /* 2^32 / goldenRatio */
        "	ADD     r1, r5                      \n" /* A += 0x9e3779b9 */
        "	ADD     r2, r1, r2, ROR #19         \n" /* B := A + (B >>> 19) */
        "	ADD     r3, r2, r3, ROR #19         \n" /* C := B + (C >>> 19) */
        "	MUL     r3, r3, r5                  \n" /* C *= 0x9e3779b9 */
        "	ADD     r4, r3, r4, ROR #19         \n" /* D := C + (D >>> 19) */
        "	STM     r0, {r1-r4}                 \n" /* write back A, B, C, D */
        "	EOR     r0, r1, r2                  \n" /* retVal = A ^ B */
        "	EOR     r0, r3                      \n" /* retVal = A ^ B ^ C; EOR instead of EORS to avoid unnecessary
                                                     leakage by CPU flags */
        "	EOR     r0, r4                      \n" /* retVal = A ^ B ^ C ^ D ; EOR instead of EORS to avoid unnecessary
                                                     leakage by CPU flags */
        "	POP     {r4 - r5, pc}               \n" /* return and restore registers */
        ::);
}

/*; =============================================================================
; secureCopy
; =============================================================================
; input:
;   r0: dst ptr
;   r1: src ptr
;   r2: nBytes, must be a power of 2 with nBytes <= 2^10
;   r3: random 32 bit, used for randomization
; output:
;   none
; globbered:
;   nBytes are copied from src to dst
; register organization:
;   r0:         dst ptr
;   r1:         src ptr
;   r2:         mask = nBytes - 1
;   r3 - r6:    e, s, x, r
;   r7:         temp
;   r12:        counter
; =============================================================================*/
void secureCopy(void *dstPtr, const void *srcPtr, int nBytes, uint32_t random32bits)
{
    __asm volatile(
        /* ; init permutation */
        "    PUSH    {r4 - r7, lr}           \n" /*  backup registers */
        "    ROR     r4, r3, #10             \n" /*  r4 := s   ; r3 = e    ; reuse of random bits */
        "    ROR     r5, r3, #20             \n" /*  r5 := x */
        "    ORR     r4, r4, #1              \n" /*  s := s OR 1   ; odd s */
                                                 /* ; check for alignment */
        "    ORR     r7, r0, r1              \n" /*  r7 := dstPtr OR srcPtr */
        "    LSLS    r7, #30                 \n" /*  r7 contains only two lsb of dstPtr OR srcPtr */
        "    BEQ     _secureCopyWords        \n" /*  if word aligned copy word wise */
        "_secureCopyBytes:\n"
        /*  prepare loop variables and mask */
        "    SUBS    r2, #1                  \n" /*  r2 := m = nBytes - 1  ; value is known so leakage by CPU flags is
                                                    ok */
        "    MOV     r12, r2                 \n" /*  r12 := counter = nBytes - 1 */
        /* ; -----------------------------------------------------------------------------*/
        "_secureCopyBytes_loop:               \n" /*  for i = 0, ..., p-1 do: */
        /*    ; update permutation and compute next r */
        "    ADD     r3, r4                  \n" /*  e += s    ; value is sensitive hence no ADDS */
        "    EOR     r6, r3, r5              \n" /*  r6 := e XOR x */
        "    AND     r6, r2                  \n" /*  r6 := r = (e XOR x) AND m */

        /*    ; copy value from src to dst */
        "    LDRB    r7, [r1, r6]            \n" /*  r7 = temp := byte@( srcPtr + r ) */
        "    STRB    r7, [r0, r6]            \n" /*  byte@( dstPtr + r ) := r7 = temp */

        /*    ; next iteration */
        "    SUBS    r12, #1                 \n" /*  counter -= 1; */
        "    BHS     _secureCopyBytes_loop   \n"
        "    B       _secureCopy_commonEnd   \n"
        /*; -----------------------------------------------------------------------------*/

        "_secureCopyWords: \n"
        /*; prepare loop variables and mask */
        "    LSRS    r2, #2                  \n" /*  r2 = nWords = nBytes / 4  ; value is known so leakage by CPU flags
                                                    is ok */
        "    SUBS    r2, #1                  \n" /*  r2 := m = nWords - 1      ; value is known so leakage by CPU flags
                                                    is ok */
        "    MOV     r12, r2                 \n" /*  r12 := counter = nWords - 1 */

        /*; -----------------------------------------------------------------------------*/
        "_secureCopyWords_loop: \n" /* for i = 0, ..., p-1 do: */
        /* update permutation and compute next r */
        "    ADD     r3, r4                  \n" /*  e += s    ; value is sensitive hence no ADDS */
        "    EOR     r6, r3, r5              \n" /*  r6 := e XOR x */
        "    AND     r6, r2                  \n" /*  r6 := r = (e XOR x) AND m */

        /* copy value from src to dst */
        "    LDR     r7, [r1, r6, LSL #2]    \n" /*  r7 = temp := word@( srcPtr + r*4 ) */
        "    STR     r7, [r0, r6, LSL #2]    \n" /*  word@( dstPtr + r*4 ) := r7 = temp */

        /* next iteration */
        "    SUBS    r12, #1                 \n" /*  counter -= 1; */
        "    BHS     _secureCopyWords_loop   \n"
        /* ----------------------------------------------------------------------------- */

        "_secureCopy_commonEnd: \n"
        "    POP     {r4 - r7, pc}           \n" /*  return and restore registers */

        ::);
}

/* ; =============================================================================
; secureCopy_wordsInterleaved
; =============================================================================
; input:
;   r0: dst ptr
;   r1: src ptr
;   r2: nBytes, must be a power of 2 with 4 <= nBytes <= 2^10
;   r3: random 32 bit, used for randomization
; output:
;   none
; globbered:
;   nBytes are copied from src to dst wordwise
;   word@( dstPtr + 8*i ) = word@( srcPtr + 4*i ), i = 0, ..., nWords - 1; with nWords = nBytes / 4
; register organization:
;   r0:         dst ptr
;   r1:         src ptr
;   r2:         mask = nWords - 1
;   r3 - r6:    e, s, x, r
;   r7:         temp
;   r12:        counter
; ============================================================================= */
void secureCopy_wordsInterleaved(void *dstPtr, void *srcPtr, int nBytes, uint32_t random32bits)
{
    __asm volatile(
        /*    ; init permutation */
        "    PUSH    {r4 - r7, lr}           \n" /*  backup registers */
        "    ROR     r4, r3, #10             \n" /*  r4 := s   ; r3 = e    ; reuse of random bits */
        "    ROR     r5, r3, #20             \n" /*  r5 := x */
        "    ORR     r4, r4, #1              \n" /*  s := s OR 1   ; odd s */

        /*   ; prepare loop variables and mask */
        "    LSRS    r2, #2                  \n" /*  r2 = nWords = nBytes / 4  ; value is known so leakage by CPU flags
                                                    is ok */
        "    SUBS    r2, #1                  \n" /*  r2 := m = nWords - 1      ; value is known so leakage by CPU flags
                                                    is ok */
        "    MOV     r12, r2                 \n" /*  r12 := counter = nWords - 1 */

        /* ; ----------------------------------------------------------------------------- */
        "_secureCopy_wordsInterleaved_loop: \n" /* for i = 0, ..., p-1 do: */
        /* update permutation and compute next r */
        "    ADD     r3, r4                  \n" /*  e += s    ; value is sensitive hence no ADDS */
        "    EOR     r6, r3, r5              \n" /*  r6 := e XOR x */
        "    AND     r6, r2                  \n" /*  r6 := r = (e XOR x) AND m */

        /* copy value from src to dst */
        "    LDR     r7, [r1, r6, LSL #2]    \n" /*  r7 = temp := word@( srcPtr + r*4 ) */
        "    STR     r7, [r0, r6, LSL #3]    \n" /*  word@( dstPtr + r*8 ) := r7 = temp */

        /* next iteration */
        "    SUBS    r12, #1                 \n" /*  counter -= 1; */
        "    BHS     _secureCopy_wordsInterleaved_loop \n"
        /*  ----------------------------------------------------------------------------- */

        /* return */
        "    POP     {r4 - r7, pc}           \n" /*  return and restore registers */
        ::);
}

/*; =============================================================================
; secureCopy_wordsCombine
; =============================================================================
; input:
;   r0: dst ptr
;   r1: src ptr
;   r2: nBytes, must be a power of 2 with 4 <= nBytes <= 2^10
;   r3: random 32 bit, used for randomization
; output:
;   none
; globbered:
;   nBytes are copied from src to dst wordwise
;   word@( dstPtr + 4*i ) = word@( srcPtr + 8*i ), i = 0, ..., nWords - 1; with nWords = nBytes / 4
; register organization:
;   r0:         dst ptr
;   r1:         src ptr
;   r2:         mask = nWords - 1
;   r3 - r6:    e, s, x, r
;   r7:         temp
;   r12:        counter
; ============================================================================= */
void secureCopy_wordsCombine(volatile uint32_t *dstPtr, void *srcPtr, int nBytes, uint32_t random32bits)
{
    __asm volatile(
        /* init permutation */
        "    PUSH    {r4 - r7, lr}           \n" /*  backup registers */
        "    ROR     r4, r3, #10             \n" /*  r4 := s   ; r3 = e    ; reuse of random bits */
        "    ROR     r5, r3, #20             \n" /*  r5 := x */
        "    ORR     r4, r4, #1              \n" /*  s := s OR 1   ; odd s */

        /* prepare loop variables and mask */
        "    LSRS    r2, #2                  \n" /*  r2 = nWords = nBytes / 4  ; value is known so leakage by CPU flags
                                                    is ok */
        "    SUBS    r2, #1                  \n" /*  r2 := m = nWords - 1      ; value is known so leakage by CPU flags
                                                    is ok */
        "    MOV     r12, r2                 \n" /*  r12 := counter = nWords - 1 */

        /* ----------------------------------------------------------------------------- */
        "_secureCopy_wordsCombine_loop: \n" /* for i = 0, ..., p-1 do: */
        /* update permutation and compute next r */
        "    ADD     r3, r4                  \n" /*  e += s    ; value is sensitive hence no ADDS */
        "    EOR     r6, r3, r5              \n" /*  r6 := e XOR x */
        "    AND     r6, r2                  \n" /*  r6 := r = (e XOR x) AND m */

        /* copy value from src to dst */
        "    LDR     r7, [r1, r6, LSL #3]    \n" /*  r7 = temp := word@( srcPtr + r*8 ) */
        "    STR     r7, [r0, r6, LSL #2]    \n" /*  word@( dstPtr + r*4 ) := r7 = temp */

        /* next iteration */
        "    SUBS    r12, #1                 \n" /*  counter -= 1; */
        "    BHS     _secureCopy_wordsCombine_loop \n"
        /*  ----------------------------------------------------------------------------- */

        /* return */
        "    POP     {r4 - r7, pc}           \n" /*  return and restore registers */
        ::);
}

/* =============================================================================
; getRandomIndex
; =============================================================================
; input:
;   r0: n, number of possible indexes with n < 2^16
;   r1: random 32 bit, used for randomization
; output:
;   r0: random index in [0, n-1] provided as r || c with random 16-bit r and random 16-bit index c in [0, n-1]
; globbered:
;   r2
; register organization:
;   r0: n, temp and result
;   r1: random to generate c
;   r2: random for extra random bits
; =============================================================================*/
uint32_t getRandomIndex(uint32_t n, uint32_t random32bits)
{
    __asm volatile(
        "    UXTH    r2, r1      \n" /*  r2 = 16-bit random */
        "    LSRS    r1, #16     \n" /*  r1 = 16-bit random */
        "    MUL     r0, r1      \n" /*  r0 = c || ... */
        "    EOR     r0, r2      \n" /*  r0 = c || r */
        "    ROR     r0, #16     \n" /*  r0 = r || c */
        "    BX      lr          \n" /*  return */
        ::);
}

/*; =============================================================================
; securePointerSelect
; =============================================================================
; input:
;   r0:         index i
;   r1:         reference index provided as r || c with random 16-bit r and random 16-bit index c
;   r2:         ptrA
;   r3:         ptrB
;   stack[0]:   random 32 bit
; output:
;   r0: (i == c) ? ptrA : ptrB in constant time and with minimal side channel leakage
; globbered:
;   none
; register organization:
;   r0: temp for computing AND of all bits of i^c with noise
;   r1: used for selecting lower half of pointers
;   r2: used for selecting higher half of pointers
;   r3: random 32 bit
; ============================================================================= */
void *securePointerSelect(
    uint32_t index, uint32_t referenceIndex, void *ptrEqual, void *ptrDifferent, uint32_t random32bits)
{
    __asm volatile(
        /* prepare registers */
        "    MVNS    r0, r0                  \n" /*  r0 = ~i               ; to avoid fixed rotations for i == c ... */
        "    EOR     r0, r1                  \n" /*  r0 = ~r || (~i ^ c) */
        "    UXTH    r1, r2                  \n" /*  r1 = ptrA_L */
        "    ORR     r1, r1, r3, LSL #16     \n" /*  r1 = ptrB_L || ptrA_L */
        "    BFC     r2, #0, #16             \n" /*  r2 = ptrA_H || 0 */
        "    ORR     r2, r2, r3, LSR #16     \n" /*  r2 = ptrA_H || ptrB_H */
        "    LDR     r3, [ sp ]              \n" /*  r3 = random 32 bit */

        /* compute AND of all bits of ~i^c with noise */
        "    AND     r0, r0, r0, ROR #8      \n" /*  AND of 8 bit offsets */
        "    EOR     r0, r0, r3, LSL #8      \n" /*  rerandomize */
        "    AND     r0, r0, r0, ROR #4      \n" /*  AND of 4 bit offsets */
        "    EOR     r0, r0, r3, LSL #4      \n" /*  rerandomize */
        "    AND     r0, r0, r0, ROR #2      \n" /*  AND of 2 bit offsets */
        "    EOR     r0, r0, r3, LSL #2      \n" /*  rerandomize */
        "    AND     r0, r0, r0, ROR #1      \n" /*  AND of 1 bit offsets */
        "    EOR     r0, r0, r3, LSL #1      \n" /*  rerandomize   ; r0 = random 31 bits || e, with e == 1 <=> i == c */

        /* select pointer by random rotations */
        "    ROR     r0, #(32 - 3)           \n" /*  r0 <<<= 3     ; r0<3> = e */
        "    ROR     r1, #(32 - 7 - 16)      \n" /*  r1 <<<= 7 + 16 */
        "    ROR     r2, #(32 - 7 - 16)      \n" /*  r2 <<<= 7 + 16 */
        "    ROR     r1, r0                  \n" /*  r1 >>>= ...xexxx */
        "    ROR     r2, r0                  \n" /*  r2 >>>= ...xexxx */
        "    EOR     r0, #0x07               \n" /*  r0 = ...xeyyy */
        "    ROR     r1, r0                  \n" /*  r1 >>>= ...xeyyy  ; r1 = (ptrB_L || ptrA_L) >>> (16*e + 16) */
        "    ROR     r2, r0                  \n" /*  r2 >>>= ...xeyyy  ; r2 = (ptrA_H || ptrB_H) >>> (16*e + 16) */

        /* r0 = ptrX with X = (e == 0) ? A : B */
        "    MOV     r0, r2                  \n" /*  r0 = ptrX_H || ptrY_H */
        "    BFI     r0, r1, #0, #16         \n" /*  r0 = ptrX_H || ptrX_L = ptrX */

        /* return */
        "    BX      lr                      \n" /*  return */
        ::);
}

void ltc_decrementer(uint32_t count)
{
    __asm volatile(
        "ltc_decrementer_loop: \n"
        "SUBS    r0, r0, #1 \n"
        "CMP     r0, #0 \n"
        "BNE     ltc_decrementer_loop \n"
        "BX      lr	\n" ::);
}

/*; =============================================================================
; ltc_gate_off
; =============================================================================
; input:
;   r0:         SCGC2 register address
;   r1:         r32 random value
;   r2:         number of repeats
;   r3:         number of inner cycles (LTC clock off counter)
; output:
;   r0:         none
; globbered:
;   none
; register organization:
;   r0:
;   r1:         random 32-bit
;   r2:
;   r2:
; =============================================================================*/
void ltc_gate_off(volatile uint32_t *scgc2, uint32_t gateOffRandom, uint32_t gateOffRepeat, uint32_t gateOffCycles)
{
    __asm volatile(
        "    CMP         r2, #0 \n"
        "    BEQ         ltc_gate_off_exit \n"

        "    PUSH        {r4-r6, r8} \n"
        "    MOV         r8, r3 \n"
        "    MOV         r3, r1 \n"

        "ltc_gate_off_outer_loop: \n"

        "    MOV         r6, r8 \n"

        /*  LTC clock off */
        "    CPSID       i \n"
        "    LDR         r4, [r0]                 \n" /*  r4 = SIM_SCGC2 */
        "    AND         r4, r4, #0xFFF0FFFF      \n" /*  r4 = r4 & (~SIM_SCGC2_LTC_MASK)     */
        "    STR         r4, [r0]                 \n" /*  SIM_SCGC2 = r4 */
        "    CPSIE       i \n"

        "ltc_gate_negated:   \n"
        "    MLA         r1, r1, r3, r1           \n" /*  r1 = (r1 * r3) + r1 */
        "    ROR         r3, r3, #3     \n"
        "    CMP         r6, #0 \n"
        "    BEQ         ltc_gate_on \n"
        "    SUBS        r6, r6, #1 \n"
        "    B           ltc_gate_negated \n"

        "ltc_gate_on: \n"
        /*  LTC clock on */
        "    CPSID       i \n"
        "    LDR         r4, [r0]                 \n" /*  r4 = SIM_SCGC2 */
        "    ORR         r4, r4, #0x00020000      \n" /*  r4 = r4 | (SIM_SCGC2_LTC_MASK) */
        "    STR         r4, [r0]                 \n" /*  SIM_SCGC2 = r4 */
        "    CPSIE       i \n"

        "    SUBS        r2, r2, #1 \n"
        "    CMP         r2, #0 \n"
        "    BNE         ltc_gate_off_outer_loop \n"

        "    POP         {r4-r6, r8} \n"
        "ltc_gate_off_exit: \n"
        "    BX lr \n" ::);
}
