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

/** @file  mcuxClHash.h
 *  @brief Top-level include file for the @ref mcuxClHash component
 *
 *  This includes headers for all of the functionality provided by the @ref mcuxClHash component.
 *
 *  @defgroup mcuxClHash mcuxClHash
 *  @brief Hash component
 *
 *  The mcuxClHash component implements the Hash functionality supported by CLNS.
 *
 *  An example of how to use the @ref mcuxClHash component can be found in /mcuxClHash/ex.
 *
 *  The @ref mcuxClHash component supports interfaces to either hash a message in one shot
 *  (mcuxClHash_compute) or to hash it in parts (mcuxClHash_init, mcuxClHash_process,
 *  and mcuxClHash_finish). In case of hashing a message in parts, first an initialization
 *  has to be performed (mcuxClHash_init), followed by zero, one, or multiple updates
 *  (mcuxClHash_process), followed by a finalization (mcuxClHash_finish). The finalization
 *  generates the output data (digest) and destroys the context. After the finalization step,
 *  no further updates are possible.
 *
 *  The targeted hash algorithm is selected by passing one of the offered algorithm mode
 *  descriptors (@ref mcuxClHash_Modes), which are listed in file mcuxClHash_Algorithms.h
 *
 *  Note: In case the hashing functionality is based on a hardware co-processor, it might
 *  be necessary to initialize the co-processor, before it's use in the @ref mcuxClHash
 *  component. Please refer to the example for further information on this.
 *
 * */

#ifndef MCUXCLHASH_H_
#define MCUXCLHASH_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClHash_Types.h>
#include <mcuxClHash_Functions.h>
#include <mcuxClHash_MemoryConsumption.h>
#include <mcuxClHash_Constants.h>

#endif /* MCUXCLHASH_H_ */
