/** @file wmcrypto.c
 *
 *  @brief This file contains mbed TLS wrap function
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "mbedtls/dhm.h"
#include "mbedtls/ctr_drbg.h"

#include <mbedtls/md5.h>
#include <mbedtls/sha1.h>
#include <mbedtls/sha256.h>
#include <mbedtls/hmac_drbg.h>
#include <mbedtls/pkcs5.h>
#include <wmerrno.h>
#include <mbedtls/aes.h>

#include <stdio.h>
#include <stdlib.h>
#include "wmcrypto.h"
#include <wm_mbedtls_helper_api.h>
#ifndef __linux__
#endif /* __linux__ */
#include "wmcrypto_mem.h"

#include "wm_mbedtls_entropy.h"

#define BLOCK_SIZE 16
#define APP_AES    AES

/*
 * Note: Please call ctaocrypt_lib_init() once from your module before
 * using any functions of this file.
 */
#ifndef NO_DH
/*
 * Setup Diffie-Hellman public and private key pair
 * i.e. 'public_key' and 'private_key',
 * with the help of parameters in 'dh_params'
 */

void *nxp_dh_setup_key(
    uint8_t *public_key, uint32_t public_len, uint8_t *private_key, uint32_t private_len, DH_PG_PARAMS *dh_params)
{
    uint32_t ret = 0;
    size_t temp_len;

    mbedtls_ctr_drbg_context *ctr_drbg = wm_mbedtls_get_ctr_drbg_ctx();
    if (ctr_drbg == NULL)
    {
        crypto_e("Failed to get ctr_drbg handle");
        return NULL;
    }

    if (!public_key || !private_key)
        return NULL;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return NULL;
    }

    mbedtls_dhm_context *dh;
    if ((dh = (mbedtls_dhm_context *)crypto_mem_malloc(sizeof(mbedtls_dhm_context))) == NULL)
    {
        crypto_e("Failed to allocate memory");
        goto error;
    }

    mbedtls_dhm_init(dh);

    if ((ret = mbedtls_mpi_read_binary(&dh->P, dh_params->prime, dh_params->primeLen)) != 0)
    {
        crypto_e("mbedtls_mpi_read_binary failed: %02x", -ret);
        goto error;
    }

    if ((ret = mbedtls_mpi_read_binary(&dh->G, dh_params->generator, dh_params->generatorLen)) != 0)
    {
        crypto_e("mbedtls_mpi_read_binary failed %02x", -ret);
        goto error;
    }

    unsigned char *buf;
    if ((buf = (unsigned char *)crypto_mem_malloc(private_len)) == NULL)
    {
        crypto_e("Failed to allocate memory");
        return NULL;
    }
    else
    {
        (void)memset(buf, 0, private_len);
    }

    dh->len  = private_len;
    temp_len = dh->len;

    if ((ret = mbedtls_dhm_make_public(dh, (int)dh->len, buf, temp_len, mbedtls_ctr_drbg_random, ctr_drbg)) != 0)
    {
        crypto_e("mbedtls_dhm_make_public failed %d", ret);
        crypto_e("mbedtls_dhm_make_public failed %d", -ret);
        goto error;
    }
    else
    {
        crypto_mem_free(buf);
    }

    if ((ret = mbedtls_mpi_write_binary(&dh->X, (unsigned char *)private_key, (size_t)private_len)) != 0)
    {
        crypto_e("mbedtls_mpi_write_binary failed %02x", -ret);
        goto error;
    }

    if ((ret = mbedtls_mpi_write_binary(&dh->GX, (unsigned char *)public_key, (size_t)public_len)) != 0)
    {
        crypto_e("mbedtls_mpi_write_binary failed %02x", -ret);
        goto error;
    }

    return dh;

error:
    mbedtls_dhm_free(dh);
    crypto_mem_free(dh);
    return NULL;
}

