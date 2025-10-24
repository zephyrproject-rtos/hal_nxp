/**
*   @file    hse_srv_self_test.h
*
*   @brief   HSE Self Test service definition.
*   @details This file contains the Self Test service definition.
*
*   @addtogroup hse_srv_self_test HSE Self Test Service
*   @ingroup class_admin_services
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019-2024 NXP
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_SELF_TEST_H
#define HSE_SRV_SELF_TEST_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"
#include "hse_srv_attr.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**<@brief Self-test capabilities mask. */
typedef uint64_t hseSelfTestMask_t;
#define HSE_ST_FW_INTEGRITY         ((hseSelfTestMask_t)(1ULL << 0U))     /**<@brief Verify HSE Firmware Integrity */
#if defined(HSE_SPT_RANDOM)
#define HSE_ST_RNG_ENGINE           ((hseSelfTestMask_t)(1ULL << 1U))     /**<@brief Random Number Generator */
#endif /* defined(HSE_SPT_RANDOM) */
#if defined(HSE_SPT_AES)
#define HSE_ST_AES_ENGINE           ((hseSelfTestMask_t)(1ULL << 2U))     /**<@brief Advanced Encryption Standard Hardware Accelerator */
#endif /* defined(HSE_SPT_AES) */
#if defined(HSE_SPT_HASH)
#define HSE_ST_HASH_ENGINE          ((hseSelfTestMask_t)(1ULL << 3U))     /**<@brief Hash Generator */
#endif /* defined(HSE_SPT_HASH) */
#if defined(HSE_SPT_CRC32)
#define HSE_ST_CRC_ENGINE           ((hseSelfTestMask_t)(1ULL << 4U))     /**<@brief Cyclic-Redundancy Check Hardware Accelerator */
#endif /* defined(HSE_SPT_CRC32) */
#if defined(HSE_SPT_RSA)
#define HSE_ST_RSA_ENGINE           ((hseSelfTestMask_t)(1ULL << 5U))     /**<@brief Rivest-Shamir-Adleman Hardware Accelerator */
#endif /* defined(HSE_SPT_RSA) */
#if defined(HSE_SPT_ECC)
#define HSE_ST_ECC_ENGINE           ((hseSelfTestMask_t)(1ULL << 6U))     /**<@brief Elliptic Curve Cryptography Hardware Accelerator */
#endif /* defined(HSE_SPT_ECC) */
#if defined(HSE_SPT_HMAC)
#define HSE_ST_HMAC_ENGINE          ((hseSelfTestMask_t)(1ULL << 7U))     /**<@brief Hash-Based Message Authentication Code Hardware Accelerator */
#endif /* defined(HSE_SPT_HMAC) */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Self Test service.
 *  @details Performs a self-test on a specific security block or a full self-test.
 *  @note - During the self-test operation, the HSE firmware cannot be interrupted by another request
 *         (until the operation is completed).
 *        - The requested self-tests must be supported; otherwise, the self-test service returns the
 *          #HSE_SRV_RSP_NOT_ALLOWED status (no requested self-tests will be executed).
 *        - If one of the check fails, the HSE firmware returns #HSE_SRV_RSP_GENERAL_ERROR and goes to
 *          shutdown (a fatal error occurred). In this case, the application must perform a system reset.
 *        - The #HSE_ST_FW_INTEGRITY flag checks the integrity of HSE FW and runtime SYS-IMG (if present) inside HSE.
 *        - At first request for #HSE_ST_FW_INTEGRITY the hash over HSE FW will be computed,
 *          verification being done in the subsequent requests. */
typedef struct
{
    /** @brief   INPUT:  Select bits to run a specific self-test.
     *                   (note that the selected bits should map the supported self-tests).
     *                   All bits zero means that a full self-test will be performed. */
    hseSelfTestMask_t    selfTest;
    /** @brief   OUTPUT: The address where the self-tests results bit mask is returned (points to a #hseSelfTestMask_t type).
     *                   If one of the requested self-tests failed, HSE returns #HSE_SRV_RSP_GENERAL_ERROR
     *                   and the corresponding bit for the failing test is set to one.
     *                   If all the self-tests passed, HSE returns #HSE_SRV_RSP_OK and this field can be ignored. */
    HOST_ADDR            pTestResultsBitMask;
} hseSelfTestSrv_t;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_SELF_TEST_H */

/** @} */
