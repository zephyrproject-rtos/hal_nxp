/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClPkc_ImportExport.c
 * @brief mcuxClPkc: implementation of PKC internal import/export functions
 */


#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>

#include <mcuxClBuffer.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>

#include <internal/mcuxClMemory_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_ImportExport.h>


/**
 * [Design]
 * This function reverses a byte string in-place (switches the endianness).
 *
 * The buffer address shall be CPU word (4-byte) aligned.
 *
 * For platforms not supporting unaligned access to PKC workarea, this function
 * accesses to the byte string word-wisely if length is a multiple of CPU wordsize,
 * and byte-wisely if length is not a multiple of CPU wordsize.
 *
 * For platforms supporting unaligned access to PKC workarea, this function
 * intentionally declares some memory accesses as UNALIGNED.
 * When length = 0, this function does nothing.
 * When length = 8n+t, this function accesses the first 4n bytes and the last 4n
 * bytes word-wisely. Accesses to the last 4n bytes are declared as UNALIGNED.
 * For the t bytes in between, there are 2 scenarios:
 *   when t = 1~3, this function accesses these t-byte byte-wisely;
 *   when t = 4~7, this function accesses these t-byte word-wisely.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_SwitchEndianness)
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is indeed defined.")
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It defined only once.")
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_SwitchEndianness(uint32_t *ptr, uint32_t length)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_SwitchEndianness);
    if(0u == length)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_SwitchEndianness);
    }
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("use of UNALIGNED keyword")
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "ptrH32 will not be dereferenced outside the range [ptr, ptr+length-1] because of the condition (ptrH32 >= ptrL32).")
    uint32_t UNALIGNED *ptrH32 = (uint32_t UNALIGNED *) & ((uint8_t *) ptr)[length - 4u];
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    uint32_t *ptrL32 = ptr;

    /* While there are >= 4 bytes to switch the endianness. */
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(MISRA_C_2012_Rule_18_3, "both ptrH32 and ptrL32 point into ptr[].")
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(CERT_ARR36_C, "both ptrH32 and ptrL32 point into ptr[].")
    while (ptrH32 >= ptrL32)
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(CERT_ARR36_C)
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(MISRA_C_2012_Rule_18_3)
    {
        MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(INTEGER_OVERFLOW, "ptrH32 and ptrL32 will not be dereferenced outside the range [ptr, ptr+length-1] because of the condition (ptrH32 >= ptrL32).")
        uint32_t wordL = *ptrL32;
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("UNALIGNED keyword is used for ptrH32 definition")
        uint32_t wordH = *ptrH32;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

        wordL = MCUXCLMEMORY_SWITCH_4BYTE_ENDIANNESS(wordL);
        wordH = MCUXCLMEMORY_SWITCH_4BYTE_ENDIANNESS(wordH);

        *ptrH32 = wordL;
        ptrH32--;
        *ptrL32 = wordH;
        ptrL32++;
        MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(INTEGER_OVERFLOW)
    }

    /* If ptrH <= ptrL - 4, nothing more to do. */
    /* If ptrH == ptrL - 3, swap ptrL[0] with ptrH[3] = ptrL[0], i.e., nothing to do. */
    /* If ptrH == ptrL - 2, swap ptrL[0] with ptrH[3] = ptrL[1]. */
    /* If ptrH == ptrL - 1, swap ptrL[0] with ptrH[3] = ptrL[2], and leave ptrL[1] unchanged. */
    uint8_t *ptrL8 = (uint8_t *) ptrL32;
    uint8_t *ptrH8 = & ((uint8_t *) ptrH32)[3u];
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(MISRA_C_2012_Rule_18_3, "both ptrH8 and ptrL8 point into ptr[].")
    MCUX_CSSL_ANALYSIS_COVERITY_START_FALSE_POSITIVE(CERT_ARR36_C, "both ptrH32 and ptrL32 point into ptr[].")
    if (ptrH8 > ptrL8)
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(CERT_ARR36_C)
    MCUX_CSSL_ANALYSIS_COVERITY_STOP_FALSE_POSITIVE(MISRA_C_2012_Rule_18_3)
    {
        uint8_t byteL = *ptrL8;
        uint8_t byteH = *ptrH8;

        *ptrH8 = byteL;
        *ptrL8 = byteH;
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_SwitchEndianness);
}

