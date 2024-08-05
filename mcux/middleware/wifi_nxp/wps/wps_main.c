/** @./middleware/wifi/wps/wps_main.cfile wps_main.c
 *
 *  @brief This file contains WPS application program entry function
 *  and functions for initialization setting.
 *
 *  Copyright 2008-2024 NXP
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
#include <osa.h>
#include "wmcrypto.h"

#include "wps_msg.h"
#if CONFIG_P2P
#include <wifi.h>
#endif

#if CONFIG_FSL_AES
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

#define RX_WAIT osaWaitForever_c
#define APP_AES AES

/********************************************************
        Global Variables
********************************************************/
/** Global pwps information */
PWPS_INFO gpwps_info;
/** wps global */
WPS_DATA wps_global PM3_BSS;

bool gpwps_info_initialized;

#if CONFIG_WPA2_ENTP
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

#if CONFIG_P2P
OSA_MUTEX_HANDLE_DEFINE(p2p_session);

struct wlan_network p2p_uap_network;
struct wlan_network p2p_network;

static OSA_QueuePoolDefine(wps_peer_event_queue_data, sizeof(struct wfd_wlan_event) * MAX_MSGS);
static OSA_QueuePoolDefine(wps_event_queue_data, sizeof(struct wfd_wlan_event) * MAX_MSGS);
#endif

static OSA_QueuePoolDefine(wps_cmd_queue_data, sizeof(struct prov_command **) * MAX_COMMANDS);

static OSA_QueuePoolDefine(wps_data_queue_data, sizeof(struct wps_msg) * MAX_MSGS);

struct wps_thread_t wps;
struct wps_config *local_wcc = NULL;

extern int wpa2_failure;

static void wps_main(osa_task_param_t arg);
OSA_TASK_HANDLE_DEFINE(wps_main_Handle);

#if CONFIG_P2P
static void wps_peer_event_receive(osa_task_param_t arg);
OSA_TASK_HANDLE_DEFINE(p2p_scan_Handle);
static OSA_TASK_DEFINE(p2p_scan, PRIORITY_RTOS_TO_OSA(3), 1, 4096, 0);

static OSA_TASK_DEFINE(wps_main, PRIORITY_RTOS_TO_OSA(3), 1, 10240, 0);
#else
static OSA_TASK_DEFINE(wps_main, PRIORITY_RTOS_TO_OSA(2), 1, 10240, 0);
#endif

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

#if !CONFIG_P2P
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
#endif
    LEAVE();

    gpwps_info_initialized = true;

    return WPS_STATUS_SUCCESS;
}

#if CONFIG_P2P
void wps_set_wfd_cfg()
{
    char wps_para[] = "pbc";
    wfd_cfg_cmd_wps_params(ACTION_SET, wps_para);
    wfd_cfg_cmd_provisioning_params(ACTION_SET, CONFIG_METHOD_PUSHBUTTON, DEVICE_PASSWORD_PUSH_BUTTON);
}
#endif

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
#if CONFIG_P2P
        if (pwps_info->role == WFD_ROLE)
            wps_set_wfd_cfg();
#endif
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
#if CONFIG_P2P
        if (pwps_info->role == WFD_ROLE)
        {
            char wps_para[] = "pin";
            wfd_cfg_cmd_wps_params(ACTION_SET, wps_para);
            wfd_cfg_cmd_provisioning_params(ACTION_SET, CONFIG_METHOD_KEYPAD, DEVICE_PASSWORD_REG_SPECIFIED);
        }
#endif
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

    seed = OSA_TicksGet();

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
#if CONFIG_P2P
    pwps_info->p2p_session = 0;
#endif

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
#if CONFIG_P2P
    strncpy((char *)local_wcc->device_name, (const char *)WFD_devicename, strlen(WFD_devicename) + 1);
