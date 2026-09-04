/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClKdfModes_Algorithms_NIST_SP800_108.h
 * @brief Declarations and definitions for the NIST SP800-108 KDF
 */

#ifndef MCUXCLKDFMODES_ALGORITHMS_NIST_SP800_108_H_
#define MCUXCLKDFMODES_ALGORITHMS_NIST_SP800_108_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClKdfModes_Algorithms_NIST_SP800_108 mcuxClKdfModes_Algorithms_NIST_SP800_108
 * @brief Defines NIST_SP800_108 algorithm of @ref mcuxClKdfModes
 * @ingroup mcuxClKdfModes_Algorithms
 * @{
 */

#include <mcuxCsslAnalysis.h>
#include <mcuxClKey_Types.h>
#include <mcuxClMac.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Construct a key derivation function (KDF) mode according to NIST SP800-108.
 *
 * @param[out]    pDerivationMode        Pointer to the key derivation mode structure to be initialized.
 * @param[in]     derivationAlgorithm    Function pointer to the key derivation algorithm function.
 * @param[in]     macMode                Mac mode type, in case a Mac mode is used within the key derivation algorithm.
 * @param[in]     options                Generic options field containing algorithm-specific parameters (e.g., counter length or iteration count).
 *                                       Must not be larger than 32. Use MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_* definitions.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
    mcuxClKey_DerivationMode_t * pDerivationMode,
    const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
    mcuxClMac_Mode_t macMode,
    uint32_t options
);

/**
 * @brief NIST SP800-108 key derivation algorithm descriptors
 */
extern const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_NIST_SP800_108;

/**
 * @brief NIST SP800-108 key derivation algorithm types
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static mcuxClKey_DerivationAlgorithm_t mcuxClKey_DerivationAlgorithm_NIST_SP800_108 = &mcuxClKey_DerivationAlgorithmDescriptor_NIST_SP800_108;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief NIST SP800-108 Counter Mode with CMAC algorithm descriptor
 */
extern const mcuxClKey_DerivationMode_t mcuxClKey_DerivationMode_SP800_108_CM_CMAC;

/**
 * @brief NIST SP800-108 algorithm type
 *
 * Parameters:
 * - Counter Mode
 * - CMAC
 * - 8-bit counter
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static const mcuxClKey_Derivation_t mcuxClKdfModes_SP800_108_CM_CMAC = &mcuxClKey_DerivationMode_SP800_108_CM_CMAC;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef __cplusplus
} /* extern "C" */
#endif

/** @} */

#endif /* MCUXCLKDFMODES_ALGORITHMS_NIST_SP800_108_H_ */
