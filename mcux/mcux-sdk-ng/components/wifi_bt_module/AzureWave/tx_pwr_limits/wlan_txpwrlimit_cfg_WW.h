/** @file wlan_txpwrlimit_cfg_WW.h
 *
 *  @brief  This file provides WLAN World Wide Safe Mode Tx Power Limits.
 *
 *  Copyright 2008-2021 NXP
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

static wlan_chanlist_t chanlist_2g_cfg = {13,
                                          {[0] =
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
                                           [53] = {0}}};

#if CONFIG_5GHz_SUPPORT
static wlan_chanlist_t chanlist_5g_cfg = {25,
                                          {[0] =
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
                                           [53] = {0}}};
#endif

#if CONFIG_COMPRESS_TX_PWTBL

/*
 *  NOTE: The values here are taken from the Murata 1XK M2 module and are placeholders.
 *  https://github.com/murata-wireless/nxp-linux-calibration/tree/master/murata/files/1XK
 */

static const t_u8 rg_table_WW[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x57, 0x57, 0x20, 0x00, 0x00, 0x00, 0x06, 0x02, 0x46, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x57, 0x20, 0x00, 0x43, 0x03, 0x00, 0x00, 0x08, 0x05,
    0x03, 0x00, 0x80, 0x83, 0x60, 0x02, 0x06, 0x0a, 0x83, 0x40, 0x21, 0x20, 0x40, 0x58, 0x3c, 0x10, 0x04, 0x06,
    0x00, 0x51, 0x80, 0xe0, 0x58, 0x04, 0x00, 0x27, 0x04, 0x06, 0x00, 0x00, 0xe0, 0x40, 0x66, 0x37, 0x1d, 0x8f,
    0xc7, 0xa3, 0x92, 0x29, 0x04, 0x72, 0x35, 0x0e, 0x93, 0xc6, 0x40, 0x10, 0xe0, 0x08};

static const t_u8 rg_table_JP[] = {
    0x01, 0x00, 0x49, 0x02, 0x01, 0x00, 0x01, 0xee, 0x01, 0x06, 0x00, 0x4a, 0x50, 0x20, 0x40, 0x00, 0x03, 0x06,
    0x02, 0x50, 0x00, 0x88, 0x88, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x50, 0x20, 0x40, 0xe3,
    0x03, 0x00, 0x00, 0x0c, 0x06, 0xab, 0x00, 0x20, 0xf0, 0x68, 0x00, 0x02, 0x10, 0x82, 0xc1, 0xe1, 0x30, 0x88,
    0x30, 0x3a, 0x13, 0x0e, 0x86, 0xc1, 0x45, 0x60, 0x80, 0x20, 0x2c, 0x1c, 0x0f, 0x00, 0xab, 0x00, 0xa8, 0xc0,
    0x72, 0xbc, 0x02, 0x00, 0x13, 0x83, 0x82, 0x60, 0x00, 0xa4, 0x8a, 0x49, 0x26, 0x0a, 0x03, 0xe4, 0x72, 0x99,
    0x5c, 0xaa, 0x4e, 0x12, 0x00, 0x05, 0x41, 0xd3, 0x09, 0x94, 0xd0};

static const t_u8 rg_table_US[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x55, 0x53, 0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0x58, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x53, 0x20, 0x10, 0x63, 0x04, 0x00, 0x00, 0x0c, 0x05,
    0xab, 0x00, 0x61, 0x10, 0x58, 0x00, 0x06, 0x10, 0x05, 0x03, 0xc0, 0x30, 0x68, 0x44, 0x2a, 0x19, 0x09, 0x85,
    0x80, 0xc1, 0xd0, 0x58, 0x94, 0x52, 0x26, 0x00, 0x16, 0x82, 0x00, 0x80, 0xb0, 0x7c, 0x68, 0x18, 0x01, 0x46,
    0x44, 0xe1, 0x62, 0x70, 0x70, 0x60, 0x00, 0x0e, 0x07, 0x06, 0x64, 0xf2, 0x99, 0x58, 0x04, 0x1b, 0x26, 0x07,
    0x03, 0x65, 0x53, 0x19, 0x9c, 0xbc, 0x00, 0x0f, 0x9b, 0x4e, 0x24, 0xd3, 0x80, 0x08};

