/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_ExtOsc.c
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
#define CLOCK_IP_EXTOSC_VENDOR_ID_C                      43
#define CLOCK_IP_EXTOSC_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_EXTOSC_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_EXTOSC_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_EXTOSC_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_EXTOSC_SW_MINOR_VERSION_C               8
#define CLOCK_IP_EXTOSC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_ExtOsc.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_EXTOSC_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_ExtOsc.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_ExtOsc.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_EXTOSC_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_EXTOSC_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_EXTOSC_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_ExtOsc.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_ExtOsc.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_EXTOSC_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_EXTOSC_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_EXTOSC_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_ExtOsc.c and Clock_Ip_Private.h are different"
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

static Clock_Ip_NameType Clock_Ip_XoscName = RESERVED_CLK;

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

static void Clock_Ip_ExternalOscillatorEmptyName(Clock_Ip_NameType Name);
static void Clock_Ip_ExternalOscillatorEmpty1(void);
static void Clock_Ip_ExternalOscillatorEmpty2(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_ExternalOscillatorEmpty3(uint32 ExternalOscillatorFrequency, ClockLLD_XoscModeType Mode, uint32 StartupStabilizationTime, uint32 Transconductance);
static ClockLLD_StatusReturnType Clock_Ip_ExternalOscillatorEmpty4(void);

#ifdef CLOCK_IP_FXOSC_CTRL_OSCON_ALC_D_GM_SEL_EOCV_COMP_EN_OSC_BYP_OSC_STAT
static void Clock_Ip_SetNameFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(Clock_Ip_NameType Name);
static void Clock_Ip_ResetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void);
static void Clock_Ip_SetOptionalParameterFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(uint32 ExternalOscillatorFrequency,ClockLLD_XoscModeType Mode,uint32 StartupStabilizationTime,uint32 Transconductance);
static void Clock_Ip_EnableFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void);
static void Clock_Ip_WaitFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void);
static void Clock_Ip_LockFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(uint32 ExternalOscillatorFrequency,ClockLLD_XoscModeType Mode,uint32 StartupStabilizationTime,uint32 Transconductance);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void);
#endif
#ifdef CLOCK_IP_SXOSC_CTRL_OSCON_GM_SEL_EOCV_CURR_PRG_STAT
static void Clock_Ip_SetNameSxoscCtrlOsconGmSelEocvCurrPrgStat(Clock_Ip_NameType Name);
static void Clock_Ip_ResetSxoscCtrlOsconGmSelEocvCurrPrgStat(void);
static void Clock_Ip_SetOptionalParameterSxoscCtrlOsconGmSelEocvCurrPrgStat(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetSxoscCtrlOsconGmSelEocvCurrPrgStat(uint32 ExternalOscillatorFrequency,ClockLLD_XoscModeType Mode,uint32 StartupStabilizationTime,uint32 Transconductance);
static void Clock_Ip_EnableSxoscCtrlOsconGmSelEocvCurrPrgStat(void);
static void Clock_Ip_WaitSxoscCtrlOsconGmSelEocvCurrPrgStat(void);
static void Clock_Ip_LockSxoscCtrlOsconGmSelEocvCurrPrgStat(uint32 ExternalOscillatorFrequency,ClockLLD_XoscModeType Mode,uint32 StartupStabilizationTime,uint32 Transconductance);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusSxoscCtrlOsconGmSelEocvCurrPrgStat(void);
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

static void Clock_Ip_ExternalOscillatorEmptyName(Clock_Ip_NameType Name)
{
    Clock_Ip_XoscName = Name;
}
static void Clock_Ip_ExternalOscillatorEmpty1(void)
{
    /* No implementation */
}
static void Clock_Ip_ExternalOscillatorEmpty2(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_ExternalOscillatorEmpty3(uint32 ExternalOscillatorFrequency, ClockLLD_XoscModeType Mode, uint32 StartupStabilizationTime, uint32 Transconductance)
{
    (void)ExternalOscillatorFrequency;
    (void)Mode;
    (void)StartupStabilizationTime;
    (void)Transconductance;
    /* No implementation */
}
static ClockLLD_StatusReturnType Clock_Ip_ExternalOscillatorEmpty4(void)
{
    return CLOCK_LLD_STATUS_SUCCESS;
}
#ifdef CLOCK_IP_FXOSC_CTRL_OSCON_ALC_D_GM_SEL_EOCV_COMP_EN_OSC_BYP_OSC_STAT
static void Clock_Ip_SetNameFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(Clock_Ip_NameType Name)
{
    Clock_Ip_XoscName = Name;
}

static void Clock_Ip_ResetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void)
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 FxoscStatus;

    /* Disable XOSC */
    Clock_Ip_apxXosc[Instance]->CTRL &= ~FXOSC_CTRL_OSCON_MASK;
    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    /* Wait until xosc is locked */
    do
    {
        FxoscStatus = ((Clock_Ip_apxXosc[Instance]->STAT & FXOSC_STAT_OSC_STAT_MASK) >> FXOSC_STAT_OSC_STAT_SHIFT);
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while ((1U == FxoscStatus) && (FALSE == TimeoutOccurred));

    if (TimeoutOccurred)
    {
        /* Report timeout error */
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_XoscName);
    }
}

