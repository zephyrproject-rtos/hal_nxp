/*
 * Copyright 2018-2021 NXP
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

sss_status_t sss_sscp_cipher_init(sss_sscp_symmetric_t *context, uint8_t *iv, size_t ivLen);

sss_status_t sss_sscp_cipher_update(
    sss_sscp_symmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen);

sss_status_t sss_sscp_cipher_finish(
    sss_sscp_symmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen);

sss_status_t sss_sscp_cipher_crypt_ctr(sss_sscp_symmetric_t *context,
                                       const uint8_t *srcData,
                                       uint8_t *destData,
                                       size_t size,
                                       uint8_t *initialCounter,
                                       uint8_t *lastEncryptedCounter,
                                       size_t *szLeft);

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

sss_status_t sss_sscp_aead_init(
    sss_sscp_aead_t *context, uint8_t *nonce, size_t nonceLen, size_t tagLen, size_t aadLen, size_t payloadLen);

sss_status_t sss_sscp_aead_update_aad(sss_sscp_aead_t *context, const uint8_t *aadData, size_t aadDataLen);

sss_status_t sss_sscp_aead_update(
    sss_sscp_aead_t *context, const uint8_t *srcData, size_t srcLen, uint8_t destData, size_t *destLen);

sss_status_t sss_sscp_aead_finish(sss_sscp_aead_t *context,
                                  const uint8_t *srcData,
                                  size_t srcLen,
                                  uint8_t destData,
                                  size_t *destLen,
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

sss_status_t sss_sscp_digest_context_free(sss_sscp_digest_t *context);

/*******************************ASYMETRIC**************************************/
sss_status_t sss_sscp_asymmetric_context_init(sss_sscp_asymmetric_t *context,
                                              sss_sscp_session_t *session,
                                              sss_sscp_object_t *keyObject,
                                              sss_algorithm_t algorithm,
                                              sss_mode_t mode);

sss_status_t sss_sscp_asymmetric_encrypt(
    sss_sscp_asymmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen);

sss_status_t sss_sscp_asymmetric_decrypt(
    sss_sscp_asymmetric_t *context, const uint8_t *srcData, size_t srcLen, uint8_t *destData, size_t *destLen);

sss_status_t sss_sscp_asymmetric_sign_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t *signatureLen);

sss_status_t sss_sscp_asymmetric_verify_digest(
    sss_sscp_asymmetric_t *context, uint8_t *digest, size_t digestLen, uint8_t *signature, size_t signatureLen);

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
                                 sss_sscp_object_t *derivedKeyObject);

sss_status_t sss_sscp_asymmetric_dh_derive_key(sss_sscp_derive_key_t *context,
                                               sss_sscp_object_t *otherPartyKeyObject,
                                               sss_sscp_object_t *derivedKeyObject);

sss_status_t sss_sscp_derive_key_context_free(sss_sscp_derive_key_t *context);
/*********************************MAC******************************************/
sss_status_t sss_sscp_mac_context_init(sss_sscp_mac_t *context,
                                       sss_sscp_session_t *session,
                                       sss_sscp_object_t *keyObject,
                                       sss_algorithm_t algorithm,
                                       sss_mode_t mode);

sss_status_t sss_sscp_mac_one_go(
    sss_sscp_mac_t *context, const uint8_t *message, size_t messageLen, uint8_t *mac, size_t *macLen);

sss_status_t sss_sscp_mac_init(sss_sscp_mac_t *context);

sss_status_t sss_sscp_mac_update(sss_sscp_mac_t *context, const uint8_t *message, size_t messageLen);

sss_status_t sss_sscp_mac_finish(sss_sscp_mac_t *context, uint8_t *mac, size_t *macLen);

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

sss_status_t sss_sscp_key_store_generate_key(sss_sscp_key_store_t *keyStore,
                                             sss_sscp_object_t *keyObject,
                                             size_t keyBitLen,
                                             void *options);

sss_status_t sss_sscp_key_store_open_key(sss_sscp_key_store_t *keyStore, sss_sscp_object_t *keyObject);
sss_status_t sss_sscp_key_store_open_internal_key(sss_sscp_key_store_t *keyStore, sss_internal_keyID_t keyID);
sss_status_t sss_sscp_key_store_erase_key(sss_sscp_key_store_t *keyStore, sss_sscp_object_t *keyObject);
sss_status_t sss_sscp_key_store_erase_all(sss_sscp_key_store_t *keyStore);
sss_status_t sss_sscp_key_store_get_property(sss_sscp_key_store_t *keyStore,
                                             sss_sscp_key_store_property_t propertyId,
                                             uint32_t *property);

sss_status_t sss_sscp_key_store_free(sss_sscp_key_store_t *keyStore);
/******************************KEYOBJECT***************************************/
sss_status_t sss_sscp_key_object_init_internal(sss_sscp_object_t *keyObject, sss_sscp_key_store_t *keyStore);

sss_status_t sss_sscp_key_object_init(sss_sscp_object_t *keyObject, sss_sscp_key_store_t *keyStore);

sss_status_t sss_sscp_key_object_set_eccgfp_group(sss_sscp_object_t *keyObject, sss_eccgfp_group_t *group);

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
