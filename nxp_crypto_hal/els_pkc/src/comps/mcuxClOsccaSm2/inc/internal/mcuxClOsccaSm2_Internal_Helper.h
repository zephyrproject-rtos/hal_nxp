/*--------------------------------------------------------------------------*/
/* Copyright 2018-2019, 2021-2024 NXP                                       */
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
 * @file  mcuxClOsccaSm2_Internal_Helper.h
 * @brief defines Internal Helper function
 */

#ifndef MCUXCLOSCCASM2_INTERNAL_HELPER_H_
#define MCUXCLOSCCASM2_INTERNAL_HELPER_H_

#include <mcuxClOscca_Types.h>
#include <mcuxClOsccaSm2_Types.h>
#include <internal/mcuxClOsccaSm2_Internal_Types.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>


/** @brief Secure memory compare successful, operands are equal. */
#define MCUXCLOSCCASM2_STATUS_CMP_EQUAL                                       ((mcuxClOsccaSm2_Status_t) 0x3935U)
/** @brief Secure memory compare successful, operands are not equal. */
#define MCUXCLOSCCASM2_STATUS_NOT_EQUAL                                       ((mcuxClOsccaSm2_Status_t) 0x3969U)

/** @brief Secure import/export successful, data in PKC RAM can be imported/exported securely. */
#define MCUXCLOSCCASM2_STATUS_EXIMPORT_OK                                     ((mcuxClOsccaSm2_Status_t) 0x3970U)
/** @brief Secure import/export failed, data in PKC RAM isn't imported/exported securely. */
#define MCUXCLOSCCASM2_STATUS_EXIMPORT_FAILED                                   ((mcuxClOsccaSm2_Status_t) 0x3992U)

/******************************************************************************/
/* Macros to wrapper the SM2 domain parameter copy                            */
/******************************************************************************/
#define MCUXCLOSCCASM2_FP_DOMAINPARAMETER_COPY(pDomainParamDst, pDomainParamSrc)       \
    do{                                                                               \
        (pDomainParamDst).pA = (pDomainParamSrc).pA;                                  \
        (pDomainParamDst).pB = (pDomainParamSrc).pB;                                  \
        (pDomainParamDst).p.pMPInt = (pDomainParamSrc).p.pMPInt;                      \
        (pDomainParamDst).p.wNumBytes = (pDomainParamSrc).p.wNumBytes;                \
        (pDomainParamDst).pG = (pDomainParamSrc).pG;                                  \
        (pDomainParamDst).n.pMPInt = (pDomainParamSrc).n.pMPInt;                      \
        (pDomainParamDst).n.wNumBytes = (pDomainParamSrc).n.wNumBytes;                \
    } while(false)

/**
 * @brief This function import external data into one PKC operand ram
 *
 *
 * @param[in]  operandIndex   PKC operand index import to
 * @param[in]  pSrc           base address of source buffer
 * @param[in]  length         length[1, 80] of source data, max length of P is 80 bytes
 * @param[in]  buffLen        not used currently
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Import)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm2_Import(
        uint32_t operandIndex,
        mcuxCl_InputBuffer_t pSrc,
        uint32_t length,
        uint32_t buffLen
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_SecureImport)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm2_SecureImport(
        uint32_t operandIndex,
        mcuxCl_InputBuffer_t pSrc,
        uint32_t length,
        uint32_t buffLen
);

/**
 * @brief This function export data from one PKC operand ram
 *
 *
 * @param[in]  operandIndex   PKC operand index export from
 * @param[in]  pDst           base address of target buffer
 * @param[in]  length         length[1, 80] of source data, max length of P is 80 bytes
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_Export)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm2_Export(
        uint32_t operandIndex,
        mcuxCl_Buffer_t pDst,
        uint32_t length
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_SecureExport)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClOsccaSm2_SecureExport(
        uint32_t operandIndex,
        mcuxCl_Buffer_t pDst,
        uint32_t length
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_RobustCompareToZero) /* No semicolon */
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_RobustCompareToZero(
         uint8_t const *pData,
         uint32_t len
);

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClOsccaSm2_RobustCompareBoolean) /* No semicolon */
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm2_Status_t) mcuxClOsccaSm2_RobustCompareBoolean(
         uint8_t const *pTgt,
         uint8_t const *pSrc,
         uint32_t len
);

#define MCUXCLOSCCASM2_FP_REQUEST_PKC(session, callerName) (void)(session)
#define MCUXCLOSCCASM2_FP_RELEASE_PKC(session, callerName) (void)(session)

#define MCUXCLOSCCASM2_FP_CALLED_REQUEST_PKC 0u
#define MCUXCLOSCCASM2_FP_CALLED_RELEASE_PKC 0u

#endif /* MCUXCLOSCCASM2_INTERNAL_HELPER_H_ */
