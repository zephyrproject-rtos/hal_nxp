/** @file wlan_txpwrlimit_cfg_murata_2LL.h
 *
 *  @brief  This file provides Murata 2LL WLAN Mode Tx Power Limits.
 *
 *  Copyright 2024-2025 NXP
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

#define WLAN_REGION_CODE "WW"

static wlan_chanlist_t chanlist_2g_cfg = {
    .num_chans = 13,
    .chan_info[0] =
        {
            .chan_num                     = 1,
            .chan_freq                    = 2412,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[1] =
        {
            .chan_num                     = 2,
            .chan_freq                    = 2417,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[2] =
        {
            .chan_num                     = 3,
            .chan_freq                    = 2422,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[3] =
        {
            .chan_num                     = 4,
            .chan_freq                    = 2427,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[4] =
        {
            .chan_num                     = 5,
            .chan_freq                    = 2432,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[5] =
        {
            .chan_num                     = 6,
            .chan_freq                    = 2437,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[6] =
        {
            .chan_num                     = 7,
            .chan_freq                    = 2442,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[7] =
        {
            .chan_num                     = 8,
            .chan_freq                    = 2447,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[8] =
        {
            .chan_num                     = 9,
            .chan_freq                    = 2452,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[9] =
        {
            .chan_num                     = 10,
            .chan_freq                    = 2457,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[10] =
        {
            .chan_num                     = 11,
            .chan_freq                    = 2462,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[11] =
        {
            .chan_num                     = 12,
            .chan_freq                    = 2467,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[12] =
        {
            .chan_num                     = 13,
            .chan_freq                    = 2472,
            .passive_scan_or_radar_detect = true,
        },
};

#if CONFIG_5GHz_SUPPORT
static wlan_chanlist_t chanlist_5g_cfg = {
    .num_chans = 25,

    .chan_info[0] =
        {
            .chan_num                     = 36,
            .chan_freq                    = 5180,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[1] =
        {
            .chan_num                     = 40,
            .chan_freq                    = 5200,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[2] =
        {
            .chan_num                     = 44,
            .chan_freq                    = 5220,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[3] =
        {
            .chan_num                     = 48,
            .chan_freq                    = 5240,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[4] =
        {
            .chan_num                     = 52,
            .chan_freq                    = 5260,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[5] =
        {
            .chan_num                     = 56,
            .chan_freq                    = 5280,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[6] =
        {
            .chan_num                     = 60,
            .chan_freq                    = 5300,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[7] =
        {
            .chan_num                     = 64,
            .chan_freq                    = 5320,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[8] =
        {
            .chan_num                     = 100,
            .chan_freq                    = 5500,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[9] =
        {
            .chan_num                     = 104,
            .chan_freq                    = 5520,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[10] =
        {
            .chan_num                     = 108,
            .chan_freq                    = 5540,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[11] =
        {
            .chan_num                     = 112,
            .chan_freq                    = 5560,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[12] =
        {
            .chan_num                     = 116,
            .chan_freq                    = 5580,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[13] =
        {
            .chan_num                     = 120,
            .chan_freq                    = 5600,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[14] =
        {
            .chan_num                     = 124,
            .chan_freq                    = 5620,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[15] =
        {
            .chan_num                     = 128,
            .chan_freq                    = 5640,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[16] =
        {
            .chan_num                     = 132,
            .chan_freq                    = 5660,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[17] =
        {
            .chan_num                     = 136,
            .chan_freq                    = 5680,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[18] =
        {
            .chan_num                     = 140,
            .chan_freq                    = 5700,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[19] =
        {
            .chan_num                     = 144,
            .chan_freq                    = 5720,
            .passive_scan_or_radar_detect = true,
        },
    .chan_info[20] =
        {
            .chan_num                     = 149,
            .chan_freq                    = 5745,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[21] =
        {
            .chan_num                     = 153,
            .chan_freq                    = 5765,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[22] =
        {
            .chan_num                     = 157,
            .chan_freq                    = 5785,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[23] =
        {
            .chan_num                     = 161,
            .chan_freq                    = 5805,
            .passive_scan_or_radar_detect = false,
        },
    .chan_info[24] =
        {
            .chan_num                     = 165,
            .chan_freq                    = 5825,
            .passive_scan_or_radar_detect = false,
        },
};
#endif /* CONFIG_5GHz_SUPPORT */

#if CONFIG_COMPRESS_TX_PWTBL

