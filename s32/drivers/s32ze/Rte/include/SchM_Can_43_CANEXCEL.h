/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SCHM_CAN_43_CANEXCEL_H
#define SCHM_CAN_43_CANEXCEL_H

/**
*   @file
*
*   @addtogroup RTE_MODULE
*   @{
*/

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
#define SCHM_CAN_43_CANEXCEL_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_CAN_43_CANEXCEL_AR_RELEASE_MINOR_VERSION     7
#define SCHM_CAN_43_CANEXCEL_AR_RELEASE_REVISION_VERSION  0
#define SCHM_CAN_43_CANEXCEL_SW_MAJOR_VERSION             0
#define SCHM_CAN_43_CANEXCEL_SW_MINOR_VERSION             9
#define SCHM_CAN_43_CANEXCEL_SW_PATCH_VERSION             0

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
void SchM_Check_can_43_CANEXCEL(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_20(void);


void Can_43_CANEXCEL_MainFunction_Write(void);
void Can_43_CANEXCEL_MainFunction_Write_0(void);
void Can_43_CANEXCEL_MainFunction_Write_1(void);
void Can_43_CANEXCEL_MainFunction_Write_2(void);
void Can_43_CANEXCEL_MainFunction_Write_3(void);
void Can_43_CANEXCEL_MainFunction_Write_4(void);
void Can_43_CANEXCEL_MainFunction_Write_5(void);
void Can_43_CANEXCEL_MainFunction_Write_6(void);
void Can_43_CANEXCEL_MainFunction_Write_7(void);
void Can_43_CANEXCEL_MainFunction_Write_8(void);
void Can_43_CANEXCEL_MainFunction_Write_9(void);
void Can_43_CANEXCEL_MainFunction_Write_10(void);
void Can_43_CANEXCEL_MainFunction_Read(void);
void Can_43_CANEXCEL_MainFunction_Read_0(void);
void Can_43_CANEXCEL_MainFunction_Read_1(void);
void Can_43_CANEXCEL_MainFunction_Read_2(void);
void Can_43_CANEXCEL_MainFunction_Read_3(void);
void Can_43_CANEXCEL_MainFunction_Read_4(void);
void Can_43_CANEXCEL_MainFunction_Read_5(void);
void Can_43_CANEXCEL_MainFunction_Read_6(void);
void Can_43_CANEXCEL_MainFunction_Read_7(void);
void Can_43_CANEXCEL_MainFunction_Read_8(void);
void Can_43_CANEXCEL_MainFunction_Read_9(void);
void Can_43_CANEXCEL_MainFunction_Read_10(void);
void Can_43_CANEXCEL_MainFunction_BusOff(void);
void Can_43_CANEXCEL_MainFunction_Wakeup(void);
void Can_43_CANEXCEL_MainFunction_Mode(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_CAN_43_CANEXCEL_H */
