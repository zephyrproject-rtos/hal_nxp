/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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

/** @file  mcuxClHash_Types.h
 *  @brief Type definitions for the mcuxClHash component
 */

#ifndef MCUXCLHASH_TYPES_H_
#define MCUXCLHASH_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClHash_Types mcuxClHash_Types
 * @brief Defines all types of the @ref mcuxClHash component
 * @ingroup mcuxClHash
 * @{
 */

/**
 * @brief Hash mode/algorithm descriptor type
 *
 * This type captures all the information that the Hash interfaces need to
 * know about a particular Hash mode/algorithm.
 *
 */
typedef struct mcuxClHash_AlgorithmDescriptor mcuxClHash_AlgorithmDescriptor_t;

/**
 * @brief Hash mode/algorithm type
 *
 * This type is used to refer to a Hash mode/algorithm.
 *
 */
typedef const mcuxClHash_AlgorithmDescriptor_t * const mcuxClHash_Algo_t;

#if defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE)
/**
 * @brief Hash mode/algorithm type
 *
 * This type is used to refer to a custom Hash mode/algorithm that
 * can be created via a provided constructor.
 */
typedef mcuxClHash_AlgorithmDescriptor_t * const mcuxClHash_Algo_Custom_t;
#endif /* defined(MCUXCL_FEATURE_HASH_C_SHA3_SHAKE) */

#ifdef MCUXCL_FEATURE_HASH_SELFTEST
/**
 * @brief Hash selftest mode/algorithm descriptor type
 *
 * This type captures all the information that the hash selftest interfaces need to
 * know about a particular Hash selftest mode/algorithm.
 */
typedef struct mcuxClHash_TestDescriptor mcuxClHash_TestDescriptor_t;

/**
 * @brief Hash selftest mode/algorithm type
 *
 * This type is used to refer to a Hash selftest mode/algorithm.
 */
typedef const mcuxClHash_TestDescriptor_t * const mcuxClHash_Test_t;

#endif /* MCUXCL_FEATURE_HASH_SELFTEST */

/**
 * @brief Hash Context buffer type
 *
 * This type is used in the streaming interfaces to store the information
 * about the current operation and the relevant internal state.
 *
 * Note: A copy of the Hash context to another memory location is only supported if both source and destination addresses have the same 64 bit alignment.
 * This requirement can be ignored when using mcuxClHash_export_state and mcuxClHash_import_state to move a Hash context.
 *
 */
typedef struct mcuxClHash_ContextDescriptor mcuxClHash_ContextDescriptor_t;

/**
 * @brief Hash Context type
 *
 * This type is used to refer to the Hash context.
 *
 */
typedef mcuxClHash_ContextDescriptor_t * mcuxClHash_Context_t;

/**
 * @brief Hash Status type
 *
 * This type is used for hash return values: \ref mcuxClHashStatusValues
 *
 */
typedef uint32_t mcuxClHash_Status_t;

/**@}*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASH_TYPES_H_ */
