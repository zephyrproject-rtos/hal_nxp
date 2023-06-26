/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file       Emios_Pwm_Ip.c
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
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
#include "Emios_Pwm_Ip.h"
#include "Emios_Pwm_Ip_HwAccess.h"

#if (EMIOS_PWM_IP_USED == STD_ON)
#include "Emios_Mcl_Ip.h"
#endif

#include "SchM_Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_VENDOR_ID_C                      43
#define EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION_C       7
#define EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION_C    0
#define EMIOS_PWM_IP_SW_MAJOR_VERSION_C               3
#define EMIOS_PWM_IP_SW_MINOR_VERSION_C               0
#define EMIOS_PWM_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

#if (EMIOS_PWM_IP_USED == STD_ON)
    /* Check if header file and Emios_Mcl_Ip.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION_C != EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip.c and Emios_Mcl_Ip.h are different"
    #endif
#endif

    /* Check if this source file and SchM_Pwm.h file are of the same Autosar version */
    #if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_PWM_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_PWM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Pwm_Ip.c and SchM_Pwm.h are different"
    #endif
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same vendor */
#if (EMIOS_PWM_IP_VENDOR_ID_C != EMIOS_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same Software version */
#if ((EMIOS_PWM_IP_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_SW_MAJOR_VERSION)  || \
     (EMIOS_PWM_IP_SW_MINOR_VERSION_C != EMIOS_PWM_IP_SW_MINOR_VERSION)  || \
     (EMIOS_PWM_IP_SW_PATCH_VERSION_C != EMIOS_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_HwAccess.h file are of the same vendor */
#if (EMIOS_PWM_IP_VENDOR_ID_C != EMIOS_PWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip.c and Emios_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_HwAccess.h file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip.c and Emios_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_HwAccess.h file are of the same Software version */
#if ((EMIOS_PWM_IP_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
     (EMIOS_PWM_IP_SW_MINOR_VERSION_C != EMIOS_PWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
     (EMIOS_PWM_IP_SW_PATCH_VERSION_C != EMIOS_PWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip.c and Emios_Pwm_Ip_HwAccess.h are different."
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
#if (EMIOS_PWM_IP_USED == STD_ON)
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with Base addresses for Emios instances available on platform */
Emios_Pwm_Ip_HwAddrType *const Emios_Pwm_Ip_aBasePtr[EMIOS_PWM_IP_INSTANCE_COUNT] = IP_eMIOS_BASE_PTRS;

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#define PWM_START_SEC_VAR_INIT_32
#include "Pwm_MemMap.h"

/* Array with available pwm modes for each Emios Channel */
static uint32 Emios_Pwm_Ip_aChannelModes[EMIOS_PWM_IP_INSTANCE_COUNT][EMIOS_PWM_IP_MODES] = EMIOS_PWM_IP_CHANNEL_MODES;

#define PWM_STOP_SEC_VAR_INIT_32
#include "Pwm_MemMap.h"
#endif

#define PWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

/* Array with initial pwm modes for each Emios Channel */
static Emios_Pwm_Ip_PwmModeType Emios_Pwm_Ip_aInitialModes[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED] = EMIOS_PWM_IP_INITIAL_MODES;

/* Array with current pwm modes for each Emios Channel */
Emios_Pwm_Ip_PwmModeType Emios_Pwm_Ip_aCurrentModes[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED] = EMIOS_PWM_IP_INITIAL_MODES;

#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with notification handlers for all configurable channels */
Emios_Pwm_Ip_NotificationType const *Emios_Pwm_Ip_aNotificationPtr[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
#define PWM_START_SEC_VAR_CLEARED_32
#include "Pwm_MemMap.h"
#else
#define PWM_START_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"
#endif
/** @brief Array with period for each channels */
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_aPeriod[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Array to store register A value for each channels */
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_aRegA[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Array with duty cycle for all channels */
Emios_Pwm_Ip_DutyType Emios_Pwm_Ip_aDutyCycle[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
#define PWM_STOP_SEC_VAR_CLEARED_32
#include "Pwm_MemMap.h"
#else
#define PWM_STOP_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"
#endif

#define PWM_START_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

/** @brief Arrays to check the condition whether Channel can be enale notification or not */
uint8 Emios_Pwm_Ip_aNotif[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Arrays to check the state of Channel in the notification or not */
uint8 Emios_Pwm_Ip_aCheckEnableNotif[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Arrays with the polarity of channels */
uint8 Emios_Pwm_Ip_aPolarity[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Arrays to check the state of Channel is initial state or uninitialized state or idle state */
uint8 Emios_Pwm_Ip_aCheckState[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

#define PWM_STOP_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_INIT_8
#include "Pwm_MemMap.h"

/* Arrays to store the channel logic Index State */
uint8 eMios_Pwm_Ip_IndexInChState[EMIOS_PWM_IP_INSTANCE_COUNT][EMIOS_PWM_IP_CHANNEL_COUNT] = EMIOS_PWM_IP_USED_CHANNELS;

#define PWM_STOP_SEC_VAR_INIT_8
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
/*---------------------Validation API------------------------*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_ValidateMode
 * Description   : Validate a eMIOS Mode can run on the Channel or not.
 *END**************************************************************************/
static inline boolean Emios_Pwm_Ip_ValidateMode(uint8  Instance,
                                                uint8  Channel,
                                                Emios_Pwm_Ip_PwmType Mode)
{
    boolean Ret = FALSE;
    if((uint8)Mode < (uint8)EMIOS_PWM_IP_MODES)
    {
        Ret = (((Emios_Pwm_Ip_aChannelModes[Instance][(uint8)Mode] >> Channel) & 0x01UL) == 1UL) ? TRUE : FALSE;
    }
    else
    {
        /* Avoid compiler warning */
        (void) Instance;
        (void) Channel;
        (void) Mode;
    }
    return Ret;
}

#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_GetCounterBusPeriod
 * Description   : Return the period for Channel using an external counter bus.
 * Only used for channels in OPWMB/OPWMCB/OPWMT modes
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetCounterBusPeriod(uint8 Instance,
                                                      uint8 Channel,
                                                      Emios_Pwm_Ip_CounterBusSourceType CounterBus)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_PeriodType ChPeriod = 0U;
    uint8 MasterBusCh = Emios_Pwm_Ip_GetTimebaseChannel(Channel, CounterBus);

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    /* The used channel in internal counter or undefined mode. */
    DevAssert(0xFFU != MasterBusCh);
#endif

    ChPeriod = Emios_Mcl_Ip_GetCounterBusPeriod(Instance, MasterBusCh);

    return ChPeriod;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_GetCounterBusMode
 * Description   : Return the counter bus Mode for Channel using an external counter bus.
 * Only used for channels in OPWMB/OPWMCB/OPWMT modes
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_MasterBusModeType Emios_Pwm_Ip_GetCounterBusMode(uint8 Instance,
                                                                            uint8 Channel,
                                                                            Emios_Pwm_Ip_CounterBusSourceType CounterBus)
{

    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_MasterBusModeType CounterBusMode = EMIOS_PWM_IP_MC_UP_COUNTER_START;
    switch (CounterBus)
    {
        case EMIOS_PWM_IP_BUS_A:
            CounterBusMode = (Emios_Pwm_Ip_MasterBusModeType)Emios_Pwm_Ip_GetChannelPwmMode(Base, EMIOS_PWM_IP_COUNTER_BUS_A);
            break;
        case EMIOS_PWM_IP_BUS_BCDE:
            CounterBusMode = (Emios_Pwm_Ip_MasterBusModeType)Emios_Pwm_Ip_GetChannelPwmMode(Base, (Channel & (uint8)EMIOS_PWM_IP_COUNTER_BUS_BCDE));
            break;
        case EMIOS_PWM_IP_BUS_F:
            CounterBusMode = (Emios_Pwm_Ip_MasterBusModeType)Emios_Pwm_Ip_GetChannelPwmMode(Base, EMIOS_PWM_IP_COUNTER_BUS_F);
            break;
        default:
            /* internal counter bus */
            CounterBusMode = EMIOS_PWM_IP_NODEFINE_COUNTER;
            break;
    }

    return CounterBusMode;
}
#ifdef EMIOS_PWM_IP_MODE_OPWFMB_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitPeriodDutyCycleOpwfmbMode
 * Description   : Initial Output Pulse Width and Frequency Modulation Buffered Mode - OPWFMB Mode.
 * This Mode provides waveforms with variable duty cycle and frequency. The internal Channel counter
 * is automatically selected as the time Base when this Mode is selected.
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitPeriodDutyCycleOpwfmbMode(uint8 Instance,
                                                       Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected Channel is set for OPWFMB */
    DevAssert((UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWFMB_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH));
    /* Check that Channel has internal counter for this Mode */
    DevAssert(TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWFMB));
    /* Validate parametter */
    DevAssert(EMIOS_PWM_IP_MIN_CNT_VAL < UserChCfg->PeriodCount);
    DevAssert(UserChCfg->DutyCycle <= UserChCfg->PeriodCount);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    /* Configure OPWFMB special parameters */
    /* Configure Counter Bus used by this Channel */
    Emios_Pwm_Ip_SetCounterBus(Base, UserChCfg->ChannelId, UserChCfg->Timebase);
    /* Configure DutyCycle in reg A */
    Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, UserChCfg->DutyCycle);
    /* Configure Period in reg B */
    Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, UserChCfg->PeriodCount);

    Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->PeriodCount;

    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {   /* 100% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        /* To avoid spike pulse
        If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
        after that, EDPOL bit is restored valid value */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    }
    else if(0U == UserChCfg->DutyCycle)
    {
        /* 0% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        /* Configure output pin polarity */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
    }
    else
    {
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
    }
    /* Transition from GPIO Mode to OPWFMB Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, UserChCfg->ChannelId, UserChCfg->Mode);
    /* Configure output pin polarity */
    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
    /* Stores the inital duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;
}
#endif /* EMIOS_PWM_IP_MODE_OPWFMB_USED */

#ifdef EMIOS_PWM_IP_MODE_OPWFM_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitPeriodDutyCycleOpwfmMode
 * Description   : Initial Output Pulse Width and Frequency Modulation Mode - OPWFM Mode.
 * This Mode provides waveforms with variable duty cycle and frequency. The internal Channel counter
 * is automatically selected as the time Base when this Mode is selected.
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitPeriodDutyCycleOpwfmMode(uint8 Instance,
                                                      Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected Channel is set for OPWFM*/
    DevAssert((UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH));
    /* Check that Channel has internal counter for this Mode */
    DevAssert(TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWFM));
    /* Validate parametter */
    DevAssert(EMIOS_PWM_IP_MIN_CNT_VAL < UserChCfg->PeriodCount);
    DevAssert(UserChCfg->DutyCycle <= UserChCfg->PeriodCount);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    /* Configure OPWFM special parameters */
    /* Configure Counter Bus used by this Channel */
    Emios_Pwm_Ip_SetCounterBus(Base, UserChCfg->ChannelId, UserChCfg->Timebase);
    /* Configure DutyCycle in reg A */
    Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, UserChCfg->DutyCycle);
    /* Configure Period in reg B */
    Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, UserChCfg->PeriodCount);

    Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->PeriodCount;

    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {   /* 100% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
	    /* To avoid spike pulse
	    If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
	    after that, EDPOL bit is restored valid value */		
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );          
    }
    else if(0U == UserChCfg->DutyCycle)
    {
        /* 0% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
	    /* Configure output pin polarity */
	    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );
    }
    else
    {
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
        /* Configure output pin polarity */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
    }
    
    /* Transition from GPIO Mode to OPWFM Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, UserChCfg->ChannelId, UserChCfg->Mode);
    
    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {
        /* Configure output pin polarity */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );        
    }

    /* Stores the inital duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;
    Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH)? 1U : 0U;
}
#endif /* EMIOS_PWM_IP_MODE_OPWFM_USED */

#ifdef EMIOS_PWM_IP_MODE_OPWFMB_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwfmb
 * Description   : Set new duty cycle for the Channel in OPWFMB Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwfmb(uint8  Instance,
                                                                      uint8  Channel,
                                                                      Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;

    /* OPWFMB Mode */
    if ((NewDutyCycle > Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) && ((Emios_Pwm_Ip_PeriodType)0U != Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]))
    {   /* Duty cycle value should not be greater than the Channel Period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else if ((Emios_Pwm_Ip_PeriodType)0U == Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
        /* If new period is 0, set duty cycle to 0 */
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, (Emios_Pwm_Ip_PeriodType)0U);
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
    }
    else
    {
        if(NewDutyCycle == 0U)
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        else if (NewDutyCycle == Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        else
        {
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
        }

        Emios_Pwm_Ip_SetUCRegA(Base, Channel, NewDutyCycle);
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWFM_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwfm
 * Description   : Set new duty cycle for the Channel in OPWFM Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwfm(uint8  Instance,
                                                                     uint8  Channel,
                                                                     Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;

    /* OPWFM Mode */
    if ((NewDutyCycle > Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) && ((Emios_Pwm_Ip_PeriodType)0U != Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]))
    {   /* Duty cycle value should not be greater than the Channel Period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else if ((Emios_Pwm_Ip_PeriodType)0U == Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
        /* If new period is 0, set duty cycle to 0 */
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, (Emios_Pwm_Ip_PeriodType)0U);
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        /* Set polarity when channels is in active state */
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {        
            /* Reverse output pin polarity */
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );
        }
    }
    else
    {
        if(NewDutyCycle == 0U)
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
            /* Set polarity when channels is in active state */
            if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
            {
                /* Reverse output pin polarity */
                Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );
            }
        }
        else if (NewDutyCycle == Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
            /* Set polarity when channels is in active state */
            if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
            {            
                /* Reverse output pin polarity */
                Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );
            }
        }
        else
        {
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
            /* Set polarity when channels is in active state */
            if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
            {
                /* Configure output pin polarity */
                Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
            }
        }

        Emios_Pwm_Ip_SetUCRegA(Base, Channel, NewDutyCycle);
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif

