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

/** @file  mcuxClMemory_Types.h
 *  @brief Memory type header.
 * This header exposes types used by the @ref mcuxClMemory functions. */

/**
 * @defgroup mcuxClMemory_Types mcuxClMemory_Types
 * @brief Defines all types used by the @ref mcuxClMemory functions.
 * @ingroup mcuxClMemory
 * @{
 */

#ifndef MCUXCLMEMORY_TYPES_H
#define MCUXCLMEMORY_TYPES_H

#include <stdint.h>
#include <stddef.h>

/**********************************************
 * MACROS
 **********************************************/
/**
 * @defgroup mcuxClMemory_Types_Macros mcuxClMemory_Types_Macros
 * @brief Defines all macros of @ref mcuxClMemory_Types
 * @ingroup mcuxClMemory_Types
 * @{
 */
#define MCUXCLMEMORY_API extern  ///< Marks a function as a public API function of the mcuxClMemory component

/**
 * @defgroup MCUXCLMEMORY_STATUS_ MCUXCLMEMORY_STATUS_
 * @brief Defines valid mcuxClMemory function return codes
 * @ingroup mcuxClMemory_Types_Macros
 * @{
 */

#define MCUXCLMEMORY_STATUS_OK ((mcuxClMemory_Status_t) 0x9C9C9C9Cu) ///< Memory operation successful

/**
 * @}
 */

#define MCUXCLMEMORY_ERRORCODE_OK MCUXCLMEMORY_STATUS_OK ///< Memory operation successful
                                                       ///< @deprecated Please use #MCUXCLMEMORY_STATUS_OK instead

/**
 * @}
 */

/**********************************************
 * TYPEDEFS
 **********************************************/
/**
 * @brief Type for error codes of mcuxClMemory component functions.
 * 
 * Type returned by mcuxClMemory functions. See @ref MCUXCLMEMORY_STATUS_ for possible options.
 */
typedef uint32_t mcuxClMemory_Status_t;

/**
 * @brief Type for error codes used by code-flow protected mcuxClMemory component functions.
 * 
 * 
 */
typedef MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClMemory_Status_t) mcuxClMemory_Status_Protected_t;

#endif /* #MCUXCLMEMORY_TYPES_H */

/**
 * @}
 */
