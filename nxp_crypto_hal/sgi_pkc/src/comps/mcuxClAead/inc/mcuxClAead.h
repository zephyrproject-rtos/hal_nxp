/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021, 2024 NXP                                            */
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

/** @file  mcuxClAead.h
 *  @brief Top-level include file for the @ref mcuxClAead component
 *
 *  This includes headers for all of the functionality provided by the @ref mcuxClAead component.
 *
 *  @defgroup mcuxClAead mcuxClAead
 *  @brief Aead component
 *
 *  The mcuxClAead component implements the Authenticated Encryption with Associated Data (AEAD)
 *  operations supported by CLNS.
 *
 *  An example of how to use the @ref mcuxClAead component can be found in /mcuxClAead/ex.
 *
 *  The @ref mcuxClAead component supports interfaces to either authenticate and encrypt or
 *  verify and decrypt a message in one shot (mcuxClAead_crypt) or to either authenticate and
 *  encrypt or verify and decrypt it in parts (mcuxClAead_init, mcuxClAead_process,
 *  mcuxClAead_process_adata and mcuxClAead_finish). In case of processing a message in parts,
 *  first an initialization has to be performed (mcuxClAead_init), followed by zero, one
 *  or multiple updates (mcuxClAead_process_adata and mcuxClAead_process), followed by a
 *  finalization or verification (mcuxClAead_finish/mcuxClAead_verify). The finalization generates
 *  the output tag and destroys the context. The verification generates and compares the output
 *  tag and destroys the context. After the finalization/verification step, no further updates
 *  are possible.
 *
 *  The targeted AEAD algorithm is selected by passing one of the offered algorithm mode
 *  descriptors (@ref mcuxClAead_Modes), which are listed in file mcuxClAead_Modes.h
 *
 * */

#ifndef MCUXCLAEAD_H_
#define MCUXCLAEAD_H_

#include <mcuxClConfig.h> // Exported features flags header

#include <mcuxClAead_Types.h>
#include <mcuxClAead_Functions.h>
#include <mcuxClAead_Constants.h>


#endif /* MCUXCLAEAD_H_ */