#if ((defined EMIOS_PWM_IP_MODE_OPWMCB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED))
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitDeadTimeMode
 * Description   : Initial Center Aligned Output Pulse Width Modulation with Dead Time Insertion (Buffered Mode - OPWMCB, Nonbuffered Mode - OPWMC).
 * This operation Mode generates a center aligned PWM with dead time insertion to the leading or trailing edge.
 * Allow smooth output signal generation when changing duty cycle and deadtime values.
 *
 * The time Base selected for a Channel configured to OPWMCB or OPWMC Mode should be a Channel configured to MCB or MC Up/Down Mode.
 * It is recommended to start the Channel time Base after the OPWMCB or OPWMC Mode is entered
 * in order to avoid missing A matches at the very first duty cycle.
 *
 * The internal counter runs in the internal prescaler ratio, while the selected time Base
 * may be running in a different prescaler ratio.
 *
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitDeadTimeMode(uint8 Instance,
                                          Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected Channel is set for OPWMCB or OPWMC*/
    DevAssert((UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH));
    /* Check selected Channel supports OPWMCB or OPWMC Mode */
    DevAssert((TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWMCB)) ||
              (TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWMC)));
    /* Check selected counter bus is configured in MCB or MC Up-Down Mode */
    DevAssert((EMIOS_PWM_IP_MCB_UP_DOWN_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) ||
              (EMIOS_PWM_IP_MC_UP_DOWN_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)));
    /* Validate OPWMCB or OPWMC parametter */
    DevAssert(((2U * Emios_Pwm_Ip_GetCounterBusPeriod(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) - 2U) >= UserChCfg->DutyCycle);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_PeriodType DutyCycle = 0U;

    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {   /* 100% DutyCycle is desired. */
        if((UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG) ||
           (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH) ||
           (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG) ||
           (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH))
        {
            DutyCycle = 1U;
        }
        else 
        {
            /* Do nothing */
        }
        /* To avoid spike pulse
        If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
        after that, EDPOL bit is restored valid value */ 
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
    }
    else if((0U == UserChCfg->DutyCycle) || (1U == UserChCfg->DutyCycle))
    {
        /* 0% DutyCycle is desired. */
        DutyCycle = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, UserChCfg->ChannelId, UserChCfg->Timebase) + (uint8)1U;
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    }
    else
    {
        DutyCycle = (UserChCfg->DutyCycle) >> (uint8)1U;
        DutyCycle = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, UserChCfg->ChannelId, UserChCfg->Timebase) - DutyCycle;
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);        
    }

    /* Configure OPWMCB or OPWMC special parameters */
    /* Configure Counter Bus used by this Channel */
    Emios_Pwm_Ip_SetCounterBus(Base, UserChCfg->ChannelId, UserChCfg->Timebase);
    /* Configure DutyCycle in reg A */
    Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, DutyCycle);
    /* Configure DeadTime in reg B */
    Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, UserChCfg->DeadTime);
    /* Transition from GPIO Mode to OPWMCB or OPWMC Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, UserChCfg->ChannelId, UserChCfg->Mode);
    /* Configure output pin polarity */
    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);        
    /* Stores the inital duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;
    Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH)? 1U : 0U;      
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWMCB_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwmcb
 * Description   : Set new duty cycle for the Channel in OPWMCB Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwmcb(uint8  Instance,
                                                                      uint8  Channel,
                                                                      Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PeriodType ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));

    /* OPWMCB Mode */
    if(NewDutyCycle > ((ChPeriod * 2U) - 2U))
    { /* Duty cycle value should not be greater than the Channel Period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else if(0U == NewDutyCycle)
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

        Emios_Pwm_Ip_SetUCRegA(Base, Channel, ChPeriod + 1U);
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        /* This statement is required to avoid limitation of 0% duty cycle (if call 100% to 0%) */
        if(1U == Emios_Pwm_Ip_GetUCRegA(Base, Channel))
        {
            if((Emios_Pwm_Ip_aInitialModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG) ||
               (Emios_Pwm_Ip_aInitialModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH))
            {
                Emios_Pwm_Ip_SetForceMatchB(Base, Channel, TRUE);
            }
            else
            {
                Emios_Pwm_Ip_SetForceMatchA(Base, Channel, TRUE);
            }
        }
    }
    else if(NewDutyCycle == ((ChPeriod * 2U) - 2U))
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

        Emios_Pwm_Ip_SetUCRegA(Base, Channel, 1U);
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
    }
    else
    {
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, (Emios_Pwm_Ip_PeriodType)(ChPeriod - (NewDutyCycle >> 1U)));
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWMC_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwmc
 * Description   : Set new duty cycle for the Channel in OPWMC Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwmc(uint8  Instance,
                                                                     uint8  Channel,
                                                                     Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PeriodType ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));

    /* OPWMC Mode */
    if(NewDutyCycle > ((ChPeriod * 2U) - 2U))
    { /* Duty cycle value should not be greater than the Channel Period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else if(0U == NewDutyCycle)
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

        Emios_Pwm_Ip_SetUCRegA(Base, Channel, 0U);
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );         
        }
    }
    else if(NewDutyCycle == ((ChPeriod * 2U) - 2U))
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

        Emios_Pwm_Ip_SetUCRegA(Base, Channel, 0U);
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );         
        }
    }
    else
    {
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, (Emios_Pwm_Ip_PeriodType)(ChPeriod - (NewDutyCycle >> 1U)));
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == (uint16)1U) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );          
        }
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWM_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitEdgePlacementOpwmMode
 * Description   : Initial Output Pulse Width Modulation (OPWM).
 * OPWM Mode is used to generate pulses with programmable leading and trailing edge placement.
 * An external counter driven in MC Up Mode must be selected from one of the counter buses.
 * UserChCfg defines the first edge and the second edge. The output signal polarity is defined
 * by OutputPolarity in UserChCfg.
 *
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitEdgePlacementOpwmMode(uint8 Instance,
                                                   Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected Channel is set for OPWM */
    DevAssert((UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH));
    /* Check selected Channel supports OPWM */
    DevAssert(TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWM));
    /* Check selected counter bus is configured in MCB Up-Down Mode */
    DevAssert((EMIOS_PWM_IP_MC_UP_COUNTER_START == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) ||
              (EMIOS_PWM_IP_MC_UP_COUNTER_END == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)));
    /* Validate OPWM parametter */
    /* Phase Shift and DutyCycle cannot be bigger than the counter bus period */
    DevAssert((Emios_Pwm_Ip_GetCounterBusPeriod(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) >= (UserChCfg->PhaseShift + UserChCfg->DutyCycle));
    DevAssert(EMIOS_PWM_IP_MAX_CNT_VAL >= (uint32)((uint32)UserChCfg->PhaseShift + (uint32)UserChCfg->DutyCycle));
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->PhaseShift;

    /* Configure Counter Bus used by this Channel */
    Emios_Pwm_Ip_SetCounterBus(Base, UserChCfg->ChannelId, UserChCfg->Timebase);
    /* Configure Phase Shift in reg A */
    Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, UserChCfg->PhaseShift + (Emios_Pwm_Ip_PeriodType)1U);
    /* Configure Trailing edge in reg B */
    Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, UserChCfg->PhaseShift + UserChCfg->DutyCycle);

    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {   /* 100% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        /* Write the same nonzero value to AS1 and BS1 */
        Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, UserChCfg->PhaseShift + UserChCfg->DutyCycle);
        
        /* To avoid spike pulse
        If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
        after that, EDPOL bit is restored valid value */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );        
    }
    else if((0U == UserChCfg->DutyCycle) || (1U == UserChCfg->DutyCycle))
    {
        /* 0% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        /* Write 0 to AS1 */
        Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, (Emios_Pwm_Ip_PeriodType)0U);
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW );
    }
    else
    {
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
	    /* Configure output pin polarity */
	    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);		
    }
    
    /* Transition from GPIO Mode to OPWM Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, UserChCfg->ChannelId, UserChCfg->Mode);
    
    /* Configure output pin polarity */
    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    
    /* Stores the inital duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitEdgePlacementOpwmbMode
 * Description   : Initial Output Pulse Width Modulation Buffered (OPWMB).
 * OPWMB Mode is used to generate pulses with programmable leading and trailing edge placement.
 * An external counter driven in MCB Up Mode must be selected from one of the counter buses.
 * UserChCfg defines the first edge and the second edge. The output signal polarity is defined
 * by OutputPolarity in UserChCfg.
 *
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitEdgePlacementOpwmbMode(uint8 Instance,
                                                    Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected Channel is set for OPWMB */
    DevAssert((UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMB_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH));
    /* Check selected Channel supports OPWMB Mode */
    DevAssert(TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWMB));
    /* Check selected counter bus is configured in MCB Up-Down Mode */
    DevAssert(EMIOS_PWM_IP_MCB_UP_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase));
    /* Validate OPWMB parametter */
    /* Phase Shift and DutyCycle cannot be bigger than the counter bus period */
    DevAssert((Emios_Pwm_Ip_GetCounterBusPeriod(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) >= (UserChCfg->PhaseShift + UserChCfg->DutyCycle));
    DevAssert(EMIOS_PWM_IP_MAX_CNT_VAL >= (uint32)((uint32)UserChCfg->PhaseShift + (uint32)UserChCfg->DutyCycle));
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->PhaseShift;

    /* Configure Counter Bus used by this Channel */
    Emios_Pwm_Ip_SetCounterBus(Base, UserChCfg->ChannelId, UserChCfg->Timebase);
    /* Configure Phase Shift in reg A */
    Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, UserChCfg->PhaseShift);
    /* Configure Trailing edge in reg B */
    Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, UserChCfg->PhaseShift + UserChCfg->DutyCycle);

    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {   /* 100% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    }
    else if((0U == UserChCfg->DutyCycle) || (1U == UserChCfg->DutyCycle))
    {
        /* 0% DutyCycle is desired. */
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
        /* To avoid spike pulse
        If duty cycle = 0%, when enter Mode, EDPOL bit get complement of polarity
        after that, EDPOL bit is restored valid value */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
    }
    else
    {
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
    }
    /* Transition from GPIO Mode to OPWMB Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, UserChCfg->ChannelId, UserChCfg->Mode);
    /* Configure output pin polarity */
    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    /* Stores the inital duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwmb
 * Description   : Set new duty cycle for the Channel in OPWMB Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwmb(uint8  Instance,
                                                                     uint8  Channel,
                                                                     Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PeriodType ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));

    /* OPWMB Mode */
    if ((NewDutyCycle + Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) > ChPeriod)
    { /* New duty cycle puts trailing edge outside of counter bus period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else
    {
        if(NewDutyCycle == 0U)
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        else if (NewDutyCycle == ChPeriod)
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        else
        {
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
        }
        Emios_Pwm_Ip_SetUCRegB(Base, Channel, (NewDutyCycle + Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWM_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwm
 * Description   : Set new duty cycle for the Channel in OPWM Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwm(uint8  Instance,
                                                                    uint8  Channel,
                                                                    Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PeriodType ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));

    /* OPWM Mode */
    if ((NewDutyCycle + Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) > ChPeriod)
    { /* New duty cycle puts trailing edge outside of counter bus period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else
    {
        if(NewDutyCycle == 0U)
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
            Emios_Pwm_Ip_SetUCRegA(Base, Channel, (NewDutyCycle + Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));
        }
        else if (NewDutyCycle == ChPeriod)
        {
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
            Emios_Pwm_Ip_SetUCRegA(Base, Channel, (NewDutyCycle + Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));
        }
        else
        {
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
            Emios_Pwm_Ip_SetUCRegA(Base, Channel, (Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) + (Emios_Pwm_Ip_PeriodType)1U);
        }
        Emios_Pwm_Ip_SetUCRegB(Base, Channel, (NewDutyCycle + Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif

#ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitTriggerMode
 * Description   : Initial Output Pulse Width Modulation with Trigger (OPWMT) Mode
 * OPWMT Mode is intended to support the generation of Pulse Width Modulation signals where
 * the period is not modified while the signal is being output, but where the duty cycle will
 * be varied and must not create glitches. The Mode is intended to be used in conjunction with
 * other channels executing in the same Mode and sharing a common timebase. It will support each
 * Channel with a fixed PWM leading edge position with respect to the other channels and the
 * ability to generate a trigger signal at any point in the period that can be output from
 * the module to initiate activity in other parts of the SoC such as starting ADC conversions.
 *
 * An external counter driven in either MC Up or MCB Up Mode must be selected from one of the counter buses.
 *
 * The leading edge can be configured with any value within the range of the selected time Base. Note that registers
 * loaded with 0x0 will not produce matches if the timebase is driven by a Channel in MCB Mode.
 *
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitTriggerMode(uint8 Instance,
                                         Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected Channel is set for OPWMT */
    DevAssert(UserChCfg->Mode == EMIOS_PWM_IP_MODE_OPWMT);
    /* Check selected Channel supports OPWMT Mode */
    DevAssert(TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_OPWMT));
    /* Check selected counter bus is configured in MCB Up Mode or MC Up Mode */
    DevAssert((EMIOS_PWM_IP_MCB_UP_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) ||
              (EMIOS_PWM_IP_MC_UP_COUNTER_START == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)) ||
              (EMIOS_PWM_IP_MC_UP_COUNTER_END == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase)));
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_PeriodType CounterBusPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, UserChCfg->ChannelId, UserChCfg->Timebase);
    Emios_Pwm_Ip_DutyType TrailingEdge = 0x0000U;
    uint8 CounterStart = 0U;

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    /* Validate OPWMT parameters */
    /* Phase Shift must be in the counter bus period range. */
    DevAssert(CounterBusPeriod >= UserChCfg->PhaseShift);
    /* If 100% duty cycle must be implemented the maximum counter value for the time Base is 0xFFFE */
    DevAssert(EMIOS_PWM_IP_MAX_CNT_VAL > CounterBusPeriod);
    /* Duty cycle must not exceed the counter bus period. If 100% duty is desired dutycycle must be counterbus period +1U */
    DevAssert((CounterBusPeriod + 1U) >= UserChCfg->DutyCycle);
    /* Trigger point must be inside the counter bus period */
    DevAssert(CounterBusPeriod >= UserChCfg->TriggerPosition);