int nxp_dh_compute_key(void *dh,
                       uint8_t *shared_key,
                       uint32_t shared_len,
                       uint8_t *public_key,
                       uint32_t public_len,
                       uint8_t *private_key,
                       uint32_t private_len,
                       DH_PG_PARAMS *dh_params)
{
    /*
     * Note:
     *
     * Ignoring last 3 parameters, namely
     * private_key, private_len, dh_params.
     *
     * Since these parameters are already populated
     * in dh context by function 'nxp_dh_setup_key'
     */
    mbedtls_dhm_context *dh_m = (mbedtls_dhm_context *)dh;
    unsigned char *buf;

    mbedtls_ctr_drbg_context *ctr_drbg = wm_mbedtls_get_ctr_drbg_ctx();
    if (ctr_drbg == NULL)
    {
        crypto_e("Failed to get ctr_drbg handle");
        return -1;
    }
    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -1;
    }

    uint8_t *key   = NULL;
    size_t key_len = 0, temp_len = shared_len;

    key_len = shared_len;
    key     = crypto_mem_malloc(key_len);
    if (key == NULL)
    {
        crypto_e("Failed to allocate memory");
        return -WM_E_NOMEM;
    }
    (void)memset(key, 0, key_len);

    uint32_t ret = 0;
    if ((ret = mbedtls_mpi_read_binary(&dh_m->GY, public_key, public_len)) != 0)
    {
        crypto_e("mbedtls_mpi_read_binary failed %02x", -ret);
        goto error;
    }

    buf = (unsigned char *)crypto_mem_malloc(shared_len);
    if (buf == NULL)
    {
        crypto_e("Failed to allocate memory");
        return -WM_E_NOMEM;
    }
    (void)memset(buf, 0, shared_len);

    if ((ret = mbedtls_dhm_calc_secret(dh_m, buf, (size_t)shared_len, &temp_len, mbedtls_ctr_drbg_random, ctr_drbg)) !=
        0)
    {
        crypto_e("mbedtls_dhm_calc_secret failed %02x", -ret);
        crypto_mem_free(buf);
        goto error;
    }

    if ((ret = mbedtls_mpi_write_binary(&dh_m->K, (unsigned char *)key, key_len)) != 0)
    {
        crypto_e("mbedtls_mpi_write_binary failed %02x", -ret);
        goto error;
    }

    (void)memcpy(shared_key, key, key_len);
    ret = key_len;
    crypto_mem_free(buf);

error:
    crypto_mem_free(key);
    return ret;
}

void nxp_dh_free(void *dh_context)
{
    mbedtls_dhm_context *dh = (mbedtls_dhm_context *)dh_context;
    if (dh)
    {
        mbedtls_dhm_free(dh);
        crypto_mem_free(dh);
    }
}
#endif
static void sha1_vector(size_t num_elem, const uint8_t *addr[], const size_t *len, uint8_t *mac)
{
    mbedtls_sha1_context sha;
    size_t i;

    mbedtls_sha1_init(&sha);
    mbedtls_sha1_starts(&sha);

    for (i = 0; i < num_elem; i++)
        mbedtls_sha1_update(&sha, addr[i], len[i]);

    mbedtls_sha1_finish(&sha, mac);
}

uint32_t nxp_sha1_vector(size_t nmsg, const uint8_t *msg[], const size_t msglen[], uint8_t *mac, size_t maclen)
{
    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }
    sha1_vector(nmsg, msg, msglen, mac);
    return 0;
}

static void md5_vector(size_t num_elem, const uint8_t *addr[], const size_t *len, uint8_t *mac)
{
    mbedtls_md5_context md5;
    size_t i;

    mbedtls_md5_init(&md5);
    mbedtls_md5_starts(&md5);

    for (i = 0; i < num_elem; i++)
        mbedtls_md5_update(&md5, addr[i], len[i]);

    mbedtls_md5_finish(&md5, mac);
}

static uint32_t nxp_md5_vector(size_t nmsg, const uint8_t *msg[], const size_t msglen[], uint8_t *mac, size_t maclen)
{
    md5_vector(nmsg, msg, msglen, mac);
    return 0;
}

uint32_t nxp_sha256_vector(size_t nmsg, const uint8_t *msg[], const size_t msglen[], uint8_t *mac, size_t maclen)
{
    const uint8_t *addr[6];
    size_t len[6], i;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    for (i = 0; i < nmsg; i++)
    {
        addr[i] = (uint8_t *)msg[i];
        len[i]  = (size_t)msglen[i];
    }

    nxp_sha256(nmsg, addr, len, mac);

    return maclen;
}

void nxp_sha256(size_t num_elem, const uint8_t *addr[], const size_t *len, uint8_t *mac)
{
    mbedtls_sha256_context sha;
    size_t i;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }

    mbedtls_sha256_init(&sha);
    mbedtls_sha256_starts(&sha, 0);

    for (i = 0; i < num_elem; i++)
        mbedtls_sha256_update(&sha, addr[i], len[i]);

    mbedtls_sha256_finish(&sha, mac);
}

