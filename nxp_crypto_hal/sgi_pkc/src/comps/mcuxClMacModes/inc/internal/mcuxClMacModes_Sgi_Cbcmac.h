/*--------------------------------------------------------------------------*/
/* Copyright 2020-2026 NXP                                                  */
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

#ifndef MCUXCLMACMODES_SGI_CBCMAC_H_
#define MCUXCLMACMODES_SGI_CBCMAC_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>

#include <mcuxClMac_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

/* If not publicly defined, define internally */
#define MCUXCLMAC_CBCMAC_OUTPUT_SIZE                   (16U)                                              ///< Size of CBCMAC output in bytes:       128 bits (16 bytes)
#define MCUXCLMAC_CBCMAC_OUTPUT_SIZE_IN_WORDS          (MCUXCLMAC_CBCMAC_OUTPUT_SIZE / sizeof(uint32_t)) ///< Size of CBCMAC output in bytes:       128 bits (16 bytes)


MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()

/*
 * Engine functions
 */


/**
 * @brief Internal function, which processes input to a CBC-Mac computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 * @param[in]  pIn       Pointer to the input to be processed.
 * @param[in]  inLength    Size of input buffer pointed to by @p pIn.
 * @param[out] pProcessedBytes  Number of bytes processed from @p pIn. RFU.
 *
 * @return mcuxClMac_Status_t  Status of the operation
 * @retval MCUXCLMAC_STATUS_FAILURE Operation failed
 * @retval MCUXCLMAC_STATUS_OK      Operation succeeded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_updateCBCMac, mcuxClMacModes_UpdateFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_updateCBCMac(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
);



/**
 * @brief Internal function, which finalizes a CBC-Mac computation.
 *
 * @pre The subkeys K1 and K2 have been generated.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_finalizeCBCMac, mcuxClMacModes_FinalizeFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeCBCMac(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext);


/**
 * Helper Functions
 */


MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_SGI_CBCMAC_H_ */
