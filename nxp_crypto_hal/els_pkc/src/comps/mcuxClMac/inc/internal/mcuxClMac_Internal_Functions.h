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

/** @file  mcuxClMac_Internal_Functions.h
 *  @brief Internal header for the MAC internal functions
 */

#ifndef MCUXCLMAC_INTERNAL_FUNCTIONS_H_
#define MCUXCLMAC_INTERNAL_FUNCTIONS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMac_Types.h>
#include <internal/mcuxClMac_Ctx.h>

#include <mcuxCsslFlowProtection.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Inline functions for proper type casts */

/**
 * @brief Cast a pointer to word-aligned data to a pointer to the mcuxClMac_Context_t type.
 *
 * @param pContext    The pointer to cast to a proper context type. Must be aligned. Must point to an area of enough size.
*/
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_castToMacContext)
static inline mcuxClMac_Context_t* mcuxClMac_castToMacContext(uint32_t* pContext)
{
  MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
  return (mcuxClMac_Context_t*) pContext;
  MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
}


/**
 * @brief Computes the CRC for a MAC context struct (without the CRC value member) and saves it in the struct.
 *
 * When the MAC_CONTEXT_INTEGRITY_PROTECTION feature is not active, the function does nothing.
 *
 * @param[in,out]     pCtx            Pointer to the MAC context struct.
 * @param[in]         contextSize     Size of the MAC context struct in bytes (including the CRC value member).
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_computeContextCrc)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMac_computeContextCrc(mcuxClMac_Context_t * const pCtx, uint32_t contextSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMac_computeContextCrc);


  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClMac_computeContextCrc);
}

/**
 * @brief Verifies the CRC of a MAC context struct.
 *
 * The function computes the CRC for a MAC context struct (without the CRC value member) and checks if it is equal
 * to the saved CRC value within the struct.
 * When the MAC_CONTEXT_INTEGRITY_PROTECTION feature is not active, the function always returns MCUXCLMAC_STATUS_OK.
 *
 * @param[in]         pCtx            Pointer to the MAC context struct.
 * @param[in]         contextSize     Size of the MAC context struct in bytes (including the CRC value member).
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLMAC_STATUS_OK               Mac operation successful
 * @retval MCUXCLMAC_STATUS_FAULT_ATTACK     Fault attack detected
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClMac_verifyContextCrc)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMac_verifyContextCrc(mcuxClMac_Context_t * const pCtx, uint32_t contextSize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClMac_verifyContextCrc);

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClMac_verifyContextCrc, MCUXCLMAC_STATUS_OK);

}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMAC_INTERNAL_FUNCTIONS_H_ */
