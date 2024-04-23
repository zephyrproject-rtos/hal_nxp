/** @./middleware/wifi/wps/wps_main.cfile wps_main.c
 *
 *  @brief This file contains WPS application program entry function
 *  and functions for initialization setting.
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wifi_nxp_wps.h"
#include <lwip/sys.h>
#include <lwip/inet.h>
#include <wm_os.h>
#include "wmcrypto.h"

#include "wps_msg.h"

#ifdef CONFIG_FSL_AES
#include "fsl_aes.h"
#endif
#include "wps_mem.h"
#include "wps_def.h"
#include "wps_wlan.h"
#include "wps_os.h"
#include "wps_eapol.h"

/********************************************************
        Local Variables
********************************************************/
#define MAX_COMMANDS 4
#define MAX_MSGS     4

#define RX_WAIT OS_WAIT_FOREVER
#define APP_AES AES

/********************************************************
        Global Variables
********************************************************/
/** Global pwps information */
PWPS_INFO gpwps_info;
/** wps global */
WPS_DATA wps_global PM3_BSS;

bool gpwps_info_initialized;

#ifdef CONFIG_WPA2_ENTP
/** WPA sm */
WPA_SM wpa_sm;
#endif

extern WPS_LOOP_S wps_loop;

u8 *g_ssid  = NULL;
u8 *g_bssid = NULL;
u8 g_channel;
int g_method  = -1;
u32 g_gen_pin = 0;
extern u8 auto_go;
extern char WFD_devicename[33];
u8 p2p_scan_on;
u8 go_request;
u8 pd_request;

/** IE buffer index */
static short ie_index = 0x0002;
short assoc_ie_index  = 0x0002;
short ap_assocresp_ie_index;


static os_queue_pool_define(wps_cmd_queue_data, sizeof(struct prov_command **) * MAX_COMMANDS);

static os_queue_pool_define(wps_data_queue_data, sizeof(struct wps_msg) * MAX_MSGS);

struct wps_thread_t wps;
struct wps_config *local_wcc = NULL;

extern int wpa2_failure;

os_thread_t wps_main_thread;
static os_thread_stack_define(wps_stack, 10240);


extern void wps_register_rx_callback(void (*WPSEAPoLRxDataHandler)(const u8 *buf, const size_t len));
extern void wps_deregister_rx_callback();

/********************************************************
        Local Functions
********************************************************/

/**
 *  @brief Allocate buffer for WPS_INFO structure
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
static int wps_private_info_allocate(PWPS_INFO *pwps_info)
{
    if (gpwps_info_initialized)
        return WPS_STATUS_SUCCESS;

    PWPS_INFO temp;

    ENTER();

    temp = wps_mem_calloc(1, sizeof(WPS_INFO));

    if (!temp)
    {
        wps_d("Allocate buffer for WPS_INFO failed!\n");

        LEAVE();
        return WPS_STATUS_FAIL;
    }
    *pwps_info = temp;

    g_bssid = wps_mem_malloc(ETH_ALEN);

    if (!g_bssid)
    {
        LEAVE();
        return WPS_STATUS_FAIL;
    }

    g_ssid = wps_mem_malloc(MAX_SSID_LEN + 1);

    if (!g_ssid)
    {
        LEAVE();
        return WPS_STATUS_FAIL;
    }
    LEAVE();

    gpwps_info_initialized = true;

    return WPS_STATUS_SUCCESS;
}


/**
 *  @brief Set the method of Device Password ID (PIN or PBC)
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             None
 */
