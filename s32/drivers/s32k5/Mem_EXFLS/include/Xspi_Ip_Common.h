/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_COMMON_H
#define XSPI_IP_COMMON_H

/**
*   @file Xspi_Ip_Common.h
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip_Common.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "Xspi_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_COMMON_VENDOR_ID_H                       43
#define XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H        4
#define XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H        9
#define XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H     0
#define XSPI_IP_COMMON_SW_MAJOR_VERSION_H                0
#define XSPI_IP_COMMON_SW_MINOR_VERSION_H                8
#define XSPI_IP_COMMON_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Types.h header file are of the same vendor */
#if (XSPI_IP_COMMON_VENDOR_ID_H != XSPI_IP_TYPES_VENDOR_ID)
    #error "Xspi_Ip_Common.h and Xspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Autosar version */
#if ((XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Common.h and Xspi_Ip_Types.h are different"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Software version */
#if ((XSPI_IP_COMMON_SW_MAJOR_VERSION_H != XSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_COMMON_SW_MINOR_VERSION_H != XSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_COMMON_SW_PATCH_VERSION_H != XSPI_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_Common.h and Xspi_Ip_Types.h are different"
#endif

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/


/*******************************************************************************
* Definitions
******************************************************************************/


/*! @brief xspi host interface structure
 */
#if defined(DERIVATIVE_S32N55) || defined(DERIVATIVE_S32N79)
typedef XSPI_REG(Type) XSPI_Type;
#endif

/*! @brief xspi command execution states
 */
typedef enum
{
    XSPI_COMMAND_IDLE                         = 0x00U,   /*!< No command ongoing                                           */
    XSPI_COMMAND_LOCKING_ARBITRATION          = 0x01U,   /*!< Arbitration lock requested, waiting for arbitration grant    */
    XSPI_COMMAND_WAIT_EXT_DEVICE_BUSY         = 0x02U,   /*!< Command sent, waiting command completion in external device  */
} Xspi_Ip_CommandStateType;


/*!
* @brief Last command that was executed by the device flash
*/
typedef enum
{
    XSPI_IP_LAST_COMMAND_NONE                = 0U,  /* No command in progress                              */
    XSPI_IP_LAST_COMMAND_READ                = 1U,  /* Read command                                        */
    XSPI_IP_LAST_COMMAND_WRITE               = 2U,  /* Write command                                       */
    XSPI_IP_LAST_COMMAND_ERASE               = 3U,  /* Erase command                                       */
    XSPI_IP_LAST_COMMAND_BLANK_CHECK         = 4U,  /* Blank check command                                 */
    XSPI_IP_LAST_COMMAND_PROGRAM_VERIFY      = 5U,  /* Program verify command                              */
    XSPI_IP_LAST_COMMAND_ERASE_SUSPEND       = 6U,  /* Erase suspend command                               */
    XSPI_IP_LAST_COMMAND_ERASE_RESUME        = 7U,  /* Erase resume command                                */
    XSPI_IP_LAST_COMMAND_PROGRAM_SUSPEND     = 8U,  /* Write suspend command                               */
    XSPI_IP_LAST_COMMAND_PROGRAM_RESUME      = 9U,  /* Write resume command                                */
} Xspi_Ip_LastCommandType;


/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the external flash driver
 * at initialization time.
 */
typedef struct
{
    const Xspi_Ip_MemoryConfigType *configuration;      /*!< Serial flash device configuration                */
    const Xspi_Ip_MemoryConnectionType *connection;     /*!< Connection to an XSPI device                     */
    uint32 baseAddress;                                 /*!< Base address of serial flash device              */
    Xspi_Ip_LastCommandType lastCommand;                /*!< Last command sent to the flash device            */
    Xspi_Ip_LastCommandType lastSuspendCommand;         /*!< Last command suspend sent to the flash device    */
    uint32 lastAddress;                                 /*!< Address of the last command                      */
    uint8 * lastRData;                                  /*!< Read data of the last command, if applicable     */
    const uint8 * lastWData;                            /*!< Write data of the last command, if applicable    */
    uint32 lastSize;                                    /*!< Size of the last command                         */
    Xspi_Ip_CommandStateType cmdState;                  /*!< Execution state o the current commend            */
    uint32 srValue;                                     /*!< SR value for asynchronous get SR commands        */
} Xspi_Ip_StateType;


/*******************************************************************************
 * External variable declarations.
 ******************************************************************************/

 /* Physical LUT seq to use for all flash commands */
#define XSPI_IP_COMMAND_LUT 1U

#define MEM_43_EXFLS_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Table of AHB addresses for XSPI instances. */
extern const uint32 Xspi_Ip_AhbAddress[XSPI_REG(INSTANCE_COUNT)];

#define MEM_43_EXFLS_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to runtime state structures */
extern Xspi_Ip_StateType Xspi_Ip_MemoryStateStructure[];

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/*******************************************************************************
 * API
 ******************************************************************************/

#endif /* XSPI_IP_MEM_INSTANCE_COUNT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_COMMON_H */
