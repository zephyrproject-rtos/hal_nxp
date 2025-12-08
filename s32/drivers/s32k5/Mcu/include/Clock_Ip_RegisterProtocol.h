/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_REGISTER_PROTOCOL_H
#define CLOCK_IP_REGISTER_PROTOCOL_H

/**
*   @file       Clock_Ip_Register_Protocol.h
   @version    0.8.0
*
*   @brief   CLOCK IP driver register protocol header file.
*   @details CLOCK IP driver register protocol header file.

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

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_REGISTER_PROTOCOL_VENDOR_ID                       43
#define CLOCK_IP_REGISTER_PROTOCOL_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_REGISTER_PROTOCOL_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_REGISTER_PROTOCOL_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_REGISTER_PROTOCOL_SW_MAJOR_VERSION                1
#define CLOCK_IP_REGISTER_PROTOCOL_SW_MINOR_VERSION                0
#define CLOCK_IP_REGISTER_PROTOCOL_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/




/*
    REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       // Register access: check a bitfield from register
    CLOCK_IP_SET_SELECTOR_001_RETURN,                                            // The first branch offset
    CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE,                                // The second branch offset
    REGISTER_ACCESS__NO_EVENT,                                                   // No event to be reported
    &Clock_Ip_apxCgm[Instance][SelectorIndex]->CSS,                              // Register address.
    SelectorMask,                                                                // Register mask.
    SelectorValue << SelectorShift,                                              // Register value.
    Config->Name,                                                                // Clock Name by which selector identified.
    CLOCK_IP_SELECTOR_TYPE,                                                      // Type of the resource.
    CLOCK_IP_SET_TYPE,                                                           // Operation type, service routine type.
    (Config - Clock_Ip_pxConfig->Selectors)/sizeof(Clock_Ip_SelectorConfigType), // Index of the configuration.
    CLOCK_IP_SetCgmXCscCssClkswRampupRampdownSwip_TYPE,                          // Name of the function/service routine where register is accessed.
    CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE,                                           // Command to be processed.
*/

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
);



void Clock_Ip_ResetCountOfConfiguredRegisters(void);

uint32 Clock_Ip_GetCountOfConfiguredRegisters(void);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef CLOCK_IP_REGISTER_PROTOCOL_H */

