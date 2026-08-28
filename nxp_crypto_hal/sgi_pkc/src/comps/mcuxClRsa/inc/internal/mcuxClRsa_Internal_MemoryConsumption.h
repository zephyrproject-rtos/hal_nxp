/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

/** @file  mcuxClRsa_Internal_MemoryConsumption.h
 *  @brief Internal memory consumption definitions of the mcuxClRsa component */

#ifndef MCUXCLRSA_INTERNAL_MEMORY_CONSUMPTION_H_
#define MCUXCLRSA_INTERNAL_MEMORY_CONSUMPTION_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClHash_Internal_Memory.h>
#include <internal/mcuxClRandomModes_Internal_SizeDefinitions.h>
#include <mcuxClRsa_KeyTypes.h>
#include <mcuxClKey_Constants.h>

#include <mcuxClCore_Macros.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClRsa_Internal_PkcDefs.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClRsa_Internal_Types.h>



#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/* Definitions of blinding size of Rsa modulus blinding                     */
/****************************************************************************/
#define MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE         (4UL)

/****************************************************************************/
/* Definitions of sizes for Rsa Verify functions                            */
/****************************************************************************/
#define MCUXCLRSA_SIZEOF_UPTRT_PKCWA 0U
#define MCUXCLRSA_SIZEOF_UPTRT_CPUWA MCUXCLMATH_SIZEOF_MATH_UPTRT

/***********************************************************************************************************************************/
/* Definition of PKC WA buffer sizes for the mcuxClRsa_privatePlain, mcuxClRsa_privateCrt and mcuxClRsa_Public functions. */
/***********************************************************************************************************************************/

#define MCUXCLRSA_INTERNAL_BLIND_ALIGN_SIZE(keyByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE))

#define MCUXCLRSA_INTERNAL_BUFF_SIZE(keyByteLength)  \
 (MCUXCLRSA_INTERNAL_BLIND_ALIGN_SIZE(keyByteLength) + MCUXCLRSA_PKC_WORDSIZE)
// Buffer size of the result of the exponentiation

#define MCUXCLRSA_INTERNAL_TE_BUFF_SIZE  \
 (6U*MCUXCLRSA_PKC_WORDSIZE)

// Buffer size of temp buffer TE

#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_INTERNAL_EXP_TEMP_BUFF_CRT_SIZE(primeByteLength) \
    (primeByteLength <= MCUXCLKEY_SIZE_6144/(2u*8u) ? MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength + 1u) : 0u) // size of buffer for expTemp - lengths of DP, DQ are not bigger than keybytelength

#ifdef MCUXCL_FEATURE_PKC_RAM_4KB
#define MCUXCLRSA_INTERNAL_EXP_TEMP_BUFF_PLAIN_SIZE(keyByteLength)  \
    (keyByteLength <= MCUXCLRSA_MAX_MODLEN_EXPTEMP_IN_PKCRAM ? MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(key ByteLength + 1u) : 0u)

#endif /*MCUXCL_FEATURE_PKC_RAM_4KB*/

#else
#define MCUXCLRSA_INTERNAL_EXP_TEMP_BUFF_CRT_SIZE(primeByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength + 1u)) /* size of buffer for expTemp - lengths of DP, DQ are not bigger than byteLenPQ */

#define MCUXCLRSA_INTERNAL_EXP_TEMP_BUFF_PLAIN_SIZE(keybytelength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keybytelength + 1U)) /* Size of buffer for expTemp in PKC RAM, assuming byteLenD is not bigger than keyByteLength. */

#endif /*MCUXCL_FEATURE_RSA_8K_KEYS*/

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_RemoveBlinding function.  */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_REMOVEBLINDING_WA MCUXCLRSA_INTERNAL_REMOVEBLINDING_WA
 * @brief Workarea size macros of mcuxClRsa_RemoveBlinding.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_BYTESIZE \
    MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE((MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_SIZE * sizeof(uint16_t)))
    ///< Definition of UPTRT size for mcuxClRsa_RemoveBlinding function.

#define MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_WAPKC_SIZE (0U)
#define MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_WACPU_SIZE MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_BYTESIZE
///< Definition of workarea sizes for the mcuxClRsa_RemoveBlinding function when UPTRT is in CPU RAM.

#define MCUXCLRSA_INTERNAL_REMOVEBLINDING_WACPU_SIZE \
    (MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_WACPU_SIZE)
    ///< Definition of CPU workarea size in words for the mcuxClRsa_RemoveBlinding function

#define MCUXCLRSA_INTERNAL_REMOVEBLINDING_WAPKC_SIZE  \
    (MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_WAPKC_SIZE)
    ///< Definition of total PKC workarea size for the mcuxClRsa_RemoveBlinding function
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_privatePlain function.    */
/****************************************************************************/

/**
 * @defgroup MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WA MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WA
 * @brief Workarea size macros of mcuxClRsa_privatePlain.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE_IN_BYTES \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE * sizeof(uint16_t)))

#define MCUXCLRSA_INTERNAL_PRIVATEPLAIN_UPTRT_SIZE_IN_WORDS \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE_IN_BYTES))

#define MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength) \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) + 2U * MCUXCLRSA_PKC_WORDSIZE)
    ///< Size of the input buffer for mcuxClRsa_privatePlain, that is allocated in PKC RAM.

#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength)  \
    MCUX_CSSL_ANALYSIS_START_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS() \
    (MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE_IN_BYTES \
     + ((keyByteLength) > MCUXCLRSA_MAX_MODLEN_EXPTEMP_IN_PKCRAM ? MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(keyByteLength) : 0U)) \
     MCUX_CSSL_ANALYSIS_STOP_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()
    ///< Definition of CPU workarea size for the mcuxClRsa_privatePlain function depending on the key byte-length.
    ///< Internally, it depends on the byte-length of the exponent, and it is rounded up here, based on the fact that d < n.
#else
#define MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength)  \
    MCUX_CSSL_ANALYSIS_START_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS() \
    (MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE_IN_BYTES \
      /* mcuxClRsa_RemoveBlinding */ \
      + MCUXCLRSA_INTERNAL_REMOVEBLINDING_WACPU_SIZE) \
     MCUX_CSSL_ANALYSIS_STOP_PATTERN_INVARIANT_EXPRESSION_WORKAREA_CALCULATIONS()
    ///< Definition of CPU workarea size for the mcuxClRsa_privatePlain function depending on the key byte-length.
