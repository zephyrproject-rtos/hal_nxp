/**
*   @file    hse_common_types.h
*
*   @brief   HSE types used by other interface services' types
*   @details This file contains the types used by other interface services' types
*
*   @addtogroup hse_common_types HSE Common Types
*   @ingroup class_common_types
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

#ifndef HSE_COMMON_TYPES_H
#define HSE_COMMON_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "std_typedefs.h"
#include "hse_platform.h"
#include "hse_defs.h"

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

/** @brief Absolute maximum HSE service descriptor size.
 *         This is determined by the HSE-HOST shared memory size, the number of MUs and the number of channels per MU.*/
#define HSE_MAX_DESCR_SIZE                  (256U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief    HSE Message Unite (MU) masks */
typedef uint8_t hseMuMask_t;
#define HSE_MU0_MASK                 ((hseMuMask_t)1U << 0U) /**< @brief MU Instance 0 */
#define HSE_MU1_MASK                 ((hseMuMask_t)1U << 1U) /**< @brief MU Instance 1 */
#if HSE_NUM_OF_MU_INSTANCES > 2
#define HSE_MU2_MASK                 ((hseMuMask_t)1U << 2U) /**< @brief MU Instance 2 */
#define HSE_MU3_MASK                 ((hseMuMask_t)1U << 3U) /**< @brief MU Instance 3 */
#if HSE_NUM_OF_MU_INSTANCES > 4
#define HSE_MU4_MASK                 ((hseMuMask_t)1U << 4U) /**< @brief MU Instance 2 */
#define HSE_MU5_MASK                 ((hseMuMask_t)1U << 5U) /**< @brief MU Instance 3 */
#define HSE_MU6_MASK                 ((hseMuMask_t)1U << 6U) /**< @brief MU Instance 2 */
#define HSE_MU7_MASK                 ((hseMuMask_t)1U << 7U) /**< @brief MU Instance 3 */
#endif
#endif


/** @brief    Mask for all MU Instances */
#if HSE_NUM_OF_MU_INSTANCES == 2
#define HSE_ALL_MU_MASK              (HSE_MU0_MASK | HSE_MU1_MASK)
#elif HSE_NUM_OF_MU_INSTANCES == 4
#define HSE_ALL_MU_MASK              (HSE_MU0_MASK | HSE_MU1_MASK | HSE_MU2_MASK | HSE_MU3_MASK)
#else
#define HSE_ALL_MU_MASK              (HSE_MU0_MASK | HSE_MU1_MASK | HSE_MU2_MASK | HSE_MU3_MASK | \
                                      HSE_MU4_MASK | HSE_MU5_MASK | HSE_MU6_MASK | HSE_MU7_MASK )
#endif

/** @brief   HSE Scatter-Gather Option .
 *  @details Specifies if the input or output data is provided a scatter list (see hseScatterList_t).
 *           @note The remaining bit are ignored when SGT option is used.*/
typedef uint8_t hseSGTOption_t;
#define HSE_SGT_OPTION_NONE      ((hseSGTOption_t)0U)       /**< @brief Scatter list is not used.*/
#define HSE_SGT_OPTION_INPUT     ((hseSGTOption_t)1U << 0U) /**< @brief Input pointer is provided a scatter list.*/
#define HSE_SGT_OPTION_OUTPUT    ((hseSGTOption_t)1U << 1U) /**< @brief Output pointer is provided a scatter list.*/
/** @brief    Mask for input/output scatter-gatther option */
#define HSE_SGT_OPTION_INPUT_OUTPUT_MASK (HSE_SGT_OPTION_INPUT | HSE_SGT_OPTION_OUTPUT)

/** @brief   Scatter-gather Final chunk BIT.
 *           This bit is set in the "length" field of the chunk (see hseScatterList_t).*/
#define HSE_SGT_FINAL_CHUNK_BIT_MASK (0x40000000UL)

