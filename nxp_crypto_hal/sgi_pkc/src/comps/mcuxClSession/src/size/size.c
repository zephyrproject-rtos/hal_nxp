/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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
#include <mcuxClSession_Types.h>
#include <internal/mcuxClSession_Internal_EntryExit_EarlyExit_Types.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()


volatile uint8_t mcuxClSession_Descriptor_SIZE [sizeof(mcuxClSession_Descriptor_t)];

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
volatile uint8_t mcuxClSession_Status_API_Entered_hi16           [MCUXCLSESSION_STATUS_API_ENTERED            >> 16u];
volatile uint8_t mcuxClSession_Status_API_Entered_lo16           [MCUXCLSESSION_STATUS_API_ENTERED            & 0xFFFFu];
volatile uint8_t mcuxClSession_Status_EXIT_FA_hi16               [MCUXCLSESSION_STATUS_EXIT_FA                >> 16u];
volatile uint8_t mcuxClSession_Status_EXIT_FA_lo16               [MCUXCLSESSION_STATUS_EXIT_FA                & 0xFFFFu];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

volatile uint8_t mcuxClSession_wordlen                            [sizeof(void*)];
volatile uint8_t mcuxClSession_apiCallOffset                      [offsetof(struct mcuxClSession_Descriptor, apiCall) + 1u];   /* Added +1 to avoid [0] */
volatile uint8_t mcuxClSession_apiCallFaultStatusOffset           [offsetof(struct mcuxClSession_apiCall, faultStatus) + 1u];  /* Added +1 to avoid [0] */
volatile uint8_t mcuxClSession_apiCallDiBackupOffset              [offsetof(struct mcuxClSession_apiCall, diBackup) + 1u];     /* Added +1 to avoid [0] */
volatile uint8_t mcuxClSession_apiCallPreviousOffset              [offsetof(struct mcuxClSession_apiCall, previous) + 1u];     /* Added +1 to avoid [0] */
volatile uint8_t mcuxClSession_apiCallCpuRegisterBackupOffset     [offsetof(struct mcuxClSession_apiCall, cpuRegisterBackup) + 1u];    /* Added +1 to avoid [0] */

MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
