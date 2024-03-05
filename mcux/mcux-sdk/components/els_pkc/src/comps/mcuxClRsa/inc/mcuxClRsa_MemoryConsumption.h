/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
/*                                                                          */
/* NXP Confidential. This software is owned or controlled by NXP and may    */
/* only be used strictly in accordance with the applicable license terms.   */
/* By expressly accepting such terms or by downloading, installing,         */
/* activating and/or otherwise using the software, you are agreeing that    */
/* you have read, and that you agree to comply with and are bound by, such  */
/* license terms. If you do not agree to be bound by the applicable license */
/* terms, then you may not retain, install, activate or otherwise use the   */
/* software.                                                                */
/*--------------------------------------------------------------------------*/

/**
 * @file  mcuxClRsa_MemoryConsumption.h
 * @brief Defines the memory consumption for the mcuxClRsa component 
 */

#ifndef MCUXCLRSA_MEMORYCONSUMPTION_H_
#define MCUXCLRSA_MEMORYCONSUMPTION_H_


/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa Sign                      */
/****************************************************************************/

/**
 * @defgroup MCUXCLRSA_SIGN_WA MCUXCLRSA_SIGN_WA
 * @brief Definitions of workarea sizes for the mcuxClRsa Sign
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_SIGN_PLAIN_NOENCODE_1024_WACPU_SIZE    (152u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 1024-bit private plain keys using mode mcuxClRsa_Mode_Sign_NoEncode.
#define MCUXCLRSA_SIGN_PLAIN_NOENCODE_2048_WACPU_SIZE    (280u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 2048-bit private plain keys using mode mcuxClRsa_Mode_Sign_NoEncode.
#define MCUXCLRSA_SIGN_PLAIN_NOENCODE_3072_WACPU_SIZE    (408u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 3072-bit private plain keys using mode mcuxClRsa_Mode_Sign_NoEncode.
#define MCUXCLRSA_SIGN_PLAIN_NOENCODE_4096_WACPU_SIZE    (536u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 4096-bit private plain keys using mode mcuxClRsa_Mode_Sign_NoEncode.

#define MCUXCLRSA_SIGN_PLAIN_NOENCODE_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_NOENCODE_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_NOENCODE_3072_WACPU_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_NOENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_NOENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATEPLAIN.

#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_1024_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 1024-bit private plain keys using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_2048_WACPU_SIZE    (280u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 2048-bit private plain keys using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_3072_WACPU_SIZE    (408u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 3072-bit private plain keys using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_4096_WACPU_SIZE    (536u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 4096-bit private plain keys using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_3072_WACPU_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PSSENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_PSSENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATEPLAIN.

#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_1024_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 1024-bit private plain keys using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_2048_WACPU_SIZE    (280u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 2048-bit private plain keys using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_3072_WACPU_SIZE    (408u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 3072-bit private plain keys using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_4096_WACPU_SIZE    (536u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function for 4096-bit private plain keys using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*.
#define MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_3072_WACPU_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATEPLAIN.

#define MCUXCLRSA_SIGN_PLAIN_1024_WAPKC_SIZE     (1064u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 1024-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_2048_WAPKC_SIZE     (1960u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 2048-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_3072_WAPKC_SIZE     (2856u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 3072-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_4096_WAPKC_SIZE     (3752u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 4096-bit private plain keys.
#define MCUXCLRSA_SIGN_PLAIN_WAPKC_SIZE(keyBitLength) \
        ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_4096_WAPKC_SIZE : \
        ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_3072_WAPKC_SIZE : \
        ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_PLAIN_2048_WAPKC_SIZE : \
                                    MCUXCLRSA_SIGN_PLAIN_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATEPLAIN.

#define MCUXCLRSA_SIGN_CRT_NOENCODE_1024_WACPU_SIZE    (104u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_NoEncode, for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_NOENCODE_2048_WACPU_SIZE    (168u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_NoEncode, for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_NOENCODE_3072_WACPU_SIZE    (232u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_NoEncode, for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_NOENCODE_4096_WACPU_SIZE    (296u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_NoEncode, for 4096-bit private CRT keys.

#define MCUXCLRSA_SIGN_CRT_NOENCODE_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_NOENCODE_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_NOENCODE_3072_WACPU_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_NOENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_NOENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATECRT or MCUXCLRSA_KEY_PRIVATECRT_DFA.

#define MCUXCLRSA_SIGN_CRT_PSSENCODE_1024_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*, for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_2048_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*, for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_3072_WACPU_SIZE    (232u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*, for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_4096_WACPU_SIZE    (296u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_Pss_Sha2_*, for 4096-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PSSENCODE_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_3072_WACPU_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PSSENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_PSSENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATECRT or MCUXCLRSA_KEY_PRIVATECRT_DFA.

#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_1024_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*, for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_2048_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*, for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_3072_WACPU_SIZE    (232u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*, for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_4096_WACPU_SIZE    (296u) ///< Definition of CPU workarea size for the mcuxClRsa_sign function using mode mcuxClRsa_Mode_Sign_PKCS1v15_Sha2_*, for 4096-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_3072_WACPU_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_2048_WACPU_SIZE : \
                                 MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_1024_WACPU_SIZE)))  ///< Macro to extract CPU workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATECRT or MCUXCLRSA_KEY_PRIVATECRT_DFA.

#define MCUXCLRSA_SIGN_CRT_1024_WAPKC_SIZE     (968u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 1024-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_2048_WAPKC_SIZE     (1864u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 2048-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_3072_WAPKC_SIZE     (2760u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 3072-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_4096_WAPKC_SIZE     (3656u) ///< Definition of PKC workarea size for the mcuxClRsa_sign function for 4096-bit private CRT keys.
#define MCUXCLRSA_SIGN_CRT_WAPKC_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_4096_WAPKC_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_3072_WAPKC_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_SIGN_CRT_2048_WAPKC_SIZE : \
                                MCUXCLRSA_SIGN_CRT_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length, with a key of type MCUXCLRSA_KEY_PRIVATECRT or MCUXCLRSA_KEY_PRIVATECRT_DFA.

/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa Verify                    */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_VERIFY_WA MCUXCLRSA_VERIFY_WA
 * @brief Definitions of workarea sizes for the mcuxClRsa Verify
 * @ingroup mcuxClRsa_Macros
 * @{
 */


#define MCUXCLRSA_VERIFY_NOVERIFY_WACPU_SIZE          (16u) ///< Definition of CPU workarea size for the mcuxClRsa_verify function using mode mcuxClRsa_Mode_Verify_NoVerify.
#define MCUXCLRSA_VERIFY_PSSVERIFY_WACPU_SIZE         (196u) ///< Definition of CPU workarea size for the mcuxClRsa_verify function using mode mcuxClRsa_Mode_Verify_PssVerify.
#define MCUXCLRSA_VERIFY_PKCS1V15VERIFY_WACPU_SIZE    (196u) ///< Definition of CPU workarea size for the mcuxClRsa_verify function using mode mcuxClRsa_Mode_Verify_PKCS1v15_Sha2_*.

#define MCUXCLRSA_VERIFY_1024_WAPKC_SIZE     (800u) ///< Definition of PKC workarea size for the mcuxClRsa_verify function for 1024-bit keys.
#define MCUXCLRSA_VERIFY_2048_WAPKC_SIZE     (1568u) ///< Definition of PKC workarea size for the mcuxClRsa_verify function for 2048-bit keys.
#define MCUXCLRSA_VERIFY_3072_WAPKC_SIZE     (2336u) ///< Definition of PKC workarea size for the mcuxClRsa_verify function for 3072-bit keys.
#define MCUXCLRSA_VERIFY_4096_WAPKC_SIZE     (3104u) ///< Definition of PKC workarea size for the mcuxClRsa_verify function for 4096-bit keys.
#define MCUXCLRSA_VERIFY_WAPKC_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_VERIFY_4096_WAPKC_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_VERIFY_3072_WAPKC_SIZE : \
    ((1024u < (keyBitLength)) ? MCUXCLRSA_VERIFY_2048_WAPKC_SIZE : \
                                MCUXCLRSA_VERIFY_1024_WAPKC_SIZE)))  ///< Macro to extract PKC workarea size to be used with a non-standard key length.