void wps_set_device_password_id(PWPS_INFO pwps_info)
{
    int index = -1;
    int i;
    MESSAGE_ENROLLEE_REGISTRAR *en_reg;

    ENTER();

    /* Set Default PIN to all '0' */
    for (i = 0; i < 8; i++)
        pwps_info->PIN[i] = 0x30;

    if (g_method == 0 || g_method == 1)
    {
        wps_d("setting g_method %d\n", g_method);
        index = g_method;
    }

    if (index == 1)
    {
        pwps_info->registrar.device_password_id         = DEVICE_PASSWORD_PUSH_BUTTON;
        pwps_info->registrar.updated_device_password_id = DEVICE_PASSWORD_PUSH_BUTTON;

        pwps_info->enrollee.device_password_id         = DEVICE_PASSWORD_PUSH_BUTTON;
        pwps_info->enrollee.updated_device_password_id = DEVICE_PASSWORD_PUSH_BUTTON;
        pwps_info->input_state                         = WPS_INPUT_STATE_NO_INPUT;
        pwps_info->pin_pbc_set                         = WPS_SET;
        wps_d("Device Password ID select : [%d]\n", index);
    }
    else if (index == 0)
    {
        pwps_info->registrar.device_password_id         = DEVICE_PASSWORD_ID_PIN;
        pwps_info->registrar.updated_device_password_id = DEVICE_PASSWORD_ID_PIN;

        pwps_info->enrollee.device_password_id         = DEVICE_PASSWORD_ID_PIN;
        pwps_info->enrollee.updated_device_password_id = DEVICE_PASSWORD_ID_PIN;
        wps_d("Device Password ID select : [%d]\n", index);
        if (pwps_info->pin_generator == WPS_ENROLLEE)
        {
            pwps_info->input_state = WPS_INPUT_STATE_NO_INPUT;
            pwps_info->pin_pbc_set = WPS_SET;
        }
        else
        {
            pwps_info->input_state = WPS_INPUT_STATE_READ_PIN;
        }
    }

    en_reg = ((pwps_info->role == WPS_ENROLLEE) ? &pwps_info->enrollee : &pwps_info->registrar);

    if (en_reg->device_password_id == DEVICE_PASSWORD_PUSH_BUTTON)
    {
        /* Override User's pin length to 8 for PBC */
        pwps_info->PINLen = 8;
    }

    LEAVE();
}

/**
 *  @brief  Generate 16 Bytes Nonce
 *
 *  @param buf      A pointer to store nonce
 *  @return         None
 */
void wps_generate_nonce_16B(u8 *buf)
{
    int i, randNum;
    unsigned int seed;

    ENTER();

    seed = os_ticks_get();

    for (i = 0; i < 4; i++)
    {
        srand(seed);
        randNum = rand();
        (void)memcpy(buf + i * 4, &randNum, sizeof(int));
        seed = seed * 1103515245 + 12345 * i;
    }

    LEAVE();
}

/**
 *  @brief Generate UUID using local MAC address
 *
 *  @param mac_addr     A pointer to local MAC address
 *  @param wps_s        A pointer to UUID
 *  @return             None
 */
void wps_generate_uuid_using_mac_addr(const u8 *mac_addr, u8 *uuid)
{
    const u8 *addr[2];
    size_t len[2];
    int ret;
    u8 hash[SHA1_MAC_LEN];
    u8 nsid[16] = {0x52, 0x64, 0x80, 0xf8, 0xc9, 0x9b, 0x4b, 0xe5, 0xa6, 0x55, 0x58, 0xed, 0x5f, 0x5d, 0x60, 0x84};

    ENTER();

    addr[0] = nsid;
    len[0]  = sizeof(nsid);
    addr[1] = mac_addr;
    len[1]  = 6;
    ret     = nxp_sha1_vector(2, addr, len, hash, sizeof(hash));
    if (ret == WPS_STATUS_SUCCESS)
    {
        (void)memcpy(uuid, hash, 16);

        /* Version: 5 = named-based version using SHA-1 */
        uuid[6] = (5 << 4) | (uuid[6] & 0x0f);

        /* Variant specified in RFC 4122 */
        uuid[8] = 0x80 | (uuid[8] & 0x3f);
    }

    LEAVE();
}

/**
 *  @brief Process WPS parameter initialization
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param wps_s        A pointer to global WPS structure
 *  @return             WPS_STATUS_SUCCESS--success, WPS_STATUS_FAIL--fail
 */
