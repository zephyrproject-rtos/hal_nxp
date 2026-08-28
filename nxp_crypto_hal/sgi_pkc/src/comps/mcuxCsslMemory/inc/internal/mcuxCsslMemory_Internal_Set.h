/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxCsslMemory_Internal_Set.h
 * @brief header file of internal memory set function
 */


#ifndef MCUXCSSLMEMORY_INTERNAL_SET_H_
#define MCUXCSSLMEMORY_INTERNAL_SET_H_


#include <stdint.h>
#include <stddef.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslParamIntegrity.h>

/**
 * @defgroup mcuxCsslMemory_Int_Set_Functions mcuxCsslMemory_Int_Set Function Definitions
 * @brief mcuxCsslMemory_Int_Set Function Definitions
 *
 * @ingroup mcuxCsslMemory_Int_Set
 * @{
 */


/**
 * @brief Set @p length bytes of data at @p pDst.
 *
 * The implementation is robust against fault attacks.
 *
 * @post
 *  - Data Integrity: Expunge(pDst + length)
 *
 * @param[in]  pDst         The destination pointer to buffer to be set. Must not be NULL.
 * @param[in]  val          The byte value to be set.
 * @param[in]  length       The size in bytes to set.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslMemory_Int_Set)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxCsslMemory_Int_Set
(
    uint8_t * pDst,
    uint8_t val,
    uint32_t length
);


#endif /* MCUXCSSLMEMORY_INTERNAL_SET_H_ */
