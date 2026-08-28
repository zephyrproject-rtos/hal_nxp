/*--------------------------------------------------------------------------*/
/* Copyright 2020, 2025 NXP                                                 */
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

#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>
MCUX_CSSL_ANALYSIS_START_SUPPRESS_STDARG_USAGE("Usage of stdarg.h feature has been analyzed and approved, compiler error has been added for exceptions (when CPU word size > 32 bit)")
#include <stdarg.h>
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_STDARG_USAGE()
#include <stddef.h>

MCUX_CSSL_ANALYSIS_START_SUPPRESS_STDARG_USAGE("Usage of stdarg.h feature has been analyzed and approved, compiler error has been added for exceptions (when CPU word size > 32 bit)")

MCUX_CSSL_FP_FUNCTION_DEF(rotate_right)
static uint32_t rotate_right(uint32_t val, uint32_t shift_amt) {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("shift_amt will be always less than 32.")
    return ((val) >> (shift_amt) % 32u) | ((val) << (32u - (shift_amt)) % 32u);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslParamIntegrity_InternalProtect)
static mcuxCsslParamIntegrity_Checksum_t mcuxCsslParamIntegrity_InternalProtect(uint32_t nargs, va_list args) {
    mcuxCsslParamIntegrity_Checksum_t result = MCUXCSSLPARAMINTEGRITY_BASE_CHECKSUM;
    for(uint32_t i = 0; i < nargs; i++) {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_VA_ARGS_USAGE("This is third party code. va_arg macro from stdarg.h contains two violations to MISRA rule 10.1, two violations to MISRA rule 10.4 and a violation to MISRA rule 20.7")
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW()
        result += rotate_right(va_arg(args, uint32_t), i);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_VA_ARGS_USAGE()
    }
    return result;
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslParamIntegrity_Protect)
mcuxCsslParamIntegrity_Checksum_t mcuxCsslParamIntegrity_Protect
(
    uint32_t nargs,
    ...
)
{
    va_list args;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_VA_ARGS_USAGE("This is third party code. va_start macro from stdarg.h contains a violation to MISRA rule 20.7")
    va_start(args, nargs);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_VA_ARGS_USAGE()

    mcuxCsslParamIntegrity_Checksum_t result = mcuxCsslParamIntegrity_InternalProtect(nargs, args);
    va_end(args);
    return result;
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslParamIntegrity_Validate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslParamIntegrity_Checksum_t) mcuxCsslParamIntegrity_Validate
(
    mcuxCsslParamIntegrity_Checksum_t chk,
    uint32_t nargs,
    ...
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslParamIntegrity_Validate);

    va_list args;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_VA_ARGS_USAGE("This is third party code. va_start macro from stdarg.h contains a violation to MISRA rule 20.7")
    va_start(args, nargs);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_VA_ARGS_USAGE()

    mcuxCsslParamIntegrity_Checksum_t recalculatedChecksum = mcuxCsslParamIntegrity_InternalProtect(nargs, args);
    va_end(args);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslParamIntegrity_Validate,
        (recalculatedChecksum == chk) ? MCUXCSSLPARAMINTEGRITY_CHECK_VALID : MCUXCSSLPARAMINTEGRITY_CHECK_INVALID
    );
}

MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_STDARG_USAGE()
