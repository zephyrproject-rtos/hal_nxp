/** @file wps_wlan.h
 *
 *  @brief This file contains definition for WLAN driver control/command
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <wlan.h>

#ifndef _WPS_WLAN_H_
#define _WPS_WLAN_H_

/*
 *  ctype from older glib installations defines BIG_ENDIAN.  Check it
 *   and undef it if necessary to correctly process the wlan header
 *   files
 */
#if (BYTE_ORDER == LITTLE_ENDIAN)
#undef BIG_ENDIAN
#endif

/* Length of interface name.  */
#define IF_NAMESIZE 16
#define IFNAMESIZE  IF_NAMESIZE

/** WPS IE Operation type */
/** Clear WPS IE */
#define CLEAR_WPS_IE 0x00
/** Set WPS IE */
#define SET_WPS_IE 0x10
/** Get WPS IE */
#define GET_WPS_IE 0x20

/** Probe request Enable OR Mask */
#define WPS_ORMASK_ENABLE_PROBE_REQ 0x0010
/** Probe request Disable AND Mask */
#define WPS_ANDMASK_DISABLE_PROBE_REQ 0xffef

/** WPS IE set type : session inactive */
#define WPS_AP_SESSION_INACTIVE 0x00
/** WPS IE set type : session active ap */
#define WPS_AP_SESSION_ACTIVE 0x01
/** WPS IE set type : session active sta */
#define WPS_STA_SESSION_ACTIVE 0x02
/** WPS IE set type : session inactive AP AssocResp */
#define WPS_AP_SESSION_ACTIVE_AR 0x03
/** WPS IE set type : session inactive AP ReAssocResp */
#define WPS_AP_SESSION_INACTIVE_AR 0x04

/** IE set type : wps + session active ap */
#define SET_WPS_AP_SESSION_ACTIVE_IE (SET_WPS_IE | WPS_AP_SESSION_ACTIVE)
/** IE set type : wps + session inactive ap */
#define SET_WPS_AP_SESSION_INACTIVE_IE (SET_WPS_IE | WPS_AP_SESSION_INACTIVE)
/** IE set type : wps + session active sta */
#define SET_WPS_STA_SESSION_ACTIVE_IE (SET_WPS_IE | WPS_STA_SESSION_ACTIVE)
/** IE set type : wps + session active ap */
#define SET_WPS_AP_SESSION_ACTIVE_AR_IE (SET_WPS_IE | WPS_AP_SESSION_ACTIVE_AR)
/** IE set type : wps + session active ap */
#define SET_WPS_AP_SESSION_INACTIVE_AR_IE (SET_WPS_IE | WPS_AP_SESSION_INACTIVE_AR)
/** IE clear type : wps + session active ap */
#define CLEAR_AR_WPS_IE (CLEAR_WPS_IE | WPS_AP_SESSION_ACTIVE_AR)
/** IE clear type : wps + session active ap */
#define CLEAR_STA_WPS_IE (CLEAR_WPS_IE | WPS_STA_SESSION_ACTIVE)

/** Maximum MGMT IE index count */
//#define MAX_MGMT_IE_INDEX                        12

/** WPA Passphrase length*/
#define WPA_PASSPHARE_LENGTH 64

/** Maximum number of MAC addresses for one-shot filter modifications */
#define MAX_MAC_ONESHOT_FILTER 16
/** Maximum SSID length */
#define MAX_SSID_LENGTH 32
/** Maximum channels */
#define MAX_CHANNELS 14
/** Standard DEAUTH code for AP deauth */
#define DEAUTH_REASON_PREV_AUTH_INVALID 0x0002

