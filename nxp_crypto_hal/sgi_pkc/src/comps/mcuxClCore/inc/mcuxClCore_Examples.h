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

#ifndef MCUXCLCORE_EXAMPLES_H_
#define MCUXCLCORE_EXAMPLES_H_

#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Macros.h>
#include <mcuxCsslFlowProtection.h>

typedef void (*Interrupt_Callback_t)(void);
void IsrInterface_HandlerInstall(Interrupt_Callback_t callback,uint8_t Interrupt_number);
void IsrInterface_Enable(uint32_t IRQ_Number);
void IsrInterface_Disable(uint32_t IRQ_Number);

/**
 * \def MCUXCLEXAMPLE_FUNCTION
 * \brief Macro to indicate that the symbol is an example function.
 */
// TODO CLNS-3599: #define MCUXCLEXAMPLE_FUNCTION(_name) uint32_t _name(void)
#define MCUXCLEXAMPLE_FUNCTION(_name) \
MCUX_CSSL_ANALYSIS_START_PATTERN_EXAMPLE_FUNCTION() \
bool _name(void); \
bool _name(void) \
MCUX_CSSL_ANALYSIS_STOP_PATTERN_EXAMPLE_FUNCTION()

/**
 * \def MCUXCLEXAMPLE_STATUS_OK
 * \brief Example execution completed successfully.
 */
#define MCUXCLEXAMPLE_STATUS_OK      true // TODO CLNS-3599: 0xC001C0DEu

/**
 * \def MCUXCLEXAMPLE_OK
 * \brief Example execution completed successfully.
 * \deprecated{Replaced by MCUXCLEXAMPLE_STATUS_OK}
 */
#define MCUXCLEXAMPLE_OK      MCUXCLEXAMPLE_STATUS_OK

/**
 * \def MCUXCLEXAMPLE_STATUS_ERROR
 * \brief Example execution resulted in an unexpected error.
 */
#define MCUXCLEXAMPLE_STATUS_ERROR   false // TODO CLNS-3599: 0xEEEEEEEEu

/**
 * \def MCUXCLEXAMPLE_ERROR
 * \brief Example execution resulted in an unexpected error.
 * \deprecated{Replaced by MCUXCLEXAMPLE_STATUS_ERROR}
 */
#define MCUXCLEXAMPLE_ERROR   MCUXCLEXAMPLE_STATUS_ERROR


/**
 * \def MCUXCLEXAMPLE_STATUS_FAILURE
 * \brief Example execution resulted in an expected failure.
 */
#define MCUXCLEXAMPLE_STATUS_FAILURE  false // TODO CLNS-3599: 0xFFFFFFFFu

/**
 * \def MCUXCLEXAMPLE_FAILURE
 * \brief Example execution resulted in an expected failure.
 * \deprecated{Replaced by MCUXCLEXAMPLE_STATUS_FAILURE}
 */
#define MCUXCLEXAMPLE_FAILURE  MCUXCLEXAMPLE_STATUS_FAILURE

/**
 * \brief Assert whether two buffers are equal.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClCore_assertEqual)
static inline bool mcuxClCore_assertEqual(const uint8_t * const x, const uint8_t * const y, uint32_t length)
{
  for (uint32_t i = 0; i < length; ++i)
  {
    if (x[i] != y[i])
    {
      return false;
    }
  }

  return true;
}

#endif /* MCUXCLCORE_EXAMPLES_H_ */
