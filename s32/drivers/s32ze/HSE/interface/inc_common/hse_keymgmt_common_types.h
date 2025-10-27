/**
*   @file    hse_keymgmt_common_types.h
*
*   @brief   HSE Key Management Common types.
*   @details This file contains the Key Management Common types definition.
*
*   @addtogroup hse_keymgmt_common_types HSE Key Management Common Types
*   @ingroup class_key_management
*   @{
*/
/*==================================================================================================
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

#ifndef HSE_KEYMGMT_COMMON_TYPES_H
#define HSE_KEYMGMT_COMMON_TYPES_H


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
/** @brief   HSE key catalog type.
 *  @details A key catalog is a memory container that holds groups of keys.
 *           The catalog defines the type of storage (volatile / non-volatile) and the visibility to the application (host) */
typedef uint8_t hseKeyCatalogId_t;
#define HSE_KEY_CATALOG_ID_ROM        ((hseKeyCatalogId_t)0U)    /**< @brief ROM key catalog (NXP keys) */
#define HSE_KEY_CATALOG_ID_NVM        ((hseKeyCatalogId_t)1U)    /**< @brief NVM key catalog */
#define HSE_KEY_CATALOG_ID_RAM        ((hseKeyCatalogId_t)2U)    /**< @brief RAM key catalog */

/** @brief All keys used in cryptographic operations are referenced by a unique key handle.
 *         The key handle is a 32-bit integer: the key catalog(byte2), group index in catalog (byte1) and key slot index (byte0).
 *         It can be retrieved  based on the catalog ID, the group index and its slot index within the group.
 *         The group index is between 0 and (n-1), where n is the maximum number of groups defined in the catalog
 *         The slot index is between 0 and (p-1), where p is the maximum number of keys defined in the group */
#define GET_KEY_HANDLE(catalogId, groupIdx, slotIdx) \
                      ((((hseKeyHandle_t)((hseKeyCatalogId_t)(catalogId))) << 16U) | \
                       (((hseKeyHandle_t)((hseKeyGroupIdx_t)(groupIdx))) << 8U) | \
                       (((hseKeyHandle_t)((hseKeySlotIdx_t)(slotIdx)))))

#define GET_CATALOG_ID(keyHandle)     ((hseKeyCatalogId_t)(((keyHandle) >> 16U) & 0xFFU)) /**< @brief Get key catalog Id. */
#define GET_GROUP_IDX(keyHandle)      ((hseKeyGroupIdx_t)(((keyHandle) >> 8U) & 0xFFU))   /**< @brief Get key group index. */
#define GET_SLOT_IDX(keyHandle)       ((hseKeySlotIdx_t)((keyHandle) & 0xFFU))            /**< @brief Get key slot index. */

#define HSE_INVALID_KEY_HANDLE        ((hseKeyHandle_t)0xFFFFFFFFUL)   /**< @brief HSE invalid key . */
#define HSE_INVALID_GROUP_IDX         ((hseKeyGroupIdx_t)0xFFU)        /**< @brief HSE invalid key group index. */
#define HSE_INVALID_SLOT_IDX          ((hseKeySlotIdx_t)0xFFU)         /**< @brief HSE invalid key slot index. */


/** @brief HSE Key Group owner */
typedef uint8_t hseKeyGroupOwner_t;

/** @brief The key are owned by ANY owner. This applies only for RAM key groups.
 *         The RAM keys can be installed/updated by any owner (CUST or OEM) having SuperUser or User rights. */
#define HSE_KEY_OWNER_ANY             ((hseKeyGroupOwner_t)0U)

/** @brief The key are owned by OWNER_CUST. This applies only for NVM key groups. <br>
 *         The CUST keys can be installed/updated as follow:
 *          - using CUST SuperUser rights (if Life Cycle = CUST_DEL or if the host was granted with CUST SuperUser rights).
 *          - using User rights (Life Cycle = IN_FIELD) */
#define HSE_KEY_OWNER_CUST            ((hseKeyGroupOwner_t)1U)

