/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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
#include <mcuxCsslAnalysis.h>

#include <mcuxClCore_Macros.h>
#include <internal/mcuxClMacModes_Common_Types.h>
#include <internal/mcuxClMacModes_Common_Memory.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>


/*************************/
/**** Work area sizes ****/
/*************************/

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()

/* Context and WA for MAC computation */
volatile mcuxClMacModes_Context_t mcuxClMacModes_Ctx;
volatile uint8_t mcuxClMacModes_WA[MCUXCLMACMODES_INTERNAL_WASIZE];

/* Mode-specific structures */
volatile uint8_t mcuxClMacModes_GmacModeDescriptor_SIZE[sizeof(mcuxClMac_ModeDescriptor_t) + sizeof(mcuxClMacModes_GmacModeDescriptor_t)];


MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
