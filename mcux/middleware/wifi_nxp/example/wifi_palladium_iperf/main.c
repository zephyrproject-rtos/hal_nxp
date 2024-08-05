/** @file main.c
 *
 *  @brief main file
 *
 *  Copyright 2020-2024 NXP
 *  All rights reserved.
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 */

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////

// SDK Included Files
#include "board.h"
#include "fsl_debug_console.h"

#include "wlan_bt_fw.h"
#include "wlan.h"
#include "wifi.h"
#include "wm_net.h"
#include <osa.h>
#include "dhcp-server.h"

#include "lwiperf.h"
#include "lwip/tcpip.h"
#if CONFIG_PALLADIUM_SUPPORT
#include "wifi_ping.h"
#include "mlan_api.h"
#endif
#include "app.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

const int TASK_MAIN_PRIO       = OS_PRIO_4;
const int TASK_MAIN_STACK_SIZE = 800;

portSTACK_TYPE *task_main_stack = NULL;
TaskHandle_t task_main_task_handler;
TimerHandle_t timer;

static void timer_poll_udp_client(TimerHandle_t timer);

#if CONFIG_PALLADIUM_SUPPORT
extern pdm_wlan_t pdm_wlan;
enum
{
    HAL_VALIDATION_SET_UNICAST_KEY = 1,
    HAL_VALIDATION_SET_MULTICAST_KEY,
    HAL_VALIDATION_READ_UNICAST_KEY,
    HAL_VALIDATION_SET_BYPASS,
    HAL_VALIDATION_DELETE_UNICAST_KEY,
    HAL_VALIDATION_SET_EU_TEST,
    HAL_VALIDATION_SET_EU_CCMP,
    HAL_VALIDATION_SET_WAKEUP_CONFIG,
    HAL_VALIDATION_SET_IPS_CONFIG,
    HAL_VALIDATION_SET_HOSTCMD,
};
extern unsigned int uap_ip;
extern unsigned int sta_ip;

// Hardwired SSID, passphrase of Soft AP to star
#define AP_SSID       "NXP_Soft_AP"
#define AP_PASSPHRASE "12345678"

// Hardwired SSID, passphrase of AP to connect to
// Change this to fit your AP
#define EXT_AP_SSID       "NXP_Soft_AP"
#define EXT_AP_PASSPHRASE "12345678"
#else
// Hardwired SSID, passphrase of Soft AP to star
#define AP_SSID           "NXP_Soft_AP"
#define AP_PASSPHRASE     "12345678"

// Hardwired SSID, passphrase of AP to connect to
// Change this to fit your AP
#define EXT_AP_SSID       "nxp_wifi_demo"
#define EXT_AP_PASSPHRASE ""
#endif

#ifndef IPERF_SERVER_ADDRESS
#define IPERF_SERVER_ADDRESS "192.168.10.1"
#endif

#ifndef IPERF_UDP_CLIENT_RATE
#define IPERF_UDP_CLIENT_RATE (100 * 1024 * 1024) /* 100 Mbit/s */
#endif

#ifndef IPERF_CLIENT_AMOUNT
#define IPERF_CLIENT_AMOUNT (-1000) /* 10 seconds */
#endif

struct iperf_test_context
{
    bool server_mode;
    bool tcp;
    enum lwiperf_client_type client_type;
    void *iperf_session;
};

static struct iperf_test_context ctx;

struct wlan_network sta_network;
struct wlan_network uap_network;

static void iperf_test_start(void *arg);
static void iperf_test_abort(void *arg);

// ============================================================================
// Menu Handling
// ============================================================================
#if CONFIG_PALLADIUM_SUPPORT
static void pdm_wlan_set_txratecfg(u32_t rate_format, u32_t rate_index, u32_t nss)
{
    wlan_ds_rate ds_rate;
    int rv = WM_SUCCESS;

    (void)memset(&ds_rate, 0, sizeof(wlan_ds_rate));
    ds_rate.sub_command                = WIFI_DS_RATE_CFG;
    ds_rate.param.rate_cfg.rate_format = rate_format;
    ds_rate.param.rate_cfg.rate_index  = rate_index;
#if CONFIG_11AC
    ds_rate.param.rate_cfg.nss = nss;
#endif

#if CONFIG_11AC
    if (ds_rate.param.rate_cfg.rate_format > 2)
#else
    if (ds_rate.param.rate_cfg.rate_format > 1)
#endif
    {
        (void)PRINTF("Invalid format selection\r\n");
        return;
    }

    if (((ds_rate.param.rate_cfg.rate_format == 0) && (ds_rate.param.rate_cfg.rate_index > 11)) ||
        ((ds_rate.param.rate_cfg.rate_format == 1) && (ds_rate.param.rate_cfg.rate_index != 32) &&
         (ds_rate.param.rate_cfg.rate_index > 7)))
    {
        (void)PRINTF("Invalid index selection\r\n");
        return;
    }
#if CONFIG_11AC
    /* NSS is supported up to 2 */
    if ((ds_rate.param.rate_cfg.nss <= 0) || (ds_rate.param.rate_cfg.nss >= 3))
    {
        (void)PRINTF("Invalid nss selection\r\n");
        return;
    }
#endif

    rv = wlan_set_txratecfg(ds_rate);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set txratecfg\r\n");
    }

    return;
}

