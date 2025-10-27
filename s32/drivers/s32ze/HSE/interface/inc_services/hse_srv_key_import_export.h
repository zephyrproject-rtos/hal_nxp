/**
*   @file    hse_srv_key_import_export.h
*
*   @brief   HSE Key Import/Export services.
*   @details This file contains the Key Import/Export services definition.
*
*   @addtogroup hse_srv_key_import_export HSE Key Import/Export Services
*   @ingroup class_key_management
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019 - 2024 NXP.
*
*   Redistribution and use in source and binary forms, with or without modification,
*   are permitted provided that the following conditions are met:
*
*   1. Redistributions of source code must retain the above copyright notice, this list
*      of conditions and the following disclaimer.
*
*   2. Redistributions in binary form must reproduce the above copyright notice, this
*      list of conditions and the following disclaimer in the documentation and/or
*      other materials provided with the distribution.
*
*   3. Neither the name of the copyright holder nor the names of its
*      contributors may be used to endorse or promote products derived from this
*      software without specific prior written permission.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_KEY_IMPORT_EXPORT_H
#define HSE_SRV_KEY_IMPORT_EXPORT_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief HSE ECC key format
 *  @details Additional info for Ecc key format for import and export
 *    For Weierstrass curve public keys:
 *    - the raw format is the X coordinate concatenated with the Y coordinate ( X || Y ), in big endian
 *    - the uncompressed  format is a byte of 0x04, concatenated with the X coordinate and Y coordinates ( 0x04 || X || Y )
 *    - the compressed format is a byte of 0x02 or 0x03, depending on the (lsb) of Y, concatenated with the X coordinate
 *          - ( 0x02 || X ) if the lsb of Y is 0
 *          - ( 0x03 || X ) if the lsb of Y is 1
 *    For Twisted Edwards curve public keys:
 *    - the raw format is the standard compressed format (point Y with the the sign bit of X), but in big endian
 *    For Montgomery curve public keys:
 *    - the raw format is the X coordinate, in big endian
 */
typedef uint8_t hseEccKeyFormat_t;
#define HSE_KEY_FORMAT_ECC_PUB_RAW                       ((hseEccKeyFormat_t)0U) /**< @brief Raw ECC public key: X || Y */
#define HSE_KEY_FORMAT_ECC_PUB_UNCOMPRESSED              ((hseEccKeyFormat_t)1U) /**< @brief Standard ECC uncompressed public key: 0x04 || X || Y */
#define HSE_KEY_FORMAT_ECC_PUB_COMPRESSED                ((hseEccKeyFormat_t)2U) /**< @brief Standard ECC compressed public key: 0x02/0x03 || X */

/** @brief HSE key format.
 *  @details Includes additional information about the format of the key. Currently only used for ECC keys.
 */
typedef union
{
    /** @brief   INPUT: ECC key format. */
    hseEccKeyFormat_t eccKeyFormat;
    uint8_t reserved[4];
} hseKeyFormat_t;


