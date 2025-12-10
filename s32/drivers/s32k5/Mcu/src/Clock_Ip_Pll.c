/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Pll.c
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
#define CLOCK_IP_PLL_VENDOR_ID_C                      43
#define CLOCK_IP_PLL_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PLL_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_PLL_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PLL_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_PLL_SW_MINOR_VERSION_C               8
#define CLOCK_IP_PLL_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PLL_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Pll.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PLL_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PLL_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PLL_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Pll.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PLL_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PLL_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PLL_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Pll.c and Clock_Ip_Private.h are different"
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

static Clock_Ip_NameType Clock_Ip_PllName = RESERVED_CLK;

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

static void Clock_Ip_CallbackPllEmptyName(Clock_Ip_NameType PllName);
static void Clock_Ip_CallbackPllEmpty1(void);
static void Clock_Ip_CallbackPllEmpty2(ClockLLD_PllParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_CallbackPllEmpty3(Clock_Ip_NameType InputReferenceName,uint32 PredividerValue,float MultiplierValue,uint32 PostdividerValue);
static ClockLLD_StatusReturnType Clock_Ip_CallbackPllEmpty4(void);
static uint32 Clock_Ip_CallbackPllEmpty5(Clock_Ip_NameType (*InputReferences)[]);
static uint32 Clock_Ip_CallbackPllEmpty6(Clock_Ip_NameType (*DividerChildren)[]);
static uint32 Clock_Ip_CallbackPllEmpty7(void);

#ifdef CLOCK_IP_PLL_POWERUP_RDIV_MFI_ENABLE_SPREADCTL_STEP_STOP_MFN_REF_CLK_SEL
static void Clock_Ip_SetNamePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType Name);
static void Clock_Ip_ResetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void);
static void Clock_Ip_SetOptionalParameterPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(ClockLLD_PllParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType InputReferenceName,uint32 PredividerValue,float MultiplierValue,uint32 PostdividerValue);
static void Clock_Ip_EnablePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void);
static void Clock_Ip_WaitPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void);
static void Clock_Ip_LockPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType InputReferenceName,uint32 PredividerValue,float MultiplierValue,uint32 PostdividerValue);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void);
static uint32 Clock_Ip_GetInputReferencesPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType (*InputReferences)[]);
static uint32 Clock_Ip_GetDividerChildrenPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType (*DividerChildren)[]);
static uint32 Clock_Ip_GetMaximumPredividerValuePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void);
static uint32 Clock_Ip_GetMaximumDenominatorValuePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void);
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


static void Clock_Ip_CallbackPllEmptyName(Clock_Ip_NameType PllName)
{
    (void)PllName;
    /* No implementation */
}
static void Clock_Ip_CallbackPllEmpty1(void)
{
    /* No implementation */
}
static void Clock_Ip_CallbackPllEmpty2(ClockLLD_PllParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_CallbackPllEmpty3(Clock_Ip_NameType InputReferenceName,uint32 PredividerValue,float MultiplierValue,uint32 PostdividerValue)
{
    (void)InputReferenceName;
    (void)PredividerValue;
    (void)MultiplierValue;
    (void)PostdividerValue;
    /* No implementation */
}
static ClockLLD_StatusReturnType Clock_Ip_CallbackPllEmpty4(void)
{
    /* No implementation */
    return CLOCK_LLD_PLL_LOCKED_STATUS;
}
static uint32 Clock_Ip_CallbackPllEmpty5(Clock_Ip_NameType (*InputReferences)[])
{
    (void)InputReferences;
    /* No implementation */
    return 0U;
}
static uint32 Clock_Ip_CallbackPllEmpty6(Clock_Ip_NameType (*DividerChildren)[])
{
    (void)DividerChildren;
    /* No implementation */
    return 0U;
}
static uint32 Clock_Ip_CallbackPllEmpty7(void)
{
    /* No implementation */
    return 0U;
}

#ifdef CLOCK_IP_PLL_POWERUP_RDIV_MFI_ENABLE_SPREADCTL_STEP_STOP_MFN_REF_CLK_SEL
#ifndef CLOCK_IP_FIRC_PLL_REFERENCE
    #define CLOCK_IP_FIRC_PLL_REFERENCE 0U
#endif
#ifndef CLOCK_IP_FXOSC_PLL_REFERENCE
    #define CLOCK_IP_FXOSC_PLL_REFERENCE 1U
#endif
#ifndef CLOCK_IP_DENOMINATOR_VALUE
    #define CLOCK_IP_DENOMINATOR_VALUE 18432U
#endif
static void Clock_Ip_SetNamePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType Name)
{
    Clock_Ip_PllName = Name;
}

