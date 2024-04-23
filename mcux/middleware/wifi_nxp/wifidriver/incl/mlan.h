/** @file mlan.h
 *
 *  @brief This file declares all APIs that will be called from MOAL module.
 *  It also defines the data structures used for APIs between MLAN and MOAL.
 *
 *  Copyright 2008-2021, 2023 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/******************************************************
Change log:
    10/13/2008: initial version
    11/07/2008: split mlan.h into mlan_decl.h & mlan_ioctl.h
******************************************************/

#ifndef _MLAN_H_
#define _MLAN_H_

#ifdef __ZEPHYR__
#include "nxp_wifi.h"
#endif




#ifndef __ZEPHYR__
#ifndef CONFIG_STA_AUTO_DHCPV4
#define CONFIG_STA_AUTO_DHCPV4 1
#endif
#endif

#ifndef __ZEPHYR__
#ifndef CONFIG_WIFI_STA_RECONNECT
#define CONFIG_WIFI_STA_RECONNECT 1
#endif
#endif

#ifndef __ZEPHYR__
#ifndef CONFIG_WIFI_AUTO_POWER_SAVE
#define CONFIG_WIFI_AUTO_POWER_SAVE 1
#endif
#endif

#if !(defined(SD8801) || defined(RW610))
#define CONFIG_GTK_REKEY_OFFLOAD 1
#endif

#if defined(SD9177)
#define CONFIG_TCP_ACK_ENH 1
#define CONFIG_FW_VDLL     1
#endif

#ifdef CONFIG_11AX
#ifndef CONFIG_11K
#define CONFIG_11K 1
#endif
#ifndef CONFIG_11V
#define CONFIG_11V 1
#endif
#ifndef CONFIG_WPA_SUPP
#define CONFIG_DRIVER_MBO 1
#endif
#endif

#include "mlan_decl.h"
#include "mlan_ioctl.h"
#include "mlan_ieee.h"

#endif /* !_MLAN_H_ */
