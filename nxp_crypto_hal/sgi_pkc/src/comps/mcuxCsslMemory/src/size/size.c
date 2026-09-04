/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

#include <stdint.h>
#include <mcuxCsslMemory_Constants.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
volatile uint8_t mcuxCsslMemory_OK_hi16               [MCUXCSSLMEMORY_STATUS_OK                >> 16u];
volatile uint8_t mcuxCsslMemory_EQUAL_hi16            [MCUXCSSLMEMORY_STATUS_EQUAL             >> 16u];
volatile uint8_t mcuxCsslMemory_NOT_EQUAL_hi16        [MCUXCSSLMEMORY_STATUS_NOT_EQUAL         >> 16u];
volatile uint8_t mcuxCsslMemory_INVALID_PARAMETER_hi16[MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER >> 16u];
volatile uint8_t mcuxCsslMemory_FAULT_hi16            [MCUXCSSLMEMORY_STATUS_FAULT             >> 16u];

volatile uint8_t mcuxCsslMemory_OK_lo16               [MCUXCSSLMEMORY_STATUS_OK                & 0xFFFFu];
volatile uint8_t mcuxCsslMemory_EQUAL_lo16            [MCUXCSSLMEMORY_STATUS_EQUAL             & 0xFFFFu];
volatile uint8_t mcuxCsslMemory_NOT_EQUAL_lo16        [MCUXCSSLMEMORY_STATUS_NOT_EQUAL         & 0xFFFFu];
volatile uint8_t mcuxCsslMemory_INVALID_PARAMETER_lo16[MCUXCSSLMEMORY_STATUS_INVALID_PARAMETER & 0xFFFFu];
volatile uint8_t mcuxCsslMemory_FAULT_lo16            [MCUXCSSLMEMORY_STATUS_FAULT             & 0xFFFFu];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