#endif

    if (EMIOS_PWM_IP_MCB_UP_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, UserChCfg->ChannelId, UserChCfg->Timebase))
    {
        CounterStart = 1U;
    }
    else
    {
        CounterStart = 0U;
    }

    if (CounterBusPeriod == UserChCfg->DutyCycle)
    {   /* 100% DutyCycle is desired. Trailing edge must be placed outside counter bus period. */
        TrailingEdge = UserChCfg->DutyCycle + 1U;
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
    }
    else if ((0U == UserChCfg->DutyCycle) || (0U == CounterBusPeriod))
    {
        TrailingEdge = UserChCfg->PhaseShift;
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
    }
    else
    { /* Calculate trailing edge postion. Wrap-around if DutyCycle extends the signal past the counterbus period. */
        TrailingEdge = (UserChCfg->PhaseShift + UserChCfg->DutyCycle) % CounterBusPeriod;
        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
    }

    Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->PhaseShift + CounterStart;

    /* Configure Counter Bus used by this Channel */
    Emios_Pwm_Ip_SetCounterBus(Base, UserChCfg->ChannelId, UserChCfg->Timebase);
    /* Configure Leading Edge in reg A */
    Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, (UserChCfg->PhaseShift + CounterStart));
    /* Configure Trailing Edge in reg B */
    Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, (TrailingEdge + CounterStart));
    /* Configure Triggerpoint in reg ALTA */
    Emios_Pwm_Ip_SetTrigger(Base, UserChCfg->ChannelId, (UserChCfg->TriggerPosition + CounterStart));
    /* To avoid spike pulse
    If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
    after that, EDPOL bit is restored valid value */
    if (CounterBusPeriod == UserChCfg->DutyCycle)
    {
         Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
    }
    else
    {
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    }
    /* Transition from GPIO Mode to OPWMT Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, UserChCfg->ChannelId, UserChCfg->Mode);
    /* Configure output pin polarity */
    Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    /* Stores the inital duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleOpwmt
 * Description   : Set new duty cycle for the Channel in OPWMT Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleOpwmt(uint8  Instance,
                                                                     uint8  Channel,
                                                                     Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PeriodType ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));

    /* OPWMT Mode */
    if (NewDutyCycle > ChPeriod)
    { /* Duty cycle value should not be greater than the Channel Period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else
    {
        if (ChPeriod == NewDutyCycle)
        {   /* 100% DutyCycle is desired. Trailing edge must be placed outside counter bus period. */
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

            Emios_Pwm_Ip_SetUCRegB(Base, Channel, (NewDutyCycle + 1U));
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        else if(0U == NewDutyCycle)
        {
            /* 0% DutyCycle is desired. */
            /* Disable and clear interrupt flag */
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

            Emios_Pwm_Ip_SetUCRegB(Base, Channel, Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        else
        { /* Calculate trailing edge postion. Wrap-around if DutyCycle extends the signal past the counterbus period. */
            Emios_Pwm_Ip_SetUCRegB(Base, Channel, (Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + NewDutyCycle) % ChPeriod);
            Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, (Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 0U)? FALSE : TRUE);
        }
    }

    /* Stores the new duty cycle in ticks */
    Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;

    return Ret;
}
#endif /* EMIOS_PWM_IP_MODE_OPWMT_USED */

