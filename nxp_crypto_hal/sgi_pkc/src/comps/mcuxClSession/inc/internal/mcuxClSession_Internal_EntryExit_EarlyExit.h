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
 * @file mcuxClSession_Internal_EntryExit_EarlyExit.h
 */


#ifndef MCUXCLSESSION_INTERNAL_ENTRYEXIT_EARLYEXIT_H_
#define MCUXCLSESSION_INTERNAL_ENTRYEXIT_EARLYEXIT_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClToolchain.h>

#include <mcuxClSession_Types.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit_EarlyExit_Types.h>

/**
 * \brief Function to set up the Session apiCall when entering an API function:
 *   - the previous DI value is backed up
 *   - the fault status is set
 *
 * \param session     Handle for the current CL session.
 * \param pCallCtx    API call context that is allocated on the stack by the caller.
 * \param faultStatus Fault status value for the current API.
 *
 * \retval MCUXCLSESSION_STATUS_OK             API function entered
 * \retval MCUXCLSESSION_STATUS_ERROR          Fault attack detected
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_entry)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSession_Status_t) mcuxClSession_entry(mcuxClSession_Handle_t session, mcuxClSession_apiCall_t * pCallCtx, uint32_t faultStatus);

/**
 * \brief Function to perform a long jump back to the SESSION_ENTRY of the calling CL API Function.
 *  All necessary information are taken from the session.
 *  This function should only be used in case of an unrecoverable error (e.g. fault attack) to exit the CL immediately.
 *
 * \param returnCode     Return code for the calling API function. We use the returnCode as the first parameter (and not the session like usually),
 *                       so that the returnCode does not have to be moved in the assembly implementation.
 * \param session        Handle for the current CL session.
 *
 * Does not return but instead trigger a long jump back to the closest calling CL API function.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSession_return)
void mcuxClSession_return(uint32_t returnCode, mcuxClSession_Handle_t session) NORETURN;

/**
 * \def MCUXCLSESSION_ENTRY_IMPLn
 * \brief Enter a CL API function
 *
 * This macro is the implementation macro of MCUXCLSESSION_ENTRY, with more than 4 arguments.
 * It allocates a Session apiCall context on the stack, and calls mcuxClSession_entry that backs
 * up the current DI value and sets up the apiCall context.
 *
 * \param session       Handle for the current CL session.
 * \param functionID    Flow Protection identifier of the function that has just been entered.
 * \param diBackupValue Fresh variable name to back up the current DI value (unused).
 * \param faultStatus   Fault status value for the current API.
 * \param expectations  One or more (comma separated) declarations of expected code
 *                      flow behavior.
 */
#define MCUXCLSESSION_ENTRY_IMPLn(session, functionID, diBackupValue, faultStatus, ...) \
      MCUX_CSSL_FP_FUNCTION_ENTRY(functionID, __VA_ARGS__);                          \
      /* Allocate DI and backup relevant session parameters */                      \
      mcuxClSession_apiCall_t sessionCallCtx;                                        \
      mcuxClSession_Status_t resultSessionEntry = MCUX_CSSL_FP_RESULT(mcuxClSession_entry(session, &sessionCallCtx, faultStatus)); \
      if((mcuxClSession_Status_t) MCUXCLSESSION_STATUS_API_ENTERED != resultSessionEntry) \
      {                                                                             \
          /* Early exit detected. Restore previous apiCall info. */                 \
          /* This allows the (CL internal)-caller to call cleanup functions before codeflow is returned to the user. */ \
          (session)->apiCall = (session)->apiCall->previous;                        \
          /* Return to caller without SC or DI check. This code is only reached after an early exit in the error or  */ \
          /* fault attack case. Here, we don't need to check the SC or DI. */       \
          MCUX_CSSL_FP_FUNCTION_EXIT(functionID, resultSessionEntry);                \
      }

/**
 * \def MCUXCLSESSION_ENTRY_IMPL4
 * \brief Enter a CL API function
 *
 * This macro is the implementation macro of MCUXCLSESSION_ENTRY, with exactly 4 arguments.
 * It is a wrapper around MCUXCLSESSION_ENTRY_IMPLn.
 *
 * \param session       Handle for the current CL session.
 * \param functionID    Flow Protection identifier of the function that has just been entered.
 * \param diBackupValue Fresh variable name to back up the current DI value (unused).
 * \param faultStatus   Fault status value for the current API.
 */
#define MCUXCLSESSION_ENTRY_IMPL4(session, functionID, diBackupValue, faultStatus) \
      MCUXCLSESSION_ENTRY_IMPLn(session, functionID, diBackupValue, faultStatus, 0u)

/**
 * \def MCUXCLSESSION_EXIT_IMPLn
 * \brief Exit a CL API function
 *
 * This macro is the implementation macro of MCUXCLSESSION_EXIT, with more than 5 arguments.
 * It checks the DI value against the initial value, and exits with Fault Attack if there is a mismatch.
 * It checks the FP value, and exits with Fault Attack if there is a mismatch.
 *
 * \param session      Handle for the current CL session.
 * \param functionID   Flow Protection identifier of the function that has just been entered.
 * \param diRefValue   DI reference value (unused).
 * \param returnStatus Status that should be returned to the caller (should be a normal status code).
 * \param faultStatus  Fault status value for the current API.
 * \param expectations One or more (comma separated) declarations of expected code
 *                     flow behavior.
 */
