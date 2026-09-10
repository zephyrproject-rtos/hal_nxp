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

#ifndef MCUXCLSIGNATURE_TYPES_H_
#define MCUXCLSIGNATURE_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mcuxClSignature_Types mcuxClSignature_Types
 * \brief Types used by the Signature operations.
 * \ingroup mcuxClSignature
 * @{
 */

/**
 * \brief Signature mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Signature interfaces need
 * to know about a particular Signature mode/algorithm.
 */
struct mcuxClSignature_ModeDescriptor;

/**
 * \brief Signature mode/algorithm descriptor type
 *
 * This type captures all the information that the Signature interfaces need
 * to know about a particular Signature mode/algorithm.
 */
typedef struct mcuxClSignature_ModeDescriptor mcuxClSignature_ModeDescriptor_t;

/**
 * \brief Signature mode/algorithm type
 *
 * This type is used to refer to a Signature mode/algorithm.
 */
typedef const mcuxClSignature_ModeDescriptor_t * const mcuxClSignature_Mode_t;

/**
 * \brief Signature selftest mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Signature selftest interfaces need
 * to know about a particular Signature selftest mode/algorithm.
 */
struct mcuxClSignature_TestDescriptor;

/**
 * \brief Signature selftest mode/algorithm descriptor type
 *
 * This type captures all the information that the Signature selftest interfaces need
 * to know about a particular Signature selftest mode/algorithm.
 */
typedef struct mcuxClSignature_TestDescriptor mcuxClSignature_TestDescriptor_t;

/**
 * \brief Signature selftest mode/algorithm type
 *
 * This type is used to refer to a Signature selftest mode/algorithm.
 */
typedef const mcuxClSignature_TestDescriptor_t * const mcuxClSignature_Test_t;

/**
 * \brief Signature context structure
 *
 * This structure is used in the multi-part interfaces to store the
 * information about the current operation and the relevant internal state.
 */
struct mcuxClSignature_Context;

/**
 * \brief Signature context type
 *
 * This type is used in the multi-part interfaces to store the information
 * about the current operation and the relevant internal state.
 */
typedef struct mcuxClSignature_Context mcuxClSignature_Context_t;

/**
 * \brief Signature status code
 *
 * This type provides information about the status of the Signature operation
 * that has been performed.
 */
typedef uint32_t mcuxClSignature_Status_t;

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSIGNATURE_TYPES_H_ */
