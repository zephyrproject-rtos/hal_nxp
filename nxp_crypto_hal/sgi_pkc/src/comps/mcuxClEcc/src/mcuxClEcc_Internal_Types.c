/*--------------------------------------------------------------------------*/
/* Copyright 2021-2023 NXP                                                  */
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
 * @file  mcuxClEcc_Internal_Types.c
 * @brief Instantiation of the type descriptors supported by the mcuxClEcc component.
 */

#include <mcuxClEcc_Constants.h>

#ifdef  MCUXCL_FEATURE_ECC_EDDSA
#include <internal/mcuxClEcc_EdDSA_Internal.h>
#endif /* MCUXCL_FEATURE_ECC_EDDSA */
#include <internal/mcuxClEcc_ECDSA_Internal.h>

/**********************************************************/
/* Key pair generation descriptors                        */
/**********************************************************/
#ifdef MCUXCL_FEATURE_ECC_EDDSA
const mcuxClEcc_EdDSA_GenerateKeyPairDescriptor_t mcuxClEcc_EdDsa_GeneratePrivKeyDescriptor =
{
    .options       = MCUXCLECC_EDDSA_PRIVKEY_GENERATE,
    .pPrivKeyInput = NULL
};
#endif /* MCUXCL_FEATURE_ECC_EDDSA */


/**********************************************************/
/* Signature protocol descriptors                         */
/**********************************************************/
#ifdef MCUXCL_FEATURE_ECC_EDDSA

const mcuxClEcc_EdDSA_SignatureProtocolDescriptor_t mcuxClEcc_EdDsa_Ed25519ProtocolDescriptor =
{
    .generateOption = 0u,
    .verifyOption   = 0u,
    .phflag             = MCUXCLECC_EDDSA_PHFLAG_ZERO,
    .pHashPrefix    = NULL,
    .hashPrefixLen      = 0u
};

#endif /* MCUXCL_FEATURE_ECC_EDDSA */

const mcuxClEcc_ECDSA_SignatureProtocolDescriptor_t mcuxClEcc_ECDSA_ProtocolDescriptor =
{
    .generateOption = MCUXCLECC_ECDSA_SIGNATURE_GENERATE_RANDOMIZED,
    .verifyOption   = 0u,
    .pHmacModeDesc  = NULL
};

