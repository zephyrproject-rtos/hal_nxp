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
 *
 * @file:    mcuxClOsccaSm2_SelfTest.h
 * @brief:   Self test function prototype definitions for the OSCCA SM2 component
 *
 */

#ifndef MCUXCLOSCCA_SM2_SELFTEST_H_
#define MCUXCLOSCCA_SM2_SELFTEST_H_

#include <mcuxClSession.h>
#include <mcuxClHash.h>
#include <mcuxClOsccaSm3_Constants.h>
#include <mcuxClOsccaSm2.h>
#include <mcuxClKey.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************************************/
/** \brief SM2 selftest error codes                                                             */
/************************************************************************************/

typedef uint32_t mcuxClOsccaSm2_SelfTest_Status_t;

#define MCUXCLOSCCASM2_STATUS_SELFTEST_OK                                 ((mcuxClOsccaSm2_SelfTest_Status_t) 0x011B2E4FU)
#define MCUXCLOSCCASM2_STATUS_SELFTEST_FAIL                               ((mcuxClOsccaSm2_SelfTest_Status_t) 0x011B53FCU)
#define MCUXCLOSCCASM2_STATUS_SELFTEST_FAULT_ATTACK                       ((mcuxClOsccaSm2_SelfTest_Status_t) 0x011BF0F0U)

/**
 * \brief This function tests the OSCCA SM2 encryption and decryption APIs.
 *
 * \param[in]  session                   Pointer to #mcuxClSession_Descriptor
 *
 * \returns Result of the test
 *
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_OK               Test succeeded
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_FAIL             Test failed
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_FAULT_ATTACK     Checking security counter failed or APIs returned FAULT_ATTACK
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_EncDec_SelfTest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_SelfTest_Status_t) mcuxClOsccaSm2_EncDec_SelfTest(
    mcuxClSession_Handle_t session
);

/**
 * \brief This function tests the OSCCA SM2 signature and verification APIs.
 *
 * \param[in]  session                   Pointer to #mcuxClSession_Descriptor
 *
 * \returns Result of the test
 *
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_OK               Test succeeded
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_FAIL             Test failed
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_FAULT_ATTACK     Checking security counter failed or APIs returned FAULT_ATTACK
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_SignVerify_SelfTest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_SelfTest_Status_t) mcuxClOsccaSm2_SignVerify_SelfTest(
    mcuxClSession_Handle_t session
);

/**
 * \brief This function tests the OSCCA SM2 keyexchange APIs.
 *
 * \param[in]  session                   Pointer to #mcuxClSession_Descriptor
 *
 * \returns Result of the test
 *
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_OK               Test succeeded
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_FAIL             Test failed
 * \retval ::MCUXCLOSCCASM2_STATUS_SELFTEST_FAULT_ATTACK     Checking security counter failed or APIs returned FAULT_ATTACK
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_KeyExchange_SelfTest)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_SelfTest_Status_t) mcuxClOsccaSm2_KeyExchange_SelfTest(
    mcuxClSession_Handle_t session
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // MCUXCLOSCCA_SM2_SELFTEST_H_