static void Clock_Ip_ResetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void)
{
    uint32 Instance = 0U;
    uint32 RegValue;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case CLOCK_IP_HAS_PLL0_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case CLOCK_IP_HAS_PLL1_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CLOCK_IP_HAS_CPE_PLL_CLK:
        {
            Instance = 2U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }

    /* Power down PLL */
    RegValue = Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW;
    RegValue &= ~PLL_CTRL_CLKMUX_EN_MASK;   /* Disable Clk Mux */
    RegValue &= ~PLL_CTRL_POWERUP_MASK;     /* Disable PLL */
    Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW = RegValue;
}

static void Clock_Ip_SetOptionalParameterPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(ClockLLD_PllParameterIdentifierType ParamId, uint32 Value)
{
    uint32 RegValue;
    uint32 Instance = 0U;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case CLOCK_IP_HAS_PLL0_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case CLOCK_IP_HAS_PLL1_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CLOCK_IP_HAS_CPE_PLL_CLK:
        {
            Instance = 2U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }


    switch(ParamId)
    {
        case CLOCK_LLD_PLL_MODULATION_TYPE_ID:
        {
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->SPREAD_SPECTRUM.RW;
            RegValue &= ~PLL_SPREAD_SPECTRUM_ENABLE_MASK;
            RegValue |= PLL_SPREAD_SPECTRUM_ENABLE(Value);
            Clock_Ip_apxPll[Instance].PllInstance->SPREAD_SPECTRUM.RW = RegValue;

        }
        break;
        case CLOCK_LLD_PLL_MODULATION_TYPE_SELECTION_ID:
        {
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW;
            RegValue &= ~PLL_CTRL_SPREADCTL_MASK;
            RegValue |= PLL_CTRL_SPREADCTL(Value);
            Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW = RegValue;
        }
        break;
        case CLOCK_LLD_PLL_MODULATION_STEP_SIZE_ID:
        {
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->SPREAD_SPECTRUM.RW;
            RegValue &= ~PLL_SPREAD_SPECTRUM_STEP_MASK;
            RegValue |= PLL_SPREAD_SPECTRUM_STEP(Value);
            Clock_Ip_apxPll[Instance].PllInstance->SPREAD_SPECTRUM.RW = RegValue;

        }
        break;
        case CLOCK_LLD_PLL_MODULATION_STEP_NO_ID:
        {
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->SPREAD_SPECTRUM.RW;
            RegValue &= ~PLL_SPREAD_SPECTRUM_STOP_MASK;
            RegValue |= PLL_SPREAD_SPECTRUM_STOP(Value);
            Clock_Ip_apxPll[Instance].PllInstance->SPREAD_SPECTRUM.RW = RegValue;

        }
        break;
        case CLOCK_LLD_PLL_MULTIPHASE_SDM_ID:
        {
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW;
            RegValue &= ~PLL_CTRL_MULTIPHASE_SDM_DISABLE_MASK;
            RegValue |= PLL_CTRL_MULTIPHASE_SDM_DISABLE(Value);
            Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW = RegValue;

        }
        break;
        default:
        {
            /* Invalid parameter type */
        }
    }
}