/** @brief    HSE access modes.*/
typedef uint8_t hseAccessMode_t;
#define HSE_ACCESS_MODE_ONE_PASS     ((hseAccessMode_t)0U)      /**< @brief ONE-PASS access mode */
#define HSE_ACCESS_MODE_START        ((hseAccessMode_t)1U)      /**< @brief START access mode  */
#define HSE_ACCESS_MODE_UPDATE       ((hseAccessMode_t)2U)      /**< @brief UPDATE access mode  */
#define HSE_ACCESS_MODE_FINISH       ((hseAccessMode_t)3U)      /**< @brief FINISH access mode  */

/** @brief   HASH algorithm types.*/
typedef uint8_t hseHashAlgo_t;
#define HSE_HASH_ALGO_NULL           ((hseHashAlgo_t)0U)         /**< @brief None */
#define HSE_HASH_RESERVED1           ((hseHashAlgo_t)1U)         /**< @brief Reserved (MD5 obsolete) */
#define HSE_HASH_ALGO_SHA_1          ((hseHashAlgo_t)2U)         /**< @brief SHA1 hash */
#define HSE_HASH_ALGO_SHA2_224       ((hseHashAlgo_t)3U)         /**< @brief SHA2_224 hash */
#define HSE_HASH_ALGO_SHA2_256       ((hseHashAlgo_t)4U)         /**< @brief SHA2_256 hash */
#define HSE_HASH_ALGO_SHA2_384       ((hseHashAlgo_t)5U)         /**< @brief SHA2_384 hash */
#define HSE_HASH_ALGO_SHA2_512       ((hseHashAlgo_t)6U)         /**< @brief SHA2_512 hash */
#define HSE_HASH_ALGO_SHA2_512_224   ((hseHashAlgo_t)7U)         /**< @brief SHA2_512_224 hash */
#define HSE_HASH_ALGO_SHA2_512_256   ((hseHashAlgo_t)8U)         /**< @brief SHA2_512_256 hash */
#define HSE_HASH_ALGO_SHA3_224       ((hseHashAlgo_t)9U)         /**< @brief SHA3_224 hash */
#define HSE_HASH_ALGO_SHA3_256       ((hseHashAlgo_t)10U)        /**< @brief SHA3_256 hash */
#define HSE_HASH_ALGO_SHA3_384       ((hseHashAlgo_t)11U)        /**< @brief SHA3_384 hash */
#define HSE_HASH_ALGO_SHA3_512       ((hseHashAlgo_t)12U)        /**< @brief SHA3_512 hash */
#define HSE_HASH_ALGO_MP             ((hseHashAlgo_t)13U)        /**< @brief Miyaguchi-Preneel compression using AES-ECB with 128-bit key size (SHE spec support). */


/** @brief    Symmetric Cipher Algorithms .*/
typedef uint8_t hseCipherAlgo_t;
#define HSE_CIPHER_ALGO_NULL         ((hseCipherAlgo_t)0x00U)     /**< @brief NULL cipher */
#define HSE_CIPHER_ALGO_AES          ((hseCipherAlgo_t)0x10U)     /**< @brief AES cipher */


/** @brief    Symmetric Cipher Block Modes */
typedef uint8_t hseCipherBlockMode_t;
#define HSE_CIPHER_BLOCK_MODE_NULL   ((hseCipherBlockMode_t)0U)   /**< @brief NULL cipher */
#define HSE_CIPHER_BLOCK_MODE_CTR    ((hseCipherBlockMode_t)1U)   /**< @brief CTR mode (AES) */
#define HSE_CIPHER_BLOCK_MODE_CBC    ((hseCipherBlockMode_t)2U)   /**< @brief CBC mode (AES) */
#define HSE_CIPHER_BLOCK_MODE_ECB    ((hseCipherBlockMode_t)3U)   /**< @brief ECB mode (AES) */
#define HSE_CIPHER_BLOCK_MODE_CFB    ((hseCipherBlockMode_t)4U)   /**< @brief CFB mode (AES) */
#define HSE_CIPHER_BLOCK_MODE_OFB    ((hseCipherBlockMode_t)5U)   /**< @brief OFB mode (AES) */


