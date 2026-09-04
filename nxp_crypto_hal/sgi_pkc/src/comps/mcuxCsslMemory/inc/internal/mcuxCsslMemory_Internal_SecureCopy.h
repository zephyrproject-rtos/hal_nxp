/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxCsslMemory_Internal_SecureCopy.h
 * @brief Internal header of mcuxCsslMemory_Int_SecCopy(Rev)
 */

#ifndef MCUXCSSLMEMORY_INTERNAL_SECURECOPY_H
#define MCUXCSSLMEMORY_INTERNAL_SECURECOPY_H

#include <stdint.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslMemory_Types.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief securely copy byte string - internal use only
 * 
 * This function securely copies byte string of the given length from source
 * to target. It assumes there is no overlapping between buffers at source
 * and target.
 * 
 * @param[out] pTarget  destination address
 * @param[in]  pSource  source address
 * @param      length   byte length of the string to be copied
 * 
 * @pre
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pTarget + pSource + length)
 *
 * @return void
 */
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxCsslMemory_Int_SecCopy(
    uint8_t * pTarget,
    const uint8_t * pSource,
    uint32_t length
    );

/**
 * @brief securely copy byte string, with reversed byte order - internal use only
 * 
 * This function securely copies byte string of the given length from source
 * to target, with reversed byte order. It assumes there is no overlapping
 * between buffers at source and target.
 * 
 * @param[out] pTarget  destination address
 * @param[in]  pSource  source address
 * @param      length   byte length of the string to be copied
 * 
 * @pre
 *  - For better performance and security, please use aligned pointers, and lengths multiple of word size.
 * @post
 *  - Data Integrity: Expunge(pTarget + pSource + length)
 *
 * @return void
 */
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxCsslMemory_Int_SecCopyRev(
    uint8_t * pTarget,
    const uint8_t * pSource,
    uint32_t length
    );


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCSSLMEMORY_INTERNAL_SECURECOPY_H */
