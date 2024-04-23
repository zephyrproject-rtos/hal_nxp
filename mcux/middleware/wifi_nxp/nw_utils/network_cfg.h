/*
 * Copyright 2018-2021-2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _NETWORK_CFG_H_
#define _NETWORK_CFG_H_

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined(SDK_OS_FREE_RTOS)

#if !defined(IP_ADDR) && !defined(IP_MASK) && !defined(GW_ADDR)
#define IP_USE_DHCP
#endif

/* IP address configuration. */
#ifndef IP_ADDR
#define IP_ADDR "192.168.250.19"
#endif

/* Netmask configuration. */
#ifndef IP_MASK
#define IP_MASK "255.255.255.0"
#endif

/* Gateway address configuration. */
#ifndef GW_ADDR
#define GW_ADDR "192.168.250.10"
#endif

#endif

#endif /* _NETWORK_CFG_H_ */
