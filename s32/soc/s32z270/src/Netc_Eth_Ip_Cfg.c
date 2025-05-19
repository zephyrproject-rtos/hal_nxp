/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Netc_Eth_Ip_Cfg.c
*
*   @addtogroup Netc_Eth_Ip
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
#include "Netc_Eth_Ip_Types.h"
#include "Netc_Eth_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_IP_CFG_VENDOR_ID_C                     43
#define NETC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define NETC_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define NETC_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define NETC_IP_CFG_SW_MAJOR_VERSION_C              2
#define NETC_IP_CFG_SW_MINOR_VERSION_C              0
#define NETC_IP_CFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Types.h */
#if (NETC_IP_CFG_VENDOR_ID_C != NETC_ETH_IP_TYPES_VENDOR_ID)
    #error "Netc_Eth_Ip_Cfg.c and Netc_Eth_Ip_Types.h have different vendor ids"
#endif
#if ((NETC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Cfg.c and Netc_Eth_Ip_Types.h are different"
#endif
#if ((NETC_IP_CFG_SW_MAJOR_VERSION_C != NETC_ETH_IP_TYPES_SW_MAJOR_VERSION) || \
     (NETC_IP_CFG_SW_MINOR_VERSION_C != NETC_ETH_IP_TYPES_SW_MINOR_VERSION) || \
     (NETC_IP_CFG_SW_PATCH_VERSION_C != NETC_ETH_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Cfg.c and Netc_Eth_Ip_Types.h are different"
#endif

/* Checks against Netc_Eth_Ip_Cfg.h */
#if (NETC_IP_CFG_VENDOR_ID_C != NETC_ETH_IP_CFG_VENDOR_ID)
    #error "Netc_Eth_Ip_Cfg.c and Netc_Eth_Ip_Cfg.h have different vendor ids"
#endif
#if ((NETC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Cfg.c and Netc_Eth_Ip_Cfg.h are different"
#endif
#if ((NETC_IP_CFG_SW_MAJOR_VERSION_C != NETC_ETH_IP_CFG_SW_MAJOR_VERSION) || \
     (NETC_IP_CFG_SW_MINOR_VERSION_C != NETC_ETH_IP_CFG_SW_MINOR_VERSION) || \
     (NETC_IP_CFG_SW_PATCH_VERSION_C != NETC_ETH_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Cfg.c and Netc_Eth_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

/** @brief Base address of all SIs. */
Netc_Eth_Ip_SiBaseType *netcSIsBase[] = { (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI0, (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI1, \
                                          (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI2, (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI3, \
                                          (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI4, (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI5, \
                                          (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI6, (Netc_Eth_Ip_SiBaseType*)IP_NETC__ENETC0_SI7 };

/** @brief Base address for all VFs. NULL_PTR is added as the hardware has only 7 VF starting from 1. */
Netc_Eth_Ip_VfBaseType *netcVFBase[] = { (Netc_Eth_Ip_VfBaseType *)NULL_PTR, \
                                         (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF1_PCI_HDR_TYPE0, (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF2_PCI_HDR_TYPE0, \
                                         (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF3_PCI_HDR_TYPE0, (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF4_PCI_HDR_TYPE0, \
                                         (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF5_PCI_HDR_TYPE0, (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF6_PCI_HDR_TYPE0, \
                                         (Netc_Eth_Ip_VfBaseType *)IP_NETC__NETC_VF7_PCI_HDR_TYPE0};
                                         
/** @brief Base address for all VFs. NULL_PTR is added as the hardware has only 7 VF starting from 1. */
Netc_Eth_Ip_PCIeBaseType *netcPCIePFBase[] = { (Netc_Eth_Ip_PCIeBaseType *)IP_NETC__NETC_F0_PCI_HDR_TYPE0, (Netc_Eth_Ip_PCIeBaseType *)IP_NETC__NETC_F1_PCI_HDR_TYPE0, \
                                               (Netc_Eth_Ip_PCIeBaseType *)IP_NETC__NETC_F2_PCI_HDR_TYPE0, (Netc_Eth_Ip_PCIeBaseType *)IP_NETC__NETC_F3_PCI_HDR_TYPE0};

#define ETH_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

