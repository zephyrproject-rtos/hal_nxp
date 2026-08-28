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

#ifndef MCUXCLHASHMODES_MODESMEMORYMACROS_IMPL_H
#define MCUXCLHASHMODES_MODESMEMORYMACROS_IMPL_H

#include <mcuxCsslCPreProcessor.h>
#include <mcuxCsslFlowProtection.h>

/**
 * @brief This file contains the low level macro implementations for the memory computation and struct generation.
 *        No changes are needed here, if you just want to add a new mode or adapt the memory demand of an existing one.
 */


/*
 * Helper macros for the generation of a mode descriptor.
 * The descriptors are defined in the mcuxClHashModes_ModesConstants.h header file.
 */

 /** @brief Get the variable name of the descriptor struct */
 #define MCUXCLHASHMODES_GET_NAME(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _NAME)

/** @brief Get the oneshot skeleton of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_ONESHOT(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _ONESHOT)

/** @brief Get the oneshot skeleton FP token of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_ONESHOT_TOKEN(DESCRIPTOR) \
 MCUX_CSSL_FP_FUNCTION_CALLED(MCUXCLHASHMODES_GET_ONESHOT(DESCRIPTOR))

/** @brief Get the process skeleton of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_PROCESS(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _PROCESS)

/** @brief Get the process skeleton FP token of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_PROCESS_TOKEN(DESCRIPTOR) \
 MCUX_CSSL_FP_FUNCTION_CALLED(MCUXCLHASHMODES_GET_PROCESS(DESCRIPTOR))

/** @brief Get the finish skeleton of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_FINISH(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _FINISH)

/** @brief Get the finish skeleton FP token of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_FINISH_TOKEN(DESCRIPTOR) \
 MCUX_CSSL_FP_FUNCTION_CALLED(MCUXCLHASHMODES_GET_FINISH(DESCRIPTOR))

/** @brief Get the length mask of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_LENGTHMASK(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _LENGTHMASK)

/** @brief Get the block size of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _BLOCKSIZE)

/** @brief Get the hash size (output size) of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_HASHSIZE(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _HASHSIZE)

/** @brief Get the state size of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _STATESIZE)

/** @brief Get the counter size of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_COUNTERSIZE(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _COUNTERSIZE)

/** @brief Get the OID of a @p DESCRIPTOR */
#define MCUXCLHASHMODES_GET_OID(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _OID)

/** @brief Returns 1 if the mode of @p DESCRIPTOR is active and 0 otherwise */
#define MCUXCLHASHMODES_GET_ACTIVE(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _ACTIVE)

/** @brief Get memory computation macro of @p DESCRIPTOR for the oneshot skeleton */
#define MCUXCLHASHMODES_GET_MEMORY_ONESHOT(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _MEMORY_ONESHOT)

/** @brief Get memory computation macro of @p DESCRIPTOR for the process skeleton */
#define MCUXCLHASHMODES_GET_MEMORY_PROCESS(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _MEMORY_PROCESS)

/** @brief Get memory computation macro of @p DESCRIPTOR for the finish skeleton */
#define MCUXCLHASHMODES_GET_MEMORY_FINISH(DESCRIPTOR) \
 MCUX_CSSL_CPP_CAT(DESCRIPTOR, _MEMORY_FINISH)

/** @brief Get memory computation macro of @p DESCRIPTOR for the context size. */
#define MCUXCLHASHMODES_GET_MEMORY_CONTEXT(DESCRIPTOR) \
  MCUX_CSSL_CPP_CAT(DESCRIPTOR, _MEMORY_CONTEXT)

/*
* Adding another abstraction layer, which we need for MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR.
* The members of the mode descriptor struct (mcuxClHash_AlgorithmDescriptor_t) depend on some feature flags.
* Therefore, we define macros which return a certain field or nothing, depending on the active feature flags.
*/



#define MCUXCLHASHMODES_DEFINE_ONESHOTSKELETON(DESCRIPTOR) \
 .oneShotSkeleton = MCUXCLHASHMODES_GET_ONESHOT(DESCRIPTOR),

#define MCUXCLHASHMODES_DEFINE_ONESHOTSKELETON_TOKEN(DESCRIPTOR) \
 .protection_token_oneShotSkeleton = MCUXCLHASHMODES_GET_ONESHOT_TOKEN(DESCRIPTOR),




#define MCUXCLHASHMODES_DEFINE_PROCESSSKELETON(DESCRIPTOR) \
 .processSkeleton                  = MCUXCLHASHMODES_GET_PROCESS(DESCRIPTOR),