static void Clock_Ip_SetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(
    Clock_Ip_NameType InputReferenceName,
    uint32 PredividerValue,
    float MultiplierValue,
    uint32 PostdividerValue
    )
{
    uint32 RegValue;
    uint32 Instance = 0U;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case CLOCK_IP_HAS_PLL0_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case CLOCK_IP_HAS_PLL1_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CLOCK_IP_HAS_CPE_PLL_CLK:
        {
            Instance = 2U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }


    (void)PostdividerValue;

    /* Name of the input reference clock */
    switch (InputReferenceName)
    {
        case FIRC_CLK:
            /* Select input reference. */
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW;
            RegValue &= ~PLL_CTRL_REF_CLK_SEL_MASK;
            RegValue |= PLL_CTRL_REF_CLK_SEL(CLOCK_IP_FIRC_PLL_REFERENCE);
            Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW = RegValue;
            break;
        case FXOSC_CLK:
            /* Select input reference. */
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW;
            RegValue &= ~PLL_CTRL_REF_CLK_SEL_MASK;
            RegValue |= PLL_CTRL_REF_CLK_SEL(CLOCK_IP_FXOSC_PLL_REFERENCE);
            Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW = RegValue;
            break;
        default:
            /* Command is not implemented on this platform */
            break;
    }

    /* Configure PLL: predivider and multiplier */
    RegValue = Clock_Ip_apxPll[Instance].PllInstance->DIV.RW;
    RegValue &= ~(PLL_DIV_RDIV_MASK | PLL_DIV_MFI_MASK);
    RegValue |= (uint32) (PLL_DIV_RDIV(PredividerValue)   |
                       PLL_DIV_MFI((int)(((int)(MultiplierValue * CLOCK_IP_DENOMINATOR_VALUE)) / CLOCK_IP_DENOMINATOR_VALUE)));
    Clock_Ip_apxPll[Instance].PllInstance->DIV.RW = RegValue;

    Clock_Ip_apxPll[Instance].PllInstance->DENOMINATOR.RW = PLL_DENOMINATOR_MFD(CLOCK_IP_DENOMINATOR_VALUE);

    Clock_Ip_apxPll[Instance].PllInstance->NUMERATOR.RW = PLL_NUMERATOR_MFN(((int)(MultiplierValue * CLOCK_IP_DENOMINATOR_VALUE)) % CLOCK_IP_DENOMINATOR_VALUE);
}

static void Clock_Ip_EnablePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel()
{
    uint32 RegValue;
    uint32 Instance = 0U;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case CLOCK_IP_HAS_PLL0_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case CLOCK_IP_HAS_PLL1_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CLOCK_IP_HAS_CPE_PLL_CLK:
        {
            Instance = 2U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }


    /* Generate LOL signal */
    Clock_Ip_apxPll[Instance].PllInstance->PLL_STATUS |= PLL_PLL_STATUS_PLL_LOL_MASK;

    /* Send command to enable PLL device. */
    RegValue = Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW;
    RegValue |= PLL_CTRL_CLKMUX_EN_MASK;
    RegValue |= PLL_CTRL_POWERUP_MASK;
    Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW = RegValue;
}

static void Clock_Ip_WaitPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 PllLockStatus;
    uint32 Instance = 0U;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case CLOCK_IP_HAS_PLL0_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case CLOCK_IP_HAS_PLL1_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CLOCK_IP_HAS_CPE_PLL_CLK:
        {
            Instance = 2U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }


    if (0U != (Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW & PLL_CTRL_POWERUP_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until this pll is locked */
        do
        {
            PllLockStatus = ((Clock_Ip_apxPll[Instance].PllInstance->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) >> PLL_PLL_STATUS_PLL_LOCK_SHIFT);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == PllLockStatus) && (FALSE == TimeoutOccurred));

        if (TRUE == TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_PllName);
        }
    }
}

static void Clock_Ip_LockPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(
    Clock_Ip_NameType InputReferenceName,
    uint32 PredividerValue,
    float MultiplierValue,
    uint32 PostdividerValue
    )
{
    Clock_Ip_SetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(
        InputReferenceName,
        PredividerValue,
        MultiplierValue,
        PostdividerValue
    );
    Clock_Ip_EnablePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel();
    Clock_Ip_WaitPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel();
}

