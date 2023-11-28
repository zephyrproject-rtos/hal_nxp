/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Lcu_Ip_Hw_Access.c
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

#include "Lcu_Ip_Hw_Access.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_HW_ACCESS_VENDOR_ID_C                       43
#define LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C        4
#define LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C        7
#define LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C     0
#define LCU_IP_HW_ACCESS_SW_MAJOR_VERSION_C                3
#define LCU_IP_HW_ACCESS_SW_MINOR_VERSION_C                0
#define LCU_IP_HW_ACCESS_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lcu_Ip_Hw_Access.c file and Lcu_Ip_Hw_Access.h file are of the same vendor */
#if (LCU_IP_HW_ACCESS_VENDOR_ID_C != LCU_IP_HW_ACCESS_VENDOR_ID)
    #error "Lcu_Ip_Hw_Access.c and Lcu_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if Lcu_Ip_Hw_Access.c file and Lcu_Ip_Hw_Access.h file are of the same Autosar version */
#if ((LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C != LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Hw_Access.c and Lcu_Ip_Hw_Access.h are different"
#endif

/* Check if Lcu_Ip_Hw_Access.c file and Lcu_Ip_Hw_Access.h file are of the same Software version */
#if ((LCU_IP_HW_ACCESS_SW_MAJOR_VERSION_C != LCU_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (LCU_IP_HW_ACCESS_SW_MINOR_VERSION_C != LCU_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (LCU_IP_HW_ACCESS_SW_PATCH_VERSION_C != LCU_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Hw_Access.c and Lcu_Ip_Hw_Access.h are different"
#endif

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
#define MCL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

LCU_Type * const Lcu_Ip_paxBaseInst[LCU_INSTANCE_COUNT] = IP_LCU_BASE_PTRS;

#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

#define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

VAR_SEC_NOCACHE(Lcu_Ip_paxHwOutputState) static Lcu_Ip_HwOutputStateType * Lcu_Ip_paxHwOutputState[LCU_INSTANCE_COUNT][LCU_LC_COUNT][LCU_NUM_OUTPUT_PER_LC];