/** @brief   HSE Import Key Service.
 *  @details This service can be used to import a key in an empty slot or to update an existing key.
 *  1. Common key restrictions (which apply for both SuperUser and User rights):
 *     - Key flags (of key properties) are always applied.
 *     - The NVM provisioning keys can be installed/updated without authentication only having SuperUser rights;
 *       they can also be updated having User rights using the pre-installed provision keys.
 *     - The RAM provision keys can be imported only authenticated and can be used only to import RAM keys.
 *     - A key can be authenticated signing the key container (e.g. X.509 certificate or any container).
 *       The HOST shall provide a pointer to that key container, pointer(s) to key value(s) within the key container and
 *       pointer(s) to the tag/signature(s) (computed over the key container).
 *     - To import an encrypted/authenticated NVM key, the provided provision key(s) must have the same group owner as the imported NVM key.
 *     - To import an encrypted/authenticated NVM symmetric key using AEAD, the pointer to key info must be in the additional data
 *     - The key properties (keyInfo) along with the public key values are always imported in plain format.
 *  2. Restrictions for SuperUser rights:
 *     - NVM keys:
 *         - In empty slots, an encrypted key can be imported only authenticated, and a plain key can be imported
 *           with/without authentication (public keys must be imported in plain).
 *         - In non-empty slots, NVM keys can be imported(overwritten) in plain/encrypted, only authenticated.
 *     - RAM keys:
 *         - An encrypted key can be imported only authenticated. A plain key can be imported with/without authentication.
 *           Exception: RAM provision keys can be imported only authenticated.
 *  3. Restrictions for User rights:
 *     - NVM keys:
 *         - NVM secrets (symmetric keys and key pairs) can be imported only encrypted and authenticated.
 *           For key pair, private value must be encrypted and public value(s) unencrypted.
 *           NVM secrets imported from a signed key container MUST include the key properties (keyInfo) in the container
 *           (the provided key counter must be bigger than the previous one).
 *         - NVM public keys can be imported in plain, only authenticated.
 *           NVM public key imported from a signed key container can/cannot include the keyInfo in the container.
 *     - RAM keys:
 *         - An encrypted key can be imported only authenticated. A plain key can be imported with/without authentication.
 *         - key pairs can be imported only authenticated; private value encrypted and public value(s) unencrypted
 *         - public keys can be imported in plain, only authenticated.
 *  @note
 *     - The key catalogs must have been formatted prior to provisioning the keys.
 *     - When AEAD is used to import a key, the container cannot be used.
 *     - The key types *_PUB_EXT are stored in plain in the application NVM. For these key types, HSE stores only the key
 *       properties and the pointers to the public key values, as well as an authentication tag calculated over the key container:
 *       the authentication tag is verified by the HSE firmware whenever the related key is used by the host.
 *     - For HSE_H/M devices, the SYS-IMAGE does not have to be written to application NVM after each key import operation; the SYS-IMAGE update
 *       process can be done at the end of the configuration process.
 **/
