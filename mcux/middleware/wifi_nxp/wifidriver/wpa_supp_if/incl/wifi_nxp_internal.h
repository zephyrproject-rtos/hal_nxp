/** @file wifi_nxp_internal.h
 *
 * @brief This file provides Core Wi-Fi definition for wpa supplicant RTOS driver.
 *
 * Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __WIFI_NXP_INTERNAL_H__
#define __WIFI_NXP_INTERNAL_H__

#include <stdio.h>

#include <wifi_config_default.h>

#if CONFIG_WPA_SUPP
#define WIFI_NXP_HT_MCS_MASK_LEN 10
#define WIFI_NXP_HT_MCS_RES_LEN 3

/**
 * @brief MCS information.
 *
 */
struct wifi_nxp_event_mcs_info {
    /** Highest supported RX rate */
    unsigned short wifi_nxp_rx_highest;
    /** RX mask */
    unsigned char wifi_nxp_rx_mask[WIFI_NXP_HT_MCS_MASK_LEN];
    /** TX parameters */
    unsigned char wifi_nxp_tx_params;
    /** reserved */
    unsigned char wifi_nxp_reserved[WIFI_NXP_HT_MCS_RES_LEN];
};

/**
 * @brief This structure represents HT capability parameters.
 *
 */
struct wifi_nxp_event_sta_ht_cap {
    /** 1 indicates HT Supported */
    signed int wifi_nxp_ht_supported;
    /** HT capabilities, as in the HT information IE */
    unsigned short wifi_nxp_cap;
    /** MCS information. @ref wifi_nxp_event_mcs_info */
    struct wifi_nxp_event_mcs_info mcs;
    /** A-MPDU factor, as in 11n */
    unsigned char wifi_nxp_ampdu_factor;
    /** A-MPDU density, as in 11n */
    unsigned char wifi_nxp_ampdu_density;
};

#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_IR (1 << 0)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_IBSS (1 << 1)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_RADAR (1 << 2)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_HT40_MINUS (1 << 3)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_HT40_PLUS (1 << 4)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_80MHZ (1 << 5)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_160MHZ (1 << 6)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_INDOOR_ONLY (1 << 7)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_GO_CONCURRENT (1 << 8)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_20MHZ (1 << 9)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_10MHZ (1 << 10)
#define WIFI_NXP_CHAN_FLAG_FREQUENCY_DISABLED (1 << 11)

#define WIFI_NXP_CHAN_DFS_VALID (1 << 12)
#define WIFI_NXP_CHAN_DFS_CAC_TIME_VALID (1 << 13)

/**
 * @brief This structure represents channel parameters.
 */
struct wifi_nxp_event_channel {
    /** channel flags WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_IBSS */
    unsigned short wifi_nxp_flags;
    /** maximum transmission power (in dBm) */
    signed int wifi_nxp_max_power;
    /** DFS state time */
    unsigned int wifi_nxp_time;
    /** DFS CAC time in ms */
    unsigned int dfs_cac_msec;
    /** Channel parameters are valid or not 1=valid */
    signed char ch_valid;
    /** Channel center frequency */
    unsigned short center_frequency;
    /** Current dfs state */
    signed char dfs_state;
};

#define WIFI_NXP_EVENT_GET_WIPHY_FLAG_RATE_SHORT_PREAMBLE (1 << 0)
/**
 * @brief This structure represents rate information.
 */
struct wifi_nxp_event_rate {
    /** WIFI_NXP_EVENT_GET_WIPHY_FLAG_RATE_SHORT_PREAMBLE */
    unsigned short wifi_nxp_flags;
    /** Bitrate in units of 100 kbps */
    unsigned short wifi_nxp_bitrate;
};

/**
 * @brief VHT MCS information.
 *
 */
struct wifi_nxp_event_vht_mcs_info {
    /** RX MCS map 2 bits for each stream, total 8 streams */
    unsigned short rx_mcs_map;
    /** Indicates highest long GI VHT PPDU data rate
     *  STA can receive. Rate expressed in units of 1 Mbps.
     *  If this field is 0 this value should not be used to
     *  consider the highest RX data rate supported.
     */
    unsigned short rx_highest;
    /** TX MCS map 2 bits for each stream, total 8 streams */
    unsigned short tx_mcs_map;
    /** Indicates highest long GI VHT PPDU data rate
     *  STA can transmit. Rate expressed in units of 1 Mbps.
     *  If this field is 0 this value should not be used to
     *  consider the highest TX data rate supported.
     */
    unsigned short tx_highest;
};

