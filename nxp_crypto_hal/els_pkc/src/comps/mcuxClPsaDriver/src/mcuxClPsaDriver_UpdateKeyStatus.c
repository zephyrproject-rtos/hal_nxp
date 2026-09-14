/*--------------------------------------------------------------------------*/
/* Copyright 2023-2024 NXP                                                  */
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


#include <mcuxClKey_Types.h>
#include <mcuxClPsaDriver.h>
#include <mcuxClPsaDriver_Oracle.h>
#include <internal/mcuxClPsaDriver_Functions.h>
#include <internal/mcuxClPsaDriver_Internal.h>
#include <mcuxCsslAnalysis.h>

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusSuspend(
    mcuxClKey_Descriptor_t *key_descriptor)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    psa_key_attributes_t *attributes = mcuxClPsaDriver_castAuxDataToKeyAttributes(key_descriptor);

    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    if(false == (MCUXCLPSADRIVER_IS_LOCAL_STORAGE(location)) )
    {
        return mcuxClPsaDriver_Oracle_SuspendKey(key_descriptor);
    }
    else
    {
        return PSA_SUCCESS;
    }
}

psa_status_t mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusResume(
    mcuxClKey_Descriptor_t *key_descriptor)
{
    psa_key_attributes_t *attributes = mcuxClPsaDriver_castAuxDataToKeyAttributes(key_descriptor);

    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    if(false == (MCUXCLPSADRIVER_IS_LOCAL_STORAGE(location)) )
    {
        return mcuxClPsaDriver_Oracle_ResumeKey(key_descriptor);
    }
    else
    {
        return PSA_SUCCESS;
    }
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_UpdateKeyStatusUnload(
    mcuxClKey_Descriptor_t *key_descriptor)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    psa_key_attributes_t *attributes = mcuxClPsaDriver_castAuxDataToKeyAttributes(key_descriptor);

    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    if(false == (MCUXCLPSADRIVER_IS_LOCAL_STORAGE(location)) )
    {
        return mcuxClPsaDriver_Oracle_UnloadKey(key_descriptor);
    }
    else
    {
        // the keydescriptor contains a reference to the key_buffer, wiping it would mean wiping the original
        return PSA_SUCCESS;
    }
}

