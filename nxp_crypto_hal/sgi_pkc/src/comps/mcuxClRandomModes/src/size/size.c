/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file:	size.c
 * @brief:	This file contains objects which will be used to measure size of particular types.
 *
 */

#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClRandomModes_Internal_SizeDefinitions.h>

#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>
#include <mcuxClRandom_Types.h>
#include <internal/mcuxClRandom_Internal_Types.h>

/* *********************** */
/* *** Work area sizes *** */
/* *********************** */
MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
volatile uint8_t mcuxClRandom_Mode_Descriptor_size[sizeof(mcuxClRandom_ModeDescriptor_t)];

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
volatile mcuxClRandomModes_Context_CtrDrbg_Aes128_t mcuxClRandomModes_Context_Aes128;
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
volatile mcuxClRandomModes_Context_CtrDrbg_Aes192_t mcuxClRandomModes_Context_Aes192;
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
volatile mcuxClRandomModes_Context_CtrDrbg_Aes256_t mcuxClRandomModes_Context_Aes256;
#endif

volatile mcuxClRandom_Context_t mcuxClRandomModes_Context_PatchMode;

volatile uint8_t mcuxClRandomModes_CpuWA_MaxSize[MCUXCLRANDOMMODES_CPUWA_MAXSIZE];
volatile uint8_t mcuxClRandomModes_init_CpuWA_Size[MCUXCLRANDOMMODES_INIT_WACPU_SIZE_MAX];
volatile uint8_t mcuxClRandomModes_reseed_CpuWA_Size[MCUXCLRANDOMMODES_RESEED_WACPU_SIZE_MAX];
volatile uint8_t mcuxClRandomModes_generate_CpuWA_Size[MCUXCLRANDOMMODES_GENERATE_WACPU_SIZE_MAX];
volatile uint8_t mcuxClRandomModes_selftest_CpuWA_Size[MCUXCLRANDOMMODES_SELFTEST_WACPU_SIZE_MAX];

/* *********************** */
/* *** Entropy sizes   *** */
/* *********************** */
#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_128
volatile uint8_t mcuxClRandomModes_TestMode_CtrDrbg_Aes128_Entropy_Input_Init_size[MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES128];
volatile uint8_t mcuxClRandomModes_TestMode_CtrDrbg_Aes128_Entropy_Input_Reseed_size[MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES128];
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_192
volatile uint8_t mcuxClRandomModes_TestMode_CtrDrbg_Aes192_Entropy_Input_Init_size[MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES192];
volatile uint8_t mcuxClRandomModes_TestMode_CtrDrbg_Aes192_Entropy_Input_Reseed_size[MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES192];
#endif

#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256
volatile uint8_t mcuxClRandomModes_TestMode_CtrDrbg_Aes256_Entropy_Input_Init_size[MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_INIT_CTR_DRBG_AES256];
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
volatile uint8_t mcuxClRandomModes_TestMode_CtrDrbg_Aes256_Entropy_Input_Reseed_size[MCUXCLRANDOMMODES_ENTROPYINPUT_SIZE_RESEED_CTR_DRBG_AES256];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
#endif

MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
