/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023, 2025 NXP                                            */
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
 * @file  mcuxCsslFlowProtection_SecureCounter_Local.h
 * @brief Counter based implementation for the flow protection mechanism, for a local security counter.
 */

#ifndef MCUX_CSSL_FLOW_PROTECTION_SECURE_COUNTER_LOCAL_H_
#define MCUX_CSSL_FLOW_PROTECTION_SECURE_COUNTER_LOCAL_H_

/* Include the CSSL C pre-processor support functionality. */
#include <mcuxCsslCPreProcessor.h>

/* Include the CSSL secure counter mechanism as basic building block. */
#include <mcuxCsslSecureCounter.h>

/* Include Core macros for return type class checks */
#include <mcuxClCore_Macros.h>

/* Include the C99 standard integer types. */
#include <stdint.h>

/* Include standard boolean types */
#include <stdbool.h>

/***********************************************************************/
/* Helper Macros specific to the SC Local backend.                     */
/* Since the security counter is encoded in return values, these       */
/* act as getter and setter for the counter and result within the      */
/* encoded return code.                                                */
/***********************************************************************/

/**
 * @def MCUX_CSSL_FP_RESULT_OFFSET
 * @brief Offset of the result in the return value.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_RESULT_OFFSET \
  (0u)

/**
 * @def MCUX_CSSL_FP_RESULT_MASK
 * @brief Bitmask of the result in the return value.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_RESULT_MASK \
  (0xFFFFFFFFuLL)

/**
 * @def MCUX_CSSL_FP_RESULT_VALUE
 * @brief Encode a result value for a protected return value.
 * @ingroup csslFpCntFunction
 *
 * @param result The result that needs to be encoded.
 */
#define MCUX_CSSL_FP_RESULT_VALUE(result) \
  (((uint64_t)((uint32_t)(result) & MCUX_CSSL_FP_RESULT_MASK) << MCUX_CSSL_FP_RESULT_OFFSET))

/**
 * @def MCUX_CSSL_FP_PROTECTION_OFFSET
 * @brief Offset of the protection token in the return value.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_PROTECTION_OFFSET \
  (32u)

/**
 * @def MCUX_CSSL_FP_PROTECTION_MASK
 * @brief Bitmask of the protection token in the return value.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_PROTECTION_MASK \
  ((uint64_t) 0xFFFFFFFFuLL)

/**
 * @def MCUX_CSSL_FP_PROTECTION_TOKEN_VALUE
 * @brief Encode a protection token for a protected return value.
 * @ingroup csslFpCntFunction
 *
 * Note that this macro is only used with a local security counter,
 * e.g. for configuration CSSL_SC_USE_SW_LOCAL
 *
 * @param token The protection token that needs to be encoded.
 */
#define MCUX_CSSL_FP_PROTECTION_TOKEN_VALUE(token) \
  ((((uint64_t)(token) & MCUX_CSSL_FP_PROTECTION_MASK)) << MCUX_CSSL_FP_PROTECTION_OFFSET)

/**
 * @def MCUX_CSSL_FP_COUNTER_COMPRESSED
 * @brief Compressed version of the secure counter that can be used as a
 *        protection token.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_COUNTER_COMPRESSED() \
  MCUX_CSSL_SC_VALUE()

/***********************************************************************/
/* SC Local backend implementations of top-level FP macros.            */
/***********************************************************************/

/**
 * @def MCUX_CSSL_FP_PROTECTED_TYPE_IMPL
 * @brief Based on a given base type, builds a return type with flow
 *        protection.
 * @ingroup csslFpCntFunction
 *
 * @see MCUX_CSSL_FP_FUNCTION_DEF_IMPL
 *
 * @param resultType The type to be converted into a protected type.
 */
#define MCUX_CSSL_FP_PROTECTED_TYPE_IMPL(resultType) \
  uint64_t

/**
 * @def MCUX_CSSL_FP_RESULT_IMPL2
 * @brief Extract the result value from a protected @p return value.
 * @ingroup csslFpCntFunction
 *
 * @param type   Type of the result.
 * @param return The protected return value which contains the result.
 */