#define MCUXCLHASHMODES_DEFINE_PROCESSSKELETON_TOKEN(DESCRIPTOR) \
 .protection_token_processSkeleton = MCUXCLHASHMODES_GET_PROCESS_TOKEN(DESCRIPTOR),

#define MCUXCLHASHMODES_DEFINE_FINISHSKELETON(DESCRIPTOR) \
 .finishSkeleton                   = MCUXCLHASHMODES_GET_FINISH(DESCRIPTOR),

#define MCUXCLHASHMODES_DEFINE_FINISHSKELETON_TOKEN(DESCRIPTOR) \
 .protection_token_finishSkeleton  = MCUXCLHASHMODES_GET_FINISH_TOKEN(DESCRIPTOR),

#define MCUXCLHASHMODES_DEFINE_PROCESSEDLENGTHMASK(DESCRIPTOR) \
 .processedLengthCheckMask         = MCUXCLHASHMODES_GET_LENGTHMASK(DESCRIPTOR),



#ifdef MCUXCL_FEATURE_HASH_OIDS

#define MCUXCLHASHMODES_DEFINE_OID(DESCRIPTOR) \
 .pOid = MCUXCLHASHMODES_GET_OID(DESCRIPTOR),

#define MCUXCLHASHMODES_DEFINE_OIDSIZE(DESCRIPTOR) \
 .oidSize = sizeof(MCUXCLHASHMODES_GET_OID(DESCRIPTOR)),

#else

#define MCUXCLHASHMODES_DEFINE_OID(DESCRIPTOR)
#define MCUXCLHASHMODES_DEFINE_OIDSIZE(DESCRIPTOR)

#endif /* MCUXCL_FEATURE_HASH_OIDS */

/** @brief Function identifier (protection token) when skeleton is NULL */
#define MCUX_CSSL_FP_FUNCID_0U                               (0U)

/** @brief Macro for null pointers as skeleton functions. To be used in mcuxClHashModes_ModesConstants.h */
#define MCUXCLHASHMODES_SKELETON_NULL_POINTER                                0U


/** @brief Implementation of #MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR.
 *         Returns the struct definition of a hash mode for @p DESCRIPTOR with @p ALGORITHM_DETAILS.
 *         The members for the descriptor are defined in mcuxClHashModes_ModesConstants.h.
 *         The MCUXCLHASHMODES_DEFINE_* macros ensure that we only have members with corresponding
 *         feature flags being active.
 *
 *  @param  DESCRIPTOR            Name of the descriptor. Defined in mcuxClHashModes_ModesConstants.h.
 *  @param  ALGORITHM_DETAILS     Pointer to the internal algorithm descriptor (mcuxClHashModes_Internal_AlgorithmDescriptor_t).
 *                                Can be NULL. The internal algorithm descriptor is initialized directly without a macro.
 */