uint32_t nxp_hmac_sha256(
    const uint8_t *key, uint32_t keylen, uint8_t *msg, uint32_t msglen, uint8_t *mac, uint32_t maclen)
{
    uint8_t k_pad[64]; /* padding - key XORd with ipad/opad */
    uint8_t tk[SHA256_DIGEST_SIZE] = {0x0};
    const uint8_t *_addr[2];
    size_t _len[2];
    uint32_t i;
    uint32_t ret = 0;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    if ((mac == NULL) || (maclen < SHA256_DIGEST_SIZE))
        return 0;

    /* if key is longer than 64 bytes reset it to key = SHA256(key) */
    if (keylen > 64)
    {
        nxp_sha256_vector(1, &key, (size_t *)&keylen, tk, SHA256_DIGEST_SIZE);
        key    = tk;
        keylen = SHA256_DIGEST_SIZE;
    }

    /* the HMAC_SHA256 transform looks like:
     *
     *
     * SHA256(K XOR opad, SHA256(K XOR ipad, text))
     *
     * where K is an n byte key
     * ipad is the byte 0x36 repeated 64 times
     * opad is the byte 0x5c repeated 64 times
     * and text is the data being protected */

    /* start out by storing key in ipad */
    (void)memset(k_pad, 0, sizeof(k_pad));
    (void)memcpy(k_pad, key, keylen);
    /* XOR key with ipad values */
    for (i = 0; i < 64; i++)
        k_pad[i] ^= 0x36;

    /* perform inner SHA256 */
    _addr[0] = k_pad;
    _len[0]  = 64;
    _addr[1] = msg;
    _len[1]  = msglen;

    nxp_sha256_vector(2, _addr, _len, mac, maclen);

    (void)memset(k_pad, 0, sizeof(k_pad));
    (void)memcpy(k_pad, key, keylen);
    /* XOR key with opad values */
    for (i = 0; i < 64; i++)
        k_pad[i] ^= 0x5c;

    /* perform outer SHA256 */
    _addr[0] = k_pad;
    _len[0]  = 64;
    _addr[1] = mac;
    _len[1]  = SHA256_DIGEST_SIZE;

    ret = nxp_sha256_vector(2, _addr, _len, mac, maclen);
    return ret;
}

/**
 *  * @brief Key derivation function to generate Authentication
 *            Key and Key Wrap Key used in WPS registration protocol
 * @param key        Input key to generate authentication key (KDK)
 * @param keylen        Length of input key
 * @param result        result buffer
 * @param result_len    Length of result buffer
 * @return 0 on success otherwise 1
 */
int nxp_kdf(uint8_t *key, uint32_t key_len, uint8_t *result, uint32_t result_len)
{
    uint8_t mac[SHA256_DIGEST_SIZE] = {0x0};
    uint32_t mac_len                = SHA256_DIGEST_SIZE;
    uint8_t msg[100];
    uint32_t iter = (result_len * 8 + SHA256_DIGEST_SIZE - 1) / SHA256_DIGEST_SIZE;
    uint8_t *start;
    uint8_t *end;
    uint32_t i;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    start = result;
    end   = start + result_len;

    for (i = 1; i < (iter + 1); i++)
    {
        sprintf((char *)msg, "%c%c%c%cWi-Fi Easy and Secure Key Derivation%c%c%c%c", 0x00, 0x00, 0x00, (int)i, 0x00,
                0x00, (int)((result_len * 8) / 0x100), (int)((result_len * 8) % 0x100));

        nxp_hmac_sha256(key, key_len, msg, 44, mac, mac_len);

        if ((start + mac_len) < end)
        {
            (void)memcpy(start, mac, mac_len);
            start += mac_len;
        }
        else
        {
            (void)memcpy(start, mac, (uint32_t)(end - start));
            return 0;
        }
    }
    return 1;
}

#ifndef __linux__
/**********************************************************
 *  ***   AES Key Wrap Key
 *   **********************************************************/
/**
 *  @brief  Wrap keys with AES Key Wrap Algorithm (128-bit KEK)
 *
 *  @param pPlainTxt    Plaintext key to be wrapped
 *  @param TextLen      Length of the plain key in bytes (16 bytes)
 *  @param pCipTxt      Wrapped key
 *  @param pKEK         Key encryption key (KEK)
 *  @param KeyLen       Length of KEK in bytes (must be divisible by 16)
 *  @param IV           Encryption IV for CBC mode (16 bytes)
 *  @return             0 on success, -1 on failure
 */
