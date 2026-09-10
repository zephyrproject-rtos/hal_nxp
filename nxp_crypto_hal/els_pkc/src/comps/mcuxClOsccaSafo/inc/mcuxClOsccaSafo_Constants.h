/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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

/** @file  mcuxClOsccaSafo_Constants.h
 *  @brief SAFO constant header.
 * This header exposes constants used by the @ref mcuxClOsccaSafo functions. */

#include <mcuxClOsccaSafo_Types.h>

/**
 * @defgroup mcuxClOsccaSafo_Constants mcuxClOsccaSafo_Constants
 * @brief Defines all constants used by the @ref mcuxClOsccaSafo functions.
 * @ingroup mcuxClOsccaSafo
 * @{
 */

#ifndef MCUXCLOSCCASAFO_CONSTANTS_H
#define MCUXCLOSCCASAFO_CONSTANTS_H

/**********************************************
 * CONSTANTS
 **********************************************/

/**
 * @defgroup MCUXCLOSCCASAFO_STATUS_ MCUXCLOSCCASAFO_STATUS_
 * @brief Defines valid mcuxClOsccaSafo function return codes
 * @ingroup mcuxClOsccaSafo_Types_Macros
 * @{
 */
/* Status/error codes */
#define MCUXCLOSCCASAFO_STATUS_ERROR           ((mcuxClOsccaSafo_Status_t) 0x0FF95330u) ///< An error occured during an SAFO operation
#define MCUXCLOSCCASAFO_STATUS_OK              ((mcuxClOsccaSafo_Status_t) 0x0FF92E03u) ///< No error occured

/**
 * @}
 */

#endif  /* MCUXCLOSCCASAFO_CONSTANTS_H */

/**
 * @}
 */
