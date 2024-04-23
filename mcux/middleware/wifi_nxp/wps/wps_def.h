/** @file wps_def.h
 *
 *  @brief This file contains definitions for WPS global information.
 *
 *  Copyright 2008-2022 NXP
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
#ifdef CONFIG_WPA2_ENTP
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
    os_semaphore_t ssl_sync_sem;
    /* WPS connect network profile */
    struct wlan_network wps_conn_network;
} WPS_DATA, *PWPS_DATA;


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
#ifdef CONFIG_WPA2_ENTP
        struct wpa2_command entp_cmd;
#endif
    } cmd;
};


#endif /* _WPS_DEF_H_ */
