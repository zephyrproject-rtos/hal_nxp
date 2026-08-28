/*--------------------------------------------------------------------------*/
/* Copyright 2021-2024, 2026 NXP                                            */
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

#include <mcuxClCore_Platform.h>
#include <mcuxCsslAnalysis.h>

#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_Types.h>

#if defined(MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT) || defined(MCUXCL_FEATURE_CIPHER_RSA_DECRYPT)
#include <internal/mcuxClCipher_Internal.h>
MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
volatile uint8_t mcuxClRsa_Cipher_AlgorithmMode_Descriptors_Size[sizeof(mcuxClCipher_ModeDescriptor_t) + sizeof(mcuxClRsa_Cipher_AlgorithmDescriptor_t)];
MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
#endif

MCUX_CSSL_ANALYSIS_START_PATTERN_OBJ_SIZES()
volatile mcuxClRsa_SignatureProtocolDescriptor_t mcuxClRsa_Signature_ProtocolDescriptor_size;

#include <internal/mcuxClKey_Internal.h>
volatile uint8_t mcuxClRsa_KeyGeneration_ProtocolDescriptor_size[sizeof(mcuxClKey_GenerationDescriptor_t) + sizeof(mcuxClRsa_KeyGeneration_ProtocolDescriptor_t)];

#ifdef MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT
/****************************************************************************/
/* Computation of workarea sizes for the mcuxClRsa_Util_encrypt function.    */
/****************************************************************************/

