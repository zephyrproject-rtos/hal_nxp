/** @file wps_wlan.c
 *
 *  @brief This file contains functions for WLAN driver control/command
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <wifi.h>
#include <mlan_api.h>
#include <wm_net.h>
#include "wifi_nxp_wps.h"

#include "wps_mem.h"
#include "wps_msg.h"
#include "wps_def.h"
#include "wps_wlan.h"
#include "wps_os.h"

/* fixme: Duplicated macros. remove when possible */
/** TLV : SSID */
#define MRVL_SSID_TLV_ID 0x0000
/** TLV type ID definition */
#ifndef PROPRIETARY_TLV_BASE_ID
#define PROPRIETARY_TLV_BASE_ID 0x0100U
#endif
/** TLV : WPA passphrase */
#define MRVL_WPA_PASSPHRASE_TLV_ID (PROPRIETARY_TLV_BASE_ID + 0x3c)
#define TLV_HEADER_SIZE            4

extern mlan_status wrapper_wlan_cmd_mgmt_ie(int bss_type, void *buffer, unsigned int len, t_u16 action);

#if CONFIG_P2P
extern struct wps_thread_t wps;
/** Global pwps information */
extern PWPS_INFO gpwps_info;

extern struct wlan_network p2p_uap_network;
extern struct wlan_network p2p_network;
#endif

/*
 *  @brief convert hex char to integer
 *
 *  @param c        Hex char
 *  @return         Integer value or WPS_STATUS_FAIL
 */
static int hex2num(s8 c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return WPS_STATUS_FAIL;
}

/*
 *  @brief convert integer to hex char
 *
 *  @param c        Integer value or WPS_STATUS_FAIL
 *  @return         Hex char
 */

int num2hex(s8 c)
{
    if ((c + '0') >= '0' && (c + '0') <= '9')
        return c + '0';
    if ((c - 10 + 'a') >= 'a' && (c - 10 + 'a') <= 'f')
        return c - 10 + 'a';
    if ((c - 10 + 'A') >= 'A' && (c - 10 + 'A') <= 'F')
        return c - 10 + 'A';
    return WPS_STATUS_FAIL;
}

/*
 *  @brief convert hex char to integer
 *
 *  @param c        char
 *  @return         Integer value or WPS_STATUS_FAIL
 */
static int hex2byte(const s8 *hex)
{
    s32 a, b;
    a = hex2num(*hex++);
    if (a < 0)
        return WPS_STATUS_FAIL;
    b = hex2num(*hex++);
    if (b < 0)
        return WPS_STATUS_FAIL;
    return (a << 4) | b;
}

/*
 *  @brief convert hex char to integer
 *
 *  @param hex      A pointer to hex string
 *  @param buf      buffer to storage the data
 *  @param len
 *  @return         WPS_STATUS_SUCCESS--success, otherwise --fail
 */
int hexstr2bin(const s8 *hex, u8 *buf, size_t len)
{
    s32 i, a;
    const s8 *ipos = hex;
    u8 *opos       = buf;

    for (i = 0; i < len; i++)
    {
        a = hex2byte(ipos);
        if (a < 0)
            return WPS_STATUS_FAIL;
        *opos++ = a;
        ipos += 2;
    }
    return WPS_STATUS_SUCCESS;
}

/*
 *  @brief convert binary data to Hex string
 *
 *  @param bin      A pointer to binary data
 *  @param hex      A pointer to hex string
 *  @param len
 *  @return         WPS_STATUS_SUCCESS--success, otherwise --fail
 */

int bin2hexstr(const u8 *bin, s8 *hex, size_t len)
{
    s32 i;

    for (i = 0; i < len; i++)
    {
        hex[2 * i]       = num2hex(bin[i] >> 4);
        hex[(2 * i) + 1] = num2hex(bin[i] & 0x0f);
    }

    return WPS_STATUS_SUCCESS;
}

#if CONFIG_P2P
/** uAP Protocol: Open */
#define UAP_PROTO_OPEN 1
/** uAP Protocol: WEP Static */
#define UAP_PROTO_WEP_STATIC 2
/** uAP Protocol: WPA */
#define UAP_PROTO_WPA 8
/** uAP Protocol: WPA2 */
#define UAP_PROTO_WPA2 32
/** uAP Protocol: WPA+WPA2 */
#define UAP_PROTO_MIXED 40

/** uAP Auth Mode: Open */
#define UAP_AUTH_MODE_OPEN 0
/** uAP Auth Mode: Shared Key */
#define UAP_AUTH_MODE_SHARED 1

/** uAP Cipher: None */
#define UAP_CIPH_NONE 0
/** uAP Cipher: TKIP */
#define UAP_CIPH_TKIP 4
/** uAP Cipher: AES */
#define UAP_CIPH_AES 8
/** uAP Cipher:  AES+TKIP*/
#define UAP_CIPH_AES_TKIP 12

