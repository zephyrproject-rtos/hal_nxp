/** @file wlan_txpwrlimit_cfg_maya_W1.h
 *
 *  @brief  This file provides Maya W1 Tx Power Limits.
 *
 *  NOTE: The compress Tx power values in this file are taken from
 *  https://github.com/u-blox/u-blox-sho-host-based/tree/main/MAYA-W1/txpower_config
 *
 *  Copyright 2026 NXP
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  'Software'), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sub license, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject
 *  to the following conditions:
 *
 *  The above copyright notice and this permission notice (including the
 *  next paragraph) shall be included in all copies or substantial
 *  portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 *  IN NO EVENT SHALL NXP AND/OR ITS SUPPLIERS BE LIABLE FOR ANY
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _WLAN_TXPWRLIMIT_CFG_WW_H_
#define _WLAN_TXPWRLIMIT_CFG_WW_H_

#include <wlan.h>
#include <wifi.h>

#if !CONFIG_COMPRESS_TX_PWTBL
#define WLAN_REGION_CODE "WW"
#endif

static wlan_chanlist_t chanlist_2g_cfg = {.num_chans = 13,
                                          .chan_info = {
                                              [0] =
                                                  {
                                                      .chan_num                     = 1,
                                                      .chan_freq                    = 2412,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [1] =
                                                  {
                                                      .chan_num                     = 2,
                                                      .chan_freq                    = 2417,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [2] =
                                                  {
                                                      .chan_num                     = 3,
                                                      .chan_freq                    = 2422,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [3] =
                                                  {
                                                      .chan_num                     = 4,
                                                      .chan_freq                    = 2427,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [4] =
                                                  {
                                                      .chan_num                     = 5,
                                                      .chan_freq                    = 2432,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [5] =
                                                  {
                                                      .chan_num                     = 6,
                                                      .chan_freq                    = 2437,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [6] =
                                                  {
                                                      .chan_num                     = 7,
                                                      .chan_freq                    = 2442,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [7] =
                                                  {
                                                      .chan_num                     = 8,
                                                      .chan_freq                    = 2447,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [8] =
                                                  {
                                                      .chan_num                     = 9,
                                                      .chan_freq                    = 2452,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [9] =
                                                  {
                                                      .chan_num                     = 10,
                                                      .chan_freq                    = 2457,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [10] =
                                                  {
                                                      .chan_num                     = 11,
                                                      .chan_freq                    = 2462,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [11] =
                                                  {
                                                      .chan_num                     = 12,
                                                      .chan_freq                    = 2467,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [12] =
                                                  {
                                                      .chan_num                     = 13,
                                                      .chan_freq                    = 2472,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [13] = {0},
                                              [14] = {0},
                                              [15] = {0},
                                              [16] = {0},
                                              [17] = {0},
                                              [18] = {0},
                                              [19] = {0},
                                              [20] = {0},
                                              [21] = {0},
                                              [22] = {0},
                                              [23] = {0},
                                              [24] = {0},
                                              [25] = {0},
                                              [26] = {0},
                                              [27] = {0},
                                              [28] = {0},
                                              [29] = {0},
                                              [30] = {0},
                                              [31] = {0},
                                              [32] = {0},
                                              [33] = {0},
                                              [34] = {0},
                                              [35] = {0},
                                              [36] = {0},
                                              [37] = {0},
                                              [38] = {0},
                                              [39] = {0},
                                              [40] = {0},
                                              [41] = {0},
                                              [42] = {0},
                                              [43] = {0},
                                              [44] = {0},
                                              [45] = {0},
                                              [46] = {0},
                                              [47] = {0},
                                              [48] = {0},
                                              [49] = {0},
                                              [50] = {0},
                                              [51] = {0},
                                              [52] = {0},
                                              [53] = {0},
                                          }};

#if CONFIG_5GHz_SUPPORT
static wlan_chanlist_t chanlist_5g_cfg = {.num_chans = 25,
                                          .chan_info = {
                                              [0] =
                                                  {
                                                      .chan_num                     = 36,
                                                      .chan_freq                    = 5180,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [1] =
                                                  {
                                                      .chan_num                     = 40,
                                                      .chan_freq                    = 5200,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [2] =
                                                  {
                                                      .chan_num                     = 44,
                                                      .chan_freq                    = 5220,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [3] =
                                                  {
                                                      .chan_num                     = 48,
                                                      .chan_freq                    = 5240,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [4] =
                                                  {
                                                      .chan_num                     = 52,
                                                      .chan_freq                    = 5260,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [5] =
                                                  {
                                                      .chan_num                     = 56,
                                                      .chan_freq                    = 5280,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [6] =
                                                  {
                                                      .chan_num                     = 60,
                                                      .chan_freq                    = 5300,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [7] =
                                                  {
                                                      .chan_num                     = 64,
                                                      .chan_freq                    = 5320,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [8] =
                                                  {
                                                      .chan_num                     = 100,
                                                      .chan_freq                    = 5500,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [9] =
                                                  {
                                                      .chan_num                     = 104,
                                                      .chan_freq                    = 5520,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [10] =
                                                  {
                                                      .chan_num                     = 108,
                                                      .chan_freq                    = 5540,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [11] =
                                                  {
                                                      .chan_num                     = 112,
                                                      .chan_freq                    = 5560,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [12] =
                                                  {
                                                      .chan_num                     = 116,
                                                      .chan_freq                    = 5580,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [13] =
                                                  {
                                                      .chan_num                     = 120,
                                                      .chan_freq                    = 5600,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [14] =
                                                  {
                                                      .chan_num                     = 124,
                                                      .chan_freq                    = 5620,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [15] =
                                                  {
                                                      .chan_num                     = 128,
                                                      .chan_freq                    = 5640,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [16] =
                                                  {
                                                      .chan_num                     = 132,
                                                      .chan_freq                    = 5660,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [17] =
                                                  {
                                                      .chan_num                     = 136,
                                                      .chan_freq                    = 5680,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [18] =
                                                  {
                                                      .chan_num                     = 140,
                                                      .chan_freq                    = 5700,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [19] =
                                                  {
                                                      .chan_num                     = 144,
                                                      .chan_freq                    = 5720,
                                                      .passive_scan_or_radar_detect = true,
                                                  },
                                              [20] =
                                                  {
                                                      .chan_num                     = 149,
                                                      .chan_freq                    = 5745,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [21] =
                                                  {
                                                      .chan_num                     = 153,
                                                      .chan_freq                    = 5765,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [22] =
                                                  {
                                                      .chan_num                     = 157,
                                                      .chan_freq                    = 5785,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [23] =
                                                  {
                                                      .chan_num                     = 161,
                                                      .chan_freq                    = 5805,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [24] =
                                                  {
                                                      .chan_num                     = 165,
                                                      .chan_freq                    = 5825,
                                                      .passive_scan_or_radar_detect = false,
                                                  },
                                              [25] = {0},
                                              [26] = {0},
                                              [27] = {0},
                                              [28] = {0},
                                              [29] = {0},
                                              [30] = {0},
                                              [31] = {0},
                                              [32] = {0},
                                              [33] = {0},
                                              [34] = {0},
                                              [35] = {0},
                                              [36] = {0},
                                              [37] = {0},
                                              [38] = {0},
                                              [39] = {0},
                                              [40] = {0},
                                              [41] = {0},
                                              [42] = {0},
                                              [43] = {0},
                                              [44] = {0},
                                              [45] = {0},
                                              [46] = {0},
                                              [47] = {0},
                                              [48] = {0},
                                              [49] = {0},
                                              [50] = {0},
                                              [51] = {0},
                                              [52] = {0},
                                              [53] = {0},
                                          }};
#endif

#if CONFIG_COMPRESS_TX_PWTBL

static const t_u8 rg_table_WW[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x57, 0x57, 0x20, 0x00, 0x00, 0x00, 0x06, 0x02, 0x46, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x57, 0x20, 0x00, 0x43, 0x03, 0x00, 0x00, 0x08, 0x05,
    0x03, 0x00, 0x80, 0x83, 0x60, 0x02, 0x06, 0x0a, 0x83, 0x40, 0x21, 0x20, 0x40, 0x58, 0x3c, 0x10, 0x04, 0x06,
    0x00, 0x51, 0x80, 0xe0, 0x58, 0x04, 0x00, 0x27, 0x04, 0x06, 0x00, 0x00, 0xe0, 0x40, 0x66, 0x37, 0x1d, 0x8f,
    0xc7, 0xa3, 0x92, 0x29, 0x04, 0x72, 0x35, 0x0e, 0x93, 0xc6, 0x40, 0x10, 0xe0, 0x08};

static const t_u8 rg_table_JP[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x4a, 0x50, 0x20, 0x40, 0x00, 0x03, 0x06, 0x02, 0x4e, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x50, 0x20, 0x40, 0xc3, 0x03, 0x00, 0x00, 0x0c, 0x06,
    0xab, 0x00, 0x21, 0x20, 0x68, 0x02, 0x07, 0x05, 0x83, 0xc1, 0x82, 0x10, 0x88, 0x5c, 0x2a, 0x19, 0x05, 0x15,
    0x82, 0x00, 0x80, 0xb0, 0x7a, 0xb0, 0x0a, 0x8c, 0x07, 0x02, 0xc0, 0x20, 0x01, 0x38, 0x48, 0x26, 0x00, 0x09,
    0x84, 0x82, 0x92, 0x00, 0x90, 0x04, 0x21, 0x1f, 0x09, 0x84, 0x24, 0x72, 0x99, 0x5c, 0xaa, 0x41, 0x2e, 0x96,
    0x4b, 0xe5, 0xa0, 0x10};

static const t_u8 rg_table_US[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x55, 0x53, 0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0xb2, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x53, 0x20, 0x10, 0x03, 0x0a, 0x00, 0x00, 0x0c, 0x01,
    0x02, 0x00, 0xf0, 0x05, 0x60, 0x0c, 0x24, 0x0b, 0x00, 0x00, 0xc2, 0x00, 0x10, 0x90, 0x20, 0x22, 0x01, 0x85,
    0xc2, 0x61, 0x70, 0xd8, 0x7c, 0x46, 0x15, 0x08, 0x01, 0x83, 0xe2, 0x00, 0x98, 0xd4, 0x26, 0x34, 0x10, 0x8e,
    0x00, 0x63, 0xd1, 0xb8, 0xe8, 0x14, 0x1c, 0x02, 0x8f, 0x80, 0x41, 0xe0, 0x30, 0x00, 0x1e, 0x4f, 0x29, 0x95,
    0xcb, 0x65, 0xf1, 0x09, 0x54, 0xb0, 0x0a, 0x08, 0x02, 0x02, 0xc1, 0xd1, 0xa9, 0xc0, 0x30, 0x02, 0x8c, 0x07,
    0x2b, 0xe4, 0x42, 0x70, 0x88, 0x1c, 0x20, 0x02, 0x86, 0xc2, 0xc1, 0xd1, 0x00, 0x14, 0x3c, 0x24, 0x02, 0x00,
    0x03, 0xe8, 0xb4, 0x7a, 0x48, 0x06, 0x97, 0x47, 0xa7, 0x54, 0x01, 0xe1, 0x00, 0x95, 0x5c, 0x0b, 0x51, 0x08,
    0x01, 0xc1, 0xe0, 0x29, 0x05, 0x7a, 0xc1, 0x62, 0xb2, 0x02, 0x6c, 0xd5, 0xbb, 0x45, 0x96, 0x21, 0x5f, 0x07,
    0xc9, 0xc2, 0x00, 0x49, 0x38, 0x36, 0xc8, 0x06, 0xbb, 0x00, 0x22, 0x00, 0x40, 0x00, 0x42, 0xe5, 0x74, 0x01,
    0x5d, 0x82, 0x17, 0x8a, 0x85, 0xee, 0xfb, 0x7f, 0xba, 0xdd, 0xef, 0x38, 0x60, 0x80};

static const t_u8 rg_table_EU[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x45, 0x55, 0x20, 0x30, 0x00, 0x02, 0x06, 0x02, 0x5f, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x55, 0x20, 0x30, 0xd3, 0x04, 0x00, 0x00, 0x0c, 0x06,
    0xab, 0x00, 0x21, 0x20, 0x68, 0x02, 0x07, 0x05, 0x83, 0xc1, 0x82, 0x10, 0x88, 0x5c, 0x2a, 0x19, 0x05, 0x15,
    0x82, 0x00, 0x80, 0xb0, 0x70, 0x3c, 0x03, 0x12, 0x06, 0x00, 0x51, 0x80, 0xe5, 0x78, 0x04, 0x00, 0x27, 0x09,
    0x04, 0xc1, 0x80, 0x50, 0x00, 0x3e, 0x43, 0x23, 0x92, 0x84, 0x24, 0x52, 0x40, 0x7c, 0xaa, 0x51, 0x2d, 0x95,
    0xca, 0x66, 0x32, 0xd0, 0x94, 0x18, 0x18, 0x04, 0x00, 0x04, 0x02, 0x13, 0x50, 0x0c, 0xde, 0x73, 0x3b, 0x9b,
    0x4e, 0x02, 0x00};

static const t_u8 rg_table_CA[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x41, 0x20, 0x20, 0x00, 0x00, 0x06, 0x02, 0xb2, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x41, 0x20, 0x20, 0x03, 0x0a, 0x00, 0x00, 0x0c, 0x01,
    0x02, 0x00, 0xf0, 0x05, 0x60, 0x0c, 0x24, 0x0b, 0x00, 0x00, 0xc2, 0x00, 0x10, 0x90, 0x20, 0x22, 0x01, 0x85,
    0xc2, 0x61, 0x70, 0xd8, 0x7c, 0x46, 0x15, 0x08, 0x01, 0x83, 0xe2, 0x00, 0x98, 0xd4, 0x26, 0x34, 0x10, 0x8e,
    0x00, 0x63, 0xd1, 0xb8, 0xe8, 0x14, 0x1c, 0x02, 0x8f, 0x80, 0x41, 0xe0, 0x30, 0x00, 0x1e, 0x4f, 0x29, 0x95,
    0xcb, 0x65, 0xf1, 0x09, 0x54, 0xb0, 0x0a, 0x08, 0x02, 0x02, 0xc1, 0xd1, 0xa9, 0xc0, 0x30, 0x02, 0x8c, 0x07,
    0x2b, 0xe4, 0x42, 0x70, 0x88, 0x1c, 0x20, 0x02, 0x86, 0xc2, 0xc1, 0xd1, 0x00, 0x14, 0x3c, 0x24, 0x02, 0x00,
    0x03, 0xe8, 0xb4, 0x7a, 0x48, 0x06, 0x97, 0x47, 0xa7, 0x54, 0x01, 0xe1, 0x00, 0x95, 0x5c, 0x0b, 0x51, 0x08,
    0x01, 0xc1, 0xe0, 0x29, 0x05, 0x7a, 0xc1, 0x62, 0xb2, 0x02, 0x6c, 0xd5, 0xbb, 0x45, 0x96, 0x21, 0x5f, 0x07,
    0xc9, 0xc2, 0x00, 0x49, 0x38, 0x36, 0xc8, 0x06, 0xbb, 0x00, 0x22, 0x00, 0x40, 0x00, 0x42, 0xe5, 0x74, 0x01,
    0x5d, 0x82, 0x17, 0x8a, 0x85, 0xee, 0xfb, 0x7f, 0xba, 0xdd, 0xef, 0x38, 0x60, 0x80};
#else

static wifi_txpwrlimit_t tx_pwrlimit_2g_cfg = {
    .subband           = (wifi_SubBand_t)0x00,
    .num_chans         = 14,
    .txpwrlimit_config = {
        [0] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 1,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [1] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 2,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [2] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 3,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [3] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 4,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [4] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 5,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [5] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 6,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [6] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 7,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [7] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 8,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [8] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 9,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [9] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 10,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [10] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 11,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [11] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 12,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [12] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 13,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [13] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 14,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 0}, {8, 0}, {9, 0}},
            },
        [14] = {0},
        [15] = {0},
        [16] = {0},
        [17] = {0},
        [18] = {0},
        [19] = {0},
        [20] = {0},
        [21] = {0},
        [22] = {0},
        [23] = {0},
        [24] = {0},
        [25] = {0},
        [26] = {0},
        [27] = {0},
        [28] = {0},
        [29] = {0},
        [30] = {0},
        [31] = {0},
        [32] = {0},
        [33] = {0},
        [34] = {0},
        [35] = {0},
        [36] = {0},
        [37] = {0},
        [38] = {0},
        [39] = {0},
    }};

#if CONFIG_5GHz_SUPPORT
static wifi_txpwrlimit_t tx_pwrlimit_5g_cfg = {
    .subband           = (wifi_SubBand_t)0x00,
    .num_chans         = 25,
    .txpwrlimit_config = {
        [0] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 36,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [1] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 40,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [2] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 44,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [3] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 48,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [4] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 52,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [5] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 56,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [6] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 60,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [7] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 64,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [8] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 100,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [9] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 104,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [10] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 108,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [11] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 112,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [12] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 116,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [13] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 120,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [14] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 124,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [15] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 128,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [16] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 132,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [17] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 136,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [18] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 140,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [19] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 144,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [20] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 149,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [21] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 153,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [22] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 157,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [23] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 161,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [24] =
            {
                .num_mod_grps = 9,
                .chan_desc =
                    {
                        .start_freq = 5000,
                        .chan_width = 20,
                        .chan_num   = 165,
                    },
                .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {0, 0}},
            },
        [25] = {0},
        [26] = {0},
        [27] = {0},
        [28] = {0},
        [29] = {0},
        [30] = {0},
        [31] = {0},
        [32] = {0},
        [33] = {0},
        [34] = {0},
        [35] = {0},
        [36] = {0},
        [37] = {0},
        [38] = {0},
        [39] = {0},
    }};
#endif /* CONFIG_5GHz_SUPPORT */
#endif

#endif /* _WLAN_TXPWRLIMIT_CFG_WW_H_ */
