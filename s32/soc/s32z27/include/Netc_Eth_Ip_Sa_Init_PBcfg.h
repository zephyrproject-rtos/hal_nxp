/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_SA_INIT_PBCFG_H
#define NETC_ETH_IP_SA_INIT_PBCFG_H

/**
*   @file Netc_Eth_Ip_Sa_INIT_PBcfg.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID                     43
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION              0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION              9
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* Create define to export varaint specific configuration. */
#define NETC_ETH_IP_CONFIG_SA_INIT_PB \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_0_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_1_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_2_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_3_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_4_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_5_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_6_ConfigPB_INIT; \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_7_ConfigPB_INIT;

#ifndef NETC_ETH_0_USED
	#define NETC_ETH_0_USED
#endif /* NETC_ETH_0_USED */
#ifndef NETC_ETH_1_USED
	#define NETC_ETH_1_USED
#endif /* NETC_ETH_1_USED */
#ifndef NETC_ETH_2_USED
	#define NETC_ETH_2_USED
#endif /* NETC_ETH_2_USED */
#ifndef NETC_ETH_3_USED
	#define NETC_ETH_3_USED
#endif /* NETC_ETH_3_USED */
#ifndef NETC_ETH_4_USED
	#define NETC_ETH_4_USED
#endif /* NETC_ETH_4_USED */
#ifndef NETC_ETH_5_USED
	#define NETC_ETH_5_USED
#endif /* NETC_ETH_5_USED */
#ifndef NETC_ETH_6_USED
	#define NETC_ETH_6_USED
#endif /* NETC_ETH_6_USED */
#ifndef NETC_ETH_7_USED
	#define NETC_ETH_7_USED
#endif /* NETC_ETH_7_USED */

/* ---------------------------------- BEGIN: TX generation ---------------------------------- */
/* Generate TX BDR defines for all rings used for each controller. */
/* NETC_ETH_#CONTROLLER_INDEX#_TXBDR_#RING_INDEX# */
#ifndef NETC_ETH_0_TXBDR_0
	#define NETC_ETH_0_TXBDR_0
#endif /* NETC_ETH_0_TXBDR_0 */

#ifndef NETC_ETH_0_TXBDATA_0
	#define NETC_ETH_0_TXBDATA_0
#endif /* NETC_ETH_0_TXBDATA_0 */

#ifndef NETC_ETH_0_TXBDR_1
	#define NETC_ETH_0_TXBDR_1
#endif /* NETC_ETH_0_TXBDR_1 */

#ifndef NETC_ETH_0_TXBDATA_1
	#define NETC_ETH_0_TXBDATA_1
#endif /* NETC_ETH_0_TXBDATA_1 */

#ifndef NETC_ETH_1_TXBDR_0
	#define NETC_ETH_1_TXBDR_0
#endif /* NETC_ETH_1_TXBDR_0 */

#ifndef NETC_ETH_1_TXBDATA_0
	#define NETC_ETH_1_TXBDATA_0
#endif /* NETC_ETH_1_TXBDATA_0 */

#ifndef NETC_ETH_2_TXBDR_0
	#define NETC_ETH_2_TXBDR_0
#endif /* NETC_ETH_2_TXBDR_0 */

#ifndef NETC_ETH_2_TXBDATA_0
	#define NETC_ETH_2_TXBDATA_0
#endif /* NETC_ETH_2_TXBDATA_0 */

#ifndef NETC_ETH_3_TXBDR_0
	#define NETC_ETH_3_TXBDR_0
#endif /* NETC_ETH_3_TXBDR_0 */

#ifndef NETC_ETH_3_TXBDATA_0
	#define NETC_ETH_3_TXBDATA_0
#endif /* NETC_ETH_3_TXBDATA_0 */

#ifndef NETC_ETH_4_TXBDR_0
	#define NETC_ETH_4_TXBDR_0
#endif /* NETC_ETH_4_TXBDR_0 */

#ifndef NETC_ETH_4_TXBDATA_0
	#define NETC_ETH_4_TXBDATA_0
#endif /* NETC_ETH_4_TXBDATA_0 */

#ifndef NETC_ETH_5_TXBDR_0
	#define NETC_ETH_5_TXBDR_0
#endif /* NETC_ETH_5_TXBDR_0 */

#ifndef NETC_ETH_5_TXBDATA_0
	#define NETC_ETH_5_TXBDATA_0
#endif /* NETC_ETH_5_TXBDATA_0 */

