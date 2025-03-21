/*
 * Copyright 2023-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

const uint8_t fw_cpu2_bt[] = {
    #include <nw61x_bt_fw.bin.inc>
};

const unsigned char *bt_fw_bin = (const unsigned char *)(void *)&fw_cpu2_bt[0];
const unsigned int bt_fw_bin_len = sizeof(fw_cpu2_bt);