static const t_u8 rg_table_WW_qfn[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x57, 0x57,
0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x7d, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x57, 0x57, 0x00, 0x00, 0xb3, 0x06, 0x00, 0x02, 0x0c, 0x13, 0x02, 0xc0, 0x20, 0x80,
0x08, 0x0c, 0x02, 0x00, 0x00, 0x83, 0x01, 0x50, 0x28, 0x24, 0x1a, 0x11, 0x0a, 0x86, 0x41, 0x60,
0xf0, 0x90, 0x58, 0x1c, 0x02, 0x02, 0x89, 0x83, 0x22, 0xb1, 0x78, 0xcc, 0x6e, 0x30, 0x00, 0x15,
0xc6, 0xa2, 0xd1, 0xf2, 0x3c, 0x40, 0x03, 0x23, 0x83, 0xc8, 0x40, 0x80, 0xf0, 0x78, 0x30, 0x10,
0x8c, 0x07, 0x03, 0xe0, 0xe2, 0xa0, 0x50, 0x10, 0x0e, 0x04, 0x07, 0x04, 0xc0, 0x00, 0xe0, 0x70,
0x06, 0x6b, 0x37, 0x9c, 0xce, 0xe7, 0xb3, 0xf9, 0xc4, 0xea, 0x79, 0x3e, 0x9b, 0x51, 0x68, 0x54,
0x8a, 0x05, 0x1a, 0x87, 0x49, 0xa0, 0xd1, 0xc0, 0x07, 0xea, 0x25, 0x46, 0x7a, 0x00, 0x34, 0xd6,
0x2a, 0xb4, 0xe8, 0x39, 0xf8};

static const t_u8 rg_table_WW_csp[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x57, 0x57,
0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x7c, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x57, 0x57, 0x00, 0x00, 0xa3, 0x06, 0x00, 0x02, 0x0c, 0x13, 0x02, 0xc0, 0x20, 0x80,
0x08, 0x0c, 0x02, 0x00, 0x00, 0x83, 0x01, 0x50, 0x28, 0x24, 0x1a, 0x11, 0x0a, 0x86, 0x41, 0x60,
0xf0, 0x90, 0x58, 0x1e, 0x25, 0x0f, 0x8a, 0xc5, 0xe2, 0x91, 0x68, 0x70, 0xac, 0x18, 0x0b, 0x03,
0x45, 0xc8, 0xf1, 0x08, 0x18, 0x04, 0x05, 0x07, 0x8f, 0x01, 0x01, 0xe0, 0xf0, 0x60, 0x21, 0x18,
0x0e, 0x07, 0xc1, 0xc5, 0x40, 0xa0, 0x20, 0x1c, 0x08, 0x0e, 0x09, 0x80, 0x01, 0xc0, 0xe0, 0x0c,
0xd2, 0x6d, 0x38, 0x9d, 0x4f, 0x27, 0xd3, 0x79, 0xcc, 0xee, 0x7b, 0x35, 0xa2, 0x50, 0x68, 0xf3,
0xfa, 0x2d, 0x0a, 0x91, 0x40, 0xa3, 0x00, 0x0f, 0xd4, 0x3a, 0x84, 0xf0, 0x00, 0x69, 0xab, 0xd5,
0x29, 0xb0, 0x73, 0xf0};

static const t_u8 rg_table_US_qfn[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x55, 0x53,
0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0x7a, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x55, 0x53, 0x20, 0x10, 0x83, 0x06, 0x00, 0x02, 0x0c, 0x05, 0xab, 0x00, 0x61, 0x60,
0x58, 0x00, 0x06, 0x14, 0x00, 0x85, 0x40, 0x41, 0x60, 0x34, 0x20, 0x26, 0x01, 0x83, 0x05, 0x01,
0x50, 0xf8, 0x30, 0x4e, 0x0b, 0x07, 0x89, 0xc4, 0x23, 0x11, 0x40, 0x1c, 0x58, 0x00, 0x2d, 0x09,
0x41, 0x49, 0x21, 0x18, 0x28, 0xb4, 0x18, 0x04, 0x07, 0x83, 0xc1, 0x80, 0x84, 0x60, 0x38, 0x1f,
0x10, 0x15, 0x05, 0x03, 0x60, 0x00, 0x70, 0x50, 0x39, 0x34, 0x0a, 0x02, 0x64, 0x21, 0x30, 0x44,
0xd0, 0x24, 0x01, 0x99, 0x4e, 0x26, 0xf3, 0x50, 0x0c, 0xf0, 0x24, 0x13, 0x9f, 0x44, 0x0f, 0xc1,
0x20, 0x40, 0x46, 0x90, 0x0e, 0x08, 0xc4, 0x0d, 0x20, 0x03, 0x48, 0x44, 0x10, 0x10, 0xa7, 0x84,
0x29, 0x40};

