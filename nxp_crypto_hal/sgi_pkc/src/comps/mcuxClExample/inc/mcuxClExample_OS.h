/*--------------------------------------------------------------------------*/
/* Copyright 2025 NXP                                                       */
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

#ifndef MCUXCLEXAMPLE_OS_H_
#define MCUXCLEXAMPLE_OS_H_

#include <mcuxClConfig.h> // Exported features flags header
#include <mcuxClCore_Platform.h>
#include <mcuxClCore_Examples.h>

/**
 * @brief Install the interupt handler function in the controller for a specific IRQ number.
 *
 * @param       callback    The interrupt handler function
 * @param       IRQNumber   The IRQ to install the interrupt handler function for
 *
 * @returns void
 *
 * @note This is an abstraction function to illustrate the required OS functionality by the example code.
 *       The implementation most likely needs to be updated to map it to the corresponding functionality
 *       from the target OS that will be used.
*/
static inline void mcuxClExample_OS_Interrupt_Callback_Install(Interrupt_Callback_t callback, uint8_t IRQNumber)
{
  IsrInterface_HandlerInstall(callback, IRQNumber);
}

/**
 * @brief Uninstall the interupt handler function in the controller for a specific IRQ number.
 *        Currently not implemented because it's not used in the CL.
 *
 * @returns void
 *
 * @note This is an abstraction function to illustrate the required OS functionality by the example code.
 *       The implementation most likely needs to be updated to map it to the corresponding functionality
 *       from the target OS that will be used.
*/
static inline void mcuxClExample_OS_Interrupt_Callback_Uninstall(void)
{
  /* Intended empty */
}

/**
 * @brief Enable a specific IRQ number in the controller.
 *
 * @param       IRQNumber    The IRQ to enable the interrupt for
 *
 * @returns void
 *
 * @note This is an abstraction function to illustrate the required OS functionality by the example code.
 *       The implementation most likely needs to be updated to map it to the corresponding functionality
 *       from the target OS that will be used.
*/
static inline void mcuxClExample_OS_Interrupt_Enable(uint32_t IRQNumber)
{
  IsrInterface_Enable(IRQNumber);
}

/**
 * @brief Disable a specific IRQ number in the controller.
 *
 * @param       IRQNumber    The IRQ to disable the interrupt for
 *
 * @returns void
 *
 * @note This is an abstraction function to illustrate the required OS functionality by the example code.
 *       The implementation most likely needs to be updated to map it to the corresponding functionality
 *       from the target OS that will be used.
*/
static inline void mcuxClExample_OS_Interrupt_Disable(uint32_t IRQNumber)
{
  IsrInterface_Disable(IRQNumber);
}


#endif /* MCUXCLEXAMPLE_OS_H_ */
