/*
 * WPA definitions shared between hostapd and wpa_supplicant
 * Copyright (c) 2002-2015, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

/**
 *  Copyright 2003-2022 NXP
 */

#ifndef _WPS_EAPOL_H_
#define _WPS_EAPOL_H_

#include "wps_def.h"
#include "wifi_nxp_wps.h"

#define WPA_PROTO_WPA BIT(0)
#define WPA_PROTO_RSN BIT(1)

#define WPA_CIPHER_NONE   BIT(0)
#define WPA_CIPHER_WEP40  BIT(1)
#define WPA_CIPHER_WEP104 BIT(2)
#define WPA_CIPHER_TKIP   BIT(3)
#define WPA_CIPHER_CCMP   BIT(4)
#ifdef CONFIG_IEEE80211W
#define WPA_CIPHER_AES_128_CMAC BIT(5)
#endif /* CONFIG_IEEE80211W */
#define WPA_CIPHER_GCMP BIT(6)
#define WPA_CIPHER_SMS4 BIT(7)

#define WPA_KEY_MGMT_IEEE8021X        BIT(0)
#define WPA_KEY_MGMT_PSK              BIT(1)
#define WPA_KEY_MGMT_NONE             BIT(2)
#define WPA_KEY_MGMT_IEEE8021X_NO_WPA BIT(3)
#define WPA_KEY_MGMT_WPA_NONE         BIT(4)
#define WPA_KEY_MGMT_FT_IEEE8021X     BIT(5)
#define WPA_KEY_MGMT_FT_PSK           BIT(6)
#define WPA_KEY_MGMT_IEEE8021X_SHA256 BIT(7)
#define WPA_KEY_MGMT_PSK_SHA256       BIT(8)
#define WPA_KEY_MGMT_WPS              BIT(9)
#define WPA_KEY_MGMT_SAE              BIT(10)
#define WPA_KEY_MGMT_FT_SAE           BIT(11)
#define WPA_KEY_MGMT_WAPI_PSK         BIT(12)
#define WPA_KEY_MGMT_WAPI_CERT        BIT(13)
#define WPA_KEY_MGMT_CCKM             BIT(14)

/** IEEE 802.1x header */
struct ieee802_1x_hdr
{
    /** Version */
    u8 version;
    /** Type */
    u8 type;
    /** Length */
    u16 length;
    /* followed by length octets of data */
} __attribute__((packed));

#define EAPOL_VERSION 2

enum
{
    IEEE802_1X_TYPE_EAP_PACKET                   = 0,
    IEEE802_1X_TYPE_EAPOL_START                  = 1,
    IEEE802_1X_TYPE_EAPOL_LOGOFF                 = 2,
    IEEE802_1X_TYPE_EAPOL_KEY                    = 3,
    IEEE802_1X_TYPE_EAPOL_ENCAPSULATED_ASF_ALERT = 4
};

enum
{
    EAPOL_KEY_TYPE_RC4 = 1,
    EAPOL_KEY_TYPE_RSN = 2,
    EAPOL_KEY_TYPE_WPA = 254
};

enum wpa_alg
{
    WPA_ALG_NONE,
    WPA_ALG_WEP,
    WPA_ALG_TKIP,
    WPA_ALG_CCMP,
    WPA_ALG_IGTK,
    WPA_ALG_PMK,
    WPA_ALG_GCMP,
    WPA_ALG_SMS4,
    WPA_ALG_KRK
};

#define IEEE8021X_REPLAY_COUNTER_LEN 8
#define IEEE8021X_KEY_SIGN_LEN       16
#define IEEE8021X_KEY_IV_LEN         16

#define IEEE8021X_KEY_INDEX_FLAG 0x80
#define IEEE8021X_KEY_INDEX_MASK 0x03

struct ieee802_1x_eapol_key
{
    u8 type;
    /* Note: key_length is unaligned */
    u8 key_length[2];
    /* does not repeat within the life of the keying material used to
     * encrypt the Key field; 64-bit NTP timestamp MAY be used here */
    u8 replay_counter[IEEE8021X_REPLAY_COUNTER_LEN];
    u8 key_iv[IEEE8021X_KEY_IV_LEN]; /* cryptographically random number */
    u8 key_index;                    /* key flag in the most significant bit:
                                      * 0 = broadcast (default key),
                                      * 1 = unicast (key mapping key); key index is in the
                                      * 7 least significant bits */
    /* HMAC-MD5 message integrity check computed with MS-MPPE-Send-Key as
     * the key */
    u8 key_signature[IEEE8021X_KEY_SIGN_LEN];

