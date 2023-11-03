/**
 * 2023-11-03 - Created by Sendrato.com
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mcux_zephyr.h"
#include <zephyr/devicetree.h>

#if (defined(gSupportBle) && (gSupportBle == 1))

uint32_t _scratch_buf_start = (DT_REG_ADDR(DT_NODELABEL(sram0)));
uint32_t _scratch_buf_end   = (DT_REG_ADDR(DT_NODELABEL(sram0)) + 1024);

#endif