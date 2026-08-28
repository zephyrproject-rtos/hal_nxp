/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2023-2024, 2026 NXP                                      */
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

/**
 * @file  mcuxClRsa_Internal_PkcDefs.h
 * @brief Internal definitions of the mcuxClRsa component
 */

#ifndef MCUXCLRSA_INTERNAL_PKCDEFS_H_
#define MCUXCLRSA_INTERNAL_PKCDEFS_H_

#include <mcuxClConfig.h> // Exported features flags header

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_public                                                      */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_ MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_
 * @brief UPTR table defines for function mcuxClRsa_public.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_X         (0U) ///< UPTR table index for buffer x
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_N         (1U) ///< UPTR table index for buffer n
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T1        (2U) ///< UPTR table index for buffer t1
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T2        (3U) ///< UPTR table index for buffer t2
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_T3        (4U) ///< UPTR table index for buffer t3
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_OUTPUT    (5U) ///< UPTR table index for buffer output
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PUBLIC_RAND      (6U) ///< UPTR table index for blinding random number
#define MCUXCLRSA_INTERNAL_PUBLIC_UPTRT_SIZE           (7U) ///< UPTR table size of function mcuxClRsa_public

/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_privatePlain                                                */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_ MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_
 * @brief UPTR table defines for function mcuxClRsa_privatePlain.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_X         (0U) ///< UPTR table index for buffer x
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_R         (1U) ///< UPTR table index for buffer r
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_N         (2U) ///< UPTR table index for buffer n
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T0        (3U) ///< UPTR table index for buffer t0
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T1        (4U) ///< UPTR table index for buffer t1
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T2        (5U) ///< UPTR table index for buffer t2
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_T3        (6U) ///< UPTR table index for buffer t3
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_TE        (7U) ///< UPTR table index for buffer te
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVPLAIN_RAND      (8U) ///< UPTR table index for the buffer with random data used for bliding
#define MCUXCLRSA_INTERNAL_PRIVPLAIN_UPTRT_SIZE           (9U) ///< UPTR table size of function mcuxClRsa_privatePlain

/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_privateCRT                                                  */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_ MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_
 * @brief UPTR table defines for function mcuxClRsa_privateCRT.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_INPUT       (0U) ///< UPTR table index for the input buffer
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_RAND        (1U) ///< UPTR table index for the buffer with random data used for bliding
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PQ_B        (2U) ///< UPTR table index for buffer pq_b
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET0     (3U) ///< UPTR table index for buffer primeT0
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET1     (4U) ///< UPTR table index for buffer primeT1
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET2     (5U) ///< UPTR table index for buffer primeT2
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET3     (6U) ///< UPTR table index for buffer primeT3
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET4     (7U) ///< UPTR table index for buffer primeT4
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_TE          (8U) ///< UPTR table index for buffer primeTE
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_R           (9U) ///< UPTR table index for buffer r
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_PRIMET5     (10U) ///< UPTR table index for buffer primeT5
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_M           (11U) ///< UPTR table index for buffer m
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT1       (12U) ///< UPTR table index for buffer modT1
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT2       (13U) ///< UPTR table index for buffer modT2
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT3       (14U) ///< UPTR table index for buffer modT3
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_MODT4       (15U) ///< UPTR table index for buffer modT4
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_N           (16U) ///< UPTR table index for buffer n
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_PRIVCRT_CONST0      (17U) ///< UPTR table index for constant 0
#define MCUXCLRSA_INTERNAL_PRIVCRT_UPTRT_SIZE             (18U) ///< UPTR table size of function mcuxClRsa_privateCRT
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_Sign_NoEMSA                                                 */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_SIGN_NOEMSA_ MCUXCLRSA_INTERNAL_UPTRTINDEX_SIGN_NOEMSA_
 * @brief UPTR table defines for function mcuxClRsa_Sign_NoEMSA.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_SIGN_NOEMSA_OUT          (0U) ///< UPTR table index for buffer input
#define MCUXCLRSA_INTERNAL_SIGN_NOEMSA_UPTRT_SIZE              (1U) ///< UPTR table size of function mcuxClRsa_Sign_NoEMSA
/** @} */



