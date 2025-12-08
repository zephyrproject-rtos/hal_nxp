/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Divider.c
*   @version    0.8.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
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

#include "Clock_Ip_Private.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_DIVIDER_VENDOR_ID_C                      43
#define CLOCK_IP_DIVIDER_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_DIVIDER_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_DIVIDER_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_DIVIDER_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_DIVIDER_SW_MINOR_VERSION_C               8
#define CLOCK_IP_DIVIDER_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Divider.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_DIVIDER_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Divider.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Divider.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_DIVIDER_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_DIVIDER_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_DIVIDER_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Divider.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Divider.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_DIVIDER_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_DIVIDER_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_DIVIDER_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Divider.c and Clock_Ip_Private.h are different"
#endif

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

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static Clock_Ip_NameType Clock_Ip_DividerName = gated_clk;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_CallbackDividerEmptyName(Clock_Ip_NameType DividerName);
static void Clock_Ip_CallbackDividerEmpty1(void);
static uint32 Clock_Ip_CallbackDividerEmpty2(void);
static ClockLLD_StatusReturnType Clock_Ip_CallbackDividerEmpty3(void);
static void Clock_Ip_CallbackDividerEmpty4(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_CallbackDividerEmpty5(uint32 DividerValue);
#ifdef CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_POSTDIV
static void Clock_Ip_SetNamePlldivOutputDividerPostdiv(Clock_Ip_NameType DividerName);
static void Clock_Ip_ResetPlldivOutputDividerPostdiv(void);
static void Clock_Ip_SetOptionalParameterPlldivOutputDividerPostdiv(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetPlldivOutputDividerPostdiv(uint32 DividerValue);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusPlldivOutputDividerPostdiv(void);
static uint32 Clock_Ip_GetDividerValuePlldivOutputDividerPostdiv(void);
static uint32 Clock_Ip_GetMinimumDividerValuePlldivOutputDividerPostdiv(void);
#endif
#ifdef CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_DE_OUTPUT_DIV
static void Clock_Ip_SetNamePlldivOutputDividerDeOutputDiv(Clock_Ip_NameType DividerName);
static void Clock_Ip_ResetPlldivOutputDividerDeOutputDiv(void);
static void Clock_Ip_SetOptionalParameterPlldivOutputDividerDeOutputDiv(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetPlldivOutputDividerDeOutputDiv(uint32 DividerValue);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusPlldivOutputDividerDeOutputDiv(void);
static uint32 Clock_Ip_GetDividerValuePlldivOutputDividerDeOutputDiv(void);
static uint32 Clock_Ip_GetMinimumDividerValuePlldivOutputDividerDeOutputDiv(void);
#endif
#ifdef CLOCK_IP_CGM_X_SLC_Y_DC_DE_DIV_UPD_STAT
static void Clock_Ip_SetNameCgmXSlcYDcDeDivUpdStat(Clock_Ip_NameType DividerName);
static void Clock_Ip_ResetCgmXSlcYDcDeDivUpdStat(void);
static void Clock_Ip_SetOptionalParameterCgmXSlcYDcDeDivUpdStat(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetCgmXSlcYDcDeDivUpdStat(uint32 DividerValue);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCgmXSlcYDcDeDivUpdStat(void);
static uint32 Clock_Ip_GetDividerValueCgmXSlcYDcDeDivUpdStat(void);
static uint32 Clock_Ip_GetMinimumDividerValueCgmXSlcYDcDeDivUpdStat(void);
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/* Clock start section code */

#include "Mcu_MemMap.h"

static void Clock_Ip_CallbackDividerEmptyName(Clock_Ip_NameType DividerName)
{
    (void)DividerName;
    /* No implementation */
}
static void Clock_Ip_CallbackDividerEmpty1(void)
{
    /* No implementation */
}
static uint32 Clock_Ip_CallbackDividerEmpty2(void)
{
    /* No implementation */
    return 0U;
}
static ClockLLD_StatusReturnType Clock_Ip_CallbackDividerEmpty3(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static void Clock_Ip_CallbackDividerEmpty4(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_CallbackDividerEmpty5(uint32 DividerValue)
{
    (void)DividerValue;
}

#ifdef CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_POSTDIV
static void Clock_Ip_SetNamePlldivOutputDividerPostdiv(Clock_Ip_NameType DividerName)
{
    Clock_Ip_DividerName = DividerName;
}
static void Clock_Ip_ResetPlldivOutputDividerPostdiv(void)
{
    /* No implementation */
}
static void Clock_Ip_SetOptionalParameterPlldivOutputDividerPostdiv(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_SetPlldivOutputDividerPostdiv(uint32 DividerValue)
{
    (void)DividerValue;
    /* No implementation */
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusPlldivOutputDividerPostdiv(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static uint32 Clock_Ip_GetDividerValuePlldivOutputDividerPostdiv(void)
{
    return 0U;
}
static uint32 Clock_Ip_GetMinimumDividerValuePlldivOutputDividerPostdiv(void)
{
    return 0U;
}
#endif
#ifdef CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_DE_OUTPUT_DIV
static void Clock_Ip_SetNamePlldivOutputDividerDeOutputDiv(Clock_Ip_NameType DividerName)
{
    Clock_Ip_DividerName = DividerName;
}
static void Clock_Ip_ResetPlldivOutputDividerDeOutputDiv(void)
{
    /* No implementation */
}
static void Clock_Ip_SetOptionalParameterPlldivOutputDividerDeOutputDiv(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_SetPlldivOutputDividerDeOutputDiv(uint32 DividerValue)
{
    (void)DividerValue;
    /* No implementation */

    switch (Clock_Ip_DividerName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT0_CLK)
        case COREPLL_CLKOUT0_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT1_CLK)
        case COREPLL_CLKOUT1_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT2_CLK)
        case COREPLL_CLKOUT2_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT3_CLK)
        case COREPLL_CLKOUT3_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_CORE_PLL->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT0_CLK)
        case PERIPHPLL_CLKOUT0_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_0 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_0 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT1_CLK)
        case PERIPHPLL_CLKOUT1_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_1 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_1 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT2_CLK)
        case PERIPHPLL_CLKOUT2_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_2 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_2 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT3_CLK)
        case PERIPHPLL_CLKOUT3_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_3 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_3 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT4_CLK)
        case PERIPHPLL_CLKOUT4_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_4 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PERIPH_PLL->PLL_OUTPUT_DIVIDER_4 = PERIPH_PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV0_CLK)
        case PLL0_DIV0_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV1_CLK)
        case PLL0_DIV1_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV2_CLK)
        case PLL0_DIV2_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV3_CLK)
        case PLL0_DIV3_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_0->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV0_CLK)
        case PLL1_DIV0_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV1_CLK)
        case PLL1_DIV1_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV2_CLK)
        case PLL1_DIV2_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV3_CLK)
        case PLL1_DIV3_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_1->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_DIV0_CLK)
        case CPE_DIV0_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_CPE_PLL->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_CPE_PLL->PLL_OUTPUT_DIVIDER_0 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_DIV1_CLK)
        case CPE_PLL_DIV1_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_CPE->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_CPE->PLL_OUTPUT_DIVIDER_1 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_DIV2_CLK)
        case CPE_PLL_DIV2_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_CPE->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_CPE->PLL_OUTPUT_DIVIDER_2 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_DIV3_CLK)
        case CPE_PLL_DIV3_CLK:
        {
            if (DividerValue > 0U)
            {
                IP_PLL_CPE->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(1U) | PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(DividerValue - 1U);
            }
            else
            {
                IP_PLL_CPE->PLL_OUTPUT_DIVIDER_3 = PLL_PLL_OUTPUT_DIVIDER_0_DE(0U);
            }
        }
        break;