VAR_SEC_NOCACHE(Lcu_Ip_au8OperationMode) static uint8 Lcu_Ip_au8OperationMode[LCU_INSTANCE_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

static void HwAcc_Lcu_AsyncGetLogicInput (const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value);

static void HwAcc_Lcu_AsyncGetSwOverrideInput (const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value);

static void HwAcc_Lcu_AsyncGetLogicOutput(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value);

static void HwAcc_Lcu_AsyncGetForceOutput(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value);

static void HwAcc_Lcu_AsyncGetForceStatus(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value);

static void HwAcc_Lcu_AsyncGetCombineForce (const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value);

static void HwAcc_Lcu_AsyncGetLutStatus(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
 * LCU INSTANCE INSTANCE FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/* Input Configuration */
void HwAcc_Lcu_AsyncSetInputMuxSelect(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    PtBase->MUXSEL[HwLcInputId] = LCU_MUXSEL_MUXSEL(MaskValue);
}

void HwAcc_Lcu_AsyncSetInputSwOverrideValue(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg = PtBase->SWVALUE;

    /* Register access */
    Reg &= ~(uint32)((uint32)1U << HwLcInputId);
    Reg |= LCU_SWVALUE_SWVALUE((uint32)((uint32)MaskValue << HwLcInputId));
    PtBase->SWVALUE = Reg;
}

void HwAcc_Lcu_AsyncSetInputSwSyncMode(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_INPUT_TO_LC(HwLcInputId);
    uint32 Reg = PtBase->LC[LcId].SCTRL;
    uint8 HwInput = LCU_IP_MAPPING_INTPUT_ID_TO_HW_INPUT(HwLcInputId);

    /* Register access */

    Reg &= ~(uint32)((uint32)1U << HwInput);
    Reg |= LCU_SCTRL_SW_MODE((uint32)((uint32)MaskValue << HwInput));
    PtBase->LC[LcId].SCTRL = Reg;
}

void HwAcc_Lcu_AsyncSetInputSwOverrideEnable(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg = PtBase->SWEN;

    /* Register access */

    Reg &= ~(uint32)((uint32)1U << HwLcInputId);
    Reg |= LCU_SWEN_SWEN((uint8)((MaskValue & LCU_SWEN_SWEN_MASK) << HwLcInputId));
    PtBase->SWEN = Reg;
}

/* Output Configuration */
boolean HwAcc_Lcu_AsyncSetOutputEnable(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg = PtBase->OUTEN;

    /* Register access */

    Reg &= ~(uint32)((uint32)1U << HwLcOutputId);
    Reg |= LCU_OUTEN_OUTEN((uint16)((MaskValue & LCU_OUTEN_OUTEN_MASK) << HwLcOutputId));
    PtBase->OUTEN = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputDebugMode(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg = PtBase->DBGEN;

    /* Register access */
    Reg &= ~(uint32)((uint32)1U << HwLcOutputId);
    Reg |= LCU_DBGEN_DBGEN((uint32)((uint32)MaskValue << HwLcOutputId));
    PtBase->DBGEN = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputForceInputSensitivity(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg = PtBase->LC[LcId].FCTRL;
    uint32 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    Reg &= ~(uint32)(LCU_FCTRL_FORCE_SENSE_MASK(HwOutput));
    Reg |= LCU_FCTRL_FORCE_SENSE(HwOutput, MaskValue);
    PtBase->LC[LcId].FCTRL = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputForceClearingMode(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg = PtBase->LC[LcId].FCTRL;
    uint32 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    Reg &= ~(uint32)(LCU_FCTRL_FORCE_MODE_MASK(HwOutput));
    Reg |= LCU_FCTRL_FORCE_MODE(HwOutput, MaskValue);
    PtBase->LC[LcId].FCTRL = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputForceSyncSelect(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg = PtBase->LC[LcId].FCTRL;
    uint32 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    Reg &= ~(uint32)(LCU_FCTRL_SYNC_SEL_MASK(HwOutput));
    Reg |= LCU_FCTRL_SYNC_SEL(HwOutput, MaskValue);
    PtBase->LC[LcId].FCTRL = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputPolarity(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg = PtBase->LC[LcId].OUTPOL;
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    Reg &= ~(uint32)((uint32)1U << HwOutput);
    Reg |= LCU_OUTPOL_OUTPOL((uint32)((uint32)MaskValue << HwOutput));
    PtBase->LC[LcId].OUTPOL = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncClearOutputForceEvent(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 HwOutput = HwLcOutputId;
    (void)MaskValue;

    /* Register access */
    PtBase->FORCESTS = LCU_FORCESTS_FORCESTS((uint32)1U << HwOutput);

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputForceDma(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].INTDMAEN;
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    Reg &= ~(uint32)(((uint32)1U << HwOutput) << LCU_INTDMAEN_FORCE_DMA_EN_SHIFT);
    Reg |= LCU_INTDMAEN_FORCE_DMA_EN(((uint32)((uint32)MaskValue << HwOutput)));
    PtBase->LC[LcId].INTDMAEN = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputForceInt(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].INTDMAEN;
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    boolean ReturnValue = TRUE;

    /* Register access */
    if (Lcu_Ip_au8OperationMode[LcuId] == LCU_IP_POLLING_MODE)
    {
        ReturnValue = FALSE;
    }
    else
    {
        Reg &= ~(uint32)(((uint32)1U << HwOutput) << LCU_INTDMAEN_FORCE_INT_EN_SHIFT);
        Reg |= LCU_INTDMAEN_FORCE_INT_EN(((uint32)((uint32)MaskValue << HwOutput)));
        PtBase->LC[LcId].INTDMAEN = Reg;
    }
    return ReturnValue;
}

boolean HwAcc_Lcu_AsyncSetOutputLutDma(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].INTDMAEN;
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    Reg &= ~(uint32)((uint32)1U << HwOutput);
    Reg |= LCU_INTDMAEN_LUT_DMA_EN(((uint32)((uint32)MaskValue << HwOutput)));
    PtBase->LC[LcId].INTDMAEN = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputLutInt(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].INTDMAEN;
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    boolean ReturnValue = TRUE;

    /* Register access */
    if (Lcu_Ip_au8OperationMode[LcuId] == LCU_IP_POLLING_MODE)
    {
        ReturnValue = FALSE;
    }
    else
    {
        Reg &= ~(uint32)((uint32)1U << HwOutput);
        Reg |= LCU_INTDMAEN_LUT_INT_EN(((uint32)((uint32)MaskValue << HwOutput)));
        PtBase->LC[LcId].INTDMAEN = Reg;
    }
    return ReturnValue;
}

boolean HwAcc_Lcu_AsyncSetOutputFallFilter(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].FILT[HwOutput];

    /* Register access */
    Reg &= ~(LCU_FILT_LUT_FALL_FILT_MASK);
    Reg |= LCU_FILT_LUT_FALL_FILT(MaskValue);
    PtBase->LC[LcId].FILT[HwOutput] = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputRiseFilter(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].FILT[HwOutput];

    /* Register access */
    Reg &= ~(LCU_FILT_LUT_RISE_FILT_MASK);
    Reg |= LCU_FILT_LUT_RISE_FILT(MaskValue);
    PtBase->LC[LcId].FILT[HwOutput] = Reg;

    return TRUE;
}

boolean HwAcc_Lcu_AsyncSetOutputLutControl(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    PtBase->LC[LcId].LUTCTRL[HwOutput] = LCU_LUTCTRL_LUTCTRL(MaskValue);

    return TRUE;
}

uint8 HwAcc_Lcu_AsyncGetCombineForceInput(const uint8 LcuId, const uint8 HwLcOutputId)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].FFILT;
    uint8 Mask = 1U << HwOutput;
    uint8 ReturnValue = (uint8) ((Reg & LCU_FFILT_COMB_FORCE_MASK) >> LCU_FFILT_COMB_FORCE_SHIFT);

    /* Register access */
    ReturnValue = (uint8)((ReturnValue & Mask) >> HwOutput);
    return ReturnValue;
}

void HwAcc_Lcu_SetForceFilter(const uint8 LcuId, const uint8 LcId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg =  PtBase->LC[LcId].FFILT;

    /* Register access */
    Reg &= ~(LCU_FFILT_FORCE_FILT_MASK);
    Reg |= LCU_FFILT_FORCE_FILT(MaskValue);
    PtBase->LC[LcId].FFILT = Reg;
}

void HwAcc_Lcu_SetForcePolarity(const uint8 LcuId, const uint8 LcId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg =  PtBase->LC[LcId].FFILT;

    /* Register access */
    Reg &= ~(LCU_FFILT_FORCE_POL_MASK);
    Reg |= LCU_FFILT_FORCE_POL(MaskValue);
    PtBase->LC[LcId].FFILT = Reg;
}

void HwAcc_Lcu_SetCombineEnable(const uint8 LcuId, const uint8 LcId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg =  PtBase->LC[LcId].FFILT;

    /* Register access */
    Reg &= ~(LCU_FFILT_COMB_EN_MASK);
    Reg |= LCU_FFILT_COMB_EN(MaskValue);
    PtBase->LC[LcId].FFILT = Reg;
}

void HwAcc_Lcu_SetSwSyncSelect(const uint8 LcuId, const uint8 LcId, uint8 MaskValue)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg =  PtBase->LC[LcId].SCTRL;

    /* Register access */
    Reg &= ~(LCU_SCTRL_SW_SYNC_SEL_MASK);
    Reg |= LCU_SCTRL_SW_SYNC_SEL(MaskValue);
    PtBase->LC[LcId].SCTRL = Reg;
}

void HwAcc_Lcu_SetWriteProtect(const uint8 LcuId)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];

    /* Register access */
    PtBase->CFG |= LCU_CFG_WP_MASK;
}

Lcu_Ip_ReturnType HwAcc_Lcu_GetWriteProtect(const uint8 LcuId)
{
    Lcu_Ip_ReturnType ReturnValue = LCU_IP_STATUS_SUCCESS;
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg = PtBase->CFG;

    /* Register access */
    if(0U != (Reg & LCU_CFG_WP_MASK))
    {
        ReturnValue = LCU_IP_STATUS_PROTECTED;
    }
    return ReturnValue;
}


#if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE)
void HwAcc_Lcu_AsyncSetInputList(const uint32 Parameter, const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue)
{
    /* Function pointer */
    static void (*fpHwAcc_Lcu_SetInputList[])(const uint8 LcuId, const uint8 HwLcInputId, uint8 MaskValue) =
    {
        HwAcc_Lcu_AsyncSetInputMuxSelect,
        HwAcc_Lcu_AsyncSetInputSwSyncMode,
        HwAcc_Lcu_AsyncSetInputSwOverrideEnable,
        HwAcc_Lcu_AsyncSetInputSwOverrideValue,
    };
    fpHwAcc_Lcu_SetInputList[Parameter](LcuId, HwLcInputId, MaskValue);
}

boolean HwAcc_Lcu_AsyncSetOutputList(const uint32 Parameter, const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue)
{
    /* Function pointer */
    static boolean (*fpHwAcc_Lcu_SetOutputList[])(const uint8 LcuId, const uint8 HwLcOutputId, uint16 MaskValue) =
    {
        HwAcc_Lcu_AsyncSetOutputDebugMode,
        HwAcc_Lcu_AsyncSetOutputEnable,
        HwAcc_Lcu_AsyncSetOutputLutControl,
        HwAcc_Lcu_AsyncSetOutputRiseFilter,
        HwAcc_Lcu_AsyncSetOutputFallFilter,
        HwAcc_Lcu_AsyncSetOutputForceDma,
        HwAcc_Lcu_AsyncSetOutputLutDma,
        HwAcc_Lcu_AsyncSetOutputForceInt,
        HwAcc_Lcu_AsyncSetOutputLutInt,
        HwAcc_Lcu_AsyncSetOutputPolarity,
        HwAcc_Lcu_AsyncSetOutputForceInputSensitivity,
        HwAcc_Lcu_AsyncSetOutputForceClearingMode,
        HwAcc_Lcu_AsyncSetOutputForceSyncSelect,
        HwAcc_Lcu_AsyncClearOutputForceEvent,
    };
    return fpHwAcc_Lcu_SetOutputList[Parameter](LcuId, HwLcOutputId, MaskValue);
}
#endif /* #if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE) */

void HwAcc_Lcu_SetHwOutputSetState(const uint8 LcuId, const uint8 HwLcOutputId, Lcu_Ip_HwOutputStateType * SetState)
{
    /* Register access */
    uint8 HwLogicCell = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    Lcu_Ip_paxHwOutputState[LcuId][HwLogicCell][HwOutput] = SetState;
}

void HwAcc_Lcu_SetHwOutputCallbackState(const uint8 LcuId, const uint8 HwLcOutputId, Lcu_Ip_Callback IntCallback)
{
    /* Register access */
    uint8 HwLogicCell = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    Lcu_Ip_paxHwOutputState[LcuId][HwLogicCell][HwOutput]->Callback = IntCallback;
}

Lcu_Ip_HwOutputStateType * HwAcc_Lcu_GetHwOutputStatePointer(const uint8 LcuId, const uint8 LcId, const uint8 OutputId)
{
    /* Register access */
    return Lcu_Ip_paxHwOutputState[LcuId][LcId][OutputId];
}

/* Set Status Register to reset value */
void HwAcc_Lcu_AsyncClearAllForceEvent(uint8 LcuId, uint8 LcId)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg =  PtBase->LC[LcId].STS;

    /* Register access */
    Reg |= LCU_STS_FORCESTS_MASK;
    PtBase->LC[LcId].STS = Reg;
}