/** @brief   HSE cipher direction: encryption/decryption */
typedef uint8_t hseCipherDir_t;
#define HSE_CIPHER_DIR_DECRYPT       ((hseCipherDir_t)0U)         /**< @brief Decrypt */
#define HSE_CIPHER_DIR_ENCRYPT       ((hseCipherDir_t)1U)         /**< @brief Encrypt */


/** @brief   HSE Authenticated cipher/encryption mode (only AES supported). */
typedef uint8_t hseAuthCipherMode_t;
#define HSE_AUTH_CIPHER_MODE_CCM     ((hseAuthCipherMode_t)0x11U)  /**< @brief CCM mode */
#define HSE_AUTH_CIPHER_MODE_GCM     ((hseAuthCipherMode_t)0x12U)  /**< @brief GCM mode */


/** @brief   HSE authentication direction: generate/verify.*/
typedef uint8_t hseAuthDir_t;
#define HSE_AUTH_DIR_VERIFY          ((hseAuthDir_t)0U)            /**< @brief Verify authentication tag */
#define HSE_AUTH_DIR_GENERATE        ((hseAuthDir_t)1U)            /**< @brief Generate authentication tag */


/** @brief   HSE MAC algorithm.*/
typedef uint8_t hseMacAlgo_t;
#define HSE_MAC_ALGO_CMAC            ((hseMacAlgo_t)0x11U)         /**< @brief CMAC (AES)*/
#define HSE_MAC_ALGO_GMAC            ((hseMacAlgo_t)0x12U)         /**< @brief GMAC (AES)*/
#define HSE_MAC_ALGO_XCBC_MAC        ((hseMacAlgo_t)0x13U)         /**< @brief XCBC MAC (AES128) */
#define HSE_MAC_ALGO_HMAC            ((hseMacAlgo_t)0x20U)         /**< @brief HMAC */

/** @brief   Signature scheme enumeration.*/
typedef uint8_t hseSignSchemeEnum_t;
#define HSE_SIGN_ECDSA                ((hseSignSchemeEnum_t)0x80U) /**< @brief ECDSA signature scheme */
#define HSE_SIGN_EDDSA                ((hseSignSchemeEnum_t)0x81U) /**< @brief EdDSA signature scheme */
#define HSE_SIGN_RSASSA_PKCS1_V15     ((hseSignSchemeEnum_t)0x93U) /**< @brief RSASSA_PKCS1_V15 signature scheme */
#define HSE_SIGN_RSASSA_PSS           ((hseSignSchemeEnum_t)0x94U) /**< @brief RSASSA_PSS signature scheme */


/** @brief   RSA algorithm types.*/
typedef uint8_t hseRsaAlgo_t;
#define HSE_RSA_ALGO_NO_PADDING        ((hseRsaAlgo_t)0x90U)        /**< @brief The input will be treated as an unsigned integer and perform a modular exponentiation of the input  */
#define HSE_RSA_ALGO_RSAES_OAEP        ((hseRsaAlgo_t)0x91U)        /**< @brief RSAES OAEP cipher */
#define HSE_RSA_ALGO_RSAES_PKCS1_V15   ((hseRsaAlgo_t)0x92U)        /**< @brief ECDSA RSAES_PKCS1_V15 cipher */