#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE_IN_WORDS(keyByteLength) \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength)))

#define MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WAPKC_SIZE(keyByteLength)  \
    (6U * (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE)) + 12U * MCUXCLRSA_PKC_WORDSIZE \
     + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE) + ((keyByteLength) <= MCUXCLRSA_MAX_MODLEN_EXPTEMP_IN_PKCRAM ? MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE((keyByteLength) + 1U) : 0U) \
    /* mcuxClRsa_RemoveBlinding */ \
    + MCUXCLRSA_INTERNAL_REMOVEBLINDING_WAPKC_SIZE)
    ///< Definition of PKC workarea size for the mcuxClRsa_privatePlain function depending on the key byte-length.
/** @} */


/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_publicExp function.       */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PUBLICEXP_WA MCUXCLRSA_INTERNAL_PUBLICEXP_WA
 * @brief Workarea size macros of mcuxClRsa_publicExp.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_PUBLICEXP_WACPU_SIZE \
    (MCUXCLRSA_INTERNAL_REMOVEBLINDING_WACPU_SIZE)
    ///< Definition of CPU workarea size in words for the mcuxClRsa_publicExp function

#define MCUXCLRSA_INTERNAL_PUBLICEXP_WAPKC_SIZE \
    (MCUXCLRSA_INTERNAL_REMOVEBLINDING_WAPKC_SIZE)
    ///< Definition of total PKC workarea size for the mcuxClRsa_publicExp function depending on the key byte-length.
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_privateCRT function.      */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PRIVATECRT_WA MCUXCLRSA_INTERNAL_PRIVATECRT_WA
 * @brief Workarea size macros of mcuxClRsa_privateCRT.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_PRIVATECRT_UPRT_SIZE \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRSA_INTERNAL_PRIVCRT_UPTRT_SIZE * sizeof(uint16_t)))

#define MCUXCLRSA_INTERNAL_PRIVATECRT_UPRT_SIZE_IN_WORDS \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_PRIVATECRT_UPRT_SIZE))

#ifdef MCUXCL_FEATURE_RSA_8K_KEYS
#define MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength)  \
    (MCUXCLRSA_INTERNAL_PRIVATECRT_UPRT_SIZE \
     + ((primeByteLength) > MCUXCLKEY_SIZE_6144/(2U*8U) ? MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(primeByteLength) : 0U))
    ///< Definition of CPU workarea size for the mcuxClRsa_privateCRT function depending on the byte-length of p (equal to the byte-length of q).
    ///< Internally, it depends on the byte-lengths of the exponents dp and dq, and it is rounded up here, based on the fact that dp and dq are smaller than p and q.

#else
#define MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength)  \
    (MCUXCLRSA_INTERNAL_PRIVATECRT_UPRT_SIZE \
      /* mcuxClRsa_publicExp */ \
    + MCUXCLRSA_INTERNAL_PUBLICEXP_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_privateCRT function depending on the byte-length of p (equal to the byte-length of q).

#endif /* MCUXCL_FEATURE_RSA_8K_KEYS */

#define MCUXCLRSA_INTERNAL_PRIVATECRT_WAPKC_SIZE(primeByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE)  /* size of buffer for random multiplicative blinding */  \
    + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength) /* size of buffer for blinded P or Q, including PKW word for NDash */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength)  /* size of temporary buffer primeT0 */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength) /* size of temporary buffer primeT1 */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength)  /* size of temporary buffer primeT2 */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength)  /* size of temporary buffer primeT3 */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength)  /* size of temporary buffer primeT4 */  \
    + MCUXCLRSA_INTERNAL_TE_BUFF_SIZE  /* size of temporary buffer primeTE */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength)  /* size of temporary buffer R (result of the internal exponentiation) */ \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(primeByteLength) /* size of temporary buffer primeT5 */  \
    + MCUXCLRSA_INTERNAL_EXP_TEMP_BUFF_CRT_SIZE(primeByteLength),    /* Size of buffer for expTemp in PKC RAM */  \
    MCUXCLRSA_INTERNAL_BLIND_ALIGN_SIZE(2U * primeByteLength)   /* size of buffer for result M */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(2U * primeByteLength)  /* size of temporary buffer modT1*/  \
    + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(2U * primeByteLength) + 2U * MCUXCLRSA_PKC_WORDSIZE  /* size of temporary buffer modT2 */  \
    + MCUXCLRSA_INTERNAL_BUFF_SIZE(2U * primeByteLength)  /* size of blinded message modT3*/  \
    + 2U * MCUXCLRSA_INTERNAL_BLIND_ALIGN_SIZE(primeByteLength)  /* size of temporary buffer modT4*/  \
    + 2U * MCUXCLRSA_INTERNAL_BLIND_ALIGN_SIZE(primeByteLength) + MCUXCLRSA_PKC_WORDSIZE) \
    /* mcuxClRsa_publicExp */ \
    + MCUXCLRSA_INTERNAL_PUBLICEXP_WAPKC_SIZE) /* size of buffer for modulus N */
    ///< Definition of PKC workarea size for the mcuxClRsa_privateCRT function depending on the byte-length of p.

#define MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE_IN_WORDS(primeByteLength) \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength)))
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_public function.          */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PUBLIC_WA MCUXCLRSA_INTERNAL_PUBLIC_WA
 * @brief Workarea size macros of mcuxClRsa_public.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_BYTESIZE \
    MCUXCLPKC_ALIGN_TO_PKC_WORDSIZE((MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_SIZE * sizeof(uint16_t)))
    ///< Definition of UPTRT size for mcuxClRsa_public function.

