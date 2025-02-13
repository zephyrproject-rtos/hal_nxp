/*
 * Copyright 2019-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef HSE_SRV_MONOTONIC_CNT_H
#define HSE_SRV_MONOTONIC_CNT_H

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

#if defined(HSE_SPT_FLASHLESS_DEV)
/** @brief  The size of the NVM container for the Monotonic Counter table (in bytes).*/
#define HSE_NVM_CONTAINER_CNT_TBL_SIZE   ((HSE_NUM_OF_MONOTONIC_COUNTERS * sizeof(uint64_t)) + 48U)

/** @brief  Publish or load the NVM container for the Monotonic Counter table. */
typedef uint8_t hseNvmCntTblAction_t;
#define HSE_NVM_CNT_TBL_ACTION_PUBLISH   ((hseNvmCntTblAction_t)0x01U)     /**< @brief  Publish the Nvm Container for the Monotonic Counter table. */
#define HSE_NVM_CNT_TBL_ACTION_LOAD      ((hseNvmCntTblAction_t)0x02U)     /**< @brief  Load the Nvm Container for the Monotonic Counter table. */
#endif /* HSE_SPT_FLASHLESS_DEV */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief Increment a monotonic counter service with a specific value.
 * @details
 *         - For HSE_H/M, the counters are volatile. Host application has to publish/load
 *           the monotonic counter table using hsePublishLoadCntTblSrv_t service.
 *         - For HSE_B, the host application shall use the hseConfigSecCounterSrv_t service
 *           to initialize and configure the secure counters.
 *         - If the counter is saturated, an error is reported. */
typedef struct
{
    /** @brief   INPUT: The counter Index. */
    uint32_t                counterIndex;
    /** @brief   INPUT: The value to be added. */
    uint32_t                value;
}hseIncrementCounterSrv_t;

/** @brief Read a monotonic counter service. */
typedef struct
{
    /** @brief   INPUT: The counter Index. */
    uint32_t                counterIndex;
    /** @brief   OUTPUT: The address where the counter value is returned (a uint64_t value). */
    HOST_ADDR               pCounterVal;
} hseReadCounterSrv_t;


#if defined(HSE_SPT_FLASHLESS_DEV)
/**
 * @brief    Publish or load the monotonic counter table.
 * @details   This is supported only for HSE_H/M devices and should be used to publish/load
 *            the monotonic counter table in NVM
 * */
typedef struct
{
    /** @brief  INPUT:   Publish/load the NVM container for the Monotonic Counter table. */
    hseNvmCntTblAction_t    action;
    uint8_t                 reserved[3];
    /** @brief  OUTPUT:  The address of the NVM container for the Monotonic Counter table.
     *                   The size of the NVM container is #HSE_NVM_CONTAINER_CNT_TBL_SIZE. */
    HOST_ADDR               pNvmContainerCntTbl;
} hsePublishLoadCntTblSrv_t;
#endif /* HSE_SPT_FLASHLESS_DEV */


/**
 * @brief   Initialize and configure a secure counter.
 * @details HSE supports 16 X 64 bits secure counters, each counter having associated a CounterIndex from 0 to 15.
 *          By default, all the counters are disabled.  <br>
 *          The secure counter (SC) consists of 2 separate bitfields: Rollover Protection (RP) + Volatile Counter (VC).
 *          HSE stores the secure counter in data flash each time the Rollover Protection (RP) is updated.  <br>
 *          The purpose of this service is to enable the secure counter and configure the Rollover Protection bitfield size.
 *          The objective is to reduce the rate at which NVM programming operations occur.  <br>
 *          If the secure counter is already configured and this service is called, HSE re-configures the counter
 *          with the new Rollover Protection (RP) and reset it to 0.
 *         @note
 *         - SuperUser rights are needed to configure/enable the monotonic counters.
 *         - For HSE_B (devices with internal flash)
 *              - WARNING: The HSE erases a flash sector after 511 Rollover Protection updates in data flash.  <br>
 *              The number of data flash erases is limited to 100.000. The application shall configure each secure counter
 *              depending on the SC update rate and the number of enabled counters.
 *              - The secure counter configuration is stored in data flash each time hseConfigSecCounterSrv_t is called.
 *              - If RPBitSize = 64bits, the HSE stores the SC in flash each time is updated.
 *         - For HSE_H/M (flashless devices)
 *              - The RPBitSize is configured for all the enabled secure counters. If the RP of a counter is updated, a warning event is trigger
 *                called #HSE_WA_PUBLISH_COUNTER_TBL through MUB_GSR register. The application shall clear the warning bit (W1C) and
 *                use the #hsePublishLoadCntTblSrv_t service to publish and store the counter table in the external flash.
 *                Note that the counter table must be loaded at initialization time by the application (anti-rollback protection is not supported).
 *
 *         Example:
 *         Let's consider the RPBitSize = 40bits and SC = 0x0000000000000001.  <br>
 *         This means Rollover Protection (40bits) + Volatile Counter (24bits).  <br>
 *         The secure counter (SC) will be stored in flash if the incremental value is >= 0xFFFFFF. Otherwise, the counter will be updated but not stored.  <br>
 *         SC = 0x0000000000000001+0xFFFFFF = 0x0000000001000000 (RP was changed)
 */
typedef struct
{
    /** @brief   INPUT: - For HSE_B, specifies the counter Index.
     *                  - For HSE_H/M, specifies the number of counters to be enabled (max 16). E.g. if it is set to 5,
     *                    the counters with the index from 0 to 4 are enabled. */
    uint32_t                counterIndex;
    /** @brief   INPUT: The Rollover Protection bit size (refer to service comments). It shall be >= 32 bits and <= 64 bits. */
    uint8_t                 RPBitSize;
    uint8_t                 reserved[3];
} hseConfigSecCounterSrv_t;




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

#endif /* HSE_SRV_MONOTONIC_CNT_H */

/** @} */
