/** @file wps_def.h
 *
 *  @brief This file contains definitions for WPS global information.
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _WPS_DEF_H_
#define _WPS_DEF_H_

#include <stdint.h>
#include <wlan.h>

#ifndef MIN
/** Macro to get minimun number */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif /* MIN */

#ifndef MAX
/** Macro to get maximun number */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef NELEMENTS
/** Number of elements in aray x */
#define NELEMENTS(x) (sizeof(x) / sizeof(x[0]))
#endif

/** Unsigned character, 1 byte */
#define u8 uint8_t
/** Unsigned character, 2 byte */
#define u16 uint16_t
/** Unsigned character, 4 byte */
#define u32 uint32_t
/** Unsigned character, 8 byte */
#define u64 uint64_t
/** Signed character, 1 byte */
#define s8 int8_t
/** Signed character, 2 byte */
#define s16 int16_t
/** Signed character, 4 byte */
#define s32 int32_t
/** Signed character, 8 byte */
#define s64 int64_t

#ifndef ETH_ALEN
/** Ethernet address length */
#define ETH_ALEN 6
#endif

/** Maximum SSID length */
#define MAX_SSID_LEN 32

/** Return type: success */
#define WPS_STATUS_SUCCESS (0)
/** Return type: failure */
#define WPS_STATUS_FAIL (-1)

/** WPS Set */
#define WPS_SET 1
/** WPS Cancel */
#define WPS_CANCEL 0

/** Action SET */
#ifndef ACTION_GET
#define ACTION_GET (0U)
#endif
/** Action GET */
#ifndef ACTION_SET
#define ACTION_SET (1)
#endif

/** Discovery phase : Start */
#define WPS_START_REG_DISCOVERY_PHASE 1
/** Discovery phase : End */
#define WPS_END_REG_DISCOVERY_PHASE 0

/** BSS type : STA */
#ifndef BSS_TYPE_STA
#define BSS_TYPE_STA 0U
#endif
/** BSS type : UAP */
#ifndef BSS_TYPE_UAP
#define BSS_TYPE_UAP 1U
#endif
/** BSS type : WFD */
#ifndef BSS_TYPE_WFD
#define BSS_TYPE_WFD 2
#endif

#define MSCHAPV2_CHAL_LEN          16
#define MSCHAPV2_NT_RESPONSE_LEN   24
#define MSCHAPV2_AUTH_RESPONSE_LEN 20
#define MSCHAPV2_MASTER_KEY_LEN    16

#define EAP_TLV_RESULT_SUCCESS 1
#define EAP_TLV_RESULT_FAILURE 2

/** Device password: PIN ID */
#define DEVICE_PASSWORD_ID_PIN 0x0000
/** Device password: Push Button */
#define DEVICE_PASSWORD_PUSH_BUTTON 0x0004
/** Device password: Registrar Specified */
#define DEVICE_PASSWORD_REG_SPECIFIED 0x0005
/** Device password: SMPBC */
#define DEVICE_PASSWORD_SMPBC 0x0006

/** Maximum WFD devices in Find phase */
#define WFD_MAX_FIND_DEVICES 10
/** Maximum WFD devices in Find phase */
#define WFD_MAX_VALID_FIND_DEVICES 10
/** Maximum WFD device name length */
#define MAX_DEVICE_NAME_LEN 32
/** WPS Device Type Length */
#define WPS_DEVICE_TYPE_LEN 8

/** Maximum event buffer size */
#define EVENT_MAX_BUF_SIZE 1024

/** Role enrollee after discovery */
#define IS_DISCOVERY_ENROLLEE(gpwps) \
    (((gpwps)->role == WPS_ADHOC_EXTENTION || (gpwps)->role == WFD_ROLE) && (gpwps)->discovery_role == WPS_ENROLLEE)
/** Role registrar after discovery */
#define IS_DISCOVERY_REGISTRAR(gpwps) \
    (((gpwps)->role == WPS_ADHOC_EXTENTION || (gpwps)->role == WFD_ROLE) && (gpwps)->discovery_role == WPS_REGISTRAR)

typedef struct wps_ssid
{
    /** SSID */
    u8 ssid[MAX_SSID_LEN];
    /** SSID Length */
    size_t ssid_len;
    /** BSSID */
    u8 bssid[ETH_ALEN];
    /*
     * mode - IEEE 802.11 operation mode (Infrastructure/IBSS)
     * 0 = infrastructure (Managed) mode, i.e., associate with an AP.
     * 1 = IBSS (ad-hoc, peer-to-peer)
     */
    /** IEEE 802.11 operation mode (Infrastructure/IBSS) */
    int mode;
} WPS_SSID, *PWPS_SSID;

typedef struct wps_l2_info
{
    /** Interface name */
    char ifname[17];
    /** MAC Address */
    u8 my_mac_addr[6];
} WPS_L2_INFO;

#if CONFIG_P2P
/** Maximum no of channels in channel list */
#define MAX_CHANNELS 14

/** chan_list data structure */
typedef struct _channel_list
{
    /** Number of channel */
    u32 num_of_chan;
    /** Channel number*/
    u16 chan[MAX_CHANNELS];
} channel_list;

