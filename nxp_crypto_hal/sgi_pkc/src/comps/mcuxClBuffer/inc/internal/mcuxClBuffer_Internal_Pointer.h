/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClBuffer_Internal_Pointer.h
 * @brief Provides the internal API & implementation for the plain C pointer buffer types.
 */

#ifndef MCUXCLBUFFER_INTERNAL_POINTER_H_
#define MCUXCLBUFFER_INTERNAL_POINTER_H_

#include <mcuxClToolchain.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClBuffer.h>
#include <mcuxClBuffer_Pointer.h>

#include <mcuxCsslDataIntegrity.h>

#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClMemory_Copy_Reversed_Internal.h>
#include <internal/mcuxClMemory_CopySecure_Internal.h>
#include <internal/mcuxClMemory_CopySecure_Reversed_Internal.h>
#include <internal/mcuxClBuffer_FeatureConfig.h>
#include <internal/mcuxClMemory_XOR_Internal.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup clBufferUsage Buffer read/write functionality
 * @brief Buffer read/write functionality.
 * @ingroup mcuxClBuffer
 */

/**
 * @brief Perform a read from the buffer
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param      offset     Offset into the buffer at which the read operation shall start.
 * @param[out] pDst       Pointer to the memory location where the data will be stored.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @post
 *  -  Data Integrity: Expunge(pDst + bufSrc + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_read);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDst, &bufSrc[offset], byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_read,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}

/**
 * @brief Perform a read and XOR from the buffer
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param[in]  offset     Offset that allows to access at the right index of bufSrc.
 * @param[in]  pSrc       Pointer to the memory location where data shall be xored.
 * @param[out] pDst       Pointer to the memory location where the data will be stored.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @post
 *  - Data Integrity: Expunge(pDst + bufSrc + offset + pSrc + byteLength) -> done in MCUXCLMEMORY_XOR_INT function.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_readAndXor)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_readAndXor(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t* pSrc, uint8_t* pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_readAndXor);

  MCUXCLMEMORY_XOR_INT(pDst, (const uint8_t *)&bufSrc[offset], (const uint8_t *)pSrc, byteLength);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_readAndXor,
    MCUXCLMEMORY_XOR_INT_FP_EXPECT
  );
}

/**
 * @brief Perform a word-wise read from the buffer
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param      offset     Offset into the buffer at which the read operation shall start.
 * @param[out] pDst       Pointer to the aligned memory location where the data will be stored.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @pre
 *  - pDst must be 32-bit aligned.
 * @post
 *  - Data Integrity: Expunge(pDst + bufSrc + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read_word)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read_word(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_read_word);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDst, &bufSrc[offset], byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_read_word,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}

/**
 * @brief Perform a read with endianess reversal from the buffer
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param      offset     Offset into the buffer at which the read operation shall start.
 * @param[out] pDst       Pointer to the memory location where the data will be stored.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @post
 *  - Data Integrity: Expunge(pDst + bufSrc + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read_reverse)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read_reverse(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_read_reverse);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(pDst, &bufSrc[offset], byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_read_reverse,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int));
}

/**
 * @brief Perform a secure read from the buffer
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param      offset     Offset into the buffer at which the read operation shall start.
 * @param[out] pDst       Pointer to the memory location where the data will be stored.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @post
 *  -  Data Integrity: Expunge(pDst + bufSrc + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read_secure)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read_secure(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_read_secure);

  MCUXCLMEMORY_COPY_SECURE_INT(pDst, &bufSrc[offset], byteLength);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_read_secure, MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT);
}

/**
 * @brief Perform a secure read with endianess reversal from the buffer
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param      offset     Offset into the buffer at which the read operation shall start.
 * @param[out] pDst       Pointer to the memory location where the data will be stored.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @post
 *  -  Data Integrity: Expunge(pDst + bufSrc + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read_secure_reverse)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read_secure_reverse(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_read_secure_reverse);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(pDst, &bufSrc[offset], byteLength);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_read_secure_reverse,
    MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT
  );
}

#ifdef MCUXCLBUFFER_FEATURE_INTERNAL_READ_NO_DEST_INC
/**
 * @brief Write to a SFR register from an input buffer.
 *
 * @param[in]  bufSrc     Input buffer from which the data shall be read.
 * @param      offset     Offset into the buffer at which the read operation shall start.
 * @param[out] pDst       Pointer to the register location where the data will be written.
 *                        This address is not incremented during the whole execution of the function.
 * @param      byteLength Amount of bytes that will be read.
 *
 * @pre
 *  - pDst must be 32-bit aligned.
 *  - Depending on the length and on the alignment of source address, this function might write byte-wisely to the target SFR.
 *    If word access shall be ensured, the addresses shall be aligned and the length shall be a multiple of 4 (CPU word size).
 * @post
 *  - Data Integrity: Expunge(pDst + bufSrc + byteLength + offset)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_read_withoutDestIncrement)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_read_withoutDestIncrement(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *pDst, uint32_t byteLength)
#endif /* MCUXCLBUFFER_FEATURE_INTERNAL_READ_NO_DEST_INC */

