/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

#ifndef MCUXCLOSCCASAFO_SFR_STATUS_H_
#define MCUXCLOSCCASAFO_SFR_STATUS_H_

#include <mcuxCsslFlowProtection.h>
#include <platform_specific_headers.h>
#include <mcuxClOsccaSafo_SfrAccess.h>

#define MCUXCLOSCCASAFO_SFR_STATUS_ERROR_OK      (0x5u)
#define MCUXCLOSCCASAFO_SFR_STATUS_ERROR_ERROR   (0x2u)

#define MCUXCLOSCCASAFO_SFR_STATUS_ERROR(status) ((MCUXCLOSCCASAFO_SFR_STATUS_ERROR_OK << MCUXCLOSCCASAFO_SFR_FIELD_SHIFT(STATUS,ERROR)) != ((status) & MCUXCLOSCCASAFO_SFR_FIELD_MASK(STATUS,ERROR)))
#define MCUXCLOSCCASAFO_SFR_STATUS_BUSY(status)  (0u != ((status) & MCUXCLOSCCASAFO_SFR_FIELD_MASK(STATUS,BUSY)))

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Read the SAFO STATUS register
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSafo_Sfr_readStatus)
static inline uint32_t mcuxClOsccaSafo_Sfr_readStatus(void)
{
  return MCUXCLOSCCASAFO_SFR_READ(STATUS);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASAFO_SFR_STATUS_H_ */