static int wps_parameter_initialization(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int ret          = WPS_STATUS_SUCCESS;
    u8 zero_uuid[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ENTER();

    /* Initial variable used in state machine */
    pwps_info->registration_fail        = WPS_CANCEL;
    pwps_info->registration_in_progress = WPS_CANCEL;

    wps_d("Set registration in progress %d", pwps_info->registration_in_progress);

    pwps_info->id                           = 1;
    pwps_info->eap_msg_sent                 = 0;
    pwps_info->last_recv_wps_msg            = -1;
    pwps_info->last_recv_tls_msg_identifier = 0;
    pwps_info->restart_link_lost            = WPS_CANCEL;
    pwps_info->read_ap_config_only          = WPS_CANCEL;
    pwps_info->pin_pbc_set                  = WPS_CANCEL;
    pwps_info->input_state                  = WPS_INPUT_STATE_METHOD;
    pwps_info->enrollee_in_authorized_mac   = WPS_SET;
    pwps_info->wps_session                  = 0;

    /* Reset ssid here, to read from file or driver */
    (void)memset(&wps_s->current_ssid, 0, sizeof(WPS_SSID));

    (void)memset(&pwps_info->enrollee.wps_uuid, 0, WPS_UUID_MAX_LEN);
    (void)memset(&pwps_info->registrar.wps_uuid, 0, WPS_UUID_MAX_LEN);
    pwps_info->registrar.wps_uuid_length = WPS_UUID_MAX_LEN;
    pwps_info->enrollee.wps_uuid_length  = WPS_UUID_MAX_LEN;

    pwps_info->registrar.auth_type_flag  = AUTHENTICATION_TYPE_ALL;
    pwps_info->registrar.encry_type_flag = ENCRYPTION_TYPE_ALL;
    pwps_info->enrollee.auth_type_flag   = AUTHENTICATION_TYPE_ALL;
    pwps_info->enrollee.encry_type_flag  = ENCRYPTION_TYPE_ALL;

    pwps_info->role              = local_wcc->role;
    pwps_info->pin_generator     = local_wcc->pin_generator;
    pwps_info->prov_session      = local_wcc->prov_session;
    pwps_info->enrollee.version  = local_wcc->version;
    pwps_info->enrollee.version2 = local_wcc->version2;
    strcpy((char *)pwps_info->enrollee.device_name, (const char *)local_wcc->device_name);
    pwps_info->enrollee.device_name_length = strlen((const char *)pwps_info->enrollee.device_name);
    strcpy((char *)pwps_info->enrollee.manufacture, (const char *)local_wcc->manufacture);
    pwps_info->enrollee.manufacture_length = strlen((const char *)pwps_info->enrollee.manufacture);
    strcpy((char *)pwps_info->enrollee.model_name, (const char *)local_wcc->model_name);
    pwps_info->enrollee.model_name_length = strlen((const char *)pwps_info->enrollee.model_name);
    strcpy((char *)pwps_info->enrollee.model_number, (const char *)local_wcc->model_number);
    pwps_info->enrollee.model_number_length = strlen((const char *)pwps_info->enrollee.model_number);
    strcpy((char *)pwps_info->enrollee.serial_number, (const char *)local_wcc->serial_number);
    pwps_info->enrollee.serial_number_length = strlen((const char *)pwps_info->enrollee.serial_number);
    pwps_info->enrollee.config_methods       = local_wcc->config_methods;
    pwps_info->primary_dev_category          = local_wcc->primary_dev_category;
    pwps_info->primary_dev_subcategory       = local_wcc->primary_dev_subcategory;
    pwps_info->enrollee.rf_bands             = local_wcc->rf_bands;
    pwps_info->enrollee.os_version           = local_wcc->os_version;
    pwps_info->wps_msg_max_retry             = local_wcc->wps_msg_max_retry;
    pwps_info->wps_msg_timeout               = local_wcc->wps_msg_timeout;
    pwps_info->PINLen                        = local_wcc->pin_len;

    pwps_info->registrar.version  = local_wcc->version;
    pwps_info->registrar.version2 = local_wcc->version2;
    strcpy((char *)pwps_info->registrar.device_name, (const char *)local_wcc->device_name);
    pwps_info->registrar.device_name_length = strlen((const char *)pwps_info->registrar.device_name);
    strcpy((char *)pwps_info->registrar.manufacture, (const char *)local_wcc->manufacture);
    pwps_info->registrar.manufacture_length = strlen((const char *)pwps_info->registrar.manufacture);
    strcpy((char *)pwps_info->registrar.model_name, (const char *)local_wcc->model_name);
    pwps_info->registrar.model_name_length = strlen((const char *)pwps_info->registrar.model_name);
    strcpy((char *)pwps_info->registrar.model_number, (const char *)local_wcc->model_number);
    pwps_info->registrar.model_number_length = strlen((const char *)pwps_info->registrar.model_number);
    strcpy((char *)pwps_info->registrar.serial_number, (const char *)local_wcc->serial_number);
    pwps_info->registrar.serial_number_length = strlen((const char *)pwps_info->registrar.serial_number);
    pwps_info->registrar.config_methods       = local_wcc->config_methods;
    pwps_info->registrar.rf_bands             = local_wcc->rf_bands;
    pwps_info->registrar.os_version           = local_wcc->os_version;

    wps_d("Device state SC_NOT_CONFIGURED_STATE !\r\n");
    if (!(memcmp(pwps_info->enrollee.wps_uuid, zero_uuid, WPS_UUID_MAX_LEN)))
    {
        wps_d("Generating UUID using local MAC address!\r\n");
        wps_generate_uuid_using_mac_addr(wps_s->my_mac_addr, pwps_info->registrar.wps_uuid);
        (void)memcpy(&pwps_info->enrollee.wps_uuid, &pwps_info->registrar.wps_uuid, WPS_UUID_MAX_LEN);
        wps_hexdump("pwps_info->registrar.wps_uuid", pwps_info->registrar.wps_uuid, WPS_UUID_MAX_LEN);
    }

    if (pwps_info->role == WPS_ENROLLEE)
    {
        wps_d("Role : WPS_ENROLLEE\r\n");

        pwps_info->state = WPS_STATE_A;

        wps_set_device_password_id(gpwps_info);

        /* Enrollee MAC Address */
        (void)memcpy(pwps_info->enrollee.mac_address, wps_s->my_mac_addr, ETH_ALEN);

        /* Association State */
        pwps_info->enrollee.association_state = 0x01;

        /* Random Number */
        wps_generate_nonce_16B(pwps_info->enrollee.nonce); /* Nonce */
        wps_generate_nonce_16B(pwps_info->enrollee.e_s1);  /* E-S1 */
        wps_generate_nonce_16B(pwps_info->enrollee.e_s2);  /* E-S1 */
        wps_generate_nonce_16B(pwps_info->enrollee.IV);    /* IV */
    }
    else if (pwps_info->role == WPS_REGISTRAR)
    {
        wps_d("Role : WPS_REGISTRAR\r\n");

        pwps_info->state = WPS_STATE_A;

        wps_set_device_password_id(gpwps_info);

        /* Registrar MAC Address */
        (void)memcpy(pwps_info->registrar.mac_address, wps_s->my_mac_addr, ETH_ALEN);

        /* Association State */
        pwps_info->registrar.association_state = 0x01;

        /* Random Number */
        wps_generate_nonce_16B(pwps_info->registrar.nonce); /* Nonce */
        wps_generate_nonce_16B(pwps_info->registrar.r_s1);  /* R-S1 */
        wps_generate_nonce_16B(pwps_info->registrar.r_s2);  /* R-S2 */
        wps_generate_nonce_16B(pwps_info->registrar.IV);    /* IV */
    }
    else if (pwps_info->role == WFD_ROLE)
    {
    }

    LEAVE();
    return ret;
}

#ifndef CONFIG_FSL_AES
uint32_t wps_wlan_random_entropy(void)
{
    unsigned char mac[6] = {0}, byte;
    short rssi, i;
    unsigned int feed_data;

    /* Start with a high prime number */
    feed_data = 98953;

    wlan_get_mac_address(mac);
    /* The nf and snr values are so varying per-packet (range-bound) that
     * this should give some good randomness.
     */

    rssi = g_data_nf_last - g_data_snr_last;

    feed_data *= (rssi);
    for (i = 0; i < 4; i++)
    {
        byte = (rssi & (0xff << (i * 8))) ^ mac[5 - i];
        feed_data ^= byte << (i * 8);
    }
    return feed_data;
}
#endif /* CONFIG_FSL_AES */
/********************************************************
        Global Functions
********************************************************/
/**
 *  @brief Get WPS_INFO structure
 *
 *  @return             A pointer of global WPS_INFO structure
 */
PWPS_INFO wps_get_private_info(void)
{
    return gpwps_info;
}

u16 wps_get_local_config_methods(void)
{
    if (local_wcc)
        return local_wcc->config_methods;
    return 0;
}

/**
 *  @brief WPS Initialization
 *
 *  @param wps_s        A pointer to global WPS structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
static int wps_session_init(WPS_DATA *wps_s)
{
    int ret = WPS_STATUS_SUCCESS;
    ENTER();

    wps_s->userAbort = WPS_CANCEL;
    ret              = wps_parameter_initialization(gpwps_info, wps_s);

    LEAVE();
    return ret;
}

/**
 *  @brief Process WPS start up operations
 *
 *  @param wps_s        A pointer to global WPS structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
static int wps_session_start(WPS_DATA *wps_s)
{
    int ret = WPS_STATUS_SUCCESS;
    ENTER();

    wps_d("Mak: my role is %d\r\n", gpwps_info->role);
    if (gpwps_info->role == WPS_ENROLLEE)
    {
        if (gpwps_info->prov_session == PROV_WPS_SESSION_ATTEMPT)
        {
            wps_d("calling wps_wlan_ie_config\r\n");
            ret = wps_wlan_ie_config(SET_WPS_STA_SESSION_ACTIVE_IE, &assoc_ie_index);
            if (ret != WPS_STATUS_SUCCESS)
            {
                wps_d("WPS IE configuration failure.\n");
            }
        }
        /* Enrollee Process : PIN mode and PBC user selection */
        ret = wps_enrollee_start(gpwps_info, wps_s);
    }
    else if (gpwps_info->role == WPS_REGISTRAR)
    {
        /* set credentials */
        ret = wps_load_uap_cred(wps_s, gpwps_info);
        /* Registrar Process */
        ret = wps_wlan_ie_config(SET_WPS_AP_SESSION_ACTIVE_IE, &ie_index);
        if (ret != WPS_STATUS_SUCCESS)
        {
            wps_d("WPS IE configuration failure.\n");
        }
        /* Configure session start IEs for Assoc response */
        if (gpwps_info->registrar.version >= WPS_VERSION_2DOT0)
        {
            ap_assocresp_ie_index = ie_index + 2;
            ret                   = wps_wlan_ie_config(SET_WPS_AP_SESSION_ACTIVE_AR_IE, &ap_assocresp_ie_index);
            if (ret != WPS_STATUS_SUCCESS)
            {
                wps_d("WPS IE configuration failure.\n");
            }
        }
        ret = wps_registrar_start(gpwps_info, wps_s);
    }
    else if (gpwps_info->role == WFD_ROLE)
    {
    }

    LEAVE();

    return ret;
}