#define MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_WAPKC_SIZE 0U
#define MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_WACPU_SIZE MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_BYTESIZE
///< Definition of workarea sizes for the mcuxClRsa_public function when UPTRT is in CPU RAM.

#define MCUXCLRSA_INTERNAL_PUBLIC_WACPU_SIZE \
    (MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_WACPU_SIZE \
    /* mcuxClRsa_publicExp */ \
    + MCUXCLRSA_INTERNAL_PUBLICEXP_WACPU_SIZE)
    ///< Definition of CPU workarea size in words for the mcuxClRsa_public function

#define MCUXCLRSA_INTERNAL_PUBLIC_OPERANDS_WAPKC_SIZE(keyByteLength) \
    (4U * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE((keyByteLength) + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE)) + 4U * MCUXCLRSA_PKC_WORDSIZE \
    + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE))
    ///< Definition of PKC workarea size for the mcuxClRsa_public function depending on the key byte-length.

#define MCUXCLRSA_INTERNAL_PUBLIC_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_WAPKC_SIZE + MCUXCLRSA_INTERNAL_PUBLIC_OPERANDS_WAPKC_SIZE(keyByteLength) \
    /* mcuxClRsa_publicExp */ \
    + MCUXCLRSA_INTERNAL_PUBLICEXP_WAPKC_SIZE)
    ///< Definition of total PKC workarea size for the mcuxClRsa_public function depending on the key byte-length.

#define MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength) \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) + 2U * MCUXCLRSA_PKC_WORDSIZE)
    ///< Size of the output buffer for mcuxClRsa_public, that is allocated in PKC RAM.

#define MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE_IN_WORDS(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength) / sizeof(uint32_t))
    ///< Size of the output buffer for mcuxClRsa_public in words, that is allocated in PKC RAM.
/** @} */


/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_Sign_NoEMSA function.     */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WA MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WA
 * @brief Workarea size macros of mcuxClRsa_Sign_NoEMSA.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WACPU_SIZE  \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE((MCUXCLRSA_INTERNAL_SIGN_NOEMSA_UPTRT_SIZE * sizeof(uint16_t))))
    ///< Definition of CPU workarea size for the mcuxClRsa_Sign_NoEMSA function.

#define MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WAPKC_SIZE  \
    0U
    ///< Definition of PKC workarea size for the mcuxClRsa_Sign_NoEMSA function.

#define MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WACPU_SIZE_IN_WORDS  \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WACPU_SIZE))
    ///< Definition of CPU workarea size in words for the mcuxClRsa_Sign_NoEMSA function.


/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_Verify_Compare_NoEMSA function.*/
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_COMPARE_NOEMSA_VERIFY_WA MCUXCLRSA_INTERNAL_COMPARE_NOEMSA_VERIFY_WA
 * @brief Workarea size macros of mcuxClRsa_Verify_Compare_NoEMSA.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_COMPARE_NOEMSA_VERIFY_WACPU_SIZE  MCUXCLRSA_SIZEOF_UPTRT_CPUWA
    ///< Definition of CPU workarea size for the mcuxClRsa_Verify_Compare_NoEMSA function.

#define MCUXCLRSA_INTERNAL_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
     MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_Verify_Compare_NoEMSA function depending on the key byte-length.

/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_Mgf1 function.            */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_MGF1_WA MCUXCLRSA_INTERNAL_MGF1_WA
 * @brief Workarea size macros of mcuxClRsa_Mgf1.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_MGF1_WACPU_SIZE  \
    (MCUXCLHASH_INTERNAL_WACPU_MAX)
    ///< Definition of CPU workarea size for the mcuxClRsa_Mgf1 function.

#define MCUXCLRSA_INTERNAL_MGF1_WAPKC_SIZE(inputLen, hashLen)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE((inputLen) + 4U + (hashLen)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Mgf1 function.

/*
 * Definitions of maximum size of PKC workarea for the mcuxClRsa_Mgf1 function
 * for PSSENCODE and PSSVERIFY.
 * This function allocate space for Input, Hash output and 4B of the counter.
 * This macro takes into account the fact that:
 * inputLength = hashLen <= MCUXCLRSA_HASH_MAX_SIZE
 */
 #define MCUXCLRSA_INTERNAL_PSS_MGF1_MAX_WAPKC_SIZE  \
    (MCUXCLRSA_INTERNAL_MGF1_WAPKC_SIZE(MCUXCLRSA_HASH_MAX_SIZE, MCUXCLRSA_HASH_MAX_SIZE))
    ///< Definition of PKC workarea size for the mcuxClRsa_Mgf1 function.

/*
 * Definitions of maximum size of PKC workarea for the mcuxClRsa_Mgf1 function
 * for OAEPENCODE and OAEPDECODE.
 * This function allocate space for Input, Hash output and 4B of the counter.
 * This macro takes into account the fact that:
 * a. inputLength = keyByteLength - hLen - 1 or inputLength = hLen
 * b. keyByteLength >= mLen + 2*hLen + 2 which means, that keyByteLength - hLen - 1 >= mLen + hLen + 1  > hLen
 */
 #define MCUXCLRSA_INTERNAL_OAEP_MGF1_MAX_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength + 3U))

    ///< Definition of PKC workarea size for the mcuxClRsa_Mgf1 function.

/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_pssEncode function.       */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PSSENCODE_WA MCUXCLRSA_INTERNAL_PSSENCODE_WA
 * @brief Workarea size macros of mcuxClRsa_pssEncode.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WAPKC_SIZE_WO_MGF1(keyByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(((keyByteLength) - 2U) + MCUXCLRSA_PSS_PADDING1_LEN + (keyByteLength /* pEm */) + (keyByteLength /* pH (emLen >= hLen + sLen + 2, hence hLen < emLen) */)))
    ///< Maximum size for the temp buffer in mcuxClRsa_pssEncode, based on the fact that emLen >= hLen + sLen + 2.

#define MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WACPU_SIZE  \
    MCUXCLCORE_MAX(MCUXCLHASH_INTERNAL_WACPU_MAX, MCUXCLRSA_INTERNAL_MGF1_WACPU_SIZE)
    ///< Definitions of maximum size of CPU workarea for the mcuxClRsa_pssEncode function.

