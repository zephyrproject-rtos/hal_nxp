/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024, 2026 NXP                                            */
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
 * @file  mcuxClKey_Types.h
 * @brief Type definitions for the mcuxClKey component
 */

#ifndef MCUXCLKEY_TYPES_H_
#define MCUXCLKEY_TYPES_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClKey_Types mcuxClKey_Types
 * @brief Defines all types of @ref mcuxClKey
 * @ingroup mcuxClKey
 * @{
 */

/**
 * @brief Type for Key component error codes.
 */
typedef uint32_t mcuxClKey_Status_t;

/**
 * @brief Type for algorithm based key id.
 */
typedef uint32_t mcuxClKey_AlgorithmId_t;

/**
 * @brief Type for algorithm based key size.
 */
typedef uint32_t mcuxClKey_Size_t;

/**
 * @brief Type for encoding based key id.
 */
typedef uint32_t mcuxClKey_Encoding_Spec_t;

/**
 * @brief Deprecated type for Key component error codes, returned by functions with code-flow protection.
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClKey_Status_t) mcuxClKey_Status_Encoded_t;

/* Forward declaration */
struct mcuxClKey_Encoding;

/**
 * @brief Forward declaration for Key descriptor structure
 *
 * This structure captures all the information that the Key interfaces need
 * to know about a particular key.
 */
struct mcuxClKey_Descriptor;

/**
 * @brief Key descriptor type
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key.
 */
typedef struct mcuxClKey_Descriptor mcuxClKey_Descriptor_t;

/**
 * @brief Key handle type
 *
 * This type is used to refer to the opaque key descriptor, the pointer must be word-aligned.
 */
typedef mcuxClKey_Descriptor_t * const mcuxClKey_Handle_t;

/**
 * @brief Forward declaration for Key type structure
 *
 * This structure captures all the information that the Key interfaces need to
 * know about a particular Key type.
 */
struct mcuxClKey_TypeDescriptor;

/**
 * @brief Key type descriptor type
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key type.
 */
typedef struct mcuxClKey_TypeDescriptor mcuxClKey_TypeDescriptor_t;

/**
 * @brief Key type handle type
 *
 * This type is used to refer to a key type descriptor.
 */
typedef const mcuxClKey_TypeDescriptor_t * mcuxClKey_Type_t;

/**
 * @brief Custom key type handle type
 *
 * This type is used to refer to a custom key type descriptor.
 */
typedef mcuxClKey_TypeDescriptor_t * mcuxClKey_CustomType_t;

/**
 * @brief Key encoding mechanism descriptor structure
 *
 * This structure captures all the information that the Key interfaces need to
 * know about a particular Key encoding mechanism.
 */
struct mcuxClKey_EncodingDescriptor;

/**
 * @brief Key encoding mechanism descriptor type
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key encoding mechanism.
 */
typedef struct mcuxClKey_EncodingDescriptor mcuxClKey_EncodingDescriptor_t;

/**
 * Key encoding mechanism type
 *
 * This type is used to refer to a Key encoding mechanism.
 */
typedef const mcuxClKey_EncodingDescriptor_t * mcuxClKey_Encoding_t;

/**
 * @brief Key agreement additional input pointers
 */
struct mcuxClKey_Agreement_AdditionalInput{
  mcuxCl_InputBuffer_t input;
  uint32_t size;
};

typedef struct mcuxClKey_Agreement_AdditionalInput mcuxClKey_Agreement_AdditionalInput_t;

/**
 * @brief Key agreement descriptor structure
 *
 * This structure captures all the information that the Key interfaces need to
 * know about a particular Key agreement algorithm.
 */
struct mcuxClKey_AgreementDescriptor;

/**
 * @brief Key agreement descriptor type
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key agreement algorithm.
 */
typedef struct mcuxClKey_AgreementDescriptor mcuxClKey_AgreementDescriptor_t;

/**
 * @brief Key agreement type
 *
 * This type is used to refer to a Key agreement algorithm.
 */
typedef const mcuxClKey_AgreementDescriptor_t * const mcuxClKey_Agreement_t;


#ifdef MCUXCL_FEATURE_KEY_SELFTEST

/**
 * @brief Key selftest descriptor structure
 *
 * This structure captures all the information that the Key interfaces need to
 * know about a particular Key selftest algorithm.
 */
struct mcuxClKey_TestDescriptor;

/**
 * @brief Key selftest descriptor type
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key selftest algorithm.
 */
typedef struct mcuxClKey_TestDescriptor mcuxClKey_TestDescriptor_t;

/**
 * @brief Key selftest type
 *
 * This type is used to refer to a Key selftest algorithm.
 */
typedef const mcuxClKey_TestDescriptor_t * const mcuxClKey_Test_t;
#endif /* MCUXCL_FEATURE_KEY_SELFTEST */
/**
 * @brief Key generation descriptor structure
 *
 * This structure captures all the information that the Key interfaces need to
 * know about a particular Key generation algorithm.
 */
struct mcuxClKey_GenerationDescriptor;

/**
 * @brief Key generation descriptor type
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key generation algorithm.
 */
typedef struct mcuxClKey_GenerationDescriptor mcuxClKey_GenerationDescriptor_t;

/**
 * @brief Key generation type
 *
 * This type is used to refer to a Key generation algorithm.
 */
typedef const mcuxClKey_GenerationDescriptor_t * const mcuxClKey_Generation_t;

#ifdef MCUXCL_FEATURE_KEY_DERIVATION
/**
 * @brief Key derivation algorithm descriptor structure
 */
struct mcuxClKey_DerivationAlgorithmDescriptor;

/**
 * @brief Key derivation algorithm descriptor type
 */
typedef struct mcuxClKey_DerivationAlgorithmDescriptor mcuxClKey_DerivationAlgorithmDescriptor_t;

/**
 * @brief Key derivation algorithm type
 */
typedef const mcuxClKey_DerivationAlgorithmDescriptor_t * const mcuxClKey_DerivationAlgorithm_t;

/**
 * @brief Generic key derivation input.
 */
struct mcuxClKey_DerivationInput {
  mcuxCl_InputBuffer_t input;
  uint32_t size;
};

/**
 * @brief Type of generic key derivation input.
 */
typedef struct mcuxClKey_DerivationInput mcuxClKey_DerivationInput_t;

/**
 * @brief Forward declaration for generic key derivation function descriptor structure.
 *
 * This structure captures all the information that the Key interfaces need to
 * know about a particular Key derivation algorithm.
 */
struct mcuxClKey_DerivationMode;

/**
 * @brief Generic key derivation function descriptor type.
 *
 * This descriptor captures all the information that the Key interfaces need to know
 * about a particular Key derivation algorithm.
 */
typedef struct mcuxClKey_DerivationMode mcuxClKey_DerivationMode_t;

/**
 * @brief Generic key derivation function type.
 *
 * This type captures all the information that the Key interfaces need to know
 * about a particular Key derivation algorithm.
 */
typedef const mcuxClKey_DerivationMode_t * mcuxClKey_Derivation_t;

/**
 * \brief Key type structure for keys with variable length.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_derivationKey_variableLength;

/**
 * \brief Key type pointer for keys with variable length.
 */

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")
static const mcuxClKey_Type_t mcuxClKey_Type_derivationKey_variableLength = &mcuxClKey_TypeDescriptor_derivationKey_variableLength;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_KEY_DERIVATION */

/**
 * @brief Forward declaration for generic key validation descriptor structure.
 */
struct mcuxClKey_ValidationDescriptor;

/**
 * @brief Generic key validation descriptor type.
 */
typedef struct mcuxClKey_ValidationDescriptor mcuxClKey_ValidationDescriptor_t;

/**
 * @brief Generic key validation type.
 */
typedef const mcuxClKey_ValidationDescriptor_t * const mcuxClKey_Validation_t;

/**
 * @}
 */ /* mcuxClKey_Types */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLKEY_TYPES_H_ */
