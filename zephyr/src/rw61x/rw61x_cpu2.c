/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

#if defined(CONFIG_NXP_MONOLITHIC_IEEE802154)
__attribute__ ((__section__(".fw_cpu2_combo"), used))
const uint8_t fw_cpu2_combo[] = {
    #include <rw61x_combo_fw.bin.inc>
};
#elif defined(CONFIG_NXP_MONOLITHIC_BT)
__attribute__ ((__section__(".fw_cpu2_ble"), used))
const uint8_t fw_cpu2_ble[] = {
    #include <rw61x_ble_fw.bin.inc>
};
#endif
