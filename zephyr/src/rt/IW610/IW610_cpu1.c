/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

const uint8_t fw_cpu1[] = {
#ifndef CONFIG_BUILD_ONLY_NO_BLOBS
    #include <iw610_wifi_fw.bin.se.inc>
#endif
};

const unsigned char *wlan_fw_bin = (const unsigned char *)(void *)&fw_cpu1[0];
const unsigned int wlan_fw_bin_len = sizeof(fw_cpu1);