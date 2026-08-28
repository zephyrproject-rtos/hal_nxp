/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023, 2025 NXP                                           */
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
 * @file  mcuxCsslMemory_Copy.h
 * @brief Include file for memory copy function
 */

#ifndef MCUXCSSLMEMORY_COPY_H_
#define MCUXCSSLMEMORY_COPY_H_

#include <mcuxCsslMemory_Types.h>
#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>

/**
 * @defgroup mcuxCsslMemory_Copy mcuxCssl Memory Copy
 * @brief Control Flow Protected Memory Copy Function
 *
 * @ingroup mcuxCsslMemory
 * @{
 */

/**
 * @defgroup mcuxCsslMemory_Copy_Functions mcuxCsslMemory_Copy Function Definitions
 * @brief mcuxCsslMemory_Copy Function Definitions
 *
 * @ingroup mcuxCsslMemory_Copy
 * @{
 */

/**
 * @brief Copies @p length bytes of data from @p pSrc to @p pDst
 *
 * The implementation is secure in the following aspects:
 *
 * * Constant execution time: If @p pSrc and @p pDst have the same offset to the nearest 16-byte boundary, and if @p length
 *     is the same, the execution sequence of the code is always identical.
 * * Parameter integrity protection: An incorrect parameter checksum makes the function return immediately.
 * * Code flow protection: The function call is protected. Additionally, the result depends on all steps of the calculation.
 * * Buffer overflow protection: No data is written to @p pDst beyond @p dstLength bytes.
 *
 * @param[in]     chk        The parameter checksum, generated with #MCUX_CSSL_PI_PROTECT.
 * @param[in]     pSrc       The data to be copied. Must not be NULL. Must not overlap with @p pDst.
 * @param[out]    pDst       The destination pointer. Must not be NULL. Must not overlap with @p pSrc.
 * @param[in]     dstLength  The size of the destination data buffer in bytes.
 * @param[in]     length     The number of bytes to copy.
 * @return A status code encapsulated in a flow-protection type.
 * @retval #MCUXCSSLMEMORY_STATUS_OK If the operation was successful.
 * @retval #MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER If one of the parameters was invalid (i.e. @p pSrc or @p pDst was NULL or @p length was zero).
 * @retval #MCUXCSSLMEMORY_STATUS_FAULT If a fault was detected.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslMemory_Copy)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslMemory_Status_t) mcuxCsslMemory_Copy
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    void const * pSrc,
    void * pDst,
    uint32_t dstLength,
    uint32_t length
);

/**
 * @}
 */

/**
 * @}
 */

#endif /* MCUXCSSLMEMORY_COPY_H_ */
