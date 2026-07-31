/*
 * Copyright 2018-2021, 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSS_SSCP_H
#define FSL_SSS_SSCP_H

// #include <stddef.h>
#include <stdint.h>
#include "fsl_sscp.h"
#include "fsl_sss_api.h"

#if !defined(SSS_SSCP_CONFIG_FILE)
#include "fsl_sss_sscp_config.h"
#else
#include SSS_SSCP_CONFIG_FILE
#endif

typedef struct
{
    /*! Indicates which security subsystem is selected to be used. */
    sss_type_t subsystem;

    /*! Implementation specific part */
    sscp_context_t *sscp;
    uint32_t ctx;
} sss_sscp_session_t;

typedef struct
{
    /*! Virtual connection between application (user context) and specific
     * security subsystem and function thereof. */
    sss_sscp_session_t *session;
    /*! Implementation specific part */
    uint32_t keyStoreId;
    struct
    {
        uint8_t data[SSS_SSCP_KEY_STORE_CONTEXT_SIZE];
    } context;
    uint32_t ctx;
} sss_sscp_key_store_t;

typedef struct
{
    /*! key store holding the data and other properties */
    sss_sscp_key_store_t *keyStore;

    uint32_t objectType; /*! TODO define object types */
    uint32_t objectKeyCipher;
    /*! Application specific key identifier. The keyId is kept in the key store along with the key data and other
     * properties. */
    uint32_t keyId;
    /*! Used only for ECC key types, to specify the elliptic curve related to the key. */
    sss_eccgfp_group_t *eccgfpGroup;
    /*! Implementation specific part */
    struct
    {
        uint8_t data[SSS_SSCP_KEY_OBJECT_CONTEXT_SIZE];
    } context;
    uint32_t ctx;
} sss_sscp_object_t;

/*! @brief ::_sss_symmetric with SSCP specific information */
typedef struct
{
    /*! Virtual connection between application (user context) and
                specific security subsystem  and function thereof. */
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject; /*! Reference to key and it's properties. */
    sss_algorithm_t algorithm;    /*!  */
    sss_mode_t mode;              /*!  */

    /*! Implementation specific part */
    struct
    {
        uint8_t data[SSS_SSCP_SYMMETRIC_CONTEXT_SIZE];
    } context;
    uint32_t ctx;
} sss_sscp_symmetric_t;

typedef struct
{
    /*! Virtual connection between application (user context) and specific
     * security subsystem and function thereof. */
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject; /*! Reference to key and it's properties. */
    sss_algorithm_t algorithm;    /*!  */
    sss_mode_t mode;              /*!  */

    /*! Implementation specific part */
    struct
    {
        uint8_t data[SSS_SSCP_AEAD_CONTEXT_SIZE];
    } context;
    uint32_t ctx;
} sss_sscp_aead_t;

typedef struct
{
    /*! Virtual connection between application (user context) and specific security subsystem and function thereof. */
    sss_sscp_session_t *session;
    sss_algorithm_t algorithm; /*!  */
    sss_mode_t mode;           /*!  */
    /*! Full digest length per algorithm definition. This field is initialized along with algorithm. */
    size_t digestFullLen;
    /*! Implementation specific part */
    struct
    {
        uint8_t data[SSS_SSCP_DIGEST_CONTEXT_SIZE];
    } context;
    uint32_t ctx;
} sss_sscp_digest_t;

typedef struct
{
    /*! Virtual connection between application (user context) and specific
     * security subsystem and function thereof. */
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject; /*! Reference to key and it's properties. */
    sss_algorithm_t algorithm;    /*!  */
    sss_mode_t mode;              /*!  */

    /*! Implementation specific part */
    uint32_t ctx;
    struct
    {
        uint8_t data[SSS_SSCP_MAC_CONTEXT_SIZE];
    } context;
} sss_sscp_mac_t;

typedef struct
{
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject;
    sss_algorithm_t algorithm; /*!  */
    sss_mode_t mode;           /*!  */
    size_t signatureFullLen;

    /*! Implementation specific part */
    uint32_t ctx;
} sss_sscp_asymmetric_t;