static void Clock_Ip_SetOptionalParameterFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value)
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];
    uint32 RegValue;

    switch (ParamId)
    {
        case CLOCK_LLD_XOSC_AUTOMATIC_LEVEL_CONTROLLER_ID:
        {
            RegValue = Clock_Ip_apxXosc[Instance]->CTRL;
            RegValue &= ~FXOSC_CTRL_ALC_D_MASK;
            RegValue |= FXOSC_CTRL_ALC_D(Value);
            Clock_Ip_apxXosc[Instance]->CTRL = RegValue;
        }
        break;
        default:
        {
            /* Invalid parameter type */
        }
    }
}

/* Set Fxosc configuration to register */
static void Clock_Ip_SetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(
    uint32 ExternalOscillatorFrequency,
    ClockLLD_XoscModeType Mode,
    uint32 StartupStabilizationTime,
    uint32 Transconductance)
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];
    uint32 RegValue = Clock_Ip_apxXosc[Instance]->CTRL;

    switch (Mode)
    {
        case CLOCK_LLD_XOSC_SINGLE_ENDED_MODE:
        case CLOCK_LLD_XOSC_BYPASS_MODE:
        {
            RegValue |= FXOSC_CTRL_OSC_BYP(1U);
        }
        break;
        case CLOCK_LLD_XOSC_DIFFERENTIAL_MODE:
        case CLOCK_LLD_XOSC_CRYSTAL_MODE:
        {
            RegValue |= FXOSC_CTRL_COMP_EN(1U);
        }
        break;
        default:
        {
            /* Nothing to implement here. */
        }
        break;
    }
    RegValue |= FXOSC_CTRL_GM_SEL(Transconductance);
	RegValue |= FXOSC_CTRL_EOCV(StartupStabilizationTime);
	Clock_Ip_apxXosc[Instance]->CTRL = RegValue;

    #ifdef CLOCK_IP_GET_FREQUENCY_API
    #if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)
        Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_XoscName,ExternalOscillatorFrequency);
    #endif
    #endif
}

static void Clock_Ip_EnableFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat()
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    /* Enable SOSC. */
    Clock_Ip_apxXosc[Instance]->CTRL |= FXOSC_CTRL_OSCON_MASK;
}

