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

/** @file  mcuxClRsa_Util_Sign.c
 *  @brief mcuxClRsa: implementation of RSA Sign function
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClHash.h>
#include <mcuxClSignature_Types.h>
#include <mcuxClSignature_Constants.h>
#include <mcuxClBuffer.h>

#include <mcuxClRsa.h>

#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClPkc_Internal.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClRsa_Internal_Functions.h>
#include <internal/mcuxClRsa_Internal_Types.h>
#include <internal/mcuxClRsa_Internal_Macros.h>
#include <internal/mcuxClKey_Internal.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClSignature_Internal.h>
#include <internal/mcuxClRsa_Internal_MemoryConsumption.h>
#include <internal/mcuxClRsa_Internal_PkcTypes.h>
#include <internal/mcuxClMath_Internal.h>

/* TODO CLNS-17683: Align when the Signature component is updated and if the return status for mcuxClSignature_SignFct_t changes */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClRsa_Util_sign, mcuxClSignature_SignFct_t)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSignature_Status_t) mcuxClRsa_Util_sign(
  mcuxClSession_Handle_t           pSession,
  mcuxClKey_Handle_t               key,
  mcuxClSignature_Mode_t           mode,
  mcuxCl_InputBuffer_t             pMessageOrDigest,
  uint32_t                        messageLength UNUSED_PARAM,
  mcuxCl_Buffer_t                  pSignature,
  uint32_t * const                pSignatureSize
  )
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClRsa_Util_sign);

  /* SREQI_RSA_0: DI protect the Key algoId.
   * Will be balanced in the call to mcuxClRsa_privatePlain() or mcuxClRsa_privateCrt() */
  MCUX_CSSL_DI_RECORD(verifyKey, mcuxClKey_getAlgoId(key));

  /*****************************************************/
  /* Initialization                                    */
  /*****************************************************/

  /* Initialize PKC */
  MCUXCLPKC_FP_REQUEST_INITIALIZE(pSession, mcuxClRsa_Util_sign);

  /* The CPU WA layout is:
  * +-------------+------------------------+
  * | Math UPTRT  | RSA Allocated Memory   |
  * +-------------+------------------------+
  */
  /* Setup mcuxClMath UPTRT buffer at beginning of PKC/CPU depending on MCUXCL_FEATURE_PKC_UPTRT_IN_PKCRAM and update session info */
  MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pMathUptrt, mcuxClSession_allocateWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t)));
  /* Update session info for pMathUptrt location in PKC WA */
  pSession->pMathUptrt = pMathUptrt;

  /*****************************************************/
  /* Perform padding operation                         */
  /*****************************************************/

  // TODO CLNS-9134: define which parameters should be verified (valid mode, hash function, key size, etc.. ?)

  /* Setup the parameters used by RSA internal functions, based on the protocol descriptor:
   * padding mode, salt length, options, signature size and RSA key. */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_CAST_VOID()
  const mcuxClRsa_SignatureProtocolDescriptor_t * pRsa_Signature_ProtocolDescriptor = (const mcuxClRsa_SignatureProtocolDescriptor_t*) mode->pProtocolDescriptor;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_CAST_VOID()

  const uint32_t saltLength = pRsa_Signature_ProtocolDescriptor->saltLength;
  const uint32_t options = pRsa_Signature_ProtocolDescriptor->options;

  /* Get the modulus bit length from the input key */
  uint32_t keyBitLength = mcuxClKey_getSize(key);
  *pSignatureSize = keyBitLength / 8U;

  /* Locate paddedMessage buffer at beginning of PKC WA and update session info */
  uint32_t keyByteLength = keyBitLength / 8U;
  uint32_t pkcWaUsedByte = MCUXCLRSA_INTERNAL_SIGN_PADDED_MESSAGE_BUFFER(keyByteLength, mcuxClKey_getAlgoId(key));
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorakarea, mcuxClSession_allocateWords_pkcWa(pSession, pkcWaUsedByte / (sizeof(uint32_t))));
  uint8_t *pPaddedMessage = pPkcWorakarea;

  /* Call the padding function */
  MCUXCLBUFFER_INIT(pPaddedMessageBuf, NULL, pPaddedMessage, pkcWaUsedByte);
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEREFERENCE_NULL_POINTER("pVerificationInput, pLabel, pOutLength are unused by this function")
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_NULL_POINTER_CONSTANT("NULL is used in code")
  MCUX_CSSL_FP_FUNCTION_CALL(retVal_PaddingOperation, pRsa_Signature_ProtocolDescriptor->pSignMode(
                              /* mcuxClSession_Handle_t       pSession,           */ pSession,
                              /* mcuxCl_InputBuffer_t         pInput,             */ pMessageOrDigest,
                              /* const uint32_t              inputLength,        */ 0U,
                              /* mcuxCl_Buffer_t              pVerificationInput, */ NULL,
                              /* mcuxClHash_Algo_t            pHashAlgo,          */ pRsa_Signature_ProtocolDescriptor->pHashAlgo,
                              /* const uint8_t *             pLabel,             */ NULL,
                              /* const uint32_t              saltlabelLength,    */ saltLength,
                              /* const uint32_t              keyBitLength,       */ keyBitLength,
                              /* const uint32_t              options,            */ options,
                              /* mcuxCl_Buffer_t              pOutput             */ pPaddedMessageBuf,
                              /* uint32_t * const            pOutLength          */ NULL
  ));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_NULL_POINTER_CONSTANT()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEREFERENCE_NULL_POINTER()

  /* Note: the pRsa_Signature_ProtocolDescriptor->pSignMode functions always return
   * MCUXCLRSA_STATUS_INTERNAL_ENCODE_OK on success, and on any early exit it returns other errors through session parameter.
   * Hence retVal_PaddingOperation does not need to be checked.
   */
  (void)retVal_PaddingOperation;

  if (pkcWaUsedByte > keyByteLength)
  {
    /* Clear PKC workarea after the input */
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_afterInput, pPaddedMessage + keyByteLength);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_afterInput, pkcWaUsedByte - keyByteLength);
    MCUXCLMEMORY_CLEAR_INT(pPaddedMessage + keyByteLength, pkcWaUsedByte - keyByteLength);
  }

  /*****************************************************/
  /* Perform RSA private operation                     */
  /*****************************************************/
  /* Call the appropriate private key operation, based on the key type */
  mcuxClKey_AlgorithmId_t keyAlgoId = mcuxClKey_getAlgoId(key);
  if(MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN == keyAlgoId)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_privatePlain(pSession, key, pPaddedMessage, pSignature));
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClRsa_privateCRT(pSession, key, pPaddedMessage, pSignature));
  }

  /*****************************************************/
  /* Exit                                              */
  /*****************************************************/

  mcuxClSession_freeWords_pkcWa(pSession, pkcWaUsedByte / (sizeof(uint32_t)));
  MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);

  /* Free Math UPTRT allocated WA */
  mcuxClSession_freeWords_uptrt(pSession, MCUXCLMATH_SIZEOF_MATH_UPTRT / sizeof(uint32_t));

  MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClRsa_Util_sign, MCUXCLRSA_STATUS_SIGN_OK,
      MCUXCLPKC_FP_CALLED_REQUEST_INITIALIZE,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_uptrt),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
      pRsa_Signature_ProtocolDescriptor->sign_FunId,
      MCUX_CSSL_FP_CONDITIONAL(pkcWaUsedByte > keyByteLength, MCUXCLMEMORY_CLEAR_INT_FP_EXPECT),
      MCUX_CSSL_FP_CONDITIONAL((MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATEPLAIN == mcuxClKey_getAlgoId(key)),
          MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_privatePlain)
      ),
      MCUX_CSSL_FP_CONDITIONAL(((MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRT == mcuxClKey_getAlgoId(key))
          || (MCUXCLRSA_KEYTYPE_INTERNAL_PRIVATECRTDFA == mcuxClKey_getAlgoId(key))),
              MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRsa_privateCRT)
      ),
      MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE
  );
}
