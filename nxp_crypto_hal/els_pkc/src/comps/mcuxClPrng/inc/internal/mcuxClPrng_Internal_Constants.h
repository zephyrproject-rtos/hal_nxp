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

/**
 * @file  mcuxClPrng_Internal_Constants.h
 * @brief Constant definitions of mcuxClPrng component
 */


#ifndef MCUXCLPRNG_INTERNAL_CONSTANTS_H_
#define MCUXCLPRNG_INTERNAL_CONSTANTS_H_

#include <internal/mcuxClPrng_Internal_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Constants of mcuxClPrng                                 */
/**********************************************************/
/**
 * @defgroup mcuxClPrng_Internal_Constants mcuxClPrng_Internal_Constants
 * @brief Defines all contstants of @ref mcuxClPrng
 * @ingroup mcuxClPrng
 * @{
 */

/** @addtogroup MCUXCLPRNG_STATUS_
 * mcuxClPrng return code definitions
 * @{ */
#define MCUXCLPRNG_STATUS_ERROR                  ((mcuxClPrng_Status_t) 0x0FF55330u)  ///< An error occurred during the PRNG operation
#define MCUXCLPRNG_STATUS_OK                     ((mcuxClPrng_Status_t) 0x0FF52E03u)  ///< PRNG operation returned successfully
#define MCUXCLPRNG_STATUS_FAULT_ATTACK           ((mcuxClPrng_Status_t) 0x0FF5F0F0u)  ///< A fault attack is detected
/** @} */


/**
 * @}
 */ /* mcuxClPrng_Constants */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPRNG_INTERNAL_CONSTANTS_H_ */
