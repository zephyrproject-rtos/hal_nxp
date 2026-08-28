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

/** @file  mcuxClKdfModes_NIST_SP800_108.c
 *  @brief Implementation of SP800-108 Key Derivation */

#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection

#include <mcuxClKey.h>
#include <mcuxClKdfModes.h>
#include <mcuxClMac.h>
#include <mcuxClMacModes.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClKdfModes_Internal_Algorithms.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKdfModes_Internal_Functions.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClMemory_ClearSecure_Internal.h>
#include <internal/mcuxClMacModes_Common_Functions.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
/* Defines to extract actual sizes from option bits */
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(options) \
    ((((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_MASK & (~(options))) >> MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT) + 1u) * 8u)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_FROM_OPTIONS(options) \
    ((((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_MASK & (options)) >> MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT) + 1u) * 8u)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

/**
 * \brief SC (FP+DI) balancing for the for-loop inside mcuxClKdfModes_envSetup_NIST_SP800_108
 * \param[in] nOfIterations The number of loop iterations
 */
#define MCUXCLKEY_DERIVATION_DERIVATION_ENGINE_NIST_SP800_108_LOOP_SC_BALANCING(nOfIterations) \
  /* 1st if statement with Double Pipeline mode */                              \
  MCUX_CSSL_FP_CONDITIONAL(                                                      \
      (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE ==       \
       mode),                                                                   \
      ((nOfIterations) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init)),           \
      MCUX_CSSL_FP_FUNCTION_CALLED(                                              \
          mcuxClKdfModes_macProcess_AOne_NIST_SP800_108),                        \
      (((nOfIterations) - 1u) *                                                 \
       MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)),                          \
      ((nOfIterations) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish))),        \
                                                                                \
  /* Init Mac context */                                                        \
  ((nOfIterations) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init)),               \
                                                                                \
  /* Process K(i-1) for Feedback mode */                                        \
  ((nOfIterations) *                                                            \
   (MCUX_CSSL_FP_CONDITIONAL(                                                    \
        (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK ==            \
         mode),                                                                 \
        MCUX_CSSL_FP_FUNCTION_CALLED(                                            \
            mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108)) +              \
                                                                                \
    MCUX_CSSL_FP_CONDITIONAL(                                                    \
        (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE ==     \
         mode),                                                                 \
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)))),                       \
                                                                                \
  /* Process the counter [i]2 */                                                \
  ((nOfIterations) *                                                            \
   (MCUX_CSSL_FP_CONDITIONAL(                                                    \
       ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER ==             \
         mode) ||                                                               \
        (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER ==          \
         flagIncludeCounter)),                                                  \
       MCUX_CSSL_FP_FUNCTION_CALLED(                                             \
           mcuxClKdfModes_macProcess_counter_NIST_SP800_108)))),                 \
                                                                                \
  ((nOfIterations) * (MCUX_CSSL_FP_FUNCTION_CALLED(                              \
                         mcuxClKdfModes_macProcess_AOne_NIST_SP800_108))),       \
                                                                                \
  (((nOfIterations) - 1u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish)),      \
  MCUX_CSSL_FP_FUNCTION_CALLED(                                                  \
      mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108),                   \
                                                                                \
  MCUX_CSSL_FP_CONDITIONAL(                                                      \
      (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE ==       \
       mode),                                                                   \
      MCUX_CSSL_FP_LOOP_ITERATIONS(                                              \
          ifStmtModeDoublePipelineLoopCount,                                    \
          (nOfIterations) *                                                     \
              2u)), /* We increment twice for Double Pipeline                   \
                     in 2 different if statements */                            \
                                                                                \
  MCUX_CSSL_FP_CONDITIONAL(                                                      \
      (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode),       \
      MCUX_CSSL_FP_LOOP_ITERATIONS(ifStmtModeFeedbackLoopCount,                  \
                                  (nOfIterations))),                            \
                                                                                \
  MCUX_CSSL_FP_CONDITIONAL(                                                      \
      (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == mode),        \
      MCUX_CSSL_FP_LOOP_ITERATIONS(ifStmtModeCounterLoopCount,                   \
                                  (nOfIterations) * 2u))


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
  mcuxClKey_DerivationMode_t * pDerivationMode,
  const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
  mcuxClMac_Mode_t macMode,
  uint32_t options)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108);

    pDerivationMode->derivationAlgorithm = derivationAlgorithm;
    pDerivationMode->macMode = macMode;
    pDerivationMode->options = options;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108, MCUXCLKEY_STATUS_OK);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKdfModes_inputCheck_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_inputCheck_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    uint32_t mode,
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_inputCheck_NIST_SP800_108);

    /* input validation */
    if(((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode) && (numberOfInputs < 3u))
    || ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK != mode) && (numberOfInputs < 2u)))
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    uint32_t derivedKeySize = mcuxClKey_getSize(derivedKey);
    if(derivedKeySize > derivedKey->container.length)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_ERROR);
    }
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_inputCheck_NIST_SP800_108);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKdfModes_envSetup_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_envSetup_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    uint32_t *pNOfIterations,
    uint32_t *pAdditionalIteration,
    uint32_t *pOutputBytesLastIteration,
    uint32_t *pCounterByteLen,
    mcuxClKey_Derivation_t derivationMode
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_envSetup_NIST_SP800_108);

    uint32_t counterBitLen = 0u;

    MCUX_CSSL_FP_COUNTER_STMT(uint32_t outputBytesLastIterationIfStmt = *pOutputBytesLastIteration;)
    MCUX_CSSL_FP_BRANCH_DECL(lastIterationBranch);
    if(*pOutputBytesLastIteration != 0u)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("*pNOfIterations can't wrap since drivedKeySize / derivationMode->hashFunction->hashSize < UINT32_MAX")
        (*pNOfIterations)++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("*pAdditionalIteration can't wrap since it's initialized to 0")
        (*pAdditionalIteration)++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_FP_BRANCH_POSITIVE(lastIterationBranch);
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        *pOutputBytesLastIteration = derivationMode->macMode->common.macByteSize;
        MCUX_CSSL_FP_BRANCH_NEGATIVE(lastIterationBranch);
    }

    MCUX_CSSL_FP_BRANCH_DECL(counterExceedBranch);
    /* If n > 2^r-1 when the counter is encoded in the input-string, then indicate an error and stop. */
    if ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == (derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK))
            || (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER == (derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_MASK)))
    {
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(derivationMode->options, 0u, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_MASK, MCUXCLKEY_STATUS_FAULT_ATTACK)
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("*pCounterBitLen can't wrap since it's always smaller than 4.")
        counterBitLen = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_FROM_OPTIONS(derivationMode->options);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        uint32_t counterExceedMask = 0xFFFFFFFFu << (counterBitLen);

        if (0u != ((*pNOfIterations) & counterExceedMask))
        {
            MCUX_CSSL_FP_BRANCH_POSITIVE(counterExceedBranch);
            MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
        }
        else
        {
            *pCounterByteLen = (counterBitLen / 8u);
            MCUX_CSSL_FP_BRANCH_NEGATIVE(counterExceedBranch);
        }
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_envSetup_NIST_SP800_108,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(lastIterationBranch, 0u != outputBytesLastIterationIfStmt),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(lastIterationBranch, 0u == outputBytesLastIterationIfStmt),
        MCUX_CSSL_FP_CONDITIONAL(
            (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == (derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK))
            || (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER == (derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_MASK)),
                MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(counterExceedBranch, 0u != (((*pNOfIterations) & (0xFFFFFFFFu << (counterBitLen))))),
                MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(counterExceedBranch, 0u == (((*pNOfIterations) & (0xFFFFFFFFu << (counterBitLen))))))
    );
}

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClKdfModes_outputInit_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_outputInit_NIST_SP800_108(
    uint8_t **ppL,
    uint32_t flagEndianess,
    uint32_t derivedKeySizeInBits,
    uint32_t sizeOfEncodedOutputSize
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_outputInit_NIST_SP800_108);

    MCUX_CSSL_FP_SWITCH_DECL(switchProtector);
    if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN == flagEndianess)
    {
        mcuxClMemory_StoreBigEndian32(*ppL, derivedKeySizeInBits);
        /* in big endian we need to skip some upper bytes */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pL is initialized with encodedDataWorkarea and ensure no overflow by caller")
        *ppL += (sizeof(uint32_t) - sizeOfEncodedOutputSize);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN);
    }
    else if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN == flagEndianess)
    {
        mcuxClMemory_StoreLittleEndian32(*ppL, derivedKeySizeInBits);
        MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN);
    }
    else
    {
        /* Considered options are complete */
        MCUX_CSSL_FP_SWITCH_DEFAULT(switchProtector);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_outputInit_NIST_SP800_108,
        MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN == flagEndianess),
        MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN == flagEndianess),
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN != flagEndianess)
                             && (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN != flagEndianess),
            MCUX_CSSL_FP_SWITCH_TAKEN_DEFAULT(switchProtector))
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKdfModes_macProcess_AOne_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_macProcess_AOne_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context
    mcuxClMac_Context_t * pMacContext,
    uint8_t *encodedDataWorkarea,
    uint8_t *pL,
    uint32_t sizeOfEncodedOutputSize)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_macProcess_AOne_NIST_SP800_108);

    /* Process the label */
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_label, mcuxClMac_process(pSession, pMacContext, inputs[0].input, inputs[0].size));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacProcessInput_label);

    /* Process the fixed 0-byte */
    encodedDataWorkarea[0u]= 0u;
    MCUXCLBUFFER_INIT_RO(pInBuf, pSession, encodedDataWorkarea, 1u);
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_0, mcuxClMac_process(pSession, pMacContext, pInBuf, 1u));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacProcessInput_0);

    /* Process the context */
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_context, mcuxClMac_process(pSession, pMacContext, inputs[1].input, inputs[1].size));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacProcessInput_context);

    /* Process [L]2 */
    MCUXCLBUFFER_INIT_RO(pLBuf, pSession, pL, sizeOfEncodedOutputSize);
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_l, mcuxClMac_process(pSession, pMacContext, pLBuf, sizeOfEncodedOutputSize));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacProcessInput_l);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_macProcess_AOne_NIST_SP800_108,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxClMac_Context_t * pMacContext,
    uint8_t *pMacNew,
    mcuxClKey_Derivation_t derivationMode,
    uint32_t loop,
    mcuxClKey_DerivationInput_t input
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108);

    MCUX_CSSL_FP_BRANCH_DECL(loopBranch);
    if(1u != loop)
    {
        MCUXCLBUFFER_INIT_RO(pMacInBuf, pSession, pMacNew - derivationMode->macMode->common.macByteSize, derivationMode->macMode->common.macByteSize);
        MCUX_CSSL_FP_FUNCTION_CALL(
          ret,
          mcuxClMac_process(pSession, pMacContext, pMacInBuf, derivationMode->macMode->common.macByteSize)
        );
        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret);
        MCUX_CSSL_FP_BRANCH_POSITIVE(loopBranch);
    }
    else
    {
      MCUX_CSSL_FP_FUNCTION_CALL(ret, mcuxClMac_process(pSession, pMacContext, input.input, input.size));
      MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret);
      MCUX_CSSL_FP_BRANCH_NEGATIVE(loopBranch);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108,
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(loopBranch, 1u != loop),
        MCUX_CSSL_FP_BRANCH_TAKEN_NEGATIVE(loopBranch, 1u == loop),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKdfModes_macProcess_counter_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_macProcess_counter_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxClMac_Context_t * pMacContext,
    uint32_t loop,
    uint32_t counterByteLen,
    uint32_t flagEndianess,
    uint8_t *pI
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_macProcess_counter_NIST_SP800_108);

    MCUX_CSSL_FP_SWITCH_DECL(switchProtector);
    if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN == flagEndianess)
    {
        mcuxClMemory_StoreBigEndian32(pI, loop);
        /* in big endian we need to skip some upper bytes */
        MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(counterByteLen, 0u, 3u, MCUXCLMAC_STATUS_FAULT_ATTACK) \
        pI += (sizeof(uint32_t) - counterByteLen);
        MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN);
    }
    else if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN == flagEndianess)
    {
        mcuxClMemory_StoreLittleEndian32(pI, loop);
        MCUX_CSSL_FP_SWITCH_CASE(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN);
    }
    else
    {
        /* Considered options are complete */
        MCUX_CSSL_FP_SWITCH_DEFAULT(switchProtector);
    }

    MCUXCLBUFFER_INIT_RO(pIBuf, pSession, pI, counterByteLen);
    MCUX_CSSL_FP_FUNCTION_CALL(ret, mcuxClMac_process(pSession, pMacContext, pIBuf, counterByteLen));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, ret);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_macProcess_counter_NIST_SP800_108,
        MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN == flagEndianess),
        MCUX_CSSL_FP_SWITCH_TAKEN(switchProtector, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN == flagEndianess),
        MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN != flagEndianess)
                             && (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN != flagEndianess),
            MCUX_CSSL_FP_SWITCH_TAKEN_DEFAULT(switchProtector)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxCl_Buffer_t pMacRetOutBuf,
    mcuxClMac_Context_t * pMacContext,
    uint32_t *pMacOutSize,
    mcuxCl_Buffer_t pOutBuf,
    uint32_t outputBytesLastIteration
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108);

    /* Handle the last iteration, which might involve a needed output smaller than the MAC output size.
        Use a buffer on stack to generate the last MAC, and copy only the needed amount of bytes to the pMac buffer. */
    MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize , mcuxClMac_finish(pSession, pMacContext, pMacRetOutBuf, pMacOutSize));
    MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacFinalize);

    MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, pOutBuf);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, MCUXCLBUFFER_GET(pMacRetOutBuf));
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_write, outputBytesLastIteration);
    /* Error will be handled inside mcuxClBuffer_write */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_write(pOutBuf, 0u, (uint8_t*)MCUXCLBUFFER_GET(pMacRetOutBuf), outputBytesLastIteration));

    MCUX_CSSL_ANALYSIS_START_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()
    /* SREQI_KDF_1 - Clear pMacResult buffers after usage */
    /* DI for mcuxClMemory_clear_secure_int is unbalanced in mcuxClKey_derivationEngine_NIST_SP800_108 */
    MCUXCLMEMORY_CLEAR_SECURE_INT((uint8_t*)MCUXCLBUFFER_GET(pMacRetOutBuf), MCUXCLMAC_MAX_OUTPUT_SIZE);
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),
        MCUXCLMEMORY_CLEAR_SECURE_INT_FP_EXPECT
    );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_108, mcuxClKey_DerivationEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClKey_derivationEngine_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = IV (only for Feedback mode)
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_108);

    uint32_t derivedKeySize = mcuxClKey_getSize(derivedKey);
    /* Use pointer from mcuxClKey_getKeyData as temporary buffer for the plain key data */
    uint8_t *pMac = mcuxClKey_getKeyData(derivedKey);
    MCUXCLBUFFER_INIT(pOutBuf, pSession, pMac, derivedKeySize);
    const uint32_t mode = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK;

    /* DI unbalancing to protect input parameters, balanced individually after last usage. */
    MCUX_CSSL_DI_RECORD(kdfParameters, derivedKeySize);
    MCUX_CSSL_DI_RECORD(kdfParameters, derivationKey);
    MCUX_CSSL_DI_RECORD(kdfParameters, pMac);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[1].size);
    MCUX_CSSL_DI_RECORD(kdfParameters, inputs[1].input);
    /* inputs[2] = IV (only for Feedback mode) */
    if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode)
    {
      MCUX_CSSL_DI_RECORD(kdfParameters, inputs[2].size);
      MCUX_CSSL_DI_RECORD(kdfParameters, inputs[2].input);
    }

    const uint32_t flagIncludeCounter = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_MASK;
    const uint32_t flagEndianess = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_MASK & derivationMode->options;

    /* Encoding validation: Check if the derived key size, can be fully encoded in the specified encoding size */
    const uint32_t derivedKeySizeBits = (derivedKeySize << 3U);
    const uint32_t requestedEncodingBits = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(derivationMode->options);

    if((derivedKeySizeBits >> requestedEncodingBits) > 0U)
    {
        MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
    }

    /* Input validation */
    /* Errors handled inside mcuxClKdfModes_inputCheck_NIST_SP800_108 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_inputCheck_NIST_SP800_108(pSession, mode, numberOfInputs, derivedKey));

    /* r = bit-length of the binary representation of the counter i (encoded in the derivation options) = counterByteLen * 8
     * L = derivedKeySizeInBits = length of the derived key material in bits (derivedKeySize * 8u)
     * h = output length of the MAC in bits (derivationMode->macMode->common.macByteSize * 8u)
     * n = nOfIterations = ceiling(L/h)
     */
    const uint32_t derivedKeySizeInBits = derivedKeySize << 3u;

    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
         - The number of operations depends on the requested size of the derived output key,
           and on the output size of the chosen MAC.
         - The outputBytesLastIteration will be < macByteSize if the requested key's size is
           not a multiple of the MAC output size (1 <= outputBytesLastIteration <= macByteSize).
    */
    uint32_t nOfIterations = derivedKeySize / derivationMode->macMode->common.macByteSize;
    uint32_t outputBytesLastIteration = derivedKeySize % derivationMode->macMode->common.macByteSize;
    uint32_t additionalIteration = 0u;

    /* DI balancing for input parameter derivedKeySize, balanced after last usage. */
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivedKeySize);

    uint32_t counterByteLen = 0u;
    /* Errors handled inside mcuxClKdfModes_envSetup_NIST_SP800_108 */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_envSetup_NIST_SP800_108(pSession, &nOfIterations, &additionalIteration, &outputBytesLastIteration, &counterByteLen, derivationMode));

    /* The derived output key may be of any size, i.e. it does not have to be a multiple of the MAC's output size.
     * We need to handle the last iteration seperately:
     * 1. Compute the resulting MACs of all full output blocks (except the last one) in a loop and put
          the result directly to the output buffer.
         1.1 If it is Double-Pipeline mode, Compute A(i) := MAC(Key_In, A(i-1)), (A(0) := Label || 0x00 || Context || [L]2, 0x00 is optional).
         1.2 Compute K(i).
         1.2.1 If it is Feedback mode, MAC process K(i-1), K(0) = IV; if it is Double-Pipeline mode, MAC process A(i).
         1.2.2 If it is Counter mode or INCLUDE_COUNTER is set for Feedback and Double-Pipeline mode, MAC process [i]2.
         1.2.3 MAC process Label || 0x00 || Context || [L]2, 0x00 is optional.
         1.2.4 Finish MAC computation and put the result directly to the output buffer.
     * 2. Compute the resulting MAC of the last iteration (share 1.1 - 1.2.3). The MAC API does not support truncated MACs,
          so we use a temporary, block-sized output buffer for the MAC compuation. Then only the needed/requested bytes
          are copied to the actual output buffer (1 <= outputBytesLastIteration <= macByteSize).

     * If [i]2 is included in the input, we need to update the i in the encodedDataWorkarea for each iteration.
     */

    MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pCpuWa, mcuxClSession_allocateWords_cpuWa(pSession, sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t)));
    mcuxClKdfModes_WorkArea_t *pWa = mcuxClKdfModes_castPointerToCpuWa(pCpuWa);

    uint32_t macOutSize = 0u;
    /* Use a workarea buffer to encode intermediate MAC inputs. */
    /* The first 4 bytes are used for [i]2 and a zero-byte input, the following 4 bytes are for [L]2 */
    uint8_t* encodedDataWorkarea = pWa->input_Wa;

    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pWa->context_Wa);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, MCUXCLMAC_MAX_CONTEXT_SIZE);
    MCUXCLMEMORY_CLEAR_INT((uint8_t*)pWa->context_Wa, MCUXCLMAC_MAX_CONTEXT_SIZE);
    mcuxClMac_Context_t *pMacContext = mcuxClMacModes_castPointerToContext(pWa->context_Wa);
    uint8_t* pMacResult = pWa->macResult_Wa;
    MCUXCLBUFFER_INIT_RO(pMacRetInBuf, pSession, pMacResult, MCUXCLMAC_MAX_OUTPUT_SIZE);
    MCUXCLBUFFER_INIT(pMacRetOutBuf, pSession, pMacResult, MCUXCLMAC_MAX_OUTPUT_SIZE);
    /* SREQI_KDF_1 - DI records for clearing of pMacResult */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pMacResult);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, MCUXCLMAC_MAX_OUTPUT_SIZE);

    /* copy the bit-length L adjusting the endianness */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("sizeOfEncodeOutputSize can't wrap since it's always smaller than 32.")
    const uint32_t sizeOfEncodedOutputSize = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(derivationMode->options) / 8u;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    uint8_t *pL = (encodedDataWorkarea + 4U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_outputInit_NIST_SP800_108(&pL, flagEndianess, derivedKeySizeInBits, sizeOfEncodedOutputSize));

    uint32_t offset = 0U;
    MCUX_CSSL_FP_LOOP_DECL(ifStmtModeDoublePipelineLoopCount);
    MCUX_CSSL_FP_LOOP_DECL(ifStmtModeFeedbackLoopCount);
    MCUX_CSSL_FP_LOOP_DECL(ifStmtModeCounterLoopCount);
    for(uint32_t i = 1U; i <= nOfIterations; i++)
    {
        MCUX_CSSL_DI_RECORD(loop, 1u);
        /* Compute A(i) for Double-Pipeline mode */
        if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode)
        {
            /* Init Mac context */
            MCUX_CSSL_FP_FUNCTION_CALL(MacInit, mcuxClMac_init(pSession, pMacContext, derivationKey, derivationMode->macMode));
            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacInit);

            if (1u == i)
            {
                /* Errors are handled inside mcuxClKdfModes_macProcess_AOne_NIST_SP800_108 */
                MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_macProcess_AOne_NIST_SP800_108(pSession, inputs, pMacContext, encodedDataWorkarea, pL, sizeOfEncodedOutputSize));
            }
            else
            {
                /* Process A(i-1) */
                MCUX_CSSL_FP_FUNCTION_CALL(
                  MacProcessInput_AMinusOne,
                  mcuxClMac_process(pSession, pMacContext, pMacRetInBuf, derivationMode->macMode->common.macByteSize));
                MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacProcessInput_AMinusOne);
            }

            MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(pSession, pMacContext, pMacRetOutBuf, &macOutSize));
            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacFinalize);

            macOutSize = 0u;
            MCUX_CSSL_FP_LOOP_ITERATION(ifStmtModeDoublePipelineLoopCount);
        }

        /* Init Mac context */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("Mac Context is initialized in mcuxClMac_init")
        MCUX_CSSL_FP_FUNCTION_CALL(MacInit, mcuxClMac_init(pSession, pMacContext, derivationKey, derivationMode->macMode));
        MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacInit);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()

        /* Process K(i-1) for Feedback mode */
        if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode)
        {
            uint8_t* pMacNew;
            pMacNew = pMac + offset;
            /* Erros is handled inside mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108 */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_macProcess_KiMinusOne_NIST_SP800_108(pSession, pMacContext, pMacNew, derivationMode, i, inputs[2]));
            MCUX_CSSL_FP_LOOP_ITERATION(ifStmtModeFeedbackLoopCount);
        }
        else if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode) /* Process A(i) for Double-Pipline mode */
        {
          MCUX_CSSL_FP_FUNCTION_CALL(
            MacProcessInput_Ai,
            mcuxClMac_process(pSession, pMacContext, pMacRetInBuf, derivationMode->macMode->common.macByteSize)
          );
          MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacProcessInput_Ai);
          MCUX_CSSL_FP_LOOP_ITERATION(ifStmtModeDoublePipelineLoopCount);
        }
        else
        {
           /* Do nothing for Counter Mode */
           MCUX_CSSL_FP_LOOP_ITERATION(ifStmtModeCounterLoopCount);
        }

        /* Process the counter [i]2 */
        if ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == mode)
             || (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER == flagIncludeCounter))
        {
            /* copy the counter i in correct format according to the endianness */
            uint8_t *pI = encodedDataWorkarea;
            /* Error is handled inside mcuxClKdfModes_macProcess_counter_NIST_SP800_108 */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_macProcess_counter_NIST_SP800_108(pSession, pMacContext, i, counterByteLen, flagEndianess, pI));

            if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == mode)
            {
                MCUX_CSSL_FP_LOOP_ITERATION(ifStmtModeCounterLoopCount);
            }
        }

        /* Error is handled inside mcuxClKdfModes_macProcess_AOne_NIST_SP800_108 */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_macProcess_AOne_NIST_SP800_108(pSession, inputs, pMacContext, encodedDataWorkarea, pL, sizeOfEncodedOutputSize));

        if (i != nOfIterations)
        {
            /* Generate Mac output */
            MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(pSession, pMacContext, pOutBuf, &macOutSize));
            MCUXCLSESSION_CHECK_ERROR_FAULT(pSession, MacFinalize);
        }
        else
        {
            /* Handle the last iteration */
            /* Error is handled inside mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108 */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClKdfModes_macProcess_lastIteration_NIST_SP800_108(pSession, pMacRetOutBuf, pMacContext, &macOutSize, pOutBuf, outputBytesLastIteration));
        }

        MCUXCLBUFFER_UPDATE(pOutBuf, derivationMode->macMode->common.macByteSize);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("offset <= nOfIterations <= MCUXCLKEY_SIZE_8192 / MCUXCLMAC_CBCMAC_OUTPUT_SIZE <= 16; and macByteSize <= MCUXCLMAC_CBCMAC_OUTPUT_SIZE <= 16, hence offset += macByteSize < UINT32_MAX")
        offset += derivationMode->macMode->common.macByteSize;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        macOutSize = 0u;
    }

    /* DI balancing for input parameters, balanced after last usage. */
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, derivationKey);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[0].input);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].size);
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[1].input);
    /* inputs[2] = IV (only for Feedback mode) */
    if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode)
    {
        MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[2].size);
        MCUX_CSSL_DI_EXPUNGE(kdfParameters, inputs[2].input);
    }

    /* DI balancing for-loop total number of iterations */
    MCUX_CSSL_DI_EXPUNGE(loop, nOfIterations);

    /* Apply the requested encoding to the generated key data. This will overwrite the plain key data with the encoded key data */
    MCUXCLKEY_STORE_FP(pSession, derivedKey, pMac, MCUXCLKEY_ENCODING_SPEC_ACTION_NORMAL);

    /* DI balancing for input parameter pMac, balanced after last usage. */
    MCUX_CSSL_DI_EXPUNGE(kdfParameters, pMac);

    /* clean-up the CPU work-area. */
    mcuxClSession_freeWords_cpuWa(pSession, sizeof(mcuxClKdfModes_WorkArea_t) / sizeof(uint32_t));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClKey_derivationEngine_NIST_SP800_108, /* In the last iteration of the main loop */
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKdfModes_inputCheck_NIST_SP800_108),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKdfModes_envSetup_NIST_SP800_108),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa),
        MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKdfModes_outputInit_NIST_SP800_108),

        /* For-loop balancing */
        MCUXCLKEY_DERIVATION_DERIVATION_ENGINE_NIST_SP800_108_LOOP_SC_BALANCING(((derivedKeySize / derivationMode->macMode->common.macByteSize) + additionalIteration)),

        MCUXCLKEY_STORE_FP_CALLED(derivedKey)
    );
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
const mcuxClKey_DerivationAlgorithmDescriptor_t mcuxClKey_DerivationAlgorithmDescriptor_NIST_SP800_108 = {
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
    .pDerivationEngine = mcuxClKey_derivationEngine_NIST_SP800_108,
    .protectionTokenDerivationEngine = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108)
};

/* KDF in Counter Mode for CMAC */
/* \deprecated{Use ModeConstructor instead.} */
const mcuxClKey_DerivationMode_t mcuxClKey_DerivationMode_SP800_108_CM_CMAC = {
  .derivationAlgorithm = &mcuxClKey_DerivationAlgorithmDescriptor_NIST_SP800_108,
  .macMode =  (mcuxClMac_Mode_t)&mcuxClMac_ModeDescriptor_CMAC,
  .options = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_8
            | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_32
            | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN
            | MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER
};