/**
 * @brief This structure represents VHT capability parameters.
 *
 */
struct wifi_nxp_event_sta_vht_cap {
    /** 1 indicates VHT Supported */
    signed char wifi_nxp_vht_supported;
    /** VHT capability info */
    unsigned int wifi_nxp_cap;
    /** Refer @ref wifi_nxp_event_vht_mcs_info */
    struct wifi_nxp_event_vht_mcs_info vht_mcs;
};

#define WIFI_NXP_HE_MAX_MAC_CAPAB_SIZE  6
#define WIFI_NXP_HE_MAX_PHY_CAPAB_SIZE  11
#define WIFI_NXP_HE_MAX_MCS_CAPAB_SIZE  12
#define WIFI_NXP_HE_MAX_PPET_CAPAB_SIZE 25

/**
 * @brief This structure represents HE capability parameters.
 *
 */
struct wifi_nxp_event_sta_he_cap {
    unsigned char wifi_nxp_he_supported;
    unsigned char phy_cap[WIFI_NXP_HE_MAX_PHY_CAPAB_SIZE];
    unsigned char mac_cap[WIFI_NXP_HE_MAX_MAC_CAPAB_SIZE];
    unsigned char mcs[WIFI_NXP_HE_MAX_MCS_CAPAB_SIZE];
    unsigned char ppet[WIFI_NXP_HE_MAX_PPET_CAPAB_SIZE];
    unsigned short he_6ghz_capa;
};

/**
 * @brief Frequency band information.
 *
 */
struct wifi_nxp_event_supported_band {
	/** No.of channels */
	unsigned short wifi_nxp_n_channels;
	/** No.of bitrates */
	unsigned short wifi_nxp_n_bitrates;
	/** Array of channels the hardware can operate in this band */
	struct wifi_nxp_event_channel channels[29];
	/** Array of bitrates the hardware can operate with in this band */
	struct wifi_nxp_event_rate bitrates[13];
	/** HT capabilities in this band */
	struct wifi_nxp_event_sta_ht_cap ht_cap;
	/** VHT capabilities in this band */
	struct wifi_nxp_event_sta_vht_cap vht_cap;
	/** HE capabilities in this band */
	struct wifi_nxp_event_sta_he_cap he_cap;
	/** the band this structure represents */
	signed char band;
};

struct wifi_nxp_event_get_wiphy
{
    /** Supported bands info. @ref wifi_nxp_event_supported_band */
    struct wifi_nxp_event_supported_band sband[WIFI_NXP_EVENT_GET_WIPHY_NUM_BANDS];
};

#define WIFI_HE_MAX_MAC_CAPAB_SIZE  6
#define WIFI_HE_MAX_PHY_CAPAB_SIZE  11
#define WIFI_HE_MAX_MCS_CAPAB_SIZE  12
#define WIFI_HE_MAX_PPET_CAPAB_SIZE 25

/**
 * struct he_capabilities - IEEE 802.11ax HE capabilities
 */
typedef MLAN_PACK_START struct _nxp_wifi_he_capabilities
{
    unsigned char he_supported;
    unsigned char phy_cap[WIFI_HE_MAX_PHY_CAPAB_SIZE];
    unsigned char mac_cap[WIFI_HE_MAX_MAC_CAPAB_SIZE];
    unsigned char mcs[WIFI_HE_MAX_MCS_CAPAB_SIZE];
    unsigned char ppet[WIFI_HE_MAX_PPET_CAPAB_SIZE];
    unsigned short he_6ghz_capa;
} MLAN_PACK_END nxp_wifi_he_capabilities;

#define WIFI_MAX_IE_LEN 500U

typedef MLAN_PACK_START struct _nxp_wifi_ie
{
    unsigned short ie_len;
    char ie[WIFI_MAX_IE_LEN];
} MLAN_PACK_END nxp_wifi_ie_t;

