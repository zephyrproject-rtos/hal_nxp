/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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

#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClCore_Macros.h>

#include <mcuxClAes.h>
#include <mcuxClBuffer.h>
#include <mcuxClCipherModes_MemoryConsumption.h>
#include <mcuxClKey.h>
#include <mcuxClMemory_Copy.h>
#include <mcuxClSession.h>
#include <mcuxCsslDataIntegrity.h>
#include <mcuxCsslFlowProtection.h>

#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClCipher_Internal.h>
#include <internal/mcuxClCipherModes_Common.h>
#include <internal/mcuxClCipherModes_Sgi_Cleanup.h>
#include <internal/mcuxClCipherModes_Sgi_Helper.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>

#include <mcuxClResource_Types.h>


/**
 * @brief Function used for DFA protection.
 *
 * This function is capable of computing en/decryption multiple times (depends on security setting
 * and feature SESSION_SECURITYOPTIONS_ADDITIONAL_SWCOMP) and comparing CRC result
 * of each calculation with each other to determine if any fault was injected in between calculations
 *
 * This function fulfills SREQI_BCIPHER_11
 * Code flow is described in detail in SREQI_BCIPHER_11
 *
 * @param      session      Handle for the current CL session.
 * @param[in]  pWa          Pointer to cpu workarea
 * @param[in]  pIn          Buffer which holds the input data
 * @param[in]  pOut         Buffer to hold the output data
 * @param[in]  inLength     Length of input data
 * @param[in]  pIvOut       Pointer for the updated Iv
 * @param[in]  pOutLength   Pointer to length of output data
 * @param[in]  cryptEngine  Engine function to do the specified crypt operation
 *
 */
 MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCipherModes_crypt)
 MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClCipherModes_crypt(
   mcuxClSession_Handle_t session,
   mcuxClCipherModes_WorkArea_t* pWa,
   mcuxCl_InputBuffer_t pIn,
   mcuxCl_Buffer_t pOut,
   uint32_t inLength,
   uint32_t *pIvOut,
   uint32_t * const pOutLength,
   mcuxClKey_KeyChecksum_t* pKeyChecksum,
   mcuxClCipherModes_EngineFunc_AesSgi_t cryptEngine,
   uint32_t protectionToken_cryptEngine
 )
 {
   MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClCipherModes_crypt);

   if(0U == inLength)
   {
     /* Nothing to do - exit */
     MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_crypt);
   }

   // Set copy function to output the crypt result into user buffer
   pWa->sgiWa.copyOutFunction = mcuxClCipherModes_copyOut_toPtr;
   pWa->sgiWa.protectionToken_copyOutFunction = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClCipherModes_copyOut_toPtr);
   MCUX_CSSL_FP_FUNCTION_CALL(status1, cryptEngine(
     session,
     pWa,
     pIn,
     pOut,
     inLength,
     pIvOut,
     pOutLength));
   (void) status1; /* Blocking cryptEngines always return OK */

   MCUX_CSSL_FP_FUNCTION_CALL_VOID(pKeyChecksum->VerifyFunc(session, pKeyChecksum, (uint8_t *)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_KEY0_OFFSET)));

   MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClCipherModes_crypt,
                                  protectionToken_cryptEngine, pKeyChecksum->protectionToken_VerifyFunc);
}

