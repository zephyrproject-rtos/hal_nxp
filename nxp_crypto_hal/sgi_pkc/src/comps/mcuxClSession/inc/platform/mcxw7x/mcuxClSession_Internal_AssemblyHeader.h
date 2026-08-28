/*--------------------------------------------------------------------------*/
/* Copyright 2024 NXP                                                       */
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
 * @file  mcuxClSession_Internal_AssemblyHeader.h
 * @brief Constant definitions for the mcuxClSession Early Exit assembly implementation
 */

#ifndef MCUXCLSESSION_INTERNAL_ASSEMBLYHEADER_H_
#define MCUXCLSESSION_INTERNAL_ASSEMBLYHEADER_H_

#define MCUXCLSESSION_STATUS_ASM_API_ENTERED     ((3822 << 16) | 11847)
#define MCUXCLSESSION_STATUS_ASM_EXIT_FA         ((3822 << 16) | 61680)

#define WORDLEN                     (4)                                   /* CPU word length */
#define APICALL_OFFSET              (85 - 1)                         /* Index of apiCall in struct mcuxClSession_Descriptor */

#define FAULTSTATUS_OFFSET          (1 - 1)              /* Index of faultStatus in struct mcuxClSession_apiCall */
#define DIBACKUP_OFFSET             (5 - 1)                 /* Index of diBackup in struct mcuxClSession_apiCall */
#define PREVIOUS_OFFSET             (9 - 1)                 /* Index of previous in struct mcuxClSession_apiCall */
#define CPUREGISTERBACKUP_OFFSET    (13 - 1)        /* Index of cpuRegisterBackup in struct mcuxClSession_apiCall */

#define CPUREGISTERBACKUP_NUMBEROF_S_REGISTERS  (8)                                             /* Number of S registers to backup */
#define CPUREGISTERBACKUP_S(s_index)            (CPUREGISTERBACKUP_OFFSET + s_index * WORDLEN)  /* Index of S register in cpuRegisterBackup */
#define CPUREGISTERBACKUP_RA                    (CPUREGISTERBACKUP_OFFSET + CPUREGISTERBACKUP_NUMBEROF_S_REGISTERS * WORDLEN)       /* Index of RA register in cpuRegisterBackup */
#define CPUREGISTERBACKUP_SP                    (CPUREGISTERBACKUP_OFFSET + (CPUREGISTERBACKUP_NUMBEROF_S_REGISTERS + 1) * WORDLEN) /* Index of SP register in cpuRegisterBackup */
#define CPUREGISTERBACKUP_UPCSSTATE             (CPUREGISTERBACKUP_OFFSET + (CPUREGISTERBACKUP_NUMBEROF_S_REGISTERS + 2) * WORDLEN) /* Index of UPCSSTATE register in cpuRegisterBackup */


#endif /* MCUXCLSESSION_INTERNAL_ASSEMBLYHEADER_H_ */