static void pdm_wlan_set_static_ip(struct wlan_network *network)
{
    uint8_t psk_len            = 0;
    network->ip.ipv4.addr_type = ADDR_TYPE_STATIC;
    network->ip.ipv4.address   = htonl(sta_ip);
    network->ip.ipv4.netmask   = htonl(0xffffff00UL);
    network->ip.ipv4.gw        = htonl(uap_ip);
    network->ssid_specific     = 1;
    if (pdm_wlan.enable_security)
    {
        network->security.type = pdm_wlan.security_mode;
        psk_len                = (strlen(EXT_AP_PASSPHRASE) <= (WLAN_PSK_MAX_LENGTH - 1)) ? strlen(EXT_AP_PASSPHRASE) :
                                                                                            (WLAN_PSK_MAX_LENGTH - 1);
        strncpy(network->security.psk, EXT_AP_PASSPHRASE, psk_len);
        network->security.psk_len = psk_len;
    }
    else
    {
        network->security.type = WLAN_SECURITY_NONE;
    }
}
#endif

static void printSeparator(void)
{
    PRINTF("========================================\r\n");
}

int __scan_cb(unsigned int count)
{
    struct wlan_scan_result res;
    int i;
    int err;

    if (count == 0)
    {
        PRINTF("no networks found\r\n");
        return 0;
    }

    PRINTF("%d network%s found:\r\n", count, count == 1 ? "" : "s");

    for (i = 0; i < count; i++)
    {
        err = wlan_get_scan_result(i, &res);
        if (err)
        {
            PRINTF("Error: can't get scan res %d\r\n", i);
            continue;
        }

        print_mac(res.bssid);

        if (res.ssid[0])
            PRINTF(" \"%s\"\r\n", res.ssid);
        else
            PRINTF(" (hidden) \r\n");

        PRINTF("\tchannel: %d\r\n", res.channel);
        PRINTF("\trssi: -%d dBm\r\n", res.rssi);
        PRINTF("\tsecurity: ");
        if (res.wep)
            PRINTF("WEP ");
        if (res.wpa && res.wpa2)
            PRINTF("WPA/WPA2 Mixed ");
        else
        {
            if (res.wpa)
                PRINTF("WPA ");
            if (res.wpa2)
                PRINTF("WPA2 ");
            if (res.wpa3_sae)
                PRINTF("WPA3 SAE ");
            if (res.wpa2_entp)
                PRINTF("WPA2 Enterprise");
        }
        if (!(res.wep || res.wpa || res.wpa2 || res.wpa3_sae || res.wpa2_entp))
            PRINTF("OPEN ");
        PRINTF("\r\n");

        PRINTF("\tWMM: %s\r\n", res.wmm ? "YES" : "NO");
    }

    return 0;
}

static void menuScan(void)
{
    if (wlan_scan(__scan_cb))
        PRINTF("Error: scan request failed\r\n");
    else
        PRINTF("Scan scheduled...\r\n");
}

static void menuConnectToAP(void)
{
    int ret;

    PRINTF("Connecting to %s .....", sta_network.ssid);

    ret = wlan_connect(sta_network.name);

    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to connect %d\r\n", ret);
    }
}

static void menuDisconnect(void)
{
    int ret;

    /* STA Disconnect */
    ret = wlan_disconnect();

    if (ret != WM_SUCCESS)
    {
        PRINTF("Error: Failed to disconnect\r\n");
    }
}

static void menuIEEEPSON(void)
{
    wlan_ieeeps_on(WAKE_ON_ARP_BROADCAST | WAKE_ON_UNICAST | WAKE_ON_MULTICAST | WAKE_ON_MAC_EVENT);
}

static void menuIEEEPSOFF(void)
{
    wlan_ieeeps_off();
}

static void menuDEEPSLEEPON(void)
{
    wlan_deepsleepps_on();
}

static void menuDEEPSLEEPOFF(void)
{
    wlan_deepsleepps_off();
}

static const char *print_role(enum wlan_bss_role role)
{
    switch (role)
    {
        case WLAN_BSS_ROLE_STA:
            return "Infra";
        case WLAN_BSS_ROLE_UAP:
            return "uAP";
        case WLAN_BSS_ROLE_ANY:
            return "any";
    }

    return "unknown";
}

