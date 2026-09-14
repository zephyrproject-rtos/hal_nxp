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

/** @file  mcuxClOsccaAeadModes_Modes.h
 *  @brief Supported modes for the mcuxClOsccaAeadModes component
 */

#ifndef MCUXCLOSCCAAEADMODES_MODES_H_
#define MCUXCLOSCCAAEADMODES_MODES_H_

#include <mcuxCsslAnalysis.h>
#include <mcuxClAead_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

/**
 * @defgroup mcuxClOsccaAeadModes_Modes mcuxClOsccaAeadModes_Modes
 * @brief Modes used by the OSCCA AEAD operations.
 * @ingroup mcuxClOsccaAeadModes
 * @{
 */
#ifdef MCUXCL_FEATURE_SM4_CCM

/**
 * @brief AES CCM encrypt mode descriptor
 */
extern const mcuxClAead_ModeDescriptor_t mcuxClOsccaAeadModes_ModeDescriptor_CCM_ENC;

/**
 * @brief AES CCM encrypt mode
 */
static mcuxClAead_Mode_t mcuxClOsccaAead_Mode_CCM_ENC =
  &mcuxClOsccaAeadModes_ModeDescriptor_CCM_ENC;

/**
 * @brief AES CCM decrypt mode descriptor
 */
extern const mcuxClAead_ModeDescriptor_t mcuxClOsccaAeadModes_ModeDescriptor_CCM_DEC;

/**
 * @brief AES CCM decrypt mode
 */
static mcuxClAead_Mode_t mcuxClOsccaAead_Mode_CCM_DEC =
  &mcuxClOsccaAeadModes_ModeDescriptor_CCM_DEC;


#endif /* MCUXCL_FEATURE_SM4_CCM */

/** @} */

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCAAEADMODES_MODES_H_ */