static const t_u8 rg_table_EU[] = {
    0x01, 0x00, 0x49, 0x02, 0x01, 0x00, 0x01, 0xee, 0x01, 0x06, 0x00, 0x45, 0x55, 0x20, 0x30, 0x00, 0x02, 0x06,
    0x02, 0x51, 0x00, 0x88, 0x88, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x55, 0x20, 0x30, 0xf3,
    0x03, 0x00, 0x00, 0x0c, 0x06, 0xab, 0x00, 0x21, 0x00, 0x68, 0x00, 0x02, 0x0f, 0x82, 0xc1, 0xe1, 0x30, 0x88,
    0x30, 0x3a, 0x13, 0x0e, 0x86, 0xc1, 0x45, 0x60, 0x80, 0x20, 0x2c, 0x1c, 0x0f, 0x00, 0xab, 0x00, 0xa8, 0xc0,
    0x72, 0xbc, 0x02, 0x00, 0x13, 0x84, 0x02, 0x60, 0x00, 0xa4, 0x8a, 0x49, 0x26, 0x0a, 0x03, 0xe4, 0x72, 0x99,
    0x5c, 0xaa, 0x48, 0x0e, 0x09, 0x00, 0x02, 0xb3, 0x09, 0x94, 0xd0, 0x2a};

static const t_u8 rg_table_CA[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x41, 0x20, 0x20, 0x00, 0x01, 0x06, 0x02, 0x58, 0x00, 0x88, 0x88,
    0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x41, 0x20, 0x20, 0x63, 0x04, 0x00, 0x00, 0x0c, 0x05,
    0xab, 0x00, 0x61, 0x10, 0x58, 0x00, 0x06, 0x10, 0x05, 0x03, 0xc0, 0x30, 0x68, 0x44, 0x2a, 0x19, 0x09, 0x85,
    0x80, 0xc1, 0xd0, 0x58, 0x94, 0x52, 0x26, 0x00, 0x16, 0x82, 0x00, 0x80, 0xb0, 0x7c, 0x68, 0x18, 0x01, 0x46,
    0x44, 0xe1, 0x62, 0x70, 0x70, 0x60, 0x00, 0x0e, 0x07, 0x06, 0x64, 0xf2, 0x99, 0x58, 0x04, 0x1b, 0x26, 0x07,
    0x03, 0x65, 0x53, 0x19, 0x9c, 0xbc, 0x00, 0x0f, 0x9b, 0x4e, 0x24, 0xd3, 0x80, 0x08};

#else
#ifndef CONFIG_11AC
static wifi_txpwrlimit_t tx_pwrlimit_2g_cfg =
    {
        .subband   = (wifi_SubBand_t)0x00,
        .num_chans = 14,
        .txpwrlimit_config[0] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 1,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[1] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 2,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[2] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 3,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[3] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 4,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[4] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 5,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[5] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 6,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[6] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 7,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[7] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 8,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[8] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 9,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[9] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 10,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[10] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 11,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[11] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 12,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[12] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 13,
                    },
                .txpwrlimit_entry = {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
            },
        .txpwrlimit_config[13] =
            {
                .num_mod_grps = 10,
                .chan_desc =
                    {
                        .start_freq = 2414,
                        .chan_width = 20,
                        .chan_num   = 14,
                    },
                .txpwrlimit_entry = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}},
            },
};

