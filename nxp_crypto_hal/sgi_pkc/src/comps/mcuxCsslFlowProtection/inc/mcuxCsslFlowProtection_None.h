/*--------------------------------------------------------------------------*/
/* Copyright 2020-2025 NXP                                                  */
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
 * @file  mcuxCsslFlowProtection_None.h
 * @brief Disabled implementation for the flow protection mechanism.
 */

#ifndef MCUX_CSSL_FLOW_PROTECTION_NONE_H_
#define MCUX_CSSL_FLOW_PROTECTION_NONE_H_

/* Include the CSSL C pre-processor support functionality. */
#include <mcuxCsslCPreProcessor.h>

/**
 * @addtogroup mcuxCsslIMPL MCUX CSSL -- Implementations
 *
 * @defgroup mcuxCsslFlowProtection_None Flow Protection: Disabled
 * @brief Disable the flow protection mechanism.
 * @ingroup mcuxCsslIMPL
 */


/**
 * @defgroup csslFpNoneCore Flow protection core functionality
 * @brief Flow protection handling core functionality.
 * @ingroup mcuxCsslFlowProtection_None
 *
 * This subset of Flow protection macros is common to all code flow patterns to be protected.
 */

/**
 * @def MCUX_CSSL_FP_COUNTER_STMT_IMPL
 * @brief A statement which is only evaluated if a secure counter is used.
 * @ingroup csslFpNoneCore
 *
 * @param statement The statement to be conditionally included.
 */
#define MCUX_CSSL_FP_COUNTER_STMT_IMPL(statement) \
  /* Intentionally empty. */


/**
 * @defgroup csslFpNoneExpect Expectation handling
 * @brief Expectation handling support functionality.
 * @ingroup mcuxCsslFlowProtection_None
 */

/**
 * @def MCUX_CSSL_FP_CONDITIONAL_IMPL
 * @brief Conditional expectation aggregation.
 * @ingroup csslFpNoneExpect
 *
 * @param condition Condition under which the given expectations apply
 * @param expect    One or more (comma separated) declarations of expected code
 *                  code flow behavior.
 * @return          Aggregated counter value for the given expectations, if
 *                  condition is satisfied. Otherwise 0.
 */
#define MCUX_CSSL_FP_CONDITIONAL_IMPL(condition, ...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_VOID_EXPECTATION_IMPL
 * @brief Implementation of expectation of nothing
 * @ingroup csslFpNoneExpect
 *
 * This expectation macro indicates to the flow protection mechanism that nothing
 * is expected to happen. This is mainly intended for internal use (to ensure at
 * least one expectation is passed).
 */
#define MCUX_CSSL_FP_VOID_EXPECTATION_IMPL() \
  (0u)

/**
 * @def MCUX_CSSL_FP_EXPECT_IMPL
 * @brief Declaration(s) of expected code flow behavior.
 * @ingroup csslFpNoneExpect
 *
 * This macro can be used to indicate expectations in the function body at
 * another location than the function entry or exit.
 *
 * @see MCUX_CSSL_FP_EXPECTATIONS
 *
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 */
#define MCUX_CSSL_FP_EXPECT_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_ASSERT_IMPL
 * @brief Assert an expected state of the code flow.
 * @ingroup csslFpNoneExpect
 *
 * @param expect One or more (comma separated) declarations of expected code
 *               flow behavior.
 */
#define MCUX_CSSL_FP_ASSERT_IMPL(...) \
  /* Intentionally empty. */

/**
 * @defgroup csslFpNoneFunction Function calling flow protection
 * @brief Support for flow protected functions.
 * @ingroup mcuxCsslFlowProtection_None
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @event{MCUX_CSSL_FP_FUNCTION_CALL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 */

/**
 * @def MCUX_CSSL_FP_PROTECTED_TYPE_IMPL
 * @brief Based on a given base type, builds a return type with flow
 *        protection.
 * @ingroup csslFpNoneFunction
 *
 * @see MCUX_CSSL_FP_FUNCTION_DEF_IMPL
 *
 * @param resultType The type to be converted into a protected type.
 */
