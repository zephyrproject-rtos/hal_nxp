/*
 * Copyright 2021-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_RNG_H_
#define FSL_RNG_H_

#include "PN76_Rng.h"
#include "fsl_common.h"

/*!
 * @addtogroup rng
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_rng"
#endif

/*! @brief RNG driver version 2.1.0. */
#define FSL_RNG_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))

/* For backward compatibility. */
#define GenerateSecureRng  RNG_GenerateSecureRng
#define GenerateRng        RNG_GenerateRng
#define GeneratePrng       RNG_GeneratePrng
#define GenerateSecurePrng RNG_GenerateSecurePrng

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief This function initializes random number generator.
 */
static inline void RNG_Init(void)
{
    PN76_Sys_Hal_RNG_Init();
}

/*!
 * @brief    This function generates CHI SQUARE tested random numbers in the passed buffer.
 *
 * @param *pBuffer : Pointer to generated random number data message structure.
 * @param dwDataLength : Length of \a pBuffer in bytes.
 *
 * @retval kStatus_Success on successful RNG Generation
 * @retval kStatus_InvalidArgument error code due to wrong parameter
 * @note  Value of RNG is 8-bit, but it is placed in 32-bit register.
 * @note  This function will first enable RNG, calculate RNG and then disable RNG.
 */
static inline status_t RNG_GenerateSecureRng(uint8_t *pBuffer, uint32_t dwDataLength)
{
    return (PN76_Sys_Hal_RNG_GenerateSecureRng(pBuffer, dwDataLength) == PN76_STATUS_SUCCESS) ? kStatus_Success :
                                                                                                kStatus_InvalidArgument;
}

/*!
 * @brief    This function generates random numbers buffer.
 *
 * @param *pBuffer : Pointer to generated random number data message structure.
 * @param dwDataLength :  Length of data message structure in bytes
 *
 * @retval kStatus_Success on successful RNG Generation
 * @retval kStatus_InvalidArgument Parameter error
 * @note  Once started RNG will be enabled all the time and will continuously generate random numbers.
 * @note  Value of RNG is 8-bit, but it is placed in 32-bit register.
 */
static inline status_t RNG_GenerateRng(uint8_t *pBuffer, uint32_t dwDataLength)
{
    return (PN76_Sys_Hal_RNG_GenerateRng(pBuffer, dwDataLength) == PN76_STATUS_SUCCESS) ? kStatus_Success :
                                                                                          kStatus_InvalidArgument;
}

/*!
 * @brief    This function generates random numbers buffer.
 *
 * @param *pBuf : Pointer to generated random number data message structure.
 * @param dwLen : Length of data message structure in bytes.
 *
 * @retval kStatus_Success on successful PRNG Generation
 * @retval kStatus_InvalidArgument Parameter error
 * @note  This function is generic and not dependent on any RTOS
 * @note  Once started RNG will be enabled all the time and will continuously generate random numbers
 */
static inline status_t RNG_GeneratePrng(uint8_t *pBuf, uint32_t dwLen)
{
    return (PN76_Sys_Hal_RNG_GeneratePrng(pBuf, dwLen) == PN76_STATUS_SUCCESS) ? kStatus_Success :
                                                                                 kStatus_InvalidArgument;
}

/*!
 * @brief    This function generates CHI SQUARE tested random numbers in the passed buffer.
 *
 * @param *pbiRngBuffer  : Pointer to generated random number data message structure
 * @param dRNrLength : Length of data message structure in bytes
 *
 * @retval kStatus_Success on successful Secure PRNG generated.
 * @retval kStatus_InvalidArgument Parameter error
 * @note  This function is generic and not dependent on any RTOS
 * @note  This function will first enable RNG, calculate RNG and then disable RNG
 */
static inline status_t RNG_GenerateSecurePrng(uint8_t *pbiRngBuffer, uint32_t dRNrLength)
{
    return (PN76_Sys_Hal_RNG_GenerateSecurePrng(pbiRngBuffer, dRNrLength) == PN76_STATUS_SUCCESS) ?
               kStatus_Success :
               kStatus_InvalidArgument;
}

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FSL_RNG_H_ */