#ifndef NETC_ETH_6_TXBDR_0
	#define NETC_ETH_6_TXBDR_0
#endif /* NETC_ETH_6_TXBDR_0 */

#ifndef NETC_ETH_6_TXBDATA_0
	#define NETC_ETH_6_TXBDATA_0
#endif /* NETC_ETH_6_TXBDATA_0 */

#ifndef NETC_ETH_7_TXBDR_0
	#define NETC_ETH_7_TXBDR_0
#endif /* NETC_ETH_7_TXBDR_0 */

#ifndef NETC_ETH_7_TXBDATA_0
	#define NETC_ETH_7_TXBDATA_0
#endif /* NETC_ETH_7_TXBDATA_0 */

/* Generate the maximum number of descriptors between variants(VS) for each ring. */
#ifndef NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR */

/* Generate the maximum buffer length between variants(VS) for each ring. */
#ifndef NETC_ETH_0_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_0_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_0_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_0_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_0_TXBDR_1_MAX_BUFFLEN
	#define NETC_ETH_0_TXBDR_1_MAX_BUFFLEN (64U)
#elif (NETC_ETH_0_TXBDR_1_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_0_TXBDR_1_MAX_BUFFLEN
	#define NETC_ETH_0_TXBDR_1_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_0_TXBDR_1_MAX_BUFFLEN */

#ifndef NETC_ETH_1_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_1_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_1_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_1_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_1_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_1_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_2_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_2_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_2_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_2_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_2_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_2_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_3_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_3_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_3_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_3_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_3_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_3_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_4_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_4_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_4_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_4_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_4_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_4_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_5_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_5_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_5_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_5_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_5_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_5_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_6_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_6_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_6_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_6_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_6_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_6_TXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_7_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_7_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_7_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_7_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_7_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_7_TXBDR_0_MAX_BUFFLEN */

/* Maximum number of TX descriptors from all controllers on the current variant. */
#ifndef NETC_ETH_MAX_NUMBER_OF_TXBD
	#define NETC_ETH_MAX_NUMBER_OF_TXBD (8U)
#elif (NETC_ETH_MAX_NUMBER_OF_TXBD < (8U))
	#undef NETC_ETH_MAX_NUMBER_OF_TXBD
	#define NETC_ETH_MAX_NUMBER_OF_TXBD (8U)
#endif /* NETC_ETH_MAX_NUMBER_OF_TXBD */

/* ---------------------------------- END: TX generation ---------------------------------- */

/* ---------------------------------- BEGIN: RX generation ---------------------------------- */
/* Generate RX BDR defines for all rings used for each controller. */
/* NETC_ETH_#CONTROLLER_INDEX#_RXBDR_#RING_INDEX# */
#ifndef NETC_ETH_0_RXBDR_0
	#define NETC_ETH_0_RXBDR_0
#endif /* NETC_ETH_0_RXBDR_0 */

#ifndef NETC_ETH_0_RXBDATA_0
	#define NETC_ETH_0_RXBDATA_0
#endif /* NETC_ETH_0_RXBDATA_0 */

#ifndef NETC_ETH_1_RXBDR_0
	#define NETC_ETH_1_RXBDR_0
#endif /* NETC_ETH_1_RXBDR_0 */

#ifndef NETC_ETH_1_RXBDATA_0
	#define NETC_ETH_1_RXBDATA_0
#endif /* NETC_ETH_1_RXBDATA_0 */

#ifndef NETC_ETH_2_RXBDR_0
	#define NETC_ETH_2_RXBDR_0
#endif /* NETC_ETH_2_RXBDR_0 */

#ifndef NETC_ETH_2_RXBDATA_0
	#define NETC_ETH_2_RXBDATA_0
#endif /* NETC_ETH_2_RXBDATA_0 */

#ifndef NETC_ETH_3_RXBDR_0
	#define NETC_ETH_3_RXBDR_0
#endif /* NETC_ETH_3_RXBDR_0 */

#ifndef NETC_ETH_3_RXBDATA_0
	#define NETC_ETH_3_RXBDATA_0
#endif /* NETC_ETH_3_RXBDATA_0 */

#ifndef NETC_ETH_4_RXBDR_0
	#define NETC_ETH_4_RXBDR_0
#endif /* NETC_ETH_4_RXBDR_0 */

#ifndef NETC_ETH_4_RXBDATA_0
	#define NETC_ETH_4_RXBDATA_0
#endif /* NETC_ETH_4_RXBDATA_0 */