typedef struct
{
    sss_sscp_session_t *session;
    uint32_t tunnelType;

    /*! Implementation specific part */
    uint32_t ctx;
    uint8_t *buffer;
    size_t bufferSize;
} sss_sscp_tunnel_t;

typedef struct
{
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject;
    sss_algorithm_t algorithm; /*!  */
    sss_mode_t mode;           /*!  */

    /*! Implementation specific part */
    uint32_t ctx;
} sss_sscp_derive_key_t;

typedef struct
{
    sss_sscp_session_t *session;
    uint32_t rngTypeSpecifier;
    /*! Implementation specific part */
} sss_sscp_rng_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif
sss_status_t sss_sscp_open_session(sss_sscp_session_t *session,
                                   uint32_t sessionId,
                                   sss_type_t subsystem,
                                   sscp_context_t *sscpctx);

sss_status_t sss_sscp_close_session(sss_sscp_session_t *session);

/*******************************SYMETRIC***************************************/

sss_status_t sss_sscp_symmetric_context_init(sss_sscp_symmetric_t *context,
                                             sss_sscp_session_t *session,
                                             sss_sscp_object_t *keyObject,
                                             sss_algorithm_t algorithm,
                                             sss_mode_t mode);

sss_status_t sss_sscp_cipher_one_go(sss_sscp_symmetric_t *context,
                                    uint8_t *iv,
                                    size_t ivLen,
                                    const uint8_t *srcData,
                                    uint8_t *destData,
                                    size_t dataLen);

sss_status_t sss_sscp_symmetric_context_free(sss_sscp_symmetric_t *context);

/**********************************AEAD****************************************/

sss_status_t sss_sscp_aead_context_init(sss_sscp_aead_t *context,
                                        sss_sscp_session_t *session,
                                        sss_sscp_object_t *keyObject,
                                        sss_algorithm_t algorithm,
                                        sss_mode_t mode);

sss_status_t sss_sscp_aead_one_go(sss_sscp_aead_t *context,
                                  const uint8_t *srcData,
                                  uint8_t *destData,
                                  size_t size,
                                  uint8_t *nonce,
                                  size_t nonceLen,
                                  const uint8_t *aad,
                                  size_t aadLen,
                                  uint8_t *tag,
                                  size_t *tagLen);

sss_status_t sss_sscp_aead_context_free(sss_sscp_aead_t *context);

/********************************DIGEST****************************************/

sss_status_t sss_sscp_digest_context_init(sss_sscp_digest_t *context,
                                          sss_sscp_session_t *session,
                                          sss_algorithm_t algorithm,
                                          sss_mode_t mode);

/*! @copydoc sss_digest_one_go */
sss_status_t sss_sscp_digest_one_go(
    sss_sscp_digest_t *context, const uint8_t *message, size_t messageLen, uint8_t *digest, size_t *digestLen);

sss_status_t sss_sscp_digest_init(sss_sscp_digest_t *context);

sss_status_t sss_sscp_digest_update(sss_sscp_digest_t *context, uint8_t *message, size_t messageLen);

sss_status_t sss_sscp_digest_finish(sss_sscp_digest_t *context, uint8_t *digest, size_t *digestLen);

#if defined(ELE_FEATURE_DIGEST_CLONE) && (ELE_FEATURE_DIGEST_CLONE == 1)
sss_status_t sss_sscp_digest_clone(sss_sscp_digest_t *context_src, sss_sscp_digest_t *context_dst);
#endif /* ELE_FEATURE_DIGEST_CLONE */

#if defined(ELE_FEATURE_DIGEST_IMPORT) && (ELE_FEATURE_DIGEST_IMPORT == 1)
sss_status_t sss_sscp_digest_import(sss_sscp_digest_t *context_dst,
                                    uint8_t *digest_context_blob,
                                    size_t digest_context_blob_size);
#endif /* ELE_FEATURE_DIGEST_IMPORT */

