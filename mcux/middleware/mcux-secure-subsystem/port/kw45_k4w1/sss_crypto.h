/*! *********************************************************************************
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */

#ifndef __SSS_CRYPTO_H__
#define __SSS_CRYPTO_H__

#include "fsl_common.h"
#include "fsl_sscp_mu.h"
#include "fsl_sss_sscp.h"

#define SSS_HIGH_QUALITY_RNG 1

#ifndef RAISE_ERROR
#define RAISE_ERROR(x, code) \
    {                        \
        (x) = (code);        \
        break;               \
    }
#endif

#define SSS_MAX_SUBSYTEM_WAIT (0xFFFFFFFFu)

#ifndef SSS_CRYPTOHW_INITIALIZED
#define SSS_CRYPTOHW_INITIALIZED (0xF0F0F0F0u)
#endif
#ifndef SSS_CRYPTOHW_NONINITIALIZED
#define SSS_CRYPTOHW_NONINITIALIZED ~SSS_CRYPTOHW_INITIALIZED
#endif
#define SSS_SUBSYSTEM (kType_SSS_Ele200)

#define SSS_KEYPROP_OPERATION_NONE (0x00000000u)
#define SSS_KEYPROP_OPERATION_AES  (0x00000001u)
#define SSS_KEYPROP_OPERATION_MAC  (0x00000002u)
#define SSS_KEYPROP_OPERATION_AEAD (0x00000004u)
#define SSS_KEYPROP_OPERATION_ASYM (0x00000008u)
#define SSS_KEYPROP_OPERATION_KDF  (0x00000010u)
#define SSS_KEYPROP_NO_PLAIN_READ  (0x00008000u)

#define ECP256_COORDINATE_BITLEN 256u
#define ECP256_COORDINATE_LEN    (ECP256_COORDINATE_BITLEN >> 3)
#define ECP256_COORDINATE_WLEN   ((ECP256_COORDINATE_LEN) / 4U)

/* HMAC SHA256 section */
#define MD_HMAC_SHA256_SIZE       32u
#define MD_HMAC_SHA256_BLOCK_SIZE 64u

extern sss_sscp_key_store_t g_keyStore;
extern sss_sscp_session_t g_sssSession;
extern sscp_context_t g_sscpContext;

/* AES related section */

typedef struct aes_context_t
{
    sss_sscp_object_t sssKey;
    sss_sscp_symmetric_t cipher_ctx;
} aes_context_t;

typedef struct cmac_aes_context_t
{
    sss_sscp_object_t sssKey;
    sss_sscp_mac_t sscp_mac;
    bool sscp_mac_was_set;

} cmac_aes_context_t;

/**
 * \brief          The SHA-256 context structure.
 *
 *                 The structure is used both for SHA-256 and for SHA-224
 *                 checksum calculations. The choice between these two is
 *                 made in the call to mbedtls_sha256_starts_ret().
 */
typedef struct sss_sha256_context
{
    sss_sscp_digest_t ctx;
} sss_sha256_context_t;

typedef struct sss_ccm_context_t
{
    sss_sscp_object_t key;

    sss_sscp_aead_t aead_ctx;

} sss_ccm_context_t;

typedef struct sss_hmac_context_t
{
    unsigned char ipad[MD_HMAC_SHA256_BLOCK_SIZE];
    unsigned char opad[MD_HMAC_SHA256_BLOCK_SIZE];
    unsigned char tmp[MD_HMAC_SHA256_SIZE];
} sss_hmac_context_t;

typedef struct sss_hmac_sha256_context_s
{
    sss_sha256_context_t md_ctx;
    sss_hmac_context_t hmac_ctx;

} sss_hmac_sha256_context_t;

typedef struct sss_ecp256_context_t
{
    uint32_t PrivateKey[ECP256_COORDINATE_WLEN];        /*!< The private key : RNG output */
    uint32_t OwnPublicKey[2U * ECP256_COORDINATE_WLEN]; /*! Own Public computed from PrivateKey */
    sss_session_t session;
    sss_sscp_key_store_t ks;
    uint32_t keyId;
    sss_sscp_object_t OwnKey; /*! Own Key object reference */
} sss_ecp256_context_t;

