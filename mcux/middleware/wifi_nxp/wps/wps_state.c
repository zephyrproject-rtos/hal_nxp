/** @file wps_state.c
 *
 *  @brief This file contains functions for WPS state machine.
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <stdlib.h>
#include "wifi_nxp_wps.h"
#include <lwip/sys.h>
#include <wmtypes.h>
#include <lwip/inet.h>
#include <wm_os.h>
#include <wlan.h>
#ifdef CONFIG_PEAP_MSCHAPV2
#include <mbedtls/sha1.h>
#include <mbedtls/md4.h>
#include <mbedtls/des.h>
#endif

#include "wps_msg.h"
#include "wps_eapol.h"
#include "wps_def.h"
#include "wps_wlan.h"
#include "wps_os.h"
#include "wps_mem.h"
#include <wifi.h>

extern struct wps_thread_t wps;

#ifdef CONFIG_WPA2_ENTP
#define SSL_WAIT             5000
#define TLS_RECV_BUFFER_SIZE 6144
extern WPA_SM wpa_sm;
extern int err_count, req_len, wpa2_failure;
extern void wpa2_shutdown();

os_thread_t wps_tls_thread;
static os_thread_stack_define(wps_tls_stack, 8192);

u8 *rbuf;
#ifdef CONFIG_PEAP_MSCHAPV2
static u8 plain_data[512], msg[512];
#endif
static int msg_length, fragment = 0;
size_t rlen = 0, used_len = 0;
static void signal_receive();
int wait_for_receive();
extern uint8_t *key_data;
#endif

extern struct wlan_network wps_network;

int wps_registrar_state_check(PWPS_INFO pwps_info, u16 msg_type);
int wps_registrar_state_transition(PWPS_INFO pwps_info, u16 msg_type);

extern int wps_install_current_ipv4_cfg(char *ifname, u32 ip_addr, u32 subnet_mask);

/********************************************************
        Local Variables
********************************************************/
static int (*wps_msg_process[17])(PWPS_INFO, u8 *, u16) = {wps_dummy,
                                                           wps_dummy,
                                                           wps_eap_response_identity_process,
                                                           wps_eap_request_start_process,
                                                           wps_eap_M1_frame_process,
                                                           wps_eap_M2_frame_process,
                                                           wps_eap_M2D_frame_process,
                                                           wps_eap_M3_frame_process,
                                                           wps_eap_M4_frame_process,
                                                           wps_eap_M5_frame_process,
                                                           wps_eap_M6_frame_process,
                                                           wps_eap_M7_frame_process,
                                                           wps_eap_M8_frame_process,
                                                           wps_ack_message_process,
                                                           wps_nack_message_process,
                                                           wps_done_message_process,
                                                           wps_dummy};

static int (*wps_msg_prepare[18])(PWPS_INFO) = {
    wps_eapol_start_prepare,       wps_eap_request_identity_prepare, wps_eap_response_identity_prepare,
    wps_eap_request_start_prepare, wps_eap_M1_frame_prepare,         wps_eap_M2_frame_prepare,
    wps_eap_M2D_frame_prepare,     wps_eap_M3_frame_prepare,         wps_eap_M4_frame_prepare,
    wps_eap_M5_frame_prepare,      wps_eap_M6_frame_prepare,         wps_eap_M7_frame_prepare,
    wps_eap_M8_frame_prepare,      wps_ack_message_prepare,          wps_nack_message_remap,
    wps_done_message_prepare,      wps_eap_fail_frame_prepare,       NULL};
#ifdef CONFIG_WPA2_ENTP
typedef struct eap_tls_keys
{
    unsigned char master_secret[48];
    unsigned char randbytes[64];
    mbedtls_tls_prf_types tls_prf_type;
} eap_tls_keys;
unsigned char eap_tls_keymaterial[32];
const char *eap_tls_label = "client EAP encryption";
eap_tls_keys eap_tls_keying;
#endif /* CONFIG_WPA2_ENTP */

/********************************************************
        Global Variables
********************************************************/
/** WPS global */
extern WPS_DATA wps_global;
extern int wps_eapol_txStart(void);
/** IE buffer index */
extern short ie_index;
extern short assoc_ie_index;

/** IE buffer index */
extern short ap_assocresp_ie_index;
extern u8 *g_ssid;

/********************************************************
        Local Functions
********************************************************/
#ifdef STDOUT_DEBUG_MSG
/**
 *  @brief Print WPS message type information for debugging
 *
 *  @param str      Print string
 *  @param msg      Message type
 *  @return         None
 */
void wps_debug_print_msgtype(const char *str, int msg)
{
    ENTER();

    switch (msg)
    {
        case WPS_EAPOL_MSG_START:
            wps_d("%s: EAPOL_START", str);
            break;
        case WPS_EAP_MSG_REQUEST_IDENTITY:
            wps_d("%s: EAP_REQUEST_IDENTITY", str);
            break;
        case WPS_EAP_MSG_RESPONSE_IDENTITY:
            wps_d("%s: EAP_RESPONSE_IDENTITY", str);
            break;
        case WPS_EAP_START:
            wps_d("%s: WPS_START", str);
            break;
        case WPS_EAP_M1:
            wps_d("%s: WPS_M1", str);
            break;
        case WPS_EAP_M2:
            wps_d("%s: WPS_M2", str);
            break;
        case WPS_EAP_M2D:
            wps_d("%s: WPS_M2D", str);
            break;
        case WPS_EAP_M3:
            wps_d("%s: WPS_M3", str);
            break;
        case WPS_EAP_M4:
            wps_d("%s: WPS_M4", str);
            break;
        case WPS_EAP_M5:
            wps_d("%s: WPS_M5", str);
            break;
        case WPS_EAP_M6:
            wps_d("%s: WPS_M6", str);
            break;
        case WPS_EAP_M7:
            wps_d("%s: WPS_M7", str);
            break;
        case WPS_EAP_M8:
            wps_d("%s: WPS_M8", str);
            break;
        case WPS_MSG_DONE:
            wps_d("%s: WPS_DONE", str);
            break;
        case WPS_MSG_ACK:
            wps_d("%s: WPS_ACK", str);
            break;
        case WPS_MSG_NACK:
            wps_d("%s: WPS_NACK ", str);
            break;
        case WPS_EAP_MSG_FAIL:
            wps_d("%s: EAP_FAIL ", str);
            break;
        case WPS_MSG_FRAG_ACK:
            wps_d("%s: WPS_FRAG_ACK ", str);
            break;
        default:
            wps_d("%s: ERROR - UNKNOWN TYPE ! ", str);
            break;
    }
    LEAVE();
}

/**
 *  @brief Print WPS state information for debugging
 *
 *  @param str      Print string
 *  @param state    State information
 *  @return         None
 */
static void wps_debug_print_state(const char *str, int state)
{
    ENTER();

    switch (state)
    {
        case WPS_STATE_A:
            wps_d("%s = A", str);
            break;
        case WPS_STATE_B:
            wps_d("%s = B", str);
            break;
        case WPS_STATE_C:
            wps_d("%s = C", str);
            break;
        case WPS_STATE_D:
            wps_d("%s = D", str);
            break;
        case WPS_STATE_E:
            wps_d("%s = E", str);
            break;
        case WPS_STATE_F:
            wps_d("%s = F", str);
            break;
        case WPS_STATE_G:
            wps_d("%s = G", str);
            break;
        case WPS_STATE_H:
            wps_d("%s = H", str);
            break;
        case WPS_STATE_I:
            wps_d("%s = I", str);
            break;
        default:
            wps_d("%s = Unknown WPS State", str);
            break;
    }

    LEAVE();
}
#else
void wps_debug_print_msgtype(const char *str, int msg)
{
}

static void wps_debug_print_state(const char *str, int state)
{
}
#endif /* STDOUT_DEBUG_MSG */

/**
 *  @brief Extract the message type field from EAP packet
 *
 *  @param peap     A pointer to EAP frame header
 *  @return         Message type
 */
static int wps_get_message_type(PEAP_FRAME_HEADER peap)
{
    u8 *buffer;
    int msg_type = 0;
    PTLV_DATA_HEADER ptlv;
    int type, length;

    ENTER();

    switch (peap->op_code)
    {
        case WPS_Start:
            msg_type = WPS_EAP_START;
            break;
        case WPS_Ack:
        case WPS_Nack:
        case WPS_Msg:
        case WPS_Done:
            buffer = (u8 *)peap;
            buffer += SZ_EAP_WPS_FRAME_HEADER;
            ptlv   = (PTLV_DATA_HEADER)buffer;
            length = ntohs(ptlv->length);
            buffer += (SZ_TLV_HEADER + length);
            ptlv = (PTLV_DATA_HEADER)buffer;
            type = ntohs(ptlv->type);
            if (type == SC_Message_Type)
            {
                buffer += SZ_TLV_HEADER;
                msg_type = (u8)*buffer;
            }
            break;
        default:
            wps_d("Unknown opcode: 0x%x", peap->op_code);
            break;
    }

    wps_debug_print_msgtype("RX WPS Message Type", msg_type);

    LEAVE();
    return msg_type;
}

#ifdef CONFIG_WPA2_ENTP
static void signal_receive()
{
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    os_semaphore_put(&wps_s->ssl_sync_sem);
}

int wait_for_receive()
{
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    return os_semaphore_get(&wps_s->ssl_sync_sem, os_msec_to_ticks(SSL_WAIT));
}
#endif

/**
 *  @brief Process Enrollee state machine checking
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param msg_type     Message type to be checked
 *  @return             Message type to be sent in current state
 */
static int wps_enrollee_state_check(PWPS_INFO pwps_info, u16 msg_type)
{
    int msg_next = WPS_EAP_UNKNOWN;

    ENTER();

    switch (msg_type)
    {
        case WPS_EAP_MSG_REQUEST_IDENTITY:
            pwps_info->eap_identity_count++;
            if (pwps_info->eap_identity_count < 1)
                msg_next = WPS_EAPOL_MSG_START;
            else if ((pwps_info->state == WPS_STATE_A) || (pwps_info->state == WPS_STATE_B))
                msg_next = WPS_EAP_MSG_RESPONSE_IDENTITY;
            break;

        case WPS_EAP_MSG_RESPONSE_IDENTITY:
            break;
        case WPS_EAP_START:
            pwps_info->eap_identity_count = 0;
            if ((pwps_info->state == WPS_STATE_B) || (pwps_info->state == WPS_STATE_C) ||
                (pwps_info->state == WPS_STATE_D))
                msg_next = WPS_EAP_M1;
            break;
        case WPS_EAP_M2:

            if ((pwps_info->state == WPS_STATE_D) || (pwps_info->state == WPS_STATE_E) ||
                (pwps_info->state == WPS_STATE_F))
                msg_next = WPS_EAP_M3;
            break;
        case WPS_EAP_M2D:
            if ((pwps_info->state == WPS_STATE_D) || (pwps_info->state == WPS_STATE_B) ||
                (pwps_info->state == WPS_STATE_E))
                msg_next = WPS_MSG_ACK;
            break;
        case WPS_EAP_M4:
            if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_F))
                msg_next = WPS_EAP_M5;
            break;
        case WPS_EAP_M6:
            if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_F))
                msg_next = WPS_EAP_M7;
            break;
        case WPS_EAP_M8:
            if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_F) ||
                (pwps_info->state == WPS_STATE_H))
                msg_next = WPS_MSG_DONE;
            break;
        case WPS_MSG_NACK:
            if (pwps_info->state == WPS_STATE_I)
                msg_next = WPS_MSG_NACK;
            break;
        case WPS_MSG_ACK:
            break;
        case WPS_EAP_MSG_FAIL:
            if ((pwps_info->state == WPS_STATE_A) || (pwps_info->state == WPS_STATE_B))
                msg_next = WPS_EAP_MSG_RESPONSE_IDENTITY;
            break;
        default:
            break;
    } /* end of swtich */

    wps_debug_print_msgtype("WPS Next Message", msg_next);

    LEAVE();
    return msg_next;
}