#if defined(ELE_FEATURE_DIGEST_EXPORT) && (ELE_FEATURE_DIGEST_EXPORT == 1)
sss_status_t sss_sscp_digest_export(sss_sscp_digest_t *context_src,
                                    uint8_t *digest_context_blob,
                                    size_t *digest_context_blob_size);
#endif /* ELE_FEATURE_DIGEST_EXPORT */

sss_status_t sss_sscp_digest_context_free(sss_sscp_digest_t *context);

/*******************************ASYMETRIC**************************************/
sss_status_t sss_sscp_asymmetric_context_init(sss_sscp_asymmetric_t *context,
                                              sss_sscp_session_t *session,
                                              sss_sscp_object_t *keyObject,
                                              sss_algorithm_t algorithm,
                                              sss_mode_t mode);

sss_status_t sss_sscp_asymmetric_sign_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t *signatureLen);

/*!
 * @brief Asymmetric sign operation on digest or message using PQC algorithm
 *
 * @param[in] context          Asymmetric context.
 * @param[in] input            Input digest (with ML-DSA Pre-Hash) or
 *                             message (with ML-DSA Pure) buffer.
 * @param[in] inputLen         Length of digest (with ML-DSA Pre-Hash) or
 *                             message (with ML-DSA Pure).
 * @param[out] signature       Output signature buffer.
 * @param[in,out] signatureLen Size of the output signature buffer as input,
 *                             length of the generated signature as output.
 * @param[in] userCtx          User context buffer. May be NULL.
 * @param[in] userCtxLen       Length of user context. May be 0.
 * @param[in] preHashAlg       Pre-hashing algorithm. Supported values are
 *                             all of SHA3 (kAlgorithm_SSS_SHA3_256, etc.),
 *                             SHAKE256 (kAlgorithm_SSS_SHAKE256), and
 *                             SHAKE128 (kAlgorithm_SSS_SHAKE128).
 *                             For ML-DSA Pure, use kAlgorithm_SSS_NoPreHashing.
 * @param[out] workArea        Work area buffer for intermediate computations.
 *                             This MUST be provided for ML-DSA-87, its
 *                             size MUST be at least
 *                             ELE_MLDSA_WORK_AREA_BUFFER_SIZE Bytes, and the
 *                             buffer MUST be word-aligned (4-byte alignment).
 *                             For other ML-DSA variants, this may be NULL, but
 *                             if provided, word-alignment is still required.
 * @param[in] workAreaLen      Length of work area buffer.
 *
 * @return Status code of the operation.
 */
sss_status_t sss_sscp_asymmetric_sign_pqc(
    sss_sscp_asymmetric_t *context, uint8_t *input, size_t inputLen,
    uint8_t *signature, size_t *signatureLen, uint8_t *userCtx, size_t userCtxLen,
    sss_algorithm_t preHashAlg, uint8_t *workArea, size_t workAreaLen);

sss_status_t sss_sscp_asymmetric_verify_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t signatureLen);

/*!
 * @brief Asymmetric verify operation on digest or message using PQC algorithm
 *
 * @param[in] context      Asymmetric context.
 * @param[in] input        Input digest (with ML-DSA Pre-Hash) or
 *                         message (with ML-DSA Pure) buffer.
 * @param[in] inputLen     Length of digest (with ML-DSA Pre-Hash) or
 *                         message (with ML-DSA Pure).
 * @param[in] signature    The signature to verify.
 * @param[in] signatureLen Length of the signature.
 * @param[in] userCtx      User context buffer. May be NULL.
 * @param[in] userCtxLen   Length of user context. May be 0.
 * @param[in] preHashAlg   Pre-hashing algorithm. Supported values are
 *                         all of SHA3 (kAlgorithm_SSS_SHA3_256, etc.),
 *                         SHAKE256 (kAlgorithm_SSS_SHAKE256), and
 *                         SHAKE128 (kAlgorithm_SSS_SHAKE128).
 *                         For ML-DSA Pure, use kAlgorithm_SSS_NoPreHashing.
 *
 * @return Status code of the operation.
 */
