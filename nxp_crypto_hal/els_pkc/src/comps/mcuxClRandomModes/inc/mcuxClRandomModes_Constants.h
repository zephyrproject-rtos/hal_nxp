/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClRandomModes_Constants.h
 * @brief Mode definitions of mcuxClRandomModes component
 */

#ifndef MCUXCLRANDOMMODES_CONSTANTS_H_
#define MCUXCLRANDOMMODES_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClRandom_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Values for reseeds                                     */
/**********************************************************/


/**********************************************************/
/* Types of mcuxClRandom                                   */
/**********************************************************/
/**
 * @defgroup mcuxClRandomModes_Constants mcuxClRandom_Constants
 * @brief Defines all modes of @ref mcuxClRandomModes
 * @ingroup mcuxClRandom
 * @{
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @brief Mode for a DRBG implemented by the ELS
 *
 * This mode provides a function to get random values from a DRBG implemented by the ELS. The provided security strength
 * is HW dependent and can be determined using the function mcuxClRandom_checkSecurityStrength
 */
extern const mcuxClRandom_ModeDescriptor_t mcuxClRandomModes_mdELS_Drbg;
static const mcuxClRandom_Mode_t mcuxClRandomModes_Mode_ELS_Drbg =
    &mcuxClRandomModes_mdELS_Drbg;


#if defined(MCUXCL_FEATURE_RANDOMMODES_NORMALMODE) && defined(MCUXCL_FEATURE_RANDOMMODES_CTRDRBG)

#ifdef MCUXCL_FEATURE_RANDOMMODES_PR_DISABLED



#ifdef MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256

/**
 * @brief Mode for a NIST SP800-90A CTR_DRBG based on AES-256 configured to not provide prediction resistance and realize a DRG.3 at 256 bit security level.
 *
 * This mode realizes a NIST SP800-90A CTR_DRBG based on AES-256 which does not provide prediction resistance. It is designed in a way
 * to comply to FIPS 140-3 on the one hand and realize a DRG.3 at 256 bit security level on the other.
 * For an up to date list of evaluations and certifications one should refer to the product (HW) documentation.
 */
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("Definition is provided assuming library is built properly")
extern const mcuxClRandom_ModeDescriptor_t mcuxClRandomModes_mdCtrDrbg_AES256_DRG3;
static const mcuxClRandom_Mode_t mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3 =
    &mcuxClRandomModes_mdCtrDrbg_AES256_DRG3;
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()

/**
 * @brief Mode for a NIST SP800-90A CTR_DRBG based on AES-256 configured to not provide prediction resistance and realize a DRG.4 at 256 bit security level.
 *
 * This mode realizes a NIST SP800-90A CTR_DRBG based on AES-256 which does not provide prediction resistance. It is designed in a way
 * to comply to FIPS 140-3 on the one hand and realize a DRG.4 at 256 bit security level on the other.
 * For an up to date list of evaluations and certifications one should refer to the product (HW) documentation.
 *
* NOTE: This mode is an alias of mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3 and does not perform any internal reseeding.
* To realize the desired DRG.4 functionality by on-demand reseeding, the mcuxClRandom_reseed function is provided.
 */
#define mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG4 mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3

/**
 * @brief Mode for a NIST SP800-90A CTR_DRBG based on AES-256 configured to not provide prediction resistance.
 *
 * This mode realizes a NIST SP800-90A CTR_DRBG based on AES-256 which does not provide prediction resistance and
 * is designed in a way to comply to FIPS 140-3.
 * For an up to date list of evaluations and certifications one should refer to the product (HW) documentation.
 *
 * This is an alias of mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3, as both modes offer the same functionality.
 */
#define mcuxClRandomModes_Mode_CtrDrbg_AES256 mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3

#endif /* MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256 */

#endif /* MCUXCL_FEATURE_RANDOMMODES_PR_DISABLED */



#endif /* defined(MCUXCL_FEATURE_RANDOMMODES_NORMALMODE) && defined(MCUXCL_FEATURE_RANDOMMODES_CTRDRBG) */
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXTERNAL_API_DECLARATIONS()

/**
 * @}
 */ /* mcuxClRandom_Types */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_CONSTANTS_H_ */