static void print_address(struct wlan_ip_config *addr, enum wlan_bss_role role)
{
    struct in_addr ip, gw, nm, dns1, dns2;
    char addr_type[10];

    ip.s_addr   = addr->ipv4.address;
    gw.s_addr   = addr->ipv4.gw;
    nm.s_addr   = addr->ipv4.netmask;
    dns1.s_addr = addr->ipv4.dns1;
    dns2.s_addr = addr->ipv4.dns2;
    if (addr->ipv4.addr_type == ADDR_TYPE_STATIC)
        strncpy(addr_type, "STATIC", sizeof(addr_type));
    else if (addr->ipv4.addr_type == ADDR_TYPE_STATIC)
        strncpy(addr_type, "AUTO IP", sizeof(addr_type));
    else
        strncpy(addr_type, "DHCP", sizeof(addr_type));

    PRINTF("\r\n\tIPv4 Address\r\n");
    PRINTF("\taddress: %s", addr_type);
    PRINTF("\r\n\t\tIP:\t\t%s", inet_ntoa(ip));
    PRINTF("\r\n\t\tgateway:\t%s", inet_ntoa(gw));
    PRINTF("\r\n\t\tnetmask:\t%s", inet_ntoa(nm));
    PRINTF("\r\n\t\tdns1:\t\t%s", inet_ntoa(dns1));
    PRINTF("\r\n\t\tdns2:\t\t%s", inet_ntoa(dns2));
    PRINTF("\r\n");
}

static void print_network(struct wlan_network *network)
{
    PRINTF("\"%s\"\r\n\tSSID: %s\r\n\tBSSID: ", network->name, network->ssid[0] ? network->ssid : "(hidden)");

    print_mac(network->bssid);

    if (network->channel)
        PRINTF("\r\n\tchannel: %d", network->channel);
    else
        PRINTF("\r\n\tchannel: %s", "(Auto)");

    PRINTF("\r\n\trole: %s\r\n", print_role(network->role));

    char *sec_tag = "\tsecurity";
    if (!network->security_specific)
    {
        sec_tag = "\tsecurity [Wildcard]";
    }
    switch (network->security.type)
    {
        case WLAN_SECURITY_NONE:
            PRINTF("%s: none\r\n", sec_tag);
            break;
        case WLAN_SECURITY_WEP_OPEN:
            PRINTF("%s: WEP (open)\r\n", sec_tag);
            break;
        case WLAN_SECURITY_WEP_SHARED:
            PRINTF("%s: WEP (shared)\r\n", sec_tag);
            break;
        case WLAN_SECURITY_WPA:
            PRINTF("%s: WPA\r\n", sec_tag);
            break;
        case WLAN_SECURITY_WPA2:
            PRINTF("%s: WPA2\r\n", sec_tag);
            break;
        case WLAN_SECURITY_WPA_WPA2_MIXED:
            PRINTF("%s: WPA/WPA2 Mixed\r\n", sec_tag);
            break;
        case WLAN_SECURITY_WPA3_SAE:
            PRINTF("%s: WPA3 SAE\r\n", sec_tag);
            break;
        default:
            break;
    }

    print_address(&network->ip, network->role);
}

static void menuPrintInfo(void)
{
    enum wlan_connection_state state;
    struct wlan_network psta_network;
    struct wlan_network puap_network;
    int sta_found = 0;

    if (wlan_get_connection_state(&state))
    {
        PRINTF(
            "Error: unable to get STA connection"
            " state\r\n");
    }
    else
    {
        switch (state)
        {
            case WLAN_CONNECTED:
                if (!wlan_get_current_network(&psta_network))
                {
                    PRINTF("Station connected to:\r\n");
                    print_network(&psta_network);
                    sta_found = 1;
                }
                else
                    PRINTF("Station not connected\r\n");
                break;
            default:
                PRINTF("Station not connected\r\n");
                break;
        }
    }

    if (wlan_get_current_uap_network(&puap_network))
        PRINTF("uAP not started\r\n");
    else
    {
        /* Since uAP automatically changes the channel to the one that
         * STA is on */
        if (sta_found == 1)
            puap_network.channel = psta_network.channel;

        if (puap_network.role == WLAN_BSS_ROLE_UAP)
            PRINTF("uAP started as:\r\n");

        print_network(&puap_network);
    }
}

static void menuPrintDHCPServerInfo()
{
    dhcp_stat();
}

static void menuSeparator(void)
{
    printSeparator();
}

static void menuExtraHelp(void)
{
    PRINTF("For Soft AP demonstration\r\n");
    PRINTF("Start a Soft AP using option \"A\" in WPA2 security mode from menu\r\n");
    PRINTF("This also starts DHCP Server with IP 192.168.10.1, NETMASK 255.255.255.0\r\n");
    printSeparator();
    PRINTF("For Station demonstration\r\n");
    PRINTF("Start an External AP with SSID as \"%s\" in Open mode\r\n", EXT_AP_SSID);
    PRINTF("Start DHCP Server on External AP\r\n");
    PRINTF("Station network is configured with Dynamic address assignment\r\n");
    PRINTF("Application provides IPerf support\r\n");
    PRINTF("Set IPERF_SERVER_ADDRESS while using as IPerf Client\r\n");
    printSeparator();
}

static void menuPrint(void);