/**
 *  @brief Set the BSS information into the registrar credential structure
 *  @param wps_s     A pointer to the WPS_DATA structure
 *  @param pwps_info A pointer to the PWPS_INFO structure
 *  @param bss       BSS information
 *
 *  @return          WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int load_cred_info(WPS_DATA *wps_s, PWPS_INFO pwps_info, bss_config_t *bss)
{
    int i, ret = WPS_STATUS_SUCCESS;
    CREDENTIAL_DATA *reg_cred = NULL, *enr_cred = NULL;
    MESSAGE_ENROLLEE_REGISTRAR *enr_reg = NULL, *enrollee_info = NULL;
    u8 cipher = 0;
    u8 mac[6];

    ENTER();

    if (!bss)
    {
        wps_d("BSS info is not present");
        ret = WPS_STATUS_FAIL;
    }

    enr_reg  = &pwps_info->registrar;
    reg_cred = &enr_reg->cred_data[0];

    enrollee_info = &pwps_info->enrollee;
    enr_cred      = &enrollee_info->cred_data[0];

    wlan_get_wfd_mac_address(mac);

    (void)memset(&p2p_uap_network, 0, sizeof(struct wlan_network));

    /* Set profile name */
    (void)memcpy(p2p_uap_network.bssid, mac, ETH_ALEN);
    /* Set profile name */
    strcpy(p2p_uap_network.name, "p2p-uap-network");
    /* Set channel selection to auto (0) */
    p2p_uap_network.channel = 0;
    /* Set network type to uAP */
    p2p_uap_network.type = WLAN_BSS_TYPE_WIFIDIRECT;
    /* Set network role to uAP */
    p2p_uap_network.role = WLAN_BSS_ROLE_UAP;
    /* Set IP address to 192.168.10.1 */
    p2p_uap_network.ip.ipv4.address = htonl(0xc0a83101UL);
    /* Set default gateway to 192.168.10.1 */
    p2p_uap_network.ip.ipv4.gw = htonl(0xc0a83101UL);
    /* Set netmask to 255.255.255.0 */
    p2p_uap_network.ip.ipv4.netmask = htonl(0xffffff00UL);
    /* Specify address type as static assignment */
    p2p_uap_network.ip.ipv4.addr_type = ADDR_TYPE_STATIC;

    (void)memset(reg_cred, 0, sizeof(CREDENTIAL_DATA));
    if (bss->ssid.ssid_len)
    {
        (void)memcpy(reg_cred->ssid, bss->ssid.ssid, bss->ssid.ssid_len);
        reg_cred->ssid_length = bss->ssid.ssid_len;
        (void)memcpy(wps_s->current_ssid.ssid, bss->ssid.ssid, bss->ssid.ssid_len);
        wps_s->current_ssid.ssid_len = bss->ssid.ssid_len;
        (void)memcpy(p2p_uap_network.ssid, bss->ssid.ssid, bss->ssid.ssid_len);
        wps_d("SSID '%s'", wps_s->current_ssid.ssid);
    }
    switch (bss->protocol)
    {
        case UAP_PROTO_OPEN:
            reg_cred->auth_type  = AUTHENTICATION_TYPE_OPEN;
            reg_cred->encry_type = ENCRYPTION_TYPE_NONE;
            /* Set security to Open */
            p2p_uap_network.security.type = WLAN_SECURITY_NONE;
            break;
        case UAP_PROTO_WEP_STATIC:
            reg_cred->encry_type = ENCRYPTION_TYPE_WEP;
            break;
        case UAP_PROTO_WPA:
            reg_cred->auth_type = AUTHENTICATION_TYPE_WPAPSK;
            /* Set security to WPA */
            p2p_uap_network.security.type = WLAN_SECURITY_WPA;
            break;
        case UAP_PROTO_WPA2:
            reg_cred->auth_type = AUTHENTICATION_TYPE_WPA2PSK;
            /* Set security to WPA2 */
            p2p_uap_network.security.type = WLAN_SECURITY_WPA2;
            break;
        case UAP_PROTO_MIXED:
            reg_cred->auth_type = AUTHENTICATION_TYPE_WPA_MIXED;
            break;
        default:
            break;
    }

    if (wps_s->bss_type == BSS_TYPE_UAP)
    {
        if (bss->band_cfg & 0x01 || bss->channel > MAX_CHANNELS)
        {
            reg_cred->rf_bands = RF_50_G;

            pwps_info->enrollee.rf_bands  = RF_50_G;
            pwps_info->registrar.rf_bands = RF_50_G;
        }
        else
        {
            reg_cred->rf_bands = RF_24_G;

            pwps_info->enrollee.rf_bands  = RF_24_G;
            pwps_info->registrar.rf_bands = RF_24_G;
        }
    }

    if (reg_cred->encry_type == ENCRYPTION_TYPE_WEP)
    {
        /* For WEP */
        for (i = 0; i < 4; i++)
        {
            if (bss->wep_cfg[i].is_default)
            {
                /* Get the current default key settings */
                (void)memcpy(reg_cred->network_key, bss->wep_cfg[i].key, bss->wep_cfg[i].length);
                reg_cred->network_key_len   = bss->wep_cfg[i].length;
                reg_cred->network_key_index = bss->wep_cfg[i].key_index + 1;
                break;
            }
        }
        wps_d("NETWORK KEY INDEX = %d", reg_cred->network_key_index - 1);
        wps_hexdump("NETWORK_KEY", (const unsigned char *)reg_cred->network_key, reg_cred->network_key_len);
        switch (bss->auth_mode)
        {
            case UAP_AUTH_MODE_OPEN:
                reg_cred->auth_type = AUTHENTICATION_TYPE_OPEN;
                /* Set security to WEP OPEN */
                p2p_uap_network.security.type = WLAN_SECURITY_WEP_OPEN;
                break;
            case UAP_AUTH_MODE_SHARED:
                reg_cred->auth_type = AUTHENTICATION_TYPE_SHARED;
                /* Set security to WEP SHARED */
                p2p_uap_network.security.type = WLAN_SECURITY_WEP_SHARED;
                break;
            default:
                break;
        }
    }
    wps_d("AUTHENTICATION TYPE = 0x%04x", enr_reg->cred_data[0].auth_type);
    if ((reg_cred->auth_type == AUTHENTICATION_TYPE_WPAPSK) || (reg_cred->auth_type == AUTHENTICATION_TYPE_WPA2PSK) ||
        (reg_cred->auth_type == AUTHENTICATION_TYPE_WPA_MIXED) || (reg_cred->auth_type == AUTHENTICATION_TYPE_ALL))
    {
        /* For WPA/WPA2 */

        if (reg_cred->auth_type == AUTHENTICATION_TYPE_WPAPSK)
            cipher = bss->wpa_cfg.pairwise_cipher_wpa;
        else
            cipher = bss->wpa_cfg.pairwise_cipher_wpa2;

        switch (cipher)
        {
            case UAP_CIPH_NONE:
                reg_cred->encry_type = ENCRYPTION_TYPE_NONE;
                break;
            case UAP_CIPH_TKIP:
                reg_cred->encry_type = ENCRYPTION_TYPE_TKIP;
                break;
            case UAP_CIPH_AES:
                reg_cred->encry_type = ENCRYPTION_TYPE_AES;
                break;
            case UAP_CIPH_AES_TKIP:
                reg_cred->encry_type = ENCRYPTION_TYPE_TKIP_AES_MIXED;
                break;
            default:
                break;
        }
        (void)memcpy(reg_cred->network_key, bss->wpa_cfg.passphrase, bss->wpa_cfg.length);
        if (reg_cred->encry_type != ENCRYPTION_TYPE_WEP)
        {
            reg_cred->network_key_len   = bss->wpa_cfg.length;
            reg_cred->network_key_index = 1;
        }
        wps_d("NETWORK_KEY '%s'", enr_reg->cred_data[0].network_key);
        /* Set passphrase to 12345678 */
        strcpy(p2p_uap_network.security.psk, (const char *)enr_reg->cred_data[0].network_key);
        p2p_uap_network.security.psk_len = enr_reg->cred_data[0].network_key_len;
    }
    wps_d("ENCRYPTION TYPE = 0x%04x", enr_reg->cred_data[0].encry_type);

    /* Both auth_type and encry_type can not be ZERO */
    if (!reg_cred->auth_type && !reg_cred->encry_type)
    {
        reg_cred->auth_type = AUTHENTICATION_TYPE_OPEN;
        wps_d("Incorrect Auth encryption types, Using open security\n");
    }
    if (enr_reg->version >= WPS_VERSION_2DOT0)
    {
        switch (reg_cred->encry_type)
        {
            case ENCRYPTION_TYPE_TKIP:
                PRINTF("WPA-TKIP is deprecated from WSC2.0.\n");
                ret = WPS_STATUS_FAIL;
                break;
            case ENCRYPTION_TYPE_WEP:
                PRINTF("WEP is deprecated from WSC2.0.\n");
                ret = WPS_STATUS_FAIL;
                break;
            default:
                break;
        }
    }

    (void)memcpy(enr_cred, reg_cred, sizeof(CREDENTIAL_DATA));

    LEAVE();
    return ret;
}

