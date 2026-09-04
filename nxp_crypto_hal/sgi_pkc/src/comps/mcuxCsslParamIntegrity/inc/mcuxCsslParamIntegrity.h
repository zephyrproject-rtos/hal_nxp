/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2025 NXP                                            */
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

/// @file  mcuxCsslParamIntegrity.h
/// @brief Top-level include file for the parameter integrity protection mechanism
///
/// The library exposes the following functions:
/// <ol>
///     <li> Generation of parameter checksums: #mcuxCsslParamIntegrity_Protect
///     <li> Validation of parameter checksums: #mcuxCsslParamIntegrity_Validate
/// </ol>

#ifndef MCUXCSSLPARAMINTEGRITY_H
#define MCUXCSSLPARAMINTEGRITY_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>

/**
 * @defgroup mcuxCsslParamIntegrity Parameter Integrity API
 * @brief Functionality to ensure parameter integrity during function calls
 *
 * @ingroup mcuxCsslAPI
 * @{
 */

/**
 * @defgroup mcuxCsslParamIntegrity_Macros mcuxCsslParamIntegrity Macro Definitions
 * @brief Macros of mcuxCsslParamIntegrity component
 * @ingroup mcuxCsslParamIntegrity
 * @{
 */

#define MCUXCSSLPARAMINTEGRITY_BASE_CHECKSUM ((mcuxCsslParamIntegrity_Checksum_t)0xb7151628u) ///< First eight hex digits of Eulers number

#define MCUXCSSLPARAMINTEGRITY_CHECK_VALID ((mcuxCsslParamIntegrity_Checksum_t)0x6969u) ///< Return value of #mcuxCsslParamIntegrity_Validate if the parameter checksum was correct

#define MCUXCSSLPARAMINTEGRITY_CHECK_INVALID ((mcuxCsslParamIntegrity_Checksum_t)0x9696u) ///< Return value of #mcuxCsslParamIntegrity_Validate if the parameter checksum was incorrect

#define MCUX_CSSL_PI_PARAM_ADD_CASTED_ARG(x) ,( \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Typecast pointer to integer for parameter integrity evaluation") \
    (mcuxCsslParamIntegrity_Param_t)(x) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER())

#define MCUX_CSSL_PI_VALIDATE(chk, ...) (mcuxCsslParamIntegrity_Validate(chk, MCUX_CSSL_CPP_ARGCOUNT(__VA_ARGS__) MCUX_CSSL_CPP_MAP(MCUX_CSSL_PI_PARAM_ADD_CASTED_ARG, __VA_ARGS__)))

#define MCUX_CSSL_PI_PROTECT(...) (mcuxCsslParamIntegrity_Protect(MCUX_CSSL_CPP_ARGCOUNT(__VA_ARGS__) MCUX_CSSL_CPP_MAP(MCUX_CSSL_PI_PARAM_ADD_CASTED_ARG, __VA_ARGS__)))

/**
 * @}
 */

/**
 * @defgroup mcuxCsslParamIntegrity_Types mcuxCsslParamIntegrity Type Definitions
 * @brief Types of mcuxCsslParamIntegrity component
 * @ingroup mcuxCsslParamIntegrity
 * @{
 */

/**
* @brief Build time assertion to ensure CPU word size of 32 bit
*/
typedef void * mcuxCsslParamIntegrity_AssertionCpuWordSize_t[(4u == sizeof(size_t)) ? (+1) : (-1)];

/**
* @brief  Type of a parameter checksum.
*/
typedef uint32_t mcuxCsslParamIntegrity_Checksum_t;

/**
* @brief  Type of a parameter for the checksum calculation.
*/
typedef uint32_t mcuxCsslParamIntegrity_Param_t;


/**
 * @}
 */

/**
 * @defgroup mcuxCsslParamIntegrity_Functions mcuxCsslParamIntegrity Function Definitions
 * @brief Functions of mcuxCsslParamIntegrity component
 * @ingroup mcuxCsslParamIntegrity
 * @{
 */

/**
 * @brief Calculates a parameter checksum.
 *
 * @param nargs The number of parameters to be protected.
 * @param ... The parameters that should be protected. Note that parameters bigger than a single machine word are not supported.
 * @return checksum over the input parameters to be protected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslParamIntegrity_Protect)
mcuxCsslParamIntegrity_Checksum_t mcuxCsslParamIntegrity_Protect(uint32_t nargs, ...);

/**
 * @brief Verifies the correctness of a parameter checksum.
 *
 * @param chk The parameter checksum.
 * @param nargs The number of parameters to be protected.
 * @param ... The parameters that were used to calculate the parameter checksum. Note that parameters bigger than a single machine word are not supported.
 * @return A status code encapsulated in a flow-protection type.
 * @retval #MCUXCSSLPARAMINTEGRITY_CHECK_VALID The parameter checksum was correct.
 * @retval #MCUXCSSLPARAMINTEGRITY_CHECK_INVALID The parameter checksum was incorrect.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxCsslParamIntegrity_Validate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslParamIntegrity_Checksum_t) mcuxCsslParamIntegrity_Validate(mcuxCsslParamIntegrity_Checksum_t chk, uint32_t nargs, ...);

/**
 * @}
 */

/**
 * @}
 */

#endif
