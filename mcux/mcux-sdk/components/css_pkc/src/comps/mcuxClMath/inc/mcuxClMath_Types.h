/*--------------------------------------------------------------------------*/
/* Copyright 2020-2021 NXP                                                  */
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

/**
 * @file  mcuxClMac_Types.h
 * @brief Type definitions for the mcuxClMac component
 */


#ifndef MCUXCLMATH_TYPES_H_
#define MCUXCLMATH_TYPES_H_

#include <stdint.h>


/**********************************************
 * CONSTANTS
 **********************************************/
/* None */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @defgroup mcuxClMath_Macros mcuxClMath_Macros
 * @brief Defines all macros of @ref mcuxClMath
 * @ingroup mcuxClMath
 * @{
 */

/**
 * @brief Type for error codes used by Math component functions.
 */
typedef uint32_t mcuxClMath_Status_t;

/**
 * @brief Type for error codes used by code-flow protected Math component functions.
 */
typedef uint64_t mcuxClMath_Status_Protected_t;

#define MCUXCLMATH_ERRORCODE_OK    ((mcuxClMath_Status_t) 0x17171717u) ///< Math operation successful
#define MCUXCLMATH_ERRORCODE_ERROR ((mcuxClMath_Status_t) 0x17177171u) ///< Error occurred during Math operation

/**
 * @}
 */ /* mcuxClMath_Macros */


#endif /* MCUXCLMATH_TYPES_H_ */