#ifdef EMIOS_PWM_IP_MODE_DAOC_USED
static inline void Emios_Pwm_Ip_InitDCModeWithDuty(uint8 Instance,
                                               Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_PeriodType DaocRegA = 0U;
    Emios_Pwm_Ip_PeriodType CounterMax = Emios_Pwm_Ip_GetUCRegA(Base, Emios_Pwm_Ip_GetMasterBusChannel(Instance, UserChCfg->ChannelId));

    if(0U == UserChCfg->DutyCycle)
    {
        DaocRegA = 1U;
        Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = 0U;

        Emios_Pwm_Ip_SetForceMatchB(Base, UserChCfg->ChannelId, TRUE);
        /* Configure Leading Edge in reg A */
        Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, DaocRegA);
        /* Configure Trailing Edge in reg B */
        Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, (UserChCfg->DutyCycle + 1U));

        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);

        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;

    }
    else if(UserChCfg->DutyCycle == UserChCfg->PeriodCount)
    {
        DaocRegA = (Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] + Emios_Pwm_Ip_GetUCRegA(Base, UserChCfg->ChannelId)) % CounterMax;

        Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = 0U;

        Emios_Pwm_Ip_SetForceMatchA(Base, UserChCfg->ChannelId, TRUE);
        /* Configure Leading Edge in reg A */
        Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, (DaocRegA == 0U)? CounterMax : DaocRegA);
        /* Configure Trailing Edge in reg B */
        Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, (DaocRegA == 0U)? CounterMax : DaocRegA);
        /* Invert the EDGE POLARITY in control register */
        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);

        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
    }
    else
    {
        DaocRegA = 1U;
        Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->DutyCycle;

        /* Configure Leading Edge in reg A */
        Emios_Pwm_Ip_SetUCRegA(Base, UserChCfg->ChannelId, DaocRegA);
        /* Configure Trailing Edge in reg B */
        Emios_Pwm_Ip_SetUCRegB(Base, UserChCfg->ChannelId, (UserChCfg->DutyCycle + 1U));

        Emios_Pwm_Ip_SetEdgePolarity(Base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);

        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_InitDoubleCompareMode
 * Description   : Initial Double Action Output Compare (DAOC) Mode.
 * This mode provides waveforms with variable duty cycle and frequency.
 * In DAOC mode, at the end of period, the A register and B register need re-calculated to
 * enable next match A. This calculation and first pulse must be done by software.
 * Calculate the duty tick follow period and Duty cycle
 * Always enable interrupt. Because in this mode, the A register and B register is re-calculated
 * with period and duty at the end of period by software.
 *
 *END**************************************************************************/
static void Emios_Pwm_Ip_InitDoubleCompareMode(uint8 Instance,
                                               Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > UserChCfg->ChannelId);
    /* Check Selected channel is set for DAOC mode */
    DevAssert((UserChCfg->Mode == EMIOS_PWM_IP_MODE_DAOC_FLAG) ||
              (UserChCfg->Mode == EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH));
    /* Check selected Channel supports DAOC Mode */
    DevAssert(TRUE == Emios_Pwm_Ip_ValidateMode(Instance, UserChCfg->ChannelId, EMIOS_PWM_IP_HW_MODE_DAOC));
    /* Validate DAOC parametter */
    DevAssert(EMIOS_PWM_IP_MIN_CNT_VAL < UserChCfg->PeriodCount);
    DevAssert(UserChCfg->DutyCycle <= UserChCfg->PeriodCount);
#endif

    Emios_Pwm_Ip_HwAddrType *const base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->PeriodCount;
    Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH)? 1U : 0U;

    /* FLAG event enabled */
    Emios_Pwm_Ip_SetInterruptRequest(base, UserChCfg->ChannelId, TRUE);
    /* Configure Counter Bus used by this channel */
    Emios_Pwm_Ip_SetCounterBus(base, UserChCfg->ChannelId, UserChCfg->Timebase);

    if (UserChCfg->PeriodCount == UserChCfg->DutyCycle)
    {
        Emios_Pwm_Ip_SetEdgePolarity(base, UserChCfg->ChannelId,(UserChCfg->OutputPolarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
    }
    else
    {
        Emios_Pwm_Ip_SetEdgePolarity(base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    }
    /* Transition from GPIO mode to DAOC mode */
    Emios_Pwm_Ip_SetPwmMode(base, UserChCfg->ChannelId, UserChCfg->Mode);
    /* Configure output pin polarity */
    Emios_Pwm_Ip_SetEdgePolarity(base, UserChCfg->ChannelId, UserChCfg->OutputPolarity);
    /* With Duty cycle 0% */
    Emios_Pwm_Ip_InitDCModeWithDuty(Instance, UserChCfg);

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycleDaoc
 * Description   : Set new duty cycle for the Channel in DAOC Mode
 * This function will check the specific duty cycle and set new duty cycle for
 * this Channel
 *
 *END**************************************************************************/
static inline Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycleDaoc(uint8  Instance,
                                                                    uint8  Channel,
                                                                    Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PeriodType DaocRegA = 0U;
    Emios_Pwm_Ip_PeriodType CounterMax = Emios_Pwm_Ip_GetUCRegA(Base, Emios_Pwm_Ip_GetMasterBusChannel(Instance, Channel));

    /* DAOC Mode */
    if ((NewDutyCycle > Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) && ((Emios_Pwm_Ip_PeriodType)0U != Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]))
    {   /* Duty cycle value should not be greater than the Channel Period. */
        Ret = EMIOS_PWM_IP_STATUS_ERROR;
    }
    else if (((Emios_Pwm_Ip_PeriodType)0U == Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) || ((Emios_Pwm_Ip_DutyType)0U == NewDutyCycle))
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

        /* If new period is 0, set duty cycle to 0 */
        Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = 0U;

        Emios_Pwm_Ip_SetForceMatchB(Base, Channel, TRUE);
        /* Configure Leading Edge in reg A */
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, 1U);
        /* Configure Trailing Edge in reg B */
        Emios_Pwm_Ip_SetUCRegB(Base, Channel, (NewDutyCycle + 1U));
        /* Set polarity when channels is in active state */
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, (Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 1U)? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW);
        }

        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
    }
    else if(NewDutyCycle == Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
        /* Disable and clear interrupt flag */
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

        Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = 0U;
        DaocRegA = (Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + Emios_Pwm_Ip_GetUCRegA(Base, Channel)) % CounterMax;

        Emios_Pwm_Ip_SetForceMatchA(Base, Channel, TRUE);
        /* Configure Leading Edge in reg A */
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, (DaocRegA == 0U)? CounterMax : DaocRegA);
        /* Configure Trailing Edge in reg B */
        Emios_Pwm_Ip_SetUCRegB(Base, Channel, (DaocRegA == 0U)? CounterMax : DaocRegA);
        /* Set polarity when channels is in active state */
        /* Invert the EDGE POLARITY in control register */
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 1U)? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);
        }

        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
    }
    else
    {
        /* FLAG event enabled. The Daoc Mode requires interrupt to calculate the next match value*/
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, TRUE);

        Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewDutyCycle;
        /* Configure Leading Edge in reg A */
        Emios_Pwm_Ip_SetUCRegA(Base, Channel, 1U);
        /* Configure Trailing Edge in reg B */
        Emios_Pwm_Ip_SetUCRegB(Base, Channel, NewDutyCycle + 1U);
        /* Set polarity when channels is in active state */
        if (EMIOS_PWM_IP_MODE_GPO != Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, (Emios_Pwm_Ip_aPolarity[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == 1U)? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW);
        }

        Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;

    }

    return Ret;
}
#endif /* EMIOS_PWM_IP_MODE_DAOC_USED */

