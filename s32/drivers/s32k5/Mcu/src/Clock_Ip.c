/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip.c
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
#include "OsIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_VENDOR_ID_C                      43
#define CLOCK_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_SW_MINOR_VERSION_C               8
#define CLOCK_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip.c and Clock_Ip_Private.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((CLOCK_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip.c and OsIf.h are different"
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*!
 * @brief Clock ip driver context
 */
typedef struct
{
    boolean ClockTreeIsConsumingPll;                /**< Clock tree is using a PLL output. */
    boolean WaitStatesAreSupported;                 /**< Wait states are supported. */
    uint8 HwPllsNo;                                 /**< Number of plls . */
    uint8 HwDfsNo;                                  /**< Number of fractional dividers . */

} Clock_Ip_DriverContextType;

/*! @brief Clock ip distribution type commands
 */
typedef enum
{
    CLOCK_IP_NO_PLL_DISTRIBUTION_TYPE                       = 0x00U,    /*!< The clock tree is not using PLL/DFS output clock as sources. */
    CLOCK_IP_FILTER_PLL_DISTRIBUTION_TYPE                   = 0x01U,    /*!< The clock tree is using at least one PLL/DFS output clock as source. Pll is not distributed. */
    CLOCK_IP_PLL_DISTRIBUTION_TYPE                          = 0x02U,    /*!< The clock tree is using at least one PLL/DFS output clock as source. Pll is distributed only. */

} Clock_Ip_DistributionType;

typedef void (*ProgramRegisterType)(void);

#ifndef CLOCK_IP_DO_NOT_LOG_REGITSTER_VALUES
typedef struct
{
    Clock_Ip_NameType ClockName;
    uint16 RegisterIndex;


    Clock_Ip_RegisterAccessOperationType RegisterAccessOperation;
    Clock_Ip_RegisterAccessEventType Event;
    uint16 BufferIndex;

    uint8 BranchOffset1;
    uint8 BranchOffset2;

    volatile uint32 *Address;
    volatile const uint32 *ConstAddress;
    uint32 Mask;
    uint32 Value;

    Clock_Ip_ResourceType ResourceType;
    Clock_Ip_OperationRequestType OperationType;

    Clock_Ip_FunctionNameType FunctionName;
    Clock_Ip_HwStateType State;

} Clock_Ip_LoggedRegisterType;
#endif

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*    Partition 0 */
#define PRTN0_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0x00000010U)
#define PRTN0_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0xF3E3C000U)
#define PRTN0_COFB2_CLKEN_REQ_MASK_U32    ((uint32)0x002200A7U)
/*    Partition 1 */
#define PRTN1_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0x00000001U)
#define PRTN1_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0x1FFFFFF8U)
/*    Partition 2 */
#define PRTN2_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0xFFAAAAB8U)
#define PRTN2_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0xFFDF863FU)
#define PRTN2_COFB2_CLKEN_REQ_MASK_U32    ((uint32)0xFFFFFFFFU)
#define PRTN2_COFB3_CLKEN_REQ_MASK_U32    ((uint32)0x63FC03FFU)
/*    Partition 3 */
#define PRTN3_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0x00000009U)
#define PRTN3_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0x383FFFD0U)
/*    Partition 4 */
#define PRTN4_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0x00000001U)
#define PRTN4_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0x001E7FF8U)
/*    Partition 5 */
#define PRTN5_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0xFC5555FCU)
#define PRTN5_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0xFFFFFFFFU)
#define PRTN5_COFB2_CLKEN_REQ_MASK_U32    ((uint32)0xC19D03CFU)
#define PRTN5_COFB3_CLKEN_REQ_MASK_U32    ((uint32)0x000007FFU)

/* CPE -----------------------------------------------------------------------*/
/*    Partition 0 */
#define CPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0xFFFFFFFEU)
#define CPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0x00007F4FU)
/*    Partition 1 */
#define CPE_PRTN1_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0x0077FFFFU)
/* LPE -----------------------------------------------------------------------*/
/*    Partition 0 */
#define LPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32    ((uint32)0xFBFFAAAFU)
#define LPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32    ((uint32)0xFFFFFFFFU)
#define LPE_PRTN0_COFB2_CLKEN_REQ_MASK_U32    ((uint32)0xFFEFDFFFU)
#define LPE_PRTN0_COFB3_CLKEN_REQ_MASK_U32    ((uint32)0x00000FFFU)

#define CLOCK_IP_ALL_CLOCK_SOURCE_TYPES_SIZE          6U
#define CLOCK_IP_NON_PLL_CLOCK_SOURCE_TYPES_SIZE      5U
#define CLOCK_IP_PLL_ONLY_CLOCK_SOURCE_TYPES_SIZE     1U