/**
 *  @brief Process Enrollee state machine transition
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param msg_type     Message type for triggering state transition
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
static int wps_enrollee_state_transition(PWPS_INFO pwps_info, u16 msg_type)
{
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
    int status      = WPS_STATUS_SUCCESS;

    ENTER();

    /* Current WPS State */
    wps_debug_print_state("State Transition Before", pwps_info->state);

    switch (msg_type)
    {
        case WPS_EAPOL_MSG_START:
            wps_d("Event Trigger : EAPOL_START");

            pwps_info->last_recv_wps_msg = -1;

            /* Reset Public keys and E-Hash, R-Hash */
            wps_reset_wps_state(pwps_info);
            break;
        case WPS_EAP_MSG_RESPONSE_IDENTITY:
            wps_d("Event Trigger : EAP_RESPONSE_IDENTITY");

            pwps_info->register_completed       = WPS_CANCEL;
            pwps_info->registration_in_progress = WPS_SET;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            if (pwps_info->state == WPS_STATE_A)
            {
                pwps_info->state = WPS_STATE_B;
                wps_d("State A->B");
            }
            break;
        case WPS_EAP_START:
            wps_d("Event Trigger : WPS_START");

            pwps_info->register_completed       = WPS_CANCEL;
            pwps_info->registration_in_progress = WPS_SET;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            if (pwps_info->state == WPS_STATE_A)
                pwps_info->state = WPS_STATE_B;

            if (pwps_info->state == WPS_STATE_B)
            {
                pwps_info->state = WPS_STATE_C;
                wps_d("State B->C");
            }
            break;
        case WPS_EAP_M1:
            wps_d("Event Trigger : WPS_M1");
            if (pwps_info->state == WPS_STATE_C)
            {
                pwps_info->state = WPS_STATE_D;
                wps_d("State C->D");
            }
            break;
        case WPS_EAP_M2:
            wps_d("Event Trigger : WPS_M2");
            if (pwps_info->state == WPS_STATE_D)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State D->E");
            }
            break;
        case WPS_EAP_M2D:
            wps_d("Event Trigger : WPS_M2D");
            if ((pwps_info->state == WPS_STATE_D) || (pwps_info->state == WPS_STATE_B))
                pwps_info->state = WPS_STATE_E;
            break;
        case WPS_EAP_M3:
            wps_d("Event Trigger : WPS_M3");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_F;
                wps_d("State E->F");
            }
            break;
        case WPS_EAP_M4:
            wps_d("Event Trigger : WPS_M4");
            if (pwps_info->state == WPS_STATE_F)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State F->E");
            }
            break;
        case WPS_EAP_M5:
            wps_d("Event Trigger : WPS_M5");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_F;
                wps_d("State E->F");
            }
            break;
        case WPS_EAP_M6:
            wps_d("Event Trigger : WPS_M6");
            if (pwps_info->state == WPS_STATE_F)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State F->E");
            }
            break;
        case WPS_EAP_M7:
            wps_d("Event Trigger : WPS_M7");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_F;
                wps_d("State E->F");
            }
            break;
        case WPS_EAP_M8:
            wps_d("Event Trigger : WPS_M8");
            pwps_info->register_completed       = WPS_SET;
            pwps_info->registration_in_progress = WPS_CANCEL;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            if (pwps_info->state == WPS_STATE_F)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State F->E");
            }
            break;
        case WPS_MSG_DONE:
            wps_d("Event Trigger : WPS_DONE");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_H;
                wps_d("State E->H");
            }
            break;
        case WPS_MSG_ACK:
            wps_d("Event Trigger : WPS_ACK");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_D;
                wps_d("State E->D");
            }
            break;
        case WPS_MSG_NACK:
            wps_d("Event Trigger : WPS_NACK");
            switch (pwps_info->state)
            {
                case WPS_STATE_D:
                case WPS_STATE_H:
                    break;
                case WPS_STATE_E:
                    pwps_info->state = WPS_STATE_G;
                    wps_d("State E->G");
                    break;
                case WPS_STATE_I:
                    if (wps_s->bss_type != BSS_TYPE_UAP)
                    {
                        pwps_info->state = WPS_STATE_G;
                        wps_d("State I->G");
                    }
                    break;
                case WPS_STATE_F:
                    if (wps_s->bss_type != BSS_TYPE_UAP)
                    {
                        pwps_info->state = WPS_STATE_I;
                        wps_d("State F->I");
                    }
                    break;
                default:
                    break;
            }
            break;
        case WPS_EAP_MSG_FAIL:
            wps_d("Event Trigger : EAP_FAIL");

            pwps_info->last_recv_wps_msg        = -1;
            pwps_info->registration_in_progress = WPS_CANCEL;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            switch (pwps_info->state)
            {
#ifdef CONFIG_WPA2_ENTP
                case WPS_STATE_B:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State B->A");
                    break;
#endif /*CONFIG_WPA2_ENTP*/
                case WPS_STATE_F:
                    break;
                case WPS_STATE_D:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State D->A");
                    break;
                case WPS_STATE_G:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State G->A");
                    break;
                case WPS_STATE_H:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State H->A");
                    break;
                case WPS_STATE_I:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State I->A");
                    break;
                default:
                    break;
            }
            break;

        default:
            break;

    } /* end of switch */

    /* New WPS State */
    wps_debug_print_state("State Transition After", pwps_info->state);

    LEAVE();
    return status;
}

#ifdef CONFIG_WPA2_ENTP
void wpa2_session_success()
{
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    PWPS_INFO pwps_info;

    pwps_info = wps_get_private_info();

    err_count    = 0;
    req_len      = 0;
    wpa2_failure = 0;

    pwps_info->register_completed       = WPS_SET;
    pwps_info->registration_in_progress = WPS_CANCEL;

    /* Cancel WPS Registration Timer */
    wps_d("Cancelling registration timer!");
    wps_cancel_timer(wps_registration_time_handler, pwps_info);

    pwps_info->wps_session = 0;

    wps_s->tls_session_active    = false;
    wps_s->tls_session_key_valid = false;

    if (pwps_info->set_timer == WPS_SET)
    {
        wps_cancel_timer(wps_txTimer_handler, pwps_info);
        pwps_info->set_timer            = WPS_CANCEL;
        pwps_info->wps_msg_resent_count = 0;
    }

    pwps_info->registration_fail        = WPS_SET;
    pwps_info->registration_in_progress = WPS_CANCEL;
    wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

    wps_d("State *->A");
    pwps_info->state = WPS_STATE_A;
}

void wpa2_session_clean()
{
    int status;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    if (wps_s->wpa2_network.security.wlan_ssl)
    {
        wm_mbedtls_ssl_free(wps_s->wpa2_network.security.wlan_ssl);
        wps_s->wpa2_network.security.wlan_ssl = NULL;
        if (wps_s->wpa2_network.security.wlan_ctx)
        {
            wm_mbedtls_ssl_config_free(wps_s->wpa2_network.security.wlan_ctx);
            wps_s->wpa2_network.security.wlan_ctx = NULL;
        }
    }

    if (wps_s->tls_session_init)
    {
        wps_s->tls_session_init = false;

        if (rbuf)
        {
            wps_mem_free(rbuf);
            rbuf = NULL;
        }

        status = os_semaphore_delete(&wps_s->ssl_sync_sem);
        if (status != WM_SUCCESS)
            wps_d("Warning: failed to delete mutex.\r\n");

        status = os_thread_delete(&wps_tls_thread);
        if (status != WM_SUCCESS)
            wps_d("Warning: failed to delete thread.\r\n");
    }
}

void wpa2_session_complete()
{
    WPS_DATA *wps_s  = (WPS_DATA *)&wps_global;
    WPA_SM *wpa_sm_s = (WPA_SM *)&wpa_sm;
    PWPS_INFO pwps_info;

    err_count    = 0;
    req_len      = 0;
    wpa2_failure = 0;

    pwps_info = wps_get_private_info();

    if (pwps_info && pwps_info->wps_session)
    {
        if (wps.cb(WPS_SESSION_FAILED, NULL, 0) == -WM_FAIL)
            wps_d(
                "WPS Callback failed for event:"
                "%d",
                WPS_SESSION_FAILED);

        pwps_info->register_completed       = WPS_CANCEL;
        pwps_info->registration_in_progress = WPS_CANCEL;

        /* Cancel WPS Registration Timer */
        wps_d("Cancelling registration timer!");
        wps_cancel_timer(wps_registration_time_handler, pwps_info);

        pwps_info->wps_session = 0;

        if (pwps_info->set_timer == WPS_SET)
        {
            wps_cancel_timer(wps_txTimer_handler, pwps_info);
            pwps_info->set_timer            = WPS_CANCEL;
            pwps_info->wps_msg_resent_count = 0;
        }

        pwps_info->registration_fail        = WPS_SET;
        pwps_info->registration_in_progress = WPS_CANCEL;
        wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

        wps_d("State *->A");
        pwps_info->state             = WPS_STATE_A;
        wps_s->tls_session_active    = false;
        wps_s->tls_session_key_valid = false;
    }
    if (pwps_info)
    {
        /* Reset Public keys and E-Hash, R-Hash */
        wps_reset_wps_state(pwps_info);

        wps_session_deinit();

        (void)memset(wpa_sm_s, 0, sizeof(WPA_SM));

        wpa_sm_s->pairwise_cipher = WPA_CIPHER_CCMP;
        wpa_sm_s->group_cipher    = WPA_CIPHER_CCMP;
        wpa_sm_s->proto           = WPA_PROTO_RSN;
        wpa_sm_s->key_mgmt        = WPA_KEY_MGMT_IEEE8021X;
        wpa_sm_s->renew_snonce    = 1;
        (void)memcpy(wpa_sm_s->own_addr, wps_s->l2->my_mac_addr, ETH_ALEN);
    }
}

static int SSLSend(void *ctx, u8 *buf, size_t sz)
{
    ((void)ctx);
    return WPSEAPoLSSLTxDataHandler(buf, sz);
}

static int SSLReceive(void *ctx, u8 *buf, size_t sz)
{
    ((void)ctx);
    return WPSEAPoLSSLRxDataHandler(buf, &sz);
}

int eap_tls_key_derivation(void *p_expkey,
                           const unsigned char *ms,
                           const unsigned char *kb,
                           size_t maclen,
                           size_t keylen,
                           size_t ivlen,
                           const unsigned char client_random[32],
                           const unsigned char server_random[32],
                           mbedtls_tls_prf_types tls_prf_type)
{
    eap_tls_keys *keys = (eap_tls_keys *)p_expkey;

    ((void)kb);
    (void)memcpy(keys->master_secret, ms, sizeof(keys->master_secret));
    (void)memcpy(keys->randbytes, client_random, 32);
    (void)memcpy(keys->randbytes + 32, server_random, 32);
    keys->tls_prf_type = tls_prf_type;

    return (0);
}

void wps_tls_init(void *argv)
{
    int status      = WPS_STATUS_SUCCESS, rv;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    status = os_semaphore_create(&wps_s->ssl_sync_sem, "ssl-synch-sem");

    if (status != WM_SUCCESS)
    {
        goto fail;
    }
    /*Take semaphore immediatly so that we can later block on it */
    os_semaphore_get(&wps_s->ssl_sync_sem, OS_WAIT_FOREVER);

    wps_d("EAP: Init Session");
    wps_s->tls_session_init      = true;
    wps_s->tls_session_active    = false;
    wps_s->tls_session_key_valid = false;

    mbedtls_ssl_set_bio(wps_s->wpa2_network.security.wlan_ssl, (void *)wps_s->sockfd, (mbedtls_ssl_send_t *)SSLSend,
                        (mbedtls_ssl_recv_t *)SSLReceive, NULL);
    mbedtls_ssl_conf_export_keys_ext_cb(wps_s->wpa2_network.security.wlan_ctx, eap_tls_key_derivation, &eap_tls_keying);
    wps_d("EAP: SSL Connect");
    /* see note at top of README */
    rv = wm_mbedtls_ssl_connect(wps_s->wpa2_network.security.wlan_ssl);
    if (rv != 0)
    {
        wps_d(
            "wm_mbedtls_ssl_connect returned: -0x%02x "
            "(-%d)\r\n",
            -rv, -rv);
        wps_d(
            "WPA2 Enterprise (EAP) Registration "
            "protocol failed !");
        if (wps.cb(WPS_SESSION_FAILED, NULL, 0) == -WM_FAIL)
            wps_d(
                "WPS Callback failed for event:"
                "%d",
                WPS_SESSION_FAILED);
        wpa2_session_complete();
        goto fail;
    }

    wps_d("EAP: SSL Connect Successful");

    wps_d("EAP: Done");

#ifdef CONFIG_PEAP_MSCHAPV2
    if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
        wps_s->tls_session_active = true;
#endif

    wps_eap_tls_response_send(NULL, 0);

    wps_d("EAP: Session Successful");

    if ((status = mbedtls_ssl_tls_prf(eap_tls_keying.tls_prf_type, eap_tls_keying.master_secret,
                                      sizeof(eap_tls_keying.master_secret), eap_tls_label, eap_tls_keying.randbytes,
                                      sizeof(eap_tls_keying.randbytes), eap_tls_keymaterial,
                                      sizeof(eap_tls_keymaterial))) != 0)
    {
        wps_d(" failed\n  ! mbedtls_ssl_tls_prf returned -0x%x\n\n", (unsigned int)-status);
        goto fail;
    }
    (void)memcpy(wps_s->key_data, eap_tls_keymaterial, sizeof(eap_tls_keymaterial));

    wps_hexdump("EAP Session key", wps_s->key_data, PMK_LEN);

    wps_d("Negotiated SSL protocol: %s", mbedtls_ssl_get_version(wps_s->wpa2_network.security.wlan_ssl));
    wps_d("SSL cipher suite: %s", mbedtls_ssl_get_ciphersuite(wps_s->wpa2_network.security.wlan_ssl));

    /* Send key as soon as SSL handshake is complete to avoid key failure */
    if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_TLS)
        wps_s->tls_session_active = true;
    wps_s->tls_session_key_valid = true;
    if (wps.cb(WPS_SESSION_SUCCESSFUL, wps_s->key_data, PMK_LEN) == -WM_FAIL)
        wps_d("WPS Callback failed for event: %d", WPS_SESSION_SUCCESSFUL);

    if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_TLS)
    {
        wpa2_session_success();
        wps_d(
            "WPA2 Enterprise (EAP-TLS) Protocol "
            "Completed Successfully !");
    }
#ifdef CONFIG_PEAP_MSCHAPV2
    else if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
    {
        while (1)
            os_thread_sleep(5000);
    }
#endif
fail:
    wpa2_session_clean();
}

#ifdef CONFIG_PEAP_MSCHAPV2
static void des_encrypt(const u8 *clear, const u8 *key, u8 *cipher)
{
    u8 pkey[8], next, tmp;
    int i;

    /* Add parity bits to the key */
    next = 0;
    for (i = 0; i < 7; i++)
    {
        tmp     = key[i];
        pkey[i] = (tmp >> i) | next | 1;
        next    = tmp << (7 - i);
    }
    pkey[i] = next | 1;

    mbedtls_des_context ctx;

    mbedtls_des_init(&ctx);

    mbedtls_des_setkey_enc(&ctx, pkey);

    mbedtls_des_crypt_ecb(&ctx, clear, cipher);

    mbedtls_des_free(&ctx);
}

static void challenge_hash(
    const u8 *auth_challenge, const u8 *peer_challenge, const u8 *username, const size_t username_len, u8 *challenge)
{
    u8 hash[20];

    mbedtls_sha1_context ctx;

    mbedtls_sha1_init(&ctx);
    mbedtls_sha1_starts(&ctx);
    mbedtls_sha1_update(&ctx, peer_challenge, 16);
    mbedtls_sha1_update(&ctx, auth_challenge, 16);
    mbedtls_sha1_update(&ctx, username, username_len);
    mbedtls_sha1_finish(&ctx, hash);
    mbedtls_sha1_free(&ctx);

    (void)memcpy(challenge, hash, 8);
}

static void challenge_response(const u8 *challenge, const u8 *pass_hash, u8 *nt_response)
{
    u8 zpwd[21];

    (void)memset(zpwd, 0, 21);

    (void)memcpy(zpwd, pass_hash, 16);

    des_encrypt(challenge, zpwd, nt_response);
    des_encrypt(challenge, zpwd + 7, nt_response + 8);
    des_encrypt(challenge, zpwd + 14, nt_response + 16);
}

