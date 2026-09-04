/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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

/** @file  mcuxClMac_Types.h
 *  @brief Type definitions for the mcuxClMac component
 */

#ifndef MCUXCLMAC_TYPES_H_
#define MCUXCLMAC_TYPES_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClSession_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

/**
 * @defgroup mcuxClMac_Types mcuxClMac_Types
 * @brief Defines all types of the @ref mcuxClMac component
 * @ingroup mcuxClMac
 * @{
 */

/**********************************************
 * TYPEDEFS
 **********************************************/

/**
 * @brief Type for Mac component error codes.
 */
typedef uint32_t mcuxClMac_Status_t;

/**
 * @brief MAC mode/algorithm descriptor structure
 *
 * This structure captures all the information that the MAC interfaces need to
 * know about a particular MAC mode/algorithm.
 */
struct mcuxClMac_ModeDescriptor;

/**
 * @brief MAC mode/algorithm descriptor type
 *
 * This type captures all the information that the MAC interfaces need to
 * know about a particular MAC mode/algorithm.
*/
typedef struct mcuxClMac_ModeDescriptor mcuxClMac_ModeDescriptor_t;

/**
 * @brief MAC mode/algorithm type
 *
 * This type is used to refer to a MAC mode/algorithm.
 */
typedef const mcuxClMac_ModeDescriptor_t * const mcuxClMac_Mode_t;

/**
 * @brief MAC custom mode/algorithm type
 *
 * This type is used to refer to a custom MAC mode/algorithm that
 * can be created via a provided constructor.
 */
typedef mcuxClMac_ModeDescriptor_t * const mcuxClMac_CustomMode_t;

#ifdef MCUXCL_FEATURE_MAC_SELFTEST
/**
 * @brief Mac selftest mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Mac selftest interfaces need
 * to know about a particular Mac selftest mode/algorithm.
 */
struct mcuxClMac_TestDescriptor;

/**
 * @brief Mac selftest mode/algorithm descriptor type
 *
 * This type captures all the information that the Mac selftest interfaces need
 * to know about a particular Mac selftest mode/algorithm.
 */
typedef struct mcuxClMac_TestDescriptor mcuxClMac_TestDescriptor_t;

/**
 * @brief Mac selftest mode/algorithm type
 *
 * This type is used to refer to a Mac selftest mode/algorithm.
 */
typedef const mcuxClMac_TestDescriptor_t * const mcuxClMac_Test_t;
#endif /* MCUXCL_FEATURE_MAC_SELFTEST */

/**
 * @brief Mac context structure
 *
 * This structure captures all the information that the Mac interface needs to
 * know for a particular Mac mode/algorithm to work.
 */
struct mcuxClMac_Context;

/**
 * @brief Mac context type
 *
 * This type captures all the information that the Mac interface needs to
 * know for a particular Mac mode/algorithm to work.
 *
 * The size of the context depends on the mode used
 * (see @ref mcuxClMac_MemoryConsumption).
 * 
 * Note: A copy of the Mac context to another memory location is only supported if both source and destination addresses have the same 64 bit alignment.
 *
 */
typedef struct mcuxClMac_Context mcuxClMac_Context_t;

/**
 * @}
 */ /* mcuxClMac_Types */

#endif /* MCUXCLMAC_TYPES_H_ */
