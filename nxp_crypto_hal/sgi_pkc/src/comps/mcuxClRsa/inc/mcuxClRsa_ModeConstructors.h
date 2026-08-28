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

#ifndef MCUXCLRSA_MODECONSTRUCTORS_H_
#define MCUXCLRSA_MODECONSTRUCTORS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>

#include <mcuxClSignature_Types.h>

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <mcuxClCipher_Types.h>
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

#include <mcuxClKey_Types.h>
#include <mcuxClHash_Types.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Descriptors of mcuxClRsa APIs                           */
/**********************************************************/
/**
 * @defgroup mcuxClRsa_Descriptors mcuxClRsa_Descriptors
 * @brief Defines descriptors of @ref mcuxClRsa
 * @ingroup mcuxClRsa
 * @{
 */
/**
 * @defgroup clRsaSignatureModes Signature RSA mode definitions
 * @brief Modes used by the Signature operations with RSA.
 * @ingroup clSignatureModes
 * @{
 */

/**
 * @brief RSA signature protocol descriptor structure
 *
 * This structure captures all the information that the Signature interfaces need
 * to know about RSA-specific operations.
 */
struct mcuxClRsa_Signature_ProtocolDescriptor;
typedef struct mcuxClRsa_Signature_ProtocolDescriptor mcuxClRsa_SignatureProtocolDescriptor_t;

/**
 * @brief Mode constructor for RSASSA-PSS signature generation and verification
 *
 * @param pSignatureMode      Pointer to a mode descriptor that will be updated by this function.
 * @param pProtocolDescriptor Pointer to an RSA protocol descriptor that will be updated by this function.
 * @param hashAlgorithm       Hash algorithm that should be used.
 * @param saltLength          Number of bytes of the salt.
 * @param options             RSA options:
 *                            - MCUXCLRSA_OPTION_VERIFY_NOHWACC: perform pure SW verification, without using HW acceleration
 *
 * @pre
 * - The RNG context must be initialized before performing an RSA signature generation with RSASSA-PSS.
 *
 * @implements{REQ_788249,REQ_788250,REQ_788253}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_SignatureModeConstructor_RSASSA_PSS)
MCUX_CSSL_FP_PROTECTED_TYPE (void) mcuxClRsa_SignatureModeConstructor_RSASSA_PSS(
  mcuxClSignature_ModeDescriptor_t * pSignatureMode,
  mcuxClRsa_SignatureProtocolDescriptor_t * pProtocolDescriptor,
  mcuxClHash_Algo_t hashAlgorithm,
  uint32_t saltLength,
  uint32_t options
);

/**
 * @brief Mode constructor for RSASSA-PKCS1-v1_5 signature generation and verification
 *
 * @param pSignatureMode      Pointer to a mode descriptor that will be updated by this function.
 * @param pProtocolDescriptor Pointer to an RSA protocol descriptor that will be updated by this function.
 * @param hashAlgorithm       Hash algorithm that should be used.
 * @param options             RSA options:
 *                            - MCUXCLRSA_OPTION_VERIFY_NOHWACC: perform pure SW verification, without using HW acceleration
 *
 * \implements{REQ_788249,REQ_788250,REQ_788252}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_SignatureModeConstructor_RSASSA_PKCS1_v1_5)
MCUX_CSSL_FP_PROTECTED_TYPE (void) mcuxClRsa_SignatureModeConstructor_RSASSA_PKCS1_v1_5(
  mcuxClSignature_ModeDescriptor_t * pSignatureMode,
  mcuxClRsa_SignatureProtocolDescriptor_t * pProtocolDescriptor,
  mcuxClHash_Algo_t hashAlgorithm,
  uint32_t options
);


/** @} */

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
/**
 * @defgroup clRsaCipherModes Cipher RSA mode definitions
 * @brief Modes used by the Cipher operations with RSA.
 * @ingroup clRsaCipherModes
 * @{
 */

