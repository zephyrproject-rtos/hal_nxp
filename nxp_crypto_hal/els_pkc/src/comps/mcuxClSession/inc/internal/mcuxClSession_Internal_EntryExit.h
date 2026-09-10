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

/**
 * @file mcuxClSession_Internal_EntryExit.h
 */


#ifndef MCUXCLSESSION_INTERNAL_ENTRYEXIT_H_
#define MCUXCLSESSION_INTERNAL_ENTRYEXIT_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslCPreProcessor.h>

#include <mcuxClSession_Types.h>

/* Include the selected implementation of the session entry/exit mechanism. */
/* Default implementation that supports DI/FP initialization and check */
#  include <internal/mcuxClSession_Internal_EntryExit_RegularReturn.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \def MCUXCLSESSION_ENTRY
 * \brief Enter a CL API function
 *
 * This macro shall be called when entering a CL API function.
 * It performs the necessary set up for the API call, including the preparation
 * of the data integrity and flow protection mechanisms.
 *
 * \param ...  The following parameters need to be passed (comma separated):
 *             - session:       Handle for the current CL session.
 *             - functionID:    Flow Protection identifier of the function that has just been entered.
 *             - diBackupValue: Fresh variable name to back up the current DI value.
 *             - faultStatus:   Fault status value for the current API.
 *             - expectations:  Zero or more (comma separated) declarations of expected code
 *                              flow behavior.
 */
#define MCUXCLSESSION_ENTRY(...) \
      MCUX_CSSL_CPP_OVERLOADED4(MCUXCLSESSION_ENTRY_IMPL, __VA_ARGS__)

/**
 * \def MCUXCLSESSION_EXIT
 * \brief Exit a CL API function
 *
 * This macro shall be called when exiting a CL API function.
 * It restores necessary parameters to allow nesting CL API calls, and verifies
 * the data integrity and flow protection values.
 *
 * \param ...  The following parameters need to be passed (comma separated):
 *             - session:      Handle for the current CL session.
 *             - functionID:   Flow Protection identifier of the function that has just been entered.
 *             - diRefValue:   DI reference value.
 *             - returnStatus: Status that should be returned to the caller in the absence of fault attack.
 *             - faultStatus:  Fault status value for the current API.
 *             - expectations: Zero or more (comma separated) declarations of expected code
 *                             flow behavior.
 */
#define MCUXCLSESSION_EXIT(...) \
      MCUX_CSSL_CPP_OVERLOADED5(MCUXCLSESSION_EXIT_IMPL, __VA_ARGS__)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSESSION_INTERNAL_ENTRYEXIT_H_ */
