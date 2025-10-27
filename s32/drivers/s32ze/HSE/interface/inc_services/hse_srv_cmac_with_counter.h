/**
 *   @file    hse_srv_cmac_with_counter.h
 *
 *   @brief   CMAC with counter service definition.
 *   @details This file contains the definition of the CMAC-With-Counter service.
 *
 *   @addtogroup hse_srv_cmac_with_counter HSE CMAC With Counter Service
 *   @ingroup class_crypto_services
 *
 *   @note    For HSE_B (devices with internal flash), the first service request after reset that depends on Monotonic Counters,
 *            i.e., #hseConfigSecCounterSrv_t, #hseReadCounterSrv_t, #hseIncrementCounterSrv_t and #hseCmacWithCounterSrv_t
 *            will take more time because of Monotonic Counters Initialization. Further requests will take usual time.
 *   @{
 */

/*==================================================================================================
 *   Copyright 2019 - 2024 NXP
 *
 *   Redistribution and use in source and binary forms, with or without modification,
 *   are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list
 *      of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this
 *      list of conditions and the following disclaimer in the documentation and/or
 *      other materials provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its
 *      contributors may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 *   This software is owned or controlled by NXP and may only be used strictly in accordance with
 *   the applicable license terms. By expressly accepting such terms or by downloading, installing,
 *   activating and/or otherwise using the software, you are agreeing that you have read, and that
 *   you agree to comply with and are bound by, such license terms. If you do not agree to
 *   be bound by the applicable license terms, then you may not retain, install, activate or
 *   otherwise use the software.
 * ==================================================================================================*/

/*==================================================================================================
 * ==================================================================================================*/

#ifndef HSE_SRV_CMAC_WITH_COUNTER_H
#define HSE_SRV_CMAC_WITH_COUNTER_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * ==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 * ==================================================================================================*/

/*==================================================================================================
 *                                     FILE VERSION CHECKS
 * ==================================================================================================*/

/*==================================================================================================
 *                                          CONSTANTS
 * ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 * ==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
 * ==================================================================================================*/

/*==================================================================================================
 *                               STRUCTURES AND OTHER TYPEDEFS
 * ==================================================================================================*/

/**
 * @brief          CMAC With Counter service.
 * @details        This service calculates/verifies the CMAC of a given input message concatenated with a selected secure counter.
 *                 @note
 *                 - The secure counter must be configured before (refer to #hseConfigSecCounterSrv_t)
 *                 - Bits are represented from left to right at byte level.
 *                 - In the description below, the following notation is used:
 *                     - SC - 64bit secure counter
 *                     - RP - The Rollover Protection bits of the secure counter (refer to #hseConfigSecCounterSrv_t)
 *                     - VC - The Volatile Counter bits of the secure counter (refer to #hseConfigSecCounterSrv_t)
 *                     - SC_counterIdx is the secure counter identified by the counterIdx (counter index)
 *                     - VC_counterIdx is the volatile part of the secure counter (volatile counter) identified by the counterIdx
 *                     - RP_counterIdx is the Rollover Protection value of the secure counter identified by the counterIdx (the volatile counter bits are all zeros)
 *                     - "||" means concatenation
 *                     - VCI is the Volatile Counter provide as input parameter by the service (#pVolatileCounter parameter)
 *                     - RPO is the Rollover Protection Offset (#RPOffset parameter for CMAC verify) added to Rollover Protection value to adjust the RP bits.
 *                     - ISC - the implied value of the SC computed by HSE concatenating the optionally adjusted RP bits with the VCI bits
 *                       (refer to CMAC verify sequence below)
 *
 *                 For CMAC generate, the HSE firmware performs the following sequence: <br>
 *                     \code
 *                     SC_counterIdx = SC_counterIdx + 1
 *                     TAG = CMAC_GENERATE(KeyHandle, input || SC_counterIdx)
 *                     VC_counterIdx = SC_counterIdx - RP_counterIdx
 *                     if(VC_counterIdx == 0) then update RP_counterIdx in NVM
 *                     return  TAG, VC_counterIdx & RSP_STATUS_OK
 *                     \endcode
 *
 *                 For CMAC verify, the HSE firmware performs the following sequence: <br>
 *                      \code
 *                      if(VCI > VC_counterIdx) then ISC = (RP_counterIdx + RPO) || VCI
 *                      if(VCI <= VC_counterIdx) then ISC = (RP_counterIdx + 1 + RPO) || VCI
 *                      if(CMAC_VERIFY(KEY_HANDLE, input || ISC)) then
 *                      {
 *                           SC_counterIdx = ISC
 *                           if((RPO != 0) or (VCI <= VC_counterIdx)) then update RP_counterIdx in NVM
 *                           rsp_status = HSE_SRV_RSP_OK
 *                      }
 *                      else
 *                      {
 *                           rsp_status =  HSE_SRV_RSP_VERIFY_FAILED
 *                      }
 *                      return rsp_status
 *                      \endcode
 */
