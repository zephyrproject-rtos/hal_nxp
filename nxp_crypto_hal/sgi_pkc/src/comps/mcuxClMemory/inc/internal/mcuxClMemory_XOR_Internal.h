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

/** @file  mcuxClMemory_XOR_Internal.h
 *  @brief Memory header for XOR function.
 * This header exposes functions that enable using memory XOR functions.
 */

/**
 * @defgroup mcuxClMemory_XOR_Internal mcuxClMemory_XOR_Internal
 * @brief This function XORs two byte strings of the given length and stores it in the target buffer.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_XOR_INTERNAL_H_
#define MCUXCLMEMORY_XOR_INTERNAL_H_

#include <mcuxClConfig.h>  // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxCsslMemory_Internal_XOR.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief This function XORs data from @p pSrc1 and @p pSrc2 and stores the result in @p pDst - internal use only.
 *
 * Operation in place is allowed - one of the input buffer can also be the output buffer.
 *
 * @param[out] pDst        pointer to the destination buffer.
 * @param[in]  pSrc1       pointer to the first source buffer. Can be equal to pDst.
 * @param[in]  pSrc2       pointer to the second source buffer. Can be equal to pDst.
 * @param      length      size (in bytes) to be operated
 * 
 * @pre
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pDst + pSrc1 + pSrc2 + length)
 *
 * @return void
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_XOR_int)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_XOR_int
(
    uint8_t *pDst,
    const uint8_t *pSrc1,
    const uint8_t *pSrc2,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_XOR_int);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_XOR(pDst, pSrc1, pSrc2, length));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_XOR_int, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_XOR));
}

#define MCUXCLMEMORY_XOR_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_XOR))
#define MCUXCLMEMORY_XOR_INT(pDst, pSrc1, pSrc2, length)                                \
  do {                                                                                 \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_XOR(pDst, pSrc1, pSrc2, length)); \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()           \
  } while(false)                                                                       \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_XOR_INTERNAL_H_ */

/**
 * @}
 */
