/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file OsIf_TrustedFunctions.h
*   @version 0.8.0
*
*   @brief   BaseNXP - Driver header file.
*   @details Specific driver header file.
*
*   @addtogroup osif_drv
*   @{
*/

#ifndef OSIF_TRUSTEDFUNCTIONS_H
#define OSIF_TRUSTEDFUNCTIONS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define OSIF_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     9
#define OSIF_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define OSIF_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             0
#define OSIF_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             8
#define OSIF_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if OsIf_TrustedFunctions.h file and OsIf_Cfg.h file are of the same vendor */
#if (OSIF_TRUSTEDFUNCTIONS_VENDOR_ID != OSIF_CFG_VENDOR_ID)
    #error "OsIf_TrustedFunctions.h and OsIf_Cfg.h have different vendor ids"
#endif
/* Check if OsIf_TrustedFunctions.h file and OsIf_Cfg.h file are of the same Autosar version */
#if ((OSIF_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_TrustedFunctions.h and OsIf_Cfg.h are different"
#endif
/* Check if OsIf_TrustedFunctions.h file and OsIf_Cfg.h file are of the same Software version */
#if ((OSIF_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_TrustedFunctions.h and OsIf_Cfg.h are different"
#endif

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
 * @brief Get physical core id
 *
 * This function gets physical core id.
 *
 * @param[in] void
 * @return the physical core id
 */
#ifdef OSIF_GET_PHYSICAL_CORE_ID_ENABLE
#if (OSIF_GET_PHYSICAL_CORE_ID_ENABLE == STD_ON)
uint8 OsIf_GetPhysicalCoreIdPrivileged(void);
#endif /* #ifdef OSIF_GET_PHYSICAL_CORE_ID_ENABLE */
#endif /* #if (OSIF_GET_PHYSICAL_CORE_ID_ENABLE == STD_ON) */
/*!
 * @brief Initialize SysTick timer
 *
 * This function initializes SysTick timer
 *
 * @param[in] SystemCounterFreq     Systick's frequency
 * @return void
 */
extern void OsIf_Timer_System_Internal_Init(uint32 SystemCounterFreq);

/*!
 * @brief Get current counter value of SysTick timer
 *
 * This function gets current counter value of SysTick timer
 *
 * @param[in] void
 * @return current counter value
 */
extern uint32 OsIf_Timer_System_Internal_GetCounter(void);

/*!
 * @brief Get elapsed time
 *
 * This function gets elapsed time.
 * NOTE: When CVR register return the value greater than the previous reading value then overflow detected.
 * We can calculate ElapsedTime = MAX_COUNTER_VALUE - CurrentCounterValue + PreviousCounterValue.
 *
 * @param[in] CurrentRef - pointer to old counter value
 * @return elapsed time
 */
extern uint32 OsIf_Timer_System_Internal_GetElapsed(uint32 * const CurrentRef);

#if (defined(USING_OS_ZEPHYR) || defined(USING_OS_FREERTOS))
/*!
 * @brief Resume all interrupts.
 *
 * This function resume all interrupts.
 */
extern void OsIf_Interrupts_ResumeAllInterrupts(void);

/*!
 * @brief Suspend all interrupts.
 *
 * This function suspend all interrupts.
 */
extern void OsIf_Interrupts_SuspendAllInterrupts(void);
#endif /* defined(USING_OS_ZEPHYR) || defined(USING_OS_FREERTOS) */

#if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH32) || (MCAL_PLATFORM_ARM  == MCAL_ARM_RARCH)
extern void Sys_EL1SuspendInterrupts(void);
extern void Sys_EL1ResumeInterrupts(void);
#endif

#if !defined(USING_OS_AUTOSAROS)
extern uint8 Sys_GetCoreID(void);
#endif /* !defined(USING_OS_AUTOSAROS) */

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* OSIF_TRUSTEDFUNCTIONS_H */

/** @} */

