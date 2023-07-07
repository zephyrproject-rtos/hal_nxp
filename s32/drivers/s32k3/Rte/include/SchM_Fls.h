/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    SchM_Fls.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifndef SCHM_FLS_H
#define SCHM_FLS_H

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
#define SCHM_FLS_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_FLS_AR_RELEASE_MINOR_VERSION     7
#define SCHM_FLS_AR_RELEASE_REVISION_VERSION  0
#define SCHM_FLS_SW_MAJOR_VERSION             3
#define SCHM_FLS_SW_MINOR_VERSION             0
#define SCHM_FLS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define NUMBER_OF_CORES         (uint8)(4U)

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
void SchM_Check_fls(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_14(void);


void Fls_MainFunction(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_FLS_H */