#if CONFIG_5GHz_SUPPORT
static wifi_txpwrlimit_t
    tx_pwrlimit_5g_cfg =
        {
            .subband   = (wifi_SubBand_t)0x00,
            .num_chans = 39,

            .txpwrlimit_config[0] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 36,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[1] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 40,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[2] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 44,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[3] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 48,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[4] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 52,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[5] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 56,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[6] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 60,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[7] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 64,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[8] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 100,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[9] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 104,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[10] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 108,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[11] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 112,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[12] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 116,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[13] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 120,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[14] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 124,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[15] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 128,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[16] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 132,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[17] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 136,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[18] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 140,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[19] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 144,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[20] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 149,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[21] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 153,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[22] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 157,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[23] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 161,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[24] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 165,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[25] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 183,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[26] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 184,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[27] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 185,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[28] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 187,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[29] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 188,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[30] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 189,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[31] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 192,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[32] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 196,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[33] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 7,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[34] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 8,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[35] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 11,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[36] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 12,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[37] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 16,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
            .txpwrlimit_config[38] =
                {
                    .num_mod_grps = 9,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 34,
                        },
                    .txpwrlimit_entry = {{1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}},
                },
};
#endif /* CONFIG_5GHz_SUPPORT */
#else
static wifi_txpwrlimit_t tx_pwrlimit_2g_cfg =
    {
        .subband   = (wifi_SubBand_t)0x00,
        .num_chans = 14,
        .txpwrlimit_config[0] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 1,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[1] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 2,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[2] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 3,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[3] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 4,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[4] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 5,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[5] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 6,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[6] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 7,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[7] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 8,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[8] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 9,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[9] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 10,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[10] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 11,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[11] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 12,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[12] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2407,
                        .chan_width = 20,
                        .chan_num   = 13,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
        .txpwrlimit_config[13] =
            {
                .num_mod_grps = 12,
                .chan_desc =
                    {
                        .start_freq = 2414,
                        .chan_width = 20,
                        .chan_num   = 14,
                    },
                .txpwrlimit_entry =
                    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}},
            },
};

#if CONFIG_5GHz_SUPPORT
static wifi_txpwrlimit_t
    tx_pwrlimit_5g_cfg =
        {
            .subband   = (wifi_SubBand_t)0x00,
            .num_chans = 39,

            .txpwrlimit_config[0] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 36,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[1] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 40,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[2] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 44,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[3] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 48,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[4] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 52,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[5] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 56,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[6] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 60,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[7] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 64,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[8] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 100,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[9] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 104,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[10] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 108,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[11] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 112,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[12] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 116,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[13] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 120,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[14] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 124,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[15] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 128,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[16] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 132,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[17] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 136,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[18] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 140,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[19] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 144,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[20] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 149,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[21] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 153,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[22] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 157,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[23] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 161,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[24] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 165,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[25] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 183,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[26] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 184,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[27] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 185,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[28] =
                {
                    .num_mod_grps     = 16,
                    .chan_desc        = {.start_freq = 5000, .chan_width = 20, .chan_num = 187},
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[29] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 188,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[30] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 189,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[31] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 192,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[32] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 196,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[33] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 7,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[34] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 8,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[35] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 11,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[36] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 12,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[37] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 16,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
            .txpwrlimit_config[38] =
                {
                    .num_mod_grps = 16,
                    .chan_desc =
                        {
                            .start_freq = 5000,
                            .chan_width = 20,
                            .chan_num   = 34,
                        },
                    .txpwrlimit_entry = {{0, 0},
                                         {1, 8},
                                         {2, 8},
                                         {3, 8},
                                         {4, 8},
                                         {5, 8},
                                         {6, 8},
                                         {7, 8},
                                         {8, 8},
                                         {9, 8},
                                         {10, 8},
                                         {11, 8},
                                         {12, 8},
                                         {13, 8},
                                         {14, 8},
                                         {15, 8}},
                },
};
#endif /* CONFIG_5GHz_SUPPORT */
#endif /* CONFIG_11AC */

#if CONFIG_11AX

#define MAX_2G_RU_PWR_CHANNELS 26
#define MAX_5G_RU_PWR_CHANNELS 69

static uint8_t rutxpowerlimit_cfg_set[] = {
    0x6d, 0x02, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0xfa,
    0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00, 0x03,
    0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c,
    0xfa, 0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00,
    0x03, 0x06, 0x09, 0x0c, 0xfa, 0xfd, 0x00, 0x03, 0x06, 0x09, 0x0c, 0x14, 0x14, 0x14, 0x14, 0x14};
#endif /* CONFIG_11AX */
#endif
#endif /* _WLAN_TXPWRLIMIT_CFG_WW_H_ */
