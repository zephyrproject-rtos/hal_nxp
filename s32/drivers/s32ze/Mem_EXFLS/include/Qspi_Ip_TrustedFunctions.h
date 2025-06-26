/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_TRUSTEDFUNCTIONS_H
#define QSPI_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Qspi_Ip_TrustedFunctions.h
*
*   @addtogroup IPV_QSPI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Qspi_Ip_Types.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                2
#define QSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define QSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Types header file are of the same vendor */
#if (QSPI_IP_TYPES_VENDOR_ID_CFG != QSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Autosar version */
#if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Types.h are different"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Software version */
#if ((QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_TYPES_SW_MINOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_TYPES_SW_PATCH_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Types.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_CFG != QSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_SW_MINOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_SW_PATCH_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Cfg.h are different"
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


#if (QSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)

extern void Qspi_Ip_Sfp_Configure_Privileged(QuadSPI_Type * baseAddr,
                                             Qspi_Ip_ControllerConfigType const * userConfigPtr
                                            );

extern void Qspi_Ip_Sfp_ClearLatchedErrors_Privileged(QuadSPI_Type * BaseAddr);

extern void Qspi_Ip_ResetPrivilegedRegisters_Privileged(QuadSPI_Type * BaseAddr);

extern void Qspi_Ip_WriteLuts_Privileged(uint32 Instance,
                                         uint8 StartLutRegister,
                                         const uint32 *Data,
                                         uint8 Size
                                        );

extern void Qspi_Ip_SetAhbSeqId_Privileged(uint32 instance, uint8 seqID);

#endif /* QSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON */


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_TRUSTEDFUNCTIONS_H */