/** @brief The key groups owned by OWNER_OEM. This applies only for NVM key groups. <br>
 *         The OEM keys can be installed/updated as follow:
 *          - using OEM SuperUser rights (if Life Cycle = OEM_PROD or if the host was granted with OEM SuperUser rights).
 *          - using User rights (Life Cycle = IN_FIELD) */
#define HSE_KEY_OWNER_OEM             ((hseKeyGroupOwner_t)2U)

/** @brief HSE Key type.
  *       Specifies the Key type. It provides information about the interpretation of key data. */
typedef uint8_t hseKeyType_t;
#define HSE_KEY_TYPE_SHE              ((hseKeyType_t)0x11U)            /**< @brief Symmetric AES128 key used with SHE specification commands.
                                                                                 It can be used with any AES block ciphering mode and AES MACs (same as any AES128 key). */
#define HSE_KEY_TYPE_AES              ((hseKeyType_t)0x12U)            /**< @brief Symmetric AES key or AES OTFAD key */
#define HSE_KEY_TYPE_HMAC             ((hseKeyType_t)0x20U)            /**< @brief Symmetric HMAC key */
#define HSE_KEY_TYPE_SHARED_SECRET    ((hseKeyType_t)0x30U)            /**< @brief Shared secret used by DH key exchange protocols */
#define HSE_KEY_TYPE_SIPHASH          ((hseKeyType_t)0x40U)            /**< @brief Symmetric SipHash key */
#define HSE_KEY_TYPE_ECC_PAIR         ((hseKeyType_t)0x87U)            /**< @brief ECC key pair (private and public) */
#define HSE_KEY_TYPE_ECC_PUB          ((hseKeyType_t)0x88U)            /**< @brief ECC Public key */
#define HSE_KEY_TYPE_ECC_PUB_EXT      ((hseKeyType_t)0x89U)            /**< @brief ECC public keys, where the key value is stored in the application area (e.g. certificate) */
#define HSE_KEY_TYPE_RSA_PAIR         ((hseKeyType_t)0x97U)            /**< @brief RSA key pair (private and public key) */
#define HSE_KEY_TYPE_RSA_PUB          ((hseKeyType_t)0x98U)            /**< @brief RSA Public key */
#define HSE_KEY_TYPE_RSA_PUB_EXT      ((hseKeyType_t)0x99U)            /**< @brief RSA public keys, where the key value is stored in the application area (e.g. certificate) */
#define HSE_KEY_TYPE_DH_PAIR          ((hseKeyType_t)0xA7U)            /**< @brief DH key pair */
#define HSE_KEY_TYPE_DH_PUB           ((hseKeyType_t)0xA8U)            /**< @brief DH public key */


/** @brief    The key flags specifies the operations or restrictions that can be apply to a key. */
typedef uint16_t hseKeyFlags_t;
#define HSE_KF_USAGE_ENCRYPT          ((hseKeyFlags_t)1U << 0U)     /**< @brief Key is used to encrypt data. If the HSE_KF_USAGE_KEY_PROVISION flag is set, the key can not be used for data encryption (only for key encryption). */
#define HSE_KF_USAGE_DECRYPT          ((hseKeyFlags_t)1U << 1U)     /**< @brief Key is used to decrypt data. If the HSE_KF_USAGE_KEY_PROVISION flag is set, the key can not be used for data decryption (only for key decryption).*/
#define HSE_KF_USAGE_SIGN             ((hseKeyFlags_t)1U << 2U)     /**< @brief Key is used to generate digital signatures or MACs of any data
                                                                     *          (including keys if HSE_KF_USAGE_KEY_PROVISION is set).*/
#define HSE_KF_USAGE_VERIFY           ((hseKeyFlags_t)1U << 3U)     /**< @brief Key is used to verify digital signatures or MACs of any data
                                                                     *          (including keys if HSE_KF_USAGE_KEY_PROVISION is set).*/