#define MCUX_CSSL_FP_PROTECTED_TYPE_IMPL(resultType) \
  resultType

/**
 * @def MCUX_CSSL_FP_FUNCTION_DECL_IMPL
 * @brief Declaration implementation of a flow protected function.
 * @ingroup csslFpNoneFunction
 *
 * @event{MCUX_CSSL_FP_FUNCTION_CALL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 *
 * @param id Identifier for the function that is flow protected.
 * @param ptrType Optional, pointer type matching this function.
 */
#define MCUX_CSSL_FP_FUNCTION_DECL_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_FUNCTION_DEF_IMPL
 * @brief Definition implementation of a flow protected function.
 * @ingroup csslFpNoneFunction
 *
 * @param id Identifier for the function that is flow protected.
 * @param ptrType Optional, pointer type matching this function.
 */
#define MCUX_CSSL_FP_FUNCTION_DEF_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_FUNCTION_POINTER_IMPL
 * @brief Definition implementation of a flow protected function pointer.
 * @ingroup csslFpNoneFunction
 *
 * @param type Identifier for the function pointer type that is flow protected.
 * @param definition Actual type definition of the function pointer type.
 */
#define MCUX_CSSL_FP_FUNCTION_POINTER_IMPL(type, definition) \
  definition

/**
 * @def MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL
 * @brief Flow protection handler implementation for the function entry point.
 * @ingroup csslFpNoneFunction
 *
 * @param id     Identifier of the function that has just been entered.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 */
#define MCUX_CSSL_FP_FUNCTION_ENTRY_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_RESULT_IMPL2
 * @brief Extract the result value from a protected @p return value.
 * @ingroup csslFpNoneFunction
 *
 * @param type   Type of the result.
 * @param return The protected return value which contains the result.
 */
#define MCUX_CSSL_FP_RESULT_IMPL2(type, return) \
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES() \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Proper alignment is ensured during type cast") \
  ((type)(return)) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER() \
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

/**
 * @def MCUX_CSSL_FP_RESULT_IMPL1
 * @brief Extract the result value from a protected @p return value.
 * @ingroup csslFpNoneFunction
 *
 * @param return The protected return value which contains the result.
 */
#define MCUX_CSSL_FP_RESULT_IMPL1(return) \
  (return)

/**
 * @def MCUX_CSSL_FP_RESULT_IMPL
 * @brief Extract the result value from a protected @p return value.
 * @ingroup csslFpNoneFunction
 *
 * @param type   Optional, type of the result.
 * @param return The protected return value which contains the result.
 */
#define MCUX_CSSL_FP_RESULT_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUX_CSSL_FP_RESULT_IMPL, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_PROTECTION_TOKEN_IMPL
 * @brief Extract the protection token value from a protected @p return value.
 * @ingroup csslFpNoneFunction
 *
 * @param return The protected return value which contains the protection token.
 */