typedef MLAN_PACK_START struct _nxp_wifi_ie2
{
    unsigned short ie_len;
    unsigned char *ie;
} MLAN_PACK_END nxp_wifi_ie2_t;

#define WIFI_MAX_SSID_LEN 32U
#define WIFI_ETH_ADDR_LEN 6U

typedef MLAN_PACK_START struct _nxp_wifi_ssid
{
    unsigned char ssid_len;
    unsigned char ssid[WIFI_MAX_SSID_LEN];
} MLAN_PACK_END nxp_wifi_ssid_t;

#define WIFI_SCAN_MAX_NUM_SSIDS 2U
#define WIFI_SCAN_MAX_NUM_CHAN  41U
#define MAX_NUM_CHANNELS        39U

typedef MLAN_PACK_START struct _nxp_wifi_trigger_scan
{
    bool hostapd;
    unsigned char num_ssids;
    nxp_wifi_ssid_t scan_ssids[WIFI_SCAN_MAX_NUM_SSIDS];
    unsigned char num_chans;
    unsigned char chan_list[WIFI_SCAN_MAX_NUM_CHAN];
    nxp_wifi_ie_t extra_ies;
    int filter_rssi;
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
    unsigned int only_new_results : 1;
} MLAN_PACK_END nxp_wifi_trigger_scan_t;

typedef MLAN_PACK_START struct _nxp_wifi_trigger_sched_scan
{
    unsigned int chan_per_scan;
    unsigned char num_ssids;
    nxp_wifi_ssid_t scan_ssids[WIFI_SCAN_MAX_NUM_SSIDS];
    unsigned char num_chans;
    unsigned char chan_list[WIFI_SCAN_MAX_NUM_CHAN];
    nxp_wifi_ie_t extra_ies;
    unsigned int scan_interval;
    unsigned int report_condition;
    unsigned short repeat_count;
    int filter_rssi;
} MLAN_PACK_END nxp_wifi_trigger_sched_scan_t;

typedef MLAN_PACK_START struct _nxp_wifi_event_new_scan_result
{
    unsigned int frequency;
    unsigned int chan_width;
    unsigned int seen_ms_ago;
    int status;
    unsigned long long ies_tsf;
    unsigned long long beacon_ies_tsf;
    unsigned short beacon_interval;
    unsigned short capability;
    nxp_wifi_ie2_t ies;
    unsigned char rssi;
    unsigned short noise;
    unsigned char mac_addr[WIFI_ETH_ADDR_LEN];
    bool more_res;
} MLAN_PACK_END nxp_wifi_event_new_scan_result_t;

typedef MLAN_PACK_START struct _nxp_wifi_trigger_op
{
    bool hostapd;
} MLAN_PACK_END nxp_wifi_trigger_op_t;

typedef MLAN_PACK_START struct _nxp_wifi_event_new_survey_result
{
    unsigned int freq;
    char nf;
    unsigned long long channel_time;
    unsigned long long channel_time_busy;
    unsigned long long channel_time_rx;
    unsigned long long channel_time_tx;
    bool more_res;
} MLAN_PACK_END nxp_wifi_event_new_survey_result_t;

typedef MLAN_PACK_START struct _nxp_wifi_acs_params
{
    unsigned int pri_freq;
    unsigned int sec_freq;
    unsigned short ch_width;
    unsigned int hw_mode;
} MLAN_PACK_END nxp_wifi_acs_params;

#define WIFI_MAX_FRAME_LEN 1500U

typedef MLAN_PACK_START struct _nxp_wifi_frame
{
    int frame_len;
    int freq;
    unsigned char frame[WIFI_MAX_FRAME_LEN];
} MLAN_PACK_END nxp_wifi_frame_t;

typedef MLAN_PACK_START struct _nxp_wifi_event_mlme
{
    nxp_wifi_frame_t frame;
    unsigned char mac_addr[WIFI_ETH_ADDR_LEN];
} MLAN_PACK_END nxp_wifi_event_mlme_t;

#define WIFI_EAPOL_MAX_FRAME_LEN 1500U

