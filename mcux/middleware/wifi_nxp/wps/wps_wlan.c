/** @file wps_wlan.c
 *
 *  @brief This file contains functions for WLAN driver control/command
 *
 *  Copyright 2008-2022 NXP
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
                reg_cred->auth_type = AUTHENTICATION_TYPE_OPEN;
                reg_cred->encry_type = ENCRYPTION_TYPE_NONE;
                break;
            case WLAN_SECURITY_WPA:
                reg_cred->auth_type = AUTHENTICATION_TYPE_WPAPSK;
                reg_cred->encry_type = ENCRYPTION_TYPE_TKIP;
                break;
            case WLAN_SECURITY_WPA2:
                reg_cred->auth_type = AUTHENTICATION_TYPE_WPA2PSK;
                reg_cred->encry_type = ENCRYPTION_TYPE_AES;
                break;
            case WLAN_SECURITY_WPA_WPA2_MIXED:
                reg_cred->auth_type = AUTHENTICATION_TYPE_WPA_MIXED;
                reg_cred->encry_type = ENCRYPTION_TYPE_TKIP_AES_MIXED;
                break;
            default:
                reg_cred->auth_type = 1 << uap_network.security.type;
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

    ret = wrapper_wlan_cmd_mgmt_ie(bss_type, buf, buf_len, saction);

_exit_:
    if (buf)
        wps_mem_free(buf);

    LEAVE();
    return ret;
}

