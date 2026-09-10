/*--------------------------------------------------------------------------*/
/* Copyright 2020, 2022 NXP                                                 */
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
 * @file  mcuxClMac.h
 * @brief Top-level include file for the mcuxClMac component
 *
 * @defgroup mcuxClMac mcuxClMac
 * @brief Message Authentication Code (MAC) component
 *
 * The mcuxClMac component implements Message Authentication Code (MAC) calculation,
 * based on either HMAC or CMAC.
 *
 * An example of how to use the @ref mcuxClMac component can be found in /mcuxClMac/ex.
 *
 * The MAC can either be computed in one shot, using the mcuxClMac_compute function,
 * or the input can be split into multiple parts. In that case, an initialization
 * has to be performed first by calling the mcuxClMac_init function. Now zero, one,
 * or more messages can be added for authentication by calling mcuxClMac_process.
 * Finally, the MAC is generated when the mcuxClMac_finish function is called.
 *
 * The mode to be used, HMAC or CMAC, is defined by passing the corresponding mode
 * descriptor (mcuxClMac_Mode_t) to mcuxClMac_compute or mcuxClMac_init.
 *
 */

#ifndef MCUXCLMAC_H_
#define MCUXCLMAC_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClMac_Types.h>
#include <mcuxClMac_Functions.h>
#include <mcuxClMac_Constants.h>

#endif /* MCUXCLMAC_H_ */
