/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

    .syntax unified

    .text
    .thumb

    .align 2

#ifndef MSDK_MISC_OVERRIDE_MEMSET
#define MSDK_MISC_OVERRIDE_MEMSET 1
#endif

/*
   This memset function is used to replace the GCC newlib function for these purposes:
   1. The newlib nano memset function uses byte-by-byte fill, which is slow.
   2. This implementation fills destination memory word-by-word after alignment,
      avoiding performance penalties from misaligned accesses on device memory.

   The workflow is:
   1. Return directly if length is 0.
   2. Spread the fill byte to a 32-bit word pattern (e.g. 0xAB -> 0xABABABAB).
   3. If the destination address is not 4-byte aligned, fill unaligned bytes first.
   4. Fill memory 16 bytes at a time using stmia for the bulk of the data.
   5. Handle the 8-byte, 4-byte, 2-byte, and 1-byte remainders.

   The equivalent C function is:

   void * memset(void *s, int c, size_t n)
   {
       void *ret = s;
       uint8_t  byte = (uint8_t)c;
       uint32_t word = byte | ((uint32_t)byte << 8) | ((uint32_t)byte << 16) | ((uint32_t)byte << 24);

       if (0 == n) return ret;

       while (((uintptr_t)s & 0x03UL) != 0UL)
       {
           *(uint8_t *)s = byte;
           s = ((uint8_t *)s) + 1;
           n--;
           if (0 == n) return ret;
       }

       while (n >= 16UL)
       {
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
           n -= 16UL;
       }

       if ((n & 0x08UL) != 0UL)
       {
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
       }

       if ((n & 0x04UL) != 0UL)
       {
           *(uint32_t *)s = word; s = ((uint32_t *)s) + 1;
       }

       if ((n & 0x02UL) != 0UL)
       {
           *(uint16_t *)s = (uint16_t)word; s = ((uint16_t *)s) + 1;
       }

       if ((n & 0x01UL) != 0UL)
       {
           *(uint8_t *)s = byte;
       }

       return ret;
   }

   Register usage:
     r0 = s (dst pointer, preserved on stack as return value)
     r1 = fill word (0xCCCCCCCC after byte-spread)
     r2 = n (remaining byte count)
     r3 = scratch (alignment check / shift result)
     r4-r7 = fill word copies for stmia (16-byte bulk stores)

   The function is testd with:

    static void test_memset(uint8_t *buf, size_t n)
    {
        uint8_t *bs, *be, *data;
        uint8_t fill;
        size_t nn;

        for (bs = buf; bs < buf + n; bs++)
        {
            for (be = bs; be <= buf + n; be++)
            {
                nn   = (size_t)((uintptr_t)be - (uintptr_t)bs);
                fill = (uint8_t)((uintptr_t)bs ^ nn);

                for (data = buf; data < buf + n; data++)
                {
                    *data = (uint8_t)~fill;
                }

                memset(bs, (int)fill, nn);

                for (data = buf; data < bs; data++)
                {
                    assert(*data == (uint8_t)~fill);
                }

                for (data = bs; data < be; data++)
                {
                    assert(*data == fill);
                }

                for (data = be; data < buf + n; data++)
                {
                    assert(*data == (uint8_t)~fill);
                }
            }
        }
    }
*/

#if MSDK_MISC_OVERRIDE_MEMSET

    .thumb_func
    .align 2
    .global  memset
    .type    memset, %function

memset:
    push    {r0, r4, r5, r6, r7, lr}
    cmp     r2, #0
    beq.n   ret                    /* If size is 0, return. */

    /* Spread fill byte to all 4 bytes of a word: c -> 0xCCCCCCCC */
    uxtb    r1, r1                 /* r1 = c & 0xFF (zero-extend byte) */
    orr     r1, r1, r1, lsl #8    /* r1 = c | (c << 8) */
    orr     r1, r1, r1, lsl #16   /* r1 = c | (c<<8) | (c<<16) | (c<<24) */

dst_byte_unaligned:
    ands    r3, r0, #3             /* Check dst 4-byte alignment. */
    beq.n   dst_word_aligned       /* dst is 4-byte aligned, jump. */
    strb    r1, [r0], #1          /* Store one byte and advance dst. */
    subs    r2, r2, #1             /* n-- */
    beq.n   ret                    /* n=0, return. */
    b.n     dst_byte_unaligned

dst_word_aligned:
    mov     r4, r1                 /* Load fill word into r4-r7 for stmia. */
    mov     r5, r1
    mov     r6, r1
    mov     r7, r1
    cmp     r2, #16
    blt.n   size_ge_8
size_ge_16:                        /* size >= 16: fill 4 words (16 bytes) per loop. */
    subs    r2, r2, #16
    cmp     r2, #16
    stmia   r0!, {r4, r5, r6, r7}
    bcs.n   size_ge_16
size_ge_8:                         /* Bit 3 of r2 set → 8 more bytes to fill. */
    lsls    r3, r2, #28
    it      mi
    stmiami r0!, {r4, r5}
size_ge_4:                         /* Bit 2 of r2 set → 4 more bytes to fill. */
    lsls    r3, r2, #29
    it      mi
    strmi   r1, [r0], #4
size_ge_2:                         /* Bit 1 of r2 set → 2 more bytes to fill. */
    lsls    r3, r2, #30
    it      mi
    strhmi  r1, [r0], #2
size_ge_1:                         /* Bit 0 of r2 set → 1 more byte to fill. */
    lsls    r3, r2, #31
    it      mi
    strbmi  r1, [r0]
ret:
    pop     {r0, r4, r5, r6, r7, pc}

#endif /* MSDK_MISC_OVERRIDE_MEMSET */
