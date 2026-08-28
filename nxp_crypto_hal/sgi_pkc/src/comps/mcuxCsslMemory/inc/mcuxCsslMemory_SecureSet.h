/*--------------------------------------------------------------------------*/
/* Copyright 2023, 2025 NXP                                                 */
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
 * @file  mcuxCsslMemory_SecureSet.h
 * @brief header file of secure memory set function
 */


#ifndef MCUXCSSLMEMORY_SECURESET_H_
#define MCUXCSSLMEMORY_SECURESET_H_

#include <mcuxCsslMemory_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslParamIntegrity.h>

/**
 * @defgroup mcuxCsslMemory_SecureSet mcuxCssl Memory Set
 * @brief Control Flow Protected Memory Set Function
 *
 * @ingroup mcuxCsslMemory
 * @{
 */

/**
 * @defgroup mcuxCsslMemory_SecureSet_Functions mcuxCsslMemory_SecureSet Function Definitions
 * @brief mcuxCsslMemory_SecureSet Function Definitions
 *
 * @ingroup mcuxCsslMemory_SecureSet
 * @{
 */

/**
 * @brief Set @p length bytes of data at @p pDst
 *
 * The implementation is secure in the following aspects:
 * Parameter integrity protection: the function returns immediately in case of an incorrect parameter checksum.
 * Data is first overwritten with random data before being set to the new value
 * Code flow protection: the function call is protected.
 * Buffer overflow protection: no data is written to @p pDst beyond @p bufLength bytes.
 *
 * @param[in]  chk          The parameter checksum, generated with #MCUX_CSSL_PI_PROTECT.
 * @param[in]  pDst         The destination pointer to buffer to be set. Must not be NULL.
 * @param[in]  val          The byte value to be set. 
 * @param[in]  length       The size in bytes to set.
 * @param[in]  bufLength    The buffer size (if bufLength < length, only bufLength bytes are set).
 *
 * @return A status code encapsulated in a flow-protection type.
 * @retval #MCUXCSSLMEMORY_STATUS_OK                 If @p val set @p length times at @p pDst.
 * @retval #MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER  If one of the parameters is invalid.
 * @retval #MCUXCSSLMEMORY_STATUS_FAULT              If a fault was detected, included invalid checksum @p chk.
 * 
 * \implements{REQ_788365}
 *
 * @attention The function uses PRNG, which has to be available and ready for generation.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslMemory_SecureSet)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_SecureSet
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void * pDst,
    uint8_t val,
    uint32_t length,
    uint32_t bufLength
);

/**
 * @}
 */

/**
 * @}
 */

#endif /* MCUXCSSLMEMORY_SECURESET_H_ */