#endif
        default:
        {
            /* Not supported */
        }
    }
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusPlldivOutputDividerDeOutputDiv(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static uint32 Clock_Ip_GetDividerValuePlldivOutputDividerDeOutputDiv(void)
{
    return 0U;
}
static uint32 Clock_Ip_GetMinimumDividerValuePlldivOutputDividerDeOutputDiv(void)
{
    return 0U;
}
#endif
#ifdef CLOCK_IP_CGM_X_SLC_Y_DC_DE_DIV_UPD_STAT
static void Clock_Ip_SetNameCgmXSlcYDcDeDivUpdStat(Clock_Ip_NameType DividerName)
{
    Clock_Ip_DividerName = DividerName;
}
static void Clock_Ip_ResetCgmXSlcYDcDeDivUpdStat(void)
{
    /* No implementation */
}
static void Clock_Ip_SetOptionalParameterCgmXSlcYDcDeDivUpdStat(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_SetCgmXSlcYDcDeDivUpdStat(uint32 DividerValue)
{
    uint32 DividerEntry;
    uint32 DividerIndex;
    uint32 DividerMask;
    uint32 DividerShift;

    uint32 RegValue;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 DividerStatus;

    Clock_Ip_HwSelectorType *HwAddr;

    DividerEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_DividerName][CLOCK_LLD_DIVIDER_ENTRY];

    DividerIndex      =  Clock_Ip_axSelectorsDividersTable[DividerEntry].DivIndex;
    DividerMask       =  Clock_Ip_axSelectorsDividersTable[DividerEntry].DivMask;
    DividerShift      =  Clock_Ip_axSelectorsDividersTable[DividerEntry].DivShift;

    HwAddr            =  Clock_Ip_axSelectorsDividersTable[DividerEntry].Address;

    RegValue = HwAddr->Dividers[DividerIndex];

    /* Program divider value */
    if (DividerValue != 0U)
    {
        RegValue &= ~DividerMask;
        RegValue |= (((DividerValue-1U) << DividerShift) & DividerMask);

        /* Enable divider */
        RegValue |= MC_CGM_MUX_DC_DE_MASK;
    }
    else
    {
        RegValue &= ~MC_CGM_MUX_DC_DE_MASK;
    }

    HwAddr->Dividers[DividerIndex] = RegValue;

    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    /* Wait for acknowledge to be cleared. */
    do
    {
        DividerStatus = (HwAddr->DividerStatus & MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK);
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while ((MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_PENDING == DividerStatus) && (FALSE == TimeoutOccurred));

    if (TRUE == TimeoutOccurred)
    {
        /* Report timeout error */
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_DividerName);
    }
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCgmXSlcYDcDeDivUpdStat(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static uint32 Clock_Ip_GetDividerValueCgmXSlcYDcDeDivUpdStat(void)
{
    return 0U;
}
static uint32 Clock_Ip_GetMinimumDividerValueCgmXSlcYDcDeDivUpdStat(void)
{
    return 0U;
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_DividerCallbackType Clock_Ip_axDividerCallbacks[CLOCK_IP_DIVIDER_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackDividerEmptyName,                     /* SetName */
        &Clock_Ip_CallbackDividerEmpty1,                        /* Reset */
        &Clock_Ip_CallbackDividerEmpty4,                        /* SetOptionalParameter */
        &Clock_Ip_CallbackDividerEmpty5,                        /* Set */
        &Clock_Ip_CallbackDividerEmpty3,                        /* GetStatus */
        &Clock_Ip_CallbackDividerEmpty2,                        /* GetDividerValue */
        &Clock_Ip_CallbackDividerEmpty2,                        /* GetMinimumDividerValue */
    },
#ifdef CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_POSTDIV
    {
        &Clock_Ip_SetNamePlldivOutputDividerPostdiv,                            /* SetName */
        &Clock_Ip_ResetPlldivOutputDividerPostdiv,                              /* Reset */
        &Clock_Ip_SetOptionalParameterPlldivOutputDividerPostdiv,               /* SetOptionalParameter */
        &Clock_Ip_SetPlldivOutputDividerPostdiv,                                /* Set */
        &Clock_Ip_GetStatusPlldivOutputDividerPostdiv,                          /* GetStatus */
        &Clock_Ip_GetDividerValuePlldivOutputDividerPostdiv,                    /* GetDividerValue */
        &Clock_Ip_GetMinimumDividerValuePlldivOutputDividerPostdiv,             /* GetMinimumDividerValue */
    },
#endif
#ifdef CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_DE_OUTPUT_DIV
    {
        &Clock_Ip_SetNamePlldivOutputDividerDeOutputDiv,                            /* SetName */
        &Clock_Ip_ResetPlldivOutputDividerDeOutputDiv,                              /* Reset */
        &Clock_Ip_SetOptionalParameterPlldivOutputDividerDeOutputDiv,               /* SetOptionalParameter */
        &Clock_Ip_SetPlldivOutputDividerDeOutputDiv,                                /* Set */
        &Clock_Ip_GetStatusPlldivOutputDividerDeOutputDiv,                          /* GetStatus */
        &Clock_Ip_GetDividerValuePlldivOutputDividerDeOutputDiv,                    /* GetDividerValue */
        &Clock_Ip_GetMinimumDividerValuePlldivOutputDividerDeOutputDiv,             /* GetMinimumDividerValue */
    },
#endif
#ifdef CLOCK_IP_CGM_X_SLC_Y_DC_DE_DIV_UPD_STAT
    {
        &Clock_Ip_SetNameCgmXSlcYDcDeDivUpdStat,                            /* SetName */
        &Clock_Ip_ResetCgmXSlcYDcDeDivUpdStat,                              /* Reset */
        &Clock_Ip_SetOptionalParameterCgmXSlcYDcDeDivUpdStat,               /* SetOptionalParameter */
        &Clock_Ip_SetCgmXSlcYDcDeDivUpdStat,                                /* Set */
        &Clock_Ip_GetStatusCgmXSlcYDcDeDivUpdStat,                          /* GetStatus */
        &Clock_Ip_GetDividerValueCgmXSlcYDcDeDivUpdStat,                    /* GetDividerValue */
        &Clock_Ip_GetMinimumDividerValueCgmXSlcYDcDeDivUpdStat,             /* GetMinimumDividerValue */
    },
#endif

};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

