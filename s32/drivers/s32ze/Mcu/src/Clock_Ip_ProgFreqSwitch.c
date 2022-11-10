/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file       Clock_Ip_ProgFreqSwitch.c
*   @version    0.9.0
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
#define CLOCK_IP_PROGFREQSWITCH_VENDOR_ID_C                      43
#define CLOCK_IP_PROGFREQSWITCH_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PROGFREQSWITCH_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_PROGFREQSWITCH_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PROGFREQSWITCH_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_PROGFREQSWITCH_SW_MINOR_VERSION_C               9
#define CLOCK_IP_PROGFREQSWITCH_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_ProgFreqSwitch.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PROGFREQSWITCH_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_ProgFreqSwitch.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_ProgFreqSwitch.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PROGFREQSWITCH_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PROGFREQSWITCH_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PROGFREQSWITCH_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_ProgFreqSwitch.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_ProgFreqSwitch.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PROGFREQSWITCH_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PROGFREQSWITCH_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PROGFREQSWITCH_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_ProgFreqSwitch.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#ifdef CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS
/* Pcfs settings that are dependent on device */
#define CLOCK_IP_A_MAX_SIZE 6U

/* microA per MHz */
#define CLOCK_IP_DYNAMIC_IDD_CHANGE 2360U

#define CLOCK_IP_DIVIDE_BY_1000000                              1000000U
#define CLOCK_IP_DIVIDE_BY_100000                               100000U
#define CLOCK_IP_CONSTANT_2048000                               (1024U * 2000U)
#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS
static const uint32 AMax[CLOCK_IP_A_MAX_SIZE] = {0U,5U,10U,15U,20U,100U};
static const uint32 PcfsRate[CLOCK_IP_A_MAX_SIZE] = {0U,12U,48U,112U,184U,1000U};
#endif

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS
static uint32 HashPfs[CLOCK_IP_PCFS_NO];
#endif

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


static void Clock_Ip_ProgressiveFrequencyClockSwitchEmpty(Clock_Ip_PcfsConfigType const* Config, uint32 Index);
#ifdef CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS
static void Clock_Ip_CgmXPcfsSdurDivcDiveDivs(Clock_Ip_PcfsConfigType const *Config, uint32 CfgIndex);
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

static void Clock_Ip_ProgressiveFrequencyClockSwitchEmpty(Clock_Ip_PcfsConfigType const* Config, uint32 Index)
{
    (void)Config;
    (void)Index;
    /* No implementation */
}

#ifdef CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS
static void Clock_Ip_CgmXPcfsSdurDivcDiveDivs(Clock_Ip_PcfsConfigType const *Config, uint32 CfgIndex)
{
    volatile Clock_Ip_CgmPcfsType* CgmPcfsBase  = Clock_Ip_apxCgmPcfs[Clock_Ip_au8ClockFeatures[Config->SelectorName][CLOCK_IP_MODULE_INSTANCE]];
    uint32 HwIndex                       = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_PCFS_INDEX];

    uint32 Finput = 0U;
    uint32 Fsafe = 0U;
    uint32 AmaxBrut;
    uint32 Rate = 0U;
    uint32 Index;
    uint32 Var1;
    uint32 Var2;
    uint32 Var3;
    uint32 K;

    uint32 Sdur;
    uint32 DivcInit;
    uint32 DivcRate;
    uint32 DivStartValue;
    uint32 DivEndValue;

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
        CLOCK_IP_DEV_ASSERT(Config->SelectorName != RESERVED_CLK);
