/*--------------------------------------------------------------------------*/
/* Copyright 2021, 2024 NXP                                                 */
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

#ifndef MCUXCLCORE_PLATFORM_H_
#define MCUXCLCORE_PLATFORM_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <mcuxCsslAnalysis.h>

#include <mcuxClConfig.h> // Exported features flags header

#ifdef MCUXCL_FEATURE_HW_DMA_WORKAROUND

/** Convert the register address to the one used in secure mode. */
#define MCUXCL_MSDK_REG_SECURE_ADDR(x) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Convert pointer to address for bitwise operations needed in bit masking.") \
  ((uint32_t)(x) | (0x1UL << 28)) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

/** Convert the register address to the one used in non-secure mode. */
#define MCUXCL_MSDK_REG_NONSECURE_ADDR(x) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Convert pointer to address for bitwise operations needed in bit masking.") \
  ((uint32_t)(x) & ~(0x1UL << 28)) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

/** Address mapping to allow HW IP access 0x2xxx_xxxx memory range */
#define MCUXCL_HW_DMA_WORKAROUND(addr) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Convert pointer to address for bitwise operations needed in mapping calculations.") \
  (((uint32_t)(MCUXCL_MSDK_REG_NONSECURE_ADDR(addr)) < 0x00780000u) ? ((uint32_t)(addr) | 0x20000000u) : (uint32_t)(addr)) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

#else

#define MCUXCL_HW_DMA_WORKAROUND(addr) \
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER("Convert pointer to address for bitwise operations needed in mapping calculations. This instance needed for consistent macro behaviour.") \
  ((uint32_t)(addr)) \
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_TYPECAST_BETWEEN_INTEGER_AND_POINTER()

#endif /* MCUXCL_FEATURE_DMA_WORKAROUND */

#endif /* MCUXCLCORE_PLATFORM_H_ */