#define HSE_KF_USAGE_EXCHANGE         ((hseKeyFlags_t)1U << 4U)     /**< @brief Key is used for key exchange protocol (e.g. DH).*/
#define HSE_KF_USAGE_DERIVE           ((hseKeyFlags_t)1U << 5U)     /**< @brief Key may be use as a base key for deriving other keys. */
#define HSE_KF_USAGE_KEY_PROVISION    ((hseKeyFlags_t)1U << 6U)     /**< @brief Key used for key provisioning operation. The provision keys can only be NVM keys.
                                                                     *          This bit (if it is set) along with the encrypt/decrypt/sign/verify flags
                                                                     *           specifies which operations can be performed on a key using this key (provisioning key). */
#define HSE_KF_USAGE_AUTHORIZATION    ((hseKeyFlags_t)1U << 7U)     /**< @brief Key can be used for system authorization. Can be set only for NVM keys.
                                                                     *          This key should have the verify flag set, but the sign flag NOT set. */
#define HSE_KF_USAGE_SMR_DECRYPT      ((hseKeyFlags_t)1U << 8U)     /**< @brief The key is used for SMR decryption. If this bit is set during key installation, the HSE will set the HSE_KF_USAGE_DECRYPT flag to zero. */
#define HSE_KF_ACCESS_WRITE_PROT      ((hseKeyFlags_t)1U << 9U)     /**< @brief The key is write protected and cannot change anymore. For RAM keys, this flag is forced to zero. */
#define HSE_KF_ACCESS_DEBUG_PROT      ((hseKeyFlags_t)1U << 10U)    /**< @brief The key is disabled when a debugger is attached. For RAM keys, this flag is forced to zero. */
#define HSE_KF_ACCESS_EXPORTABLE      ((hseKeyFlags_t)1U << 11U)    /**< @brief The key can be exported or not in any format. Ignored when used in combination with
                                                                    *          HSE_KF_USAGE_KEY_PROVISION or HSE_KF_USAGE_AUTHORIZATION (provision/authorization keys are NOT exportable). */
#define HSE_KF_USAGE_XTS_TWEAK        ((hseKeyFlags_t)1U << 12U)    /**< @brief This is used as a tweak key in xts aes encryption; no other flag shall be set */
#define HSE_KF_USAGE_OTFAD_DECRYPT    ((hseKeyFlags_t)1U << 13U)    /**< @brief The key is used just in OTFAD decryption; no other flag shall be set*/

/** @brief    The Key Usage flags mask. */
#define HSE_KF_USAGE_MASK   \
       (HSE_KF_USAGE_ENCRYPT | HSE_KF_USAGE_DECRYPT | HSE_KF_USAGE_SIGN | HSE_KF_USAGE_VERIFY | HSE_KF_USAGE_EXCHANGE | \
        HSE_KF_USAGE_DERIVE | HSE_KF_USAGE_KEY_PROVISION | HSE_KF_USAGE_AUTHORIZATION | HSE_KF_USAGE_SMR_DECRYPT |      \
        HSE_KF_USAGE_XTS_TWEAK | HSE_KF_USAGE_OTFAD_DECRYPT)

/** @brief    The Key Usage flags mask for Managed Security Component (MSC) targeted keys.
 *            The accepted key flags for keys that are configured in Key Handle Translation Table (KHTT) for MSC keystore.
 *            These key flags can be configured only with HSE_KF_USAGE_ENCRYPT, HSE_KF_USAGE_DECRYPT, HSE_KF_USAGE_SIGN or HSE_KF_USAGE_VERIFY.
 */
#define HSE_KF_MSC_USAGE_MASK   \
       (HSE_KF_USAGE_ENCRYPT | HSE_KF_USAGE_DECRYPT | HSE_KF_USAGE_SIGN | HSE_KF_USAGE_VERIFY)

/** @brief    The Key Access flags mask. */
#define HSE_KF_ACCESS_MASK  (HSE_KF_ACCESS_WRITE_PROT | HSE_KF_ACCESS_DEBUG_PROT | HSE_KF_ACCESS_EXPORTABLE)