#define MCUXCLSESSION_EXIT_IMPLn(session, functionID, diRefValue, returnStatus, faultStatus, ...) \
      /* Only normal status codes should be expected here */ \
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT("Constant values are allowed as an argument to macro function") \
      if((MCUXCLCORE_CLS_ABNORMAL == MCUXCLCORE_GET_CLS(returnStatus)) || (MCUXCLCORE_CLS_ATTACK == MCUXCLCORE_GET_CLS(returnStatus))) \
      { \
          MCUX_CSSL_FP_FUNCTION_EXIT(functionID, faultStatus); \
      } \
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CONTROLLING_EXPRESSION_IS_INVARIANT() \
      /* Check DI value, and exit with faultStatus if the comparison fails. */ \
      MCUX_CSSL_DI_CHECK_EXIT(functionID, (session)->apiCall->diBackup, faultStatus); \
      /* Restore previous apiCall info */ \
      (session)->apiCall = (session)->apiCall->previous; \
      /* Exit CL API function */ \
      MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK(functionID, returnStatus, faultStatus, __VA_ARGS__)

/**
 * \def MCUXCLSESSION_EXIT_IMPL5
 * \brief Exit a CL API function
 *
 * This macro is the implementation macro of MCUXCLSESSION_EXIT, with exactly 5 arguments.
 * It is a wrapper around MCUXCLSESSION_EXIT_IMPLn.
 *
 * \param session      Handle for the current CL session.
 * \param functionID   Flow Protection identifier of the function that has just been entered.
 * \param diRefValue   DI reference value (unused).
 * \param returnStatus Status that should be returned to the caller in the absence of fault attack.
 * \param faultStatus  Fault status value for the current API.
 */
#define MCUXCLSESSION_EXIT_IMPL5(session, functionID, diRefValue, returnStatus, faultStatus) \
      MCUXCLSESSION_EXIT_IMPLn(session, functionID, diRefValue, returnStatus, faultStatus, 0u)

/**
 * \def MCUXCLSESSION_FAULT_IMPL
 * \brief Exit a CL API function
 *
 * This macro is the implementation macro of MCUXCLSESSION_FAULT.
 * It exits the current function via a longjump back to the MCUXCLSESSION_ENTRY of the calling CL API function.
 * There is no DI or FP balancing or checking.
 * Intermediate functions between the current and the calling CL API function are skipped.
 *
 * \param session      Handle for the current CL session.
 * \param faultStatus  Fault status value for the current API.
 */
#define MCUXCLSESSION_FAULT_IMPL(session, faultStatus)     \
      mcuxClSession_return(faultStatus, session)

/**
 * \def MCUXCLSESSION_ERROR_IMPL
 * \brief Exit a CL API function
 *
 * This macro is the implementation macro of MCUXCLSESSION_ERROR.
 * It exits the current function via a longjump back to the MCUXCLSESSION_ENTRY of the calling CL API function.
 * There is no DI or FP balancing or checking.
 * Intermediate functions between the current and the calling CL API function are skipped.
 *
 * \param session      Handle for the current CL session.
 * \param faultStatus  Error status value for the current API.
 */
#define MCUXCLSESSION_ERROR_IMPL(session, errorStatus)     \
      mcuxClSession_return(errorStatus, session)

/**
 * \brief Implementation of MCUXCLSESSION_CHECK_ERROR_FAULT_IMPL.
 *        We use a static inline function to reduce the CCM.
 *
 * \param session      Handle for the current CL session.
 * \param status       Status code which is checked for errors and faults.
 */
static inline void mcuxClSession_CheckErrorFault(mcuxClSession_Handle_t session, uint32_t status)
{
  if((MCUXCLCORE_CLS_NORMAL != MCUXCLCORE_GET_CLS(status)) && (MCUXCLCORE_CLS_NORMALMISMATCH != MCUXCLCORE_GET_CLS(status)))
  {
    mcuxClSession_return(status, session);
  }
}

/**
 * \def MCUXCLSESSION_CHECK_ERROR_FAULT_IMPL
 * \brief Exit a CL API function in case of error, fault
 *
 * This macro is the implementation macro of MCUXCLSESSION_CHECK_ERROR_FAULT
 * It performs check if abnormal or fault was received. If true it exits the current function
 * via a longjump back to the MCUXCLSESSION_ENTRY of the calling CL API function.
 * Intermediate functions between the current and the calling CL API function are skipped.
 * There is no DI or FP balancing or checking.
 *
 * On normal status it will not perform any action and allow execution to continue.
 *
 * \param session      Handle for the current CL session (unused).
 * \param status       Status value for the current API.
 */
#define MCUXCLSESSION_CHECK_ERROR_FAULT_IMPL(session, status) \
      mcuxClSession_CheckErrorFault(session, status)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSESSION_INTERNAL_ENTRYEXIT_EARLYEXIT_H_ */