/**
 *  @brief Process WPS free operations
 *
 *  @return             None
 */
void wps_session_deinit(void)
{
    ENTER();

    if (gpwps_info == NULL || !gpwps_info_initialized)
    {
        LEAVE();
        return;
    }

    nxp_dh_free(gpwps_info->dh);
    wps_mem_free(gpwps_info);

    gpwps_info_initialized = false;

    if (g_bssid)
        wps_mem_free(g_bssid);
    if (g_ssid)
        wps_mem_free(g_ssid);

    g_bssid = NULL;
    g_ssid  = NULL;

    gpwps_info = NULL;

    LEAVE();
}

/**
 *  @brief WPS Enrollee Shutdown function
 *
 *  @param              None
 *  @return             None
 */
void wps_shutdown()
{
    ENTER();

    /* shutdown the main processing loop */
    wps_main_loop_shutdown();

    LEAVE();
}

int wps_connect(enum wps_session_command pbc, uint32_t pin, struct wlan_scan_result *res)
{
    struct prov_command *prov_cmd = NULL;
    struct wps_command *wps_cmd   = NULL;

    prov_cmd = (struct prov_command *)wps_mem_malloc(sizeof(struct prov_command));

    if (prov_cmd == NULL)
    {
        PRINTF("Failed to allocated memory for prov command\r\n");
        return -WM_FAIL;
    }

    (void)memset(prov_cmd, 0, sizeof(struct prov_command));
    prov_cmd->prov_session = local_wcc->prov_session;
    wps_cmd                = &(prov_cmd->cmd.wps_cmd);

    wps_cmd->command = pbc;
    wps_cmd->wps_pin = pin;
    (void)memcpy(&wps_cmd->res, res, sizeof(struct wlan_scan_result));

    if (os_queue_send(&wps.cmd_queue, &prov_cmd, OS_NO_WAIT) != WM_SUCCESS)
    {
        wps_mem_free(prov_cmd);
        return -WM_FAIL;
    }
    return WM_SUCCESS;
}