/**
 * [Design]
 * This function imports an integer stored as a big-endian octet string to PKC workarea.
 *
 * (1) clear the target PKC buffer by CPU if the passed length is smaller than targetBufferLength
 * (2) copy the big-endian octet string of the specified length to the target buffer, with reversed byte order.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_ImportBigEndianToPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_ImportBigEndianToPkc(uint8_t iTarget, const uint8_t * pSource, uint32_t length, uint32_t targetBufferLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_ImportBigEndianToPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pTarget = MCUXCLPKC_OFFSET2PTR (pOperands[iTarget]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, (uint32_t)pTarget);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_ImportBigEndianToPkc /* not used*/, iTarget);

    MCUXCLPKC_WAITFORFINISH();

    if (targetBufferLength > length)
    {
        MCUX_CSSL_DI_RECORD(clearTarget, (uint32_t)pTarget);
        MCUX_CSSL_DI_RECORD(clearTarget, targetBufferLength);
        MCUXCLMEMORY_CLEAR_INT(&pTarget[length], targetBufferLength - length);
    }
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_ImportBigEndianToPkc /* not used*/, targetBufferLength);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(pTarget, pSource, length));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_ImportBigEndianToPkc,
        MCUX_CSSL_FP_CONDITIONAL(targetBufferLength > length, MCUXCLMEMORY_CLEAR_INT_FP_EXPECT),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int));
}

/**
 * [Design]
 * This function imports an integer stored as a little-endian octet string to PKC workarea.
 *
 * (1) clear the target PKC buffer by CPU if the passed length is smaller than targetBufferLength
 * (2) copy the little-endian octet string of the specified length to the target buffer.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_ImportLittleEndianToPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_ImportLittleEndianToPkc(uint8_t iTarget, const uint8_t * pSource, uint32_t length, uint32_t targetBufferLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_ImportLittleEndianToPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pTarget = MCUXCLPKC_OFFSET2PTR(pOperands[iTarget]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int /* not used*/, pTarget);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_ImportLittleEndianToPkc /* not used*/, iTarget);

    MCUXCLPKC_WAITFORFINISH();

    if (targetBufferLength > length)
    {
        MCUX_CSSL_DI_RECORD(clearTarget, (uint32_t)pTarget);
        MCUX_CSSL_DI_RECORD(clearTarget, targetBufferLength);
        MCUXCLMEMORY_CLEAR_INT(&pTarget[length], targetBufferLength - length);
    }
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_ImportLittleEndianToPkc /* not used*/, targetBufferLength);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pTarget, pSource, length));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_ImportLittleEndianToPkc,
        MCUX_CSSL_FP_CONDITIONAL(targetBufferLength > length, MCUXCLMEMORY_CLEAR_INT_FP_EXPECT),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}

/**
 * [Design]
 * This function exports a PKC operand (with specified length) and stores it as
 * a big-endian octet string in the target buffer.
 *
 * (0) the PKC operand is stored as a little-endian octet string in PKC workarea;
 * (1) copy the string in PKC workarea to the target buffer, with reversed byte order.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_ExportBigEndianFromPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_ExportBigEndianFromPkc(uint8_t * pTarget, uint8_t iSource, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_ExportBigEndianFromPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint8_t *pSource = MCUXCLPKC_OFFSET2PTR(pOperands[iSource]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_reversed_int /* not used*/, (uint32_t) pSource);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_ExportBigEndianFromPkc /* not used*/, iSource);
    MCUXCLPKC_WAITFORFINISH();

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(pTarget, pSource, length));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_ExportBigEndianFromPkc,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int));
}

