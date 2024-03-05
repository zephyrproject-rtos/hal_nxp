/*--------------------------------------------------------------------------*/
/* Copyright 2020 NXP                                                       */
/*                                                                          */
/* NXP Confidential. This software is owned or controlled by NXP and may    */
/* only be used strictly in accordance with the applicable license terms.   */
/* By expressly accepting such terms or by downloading, installing,         */
/* activating and/or otherwise using the software, you are agreeing that    */
/* you have read, and that you agree to comply with and are bound by, such  */
/* license terms. If you do not agree to be bound by the applicable license */
/* terms, then you may not retain, install, activate or otherwise use the   */
/* software.                                                                */
/*--------------------------------------------------------------------------*/

#include <mcuxCsslParamIntegrity.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxCsslFlowProtection_FunctionIdentifiers.h>
#include <mcuxCsslAnalysis.h>
#include <stdarg.h>
#include <stddef.h>

#ifdef __COVERITY__
#pragma coverity compliance block deviate MISRA_C_2012_Rule_17_1 "Usage of stdarg.h feature has been analyzed and approved, compiler error has been added for exceptions (when CPU word size > 32 bit)"
#endif

MCUX_CSSL_FP_FUNCTION_DEF(rotate_right)
static uint32_t rotate_right(uint32_t val, uint32_t shift_amt) {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("shift_amt will be always less than 32.")
    return ((val) >> (shift_amt) % 32u) | ((val) << (32u - (shift_amt)) % 32u);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslParamIntegrity_InternalProtect)
static mcuxCsslParamIntegrity_Checksum_t mcuxCsslParamIntegrity_InternalProtect(size_t nargs, va_list args) {
    mcuxCsslParamIntegrity_Checksum_t result = MCUXCSSLPARAMINTEGRITY_BASE_CHECKSUM;
    for(size_t i = 0; i < nargs; i++) {
#ifdef __COVERITY__
#pragma coverity compliance block deviate MISRA_C_2012_Rule_10_1 "This is third party code. va_arg macro from stdarg.h contains two violations to MISRA rule 10.1"
#pragma coverity compliance block deviate MISRA_C_2012_Rule_10_4 "This is third party code. va_arg macro from stdarg.h contains two violations to MISRA rule 10.4"
#pragma coverity compliance block deviate MISRA_C_2012_Rule_20_7 "This is third party code. va_arg macro from stdarg.h contains a violation to MISRA rule 20.7"
#endif
        result += rotate_right(va_arg(args, uint32_t), i);
#ifdef __COVERITY__
#pragma coverity compliance end_block MISRA_C_2012_Rule_10_1
#pragma coverity compliance end_block MISRA_C_2012_Rule_10_4
#pragma coverity compliance end_block MISRA_C_2012_Rule_20_7
#endif
    }
    return result;
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslParamIntegrity_Protect)
mcuxCsslParamIntegrity_Checksum_t mcuxCsslParamIntegrity_Protect
(
    size_t nargs, 
    ...
)
{
    va_list args;
#ifdef __COVERITY__
#pragma coverity compliance block deviate MISRA_C_2012_Rule_20_7 "This is third party code. va_start macro from stdarg.h contains a violation to MISRA rule 20.7"
#endif
    va_start(args, nargs);
#ifdef __COVERITY__
#pragma coverity compliance end_block MISRA_C_2012_Rule_20_7
#endif
    mcuxCsslParamIntegrity_Checksum_t result = mcuxCsslParamIntegrity_InternalProtect(nargs, args);
    va_end(args);
    return result;
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxCsslParamIntegrity_Validate)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxCsslParamIntegrity_Checksum_t) mcuxCsslParamIntegrity_Validate
(
    mcuxCsslParamIntegrity_Checksum_t chk, 
    size_t nargs, 
    ...
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxCsslParamIntegrity_Validate);

    va_list args;
#ifdef __COVERITY__
#pragma coverity compliance block deviate MISRA_C_2012_Rule_20_7 "This is third party code. va_start macro from stdarg.h contains a violation to MISRA rule 20.7"
#endif
    va_start(args, nargs);
#ifdef __COVERITY__
#pragma coverity compliance end_block MISRA_C_2012_Rule_20_7
#endif
    mcuxCsslParamIntegrity_Checksum_t recalculatedChecksum = mcuxCsslParamIntegrity_InternalProtect(nargs, args);
    va_end(args);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxCsslParamIntegrity_Validate, 
        (recalculatedChecksum == chk) ? MCUXCSSLPARAMINTEGRITY_CHECK_VALID : MCUXCSSLPARAMINTEGRITY_CHECK_INVALID
    );
}

#ifdef __COVERITY__
#pragma coverity compliance end_block MISRA_C_2012_Rule_17_1
#endif
