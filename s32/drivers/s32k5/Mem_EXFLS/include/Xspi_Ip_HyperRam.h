/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_HYPERRAM_H
#define XSPI_IP_HYPERRAM_H

/**
*   @file Xspi_Ip_HyperRam.h
*
*   @addtogroup IPV_XSPI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Xspi_Ip_Types.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_HYPERRAM_VENDOR_ID_H                    43
#define XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_H     4
#define XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_H     9
#define XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_H  0
#define XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_H             0
#define XSPI_IP_HYPERRAM_SW_MINOR_VERSION_H             8
#define XSPI_IP_HYPERRAM_SW_PATCH_VERSION_H             0

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Types header file are of the same vendor */
#if (XSPI_IP_HYPERRAM_VENDOR_ID_H != XSPI_IP_TYPES_VENDOR_ID)
    #error "Xspi_Ip_HyperRam.h and Xspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Types header file are of the same Autosar version */
#if ((XSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HyperRam.h and Xspi_Ip_Types.h are different"
#endif
/* Check if current file and Xspi_Ip_Types header file are of the same Software version */
#if ((XSPI_IP_HYPERRAM_SW_MAJOR_VERSION_H != XSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_HYPERRAM_SW_MINOR_VERSION_H != XSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_HYPERRAM_SW_PATCH_VERSION_H != XSPI_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_HyperRam.h and Xspi_Ip_Types.h are different"
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

#if (XSPI_IP_HYPERRAM_ENABLED == STD_ON)

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_HyperRamInit
 * Description   : Initial hyperram device
 *END**************************************************************************/
Xspi_Ip_StatusType Xspi_Ip_HyperRamInit(uint32 instance);

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_ArbUnlock
 * Description   : Unlocks XSPI arbitration
 *END**************************************************************************/
Xspi_Ip_StatusType Xspi_Ip_HyperRamArbUnlock(uint32 instance, uint32 address);

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_HyperRamArbLock
 * Description   : Locks XSPI arbitration
 *END**************************************************************************/
Xspi_Ip_StatusType Xspi_Ip_HyperRamArbLock(uint32 instance, uint32 address);

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* XSPI_IP_HYPERRAM_ENABLED == STD_ON */
#endif /* XSPI_IP_MEM_INSTANCE_COUNT */

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* XSPI_IP_HYPERRAM_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/