static int generate_mschapv2_nt_response(const u8 *challenge, const u8 *pass_hash, u8 *nt_response)
{
    int status = WPS_STATUS_SUCCESS;

    challenge_response(challenge, pass_hash, nt_response);

    return status;
}

static int generate_mschapv2_auth_response(const u8 *auth_challenge,
                                           const u8 *peer_challenge,
                                           const u8 *username,
                                           const size_t username_len,
                                           const u8 *pass_hash_hash,
                                           const u8 *challenge,
                                           const u8 *nt_response,
                                           u8 *auth_response)
{
    int status                 = WPS_STATUS_SUCCESS;
    static const u8 magic1[39] = {0x4D, 0x61, 0x67, 0x69, 0x63, 0x20, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x20,
                                  0x74, 0x6F, 0x20, 0x63, 0x6C, 0x69, 0x65, 0x6E, 0x74, 0x20, 0x73, 0x69, 0x67,
                                  0x6E, 0x69, 0x6E, 0x67, 0x20, 0x63, 0x6F, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x74};
    static const u8 magic2[41] = {0x50, 0x61, 0x64, 0x20, 0x74, 0x6F, 0x20, 0x6D, 0x61, 0x6B, 0x65, 0x20, 0x69, 0x74,
                                  0x20, 0x64, 0x6F, 0x20, 0x6D, 0x6F, 0x72, 0x65, 0x20, 0x74, 0x68, 0x61, 0x6E, 0x20,
                                  0x6F, 0x6E, 0x65, 0x20, 0x69, 0x74, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6F, 0x6E};

    mbedtls_sha1_context ctx;

    mbedtls_sha1_init(&ctx);
    mbedtls_sha1_starts(&ctx);
    mbedtls_sha1_update(&ctx, pass_hash_hash, 16);
    mbedtls_sha1_update(&ctx, nt_response, 24);
    mbedtls_sha1_update(&ctx, magic1, sizeof(magic1));
    mbedtls_sha1_finish(&ctx, auth_response);
    mbedtls_sha1_free(&ctx);

    mbedtls_sha1_init(&ctx);
    mbedtls_sha1_starts(&ctx);
    mbedtls_sha1_update(&ctx, auth_response, 20);
    mbedtls_sha1_update(&ctx, challenge, 8);
    mbedtls_sha1_update(&ctx, magic2, sizeof(magic2));
    mbedtls_sha1_finish(&ctx, auth_response);
    mbedtls_sha1_free(&ctx);

    return status;
}

static void wpa_put_le16(u8 *a, u16 val)
{
    a[1] = val >> 8;
    a[0] = val & 0xff;
}

static u16 wpa_get_be16(const u8 *a)
{
    return (a[0] << 8) | a[1];
}
/**
 * utf8_to_ucs2 - Convert UTF-8 string to UCS-2 encoding
 * @utf8_string: UTF-8 string (IN)
 * @utf8_string_len: Length of utf8_string (IN)
 * @ucs2_buffer: UCS-2 buffer (OUT)
 * @ucs2_buffer_size: Length of UCS-2 buffer (IN)
 * @ucs2_string_size: Number of 2-byte words in the resulting UCS-2 string
 * Returns: 0 on success, -1 on failure
 */
static int utf8_to_ucs2(
    const u8 *utf8_string, size_t utf8_string_len, u8 *ucs2_buffer, size_t ucs2_buffer_size, size_t *ucs2_string_size)
{
    size_t i, j;

    for (i = 0, j = 0; i < utf8_string_len; i++)
    {
        u8 c = utf8_string[i];
        if (j >= ucs2_buffer_size)
        {
            /* input too long */
            return -1;
        }
        if (c <= 0x7F)
        {
            wpa_put_le16(ucs2_buffer + j, c);
            j += 2;
        }
        else if (i == utf8_string_len - 1 || j >= ucs2_buffer_size - 1)
        {
            /* incomplete surrogate */
            return -1;
        }
        else
        {
            u8 c2 = utf8_string[++i];
            if ((c & 0xE0) == 0xC0)
            {
                /* two-byte encoding */
                wpa_put_le16(ucs2_buffer + j, ((c & 0x1F) << 6) | (c2 & 0x3F));
                j += 2;
            }
            else if (i == utf8_string_len - 1 || j >= ucs2_buffer_size - 1)
            {
                /* incomplete surrogate */
                return -1;
            }
            else
            {
                /* three-byte encoding */
                u8 c3 = utf8_string[++i];
                wpa_put_le16(ucs2_buffer + j, ((c & 0xF) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F));
                j += 2;
            }
        }
    }

    if (ucs2_string_size)
        *ucs2_string_size = j / 2;
    return 0;
}

static int generate_nt_pass_hash(const u8 *pass, const size_t pass_len, u8 *pass_hash)
{
    int status = WPS_STATUS_SUCCESS;
    u8 buf[512], *pos;
    size_t len, max_len;

    /* TODO: utf8 to ucs2 conversion of password before hash */

    max_len = sizeof(buf);
    if (utf8_to_ucs2(pass, pass_len, buf, max_len, &len) < 0)
        return -1;

    len *= 2;
    pos = buf;

    mbedtls_md4(pos, len, pass_hash);

    return status;
}

static int generate_hash_nt_pass_hash(const u8 *pass_hash, u8 *pass_hash_hash)
{
    int status = WPS_STATUS_SUCCESS;

    mbedtls_md4(pass_hash, 16, pass_hash_hash);

    return status;
}

static int generate_master_key(const u8 *pass_hash_hash, const u8 *nt_response, u8 *master_key)
{
    static const u8 magic1[27] = {0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x4d, 0x50,
                                  0x50, 0x45, 0x20, 0x4d, 0x61, 0x73, 0x74, 0x65, 0x72, 0x20, 0x4b, 0x65, 0x79};
    u8 hash[20];
    mbedtls_sha1_context ctx;

    mbedtls_sha1_init(&ctx);
    mbedtls_sha1_starts(&ctx);
    mbedtls_sha1_update(&ctx, pass_hash_hash, 16);
    mbedtls_sha1_update(&ctx, nt_response, 24);
    mbedtls_sha1_update(&ctx, magic1, sizeof(magic1));
    mbedtls_sha1_finish(&ctx, hash);
    mbedtls_sha1_free(&ctx);

    (void)memcpy(master_key, hash, 16);

    return 0;
}

static int derive_mschapv2_response(const u8 *username,
                                    const size_t username_len,
                                    const u8 *pass,
                                    const size_t pass_len,
                                    const u8 *auth_challenge,
                                    const u8 *peer_challenge,
                                    u8 *nt_response,
                                    u8 *auth_response,
                                    u8 *master_key)
{
    int status = WPS_STATUS_SUCCESS;
    u8 pass_hash[16], pass_hash_hash[16], challenge[8];

    challenge_hash(auth_challenge, peer_challenge, username, username_len, challenge);

    wps_hexdump("Challenge", challenge, 8);

    status = generate_nt_pass_hash(pass, pass_len, pass_hash);

    if (status != WPS_STATUS_SUCCESS)
        return status;

    wps_hexdump("password hash", pass_hash, 16);

    status = generate_hash_nt_pass_hash(pass_hash, pass_hash_hash);

    if (status != WPS_STATUS_SUCCESS)
        return status;

    wps_hexdump("Hash of password hash", pass_hash_hash, 16);

    status = generate_mschapv2_nt_response(challenge, pass_hash, nt_response);

    if (status != WPS_STATUS_SUCCESS)
        return status;

    wps_hexdump("NT response", nt_response, MSCHAPV2_NT_RESPONSE_LEN);

    status = generate_mschapv2_auth_response(auth_challenge, peer_challenge, username, username_len, pass_hash_hash,
                                             challenge, nt_response, auth_response);

    if (status != WPS_STATUS_SUCCESS)
        return status;

    wps_hexdump("auth response", auth_response, MSCHAPV2_AUTH_RESPONSE_LEN);

    status = generate_master_key(pass_hash_hash, nt_response, master_key);

    if (status != WPS_STATUS_SUCCESS)
        return status;

    wps_hexdump("Master Key", master_key, MSCHAPV2_MASTER_KEY_LEN);

    return status;
}

static const u8 *remove_mschapv2_domain(const u8 *username, size_t *len)
{
    size_t i;

    for (i = 0; i < *len; i++)
    {
        if (username[i] == '\\')
        {
            *len -= i + 1;
            return username + i + 1;
        }
    }

    return username;
}

static int prepare_mschapv2_challenge_reply(const u8 id, const u8 mschapv2_identifier, const u8 *auth_challenge)
{
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
    int status      = WPS_STATUS_SUCCESS;
    PEAP_FRAME_HEADER2 peap_frame;
    PEAP_MSCHAPV2_FRAME_HEADER mschapv2_frame;
    PEAP_MSCHAPV2_RESPONSE_HEADER mschapv2_resp;
    size_t length;
    u8 eap_type, resp_len;
    const u8 *id_str = NULL, *pass = NULL, *username = NULL;
    size_t id_len, pass_len, username_len = 0, mschapv2_frame_len = 0;

    wps_d("EAP-MSCHAPv2: Generating challenge response");

    pwps_info = wps_get_private_info();

    id_str = (u8 *)wps_s->wpa2_network.identity;
    pass   = (u8 *)wps_s->wpa2_network.password;

    id_len   = strlen((const char *)id_str);
    pass_len = strlen((const char *)pass);

    wps_d("identity ascii: %s", id_str);
    wps_hexdump("identity", id_str, id_len);
    username_len = id_len;
    username     = remove_mschapv2_domain(id_str, &username_len);
    wps_d("username ascii: %s", username);
    wps_hexdump("username", username, username_len);
    wps_d("password ascii: %s", pass);
    wps_hexdump("password", pass, pass_len);

    wps_generate_nonce_16B(wps_s->peer_challenge);

    wps_hexdump("auth challenge", auth_challenge, MSCHAPV2_CHAL_LEN);

    wps_hexdump("peer challenge", wps_s->peer_challenge, MSCHAPV2_CHAL_LEN);

    status = derive_mschapv2_response(username, username_len, pass, pass_len, auth_challenge, wps_s->peer_challenge,
                                      wps_s->nt_response, wps_s->auth_response, wps_s->master_key);

    if (status != WPS_STATUS_SUCCESS)
        return status;

    mschapv2_frame_len = sizeof(EAP_MSCHAPV2_FRAME_HEADER) + 1 + sizeof(EAP_MSCHAPV2_RESPONSE_HEADER) + id_len;

    peap_frame             = (PEAP_FRAME_HEADER2)pwps_info->buffer;
    peap_frame->code       = EAP_RESPONSE;
    peap_frame->identifier = id;
    peap_frame->length     = sizeof(EAP_FRAME_HEADER2) + 1 + mschapv2_frame_len;
    length                 = peap_frame->length;
    peap_frame->length     = htons(peap_frame->length);

    eap_type = EAP_TYPE_MSCHAPV2;

    (void)memcpy((u8 *)peap_frame + sizeof(EAP_FRAME_HEADER2), &eap_type, sizeof(u8));

    mschapv2_frame = (PEAP_MSCHAPV2_FRAME_HEADER)((u8 *)pwps_info->buffer + sizeof(EAP_FRAME_HEADER2) + 1);

    mschapv2_frame->code       = MSCHAPV2_RESPONSE;
    mschapv2_frame->identifier = mschapv2_identifier;
    mschapv2_frame->length     = mschapv2_frame_len;
    mschapv2_frame->length     = htons(mschapv2_frame->length);

    resp_len = sizeof(EAP_MSCHAPV2_RESPONSE_HEADER);

    (void)memcpy((u8 *)mschapv2_frame + sizeof(EAP_MSCHAPV2_FRAME_HEADER), &resp_len, sizeof(u8));

    mschapv2_resp = (PEAP_MSCHAPV2_RESPONSE_HEADER)((u8 *)pwps_info->buffer + sizeof(EAP_FRAME_HEADER2) + 1 +
                                                    sizeof(EAP_MSCHAPV2_FRAME_HEADER) + 1);

    (void)memcpy(mschapv2_resp->peer_challenge, wps_s->peer_challenge, MSCHAPV2_CHAL_LEN);

    (void)memset(mschapv2_resp->reserved, 0, 8);

    (void)memcpy(mschapv2_resp->nt_response, wps_s->nt_response, MSCHAPV2_NT_RESPONSE_LEN);

    mschapv2_resp->flags = 0;

    (void)memcpy((u8 *)mschapv2_resp + sizeof(EAP_MSCHAPV2_RESPONSE_HEADER), id_str, id_len);

    wps_hexdump("Challenge Response", (u8 *)pwps_info->buffer, (size_t)length);

    /* call ssl write function */
    status =
        wm_mbedtls_ssl_write(wps_s->wpa2_network.security.wlan_ssl, (u8 *)pwps_info->buffer + 4, (size_t)length - 4);

    if (status < 0)
        return WPS_STATUS_FAIL;

    return WPS_STATUS_SUCCESS;
}

static int process_mschapv2_challenge(const u8 id, PEAP_MSCHAPV2_FRAME_HEADER ms, size_t ms_len)
{
    int status = WPS_STATUS_SUCCESS;
    const u8 *p, *challenge;
    size_t len, challenege_len;

    wps_d("EAP-MSCHAPv2: Processing challenge");

    p              = (const u8 *)(ms + 1);
    challenege_len = *p++;

    len = ms_len - sizeof(*ms) - 1;

    if (challenege_len != MSCHAPV2_CHAL_LEN)
        return WPS_STATUS_FAIL;

    challenge = p;

    p += challenege_len;
    len -= challenege_len;

    wps_hexdump("Authentication servername", p, len);

    prepare_mschapv2_challenge_reply(id, ms->identifier, challenge);

    return status;
}