#define MCUX_CSSL_FP_PROTECTION_TOKEN_IMPL(return) \
  (0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpNoneFunction
 *
 * Return the @p result via the function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 *
 * @param id     Identifier of the function from which we will exit.
 * @param result Result that should be encoded in the return value.
 * @return       A value in which the @p result is encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn(id, result, ...) \
  return (result)

  /**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPL1
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpNoneFunction
 *
 * Return a null value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 *
 * @param id Identifier of the function from which we will exit.
 * @return   A null value.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPL1(id) \
  MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn(id, 0u, 0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPL2
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpNoneFunction
 *
 * Return the @p result via the function return value.
 *
 * @see MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 *
 * @param id     Identifier of the function from which we will exit.
 * @param result Result that should be encoded in the return value.
 * @return       A value in which the @p result is encoded.

 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPL2(id, result) \
  MCUX_CSSL_FP_FUNCTION_EXIT_IMPLn(id, result, 0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_IMPL
 * @brief Flow protection handler implementation for the function exit point.
 * @ingroup csslFpNoneFunction
 *
 * Return the @p result via the function return value.
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
 * @return       A value in which the @p result is encoded.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUX_CSSL_FP_FUNCTION_EXIT_IMPL, __VA_ARGS__)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL
 * @brief Flow protection handler implementation for the function exit point
 *        which includes an actual check of the code flow.
 * @ingroup csslFpNoneFunction
 *
 * @param id     Identifier of the function from which we will exit.
 * @param pass   Result that should be encoded in the return value if the flow
 *               protection check passed.
 * @param fail   Result that should be encoded in the return value if the flow
 *               protection check failed.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       @p pass.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_WITH_CHECK_IMPL(id, pass, fail,...) \
  return (pass)

/**
 * @def MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL
 * @brief Flow protection handler for the exit point of functions with the
 *        return type @c void.
 * @ingroup csslFpNoneFunction
 *
 * @param id     Identifier of the function from which we will exit.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior.
 * @return       A protected return value of type void.
 */
#define MCUX_CSSL_FP_FUNCTION_EXIT_VOID_IMPL(...) \
  return

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_IMPL3
 * @brief Event implementation of a flow protected function call.
 * @ingroup csslFpNoneFunction
 *
 * @param type   Type of the @p result variable.
 * @param result Fresh variable name to store the result of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_IMPL3(type, result, call) \
  type const result = MCUX_CSSL_FP_RESULT(type,call)


/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_IMPL2
 * @brief Event implementation of a flow protected function call.
 * @ingroup csslFpNoneFunction
 *
 * @param result Fresh variable name to store the result of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_IMPL2(result, call) \
  MCUX_CSSL_FP_FUNCTION_CALL_IMPL3(uint32_t, result, call)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_IMPL
 * @brief Event implementation of a flow protected function call.
 * @ingroup csslFpNoneFunction
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
 * @ingroup csslFpNoneFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 *
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_IMPL(call) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("False positive, due to macro expansion, any usage of NULL is considered as 0 by Coverity") \
  (call) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED_IMPL
 * @brief Implementation of a flow protected function call.
 * @ingroup csslFpNoneFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 *
 * @param result Fresh variable name to store the result of @p call.
 * @param token  Intenionally unused, since no flow protection is provided.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED_IMPL(result, token, call) \
  const uint32_t result = (call); \
  const uint32_t token = 0u

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_PROTECTED_IMPL
 * @brief Implementation of a flow protected void function call.
 * @ingroup csslFpNoneFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @expectation{MCUX_CSSL_FP_FUNCTION_CALLED_IMPL}
 *
 * @param token  Intentionally unused, since no flow protection is provided.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_PROTECTED_IMPL(token, call) \
  (call); \
  const uint32_t token = 0u

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_BEGIN_IMPL
 * @brief Implementation of a flow protected function call meant to be used
 *        from within an unprotected function, that must be terminated by
 *        #MCUX_CSSL_FP_FUNCTION_CALL_END_IMPL.
 * @ingroup csslFpNoneFunction
 *
 * @param result Fresh variable name to store the result of @p call.
 * @param token  Fresh variable name to store the protection token of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_BEGIN_IMPL(result, token, call)   \
    MCUX_CSSL_FP_FUNCTION_CALL_PROTECTED_IMPL(result, token, call)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_END_IMPL
 * @brief Implementation of the end of a section started by
 * #MCUX_CSSL_FP_FUNCTION_CALL_BEGIN_IMPL.
 * @ingroup csslFpNoneFunction
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_END_IMPL() \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN_IMPL
 * @brief Implementation of a flow protected void function call meant to be used
 *        from within an unprotected function, that must be terminated by
 *        #MCUX_CSSL_FP_FUNCTION_CALL_VOID_END_IMPL.
 * @ingroup csslFpNoneFunction
 *
 * @param token  Fresh variable name to store the protection token of @p call.
 * @param call   The (protected) function call that must be performed.
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN_IMPL(token, call)   \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_PROTECTED_IMPL(token, call)

/**
 * @def MCUX_CSSL_FP_FUNCTION_CALL_VOID_END_IMPL
 * @brief Implementation of the end of a section started by
 * #MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN_IMPL.
 * @ingroup csslFpNoneFunction
 */
#define MCUX_CSSL_FP_FUNCTION_CALL_VOID_END_IMPL() \
  /* Intentionally empty. */


/**
 * @def MCUX_CSSL_FP_FUNCTION_CALLED_IMPL
 * @brief Expectation implementation of a called function.
 * @ingroup csslFpNoneFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @event{MCUX_CSSL_FP_FUNCTION_CALL_IMPL}
 *
 * @see MCUX_CSSL_FP_FUNCTION_VALUE
 *
 * @param id Identifier of the function that is expected to be called.
 * @return   A null value.
 */
#define MCUX_CSSL_FP_FUNCTION_CALLED_IMPL(id) \
  (0u)

/**
 * @def MCUX_CSSL_FP_FUNCTION_ENTERED_IMPL
 * @brief Expectation implementation of an entered (but not exited) function.
 * @ingroup csslFpNoneFunction
 *
 * @declaration{MCUX_CSSL_FP_FUNCTION_DECL_IMPL}
 * @event{MCUX_CSSL_FP_FUNCTION_CALL_IMPL}
 *
 * @see MCUX_CSSL_FP_FUNCTION_VALUE
 *
 * @param id Identifier of the function that is expected to be entered.
 * @return   A null value.
 */
#define MCUX_CSSL_FP_FUNCTION_ENTERED_IMPL(id) \
  (0u)

/**
 * @defgroup csslFpNoneLoop Looping flow protection
 * @brief Support for flow protected loops.
 * @ingroup mcuxCsslFlowProtection_None
 *
 * @declaration{MCUX_CSSL_FP_LOOP_DECL_IMPL}
 * @event{MCUX_CSSL_FP_LOOP_ITERATION_IMPL}
 * @expectation{MCUX_CSSL_FP_LOOP_ITERATIONS_IMPL}
 */

/**
 * @def MCUX_CSSL_FP_LOOP_DECL_IMPL
 * @brief Declaration implementation of a flow protected loop.
 * @ingroup csslFpNoneLoop
 *
 * @param id Identifier for the loop that is flow protected.
 */
#define MCUX_CSSL_FP_LOOP_DECL_IMPL(id) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_LOOP_ITERATION_IMPL
 * @brief Event implementation of a loop iteration.
 * @ingroup csslFpNoneLoop
 *
 * @param id     Identifier for the loop that is flow protected.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 */
#define MCUX_CSSL_FP_LOOP_ITERATION_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_LOOP_ITERATIONS_IMPL
 * @brief Expectation implementation of a number of loop iterations.
 * @ingroup csslFpNoneLoop
 *
 * @param id    Identifier of the flow protected loop.
 * @param count Number of expected iterations.
 */
#define MCUX_CSSL_FP_LOOP_ITERATIONS_IMPL(id, count) \
  /* Intentionally empty. */



/**
 * @defgroup csslFpNoneBranch Branching flow protection
 * @brief Support for flow protected branches.
 * @ingroup mcuxCsslFlowProtection_None
 *
 * @declaration{MCUX_CSSL_FP_BRANCH_DECL_IMPL}
 * @event{MCUX_CSSL_FP_BRANCH_POSITIVE_IMPL,MCUX_CSSL_FP_BRANCH_NEGATIVE_IMPL}
 * @expectation{MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE_IMPL,MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE_IMPL}
 */

/**
 * @def MCUX_CSSL_FP_BRANCH_DECL_IMPL
 * @brief Declaration implementation of a flow protected branch.
 * @ingroup csslFpNoneBranch
 *
 * @param id Identifier for the branch that is flow protected.
 */
#define MCUX_CSSL_FP_BRANCH_DECL_IMPL(id) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_BRANCH_POSITIVE_IMPL
 * @brief Event implementation for the execution of a positive branch scenario.
 * @ingroup csslFpNoneBranch
 *
 * Implemented as an overloaded macro to simplify the use of the API.
 *
 * @see MCUX_CSSL_FP_BRANCH_POSITIVE_IMPL1
 * @see MCUX_CSSL_FP_BRANCH_POSITIVE_IMPLn
 *
 * @param id     Identifier for the branch for which the positive scenario is
 *               executed.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 */
#define MCUX_CSSL_FP_BRANCH_POSITIVE_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_BRANCH_NEGATIVE_IMPL
 * @brief Event implementation for the execution of a negative branch scenario.
 * @ingroup csslFpNoneBranch
 *
 * Implemented as an overloaded macro to simplify the use of the API.
 *
 * @see MCUX_CSSL_FP_BRANCH_NEGATIVE_IMPL1
 * @see MCUX_CSSL_FP_BRANCH_NEGATIVE_IMPLn
 *
 * @param id     Identifier for the branch for which the negative scenario is
 *               executed.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 */
#define MCUX_CSSL_FP_BRANCH_NEGATIVE_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE_IMPL
 * @brief Expectation implementation of an executed positive branch.
 * @ingroup csslFpNoneBranch
 *
 * @param id        Identifier of the flow protected branch.
 * @param condition Optional, condition under which this branch is taken.
 */
#define MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE_IMPL
 * @brief Expectation implementation of an executed negative branch.
 * @ingroup csslFpNoneBranch
 *
 * @param id        Identifier of the flow protected branch.
 * @param condition Optional, condition under which this branch is taken.
 */
#define MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE_IMPL(...) \
  /* Intentionally empty. */



/**
 * @defgroup csslFpNoneSwitch Switching flow protection
 * @brief Support for flow protected switches.
 * @ingroup mcuxCsslFlowProtection_None
 *
 * @declaration{MCUX_CSSL_FP_SWITCH_DECL_IMPL}
 * @event{MCUX_CSSL_FP_SWITCH_CASE_IMPL,MCUX_CSSL_FP_SWITCH_DEFAULT_IMPL}
 * @expectation{MCUX_CSSL_FP_SWITCH_TAKEN_IMPL,MCUX_CSSL_FP_SWITCH_TAKEN_DEFAULT_IMPL}
 */

/**
 * @def MCUX_CSSL_FP_SWITCH_DECL_IMPL
 * @brief Declaration implementation of a flow protected switch.
 * @ingroup csslFpNoneSwitch
 *
 * @param id Identifier for the switch that is flow protected.
 */
#define MCUX_CSSL_FP_SWITCH_DECL_IMPL(id) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_SWITCH_CASE_IMPL
 * @brief Case that is being handled from a switch.
 * @ingroup csslFpNoneSwitch
 *
 * @param id     Identifier of the flow protected switch.
 * @param case   Case value that is chosen in the switch.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 */
#define MCUX_CSSL_FP_SWITCH_CASE_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_SWITCH_DEFAULT_IMPL
 * @brief Case that is being handled from a switch.
 * @ingroup csslFpNoneSwitch
 *
 * @param id     Identifier of the flow protected switch.
 * @param expect Zero or more (comma separated) declarations of expected code
 *               flow behavior related to this event.
 */
#define MCUX_CSSL_FP_SWITCH_DEFAULT_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_SWITCH_TAKEN_IMPL
 * @brief Expected that a specific case is handled from a switch.
 * @ingroup csslFpNoneSwitch
 *
 * @param id        Identifier of the flow protected switch.
 * @param case      Value of the case that is expected to be chosen in the
 *                  switch.
 * @param condition Optional, condition under which the @p case is taken.
 */
#define MCUX_CSSL_FP_SWITCH_TAKEN_IMPL(...) \
  /* Intentionally empty. */

/**
 * @def MCUX_CSSL_FP_SWITCH_TAKEN_DEFAULT_IMPL
 * @brief Expected that default case is handled from a switch.
 * @ingroup csslFpNoneSwitch
 *
 * @param id        Identifier of the flow protected switch.
 * @param condition Optional, condition under which the default case is taken.
 */
#define MCUX_CSSL_FP_SWITCH_TAKEN_DEFAULT_IMPL(...) \
  /* Intentionally empty. */


#endif /* MCUX_CSSL_FLOW_PROTECTION_NONE_H_ */