sss_status_t sss_sscp_asymmetric_verify_pqc(
    sss_sscp_asymmetric_t *context, uint8_t *input, size_t inputLen,
    uint8_t *signature, size_t signatureLen, uint8_t *userCtx,
    size_t userCtxLen, sss_algorithm_t preHashAlg);

sss_status_t sss_sscp_asymmetric_context_free(sss_sscp_asymmetric_t *context);

/******************************DERIVE KEY**************************************/
sss_status_t sss_sscp_derive_key_context_init(sss_sscp_derive_key_t *context,
                                              sss_sscp_session_t *session,
                                              sss_sscp_object_t *keyObject,
                                              sss_algorithm_t algorithm,
                                              sss_mode_t mode);

sss_status_t sss_sscp_derive_key(sss_sscp_derive_key_t *context,
                                 const uint8_t *saltData,
                                 size_t saltLen,
                                 sss_sscp_object_t *derivedKeyObject,
                                 size_t derivedKeyBitLength);

/*!
 * @brief Derive multiple keys with HKDF Expand.
 *
 * This API provides functionality for the HKDF Expand operation to derive
 * up to six keys in a single call, improving efficiency for multi-key
 * derivation scenarios.
 *
 * The derivedKeyObject parameters can be NULL if the corresponding key is not
 * needed. At least one key object must be provided. If multiple keys are
 * derived, they will all have the same bit length and the key object must be
 * provided in-order (e.g. if deriving two keys, derivedKeyObject1 and
 * derivedKeyObject2 must be provided).
 *
 * @param[in] context               Derive key context.
 * @param[in] saltData              Input salt data buffer.
 * @param[in] saltLen               Length of the salt data.
 * @param[in] derivedKeyObject1     Output key object 1.
 * @param[in] derivedKeyObject2     Output key object 2.
 * @param[in] derivedKeyObject3     Output key object 3.
 * @param[in] derivedKeyObject4     Output key object 4.
 * @param[in] derivedKeyObject5     Output key object 5.
 * @param[in] derivedKeyObject6     Output key object 6.
 * @param[in] derivedKeyBitLength   The bit length of the derived keys. All keys
 *                                  will have the same length. Available options
 *                                  are 128 or 256 bits.
 * @param[in] keyCount              The number of keys to derive. Valid range is
 *                                  1 to 6.
 *
 * @return Status code of the operation.
 */
sss_status_t sss_sscp_derive_key_multi(sss_sscp_derive_key_t *context,
                                       const uint8_t *saltData,
                                       size_t saltLen,
                                       sss_sscp_object_t *derivedKeyObject1,
                                       sss_sscp_object_t *derivedKeyObject2,
                                       sss_sscp_object_t *derivedKeyObject3,
                                       sss_sscp_object_t *derivedKeyObject4,
                                       sss_sscp_object_t *derivedKeyObject5,
                                       sss_sscp_object_t *derivedKeyObject6,
                                       size_t derivedKeyBitLength,
                                       uint32_t keyCount);

/*!
 * @brief Encapsulate or decapsulate a shared secret using the ML-KEM algorithm.
 *
 * @param[in] context           Derive key context.
 * @param[in,out] cipherText    The meaning of this parameter changes depending
 *                              on the ML-KEM mode.
 *                              On Encapsulation: output cipher text buffer.
 *                              On Decapsulation: input cipher text buffer.
 * @param[in,out] cipherTextLen The meaning of this parameter changes depending
 *                              on the ML-KEM mode.
 *                              On Encapsulation: it is an [in/out] parameter
 *                              with size of the output cipher text buffer
 *                              as input, length of the generated cipher
 *                              text as output.
 *                              On Decapsulation: it is an [in] parameter with
 *                              the length of the input cipher text.
 * @param[out] sharedSecret     Derived shared secret key object.
 * @param[in] mode              Operation mode. Accepted values are
 *                              kMode_SSS_MlkemDecapsulate and
 *                              kMode_SSS_MlkemEncapsulate.
 *
 * @return Status code of the operation.
 */