#ifdef MCUXCL_FEATURE_RSA_RSAES_OAEP
/**
 * @brief Mode constructor for RSAES-OAEP-ENCRYPT and RSAES-OAEP-DECRYPT operation
 *
 * @param pCipherMode         Pointer to a mode descriptor that will be updated by this function.
 * @param hashAlgorithm       Hash algorithm that should be used.
 *
 * @pre
 * - Sufficient space should be allocated for the cipher mode and RSA-specific content,
 *   using the macro MCUXCLRSA_CIPHER_MODE_SIZE.
 * - The RNG context must be initialized before performing an RSA encryption with RSAES-OAEP-ENCRYPT.
 *
 * @implements{REQ_788246,REQ_788248}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_CipherModeConstructor_RSAES_OAEP)
MCUX_CSSL_FP_PROTECTED_TYPE (void) mcuxClRsa_CipherModeConstructor_RSAES_OAEP(
  mcuxClCipher_ModeDescriptor_t * pCipherMode,
  mcuxClHash_Algo_t hashAlgorithm
);
#endif /* MCUXCL_FEATURE_RSA_RSAES_OAEP */

/**
 * @brief Mode constructor for RSAES-PKCS1-V1_5-ENCRYPT and RSAES-PKCS1-V1_5-DECRYPT operation
 *
 * @param pCipherMode         Pointer to a mode descriptor that will be updated by this function.
 *
 * @pre
 * - Sufficient space should be allocated for the cipher mode and RSA-specific content,
 *   using the macro MCUXCLRSA_CIPHER_MODE_SIZE.
 * - The RNG context must be initialized before performing an RSA encryption with RSAES-PKCS1-V1_5-ENCRYPT.
 *
 * @implements{REQ_788246,REQ_788247}
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5)
MCUX_CSSL_FP_PROTECTED_TYPE (void) mcuxClRsa_CipherModeConstructor_RSAES_PKCS1_v1_5(
  mcuxClCipher_ModeDescriptor_t * pCipherMode
);


/** @} */
#endif /* defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT) */

