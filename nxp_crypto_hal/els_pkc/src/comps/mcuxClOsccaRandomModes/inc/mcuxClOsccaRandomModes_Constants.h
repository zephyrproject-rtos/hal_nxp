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
 * @file  mcuxClOsccaRandomModes_Constants.h
 * @brief Mode definitions of mcuxClOsccaRandomModes component
 */

#ifndef MCUXCLOSCCARANDOMMODES_CONSTANTS_H_
#define MCUXCLOSCCARANDOMMODES_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClRandom_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Types of mcuxClOsccaRandomModes                         */
/**********************************************************/
/**
 * @defgroup mcuxClOsccaRandomModes_Modes mcuxClOsccaRandomModes_Modes
 * @brief Defines all modes of @ref mcuxClOsccaRandomModes
 * @ingroup mcuxClOsccaRandomModes
 * @{
 */
#ifdef MCUXCL_FEATURE_RANDOMMODES_OSCCA_TRNG
/**
 * @brief DTRNG implemented in ROTRNG mode descriptor
 */
extern const mcuxClRandom_ModeDescriptor_t mcuxClOsccaRandomModes_mdROTRNG_Trng;
MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()
static const mcuxClRandom_Mode_t mcuxClOsccaRandomModes_Mode_TRNG = &mcuxClOsccaRandomModes_mdROTRNG_Trng;
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()
#endif /* MCUXCL_FEATURE_RANDOMMODES_OSCCA_TRNG */

/**
 * @}
 */ /* mcuxClOsccaRandomModes_Types */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCARANDOMMODES_CONSTANTS_H_ */
