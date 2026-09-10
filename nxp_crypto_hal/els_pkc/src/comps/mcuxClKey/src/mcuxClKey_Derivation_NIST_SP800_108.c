/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClKey_Derivation_NIST_SP800_108.c
 *  @brief Implementation of SP800-108 Key Derivation */

#include <mcuxClKey.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClKey_Derivation_Helper.h>

#include <mcuxClMac.h>
#include <mcuxClMacModes.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClMac_Internal_Constants.h>
#include <internal/mcuxClMac_Internal_Functions.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClMemory.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <mcuxClCore_FunctionIdentifiers.h> // Code flow protection
#include <mcuxCsslAnalysis.h>
#include <mcuxClKey_DerivationAlgorithms_NIST_SP800_108.h>
#include <internal/mcuxClKey_DerivationAlgorithms_NIST_SP800_108_Internal.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
/* Macros to extract actual sizes from option bits */
#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(options) \
    ((((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_MASK & (~(options))) >> MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_SHIFT) + 1U) * 8U)

#define MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_FROM_OPTIONS(options) \
    ((((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_MASK & (options)) >> MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_SHIFT) + 1U) * 8U)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108)
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108(
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
  mcuxClKey_DerivationMode_t * pDerivationMode,
  const mcuxClKey_DerivationAlgorithmDescriptor_t * derivationAlgorithm,
  mcuxClMac_Mode_t macMode,
  uint32_t options)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108);

    pDerivationMode->derivationAlgorithm = derivationAlgorithm;
    pDerivationMode->macMode = macMode;
    pDerivationMode->options = options;

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_Derivation_ModeConstructor_NIST_SP800_108, MCUXCLKEY_STATUS_OK);
}


/**
 * @brief   Function for validating input parameters of SP800-108 key derivation engine
 *          - verify number of inputs for each mode
 *          - verify derivedKey sizes
 *
 * @param[in]     pSession              Session handle.
 * @param[in]     numberOfInputs        Number of inputs
 * @param[in]     derivedKey            Derived key
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput(
    uint32_t mode,
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput);

    /* input validation */
    if(((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode) && (numberOfInputs < 3U))
        || ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK != mode) && (numberOfInputs < 2U)))
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput, MCUXCLKEY_STATUS_INVALID_INPUT);
    }
    if(derivedKey->type.size > derivedKey->container.length)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput, MCUXCLKEY_STATUS_ERROR);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput, MCUXCLKEY_STATUS_OK);
}


/**
 * @brief   Function for processing fist step of main calculation loop of mcuxClKey_derivationEngine_NIST_SP800_108 algorithm.
 *          This step performs double pipeline mode specific processing.
 *          In Double-Pipeline mode compute intermediate A(i) := MAC(Key_In, A(i-1)) and place the result in MacTemp buffer.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Derivation key
 * @param[in]     inputs            Pointer to SP800-108 engine inputs. Only label (inputs[0]) and context (inputs[1])
 *                                  will be processed in this step.
 * @param[in,out] pMacContext       Pointer to initialized mac context
 * @param[in]     pLBuf             Pointer label buffer
 * @param[in,out] pMacTemp          Pointer with temporary MAC results calculated in first step
 * @param[in]     i                 Current loop interation in range [1, nOfIterations]
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = IV (only for Feedback mode)
    mcuxClMac_Context_t * const pMacContext,
    mcuxCl_InputBuffer_t pLBuf,
    uint8_t * pMacTemp,
    uint32_t i)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline);

    const uint32_t mode = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK;
    const uint32_t flagSeparatorEnable = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_MASK & derivationMode->options;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This computation extracts certain bits from derivationMode->options, for which public constants are provided. It cannot overflow.")
    const uint32_t sizeOfEncodedOutputSize = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(derivationMode->options) / 8U;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    MCUXCLBUFFER_INIT_RO(pMacTempInBuf, pSession, pMacTemp, MCUXCLMAC_MAX_OUTPUT_SIZE);
    MCUXCLBUFFER_INIT(pMacTempOutBuf, pSession, pMacTemp, MCUXCLMAC_MAX_OUTPUT_SIZE);

    /* Compute A(i) for Double-Pipeline mode */
    if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode)
    {
        /* Init Mac context */
        MCUX_CSSL_FP_FUNCTION_CALL(MacInit, mcuxClMac_init(
            pSession,
            pMacContext,
            derivationKey,
            derivationMode->macMode));

        if (MCUXCLMAC_STATUS_OK != MacInit)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        if (1U == i)
        {
            /* Process the label */
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_label, mcuxClMac_process(
                pSession,
                pMacContext,
                inputs[0].input,
                inputs[0].size));

            if (MCUXCLMAC_STATUS_OK != MacProcessInput_label)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_ENABLED == flagSeparatorEnable)
            {
                /* Process the fixed 0-byte */
                uint8_t inputData = 0U;
                MCUXCLBUFFER_INIT_RO(pInBuf, pSession, &inputData, 1U);
                MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_0, mcuxClMac_process(
                    pSession,
                    pMacContext,
                    pInBuf,
                    1U));

                if (MCUXCLMAC_STATUS_OK != MacProcessInput_0)
                {
                    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
                }
            }

            /* Process the context */
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_context, mcuxClMac_process(
                pSession,
                pMacContext,
                inputs[1].input,
                inputs[1].size));

            if (MCUXCLMAC_STATUS_OK != MacProcessInput_context)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

            /* Process [L]2 */
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_l, mcuxClMac_process(
                pSession,
                pMacContext,
                pLBuf,
                sizeOfEncodedOutputSize));

            if (MCUXCLMAC_STATUS_OK != MacProcessInput_l)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }

        }
        else
        {
            /* Process A(i-1) */
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_AMinusOne, mcuxClMac_process(
                pSession,
                pMacContext,
                pMacTempInBuf,
                derivationMode->macMode->common.macByteSize));

            if (MCUXCLMAC_STATUS_OK != MacProcessInput_AMinusOne)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }
        }

        uint32_t macOutSize = 0U;
        MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(
            pSession,
            pMacContext,
            pMacTempOutBuf,
            &macOutSize
        ));

        if (MCUXCLMAC_STATUS_OK != MacFinalize)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }
    }

    /* Balance the security counter */
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_CONDITIONAL(1U == i, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process) * 2U,
            MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_ENABLED == flagSeparatorEnable),
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process))),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish));
}

