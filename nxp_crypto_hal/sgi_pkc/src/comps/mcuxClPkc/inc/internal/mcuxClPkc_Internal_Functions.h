/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
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
 * @file  mcuxClPkc_Internal_Functions.h
 * @brief Internal APIs of mcuxClPkc component
 */


#ifndef MCUXCLPKC_INTERNAL_FUNCTIONS_H_
#define MCUXCLPKC_INTERNAL_FUNCTIONS_H_


#include <mcuxClCore_Platform.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClSession.h>
#include <internal/mcuxClPkc_Internal_Types.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup mcuxClPkc_Internal_Functions mcuxClPkc_Internal_Functions
 * @brief Defines all functions of @ref mcuxClPkc
 * @ingroup mcuxClPkc
 * @{
 */


/**********************************************************/
/* PKC initialization and deinitialization                */
/**********************************************************/
/**
 * @addtogroup mcuxClPkc_Functions_Init
 * mcuxClPkc functions of PKC initialization and deinitialization
 * @{
 */

/**
 * @brief Function type for PKC initialization engine
 *
 * Generic function pointer to PKC initialization function
 *
 * @param[in]  session  handle for the current CL session.
 *
 * @return void
*/
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClPkc_PkcInitializeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClPkc_PkcInitializeEngine_t)(mcuxClSession_Handle_t session));

/**
 * @brief Function type for PKC deinitialization engine
 *
 * Generic function pointer to PKC deinitialization function
 *
 * @return void
*/
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClPkc_PkcDeInitializeEngine_t,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (* mcuxClPkc_PkcDeInitializeEngine_t)(void));

/**
 * @brief initialize PKC hardware
 *
 * This function initializes PKC hardware.
 *
 * @param[in]  session handle for the current CL session.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_Initialize, mcuxClPkc_PkcInitializeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_Initialize(
    mcuxClSession_Handle_t session
    );
/** Helper macro to call #mcuxClPkc_Initialize with flow protection. */
#define MCUXCLPKC_FP_INITIALIZE(session)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_Initialize(session))

/**
 * @brief deinitialize PKC hardware
 *
 * This function deinitializes PKC hardware.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_Deinitialize, mcuxClPkc_PkcDeInitializeEngine_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_Deinitialize(void);
/** Helper macro to call #mcuxClPkc_Deinitialize with flow protection. */
#define MCUXCLPKC_FP_DEINITIALIZE(pState)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_Deinitialize())


/**
 * @}
 */ /* mcuxClPkc_Functions_Init */


/**********************************************************/
/* UPTR table                                             */
/**********************************************************/
/**
 * @addtogroup mcuxClPkc_Functions_UPTRT
 * mcuxClPkc functions of PKC UPTR table setup
 * @{
 */

/**
* @brief Initialize UPTR table.

 * This function initializes elements in UPTR table.
 * UPTR table contains the address (16-bit offset in PKC workarea) of each buffer (PKC operand).
 * Each element of the table will be initialized with a 16-bit offset, associated with a buffer allocated in sequence in PKC workarea.
 *
 * @param[out] pUPTRT       pointer to the first element to be initialized in UPTR table.
 * @param[in]  pBaseBuffer  address of the buffer in PKC workarea, with which the first element will be associated.
 * @param      bufferLength byte length of each buffer in PKC workarea.
 * @param      noOfBuffer   number of elements to be initialized.
 *
 * @pre
 *  - @p pUPTRT shall be 2-byte aligned.
 *  - @p pBaseBuffer shall be MCUXCLPKC_WORDSIZE aligned.
 *  - @p bufferLength shall be a multiple of MCUXCLPKC_WORDSIZE.
 *  - When calling this function, there shall be no on-going and pending PKC calculations using the specified UPTR table elements.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_GenerateUPTRT)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_GenerateUPTRT(
    uint16_t *pUPTRT,
    const uint8_t *pBaseBuffer,
    uint16_t bufferLength,
    uint8_t noOfBuffer
    );
/** Helper macro to call #mcuxClPkc_GenerateUPTRT with flow protection. */
#define MCUXCLPKC_FP_GENERATEUPTRT(pUPTRT, pBaseBuffer, bufferSize, noOfBuffer)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_GenerateUPTRT(pUPTRT, pBaseBuffer, bufferSize, noOfBuffer))

