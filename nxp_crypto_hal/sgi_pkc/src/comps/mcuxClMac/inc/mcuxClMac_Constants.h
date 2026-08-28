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
 * @file  mcuxClMac_Constants.h
 * @brief Constants and status codes for the mcuxClMac component
 */

#ifndef MCUXCLMAC_CONSTANTS_H_
#define MCUXCLMAC_CONSTANTS_H_

#include <mcuxClConfig.h> // Exported features flags header

/**
 * @defgroup mcuxClMac_Constants mcuxClMac_Constants
 * @brief Constants of @ref mcuxClMac component
 * @ingroup mcuxClMac
 * @{
 */

/* Status codes */
#define MCUXCLMAC_STATUS_ERROR                     ((mcuxClMac_Status_t) 0x08885330U) ///< Functional error detected in MAC operation
#define MCUXCLMAC_STATUS_FAILURE                   ((mcuxClMac_Status_t) 0x08885334U) ///< Functional failure detected
#define MCUXCLMAC_STATUS_INVALID_PARAM             ((mcuxClMac_Status_t) 0x088853F8U) ///< Invalid input provided
#define MCUXCLMAC_STATUS_FAULT_ATTACK              ((mcuxClMac_Status_t) 0x0888F0F0U) ///< Fault attack detected
#define MCUXCLMAC_STATUS_OK                        ((mcuxClMac_Status_t) 0x08882E03U) ///< Blocking operation finished successfully
#define MCUXCLMAC_STATUS_COMPARE_NOK               ((mcuxClMac_Status_t) 0x088889FCU) ///< Blocking operation finished, invalid tag detected
#define MCUXCLMAC_STATUS_JOB_STARTED               ((mcuxClMac_Status_t) 0x08882E47U) ///< Non-blocking operation started successfully
#define MCUXCLMAC_STATUS_JOB_COMPLETED             ((mcuxClMac_Status_t) 0x08882EFCU) ///< Non-blocking operation finished successfully
#define MCUXCLMAC_STATUS_JOB_COMPLETED_COMPARE_NOK ((mcuxClMac_Status_t) 0x08888903U) ///< Non-blocking operation finished, invalid tag detected

/** @}*/

#endif /* MCUXCLMAC_CONSTANTS_H_ */
