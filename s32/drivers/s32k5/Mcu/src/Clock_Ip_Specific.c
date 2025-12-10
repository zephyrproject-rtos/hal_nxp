/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Specific.c
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

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SPECIFIC_VENDOR_ID_C                      43
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_SPECIFIC_SW_MINOR_VERSION_C               8
#define CLOCK_IP_SPECIFIC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_SPECIFIC_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Specific.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Specific.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Specific.c and Clock_Ip_Private.h are different"
#endif

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Clock_Ip_Specific.c file and RegLockMacros.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.c and RegLockMacros.h are different"
    #endif
    #endif
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define DFS_DVPORT      (DFS_DVPORT_MFN(0u) | DFS_DVPORT_MFI(1U))
#define DFS_PORT_RESET  (DFS_PORTRESET_RESET0_MASK | DFS_PORTRESET_RESET1_MASK | DFS_PORTRESET_RESET2_MASK | DFS_PORTRESET_RESET3_MASK | DFS_PORTRESET_RESET4_MASK | DFS_PORTRESET_RESET5_MASK)

#define RTU0_CORE_CLK_MAX_FREQUENCY 900000000U
#define RTU0_CORE_CLK_THRESHOLD0_FREQUENCY (RTU0_CORE_CLK_MAX_FREQUENCY>>2U)
#define RTU0_CORE_CLK_THRESHOLD1_FREQUENCY (RTU0_CORE_CLK_THRESHOLD0_FREQUENCY*(2U))
#define RTU0_CORE_CLK_THRESHOLD2_FREQUENCY (RTU0_CORE_CLK_THRESHOLD0_FREQUENCY*(3U))

#define RTU1_CORE_CLK_MAX_FREQUENCY 900000000U
#define RTU1_CORE_CLK_THRESHOLD0_FREQUENCY (RTU1_CORE_CLK_MAX_FREQUENCY>>2U)
#define RTU1_CORE_CLK_THRESHOLD1_FREQUENCY (RTU1_CORE_CLK_THRESHOLD0_FREQUENCY*(2U))
#define RTU1_CORE_CLK_THRESHOLD2_FREQUENCY (RTU1_CORE_CLK_THRESHOLD0_FREQUENCY*(3U))

#define SMU_M33_CORE_CLK_MAX_FREQUENCY 400000000U
#define SMU_M33_CORE_CLK_THRESHOLD0_FREQUENCY (SMU_M33_CORE_CLK_MAX_FREQUENCY>>2U)
#define SMU_M33_CORE_CLK_THRESHOLD1_FREQUENCY (SMU_M33_CORE_CLK_THRESHOLD0_FREQUENCY*(2U))
#define SMU_M33_CORE_CLK_THRESHOLD2_FREQUENCY (SMU_M33_CORE_CLK_THRESHOLD0_FREQUENCY*(3U))

#define CE_M33_CORE_CLK_MAX_FREQUENCY 405000000U
#define CE_M33_CORE_CLK_THRESHOLD0_FREQUENCY (CE_M33_CORE_CLK_MAX_FREQUENCY>>2U)
#define CE_M33_CORE_CLK_THRESHOLD1_FREQUENCY (CE_M33_CORE_CLK_THRESHOLD0_FREQUENCY*(2U))
#define CE_M33_CORE_CLK_THRESHOLD2_FREQUENCY (CE_M33_CORE_CLK_THRESHOLD0_FREQUENCY*(3U))


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES

/* Clock start rom section code */
#define MCU_START_SEC_CODE_AC
#include "Mcu_MemMap.h"

static void SRAMController_SetRamIWS(uint32 SmuM33CoreClk_IwsSetting, uint32 Rtu0CoreClk_IwsSetting, uint32 Rtu1CoreClk_IwsSetting, uint32 CeM33CoreClk_IwsSetting);

/* Clock stop rom section code */
#define MCU_STOP_SEC_CODE_AC
#include "Mcu_MemMap.h"

#endif /* CLOCK_IP_HAS_RAM_WAIT_STATES */

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES

/* Function set ram wait states */
void Clock_Ip_SetRamWaitStates(void)
{
    uint32 Counter = 0x1000;
    /* Wait states have not yet supported,
       insert a delay . */
    do
    {
        Counter--;
    }
    while (Counter != 0U);
}
#endif

static void Clock_Ip_SpecificPlatformInitClock(Clock_Ip_ClockConfigType const * Config)
{
    /* No implementation */
    (void)Config;
}


void Clock_Ip_McMeEnterKey(void)
{
    /* No implementation */
}


#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
void Clock_Ip_SpecificSetUserAccessAllowed(void)
{
    /* CMU_AE SetUserAccessAllowed */
    #if (defined(IP_CMU_FC_AE_1_BASE))
    /* Set user access allowed for CMU_FC_AE_1 */
    #endif
    #if (defined(IP_CMU_FC_AE_2_BASE))
    /* Set user access allowed for CMU_FC_AE_2 */
    #endif
}
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