typedef MLAN_PACK_START struct _nxp_wifi_eapol_frame
{
    int frame_len;
    unsigned char frame[WIFI_EAPOL_MAX_FRAME_LEN];
} MLAN_PACK_END nxp_wifi_eapol_frame_t;

typedef MLAN_PACK_START struct _nxp_wifi_event_eapol_mlme
{
    nxp_wifi_eapol_frame_t frame;
    unsigned char mac_addr[WIFI_ETH_ADDR_LEN];
} MLAN_PACK_END nxp_wifi_event_eapol_mlme_t;

typedef MLAN_PACK_START struct _nxp_wifi_assoc_event_mlme
{
    nxp_wifi_frame_t frame;
    unsigned char mac_addr[WIFI_ETH_ADDR_LEN];
    unsigned int req_ie_len;
    unsigned char req_ie[WIFI_MAX_FRAME_LEN];
} MLAN_PACK_END nxp_wifi_assoc_event_mlme_t;

typedef MLAN_PACK_START struct _nxp_wifi_gsta_info
{
    unsigned char mac_addr[WIFI_ETH_ADDR_LEN];
} MLAN_PACK_END nxp_wifi_gsta_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_event_new_station
{
    // struct wpa_signal_info for supplicant
    unsigned char wme;
    unsigned char is_sta_legacy;
    unsigned char mac_addr[WIFI_ETH_ADDR_LEN];
    unsigned int generation;
    nxp_wifi_gsta_info_t sta_info;
    nxp_wifi_ie_t assoc_req_ies;
} MLAN_PACK_END nxp_wifi_event_new_station_t;

typedef MLAN_PACK_START struct _nxp_wifi_chan_definition
{
    int width;
    unsigned int center_frequency1;
    unsigned int center_frequency2;
} MLAN_PACK_END nxp_wifi_chan_definition_t;

#define IFACENAMSIZ 10U

typedef MLAN_PACK_START struct _nxp_wifi_interface_info
{
    // struct wpa_signal_info for supplicant
    int nrf_wifi_iftype;
    char ifacename[IFACENAMSIZ];
    unsigned char nxp_wifi_eth_addr[WIFI_ETH_ADDR_LEN];
    nxp_wifi_chan_definition_t chan_def;
    nxp_wifi_ssid_t ssid;
} MLAN_PACK_END nxp_wifi_interface_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_auth_info
{
    unsigned char auth_alg;
    unsigned char auth_trans_num;
    unsigned char status_code;
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
    int channel;
    nxp_wifi_ie_t auth_ie;
} MLAN_PACK_END nxp_wifi_auth_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_deauth_info
{
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
    unsigned short reason_code;
} MLAN_PACK_END nxp_wifi_deauth_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_assoc_info
{
    unsigned int center_frequency;
    nxp_wifi_ssid_t ssid;
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
    unsigned char prev_bssid[WIFI_ETH_ADDR_LEN];
    int channel;
    nxp_wifi_ie_t wpa_ie;
    unsigned char use_mfp;
    char control_port;
    bool is_ft;
} MLAN_PACK_END nxp_wifi_assoc_info_t;

#define WIFI_MAX_KEY_LEN 256U

typedef MLAN_PACK_START struct _nxp_wifi_key_info
{
    bool is_pairwise;
    int key_idx;
    unsigned char key[WIFI_MAX_KEY_LEN];
    size_t key_len;
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
} MLAN_PACK_END nxp_wifi_key_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_port_info
{
    int authorized;
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
} MLAN_PACK_END nxp_wifi_port_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_signal_info
{
    int current_signal;
    int avg_signal;
    int avg_beacon_signal;
    int current_noise;
    int current_txrate;
} MLAN_PACK_END nxp_wifi_signal_info_t;

#define WIFI_MAX_DATA_LEN 400U

typedef MLAN_PACK_START struct _nxp_wifi_mgmt_tx_info
{
    int channel;
    unsigned int wait_time;
    size_t data_len;
    unsigned char data[WIFI_MAX_DATA_LEN];
} MLAN_PACK_END nxp_wifi_mgmt_tx_info_t;

