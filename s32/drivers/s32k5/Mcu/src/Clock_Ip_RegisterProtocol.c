/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_RegisterProtocol.c
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
#define CLOCK_IP_REGISTERPROTOCOL_VENDOR_ID_C                      43
#define CLOCK_IP_REGISTERPROTOCOL_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_REGISTERPROTOCOL_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_REGISTERPROTOCOL_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_REGISTERPROTOCOL_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_REGISTERPROTOCOL_SW_MINOR_VERSION_C               8
#define CLOCK_IP_REGISTERPROTOCOL_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if CLOCK_IP_REGISTERPROTOCOL.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_REGISTERPROTOCOL_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "CLOCK_IP_REGISTERPROTOCOL.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if CLOCK_IP_REGISTERPROTOCOL.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_REGISTERPROTOCOL_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_REGISTERPROTOCOL_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_REGISTERPROTOCOL_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CLOCK_IP_REGISTERPROTOCOL.c and Clock_Ip_Private.h are different"
#endif

/* Check if CLOCK_IP_REGISTERPROTOCOL.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_REGISTERPROTOCOL_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_REGISTERPROTOCOL_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_REGISTERPROTOCOL_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CLOCK_IP_REGISTERPROTOCOL.c and Clock_Ip_Private.h are different"
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
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

static uint32 Clock_Ip_RegIndex;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

static boolean RegisterValidationFailed;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"


/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

static Clock_Ip_RegisterType Clock_Ip_ExpectedRegisterValue;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/



/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


void RegisterAccess
(
	Clock_Ip_RegisterAccessOperationType RegOperation,
	uint32 Offset1,
	uint32 Offset2,
    Clock_Ip_RegisterAccessEventType EventToBeReported,
    volatile uint32 *RegAddress,
	volatile const uint32 *RegAddressRo,
	uint32 RegMask,
	uint32 RegVal,
    Clock_Ip_NameType ClockName,
	Clock_Ip_ResourceType ResourceType,
	Clock_Ip_OperationRequestType OperationType,
	uint32 ConfigurationIndex,
	Clock_Ip_FunctionNameType FunctionName,
	Clock_Ip_HwStateType CmdToBeProcessed
)
{
	(void)RegOperation;
	(void)Offset1;
	(void)Offset2;
	(void)EventToBeReported;
	(void)RegAddress;
	(void)RegAddressRo;
	(void)RegMask;
	(void)RegVal;
	(void)ClockName;
	(void)ResourceType;
	(void)OperationType;
	(void)ConfigurationIndex;
	(void)FunctionName;
	(void)CmdToBeProcessed;

	if (((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].RegisterAccessOperation == RegOperation) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BranchOffset1 == Offset1) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BranchOffset2 == Offset2) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Event == EventToBeReported) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Address == RegAddress) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ConstAddress == RegAddressRo) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Mask == RegMask) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Value == RegVal) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ClockName == ClockName) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ResourceType == ResourceType) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].OperationType == OperationType) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BufferIndex == ConfigurationIndex) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].FunctionName == FunctionName) &&
		((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].State == CmdToBeProcessed) &&
        RegisterValidationFailed == FALSE)
	{
		Clock_Ip_RegIndex++;
	}
    else
    {
        Clock_Ip_ExpectedRegisterValue.RegisterAccessOperation    = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].RegisterAccessOperation;
        Clock_Ip_ExpectedRegisterValue.BranchOffset1              = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BranchOffset1;
        Clock_Ip_ExpectedRegisterValue.BranchOffset2              = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BranchOffset2;
        Clock_Ip_ExpectedRegisterValue.Event                      = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Event;
        Clock_Ip_ExpectedRegisterValue.Address                    = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Address;
        Clock_Ip_ExpectedRegisterValue.ConstAddress               = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ConstAddress;
        Clock_Ip_ExpectedRegisterValue.Mask                       = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Mask;
        Clock_Ip_ExpectedRegisterValue.Value                      = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Value;
        Clock_Ip_ExpectedRegisterValue.ClockName                  = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ClockName;
        Clock_Ip_ExpectedRegisterValue.ResourceType               = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ResourceType;
        Clock_Ip_ExpectedRegisterValue.OperationType              = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].OperationType;
        Clock_Ip_ExpectedRegisterValue.BufferIndex                = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BufferIndex;
        Clock_Ip_ExpectedRegisterValue.FunctionName               = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].FunctionName;
        Clock_Ip_ExpectedRegisterValue.State                      = (*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].State;

        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].RegisterAccessOperation == RegOperation));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BranchOffset1 == Offset1));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BranchOffset2 == Offset2));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Event == EventToBeReported));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Address == RegAddress));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ConstAddress == RegAddressRo));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Mask == RegMask));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].Value == RegVal));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ClockName == ClockName));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].ResourceType == ResourceType));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].OperationType == OperationType));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].BufferIndex == ConfigurationIndex));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].FunctionName == FunctionName));
        CLOCK_IP_DEV_ASSERT(((*Clock_Ip_pxConfig->Registers)[Clock_Ip_RegIndex].State == CmdToBeProcessed));

        Clock_Ip_RegIndex = 0U;
        RegisterValidationFailed = TRUE;
    }


}


void Clock_Ip_ResetCountOfConfiguredRegisters()
{
    Clock_Ip_RegIndex = 0U;
    RegisterValidationFailed = FALSE;
}

uint32 Clock_Ip_GetCountOfConfiguredRegisters()
{
    return Clock_Ip_RegIndex;
}



/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
