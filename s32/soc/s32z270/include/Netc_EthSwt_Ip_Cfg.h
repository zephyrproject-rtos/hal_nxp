/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETHSWT_IP_CFG_H
#define NETC_ETHSWT_IP_CFG_H

/**
 *   @file Netc_EthSwt_Ip_Cfg.h
 *   @addtogroup NETC_ETHSWT_IP NETC_ETHSWT Driver
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
#include "Netc_EthSwt_Ip_Sa_Init_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_CFG_VENDOR_ID                    43
#define NETC_ETHSWT_IP_CFG_MODULE_ID                    89
#define NETC_ETHSWT_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETHSWT_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETHSWT_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETHSWT_IP_CFG_SW_MAJOR_VERSION             2
#define NETC_ETHSWT_IP_CFG_SW_MINOR_VERSION             0
#define NETC_ETHSWT_IP_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_EthSwt_Ip_Sa_Init_PBcfg.h */
#if (NETC_ETHSWT_IP_CFG_VENDOR_ID != NETC_ETHSWT_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Netc_EthSwt_Ip_Cfg.h and Netc_EthSwt_Ip_Sa_Init_PBcfg.h have different vendor ids"
#endif
#if ((NETC_ETHSWT_IP_CFG_AR_RELEASE_MAJOR_VERSION    != NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_CFG_AR_RELEASE_MINOR_VERSION    != NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETHSWT_IP_CFG_AR_RELEASE_REVISION_VERSION != NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Cfg.h and Netc_EthSwt_Ip_Sa_Init_PBcfg.h are different"
#endif
#if ((NETC_ETHSWT_IP_CFG_SW_MAJOR_VERSION != NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_CFG_SW_MINOR_VERSION != NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (NETC_ETHSWT_IP_CFG_SW_PATCH_VERSION != NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip_Cfg.h and Netc_EthSwt_Ip_Sa_Init_PBcfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief      Specifies the cycle time of the periodic main function of EthSwt. Defined in seconds */
#define NETC_ETHSWT_IP_MAIN_FUNCTION_PERIOD         ((float32)0.001)

#define NETC_ETHSWT_CONFIG_EXT \
    NETC_ETHSWT_CONFIG_SA_INIT_PB \

#define NETC_ETHSWT_IP_TIMEOUT_TYPE                                    (OSIF_COUNTER_DUMMY)

#define NETC_ETHSWT_IP_TIMEOUT_VALUE_US                                (10000U)

#define NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES                              (0U)

#define NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES                       (0U)

#define NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES             (0U)

#define NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES                           (0U)

#define NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES                      (0U)

#define NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES                             (0U)

#define NETC_ETHSWT_NUMBER_OF_RP_ENTRIES                               (0U)

#define NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES                             (0U)

#define NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES                              (0U)

#define NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES                    (0U)

#define NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES                     (0U)

#define NETC_ETHSWT_NUMBER_OF_STREAMCOUNT_ENTRIES                      (0U)

#define NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES                  (0U)

#define NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES                (0U)


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

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* NETC_ETHSWT_IP_CFG_H */