enum wifi_mode
{
    MODE_IEEE80211B,
    MODE_IEEE80211G,
    MODE_IEEE80211A,
    MODE_IEEE80211AD,
    MODE_IEEE80211ANY,
    NUM_MODES
};

typedef MLAN_PACK_START struct _nxp_wifi_chan_info
{
    enum wifi_mode mode;
    int freq;
    int channel;
    int sec_channel_offset;
    int bandwidth;
    int ht_enabled;
    int vht_enabled;
    int he_enabled;
    int center_freq1;
    int center_freq2;
} MLAN_PACK_END nxp_wifi_chan_info_t;

typedef MLAN_PACK_START struct _nxp_wifi_ap_info
{
    int beacon_set;
    unsigned char bssid[WIFI_ETH_ADDR_LEN];
    nxp_wifi_ie_t head_ie;
    nxp_wifi_ie_t tail_ie;
    int dtim_period;
    int beacon_int;
    nxp_wifi_chan_info_t chan;
    nxp_wifi_ie_t proberesp;
    nxp_wifi_ssid_t ssid;
    int hide_ssid;
    unsigned int pairwise_ciphers;
    unsigned int group_cipher;
    unsigned int key_mgmt_suites;
    unsigned int auth_algs;
    unsigned int wpa_version;
    int privacy;
    nxp_wifi_ie_t beacon_ies;
    nxp_wifi_ie_t proberesp_ies;
    nxp_wifi_ie_t assocresp_ies;
    int ht_opmode;
    int ap_max_inactivity;
    int reenable;
    int twt_responder;
    int sae_pwe;
} MLAN_PACK_END nxp_wifi_ap_info_t;

/* HT Capabilities element */
typedef MLAN_PACK_START struct _ieee80211_ht_capab
{
    unsigned short ht_capabilities_info;
    unsigned char a_mpdu_params;
    unsigned char supported_mcs_set[16];
    unsigned short ht_extended_capabilities;
    unsigned int tx_bf_capability_info;
    unsigned char asel_capabilities;
} MLAN_PACK_END ieee80211_ht_capab_t;

typedef MLAN_PACK_START struct _ieee80211_vht_capab
{
    unsigned int vht_capabilities_info;
    struct
    {
        unsigned short rx_map;
        unsigned short rx_highest;
        unsigned short tx_map;
        unsigned short tx_highest;
    } vht_supported_mcs_set;
} MLAN_PACK_END ieee80211_vht_capab_t;

typedef MLAN_PACK_START struct _ieee80211_he_capab
{
    unsigned char he_mac_capab_info[6];
    unsigned char he_phy_capab_info[11];
    unsigned char optional[37];
} MLAN_PACK_END ieee80211_he_capab_t;

typedef MLAN_PACK_START struct _nxp_wifi_sta_info
{
    unsigned char addr[WIFI_ETH_ADDR_LEN];
    unsigned short aid;
    unsigned short capability;
    unsigned char supp_rates[30];
    size_t supp_rates_len;
    unsigned short listen_interval;
    ieee80211_ht_capab_t ht_capab;
    size_t ht_capab_len;
    ieee80211_vht_capab_t vht_capab;
    size_t vht_capab_len;
    int vht_opmode_enabled;
    unsigned char vht_opmode;
    ieee80211_he_capab_t he_capab;
    size_t he_capab_len;
    unsigned int flags; /* bitmask of WPA_STA_* flags */
    int set;            /* Set STA parameters instead of add */
    unsigned char qosinfo;
    unsigned char ext_capab[10];
    size_t ext_capab_len;
} MLAN_PACK_END nxp_wifi_sta_info_t;

enum chanWidth
{
    CHAN_BAND_WIDTH_20_NOHT,
    CHAN_BAND_WIDTH_20,
    CHAN_BAND_WIDTH_40,
    CHAN_BAND_WIDTH_80,
    CHAN_BAND_WIDTH_80P80,
    CHAN_BAND_WIDTH_160,
};

typedef MLAN_PACK_START struct _nxp_wifi_ch_switch_info
{
    int center_freq;
    int ht_enabled;
    int ch_offset;
    enum chanWidth ch_width;
    int center_freq1;
    int center_freq2;
} MLAN_PACK_END nxp_wifi_ch_switch_info;

