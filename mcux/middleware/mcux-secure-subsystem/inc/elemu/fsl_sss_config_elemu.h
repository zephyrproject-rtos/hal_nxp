/*
 * Copyright 2018-2021, 2024-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSS_CONFIG_ELEMU_H
#define FSL_SSS_CONFIG_ELEMU_H

#include <stdint.h>
#include "fsl_common.h"

#if defined(K32W1480_SERIES) || defined(KW45B41Z52_SERIES) || defined(KW45B41Z53_SERIES) ||         \
    defined(KW45B41Z82_SERIES) || defined(KW45B41Z83_SERIES) || defined(KW45Z41052_SERIES) ||       \
    defined(KW45Z41053_SERIES) || defined(KW45Z41082_SERIES) || defined(KW45Z41083_SERIES) ||       \
    defined(KW45B41Z82_NBU_SERIES) || defined(KW45B41Z83_NBU_SERIES) || defined(MCXW716A_SERIES) || \
    defined(MCXW716C_SERIES)

#define ELE200_BASELINE (1)

#if defined(CONFIG_ELE_TRACK_SESSION_STATE) /* toggled via Kconfig */
/**
 * @def ELE_TRACK_SESSION_STATE
 * Keeps track of the session state during runtime and emulates KW47/MCXW72 behavior.
 *
 * On KW45/MCXW71 devices, we want to be able to repeatedly open the same
 * sessions, just like on KW47/MCXW72.
 * So we emulate the same behavior as if we were repeatedly calling
 * OPEN SESSION with a non-zero ID on KW47/MCXW72, which just returns the
 * already-open session context.
 */
#define ELE_TRACK_SESSION_STATE (1)
#endif /* CONFIG_ELE_TRACK_SESSION_STATE */

/* MAC */
#define ELE_FEATURE_HMAC_SHA256_ONLY (1)

/* KDF extensions via FW */
#define ELE_FEATURE_MAC_KDF          (1)

#elif defined(KW47B42Z83_cm33_core0_SERIES) || defined(KW47B42Z83_cm33_core1_SERIES) ||                             \
    defined(KW47B42Z96_cm33_core0_SERIES) || defined(KW47B42Z96_cm33_core1_SERIES) ||                               \
    defined(KW47B42Z97_cm33_core0_SERIES) || defined(KW47B42Z97_cm33_core1_SERIES) ||                               \
    defined(KW47B42ZB2_cm33_core0_SERIES) || defined(KW47B42ZB2_cm33_core1_SERIES) ||                               \
    defined(KW47B42ZB3_cm33_core0_SERIES) || defined(KW47B42ZB3_cm33_core1_SERIES) ||                               \
    defined(KW47B42ZB6_cm33_core0_SERIES) || defined(KW47B42ZB6_cm33_core1_SERIES) ||                               \
    defined(KW47B42ZB7_cm33_core0_SERIES) || defined(KW47B42ZB7_cm33_core1_SERIES) || defined(KW47Z420B2_SERIES) || \
    defined(KW47Z420B3_SERIES) || defined(KW47Z42082_SERIES) || defined(KW47Z42092_SERIES) ||                       \
    defined(MCXW727A_cm33_core0_SERIES) || defined(MCXW727A_cm33_core1_SERIES) ||                                   \
    defined(MCXW727C_cm33_core0_SERIES) || defined(MCXW727C_cm33_core1_SERIES) ||                                   \
    defined(MCXW727D_cm33_core0_SERIES) || defined(MCXW727D_cm33_core1_SERIES) ||                                   \
    defined(MCXW728A_cm33_core0_SERIES) || defined(MCXW728A_cm33_core1_SERIES) ||                                   \
    defined(MCXW728D_cm33_core0_SERIES) || defined(MCXW728D_cm33_core1_SERIES) ||                                   \
    defined(MCXW72B1_cm33_core0_SERIES) || defined(MCXW72B1_cm33_core1_SERIES) ||                                   \
    defined(MCXW72BD_cm33_core0_SERIES) || defined(MCXW72BD_cm33_core1_SERIES)