#ifdef CONFIG_WPA2_ENTP
#define WLAN_EID_ERP_INFO                        42
#define WLAN_EID_HT_CAP                          45
#define WLAN_EID_RSN                             48
#define WLAN_EID_EXT_SUPP_RATES                  50
#define WLAN_EID_MOBILITY_DOMAIN                 54
#define WLAN_EID_FAST_BSS_TRANSITION             55
#define WLAN_EID_TIMEOUT_INTERVAL                56
#define WLAN_EID_RIC_DATA                        57
#define WLAN_EID_HT_OPERATION                    61
#define WLAN_EID_SECONDARY_CHANNEL_OFFSET        62
#define WLAN_EID_WAPI                            68
#define WLAN_EID_TIME_ADVERTISEMENT              69
#define WLAN_EID_20_40_BSS_COEXISTENCE           72
#define WLAN_EID_20_40_BSS_INTOLERANT            73
#define WLAN_EID_OVERLAPPING_BSS_SCAN_PARAMS     74
#define WLAN_EID_MMIE                            76
#define WLAN_EID_SSID_LIST                       84
#define WLAN_EID_BSS_MAX_IDLE_PERIOD             90
#define WLAN_EID_TFS_REQ                         91
#define WLAN_EID_TFS_RESP                        92
#define WLAN_EID_WNMSLEEP                        93
#define WLAN_EID_TIME_ZONE                       98
#define WLAN_EID_LINK_ID                         101
#define WLAN_EID_INTERWORKING                    107
#define WLAN_EID_ADV_PROTO                       108
#define WLAN_EID_ROAMING_CONSORTIUM              111
#define WLAN_EID_EXT_CAPAB                       127
#define WLAN_EID_CCKM                            156
#define WLAN_EID_VHT_CAP                         191
#define WLAN_EID_VHT_OPERATION                   192
#define WLAN_EID_VHT_EXTENDED_BSS_LOAD           193
#define WLAN_EID_VHT_WIDE_BW_CHSWITCH            194
#define WLAN_EID_VHT_TRANSMIT_POWER_ENVELOPE     195
#define WLAN_EID_VHT_CHANNEL_SWITCH_WRAPPER      196
#define WLAN_EID_VHT_AID                         197
#define WLAN_EID_VHT_QUIET_CHANNEL               198
#define WLAN_EID_VHT_OPERATING_MODE_NOTIFICATION 199

/* Information Element IDs */
#define WLAN_EID_SSID       0
#define WLAN_EID_SUPP_RATES 1

/* Timeout Interval Type */
#define WLAN_TIMEOUT_REASSOC_DEADLINE 1
#define WLAN_TIMEOUT_KEY_LIFETIME     2
#define WLAN_TIMEOUT_ASSOC_COMEBACK   3

#endif
#define WLAN_EID_VENDOR_SPECIFIC 221

/** MLAN 802.11 MAC Address */
// typedef u8 mlan_802_11_mac_addr[ETH_ALEN];

/** BSS config structure */
typedef struct _bss_config_t
{
    /** AP mac addr */
    mlan_802_11_mac_addr mac_addr;
    /** SSID */
    mlan_802_11_ssid ssid;
    /** Broadcast ssid control */
    u8 bcast_ssid_ctl;
    /** Radio control */
    u8 radio_ctl;
    /** dtim period */
    u8 dtim_period;
    /** beacon period */
    u16 beacon_period;
    /** rates */
    u8 rates[14];
    /** Tx data rate */
    u16 tx_data_rate;
    /** multicast/broadcast data rate */
    u16 mcbc_data_rate;
    /** Tx power level */
    u8 tx_power_level;
    /** Tx antenna */
    u8 tx_antenna;
    /** Rx anteena */
    u8 rx_antenna;
    /** packet forward control */
    u8 pkt_forward_ctl;
    /** max station count */
    u16 max_sta_count;
    /** mac filter */
    mac_filter filter;
    /** station ageout timer in the unit of 100ms  */
    u32 sta_ageout_timer;
    /** PS station ageout timer in the unit of 100ms  */
    u32 ps_sta_ageout_timer;
    /** RTS threshold */
    u16 rts_threshold;
    /** fragmentation threshold */
    u16 frag_threshold;
    /**  retry_limit */
    u16 retry_limit;
    /**  pairwise update timeout */
    u32 pairwise_update_timeout;
    /** pairwise handshake retries */
    u32 pwk_retries;
    /**  groupwise update timeout */
    u32 groupwise_update_timeout;
    /** groupwise handshake retries */
    u32 gwk_retries;
    /** preamble type */
    u8 preamble_type;
    /** band cfg */
    u8 band_cfg;
    /** channel */
    u8 channel;
    /** auth mode */
    u16 auth_mode;
    /** encryption protocol */
    u16 protocol;
    /** key managment type */
    u16 key_mgmt;
    /** wep param */
    wep_key wep_cfg[4];
    /** wpa param */
    wpa_param wpa_cfg;
    /** Mgmt IE passthru mask */
    u32 mgmt_ie_passthru_mask;
    /*
     * 11n HT Cap  HTCap_t  ht_cap
     */
    /** HT Capabilities Info field */
    u16 ht_cap_info;
    /** A-MPDU Parameters field */
    u8 ampdu_param;
    /** Supported MCS Set field */
    u8 supported_mcs_set[16];
    /** HT Extended Capabilities field */
    u16 ht_ext_cap;
    /** Transmit Beamforming Capabilities field */
    u32 tx_bf_cap;
    /** Antenna Selection Capability field */
    u8 asel;
    /** Enable 2040 coex */
    u8 enable_2040coex;
    /** key management operation */
    u16 key_mgmt_operation;
    /** BSS status */
    u16 bss_status;
    u8 psk[32];
    /** scan channel list in ACS mode */
    scan_chan_list chan_list;

} bss_config_t;

