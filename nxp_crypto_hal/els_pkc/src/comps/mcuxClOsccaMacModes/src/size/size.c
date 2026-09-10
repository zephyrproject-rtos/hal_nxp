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

/**
 *
 * @file:   size.c
 * @brief:  This file contains objects which will be used to measure size of particular types.
 *
 */
#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClKey_Types.h>
#include <mcuxClOscca_Memory.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClOsccaMacModes_Types.h>
#include <internal/mcuxClOsccaMacModes_Ctx.h>
#include <internal/mcuxClOsccaSm4_Internal_Constants.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
/* *********************** */
/* *** Work area sizes *** */
/* *********************** */
volatile uint8_t mcuxClOsccaMacModes_Context_size[sizeof(mcuxClOsccaMacModes_Context_t)];

volatile uint8_t mcuxClOsccaMacModes_Compute_CpuWA_MaxSize[MCUXCLOSCCASM4_BLOCK_SIZE * 4u + MCUXCLOSCCASM4_RK_WORDS * sizeof(uint32_t)];


volatile uint8_t mcuxClOsccaMacModes_Init_CpuWA_Size[sizeof(uint32_t)];
volatile uint8_t mcuxClOsccaMacModes_Update_CpuWA_Size[MCUXCLOSCCASM4_RK_WORDS * sizeof(uint32_t)];
volatile uint8_t mcuxClOsccaMacModes_Final_CpuWA_MaxSize[MCUXCLOSCCASM4_BLOCK_SIZE * 2u + MCUXCLOSCCASM4_RK_WORDS * sizeof(uint32_t)];

volatile uint8_t mcuxClOsccaMacModes_WaCpuMax [MCUXCLOSCCASM4_BLOCK_SIZE * 4u + MCUXCLOSCCASM4_RK_WORDS * sizeof(uint32_t) + 2u * MCUXCLOSCCAMACMODES_MAX_OUTPUT_SIZE];

MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
