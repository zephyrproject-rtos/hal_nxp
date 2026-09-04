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

/** @file  mcuxClMemory_XORSecureWithConst_Internal.h
 *  @brief Memory header for secure XOR with const function.
 * This header exposes functions that enable secure memory XOR with const function.
 */

/**
 * @defgroup mcuxClMemory_XOR_Secure_With_Const_Internal mcuxClMemory_XOR_Secure_With_Const_Internal
 * @brief This function performs XOR of a memory buffer with const in a secure way
 * when a secure XOR is available.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_XORSECUREWITHCONST_INTERNAL_H_
#define MCUXCLMEMORY_XORSECUREWITHCONST_INTERNAL_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR
#include <internal/mcuxCsslMemory_Internal_SecureXOR.h>
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR */

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief This function XORs data from @p pSrc with a 1-byte @p byteConstant in a secure way
 *        and stores the result in @p pDst - internal use only.
 *
 * @param[out] pDst         pointer to the destination buffer.
 * @param[in]  pSrc         pointer to the source buffer. Can be equal to pTarget if the length is a multiple of 4
 * @param      byteConstant 1-byte constant.
 * @param      length       size (in bytes) to be operated.
 * 
 * @pre
 *  - if @p pDst overlaps with @p pSrc then @p length must be a multiple of 4
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pDst + pSrc + length)
 *
 * @return void
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_XORWithConst_secure_int)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_XORWithConst_secure_int
(
    uint8_t *pDst,
    const uint8_t *pSrc,
    const uint8_t byteConstant,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_XORWithConst_secure_int);
#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecXORWithConst(pDst, pSrc, byteConstant, length));
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_XORWithConst_secure_int, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecXORWithConst));
#else
    MCUX_CSSL_DI_EXPUNGE(xorParamsDst /* Not used */, (uint32_t) pDst);
    MCUX_CSSL_DI_EXPUNGE(xorParamsSrc /* Not used */, (uint32_t) pSrc);
    MCUX_CSSL_DI_EXPUNGE(xorParamsLength /* Not used */, (uint32_t) length);
    for(uint32_t i = 0u; i < length; ++i)
    {
        pDst[i] = pSrc[i] ^ byteConstant;
    }
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_XORWithConst_secure_int);
#endif /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR */
}

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR
#define MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecXORWithConst))
#define MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pDst, pSrc, byteConstant, length)                          \
  do {                                                                                                   \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecXORWithConst(pDst, pSrc, byteConstant, length)); \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()                             \
  } while(false)                                                                                         \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()
#else
#define MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT_FP_EXPECT 0U
#define MCUXCLMEMORY_SECURE_XOR_WITH_CONST_INT(pDst, pSrc, byteConstant, length) \
  do {                                                                          \
    MCUX_CSSL_DI_EXPUNGE(xorParamsDst /* Not used */, (uint32_t)(pDst));         \
    MCUX_CSSL_DI_EXPUNGE(xorParamsSrc /* Not used */, (uint32_t)(pSrc));         \
    MCUX_CSSL_DI_EXPUNGE(xorParamsLength /* Not used */, (uint32_t)(length));    \
    for(uint32_t i = 0u; i < (length); ++i)                                     \
    {                                                                           \
        (pDst)[i] = (pSrc)[i] ^ (byteConstant);                                 \
    }                                                                           \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()    \
  } while(false)                                                                \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()
#endif /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_XOR */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_XORSECUREWITHCONST_INTERNAL_H_ */

/**
 * @}
 */
