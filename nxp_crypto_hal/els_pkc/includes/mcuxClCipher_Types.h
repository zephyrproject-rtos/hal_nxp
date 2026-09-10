/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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

/** @file  mcuxClCipher_Types.h
 *  @brief Type definitions for the mcuxClCipher component
 */

#ifndef MCUXCLCIPHER_TYPES_H_
#define MCUXCLCIPHER_TYPES_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClCipher_Types mcuxClCipher_Types
 * @brief Types used by the Cipher operations.
 * @ingroup mcuxClCipher
 * @{
 */

/**
 * @brief Cipher mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Cipher interfaces need
 * to know about a particular Cipher mode/algorithm.
 */
struct mcuxClCipher_ModeDescriptor;

/**
 * @brief Cipher mode/algorithm descriptor type
 *
 * This type captures all the information that the Cipher interfaces need to
 * know about a particular Cipher mode/algorithm.
 */
typedef struct mcuxClCipher_ModeDescriptor mcuxClCipher_ModeDescriptor_t;

/**
 * @brief Cipher mode/algorithm type
 *
 * This type is used to refer to a Cipher mode/algorithm.
 */
typedef const mcuxClCipher_ModeDescriptor_t * const mcuxClCipher_Mode_t;

/**
 * @brief Cipher selftest mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Cipher selftest interfaces need
 * to know about a particular Cipher selftest mode/algorithm.
 */
struct mcuxClCipher_TestDescriptor;

/**
 * @brief Cipher selftest mode/algorithm descriptor type
 *
 * This type captures all the information that the Cipher selftest interfaces need to
 * know about a particular Cipher selftest mode/algorithm.
 */
typedef struct mcuxClCipher_TestDescriptor mcuxClCipher_TestDescriptor_t;

/**
 * @brief Cipher selftest mode/algorithm type
 *
 * This type is used to refer to a Cipher selftest mode/algorithm.
 */
typedef const mcuxClCipher_TestDescriptor_t * const mcuxClCipher_Test_t;

/**
 * @brief Cipher context structure
 *
 * This structure is used in the multi-part interfaces to store the
 * information about the current operation and the relevant internal state.
 */
struct mcuxClCipher_Context;

/**
 * @brief Cipher context type
 *
 * This type is used in the multi-part interfaces to store the information
 * about the current operation and the relevant internal state.
 */
typedef struct mcuxClCipher_Context mcuxClCipher_Context_t;

/**
 * @brief Cipher status code
 *
 * This type provides information about the status of the Cipher operation that
 * has been performed.
 */
typedef uint32_t mcuxClCipher_Status_t;

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLCIPHER_TYPES_H_ */
