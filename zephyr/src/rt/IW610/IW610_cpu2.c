/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

const uint8_t fw_cpu2_bt[] = {
#ifndef CONFIG_BUILD_ONLY_NO_BLOBS
    #include <iw610_bt_fw.bin.inc>
#endif
};

const unsigned char *bt_fw_bin = (const unsigned char *)(void *)&fw_cpu2_bt[0];
const unsigned int bt_fw_bin_len = sizeof(fw_cpu2_bt);