/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_SecurePointSelect.c
 * @brief SecurePointSelect function
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClEcc.h>

#include <internal/mcuxClPkc_FupMacros.h>
#include <internal/mcuxClPrng_Internal.h>
#include <internal/mcuxClEcc_Weier_Internal_PkcWaLayout.h>
#include <internal/mcuxClEcc_Weier_Internal_FUP.h>
#include <internal/mcuxClEcc_Weier_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_XOR_Internal.h>

#include <mcuxClCore_Platform.h>
#define CREATE_ROR_TEMP /* not used */
#define ALLOCATE_ROR_TEMP  /* not used */
#define ROTATE_RIGHT(dest, src, bitsToRotate) \
    dest = ((src) >> (bitsToRotate)) | ((src) << (32U - (bitsToRotate)))

#define MCUXCLECC_PTR_TABLE_ENTRY_SHUFFLE(temp1_, offset_, randomN_, inShufShr2_, i_, pSource, pDestination, mask_, outShuf_, entrySizeLog2_)  \
    do{  \
        uint32_t temp1 = ((uint32_t) (temp1_)); \
        uint32_t offset = ((uint32_t) (offset_)); \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("i_ cannot not be larger than MCUXCLECC_TWED_PPTABLE_SIZE"); \
        offset = ((i_) + (inShufShr2_)); /* offset = i + (inShuf >> 2) */ \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW(); \
        offset ^= (randomN_); /* offset ^= inShuf */ \
        temp1 = ((offset) & (mask_)); /* scratch = offset & bitmask */ \
        temp1 <<= (entrySizeLog2_); /* scratch *= tableEntrySize */ \
        temp1 += ((uint32_t) (pSource)); /* scratch += rsrc */ \
        offset ^= (outShuf_); /* offset ^= outShuf */ \
        offset &= (mask_); /* offset &= bitmask */ \
        offset <<= (entrySizeLog2_); /* offset *= tableEntrySize */ \
        offset += ((uint32_t) (pDestination)); /* address = rdst + offset */ \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("legitimate pointer cast for shuffling"); \
        (temp1_) = ((uint8_t *) (temp1)); \
        (offset_) = ((uint8_t *) (offset)); \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER(); \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLECC_PREPARE_FOR_FIRST_SHUFFLE(temp1_, inShufShr2_, randomN_, indexMask_, maskedIndex_, tableEntryIndexBitSize, scalarDigitOffset)  \
    do {\
        /* Rotate scalar words so selected bits are LSBs */ \
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("scalarDigitOffset parameter is mod 32 (see calling function mcuxClEcc_TwEd_FixScalarMult)"); \
        ROTATE_RIGHT(maskedIndex_, maskedIndex_, scalarDigitOffset); \
        ROTATE_RIGHT(indexMask_, indexMask_, scalarDigitOffset); \
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW(); \
        /* Randomize not selected bits */ \
        (temp1_) = ((randomN_) << (tableEntryIndexBitSize)); /* temp1 = randomN << nBits */ \
        (randomN_) >>= 2; /* randomN >>= 2 */ \
        (maskedIndex_) ^= (temp1_); /* maskedIndex ^= temp1 */ \
        (temp1_) <<= 1; /* temp1 <<= 1 */ \
        (indexMask_) ^= (temp1_); /* indexMask ^= temp1 */ \
        /* Remask by xoring with random value */ \
        (maskedIndex_) ^= (randomN_); /* maskedIndex ^= randomN */ \
        (indexMask_) ^= (randomN_); /* indexMask ^= randomN */ \
        /* Calculate inShuf and inShuf >> 2 */ \
        (randomN_) >>= 2; /* randomN >>= 2 */ \
        (inShufShr2_) = (randomN_) >> 2; /* inShufShr2 = randomN >> 2 */ \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLECC_PREPARE_FOR_SECOND_SHUFFLE(inShufShr2_, maskedIndex_, outShuf_, randomN_) \
    do { \
        (outShuf_) = (randomN_) >> 4; /* randomB = randomN >> 4 */ \
        (maskedIndex_) ^= (outShuf_); /* index ^= randomB */ \
        (randomN_) = (outShuf_) >> 2; /* randomN = randomB >> 2 */ \
        (inShufShr2_) = (randomN_) >> 2; /* inShufShr2 = randomN >> 2 */ \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#define MCUXCLECC_CALCULATE_DESTINATION(address_, maskedIndex_, bitmask_, rsrc_, entrySizeLog2_)  \
    do {\
        (maskedIndex_) &= (bitmask_); /* index &= bitmask */ \
        (maskedIndex_) <<= (entrySizeLog2_); /* index *= tableEntrySize */ \
        (address_) = ((rsrc_) + (maskedIndex_)); /* address = rsrc + index */ \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
    } while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()



/**
  * Returns the value stored at index (maskedIndex ^ indexMask) in pTable.
  *
  * To do this in a secure way, the entire table is copied in a randomized order to the stack. It is then copied from there
  * to another portion of the stack, in a differently randomized order. The index is kept consistent with the randomization
  * such that the correct word can be read and returned at the end.
  *
  * In the permuted copy loops, the randomization happens as follows: The source index is chosen based on a permutation
  * derived from the round counter i, and a random mask value inShuf. The random mask value is applied to i in such a way
  * that it effectively generates a permuted value of i.
  *
  *   Example: For inShuf=0b0101, the permutation generated is (0,1,2,3)->(0,3,2,1). x maps to (x+inShuf>>2)^inShuf.
  *
  * The destination index for the copy operation in round i is chosen based on a permutation of the source index using a
  * different random mask, outShuf. Unlike the permutation that decides the source index, which is based on an addition and
  * bitwise XOR, this permutation is generated purely by a bitwise XOR.
  *
  *   Example: For outShuf=0b10, the permutation generated is (0,1,2,3)->(2,3,0,1). x maps to x ^ outShuf.
  *
  * The combined example is shown in the table below. Read the entries as follows: In round i, <source index> from the
  * source array is copied to <destination index> in the target array.
  *
  * +-------+------------------------+-------------------+
  * | round | source index           | destination index |
  * | i     | (i+(inShuf>>2))^inShuf | src^outShuf       |
  * +-------+------------------------+-------------------+
  * |     0 |                      0 |                 2 |
  * |     1 |                      3 |                 1 |
  * |     2 |                      2 |                 0 |
  * |     3 |                      1 |                 3 |
  * +-------+------------------------+-------------------+
  *
  * Note: Given an index Xsrc in the source array, the corresponding entry in the target array after the permuted copy loop
  * is found at index Xtgt = Xsrc^outShuf. The value of Xtgt depends only on outShuf, not on inShuf!
  *
  * In the context of the secure pointer selection algorithm, the first time this loop is executed with the source array
  * pTarget, target on the stack, inShuf=<randomN> and outShuf=indexMask. This is handy because it means that as described
  * in the note above, maskedIndex can be used as the selection index in the target array without modification.
  *
  * The second time this loop is executed with the source array on the stack, target on another portion of stack,
  * inShuf=<randomN>>2> and outShuf=<randomN>. The selection index is XORed with randomN to keep it consistent with the copy
  * permutation.
  *
  * The requested word is then loaded from the stack using the selection index.
  */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClEcc_SecurePtrTableEntrySelect)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_SecurePtrTableEntrySelect(
    const uint8_t *pTable,
    uint32_t scalarWord0,
    uint32_t scalarWord1,
    uint32_t scalarDigitOffset,
    uint32_t tableEntrySizeLog2,
    uint32_t tableEntryIndexBitSize,
    uint8_t *pShufBuffer,
    uint8_t *pShufBuffer2,
    uint8_t *pTargetTableEntry,
    const uint8_t *pPrecPointTableMask
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClEcc_SecurePtrTableEntrySelect);

    uint32_t numOfTableEntry = (uint32_t)1u << tableEntryIndexBitSize;
    uint32_t tableEntrySize = (uint32_t)1u << tableEntrySizeLog2;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("numOfTableEntry must have non-zero value.")
    uint32_t mask_ = numOfTableEntry - 1u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()


    CREATE_ROR_TEMP;

    uint32_t maskedIndex_ = scalarWord0;
    uint32_t indexMask_ = scalarWord1;
    MCUX_CSSL_FP_FUNCTION_CALL(randomNReturn, mcuxClPrng_generate_word());
    /* Assign randomN_ not to const */
    uint32_t randomN_ = randomNReturn;
    uint32_t outShuf_;
    uint32_t inShufShr2_;

    /* Expunged value is equal to 2 * [1 + 2 + ... + (nWords-1)] = (nWords << nBits) - nWords */
    MCUX_CSSL_DI_RECORD(securePointSelection, (numOfTableEntry << tableEntryIndexBitSize) - numOfTableEntry);

    /* Prepare inShuf and inShufshr2 for first shuffle */
    MCUXCLECC_PREPARE_FOR_FIRST_SHUFFLE(outShuf_, inShufShr2_, randomN_, indexMask_, maskedIndex_, tableEntryIndexBitSize, scalarDigitOffset);

    uint8_t* pSource = NULL;
    uint8_t* pDestionation = NULL;

    /* Permuted copy point index table to buffer with indexMask_ at outShuf */
    /* As a result point from indexMask_ ^ maskedIndex_ is moved to indexMask_ ^ maskedIndex_ ^ indexMask_ = maskedIndex_ */
    MCUX_CSSL_FP_LOOP_DECL(loop1);
    for (uint32_t i = 0u; i < numOfTableEntry; i++)
    {
        MCUXCLECC_PTR_TABLE_ENTRY_SHUFFLE(pSource, pDestionation, randomN_, inShufShr2_, i, pTable, pShufBuffer, mask_, indexMask_, tableEntrySizeLog2);
        MCUX_CSSL_DI_RECORD(sumOfMemXorParams, pDestionation);
        MCUX_CSSL_DI_RECORD(sumOfMemXorParams, pSource);
        MCUX_CSSL_DI_RECORD(sumOfMemXorParams, pPrecPointTableMask);
        MCUX_CSSL_DI_RECORD(sumOfMemXorParams, tableEntrySize);
        MCUXCLMEMORY_XOR_INT(pDestionation, pSource, pPrecPointTableMask, tableEntrySize);
        MCUX_CSSL_DI_EXPUNGE(securePointSelection, i);

        MCUX_CSSL_FP_LOOP_ITERATION(loop1, MCUXCLMEMORY_XOR_INT_FP_EXPECT);
    }

    /* Prepare inShuf and inShuf >> 2 for second xor shuffle */
    MCUXCLECC_PREPARE_FOR_SECOND_SHUFFLE(inShufShr2_, maskedIndex_, outShuf_, randomN_);

    /* Permuted copy point index table to buffer second time */
    /* As a result point from maskedIndex_ is moved maskedIndex_ ^ outShuf. maskedIndex is adjusted accordingly */
    MCUX_CSSL_FP_LOOP_DECL(loop2);
    for (uint32_t i = 0u; i < numOfTableEntry; i++)
    {
        MCUXCLECC_PTR_TABLE_ENTRY_SHUFFLE(pSource, pDestionation, randomN_, inShufShr2_, i, pShufBuffer, pShufBuffer2, mask_, outShuf_, tableEntrySizeLog2);
        MCUX_CSSL_DI_RECORD(sumOfMemCpyParams, pDestionation);
        MCUX_CSSL_DI_RECORD(sumOfMemCpyParams, pSource);
        MCUX_CSSL_DI_RECORD(sumOfMemCpyParams, tableEntrySize);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDestionation, pSource, tableEntrySize));
        MCUX_CSSL_DI_EXPUNGE(securePointSelection, i);

        MCUX_CSSL_FP_LOOP_ITERATION(loop2, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
    }
    uint8_t* address_ = NULL;

    /* Calculate address of selected point */
    MCUXCLECC_CALCULATE_DESTINATION(address_, maskedIndex_, mask_, pShufBuffer2, tableEntrySizeLog2);

    MCUX_CSSL_DI_RECORD(sumOfMemCpyParams, pTargetTableEntry);
    MCUX_CSSL_DI_RECORD(sumOfMemCpyParams, address_);
    MCUX_CSSL_DI_RECORD(sumOfMemCpyParams, tableEntrySize);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pTargetTableEntry, address_, tableEntrySize));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClEcc_SecurePtrTableEntrySelect,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop1, numOfTableEntry),
        MCUX_CSSL_FP_LOOP_ITERATIONS(loop2, numOfTableEntry),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}