#ifdef HSE_SPT_FLASHLESS_DEV /* HSE_H/M device */
/** @brief   The application core IDs (that can be started).
             Only the IDs for the table below must be provided for a specific platform; otherwise an error will be reported.

    Core assignment table:

    | CoreID | S32G2XX | S32R45| S32R41      | SAF85XX     |S32G3XX  | S32ZE             |
    |-------:|:-------:|:-----:|:-----------:|:-----------:|:-------:|:-----------------:|
    |   0    | M7_0    | M7_0  | M7_0        | M7_0        | M7_0    | M33 (SMU)         |
    |   1    | M7_1    | M7_1  | M7_1        | M7_1(RFE)   | M7_1    | LLCE_0(CE M33_0)* |
    |   2    | M7_2    | M7_2  | A53_0       | A53_0       | M7_2    | LLCE_1(CE M33_1)* |
    |   3    | A53_0   | A53_0 | BBE32EP DSP | BBE32EP DSP | M7_3    | CEVA_SPF2*        |
    |   4    | A53_1   | A53_1 |             |             | A53_0   | R52_0             |
    |   5    | A53_2   | A53_2 |             |             | A53_1   | R52_1             |
    |   6    | A53_3   | A53_3 |             |             | A53_2   | R52_2             |
    |   7    | LLCE_0* |       |             |             | A53_3   | R52_3             |
    |   8    | LLCE_1* |       |             |             | A53_4   | R52_4             |
    |   9    | LLCE_2* |       |             |             | A53_5   | R52_5             |
    |  10    | LLCE_3* |       |             |             | A53_6   | R52_6             |
    |  11    |         |       |             |             | A53_7   | R52_7             |
    |  12    |         |       |             |             | LLCE_0* |                   |
    |  13    |         |       |             |             | LLCE_1* |                   |
    |  14    |         |       |             |             | LLCE_2* |                   |
    |  15    |         |       |             |             | LLCE_3* |                   |
@note: The cores marked with "*" are currently not supported to be loaded by the HSE FW
*/
#else /* HSE_B device */
/** @brief   The application core IDs (that can be started).
             Only the IDs for the table below must be provided for a specific platform; otherwise an error will be reported.

    Core assignment table:

    | CoreID | S32K311 | S32K312| S32K342 | S32K344 | S32K396 | S32K358  | S32K388 |
    |-------:|:-------:|:------:|:-------:|:-------:|:-------:|:--------:|:-------:|
    |   0    | M7_0    | M7_0   | M7_0    | M7_0    | M7_0    | M7_0     | M7_0    |
    |   1    |         |        | M7_1    | M7_1    | M7_1    | M7_1     | M7_1    |
    |   2    |         |        |         |         | M7_2    | M7_2     | M7_2    |
    |   3    |         |        |         |         |         |          | M7_3    |
*/
#endif /* HSE_SPT_FLASHLESS_DEV */

typedef uint8_t hseAppCore_t;
#define HSE_APP_CORE0        ((hseAppCore_t)0U)    /**< @brief Core0 */
#define HSE_APP_CORE1        ((hseAppCore_t)1U)    /**< @brief Core1 */
#define HSE_APP_CORE2        ((hseAppCore_t)2U)    /**< @brief Core2 */
#define HSE_APP_CORE3        ((hseAppCore_t)3U)    /**< @brief Core3 */
#define HSE_APP_CORE4        ((hseAppCore_t)4U)    /**< @brief Core4 */
#define HSE_APP_CORE5        ((hseAppCore_t)5U)    /**< @brief Core5 */
#define HSE_APP_CORE6        ((hseAppCore_t)6U)    /**< @brief Core6 */
#define HSE_APP_CORE7        ((hseAppCore_t)7U)    /**< @brief Core7 */
#define HSE_APP_CORE8        ((hseAppCore_t)8U)    /**< @brief Core8 */
#define HSE_APP_CORE9        ((hseAppCore_t)9U)    /**< @brief Core9 */
#define HSE_APP_CORE10       ((hseAppCore_t)10U)   /**< @brief Core10 */
#define HSE_APP_CORE11       ((hseAppCore_t)11U)   /**< @brief Core11 */
#define HSE_APP_CORE12       ((hseAppCore_t)12U)   /**< @brief Core12 */
#define HSE_APP_CORE13       ((hseAppCore_t)13U)   /**< @brief Core13 */
#define HSE_APP_CORE14       ((hseAppCore_t)14U)   /**< @brief Core14 */
#define HSE_APP_CORE15       ((hseAppCore_t)15U)   /**< @brief Core15 */

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** @brief    HSE Service IDs.*/
typedef uint32_t hseSrvId_t;

