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

/**
 * @file  mcuxClKdfModes_Algorithms_HKDF.h
 * @brief Declarations and definitions for the Implementation of RFC5869 Key Derivation
 */

#ifndef MCUXCLKDFMODES_ALGORITHMS_HKDF_H_
#define MCUXCLKDFMODES_ALGORITHMS_HKDF_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClKdfModes_Algorithms_HKDF mcuxClKdfModes_Algorithms_HKDF
 * @brief Defines HKDF algorithm of @ref mcuxClKdfModes
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
 * @brief Construct a key derivation function (KDF) mode according to RFC5869.
 *
 * @param[out]    pDerivationMode        Pointer to the key derivation mode structure to be initialized.
 * @param[in]     derivationAlgorithm    Function pointer to the key derivation algorithm function.
 * @param[in]     macMode                Mac mode type, must represent an HMAC mode.
 * @param[in]     options                Generic options field containing algorithm-specific parameters (currently not used).
 *
 * @details When calling mcuxClKey_derivation function with this constructor additional inputs may be provided via mcuxClKey_DerivationInput_t inputs[]
 *          parameter array. Detailed description of possible inputs is provided for each algorithm type.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKey_Derivation_ModeConstructor_HKDF)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_HKDF(
    mcuxClKey_DerivationMode_t * pDerivationMode,
    const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
    mcuxClMac_Mode_t macMode,
    uint32_t options // currently no options for this mode
);

/**
 * @brief RFC5869 key derivation algorithm descriptor
 */
extern const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_HKDF;

/**
 * @brief RFC5869 key derivation algorithm type
 *
 * @details When using this algorithm possible inputs[] for mcuxClKey_derivation function are:
 *          - inputs[0] fixedInfo (optional) (length is required, data pointer may be NULL which defaults to all-zero salt)
 *          - inputs[1] salt (optional) (length is required, data pointer may be NULL which defaults to all-zero salt)
 * \implements{REQ_787502}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static mcuxClKey_DerivationAlgorithm_t mcuxClKey_DerivationAlgorithm_HKDF = &mcuxClKey_DerivationAlgorithmDescriptor_HKDF;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef __cplusplus
} /* extern "C" */
#endif

/** @} */

#endif /* MCUXCLKDFMODES_ALGORITHMS_HKDF_H_ */
