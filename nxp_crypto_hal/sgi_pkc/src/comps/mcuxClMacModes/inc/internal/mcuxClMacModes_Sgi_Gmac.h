/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

#ifndef MCUXCLMACMODES_SGI_GMAC_H_
#define MCUXCLMACMODES_SGI_GMAC_H_

#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_Platform.h>

#include <internal/mcuxClSession_Internal.h>
#include <mcuxClMac_Types.h>
#include <mcuxClKey_Types.h>
#include <mcuxClBuffer.h>

#include <internal/mcuxClMacModes_Sgi_Types.h>
#include <internal/mcuxClMacModes_Common_Wa.h>
#include <internal/mcuxClMacModes_Sgi_Ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Internal GMAC defines */

#define MCUXCLMAC_GMAC_OUTPUT_SIZE                     (16U)                                               ///< Size of GMAC output in bytes:         128 bits (16 bytes)
#define MCUXCLMAC_GMAC_OUTPUT_SIZE_IN_WORDS            (MCUXCLMAC_GMAC_OUTPUT_SIZE / sizeof(uint32_t))    ///< Size of GMAC output in bytes:         128 bits (16 bytes)

/* Internal GMAC functions */

/* If not publicly defined, define internally */
/**
 * @brief This function creates a GMAC mode descriptor
 *
 * The GMAC mode of operation requires additional input, hence a
 * mode descriptor has to be constructed with this function.
 * The resulting descriptor will be written to @p mode.
 *
 * This function must be called before any MAC operation is performed.
 *
 * @param mode[out]     Pointer to GMAC custom mode to be initialized.
 * @param pIv[in]       Pointer to the IV/nonce data.
 * @param ivLength[in]  Number of bytes of data in the @p pIv buffer.
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_createGmacMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_createGmacMode(
  mcuxClMac_CustomMode_t mode,
  mcuxCl_InputBuffer_t pIv,
  uint32_t ivLength
);


/**
 * @brief Internal function, which initializes a GMAC computation.
 *
 * @pre The key has been loaded to SGI.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workArea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_initGMAC, mcuxClMacModes_InitFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_initGMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t * workArea,
  mcuxClMacModes_Context_t * const pContext
);

/**
 * @brief Internal function, which processes input to a GMAC computation.
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
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_updateGMAC, mcuxClMacModes_UpdateFunc_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMac_Status_t) mcuxClMacModes_updateGMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t * const pContext,
  mcuxCl_InputBuffer_t pIn,
  uint32_t inLength,
  uint32_t * pProcessedBytes
);


/**
 * @brief  Internal function, which is used to finalize processing of
 *         input data GMAC computation. Also useful for finalizing processing
 *         of the additional data in AEAD modes like GCM.
 *
 * @pre    The key has been loaded to SGI.
 * @pre    The Hkey has been loaded to SGI (key2).
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workarea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_finalizeDataGMAC)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeDataGMAC(
    mcuxClSession_Handle_t session,
    mcuxClMacModes_WorkArea_t *workArea,
    mcuxClMacModes_Context_t *const pContext);

/**
 * @brief  Internal function, which is called to after processing of
 *         all data to a GMAC computation. A payload length can be supplied,
 *         this is useful for in AEAD modes like GCM.
 *
 * @pre   The pretag is loaded to DATOUT
 * @pre   The key has been loaded to SGI.
 * @pre   The Hkey has been loaded to SGI (key2).
 * @post  The final (encrypted) tag will be in SGI DATOUT0.
 *
 * @param[in]  session   Handle for the current CL session.
 * @param[in]  workarea  Pointer to workarea (word-aligned).
 * @param[in]  pContext  Pointer to context (word-aligned).
 * @param[in]  uint32_t  The size of the payload (for GMAC this is 0).
 *
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClMacModes_finalizeSizesGMAC)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClMacModes_finalizeSizesGMAC(
  mcuxClSession_Handle_t session,
  mcuxClMacModes_WorkArea_t *workArea,
  mcuxClMacModes_Context_t *const pContext,
  uint32_t payloadLength);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLMACMODES_SGI_GMAC_H_ */