/** @brief Stream ID type.
  * @details The stream ID identifies the stream to be used in streaming operations. */
typedef uint8_t hseStreamId_t;

/** @brief Key Handle type.
  * @details The keyHandle identifies the key catalog(byte2), group index in catalog(byte1) and key slot index (byte0) */
typedef uint32_t hseKeyHandle_t;

/** @brief   HSE key group index.
 *  @details A group represents a set of keys of the same type.
 *           Each group is identified by its index within the catalog where it is declared*/
typedef uint8_t hseKeyGroupIdx_t;

/** @brief   HSE key slot index.
 *  @details A key slot represent a memory container for a single key.
 *           A group contains several key slots as defined during the key configuration */
typedef uint8_t hseKeySlotIdx_t;

/**
 * @brief   HSE service metadata.
 * @details Each service has a metadata (e.g. priority) */
typedef struct
{
    uint8_t             reserved[4]; /**< @brief For future use. */
} hseSrvMetaData_t;


/** @brief  No scheme (or parameters) are defined. */
typedef uint32_t hseNoScheme_t;


/** @brief RSAES OAEP Scheme.
 *  @details  Includes parameters needed for RSAES OAEP encryption/ decryption. */
typedef struct
{
    /** @brief   INPUT: The Hash algorithm for RSA OAEP padding. */
    hseHashAlgo_t   hashAlgo;
    uint8_t         reserved[3];
    /** @brief   INPUT: Optional OAEP label length (it can be 0). Must be less than 128. */
    uint32_t        labelLength;
    /** @brief   INPUT: Optional OAEP label (it can be NULL if label length is 0). Must be less than 128 bytes long. */
    HOST_ADDR       pLabel;
}hseRsaOAEPScheme_t;


/** @brief ECDSA signature scheme.
 *  @details  Includes parameters needed for ECDSA signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: The hash algorithm used to hash the input before applying the ECDSA operation.
     *           Must not be #HSE_HASH_ALGO_NULL. */
    hseHashAlgo_t   hashAlgo;

    uint8_t         reserved[3];
}hseEcdsaScheme_t;


/** @brief EDDSA signature scheme.
 *  @details  Includes parameters needed for EDDSA signature generate/verify. 
 * 
 *  EdDSA signature mode vs. EdDDA sign scheme parameters:
 * |EdDSA signature mode | EdDsa sign scheme parameters                         |
 * |--------------------:|:----------------------------------------------------:|
 * | PureEdDSA           | bHashEddsa == FALSE && contextLength/pContext == 0   |
 * | Context             | bHashEddsa == FALSE && contextLength/pContext != 0   |
 * | HashEdDSA           | bHashEddsa == TRUE                                   |
 * 
 * */
typedef struct
{
    /** @brief   INPUT: Whether to pre-hash the input, and perform a HashEddsa signature. */
    bool_t          bHashEddsa;

    /** @brief   INPUT: The length of the EDDSA context. Length of zero means no context. */
    uint8_t         contextLength;

    uint8_t         reserved[2];

    /** @brief   INPUT: The EDDSA context. Ignored if contextLength is zero.
     *           Must remain unchanged until the signing operation is finished (especially in streaming),
     *           or the signature will be incorrect */
    HOST_ADDR       pContext;
}hseEddsaSignScheme_t;


