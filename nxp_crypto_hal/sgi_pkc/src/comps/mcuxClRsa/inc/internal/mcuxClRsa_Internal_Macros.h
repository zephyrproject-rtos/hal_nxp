/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2026 NXP                                            */
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
 * @file  mcuxClRsa_Internal_Macros.h
 * @brief Internal macros of the mcuxClRsa component
 */

#ifndef MCUXCLRSA_INTERNAL_MACROS_H_
#define MCUXCLRSA_INTERNAL_MACROS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stdint.h>
#include <mcuxClCore_Macros.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup MCUXCLRSA_INTERNAL_DEFINES_ MCUXCLRSA_INTERNAL_DEFINES_
 * @brief Internal macros of the mcuxClRsa component.
 * @ingroup mcuxClRsa_Internal_Defines
 * @{
 */
#define MCUXCLRSA_PSS_PADDING1_LEN (8U)
    ///< Define for the PSS padding1 length.

#define MCUXCLRSA_HASH_MIN_SIZE MCUXCLHASH_STATE_SIZE_MIN
    ///< Defines the minimum size of the hash algorithms

#define MCUXCLRSA_HASH_MAX_SIZE MCUXCLHASH_OUTPUT_SIZE_SHA_512
    ///< Defines the maximum size of the hash algorithms

#define MCUXCLRSA_MIN_MODLEN (128U)
    ///< Defines the minimum size of the rsa modulus byte length

#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_MAX_MODLEN (1024U)
    ///< Defines the maximum size of the rsa modulus byte length
#else
#define MCUXCLRSA_MAX_MODLEN (512U)
    ///< Defines the maximum size of the rsa modulus byte length
#endif

#if defined(MCUXCL_FEATURE_PKC_RAM_4KB)
#define MCUXCLRSA_MAX_MODLEN_EXPTEMP_IN_PKCRAM    (MCUXCLKEY_SIZE_3072/8U)
    ///< Defines the maximum size of the rsa modulus byte length so that expTemp buffer can be located in PKC RAM
#elif defined(MCUXCL_FEATURE_PKC_RAM_8KB)
#define MCUXCLRSA_MAX_MODLEN_EXPTEMP_IN_PKCRAM    (MCUXCLKEY_SIZE_6144/8U)
    ///< Defines the maximum size of the rsa modulus byte length so that expTemp buffer can be located in PKC RAM
#else
#error PKC_RAM size feature not properly defined
#endif /* MCUXCL_FEATURE_PKC_RAM_8KB */
/** @} */


/**
 * @defgroup MCUXCLRSA_INTERNAL_MACROS_ MCUXCLRSA_INTERNAL_MACROS_
 * @brief Internal macros of the mcuxClRsa component.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_GET_MINIMUM_SECURITY_STRENGTH(keyBitLength) \
        (((keyBitLength) <= 1024U) ? 80U :  \
        (((keyBitLength) <= 2048U) ? 112U : \
        (((keyBitLength) <= 3072U) ? 128U : \
        (((keyBitLength) <= 4096U) ? 152U : \
        (((keyBitLength) <= 6144U) ? 176U : \
                                     200U))))) ///< Macro to determine the minimal security strength that
                                               ///< needs to be provided by the RNG for RSA keys with
                                               ///< lengths from 1024 bits to 8192 bits.
                                               ///< Numbers taken from NIST SP 800-56B REV. 2, Table 2 and Appendix D
#else
#define MCUXCLRSA_GET_MINIMUM_SECURITY_STRENGTH(keyBitLength) \
        (((keyBitLength) <= 1024U) ? 80U :  \
        (((keyBitLength) <= 2048U) ? 112U : \
        (((keyBitLength) <= 3072U) ? 128U : \
                                     152U))) ///< Macro to determine the minimal security strength that
                                             ///< needs to be provided by the RNG for RSA keys with
                                             ///< lengths from 1024 bits to 4096 bits.
                                             ///< Numbers taken from NIST SP 800-56B REV. 2, Table 2 and Appendix D
#endif /* #ifdef MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_MAX_LOOP_ITER_P  (5U)   /* Value used to compute maximum number of iterations for generating p according to FIPS186-5 */
#define MCUXCLRSA_MAX_LOOP_ITER_Q  (10U)   /* Value used to compute maximum number of iterations for generating q according to FIPS186-5 */

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_INTERNAL_MACROS_H_ */

