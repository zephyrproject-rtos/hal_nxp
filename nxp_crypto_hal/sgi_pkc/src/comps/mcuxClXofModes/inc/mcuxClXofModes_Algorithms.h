/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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

/** @file  mcuxClXof_Algorithms.h
 *  @brief Algorithm/mode definitions for the mcuxClXofModes component
 */

#ifndef MCUXCLXOFMODES_ALGORITHMS_H_
#define MCUXCLXOFMODES_ALGORITHMS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClXof_Types.h>
#include <mcuxClHash_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup mcuxClXofModes_Algorithms mcuxClXofModes_Algorithms
* @brief Xof algorithms of the @ref mcuxClXofModes component
* @ingroup mcuxClXofModes
* @{
*/

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()





#ifdef MCUXCL_FEATURE_XOF_C_SHAKE_128
/**
 * @brief SHAKE-128 algorithm descriptor
 *        SHAKE-128 Xof calculation using an underlying software implementation of Keccak.
 */
extern const mcuxClXof_AlgorithmDescriptor_t mcuxClXof_AlgorithmDescriptor_C_Shake_128;

/**
 * @brief SHAKE-128 algorithm descriptor
 *        SHAKE-128 Xof calculation using an underlying software implementation of Keccak.
 * \implements{REQ_788292}
 */
static mcuxClXof_Algo_t mcuxClXof_Algorithm_Shake_128 = &mcuxClXof_AlgorithmDescriptor_C_Shake_128;
#endif /* MCUXCL_FEATURE_XOF_C_SHAKE_128 */

#ifdef MCUXCL_FEATURE_XOF_C_SHAKE_256
/**
 * @brief SHAKE-256 algorithm descriptor
 *        SHAKE-256 Xof calculation using an underlying software implementation of Keccak.
 */
extern const mcuxClXof_AlgorithmDescriptor_t mcuxClXof_AlgorithmDescriptor_C_Shake_256;

/**
 * @brief SHAKE-256 algorithm descriptor
 *        SHAKE-256 Xof calculation using an underlying software implementation of Keccak.
 * \implements{REQ_788292}
 */
static mcuxClXof_Algo_t mcuxClXof_Algorithm_Shake_256 = &mcuxClXof_AlgorithmDescriptor_C_Shake_256;
#endif /* MCUXCL_FEATURE_XOF_C_SHAKE_256 */



MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**@}*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLXOFMODES_ALGORITHMS_H_ */
