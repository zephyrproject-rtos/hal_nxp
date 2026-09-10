/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2023, 2025 NXP                                      */
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
 * @file  mcuxClMac_Types.h
 * @brief Type definitions for the mcuxClMac component
 */


#ifndef MCUXCLMATH_TYPES_H_
#define MCUXCLMATH_TYPES_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>


/**********************************************
 * CONSTANTS
 **********************************************/
/* None */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClMath_Macros mcuxClMath_Macros
 * @brief Defines all macros of @ref mcuxClMath
 * @ingroup mcuxClMath
 * @{
 */

/**
 * @brief Type for error codes used by Math component functions.
 */
typedef uint32_t mcuxClMath_Status_t;

/**
 * @brief Deprecated type for error codes used by code-flow protected Math component functions.
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMath_Status_t) mcuxClMath_Status_Protected_t;

#define MCUXCLMATH_STATUS_OK                 ((mcuxClMath_Status_t) 0x0FF32E03u)  ///< Math operation successful
#define MCUXCLMATH_STATUS_ERROR              ((mcuxClMath_Status_t) 0x0FF35330u)  ///< Error occurred during Math operation
#define MCUXCLMATH_STATUS_FAULT_ATTACK       ((mcuxClMath_Status_t) 0x0FF3F0F0u)  ///< Error occurred during Math operation
#define MCUXCLMATH_STATUS_INVALID_PARAMS     ((mcuxClMath_Status_t) 0x0FF353F8u)  ///< Math function called with invalid parameters

/**
 * @brief number of buffers allocated in PKC RAM, T2 reuses X.
 */
#define MCUXCLMATH_MODMULT_NO_OF_BUFFERS  6u

/**
 * @}
 */ /* mcuxClMath_Macros */


#endif /* MCUXCLMATH_TYPES_H_ */
