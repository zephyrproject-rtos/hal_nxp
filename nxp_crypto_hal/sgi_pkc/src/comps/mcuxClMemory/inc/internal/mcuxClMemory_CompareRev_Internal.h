/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/** @file  mcuxClMemory_Compare_Internal.h
 *  @brief Memory header for internal compare function.
 * This header exposes functions that enable memory compare function.
 */

/**
 * @defgroup mcuxClMemory_Compare_Internal mcuxClMemory_Compare_Internal
 * @brief This function compares two memory region @p lhs and @p rhs.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_COMPAREREV_INTERNAL_H_
#define MCUXCLMEMORY_COMPAREREV_INTERNAL_H_

#include <mcuxClConfig.h>  // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClMemory_Constants.h>
#include <mcuxClMemory_Types.h>
#include <mcuxCsslMemory.h>
#include <internal/mcuxCsslMemory_Internal_CompareRev_arm_asm.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * FUNCTIONS
 **********************************************/

/**
 * @brief Compares two memory buffer with security against faults - internal use only.
 * IMPORTANT: This function should not be used with secret input parameters.
 *
 * @param[in]  pLhs        pointer to the left buffer to be compared.
 * @param[in]  pRhs        pointer to the right buffer to be compared.
 * @param      length      size (in bytes) to be compared.
 *
 * @pre
 *  - For better performance, please use aligned pointers, and lengths multiple of word size.
 * @post
 * - Data Integrity: Record(status) + Expunge(pLhs + pRhs + length)
 *
 * @return A status code encapsulated in a flow-protection type.
 * @retval #MCUXCLMEMORY_STATUS_EQUAL                 If length bytes of Lhs and Rhs are equal.
 * @retval #MCUXCLMEMORY_STATUS_NOT_EQUAL             If at least one byte differs between the two.
 * @retval #MCUXCLMEMORY_STATUS_FAULT                 A fault attack occured.
 */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMemory_compare_reversed_int)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMemory_Status_t) mcuxClMemory_compare_reversed_int
(
    const uint8_t * pLhs,
    const uint8_t * pRhs,
    uint32_t length
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMemory_compare_reversed_int);

    mcuxClMemory_Status_t retval = MCUXCLMEMORY_STATUS_FAULT;

    retval = MCUXCLMEMORY_STATUS_EQUAL;
    for (uint32_t i = 0u; i < length; ++i)
    {
        if (pLhs[i] != pRhs[i])
        {
            retval = MCUXCLMEMORY_STATUS_NOT_EQUAL;
        }
    }
    MCUX_CSSL_DI_EXPUNGE(identifier /* Not used */, (uint32_t) pLhs + (uint32_t) pRhs + length);  // Balance the SC
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMemory_compare_reversed_int, retval);
}


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMEMORY_COMPAREREV_INTERNAL_H_ */

/**
 * @}
 */