/**
 * [Design]
 * This function exports a PKC operand (with specified length) and stores it as
 * a little-endian octet string in the target buffer.
 *
 * (1) Copy the little-endian octet string of the specified length to the target buffer.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_ExportLittleEndianFromPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_ExportLittleEndianFromPkc(uint8_t *pTarget, uint8_t iSource, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_ExportLittleEndianFromPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint8_t *pSource = MCUXCLPKC_OFFSET2PTR(pOperands[iSource]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int /* not used*/, pSource);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_ExportLittleEndianFromPkc /* not used*/, iSource);

    MCUXCLPKC_WAITFORFINISH();
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pTarget, pSource, length));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_ExportLittleEndianFromPkc,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int) );
}

/**
 * [Design]
 * This function imports an integer stored as a big-endian octet string to PKC workarea,
 * in a secure manner.
 *
 * (1) clear the target PKC buffer by CPU if the passed length is smaller than targetBufferLength
 * (2) Securely copy the big-endian octet string of the specified length to the target buffer.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_SecureImportBigEndianToPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_SecureImportBigEndianToPkc(uint8_t iTarget, const uint8_t * pSource, uint32_t length, uint32_t targetBufferLength)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_SecureImportBigEndianToPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    uint8_t *pTarget = MCUXCLPKC_OFFSET2PTR(pOperands[iTarget]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_reversed_int /* not used*/, pTarget);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_SecureImportBigEndianToPkc /* not used*/, iTarget);

    MCUXCLPKC_WAITFORFINISH();

    if (targetBufferLength > length)
    {
        MCUX_CSSL_DI_RECORD(clearTarget, (uint32_t)pTarget);
        MCUX_CSSL_DI_RECORD(clearTarget, targetBufferLength);
        MCUXCLMEMORY_CLEAR_INT(&pTarget[length], targetBufferLength - length);
    }
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_SecureImportBigEndianToPkc /* not used*/, targetBufferLength);

    MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(pTarget, pSource, length);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_SecureImportBigEndianToPkc,
        MCUX_CSSL_FP_CONDITIONAL(targetBufferLength > length, MCUXCLMEMORY_CLEAR_INT_FP_EXPECT),
        MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT);
}

/**
 * [Design]
 * This function exports a PKC operand (with specified length) and stores it as
 * a big-endian octet string in the target buffer, in a secure manner.
 *
 * (0) the source PKC operand is stored as a little-endian octet string in PKC workarea;
 * (1) securely copy the PKC operand of the specified length to the target buffer, with reversed byte order.
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_SecureExportBigEndianFromPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_SecureExportBigEndianFromPkc(uint8_t * pTarget, uint8_t iSource, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_SecureExportBigEndianFromPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint8_t *pSource = MCUXCLPKC_OFFSET2PTR(pOperands[iSource]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int /* not used*/, pSource);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_SecureExportBigEndianFromPkc /* not used*/, iSource);

    MCUXCLPKC_WAITFORFINISH();

    MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(pTarget, pSource, length);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_SecureExportBigEndianFromPkc,
        MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT);
}

/**
 * [Design]
 * This function exports a PKC operand (with specified length) and stores it as
 * a little-endian octet string in the target buffer, in a secure manner.
 *
 * (0) the PKC operand is stored as a little-endian octet string in PKC workarea;
 * (1) securely copy the PKC operand of the specified length to the target buffer.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClPkc_SecureExportLittleEndianFromPkc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_SecureExportLittleEndianFromPkc(uint8_t * pTarget, uint8_t iSource, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClPkc_SecureExportLittleEndianFromPkc);

    const uint16_t *pOperands = MCUXCLPKC_GETUPTRT();
    const uint8_t *pSource = MCUXCLPKC_OFFSET2PTR(pOperands[iSource]);

    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int /* not used*/, pSource);
    MCUX_CSSL_DI_EXPUNGE(mcuxClPkc_SecureExportLittleEndianFromPkc /* not used*/, iSource);

    MCUXCLPKC_WAITFORFINISH();

    MCUXCLMEMORY_COPY_SECURE_INT(pTarget, pSource, length);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClPkc_SecureExportLittleEndianFromPkc,
        MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT);
}
