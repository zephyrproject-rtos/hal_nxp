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

#include <mcuxClRandom_Constants.h>
#include <internal/mcuxClRandomModes_Private_ExitGates.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSession_Internal_Functions.h>
#include <internal/mcuxClRandomModes_Private_CtrDrbg.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_cleanupOnExit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_cleanupOnExit(mcuxClSession_Handle_t session)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRandomModes_cleanupOnExit);

    /* Free CPU WA in Session - SREQI_DRBG_10 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSession_cleanup_freedWorkareas(session));

    /* Clean up HW memory - SREQI_DRBG_10 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_cleanUpHW());

    /* Release HW */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRandomModes_CtrDrbg_releaseHW(session));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClRandomModes_cleanupOnExit,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup_freedWorkareas),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_cleanUpHW),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandomModes_CtrDrbg_releaseHW));
}

