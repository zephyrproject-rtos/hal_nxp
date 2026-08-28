/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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
 * @file  mcuxClFfdh_KeyTypes.h
 * @brief FFDH related definitions to be used for key handling mechanisms of the mcuxClKey component
 */


#ifndef MCUXCLFFDH_KEYTYPES_H
#define MCUXCLFFDH_KEYTYPES_H

#include <mcuxClFfdh_Types.h>
#include <mcuxCsslAnalysis.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClFfdh_KeyTypeDescriptors mcuxClFfdh_KeyTypeDescriptors
 * @brief Definitions of FFDH related key type descriptors
 * @ingroup mcuxClFfdh
 * @{
 */

/***********************************************/
/* Key types for ffdhe2048                     */
/***********************************************/

/**
 * @brief Key type structure for public FFDHE2048 keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe2048_Pub;

/**
 * @brief Key type pointer for public FFDHE2048 keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe2048_Pub = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe2048_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private FFDHE2048 keys
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe2048_Priv;

/**
 * @brief Key type pointer for private FFDHE2048 keys
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe2048_Priv = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe2048_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for ffdhe3072                     */
/***********************************************/

/**
 * @brief Key type structure for public FFDHE3072 keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe3072_Pub;

/**
 * @brief Key type pointer for public FFDHE3072 keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe3072_Pub = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe3072_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private FFDHE3072 keys
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe3072_Priv;

/**
 * @brief Key type pointer for private FFDHE3072 keys
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe3072_Priv = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe3072_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


/***********************************************/
/* Key types for ffdhe4096                     */
/***********************************************/

/**
 * @brief Key type structure for public FFDHE4096 keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe4096_Pub;

/**
 * @brief Key type pointer for public FFDHE4096 keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe4096_Pub = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe4096_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private FFDHE4096 keys
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe4096_Priv;

/**
 * @brief Key type pointer for private FFDHE4096 keys
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe4096_Priv = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe4096_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/***********************************************/
/* Key types for ffdhe6144                     */
/***********************************************/

/**
 * @brief Key type structure for public FFDHE6144 keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe6144_Pub;

/**
 * @brief Key type pointer for public FFDHE6144 keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe6144_Pub = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe6144_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private FFDHE6144 keys
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe6144_Priv;

/**
 * @brief Key type pointer for private FFDHE6144 keys
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe6144_Priv = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe6144_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()


#ifdef MCUXCL_FEATURE_FFDH_RFC7919_FFDHE8192
/***********************************************/
/* Key types for ffdhe8192                     */
/***********************************************/

/**
 * @brief Key type structure for public FFDHE8192 keys.
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe8192_Pub;

/**
 * @brief Key type pointer for public FFDHE8192 keys.
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe8192_Pub = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe8192_Pub;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @brief Key type structure for private FFDHE8192 keys
 *
 */
extern const mcuxClKey_TypeDescriptor_t mcuxClKey_TypeDescriptor_Ffdh_ffdhe8192_Priv;

/**
 * @brief Key type pointer for private FFDHE8192 keys
 *
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static const mcuxClKey_Type_t mcuxClKey_Type_Ffdh_ffdhe8192_Priv = &mcuxClKey_TypeDescriptor_Ffdh_ffdhe8192_Priv;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()
#endif /* MCUXCL_FEATURE_FFDH_RFC7919_FFDHE8192 */

/**
 * @}
 */ /* mcuxClFfdh_KeyTypeDescriptors */

/**
 * @defgroup mcuxClFfdh_KeyAgreementDescriptors mcuxClFfdh_KeyAgreementDescriptors
 * @brief Definitions of FFDH related key agreement algorithm descriptors
 * @ingroup mcuxClFfdh
 * @{
 */

/**
 * @brief FFDH Key agreement algorithm descriptor
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("Forward declaration. Hence, it is declared but not defined in this file.")
extern const mcuxClKey_AgreementDescriptor_t mcuxClKey_AgreementDescriptor_FFDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()

/**
 * @brief FFDH Key agreement algorithm
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED("Consumed by mcuxClKey component. Hence, it is declared but never referenced.")
static mcuxClKey_Agreement_t mcuxClKey_Agreement_FFDH =
  &mcuxClKey_AgreementDescriptor_FFDH;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_REFERENCED()

/**
 * @}
 */ /* mcuxClFfdh_KeyAgreementDescriptors */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLFFDH_KEYTYPES_H */