static int verify_mschapv2_auth_response(const u8 id, PEAP_MSCHAPV2_FRAME_HEADER ms, size_t ms_len)
{
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
    PEAP_FRAME_HEADER2 peap_frame;
    int status = WPS_STATUS_SUCCESS;
    const u8 *buf;
    size_t length;
    u8 eap_type, success;
    size_t len = ms_len - sizeof(EAP_MSCHAPV2_FRAME_HEADER);

    pwps_info = wps_get_private_info();

    buf = (const u8 *)(ms + 1);

    u8 recv_response[MSCHAPV2_AUTH_RESPONSE_LEN];
    if (len < 2 + 2 * MSCHAPV2_AUTH_RESPONSE_LEN || buf[0] != 'S' || buf[1] != '=' ||
        hexstr2bin((const s8 *)(buf + 2), recv_response, MSCHAPV2_AUTH_RESPONSE_LEN) ||
        memcmp(wps_s->auth_response, recv_response, MSCHAPV2_AUTH_RESPONSE_LEN) != 0)
        return -1;

    peap_frame             = (PEAP_FRAME_HEADER2)pwps_info->buffer;
    peap_frame->code       = EAP_RESPONSE;
    peap_frame->identifier = id;
    peap_frame->length     = sizeof(EAP_FRAME_HEADER2) + 1 + 1;
    length                 = peap_frame->length;
    peap_frame->length     = htons(peap_frame->length);

    eap_type = EAP_TYPE_MSCHAPV2;

    (void)memcpy((u8 *)peap_frame + sizeof(EAP_FRAME_HEADER2), &eap_type, sizeof(u8));

    success = MSCHAPV2_SUCCESS;

    (void)memcpy((u8 *)peap_frame + sizeof(EAP_FRAME_HEADER2) + 1, &success, sizeof(u8));

    wps_hexdump("Auth Response", (u8 *)pwps_info->buffer, (size_t)length);

    /* call ssl write function */
    status =
        wm_mbedtls_ssl_write(wps_s->wpa2_network.security.wlan_ssl, (u8 *)pwps_info->buffer + 4, (size_t)length - 4);

    if (status < 0)
        return WPS_STATUS_FAIL;

    return status;
}

static int process_mschapv2_message(const u8 *msg)
{
    int status                    = WPS_STATUS_SUCCESS;
    PEAP_FRAME_HEADER2 hdr        = (PEAP_FRAME_HEADER2)msg;
    PEAP_MSCHAPV2_FRAME_HEADER ms = (PEAP_MSCHAPV2_FRAME_HEADER)((u8 *)(hdr + 1) + 1);
    size_t len                    = ntohs(hdr->length) - sizeof(EAP_FRAME_HEADER2) - 1;

    wps_d("EAP-MSCHAPv2: id: %d Request code: %d", hdr->identifier, ms->code);

    switch (ms->code)
    {
        case MSCHAPV2_CHALLENGE:
            process_mschapv2_challenge(hdr->identifier, ms, len);
            break;
        case MSCHAPV2_SUCCESS:
            if (verify_mschapv2_auth_response(hdr->identifier, ms, len))
                return WPS_STATUS_FAIL;

            wps_d("Received Success");
            wps_d("Authentication succeeded");
            break;
        case MSCHAPV2_FAILURE:
            break;
        default:
            break;
    }
    return status;
}

static int peap_prepare_tlv_result(const u8 *msg, int resp_status)
{
    int status = WPS_STATUS_SUCCESS;
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s        = (WPS_DATA *)&wps_global;
    PEAP_FRAME_HEADER2 hdr = (PEAP_FRAME_HEADER2)msg;
    PEAP_FRAME_HEADER2 peap_frame;
    u8 eap_type;
    u8 success_tlv[] = {0x80, 0x03, 0x00, 0x02, 0x00, 0x01};
    u8 failure_tlv[] = {0x80, 0x03, 0x00, 0x02, 0x00, 0x02};
    size_t length;

    pwps_info = wps_get_private_info();

    peap_frame             = (PEAP_FRAME_HEADER2)pwps_info->buffer;
    peap_frame->code       = EAP_RESPONSE;
    peap_frame->identifier = hdr->identifier;
    peap_frame->length     = sizeof(EAP_FRAME_HEADER2) + 1 + 6;
    length                 = peap_frame->length;
    peap_frame->length     = htons(peap_frame->length);

    eap_type = EAP_TYPE_TLV;

    (void)memcpy((u8 *)peap_frame + sizeof(EAP_FRAME_HEADER2), &eap_type, sizeof(u8));

    if (resp_status == EAP_TLV_RESULT_SUCCESS)
    {
        (void)memcpy((u8 *)peap_frame + sizeof(EAP_FRAME_HEADER2) + 1, success_tlv, 6);
    }
    else
    {
        (void)memcpy((u8 *)peap_frame + sizeof(EAP_FRAME_HEADER2) + 1, failure_tlv, 6);
    }

    wps_hexdump("TLV Response", (u8 *)pwps_info->buffer, (size_t)length);

    /* call ssl write function */
    status = wm_mbedtls_ssl_write(wps_s->wpa2_network.security.wlan_ssl, (u8 *)pwps_info->buffer, (size_t)length);

    if (status < 0)
        return WPS_STATUS_FAIL;

    return WPS_STATUS_SUCCESS;
}

static int peap_process_tlv(const u8 *msg)
{
    const u8 *p, *tlv;
    int status, resp_status;

    tlv = msg + sizeof(EAP_FRAME_HEADER2) + 1;

    /** TODO: We process only result tlv as of now and ignore rest */
    if (tlv[0] == 0x80 && tlv[1] == 0x03)
    {
        p      = tlv + 4;
        status = wpa_get_be16(p);
        if (status == EAP_TLV_RESULT_SUCCESS)
        {
            wps_d(
                "EAP-TLV: TLV Result - Success "
                "Phase 2 Completed");
            wps_d("EAP-MSCHAPv2: Session Successful");
            resp_status = EAP_TLV_RESULT_SUCCESS;
        }
        else if (status == EAP_TLV_RESULT_FAILURE)
        {
            wpa2_failure = 1;
            wps_d("EAP-TLV: TLV Result - Failure");
            resp_status = EAP_TLV_RESULT_FAILURE;
        }
        else
        {
            wpa2_failure = 1;
            wps_d("EAP-TLV: Unknown TLV Result %d", status);
            resp_status = EAP_TLV_RESULT_FAILURE;
        }
    }
    else
    {
        resp_status = EAP_TLV_RESULT_FAILURE;
    }

    peap_prepare_tlv_result(msg, resp_status);

    if (resp_status == EAP_TLV_RESULT_SUCCESS)
    {
        wps_d(
            "WPA2 Enterprise (PEAPv0/EAP-MSCHAPv2) Protocol "
            "Completed Successfully !");
    }
    else
    {
        wps_d(
            "WPA2 Enterprise (EAP) Registration "
            "protocol failed !");
    }

    return WPS_STATUS_SUCCESS;
}

static int process_peap_phase2_request(const u8 *msg)
{
    int status = WPS_STATUS_SUCCESS;
    PWPS_INFO pwps_info;
    PEAP_FRAME_HEADER2 hdr = (PEAP_FRAME_HEADER2)msg;
    u8 type                = *(u8 *)(hdr + 1);

    pwps_info = wps_get_private_info();

    wps_d(
        "EAP-PEAP: Phase 2 id: %d "
        "Request type: %d",
        hdr->identifier, type);

    switch (type)
    {
        case EAP_TYPE_IDENTITY:
            status = wps_peap_response_identity_prepare(pwps_info);
            break;
        case EAP_TYPE_MSCHAPV2:
            status = process_mschapv2_message(msg);
            break;
        case EAP_TYPE_TLV:
            status = peap_process_tlv(msg);
            break;
        default:
            break;
    }

    return status;
}

static int process_peap_message(const u8 *msg)
{
    int status             = WPS_STATUS_SUCCESS;
    PEAP_FRAME_HEADER2 hdr = (PEAP_FRAME_HEADER2)msg;

    wps_d("EAP-PEAP: Received Phase 2: code %d, id %d, len %d", hdr->code, hdr->identifier, ntohs(hdr->length));

    switch (hdr->code)
    {
        case EAP_REQUEST:
            process_peap_phase2_request(msg);
            break;
        case EAP_SUCCESS:
            break;
        case EAP_FAILURE:
            break;
        default:
            wps_d(
                "EAP-PEAP: Unexpected code %d in"
                "Phase 2 EAP header",
                hdr->code);
            break;
    }

    return status;
}

static u8 eap_get_type(const u8 *data)
{
    return ((const u8 *)data)[sizeof(EAP_FRAME_HEADER2)];
}
#endif /* CONFIG_PEAP_MSCHAPV2 */
#endif /* CONFIG_WPA2_ENTP */

/**
 *  @brief Enrollee EAP packet process handling
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param peap         A pointer to EAP frame header
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
static int wps_eap_request_message_handler(PWPS_INFO pwps_info, PEAP_FRAME_HEADER peap)
{
    int status = WPS_STATUS_SUCCESS;
    int msg_next, msg_type;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
#ifdef CONFIG_WPA2_ENTP
    PEAP_TLS_FRAME_HEADER peap_tls;
#endif

    ENTER();

    pwps_info->peer_id = peap->identifier;

    if (peap->type == EAP_TYPE_IDENTITY)
    {
        wps_d("EAP_REQUEST_IDENTITY Received");
        wps_debug_print_msgtype("RX WPS Message Type", WPS_EAP_MSG_REQUEST_IDENTITY);

        if (pwps_info->set_timer == WPS_SET)
        {
            wps_cancel_timer(wps_txTimer_handler, pwps_info);
            pwps_info->set_timer            = WPS_CANCEL;
            pwps_info->wps_msg_resent_count = 0;
        }

        msg_type                     = WPS_EAP_MSG_REQUEST_IDENTITY;
        pwps_info->last_recv_wps_msg = msg_type;

        if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
        {
            msg_next = wps_enrollee_state_check(pwps_info, WPS_EAP_MSG_REQUEST_IDENTITY);
        }
        else
        {
            msg_next = wps_registrar_state_check(pwps_info, WPS_EAP_MSG_REQUEST_IDENTITY);
        }
        if (msg_next != WPS_EAP_UNKNOWN)
            status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
    }
    else if (peap->type == EAP_TYPE_WPS)
    {
        switch (peap->op_code)
        {
            case WPS_Msg:
            {
                msg_type = wps_get_message_type(peap);

                if ((msg_type > pwps_info->last_recv_wps_msg) || (msg_type == WPS_M2D) ||
                    ((pwps_info->last_recv_wps_msg == WPS_M2D) && (msg_type == WPS_M2)))
                {
                    wps_d("Last Message received 0x%x", pwps_info->last_recv_wps_msg);
                    wps_d("Current message 0x%x", msg_type);

                    if ((msg_type == pwps_info->last_recv_wps_msg) && (msg_type != WPS_M2D))
                    {
                        /** recevied the retransmitted message
                         *  use the previous transmitted message,
                         *  instead of current tx message
                         */
                        wps_d("Received reTx EAPOL Req message: 0x%x", msg_type);
                        (void)memcpy(&pwps_info->last_message, &pwps_info->last_tx_message, sizeof(MESSAGE_BUFFER));
                    }

                    pwps_info->last_recv_wps_msg = msg_type;
                }
                else
                {
                    wps_d(
                        "rx_msg: Dropping unexpected msg! "
                        "(prev_msg: 0x%x, curr_msg: 0x%x)",
                        pwps_info->last_recv_wps_msg, msg_type);
                    break;
                }

                if (pwps_info->set_timer == WPS_SET)
                {
                    wps_cancel_timer(wps_txTimer_handler, pwps_info);
                    pwps_info->set_timer            = WPS_CANCEL;
                    pwps_info->wps_msg_resent_count = 0;
                }

                if (msg_type != WPS_EAP_UNKNOWN)
                    status = (*wps_msg_process[msg_type])(pwps_info, (u8 *)peap, peap->length);
                else
                    status = WPS_STATUS_FAIL;

                if (status == WPS_STATUS_SUCCESS)
                {
                    if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
                    {
                        wps_enrollee_state_transition(pwps_info, msg_type);
                        msg_next = wps_enrollee_state_check(pwps_info, msg_type);

                        if (wps_s->bss_type == BSS_TYPE_UAP && pwps_info->wps_ap_setup_locked == WPS_SET &&
                            msg_next == WPS_MSG_NACK && msg_type == WPS_EAP_M2)
                        {
                            wps_d(
                                "WPS AP Setup is "
                                "locked because of probable attack.");
                            wps_d(
                                "WPS Registration "
                                "for AP Configuration will not continue.");
                        }
                    }
                    else
                    {
                        wps_registrar_state_transition(pwps_info, msg_type);
                        msg_next = wps_registrar_state_check(pwps_info, msg_type);
                    }
                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                    else
                        status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);
                }
                else
                    status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);

                break;
            }

            case WPS_Done:
            {
                if (pwps_info->role == WPS_REGISTRAR)
                {
                    msg_type = wps_get_message_type(peap);
                    status   = wps_done_message_process(pwps_info, (u8 *)peap, peap->length);
                    if (status == WPS_STATUS_SUCCESS)
                    {
                        wps_registrar_state_transition(pwps_info, msg_type);
                        msg_next = wps_registrar_state_check(pwps_info, msg_type);
                        if (msg_next != WPS_EAP_UNKNOWN)
                            status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                    }
                    else
                        status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);
                }
                break;
            }

            case WPS_Start:
            {
                msg_type = wps_get_message_type(peap);

                if ((msg_type > pwps_info->last_recv_wps_msg) || (msg_type == WPS_M2D) ||
                    ((pwps_info->last_recv_wps_msg == WPS_M2D) && (msg_type == WPS_M2)))
                {
                    wps_d("Last Message received 0x%x", pwps_info->last_recv_wps_msg);
                    wps_d("Current message 0x%x", msg_type);

                    if ((msg_type == pwps_info->last_recv_wps_msg) && (msg_type != WPS_M2D))
                    {
                        /** recevied the retransmitted message
                         *  use the previous transmitted message,
                         *  instead of current tx message
                         */
                        wps_d("Received reTx EAPOL Req message: 0x%x", msg_type);
                        memcpy(&pwps_info->last_message, &pwps_info->last_tx_message, sizeof(MESSAGE_BUFFER));
                    }

                    pwps_info->last_recv_wps_msg = msg_type;
                }
                else
                {
                    wps_d(
                        "rx_msg: Dropping unexpected msg! "
                        "(prev_msg: 0x%x, curr_msg: 0x%x)",
                        pwps_info->last_recv_wps_msg, msg_type);
                    break;
                }

                if (pwps_info->set_timer == WPS_SET)
                {
                    wps_cancel_timer(wps_txTimer_handler, pwps_info);
                    pwps_info->set_timer            = WPS_CANCEL;
                    pwps_info->wps_msg_resent_count = 0;
                }

                status = wps_eap_request_start_process(pwps_info, (u8 *)peap, peap->length);
                if (status == WPS_STATUS_SUCCESS)
                {
                    wps_enrollee_state_transition(pwps_info, WPS_EAP_START);

                    msg_next = wps_enrollee_state_check(pwps_info, WPS_EAP_START);
                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                    else
                        status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);
                }
                else
                {
                    wps_d("Process WPS_Start Fail !");
                }

                break;
            }

            case WPS_Ack:
                break;

            case WPS_Nack:
                msg_type = wps_get_message_type(peap);

                status = wps_nack_message_process(pwps_info, (u8 *)peap, peap->length);
                if (status == WPS_STATUS_SUCCESS)
                {
                    if (pwps_info->set_timer == WPS_SET)
                    {
                        wps_cancel_timer(wps_txTimer_handler, pwps_info);
                        pwps_info->set_timer = WPS_CANCEL;
                    }
                    if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
                    {
                        wps_enrollee_state_transition(pwps_info, msg_type);
                        msg_next = wps_enrollee_state_check(pwps_info, msg_type);
                    }
                    else
                    {
                        wps_registrar_state_transition(pwps_info, msg_type);
                        msg_next = wps_registrar_state_check(pwps_info, msg_type);
                    }
                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                }
                else
                    status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);
                break;

            default:
                break;
        }
    }
