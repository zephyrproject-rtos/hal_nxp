/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023-2024 NXP                                       */
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
 * @file  mcuxClPkc_Internal_Types.h
 * @brief Type definitions of mcuxClPkc component
 */


#ifndef MCUXCLPKC_INTERNAL_TYPES_H_
#define MCUXCLPKC_INTERNAL_TYPES_H_


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslFlowProtection.h>

/**
 * @defgroup mcuxClPkc_Internal_Types mcuxClPkc_Internal_Types
 * @brief Defines all macros of @ref mcuxClPkc
 * @ingroup mcuxClPkc
 * @{
 */


/**********************************************
 * CONSTANTS
 **********************************************/


/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @addtogroup MCUXCLPKC_STATUS_
 * mcuxClPkc return code definitions
 * @{
 */
/**
 * @brief Type for error codes used by PKC component functions.
 */
typedef uint32_t mcuxClPkc_Status_t;

/**
 * @brief Deprecated type for error codes used by code-flow protected PKC component functions.
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClPkc_Status_t) mcuxClPkc_Status_Protected_t;

#define MCUXCLPKC_STATUS_OK           ((mcuxClPkc_Status_t) 0x0AAA2E03u)  ///< PKC operation successful
#define MCUXCLPKC_STATUS_NOK          ((mcuxClPkc_Status_t) 0x0AAA53FCu)  ///< PKC operation not successful
#define MCUXCLPKC_STATUS_FAULT_ATTACK ((mcuxClPkc_Status_t) 0x0AAAF0F0u)  ///< Fault attack
/**
 * @}
 */ /* MCUXCLPKC_STATUS_ */


/**********************************************************/
/* Helper macros                                          */
/**********************************************************/
/**
 * @addtogroup MCUXCLPKC_MISC_
 * mcuxClPkc misc macros and definitions
 * @{
 */

/** @brief Round-up a length to a multiple of PKC wordsize. */
#define MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE(size)  \
    MCUXCLCORE_ALIGN_TO_WORDSIZE(MCUXCLPKC_WORDSIZE, size)

/** @brief Macros for packing 4 8-bit parameters. */
#define MCUXCLPKC_PACKARGS4(byte3_MSByte, byte2, byte1, byte0_LSByte)  \
    (  ((uint32_t) (byte3_MSByte) << 24u) | ((uint32_t) (byte2) << 16u)  \
     | ((uint32_t) (byte1) << 8u) | ((uint32_t) (byte0_LSByte)) )

/** @brief Macros for packing 2 8-bit parameters. */
#define MCUXCLPKC_PACKARGS2(hi8, lo8)  \
    ( ((uint16_t) (hi8) << 8u) | ((uint16_t) (lo8)) )


/**********************************************************/
/* PKC information                                        */
/**********************************************************/
#define MCUXCLPKC_WORDSIZE   (8u)  ///< PKC wordsize in byte


/**
 * @}
 */ /* MCUXCLPKC_MISC_ */

/**
 * @}
 */ /* mcuxClPkc_Internal_Types */

#endif /* MCUXCLPKC_INTERNAL_TYPES_H_ */