#endif
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
#if CONFIG_P2P
        wps_d("Role : WiFi Direct\r\n");

        if (auto_go)
            pwps_info->discovery_role = WPS_REGISTRAR;

        pwps_info->state = WPS_STATE_A;

        wps_set_device_password_id(gpwps_info);
        /* Update beacon IE, probe response IE
        for this device password */
        /*if (auto_go)
            wps_wlan_update_password_ie_config();*/

        (void)memcpy(pwps_info->enrollee.mac_address, wps_s->my_mac_addr, ETH_ALEN);
        (void)memcpy(pwps_info->registrar.mac_address, wps_s->my_mac_addr, ETH_ALEN);

        /* Association State */
        pwps_info->enrollee.association_state  = 0x01;
        pwps_info->registrar.association_state = 0x01;

        /* Random Number */
        wps_generate_nonce_16B(pwps_info->enrollee.nonce);  /* Nonce */
        wps_generate_nonce_16B(pwps_info->enrollee.e_s1);   /* E-S1 */
        wps_generate_nonce_16B(pwps_info->enrollee.e_s2);   /* E-S1 */
        wps_generate_nonce_16B(pwps_info->enrollee.IV);     /* IV */
        wps_generate_nonce_16B(pwps_info->registrar.nonce); /* Nonce */
        wps_generate_nonce_16B(pwps_info->registrar.r_s1);  /* R-S1 */
        wps_generate_nonce_16B(pwps_info->registrar.r_s2);  /* R-S2 */
        wps_generate_nonce_16B(pwps_info->registrar.IV);    /* IV */
#endif
    }

    LEAVE();
    return ret;
}

#if !CONFIG_FSL_AES
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
#if CONFIG_P2P
        if (auto_go)
        {
            if (wps.cb(P2P_SESSION_STARTED, NULL, 0) == -WM_FAIL)
                P2P_LOG("WFD Callback failed for event: %d", P2P_SESSION_STARTED);

            ie_index = 0x0002;
            ret      = wps_wlan_ie_config(SET_WPS_AP_SESSION_ACTIVE_IE, &ie_index);
            if (ret != WPS_STATUS_SUCCESS)
            {
                wps_d("WPS IE configuration failure.\n");
            }
            ret = wps_registrar_start(gpwps_info, wps_s);
        }
#endif
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

#if !CONFIG_P2P
    if (g_bssid)
        wps_mem_free(g_bssid);
    if (g_ssid)
        wps_mem_free(g_ssid);

    g_bssid = NULL;
    g_ssid  = NULL;
#endif

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

    if (OSA_MsgQPut(wps.cmd_queue, &prov_cmd) != KOSA_StatusSuccess)
    {
        wps_mem_free(prov_cmd);
        return -WM_FAIL;
    }
    return WM_SUCCESS;
}