#define MCUX_CSSL_FP_RESULT_IMPL2(type, return) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA("Loss of precision intended") \
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Proper alignment is ensured during type cast") \
  ((type)((uint32_t)(((return) >> MCUX_CSSL_FP_RESULT_OFFSET) & MCUX_CSSL_FP_RESULT_MASK))) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER() \
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_MAY_RESULT_IN_MISINTERPRETED_DATA()

/**
 * @def MCUX_CSSL_FP_RESULT_IMPL1
 * @brief Extract the result value from a protected @p return value.
 * @ingroup csslFpCntFunction
 *
 * @param return The protected return value which contains the result.
 */
#define MCUX_CSSL_FP_RESULT_IMPL1(return) \
  MCUX_CSSL_FP_RESULT_IMPL2(uint32_t,return)

/**
 * @def MCUX_CSSL_FP_RESULT_IMPL
 * @brief Extract the result value from a protected @p return value.
 * @ingroup csslFpCntFunction
 *
 * @param type   Optional, type of the result.
 * @param return The protected return value which contains the result.
 */
#define MCUX_CSSL_FP_RESULT_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUX_CSSL_FP_RESULT_IMPL, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_PROTECTION_TOKEN_IMPL
 * @brief Extract the protection token value from a protected @p return value.
 * @ingroup csslFpCntFunction
 *
 * Note that this macro is only used with a local security counter,
 * e.g. for configuration CSSL_SC_USE_SW_LOCAL
 *
 * @param return The protected return value which contains the protection token.
 */
#define MCUX_CSSL_FP_PROTECTION_TOKEN_IMPL(return) \
  (uint32_t)(((return) >> MCUX_CSSL_FP_PROTECTION_OFFSET) & MCUX_CSSL_FP_PROTECTION_MASK)

/**
 * @def MCUX_CSSL_FP_FUNCTION_ENTRY_IMPLn
 * @brief Flow protection handler implementation for the function entry point.
 * @ingroup csslFpCntFunction
 *
 * Initialize the counter with the entry part of the function identifier, and
 * include expectations in the initialization value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL
 *
 * @param id     Identifier of the function that has just been entered.
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 */
#define MCUX_CSSL_FP_FUNCTION_ENTRY_IMPLn(function, ...) \
  MCUX_CSSL_SC_INIT( \
    MCUX_CSSL_FP_FUNCTION_ID_ENTRY_PART(function) \
    - (MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__)) \
  )

/**
 * @def MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL1
 * @brief Flow protection handler implementation for the function entry point.
 * @ingroup csslFpCntFunction
 *
 * Initialize the counter with the entry part of the function identifier,
 * without any potential expectations.
 *
 * @see MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL
 *
 * @param id Identifier of the function that has just been entered.
 */