/* Default FXOSC frequency in MHz (FVB) */
#ifndef FXOSC_FREQ_MHZ
#define FXOSC_FREQ_MHZ        (40)
/* #define FXOSC_FREQ_MHZ        (50) */
#endif /* FXOSC_FREQ_MHZ */


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static void Clock_Ip_NotificatonsEmptyCallback(Clock_Ip_NotificationType Notification, Clock_Ip_NameType ClockName);
static void Clock_Ip_UpdateDriverContext(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CallEmptyCallbacks(void);
static boolean Clock_Ip_CheckFilter(Clock_Ip_NameType source, const Clock_Ip_ClockNameSourceType *ClocksDistribution, uint32 ClocksDistributionSize);
static void Clock_Ip_DistributeClock(Clock_Ip_DistributionType ClocksDistributionType);

#if ( defined(CLOCK_IP_HAS_RAM_WAIT_STATES) || defined(CLOCK_IP_HAS_FLASH_WAIT_STATES) )
static void Clock_Ip_SetWaitStates(void);
#endif

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
static void Clock_Ip_CheckClockConfiguration(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckXoscClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckPllClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckExtSigClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckSelectorClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckDividerClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckFracDividerClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckGateClocks(Clock_Ip_ClockConfigType const * Config);
static void Clock_Ip_CheckCmuClocks(Clock_Ip_ClockConfigType const * Config);
#endif

static void Clock_Ip_Registers_RunOnHardware(void);


static void Clock_Ip_RegisterAccess_CheckRegisterValue(void);
static void Clock_Ip_RegisterAccess_CheckRegisterValue_WithEvent(void);
static void Clock_Ip_RegisterAccess_CheckNotRegisterValue_WithEvent(void);
static void Clock_Ip_RegisterAccess_CheckRegisterValue_WithTimeout(void);
static void Clock_Ip_RegisterAccess_ReadModifyWrite(void);
static void Clock_Ip_RegisterAccess_Write(void);
static void Clock_Ip_RegisterAccess_SetBit(void);
static void Clock_Ip_RegisterAccess_ClearBit(void);

static void Clock_Ip_FracDivs__Enable(uint8 FracDivsCount, const Clock_Ip_FracDivConfigType FracDivConfigurations[]);
static void Clock_Ip_Pll__Set(uint8 PllsCount, const Clock_Ip_PllConfigType PllConfigurations[]);
static void Clock_Ip_Pll__Enable(uint8 PllsCount, const Clock_Ip_PllConfigType PllConfigurations[]);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/


/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

static boolean FunctionWasCalled;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_8
#include "Mcu_MemMap.h"


uint8 Clock_Ip_FreqIds[CLOCK_IP_FEATURE_NAMES_NO];

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_8
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

static uint32 Clock_Ip_LoggedRegisterIndex;
static uint32 Clock_Ip_RegisterIndex;
static volatile uint32* Clock_Ip_RegAddress;
static uint32 Clock_Ip_Mask;
static uint32 Clock_Ip_Value;
static uint32 Clock_Ip_RegisterValue;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

const Clock_Ip_ClockConfigType *Clock_Ip_pxConfig;                                           /* Reference to the current clock configuration */

static const Clock_Ip_RegisterType   *Clock_Ip_Register;

static Clock_Ip_DriverContextType DriverContext;

#ifndef CLOCK_IP_DO_NOT_LOG_REGITSTER_VALUES
Clock_Ip_LoggedRegisterType Clock_Ip_LoggedRegisterValues[CLOCK_IP_CONFIGURED_REGISTERS_0_VS_0_NO];
#endif

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"


/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock Report Error Callback */
static Clock_Ip_NotificationsCallbackType Clock_Ip_pfkNotificationsCallback = &Clock_Ip_NotificatonsEmptyCallback;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


#define MCU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

boolean RunOptimizedVersion_for_Mcu;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Clock_Ip_ClockNameSourceType AllClockSources[CLOCK_IP_ALL_CLOCK_SOURCE_TYPES_SIZE] = {UKNOWN_TYPE, IRCOSC_TYPE, XOSC_TYPE, EXT_CLK_TYPE, SERDES_TYPE, PLL_TYPE};
static const Clock_Ip_ClockNameSourceType NonPllClockSources[CLOCK_IP_NON_PLL_CLOCK_SOURCE_TYPES_SIZE] = {UKNOWN_TYPE, IRCOSC_TYPE, XOSC_TYPE, EXT_CLK_TYPE, SERDES_TYPE};
static const Clock_Ip_ClockNameSourceType PllOnlyClockSources[CLOCK_IP_PLL_ONLY_CLOCK_SOURCE_TYPES_SIZE] = {PLL_TYPE};

static const ProgramRegisterType Clock_Ip_RegisterAccessOperations[REGISTER_ACCESS__OPS_NO] = {
    &Clock_Ip_RegisterAccess_CheckRegisterValue,                  /* REGISTER_ACCESS__CHECK_REGISTER_VALUE */
    &Clock_Ip_RegisterAccess_CheckRegisterValue_WithEvent,        /* REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_EVENT */
    &Clock_Ip_RegisterAccess_CheckNotRegisterValue_WithEvent,     /* REGISTER_ACCESS__CHECK_NOT_REGISTER_VALUE__WITH_EVENT */
    &Clock_Ip_RegisterAccess_CheckRegisterValue_WithTimeout,      /* REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_TIMEOUT */
    &Clock_Ip_RegisterAccess_ReadModifyWrite,                     /* REGISTER_ACCESS__READ_MODIFY_WRITE */
    &Clock_Ip_RegisterAccess_Write,                               /* REGISTER_ACCESS__WRITE */
    &Clock_Ip_RegisterAccess_SetBit,                              /* REGISTER_ACCESS__SET_BIT */
    &Clock_Ip_RegisterAccess_ClearBit,                            /* REGISTER_ACCESS__CLEAR_BIT */
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"


/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


static void Clock_Ip_enable_all_gates(void)
{
    /* Enable partitions */
    IP_MC_ME->PRTN0_PCONF |= MC_ME_PRTN0_PCONF_PCE_MASK;
    IP_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE_MASK;
    IP_MC_ME->PRTN2_PCONF |= MC_ME_PRTN2_PCONF_PCE_MASK;
    IP_MC_ME->PRTN3_PCONF |= MC_ME_PRTN3_PCONF_PCE_MASK;
    IP_MC_ME->PRTN4_PCONF |= MC_ME_PRTN4_PCONF_PCE_MASK;
    IP_MC_ME->PRTN5_PCONF |= MC_ME_PRTN5_PCONF_PCE_MASK;

    /* Prepare partition update */
    IP_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN2_PUPD  |= MC_ME_PRTN2_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN3_PUPD  |= MC_ME_PRTN3_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN4_PUPD  |= MC_ME_PRTN4_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN5_PUPD  |= MC_ME_PRTN5_PUPD_PCUD_MASK;

    /* Trigger partition update by writing CTL_KEYs */
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
    while (((IP_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK) >> MC_ME_PRTN1_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN2_PUPD & MC_ME_PRTN2_PUPD_PCUD_MASK) >> MC_ME_PRTN2_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN3_PUPD & MC_ME_PRTN3_PUPD_PCUD_MASK) >> MC_ME_PRTN3_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN4_PUPD & MC_ME_PRTN4_PUPD_PCUD_MASK) >> MC_ME_PRTN4_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN5_PUPD & MC_ME_PRTN5_PUPD_PCUD_MASK) >> MC_ME_PRTN5_PUPD_PCUD_SHIFT) != 0) {}

    /* Check partition clocks' statuses */
    while (((IP_MC_ME->PRTN0_PCONF & MC_ME_PRTN0_PCONF_PCE_MASK) >> MC_ME_PRTN0_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_MC_ME->PRTN1_PCONF & MC_ME_PRTN1_PCONF_PCE_MASK) >> MC_ME_PRTN1_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_MC_ME->PRTN2_PCONF & MC_ME_PRTN2_PCONF_PCE_MASK) >> MC_ME_PRTN2_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_MC_ME->PRTN3_PCONF & MC_ME_PRTN3_PCONF_PCE_MASK) >> MC_ME_PRTN3_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_MC_ME->PRTN4_PCONF & MC_ME_PRTN4_PCONF_PCE_MASK) >> MC_ME_PRTN4_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_MC_ME->PRTN5_PCONF & MC_ME_PRTN5_PCONF_PCE_MASK) >> MC_ME_PRTN5_PCONF_PCE_SHIFT) != 1) {}

    /* Enable peripheral clocks */
    IP_MC_ME->PRTN0_COFB0_CLKEN |= PRTN0_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN0_COFB1_CLKEN |= PRTN0_COFB1_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN0_COFB2_CLKEN |= PRTN0_COFB2_CLKEN_REQ_MASK_U32;

    IP_MC_ME->PRTN1_COFB0_CLKEN |= PRTN1_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN1_COFB1_CLKEN |= PRTN1_COFB1_CLKEN_REQ_MASK_U32;

    IP_MC_ME->PRTN2_COFB0_CLKEN |= PRTN2_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN2_COFB1_CLKEN |= PRTN2_COFB1_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN2_COFB2_CLKEN |= PRTN2_COFB2_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN2_COFB3_CLKEN |= PRTN2_COFB3_CLKEN_REQ_MASK_U32;

    IP_MC_ME->PRTN3_COFB0_CLKEN |= PRTN3_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN3_COFB1_CLKEN |= PRTN3_COFB1_CLKEN_REQ_MASK_U32;

    IP_MC_ME->PRTN4_COFB0_CLKEN |= PRTN4_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN4_COFB1_CLKEN |= PRTN4_COFB1_CLKEN_REQ_MASK_U32;

    IP_MC_ME->PRTN5_COFB0_CLKEN |= PRTN5_COFB0_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN5_COFB1_CLKEN |= PRTN5_COFB1_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN5_COFB2_CLKEN |= PRTN5_COFB2_CLKEN_REQ_MASK_U32;
    IP_MC_ME->PRTN5_COFB3_CLKEN |= PRTN5_COFB3_CLKEN_REQ_MASK_U32;

    /* Prepare partition update */
    IP_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN2_PUPD  |= MC_ME_PRTN2_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN3_PUPD  |= MC_ME_PRTN3_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN4_PUPD  |= MC_ME_PRTN4_PUPD_PCUD_MASK;
    IP_MC_ME->PRTN5_PUPD  |= MC_ME_PRTN5_PUPD_PCUD_MASK;

    /* Trigger partition update by writing CTL_KEYs */
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
    while (((IP_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK) >> MC_ME_PRTN1_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN2_PUPD & MC_ME_PRTN2_PUPD_PCUD_MASK) >> MC_ME_PRTN2_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN3_PUPD & MC_ME_PRTN3_PUPD_PCUD_MASK) >> MC_ME_PRTN3_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN4_PUPD & MC_ME_PRTN4_PUPD_PCUD_MASK) >> MC_ME_PRTN4_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_MC_ME->PRTN5_PUPD & MC_ME_PRTN5_PUPD_PCUD_MASK) >> MC_ME_PRTN5_PUPD_PCUD_SHIFT) != 0) {}

    /* Check peripheral clocks statuses */
    while ((IP_MC_ME->PRTN0_COFB0_STAT & PRTN0_COFB0_CLKEN_REQ_MASK_U32) != PRTN0_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN0_COFB1_STAT & PRTN0_COFB1_CLKEN_REQ_MASK_U32) != PRTN0_COFB1_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN0_COFB2_STAT & PRTN0_COFB2_CLKEN_REQ_MASK_U32) != PRTN0_COFB2_CLKEN_REQ_MASK_U32) {}

    while ((IP_MC_ME->PRTN1_COFB0_STAT & PRTN1_COFB0_CLKEN_REQ_MASK_U32) != PRTN1_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN1_COFB1_STAT & PRTN1_COFB1_CLKEN_REQ_MASK_U32) != PRTN1_COFB1_CLKEN_REQ_MASK_U32) {}

    while ((IP_MC_ME->PRTN2_COFB0_STAT & PRTN2_COFB0_CLKEN_REQ_MASK_U32) != PRTN2_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN2_COFB1_STAT & PRTN2_COFB1_CLKEN_REQ_MASK_U32) != PRTN2_COFB1_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN2_COFB2_STAT & PRTN2_COFB2_CLKEN_REQ_MASK_U32) != PRTN2_COFB2_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN2_COFB3_STAT & PRTN2_COFB3_CLKEN_REQ_MASK_U32) != PRTN2_COFB3_CLKEN_REQ_MASK_U32) {}

    while ((IP_MC_ME->PRTN3_COFB0_STAT & PRTN3_COFB0_CLKEN_REQ_MASK_U32) != PRTN3_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN3_COFB1_STAT & PRTN3_COFB1_CLKEN_REQ_MASK_U32) != PRTN3_COFB1_CLKEN_REQ_MASK_U32) {}

    while ((IP_MC_ME->PRTN4_COFB0_STAT & PRTN4_COFB0_CLKEN_REQ_MASK_U32) != PRTN4_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN4_COFB1_STAT & PRTN4_COFB1_CLKEN_REQ_MASK_U32) != PRTN4_COFB1_CLKEN_REQ_MASK_U32) {}

    while ((IP_MC_ME->PRTN5_COFB0_STAT & PRTN5_COFB0_CLKEN_REQ_MASK_U32) != PRTN5_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN5_COFB1_STAT & PRTN5_COFB1_CLKEN_REQ_MASK_U32) != PRTN5_COFB1_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN5_COFB2_STAT & PRTN5_COFB2_CLKEN_REQ_MASK_U32) != PRTN5_COFB2_CLKEN_REQ_MASK_U32) {}
    while ((IP_MC_ME->PRTN5_COFB3_STAT & PRTN5_COFB3_CLKEN_REQ_MASK_U32) != PRTN5_COFB3_CLKEN_REQ_MASK_U32) {}

    /* Enable partitions */
    IP_CPE_MC_ME->PRTN0_PCONF |= MC_ME_PRTN0_PCONF_PCE_MASK;
    IP_CPE_MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE_MASK;

    /* Prepare partition update */
    IP_CPE_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;
    IP_CPE_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;

    /* Trigger partition update by writing CTL_KEYs */
    IP_CPE_MC_ME->CTL_KEY = 0x5AF0;
    IP_CPE_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
    while (((IP_CPE_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_CPE_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK) >> MC_ME_PRTN1_PUPD_PCUD_SHIFT) != 0) {}

    /* Check partition clocks' statuses */
    while (((IP_CPE_MC_ME->PRTN0_PCONF & MC_ME_PRTN0_PCONF_PCE_MASK) >> MC_ME_PRTN0_PCONF_PCE_SHIFT) != 1) {}
    while (((IP_CPE_MC_ME->PRTN1_PCONF & MC_ME_PRTN1_PCONF_PCE_MASK) >> MC_ME_PRTN1_PCONF_PCE_SHIFT) != 1) {}

    /* Enable peripheral clocks */
    IP_CPE_MC_ME->PRTN0_COFB0_CLKEN |= CPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32;
    IP_CPE_MC_ME->PRTN0_COFB1_CLKEN |= CPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32;

    IP_CPE_MC_ME->PRTN1_COFB0_CLKEN |= CPE_PRTN1_COFB0_CLKEN_REQ_MASK_U32;

    /* Prepare partition update */
    IP_CPE_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;
    IP_CPE_MC_ME->PRTN1_PUPD  |= MC_ME_PRTN1_PUPD_PCUD_MASK;

    /* Trigger partition update by writing CTL_KEYs */
    IP_CPE_MC_ME->CTL_KEY = 0x5AF0;
    IP_CPE_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
    while (((IP_CPE_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}
    while (((IP_CPE_MC_ME->PRTN1_PUPD & MC_ME_PRTN1_PUPD_PCUD_MASK) >> MC_ME_PRTN1_PUPD_PCUD_SHIFT) != 0) {}
    /* Check peripheral clocks statuses */
    while ((IP_CPE_MC_ME->PRTN0_COFB0_STAT & CPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32) != CPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_CPE_MC_ME->PRTN0_COFB1_STAT & CPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32) != CPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32) {}

    while ((IP_CPE_MC_ME->PRTN1_COFB0_STAT & CPE_PRTN1_COFB0_CLKEN_REQ_MASK_U32) != CPE_PRTN1_COFB0_CLKEN_REQ_MASK_U32) {}


    /* Enable partitions */
    IP_LPE_MC_ME->PRTN0_PCONF |= MC_ME_PRTN0_PCONF_PCE_MASK;

    /* Prepare partition update */
    IP_LPE_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;

    /* Trigger partition update by writing CTL_KEYs */
    IP_LPE_MC_ME->CTL_KEY = 0x5AF0;
    IP_LPE_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
    while (((IP_LPE_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}

    /* Check partition clocks' statuses */
    while (((IP_LPE_MC_ME->PRTN0_PCONF & MC_ME_PRTN0_PCONF_PCE_MASK) >> MC_ME_PRTN0_PCONF_PCE_SHIFT) != 1) {}

    /* Enable peripheral clocks */
    IP_LPE_MC_ME->PRTN0_COFB0_CLKEN |= LPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32;
    IP_LPE_MC_ME->PRTN0_COFB1_CLKEN |= LPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32;
    IP_LPE_MC_ME->PRTN0_COFB2_CLKEN |= LPE_PRTN0_COFB2_CLKEN_REQ_MASK_U32;
    IP_LPE_MC_ME->PRTN0_COFB3_CLKEN |= LPE_PRTN0_COFB3_CLKEN_REQ_MASK_U32;

    /* Prepare partition update */
    IP_LPE_MC_ME->PRTN0_PUPD  |= MC_ME_PRTN0_PUPD_PCUD_MASK;

    /* Trigger partition update by writing CTL_KEYs */
    IP_LPE_MC_ME->CTL_KEY = 0x5AF0;
    IP_LPE_MC_ME->CTL_KEY = 0xA50F;

    /* Poll partition update statuses */
    while (((IP_LPE_MC_ME->PRTN0_PUPD & MC_ME_PRTN0_PUPD_PCUD_MASK) >> MC_ME_PRTN0_PUPD_PCUD_SHIFT) != 0) {}

    /* Check peripheral clocks statuses */
    while ((IP_LPE_MC_ME->PRTN0_COFB0_STAT & LPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32) != LPE_PRTN0_COFB0_CLKEN_REQ_MASK_U32) {}
    while ((IP_LPE_MC_ME->PRTN0_COFB1_STAT & LPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32) != LPE_PRTN0_COFB1_CLKEN_REQ_MASK_U32) {}
    while ((IP_LPE_MC_ME->PRTN0_COFB2_STAT & LPE_PRTN0_COFB2_CLKEN_REQ_MASK_U32) != LPE_PRTN0_COFB2_CLKEN_REQ_MASK_U32) {}
    while ((IP_LPE_MC_ME->PRTN0_COFB3_STAT & LPE_PRTN0_COFB3_CLKEN_REQ_MASK_U32) != LPE_PRTN0_COFB3_CLKEN_REQ_MASK_U32) {}
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Gates__Reset.
 * Description   : Gate software reset.
 *
 *END**************************************************************************/
static void Clock_Ip_Gates__Reset(uint8 GatesCount, const Clock_Ip_GateConfigType GateConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType GateClkName = gated_clk;  /* Clock name corresponding to gate. */

    for (Index = GatesCount; Index > 0U; Index--)    /* Gate software reset. */
    {
        GateClkName = GateConfigurations[Index - 1U].Name;
        ClockLLD_Gates(GateClkName)->Reset();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Gates__Set.
 * Description   : Update gate status
 *
 *END**************************************************************************/
static void Clock_Ip_Gates__Set(uint8 GatesCount, const Clock_Ip_GateConfigType GateConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType GateClkName = gated_clk;  /* Clock name corresponding to gate */

    for (Index = 0U; Index < GatesCount; Index++)    /* Update clock source. */
    {
        GateClkName = GateConfigurations[Index].Name;
        if (0U != GateConfigurations[Index].Name)
        {
            ClockLLD_Gates(GateClkName)->Enable();
        }
        else
        {
            ClockLLD_Gates(GateClkName)->Disable();
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Gates__Wait.
 * Description   : Wait for gate to update
 *
 *END**************************************************************************/
static void Clock_Ip_Gates__Wait(uint8 GatesCount, const Clock_Ip_GateConfigType GateConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType GateClkName = gated_clk;  /* Clock name corresponding to gate */

    for (Index = 0U; Index < GatesCount; Index++)    /* Update clock source. */
    {
        GateClkName = GateConfigurations[Index].Name;
        ClockLLD_Gates(GateClkName)->Wait();
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Cmus__Disable.
 * Description   : Disables/resets all monitors from a configuration
 *
 *END**************************************************************************/
static void Clock_Ip_Cmus__Disable(uint8 MonitorsCount, const Clock_Ip_CmuConfigType MonitorConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType MonClkName = gated_clk;  /* Name of the monitored clock */

    for (Index = 0U; Index < MonitorsCount; Index++)    /* Reset all clock monitor units from previous configuration. */
    {
        MonClkName = MonitorConfigurations[Index].Name;
        ClockLLD_Monitors(MonClkName)->Disable();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Cmus__Set.
 * Description   : Configure all clock monitors
 *
 *END**************************************************************************/
static void Clock_Ip_Cmus__Set(uint8 MonitorsCount, const Clock_Ip_CmuConfigType MonitorConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType MonClkName = gated_clk;  /* Name of the monitored clock */
    ClockLLD_CmuEventReactionType EventReaction = CLOCK_LLD_INTERRUPT_MODE;
    ClockLLD_CmuDeviationType Deviation = CLOCK_LLD_MAXIMUM_5_PERCENTAGE_DEVIATION;
    ClockLLD_CmuLatencyType Latency = CLOCK_LLD_LOWEST_LATENCY;
    uint64 MonitoredClockFrequency = 0UL;


    for (Index = 0U; Index < MonitorsCount; Index++)    /* Reset all clock monitor units from previous configuration. */
    {
        MonClkName = MonitorConfigurations[Index].Name;
        ClockLLD_Monitors(MonClkName)->Set(EventReaction,Deviation,Latency,MonitoredClockFrequency);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Cmus__Enable.
 * Description   : Start to monitor
 *
 *END**************************************************************************/
static void Clock_Ip_Cmus__Enable(uint8 MonitorsCount, const Clock_Ip_CmuConfigType MonitorConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType MonClkName = gated_clk;  /* Name of the monitored clock */

    for (Index = 0U; Index < MonitorsCount; Index++)    /* Reset all clock monitor units from previous configuration. */
    {
        MonClkName = MonitorConfigurations[Index].Name;
        if (0U != MonitorConfigurations[Index].Enable)
        {
            ClockLLD_Monitors(MonClkName)->Enable();
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Selectors__Reset.
 * Description   : Transition all selectors from configuration to safe clock.
 *
 *END**************************************************************************/
static void Clock_Ip_Selectors__Reset(uint8 SelectorsCount, const Clock_Ip_SelectorConfigType SelectorConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType SelClkName = gated_clk;  /* Clock name corresponding to selector */

    for (Index = SelectorsCount; Index > 0U; Index--)    /* Reset all selectors to safe clock. */
    {
        SelClkName = SelectorConfigurations[Index - 1U].Name;
        ClockLLD_Selectors(SelClkName)->Reset();
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_FracDivs__Reset.
 * Description   : Put in reset state all fractional dividers from configuration.
 *
 *END**************************************************************************/
static void Clock_Ip_FracDivs__Reset(uint8 FracDivsCount, const Clock_Ip_FracDivConfigType FracDivConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType FracDivClkName = gated_clk;  /* Clock name corresponding to fractional divider */

    for (Index = FracDivsCount; Index > 0U; Index--)    /* Put in reset state fractional divider channels. */
    {
        FracDivClkName = FracDivConfigurations[Index - 1U].Name;
        ClockLLD_FracDividers(FracDivClkName)->Reset();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_FracDivs__Set.
 * Description   : Sets fractional division value by which clock signal si divided
 *
 *END**************************************************************************/
static void Clock_Ip_FracDivs__Set(uint8 FracDivsCount, const Clock_Ip_FracDivConfigType FracDivConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType FracDivClkName = gated_clk;  /* Clock name corresponding to fractional divider */
    float DivisionValue = 0.0f;

    for (Index = 0U; Index < FracDivsCount; Index++)    /* Put in reset state fractional divider channels. */
    {
        FracDivClkName = FracDivConfigurations[Index].Name;
        DivisionValue = FracDivConfigurations[Index].Value;
        ClockLLD_FracDividers(FracDivClkName)->Set(DivisionValue);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_FracDivs__Enable.
 * Description   : Configure plls.
 *
 *END**************************************************************************/
static void Clock_Ip_FracDivs__Enable(uint8 FracDivsCount, const Clock_Ip_FracDivConfigType FracDivConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType FracDivClkName = gated_clk;  /* Clock name corresponding to fractional divider */

    for (Index = 0U; Index < FracDivsCount; Index++)    /* Power down plls. */
    {
        FracDivClkName = FracDivConfigurations[Index].Name;
        if (FracDivConfigurations[Index].Value != 0.0f)
        {
            ClockLLD_FracDividers(FracDivClkName)->Enable();
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Plls__Reset.
 * Description   : Power down all plls from configuration.
 *
 *END**************************************************************************/
static void Clock_Ip_Plls__Reset(uint8 PllsCount, const Clock_Ip_PllConfigType PllConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType PllClkName = gated_clk;  /* Clock name corresponding to pll */

    for (Index = PllsCount; Index > 0U; Index--)    /* Power down plls. */
    {
        PllClkName = PllConfigurations[Index - 1U].Name;
        ClockLLD_Plls(PllClkName)->Reset();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Pll__Set.
 * Description   : Configure plls.
 *
 *END**************************************************************************/
static void Clock_Ip_Pll__Set(uint8 PllsCount, const Clock_Ip_PllConfigType PllConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType PllClkName = gated_clk;  /* Clock name corresponding to pll */
    Clock_Ip_NameType InputReferenceName = gated_clk;  /* Clock name corresponding to pll input reference */
    uint32 PredividerValue = 0U;
    float MultiplierValue = 0.0f;
    uint32 PostdividerValue = 0U;

    for (Index = 0U; Index < PllsCount; Index++)    /* Power down plls. */
    {
        PllClkName = PllConfigurations[Index].Name;
        InputReferenceName = PllConfigurations[Index].InputReference;
        PredividerValue = PllConfigurations[Index].Predivider;
        MultiplierValue = PllConfigurations[Index].Multiplier;
        PostdividerValue = PllConfigurations[Index].Postdivider;

        ClockLLD_Plls(PllClkName)->Set(InputReferenceName, PredividerValue, MultiplierValue, PostdividerValue);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Pll__Enable.
 * Description   : Configure plls.
 *
 *END**************************************************************************/
static void Clock_Ip_Pll__Enable(uint8 PllsCount, const Clock_Ip_PllConfigType PllConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType PllClkName = gated_clk;  /* Clock name corresponding to pll */

    for (Index = 0U; Index < PllsCount; Index++)    /* Power down plls. */
    {
        PllClkName = PllConfigurations[Index].Name;
        if (PllConfigurations[Index].Enable != 0U)
        {
            ClockLLD_Plls(PllClkName)->Enable();
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Xoscs__Reset.
 * Description   : Power down all xoscs from configuration.
 *
 *END**************************************************************************/
static void Clock_Ip_Xoscs__Reset(uint8 XocsCount, const Clock_Ip_XoscConfigType XoscConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType XoscClkName = gated_clk;  /* Clock name corresponding to xosc */

    for (Index = XocsCount; Index > 0U; Index--)    /* Power down xoscs. */
    {
        XoscClkName = XoscConfigurations[Index - 1U].Name;
        ClockLLD_Xoscs(XoscClkName)->Reset();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Xoscs__Set.
 * Description   : Configure all xoscs from configuration.
 *
 *END**************************************************************************/
static void Clock_Ip_Xoscs__Set(uint8 XocsCount, const Clock_Ip_XoscConfigType XoscConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType XoscClkName = gated_clk;  /* Clock name corresponding to xosc */
    uint32 ExternalOscillatorFrequency = 0U;
    uint32 Mode = 0U;
    uint32 StartupStabilizationTime = 0U;
    uint32 Transconductance = 0U;

    for (Index = 0U; Index < XocsCount; Index++)    /* Power down xoscs. */
    {
        XoscClkName = XoscConfigurations[Index].Name;
        ExternalOscillatorFrequency = XoscConfigurations[Index].Freq;
        Mode = XoscConfigurations[Index].Mode;
        StartupStabilizationTime = XoscConfigurations[Index].StartupDelay;
        Transconductance = XoscConfigurations[Index].TransConductance;

        ClockLLD_Xoscs(XoscClkName)->Set(ExternalOscillatorFrequency, Mode, StartupStabilizationTime, Transconductance);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Xoscs__Enable.
 * Description   : Enable all xoscs from configuration.
 *
 *END**************************************************************************/
static void Clock_Ip_Xoscs__Enable(uint8 XocsCount, const Clock_Ip_XoscConfigType XoscConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType XoscClkName = gated_clk;  /* Clock name corresponding to xosc */

    for (Index = 0U; Index < XocsCount; Index++)    /* Power down xoscs. */
    {
        XoscClkName = XoscConfigurations[Index].Name;
        if (0U != XoscConfigurations[Index].Enable)
        {
            ClockLLD_Xoscs(XoscClkName)->Enable();
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Xoscs__Wait.
 * Description   : Wait for Xosc to lock.
 *
 *END**************************************************************************/
static void Clock_Ip_Xoscs__Wait(uint8 XocsCount, const Clock_Ip_XoscConfigType XoscConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType XoscClkName = gated_clk;  /* Clock name corresponding to xosc */

    for (Index = 0U; Index < XocsCount; Index++)    /* Power down xoscs. */
    {
        XoscClkName = XoscConfigurations[Index].Name;
        ClockLLD_Xoscs(XoscClkName)->Wait();
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Dividers__Reset.
 * Description   : Software reset of all dividers.
 *
 *END**************************************************************************/
static void Clock_Ip_Dividers__Reset(uint8 DividersCount, const Clock_Ip_DividerConfigType DividerConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType DividerClkName = gated_clk;  /* Clock name of the divider. */

    for (Index = DividersCount; Index > 0U; Index--)    /* Divider software reset. */
    {
        DividerClkName = DividerConfigurations[Index - 1U].Name;
        ClockLLD_Dividers(DividerClkName)->Reset();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_Dividers__Set.
 * Description   : Update division value.
 *
 *END**************************************************************************/
static void Clock_Ip_Dividers__Set(uint8 DividersCount, const Clock_Ip_DividerConfigType DividerConfigurations[])
{
    uint32 Index;
    Clock_Ip_NameType DividerClkName = gated_clk;  /* Clock name of the divider. */
    uint32 DivisionValue = 0U;

    for (Index = 0; Index < DividersCount; Index++)    /* Divider software reset. */
    {
        DividerClkName = DividerConfigurations[Index].Name;
        DivisionValue = DividerConfigurations[Index].Value;
        ClockLLD_Dividers(DividerClkName)->Set(DivisionValue);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_NotificatonsEmptyCallback.
 * Description   : Notification clock call back.
 *
 *END**************************************************************************/
static void Clock_Ip_NotificatonsEmptyCallback( Clock_Ip_NotificationType Notification,
                                                Clock_Ip_NameType ClockName
                                               )
{
    /* No implementation */
    (void)Notification;
    (void)ClockName;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_UpdateDriverContext.
 * Description   : Updates context of the driver, internal memory, clock objects.
 *
 *END**************************************************************************/
static void Clock_Ip_UpdateDriverContext(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;
    uint32 GatedIndex = 0xffffffff;

    /* Initialize clock objects */
    Clock_Ip_Command(Clock_Ip_pxConfig, CLOCK_IP_INITIALIZE_CLOCK_OBJECTS_COMMAND);

    for (Index = 0U; Index < Config->ExtClksCount; Index++)    /* Set external signal frequency. */
    {
        Clock_Ip_SetExternalSignalFrequency((*(Config->ExtClks))[Index].Name, (*(Config->ExtClks))[Index].Value);
    }

    /* Call empty callbacks */
    Clock_Ip_CallEmptyCallbacks();

    for (Index = 0U; Index < Config->ConfigureFrequenciesCount; Index++)
    {
        if ((*(Config->ConfiguredFrequencies))[Index].Name == gated_clk)
        {
            GatedIndex = Index;
            break;
        }
    }

    if (GatedIndex != 0xffffffff)
    {
        for (Index = 0U; Index < CLOCK_IP_FEATURE_NAMES_NO; Index++)
        {
            Clock_Ip_FreqIds[Index] = GatedIndex;
        }

        for (Index = 0U; Index < Config->ConfigureFrequenciesCount; Index++)
        {
            Clock_Ip_FreqIds[(*(Config->ConfiguredFrequencies))[Index].Name] = Index;
        }
    }
}

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
    #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckXoscClocks
 * Description   : Checks clock names from xoscs array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckXoscClocks(Clock_Ip_ClockConfigType const * Config)
{
#if CLOCK_IP_XOSCS_COUNT > 1U
    uint32 Index;
#endif

    if (Config->XoscsCount != 0U)
    {
#if CLOCK_IP_XOSCS_COUNT > 1U
        if (Config->XoscsCount > 1U)
        {
            for (Index = 0U; Index < (Config->XoscsCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT(((uint32)(*(Config->Xoscs))[Index].Name) < ((uint32)(*(Config->Xoscs))[Index+1U].Name));
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Xoscs))[Index].Name] & CLOCK_IP_XOSC_OBJECT) != 0U);
            }
        }
#endif
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Xoscs))[Config->XoscsCount - 1U].Name] & CLOCK_IP_XOSC_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckPllClocks
 * Description   : Checks clock names from plls array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckPllClocks(Clock_Ip_ClockConfigType const * Config)
{
#if CLOCK_IP_PLLS_COUNT > 1U
    uint32 Index;
#endif
    if (Config->PllsCount != 0U)
    {
#if CLOCK_IP_PLLS_COUNT > 1U
        if (Config->PllsCount > 1U)
        {
            for (Index = 0U; Index < (Config->PllsCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT(((uint32)(*(Config->Plls))[Index].Name) < ((uint32)(*(Config->Plls))[Index+1U].Name));
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Plls))[Index].Name] & CLOCK_IP_PLL_OBJECT) != 0U);
            }
        }
#endif
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Plls))[Config->PllsCount - 1U].Name] & CLOCK_IP_PLL_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckExtSigClocks
 * Description   : Checks clock names from ext signal clocks array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckExtSigClocks(Clock_Ip_ClockConfigType const * Config)
{
#if CLOCK_IP_EXT_CLKS_COUNT > 1U
    uint32 Index;
#endif
    if (Config->ExtClksCount != 0U)
    {
#if CLOCK_IP_EXT_CLKS_COUNT > 1U
        if (Config->ExtClksCount > 1U)
        {
            for (Index = 0U; Index < (Config->ExtClksCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT(((uint32)(*(Config->ExtClks))[Index].Name) < ((uint32)(*(Config->ExtClks))[Index+1U].Name));
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->ExtClks))[Index].Name] & CLOCK_IP_EXT_SIG_OBJECT) != 0U);
            }
        }
#endif
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->ExtClks))[Config->ExtClksCount - 1U].Name] & CLOCK_IP_EXT_SIG_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckSelectorClocks
 * Description   : Checks clock names from selectors array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckSelectorClocks(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;

    if (Config->SelectorsCount != 0U)
    {
        if (Config->SelectorsCount > 1U)
        {
            for (Index = 0U; Index < (Config->SelectorsCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Selectors))[Index].Name] & CLOCK_IP_SELECTOR_OBJECT) != 0U);
            }
        }
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Selectors))[Config->SelectorsCount - 1U].Name] & CLOCK_IP_SELECTOR_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckDividerClocks
 * Description   : Checks clock names from dividers array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckDividerClocks(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;

    if (Config->DividersCount != 0U)
    {
        if (Config->DividersCount > 1U)
        {
            for (Index = 0U; Index < (Config->DividersCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Dividers))[Index].Name] & CLOCK_IP_DIVIDER_OBJECT) != 0U);
            }
        }
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Dividers))[Config->DividersCount - 1U].Name] & CLOCK_IP_DIVIDER_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Check_FracDivider_Clocks
 * Description   : Checks clock names from fractional divider array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckFracDividerClocks(Clock_Ip_ClockConfigType const * Config)
{
#if CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT > 1U
    uint32 Index;
#endif

    if (Config->FracDivsCount != 0U)
    {
#if CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT > 1U
        if (Config->FracDivsCount > 1U)
        {
            for (Index = 0U; Index < (Config->FracDivsCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT(((uint32)(*(Config->FracDivs))[Index].Name) < ((uint32)(*(Config->FracDivs))[Index+1U].Name));
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->FracDivs))[Index].Name] & CLOCK_IP_FRAC_DIV_OBJECT) != 0U);
            }
        }
#endif
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->FracDivs))[Config->FracDivsCount - 1U].Name] & CLOCK_IP_FRAC_DIV_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckGateClocks
 * Description   : Checks clock names from gates array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckGateClocks(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;

    if (Config->GatesCount != 0U)
    {
        if (Config->GatesCount > 1U)
        {
            for (Index = 0U; Index < (Config->GatesCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT(((uint32)(*(Config->Gates))[Index].Name) < ((uint32)(*(Config->Gates))[Index+1U].Name));
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Gates))[Index].Name] & CLOCK_IP_GATE_OBJECT) != 0U);
            }
        }
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Gates))[Config->GatesCount - 1U].Name] & CLOCK_IP_GATE_OBJECT) != 0U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_CheckCmuClocks
 * Description   : Checks clock names from cmu array
 *
 *END**************************************************************************/
static void Clock_Ip_CheckCmuClocks(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;

    if (Config->CmusCount != 0U)
    {
        if (Config->CmusCount > 1U)
        {
            for (Index = 0U; Index < (Config->CmusCount - 1U); Index++)
            {
                CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Cmus))[Index].Name] & CLOCK_IP_CMU_OBJECT) != 0U);
            }
        }
        CLOCK_IP_DEV_ASSERT((Clock_Ip_au8ClockNameTypes[(*(Config->Cmus))[Config->CmusCount - 1U].Name] & CLOCK_IP_CMU_OBJECT) != 0U);
    }
}
    #endif
#endif

#define CLOCK_IP_NO_CALLBACK 0U

/* Call empty callbacks to improve CCOV*/
static void Clock_Ip_CallEmptyCallbacks(void)
{
    if (FALSE == FunctionWasCalled)
    {
        FunctionWasCalled = TRUE;
        if (NULL_PTR != Clock_Ip_pxConfig->Cmus)
        {
            /*Clock_Ip_axCmuCallbacks[CLOCK_IP_NO_CALLBACK].Set(&(*Clock_Ip_pxConfig->Cmus)[0U], 0U);*/
        }
        /*Clock_Ip_axCmuCallbacks[CLOCK_IP_NO_CALLBACK].Disable(FIRC_CLK);*/

        if (NULL_PTR != Clock_Ip_pxConfig->Dividers)
        {
            /*Clock_Ip_axDividerCallbacks[CLOCK_IP_NO_CALLBACK].Set(&(*Clock_Ip_pxConfig->Dividers)[0U]);*/
        }

        if (NULL_PTR != Clock_Ip_pxConfig->FracDivs)
        {
            /*Clock_Ip_axFracDivCallbacks[CLOCK_IP_NO_CALLBACK].Set(&(*Clock_Ip_pxConfig->FracDivs)[0U]);*/
        }
        /*(void)Clock_Ip_axFracDivCallbacks[CLOCK_IP_NO_CALLBACK].Complete(FIRC_CLK);*/

        if (NULL_PTR != Clock_Ip_pxConfig->Gates)
        {
            /*Clock_Ip_axGateCallbacks[CLOCK_IP_NO_CALLBACK].Set(&(*Clock_Ip_pxConfig->Gates)[0U]);*/
        }
        /*Clock_Ip_axGateCallbacks[CLOCK_IP_NO_CALLBACK].Update(FIRC_CLK,FALSE);*/

        if (NULL_PTR != Clock_Ip_pxConfig->Plls)
        {
            /*Clock_Ip_axPllCallbacks[CLOCK_IP_NO_CALLBACK].Set(&(*Clock_Ip_pxConfig->Plls)[0U]);*/
        }
        /*(void)Clock_Ip_axPllCallbacks[CLOCK_IP_NO_CALLBACK].Complete(FIRC_CLK);*/

        if (NULL_PTR != Clock_Ip_pxConfig->Selectors)
        {
            /*Clock_Ip_axSelectorCallbacks[CLOCK_IP_NO_CALLBACK].Set(&(*Clock_Ip_pxConfig->Selectors)[0U]);*/
        }
    }
}

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
    #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
static void Clock_Ip_CheckClockConfiguration(Clock_Ip_ClockConfigType const * Config)
{
    Clock_Ip_CheckXoscClocks(Config);
    Clock_Ip_CheckPllClocks(Config);
    Clock_Ip_CheckExtSigClocks(Config);
    Clock_Ip_CheckSelectorClocks(Config);
    Clock_Ip_CheckDividerClocks(Config);
    Clock_Ip_CheckFracDividerClocks(Config);
    Clock_Ip_CheckGateClocks(Config);
    Clock_Ip_CheckCmuClocks(Config);
}
    #endif
#endif

static boolean Clock_Ip_CheckFilter(Clock_Ip_NameType source, const Clock_Ip_ClockNameSourceType *ClocksDistribution, uint32 ClocksDistributionSize)
{
    uint32 FilterIndex = 0U;
    boolean PassedFilter = FALSE;
    Clock_Ip_ClockNameSourceType Filter;

    /* Configure all plls from configuration asynchronously. Do not enable. */
    for (FilterIndex = 0U; FilterIndex < ClocksDistributionSize; FilterIndex++)
    {
        Filter = ClocksDistribution[FilterIndex];
        if (Filter == Clock_Ip_aeSourceTypeClockName[source])
        {
            PassedFilter = TRUE;
            break;
        }
    }

    return PassedFilter;
}

static void Clock_Ip_DistributeClock(Clock_Ip_DistributionType ClocksDistributionType)
{
    uint32 Index;
    Clock_Ip_NameType SelClkName = gated_clk;  /* Clock name corresponding to selector */
    const Clock_Ip_ClockNameSourceType (*ClocksDistribution)[] = NULL_PTR;
    uint32 ClocksDistributionSize = 0U;
    boolean CheckFilter;

    CLOCK_IP_DEV_ASSERT(NULL_PTR != Clock_Ip_pxConfig);
    /* 'Clock_Ip_pxConfig' is set by Clock_Ip_InitClock().
     *  It doesn't make sense to call PLL distribution without clock initialization. */
    if (NULL_PTR != Clock_Ip_pxConfig)
    {
        switch (ClocksDistributionType)
        {
            /* The clock tree is not using PLL/DFS output clock as sources.
               In this case all clock sources can be distributed. */
            case CLOCK_IP_NO_PLL_DISTRIBUTION_TYPE:

                /* Set all selectors, no pll is consumed by any selector. */
                ClocksDistribution = &AllClockSources;
                ClocksDistributionSize = CLOCK_IP_ALL_CLOCK_SOURCE_TYPES_SIZE;
                break;

            /* The clock tree is using at least one PLL/DFS output clock as source.
               Clocks are distributed on behalf of "Clock_Ip_InitClock" function before polling "Clock_Ip_GetPllStatus".
               Internal and external oscillators, external signals are distributed, instead pll clock sources are filtered. */
            case CLOCK_IP_FILTER_PLL_DISTRIBUTION_TYPE:

                /* Set only if selected inputs are not clocked from PLLs */
                ClocksDistribution = &NonPllClockSources;
                ClocksDistributionSize = CLOCK_IP_NON_PLL_CLOCK_SOURCE_TYPES_SIZE;
                break;

            /* The clock tree is using at least one PLL/DFS output clock as source.
               The user must wait until the PLLs and DFSs are locked by polling Clock_Ip_GetPllStatus.
               and then call "Clock_Ip_DistributePllClock".
               Pll clock sources are distributed on behalf of "Clock_Ip_DistributePllClock" function */
            case CLOCK_IP_PLL_DISTRIBUTION_TYPE:

                /* Set only if selected inputs are clocked from PLLs */
                ClocksDistribution = &PllOnlyClockSources;
                ClocksDistributionSize = CLOCK_IP_PLL_ONLY_CLOCK_SOURCE_TYPES_SIZE;
                break;
            default:
                /* Unsupported clock distribution type */
                break;
        }

        /* Set selectors */
        for (Index = 0U; Index < Clock_Ip_pxConfig->SelectorsCount; Index++)
        {
            CheckFilter = Clock_Ip_CheckFilter((*Clock_Ip_pxConfig->Selectors)[Index].Source, *ClocksDistribution, ClocksDistributionSize);
            if (CheckFilter)
            {
                SelClkName = (*Clock_Ip_pxConfig->Selectors)[Index].Name;
                if (RunOptimizedVersion_for_Mcu == FALSE)
                {
                    ClockLLD_Selectors(SelClkName)->Set((*Clock_Ip_pxConfig->Selectors)[Index].Source);
                }
                else
                {
                    ClockLLD_Selectors(SelClkName)->Set_Optimized((*Clock_Ip_pxConfig->Selectors)[Index].Source);
                }
            }
        }

        /* Wait for selectors to complete */
        for (Index = 0U; Index < Clock_Ip_pxConfig->SelectorsCount; Index++)
        {
            CheckFilter = Clock_Ip_CheckFilter((*Clock_Ip_pxConfig->Selectors)[Index].Source, *ClocksDistribution, ClocksDistributionSize);
            if (CheckFilter)
            {
                SelClkName = (*Clock_Ip_pxConfig->Selectors)[Index].Name;
                if (RunOptimizedVersion_for_Mcu == FALSE)
                {
                    ClockLLD_Selectors(SelClkName)->Wait();
                }
                else
                {
                    ClockLLD_Selectors(SelClkName)->Wait_Optimized();
                }
            }
        }



        switch (ClocksDistributionType)
        {
            /* The clock tree is not using PLL/DFS output clock as sources.
               The user doesn't need to call Clock_Ip_GetPllStatus to wait until the PLLs and DFSs are locked.
               Clocks distribution has been completed on behalf of Clock_Ip_InitClock function.
               Peripheral clock gates and clock monitor can be configured. */
            case CLOCK_IP_NO_PLL_DISTRIBUTION_TYPE:

            /* The clock tree is using at least one PLL/DFS output clock as source.
               Pll distribution has been completed on behalf of "Clock_Ip_DistributePllClock" function.
               Pll clock sources are distributed on behalf of "Clock_Ip_DistributePllClock" function.
               Clock distribution is completed, peripheral clock gates and clock monitor can be configured. */
            case CLOCK_IP_PLL_DISTRIBUTION_TYPE:

                /* Gates sofware reset. */
                Clock_Ip_Gates__Reset(Clock_Ip_pxConfig->GatesCount,*Clock_Ip_pxConfig->Gates);

                /* Gates sofware setting. */
                Clock_Ip_Gates__Set(Clock_Ip_pxConfig->GatesCount,*Clock_Ip_pxConfig->Gates);

                /* Wait for gates to lock. */
                Clock_Ip_Gates__Wait(Clock_Ip_pxConfig->GatesCount,*Clock_Ip_pxConfig->Gates);

                /* Set the Clock Monitoring Units of all configured clock. Cmus are not enabled. */
                Clock_Ip_Cmus__Set(Clock_Ip_pxConfig->CmusCount,*Clock_Ip_pxConfig->Cmus);

                /* Enable the Clock Monitoring Units ( CMU0 .. n ) according to configuration. */
                Clock_Ip_Cmus__Enable(Clock_Ip_pxConfig->CmusCount,*Clock_Ip_pxConfig->Cmus);

                /* Disable safe clock if it is supported by platform and it is configured/required. */
                /* Note: Safe clock is the fast internal oscillator clock. It is clocking the clock tree until pll is distributed.
                 * At the end of configuration it can be disabled if it is supported on this platform and required/configured. */
                Clock_Ip_Command(Clock_Ip_pxConfig, CLOCK_IP_DISABLE_SAFE_CLOCK_COMMAND);

                Clock_Ip_enable_all_gates();

                break;

            /* The clock tree is using at least one PLL/DFS output clock as source.
               Clocks are distributed on behalf of "Clock_Ip_InitClock" function before polling "Clock_Ip_GetPllStatus".
               Internal and external oscilators, external signals are distributed, instead pll clock sources are filtered.
               Clock distribution is not completed, peripheral clock gates and clock monitor can be configured. */
            case CLOCK_IP_FILTER_PLL_DISTRIBUTION_TYPE:

            default:
                /* Unsupported clock distribution type */
                break;
        }
    }
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_Init
 *
 * Description   : Set clock configuration according to pre-defined structure.
 *                 This function sets system to target clock configuration; It sets the
 *                 clock modules registers for clock mode change.
 *
 *                 If external clock is used in the target mode, please make sure it is
 *                 enabled, for example, if the external oscillator is used, please setup correctly.
 *
 * @implements Clock_Ip_Init_Activity
 * END**********************************************************************************/
Clock_Ip_StatusType Clock_Ip_Init(Clock_Ip_ClockConfigType const * Config)
{
    Clock_Ip_StatusType ClockStatus = CLOCK_IP_ERROR;

    Clock_Ip_PllStatusType PllStatus;

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    /* Set user access allowed for Clock */
    Clock_Ip_Command(Config, CLOCK_IP_SET_USER_ACCESS_ALLOWED_COMMAND);
  #endif
#endif
    CLOCK_IP_DEV_ASSERT(NULL_PTR != Config);

    Clock_Ip_InitClock(Config);

    if (DriverContext.ClockTreeIsConsumingPll)
    {
        PllStatus = Clock_Ip_GetPllStatus();
        if (CLOCK_IP_PLL_LOCKED == PllStatus)
        {
            Clock_Ip_DistributePll();
            ClockStatus = CLOCK_IP_SUCCESS;
        }
    }
    else
    {
        ClockStatus = CLOCK_IP_SUCCESS;
    }

    return ClockStatus;
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_InitClock
 *
 * Description   : Set the PLL and other MCU specific clock options.
 *                 This function initializes the PLL and other MCU specific clock options.
 *                 The clock configuration parameters are provided via the configuration structure.
 *
 *                 This function shall start the PLL lock procedure (if PLL
 *                 shall be initialized) and shall return without waiting until the PLL is locked.
 *
 * @implements Clock_Ip_InitClock_Activity
 * END**********************************************************************************/
void Clock_Ip_InitClock(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;


#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    /* Check clock elements from clock configuration */
    Clock_Ip_CheckClockConfiguration(Config);

    /* Reset the registers that will be written from DistributePll */
    Clock_Ip_ResetCountOfConfiguredRegisters();
#endif

    CLOCK_IP_DEV_ASSERT(NULL_PTR != Config);

    /* Save the current clock configuration to be used by "Clock_Ip_DistributePllClock". */
    Clock_Ip_pxConfig = Config;

    /* TODO to be removed, it's temporary */
    Clock_Ip_enable_all_gates();

    /* Platform specific initialization:
     * DFS reset, FIRC_CLK configuration etc. */
    Clock_Ip_Command(Config, CLOCK_IP_INITIALIZE_PLATFORM_COMMAND);

    /*********************************************************************
     ***  Ramp down to safe configuration. Reset elements from clock tree:
     ***  selectors, fractional dividers, plls and xoscs
     ***********************************************************************/


    /* Clear all the settings for CMU0/1/2... */
    /* In case one clock configuration has the CMU disabled, then need to make the transition to
    reset state of CMU modules. */
    Clock_Ip_Cmus__Disable(Config->CmusCount,*Config->Cmus);

    /* Ramp down all selectors from configuration to SAFE_CLOCK */
    Clock_Ip_Selectors__Reset(Config->SelectorsCount,*Config->Selectors);

    /* Put in reset state all fractional dividers from configuration */
    Clock_Ip_FracDivs__Reset(Config->FracDivsCount,*Config->FracDivs);

    /* Power down all plls from configuration */
    Clock_Ip_Plls__Reset(Config->PllsCount,*Config->Plls);

    /* Power down all xoscs from configuration */
    Clock_Ip_Xoscs__Reset(Config->XoscsCount,*Config->Xoscs);

    /* Software reset of all dividers. */
    Clock_Ip_Dividers__Reset(Config->DividersCount,*Config->Dividers);


    /*******************************************************
     *** Load the new configuration. Selectors that might
     *** be clocked from PLLs shouldn't be configured.
     *******************************************************/


    /* Initialize clock objects, internal driver data */
    Clock_Ip_UpdateDriverContext(Config);

    /* Configure all xoscs from configuration */
    Clock_Ip_Xoscs__Set(Config->XoscsCount,*Config->Xoscs);

    /* Enable all xoscs from configuration */
    Clock_Ip_Xoscs__Enable(Config->XoscsCount,*Config->Xoscs);

    /* Update dividers from configurations */
    Clock_Ip_Dividers__Set(Config->DividersCount,*Config->Dividers);

    /* Configure all plls from configuration asynchronously. Do not enable. */
    Clock_Ip_Pll__Set(Config->PllsCount,*Config->Plls);

    /* Wait for Xosc to lock. */
    Clock_Ip_Xoscs__Wait(Config->XoscsCount,*Config->Xoscs);

    /* Enable plls according to configuration asynchronously. Do not wait. */
    Clock_Ip_Pll__Enable(Config->PllsCount,*Config->Plls);

    /* Update all fractional dividers from clock configuration */
    Clock_Ip_FracDivs__Set(Config->FracDivsCount,*Config->FracDivs);

    /* Enable all fractional dividers from clock configuration */
    /* Note: The DFS configuration might actually need to be done after we
     * know that the PLLs are all locked in "Clock_Ip_GetPllStatus". */
    Clock_Ip_FracDivs__Enable(Config->FracDivsCount,*Config->FracDivs);


    DriverContext.ClockTreeIsConsumingPll = FALSE;                                  /* Check if clock tree is using a PLL output */
#if (defined(CLOCK_IP_SUPPORTS_WAIT_STATES))
#if (CLOCK_IP_SUPPORTS_WAIT_STATES == STD_ON)
    DriverContext.WaitStatesAreSupported = TRUE;                                    /* Wait states are supported */
#else
    DriverContext.WaitStatesAreSupported = FALSE;                                   /* Wait states are not supported */
#endif /*CLOCK_IP_SUPPORTS_WAIT_STATES == STD_ON */
#else
    DriverContext.WaitStatesAreSupported = FALSE;                                   /* Wait states are not supported */
#endif /* #if (defined(CLOCK_IP_SUPPORTS_WAIT_STATES)) */
    DriverContext.HwPllsNo = CLOCK_IP_NUMBER_OF_HARDWARE_PLL;                       /* Number of plls */
    DriverContext.HwDfsNo = CLOCK_IP_NUMBER_OF_HARDWARE_DFS;                        /* Number of fractional dividers */

#if ( defined(CLOCK_IP_HAS_RAM_WAIT_STATES) || defined(CLOCK_IP_HAS_FLASH_WAIT_STATES) )
    /* Configure wait states */
    Clock_Ip_SetWaitStates();
#endif

    /* Switch the clock multiplexers under MCU control to the configured source clocks */
    /* Note: if the configured source clock of a ClockMux is the output clock of a PLL/DFS,
     * the configuration will be skipped and the respective ClockMux will be switched in
     * the "Clock_Ip_DistributePllClock" function instead, when the source clock will have
     * stabilized already. */
    for (Index = 0U; Index < Config->SelectorsCount; Index++)    /* Set only if selected inputs are not clocked from PLLs */
    {
        if ((PLL_TYPE == Clock_Ip_aeSourceTypeClockName[(*(Config->Selectors))[Index].Source]))
        {
            /* At least one mux is consuming pll */
            DriverContext.ClockTreeIsConsumingPll = TRUE;
            break;
        }
    }

    if (RunOptimizedVersion_for_Mcu == FALSE)
    {
        if (DriverContext.ClockTreeIsConsumingPll == FALSE)
        {
            Clock_Ip_DistributeClock(CLOCK_IP_NO_PLL_DISTRIBUTION_TYPE);
        }
        else
        {
            Clock_Ip_DistributeClock(CLOCK_IP_FILTER_PLL_DISTRIBUTION_TYPE);
        }
    }
    else
    {
    #if (defined(CLOCK_IP_DEV_ERROR_DETECT))
      #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)

        if (DriverContext.ClockTreeIsConsumingPll == FALSE)
        {
            Clock_Ip_DistributeClock(CLOCK_IP_NO_PLL_DISTRIBUTION_TYPE);
        }
        else
        {
            Clock_Ip_DistributeClock(CLOCK_IP_FILTER_PLL_DISTRIBUTION_TYPE);
        }
      #endif
    #endif
        Clock_Ip_Registers_RunOnHardware();
    }
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_GetPllStatus
 * Description   : This function configures all clocks according to a clock configuration.
 * If no configuration is received, no change will be processed in HW and clock driver
 * will calculate frequencies only.
 *
 * @implements Clock_Ip_GetPllStatus_Activity
 * END**********************************************************************************/
Clock_Ip_PllStatusType Clock_Ip_GetPllStatus(void)
{
    Clock_Ip_PllStatusType RetValue = CLOCK_IP_PLL_STATUS_UNDEFINED;
    ClockLLD_StatusReturnType PllStatus = CLOCK_LLD_PLL_NOT_ENABLED_STATUS;
    ClockLLD_StatusReturnType DfsStatus = CLOCK_LLD_DFS_NOT_ENABLED_STATUS;

    uint32 Index;
    Clock_Ip_NameType PllClkName = gated_clk;  /* Clock name corresponding to pll */
    Clock_Ip_NameType FracDivClkName = gated_clk;  /* Clock name corresponding to fractional divider */

    if (Clock_Ip_pxConfig->PllsCount != 0U)
    {
        for (Index = 0U; Index < DriverContext.HwPllsNo; Index++)
        {
            PllClkName = Clock_Ip_aeHwPllName[Index];
            ClockLLD_Plls(PllClkName)->Wait();
            PllStatus = ClockLLD_Plls(PllClkName)->GetStatus();

            if (CLOCK_LLD_PLL_UNLOCKED_STATUS == PllStatus)
            {
                RetValue = CLOCK_IP_PLL_UNLOCKED;
                break;
            }
            else
            {
                if (CLOCK_LLD_PLL_LOCKED_STATUS == PllStatus)
                {
                    RetValue = CLOCK_IP_PLL_LOCKED;
                }
            }
        }

        if (CLOCK_IP_PLL_LOCKED == RetValue)
        {
            for (Index = 0U; Index < DriverContext.HwDfsNo; Index++)
            {
                FracDivClkName = Clock_Ip_aeHwDfsName[Index];
                ClockLLD_FracDividers(FracDivClkName)->Wait();
                DfsStatus = ClockLLD_FracDividers(PllClkName)->GetStatus();

                if (CLOCK_LLD_DFS_UNLOCKED_STATUS == DfsStatus)
                {
                    RetValue = CLOCK_IP_PLL_UNLOCKED;
                    break;
                }
            }
        }
    }
    else
    {
        RetValue = CLOCK_IP_PLL_LOCKED;
    }
    return RetValue;
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_DistributePll
 * Description   : Function completes the PLL configuration and then activates the PLL clock to Mcu
 * The function will not distribute the PLL clock if the driver state does not allow it, or the PLL is not stable.
 *
 * @implements Clock_Ip_DistributePll_Activity
 * END**********************************************************************************/
void Clock_Ip_DistributePll(void)
{

    if (NULL_PTR != Clock_Ip_pxConfig)
    {
        if (RunOptimizedVersion_for_Mcu == FALSE)
        {
            Clock_Ip_DistributeClock(CLOCK_IP_PLL_DISTRIBUTION_TYPE);
        }
        else
        {
        #if (defined(CLOCK_IP_DEV_ERROR_DETECT))
          #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
            Clock_Ip_DistributeClock(CLOCK_IP_PLL_DISTRIBUTION_TYPE);
          #endif
        #endif
            Clock_Ip_Registers_RunOnHardware();
        }
    }
}


/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_DisableClockMonitor
 * Description   : Disables a clock monitor.
 *
 * @implements Clock_Ip_DisableClockMonitor_Activity
 * END**********************************************************************************/
void Clock_Ip_DisableClockMonitor(Clock_Ip_NameType ClockName)
{
    (void)ClockName;
/*uint32 CallbackIndex;

    CallbackIndex = Clock_Ip_au8CmuCallbackIndex[Clock_Ip_au16ClockFeatures[ClockName][CLOCK_IP_CALLBACK]];
    Clock_Ip_axCmuCallbacks[CallbackIndex].Disable(ClockName);*/
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_InstallNotificationsCallback
 * Description   : This function installs a callback for clock notifications.
 *
 * @implements Clock_Ip_InstallNotificationsCallback_Activity
 * END**********************************************************************************/
void Clock_Ip_InstallNotificationsCallback(Clock_Ip_NotificationsCallbackType Callback)
{
    CLOCK_IP_DEV_ASSERT(NULL_PTR != Callback);

    Clock_Ip_pfkNotificationsCallback = Callback;
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_DisableModuleClock
 * Description   : Disables clock for a peripheral.
 *
 * @implements Clock_Ip_DisableModuleClock_Activity
 * END**********************************************************************************/
void Clock_Ip_DisableModuleClock(Clock_Ip_NameType ClockName)
{
    (void)ClockName;
    /* No implementation */
}

/*FUNCTION******************************************************************************
 *
 * Function Name : Clock_Ip_EnableModuleClock
 * Description   : Enable clock for a peripheral.
 *
 * @implements Clock_Ip_EnableModuleClock_Activity
 * END**********************************************************************************/
void Clock_Ip_EnableModuleClock(Clock_Ip_NameType ClockName)
{
    (void)ClockName;
    /* No implementation */
}


#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_SetUserAccessAllowed.
 * Description   : Set user access allowed.
 *
 *END**************************************************************************/
void Clock_Ip_SetUserAccessAllowed(void)
{
    Clock_Ip_Command(Clock_Ip_pxConfig, CLOCK_IP_SET_USER_ACCESS_ALLOWED_COMMAND);
}
  #endif
#endif


#if (defined(CLOCK_IP_GET_FREQUENCY_API))
  #if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_GetClockFrequency
 * Description   : This function returns the frequency of a given clock
 *
 * @implements Clock_Ip_GetClockFrequency_Activity
 * END**************************************************************************/
uint64 Clock_Ip_GetClockFrequency(Clock_Ip_NameType ClockName)
{
#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
  #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
    CLOCK_IP_DEV_ASSERT((((uint32)ClockName) < ((uint32)CLOCK_IP_NAMES_NO)) && (THE_LAST_PRODUCER_CLK != ClockName));
  #endif
#endif
    return Clock_Ip_GetFreq(ClockName);
}
    #endif
#endif


/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_SetWaitStates
 * Description   : Configure wait states
 *
 *END**************************************************************************/
#if ( defined(CLOCK_IP_HAS_RAM_WAIT_STATES) || defined(CLOCK_IP_HAS_FLASH_WAIT_STATES) )
static void Clock_Ip_SetWaitStates(void)
{
#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES
    /* The entry point of the flash and RAM controllers configuration. */
#ifdef CLOCK_IP_PREPARE_MEMORY_CONFIG
    CLOCK_IP_PREPARE_MEMORY_CONFIG(CLOCK_IP_RAM_MEMORY_CONFIG_ENTRY_POINT);
#else
    Clock_Ip_pfkNotificationsCallback(CLOCK_IP_RAM_MEMORY_CONFIG_ENTRY, RESERVED_CLK);
#endif

    Clock_Ip_SetRamWaitStates();

    /* The exit point of the flash and RAM controllers configuration. */
#ifdef CLOCK_IP_PREPARE_MEMORY_CONFIG
    CLOCK_IP_PREPARE_MEMORY_CONFIG(CLOCK_IP_RAM_MEMORY_CONFIG_EXIT_POINT);
#else
    Clock_Ip_pfkNotificationsCallback(CLOCK_IP_RAM_MEMORY_CONFIG_EXIT, RESERVED_CLK);
#endif
#endif

#ifdef CLOCK_IP_HAS_FLASH_WAIT_STATES
    /* The entry point of the flash and RAM controllers configuration. */
#ifdef CLOCK_IP_PREPARE_MEMORY_CONFIG
    CLOCK_IP_PREPARE_MEMORY_CONFIG(CLOCK_IP_FLASH_MEMORY_CONFIG_ENTRY_POINT);
#else
    Clock_Ip_pfkNotificationsCallback(CLOCK_IP_FLASH_MEMORY_CONFIG_ENTRY, RESERVED_CLK);
#endif

    Clock_Ip_SetFlashWaitStates();

    /* The exit point of the flash and RAM controllers configuration. */
#ifdef CLOCK_IP_PREPARE_MEMORY_CONFIG
    CLOCK_IP_PREPARE_MEMORY_CONFIG(CLOCK_IP_FLASH_MEMORY_CONFIG_EXIT_POINT);
#else
    Clock_Ip_pfkNotificationsCallback(CLOCK_IP_FLASH_MEMORY_CONFIG_EXIT, RESERVED_CLK);
#endif
#endif
}
#endif /* ( defined(CLOCK_IP_HAS_RAM_WAIT_STATES) || defined(CLOCK_IP_HAS_FLASH_WAIT_STATES) ) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_ReportClockErrors
 * Description   : Report clock error
 *
 *END**************************************************************************/
void Clock_Ip_ReportClockErrors(Clock_Ip_NotificationType Error, Clock_Ip_NameType ClockName)
{
    Clock_Ip_pfkNotificationsCallback(Error,ClockName);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void Clock_Ip_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(CLOCK_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, CLOCK_IP_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Clock_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean Clock_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, CLOCK_IP_TIMEOUT_TYPE);

    if (*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }
    return RetVal;
}

static void Clock_Ip_Registers_RunOnHardware(void)
{
    Clock_Ip_LoggedRegisterIndex = 0U;
    Clock_Ip_RegisterIndex = 0U;

    if (Clock_Ip_GetCountOfConfiguredRegisters() > 0U)
    {
        while (Clock_Ip_RegisterIndex < Clock_Ip_pxConfig->ConfiguredRegistersCount)
        {
#ifndef CLOCK_IP_DO_NOT_LOG_REGITSTER_VALUES
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].RegisterIndex            = Clock_Ip_RegisterIndex;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].ClockName                = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].ClockName;

            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].RegisterAccessOperation  = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].RegisterAccessOperation;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].Event                    = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].Event;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].BranchOffset1            = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].BranchOffset1;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].BranchOffset2            = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].BranchOffset2;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].Address                  = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].Address;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].ConstAddress             = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].ConstAddress;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].Mask                     = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].Mask;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].Value                    = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].Value;

            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].BufferIndex              = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].BufferIndex;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].ResourceType             = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].ResourceType;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].OperationType            = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].OperationType;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].FunctionName             = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].FunctionName;
            Clock_Ip_LoggedRegisterValues[Clock_Ip_LoggedRegisterIndex].State                    = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].State;

            Clock_Ip_LoggedRegisterIndex = Clock_Ip_LoggedRegisterIndex + 1U;
