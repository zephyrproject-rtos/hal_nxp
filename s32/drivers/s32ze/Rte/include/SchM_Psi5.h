/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    SchM_Psi5.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifndef SCHM_PSI5_H
#define SCHM_PSI5_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_PSI5_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_PSI5_AR_RELEASE_MINOR_VERSION     7
#define SCHM_PSI5_AR_RELEASE_REVISION_VERSION  0
#define SCHM_PSI5_SW_MAJOR_VERSION             2
#define SCHM_PSI5_SW_MINOR_VERSION             0
#define SCHM_PSI5_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define NUMBER_OF_CORES         (uint8)(14U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_TESTING_ENVIRONMENT
/**
@brief   This function checks that all entered exclusive areas were also exited.
@details This function checks that all entered exclusive areas were also exited. The check
         is done by verifying that all reentry_guard_* static variables are back to the
         zero value.

@param[in]     void       No input parameters
@return        void       This function does not return a value. Test asserts are used instead.

@pre  None
@post None

@remarks Covers
@remarks Implements
*/
void SchM_Check_psi5(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_05(void);




#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_PSI5_H */