sss_status_t sss_sscp_asymmetric_mlkem_derive_key(sss_sscp_derive_key_t *context,
                                                  uint8_t *cipherText,
                                                  size_t *cipherTextLen,
                                                  sss_sscp_object_t *sharedSecret,
                                                  sss_mode_t mode);

sss_status_t sss_sscp_asymmetric_dh_derive_key(sss_sscp_derive_key_t *context,
                                               sss_sscp_object_t *otherPartyKeyObject,
                                               sss_sscp_object_t *derivedKeyObject);

#if defined(ELE_FEATURE_SPAKE2PLUS)
sss_status_t sss_sscp_asymmetric_spake2plus_derive_key(sss_sscp_derive_key_t *context,
                                                       sss_sscp_object_t *pA,
                                                       sss_sscp_object_t *w0,
                                                       sss_sscp_object_t *L,
                                                       uint8_t *contextData,
                                                       size_t contextDataLength,
                                                       sss_sscp_object_t *pB,
                                                       sss_sscp_object_t *cA,
                                                       sss_sscp_object_t *cB,
                                                       sss_sscp_object_t *Ke);

/*!
 * @brief Derive keys using the CCC specification of SPAKE2+ protocol.
 *
 * This function implements the CCC SPAKE2+ key derivation process, generating
 * multiple session keys based on provided parameters and context data.
 *
 * NOTE: On NBU core, please make sure that stack is placed in shared
 *       memory, so that ELE can access it. In this API, the output key objects
 *       are handled as a memory reference.
 *
 * @param[in] context            ELE context for the SPAKE2+ operation.
 * @param[in] pA                 Public element A (also noted as X).
 * @param[in] w0                 First password-based scalar.
 * @param[in] L                  Precomputed element L.
 * @param[in] contextData        Additional context data for key derivation.
 * @param[in] contextDataLength  Length of the context data.
 * @param[in] pB                 Public element B (also noted as Y).
 * @param[in] cA                 Confirmation value for A (in CCC noted as M1).
 * @param[in] cB                 Confirmation value for B (in CCC noted as M2).
 * @param[out] Ke                Derived encryption key (in CCC noted as SK).
 * @param[out] k1                Derived key 1 (in CCC noted as Kenc).
 * @param[out] k2                Derived key 2 (in CCC noted as Kmac).
 * @param[out] k3                Derived key 3 (in CCC noted as Krmac).
 * @param[out] k4                Derived key 4 (in CCC noted as LONG_TERM_SHARED_SECRET).
 * @param[out] k5                Derived key 5 (in CCC noted as Kble_intro).
 * @param[out] k6                Derived key 6 (in CCC noted as Kble_oob_master).
 *
 * @return Status code of the operation.
 */
sss_status_t sss_sscp_asymmetric_spake2plus_derive_key_ccc(sss_sscp_derive_key_t *context,
                                                           sss_sscp_object_t *pA,
                                                           sss_sscp_object_t *w0,
                                                           sss_sscp_object_t *L,
                                                           uint8_t *contextData,
                                                           size_t contextDataLength,
                                                           sss_sscp_object_t *pB,
                                                           sss_sscp_object_t *cA,
                                                           sss_sscp_object_t *cB,
                                                           sss_sscp_object_t *Ke,
                                                           sss_sscp_object_t *k1,
                                                           sss_sscp_object_t *k2,
                                                           sss_sscp_object_t *k3,
                                                           sss_sscp_object_t *k4,
                                                           sss_sscp_object_t *k5,
                                                           sss_sscp_object_t *k6);
#endif /* ELE_FEATURE_SPAKE2PLUS */

