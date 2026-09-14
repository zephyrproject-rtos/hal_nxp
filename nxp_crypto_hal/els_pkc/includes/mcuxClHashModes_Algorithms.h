/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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

/** @file  mcuxClHashModes_Algorithms.h
 *  @brief Algorithm/mode definitions for the mcuxClHashModes component
 */

#ifndef MCUXCLHASHMODES_ALGORITHMS_H_
#define MCUXCLHASHMODES_ALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClHash_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup mcuxClHashModes_Algorithms mcuxClHashModes_Algorithms
* @brief Hashing algorithms of the @ref mcuxClHashModes component
* @ingroup mcuxClHashModes
* @{
*/

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()



/**
 * @brief Sha-1 algorithm descriptor
 *        Sha-1 hash calculation using an underlying software implementation of SHA-1
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_C_Sha1;

/**
 * @brief Sha-1 algorithm
 *        Sha-1 hash calculation using an underlying software implementation of SHA-1
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha1 = &mcuxClHash_AlgorithmDescriptor_C_Sha1;








#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

/**
 * @brief Sha-224 direct algorithm descriptor
 *        Sha-224 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha224_direct;

/**
 * @brief Sha-224 direct algorithm
 *        Sha-224 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha224_direct = &mcuxClHash_AlgorithmDescriptor_Sha224_direct;
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

/**
 * @brief Sha-224 algorithm descriptor
 *        Sha-224 hash calculation using the Hash functionality of ELS, it does not support RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha224;

/**
 * @brief Sha-224 algorithm
 *        Sha-224 hash calculation using the Hash functionality of ELS, it does not support RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha224 = &mcuxClHash_AlgorithmDescriptor_Sha224;

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

/**
 * @brief Sha-256 direct algorithm descriptor
 *        Sha-256 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha256_direct;

/**
 * @brief Sha-256 direct algorithm
 *        Sha-256 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha256_direct = &mcuxClHash_AlgorithmDescriptor_Sha256_direct;
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

/**
 * @brief Sha-256 algorithm descriptor
 *        Sha-256 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha256;

/**
 * @brief Sha-256 algorithm
 *        Sha-256 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha256 = &mcuxClHash_AlgorithmDescriptor_Sha256;

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

/**
 * @brief Sha-384 direct algorithm descriptor
 *        Sha-384 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha384_direct;

/**
 * @brief Sha-384 direct algorithm
 *        Sha-384 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha384_direct = &mcuxClHash_AlgorithmDescriptor_Sha384_direct;
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

/**
 * @brief Sha-384 algorithm descriptor
 *        Sha-384 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha384;

/**
 * @brief Sha-384 algorithm
 *        Sha-384 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha384 = &mcuxClHash_AlgorithmDescriptor_Sha384;

#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

/**
 * @brief Sha-512 direct algorithm descriptor
 *        Sha-512 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_direct;

/**
 * @brief Sha-512 direct algorithm
 *        Sha-512 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512_direct = &mcuxClHash_AlgorithmDescriptor_Sha512_direct;
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

/**
 * @brief Sha-512 algorithm descriptor
 *        Sha-512 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512;

/**
 * @brief Sha-512 algorithm
 *        Sha-512 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512 = &mcuxClHash_AlgorithmDescriptor_Sha512;
#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

/**
 * @brief Sha-512/224 direct algorithm descriptor
 *        Sha-512/224 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_224_direct;

/**
 * @brief Sha-512/224 direct algorithm
 *        Sha-512/224 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512_224_direct = &mcuxClHash_AlgorithmDescriptor_Sha512_224_direct;
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

/**
 * @brief Sha-512/224 algorithm descriptor
 *        Sha-512/224 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_224;

/**
 * @brief Sha-512/224 algorithm
 *        Sha-512/224 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512_224 = &mcuxClHash_AlgorithmDescriptor_Sha512_224;
#ifdef MCUXCL_FEATURE_ELS_SHA_DIRECT

/**
 * @brief Sha-512/256 direct algorithm descriptor
 *        Sha-512/256 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_256_direct;

/**
 * @brief Sha-512/256 direct algorithm
 *        Sha-512/256 hash calculation using the SHA-direct feature of ELS, it does not support RTF.
 *        SHA-direct mode has to be enabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512_256_direct = &mcuxClHash_AlgorithmDescriptor_Sha512_256_direct;
#endif /* MCUXCL_FEATURE_ELS_SHA_DIRECT */

/**
 * @brief Sha-512/256 algorithm descriptor
 *        Sha-512/256 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClHash_AlgorithmDescriptor_Sha512_256;

/**
 * @brief Sha-512/256 algorithm
 *        Sha-512/256 hash calculation using the Hash functionality of ELS, it supports RTF.
 *        SHA-direct mode has to be disabled prior to using this algorithm
 */
static mcuxClHash_Algo_t mcuxClHash_Algorithm_Sha512_256 = &mcuxClHash_AlgorithmDescriptor_Sha512_256;



















MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**@}*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHASHMODES_ALGORITHMS_H_ */
