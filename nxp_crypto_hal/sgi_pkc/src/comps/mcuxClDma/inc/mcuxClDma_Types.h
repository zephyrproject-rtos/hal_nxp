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

/**
 * @file  mcuxClDma_Types.h
 * @brief Type and associated constant definitions of the mcuxClDma component.
 */

#ifndef MCUXCLDMA_TYPES_H_
#define MCUXCLDMA_TYPES_H_

#include <mcuxClCore_Platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClDma mcuxClDma
 * @brief DMA component
 * 
 * @defgroup mcuxClDma_Types mcuxClDma_Types
 * @brief Defines the types and associated constants of the @ref mcuxClDma component.
 * @ingroup mcuxClDma
 * @{
 */

/**
 * @brief DMA status code
 *
 * This type provides information about the status of the DMA operation that
 * has been performed.
 */
typedef uint32_t mcuxClDma_Status_t;

/* Status/error codes */
#define MCUXCLDMA_STATUS_SOURCE_BUS_ERROR        ((mcuxClDma_Status_t) 0x03335330u) ///< Source address bus is not accessible by DMA
#define MCUXCLDMA_STATUS_DESTINATION_BUS_ERROR   ((mcuxClDma_Status_t) 0x03335334u) ///< Destination address bus is not accessible by DMA
#define MCUXCLDMA_STATUS_CONFIGURATION_ERROR     ((mcuxClDma_Status_t) 0x03335338u) ///< DMA was not correctly configured
#define MCUXCLDMA_STATUS_OK                      ((mcuxClDma_Status_t) 0x03332E03u) ///< No error occurred

/**
 * @}
 */ /* mcuxClDma_Types */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLDMA_TYPES_H_ */
