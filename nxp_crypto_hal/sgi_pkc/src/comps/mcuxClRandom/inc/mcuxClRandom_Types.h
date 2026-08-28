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
 * @file  mcuxClRandom_Types.h
 * @brief Type definitions of mcuxClRandom component
 */


#ifndef MCUXCLRANDOM_TYPES_H_
#define MCUXCLRANDOM_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClCore_Platform.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Types of mcuxClRandom                                   */
/**********************************************************/
/**
 * @defgroup mcuxClRandom_Types mcuxClRandom_Types
 * @brief Defines all types of @ref mcuxClRandom
 * @ingroup mcuxClRandom
 * @{
 */

/**
 * @brief Type for status codes of mcuxClRandom component functions.
 *
 * This type provides information about the status of the Random operation
 * that has been performed.
 */
typedef uint32_t mcuxClRandom_Status_t;

/**
 * @brief Random context structure
 *
 * This structure is used to store the information about the current random
 * data generator and the relevant internal state.
 */
struct mcuxClRandom_Context;

/**
 * @brief Random context type
 *
 * This type is used to store the information about the current random data
 * generator and the relevant internal state.
 */
typedef struct mcuxClRandom_Context mcuxClRandom_ContextDescriptor_t;

/**
 * @brief Random context type
 *
 * This type is used to refer to a Random context.
 */
typedef mcuxClRandom_ContextDescriptor_t * mcuxClRandom_Context_t;

/**
 * @brief Random data generation mode/algorithm descriptor structure
 *
 * This structure captures all the information that the Random interfaces need
 * to know about a particular Random data generation mode/algorithm.
 */
struct mcuxClRandom_ModeDescriptor;

/**
 * @brief Random data generation mode/algorithm descriptor type
 *
 * This type captures all the information that the Random interfaces need to
 * know about a particular Random data generation mode/algorithm.
 */
typedef struct mcuxClRandom_ModeDescriptor mcuxClRandom_ModeDescriptor_t;

/**
 * @brief Random data generation mode/algorithm type
 *
 * This type is used to refer to a Random data generation mode/algorithm.
 */
typedef const mcuxClRandom_ModeDescriptor_t * mcuxClRandom_Mode_t;

/**
 * @brief Interface definition for custom PRNG functions to be used by PRNG patch mode
 */
typedef mcuxClRandom_Status_t (* mcuxClRandom_CustomNcGenerateAlgorithm_t)(
    void *pCustomPrngState,
    mcuxCl_Buffer_t pOut,
    uint32_t outLength
);

/**
 * @brief Random config structure
 *
 * This structure is used to store context and mode pointers.
 */
struct mcuxClRandom_Config {
    mcuxClRandom_Mode_t    mode;      ///< Random data generation mode/algorithm
    mcuxClRandom_Context_t ctx;       ///< Context for the Rng
    mcuxClRandom_CustomNcGenerateAlgorithm_t prngPatchFunction; ///< Function pointer to a custom PRNG function
    void *pCustomPrngState;   ///< User-maintained state for a custom PRNG function
};

/**
 * @brief Random config type
 *
 * This type is used to store context and mode.
 */
typedef struct mcuxClRandom_Config mcuxClRandom_Config_t;

/**
 * @}
 */ /* mcuxClRandom_Types */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOM_TYPES_H_ */
