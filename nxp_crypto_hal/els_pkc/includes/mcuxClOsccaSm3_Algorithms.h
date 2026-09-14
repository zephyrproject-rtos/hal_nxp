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

/** @file  mcuxClOsccaSm3_Algorithms.h
 *  @brief Algorithm/mode definitions for the mcuxClOsccaSm3 component
 */

#ifndef MCUXCLOSCCASM3_ALGORITHMS_H_
#define MCUXCLOSCCASM3_ALGORITHMS_H_

#include <mcuxClHash_Types.h>
#include <mcuxCsslAnalysis.h>

/**
* @defgroup mcuxClOsccaSm3_Algorithms mcuxClOsccaSm3_Algorithms
* @brief Hashing modes of the @ref mcuxClOsccaSm3 component
* @ingroup mcuxClOsccaSm3
* @{
*/

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

#if defined(MCUXCL_FEATURE_HASH_HW_SM3)
/**
 * @brief SM3 algorithm descriptor
 *        SM3 hash calculation using the Hash functionality OSCCA SM3.
 */
extern const mcuxClHash_AlgorithmDescriptor_t mcuxClOsccaSm3_AlgorithmDescriptor_Sm3;

/**
 * @brief SM3 algorithm descriptor
 *        SM3 hash calculation using the Hash functionality OSCCA SM3.
 */
static mcuxClHash_Algo_t mcuxClOsccaSm3_Algorithm_Sm3 = &mcuxClOsccaSm3_AlgorithmDescriptor_Sm3;

#endif /* MCUXCL_FEATURE_HASH_HW_SM3 */

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**@}*/

#endif /* MCUXCLOSCCASM3_ALGORITHMS_H_ */
