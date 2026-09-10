/*--------------------------------------------------------------------------*/
/* Copyright 2020-2023 NXP                                                  */
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
 * @file  mcuxClRandom_Constants.h
 * @brief Constant definitions of mcuxClRandom component
 */


#ifndef MCUXCLRANDOM_CONSTANTS_H_
#define MCUXCLRANDOM_CONSTANTS_H_


#include <mcuxClConfig.h> // Exported features flags header

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************/
/* Constants of mcuxClRandom                               */
/**********************************************************/
/**
 * @defgroup mcuxClRandom_Constants mcuxClRandom_Constants
 * @brief Defines all contstants of @ref mcuxClRandom
 * @ingroup mcuxClRandom
 * @{
 */

/** @addtogroup MCUXCLRANDOM_STATUS_
 * mcuxClRandom return code definitions
 * @{ */
#define MCUXCLRANDOM_STATUS_ERROR                  0x0BBB5330u  ///< Random function returned error
#define MCUXCLRANDOM_STATUS_LOW_SECURITY_STRENGTH  0x0BBB5334u  ///< Security strength of given RNG lower than requested
#define MCUXCLRANDOM_STATUS_INVALID_PARAM          0x0BBB53F8u  ///< Random function parameter invalid
#define MCUXCLRANDOM_STATUS_OK                     0x0BBB2E03u  ///< Random function returned successfully
#define MCUXCLRANDOM_STATUS_FAULT_ATTACK           0x0BBBF0F0u  ///< Random function returned fault attack
/** @} */

/**
 * @}
 */ /* mcuxClRandom_Constants */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLRANDOM_TYPES_H_ */