/**
 *  @brief Copy BSS configuration into PWPS_INFO  structure
 *  @param wps_s     A pointer to the WPS_DATA structure
 *  @param pwps_info A pointer to the PWPS_INFO structure
 *
 *  @return          WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wps_load_uap_cred(WPS_DATA *wps_s, PWPS_INFO pwps_info)
{
    int ret;
    bss_config_t bss;

    ENTER();

    (void)memset(&bss, 0, sizeof(bss_config_t));

    if ((ret = apcmd_get_bss_config(&bss)) != WPS_STATUS_SUCCESS)
    {
        goto done;
    }

    /* set credentials */
    ret = load_cred_info(wps_s, pwps_info, &bss);

done:
    LEAVE();
    return ret;
}

/**
 *  @brief Creates a get bss_config request and sends to the driver
 *
 *  @param bss       A pointer to the bss_config_t structure
 *
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int apcmd_get_bss_config(bss_config_t *bss)
{
    sys_config *sys_buf = NULL;
    tlvbuf_header *pcurrent_tlv;
    int tlv_buf_left;
    u16 tlv_type;
    u16 tlv_len;
    u16 tlv_val_16;
    tlvbuf_ssid *ssid_tlv;
    tlvbuf_auth_mode *auth_tlv;
    tlvbuf_protocol *proto_tlv;
    tlvbuf_pwk_cipher *pwk_cipher_tlv;
    tlvbuf_wpa_passphrase *psk_tlv;
    u8 *buffer  = NULL;
    u16 cmd_len = 0;

    ENTER();

    (void)memset(bss, 0, sizeof(bss_config_t));

    cmd_len = sizeof(sys_config);
    buffer  = (u8 *)wps_mem_malloc(MRVDRV_SIZE_OF_CMD_BUFFER);
    if (!buffer)
    {
        PRINTF("ERR:Cannot allocate memory!\n");
        return WPS_STATUS_FAIL;
    }
    (void)memset(buffer, 0, MRVDRV_SIZE_OF_CMD_BUFFER);
    sys_buf                    = (sys_config *)buffer;
    sys_buf->cmd_head.cmd_code = HOST_CMD_APCMD_SYS_CONFIGURE;
    sys_buf->cmd_head.seq_num  = (0x01) << 13;
    sys_buf->cmd_head.result   = 0;
    sys_buf->action            = wlan_cpu_to_le16(ACTION_GET);
    sys_buf->cmd_head.size     = cmd_len - BUF_HEADER_SIZE;

    if (wfd_ioctl((u8 *)buffer, cmd_len) == WPS_STATUS_SUCCESS)
        wps_d("Get BSS config command successfully sent.\n");
    else
    {
        wps_d("Get BSS config command send failed.\n");
        wps_mem_free(buffer);
        return WPS_STATUS_FAIL;
    }
    pcurrent_tlv = (tlvbuf_header *)(buffer + cmd_len);
    cmd_len      = sys_buf->cmd_head.size;
    tlv_buf_left = cmd_len;

    wps_d("tlv total len=%d\r\n", cmd_len);

    while (tlv_buf_left >= (int)sizeof(tlvbuf_header))
    {
        tlv_type = *(u8 *)&pcurrent_tlv->type;
        tlv_type |= (*((u8 *)&pcurrent_tlv->type + 1) << 8);
        tlv_len = *(u8 *)&pcurrent_tlv->len;
        tlv_len |= (*((u8 *)&pcurrent_tlv->len + 1) << 8);
        if ((sizeof(tlvbuf_header) + tlv_len) > (unsigned int)tlv_buf_left)
        {
            wps_d("wrong tlv: tlv_len=%d, tlv_buf_left=%d\r\n", tlv_len, tlv_buf_left);
            break;
        }
        switch (tlv_type)
        {
            case MRVL_SSID_TLV_ID:
                ssid_tlv = (tlvbuf_ssid *)pcurrent_tlv;
                if (tlv_len)
                {
                    bss->ssid.ssid_len = tlv_len;
                    (void)memcpy(bss->ssid.ssid, ssid_tlv->ssid, bss->ssid.ssid_len);
                }
                break;
            case MRVL_AUTH_TLV_ID:
                auth_tlv       = (tlvbuf_auth_mode *)pcurrent_tlv;
                bss->auth_mode = auth_tlv->auth_mode;
                break;
            case MRVL_PROTOCOL_TLV_ID:
                proto_tlv  = (tlvbuf_protocol *)pcurrent_tlv;
                tlv_val_16 = *(u8 *)&proto_tlv->protocol;
                tlv_val_16 |= (*((u8 *)&proto_tlv->protocol + 1) << 8);
                bss->protocol = tlv_val_16;
                break;
            case MRVL_CIPHER_PWK_TLV_ID:
                pwk_cipher_tlv           = (tlvbuf_pwk_cipher *)pcurrent_tlv;
                pwk_cipher_tlv->protocol = pwk_cipher_tlv->protocol;
                if (pwk_cipher_tlv->protocol == PROTOCOL_WPA)
                    bss->wpa_cfg.pairwise_cipher_wpa = pwk_cipher_tlv->pairwise_cipher;
                else if (pwk_cipher_tlv->protocol == PROTOCOL_WPA2)
                    bss->wpa_cfg.pairwise_cipher_wpa2 = pwk_cipher_tlv->pairwise_cipher;
                break;
            case MRVL_WPA_PASSPHRASE_TLV_ID:
                psk_tlv             = (tlvbuf_wpa_passphrase *)pcurrent_tlv;
                bss->wpa_cfg.length = tlv_len;
                if (bss->wpa_cfg.length)
                    (void)memcpy(bss->wpa_cfg.passphrase, psk_tlv->passphrase, bss->wpa_cfg.length);
                break;
            default:
                break;
        }
        tlv_buf_left -= (sizeof(tlvbuf_header) + tlv_len);
        pcurrent_tlv = (tlvbuf_header *)(pcurrent_tlv->data + tlv_len);
    }

    if (buffer)
        wps_mem_free(buffer);

    LEAVE();
    return WPS_STATUS_SUCCESS;
}
#else
/**
 *  @brief Copy BSS configuration into PWPS_INFO  structure
 *  @param wps_s     A pointer to the WPS_DATA structure
 *  @param pwps_info A pointer to the PWPS_INFO structure
 *
 *  @return          WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wps_load_uap_cred(WPS_DATA *wps_s, PWPS_INFO pwps_info)
{
    int ret;
    struct wlan_network uap_network;
    ENTER();

    /* Create credential data */
    if (wlan_get_current_uap_network(&uap_network))
    {
        wps_d("WPS Registration not Started as no uap network");
        ret = WPS_STATUS_FAIL;
    }
    else
    {
        CREDENTIAL_DATA *reg_cred           = NULL;
        MESSAGE_ENROLLEE_REGISTRAR *enr_reg = NULL;

        enr_reg                      = &pwps_info->registrar;
        reg_cred                     = &enr_reg->cred_data[0];
        wps_s->current_ssid.ssid_len = strlen(uap_network.ssid);
        (void)memcpy(wps_s->current_ssid.ssid, uap_network.ssid, wps_s->current_ssid.ssid_len);
        (void)memcpy(reg_cred->ssid, uap_network.ssid, wps_s->current_ssid.ssid_len);
        reg_cred->ssid_length = wps_s->current_ssid.ssid_len;

        switch (uap_network.security.type)
        {
            case WLAN_SECURITY_NONE:
                reg_cred->auth_type  = AUTHENTICATION_TYPE_OPEN;
                reg_cred->encry_type = ENCRYPTION_TYPE_NONE;
                break;
            case WLAN_SECURITY_WPA:
                reg_cred->auth_type  = AUTHENTICATION_TYPE_WPAPSK;
                reg_cred->encry_type = ENCRYPTION_TYPE_TKIP;
                break;
            case WLAN_SECURITY_WPA2:
                reg_cred->auth_type  = AUTHENTICATION_TYPE_WPA2PSK;
                reg_cred->encry_type = ENCRYPTION_TYPE_AES;
                break;
            case WLAN_SECURITY_WPA_WPA2_MIXED:
                reg_cred->auth_type  = AUTHENTICATION_TYPE_WPA_MIXED;
                reg_cred->encry_type = ENCRYPTION_TYPE_TKIP_AES_MIXED;
                break;
            default:
                reg_cred->auth_type  = 1 << uap_network.security.type;
                reg_cred->encry_type = ENCRYPTION_TYPE_AES;
                break;
        }

        (void)memcpy(reg_cred->network_key, uap_network.security.psk, uap_network.security.psk_len);
        reg_cred->network_key_len = uap_network.security.psk_len;
        reg_cred->rf_bands        = pwps_info->registrar.rf_bands;
        ret                       = WPS_STATUS_SUCCESS;
    }

    LEAVE();
    return ret;
}
#endif

