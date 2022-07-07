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

/** @file  mcuxClHash.h
 *  @brief Top-level include file for the @ref mcuxClHash component
 *
 *  This includes headers for all of the functionality provided by the @ref mcuxClHash component.
 *
 *  @defgroup mcuxClHash mcuxClHash
 *  @brief Hash component
 *
 *  The mcuxClHash component implements the Hash functionality supported by CLNS.
 *  It supports SHA-2 algorithms based on NIST FIPS PUB 180-4.
 *
 *  An example of how to use the @ref mcuxClHash component can be found in /mcuxClHash/ex.
 *
 *  The component uses the CSS hardware. The CSS hardware has to be initialized, prior to
 *  calling any function of the @ref mcuxClHash component.
 *
 *  The @ref mcuxClHash component supports interfaces to either hash a message in one shot
 *  (mcuxClHash_compute) or to hash it in parts (mcuxClHash_init, mcuxClHash_update,
 *  and mcuxClHash_finish). In case of hashing a message in parts, first an initialization
 *  has to be performed (mcuxClHash_init), followed by zero, one or multiple updates
 *  (mcuxClHash_update), followed by a finalization (mcuxClHash_finish). The finalization
 *  generates the output data (digest) and destroys the context. After the finalization step,
 *  no further updates are possible.
 *
 *  The targeted hash algorithm is selected by passing one of the offered algorithm mode
 *  descriptors (@ref mcuxClHash_Modes), which are listed in file mcuxClHash_Constants.h
 *
 * */

#ifndef MCUXCLHASH_H_
#define MCUXCLHASH_H_

#include <mcuxClHash_MemoryConsumption.h>
#include <mcuxClHash_Types.h>
#include <mcuxClHash_Functions.h>
#include <mcuxClHash_Constants.h>

#endif /* MCUXCLHASH_H_ */