/* Can be used to differentiate KW47 from KW45. Shall not be enabled on KW45 */
#define ELE200_EXTENDED_FEATURES                      (1)

/* DIGEST */
#define ELE_HAVE_SHA3                                 (1)
#define ELE_FEATURE_DIGEST_CLONE                      (1)
#define ELE_FEATURE_DIGEST_IMPORT                     (1)
#define ELE_FEATURE_DIGEST_EXPORT                     (1)
#define ELE_FEATURE_DIGEST_CONTEXT_BLOB_SIZE_IN_BYTES (412u)

/* MAC */
#define ELE_FEATURE_MAC_MULTIPART                     (1)
#define ELE_FEATURE_MAC_IMPORT                        (1)
#define ELE_FEATURE_MAC_EXPORT                        (1)
#define ELE_FEATURE_MAC_CONTEXT_BLOB_SIZE_IN_BYTES    (384u)

/* Key Derivation */
#define ELE_FEATURE_SPAKE2PLUS                        (1)
#define ELE_FEATURE_MAC_KDF                           (1)

/* Open Key features */
#define ELE_FEATURE_OPEN_KEY_NPX                      (1)
#define ELE_FEATURE_OPEN_KEY_DKEY                     (1)
#define ELE_FEATURE_OPEN_KEY_BRIC                     (1)

/* PQC */
#define ELE_MLDSA_WORK_AREA_BUFFER_SIZE               (9528u)

#else
#error "No valid SoC defined"
#endif /* defined(K32W1480_SERIES) ..... defined(MCXW72BD_cm33_core1_SERIES) */

/* We extend HMAC features for base KW47 and for KW45 EL2GO FW */
#if !defined(ELE_FEATURE_HMAC_SHA256_ONLY) || defined(ELEMU_HAS_LOADABLE_FW)
#define ELE_FEATURE_EXTENDED_HMAC (1)
#endif

#define SSS_SESSION_MAX_CONTEXT_SIZE      (16)
#define SSS_KEY_STORE_MAX_CONTEXT_SIZE    (16 + 80)
#define SSS_KEY_OBJECT_MAX_CONTEXT_SIZE   (16)
#define SSS_SYMMETRIC_MAX_CONTEXT_SIZE    (16 + 80)
#define SSS_AEAD_MAX_CONTEXT_SIZE         (16)
#define SSS_DIGEST_MAX_CONTEXT_SIZE       (16 + 80)
#define SSS_MAC_MAX_CONTEXT_SIZE          (16 + 16)
#define SSS_ASYMMETRIC_MAX_CONTEXT_SIZE   (16)
#define SSS_TUNNEL_MAX_CONTEXT_SIZE       (16)
#define SSS_DERIVE_KEY_MAX_CONTEXT_SIZE   (16)
#define SSS_RNG_MAX_CONTEXT_SIZE          (16)
#define SSS_PH_CLSHA_CTX_MAX_CONTEXT_SIZE (216)

#define SSS_TYPE_ENUM_ALT
typedef uint32_t sss_type_t;
#define kType_SSS_Software      ((sss_type_t)0x00u)
#define kType_SSS_SECO          ((sss_type_t)0x01u)
#define kType_SSS_Ele200        ((sss_type_t)0x02u)
#define kType_SSS_Ele300        ((sss_type_t)0x03u)
#define kType_SSS_Ele400        ((sss_type_t)0x04u)
#define kType_SSS_Ele500        ((sss_type_t)0x05u)
#define kType_SSS_SecureElement ((sss_type_t)0x06u)