/*!
 * @brief Apply an arithmetic operation to elliptic curve points.
 *
 * The function provides an API for applying the ADD, SUB, and MULT arithmetic
 * operations to elliptic curve points (or scalar and point for MULT operation)
 * represented as key objects; points are represented by EC public keys,
 * while scalars are EC private keys.
 *
 * The order of operands matters for some operations:
 *  - MULT key object order MUST be: pIn1 as the scalar, pIn2 as the point to
 *    multiply,
 *  - SUB key object order is (pIn1 - pIn2),
 *  - ADD key object order does not matter.
 *
 * @note Curves supported by this API are limited to the Weierstrass curve
 *       family, which includes NIST-P and Brainpool-P curves of all sizes
 *       supported by ELE S200.
 *
 * @note The MULT operation may be used to check if a given point lies on
 *       a given curve.
 *
 * @note Support for this functionality is enabled by ELE S200 loadable firmware
 *       version KW47_A2_1_SDKFW4_0 and onwards, for the KW47 or MCXW72 devices.
 *
 * @param[in] session   An open session context.
 * @param[in] pIn1      First input operand (this must be a scalar for MULT,
 *                      and a point for ADD/SUB).
 * @param[in] pIn2      Second input operand (point ADD/SUB/MULT).
 * @param[out] pOut     Output operand (resulting point).
 * @param[in] operation The arithmetic operation to perform.
 *
 * @return Status code of the operation.
 */
sss_status_t sss_sscp_asymmetric_ec_point_operate(sss_sscp_session_t *session,
                                                  sss_sscp_object_t *pIn1,
                                                  sss_sscp_object_t *pIn2,
                                                  sss_sscp_object_t *pOut,
                                                  sss_sscp_ecPointOp_t operation);

sss_status_t sss_sscp_derive_key_context_free(sss_sscp_derive_key_t *context);
/*********************************MAC******************************************/
sss_status_t sss_sscp_mac_context_init(sss_sscp_mac_t *context,
                                       sss_sscp_session_t *session,
                                       sss_sscp_object_t *keyObject,
                                       sss_algorithm_t algorithm,
                                       sss_mode_t mode);

sss_status_t sss_sscp_mac_one_go(
    sss_sscp_mac_t *context, const uint8_t *message, size_t messageLen, uint8_t *mac, size_t *macLen);

#if defined(ELE_FEATURE_MAC_MULTIPART)
sss_status_t sss_sscp_mac_init(sss_sscp_mac_t *context);

sss_status_t sss_sscp_mac_update(sss_sscp_mac_t *context, const uint8_t *message, size_t messageLen);

sss_status_t sss_sscp_mac_finish(sss_sscp_mac_t *context, uint8_t *mac, size_t *macLen);
#endif /* ELE_FEATURE_MAC_MULTIPART */

#if defined(ELE_FEATURE_MAC_IMPORT) && (ELE_FEATURE_MAC_IMPORT == 1)
sss_status_t sss_sscp_mac_import(sss_sscp_mac_t *context_dst, uint8_t *mac_context_blob, size_t mac_context_blob_size);
#endif /* ELE_FEATURE_MAC_IMPORT */

#if defined(ELE_FEATURE_MAC_EXPORT) && (ELE_FEATURE_MAC_EXPORT == 1)
sss_status_t sss_sscp_mac_export(sss_sscp_mac_t *context_src, uint8_t *mac_context_blob, size_t *mac_context_blob_size);
#endif /* ELE_FEATURE_MAC_EXPORT */

sss_status_t sss_sscp_mac_context_free(sss_sscp_mac_t *context);

/*******************************KEYSTORE***************************************/
sss_status_t sss_sscp_key_store_init(sss_sscp_key_store_t *keyStore, sss_sscp_session_t *session);

sss_status_t sss_sscp_key_store_set_key(sss_sscp_key_store_t *keyStore,
                                        sss_sscp_object_t *keyObject,
                                        const uint8_t *data,
                                        size_t dataLen,
                                        uint32_t keyBitLen,
                                        sss_key_part_t keyPart);

sss_status_t sss_sscp_key_store_get_key(sss_sscp_key_store_t *keyStore,
                                        sss_sscp_object_t *keyObject,
                                        uint8_t *data,
                                        size_t *dataLen,
                                        size_t *pKeyBitLen,
                                        sss_key_part_t keyPart);

sss_status_t sss_sscp_key_store_export_key(sss_sscp_key_store_t *keyStore,
                                           sss_sscp_object_t *keyObject,
                                           uint8_t *data,
                                           size_t *dataLen,
                                           sss_sscp_blob_type_t blobType);

