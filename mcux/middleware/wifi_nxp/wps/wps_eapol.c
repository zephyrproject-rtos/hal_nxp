/** @file wps_eapol.c
 *
 *  @brief This file contains functions for EAPOL packet Tx/Rx.
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "wifi_nxp_wps.h"
#include <lwip/inet.h>
#include <wm_os.h>
#include <wm_utils.h>
#include <wifi.h>

#include "wps_eapol.h"
#include "wps_mem.h"
#include "wps_def.h"
#include "wps_msg.h"
#include "wps_wlan.h"
#include "wps_l2.h"
#include "wps_os.h"

/********************************************************
        Local Variables
********************************************************/

/* If want to enable rx_callback log, need to increase IMU_TASK_STACK_SIZE to avoid stack overflow */
#undef WPS_RX_EOPAL_DEBUG

/********************************************************
        Global Variables
********************************************************/
extern WPS_DATA wps_global;
extern PWPS_INFO gpwps_info;

extern struct wps_thread_t wps;

#ifdef CONFIG_WPA2_ENTP
extern WPA_SM wpa_sm;
extern u8 *rbuf;
extern u8 content_type;
extern size_t rlen, used_len;
extern int wait_for_receive();
int err_count, req_len, wpa2_failure;
extern void wpa2_shutdown();
#ifdef CONFIG_PEAP_MSCHAPV2
static u8 tbuf[256];
static size_t tlen;
static int f_count;
static bool not_cert = true;
#endif
#endif

u8 wps_src_macaddr[ETH_ALEN];

/********************************************************
        Local Functions
********************************************************/
/**
 *  @brief Allocate and prepare a EAPOL packet
 *
 *  @param type         Type of EAPOL packet
 *  @param data         A pointer to payload of EAPOL packet
 *  @param data_len     Length of payload
 *  @param msg_len      A pointer to allocated length
 *  @return             A pointer to allocated buffer or NULL if fail
 *            on allocation
 */
static u8 *wps_alloc_eapol(u8 type, const void *data, u16 data_len, size_t *msg_len, void **data_pos)
{
    struct ieee802_1x_hdr *hdr;

    ENTER();

    *msg_len = sizeof(*hdr) + data_len;
    hdr      = wps_mem_malloc(*msg_len);
    if (hdr == NULL)
    {
        LEAVE();
        return NULL;
    }
#define DEFAULT_EAPOL_VERSION 1

    hdr->version = DEFAULT_EAPOL_VERSION;
    hdr->type    = type;
    hdr->length  = htons(data_len);

    if (data)
        (void)memcpy(hdr + 1, data, data_len);
    else
        (void)memset(hdr + 1, 0, data_len);

    if (data_pos)
        *data_pos = hdr + 1;

    LEAVE();
    return (u8 *)hdr;
}

/********************************************************
        Global Functions
********************************************************/
/**
 *  @brief Send Ethernet frame to layer 2 socket
 *
 *  @param dest         Destination MAC address
 *  @param proto        Ethertype
 *  @param buf          Frame payload starting from IEEE 802.1X header
 *  @param len          Frame payload length
 *  @return             Result of layer 2 send function
 */
static int wps_ether_send(const u8 *dest, u16 proto, const u8 *buf, size_t len)
{
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    ENTER();

    return wps_l2_send(wps_s->l2, dest, proto, buf, len);
}

/**
 *  @brief Send IEEE 802.1X EAPOL packet to Authenticator
 *         This function adds Ethernet and IEEE 802.1X header
 *         and sends the EAPOL frame to the current Authenticator.
 *
 *  @param type         IEEE 802.1X packet type (IEEE802_1X_TYPE_*)
 *  @param buf          EAPOL payload (after IEEE 802.1X header)
 *  @param len          EAPOL payload length
 *  @return             Result of Ether sending function
 */
