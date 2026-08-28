/*--------------------------------------------------------------------------*/
/* Copyright 2023-2025 NXP                                                  */
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

/** @file  mcuxClHmac_Internal_Types.h
 *  @brief Internal header for HMAC types  *
 */

#ifndef MCUXCLHMAC_INTERNAL_TYPES_H_
#define MCUXCLHMAC_INTERNAL_TYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClBuffer.h>
#include <mcuxClCore_Platform.h>
#include <mcuxClSession_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClKey_Types.h>
#include <mcuxClMac_Types.h>
#include <internal/mcuxClMac_Ctx.h>
#include <internal/mcuxClMac_Internal_Types.h>
#include <internal/mcuxClPadding_Types_Internal.h> /* for mcuxClHash_ContextBuffer_t */
#include <mcuxClHash_Types.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal_Memory.h>

#ifdef __cplusplus
extern "C" {
#endif

/****************************/
/* Context types            */
/****************************/
#define MCUXCLHMAC_INTEGRITY_PROTECTION_CONTEXT                                             \
    mcuxClMac_Context_t common;                                                            \
    mcuxClKey_Descriptor_t * key;                                                          \
    /* Padded/Hashed HMAC key, must be large enough to hold any block */                  \
    uint32_t preparedHmacKey[MCUXCLHASH_BLOCK_SIZE_MAX_WITHOUT_MASK / sizeof(uint32_t)];

/**
 * @brief Hmac integrity protected context structure
 *
 * This struct is used to calculate the size of the integrity protected context
 */
typedef struct
{
    MCUXCLHMAC_INTEGRITY_PROTECTION_CONTEXT
} mcuxClHmac_IntegrityProtectionContext_t;

#define MCUXCLHMAC_INTEGRITY_PROTECTED_CONTEXT_SIZE (sizeof(mcuxClHmac_IntegrityProtectionContext_t))

/**
 * @brief HMAC context structure for modes using a SW implementation
 *
 * This structure captures all the information that the Mac interface needs to
 * know for a particular HMAC mode/algorithm to work.
 * It also contains information specific to the SW implementation of HMAC.
 */
typedef struct mcuxClHmac_Context_Sw
{
    /* Integrity protected Context */
    MCUXCLHMAC_INTEGRITY_PROTECTION_CONTEXT

    mcuxClHash_ContextDescriptor_t *hashCtx;                                                     /* Hash context for SW-HMAC */
    uint32_t hashContextBuffer[MCUXCLHASHMODES_CONTEXT_MAX_SIZE_INTERNAL / sizeof(uint32_t)];    /* Buffer to store the actual hash context data using maximum size of a hash context */
} mcuxClHmac_Context_Sw_t;


/****************************/
/* Engine function types    */
/****************************/

/**
 * @brief HMAC engine function type for the oneshot computation
 *
 * These functions will perform the actual HMAC operation.
 * See specific function declarations for details.
 *
 * Data Integrity: Expunge(pIn + inLength + pOut)
 *                 Record(*pOutLength)
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHmac_ComputeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClHmac_ComputeEngine_t)(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Sw_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength,
    mcuxCl_Buffer_t pOut,
    uint32_t *const outLength
));

/**
 * @brief HMAC engine function type for the init phase of a multi-part computation
 *
 * These functions will perform the actual HMAC init operation.
 * See specific function declarations for details.
 *
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHmac_InitEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClHmac_InitEngine_t)(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Sw_t * const pContext
));

/**
 * @brief HMAC engine function type for the update phase of a multi-part computation
 *
 * These functions will perform the actual HMAC update operation.
 * See specific function declarations for details.
 *
 * Data Integrity: Expunge(pIn + inLength)
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHmac_UpdateEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClHmac_UpdateEngine_t)(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Sw_t * const pContext,
    mcuxCl_InputBuffer_t pIn,
    uint32_t inLength
));

/**
 * @brief HMAC engine function type for the finalize phase of a multi-part computation
 *
 * These functions will perform the actual HMAC finalize operation.
 * See specific function declarations for details.
 *
 * Data Integrity: Expunge(pOut)
 *                 Record(*pOutLength)
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClHmac_FinalizeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClHmac_FinalizeEngine_t)(
    mcuxClSession_Handle_t session,
    mcuxClHmac_Context_Sw_t * const pContext,
    mcuxCl_Buffer_t pOut,
    uint32_t * const outLength
));


/****************************/
/* Algorithm types          */
/****************************/

/**
 * @brief HMAC structure
 *
 * This internal structure provides all implementation details for the top level mcuxClHmac functions.
 * It consists of Init, Update, Finalize and Oneshot engines and the output size.
 *
 */
typedef struct mcuxClHMac_AlgorithmDescriptor
{
    mcuxClHmac_InitEngine_t engineInit;           ///< engine function to perform the init operation
    uint32_t protection_token_engineInit;        ///< Protection token value for the used engine init
    mcuxClHmac_UpdateEngine_t engineUpdate;       ///< engine function to perform the update operation
    uint32_t protection_token_engineUpdate;      ///< Protection token value for the used engine update
    mcuxClHmac_FinalizeEngine_t engineFinalize;   ///< engine function to perform the finalize operation
    uint32_t protection_token_engineFinalize;    ///< Protection token value for the used engine finalize
    mcuxClHmac_ComputeEngine_t engineOneshot;     ///< engine function to perform the Mac operation in one shot
    uint32_t protection_token_engineOneShot;     ///< Protection token value for the used one-shot engine
    mcuxClPadding_addPaddingMode_t addPadding;   ///< padding function to be used. One of mcuxClPaddingMode
} mcuxClHmac_AlgorithmDescriptor_t;

/**
 * @brief HMAC algorithm type for algorithms
 *
 * This type is used to refer to an HMAC algorithm.
 */
typedef const mcuxClHmac_AlgorithmDescriptor_t * const mcuxClHmac_Algorithm_t;

/**
 * @brief Forward declaration of HMAC algorithm instances
 *
 */
extern const mcuxClHmac_AlgorithmDescriptor_t mcuxClHmac_AlgorithmDescriptor_Sw;

/****************************/
/* Mode descriptor types    */
/****************************/

/**
 * @brief HMAC specific mode descriptor structure
 *
 * This structure captures all the additional information for the SW-HMAC implementation
 * that is not contained in the @ref mcuxClMac_CommonModeDescriptor_t type.
 */
typedef struct mcuxClHmac_ModeDescriptor
{
    const mcuxClHash_AlgorithmDescriptor_t * hashAlgorithm;
} mcuxClHmac_ModeDescriptor_t;

/**
 * @brief Forward declaration of common mode descriptor needed for constructor of HMAC mode
 *
 */
extern const mcuxClMac_CommonModeDescriptor_t mcuxClHmac_CommonModeDescriptor_Sw;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLHMAC_INTERNAL_TYPES_H_ */
