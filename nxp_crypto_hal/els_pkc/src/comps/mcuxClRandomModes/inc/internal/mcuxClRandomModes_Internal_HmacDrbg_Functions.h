/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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
 *
 * @file:   mcuxClRandomModes_Internal_HmacDrbg_Functions.h
 * @brief:  This file contains function declarations and size definitions for HMAC_DRBG functionality to be used by other components.
 *
 */

#ifndef MCUXCLRANDOMMODES_INTERNAL_HMACDRBG_FUNCTIONS_H
#define MCUXCLRANDOMMODES_INTERNAL_HMACDRBG_FUNCTIONS_H

#include <mcuxClConfig.h> // Exported features flags header

#include <internal/mcuxClKey_Types_Internal.h>
#include <mcuxClCore_Macros.h>
#include <internal/mcuxClRandom_Internal_Types.h>
#include <mcuxClHashModes_Constants.h>
#include <mcuxClMac.h>
#include <internal/mcuxClRandomModes_Private_Drbg.h>
#include <internal/mcuxClRandomModes_Private_HmacDrbg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* As HMAC DRBG has no public visibility at the moment, size definitions are included here. */
#define MCUXCLRANDOMMODES_HMAC_DRBG_MODE_DESCRIPTOR_SIZE          (sizeof(mcuxClRandom_ModeDescriptor_t) + sizeof(mcuxClRandomModes_DrbgModeDescriptor_t) + sizeof(mcuxClRandomModes_DrbgVariantDescriptor_t))
#define MCUXCLRANDOMMODES_HMAC_DRBG_MODE_DESCRIPTOR_SIZE_IN_WORDS (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRANDOMMODES_HMAC_DRBG_MODE_DESCRIPTOR_SIZE))
#define MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE              (sizeof(mcuxClRandomModes_Context_HmacDrbg_Generic_t))
#define MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE_IN_WORDS     (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRANDOMMODES_HMAC_DRBG_MAX_CONTEXT_SIZE))
#define MCUXCLRANDOMMODES_HMAC_DRBG_GENERATE_WACPU_SIZE           (sizeof(mcuxClKey_Descriptor_t) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHMAC_INTERNAL_MAX_CONTEXT_SIZE) + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLHMAC_INTERNAL_MAX_WACPU))
#define MCUXCLRANDOMMODES_HMAC_DRBG_GENERATE_WACPU_SIZE_IN_WORDS  (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRANDOMMODES_HMAC_DRBG_GENERATE_WACPU_SIZE))

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_createCustomHmacDrbgMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_createCustomHmacDrbgMode(
    mcuxClRandom_ModeDescriptor_t *randomMode,
    mcuxClMac_Mode_t hmacMode,
    uint32_t initSeedSize,
    uint32_t reseedSeedSize);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_INTERNAL_HMACDRBG_FUNCTIONS_H */
