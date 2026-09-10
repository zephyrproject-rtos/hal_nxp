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
 * @file  mcuxClEls_Cmac.h
 * @brief ELS header for CMAC support.
 * This header exposes functions that enable using the ELS for the generation of cipher-based message authentication
 * codes (CMAC).
 * The supported cipher algorithm is AES-128 and AES-256.
 */

/**
 * @defgroup mcuxClEls_Cmac mcuxClEls_Cmac
 * @brief This part of the @ref mcuxClEls driver supports functionality for cipher-based message authentication codes (CMAC).
 * @ingroup mcuxClEls
 * @{
 */

#ifndef MCUXCLELS_CMAC_H_
#define MCUXCLELS_CMAC_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClEls_Common.h> // Common functionality

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************
 * MACROS
 **********************************************/
/**
 * @defgroup mcuxClEls_Cmac_Macros mcuxClEls_Cmac_Macros
 * @brief Defines all macros of @ref mcuxClEls_Cmac
 * @ingroup mcuxClEls_Cmac
 * @{
 */

/**
 * @defgroup MCUXCLELS_CMAC_KEY_SIZE_ MCUXCLELS_CMAC_KEY_SIZE_
 * @brief Valid CMAC key sizes in bytes
 * @ingroup mcuxClEls_Cmac_Macros
 * @{ */
#define MCUXCLELS_CMAC_KEY_SIZE_128 ((size_t) 16U) ///< Size of 128 bit CMAC key (16 bytes)
#define MCUXCLELS_CMAC_KEY_SIZE_256 ((size_t) 32U) ///< Size of 256 bit CMAC key (32 bytes)
/** @} */

/**
 * @defgroup MCUXCLELS_CMAC_ MCUXCLELS_CMAC_
 * @brief Option values for #mcuxClEls_CmacOption_t
 * @ingroup mcuxClEls_Cmac_Macros
 * @{ */
#define MCUXCLELS_CMAC_EXTERNAL_KEY_ENABLE  1U ///< Set #mcuxClEls_CmacOption_t.extkey to this value to use an external key
#define MCUXCLELS_CMAC_EXTERNAL_KEY_DISABLE 0U ///< Set #mcuxClEls_CmacOption_t.extkey to this value to use a key from the ELS keystore
#define MCUXCLELS_CMAC_INITIALIZE_DISABLE   0U ///< Set #mcuxClEls_CmacOption_t.initialize to this value if the message chunk does not include the first block of the message
#define MCUXCLELS_CMAC_INITIALIZE_ENABLE    1U ///< Set #mcuxClEls_CmacOption_t.initialize to this value if the message chunk includes the first block of the message
#define MCUXCLELS_CMAC_FINALIZE_DISABLE     0U ///< Set #mcuxClEls_CmacOption_t.finalize to this value if the message chunk does not include the last block of the message
#define MCUXCLELS_CMAC_FINALIZE_ENABLE      1U ///< Set #mcuxClEls_CmacOption_t.finalize to this value if the message chunk includes the last block of the message
/**
 * @}
 */

#define MCUXCLELS_CMAC_OUT_SIZE ((size_t) 16U) ///< Size of CMAC output: 128 bit (16 bytes)

/**
 * @}
 */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClEls_Cmac_Types mcuxClEls_Cmac_Types
 * @brief Defines all types of @ref mcuxClEls_Cmac
 * @ingroup mcuxClEls_Cmac
 * @{
 */
/**
 * @brief Command option bit field for #mcuxClEls_Cmac_Async.
 */
typedef union
{
    struct
    {
        uint32_t value; ///< Accesses the bit field as a full word
    } word;             ///< Access #mcuxClEls_CmacOption_t word-wise
    struct
    {
        uint32_t initialize : 1; ///< Request initial processing for the first block of the message
        uint32_t finalize : 1;   ///< Request final processing for the last block of the message
        uint32_t soe : 1;        ///< This field is managed internally
        uint32_t sie : 1;        ///< This field is managed internally
        uint32_t :9;             ///< RFU
        uint32_t extkey :1;      ///< An external key should be used
        uint32_t :18;            ///< RFU
    } bits;                      ///< Access #mcuxClEls_CmacOption_t bit-wise
} mcuxClEls_CmacOption_t;
/**
 * @}
 */

/**********************************************
 * FUNCTIONS
 **********************************************/
/**
 * @defgroup mcuxClEls_Cmac_Functions mcuxClEls_Cmac_Functions
 * @brief Defines all functions of @ref mcuxClEls_Cmac
 * @ingroup mcuxClEls_Cmac
 * @{
 */
/**
 * @brief Performs CMAC with AES-128 or AES-256
 * 
 * @if ELS_AES_WITH_SIDE_CHANNEL_PROTECTION
 * Before execution, ELS will wait until #mcuxClEls_HwState_t.drbgentlvl == #MCUXCLELS_STATUS_DRBGENTLVL_LOW. This can lead to a delay if the DRBG is in a state with less security strength at the time of the call.
 * @endif
 * 
 * Call #mcuxClEls_WaitForOperation to complete the operation.
 *
 * @param[in]      options     The command options. For more information, see #mcuxClEls_CmacOption_t.
 * @param[in]      keyIdx      The CMAC key index
 * @param[in]      pKey        Pointer to the padded CMAC key
 * @param[in]      keyLength   Size of @p pKey in bytes. Must be a @ref MCUXCLELS_CMAC_KEY_SIZE_ "valid CMAC key size". See the parameter properties section in the function description.
 * @param[in]      pInput      Pointer to a memory location which contains the data, padded via SP 800-38b standard, to be authenticated
 * @param[in]      inputLength Size of @p pInput in bytes before padding
 * @param[in, out] pMac        Pointer to the CMAC command state input/output. See the parameter properties section in the function description.
 * 
 * The properties of some parameters change with respect to selected options.
 *
 * <dl>
 *  <dt>Parameter properties</dt>
 *
 *  <dd><dl>
 *      <dt>@p options.extkey == #MCUXCLELS_CMAC_EXTERNAL_KEY_ENABLE</dt>
 *          <dd>@p keyIdx is ignored.</dd>
 *
 *      <dt>@p options.extkey == #MCUXCLELS_CMAC_EXTERNAL_KEY_DISABLE</dt>
 *          <dd>@p pKey is ignored.
 *
 *          @p keyLength is ignored.</dd>
 * 
 *      <dt>(@p options.finalize == #MCUXCLELS_CMAC_FINALIZE_DISABLE)</dt>
 *          <dd>The intermediate state is written to @p pMac. </dd>
 * 
 *      <dt>@p options.finalize == #MCUXCLELS_CMAC_FINALIZE_ENABLE</dt>
 *          <dd>The resulting MAC is written to @p pMac.
 * 
 *          @p options.soe is ignored.</dd>
 *  </dl></dd>
 * </dl>
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @endif
 * @retval #MCUXCLELS_STATUS_SW_INVALID_PARAM    if an invalid parameter was specified
 * @retval #MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT if a running operation prevented the request
 * @retval #MCUXCLELS_STATUS_OK_WAIT             on successful request */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEls_Cmac_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_Cmac_Async(
    mcuxClEls_CmacOption_t options,
    mcuxClEls_KeyIndex_t keyIdx,
    uint8_t const * pKey,
    size_t keyLength,
    uint8_t const * pInput,
    size_t inputLength, 
    uint8_t * pMac
    );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLELS_CMAC_H_ */

/**
 * @}
 * 
 * @}
 */
