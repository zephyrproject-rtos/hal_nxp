/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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
 * @file  mcuxClOsccaSm2_KeyTypes.h
 * @brief Definition of supported key types in mcuxClOsccaSm2 component, see also @ref mcuxClKey component
 */

#ifndef MCUXCLOSCCASM2_KEYTYPES_H_
#define MCUXCLOSCCASM2_KEYTYPES_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClKey_Types.h>

/**
 * @defgroup mcuxClOsccaSm2_KeyTypes mcuxClOsccaSm2_KeyTypes
 * @brief Defines of supported key types of @ref mcuxClOsccaSm2, see @ref mcuxClKey
 * @ingroup mcuxClOsccaSm2
 * @{
 */

/**********************************************
 * KEY TYPE DEFS
 **********************************************/
/**
 * @brief Key type structures for public SM2 standard keys and modulus sizes 256 bits.
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_SM2P256_Std_Public;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * @brief Key type pointers for public SM2 standard keys and modulus sizes 256 bits.
 *
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()
static const mcuxClKey_Type_t mcuxClKey_Type_SM2P256_Std_Public = &mcuxClKey_TypeDescriptor_SM2P256_Std_Public;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @brief Key type structures for private SM2 standard keys and modulus sizes 256 bits.
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_SM2P256_Std_Private;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * @brief Key type pointers for private SM2 standard keys and modulus sizes 256 bits.
 *
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()
static const mcuxClKey_Type_t mcuxClKey_Type_SM2P256_Std_Private = &mcuxClKey_TypeDescriptor_SM2P256_Std_Private;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @brief Key type structures for public SM2 extend keys and modulus sizes 256 bits.
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_SM2P256_Ext_Public;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * @brief Key type pointers for public SM2 extend keys and modulus sizes 256 bits.
 *
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()
static const mcuxClKey_Type_t mcuxClKey_Type_SM2P256_Ext_Public = &mcuxClKey_TypeDescriptor_SM2P256_Ext_Public;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @brief Key type structures for private SM2 extend keys and modulus sizes 256 bits.
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_SM2P256_Ext_Private;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * @brief Key type pointers for private SM2 extend keys and modulus sizes 256 bits.
 *
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()
static const mcuxClKey_Type_t mcuxClKey_Type_SM2P256_Ext_Private = &mcuxClKey_TypeDescriptor_SM2P256_Ext_Private;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @}
 */ /* mcuxClOsccaSm2_KeyTypes */

#endif /* MCUXCLOSCCASM2_KEYTYPES_H_ */