#if CONFIG_WPA2_ENTP
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

    if (OSA_MsgQPut(wps.cmd_queue, &prov_cmd) != KOSA_StatusSuccess)
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
static void wps_main(osa_task_param_t data)
{
#if CONFIG_P2P
    struct timeval tv, now;
    WPS_DATA *wps_s     = (WPS_DATA *)&wps_global;
    WFD_DATA *pwfd_data = &wps_global.wfd_data;
    bss_config_t bss_config;
#endif
    enum wlan_connection_state state;
    int ret;

    struct prov_command *prov_cmd = NULL;
#if CONFIG_WPA2_ENTP
    struct wpa2_command *wpa2_cmd = NULL;
    WPS_DATA *wps_s               = (WPS_DATA *)&wps_global;
#endif
    struct wps_command *wps_cmd = NULL;

#if CONFIG_P2P
    (void)memset(&bss_config, 0, sizeof(bss_config_t));

    /*
     * Download Wfd configuration if supplied with -p command line.
     */
    if (local_wcc->role == WFD_ROLE)
    {
        if (wfd_wlan_update_bss_mode(BSS_MODE_WIFIDIRECT_GO) != WPS_STATUS_SUCCESS)
        {
            wps_d(
                "ERROR - Fail to initialize "
                "BSS Mode!\n");
            goto fail;
        }
        /* Set WFD uAP configuration */
        wifidirectapcmd_sys_config();

        if (wfd_wlan_update_bss_mode(BSS_MODE_WIFIDIRECT_CLIENT) != WPS_STATUS_SUCCESS)
        {
            wps_d(
                "ERROR - Fail to initialize "
                "BSS Mode!\n");
            goto fail;
        }
        /* Set WFD configuration */
        wifidirectcmd_config();

        if (wfd_set_mode(WFD_MODE_START) != WPS_STATUS_SUCCESS)
        {
            wps_d(
                "ERROR - Fail to "
                "initialize WFD!\n");
            goto fail;
        }

        if (auto_go)
        {
            if (wfd_wlan_update_bss_mode(BSS_MODE_WIFIDIRECT_GO) != WPS_STATUS_SUCCESS)
            {
                wps_d(
                    "ERROR - Fail to "
                    "initialize BSS Mode!\n");
                goto fail;
            }
            if (wfd_set_mode(WFD_MODE_START_GROUP_OWNER) != WPS_STATUS_SUCCESS)
            {
                wps_d(
                    "ERROR - Fail to "
                    "initialize WFD!\n");
                goto fail;
            }

            if (!wps_s->current_ssid.ssid_len)
            {
                apcmd_get_bss_config(&bss_config);

                load_cred_info(wps_s, gpwps_info, &bss_config);
                /*
                 * For Wi-Fi Direct, we need to
                 * convert the passphrase to PSK.
                 *
                 * Hence update the default
                 * passphrase
                 */

                wlan_generate_psk(gpwps_info);
            }
            if (wps.cb(P2P_AUTO_GO_STARTED, &WFD_devicename, strlen(WFD_devicename)) == -WM_FAIL)
                P2P_LOG(
                    "WFD Callback failed for "
                    "event: %d\r\n",
                    P2P_AUTO_GO_STARTED);
            if (wlan_add_network(&p2p_uap_network) != WM_SUCCESS)
            {
                wps_d(
                    "failed to add "
                    "wfd network\r\n");
                goto fail;
            }
            if (wlan_start_network(p2p_uap_network.name) != WM_SUCCESS)
            {
                wps_d(
                    "failed to start "
                    "wfd network\r\n");
                goto fail;
            }
            wlan_rx_mgmt_indication(BSS_TYPE_WFD, 0x2000, NULL);
        }
        else
        {
            mlanconfig_bgscan(1);

            if (wfd_set_mode(WFD_MODE_START_FIND_PHASE) != WPS_STATUS_SUCCESS)
            {
                wps_d(
                    "ERROR - Fail to "
                    "initialize WFD!\n");
                goto fail;
            }

            wps_set_wfd_cfg();

            if (wps.cb(P2P_DEVICE_STARTED, &WFD_devicename, strlen(WFD_devicename)) == -WM_FAIL)
                P2P_LOG(
                    "WFD Callback failed for "
                    "event: %d\r\n",
                    P2P_DEVICE_STARTED);

            wfd_start_peer_ageout_timer(pwfd_data);
            p2p_scan_on = 1;
        }
    }
#endif

    wps_register_rx_callback(WPSEAPoLRxDataHandler);

    while (1)
    {
#if CONFIG_WPS2
        ret = OSA_MsgQGet(&wps.cmd_queue, &prov_cmd, RX_WAIT);
        if (ret != WM_SUCCESS || prov_cmd == NULL)
            continue;
#else
#if CONFIG_P2P
        if (!auto_go && p2p_scan_on)
        {
            if (wps_loop.timeout)
            {
                now.tv_sec  = OSA_TicksToMsec(OSA_TicksGet()) / 1000;
                now.tv_usec = (OSA_TicksToMsec(OSA_TicksGet()) % 1000) * 1000;

                if (timer_cmp(&now, &wps_loop.timeout->time))
                    timersub(&wps_loop.timeout->time, &now, &tv);
                else
                    tv.tv_sec = tv.tv_usec = 0;
            }

            /* check if some registered timeouts have occurred */
            if (wps_loop.timeout)
            {
                struct wps_timeout_s *tmp;

                now.tv_sec  = OSA_TicksToMsec(OSA_TicksGet()) / 1000;
                now.tv_usec = (OSA_TicksToMsec(OSA_TicksGet()) % 1000) * 1000;

                if (!timer_cmp(&now, &wps_loop.timeout->time))
                {
                    tmp              = wps_loop.timeout;
                    wps_loop.timeout = wps_loop.timeout->next;
                    tmp->handler(tmp->callback_data);
                    wps_mem_free(tmp);
                }
            }
        }

        if (go_request || pd_request)
        {
            p2p_scan_on = 0;
            g_method    = CMD_WPS_PBC;
            wps_init();
            go_request = 0;
            pd_request = 0;
        }
#endif
        ret     = OSA_MsgQGet((osa_msgq_handle_t)wps.cmd_queue, &prov_cmd, 1000);
        wps_cmd = &(prov_cmd->cmd.wps_cmd);

        if (ret != WM_SUCCESS || wps_cmd == NULL)
            continue;
#endif

        if (prov_cmd->prov_session == PROV_WPS_SESSION_ATTEMPT)
        {
            wps_cmd   = &(prov_cmd->cmd.wps_cmd);
            g_method  = wps_cmd->command;
            g_channel = wps_cmd->res.channel;

#if CONFIG_P2P
            g_bssid = (u8 *)wps_cmd->res.bssid;
            g_ssid  = (u8 *)wps_cmd->res.ssid;
#else
            (void)memcpy(g_ssid, (u8 *)wps_cmd->res.ssid, MAX_SSID_LEN + 1);
            (void)memcpy(g_bssid, (u8 *)wps_cmd->res.bssid, ETH_ALEN);
#endif
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
#if CONFIG_WPA2_ENTP
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

#if CONFIG_P2P
fail:
    if (wps.cb(P2P_FAILED, NULL, 0) == -WM_FAIL)
        P2P_LOG("WPS Callback failed for event: %d\r\n", P2P_FAILED);

    wps_stop();
#endif
}

/* Internal cleanup function. */
static int wps_cleanup(void)
{
    int ret;

#if CONFIG_P2P
    ret = OSA_MutexDestroy((osa_mutex_handle_t)wps.p2p_session);
    if (ret != KOSA_StatusSuccess)
    {
        wps_d("Warning: failed to delete mutex.\r\n");
        return -WM_FAIL;
    }
    ret = OSA_MsgQDestroy((osa_msgq_handle_t)wps.peer_event_queue);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete queue.\r\n");
        return -WM_FAIL;
    }
    ret = OSA_MsgQDestroy((osa_msgq_handle_t)wps.event_queue);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete queue.\r\n");
        return -WM_FAIL;
    }
    if (!auto_go)
    {
        ret = OSA_TaskDestroy((osa_task_handle_t)p2p_scan_thread);
        if (ret != WM_SUCCESS)
        {
            wps_d("Warning: failed to delete thread.\r\n");
            return -WM_FAIL;
        }
    }
#endif

    ret = OSA_MsgQDestroy((osa_msgq_handle_t)wps.cmd_queue);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete queue.\r\n");
        return -WM_FAIL;
    }

    ret = OSA_MsgQDestroy((osa_msgq_handle_t)wps.data_queue);
    if (ret != WM_SUCCESS)
    {
        wps_d("Warning: failed to delete queue.\r\n");
        return -WM_FAIL;
    }
    ret = OSA_TaskDestroy((osa_task_handle_t)wps_main_Handle);
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
#if CONFIG_WPA2_ENTP
    WPA_SM *wpa_sm_s = (WPA_SM *)&wpa_sm;