#ifdef CONFIG_WPA2_ENTP
int wpa2_ent_connect(struct wlan_network *wpa2_network)
{
    struct prov_command *prov_cmd = NULL;

    prov_cmd = (struct prov_command *)wps_mem_malloc(sizeof(struct prov_command));

    if (prov_cmd == NULL)
    {
        PRINTF("Failed to allocated memory for prov_cmd command\r\n");
        return -WM_FAIL;
    }

    (void)memset(prov_cmd, 0, sizeof(struct prov_command));

    prov_cmd->prov_session = local_wcc->prov_session;
    (void)memcpy(&prov_cmd->cmd.entp_cmd.wpa2_network, wpa2_network, sizeof(struct wlan_network));

    if (os_queue_send(&wps.cmd_queue, &prov_cmd, OS_NO_WAIT) != WM_SUCCESS)
    {
        wps_mem_free(prov_cmd);
        return -WM_FAIL;
    }
    return WM_SUCCESS;
}

void wpa2_shutdown()
{
    ENTER();

    wpa2_failure = 1;

    /* shutdown the main processing loop */
    wps_main_loop_shutdown();

    LEAVE();
}
#endif

/* WPS main processing thread
 *
 */
static void wps_main(os_thread_arg_t data)
{
    enum wlan_connection_state state;
    int ret;

    struct prov_command *prov_cmd = NULL;
#ifdef CONFIG_WPA2_ENTP
    struct wpa2_command *wpa2_cmd = NULL;
    WPS_DATA *wps_s               = (WPS_DATA *)&wps_global;
#endif
    struct wps_command *wps_cmd = NULL;


    wps_register_rx_callback(WPSEAPoLRxDataHandler);

    while (1)
    {
#ifdef CONFIG_WPS2
        ret = os_queue_recv(&wps.cmd_queue, &prov_cmd, RX_WAIT);
        if (ret != WM_SUCCESS || prov_cmd == NULL)
            continue;
#else
        ret     = os_queue_recv(&wps.cmd_queue, &prov_cmd, os_msec_to_ticks(1000));
        wps_cmd = &(prov_cmd->cmd.wps_cmd);

        if (ret != WM_SUCCESS || wps_cmd == NULL)
            continue;
#endif

        if (prov_cmd->prov_session == PROV_WPS_SESSION_ATTEMPT)
        {
            wps_cmd   = &(prov_cmd->cmd.wps_cmd);
            g_method  = wps_cmd->command;
            g_channel = wps_cmd->res.channel;

            (void)memcpy(g_ssid, (u8 *)wps_cmd->res.ssid, MAX_SSID_LEN + 1);
            (void)memcpy(g_bssid, (u8 *)wps_cmd->res.bssid, ETH_ALEN);
            if ((wlan_get_connection_state(&state) == WM_SUCCESS) && (wps_global.wps_conn_network.role == BSS_TYPE_STA))
            {
                if (state == WLAN_ASSOCIATED || state == WLAN_CONNECTED)
                {
                    wps_mem_free(prov_cmd);
                    prov_cmd = NULL;
                    wps_cmd  = NULL;
                    continue;
                }
                if (strlen(wps_global.wps_conn_network.name) > 0)
                {
                    wlan_remove_network(wps_global.wps_conn_network.name);
                    (void)memset(&(wps_global.wps_conn_network), 0, sizeof(struct wlan_network));
                }
            }
            switch (g_method)
            {
                case CMD_WPS_PIN:
                    g_gen_pin = wps_cmd->wps_pin;
                    wps_init();
                    break;

                case CMD_WPS_PBC:
                    wps_init();
                    break;
            }
            wps_mem_free(prov_cmd);
            prov_cmd = NULL;
            wps_cmd  = NULL;
        }
#ifdef CONFIG_WPA2_ENTP
        else if (prov_cmd->prov_session == PROV_ENTP_SESSION_ATTEMPT)
        {
            wpa2_cmd = &(prov_cmd->cmd.entp_cmd);
            (void)memcpy(&wps_s->wpa2_network, &wpa2_cmd->wpa2_network, sizeof(struct wlan_network));
            wps_mem_free(prov_cmd);
            prov_cmd = NULL;
            wpa2_cmd = NULL;

            g_method = CMD_WPS_PBC;

            ret = wps_private_info_allocate(&gpwps_info);

            ret = wps_init();
            continue;
        }
#endif
        else
        {
            wps_d("Receives PROV cmd but failed session:%d\r\n", prov_cmd->prov_session);
            wps_mem_free(prov_cmd);
            prov_cmd = NULL;
            wps_cmd  = NULL;
            continue;
        }
    }

}

