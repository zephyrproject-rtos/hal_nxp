/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Power_Ip_Private.c
*   @version    3.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip.h"
#include "Power_Ip_Private.h"
#include "OsIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PRIVATE_VENDOR_ID_C                      43
#define POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_PRIVATE_SW_MAJOR_VERSION_C               3
#define POWER_IP_PRIVATE_SW_MINOR_VERSION_C               0
#define POWER_IP_PRIVATE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and OsIf header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Power_Ip_Private.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Power_Ip header file are of the same Autosar version */
#if (POWER_IP_PRIVATE_VENDOR_ID_C != POWER_IP_VENDOR_ID)
    #error "Power_Ip_Private.c and Power_Ip.h have different vendor ids"
#endif
/* Check if current file and Power_Ip header file are of the same Autosar version */
#if ((POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Private.c and Power_Ip.h are different"
#endif
/* Check if current file and Power_Ip header file are of the same Software version */
#if ((POWER_IP_PRIVATE_SW_MAJOR_VERSION_C != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_MINOR_VERSION_C != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_PATCH_VERSION_C != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_Private.c and Power_Ip.h are different"
#endif

/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if (POWER_IP_PRIVATE_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_Private.c and Power_Ip_Private.h have different vendor ids"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if ((POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Private.c and Power_Ip_Private.h are different"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Software version */
#if ((POWER_IP_PRIVATE_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_Private.c and Power_Ip_Private.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


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

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
void Power_Ip_ReportPowerErrors(Power_Ip_ReportErrorType Error, uint8 ErrorCode)
{
    Power_Ip_pfReportErrorsCallback(Error, ErrorCode);
}

void Power_Ip_ReportPowerErrorsEmptyCallback(Power_Ip_ReportErrorType Error, uint8 ErrorCode)
{
    /* No implementation */
    (void)Error;
    (void)ErrorCode;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Power_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void Power_Ip_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(POWER_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, POWER_IP_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Power_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean Power_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, POWER_IP_TIMEOUT_TYPE);

    if (*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }
    return RetVal;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