/** @brief    The maximum value of key counter. Note that 0xFFFFFFFF is reserved for RAM keys. */
#define HSE_KF_MAX_KEY_COUNTER_VALUE    ((uint32_t)0xFFFFFFFFUL - 1UL)

/**  HSE ROM key handles.
  *  The ROM key catalog references keys that are provisioned by NXP and can be used by the host.
  *
  *  @note
  *       - The ROM keys have the following access restriction flags set:
  *      \code
  *
  *             (#HSE_KF_ACCESS_WRITE_PROT | #HSE_KF_ACCESS_DEBUG_PROT)
  *
  *      \endcode
  */

/** @brief  This key can be used for data encryption/decryption, having the following usage restrictions:
 *  @note
 *        - This key is a device-specific secret
 *        - This key can be used to encrypt/decrypt application data with a device-specific key
 * \code
 *
 * (#HSE_KF_USAGE_ENCRYPT | #HSE_KF_USAGE_DECRYPT)
 *
 * \endcode */
#define HSE_ROM_KEY_AES256_KEY0       ((hseKeyHandle_t)0x00000000UL)

/** @brief This key can be used for key derivation and key provisioning, having the following usage restrictions:
 *  @note
 *       - This key is a shared secret owned by NXP
 *       - It can be used during key provision to import an application key encrypted with an NXP secret
 *       - This NXP key can be used to encrypt a customer key using an email service provided by NXP. In this way, the customer key can be injected in HSE
 *         sub-system in a secure manner. Contact NXP support team for more details.
 *       - The service is used in pair with another RSA key. The email service provides a signature which is verified using the RSA key.
 * \code
 *
 * (#HSE_KF_USAGE_DERIVE | #HSE_KF_USAGE_VERIFY | #HSE_KF_USAGE_DECRYPT | #HSE_KF_USAGE_KEY_PROVISION)
 *
 * \endcode */
#define HSE_ROM_KEY_AES256_KEY1       ((hseKeyHandle_t)0x00000001UL)

#if defined(HSE_SPT_NXP_RFE_SW)
/** @brief This key can be used for the decryption of NXP RFE image, having the following usage restrictions:
 * \code
 *
 * (#HSE_KF_USAGE_SMR_DECRYPT | #HSE_KF_USAGE_VERIFY)
 *
 * \endcode */
#define HSE_ROM_KEY_AES256_KEY2       ((hseKeyHandle_t)0x00000002UL)
#endif /* HSE_SPT_NXP_RFE_SW */

/** @brief This key can be used for RSA decryption and signature verify, having the following usage restrictions:
 *  @note
 *       - This key is a public RSA key owned by NXP; the corresponding private key is owned by NXP.
 *       - It can be used during key provision to import an application key signed.
 *       - This NXP key can be used to verify a signature on a customer key which is signed using an email service provided by NXP. In this way, the customer key can be injected in HSE
 *         sub-system in a secure manner. Contact NXP support team for more details.
 *       - The service is used in pair with another ROM key i.e HSE_ROM_KEY_AES256_KEY1.
 * \code
 *
 * (#HSE_KF_USAGE_DECRYPT | #HSE_KF_USAGE_VERIFY | #HSE_KF_USAGE_KEY_PROVISION)
 *
 * \endcode */
#define HSE_ROM_KEY_RSA3072_PUB_KEY0  ((hseKeyHandle_t)0x00000100UL)

#if defined(HSE_SPT_NXP_RFE_SW)
/** @brief This key can be used for RSA signature verification of NXP RFE image, having the following usage restrictions:
 * \code
 *
 * (#HSE_KF_USAGE_VERIFY)
 *
 * \endcode */
#define HSE_ROM_KEY_RSA2048_PUB_KEY1  ((hseKeyHandle_t)0x00000101UL)
#endif /* HSE_SPT_NXP_RFE_SW */

