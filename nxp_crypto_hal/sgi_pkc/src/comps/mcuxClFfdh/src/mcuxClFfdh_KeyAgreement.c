/*--------------------------------------------------------------------------*/
/* Copyright 2025-2026 NXP                                                  */
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
 * @file  mcuxClFfdh_KeyAgreement.c
 * @brief FFDH key agreement function
 */


#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxClBuffer.h>
#include <mcuxCsslAnalysis.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>

#include <mcuxClFfdh.h>
#include <internal/mcuxClFfdh_Internal.h>
#include <internal/mcuxClFfdh_Internal_PkcDefs.h>

#include <internal/mcuxClMemory_Clear_Internal.h>

#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClMath_Internal.h>
#include <internal/mcuxClMath_Internal_Functions.h>

#include <internal/mcuxClPkc_ImportExport.h>
#include <internal/mcuxClPkc_Resource.h>
#include <internal/mcuxClPkc_Operations.h>
#include <internal/mcuxClPkc_Macros.h>

/**
 * @brief FFDH key agreement.
 *
 * This function performs an FFDH key agreement to compute a shared secret between two parties.
 *
 * @param[in] pSession             pointer to #mcuxClSession_Descriptor
 * @param[in] agreement            Key agreement algorithm specifier
 * @param[in] key                  private key handling structure
 * @param[in] otherKey             public key handling structure
 * @param[in] additionalInputs     Key agreement additional input pointers (unused parameter)
 * @param[in] numberOfInputs       number of additional inputs (unused parameter)
 * @param[out] pOut                buffer for shared secret
 * @param[out] pOutLength          shared secret length
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClFfdh_KeyAgreement, mcuxClKey_AgreementFct_t)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClFfdh_KeyAgreement(
  mcuxClSession_Handle_t pSession,
  mcuxClKey_Agreement_t agreement,
  mcuxClKey_Handle_t key,
  mcuxClKey_Handle_t otherKey,
  mcuxClKey_Agreement_AdditionalInput_t additionalInputs[] UNUSED_PARAM,
  uint32_t numberOfInputs UNUSED_PARAM,
  uint8_t * pOut,
  uint32_t * const pOutLength)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClFfdh_KeyAgreement);

  /* Initialize output length with zero */
  *pOutLength = 0U;

  /* Domain parameters for each key must be properly matched on protocol level.
   * Double check here for extra safety against downgrade attacks. */
  if(mcuxClKey_getTypeInfo(key) != mcuxClKey_getTypeInfo(otherKey))
  {
    MCUXCLSESSION_ERROR(pSession, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  /* Set up the environment */
  mcuxClFfdh_DomainParams_t *pDomainParameters = (mcuxClFfdh_DomainParams_t *)mcuxClKey_getTypeInfo(key);

  /* mcuxClFfdh_CpuWa_t will be allocated and placed in the beginning of CPU workarea free space by SetupEnvironment. */
  mcuxClFfdh_CpuWa_t *pCpuWorkarea = mcuxClFfdh_castToFfdhCpuWorkArea(mcuxClSession_getEndOfUsedBuffer_Internal(pSession));
  MCUX_CSSL_FP_FUNCTION_CALL(uint8_t*, pPkcWorkarea, mcuxClSession_allocateWords_pkcWa(pSession, 0U));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClFfdh_SetupEnvironment(pSession, pDomainParameters));

  const uint32_t lenP = pDomainParameters->lenP;
  const uint32_t expOperandSize = pCpuWorkarea->expOperandSize;
  uint16_t * pOperands = MCUXCLPKC_GETUPTRT();

  /* Prepare temporary buffer for MCUXCLMATH_SECMODEXP execution.
   * For certain (big) group sizes not all buffer can fit into the PKC RAM memory.
   * In those instances CPU workspace is used. */
   uint32_t *pExpTemp = NULL;
   if(FFDH_EXPTMP_FAME_RAM_ONLY_MAX_LENGTH >= lenP)
   {
     pExpTemp =  MCUXCLPKC_OFFSET2PTRWORD(pOperands[FFDH_UPTRTINDEX_T6]);
   }
   else
   {
     const uint32_t cpuExpWordCount = expOperandSize / sizeof(uint32_t);
     MCUX_CSSL_FP_FUNCTION_CALL(uint32_t*, pExpTemp2, mcuxClSession_allocateWords_cpuWa(pSession, cpuExpWordCount));
     pExpTemp = pExpTemp2;
     MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("wordNumCpuWa is properly initialized in mcuxClFfdh_SetupEnvironment and does not overflow")
     pCpuWorkarea->wordNumCpuWa += cpuExpWordCount;
     MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
   }

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClFfdh_PublicKeyLoadAndValidate(
    pSession,
    otherKey,
    pCpuWorkarea,
    pExpTemp
  ));

  /* Securely load private key to PKC buffer FFDH_UPTRTINDEX_EXP */
  uint8_t *pPrivateKeyDest = MCUXCLPKC_OFFSET2PTR(pOperands[FFDH_UPTRTINDEX_EXP]);
  MCUXCLKEY_LOAD_FP(pSession, key, &pPrivateKeyDest, NULL, MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE);
  MCUX_CSSL_DI_RECORD(memoryClear, pPrivateKeyDest + pDomainParameters->lenQ);
  MCUX_CSSL_DI_RECORD(memoryClear, expOperandSize - pDomainParameters->lenQ);
  MCUXCLMEMORY_CLEAR_INT(pPrivateKeyDest + pDomainParameters->lenQ, expOperandSize - pDomainParameters->lenQ);

  MCUX_CSSL_DI_RECORD(exponentiation, pDomainParameters->lenQ);
  MCUXCLPKC_PS1_SETLENGTH(expOperandSize, expOperandSize);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(MCUXCLMATH_SECMODEXP(pSession,
                      pExpTemp,
                      pDomainParameters->lenQ,    /* Length of exponent  */
                      FFDH_UPTRTINDEX_EXP,        /* Output -> result, input -> private exponent */
                      FFDH_UPTRTINDEX_BASE,       /* Montgomery representation of base */
                      FFDH_UPTRTINDEX_P,          /* Modulus */
                      FFDH_UPTRTINDEX_T5,         /* iTE - last buffer 6FW */
                      FFDH_UPTRTINDEX_T1,         /* Remaining temporary buffers */
                      FFDH_UPTRTINDEX_T2,
                      FFDH_UPTRTINDEX_T3,
                      FFDH_UPTRTINDEX_T4));

  /* Bring back to normal representation */
  MCUXCLPKC_FP_CALC_MC1_MR(FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_EXP, FFDH_UPTRTINDEX_P);
  MCUXCLPKC_FP_CALC_MC1_MS(FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_T1, FFDH_UPTRTINDEX_P, FFDH_UPTRTINDEX_P);
  MCUXCLPKC_WAITFORFINISH();
  /* Securely export shared secret. */
  MCUXCLPKC_FP_SECUREEXPORTBIGENDIANFROMPKC_DI_BALANCED(pOut, FFDH_UPTRTINDEX_T1, lenP);
  *pOutLength = lenP;

  /* Clear PKC workarea. */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("wordNumCpuWa is limited by FFDH_WAPKC_SIZE define and does not overflow")
  MCUXCLPKC_PS1_SETLENGTH(0U, pCpuWorkarea->wordNumPkcWa * sizeof(uint32_t));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  pOperands[FFDH_UPTRTINDEX_P] = MCUXCLPKC_PTR2OFFSET(pPkcWorkarea);
  MCUXCLPKC_FP_CALC_OP1_CONST(FFDH_UPTRTINDEX_P, 0U);

  mcuxClSession_freeWords_pkcWa(pSession, pCpuWorkarea->wordNumPkcWa);
  MCUXCLPKC_FP_DEINITIALIZE_RELEASE(pSession);
  mcuxClSession_freeWords_cpuWa(pSession, pCpuWorkarea->wordNumCpuWa);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(
    mcuxClFfdh_KeyAgreement,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_pkcWa),
    MCUX_CSSL_FP_CONDITIONAL(
      FFDH_EXPTMP_FAME_RAM_ONLY_MAX_LENGTH < lenP,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_allocateWords_cpuWa)
    ),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClFfdh_SetupEnvironment),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClFfdh_PublicKeyLoadAndValidate),
    MCUXCLKEY_LOAD_FP_CALLED(key),
    MCUXCLMEMORY_CLEAR_INT_FP_EXPECT,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMath_SecModExp),
    MCUXCLPKC_FP_CALLED_CALC_MC1_MR,
    MCUXCLPKC_FP_CALLED_CALC_MC1_MS,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPkc_SecureExportBigEndianFromPkc),
    MCUXCLPKC_FP_CALLED_CALC_OP1_CONST,
    MCUXCLPKC_FP_CALLED_DEINITIALIZE_RELEASE
  );
}

const mcuxClKey_AgreementDescriptor_t mcuxClKey_AgreementDescriptor_FFDH =
{
  .pAgreementFct = mcuxClFfdh_KeyAgreement,
  .protectionTokenAgreementFct = MCUX_CSSL_FP_FUNCID_mcuxClFfdh_KeyAgreement,
  .pProtocolDescriptor = NULL
};
