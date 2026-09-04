/*--------------------------------------------------------------------------*/
/* Copyright 2021-2022, 2024 NXP                                            */
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
 * @file  mcuxClEcc_Mont_Internal_PkcWaLayout.h
 * @brief internal header of mcuxClEcc MontDH PKC workarea layout
 */


#ifndef MCUXCLECC_MONT_INTERNAL_PKCWALAYOUT_H_
#define MCUXCLECC_MONT_INTERNAL_PKCWALAYOUT_H_

#include <mcuxClCore_Platform.h>
#include <internal/mcuxClEcc_Internal_PkcWaLayout.h>


/**********************************************************/
/** PKC workarea memory layout used for MontDH functions. */
/**********************************************************/
#define MONT_V0   ECC_V0
#define MONT_V1   ECC_V1
#define MONT_V2   ECC_V2
#define MONT_V3   ECC_V3
#define MONT_V4   ECC_V4
#define MONT_V5   ECC_V5
#define MONT_V6   ECC_V6
#define MONT_V7   ECC_V7

#define MONT_VX1  ECC_V8
#define MONT_VZ1  ECC_V9
#define MONT_VX2  ECC_VA
#define MONT_VZ2  ECC_VB

#define MONT_X1   ECC_COORD00 /* Make sure the pointer entry for MONT_X1 to be at a 64-bit aligned address */
#define MONT_Z1   ECC_COORD01
#define MONT_X2   ECC_COORD02
#define MONT_Z2   ECC_COORD03
#define MONT_X0   ECC_COORD04
#define MONT_Z0   ECC_COORD05

/* Virtual and real buffer amounts definition for Mont functions */
#define ECC_MONTDH_NO_OF_VIRTUALS  ECC_NO_OF_VIRTUALS
#define ECC_MONTDH_NO_OF_BUFFERS   (MONT_Z0 + 1u - ECC_MONTDH_NO_OF_VIRTUALS)


#endif /* MCUXCLECC_MONT_INTERNAL_PKCWALAYOUT_H_ */
