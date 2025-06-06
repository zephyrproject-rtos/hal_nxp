/*
 * Copyright 2023-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

const uint8_t fw_cpu1[] = {
#ifndef CONFIG_BUILD_ONLY_NO_BLOBS
    #include <nw61x_wifi_fw.bin.se.inc>
#endif /*CONFIG_BUILD_ONLY_NO_BLOBS*/
};

const unsigned char *wlan_fw_bin = (const unsigned char *)(void *)&fw_cpu1[0];
const unsigned int wlan_fw_bin_len = sizeof(fw_cpu1);