/*
 * Bit 0 : Assoc Req
 * Bit 1 : Assoc Resp
 * Bit 2 : ReAssoc Req
 * Bit 3 : ReAssoc Resp
 * Bit 4 : Probe Req
 * Bit 5 : Probe Resp
 * Bit 8 : Beacon
 */
/** Mask for Assoc request frame */
#define MGMT_MASK_ASSOC_REQ 0x01
/** Mask for ReAssoc request frame */
#define MGMT_MASK_REASSOC_REQ 0x04
/** Mask for Assoc response frame */
#define MGMT_MASK_ASSOC_RESP 0x02
/** Mask for ReAssoc response frame */
#define MGMT_MASK_REASSOC_RESP 0x08
/** Mask for probe request frame */
#define MGMT_MASK_PROBE_REQ 0x10
/** Mask for probe response frame */
#define MGMT_MASK_PROBE_RESP 0x20
/** Mask for beacon frame */
#define MGMT_MASK_BEACON 0x100
/** Mask to clear previous settings */
#define MGMT_MASK_CLEAR 0x000

/**
 *  @brief Process and send ie config command
 *  @param flag   FLAG: Set/clear WPS IE
 *  @param ie_index  A pointer to the IE buffer index
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wps_wlan_ie_config(int flag, short *pie_index)
{
    u8 *buf, *pos;
    IEEEtypes_Header_t *ptlv_header = NULL;
    int ret                         = WPS_STATUS_SUCCESS;
    u16 ie_len = 0, mgmt_subtype_mask = 0;
    tlvbuf_custom_ie *tlv = NULL;
    custom_ie *ie_ptr     = NULL;
    u8 action = 0x00, type = 0x00;
    u8 saction;
    u16 buf_len;
    int bss_type;

    ENTER();

    type   = flag & 0x0f;
    action = flag & 0xf0;

    buf = (u8 *)wps_mem_malloc(MRVDRV_SIZE_OF_CMD_BUFFER);
    if (!buf)
    {
        PRINTF("ERR:Cannot allocate memory!\n");
        return WPS_STATUS_FAIL;
    }

    (void)memset(buf, 0, MRVDRV_SIZE_OF_CMD_BUFFER);

    tlv       = (tlvbuf_custom_ie *)buf;
    tlv->type = MRVL_MGMT_IE_LIST_TLV_ID;

    /* Locate headers */
    ie_ptr = (custom_ie *)(tlv->ie_data);
    /* Set TLV fields */

    if (action == SET_WPS_IE)
    {
        saction = ACTION_SET;
        /* Set WPS IE */
        pos         = ie_ptr->ie_buffer;
        ptlv_header = (IEEEtypes_Header_t *)pos;
        pos += sizeof(IEEEtypes_Header_t);

        if (type == WPS_AP_SESSION_INACTIVE)
        {
            ie_len            = wps_ap_beacon_prepare(WPS_END_REG_DISCOVERY_PHASE, pos);
            mgmt_subtype_mask = MGMT_MASK_BEACON;
        }
        else if (type == WPS_AP_SESSION_ACTIVE)
        {
            ie_len            = wps_ap_beacon_prepare(WPS_START_REG_DISCOVERY_PHASE, pos);
            mgmt_subtype_mask = MGMT_MASK_BEACON;
        }
        else if (type == WPS_STA_SESSION_ACTIVE)
        {
            ie_len            = wps_sta_assoc_request_prepare(pos);
            mgmt_subtype_mask = MGMT_MASK_ASSOC_REQ | MGMT_MASK_REASSOC_REQ;
        }
        else if (type == WPS_AP_SESSION_ACTIVE_AR)
        {
            ie_len            = wps_ap_assoc_response_prepare(WPS_START_REG_DISCOVERY_PHASE, pos);
            mgmt_subtype_mask = MGMT_MASK_ASSOC_RESP | MGMT_MASK_REASSOC_RESP;
        }
        else if (type == WPS_AP_SESSION_INACTIVE_AR)
        {
            ie_len            = wps_ap_assoc_response_prepare(WPS_END_REG_DISCOVERY_PHASE, pos);
            mgmt_subtype_mask = MGMT_MASK_ASSOC_RESP | MGMT_MASK_REASSOC_RESP;
        }
        else
        {
            wps_d("ie_config: unknown SET type!\n");
            ret = WPS_STATUS_FAIL;
            goto _exit_;
        }

        ptlv_header->element_id   = WPS_IE;
        ptlv_header->len          = ie_len;
        ie_ptr->mgmt_subtype_mask = mgmt_subtype_mask;
        tlv->length               = sizeof(custom_ie) + sizeof(IEEEtypes_Header_t) + ie_len - MAX_IE_SIZE;
        ie_ptr->ie_length         = sizeof(IEEEtypes_Header_t) + ie_len;
        ie_ptr->ie_index          = *pie_index;

        if (type == WPS_AP_SESSION_INACTIVE || type == WPS_AP_SESSION_ACTIVE)
        {
            ie_ptr =
                (custom_ie *)(((u8 *)ie_ptr) + sizeof(custom_ie) + sizeof(IEEEtypes_Header_t) + ie_len - MAX_IE_SIZE);
            pos         = ie_ptr->ie_buffer;
            ptlv_header = (IEEEtypes_Header_t *)pos;
            pos += sizeof(IEEEtypes_Header_t);

            if (type == WPS_AP_SESSION_INACTIVE)
            {
                ie_len            = wps_ap_probe_response_prepare(WPS_END_REG_DISCOVERY_PHASE, pos);
                mgmt_subtype_mask = MGMT_MASK_PROBE_RESP;
            }
            else if (type == WPS_AP_SESSION_ACTIVE)
            {
                ie_len            = wps_ap_probe_response_prepare(WPS_START_REG_DISCOVERY_PHASE, pos);
                mgmt_subtype_mask = MGMT_MASK_PROBE_RESP;
            }

            ptlv_header->element_id   = WPS_IE;
            ptlv_header->len          = ie_len;
            ie_ptr->mgmt_subtype_mask = mgmt_subtype_mask;
            tlv->length += sizeof(custom_ie) + sizeof(IEEEtypes_Header_t) + ie_len - MAX_IE_SIZE;
            ie_ptr->ie_length = sizeof(IEEEtypes_Header_t) + ie_len;
            ie_ptr->ie_index  = *pie_index + 1;
        }
    }
    else if (action == CLEAR_WPS_IE)
    {
        saction = ACTION_SET;
        if (*pie_index < 0)
        {
            wps_d("Clear IE number should be valid\n");
            ret = WPS_STATUS_FAIL;
            goto _exit_;
        }
        /* Clear WPS IE */
        pos                       = ie_ptr->ie_buffer;
        ie_ptr->mgmt_subtype_mask = MGMT_MASK_CLEAR;
        ie_ptr->ie_length         = 0;
        ie_ptr->ie_index          = *pie_index;

        if ((type == CLEAR_WPS_IE) && (*pie_index < (MAX_MGMT_IE_INDEX - 1)))
        {
            ie_ptr                    = (custom_ie *)(((u8 *)ie_ptr) + sizeof(custom_ie) - MAX_IE_SIZE);
            ie_ptr->mgmt_subtype_mask = MGMT_MASK_CLEAR;
            ie_ptr->ie_length         = 0;
            ie_ptr->ie_index          = *pie_index + 1;
            tlv->length               = 2 * (sizeof(custom_ie) - MAX_IE_SIZE);
        }
        else
            tlv->length = sizeof(custom_ie) - MAX_IE_SIZE;

        /* reinit IE index */
        *pie_index = -1;
    }
    else
    {
        /* Get WPS IE */
        tlv->length = 0;
        saction     = ACTION_GET;
    }
    wps_d("Mak: tlv length = %d\n", tlv->length);
    wps_hexdump("MGMT_IE", (const unsigned char *)buf, tlv->length + TLV_HEADER_SIZE);

    buf_len  = tlv->length + TLV_HEADER_SIZE;
    bss_type = (type == WPS_STA_SESSION_ACTIVE) ? BSS_TYPE_STA : BSS_TYPE_UAP;