typedef MLAN_PACK_START struct _nxp_wifi_dfs_cac_info
{
    int center_freq;
    int ht_enabled;
    int ch_offset;
    enum chanWidth ch_width;
    int center_freq1;
    int center_freq2;
} MLAN_PACK_END nxp_wifi_dfs_cac_info;
/**
 * struct wifi_nxp_callbk_fns - Callback functions to be invoked by Wi-Fi driver
 * when a paticular event occurs.
 * @if_state_chg_callbk_fn: Callback function to be called when an interface
 *                          state changes.
 * @rx_frm_callbk_fn: Callback function to be called when a frame is received.
 *
 * This structure contains function pointers to all the callback functions that
 * the Wi-Fi driver needs to invoked for various events.
 */
typedef MLAN_PACK_START struct _wifi_nxp_callbk_fns
{
    void (*mac_changed_callbk_fn)(void *if_priv);

    void (*chan_list_changed_callbk_fn)(void *if_priv, const char *alpha2);

    void (*scan_start_callbk_fn)(void *if_priv);

    void (*scan_done_callbk_fn)(void *if_priv, int aborted, int external_scan);

    void (*survey_res_callbk_fn)(void *if_priv,
                                 nxp_wifi_event_new_survey_result_t *survey_res,
                                 unsigned int event_len,
                                 bool more_res);

    void (*auth_resp_callbk_fn)(void *if_priv, nxp_wifi_event_mlme_t *auth_resp_event, unsigned int event_len);

    void (*assoc_resp_callbk_fn)(void *if_priv, nxp_wifi_assoc_event_mlme_t *assoc_resp_event, unsigned int event_len);

    void (*deauth_callbk_fn)(void *if_priv, nxp_wifi_event_mlme_t *deauth_event, unsigned int event_len);

    void (*disassoc_callbk_fn)(void *if_priv, nxp_wifi_event_mlme_t *disassoc_event, unsigned int event_len);

    void (*acs_channel_sel_callbk_fn)(void *if_priv, nxp_wifi_acs_params *acs_params);

    void (*mgmt_rx_callbk_fn)(void *if_priv, nxp_wifi_event_mlme_t *mgmt_rx_event, unsigned int event_len, int rssi);
    void (*get_wiphy_callbk_fn)(void *if_priv, struct wifi_nxp_event_get_wiphy *wiphy_info, unsigned int event_len);
    void (*eapol_rx_callbk_fn)(void *if_priv, nxp_wifi_event_eapol_mlme_t *mgmt_rx_event, unsigned int event_len);
    void (*unprot_mlme_mgmt_rx_callbk_fn)(void *if_priv,
                                          nxp_wifi_event_mlme_t *unprot_mlme_event,
                                          unsigned int event_len);

    void (*mgmt_tx_status_callbk_fn)(void *if_priv, nxp_wifi_event_mlme_t *mlme_event, unsigned int event_len);
    void (*remain_on_channel_callbk_fn)(void *if_priv, int cancel_channel);
    void (*ecsa_complete_callbk_fn)(void *if_priv, nxp_wifi_ch_switch_info *ch_switch_info);
    void (*dfs_cac_started_callbk_fn)(void *if_priv, nxp_wifi_dfs_cac_info *ch_switch_info);
    void (*dfs_cac_finished_callbk_fn)(void *if_priv, nxp_wifi_dfs_cac_info *ch_switch_info);
    int (*is_supp_scan_in_progress_callbk_fn)(void *if_priv);
    void (*signal_change_callbk_fn)(void *if_priv, t_s16 *rssi);
} MLAN_PACK_END wifi_nxp_callbk_fns_t;

typedef struct _chan_to_freq_t
{
    /** Frequency */
    t_u32 freq;
    /** Channel */
    t_u16 channel;
    /** Band */
    t_u8 band;
} chan_to_freq_t;

int channel_to_frequency(t_u16 channel, t_u8 band);
t_u16 freq_to_chan(unsigned int freq);
#endif

#endif /* __WIFI_NXP_INTERNAL_H__ */