int wps_eapol_send(int type, u8 *buf, size_t len)
{
    u8 *msg, *dst;
    size_t msglen;
    int res;

    ENTER();

    dst = (u8 *)&gpwps_info->enrollee.mac_address[0];
    if (gpwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(gpwps_info)))
    {
        dst = (u8 *)&gpwps_info->registrar.mac_address[0];
    }
    else
    {
        dst = (u8 *)&gpwps_info->enrollee.mac_address[0];
    }

    wps_d("TX EAPOL to " MACSTR, MAC2STR(dst));

    /* Payload of EAPOL copied in wps_alloc_eapol */
    msg = wps_alloc_eapol(type, buf, len, &msglen, NULL);
    if (msg == NULL)
    {
        LEAVE();
        return WPS_STATUS_FAIL;
    }
    wps_hexdump("TX EAPOL", msg, msglen);

    res = wps_ether_send(dst, ETH_P_EAPOL, msg, msglen);

    if (msg)
        wps_mem_free(msg);

    LEAVE();
    return res;
}

/**
 *  @brief Send EAPOL-START packet
 *
 *  @return         Result of EAPOL sending function
 */
int wps_eapol_txStart(void)
{
    int ret;

    ENTER();

    ret = wps_eapol_send(IEEE802_1X_TYPE_EAPOL_START, (u8 *)"", 0);
    if (ret < 0)
        wps_d("wps_eapol_txStart fail");

    LEAVE();
    return ret;
}

/**
 *  @brief Send EAPOL packet
 *
 *  @param buf      EAP packet payload
 *  @param len      Length of payload
 *  @return         Result of EAPOL sending function
 */
int wps_eapol_txPacket(u8 *buf, size_t len)
{
    int ret;

    ENTER();

    ret = wps_eapol_send(IEEE802_1X_TYPE_EAP_PACKET, buf, len);
    if (ret < 0)
        wps_d("wps_eapol_txPacket fail");

    LEAVE();
    return ret;
}

/**
 *  @brief Send EAPOL KEY packet
 *
 *  @param buf      EAP packet payload
 *  @param len      Length of payload
 *  @return         Result of EAPOL sending function
 */
int wps_eapol_key_txPacket(u8 *buf, size_t len)
{
    int ret;

    ENTER();

    ret = wps_eapol_send(IEEE802_1X_TYPE_EAPOL_KEY, buf, len);
    if (ret < 0)
        wps_d("wps_eapol_txPacket fail");

    LEAVE();
    return ret;
}
/**
 *  @brief EAPOL packet received handler
 *
 *  @param src_addr     Layer 2 source address of EAPOL packet
 *  @param buf          Received packet buffer
 *  @param len          Received packet length
 *  @return             None
 */
void wps_rx_eapol(const u8 *src_addr, const u8 *buf, size_t len)
{
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    ENTER();

    if (IS_DISCOVERY_REGISTRAR(gpwps_info))
        (void)memcpy(gpwps_info->enrollee.mac_address, src_addr, ETH_ALEN);

    wps_d("RX EAPOL from " MACSTR, MAC2STR(src_addr));
    wps_hexdump("RX EAPOL", buf, len);

    wps_s->eapol_received++;

    /* Callback to WPS state machine message handler */
    wps_message_handler((u8 *)buf, (u8 *)src_addr);

    LEAVE();
}

