/*--------------------------------------------------------------------------*/
/* Copyright 2022, 2024 NXP                                                 */
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

/** @file  mcuxClOsccaMacModes_Helper.c
 *  @brief internal API to implement the SM4 CMAC Key generation of mcuxClOsccaMacModes component */

#include <mcuxClToolchain.h>
#include <mcuxClMac.h>
#include <mcuxClKey.h>
#include <mcuxClMemory.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>
#include <internal/mcuxClOsccaMacModes_Internal_Functions.h>


#ifdef MCUXCL_FEATURE_MACMODES_CMAC_SM4
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaMacModes_SM4_Gen_K1K2)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaMacModes_SM4_Gen_K1K2(uint8_t *output, uint8_t * input)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaMacModes_SM4_Gen_K1K2);
    uint8_t mask;
    uint8_t i;

    for(i = 0U; i <= MCUXCLOSCCASM4_BLOCK_SIZE - 1U; i++)
    {
        output[i] = (uint8_t)((input[i] << 1) & 0xffU);
        uint8_t carryBit = input[i+1U] & 0x80U;
        if((i < MCUXCLOSCCASM4_BLOCK_SIZE - 1U) && (carryBit != 0U))
        {
            MCUX_CSSL_ANALYSIS_START_SUPPRESS_FALSE_POSITIVE_INTEGER_CONVERSION_MISINTERPRETS_DATA("A logical OR-operation with two values of the same width does not misinterpret or wrap data.")
            output[i] = output[i] | (uint8_t)0x01U;
            MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_FALSE_POSITIVE_INTEGER_CONVERSION_MISINTERPRETS_DATA()
        }
    }

    mask = ((input[0u] >> 7U) != 0U) ? 0xffU : 0x00U;
    output[ MCUXCLOSCCASM4_BLOCK_SIZE - 1U] ^= 0x87U & mask;

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClOsccaMacModes_SM4_Gen_K1K2);
}
#endif /* MCUXCL_FEATURE_MACMODES_CMAC_SM4 */

