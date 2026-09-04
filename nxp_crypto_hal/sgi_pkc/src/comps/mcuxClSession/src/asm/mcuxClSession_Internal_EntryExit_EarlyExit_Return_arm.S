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

/**
 * @file  mcuxClSession_Internal_EntryExit_EarlyExit_Return_asm.S
 */

#include <mcuxClSession_Internal_AssemblyHeader.h>

#define rReturnCode    r0      /* returnCode, status code of the Clib */ /* UNUSED */
#define rPSession      r1      /* pSession, pointer to the session */
#ifdef CORTEXM0
#define rAPIcall       r2      /* session->apiCall */
#else
#define rAPIcall       r12     /* session->apiCall */
#endif

#ifdef __IASMARM__
    NAME mcuxClSession_return
    SECTION .text:CODE(2)
    PUBLIC  mcuxClSession_return
#else
.syntax unified
.thumb
.section .text.mcuxClSession_return, "ax"
.global        mcuxClSession_return
.type          mcuxClSession_return, "function"
#endif

/**
 * void mcuxClSession_return(returnCode, session)
 * r0 = returnCode
 * r1 = session
 */
mcuxClSession_return:
    /* Restore CPU registers to prepare longjump */
    ldr rAPIcall, [rPSession, #APICALL_OFFSET]
#ifdef CORTEXM0
    mov r12, rAPIcall
    ldr r4, [rAPIcall, #CPUREGISTERBACKUP_S(4)]
    ldr r5, [rAPIcall, #CPUREGISTERBACKUP_S(5)]
    ldr r6, [rAPIcall, #CPUREGISTERBACKUP_S(6)]
    ldr r7, [rAPIcall, #CPUREGISTERBACKUP_S(7)]
    mov r8, r4
    mov r9, r5
    mov r10, r6
    mov r11, r7
    ldr r4, [rAPIcall, #CPUREGISTERBACKUP_SP]
    mov sp, r4
    ldr r4, [rAPIcall, #CPUREGISTERBACKUP_RA]
    mov lr, r4
    ldr r4, [rAPIcall, #CPUREGISTERBACKUP_S(0)]
    ldr r5, [rAPIcall, #CPUREGISTERBACKUP_S(1)]
    ldr r6, [rAPIcall, #CPUREGISTERBACKUP_S(2)]
    ldr r7, [rAPIcall, #CPUREGISTERBACKUP_S(3)]
#else
    ldr r4, [rAPIcall, #CPUREGISTERBACKUP_S(0)]
    ldr r5, [rAPIcall, #CPUREGISTERBACKUP_S(1)]
    ldr r6, [rAPIcall, #CPUREGISTERBACKUP_S(2)]
    ldr r7, [rAPIcall, #CPUREGISTERBACKUP_S(3)]
    ldr r8, [rAPIcall, #CPUREGISTERBACKUP_S(4)]
    ldr r9, [rAPIcall, #CPUREGISTERBACKUP_S(5)]
    ldr r10, [rAPIcall, #CPUREGISTERBACKUP_S(6)]
    ldr r11, [rAPIcall, #CPUREGISTERBACKUP_S(7)]
    ldr lr, [rAPIcall, #CPUREGISTERBACKUP_RA]
    ldr sp, [rAPIcall, #CPUREGISTERBACKUP_SP]
#endif

    /* Perform longjump to ra extracted from session->apiCall */
    bx lr

#ifdef __IASMARM__
    END
#else
.mcuxClSession_return_End:
.size       mcuxClSession_return, .mcuxClSession_return_End - mcuxClSession_return
#endif