static const t_u8 rg_table_US_csp[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x55, 0x53,
0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0x94, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x55, 0x53, 0x20, 0x10, 0x23, 0x08, 0x00, 0x02, 0x0c, 0x05, 0xab, 0x00, 0x61, 0x00,
0x10, 0x44, 0x0e, 0x0f, 0x01, 0x00, 0x00, 0x60, 0xb0, 0x08, 0x38, 0x02, 0x10, 0x04, 0x43, 0x21,
0x50, 0xc8, 0x74, 0x42, 0x25, 0x0b, 0x86, 0x80, 0x41, 0xf1, 0x10, 0x0c, 0x28, 0x10, 0x01, 0x06,
0xc6, 0x41, 0xe0, 0x50, 0x70, 0x08, 0x15, 0x1d, 0x01, 0xc7, 0xe4, 0x30, 0xe9, 0x1c, 0x96, 0x4f,
0x1e, 0x90, 0x43, 0x41, 0x12, 0xf1, 0x6c, 0xa8, 0x13, 0x12, 0x24, 0xcd, 0xa6, 0x80, 0xc0, 0x20,
0x3c, 0x1e, 0x0c, 0x04, 0x23, 0x01, 0xc0, 0xf8, 0xe8, 0xa8, 0x20, 0x1b, 0x00, 0x03, 0x82, 0x01,
0xca, 0x48, 0x42, 0x35, 0x48, 0xa1, 0xc8, 0x80, 0xd2, 0xc0, 0x54, 0x86, 0x37, 0x49, 0xa2, 0x4b,
0x2a, 0x71, 0xaa, 0xac, 0x68, 0x11, 0x58, 0x86, 0x84, 0xa5, 0x75, 0xf0, 0x74, 0x38, 0x00, 0x7e,
0x06, 0xd4, 0x24, 0x20, 0x03, 0x4d, 0xb2, 0xd3, 0x49, 0xb5, 0x9f, 0x80};

static const t_u8 rg_table_EU_qfn[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x45, 0x55,
0x20, 0x30, 0x00, 0x02, 0x06, 0x02, 0x74, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x45, 0x55, 0x20, 0x30, 0x23, 0x06, 0x00, 0x02, 0x0c, 0x06, 0xab, 0x00, 0x21, 0x40,
0x68, 0x02, 0x07, 0x05, 0x83, 0xc1, 0x82, 0x70, 0x88, 0x24, 0x1a, 0x1a, 0x01, 0x85, 0x80, 0x05,
0x61, 0x28, 0x29, 0x1c, 0x23, 0x05, 0x15, 0x83, 0x00, 0x80, 0xf0, 0x78, 0x30, 0x10, 0x8c, 0x07,
0x03, 0xc0, 0x20, 0x01, 0x50, 0x50, 0x26, 0x0e, 0x04, 0x00, 0x01, 0xc1, 0x40, 0xa4, 0xa2, 0x54,
0x14, 0x04, 0x84, 0x81, 0x72, 0xe0, 0x70, 0x4a, 0x07, 0x27, 0x94, 0xca, 0xe5, 0xb3, 0x90, 0xa4,
0x40, 0x11, 0x32, 0x9a, 0x4d, 0x80, 0x07, 0xe0, 0x90, 0x20, 0x23, 0x33, 0x9c, 0x84, 0x64, 0x66,
0x90, 0x01, 0xa4, 0x22, 0x08, 0x08, 0x52, 0x25, 0x41, 0x09, 0x19, 0xf8};

static const t_u8 rg_table_EU_csp[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x45, 0x55,
0x20, 0x30, 0x00, 0x02, 0x06, 0x02, 0x5d, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x45, 0x55, 0x20, 0x30, 0xb3, 0x04, 0x00, 0x02, 0x0c, 0x06, 0xab, 0x00, 0x30, 0x00,
0x00, 0x04, 0x16, 0x0d, 0x82, 0xc1, 0xe1, 0x30, 0x88, 0x34, 0x32, 0x15, 0x0d, 0x00, 0x0a, 0xe1,
0x44, 0x78, 0x50, 0xac, 0x18, 0x04, 0x07, 0x83, 0xc1, 0x80, 0x55, 0x60, 0x0d, 0x18, 0x0e, 0x57,
0x80, 0x40, 0x02, 0xa0, 0x70, 0x4c, 0x0c, 0x05, 0x00, 0x04, 0xa4, 0xb2, 0x79, 0x4c, 0xae, 0x51,
0x2a, 0x93, 0x4b, 0xe5, 0xd2, 0xd9, 0x88, 0x00, 0x91, 0x36, 0x06, 0xcd, 0x4e, 0x40, 0x03, 0x94,
0xe6, 0x59, 0x37, 0x24, 0x00};

