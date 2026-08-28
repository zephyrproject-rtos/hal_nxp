/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/** @file  mcuxClSgi_Constants.h
 *  @brief SGI constant header.
 * This header exposes constants used by the @ref mcuxClSgi functions. */

/** @defgroup mcuxClSgi mcuxClSgi
 *  @brief Sgi component
 *
 * */

#ifndef MCUXCLSGI_CONSTANTS_H_
#define MCUXCLSGI_CONSTANTS_H_

#include <mcuxClSgi_Types.h>

/**
 * @defgroup mcuxClSgi_Constants mcuxClSgi_Constants
 * @brief Defines all constants used by the @ref mcuxClSgi functions.
 * @ingroup mcuxClSgi
 * @{
 */

/**********************************************
 * CONSTANTS
 **********************************************/

/**
 * @defgroup MCUXCLSGI_STATUS_ MCUXCLSGI_STATUS_
 * @brief Defines valid mcuxClSgi function return codes
 * @ingroup mcuxClSgi_Types_Macros
 * @{
 */
/* Status/error codes */
#define MCUXCLSGI_STATUS_ERROR                            ((mcuxClSgi_Status_t) 0x0FFF5330U) ///< An error occurred during an SGI operation
#define MCUXCLSGI_STATUS_UNWRAP_ERROR                     ((mcuxClSgi_Status_t) 0x0FFF53B8U) ///< An error occurred during SGI key unwrap, an SGI reset or FULL_FLUSH has to be performed to clear this sticky error
#define MCUXCLSGI_STATUS_KEYSIZE_NOT_SUPPORTED            ((mcuxClSgi_Status_t) 0x0FFF5374U) ///< The given key size is not supported for the operation
#define MCUXCLSGI_STATUS_UNALIGNED_ACCESS_NOT_SUPPORTED   ((mcuxClSgi_Status_t) 0x0FFF5338U) ///< The given key buffer is not aligned correctly for the operation
#define MCUXCLSGI_STATUS_OK                               ((mcuxClSgi_Status_t) 0x0FFF2E03U) ///< The operation was successful and no SGI error occurred
#define MCUXCLSGI_STATUS_FAULT                            ((mcuxClSgi_Status_t) 0x0FFFF0F0U) ///< Fault attack detected

/**
 * @}
 */

#endif  /* MCUXCLSGI_CONSTANTS_H_ */

/**
 * @}
 */