typedef struct
{
    /** @brief   INPUT: Specifies the slot where to add or updated a key.
     *                  Note that the keyHandle identifies the key catalog, key group index and key slot index */
    hseKeyHandle_t      targetKeyHandle;
    /** @brief   INPUT: Specifies usage flags, restriction access, key length in bits, etc for the key (see hseKeyInfo_t).
     *                  @note
     *                        - Only keys that are not write protected can be updated with this service.
     *                        - NVM keys are secured against replay attacks by including a counter value stored within HSE.
     *                          The anti-replay attack counter included in the key info header should be greater than
     *                          the counter of the HSE key that will be updated (in case of key update).
     *                          This mean that keyInfo MUST be included in the signed key container (when the Life Cycle is IN_FIELD).
     *                        - For RAM keys the key counter is ignored (keyInfo may not be in the key container). */
    HOST_ADDR           pKeyInfo;
    /** @brief   INPUT: Pointer to key values.
     *           A RSA private key should always be imported together with the public key.
     *           An ECC private key can be imported standalone if the public key (pKey[0]) is NULL and
     *           the public key length (keyLen[0]) is zero. The public key will be computed internally from
     *           the private key.
     *           - pKey[0]:
     *              - RSA public modulus n (big-endian).
     *              - ECC depends on the key format
     *                  - Weierstrass curve keys:
     *                      - raw format: X || Y, in big endian; keyLen[0] must be 2 * #HSE_BITS_TO_BYTES(keyBitLength)
     *                      - uncompressed format: 0x04 || X || Y, in big endian; keyLen[0] must be 1 + 2 * #HSE_BITS_TO_BYTES(keyBitLength)
     *                      - compressed format: 0x02 / x03 || X,  in big endian; keyLen[0] must be 1 + #HSE_BITS_TO_BYTES(keyBitLength)
     *                  - Twisted Edwards curve keys:
     *                      - raw format: point Y with the sign bit of X, in big endian; keyLen[0] must be #HSE_BITS_TO_BYTES(keyBitLength)
     *                  - Montgomery curve keys:
     *                      - raw format: the X coordinate, in big endian; keyLen[0] must be #HSE_BITS_TO_BYTES(keyBitLength)
     *              - Classic DH prime modulus p
     *           - pKey[1]:
     *              - RSA public exponent e (big-endian).
     *              - Classic DH public key
     *           - pKey[2]:
     *              - RSA private exponent d (big-endian).
     *              - ECC/ED25519 private scalar (big-endian).
     *              - The symmetric key (e.g AES, HMAC).
     *              - Classic DH private key
     */
    HOST_ADDR       pKey[3];
    /** @brief   INPUT: The length in bytes for the above key values in the same order. <br>
     *                  Note that keyInfo.keyBitLen specifies the key length in bits.*/
    uint16_t        keyLen[3];
    uint8_t         reserved[2];
    /** @brief   INPUT: Cipher parameters are used only if the cipherKeyHandle is not #HSE_INVALID_KEY_HANDLE.
     *                  @note
     *                  - For AES-block cipher, if the keyBitLen is not multiple of AES block size (128bits), the key value have to be padded with zeros.
     *                  - For RSAES NO PADDING, the keyBitLen of the imported key must be less than or equal to #HSE_BITS_TO_BYTES(cipherKey_keyBitLen), and the key is considered a big-endian integer.
     *                  - For RSAES-PKCS1-v1_5, the keyBitLen of the imported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) -11 bytes.
     *                  - For RSAES-OAEP, the keyBitLen of the imported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) - 2 * hashLen - 2 bytes.
    */
    struct
    {
        /** @brief   INPUT: Decryption key handle.
         *                  The cipherKeyHandle can only be a provisioning key (#HSE_KF_USAGE_KEY_PROVISION and #HSE_KF_USAGE_DECRYPT flags are set). <br>
         *                  Note that the key handle identifies the cipher scheme below.
         *                  In case of symmetric cipher scheme and authenticated encryption scheme(AEAD) the differentiation is made using the first byte of cipherScheme.
         *                  Must be set to #HSE_INVALID_KEY_HANDLE if not used. */
        hseKeyHandle_t    cipherKeyHandle;
        /** @brief Symmetric, asymmetric  and AEAD cipher scheme.
                   @note
                   - Only the private keys are encrypted. */
        hseCipherScheme_t cipherScheme;
    }cipher;

    /** @brief   INPUT: The keyContainer parameters should be used if the key comes in a signed key container: pointers to key values
     *                  within the key container should be provided. The signature/tag is assumed to be done over the key container.
     *           @note
     *              - For NVM keys having User rights, the keyInfo MUST be included in the key container.
     *              - If the HOST is authorized (SU rights), the *_PUB_EXT key type can be imported from an unauthenticated key container (providing the key container without the signature). */
    struct
    {
        /** @brief   INPUT: The container length.
         *           @note  The container includes only the signed block (without the signature). */
        uint16_t          keyContainerLen;
        uint8_t           reserved[2];
        /** @brief   INPUT: Address of the key container; includes the key value(s) and other information used to authenticate the key.
         *                  (e.g. TBSCertificate for a X.509 certificate). */
        HOST_ADDR         pKeyContainer;
        /** @brief   INPUT: Authentication key handle (#HSE_KF_USAGE_KEY_PROVISION and #HSE_KF_USAGE_VERIFY flags are set).
         *                  Must be set to #HSE_INVALID_KEY_HANDLE if not used. An encrypted key can be imported only authenticated.*/
        hseKeyHandle_t    authKeyHandle;
        /** @brief   INPUT: Authentication scheme. <br>
         *                  Note that the key handle identifies the authentication scheme below.
         *           @note  For the GMAC scheme, the minimum IV length is 12 bytes.*/
        hseAuthScheme_t   authScheme;
        /** @brief   INPUT: Byte length(s) of the authentication tag(s).
         *                   @note
         *                   - For MAC and RSA signature, only authLen[0] is used.
         *                   - Both lengths are used for (R,S) (ECC or ED25519).
         *                   - The MAC tag size must be minimum 16 bytes.
         *                   - RSA signature size must be #HSE_BITS_TO_BYTES(keyBitLength);
         *                   - R or S size for ECDSA/EdDSA signature must be #HSE_BITS_TO_BYTES(keyBitLength) */
        uint16_t          authLen[2];
        /** @brief   INPUT: Address(es) to authentication tag.
         *                   @note
         *                   - For MAC and RSA signature,  only pAuth[0] is used.
         *                   - Both pointers are used for (R,S) (ECC or ED25519). */
        HOST_ADDR         pAuth[2];
    }keyContainer;
    /** @brief   INPUT: Additional information about the format of the key. Key type specific. */
    hseKeyFormat_t     keyFormat;
} hseImportKeySrv_t;