#define MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WAPKC_SIZE_WO_MGF1(keyByteLength) \
     + MCUXCLRSA_INTERNAL_PSS_MGF1_MAX_WAPKC_SIZE)
    ///< Definitions of maximum size of PKC workarea for the mcuxClRsa_pssEncode function.
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_pssVerify function.       */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PSSVERIFY_WA MCUXCLRSA_INTERNAL_PSSVERIFY_WA
 * @brief Workarea size macros of mcuxClRsa_pssVerify.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WACPU_SIZE  \
    (MCUXCLRSA_INTERNAL_MGF1_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_pssVerify function.

/*
 * Definitions of maximum size of PKC workarea for the mcuxClRsa_pssVerify function without workarea size for MGF1 function.
 * This macro specifies the size of the space allocated for Hash (size hLen), salt (sLen) and padding1.
 * It takes into account the condition that emLen >= hLen + sLen + 2 -> hLen + sLen <= emLen - 2,
 * where emLen = keyByteLength (only byte-level granularity of keys is supported, thus keyBitLength is a multiple of 8).
 */
/* Having sLen rounding up to CPU word additionally 3B must be added. */
#define MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WAPKC_SIZE_WO_MGF1(keyByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE((((keyByteLength) - 2U /* hLen + sLen */ + 3U /* round up sLen to CPU word */) + MCUXCLRSA_PSS_PADDING1_LEN) \
     + (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(keyByteLength) - 1U) /* maskedDB  + H' */ \
    + (keyByteLength) /* Maximum size for the encoded message in mcuxClRsa_pssVerify */))
    ///< Definitions of maximum size of PKC workarea for the mcuxClRsa_pssVerify function without workarea size for MGF1 function.

#define MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WAPKC_SIZE_WO_MGF1(keyByteLength) \
     + MCUXCLRSA_INTERNAL_PSS_MGF1_MAX_WAPKC_SIZE)
    ///< Definitions of maximum size of PKC workarea for the mcuxClRsa_pssVerify function.

/** @} */

/*********************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_pkcs1v15Encode_sign function.  */
/*********************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WA MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WA
 * @brief Workarea size macros of mcuxClRsa_pkcs1v15Encode_sign.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WACPU_SIZE  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA
    ///< Definition of CPU workarea size for the mcuxClRsa_pkcs1v15Encode_sign function.

#define MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
      MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_pkcs1v15Encode_sign function.
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_pkcs1v15Verify function.  */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_WA MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_WA
 * @brief Workarea size macros of mcuxClRsa_pkcs1v15Verify.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_WACPU_SIZE  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA
    ///< Definition of CPU workarea size for the mcuxClRsa_pkcs1v15Verify function.

#define MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_ENC_BUFF_WAPKC_SIZE(keyByteLength) \
    MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength)

#define MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
      MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_ENC_BUFF_WAPKC_SIZE(keyByteLength) \
    + MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WAPKC_SIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_pkcs1v15Verify function.
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_oaepEncode function.      */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_OAEPENCODE_WA MCUXCLRSA_INTERNAL_OAEPENCODE_WA
 * @brief Workarea size macros of mcuxClRsa_oaepEncode.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_OAEPENCODE_WACPU_SIZE  \
    MCUXCLCORE_MAX(MCUXCLHASH_INTERNAL_WACPU_MAX, MCUXCLRSA_INTERNAL_MGF1_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_oaepEncode function.

#define MCUXCLRSA_INTERNAL_OAEPENCODE_WAPKC_SIZE_WO_MGF1(keyByteLength)  \
    (2U * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE((keyByteLength)-1U) + \
     4U * MCUXCLRSA_PKC_WORDSIZE /* takes into account the possible rounding up of the 4 buffers | db MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(dbLen) || seed MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(hLen) || dbMask MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(dbLen)  || seedMask MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(hLen) | */)
    ///< Definition of PKC workarea size for the mcuxClRsa_oaepEncode function, without taking into account the PKC WA usage of the MGF1

#define MCUXCLRSA_INTERNAL_OAEPENCODE_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_OAEPENCODE_WAPKC_SIZE_WO_MGF1(keyByteLength) \
     + MCUXCLRSA_INTERNAL_OAEP_MGF1_MAX_WAPKC_SIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_oaepEncode function.
/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_oaepDecode function.      */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_OAEPDECODE_WA MCUXCLRSA_INTERNAL_OAEPDECODE_WA
 * @brief Workarea size macros of mcuxClRsa_oaepDecode.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_OAEPDECODE_WACPU_SIZE  \
    MCUXCLCORE_MAX(MCUXCLHASH_INTERNAL_WACPU_MAX, MCUXCLRSA_INTERNAL_MGF1_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_oaepDecode function.

#define MCUXCLRSA_INTERNAL_OAEPDECODE_WAPKC_SIZE_WO_MGF1(keyByteLength)  \
    (2U * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_oaepDecode function, without taking into account the PKC WA usage of the MGF1

#define MCUXCLRSA_INTERNAL_OAEPDECODE_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_OAEPDECODE_WAPKC_SIZE_WO_MGF1(keyByteLength) \
     + MCUXCLRSA_INTERNAL_OAEP_MGF1_MAX_WAPKC_SIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_oaepDecode function.
/** @} */

/****************************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_pkcs1v15Encode_encrypt function.      */
/****************************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_ENCRYPT_WA MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_ENCRYPT_WA
 * @brief Workarea size macros of mcuxClRsa_pkcs1v15Encode_encrypt.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_ENCRYPT_WACPU_SIZE (0U)
    ///< Definition of CPU workarea size for the mcuxClRsa_pkcs1v15Encode_encrypt function.

#define MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_ENCRYPT_WAPKC_SIZE (0U)
    ///< Definition of PKC workarea size for the mcuxClRsa_pkcs1v15Encode_encrypt function.
/** @} */

/****************************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_pkcs1v15Decode_decrypt function.      */
/****************************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WA MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WA
 * @brief Workarea size macros of mcuxClRsa_pkcs1v15Decode_decrypt.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WACPU_SIZE (0U)
    ///< Definition of CPU workarea size for the mcuxClRsa_pkcs1v15Decode_decrypt function.

#define MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_pkcs1v15Decode_decrypt function.
/** @} */


/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_verify function.          */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_VERIFY_WA MCUXCLRSA_VERIFY_WA
 * @brief Workarea size macros of mcuxClRsa_verify.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WACPU_SIZE  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA \
    + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_COMPARE_NOEMSA_VERIFY_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PUBLIC_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_verify function using COMPARE_NOEMSA option.

#define MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WACPU_SIZE  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA \
    + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PUBLIC_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_verify function using PKCS1V15VERIFY option.


#define MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WACPU_SIZE  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA \
    + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PUBLIC_WACPU_SIZE)
    ///< Definition of CPU workarea size for the mcuxClRsa_verify function using PSSVERIFY option.

#define MCUXCLRSA_INTERNAL_VERIFY_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
     MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength)  \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PUBLIC_WAPKC_SIZE(keyByteLength),  \
                    MCUXCLRSA_INTERNAL_COMPARE_NOEMSA_VERIFY_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Verify function using COMPARE_NOEMSA option depending on the key byte-length.

#define MCUXCLRSA_INTERNAL_VERIFY_PKCS1V15VERIFY_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
     MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength)  \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PUBLIC_WAPKC_SIZE(keyByteLength),  \
                    MCUXCLRSA_INTERNAL_PKCS1V15VERIFY_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Verify function using PKCS1V15VERIFY option depending on the key byte-length.