/** @brief RSASSA_PSS signature scheme.
 *  @details  Includes parameters needed for RSASSA_PSS signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: The hash algorithm used to hash the input before applying the RSA operation.
     *           Must not be #HSE_HASH_ALGO_NULL. */
    hseHashAlgo_t   hashAlgo;

    uint8_t         reserved[3];

    /** @brief   INPUT: The length of the salt in bytes. It must fulfill one of the following conditions:
     *                    - 0 <= saltLength <= 62 if the key length is 128 bytes and SHA-512 is used as hash algorithm;
     *                    - 0 <= saltLength <= hashLength otherwise, where hashLength denotes the output length of the chosen hash algorithm.

     */
    uint32_t        saltLength;
}hseRsaPssSignScheme_t;


/** @brief RSASSA_PKCS1_V15 signature scheme.
 *  @details  Includes parameters needed for RSASSA_PKCS1_V15 signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: The hash algorithm
     *           Must not be HSE_HASH_ALGO_NULL. */
    hseHashAlgo_t   hashAlgo;

    uint8_t         reserved[3];
}hseRsaPkcs1v15Scheme_t;


/** @brief The HSE signature scheme.
 *  @details  Includes parameters needed for signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: Signature scheme.*/
    hseSignSchemeEnum_t        signSch;
    uint8_t                    reserved[3];
    /** @brief   INPUT: Additional information for selected Signature scheme. */
    union
    {
        /** @brief   INPUT: ECDSA signature scheme. */
        hseEcdsaScheme_t       ecdsa;
        /** @brief   INPUT: EDDSA signature scheme. */
        hseEddsaSignScheme_t   eddsa;
        /** @brief   INPUT: RSA PSS signature scheme. */
        hseRsaPssSignScheme_t  rsaPss;
        /** @brief   INPUT: RSASSA_PKCS1_V15 signature scheme. */
        hseRsaPkcs1v15Scheme_t rsaPkcs1v15;
    }sch;
}hseSignScheme_t;


/** @brief HSE symmetric cipher scheme.
 *  @details Includes parameters needed for a symmetric cipher.
 */
typedef struct
{
    /** @brief   INPUT: Select an symmetric cipher. */
    hseCipherAlgo_t         cipherAlgo;
    /** @brief   INPUT: Specifies the cipher block mode. */
    hseCipherBlockMode_t    cipherBlockMode;
    uint8_t                 reserved[2];
    /** @brief   INPUT: Initialization Vector length(at least 16 bytes). */
    uint32_t                ivLength;
    /** @brief   INPUT: Initialization Vector/Nonce. */
    HOST_ADDR               pIV;
} hseSymCipherScheme_t;

typedef struct
{
    /** @brief   INPUT: Specifies the authenticated cipher mode. */
    hseAuthCipherMode_t     authCipherMode;
    uint8_t                 reserved[1];
    /** @brief   INPUT: Specifies the tag length. */
    uint16_t                tagLength;
    /** @brief   INPUT: Tag pointer. */
    HOST_ADDR                pTag;
    /** @brief   INPUT: Initialization Vector length(at least 12 bytes). */
    uint32_t                ivLength;
    /** @brief   INPUT: Initialization Vector/Nonce. */
    HOST_ADDR               pIV;
    /** @brief   INPUT: The length of Additional Data (in bytes). Can be zero. */
    uint32_t                aadLength;
    /** @brief   INPUT: The AAD Header data. Ignored if aadLength is zero. */
    HOST_ADDR               pAAD;
} hseAeadScheme_t;


/**
* @brief          RSA cipher scheme.
* @details        Performs the RSA encryption/decryption).
*/
typedef struct
{
    /** @brief   INPUT: RSA algorithm. */
    hseRsaAlgo_t             rsaAlgo;
    uint8_t                  reserved[3];
    /** @brief   INPUT: Scheme for selected RSA algorithm. */
    union
    {
        /** @brief   INPUT: RSA-OAEP scheme. */
        hseRsaOAEPScheme_t   rsaOAEP;
        /** @brief   INPUT: No scheme for RSA-PKCS1V15. */
        hseNoScheme_t        rsaPkcs1v15;
    }sch;
}hseRsaCipherScheme_t;


