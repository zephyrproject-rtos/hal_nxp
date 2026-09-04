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
 * @file mcuxClSession_Internal_EntryExit_EarlyExit_Types.h
 */


#ifndef MCUXCLSESSION_INTERNAL_ENTRYEXIT_EARLYEXIT_TYPES_H_
#define MCUXCLSESSION_INTERNAL_ENTRYEXIT_EARLYEXIT_TYPES_H_

#define MCUXCLSESSION_STATUS_API_ENTERED         (0x0EEE2E47u)
#define MCUXCLSESSION_STATUS_EXIT_FA             (0x0EEEF0F0u)
#define MCUXCLSESSION_NUMBER_OF_SAVED_REGISTERS  (10u) /* r4-r11, sp, lr */

/**
 * Structure that holds the necessary information to enter/exit CL API functions, including early exit.
 */
struct mcuxClSession_apiCall
{
  uint32_t faultStatus;     ///< status to be returned in case of fault
  uint32_t diBackup;        ///< backup of original value of DI upon entry of CL API function
  struct mcuxClSession_apiCall *previous; ///< To be set in entry and restored in exit of CL API function to allow multiple levels of CL API calls from within CL
  uint32_t cpuRegisterBackup[MCUXCLSESSION_NUMBER_OF_SAVED_REGISTERS]; ///< CPU Register backup for early exit longjump. Needs to hold s0-s11, ra, sp and upcsstate.
};

#endif /* MCUXCLSESSION_INTERNAL_ENTRYEXIT_EARLYEXIT_TYPES_H_ */