typedef struct
{
    /** @brief   INPUT: Specifies the direction: generate/verify. */
    hseAuthDir_t   authDir;

    uint8_t        reserved1[3U];

    /** @brief   INPUT: The key to be used for the operation. */
    hseKeyHandle_t keyHandle;

    /** @brief   INPUT: The counter Index of the secure counter */
    uint32_t       counterIdx;

    /** @brief   INPUT: The Rollover protection offset used to adjust the Rollover protection bits of the secure counter in the CMAC verify operation.
     *                  It is ignored for CMAC generate.
     *                  If the CMAC verification fails, the application can try with a different RPOffset. */
    uint8_t        RPOffset;

    /** @brief  INPUT: Specify if pInput is provided as hseScatterList_t list (the host address points to a hseScatterList_t list).
     *                 Ignored if SGT is not supported.
     *                 @note
     *                 - ONLY HSE_SGT_OPTION_INPUT can be used.
     *                 - If scatter option is selected (set), the length (e.g. inputBitLength) shall specified the entire message length
     *                 (sum of all hseScatterList_t lengths in bits).
     *                 - If scatter option is selected, the number of input SGT entries shall be 2. */
    hseSGTOption_t   sgtOption;

    uint8_t        reserved2[2U];

    /** @brief   INPUT: Length of the input message.(in bits) */
    uint32_t       inputBitLength;

    /** @brief   INPUT: The input message. */
    HOST_ADDR      pInput;

    /** @brief   INPUT: Holds tag length in bits.
     *           - CMAC GENERATE:
     *             - On calling service (input), this parameter shall contain the length of the buffer (in bits) provided by #pTag.
     *             - Recommended tag lengths are [32, 128]. Tag-lengths greater than 128 are truncated to 128.
     *           - CMAC VERIFY:
     *             - On calling service (input), this parameter shall contain the bit-length to be verified.
     *             - Recommended tag lengths are [32, 128].
     *             - The #HSE_FAST_CMAC_MIN_TAG_BIT_LEN_ATTR_ID attribute can be used to overwrite
     *               the lower recommended tag bit length limit (minimum is 1). */
    uint8_t        tagBitLength;

    uint8_t        reserved3[3U];

    /** @brief   OUTPUT/INPUT: The output tag for "generate"; the input tag for "verify". */
    HOST_ADDR      pTag;

    /** @brief   OUTPUT/INPUT: The address of the volatile counter.
     *                         HSE reads/writes #HSE_BITS_TO_BYTES(64-RPBitSize) bytes at pVolatileCounter address:
     *           - CMAC GENERATE: Specifies the address where to provide the Volatile Counter (Output parameter).
     *           - CMAC VERIFY: Input parameter that specifies the Volatile Counter to be used for the CMAC verify operation. */
    HOST_ADDR      pVolatileCounter;
}hseCmacWithCounterSrv_t;

/*==================================================================================================
 *                               GLOBAL VARIABLE DECLARATIONS
 * ==================================================================================================*/

/*==================================================================================================
 *                                   FUNCTION PROTOTYPES
 * ==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_CMAC_WITH_COUNTER_H */

/** @} */
