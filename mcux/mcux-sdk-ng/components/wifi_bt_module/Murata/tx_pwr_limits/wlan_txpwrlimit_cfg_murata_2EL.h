/** @file wlan_txpwrlimit_cfg_murata_2EL.h
 *
 *  @brief  This file provides Murata 2EL WLAN World Wide Safe Mode Tx Power Limits.
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

#ifndef _WLAN_TXPWRLIMIT_CFG_H_
#define _WLAN_TXPWRLIMIT_CFG_H_
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

static const t_u8 rg_table_SD9177_WW[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x57, 0x57, 0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x5b, 0x00, 0xf0, 0xf0,
    0x04, 0x01, 0x0b, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x57, 0x57, 0x00, 0x00, 0x93, 0x04, 0x00, 0x02, 0x08, 0x05,
    0x82, 0xc0, 0x48, 0x00, 0x08, 0x20, 0x1a, 0x00, 0x82, 0xc1, 0xe1, 0x30, 0x88, 0x34, 0x32, 0x15, 0x0d, 0x85,
    0xc4, 0x62, 0x11, 0x38, 0x7c, 0x1c, 0x73, 0x14, 0x87, 0x00, 0x01, 0xe0, 0x00, 0x20, 0x0e, 0x36, 0x05, 0x40,
    0x04, 0x40, 0x60, 0x10, 0x00, 0xa8, 0x10, 0x18, 0x00, 0x04, 0x41, 0x01, 0x99, 0x4c, 0xae, 0x5b, 0x2c, 0x95,
    0x4c, 0x25, 0xd3, 0x19, 0x7c, 0xd6, 0x69, 0x37, 0x99, 0xce, 0x66, 0x53, 0xb9, 0xb4, 0xea, 0x5a, 0x01};
static const t_u16 rg_table_SD9177_WW_len = 107;

static const t_u8 rg_table_SD9177_JP[] = {
        0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x4a, 0x50,
	0x20, 0x40, 0x00, 0x03, 0x06, 0x02, 0x6c, 0x00, 0xff, 0xff, 0x04, 0x01, 0x0b, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x4a, 0x50, 0x20, 0x40, 0xa3, 0x05, 0x00, 0x02, 0x0c, 0x01, 0x02, 0x00, 0xe0, 0xc0,
	0x28, 0x34, 0x36, 0x00, 0x00, 0x83, 0x41, 0xb0, 0x88, 0x54, 0x32, 0x17, 0x09, 0x87, 0xc3, 0x40,
	0x60, 0xd0, 0x38, 0x00, 0x0f, 0x14, 0x8b, 0x46, 0x00, 0xb0, 0x08, 0xa0, 0x30, 0x08, 0x00, 0x89,
	0xc5, 0x47, 0xa0, 0xc8, 0x7c, 0x92, 0x40, 0x0c, 0x8a, 0x84, 0xc0, 0x00, 0x40, 0x18, 0x3d, 0x00,
	0x17, 0x00, 0x0a, 0x81, 0xd2, 0xa0, 0xbc, 0xcc, 0x01, 0x35, 0x9a, 0x4d, 0xa7, 0x13, 0x79, 0xd0,
	0x2a, 0x69, 0x3e, 0x9b, 0xd0, 0x02, 0xe0, 0xc9, 0xfd, 0x16, 0x83, 0x46, 0x0b, 0xd0, 0xa8, 0x93,
	0x7a, 0x5d, 0x26, 0x90
};
static const t_u16 rg_table_SD9177_JP_len = 132;

static const t_u8 rg_table_SD9177_US[] = {
	0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x55, 0x53,
	0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0x82, 0x01, 0xf0, 0xf0, 0x04, 0x01, 0x0b, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x53, 0x20, 0x10, 0x03, 0x17, 0x00, 0x02, 0x08, 0x05, 0xa0, 0x00, 0x61, 0x30,
	0x08, 0x50, 0x10, 0x13, 0x01, 0x00, 0x00, 0x60, 0xf0, 0x10, 0x46, 0x0a, 0x05, 0x09, 0x00, 0x42,
	0x00, 0x10, 0x70, 0x06, 0x15, 0x0c, 0x87, 0x04, 0xe2, 0x11, 0x28, 0xa4, 0x5a, 0x17, 0x0d, 0x00,
	0x84, 0x80, 0x81, 0x10, 0x14, 0x4e, 0x2b, 0x0a, 0x06, 0x80, 0x41, 0xf1, 0xc0, 0x88, 0x1a, 0x57,
	0x27, 0x01, 0xca, 0x65, 0x71, 0x39, 0x6c, 0xbe, 0x3d, 0x32, 0x96, 0x4b, 0xa3, 0xb2, 0x80, 0x14,
	0x54, 0x20, 0x02, 0x06, 0x00, 0x81, 0x72, 0x58, 0x4c, 0xc6, 0x7b, 0x12, 0xa0, 0x50, 0xa8, 0x93,
	0xc9, 0xf5, 0x26, 0x87, 0x3f, 0x85, 0x45, 0x63, 0x00, 0x30, 0x84, 0x2e, 0x76, 0x03, 0x07, 0x55,
	0x00, 0x52, 0x90, 0x65, 0x52, 0x55, 0x16, 0x1d, 0xca, 0x67, 0xd0, 0xb0, 0x2c, 0xa6, 0x51, 0x1d,
	0x07, 0x81, 0x41, 0xc0, 0x29, 0x5d, 0x9a, 0x63, 0x14, 0xb6, 0x56, 0xc0, 0x35, 0xd8, 0x60, 0x00,
	0x22, 0x00, 0x02, 0x42, 0xc0, 0x00, 0x84, 0x05, 0x66, 0x2c, 0x2a, 0x82, 0x05, 0x00, 0xd0, 0xe8,
	0x98, 0x48, 0x15, 0x81, 0x01, 0x46, 0x80, 0x00, 0xe8, 0x8e, 0x07, 0x07, 0x1c, 0xc3, 0x04, 0xc1,
	0x18, 0xbc, 0x68, 0x08, 0x24, 0x05, 0xc2, 0x48, 0x41, 0x71, 0xa0, 0x94, 0x27, 0x18, 0x01, 0x87,
	0x60, 0xa2, 0x72, 0xb0, 0x8e, 0x1f, 0x26, 0x0e, 0x92, 0x68, 0xab, 0xf9, 0x1d, 0x3c, 0x46, 0x1c,
	0x12, 0x03, 0x68, 0xf4, 0x00, 0xad, 0x84, 0x93, 0x17, 0x0e, 0x86, 0x05, 0x00, 0x94, 0x10, 0x6c,
	0x34, 0x13, 0x92, 0xdb, 0xca, 0x80, 0x5b, 0xad, 0xe6, 0xf8, 0x25, 0xa7, 0xdc, 0x65, 0xb7, 0x75,
	0xb8, 0x6d, 0xdf, 0x50, 0x04, 0x9a, 0x55, 0xa7, 0xd9, 0x80, 0x2c, 0xd2, 0x4b, 0xa0, 0xb8, 0xf0,
	0x61, 0x81, 0x0e, 0x5e, 0xf4, 0x1f, 0xd0, 0x02, 0xc3, 0x01, 0xc0, 0x6c, 0x5c, 0x98, 0x08, 0x0a,
	0x04, 0x04, 0x01, 0x72, 0x2f, 0x2c, 0x53, 0xcf, 0xe9, 0xf5, 0x81, 0x3d, 0xa0, 0xef, 0x7f, 0xa8,
	0x23, 0xf2, 0x07, 0x79, 0xbd, 0x1f, 0x40, 0x7c, 0xc7, 0x4f, 0x33, 0x08, 0x06, 0x80, 0x41, 0xc0,
	0x50, 0x80, 0x14, 0x1e, 0x08, 0x00, 0x03, 0x82, 0x00, 0x10, 0x7c, 0x08, 0x03, 0x01, 0x06, 0x43,
	0x00, 0x40, 0xe0, 0x0c, 0x46, 0x03, 0x14, 0x06, 0x80, 0xc1, 0xc0, 0x20, 0x7c, 0x4e, 0x19, 0x0f,
	0x01, 0x82, 0x61, 0xe0, 0x20, 0x48, 0x0a, 0x13, 0x0d, 0x8d, 0x83, 0x63, 0x80, 0x20, 0x60, 0x0a,
	0x55, 0x2d, 0x07, 0x01, 0xe5, 0xa0, 0xa0, 0x10, 0x2c, 0x05, 0x34, 0x84, 0xc5, 0x01, 0x60, 0x40,
	0x50, 0x30, 0x16, 0x03, 0x04, 0x42, 0x01, 0xc0, 0xb0, 0x08
};
static const t_u16 rg_table_SD9177_US_len = 410;

static const t_u8 rg_table_SD9177_EU[] = {
	0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x45, 0x55,
	0x20, 0x30, 0x00, 0x02, 0x06, 0x02, 0x64, 0x00, 0xf9, 0xff, 0x04, 0x01, 0x0b, 0xab, 0x00, 0x00,
	0x00, 0x00, 0x45, 0x55, 0x20, 0x30, 0x23, 0x05, 0x00, 0x02, 0x0c, 0x01, 0x02, 0x00, 0xe0, 0xc0,
	0x22, 0x00, 0x02, 0x0c, 0x06, 0x80, 0x20, 0xf0, 0x98, 0x5c, 0x2a, 0x11, 0x0e, 0x86, 0x43, 0xe1,
	0xa0, 0x30, 0x60, 0x1c, 0x01, 0x03, 0x8b, 0x46, 0x00, 0x00, 0x58, 0x7c, 0x52, 0x2c, 0x3d, 0x89,
	0x47, 0x62, 0xa0, 0x00, 0x98, 0x00, 0x08, 0x03, 0x07, 0xa0, 0x02, 0xe0, 0x01, 0x50, 0x32, 0x4a,
	0x17, 0x97, 0x00, 0x26, 0x12, 0xf9, 0x8c, 0xce, 0x65, 0x35, 0x05, 0x4b, 0xe7, 0x33, 0x29, 0xdc,
	0xd8, 0x2f, 0x3d, 0xa0, 0x4e, 0xa8, 0x53, 0x79, 0xa5, 0x0e, 0x7f, 0x2f
};
static const t_u16 rg_table_SD9177_EU_len = 124;

static const t_u8 rg_table_SD9177_CA[] = {
	0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x41,
	0x20, 0x20, 0x00, 0x01, 0x06, 0x02, 0x6c, 0x01, 0xf0, 0xf0, 0x04, 0x01, 0x0b, 0xa0, 0x00, 0x00,
	0x00, 0x00, 0x43, 0x41, 0x20, 0x20, 0xa3, 0x15, 0x00, 0x02, 0x08, 0x05, 0xa0, 0x00, 0x61, 0x30,
	0x08, 0x50, 0x10, 0x13, 0x01, 0x00, 0x00, 0x60, 0xf0, 0x10, 0x46, 0x0a, 0x05, 0x09, 0x00, 0x42,
	0x00, 0x10, 0x70, 0x06, 0x15, 0x0c, 0x87, 0x04, 0xe2, 0x11, 0x28, 0xa4, 0x5a, 0x17, 0x0d, 0x00,
	0x84, 0x80, 0x81, 0x10, 0x14, 0x4e, 0x2b, 0x0a, 0x06, 0x80, 0x41, 0xf1, 0xc0, 0x88, 0x1a, 0x57,
	0x27, 0x01, 0xca, 0x65, 0x71, 0x39, 0x6c, 0xbe, 0x3d, 0x32, 0x96, 0x4b, 0xa3, 0xb2, 0x80, 0x14,
	0x54, 0x20, 0x02, 0x06, 0x00, 0x81, 0x72, 0x58, 0x4c, 0xc6, 0x7b, 0x12, 0xa0, 0x50, 0xa8, 0x93,
	0xc9, 0xf5, 0x26, 0x87, 0x3f, 0x85, 0x45, 0x63, 0x00, 0x30, 0x84, 0x2e, 0x76, 0x03, 0x07, 0x55,
	0x00, 0x52, 0x90, 0x65, 0x52, 0x55, 0x16, 0x1d, 0xca, 0x67, 0xd0, 0xb0, 0x2c, 0xa6, 0x51, 0x1d,
	0x07, 0x81, 0x41, 0xc0, 0x29, 0x5d, 0x9a, 0x63, 0x14, 0xb6, 0x56, 0xc0, 0x35, 0xd8, 0x60, 0x00,
	0x22, 0x00, 0x02, 0x42, 0xc0, 0x00, 0x54, 0x05, 0xdc, 0x57, 0x04, 0x0a, 0x01, 0xa1, 0xd1, 0x30,
	0x90, 0x2b, 0x00, 0x02, 0x84, 0x5d, 0xa2, 0x38, 0x0c, 0x14, 0x73, 0x0b, 0x1a, 0xc5, 0x00, 0x61,
	0x01, 0x20, 0x2e, 0x0e, 0x42, 0x0b, 0x09, 0x81, 0x32, 0x30, 0xec, 0x0c, 0x4e, 0x56, 0x11, 0xc3,
	0x01, 0x6e, 0xd2, 0x4c, 0xed, 0x7f, 0x1f, 0xa2, 0x08, 0xc4, 0x61, 0xc1, 0x20, 0x36, 0x78, 0x03,
	0xa0, 0xca, 0x68, 0xe5, 0x40, 0x20, 0xa0, 0x12, 0x82, 0x0d, 0x86, 0x82, 0x72, 0x01, 0x18, 0x74,
	0x33, 0x6b, 0xb7, 0xdc, 0xec, 0x77, 0x9b, 0x39, 0x17, 0x00, 0x22, 0x0e, 0xd1, 0x81, 0x26, 0x95,
	0x69, 0xf6, 0x54, 0x0b, 0x34, 0x92, 0xeb, 0xe2, 0xdc, 0x38, 0x60, 0x43, 0x6d, 0x5b, 0xb6, 0x72,
	0x80, 0xb0, 0xca, 0xcd, 0xda, 0x4c, 0x04, 0x05, 0x02, 0x02, 0x00, 0xb8, 0x8f, 0x7a, 0x29, 0xe0,
	0xf1, 0x79, 0x3a, 0x7d, 0xff, 0x0f, 0x8e, 0x1d, 0xe6, 0x07, 0x7a, 0x3e, 0x20, 0xf9, 0x8e, 0xa2,
	0x66, 0x08, 0xb1, 0x73, 0xfb, 0x7a, 0x8d, 0x74, 0x56, 0xb9, 0xb3, 0x0e, 0x00, 0x83, 0x00, 0x20,
	0xd0, 0x0c, 0x00, 0x1a, 0x03, 0x07, 0x00, 0x81, 0xe0, 0x28, 0x00, 0x3e, 0x06, 0x03, 0x04, 0xc0,
	0xc0, 0x20, 0x00, 0x8c, 0x3a, 0x12, 0x0d, 0x85, 0x00, 0x81, 0x80, 0x28, 0xc4, 0x6c, 0x1c, 0x07,
	0x8d, 0x82, 0x80, 0x40, 0xb8, 0x98, 0x46, 0x00, 0x0b, 0x02, 0x02, 0x81, 0x80, 0xb0, 0x18, 0x20,
	0x0b, 0x14, 0x92, 0x00
};

static const t_u16 rg_table_SD9177_CA_len = 388;

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
    0x6d, 0x02, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c};

const static uint8_t rutxpowerlimit_cfg_set_CA[] = {
	0x6d, 0x02, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c
};
static const t_u16 rutxpowerlimit_cfg_set_CA_len = 101;


const static uint8_t rutxpowerlimit_cfg_set_EU[] = {
	0x6d, 0x02, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c
};
static const t_u16 rutxpowerlimit_cfg_set_EU_len = 101;

const static uint8_t rutxpowerlimit_cfg_set_US[] = {
	0x6d, 0x02, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c
};
static const t_u16 rutxpowerlimit_cfg_set_US_len = 101;


const static uint8_t rutxpowerlimit_cfg_set_JP[] = {
	0x6d, 0x02, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x01, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c
};
static const t_u16 rutxpowerlimit_cfg_set_JP_len = 101;

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