/** @brief This key can be used for key provisioning having the following usage restrictions:
 *  @note
 *       - This key is a public ECC key owned by NXP; the corresponding private key owned by NXP.
 *       - It can be used during key provision to import an application key signed using an NXP ECC public key.
 *       - This NXP key can be used to sign a customer key using an email service provided by NXP. In this way, the customer key can be injected in HSE
 *         sub-system in a secure manner. Contact NXP for more details.
 * \code
 *
 * (#HSE_KF_USAGE_VERIFY | #HSE_KF_USAGE_KEY_PROVISION)
 *
 * \endcode */
#define HSE_ROM_KEY_ECC256_PUB_KEY0   ((hseKeyHandle_t)0x00000200UL)

/** @brief   The SMR flags.
 *  @details A set of flags that define which secure memory region (SMR),
 *           shall be verified before the key can be used.
 *           For RAM keys, the SMR flags are forced to zero (not used). */
typedef uint32_t hseSmrFlags_t;
#define HSE_KF_SMR_0                  ((hseSmrFlags_t)1UL << 0UL)
#define HSE_KF_SMR_1                  ((hseSmrFlags_t)1UL << 1UL)
#define HSE_KF_SMR_2                  ((hseSmrFlags_t)1UL << 2UL)
#define HSE_KF_SMR_3                  ((hseSmrFlags_t)1UL << 3UL)
#define HSE_KF_SMR_4                  ((hseSmrFlags_t)1UL << 4UL)
#define HSE_KF_SMR_5                  ((hseSmrFlags_t)1UL << 5UL)
#define HSE_KF_SMR_6                  ((hseSmrFlags_t)1UL << 6UL)
#define HSE_KF_SMR_7                  ((hseSmrFlags_t)1UL << 7UL)
#define HSE_KF_SMR_8                  ((hseSmrFlags_t)1UL << 8UL)
#define HSE_KF_SMR_9                  ((hseSmrFlags_t)1UL << 9UL)
#define HSE_KF_SMR_10                 ((hseSmrFlags_t)1UL << 10UL)
#define HSE_KF_SMR_11                 ((hseSmrFlags_t)1UL << 11UL)
#define HSE_KF_SMR_12                 ((hseSmrFlags_t)1UL << 12UL)
#define HSE_KF_SMR_13                 ((hseSmrFlags_t)1UL << 13UL)
#define HSE_KF_SMR_14                 ((hseSmrFlags_t)1UL << 14UL)
#define HSE_KF_SMR_15                 ((hseSmrFlags_t)1UL << 15UL)
#define HSE_KF_SMR_16                 ((hseSmrFlags_t)1UL << 16UL)
#define HSE_KF_SMR_17                 ((hseSmrFlags_t)1UL << 17UL)
#define HSE_KF_SMR_18                 ((hseSmrFlags_t)1UL << 18UL)
#define HSE_KF_SMR_19                 ((hseSmrFlags_t)1UL << 19UL)
#define HSE_KF_SMR_20                 ((hseSmrFlags_t)1UL << 20UL)
#define HSE_KF_SMR_21                 ((hseSmrFlags_t)1UL << 21UL)
#define HSE_KF_SMR_22                 ((hseSmrFlags_t)1UL << 22UL)
#define HSE_KF_SMR_23                 ((hseSmrFlags_t)1UL << 23UL)
#define HSE_KF_SMR_24                 ((hseSmrFlags_t)1UL << 24UL)
#define HSE_KF_SMR_25                 ((hseSmrFlags_t)1UL << 25UL)
#define HSE_KF_SMR_26                 ((hseSmrFlags_t)1UL << 26UL)
#define HSE_KF_SMR_27                 ((hseSmrFlags_t)1UL << 27UL)
#define HSE_KF_SMR_28                 ((hseSmrFlags_t)1UL << 28UL)
#define HSE_KF_SMR_29                 ((hseSmrFlags_t)1UL << 29UL)
#define HSE_KF_SMR_30                 ((hseSmrFlags_t)1UL << 30UL)
#define HSE_KF_SMR_31                 ((hseSmrFlags_t)1UL << 31UL)

