/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file       Emios_Pwm_Ip_Irq.c
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
#include "Emios_Pwm_Ip_Irq.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_IRQ_VENDOR_ID_C                      43
#define EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION_C               3
#define EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION_C               0
#define EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Emios_Pwm_Ip.h file are of the same vendor */
#if (EMIOS_PWM_IP_IRQ_VENDOR_ID_C != EMIOS_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip.h file are of the same Software version */
#if ((EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_SW_MAJOR_VERSION)  || \
     (EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_PWM_IP_SW_MINOR_VERSION)  || \
     (EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_HwAccess.h file are of the same vendor */
#if (EMIOS_PWM_IP_IRQ_VENDOR_ID_C != EMIOS_PWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_HwAccess.h file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_HwAccess.h file are of the same Software version */
#if ((EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
     (EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_PWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
     (EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_PWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_Irq.h file are of the same vendor */
#if (EMIOS_PWM_IP_IRQ_VENDOR_ID_C != EMIOS_PWM_IP_IRQ_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_Irq.h file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Emios_Pwm_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION)  || \
     (EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION)  || \
     (EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Irq.c and Emios_Pwm_Ip_Irq.h are different."
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (EMIOS_PWM_IP_USED == STD_ON)
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with base addresses for Emios instances available on platform */
extern Emios_Pwm_Ip_HwAddrType *const Emios_Pwm_Ip_aBasePtr[EMIOS_PWM_IP_INSTANCE_COUNT];

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with notification handlers for all configurable channels */
extern Emios_Pwm_Ip_NotificationType const *Emios_Pwm_Ip_aNotificationPtr[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

/* Array with current pwm modes for each Emios Channel */
extern Emios_Pwm_Ip_PwmModeType Emios_Pwm_Ip_aCurrentModes[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
#define PWM_START_SEC_VAR_CLEARED_32
#include "Pwm_MemMap.h"
#else
#define PWM_START_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"
#endif

/** @brief Array with period for all channels */
extern Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_aPeriod[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Array with duty cycle for all channels */
extern Emios_Pwm_Ip_DutyType Emios_Pwm_Ip_aDutyCycle[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
#define PWM_STOP_SEC_VAR_CLEARED_32
#include "Pwm_MemMap.h"
#else
#define PWM_STOP_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"
#endif

#define PWM_START_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

/* Arrays to store the channel logic Index State */
extern uint8 eMios_Pwm_Ip_IndexInChState[EMIOS_PWM_IP_INSTANCE_COUNT][EMIOS_PWM_IP_CHANNEL_COUNT];

/** @brief Arrays to check the state of Channel is initial state or uninitialized state or idle state */
extern uint8 Emios_Pwm_Ip_aCheckState[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

/** @brief Arrays to check the state of Channel in the notification or not */
extern uint8 Emios_Pwm_Ip_aCheckEnableNotif[EMIOS_PWM_IP_NUM_OF_CHANNELS_USED];

#define PWM_STOP_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
#ifdef EMIOS_PWM_IP_MODE_DAOC_USED
static void Emios_Pwm_Ip_IrqDaocHandler(uint8 Instance, uint8 Channel)
{
    Emios_Pwm_Ip_DutyType DaocDuty = 0U;
    Emios_Pwm_Ip_DutyType DaocRegA = 0U;
    Emios_Pwm_Ip_PeriodType DaocRegB = 0U;
    Emios_Pwm_Ip_DutyType CounterMax = Emios_Pwm_Ip_GetUCRegA(Emios_Pwm_Ip_aBasePtr[Instance], Emios_Pwm_Ip_GetMasterBusChannel(Instance, Channel));

    Emios_Pwm_Ip_PolarityType Polarity = Emios_Pwm_Ip_GetEdgePolarity(Emios_Pwm_Ip_aBasePtr[Instance], Channel);
    boolean OutputPin = Emios_Pwm_Ip_GetOutputPinState(Emios_Pwm_Ip_aBasePtr[Instance], Channel);

    if (EMIOS_PWM_IP_MODE_DAOC_FLAG == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
        DaocDuty = Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] - Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]];
        DaocRegA = ((DaocDuty + Emios_Pwm_Ip_GetUCRegB(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) % CounterMax);

        Emios_Pwm_Ip_SetUCRegA(Emios_Pwm_Ip_aBasePtr[Instance], Channel, (DaocRegA == 0U)? CounterMax : DaocRegA);

        DaocRegB = (Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + Emios_Pwm_Ip_GetUCRegB(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) % CounterMax;
        Emios_Pwm_Ip_SetUCRegB(Emios_Pwm_Ip_aBasePtr[Instance], Channel, (DaocRegB == 0U)? CounterMax : DaocRegB);

    }
    else if (EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH == Emios_Pwm_Ip_aCurrentModes[eMios_Pwm_Ip_IndexInChState[Instance][Channel]])
    {
        if (((EMIOS_PWM_IP_ACTIVE_HIGH == Polarity) && (FALSE == OutputPin)) ||
            ((EMIOS_PWM_IP_ACTIVE_LOW == Polarity) && (TRUE == OutputPin)))
        {
            DaocRegA = (Emios_Pwm_Ip_aPeriod[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + Emios_Pwm_Ip_GetUCRegA(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) % CounterMax;
            Emios_Pwm_Ip_SetUCRegA(Emios_Pwm_Ip_aBasePtr[Instance], Channel, (DaocRegA == 0U)? CounterMax : DaocRegA);      
        }
        else
        {
            DaocRegB = (Emios_Pwm_Ip_aDutyCycle[eMios_Pwm_Ip_IndexInChState[Instance][Channel]] + Emios_Pwm_Ip_GetUCRegA(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) % CounterMax;
            Emios_Pwm_Ip_SetUCRegB(Emios_Pwm_Ip_aBasePtr[Instance], Channel, (DaocRegB == 0U)? CounterMax : DaocRegB);
        }
    }
    else
    {
        /* Do nothing */
    }
    (void)DaocDuty;
    (void)DaocRegA;
    (void)DaocRegB;
    (void)Polarity;
    (void)OutputPin;
}
#endif
/**
* @brief          Interrupt handler for Emios Pwm channels.
* @details        Interrupt handler that clears the flags and calls the user notification function.
*
* @param[in]      Instance    Emios Instance id on which the interrupt occured.
* @param[in]      Channel     Channel id within the emios Instance that triggered the interrupt.
* @implements Emios_Pwm_Ip_IrqHandler_Activity
*/
void Emios_Pwm_Ip_IrqHandler(uint8 Instance, uint8 Channel)
{
    /* Check the state of Channel is uninitialized state */
    if ((0U == Emios_Pwm_Ip_aCheckState[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]) &&
        ((TRUE == Emios_Pwm_Ip_GetOverRunFlag(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) ||
        (TRUE == Emios_Pwm_Ip_GetOverFlagEvent(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) ||
        (TRUE == Emios_Pwm_Ip_GetOverFlowFlag(Emios_Pwm_Ip_aBasePtr[Instance], Channel))))
    {
        /* Clear Interrupt flag */
        Emios_Pwm_Ip_ClearFlagEvent(Emios_Pwm_Ip_aBasePtr[Instance], Channel);
    }
    else
    {
        /*Interrupt Flag and Interrupt Enable is set*/
        if ((TRUE == Emios_Pwm_Ip_GetInterruptRequest(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) &&
            ((TRUE == Emios_Pwm_Ip_GetOverRunFlag(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) ||
            (TRUE == Emios_Pwm_Ip_GetOverFlagEvent(Emios_Pwm_Ip_aBasePtr[Instance], Channel)) ||
            (TRUE == Emios_Pwm_Ip_GetOverFlowFlag(Emios_Pwm_Ip_aBasePtr[Instance], Channel))))
        {
#ifdef EMIOS_PWM_IP_MODE_DAOC_USED
            Emios_Pwm_Ip_IrqDaocHandler(Instance, Channel);
#endif
            /* Clear Interrupt flag */
            Emios_Pwm_Ip_ClearFlagEvent(Emios_Pwm_Ip_aBasePtr[Instance], Channel);

            if ((NULL_PTR != Emios_Pwm_Ip_aNotificationPtr[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]->CbFunction) &&
                (1U == Emios_Pwm_Ip_aCheckEnableNotif[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]))
            {
                /* Call the user notification callback with the provided parameter */
                (Emios_Pwm_Ip_aNotificationPtr[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]->CbFunction)(Emios_Pwm_Ip_aNotificationPtr[eMios_Pwm_Ip_IndexInChState[Instance][Channel]]->CbParameter);
            }
        }
    }
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* EMIOS_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