static void Clock_Ip_WaitFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 FxoscStatus;
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    if ((Clock_Ip_apxXosc[Instance]->CTRL & FXOSC_CTRL_OSCON_MASK) != 0U)
    {
        /* This assumes that FXOSC_CTRL[COMP_EN] = 1 and FXOSC_CTRL[OSC_BYP] = 0 (i.e. crystal clock/oscillator output). */
        /* In bypass mode (i.e. EXTAL output), FXOSC_CTRL[COMP_EN] = 0 and FXOSC_CTRL[OSC_BYP] = 1, which means that
           we cannot check for stabilization. This shifts the responsibility of waiting for a stable clock to the
           upper layers. */
        if ((Clock_Ip_apxXosc[Instance]->CTRL & FXOSC_CTRL_COMP_EN_MASK) != 0U)
        {
            if ((Clock_Ip_apxXosc[Instance]->CTRL & FXOSC_CTRL_OSC_BYP_MASK) == 0U)
            {
                Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
                /* Wait until xosc is locked */
                do
                {
                    FxoscStatus = ((Clock_Ip_apxXosc[Instance]->STAT & FXOSC_STAT_OSC_STAT_MASK) >> FXOSC_STAT_OSC_STAT_SHIFT);
                    TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                }
                while ((0U == FxoscStatus) && (FALSE == TimeoutOccurred));

                if (TimeoutOccurred)
                {
                    /* Report timeout error */
                    Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_XoscName);
                }
            }
            else
            {
                /* Invalid FXOSC configuration: FXOSC_CTRL[COMP_EN] = 1 enforces FXOSC_CTRL[OSC_BYP] = 0. */
                /* Report timeout error */
                Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_FXOSC_CONFIGURATION_ERROR, Clock_Ip_XoscName);
            }
        }
    }

}

static void Clock_Ip_LockFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(
    uint32 ExternalOscillatorFrequency,
    ClockLLD_XoscModeType Mode,
    uint32 StartupStabilizationTime,
    uint32 Transconductance)
{
    Clock_Ip_SetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(
        ExternalOscillatorFrequency,
        Mode,
        StartupStabilizationTime,
        Transconductance
    );
    Clock_Ip_EnableFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat();
    Clock_Ip_WaitFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat();
}

static ClockLLD_StatusReturnType Clock_Ip_GetStatusFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat(void)
{
    ClockLLD_StatusReturnType FxoscStatus = CLOCK_LLD_XOSC_LOCKED_STATUS;
    uint32 FxoscLockStatus;
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    if (0U == (Clock_Ip_apxXosc[Instance]->CTRL & FXOSC_CTRL_OSCON_MASK))
    {
         FxoscLockStatus = ((Clock_Ip_apxXosc[Instance]->STAT & FXOSC_STAT_OSC_STAT_MASK) >> FXOSC_STAT_OSC_STAT_SHIFT);

        if (0U == FxoscLockStatus)
        {
            FxoscStatus = CLOCK_LLD_XOSC_UNLOCKED_STATUS;
        }
    }
    else
    {
        FxoscStatus = CLOCK_LLD_XOSC_NOT_ENABLED_STATUS;
    }

    return FxoscStatus;
}

#endif
#ifdef CLOCK_IP_SXOSC_CTRL_OSCON_GM_SEL_EOCV_CURR_PRG_STAT
static void Clock_Ip_SetNameSxoscCtrlOsconGmSelEocvCurrPrgStat(Clock_Ip_NameType Name)
{
    Clock_Ip_XoscName = Name;
}

static void Clock_Ip_ResetSxoscCtrlOsconGmSelEocvCurrPrgStat(void)
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    /* Todo remove this workaround */
    Instance = 1U;


    /* Disable XOSC */
    Clock_Ip_apxXosc[Instance]->CTRL &= ~(  SXOSC_CTRL_OSCON_MASK |
                                            SXOSC_CTRL_GM_SEL_MASK |
                                            SXOSC_CTRL_EOCV_MASK |
                                            SXOSC_CTRL_CURR_PRG_MASK );
}