#ifdef CONFIG_WPA2_ENTP
    else if (peap->type == EAP_TYPE_TLS || peap->type == EAP_TYPE_PEAP)
    {
        peap_tls = (PEAP_TLS_FRAME_HEADER)((void *)peap);

        if (peap_tls->flags & EAP_TLS_FLAGS_START)
        {
            if (!wps_s->tls_session_init)
            {
                wps_d("%s Start Request Received", peap->type == EAP_TYPE_TLS ? "TLS" : "PEAP");

                err_count    = 0;
                req_len      = 0;
                wpa2_failure = 0;

                msg_type                                = WPS_EAP_TLS_START;
                pwps_info->last_recv_wps_msg            = msg_type;
                pwps_info->last_recv_tls_msg_identifier = peap_tls->identifier;

                pwps_info->eap_type = peap->type;

                status = os_thread_create(&wps_tls_thread, "wps_tls", wps_tls_init, 0, &wps_tls_stack, OS_PRIO_2);

                if (status != WM_SUCCESS)
                {
                    wps_d(
                        "Error: Failed to create wps_tls"
                        " thread: %d",
                        status);
                    status = WPS_STATUS_FAIL;
                }

                rbuf = (u8 *)wps_mem_malloc(TLS_RECV_BUFFER_SIZE * sizeof(u8));
                if (!rbuf)
                {
                    wps_d(
                        "Error: Failed to allocate buffer"
                        " for tls session");
                    status = WPS_STATUS_FAIL;
                    rbuf   = NULL;
                }
                rlen     = 0;
                used_len = 0;
                fragment = 0;
            }
        }
        else if (rbuf)
        {
            msg_type                                = WPS_EAP_TLS_MSG;
            pwps_info->last_recv_wps_msg            = msg_type;
            pwps_info->last_recv_tls_msg_identifier = peap_tls->identifier;

#ifdef CONFIG_PEAP_MSCHAPV2
            if (wps_s->tls_session_active)
            {
                rlen                      = 0;
                used_len                  = 0;
                size_t plain_data_max_len = 512;
                size_t plain_data_len;
                int skip_change            = 0;
                PEAP_FRAME_HEADER2 eap_hdr = (PEAP_FRAME_HEADER2)msg;

                msg_length = ntohs(peap_tls->length) - sizeof(EAP_TLS_FRAME_HEADER);
                if (msg_length)
                {
                    int ret;

                    if ((msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                    {
                        (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                            msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                        goto ret;
                    }
                    (void)memcpy(rbuf, (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER), msg_length);

                    rlen = msg_length;

                    wps_d("Tunnel EAP Request id: %d", peap_tls->identifier);
                    wps_hexdump("Encrypted Data", rbuf, rlen);

                    ret = wm_mbedtls_ssl_read(wps_s->wpa2_network.security.wlan_ssl, plain_data, plain_data_max_len);
                    if (ret < 0)
                    {
                        return WPS_STATUS_FAIL;
                    }
                    else
                    {
                        plain_data_len = (size_t)ret;
                        wps_hexdump("Plain Data", plain_data, plain_data_len);
                    }

                    eap_hdr = (PEAP_FRAME_HEADER2)plain_data;

                    if (plain_data_len == 5 && eap_hdr->code == EAP_REQUEST && ntohs(eap_hdr->length) == 5 &&
                        eap_get_type(plain_data) == EAP_TYPE_IDENTITY)
                    {
                        skip_change = 1;
                    }
                    if (plain_data_len >= 5 && eap_hdr->code == EAP_REQUEST && eap_get_type(plain_data) == EAP_TYPE_TLV)
                    {
                        skip_change = 1;
                    }

                    if (!skip_change)
                    {
                        eap_hdr = (PEAP_FRAME_HEADER2)msg;

                        eap_hdr->code       = peap_tls->code;
                        eap_hdr->identifier = peap_tls->identifier;
                        eap_hdr->length     = sizeof(EAP_FRAME_HEADER2) + plain_data_len;
                        eap_hdr->length     = htons(eap_hdr->length);

                        (void)memcpy(msg + sizeof(EAP_FRAME_HEADER2), plain_data, plain_data_len);

                        process_peap_message(msg);
                    }
                    else
                    {
                        process_peap_message(plain_data);
                    }
                }
            }
            else
            {
#endif /* CONFIG_PEAP_MSCHAPV2 */
                if ((peap_tls->flags & EAP_TLS_FLAGS_MORE_FRAGMENTS) && (!fragment))
                {
                    if (!(peap_tls->flags & EAP_TLS_FLAGS_MORE_FRAGMENTS))
                        used_len = 0;

                    msg_length = ntohs(peap_tls->length) - sizeof(EAP_TLS_FRAME_HEADER);

                    if (msg_length)
                    {
                        if (peap_tls->flags & EAP_TLS_FLAGS_LENGTH_INCLUDED)
                        {
                            msg_length -= sizeof(u32);
                            if ((msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                            {
                                (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                                    msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                                goto ret;
                            }
                            (void)memcpy(rbuf, (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER) + sizeof(u32), msg_length);
                        }
                        else
                        {
                            if ((msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                            {
                                (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                                    msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                                goto ret;
                            }
                            (void)memcpy(rbuf, (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER), msg_length);
                        }

                        fragment++;

                        rlen = msg_length;

                        wps_eap_tls_response_send(NULL, 0);
                    }
                }
                else if ((peap_tls->flags & EAP_TLS_FLAGS_LENGTH_INCLUDED) && fragment)
                {
                    msg_length = ntohs(peap_tls->length) - sizeof(EAP_TLS_FRAME_HEADER) - sizeof(u32);

                    if (msg_length)
                    {
                        if ((used_len + rlen + msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                        {
                            (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                                used_len + rlen + msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                            goto ret;
                        }
                        (void)memcpy(rbuf + used_len + rlen, (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER) + sizeof(u32),
                                     msg_length);
                        rlen += msg_length;

                        if (peap_tls->flags & EAP_TLS_FLAGS_MORE_FRAGMENTS)
                            wps_eap_tls_response_send(NULL, 0);
                        else
                        {
                            fragment--;
                            signal_receive();
                        }
                    }
                }
                else if (fragment)
                {
                    msg_length = ntohs(peap_tls->length) - sizeof(EAP_TLS_FRAME_HEADER);

                    if (msg_length)
                    {
                        if ((used_len + rlen + msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                        {
                            (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                                used_len + rlen + msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                            goto ret;
                        }
                        (void)memcpy(rbuf + used_len + rlen, (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER), msg_length);

                        rlen += msg_length;

                        if (peap_tls->flags & EAP_TLS_FLAGS_MORE_FRAGMENTS)
                            wps_eap_tls_response_send(NULL, 0);
                        else
                        {
                            fragment--;
                            signal_receive();
                        }
                    }
                }
                else
                {
                    used_len   = 0;
                    msg_length = ntohs(peap_tls->length) - sizeof(EAP_TLS_FRAME_HEADER);

                    if (msg_length)
                    {
                        if (peap_tls->flags & EAP_TLS_FLAGS_LENGTH_INCLUDED)
                        {
                            msg_length -= sizeof(u32);
                            if ((used_len + rlen + msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                            {
                                (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                                    used_len + rlen + msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                                goto ret;
                            }
                            (void)memcpy(rbuf + used_len + rlen,
                                         (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER) + sizeof(u32), msg_length);
                        }
                        else
                        {
                            if ((used_len + rlen + msg_length) > (TLS_RECV_BUFFER_SIZE * sizeof(u8)))
                            {
                                (void)PRINTF("(%s)(%d), rbuf overflow, want=%u, actual=%u\r\n", __FUNCTION__, __LINE__,
                                    used_len + rlen + msg_length, TLS_RECV_BUFFER_SIZE * sizeof(u8));
                                goto ret;
                            }
                            (void)memcpy(rbuf + used_len + rlen, (u8 *)peap + sizeof(EAP_TLS_FRAME_HEADER), msg_length);
                        }
                        rlen += msg_length;
                        signal_receive();
                    }
                }
            }
#ifdef CONFIG_PEAP_MSCHAPV2
        }
#endif
    }
#endif
    LEAVE();
    return status;

ret:
    wps_mem_free(rbuf);
    rbuf = NULL;
    rlen     = 0;
    used_len = 0;
    fragment = 0;
    return WPS_STATUS_FAIL;
}

/**
 *  @brief Process Registrar state machine checking
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param msg_type     Message type to be checked
 *  @return             Message type to be sent in current state
 */
int wps_registrar_state_check(PWPS_INFO pwps_info, u16 msg_type)
{
    int msg_next    = WPS_EAP_UNKNOWN;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    ENTER();

    switch (msg_type)
    {
        case WPS_EAP_MSG_REQUEST_IDENTITY:
            break;

        case WPS_EAPOL_MSG_START:
            if (pwps_info->state == WPS_STATE_A)
                msg_next = WPS_EAP_MSG_REQUEST_IDENTITY;
            break;
        case WPS_EAP_MSG_RESPONSE_IDENTITY:
            if ((pwps_info->state == WPS_STATE_A) || (pwps_info->state == WPS_STATE_B) ||
                (pwps_info->state == WPS_STATE_C))
                msg_next = WPS_EAP_START;
            break;
        case WPS_EAP_M1:
            if ((pwps_info->state == WPS_STATE_C) || (pwps_info->state == WPS_STATE_D) ||
                (pwps_info->state == WPS_STATE_E))
            {
                if (pwps_info->role != WFD_ROLE)
                {
                    if ((pwps_info->registrar.updated_device_password_id != pwps_info->enrollee.device_password_id) ||
                        (pwps_info->pin_pbc_set == WPS_CANCEL))
                    {
                        wps_d(
                            "Enrollee and Registrar "
                            "Device password ID dont match."
                            "Registar %d. Enrollee %d",
                            pwps_info->registrar.updated_device_password_id, pwps_info->enrollee.device_password_id);
                        wps_d("Pin PBC set value %d", pwps_info->pin_pbc_set);
                        msg_next = WPS_EAP_M2D;
                    }
                    else
                        msg_next = WPS_EAP_M2;
                }
                else
                {
                    if (pwps_info->pin_pbc_set == WPS_CANCEL)
                    {
                        wps_d("Pin PBC set value %d", pwps_info->pin_pbc_set);
                        msg_next = WPS_EAP_M2D;
                    }
                    else
                    {
                        wps_d(
                            "Ignoring Device password "
                            "ID check for WFD");
                        wps_d(
                            "Enrollee and Registrar "
                            "Device password ID dont match."
                            "Registar %d. Enrollee %d",
                            pwps_info->registrar.updated_device_password_id, pwps_info->enrollee.device_password_id);
                        msg_next = WPS_EAP_M2;
                    }
                }
            }
            break;
        case WPS_EAP_M3:
            if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_F))
                msg_next = WPS_EAP_M4;
            break;
        case WPS_EAP_M5:
            if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_F))
                msg_next = WPS_EAP_M6;
            break;
        case WPS_EAP_M7:
            if (pwps_info->state == WPS_STATE_F)
                msg_next = WPS_EAP_M8;
            break;
        case WPS_MSG_DONE:
            if (wps_s->bss_type == BSS_TYPE_STA && (pwps_info->role == WPS_REGISTRAR) &&
                pwps_info->state == WPS_STATE_E)
            {
                msg_next = WPS_MSG_ACK;
            }
            else if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_H) ||
                     (pwps_info->state == WPS_STATE_A))
                msg_next = WPS_EAP_MSG_FAIL;
            break;
        case WPS_MSG_ACK:
            if (pwps_info->state == WPS_STATE_D)
                msg_next = WPS_EAP_MSG_FAIL;
            break;
        case WPS_MSG_NACK:
            if ((wps_s->bss_type == BSS_TYPE_STA) && (pwps_info->role == WPS_REGISTRAR) &&
                pwps_info->state == WPS_STATE_H)
            {
                msg_next = WPS_MSG_NACK;
            }
            else if ((pwps_info->state == WPS_STATE_E) || (pwps_info->state == WPS_STATE_I) ||
                     (pwps_info->state == WPS_STATE_G))
                msg_next = WPS_EAP_MSG_FAIL;
            break;
        default:
            break;
    } /* end of swtich */

    wps_debug_print_msgtype("WPS Next Message", msg_next);

    LEAVE();
    return msg_next;
}

/**
 *  @brief Process Registrar state machine transition
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param msg_type     Message type for triggering state transition
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_registrar_state_transition(PWPS_INFO pwps_info, u16 msg_type)
{
    int status = WPS_STATUS_SUCCESS;

    ENTER();

    /* Current WPS State */
    wps_debug_print_state("State Transition Before", pwps_info->state);

    switch (msg_type)
    {
        case WPS_EAPOL_MSG_START:
            wps_d("Event Trigger : EAPOL_START");

            pwps_info->last_recv_wps_msg = -1;
            /* Reset Public keys and E-Hash, R-Hash */
            wps_reset_wps_state(pwps_info);
            break;
        case WPS_EAP_MSG_RESPONSE_IDENTITY:
            wps_d("Event Trigger : EAP_RESPONSE_IDENTITY");

            pwps_info->register_completed       = WPS_CANCEL;
            pwps_info->registration_in_progress = WPS_SET;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            if (pwps_info->state == WPS_STATE_A)
            {
                pwps_info->state = WPS_STATE_B;
                wps_d("State A->B");
            }
            break;
        case WPS_EAP_START:
            wps_d("Event Trigger : WPS_START");
            if (pwps_info->state == WPS_STATE_B)
            {
                pwps_info->state = WPS_STATE_C;
                wps_d("State B->C");
            }
            break;
        case WPS_EAP_M1:
            wps_d("Event Trigger : WPS_M1");

            if (pwps_info->state == WPS_STATE_C)
            {
                pwps_info->state = WPS_STATE_D;
                wps_d("State C->D");
            }
            break;
        case WPS_EAP_M2:
            wps_d("Event Trigger : WPS_M2");
            if (pwps_info->state == WPS_STATE_D)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State D->E");
            }
            break;
        case WPS_EAP_M2D:
            wps_d("Event Trigger : WPS_M2D");
            if (pwps_info->state == WPS_STATE_D)
                pwps_info->state = WPS_STATE_E;
            break;
        case WPS_EAP_M3:
            wps_d("Event Trigger : WPS_M3");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_F;
                wps_d("State E->F");
            }
            break;
        case WPS_EAP_M4:
            wps_d("Event Trigger : WPS_M4");
            if (pwps_info->state == WPS_STATE_F)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State F->E");
            }
            break;
        case WPS_EAP_M5:
            wps_d("Event Trigger : WPS_M5");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_F;
                wps_d("State E->F");
            }
            break;
        case WPS_EAP_M6:
            wps_d("Event Trigger : WPS_M6");
            if (pwps_info->state == WPS_STATE_F)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State F->E");
            }
            break;
        case WPS_EAP_M7:
            wps_d("Event Trigger : WPS_M7");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_F;
                wps_d("State E->F");
            }
            break;
        case WPS_EAP_M8:
            wps_d("Event Trigger : WPS_M8");
            if (pwps_info->state == WPS_STATE_F)
            {
                pwps_info->state = WPS_STATE_E;
                wps_d("State F->E");
            }
            break;
        case WPS_MSG_DONE:
            wps_d("Event Trigger : WPS_DONE");
            pwps_info->register_completed       = WPS_SET;
            pwps_info->registration_in_progress = WPS_CANCEL;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_H;
                wps_d("State E->H");
            }
            break;
        case WPS_MSG_ACK:
            wps_d("Event Trigger : WPS_ACK");
            if (pwps_info->state == WPS_STATE_E)
            {
                pwps_info->state = WPS_STATE_D;
                wps_d("State E->D");
            }
            break;
        case WPS_MSG_NACK:
            wps_d("Event Trigger : WPS_NACK");
            switch (pwps_info->state)
            {
                case WPS_STATE_F:
                    pwps_info->state = WPS_STATE_I;
                    wps_d("State F->I");
                    break;
                case WPS_STATE_E:
                    pwps_info->state = WPS_STATE_G;
                    wps_d("State E->G");
                    break;
            }
            break;
        case WPS_EAP_MSG_FAIL:
            wps_d("Event Trigger : EAP_FAIL");

            pwps_info->last_recv_wps_msg = -1;

            /* Reset Public keys and E-Hash, R-Hash */
            wps_reset_wps_state(pwps_info);

            switch (pwps_info->state)
            {
                case WPS_STATE_D:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State D->A");
                    break;
                case WPS_STATE_G:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State G->A");
                    break;
                case WPS_STATE_H:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State H->A");
                    break;
                case WPS_STATE_I:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State I->A");
                    break;
                case WPS_STATE_A:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State A->A");
                    break;
                case WPS_STATE_F:
                    pwps_info->state = WPS_STATE_A;
                    wps_d("State F->A");
                    break;
                default:
                    break;
            }

            break;

        default:
            break;
    } /* end of switch */

    /* New WPS State */
    wps_debug_print_state("State Transition After", pwps_info->state);

    LEAVE();
    return status;
}

/**
 *  @brief Maximum NACK error handler
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param wps_s        A pointer to WPS_DATA structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_maximum_nack_handler(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int status = WPS_STATUS_SUCCESS;
    ENTER();
#if 0
    pwps_info->nack_error_count = 0;

    if (pwps_info->set_timer == WPS_SET) {
        wps_cancel_timer(wps_txTimer_handler, pwps_info);
        pwps_info->set_timer = WPS_CANCEL;
        pwps_info->wps_msg_resent_count = 0;
    }
    if (pwps_info->role == WPS_ENROLLEE) {

        /* clear IE buffer for registrar */
        /* shutdown the main processing loop */
        /* unregister user abort handler */
#if defined(WSC2) && defined(UAP_SUPPORT)
        if (wps_s->bss_type == BSS_TYPE_UAP &&
            pwps_info->registrar.version >= WPS_VERSION_2DOT0) {
            /* Clear session start IEs for Assoc response */
            wps_wlan_ie_config(CLEAR_AR_WPS_IE,
                       &ap_assocresp_ie_index);
        }
#endif
        /*
         * Send APCMD_SYS_CONFIGURE command to set WPS IE
         */
        status = wps_wlan_ie_config(SET_WPS_IE, &ie_index);
        if (status != WPS_STATUS_SUCCESS) {
            wps_d(MSG_WARNING, "Setting WPS IE failed!!!");
        }
#if defined(WSC2) && defined(UAP_SUPPORT)
        if (pwps_info->registrar.version >= WPS_VERSION_2DOT0) {
            status =
                wps_wlan_ie_config
                (SET_WPS_AP_SESSION_INACTIVE_AR_IE,
                 &ap_assocresp_ie_index);
            if (status != WPS_STATUS_SUCCESS) {
                wps_d(MSG_WARNING,
                       "WPS IE configuration failure.\n");
            }
        }
#endif
        pwps_info->input_state = WPS_INPUT_STATE_ROLE;
        pwps_info->pin_pbc_set = WPS_CANCEL;

        wps_print_uap_role_menu(pwps_info);

        LEAVE();
        return status;
    } else if (pwps_info->role == WPS_REGISTRAR) {

        wps_d("Cancelling registration timer!");
        wps_cancel_timer(wps_registration_time_handler, pwps_info);
    /**
    * Read uAP configuration for next connection
    */
        wps_load_uap_cred(wps_s, pwps_info);

        /* For UAP mode */
        wps_s->current_ssid.mode = IEEE80211_MODE_INFRA;
        pwps_info->mode = IEEE80211_MODE_INFRA;

        /*
         * Send APCMD_SYS_CONFIGURE command to set WPS IE
         */
        status = wps_wlan_ie_config(SET_WPS_IE, &ie_index);
        if (status != WPS_STATUS_SUCCESS) {
            wps_d(MSG_WARNING, "Setting WPS IE failed!!!");
        }
        if (pwps_info->registrar.version >= WPS_VERSION_2DOT0) {
            status =
                wps_wlan_ie_config
                (SET_WPS_AP_SESSION_INACTIVE_AR_IE,
                 &ap_assocresp_ie_index);
            if (status != WPS_STATUS_SUCCESS) {
                wps_d(MSG_WARNING,
                       "WPS IE configuration failure.\n");
            }
        }
        pwps_info->input_state = WPS_INPUT_STATE_ROLE;
        pwps_info->pin_pbc_set = WPS_CANCEL;

        wps_print_uap_role_menu(pwps_info);

    }
#endif
    LEAVE();
    return status;
}

/**
 *  @brief Registrar EAP packet process handling
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param peap         A pointer to EAP frame header
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
static int wps_eap_response_message_handler(PWPS_INFO pwps_info, PEAP_FRAME_HEADER peap)
{
    int status = WPS_STATUS_SUCCESS;
    u16 msg_next, msg_type = 0;

    ENTER();

    pwps_info->peer_id = peap->identifier + 1;

    if (peap->type == EAP_TYPE_IDENTITY)
    {
        wps_debug_print_msgtype("RX WPS Message Type", WPS_EAP_MSG_RESPONSE_IDENTITY);
        if (pwps_info->set_timer == WPS_SET)
        {
            wps_cancel_timer(wps_txTimer_handler, pwps_info);
            pwps_info->set_timer            = WPS_CANCEL;
            pwps_info->wps_msg_resent_count = 0;
        }

        status = wps_eap_response_identity_process(pwps_info, (u8 *)peap, peap->length);
        if (status == WPS_STATUS_SUCCESS)
        {
            msg_type                     = WPS_EAP_MSG_RESPONSE_IDENTITY;
            pwps_info->last_recv_wps_msg = msg_type;

            if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
            {
                wps_enrollee_state_transition(pwps_info, msg_type);
                msg_next = wps_enrollee_state_check(pwps_info, msg_type);
            }
            else
            {
                wps_registrar_state_transition(pwps_info, msg_type);
                msg_next = wps_registrar_state_check(pwps_info, msg_type);
            }

            if (msg_next != WPS_EAP_UNKNOWN)
                status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
        }
    }
    else if (peap->type == EAP_TYPE_WPS)
    {
        switch (peap->op_code)
        {
            case WPS_Msg:

                msg_type = wps_get_message_type(peap);

                if ((msg_type > pwps_info->last_recv_wps_msg) || (msg_type == WPS_M2D) ||
                    ((pwps_info->last_recv_wps_msg == WPS_M2D) && (msg_type == WPS_M2)))
                {
                    wps_d("Last Message received 0x%x", pwps_info->last_recv_wps_msg);
                    wps_d("Current message 0x%x", msg_type);
                    if ((msg_type == pwps_info->last_recv_wps_msg) && (msg_type != WPS_M2D))
                    {
                        /** recevied the retransmitted message
                         *  use the previous transmitted message for auth,
                         *  instead of current tx message
                         */
                        wps_d("Received reTx EAPOL Rsp message: 0x%x", msg_type);
                        (void)memcpy(&pwps_info->last_message, &pwps_info->last_tx_message, sizeof(MESSAGE_BUFFER));
                    }

                    pwps_info->last_recv_wps_msg = msg_type;
                }
                else
                {
                    wps_d(
                        "rx_msg: Dropping unexpected msg! "
                        "(prev_msg: 0x%x, curr_msg: 0x%x)\n",
                        pwps_info->last_recv_wps_msg, msg_type);
                    break;
                }

                if (pwps_info->set_timer == WPS_SET)
                {
                    wps_cancel_timer(wps_txTimer_handler, pwps_info);
                    pwps_info->set_timer            = WPS_CANCEL;
                    pwps_info->wps_msg_resent_count = 0;
                }
                if (msg_type != WPS_EAP_UNKNOWN)
                    status = (*wps_msg_process[msg_type])(pwps_info, (u8 *)peap, peap->length);
                else
                    status = WPS_STATUS_FAIL;

                if (status == WPS_STATUS_SUCCESS)
                {
                    if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
                    {
                        wps_enrollee_state_transition(pwps_info, msg_type);
                        msg_next = wps_enrollee_state_check(pwps_info, msg_type);
                    }
                    else
                    {
                        wps_registrar_state_transition(pwps_info, msg_type);
                        msg_next = wps_registrar_state_check(pwps_info, msg_type);
                    }

                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                    else
                        status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);
                }
                else
                    status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);

                break;

            case WPS_Done:
                msg_type = wps_get_message_type(peap);

                status = wps_done_message_process(pwps_info, (u8 *)peap, peap->length);

                if (status == WPS_STATUS_SUCCESS)
                {
                    wps_registrar_state_transition(pwps_info, msg_type);

                    msg_next = wps_registrar_state_check(pwps_info, msg_type);

                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                }
                else
                    status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);

                break;

            case WPS_Ack:
                msg_type = wps_get_message_type(peap);
                status   = wps_ack_message_process(pwps_info, (u8 *)peap, peap->length);
                if (status == WPS_STATUS_SUCCESS)
                {
                    if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
                    {
                        wps_enrollee_state_transition(pwps_info, msg_type);
                        msg_next = wps_enrollee_state_check(pwps_info, msg_type);
                    }
                    else
                    {
                        wps_registrar_state_transition(pwps_info, msg_type);
                        msg_next = wps_registrar_state_check(pwps_info, msg_type);
                    }
                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                }
                else
                    status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);

                break;

            case WPS_Nack:
                msg_type = wps_get_message_type(peap);
                status   = wps_nack_message_process(pwps_info, (u8 *)peap, peap->length);
                if (status == WPS_STATUS_SUCCESS)
                {
                    if (pwps_info->set_timer == WPS_SET)
                    {
                        wps_cancel_timer(wps_txTimer_handler, pwps_info);
                        pwps_info->set_timer = WPS_CANCEL;
                    }
                    if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
                    {
                        wps_enrollee_state_transition(pwps_info, msg_type);
                        msg_next = wps_enrollee_state_check(pwps_info, msg_type);
                    }
                    else
                    {
                        wps_registrar_state_transition(pwps_info, msg_type);
                        msg_next = wps_registrar_state_check(pwps_info, msg_type);
                    }
                    if (msg_next != WPS_EAP_UNKNOWN)
                        status = wps_msg_transmit(pwps_info, msg_next, pwps_info->wps_msg_timeout);
                }
                else
                    status = wps_msg_transmit(pwps_info, WPS_MSG_NACK, pwps_info->wps_msg_timeout);

                break;

            default:
                break;
        }
    }

    LEAVE();
    return status;
}