/**
 * @brief Randomize UPTR table
 *
 * This function randomly permutes offsets stored in UPTR table.
 * It randomizes the buffer allocation (physical address in PKC workarea).
 *
 * @param[in,out] pUPTRT      pointer to the first element to be randomized in UPTR table.
 * @param         noOfBuffer  number of elements to be randomized.
 *
 * @pre
 *  - @p pUPTRT shall be 2-byte aligned.
 *  - This function uses PRNG which has to be initialized and ready prior to calling the function.
 *  - When calling this function, there shall be no on-going and pending PKC calculations
 *    using the specified UPTR table elements.
 *
 * @post
 *  - Only the buffer allocation will be randomized, existing operands stored in each buffer will not be moved accordingly.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_RandomizeUPTRT)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_RandomizeUPTRT(
    uint16_t *pUPTRT,
    uint8_t noOfBuffer
    );

/**
 * @brief Randomize UPTR table and operands in PKC workarea.
 *
 * This function randomly permutes offsets stored in UPTR table, together with operands stored in each buffer in PKC workarea.
 * It randomizes the buffer allocation (physical address in PKC workarea) and moves operands stored accordingly.
 *
 * @param[in,out] pUPTRT        pointer to the first element to be randomized in UPTR table.
 * @param         bufferLength  byte length of each buffer in PKC workarea.
 * @param         noOfBuffer    number of elements to be randomized.
 *
 * @pre
 *  - @p pUPTRT shall be 2-byte aligned.
 *    All offsets (pUPTRT[0~(noOfBuffer-1)]) shall be exactly a multiple of MCUXCLPKC_WORDSIZE.
 *  - @p bufferLength shall be a multiple of MCUXCLPKC_WORDSIZE.
 *  - This function uses PRNG which has to be initialized and ready prior to calling the function.
 *  - When calling this function, there shall be no on-going and pending PKC calculations
 *    using the specified UPTR table elements.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_ReRandomizeUPTRT)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_ReRandomizeUPTRT(
    uint16_t *pUPTRT,
    uint16_t bufferLength,
    uint8_t noOfBuffer
    );

/**
 * @}
 */ /* mcuxClPkc_Functions_UPTRT */


/**********************************************************/
/* PKC calculation                                        */
/**********************************************************/
/**
 * @addtogroup mcuxClPkc_Functions_Calculation
 * mcuxClPkc functions of PKC calculation
 * @{
 */

/**
 * @brief Start a PKC calculation
 *
 * This function performs one specified PKC calculation, of which the operand(s) and result are specified by the indices of UPTR table.
 *
 * @param     param_mode   param (the higher 8 bits) indicates the type of the calculation (L0 or L1) and the parameter set (PS1 or PS2).
 *                         mode (the lower 8 bits) indicates the calculation, either an L0 operation or L1 microcode.
 * @param[in] iR_iX_iY_iZ  indices of the operand(s) and the result in UPTR table.
 *
 * @post
 *  - The PKC calculation might be still on-going when returning to caller, call #MCUXCLPKC_WAITFORFINISH
 *    before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_Calc)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_Calc(
    uint16_t param_mode,
    uint32_t iR_iX_iY_iZ
    );

/**
 * @brief Start a PKC calculation with one constant parameter
 *
 * This function performs one specified PKC calculation, of which the operand(s) and result are specified by the indices of UPTR table,
 * and a 8-bit constant parameter is directly provided.
 * This function can also be used to perform an L0 operation without using Z operand, e.g., OP_MUL, R = X0 * Y.
 *
 * @param     param_mode  param (the higher 8 bits) indicates the type of the calculation (always L0) and the parameter set (PS1 or PS2).
                          mode (the lower 8 bits) indicates the calculation, an L0 operation.
 * @param[in] iR_iX_iY_C  indices of the operand(s) and the result in UPTR table, and a direct 8-bit constant.
 *
 * @post
 *  - The PKC calculation might be still on-going when returning to caller, call #MCUXCLPKC_WAITFORFINISH
 *    before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_CalcConst)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_CalcConst(
    uint16_t param_mode,
    uint32_t iR_iX_iY_C
    );

/** @brief type of FUP program address. */
typedef const struct mcuxClPkc_FUPEntry * mcuxClPkc_PtrFUPEntry_t;

/**
 * @brief Start a PKC FUP program calculation
 *
 * This function triggers PKC to start the calculation of a FUP program.
 *
 * @param[in] pUPTR    2-byte aligned address of the FUP program.
 * @param     uLength  length (number of calculation) of the FUP program.
 *
 * @post
 *  - The PKC calculation might be still on-going when returning to caller, call #MCUXCLPKC_WAITFORFINISH
 *    before CPU accesses to the result.
 *
 * @return void
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClPkc_CalcFup)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClPkc_CalcFup(
    mcuxClPkc_PtrFUPEntry_t pUPTR,
    uint8_t uLength
    );
/** Helper macro to call #mcuxClPkc_CalcFup with flow protection. */
#define MCUXCLPKC_FP_CALCFUP(pUPTR, ulen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_CalcFup(pUPTR, ulen))

/** Helper macro to call #mcuxClPkc_CalcFup (skipping first skipLen calculation(s)) with flow protection. */
#define MCUXCLPKC_FP_CALCFUP_OFFSET(pUPTR, skipLen, ulen)  \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClPkc_CalcFup(&((mcuxClPkc_PtrFUPEntry_t) (pUPTR))[(skipLen)], ulen))

/**
 * @}
 */ /* mcuxClPkc_Functions_Calculation */

/**
 * @}
 */ /* mcuxClPkc_Internal_Functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLPKC_INTERNAL_FUNCTIONS_H_ */