/**
 * @brief   Function for processing second step of main calculation loop of mcuxClKey_derivationEngine_NIST_SP800_108 algorithm.
 *          Operations performed during this step:
 *          - Mac context initialization
 *          - Begin Computations of K(i) by performing mode specific processing:
 *              - If it is Feedback mode, MAC process K(i-1), K(0) = IV;
 *              - If it is Double-Pipeline mode, MAC process A(i) calculated in first step
 *              - If it is Counter mode or INCLUDE_COUNTER is set for Feedback and Double-Pipeline mode, MAC process [i]2.
 *
 * @param[in]     pSession          Session handle.
 * @param[in]     derivationMode    Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey     Derivation key
 * @param[in]     inputs            Pointer to SP800-108 engine inputs. Only IV (inputs[2]) is used in feedback mode.
 * @param[in,out] pMacContext       Pointer to mac context (uninitialized)
 * @param[in]     pLBuf             Pointer label buffer
 * @param[in,out] pMacTemp          Pointer to temporary MAC results. For Double-Pipeline mode must contain A(i) calculated in FirstPipeline step.
 * @param[in]     counterByteLen    Counter byte length
 * @param[in]     derivedKey        Derived key
 * @param[in]     i                 Current loop interation in range [1, nOfIterations]
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[],
    mcuxClMac_Context_t * const pMacContext,
    mcuxCl_InputBuffer_t pLBuf,
    uint8_t *pMacTemp,
    uint32_t counterByteLen,
    mcuxClKey_Handle_t derivedKey,
    uint32_t i)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable);

    const uint32_t mode = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK;
    const uint32_t flagIncludeCounter = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_MASK;
    const uint32_t flagEndianess = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_MASK & derivationMode->options;

    uint8_t *pMac = derivedKey->container.pData;
    MCUXCLBUFFER_INIT_RO(pMacTempInBuf, pSession, pMacTemp, MCUXCLMAC_MAX_OUTPUT_SIZE);

    /* Init Mac context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by trusted source mcuxClMac_init")
    MCUX_CSSL_FP_FUNCTION_CALL(MacInit, mcuxClMac_init(
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
        pSession,
        pMacContext,
        derivationKey,
        derivationMode->macMode));

    if (MCUXCLMAC_STATUS_OK != MacInit)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    MCUX_CSSL_FP_BRANCH_DECL(feedbackModeBranch);
    MCUX_CSSL_FP_BRANCH_DECL(doublePipelineModeBranch);
    MCUX_CSSL_FP_BRANCH_DECL(counterModeBranch);

    /* Process K(i-1) for Feedback mode */
    if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode)
    {
        mcuxClMac_Status_t ret_firstProcess = MCUXCLMAC_STATUS_FAULT_ATTACK;
        if(1U < i)
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This pointer arithmetic cannot wrap, derivationMode->macMode->common.macByteSize is at most MCUXCLMAC_MAX_OUTPUT_SIZE.")
            MCUXCLBUFFER_INIT_RO(pMacInBuf, pSession, pMac + (i - 2U) * derivationMode->macMode->common.macByteSize, derivationMode->macMode->common.macByteSize);
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_KiMinusOne, mcuxClMac_process(
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                pSession,
                pMacContext,
                pMacInBuf,
                derivationMode->macMode->common.macByteSize));

            ret_firstProcess = MacProcessInput_KiMinusOne;

        }
        else
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
            MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_KiMinusOne, mcuxClMac_process(
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
                pSession,
                pMacContext,
                inputs[2].input,
                inputs[2].size));

            ret_firstProcess = MacProcessInput_KiMinusOne;
        }

        if (MCUXCLMAC_STATUS_OK != ret_firstProcess)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Balance the security counter */
        MCUX_CSSL_FP_BRANCH_POSITIVE(feedbackModeBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
    }
    /* Process A(i) for Double-Pipline mode */
    else if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_Ai, mcuxClMac_process(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
            pSession,
            pMacContext,
            pMacTempInBuf,
            derivationMode->macMode->common.macByteSize));

        if (MCUXCLMAC_STATUS_OK != MacProcessInput_Ai)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* Balance the security counter */
        MCUX_CSSL_FP_BRANCH_POSITIVE(doublePipelineModeBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
    }
    else
    {
       /* Do nothing for Counter Mode - will be handled below */
    }

    /* Process the counter [i]2 */
    if ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == mode)
            || (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER == flagIncludeCounter))
    {
        /* copy the counter i in correct format according to the endianness */
        uint32_t counterData = 0U;
        uint8_t *pI = (uint8_t *)&counterData;

        if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN == flagEndianess)
        {
            mcuxClMemory_StoreBigEndian32(pI, i);
            /* in big endian we need to skip some upper bytes */
            pI += (sizeof(uint32_t) - counterByteLen);
        }
        else if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN == flagEndianess)
        {
            mcuxClMemory_StoreLittleEndian32(pI, i);
        }
        else
        {
            /* Considered options are complete */
        }

        MCUXCLBUFFER_INIT_RO(pIBuf, pSession, pI, counterByteLen);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_i, mcuxClMac_process(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
            pSession,
            pMacContext,
            pIBuf,
            counterByteLen));

        if (MCUXCLMAC_STATUS_OK != MacProcessInput_i)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        MCUX_CSSL_FP_BRANCH_POSITIVE(counterModeBranch, MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_init),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(feedbackModeBranch, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_FEEDBACK == mode),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(doublePipelineModeBranch, MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode),
        MCUX_CSSL_FP_BRANCH_TAKEN_POSITIVE(counterModeBranch, ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == mode)
             || (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER == flagIncludeCounter))));
}