volatile uint8_t mcuxClRsa_Util_Encrypt_1024_WaCPU[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_2048_WaCPU[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_3072_WaCPU[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_4096_WaCPU[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Util_Encrypt_6144_WaCPU[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_8192_WaCPU[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_Util_Encrypt_1024_WaPKC[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_2048_WaPKC[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_3072_WaPKC[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_4096_WaPKC[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Util_Encrypt_6144_WaPKC[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_Util_Encrypt_8192_WaPKC[MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT */
#ifdef MCUXCL_FEATURE_CIPHER_RSA_DECRYPT
/****************************************************************************/
/* Computation of workarea sizes for the mcuxClRsa_Util_decrypt function.    */
/****************************************************************************/

volatile uint8_t mcuxClRsa_Util_Decrypt_1024_WaCPU[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_Util_Decrypt_2048_WaCPU[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_Util_Decrypt_3072_WaCPU[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_Util_Decrypt_4096_WaCPU[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Util_Decrypt_6144_WaCPU[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_Util_Decrypt_8192_WaCPU[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/* NOTE: MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN is used as parameter since it gives max WA PKC usage. */
volatile uint8_t mcuxClRsa_Util_Decrypt_1024_WaPKC[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(1024/8, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
volatile uint8_t mcuxClRsa_Util_Decrypt_2048_WaPKC[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(2048/8, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
volatile uint8_t mcuxClRsa_Util_Decrypt_3072_WaPKC[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(3072/8, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
volatile uint8_t mcuxClRsa_Util_Decrypt_4096_WaPKC[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(4096/8, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Util_Decrypt_6144_WaPKC[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(6144/8, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
volatile uint8_t mcuxClRsa_Util_Decrypt_8192_WaPKC[MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(8192/8, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */
#endif /* MCUXCL_FEATURE_CIPHER_RSA_DECRYPT */

/****************************************************************************/
/* Computation of workarea sizes for the Rsa_sign function.               */
/****************************************************************************/

volatile uint8_t mcuxClRsa_Sign_Plain_NoEMSA_1024_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WACPU_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_NoEMSA_2048_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WACPU_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_NoEMSA_3072_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WACPU_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_NoEMSA_4096_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WACPU_SIZE(4096/8)];

volatile uint8_t mcuxClRsa_Sign_Plain_Pkcs1v15Encode_1024_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_Pkcs1v15Encode_2048_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_Pkcs1v15Encode_3072_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_Pkcs1v15Encode_4096_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Sign_Plain_Pkcs1v15Encode_6144_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_Pkcs1v15Encode_8192_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_Sign_Plain_PssEncode_1024_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_PssEncode_2048_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_PssEncode_3072_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_PssEncode_4096_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Sign_Plain_PssEncode_6144_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_Sign_Plain_PssEncode_8192_WaCPU[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Plain_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(1024/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(1024/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(1024/8)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_1024_t;
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_1024 (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_1024_t))
volatile uint8_t mcuxClRsa_Sign_Plain_1024_WaPKC[MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_1024 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(1024U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Plain_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(2048/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(2048/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(2048/8)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_2048_t;
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_2048  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_2048_t))
volatile uint8_t mcuxClRsa_Sign_Plain_2048_WaPKC[MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_2048 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(2048U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Plain_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(3072/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(3072/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(3072/8)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_3072_t;
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_3072  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_3072_t))
volatile uint8_t mcuxClRsa_Sign_Plain_3072_WaPKC[MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_3072 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(3072U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Plain_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(4096/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(4096/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(4096/8)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_4096_t;
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_4096  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_4096_t))
volatile uint8_t mcuxClRsa_Sign_Plain_4096_WaPKC[MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_4096 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(4096U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Plain_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(6144/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(6144/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(6144/8)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_6144_t;
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_6144  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_6144_t))
volatile uint8_t mcuxClRsa_Sign_Plain_6144_WaPKC[MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_6144 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(6144U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Plain_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(8192/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(8192/8)];
    uint8_t mcuxClRsa_Internal_Sign_Plain_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(8192/8)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_8192_t;
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_8192  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Plain_PrimeByteLength_8192_t) + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(8192U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN))
volatile uint8_t mcuxClRsa_Sign_Plain_8192_WaPKC[MCUXCLRSA_INTERNAL_SIGN_PLAIN_WAPKC_SIZE_8192];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_Sign_CRT_NoEMSA_1024_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WACPU_SIZE(1024/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_NoEMSA_2048_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WACPU_SIZE(2048/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_NoEMSA_3072_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WACPU_SIZE(3072/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_NoEMSA_4096_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WACPU_SIZE(4096/8/2)];

volatile uint8_t mcuxClRsa_Sign_CRT_Pkcs1v15Encode_1024_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(1024/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_Pkcs1v15Encode_2048_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(2048/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_Pkcs1v15Encode_3072_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(3072/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_Pkcs1v15Encode_4096_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(4096/8/2)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Sign_CRT_Pkcs1v15Encode_6144_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(6144/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_Pkcs1v15Encode_8192_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(8192/8/2)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_Sign_CRT_PssEncode_1024_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(1024/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_PssEncode_2048_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(2048/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_PssEncode_3072_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(3072/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_PssEncode_4096_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(4096/8/2)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_Sign_CRT_PssEncode_6144_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(6144/8/2)];
volatile uint8_t mcuxClRsa_Sign_CRT_PssEncode_8192_WaCPU[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(8192/8/2)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Crt_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(1024/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(1024/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(1024/8/2)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_1024_t;
#define MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_1024  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_1024_t))
volatile uint8_t mcuxClRsa_Sign_CRT_1024_WaPKC[MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_1024 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(1024U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Crt_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(2048/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(2048/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(2048/8/2)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_2048_t;
#define MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_2048  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_2048_t))
volatile uint8_t mcuxClRsa_Sign_CRT_2048_WaPKC[MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_2048 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(2048U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Crt_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(3072/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(3072/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(3072/8/2)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_3072_t;
#define MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_3072  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_3072_t))
volatile uint8_t mcuxClRsa_Sign_CRT_3072_WaPKC[MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_3072 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(3072U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Crt_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(4096/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(4096/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(4096/8/2)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_4096_t;
#define MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_4096  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_4096_t))
volatile uint8_t mcuxClRsa_Sign_CRT_4096_WaPKC[MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_4096 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(4096U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Crt_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(6144/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(6144/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(6144/8/2)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_6144_t;
#define MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_6144  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_6144_t))
volatile uint8_t mcuxClRsa_Sign_CRT_6144_WaPKC[MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_6144 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(6144U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT)];
typedef union
{
    uint8_t mcuxClRsa_Internal_Sign_Crt_PKCS1V15Encode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(8192/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_PSSEncode_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(8192/8/2)];
    uint8_t mcuxClRsa_Internal_Sign_Crt_NoEMSA_WaPkc_Size[MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(8192/8/2)];
} mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_8192_t;
#define MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_8192  (sizeof(mcuxClRsa_Internal_MaxUnion_WaPkc_Sign_Crt_PrimeByteLength_8192_t))
volatile uint8_t mcuxClRsa_Sign_CRT_8192_WaPKC[MCUXCLRSA_INTERNAL_SIGN_CRT_WAPKC_SIZE_8192 + MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(8192U/8U, MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */


/****************************************************************************/
/* Computation of workarea sizes for the   function.               */
/****************************************************************************/

volatile uint8_t mcuxClRsa_Verify_Compare_NoEMSA_Verify_WaCPU[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WACPU_SIZE];

volatile uint8_t mcuxClRsa_Verify_Pkcs1v15Verify_WaCPU[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WACPU_SIZE];

volatile uint8_t mcuxClRsa_Verify_PssVerify_WaCPU[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WACPU_SIZE];

typedef union
{
    uint8_t mcuxClRsa_Internal_Verify_PKCS1V15Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(1024U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_PSSVerify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(1024U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_Compare_NoEMSA_Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(1024U/8U)];
} mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_1024_t;
#define MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_1024 (sizeof(mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_1024_t))
volatile uint8_t mcuxClRsa_Verify_1024_WaPKC[MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_1024];
typedef union
{
    uint8_t mcuxClRsa_Internal_Verify_PKCS1V15Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(2048U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_PSSVerify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(2048U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_Compare_NoEMSA_Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(2048U/8U)];
} mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_2048_t;
#define MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_2048 (sizeof(mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_2048_t))
volatile uint8_t mcuxClRsa_Verify_2048_WaPKC[MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_2048];
typedef union
{
    uint8_t mcuxClRsa_Internal_Verify_PKCS1V15Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(3072U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_PSSVerify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(3072U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_Compare_NoEMSA_Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(3072U/8U)];
} mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_3072_t;
#define MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_3072 (sizeof(mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_3072_t))
volatile uint8_t mcuxClRsa_Verify_3072_WaPKC[MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_3072];
typedef union
{
    uint8_t mcuxClRsa_Internal_Verify_PKCS1V15Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(4096U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_PSSVerify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(4096U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_Compare_NoEMSA_Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(4096U/8U)];
} mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_4096_t;
#define MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_4096 (sizeof(mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_4096_t))
volatile uint8_t mcuxClRsa_Verify_4096_WaPKC[MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_4096];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
typedef union
{
    uint8_t mcuxClRsa_Internal_Verify_PKCS1V15Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(6144U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_PSSVerify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(6144U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_Compare_NoEMSA_Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(6144U/8U)];
} mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_6144_t;
#define MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_6144 (sizeof(mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_6144_t))
volatile uint8_t mcuxClRsa_Verify_6144_WaPKC[MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_6144];
typedef union
{
    uint8_t mcuxClRsa_Internal_Verify_PKCS1V15Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(8192U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_PSSVerify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(8192U/8U)];
    uint8_t mcuxClRsa_Internal_Verify_Compare_NoEMSA_Verify_WaPkc_Size[MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(8192U/8U)];
} mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_8192_t;
#define MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_8192 (sizeof(mcuxClRsa_Internal_MaxUnion_Verify_WaPkc_8192_t))
volatile uint8_t mcuxClRsa_Verify_8192_WaPKC[MCUXCLRSA_INTERNAL_VERIFY_WAPKC_SIZE_8192];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */


/*************************************************************************************************************************/
/* Computation of key data size for the mcuxClRsa_Util_KeyGeneration_Crt and mcuxClRsa_Util_KeyGeneration_Plain functions. */
/*************************************************************************************************************************/
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_Key_Data_1024[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_Key_Data_2048[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_Key_Data_3072[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_Key_Data_4096[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_Key_Data_6144[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_Key_Data_8192[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_KeyGeneration_Crt_Key_Data_1024[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_Key_Data_2048[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_Key_Data_3072[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_Key_Data_4096[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_Key_Data_6144[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_Key_Data_8192[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_1024[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_2048[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_3072[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_4096[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_6144[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_CrtDfa_Key_Data_8192[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

volatile uint8_t mcuxClRsa_KeyData_Plain_t_Size[sizeof(mcuxClRsa_KeyData_Plain_t)];
volatile uint8_t mcuxClRsa_KeyGeneration_Public_Key_Data_1024[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Public_Key_Data_2048[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Public_Key_Data_3072[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Public_Key_Data_4096[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Public_Key_Data_6144[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Public_Key_Data_8192[MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(8192/8)];
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

/***********************************************************************************************************/
/* Computation of workarea sizes for the mcuxClRsa_Util_KeyGeneration_Plain function for typical key sizes. */
/***********************************************************************************************************/
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_1024_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_2048_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_3072_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_4096_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_6144_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_8192_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(8192/8)];
#endif

volatile uint8_t mcuxClRsa_KeyGeneration_Plain_1024_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(1024/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_2048_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(2048/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_3072_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(3072/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_4096_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(4096/8)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_6144_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(6144/8)];
volatile uint8_t mcuxClRsa_KeyGeneration_Plain_8192_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(8192/8)];
#endif
/*********************************************************************************************************/
/* Computation of workarea sizes for the mcuxClRsa_Util_KeyGeneration_Crt function for typical key sizes. */
/*********************************************************************************************************/
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_1024_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(1024/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_2048_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(2048/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_3072_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(3072/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_4096_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(4096/8/2)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_6144_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(6144/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_8192_WaPKC[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(8192/8/2)];
#endif
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_1024_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(1024/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_2048_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(2048/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_3072_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(3072/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_4096_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(4096/8/2)];
#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_6144_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(6144/8/2)];
volatile uint8_t mcuxClRsa_KeyGeneration_Crt_8192_WaCPU[MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(8192/8/2)];
#endif


MCUX_CSSL_ANALYSIS_STOP_PATTERN_OBJ_SIZES()