/** @brief The ECC curve IDs*/
typedef uint8_t hseEccCurveId_t;
#define HSE_EC_CURVE_NONE                 ((hseEccCurveId_t)0U)
#define HSE_EC_SEC_SECP256R1              ((hseEccCurveId_t)1U)
#define HSE_EC_SEC_SECP384R1              ((hseEccCurveId_t)2U)
#define HSE_EC_SEC_SECP521R1              ((hseEccCurveId_t)3U)
#define HSE_EC_BRAINPOOL_BRAINPOOLP256R1  ((hseEccCurveId_t)4U)
#define HSE_EC_BRAINPOOL_BRAINPOOLP320R1  ((hseEccCurveId_t)5U)
#define HSE_EC_BRAINPOOL_BRAINPOOLP384R1  ((hseEccCurveId_t)6U)
#define HSE_EC_BRAINPOOL_BRAINPOOLP512R1  ((hseEccCurveId_t)7U)
#define HSE_EC_25519_ED25519              ((hseEccCurveId_t)9U)
#define HSE_EC_25519_CURVE25519           ((hseEccCurveId_t)10U)
#define HSE_EC_448_ED448                  ((hseEccCurveId_t)11U)
#define HSE_EC_448_CURVE448               ((hseEccCurveId_t)12U)

/* The curve IDs that can be set at init time */
#define HSE_EC_USER_CURVE1                ((hseEccCurveId_t)101U)
#define HSE_EC_USER_CURVE2                ((hseEccCurveId_t)102U)
#define HSE_EC_USER_CURVE3                ((hseEccCurveId_t)103U)

/** @brief    Some default key bits values.
 *  @details  The below values are only only a few possible values.
 *            Note that HSE supports key bit length different than those defined below (eg. TU Darmstadt curves 1 to 38). */
typedef uint16_t hseKeyBits_t;
#define HSE_KEY_BITS_INVALID          ((hseKeyBits_t)0xFFFFU)
#define HSE_KEY_BITS_ZERO             ((hseKeyBits_t)0U)
#define HSE_KEY64_BITS                ((hseKeyBits_t)64U)
#define HSE_KEY128_BITS               ((hseKeyBits_t)128U)
#define HSE_KEY160_BITS               ((hseKeyBits_t)160U)
#define HSE_KEY192_BITS               ((hseKeyBits_t)192U)
#define HSE_KEY224_BITS               ((hseKeyBits_t)224U)
#define HSE_KEY240_BITS               ((hseKeyBits_t)240U)
#define HSE_KEY256_BITS               ((hseKeyBits_t)256U)
#define HSE_KEY320_BITS               ((hseKeyBits_t)320U)
#define HSE_KEY384_BITS               ((hseKeyBits_t)384U)
#define HSE_KEY512_BITS               ((hseKeyBits_t)512U)
#define HSE_KEY521_BITS               ((hseKeyBits_t)521U)
#define HSE_KEY638_BITS               ((hseKeyBits_t)638U)
#define HSE_KEY1024_BITS              ((hseKeyBits_t)1024U)
#define HSE_KEY2048_BITS              ((hseKeyBits_t)2048U)
#define HSE_KEY3072_BITS              ((hseKeyBits_t)3072U)
#define HSE_KEY4096_BITS              ((hseKeyBits_t)4096U)

/** @brief    Cipher modes flags for AES keys
 *  @details  The values below are representing the cipher mode flags that an AES key can take. */