#if CONFIG_P2P
    ret = wlan_sys_config(buf, &buf_len, saction);
#else
    ret = wrapper_wlan_cmd_mgmt_ie(bss_type, buf, buf_len, saction);
#endif

_exit_:
    if (buf)
        wps_mem_free(buf);

    LEAVE();
    return ret;
}

#if CONFIG_P2P
/**
 *  @brief  Wlan event parser for FW events
 *  @param context    Pointer to Context
 *  @param wps_s      Pointer to WPS global structure
 *  @param evt_buffer Pointer to Event buffer
 *  @param evt_len    Event Length
 *
 *  @return           None
 */
void wps_wlan_peer_event_parser(WPS_DATA *wps_s, char *evt_buffer, int evt_len)
{
    event_header *event = NULL;
    int ret;

    ENTER();

    /* event parser */
    event = (event_header *)evt_buffer;

    switch (event->event_id)
    {
        case EV_ID_WFD_GENERIC:
            wfd_process_peer_detected_event(event->event_data, evt_len - sizeof(event->event_id));
            break;
        case EV_ID_WFD_PEER_CONNECTED:
            gpwps_info->p2p_session = 1;
            break;
        case EV_ID_WFD_PEER_DEAUTH:
        case EV_ID_WFD_PEER_DISASSOC:
        case EV_ID_WFD_PEER_LINK_LOST:
            if (gpwps_info->p2p_session)
            {
                ret = wlan_disconnect();
                if (ret != 0)
                    P2P_LOG("Failed to disconnect %d", ret);

                ret = wlan_remove_network(p2p_network.name);
                if (ret != 0)
                    P2P_LOG("Failed to remove network %d", ret);

                wfd_reset();

                if (wps.cb(P2P_SESSION_FAILED, NULL, 0) == -WM_FAIL)
                    wps_d("P2P Callback failed for event: %d\r\n", P2P_SESSION_FAILED);
            }
            break;
        default:
            break;
    }
    LEAVE();
}