static void menuTCPServer(void)
{
    char key;

    ctx.server_mode = true;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_CLIENT;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuTCPClient(void)
{
    char key;

    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_CLIENT;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuTCPClientDualMode(void)
{
    char key;

    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_DUAL;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuTCPClientTradeOffMode(void)
{
    char key;

    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_TRADEOFF;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuUDPServer(void)
{
    char key;

    ctx.server_mode = true;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_CLIENT;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuUDPClient(void)
{
    char key;

    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_CLIENT;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuUDPClientDualMode(void)
{
    char key;

    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_DUAL;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuUDPClientTradeOffMode(void)
{
    char key;

    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_TRADEOFF;

    tcpip_callback(iperf_test_start, (void *)&ctx);

    do
    {
        key = GETCHAR();
    } while (key != ' ');

    tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void menuStartSoftAP(void)
{
    int ret;

    ret = wlan_start_network(uap_network.name);
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to start Soft AP\r\n");
    }
}

static void menuStopSoftAP(void)
{
    int ret;

    if (is_uap_started())
    {
        ret = wlan_stop_network(uap_network.name);

        if (ret != WM_SUCCESS)
        {
            PRINTF("Failed to stop Soft AP network\r\n");
            return;
        }

        return;
    }

    PRINTF("Soft AP is not up\r\n");
}

typedef struct
{
    char key;
    void (*func)(void);
    const char *text;
} menu_item_t;

menu_item_t menuItems[] = {
    {'A', menuStartSoftAP, "Start Soft AP"},
    {'S', menuStopSoftAP, "Stop Soft AP"},
    {'s', menuScan, "Start Scan for external APs"},
    {'c', menuConnectToAP, "Connect to External AP (SSID='" EXT_AP_SSID "')"},
    {'D', menuDisconnect, "Disconnect from External AP"},
    {'I', menuIEEEPSON, "Enable IEEE PS on Station"},
    {'i', menuIEEEPSOFF, "Disable IEEE PS on Station"},
    {'d', menuDEEPSLEEPON, "Enable Deep sleep on Station"},
    {'e', menuDEEPSLEEPOFF, "Disable Deep sleep on Station"},
    {'p', menuPrintInfo, "Print All Network info"},
    {'P', menuPrintDHCPServerInfo, "Print DHCP Server info"},
    {'1', menuTCPServer, "TCP server mode (RX only test)"},
    {'2', menuTCPClient, "TCP client mode (TX only test)"},
    {'3', menuTCPClientDualMode, "TCP client dual mode (TX and RX in parallel)"},
    {'4', menuTCPClientTradeOffMode, "TCP client tradeoff mode (TX and RX sequentially)"},
    {'5', menuUDPServer, "UDP server mode (RX only test)"},
    {'6', menuUDPClient, "UDP client mode (TX only test)"},
    {'7', menuUDPClientDualMode, "UDP client dual mode (TX and RX in parallel)"},
    {'8', menuUDPClientTradeOffMode, "UDP client tradeoff mode (TX and RX sequentially)"},
    {'h', menuPrint, "Help (print this menu)"},
    {'H', menuExtraHelp, "Print extended help"},
    {0, NULL, NULL},
};

static void menuAction(int ch)
{
    if (ch == '\r' || ch == ' ')
    {
        menuSeparator();
        return;
    }

    for (int i = 0; menuItems[i].func != NULL; i++)
    {
        if (menuItems[i].key == ch)
        {
            PRINTF("Key '%c': %s\r\n", ch, menuItems[i].text);
            menuItems[i].func();
            return;
        }
    }
    PRINTF("ERROR: No action bound to '%c'\r\n", ch);
}

static void menuPrint(void)
{
    for (int i = 0; menuItems[i].text != NULL; i++)
    {
        if (menuItems[i].key)
            PRINTF("  %c  %s\r\n", menuItems[i].key, menuItems[i].text);
        else
            PRINTF("  %d  %s\r\n", i, menuItems[i].text);
    }
}

static int pollChar()
{
    //    if (!UART_HAL_GetStatusFlag(BOARD_DEBUG_UART_BASEADDR, kUartRxDataRegFull))
    //        return -1;
    //
    //    uint8_t ch;
    //    UART_HAL_Getchar(BOARD_DEBUG_UART_BASEADDR, &ch);
    //    // Flush the UART to avoid the "OpenSDA UART infinite RX FIFO" bug:
    //    // If user presses keys very quickly then after a while, the UART enters
    //    // a mode where the same sequence of characters are repeatedly returned
    //    // by UART_HAL_Getchar(). Even a hard reset does not fix it.
    //    // Only way to recover is by unplugging OpenSDA USB.
    //    UART_HAL_FlushRxFifo(BOARD_DEBUG_UART_BASEADDR);

    int tmp;
    // TODO: verify the message above. Which board has this issue ?
    tmp = GETCHAR();
    return tmp;
}
// ============================================================================
// Main
// ============================================================================

#define MAX_RETRY_TICKS 50

static int network_added     = 0;
static int uap_network_added = 0;

/* Callback Function passed to WLAN Connection Manager. The callback function
 * gets called when there are WLAN Events that need to be handled by the
 * application.
 */
int wlan_event_callback(enum wlan_event_reason reason, void *data)
{
    struct wlan_ip_config addr;
    char ip[16];
    static int auth_fail = 0;

    printSeparator();
    PRINTF("app_cb: WLAN: received event %d\r\n", reason);
    printSeparator();

    switch (reason)
    {
        case WLAN_REASON_INITIALIZED:
            PRINTF("app_cb: WLAN initialized\r\n");
            int ret;

            printSeparator();

            /* Print WLAN FW Version */
            wlan_version_extended();
            printSeparator();

            if (!network_added)
            {
                uint8_t network_name_len = 0;
                uint8_t ssid_len         = 0;
                uint8_t psk_len          = 0;
                memset(&sta_network, 0, sizeof(struct wlan_network));

                network_name_len = (strlen("sta_network") < WLAN_NETWORK_NAME_MAX_LENGTH) ?
                                       (strlen("sta_network") + 1) :
                                       WLAN_NETWORK_NAME_MAX_LENGTH;
                strncpy(sta_network.name, "sta_network", network_name_len);

                ssid_len = (strlen(EXT_AP_SSID) <= IEEEtypes_SSID_SIZE) ? strlen(EXT_AP_SSID) : IEEEtypes_SSID_SIZE;
                memcpy(sta_network.ssid, (const char *)EXT_AP_SSID, ssid_len);
#if CONFIG_PALLADIUM_SUPPORT
                pdm_wlan_set_static_ip(&sta_network);
#else
                sta_network.ip.ipv4.addr_type = ADDR_TYPE_DHCP;
                sta_network.ssid_specific     = 1;
                if (strlen(EXT_AP_PASSPHRASE))
                {
                    sta_network.security.type = WLAN_SECURITY_WILDCARD;
                    psk_len = (strlen(EXT_AP_PASSPHRASE) <= (WLAN_PSK_MAX_LENGTH - 1)) ? strlen(EXT_AP_PASSPHRASE) :
                                                                                         (WLAN_PSK_MAX_LENGTH - 1);
                    strncpy(sta_network.security.psk, EXT_AP_PASSPHRASE, psk_len);
                    sta_network.security.psk_len = psk_len;
                }
                else
                {
                    sta_network.security.type = WLAN_SECURITY_NONE;
                }
#endif
                ret = wlan_add_network(&sta_network);

                if (ret != 0)
                {
                    PRINTF(" Failed to add network %d\r\n", ret);
                    return 0;
                }
                network_added = 1;
            }

            if (!uap_network_added)
            {
                uint8_t ssid_len = 0;
                uint8_t psk_len  = 0;

                wlan_initialize_uap_network(&uap_network);

                /* Set SSID as passed by the user */
                ssid_len = (strlen(AP_SSID) <= IEEEtypes_SSID_SIZE) ? strlen(AP_SSID) : IEEEtypes_SSID_SIZE;
                memcpy(uap_network.ssid, (const char *)AP_SSID, ssid_len);
                /* Channel 0 sets channel selection to auto */
#if CONFIG_PALLADIUM_SUPPORT
                uap_network.channel       = pdm_wlan.test_channel;
                uap_network.security.type = pdm_wlan.enable_security;
#else
                uap_network.channel       = 0;
                uap_network.security.type = WLAN_SECURITY_WPA2;
#endif
                /* Set the passphrase. Max WPA2 passphrase can be upto 64 ASCII chars */
                psk_len = (strlen(AP_PASSPHRASE) <= (WLAN_PSK_MAX_LENGTH - 1)) ? strlen(AP_PASSPHRASE) :
                                                                                 (WLAN_PSK_MAX_LENGTH - 1);
                strncpy(uap_network.security.psk, AP_PASSPHRASE, psk_len);
                uap_network.security.psk_len = psk_len;

                ret = wlan_add_network(&uap_network);
                if (ret != WM_SUCCESS)
                {
                    PRINTF(" Failed to add uAP network %d\r\n", ret);
                    return 0;
                }

                uap_network_added = 1;
            }

            timer = xTimerCreate("UDP Poll Timer", 1 / portTICK_PERIOD_MS, pdTRUE, (void *)0, timer_poll_udp_client);
            if (timer == NULL)
            {
                PRINTF("UDP Poll Timer creation failed!\r\n");
            }

            if (xTimerStart(timer, 0) != pdPASS)
            {
                PRINTF("UDP Poll Timer could not be started!\r\n");
            }
            break;
        case WLAN_REASON_INITIALIZATION_FAILED:
            PRINTF("app_cb: WLAN: initialization failed\r\n");
            break;
        case WLAN_REASON_AUTH_SUCCESS:
            PRINTF("app_cb: WLAN: authenticated to network\r\n");
            break;
        case WLAN_REASON_SUCCESS:
            PRINTF("app_cb: WLAN: connected to network\r\n");

            ret = wlan_get_address(&addr);
            if (ret != WM_SUCCESS)
            {
                PRINTF("failed to get IP address\r\n");
                return 0;
            }

            net_inet_ntoa(addr.ipv4.address, ip);

            PRINTF("Connected to following BSS:\r\n");
            PRINTF("SSID = [%s]\r\n", sta_network.ssid);
            if (addr.ipv4.address != 0U)
            {
                PRINTF("IPv4 Address: [%s]\r\n", ip);
            }
#if CONFIG_IPV6
            int i;
            for (i = 0; i < CONFIG_MAX_IPV6_ADDRESSES; i++)
            {
                if (ip6_addr_isvalid(addr.ipv6[i].addr_state))
                {
                    (void)PRINTF("IPv6 Address: %-13s:\t%s (%s)\r\n",
                                 ipv6_addr_type_to_desc((struct net_ipv6_config *)&addr.ipv6[i]),
                                 inet6_ntoa(addr.ipv6[i].address), ipv6_addr_state_to_desc(addr.ipv6[i].addr_state));
                }
            }
            (void)PRINTF("\r\n");
#endif
            PRINTF("SSID = [%s], IP = [%s]\r\n", sta_network.ssid, ip);
            auth_fail = 0;
#if CONFIG_PALLADIUM_SUPPORT
            pdm_wlan.get_ip_addr = true;
#endif
            break;
        case WLAN_REASON_CONNECT_FAILED:
            PRINTF("app_cb: WLAN: connect failed\r\n");
            break;
        case WLAN_REASON_NETWORK_NOT_FOUND:
            PRINTF("app_cb: WLAN: network not found\r\n");
            break;
        case WLAN_REASON_NETWORK_AUTH_FAILED:
            PRINTF("app_cb: WLAN: network authentication failed\r\n");
            auth_fail++;
            if (auth_fail >= 3)
            {
                PRINTF("Authentication Failed. Disconnecting ... \r\n");
                wlan_disconnect();
                auth_fail = 0;
            }
            break;
        case WLAN_REASON_ADDRESS_SUCCESS:
            PRINTF("network mgr: DHCP new lease\r\n");
            break;
        case WLAN_REASON_ADDRESS_FAILED:
            PRINTF("app_cb: failed to obtain an IP address\r\n");
            break;
        case WLAN_REASON_USER_DISCONNECT:
            PRINTF("app_cb: disconnected\r\n");
            auth_fail = 0;
            break;
        case WLAN_REASON_LINK_LOST:
            PRINTF("app_cb: WLAN: link lost\r\n");
            break;
        case WLAN_REASON_CHAN_SWITCH:
            PRINTF("app_cb: WLAN: channel switch\r\n");
            break;
        case WLAN_REASON_UAP_SUCCESS:
            PRINTF("app_cb: WLAN: UAP Started\r\n");
            printSeparator();
            PRINTF("Soft AP \"%s\" Started successfully\r\n", AP_SSID);
            printSeparator();
            if (dhcp_server_start(net_get_uap_handle()))
                PRINTF("Error in starting dhcp server\r\n");

            PRINTF("DHCP Server started successfully\r\n");
            printSeparator();
            break;
        case WLAN_REASON_UAP_CLIENT_ASSOC:
            PRINTF("app_cb: WLAN: UAP a Client Associated\r\n");
            printSeparator();
            PRINTF("Client => ");
            print_mac((const char *)data);
            PRINTF("Associated with Soft AP\r\n");
            printSeparator();
#if CONFIG_PALLADIUM_SUPPORT
            pdm_wlan.get_ip_addr = true;
#endif
            break;
        case WLAN_REASON_UAP_CLIENT_DISSOC:
            PRINTF("app_cb: WLAN: UAP a Client Dissociated\r\n");
            printSeparator();
            PRINTF("Client => ");
            print_mac((const char *)data);
            PRINTF("Dis-Associated from Soft AP\r\n");
            printSeparator();
            break;
        case WLAN_REASON_UAP_STOPPED:
            PRINTF("app_cb: WLAN: UAP Stopped\r\n");
            printSeparator();
            PRINTF("Soft AP \"%s\" Stoped successfully\r\n", AP_SSID);
            printSeparator();

            dhcp_server_stop();

            PRINTF("DHCP Server stopped successfully\r\n");
            printSeparator();
            break;
        case WLAN_REASON_PS_ENTER:
            PRINTF("app_cb: WLAN: PS_ENTER\r\n");
            break;
        case WLAN_REASON_PS_EXIT:
            PRINTF("app_cb: WLAN: PS EXIT\r\n");
            break;
        default:
            PRINTF("app_cb: WLAN: Unknown Event: %d\r\n", reason);
    }
    return 0;
}

void task_main(void *param)
{
    int32_t result = 0;
    (void)result;
    ip_addr_t addr;
    int ret;

    PRINTF("Initialize WLAN Driver\r\n");

#if CONFIG_PALLADIUM_SUPPORT
    inet_aton("192.168.10.1", &addr);
#endif

    /* Initialize WIFI Driver */
    result = wlan_init(wlan_fw_bin, wlan_fw_bin_len);

    assert(WM_SUCCESS == result);

    result = wlan_start(wlan_event_callback);

    assert(WM_SUCCESS == result);

    printSeparator();
    menuExtraHelp();

    menuPrint();

#if CONFIG_PALLADIUM_SUPPORT
    pdm_wlan.inputC = 0;
    while (1)
    {
    wait_input:
        if (pdm_wlan.inputC == 0)
        {
            OSA_TimeDelay(10);
            if (pdm_wlan.test_set_rate)
            {
                pdm_wlan_set_txratecfg(pdm_wlan.test_rate_format, pdm_wlan.test_rate_index, pdm_wlan.test_nss);
            }
            if (pdm_wlan.hal_validation)
            {
                if (HAL_VALIDATION_SET_UNICAST_KEY == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_validation(EU_SET_UNICAST_KEY, is_uap_started());
                }
                else if (HAL_VALIDATION_SET_MULTICAST_KEY == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_validation(EU_SET_MULTICAST_KEY, is_uap_started());
                }
                else if (HAL_VALIDATION_READ_UNICAST_KEY == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_read(is_uap_started());
                }
                else if (HAL_VALIDATION_SET_BYPASS == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_bypass(1, is_uap_started());
                }
                else if (HAL_VALIDATION_DELETE_UNICAST_KEY == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_validation(EU_DELETE_UNICAST_KEY, is_uap_started());
                }
                else if (HAL_VALIDATION_SET_EU_TEST == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_test(is_uap_started(), pdm_wlan.hal_validation_param);
                }
                else if (HAL_VALIDATION_SET_EU_CCMP == pdm_wlan.hal_validation)
                {
                    wifi_set_eu_ccmp(is_uap_started(), pdm_wlan.hal_validation_param);
                }
                else if (HAL_VALIDATION_SET_WAKEUP_CONFIG == pdm_wlan.hal_validation)
                {
                    wifi_set_wakeup_config(WLAN_BSS_TYPE_STA, pdm_wlan.hal_validation_param);
                }
                else if (HAL_VALIDATION_SET_IPS_CONFIG == pdm_wlan.hal_validation)
                {
                    wifi_set_ips_config(WLAN_BSS_TYPE_STA, pdm_wlan.hal_validation_param);
                }
                else if (HAL_VALIDATION_SET_HOSTCMD == pdm_wlan.hal_validation)
                {
                    wifi_set_hostcmd();
                }
                pdm_wlan.hal_validation = 0;
            }
            if (pdm_wlan.get_ip_addr && pdm_wlan.ping_req)
            {
                if (is_uap_started() && pdm_wlan.peer_mac)
                {
                    char str_peer_mac[16] = {0};
                    snprintf(str_peer_mac, 16, "%u.%u.%u.%u", (pdm_wlan.peer_mac & 0xFF000000) >> 24,
                             (pdm_wlan.peer_mac & 0x00FF0000) >> 16, (pdm_wlan.peer_mac & 0x0000FF00) >> 8,
                             (pdm_wlan.peer_mac & 0x000000FF));
                    inet_aton(str_peer_mac, &addr);
                }
                ret = ping(1, PING_DEFAULT_SIZE, 1, &addr);
                if (WM_SUCCESS == ret)
                    pdm_wlan.ping_success_cnt++;
                else
                    pdm_wlan.ping_failure_cnt++;
            }
            goto wait_input;
        }
        if (pdm_wlan.inputC != 0)
        {
            menuAction(pdm_wlan.inputC);
            pdm_wlan.inputC = 0;
        }
    }
#else
    while (1)
    {
        int ch = pollChar();

        if (ch != -1)
        {
            menuAction(ch);
        }

        /* wait for interface up */
        OSA_TimeDelay(500);
    }
#endif
}

/* Report state => string */
const char *report_type_str[] = {
    "TCP_DONE_SERVER (RX)",        /* LWIPERF_TCP_DONE_SERVER_RX,*/
    "TCP_DONE_SERVER (TX)",        /* LWIPERF_TCP_DONE_SERVER_TX,*/
    "TCP_DONE_CLIENT (TX)",        /* LWIPERF_TCP_DONE_CLIENT_TX,*/
    "TCP_DONE_CLIENT (RX)",        /* LWIPERF_TCP_DONE_CLIENT_RX,*/
    "TCP_ABORTED_LOCAL",           /* LWIPERF_TCP_ABORTED_LOCAL, */
    "TCP_ABORTED_LOCAL_DATAERROR", /* LWIPERF_TCP_ABORTED_LOCAL_DATAERROR, */
    "TCP_ABORTED_LOCAL_TXERROR",   /* LWIPERF_TCP_ABORTED_LOCAL_TXERROR, */
    "TCP_ABORTED_REMOTE",          /* LWIPERF_TCP_ABORTED_REMOTE, */
    "UDP_DONE_SERVER (RX)",        /* LWIPERF_UDP_DONE_SERVER_RX, */
    "UDP_DONE_SERVER (TX)",        /* LWIPERF_UDP_DONE_SERVER_TX, */
    "UDP_DONE_CLIENT (TX)",        /* LWIPERF_UDP_DONE_CLIENT_TX, */
    "UDP_DONE_CLIENT (RX)",        /* LWIPERF_UDP_DONE_CLIENT_RX, */
    "UDP_ABORTED_LOCAL",           /* LWIPERF_UDP_ABORTED_LOCAL, */
    "UDP_ABORTED_LOCAL_DATAERROR", /* LWIPERF_UDP_ABORTED_LOCAL_DATAERROR, */
    "UDP_ABORTED_LOCAL_TXERROR",   /* LWIPERF_UDP_ABORTED_LOCAL_TXERROR, */
    "UDP_ABORTED_REMOTE",          /* LWIPERF_UDP_ABORTED_REMOTE, */
};

/** Prototype of a report function that is called when a session is finished.
    This report function shows the test results. */
static void lwiperf_report(void *arg,
                           enum lwiperf_report_type report_type,
                           const ip_addr_t *local_addr,
                           u16_t local_port,
                           const ip_addr_t *remote_addr,
                           u16_t remote_port,
                           u64_t bytes_transferred,
                           u32_t ms_duration,
                           u32_t bandwidth_kbitpsec)
{
    PRINTF("-------------------------------------------------\r\n");
    if (report_type < (sizeof(report_type_str) / sizeof(report_type_str[0])))
    {
        PRINTF(" %s \r\n", report_type_str[report_type]);
        if (local_addr && remote_addr)
        {
            PRINTF(" Local address : %u.%u.%u.%u ", ((u8_t *)local_addr)[0], ((u8_t *)local_addr)[1],
                   ((u8_t *)local_addr)[2], ((u8_t *)local_addr)[3]);
            PRINTF(" Port %d \r\n", local_port);
            PRINTF(" Remote address : %u.%u.%u.%u ", ((u8_t *)remote_addr)[0], ((u8_t *)remote_addr)[1],
                   ((u8_t *)remote_addr)[2], ((u8_t *)remote_addr)[3]);
            PRINTF(" Port %d \r\n", remote_port);
            PRINTF(" Bytes Transferred %llu \r\n", bytes_transferred);
            PRINTF(" Duration (ms) %d \r\n", ms_duration);
            PRINTF(" Bandwidth (Mbitpsec) %d \r\n", bandwidth_kbitpsec / 1000);
        }
    }
    else
    {
        PRINTF(" IPERF Report error\r\n");
    }
    PRINTF("\r\n");
}

/*!
 * @brief Function to start iperf test.
 */
static void iperf_test_start(void *arg)
{
    struct iperf_test_context *ctx = (struct iperf_test_context *)arg;
    ip_addr_t server_address;

    ctx->iperf_session = NULL;

    if (!(ctx->tcp) && ctx->client_type == LWIPERF_DUAL)
    {
        /* Reducing timer interval of UDP Tx for Rx to run */
        xTimerChangePeriod(timer, MSEC_TO_TICK(4), 100);
    }
    else
    {
        /* Setting timer to original value of 1 ms */
        xTimerChangePeriod(timer, 1 / portTICK_PERIOD_MS, 100);
    }

    if (ctx->server_mode)
    {
        if (ctx->tcp)
        {
            ctx->iperf_session = lwiperf_start_tcp_server(IP_ADDR_ANY, LWIPERF_TCP_PORT_DEFAULT, lwiperf_report, 0);
        }
        else
        {
            ctx->iperf_session =
                lwiperf_start_udp_server(netif_ip_addr4(netif_default), LWIPERF_TCP_PORT_DEFAULT, lwiperf_report, 0);
        }
    }
    else
    {
        if (ipaddr_aton(IPERF_SERVER_ADDRESS, &server_address) && IP_IS_V4(&server_address))
        {
            if (ctx->tcp)
            {
                ctx->iperf_session =
                    lwiperf_start_tcp_client(&server_address, LWIPERF_TCP_PORT_DEFAULT, ctx->client_type,
                                             IPERF_CLIENT_AMOUNT, 0, LWIPERF_TOS_DEFAULT, lwiperf_report, 0);
            }
            else
            {
                ctx->iperf_session = lwiperf_start_udp_client(
                    netif_ip_addr4(netif_default), LWIPERF_TCP_PORT_DEFAULT, &server_address, LWIPERF_TCP_PORT_DEFAULT,
                    ctx->client_type, IPERF_CLIENT_AMOUNT, 0, IPERF_UDP_CLIENT_RATE, 0, lwiperf_report, NULL);
            }
        }
        else
        {
            PRINTF("IPERF_SERVER_ADDRESS is not a valid IPv4 address!\r\n");
        }
    }

    if (ctx->iperf_session == NULL)
    {
        PRINTF("IPERF initialization failed!\r\n");
    }
}

/*!
 * @brief Function to abort iperf test.
 */
static void iperf_test_abort(void *arg)
{
    struct iperf_test_context *ctx = (struct iperf_test_context *)arg;

    if (ctx->iperf_session != NULL)
    {
        lwiperf_abort(ctx->iperf_session);
        ctx->iperf_session = NULL;
    }
}

/*!
 * @brief Invokes UDP polling, to be run on tcpip_thread.
 */
static void poll_udp_client(void *arg)
{
    LWIP_UNUSED_ARG(arg);

    lwiperf_poll_udp_client();
}

/*!
 * @brief Invokes UDP polling on tcpip_thread.
 */
static void timer_poll_udp_client(TimerHandle_t timer)
{
    LWIP_UNUSED_ARG(timer);

    tcpip_try_callback(poll_udp_client, NULL);
}

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

int main(void)
{
    BaseType_t result = 0;
    (void)result;

    BOARD_InitHardware();

    printSeparator();
    PRINTF("wifi iperf demo\r\n");
    printSeparator();

    result =
        xTaskCreate(task_main, "main", TASK_MAIN_STACK_SIZE, task_main_stack, TASK_MAIN_PRIO, &task_main_task_handler);
    assert(pdPASS == result);

    vTaskStartScheduler();
    for (;;)
        ;
}