/********************************************************
        Global Functions
********************************************************/

/**
 *  @brief EAP frame handling function
 *
 *  @param buffer       A pointer to frame received buffer
 *  @param src_addr     A pointer to source address of received frame
 *  @return             None
 */
void wps_message_handler(u8 *buffer, u8 *src_addr)
{
    PEAPOL_FRAME_HEADER peapol;
    PEAP_FRAME_HEADER peap;
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
    int status      = WPS_STATUS_SUCCESS;
    int ret;

    ENTER();

    pwps_info = wps_get_private_info();

    peapol = (PEAPOL_FRAME_HEADER)buffer;
    switch (peapol->packet_type)
    {
        case EAP_PACKET:
        {
            peap = (PEAP_FRAME_HEADER)(buffer + sizeof(EAPOL_FRAME_HEADER));

            pwps_info->peer_id = peap->identifier;

            switch (peap->code)
            {
                case EAP_REQUEST:
                    wps_d("EAP_REQUEST received");

                    if (wps_s->bss_type == BSS_TYPE_UAP)
                    {
                        if ((pwps_info->role == WPS_REGISTRAR &&
                             memcmp(pwps_info->enrollee.mac_address, src_addr, ETH_ALEN)) ||
                            (pwps_info->role == WPS_ENROLLEE &&
                             memcmp(pwps_info->registrar.mac_address, src_addr, ETH_ALEN)))
                        {
                            wps_d(
                                "EAP_REQUEST received "
                                "from invalid source " MACSTR " dropped!",
                                MAC2STR(src_addr));
                            break;
                        }
                    }

                    wps_eap_request_message_handler(pwps_info, peap);
                    break;
                case EAP_RESPONSE:
                    wps_d("EAP_RESPONSE received");

                    if (wps_s->bss_type == BSS_TYPE_UAP)
                    {
                        if ((pwps_info->role == WPS_REGISTRAR &&
                             memcmp(pwps_info->enrollee.mac_address, src_addr, ETH_ALEN)) ||
                            (pwps_info->role == WPS_ENROLLEE &&
                             memcmp(pwps_info->registrar.mac_address, src_addr, ETH_ALEN)))
                        {
                            wps_d(
                                "EAP_RESPONSE received "
                                "from invalid source " MACSTR " dropped!",
                                MAC2STR(src_addr));
                            break;
                        }
                    }

                    wps_eap_response_message_handler(pwps_info, peap);
                    break;
#ifdef CONFIG_WPA2_ENTP
                case EAP_SUCCESS:
                {
#ifdef CONFIG_PEAP_MSCHAPV2
                    if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
                    {
                        wpa2_session_success();
                        wpa2_session_clean();
                        wpa2_shutdown();
                    }
#endif
#if 0
                    /* Here WPA2 ENT protocol is finished so
                     * shutdown main processing thread
                     */
                    wpa2_shutdown();
#endif
                }
                break;
#endif

                case EAP_FAILURE:
                {
#ifdef CONFIG_WPA2_ENTP
                    if (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT)
                    {
                        wpa2_failure = 1;
                        if (wps.cb(WPS_SESSION_FAILED, NULL, 0) == -WM_FAIL)
                            wps_d(
                                "WPS Callback "
                                "failed for event:"
                                "%d",
                                WPS_SESSION_FAILED);
                        wps_d(
                            "WPA2 Enterprise (EAP) "
                            "Registration "
                            "protocol failed !");
                    }
                    else
#endif
                    {
                        wps_d("EAP_FAILURE received");
                        wps_d(
                            "RX WPS Message Type: "
                            "EAP_FAIL");

                        if (pwps_info->set_timer == WPS_SET)
                        {
                            wps_cancel_timer(wps_txTimer_handler, pwps_info);
                            pwps_info->set_timer            = WPS_CANCEL;
                            pwps_info->wps_msg_resent_count = 0;
                        }
                        if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
                        {
                            wps_enrollee_state_transition(pwps_info, WPS_EAP_MSG_FAIL);
                        }
                        else
                        {
                            wps_registrar_state_transition(pwps_info, WPS_EAP_MSG_FAIL);
                        }

                        if (pwps_info->invalid_credential == WPS_SET)
                        {
                            if ((pwps_info->role == WPS_ENROLLEE) || IS_DISCOVERY_ENROLLEE(pwps_info))
                            {
                                /* clear IE buffer for registrar */
                                /* shutdown the main processing loop */
                                /* unregister user abort handler */
                                wps_shutdown();
                            }
                        }
                        if (pwps_info->state == WPS_STATE_A && pwps_info->register_completed == WPS_SET)
                        {
                            pwps_info->wps_session = 0;

                            /*
                             * Registration complete with M8 received.
                             */
                            assoc_ie_index = 0x0002;
                            ret            = wps_wlan_ie_config(CLEAR_STA_WPS_IE, &assoc_ie_index);
                            if (ret != WPS_STATUS_SUCCESS)
                            {
                                wps_d("WPS IE configuration failure.\n");
                            }
                            wps_d(
                                "WPS Registration Protocol"
                                " Completed Successfully !");
                            pwps_info->wps_session = 0;

                            ret = wlan_disconnect();
                            if (ret != 0)
                                wps_d("Failed to disconnect");

                            ret = wlan_remove_network(wps_network.name);

                            if (ret != 0)
                                wps_d("Failed to remove network");

                            /* Single Credential */
                            status = wps_write_credentials(pwps_info);

                            if (pwps_info->role == WPS_REGISTRAR)
                            {
                                (void)memset(&pwps_info->enrollee.mac_address, 0, ETH_ALEN);
                            }
                            /* message exchange completed */
                            if (status != WPS_STATUS_SUCCESS)
                            {
                                wps_d(
                                    "Failed to generate WPS "
                                    "Registration configuration "
                                    "file !");
                            }
                            /* Cancel WPS Registration Timer */

                            wps_d("Cancelling registration timer!");
                            wps_cancel_timer(wps_registration_time_handler, pwps_info);
                            if (wps.cb(WPS_SESSION_SUCCESSFUL, &wps_global.wps_conn_network,
                                       sizeof(struct wlan_network)) == -WM_FAIL)
                                wps_d("Callback failed for event: %d", WPS_SESSION_SUCCESSFUL);
                            wps_shutdown();
                        }
                        else
                        {
                            wps_d(
                                "WPS Registration "
                                "Protocol Failed !");

                            pwps_info->wps_session = 0;
                            pwps_info->p2p_session = 0;

                            ret = wlan_disconnect();
                            if (ret != 0)
                                wps_d("Failed to disconnect");

                            ret = wlan_remove_network(wps_network.name);
                            if (ret != 0)
                                wps_d("Failed to remove network");

                            wps_d(
                                "Cancelling "
                                "registration timer!");
                            wps_cancel_timer(wps_registration_time_handler, pwps_info);
                            if (wps.cb(WPS_SESSION_FAILED, NULL, 0) == -WM_FAIL)
                                wps_d(
                                    "WPS Callback failed for event:"
                                    "%d\r\n",
                                    WPS_SESSION_FAILED);
                        }
                    } /* EAP_FAILURE */
                }
                break;

                default:
                    wps_d("Unknown Code received");
                    break;
            }
            break;
        } /* EAP_PACKET */
        case EAPOL_START:
        {
            wps_d("EAPOL_START received");

            if (pwps_info->registration_in_progress == WPS_SET)
            {
                if (memcmp(pwps_info->enrollee.mac_address, src_addr, ETH_ALEN))
                {
                    wps_d("EAPOL_START received from " MACSTR " while session is in progress with " MACSTR,
                          MAC2STR(src_addr), MAC2STR(pwps_info->enrollee.mac_address));
                    wps_d("EAPOL_START dropped!!");
                    return;
                }
            }
            if ((pwps_info->role == WPS_REGISTRAR) || (IS_DISCOVERY_REGISTRAR(pwps_info)))
            {
                /* Get Enrollee Peer Address */
                (void)memcpy(pwps_info->enrollee.mac_address, src_addr, ETH_ALEN);
                wps_d("Peer Address Get: ");
                wps_hexdump("pwps_info->enrollee.mac_address", pwps_info->enrollee.mac_address, ETH_ALEN);

                wps_eapol_start_handler(pwps_info);
                wps_eap_request_identity_prepare(pwps_info);

                wps_d(
                    "eap_msg_sent = "
                    "WPS_EAP_MSG_REQUEST_IDENTITY");
                pwps_info->eap_msg_sent = WPS_EAP_MSG_REQUEST_IDENTITY;
            }

            break;
        } /* EAPOL_START */
#if 0
        case EAPOL_KEY_PACKET:
                wpa_rx_eapol(src_addr, buffer,
                sizeof(EAPOL_FRAME_HEADER) + ntohs(peapol->length));
            break;
#endif
        default:
            wps_d("Unknown Packet Type %d", peapol->packet_type);
            wps_hexdump("Packet Dump", buffer, sizeof(EAPOL_FRAME_HEADER) + ntohs(peapol->length));
            break;
    }

    LEAVE();
}

