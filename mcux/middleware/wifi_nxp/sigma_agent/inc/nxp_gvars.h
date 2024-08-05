/** @file nxp_gvars.h
 *
 * @brief This file contains WLAN  specific defines etc.
 *
 * Copyright 2008-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* New Variables */
extern int HOSTAPD;
extern int MWIFIEX;

/*
struct nxp_sigma_dut_info {
 char sta_interface[32];
 char p2p_interface[32];
 char mmh_interface[32];
 char p2p_dev_address[32];
 char sta_dev_address[32];
 char mwlan_info_path[256];
 int  use_supplicant;
 char build_load[256];
 char build_unload[256];
 char config_methods[8];
 char model[30];
 int HE;
 int BW_20_only;
 int SAE_PWEuser;
 int usereg;
 int NSS;
 int mcsindex;
 //char MODEL_NUM[20];
};

struct nxp_sigma_dhcp_info {
 char dhcp_srv_ip[32];
 char dhcp_range[64];
 char dhcpd_lease_file[256];
 char dhclient_lease_file[256];
};


struct sigma_runtime_test_data {
 char wps_method[32];
 char wps_pin[32];
 char neg_res[8];
 int autogo;
 int dhcp;
 int oper_chn;
 int listen_chn;
 int reinvoke;
 int grpCapability;
 int devCapability;
 int eap_test;
 int roam;
 char ssid[32];
    char preset_non_pref_chan_list[50];
    char rfeat_non_pref_chan_list[50];
};

extern struct nxp_sigma_dut_info* nxp_dut_info;
extern struct nxp_sigma_dhcp_info* nxp_dhcp_info;
extern struct sigma_runtime_test_data* runtime_test_data;
*/

/* Old Variables */

extern char sta_saved_ssid[];

extern int ap_vht_bw;
extern int ap_ch_width;
extern int sta_ch_width;

// Bandwidth Global
extern int width;
extern int bw_signal;
extern int bw_signal_flag;
extern int dyn_bw_signal;
extern int dyn_bw_signal_flag;
extern int is_vht_tkip;

// STA/AP type: Testbed/DUT
extern char sta_type[];
extern char ap_type[];
extern char channel[];
extern int HE;
extern int MCSINDEX;
extern int NSS;
extern int coding;

extern int ap_sgi80_hack; /* we do not want to use auto rate when sgi80 enable comes on AP */
extern unsigned char ap_mcs_fixedrate;

/* uap default wmm params */
/*
extern wmm_ac_t   vi;
extern wmm_ac_t   vo;
extern wmm_ac_t   be;
extern wmm_ac_t   bk;

extern ap_vi_flag;
extern ap_vo_flag;
extern ap_be_flag;
extern ap_bk_flag;
*/

// flag to indicate whether or not to use open-source supplicant
extern int useSupplicant;
// flag to indicate whether or not to use supplicant for enterprise mode
extern int useSupplicantEnt;

// declared my my //

extern char methods[];
extern char wps_pin[];
extern char wps_read_pin[];
extern int i_am_autogo;
extern char autossid[];
extern char my_device_mac[];

extern int intent;
extern int op_chan;
extern int listen_chan;

// struct wlan_network net;

// For MBO
extern int Ch_Op_Class_0;
extern int Ch_Pref_Num_0;
extern int Ch_Pref_0;
extern int Ch_Reason_Code_0;

extern char default_method[];
extern char name[];
extern char model_name[];
extern char model_number[];
extern char wpa2_key[];
extern char p2p_interface[];
extern char dhcp_srv_ip[];
extern char dhcp_range[];
extern char auth[];
extern char encrypt[];
extern char ssid_prefix[];

extern char COUNTRY_CODE[];
extern int usereg;
extern char MODEL_NUM[];

// declared by my //

extern char e2eResults[];
// extern char *e2eResults;
// extern FILE *e2efp;

/* Since the two definitions are used all over the CA function */
extern char gCmdStr[];
extern dutCmdResponse_t gGenericResp;

extern char saved_mcs_fixed_rate[];
extern char saved_txsp_stream[];
extern int ap_use_hostapd;

extern int flag;
extern int return_flag;
