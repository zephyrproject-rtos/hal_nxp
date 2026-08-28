/*--------------------------------------------------------------------------*/
/* Copyright 2024-2025 NXP                                                  */
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

#include <mcuxClMac.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClHmac_Internal_Functions.h>
#include <internal/mcuxClHmac_Internal_Types.h>
#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSession_Internal.h>

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHmac_cleanupOnExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_cleanupOnExit(
    mcuxClSession_Handle_t session,
    uint32_t *pMemoryToClear,
    size_t wordSizeMemoryToClear,
    size_t wordSizeCpuWaBuffer)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHmac_cleanupOnExit);

    /* Clear sensitive information in cpuWa, if any. */
    if(NULL != pMemoryToClear)
    {
        MCUX_CSSL_DI_RECORD(clearSecureDI, pMemoryToClear);
        MCUX_CSSL_DI_RECORD(clearSecureDI, wordSizeMemoryToClear * sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Conversion from word size to byte size cannot wrap.")
        MCUXCLMEMORY_CLEAR_SECURE_INT((uint8_t*)pMemoryToClear, wordSizeMemoryToClear * sizeof(uint32_t));
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }

    /* Free CPU WA in Session */
    mcuxClSession_freeWords_cpuWa(session, wordSizeCpuWaBuffer);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClHmac_cleanupOnExit,
        MCUX_CSSL_FP_CONDITIONAL((NULL != pMemoryToClear),
            MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT
        )
    );
}