/**
 * @brief   Function for processing last step of main calculation loop of mcuxClKey_derivationEngine_NIST_SP800_108 algorithm.
 *          Operations performed during this step:
            - MAC process Label || 0x00 (optional) || Context || [L]2
            - MAC finalization step
 *
 *
 * @param[in]     pSession                  Session handle.
 * @param[in]     derivationMode            Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     inputs                    Pointer to SP800-108 engine inputs. Only label (inputs[0]) and context (inputs[1])
 *                                          will be processed in this step.
 * @param[in,out] pMacContext               Pointer to initialized mac context
 * @param[out]    pOutBuf                   Pointer to output buffer
 * @param[in]     pLBuf                     Pointer label buffer
 * @param[in,out] pMacTemp                  Pointer to temporary mac buffer
 * @param[in]     i                         Current loop interation in range [1, nOfIterations]
 * @param[in]     nOfIterations             Iteration count
 * @param[in]     outputBytesLastIteration  Number of output bytes
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput)
static MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_DerivationInput_t inputs[],
    mcuxClMac_Context_t * const pMacContext,
    mcuxCl_Buffer_t pOutBuf,
    mcuxCl_InputBuffer_t pLBuf,
    uint8_t *pMacTemp,
    uint32_t i,
    uint32_t nOfIterations,
    uint32_t outputBytesLastIteration)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput);

    /* r = bit-length of the binary representation of the counter i (encoded in the derivation options) = counterByteLen * 8
     * L = derivedKeySizeInBits = length of the derived key material in bits (derivedKey->type.size * 8U)
     * h = output length of the MAC in bits (derivationMode->macMode->common.macByteSize * 8U)
     * n = nOfIterations = ceiling(L/h)
     */
    const uint32_t flagSeparatorEnable = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_MASK & derivationMode->options;

    MCUXCLBUFFER_INIT(pMacTempOutBuf, pSession, pMacTemp, MCUXCLMAC_MAX_OUTPUT_SIZE);

    /* Process the label */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_label, mcuxClMac_process(
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
        pSession,
        pMacContext,
        inputs[0].input,
        inputs[0].size));

    if (MCUXCLMAC_STATUS_OK != MacProcessInput_label)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_ENABLED == flagSeparatorEnable)
    {
        /* Process the fixed 0-byte */
        uint8_t separator = 0U;
        MCUXCLBUFFER_INIT_RO(pInBuf, pSession, &separator, 1U);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_0, mcuxClMac_process(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
            pSession,
            pMacContext,
            pInBuf,
            1U));

        if (MCUXCLMAC_STATUS_OK != MacProcessInput_0)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }
    }

    /* Process the context */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_context, mcuxClMac_process(
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
        pSession,
        pMacContext,
        inputs[1].input,
        inputs[1].size));

    if (MCUXCLMAC_STATUS_OK != MacProcessInput_context)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    /* Process [L]2 */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This computation extracts certain bits from derivationMode->options, for which public constants are provided. It cannot overflow.")
    const uint32_t sizeOfEncodedOutputSize = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(derivationMode->options) / 8U;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
    MCUX_CSSL_FP_FUNCTION_CALL(MacProcessInput_l, mcuxClMac_process(
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
        pSession,
        pMacContext,
        pLBuf,
        sizeOfEncodedOutputSize));

    if (MCUXCLMAC_STATUS_OK != MacProcessInput_l)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_FAULT_ATTACK);
    }

    uint32_t macOutSize = 0U;
    if (i != nOfIterations)
    {
        /* Generate Mac output */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
            pSession,
            pMacContext,
            pOutBuf,
            &macOutSize));

        if (MCUXCLMAC_STATUS_OK != MacFinalize)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }
    }
    else
    {
        /* Handle the last iteration, which might involve a needed output smaller than the MAC output size.
            Use a buffer on stack to generate the last MAC, and copy only the needed amount of bytes to the pMac buffer. */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_TAINTED_EXPRESSION("pMacContext is initialized by mcuxClMac_init and processed by mcuxClMac_process which are both trusted functions")
        MCUX_CSSL_FP_FUNCTION_CALL(MacFinalize, mcuxClMac_finish(
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TAINTED_EXPRESSION()
            pSession,
            pMacContext,
            pMacTempOutBuf,
            &macOutSize
        ));

        if (MCUXCLMAC_STATUS_OK != MacFinalize)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        MCUX_CSSL_FP_FUNCTION_CALL(write_result, mcuxClBuffer_write(pOutBuf, 0U, (uint8_t *) MCUXCLBUFFER_GET(pMacTempOutBuf), outputBytesLastIteration));
        if(MCUXCLBUFFER_STATUS_OK != write_result)
        {
            /* clean-up the CPU work-area. */
            mcuxClSession_freeWords_cpuWa(pSession, sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t));
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, write_result);
        }
        MCUXCLMEMORY_FP_MEMORY_CLEAR((uint8_t *)MCUXCLBUFFER_GET(pMacTempOutBuf), MCUXCLMAC_MAX_OUTPUT_SIZE);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_CONDITIONAL(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_SEPARATOR_ENABLED == flagSeparatorEnable,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process)),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_process),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMac_finish),
        MCUX_CSSL_FP_CONDITIONAL(i == nOfIterations,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_write),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear)));
}


