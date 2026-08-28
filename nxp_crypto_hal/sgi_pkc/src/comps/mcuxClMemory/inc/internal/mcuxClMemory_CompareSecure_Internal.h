/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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

/** @file  mcuxClMemory_CompareSecure_Internal.h
 *  @brief Memory header for compare function.
 * This header exposes functions that enable secure memory compare function.
 */

/**
 * @defgroup mcuxClMemory_Compare_Internal mcuxClMemory_Compare_Secure_Internal
 * @brief This function compares two memory region @p lhs and @p rhs.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_COMPARE_SECURE_INTERNAL_H_
#define MCUXCLMEMORY_COMPARE_SECURE_INTERNAL_H_

#include <mcuxClConfig.h>  // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>
#include <mcuxCsslFlowProtection.h>
#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE
#include <mcuxCsslMemory.h>
#include <internal/mcuxCsslMemory_Internal_SecureCompare_arm_asm.h>
#else
#include <internal/mcuxClMemory_Compare_Internal.h>
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE */

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief Compares two memory buffers with security against fault and SPA - internal use only.
 *  
 * @param[in]  pLhs        pointer to the left buffer to be compared.
 * @param[in]  pRhs        pointer to the right buffer to be compared.
 * @param      length      size (in bytes) to be compared.
 * 
 * @pre
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pLhs + pRhs + length)
 *
 * @return A status code encapsulated in a flow-protection type.
 * @retval #MCUXCLMEMORY_STATUS_EQUAL                 If length bytes of Lhs and Rhs are equal.
 * @retval #MCUXCLMEMORY_STATUS_NOT_EQUAL             If at least one byte differs between the two.
 * @retval #MCUXCLMEMORY_STATUS_FAULT
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_compare_secure_int)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMemory_Status_t) mcuxClMemory_compare_secure_int
(
    const uint8_t * pLhs,
    const uint8_t * pRhs,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_compare_secure_int);

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE
    mcuxClMemory_Status_t retval = MCUXCLMEMORY_STATUS_FAULT;

    MCUX_CSSL_FP_FUNCTION_CALL(csslRetval, mcuxCsslMemory_Int_SecComp_arm_asm(pLhs, pRhs, length));

    /* translate mcuxCsslMemory_Status_t -> mcuxClMemory_Status_t */
    retval = (mcuxClMemory_Status_t) csslRetval ^ (MCUXCSSLMEMORY_COMPONENT_MASK ^ MCUXCLMEMORY_COMPONENT_MASK);

    /* Record mcuxClMemory status and expunge mcuxCssl status, since it's internal */
    /* TODO CLNS-17727: add expunge(status) after all calls to this function and uncomment here */
    /* MCUX_CSSL_DI_RECORD(memoryRet, retval); */
    MCUX_CSSL_DI_EXPUNGE(csslMemoryRet, csslRetval);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMemory_compare_secure_int, retval, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecComp_arm_asm));
#else
    MCUX_CSSL_FP_FUNCTION_CALL(retClCompare, mcuxClMemory_compare_int(pLhs, pRhs, length));
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMemory_compare_secure_int, retClCompare, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_compare_int));
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE */
}

#ifdef MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE
#define MCUXCLMEMORY_COMPARE_SECURE_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Int_SecComp_arm_asm))
#define MCUXCLMEMORY_COMPARE_SECURE_INT(retval, pLhs, pRhs, length)                                            \
  do {                                                                                                        \
    MCUX_CSSL_FP_FUNCTION_CALL(csslRetval, mcuxCsslMemory_Int_SecComp_arm_asm(pLhs, pRhs, length));             \
    MCUX_CSSL_DI_EXPUNGE(csslMemoryRet, csslRetval);                                                           \
    retval = (mcuxClMemory_Status_t) csslRetval ^ (MCUXCSSLMEMORY_COMPONENT_MASK ^ MCUXCLMEMORY_COMPONENT_MASK); \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()                                  \
  } while(false)                                                                                              \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()
#else
#define MCUXCLMEMORY_COMPARE_SECURE_INT_FP_EXPECT (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_compare_int))
#define MCUXCLMEMORY_COMPARE_SECURE_INT(retval, pLhs, pRhs, length)                      \
  do {                                                                                  \
    MCUX_CSSL_FP_FUNCTION_CALL(csslRetval, mcuxClMemory_compare_int(pLhs, pRhs, length)); \
    retval = (mcuxClMemory_Status_t) csslRetval;                                         \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()            \
  } while(false)                                                                        \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()
#endif  /* MCUXCL_FEATURE_CSSL_MEMORY_ARM_SECURE_COMPARE */  

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_COMPARE_SECURE_INTERNAL_H_ */

/**
 * @}
 */
