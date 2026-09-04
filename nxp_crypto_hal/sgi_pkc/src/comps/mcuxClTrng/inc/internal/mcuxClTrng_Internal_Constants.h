/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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
 * @file  mcuxClTrng_Internal_Constants.h
 * @brief Constant definitions of mcuxClTrng component
 */


#ifndef MCUXCLTRNG_INTERNAL_CONSTANTS_H_
#define MCUXCLTRNG_INTERNAL_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <stdint.h>
#include <internal/mcuxClTrng_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Constants of mcuxClTrng                                 */
/**********************************************************/
/**
 * @defgroup mcuxClTrng_Internal_Constants mcuxClTrng_Internal_Constants
 * @brief Defines all contstants of @ref mcuxClTrng
 * @ingroup mcuxClTrng
 * @{
 */

/** @addtogroup MCUXCLTRNG_STATUS_
 * mcuxClTrng return code definitions
 * @{ */
#define MCUXCLTRNG_STATUS_ERROR                  ((mcuxClTrng_Status_t) 0x0FF15330u)  ///< An error occurred during the TRNG operation
#define MCUXCLTRNG_STATUS_OK                     ((mcuxClTrng_Status_t) 0x0FF12E03u)  ///< TRNG operation returned successfully
#define MCUXCLTRNG_STATUS_FAULT_ATTACK           ((mcuxClTrng_Status_t) 0x0FF1F0F0u)  ///< A fault attack is detected
/** @} */

/**
 * @}
 */ /* mcuxClTrng_Constants */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLTRNG_INTERNAL_CONSTANTS_H_ */