#define MCUXCLRSA_INTERNAL_VERIFY_PSSVERIFY_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
      MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength)  \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PUBLIC_WAPKC_SIZE(keyByteLength),  \
                    MCUXCLRSA_INTERNAL_PSSVERIFY_MAX_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Verify function using PSSVERIFY option.


/** @} */


/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_sign function.            */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_SIGN_WA MCUXCLRSA_SIGN_WA
 * @brief Workarea size macros of mcuxClRsa_sign.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WACPU_SIZE(keyByteLength)  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
    MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength))
    ///< Definition of CPU workarea size for the mcuxClRsa_sign function using NOEMSA option and a private plain key.

#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WACPU_SIZE(keyByteLength)  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
    MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength))
    ///< Definition of CPU workarea size for the mcuxClRsa_sign function with pkcs1v15 encoding and a private plain key.

#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WACPU_SIZE(keyByteLength)  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
    MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength))
    ///< Definitions of CPU workarea size for the mcuxClRsa_sign function with pss encoding and a private plain key.

#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_NOEMSA_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA \
     + MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength)  \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WAPKC_SIZE,  \
                    MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Sign function using NOEMSA option and a private plain key.

#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_PSSENCODE_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA \
     + MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength)  \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WAPKC_SIZE(keyByteLength),  \
                    MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_sign function with pss encoding and a private plain key.

#define MCUXCLRSA_INTERNAL_SIGN_PLAIN_PKCS1V15ENCODE_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA \
     + MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength)  \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WAPKC_SIZE(keyByteLength),  \
                    MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_sign function with pkcs1v15 encoding and a private plain key.

#define MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WACPU_SIZE(primeByteLength)  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
    MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength))
    ///< Definition of CPU workarea size for the mcuxClRsa_sign function using NOEMSA option and a private CRT key.

#define MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WACPU_SIZE(primeByteLength)  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
    MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength))
    ///< Definition of CPU workarea size for the mcuxClRsa_sign function with pkcs1v15 encoding and a private CRT key.

#define MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WACPU_SIZE(primeByteLength)  \
    MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
    MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WACPU_SIZE,  \
                  MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength))
   ///< Definitions of CPU workarea size for the mcuxClRsa_sign function with pss encoding and a private CRT key.

#define MCUXCLRSA_INTERNAL_SIGN_CRT_NOEMSA_WAPKC_SIZE(primeByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
     MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(2U * primeByteLength) + \
     MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_NOEMSA_SIGN_WAPKC_SIZE, MCUXCLRSA_INTERNAL_PRIVATECRT_WAPKC_SIZE(primeByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Sign function using NOEMSA option and a private CRT key.

#define MCUXCLRSA_INTERNAL_SIGN_CRT_PSSENCODE_WAPKC_SIZE(primeByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(2U * primeByteLength) + \
     MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PSSENCODE_MAX_WAPKC_SIZE(2u * primeByteLength), MCUXCLRSA_INTERNAL_PRIVATECRT_WAPKC_SIZE(primeByteLength))))
    ///< Definition of PKC workarea size for the mcuxClRsa_sign function with pss encoding and a private CRT key.