void WPSEAPoLRxDataHandler(const u8 *buf, const size_t len)
{
#ifdef CONFIG_WPA2_ENTP
    PWPS_INFO pwps_info;
    pwps_info = wps_get_private_info();
#endif

    const u8 *etherhead  = buf;
    const u8 *data       = buf + sizeof(struct l2_ethhdr);
    struct l2_ethhdr *eh = (struct l2_ethhdr *)etherhead;
    PEAPOL_FRAME_HEADER peapol;
    PEAP_FRAME_HEADER peap;
#ifdef CONFIG_WPA2_ENTP
    PEAP_TLS_FRAME_HEADER peap_tls;
#endif
    int new_msg_type = 0;
    u8 *mbuffer;
    PTLV_DATA_HEADER ptlv;
    int type, length;
    struct wps_msg msg;
    u8 *buffer;
    size_t data_len;

#ifdef WPS_RX_EOPAL_DEBUG
    ENTER();
#endif

    peapol = (PEAPOL_FRAME_HEADER)data;

    if (wlan_get_prov_session() == PROV_NON_SESSION_ATTEMPT)
    {
        wps_d("return for PROV_NON_SESSION_ATTEMPT");
        return;
    }

    switch (peapol->packet_type)
    {
        case EAP_PACKET:
        {
            peap = (PEAP_FRAME_HEADER)(data + sizeof(EAPOL_FRAME_HEADER));

            switch (peap->code)
            {
                case EAP_REQUEST:
#ifdef WPS_RX_EOPAL_DEBUG
                    wps_d("EAP_REQUEST received");
#endif
                    if (peap->type == EAP_TYPE_IDENTITY)
                    {
#ifdef WPS_RX_EOPAL_DEBUG
                        wps_d("EAP_REQUEST_IDENTITY Received");
#endif
                        new_msg_type = WPS_EAP_MSG_REQUEST_IDENTITY;

#if 0 // -- TBD
//#ifdef CONFIG_WPA2_ENTP
                        /* Here we check for wlan state and if
                         * it is connected than we will re-start
                         * wpa2_ent main thread.
                         */
                        enum wlan_connection_state state;
                        int ret;
                        ret = wlan_get_connection_state(&state);
                        if (ret != WM_SUCCESS)
                        {
                            wps_d(
                                "EAP Request Identity :"
                                " Get connection state "
                                " failed");
                            break;
                        }
                        if (state == WLAN_CONNECTED)
                        {
                            if (is_wps_main_loop_running())
                            {
                                wpa2_shutdown();
                                /* We are sleeping current
                                 * thread (stack_dispatcher) so
                                 * that wpa2_ent thread can get
                                 * chance to finish cleanup.
                                 */
                                os_thread_sleep(1000);
                            }
                            ret = wlan_wpa2_ent_reinit();
                            if (ret != WM_SUCCESS)
                            {
                                wps_d(
                                    "EAP Request Identity :"
                                    " wlan_wpa2_ent_reinit"
                                    " failed");
                                break;
                            }
                            wps_d(
                                "EAP Request Identity :"
                                " connected state");
                        }
#endif
                    }
                    else if (peap->type == EAP_TYPE_WPS)
                    {
                        switch (peap->op_code)
                        {
                            case WPS_Start:
                            {
                                new_msg_type = WPS_EAP_START;
                            }
                            break;
                            case WPS_Ack:
                            case WPS_Nack:
                            case WPS_Msg:
                            case WPS_Done:
                                mbuffer = (u8 *)peap;
                                mbuffer += SZ_EAP_WPS_FRAME_HEADER;
                                ptlv   = (PTLV_DATA_HEADER)mbuffer;
                                length = ntohs(ptlv->length);
                                mbuffer += (SZ_TLV_HEADER + length);
                                ptlv = (PTLV_DATA_HEADER)mbuffer;
                                type = ntohs(ptlv->type);
                                if (type == SC_Message_Type)
                                {
                                    mbuffer += SZ_TLV_HEADER;
                                    new_msg_type = (u8)*mbuffer;
                                }
                                break;
                            default:
#ifdef WPS_RX_EOPAL_DEBUG
                                wps_d("Unknown opcode: 0x%x", peap->op_code);
#endif
                                return;
                        }
                    }
#ifdef CONFIG_WPA2_ENTP
                    else if (peap->type == EAP_TYPE_TLS || peap->type == EAP_TYPE_PEAP)
                    {
                        peap_tls = (PEAP_TLS_FRAME_HEADER)(data + sizeof(EAPOL_FRAME_HEADER));

                        if ((pwps_info->last_recv_tls_msg_identifier < 255) &&
                            (peap_tls->identifier <= pwps_info->last_recv_tls_msg_identifier))
                        {
                            wps_d("return for %d <= %d", peap_tls->identifier, pwps_info->last_recv_tls_msg_identifier);
                            return;
                        }

                        if (peap_tls->flags & EAP_TLS_FLAGS_START)
                        {
                            new_msg_type = WPS_EAP_TLS_START;
#ifdef CONFIG_PEAP_MSCHAPV2
                            tlen     = 0;
                            f_count  = 0;
                            not_cert = true;
#endif
                        }
                        else
                            new_msg_type = WPS_EAP_TLS_MSG;
                    }
#endif
                    break;
#ifdef CONFIG_WPA2_ENTP
                case EAP_SUCCESS:
                    new_msg_type = WPS_EAP_MSG_SUCCESS;
                    break;
#endif
            }
        }
        break;
        case EAPOL_KEY_PACKET:
            /* Do not process EAPOL-Key packets in WPS */
            return;
    }

    data_len = len - sizeof(struct l2_ethhdr);

    buffer = (u8 *)wps_mem_malloc(data_len);

    if (!buffer)
        return;

    (void)memcpy(wps_src_macaddr, eh->h_source, ETH_ALEN);

    (void)memcpy(buffer, data, data_len);

    msg.mac          = wps_src_macaddr;
    msg.len          = data_len;
    msg.buffer       = (void *)buffer;
    msg.new_msg_type = new_msg_type;

    if (os_queue_send(&wps.data_queue, &msg, OS_NO_WAIT) != WM_SUCCESS)
    {
        wps_mem_free(buffer);
#ifdef WPS_RX_EOPAL_DEBUG
        wps_d("Failed to send data\r\n");
#endif
    }

#ifdef WPS_RX_EOPAL_DEBUG
    LEAVE();
#endif
}

