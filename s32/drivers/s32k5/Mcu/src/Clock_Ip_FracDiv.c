/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_FracDiv.c
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
#define CLOCK_IP_FRACDIV_VENDOR_ID_C                      43
#define CLOCK_IP_FRACDIV_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_FRACDIV_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_FRACDIV_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_FRACDIV_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_FRACDIV_SW_MINOR_VERSION_C               8
#define CLOCK_IP_FRACDIV_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_FracDiv.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_FRACDIV_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_FracDiv.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_FracDiv.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_FRACDIV_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_FRACDIV_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_FRACDIV_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_FracDiv.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_FracDiv.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_FRACDIV_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_FRACDIV_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_FRACDIV_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_FracDiv.c and Clock_Ip_Private.h are different"
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

static Clock_Ip_NameType Clock_Ip_FracDivName = RESERVED_CLK;

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


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_CallbackDfsEmptyName(Clock_Ip_NameType PllName);
static void Clock_Ip_CallbackDfsEmpty1(void);
static void Clock_Ip_CallbackDfsEmpty2(ClockLLD_FracDivParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_CallbackDfsEmpty3(float DivisionValue);
static ClockLLD_StatusReturnType Clock_Ip_CallbackDfsEmpty4(void);
#ifdef CLOCK_IP_DFS_BYPASS_CLKOUT_ENABLE_MFI_MFN
static void Clock_Ip_SetNameDfsBypassClkoutEnableMfiMfn(Clock_Ip_NameType Name);
static void Clock_Ip_ResetDfsBypassClkoutEnableMfiMfn(void);
static void Clock_Ip_SetOptionalParameterDfsBypassClkoutEnableMfiMfn(ClockLLD_FracDivParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetDfsBypassClkoutEnableMfiMfn(float DivisionValue);
static void Clock_Ip_EnableDfsBypassClkoutEnableMfiMfn(void);
static void Clock_Ip_WaitDfsBypassClkoutEnableMfiMfn(void);
static void Clock_Ip_LockDfsBypassClkoutEnableMfiMfn(float DivisionValue);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusDfsBypassClkoutEnableMfiMfn(void);
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_CallbackDfsEmptyName(Clock_Ip_NameType DfsName)
{
    (void)DfsName;
    /* No implementation */
}
static void Clock_Ip_CallbackDfsEmpty1(void)
{
    /* No implementation */
}
static void Clock_Ip_CallbackDfsEmpty2(ClockLLD_FracDivParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_CallbackDfsEmpty3(float DivisionValue)
{
    (void)DivisionValue;
    /* No implementation */
}
static ClockLLD_StatusReturnType Clock_Ip_CallbackDfsEmpty4(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}

#ifdef CLOCK_IP_DFS_BYPASS_CLKOUT_ENABLE_MFI_MFN
static void Clock_Ip_SetNameDfsBypassClkoutEnableMfiMfn(Clock_Ip_NameType Name)
{
    Clock_Ip_FracDivName = Name;
}
static void Clock_Ip_ResetDfsBypassClkoutEnableMfiMfn(void)
{
    switch (Clock_Ip_FracDivName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_DFS0_CLK)
        case COREPLL_DFS0_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_0.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS1_CLK)
        case COREPLL_DFS1_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_1.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS2_CLK)
        case COREPLL_DFS2_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_2.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS3_CLK)
        case COREPLL_DFS3_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_3.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS0_CLK)
        case PERIPHPLL_DFS0_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_0.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
        case PERIPHPLL_DFS1_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_1.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
        case PERIPHPLL_DFS2_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_2.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS3_CLK)
        case PERIPHPLL_DFS3_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_3.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS0_CLK)
        case PLL0_DFS0_CLK:
        {
            IP_PLL_0->DFS_CTRL_0.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
        case PLL0_DFS1_CLK:
        {
            IP_PLL_0->DFS_CTRL_1.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
        case PLL0_DFS2_CLK:
        {
            IP_PLL_0->DFS_CTRL_2.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
        case PLL0_DFS3_CLK:
        {
            IP_PLL_0->DFS_CTRL_3.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS0_CLK)
        case PLL1_DFS0_CLK:
        {
            IP_PLL_1->DFS_CTRL_0.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS1_CLK)
        case PLL1_DFS1_CLK:
        {
            IP_PLL_1->DFS_CTRL_1.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS2_CLK)
        case PLL1_DFS2_CLK:
        {
            IP_PLL_1->DFS_CTRL_2.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS3_CLK)
        case PLL1_DFS3_CLK:
        {
            IP_PLL_1->DFS_CTRL_3.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS0_CLK)
        case CPEPLL_DFS0_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_0.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS1_CLK)
        case CPEPLL_DFS1_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_1.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS2_CLK)
        case CPEPLL_DFS2_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_2.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS3_CLK)
        case CPEPLL_DFS3_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_3.RW &= ~(PLL_DFS_CTRL_0_ENABLE_MASK | PLL_DFS_CTRL_0_CLKOUT_EN_MASK);
        }
        break;