int nxp_aes_wrap(uint8_t *pPlainTxt, uint32_t TextLen, uint8_t *pCipTxt, uint8_t *pKEK, uint32_t KeyLen, uint8_t *IV)
{
    mbedtls_aes_context aes;
    uint8_t *buf;
    //    aes_t enc;

    //    mdev_t *aes_dev = aes_drv_open(MDEV_AES_0);
    //    if (aes_dev == NULL) {
    //        crypto_e("AES driver init is required before open");
    //        return -1;
    //    }

    //    aes_drv_setkey(aes_dev, &enc, pKEK, KeyLen, IV,
    //               AES_ENCRYPTION, HW_AES_MODE_CBC);
    //        AES_SetKey(APP_AES, pKEK, KeyLen);

    if ((TextLen / 16) % 2)
    {
        buf = (uint8_t *)crypto_mem_malloc(TextLen);
        if (buf == NULL)
        {
            crypto_e("nxp_aes_wrap malloc failed!");
            //            aes_drv_close(aes_dev);
            return -1;
        }

        (void)memcpy(buf, pPlainTxt, TextLen);
        //        aes_drv_encrypt(aes_dev, &enc, buf, pCipTxt, TextLen);
        //        AES_EncryptCbc(APP_AES, buf, pCipTxt, TextLen, IV, NULL);
    }
    else
    {
        buf = (uint8_t *)crypto_mem_malloc(TextLen + 16);
        if (buf == NULL)
        {
            crypto_e("nxp_aes_wrap malloc failed!");
            //            aes_drv_close(aes_dev);
            return -1;
        }

        (void)memcpy(buf, pPlainTxt, TextLen);
        (void)memset(&buf[TextLen], 0x10, 16);
        TextLen = TextLen + 16;
        //        aes_drv_encrypt(aes_dev, &enc, buf, pCipTxt, TextLen + 16);
        //        AES_EncryptCbc(APP_AES, buf, pCipTxt, TextLen + 16, IV, NULL);
    }

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_enc(&aes, pKEK, KeyLen * 8);
    mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, TextLen, IV, buf, pCipTxt);
    mbedtls_aes_free(&aes);

    crypto_mem_free(buf);
    //    aes_drv_close(aes_dev);
    return 0;
}

/**
 *  @brief  Unwrap key with AES Key Wrap Algorithm (128-bit KEK)
 *
 *  @param pCipTxt      Wrapped key to be unwrapped
 *  @param TextLen      Length of the wrapped key in bytes (16 bytes)
 *  @param pPlainTxt    Plaintext key
 *  @param pKEK         Key encryption key (KEK)
 *  @param KeyLen       Length of KEK in bytes (must be divisible by 16)
 *  @param IV           Encryption IV for CBC mode (16 bytes)
 *  @return             0 on success, -1 on failure
 */
int nxp_aes_unwrap(uint8_t *pCipTxt, uint32_t TextLen, uint8_t *pPlainTxt, uint8_t *pKEK, uint32_t KeyLen, uint8_t *IV)
{
    //    aes_t dec;

    //    mdev_t *aes_dev = aes_drv_open(MDEV_AES_0);
    //    if (aes_dev == NULL) {
    //        crypto_e("AES driver init is required before open");
    //        return -1;
    //    }

    //    aes_drv_setkey(aes_dev, &dec, pKEK, KeyLen, IV,
    //               AES_DECRYPTION, HW_AES_MODE_CBC);
    //        AES_SetKey(APP_AES, pKEK, KeyLen);
    //    aes_drv_decrypt(aes_dev, &dec, pCipTxt, pPlainTxt, TextLen);
    //    AES_DecryptCbc(APP_AES, pCipTxt, pPlainTxt, TextLen, IV, NULL);

    mbedtls_aes_context aes;
    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_dec(&aes, pKEK, KeyLen * 8);
    mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_DECRYPT, TextLen, IV, pCipTxt, pPlainTxt);
    mbedtls_aes_free(&aes);

    //    AES_DecryptCbcWithLock(APP_AES,pKEK, KeyLen, pCipTxt, pPlainTxt, TextLen, IV, NULL);
    //`aes_drv_close(aes_dev);

    return 0;
}

