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

#ifndef MCUXCLOSCCAMACMODES_MODES_H_
#define MCUXCLOSCCAMACMODES_MODES_H_

#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup mcuxClAPI MCUX CL -- API
 *
 * @addtogroup mcuxClOsccaMacModes MAC API
 * @brief Message Authentication Code (MAC) operations.
 * @ingroup mcuxClAPI
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()
/**
 * @defgroup mcuxClOsccaMacModes MAC mode definitions
 * @brief Modes used by the MAC operations.
 * @ingroup mcuxClMac
 */
#ifdef MCUXCL_FEATURE_MACMODES_CMAC_SM4
/**
 * @brief CMAC mode descriptor
 * @ingroup mcuxClOsccaMacModes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CMAC;

/**
 * @brief CMAC mode
 * @ingroup mcuxClOsccaMacModes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClOsccaMac_Mode_CMAC =
  &mcuxClOsccaMacModes_ModeDescriptor_CMAC;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* MCUXCL_FEATURE_MACMODES_CMAC_SM4 */

#ifdef MCUXCL_FEATURE_MACMODES_CBCMAC_SM4
/**
 * @brief CBC-MAC mode descriptor without padding
 * @ingroup mcuxClOsccaMacModes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_NoPadding;

/**
 * @brief CBC-MAC mode without padding
 * @ingroup mcuxClOsccaMacModes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClOsccaMac_Mode_CBCMAC_NoPadding =
  &mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_NoPadding;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
/**
 * @brief CBC-MAC mode descriptor with ISO/IEC 9797-1 padding method 1
 * @ingroup mcuxClOsccaMacModes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;

/**
 * @brief CBC-MAC mode with ISO/IEC 9797-1 padding method 1
 * @ingroup mcuxClOsccaMacModes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClOsccaMac_Mode_CBCMAC_PaddingISO9797_1_Method1 =
  &mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief CBC-MAC mode descriptor with ISO/IEC 9797-1 padding method 2
 * @ingroup mcuxClOsccaMacModes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method2;

/**
 * @brief CBC-MAC mode with ISO/IEC 9797-1 padding method 2
 * @ingroup mcuxClOsccaMacModes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClOsccaMac_Mode_CBCMAC_PaddingISO9797_1_Method2 =
  &mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method2;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
/**
 * @brief CBC-MAC mode descriptor with PKCS7 padding padding
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_Padding_PKCS7;

/**
 * @brief CBC-MAC mode with PKCS7 padding
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClOsccaMac_Mode_CBCMAC_Padding_PKCS7 =
  &mcuxClOsccaMacModes_ModeDescriptor_CBCMAC_Padding_PKCS7;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

#endif /* MCUXCL_FEATURE_MACMODES_CBCMAC_SM4 */


MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCAMACMODES_MODES_H_ */
