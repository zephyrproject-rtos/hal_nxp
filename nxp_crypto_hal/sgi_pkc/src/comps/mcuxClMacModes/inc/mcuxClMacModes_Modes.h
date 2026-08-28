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
 * @defgroup mcuxClMacModes_Modes mcuxClMacModes_Modes
 * @brief Modes used by the MAC operations.
 * @ingroup mcuxClMacModes
 * @{
 */

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Declaration provided for externally accessible API")


/**
 * @brief AES-CMAC mode descriptor
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CMAC;

/**
 * @brief AES-CMAC mode.
 *
 * See @ref mcuxClMac_ModeDescriptor_CMAC.
 *
 * @implements{REQ_788232,REQ_788235}
 */
static mcuxClMac_Mode_t mcuxClMac_Mode_CMAC =
  &mcuxClMac_ModeDescriptor_CMAC;


/**
 * @brief AES-CMAC mode descriptor, non-blocking API, using the DMA for I/O operations
 * @note Interrupts must be enabled on the DMA input channel with a properly installed handler.
 * If the non-blocking Mac operation returns @ref MCUXCLMAC_STATUS_JOB_STARTED, a
 * non-blocking operation has started and the CPU is unblocked in the meantime.
 *
 * @attention The input length for this mode has an upper limit of 0x7fff0 bytes per API call.
 * Bigger sizes need to be split into multiple process calls.
 *
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CMAC_NonBlocking;

/**
 * @brief AES-CMAC mode, non-blocking API, using the DMA for I/O operations.
 *
 * See @ref mcuxClMac_ModeDescriptor_CMAC_NonBlocking.
 *
 * @implements{REQ_1550258,REQ_788235}
 */
static mcuxClMac_Mode_t mcuxClMac_Mode_CMAC_NonBlocking =
  &mcuxClMac_ModeDescriptor_CMAC_NonBlocking;




/**
 * @brief AES-CBC-MAC mode descriptor with ISO/IEC 9797-1 padding method 1
 */
extern const mcuxClMac_ModeDescriptor_t mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;

/**
 * @brief AES-CBC-MAC mode with ISO/IEC 9797-1 padding method 1.
 *
 * See @ref mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1.
 *
 * @implements{REQ_788237}
 */
static mcuxClMac_Mode_t mcuxClMac_Mode_CBCMAC_PaddingISO9797_1_Method1 =
  &mcuxClMac_ModeDescriptor_CBCMAC_PaddingISO9797_1_Method1;


MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_MODES_H_ */
