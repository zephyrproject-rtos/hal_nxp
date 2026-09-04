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

#include <mcuxCsslAnalysis.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClXof_Types.h>
#include <internal/mcuxClXof_Internal.h>
#include <internal/mcuxClHashModes_Internal_Memory.h>
#include <internal/mcuxClXofModes_Internal_Memory.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
volatile uint8_t mcuxClXof_WaCpuMax          [MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE];
volatile uint8_t mcuxClXof_compute_WaCpuMax  [MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE];
volatile uint8_t mcuxClXof_init_WaCpuMax     [MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE];
volatile uint8_t mcuxClXof_process_WaCpuMax  [MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE];
volatile uint8_t mcuxClXof_generate_WaCpuMax [MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE];
volatile uint8_t mcuxClXof_finish_WaCpuMax   [MCUXCLXOF_INTERNAL_WACPU_SIZE_SHAKE];

/* Xof multipart context size generation */
volatile uint8_t mcuxClXof_Ctx_size_max      [MCUXCLXOFMODES_CONTEXT_MAX_SIZE_INTERNAL];
volatile uint8_t mcuxClXof_Shake128_Ctx_size [MCUXCLXOFMODES_SHAKE128_CONTEXT_SIZE_INTERNAL];
volatile uint8_t mcuxClXof_Shake256_Ctx_size [MCUXCLXOFMODES_SHAKE256_CONTEXT_SIZE_INTERNAL];
volatile uint8_t mcuxClXof_SecShake128_Ctx_size [MCUXCLXOFMODES_SECSHAKE128_CONTEXT_SIZE_INTERNAL];
volatile uint8_t mcuxClXof_SecShake256_Ctx_size [MCUXCLXOFMODES_SECSHAKE256_CONTEXT_SIZE_INTERNAL];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