#define MCUXCLRSA_INTERNAL_SIGN_CRT_PKCS1V15ENCODE_WAPKC_SIZE(primeByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
    MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(2U * primeByteLength) + \
     MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_SIGN_WAPKC_SIZE(2u * primeByteLength), MCUXCLRSA_INTERNAL_PRIVATECRT_WAPKC_SIZE(primeByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_sign function with pkcs1v15 encoding and a private CRT key.

/** @} */



/*****************************************************************************************/
/* Definitions of workarea size for the mcuxClRsa_MillerRabinTest function.               */
/*****************************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_MILLERRABINTEST_WA MCUXCLRSA_INTERNAL_MILLERRABINTEST_WA
 * @brief Workarea size macros of mcuxClRsa_MillerRabinTest
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
//The parameters are just to keep the API consistent
#define MCUXCLRSA_INTERNAL_MILLERRABINTEST_WACPU_SIZE_WO_RNG(primeByteLength)  \
    (0U)
///< Definition of CPU workarea size for the mcuxClRsa_MillerRabinTest function depending on the byte-length of primeByteLength.

#define MCUXCLRSA_INTERNAL_MILLERRABINTEST_WACPU_SIZE(primeByteLength)  \
    (MCUXCLRSA_INTERNAL_MILLERRABINTEST_WACPU_SIZE_WO_RNG(primeByteLength) + MCUXCLRANDOMMODES_CPUWA_MAXSIZE)

#define MCUXCLRSA_INTERNAL_MILLERRABINTEST_T_BUFFER_SIZE(primeByteLength)  \
    (10U * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength) + 8U * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE) + 14U * MCUXCLRSA_PKC_WORDSIZE)
    ///< Definition of PKC workarea size for the mcuxClRsa_MillerRabinTest function depending on the byte-length of primeByteLength.
/** @} */

/*****************************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_TestPrimeCandidate function.           */
/*****************************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WA MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WA
 * @brief Workarea size macros of mcuxClRsa_TestPrimeCandidate
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
#define MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WACPU_SIZE_WO_MILLERRABIN \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE((MCUXCLRSA_INTERNAL_TESTPRIME_UPTRT_SIZE * sizeof(uint16_t))))
///< Definition of CPU workarea size for the mcuxClRsa_TestPrimeCandidate function depending on the byte-length of primeByteLength without mcuxClRsa_MillerRabinTest

#define MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WACPU_SIZE_WO_MILLERRABIN_IN_WORDS  \
    ((MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WACPU_SIZE_WO_MILLERRABIN)))
    ///< Definition of CPU workarea size in words for the mcuxClRsa_TestPrimeCandidate function depending on the byte-length of primeByteLength without mcuxClRsa_MillerRabinTest
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()

#define MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WACPU_SIZE(primeByteLength)  \
    ((MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WACPU_SIZE_WO_MILLERRABIN)  \
     + MCUXCLRSA_INTERNAL_MILLERRABINTEST_WACPU_SIZE(primeByteLength))

#define MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WAPKC_SIZE(primeByteLength)  \
    (MCUXCLCORE_MAX(2U * MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength), \
                  MCUXCLRSA_INTERNAL_MILLERRABINTEST_T_BUFFER_SIZE(primeByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_TestPrimeCandidate function depending on the byte-length of primeByteLength.
/** @} */

/*****************************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_GenerateProbablePrime function.        */
/*****************************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WA MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WA
 * @brief Workarea size macros of mcuxClRsa_GenerateProbablePrime
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

//The parameters are just to keep the API consistent
#define MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE_WO_TESTPRIME_AND_MILLERRABIN(primeByteLength)  \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE((MCUXCLRSA_INTERNAL_GENPRIME_UPTRT_SIZE * sizeof(uint16_t))))
    ///< Definition of CPU workarea size for the mcuxClRsa_GenerateProbablePrime function depending on the byte-length of primeByteLength without mcuxClRsa_TestPrimeCandidate and mcuxClRsa_MillerRabinTest

#define MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE(primeByteLength)  \
    (MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE_WO_TESTPRIME_AND_MILLERRABIN(primeByteLength) \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WACPU_SIZE(primeByteLength), \
                    MCUXCLRANDOMMODES_CPUWA_MAXSIZE))
    ///< Definition of CPU workarea size for the mcuxClRsa_GenerateProbablePrime function depending on the byte-length of primeByteLength.

#define MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE_IN_WORDS_WO_TESTPRIME_AND_MILLERRABIN(primeByteLength)  \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE_WO_TESTPRIME_AND_MILLERRABIN(primeByteLength)))
    ///< Definition of CPU workarea size in words for the mcuxClRsa_GenerateProbablePrime function depending on the byte-length of primeByteLength without mcuxClRsa_TestPrimeCandidate and mcuxClRsa_MillerRabinTest

#define MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WO_TESTPRIMECANDIDATE_WAPKC_SIZE  \
    (3u * MCUXCLRSA_PKC_WORDSIZE)
    ///< Definition of PKC workarea size for the mcuxClRsa_GenerateProbablePrime function, without the workarea size of TestPrimeCandidate.

#define MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WAPKC_SIZE(primeByteLength)  \
    (MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WO_TESTPRIMECANDIDATE_WAPKC_SIZE \
     + MCUXCLRSA_INTERNAL_TESTPRIMECANDIDATE_WAPKC_SIZE(primeByteLength))
    ///< Definition of PKC workarea size for the mcuxClRsa_GenerateProbablePrime function depending on the byte-length of primeByteLength.

/** @} */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_ComputeD function.        */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_COMPD_WA MCUXCLRSA_COMPD_WA
 * @brief Workarea size macros of mcuxClRsa_ComputeD
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

#define MCUXCLRSA_INTERNAL_COMPUTED_WACPU_SIZE  \
    (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE((MCUXCLRSA_INTERNAL_COMPD_UPTRT_SIZE * sizeof(uint16_t))))

#define MCUXCLRSA_INTERNAL_COMPUTED_WACPU_SIZE_IN_WORDS  \
  (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_COMPUTED_WACPU_SIZE))
///< Definition of CPU workarea size in words for the mcuxClRsa_ComputeD function

#define MCUXCLRSA_INTERNAL_COMPUTED_WAPKC_SIZE(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_BUFF_SIZE(keyByteLength) + MCUXCLRSA_PKC_WORDSIZE /* Lcm_b, equal to (2u*blindedPrimePQAlignLen + MCUXCLRSA_PKC_WORDSIZE) for mcuxClMath_ExactDivide and mcuxClRsa_ModInv */  \
                               + MCUXCLRSA_INTERNAL_BUFF_SIZE(keyByteLength) /* Phi_b, equal to (2u*blindedPrimePQAlignLen) for mcuxClRsa_ComputeD_Steps3_FUP and mcuxClRsa_ModInv */  \
                               + MCUXCLRSA_PKC_WORDSIZE /* Rnd */  \
                               + 2U * (MCUXCLRSA_INTERNAL_BUFF_SIZE(keyByteLength))) /* T0 and T1. PSub1, QSub1, PSub1_b and QSub1_b will reuse it */

