/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETHSWT_IP_SA_INIT_PBCFG_H
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_H

/**
 *   @file Netc_Eth_Ip_VS_0_PBcfg.h
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

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_VENDOR_ID                    43
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_MODULE_ID                    89
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION             0
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MINOR_VERSION             9
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Create define to export variant specific configuration. */
#define NETC_ETHSWT_CONFIG_SA_INIT_PB \
    extern const Netc_EthSwt_Ip_ConfigType Netc_EthSwt_0_ConfigPB_INIT;

#ifndef NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES
	#define NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES (0U)
#elif (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES < (0U))
	#undef NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES
	#define NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES (0U)
#endif /* NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES */

#ifndef NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES
	#define NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES (0U)
#elif (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES < (0U))
	#undef NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES
	#define NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES (0U)
#endif /* NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES */

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

#endif /* NETC_ETHSWT_IP_SA_INIT_PBCFG_H */