    /* followed by key: if packet body length = 44 + key length, then the
     * key field (of key_length bytes) contains the key in encrypted form;
     * if packet body length = 44, key field is absent and key_length
     * represents the number of least significant octets from
     * MS-MPPE-Send-Key attribute to be used as the keying material;
     * RC4 key used in encryption = Key-IV + MS-MPPE-Recv-Key */
} __attribute__((packed));

/* IEEE 802.11i */
#define PMKID_LEN              16
#define PMK_LEN                32
#define WPA_REPLAY_COUNTER_LEN 8
#define WPA_NONCE_LEN          32
#define WPA_KEY_RSC_LEN        8
#define WPA_GMK_LEN            32
#define WPA_GTK_MAX_LEN        32

#define WPA_SELECTOR_LEN 4
#define WPA_VERSION      1
#define RSN_SELECTOR_LEN 4
#define RSN_VERSION      1

#define RSN_SELECTOR(a, b, c, d) ((((u32)(a)) << 24) | (((u32)(b)) << 16) | (((u32)(c)) << 8) | (u32)(d))

#define WPA_AUTH_KEY_MGMT_NONE            RSN_SELECTOR(0x00, 0x50, 0xf2, 0)
#define WPA_AUTH_KEY_MGMT_UNSPEC_802_1X   RSN_SELECTOR(0x00, 0x50, 0xf2, 1)
#define WPA_AUTH_KEY_MGMT_PSK_OVER_802_1X RSN_SELECTOR(0x00, 0x50, 0xf2, 2)
#define WPA_AUTH_KEY_MGMT_CCKM            RSN_SELECTOR(0x00, 0x40, 0x96, 0)
#define WPA_CIPHER_SUITE_NONE             RSN_SELECTOR(0x00, 0x50, 0xf2, 0)
#define WPA_CIPHER_SUITE_WEP40            RSN_SELECTOR(0x00, 0x50, 0xf2, 1)
#define WPA_CIPHER_SUITE_TKIP             RSN_SELECTOR(0x00, 0x50, 0xf2, 2)
#if 0
#define WPA_CIPHER_SUITE_WRAP RSN_SELECTOR(0x00, 0x50, 0xf2, 3)
#endif
#define WPA_CIPHER_SUITE_CCMP   RSN_SELECTOR(0x00, 0x50, 0xf2, 4)
#define WPA_CIPHER_SUITE_WEP104 RSN_SELECTOR(0x00, 0x50, 0xf2, 5)

#define RSN_AUTH_KEY_MGMT_UNSPEC_802_1X   RSN_SELECTOR(0x00, 0x0f, 0xac, 1)
#define RSN_AUTH_KEY_MGMT_PSK_OVER_802_1X RSN_SELECTOR(0x00, 0x0f, 0xac, 2)
#define RSN_AUTH_KEY_MGMT_802_1X_SHA256   RSN_SELECTOR(0x00, 0x0f, 0xac, 5)
#define RSN_AUTH_KEY_MGMT_PSK_SHA256      RSN_SELECTOR(0x00, 0x0f, 0xac, 6)
#define RSN_AUTH_KEY_MGMT_TPK_HANDSHAKE   RSN_SELECTOR(0x00, 0x0f, 0xac, 7)
#define RSN_AUTH_KEY_MGMT_SAE             RSN_SELECTOR(0x00, 0x0f, 0xac, 8)
#define RSN_AUTH_KEY_MGMT_FT_SAE          RSN_SELECTOR(0x00, 0x0f, 0xac, 9)
#define RSN_AUTH_KEY_MGMT_CCKM            RSN_SELECTOR(0x00, 0x40, 0x96, 0x00)

