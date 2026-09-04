/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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
 * @file  mcuxClEcc_EdDSA_Internal.h
 * @brief internal header of mcuxClEcc EdDSA functionalities
 */


#ifndef MCUXCLECC_EDDSA_INTERNAL_H_
#define MCUXCLECC_EDDSA_INTERNAL_H_


#include <mcuxClCore_Platform.h>
#include <mcuxClSession.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>
#include <mcuxClSignature_Types.h>
#include <mcuxClSignature_Constants.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClHash_Types.h>

#include <mcuxClEcc_Types.h>
#include <internal/mcuxClEcc_Internal.h>
#include <internal/mcuxClEcc_TwEd_Internal_PkcWaLayout.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Internal return codes for EdDSA functions              */
/**********************************************************/
// None


/**********************************************************/
/* Internal EdDSA types                                   */
/**********************************************************/

/**
 * Decode function pointer structure for EdDsa point decoding.
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClEcc_EdDSA_DecodePointFunction_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) (*mcuxClEcc_EdDSA_DecodePointFunction_t)(mcuxClSession_Handle_t pSession, mcuxClEcc_EdDSA_DomainParams_t *pDomainParams));

/**
 * Domain parameter structure for EdDSA functions.
 */
struct mcuxClEcc_EdDSA_DomainParams
{
    mcuxClEcc_CommonDomainParams_t common;  ///< structure containing pointers and lengths for common ECC parameters (see Common ECC Domain parameters)
    uint16_t b;                            ///< Integer satisfying 2^(b-1) > p. EdDSA public keys have exactly b bits, and EdDSA signatures have exactly 2*b bits.
    uint16_t c;                            ///< cofactor exponent
    uint16_t t;                            ///< bit position of MSBit of decoded scalar
    uint8_t *pSqrtMinusOne;                ///< Pointer to a square root of -1 modulo p which is needed for point decoding in case p = 5 mod 8 (i.e. only needed for Ed25519, not for Ed448)
    mcuxClHash_Algo_t algoSecHash;          ///< Hash algorithm descriptor of the hash function H() to be used for hashing the private key hash (see Public and private keys)
    mcuxClHash_Algo_t algoHash;             ///< Hash algorithm descriptor of the hash function H() to be used for hashing the private key, public data and plaintext messages
    mcuxClEcc_EdDSA_DecodePointFunction_t pDecodePointFct; ///< Function to be used to decode a point
    uint32_t pDecodePoint_FP_FuncId;                      ///< ID of function to be used to decode a point
    const uint32_t *pDomPrefix;            ///< The prefix string for dom2 or dom4
    uint32_t domPrefixLen;                 ///< Length of the prefix string for dom2 or dom4 in bytes
};

/**
 * EdDSA GenerateKeyPair variant structure.
 */
struct mcuxClEcc_EdDSA_GenerateKeyPairDescriptor
{
    uint32_t options;              ///< option of GenerateKeyPair, see @ref MCUXCLECC_EDDSA_GENERATEKEYPAIR_OPTION_
    const uint8_t *pPrivKeyInput;  ///< Pointer to private key input; set to NULL, if MCUXCLECC_EDDSA_GENERATEKEYPAIR_OPTION_GENERATE is chosen
};

/**
 * EdDSA SignatureProtocol variant structure.
 */
struct mcuxClEcc_EdDSA_SignatureProtocolDescriptor
{
    uint32_t generateOption;      ///< option of signature generation
    uint32_t verifyOption;        ///< option of signature verification
    uint32_t phflag;              ///< option of pre-hashing
    const uint8_t *pHashPrefix;   ///< pointer to hash prefix
    uint32_t hashPrefixLen;       ///< size of hash prefix
};


/**********************************************************/
/* Internal EdDSA defines                                 */
/**********************************************************/

/**
 * Size of message digest for EdDSA
 */
#define MCUXCLECC_EDDSA_MESSAGE_DIGEST_SIZE       (64u)

/**
 * Options for EdDSA key pair generation descriptors
 */
#define MCUXCLECC_EDDSA_PRIVKEY_INPUT     (0xA5A5A5A5U)  ///< the private key d is passed as input
#define MCUXCLECC_EDDSA_PRIVKEY_GENERATE  (0X5A5A5A5AU)  ///< the private key is generated internally