void HwAcc_Lcu_AsyncClearAllLutEvent(uint8 LcuId, uint8 LcId)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint32 Reg =  PtBase->LC[LcId].STS;

    /* Register access */
    Reg |= LCU_STS_LUT_STS_MASK;
    PtBase->LC[LcId].STS = Reg;
}

static void HwAcc_Lcu_AsyncGetLogicInput (const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value)
{
    /* Register access */
    *Value = (uint8)((Lcu_Ip_paxBaseInst[LcuId]->LCIN >> HwLcInputId) & 1U);
}

static void HwAcc_Lcu_AsyncGetSwOverrideInput (const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value)
{
    /* Register access */
    *Value = (uint8)((Lcu_Ip_paxBaseInst[LcuId]->SWOUT >> HwLcInputId) & 1U);
}

static void HwAcc_Lcu_AsyncGetLogicOutput(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value)
{
    /* Register access */
    *Value = (uint8)((Lcu_Ip_paxBaseInst[LcuId]->LCOUT >> HwLcOutputId) & 1U);
}

static void HwAcc_Lcu_AsyncGetForceOutput(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value)
{
    /* Register access */
    *Value = (uint8)((Lcu_Ip_paxBaseInst[LcuId]->FORCEOUT >> HwLcOutputId) & 1U);
}
static void HwAcc_Lcu_AsyncGetForceStatus(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value)
{
    /* Register access */
    *Value = (uint8)((Lcu_Ip_paxBaseInst[LcuId]->FORCESTS >> HwLcOutputId) & 1U);
}