static inline void Emios_Pwm_Ip_InitOutputIrqAndMode(uint8                                   Instance,
                                                     Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    if (EMIOS_PWM_IP_OUTPUT_DISABLE_NONE != UserChCfg->OutputDisableSource)
    {
        Emios_Pwm_Ip_SetOutDisable(Base, UserChCfg->ChannelId, TRUE);
        Emios_Pwm_Ip_SetOutDisableSource(Base, UserChCfg->ChannelId, UserChCfg->OutputDisableSource);
    }

    /* Configure Interrupt/DMA request */
    if (EMIOS_PWM_IP_NOTIFICATION_DISABLED != UserChCfg->IrqMode)
    {
        if (EMIOS_PWM_IP_INTERRUPT_REQUEST == UserChCfg->IrqMode)
        {
            /* Register the notification structure */
            Emios_Pwm_Ip_aNotificationPtr[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = &(UserChCfg->UserCallback);
        }
        else
        {
            Emios_Pwm_Ip_SetDMARequest(Base, UserChCfg->ChannelId, TRUE);
        }
    }

    /* Configure CounterBus, DutyCycle, period, trigger, phase shift for selected Mode */
    switch (UserChCfg->Mode)
    {
        #ifdef EMIOS_PWM_IP_MODE_OPWFMB_USED
        case EMIOS_PWM_IP_MODE_OPWFMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH:
            /* OPWFMB Mode initialization */
            Emios_Pwm_Ip_InitPeriodDutyCycleOpwfmbMode(Instance, UserChCfg);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWFM_USED
        case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
            /* OPWFM Mode initialization */
            Emios_Pwm_Ip_InitPeriodDutyCycleOpwfmMode(Instance, UserChCfg);
            break;
        #endif
        #if ((defined EMIOS_PWM_IP_MODE_OPWMCB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED))
        #ifdef EMIOS_PWM_IP_MODE_OPWMCB_USED
        case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH:
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMC_USED
        case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH:
        #endif
            /* OPWMCB,OPWMC Mode initialization */
            Emios_Pwm_Ip_InitDeadTimeMode(Instance, UserChCfg);
            break;
        #endif /* defined EMIOS_PWM_IP_MODE_OPWMCB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED */
        #ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH:
            /* OPWMB Mode initialization */
            Emios_Pwm_Ip_InitEdgePlacementOpwmbMode(Instance, UserChCfg);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWM_USED
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
            /* OPWM Mode initialization */
            Emios_Pwm_Ip_InitEdgePlacementOpwmMode(Instance, UserChCfg);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
        case EMIOS_PWM_IP_MODE_OPWMT:
            /* OPWMT Mode initialization */
            Emios_Pwm_Ip_InitTriggerMode(Instance, UserChCfg);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_DAOC_USED
        case EMIOS_PWM_IP_MODE_DAOC_FLAG:
        case EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH:
            /* DAOC Mode initialization */
            Emios_Pwm_Ip_InitDoubleCompareMode(Instance, UserChCfg);
            break;
        #endif
        default:
            /* Nothing to do. All Pwm Mode are already treated. */
            break;
    }
}
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
 *
 * Function Name : Emios_Pwm_Ip_InitChannel
 * Description   : Initialize PWM Mode.
 * Select main Mode
 *     - EMIOS OPWFMB
 *       Initialize Output Pulse Width and Frequency Modulation Buffered (OPWFMB) Mode.
 *       This Mode provides waveforms with variable duty cycle and frequency. The internal Channel counter
 *       is automatically selected as the time Base when this Mode is selected.
 *
 *     - EMIOS OPWMB
 *       Initialize Output Pulse Width Modulation Buffered (OPWMB) Mode.
 *       OPWMB Mode is used to generate pulses with programmable leading and trailing edge placement.
 *       An external counter driven in MCB Up Mode must be selected from one of the counter buses.
 *       UserChCfg defines the first edge and the second edge. The output signal polarity is defined
 *       by OutputPolarity in UserChCfg.
 *
 *     - EMIOS OPWMCB
 *       Initialize Center Aligned Output Pulse Width Modulation with Dead Time Insertion Buffered (OPWMCB) Mode.
 *       This operation Mode generates a center aligned PWM with dead time insertion to the leading or trailing edge.
 *       Allow smooth output signal generation when changing duty cycle and deadtime values.
 *
 *     - EMIOS OPWMT
 *       Initialize Output Pulse Width Modulation with Trigger (OPWMT) Mode
 *       OPWMT Mode is intended to support the generation of Pulse Width Modulation signals where
 *       the period is not modified while the signal is being output, but where the duty cycle will
 *       be varied and must not create glitches. The Mode is intended to be used in conjunction with
 *       other channels executing in the same Mode and sharing a common timebase. It will support each
 *       Channel with a fixed PWM leading edge position with respect to the other channels and the
 *       ability to generate a trigger signal at any point in the period that can be output from
 *       the module to initiate activity in other parts of the SoC such as starting ADC conversions.
 * @implements Emios_Pwm_Ip_InitChannel_Activity
 **/
void Emios_Pwm_Ip_InitChannel(uint8 Instance,
                              Emios_Pwm_Ip_ChannelConfigType const *UserChCfg)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != UserChCfg);
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);

    /* Check that a valid notification structure is defined for interrupt Mode */
    if (EMIOS_PWM_IP_INTERRUPT_REQUEST == UserChCfg->IrqMode)
    {
        DevAssert(NULL_PTR != UserChCfg->UserCallback.CbFunction);
    }
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    /* Get timbase channel */
    uint8 TimbaseCh = Emios_Pwm_Ip_GetTimebaseChannel(UserChCfg->ChannelId, UserChCfg->Timebase);

    /* Disable Channel pre-scaler (reset default) */
    Emios_Pwm_Ip_aBasePtr[Instance]->CH.UC[UserChCfg->ChannelId].C = 0UL;

    /* Enable the Output Update for Channel */
    Emios_Pwm_Ip_SetOutputUpdate(Base, UserChCfg->ChannelId, TRUE);

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    /* Configure debug freeze enable */
    if ((FALSE == Emios_Pwm_Ip_GetDebugMode(Base)) &&
        (TRUE == UserChCfg->DebugMode))
    {
        DevAssert(FALSE);
    }
    else
    {
#endif
        Emios_Pwm_Ip_SetFreezeEnable(Base, UserChCfg->ChannelId, UserChCfg->DebugMode);

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    /* Configure output disable feature */
    /* Configure Interrupt/DMA request */
    /* Configure counterBus, dutyCycle, period, trigger, phase shift for selected mode */
    Emios_Pwm_Ip_InitOutputIrqAndMode(Instance, UserChCfg);

    /* Set the prescaler source */
    Emios_Pwm_Ip_SetPrescalerSource(Base, UserChCfg->ChannelId, UserChCfg->InternalPsSrc);

    /* Configure internal prescaler */
    Emios_Pwm_Ip_SetExtendedPrescaler(Base, UserChCfg->ChannelId, UserChCfg->InternalPs);
    Emios_Pwm_Ip_SetPrescalerEnable(Base, UserChCfg->ChannelId, TRUE);
    /* Stores the inital modes of Channel. */
    Emios_Pwm_Ip_aInitialModes[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->Mode;
    /* Stores the current modes of Channel. */
    Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = UserChCfg->Mode;
    /* Confirm the Channel is active*/
    Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][UserChCfg->ChannelId]] = (uint8)1U;
    /* If the counter buses to be used by the Unified Channel. */
    if (TimbaseCh < EMIOS_PWM_IP_CHANNEL_COUNT)
    {
        /* Confirm the timebase channel is active */
        /* Each channel that uses the master bus the Emios_Pwm_Ip_aCheckState variable will increment. */
        Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][TimbaseCh]] += (uint8)1U;
    }
    else
    {
        /* The internal counter to be used by the Unified Channel */
        (void)TimbaseCh;
    }
}

/**
 *
 * Function Name : Emios_Pwm_Ip_DeInitChannel
 * Description   : Reset eMIOS Channel to GPIO Mode (reset default)
 * @implements Emios_Pwm_Ip_DeInitChannel_Activity
 **/
void Emios_Pwm_Ip_DeInitChannel(uint8 Instance,
                                uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    /* Get Bus Select value */
    Emios_Pwm_Ip_CounterBusSourceType CounterBus = Emios_Pwm_Ip_GetCounterBus(Base, Channel);
    /* Get timbase channel */
    uint8 TimbaseCh = Emios_Pwm_Ip_GetTimebaseChannel(Channel, CounterBus);
    /* Clear control register 2 and stop clock for Channel */
    Base->CH.UC[Channel].C2 = 0UL;
#if (defined(PWM_AUTOSAR_MODE_IS_USED) && (STD_ON == PWM_AUTOSAR_MODE_IS_USED))
    /* Clear control register for Channel */
    /* If this channel is working on ASR mode, do not touch Polarity and Mode bits in control register to prevent spike */
    Base->CH.UC[Channel].C &= (eMIOS_C_MODE_MASK | eMIOS_C_EDPOL_MASK);
#else
    Base->CH.UC[Channel].C = 0UL;
    /* Clear An and Bn registers */
    Emios_Pwm_Ip_SetUCRegA(Base, Channel, 0U);
    Emios_Pwm_Ip_SetUCRegB(Base, Channel, 0U);
#endif
    /* Clear ALTAn if in PWM Trigger Mode */
#ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
    if (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMT)
    {
        Emios_Pwm_Ip_SetTrigger(Base, Channel, 0U);
    }
#endif
    Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;

    /* Confirm the Channel is inactive*/
    Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
    /* If the counter buses to be used by the Unified Channel. */
    if ((EMIOS_PWM_IP_BUS_INTERNAL != CounterBus) && (TimbaseCh < EMIOS_PWM_IP_CHANNEL_COUNT))
    {
        if((uint8)0U != Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][TimbaseCh]])
        {
            /* Confirm the timebase channel is inactive if Emios_Pwm_Ip_aCheckState is 0U*/
            /* Decrement Emios_Pwm_Ip_aCheckState variable for each channel that uses the master bus, make sure the master bus is not marked inactive when there are still active channels. */
            Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][TimbaseCh]] = Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][TimbaseCh]] - (uint8)1U;
        }
    }
    else
    {
        /* The internal counter to be used by the Unified Channel */
        (void)TimbaseCh;
    }
}

/**
 *
 * Function Name : Emios_Pwm_Ip_ForceMatchLeadingEdge
 * Description   : Force the output flip-flop to the level corresponding to a match on Leading edge
 *      In Center Aligned Output Pulse Width Modulation with Dead Time Insertion Buffered (OPWMCB) Mode
 *      FORCMA has different behaviors depending upon the selected dead time
 *      insertion Mode, lead or trail. In lead dead time insertion FORCMA force a transition
 *      in the output flipflop to the opposite of EDPOL. In trail dead time insertion the
 *      output flip-flop is forced to the value of EDPOL bit.
 *      FORCMA bit set does not set the internal time-Base to 0x1 as a regular A1 match.
 * @implements Emios_Pwm_Ip_ForceMatchLeadingEdge_Activity
 **/
void Emios_Pwm_Ip_ForceMatchLeadingEdge(uint8 Instance,
                                        uint8 Channel,
                                        boolean Enable)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_14();
    /* Force Match A bit */
    Emios_Pwm_Ip_SetForceMatchA(Base, Channel, Enable);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_14();
}

/**
 *
 * Function Name : Emios_Pwm_Ip_ForceMatchTrailingEdge
 * Description   : Force the output flipflop to the level corresponding to a match on Trailing edge
 *
 * In Center Aligned Output Pulse Width Modulation with Dead Time Insertion Buffered (OPWMCB) Mode
 *       If FORCMB bit is set, the output flip-flop value depends upon the selected dead time
 *       insertion Mode. In lead dead time insertion FORCMB forces the output flip-flop to transition to EDPOL
 *       bit value. In trail dead time insertion the output flip-flop is forced to the opposite of EDPOL bit value.
 * @implements Emios_Pwm_Ip_ForceMatchTrailingEdge_Activity
 **/
void Emios_Pwm_Ip_ForceMatchTrailingEdge(uint8 Instance,
                                         uint8 Channel,
                                         boolean Enable)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_15();
    /* Force Match B bit */
    Emios_Pwm_Ip_SetForceMatchB(Base, Channel, Enable);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_15();
}

