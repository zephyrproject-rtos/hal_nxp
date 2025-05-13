/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    SchM_Eth_43_NETC.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifndef SCHM_ETH_43_NETC_H
#define SCHM_ETH_43_NETC_H

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
#define SCHM_ETH_43_NETC_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_ETH_43_NETC_AR_RELEASE_MINOR_VERSION     7
#define SCHM_ETH_43_NETC_AR_RELEASE_REVISION_VERSION  0
#define SCHM_ETH_43_NETC_SW_MAJOR_VERSION             2
#define SCHM_ETH_43_NETC_SW_MINOR_VERSION             0
#define SCHM_ETH_43_NETC_SW_PATCH_VERSION             1

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
void SchM_Check_eth_43_netc(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_20(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_21(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_21(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_22(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_22(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_23(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_23(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_24(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_24(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_26(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_26(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_28(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_28(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_29(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_29(void);

extern void SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_30(void);
extern void SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_30(void);


/**
* @brief         The function checks for controller errors and lost frames. Used for polling state
*                changes. Calls EthIf_CtrlModeIndication when the controller mode changed.
* @api
* @violates @ref Eth_c_REF_3 For API functions (Eth.c): These functions represent the API of the driver. External linkage is needed to "export" the API.
* @implements    Eth_MainFunction_Activity
*/
extern void Eth_43_NETC_MainFunction(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_ETH_43_NETC_H */
