/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024, 2026 NXP                                            */
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
 * @file  mcuxClRsa_KeyTypes.h
 * @brief Definition of supported key types in mcuxClRsa component, see also @ref mcuxClKey component
 */

#ifndef MCUXCLRSA_KEYTYPES_H_
#define MCUXCLRSA_KEYTYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stdint.h>
#include <stdbool.h>

#include <mcuxClKey_Types.h>
#include <mcuxClRsa_Types.h>

#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif


/**********************************************
 * KEY TYPE DEFS
 **********************************************/

/**
 * @defgroup mcuxClRsa_KeyTypes_Descriptors Key Type Descriptors
 * @brief Definition of supported key types in @ref mcuxClRsa component, see also @ref mcuxClKey component
 * @ingroup mcuxClRsa_Descriptors
 * @{
 */

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

/**
 * @defgroup mcuxClRsa_KeyTypes_Public_Structures RSA public key type structures
 * @brief Defines key type structures for RSA public keys of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_1024; ///< Key type structure for RSA public key and key size 1024 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_2048; ///< Key type structure for RSA public key and key size 2048 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_3072; ///< Key type structure for RSA public key and key size 3072 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_4096; ///< Key type structure for RSA public key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_6144; ///< Key type structure for RSA public key and key size 6144 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_Public_8192; ///< Key type structure for RSA public key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_Public_Structures */

/**
 * @defgroup mcuxClRsa_KeyTypes_Public_Pointers RSA public key type pointers
 * @brief Defines key type pointers for public RSA keys of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
/**
 * \implements{REQ_788254,REQ_788255,REQ_788256,REQ_788257}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_Public_1024 = &mcuxClKey_TypeDescriptor_Rsa_Public_1024; ///< Key type pointer for RSA public key and key size 1024 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_Public_2048 = &mcuxClKey_TypeDescriptor_Rsa_Public_2048; ///< Key type pointer for RSA public key and key size 2048 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_Public_3072 = &mcuxClKey_TypeDescriptor_Rsa_Public_3072; ///< Key type pointer for RSA public key and key size 3072 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_Public_4096 = &mcuxClKey_TypeDescriptor_Rsa_Public_4096; ///< Key type pointer for RSA public key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
/**
 * \implements{REQ_788258}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_Public_6144 = &mcuxClKey_TypeDescriptor_Rsa_Public_6144; ///< Key type pointer for RSA public key and key size 6144 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_Public_8192 = &mcuxClKey_TypeDescriptor_Rsa_Public_8192; ///< Key type pointer for RSA public key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_Public_Pointers */

/* TODO CLNS-15273: the condition of defined(MCUXCL_FEATURE_RSA_SWONLY) shall be removed after SIGNATURE_RSA_SIGN or CIPHER_RSA_DECRYPT is enabled for NCCL */

/**
 * @defgroup mcuxClRsa_KeyTypes_PrivatePlain_Structures RSA private plain key type structures
 * @brief Defines key type structures for RSA private plain keys of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_1024; ///< Key type structure for RSA private plain key and key size 1024 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_2048; ///< Key type structure for RSA private plain key and key size 2048 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_3072; ///< Key type structure for RSA private plain key and key size 3072 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_4096; ///< Key type structure for RSA private plain key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_6144; ///< Key type structure for RSA private plain key and key size 6144 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_8192; ///< Key type structure for RSA private plain key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_PrivatePlain_Structures */

/**
 * @defgroup mcuxClRsa_KeyTypes_PrivatePlain_Pointers RSA private plain key type pointers
 * @brief Defines key type pointers for private plain RSA keys of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
/**
 * \implements{REQ_788254,REQ_788255,REQ_788256,REQ_788257}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivatePlain_1024 = &mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_1024; ///< Key type pointer for RSA private plain key and key size 1024 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivatePlain_2048 = &mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_2048; ///< Key type pointer for RSA private plain key and key size 2048 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivatePlain_3072 = &mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_3072; ///< Key type pointer for RSA private plain key and key size 3072 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivatePlain_4096 = &mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_4096; ///< Key type pointer for RSA private plain key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
/**
 * \implements{REQ_788258}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivatePlain_6144 = &mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_6144; ///< Key type pointer for RSA private plain key and key size 6144 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivatePlain_8192 = &mcuxClKey_TypeDescriptor_Rsa_PrivatePlain_8192; ///< Key type pointer for RSA private plain key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_PrivatePlain_Pointers */

/**
 * @defgroup mcuxClRsa_KeyTypes_PrivateCrt_Structures RSA private CRT key type structures
 * @brief Defines key type structures for RSA private CRT keys of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_1024; ///< Key type structure for RSA private CRT key and key size 1024 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_2048; ///< Key type structure for RSA private CRT key and key size 2048 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_3072; ///< Key type structure for RSA private CRT key and key size 3072 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_4096; ///< Key type structure for RSA private CRT key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_6144; ///< Key type structure for RSA private CRT key and key size 6144 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_8192; ///< Key type structure for RSA private CRT key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_PrivateCrt_Structures */

/**
 * @defgroup mcuxClRsa_KeyTypes_PrivateCRT_Pointers RSA private CRT key type pointers
 * @brief Defines key type pointers for private CRT RSA keys of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
/**
 * \implements{REQ_788254,REQ_788255,REQ_788256,REQ_788257,REQ_788260}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_1024 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_1024; ///< Key type pointer for RSA private CRT key and key size 1024 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_2048 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_2048; ///< Key type pointer for RSA private CRT key and key size 2048 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_3072 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_3072; ///< Key type pointer for RSA private CRT key and key size 3072 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_4096 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_4096; ///< Key type pointer for RSA private CRT key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
/**
 * \implements{REQ_788258}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_6144 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_6144; ///< Key type pointer for RSA private CRT key and key size 6144 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_8192 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_8192; ///< Key type pointer for RSA private CRT key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_PrivateCrt_Pointers */