/** @} */


/**********************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_KeyGeneration_Crt function.     */
/**********************************************************************************/
/**
 * @defgroup MCUXCLRSA_KEYGENERATION_CRT_WA MCUXCLRSA_KEYGENERATION_CRT_WA
 * @brief Definitions of workarea sizes for the mcuxClRsa_KeyGeneration_Crt function.
 * @ingroup mcuxClRsa_Macros
 * @{
 */

#ifdef MCUXCL_FEATURE_PROJECT_NIOBE4ANALOG

#define MCUXCLRSA_KEYGENERATION_CRT_2048_WACPU_SIZE    (56u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_3072_WACPU_SIZE    (56u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_4096_WACPU_SIZE    (56u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 4096-bit keys

#else 

#define MCUXCLRSA_KEYGENERATION_CRT_2048_WACPU_SIZE    (632u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_3072_WACPU_SIZE    (760u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_4096_WACPU_SIZE    (888u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 4096-bit keys

#endif

#define MCUXCLRSA_KEYGENERATION_CRT_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_3072_WACPU_SIZE : \
                                MCUXCLRSA_KEYGENERATION_CRT_2048_WACPU_SIZE))  ///< Macro to extract CPU workarea size (in bytes) for the given key length.

#define MCUXCLRSA_KEYGENERATION_CRT_2048_WAPKC_SIZE    (1656u) ///< Definition of PKC workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_3072_WAPKC_SIZE    (2424u) ///< Definition of PKC workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_4096_WAPKC_SIZE    (3192u) ///< Definition of PKC workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Crt function for 4096-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_WAPKC_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_4096_WAPKC_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_CRT_3072_WAPKC_SIZE : \
                                MCUXCLRSA_KEYGENERATION_CRT_2048_WAPKC_SIZE))  ///< Macro to extract PKC workarea size (in bytes) for the given key length.