#endif

    if (HashPfs[CfgIndex] != ((((uint32)Config->ClockSourceFrequency) ^ ((uint32)Config->MaxAllowableIDDchange) ^ ((uint32)Config->Name)  ^ ((uint32)Config->SelectorName) ^ ((uint32)Config->StepDuration))))
    {
        HashPfs[CfgIndex] = ((((uint32)Config->ClockSourceFrequency) ^ ((uint32)Config->MaxAllowableIDDchange) ^ ((uint32)Config->Name)  ^ ((uint32)Config->SelectorName) ^ ((uint32)Config->StepDuration)));

        Finput = Config->ClockSourceFrequency / CLOCK_IP_DIVIDE_BY_1000000;
    #if defined(CLOCK_IP_HAS_FIRC_CLK)
        Fsafe = Clock_Ip_pxConfig->ConfiguredFrequencies[Clock_Ip_FreqIds[FIRC_CLK]].ConfiguredFrequencyValue / CLOCK_IP_DIVIDE_BY_1000000;
        
        
    #endif

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
        CLOCK_IP_DEV_ASSERT(Finput != 0U);
        CLOCK_IP_DEV_ASSERT(Fsafe != 0U);
        CLOCK_IP_DEV_ASSERT(Config->MaxAllowableIDDchange != 0U);
        CLOCK_IP_DEV_ASSERT(Config->StepDuration != 0U);
#endif

        /* Calculate amax=fchg/Finput */
        AmaxBrut = (Config->MaxAllowableIDDchange * Config->StepDuration * CLOCK_IP_DIVIDE_BY_100000 / (Finput * CLOCK_IP_DYNAMIC_IDD_CHANGE));
        Rate = AmaxBrut;

        /* Round pcfs rate by rounding amax */
        if (AmaxBrut < AMax[0U])
        {
            Rate = PcfsRate[0U];
        }
        else if (AmaxBrut > AMax[CLOCK_IP_A_MAX_SIZE-1U])
        {
            Rate = PcfsRate[CLOCK_IP_A_MAX_SIZE-1U];
        }
        else
        {
            for (Index = 1U; Index < (uint8)CLOCK_IP_A_MAX_SIZE; Index++)
            {
                if (AMax[Index-1U] < AmaxBrut)
                {
                    Rate = PcfsRate[Index];
                }
            }
        }

        /* Calculate K by using formula k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Finput/fsafe)) / Rate))) */

        Var1 = 256U + ((CLOCK_IP_CONSTANT_2048000 * Finput) / (Fsafe * Rate)) - (CLOCK_IP_CONSTANT_2048000 / Rate);
        Var2 = 1UL << 30U;   /* The second-to-top bit is set: use 1u << 14 for uint16 type; use 1uL<<30 for uint32 type  */
        Var3 = 0U;

        /* Implement sqrt from K formula by using a square-root computing in embedded C */

        /* "one" starts at the highest power of four <= than the argument */
        while (Var2 > Var1)
        {
            Var2 = Var2 >> 2;
        }
        /* Implement sqrt from K formula by using a square-root computing in embedded C */

        while (Var2 != 0U)
        {
            if (Var1 >= (Var3 + Var2))
            {
                Var1 = Var1 - (Var3 + Var2);
                Var3 = Var3 + (Var2 << 1U);
            }

            Var3 = Var3 >> 1U;
            Var2 = Var2 >> 2U;
        }

        K = (64U + 127U + (Var3 << 2U)) >> 7U;   /* Calculated K from k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Fi/Fsafe)) / Rate))) */

        Sdur = Config->StepDuration * Fsafe;
        DivcInit = Rate * K;
        DivcRate = Rate;
        DivStartValue = 999U + ((Rate * K * (K+1U)) >> 1U);
        DivEndValue = (Finput * 1000U / Fsafe) - 1U;

        /* Configure pcfs registers */
        CgmPcfsBase->PCFS_SDUR = MC_CGM_PCFS_SDUR_SDUR(Sdur);
        CgmPcfsBase->PCFS[HwIndex].DIVC = MC_CGM_PCFS_DIVC_RATE(DivcRate) | MC_CGM_PCFS_DIVC_INIT(DivcInit);
        CgmPcfsBase->PCFS[HwIndex].DIVE = MC_CGM_PCFS_DIVE_DIVE(DivEndValue);
        CgmPcfsBase->PCFS[HwIndex].DIVS = MC_CGM_PCFS_DIVS_DIVS(DivStartValue);
    }
}
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_PcfsCallbackType Clock_Ip_axPcfsCallbacks[CLOCK_IP_PCFS_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_ProgressiveFrequencyClockSwitchEmpty,     /* Set */

    },
#ifdef CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS
    {
        Clock_Ip_CgmXPcfsSdurDivcDiveDivs,              /* Set */
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
