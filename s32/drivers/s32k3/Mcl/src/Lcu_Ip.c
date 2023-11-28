/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Lcu_Ip.c
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

#include "Lcu_Ip.h"
#include "Lcu_Ip_Irq.h"
#include "Lcu_Ip_Hw_Access.h"
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
#include "Lcu_Ip_Multicore.h"
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#include "SchM_Mcl.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_VENDOR_ID_C                       43
#define LCU_IP_AR_RELEASE_MAJOR_VERSION_C        4
#define LCU_IP_AR_RELEASE_MINOR_VERSION_C        7
#define LCU_IP_AR_RELEASE_REVISION_VERSION_C     0
#define LCU_IP_SW_MAJOR_VERSION_C                3
#define LCU_IP_SW_MINOR_VERSION_C                0
#define LCU_IP_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lcu_Ip.c file and "Lcu_Ip.h" file are of the same vendor */
#if (LCU_IP_VENDOR_ID_C != LCU_IP_VENDOR_ID)
    #error "Lcu_Ip.c and "Lcu_Ip.h" have different vendor ids"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip.h" file are of the same Autosar version */
#if ((LCU_IP_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_AR_RELEASE_MINOR_VERSION_C != LCU_IP_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_AR_RELEASE_REVISION_VERSION_C != LCU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip.c and "Lcu_Ip.h" are different"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip.h" file are of the same Software version */
#if ((LCU_IP_SW_MAJOR_VERSION_C != LCU_IP_SW_MAJOR_VERSION) || \
     (LCU_IP_SW_MINOR_VERSION_C != LCU_IP_SW_MINOR_VERSION) || \
     (LCU_IP_SW_PATCH_VERSION_C != LCU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip.c and "Lcu_Ip.h" are different"
#endif

/* Check if Lcu_Ip.c file and Lcu_Ip_Hw_Access.h file are of the same vendor */
#if (LCU_IP_VENDOR_ID_C != LCU_IP_HW_ACCESS_VENDOR_ID)
    #error "Lcu_Ip.c and Lcu_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if Lcu_Ip.c file and Lcu_Ip_Hw_Access.h file are of the same Autosar version */
#if ((LCU_IP_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_AR_RELEASE_MINOR_VERSION_C != LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_AR_RELEASE_REVISION_VERSION_C != LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip.c and Lcu_Ip_Hw_Access.h are different"
#endif

/* Check if Lcu_Ip.c file and Lcu_Ip_Hw_Access.h file are of the same Software version */
#if ((LCU_IP_SW_MAJOR_VERSION_C != LCU_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (LCU_IP_SW_MINOR_VERSION_C != LCU_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (LCU_IP_SW_PATCH_VERSION_C != LCU_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip.c and Lcu_Ip_Hw_Access.h are different"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip_Irq.h" file are of the same vendor */
#if (LCU_IP_VENDOR_ID_C != LCU_IP_IRQ_VENDOR_ID)
    #error "Lcu_Ip.c and "Lcu_Ip_Irq.h" have different vendor ids"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip_Irq.h" file are of the same Autosar version */
#if ((LCU_IP_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_AR_RELEASE_MINOR_VERSION_C != LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_AR_RELEASE_REVISION_VERSION_C != LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip.c and "Lcu_Ip_Irq.h" are different"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip_Irq.h" file are of the same Software version */
#if ((LCU_IP_SW_MAJOR_VERSION_C != LCU_IP_IRQ_SW_MAJOR_VERSION) || \
     (LCU_IP_SW_MINOR_VERSION_C != LCU_IP_IRQ_SW_MINOR_VERSION) || \
     (LCU_IP_SW_PATCH_VERSION_C != LCU_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip.c and "Lcu_Ip_Irq.h" are different"
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
/* Check if Lcu_Ip.c file and "Lcu_Ip_Multicore.h" file are of the same vendor */
#if (LCU_IP_VENDOR_ID_C != LCU_IP_MULTICORE_VENDOR_ID)
    #error "Lcu_Ip.c and "Lcu_Ip_Multicore.h" have different vendor ids"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip_Multicore.h" file are of the same Autosar version */
#if ((LCU_IP_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_AR_RELEASE_MINOR_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_AR_RELEASE_REVISION_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip.c and "Lcu_Ip_Multicore.h" are different"
#endif

/* Check if Lcu_Ip.c file and "Lcu_Ip_Multicore.h" file are of the same Software version */
#if ((LCU_IP_SW_MAJOR_VERSION_C != LCU_IP_MULTICORE_SW_MAJOR_VERSION) || \
     (LCU_IP_SW_MINOR_VERSION_C != LCU_IP_MULTICORE_SW_MINOR_VERSION) || \
     (LCU_IP_SW_PATCH_VERSION_C != LCU_IP_MULTICORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip.c and "Lcu_Ip_Multicore.h" are different"
#endif
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Lcu_Ip.c file and SchM_Mcl header file are of the same Autosar version */
#if ((LCU_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_MCL_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_MCL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lcu_Ip.c and SchM_Mcl.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


#if (STD_ON == LCU_IP_IS_AVAILABLE)
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

/* Pointer to the LCU Initialization Configuration. Based on this configuration pointer,
   the LCU Driver obtains all information for the Logic Cell and corresponding
   Cell Configurations.
   The Pointer is loaded when Lcu_Ip_Init() is called. */
VAR_SEC_NOCACHE(Lcu_Ip_pxInit) static const Lcu_Ip_InitType * Lcu_Ip_pxInit;

#define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/* Initializes the LCU inputs */
static void Lcu_Ip_LogicInputInit(const uint8 LogicInput, const Lcu_Ip_LogicInputConfigType * const pConfig);

/* Initializes the LCU outputs */
static void Lcu_Ip_LogicOutputInit(const uint8 LogicOutput, const Lcu_Ip_LogicOutputConfigType * const pConfig);

/* Initializes the LCU Instance */
static void Lcu_Ip_LogicInstanceInit(const Lcu_Ip_LogicInstanceType * pConfig);

/* Reset all configurations for Logic Instance */
static void Lcu_Ip_LogicInstanceReset(uint8 LogicInstace);

/* Clear all bit for status register */
static void Lcu_Ip_ClearAllStatus(uint8 LogicInstace);

static void Lcu_Ip_SetSwOverrideDisable(uint8 LogicInput);

static void Lcu_Ip_SetOutputDisable(uint8 LogicOutput);

static void Lcu_Ip_SetHwOutputCallbackState(uint8 LogicOutput);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
 *                                 LCU LOGIC INSTANCE FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

Lcu_Ip_ReturnType Lcu_Ip_Init(const Lcu_Ip_InitType * const pxLcuInit)
{
    uint8 CfgIdx;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

    LCU_IP_DEV_ASSERT(NULL_PTR != pxLcuInit);
    LCU_IP_DEV_ASSERT(NULL_PTR != pxLcuInit->ppxLogicOutputConfigArray);
    LCU_IP_DEV_ASSERT(NULL_PTR != pxLcuInit->ppxLogicInputConfigArray);


#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LocStatus = Lcu_Ip_ValidateCoreInit(pxLcuInit);
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
    /* Save pointer to initialization structure */
    Lcu_Ip_pxInit = pxLcuInit;

    (void)Lcu_Ip_Deinit();

    /* Load input configuration */
    for (CfgIdx = 0U; CfgIdx < LCU_IP_NOF_CFG_LOGIC_INPUTS; CfgIdx++)
    {
        Lcu_Ip_LogicInputInit(CfgIdx, Lcu_Ip_pxInit->ppxLogicInputConfigArray[CfgIdx]->pxLcInputConfig);
    }

    /* Load output configuration */
    for (CfgIdx = 0U; CfgIdx < LCU_IP_NOF_CFG_LOGIC_OUTPUTS; CfgIdx++)
    {
        Lcu_Ip_LogicOutputInit(CfgIdx, Lcu_Ip_pxInit->ppxLogicOutputConfigArray[CfgIdx]->pxLcOutputConfig);
        Lcu_Ip_SetHwOutputCallbackState(CfgIdx);
    }

    /* Load input configuration */
    for (CfgIdx = 0U; CfgIdx < LCU_IP_NOF_CFG_LOGIC_INSTANCES; CfgIdx++)
    {
        Lcu_Ip_LogicInstanceInit(Lcu_Ip_pxInit->ppxLogicInstanceConfigArray[CfgIdx]);
    }

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

static void Lcu_Ip_SetHwOutputCallbackState(uint8 LogicOutput)
{
    uint8 HwInstance;
    uint8 HwLcOutputId;
    Lcu_Ip_Callback Callback;

    Lcu_Ip_HwOutputStateType * ppxCallback = Lcu_Ip_pxInit->ppxHwOutputStateArray[LogicOutput];

    const Lcu_Ip_LogicOutputIdType * ppxLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId);

    HwInstance = ppxLogicOutput->HwInstId;
    HwLcOutputId = ppxLogicOutput->HwLcOutputId;
    Callback = ppxLogicOutput->IntCallback;

    /* Set hardware output */
    HwAcc_Lcu_SetHwOutputSetState(HwInstance, HwLcOutputId, ppxCallback);

    HwAcc_Lcu_SetHwOutputCallbackState(HwInstance, HwLcOutputId, Callback);
}

static void Lcu_Ip_LogicInstanceInit(const Lcu_Ip_LogicInstanceType * pConfig)
{
    uint8 CfgIdx;
    uint8 HwInstance;
    uint8 HwLogicCell;
    const Lcu_Ip_LogicCellType * ppxLocLogicCell;
    uint8 LocNumLogicCell;
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    uint8 LocCoreRef = 0U;
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    LCU_IP_DEV_ASSERT(NULL_PTR != pConfig);

    HwInstance = pConfig->HwInstId;
    LocNumLogicCell = pConfig->NumLogicCellConfig;

    HwAcc_Lcu_SetInstanceOperationMode(HwInstance, pConfig-> OperationMode);

    if (LocNumLogicCell > 0U)
    {
        for (CfgIdx = 0U; CfgIdx < LocNumLogicCell; CfgIdx++)
        {
            ppxLocLogicCell = pConfig->ppxLogicCellConfigArray[CfgIdx];
            HwLogicCell = ppxLocLogicCell->HwLcId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
            LocCoreRef = ppxLocLogicCell->CoreRef;
            Lcu_Ip_SetCoreRef(HwInstance, HwLogicCell, LocCoreRef);
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */


            HwAcc_Lcu_SetForceFilter(HwInstance, HwLogicCell, ppxLocLogicCell->ForceFilter);
            HwAcc_Lcu_SetForcePolarity(HwInstance, HwLogicCell, ppxLocLogicCell->ForcePolarity);
            HwAcc_Lcu_SetCombineEnable(HwInstance, HwLogicCell, ppxLocLogicCell->CombEn);
            HwAcc_Lcu_SetSwSyncSelect(HwInstance, HwLogicCell, ppxLocLogicCell->SwSyncSel);
        }
    }
}

Lcu_Ip_ReturnType Lcu_Ip_SetWriteProtect(const uint8 LogicInstance)
{
    uint8 HwInstance = Lcu_Ip_pxInit->ppxLogicInstanceConfigArray[LogicInstance]->HwInstId;
    Lcu_Ip_ReturnType ReturnValue = Lcu_Ip_GetWriteProtect(HwInstance);

    if (LCU_IP_STATUS_SUCCESS == ReturnValue)
    {
        /* Set write protect */
        HwAcc_Lcu_SetWriteProtect(HwInstance);
    }

    return ReturnValue;
}

Lcu_Ip_ReturnType Lcu_Ip_GetWriteProtect(const uint8 LogicInstance)
{
    uint8 HwInstance = Lcu_Ip_pxInit->ppxLogicInstanceConfigArray[LogicInstance]->HwInstId;

    /* Get write protect */
    return HwAcc_Lcu_GetWriteProtect(HwInstance);
}


#if (STD_ON == LCU_IP_SYNC_FUNC_IS_AVAILABLE)
Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputSwOverrideEnable(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcInputId;
    uint8 LocLogicInputId;
    uint8 LocIndex;
    uint32 RegValue;
    uint32 MaskValue[LCU_INSTANCE_COUNT];
    uint32 DataValue[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    MaskValue[LCU_IP_HW_INST_0] = 0U;
    DataValue[LCU_IP_HW_INST_0] = 0U;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    MaskValue[LCU_IP_HW_INST_1] = 0U;
    DataValue[LCU_IP_HW_INST_1] = 0U;
#endif

    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicInputId = List[LocIndex].LogicInputId;
        /* Get the hardware output value */
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwInstId;
        LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwLcInputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
        if (LocStatus == LCU_IP_STATUS_SUCCESS)
        {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

            MaskValue[LocHwLcu] |= (uint32)((uint32)1U << LocHwLcInputId);
            DataValue[LocHwLcu] |= (uint32)(((uint32)(List[LocIndex].Value) & 1U) << LocHwLcInputId);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        }
        else
        {
            break;
        }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
    }

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_22();
#if (LCU_INSTANCE_COUNT >= 1U)
        if(0U != MaskValue[LCU_IP_HW_INST_0])
        {
            RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->SWEN;
            RegValue &= ~MaskValue[LCU_IP_HW_INST_0];
            RegValue |= DataValue[LCU_IP_HW_INST_0];
            Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->SWEN = RegValue;
        }
        else
        {
            /* Do nothing */
        }
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
        if(0U != MaskValue[LCU_IP_HW_INST_1])
        {
            RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->SWEN;
            RegValue &= ~MaskValue[LCU_IP_HW_INST_1];
            RegValue |= DataValue[LCU_IP_HW_INST_1];
            Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->SWEN = RegValue;
        }
        else
        {
            /* Do nothing */
        }
#endif
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_22();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}


Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputSwOverrideValue(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcInputId;
    uint8 LocLogicInputId;
    uint8 LocIndex;
    uint32 RegValue;
    uint32 MaskValue[LCU_INSTANCE_COUNT];
    uint32 DataValue[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    MaskValue[LCU_IP_HW_INST_0] = 0U;
    DataValue[LCU_IP_HW_INST_0] = 0U;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    MaskValue[LCU_IP_HW_INST_1] = 0U;
    DataValue[LCU_IP_HW_INST_1] = 0U;
#endif

    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicInputId = List[LocIndex].LogicInputId;
        /* Get the hardware output value */
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwInstId;
        LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwLcInputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
        if (LocStatus == LCU_IP_STATUS_SUCCESS)
        {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

            MaskValue[LocHwLcu] |= (uint32)((uint32)1U << LocHwLcInputId);
            DataValue[LocHwLcu] |= (uint32)(((uint32)(List[LocIndex].Value) & 1U) << LocHwLcInputId);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        }
        else
        {
            break;
        }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
    }

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
     if (LocStatus == LCU_IP_STATUS_SUCCESS)
     {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_23();
#if (LCU_INSTANCE_COUNT >= 1U)
        if(0U != MaskValue[LCU_IP_HW_INST_0])
        {
            RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->SWVALUE;
            RegValue &= ~MaskValue[LCU_IP_HW_INST_0];
            RegValue |= DataValue[LCU_IP_HW_INST_0];
            Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->SWVALUE = RegValue;
        }
        else
        {
            /* Do nothing */
        }
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
        if(0U != MaskValue[LCU_IP_HW_INST_1])
        {
            RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->SWVALUE;
            RegValue &= ~MaskValue[LCU_IP_HW_INST_1];
            RegValue |= DataValue[LCU_IP_HW_INST_1];
            Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->SWVALUE = RegValue;
        }
        else
        {
            /* Do nothing */
        }
#endif
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_23();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputMuxSelect(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 MaskValue;
    uint8 LocHwLcInputId;
    uint8 LocIndex;
    uint8 LocLogicInputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic input value */
        LocLogicInputId = List[LocIndex].LogicInputId;
        /* Get the hardware input value */
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwInstId;
        LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwLcInputId;

        LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic input value */
            LocLogicInputId = List[LocIndex].LogicInputId;
            /* Get the hardware input value */
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwInstId;
            LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwLcInputId;

            /* Set register value for hardware input */
            MaskValue = ((List[LocIndex].Value) & LCU_MUXSEL_MUXSEL_MASK);
            HwAcc_Lcu_AsyncSetInputMuxSelect(LocHwLcu, LocHwLcInputId, MaskValue);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputSwSyncMode(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 MaskValue;
    uint8 LocHwLcInputId;
    uint8 LocIndex;
    uint8 LocLogicInputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic input value */
        LocLogicInputId = List[LocIndex].LogicInputId;
        /* Get the hardware input value */
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwInstId;
        LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwLcInputId;

        LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_24();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic input value */
            LocLogicInputId = List[LocIndex].LogicInputId;
            /* Get the hardware input value */
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwInstId;
            LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LocLogicInputId]->xLogicInputId.HwLcInputId;

            /* Set register value for hardware input */
            MaskValue = ((List[LocIndex].Value) & 1U);
            HwAcc_Lcu_AsyncSetInputSwSyncMode(LocHwLcu, LocHwLcInputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_24();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputDebugMode(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    uint32 RegValue;
    uint32 MaskValue[LCU_INSTANCE_COUNT];
    uint32 DataValue[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    MaskValue[LCU_IP_HW_INST_0] = 0U;
    DataValue[LCU_IP_HW_INST_0] = 0U;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    MaskValue[LCU_IP_HW_INST_1] = 0U;
    DataValue[LCU_IP_HW_INST_1] = 0U;
#endif

    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus == LCU_IP_STATUS_SUCCESS)
        {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

            MaskValue[LocHwLcu] |= (uint32)((uint32)1U << LocHwLcOutputId);
            DataValue[LocHwLcu] |= (uint32)(((uint32)(List[LocIndex].Value) & 1U) << LocHwLcOutputId);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        }
        else
        {
            break;
        }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
    }

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
     if (LocStatus == LCU_IP_STATUS_SUCCESS)
     {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_25();
#if (LCU_INSTANCE_COUNT >= 1U)
        if(0U != MaskValue[LCU_IP_HW_INST_0])
        {
            RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->DBGEN;
            RegValue &= ~MaskValue[LCU_IP_HW_INST_0];
            RegValue |= DataValue[LCU_IP_HW_INST_0];
            Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->DBGEN = RegValue;
        }
        else
        {
            /* Do nothing */
        }
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
        if(0U != MaskValue[LCU_IP_HW_INST_1])
        {
            RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->DBGEN;
            RegValue &= ~MaskValue[LCU_IP_HW_INST_1];
            RegValue |= DataValue[LCU_IP_HW_INST_1];
            Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->DBGEN = RegValue;
        }
        else
        {
            /* Do nothing */
        }
#endif
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_25();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputEnable(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    uint32 RegValue;
    uint32 MaskValue[LCU_INSTANCE_COUNT];
    uint32 DataValue[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    MaskValue[LCU_IP_HW_INST_0] = 0U;
    DataValue[LCU_IP_HW_INST_0] = 0U;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    MaskValue[LCU_IP_HW_INST_1] = 0U;
    DataValue[LCU_IP_HW_INST_1] = 0U;
#endif

    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus == LCU_IP_STATUS_SUCCESS)
        {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

            MaskValue[LocHwLcu] |= (uint32)((uint32)1U << LocHwLcOutputId);
            DataValue[LocHwLcu] |= (uint32)(((uint32)(List[LocIndex].Value) & 1U) << LocHwLcOutputId);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        }
        else
        {
            break;
        }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
    }

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
     if (LocStatus == LCU_IP_STATUS_SUCCESS)
     {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_38();
        #if (LCU_INSTANCE_COUNT >= 1U)
            if(0U != MaskValue[LCU_IP_HW_INST_0])
            {
                RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->OUTEN;
                RegValue &= ~MaskValue[LCU_IP_HW_INST_0];
                RegValue |= DataValue[LCU_IP_HW_INST_0];
                Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->OUTEN = RegValue;
            }
            else
            {
                /* Do nothing */
            }
        #endif
        #if (LCU_INSTANCE_COUNT >= 2U)
            if(0U != MaskValue[LCU_IP_HW_INST_1])
            {
                RegValue = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->OUTEN;
                RegValue &= ~MaskValue[LCU_IP_HW_INST_1];
                RegValue |= DataValue[LCU_IP_HW_INST_1];
                Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->OUTEN = RegValue;
            }
            else
            {
                /* Do nothing */
            }
        #endif
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_38();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceInputSensitivity(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_26();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & LCU_FCTRL_FORCE_SENSE_COMMON_MASK);
            (void)HwAcc_Lcu_AsyncSetOutputForceInputSensitivity(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_26();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }

#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceClearingMode(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_27();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & LCU_FCTRL_FORCE_MODE_COMMON_MASK);
            (void)HwAcc_Lcu_AsyncSetOutputForceClearingMode(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_27();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceSyncSelect(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_28();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & LCU_FCTRL_SYNC_SEL_COMMON_MASK);
            (void)HwAcc_Lcu_AsyncSetOutputForceSyncSelect(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_28();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputPolarity(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_29();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & 1U);
            (void)HwAcc_Lcu_AsyncSetOutputPolarity(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_29();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceDma(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_30();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & 1U);
            (void)HwAcc_Lcu_AsyncSetOutputForceDma(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_30();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceInt(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    boolean LocVerifyMode;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_31();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & 1U);
            LocVerifyMode = HwAcc_Lcu_AsyncSetOutputForceInt(LocHwLcu, LocHwLcOutputId, MaskValue);
            if (LocVerifyMode == FALSE)
            {
                LocStatus = LCU_IP_STATUS_ERROR;
                break;
            }
            else
            {
                /* Do Nothing*/
            }
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_31();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputLutDma(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_32();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & 1U);
            (void)HwAcc_Lcu_AsyncSetOutputLutDma(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_32();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputLutInt(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    boolean LocVerifyMode;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_33();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = ((List[LocIndex].Value) & 1U);
            LocVerifyMode = HwAcc_Lcu_AsyncSetOutputLutInt(LocHwLcu, LocHwLcOutputId, MaskValue);
            if (LocVerifyMode == FALSE)
            {
                LocStatus = LCU_IP_STATUS_ERROR;
                break;
            }
            else
            {
                /* Do Nothing */
            }
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_33();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputFallFilter(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_34();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = (List[LocIndex].Value & LCU_FILT_LUT_FALL_FILT_MASK);
            (void)HwAcc_Lcu_AsyncSetOutputFallFilter(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_34();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputRiseFilter(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_35();
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            (void)HwAcc_Lcu_AsyncSetOutputRiseFilter(LocHwLcu, LocHwLcOutputId, List[LocIndex].Value);
        }
        SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_35();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputLutControl(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint16 MaskValue;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            MaskValue = (List[LocIndex].Value & LCU_LUTCTRL_LUTCTRL_MASK);
            (void)HwAcc_Lcu_AsyncSetOutputLutControl(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_ClearSyncOutputForceEvent(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint8 LocIndex;
    uint8 LocLogicOutputId;
    uint16 MaskValue = 0U;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the logic output value */
        LocLogicOutputId = List[LocIndex].LogicOutputId;
        /* Get the hardware output value */
        LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
        LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the logic output value */
            LocLogicOutputId = List[LocIndex].LogicOutputId;
            /* Get the hardware output value */
            LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwLcOutputId;
            LocHwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LocLogicOutputId]->xLogicOutputId.HwInstId;

            /* Set register value for hardware output */
            (void)HwAcc_Lcu_AsyncClearOutputForceEvent(LocHwLcu, LocHwLcOutputId, MaskValue);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetSyncLogicInput(Lcu_Ip_SyncInputValueType List[], const uint8 Dimension)
{
    uint8 LocIndex;
    Lcu_Ip_LogicInputIdType pxLocLogicInput;
    uint8 LocHwLcu;
    uint8 LocHwLcInputId;
    uint32 regLCU[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    regLCU[LCU_IP_HW_INST_0] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->LCIN;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    regLCU[LCU_IP_HW_INST_1] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->LCIN;
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the hardware output value */
        pxLocLogicInput = Lcu_Ip_pxInit->ppxLogicInputConfigArray[(List[LocIndex].LogicInputId)]->xLogicInputId;
        LocHwLcu = pxLocLogicInput.HwInstId;
        LocHwLcInputId = pxLocLogicInput.HwLcInputId;

        LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the hardware output value */
            pxLocLogicInput = Lcu_Ip_pxInit->ppxLogicInputConfigArray[(List[LocIndex].LogicInputId)]->xLogicInputId;
            LocHwLcu = pxLocLogicInput.HwInstId;
            LocHwLcInputId = pxLocLogicInput.HwLcInputId;

            List[LocIndex].Value = (uint8)((regLCU[LocHwLcu] >> LocHwLcInputId) & 1U);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetSyncSwOverrideInput(Lcu_Ip_SyncInputValueType List[], const uint8 Dimension)
{
    uint8 LocIndex;
    const Lcu_Ip_LogicInputIdType * pxLocLogicInput;
    uint8 LocHwLcu;
    uint8 LocHwLcInputId;
    uint32 regLCU[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    regLCU[LCU_IP_HW_INST_0] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->SWOUT;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    regLCU[LCU_IP_HW_INST_1] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->SWOUT;
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the hardware output value */
        pxLocLogicInput = &(Lcu_Ip_pxInit->ppxLogicInputConfigArray[(List[LocIndex].LogicInputId)]->xLogicInputId);
        LocHwLcu = pxLocLogicInput->HwInstId;
        LocHwLcInputId = pxLocLogicInput->HwLcInputId;

        LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the hardware output value */
            pxLocLogicInput = &(Lcu_Ip_pxInit->ppxLogicInputConfigArray[(List[LocIndex].LogicInputId)]->xLogicInputId);
            LocHwLcu = pxLocLogicInput->HwInstId;
            LocHwLcInputId = pxLocLogicInput->HwLcInputId;

            List[LocIndex].Value = (uint8)((regLCU[LocHwLcu] >> LocHwLcInputId) & 1U);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetSyncLogicOutput(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocIndex;
    const Lcu_Ip_LogicOutputIdType * pxLocLogicOutput;
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint32 regLCU[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    regLCU[LCU_IP_HW_INST_0] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->LCOUT;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    regLCU[LCU_IP_HW_INST_1] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->LCOUT;
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the hardware output value */
        pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
        LocHwLcu = pxLocLogicOutput->HwInstId;
        LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the hardware output value */
            pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
            LocHwLcu = pxLocLogicOutput->HwInstId;
            LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

            List[LocIndex].Value = (uint8)((regLCU[LocHwLcu] >> LocHwLcOutputId) & 1U);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetSyncForceOutput(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocIndex;
    const Lcu_Ip_LogicOutputIdType * pxLocLogicOutput;
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint32 regLCU[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    regLCU[LCU_IP_HW_INST_0] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->FORCEOUT;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    regLCU[LCU_IP_HW_INST_1] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->FORCEOUT;
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the hardware output value */
        pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
        LocHwLcu = pxLocLogicOutput->HwInstId;
        LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the hardware output value */
            pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
            LocHwLcu = pxLocLogicOutput->HwInstId;
            LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

            List[LocIndex].Value = (uint8)((regLCU[LocHwLcu] >> LocHwLcOutputId) & 1U);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetSyncForceStatus(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocIndex;
    const Lcu_Ip_LogicOutputIdType * pxLocLogicOutput;
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    uint32 regLCU[LCU_INSTANCE_COUNT];
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (LCU_INSTANCE_COUNT >= 1U)
    regLCU[LCU_IP_HW_INST_0] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_0]->FORCESTS;
#endif
#if (LCU_INSTANCE_COUNT >= 2U)
    regLCU[LCU_IP_HW_INST_1] = Lcu_Ip_paxBaseInst[LCU_IP_HW_INST_1]->FORCESTS;
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the hardware output value */
        pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
        LocHwLcu = pxLocLogicOutput->HwInstId;
        LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the hardware output value */
            pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
            LocHwLcu = pxLocLogicOutput->HwInstId;
            LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

            List[LocIndex].Value = (uint8)((regLCU[LocHwLcu] >> LocHwLcOutputId) & 1U);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetSyncCombineForceInput(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension)
{
    uint8 LocIndex;
    const Lcu_Ip_LogicOutputIdType * pxLocLogicOutput;
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
    {
        /* Get the hardware output value */
        pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
        LocHwLcu = pxLocLogicOutput->HwInstId;
        LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

        LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
        if (LocStatus != LCU_IP_STATUS_SUCCESS)
        {
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
        for (LocIndex = 0U; LocIndex < Dimension; LocIndex++)
        {
            /* Get the hardware output value */
            pxLocLogicOutput = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[(List[LocIndex].LogicOutputId)]->xLogicOutputId);
            LocHwLcu = pxLocLogicOutput->HwInstId;
            LocHwLcOutputId = pxLocLogicOutput->HwLcOutputId;

            List[LocIndex].Value = HwAcc_Lcu_AsyncGetCombineForceInput(LocHwLcu, LocHwLcOutputId);
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}
#endif /* #if (STD_ON == LCU_IP_SYNC_FUNC_IS_AVAILABLE) */

static void Lcu_Ip_LogicInputInit(const uint8 LogicInput, const Lcu_Ip_LogicInputConfigType * const pConfig)
{
    uint8 HwLcu;
    uint8 LocHwLcInputId;

    LCU_IP_DEV_ASSERT(NULL_PTR != pConfig);

    /* Get the hardware output value */
    LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]->xLogicInputId.HwLcInputId;
    HwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]->xLogicInputId.HwInstId;

    HwAcc_Lcu_AsyncSetInputMuxSelect(HwLcu, LocHwLcInputId, pConfig->MuxSel);
    HwAcc_Lcu_AsyncSetInputSwSyncMode(HwLcu, LocHwLcInputId, (pConfig->SwSynMode ? 1U : 0U));
    HwAcc_Lcu_AsyncSetInputSwOverrideValue(HwLcu, LocHwLcInputId, (pConfig->SwValue & 1U));

}

static void Lcu_Ip_LogicOutputInit(const uint8 LogicOutput, const Lcu_Ip_LogicOutputConfigType * const pConfig)
{
    uint8 HwLcu;
    uint8 LocHwLcOutputId;

    LCU_IP_DEV_ASSERT(NULL_PTR != pConfig);

    /* Get the hardware output value */
    LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId.HwLcOutputId;
    HwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId.HwInstId;

    (void)HwAcc_Lcu_AsyncSetOutputDebugMode(HwLcu, LocHwLcOutputId, (pConfig->EnDebugMode ? 1U : 0U));
    (void)HwAcc_Lcu_AsyncSetOutputLutControl(HwLcu, LocHwLcOutputId, pConfig->LutControl);
    (void)HwAcc_Lcu_AsyncSetOutputRiseFilter(HwLcu, LocHwLcOutputId, pConfig->LutRiseFilt);
    (void)HwAcc_Lcu_AsyncSetOutputFallFilter(HwLcu, LocHwLcOutputId, pConfig->LutFallFilt);
    (void)HwAcc_Lcu_AsyncSetOutputLutDma(HwLcu, LocHwLcOutputId, (pConfig->EnLutDma ? 1U : 0U));
    (void)HwAcc_Lcu_AsyncSetOutputForceDma(HwLcu, LocHwLcOutputId, (pConfig->EnForceDma ? 1U : 0U));
    (void)HwAcc_Lcu_AsyncSetOutputLutInt(HwLcu, LocHwLcOutputId, (pConfig->EnLutInt ? 1U : 0U));
    (void)HwAcc_Lcu_AsyncSetOutputForceInt(HwLcu, LocHwLcOutputId, (pConfig->EnForceInt ? 1U : 0U));
    (void)HwAcc_Lcu_AsyncSetOutputPolarity(HwLcu, LocHwLcOutputId, (pConfig->InvertOutput ? 1U : 0U));
    HwAcc_Lcu_SetLcForceControl(HwLcu, LocHwLcOutputId, pConfig);

}

Lcu_Ip_ReturnType Lcu_Ip_Deinit(void)
{
    uint8 CfgIdx;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit);
    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit->pxLogicOutputResetConfigArray);
    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit->pxLogicInputResetConfigArray);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LocStatus = Lcu_Ip_ValidateCoreInit(Lcu_Ip_pxInit);
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    /* Reset all common configuration for Input */
    for (CfgIdx = 0U; CfgIdx < LCU_IP_NOF_CFG_LOGIC_INPUTS; CfgIdx++)
    {
        Lcu_Ip_LogicInputInit(CfgIdx, Lcu_Ip_pxInit->pxLogicInputResetConfigArray);
        Lcu_Ip_SetSwOverrideDisable(CfgIdx);
    }

    /* Reset all common configuration for Output */
    for (CfgIdx = 0U; CfgIdx < LCU_IP_NOF_CFG_LOGIC_OUTPUTS; CfgIdx++)
    {
        Lcu_Ip_LogicOutputInit(CfgIdx, Lcu_Ip_pxInit->pxLogicOutputResetConfigArray);
        Lcu_Ip_SetOutputDisable(CfgIdx);
    }

    /* Reset all common configuration for Instance and status */
    for (CfgIdx = 0U; CfgIdx < LCU_IP_NOF_CFG_LOGIC_INSTANCES; CfgIdx++)
    {
        /* Reset all configurations for Logic Instance */
        Lcu_Ip_LogicInstanceReset(CfgIdx);
        /* Clear all bit for status register */
        Lcu_Ip_ClearAllStatus(CfgIdx);
    }

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

/* Reset all configurations for Logic Instance */
static void Lcu_Ip_LogicInstanceReset(uint8 LogicInstace)
{
    uint8 LcIndex;
    uint8 HwInstance = Lcu_Ip_pxInit->ppxLogicInstanceConfigArray[LogicInstace]->HwInstId;

    for (LcIndex = 0U; LcIndex < LCU_LC_COUNT; LcIndex++)
    {
        HwAcc_Lcu_SetForceFilter(HwInstance, LcIndex, FORCE_FILTER_RESET_VALUE);
        HwAcc_Lcu_SetForcePolarity(HwInstance, LcIndex, FORCE_POLARITY_RESET_VALUE);
        HwAcc_Lcu_SetCombineEnable(HwInstance, LcIndex, COMBEN_RESET_VALUE);
        HwAcc_Lcu_SetSwSyncSelect(HwInstance, LcIndex, SW_SYNC_SEL_RESET_VALUE);
    }
}
/* Clear all bit for status register */
static void Lcu_Ip_ClearAllStatus(uint8 LogicInstace)
{
    uint8 LcIndex;
    uint8 HwInstance = Lcu_Ip_pxInit->ppxLogicInstanceConfigArray[LogicInstace]->HwInstId;

    for (LcIndex = 0U; LcIndex < LCU_LC_COUNT; LcIndex++)
    {
        HwAcc_Lcu_AsyncClearAllForceEvent(HwInstance, LcIndex);
        HwAcc_Lcu_AsyncClearAllLutEvent(HwInstance, LcIndex);
    }
}

static void Lcu_Ip_SetSwOverrideDisable(uint8 LogicInput)
{
    uint8 HwLcu = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]->xLogicInputId.HwInstId;
    uint8 LocHwLcInputId = Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]->xLogicInputId.HwLcInputId;
    /* Set input software override enable */
    HwAcc_Lcu_AsyncSetInputSwOverrideEnable(HwLcu, LocHwLcInputId, LCU_IP_SW_OVERRIDE_DISABLE);
}

static void Lcu_Ip_SetOutputDisable(uint8 LogicOutput)
{
    uint8 HwLcu = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId.HwInstId;
    uint8 LocHwLcOutputId = Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId.HwLcOutputId;
    /* Set output enable */
    (void)HwAcc_Lcu_AsyncSetOutputEnable(HwLcu, LocHwLcOutputId, LCU_IP_OUTPUT_DISABLE);
}

void Lcu_Ip_IrqHandler(const uint8 HwInstance, const uint8 HwLogicCell, const uint8 HwOutput, const Lcu_Ip_Event Event)
{
    Lcu_Ip_HwOutputStateType * LocHwOutputState = HwAcc_Lcu_GetHwOutputStatePointer(HwInstance, HwLogicCell, HwOutput);

    if (NULL_PTR != LocHwOutputState)
    {
        if (NULL_PTR != LocHwOutputState->Callback)
        {
            /* Set callback */
            LocHwOutputState->Callback(Event);
        }
    }
}

#if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE)
Lcu_Ip_ReturnType Lcu_Ip_SetAsyncInputList(const uint8 LogicInput, const Lcu_Ip_AsyncInputValueType List[], const uint8 Dimension)
{
    uint8 Index;
    uint8 LocHwLcu;
    uint8 LocHwLcInputId;
    const Lcu_Ip_LogicInputIdType * pxLocLogicInputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

   LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit);
   LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]);
   LCU_IP_DEV_ASSERT(LCU_IP_NOF_CFG_LOGIC_INPUTS > LogicInput);
   LCU_IP_DEV_ASSERT(LCU_IP_INPUT_SET_SW_VALUE >= Dimension);

   pxLocLogicInputId = &(Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]->xLogicInputId);

   LocHwLcu = pxLocLogicInputId->HwInstId;
   LocHwLcInputId = pxLocLogicInputId->HwLcInputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_36();
    for (Index = 0U; Index < Dimension; Index++)
    {
        LCU_IP_DEV_ASSERT(LCU_IP_INPUT_SET_SW_VALUE >= List[Index].Param);
        HwAcc_Lcu_AsyncSetInputList((uint32)(List[Index].Param), LocHwLcu, LocHwLcInputId, List[Index].Value);
    }
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_36();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_SetAsyncOutputList(const uint8 LogicOutput, const Lcu_Ip_AsyncOutputValueType List[], const uint8 Dimension)
{
    uint8 Index;
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    const Lcu_Ip_LogicOutputIdType * pxLocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;
    boolean LocVerifyMode;

   LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit);
   LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]);
   LCU_IP_DEV_ASSERT(LCU_IP_NOF_CFG_LOGIC_OUTPUTS > LogicOutput);
   LCU_IP_DEV_ASSERT(LCU_IP_OUTPUT_CLEAR_FORCE_STS >= Dimension);

   pxLocLogicOutputId = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId);

   LocHwLcu = pxLocLogicOutputId->HwInstId;
   LocHwLcOutputId = pxLocLogicOutputId->HwLcOutputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_37();
    for (Index = 0U; Index < Dimension; Index++)
    {
        LCU_IP_DEV_ASSERT(LCU_IP_OUTPUT_CLEAR_FORCE_STS >= List[Index].Param);
        LocVerifyMode = HwAcc_Lcu_AsyncSetOutputList((uint32)(List[Index].Param), LocHwLcu, LocHwLcOutputId, List[Index].Value);
        if (FALSE == LocVerifyMode)
        {
            LocStatus = LCU_IP_STATUS_ERROR;
            break;
        }
        else
        {
            /* Do Nothing*/
        }
    }
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_37();

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetAsyncLogicInputInfo(const uint8 LogicInput, const Lcu_Ip_LogicInputInfoParamType Param, uint8 * const Value)
{
    uint8 LocHwLcu;
    uint8 LocHwLcInputId;
    const Lcu_Ip_LogicInputIdType * pxLocLogicInputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit);
    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]);
    LCU_IP_DEV_ASSERT(LCU_IP_NOF_CFG_LOGIC_INPUTS > LogicInput);
    LCU_IP_DEV_ASSERT(LCU_IP_INPUT_GET_SW_OVERRIDE_STATE >= Param);

    pxLocLogicInputId = &(Lcu_Ip_pxInit->ppxLogicInputConfigArray[LogicInput]->xLogicInputId);

    LocHwLcu = pxLocLogicInputId->HwInstId;
    LocHwLcInputId = pxLocLogicInputId->HwLcInputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LocStatus = Lcu_Ip_InputValidateCore(LocHwLcu, LocHwLcInputId);
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        HwAcc_Lcu_AsynGetInputInfo((uint8)Param, LocHwLcu, LocHwLcInputId, Value);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}

Lcu_Ip_ReturnType Lcu_Ip_GetAsyncLogicOutputInfo(const uint8 LogicOutput, const Lcu_Ip_LogicOutputInfoParamType Param, uint8 * const Value)
{
    uint8 LocHwLcu;
    uint8 LocHwLcOutputId;
    const Lcu_Ip_LogicOutputIdType * pxLocLogicOutputId;
    Lcu_Ip_ReturnType LocStatus = LCU_IP_STATUS_SUCCESS;

    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit);
    LCU_IP_DEV_ASSERT(NULL_PTR != Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]);
    LCU_IP_DEV_ASSERT(LCU_IP_NOF_CFG_LOGIC_OUTPUTS > LogicOutput);
    LCU_IP_DEV_ASSERT(LCU_IP_OUTPUT_GET_COMBINE_FORCE_INPUT >= Param);

    pxLocLogicOutputId = &(Lcu_Ip_pxInit->ppxLogicOutputConfigArray[LogicOutput]->xLogicOutputId);

    LocHwLcu = pxLocLogicOutputId->HwInstId;
    LocHwLcOutputId = pxLocLogicOutputId->HwLcOutputId;

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LocStatus = Lcu_Ip_OutputValidateCore(LocHwLcu, LocHwLcOutputId);
    if (LocStatus == LCU_IP_STATUS_SUCCESS)
    {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        HwAcc_Lcu_AsynGetOutputInfo((uint8)Param, LocHwLcu, LocHwLcOutputId, Value);

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        /* Do Nothing */
    }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    return LocStatus;
}
#endif /* #if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE) */

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #ifdef LCU_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */
