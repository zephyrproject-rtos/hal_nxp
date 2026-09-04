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

#ifndef MCUXCLHASHMODES_MODESMEMORYMACROS_H
#define MCUXCLHASHMODES_MODESMEMORYMACROS_H

#include <internal/mcuxClHashModes_ModesMemoryMacros_Impl.h>

/** @brief Returns a struct initialization (mcuxClHash_AlgorithmDescriptor_t) of a hash mode.
 *         The members for the descriptor are defined in mcuxClHashModes_ModesConstants.h.
 *
 *  @param  DESCRIPTOR            Name of the descriptor. Defined in mcuxClHashModes_ModesConstants.h.
 *  @param  ALGORITHM_DETAILS     Pointer to the internal algorithm descriptor (mcuxClHashModes_Internal_AlgorithmDescriptor_t).
 *                                Can be NULL. The internal algorithm descriptor is initialized directly without a macro.
 */
#define MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR(DESCRIPTOR, ALGORITHM_DETAILS) \
  MCUXCLHASHMODES_MAKE_ALGORITHM_DESCRIPTOR_IMPL(DESCRIPTOR, ALGORITHM_DETAILS)

/** @brief Returns the memory consumption of the oneshot skeleton of a given descriptor. Given two descriptors as
 *         parameters, it returns the maximum of these two.  */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(...) \
  MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT_IMPL(__VA_ARGS__)


/** @brief Returns the memory consumption of the process skeleton of a given descriptor. Given two descriptors as
 *         parameters, it returns the maximum of these two.  */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(...) \
  MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS_IMPL(__VA_ARGS__)

/** @brief Returns the memory consumption of the finish skeleton of a given descriptor. Given two descriptors as
 *         parameters, it returns the maximum of these two.  */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(...) \
  MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH_IMPL(__VA_ARGS__)

/** @brief Returns the maximum memory consumption for @p DESCRIPTOR:
 *         MAX(oneshot, process, finish) or 4 if the mode is not active.
 */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_MAX(DESCRIPTOR) \
  MCUXCLCORE_MAX( \
    MCUXCLHASHMODES_COMPUTE_MEMORY_ONESHOT(DESCRIPTOR), \
    MCUXCLCORE_MAX(MCUXCLHASHMODES_COMPUTE_MEMORY_PROCESS(DESCRIPTOR), MCUXCLHASHMODES_COMPUTE_MEMORY_FINISH(DESCRIPTOR)) \
  )

/** @brief Returns the context memory size consumption of for a given descriptor. Given two descriptors as
 *         parameters, it returns the maximum context size of these two.
 */
#define MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT(...) \
  MCUXCLHASHMODES_COMPUTE_MEMORY_CONTEXT_IMPL(__VA_ARGS__)

#endif /* MCUXCLHASHMODES_MODESMEMORYMACROS_H */