sss_status_t sss_sscp_key_store_import_key(sss_sscp_key_store_t *keyStore,
                                           sss_sscp_object_t *keyObject,
                                           const uint8_t *data,
                                           size_t dataLen,
                                           uint32_t keyBitLen,
                                           sss_sscp_blob_type_t blobType);

sss_status_t sss_sscp_key_store_import_key_ext(sss_sscp_key_store_t *keyStore,
                                               sss_sscp_object_t *keyObjectOut,
                                               const uint8_t *data,
                                               size_t dataLen,
                                               uint32_t keyBitLen,
                                               sss_sscp_blob_type_t blobType,
                                               sss_sscp_object_t *keyObjectIn);

sss_status_t sss_sscp_key_store_generate_key(sss_sscp_key_store_t *keyStore,
                                             sss_sscp_object_t *keyObject,
                                             size_t keyBitLen,
                                             void *options);

sss_status_t sss_sscp_key_store_open_key(sss_sscp_key_store_t *keyStore,
                                         sss_internal_keyID_t keyID,
                                         sss_sscp_object_t *keyObject);
sss_status_t sss_sscp_key_store_open_internal_key(sss_sscp_key_store_t *keyStore, sss_internal_keyID_t keyID);
sss_status_t sss_sscp_key_store_erase_key(sss_sscp_key_store_t *keyStore, sss_sscp_object_t *keyObject);
sss_status_t sss_sscp_key_store_get_property(sss_sscp_key_store_t *keyStore,
                                             sss_sscp_key_store_property_t propertyId,
                                             uint32_t *property);

sss_status_t sss_sscp_key_store_free(sss_sscp_key_store_t *keyStore);
/******************************KEYOBJECT***************************************/
sss_status_t sss_sscp_key_object_init_internal(sss_sscp_object_t *keyObject, sss_sscp_key_store_t *keyStore);

sss_status_t sss_sscp_key_object_init(sss_sscp_object_t *keyObject, sss_sscp_key_store_t *keyStore);

sss_status_t sss_sscp_key_object_set_properties(sss_sscp_object_t *keyObject, uint32_t options);

sss_status_t sss_sscp_key_object_get_properties(sss_sscp_object_t *keyObject, uint32_t *options);

sss_status_t sss_sscp_key_object_allocate_handle(sss_sscp_object_t *keyObject,
                                                 uint32_t keyId,
                                                 sss_key_part_t keyPart,
                                                 sss_cipher_type_t cipherType,
                                                 uint32_t keyByteLenMax,
                                                 uint32_t options);

sss_status_t sss_sscp_key_object_get_handle(sss_sscp_object_t *keyObject, uint32_t keyId);
#define SSS_SSCP_KEY_OBJECT_FREE_STATIC  (0x0u)
#define SSS_SSCP_KEY_OBJECT_FREE_DYNAMIC (0x1u)
sss_status_t sss_sscp_key_object_free(sss_sscp_object_t *keyObject, uint32_t options);

/*******************************TUNNEL*****************************************/
sss_status_t sss_sscp_tunnel_context_init(sss_sscp_tunnel_t *context, sss_sscp_session_t *session, uint32_t tunnelType);

sss_status_t sss_sscp_tunnel(sss_sscp_tunnel_t *context, uint8_t *data, size_t dataLen, uint32_t *resultState);

sss_status_t sss_sscp_tunnel_context_free(sss_sscp_tunnel_t *context);
/*********************************RNG******************************************/
sss_status_t sss_sscp_rng_context_init(sss_sscp_session_t *session, sss_sscp_rng_t *context, uint32_t rngTypeSpecifier);

sss_status_t sss_sscp_rng_get_random(sss_sscp_rng_t *context, uint8_t *random_data, size_t dataLen);

sss_status_t sss_sscp_rng_free(sss_sscp_rng_t *context);

#if defined(__cplusplus)
}
#endif

#endif /* FSL_SSS_SSCP_H */
