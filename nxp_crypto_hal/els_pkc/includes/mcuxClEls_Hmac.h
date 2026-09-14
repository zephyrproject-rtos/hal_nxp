/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * @file  mcuxClEls_Hmac.h
 * @brief ELS header for HMAC support.
 * 
 * This header exposes functions that enable using the ELS for the generation of hashed-key message authentication
 * codes (HMAC).
 * The supported hash algorithm is SHA2-256.
 */

/**
 * @defgroup mcuxClEls_Hmac mcuxClEls_Hmac
 * @brief This part of the @ref mcuxClEls driver supports functionality for hashed-key message authentication codes.
 * @ingroup mcuxClEls
 * @{
 */
#ifndef MCUXCLELS_HMAC_H_
#define MCUXCLELS_HMAC_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClEls_Common.h> // Common functionality

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * MACROS
 **********************************************/
/**
 * @defgroup mcuxClEls_Hmac_Macros mcuxClEls_Hmac_Macros
 * @brief Defines all macros of @ref mcuxClEls_Hmac
 * @ingroup mcuxClEls_Hmac
 * @{
 */
/**
 * @defgroup MCUXCLELS_HMAC_EXTERNAL_KEY_ MCUXCLELS_HMAC_EXTERNAL_KEY_
 * @brief Defines valid options to be used by #mcuxClEls_HmacOption_t
 * @ingroup mcuxClEls_Hmac_Macros
 * @{
 */
#define MCUXCLELS_HMAC_EXTERNAL_KEY_ENABLE  1U ///< Set #mcuxClEls_HmacOption_t.extkey to this value to use an external key
#define MCUXCLELS_HMAC_EXTERNAL_KEY_DISABLE 0U ///< Set #mcuxClEls_HmacOption_t.extkey to this value to use a key from the ELS keystore
/**
 * @}
 */

#define MCUXCLELS_HMAC_PADDED_KEY_SIZE ((size_t) 64U) ///< HMAC Key size: 64 bytes
#define MCUXCLELS_HMAC_OUTPUT_SIZE ((size_t) 32U)     ///< HMAC Output size: 32 bytes
/**
 * @}
 */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClEls_Hmac_Types mcuxClEls_Hmac_Types
 * @brief Defines all types of @ref mcuxClEls_Hmac
 * @ingroup mcuxClEls_Hmac
 * @{
 */
/**
 * @brief Command option bit field for #mcuxClEls_Hmac_Async.
 * 
 * Valid option values can be found under @ref MCUXCLELS_HMAC_EXTERNAL_KEY_.
 */
typedef union
{
    struct
    {
        uint32_t value; ///< Accesses the bit field as a full word
    } word;             ///< Access #mcuxClEls_CipherOption_t word-wise
    struct
    {
        uint32_t :13;       ///< RFU
        uint32_t extkey :1; ///< Whether an external key should be used
        uint32_t :18;       ///< RFU
    } bits;                 ///< Access #mcuxClEls_CipherOption_t word-wise
} mcuxClEls_HmacOption_t;
/**
 * @}
 */

/**********************************************
 * FUNCTIONS
 **********************************************/
/**
 * @defgroup mcuxClEls_Hmac_Functions mcuxClEls_Hmac_Functions
 * @brief Defines all functions of @ref mcuxClEls_Hmac
 * @ingroup mcuxClEls_Hmac
 * @{
 */
/**
 * @brief Performs HMAC with SHA-256.
 * 
 * @if MCUXCL_FEATURE_ELS_SHA_DIRECT
 * It must be ensured that SHA-Direct mode is disabled when calling this function (see #mcuxClEls_ShaDirect_Disable).
 * @endif
 * 
 * Call #mcuxClEls_WaitForOperation to complete the operation.
 *
 * @param[in]      options     The command options. For more information, see #mcuxClEls_HmacOption_t.
 * @param[in]      keyIdx      The HMAC key index, if an internal key shall be used
 * @param[in]      pPaddedKey  Pointer to a memory location containing the padded HMAC key
 * @param[in]      pInput      Pointer to a memory location which contains the data to be authenticated
 * @param[in]      inputLength Size of @p pInput in bytes
 * @param    [out] pOutput     The output message authentication code
 * 
 * The properties of some parameters change with respect to selected options.
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>@p options.extkey == #MCUXCLELS_HMAC_EXTERNAL_KEY_ENABLE</dt>
 *          <dd>@p keyIdx is ignored.
 * 
 *          @p pPaddedKey must contain the padded HMAC key, which can mean one of two things depending on the length of the original HMAC key, L<sub>kHMAC</sub>:
 *          <ul><li>If L<sub>kHMAC</sub> &le; #MCUXCLELS_HMAC_PADDED_KEY_SIZE, @p pPaddedKey must be the HMAC key padded with zero-bytes to fill the required length of #MCUXCLELS_HMAC_PADDED_KEY_SIZE bytes.</li>
 * 
 *          <li>If L<sub>kHMAC</sub> &gt; #MCUXCLELS_HMAC_PADDED_KEY_SIZE, @p pPaddedKey must contain the SHA-256 hash of the HMAC key, padded with zero-bytes to fill the required length of #MCUXCLELS_HMAC_PADDED_KEY_SIZE bytes.</li></ul></dd>
 * 
 *      <dt>@p options.extkey == #MCUXCLELS_HMAC_EXTERNAL_KEY_DISABLE</dt>
 *          <dd>@p keyIdx must be a valid key index with the correct usage rights for HMAC.
 * 
 *          @p pPaddedKey is ignored.</dd>
 *
 *  </dl></dd>
 * </dl>
 * 
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @endif
 * @retval #MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT if a running operation prevented the request
 * @retval #MCUXCLELS_STATUS_OK_WAIT             on successful request */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEls_Hmac_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_Hmac_Async(
    mcuxClEls_HmacOption_t options,
    mcuxClEls_KeyIndex_t keyIdx,
    uint8_t const * pPaddedKey,
    uint8_t const * pInput,
    size_t inputLength,
    uint8_t * pOutput
    );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLELS_HMAC_H_ */
/**
 * @}
 * 
 * @}
 */