/** event header */
typedef struct _eventheader
{
    /** event id */
    u32 event_id;
    /** event data */
    u8 event_data[0];
} event_header;

/**
 *  @brief Set the BSS information into the registrar credential structure
 *  @param wps_s     A pointer to the WPS_DATA structure
 *  @param pwps_info A pointer to the PWPS_INFO structure
 *  @param bss       BSS information
 *
 *  @return          WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
extern int load_cred_info(WPS_DATA *wps_s, PWPS_INFO pwps_info, bss_config_t *bss);
/**
 *  @brief Starts the existing AP BSS .
 *
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int apcmd_start_bss(void);

/**
 *  @brief Stops the existing AP BSS .
 *
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int apcmd_stop_bss(void);

/**
 *  @brief Loads the AP configuration into data structures
 *
 *  @param wps_s      A pointer to the WPS_DATA structure
 *  @param pwps_info  A pointer to the PWPS_INFO structure
 *
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
extern int wps_load_uap_cred(WPS_DATA *wps_s, PWPS_INFO pwps_info);

/**
 *  @brief  Send Custom_IE command to driver.
 *  @param buf Pointer to data buffer
 *  @param buf_len length of data buffer
 *
 *  @return           WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wlan_sys_config(u8 *buf, u16 *buf_len, u8 action);

/**
 *  @brief Process and send ie config command
 *  @param flag   FLAG: Set/clear WPS IE
 *  @param index  A pointer to the IE buffer index
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
extern int wps_wlan_ie_config(int flag, short *ie_index);

/**
 *  @brief Creates a get bss_config request and sends to the driver
 *
 *  @param wps_s      A pointer to the WPS_DATA structure
 *  @param pwps_info  A pointer to the PWPS_INFO structure
 *
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
extern int apcmd_get_bss_config(bss_config_t *bss);
/*
 * @brief process WFD generic event data
 *
 * @param buffer   Pointer to received buffer
 * @param size     Length of the received event data
 * @return         N/A
 */
void wfd_process_generic_event(u8 *buffer, u16 size);

/**
 *  @brief performs the ioctl operation to send the command to
 *  the driver for various modes.
 *
 *  @param  mode mode value to set
 *  @return wps_status_success or wps_status_fail
 */
int wfd_wlan_update_mode(u16 mode);

/**
 *  @brief performs the ioctl operation to send the command to
 *  the driver for various modes.
 *
 *  @param  mode mode value to set
 *  @return wps_status_success or wps_status_fail
 */
int wfd_set_mode(u16 mode);

/**
 *  @brief Creates a wfd_action_frame request and sends to the driver
 *
 *  Usage: "Usage : wfd_action_frame "
 *
 *  @param sel_index Index selected by user
 *  @param frame_sub_type  Frame Sub type for generic action frame
 *  @return          WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wfdcmd_action_frame(int sel_index, int frame_sub_type);

/**
 *  @brief  Update the password IE in the device configuration.
 *          First Get the config and update with password.
 *  @param  None
 *
 *  @return  WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wps_wlan_update_password_ie_config(void);

/**
 *  @brief  Remove the password IE in the device configuration.
 *          First Get the config and remove password if it exists.
 *  @param  None
 *
 *  @return  WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wps_wlan_remove_password_ie_config(void);

int hexstr2bin(const s8 *hex, u8 *buf, size_t len);
int bin2hexstr(const u8 *bin, s8 *hex, size_t len);
void wps_wlan_peer_event_parser(WPS_DATA *wps_s, char *evt_buffer, int evt_len);
void wps_wlan_event_parser(u8 *evt_buffer, int evt_len);
int mlanconfig_bgscan(int mode);
void wlan_generate_psk(PWPS_INFO pwps_info);
#endif