/* Internal cleanup function. */
static int wps_cleanup(void)
{
    int ret;


    ret = os_queue_delete(&wps.cmd_queue);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete queue.\r\n");
        return -WM_FAIL;
    }

    ret = os_queue_delete(&wps.data_queue);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete queue.\r\n");
        return -WM_FAIL;
    }
    ret = os_thread_delete(&wps_main_thread);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete thread.\r\n");
        return -WM_FAIL;
    }

    return WM_SUCCESS;
}

/**
 *  @brief C main entry function
 *  @param argc     number of arguments
 *  @param argv     A pointer to arguments array
 *  @return         WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_start(struct wps_config *wps_conf)
{
    int ret;
    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;
#ifdef CONFIG_WPA2_ENTP
    WPA_SM *wpa_sm_s = (WPA_SM *)&wpa_sm;
#endif

    if (wps.initialized == true)
        return -WM_FAIL;

    local_wcc = wps_conf;

    (void)memset((void *)&wps, 0, sizeof(wps));
    (void)memset((void *)&(wps_s->wps_conn_network), 0, sizeof(struct wlan_network));
    wps.cmd_queue_data  = wps_cmd_queue_data;
    wps.data_queue_data = wps_data_queue_data;
    wps.cb              = local_wcc->wps_callback;


    ret = os_queue_create(&wps.cmd_queue, "wps_cmd_queue", sizeof(struct prov_command **), &wps.cmd_queue_data);
    if (ret != WM_SUCCESS)
    {
        wps_d("Error: Failed to create wps cmd queue: %d\r\n", ret);
        goto fail;
    }

    ret = os_queue_create(&wps.data_queue, "wps_message_queue", sizeof(struct wps_msg), &wps.data_queue_data);
    if (ret != WM_SUCCESS)
    {
        wps_d("Error: Failed to create wps message queue: %d\r\n", ret);
        goto fail;
    }

#ifdef CONFIG_FSL_AES
    AES_Init(APP_AES);
#else
    random_register_handler(wps_wlan_random_entropy);
#endif

    wps.initialized = true;

    (void)memset(wps_s->ifname, 0, IFNAMESIZE + 1);

        if (local_wcc->role == WPS_REGISTRAR)
        strncpy(wps_s->ifname, "uap0", IFNAMESIZE);
    else
        strncpy(wps_s->ifname, "mlan0", IFNAMESIZE);

    gpwps_info_initialized = false;

    ret = wps_private_info_allocate(&gpwps_info);

    wps_d("Initializing interface '%s'", wps_s->ifname);

        if (local_wcc->role == WPS_REGISTRAR)
        wps_s->bss_type = BSS_TYPE_UAP;
    else
        wps_s->bss_type = BSS_TYPE_STA;


    /*
     * 1. Initialize L2 packet interface for receiving EAP packet.
     * 2. Get L2 MAC address and store to application global structure
     */
    if (wps_loop_init(wps_s) != 0)
    {
        wps_d("ERROR - Fail to initialize layer 2 socket !\n");
        wps_stop();
        goto fail;
    }