static void HwAcc_Lcu_AsyncGetCombineForce (const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);
    uint32 Reg =  PtBase->LC[LcId].FFILT;
    uint8 Mask = 1U << HwOutput;
    uint8 ReturnValue = (uint8) ((Reg & LCU_FFILT_COMB_FORCE_MASK) >> LCU_FFILT_COMB_FORCE_SHIFT);

    /* Register access */
    *Value = (uint8)((ReturnValue & Mask) >> HwOutput);

}

static void HwAcc_Lcu_AsyncGetLutStatus(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value)
{
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint8 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    /* Register access */
    *Value = (uint8)((Lcu_Ip_paxBaseInst[LcuId]->LC[LcId].STS >> HwOutput) & 1U);
}

void HwAcc_Lcu_AsynGetInputInfo(const uint8 Param, const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value)
{
    /* Function pointer */
    static void (*fpHwAcc_Lcu_AsynGetInputInfo[])(const uint8 LcuId, const uint8 HwLcInputId, uint8 * const Value) =
    {
        HwAcc_Lcu_AsyncGetLogicInput,
        HwAcc_Lcu_AsyncGetSwOverrideInput,
    };
    fpHwAcc_Lcu_AsynGetInputInfo[Param](LcuId, HwLcInputId, Value);
}