/**
 * @brief   Key derivation engine function for mcuxClKey_derivationEngine_NIST_SP800_108 algorithm.
 *
 * @param[in]     pSession              Session handle.
 * @param[in]     derivationMode        Derivation mode, can be created with corresponding ModeConstructor.
 * @param[in]     derivationKey         Derivation key
 * @param[in]     inputs                The first element contains the label, the second contains the context and the third contains IV (only for Feedback mode).
 * @param[in]     numberOfInputs        Number of inputs
 * @param[in]     derivedKey            Derived key
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClKey_derivationEngine_NIST_SP800_108, mcuxClKey_DerivationEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_derivationEngine_NIST_SP800_108(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Derivation_t derivationMode,
    mcuxClKey_Handle_t derivationKey,
    mcuxClKey_DerivationInput_t inputs[], // inputs[0] = Label, inputs[1] = Context, inputs[2] = IV (only for Feedback mode)
    uint32_t numberOfInputs,
    mcuxClKey_Handle_t derivedKey)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClKey_derivationEngine_NIST_SP800_108);

    const uint32_t mode = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_MASK;
    const uint32_t flagIncludeCounter = derivationMode->options & MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_INCLUSION_MASK;

    MCUX_CSSL_FP_FUNCTION_CALL(ret_validateInput, mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput(
        mode,
        numberOfInputs,
        derivedKey));

    if(MCUXCLKEY_STATUS_OK != ret_validateInput)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, ret_validateInput,
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput));
    }

    uint32_t counterBitLen = 0U;
    uint32_t counterByteLen = 0U;

    /* Compute the number of operations and the byte-length of the last processing step's output (outputBytesLastIteration).
         - The number of operations depends on the requested size of the derived output key,
           and on the output size of the chosen MAC.
         - The outputBytesLastIteration will be < macByteSize if the requested key's size is
           not a multiple of the MAC output size (1 <= outputBytesLastIteration <= macByteSize).
    */
    uint32_t nOfIterations = derivedKey->type.size / derivationMode->macMode->common.macByteSize;
    uint32_t outputBytesLastIteration = derivedKey->type.size % derivationMode->macMode->common.macByteSize;

    if(outputBytesLastIteration != 0U)
    {
        /* Increase the number of iterations to also handle the last "incomplete" output block */
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("nOfIterations cannot be equal to UINT32_MAX, as derivationMode->macMode->common.macByteSize is always bigger than 1.")
        nOfIterations++;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    }
    else
    {
        /* The remaining output bytes for the last processing step are a full MAC output block */
        outputBytesLastIteration = derivationMode->macMode->common.macByteSize;
    }

    /* If n > 2^r-1 when the counter is encoded in the input-string, then indicate an error and stop. */
    if ((MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_COUNTER == mode)
            || (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_INCLUDE_COUNTER == flagIncludeCounter))
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This computation extracts certain bits from derivationMode->options, for which public constants are provided. It cannot overflow.")
        counterBitLen = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_COUNTER_SIZE_FROM_OPTIONS(derivationMode->options);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        if ((uint64_t)nOfIterations >= (1ULL << counterBitLen))
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, MCUXCLKEY_STATUS_INVALID_INPUT);

        }
        counterByteLen = (counterBitLen / 8U); /* byte-length of the counter i when encoded in the input-string */
    }

    /* The derived output key may be of any size, i.e. it does not have to be a multiple of the MAC's output size.
       We need to handle the last iteration seperately:
       1. Compute the resulting MACs of all full output blocks (except the last one) in a loop and put
          the result directly to the output buffer.
        1.1 (loop step 1) If it is Double-Pipeline mode,
            Compute A(i) := MAC(Key_In, A(i-1)), (A(0) := Label || 0x00 || Context || [L]2, 0x00 is optional).
        1.2 Compute K(i).
            1.2.1 (loop step 2) If it is Feedback mode, MAC process K(i-1), K(0) = IV; if it is Double-Pipeline mode, MAC process A(i).
            1.2.2 (loop step 2)  If it is Counter mode or INCLUDE_COUNTER is set for Feedback and Double-Pipeline mode, MAC process [i]2.
            1.2.3 (loop step 3)  MAC process Label || 0x00 || Context || [L]2, 0x00 is optional.
        2. (loop step 3)  Finish MAC computation and put the result directly to the output buffer.
          Compute the resulting MAC of the last iteration (share 1.1 - 1.2.3). The MAC API does not support truncated MACs,
          so we use a temporary, block-sized output buffer for the MAC compuation. Then only the needed/requested bytes
          are copied to the actual output buffer (1 <= outputBytesLastIteration <= macByteSize).

       If [i]2 is included in the input, we need to update the i in the inputData for each iteration.
     */
    mcuxClKeyDerivation_WorkArea_t *pWa = mcuxClKey_castToKeyDerivationWorkarea(
                                            mcuxClSession_allocateWords_cpuWa(pSession, sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t))
                                          );
    if(NULL == pWa)
    {
        MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, MCUXCLKEY_STATUS_ERROR);
    }

    uint8_t* inputData = pWa->input_Wa; // a buffer for [i]2 (use the first 4 bytes) and [L]2 (use the last 4 bytes)

    MCUXCLMEMORY_FP_MEMORY_CLEAR(pWa->context_Wa, MCUXCLMAC_MAX_CONTEXT_SIZE);
    mcuxClMac_Context_t * const pMacContext = mcuxClMac_castToMacContext(pWa->context_Wa);
    uint8_t *pMac = derivedKey->container.pData;
    uint8_t* pMacTemp = pWa->macResult_Wa;
    MCUXCLBUFFER_INIT(pOutBuf, pSession, pMac, derivedKey->type.size);

    /* copy the bit-length L adjusting the endianness */
    const uint32_t flagEndianess = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_MASK & derivationMode->options;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("This computation extracts certain bits from derivationMode->options, for which public constants are provided. It cannot overflow.")
    const uint32_t sizeOfEncodedOutputSize = MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_REQUESTED_KEYLENGTH_ENCODING_SIZE_FROM_OPTIONS(derivationMode->options) / 8U;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    const uint32_t derivedKeySizeInBits = derivedKey->type.size << 3;
    uint8_t *pL = inputData + 4U;
    if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_BIG_ENDIAN == flagEndianess)
    {
        mcuxClMemory_StoreBigEndian32(pL, derivedKeySizeInBits);
        /* in big endian we need to skip some upper bytes */
        pL += (sizeof(uint32_t) - sizeOfEncodedOutputSize);
    }
    else if(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_ENDIANESS_LITTLE_ENDIAN == flagEndianess)
    {
        mcuxClMemory_StoreLittleEndian32(pL, derivedKeySizeInBits);
    }
    else
    {
        /* Considered options are complete */
    }

    MCUXCLBUFFER_INIT_RO(pLBuf, pSession, pL, sizeOfEncodedOutputSize);

    MCUX_CSSL_FP_LOOP_DECL(loopCommon);
    for(uint32_t i = 1U; i <= nOfIterations; i++)
    {
        /* Compute A(i) for Double-Pipeline mode */
        if (MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode)
        {
            MCUX_CSSL_FP_FUNCTION_CALL(ret_sp800_108_processStep1, mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline(
                pSession,
                derivationMode,
                derivationKey,
                inputs,
                pMacContext,
                pLBuf,
                pMacTemp,
                i));

            if (MCUXCLKEY_STATUS_OK != ret_sp800_108_processStep1)
            {
                MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, MCUXCLKEY_STATUS_FAULT_ATTACK);
            }
        }

        MCUX_CSSL_FP_FUNCTION_CALL(ret_sp800_108_processStep2, mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable(
            pSession,
            derivationMode,
            derivationKey,
            inputs,
            pMacContext,
            pLBuf,
            pMacTemp,
            counterByteLen,
            derivedKey,
            i));

        if(MCUXCLKEY_STATUS_OK != ret_sp800_108_processStep2)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        MCUX_CSSL_FP_FUNCTION_CALL(ret_sp800_108_processStep3, mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput(
            pSession,
            derivationMode,
            inputs,
            pMacContext,
            pOutBuf,
            pLBuf,
            pMacTemp,
            i,
            nOfIterations,
            outputBytesLastIteration));

        if(MCUXCLKEY_STATUS_OK != ret_sp800_108_processStep3)
        {
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, MCUXCLKEY_STATUS_FAULT_ATTACK);
        }

        /* This update must be done outside of Step3 since it is ineffective (on plain buffers) when included in Step3 */
        MCUXCLBUFFER_UPDATE(pOutBuf, derivationMode->macMode->common.macByteSize);

        /* Balance the security counter */
        MCUX_CSSL_FP_LOOP_ITERATION(loopCommon,
            MCUX_CSSL_FP_CONDITIONAL(MCUXCLKEY_DERIVATION_OPTIONS_NIST_SP800_108_MODE_DOUBLE_PIPELINE == mode,
                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108_FirstPipeline)),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessIterationVariable),
            MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108_ProcessFixedInput));
    }

    /* clean-up the CPU work-area. */
    mcuxClSession_freeWords_cpuWa(pSession, sizeof(mcuxClKeyDerivation_WorkArea_t) / sizeof(uint32_t));

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClKey_derivationEngine_NIST_SP800_108, MCUXCLKEY_STATUS_OK,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivationEngine_NIST_SP800_108_ValidateInput),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_clear), /* Before the main loop */
        MCUX_CSSL_FP_LOOP_ITERATIONS(loopCommon, nOfIterations));
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

