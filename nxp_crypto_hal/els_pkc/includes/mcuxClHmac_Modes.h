/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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
 * @file  mcuxClHmac_Modes.h
 * @brief Mode descriptors for the mcuxClHmac component
 */

#ifndef MCUXCLHMAC_MODES_H_
#define MCUXCLHMAC_MODES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClMac_Types.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup mcuxClHmac_Modes HMAC mode definitions
 * @brief Modes used by the HMAC operations.
 * @ingroup mcuxClHmac
 */

/**
 * @brief HMAC-SHA2-256 mode descriptor using ELS HW
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClHmac_ModeDescriptor_SHA2_256_ELS;

/**
 * @brief HMAC-SHA2-256 mode using ELS HW
 *
 * The input buffer @p in will be modified by applying padding to it. The caller
 * must ensure that the input buffer is large enough to hold this padding.
 * The total buffer size including padding can be calculated using the macro
 * #MCUXCLHMAC_ELS_INPUTBUFFER_LENGTH on the data size @p inLength.
 *
 * Also note that #mcuxClMac_Mode_HMAC_SHA2_256_ELS only works with keys loaded
 * into coprocessor (see @ref mcuxClKey for details).
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClMac_Mode_HMAC_SHA2_256_ELS =
    &mcuxClHmac_ModeDescriptor_SHA2_256_ELS;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHMAC_MODES_H_ */
