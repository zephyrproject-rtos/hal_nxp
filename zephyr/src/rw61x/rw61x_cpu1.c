/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

#if defined(CONFIG_NXP_MONOLITHIC_WIFI)
__attribute__ ((__section__(".fw_cpu1"), used))
const uint8_t fw_cpu1[] = {
    #include <rw61x_wifi_fw.bin.inc>
};

const unsigned char *wlan_fw_bin = (const unsigned char *)(void *)&fw_cpu1[0];
const unsigned int wlan_fw_bin_len = sizeof(fw_cpu1);
#endif
