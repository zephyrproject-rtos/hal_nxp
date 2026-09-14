/*--------------------------------------------------------------------------*/
/* Copyright 2018-2022 NXP                                                  */
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
 * @file  mcuxClOsccaSm2_Internal.h
 * @brief internal header for SM2 curves
 */


#ifndef MCUXCLOSCCASM2_INTERNAL_H_
#define MCUXCLOSCCASM2_INTERNAL_H_


#include <stdbool.h>
#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <mcuxClSession.h>
#include <mcuxClOsccaSm2_Types.h>
#include <internal/mcuxClOsccaSm2_Internal_PkcWaLayout.h>
#include <internal/mcuxClOsccaSm2_Internal_FP.h>
#include <internal/mcuxClOsccaSm2_Internal_FUP.h>
#include <internal/mcuxClOsccaSm2_Internal_Helper.h>
#include <internal/mcuxClOsccaSm2_Internal_Ecc.h>
#include <internal/mcuxClOsccaSm2_Internal_Types.h>
#include <internal/mcuxClOsccaSm2_Internal_Functions.h>
#include <internal/mcuxClOsccaSm2_Internal_CryptoUtils.h>
#include <mcuxClBuffer.h>
#ifdef MCUXCL_FEATURE_SM2_INTERNAL
#include <internal/mcuxClOsccaSm2_Internal_ConstructTypes.h>
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */

#endif /* MCUXCLOSCCASM2_INTERNAL_H_ */