void Clock_Ip_Command(Clock_Ip_ClockConfigType const * Config, Clock_Ip_CommandType Command)
{
    switch (Command)
    {
        case CLOCK_IP_INITIALIZE_PLATFORM_COMMAND:
            Clock_Ip_SpecificPlatformInitClock(Config);
            break;
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        case CLOCK_IP_SET_USER_ACCESS_ALLOWED_COMMAND:
            OsIf_Trusted_Call(Clock_Ip_SpecificSetUserAccessAllowed);
            break;
    #endif
#endif
        default:
            /* Command is not implemented on this platform */
            break;
    }
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES


/* Clock start rom section code */
#define MCU_START_SEC_CODE_AC
#include "Mcu_MemMap.h"

/* Set Ram IWS */
void SRAMController_SetRamIWS(uint32 SmuM33CoreClk_IwsSetting, uint32 Rtu0CoreClk_IwsSetting, uint32 Rtu1CoreClk_IwsSetting, uint32 CeM33CoreClk_IwsSetting)
{
#if (1 == 1)
    (void)SmuM33CoreClk_IwsSetting;
    (void)Rtu0CoreClk_IwsSetting;
    (void)Rtu1CoreClk_IwsSetting;
    (void)CeM33CoreClk_IwsSetting;
#else
    IP_SMU__SRAMCTL_0->RAMCR |= ((IP_SMU__SRAMCTL_0->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(SmuM33CoreClk_IwsSetting));
    IP_SMU__SRAMCTL_1->RAMCR |= ((IP_SMU__SRAMCTL_1->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(SmuM33CoreClk_IwsSetting));
    IP_SMU__SRAMCTL_2->RAMCR |= ((IP_SMU__SRAMCTL_2->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(SmuM33CoreClk_IwsSetting));
    IP_SMU__SRAMCTL_3->RAMCR |= ((IP_SMU__SRAMCTL_3->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(SmuM33CoreClk_IwsSetting));

    IP_RTU0__SRAMCTL_C0->RAMCR |= ((IP_RTU0__SRAMCTL_C0->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_C1->RAMCR |= ((IP_RTU0__SRAMCTL_C1->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_C2->RAMCR |= ((IP_RTU0__SRAMCTL_C2->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_C3->RAMCR |= ((IP_RTU0__SRAMCTL_C3->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_C4->RAMCR |= ((IP_RTU0__SRAMCTL_C4->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_C5->RAMCR |= ((IP_RTU0__SRAMCTL_C5->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_C6->RAMCR |= ((IP_RTU0__SRAMCTL_C6->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_D0->RAMCR |= ((IP_RTU0__SRAMCTL_D0->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_D1->RAMCR |= ((IP_RTU0__SRAMCTL_D1->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));
    IP_RTU0__SRAMCTL_D2->RAMCR |= ((IP_RTU0__SRAMCTL_D2->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu0CoreClk_IwsSetting));

    IP_RTU1__SRAMCTL_C0->RAMCR |= ((IP_RTU1__SRAMCTL_C0->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_C1->RAMCR |= ((IP_RTU1__SRAMCTL_C1->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_C2->RAMCR |= ((IP_RTU1__SRAMCTL_C2->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_C3->RAMCR |= ((IP_RTU1__SRAMCTL_C3->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_C4->RAMCR |= ((IP_RTU1__SRAMCTL_C4->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_C5->RAMCR |= ((IP_RTU1__SRAMCTL_C5->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_C6->RAMCR |= ((IP_RTU1__SRAMCTL_C6->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_D0->RAMCR |= ((IP_RTU1__SRAMCTL_D0->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_D1->RAMCR |= ((IP_RTU1__SRAMCTL_D1->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));
    IP_RTU1__SRAMCTL_D2->RAMCR |= ((IP_RTU1__SRAMCTL_D2->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(Rtu1CoreClk_IwsSetting));

    IP_CE_SRAMCTL_0->RAMCR |= ((IP_CE_SRAMCTL_0->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(CeM33CoreClk_IwsSetting));
    IP_CE_SRAMCTL_1->RAMCR |= ((IP_CE_SRAMCTL_1->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(CeM33CoreClk_IwsSetting));
    IP_CE_SRAMCTL_2->RAMCR |= ((IP_CE_SRAMCTL_2->RAMCR & ~SRAMCTL_RAMCR_IWS_MASK) | SRAMCTL_RAMCR_IWS(CeM33CoreClk_IwsSetting));
#endif
}

/* Clock stop rom section code */
#define MCU_STOP_SEC_CODE_AC
#include "Mcu_MemMap.h"
#endif



#ifdef __cplusplus
}
#endif

/** @} */