#define SSS_MODE_ENUM_ALT
typedef uint32_t sss_mode_t;
#define kMode_SSS_Encrypt             ((sss_mode_t)0x00u)
#define kMode_SSS_Decrypt             ((sss_mode_t)0x01u)
#define kMode_SSS_Sign                ((sss_mode_t)0x02u)
#define kMode_SSS_Verify              ((sss_mode_t)0x03u)
#define kMode_SSS_ComputeSharedSecret ((sss_mode_t)0x04u)
#define kMode_SSS_Digest              ((sss_mode_t)0x05u)
#define kMode_SSS_Mac                 ((sss_mode_t)0x06u)
#if defined(ELE200_EXTENDED_FEATURES)
#define kMode_SSS_SymmetricKDF ((sss_mode_t)0x07u)
#else
#define kMode_SSS_SymmetricKDF ((sss_mode_t)0x04u)
#endif /* ELE200_EXTENDED_FEATURES */
#define kMode_SSS_MlkemEncapsulate   ((sss_mode_t)0x08u)
#define kMode_SSS_MlkemDecapsulate   ((sss_mode_t)0x09u)

#define SSS_ALGORITHM_ENUM_ALT
typedef uint32_t sss_algorithm_t;
/* AES */
#define kAlgorithm_SSS_AES_ECB ((sss_algorithm_t)0x00u)
#define kAlgorithm_SSS_AES_CBC ((sss_algorithm_t)0x01u)
#define kAlgorithm_SSS_AES_CTR ((sss_algorithm_t)0x02u)
#define kAlgorithm_SSS_AES_GCM ((sss_algorithm_t)0x03u)
#define kAlgorithm_SSS_AES_CCM ((sss_algorithm_t)0x04u)
/* CHACHA_POLY */
#define kAlgorithm_SSS_CHACHA_POLY ((sss_algorithm_t)0x05u)
/* DES3 */
#define kAlgorithm_SSS_DES3_ECB ((sss_algorithm_t)0x06u)
#define kAlgorithm_SSS_DES3_CBC ((sss_algorithm_t)0x07u)
/* Digest */
#define kAlgorithm_SSS_SHA1   ((sss_algorithm_t)0x08u)
#define kAlgorithm_SSS_SHA224 ((sss_algorithm_t)0x09u)
#define kAlgorithm_SSS_SHA256 ((sss_algorithm_t)0x0au)
#define kAlgorithm_SSS_SHA384 ((sss_algorithm_t)0x0bu)
#define kAlgorithm_SSS_SHA512 ((sss_algorithm_t)0x0cu)
#if defined(ELE_HAVE_SHA3)
#define kAlgorithm_SSS_SHA3_224 ((sss_algorithm_t)0x70u)
#define kAlgorithm_SSS_SHA3_256 ((sss_algorithm_t)0x71u)
#define kAlgorithm_SSS_SHA3_384 ((sss_algorithm_t)0x72u)
#define kAlgorithm_SSS_SHA3_512 ((sss_algorithm_t)0x73u)
#endif /* ELE_HAVE_SHA3 */
#if defined(ELE200_EXTENDED_FEATURES)
/* ML-DSA Pre-Hashing Algorithm Extentions */
#define kAlgorithm_SSS_SHAKE128   ((sss_algorithm_t)0x74u) /*!< Only usable with ML-DSA Pre-Hash mode */
#define kAlgorithm_SSS_SHAKE256   ((sss_algorithm_t)0x75u) /*!< Only usable with ML-DSA Pre-Hash mode */
#define kAlgorithm_SSS_MLDSA_Pure ((sss_algorithm_t)0x00u) /*!< Only usable with ML-DSA Pure mode */
#endif /* ELE200_EXTENDED_FEATURES */
/* MAC */
#define kAlgorithm_SSS_CMAC_AES    ((sss_algorithm_t)0x0du)
#define kAlgorithm_SSS_HMAC_SHA256 ((sss_algorithm_t)0x0eu)
#if defined(ELE_FEATURE_EXTENDED_HMAC)
#define kAlgorithm_SSS_HMAC_SHA1   ((sss_algorithm_t)0x60u)
#define kAlgorithm_SSS_HMAC_SHA224 ((sss_algorithm_t)0x61u)
#define kAlgorithm_SSS_HMAC_SHA384 ((sss_algorithm_t)0x63u)
#define kAlgorithm_SSS_HMAC_SHA512 ((sss_algorithm_t)0x64u)
#endif /* ELE_FEATURE_EXTENDED_HMAC */
/* Diffie-Helmann */
#define kAlgorithm_SSS_DH   ((sss_algorithm_t)0x0fu)
#define kAlgorithm_SSS_ECDH ((sss_algorithm_t)0x10u)
#define kAlgorithm_MONTDH   ((sss_algorithm_t)0x30u)
/* DSA */
#define kAlgorithm_SSS_DSA_SHA1   ((sss_algorithm_t)0x11u)
#define kAlgorithm_SSS_DSA_SHA224 ((sss_algorithm_t)0x12u)
#define kAlgorithm_SSS_DSA_SHA256 ((sss_algorithm_t)0x13u)
/* RSA */
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA1       ((sss_algorithm_t)0x14u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA224     ((sss_algorithm_t)0x15u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA256     ((sss_algorithm_t)0x16u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA384     ((sss_algorithm_t)0x17u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA512     ((sss_algorithm_t)0x18u)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA1   ((sss_algorithm_t)0x19u)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA224 ((sss_algorithm_t)0x1au)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA256 ((sss_algorithm_t)0x1bu)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA384 ((sss_algorithm_t)0x1cu)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA512 ((sss_algorithm_t)0x1du)
/* ECDSA */
#define kAlgorithm_SSS_ECDSA_SHA1    ((sss_algorithm_t)0x1eu)
#define kAlgorithm_SSS_ECDSA_SHA224  ((sss_algorithm_t)0x1fu)
#define kAlgorithm_SSS_ECDSA_SHA256  ((sss_algorithm_t)0x20u)
#define kAlgorithm_SSS_ECDSA_SHA384  ((sss_algorithm_t)0x21u)
#define kAlgorithm_SSS_ECDSA_SHA512  ((sss_algorithm_t)0x22u)
#define kAlgorithm_SSS_EdDSA_Ed25519 ((sss_algorithm_t)0x31u)
/* KDF */
#if defined(ELE_FEATURE_SPAKE2PLUS)
#define kAlgorithm_SSS_SPAKE2PLUS     ((sss_algorithm_t)0x23u) //!< Matter specification
#define kAlgorithm_SSS_SPAKE2PLUS_CCC ((sss_algorithm_t)0x24u) //!< CCC specification
#endif /* ELE_FEATURE_SPAKE2PLUS */
#define kAlgorithm_SSS_AES_ECB_KDF ((sss_algorithm_t)0x00u)
#define kAlgorithm_SSS_E2E_BLOB    ((sss_algorithm_t)0x40u)
#define kAlgorithm_SSS_BLE_F5      ((sss_algorithm_t)0x50u)
#if defined(ELE_FEATURE_MAC_KDF)
#define kAlgorithm_SSS_CKDF                ((sss_algorithm_t)0x51u)
#define kAlgorithm_SSS_HKDF_SHA1_EXTRACT   ((sss_algorithm_t)0x52u)
#define kAlgorithm_SSS_HKDF_SHA224_EXTRACT ((sss_algorithm_t)0x53u)
#define kAlgorithm_SSS_HKDF_SHA256_EXTRACT ((sss_algorithm_t)0x54u)
#define kAlgorithm_SSS_HKDF_SHA384_EXTRACT ((sss_algorithm_t)0x55u)
#define kAlgorithm_SSS_HKDF_SHA512_EXTRACT ((sss_algorithm_t)0x56u)
#define kAlgorithm_SSS_HKDF_SHA1_EXPAND    ((sss_algorithm_t)0x57u)
#define kAlgorithm_SSS_HKDF_SHA224_EXPAND  ((sss_algorithm_t)0x58u)
#define kAlgorithm_SSS_HKDF_SHA256_EXPAND  ((sss_algorithm_t)0x59u)
#define kAlgorithm_SSS_HKDF_SHA384_EXPAND  ((sss_algorithm_t)0x5au)
#define kAlgorithm_SSS_HKDF_SHA512_EXPAND  ((sss_algorithm_t)0x5bu)
#define kAlgorithm_SSS_AES_MP_KDF          ((sss_algorithm_t)0x5cu) //!< Miyaguchi-Preneel KDF
#define kAlgorithm_SSS_CKDF_SCP03          ((sss_algorithm_t)0x5du) //!< KDF in Counter Mode with CMAC as PRF (aligned with SCP03)
#endif /* ELE_FEATURE_MAC_KDF */

/* PQC */
#define kAlgorithm_SSS_PQC_MLDSA  ((sss_algorithm_t)0x25u)
#define kAlgorithm_SSS_PQC_MLKEM  ((sss_algorithm_t)0x26u)

#define SAB_KEY_TYPE_SYMMETRIC  (0x00)
#define SAB_KEY_TYPE_ASYMMETRIC (0x01)
#define SSS_KEY_CIPHER_TYPE_ENUM_ALT
typedef uint32_t sss_cipher_type_t;
#define kSSS_CipherType_NONE      ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_AES       ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_DES       ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_CMAC      ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_HMAC      ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_MAC       ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_SYMMETRIC ((sss_cipher_type_t)0x10u)
/* The following keys can be identified
 * solely by the *Family* and bit length */
#define kSSS_CipherType_EC_NIST_P ((sss_cipher_type_t)0x40u) /*! Keys Part of NIST-P Family */
#define kSSS_CipherType_EC_NIST_K ((sss_cipher_type_t)0x1u)  /*! Keys Part of NIST-K Family */
/* The following keys need their full curve parameters (p,a,b,x,y,n,h) */
/*! Montgomery Key,   */
#define kSSS_CipherType_EC_MONTGOMERY ((sss_cipher_type_t)0x50u)
/*! twisted Edwards form elliptic curve public key */
#define kSSS_CipherType_EC_TWISTED_ED ((sss_cipher_type_t)0x51u)
#if defined(ELE200_EXTENDED_FEATURES)
/*! RSA */
#define kSSS_CipherType_RSA             ((sss_cipher_type_t)0x1u)  /*! RSA RAW format         */
#define kSSS_CipherType_RSA_CRT         ((sss_cipher_type_t)0x32u) /*! RSA CRT format         */
#define kSSS_CipherType_RSA_CRT_COMPACT ((sss_cipher_type_t)0x33u) /*! RSA CRT compact format */
/*! Brainpool form elliptic curve public key */
#define kSSS_CipherType_EC_BRAINPOOL_R1 ((sss_cipher_type_t)0x42u)
#define kSSS_CipherType_EC_BRAINPOOL_T1 ((sss_cipher_type_t)0x43u)
/*! OSCCA SM2 */
#define kSSS_CipherType_EC_OSCCA_SM2 ((sss_cipher_type_t)0x60u)
/*! GF(2^m) Koblitz curves */
#define kSSS_CipherType_EC_KOBLITZ ((sss_cipher_type_t)0x70u)
/*! Dilithium */
#define kSSS_CipherType_DILITHIUM2 ((sss_cipher_type_t)0x80u)
#define kSSS_CipherType_DILITHIUM3 ((sss_cipher_type_t)0x81u)
#define kSSS_CipherType_DILITHIUM5 ((sss_cipher_type_t)0x82u)
/*! ML-DSA */
#define kSSS_CipherType_MLDSA44 ((sss_cipher_type_t)0x83u)
#define kSSS_CipherType_MLDSA65 ((sss_cipher_type_t)0x84u)
#define kSSS_CipherType_MLDSA87 ((sss_cipher_type_t)0x85u)
/*! ML-KEM */
#define kSSS_CipherType_MLKEM512  ((sss_cipher_type_t)0x86u)
#define kSSS_CipherType_MLKEM768  ((sss_cipher_type_t)0x87u)
#define kSSS_CipherType_MLKEM1024 ((sss_cipher_type_t)0x88u)
#endif /* ELE200_EXTENDED_FEATURES */
/*! Barreto Naehrig curve */
#define kSSS_CipherType_EC_BARRETO_NAEHRIG ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_UserID             ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_Certificate        ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_Binary             ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_Count              ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_PCR                ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_ReservedPin        ((sss_cipher_type_t)0x1u)

#define SSS_STATUS_ENUM_ALT
typedef uint32_t sss_status_t;
/** Operation was successful */
#define kStatus_SSS_Success ((sss_status_t)0x5a5a5a5au)
/** Operation failed */
#define kStatus_SSS_Fail ((sss_status_t)0x3c3c0000u)
/** Operation not performed because some of the passed parameters
 * were found inappropriate */
#define kStatus_SSS_InvalidArgument ((sss_status_t)0x3c3c0001u)
/** Where the underlying sub-system *supports* multi-threading,
 * Internal status to handle simultaneous access.
 *
 * This status is not expected to be returned to higher layers.
 * */
#define kStatus_SSS_ResourceBusy ((sss_status_t)0x3c3c0002u)

#define SSS_KEY_PART_ENUM_ALT
typedef uint32_t sss_key_part_t;
/** Part of a key */
#define kSSS_KeyPart_NONE ((sss_key_part_t)0x0u)
/** Applicable where we have UserID, PIN, Binary Files,
 * Certificates, Symmetric Keys, PCR */
#define kSSS_KeyPart_Default ((sss_key_part_t)0x1u)
/** Public part of asymmetric key */
#define kSSS_KeyPart_Public ((sss_key_part_t)0x2u)
/** Private only part of asymmetric key */
#define kSSS_KeyPart_Private ((sss_key_part_t)0x3u)
/** Both, public and private part of asymmetric key */
#define kSSS_KeyPart_Pair ((sss_key_part_t)0x4u)

typedef uint32_t sss_mgmt_security_level_t;
#define kSSS_mgmt_security_lvl_NON_SECURE            ((sss_mgmt_security_level_t)0x0u)
#define kSSS_mgmt_security_lvl_NON_SECURE_PRIVILEGED ((sss_mgmt_security_level_t)0x1u)
#define kSSS_mgmt_security_lvl_SECURE                ((sss_mgmt_security_level_t)0x2u)
#define kSSS_mgmt_security_lvl_SECURE_PRIVILEGED     ((sss_mgmt_security_level_t)0x3u)

typedef uint32_t sss_sscp_key_store_property_t;
#define kSSS_key_store_prop_totalAllocatedMemory    ((sss_sscp_key_store_property_t)0x0u)
#define kSSS_key_store_prop_availableMemory         ((sss_sscp_key_store_property_t)0x1u)
#define kSSS_key_store_prop_totalNumberOfKeyObjects ((sss_sscp_key_store_property_t)0x2u)
#define kSSS_key_store_prop_availableKeyObjects     ((sss_sscp_key_store_property_t)0x3u)

typedef uint32_t sss_sscp_key_property_t;
#define kSSS_KeyProp_Locked                    ((sss_sscp_key_property_t)0x80000000u)
#define kSSS_KeyProp_SecAccess_NS_USER         ((sss_sscp_key_property_t)0x00000000u)
#define kSSS_KeyProp_SecAccess_NS_PRIV         ((sss_sscp_key_property_t)0x20000000u)
#define kSSS_KeyProp_SecAccess_S_USER          ((sss_sscp_key_property_t)0x40000000u)
#define kSSS_KeyProp_SecAccess_S_PRIV          ((sss_sscp_key_property_t)0x60000000u)
#define kSSS_KeyProp_TrustedKey                ((sss_sscp_key_property_t)0x10000000u)
#define kSSS_KeyProp_NoImportExport            ((sss_sscp_key_property_t)0x00010000u)
#define kSSS_KeyProp_NoPlainRead               ((sss_sscp_key_property_t)0x00008000u)
#define kSSS_KeyProp_NoPlainWrite              ((sss_sscp_key_property_t)0x00004000u)
#define kSSS_KeyProp_NoVerify                  ((sss_sscp_key_property_t)0x00002000u)
#define kSSS_KeyProp_NoSign                    ((sss_sscp_key_property_t)0x00001000u)
#define kSSS_KeyProp_NoEncrypt                 ((sss_sscp_key_property_t)0x00000400u)
#define kSSS_KeyProp_NoDecrypt                 ((sss_sscp_key_property_t)0x00000800u)
#define kSSS_KeyProp_CryptoAlgo_PKB            ((sss_sscp_key_property_t)0x00000020u)
#define kSSS_KeyProp_CryptoAlgo_KDF            ((sss_sscp_key_property_t)0x00000010u)
#define kSSS_KeyProp_CryptoAlgo_AsymSignVerify ((sss_sscp_key_property_t)0x00000008u)
#define kSSS_KeyProp_CryptoAlgo_AEAD           ((sss_sscp_key_property_t)0x00000004u)
#define kSSS_KeyProp_CryptoAlgo_MAC            ((sss_sscp_key_property_t)0x00000002u)
#define kSSS_KeyProp_CryptoAlgo_AES            ((sss_sscp_key_property_t)0x00000001u)

typedef uint32_t sss_sscp_keyObjFree_options_t;
#define kSSS_keyObjFree_KeysStoreNoDefragment ((sss_sscp_keyObjFree_options_t)0x0u)
#define kSSS_keyObjFree_KeysStoreDefragment   ((sss_sscp_keyObjFree_options_t)0x1u)

typedef uint32_t sss_sscp_tunnel_type_t;
#define kSSS_tunnel_type_MasterBootImgAuth   ((sss_sscp_tunnel_type_t)0x20u)
#define kSSS_tunnel_type_SB3FileAuth         ((sss_sscp_tunnel_type_t)0x21u)
#define kSSS_tunnel_type_EdgelockFW          ((sss_sscp_tunnel_type_t)0x22u)
#define kSSS_tunnel_type_SB3FileVerification ((sss_sscp_tunnel_type_t)0x25u)
/* El2Go FW need to be loaded to use this tunnel type */
#define kSSS_tunnel_type_EL2GO_Data ((sss_sscp_tunnel_type_t)0x80000025u)

typedef uint32_t sss_sscp_blob_type_t;
#define kSSS_blobType_ELKE_blob     ((sss_sscp_blob_type_t)0x1u)
#define kSSS_blobType_E2E_blob      ((sss_sscp_blob_type_t)0x2u)
#define kSSS_blobType_NBU_ESK_blob  ((sss_sscp_blob_type_t)0x3u)
#define kSSS_blobType_NBU_EIRK_blob ((sss_sscp_blob_type_t)0x4u)
/* El2Go FW need to be loaded to use TLV blob */
#define kSSS_blobType_EL2GO_TLV_blob ((sss_sscp_blob_type_t)0x5u)
#define kSSS_blobType_ELGAMAL_blob   ((sss_sscp_blob_type_t)0x6u)

typedef uint32_t sss_internal_keyID_t;
#define kSSS_internalKey_NPX           ((sss_internal_keyID_t)0x80000007u)
#define kSSS_internalKey_NBU_DKEY_SK   ((sss_internal_keyID_t)0x80000009u)
#define kSSS_internalKey_NBU_DKEY_IRK  ((sss_internal_keyID_t)0x8000000Au)
#define kSSS_internalKey_NBU_BRIC_KEY0 ((sss_internal_keyID_t)0x8000000Bu)
#define kSSS_internalKey_NBU_BRIC_KEY1 ((sss_internal_keyID_t)0x8000000Cu)

/* Point arithmetic operations */
typedef uint32_t sss_sscp_ecPointOp_t;
#define kSSS_ecPointOp_MULT ((sss_sscp_ecPointOp_t)0x0Au)
#define kSSS_ecPointOp_ADD  ((sss_sscp_ecPointOp_t)0x0Bu)
#define kSSS_ecPointOp_SUB  ((sss_sscp_ecPointOp_t)0x0Cu)


#endif /* FSL_SSS_CONFIG_H */