static const t_u8 rg_table_CN_qfn[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x4e,
0x20, 0x50, 0x00, 0x02, 0x06, 0x02, 0xaa, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x43, 0x4e, 0x20, 0x50, 0x83, 0x09, 0x00, 0x02, 0x0c, 0x06, 0xab, 0x00, 0x21, 0x40,
0x68, 0x00, 0x02, 0x11, 0x00, 0x84, 0xc1, 0x01, 0x00, 0x08, 0x2c, 0x02, 0x08, 0x00, 0x80, 0xc0,
0x30, 0x68, 0x44, 0x2a, 0x19, 0x0e, 0x88, 0x44, 0xa2, 0x90, 0x98, 0x5c, 0x36, 0x1f, 0x11, 0x89,
0xc1, 0xe3, 0x90, 0xc0, 0x60, 0x04, 0x0e, 0x01, 0x01, 0x48, 0x62, 0xb1, 0xd9, 0x2c, 0x9e, 0x53,
0x1b, 0x8b, 0x00, 0x65, 0xb2, 0x88, 0x98, 0xae, 0x10, 0x12, 0x96, 0x49, 0xa6, 0x80, 0x02, 0x38,
0x44, 0x12, 0x0e, 0x8f, 0x4b, 0xa6, 0xa0, 0xc0, 0x20, 0x3c, 0x1e, 0x0c, 0x04, 0x23, 0x01, 0xc0,
0xf8, 0x98, 0xa8, 0x28, 0x13, 0x09, 0xc0, 0xc0, 0x61, 0x2a, 0x90, 0x00, 0x1c, 0x14, 0xa7, 0xd4,
0xaa, 0x81, 0x40, 0x1d, 0x58, 0x28, 0x09, 0x09, 0x02, 0xc2, 0x60, 0x4a, 0xa0, 0x4e, 0xba, 0x0e,
0xad, 0xd4, 0x2b, 0x55, 0x5a, 0xbd, 0x66, 0xb9, 0x5b, 0xb3, 0x85, 0x23, 0x81, 0x20, 0x9d, 0x5a,
0xa8, 0x00, 0x3f, 0x4e, 0x02, 0x37, 0x50, 0x74, 0x20, 0x00, 0x69, 0xbf, 0x84, 0x61, 0x77, 0xc8,
0x65, 0xe0};

static const t_u8 rg_table_CN_csp[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x4e,
0x20, 0x50, 0x00, 0x02, 0x06, 0x02, 0xa8, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x43, 0x4e, 0x20, 0x50, 0x63, 0x09, 0x00, 0x02, 0x0c, 0x06, 0xab, 0x00, 0x21, 0x20,
0x60, 0x38, 0x02, 0x00, 0x00, 0x84, 0x41, 0x20, 0xf0, 0x08, 0x2c, 0x02, 0x08, 0x00, 0x80, 0xe0,
0xf0, 0x98, 0x5c, 0x36, 0x1f, 0x11, 0x89, 0xc2, 0xa1, 0x90, 0xe8, 0x84, 0x4a, 0x11, 0x1a, 0x00,
0x83, 0x00, 0x20, 0x78, 0xc4, 0x7e, 0x2b, 0x22, 0x92, 0x47, 0xa2, 0x90, 0xc9, 0x44, 0x94, 0x56,
0x10, 0x02, 0x84, 0x40, 0x92, 0xc0, 0x08, 0x1a, 0x4a, 0x47, 0x08, 0x02, 0x60, 0xd1, 0xc0, 0x08,
0x0a, 0x0e, 0x2b, 0x06, 0x4c, 0xc1, 0xe0, 0xc0, 0x42, 0x30, 0x1d, 0x0c, 0x00, 0x0a, 0x82, 0x81,
0x70, 0x98, 0x04, 0x28, 0x03, 0x00, 0x03, 0x82, 0x80, 0x90, 0xa8, 0x2c, 0x28, 0x04, 0xa6, 0xd3,
0xea, 0x21, 0x5a, 0x70, 0x20, 0x26, 0x13, 0xa8, 0xd6, 0x41, 0x15, 0x5a, 0xbd, 0x66, 0xa0, 0x0e,
0xae, 0x05, 0x2c, 0x75, 0x6a, 0xc5, 0x3a, 0xcf, 0x5c, 0x09, 0x57, 0x81, 0x77, 0x1b, 0x0c, 0x1c,
0xfc, 0x12, 0x0d, 0xd4, 0x42, 0x50, 0x73, 0x48, 0x00, 0xd2, 0x11, 0xbc, 0x83, 0x82, 0x37, 0x60};

static const t_u8 rg_table_JP_qfn[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x4a, 0x50,
0x20, 0x40, 0x00, 0x03, 0x06, 0x02, 0x62, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x4a, 0x50, 0x20, 0x40, 0x03, 0x05, 0x00, 0x02, 0x0c, 0x14, 0x80, 0x00, 0x20, 0xc0,
0x6c, 0x0a, 0x09, 0x06, 0x82, 0xc0, 0xe1, 0x30, 0x71, 0x5c, 0x1c, 0x8f, 0x0c, 0x06, 0x01, 0x01,
0xe0, 0xf0, 0x60, 0x21, 0x18, 0x0e, 0x07, 0x80, 0x40, 0x02, 0xa0, 0x50, 0x10, 0x0e, 0x04, 0x07,
0x04, 0xc0, 0x00, 0xe0, 0x70, 0x06, 0x3b, 0x1f, 0x90, 0xc8, 0xe4, 0xb2, 0x79, 0x04, 0x8a, 0x49,
0x26, 0x8f, 0x4b, 0x65, 0x53, 0x09, 0x44, 0xba, 0x57, 0x31, 0x94, 0xcb, 0xc0, 0x07, 0xe9, 0x64,
0xe6, 0x4a, 0x00, 0x34, 0xd0, 0x27, 0xb3, 0x68, 0xd1, 0xf8};