#define MCUXCLRSA_INTERNAL_COMPUTED_WAPKC_SIZE_IN_WORDS(keyByteLength)  \
    (MCUXCLRSA_INTERNAL_COMPUTED_WAPKC_SIZE(keyByteLength) / sizeof(uint32_t))

/** @} */

/***********************************************************************************************************************************/
/* Definitions of generated key data size for the mcuxClRsa_Util_KeyGeneration_Crt and mcuxClRsa_Util_KeyGeneration_Plain functions. */
/***********************************************************************************************************************************/
#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE_IN_BYTES \
  (MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE * sizeof(uint16_t)))

#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE_IN_WORDS \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE_IN_BYTES))

#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WACPU_SIZE(primeByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_CPUWA \
     + MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE_IN_BYTES \
     + MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE(0) \
     /* Key verification */ \
     + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(2U * (primeByteLength)) \
     + MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE(primeByteLength) \
     /* mcuxClRsa_RemoveBlinding */ \
     + MCUXCLRSA_INTERNAL_REMOVEBLINDING_WACPU_SIZE)

#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_WAPKC_SIZE(primeByteLength)  \
    /* Take the maximum WA for key generation and key verification */ \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
      MCUXCLCORE_MAX( \
      MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength) /* e */ \
       + (2U * (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength) + MCUXCLRSA_PKC_WORDSIZE)) /* p and q */ \
       + MCUXCLCORE_MAX(6U * (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength) + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE) + MCUXCLRSA_PKC_WORDSIZE) /* T1, T2, T3, dp, dq and qInv */ \
                        + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(2U*(primeByteLength)) + 2U * MCUXCLRSA_PKC_WORDSIZE /* n */ \
                        + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE) /* rand */ \
                        + 2U * (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(primeByteLength) + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE) + MCUXCLRSA_PKC_WORDSIZE) /* p_b + q_b */ \
                        + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE * 2U) + MCUXCLRSA_PKC_WORDSIZE /* randSquare*/ \
                        , \
                        MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WAPKC_SIZE(primeByteLength)) \
      , \
      (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(2U * (primeByteLength))) \
      + MCUXCLRSA_INTERNAL_PRIVATECRT_WAPKC_SIZE(primeByteLength)) \
      /* mcuxClRsa_RemoveBlinding */ \
      + MCUXCLRSA_INTERNAL_REMOVEBLINDING_WAPKC_SIZE)

#define MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_UPTRT_SIZE_IN_WORDS \
    (MCUXCLCORE_NUM_OF_CPUWORDS_CEIL(MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_UPTRT_SIZE * sizeof(uint16_t))))

#define MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WACPU_SIZE(keyByteLength)  \
    (MCUXCLRSA_SIZEOF_UPTRT_CPUWA \
     + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_UPTRT_SIZE * sizeof(uint16_t)) \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WACPU_SIZE(0), MCUXCLRSA_INTERNAL_COMPUTED_WACPU_SIZE) \
     /* Key verification */ \
     + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(keyByteLength) \
     + MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength), \
                     MCUXCLRSA_INTERNAL_PUBLIC_WACPU_SIZE))

#define MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_WAPKC_SIZE(keyByteLength)  \
    /* Take the maximum WA for key generation and key verification */ \
    (MCUXCLRSA_SIZEOF_UPTRT_PKCWA + \
      MCUXCLCORE_MAX( \
      (2U * (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength / 2U) + MCUXCLRSA_PKC_WORDSIZE)) \
        + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) \
        + MCUXCLCORE_MAX(2U *  MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength)  + MCUXCLRSA_PKC_WORDSIZE /* D and N + FW */ \
                        + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE) /* Rand */ \
                        + 4U * (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength / 2U) + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE)) /* P_b + Q_b + N_b */ \
                        + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(MCUXCLRSA_INTERNAL_MOD_BLINDING_SIZE * 2U) + MCUXCLRSA_PKC_WORDSIZE /* RandSquare + FW */ \
                        , \
                        MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_GENERATEPROBABLEPRIME_WAPKC_SIZE(keyByteLength / 2U), \
                                    (MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) + 2U * MCUXCLRSA_PKC_WORDSIZE) /* D + 2 FWs */ \
                                     + MCUXCLRSA_INTERNAL_COMPUTED_WAPKC_SIZE(keyByteLength))) \
      , \
      MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength) \
      + MCUXCLCORE_MAX(MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength), \
          MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WAPKC_SIZE(keyByteLength), MCUXCLRSA_INTERNAL_PUBLIC_WAPKC_SIZE(keyByteLength)))))

/**
 * @defgroup MCUXCLRSA_INTERNAL_KEYGENERATION_KEY_DATA_SIZE MCUXCLRSA_INTERNAL_KEYGENERATION_KEY_DATA_SIZE
 * @brief Definitions of bufer sizes for the mcuxClRsa_Util_KeyGeneration_Crt and mcuxClRsa_Util_KeyGeneration_Plain functions.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_KEY_DATA_SIZE(keyByteLength)  \
    (2U * (keyByteLength))
    ///< Definition of buffer size for the key generation functions for private plain or public key data (i.e.: n, d or e).

#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_KEY_DATA_SIZE(keyByteLength)  \
    (5U * (((keyByteLength) + 1U) / 2U))
    ///< Definition of buffer size for the key generation functions for private CRT key data (i.e.: p, q, qInv, dp, dq).

#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRTDFA_KEY_DATA_SIZE(keyByteLength)  \
    (5U * (((keyByteLength) + 1U) / 2U) + (keyByteLength))
    ///< Definition of buffer size for the key generation functions for private CRT DFA key data (i.e.: p, q, qInv, dp, dq, e).

#define MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_PLAIN_DATA_SIZE(keyByteLength)  \
    (sizeof(mcuxClRsa_KeyData_Plain_t) \
     + MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_KEY_DATA_SIZE(keyByteLength)) \
    ///< Definition of buffer size for mcuxClRsa_KeyGeneration_GenerateKeyPair for plain keys (key entries followed by the key data, i.e.: n, d or e).

#define MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRT_DATA_SIZE(keyByteLength)  \
    (sizeof(mcuxClRsa_KeyData_Crt_t) \
     + MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_KEY_DATA_SIZE(keyByteLength))
    ///< Definition of buffer size for mcuxClRsa_KeyGeneration_GenerateKeyPair for CRT keys (key entries followed by the key data, i.e.:  p, q, qInv, dp, dq).

#define MCUXCLRSA_INTERNAL_KEYGENERATION_KEYPAIR_CRTDFA_DATA_SIZE(keyByteLength) \
    (sizeof(mcuxClRsa_KeyData_Crt_t) \
     + MCUXCLRSA_INTERNAL_KEYGENERATION_CRTDFA_KEY_DATA_SIZE(keyByteLength))
    ///< Definition of buffer size for mcuxClRsa_KeyGeneration_GenerateKeyPair for CRT keys (key entries followed by the key data, i.e.:  p, q, qInv, dp, dq, e).
/** @} */