/**
 * @brief Perform a write to the buffer
 *
 * @param[out] bufDst     Output buffer to which the data shall be written.
 * @param      offset     Offset into the buffer at which the write operation shall start.
 * @param[in]  pSrc       Pointer to the memory location from where the data will be read.
 * @param      byteLength Amount of bytes that will be written.
 *
 * @post
 *  -  Data Integrity: Expunge(pSrc + bufDst + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_write)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_write(mcuxCl_Buffer_t bufDst, uint32_t offset, const uint8_t *pSrc, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_write);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(&bufDst[offset], pSrc, byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_write,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}

/**
 * @brief Perform a word-wise write to the buffer
 *
 * @param[out] bufDst     Output buffer to which the data shall be written.
 * @param      offset     Offset into the buffer at which the write operation shall start.
 * @param[in]  pSrc       Pointer to the aligned memory location from where the data will be read.
 * @param      byteLength Amount of bytes that will be written.
 *
 * @pre
 *  - pSrc must be 32-bit aligned.
 * @post
 *  - Data Integrity: Expunge(pSrc + bufDst + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_write_word)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_write_word(mcuxCl_Buffer_t bufDst, uint32_t offset, const uint8_t *pSrc, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_write_word);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(&bufDst[offset], pSrc, byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_write_word,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
}

/**
 * @brief Perform a write with endianess reversal to the buffer
 *
 * @param[out] bufDst     Output buffer to which the data shall be written.
 * @param      offset     Offset into the buffer at which the write operation shall start.
 * @param[in]  pSrc       Pointer to the memory location from where the data will be read.
 * @param      byteLength Amount of bytes that will be written.
 *
 * @post
 *  - Data Integrity: Expunge(pSrc + bufDst + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_write_reverse)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_write_reverse(mcuxCl_Buffer_t bufDst, uint32_t offset, const uint8_t *pSrc, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_write_reverse);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_reversed_int(&bufDst[offset], pSrc, byteLength));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_write_reverse,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_reversed_int));
}

/**
 * @brief Perform a secure write to the buffer
 *
 * @param[out] bufDst     Output buffer to which the data shall be written.
 * @param      offset     Offset into the buffer at which the write operation shall start.
 * @param[in]  pSrc       Pointer to the memory location from where the data will be read.
 * @param      byteLength Amount of bytes that will be written.
 *
 * @post
 *  - Data Integrity: Expunge(pSrc + bufDst + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_write_secure)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_write_secure(mcuxCl_Buffer_t bufDst, uint32_t offset, const uint8_t *pSrc, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_write_secure);

  MCUXCLMEMORY_COPY_SECURE_INT(&bufDst[offset], pSrc, byteLength);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_write_secure, MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT);
}

/**
 * @brief Perform a secure write with endianess reversal to the buffer
 *
 * @param[out] bufDst     Output buffer to which the data shall be written.
 * @param      offset     Offset into the buffer at which the write operation shall start.
 * @param[in]  pSrc       Pointer to the memory location from where the data will be read.
 * @param      byteLength Amount of bytes that will be written.
 *
 * @post
 *  - Data Integrity: Expunge(pSrc + bufDst + offset + byteLength)
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_write_secure_reverse)
static inline ALWAYS_INLINE MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClBuffer_write_secure_reverse(mcuxCl_Buffer_t bufDst, uint32_t offset, const uint8_t *pSrc, uint32_t byteLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClBuffer_write_secure_reverse);

  MCUXCLMEMORY_COPY_SECURE_REVERSE_INT(&bufDst[offset], pSrc, byteLength);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClBuffer_write_secure_reverse,
    MCUXCLMEMORY_COPY_SECURE_REVERSE_INT_FP_EXPECT
  );
}

/**
 * @brief Writes the pointer of @p bufSrc plus the @p offset in @p ppDest.
 *
 * @param[in]  bufSrc      Input buffer
 * @param      offset      Offset of the input buffer
 * @param      bufCpuWa    Not used
 * @param[out] ppDest      Pointer-pointer to the destination address
 * @param      byteLength  Not used
 *
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClBuffer_inputBufferToCPU)
static inline ALWAYS_INLINE void mcuxClBuffer_inputBufferToCPU(mcuxCl_InputBuffer_t bufSrc, uint32_t offset, uint8_t *bufCpuWa UNUSED_PARAM, const uint8_t **ppDest, uint32_t byteLength UNUSED_PARAM)
{
  *ppDest = (const uint8_t *)bufSrc + offset;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLBUFFER_INTERNAL_POINTER_H_ */
