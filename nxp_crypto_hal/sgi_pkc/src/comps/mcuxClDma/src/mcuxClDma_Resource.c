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

#include <internal/mcuxClDma_Resource.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_requestInputAndOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_requestInputAndOutput(
  mcuxClSession_Handle_t session,
  mcuxClSession_HwInterruptHandler_t callbackFunction,
  uint32_t protectionToken_callbackFunction
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_requestInputAndOutput);

  mcuxClSession_Channel_t inChannel = mcuxClSession_getDmaInputChannel(session);
  mcuxClSession_Channel_t outChannel = mcuxClSession_getDmaOutputChannel(session);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(session, inChannel, callbackFunction, protectionToken_callbackFunction));

  /* User might use the same channel for input and output. Only request output if they differ. */
  if(inChannel != outChannel)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_request(session, outChannel, callbackFunction, protectionToken_callbackFunction));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_requestInputAndOutput,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_request),
    MCUX_CSSL_FP_CONDITIONAL((inChannel != outChannel), MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_request)));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClDma_releaseInputAndOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClDma_releaseInputAndOutput(
  mcuxClSession_Handle_t session
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClDma_releaseInputAndOutput);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_release(session, mcuxClSession_getDmaInputChannel(session)));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClDma_release(session, mcuxClSession_getDmaOutputChannel(session)));
  /* Delayed check for errors to achieve the cleanest state possible. If input and output channels are identical, the second release call shall have no effect. */

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClDma_releaseInputAndOutput,
    2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClDma_release)
  );
}