void HwAcc_Lcu_AsynGetOutputInfo(const uint8 Param, const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value)
{
    /* Function pointer */
    static void (*fpHwAcc_Lcu_AsynGetOutputInfo[])(const uint8 LcuId, const uint8 HwLcOutputId, uint8 * const Value) =
    {
        HwAcc_Lcu_AsyncGetLogicOutput,
        HwAcc_Lcu_AsyncGetForceOutput,
        HwAcc_Lcu_AsyncGetForceStatus,
        HwAcc_Lcu_AsyncGetLutStatus,
        HwAcc_Lcu_AsyncGetCombineForce,
    };
    fpHwAcc_Lcu_AsynGetOutputInfo[Param](LcuId, HwLcOutputId, Value);
}

void HwAcc_Lcu_SetInstanceOperationMode(const uint8 LucId, const uint8 OperationMode)
{
    /* Register access */
    Lcu_Ip_au8OperationMode[LucId] = OperationMode;
}

/*==================================================================================================
 * LC Force Control (FCTRL) - REGISTER ACCESS
==================================================================================================*/
void HwAcc_Lcu_SetLcForceControl(const uint8 LcuId, const uint8 HwLcOutputId, const Lcu_Ip_LogicOutputConfigType * const pConfig)
{
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    uint8 LcId = LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId);
    uint32 Reg = PtBase->LC[LcId].FCTRL;
    uint32 HwOutput = LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId);

    Reg &= ~(uint32)(LCU_FCTRL_FORCE_SENSE_MASK(HwOutput));
    Reg |= LCU_FCTRL_FORCE_SENSE(HwOutput, pConfig->ForceSignalSel);

    Reg &= ~(uint32)(LCU_FCTRL_FORCE_MODE_MASK(HwOutput));
    Reg |= LCU_FCTRL_FORCE_MODE(HwOutput, pConfig->ClearForceMode);

    Reg &= ~(uint32)(LCU_FCTRL_SYNC_SEL_MASK(HwOutput));
    Reg |= LCU_FCTRL_SYNC_SEL(HwOutput, pConfig->ForceSyncSel);

    PtBase->LC[LcId].FCTRL = Reg;
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == LCU_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