#define RSN_CIPHER_SUITE_NONE  RSN_SELECTOR(0x00, 0x0f, 0xac, 0)
#define RSN_CIPHER_SUITE_WEP40 RSN_SELECTOR(0x00, 0x0f, 0xac, 1)
#define RSN_CIPHER_SUITE_TKIP  RSN_SELECTOR(0x00, 0x0f, 0xac, 2)
#if 0
#define RSN_CIPHER_SUITE_WRAP RSN_SELECTOR(0x00, 0x0f, 0xac, 3)
#endif
#define RSN_CIPHER_SUITE_CCMP               RSN_SELECTOR(0x00, 0x0f, 0xac, 4)
#define RSN_CIPHER_SUITE_WEP104             RSN_SELECTOR(0x00, 0x0f, 0xac, 5)
#define RSN_CIPHER_SUITE_NO_GROUP_ADDRESSED RSN_SELECTOR(0x00, 0x0f, 0xac, 7)
#define RSN_CIPHER_SUITE_GCMP               RSN_SELECTOR(0x00, 0x0f, 0xac, 8)

/* EAPOL-Key Key Data Encapsulation
 * GroupKey and PeerKey require encryption, otherwise, encryption is optional.
 */
#define RSN_KEY_DATA_GROUPKEY RSN_SELECTOR(0x00, 0x0f, 0xac, 1)
#if 0
#define RSN_KEY_DATA_STAKEY RSN_SELECTOR(0x00, 0x0f, 0xac, 2)
#endif
#define RSN_KEY_DATA_MAC_ADDR RSN_SELECTOR(0x00, 0x0f, 0xac, 3)
#define RSN_KEY_DATA_PMKID    RSN_SELECTOR(0x00, 0x0f, 0xac, 4)
#ifdef CONFIG_PEERKEY
#define RSN_KEY_DATA_SMK      RSN_SELECTOR(0x00, 0x0f, 0xac, 5)
#define RSN_KEY_DATA_NONCE    RSN_SELECTOR(0x00, 0x0f, 0xac, 6)
#define RSN_KEY_DATA_LIFETIME RSN_SELECTOR(0x00, 0x0f, 0xac, 7)
#define RSN_KEY_DATA_ERROR    RSN_SELECTOR(0x00, 0x0f, 0xac, 8)
#endif /* CONFIG_PEERKEY */
#define RSN_KEY_DATA_KEYID           RSN_SELECTOR(0x00, 0x0f, 0xac, 10)
#define RSN_KEY_DATA_MULTIBAND_GTK   RSN_SELECTOR(0x00, 0x0f, 0xac, 11)
#define RSN_KEY_DATA_MULTIBAND_KEYID RSN_SELECTOR(0x00, 0x0f, 0xac, 12)

#define WPA_OUI_TYPE RSN_SELECTOR(0x00, 0x50, 0xf2, 1)

#define RSN_SELECTOR_PUT(a, val) WPA_PUT_BE32((u8 *)(a), (val))
#define RSN_SELECTOR_GET(a)      WPA_GET_BE32((const u8 *)(a))

#define RSN_NUM_REPLAY_COUNTERS_1  0
#define RSN_NUM_REPLAY_COUNTERS_2  1
#define RSN_NUM_REPLAY_COUNTERS_4  2
#define RSN_NUM_REPLAY_COUNTERS_16 3

/* IEEE 802.11, 7.3.2.25.3 RSN Capabilities */
#define WPA_CAPABILITY_PREAUTH     BIT(0)
#define WPA_CAPABILITY_NO_PAIRWISE BIT(1)
/* B2-B3: PTKSA Replay Counter */
/* B4-B5: GTKSA Replay Counter */
#define WPA_CAPABILITY_MFPR BIT(6)
#define WPA_CAPABILITY_MFPC BIT(7)
/* B8: Reserved */
#define WPA_CAPABILITY_PEERKEY_ENABLED        BIT(9)
#define WPA_CAPABILITY_SPP_A_MSDU_CAPABLE     BIT(10)
#define WPA_CAPABILITY_SPP_A_MSDU_REQUIRED    BIT(11)
#define WPA_CAPABILITY_PBAC                   BIT(12)
#define WPA_CAPABILITY_EXT_KEY_ID_FOR_UNICAST BIT(13)
/* B14-B15: Reserved */

/* IEEE 802.11r */
#define MOBILITY_DOMAIN_ID_LEN 2
#define FT_R0KH_ID_MAX_LEN     48
#define FT_R1KH_ID_LEN         6
#define WPA_PMK_NAME_LEN       16