/**
 *
 * Function Name : Emios_Pwm_Ip_GetPeriod
 * Description   : Get period of waveforms in PWM Mode.
 * @implements Emios_Pwm_Ip_GetPeriod_Activity
 **/
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetPeriod(uint8 Instance,
                              uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_PwmModeType ChMode = EMIOS_PWM_IP_MODE_NODEFINE;
    Emios_Pwm_Ip_PeriodType ChPeriod = 0x00U;
    /* Channels shall be reactivated from idle state. */
    if ((uint8)2U == Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
        ChMode = Emios_Pwm_Ip_aInitialModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];
    }
    else
    {
        ChMode =  Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];
    }

    switch (ChMode)
    {
#if ((defined EMIOS_PWM_IP_MODE_OPWFMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWFM_USED) || (defined EMIOS_PWM_IP_MODE_DAOC_USED))
        #ifdef EMIOS_PWM_IP_MODE_OPWFMB_USED
        case EMIOS_PWM_IP_MODE_OPWFMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH:
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWFM_USED
        case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
        #endif
        #ifdef EMIOS_PWM_IP_MODE_DAOC_USED
        case EMIOS_PWM_IP_MODE_DAOC_FLAG:
        case EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH:
        #endif
        /* Channel Mode is OPWFMB, OPWFM or DAOC Mode */
        ChPeriod = Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];

        /* Prevent compiler warning */
        (void)Base;
            break;
#endif
#if ((defined EMIOS_PWM_IP_MODE_OPWMCB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED))
        #ifdef EMIOS_PWM_IP_MODE_OPWMCB_USED
        case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH:
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMC_USED
        case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH:
        #endif
        /* Get the value AS1 in regA register in counter bus */
        ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));
        /* The counter period is: (2 x AS1) - 2. */
        ChPeriod = (ChPeriod << 1U) - 2U;
            break;
#endif
#if ((defined EMIOS_PWM_IP_MODE_OPWM_USED) || (defined EMIOS_PWM_IP_MODE_OPWMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMT_USED))
        #ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH:
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWM_USED
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
        case EMIOS_PWM_IP_MODE_OPWMT:
        #endif
        ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel));
            break;
#endif
        default:
        /* GPO or undefined Mode */
        ChPeriod = 0U;
        /* Prevent compiler warning */
        (void)Base;
            break;
    }

    return ChPeriod;
}

/**
 *
 * Function Name : Emios_Pwm_Ip_SetPeriod
 * Description   : Setup period of waveforms in OPWFMB Mode.
 * With PWM Mode, the OPWFMB(Output Pulse Width and Frequency Modulation Buffered) and the OPWFM(Output Pulse Width and Frequency Modulation) can set
 * period. All other PWM modes can not, because OPWFMB Mode using internal counter. All other
 * modes use external timebase and their period is timebase period.
 * @implements Emios_Pwm_Ip_SetPeriod_Activity
 **/
void Emios_Pwm_Ip_SetPeriod(uint8 Instance,
                            uint8 Channel,
                            Emios_Pwm_Ip_PeriodType NewPeriod)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check Channel Mode is OPWFMB, OPWFM, DAOC or GPO Mode */
    DevAssert(
#if ((defined EMIOS_PWM_IP_MODE_OPWFMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWFM_USED) || (defined EMIOS_PWM_IP_MODE_DAOC_USED))
              (EMIOS_PWM_IP_MODE_OPWFMB_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_DAOC_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
#endif
              (EMIOS_PWM_IP_MODE_GPO == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));

#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_16();
    /* If new period is 0, No change the period */
    if((Emios_Pwm_Ip_PeriodType)0U == NewPeriod)
    {
        /* Do Nothing */
    }
    else
    {
        /* Set new period */
        Emios_Pwm_Ip_SetUCRegB(Base, Channel, NewPeriod);
    }
    /* Store new period */
    Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = NewPeriod;
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_16();
}

/**
 *
 * Function Name : Emios_Pwm_Ip_GetDutyCycle
 * Description   : Get duty cycle of waveforms in PWM Mode. Duty cycle is signal active time in a period.
 * @implements Emios_Pwm_Ip_GetDutyCycle_Activity
 **/
Emios_Pwm_Ip_DutyType Emios_Pwm_Ip_GetDutyCycle(uint8 Instance,
                                 uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_DutyType DutyCycle = Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];

    return DutyCycle;
}

/**
 *
 * Function Name : Emios_Pwm_Ip_SetDutyCycle
 * Description   : Setup duty cycle of waveforms in OPWFMB, OPWFM Mode.
 * Duty cycle should be not greater period value. When set duty cycle value greater period value
 * (and do not over 24 bits counter register) 100% duty cycle signal generated.
 * @implements Emios_Pwm_Ip_SetDutyCycle_Activity
 **/
Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycle(uint8 Instance,
                                                  uint8 Channel,
                                                  Emios_Pwm_Ip_DutyType NewDutyCycle)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_PwmModeType ChMode = EMIOS_PWM_IP_MODE_NODEFINE;
    /* Channels shall be reactivated from idle state. */
    ChMode = ((uint8)2U == Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ? Emios_Pwm_Ip_aInitialModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] : Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_17();

    switch (ChMode)
    {
        #ifdef EMIOS_PWM_IP_MODE_OPWFMB_USED
        case EMIOS_PWM_IP_MODE_OPWFMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH:
            /* OPWFMB Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwfmb(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWFM_USED
        case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
            /* OPWFM Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwfm(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMCB_USED
        case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH:
            /* OPWMCB Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwmcb(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMC_USED
        case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH:
            /* OPWMC Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwmc(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH:
            /* OPWMB Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwmb(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWM_USED
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH:
            /* OPWM Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwm(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_DAOC_USED
        case EMIOS_PWM_IP_MODE_DAOC_FLAG:
        case EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH:
            /* DAOC Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleDaoc(Instance, Channel, NewDutyCycle);
            break;
        #endif
        #ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
        case EMIOS_PWM_IP_MODE_OPWMT:
            /* OPWMT Mode */
            Ret = Emios_Pwm_Ip_SetDutyCycleOpwmt(Instance, Channel, NewDutyCycle);
            break;
        #endif
        default:
            /* GPO or undefined Mode */
            Ret = EMIOS_PWM_IP_STATUS_WRONG_MODE;
            break;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_17();

    return Ret;
}

/**
 *
 * Function Name : Emios_Pwm_Ip_GetPhaseShift
 * Description   : Get Leading edge position of waveforms in OPWMB & OPWMT Mode.
 * @implements Emios_Pwm_Ip_GetPhaseShift_Activity
 **/
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetPhaseShift(uint8 Instance,
                                  uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#if ((defined EMIOS_PWM_IP_MODE_OPWM_USED) || (defined EMIOS_PWM_IP_MODE_OPWMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMT_USED))
    DevAssert((EMIOS_PWM_IP_MODE_OPWMB_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWMT == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));
#endif
#endif

    return Emios_Pwm_Ip_GetUCRegA(Base, Channel);
}

/**
 *
 * Function Name : Emios_Pwm_Ip_SetPhaseShift
 * Description   : Set Leading edge position of waveforms in OPWMB, OPWM & OPWMT Mode.
 * DutyCycle will be kept the same value.
 * @implements Emios_Pwm_Ip_SetPhaseShift_Activity
 **/
Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetPhaseShift(uint8 Instance,
                                                   uint8 Channel,
                                                   Emios_Pwm_Ip_DutyType PhaseShift)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_StatusType Status = EMIOS_PWM_IP_STATUS_SUCCESS;
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_CounterBusSourceType CounterBus = Emios_Pwm_Ip_GetCounterBus(Base, Channel);
    Emios_Pwm_Ip_PeriodType ChPeriod = 0U;
    Emios_Pwm_Ip_DutyType DutyCycle = 0U;
#ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
    uint8  CounterStart = 0U;
#endif

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#if ((defined EMIOS_PWM_IP_MODE_OPWM_USED) || (defined EMIOS_PWM_IP_MODE_OPWMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMT_USED))
    DevAssert((EMIOS_PWM_IP_MODE_OPWMB_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) ||
              (EMIOS_PWM_IP_MODE_OPWMT == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]));
#endif
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_18();
    ChPeriod = Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, CounterBus);
    DutyCycle = Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];
#if ((defined EMIOS_PWM_IP_MODE_OPWM_USED) || (defined EMIOS_PWM_IP_MODE_OPWMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMT_USED))
    /* Check that phase shift can be applied to the selected Channel */
    switch (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
#if ((defined EMIOS_PWM_IP_MODE_OPWM_USED) || (defined EMIOS_PWM_IP_MODE_OPWMB_USED))
#ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG:
        case EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH:
#endif
#ifdef EMIOS_PWM_IP_MODE_OPWM_USED
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG:
        case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
#endif
            Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = PhaseShift;
            if ((PhaseShift + DutyCycle) > ChPeriod)
            {
                Status = EMIOS_PWM_IP_STATUS_ERROR;
            }
            else
            {
                /* Set the new phase shift */
                Emios_Pwm_Ip_SetUCRegA(Base, Channel, Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]);
                /* Move trailing edge to keep the same duty cycle */
                Emios_Pwm_Ip_SetUCRegB(Base, Channel, (Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + DutyCycle));
            }
            break;
#endif
#ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
        case EMIOS_PWM_IP_MODE_OPWMT:
            CounterStart = (EMIOS_PWM_IP_MCB_UP_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, Channel, CounterBus)) ? 0x01U : 0x00U;
        
            Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = PhaseShift + CounterStart;
            if (PhaseShift > ChPeriod)
            {
                Status = EMIOS_PWM_IP_STATUS_ERROR;
            }
            else
            {
                /* Set the new phase shift */
                Emios_Pwm_Ip_SetUCRegA(Base, Channel, Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]);
                /* Move trailing edge to keep the same duty cycle */
                Emios_Pwm_Ip_SetUCRegB(Base, Channel, (Emios_Pwm_Ip_aRegA[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + DutyCycle));
            }
            break;
#endif
        default:
            Status = EMIOS_PWM_IP_STATUS_ERROR;
            break;
    }
#else
    /* Prevent CWE */
    (void)ChPeriod;
    (void)DutyCycle;
    (void)PhaseShift;
#endif
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_18();

    return Status;
}