static void Clock_Ip_SetOptionalParameterSxoscCtrlOsconGmSelEocvCurrPrgStat(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value)
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];
    uint32 RegValue;

    /* Todo remove this workaround */
    Instance = 1U;

    switch (ParamId)
    {
        case CLOCK_LLD_XOSC_PROGRAMMABILITY_COMPARATOR_CURRENT_ID:
        {
            RegValue = Clock_Ip_apxXosc[Instance]->CTRL;
            RegValue &= ~SXOSC_CTRL_CURR_PRG_MASK;
            RegValue |= SXOSC_CTRL_CURR_PRG(Value);
            Clock_Ip_apxXosc[Instance]->CTRL = RegValue;
        }
        break;
        default:
        {
            /* Invalid parameter type */
        }
    }
}

/* Set Fxosc configuration to register */
static void Clock_Ip_SetSxoscCtrlOsconGmSelEocvCurrPrgStat(
    uint32 ExternalOscillatorFrequency,
    ClockLLD_XoscModeType Mode,
    uint32 StartupStabilizationTime,
    uint32 Transconductance)
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];
    uint32 RegValue;

    (void)Mode;

    /* Todo remove this workaround */
    Instance = 1U;

    RegValue = Clock_Ip_apxXosc[Instance]->CTRL;
    RegValue = Clock_Ip_apxXosc[Instance]->CTRL;
    RegValue &= ~(  SXOSC_CTRL_GM_SEL_MASK |
                    SXOSC_CTRL_EOCV_MASK);
    RegValue|= (SXOSC_CTRL_EOCV(StartupStabilizationTime)     |
                SXOSC_CTRL_GM_SEL(Transconductance)
                );

    RegValue |= FXOSC_CTRL_GM_SEL(Transconductance);
	RegValue |= FXOSC_CTRL_EOCV(StartupStabilizationTime);
	Clock_Ip_apxXosc[Instance]->CTRL = RegValue;

    #ifdef CLOCK_IP_GET_FREQUENCY_API
    #if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)
        Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_XoscName,ExternalOscillatorFrequency);
    #endif
    #endif
}

static void Clock_Ip_EnableSxoscCtrlOsconGmSelEocvCurrPrgStat()
{
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    /* Enable XOSC. */
    Clock_Ip_apxXosc[Instance]->CTRL |= SXOSC_CTRL_OSCON_MASK;
}

static void Clock_Ip_WaitSxoscCtrlOsconGmSelEocvCurrPrgStat(void)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 XoscStatus;
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    /* Todo remove this workaround */
    Instance = 1U;

    if ((Clock_Ip_apxXosc[Instance]->CTRL & SXOSC_CTRL_OSCON_MASK) != 0U)
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until xosc is locked */
        do
        {
            XoscStatus = ((Clock_Ip_apxXosc[Instance]->STAT & SXOSC_STAT_OSC_STAT_MASK) >> SXOSC_STAT_OSC_STAT_SHIFT);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == XoscStatus) && (FALSE == TimeoutOccurred));

        if (TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_XoscName);
        }
    }
}

static void Clock_Ip_LockSxoscCtrlOsconGmSelEocvCurrPrgStat(
    uint32 ExternalOscillatorFrequency,
    ClockLLD_XoscModeType Mode,
    uint32 StartupStabilizationTime,
    uint32 Transconductance)
{
    Clock_Ip_SetSxoscCtrlOsconGmSelEocvCurrPrgStat(
        ExternalOscillatorFrequency,
        Mode,
        StartupStabilizationTime,
        Transconductance
    );
    Clock_Ip_EnableSxoscCtrlOsconGmSelEocvCurrPrgStat();
    Clock_Ip_WaitSxoscCtrlOsconGmSelEocvCurrPrgStat();
}

