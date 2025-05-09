/** @file wlan_txpwrlimit_cfg_murata_2DS_US.h
 *
 *  @brief  This file provides Murata 2DS WLAN US Tx Power Limit APIs.
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

#ifndef _WLAN_TXPWRLIMIT_CFG_MURATA_2DS_US_H_
#define _WLAN_TXPWRLIMIT_CFG_MURATA_2DS_US_H_
#define WLAN_REGION_CODE "US"

static wlan_chanlist_t chanlist_2g_cfg = {.num_chans = 11,
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
                                              [11] = {0},
                                              [12] = {0},
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

static wifi_txpwrlimit_t
    tx_pwrlimit_2g_cfg =
        {.subband   = (wifi_SubBand_t)0x00,
         .num_chans = 11,
         .txpwrlimit_config =
             {
                 [0] =
                     {
                         .num_mod_grps = 10,
                         .chan_desc =
                             {
                                 .start_freq = 2407,
                                 .chan_width = 20,
                                 .chan_num   = 1,
                             },
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 12}, {2, 12}, {3, 12}, {4, 11}, {5, 11}, {6, 11}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 15}, {2, 14}, {3, 14}, {4, 15}, {5, 15}, {6, 14}, {7, 0}, {8, 0}, {9, 0}},
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
                         .txpwrlimit_entry =
                             {{0, 17}, {1, 12}, {2, 12}, {3, 12}, {4, 11}, {5, 11}, {6, 11}, {7, 0}, {8, 0}, {9, 0}},
                     },
                 [11] = {0},
                 [12] = {0},
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
             }};

#endif /* _WLAN_TXPWRLIMIT_CFG_MURATA_2DS_US_H_ */
