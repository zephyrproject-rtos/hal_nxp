/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

/** @file  mcuxClOsccaAeadModes_MemoryConsumption.h
 *  @brief Defines the memory consumption for the mcuxClOsccaAeadModes component */

#ifndef MCUXCLOSCCAAEADMODES_MEMORYCONSUMPTION_H_
#define MCUXCLOSCCAAEADMODES_MEMORYCONSUMPTION_H_
/**
 * @defgroup mcuxClOsccaAeadModes_MemoryConsumption mcuxClOsccaAeadModes_MemoryConsumption
 * @brief Defines the memory consumption for the mcuxClOsccaAeadModes component
 * @ingroup mcuxClOsccaAeadModes
 * @{
 */

#ifdef MCUXCL_FEATURE_SM4_CCM

/** @def MCUXCLOSCCAAEADMODES_WA_MAX_SIZE
 *  @brief Define the max workarea size in bytes required for this component
 */
#define MCUXCLOSCCAAEADMODES_WA_MAX_SIZE (160u)

/** @def MCUXCLOSCCAAEADMODES_WA_MAX_SIZE_IN_WORDS
 *  @brief Define the max workarea size in words required for this component
 */
#define MCUXCLOSCCAAEADMODES_WA_MAX_SIZE_IN_WORDS (MCUXCLOSCCAAEADMODES_WA_MAX_SIZE / sizeof(uint32_t))

/** @def MCUXCLOSCCAAEADMODES_WA_CCM_ENC_SIZE
 *  @brief Define the workarea size in bytes required for CCM ENC mode
 */
#define MCUXCLOSCCAAEADMODES_WA_CCM_ENC_SIZE (160u)

/** @def MCUXCLOSCCAAEADMODES_WA_CCM_ENC_SIZE_IN_WORDS
 *  @brief Define the workarea size in words required for CCM ENC mode
 */
#define MCUXCLOSCCAAEADMODES_WA_CCM_ENC_SIZE_IN_WORDS (MCUXCLOSCCAAEADMODES_WA_CCM_ENC_SIZE / sizeof(uint32_t))

/** @def MCUXCLOSCCAAEADMODES_WA_CCM_DEC_SIZE
 *  @brief Define the workarea size in bytes required for CCM DEC mode
 */
#define MCUXCLOSCCAAEADMODES_WA_CCM_DEC_SIZE (160u)

/** @def MCUXCLOSCCAAEADMODES_WA_CCM_DEC_SIZE_IN_WORDS
 *  @brief Define the workarea size in words required for CCM DEC mode
 */
#define MCUXCLOSCCAAEADMODES_WA_CCM_DEC_SIZE_IN_WORDS (MCUXCLOSCCAAEADMODES_WA_CCM_DEC_SIZE / sizeof(uint32_t))


#define MCUXCLOSCCAAEADMODES_CTX_SIZE               (128u)
#define MCUXCLOSCCAAEADMODES_CTX_SIZE_IN_WORDS      (MCUXCLOSCCAAEADMODES_CTX_SIZE / sizeof(uint32_t))

#endif /* MCUXCL_FEATURE_SM4_CCM */
/**
 * @}
 */ /* mcuxClOsccaAeadModes_MemoryConsumption */
 
#endif /* MCUXCLOSCCAAEADMODES_MEMORYCONSUMPTION_H_ */