static ClockLLD_StatusReturnType Clock_Ip_GetStatusPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void)
{
    ClockLLD_StatusReturnType PllStatus = CLOCK_LLD_PLL_LOCKED_STATUS;
    uint32 PllLockStatus;
    uint32 Instance = 0U;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case CLOCK_IP_HAS_PLL0_CLK:
        {
            Instance = 0U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case CLOCK_IP_HAS_PLL1_CLK:
        {
            Instance = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CLOCK_IP_HAS_CPE_PLL_CLK:
        {
            Instance = 2U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }


    /* Check whether pll was enabled */
    if (0U == (Clock_Ip_apxPll[Instance].PllInstance->CTRL.RW & PLL_CTRL_POWERUP_MASK))
    {
        PllStatus = CLOCK_LLD_PLL_NOT_ENABLED_STATUS;
    }
    else
    {
        PllLockStatus = ((Clock_Ip_apxPll[Instance].PllInstance->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) >> PLL_PLL_STATUS_PLL_LOCK_SHIFT);

        if (0U == PllLockStatus)
        {
            PllStatus = CLOCK_LLD_PLL_UNLOCKED_STATUS;
        }
    }

    return PllStatus;
}


static uint32 Clock_Ip_GetInputReferencesPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType (*InputReferences)[])
{
    (*InputReferences)[0] = FXOSC_CLK;
    return 1U;
}

static uint32 Clock_Ip_GetDividerChildrenPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(Clock_Ip_NameType (*DividerChildren)[])
{
    uint32 DividerChildrenNo = 0U;

    switch (Clock_Ip_PllName)
    {
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
        case COREPLL_VCO_CLK:
        break;
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
        case PERIPHPLL_VCO_CLK:
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
        case PLL0_CLK:
        {
            (*DividerChildren)[0] = PLL0_DIV0_CLK;
            (*DividerChildren)[1] = PLL0_DIV4_CLK;
            (*DividerChildren)[2] = PLL0_DFS0_CLK;
            (*DividerChildren)[3] = PLL0_DFS1_CLK;
            (*DividerChildren)[4] = PLL0_DFS2_CLK;
            (*DividerChildren)[5] = PLL0_DFS3_CLK;
            DividerChildrenNo = 6U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
        case PLL1_CLK:
        {
            (*DividerChildren)[0] = PLL1_DIV0_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
        case CPE_PLL_CLK:
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }
    return DividerChildrenNo;
}

static uint32 Clock_Ip_GetMaximumPredividerValuePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void)
{
    return 7U;
}

static uint32 Clock_Ip_GetMaximumDenominatorValuePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel(void)
{
    return 65535U;
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
const Clock_Ip_PllCallbackType Clock_Ip_axPllCallbacks[CLOCK_IP_PLL_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackPllEmptyName,              /* Name */
        &Clock_Ip_CallbackPllEmpty1,                /* Reset */
        &Clock_Ip_CallbackPllEmpty1,                /* Disable */
        &Clock_Ip_CallbackPllEmpty2, /* SetOptionalParameter */
        &Clock_Ip_CallbackPllEmpty3,                  /* Set */
        &Clock_Ip_CallbackPllEmpty1,               /* Start */
        &Clock_Ip_CallbackPllEmpty1,               /* Enable */
        &Clock_Ip_CallbackPllEmpty1,                 /* Wait */
        &Clock_Ip_CallbackPllEmpty3,                 /* Lock */
        &Clock_Ip_CallbackPllEmpty4,            /* GetStatus */
        &Clock_Ip_CallbackPllEmpty5,   /* GetInputReferences */
        &Clock_Ip_CallbackPllEmpty6,   /* GetDividerChildren */
        &Clock_Ip_CallbackPllEmpty7,   /* GetMaximumPredividerValue */
        &Clock_Ip_CallbackPllEmpty7,   /* GetMaximumDenominatorValue */
    },
#ifdef CLOCK_IP_PLL_POWERUP_RDIV_MFI_ENABLE_SPREADCTL_STEP_STOP_MFN_REF_CLK_SEL
    {
        &Clock_Ip_SetNamePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,              /* Name */
        &Clock_Ip_ResetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,                /* Reset */
        &Clock_Ip_ResetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,                /* Disable */
        &Clock_Ip_SetOptionalParameterPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel, /* SetOptionalParameter */
        &Clock_Ip_SetPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,                  /* Set */
        &Clock_Ip_EnablePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,               /* Start */
        &Clock_Ip_EnablePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,               /* Enable */
        &Clock_Ip_WaitPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,                 /* Wait */
        &Clock_Ip_LockPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,                 /* Lock */
        &Clock_Ip_GetStatusPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,            /* GetStatus */
        &Clock_Ip_GetInputReferencesPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,   /* GetInputReferences */
        &Clock_Ip_GetDividerChildrenPllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,   /* GetDividerChildren */
        &Clock_Ip_GetMaximumPredividerValuePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,   /* GetMaximumPredividerValue */
        &Clock_Ip_GetMaximumDenominatorValuePllPowerupRdivMfiMfnEnableSpreadctlStepStopRefClkSel,   /* GetMaximumDenominatorValue */
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

