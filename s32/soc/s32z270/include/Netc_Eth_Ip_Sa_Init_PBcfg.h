/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_SA_INIT_PBCFG_H
#define NETC_ETH_IP_SA_INIT_PBCFG_H

#define NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID                     43
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION              2
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION              0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION              1

#ifndef NETC_ETH_0_USED
	#define NETC_ETH_0_USED
#endif /* NETC_ETH_0_USED */

/* Not used but required to build the baremetal drivers */
#define NETC_ETH_IP_CONFIG_SA_INIT_PB

/* Maximum number of TX descriptors */
#define NETC_ETH_MAX_NUMBER_OF_TXBD     CONFIG_ETH_NXP_S32_TX_RING_BUF_SIZE

#endif /* NETC_ETH_IP_SA_INIT_PBCFG_H */