#endif

    if (wps.initialized == true)
        return -WM_FAIL;

    local_wcc = wps_conf;

    (void)memset((void *)&wps, 0, sizeof(wps));
    (void)memset((void *)&(wps_s->wps_conn_network), 0, sizeof(struct wlan_network));
#if CONFIG_P2P
    wps.peer_event_queue_data = wps_peer_event_queue_data;
    wps.event_queue_data      = wps_event_queue_data;
#endif
    wps.cb = local_wcc->wps_callback;

#if CONFIG_P2P
    /* WFD data initiliazation */
    (void)memset(&wps_s->wfd_data, 0, sizeof(WFD_DATA));
    wps_s->wfd_data.dev_index = -1;
    wps_s->wfd_data.dev_found = -1;

    ret = OSA_MutexCreate(&wps.p2p_session, "p2p_session", OS_MUTEX_INHERIT);
    if (status != KOSA_StatusSuccess)
        goto fail;

    ret = OSA_MsgQCreate((osa_msgq_handle_t)wps.event_queue, MAX_MSGS, sizeof(struct wfd_wlan_event));
    if (ret != KOSA_StatusSuccess)
    {
        wps_d("Error: Failed to create wps event queue: %d\r\n", ret);
        goto fail;
    }

    ret = OSA_MsgQCreate((osa_msgq_handle_t)wps.peer_event_queue, MAX_MSGS, sizeof(struct wfd_wlan_event));
    if (ret != KOSA_StatusSuccess)
    {
        wps_d(
            "Error: Failed to create wps peer "
            "event queue: %d\r\n",
            ret);
        goto fail;
    }
    ret = wifi_register_wfd_event_queue(&wps.peer_event_queue);
    if (ret)
    {
        wps_d(
            "Error: unable to register peer "
            "event queue %d\r\n",
            ret);
        OSA_MsgQDestroy((osa_msgq_handle_t)wps.peer_event_queue);
        goto fail;
    }