int nxp_aes_wrap_ext(
    uint8_t *pPlainTxt, uint32_t TextLen, uint8_t *pCipTxt, uint8_t *pKEK, uint32_t KeyLen, uint8_t *IV)
{
    uint32_t OrigLen = TextLen;
    int i;

    if (TextLen % 32 == 0)
    {
        nxp_aes_wrap(pPlainTxt, TextLen, pCipTxt, pKEK, KeyLen, IV);
        TextLen += 16;
    }
    else
    {
        if (TextLen % 16 == 0 && TextLen % 32 != 0)
            TextLen = TextLen - TextLen % 32 + 32;
        else if (TextLen % 16 != 0)
            TextLen = TextLen - TextLen % 16 + 16;

        /* Padding the value of # of paddings */
        for (i = 0; i < TextLen - OrigLen; i++)
            *(pPlainTxt + OrigLen + i) = TextLen - OrigLen;

        nxp_aes_wrap(pPlainTxt, TextLen, pCipTxt, pKEK, KeyLen, IV);
    }

    return TextLen;
}

int nxp_aes_unwrap_ext(
    uint8_t *pCipTxt, uint32_t TextLen, uint8_t *pPlainTxt, uint8_t *pKEK, uint32_t KeyLen, uint8_t *IV)
{
    uint8_t *ptr;
    int i, pad;

    /* Decrypt */
    nxp_aes_unwrap(pCipTxt, TextLen, pPlainTxt, pKEK, KeyLen, IV);

    /* Remove padding */
    ptr = &pPlainTxt[TextLen - 1];

    pad = *ptr;

    if (pad > TextLen)
        return -1;

    for (i = 0; i < pad; i++)
    {
        if (*ptr-- != pad)
            return -1;
    }

    return TextLen - pad;
}
#endif /* ! __linux__ */

void nxp_crypto_hmac_md5(uint8_t *input, int input_len, uint8_t *hash, char *hash_key)
{
    const mbedtls_md_info_t *info_md5;
    mbedtls_md_context_t md5_ctx;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }
    mbedtls_md_init(&md5_ctx);

    if ((info_md5 = mbedtls_md_info_from_type(MBEDTLS_MD_MD5)) == NULL)
    {
        crypto_e("Failed to set sha1 info");
        return;
    }

    if (mbedtls_md_setup(&md5_ctx, info_md5, 1) != 0)
    {
        crypto_e("Failed to setup md context");
        return;
    }

    mbedtls_md_hmac_starts(&md5_ctx, (const unsigned char *)hash_key, 16);
    mbedtls_md_hmac_update(&md5_ctx, input, input_len);
    mbedtls_md_hmac_finish(&md5_ctx, hash);
}

void nxp_crypto_md5(uint8_t *input, int len, uint8_t *hash, int hlen)
{
    mbedtls_md5_context md5;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }

    mbedtls_md5_init(&md5);
    mbedtls_md5_starts(&md5);
    mbedtls_md5_update(&md5, input, len);
    mbedtls_md5_finish(&md5, hash);
}

void pbkdf2_sha1(
    const char *passphrase, const char *ssid, size_t ssid_len, int iterations, uint8_t *output, size_t output_len)
{
    const mbedtls_md_info_t *info_sha1;
    mbedtls_md_context_t sha1_ctx;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }
    mbedtls_md_init(&sha1_ctx);

    if ((info_sha1 = mbedtls_md_info_from_type(MBEDTLS_MD_SHA1)) == NULL)
    {
        crypto_e("Failed to set sha1 info");
        return;
    }

    if (mbedtls_md_setup(&sha1_ctx, info_sha1, 1) != 0)
    {
        crypto_e("Failed to setup md context");
        return;
    }

    if (mbedtls_pkcs5_pbkdf2_hmac(&sha1_ctx, (const unsigned char *)passphrase, strlen(passphrase),
                                  (const unsigned char *)ssid, strlen(ssid), iterations, output_len, output) != 0)
    {
        crypto_e("Failed to generate pbkdf");
    }
}

void nxp_crypto_pass_to_key(
    char *password, unsigned char *ssid, int ssidlength, int iterations, int output_len, unsigned char *output)
{
    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }

    pbkdf2_sha1((const char *)password, (const char *)ssid, ssidlength, iterations, output, output_len);
}

#define PSK_PASS_PHRASE_LEN_MAX 64
#define PMK_LEN_MAX             32

/*
 * password - ascii string up to 63 characters in length
 * ssid - octet string up to 32 octets
 * ssidlength - length of ssid in octets
 * output must be 32 octets in length and outputs 256 bits of key
 */
static int nxp_passwordhash(const char *passphrase, const char *ssid, int ssid_len, char *output)
{
    if ((strlen(passphrase) > 63) || (ssid_len > 32))
        return -1;

    pbkdf2_sha1(passphrase, ssid, ssid_len, 4096, (uint8_t *)output, PMK_LEN_MAX);

    return 0;
}

