/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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

/** @file  mcuxClMemory_CopySecure_Internal.h
 *  @brief Memory header for copy functions.
 * This header exposes functions that enable secure memory copy function.
 */

/**
 * @defgroup mcuxClMemory_Copy_Secure_Internal mcuxClMemory_Copy_Secure_Internal
 * @brief This function securely copies a memory region from @p src to @p dst when a secure copy is available.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_COPYSECURE_INTERNAL_H_
#define MCUXCLMEMORY_COPYSECURE_INTERNAL_H_

#include <mcuxClConfig.h>  // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslFlowProtection.h>
#if defined(MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY)
#include <mcuxCsslMemory.h>
#include <internal/mcuxCsslMemory_Internal_SecureCopy.h>
#else
#include <internal/mcuxClMemory_Copy_Internal.h>
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY */

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief Copies a memory buffer to another location with security against fault and SPA - internal use only.
 *  
 * @param[out] pDst        pointer to the buffer to be copied to.
 * @param[in]  pSrc        pointer to the buffer to copy.
 * @param      length      size (in bytes) to be copied.
 * 
 * @pre
 *  - @p pDst and @p pSrc must not overlap.
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pSrc + pDst + length)
 *
 * @return void
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_copy_secure_int)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_copy_secure_int
(
    uint8_t * pDst,
    uint8_t const * pSrc,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_copy_secure_int);

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecCopy(pDst, pSrc, length));
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_copy_secure_int, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecCopy));
#else
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDst, pSrc, length));
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_copy_secure_int, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int));
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY */
}

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY
#define MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecCopy))
#define MCUXCLMEMORY_COPY_SECURE_INT(pDst, pSrc, length)                            \
  do {                                                                             \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_SecCopy(pDst, pSrc, length)); \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()       \
  } while(false)                                                                   \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()
#else
#define MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int))
#define MCUXCLMEMORY_COPY_SECURE_INT(pDst, pSrc, length)                       \
  do {                                                                        \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pDst, pSrc, length)); \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()  \
  } while(false)                                                              \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COPY */  

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_COPYSECURE_INTERNAL_H_ */

/**
 * @}
 */