static ClockLLD_StatusReturnType Clock_Ip_GetStatusSxoscCtrlOsconGmSelEocvCurrPrgStat(void)
{
    ClockLLD_StatusReturnType XoscStatus = CLOCK_LLD_XOSC_LOCKED_STATUS;
    uint32 XoscLockStatus;
    uint32 Instance = Clock_Ip_au16ClockFeatures[Clock_Ip_XoscName][CLOCK_LLD_MODULE_INSTANCE];

    /* Todo remove this workaround */
    Instance = 1U;

    if (0U == (Clock_Ip_apxXosc[Instance]->CTRL & FXOSC_CTRL_OSCON_MASK))
    {
         XoscLockStatus = ((Clock_Ip_apxXosc[Instance]->STAT & SXOSC_STAT_OSC_STAT_MASK) >> SXOSC_STAT_OSC_STAT_SHIFT);

        if (0U == XoscLockStatus)
        {
            XoscStatus = CLOCK_LLD_XOSC_UNLOCKED_STATUS;
        }
    }
    else
    {
        XoscStatus = CLOCK_LLD_XOSC_NOT_ENABLED_STATUS;
    }

    return XoscStatus;
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

const Clock_Ip_ExtOscCallbackType Clock_Ip_axExtOscCallbacks[CLOCK_IP_XOSC_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_ExternalOscillatorEmptyName,                            /* SetName */
        &Clock_Ip_ExternalOscillatorEmpty1,                               /* Reset */
        &Clock_Ip_ExternalOscillatorEmpty1,                               /* Disable */
        &Clock_Ip_ExternalOscillatorEmpty2,                               /* SetOptionalParameter */
        &Clock_Ip_ExternalOscillatorEmpty3,                               /* Set */
        &Clock_Ip_ExternalOscillatorEmpty1,                               /* Start */
        &Clock_Ip_ExternalOscillatorEmpty1,                               /* Enable */
        &Clock_Ip_ExternalOscillatorEmpty1,                               /* Wait */
        &Clock_Ip_ExternalOscillatorEmpty3,                               /* Lock */
        &Clock_Ip_ExternalOscillatorEmpty4,                               /* GetStatus */
    },
#ifdef CLOCK_IP_FXOSC_CTRL_OSCON_ALC_D_GM_SEL_EOCV_COMP_EN_OSC_BYP_OSC_STAT
    {
        &Clock_Ip_SetNameFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,              /* Name */
        &Clock_Ip_ResetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,                /* Reset */
        &Clock_Ip_ResetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,                /* Disable */
        &Clock_Ip_SetOptionalParameterFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat, /* SetOptionalParameter */
        &Clock_Ip_SetFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,                  /* Set */
        &Clock_Ip_EnableFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,               /* Start */
        &Clock_Ip_EnableFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,               /* Enable */
        &Clock_Ip_WaitFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,                 /* Wait */
        &Clock_Ip_LockFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,                 /* Lock */
        &Clock_Ip_GetStatusFxoscCtrlOsconAlcdGmSelEocvCompEnOscBypOscStat,            /* GetStatus */
    },
#endif
#ifdef CLOCK_IP_SXOSC_CTRL_OSCON_GM_SEL_EOCV_CURR_PRG_STAT
    {
        &Clock_Ip_SetNameSxoscCtrlOsconGmSelEocvCurrPrgStat,              /* Name */
        &Clock_Ip_ResetSxoscCtrlOsconGmSelEocvCurrPrgStat,                /* Reset */
        &Clock_Ip_ResetSxoscCtrlOsconGmSelEocvCurrPrgStat,                /* Disable */
        &Clock_Ip_SetOptionalParameterSxoscCtrlOsconGmSelEocvCurrPrgStat, /* SetOptionalParameter */
        &Clock_Ip_SetSxoscCtrlOsconGmSelEocvCurrPrgStat,                  /* Set */
        &Clock_Ip_EnableSxoscCtrlOsconGmSelEocvCurrPrgStat,               /* Start */
        &Clock_Ip_EnableSxoscCtrlOsconGmSelEocvCurrPrgStat,               /* Enable */
        &Clock_Ip_WaitSxoscCtrlOsconGmSelEocvCurrPrgStat,                 /* Wait */
        &Clock_Ip_LockSxoscCtrlOsconGmSelEocvCurrPrgStat,                 /* Lock */
        &Clock_Ip_GetStatusSxoscCtrlOsconGmSelEocvCurrPrgStat,            /* GetStatus */
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

