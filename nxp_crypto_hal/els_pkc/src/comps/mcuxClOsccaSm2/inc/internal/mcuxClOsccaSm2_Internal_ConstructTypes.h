/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClOsccaSm2_Internal_ConstructTypes.h
 * @brief Internal constructors type definitions for the mcuxClOsccaSm2 component
 */

#ifndef MCUXCLOSCCASM2_INTERNAL_CONSTRUCTTYPES_H_
#define MCUXCLOSCCASM2_INTERNAL_CONSTRUCTTYPES_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stddef.h>
#include <mcuxClOscca_Types.h>
#ifdef MCUXCL_FEATURE_SM2_CIPHER
#include <mcuxClCipher_Types.h>
#include <internal/mcuxClCipher_Internal.h>
#endif
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
#include <mcuxClSignature_Types.h>
#include <internal/mcuxClSignature_Internal.h>
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */
#include <mcuxClKey_Types.h>
#include <mcuxClSession_Types.h>
#include <mcuxClOsccaSm2_Types.h>
#include <mcuxClOsccaSm2_Constants.h>
#include <internal/mcuxClOsccaSm2_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MCUXCL_FEATURE_SM2_INTERNAL
#ifdef MCUXCL_FEATURE_SM2_CIPHER

/**
 * @brief Function type for internal Encryption engine
 *
 * Generic function pointer to internal encryption function declarations
 *
 * @return Status of the internal encryption operation
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaSm2_EncEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) (* mcuxClOsccaSm2_EncEngine_t)(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Encrypt_Param_t *pParams    /**< @brief Pointer to parameter struct */
));

 /**
 * @brief Function type for internal Decryption engine
 *
 * Generic function pointer to internal decryption function declarations
 *
 * @return Status of the internal decryption operation
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClOsccaSm2_DecEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) (* mcuxClOsccaSm2_DecEngine_t)(
    mcuxClSession_Handle_t session,
    mcuxClOsccaSm2_Decrypt_Param_t *pParams    /**< @brief Pointer to parameter struct */
));


/**
 * @brief Cipher context structure for SM2 modes
 *
 * This structure is used to store the information about the current operation
 * and the relevant internal SM2 state.
 */
typedef struct mcuxClOsccaSm2_Cipher_Context
{
  mcuxClCipher_Context_t   common;
  mcuxClKey_Descriptor_t * pKey;
  mcuxClOsccaSm2_EncDecCtx_t* pEncDecCtx;
  uint8_t  pC3Buffer[MCUXCLOSCCASM3_OUTPUT_SIZE_SM3];
  uint8_t* pC1Buffer;
  uint32_t proDataLen;                               ///< date length that has been processed
} mcuxClOsccaSm2_Cipher_Context_t;

/**
 * @brief Cipher mode algorithm descriptor structure for SM2 algorithms
 *
 * This structure captures all the information that the Cipher interfaces need
 * to know about SM2 Cipher mode algorithm.
 */
typedef struct
{
    mcuxClOsccaSm2_EncEngine_t  pEncryptMode;  ///< Pointer to internal sm2 Encryption functionality.
    mcuxClOsccaSm2_DecEngine_t  pDecryptMode;  ///< Pointer to internal sm2 Decryption functionality.
    uint32_t   encrypt_FunId;                 ///< FP for sm2 encrypt functionality
    uint32_t   decrypt_FunId;                 ///< FP for sm2 decrypt functionality
    uint32_t   direction;
} mcuxClOsccaSm2_Cipher_AlgorithmDescriptor_t;

/**
 * @brief Cipher mode algorithm type for SM2 algorithms
 *
 * This type is used to refer to SM2 Cipher mode algorithm.
 */
typedef const mcuxClOsccaSm2_Cipher_AlgorithmDescriptor_t * const mcuxClOsccaSm2_Cipher_Algorithm_t;
extern const mcuxClOsccaSm2_Cipher_AlgorithmDescriptor_t mcuxClOsccaSm2_CipherAlgorithmDesc_Sm2Enc;
extern const mcuxClOsccaSm2_Cipher_AlgorithmDescriptor_t mcuxClOsccaSm2_CipherAlgorithmDesc_Sm2Dec;

#endif /* MCUXCL_FEATURE_SM2_CIPHER */

#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
/***************************************************************
 *  TYPES RELATED TO INTERNAL SM2 SIGNATURE FUNCTIONALITY
 **************************************************************/

/**
 * @brief SM2-specific protocol descriptor structure for signature generation/verification with @ref mcuxClSignature
 */
struct mcuxClOsccaSm2_SignatureProtocolDescriptor
{
  uint16_t   options;          /*< [in] Two bytes to pass further options for this function:
                                      - bits 0-15: rfu */
};

/**
 * @brief Signature context structure for SM2 modes
 *
 * This structure is used to store the information about the current operation
 * and the relevant internal SM2 sign state.
 */
typedef struct mcuxClOsccaSm2_Signature_Context
{
  mcuxClSignature_Context_t   common;

  mcuxClKey_Descriptor_t * pKey;
  uint8_t pX2[MCUXCLOSCCASM2_SM2P256_SIZE_MAX];
  uint8_t pK[MCUXCLOSCCASM2_SM2P256_SIZE_MAX];
} mcuxClOsccaSm2_Signature_Context_t;

extern const mcuxClOsccaSm2_SignatureProtocolDescriptor_t mcuxClOsccaSm2_Sm2ProtocolDescriptor;
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */

#ifdef MCUXCL_FEATURE_SM2_KEYAGREEMENT
/***************************************************************
 *  TYPES RELATED TO INTERNAL SM2 AGREEMENT FUNCTIONALITY
 **************************************************************/

/**
 * @brief SM2-specific protocol descriptor structure for key agreement with @ref mcuxClKey
 */
struct mcuxClOsccaSm2_AgreementProtocolDescriptor
{
  uint16_t   options;          /**< [in] Two bytes to pass further options for this function:
                                    - bits 0-3: rfu
                                    - bits 4-5:
                                      - 01: Role of local party is initiator, i.e., Alice
                                      - 10: Role of local party is responder, i.e., Bob
                                    - bits 6-7:
                                      - 01: Key confirmation shall be computed
                                      - 10: Key confirmation is skipped
                                    - other bits: rfu */
};

typedef struct mcuxClOsccaSm2_AgreementProtocolDescriptor mcuxClOsccaSm2_AgreementProtocolDescriptor_t;

extern const mcuxClOsccaSm2_AgreementProtocolDescriptor_t mcuxClOsccaSm2_AgreementDescriptor_Initiator;
extern const mcuxClOsccaSm2_AgreementProtocolDescriptor_t mcuxClOsccaSm2_AgreementDescriptor_Responder;

#endif /* MCUXCL_FEATURE_SM2_KEYAGREEMENT */

#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

/**
 * @}
 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM2_INTERNAL_CONSTRUCTTYPES_H_ */
