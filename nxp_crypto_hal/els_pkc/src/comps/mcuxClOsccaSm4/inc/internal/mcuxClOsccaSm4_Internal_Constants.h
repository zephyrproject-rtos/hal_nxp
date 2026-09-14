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

/** @file  mcuxClOsccaSm4_Internal_Constants.h
 *  @brief Internal constant definitions for the mcuxClOsccaSm4 component
 */

#ifndef MCUXCLOSCCASM4_INTERNAL_CONSTANTS_H_
#define MCUXCLOSCCASM4_INTERNAL_CONSTANTS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MCUXCLOSCCASM4_ROTATE_LEFT_UINT32(x, n) (((x) << (n)) | ((x) >> (32U - (n))))
#define MCUXCLOSCCASM4_RK_WORDS            (32U)
#define MCUXCLOSCCASM4_ENCRYPT             (0x1U)
#define MCUXCLOSCCASM4_DECRYPT             (0x0U)
#define MCUXCLOSCCASM4_BLOCK_SIZE          (16u)
#define MCUXCLOSCCASM4_BLOCK_SIZE_WORDS    (MCUXCLOSCCASM4_BLOCK_SIZE / sizeof(uint32_t))

typedef uint32_t mcuxClOsccaSm4_Status_t;

#define MCUXCLOSCCASM4_STATUS_LOADKEY_OK                                      ((mcuxClOsccaSm4_Status_t) 0x011A2E03U)            /**< \brief LoadKey successful */
#define MCUXCLOSCCASM4_STATUS_CRYPT_OK                                        ((mcuxClOsccaSm4_Status_t) 0x011A2E0BU)            /**< \brief Crypt operation successful */
#define MCUXCLOSCCASM4_STATUS_FAULT_ATTACK                                    ((mcuxClOsccaSm4_Status_t) 0x011AF0F0U)            /**< \brief Fault attack detected */
#define MCUXCLOSCCASM4_STATUS_ERROR                                           ((mcuxClOsccaSm4_Status_t) 0x011A533CU)            /**< \brief Feature Failed */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLOSCCASM4_INTERNAL_CONSTANTS_H_ */
