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
 * @file:   size.c
 * @brief:  This file contains objects which will be used to measure size of particular types.
 *
 */
#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClOscca_Memory.h>
#include <mcuxClOsccaSm3_Constants.h>
#include <internal/mcuxClOsccaSm3_Internal.h>
#include <internal/mcuxClHash_Internal.h>

#if defined(MCUXCL_FEATURE_HASH_HW_SM3)

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
/* Hash Cpu Workarea size generation */
volatile uint8_t mcuxClOsccaSm3_oneShot_WaCpuSm3 [MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + 2u * MCUXCLOSCCASM3_STATE_SIZE_SM3 + 2u * MCUXCLOSCCASM3_OUTPUT_SIZE_SM3]; // two additional outputSize for compare
volatile uint8_t mcuxClOsccaSm3_oneShot_WaCpuMax [MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + 2u * MCUXCLOSCCASM3_STATE_SIZE_SM3 + 2u * MCUXCLOSCCASM3_OUTPUT_SIZE_SM3]; // two additional outputSize for compare


volatile uint8_t mcuxClOsccaSm3_process_WaCpuSm3 [MCUXCLOSCCASM3_STATE_SIZE_SM3];
volatile uint8_t mcuxClOsccaSm3_process_WaCpuMax [MCUXCLOSCCASM3_STATE_SIZE_SM3];

volatile uint8_t mcuxClOsccaSm3_finish_WaCpuSm3 [2u * MCUXCLOSCCASM3_STATE_SIZE_SM3]; // one additional state for compare
volatile uint8_t mcuxClOsccaSm3_finish_WaCpuMax [2u * MCUXCLOSCCASM3_STATE_SIZE_SM3];

/* Hash multi-part context size generation */
volatile uint8_t mcuxClOsccaSm3_Ctx_size[mcuxClOscca_alignSize(sizeof(mcuxClHash_ContextDescriptor_t) + MCUXCLHASH_CONTEXT_MAX_ALIGNMENT_OFFSET + MCUXCLOSCCASM3_BLOCK_SIZE_SM3 + MCUXCLOSCCASM3_STATE_SIZE_SM3)];

volatile uint8_t mcuxClOsccaSm3_export_import_WaCpu[MCUXCLOSCCASM3_COUNTER_SIZE_SM3 + MCUXCLOSCCASM3_STATE_SIZE_SM3];

MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
#endif /* MCUXCL_FEATURE_HASH_SW_SM3 || MCUXCL_FEATURE_HASH_HW_SM3 */