#endif

            Clock_Ip_RegisterAccessOperations[(*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex].RegisterAccessOperation]();
        }
    }
}

static void Clock_Ip_RegisterAccess_CheckRegisterValue(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;
    Clock_Ip_Value = Clock_Ip_Register->Value;

    if ((*Clock_Ip_RegAddress & Clock_Ip_Mask) == Clock_Ip_Value)
    {
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
    }
    else
    {
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset2;
    }
}

static void Clock_Ip_RegisterAccess_CheckRegisterValue_WithEvent(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;
    Clock_Ip_Value = Clock_Ip_Register->Value;

    if ((*Clock_Ip_RegAddress & Clock_Ip_Mask) == Clock_Ip_Value)
    {
        Clock_Ip_ReportClockErrors((Clock_Ip_NotificationType)Clock_Ip_Register->Event, Clock_Ip_Register->ClockName);
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
    }
    else
    {
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset2;
    }
}

static void Clock_Ip_RegisterAccess_CheckNotRegisterValue_WithEvent(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;
    Clock_Ip_Value = Clock_Ip_Register->Value;

    if ((*Clock_Ip_RegAddress & Clock_Ip_Mask) != Clock_Ip_Value)
    {
        Clock_Ip_ReportClockErrors((Clock_Ip_NotificationType)Clock_Ip_Register->Event, Clock_Ip_Register->ClockName);
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
    }
    else
    {
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset2;
    }
}