#endif
        default:
        {
            /* Not supported */
        }
    }
}
static void Clock_Ip_SetOptionalParameterDfsBypassClkoutEnableMfiMfn(ClockLLD_FracDivParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_SetDfsBypassClkoutEnableMfiMfn(float DivisionValue)
{
    uint32 IntegerValue = (uint32)DivisionValue;
    uint32 NumeratorValue = 5U * (DivisionValue - ((float)IntegerValue));

    switch (Clock_Ip_FracDivName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_DFS0_CLK)
        case COREPLL_DFS0_CLK:
        {
            IP_CORE_PLL->DFS_DIV_0.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS1_CLK)
        case COREPLL_DFS1_CLK:
        {
            IP_CORE_PLL->DFS_DIV_1.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS2_CLK)
        case COREPLL_DFS2_CLK:
        {
            IP_CORE_PLL->DFS_DIV_2.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS3_CLK)
        case COREPLL_DFS3_CLK:
        {
            IP_CORE_PLL->DFS_DIV_3.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS0_CLK)
        case PERIPHPLL_DFS0_CLK:
        {
            IP_PERIPH_PLL->DFS_DIV_0.RW = PERIPH_PLL_DFS_DIV_0_MFI(IntegerValue) | PERIPH_PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
        case PERIPHPLL_DFS1_CLK:
        {
            IP_PERIPH_PLL->DFS_DIV_1.RW = PERIPH_PLL_DFS_DIV_0_MFI(IntegerValue) | PERIPH_PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
        case PERIPHPLL_DFS2_CLK:
        {
            IP_PERIPH_PLL->DFS_DIV_2.RW = PERIPH_PLL_DFS_DIV_0_MFI(IntegerValue) | PERIPH_PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS3_CLK)
        case PERIPHPLL_DFS3_CLK:
        {
            IP_PERIPH_PLL->DFS_DIV_3.RW = PERIPH_PLL_DFS_DIV_0_MFI(IntegerValue) | PERIPH_PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS0_CLK)
        case PLL0_DFS0_CLK:
        {
            IP_PLL_0->DFS_DIV_0.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
        case PLL0_DFS1_CLK:
        {
            IP_PLL_0->DFS_DIV_1.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
        case PLL0_DFS2_CLK:
        {
            IP_PLL_0->DFS_DIV_2.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
        case PLL0_DFS3_CLK:
        {
            IP_PLL_0->DFS_DIV_3.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS0_CLK)
        case PLL1_DFS0_CLK:
        {
            IP_PLL_1->DFS_DIV_0.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS1_CLK)
        case PLL1_DFS1_CLK:
        {
            IP_PLL_1->DFS_DIV_1.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS2_CLK)
        case PLL1_DFS2_CLK:
        {
            IP_PLL_1->DFS_DIV_2.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS3_CLK)
        case PLL1_DFS3_CLK:
        {
            IP_PLL_1->DFS_DIV_3.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS0_CLK)
        case CPEPLL_DFS0_CLK:
        {
            IP_PLL_CPE->DFS_DIV_0.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS1_CLK)
        case CPEPLL_DFS1_CLK:
        {
            IP_PLL_CPE->DFS_DIV_1.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS2_CLK)
        case CPEPLL_DFS2_CLK:
        {
            IP_PLL_CPE->DFS_DIV_2.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS3_CLK)
        case CPEPLL_DFS3_CLK:
        {
            IP_PLL_CPE->DFS_DIV_3.RW = PLL_DFS_DIV_0_MFI(IntegerValue) | PLL_DFS_DIV_0_MFN(NumeratorValue);
        }
        break;
#endif
        default:
        {
            /* Not supported */
        }
    }
}
static void Clock_Ip_EnableDfsBypassClkoutEnableMfiMfn()
{
    switch (Clock_Ip_FracDivName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_DFS0_CLK)
        case COREPLL_DFS0_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_0.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS1_CLK)
        case COREPLL_DFS1_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_1.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS2_CLK)
        case COREPLL_DFS2_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_2.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS3_CLK)
        case COREPLL_DFS3_CLK:
        {
            IP_CORE_PLL->DFS_CTRL_3.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS0_CLK)
        case PERIPHPLL_DFS0_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_0.RW = (PERIPH_PLL_DFS_CTRL_0_ENABLE(1U) | PERIPH_PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
        case PERIPHPLL_DFS1_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_1.RW = (PERIPH_PLL_DFS_CTRL_0_ENABLE(1U) | PERIPH_PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
        case PERIPHPLL_DFS2_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_2.RW = (PERIPH_PLL_DFS_CTRL_0_ENABLE(1U) | PERIPH_PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS3_CLK)
        case PERIPHPLL_DFS3_CLK:
        {
            IP_PERIPH_PLL->DFS_CTRL_3.RW = (PERIPH_PLL_DFS_CTRL_0_ENABLE(1U) | PERIPH_PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS0_CLK)
        case PLL0_DFS0_CLK:
        {
            IP_PLL_0->DFS_CTRL_0.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
        case PLL0_DFS1_CLK:
        {
            IP_PLL_0->DFS_CTRL_1.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
        case PLL0_DFS2_CLK:
        {
            IP_PLL_0->DFS_CTRL_2.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
        case PLL0_DFS3_CLK:
        {
            IP_PLL_0->DFS_CTRL_3.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS0_CLK)
        case PLL1_DFS0_CLK:
        {
            IP_PLL_1->DFS_CTRL_0.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS1_CLK)
        case PLL1_DFS1_CLK:
        {
            IP_PLL_1->DFS_CTRL_1.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS2_CLK)
        case PLL1_DFS2_CLK:
        {
            IP_PLL_1->DFS_CTRL_2.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS3_CLK)
        case PLL1_DFS3_CLK:
        {
            IP_PLL_1->DFS_CTRL_3.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS0_CLK)
        case CPEPLL_DFS0_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_0.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS1_CLK)
        case CPEPLL_DFS1_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_1.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS2_CLK)
        case CPEPLL_DFS2_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_2.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS3_CLK)
        case CPEPLL_DFS3_CLK:
        {
            IP_PLL_CPE->DFS_CTRL_3.RW = (PLL_DFS_CTRL_0_ENABLE(1U) | PLL_DFS_CTRL_0_CLKOUT_EN(1U));
        }
        break;
#endif
        default:
        {
            /* Not supported */
        }
    }
}
static void Clock_Ip_WaitDfsBypassClkoutEnableMfiMfn(void)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 DfsPortStatus;

    switch (Clock_Ip_FracDivName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_DFS0_CLK)
        case COREPLL_DFS0_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_CORE_PLL->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 0U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS1_CLK)
        case COREPLL_DFS1_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_CORE_PLL->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 1U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS2_CLK)
        case COREPLL_DFS2_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_CORE_PLL->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 2U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS3_CLK)
        case COREPLL_DFS3_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_CORE_PLL->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 3U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS0_CLK)
        case PERIPHPLL_DFS0_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PERIPH_PLL->DFS_STATUS & PERIPH_PLL_DFS_STATUS_DFS_OK_MASK >> PERIPH_PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 0U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
        case PERIPHPLL_DFS1_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PERIPH_PLL->DFS_STATUS & PERIPH_PLL_DFS_STATUS_DFS_OK_MASK >> PERIPH_PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 1U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
        case PERIPHPLL_DFS2_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PERIPH_PLL->DFS_STATUS & PERIPH_PLL_DFS_STATUS_DFS_OK_MASK >> PERIPH_PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 2U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS3_CLK)
        case PERIPHPLL_DFS3_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PERIPH_PLL->DFS_STATUS & PERIPH_PLL_DFS_STATUS_DFS_OK_MASK >> PERIPH_PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 3U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS0_CLK)
        case PLL0_DFS0_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 0U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
        case PLL0_DFS1_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 1U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
        case PLL0_DFS2_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 2U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
        case PLL0_DFS3_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 3U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS0_CLK)
        case PLL1_DFS0_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_1->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 0U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS1_CLK)
        case PLL1_DFS1_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_1->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 1U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS2_CLK)
        case PLL1_DFS2_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_1->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 2U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS3_CLK)
        case PLL1_DFS3_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_1->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 3U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS0_CLK)
        case CPEPLL_DFS0_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_CPE->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 0U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS1_CLK)
        case CPEPLL_DFS1_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_CPE->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 1U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS2_CLK)
        case CPEPLL_DFS2_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_CPE->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 2U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPEPLL_DFS3_CLK)
        case CPEPLL_DFS3_CLK:
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until this port is locked */
            do
            {
                DfsPortStatus = ((IP_PLL_CPE->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 3U));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == DfsPortStatus) && (FALSE == TimeoutOccurred));
        }
        break;
