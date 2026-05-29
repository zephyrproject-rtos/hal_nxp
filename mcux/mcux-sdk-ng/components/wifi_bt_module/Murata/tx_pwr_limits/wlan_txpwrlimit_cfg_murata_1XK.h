/** @file wlan_txpwrlimit_cfg_murata_1XK_WW
 *
 *  @brief  This file provides Murata 1XK WLAN World Wide Safe Mode Tx Power Limit APIs.
 *
 *  Copyright 2022 Murata Manufacturing Co., Ltd.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *  may be used to endorse or promote products derived from this software without
 *  specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef _WLAN_TXPWRLIMIT_CFG_MURATA_1XK_WW_H_
#define _WLAN_TXPWRLIMIT_CFG_MURATA_1XK_WW_H_

#define WLAN_REGION_CODE "WW"

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
static const t_u8 rg_table_SD8978_WW[] = {
    0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x57, 0x57, 0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x5b, 0x00, 0xf0, 0xf0,
    0x04, 0x01, 0x0b, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x57, 0x57, 0x00, 0x00, 0x93, 0x04, 0x00, 0x02, 0x08, 0x05,
    0x82, 0xc0, 0x48, 0x00, 0x08, 0x20, 0x1a, 0x00, 0x82, 0xc1, 0xe1, 0x30, 0x88, 0x34, 0x32, 0x15, 0x0d, 0x85,
    0xc4, 0x62, 0x11, 0x38, 0x7c, 0x1c, 0x73, 0x14, 0x87, 0x00, 0x01, 0xe0, 0x00, 0x20, 0x0e, 0x36, 0x05, 0x40,
    0x04, 0x40, 0x60, 0x10, 0x00, 0xa8, 0x10, 0x18, 0x00, 0x04, 0x41, 0x01, 0x99, 0x4c, 0xae, 0x5b, 0x2c, 0x95,
    0x4c, 0x25, 0xd3, 0x19, 0x7c, 0xd6, 0x69, 0x37, 0x99, 0xce, 0x66, 0x53, 0xb9, 0xb4, 0xea, 0x5a, 0x01
};
static const t_u16 rg_table_SD8978_WW_len = 107;

static const t_u8 rg_table_SD8978_JP[] = {
0x49, 0x02, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x4a, 0x50,
0x20, 0x40, 0x00, 0x03, 0x06, 0x02, 0x57, 0x00, 0x88, 0x88, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x4a, 0x50, 0x20, 0x40, 0x53, 0x04, 0x00, 0x00, 0x0c, 0x06, 0xab, 0x00, 0x21, 0x00,
0x68, 0x00, 0x02, 0x11, 0x82, 0xc0, 0xe1, 0x30, 0x48, 0x34, 0x30, 0x02, 0x0f, 0x84, 0xc4, 0x00,
0x02, 0xb0, 0x40, 0x10, 0x16, 0x0f, 0x56, 0x01, 0x51, 0x80, 0xe0, 0x58, 0x04, 0x00, 0x27, 0x07,
0x02, 0x01, 0xe0, 0xb0, 0x00, 0x4c, 0x1e, 0x01, 0x90, 0xc8, 0xe4, 0xb2, 0x79, 0x4c, 0x92, 0x4d,
0x28, 0x09, 0xc9, 0x41, 0xc1, 0x49, 0x94, 0xd0, 0x27, 0x33, 0x9a, 0xce, 0x66, 0xe0, 0x10
};
static const t_u16 rg_table_SD8978_JP_len = 111;

static const t_u8 rg_table_SD8978_US[] = {
0x49, 0x02, 0xad, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x55, 0x53,
0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0x95, 0x00, 0x88, 0x88, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x55, 0x53, 0x20, 0x10, 0x33, 0x08, 0x00, 0x00, 0x0c, 0x05, 0xab, 0x00, 0x61, 0x10,
0x58, 0x00, 0x06, 0x0e, 0x81, 0x81, 0x61, 0x10, 0x68, 0x40, 0x42, 0x14, 0x03, 0x86, 0x00, 0xe1,
0xd0, 0xb0, 0x18, 0x36, 0x24, 0x05, 0x8b, 0x41, 0xa2, 0xc0, 0xf8, 0xc4, 0x42, 0x2a, 0x03, 0x8e,
0x46, 0x45, 0xa0, 0x80, 0x20, 0x2c, 0x1f, 0x24, 0x06, 0x00, 0x51, 0x80, 0xe0, 0x58, 0x04, 0x00,
0x27, 0x07, 0x00, 0x42, 0x00, 0x60, 0x70, 0x08, 0x1e, 0x0f, 0x00, 0x03, 0xa6, 0xb3, 0x39, 0xac,
0xde, 0x73, 0x3b, 0x9a, 0x4d, 0xa7, 0x13, 0xa0, 0x08, 0x34, 0x02, 0x0f, 0x03, 0x03, 0x40, 0x40,
0xea, 0x1d, 0x2a, 0x91, 0x4a, 0xa6, 0x4e, 0x69, 0xd4, 0x9a, 0x5d, 0x34, 0x02, 0x0c, 0xa5, 0x81,
0x01, 0x80, 0x40, 0x70, 0x22, 0x52, 0x0e, 0x02, 0x00, 0x01, 0xe0, 0xc8, 0x3d, 0x6a, 0xb9, 0x5e,
0x00, 0xd8, 0x2c, 0x56, 0x4b, 0x05, 0x6e, 0xbb, 0x5f, 0xb0, 0xd8, 0xc0, 0x20
};
static const t_u16 rg_table_SD8978_US_len = 173;

static const t_u8 rg_table_SD8978_EU[] = {
0x49, 0x02, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x45, 0x55,
0x20, 0x30, 0x00, 0x02, 0x06, 0x02, 0x5e, 0x00, 0x88, 0x88, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x45, 0x55, 0x20, 0x30, 0xc3, 0x04, 0x00, 0x00, 0x0c, 0x06, 0xab, 0x00, 0x20, 0xe0,
0x68, 0x02, 0x07, 0x05, 0x83, 0xc1, 0xa0, 0x90, 0xa8, 0x44, 0x2e, 0x12, 0x2b, 0x04, 0x01, 0x01,
0x60, 0xe0, 0x78, 0x06, 0x22, 0x0c, 0x00, 0xa3, 0x01, 0xca, 0xf0, 0x08, 0x00, 0x4e, 0x0f, 0x09,
0x81, 0xc0, 0xa0, 0x00, 0x7c, 0x82, 0x45, 0x24, 0x93, 0x48, 0xc1, 0xe0, 0xe9, 0x0c, 0xaa, 0x59,
0x27, 0x95, 0xcb, 0x64, 0x80, 0xe0, 0x94, 0x18, 0x0e, 0x04, 0x00, 0x04, 0x26, 0x93, 0x69, 0xc4,
0xea, 0x6a, 0x01, 0x9b, 0xce, 0x40
};
static const t_u16 rg_table_SD8978_EU_len = 118;

static const t_u8 rg_table_SD8978_CA[] = {
0x49, 0x02, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xee, 0x01, 0x06, 0x00, 0x43, 0x41,
0x20, 0x10, 0x00, 0x01, 0x06, 0x02, 0xa7, 0x00, 0x88, 0x88, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x43, 0x41, 0x20, 0x10, 0x53, 0x09, 0x00, 0x00, 0x0c, 0x05, 0xab, 0x00, 0x61, 0x10,
0x58, 0x00, 0x06, 0x0e, 0x81, 0x81, 0x01, 0xc0, 0x48, 0x34, 0x20, 0x21, 0x0a, 0x86, 0x41, 0xc0,
0x70, 0xf8, 0x5c, 0x18, 0x1b, 0x13, 0x02, 0x03, 0x62, 0x31, 0x70, 0x7c, 0x66, 0x36, 0x03, 0x8e,
0xc6, 0x80, 0x02, 0xd0, 0x40, 0x10, 0x16, 0x08, 0x07, 0x80, 0x55, 0xe0, 0x30, 0x58, 0x0e, 0x4a,
0x0c, 0x00, 0xa3, 0x01, 0xc0, 0xb0, 0x08, 0x00, 0x4f, 0x0b, 0x08, 0x41, 0xc0, 0x51, 0xd8, 0x30,
0x3c, 0x10, 0x00, 0x07, 0x03, 0x80, 0xb3, 0x90, 0x74, 0xee, 0x23, 0x3e, 0xa0, 0x50, 0xa8, 0x94,
0x69, 0xec, 0xfe, 0x82, 0x01, 0x06, 0x80, 0x61, 0x00, 0xf0, 0x18, 0x34, 0x05, 0x15, 0x83, 0xd3,
0xaa, 0xd5, 0x3a, 0xad, 0x5e, 0x22, 0x0e, 0xad, 0x55, 0xe4, 0x15, 0xda, 0xc5, 0x82, 0x81, 0x51,
0x06, 0x57, 0x81, 0x90, 0xa0, 0x10, 0x02, 0xd9, 0x30, 0x8a, 0x83, 0xc1, 0x90, 0x70, 0x25, 0xae,
0x8b, 0x6e, 0xa2, 0xdc, 0x21, 0x97, 0x2b, 0xa5, 0xda, 0xdb, 0x6f, 0xa9, 0x5e, 0xe6, 0x00
};

static const t_u16 rg_table_SD8978_CA_len = 191;

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
#endif
#endif /* CONFIG_5GHz_SUPPORT */

#endif /* _WLAN_TXPWRLIMIT_CFG_MURATA_1XK_WW_H_ */