#ifdef CONFIG_WPA2_ENTP
    (void)memset(wpa_sm_s, 0, sizeof(WPA_SM));

    wpa_sm_s->pairwise_cipher = WPA_CIPHER_CCMP;
    wpa_sm_s->group_cipher    = WPA_CIPHER_CCMP;
    wpa_sm_s->proto           = WPA_PROTO_RSN;
    wpa_sm_s->key_mgmt        = WPA_KEY_MGMT_IEEE8021X;
    wpa_sm_s->renew_snonce    = 1;
    (void)memcpy(wpa_sm_s->own_addr, wps_s->l2->my_mac_addr, ETH_ALEN);
#endif

    ret = os_thread_create(&wps_main_thread, "prov", wps_main, 0, &wps_stack, OS_PRIO_2);
    if (ret != WM_SUCCESS)
    {
        wps_d("Error: Failed to create wps thread: %d\r\n", ret);
        goto fail;
    }

    return WM_SUCCESS;

fail:
    if (wps_main_thread)
        os_thread_delete(&wps_main_thread);
    if (wps.cmd_queue)
        os_queue_delete(&wps.cmd_queue);
    if (wps.data_queue)
        os_queue_delete(&wps.data_queue);

    return -WM_FAIL;
}

int wps_init()
{
    if (wps.initialized == false)
        return -WM_FAIL;

    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    if (wps.cb(WPS_STARTED, NULL, 0) == -WM_FAIL)
    {
        wps_d("WPS Callback failed for event: %d\r\n", WPS_STARTED);
    }

    if (((local_wcc->role == WPS_REGISTRAR) && (wps_s->bss_type != BSS_TYPE_UAP)) ||
        ((local_wcc->role == WPS_ENROLLEE) && (wps_s->bss_type != BSS_TYPE_STA)))
    {
        wps_d("Role does not match UAP/STA, change bss_type!\n");
        (void)memset(wps_s->ifname, 0, IFNAMESIZE + 1);
            if (local_wcc->role == WPS_REGISTRAR)
        {
            strncpy(wps_s->ifname, "uap0", IFNAMESIZE);
        }
        else
        {
            strncpy(wps_s->ifname, "mlan0", IFNAMESIZE);
        }

            if (local_wcc->role == WPS_REGISTRAR)
        {
            wps_s->bss_type = BSS_TYPE_UAP;
        }
        else
        {
            wps_s->bss_type = BSS_TYPE_STA;
        }

        wps_loop_deinit(wps_s);
        /*
         * 1. Initialize L2 packet interface for receiving EAP packet.
         * 2. Get L2 MAC address and store to application global structure
         */
        if (wps_loop_init(wps_s) != 0)
        {
            wps_d("ERROR - Fail to initialize layer 2 socket !\n");
            wps_stop();
            return WM_FAIL;
        }
    }

    /*
     * 1. Allocate memory for WPS state machine
     * 2. Initialize parameter needed in state machine
     */
    if (wps_session_init(wps_s) != WPS_STATUS_SUCCESS)
    {
        wps_d("EXIT - WPS is not initialized!\n");
        wps_stop();
    }


        /*
         * Scan and associate to AP
         */
        if (wps_session_start(wps_s) == WPS_STATUS_SUCCESS)
        {
            gpwps_info->wps_session = 1;

            /* Enable main loop procedure */
            wps_main_loop_enable();

            /* Main loop for socket read and timeout function */
            wps_main_loop_proc();
        }

    return WM_SUCCESS;
}

/* Stop the thread and cleanup */
int wps_stop()
{
    int ret;

    WPS_DATA *wps_s = (WPS_DATA *)&wps_global;

    if (wps.initialized == false)
        return -WM_FAIL;

    wps.initialized = false;

    wps_deregister_rx_callback();

    wps_session_deinit();

    wps_loop_deinit(wps_s);
    wps_intf_deinit(wps_s);

    ret = wps_cleanup();

    if (wps.cb(WPS_FINISHED, NULL, 0) == -WM_FAIL)
        wps_d("WPS Callback failed for event: %d\r\n", WPS_FINISHED);

#ifndef CONFIG_FSL_AES
    random_unregister_handler(wps_wlan_random_entropy);
#endif
    return ret;
}
