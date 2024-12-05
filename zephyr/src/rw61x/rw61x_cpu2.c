/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <stdint.h>

#if defined(CONFIG_NXP_MONOLITHIC_NBU)
__attribute__ ((__section__(".fw_cpu2"), used))
const uint8_t fw_cpu2[] = {
    #include <rw61x_cpu2_fw.bin.inc>
};
#endif