#ifndef NETC_ETH_5_RXBDR_0
	#define NETC_ETH_5_RXBDR_0
#endif /* NETC_ETH_5_RXBDR_0 */

#ifndef NETC_ETH_5_RXBDATA_0
	#define NETC_ETH_5_RXBDATA_0
#endif /* NETC_ETH_5_RXBDATA_0 */

#ifndef NETC_ETH_6_RXBDR_0
	#define NETC_ETH_6_RXBDR_0
#endif /* NETC_ETH_6_RXBDR_0 */

#ifndef NETC_ETH_6_RXBDATA_0
	#define NETC_ETH_6_RXBDATA_0
#endif /* NETC_ETH_6_RXBDATA_0 */

#ifndef NETC_ETH_7_RXBDR_0
	#define NETC_ETH_7_RXBDR_0
#endif /* NETC_ETH_7_RXBDR_0 */

#ifndef NETC_ETH_7_RXBDATA_0
	#define NETC_ETH_7_RXBDATA_0
#endif /* NETC_ETH_7_RXBDATA_0 */

/* Generate the maximum number of descriptors between variants(VS) for each ring. */
#ifndef NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR */

#ifndef NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR */

/* Generate the maximum buffer length between variants(VS) for each ring. */
#ifndef NETC_ETH_0_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_0_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_0_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_0_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_1_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_1_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_1_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_1_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_1_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_1_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_2_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_2_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_2_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_2_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_2_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_2_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_3_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_3_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_3_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_3_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_3_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_3_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_4_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_4_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_4_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_4_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_4_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_4_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_5_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_5_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_5_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_5_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_5_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_5_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_6_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_6_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_6_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_6_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_6_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_6_RXBDR_0_MAX_BUFFLEN */

#ifndef NETC_ETH_7_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_7_RXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_7_RXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_7_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_7_RXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_7_RXBDR_0_MAX_BUFFLEN */

/* Maximum number of RX rings between all controllers on the current variant. */
#ifndef NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS     (1U)
#elif (NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS < (1U))
#undef NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS     (1U)
#endif /* NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS */
/* Maximum number of RX descriptors between all controllers on the current variant. */
#ifndef NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS     (8U)
#elif (NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS < (8U))
#undef NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS (8U)
#endif /* NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS */
/* Maximum number of RX descriptors from all controllers on the current variant. */
#ifndef NETC_ETH_MAX_NUMBER_OF_RXBD
	#define NETC_ETH_MAX_NUMBER_OF_RXBD (8U)
#elif (NETC_ETH_MAX_NUMBER_OF_RXBD < (8U))
	#undef NETC_ETH_MAX_NUMBER_OF_RXBD
	#define NETC_ETH_MAX_NUMBER_OF_RXBD (8U)
#endif /* NETC_ETH_MAX_NUMBER_OF_RXBD */

/* ---------------------------------- END: RX generation ---------------------------------- */

/** @brief Size of table of hash values and MAC address for controller 0. */
#ifndef NETC_ETH_IP_CTRL_0_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_0_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_0_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_0_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_0_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_0_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 1. */
#ifndef NETC_ETH_IP_CTRL_1_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_1_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_1_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_1_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_1_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_1_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 2. */
#ifndef NETC_ETH_IP_CTRL_2_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_2_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_2_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_2_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_2_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_2_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 3. */
#ifndef NETC_ETH_IP_CTRL_3_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_3_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_3_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_3_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_3_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_3_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 4. */
#ifndef NETC_ETH_IP_CTRL_4_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_4_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_4_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_4_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_4_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_4_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 5. */
#ifndef NETC_ETH_IP_CTRL_5_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_5_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_5_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_5_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_5_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_5_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 6. */
#ifndef NETC_ETH_IP_CTRL_6_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_6_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_6_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_6_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_6_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_6_MAC_FILTER_TABLE_DIM */
/** @brief Size of table of hash values and MAC address for controller 7. */
#ifndef NETC_ETH_IP_CTRL_7_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_7_MAC_FILTER_TABLE_DIM (8U)
#elif (NETC_ETH_IP_CTRL_7_MAC_FILTER_TABLE_DIM < (8U))
	#undef NETC_ETH_IP_CTRL_7_MAC_FILTER_TABLE_DIM
	#define NETC_ETH_IP_CTRL_7_MAC_FILTER_TABLE_DIM (8U)
#endif /* NETC_ETH_IP_CTRL_7_MAC_FILTER_TABLE_DIM */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* NETC_ETH_IP_SA_INIT_PBCFG_H */