#define MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL1(function) \
  MCUX_CSSL_FP_FUNCTION_ENTRY_IMPLn(function, 0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL
 * @brief Flow protection handler implementation for the function entry point.
 * @ingroup csslFpCntFunction
 *
 * Initialize the counter with entry part of the function identifier, and
 * include potential expectations in the initialization value.
 *
 * Implemented as an overloaded macro to simplify the use of the API.
 *
 * @see MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL1
 * @see MCUX_CSSL_FP_FUNCTION_ENTRY_IMPLn
 *
 * @param id     Identifier of the function that has just been entered.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 */
#define MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED1(MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL, __VA_ARGS__)


/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier, and
 * include potential expectations in the adjustment value. Return the counter
 * value together with the @p result via the function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 *
 * @param id     Identifier of the function from which we will exit.
 * @param result Result that should be encoded in the return value.
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A value in which both @p result and a flow protection token
 *               are encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn(id, result, ...) \
  MCUX_CSSL_SC_ADD( \
    MCUX_CSSL_FP_FUNCTION_ID_EXIT_PART(id) \
    - MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__) \
  ); \
  return (MCUX_CSSL_FP_RESULT_VALUE(result) \
    | MCUX_CSSL_FP_PROTECTION_TOKEN_VALUE(MCUX_CSSL_FP_COUNTER_COMPRESSED()))

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPL1
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier, without
 * any potential expectations in the adjustment value. Return the counter value
 * via the function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 *
 * @param id Identifier of the function from which we will exit.
 * @return   A value in which a flow protection token is encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPL1(id) \
  MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn(id, 0u, 0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPL2
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier, without
 * any potential expectations in the adjustment value. Return the counter value
 * together with the @p result via the function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 *
 * @param id     Identifier of the function from which we will exit.
 * @param result Result that should be encoded in the return value.
 * @return       A value in which both @p result and a flow protection token
 *               are encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPL2(id, result) \
  MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn(id, result, 0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier, and
 * include potential expectations in the adjustment value. Return the counter
 * value together with the @p result via the function return value.
 *
 * Implemented as an overloaded macro to simplify the use of the API.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL1
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL2
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn
 *
 * @param id     Identifier of the function from which we will exit.
 * @param result Result that should be encoded in the return value.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A value in which both @p result and a flow protection token
 *               are encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUX_CSSL_FP_FUNCTION_EXIT_IMPL, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPLn
 * @brief Flow protection handler implementation for the function exit point
 *        which includes an actual check of the code flow.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier, and
 * include potential expectations in the adjustment value. Check whether
 * the counter matches the expected value, and choose the result from
 * @p pass and @p fail and return it together with the counter value
 * via the function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL3
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPLn
 *
 * @param id     Identifier of the function from which we will exit.
 * @param pass   Result that should be encoded in the return value if the flow
 *               protection check passed. This should be a normal status code.
 * @param fail   Result that should be encoded in the return value if the flow
 *               protection check failed.
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A value in which both the result (either @p pass or @p fail)
 *               and a flow protection token are encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPLn(id, pass, fail, ...) \
  MCUX_CSSL_SC_ADD(MCUX_CSSL_FP_FUNCTION_ID_EXIT_PART(id) - MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__)); \
  return (MCUX_CSSL_FP_RESULT_VALUE((MCUX_CSSL_SC_CHECK_PASSED == MCUX_CSSL_SC_CHECK(MCUX_CSSL_FP_FUNCTION_VALUE(id))) \
                                     ? pass \
                                     : fail) | \
          MCUX_CSSL_FP_PROTECTION_TOKEN_VALUE(MCUX_CSSL_FP_COUNTER_COMPRESSED()));

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL3
 * @brief Flow protection handler implementation for the function exit point
 *        which includes an actual check of the code flow.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier. Check
 * whether the counter matches the expected value, and choose the result from
 * @p pass and @p fail and return it together with the counter value via the
 * function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL
 *
 * @param id     Identifier of the function from which we will exit.
 * @param pass   Result that should be encoded in the return value if the flow
 *               protection check passed.
 * @param fail   Result that should be encoded in the return value if the flow
 *               protection check failed.
 * @return       A value in which both the result (either @p pass or @p fail)
 *               and a flow protection token are encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL3(id, pass, fail) \
  MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPLn(id, pass, fail, 0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL
 * @brief Flow protection handler implementation for the function exit point
 *        which includes an actual check of the code flow.
 * @ingroup csslFpCntFunction
 *
 * Adjust the counter with the exit part of the function identifier, and
 * include potential expectations in the adjustment value. Check whether the
 * counter matches the expected value, and choose the result from @p pass and
 * @p fail and return it together with the counter value via the function
 * return value.
 *
 * Implemented as an overloaded macro to simplify the use of the API.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL3
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPLn
 *
 * @param id     Identifier of the function from which we will exit.
 * @param pass   Result that should be encoded in the return value if the flow
 *               protection check passed.
 * @param fail   Result that should be encoded in the return value if the flow
 *               protection check failed.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A value in which both the result (either @p pass or @p fail)
 *               and a flow protection token are encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED3(MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL1
 * @brief Flow protection handler for the exit point of functions with the
 *        return type @c void.
 * @ingroup csslFpCntFunction
 *
 * @param id     Identifier of the function from which we will exit.
 * @return       A protected return value of type void.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL1(id) \
  MCUX_CSSL_FP_FUNCTION_EXIT_IMPL(id, 0U)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL2
 * @brief Flow protection handler for the exit point of functions with the
 *        return type @c void.
 * @ingroup csslFpCntFunction
 *
 * @param id     Identifier of the function from which we will exit.
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A protected return value of type void.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPLn(id, ...) \
  MCUX_CSSL_FP_FUNCTION_EXIT_IMPL(id, 0U, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL
 * @brief Flow protection handler for the exit point of functions with the
 *        return type @c void.
 * @ingroup csslFpCntFunction
 *
 * @param id     Identifier of the function from which we will exit.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A protected return value of type void.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED1(MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_IMPL3
 * @brief Event implementation of a flow protected function call.
 * @ingroup csslFpCntFunction
 *
 * @param type   Type of the @p result variable.
 * @param result Fresh variable name to store the result of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_IMPL3(type, result, call) \
  const uint64_t MCUX_CSSL_CPP_CAT(result, _protected) = (call); \
  MCUX_CSSL_SC_ADD_ON_CALL( \
    MCUX_CSSL_FP_PROTECTION_TOKEN(MCUX_CSSL_CPP_CAT(result, _protected))); \
  type const result = MCUX_CSSL_FP_RESULT(type, \
    MCUX_CSSL_CPP_CAT(result, _protected))

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_IMPL2
 * @brief Event implementation of a flow protected function call.
 * @ingroup csslFpCntFunction
 *
 * @param result Fresh variable name to store the result of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_IMPL2(result, call) \
  MCUX_CSSL_FP_FUNCTION_CALL_IMPL3(uint32_t, result, call)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_IMPL
 * @brief Event implementation of a flow protected function call.
 * @ingroup csslFpCntFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 *
 * @param type   Optional, type of the @p result variable.
 * @param result Fresh variable name to store the result of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_IMPL(...) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("False positive, due to macro expansion, any usage of NULL is considered as 0 by Coverity") \
  MCUX_CSSL_CPP_OVERLOADED3(MCUX_CSSL_FP_FUNCTION_CALL_IMPL, __VA_ARGS__) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_IMPL
 * @brief Event implementation of a flow protected void function call.
 * @ingroup csslFpCntFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 *
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_IMPL(call) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("False positive, due to macro expansion, any usage of NULL is considered as 0 by Coverity") \
  { \
  const uint64_t MCUX_CSSL_CPP_CAT(result, _protected) = (call); \
  MCUX_CSSL_SC_ADD_ON_CALL( \
    MCUX_CSSL_FP_PROTECTION_TOKEN(MCUX_CSSL_CPP_CAT(result, _protected))); \
  } \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED_IMPL
 * @brief Implementation of a flow protected function call meant to be used
 *        from within an unprotected function
 * @ingroup csslFpCntFunction
 *
 *
 * @param result Fresh variable name to store the result of @p call.
 * @param token  Fresh variable name to store the protection token of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED_IMPL(result, token, call) \
  const uint64_t MCUX_CSSL_CPP_CAT(result, _protected) = (call); \
  const uint32_t token = MCUX_CSSL_FP_PROTECTION_TOKEN( \
    MCUX_CSSL_CPP_CAT(result, _protected)); \
  const uint32_t result = MCUX_CSSL_FP_RESULT( \
    MCUX_CSSL_CPP_CAT(result, _protected))

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_PROTECTED_IMPL
 * @brief Implementation of a flow protected void function call meant to be
 *        used from within an unprotected function
 * @ingroup csslFpCntFunction
 *
 *
 * @param token  Fresh variable name to store the protection token of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_PROTECTED_IMPL(token, call) \
  const uint64_t MCUX_CSSL_CPP_CAT(token, _protected) = (call); \
  const uint32_t token = MCUX_CSSL_FP_PROTECTION_TOKEN( \
    MCUX_CSSL_CPP_CAT(token, _protected))

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_BEGIN_IMPL
 * @brief Implementation of a flow protected function call meant to be used
 *        from within an unprotected function, that must be terminated by
 *        #MCUX_CSSL_FP_FUNCTION_CALL_END_IMPL.
 * @ingroup csslFpCntFunction
 *
 *
 * @param result Fresh variable name to store the result of @p call.
 * @param token  Fresh variable name to store the protection token of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_BEGIN_IMPL(result, token, call)   \
do                                                                  \
{                                                                   \
    MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED_IMPL(result, token, call)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_END_IMPL
 * @brief Implementation of the end of a section started by
 * #MCUX_CSSL_FP_FUNCTION_CALL_BEGIN_IMPL.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_END_IMPL() \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
} while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN_IMPL
 * @brief Implementation of a flow protected void function call meant to be used
 *        from within an unprotected function, that must be terminated by
 *        #MCUX_CSSL_FP_FUNCTION_CALL_VOID_END_IMPL.
 * @ingroup csslFpCntFunction
 *
 *
 * @param token  Fresh variable name to store the protection token of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN_IMPL(token, call)   \
do                                                               \
{                                                                \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_PROTECTED_IMPL(token, call)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_END_IMPL
 * @brief Implementation of the end of a section started by
 * #MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN_IMPL.
 * @ingroup csslFpCntFunction
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_END_IMPL() \
MCUX_CSSL_ANALYSIS_START_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION() \
} while (false) \
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_BOOLEAN_TYPE_FOR_CONDITIONAL_EXPRESSION()

/**
 * @def MCUX_CSSL_FP_LOOP_ITERATION_IMPLn
 * @brief Event implementation of a loop iteration (with expectations).
 * @ingroup csslFpCntLoop
 *
 * @see MCUX_CSSL_FP_LOOP_ITERATION_IMPL
 *
 * @param id     Identifier for the loop that is flow protected.
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 *
 */
#define MCUX_CSSL_FP_LOOP_ITERATION_IMPLn(id, ...) \
  MCUX_CSSL_SC_ADD( \
    MCUX_CSSL_FP_LOOP_VALUE(id) \
    - MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__) \
  )

/**
 * @def MCUX_CSSL_FP_BRANCH_SCENARIO_IMPL
 * @brief Event implementation for the execution of a specified branch scenario.
 * @ingroup csslFpCntBranch
 *
 * @see MCUX_CSSL_FP_BRANCH_POSITIVE_IMPL
 * @see MCUX_CSSL_FP_BRANCH_NEGATIVE_IMPL
 *
 * @param id       Identifier for the branch for which the given @p scenario is
 *                 executed.
 * @param scenario The scenario for a branch is either positive or negative.
 * @param expect   One or more (comma separated) declarations of expected code
 *                 flow behavior related to this event.
 */
#define MCUX_CSSL_FP_BRANCH_SCENARIO_IMPL(id, scenario, ...) \
  MCUX_CSSL_SC_ADD( \
    (MCUX_CSSL_FP_BRANCH_VALUE(id) * (scenario)) \
    - MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__) \
  )

/**
 * @def MCUX_CSSL_FP_SWITCH_CASE_IMPLn
 * @brief Case that is being handled from a switch.
 * @ingroup csslFpCntSwitch
 *
 * @see MCUX_CSSL_FP_SWITCH_CASE_IMPL
 * @see MCUX_CSSL_FP_SWITCH_CASE_IMPL2
 *
 * @param id     Identifier of the flow protected switch.
 * @param case   Case value that is chosen in the switch.
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 */
#define MCUX_CSSL_FP_SWITCH_CASE_IMPLn(id, case, ...) \
  MCUX_CSSL_SC_ADD( \
    (MCUX_CSSL_FP_SWITCH_VALUE(id) * (case)) \
    - MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__) \
  )

/**
 * @def MCUX_CSSL_FP_ASSERT_IMPL
 * @brief Assert an expected state of the code flow.
 * @ingroup csslFpCntExpect
 *
 * This macro can be used to check whether the code flow up to this point
 * matches the expected state. Unlike the #MCUX_CSSL_FP_EXPECT macro, it will
 * not update the expectations, but merely perform a check on the recorded
 * events against the already recorded expectations plus the ones provided as
 * parameters.
 *
 * If the check fails, the code defined in MCUX_CSSL_FP_ASSERT_CALLBACK will be
 * executed.
 *
 * @see MCUX_CSSL_FP_EXPECTATIONS
 *
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 */
#define MCUX_CSSL_FP_ASSERT_IMPL(...) \
  if (MCUX_CSSL_SC_CHECK_PASSED != \
        MCUX_CSSL_SC_CHECK(MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__))) \
  { \
    MCUX_CSSL_FP_ASSERT_CALLBACK(); \
  } \
  else if (MCUX_CSSL_SC_CHECK_PASSED != \
        MCUX_CSSL_SC_CHECK(MCUX_CSSL_FP_EXPECTATIONS(__VA_ARGS__))) \
  { \
    MCUX_CSSL_FP_ASSERT_CALLBACK(); \
  } \
  else {/*empty*/}

#endif /* MCUX_CSSL_FLOW_PROTECTION_SECURE_COUNTER_LOCAL_H_ */