/**
 * @defgroup mcuxClRsa_KeyTypes_PrivateCrt_DFA_Structures RSA private CRT_DFA key type structures with
 * @brief Defines key type structures for RSA private CRT keys with DFA protection enabled of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_1024; ///< Key type structure for RSA private CRT_DFA key and key size 1024 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_2048; ///< Key type structure for RSA private CRT_DFA key and key size 2048 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_3072; ///< Key type structure for RSA private CRT_DFA key and key size 3072 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_4096; ///< Key type structure for RSA private CRT_DFA key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_6144; ///< Key type structure for RSA private CRT_DFA key and key size 6144 bits.
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_8192; ///< Key type structure for RSA private CRT_DFA key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_PrivateCrt_DFA_Structures */

/**
 * @defgroup mcuxClRsa_KeyTypes_PrivateCrt_DFA_Pointers RSA private CRT_DFA key type pointers with
 * @brief Defines key type pointers for RSA private CRT keys with DFA protection enabled of @ref mcuxClRsa, see @ref mcuxClKey.
 * @ingroup mcuxClRsa_KeyTypes_Descriptors
 * @{
 */
/**
 * \implements{REQ_788254,REQ_788255,REQ_788256,REQ_788257,REQ_788260}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_DFA_1024 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_1024; ///< Key type pointer for RSA private CRT_DFA key and key size 1024 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_DFA_2048 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_2048; ///< Key type pointer for RSA private CRT_DFA key and key size 2048 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_DFA_3072 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_3072; ///< Key type pointer for RSA private CRT_DFA key and key size 3072 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_DFA_4096 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_4096; ///< Key type pointer for RSA private CRT_DFA key and key size 4096 bits.
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
/**
 * \implements{REQ_788258}
 */
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_DFA_6144 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_6144; ///< Key type pointer for RSA private CRT_DFA key and key size 6144 bits.
static const mcuxClKey_Type_t mcuxClKey_Type_Rsa_PrivateCRT_DFA_8192 = &mcuxClKey_TypeDescriptor_Rsa_PrivateCRT_DFA_8192; ///< Key type pointer for RSA private CRT_DFA key and key size 8192 bits.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
/**
 * @}
 */ /* mcuxClRsa_KeyTypes_PrivateCrt_DFA_Pointers */


MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
/**
 * @}
 */ /* mcuxClRsa_KeyTypes */


/**********************************************
 * KEY ENCODING DEFS
 **********************************************/

MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by user / customer. Hence, it is declared but never referenced. ")

/**
 * @brief Plain encoding descriptor for RSA private plain keys.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain;
static const mcuxClKey_Encoding_t mcuxClRsa_Encoding_PrivPlainKey_Plain = &mcuxClRsa_EncodingDescriptor_PrivPlainKey_Plain;

/**
 * @brief Plain encoding descriptor for RSA public keys.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClRsa_EncodingDescriptor_PublicKey_Plain;
static const mcuxClKey_Encoding_t mcuxClRsa_Encoding_PublicKey_Plain = &mcuxClRsa_EncodingDescriptor_PublicKey_Plain;

/**
 * @brief Plain encoding descriptor for RSA private CRT keys.
 */
extern const mcuxClKey_EncodingDescriptor_t mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain;
static const mcuxClKey_Encoding_t mcuxClRsa_Encoding_PrivCrtKey_Plain = &mcuxClRsa_EncodingDescriptor_PrivCrtKey_Plain;

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**********************************************
 * MACROS AND DEFINITIONS TO SETUP RSA KEY
 **********************************************/

/**
 * @defgroup mcuxClRsa_KeyData Rsa Key Types
 * @brief Struct to supported key data for @ref mcuxClRsa, see @ref mcuxClKey
 * @ingroup mcuxClRsa_Types
 * @{
 */

/**
 * @brief Structure type for Rsa plain key data.
 */
typedef struct
{
  mcuxClRsa_KeyEntry_t modulus;    ///< Key entry for the modulus
  mcuxClRsa_KeyEntry_t exponent;   ///< Key entry for the exponent - it can be the public or the private exponent, depending on the key type
}mcuxClRsa_KeyData_Plain_t;

/**
 * @brief Structure type for Rsa CRT key data.
 */
typedef struct
{
  mcuxClRsa_KeyEntry_t p;     ///< Key entry for the prime factor P
  mcuxClRsa_KeyEntry_t q;     ///< Key entry for the prime factor Q
  mcuxClRsa_KeyEntry_t qInv;  ///< Key entry for the QInv = (1 / (Q % P))
  mcuxClRsa_KeyEntry_t dp;    ///< Key entry for the exponent DP = D % (P-1)
  mcuxClRsa_KeyEntry_t dq;    ///< Key entry for the exponent DQ = D % (Q-1)
  mcuxClRsa_KeyEntry_t e;     ///< Key entry for the public exponent E - it should be specified for a key type Rsa_PrivateCRT_DFA, and can be ignored otherwise
}mcuxClRsa_KeyData_Crt_t;

// TODO CLNS-9057: remove those definitions
#define MCUXCLRSA_KEYSTRUCT_PLAIN_SIZE (sizeof(mcuxClRsa_KeyData_Plain_t)) ///< Size of mcuxClRsa_KeyData_Plain_t
#define MCUXCLRSA_KEYSTRUCT_CRT_SIZE (sizeof(mcuxClRsa_KeyData_Crt_t)) ///< Size of mcuxClRsa_KeyData_Crt_t

/**
 * @}
 */ /* mcuxClRsa_KeyData */



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_KEYTYPES_H_ */