/**
 *
 * Function Name : Emios_Pwm_Ip_GetDeadTime
 * Description   : Get Dead time value of waveforms in OPWMCB Mode.
 * @implements Emios_Pwm_Ip_GetDeadTime_Activity
 **/
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetDeadTime(uint8 Instance,
                                uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#ifdef EMIOS_PWM_IP_MODE_OPWMCB_USED
    DevAssert((Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH));
#endif
#endif
    /* Get the configured dead time */
    return Emios_Pwm_Ip_GetUCRegB(Base, Channel);
}

/**
 *
 * Function Name : Emios_Pwm_Ip_SetDeadTime
 * Description   : Set Dead time value of waveforms in OPWMCB Mode. New dead time should
 * be no greater than 0xFFFFFF (24 bits).
 * @implements Emios_Pwm_Ip_SetDeadTime_Activity
 **/
void Emios_Pwm_Ip_SetDeadTime(uint8 Instance,
                              uint8 Channel,
                              Emios_Pwm_Ip_PeriodType NewDeadTime)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#if ((defined EMIOS_PWM_IP_MODE_OPWMCB_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED))
    DevAssert((Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG) ||
              (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH));
#endif
#endif
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_19();
    /* Set the new dead time */
    Emios_Pwm_Ip_SetUCRegB(Base, Channel, NewDeadTime);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_19();
}

/**
 *
 * Function Name : Emios_Pwm_Ip_GetTriggerPlacement
 * Description   : Get Trigger placement value in OPWMT Mode
 * @implements Emios_Pwm_Ip_GetTriggerPlacement_Activity
 **/
uint32 Emios_Pwm_Ip_GetTriggerPlacement(uint8 Instance,
                                        uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
    DevAssert(Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMT);
#endif
#endif
    /* Get the configured trigger */
    return Emios_Pwm_Ip_GetTrigger(Base, Channel);
}

/**
 *
 * Function Name : Emios_Pwm_Ip_SetTriggerPlacement
 * Description   : Set Trigger placement value in OPWMT Mode. New trigger placement
 * should be no larger than 0xFFFFFF(24 bits).
 * @implements Emios_Pwm_Ip_SetTriggerPlacement_Activity
 **/
void Emios_Pwm_Ip_SetTriggerPlacement(uint8 Instance,
                                      uint8 Channel,
                                      Emios_Pwm_Ip_PeriodType NewTriggerPlacement)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    uint8 CounterStart = 0U;

#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
#ifdef EMIOS_PWM_IP_MODE_OPWMT_USED
    DevAssert(Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] == EMIOS_PWM_IP_MODE_OPWMT);
#endif
    /* Check selected counter bus is configured in MCB Up Mode or MC Up Mode */
    DevAssert((EMIOS_PWM_IP_MCB_UP_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel))) ||
              (EMIOS_PWM_IP_MC_UP_COUNTER_START == Emios_Pwm_Ip_GetCounterBusMode(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel))) ||
              (EMIOS_PWM_IP_MC_UP_COUNTER_END == Emios_Pwm_Ip_GetCounterBusMode(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel)))
             );
    DevAssert((Emios_Pwm_Ip_GetCounterBusPeriod(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel))) > NewTriggerPlacement);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_20();
    if (EMIOS_PWM_IP_MCB_UP_COUNTER == Emios_Pwm_Ip_GetCounterBusMode(Instance, Channel, Emios_Pwm_Ip_GetCounterBus(Base, Channel)))
    {
        CounterStart = 1U;
    }
    else
    {
        CounterStart = 0U;
    }
    /* Set the new trigger value */
    Emios_Pwm_Ip_SetTrigger(Base, Channel, (Emios_Pwm_Ip_PeriodType)(NewTriggerPlacement + CounterStart));
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_20();
}

/**
 *
 * Function Name : Emios_Pwm_Ip_ChannelEnterDebugMode
 * Description   : To set a Channel enters freeze state, should be setting
 * Emios_Pwm_Ip_AllowEnterDebugMode first.
 * @implements Emios_Pwm_Ip_ChannelEnterDebugMode_Activity
 **/
Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_ChannelEnterDebugMode(uint8 Instance,
                                                           uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_StatusType Ret = EMIOS_PWM_IP_STATUS_SUCCESS;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_21();
    if (Emios_Pwm_Ip_GetDebugMode(Base) == TRUE)
    {
        Emios_Pwm_Ip_SetFreezeEnable(Base, Channel, TRUE);
    }
    else
    {
        Ret = EMIOS_PWM_IP_STATUS_GLOBAL_FREEZE_DISABLED;
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_21();
    return Ret;
}

/**
 *
 * Function Name : Emios_Pwm_Ip_ChannelStopDebugMode
 * Description   : Release a Channel from freeze state
 * @implements Emios_Pwm_Ip_ChannelStopDebugMode_Activity
 **/
void Emios_Pwm_Ip_ChannelStopDebugMode(uint8 Instance,
                                       uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_22();
    Emios_Pwm_Ip_SetFreezeEnable(Base, Channel, FALSE);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_22();
}

/**
*
* Function Name : Emios_Pwm_Ip_GetFlagRequest
* Description   : Configure what the FLAG event should do. Generate Interrupt request,
*       Generate DMA request or do nothing.
* @implements Emios_Pwm_Ip_GetFlagRequest_Activity
**/
Emios_Pwm_Ip_InterruptType Emios_Pwm_Ip_GetFlagRequest(uint8 Instance,
                                                       uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_InterruptType EventType = EMIOS_PWM_IP_NOTIFICATION_DISABLED;

    if (Emios_Pwm_Ip_GetInterruptRequest(Base, Channel) == TRUE)
    {
        if (Emios_Pwm_Ip_GetDMARequest(Base, Channel) == TRUE)
        {
            EventType = EMIOS_PWM_IP_DMA_REQUEST;
        }
        else
        {
            EventType = EMIOS_PWM_IP_INTERRUPT_REQUEST;
        }
    }

    return EventType;
}

/**
*
* Function Name : Emios_Pwm_Ip_SetFlagRequest
* Description   : Configure what the FLAG event should do. Generate Interrupt request,
*       Generate DMA request or do nothing.
 * @implements Emios_Pwm_Ip_SetFlagRequest_Activity
**/
void Emios_Pwm_Ip_SetFlagRequest(uint8 Instance,
                                 uint8 Channel,
                                 Emios_Pwm_Ip_InterruptType Event)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_23();
    /* Clear Interrupt flag */
    Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);

    switch (Event)
    {
    case EMIOS_PWM_IP_INTERRUPT_REQUEST:
        if ((uint8)0U == Emios_Pwm_Ip_aNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
        {
            Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, TRUE);
            Emios_Pwm_Ip_SetDMARequest(Base, Channel, FALSE);
            Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        }
        break;
    case EMIOS_PWM_IP_DMA_REQUEST:
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, TRUE);
        Emios_Pwm_Ip_SetDMARequest(Base, Channel, TRUE);
        Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)1U;
        break;
    case EMIOS_PWM_IP_NOTIFICATION_DISABLED:
        Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_SetDMARequest(Base, Channel, FALSE);
        Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)0U;
        break;
    default:
        /* Nothig to do. All cases are treated.*/
        break;
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_23();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_GetOutputState
* Description   : Get the Unified Channel output pin logic level
*
* Implements    : Emios_Pwm_Ip_GetOutputState_Activity
*END**************************************************************************/
Emios_Pwm_Ip_OutputStateType Emios_Pwm_Ip_GetOutputState(uint8 Instance,
                                                         uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    return (Emios_Pwm_Ip_GetOutputPinState(Base, Channel) == FALSE)? EMIOS_PWM_IP_OUTPUT_STATE_LOW : EMIOS_PWM_IP_OUTPUT_STATE_HIGH;
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_SetOutputState
* Description   : Set the state of output pin
*
*
*END**************************************************************************/
void Emios_Pwm_Ip_SetOutputState(uint8 Instance,
                                 uint8 Channel,
                                 Emios_Pwm_Ip_OutputStateType OutputState)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_24();
    /* Set output pin polarity */
    if (EMIOS_PWM_IP_OUTPUT_STATE_LOW == OutputState)
    {
        Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, (Emios_Pwm_Ip_PolarityType)EMIOS_PWM_IP_ACTIVE_LOW);
    }
    else
    {
        Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, (Emios_Pwm_Ip_PolarityType)EMIOS_PWM_IP_ACTIVE_HIGH);
    }
    /* Enter GPIO output Mode */
    Emios_Pwm_Ip_SetPwmMode(Base, Channel, (Emios_Pwm_Ip_PwmModeType)EMIOS_PWM_IP_MODE_GPO);
    /* Stored the current Mode */
    Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (Emios_Pwm_Ip_PwmModeType)EMIOS_PWM_IP_MODE_GPO;
    /* Disable Channel interrupts */
    Emios_Pwm_Ip_SetInterruptRequest(Base, Channel, FALSE);
    /* Clear pending interrupt flag for the Channel */
    Emios_Pwm_Ip_ClearFlagEvent(Base, Channel);
    /* Confirm the Channel is idle state */
    Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = (uint8)2U;
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_24();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_SetOutputToNormal
* Description   : Set the polarity and Mode for current Channel as normal
*
*
*END**************************************************************************/
void Emios_Pwm_Ip_SetOutputToNormal(uint8 Instance,
                                    uint8 Channel,
                                    uint16 DutyPercent,
                                    Emios_Pwm_Ip_PolarityType Polarity,
                                    Emios_Pwm_Ip_PwmModeType  Mode)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_25();
    if (EMIOS_PWM_IP_MODE_GPO == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
#if ((defined EMIOS_PWM_IP_MODE_OPWFMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWFM_USED) || \
     (defined EMIOS_PWM_IP_MODE_OPWMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWM_USED) || \
     (defined EMIOS_PWM_IP_MODE_DAOC_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED))
        switch (Mode)
        {
#ifdef EMIOS_PWM_IP_MODE_OPWFMB_USED
            case EMIOS_PWM_IP_MODE_OPWFMB_FLAG:
            case EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH:
                Emios_Pwm_Ip_SetPwmMode(Base, Channel, Mode);
                Emios_Pwm_Ip_SetEdgePolarity(Base, Channel,(Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH );
                break;			
#endif
#ifdef EMIOS_PWM_IP_MODE_OPWFM_USED
            case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
				if(0x0U == DutyPercent)
				{
				   Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW);
				}
				else
				{				
				   Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);
				}
				Emios_Pwm_Ip_SetPwmMode(Base, Channel, Mode);
				if(0x8000U == DutyPercent)
				{
				   Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW);
				} 
                else
                {
                    /* Do nothing */
                }
                break;
