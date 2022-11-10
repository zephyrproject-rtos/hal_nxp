/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SWT_IP_TYPES_H
#define SWT_IP_TYPES_H

/**
*   @file
*
*   @addtogroup Swt
*   @{
*/

#if defined(__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Swt_Ip_Cfg_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_TYPES_VENDOR_ID                    43
#define SWT_IP_TYPES_MODULE_ID                    102
#define SWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SWT_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define SWT_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SWT_IP_TYPES_SW_MAJOR_VERSION             0
#define SWT_IP_TYPES_SW_MINOR_VERSION             9
#define SWT_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (SWT_IP_TYPES_VENDOR_ID != SWT_IP_CFG_DEFINES_VENDOR_ID)
#error "Swt_Ip_Types.h and Swt_Ip_Cfg_Defines.h have different vendor ids"
#endif

#if ((SWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_TYPES_AR_RELEASE_MINOR_VERSION    != SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_TYPES_AR_RELEASE_REVISION_VERSION != SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip_Types.h and Swt_Ip_Cfg_Defines.h are different"
#endif

#if ((SWT_IP_TYPES_SW_MAJOR_VERSION != SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (SWT_IP_TYPES_SW_MINOR_VERSION != SWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (SWT_IP_TYPES_SW_PATCH_VERSION != SWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip_Types.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define SWT_IP_ALL_MAP_DISABLE ((uint8) 0x00)
#define SWT_IP_MAP0_ENABLE     ((uint8) 0x80)
#define SWT_IP_MAP1_ENABLE     ((uint8) 0x40)
#define SWT_IP_MAP2_ENABLE     ((uint8) 0x20)
#define SWT_IP_MAP3_ENABLE     ((uint8) 0x10)
#define SWT_IP_MAP4_ENABLE     ((uint8) 0x08)
#define SWT_IP_MAP5_ENABLE     ((uint8) 0x04)
#define SWT_IP_MAP6_ENABLE     ((uint8) 0x02)
#define SWT_IP_MAP7_ENABLE     ((uint8) 0x01)
#define SWT_IP_ALL_MAP_ENABLE  ((uint8) 0xFF)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/** @brief       Enum defining the possible type values for SWT API
* @implements    Swt_Ip_StatusType_enumeration
*/
typedef enum
{
    SWT_IP_STATUS_SUCCESS   = 0x00,
    SWT_IP_STATUS_ERROR     = 0x01,
    SWT_IP_STATUS_TIMEOUT   = 0x02
} Swt_Ip_StatusType;

/** @brief       Enum defining the possible lock types for the SWT
*/
typedef enum
{
    SWT_IP_UNLOCK           = 0x00,
    SWT_IP_SOFTLOCK         = 0x01,
    SWT_IP_HARDLOCK         = 0x02
} Swt_Ip_LockType;

/** @brief      Enum defining the possible service modes for the SWT
 */
typedef enum
{
    SWT_IP_FS_SEQ_MODE    = 0x00U,     /* Fixed Service Sequence */
    SWT_IP_KS_SEQ_MODE    = 0x01U,    /* Keyed Service Sequence */
} Swt_Ip_ServiceModeType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef void (*Swt_CallbackPtrType)(void);

/** @brief       Structure defining the configuration parameters used for SWT
* @implements    Swt_Ip_ConfigType_struct
*/
typedef struct
{
    uint8                   u8MapEnBitmask;
    boolean                 bEnResetOnInvalidAccess;
#if (defined(SWT_IP_HAS_STOP_MODE) && (SWT_IP_HAS_STOP_MODE == 1U)) 
    boolean                 bEnRunInStopMode;
#endif
    boolean                 bEnRunInDebugMode;
    boolean                 bEnWindow;
    boolean                 bEnInterrupt;  
    Swt_Ip_ServiceModeType      eServiceMode; 
    uint32                  u32TimeoutValue;
    uint32                  u32WindowValue;
    uint16                  u16InitialKey;
    Swt_Ip_LockType         lockConfig;
    Swt_CallbackPtrType     pfSwtCallback;
} Swt_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* SWT_IP_TYPES_H */
