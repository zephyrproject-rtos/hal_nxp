/** @file wps_main.c
 *
 *  @brief This file contains WPS application program entry function
 *  and functions for initialization setting.
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "wifi_nxp_wps.h"
#include <lwip/sys.h>
#include <string.h>
#include <ctype.h>
#if defined(__arm__) && !defined(__ARMCC_VERSION)
#include <sys/types.h>
#endif
#include <lwip/sys.h>
#include <lwip/inet.h>
#include <wm_os.h>
#include <wlan.h>

#include "wps_mem.h"
#include "wps_msg.h"
#include "wps_eapol.h"
#include "wps_def.h"
#include "wps_wlan.h"
#include "wps_os.h"

/********************************************************
        Local Variables
********************************************************/

/********************************************************
        Global Variables
********************************************************/
extern u8 *g_ssid;
extern u8 *g_bssid;
extern u8 g_channel;
extern u32 g_gen_pin;

extern void wfd_reset();

extern struct wps_thread_t wps;
struct wlan_network wps_network PM3_BSS;
struct wlan_network sta_network PM3_BSS;
/** Global pwps information */
extern PWPS_INFO gpwps_info;

/********************************************************
        Local Functions
********************************************************/
/**
 *  @brief Check whether the mac address is all zero
 *  @param dev_addr    the mac address to be checked
 *  @return SUCCESS--all zero, FAILURE--not all zero
 */
static int is_mac_all_zero(u8 *dev_addr)
{
    int i;
    for (i = 0; i < ETH_ALEN; ++i)
    {
        if (dev_addr[i] != 0)
            return 0;
    }
    return 1;
}

/**
 *  @brief WPS PIN value Generate
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @return             None
 */
void wps_generate_PIN(PWPS_INFO pwps_info)
{
    int i;
    char pin_str[10];

    ENTER();

    if ((pwps_info->enrollee.device_password_id == DEVICE_PASSWORD_ID_PIN) ||
        (pwps_info->registrar.device_password_id == DEVICE_PASSWORD_ID_PIN))
    {
        /* Generate PIN */
        u32 pin;
        pin = g_gen_pin;
        sprintf(pin_str, "%lu", pin);
        pwps_info->PINLen = strlen(pin_str);
        {
            u32 j, temppin = pin;
            u8 quotient;

            j = ((pwps_info->PINLen == 8) ? 10000000 : 1000);
            for (i = 0; i < pwps_info->PINLen; i++)
            {
                quotient          = temppin / j;
                pwps_info->PIN[i] = quotient;
                /* Convert to numeric digit */
                pwps_info->PIN[i] += 0x30;
                temppin -= j * quotient;
                j = j / 10;
            }
        }
        wps_hexdump("WPS PIN", (u8 *)pwps_info->PIN, pwps_info->PINLen);

        wps_d("WPS PIN is : ");
        for (i = 0; i < pwps_info->PINLen; i++)
            PRINTF("%c", pwps_info->PIN[i]);
        PRINTF("\r\n");
    }

    LEAVE();
}

/**
 * @brief  Validate checksum of PIN
 *
 * @param PIN WPS PIN value
 *
 * @returns WM_SUCCESS if successful, -WM_FAIL otherwise
 **/
int wps_validate_pin(uint32_t PIN)
{
    u32 accum = 0;
    char pin_str[10];

    ENTER();

    sprintf(pin_str, "%lu", PIN);

    if (strlen(pin_str) == 4)
        return WM_SUCCESS;

    if (strlen(pin_str) != 8)
        return -WM_FAIL;

    accum += 3 * ((PIN / 10000000) % 10);
    accum += 1 * ((PIN / 1000000) % 10);
    accum += 3 * ((PIN / 100000) % 10);
    accum += 1 * ((PIN / 10000) % 10);
    accum += 3 * ((PIN / 1000) % 10);
    accum += 1 * ((PIN / 100) % 10);
    accum += 3 * ((PIN / 10) % 10);
    accum += 1 * ((PIN / 1) % 10);

    LEAVE();

    if (0 == (accum % 10))
        return WM_SUCCESS;
    else
        return -WM_FAIL;
}

