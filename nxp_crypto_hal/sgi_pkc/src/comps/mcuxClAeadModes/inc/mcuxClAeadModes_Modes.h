/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

/** @file  mcuxClAeadModes_Modes.h
 *  @brief This file defines the modes for the mcuxClAeadModes component */

#ifndef MCUXCLAEADMODES_MODES_H_
#define MCUXCLAEADMODES_MODES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClAead_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClAeadModes_Modes mcuxClAeadModes_Modes
 * @brief Modes used by the AEAD operations.
 * @ingroup mcuxClAeadModes
 * @{
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @brief AES-CCM mode descriptor
 */


extern const mcuxClAead_ModeDescriptor_t mcuxClAead_ModeDescriptor_AES_CCM;

/**
 * @brief AES-CCM mode.
 *
 * See @ref mcuxClAead_ModeDescriptor_AES_CCM.
 *
 * @implements{REQ_788225}
 */
static mcuxClAead_Mode_t mcuxClAead_Mode_CCM =
  &mcuxClAead_ModeDescriptor_AES_CCM;

/**
 * @brief GCM mode descriptor
 */
/** @attention This mode overwrites the contents of key register SGI KEY2 for storing the H-Key.
 *             Any preloaded key data in this slot will be overwritten.
 */
extern const mcuxClAead_ModeDescriptor_t mcuxClAead_ModeDescriptor_AES_GCM;

/**
 * @brief GCM mode.
 *
 * See @ref mcuxClAead_ModeDescriptor_AES_GCM.
 *
 * @implements{REQ_788227}
 */
static mcuxClAead_Mode_t mcuxClAead_Mode_GCM =
  &mcuxClAead_ModeDescriptor_AES_GCM;

#ifdef MCUXCL_FEATURE_AEADMODES_SW
#endif /* MCUXCL_FEATURE_AEADMODES_SW */

MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLAEADMODES_MODES_H_ */
