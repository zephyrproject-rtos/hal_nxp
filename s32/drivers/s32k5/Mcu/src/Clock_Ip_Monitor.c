/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Monitor.c
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
#include "SchM_Mcu.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_MONITOR_VENDOR_ID_C                      43
#define CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_MONITOR_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_MONITOR_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_MONITOR_SW_MINOR_VERSION_C               8
#define CLOCK_IP_MONITOR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_MONITOR_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Monitor.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Monitor.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_MONITOR_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_MONITOR_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Monitor.c and Clock_Ip_Private.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Monitor.c file and SchM_Mcu.h file are of the same Autosar version */
#if ((CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C != SCHM_MCU_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C != SCHM_MCU_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Monitor.c and SchM_Mcu.h are different"
#endif
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

static Clock_Ip_NameType Clock_Ip_CmuName = RESERVED_CLK;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS
/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"



/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"
#endif

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


static void Clock_Ip_CallbackCmuEmptyName(Clock_Ip_NameType PllName);
static void Clock_Ip_CallbackCmuEmpty1(void);
static void Clock_Ip_CallbackCmuEmpty2(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency);
static ClockLLD_StatusReturnType Clock_Ip_CallbackCmuEmpty3(void);


#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS
static void Clock_Ip_SetNameCmuFcFceRefCntLfrefHfrefRs(Clock_Ip_NameType CmuName);
static void Clock_Ip_ResetCmuFcFceRefCntLfrefHfrefRs(void);
static void Clock_Ip_SetCmuFcFceRefCntLfrefHfrefRs(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency);
static void Clock_Ip_EnableCmuFcFceRefCntLfrefHfrefRs(void);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfrefRs(void);
static void Clock_Ip_Set_Optimized_CmuFcFceRefCntLfrefHfrefRs(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency);
static void Clock_Ip_Enable_Optimized_CmuFcFceRefCntLfrefHfrefRs(void);
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

static void Clock_Ip_CallbackCmuEmptyName(Clock_Ip_NameType CmuName)
{
    (void)CmuName;
    /* No implementation */
}
static void Clock_Ip_CallbackCmuEmpty1(void)
{
    /* No implementation */
}
static void Clock_Ip_CallbackCmuEmpty2(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency)
{
    /* No implementation */
    (void)EventReaction;
    (void)Deviation;
    (void)Latency;
    (void)MonitoredClockFrequency;
}
static ClockLLD_StatusReturnType Clock_Ip_CallbackCmuEmpty3(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}


#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS
static void Clock_Ip_SetNameCmuFcFceRefCntLfrefHfrefRs(Clock_Ip_NameType CmuName)
{
    Clock_Ip_CmuName = CmuName;
    /* No implementation */
}
static void Clock_Ip_ResetCmuFcFceRefCntLfrefHfrefRs(void)
{
    /* No implementation */
}
static void Clock_Ip_SetCmuFcFceRefCntLfrefHfrefRs(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency)
{
    (void)EventReaction;
    (void)Deviation;
    (void)Latency;
    (void)MonitoredClockFrequency;
}
static void Clock_Ip_EnableCmuFcFceRefCntLfrefHfrefRs()
{
    /* No implementation */
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfrefRs(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static void Clock_Ip_Set_Optimized_CmuFcFceRefCntLfrefHfrefRs(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency)
{
    (void)EventReaction;
    (void)Deviation;
    (void)Latency;
    (void)MonitoredClockFrequency;
}
static void Clock_Ip_Enable_Optimized_CmuFcFceRefCntLfrefHfrefRs()
{
    /* No implementation */
}
#endif


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS
#ifdef CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE
#if CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE > 0U
/**
* @brief        This function clear the CMU interrupt flag from CMU module.
* @details      Called by RGM ISR routine when a user notification for CMU FCCU events is configured
*
* @return       void
*
* @implements Clock_Ip_CMU_ClockFailInt_Activity
*
*/
void Clock_Ip_CMU_ClockFailInt(void)
{
    uint32 CmuIerValue;
    uint32 CmuIsrValue = 0U;
    uint32 IndexCmu;

    for (IndexCmu = 0U; IndexCmu < CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE; IndexCmu++)
    {
        if (NULL_PTR != Clock_Ip_apxCmu[IndexCmu])
		{
			/* Read flags */
            CmuIsrValue = Clock_Ip_apxCmu[IndexCmu]->SR & CLOCK_IP_CMU_ISR_MASK;

            /* Check whether driver is initialized */
            if (NULL_PTR != Clock_Ip_pxConfig)
            {
                /* Read interrupt enable */
                CmuIerValue = Clock_Ip_apxCmu[IndexCmu]->IER & CLOCK_IP_CMU_ISR_MASK;
                /* Filter all interrupts that are not enabled from cmuIsrValue */
                CmuIsrValue = CmuIsrValue & CmuIerValue;

                /* If at least one interrupt has been triggered */
                if (CmuIsrValue != 0U)
                {
                    /* Clear status flag */
                    Clock_Ip_apxCmu[IndexCmu]->SR = CmuIsrValue;
#ifdef CLOCK_IP_CMU_FCCU_NOTIFICATION
                    CLOCK_IP_CMU_FCCU_NOTIFICATION(Clock_Ip_aeCmuNames[IndexCmu]);
#else
                    Clock_Ip_ReportClockErrors(CLOCK_IP_CMU_ERROR, Clock_Ip_aeCmuNames[IndexCmu]);
#endif
                }
            }
            else
            {
                /* Clear status flag */
                Clock_Ip_apxCmu[IndexCmu]->SR = CmuIsrValue;
            }
        }
    }
}
#endif
#endif
#endif
/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_ClockMonitorCallbackType Clock_Ip_axCmuCallbacks[CLOCK_IP_CMU_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackCmuEmptyName,                     /* SetName */
        &Clock_Ip_CallbackCmuEmpty1,                        /* Reset */
        &Clock_Ip_CallbackCmuEmpty1,                        /* Disable */
        &Clock_Ip_CallbackCmuEmpty2,                        /* Set */
        &Clock_Ip_CallbackCmuEmpty1,                        /* Enable */
        &Clock_Ip_CallbackCmuEmpty1,                        /* Start */
        &Clock_Ip_CallbackCmuEmpty3,                        /* GetStatus */
        &Clock_Ip_CallbackCmuEmpty2,                        /* Set_Optimized */
        &Clock_Ip_CallbackCmuEmpty1,                        /* Enable_Optimized */
    },
#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS
    {
        &Clock_Ip_SetNameCmuFcFceRefCntLfrefHfrefRs,                            /* SetName */
        &Clock_Ip_ResetCmuFcFceRefCntLfrefHfrefRs,                              /* Reset */
        &Clock_Ip_ResetCmuFcFceRefCntLfrefHfrefRs,                              /* Disable */
        &Clock_Ip_SetCmuFcFceRefCntLfrefHfrefRs,                                /* Set */
        &Clock_Ip_EnableCmuFcFceRefCntLfrefHfrefRs,                             /* Enable */
        &Clock_Ip_EnableCmuFcFceRefCntLfrefHfrefRs,                             /* Start */
        &Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfrefRs,                          /* GetStatus */
        &Clock_Ip_Set_Optimized_CmuFcFceRefCntLfrefHfrefRs,                     /* Set_Optimized */
        &Clock_Ip_Enable_Optimized_CmuFcFceRefCntLfrefHfrefRs,                  /* Enable_Optimized */
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

