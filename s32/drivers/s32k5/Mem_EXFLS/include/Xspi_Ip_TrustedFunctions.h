/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_TRUSTEDFUNCTIONS_H
#define XSPI_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Xspi_Ip_TrustedFunctions.h
*
*   @addtogroup XSPI_IP XSPI IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Xspi_Ip_Types.h"
#include "Xspi_Ip_Cfg.h"
#include "Xspi_Ip_Common.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define XSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define XSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        9
#define XSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define XSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                0
#define XSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                8
#define XSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Types header file are of the same vendor */
#if (XSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H != XSPI_IP_TYPES_VENDOR_ID)
    #error "Xspi_Ip_TrustedFunctions.h and Xspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Types header file are of the same Autosar version */
#if ((XSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_TrustedFunctions.h and Xspi_Ip_Types.h are different"
#endif
/* Check if current file and Xspi_Ip_Types header file are of the same Software version */
#if ((XSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H != XSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H != XSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H != XSPI_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_TrustedFunctions.h and Xspi_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#if (XSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)

extern void Xspi_Ip_Sfp_Configure_Privileged(uint32 instance, Xspi_Ip_SfpConfigType const * userConfigPtr);

extern void Xspi_Ip_Sfp_Lock_Privileged(uint32 instance, Xspi_Ip_SfpConfigType const * userConfigPtr);

extern void Xspi_Ip_Sfp_Disable_Privileged(uint32 instance);

extern void Xspi_Ip_GlobaConfigurationLock_Privileged(uint32 instance);

extern void Xspi_Ip_SetLutSeq_Privileged(uint32 instance, uint8 lutSeqNo, const Xspi_Ip_InstrOpType *opList);

extern void Xspi_Ip_ResetPrivilegedRegisters_Privileged(XSPI_Type *baseAddr);

extern void Xspi_Ip_SetAhbSeqId_Privileged(uint32 instance, uint8 seqID);

extern void Xspi_Ip_SetAhbWriteSeqId_Privileged(uint32 instance, uint8 seqID);

extern void Xspi_Ip_SetLutAccess_Privileged(uint32 instance, const uint16 *accessRights);

extern void Xspi_Ip_ControllerTimeoutsConfig_Privileged(uint32 instance, const Xspi_Ip_ControllerConfigType * userConfigPtr);

#endif /* XSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON */

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_TRUSTEDFUNCTIONS_H */