#endif

    ret = OSA_MsgQCreate((osa_msgq_handle_t)wps.cmd_queue, MAX_COMMANDS, sizeof(struct prov_command **));
    if (ret != KOSA_StatusSuccess)
    {
        wps_d("Error: Failed to create wps cmd queue: %d\r\n", ret);
        goto fail;
    }

    ret = OSA_MsgQCreate((osa_msgq_handle_t)wps.data_queue, MAX_MSGS, sizeof(struct wps_msg));
    if (ret != KOSA_StatusSuccess)
    {
        wps_d("Error: Failed to create wps message queue: %d\r\n", ret);
        goto fail;
    }

#if CONFIG_FSL_AES
    AES_Init(APP_AES);
#else
    random_register_handler(wps_wlan_random_entropy);
#endif

    wps.initialized = true;

    (void)memset(wps_s->ifname, 0, IFNAMESIZE + 1);

#if CONFIG_P2P
    if (local_wcc->role == WFD_ROLE)
        strncpy(wps_s->ifname, "wfd0", IFNAMESIZE);
    else
#endif
        if (local_wcc->role == WPS_REGISTRAR)
        strncpy(wps_s->ifname, "uap0", IFNAMESIZE);
    else
        strncpy(wps_s->ifname, "mlan0", IFNAMESIZE);

    gpwps_info_initialized = false;

    ret = wps_private_info_allocate(&gpwps_info);

    wps_d("Initializing interface '%s'", wps_s->ifname);

#if CONFIG_P2P
    if (local_wcc->role == WFD_ROLE)
    {
        if (auto_go)
            wps_s->bss_type = BSS_TYPE_UAP;
        else
            wps_s->bss_type = BSS_TYPE_STA;
    }
    else
#endif
        if (local_wcc->role == WPS_REGISTRAR)
        wps_s->bss_type = BSS_TYPE_UAP;
    else
        wps_s->bss_type = BSS_TYPE_STA;

#if CONFIG_P2P
    gpwps_info->discovery_role = WPS_ENROLLEE;
#endif

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
#if CONFIG_WPA2_ENTP
    (void)memset(wpa_sm_s, 0, sizeof(WPA_SM));

    wpa_sm_s->pairwise_cipher = WPA_CIPHER_CCMP;
    wpa_sm_s->group_cipher    = WPA_CIPHER_CCMP;
    wpa_sm_s->proto           = WPA_PROTO_RSN;
    wpa_sm_s->key_mgmt        = WPA_KEY_MGMT_IEEE8021X;
    wpa_sm_s->renew_snonce    = 1;
    (void)memcpy(wpa_sm_s->own_addr, wps_s->l2->my_mac_addr, ETH_ALEN);