/** @} */

/********************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_KeyGeneration_Plain function. */
/********************************************************************************/
/**
 * @defgroup MCUXCLRSA_KEYGENERATION_PLAIN_WA MCUXCLRSA_KEYGENERATION_PLAIN_WA
 * @brief Definitions of workarea sizes for the mcuxClRsa_KeyGeneration_Plain function.
 * @ingroup mcuxClRsa_Macros
 * @{
 */

#ifdef MCUXCL_FEATURE_PROJECT_NIOBE4ANALOG

#define MCUXCLRSA_KEYGENERATION_PLAIN_2048_WACPU_SIZE    (44u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_3072_WACPU_SIZE    (44u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE    (44u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 4096-bit keys

#else

#define MCUXCLRSA_KEYGENERATION_PLAIN_2048_WACPU_SIZE    (620u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_3072_WACPU_SIZE    (748u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE    (876u) ///< Definition of CPU workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 4096-bit keys

#endif

#define MCUXCLRSA_KEYGENERATION_PLAIN_WACPU_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_4096_WACPU_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_3072_WACPU_SIZE : \
                                MCUXCLRSA_KEYGENERATION_PLAIN_2048_WACPU_SIZE))  ///< Macro to extract CPU workarea size for the given key length.

#define MCUXCLRSA_KEYGENERATION_PLAIN_2048_WAPKC_SIZE    (1832u) ///< Definition of PKC workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_3072_WAPKC_SIZE    (2728u) ///< Definition of PKC workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_4096_WAPKC_SIZE    (3624u) ///< Definition of PKC workarea size (in bytes) for the mcuxClRsa_KeyGeneration_Plain function for 4096-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_WAPKC_SIZE(keyBitLength) \
    ((3072u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_4096_WAPKC_SIZE : \
    ((2048u < (keyBitLength)) ? MCUXCLRSA_KEYGENERATION_PLAIN_3072_WAPKC_SIZE : \
                                MCUXCLRSA_KEYGENERATION_PLAIN_2048_WAPKC_SIZE))  ///< Macro to extract PKC workarea size for the given key length.

/** @} */

/*************************************************************************************************************************/
/* Definitions of generated key data size for the mcuxClRsa_KeyGeneration_Crt and mcuxClRsa_KeyGeneration_Plain functions. */
/*************************************************************************************************************************/
/**
 * @defgroup MCUXCLRSA_KEYGENERATION_KEY_DATA_SIZE MCUXCLRSA_KEYGENERATION_KEY_DATA_SIZE
 * @brief Definitions of bufer sizes for the mcuxClRsa_KeyGeneration_Crt and mcuxClRsa_KeyGeneration_Plain functions.
 * @ingroup mcuxClRsa_Macros
 * @{
 */
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_2048_SIZE     (556u)  ///< Definition of bufer size (in bytes) for the private plain key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_3072_SIZE     (812u)  ///< Definition of bufer size (in bytes) for the private plain key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PLAIN_KEY_DATA_4096_SIZE     (1068u)  ///< Definition of bufer size (in bytes) for the private plain key data for 4096-bit keys

#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_2048_SIZE       (708u)  ///< Definition of bufer size (in bytes) for the private CRT key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_3072_SIZE       (1028u)  ///< Definition of bufer size (in bytes) for the private CRT key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_CRT_KEY_DATA_4096_SIZE       (1348u)  ///< Definition of bufer size (in bytes) for the private CRT key data for 4096-bit keys

#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_2048_SIZE    (556u)  ///< Definition of bufer size (in bytes) for the public key data for 2048-bit keys
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_3072_SIZE    (812u)  ///< Definition of bufer size (in bytes) for the public key data for 3072-bit keys
#define MCUXCLRSA_KEYGENERATION_PUBLIC_KEY_DATA_4096_SIZE    (1068u)  ///< Definition of bufer size (in bytes) for the public key data for 4096-bit keys

/** @} */


#endif /* MCUXCLRSA_MEMORYCONSUMPTION_H_ */