static uint8_t nxp_get_hex_nibble(uint8_t nibble)
{
    if (nibble >= 'a')
    {
        return nibble - 'a' + 10;
    }

    if (nibble >= 'A')
    {
        return nibble - 'A' + 10;
    }

    return nibble - '0';
}

int nxp_generate_psk(const char *ssid, int ssid_len, const char *passphrase, char *output)
{
    int i, ret;

    if (output && passphrase)
    {
        for (i = 0; i < PSK_PASS_PHRASE_LEN_MAX; i++)
        {
            if (passphrase[i] == 0)
            {
                break;
            }
        }

        if (i > 7 && i < PSK_PASS_PHRASE_LEN_MAX)
        {
            ret = nxp_passwordhash(passphrase, ssid, ssid_len, output);
            if (ret != 0)
                return ret;
        }
        else if (i == PSK_PASS_PHRASE_LEN_MAX)
        {
            /* Convert ASCII to binary */
            for (i = 0; i < PSK_PASS_PHRASE_LEN_MAX; i += 2)
            {
                output[i / 2] = ((nxp_get_hex_nibble(passphrase[i]) << 4) | nxp_get_hex_nibble(passphrase[i + 1]));
            }
        }
    }

    return 0;
}

/**
 * hmac_md5_vector - HMAC-MD5 over data vector (RFC 2104)
 * @key: Key for HMAC operations
 * @key_len: Length of the key in bytes
 * @num_elem: Number of elements in the data vector
 * @addr: Pointers to the data areas
 * @len: Lengths of the data blocks
 * @mac: Buffer for the hash (16 bytes)
 */
void hmac_md5_vector(const uint8_t *key,
                     size_t key_len,
                     size_t num_elem,
                     const uint8_t *addr[],
                     const size_t *len,
                     uint8_t *mac,
                     size_t maclen)
{
    uint8_t k_pad[64]; /* padding - key XORd with ipad/opad */
    uint8_t tk[16];
    const uint8_t *_addr[6];
    size_t i, _len[6];

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }

    if (num_elem > 5)
    {
        /*
         * Fixed limit on the number of fragments to avoid having to
         * allocate memory (which could fail).
         */
        return;
    }

    /* if key is longer than 64 bytes reset it to key = MD5(key) */
    if (key_len > 64)
    {
        nxp_md5_vector(1, &key, &key_len, tk, maclen);
        key     = tk;
        key_len = 16;
    }

    /* the HMAC_MD5 transform looks like: MD5(K XOR opad, MD5(K XOR ipad,
       text)) where K is an n byte key ipad is the byte 0x36 repeated 64 times
       opad is the byte 0x5c repeated 64 times and text is the data being
       protected */

    /* start out by storing key in ipad */
    (void)memset(k_pad, 0, sizeof(k_pad));
    (void)memcpy(k_pad, key, key_len);

    /* XOR key with ipad values */
    for (i = 0; i < 64; i++)
        k_pad[i] ^= 0x36;

    /* perform inner MD5 */
    _addr[0] = k_pad;
    _len[0]  = 64;
    for (i = 0; i < num_elem; i++)
    {
        _addr[i + 1] = addr[i];
        _len[i + 1]  = len[i];
    }
    nxp_md5_vector(1 + num_elem, _addr, _len, mac, maclen);

    (void)memset(k_pad, 0, sizeof(k_pad));
    (void)memcpy(k_pad, key, key_len);
    /* XOR key with opad values */
    for (i = 0; i < 64; i++)
        k_pad[i] ^= 0x5c;

    /* perform outer MD5 */
    _addr[0] = k_pad;
    _len[0]  = 64;
    _addr[1] = mac;
    _len[1]  = MD5_MAC_LEN;
    nxp_md5_vector(2, _addr, _len, mac, maclen);
}

/**
 * hmac_sha1_vector - HMAC-SHA1 over data vector (RFC 2104)
 * @key: Key for HMAC operations
 * @key_len: Length of the key in bytes
 * @num_elem: Number of elements in the data vector
 * @addr: Pointers to the data areas
 * @len: Lengths of the data blocks
 * @mac: Buffer for the hash (20 bytes)
 */