static const t_u8 rg_table_JP_csp[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x4a, 0x50,
0x20, 0x40, 0x00, 0x03, 0x06, 0x02, 0x59, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x4a, 0x50, 0x20, 0x40, 0x73, 0x04, 0x00, 0x02, 0x0c, 0x07, 0x40, 0x42, 0x01, 0xc0,
0x78, 0xaa, 0x02, 0x00, 0x15, 0x03, 0x41, 0xc0, 0x02, 0x34, 0x2a, 0x10, 0x0c, 0x02, 0x03, 0xc1,
0xea, 0xc0, 0x42, 0x30, 0x1c, 0x0f, 0x00, 0xc2, 0x01, 0xa0, 0x80, 0x70, 0x2c, 0x00, 0x16, 0x07,
0x00, 0x63, 0x71, 0xd8, 0xfc, 0x86, 0x47, 0x1e, 0x90, 0x48, 0x82, 0x71, 0xf0, 0x68, 0x52, 0x59,
0x2e, 0x0b, 0x03, 0x63, 0x27, 0xe0, 0x6c, 0xae, 0x63, 0x19, 0x34, 0x80, 0x0d, 0x33, 0x59, 0x64,
0xcc};

static const t_u8 rg_table_CA_csp[] = {
0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x41,
0x20, 0x20, 0x00, 0x01, 0x06, 0x02, 0xaf, 0x00, 0x88, 0x88, 0x03, 0x01, 0x0b, 0x00, 0x00, 0x00,
0x00, 0x00, 0x43, 0x41, 0x20, 0x20, 0xd3, 0x09, 0x00, 0x02, 0x0c, 0x05, 0xab, 0x00, 0x61, 0x00,
0x10, 0x44, 0x0e, 0x0f, 0x01, 0x00, 0x00, 0x60, 0xb0, 0x08, 0x38, 0x02, 0x10, 0x04, 0x43, 0x21,
0x50, 0xc8, 0x74, 0x42, 0x25, 0x0b, 0x86, 0x80, 0x41, 0xf1, 0x10, 0x0c, 0x28, 0x10, 0x01, 0x06,
0xc6, 0x41, 0xe0, 0x50, 0x70, 0x08, 0x15, 0x1d, 0x01, 0xc7, 0xe4, 0x30, 0xe9, 0x1c, 0x96, 0x4f,
0x1e, 0x90, 0x43, 0x41, 0x12, 0xf1, 0x6c, 0xa8, 0x13, 0x2f, 0x24, 0xcd, 0xa6, 0x80, 0xc0, 0x20,
0x3c, 0x12, 0xaf, 0x01, 0x83, 0xc0, 0x60, 0xc0, 0x2c, 0x09, 0x18, 0x0e, 0x07, 0xc7, 0x45, 0x40,
0xd0, 0x20, 0x40, 0x13, 0x0a, 0x88, 0x00, 0x02, 0x21, 0x09, 0x05, 0x36, 0x9f, 0x03, 0x04, 0x54,
0xaa, 0x94, 0xc9, 0xf4, 0x2a, 0x37, 0x52, 0xa4, 0xd7, 0x00, 0x72, 0xc0, 0x2d, 0x78, 0x05, 0x21,
0x91, 0xd8, 0x2a, 0xb4, 0x2b, 0x25, 0x9a, 0xd1, 0x65, 0x08, 0xd8, 0x40, 0x80, 0xea, 0xbc, 0x96,
0x57, 0x70, 0x87, 0x00, 0x0f, 0xc0, 0xd0, 0x6c, 0x28, 0x1b, 0x59, 0x08, 0xc8, 0x40, 0x06, 0x9c,
0x1d, 0xf2, 0xfd, 0x80, 0xc1, 0x1f, 0x80};
#else
#ifndef CONFIG_11AX
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
#else
static wifi_txpwrlimit_t tx_pwrlimit_2g_cfg = {
    .subband   = (wifi_SubBand_t)0x00,
    .num_chans = 14,
    .txpwrlimit_config[0] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 1,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[1] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 2,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[2] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 3,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[3] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 4,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[4] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 5,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[5] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 6,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[6] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 7,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[7] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 8,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[8] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 9,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[9] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 10,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[10] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 11,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[11] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 12,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[12] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2407,
                    .chan_width = 20,
                    .chan_num   = 13,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[13] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 2414,
                    .chan_width = 20,
                    .chan_num   = 14,
                },
            .txpwrlimit_entry = {{0, 8},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
};

