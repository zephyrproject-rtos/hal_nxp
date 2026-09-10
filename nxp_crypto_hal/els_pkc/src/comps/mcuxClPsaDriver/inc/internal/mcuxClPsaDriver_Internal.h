/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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

/** @file  mcuxClPsaDriver_Internal.h
 *  @brief Internal header for the ARM PSA driver
 */

#ifndef MCUXCLPSADRIVER_INTERNAL_H_
#define MCUXCLPSADRIVER_INTERNAL_H_

#include <mcuxClCore_Macros.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClCipherModes_Els_Types.h>
#include <internal/mcuxClAeadModes_Els_Types.h>
#include <internal/mcuxClMacModes_Els_Ctx.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHash_Internal_Memory.h>

/* Definition for mcuxClPsaDriver_Sign and mcuxClPsaDriver_Verify */

/* Definition for mcuxClPsaDriver_Sign_By_Clns and mcuxClPsaDriver_Verify_By_Clns */
#define MCUXCLPSADRIVER_PREFIX_ANSI_X9_62_UNCOMPRESSED_POINT (0x04u)
#define MCUXCLPSADRIVER_PREFIX_ANSI_X9_62_COMPRESSED_POINT_EVEN_Y (0x02u)
#define MCUXCLPSADRIVER_PREFIX_ANSI_X9_62_COMPRESSED_POINT_ODD_Y (0x03u)

/* Definition of maximum lengths of key for RSA in bits */
#define MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX (4096u)

/* Macro for calculating bit/byte sizes */
#define MCUXCLPSADRIVER_BITS_TO_BYTES(bits) (((bits) + 7u) / 8u)
#define MCUXCLPSADRIVER_BYTES_TO_BITS(bytes) ((bytes) * 8u)

#define MCUXCLPSADRIVER_SIGN_BY_CLNS_RSA_PLAIN_WACPU_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRSA_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX), \
                               MCUXCLRSA_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX))
#define MCUXCLPSADRIVER_SIGN_BY_CLNS_RSA_CRT_WACPU_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRSA_SIGN_CRT_PSSENCODE_WACPU_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX), \
                               MCUXCLRSA_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX))
#define MCUXCLPSADRIVER_SIGN_BY_CLNS_RSA_WACPU_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLPSADRIVER_SIGN_BY_CLNS_RSA_PLAIN_WACPU_SIZE_MAX, \
                               MCUXCLPSADRIVER_SIGN_BY_CLNS_RSA_CRT_WACPU_SIZE_MAX)
#define MCUXCLPSADRIVER_SIGN_BY_CLNS_WACPU_SIZE_MAX \
            MCUXCLCORE_MAX(MCUXCLRANDOMMODES_INIT_WACPU_SIZE, \
                               MCUXCLCORE_MAX(MCUXCLCORE_MAX(MCUXCLPSADRIVER_SIGN_BY_CLNS_RSA_WACPU_SIZE_MAX, \
                                                  MCUXCLECC_SIGN_WACPU_SIZE), \
                                                  MCUXCLHASH_INTERNAL_WACPU_MAX))

/* Macro determining maximum size of CPU workarea size for mcuxClPsaDriver_Verify function */
#define MCUXCLPSADRIVER_VERIFY_BY_CLNS_RSA_WACPU_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRSA_VERIFY_PSSVERIFY_WACPU_SIZE, \
                               MCUXCLRSA_VERIFY_PKCS1V15VERIFY_WACPU_SIZE)
#define MCUXCLPSADRIVER_VERIFY_BY_CLNS_WACPU_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRANDOMMODES_INIT_WACPU_SIZE, \
                               MCUXCLCORE_MAX(MCUXCLCORE_MAX(MCUXCLPSADRIVER_VERIFY_BY_CLNS_RSA_WACPU_SIZE_MAX, MCUXCLECC_VERIFY_WACPU_SIZE), \
                                                  MCUXCLHASH_INTERNAL_WACPU_MAX))

/* Macro determining maximum size of PKC workarea size for mcuxClPsaDriver_Sign function */
#define MCUXCLPSADRIVER_SIGN_BY_CLNS_WAPKC_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLCORE_MAX(MCUXCLRSA_SIGN_CRT_WAPKC_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX), MCUXCLRSA_SIGN_PLAIN_WAPKC_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX)), \
                               MCUXCLECC_SIGN_WAPKC_SIZE_640)

/* Macro determining maximum size of PKC workarea size for mcuxClPsaDriver_Verify function */
#define MCUXCLPSADRIVER_VERIFY_BY_CLNS_WAPKC_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRSA_VERIFY_WAPKC_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX), MCUXCLECC_VERIFY_WAPKC_SIZE_640)

/* Macro determining maximum size of CPU workarea size for mcuxClPsaDriver_generate_rsa_key function */
#define MCUXCLPSADRIVER_RSA_KEY_GEN_BY_CLNS_WACPU_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRANDOMMODES_INIT_WACPU_SIZE, \
                               MCUXCLCORE_MAX(MCUXCLRSA_KEYGENERATION_CRT_WACPU_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX), \
                                                  MCUXCLRSA_KEYGENERATION_PLAIN_WACPU_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX)))
/* Macro determining maximum size of PKC workarea size for mcuxClPsaDriver_generate_rsa_key function */
#define MCUXCLPSADRIVER_RSA_KEY_GEN_BY_CLNS_WAPKC_SIZE_MAX  \
            MCUXCLCORE_MAX(MCUXCLRSA_KEYGENERATION_CRT_WAPKC_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX), \
                               MCUXCLRSA_KEYGENERATION_PLAIN_WAPKC_SIZE(MCUXCLPSADRIVER_RSA_KEY_SIZE_MAX))

/**
 * Internal types for structures containing CLNS internal data.
 * Such data includes key descriptors, component-specific contexts, ...
 */
typedef struct
{
    mcuxClCipherModes_Context_Aes_Els_t ctx;
    mcuxClKey_Descriptor_t keydesc;
} mcuxClPsaDriver_ClnsData_Cipher_t;


#define MCUXCLPSADRIVER_AEAD_KEYATT_SIZE 0x24u
typedef struct
{
    mcuxClAeadModes_Context_t ctx;
    mcuxClKey_Descriptor_t keydesc;
    uint32_t keyAttributes[MCUXCLPSADRIVER_AEAD_KEYATT_SIZE / sizeof(uint32_t)];
} mcuxClPsaDriver_ClnsData_Aead_t;

typedef struct
{
    mcuxClMacModes_Context_t ctx;
    mcuxClKey_Descriptor_t keydesc;
    psa_algorithm_t alg;
} mcuxClPsaDriver_ClnsData_Mac_t;

typedef struct
{
    mcuxClHash_ContextDescriptor_t ctx;
} mcuxClPsaDriver_ClnsData_Hash_t;

#endif /* MCUXCLPSADRIVER_INTERNAL_H_ */
