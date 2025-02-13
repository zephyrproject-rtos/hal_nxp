/*
 * Copyright 2021-2025 NXP
*
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef HSE_IP_CFG_H
#define HSE_IP_CFG_H

/**
*   @file
*
*   @addtogroup CRYPTO_43_HSE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32Z2_MU.h"
#include "OsIf.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HSE_IP_CFG_VENDOR_ID_H                      43
#define HSE_IP_CFG_SW_MAJOR_VERSION_H               2
#define HSE_IP_CFG_SW_MINOR_VERSION_H               0
#define HSE_IP_CFG_SW_PATCH_VERSION_H               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Defines for the available MU instances */
#define HSE_IP_MU_0                          ((uint8)0U)
#define HSE_IP_MU_1                          ((uint8)1U)
#define HSE_IP_MU_2                          ((uint8)2U)
#define HSE_IP_MU_3                          ((uint8)3U)
#define HSE_IP_MU_4                          ((uint8)4U)
#define HSE_IP_MU_5                          ((uint8)5U)
#define HSE_IP_MU_6                          ((uint8)6U)
#define HSE_IP_MU_7                          ((uint8)7U)

/* Max number of MU instances */
#define HSE_IP_NUM_OF_MU_INSTANCES               (8U)

/* Max number of channels per MU interface */
#define HSE_IP_NUM_OF_CHANNELS_PER_MU            (16U)

/* Pre-processor switch to enable/disable development error detection for Hse Ip API */
#define HSE_IP_DEV_ERROR_DETECT                  (STD_OFF)

/* OsIf counter type used in timeout detection for HSE IP service request */
#define HSE_IP_TIMEOUT_OSIF_COUNTER_TYPE         (OSIF_COUNTER_DUMMY)

/* Support for Hse operations using TCM addresses */
#define HSE_IP_ENABLE_TCM_SUPPORT                       (STD_OFF)

/* Initializer for the MU Host base addresses */
#define MU_HOST_BASE_PTRS                        { IP_MU0__MUB, IP_MU1__MUB, IP_MU2__MUB, IP_MU3__MUB, IP_MU4__MUB, IP_MU5__MUB, IP_MU6__MUB, IP_MU7__MUB }

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HSE_IP_CFG_H */