/**
 *  @brief  Wlan event parser for FW events
 *  @param context    Pointer to Context
 *  @param wps_s      Pointer to WPS global structure
 *  @param evt_buffer Pointer to Event buffer
 *  @param evt_len    Event Length
 *
 *  @return           None
 */
void wps_wlan_event_parser(u8 *evt_buffer, int evt_len)
{
    ENTER();

    wfd_process_generic_event(evt_buffer, evt_len);

    LEAVE();
}
/**
 *  @brief Starts the existing AP BSS .
 *
 *  @param wps_s      A pointer to the WPS_DATA structure
 *  @param pwps_info  A pointer to the PWPS_INFO structure
 *
 *  @return            WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int apcmd_start_bss(void)
{
    int ret            = WPS_STATUS_SUCCESS;
    u16 cmd_len        = 0;
    wfdcmdbuf *header  = NULL;
    u8 *buffer         = NULL, *cmd;
    wfdcmdbuf *cmd_buf = NULL;

    ENTER();

    /* send hostcmd now */
    cmd_len = sizeof(wfdcmdbuf);
    buffer  = (u8 *)wps_mem_malloc(cmd_len);
    if (!buffer)
    {
        PRINTF("ERR:Cannot allocate memory!\n");
        return WPS_STATUS_FAIL;
    }

    cmd_buf                    = (wfdcmdbuf *)buffer;
    cmd_buf->cmd_head.cmd_code = HOST_CMD_APCMD_BSS_START;
    cmd_buf->cmd_head.size     = cmd_len - BUF_HEADER_SIZE;
    cmd_buf->cmd_head.seq_num  = (0x01) << 13;
    cmd_buf->cmd_head.result   = 0;

    cmd = (u8 *)buffer;

    *(u32 *)cmd = cmd_len - BUF_HEADER_SIZE;

    header                    = (wfdcmdbuf *)cmd;
    header->cmd_head.size     = cmd_len - BUF_HEADER_SIZE;
    header->cmd_head.buf_size = header->cmd_head.size + BUF_HEADER_SIZE;
    endian_convert_request_header(header->cmd_head);

    if (wfd_ioctl((u8 *)cmd, cmd_len) == WPS_STATUS_SUCCESS)
        wps_d("BSS start command successfully sent.\n");
    else
    {
        wps_d("BSS start command send failed.\n");
        ret = WPS_STATUS_FAIL;
    }

    if (buffer)
        wps_mem_free(buffer);

    LEAVE();
    return ret;
}