/**
 *  @brief WPS EAP frame transmit function
 *
 *  @param pwps_info    A pointer to PWPS_INFO structure
 *  @param msg_type     message type
 *  @param timeout      timeout
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_msg_transmit(PWPS_INFO pwps_info, u16 msg_type, u32 timeout)
{
    int status = WPS_STATUS_SUCCESS;
    u32 sec, usec;
    WPS_DATA *wps_s = &wps_global;

    ENTER();
    wps_debug_print_msgtype("TX WPS Message Type", msg_type);

    if ((pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT) || (msg_type == WPS_EAP_MSG_RESPONSE_IDENTITY))
        status = (*wps_msg_prepare[msg_type])(pwps_info);

    if (status == WPS_STATUS_SUCCESS)
    {
        pwps_info->eap_msg_sent = msg_type;

        if (pwps_info->role == WPS_ENROLLEE)
        {
            wps_enrollee_state_transition(pwps_info, msg_type);
        }
        else if (pwps_info->role == WPS_REGISTRAR)
        {
            wps_registrar_state_transition(pwps_info, msg_type);
        }
        else if (pwps_info->role == WFD_ROLE)
        {
            if (pwps_info->discovery_role == WPS_REGISTRAR)
            {
                wps_registrar_state_transition(pwps_info, msg_type);
            }
            else
            {
                wps_enrollee_state_transition(pwps_info, msg_type);
            }
        }
    }

    if (msg_type != WPS_EAP_MSG_FAIL)
    {
        sec  = timeout / 1000;
        usec = (timeout % 1000) * 1000;
        wps_start_timer(sec, usec, wps_txTimer_handler, pwps_info);
        pwps_info->set_timer = WPS_SET;
        pwps_info->wps_msg_resent_count++;
    }
    else
    {
        wps_eap_fail_transmit_handler(pwps_info, wps_s);
    }

    LEAVE();
    return status;
}

/**
 *  @brief WPS EAP fail frame transmit handler
 *
 *  @param pwps_info    A pointer to PWPS_INFO structure
 *  @param wps_s        A pointer to WPS_DATA structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_eap_fail_transmit_handler(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int status       = WPS_STATUS_SUCCESS;
    u8 *sta_mac_addr = NULL;
    ENTER();
    /* registrar send out EAP-FAIL */
    /* WPS process complete */

    pwps_info->registration_in_progress = WPS_CANCEL;
    wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

    if (pwps_info->set_timer == WPS_SET)
    {
        wps_cancel_timer(wps_txTimer_handler, pwps_info);
        pwps_info->set_timer            = WPS_CANCEL;
        pwps_info->wps_msg_resent_count = 0;
    }
    if (wps_s->bss_type == BSS_TYPE_UAP)
    {
        if (pwps_info->role == WPS_REGISTRAR || (IS_DISCOVERY_REGISTRAR(pwps_info)))
            sta_mac_addr = pwps_info->enrollee.mac_address;
        else
            sta_mac_addr = pwps_info->registrar.mac_address;
        if (sta_mac_addr != NULL)
        {
            wps_d("Delay sending DEAUTH by 200 milli-seconds!");
#if 0
            usleep(200000);
            wps_hexdump("Deauth Mac Address",
                    sta_mac_addr, ETH_ALEN);
            status = apcmd_station_deauth(sta_mac_addr);
#endif
        }
    }
    status = wps_uap_session_complete_handler(pwps_info, wps_s);

    LEAVE();
    return status;
}

/**
 *  @brief WPS uAP session complete handler
 *
 *  @param pwps_info    A pointer to PWPS_INFO structure
 *  @param wps_s        A pointer to WPS_DATA structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_uap_session_complete_handler(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int status = WPS_STATUS_SUCCESS;

    ENTER();

    if (wps_s->bss_type == BSS_TYPE_UAP && pwps_info->register_completed == WPS_SET)
    {
        if ((pwps_info->role == WPS_REGISTRAR) || (pwps_info->role == WFD_ROLE))
        {
            /* Cancel WPS Registration Timer */
            wps_d("Cancelling registration timer!");
            wps_cancel_timer(wps_registration_time_handler, pwps_info);
        }

        if (pwps_info->register_completed == WPS_SET)
        {
            pwps_info->wps_session = 0;
            if (wps.cb(WPS_SESSION_SUCCESSFUL, NULL, 0) == -WM_FAIL)
                wps_d("Callback failed for event: %d", WPS_SESSION_SUCCESSFUL);

            /* shutdown the main processing loop */
            wps_main_loop_shutdown();
        }
#if 0
        status = wps_wlan_reset_ap_config(wps_s, pwps_info);
#endif
    }
    LEAVE();
    return status;
}

/**
 *  @brief Check WLAN Link Status & Reconnect if disconnected
 *
 *  @param wps_s        A pointer to PWPS_DATA structure
 *  @param pwps_info    A pointer to PWPS_INFO structure
 *  @param reconnected  A pointer to variable to indicate if STA re-connected
 *  @return             1-connected, 0-not connected
 */

