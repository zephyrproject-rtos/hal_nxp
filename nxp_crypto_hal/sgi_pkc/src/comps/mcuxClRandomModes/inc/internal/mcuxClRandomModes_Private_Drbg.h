/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#ifndef MCUXCLRANDOMMODES_PRIVATE_DRBG_H_
#define MCUXCLRANDOMMODES_PRIVATE_DRBG_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClSession.h>
#include <mcuxClCore_Macros.h>
#include <mcuxClRandom_Types.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLRANDOMMODES_SELFTEST_RANDOMDATALENGTH (64u)

/* Maximum Byte-length of output per generate call for any NIST SP800-90A DRBG
 * (other than the 3 Key TDES CTR_DRBG which is not supported).
 */
#define MCUXCLRANDOMMODES_DRBG_OUTPUT_MAX        (0x10000u)      //2^16

/*
 * Takes a byte size and returns the next largest multiple of MCUXCLAES_BLOCK_SIZE
 */
#define MCUXCLRANDOMMODES_ALIGN_TO_AES_BLOCKSIZE(size) \
    MCUXCLCORE_ALIGN_TO_WORDSIZE(MCUXCLAES_BLOCK_SIZE, size)

/**
 * @brief Defines to specify which mode a DRBG is operated in
 */
#define MCUXCLRANDOMMODES_NORMALMODE  (0xa5a5a5a5u)
#define MCUXCLRANDOMMODES_TESTMODE    (0x5a5a5a5au)
#define MCUXCLRANDOMMODES_PATCHMODE   (0x3d3d3d3du)

/* Shared generic internal structure of a random context used by DRBGs:
 *   - common           Common RNG context from mcuxClRandom
 *   - reseedCounter    This value is used to count the number of generateAlgorithm function calls since the last reseedAlgorithm call.
 *   - reseedSeedOffset For PTG.3 in test mode, the reseedSeedOffset counts the number of entropy input bytes already drawn from the entropy input buffer
 *                      for reseeding during an mcuxClRandom_generate call. Otherwise it's set to zero.
 *                      This value is not taken into account during reseeding in normal mode. It is only used to determine the right offset
 *                      in the entropy buffer during mcuxClRandom_generate calls for PTG.3 in test mode. */
#define MCUXCLRANDOMMODES_CONTEXT_DRBG_ENTRIES   \
        mcuxClRandom_Context_t common;           \
        uint64_t reseedCounter;                 \
        uint32_t reseedSeedOffset;

typedef struct
{
    MCUXCLRANDOMMODES_CONTEXT_DRBG_ENTRIES
} mcuxClRandomModes_Context_Generic_t;

/* Signatures for internal functions */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandomModes_instantiateAlgorithm_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRandomModes_instantiateAlgorithm_t)(
        mcuxClSession_Handle_t pSession,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context,
        uint8_t *pEntropyInputAndNonce
));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandomModes_reseedAlgorithm_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRandomModes_reseedAlgorithm_t)(
        mcuxClSession_Handle_t pSession,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context,
        uint8_t *pEntropyInput
));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandomModes_generateAlgorithm_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRandomModes_generateAlgorithm_t)(
        mcuxClSession_Handle_t pSession,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context,
        mcuxCl_Buffer_t pOut,
        uint32_t outLength,
        const uint32_t *pXorMask
));

MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClRandomModes_selftestAlgorithm_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClRandomModes_selftestAlgorithm_t)(
        mcuxClSession_Handle_t pSession,
        mcuxClRandom_Context_t testCtx,
        mcuxClRandom_ModeDescriptor_t *mode
));

typedef struct
{
    /* Function pointers for DRBG algorithms */
    mcuxClRandomModes_instantiateAlgorithm_t instantiateAlgorithm;  ///< DRBG instantiation algorithm depending on the chosen DRBG variant
    mcuxClRandomModes_reseedAlgorithm_t reseedAlgorithm;            ///< DRBG reseeding algorithm depending on the chosen DRBG variant
    mcuxClRandomModes_generateAlgorithm_t generateAlgorithm;        ///< DRBG random number generation algorithm depending on the chosen DRBG variant
    mcuxClRandomModes_selftestAlgorithm_t selftestAlgorithm;        ///< DRBG self-test handler depending on the chosen DRBG variant

    /* Protection tokens of DRBG algorithm function pointers */
    uint32_t protectionTokenInstantiateAlgorithm;             ///< Protection token of DRBG instantiate algorithm
    uint32_t protectionTokenReseedAlgorithm;                  ///< Protection token of DRBG reseed algorithm
    uint32_t protectionTokenGenerateAlgorithm;                ///< Protection token of DRBG generate algorithm
    uint32_t protectionTokenSelftestAlgorithm;                ///< Protection token of DRBG generate algorithm
} mcuxClRandomModes_DrbgAlgorithmsDescriptor_t;

typedef struct
{
    uint64_t reseedInterval;           ///< reseed interval of chosen DRBG variant
    uint16_t seedLen;                  ///< seedLen parameter defined in NIST SP 800-90A
    uint16_t initSeedSize;             ///< Size of entropy input used for instantiating the DRBG
    uint16_t reseedSeedSize;           ///< Size of entropy input used for reseeding the DRBG
    void *drbgVariantSpecifier;        ///< Additional variant-specific information
} mcuxClRandomModes_DrbgVariantDescriptor_t;

typedef struct
{
    const mcuxClRandomModes_DrbgAlgorithmsDescriptor_t *pDrbgAlgorithms;
    const mcuxClRandomModes_DrbgVariantDescriptor_t *pDrbgVariant;
    const uint32_t * const *pDrbgTestVectors;
    uint32_t continuousReseedInterval;
} mcuxClRandomModes_DrbgModeDescriptor_t;

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_castToDrbgModeDescriptor)
static inline const mcuxClRandomModes_DrbgModeDescriptor_t* mcuxClRandomModes_castToDrbgModeDescriptor(const void* pDrbgMode)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (const mcuxClRandomModes_DrbgModeDescriptor_t*) pDrbgMode;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRandomModes_castToContext_Generic)
static inline mcuxClRandomModes_Context_Generic_t* mcuxClRandomModes_castToContext_Generic(mcuxClRandom_Context_t context)
{
  MCUX_CSSL_ANALYSIS_START_CAST_TO_MORE_SPECIFIC_TYPE()
  return (mcuxClRandomModes_Context_Generic_t *) context;
  MCUX_CSSL_ANALYSIS_STOP_CAST_TO_MORE_SPECIFIC_TYPE()
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_PRIVATE_DRBG_H_ */
