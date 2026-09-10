/*--------------------------------------------------------------------------*/
/* Copyright 2016, 2021-2023 NXP                                            */
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
 * @file:    mcuxClOsccaSm2_Constants.h
 * @brief:   Platform related definitions for the OSCCA SM2 component
 *
 */

#ifndef MCUXCLOSCCASM2_CONSTANTS_H_
#define MCUXCLOSCCASM2_CONSTANTS_H_

#include <mcuxClOscca_Types.h>
#include <mcuxClOscca_Memory.h>
#include <mcuxClOsccaSm2_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MCUXCL_FEATURE_SM2_KEYAGREEMENT
/**
 * @defgroup mcuxClOsccaSm2_Constants mcuxClOsccaSm2_Constants
 * @brief Constants used by the OSCCA SM2 operations.
 * @ingroup mcuxClOsccaSm2
 * @{
 */
/************************************************************************************************/
/** @brief Definition of some constant used by additional inputs for SM2 key agreement through internal call */
/************************************************************************************************/
#define MCUXCLOSCCASM2_KEYAGREEMENT_NUM_OF_ADDITIONAL_INPUTS         7u
#define MCUXCLOSCCASM2_KEYAGREEMENT_PREHASH_INITIATOR                0u
#define MCUXCLOSCCASM2_KEYAGREEMENT_PREHASH_RESPONDER                1u
#define MCUXCLOSCCASM2_KEYAGREEMENT_PRIVATEEPHEMERALKEY              2u
#define MCUXCLOSCCASM2_KEYAGREEMENT_PUBLICEPHEMERALPOINT             3u
#define MCUXCLOSCCASM2_KEYAGREEMENT_PUBLICEPHEMERALPOINT_PARTY2      4u
#define MCUXCLOSCCASM2_KEYAGREEMENT_CONFIRMATION_R2I                 5u
#define MCUXCLOSCCASM2_KEYAGREEMENT_CONFIRMATION_I2R                 6u
/**
 * @}
 */ /* mcuxClOsccaSm2_Constants */
#endif /* MCUXCL_FEATURE_SM2_KEYAGREEMENT */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM2_CONSTANTS_H_ */
