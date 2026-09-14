/*--------------------------------------------------------------------------*/
/* Copyright 2020-2022 NXP                                                  */
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

/** @file  mcuxClEls_GlitchDetector.h
 *  @brief ELS header for controlling the glitch detector.
 *
 * This header exposes functions that configure the ELS glitch detector. 
 */
 
#ifndef MCUXCLELS_GLITCHDETECTOR_H_
#define MCUXCLELS_GLITCHDETECTOR_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClEls_Common.h> // Common types & functionality

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClEls_GlitchDetector mcuxClEls_GlitchDetector
 * @brief This part of the @ref mcuxClEls driver supports glitch detector functionality
 * @ingroup mcuxClEls
 * @{
 */
 
/**********************************************
 * CONSTANTS
 **********************************************/
/**
 * @defgroup mcuxClEls_GlitchDetector_Macros mcuxClEls_GlitchDetector_Macros
 * @brief Defines all macros of @ref mcuxClEls_GlitchDetector
 * @ingroup mcuxClEls_GlitchDetector
 * @{
 */

#define MCUXCLELS_GLITCHDETECTOR_CFG_SIZE  ((size_t) 0x18u) ///< Glitch detector configuration size

#define MCUXCLELS_GLITCHDETECTOR_TRIM_SIZE  ((size_t) 0x04u) ///< Glitch detector trim value size

/**
 * @}
 */ /* mcuxClEls_GlitchDetector_Macros */

/**********************************************
 * FUNCTIONS
 **********************************************/
/**
 * @defgroup mcuxClEls_GlitchDetector_Functions mcuxClEls_GlitchDetector_Functions
 * @brief Defines all functions of @ref mcuxClEls_GlitchDetector
 * @ingroup mcuxClEls_GlitchDetector
 * @{
 */

/**
 * @brief Loads a glitch detector configuration.
 *
 * Call #mcuxClEls_WaitForOperation to complete the operation.
 *
 * @param[in]   Pointer to the memory area which contains the glitch detector configuration. The size is fixed at #MCUXCLELS_GLITCHDETECTOR_CFG_SIZE bytes.
 *
 * @retval #MCUXCLELS_STATUS_SW_INVALID_PARAM    if invalid parameters were specified
 * @retval #MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT if a running operation prevented the request
 * @retval #MCUXCLELS_STATUS_OK_WAIT             on successful request 
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @endif
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEls_GlitchDetector_LoadConfig_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_LoadConfig_Async(
    uint8_t const * pInput
    );

/** 
 * @brief Calculates optimal ELS glitch detector configuration and writes it to system memory.
 *
 * Call #mcuxClEls_WaitForOperation to complete the operation.
 *
 * @param[out]  Pointer to the memory area which receives the glitch detector trim value. The size is fixed at #MCUXCLELS_GLITCHDETECTOR_TRIM_SIZE bytes.
 *
 * @retval #MCUXCLELS_STATUS_SW_INVALID_PARAM    if invalid parameters were specified
 * @retval #MCUXCLELS_STATUS_SW_CANNOT_INTERRUPT if a running operation prevented the request
 * @retval #MCUXCLELS_STATUS_OK_WAIT             on successful request 
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @endif
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEls_GlitchDetector_Trim_Async)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_Trim_Async(
    uint8_t * pOutput 
    );

/** 
 * @brief Reads the glitch detector's event counter
 * 
 * This function converts the event counter from Gray code to an unsigned number.
 *
 * @param[in]   Pointer to the word where the counter value will be stored.
 *
 * @retval #MCUXCLELS_STATUS_OK                  on successful request 
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @endif
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEls_GlitchDetector_GetEventCounter)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_GetEventCounter(
    uint8_t * pCount 
    );

/** 
 * @brief Resets the glitch detector's event counter
 *
 * @retval #MCUXCLELS_STATUS_OK                  on successful request
 *
 * @if (MCUXCL_FEATURE_CSSL_FP_USE_SECURE_COUNTER && MCUXCL_FEATURE_CSSL_SC_USE_SW_LOCAL)
 *  @return A code-flow protected error code (see @ref mcuxCsslFlowProtection). The error code can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @else
 *  @return An error code that can be any error code in @ref MCUXCLELS_STATUS_, see individual documentation for more information
 * @endif
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClEls_GlitchDetector_ResetEventCounter)
MCUXCLELS_API MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClEls_Status_t) mcuxClEls_GlitchDetector_ResetEventCounter( void
    );
 
/**
 * @}
 */ /* mcuxClEls_GlitchDetector_Functions */
 
/**
 * @}
 */ /* mcuxClEls_GlitchDetector */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLELS_GLITCHDETECTOR_H_ */
