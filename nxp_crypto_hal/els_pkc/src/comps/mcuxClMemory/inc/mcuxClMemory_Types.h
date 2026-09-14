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

/** @file  mcuxClMemory_Types.h
 *  @brief Memory type header.
 * This header exposes types used by the @ref mcuxClMemory functions. */

/**
 * @defgroup mcuxClMemory_Types mcuxClMemory_Types
 * @brief Defines all types used by the @ref mcuxClMemory functions.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_TYPES_H
#define MCUXCLMEMORY_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

/**********************************************
 * MACROS
 **********************************************/
/**
 * @defgroup mcuxClMemory_Types_Macros mcuxClMemory_Types_Macros
 * @brief Defines all macros of @ref mcuxClMemory_Types
 * @ingroup mcuxClMemory_Types
 * @{
 */
#define MCUXCLMEMORY_API extern  ///< Marks a function as a public API function of the mcuxClMemory component

/**
 * @}
 */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @brief Type for error codes of mcuxClMemory component functions.
 * 
 * Type returned by mcuxClMemory functions. See @ref MCUXCLMEMORY_STATUS_ for possible options.
 */
typedef uint32_t mcuxClMemory_Status_t;

/**
 * @brief Deprecated type for error codes used by code-flow protected mcuxClMemory component functions.
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMemory_Status_t) mcuxClMemory_Status_Protected_t;

#endif /* #MCUXCLMEMORY_TYPES_H */

/**
 * @}
 */