static void Clock_Ip_RegisterAccess_CheckRegisterValue_WithTimeout(void)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;
    Clock_Ip_Value = Clock_Ip_Register->Value;

    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    /* Wait until the output clock is ungated. */
    do
    {
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while (((*Clock_Ip_RegAddress & Clock_Ip_Mask) != Clock_Ip_Value) && (FALSE == TimeoutOccurred));

    if (TRUE == TimeoutOccurred)
    {
        Clock_Ip_ReportClockErrors((Clock_Ip_NotificationType)Clock_Ip_Register->Event, Clock_Ip_Register->ClockName);
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
    }
    else
    {
        Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset2;
    }
}

static void Clock_Ip_RegisterAccess_ReadModifyWrite(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;
    Clock_Ip_Value = Clock_Ip_Register->Value;

    Clock_Ip_RegisterValue = *Clock_Ip_RegAddress;
    Clock_Ip_RegisterValue &= ~Clock_Ip_Mask;
    Clock_Ip_RegisterValue |= Clock_Ip_Value;
    *Clock_Ip_RegAddress = Clock_Ip_RegisterValue;

    Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
}

static void Clock_Ip_RegisterAccess_Write(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Value = Clock_Ip_Register->Value;

    *Clock_Ip_RegAddress = Clock_Ip_Value;

    Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
}

static void Clock_Ip_RegisterAccess_SetBit(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;

    *Clock_Ip_RegAddress |= Clock_Ip_Mask;

    Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
}

static void Clock_Ip_RegisterAccess_ClearBit(void)
{
    Clock_Ip_Register = &((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegisterIndex]);

    Clock_Ip_RegAddress = Clock_Ip_Register->Address;
    Clock_Ip_Mask = Clock_Ip_Register->Mask;

    *Clock_Ip_RegAddress &= ~Clock_Ip_Mask;

    Clock_Ip_RegisterIndex = Clock_Ip_RegisterIndex + Clock_Ip_Register->BranchOffset1;
}


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