/** Wfd Device Information to display */
typedef struct wfd_device_results
{
    /** Group capability */
    u8 group_capability;
    /** Device Identifier ; Interface address */
    u8 device_id[ETH_ALEN];
    /** Device address in deviceInfo */
    u8 device_address[ETH_ALEN];
    /** WFD GO SSID */
    u8 go_ssid[MAX_SSID_LEN + 1];
    /** Intended address from Peer */
    u8 intended_address[ETH_ALEN];
    /** is device valid */
    u8 is_valid;
    /** Operating channel */
    int op_channel;
    /** Listen channel */
    int listen_channel;
    /** Peer channel list */
    channel_list peer_channel_list;
    /** Last event timestamp */
    time_t timestamp;
} WFD_DEVICE_RESULTS, *PWFD_DEVICE_RESULTS;

typedef struct wfd_data
{
    /** Find Results */
    WFD_DEVICE_RESULTS find_results[WFD_MAX_FIND_DEVICES];
    /** Valid Find Results */
    struct p2p_scan_result valid_find_results[WFD_MAX_VALID_FIND_DEVICES];
    /** number of find results */
    int num_find_results;
    /** current Device index */
    int dev_index;
    /** Self channel list */
    channel_list self_channel_list;
    /** Device found or not */
    int dev_found;
    /** Default scan */
    int default_scan;
    /** Valid devices */
    int valid_devices;
} WFD_DATA, *PWFD_DATA;
#endif

#define TLS_KEY_LEN 32

typedef struct wps_data
{
    /** Layer 2 Info */
    WPS_L2_INFO *l2;
    /** event Info */
    int evt_fd;
    /** IO vector */
    void *evt_iov;
    /** event netlink header */
    void *evt_nl_head;
    /** event messsage header */
    void *evt_msg_head;
    /** event destination address */
    void *evt_dest_addr;
#if CONFIG_P2P
    /** WFD data pointer */
    WFD_DATA wfd_data;
#endif
    /** MAC Address */
    u8 my_mac_addr[ETH_ALEN];
    /** Interface name */
    char ifname[17];
    /** Bridge name */
    char brname[17];
    /** WPS non interactive FD */
    int non_int_fd;
    /** BSS type */
    int bss_type;
    /** BSSID */
    u8 bssid[ETH_ALEN];
    /** WPS SSID */
    WPS_SSID current_ssid;
    /** User abort flag */
    u8 userAbort;
    /** number of EAPOL packets received after
    the previous association event */
    int eapol_received;
    /* WPA2 network profile */
    struct wlan_network wpa2_network;
    /* TLS Session initialization flag */
    bool tls_session_init;
    /* TLS Session active flag */
    bool tls_session_active;
#if CONFIG_WPA2_ENTP
    /* Derived key data */
    uint8_t key_data[TLS_KEY_LEN];
    u8 peer_challenge[MSCHAPV2_CHAL_LEN];
    u8 nt_response[MSCHAPV2_NT_RESPONSE_LEN];
    u8 auth_response[MSCHAPV2_AUTH_RESPONSE_LEN];
    u8 master_key[MSCHAPV2_MASTER_KEY_LEN];
#endif
    /* TLS session key valid */
    bool tls_session_key_valid;
    /* TLS socket */
    int sockfd;
    /** Sync semaphore */
    osa_semaphore_handle_t ssl_sync_sem;
    /* WPS connect network profile */
    struct wlan_network wps_conn_network;
} WPS_DATA, *PWPS_DATA;

#if CONFIG_P2P
/** Maximum Persistent peers possible in a group */
#define WFD_MAX_PERSISTENT_PEERS (2)
/** PSK max len */
#define WFD_PSK_LEN_MAX (64)

/** User Persistent record format  */
typedef struct
{
    /* Index of record */
    s8 index;
    /* Device role */
    u8 dev_role;
    /* BSSID */
    u8 bssid[ETH_ALEN];
    /* Group device ID */
    u8 groupdevid[ETH_ALEN];
    /* SSID length */
    u8 ssid_len;
    /* SSID */
    u8 ssid[MAX_SSID_LEN];
    /* PSK length */
    u8 psk_len;
    /* PSK */
    u8 psk[WFD_PSK_LEN_MAX];
    /* Number of Peers */
    u8 num_peers;
    /* List of Peers */
    u8 peers[WFD_MAX_PERSISTENT_PEERS][ETH_ALEN];
} wfd_persistent_record;
#endif

struct wps_msg
{
    void *mac;
    u16 len;
    void *buffer;
    int new_msg_type;
};

struct wps_command
{
    /** WPS command */
    int command;
    /** Wireless network configuration to start WPS session attempt*/
    struct wlan_scan_result res;
    /** 4 or 8 digit PIN for WPS PIN mode, ignored for PBC */
    uint32_t wps_pin;
};

struct wpa2_command
{
    /** Wireless network configuration to start WPS session attempt*/
    struct wlan_network wpa2_network;
};

struct prov_command
{
    u8 prov_session;
    union
    {
        struct wps_command wps_cmd;
#if CONFIG_WPA2_ENTP
        struct wpa2_command entp_cmd;
#endif
    } cmd;
};

#if CONFIG_P2P
struct wfd_wlan_event
{
    bool peer_event;
    bool action_frame;
    void *buffer;
};

void wfd_cfg_cmd_provisioning_params(u16 action, u16 config_method, u16 dev_password);
void wfd_cfg_cmd_wps_params(u16 action, char *wps_param);
#endif

#endif /* _WPS_DEF_H_ */
