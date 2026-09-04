/*--------------------------------------------------------------------------*/
/* Copyright 2021-2025 NXP                                                  */
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

#ifndef MCUXCLRANDOMMODES_PRIVATE_PATCHMODE_H_
#define MCUXCLRANDOMMODES_PRIVATE_PATCHMODE_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClSession.h>
#include <mcuxClRandom_Types.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif



/**
 * @brief Implements mcuxClRandom_initFunction_t for the patch mode
 *
 * This function implements an empty mcuxClRandom_initFunction_t for the patch mode.
 * None of the parameters is used and it allways returns OK.
 *
 * @param session       Handle for the current CL session.
 * @param mode          Handle for the current random mode
 * @param context       Handle for the random context
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_PatchMode_initFunction, mcuxClRandom_initFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_PatchMode_initFunction(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context);

/**
 * @brief Implements mcuxClRandom_reseedFunction_t for the patch mode
 *
 * This function implements an empty mcuxClRandom_reseedFunction_t for the patch mode.
 * None of the parameters is used and it allways returns OK.
 *
 * @param session       Handle for the current CL session.
 * @param mode          Handle for the current random mode
 * @param context       Handle for the random context
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_PatchMode_reseedFunction, mcuxClRandom_reseedFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_PatchMode_reseedFunction(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context);

/**
 * @brief Implements mcuxClRandom_generateFunction_t for the patch mode
 *
 * This function retrieves a custom user generate function from the mode. It calls this function to compute the output.
 * If @p pXorMask is not NULL, the output is XORed with that mask.
 *
 * @note In case that pXorMask is not NULL this function executes CPU accesses to the output buffer. Consider this behaviour
 * when using this function with a output buffer provided by the user.
 *
 * @param session       Handle for the current CL session.
 * @param mode          Handle for the current random mode
 * @param context       Handle for the random context
 * @param pOut          Buffer for the generated random data
 * @param outLength     Number of requested random bytes
 * @param pXorMask      Pointer to Boolean masking used for masking DRBG output (in CtrDrbg mode only)
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_PatchMode_generateFunction, mcuxClRandom_generateFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_PatchMode_generateFunction(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode,
        mcuxClRandom_Context_t context,
        mcuxCl_Buffer_t pOut,
        uint32_t outLength,
        const uint32_t *pXorMask);

/**
 * @brief Implements mcuxClRandom_selftestFunction_t for the patch mode
 *
 * This function implements an empty mcuxClRandom_reseedFunction_t for the patch mode.
 * None of the parameters is used and it allways returns OK.
 *
 * @param session       Handle for the current CL session.
 * @param mode          Handle for the current random mode
 *
 * @return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_PatchMode_selftestFunction, mcuxClRandom_selftestFunction_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClRandomModes_PatchMode_selftestFunction(
        mcuxClSession_Handle_t session,
        mcuxClRandom_Mode_t mode);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_PRIVATE_PATCHMODE_H_ */