typedef uint8_t hseAesBlockModeMask_t;
#define HSE_KU_AES_BLOCK_MODE_ANY     ((hseAesBlockModeMask_t)0U)                                   /**< @brief Any block mode below */
#define HSE_KU_AES_BLOCK_MODE_XTS     ((hseAesBlockModeMask_t)(1U << 0U))                           /**< @brief XTS mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_CTR     ((hseAesBlockModeMask_t)(1U << HSE_CIPHER_BLOCK_MODE_CTR))    /**< @brief CTR mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_CBC     ((hseAesBlockModeMask_t)(1U << HSE_CIPHER_BLOCK_MODE_CBC))    /**< @brief CBC mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_ECB     ((hseAesBlockModeMask_t)(1U << HSE_CIPHER_BLOCK_MODE_ECB))    /**< @brief ECB mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_CFB     ((hseAesBlockModeMask_t)(1U << HSE_CIPHER_BLOCK_MODE_CFB))    /**< @brief CFB mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_OFB     ((hseAesBlockModeMask_t)(1U << HSE_CIPHER_BLOCK_MODE_OFB))    /**< @brief OFB mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_CCM     ((hseAesBlockModeMask_t)(1U << 6U))                           /**< @brief CCM mode (AES) */
#define HSE_KU_AES_BLOCK_MODE_GCM     ((hseAesBlockModeMask_t)(1U << 7U))                           /**< @brief GCM mode (AES) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** @brief    The entry of the Key Catalog Configuration
 *  @details  The size of a key slot is computed internally based on keytype and maxKeyBitLen.
 *            @note A key group (catalog entry) contains keys that have the same key type and the keybitLen <= maxKeyBitLen.
 *  */
typedef struct
{
    hseMuMask_t        muMask;          /**< @brief Specifies the MU Instance(s) for the key group. A key group can belong to one ore more MUs. */
    hseKeyGroupOwner_t groupOwner;      /**< @brief Specifies the key group owner. */
    hseKeyType_t       keyType;         /**< @brief The key type (see #hseKeyType_t). */
    uint8_t            numOfKeySlots;   /**< @brief The number of key slots. */
    uint16_t           maxKeyBitLen;    /**< @brief The maximum length of the key (in bits). All stored keys have keyBitLen <= maxKeyBitLen. */
    uint8_t            hseReserved[2];  /**< @brief HSE reserved */
} hseKeyGroupCfgEntry_t;


/** @brief   Key properties
 *  @details Each cryptographic key material will be based on key properties (info) and key data */
typedef struct
{
    hseKeyFlags_t keyFlags;         /**< @brief The key flags (see #hseKeyFlags_t) */

    /** @brief The length of key in bits.
     * - For RSA, bit length of modulus n
     * - For ECC, the bit length of the base point order.
     * - Any other key, the bit length of the key. */
    uint16_t      keyBitLen;

    /** @brief The key counter used to prevent the rollback attacks on the key. <br>
     *         For NVM keys, the key counter must be between 0 and #HSE_KF_MAX_KEY_COUNTER_VALUE
     *         For RAM keys, the key counter is forced to 0xFFFFFFFF (not used).
     *         @note
     *         The key counter for SHE keys follows the SHE specification (e.g. key counter is 28bits;
     *         for SHE RAM keys, the key counter is forced to zero). */
    uint32_t      keyCounter;

    /** @brief A set of flags that define which secure memory region (SMR),
     *         indexed from 0 to 31, should be verified before the
     *         key can be used. Set to zero means not used. <br>
     *         For RAM keys, the SMR flags are forced to zero (not used).
     *         Keys linked with SMR(s) that are not yet present in the system
     *         will be available until these SMR(s) are successfully installed. */
    hseSmrFlags_t smrFlags;
    hseKeyType_t  keyType;                   /**< @brief The key type (see #hseKeyType_t). */

    union
    {
        hseEccCurveId_t         eccCurveId;          /**< @brief The ECC curve Id used with this key. This is used only for ECC key type */
        uint8_t                 pubExponentSize;     /**< @brief The size (in bytes) of the RSA public exponent (e); it should be less than 16 bytes. */
        hseAesBlockModeMask_t   aesBlockModeMask;    /**< @brief The cipher mode usage for an AES key. This is used only for AES key type
                                                                 If aesBlockModeMask == 0, any AES block mode can be used */
    }specific;
    uint8_t          hseReserved[2U];
} hseKeyInfo_t;


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

#endif /* HSE_KEYMGMT_COMMON_TYPES_H */

/** @} */
