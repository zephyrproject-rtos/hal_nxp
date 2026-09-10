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
 * @file  mcuxClOsccaSm2_Types.h
 * @brief Type definitions of mcuxClOsccaSm2 component
 */


#ifndef MCUXCLOSCCASM2_TYPES_H_
#define MCUXCLOSCCASM2_TYPES_H_


#include <stdint.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClOscca_Types.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>

/**********************************************
 * TYPEDEFS
 **********************************************/
 /**
 * @defgroup mcuxClOsccaSm2_Types mcuxClOsccaSm2_Types
 * @brief Defines all types of the @ref mcuxClOsccaSm2 component
 * @ingroup mcuxClOsccaSm2
 * @{
 */

/***********************************************************
 *  TYPES RELATED TO FUNCTION STATUS
 **********************************************************/

/**
 * @brief Type for SM2 status codes
 */
typedef uint32_t mcuxClOsccaSm2_Status_t;


/***********************************************************
 *  MACROS
 **********************************************************/

/**
 * @defgroup mcuxClOsccaSm2_Macros mcuxClOsccaSm2_Macros
 * @brief Defines all macros of @ref mcuxClOsccaSm2
 * @ingroup mcuxClOsccaSm2
 * @{
 */
#define MCUXCLOSCCASM2_CEILING(x,y)                       (((x) + (y) - 1u) / (y))
#define MCUXCLOSCCASM2_BYTELEN(bitLen)                    (((bitLen) + 7u) / 8u)

/**
 * @addtogroup MCUXCLOSCCASM2_SM2P256_SIZE_
 * mcuxClOsccaSm2_size definitions for curve256 input buffers
 * @{ */
#define MCUXCLOSCCASM2_ENCDEC_FORMAT_INDICATOR_SIZE (1u)
#define MCUXCLOSCCASM2_SM2P256_SIZE_PRIVATEKEY      (32u)   ///< Byte length of a SM2P256 private key.
#define MCUXCLOSCCASM2_SM2P256_SIZE_PUBLICKEY       (2u * MCUXCLOSCCASM2_SM2P256_SIZE_PRIVATEKEY)   ///< Byte length of a SM2P256 public key.
#define MCUXCLOSCCASM2_SM2P256_SIZE_SHAREDSECRET    (32u)   ///< Byte length of a SM2P256 shared secret.
#define MCUXCLOSCCASM2_SM2P256_SIZE_PRIMEP          (32u)   ///< Byte length of the underlying prime p used in SM2P256.
#define MCUXCLOSCCASM2_SM2P256_SIZE_BASEPOINTORDER  (32u)   ///< Byte length of the base point order n used in SM2P256.
#define MCUXCLOSCCASM2_SM2P256_SIZE_MAX             (32u)   ///< Max byte length of MCUXCLOSCCASM2_SM2P256_SIZE_BASEPOINTORDER and MCUXCLOSCCASM2_SM2P256_SIZE_PRIMEP used in SM2P256.
/** @} */  /* MCUXCLOSCCASM2_SM2P256_SIZE_ */
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
#define MCUXCLOSCCASM2_SM2P256_SIZE_SIGNATURE       (2u * MCUXCLOSCCASM2_SM2P256_SIZE_BASEPOINTORDER)   ///< Byte length of a SM2P256 signature.
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */

#ifdef MCUXCL_FEATURE_SM2_CIPHER
#define MCUXCLOSCCASM2_SM2P256_SIZE_CIPHER_MESSAGE  (128U)   ///< Byte length of a SM2P256 cipher message.
#endif /* MCUXCL_FEATURE_SM2_CIPHER */

/**********************************************************/
/* Parameter structure of mcuxClOscca SM2 APIs             */
/**********************************************************/
typedef struct mcuxClOsccaSm2_DomainParam mcuxClOsccaSm2_DomainParam_t;

#ifdef MCUXCL_FEATURE_SM2_INTERNAL
#ifdef MCUXCL_FEATURE_SM2_SIGNATURE
typedef struct mcuxClOsccaSm2_SignatureProtocolDescriptor mcuxClOsccaSm2_SignatureProtocolDescriptor_t;
#endif /* MCUXCL_FEATURE_SM2_SIGNATURE */
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

/***********************************************************
 *  MACROS RELATED TO FUNCTION STATUS
 **********************************************************/

/**
 * @defgroup MCUXCLOSCCASM2_STATUS_ MCUXCLOSCCASM2_STATUS_
 * @brief Return code definitions
 * @ingroup mcuxClOsccaSm2_Macros
 * @{
 */
#define MCUXCLOSCCASM2_STATUS_OK                          ((mcuxClOsccaSm2_Status_t)0x011B2E03u)
#define MCUXCLOSCCASM2_STATUS_FAILURE                     ((mcuxClOsccaSm2_Status_t)0x011B5354U)
#define MCUXCLOSCCASM2_STATUS_INVALID_PARAMS              ((mcuxClOsccaSm2_Status_t)0x011B5330u)
#define MCUXCLOSCCASM2_STATUS_RNG_ERROR                   ((mcuxClOsccaSm2_Status_t)0x011B5334U)
#define MCUXCLOSCCASM2_STATUS_INVALID_SIGNATURE           ((mcuxClOsccaSm2_Status_t)0x011B8930u)
#define MCUXCLOSCCASM2_STATUS_FAULT_ATTACK                ((mcuxClOsccaSm2_Status_t)0x011BF0F0u)

/**
 * @}
 */ /* mcuxClOsccaSm2_Types */


#endif /* MCUXCLOSCCASM2_TYPES_H_ */
