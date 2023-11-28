/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_HW_ACCESS_H_
#define LCU_IP_HW_ACCESS_H_

/**
*   @file    Lcu_Ip_Hw_Access.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Lcu Ip driver source file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
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
#include "Lcu_Ip.h"
#include "Lcu_Ip_Devassert.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_HW_ACCESS_VENDOR_ID                       43
#define LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_HW_ACCESS_SW_MAJOR_VERSION                3
#define LCU_IP_HW_ACCESS_SW_MINOR_VERSION                0
#define LCU_IP_HW_ACCESS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip.h file are of the same vendor */
#if (LCU_IP_HW_ACCESS_VENDOR_ID != LCU_IP_VENDOR_ID)
    #error "Lcu_Ip_Hw_Access.h and Lcu_Ip.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip.h file are of the same Autosar version */
#if ((LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != LCU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != LCU_IP_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != LCU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Hw_Access.h and Lcu_Ip.h are different"
#endif

/* Check if header file and Lcu_Ip.h file are of the same Software version */
#if ((LCU_IP_HW_ACCESS_SW_MAJOR_VERSION != LCU_IP_SW_MAJOR_VERSION) || \
     (LCU_IP_HW_ACCESS_SW_MINOR_VERSION != LCU_IP_SW_MINOR_VERSION) || \
     (LCU_IP_HW_ACCESS_SW_PATCH_VERSION != LCU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Hw_Access.h and Lcu_Ip.h are different"
#endif

/* Check if header file and Lcu_Ip_Devassert.h file are of the same vendor */
#if (LCU_IP_HW_ACCESS_VENDOR_ID != LCU_IP_DEVASSERT_VENDOR_ID)
    #error "Lcu_Ip_Hw_Access.h and Lcu_Ip_Devassert.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Devassert.h file are of the same Autosar version */
#if ((LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != LCU_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != LCU_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != LCU_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Hw_Access.h and Lcu_Ip_Devassert.h are different"
#endif

/* Check if header file and Lcu_Ip_Devassert.h file are of the same Software version */
#if ((LCU_IP_HW_ACCESS_SW_MAJOR_VERSION != LCU_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (LCU_IP_HW_ACCESS_SW_MINOR_VERSION != LCU_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (LCU_IP_HW_ACCESS_SW_PATCH_VERSION != LCU_IP_DEVASSERT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Hw_Access.h and Lcu_Ip_Devassert.h are different"
#endif

#if (STD_ON == LCU_IP_IS_AVAILABLE)
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
extern LCU_Type * const Lcu_Ip_paxBaseInst[LCU_INSTANCE_COUNT];

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

void HwAcc_Lcu_SetHwOutputSetState(const uint8 LcuId, const uint8 HwLcOutputId, Lcu_Ip_HwOutputStateType * SetState);

/* Input Configuration */
void HwAcc_Lcu_AsyncSetInputMuxSelect(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue);

void HwAcc_Lcu_AsyncSetInputSwOverrideValue(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue);

void HwAcc_Lcu_AsyncSetInputSwSyncMode(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue);

void HwAcc_Lcu_AsyncSetInputSwOverrideEnable(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue);

/* Output Configuration */

boolean HwAcc_Lcu_AsyncSetOutputEnable(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputDebugMode(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputForceInputSensitivity(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputForceClearingMode(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputForceSyncSelect(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputPolarity(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncClearOutputForceEvent(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputForceDma(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputForceInt(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputLutDma(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputLutInt(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputFallFilter(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputRiseFilter(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputLutControl(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);

uint8 HwAcc_Lcu_AsyncGetCombineForceInput(const uint8 LcuId, const uint8 HwLcOutputId);

/* LC/LCU Configuration */
void HwAcc_Lcu_SetForceFilter(const uint8 LcuId, const uint8 LcId, uint8 MaskValue);

void HwAcc_Lcu_SetForcePolarity(const uint8 LcuId, const uint8 LcId, uint8 MaskValue);

void HwAcc_Lcu_SetCombineEnable(const uint8 LcuId, const uint8 LcId, uint8 MaskValue);

void HwAcc_Lcu_SetSwSyncSelect(const uint8 LcuId, const uint8 LcId, uint8 MaskValue);

void HwAcc_Lcu_SetWriteProtect(const uint8 LcuId);

Lcu_Ip_ReturnType HwAcc_Lcu_GetWriteProtect(const uint8 LcuId);

#if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE)
void HwAcc_Lcu_AsyncSetInputList(const uint32 Parameter, const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue);

boolean HwAcc_Lcu_AsyncSetOutputList(const uint32 Parameter, const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue);
#endif /* #if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE) */

void HwAcc_Lcu_SetHwOutputCallbackState(const uint8 LcuId, const uint8 HwLcOutputId, Lcu_Ip_Callback IntCallback);

Lcu_Ip_HwOutputStateType * HwAcc_Lcu_GetHwOutputStatePointer(const uint8 LcuId, const uint8 LcId, const uint8 OutputId);

/* Set Status Register to reset value */
void HwAcc_Lcu_AsyncClearAllForceEvent(uint8 LcuId, uint8 LcId);

void HwAcc_Lcu_AsyncClearAllLutEvent(uint8 LcuId, uint8 LcId);

void HwAcc_Lcu_AsynGetInputInfo(const uint8 Param, const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value);

void HwAcc_Lcu_AsynGetOutputInfo(const uint8 Param, const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value);

void HwAcc_Lcu_SetInstanceOperationMode(const uint8 LucId, const uint8 OperationMode);

/* Set FCTRL value */
void HwAcc_Lcu_SetLcForceControl(const uint8 LcuId, const uint8 HwLcOutputId, const Lcu_Ip_LogicOutputConfigType * const pConfig);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == LCU_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef LCU_IP_HW_ACCESS_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
