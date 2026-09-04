/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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

#include <mcuxClToolchain.h>
#include <mcuxClHash.h>
#include <mcuxClHashModes.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClMemory_Internal.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClHashModes_Internal_Resource_Common.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClHashModes_Internal_sgi_sha2_common.h>


/**********************************************************
 * Algorithm descriptor implementations
 **********************************************************/

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha224 =
{
    .sgiUtilsInitHash                 = mcuxClSgi_Utils_initSha224,
    .protectionToken_sgiUtilsInitHash = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_initSha224),
};




const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha256 =
{
    .sgiUtilsInitHash                 = mcuxClSgi_Utils_initSha256,
    .protectionToken_sgiUtilsInitHash = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_initSha256),
};



const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha384 =
{
    .sgiUtilsInitHash                 = mcuxClSgi_Utils_initSha384,
    .protectionToken_sgiUtilsInitHash = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_initSha384),
};


const mcuxClHashModes_Internal_AlgorithmDescriptor_t mcuxClHashModes_Internal_AlgorithmDescriptor_Sgi_Sha512 =
{
    .sgiUtilsInitHash                 = mcuxClSgi_Utils_initSha512,
    .protectionToken_sgiUtilsInitHash = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_initSha512),
};




MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
