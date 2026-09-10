/*--------------------------------------------------------------------------*/
/* Copyright 2022 NXP                                                       */
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
 * @file mcuxClOsccaSm2.h
 * @brief Top level header of mcuxClOsccaSm2 component
 *
 * @defgroup mcuxClOsccaSm2 mcuxClOsccaSm2
 * @brief SM2 Cryptography component
 */


#ifndef MCUXCLOSCCASM2_H_
#define MCUXCLOSCCASM2_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClOsccaSm2_Types.h>
#include <mcuxClOsccaSm2_Functions.h>
#include <mcuxClOsccaSm2_Constants.h>
#include <mcuxClOsccaSm2_KeyTypes.h>
#include <mcuxClOsccaSm2_MemoryConsumption.h>
#ifdef MCUXCL_FEATURE_SM2_INTERNAL
#include <mcuxClOsccaSm2_ModeConstants.h>
#endif /* MCUXCL_FEATURE_SM2_INTERNAL */
#include <mcuxClOsccaSm2_MemoryConsumption.h>

#endif /* MCUXCLOSCCASM2_H_ */
