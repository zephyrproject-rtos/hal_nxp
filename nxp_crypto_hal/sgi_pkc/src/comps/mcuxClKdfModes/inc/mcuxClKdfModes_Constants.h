/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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
 * @file  mcuxClKdfModes_Constants.h
 * @brief Constants for the mcuxClKdfModes component.
 */

#ifndef MCUXCLKDFMODES_CONSTANTS_H_
#define MCUXCLKDFMODES_CONSTANTS_H_

#include <mcuxCsslAnalysis.h>
#include <mcuxClConfig.h> // Exported features flags header

/**********************************************
 * CONSTANTS
 **********************************************/
/**
 * @defgroup mcuxClKdfModes_Constants mcuxClKdfModes_Constants
 * @brief Defines all constants of @ref mcuxClKdfModes
 * @ingroup mcuxClKdfModes
 * @{
 */

/** Bit-size of the binary repr. of the iteration counter r */
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT   (0u)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_MASK    ((uint32_t)0x3u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_8       ((uint32_t)0u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_16      ((uint32_t)1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_24      ((uint32_t)2u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_32      ((uint32_t)3u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT)

/** Bit-size of the encoded output size */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT    (2u)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_MASK     ((uint32_t)0x3u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_32       ((uint32_t)0u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_24       ((uint32_t)1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_16       ((uint32_t)2u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_8        ((uint32_t)3u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/** Endianess of iteration counter and encoded output size */
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_SHIFT          (4u)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_MASK           ((uint32_t)0x1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_SHIFT)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN     ((uint32_t)0u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN  ((uint32_t)1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_SHIFT)

/** If PRF input includes counter in Feedback and Double-Pipeline mode */
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_SHIFT  (6u)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_MASK   ((uint32_t)1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_SHIFT)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_EXCLUDE_COUNTER          ((uint32_t)0u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER          ((uint32_t)1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_SHIFT)

/** KDF mode */
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_SHIFT               (7u)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK                ((uint32_t)3u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_SHIFT)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER             ((uint32_t)0u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK            ((uint32_t)1u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_SHIFT)
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE     ((uint32_t)2u << MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_SHIFT)




/** Max IV Lengths */

#define MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH           MCUXCLHASH_MAX_OUTPUT_SIZE
#define MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH_IN_WORDS (MCUXCLKEY_DERIVATION_NIST_SP800_56C_MAX_IVLENGTH / sizeof(uint32_t))

/** @} */

#endif /* MCUXCLKDFMODES_CONSTANTS_H_ */

