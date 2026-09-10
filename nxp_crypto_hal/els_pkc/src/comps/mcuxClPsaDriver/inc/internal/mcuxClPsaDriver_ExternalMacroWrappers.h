/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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

/** @file  mcuxClPsaDriver_ExternalMacroWrappers.h
 *  @brief Defines the memory consumption for the mcuxClPsaDriver component
 */

#ifndef MCUXCLPSADRIVER_EXTERNAL_MACRO_WRAPPERS_H_
#define MCUXCLPSADRIVER_EXTERNAL_MACRO_WRAPPERS_H_

#include <psa/crypto.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClPsaDriver_ExternalMacroWrappers mcuxClPsaDriver_ExternalMacroWrappers
 * @brief Defines the External Macro Wrappers for the @ref mcuxClPsaDriver component
 * @ingroup mcuxClPsaDriver
 * @{
 */

#define MCUXCLPSADRIVER_PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(aead_alg) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_INVALID_WIDTH_IN_SHIFT_OPERATIONS("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(aead_alg) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INVALID_WIDTH_IN_SHIFT_OPERATIONS() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_AEAD_FINISH_OUTPUT_SIZE(key_type, alg) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_AEAD_FINISH_OUTPUT_SIZE(key_type, alg) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())


#define MCUXCLPSADRIVER_PSA_AEAD_ENCRYPT_OUTPUT_SIZE(key_type, alg, plaintext_length) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_AEAD_ENCRYPT_OUTPUT_SIZE(key_type, alg, plaintext_length) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_AEAD_DECRYPT_OUTPUT_SIZE(key_type, alg, ciphertext_length) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_AEAD_DECRYPT_OUTPUT_SIZE(key_type, alg, ciphertext_length) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_MAC_LENGTH(key_type, key_bits, alg) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_MAC_LENGTH(key_type, key_bits, alg) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_KEY_TYPE_ECC_GET_FAMILY(type)  \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_KEY_TYPE_ECC_GET_FAMILY(type)  \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_ALG_SIGN_GET_HASH(alg) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_ALG_SIGN_GET_HASH(alg) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_MBEDTLS_BYTE_0(x_) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        MBEDTLS_BYTE_0(x_) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_MBEDTLS_BYTE_1(x_) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        MBEDTLS_BYTE_1(x_) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE() \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_ALG_IS_DETERMINISTIC_ECDSA(alg) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
        PSA_ALG_IS_DETERMINISTIC_ECDSA(alg) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_OPERATIONS_ON_INAPPROPRIATE_TYPE())

#define MCUXCLPSADRIVER_PSA_ALG_IS_ECDSA(alg) \
    (MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE("External code. Operation is safe on target platform.") \
    PSA_ALG_IS_ECDSA(alg) \
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONVERSIONS_WITH_INAPPROPRIATE_TYPE())

/**
 * @}
 */ /* mcuxClPsaDriver_ExternalMacroWrappers */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPSADRIVER_EXTERNAL_MACRO_WRAPPERS_H_ */

