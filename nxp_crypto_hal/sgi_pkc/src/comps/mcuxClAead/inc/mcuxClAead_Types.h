/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023 NXP                                            */
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

/** @file  mcuxClAead_Types.h
 *  @brief Type definitions for the mcuxClAead component
 */

#ifndef MCUXCLAEAD_TYPES_H_
#define MCUXCLAEAD_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <mcuxClSession.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClAead_Types mcuxClAead_Types
 * @brief Types used by the AEAD operations.
 * @ingroup mcuxClAead
 * @{
 */

/**
 * @brief AEAD mode/algorithm descriptor structure
 *
 * This structure captures all the information that the AEAD interfaces need
 * to know about a particular AEAD mode/algorithm.
 */
struct mcuxClAead_ModeDescriptor;

/**
 * @brief AEAD mode/algorithm descriptor type
 *
 * This type captures all the information that the AEAD interfaces need to
 * know about a particular AEAD mode/algorithm.
 */
typedef struct mcuxClAead_ModeDescriptor mcuxClAead_ModeDescriptor_t;


/**
 * @brief AEAD mode/algorithm type
 *
 * This type is used to refer to an AEAD mode/algorithm.
 */
typedef const mcuxClAead_ModeDescriptor_t * const mcuxClAead_Mode_t;

/**
 * @brief Aead selftest mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Aead selftest interfaces need
 * to know about a particular Aead selftest mode/algorithm.
 */
struct mcuxClAead_TestDescriptor;

/**
 * @brief Aead selftest mode/algorithm descriptor type
 *
 * This type captures all the information that the Aead selftest interfaces need
 * to know about a particular Aead selftest mode/algorithm.
 */
typedef struct mcuxClAead_TestDescriptor mcuxClAead_TestDescriptor_t;

/**
 * @brief Aead selftest mode/algorithm type
 *
 * This type is used to refer to a Aead selftest mode/algorithm.
 */
typedef const mcuxClAead_TestDescriptor_t * const mcuxClAead_Test_t;

/**
 * @brief AEAD context structure
 *
 * This structure is used in the multi-part interfaces to store the
 * information about the current operation and the relevant internal state.
 */
struct mcuxClAead_Context;

/**
 * @brief AEAD context type
 *
 * This type is used in the multi-part interfaces to store the information
 * about the current operation and the relevant internal state.
 */
typedef struct mcuxClAead_Context mcuxClAead_Context_t;

/**
 * @brief AEAD status code
 *
 * This type provides information about the status of the AEAD operation that
 * has been performed.
 */
typedef uint32_t mcuxClAead_Status_t;

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAEAD_TYPES_H_ */