typedef struct sss_ecdh_p256_context_t
{
    sss_ecp256_context_t *ecdh_key_pair;
    uint32_t Qp[2U * ECP256_COORDINATE_WLEN]; /*!< The value of the public key of the peer. */
    uint32_t z[2U * ECP256_COORDINATE_WLEN];  /*!< The shared secret is the X  coordinate of the DH Key   */

    sss_sscp_object_t peerPublicKey;
    sss_sscp_object_t sharedSecret;
    bool keepSharedSecret;
} sss_ecdh_context_t;

#ifdef __cplusplus
extern "C" {
#endif

status_t CRYPTO_InitHardware(void);
status_t CRYPTO_ReinitHardware(void);

void CRYPTO_DeinitHardware(void);

void CRYPTO_ELEMU_reset(void);

status_t SSS_aes_cmac_starts(cmac_aes_context_t *ctx, const unsigned char *key, size_t key_bytelen);

#ifdef SSS_CMAC_UPDATE_SUPPORTED

status_t SSS_aes_cmac_update(cmac_aes_context_t *ctx, const unsigned char *input, size_t ilen);

status_t SSS_aes_cmac_finish(cmac_aes_context_t *ctx, unsigned char *output);

#endif /* SSS_CMAC_UPDATE_SUPPORTED */

status_t SSS_aes_cmac(cmac_aes_context_t *pCtx,
                      const unsigned char *key,
                      size_t keylen,
                      const unsigned char *input,
                      size_t ilen,
                      unsigned char *output);

status_t SSS_aes_cmac_prf_128(cmac_aes_context_t *pCtx,
                              const unsigned char *key,
                              size_t key_len,
                              const unsigned char *input,
                              size_t in_len,
                              unsigned char output[16]);

status_t SSS_set_aes_key_cmac(cmac_aes_context_t *pCtx, const unsigned char *key, size_t key_bytelen);

void SSS_aes_cmac_free(cmac_aes_context_t *ctx);

status_t SSS_set_aes_key(aes_context_t *ctx, const unsigned char *key, const size_t key_byte_len);

status_t SSS_aes_init(aes_context_t *ctx, const unsigned char *key, size_t keybits);

status_t SSS_aes_operation(aes_context_t *ctx,
                           const unsigned char *input,
                           size_t inputLen,
                           unsigned char *iv,
                           const unsigned char *key,
                           size_t key_bitlen,
                           unsigned char *output,
                           bool encrypt_nDecrypt,
                           sss_algorithm_t algo);

status_t SSS_aes128_CTR_operation(aes_context_t *ctx,
                                  const unsigned char *input,
                                  size_t inputLen,
                                  unsigned char *initialCounter,
                                  const unsigned char *key,
                                  unsigned char *output,
                                  bool encrypt_nDecrypt,
                                  unsigned char *stream_block,
                                  size_t *offset_sz_left);

/* CMAC related section */

/* CCM section */

status_t SSS_ccm_setkey(sss_ccm_context_t *ctx, const unsigned char *key, unsigned int keybits);

void SSS_ccm_free(sss_ccm_context_t *ctx);

status_t SSS_ccm_encrypt_and_tag(sss_ccm_context_t *ctx,
                                 size_t length,
                                 const unsigned char *iv,
                                 size_t iv_len,
                                 const unsigned char *add,
                                 size_t add_len,
                                 const unsigned char *input,
                                 unsigned char *output,
                                 unsigned char *tag,
                                 size_t tag_len);

status_t SSS_ccm_auth_decrypt(sss_ccm_context_t *ctx,
                              size_t length,
                              const unsigned char *iv,
                              size_t iv_len,
                              const unsigned char *add,
                              size_t add_len,
                              const unsigned char *input,
                              unsigned char *output,
                              const unsigned char *tag,
                              size_t tag_len);

/* SHA256 Digest section */

void SSS_sha256_init(sss_sha256_context_t *p_ctx);
void SSS_sha256_free(sss_sha256_context_t *p_ctx);
void SSS_sha256_clone(sss_sha256_context_t *dst, const sss_sha256_context_t *src);

/* The output of SHA224 and SHA256 is similar in size so the codeis shared */
status_t SSS_sha256_ret(const unsigned char *input, size_t ilen, unsigned char output[32], bool is_sha224);

status_t SSS_sha256_finish_ret(sss_sha256_context_t *ctx, unsigned char output[32]);

status_t SSS_sha256_update_ret(sss_sha256_context_t *ctx, const unsigned char *input, size_t ilen);

status_t SSS_sha256_starts_ret(sss_sha256_context_t *ctx, bool is_sha224);

/*! *********************************************************************************
 * \brief   Performs the initialization of the HMAC SHA256 context data.
 *
 * \param [in]    ctx    Pointer to the HMAC SHA256 context data structure.
 *
 * note: The sss_hmac_sha256_context_t structure contains the HMAC buffers.
 *       It may be allocated or in the stack
 *
 ********************************************************************************** */
void SSS_md_hmac_sha256_init(sss_hmac_sha256_context_t *ctx);

/*! *********************************************************************************
 * \brief   Free the HMAC SHA256 context data by simply resetting the contents.
 *
 * \param [in]    ctx    Pointer to the HMAC SHA256 context data structure.
 *
 *
 ********************************************************************************** */
void SSS_md_hmac_sha256_free(sss_hmac_sha256_context_t *ctx);

/*! *********************************************************************************
 * \brief   Reset the HMAC SHA256 context data.
 *
 * \param [in]    ctx    Pointer to the HMAC SHA256 context data structure.
 *
 *
 ********************************************************************************** */
status_t SSS_md_hmac_sha256_reset(sss_hmac_sha256_context_t *ctx);

/*! *********************************************************************************
 * \brief  Clones a HMAC SHA256 context
 *
 * \param [out]   dst    Pointer to buffer sufficient to hold HMAC SHA256 context data
 *
 * \param [in]    src    Pointer to the HMAC SHA256 context to be cloned
 *
 ********************************************************************************** */
status_t SSS_md_hmac_sha256_clone(sss_hmac_sha256_context_t *dst, const sss_hmac_sha256_context_t *src);

/*! *********************************************************************************
 * \brief  Start a HMAC SHA256 operation
 *
 * \param [in]   ctx    Pointer to the HMAC SHA256 context data.
 * \param [in]   key    Pointer to the HMAC key
 * \param [in]   keyLen Length of the HMAC key in bytes
 *
 * \return       kSSS_StatusSuccess if all SSS operations are Ok
 ********************************************************************************** */
status_t SSS_md_hmac_sha256_starts(sss_hmac_sha256_context_t *ctx, const unsigned char *key, size_t keylen);

/*! *********************************************************************************
 * \brief  Compute HMAC SHA256 digest over input
 *
 * \param [in]   ctx    Pointer to the HMAC SHA256 context data.
 * \param [in]   input  Pointer to input to be hashed.
 * \param [in]   iLen   Length of input buffer in bytes.
 *
 * \return       kSSS_StatusSuccess if all SSS operations are Ok
 ********************************************************************************** */
status_t SSS_md_hmac_sha256_update(sss_hmac_sha256_context_t *ctx, const unsigned char *input, size_t ilen);

/*! *********************************************************************************
 * \brief  Return the HMAC SHA256 digest value
 *
 * \param [in]   ctx    Pointer to the HMAC SHA256 context data.
 * \param [out]  output Pointer to output buffer for caller to receive digest.
 *
 * \return       kSSS_StatusSuccess if all SSS operations are Ok
 ********************************************************************************** */
status_t SSS_md_hmac_sha256_finish(sss_hmac_sha256_context_t *ctx, unsigned char *output);

/*! *********************************************************************************
* \brief  Performs all HMAC SHA256 steps on multiple bytes: initialize,
*         update, finish, and update context data.
*         The final HMAC value is stored at the provided output location.

* \param [in]       pCtx       context maybe allocated or on stack
* \param [in]       key        Pointer to the HMAC key
* \param [in]       keylen      Length of the HMAC key in bytes
* \param [in]       input       Pointer to the input data
* \param [in]       ilen    Number of bytes to perform HMAC on
* \param [in,out]   output     Pointer to the output location
*
* \return       kSSS_StatusSuccess if all SSS operations are Ok
********************************************************************************** */
status_t SSS_md_hmac_sha256(sss_hmac_sha256_context_t *pCtx,
                            const unsigned char *key,
                            size_t keylen,
                            const unsigned char *input,
                            size_t ilen,
                            unsigned char *output);

status_t sss_ecdh_init_key(sss_ecp256_context_t *K_ctx);

/*! *********************************************************************************
* \brief  This function performs ECDH P256 Key pair generation
*
* \param[in]  ecdh_ctx Pointer to the location of the 16-byte plain text block.

* \param[in]  wrk_buf Pointer to the location of the 64 byte public key where public key
*             is generated by SSS in MSB format.
*
* \param[in]  wrk_buf_len  Pointer to the location of the 128-bit key.
*
* \param[out]  pOutPublicKey Pointer to the location to store the ecdhPublicKey_t X and Y coordinates
*              i.e. 64 bytes LSB first.
*
* \param[out]  pOutPrivateKey Pointer to the location to store the ecdhPrivateKey_t X P256 ECP point.
*              i.e. 32 bytes LSB first.
*
*
********************************************************************************** */
status_t sss_ecdh_make_public_ecp256_key(sss_ecp256_context_t *K_ctx, unsigned char *wrk_buf, size_t wrk_buf_len);

/*! *********************************************************************************
 * \brief  This function performs ECDH P256 DH secret calculation using the peer public key
 *
 * \param[in]  pEcdh_ctx Pointer to the ECDH context.
 *                      prerequiste: Qp must have been set.
 *
 * \param[in]  wrk_buf Pointer to the location of the 64 byte public key where public key
 *             is generated by SSS in MSB format.
 *
 * \param[in]  wrk_buf_len  Pointer to the location of the 128-bit key.
 *
 * Remark: On completion, the reponse DH Key is in the wrk_buf in big endian format
 *
 ********************************************************************************** */
status_t sss_ecdh_calc_secret(sss_ecdh_context_t *pEcdh_ctx, unsigned char *wrk_buf, size_t wrk_buf_lg);
status_t sss_ecdh_calc_EL2EL_key(sss_ecdh_context_t *pEcdh_ctx, unsigned char *wrk_buf, size_t wrk_buf_lg);

#define SSS_KEY_OBJ_FREE(_KEY_OBJ_) sss_sscp_key_object_free(_KEY_OBJ_, SSS_SSCP_KEY_OBJECT_FREE_DYNAMIC)

#define SSS_KEY_STORE_SET_KEY(_KEY_OBJ_, _KEY_, _KEY_BYTE_LEN_, _KEY_BITLEN_, _KEY_PART_) \
    sss_sscp_key_store_set_key(&g_keyStore, _KEY_OBJ_, _KEY_, _KEY_BYTE_LEN_, _KEY_BITLEN_, _KEY_PART_)

#define SSS_ECP_KEY_SZ(_KEYLEN_) (2 * (_KEYLEN_))

#define SSS_ECP_GENERATE_KEY(_KEY_OBJ_, _KEY_BITLEN_) \
    sss_sscp_key_store_generate_key(&g_keyStore, _KEY_OBJ_, _KEY_BITLEN_, NULL)

#define SSS_KEY_STORE_GET_PUBKEY(_KEY_OBJ_, _KEY_BUF_, _KEY_BYTELEN_, _KEY_BITLEN_) \
    sss_sscp_key_store_get_key(&g_keyStore, _KEY_OBJ_, _KEY_BUF_, _KEY_BYTELEN_, _KEY_BITLEN_, kSSS_KeyPart_Public)

#define SSS_KEY_ALLOCATE_HANDLE(_KEY_OBJ_, _KEY_ID_, _KEY_PART_, _TYPE_, _BYTE_LEN_, _OPT_) \
    sss_sscp_key_object_allocate_handle(_KEY_OBJ_, _KEY_ID_, _KEY_PART_, _TYPE_, _BYTE_LEN_, _OPT_)

#ifdef __cplusplus
}
#endif

#endif