int hmac_sha1_vector(const uint8_t *key,
                     size_t key_len,
                     size_t num_elem,
                     const uint8_t *addr[],
                     const size_t *len,
                     uint8_t *mac,
                     size_t maclen)
{
    unsigned char k_pad[64]; /* padding - key XORd with ipad/opad */
    unsigned char tk[20] = {0};
    const uint8_t *_addr[6];
    size_t _len[6], i;

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    if (num_elem > 5)
    {
        /*
         * Fixed limit on the number of fragments to avoid having to
         * allocate memory (which could fail).
         */
        return -1;
    }

    /* if key is longer than 64 bytes reset it to key = SHA1(key) */
    if (key_len > 64)
    {
        nxp_sha1_vector(1, &key, &key_len, tk, maclen);
        key     = tk;
        key_len = 20;
    }

    /* the HMAC_SHA1 transform looks like: SHA1(K XOR opad, SHA1(K XOR ipad,
       text)) where K is an n byte key ipad is the byte 0x36 repeated 64
       times
       opad is the byte 0x5c repeated 64 times and text is the data being
       protected */

    /* start out by storing key in ipad */
    (void)memset(k_pad, 0, sizeof(k_pad));
    (void)memcpy(k_pad, key, key_len);
    /* XOR key with ipad values */
    for (i = 0; i < 64; i++)
        k_pad[i] ^= 0x36;

    /* perform inner SHA1 */
    _addr[0] = k_pad;
    _len[0]  = 64;
    for (i = 0; i < num_elem; i++)
    {
        _addr[i + 1] = addr[i];
        _len[i + 1]  = len[i];
    }
    nxp_sha1_vector(1 + num_elem, _addr, _len, mac, maclen);

    (void)memset(k_pad, 0, sizeof(k_pad));
    (void)memcpy(k_pad, key, key_len);
    /* XOR key with opad values */
    for (i = 0; i < 64; i++)
        k_pad[i] ^= 0x5c;

    /* perform outer SHA1 */
    _addr[0] = k_pad;
    _len[0]  = 64;
    _addr[1] = mac;
    _len[1]  = SHA1_MAC_LEN;
    nxp_sha1_vector(2, _addr, _len, mac, maclen);

    return 0;
}

/**
 * hmac_md5 - HMAC-MD5 over data buffer (RFC 2104)
 * @key: Key for HMAC operations
 * @key_len: Length of the key in bytes
 * @data: Pointers to the data area
 * @data_len: Length of the data area
 * @mac: Buffer for the hash (16 bytes)
 */
void hmac_md5(const uint8_t *key, size_t key_len, const uint8_t *data, size_t data_len, uint8_t *mac, size_t maclen)
{
    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }
    hmac_md5_vector(key, key_len, 1, &data, &data_len, mac, maclen);
}

/**
 * hmac_sha1 - HMAC-SHA1 over data buffer (RFC 2104)
 * @key: Key for HMAC operations
 * @key_len: Length of the key in bytes
 * @data: Pointers to the data area
 * @data_len: Length of the data area
 * @mac: Buffer for the hash (20 bytes)
 */
int hmac_sha1(const uint8_t *key, size_t key_len, const uint8_t *data, size_t data_len, uint8_t *mac, size_t maclen)
{
    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    return hmac_sha1_vector(key, key_len, 1, &data, &data_len, mac, maclen);
}

void nxp_hmac_md5(const uint8_t *key, size_t key_len, const uint8_t *data, size_t data_len, uint8_t *mac, size_t maclen)
{
    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return;
    }

    hmac_md5(key, key_len, data, data_len, mac, maclen);
}

/**
 * tls_prf - Pseudo-Random Function for TLS (TLS-PRF, RFC 2246)
 * @secret: Key for PRF
 * @secret_len: Length of the key in bytes
 * @label: A unique label for each purpose of the PRF
 * @seed: Seed value to bind into the key
 * @seed_len: Length of the seed
 * @out: Buffer for the generated pseudo-random key
 * @outlen: Number of bytes of key to generate
 * Returns: 0 on success, -1 on failure.
 *
 * This function is used to derive new, cryptographically separate keys from a
 * given key in TLS. This PRF is defined in RFC 2246, Chapter 5.
 */
