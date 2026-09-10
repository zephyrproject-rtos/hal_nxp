/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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

#ifndef MCUXCLMACMODES_MODES_H_
#define MCUXCLMACMODES_MODES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClMac_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup mcuxClAPI MCUX CL -- API
 *
 * @addtogroup mcuxClMacModes MAC Modes API
 * @brief Message Authentication Code (MAC) mode operations.
 * @ingroup mcuxClAPI
 */

/**
 * @defgroup mcuxClMacModes_Modes MAC mode definitions
 * @brief Modes used by the MAC operations.
 * @ingroup mcuxClMacModes
 */


/**
 * @brief CMAC mode descriptor
 * @ingroup mcuxClMacModes_Modes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CMAC;

/**
 * @brief CMAC mode
 * @ingroup mcuxClMacModes_Modes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClMac_Mode_CMAC =
  &mcuxClMac_ModeDescriptor_CMAC;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()



/**
 * @brief CBC-MAC mode descriptor without padding
 * @ingroup mcuxClMacModes_Modes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CBCMAC_NoPadding;

/**
 * @brief CBC-MAC mode without padding
 * @ingroup mcuxClMacModes_Modes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClMac_Mode_CBCMAC_NoPadding =
  &mcuxClMac_ModeDescriptor_CBCMAC_NoPadding;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/**
 * @brief CBC-MAC mode descriptor with ISO/IEC 9797-1 padding method 1
 * @ingroup mcuxClMacModes_Modes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;

/**
 * @brief CBC-MAC mode with ISO/IEC 9797-1 padding method 1
 * @ingroup mcuxClMacModes_Modes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClMac_Mode_CBCMAC_PaddingISO9797_1_Method1 =
  &mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief CBC-MAC mode descriptor with ISO/IEC 9797-1 padding method 2
 * @ingroup mcuxClMacModes_Modes
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method2;

/**
 * @brief CBC-MAC mode with ISO/IEC 9797-1 padding method 2
 * @ingroup mcuxClMacModes_Modes
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClMac_Mode_CBCMAC_PaddingISO9797_1_Method2 =
  &mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method2;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/**
 * @brief CBC-MAC mode descriptor with PKCS7 padding padding
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CBCMAC_Padding_PKCS7;

/**
 * @brief CBC-MAC mode with PKCS7 padding
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")
static mcuxClMac_Mode_t mcuxClMac_Mode_CBCMAC_Padding_PKCS7 =
  &mcuxClMac_ModeDescriptor_CBCMAC_Padding_PKCS7;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_MODES_H_ */