static int prov_wps_enrollee_start(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int ret           = WPS_STATUS_SUCCESS;
    int retry_cnt     = 5;
    int connect_retry = 10;
    enum wlan_connection_state state;

    ENTER();

    pwps_info->enrollee.auth_type_flag  = AUTHENTICATION_TYPE_ALL;
    pwps_info->enrollee.encry_type_flag = ENCRYPTION_TYPE_ALL;

    if (pwps_info->enrollee.device_password_id == DEVICE_PASSWORD_ID_PIN)
    {
        /* Generate PIN */
        wps_generate_PIN(pwps_info);

        if (pwps_info->pin_generator == WPS_ENROLLEE)
        {
            pwps_info->input_state = WPS_INPUT_STATE_NO_INPUT;
            pwps_info->pin_pbc_set = WPS_SET;
        }
        else
        {
            pwps_info->enrollee.updated_device_password_id = DEVICE_PASSWORD_REG_SPECIFIED;
        }
    }

    (void)memset(&wps_network, 0, sizeof(struct wlan_network));

    if (g_ssid && strlen((const char *)g_ssid))
        strncpy(wps_network.name, "wps_network",
                ((MAX_SSID_LEN + 1) > strlen("wps_network")) ? strlen("wps_network") : (MAX_SSID_LEN + 1));
    else
        strncpy(wps_network.name, "p2p_network",
                ((MAX_SSID_LEN + 1) > strlen("p2p_network")) ? strlen("p2p_network") : (MAX_SSID_LEN + 1));
    wps_network.name[(sizeof(wps_network.name) / sizeof(wps_network.name[0])) - 1] = '\0';
    (void)memcpy(wps_network.ssid, (const char *)g_ssid, MAX_SSID_LEN + 1);
    (void)memcpy(wps_network.bssid, (const char *)g_bssid, ETH_ALEN);
    wps_network.channel           = g_channel;
    wps_network.ip.ipv4.addr_type = ADDR_TYPE_DHCP;
#ifdef CONFIG_WPS2
    wps_network.wps_specific = 1;
#endif /* CONFIG_WPS2 */
    if (g_channel)
        wps_network.channel_specific = 1;
    else if (is_mac_all_zero(g_bssid))
        wps_network.ssid_specific = 1;
    else
        wps_network.bssid_specific = 1;

    wps_network.security.type = WLAN_SECURITY_NONE;
    ret = wlan_add_network(&wps_network);

    if (ret != 0)
    {
        wps_d(" Failed to add network %d\r\n", ret);
        goto fail;
    }

    do
    {
        wps_d("Connecting to %s .....", wps_network.ssid);

        ret = wlan_connect(wps_network.name);

        if (ret != 0)
        {
            wps_d("Failed to connect %d\r\n", ret);
            goto retry;
        }

        connect_retry = 200;

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

            if (state == WLAN_ASSOCIATED || connect_retry == 0)
                break;
        }
        while (connect_retry--);

        if (state != WLAN_ASSOCIATED)
        {
            wps_d("Error: Not connected.\r\n");
            goto retry;
        }

        wps_d("Connected to following BSS (or IBSS) :");
        wps_d("SSID = [%s], BSSID = [%02x:%02x:%02x:%02x:%02x:%02x]", wps_network.ssid, wps_network.bssid[0],
              wps_network.bssid[1], wps_network.bssid[2], wps_network.bssid[3], wps_network.bssid[4],
              wps_network.bssid[5]);

        /* Save information to global structure */
        wps_s->current_ssid.ssid_len = strlen(wps_network.ssid);
        (void)memcpy(wps_s->current_ssid.ssid, wps_network.ssid, wps_s->current_ssid.ssid_len);

        (void)memcpy(wps_s->current_ssid.bssid, wps_network.bssid, ETH_ALEN);

        /* Store Peer MAC Address */
        if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
        {
            if (is_mac_all_zero((u8 *)wps_network.bssid))
            {
                if (wlan_get_current_network(&sta_network))
                    goto fail;
                (void)memcpy(pwps_info->registrar.mac_address, sta_network.bssid, ETH_ALEN);
            }
            else
                (void)memcpy(pwps_info->registrar.mac_address, wps_network.bssid, ETH_ALEN);
        }
        wps_d("WPS Registration Protocol Started .....");

        if (wps.cb(WPS_SESSION_STARTED, NULL, 0) == -WM_FAIL)
        {
            wps_d("WPS Callback failed for event: %d\r\n", WPS_SESSION_STARTED);
        }
        /* Start WPS registration timer */
        wps_start_registration_timer(pwps_info);

        /* Starting WPS Message Exchange Engine */

        wps_state_machine_start(pwps_info);

        ret = WPS_STATUS_SUCCESS;
        break;

    retry:
        retry_cnt--;
        wps_d("Connect to AP FAIL ! Retrying ..... \r\n");
        wps_d("Retry Count = %d", retry_cnt);

    } while (retry_cnt != 0);

    if (retry_cnt == 0)
    {
    fail:
        os_thread_sleep(os_msec_to_ticks(500));

        wps_d("WPS Registration Protocol Failed !");

        ret = wlan_disconnect();
        if (ret != 0)
            wps_d("Failed to disconnect \r\n");

        ret = wlan_remove_network(wps_network.name);
        if (ret != 0)
            wps_d("Failed to remove network %d\r\n", ret);
        if (wps.cb(WPS_SESSION_FAILED, NULL, 0) == -WM_FAIL)
            wps_d("WPS Callback failed for event: %d\r\n", WPS_SESSION_FAILED);
        return WPS_STATUS_FAIL;
    }
    LEAVE();
    return ret;
}

