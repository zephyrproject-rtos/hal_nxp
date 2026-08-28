/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024, 2026 NXP                                            */
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

/** @file  mcuxClHmac_Core_Functions_Sw.h
 *  @brief Internal definitions of SW engine functions for the HMAC component
 */

#ifndef MCUXCLHMAC_CORE_FUNCTIONS_SW_H_
#define MCUXCLHMAC_CORE_FUNCTIONS_SW_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <internal/mcuxClHmac_Internal_Types.h>


#ifdef __cplusplus
extern "C" {
#endif


/****************************/
/* Engine functions         */
/****************************/

/**
 * @brief HMAC engine function for the oneshot computation using SW
 *
 * This function performs the actual HMAC operation using the SW.
 *
 * Data Integrity: Expunge(pIn + inLength + pOut)
 *                 Record(*pOutLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_Engine_Oneshot_Sw, mcuxClHmac_ComputeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_Engine_Oneshot_Sw(
    mcuxClSession_Handle_t session,                /* HMAC session handle */
    mcuxClHmac_Context_Sw_t * const pContext,      /* HMAC context (word-aligned) */
    mcuxCl_InputBuffer_t pIn,                      /* HMAC input */
    uint32_t inLength,                            /* Input size */
    mcuxCl_Buffer_t pOut,                          /* HMAC output */
    uint32_t * const pOutLength                   /* Output size */
);

/**
 * @brief HMAC engine function for the init phase of a multi-part computation using SW
 *
 * This function prepares a context to start a multi-part HMAC computation.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_Engine_Init_Sw, mcuxClHmac_InitEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_Engine_Init_Sw(
    mcuxClSession_Handle_t session,                /*  HMAC session handle */
    mcuxClHmac_Context_Sw_t * const pContext       /*  HMAC context (word-aligned)*/
);

/**
 * @brief HMAC engine function for the update phase of a multi-part computation using SW
 *
 * This function processes additional data for a multi-part HMAC computation.
 *
 * Data Integrity: Expunge(pIn + inLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_Engine_Update_Sw, mcuxClHmac_UpdateEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_Engine_Update_Sw(
    mcuxClSession_Handle_t session,                /* HMAC session handle */
    mcuxClHmac_Context_Sw_t * const pContext,      /* HMAC context (word-aligned)*/
    mcuxCl_InputBuffer_t pIn,                      /* HMAC input */
    uint32_t inLength                             /* Input size */
);

/**
 * @brief HMAC engine function for the finalize phase of a multi-part computation using SW
 *
 * This function finalizes a multi-part HMAC computation.
 *
 * Data Integrity: Expunge(pOut)
 *                 Record(*pOutLength)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClHmac_Engine_Finalize_Sw, mcuxClHmac_FinalizeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClHmac_Engine_Finalize_Sw(
    mcuxClSession_Handle_t session,                /* HMAC session handle */
    mcuxClHmac_Context_Sw_t * const pContext,      /* HMAC context (word-aligned)*/
    mcuxCl_Buffer_t pOut,                          /* HMAC output */
    uint32_t *const pOutLength                    /* Output size */
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHMAC_CORE_FUNCTIONS_SW_H_ */
