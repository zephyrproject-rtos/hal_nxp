/*--------------------------------------------------------------------------*/
/* Copyright 2022-2025 NXP                                                  */
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
 * @file  mcuxClRandom_Internal_Types.h
 * @brief Internal type definitions of mcuxClRandom component
 */

#ifndef MCUXCLRANDOM_INTERNAL_TYPES_H_
#define MCUXCLRANDOM_INTERNAL_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClSession.h>
#include <mcuxClRandom_Types.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Function prototype for init function pointer in OperationMode structure.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandom_initFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRandom_initFunction_t)(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context
));

/**
 * @brief Function prototype for reseed function pointer in OperationMode structure.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandom_reseedFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClRandom_reseedFunction_t)(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context
));

/**
 * @brief Function prototype for generate function pointer in OperationMode structure.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandom_generateFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClRandom_generateFunction_t)(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context,
        mcuxCl_Buffer_t pOut,
        uint32_t outLength,
        const uint32_t *pXorMask
));

/**
 * @brief Function prototype for selftest function pointer in OperationMode structure.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandom_selftestFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClRandom_selftestFunction_t)(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode
));

/**
 * @brief Random operation mode descriptor structure
 *
 * This structure is used to store all information needed in the top level Random DRBG functions,
 * determines which mode the DRBG shall be operated in (normal, test or patch mode) and specifies
 * pointers to functions implementing the DRBG in the chosen operation mode.
 */
typedef struct
{
    /* Function pointers for DRBG functions */
    mcuxClRandom_initFunction_t initFunction;          ///< Function to be called for DRBG instantiation depending on the chosen operationMode
    mcuxClRandom_reseedFunction_t reseedFunction;      ///< Function to be called for DRBG reseeding depending on the chosen operationMode
    mcuxClRandom_generateFunction_t generateFunction;  ///< Function to be called for DRBG random number generation depending on the chosen operationMode
    mcuxClRandom_selftestFunction_t selftestFunction;  ///< Function to be called for DRBG self testing depending on the chosen operationMode

    /* Protection tokens for DRBG functions */
    uint32_t protectionTokenInitFunction;             ///< Protection token of DRBG init function
    uint32_t protectionTokenReseedFunction;           ///< Protection token of DRBG reseed function
    uint32_t protectionTokenGenerateFunction;         ///< Protection token of DRBG generate function
    uint32_t protectionTokenSelftestFunction;         ///< Protection token of DRBG selftest function

    /* Operation mode definition */
    uint32_t operationMode;                           ///< operationMode
} mcuxClRandom_OperationModeDescriptor_t;

/**
 * @brief Random mode descriptor structure
 *
 * This structure stores all information needed to operate a DRBG in the chosen mode.
 */
struct mcuxClRandom_ModeDescriptor
{
    const mcuxClRandom_OperationModeDescriptor_t *pOperationMode;       ///< pointer to top level information about the DRBG mode operated in (NORMALMODE, TESTMODE, PATCHMODE)
    const void *pDrbgMode;                                             ///< pointer to DRBG specific information depending on the chosen mode
    uint32_t *auxParam;                                                ///< auxiliary parameter depending on the chosen mode
    uint32_t contextSize;                                              ///< size of context
    uint16_t securityStrength;                                         ///< supported security strength of DRBG
};

struct mcuxClRandom_Context
{
    uint32_t contextCrc;                                                ///< 32 Bit CRC checksum of the complete context, including the algorithm-specific part
};


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOM_INTERNAL_TYPES_H_ */