#ifdef CONFIG_WPA2_ENTP
static int prov_entp_enrollee_start(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int ret = WPS_STATUS_SUCCESS;

    ENTER();

    pwps_info->enrollee.auth_type_flag  = AUTHENTICATION_TYPE_ALL;
    pwps_info->enrollee.encry_type_flag = ENCRYPTION_TYPE_ALL;

    /* Save information to global structure */
    wps_s->current_ssid.ssid_len = strlen(wps_s->wpa2_network.ssid);
    (void)memcpy(wps_s->current_ssid.ssid, wps_s->wpa2_network.ssid, wps_s->current_ssid.ssid_len);

    (void)memcpy(wps_s->current_ssid.bssid, wps_s->wpa2_network.bssid, ETH_ALEN);

    /* Store Peer MAC Address */
    if (pwps_info->role == WPS_ENROLLEE || (IS_DISCOVERY_ENROLLEE(pwps_info)))
    {
        if (is_mac_all_zero((u8 *)wps_s->wpa2_network.bssid))
        {
            if (wlan_get_current_network(&sta_network))
                goto fail;
            (void)memcpy(pwps_info->registrar.mac_address, sta_network.bssid, ETH_ALEN);
        }
        else
            (void)memcpy(pwps_info->registrar.mac_address, wps_s->wpa2_network.bssid, ETH_ALEN);
    }

    wps_d("Connected to following BSS (or IBSS) :");
    wps_d("SSID = [%s], BSSID = [%02x:%02x:%02x:%02x:%02x:%02x]", wps_s->wpa2_network.ssid,
          wps_s->wpa2_network.bssid[0], wps_s->wpa2_network.bssid[1], wps_s->wpa2_network.bssid[2],
          wps_s->wpa2_network.bssid[3], wps_s->wpa2_network.bssid[4], wps_s->wpa2_network.bssid[5]);
    if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_TLS)
        wps_d(
            "WPA2 Enterprise (EAP-TLS) "
            "Protocol Started .....");
    else if (wps_s->wpa2_network.security.type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
        wps_d(
            "WPA2 Enterprise (PEAPv0/EAP-MSCHAPv2) "
            "Protocol Started .....");

    /* Start WPS registration timer */
    wps_start_registration_timer(pwps_info);

    /* Starting WPS Message Exchange Engine */

    wps_state_machine_start(pwps_info);

    ret = WPS_STATUS_SUCCESS;

fail:
    LEAVE();
    return ret;
}
#endif

/**
 *  @brief Process WPS Enrollee PIN mode and PBC user selection operations
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param wps_s        A pointer to global WPS structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_enrollee_start(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int ret = WPS_STATUS_SUCCESS;

#ifdef CONFIG_WPA2_ENTP
    if (pwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT)
        ret = prov_entp_enrollee_start(pwps_info, wps_s);
    else
#endif
        ret = prov_wps_enrollee_start(pwps_info, wps_s);

    return ret;
}

/**
 *  @brief Process WPS Registrar operations
 *
 *  @param pwps_info    A pointer to WPS_INFO structure
 *  @param wps_s        A pointer to global WPS structure
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_registrar_start(PWPS_INFO pwps_info, WPS_DATA *wps_s)
{
    int ret = WPS_STATUS_SUCCESS;

    ENTER();

    if (!pwps_info->registrar.auth_type_flag)
        pwps_info->registrar.auth_type_flag = AUTHENTICATION_TYPE_ALL;
    if (!pwps_info->registrar.encry_type_flag)
        pwps_info->registrar.encry_type_flag = ENCRYPTION_TYPE_ALL;

    if (pwps_info->registrar.device_password_id == DEVICE_PASSWORD_ID_PIN)
    {
        /* Generate PIN */
        wps_generate_PIN(pwps_info);

        if (pwps_info->pin_generator == WPS_ENROLLEE)
        {
            pwps_info->input_state = WPS_INPUT_STATE_NO_INPUT;
            pwps_info->pin_pbc_set = WPS_SET;
        }
        else
        {
            pwps_info->enrollee.updated_device_password_id = DEVICE_PASSWORD_REG_SPECIFIED;
        }
    }
    wps_d("WPS Registration Protocol Started .....");

    /* Start WPS registration timer */
    wps_start_registration_timer(pwps_info);

    /* Starting WPS Message Exchange Engine */
    wps_state_machine_start(pwps_info);

    LEAVE();
    return ret;
}
