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
 * @file: size.c
 * @brief: This file contains objects which will be used to measure size of particular types.
 *
 */

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClHmac_Internal_Memory.h>

/*************************/
/**** Work area sizes ****/
/*************************/

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()

/* Context and WA for MAC computation */
volatile uint8_t mcuxClHmac_Context[MCUXCLHMAC_INTERNAL_CONTEXT_SIZE];

volatile uint8_t mcuxClHmac_WorkArea_Init[MCUXCLHMAC_INTERNAL_WACPU_INIT];
volatile uint8_t mcuxClHmac_WorkArea_Process[4u];
volatile uint8_t mcuxClHmac_WorkArea_Finish[MCUXCLHMAC_INTERNAL_WACPU_FINISH];
volatile uint8_t mcuxClHmac_WorkArea_Compute[MCUXCLHMAC_INTERNAL_WACPU_COMPUTE];
volatile uint8_t mcuxClHmac_WorkArea_Compare[MCUXCLHMAC_INTERNAL_WACPU_COMPARE];
volatile uint8_t mcuxClHmac_WorkArea_Verify[MCUXCLHMAC_INTERNAL_WACPU_VERIFY];
volatile uint8_t mcuxClHmac_WorkArea_Max[MCUXCLHMAC_INTERNAL_MAX_WACPU];

/* Mode-specific structures */
volatile uint8_t mcuxClHmac_ModeDescriptor_size[sizeof(mcuxClMac_ModeDescriptor_t) + sizeof(mcuxClHmac_ModeDescriptor_t)];

MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