#endif
        default:
        {
            /* Not supported */
        }
    }
}
static void Clock_Ip_LockDfsBypassClkoutEnableMfiMfn(float DivisionValue)
{
    /* Set division value */
    Clock_Ip_SetDfsBypassClkoutEnableMfiMfn(DivisionValue);

    /* Enable/start dfs channel */
    Clock_Ip_EnableDfsBypassClkoutEnableMfiMfn();

    /* Wait for dfs channel to lock */
    Clock_Ip_WaitDfsBypassClkoutEnableMfiMfn();
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusDfsBypassClkoutEnableMfiMfn(void)
{
    return CLOCK_LLD_STATUS_SUCCESS;
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

const Clock_Ip_FracDivCallbackType Clock_Ip_axFracDivCallbacks[CLOCK_IP_FRACTIONAL_DIVIDER_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackDfsEmptyName,              /* Name */
        &Clock_Ip_CallbackDfsEmpty1,                /* Reset */
        &Clock_Ip_CallbackDfsEmpty1,                /* Disable */
        &Clock_Ip_CallbackDfsEmpty2, /* SetOptionalParameter */
        &Clock_Ip_CallbackDfsEmpty3,                  /* Set */
        &Clock_Ip_CallbackDfsEmpty1,               /* Start */
        &Clock_Ip_CallbackDfsEmpty1,               /* Enable */
        &Clock_Ip_CallbackDfsEmpty1,                 /* Wait */
        &Clock_Ip_CallbackDfsEmpty3,                 /* Lock */
        &Clock_Ip_CallbackDfsEmpty4,            /* GetStatus */
    },
#ifdef CLOCK_IP_DFS_BYPASS_CLKOUT_ENABLE_MFI_MFN
    {
        &Clock_Ip_SetNameDfsBypassClkoutEnableMfiMfn,              /* Name */
        &Clock_Ip_ResetDfsBypassClkoutEnableMfiMfn,                /* Reset */
        &Clock_Ip_ResetDfsBypassClkoutEnableMfiMfn,                /* Disable */
        &Clock_Ip_SetOptionalParameterDfsBypassClkoutEnableMfiMfn, /* SetOptionalParameter */
        &Clock_Ip_SetDfsBypassClkoutEnableMfiMfn,                  /* Set */
        &Clock_Ip_EnableDfsBypassClkoutEnableMfiMfn,               /* Start */
        &Clock_Ip_EnableDfsBypassClkoutEnableMfiMfn,               /* Enable */
        &Clock_Ip_WaitDfsBypassClkoutEnableMfiMfn,                 /* Wait */
        &Clock_Ip_LockDfsBypassClkoutEnableMfiMfn,                 /* Lock */
        &Clock_Ip_GetStatusDfsBypassClkoutEnableMfiMfn,            /* GetStatus */
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