#endif

    ret = OSA_TaskCreate((osa_task_handle_t)wps_main_Handle, OSA_TASK(wps_main), NULL);
    if (ret != WM_SUCCESS)
    {
        wps_d("Error: Failed to create p2p thread: %d\r\n", ret);
        goto fail;
    }

#if CONFIG_P2P
    ret = OSA_TaskCreate((osa_task_handle_t)p2p_scan_Handle, OSA_TASK(wps_peer_event_receive), NULL);
    if (ret != WM_SUCCESS)
    {
        wps_d(
            "Error: Failed to create p2p_scan"
            " thread: %d\r\n",
            ret);
        goto fail;
    }
#endif

    return WM_SUCCESS;

fail:
    (void)OSA_TaskDestroy((osa_task_handle_t)wps_main_Handle);
    if (wps.cmd_queue)
        (void)OSA_MsgQDestroy((osa_msgq_handle_t)wps.cmd_queue);
    if (wps.data_queue)
        (void)OSA_MsgQDestroy((osa_msgq_handle_t)wps.data_queue);
#if CONFIG_P2P
    if (wps.p2p_session)
        OSA_MutexDestroy((osa_mutex_handle_t)wps.p2p_session);
    if (wps.peer_event_queue)
        (void)OSA_MsgQDestroy((osa_msgq_handle_t)wps.peer_event_queue);
    if (wps.event_queue)
        (void)OSA_MsgQDestroy((osa_msgq_handle_t)wps.event_queue);
#endif

    return -WM_FAIL;
}

int wps_init()
{
    if (wps.initialized == false)
        return -WM_FAIL;

#if CONFIG_P2P
    int ret             = -WM_FAIL;
    WFD_DATA *pwfd_data = &wps_global.wfd_data;
#endif
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
#if CONFIG_P2P
        if (local_wcc->role == WFD_ROLE)
        {
            strncpy(wps_s->ifname, "wfd0", IFNAMESIZE);
        }
        else
#endif
            if (local_wcc->role == WPS_REGISTRAR)
        {
            strncpy(wps_s->ifname, "uap0", IFNAMESIZE);
        }
        else
        {
            strncpy(wps_s->ifname, "mlan0", IFNAMESIZE);
        }

#if CONFIG_P2P
        if (local_wcc->role == WFD_ROLE)
        {
            if (auto_go)
            {
                wps_s->bss_type = BSS_TYPE_UAP;
            }
            else
            {
                wps_s->bss_type = BSS_TYPE_STA;
            }
        }
        else
#endif
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

#if CONFIG_P2P
    p2p_scan_on = 0;
    wps_cancel_timer(wfd_peer_ageout_time_handler, pwfd_data);

    if (gpwps_info->role == WFD_ROLE)
    {
        if (!auto_go)
        {
            if (!go_request && !pd_request)
            {
                ret = wfd_peer_device_selected();

                if (ret == WPS_STATUS_FAIL)
                    return ret;
            }

            wfd_start_peer_selected_ageout_timer(pwfd_data);

            wps_event_receive(wps_s, pwfd_data);
        }
    }
#endif
#if CONFIG_P2P
    if (gpwps_info->wps_session || auto_go)
    {
#endif

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
#if CONFIG_P2P
    }
#endif

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

#if CONFIG_P2P
    ret = wifi_unregister_wfd_event_queue(&wps.peer_event_queue);
    if (ret)
        wps_d(
            "Warning: failed to unregister wifi "
            "event queue: %d\r\n",
            ret);
#endif
    ret = wps_cleanup();

    if (wps.cb(WPS_FINISHED, NULL, 0) == -WM_FAIL)
        wps_d("WPS Callback failed for event: %d\r\n", WPS_FINISHED);

#if CONFIG_P2P
    if (wps.cb(P2P_FINISHED, NULL, 0) == -WM_FAIL)
        P2P_LOG(
            "WFD Callback failed for "
            "event: %d\r\n",
            P2P_FINISHED);
#endif
#if !CONFIG_FSL_AES
    random_unregister_handler(wps_wlan_random_entropy);
#endif
    return ret;
}
