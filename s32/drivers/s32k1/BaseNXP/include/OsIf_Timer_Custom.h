/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef OSIF_TIMER_CUSTOM_H
#define OSIF_TIMER_CUSTOM_H

/**
*   @file
*
*   @addtogroup osif_drv
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
#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_TIMER_CUSTOM_VENDOR_ID                    43
#define OSIF_TIMER_CUSTOM_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_TIMER_CUSTOM_AR_RELEASE_MINOR_VERSION     7
#define OSIF_TIMER_CUSTOM_AR_RELEASE_REVISION_VERSION  0
#define OSIF_TIMER_CUSTOM_SW_MAJOR_VERSION             2
#define OSIF_TIMER_CUSTOM_SW_MINOR_VERSION             0
#define OSIF_TIMER_CUSTOM_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against StandardTypes.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_TIMER_CUSTOM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_TIMER_CUSTOM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Timer_Custom.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

/*!
 * @brief Initialize the custom timer.
 *
 * This function initialize the custom timer.
 */
void OsIf_Timer_Custom_Init(void);

/*!
 * @brief Get counter value from custom timer.
 *
 * This function get counter value from custom timer.
 *
 * @return Counter value
 */
uint32 OsIf_Timer_Custom_GetCounter(void);

/*!
 * @brief Get elapsed value from custom timer.
 *
 * This function get elapsed value from custom timer.
 *
 * @param[in] CurrentRef The pointer to current reference point
 * @return Elapsed value
 */
uint32 OsIf_Timer_Custom_GetElapsed(uint32 * const CurrentRef);

/*!
 * @brief Set custom timer frequency.
 *
 * This function set custom timer frequency.
 *
 * @param[in] Freq Frequency value
 */
void OsIf_Timer_Custom_SetTimerFrequency(uint32 Freq);

/*!
 * @brief Convert micro second to ticks based on custom timer frequency.
 *
 * This function Convert micro second to ticks based on custom timer frequency.
 *
 * @param[in] Micros Micro second
 * @return Ticks
 */
uint32 OsIf_Timer_Custom_MicrosToTicks(uint32 Micros);

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OSIF_TIMER_CUSTOM_H */
