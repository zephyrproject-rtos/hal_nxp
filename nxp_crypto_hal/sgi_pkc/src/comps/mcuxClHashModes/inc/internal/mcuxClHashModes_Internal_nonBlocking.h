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

/** @file  mcuxClHashModes_Internal_nonBlocking.h
 *  @brief Internal declarations for non blocking modes
 */

#ifndef MCUXCLHASHMODES_INTERNAL_NONBLOCKING_H_
#define MCUXCLHASHMODES_INTERNAL_NONBLOCKING_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClHash_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mcuxClHash_Sha2_Oneshot_Internal_IsrCtx
{
    mcuxCl_InputBuffer_t inputBuf;
    uint32_t inSize;
    uint32_t numberOfFullBlocks;
    mcuxCl_Buffer_t pOut;
    uint32_t *pOutSize;
    mcuxClHash_AlgorithmDescriptor_t * algorithm;
} mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t;


typedef struct mcuxClHash_Sha2_Multipart_Internal_IsrCtx
{
    mcuxCl_InputBuffer_t inputBuf;
    uint32_t inputOffset;
    uint32_t inSize;
    uint32_t numberOfFullBlocks;
    mcuxClHash_ContextDescriptor_t *ctx;
} mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t;


#define MCUXCLHASHMODES_INTERNAL_SHA2_ISR_CTX_SIZE_IN_WORDS MCUXCLCORE_MAX(MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Oneshot_Internal_IsrCtx_t)), MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(sizeof(mcuxClHash_Sha2_Multipart_Internal_IsrCtx_t)))

#define MCUXCLHASHMODES_INTERNAL_SHA2_ISR_CTX_SIZE (MCUXCLHASHMODES_INTERNAL_SHA2_ISR_CTX_SIZE_IN_WORDS * sizeof(uint32_t))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_INTERNAL_NONBLOCKING_H_ */
