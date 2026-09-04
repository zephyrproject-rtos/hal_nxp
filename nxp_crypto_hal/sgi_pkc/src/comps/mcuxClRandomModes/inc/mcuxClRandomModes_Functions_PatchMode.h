/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023, 2025 NXP                                            */
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

#ifndef MCUXCLRANDOMMODES_FUNCTIONS_PATCHMODE_H_
#define MCUXCLRANDOMMODES_FUNCTIONS_PATCHMODE_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClSession.h>
#include <mcuxClRandom_Types.h>
#include <mcuxClBuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mcuxClRandomModes_Functions_PatchMode mcuxClRandomModes_Functions_PatchMode
 * \brief Random operations in PATCH_MODE.
 * \ingroup mcuxClRandomModes
 * @{
 */

/* Interface definition for a custom RNG function */
typedef mcuxClRandom_Status_t (* mcuxClRandomModes_CustomGenerateAlgorithm_t)(
    mcuxClSession_Handle_t session,
    mcuxClRandom_Context_t pCustomCtx,
    mcuxCl_Buffer_t pOut,
    uint32_t outLength
);

/**
 * \brief This function creates a PATCH_MODE descriptor
 *
 * This function creates a PATCH_MODE descriptor.
 * The function expects as input a custom function to be used inside the CL functions for random number generation as well as
 * a pointer to a context buffer which can be used by the custom generate function.
 * The custom generate function may also use all CPU workarea allocated for the mcuxClRandom_generate function.
 * The function shall be called prior to an mcuxClRandom_init call.
 *
 * \param  patchMode[out]               Pointer to PATCH_MODE descriptor to be initialized
 * \param  customGenerateAlgorithm[in]  Pointer to the custom generate function
 * \param  pCustomCtx[in]               Pointer to a custom context which shall be used by the passed custom generate function
 * \param  securityStrength[in]         Security level for which the patch DRBG shall be used
 *
 * \return status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClRandomModes_createPatchMode)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClRandom_Status_t) mcuxClRandomModes_createPatchMode(
    mcuxClRandom_ModeDescriptor_t * patchMode,
    mcuxClRandomModes_CustomGenerateAlgorithm_t customGenerateAlgorithm,
    mcuxClRandom_Context_t pCustomCtx,
    uint32_t securityStrength
);

/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOMMODES_FUNCTIONS_PATCHMODE_H_ */
