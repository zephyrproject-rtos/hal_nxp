/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2025 NXP                                       */
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

/** @file  mcuxClMemory_Clear_Internal.h
 *  @brief Memory header for clear function.
 * This header exposes functions that enable using memory clear function.
 */


/**
 * @defgroup mcuxClMemory_Clear_Internal mcuxClMemory_Clear_Internal
 * @brief This function clears a memory region.
 * @ingroup mcuxClMemory
 * @{
 */


#ifndef MCUXCLMEMORY_CLEAR_INTERNAL_H_
#define MCUXCLMEMORY_CLEAR_INTERNAL_H_

#include <mcuxClConfig.h>  // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>
#include <mcuxClToolchain.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxCsslMemory_Internal_Set.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief Clears all bytes of the memory buffer - internal use only.
 *
 * @param[out]  pDst       pointer to the buffer to be set.
 * @param       length     size (in bytes) to be set.
 *
 * @pre
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pDst + length)
 *
 * @return void
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_clear_int)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMemory_clear_int
(
    uint8_t * pDst,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_clear_int);

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_Set( pDst, 0U, length));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMemory_clear_int, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_Set));
}

#define MCUXCLMEMORY_CLEAR_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_Set))
#define MCUXCLMEMORY_CLEAR_INT(pDst, length) \
  do { \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxCsslMemory_Int_Set(pDst, 0U, length)); \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
  } while(false)                                                             \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_CLEAR_INTERNAL_H_ */

/**
 * @}
 */