/* IEEE 802.11, 8.5.2 EAPOL-Key frames */
#define WPA_KEY_INFO_TYPE_MASK          ((u16)(BIT(0) | BIT(1) | BIT(2)))
#define WPA_KEY_INFO_TYPE_HMAC_MD5_RC4  BIT(0)
#define WPA_KEY_INFO_TYPE_HMAC_SHA1_AES BIT(1)
#define WPA_KEY_INFO_TYPE_AES_128_CMAC  3
#define WPA_KEY_INFO_KEY_TYPE           BIT(3) /* 1 = Pairwise, 0 = Group key */
/* bit4..5 is used in WPA, but is reserved in IEEE 802.11i/RSN */
#define WPA_KEY_INFO_KEY_INDEX_MASK  (BIT(4) | BIT(5))
#define WPA_KEY_INFO_KEY_INDEX_SHIFT 4
#define WPA_KEY_INFO_INSTALL         BIT(6) /* pairwise */
#define WPA_KEY_INFO_TXRX            BIT(6) /* group */
#define WPA_KEY_INFO_ACK             BIT(7)
#define WPA_KEY_INFO_MIC             BIT(8)
#define WPA_KEY_INFO_SECURE          BIT(9)
#define WPA_KEY_INFO_ERROR           BIT(10)
#define WPA_KEY_INFO_REQUEST         BIT(11)
#define WPA_KEY_INFO_ENCR_KEY_DATA   BIT(12) /* IEEE 802.11i/RSN only */
#define WPA_KEY_INFO_SMK_MESSAGE     BIT(13)

/**
 * struct wpa_ptk - WPA Pairwise Transient Key
 * IEEE Std 802.11i-2004 - 8.5.1.2 Pairwise key hierarchy
 */
struct wpa_ptk
{
    u8 kck[16]; /* EAPOL-Key Key Confirmation Key (KCK) */
    u8 kek[16]; /* EAPOL-Key Key Encryption Key (KEK) */
    u8 tk1[16]; /* Temporal Key 1 (TK1) */
    union
    {
        u8 tk2[16]; /* Temporal Key 2 (TK2) */
        struct
        {
            u8 tx_mic_key[8];
            u8 rx_mic_key[8];
        } auth;
    } u;
} __attribute__((packed));

/**
 * struct wpa_sm - Internal WPA state machine data
 */
typedef struct wpa_sm
{
    u8 pmk[PMK_LEN];
    size_t pmk_len;
    struct wpa_ptk ptk, tptk;
    int ptk_set, tptk_set;
    u8 snonce[WPA_NONCE_LEN];
    u8 anonce[WPA_NONCE_LEN]; /* ANonce from the last 1/4 msg */
    int renew_snonce;
    u8 rx_replay_counter[WPA_REPLAY_COUNTER_LEN];
    int rx_replay_counter_set;
    u8 request_counter[WPA_REPLAY_COUNTER_LEN];

    u8 own_addr[ETH_ALEN];
    u8 bssid[ETH_ALEN];

    /* Selected configuration (based on Beacon/ProbeResp WPA IE) */
    unsigned int proto;
    unsigned int pairwise_cipher;
    unsigned int group_cipher;
    unsigned int key_mgmt;
    unsigned int mgmt_group_cipher;

    int rsn_enabled; /* Whether RSN is enabled in configuration */
    int mfp;         /* 0 = disabled, 1 = optional, 2 = mandatory */

    u8 *assoc_wpa_ie; /* Own WPA/RSN IE from (Re)AssocReq */
    size_t assoc_wpa_ie_len;
    u8 *ap_wpa_ie, *ap_rsn_ie;
    size_t ap_wpa_ie_len, ap_rsn_ie_len;
} __attribute__((packed)) WPA_SM, *PWPA_SM;

struct wpa_eapol_key
{
    u8 type;
    /* Note: key_info, key_length, and key_data_length are unaligned */
    u8 key_info[2];   /* big endian */
    u8 key_length[2]; /* big endian */
    u8 replay_counter[WPA_REPLAY_COUNTER_LEN];
    u8 key_nonce[WPA_NONCE_LEN];
    u8 key_iv[16];
    u8 key_rsc[WPA_KEY_RSC_LEN];
    u8 key_id[8]; /* Reserved in IEEE 802.11i/RSN */
    u8 key_mic[16];
    u8 key_data_length[2]; /* big endian */
    /* followed by key_data_length bytes of key_data */
} __attribute__((packed));

