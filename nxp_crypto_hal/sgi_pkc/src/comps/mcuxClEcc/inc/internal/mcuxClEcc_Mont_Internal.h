/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Mont_Internal.h
 * @brief internal header of mcuxClEcc MontDH functionalities
 */


#ifndef MCUXCLECC_MONT_INTERNAL_H_
#define MCUXCLECC_MONT_INTERNAL_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClSession.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClEcc_Types.h>
#include <mcuxClKey_Types.h>
#include <internal/mcuxClPkc_Internal.h>

#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_Mont_Internal_PkcWaLayout.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Internal return codes for MontDH functions             */
/**********************************************************/
// None


/**********************************************************/
/* Internal MontDH defines                                */
/**********************************************************/

/** Use 4-byte (32-bit) multiplicative blinding in MontDH. */
#define MCUXCLECC_MONTDH_SCALAR_BLINDING_BYTELEN  4u

/** Input points shall be randomized by a random Z-coordinate then re-randomized every 8th iteration in Montgomery ladder. */
#define MCUXCLECC_MONTDH_RERANDOMIZED_ITERATION_INTERVAL  8u

/**********************************************************/
/* Internal MontDH types                                  */
/**********************************************************/

/**
 * Domain parameter structure for MontDH functions.
 */
struct mcuxClEcc_MontDH_DomainParams
{
    mcuxClEcc_CommonDomainParams_t common;  ///< structure containing pointers and lengths for common ECC parameters (see Common ECC Domain parameters)
    uint16_t c;     ///< cofactor exponent
    uint16_t t;     ///< bit position of MSBit of decoded scalar
};

#ifdef MCUXCL_FEATURE_ECC_CURVE25519

/* Curve25519 domain parameters */
extern const mcuxClEcc_MontDH_DomainParams_t mcuxClEcc_MontDH_DomainParams_Curve25519;
#endif /* MCUXCL_FEATURE_ECC_CURVE25519 */
#ifdef MCUXCL_FEATURE_ECC_CURVE448

/* Curve448 domain parameters */
extern const mcuxClEcc_MontDH_DomainParams_t mcuxClEcc_MontDH_DomainParams_Curve448;
#endif /* MCUXCL_FEATURE_ECC_CURVE448 */


/**********************************************************/
/* Declarations for internal MontDH functions             */
/**********************************************************/

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_MontDH_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_SetupEnvironment(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_MontDH_DomainParams_t *pDomainParams,
    uint8_t noOfBuffers
    );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_Mont_SecureScalarMult_XZMontLadder)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_Mont_SecureScalarMult_XZMontLadder(
    mcuxClSession_Handle_t pSession,
    uint8_t iScalar,
    uint32_t scalarBitLength,
    uint32_t optionAffineOrProjective
    );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_MontDH_X)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_MontDH_X(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_MontDH_DomainParams_t *pDomainParameters,
    const uint8_t *pCoordinateUEnc
    );


/**********************************************************/
/* Define internal MontDH functions                       */
/**********************************************************/

/**
 * @brief Implements ECC key pair generation step for a MontDH key agreement according to rfc7748.
 *
 * This function performs elliptic curve key generation of the private key and calculates corresponding public key for MontDH key agreement
 * as specified in rfc7748.
 * This API does not check if the curve parameters are correct.
 * Unexpected behavior will return MCUXCLECC_STATUS_FAULT_ATTACK.
 *
 * @param[in] pSession          pointer to #mcuxClSession_Descriptor.
 * @param[in] generation        pointer to #mcuxClKey_GenerationDescriptor.
 * @param[out] privKey          private key handling structure (word-aligned)
 * @param[out] pubKey           public key handling structure (word-aligned)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_MontDH_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
    );

/**
 * @brief Implements the MontDH key agreement according to rfc7748.
 *
 * This function performs a MontDH key agreement to compute a shared secret between two parties using according to Curve25519 or Curve448 as specified in rfc7748.
 * This API does not check if the curve parameters are correct.
 * This API might return:
 *  - MCUXCLECC_STATUS_SMALL_SUBGROUP_ATTACK if generated public key lies in the small subgroup.
 *  - MCUXCLECC_STATUS_SCALAR_ZERO if the input scalar is zero (mod n).
 *  - Unexpected behavior will return MCUXCLECC_STATUS_FAULT_ATTACK.
 *
 * @param[in] pSession             pointer to #mcuxClSession_Descriptor.
 * @param[in] agreement            Key agreement algorithm specifier.
 * @param[in] key                  private key handling structure (word-aligned)
 * @param[in] otherKey             public key handling structure (word-aligned)
 * @param[in] additionalInputs     Key agreement additional input pointers (unused parameter)
 * @param[in] numberOfInputs       number of additional inputs (unused parameter)
 * @param[out] pOut                buffer for shared secret
 * @param[out] pOutLength          shared secret length
 *
 * @attention This function uses PRNG. Caller needs to check if PRNG is ready.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_MontDH_KeyAgreement, mcuxClKey_AgreementFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_MontDH_KeyAgreement(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Agreement_t agreement,
    mcuxClKey_Handle_t key,
    mcuxClKey_Handle_t otherKey,
    mcuxClKey_Agreement_AdditionalInput_t additionalInputs[],
    uint32_t numberOfInputs,
    uint8_t * pOut,
    uint32_t * const pOutLength
    );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_MONT_INTERNAL_H_ */
