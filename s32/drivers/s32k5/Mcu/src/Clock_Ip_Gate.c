/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Gate.c
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
#define CLOCK_IP_GATE_VENDOR_ID_C                      43
#define CLOCK_IP_GATE_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_GATE_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_GATE_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_GATE_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_GATE_SW_MINOR_VERSION_C               8
#define CLOCK_IP_GATE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Gate.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_GATE_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Gate.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Gate.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_GATE_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_GATE_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_GATE_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Gate.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Gate.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_GATE_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_GATE_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_GATE_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Gate.c and Clock_Ip_Private.h are different"
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

static Clock_Ip_NameType Clock_Ip_GateName = RESERVED_CLK;

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


static void Clock_Ip_CallbackGateEmptyName(Clock_Ip_NameType GateName);
static void Clock_Ip_CallbackGateEmpty1(void);
static void Clock_Ip_CallbackGateEmpty2(uint32);
static ClockLLD_StatusReturnType Clock_Ip_CallbackGateEmpty3(void);
static uint32 Clock_Ip_CallbackGateEmpty4(void);
#ifdef CLOCK_IP_GPR_X_PCTL_MODULE_PCTL_PCTL
static void Clock_Ip_ResetGprXPctlModulePctlPctl(void);
static void Clock_Ip_EnableGprXPctlModulePctlPctl(void);
static void Clock_Ip_DisableGprXPctlModulePctlPctl(void);
static void Clock_Ip_WaitGprXPctlModulePctlPctl(void);
static void Clock_Ip_SetStateGprXPctlModulePctlPctl(uint32 value);
static uint32 Clock_Ip_GetStateGprXPctlModulePctlPctl(void);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusGprXPctlModulePctlPctl(void);
static void Clock_Ip_Disable_Optimized_GprXPctlModulePctlPctl(void);
static void Clock_Ip_Wait_Optimized_GprXPctlModulePctlPctl(void);
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

static void Clock_Ip_CallbackGateEmptyName(Clock_Ip_NameType GateName)
{
    (void)GateName;
    /* No implementation */
}
static void Clock_Ip_CallbackGateEmpty1(void)
{
    /* No implementation */
}
static void Clock_Ip_CallbackGateEmpty2(uint32 value)
{
    /* No implementation */
    (void)value;
}
static ClockLLD_StatusReturnType Clock_Ip_CallbackGateEmpty3(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static uint32 Clock_Ip_CallbackGateEmpty4(void)
{
    /* No implementation */
    return 0U;
}

#ifdef CLOCK_IP_GPR_X_PCTL_MODULE_PCTL_PCTL
static void Clock_Ip_SetNameGprXPctlModulePctlPctl(Clock_Ip_NameType Name)
{
    Clock_Ip_GateName = Name;
}
static void Clock_Ip_ResetGprXPctlModulePctlPctl(void)
{
    /* No implementation */
}
static void Clock_Ip_EnableGprXPctlModulePctlPctl(void)
{
    /* No implementation */
}
static void Clock_Ip_DisableGprXPctlModulePctlPctl(void)
{
    /* No implementation */
}
static void Clock_Ip_WaitGprXPctlModulePctlPctl(void)
{
    /* No implementation */
}
static void Clock_Ip_SetStateGprXPctlModulePctlPctl(uint32 value)
{
    /* No implementation */
    (void)value;
}
static uint32 Clock_Ip_GetStateGprXPctlModulePctlPctl(void)
{
    /* No implementation */
    return 0U;
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusGprXPctlModulePctlPctl(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static void Clock_Ip_Enable_Optimized_GprXPctlModulePctlPctl(void)
{
    /* No implementation */
}
static void Clock_Ip_Disable_Optimized_GprXPctlModulePctlPctl(void)
{
    /* No implementation */
}
static void Clock_Ip_Wait_Optimized_GprXPctlModulePctlPctl(void)
{
    /* No implementation */
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

const Clock_Ip_GateCallbackType Clock_Ip_axGateCallbacks[CLOCK_IP_GATE_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackGateEmptyName,                     /* SetName */
        &Clock_Ip_CallbackGateEmpty1,                        /* Reset */
        &Clock_Ip_CallbackGateEmpty1,                        /* Enable */
        &Clock_Ip_CallbackGateEmpty1,                        /* Disable */
        &Clock_Ip_CallbackGateEmpty1,                        /* Wait */
        &Clock_Ip_CallbackGateEmpty2,                        /* SetState */
        &Clock_Ip_CallbackGateEmpty4,                        /* GetState */
        &Clock_Ip_CallbackGateEmpty3,                        /* GetStatus */
        &Clock_Ip_CallbackGateEmpty1,                        /* Enable_Optimized */
        &Clock_Ip_CallbackGateEmpty1,                        /* Disable_Optimized */
        &Clock_Ip_CallbackGateEmpty1,                        /* Wait_Optimized */
    },
#ifdef CLOCK_IP_GPR_X_PCTL_MODULE_PCTL_PCTL
    {
        &Clock_Ip_SetNameGprXPctlModulePctlPctl,                            /* SetName */
        &Clock_Ip_ResetGprXPctlModulePctlPctl,                              /* Reset */
        &Clock_Ip_EnableGprXPctlModulePctlPctl,                             /* Enable */
        &Clock_Ip_DisableGprXPctlModulePctlPctl,                            /* Disable */
        &Clock_Ip_WaitGprXPctlModulePctlPctl,                               /* Wait */
        &Clock_Ip_SetStateGprXPctlModulePctlPctl,                           /* SetState */
        &Clock_Ip_GetStateGprXPctlModulePctlPctl,                           /* GetState */
        &Clock_Ip_GetStatusGprXPctlModulePctlPctl,                          /* GetStatus */
        &Clock_Ip_Enable_Optimized_GprXPctlModulePctlPctl,                  /* Enable_Optimized */
        &Clock_Ip_Disable_Optimized_GprXPctlModulePctlPctl,                 /* Disable_Optimized */
        &Clock_Ip_Wait_Optimized_GprXPctlModulePctlPctl,                    /* Wait_Optimized */
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