#ifdef MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_Util_encrypt function.    */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WA MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WA
 * @brief Workarea size macros of mcuxClRsa_Util_encrypt.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

/* mcuxClRsa_Encrypt_NoEME doesn't allocate CPU WA */
#define MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WACPU_SIZE(keyByteLength)  \
        MCUXCLRSA_SIZEOF_UPTRT_CPUWA + \
        MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PUBLIC_WACPU_SIZE, \
                      MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_OAEPENCODE_WACPU_SIZE, \
                                    MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_ENCRYPT_WACPU_SIZE))
    ///< Definition of CPU workarea size for the mcuxClRsa_Util_encrypt function depending on the key byte-length.

/* mcuxClRsa_Encrypt_NoEME doesn't allocate PKC WA */
#define MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_WAPKC_SIZE(keyByteLength)  \
        (MCUXCLRSA_SIZEOF_UPTRT_PKCWA \
         + MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength) /* padded message */ \
         + MCUXCLCORE_MAX( \
                      MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_OAEPENCODE_WAPKC_SIZE(keyByteLength), \
                                   MCUXCLRSA_INTERNAL_PKCS1V15ENCODE_ENCRYPT_WAPKC_SIZE), \
                      MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength) \
                      + MCUXCLRSA_INTERNAL_PUBLIC_WAPKC_SIZE(keyByteLength)))
    ///< Definition of PKC workarea size for the mcuxClRsa_Util_encrypt function depending on the key byte-length.

#define MCUXCLRSA_INTERNAL_UTIL_ENCRYPT_OUTPUT_BUFF_WAPKC_SIZE_IN_WORDS(keyByteLength)  \
   (MCUXCLRSA_INTERNAL_PUBLIC_OUTPUT_SIZE(keyByteLength) / (sizeof(uint32_t)))
   ///< Definition of PKC output buffer workarea size for the mcuxClRsa_Util_encrypt function depending on the key word-length.

/** @} */

#endif /* MCUXCL_FEATURE_CIPHER_RSA_ENCRYPT */

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_Util_Sign function.    */
/****************************************************************************/
#define MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(keyByteLength, keyAlgoId)  \
    ((MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN == (keyAlgoId)) ? MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength) : MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength))

#ifdef MCUXCL_FEATURE_CIPHER_RSA_DECRYPT

/****************************************************************************/
/* Definitions of workarea sizes for the mcuxClRsa_Util_decrypt function.    */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WA MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WA
 * @brief Workarea size macros of mcuxClRsa_Util_decrypt.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */

/* mcuxClRsa_Decrypt_NoEME doesn't allocate CPU WA */
#define MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WACPU_SIZE(keyByteLength)  \
            (MCUXCLRSA_SIZEOF_UPTRT_CPUWA \
             + MCUXCLCORE_ALIGN_TO_CPU_WORDSIZE(keyByteLength) \
             + MCUXCLCORE_MAX( \
                           MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_OAEPDECODE_WACPU_SIZE, \
                                        MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WACPU_SIZE), \
                           MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WACPU_SIZE(keyByteLength), \
                                        MCUXCLRSA_INTERNAL_PRIVATECRT_WACPU_SIZE((((keyByteLength) + 1U)/ 2U)))))
        ///< Definition of CPU workarea size for the mcuxClRsa_Util_decrypt function.

#define MCUXCLRSA_INTERNAL_UTIL_DECRYPT_INPUT_BUFFER_WAPKC_SIZE(keyByteLength, keyAlgoId)  \
    MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(keyByteLength, keyAlgoId)
    /** @} */

/* mcuxClRsa_Decrypt_NoEME doesn't allocate PKC WA */
#define MCUXCLRSA_INTERNAL_UTIL_DECRYPT_WAPKC_SIZE(keyByteLength, keyAlgoId)  \
            (MCUXCLRSA_SIZEOF_UPTRT_PKCWA \
             + MCUXCLRSA_INTERNAL_UTIL_DECRYPT_INPUT_BUFFER_WAPKC_SIZE(keyByteLength, keyAlgoId) + \
              MCUXCLCORE_MAX( \
                            MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_OAEPDECODE_WAPKC_SIZE(keyByteLength),              \
                                         MCUXCLRSA_INTERNAL_PKCS1V15DECODE_DECRYPT_WAPKC_SIZE(keyByteLength)),  \
                           (MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PRIVATEPLAIN_INPUT_SIZE(keyByteLength),            \
                                         MCUXCLRSA_ALIGN_TO_PKC_WORDSIZE(keyByteLength)) +                      \
                            MCUXCLCORE_MAX(MCUXCLRSA_INTERNAL_PRIVATEPLAIN_WAPKC_SIZE(keyByteLength),            \
                                         MCUXCLRSA_INTERNAL_PRIVATECRT_WAPKC_SIZE((((keyByteLength) + 1U)/ 2U))))))
        ///< Definition of PKC workarea size for the mcuxClRsa_Util_decrypt function depending on the key byte-length.
#endif /* MCUXCL_FEATURE_CIPHER_RSA_DECRYPT */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_INTERNAL_MEMORY_CONSUMPTION_H_ */