/**
 * @defgroup mcuxClRsa_KeyGeneration_ModeDescriptor Key Generation RSA mode descriptor
 * @brief RSA key generation mode descriptor.
 * @details RSA key generation related defines used construct the mode descriptor used by @ref mcuxClKey_generate_keypair
 *  function.
 * @ingroup mcuxClRsa_KeyGeneration_ModeDescriptor
 * @{
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_URL_IN_COMMENTS()
/**
 * @brief Mode constructor for RSA key generation algorithm.
 *
 * @details
 *         This function can be used to create mode descriptor used by @ref mcuxClKey_generate_keypair function.
 *         This mode shall be used to realize RSA key generation operation according to FIPS 186-5
 *         (https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.186-5.pdf), in particular:
 *         <ul>
 *             <li>method provided in Appendix A.1.3 used for the generation of the random primes p and q
 *                  that are probably prime;</li>
 *             <li>public exponent e, primes p and q and private exponent d meet the criteria specified
 *                 in Appendix A.1.1. According to the criteria the exponent e is restricted to odd values
 *                 in the range \f$(2^{16}<e<2^{256})\f$.</li>
 *             <li>primes p and q are generated using probabilistic primality test with the error probability
 *                 lower than \f$2^{-125}\f$. The number of Miller-Rabin test iterations is consistent with the
 *                 SOGIS Agreed Cryptographic Mechanisms version 1.2.
 *                 (https://www.sogis.eu/documents/cc/crypto/SOGIS-Agreed-Cryptographic-Mechanisms-1.2.pdf) </li>
 *         </ul>
 *         To be able to perform an key generation using  @ref mcuxClKey_generate_keypair and this mode:
 *         <ul>
 *            <li>Session must be initialized with workareas for CPU and PKC operations that considers the workareas
 *                required by this mode for the given key type and size (see @ref MCUXCLRSA_KEYGENERATION_PLAIN_WA and
 *                @ref MCUXCLRSA_KEYGENERATION_CRT_WA).</li>
 *            <li>RNG context must be initialized using mode @ref mcuxClRandomModes_Constants which will ensure the entropy level
 *                (security strength) in accordance with the generated key size, as specified in SP 800-57, Part 1.</li>
 *            <li>Handle of private key must be properly initialized  with @ref mcuxClKey_init function using:</li>
 *            <ul>
 *               <li>appropriate RSA private @ref mcuxClRsa_KeyTypes_Descriptors;</li>
 *               <li>pointer to key data buffer where the generated private key will be stored. The buffer shall be allocated using
 *                   pre-define sizes @ref MCUXCLRSA_KEYGENERATION_KEY_DATA_SIZE for the given key type and key size.</li>
 *            </ul>
 *            <li>Handle of public key must be properly initialized  with @ref mcuxClKey_init function using:</li>
 *            <ul>
 *               <li>appropriate RSA public @ref mcuxClRsa_KeyTypes_Descriptors;</li>
 *               <li>pointer to key data buffer where the generated public key will be stored.  The buffer shall be allocated using
 *                   pre-define sizes @ref MCUXCLRSA_KEYGENERATION_KEY_DATA_SIZE for the given key type and key size.</li>
 *            </ul>
 *            <li>pointers to key data buffers and key handle must be aligned to CPU word size</li>
 *         </ul>
 *
 * @note   There are the following deviations were applied from the algorithm specified in Appendix B.3.3 of FIPS 186-4:
 * @note   \li Primes p and q are chosen to be congruent \f$3\mod4\f$.\n
 *             Rationale: With this additional restriction on p and q a generated key is still compatible with FIPS 186-4.
 *             Such primes and their products have properties that simplify algorithms, for example step 4.5 in Miller-Rabin test
 *             described in Appendix B.3.1 can be skipped (due to fact that a=1). This restriction has positive impact on the security,
 *             performance, and code size. This approach was also accepted in other products.
 * @note   \li Checks performed in steps 4.4 and 5.5 are done using only 64 most significant bits of the value
 *             specified by the expression \f$(\sqrt{2})(2^{(nlen/2)–1})\f$ and rounded up, it is 0xb504f333f9de6485.\n
 *             Rationale: This deviation is acceptable as it is a stronger condition.
 * @note   \li Check performed in step 5.4 (check if \f$|p–q| <= 2^{nlen/2–100}\f$) is performed after q is generated,
 *             it is after testing that q it probably prime. If p and q does not meet this FIPS requirements, a new
 *             prime q number will be generated.
 * @note   \li The pre-check against products of small primes is applied before the steps 4.5 and 5.6 respectively.
 * @note       If an event occurs that \f$d <= 2^{nlen/2}\f$ then only a new q will be generated.
 * \attention  To support all required key lengths, this implementation does not verify that key length meets the FIPS 186-4 criteria
 *              (i.e., no check whether the key size is 2048 or 3072 bits).
 *              User shall ensure that if FIPS 186-4 compliance is claimed, this mode is used to generate keys of 2048 or 3072 bits only.
 * @attention  If the key generation operation returns Error or Fault (through session), the user shall ensure that the generated key is
 *              cleared and not used.
 *
 * @param [out] pKeyGenMode         Pointer to a mode descriptor to be initialized for RSA key pair generation with public exponent input.
 * @param [in]  pE                  Pointer to the input public exponent e. It must be odd values
 *                                  in the range \f$2^{16}<e<2^{256}\f$.
 * @param [in]  eLength             Length of the public exponent e.
 *
 * @return void
 *
 * @pre
 * Before calling this function, sufficient space should be allocated for the key mode descriptor and RSA-specific content,
 * using the macro @ref MCUXCLRSA_KEYGEN_MODE_SIZE.
 *
 * @implements{REQ_788251}
 */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_URL_IN_COMMENTS()
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRsa_KeyGeneration_ModeConstructor)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRsa_KeyGeneration_ModeConstructor(
  mcuxClKey_GenerationDescriptor_t * pKeyGenMode,
  const uint8_t * pE,
  uint32_t eLength
);
/** @} */
/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_MODECONSTRUCTORS_H_ */