/* WPA IE version 1
 * 00-50-f2:1 (OUI:OUI type)
 * 0x01 0x00 (version; little endian)
 * (all following fields are optional:)
 * Group Suite Selector (4 octets) (default: TKIP)
 * Pairwise Suite Count (2 octets, little endian) (default: 1)
 * Pairwise Suite List (4 * n octets) (default: TKIP)
 * Authenticated Key Management Suite Count (2 octets, little endian)
 *    (default: 1)
 * Authenticated Key Management Suite List (4 * n octets)
 *    (default: unspec 802.1X)
 * WPA Capabilities (2 octets, little endian) (default: 0)
 */

struct wpa_ie_hdr
{
    u8 elem_id;
    u8 len;
    u8 oui[4];     /* 24-bit OUI followed by 8-bit OUI type */
    u8 version[2]; /* little endian */
} __attribute__((packed));

/* 1/4: PMKID
 * 2/4: RSN IE
 * 3/4: one or two RSN IEs + GTK IE (encrypted)
 * 4/4: empty
 * 1/2: GTK IE (encrypted)
 * 2/2: empty
 */

/* RSN IE version 1
 * 0x01 0x00 (version; little endian)
 * (all following fields are optional:)
 * Group Suite Selector (4 octets) (default: CCMP)
 * Pairwise Suite Count (2 octets, little endian) (default: 1)
 * Pairwise Suite List (4 * n octets) (default: CCMP)
 * Authenticated Key Management Suite Count (2 octets, little endian)
 *    (default: 1)
 * Authenticated Key Management Suite List (4 * n octets)
 *    (default: unspec 802.1X)
 * RSN Capabilities (2 octets, little endian) (default: 0)
 * PMKID Count (2 octets) (default: 0)
 * PMKID List (16 * n octets)
 * Management Group Cipher Suite (4 octets) (default: AES-128-CMAC)
 */

struct rsn_ie_hdr
{
    u8 elem_id; /* WLAN_EID_RSN */
    u8 len;
    u8 version[2]; /* little endian */
} __attribute__((packed));

#ifdef CONFIG_PEERKEY
enum
{
    STK_MUI_4WAY_STA_AP   = 1,
    STK_MUI_4WAY_STAT_STA = 2,
    STK_MUI_GTK           = 3,
    STK_MUI_SMK           = 4
};

enum
{
    STK_ERR_STA_NR   = 1,
    STK_ERR_STA_NRSN = 2,
    STK_ERR_CPHR_NS  = 3,
    STK_ERR_NO_STSL  = 4
};
#endif /* CONFIG_PEERKEY */

int wpa_eapol_key_mic(const u8 *key, int ver, const u8 *buf, size_t len, u8 *mic);
void wpa_pmk_to_ptk(const u8 *pmk,
                    size_t pmk_len,
                    const char *label,
                    const u8 *addr1,
                    const u8 *addr2,
                    const u8 *nonce1,
                    const u8 *nonce2,
                    u8 *ptk,
                    size_t ptk_len,
                    int use_sha256);

struct wpa_ie_data
{
    int proto;
    int pairwise_cipher;
    int group_cipher;
    int key_mgmt;
    int capabilities;
    size_t num_pmkid;
    const u8 *pmkid;
    int mgmt_group_cipher;
} __attribute__((packed));

static inline int wpa_key_mgmt_sha256(int akm)
{
    return !!(akm & (WPA_KEY_MGMT_PSK_SHA256 | WPA_KEY_MGMT_IEEE8021X_SHA256));
}

int wpa_rx_eapol(const u8 *src_addr, const u8 *buf, size_t len);

void wps_rx_eapol(const u8 *src_addr, const u8 *buf, size_t len);
int wps_eapol_send(int type, u8 *buf, size_t len);
int wps_eapol_txStart(void);
int wps_eapol_txPacket(u8 *buf, size_t len);
void WPSEAPoLRxDataHandler(const u8 *buf, const size_t len);
int WPSEAPoLSSLTxDataHandler(u8 *buf, size_t len);
int WPSEAPoLSSLRxDataHandler(u8 *buf, size_t *len);
void wpa2_session_success();
#endif /* _WPS_EAPOL_H_ */
