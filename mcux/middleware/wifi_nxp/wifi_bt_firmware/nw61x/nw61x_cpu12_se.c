/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <osa.h>

#if !CONFIG_UART_WIFI_BRIDGE

#if defined(SD9177)

#if !(CONFIG_WIFI_IND_DNLD) && !defined(CONFIG_BT_IND_DNLD)

const uint8_t fw_cpu12[] = {
#include <sduart_nw61x.bin.se.inc>
};

const unsigned char *wlan_fw_bin   = (const unsigned char *)(void *)&fw_cpu12[0];
const unsigned int wlan_fw_bin_len = sizeof(fw_cpu12);

const unsigned char bt_fw_bin[]  = {0x00};
const unsigned int bt_fw_bin_len = 0;

#endif

#endif

#endif