/** @brief   HSE Export Key Service.
 *  @details The key values and the key properties (optional) can be exported to the host via a key export service.
 *
 *  1. Common key restrictions (which apply for both SuperUser and User rights):
 *     - Key flags (of key properties) are always applied; this service can only be used if the key is exportable.
 *     - Provision/Authorization keys are NOT exportable (#HSE_KF_ACCESS_EXPORTABLE flag is ignored).
 *     - NVM keys can not be exported using RAM provision keys.
 *     - NVM/RAM symmetric keys can be exported only encrypted with/without authentication.
 *     - NVM/RAM public keys (from key pair or public key slots) can be exported in plain; keys may/may not be authenticated.
 *     - The private part of a key pair can NOT be exported (the private part is never disclosed to the host).
 *     - _PUB_EXT can NOT be exported.
 *     - To export an encrypted/authenticated NVM key, the provided provision key must have the same group owner as the exported NVM key (not applicable for RAM keys).
 *     - When AEAD is used to export a key, the container cannot be used.
 */
typedef struct
{
    /** @brief   INPUT: The key handle to be exported.  <br>
     *                  Note that the keyHandle identifies the key catalog, key group index and key slot index */
    hseKeyHandle_t      targetKeyHandle;
    /** @brief   OUTPUT: Export the key information (see hseKeyInfo_t).
     *                   @note
     *                   - For symmetric keys exported in an authenticated key container, key information MUST be part of the key container;
     *                   - For symmetric keys exported authenticated with AEAD, key information MUST be part of AAD (see hseAeadScheme_t);
     *                   - For public keys this parameter is optional. It can be NULL. */
    HOST_ADDR           pKeyInfo;
    /** @brief   OUTPUT: Addresses where to fill to key values.
     *           - pKey[0]:
     *              - RSA public modulus n.
     *              - ECC depends on the key format
     *                  - Weierstrass curve keys:
     *                      - raw format: X || Y, in big endian; the HSE will output 2 * #HSE_BITS_TO_BYTES(keyBitLength) bytes
     *                      - uncompressed format: 0x04 || X || Y, in big endian; the HSE will output 1 + 2 * #HSE_BITS_TO_BYTES(keyBitLength) bytes
     *                      - compressed format: 0x02 / x03 || X,  in big endian; the HSE will output 1 + #HSE_BITS_TO_BYTES(keyBitLength) bytes
     *                  - Twisted Edwards curve keys:
     *                      - raw format: point Y with the sign bit of X, in big endian; the HSE will output #HSE_BITS_TO_BYTES(keyBitLength) bytes
     *                  - Montgomery curve keys:
     *                      - raw format: the X coordinate, in big endian; the HSE will output #HSE_BITS_TO_BYTES(keyBitLength) bytes
     *              - Classic DH prime modulus p
     *           - pKey[1]:
     *              - RSA public exponent e.
     *              - Classic DH public key
     *           - pKey[2]:
     *              - The symmetric key (e.g AES, HMAC).
     *              - Classic DH private key
     */
    HOST_ADDR          pKey[3];
    /** @brief   INPUT/OUTPUT: Addressed of uint16_t values of the length (in bytes) for the above buffers (INPUT).
     *                         As output, it provides the lengths of the encrypted or unencrypted (only for public) keys. <br>
     *                         Note that the length in bits of the key is specified by hseKeyInfo_t.
     */
    HOST_ADDR          pKeyLen[3];

    /** @brief   INPUT: Cipher parameters.
     *                  @note
     *                  - Only the private keys are encrypted and the encrypted value length is specified by the corresponding private key length (in bytes).
     *                  - For AES-block cipher, if the keyBitLen of the exported is not multiple of AES block size (128bits), the key value will be padded with zeros.
     *                  - For RSAES NO PADDING, the keyBitLen of the exported key must be less than or equal to #HSE_BITS_TO_BYTES(cipherKey_keyBitLen), and the key is considered a big-endian integer.
     *                  - For RSAES-PKCS1-v1_5, the keyBitLen of the exported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) -11 bytes.
     *                  - For RSAES-OAEP, the keyBitLen of the exported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) - 2 * hashLen - 2 bytes.
     * */
    struct
    {
        /** @brief   INPUT: Encryption key handle.
         *                  The cipherKeyHandle can only be a provisioning key (#HSE_KF_USAGE_KEY_PROVISION and #HSE_KF_USAGE_ENCRYPT flags are set). <br>
         *                  Note that the key handle will identifies the cipher scheme below.
         *                  Must be set to #HSE_INVALID_KEY_HANDLE if not used. */
        hseKeyHandle_t    cipherKeyHandle;
        /** @brief Symmetric, asymmetric  and AEAD cipher scheme.
                   @note
                   - Only the private keys are encrypted.*/
        hseCipherScheme_t cipherScheme;
    }cipher;

    /** @brief   INPUT: The keyContainer parameters should be used when the key have to be exported in a key container that will be authenticated:
     *                  pointers to where key values will be exported should be provided within the key container. Optionally,
     *                  the pKeyInfo may point inside the key container. The signature/tag is done over the key container. */
    struct
    {
        /** @brief   INPUT: The container length.
         *           @note  The key container length is the size of the byte block to be signed (without the signature). */
        uint16_t          keyContainerLen;
        uint8_t           reserved[2];
        /** @brief   INPUT: Address of the key container; includes the key value(s) and other information used to authenticate the key.
         *                  (e.g. TBSCertificate for a X.509 certificate). */
        HOST_ADDR         pKeyContainer;
        /** @brief   INPUT: Authentication key handle (#HSE_KF_USAGE_KEY_PROVISION and #HSE_KF_USAGE_SIGN flags are set). <br>
         *                  Note that the key handle identifies the authentication scheme below.
         *                  Must be set to HSE_INVALID_KEY_HANDLE if not used. */
        hseKeyHandle_t    authKeyHandle;
        /** @brief   INPUT: Authentication scheme.
         *           @note  For the GMAC scheme, the minimum IV length is 12 bytes. */
        hseAuthScheme_t   authScheme;
        /** @brief   OUTPUT: Address(es) for the length(s) (uin16_t values) of the authentication tag.
         *                   @note
         *                   - For MAC and RSA signature,  only pAuthLen[0] is used.
         *                   - Both lengths are used for (R,S) (ECC or ED25519). */
        HOST_ADDR         pAuthLen[2];
        /** @brief   OUTPUT: Address of authentication tag.
         *                   @note
         *                   - For MAC and RSA signature,  only pAuth[0] is used.
         *                   - Both pointers are used for (R,S) (ECC or ED25519). */
        HOST_ADDR         pAuth[2];
    }keyContainer;
    /** @brief   INPUT: Additional information about the format of the key. Key type specific. */
    hseKeyFormat_t     keyFormat;
} hseExportKeySrv_t;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_KEY_IMPORT_EXPORT_H */

/** @} */
