/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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
 * @file  mcuxClEcc_Types.h
 * @brief Type definitions and descriptors of mcuxClEcc component
 */


#ifndef MCUXCLECC_TYPES_H_
#define MCUXCLECC_TYPES_H_


#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClEcc_Constants.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxClBuffer.h>

#include <mcuxClSignature_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClEcc_Types mcuxClEcc_Types
 * @brief Defines all types of @ref mcuxClEcc
 * @ingroup mcuxClEcc
 * @{
 */

/**
 * @brief Type for mcuxClEcc component return codes.
 */
typedef uint32_t mcuxClEcc_Status_t;

/**
 * @brief Deprecated type for mcuxClEcc component return codes.
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_Status_Protected_t;


#ifdef MCUXCL_FEATURE_ECC_MONTDH
/** Type for MontDH domain parameters */
typedef struct mcuxClEcc_MontDH_DomainParams mcuxClEcc_MontDH_DomainParams_t;
#endif /* MCUXCL_FEATURE_ECC_MONTDH */

#ifdef MCUXCL_FEATURE_ECC_EDDSA

/** Type for EdDSA domain parameters */
typedef struct mcuxClEcc_EdDSA_DomainParams mcuxClEcc_EdDSA_DomainParams_t;

/**
 * @brief Forward declaration for EdDSA GenerateKeyPair variant structure
 */
struct mcuxClEcc_EdDSA_GenerateKeyPairDescriptor;

/**
 * @brief EdDSA GenerateKeyPair variant descriptor type
 */
typedef struct mcuxClEcc_EdDSA_GenerateKeyPairDescriptor mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t;

/**
 * @brief Forward declaration for EdDSA SignatureProtocol variant structure
 */
struct mcuxClEcc_EdDSA_SignatureProtocolDescriptor;

/**
 * @brief EdDSA SignatureProtocol variant descriptor type
 */
typedef struct mcuxClEcc_EdDSA_SignatureProtocolDescriptor mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t;
#endif /* MCUXCL_FEATURE_ECC_EDDSA */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION
/**
 * @brief Forward declaration for ECC arithmetic operation structure
 */
struct mcuxClEcc_ArithmeticOperationDescriptor;

/**
 * @brief ECC arithmetic operation descriptor type
 */
typedef struct mcuxClEcc_ArithmeticOperationDescriptor mcuxClEcc_ArithmeticOperationDescriptor_t;

/**
 * @brief ECC arithmetic operation type
 */
typedef const mcuxClEcc_ArithmeticOperationDescriptor_t * mcuxClEcc_ArithmeticOperation_t;
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION */

/** Type for Weierstrass ECC domain parameters */
typedef struct mcuxClEcc_Weier_DomainParams mcuxClEcc_Weier_DomainParams_t;

/**
 * @brief Forward declaration for Weierstrass point encoding variant structure
 */
struct mcuxClEcc_WeierECC_PointEncDescriptor;

/**
 * @brief Weierstrass point encoding variant descriptor type
 */
typedef struct mcuxClEcc_WeierECC_PointEncDescriptor mcuxClEcc_WeierECC_PointEncDescriptor_t;

/**
 * @brief Weierstrass point encoding variant type
 */
typedef const mcuxClEcc_WeierECC_PointEncDescriptor_t * mcuxClEcc_WeierECC_PointEncType_t;

/**
 * @brief Forward declaration for ECDSA SignatureProtocol variant structure
 */
struct mcuxClEcc_ECDSA_SignatureProtocolDescriptor;

/**
 * @brief ECDSA SignatureProtocol variant descriptor type
 */
typedef struct mcuxClEcc_ECDSA_SignatureProtocolDescriptor  mcuxClEcc_ECDSA_SignatureProtocolDescriptor_t;

/**********************************************************/
/* Parameter structure of mcuxClEcc APIs                   */
/**********************************************************/


/** @brief Structure to define basic custom domain parameters for (short) Weierstrass curves with cofactor 1. */
typedef struct {
    mcuxCl_InputBuffer_t pP;
    uint32_t pLen;
    mcuxCl_InputBuffer_t pA;
    mcuxCl_InputBuffer_t pB;
    mcuxCl_InputBuffer_t pG;
    mcuxCl_InputBuffer_t pN;
    uint32_t nLen;
} mcuxClEcc_Weier_BasicDomainParams_t;


/**
 * @}
 */ /* mcuxClEcc_Types */


/**********************************************************/
/* Descriptors of mcuxClEcc APIs                           */
/**********************************************************/
/**
 * @defgroup mcuxClEcc_Descriptors mcuxClEcc_Descriptors
 * @brief Defines descriptors of @ref mcuxClEcc
 * @ingroup mcuxClEcc
 * @{
 */

#ifdef MCUXCL_FEATURE_ECC_EDDSA

/** @addtogroup mcuxClEcc_EdDsaDescriptors
 * mcuxClEcc definitions of EdDSA variant descriptors
 * @{ */

/**********************************************************/
/* Signature ProtocolDescriptors and ModeDescriptors      */
/**********************************************************/

/**
 * \brief Ed25519 Signature mode descriptor
 */
extern const mcuxClSignature_ModeDescriptor_t mcuxClSignature_ModeDescriptor_Ed25519;

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * \brief Ed25519 Signature mode
 *
 * This mode shall be used to realize Ed25519 as described in RFC 8032 (https://www.rfc-editor.org/rfc/rfc8032). In particular
 *   - the size of the input message can be arbitrary
 *   - the dom2(f,c) hash prefix is the empty string as specified in Section 5.1 of RFC 8032
 *
 * NOTE: To be able to perform an Ed25519 signature generation using this mode, the private key handle must be properly linked to a key handle
 *       for the associated public key using the function mcuxClKey_linkKeyPair. This is necessary to make the public key accessible during an
 *       Ed25519 signature generation. If this is not satisfied the Ed25519 signature generation will fail.
 *       If the key pair has been generated using the mcuxClKey_generate_keypair function, this linking step is already
 *       performed by mcuxClKey_generate_keypair.
 *
 * \implements{REQ_788267}
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClSignature component. Hence, it is declared but never referenced.")
static mcuxClSignature_Mode_t mcuxClSignature_Mode_Ed25519 =
  &mcuxClSignature_ModeDescriptor_Ed25519;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/** @} */  /* mcuxClEcc_EdDsaDescriptors */

#endif /* MCUXCL_FEATURE_ECC_EDDSA */


/** @addtogroup mcuxClEcc_ECDSADescriptors
 * mcuxClEcc definitions of ECDSA variant descriptors
 * @{ */


/**
 * \brief ECDSA Signature mode descriptor
 */
 /** This mode requires that mcuxClSignature_verify is called with additional protection on pIn and inSize parameters.
 * mode, pIn and inSize parameters must be protected using mcuxClSignature_verify_recordParam function before executing mcuxClSignature_verify.
 */
extern const mcuxClSignature_ModeDescriptor_t mcuxClSignature_ModeDescriptor_ECDSA;

/**
 * \brief ECDSA Signature mode
 *
 * \implements{REQ_788264,REQ_788265}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClSignature component. Hence, it is declared but never referenced.")
static mcuxClSignature_Mode_t mcuxClSignature_Mode_ECDSA =
  &mcuxClSignature_ModeDescriptor_ECDSA;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/** @} */  /* mcuxClEcc_ECDSADescriptors */

/**
 * @}
 */ /* mcuxClEcc_Descriptors */

/**
 * @defgroup mcuxClEcc_DomainParamsDescriptor mcuxClEcc_DomainParamsDescriptor
 * @brief Definitions of domain parameters variant descriptors
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */
#ifdef MCUXCL_FEATURE_ECC_SECPK1_CURVES

/**
 * \brief secp160k1 domain parameters
 *
 * Domain parameters for the secp160k1 elliptic curve.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp160k1;

/**
 * \brief secp192k1 domain parameters
 *
 * Domain parameters for the secp192k1 elliptic curve.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp192k1;

/**
 * \brief secp224k1 domain parameters
 *
 * Domain parameters for the secp224k1 elliptic curve.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp224k1;

/**
 * \brief secp256k1 domain parameters
 *
 * Domain parameters for the secp256k1 elliptic curve.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp256k1;
#endif /* MCUXCL_FEATURE_ECC_SECPK1_CURVES */
#if defined(MCUXCL_FEATURE_ECC_SECPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_NISTPR1_CURVES) || defined(MCUXCL_FEATURE_ECC_ANSIX9P_CURVES)

/**
 * \brief secp192r1 (nistp192r1, ansix9p192r1) domain parameters
 *
 * Domain parameters for the secp192r1 elliptic curve, also known as NIST P-192
 * and ANSI X9.62 prime192r1.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
  * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
  * User may generate accelerated version using custom domain parameter generation
  * procedure with mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
  */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp192r1;
#define mcuxClEcc_Weier_DomainParams_NIST_P192 mcuxClEcc_Weier_DomainParams_secp192r1
#define mcuxClEcc_Weier_DomainParams_ansix9p192r1 mcuxClEcc_Weier_DomainParams_secp192r1

/**
 * \brief secp224r1 (nistp224r1, ansix9p224r1) domain parameters
 *
 * Domain parameters for the secp224r1 elliptic curve, also known as NIST P-224
 * and ANSI X9.62 prime224r1.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
  * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
  * User may generate accelerated version using custom domain parameter generation
  * procedure with mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp224r1;
#define mcuxClEcc_Weier_DomainParams_NIST_P224 mcuxClEcc_Weier_DomainParams_secp224r1
#define mcuxClEcc_Weier_DomainParams_ansix9p224r1 mcuxClEcc_Weier_DomainParams_secp224r1

/**
 * \brief secp256r1 (nistp256r1, ansix9p256r1) domain parameters
 *
 * Domain parameters for the secp256r1 elliptic curve, also known as NIST P-256
 * and ANSI X9.62 prime256r1.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
  * Calculations using those domain parameters are accelerated using precomputed points.
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp256r1;
#define mcuxClEcc_Weier_DomainParams_NIST_P256 mcuxClEcc_Weier_DomainParams_secp256r1
#define mcuxClEcc_Weier_DomainParams_ansix9p256r1 mcuxClEcc_Weier_DomainParams_secp256r1

/**
 * \brief secp384r1 (nistp384r1, ansix9p384r1) domain parameters
 *
 * Domain parameters for the secp384r1 elliptic curve, also known as NIST P-384
 * and ANSI X9.62 prime384r1.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
  * Calculations using those domain parameters are accelerated using precomputed points.
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp384r1;
#define mcuxClEcc_Weier_DomainParams_NIST_P384 mcuxClEcc_Weier_DomainParams_secp384r1
#define mcuxClEcc_Weier_DomainParams_ansix9p384r1 mcuxClEcc_Weier_DomainParams_secp384r1

/**
 * \brief secp521r1 (nistp521r1, ansix9p521r1) domain parameters
 *
 * Domain parameters for the secp521r1 elliptic curve, also known as NIST P-521
 * and ANSI X9.62 prime521r1.
 *
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
  * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
  * User may generate accelerated version using custom domain parameter generation
  * procedure with mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_secp521r1;
#define mcuxClEcc_Weier_DomainParams_NIST_P521 mcuxClEcc_Weier_DomainParams_secp521r1
#define mcuxClEcc_Weier_DomainParams_ansix9p521r1 mcuxClEcc_Weier_DomainParams_secp521r1
#endif /* defined(SECPR1_CURVES) || defined(NISTPR1_CURVES) || defined(ANSIX9P_CURVES) */
#ifdef MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES

/**
 * \brief brainpoolP160r1 domain parameters
 *
 * Domain parameters for the brainpoolP160r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP160r1;

/**
 * \brief brainpoolP192r1 domain parameters
 *
 * Domain parameters for the brainpoolP192r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP192r1;

/**
 * \brief brainpoolP224r1 domain parameters
 *
 * Domain parameters for the brainpoolP224r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP224r1;

/**
 * \brief brainpoolP256r1 domain parameters
 *
 * Domain parameters for the brainpoolP256r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP256r1;

/**
 * \brief brainpoolP320r1 domain parameters
 *
 * Domain parameters for the brainpoolP320r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP320r1;

/**
 * \brief brainpoolP384r1 domain parameters
 *
 * Domain parameters for the brainpoolP384r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP384r1;

/**
 * \brief brainpoolP512r1 domain parameters
 *
 * Domain parameters for the brainpoolP512r1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP512r1;
#endif /* MCUXCL_FEATURE_ECC_BRAINPOOLR1_CURVES */
#ifdef MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES

/**
 * \brief brainpoolP160t1 domain parameters
 *
 * Domain parameters for the brainpoolP160t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP160t1;

/**
 * \brief brainpoolP192t1 domain parameters
 *
 * Domain parameters for the brainpoolP192t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP192t1;

/**
 * \brief brainpoolP224t1 domain parameters
 *
 * Domain parameters for the brainpoolP224t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP224t1;

/**
 * \brief brainpoolP256t1 domain parameters
 *
 * Domain parameters for the brainpoolP256t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP256t1;

/**
 * \brief brainpoolP320t1 domain parameters
 *
 * Domain parameters for the brainpoolP320t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP320t1;

/**
 * \brief brainpoolP384t1 domain parameters
 *
 * Domain parameters for the brainpoolP384t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP384t1;

/**
 * \brief brainpoolP512t1 domain parameters
 *
 * Domain parameters for the brainpoolP512t1 elliptic curve.
 *
 #ifdef MCUXCL_FEATURE_ECC_WEIERECC_EXTENDED_PRECOMPUTEDPOINTS
 * Calculations using those domain parameters are NOT accelerated using precomputed points.
#ifdef MCUXCL_FEATURE_ECC_WEIERECC_GENERATECUSTOMDOMAINPARAMS
 * User may generate accelerated version using custom domain parameter generation
 * procedure calling mcuxClEcc_WeierECC_GenerateDomainParams().
#endif
#endif
 */
extern const mcuxClEcc_Weier_DomainParams_t mcuxClEcc_Weier_DomainParams_brainpoolP512t1;
#endif /* MCUXCL_FEATURE_ECC_BRAINPOOLT1_CURVES */


/* Ed25519 domain parameters */
extern const mcuxClEcc_EdDSA_DomainParams_t mcuxClEcc_EdDSA_DomainParams_Ed25519;

/**
 * @}
 */ /* mcuxClEcc_DomainParamsDescriptor */

/**
 * @defgroup mcuxClEcc_WeierECC_PointEncDescriptors mcuxClEcc_WeierECC_PointEncDescriptor
 * @brief Definitions of Weierstrass point encoding variant descriptors
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */


/*********************************************************/
/* Encoding types related to point encoding specified in */
/* SEC 1: Elliptic Curve Cryptography                    */
/*********************************************************/

/**
 * @brief Point encoding variant descriptor to be used for Weierstrass curve points as specified in SEC 1: Elliptic Curve Cryptography
 *
 */
extern const mcuxClEcc_WeierECC_PointEncDescriptor_t mcuxClEcc_WeierECC_PointEncDescriptor_SEC;

/**
 * @brief Point encoding type to be used for Weierstrass curve points as specified in SEC 1: Elliptic Curve Cryptography
 *
 * SEC encoding which encodes
 *  - the neutral point as 0x00
 *  - a point (x,y) either as
 *    - 0x04 || x || y if no point-compression is used
 *    - (0x02 | LSBit(y)) || x if point-compression is used.
 *  NOTES:
 *   - If the encoded point starts with 0x00, nothing is written to the output buffer, but
 *     #MCUXCLECC_STATUS_NEUTRAL_POINT is returned from the decoding function.
 *   - If the encoded point starts with 0x02 or 0x03 the compressed point gets decompressed.
 *   - If the encoding is invalid, i.e. the leading bytes is not in {0x00,0x02,0x03,0x04},
 *     #MCUXCLECC_STATUS_INVALID_PARAMS is returned from the decoding function.
 *   - If the encoded point is not on the curve,
 *     #MCUXCLECC_STATUS_INVALID_PARAMS is returned from the decoding function.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static const mcuxClEcc_WeierECC_PointEncType_t mcuxClEcc_WeierECC_PointEncType_SEC = &mcuxClEcc_WeierECC_PointEncDescriptor_SEC;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @}
 */ /* mcuxClEcc_WeierECC_PointEncDescriptors */


/**
 * @defgroup mcuxClEcc_ArithmeticOperation mcuxClEcc_ArithmeticOperation
 * @brief Definionts of variant descriptors for arithmetic operations of @ref mcuxClEcc
 * @ingroup mcuxClEcc_Descriptors
 * @{
 */

#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD
/**
 * \brief ECC Arithmetic operation descriptor for full point addition on a short Weierstrass curve not secured against side-channel attacks
 */
extern const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_PointAdd;

/**
 * \brief ECC Arithmetic operation type for full point addition on a short Weierstrass curve not secured against side-channel attacks
 *
 * This type shall be passed to function mcuxClEcc_ArithmeticOperation in order to perform a full point addition P1 + P2
 * on a short Weierstrass curve over prime p with base point order n. The function is not secured against side-channel attacks.
 *
 * The parameters of the function shall be chosen as follows:
 *
 *  - pDomainParams:  Pointer to the domain parameters of the Weierstrass curve (of type mcuxClEcc_Weier_DomainParams_t)
 *  - pOp1:           Pointer to buffer storing the coordinates x1 and y1 of P1 concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= x1,y1 < p, and given by byteLen(p) bytes in big endian format.
 *                    The passed parameter size op1Size must be 2*byteLen(p).
 *  - pOp2:           Pointer to buffer storing the coordinates x2 and y2 of P2 concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= x2,y2 < p, and given by byteLen(p) bytes in big endian format.
 *                    The passed parameter size op2Size must be 2*byteLen(p).
 *  - pResult:        Point to buffer in which the coordinates xRes and yRes of the result P1 + P2 shall be stored concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= xRes,yRes < p, and given by byteLen(p) bytes in big endian format.
 *                    This buffer will only be written if #MCUXCLECC_STATUS_OK is returned.
 *
 * The function returns
 *
 *  - #MCUXCLECC_STATUS_OK               if the operation was successful.
 *  - #MCUXCLECC_STATUS_INVALID_PARAMS   if the input parameters are invalid.
 *  - #MCUXCLECC_STATUS_NEUTRAL_POINT    if P1 + P2 is the neutral point.
 *
 * \implements{REQ_788270}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static mcuxClEcc_ArithmeticOperation_t mcuxClEcc_ArithmeticOperation_PointAdd =
  &mcuxClEcc_ArithOpDesc_PointAdd;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTADD */


#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB
/**
 * \brief ECC Arithmetic operation descriptor for full point subtraction on a short Weierstrass curve not secured against side-channel attacks
 */
extern const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_PointSub;

/**
 * \brief ECC Arithmetic operation type for full point subtraction on a short Weierstrass curve not secured against side-channel attacks
 *
 * This type shall be passed to function mcuxClEcc_ArithmeticOperation in order to perform a full point subtraction P1 - P2
 * on a short Weierstrass curve over prime p with base point order n. The function is not secured against side-channel attacks.
 *
 * The parameters of the function shall be chosen as follows:
 *
 *  - pDomainParams:  Pointer to the domain parameters of the Weierstrass curve (of type mcuxClEcc_Weier_DomainParams_t)
 *  - pOp1:           Pointer to buffer storing the coordinates x1 and y1 of P1 concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= x1,y1 < p, and given by byteLen(p) bytes in big endian format.
 *                    The passed parameter size op1Size must be 2*byteLen(p).
 *  - pOp2:           Pointer to buffer storing the coordinates x2 and y2 of P2 concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= x2,y2 < p, and given by byteLen(p) bytes in big endian format.
 *                    The passed parameter size op2Size must be 2*byteLen(p).
 *  - pResult:        Point to buffer in which the coordinates xRes and yRes of the result P1 - P2 shall be stored concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= xRes,yRes < p, and given by byteLen(p) bytes in big endian format.
 *                    This buffer will only be written if #MCUXCLECC_STATUS_OK is returned.
 *
 * The function returns
 *
 *  - #MCUXCLECC_STATUS_OK               if the operation was successful.
 *  - #MCUXCLECC_STATUS_INVALID_PARAMS   if the input parameters are invalid.
 *  - #MCUXCLECC_STATUS_NEUTRAL_POINT    if P1 - P2 is the neutral point.
 *
 * \implements{REQ_788271}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static mcuxClEcc_ArithmeticOperation_t mcuxClEcc_ArithmeticOperation_PointSub =
  &mcuxClEcc_ArithOpDesc_PointSub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_POINTSUB */


#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SCALARMULT
/**
 * \brief ECC Arithmetic operation descriptor for scalar multiplication on a short Weierstrass curve not secured against side-channel attacks
 */
extern const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_ScalarMult;

/**
 * \brief ECC Arithmetic operation type for scalar multiplication on a short Weierstrass curve not secured against side-channel attacks
 *
 * This type shall be passed to function mcuxClEcc_ArithmeticOperation in order to perform a scalar multiplication k*P
 * on a short Weierstrass curve over prime p with base point order n. The function is not secured against side-channel attacks.
 *
 * The parameters of the function shall be chosen as follows:
 *
 *  - pDomainParams:  Pointer to the domain parameters of the Weierstrass curve (of type mcuxClEcc_Weier_DomainParams_t)
 *  - pOp1:           Pointer to buffer storing the scalar k.
 *                    The scalar is an element of GF(n), i.e. 0 <= k < n, and given in big endian format.
 *                    The passed parameter size op1Size must be smaller than or equal to byteLen(n).
 *  - pOp2:           Pointer to buffer storing the coordinates x and y of P concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= x,y < p, and given by byteLen(p) bytes in big endian format.
 *                    The passed parameter size op2Size must be 2*byteLen(p).
 *  - pResult:        Point to buffer in which the coordinates xRes and yRes of the result k*P shall be stored concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= xRes,yRes < p, and given by byteLen(p) bytes in big endian format.
 *                    This buffer will only be written if #MCUXCLECC_STATUS_OK is returned.
 *
 * The function returns
 *
 *  - #MCUXCLECC_STATUS_OK               if the operation was successful.
 *  - #MCUXCLECC_STATUS_INVALID_PARAMS   if the input parameters are invalid.
 *  - #MCUXCLECC_STATUS_NEUTRAL_POINT    if k*P is the neutral point, i.e. k = 0.
 *
 * \implements{REQ_788268}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static mcuxClEcc_ArithmeticOperation_t mcuxClEcc_ArithmeticOperation_ScalarMult =
  &mcuxClEcc_ArithOpDesc_ScalarMult;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SCALARMULT */


#ifdef MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SECURESCALARMULT
/**
 * \brief ECC Arithmetic operation descriptor for scalar multiplication on a short Weierstrass curve secured against side-channel attacks
 */
extern const mcuxClEcc_ArithmeticOperationDescriptor_t mcuxClEcc_ArithOpDesc_SecureScalarMult;

/**
 * \brief ECC Arithmetic operation type for scalar multiplication on a short Weierstrass curve secured against side-channel attacks
 *
 * This type shall be passed to function mcuxClEcc_ArithmeticOperation in order to perform a scalar multiplication k*P secured against side-channel attacks
 * on a short Weierstrass curve over prime p with base point order n.
 *
 * The parameters of the function shall be chosen as follows:
 *
 *  - pDomainParams:  Pointer to the domain parameters of the Weierstrass curve over p (of type mcuxClEcc_Weier_DomainParams_t)
 *  - pOp1:           Pointer to buffer storing the scalar k.
 *                    The scalar is an element of GF(n), i.e. 0 <= k < n, and given in big endian format.
 *                    The passed parameter size op1Size must be smaller than or equal to byteLen(n).
 *  - pOp2:           Pointer to buffer storing the coordinates x and y of P concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= x,y < p, and given by byteLen(p) bytes in big endian format.
 *                    The passed parameter size op2Size must be 2*byteLen(p).
 *  - pResult:        Point to buffer in which the coordinates xRes and yRes of the result k*P shall be stored concatenated.
 *                    Both coordinates are elements of GF(p), i.e. 0 <= xRes,yRes < p, and given by byteLen(p) bytes in big endian format.
 *                    This buffer will only be written if #MCUXCLECC_STATUS_OK is returned.
 *
 * The function returns
 *
 *  - #MCUXCLECC_STATUS_OK               if the operation was successful.
 *  - #MCUXCLECC_STATUS_INVALID_PARAMS   if the input parameters are invalid.
 *  - #MCUXCLECC_STATUS_NEUTRAL_POINT    if k*P is the neutral point, i.e. k = 0.
 *
 * \implements{REQ_788268}
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced.")
static mcuxClEcc_ArithmeticOperation_t mcuxClEcc_ArithmeticOperation_SecureScalarMult =
  &mcuxClEcc_ArithOpDesc_SecureScalarMult;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_ECC_ARITHMETICOPERATION_SECURESCALARMULT */

/** @} */ /* mcuxClEcc_ArithmeticOperation */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_TYPES_H_ */
