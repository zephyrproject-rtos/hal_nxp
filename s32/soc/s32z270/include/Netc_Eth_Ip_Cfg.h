/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_CFG_H
#define NETC_ETH_IP_CFG_H

/**
*   @file Netc_Eth_Ip_Cfg.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
==================================================================================================*/
/* Include all variants header files. */
#include "Netc_Eth_Ip_Sa_Init_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_CFG_VENDOR_ID                    43
#define NETC_ETH_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_CFG_SW_MAJOR_VERSION             2
#define NETC_ETH_IP_CFG_SW_MINOR_VERSION             0
#define NETC_ETH_IP_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Sa_Init_PBcfg.h */
#if (NETC_ETH_IP_CFG_VENDOR_ID != NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Netc_Eth_Ip_Cfg.h and Netc_Eth_Ip_Sa_Init_PBcfg.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_CFG_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_CFG_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_CFG_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Cfg.h and Netc_Eth_Ip_Sa_Init_PBcfg.h are different"
#endif
#if ((NETC_ETH_IP_CFG_SW_MAJOR_VERSION != NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_CFG_SW_MINOR_VERSION != NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_CFG_SW_PATCH_VERSION != NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_Eth_Ip_Cfg.h and Netc_Eth_Ip_Sa_Init_PBcfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief Export all PB configurations used. */
#define NETC_ETH_IP_CONFIG_EXT \
    NETC_ETH_IP_CONFIG_SA_INIT_PB \

#define FEATURE_NETC_ETH_VSI_MSG_ALIGNMENT          (64U)

#if (STD_OFF == NETC_ETH_IP_EXTENDED_BUFF)
    /** @brief Value used to increment producer index. */
    #define  NETC_ETH_IP_PRODUCER_INCR            (1U)
#else
    /** @brief Value used to increment producer index. */
    #define  NETC_ETH_IP_PRODUCER_INCR            (2U)
#endif

/** @brief Timeout type used. */
#define NETC_ETH_IP_TIMEOUT_TYPE              (OSIF_COUNTER_DUMMY)

/** @brief Timeout value in microseconds. */
#define NETC_ETH_IP_TIMEOUT_VALUE_US          (1000U)

/*! @brief Enables / Disables the Switch Management APIs */
#define NETC_ETH_IP_MANAGEMENT_SUPPORT_API   (STD_OFF)

/*! @brief Enables / Disables the allocation of the TX data buffers. */
#define NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS  (STD_OFF)

/*! @brief Enables / Disables the allocation of the RX data buffers. */
#define NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS  (STD_OFF)

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
/*! @brief Array of the feature of external buffers support indexed at controller level. */
    #define NETC_ETH_IP_INST_HAS_EXTERNAL_TX_BUFFERS  {(boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE}
#endif

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
/*! @brief Array of the feature of external buffers support indexed at controller level. */
    #define NETC_ETH_IP_INST_HAS_EXTERNAL_RX_BUFFERS  {(boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE}
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* NETC_ETH_IP_CFG_H */