#define MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR_IMPL(DESCRIPTOR, ALGORITHM_DETAILS) \
 MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER() \
 const mcuxClHash_AlgorithmDescriptor_t MCUXCLHASHMODES_GET_NAME(DESCRIPTOR) = { \
 MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER() \
     MCUXCLHASHMODES_DEFINE_ONESHOTSKELETON(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_ONESHOTSKELETON_TOKEN(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_PROCESSSKELETON(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_PROCESSSKELETON_TOKEN(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_FINISHSKELETON(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_FINISHSKELETON_TOKEN(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_PROCESSEDLENGTHMASK(DESCRIPTOR) \
     .blockSize                        = MCUXCLHASHMODES_GET_BLOCKSIZE(DESCRIPTOR), \
     .hashSize                         = MCUXCLHASHMODES_GET_HASHSIZE(DESCRIPTOR), \
     .stateSize                        = MCUXCLHASHMODES_GET_STATESIZE(DESCRIPTOR), \
     .counterSize                      = MCUXCLHASHMODES_GET_COUNTERSIZE(DESCRIPTOR), \
     MCUXCLHASHMODES_DEFINE_OID(DESCRIPTOR) \
     MCUXCLHASHMODES_DEFINE_OIDSIZE(DESCRIPTOR) \
     MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the algorithm.") \
     .pAlgorithmDetails = (void *) ALGORITHM_DETAILS \
     MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER() \
 }



/*
 * Memory computation macros
 */

/**
 * @brief Executes @p IF_BRANCH when @p CONDITION is 1 and
 *        @p ELSE_BRANCH when @p CONDITION is 0
 */
#define MCUXCLHASHMODES_IF(CONDITION, IF_BRANCH, ELSE_BRANCH) \
  MCUX_CSSL_CPP_CAT(MCUXCLHASHMODES_IF, CONDITION)(IF_BRANCH, ELSE_BRANCH)

/** @brief Always executes @p IF_BRANCH */
#define MCUXCLHASHMODES_IF1(IF_BRANCH, ELSE_BRANCH) IF_BRANCH

/** @brief Always executes @p ELSE_BRANCH */
#define MCUXCLHASHMODES_IF0(IF_BRANCH, ELSE_BRANCH) ELSE_BRANCH

/** @brief Returns the memory consumption of the oneshot skeleton for @p DESCRIPTOR (or 4 if the mode is not active) */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL1(DESCRIPTOR) \
  MCUXCLHASHMODES_IF( \
    MCUXCLHASHMODES_GET_ACTIVE(DESCRIPTOR), \
    MCUXCLHASHMODES_GET_MEMORY_ONESHOT(DESCRIPTOR)(DESCRIPTOR), \
    4u \
  )

/** @brief Returns maximum oneshot skeleton memory consumption of @p DESCRIPTOR1 and @p DESCRIPTOR2. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL2(DESCRIPTOR1, DESCRIPTOR2) \
  MCUXCLCORE_MAX( \
    MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL1(DESCRIPTOR1), \
    MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL1(DESCRIPTOR2) \
  )

/** @brief Calls #MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL1 or #MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL2
*          depending on the number of parameters. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL, __VA_ARGS__)


/** @brief Returns the memory consumption of the process skeleton for @p DESCRIPTOR (or 4 if the mode is not active) */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL1(DESCRIPTOR) \
  MCUXCLHASHMODES_IF( \
    MCUXCLHASHMODES_GET_ACTIVE(DESCRIPTOR), \
    MCUXCLHASHMODES_GET_MEMORY_PROCESS(DESCRIPTOR)(DESCRIPTOR), \
    4u \
  )

/** @brief Returns maximum process skeleton memory consumption of @p DESCRIPTOR1 and @p DESCRIPTOR2. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL2(DESCRIPTOR1, DESCRIPTOR2) \
  MCUXCLCORE_MAX( \
    MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL1(DESCRIPTOR1), \
    MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL1(DESCRIPTOR2) \
  )

/** @brief Calls #MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL1 or #MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL2
 *         depending on the number of parameters. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL, __VA_ARGS__)


/** @brief Returns the memory consumption of the finish skeleton for @p DESCRIPTOR (or 4 if the mode is not active) */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL1(DESCRIPTOR) \
  MCUXCLHASHMODES_IF(MCUXCLHASHMODES_GET_ACTIVE(DESCRIPTOR), MCUXCLHASHMODES_GET_MEMORY_FINISH(DESCRIPTOR)(DESCRIPTOR), 4u)

/** @brief Returns maximum finish skeleton memory consumption of @p DESCRIPTOR1 and @p DESCRIPTOR2. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL2(DESCRIPTOR1, DESCRIPTOR2) \
  MCUXCLCORE_MAX( \
    MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL1(DESCRIPTOR1), \
    MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL1(DESCRIPTOR2) \
  )

/** @brief Calls #MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL1 or #MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL2
 *         depending on the number of parameters. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL, __VA_ARGS__)

/** @brief Returns the context size consumption for @p DESCRIPTOR (or 4 if the mode is not active) */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL1(DESCRIPTOR) \
  MCUXCLHASHMODES_IF( \
    MCUXCLHASHMODES_GET_ACTIVE(DESCRIPTOR), \
    MCUXCLHASHMODES_GET_MEMORY_CONTEXT(DESCRIPTOR)(DESCRIPTOR), \
    4u \
  )

/** @brief Returns the maximum context size of @p DESCRIPTOR1 and @p DESCRIPTOR2. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL2(DESCRIPTOR1, DESCRIPTOR2) \
  MCUXCLCORE_MAX( \
    MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL1(DESCRIPTOR1), \
    MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL1(DESCRIPTOR2) \
  )

/** @brief Calls #MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL1 or #MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL2
 *         depending on the number of parameters. */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL(...) \
  MCUX_CSSL_CPP_OVERLOADED2(MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL, __VA_ARGS__)

#endif /* MCUXCLHASHMODES_MODESMEMORYMACROS_IMPL_H */