int nxp_tls_prf(const uint8_t *secret,
                size_t secret_len,
                const char *label,
                const uint8_t *seed,
                size_t seed_len,
                uint8_t *out,
                size_t outlen)
{
    size_t L_S1, L_S2, i;
    const uint8_t *S1, *S2;
    uint8_t A_MD5[MD5_MAC_LEN], A_SHA1[SHA1_MAC_LEN];
    uint8_t P_MD5[MD5_MAC_LEN] = {0x0}, P_SHA1[SHA1_MAC_LEN] = {0x0};
    int MD5_pos, SHA1_pos;
    const uint8_t *MD5_addr[3];
    size_t MD5_len[3];
    const unsigned char *SHA1_addr[3];
    size_t SHA1_len[3];

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    if (secret_len & 1)
        return -1;

    MD5_addr[0] = A_MD5;
    MD5_len[0]  = MD5_MAC_LEN;
    MD5_addr[1] = (unsigned char *)label;
    MD5_len[1]  = strlen(label);
    MD5_addr[2] = seed;
    MD5_len[2]  = seed_len;

    SHA1_addr[0] = A_SHA1;
    SHA1_len[0]  = SHA1_MAC_LEN;
    SHA1_addr[1] = (unsigned char *)label;
    SHA1_len[1]  = strlen(label);
    SHA1_addr[2] = seed;
    SHA1_len[2]  = seed_len;

    /* RFC 2246, Chapter 5 A(0) = seed, A(i) = HMAC(secret, A(i-1)) P_hash =
       HMAC(secret, A(1) + seed) + HMAC(secret, A(2) + seed) + .. PRF =
       P_MD5(S1, label + seed) XOR P_SHA-1(S2, label + seed) */

    L_S1 = L_S2 = (secret_len + 1) / 2;
    S1          = secret;
    S2          = secret + L_S1;

    hmac_md5_vector(S1, L_S1, 2, &MD5_addr[1], &MD5_len[1], A_MD5, MD5_MAC_LEN);
    hmac_sha1_vector(S2, L_S2, 2, &SHA1_addr[1], &SHA1_len[1], A_SHA1, SHA1_MAC_LEN);

    MD5_pos  = MD5_MAC_LEN;
    SHA1_pos = SHA1_MAC_LEN;
    for (i = 0; i < outlen; i++)
    {
        if (MD5_pos == MD5_MAC_LEN)
        {
            hmac_md5_vector(S1, L_S1, 3, MD5_addr, MD5_len, P_MD5, MD5_MAC_LEN);
            MD5_pos = 0;
            hmac_md5(S1, L_S1, A_MD5, MD5_MAC_LEN, A_MD5, MD5_MAC_LEN);
        }
        if (SHA1_pos == SHA1_MAC_LEN)
        {
            hmac_sha1_vector(S2, L_S2, 3, SHA1_addr, SHA1_len, P_SHA1, SHA1_MAC_LEN);
            SHA1_pos = 0;
            hmac_sha1(S2, L_S2, A_SHA1, SHA1_MAC_LEN, A_SHA1, SHA1_MAC_LEN);
        }

        out[i] = P_MD5[MD5_pos] ^ P_SHA1[SHA1_pos];

        MD5_pos++;
        SHA1_pos++;
    }

    return 0;
}

/**
 * sha1_prf - SHA1-based Pseudo-Random Function (PRF) (IEEE 802.11i, 8.5.1.1)
 * @key: Key for PRF
 * @key_len: Length of the key in bytes
 * @label: A unique label for each purpose of the PRF
 * @data: Extra data to bind into the key
 * @data_len: Length of the data
 * @buf: Buffer for the generated pseudo-random key
 * @buf_len: Number of bytes of key to generate
 * Returns: 0 on success, -1 of failure
 *
 * This function is used to derive new, cryptographically separate keys from a
 * given key (e.g., PMK in IEEE 802.11i).
 */
int nxp_sha1_prf(const uint8_t *key,
                 size_t key_len,
                 const char *label,
                 const uint8_t *data,
                 size_t data_len,
                 uint8_t *buf,
                 size_t buf_len)
{
    uint8_t counter = 0;
    size_t pos, plen;
    uint8_t hash[SHA1_MAC_LEN];
    size_t label_len = strlen(label) + 1;
    const unsigned char *addr[3];
    size_t len[3];

    if (!is_wm_mbedtls_lib_init())
    {
        crypto_e("mbedtls lib init not done");
        return -WM_FAIL;
    }

    addr[0] = (uint8_t *)label;
    len[0]  = label_len;
    addr[1] = data;
    len[1]  = data_len;
    addr[2] = &counter;
    len[2]  = 1;

    pos = 0;
    while (pos < buf_len)
    {
        plen = buf_len - pos;
        if (plen >= SHA1_MAC_LEN)
        {
            if (hmac_sha1_vector(key, key_len, 3, addr, len, &buf[pos], SHA1_MAC_LEN))
                return -1;
            pos += SHA1_MAC_LEN;
        }
        else
        {
            if (hmac_sha1_vector(key, key_len, 3, addr, len, hash, SHA1_MAC_LEN))
                return -1;
            (void)memcpy(&buf[pos], hash, plen);
            break;
        }
        counter++;
    }

    return 0;
}
