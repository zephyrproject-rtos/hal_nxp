/** @file nxp_gvars.c
 *
 * @brief This file contains WLAN  specific defines etc.
 *
 * Copyright 2008-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "nxp_wifi.h"

#if CONFIG_SIGMA_AGENT
#include "wfa_portall.h"
#include "wfa_debug.h"
#include "wfa_ver.h"
#include "wfa_main.h"
#include "wfa_types.h"
#include "wfa_ca.h"
#include "wfa_tlv.h"
#include "wfa_sock.h"
#include "wfa_tg.h"
#include "wfa_cmds.h"
#include "wfa_rsp.h"
#include "wfa_utils.h"

/* New Variables */

int MWIFIEX = 0;
int HOSTAPD = 0;
#if 0
struct nxp_sigma_dut_info *nxp_dut_info;
struct nxp_sigma_dhcp_info *nxp_dhcp_info;
struct sigma_runtime_test_data *runtime_test_data;
#endif

/* Old Variables */

char sta_saved_ssid[33];

int ap_vht_bw    = 1;
int ap_ch_width  = 80;
int sta_ch_width = 80;

// Bandwidth Global
int width              = 0;
int bw_signal          = 0;
int bw_signal_flag     = 0;
int dyn_bw_signal      = 0;
int dyn_bw_signal_flag = 0;
int is_vht_tkip        = 0;

// STA/AP type: Testbed/DUT
char sta_type[16];
char ap_type[16];
char channel[20];
int HE       = 0;
int MCSINDEX = 0;
int NSS      = 0;
int coding   = 0;

int ap_sgi80_hack              = 0; /* we do not want to use auto rate when sgi80 enable comes on AP */
unsigned char ap_mcs_fixedrate = 0xff;

/* uap default wmm params */
// wmmac_t   vi = {2, 0, 3, 0, 2, 0, 47, 0};
// wmmac_t   vo = {3, 0, 4, 0, 2, 0, 94, 0};
// wmmac_t   be = {4, 0, 10, 0, 3, 0, 0, 0};
// wmmac_t   bk = {4, 0, 10, 0, 7, 0, 0, 0};
int ap_vi_flag = 0;
int ap_vo_flag = 0;
int ap_be_flag = 0;
int ap_bk_flag = 0;

int wfaExecuteCLI(char *CLI);
// flag to indicate whether or not to use open-source supplicant
int useSupplicant = 0;
// flag to indicate whether or not to use supplicant for enterprise mode
int useSupplicantEnt = 0;

// declared my my //

char methods[]       = "0188";
char wps_pin[]       = "1234567890";
char wps_read_pin[]  = "1234567890";
int i_am_autogo      = 0;
char autossid[]      = "DIRECT-xy00.00.00";
char my_device_mac[] = "00:00:00:00:00:00";

int intent      = 7;
int op_chan     = 11;
int listen_chan = 11;

// For MBO
int Ch_Op_Class_0    = 0;
int Ch_Pref_Num_0    = 0;
int Ch_Pref_0        = 0;
int Ch_Reason_Code_0 = 0;

char default_method[10];
char name[50];
char model_name[20];
char model_number[25];
char wpa2_key[64];
char p2p_interface[25];
char dhcp_srv_ip[25];
char dhcp_range[50];
char auth[16];
char encrypt[16];
char ssid_prefix[25];

// declared by my //

// char e2eResults[];
// extern char *e2eResults;
// FILE *e2efp = NULL;

/* Since the two definitions are used all over the CA function */
char gCmdStr[WFA_CMD_STR_SZ];
dutCmdResponse_t gGenericResp;
int wfaTGSetPrio(int sockfd, int tgClass);
void create_apts_msg(int msg, unsigned int txbuf[], int id);

char saved_mcs_fixed_rate[10] = {0};
char saved_txsp_stream[10]    = {0};
int ap_use_hostapd            = 0;

int flag        = 0;
int return_flag = 0;
#endif
