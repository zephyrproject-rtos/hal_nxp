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

/** @file  mcuxClSession_Types.h
 *  @brief Type definitions for the mcuxClSession component */

#ifndef MCUXCLSESSION_TYPES_H_
#define MCUXCLSESSION_TYPES_H_

#include <stdint.h>
#include <stdbool.h>

/**********************************************
 * CONSTANTS
 **********************************************/
/**
 * @defgroup mcuxClSession_Constants mcuxClSession_Constants
 * @brief Defines all constants of @ref mcuxClSession
 * @ingroup mcuxClSession
 * @{
 */

/**
 * \defgroup mcuxClSessionStatusValues  Session Status values
 * @{
 */
#define MCUXCLSESSION_STATUS_OK          ((mcuxClSession_Status_t) 0xE8E8E8E8u )  ///< Session operation successful
#define MCUXCLSESSION_STATUS_ERROR       ((mcuxClSession_Status_t) 0xE8E88E8Eu )  ///< Error occured during Session operation
/**@}*/

/**
 * \defgroup mcuxClSessionRtfValues  Session RTF configuration values
 * @{
 */
#define MCUXCLSESSION_RTF_UPDATE_TRUE    ((mcuxClSession_Rtf_t) 0xF0F00F0Fu )     ///< RTF will be updated
#define MCUXCLSESSION_RTF_UPDATE_FALSE   ((mcuxClSession_Rtf_t) 0x0F0F0F0Fu )     ///< RTF will not be updated
/**@}*/

/**
 * @}
 */ /* mcuxClSession_Constants */


/**********************************************
 * TYPEDEFS
 **********************************************/
/**
* @defgroup mcuxClSession_Types mcuxClSession_Types
 * @brief Defines all types of @ref mcuxClSession
 * @ingroup mcuxClSession
* @{
*/

/**
 * @brief Type for mcuxClSession status codes
 */
typedef uint32_t mcuxClSession_Status_t;

/**
 * @brief Type for mcuxClSession protected status codes
 */
typedef uint64_t mcuxClSession_Status_Protected_t;

/**
 * @brief Type for mcuxClSession RTF configuration flags
 */
typedef uint32_t mcuxClSession_Rtf_t;

/**
 * @brief Type for mcuxClSession workareas flags
 */
typedef struct mcuxClSession_WorkArea
{
  uint32_t * buffer;            ///< Pointer to the starting address of the workarea buffer
  uint32_t size;                ///< Size of the workarea buffer in words (uint32_t)
  uint32_t used;                ///< Used portion of the workarea buffer in words (uint32_t)
} mcuxClSession_WorkArea_t;

/**
 * @brief Type for mcuxClSession security context
 */
typedef struct mcuxClSession_SecurityContext
{
  uint32_t securityCounter;     ///< Security counter
} mcuxClSession_SecurityContext_t;

/**
 * @brief Type for mcuxClSession Descriptor
 */
typedef struct mcuxClSession_Descriptor
{
  mcuxClSession_WorkArea_t cpuWa;    ///< Workarea for the CPU
  mcuxClSession_WorkArea_t pkcWa;    ///< Workarea for the PKC
  mcuxClSession_Rtf_t rtf;           ///< Configuration of the RTF
  /* TBD: DMA handling */
} mcuxClSession_Descriptor_t;
/**
 * @brief Type for mcuxClSession Handle
 */
typedef mcuxClSession_Descriptor_t * const mcuxClSession_Handle_t;

/**
 * @}
 */ /* mcuxClSession_Types */

#endif /* MCUXCLSESSION_TYPES_H_ */