/**
 *  @brief  Send Custom_IE command to driver.
 *  @param buf Pointer to data buffer
 *
 *  @return           WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
int wlan_sys_config(u8 *buf, u16 *buf_len, u8 action)
{
    int ret             = WPS_STATUS_SUCCESS;
    sys_config *sys_buf = NULL;
    u8 *buffer          = NULL;
    u16 cmd_len         = 0;

    ENTER();

    cmd_len = sizeof(sys_config);
    buffer  = (u8 *)wps_mem_malloc(MRVDRV_SIZE_OF_CMD_BUFFER);
    if (!buffer)
    {
        PRINTF("ERR:Cannot allocate memory!\n");
        return WPS_STATUS_FAIL;
    }
    (void)memset(buffer, 0, MRVDRV_SIZE_OF_CMD_BUFFER);
    sys_buf                    = (sys_config *)buffer;
    sys_buf->cmd_head.cmd_code = HOST_CMD_APCMD_SYS_CONFIGURE;
    sys_buf->cmd_head.seq_num  = (0x01) << 13;
    sys_buf->cmd_head.result   = 0;
    sys_buf->action            = wlan_cpu_to_le16(action);
    sys_buf->cmd_head.size     = *buf_len + cmd_len - BUF_HEADER_SIZE;

    (void)memcpy(sys_buf->buf, buf, *buf_len);

    wps_hexdump("SYSCONFIGURE", (unsigned const char *)buffer, *buf_len + cmd_len);

    if (wfd_ioctl((u8 *)buffer, *buf_len + cmd_len) == WPS_STATUS_SUCCESS)
    {
        wps_d("System config command sent.\n");
        (void)memcpy(buf, buffer + cmd_len, sys_buf->cmd_head.size);
        *buf_len = sys_buf->cmd_head.size;
    }
    else
    {
        wps_d("System config command send failed.\n");
        ret = WPS_STATUS_FAIL;
    }

    if (buffer)
        wps_mem_free(buffer);

    LEAVE();
    return ret;
}

void wlan_generate_psk(PWPS_INFO pwps_info)
{
    int i, len = 0;
    u8 temp[32];
    CREDENTIAL_DATA *reg_cred = NULL;
    u8 buf[MRVDRV_SIZE_OF_CMD_BUFFER];
    tlvbuf_custom_ie *tlv = NULL;
    u16 buf_len           = 0;

    ENTER();

    (void)memset(buf, 0, MRVDRV_SIZE_OF_CMD_BUFFER);

    reg_cred = &pwps_info->registrar.cred_data[0];

    /*
     * For Wi-Fi Direct, we need to convert the passphrase to PSK.
     */
    pbkdf2_sha1((char *)reg_cred->network_key, (char *)reg_cred->ssid, reg_cred->ssid_length, 4096, temp, 32);
    for (i = 0; i < 32; ++i)
        len += sprintf((char *)reg_cred->network_key + len, "%02x", (temp[i] & 0xff));
    reg_cred->network_key_len = 64;

    wps_hexdump("NETWORK KEY(PSK)", (u8 *)pwps_info->registrar.cred_data[0].network_key, 64);

    tlv         = (tlvbuf_custom_ie *)buf;
    tlv->type   = MRVL_WPA_PASSPHRASE_TLV_ID;
    tlv->length = 64;

    buf_len = sizeof(tlvbuf_custom_ie) + 64;

    (void)memcpy(buf + sizeof(tlvbuf_custom_ie), (u8 *)pwps_info->registrar.cred_data[0].network_key, 64);

    wps_hexdump("PASSPHRASE ", (u8 *)buf, 64 + sizeof(tlvbuf_custom_ie));

    wlan_sys_config(buf, &buf_len, ACTION_SET);

    LEAVE();
}
#endif