static int wps_sta_check_link_active(WPS_DATA *wps_s, PWPS_INFO pwps_info, int *reconnected)
{
    int ret       = WPS_STATUS_SUCCESS;
    int retry_cnt = 2;
    int connect_retry;
    int link_active = 0;
    enum wlan_connection_state state;

    *reconnected = 0;

    if (wlan_get_connection_state(&state))
    {
        wps_d("Error: unable to get connection state");
        return 0;
    }

    /* link is active if it is in connected state as well */
    if (state == WLAN_ASSOCIATED || state == WLAN_CONNECTED)
    {
        /* Link not lost */
        link_active = 1;
        return link_active;
    }

    if (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT)
    {
        wps_d("Connection with AP lost..... ");
    }
    else
    {
        *reconnected = 1;

        do
        {
            wps_d("Connection lost, try to re-connect to AP .....");

            ret = wlan_connect(wps_network.name);

            if (ret != 0)
            {
                wps_d("Failed to connect %d\r\n", ret);
                goto retry;
            }

            connect_retry = 100;

            do
            {
                /* wait for interface up */
                os_thread_sleep(os_msec_to_ticks(50));

                if (wlan_get_connection_state(&state))
                {
                    wps_d(
                        "Error: unable to get "
                        "connection state\r\n");
                    continue;
                }

                if (state == WLAN_ASSOCIATED)
                {
                    link_active = 1;
                    goto done;
                }

            } while (connect_retry--);

        retry:
            retry_cnt--;

        } while (retry_cnt != 0);
    }
done:
    return link_active;
}

/**
 *  @brief Re-Transmit the last TX'ed packet
 *
 *  @param pwps_info    A pointer to PWPS_INFO structure
 *  @return             WPS_STATUS_SUCCESS--retransmit success, otherwise--fail
 */

static int retransmit_last_tx_pkt(PWPS_INFO pwps_info)
{
    PEAP_FRAME_HEADER peap_wps_frame = (PEAP_FRAME_HEADER)pwps_info->buffer;
    int pkt_len                      = ntohs(peap_wps_frame->length);
    int ret;

    wps_debug_print_msgtype("ReTX WPS Message Type", pwps_info->eap_msg_sent);

    if (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT)
    {
        ret = wps_eapol_txPacket((u8 *)pwps_info->buffer, pkt_len);

        wps_start_timer((pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT) ? (WPA2_MSG_DEFAULT_TIMEOUT / 1000) :
                                                                                 (WPS_MSG_DEFAULT_TIMEOUT / 1000),
                        0, wps_txTimer_handler, pwps_info);
        pwps_info->set_timer = WPS_SET;
        pwps_info->wps_msg_resent_count++;
    }
    else
    {
        if (pwps_info->eap_msg_sent != WPS_EAPOL_MSG_START)
        {
            ret = wps_eapol_txPacket((u8 *)pwps_info->buffer, pkt_len);

            wps_start_timer((pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT) ? (WPA2_MSG_DEFAULT_TIMEOUT / 1000) :
                                                                                     (WPS_MSG_DEFAULT_TIMEOUT / 1000),
                            0, wps_txTimer_handler, pwps_info);
            pwps_info->set_timer = WPS_SET;
            pwps_info->wps_msg_resent_count++;
        }
        else
        {
            ret = wps_msg_transmit(pwps_info, WPS_EAPOL_MSG_START,
                                   (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT) ? WPA2_MSG_DEFAULT_TIMEOUT :
                                                                                            WPS_MSG_DEFAULT_TIMEOUT);
        }
    }

    return ret;
}

/**
 *  @brief WPS frame transmit time-out handler
 *
 *  @param user_data    User private data
 *  @return             None
 */
void wps_txTimer_handler(void *user_data)
{
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
    int status      = WPS_STATUS_SUCCESS;
    int reconnected = 0, link_active = 0;

    ENTER();

    pwps_info = (PWPS_INFO)user_data;

    if (pwps_info->set_timer == WPS_SET)
    {
        wps_cancel_timer(wps_txTimer_handler, pwps_info);
        pwps_info->set_timer = WPS_CANCEL;
    }
    /*
     * Some AP/External Registrar will disconnect after EAP-FAIL
     * packet sent without M2D being sent before that.
     * So, polling link status of AP to restart registration here.
     */
    if (wps_s->bss_type == BSS_TYPE_STA)
    {
        link_active = wps_sta_check_link_active(wps_s, pwps_info, &reconnected);

        if (!link_active)
        {
#ifdef CONFIG_WPA2_ENTP
            if (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT)
            {
                wpa2_failure = 1;
            }
            else
#endif
            {
                wps_d("WPS Registration protocol failed !");
            }
            /* shutdown the main processing loop */
            wps_main_loop_shutdown();
            pwps_info->wps_session = 0;

            if (pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT)
            {
                int ret = wlan_disconnect();
                if (ret != 0)
                    wps_d("Failed to disconnect");

                ret = wlan_remove_network(wps_network.name);
                if (ret != 0)
                    wps_d("Failed to remove network");
            }

            if (pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT)
            {
                if (wps.cb(WPS_SESSION_FAILED, NULL, 0) == -WM_FAIL)
                    wps_d(
                        "WPS Callback failed for event:"
                        "%d",
                        WPS_SESSION_FAILED);
            }
            status = WPS_STATUS_FAIL;
            goto done;
        }

        if (pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT)
        {
            if (reconnected)
            {
                pwps_info->restart_link_lost = WPS_SET;
                wps_d("Connected to following BSS (or IBSS) :");
                wps_d("SSID = [%s], BSSID = [%02x:%02x:%02x:%02x:%02x:%02x]", wps_network.ssid, wps_network.bssid[0],
                      wps_network.bssid[1], wps_network.bssid[2], wps_network.bssid[3], wps_network.bssid[4],
                      wps_network.bssid[5]);
                wps_d("WPS Registration Protocol Restarted .....");
            }

            if (pwps_info->restart_link_lost || pwps_info->restart_by_M2D)
            {
                pwps_info->restart_link_lost = WPS_CANCEL;
                pwps_info->restart_by_M2D    = WPS_CANCEL;

                pwps_info->state = WPS_STATE_A;
                pwps_info->id    = 1;

                /* Reset Public keys and E-Hash, R-Hash */
                wps_reset_wps_state(pwps_info);

                pwps_info->last_recv_wps_msg    = -1;
                pwps_info->wps_msg_resent_count = 0;
                pwps_info->eap_msg_sent         = WPS_EAPOL_MSG_START;
                status =
                    wps_msg_transmit(pwps_info, WPS_EAPOL_MSG_START,
                                     (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT) ? WPA2_MSG_DEFAULT_TIMEOUT :
                                                                                              WPS_MSG_DEFAULT_TIMEOUT);

                goto done;
            }
        }
    }
    retransmit_last_tx_pkt(pwps_info);

done:
    if (status != WPS_STATUS_SUCCESS)
    {
        if (wps_s->bss_type == BSS_TYPE_UAP)
        {
            pwps_info->wps_session = 0;
        }
        else
        {
            /* Cancel WPS Registration Timer */
            wps_d("Cancelling registration timer!");
            wps_cancel_timer(wps_registration_time_handler, pwps_info);

            if (pwps_info->set_timer == WPS_SET)
            {
                wps_cancel_timer(wps_txTimer_handler, pwps_info);
                pwps_info->set_timer            = WPS_CANCEL;
                pwps_info->wps_msg_resent_count = 0;
            }

            pwps_info->registration_fail        = WPS_SET;
            pwps_info->registration_in_progress = WPS_CANCEL;
            wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

            wps_d("State *->A");
            pwps_info->state = WPS_STATE_A;
            /* Reset Public keys and E-Hash, R-Hash */
            wps_reset_wps_state(pwps_info);
        }
    }

    LEAVE();
    return;
}

/**
 *  @brief Start WPS registration timer
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
void wps_start_registration_timer(PWPS_INFO pwps_info)
{
    u32 sec, usec;

    /* Start a timer for WPS registration protocol timeout */
    wps_d("Start Timer for WPS Registration ... ");
    sec  = WPS_REGISTRATION_TIME;
    usec = 0;
    wps_start_timer(sec, usec, wps_registration_time_handler, pwps_info);

    return;
}

/**
 *  @brief Start WPS state machine
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_state_machine_start(PWPS_INFO pwps_info)
{
    int status = WPS_STATUS_SUCCESS;

    if (pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT)
    {
        WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

        if (((pwps_info->role == WPS_ENROLLEE) && wps_s->bss_type == BSS_TYPE_STA) ||
            (IS_DISCOVERY_ENROLLEE(pwps_info)))
        {
            /*
             * Start to exchange WPS Message by sending EAPOL_START packet
             */
            pwps_info->eap_msg_sent = WPS_EAPOL_MSG_START;
            status =
                wps_msg_transmit(pwps_info, WPS_EAPOL_MSG_START,
                                 (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT) ? WPA2_MSG_DEFAULT_TIMEOUT :
                                                                                          WPS_MSG_DEFAULT_TIMEOUT);
        }
    }
    return status;
}

/**
 *  @brief Time-out handler of WPS Registration (300 seconds), program will
 *          exit if registration not completed within this time.
 *
 *  @param user_data    A pointer to user data of timer functions
 *  @return             None
 */
void wps_registration_time_handler(void *user_data)
{
    int ret;
    PWPS_INFO pwps_info;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
    ENTER();

    pwps_info = (PWPS_INFO)user_data;

    wps_d("WPS Registration Timeout !");

    /* Cancel WPS Registration Timer */
    wps_d("Cancelling registration timer!");
    wps_cancel_timer(wps_registration_time_handler, pwps_info);

    /* Cancel packet Tx timer */
    if (pwps_info->set_timer == WPS_SET)
    {
        wps_cancel_timer(wps_txTimer_handler, pwps_info);
        pwps_info->set_timer            = WPS_CANCEL;
        pwps_info->wps_msg_resent_count = 0;
    }

    if ((wps_s->bss_type == BSS_TYPE_STA && pwps_info->role == WPS_ENROLLEE) || (IS_DISCOVERY_ENROLLEE(pwps_info)))
    {
        if (pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT)
        {
            if (wps.cb(WPS_SESSION_TIMEOUT, NULL, 0) == -WM_FAIL)
                wps_d("WPS Callback failed for event: %d", WPS_SESSION_TIMEOUT);
        }

        if (pwps_info->prov_session != PROV_ENTP_SESSION_ATTEMPT)
        {
            ret = wlan_disconnect();
            if (ret != 0)
                wps_d("Failed to disconnect");

            ret = wlan_remove_network(wps_network.name);
            if (ret != 0)
                wps_d("Failed to remove network");
            wps_d("WPS registration timer time-out.");
            wps_d("WPS Registration Protocol Not Completed!");

            /* shutdown the main processing loop */
            wps_main_loop_shutdown();
        }
#ifdef CONFIG_WPA2_ENTP
        else
        {
            wpa2_failure = 1;

            /* shutdown the main processing loop */
            wps_main_loop_shutdown();
        }
#endif
        pwps_info->wps_session = 0;
    }
    else if ((wps_s->bss_type == BSS_TYPE_UAP && pwps_info->role == WPS_REGISTRAR) ||
             (IS_DISCOVERY_REGISTRAR(pwps_info)))
    {
        wps_d("WPS Registration timeout!!");
        wps_d("Restarting WPS Registration.");

        pwps_info->wps_session = 0;

        /* shutdown the main processing loop */
        wps_main_loop_shutdown();
        if (wps.cb(WPS_SESSION_TIMEOUT, NULL, 0) == -WM_FAIL)
            wps_d("WPS Callback failed for event: %d", WPS_SESSION_TIMEOUT);

            /* Shutdown main loop will cause registrar restart */
#if 0
        pwps_info->input_state = WPS_INPUT_STATE_ROLE;
        pwps_info->pin_pbc_set = WPS_CANCEL;

        wps_print_uap_role_menu(pwps_info);

        ret = wps_wlan_ie_config(SET_WPS_IE, &ie_index);
        if (ret != WPS_STATUS_SUCCESS) {
            wps_d(MSG_WARNING, "Setting WPS IE failed!!!");
        }
        if (pwps_info->role == WPS_REGISTRAR) {
            if (pwps_info->registrar.version >= WPS_VERSION_2DOT0) {
                ret =
                    wps_wlan_ie_config
                    (SET_WPS_AP_SESSION_INACTIVE_AR_IE,
                     &ap_assocresp_ie_index);
                if (ret != WPS_STATUS_SUCCESS) {
                    wps_d(MSG_WARNING,
                       "WPS IE configuration failure.\n");
                }
            }
        } else if (pwps_info->role == WPS_ENROLLEE) {
            if (pwps_info->enrollee.version >= WPS_VERSION_2DOT0) {
                ret =
                    wps_wlan_ie_config
                    (SET_WPS_AP_SESSION_INACTIVE_AR_IE,
                     &ap_assocresp_ie_index);
                if (ret != WPS_STATUS_SUCCESS) {
                    wps_d(MSG_WARNING,
                       "WPS IE configuration failure.\n");
                }
            }
        }
#endif
    }

    LEAVE();
}

/**
 *  @brief EAPOL-Start handler of WPS Registration
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             None
 */
void wps_eapol_start_handler(WPS_INFO *pwps_info)
{
    ENTER();

    wps_d("EAPOL-Start received. Aborting EAPOL State machine...");
    /* Cancel packet Tx timer */
    if (pwps_info->set_timer == WPS_SET)
    {
        wps_cancel_timer(wps_txTimer_handler, pwps_info);
        pwps_info->set_timer            = WPS_CANCEL;
        pwps_info->wps_msg_resent_count = 0;
    }
    wps_d("State *->A");
    pwps_info->state = WPS_STATE_A;
    /* Reset Public keys and E-Hash, R-Hash */
    wps_reset_wps_state(pwps_info);
    LEAVE();
}

/**
 *  @brief EAPOL-Start handler of WPS Registration
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             None
 */
void wps_reset_wps_state(WPS_INFO *pwps_info)
{
    ENTER();
    wps_d("Resetting E-HASH, R-HASH and public keys");
    (void)memset(pwps_info->enrollee.e_hash1, 0, 32);
    (void)memset(pwps_info->enrollee.e_hash2, 0, 32);
    (void)memset(pwps_info->enrollee.r_hash1, 0, 32);
    (void)memset(pwps_info->enrollee.r_hash2, 0, 32);
    (void)memset(pwps_info->enrollee.public_key, 0, 192);
    (void)memset(pwps_info->registrar.public_key, 0, 192);
    if (pwps_info->last_message.length)
    {
        (void)memset(pwps_info->last_message.message, 0, pwps_info->last_message.length);
    }
    pwps_info->last_message.length = 0;
    pwps_info->last_recv_wps_msg   = 0;
    LEAVE();
}