/* Virtual and real buffer amounts definition for EdDSA functions */
#define ECC_EDDSA_NO_OF_VIRTUALS  (ECC_NO_OF_VIRTUALS)
#define ECC_EDDSA_NO_OF_BUFFERS   (TWED_PP_Z + 1u - ECC_EDDSA_NO_OF_VIRTUALS)


/**********************************************************/
/* Declarations for internal EdDSA functions              */
/**********************************************************/

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * @brief This function implements the EdDSA key pair generation for Ed25519 and Ed448 as specified in rfc8032
 *  (see Sections 5.1.5 and 5.2.5 of https://datatracker.ietf.org/doc/html/rfc8032).
 *  For an M byte private key d, which is either generated internally at random or passed as input,
 *  this function calculates the private key hash H(d)=(h0,...,h{2b-1}) and deduces and returns
 *  - the secret integer s
 *  - the second half (hb,...,h{2b-1}) of the private key hash
 *  - the public key Qenc=(s*G)enc where G is the base point.
 *
 * This API does not check if the curve parameters are correct.
 * Unexpected behavior will return MCUXCLECC_STATUS_FAULT_ATTACK.
 *
 *
 * @param[in]     pSession              Handle for the current CL session
 * @param[in]     generation            Generation descriptor specifying the EdDSA GenerateKeyPair variant
 * @param[in,out] privKey               Key handle for the private key (word-aligned)
 * @param[out]    pubKey                Key handle for the public key (word-aligned)
 *
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_GenerateKeyPair, mcuxClKey_KeyGenFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_GenerateKeyPair(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Generation_t generation,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
);


MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * @brief This function implements the EdDSA signature generation for Ed25519 and Ed448 as specified in rfc8032 (see Sections 5.1.6 and 5.2.6 of https://datatracker.ietf.org/doc/html/rfc8032).
 *  For given hash prefix prefix (either dom2(x, y) or dom4(x, y) according to the chosen EdDSA variant; see Sections 5.1 and 5.2 of https://datatracker.ietf.org/doc/html/rfc8032),
 *  a message digest m', i.e. either the message itself for PureEdDSA or the message hash for HashEdDSA (see Section 4 of https://datatracker.ietf.org/doc/html/rfc8032),
 *  the signing keys s and (hb,...,h{2b-1}) derived from the private key d (see mcuxClEcc_EdDSA_GenerateKeyPair)
 *  and a public key Qenc, this function calculates an EdDSA signature (Renc,S), where Renc and S are given by
 *
 *      - Renc = (r*G)enc
 *      - S = r+H(prefix||Renc||Qenc||m')*s mod n
 *
 * where the secret scalar r is given by r=H(prefix||(hb,...,h{2b-1})||m') and G is the base point.
 *
 * This API does not check if the curve parameters are correct.
 * Unexpected behavior will return MCUXCLECC_STATUS_FAULT_ATTACK.
 *
 *
 * @param[in]  pSession       Handle for the current CL session
 * @param[in]  key            Key handle for private key related data which a.o. references the secret signing keys s and (hb,...,h{2b-1}) as well as the public key Qenc (word-aligned).
 * @param[in]  signatureMode  Mode descriptor specifying the EdDSA variant
 * @param[in]  pIn            Buffer for message digest m'
 * @param[in]  inSize         Size of message digest m'
 * @param[out] pSignature     Buffer for where the signature (Renc,S) will be stored
 * @param[out] pSignatureSize Will be set to the number of bytes of data that have been written to the pSignature buffer
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK            signature generation was successful
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK  fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_GenerateSignature, mcuxClSignature_SignFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClEcc_EdDSA_GenerateSignature(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key,
    mcuxClSignature_Mode_t signatureMode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_Buffer_t pSignature,
    uint32_t * const pSignatureSize
);

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * @brief This function implements the EdDSA signature verification for Ed25519 and Ed448 as specified in rfc8032 (see Sections 5.1.7 and 5.2.7 of https://datatracker.ietf.org/doc/html/rfc8032).
 *  For given hash prefix prefix (either dom2(x, y) or dom4(x, y) according to the chosen EdDSA variant; see Sections 5.1 and 5.2 of https://datatracker.ietf.org/doc/html/rfc8032),
 *  a message digest m', i.e. either the message itself for PureEdDSA or the message hash for HashEdDSA (see Section 4 of https://datatracker.ietf.org/doc/html/rfc8032),
 *  and a public key Qenc, this function:
 *     - verifies the public key Qenc
 *     - verifies that the signature component S satisfies S in [0,n-1]
 *     - verifies if the following signature equation holds:
 *          * h*S*G=h*R+h*H(prefix||Renc||Qenc||m')*Q
 *
 * This API does not check if the curve parameters are correct.
 * Unexpected behavior will return MCUXCLECC_STATUS_FAULT_ATTACK.
 *
 * Data Integrity: Record(returnCode)
 * returnCode is not recorded in case of fault attack
 *
 * @param[in]  pSession        Handle for the current CL session
 * @param[in]  key             Key handle for public key Qenc (word-aligned)
 * @param[in]  signatureMode   Mode descriptor specifying the EdDSA variant
 * @param[in]  pIn             Buffer for message digest m'
 * @param[in]  inSize          Size of message digest m'
 * @param[in]  pSignature      Buffer for the signature (Renc,S)
 * @param[in]  signatureSize   Number of bytes of data in the pSignature buffer
 *
 * @return A code-flow protected error code (see @ref MCUXCLECC_STATUS_)
 * @retval #MCUXCLECC_STATUS_OK                signature verification passed
 * @retval #MCUXCLECC_STATUS_INVALID_SIGNATURE EdDSA signature is invalid
 * @retval #MCUXCLECC_STATUS_INVALID_PARAMS    input parameters are invalid
 * @retval #MCUXCLECC_STATUS_FAULT_ATTACK      fault attack (unexpected behavior) is detected
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_VerifySignature, mcuxClSignature_VerifyFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClEcc_EdDSA_VerifySignature(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t key,
    mcuxClSignature_Mode_t signatureMode,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    mcuxCl_InputBuffer_t pSignature,
    uint32_t signatureSize
    );

/**
 * @brief This function prepares the environemnt for EdDSA algorithm execution
 *
 * @param[in]  pSession             Handle for the current CL session
 * @param[in]  pDomainParams        Pointer to domain parameters of the used curve
 * @param[in]  noOfBuffers          Number of buffer to be initalized
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_SetupEnvironment)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_SetupEnvironment(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    uint8_t noOfBuffers
    );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_CalcHashModN)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_CalcHashModN(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    const uint8_t *pHashPrefix,
    uint32_t hashPrefixLen,
    mcuxCl_InputBuffer_t pSignatureR,
    mcuxClKey_Handle_t pubKey,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize
    );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_CalcSecretScalar)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_CalcSecretScalar(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t *mode,
    mcuxClKey_Handle_t privKey,
    mcuxCl_InputBuffer_t buffMessage,
    uint32_t messageSize,
    uint8_t *pOutput
	);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_GenerateHashPrefix)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_GenerateHashPrefix(
    mcuxClSession_Handle_t pSession,
    const mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    uint32_t phflag,
    mcuxCl_InputBuffer_t pContext,
    uint32_t contextLen,
    uint8_t *pHashPrefix
    );

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_PreHashMessage)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_PreHashMessage(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams,
    mcuxClEcc_CpuWa_t * const pCpuWorkarea,
    uint32_t phflag,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inSize,
    const uint8_t **pMessage,
    uint32_t *messageSize
    );


/**
 * Declaration of the point encoding function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_EncodePoint)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_EncodePoint(
    const uint32_t encodedLen
    );

/**
 * Declaration of input key pair handle sanity checking function
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_KeyPairSanityCheck)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClEcc_EdDSA_KeyPairSanityCheck(
    mcuxClSession_Handle_t pSession,
    mcuxClKey_Handle_t privKey,
    mcuxClKey_Handle_t pubKey
    );


/**********************************************************/
/* Declarations for internal Ed25519 EdDSA functions      */
/**********************************************************/

/**
 * Declaration of the point decoding function on Ed25519
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEcc_EdDSA_DecodePoint_Ed25519, mcuxClEcc_EdDSA_DecodePointFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEcc_Status_t) mcuxClEcc_EdDSA_DecodePoint_Ed25519(
    mcuxClSession_Handle_t pSession,
    mcuxClEcc_EdDSA_DomainParams_t *pDomainParams
    );


/**********************************************************/
/* Internal EDDSA descriptors                             */
/**********************************************************/

/* EdDSA key pair generation descriptor to be used when the private key shall be generated by the
 * EdDSA key pair generation function */
extern const mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t mcuxClEcc_EdDsa_GeneratePrivKeyDescriptor;

/* Ed25519 signature protocol descriptor */
extern const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t mcuxClEcc_EdDsa_Ed25519ProtocolDescriptor;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLECC_EDDSA_INTERNAL_H_ */