/** @brief HSE Cipher scheme.
 *  @details Includes parameters needed for symmetric cipher/RSA encryption and decryption.
 */
typedef union
{
    /** @brief   INPUT: Symmetric cipher scheme. */
    hseSymCipherScheme_t      symCipher;
    /** @brief   INPUT: Authenticated encryption scheme (AEAD-GCM/CCM). */
    hseAeadScheme_t           aeadCipher;
    /** @brief   INPUT: RSA cipher scheme. */
    hseRsaCipherScheme_t      rsaCipher;
}hseCipherScheme_t;

/** @brief CMAC scheme.
 *  @details  Includes parameters needed for CMAC tag generation/verification. */
typedef struct
{
    /** @brief   INPUT: Select a cipher algorithm for CMAC. */
    hseCipherAlgo_t    cipherAlgo;
    uint8_t            reserved[3];
} hseCmacScheme_t;


/** @brief HMAC scheme.
 *  @details  Includes parameters needed for HMAC tag generation/verification. */
typedef struct
{
    /** @brief   INPUT: Specifies the hash algorithm for HMAC. SHA3 and Miyaguchi-Preneel are not supported for HMAC */
    hseHashAlgo_t      hashAlgo;
    uint8_t            reserved[3];
} hseHmacScheme_t;

/** @brief GMAC scheme (AES only).
 *  @details  Includes parameters needed for GMAC tag generation/verification. */
typedef struct
{
    /** @brief   INPUT: Initialization Vector length. Zero is not allowed. Recommended 12 bytes or greater. */
    uint32_t           ivLength;

    /** @brief   INPUT: Initialization Vector/Nonce. */
    HOST_ADDR          pIV;
} hseGmacScheme_t;

/** @brief HSE MAC scheme.
 *  @details Includes parameters needed for MAC computation.
 */
typedef struct
{
    /** @brief   INPUT: Select an MAC algorithm. */
    hseMacAlgo_t      macAlgo;
    uint8_t           reserved[3];
    /** @brief   INPUT: The scheme (or parameters) for the selected mac algorithm. */
    union
    {
        /** @brief   INPUT: CMAC scheme (AES). */
        hseCmacScheme_t        cmac;
        /** @brief   INPUT: HMAC scheme. */
        hseHmacScheme_t        hmac;
        /** @brief   INPUT: GMAC scheme. Supports only AES. */
        hseGmacScheme_t        gmac;
        /** @brief   INPUT: No scheme parameters; supports only AES128. */
        hseNoScheme_t          xCbcmac;
    }sch;
} hseMacScheme_t;

/** @brief HSE authentication scheme.
 *  @details Includes parameters needed for authentication.
 */
typedef union
{
    /** @brief   INPUT: MAC scheme. */
    hseMacScheme_t    macScheme;
    /** @brief   INPUT: Signature scheme. */
    hseSignScheme_t   sigScheme;
} hseAuthScheme_t;

/** @brief   HSE Scatter List .
 *  @details The input and output data can be provided as a scatter list.
             A scatter list is used when the input/output is not a continuous buffer (the buffer is spread across multiple memory locations).
             The input and output pointers are specified as a list of entries as below. */
#ifdef HSE_SPT_SGT_OPTION
typedef struct
{
    uint32_t       length;         /**< @brief The length of the chunk. Maximum size must be less than 2^30.
                                        The final chunk from scatter list must have bit30 set to 1 (e.g. length = chunk_len | #HSE_SGT_FINAL_CHUNK_BIT_MASK) */
    HOST_ADDR      pPtr;           /**< @brief  Pointer to the chunk. */
}hseScatterList_t;
#endif /* HSE_SPT_SGT_OPTION */
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

#endif /* HSE_COMMON_TYPES_H */

/** @} */
