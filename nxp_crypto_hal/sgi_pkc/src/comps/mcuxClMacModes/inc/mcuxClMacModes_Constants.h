/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
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
 * @file  mcuxClMacModes_Constants.h
 * @brief Constants for the mcuxClMacModes component
 */

#ifndef MCUXCLMACMODES_CONSTANTS_H_
#define MCUXCLMACMODES_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClMacModes_Constants mcuxClMacModes_Constants
 * @brief Constants of @ref mcuxClMacModes component
 * @ingroup mcuxClMacModes
 * @{
 */

/* Output sizes */
#define MCUXCLMAC_CMAC_OUTPUT_SIZE                     (16U)                                              ///< Size of CMAC output in bytes:         128 bits (16 bytes)
#define MCUXCLMAC_CMAC_OUTPUT_SIZE_IN_WORDS            (MCUXCLMAC_CMAC_OUTPUT_SIZE / sizeof(uint32_t))   ///< Size of CMAC output in bytes:         128 bits (16 bytes)

#define MCUXCLMACMODES_MAX_OUTPUT_SIZE                 (16U)

#define MCUXCLMACMODES_MAX_OUTPUT_SIZE_IN_WORDS        (MCUXCLMACMODES_MAX_OUTPUT_SIZE / sizeof(uint32_t))

/** @}*/

#endif /* MCUXCLMACMODES_CONSTANTS_H_ */