/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_Util_KeyGeneration_Plain                                    */
/****************************************************************************/
/**
* @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_ MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_
* @brief UPTR table defines for function mcuxClRsa_Util_KeyGeneration_Plain.
* @ingroup mcuxClRsa_Internal_Macros
* @{
*/
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P            (0U) ///< UPTR table index for buffer p
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_Q            (1U) ///< UPTR table index for buffer q
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_E            (2U) ///< UPTR table index for buffer e
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_D            (3U) ///< UPTR table index for buffer d
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N            (4U) ///< UPTR table index for buffer n
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_RAND         (5U) ///< UPTR table index for buffer rand
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_P_B          (6U) ///< UPTR table index for buffer p_b
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_Q_B          (7U) ///< UPTR table index for buffer q_b
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_N_B          (8U) ///< UPTR table index for buffer n_b
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_PLAIN_RAND_SQUARE  (9U) ///< UPTR table index for buffer rand_square
#define MCUXCLRSA_INTERNAL_KEYGENERATION_PLAIN_UPTRT_SIZE              (10U) ///< UPTR table size of function mcuxClRsa_Util_KeyGeneration_Plain
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_Util_KeyGeneration_Crt                                      */
/****************************************************************************/
/**
* @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_ MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_
* @brief UPTR table defines for function mcuxClRsa_Util_KeyGeneration_Crt.
* @ingroup mcuxClRsa_Internal_Macros
* @{
*/
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_E            (0U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P            (1U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q            (2U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DP           (3U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_DQ           (4U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_QINV         (5U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T1           (6U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T2           (7U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_T3           (8U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N            (9U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND         (10U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_P_B          (11U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_Q_B          (12U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_N_B          (13U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_RAND_SQUARE  (14U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT0    (15U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_KEYGENERATION_CRT_CONSTANT1    (16U)
#define MCUXCLRSA_INTERNAL_KEYGENERATION_CRT_UPTRT_SIZE              (17U) ///< UPTR table size of function mcuxClRsa_Util_KeyGeneration_Crt
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_VerifyPlainKey                                              */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_PKCS1V15_ MCUXCLRSA_INTERNAL_UPTRTINDEX_PKCS1V15_
 * @brief UPTR table defines for function mcuxClRsa_pkcs1v15Verify
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFYPLAINKEY_OUTPUT       (0U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFYPLAINKEY_REF          (1U)
#define MCUXCLRSA_INTERNAL_VERIFYPLAINKEY_UPTRT_SIZE              (2U)
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_TestPrimeCandidate                                          */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_ MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_
 * @brief UPTR table defines for function mcuxClRsa_TestPrimeCandidate.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_E                 (0U) ///< UPTR table index for buffer e
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_CANDIDATE         (1U) ///< UPTR table index for buffer with prime candidate
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_CANDIDATE_64MOST  (2U) ///< UPTR table index for 64 most significant bits of prime candidate
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_NUMTOCOMPARE      (3U) ///< UPTR table index for buffer with number to compare
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_A0                (4U) ///< UPTR table index for buffer A0
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_GCD1              (5U) ///< UPTR table index for the first gcd operand
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_GCD2              (6U) ///< UPTR table index for the second gcd operand
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_CONSTANT0         (7U) ///< UPTR table index for the constant 0
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_CONSTANT1         (8U) ///< UPTR table index for the constant 1
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPRIME_CONSTANT2         (9U) ///< UPTR table index for the constant 2
#define MCUXCLRSA_INTERNAL_TESTPRIME_UPTRT_SIZE                   (10U) ///< UPTR table size of function mcuxClRsa_TestPrimeCandidate
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_GenerateProbablePrime                                       */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_ MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_
 * @brief UPTR table defines for function mcuxClRsa_GenerateProbablePrime.
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_NUMTOCOMPARE      (0U) ///< UPTR table index for buffer with number to compare
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_A0                (1U) ///< UPTR table index for buffer A0
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_CANDIDATE_LSWORD  (2U) ///< UPTR table index for least significant word of prime candidate
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_GENPRIME_WORD_CONST3       (3U) ///< UPTR table index for the pkc word with const 3
#define MCUXCLRSA_INTERNAL_GENPRIME_UPTRT_SIZE                   (4U) ///< UPTR table size of function mcuxClRsa_GenerateProbablePrime
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_MillerRabinTest                                             */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_ MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_
 * @brief UPTR table defines for function mcuxClRsa_MillerRabinTest
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_PRIMECANDIDATE   (0U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_QSQUARED         (1U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_RESULT           (2U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_X                (3U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_T0               (4U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_T1               (5U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_T2               (6U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_T3               (7U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_TE               (8U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_EXP              (9U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_CONSTANT         (10U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_NB               (11U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MILLERRABIN_R32              (12U)
#define MCUXCLRSA_INTERNAL_MILLERRABIN_UPTRT_SIZE                  (13U)
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_ComputeD                                                    */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_ MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_
 * @brief UPTR table defines for function mcuxClRsa_ComputeD
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_P                (0U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_Q                (1U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_D                (2U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_E                (3U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_LCM_B            (4U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PHI_B            (5U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_RND              (6U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1            (7U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1            (8U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_PSUB1_B          (9U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_QSUB1_B          (10U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_T0               (11U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_T1               (12U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_COMPD_CONSTANT         (13U)
#define MCUXCLRSA_INTERNAL_COMPD_UPTRT_SIZE                  (14U)
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_TestPQDistance                                              */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPQDISTANCE_ MCUXCLRSA_INTERNAL_UPTRTINDEX_TESTPQDISTANCE_
 * @brief UPTR table defines for function mcuxClRsa_TestPQDistance
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_P128MSB       (0U)
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_Q128MSB       (1U)
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T1            (2U)
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_T2            (3U)
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_RAND          (4U)
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_CONSTANT28    (5U)
#define MCUXCLRSA_INTERNAL_TESTPQDISTANCE_UPTRT_SIZE    (6U)
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_ModInv                                                      */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_ MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_
 * @brief UPTR table defines for function mcuxClRsa_ModInv
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_RND           (0U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_NB            (1U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_X             (2U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_R             (3U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_NB_ODD        (4U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_MODINV_NB_ODD_SHIFT  (5U)
#define MCUXCLRSA_INTERNAL_MODINV_UPTRT_SIZE               (6U)
/** @} */

/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_VerifyKey                                                   */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFYKEY_ MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFYKEY_
 * @brief UPTR table defines for function mcuxClRsa_VerifyKey
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_VERIFYKEY_PKCWA (0U)
/** @} */


/****************************************************************************/
/* Indices of operands in PKC workarea and UPTR table for                   */
/* the mcuxClRsa_RemoveBlinding                                              */
/****************************************************************************/
/**
 * @defgroup MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_ MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_
 * @brief UPTR table defines for function mcuxClRsa_RemoveBlinding
 * @ingroup mcuxClRsa_Internal_Macros
 * @{
 */
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_B             (0U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_NB            (1U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_X             (2U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_R             (3U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T1            (4U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_T2            (5U)
#define MCUXCLRSA_INTERNAL_UPTRTINDEX_REMOVEBLINDING_ZERO          (6U)
#define MCUXCLRSA_INTERNAL_REMOVEBLINDING_UPTRT_SIZE               (7U)
/** @} */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRSA_INTERNAL_PKCDEFS_H_ */