#endif
#ifdef EMIOS_PWM_IP_MODE_OPWMB_USED
            case EMIOS_PWM_IP_MODE_OPWMB_FLAG:
            case EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH:
                Emios_Pwm_Ip_SetPwmMode(Base, Channel, Mode);
                Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, Polarity);
                break;                
#endif
#ifdef EMIOS_PWM_IP_MODE_OPWM_USED
            case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH:
                if (0x8000U == DutyPercent)
                {   
                    /* To avoid spike pulse
                    If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
                    after that, EDPOL bit is restored valid value */
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);        
                }
                else
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW);
                }
                Emios_Pwm_Ip_SetPwmMode(Base, Channel, Mode);
                if (0x8000U == DutyPercent)
                {
                    /* Configure output pin polarity */
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_HIGH : EMIOS_PWM_IP_ACTIVE_LOW);
                }  
                else
                {
                    /* Do nothing */    
                }
                Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, Polarity);
                break;            
#endif
#ifdef EMIOS_PWM_IP_MODE_DAOC_USED
            case EMIOS_PWM_IP_MODE_DAOC_FLAG:
            case EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH:
                if(0x8000U == DutyPercent)
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);
                }
                else
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, Polarity);
                }
                Emios_Pwm_Ip_SetPwmMode(Base, Channel, Mode);
                Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] = Mode;                
                break;
#endif
#ifdef EMIOS_PWM_IP_MODE_OPWMC_USED
            case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH:
            case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG:
            case EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH:          
                if (0x8000U == DutyPercent)
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);
                }
                else
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, Polarity);
                }
                Emios_Pwm_Ip_SetPwmMode(Base, Channel, Mode);
                break;
#endif                
            default:
                /* To avoid spike pulse
                If duty cycle = 100%, when enter Mode, EDPOL bit get complement of polarity
                after that, EDPOL bit is restored valid value */

#endif
                if(0x8000U == DutyPercent)
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, (Polarity == EMIOS_PWM_IP_ACTIVE_HIGH) ? EMIOS_PWM_IP_ACTIVE_LOW : EMIOS_PWM_IP_ACTIVE_HIGH);
                    Emios_Pwm_Ip_SetEdgePolarity(Base, Channel, Polarity);
                }
                else
                {
                    Emios_Pwm_Ip_SetPwmModePol(Base, Channel, Mode, Polarity);
                }
#if ((defined EMIOS_PWM_IP_MODE_OPWFMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWFM_USED) || \
     (defined EMIOS_PWM_IP_MODE_OPWMB_USED) || (defined EMIOS_PWM_IP_MODE_OPWM_USED) || \
     (defined EMIOS_PWM_IP_MODE_DAOC_USED) || (defined EMIOS_PWM_IP_MODE_OPWMC_USED))
                break;
        }
#endif
    }
    else
    {
        /*Do Nothing*/
        (void)Polarity;
        (void)Mode;
        (void)DutyPercent;
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_25();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_GetChannelMode
* Description   : Get Mode of operation of the Unified Channel
*
*END**************************************************************************/
Emios_Pwm_Ip_PwmModeType Emios_Pwm_Ip_GetChannelMode(uint8 Instance,
                                                     uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_PwmModeType ChannelMode = Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];

    return ChannelMode;
}

/**
 * @brief  Get master bus Channel
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @return    Emios_Pwm_Ip_PwmModeType
 */
uint8 Emios_Pwm_Ip_GetMasterBusChannel(uint8 Instance,
                                       uint8 Channel)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    const Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    uint8 ChannelMaster = Channel;

    Emios_Pwm_Ip_CounterBusSourceType CounterBus = Emios_Pwm_Ip_GetCounterBus(Base, Channel);

    switch (CounterBus)
    {
        case EMIOS_PWM_IP_BUS_A:
            ChannelMaster = 23U;
            break;
        case EMIOS_PWM_IP_BUS_F:
            ChannelMaster = 22U;
            break;
        case EMIOS_PWM_IP_BUS_BCDE:
            ChannelMaster = (uint8)((Channel >> 3U) * 8U);
            break;
        default:
            /* Internal bus is used */
            ChannelMaster = Channel;
            break;
    }
    return ChannelMaster;
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_SetPreEnableClock
* Description   : Set Prescaler Enable bit.
*
*END**************************************************************************/
void Emios_Pwm_Ip_SetPreEnableClock(uint8 Instance,
                                    uint8 Channel,
                                    boolean Value)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_26();
    /* Set Prescaler Enable bit. */
    Emios_Pwm_Ip_SetPrescalerEnable(Base, Channel, Value);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_26();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_SetBusSelected
* Description   : Set Bus Select bits.
*
*END**************************************************************************/
void Emios_Pwm_Ip_SetBusSelected(uint8 Instance,
                                 uint8 Channel,
                                 Emios_Pwm_Ip_CounterBusSourceType Value)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_27();
    /* Set Bus Select bits.*/
    Emios_Pwm_Ip_SetCounterBus(Base, Channel, Value);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_27();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_SetClockPs
* Description   : This function set the value of the prescaler on eMios channels
*
*END**************************************************************************/
void Emios_Pwm_Ip_SetClockPs(uint8 Instance,
                             uint8 Channel,
                             Emios_Pwm_Ip_InternalClkPsType Value)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_28();
    /* Stop eMios Channel - this will stop the internal counter */
    Emios_Pwm_Ip_SetPrescalerEnable(Base, Channel, FALSE);
    /*Set Extended Prescaler bits */
    Emios_Pwm_Ip_SetExtendedPrescaler(Base, Channel, Value);
    /* Re-start eMios Channel */
    Emios_Pwm_Ip_SetPrescalerEnable(Base, Channel, TRUE);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_28();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_ComparatorTransferEnable
* Description   : The function shall enable the output update for the corresponding Channel.
*
*END**************************************************************************/
void Emios_Pwm_Ip_ComparatorTransferEnable(uint8 Instance, uint32 ChannelMask)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_29();

    /* Enable the output update for the corresponding Channel.*/
    Emios_Mcl_Ip_ComparatorTransferEnable(Instance, ChannelMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_29();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_ComparatorTransferDisable
* Description   : The function shall disable the output update for the corresponding Channel.
*
*END**************************************************************************/
void Emios_Pwm_Ip_ComparatorTransferDisable(uint8 Instance, uint32 ChannelMask)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_30();

    /* Disable the output update for the corresponding Channel.*/
    Emios_Mcl_Ip_ComparatorTransferDisable(Instance, ChannelMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_30();
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_SyncUpdate
* Description   : This function updates the duty cycle and-or period for the specified PWM Channel.
*                 The value written does not take effect until calling SyncUpdate API.
*
*END**************************************************************************/
void Emios_Pwm_Ip_SyncUpdate(uint8 Instance)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
#endif
    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];

    /* Read OUDIS register */
    uint32 OudisRegVal = (uint32)Emios_Pwm_Ip_GetOutputUpdateInstance(Base);
    /* the mask of channels */
    uint32 ChannelMask = (uint32)0U;

    uint8  OudisDisable = 0U;
    uint8  ChannelId;
    /* Loop all channels available on each Emios Instance */
    for (ChannelId = 0U; ChannelId < EMIOS_PWM_IP_CHANNEL_COUNT; ChannelId++)
    {
        OudisDisable = (uint8)((OudisRegVal & (uint32)((uint32)1U << ChannelId)) >> ChannelId);

        if (((uint8)0U != Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][ChannelId]]) && ((uint8)1U == OudisDisable))
        {
#ifdef EMIOS_PWM_IP_MODE_OPWMCB_USED
            /* This statement is required to avoid limitation of 0% duty cycle (if call 100% to 0%) */
            if(1U == Emios_Pwm_Ip_GetUCRegA(Base, ChannelId))
            {
                if((Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][ChannelId]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG) ||
                   (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][ChannelId]] == EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH))
                {
                    /* Enable the output update for the corresponding Channel.*/
                    Emios_Mcl_Ip_ComparatorTransferEnable(Instance, (uint32)((uint32)1U << ChannelId));

                    Emios_Pwm_Ip_SetForceMatchB(Base, ChannelId, TRUE);
                }
                else if ((Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][ChannelId]] == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG) ||
                         (Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][ChannelId]] == EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH))
                {
                    /* Enable the output update for the corresponding Channel.*/
                    Emios_Mcl_Ip_ComparatorTransferEnable(Instance, (uint32)((uint32)1U << ChannelId));

                    Emios_Pwm_Ip_SetForceMatchA(Base, ChannelId, TRUE);
                }
                else
                {
                    /* Do Nothing */
                }
            }
#endif
            /* Update OUDIS register value for synchronization */
            ChannelMask |= (uint32)((uint32)1U << ChannelId);
        }
    }
    /* Write OUDIS register */
    Emios_Mcl_Ip_ComparatorTransferEnable(Instance, ChannelMask);
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_UpdateUCRegA
* Description   : This function updates the value of UCRegA. It may be used to 
*                 change duty cycle or phase shift with minimum overhead.
*
* @implements Emios_Pwm_Ip_UpdateUCRegA_Activity
*
*END**************************************************************************/
void Emios_Pwm_Ip_UpdateUCRegA(uint8 Instance, uint8 Channel, Emios_Pwm_Ip_PeriodType Value)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_SetUCRegA(Base, Channel, Value);
}

/*FUNCTION**********************************************************************
*
* Function Name : Emios_Pwm_Ip_UpdateUCRegB
* Description   : This function updates the value of UCRegB. It may be used to 
*                 change duty cycle, phase shift or inserted dead time buffer 
*                 with minimum overhead.
*
* @implements Emios_Pwm_Ip_UpdateUCRegB_Activity
*
*END**************************************************************************/
void Emios_Pwm_Ip_UpdateUCRegB(uint8 Instance, uint8 Channel, Emios_Pwm_Ip_PeriodType Value)
{
#if (EMIOS_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(EMIOS_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(EMIOS_PWM_IP_CHANNEL_COUNT > Channel);
#endif

    Emios_Pwm_Ip_HwAddrType *const Base = Emios_Pwm_Ip_aBasePtr[Instance];
    Emios_Pwm_Ip_SetUCRegB(Base, Channel, Value);
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#endif /* EMIOS_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
