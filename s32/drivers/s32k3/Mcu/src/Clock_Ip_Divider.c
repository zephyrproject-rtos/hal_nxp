/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Divider.c
*   @version    3.0.0
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
#define CLOCK_IP_DIVIDER_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_DIVIDER_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_DIVIDER_SW_MAJOR_VERSION_C               3
#define CLOCK_IP_DIVIDER_SW_MINOR_VERSION_C               0
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

static void Clock_Ip_Callback_DividerEmpty(Clock_Ip_DividerConfigType const* Config);
#ifdef CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE
static void Clock_Ip_SetCgmXDeDivStatWithoutPhase(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_PLL_PLL0DIV_DE_DIV_OUTPUT
static void Clock_Ip_SetPllPll0divDeDivOutput(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_PLL_PLLDV_ODIV2_OUTPUT
static void Clock_Ip_SetPllPlldvOdiv2Output(Clock_Ip_DividerConfigType const* Config);
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

static void Clock_Ip_Callback_DividerEmpty(Clock_Ip_DividerConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}

#ifdef CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE
static void Clock_Ip_SetCgmXDeDivStatWithoutPhase(Clock_Ip_DividerConfigType const* Config)
{
    uint32 Instance;
    uint32 SelectorIndex;
    uint32 DividerIndex;

    uint32 DividerMask;
    uint32 DividerShift;

    uint32 RegValue;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 DividerStatus;

    if (NULL_PTR != Config)
    {
        Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];
        SelectorIndex = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_SELECTOR_INDEX];
        DividerIndex  = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_DIVIDER_INDEX];
        DividerMask   = Clock_Ip_axFeatureExtensions[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_EXTENSION_INDEX]].DividerValueMask;
        DividerShift  = Clock_Ip_axFeatureExtensions[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_EXTENSION_INDEX]].DividerValueShift;

        /* Program divider value */
        if (Config->Value != 0U)
        {
            RegValue = Clock_Ip_apxCgm[Instance][SelectorIndex]->Divider[DividerIndex];
            RegValue &= ~DividerMask;
            RegValue |= (((Config->Value-1U) << DividerShift) & DividerMask);
            Clock_Ip_apxCgm[Instance][SelectorIndex]->Divider[DividerIndex] = RegValue;

        #ifdef CLOCK_IP_DIVIDER_HAVE_DIV_FMT
            if((Instance == 0U)  && (SelectorIndex == 2U) && (DividerIndex == 2U))
            {
                IP_MC_CGM_0->MUX_2_DC_2 &= ~MC_CGM_MUX_2_DC_2_DIV_FMT_MASK;
            }
            else if((Instance == 4U) && (SelectorIndex == 2U) && (DividerIndex == 2U))
            {
                IP_MC_CGM_4->MUX_2_DC_2 &= ~MC_CGM_MUX_2_DC_2_DIV_FMT_MASK;
            }
            else
            {
                /* Do nothing */
            }
        #endif
        }

        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait for acknowledge to be cleared. */
        do
        {
            DividerStatus = (Clock_Ip_apxCgm[Instance][SelectorIndex]->MUX_DIV_UPD_STAT & MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_PENDING == DividerStatus) && (FALSE == TimeoutOccurred));

        if (FALSE == TimeoutOccurred)
        {
            /* Enable or Disable the Clock Divider */
            if (Config->Value != 0U)
            {
                /* Enable divider */
                Clock_Ip_apxCgm[Instance][SelectorIndex]->Divider[DividerIndex] |= MC_CGM_MUX_DC_DE_MASK;
            }
            else
            {
                Clock_Ip_apxCgm[Instance][SelectorIndex]->Divider[DividerIndex] &= ~MC_CGM_MUX_DC_DE_MASK;
            }
        }
        else
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
        }
    }
    else
    {
        (void)Instance;
        (void)SelectorIndex;
        (void)DividerIndex;
        (void)DividerMask;
        (void)DividerShift;
        (void)RegValue;
        (void)TimeoutOccurred;
        (void)StartTime;
        (void)ElapsedTime;
        (void)TimeoutTicks;
        (void)DividerStatus;
    }
}
#endif

#ifdef CLOCK_IP_PLL_PLL0DIV_DE_DIV_OUTPUT
static void Clock_Ip_SetPllPll0divDeDivOutput(Clock_Ip_DividerConfigType const* Config)
{
    uint32 Instance;
    uint32 DividerIndex;
    uint32 RegValue;

    if (NULL_PTR != Config)
    {
        Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];
        DividerIndex  = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_DIVIDER_INDEX];
        /* Disable divider */
        CLOCK_IP_DEV_ASSERT(!(Clock_Ip_apxPll[Instance].PllInstance->PLLODIV[DividerIndex] & PLL_PLLODIV_DE_MASK));
        /* Check if divider is enabled */
        if (Config->Value != 0U)
        {
            RegValue = Clock_Ip_apxPll[Instance].PllInstance->PLLODIV[DividerIndex];
            RegValue |= PLL_PLLODIV_DE_MASK;
            RegValue &= ~PLL_PLLODIV_DIV_MASK;
            RegValue |= PLL_PLLODIV_DIV(Config->Value - 1U);
            Clock_Ip_apxPll[Instance].PllInstance->PLLODIV[DividerIndex] = RegValue;
        }
    }
    else
    {
        (void)Instance;
        (void)DividerIndex;
        (void)RegValue;
    }
}
#endif

#ifdef CLOCK_IP_PLL_PLLDV_ODIV2_OUTPUT
/* Set Pll Odiv2 configuration to register */
static void Clock_Ip_SetPllPlldvOdiv2Output(Clock_Ip_DividerConfigType const* Config)
{
    uint32 Instance;
    uint32 RegValue;
    uint32 DividerValue;

    if (NULL_PTR != Config)
    {
        Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];
        DividerValue = (Config->Value != 0U) ? Config->Value : 1U;

        RegValue = Clock_Ip_apxPll[Instance].PllInstance->PLLDV;
        RegValue &= ~PLL_PLLDV_ODIV2_MASK;
        RegValue |= PLL_PLLDV_ODIV2(DividerValue);
        Clock_Ip_apxPll[Instance].PllInstance->PLLDV = RegValue;
    }
    else
    {
        (void)Instance;
        (void)RegValue;
        (void)DividerValue;
    }
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
        Clock_Ip_Callback_DividerEmpty,                  /* Set */
    },
#ifdef CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE
    {
        Clock_Ip_SetCgmXDeDivStatWithoutPhase,           /* Set */
    },
#endif
#ifdef CLOCK_IP_PLL_PLL0DIV_DE_DIV_OUTPUT
    {
        Clock_Ip_SetPllPll0divDeDivOutput,              /* Set */
    },
#endif /* CLOCK_IP_PLL_PLL0DIV_DE_DIV_OUTPUT */
#ifdef CLOCK_IP_PLL_PLLDV_ODIV2_OUTPUT
    {
        Clock_Ip_SetPllPlldvOdiv2Output,              /* Set */
    },
#endif /* CLOCK_IP_PLL_PLLDV_ODIV2_OUTPUT */

};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