#ifdef CONFIG_WPA2_ENTP
int WPSEAPoLSSLTxDataHandler(u8 *buf, size_t len)
{
    u8 *tr_buf    = buf;
    size_t tr_len = len;
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    pwps_info = wps_get_private_info();

#ifdef CONFIG_PEAP_MSCHAPV2
    if (len < 100 && not_cert)
    {
        (void)memcpy(tbuf + tlen, buf, len);
        tlen += len;

        if (tlen < 100)
            return len;

        tr_buf = tbuf;
        tr_len = tlen;

        tlen     = 0;
        not_cert = false;
    }
    else
    {
        f_count++;
        if (f_count >= 2)
            not_cert = false;
    }
#endif
    if (pwps_info && pwps_info->wps_session && wps_s->tls_session_init && !wpa2_failure)
    {
        wps_eap_tls_response_send(tr_buf, tr_len);
        if (wpa2_failure)
            return WPA2_ERR_CONN_CLOSE;
        return len;
    }
    return WPA2_ERR_CONN_CLOSE;
}

int WPSEAPoLSSLRxDataHandler(u8 *buf, size_t *len)
{
    PWPS_INFO pwps_info;
    int ret;

    if ((wpa2_failure) || (err_count == WPA2_RX_WAIT && *len == req_len))
    {
        return WPA2_ERR_CONN_CLOSE;
    }

    pwps_info = wps_get_private_info();

    if (pwps_info && pwps_info->wps_session)
    {
        if (!rlen)
        {
            used_len = 0;
            ret      = wait_for_receive();
            if (ret != WM_SUCCESS || !rlen)
            {
                err_count++;
                req_len = *len;
                return 0;
            }
        }

        if (*len > rlen)
        {
            ret = wait_for_receive();
            if (ret != WM_SUCCESS)
            {
                err_count++;
                req_len = *len;
                return 0;
            }
        }
        err_count = 0;
        req_len   = 0;
        (void)memcpy(buf, rbuf + used_len, *len);
        used_len += *len;
        rlen -= *len;
        if (rlen <= 0)
            rlen = 0;

        return *len;
    }
    return WPA2_ERR_CONN_CLOSE;
}
#endif