#if CONFIG_5GHz_SUPPORT
static wifi_txpwrlimit_t tx_pwrlimit_5g_cfg = {
    .subband   = (wifi_SubBand_t)0x00,
    .num_chans = 39,

    .txpwrlimit_config[0] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 36,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[1] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 40,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[2] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 44,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[3] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 48,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[4] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 52,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[5] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 56,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[6] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 60,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[7] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 64,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[8] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 100,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[9] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 104,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[10] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 108,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[11] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 112,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[12] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 116,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[13] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 120,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[14] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 124,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[15] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 128,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[16] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 132,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[17] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 136,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[18] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 140,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[19] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 144,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[20] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 149,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[21] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 153,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[22] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 157,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[23] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 161,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[24] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 165,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[25] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 183,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[26] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 184,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[27] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 185,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[28] =
        {
            .num_mod_grps     = 20,
            .chan_desc        = {.start_freq = 5000, .chan_width = 20, .chan_num = 187},
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[29] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 188,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[30] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 189,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[31] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 192,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[32] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 196,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[33] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 7,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[34] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 8,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[35] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 11,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[36] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 12,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[37] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 16,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
    .txpwrlimit_config[38] =
        {
            .num_mod_grps = 20,
            .chan_desc =
                {
                    .start_freq = 5000,
                    .chan_width = 20,
                    .chan_num   = 34,
                },
            .txpwrlimit_entry = {{0, 0},  {1, 8},  {2, 8},  {3, 8},  {4, 8},  {5, 8},  {6, 8},
                                 {7, 8},  {8, 8},  {9, 8},  {10, 8}, {11, 8}, {12, 8}, {13, 8},
                                 {14, 8}, {15, 8}, {16, 8}, {17, 8}, {18, 8}, {19, 8}},
        },
};
#endif /* CONFIG_5GHz_SUPPORT */
#endif /* CONFIG_11AX */
#endif /* CONFIG_COMPRESS_TX_PWTBL */

#if CONFIG_11AX
#if CONFIG_COMPRESS_RU_TX_PWTBL
const static uint8_t rutxpowerlimit_cfg_set_WW[] = {
0x6d, 0x02, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x04, 0x06, 0x09, 0x0c,
0x00, 0x00, 0x00, 0x04, 0x06, 0x09, 0x08, 0x00, 0x00, 0x00, 0xfd, 0xfe, 0x02, 0x04, 0x00, 0x00,
0x00, 0x06, 0x08, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x03, 0x05, 0x07, 0x07, 0x00, 0x00, 0x00, 0x03,
0x05, 0x07, 0x07, 0x00, 0x00, 0x00, 0x06, 0x09, 0x0b, 0x0e, 0x00, 0x00, 0x00, 0x06, 0x09, 0x0b,
0x0e, 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00,
0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x02, 0x03, 0x00, 0x88, 0x88, 0x00};

const static uint8_t rutxpowerlimit_cfg_set_US[] = {
0x6d, 0x02, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x0f, 0x12, 0x12, 0x12,
0x00, 0x00, 0x00, 0x12, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x10, 0x12, 0x11, 0x11, 0x00, 0x00,
0x00, 0x0d, 0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x0d, 0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x0d,
0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x0d, 0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x0d, 0x10, 0x11,
0x11, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x00,
0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x09, 0x0c, 0x0f, 0x11, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x02, 0x03, 0x00, 0x88, 0x88, 0x00};

const static uint8_t rutxpowerlimit_cfg_set_EU[] = {
0x6d, 0x02, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x0a, 0x0d, 0x10, 0x12,
0x00, 0x00, 0x00, 0x0a, 0x0d, 0x10, 0x12, 0x00, 0x00, 0x00, 0x0a, 0x0d, 0x10, 0x11, 0x00, 0x00,
0x00, 0x0e, 0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x0a, 0x0c, 0x10, 0x11, 0x00, 0x00, 0x00, 0x0a,
0x0c, 0x10, 0x11, 0x00, 0x00, 0x00, 0x0a, 0x0c, 0x10, 0x11, 0x00, 0x00, 0x00, 0x0a, 0x0c, 0x10,
0x11, 0x00, 0x00, 0x00, 0x0a, 0x0c, 0x10, 0x11, 0x00, 0x00, 0x00, 0x0a, 0x0c, 0x0e, 0x0e, 0x00,
0x00, 0x00, 0x0a, 0x0c, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x0a, 0x0c, 0x0e, 0x0e, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x02, 0x03, 0x00, 0x88, 0x88, 0x00};

const static uint8_t rutxpowerlimit_cfg_set_CN[] = {
0x6d, 0x02, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x05, 0x08, 0x0b, 0x0e,
0x00, 0x00, 0x00, 0x05, 0x08, 0x0b, 0x08, 0x00, 0x00, 0x00, 0xfd, 0xfe, 0x02, 0x04, 0x00, 0x00,
0x00, 0x06, 0x09, 0x0b, 0x0f, 0x00, 0x00, 0x00, 0x06, 0x09, 0x0b, 0x0f, 0x00, 0x00, 0x00, 0x06,
0x09, 0x0b, 0x0f, 0x00, 0x00, 0x00, 0x06, 0x09, 0x0b, 0x0f, 0x00, 0x00, 0x00, 0x06, 0x09, 0x0b,
0x0f, 0x00, 0x00, 0x00, 0x06, 0x09, 0x0b, 0x0f, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x00,
0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x02, 0x03, 0x00, 0x88, 0x88, 0x00};

const static uint8_t rutxpowerlimit_cfg_set_JP[] = {
0x6d, 0x02, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x04, 0x06, 0x09, 0x0c,
0x00, 0x00, 0x00, 0x04, 0x06, 0x09, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x06, 0x09, 0x0c, 0x00, 0x00,
0x00, 0x06, 0x08, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x03, 0x05, 0x07, 0x07, 0x00, 0x00, 0x00, 0x03,
0x05, 0x07, 0x07, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e,
0x0e, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00,
0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0e, 0x0e, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x02, 0x03, 0x00, 0x88, 0x88, 0x00};
#else
#define MAX_2G_RU_PWR_CHANNELS 26
#define MAX_5G_RU_PWR_CHANNELS 69

const static wlan_rutxpwrlimit_t rutxpowerlimit_2g_cfg_set = {
    .num_chans            = MAX_2G_RU_PWR_CHANNELS,
    .rupwrlimit_config[0] = {.start_freq = 2407, .width = 20, .chan_num = 1, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[1] = {.start_freq = 2407, .width = 20, .chan_num = 2, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[2] = {.start_freq = 2407, .width = 20, .chan_num = 3, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[3] = {.start_freq = 2407, .width = 20, .chan_num = 4, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[4] = {.start_freq = 2407, .width = 20, .chan_num = 5, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[5] = {.start_freq = 2407, .width = 20, .chan_num = 6, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[6] = {.start_freq = 2407, .width = 20, .chan_num = 7, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[7] = {.start_freq = 2407, .width = 20, .chan_num = 8, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[8] = {.start_freq = 2407, .width = 20, .chan_num = 9, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[9] = {.start_freq = 2407, .width = 20, .chan_num = 10, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[10] = {.start_freq = 2407, .width = 20, .chan_num = 11, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[11] = {.start_freq = 2407, .width = 20, .chan_num = 12, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[12] = {.start_freq = 2407, .width = 20, .chan_num = 13, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[13] = {.start_freq = 2407, .width = 40, .chan_num = 1, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[14] = {.start_freq = 2407, .width = 40, .chan_num = 2, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[15] = {.start_freq = 2407, .width = 40, .chan_num = 3, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[16] = {.start_freq = 2407, .width = 40, .chan_num = 4, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[17] = {.start_freq = 2407, .width = 40, .chan_num = 5, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[18] = {.start_freq = 2407, .width = 40, .chan_num = 6, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[19] = {.start_freq = 2407, .width = 40, .chan_num = 7, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[20] = {.start_freq = 2407, .width = 40, .chan_num = 8, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[21] = {.start_freq = 2407, .width = 40, .chan_num = 9, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[22] = {.start_freq = 2407, .width = 40, .chan_num = 10, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[23] = {.start_freq = 2407, .width = 40, .chan_num = 11, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[24] = {.start_freq = 2407, .width = 40, .chan_num = 12, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[25] = {.start_freq = 2407, .width = 40, .chan_num = 13, .ruPower = {-4, -1, 2, 5, 8, 0}},
};

#if CONFIG_5GHz_SUPPORT
const static wlan_rutxpwrlimit_t rutxpowerlimit_5g_cfg_set = {
    .num_chans            = MAX_5G_RU_PWR_CHANNELS,
    .rupwrlimit_config[0] = {.start_freq = 5000, .width = 20, .chan_num = 36, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[1] = {.start_freq = 5000, .width = 20, .chan_num = 40, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[2] = {.start_freq = 5000, .width = 20, .chan_num = 44, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[3] = {.start_freq = 5000, .width = 20, .chan_num = 48, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[4] = {.start_freq = 5000, .width = 20, .chan_num = 52, .ruPower = {-2, 1, 4, 7, 0, 0}},

    .rupwrlimit_config[5] = {.start_freq = 5000, .width = 20, .chan_num = 56, .ruPower = {-2, 1, 4, 7, 0, 0}},

    .rupwrlimit_config[6] = {.start_freq = 5000, .width = 20, .chan_num = 60, .ruPower = {-2, 1, 4, 7, 0, 0}},

    .rupwrlimit_config[7] = {.start_freq = 5000, .width = 20, .chan_num = 64, .ruPower = {-2, 1, 4, 7, 0, 0}},

    .rupwrlimit_config[8] = {.start_freq = 5000, .width = 20, .chan_num = 100, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[9] = {.start_freq = 5000, .width = 20, .chan_num = 104, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[10] = {.start_freq = 5000, .width = 20, .chan_num = 108, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[11] = {.start_freq = 5000, .width = 20, .chan_num = 112, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[12] = {.start_freq = 5000, .width = 20, .chan_num = 116, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[13] = {.start_freq = 5000, .width = 20, .chan_num = 120, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[14] = {.start_freq = 5000, .width = 20, .chan_num = 124, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[15] = {.start_freq = 5000, .width = 20, .chan_num = 128, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[16] = {.start_freq = 5000, .width = 20, .chan_num = 132, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[17] = {.start_freq = 5000, .width = 20, .chan_num = 136, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[18] = {.start_freq = 5000, .width = 20, .chan_num = 140, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[19] = {.start_freq = 5000, .width = 20, .chan_num = 144, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[20] = {.start_freq = 5000, .width = 20, .chan_num = 149, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[21] = {.start_freq = 5000, .width = 20, .chan_num = 153, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[22] = {.start_freq = 5000, .width = 20, .chan_num = 157, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[23] = {.start_freq = 5000, .width = 20, .chan_num = 161, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[24] = {.start_freq = 5000, .width = 20, .chan_num = 165, .ruPower = {-1, 2, 5, 8, 0, 0}},

    .rupwrlimit_config[25] = {.start_freq = 5000, .width = 40, .chan_num = 36, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[26] = {.start_freq = 5000, .width = 40, .chan_num = 40, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[27] = {.start_freq = 5000, .width = 40, .chan_num = 44, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[28] = {.start_freq = 5000, .width = 40, .chan_num = 48, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[29] = {.start_freq = 5000, .width = 40, .chan_num = 52, .ruPower = {-5, -2, 1, 4, 7, 0}},

    .rupwrlimit_config[30] = {.start_freq = 5000, .width = 40, .chan_num = 56, .ruPower = {-5, -2, 1, 4, 7, 0}},

    .rupwrlimit_config[31] = {.start_freq = 5000, .width = 40, .chan_num = 60, .ruPower = {-5, -2, 1, 4, 7, 0}},

    .rupwrlimit_config[32] = {.start_freq = 5000, .width = 40, .chan_num = 64, .ruPower = {-5, -2, 1, 4, 7, 0}},

    .rupwrlimit_config[33] = {.start_freq = 5000, .width = 40, .chan_num = 100, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[34] = {.start_freq = 5000, .width = 40, .chan_num = 104, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[35] = {.start_freq = 5000, .width = 40, .chan_num = 108, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[36] = {.start_freq = 5000, .width = 40, .chan_num = 112, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[37] = {.start_freq = 5000, .width = 40, .chan_num = 116, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[38] = {.start_freq = 5000, .width = 40, .chan_num = 120, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[39] = {.start_freq = 5000, .width = 40, .chan_num = 124, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[40] = {.start_freq = 5000, .width = 40, .chan_num = 128, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[41] = {.start_freq = 5000, .width = 40, .chan_num = 132, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[42] = {.start_freq = 5000, .width = 40, .chan_num = 136, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[43] = {.start_freq = 5000, .width = 40, .chan_num = 140, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[44] = {.start_freq = 5000, .width = 40, .chan_num = 144, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[45] = {.start_freq = 5000, .width = 40, .chan_num = 149, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[46] = {.start_freq = 5000, .width = 40, .chan_num = 153, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[47] = {.start_freq = 5000, .width = 40, .chan_num = 157, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[48] = {.start_freq = 5000, .width = 40, .chan_num = 161, .ruPower = {-4, -1, 2, 5, 8, 0}},

    .rupwrlimit_config[49] = {.start_freq = 5000, .width = 80, .chan_num = 36, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[50] = {.start_freq = 5000, .width = 80, .chan_num = 40, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[51] = {.start_freq = 5000, .width = 80, .chan_num = 44, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[52] = {.start_freq = 5000, .width = 80, .chan_num = 48, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[53] = {.start_freq = 5000, .width = 80, .chan_num = 52, .ruPower = {-8, -5, -2, 1, 4, 7}},

    .rupwrlimit_config[54] = {.start_freq = 5000, .width = 80, .chan_num = 56, .ruPower = {-8, -5, -2, 1, 4, 7}},

    .rupwrlimit_config[55] = {.start_freq = 5000, .width = 80, .chan_num = 60, .ruPower = {-8, -5, -2, 1, 4, 7}},

    .rupwrlimit_config[56] = {.start_freq = 5000, .width = 80, .chan_num = 64, .ruPower = {-8, -5, -2, 1, 4, 7}},

    .rupwrlimit_config[57] = {.start_freq = 5000, .width = 80, .chan_num = 100, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[58] = {.start_freq = 5000, .width = 80, .chan_num = 104, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[59] = {.start_freq = 5000, .width = 80, .chan_num = 108, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[60] = {.start_freq = 5000, .width = 80, .chan_num = 112, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[61] = {.start_freq = 5000, .width = 80, .chan_num = 116, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[62] = {.start_freq = 5000, .width = 80, .chan_num = 120, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[63] = {.start_freq = 5000, .width = 80, .chan_num = 124, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[64] = {.start_freq = 5000, .width = 80, .chan_num = 128, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[65] = {.start_freq = 5000, .width = 80, .chan_num = 149, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[66] = {.start_freq = 5000, .width = 80, .chan_num = 153, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[67] = {.start_freq = 5000, .width = 80, .chan_num = 157, .ruPower = {-7, -4, -1, 2, 5, 8}},

    .rupwrlimit_config[68] = {.start_freq = 5000, .width = 80, .chan_num = 161, .ruPower = {-7, -4, -1, 2, 5, 8}},
};
#endif /* CONFIG_5GHz_SUPPORT */
#endif /* CONFIG_COMPRESS_RU_TX_PWTBL */
#endif /* CONFIG_11AX */

#endif /* _WLAN_TXPWRLIMIT_CFG_WW_H_ */
