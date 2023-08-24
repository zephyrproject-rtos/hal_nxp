/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    SchM_Mcl.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifndef SCHM_MCL_H
#define SCHM_MCL_H

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
#define SCHM_MCL_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_MCL_AR_RELEASE_MINOR_VERSION     7
#define SCHM_MCL_AR_RELEASE_REVISION_VERSION  0
#define SCHM_MCL_SW_MAJOR_VERSION             3
#define SCHM_MCL_SW_MINOR_VERSION             0
#define SCHM_MCL_SW_PATCH_VERSION             0

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
void SchM_Check_mcl(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_20(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_21(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_21(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_22(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_22(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_23(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_23(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_24(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_24(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_25(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_25(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_26(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_26(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_27(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_27(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_28(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_28(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_29(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_29(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_30(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_30(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_31(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_31(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_32(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_32(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_33(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_33(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_34(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_34(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_35(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_35(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_36(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_36(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_37(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_37(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_38(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_38(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_39(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_39(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_40(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_40(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_41(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_41(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_42(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_42(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_43(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_43(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_44(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_44(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_45(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_45(void);

extern void SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_46(void);
extern void SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_46(void);




#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_MCL_H */
