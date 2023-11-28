/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_TYPES_H_
#define TRGMUX_IP_TYPES_H_

/**
*   @file    Trgmux_Ip_Types.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver header file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
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
#include "StandardTypes.h"
#include "Mcal.h"
#include "Trgmux_Ip_Cfg_Defines.h"
#include "Trgmux_Ip_Cfg_DeviceRegisters.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_TYPES_VENDOR_ID                    43
#define TRGMUX_IP_TYPES_MODULE_ID                    255
#define TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_TYPES_SW_MAJOR_VERSION             3
#define TRGMUX_IP_TYPES_SW_MINOR_VERSION             0
#define TRGMUX_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and StandardTypes.h are different"
#endif

/* Check if header file and Mcal header file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same vendor */
#if (TRGMUX_IP_TYPES_VENDOR_ID != TRGMUX_IP_CFG_DEFINES_VENDOR_ID)
    #error "Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Software version */
#if ((TRGMUX_IP_TYPES_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_DeviceRegisters.h file are of the same vendor */
#if (TRGMUX_IP_TYPES_VENDOR_ID != TRGMUX_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_DeviceRegisters.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg_DeviceRegisters.h file are of the same Autosar version */
#if ((TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_DeviceRegisters.h file are of the same Software version */
#if ((TRGMUX_IP_TYPES_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (TRGMUX_IP_TYPES_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Types.h and Trgmux_Ip_Cfg_DeviceRegisters.h are different"
#endif

#if (STD_ON == TRGMUX_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
typedef enum{
    TRGMUX_IP_STATUS_SUCCESS = 0U,
    TRGMUX_IP_STATUS_LOCKED  = 1U,
#if (STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE)
    TRGMUX_IP_STATUS_WRONG_CORE   = 2U,
#endif /* STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE */
}Trgmux_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct{
    uint8 LogicChannel;
    uint8 Output;
    uint8 Input;
    uint8 HwInstId;
    boolean Lock;
#if (STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE)
    uint8 CoreId;
#endif /* STD_ON == TRGMUX_IP_MULTICORE_IS_AVAILABLE */
}Trgmux_Ip_LogicTriggerType;

typedef struct{
    const Trgmux_Ip_LogicTriggerType * const paxLogicTrigger[TRGMUX_IP_NOF_CFG_LOGIC_TRIGGERS];
}Trgmux_Ip_InitType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* TRGMUX_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef TRGMUX_IP_TYPES_H_ */
