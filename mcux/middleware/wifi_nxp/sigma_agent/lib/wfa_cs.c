/****************************************************************************
Copyright (c) 2016 Wi-Fi Alliance.  All Rights Reserved

Permission to use, copy, modify, and/or distribute this software for any purpose with or
without fee is hereby granted, provided that the above copyright notice and this permission
notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH
THE USE OR PERFORMANCE OF THIS SOFTWARE.

******************************************************************************/

/*
 *   File: wfa_cs.c -- configuration and setup
 *   This file contains all implementation for the dut setup and control
 *   functions, such as network interfaces, ip address and wireless specific
 *   setup with its supplicant.
 *
 *   The current implementation is to show how these functions
 *   should be defined in order to support the Agent Control/Test Manager
 *   control commands. To simplify the current work and avoid any GPL licenses,
 *   the functions mostly invoke shell commands by calling linux system call,
 *   system("<commands>").
 *
 *   It depends on the differnt device and platform, vendors can choice their
 *   own ways to interact its systems, supplicants and process these commands
 *   such as using the native APIs.
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <linux/types.h>
// #include <linux/socket.h>
// #include <poll.h>
#include <wlan.h>
#include <wifi.h>
#include <wifi-decl.h>
#include "nxp_wifi.h"
#if CONFIG_SIGMA_AGENT
#include "wfa_portall.h"
#include "wfa_debug.h"
#include "wfa_ver.h"
#include "wfa_main.h"
#include "wfa_types.h"
#include "wfa_ca.h"
#include "wfa_tlv.h"
#include "wfa_sock.h"
#include "wfa_tg.h"
#include "wfa_cmds.h"
#include "wfa_rsp.h"
#include "wfa_utils.h"
#include "nxp_gvars.h"

#ifdef WFA_WMM_PS_EXT
#include "wfa_wmmps.h"
#endif

#define CERTIFICATES_PATH "/etc/wpa_supplicant"

#define STA_NET_NAME "dut_sta"

/* Some device may only support UDP ECHO, activate this line */
// #define WFA_PING_UDP_ECHO_ONLY 1

#define WFA_ENABLED 1

char gname[WFA_SSID_NAME_LEN];

extern unsigned short wfa_defined_debug;
int wfaExecuteCLI(char *CLI);

int wfaTGSetPrio(int sockfd, int tgClass);
void create_apts_msg(int msg, unsigned int txbuf[], int id);

int sret = 0;

extern char e2eResults[];

// FILE *e2efp = NULL;
int chk_ret_status()
{
    char *ret = getenv(WFA_RET_ENV);

    if (*ret == '1')
        return WFA_SUCCESS;
    else
        return WFA_FAILURE;
}

/*
 * agtCmdProcGetVersion(): response "ca_get_version" command to controller
 *  input:  cmd --- not used
 *          valLen -- not used
 *  output: parms -- a buffer to store the version info response.
 */
int agtCmdProcGetVersion(int len, BYTE *parms, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *getverResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "entering agtCmdProcGetVersion ...\n");

    getverResp->status = STATUS_COMPLETE;
    wSTRNCPY(getverResp->cmdru.version, WFA_SYSTEM_VER, WFA_VERNAM_LEN);

    wfaEncodeTLV(WFA_GET_VERSION_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)getverResp, respBuf);

    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * wfaStaAssociate():
 *    The function is to force the station wireless I/F to re/associate
 *    with the AP.
 */
int wfaStaAssociate(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCommand_t *assoc            = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staAssocResp = &gGenericResp;
    char *ssid                     = (char *)assoc->cmdsu.ssid;
    int length;

    length = strlen(ssid);
    memset(sta_saved_ssid, 0, 33);

    if (length >= WLAN_NETWORK_NAME_MAX_LENGTH)
        strncpy(sta_saved_ssid, "1", WLAN_NETWORK_NAME_MAX_LENGTH);
    else
        memcpy(sta_saved_ssid, ssid, strlen(ssid));

    DPRINT_INFO(WFA_OUT, "Entering wfaStaAssociate...\n");

    int ret = wlan_connect(sta_saved_ssid);

    if (ret != WM_SUCCESS)
    {
        staAssocResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_ASSOCIATE_RESP_TLV, 4, (BYTE *)staAssocResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;
        return WFA_FAILURE;
    }

#if 0
    /*
     * if bssid appears, station should associate with the specific
     * BSSID AP at its initial association.
     * If it is different to the current associating AP, it will be forced to
     * roam the new AP
     */
    if(assoc->cmdsu.assoc.bssid[0] != '\0')
    {
        /* if (the first association) */
        /* just do initial association to the BSSID */


        /* else (station already associate to an AP) */
        /* Do forced roaming */

    }
    else
    {
        /* use 'ifconfig' command to bring down the interface (linux specific) */
      //sprintf(gCmdStr, "ifconfig %s down", ifname);
      //sret = system(gCmdStr);

        /* use 'ifconfig' command to bring up the interface (linux specific) */
      //sprintf(gCmdStr, "ifconfig %s up", ifname);
      //sret = system(gCmdStr);

        /*
         *  use 'wpa_cli' command to force a 802.11 re/associate
         *  (wpa_supplicant specific)
         */
        sprintf(gCmdStr, "wpa_cli -i%s reassociate", ifname);
        sret = system(gCmdStr);
    }
#endif
    /*
     * Then report back to control PC for completion.
     * This does not have failed/error status. The result only tells
     * a completion.
     */
    staAssocResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_ASSOCIATE_RESP_TLV, 4, (BYTE *)staAssocResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaReAssociate():
 *    The function is to force the station wireless I/F to re/associate
 *    with the AP.
 */
int wfaStaReAssociate(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *reassoc            = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staReAssocResp = &gGenericResp;
    // char *ssid                       = (char *)reassoc->cmdsu.ssid;

    DPRINT_INFO(WFA_OUT, "entering wfaStaReassociate ...");

    DPRINT_INFO(WFA_OUT, "ssid ==> %s\n", sta_saved_ssid);

    int ret = wlan_connect(sta_saved_ssid);

    sleep(10);

    if (ret != WM_SUCCESS)
    {
        staReAssocResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_ASSOCIATE_RESP_TLV, 4, (BYTE *)staReAssocResp, respBuf);

        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Unable to reassociate ");
        return WFA_FAILURE;
    }

#if 0
    /*
     * if bssid appears, station should associate with the specific
     * BSSID AP at its initial association.
     * If it is different to the current associating AP, it will be forced to
     * roam the new AP
     */
    if(assoc->cmdsu.assoc.bssid[0] != '\0')
    {
        /* if (the first association) */
        /* just do initial association to the BSSID */


        /* else (station already associate to an AP) */
        /* Do forced roaming */

    }
    else
    {
        /* use 'ifconfig' command to bring down the interface (linux specific) */
        sprintf(gCmdStr, "ifconfig %s down", ifname);
        sret = system(gCmdStr);

        /* use 'ifconfig' command to bring up the interface (linux specific) */
        sprintf(gCmdStr, "ifconfig %s up", ifname);

        /*
         *  use 'wpa_cli' command to force a 802.11 re/associate
         *  (wpa_supplicant specific)
         */
        sprintf(gCmdStr, "wpa_cli -i%s reassociate", ifname);
        sret = system(gCmdStr);
    }
#endif

    /*
     * Then report back to control PC for completion.
     * This does not have failed/error status. The result only tells
     * a completion.
     */
    staReAssocResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_ASSOCIATE_RESP_TLV, 4, (BYTE *)staReAssocResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaIsConnected():
 *    The function is to check whether the station's wireless I/F has
 *    already connected to an AP.
 */
int wfaStaIsConnected(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *staConnectResp = &gGenericResp;
    wifi_ds_rate txrate;
    //  wifi_data_rate_t *datarate = (wifi_data_rate_t *)&(txrate.param.data_rate);

    (void)memset(&txrate, 0, sizeof(wifi_ds_rate));

    DPRINT_INFO(WFA_OUT, "Entering isConnected ...");

    if (is_sta_connected())
    {
        staConnectResp->cmdru.connected = 1;
        /*
         * For configuring stasetwireless parameters after association
         */
        txrate.sub_command = 1;
        (void)wifi_get_data_rate(&txrate, 0);

        width = (int)txrate.param.data_rate.tx_bw;
        DPRINT_INFO(WFA_OUT, "\n AK: txrate.param.data_rate.tx_bw => %d \n", (int)txrate.param.data_rate.tx_bw);

        if (MCSINDEX > 0)
        {
            DPRINT_INFO(WFA_OUT, "\n Info: Setting stasetwireless params post association \n");
            txrate.sub_command                = 0;
            txrate.param.rate_cfg.rate_format = HE;
            txrate.param.rate_cfg.rate_index  = MCSINDEX;
#if (CONFIG_11AC) || (CONFIG_11AX)
            txrate.param.rate_cfg.nss = NSS;
#endif
            if (width == 0 && coding == 0)
                txrate.param.rate_cfg.rate_setting = 0x2020;
            if (width == 0 && coding == 1)
                txrate.param.rate_cfg.rate_setting = 0x2220;
            if (width == 2 && coding == 0)
                txrate.param.rate_cfg.rate_setting = 0x2028;
            if (width == 2 && coding == 1)
                txrate.param.rate_cfg.rate_setting = 0x2228;

            (void)wifi_set_txratecfg(txrate, 0);
        }
    }
    else
    {
        staConnectResp->cmdru.connected = 0;
    }

    /*
     * Report back the status: Complete or Failed.
     */
    staConnectResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_IS_CONNECTED_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)staConnectResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * wfaStaGetIpConfig():
 * This function is to retriev the ip info including
 *     1. dhcp enable
 *     2. ip address
 *     3. mask
 *     4. primary-dns
 *     5. secondary-dns
 *
 *     The current implementation is to use a script to find these information
 *     and store them in a file.
 */
int wfaStaGetIpConfig(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    //    dutCommand_t *getIpConf = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *ipconfigResp = &gGenericResp;
    //    char *ifname = getIpConf->intf;
    caStaGetIpConfigResp_t *ifinfo = &ipconfigResp->cmdru.getIfconfig;
    struct wlan_network network;
    struct wlan_ip_config *addr;
    int ret = -WM_FAIL;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaGetIpConfig  ...");

    ret = wlan_get_current_network(&network);

    /*
     * check a script file (the current implementation specific)
     */
    if (ret != WM_SUCCESS)
    {
        /*ipconfigResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_GET_IP_CONFIG_RESP_TLV, 4, (BYTE *)ipconfigResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "not connected");
        return WFA_FAILURE;*/
    }

    memset(ifinfo, 0, sizeof(caStaGetIpConfigResp_t));

    addr = &network.ip;

    struct in_addr ip, nm; //, dns1, dns2;

    ip.s_addr = addr->ipv4.address;
    nm.s_addr = addr->ipv4.netmask;

    net_addr_ntop(AF_INET, &ip, ifinfo->ipaddr, sizeof(ifinfo->ipaddr));
    net_addr_ntop(AF_INET, &nm, ifinfo->mask, sizeof(ifinfo->mask));

    /*
     * Report back the results
     */
    ipconfigResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_GET_IP_CONFIG_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)ipconfigResp, respBuf);

    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

#if 1
    DPRINT_INFO(WFA_OUT, "%i %i %s %s %s %s %i\n", ipconfigResp->status, ifinfo->isDhcp, ifinfo->ipaddr, ifinfo->mask,
                ifinfo->dns[0], ifinfo->dns[1], *respLen);
#endif

    return WFA_SUCCESS;
}

/*
 * wfaStaSetIpConfig():
 *   The function is to set the ip configuration to a wireless I/F.
 *   1. IP address
 *   2. Mac address
 *   3. default gateway
 *   4. dns nameserver (pri and sec).
 */
int wfaStaSetIpConfig(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCommand_t *setIpConf        = (dutCommand_t *)caCmdBuf;
    caStaSetIpConfig_t *ipconfig   = &setIpConf->cmdsu.ipconfig;
    dutCmdResponse_t *staSetIpResp = &gGenericResp;
    struct wlan_ip_config ip;
    int ret = -WM_FAIL;

    DPRINT_INFO(WFA_OUT, "entering wfaStaSetIpConfig ...");

    memset(&ip, 0, sizeof(struct wlan_ip_config));

    if (strlen(ipconfig->ipaddr))
    {
        ip.ipv4.address = net_inet_aton(ipconfig->ipaddr);
    }

    if (strlen(ipconfig->defGateway))
    {
        ip.ipv4.gw = net_inet_aton(ipconfig->defGateway);
    }

    if (strlen(ipconfig->mask))
    {
        ip.ipv4.netmask = net_inet_aton(ipconfig->mask);
    }

    if (strlen(ipconfig->pri_dns))
    {
        ip.ipv4.dns1 = net_inet_aton(ipconfig->pri_dns);
    }

    if (strlen(ipconfig->sec_dns))
    {
        ip.ipv4.dns2 = net_inet_aton(ipconfig->sec_dns);
    }

    if (ipconfig->isDhcp)
    {
        ip.ipv4.addr_type = ADDR_TYPE_DHCP;
    }
    else
    {
        ip.ipv4.addr_type = ADDR_TYPE_STATIC;
    }

    ret = wlan_set_network_ip_byname(gname, &ip);
    if (ret != WM_SUCCESS)
    {
        staSetIpResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_SET_IP_CONFIG_RESP_TLV, 4, (BYTE *)staSetIpResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Unable to set IP address");
        return WFA_FAILURE;
    }

    /*
     * report status
     */
    staSetIpResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_IP_CONFIG_RESP_TLV, 4, (BYTE *)staSetIpResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaVerifyIpConnection():
 * The function is to verify if the station has IP connection with an AP by
 * send ICMP/pings to the AP.
 */
int wfaStaVerifyIpConnection(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCommand_t *verip            = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *verifyIpResp = &gGenericResp;
    uint16_t size    = PING_DEFAULT_SIZE;
    uint16_t count   = PING_DEFAULT_COUNT;
    uint32_t timeout = PING_DEFAULT_TIMEOUT_SEC;
    int intval       = PING_INTERVAL;
    int ret          = -1;

#ifndef WFA_PING_UDP_ECHO_ONLY
    // char strout[64], *pcnt;
    // FILE *tmpfile;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaVerifyIpConnection ...\n");

    /* set timeout value in case not set */
    if (verip->cmdsu.verifyIp.timeout <= 0)
    {
        verip->cmdsu.verifyIp.timeout = 10;
    }
#if 0
    /* execute the ping command  and pipe the result to a tmp file */
    sprintf(gCmdStr, "ping %s -c 3 -W %u | grep loss | cut -f3 -d, 1>& /tmp/pingout.txt", verip->cmdsu.verifyIp.dipaddr, verip->cmdsu.verifyIp.timeout);
    sret = system(gCmdStr);

    /* scan/check the output */
    tmpfile = fopen("/tmp/pingout.txt", "r+");
    if(tmpfile == NULL)
    {
        verifyIpResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_VERIFY_IP_CONNECTION_RESP_TLV, 4, (BYTE *)verifyIpResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "file open failed\n");
        return WFA_FAILURE;
    }

    verifyIpResp->status = STATUS_COMPLETE;
    if(fscanf(tmpfile, "%s", strout) == EOF)
        verifyIpResp->cmdru.connected = 0;
    else
    {
        pcnt = strtok(strout, "%");

        /* if the loss rate is 100%, not able to connect */
        if(atoi(pcnt) == 100)
            verifyIpResp->cmdru.connected = 0;
        else
            verifyIpResp->cmdru.connected = 1;
    }

    fclose(tmpfile);
#endif
    ret = ping(count, intval, size, timeout, &verip->cmdsu.verifyIp.dipaddr[0]);

    if (ret == WM_SUCCESS)
        verifyIpResp->cmdru.connected = 1;
    else
        verifyIpResp->cmdru.connected = 0;

#else
    int btSockfd;
    struct pollfd fds[2];
    int timeout = 2000;
    char anyBuf[64];
    struct sockaddr_in toAddr;
    int done = 1, cnt = 0, ret, nbytes;

    verifyIpResp->status          = STATUS_COMPLETE;
    verifyIpResp->cmdru.connected = 0;

    btSockfd = wfaCreateUDPSock("127.0.0.1", WFA_UDP_ECHO_PORT);

    if (btSockfd == -1)
    {
        verifyIpResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_VERIFY_IP_CONNECTION_RESP_TLV, 4, (BYTE *)verifyIpResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;
        return WFA_FAILURE;
        ;
    }

    toAddr.sin_family      = AF_INET;
    toAddr.sin_addr.s_addr = inet_addr(verip->cmdsu.verifyIp.dipaddr);
    toAddr.sin_port        = htons(WFA_UDP_ECHO_PORT);

    while (done)
    {
        wfaTrafficSendTo(btSockfd, (char *)anyBuf, 64, (struct sockaddr *)&toAddr);
        cnt++;

        fds[0].fd     = btSockfd;
        fds[0].events = POLLIN | POLLOUT;

        ret = poll(fds, 1, timeout);
        switch (ret)
        {
            case 0:
                /* it is time out, count a packet lost*/
                break;
            case -1:
            /* it is an error */
            default:
            {
                switch (fds[0].revents)
                {
                    case POLLIN:
                    case POLLPRI:
                    case POLLOUT:
                        nbytes = wfaTrafficRecv(btSockfd, (char *)anyBuf, (struct sockaddr *)&toAddr);
                        if (nbytes != 0)
                            verifyIpResp->cmdru.connected = 1;
                        done = 0;
                        break;
                    default:
                        /* errors but not care */
                        ;
                }
            }
        }
        if (cnt == 3)
        {
            done = 0;
        }
    }

#endif

    wfaEncodeTLV(WFA_STA_VERIFY_IP_CONNECTION_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)verifyIpResp, respBuf);

    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * wfaStaGetMacAddress()
 *    This function is to retrieve the MAC address of a wireless I/F.
 */
int wfaStaGetMacAddress(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    //    dutCommand_t *getMac = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *getmacResp = &gGenericResp;
    //    char *ifname = getMac->intf;
    int ret = -WM_FAIL;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaGetMacAddress ...");

    /* Get source mac address */
    BYTE mac[MLAN_MAC_ADDR_LENGTH];

    ret = wlan_get_mac_address(mac);

    if (ret != WM_SUCCESS)
    {
        getmacResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_GET_MAC_ADDRESS_RESP_TLV, 4, (BYTE *)getmacResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Unable to retrieve MAC address");
        return WFA_FAILURE;
    }

    memset(getmacResp->cmdru.mac, 0, WFA_MAC_ADDR_STR_LEN);
    snprintf(getmacResp->cmdru.mac, WFA_MAC_ADDR_STR_LEN, SMACSTR, SMAC2STR(mac));
    getmacResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_GET_MAC_ADDRESS_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)getmacResp, respBuf);

    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * wfaStaGetStats():
 * The function is to retrieve the statistics of the I/F's layer 2 txFrames,
 * rxFrames, txMulticast, rxMulticast, fcsErrors/crc, and txRetries.
 * Currently there is not definition how to use these info.
 */
int wfaStaGetStats(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *statsResp = &gGenericResp;

    /* this is never used, you can skip this call */

    statsResp->status = STATUS_ERROR;
    wfaEncodeTLV(WFA_STA_GET_STATS_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)statsResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * wfaSetEncryption():
 *   The function is to set the wireless interface with WEP or none.
 *
 *   Since WEP is optional test, current function is only used for
 *   resetting the Security to NONE/Plaintext (OPEN). To test WEP,
 *   this function should be replaced by the next one (wfaSetEncryption1())
 *
 *   Input parameters:
 *     1. I/F
 *     2. ssid
 *     3. encpType - wep or none
 *     Optional:
 *     4. key1
 *     5. key2
 *     6. key3
 *     7. key4
 *     8. activeKey Index
 */

int wfaSetEncryption1(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEncryption_t *setEncryp = (caStaSetEncryption_t *)caCmdBuf;
    dutCmdResponse_t *setEncrypResp = &gGenericResp;

    /*
     * disable the network first
     */
    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", setEncryp->intf);
    sret = system(gCmdStr);

    /*
     * set SSID
     */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", setEncryp->intf, setEncryp->ssid);
    sret = system(gCmdStr);

    /*
     * Tell the supplicant for infrastructure mode (1)
     */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 mode 0", setEncryp->intf);
    sret = system(gCmdStr);

    /*
     * set Key management to NONE (NO WPA) for plaintext or WEP
     */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt NONE", setEncryp->intf);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", setEncryp->intf);
    sret = system(gCmdStr);

    setEncrypResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_ENCRYPTION_RESP_TLV, 4, (BYTE *)setEncrypResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

#define DEF_IP 0xc0a80a01UL /* 192.168.10.1 */
static unsigned int sta_ip = DEF_IP;

static void wlan_initialize_sta_network2(struct wlan_network *net)
{
    (void)memset(net, 0, sizeof(struct wlan_network));
    /* Set profile name */
    (void)strcpy(net->name, STA_NET_NAME);
    /* Set channel selection to auto (0) */
    net->channel = 0;
    /* Set network type to uAP */
    net->type = WLAN_BSS_TYPE_STA;
    /* Set network role to uAP */
    net->role = WLAN_BSS_ROLE_STA;
    /* Set IP address to 192.168.10.1 */
    net->ip.ipv4.address = htonl(sta_ip);
    /* Set default gateway to 192.168.10.1 */
    net->ip.ipv4.gw = htonl(sta_ip);
    /* Set netmask to 255.255.255.0 */
    net->ip.ipv4.netmask = htonl(0xffffff00UL);
    /* Specify address type as static assignment */
    net->ip.ipv4.addr_type = ADDR_TYPE_DHCP;
}

/*
 *  Since WEP is optional, this function could be used to replace
 *  wfaSetEncryption() if necessary.
 */
int wfaSetEncryption(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEncryption_t *setEncryp = (caStaSetEncryption_t *)caCmdBuf;
    dutCmdResponse_t *setEncrypResp = &gGenericResp;
    int ret                         = -WM_FAIL;
    struct wlan_network net;
    DPRINT_INFO(WFA_OUT, "Entering wfaSetEncryption...");

    (void)wlan_remove_network(setEncryp->ssid);

    wlan_initialize_sta_network2(&net);

    (void)strcpy(gname, setEncryp->ssid);
    strcpy(net.name, setEncryp->ssid);

    strcpy(net.ssid, setEncryp->ssid);

    if (setEncryp->encpType == 0)
    {
        net.security.type = WLAN_SECURITY_NONE;
    }

    ret = wlan_add_network(&net);

    if (ret != WM_SUCCESS)
    {
        setEncrypResp->status = STATUS_ERROR;

        wfaEncodeTLV(WFA_STA_SET_SECURITY_RESP_TLV, 4, (BYTE *)setEncrypResp, respBuf);

        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Failed to add network");
        return WFA_FAILURE;
    }

    setEncrypResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_ENCRYPTION_RESP_TLV, 4, (BYTE *)setEncrypResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSetSecurity(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCommand_t *cmd         = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *secResp = &gGenericResp;
    caStaSetSecurity_t *sec   = &cmd->cmdsu.setsec;
    char *ssid                = sec->ssid;
    char *passphrase          = sec->secu.passphrase;
    // char *encrptype = sec->encpType;
    // char *keyMgmtType = sec->keyMgmtType;
    int ret = -WM_FAIL, length;
    struct wlan_network net;

    DPRINT_INFO(WFA_OUT, "\nInfo: gname => %s\n", gname);

    if (strcasecmp(gname, "testffd"))
    {
        DPRINT_INFO(WFA_OUT, "Entering wfaStaSetSecurity ...");
        length = strlen(ssid);
        (void)wlan_remove_network(ssid);
        (void)wlan_remove_network("1");
        wlan_initialize_sta_network2(&net);
        memset(gname, 0, WFA_SSID_NAME_LEN);
        if (length >= WLAN_NETWORK_NAME_MAX_LENGTH)
        {
            (void)strcpy(gname, "1");
            (void)strcpy(net.name, "1");
        }
        else
        {
            (void)strcpy(gname, ssid);
            (void)strcpy(net.name, ssid);
        }

        (void)strcpy(net.ssid, ssid);

        if (sec->type == SEC_TYPE_PSK)
        {
            net.security.type = WLAN_SECURITY_WPA2;
        }
        else if (sec->type == SEC_TYPE_SAE)
        {
            net.security.type           = WLAN_SECURITY_WPA3_SAE;
            net.security.pwe_derivation = 2;
        }
        else if (sec->type == SEC_TYPE_SAE_PSK)
        {
            net.security.type           = WLAN_SECURITY_WPA2_WPA3_SAE_MIXED;
            net.security.pwe_derivation = 2;
        }
#if CONFIG_DRIVER_OWE
        else if (sec->type == SEC_TYPE_OWE)
        {
            net.security.type = WLAN_SECURITY_OWE_ONLY;
        }
#endif
#if CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        else if (sec->type == SEC_TYPE_EAPTLS)
        {
            net.security.type = WLAN_SECURITY_EAP_TLS;
        }
        else if (sec->type == SEC_TYPE_EAPTTLS)
        {
            net.security.type = WLAN_SECURITY_EAP_TTLS;
        }
        else if (sec->type == SEC_TYPE_EAPPEAP)
        {
            net.security.type = WLAN_SECURITY_EAP_PEAP_MSCHAPV2;
        }
#endif

        if (sec->pmf == WFA_OPTIONAL || sec->type == SEC_TYPE_SAE_PSK)
        {
            net.security.mfpc = 1;
            net.security.mfpr = 0;
        }
        else if (sec->pmf == WFA_REQUIRED || sec->type == SEC_TYPE_SAE)
        {
            net.security.mfpc = 1;
            net.security.mfpr = 1;
        }

#if CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (strcasecmp(keyMgmtType, "SuiteB") == 0)
        {
            net.security.wpa3_sb = 1;
        }
#endif

        strcpy(net.security.psk, passphrase);
        net.security.psk_len = strlen(passphrase);

        strcpy(net.security.password, passphrase);
        net.security.password_len = strlen(passphrase);

        ret = wlan_add_network(&net);

        if (ret != WM_SUCCESS)
        {
            secResp->status = STATUS_ERROR;

            wfaEncodeTLV(WFA_STA_SET_SECURITY_RESP_TLV, 4, (BYTE *)secResp, respBuf);

            *respLen = WFA_TLV_HDR_LEN + 4;

            DPRINT_ERR(WFA_ERR, "Failed to add network");
            return WFA_FAILURE;
        }
    }

    secResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_SET_SECURITY_RESP_TLV, 4, (BYTE *)secResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
    ;
}

/*
 * wfaStaSetEapTLS():
 *   This is to set
 *   1. ssid
 *   2. encrypType - tkip or aes-ccmp
 *   3. keyManagementType - wpa or wpa2
 *   4. trustedRootCA
 *   5. clientCertificate
 */
int wfaStaSetEapTLS(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEapTLS_t *setTLS        = (caStaSetEapTLS_t *)caCmdBuf;
    char *ifname                    = setTLS->intf;
    dutCmdResponse_t *setEapTlsResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaSetEapTLS ...\n");

    /*
     * need to store the trustedROOTCA and clientCertificate into a file first.
     */
#ifdef WFA_NEW_CLI_FORMAT
    sprintf(gCmdStr, "wfa_set_eaptls -i %s %s %s %s", ifname, setTLS->ssid, setTLS->trustedRootCA,
            setTLS->clientCertificate);
    sret = system(gCmdStr);
#else

    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", ifname);
    sret = system(gCmdStr);

    /* ssid */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", ifname, setTLS->ssid);
    sret = system(gCmdStr);

    /* key management */
    if (strcasecmp(setTLS->keyMgmtType, "wpa2-sha256") == 0)
    {
    }
    else if (strcasecmp(setTLS->keyMgmtType, "wpa2-eap") == 0)
    {
    }
    else if (strcasecmp(setTLS->keyMgmtType, "wpa2-ft") == 0)
    {
    }
    else if (strcasecmp(setTLS->keyMgmtType, "wpa") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setTLS->keyMgmtType, "wpa2") == 0)
    {
        // to take all and device to pick any one supported.
    }
    else
    {
        // ??
    }
    sret = system(gCmdStr);

    /* protocol WPA */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 proto WPA", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 eap TLS", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ca_cert '\"%s\"'", ifname, setTLS->trustedRootCA);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 identity '\"wifi-user@wifilabs.local\"'", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 private_key '\"%s/%s\"'", ifname, CERTIFICATES_PATH,
            setTLS->clientCertificate);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 private_key_passwd '\"wifi\"'", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", ifname);
    sret = system(gCmdStr);
#endif

    setEapTlsResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_EAPTLS_RESP_TLV, 4, (BYTE *)setEapTlsResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * The function is to set
 *   1. ssid
 *   2. passPhrase
 *   3. keyMangementType - wpa/wpa2
 *   4. encrypType - tkip or aes-ccmp
 */
int wfaStaSetPSK(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetPSK_t *setPSK        = (caStaSetPSK_t *)caCmdBuf;
    dutCmdResponse_t *setPskResp = &gGenericResp;

    char *ssid       = setPSK->ssid;
    char *passphrase = (char *)setPSK->passphrase;
    // char *encrptype = sec->encpType;
    char *keyMgmtType = setPSK->keyMgmtType;

    int ret = -WM_FAIL, length;
    struct wlan_network net;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaSetPSK ...");

    length = strlen(ssid);

    (void)wlan_remove_network(ssid);
    (void)wlan_remove_network("1");

    wlan_initialize_sta_network2(&net);

    memset(gname, 0, WFA_SSID_NAME_LEN);

    if (length >= WLAN_NETWORK_NAME_MAX_LENGTH)
    {
        (void)strcpy(gname, "1");
        (void)strcpy(net.name, "1");
    }
    else
    {
        (void)strcpy(gname, ssid);
        (void)strcpy(net.name, ssid);
    }

    (void)strcpy(net.ssid, ssid);

    if (!strcasecmp(keyMgmtType, "wpa2"))
    {
        net.security.type = WLAN_SECURITY_WPA2;
    }

    if (setPSK->pmf == WFA_OPTIONAL)
    {
        net.security.mfpc = 1;
        net.security.mfpr = 0;
    }
    else if (setPSK->pmf == WFA_REQUIRED)
    {
        net.security.mfpc = 1;
        net.security.mfpr = 1;
    }

#if CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
    if (strcasecmp(keyMgmtType, "SuiteB") == 0)
    {
        net.security.wpa3_sb = 1;
    }
#endif

    strcpy(net.security.psk, passphrase);
    net.security.psk_len = strlen(passphrase);

    strcpy(net.security.password, passphrase);
    net.security.password_len = strlen(passphrase);

    ret = wlan_add_network(&net);

    if (ret != WM_SUCCESS)
    {
        setPskResp->status = STATUS_ERROR;

        wfaEncodeTLV(WFA_STA_SET_SECURITY_RESP_TLV, 4, (BYTE *)setPskResp, respBuf);

        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Failed to add network");
        return WFA_FAILURE;
    }

    setPskResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_PSK_RESP_TLV, 4, (BYTE *)setPskResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaGetInfo():
 * Get vendor specific information in name/value pair by a wireless I/F.
 */
int wfaStaGetInfo(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    dutCommand_t *getInfo = (dutCommand_t *)caCmdBuf;

    /*
     * Normally this is called to retrieve the vendor information
     * from a interface, no implement yet
     */
    sprintf(infoResp.cmdru.info, "interface,%s,vendor,XXX,cardtype,802.11a/b/g", getInfo->intf);

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_GET_INFO_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSetEapTTLS():
 *   This is to set
 *   1. ssid
 *   2. username
 *   3. passwd
 *   4. encrypType - tkip or aes-ccmp
 *   5. keyManagementType - wpa or wpa2
 *   6. trustedRootCA
 */
int wfaStaSetEapTTLS(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEapTTLS_t *setTTLS       = (caStaSetEapTTLS_t *)caCmdBuf;
    char *ifname                     = setTTLS->intf;
    dutCmdResponse_t *setEapTtlsResp = &gGenericResp;

#ifdef WFA_NEW_CLI_FORMAT
    sprintf(gCmdStr, "wfa_set_eapttls %s %s %s %s %s", ifname, setTTLS->ssid, setTTLS->username, setTTLS->passwd,
            setTTLS->trustedRootCA);
    sret = system(gCmdStr);
#else

    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", ifname, setTTLS->ssid);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 identity '\"%s\"'", ifname, setTTLS->username);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 password '\"%s\"'", ifname, setTTLS->passwd);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    sret = system(gCmdStr);

    /* This may not need to set. if it is not set, default to take all */
    //   sprintf(cmdStr, "wpa_cli -i %s set_network 0 pairwise '\"%s\"", ifname, setTTLS->encrptype);
    if (strcasecmp(setTTLS->keyMgmtType, "wpa2-sha256") == 0)
    {
    }
    else if (strcasecmp(setTTLS->keyMgmtType, "wpa2-eap") == 0)
    {
    }
    else if (strcasecmp(setTTLS->keyMgmtType, "wpa2-ft") == 0)
    {
    }
    else if (strcasecmp(setTTLS->keyMgmtType, "wpa") == 0)
    {
    }
    else if (strcasecmp(setTTLS->keyMgmtType, "wpa2") == 0)
    {
        // to take all and device to pick one it supported
    }
    else
    {
        // ??
    }
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 eap TTLS", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ca_cert '\"%s/%s\"'", ifname, CERTIFICATES_PATH,
            setTTLS->trustedRootCA);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 proto WPA", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 phase2 '\"auth=MSCHAPV2\"'", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", ifname);
    sret = system(gCmdStr);
#endif

    setEapTtlsResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_EAPTTLS_RESP_TLV, 4, (BYTE *)setEapTtlsResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaSetEapSIM():
 *   This is to set
 *   1. ssid
 *   2. user name
 *   3. passwd
 *   4. encrypType - tkip or aes-ccmp
 *   5. keyMangementType - wpa or wpa2
 */
int wfaStaSetEapSIM(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEapSIM_t *setSIM        = (caStaSetEapSIM_t *)caCmdBuf;
    char *ifname                    = setSIM->intf;
    dutCmdResponse_t *setEapSimResp = &gGenericResp;

#ifdef WFA_NEW_CLI_FORMAT
    sprintf(gCmdStr, "wfa_set_eapsim %s %s %s %s", ifname, setSIM->ssid, setSIM->username, setSIM->encrptype);
    sret = system(gCmdStr);
#else

    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", ifname, setSIM->ssid);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 identity '\"%s\"'", ifname, setSIM->username);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 pairwise '\"%s\"'", ifname, setSIM->encrptype);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 eap SIM", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 proto WPA", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", ifname);
    sret = system(gCmdStr);

    if (strcasecmp(setSIM->keyMgmtType, "wpa2-sha256") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-SHA256", ifname);
    }
    else if (strcasecmp(setSIM->keyMgmtType, "wpa2-eap") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setSIM->keyMgmtType, "wpa2-ft") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-FT", ifname);
    }
    else if (strcasecmp(setSIM->keyMgmtType, "wpa") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setSIM->keyMgmtType, "wpa2") == 0)
    {
        // take all and device to pick one which is supported.
    }
    else
    {
        // ??
    }
    sret = system(gCmdStr);

#endif

    setEapSimResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_EAPSIM_RESP_TLV, 4, (BYTE *)setEapSimResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaSetPEAP()
 *   This is to set
 *   1. ssid
 *   2. user name
 *   3. passwd
 *   4. encryType - tkip or aes-ccmp
 *   5. keyMgmtType - wpa or wpa2
 *   6. trustedRootCA
 *   7. innerEAP
 *   8. peapVersion
 */
int wfaStaSetPEAP(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEapPEAP_t *setPEAP    = (caStaSetEapPEAP_t *)caCmdBuf;
    char *ifname                  = setPEAP->intf;
    dutCmdResponse_t *setPeapResp = &gGenericResp;

#ifdef WFA_NEW_CLI_FORMAT
    sprintf(gCmdStr, "wfa_set_peap %s %s %s %s %s %s %i %s", ifname, setPEAP->ssid, setPEAP->username, setPEAP->passwd,
            setPEAP->trustedRootCA, setPEAP->encrptype, setPEAP->peapVersion, setPEAP->innerEAP);
    sret = system(gCmdStr);
#else

    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", ifname, setPEAP->ssid);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 eap PEAP", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 anonymous_identity '\"anonymous\"' ", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 identity '\"%s\"'", ifname, setPEAP->username);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 password '\"%s\"'", ifname, setPEAP->passwd);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ca_cert '\"%s/%s\"'", ifname, CERTIFICATES_PATH,
            setPEAP->trustedRootCA);
    sret = system(gCmdStr);

    if (strcasecmp(setPEAP->keyMgmtType, "wpa2-sha256") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-SHA256", ifname);
    }
    else if (strcasecmp(setPEAP->keyMgmtType, "wpa2-eap") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setPEAP->keyMgmtType, "wpa2-ft") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-FT", ifname);
    }
    else if (strcasecmp(setPEAP->keyMgmtType, "wpa") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setPEAP->keyMgmtType, "wpa2") == 0)
    {
        // take all and device to pick one which is supported.
    }
    else
    {
        // ??
    }
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 phase1 '\"peaplabel=%i\"'", ifname, setPEAP->peapVersion);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 phase2 '\"auth=%s\"'", ifname, setPEAP->innerEAP);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", ifname);
    sret = system(gCmdStr);
#endif

    setPeapResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_PEAP_RESP_TLV, 4, (BYTE *)setPeapResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaSetUAPSD()
 *    This is to set
 *    1. acBE
 *    2. acBK
 *    3. acVI
 *    4. acVO
 */
int wfaStaSetUAPSD(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *setUAPSDResp = &gGenericResp;
#if 0 /* used for only one specific device, need to update to reflect yours */
    caStaSetUAPSD_t *setUAPSD = (caStaSetUAPSD_t *)caCmdBuf;
    char *ifname = setUAPSD->intf;
    char tmpStr[10];
    char line[100];
    char *pathl="/etc/Wireless/RT61STA";
    BYTE acBE=1;
    BYTE acBK=1;
    BYTE acVO=1;
    BYTE acVI=1;
    BYTE APSDCapable;
    FILE *pipe;

    /*
     * A series of setting need to be done before doing WMM-PS
     * Additional steps of configuration may be needed.
     */

    /*
     * bring down the interface
     */
    sprintf(gCmdStr, "ifconfig %s down",ifname);
    sret = system(gCmdStr);
    /*
     * Unload the Driver
     */
    sprintf(gCmdStr, "rmmod rt61");
    sret = system(gCmdStr);
#ifndef WFA_WMM_AC
    if(setUAPSD->acBE != 1)
        acBE=setUAPSD->acBE = 0;
    if(setUAPSD->acBK != 1)
        acBK=setUAPSD->acBK = 0;
    if(setUAPSD->acVO != 1)
        acVO=setUAPSD->acVO = 0;
    if(setUAPSD->acVI != 1)
        acVI=setUAPSD->acVI = 0;
#else
    acBE=setUAPSD->acBE;
    acBK=setUAPSD->acBK;
    acVO=setUAPSD->acVO;
    acVI=setUAPSD->acVI;
#endif

    APSDCapable = acBE||acBK||acVO||acVI;
    /*
     * set other AC parameters
     */

    sprintf(tmpStr,"%d;%d;%d;%d",setUAPSD->acBE,setUAPSD->acBK,setUAPSD->acVI,setUAPSD->acVO);
    sprintf(gCmdStr, "sed -e \"s/APSDCapable=.*/APSDCapable=%d/g\" -e \"s/APSDAC=.*/APSDAC=%s/g\" %s/rt61sta.dat >/tmp/wfa_tmp",APSDCapable,tmpStr,pathl);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "mv /tmp/wfa_tmp %s/rt61sta.dat",pathl);
    sret = system(gCmdStr);
    pipe = popen("uname -r", "r");
    /* Read into line the output of uname*/
    fscanf(pipe,"%s",line);
    pclose(pipe);

    /*
     * load the Driver
     */
    sprintf(gCmdStr, "insmod /lib/modules/%s/extra/rt61.ko",line);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "ifconfig %s up",ifname);
    sret = system(gCmdStr);
#endif

    setUAPSDResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_UAPSD_RESP_TLV, 4, (BYTE *)setUAPSDResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaDeviceGetInfo(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    //    dutCommand_t *dutCmd = (dutCommand_t *)caCmdBuf;
    //    caDevInfo_t *devInfo = &dutCmd->cmdsu.dev;
    dutCmdResponse_t *infoResp = &gGenericResp;
    /*a vendor can fill in the proper info or anything non-disclosure */
    //    caDeviceGetInfoResp_t dinfo = {"WFA Lab", "DemoUnit", WFA_SYSTEM_VER};
    caDeviceGetInfoResp_t dinfo = {"NXP", "NXPSoC", "fw_version"};
    char *version_str; //, *pos;
    char version[WFA_VERNAM_LEN];

    DPRINT_INFO(WFA_OUT, "Entering wfaDeviceGetInfo ...");

    // Disabling power save for pre-cert testing
    (void)wlan_ieeeps_off();

    version_str = wlan_get_firmware_version_ext();

    strcpy(version, version_str);

    // pos = strtok(version, ",");

    memset(&dinfo, 0, sizeof(caDeviceGetInfoResp_t));

    strcpy(dinfo.vendor, "NXP");

    strcpy(dinfo.model, version);

    strcpy(dinfo.version, version_str);

    memcpy(&infoResp->cmdru.devInfo, &dinfo, sizeof(caDeviceGetInfoResp_t));

    infoResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_DEVICE_GET_INFO_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * This funciton is to retrieve a list of interfaces and return
 * the list back to Agent control.
 * ********************************************************************
 * Note: We intend to make this WLAN interface name as a hardcode name.
 * Therefore, for a particular device, you should know and change the name
 * for that device while doing porting. The MACRO "WFA_STAUT_IF" is defined in
 * the file "inc/wfa_ca.h". If the device OS is not linux-like, this most
 * likely is hardcoded just for CAPI command responses.
 * *******************************************************************
 *
 */
int wfaDeviceListIF(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *infoResp       = &gGenericResp;
    dutCommand_t *ifList             = (dutCommand_t *)caCmdBuf;
    caDeviceListIFResp_t *ifListResp = &infoResp->cmdru.ifList;

    DPRINT_INFO(WFA_OUT, "Entering wfaDeviceListIF ...\n");

    switch (ifList->cmdsu.iftype)
    {
        case IF_80211:
            infoResp->status   = STATUS_COMPLETE;
            ifListResp->iftype = IF_80211;
            strcpy(ifListResp->ifs[0], WFA_STAUT_IF);
            strcpy(ifListResp->ifs[1], "NULL");
            strcpy(ifListResp->ifs[2], "NULL");
            break;
        case IF_ETH:
            infoResp->status   = STATUS_COMPLETE;
            ifListResp->iftype = IF_ETH;
            strcpy(ifListResp->ifs[0], "eth0");
            strcpy(ifListResp->ifs[1], "NULL");
            strcpy(ifListResp->ifs[2], "NULL");
            break;
        default:
        {
            infoResp->status = STATUS_ERROR;
            wfaEncodeTLV(WFA_DEVICE_LIST_IF_RESP_TLV, 4, (BYTE *)infoResp, respBuf);
            *respLen = WFA_TLV_HDR_LEN + 4;

            return WFA_SUCCESS;
        }
    }

    wfaEncodeTLV(WFA_DEVICE_LIST_IF_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

int wfaStaDebugSet(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *debugResp = &gGenericResp;
    dutCommand_t *debugSet      = (dutCommand_t *)caCmdBuf;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaDebugSet ...\n");

    if (debugSet->cmdsu.dbg.state == 1) /* enable */
        wfa_defined_debug |= debugSet->cmdsu.dbg.level;
    else
        wfa_defined_debug = (~debugSet->cmdsu.dbg.level & wfa_defined_debug);

    debugResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_GET_INFO_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)debugResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 *   wfaStaGetBSSID():
 *     This function is to retrieve BSSID of a specific wireless I/F.
 */
int wfaStaGetBSSID(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *bssidResp = &gGenericResp;
    int ret                     = -WM_FAIL;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaGetBSSID ...\n");

    /* Get source mac address */
    BYTE bssid[MLAN_MAC_ADDR_LENGTH];

    ret = wlan_get_current_bssid(bssid);

    if (ret != WM_SUCCESS)
    {
        bssidResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_GET_BSSID_RESP_TLV, 4, (BYTE *)bssidResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Unable to get BSSID");
        return WFA_FAILURE;
    }

    memset(bssidResp->cmdru.bssid, 0, WFA_MAC_ADDR_STR_LEN);
    snprintf(bssidResp->cmdru.bssid, WFA_MAC_ADDR_STR_LEN, SMACSTR, SMAC2STR(bssid));

    bssidResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_GET_BSSID_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)bssidResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);

    return WFA_SUCCESS;
}

/*
 * wfaStaSetIBSS()
 *    This is to set
 *    1. ssid
 *    2. channel
 *    3. encrypType - none or wep
 *    optional
 *    4. key1
 *    5. key2
 *    6. key3
 *    7. key4
 *    8. activeIndex - 1, 2, 3, or 4
 */
int wfaStaSetIBSS(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetIBSS_t *setIBSS       = (caStaSetIBSS_t *)caCmdBuf;
    dutCmdResponse_t *setIbssResp = &gGenericResp;
    int i;

    /*
     * disable the network first
     */
    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", setIBSS->intf);
    sret = system(gCmdStr);

    /*
     * set SSID
     */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", setIBSS->intf, setIBSS->ssid);
    sret = system(gCmdStr);

    /*
     * Set channel for IBSS
     */
    sprintf(gCmdStr, "iwconfig %s channel %i", setIBSS->intf, setIBSS->channel);
    sret = system(gCmdStr);

    /*
     * Tell the supplicant for IBSS mode (1)
     */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 mode 1", setIBSS->intf);
    sret = system(gCmdStr);

    /*
     * set Key management to NONE (NO WPA) for plaintext or WEP
     */
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt NONE", setIBSS->intf);
    sret = system(gCmdStr);

    if (setIBSS->encpType == 1)
    {
        for (i = 0; i < 4; i++)
        {
            if (strlen(setIBSS->keys[i]) == 5 || strlen(setIBSS->keys[i]) == 13)
            {
                sprintf(gCmdStr, "wpa_cli -i %s set_network 0 wep_key%i \"%s\"", setIBSS->intf, i, setIBSS->keys[i]);
                sret = system(gCmdStr);
            }
        }

        i = setIBSS->activeKeyIdx;
        if (strlen(setIBSS->keys[i]) == 5 || strlen(setIBSS->keys[i]) == 13)
        {
            sprintf(gCmdStr, "wpa_cli -i %s set_network 0 wep_tx_keyidx %i", setIBSS->intf, setIBSS->activeKeyIdx);
            sret = system(gCmdStr);
        }
    }

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", setIBSS->intf);
    sret = system(gCmdStr);

    setIbssResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_IBSS_RESP_TLV, 4, (BYTE *)setIbssResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 *  wfaSetMode():
 *  The function is to set the wireless interface with a given mode (possible
 *  adhoc)
 *  Input parameters:
 *    1. I/F
 *    2. ssid
 *    3. mode adhoc or managed
 *    4. encType
 *    5. channel
 *    6. key(s)
 *    7. active  key
 */
int wfaStaSetMode(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetMode_t *setmode       = (caStaSetMode_t *)caCmdBuf;
    dutCmdResponse_t *SetModeResp = &gGenericResp;
    int i;

    /*
     * bring down the interface
     */
    sprintf(gCmdStr, "ifconfig %s down", setmode->intf);
    sret = system(gCmdStr);

    /*
     * distroy the interface
     */
    sprintf(gCmdStr, "wlanconfig %s destroy", setmode->intf);
    sret = system(gCmdStr);

    /*
     * re-create the interface with the given mode
     */
    if (setmode->mode == 1)
        sprintf(gCmdStr, "wlanconfig %s create wlandev wifi0 wlanmode adhoc", setmode->intf);
    else
        sprintf(gCmdStr, "wlanconfig %s create wlandev wifi0 wlanmode managed", setmode->intf);

    sret = system(gCmdStr);
    if (setmode->encpType == ENCRYPT_WEP)
    {
        int j = setmode->activeKeyIdx;
        for (i = 0; i < 4; i++)
        {
            if (setmode->keys[i][0] != '\0')
            {
                sprintf(gCmdStr, "iwconfig  %s key  s:%s", setmode->intf, setmode->keys[i]);
                sret = system(gCmdStr);
            }
            /* set active key */
            if (setmode->keys[j][0] != '\0')
                sprintf(gCmdStr, "iwconfig  %s key  s:%s", setmode->intf, setmode->keys[j]);
            sret = system(gCmdStr);
        }
    }
    /*
     * Set channel for IBSS
     */
    if (setmode->channel)
    {
        sprintf(gCmdStr, "iwconfig %s channel %i", setmode->intf, setmode->channel);
        sret = system(gCmdStr);
    }

    /*
     * set SSID
     */
    sprintf(gCmdStr, "iwconfig %s essid %s", setmode->intf, setmode->ssid);
    sret = system(gCmdStr);

    /*
     * bring up the interface
     */
    sprintf(gCmdStr, "ifconfig %s up", setmode->intf);
    sret = system(gCmdStr);

    SetModeResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_MODE_RESP_TLV, 4, (BYTE *)SetModeResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSetPwrSave(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetPwrSave_t *setps    = (caStaSetPwrSave_t *)caCmdBuf;
    dutCmdResponse_t *SetPSResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaSetPwrsave ...");

    if (!strcasecmp(setps->mode, "on"))
        (void)wlan_ieeeps_on(1);
    else
        (void)wlan_ieeeps_off();

    SetPSResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_PWRSAVE_RESP_TLV, 4, (BYTE *)SetPSResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSetPowerSave(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetPowerSave_t *setps  = (caStaSetPowerSave_t *)caCmdBuf;
    dutCmdResponse_t *SetPSResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaSetPowersave ...");

    if (setps->ps_flag)
        (void)wlan_ieeeps_on(1);
    else
        (void)wlan_ieeeps_off();

    SetPSResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_POWER_SAVE_RESP_TLV, 4, (BYTE *)SetPSResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaUpload(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaUpload_t *upload        = &((dutCommand_t *)caCmdBuf)->cmdsu.upload;
    dutCmdResponse_t *upLoadResp = &gGenericResp;
    //    caStaUploadResp_t *upld      = &upLoadResp->cmdru.uld;

    if (upload->type == WFA_UPLOAD_VHSO_RPT)
    {
#if 0
        int rbytes;
        /*
         * if asked for the first packet, always to open the file
         */
        if (upload->next == 1)
        {
            if (e2efp != NULL)
            {
                fclose(e2efp);
                e2efp = NULL;
            }

            //e2efp = fopen(e2eResults, "r");
        }

        if (e2efp == NULL)
        {
            upLoadResp->status = STATUS_ERROR;
            wfaEncodeTLV(WFA_STA_UPLOAD_RESP_TLV, 4, (BYTE *)upLoadResp, respBuf);
            *respLen = WFA_TLV_HDR_LEN + 4;
            return WFA_FAILURE;
        }

        rbytes = fread(upld->bytes, 1, 256, e2efp);

        if (rbytes < 256)
        {
            /*
             * this means no more bytes after this read
             */
            upld->seqnum = 0;
            fclose(e2efp);
            e2efp = NULL;
        }
        else
        {
            upld->seqnum = upload->next;
        }
        upld->nbytes = rbytes;
#endif

        upLoadResp->status = STATUS_COMPLETE;
        wfaEncodeTLV(WFA_STA_UPLOAD_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)upLoadResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);
    }
    else
    {
        upLoadResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_UPLOAD_RESP_TLV, 4, (BYTE *)upLoadResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;
    }

    return WFA_SUCCESS;
}
/*
 * wfaStaSetWMM()
 *  TO be ported on a specific plaform for the DUT
 *  This is to set the WMM related parameters at the DUT.
 *  Currently the function is used for GROUPS WMM-AC and WMM general configuration for setting RTS Threshhold,
 * Fragmentation threshold and wmm (ON/OFF) It is expected that this function will set all the WMM related parametrs for
 * a particular GROUP .
 */
int wfaStaSetWMM(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
#ifdef WFA_WMM_AC
    caStaSetWMM_t *setwmm        = (caStaSetWMM_t *)caCmdBuf;
    char *ifname                 = setwmm->intf;
    dutCmdResponse_t *setwmmResp = &gGenericResp;

    switch (setwmm->group)
    {
        case GROUP_WMMAC:
            if (setwmm->send_trig)
            {
                int Sockfd;
                struct sockaddr_in psToAddr;
                unsigned int TxMsg[512];

                Sockfd = wfaCreateUDPSock(setwmm->dipaddr, 12346);
                memset(&psToAddr, 0, sizeof(psToAddr));
                psToAddr.sin_family      = AF_INET;
                psToAddr.sin_addr.s_addr = inet_addr(setwmm->dipaddr);
                psToAddr.sin_port        = htons(12346);

                switch (setwmm->trig_ac)
                {
                    case WMMAC_AC_VO:
                        wfaTGSetPrio(Sockfd, 7);
                        create_apts_msg(APTS_CK_VO, TxMsg, 0);
                        PRINTF("\r\nSending AC_VO trigger packet\n");
                        break;

                    case WMMAC_AC_VI:
                        wfaTGSetPrio(Sockfd, 5);
                        create_apts_msg(APTS_CK_VI, TxMsg, 0);
                        PRINTF("\r\nSending AC_VI trigger packet\n");
                        break;

                    case WMMAC_AC_BK:
                        wfaTGSetPrio(Sockfd, 2);
                        create_apts_msg(APTS_CK_BK, TxMsg, 0);
                        PRINTF("\r\nSending AC_BK trigger packet\n");
                        break;

                    default:
                    case WMMAC_AC_BE:
                        wfaTGSetPrio(Sockfd, 0);
                        create_apts_msg(APTS_CK_BE, TxMsg, 0);
                        PRINTF("\r\nSending AC_BE trigger packet\n");
                        break;
                }

                sendto(Sockfd, TxMsg, 256, 0, (struct sockaddr *)&psToAddr, sizeof(struct sockaddr));
                close(Sockfd);
                wUSLEEP(1000000);
            }
            else if (setwmm->action == WMMAC_ADDTS)
            {
                PRINTF(
                    "ADDTS AC PARAMS: dialog id: %d, TID: %d, "
                    "DIRECTION: %d, PSB: %d, UP: %d, INFOACK: %d BURST SIZE DEF: %d"
                    "Fixed %d, MSDU Size: %d, Max MSDU Size %d, "
                    "MIN SERVICE INTERVAL: %d, MAX SERVICE INTERVAL: %d, "
                    "INACTIVITY: %d, SUSPENSION %d, SERVICE START TIME: %d, "
                    "MIN DATARATE: %d, MEAN DATA RATE: %d, PEAK DATA RATE: %d, "
                    "BURSTSIZE or MSDU Aggreg: %d, DELAY BOUND: %d, PHYRATE: %d, SPLUSBW: %f, "
                    "MEDIUM TIME: %d, ACCESSCAT: %d\n",
                    setwmm->actions.addts.dialog_token, setwmm->actions.addts.tspec.tsinfo.TID,
                    setwmm->actions.addts.tspec.tsinfo.direction, setwmm->actions.addts.tspec.tsinfo.PSB,
                    setwmm->actions.addts.tspec.tsinfo.UP, setwmm->actions.addts.tspec.tsinfo.infoAck,
                    setwmm->actions.addts.tspec.tsinfo.bstSzDef, setwmm->actions.addts.tspec.Fixed,
                    setwmm->actions.addts.tspec.size, setwmm->actions.addts.tspec.maxsize,
                    setwmm->actions.addts.tspec.min_srvc, setwmm->actions.addts.tspec.max_srvc,
                    setwmm->actions.addts.tspec.inactivity, setwmm->actions.addts.tspec.suspension,
                    setwmm->actions.addts.tspec.srvc_strt_tim, setwmm->actions.addts.tspec.mindatarate,
                    setwmm->actions.addts.tspec.meandatarate, setwmm->actions.addts.tspec.peakdatarate,
                    setwmm->actions.addts.tspec.burstsize, setwmm->actions.addts.tspec.delaybound,
                    setwmm->actions.addts.tspec.PHYrate, setwmm->actions.addts.tspec.sba,
                    setwmm->actions.addts.tspec.medium_time, setwmm->actions.addts.accesscat);

                // tspec should be set here.

                sret = system(gCmdStr);
            }
            else if (setwmm->action == WMMAC_DELTS)
            {
                // send del tspec
            }

            setwmmResp->status = STATUS_COMPLETE;
            break;

        case GROUP_WMMCONF:
            sprintf(gCmdStr, "iwconfig %s rts %d", ifname, setwmm->actions.config.rts_thr);

            sret = system(gCmdStr);
            sprintf(gCmdStr, "iwconfig %s frag %d", ifname, setwmm->actions.config.frag_thr);

            sret = system(gCmdStr);
            sprintf(gCmdStr, "iwpriv %s wmmcfg %d", ifname, setwmm->actions.config.wmm);

            sret               = system(gCmdStr);
            setwmmResp->status = STATUS_COMPLETE;
            break;

        default:
            DPRINT_ERR(WFA_ERR, "The group %d is not supported\n", setwmm->group);
            setwmmResp->status = STATUS_ERROR;
            break;
    }

    wfaEncodeTLV(WFA_STA_SET_WMM_RESP_TLV, 4, (BYTE *)setwmmResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
#endif

    return WFA_SUCCESS;
}

int wfaStaSendNeigReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *sendNeigReqResp = &gGenericResp;

    /*
     *  run your device to send NEIGREQ
     */

    sendNeigReqResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SEND_NEIGREQ_RESP_TLV, 4, (BYTE *)sendNeigReqResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSetEapFAST(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEapFAST_t *setFAST       = (caStaSetEapFAST_t *)caCmdBuf;
    char *ifname                     = setFAST->intf;
    dutCmdResponse_t *setEapFastResp = &gGenericResp;

#ifdef WFA_NEW_CLI_FORMAT
    sprintf(gCmdStr, "wfa_set_eapfast %s %s %s %s %s %s", ifname, setFAST->ssid, setFAST->username, setFAST->passwd,
            setFAST->pacFileName, setFAST->innerEAP);
    sret = system(gCmdStr);
#else

    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", ifname, setFAST->ssid);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 identity '\"%s\"'", ifname, setFAST->username);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 password '\"%s\"'", ifname, setFAST->passwd);
    sret = system(gCmdStr);

    if (strcasecmp(setFAST->keyMgmtType, "wpa2-sha256") == 0)
    {
    }
    else if (strcasecmp(setFAST->keyMgmtType, "wpa2-eap") == 0)
    {
    }
    else if (strcasecmp(setFAST->keyMgmtType, "wpa2-ft") == 0)
    {
    }
    else if (strcasecmp(setFAST->keyMgmtType, "wpa") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setFAST->keyMgmtType, "wpa2") == 0)
    {
        // take all and device to pick one which is supported.
    }
    else
    {
        // ??
    }
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 eap FAST", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 pac_file '\"%s/%s\"'", ifname, CERTIFICATES_PATH,
            setFAST->pacFileName);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 anonymous_identity '\"anonymous\"'", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 phase1 '\"fast_provisioning=1\"'", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 phase2 '\"auth=%s\"'", ifname, setFAST->innerEAP);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", ifname);
    sret = system(gCmdStr);
#endif

    setEapFastResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_EAPFAST_RESP_TLV, 4, (BYTE *)setEapFastResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSetEapAKA(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetEapAKA_t *setAKA        = (caStaSetEapAKA_t *)caCmdBuf;
    char *ifname                    = setAKA->intf;
    dutCmdResponse_t *setEapAkaResp = &gGenericResp;

#ifdef WFA_NEW_CLI_FORMAT
    sprintf(gCmdStr, "wfa_set_eapaka %s %s %s %s", ifname, setAKA->ssid, setAKA->username, setAKA->passwd);
    sret = system(gCmdStr);
#else

    sprintf(gCmdStr, "wpa_cli -i %s disable_network 0", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 ssid '\"%s\"'", ifname, setAKA->ssid);
    sret = system(gCmdStr);

    if (strcasecmp(setAKA->keyMgmtType, "wpa2-sha256") == 0)
    {
    }
    else if (strcasecmp(setAKA->keyMgmtType, "wpa2-eap") == 0)
    {
    }
    else if (strcasecmp(setAKA->keyMgmtType, "wpa2-ft") == 0)
    {
    }
    else if (strcasecmp(setAKA->keyMgmtType, "wpa") == 0)
    {
        sprintf(gCmdStr, "wpa_cli -i %s set_network 0 key_mgmt WPA-EAP", ifname);
    }
    else if (strcasecmp(setAKA->keyMgmtType, "wpa2") == 0)
    {
        // take all and device to pick one which is supported.
    }
    else
    {
        // ??
    }
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 proto WPA2", ifname);
    sret = system(gCmdStr);
    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 proto CCMP", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 eap AKA", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 phase1 \"result_ind=1\"", ifname);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 identity '\"%s\"'", ifname, setAKA->username);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s set_network 0 password '\"%s\"'", ifname, setAKA->passwd);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "wpa_cli -i %s enable_network 0", ifname);
    sret = system(gCmdStr);
#endif

    setEapAkaResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_EAPAKA_RESP_TLV, 4, (BYTE *)setEapAkaResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSetSystime(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaSetSystime_t *systime       = (caStaSetSystime_t *)caCmdBuf;
    dutCmdResponse_t *setSystimeResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaSetSystime ...\n");

    sprintf(gCmdStr, "date %d-%d-%d", systime->month, systime->date, systime->year);
    sret = system(gCmdStr);

    sprintf(gCmdStr, "time %d:%d:%d", systime->hours, systime->minutes, systime->seconds);
    sret = system(gCmdStr);

    setSystimeResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_SYSTIME_RESP_TLV, 4, (BYTE *)setSystimeResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaPresetParams(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *PresetParamsResp    = &gGenericResp;
    caStaPresetParameters_t *presetParams = (caStaPresetParameters_t *)caCmdBuf;
    int ret                               = -WM_FAIL;

    DPRINT_INFO(WFA_OUT, "Inside wfaStaPresetParameters function ...\n");

    ret = wlan_disconnect();
    sleep(2);

    if (presetParams->program == PROG_TYPE_MBO || presetParams->program == PROG_TYPE_HE ||
        presetParams->program == PROG_TYPE_VHT5G)
    {
        wlan_remove_all_network_profiles();
#if !CONFIG_WPA_SUPP
#if CONFIG_DRIVER_MBO

        if (presetParams->Ch_Op_Class_Flag)
        {
            if (presetParams->Ch_Pref)
            {
                DPRINT_INFO(WFA_OUT, "\n Setting prefer channel parameters\n");
                wlan_mbo_peferch_cfg(Ch_Pref_Num_0, Ch_Pref_0, presetParams->Ch_Pref_Num, presetParams->Ch_Pref);
            }
            else
            {
                Ch_Op_Class_0    = presetParams->Ch_Op_Class;
                Ch_Pref_Num_0    = presetParams->Ch_Pref_Num;
                Ch_Pref_0        = presetParams->Ch_Pref;
                Ch_Reason_Code_0 = presetParams->Ch_Reason_Code;
            }
        }
#endif
#endif
    }

    if (ret != WM_SUCCESS)
    {
        PresetParamsResp->status = STATUS_ERROR;

        wfaEncodeTLV(WFA_STA_PRESET_PARAMETERS_RESP_TLV, 4, (BYTE *)PresetParamsResp, respBuf);

        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Unable to reset defaults");
        return WFA_FAILURE;
    }

    PresetParamsResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_PRESET_PARAMETERS_RESP_TLV, 4, (BYTE *)PresetParamsResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSet11n(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *v11nParamsResp = &gGenericResp;

    v11nParamsResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_11N_RESP_TLV, 4, (BYTE *)v11nParamsResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}
int wfaStaSetWireless(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *staWirelessResp  = &gGenericResp;
    caStaSetWireless_t *staSetWireless = (caStaSetWireless_t *)caCmdBuf;
    struct setWirelessHE *heParams     = (struct setWirelessHE *)&staSetWireless->progs.he;
    /** Antenna Mode */
    uint32_t ant_mode;
    /** Evaluate Time */
    uint16_t evaluate_time;
    /** Current antenna*/
    uint16_t current_antenna;

    DPRINT_INFO(WFA_OUT, "\nInside wfaStaSetWireless function ...\n");

    (void)wlan_get_antcfg(&ant_mode, &evaluate_time, &current_antenna);

    NSS = ant_mode;

#if CONFIG_11AX
    if (staSetWireless->prog == PROG_TYPE_HE)
    {
        HE = MLAN_RATE_FORMAT_HE;
    }
#endif

    if (heParams->he_smps_flag)
    {
        DPRINT_INFO(WFA_OUT, "Ashok:Enable SMPS");
    }
    if (heParams->width_flag)
    {
        DPRINT_INFO(WFA_OUT, "Ashok: Change Bandwidth");
    }
    if ((heParams->OMControl_flag || heParams->UPH_flag) &&
        (heParams->OMControl == WFA_ENABLED || heParams->UPH == WFA_ENABLED))
    {
        DPRINT_INFO(WFA_OUT, "Ashok: OM-Control and UPH field settings logic if required");
    }
    if (heParams->ADDBAReq_BufSize_flag)
    {
        if (!strcasecmp(heParams->ADDBAReq_BufSize, "gt64"))
            DPRINT_INFO(WFA_OUT, "Ashok: ENABLE SUPER BA-TX ");
    }

    if (heParams->ADDBAResp_BufSize_flag)
    {
        if (!strcasecmp(heParams->ADDBAResp_BufSize, "gt64"))
            DPRINT_INFO(WFA_OUT, "Ashok:ENABLE SUPER BA-RX ");
    }

    if (heParams->mcs_fixedrate_flag)
    {
        if (!strcasecmp(heParams->mcs_fixedrate, "7"))
            MCSINDEX = 7;
    }

    if (heParams->amsdu_flag)
    {
        if (heParams->amsdu == WFA_ENABLED)
        {
            DPRINT_INFO(WFA_OUT, "Ashok:ENABLE AMSDU ");
        }
    }

    if (heParams->ldpc_flag)
    {
        if (heParams->ldpc == WFA_ENABLED)
        {
            coding = 1;
        }
    }
    if (heParams->bcc_flag)
    {
        if (heParams->bcc == WFA_ENABLED)
        {
            coding = 0;
        }
    }

    if ((heParams->txsp_stream_flag) || (heParams->rxsp_stream_flag))
    {
        if ((!strcasecmp(heParams->txsp_stream, "1SS")) || (!strcasecmp(heParams->rxsp_stream, "1SS")))
        {
            DPRINT_INFO(WFA_OUT, "Ashok:SET TX-NSS =1 and RX-NSS=1");
        }
        else if ((!strcasecmp(heParams->txsp_stream, "2SS")) || (!strcasecmp(heParams->rxsp_stream, "2SS")))
        {
            DPRINT_INFO(WFA_OUT, "Ashok:SET TX-NSS =2 and RX-NSS=2");
        }
    }

    staWirelessResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_WIRELESS_RESP_TLV, 4, (BYTE *)staWirelessResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSendADDBA(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *staSendADDBAResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Inside wfaStaSendADDBA function ...\n");

    staSendADDBAResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_SET_SEND_ADDBA_RESP_TLV, 4, (BYTE *)staSendADDBAResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaStaSetRIFS(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *staSetRIFSResp = &gGenericResp;

    wfaEncodeTLV(WFA_STA_SET_RIFS_TEST_RESP_TLV, 4, (BYTE *)staSetRIFSResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaSendCoExistMGMT(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *staSendMGMTResp = &gGenericResp;

    wfaEncodeTLV(WFA_STA_SEND_COEXIST_MGMT_RESP_TLV, 4, (BYTE *)staSendMGMTResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaResetDefault(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaResetDefault_t *reset  = (caStaResetDefault_t *)caCmdBuf;
    dutCmdResponse_t *ResetResp = &gGenericResp;

    int ret;

    DPRINT_INFO(WFA_OUT, "Inside wfaStaResetDefault function ...\n");

    ret = wlan_disconnect();

    if ((!strcasecmp(reset->prog, "HE")) || (!strcasecmp(reset->prog, "MBO")))
        wlan_remove_all_network_profiles();

    sleep(5);

#if CONFIG_11AX
    if (!strcasecmp(reset->prog, "HE"))
    {
        DPRINT_INFO(WFA_OUT, "\n Info: HE supported SoC, setting 11ax_tol_time to 8 secs\n");
        (void)wlan_set_11ax_tol_time(8);
    }
#endif
    if (!strcasecmp(reset->prog, "MBO"))
    {
#if !CONFIG_WPA_SUPP
        DPRINT_INFO(WFA_OUT, "\n Info: Configuring MBO parameters for Embedded supplicant\n");
#if CONFIG_DRIVER_MBO

        (void)wlan_host_mbo_cfg(1);
#endif
#if CONFIG_11K
        (void)wlan_host_11k_cfg(1);
#endif
#endif
#if CONFIG_WPA_SUPP
        DPRINT_INFO(WFA_OUT, "\n Info: Configuring MBO parameters for Open supplicant\n");
#if CONFIG_11K
        (void)wlan_host_11k_cfg(1);
#endif
#if CONFIG_11AX
        (void)wlan_mbo_set_oce(1);
        (void)wlan_mbo_set_cell_capa(1);
#endif
#endif
    }

    if (ret != WM_SUCCESS)
    {
        ResetResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_RESET_DEFAULT_RESP_TLV, 4, (BYTE *)ResetResp, respBuf);

        *respLen = WFA_TLV_HDR_LEN + 4;

        DPRINT_ERR(WFA_ERR, "Unable to reset defaults, ret => %d\n", ret);
        return WFA_FAILURE;
    }

    /*Reset used values of structure nxp_dut_info*/
    HE       = 0;
    MCSINDEX = 0;
    NSS      = 0;
    width    = 0;

    ResetResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_RESET_DEFAULT_RESP_TLV, 4, (BYTE *)ResetResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaTestBedCmd(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *staCmdResp = &gGenericResp;

    wfaEncodeTLV(WFA_STA_DISCONNECT_RESP_TLV, 4, (BYTE *)staCmdResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * This is used to send a frame or action frame
 */
int wfaStaDevSendFrame(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCommand_t *cmd             = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *devSendResp = &gGenericResp;
    caStaDevSendFrame_t *sf       = &cmd->cmdsu.sf;
    // int ret;
    // FILE *fp;
    char file_path[128];

    memset(file_path, 0, sizeof(file_path));
    //	sprintf(file_path, "%s/pingResult.txt", DATA_PATH_PREFIX);

    switch (sf->program)
    {
        case PROG_TYPE_MBO:
        {
            MBO_Frame_t *mbo = &sf->frameType.mbo;
            char list[8]     = {0};
            if (mbo->cand_list)
                strcpy(list, "list");
            if (mbo->BTMQuery)
            {
            }
            if (mbo->BTMReq)
            {
            }
            if (mbo->BcnRptReq)
            {
            }
            if (mbo->WNM_Notify)
            {
            }

            if (mbo->ANQPQuery)
            {
                if (mbo->NeighborReportReq)
                {
                }
                else if (mbo->QueryListWithCellPref)
                {
                }
            }
        }
        case PROG_TYPE_PMF:
        {
            pmfFrame_t *pmf = &sf->frameType.pmf;
            switch (pmf->eFrameName)
            {
                case PMF_TYPE_DISASSOC:
                {
                }
                break;
                case PMF_TYPE_DEAUTH:
                {
                }
                break;
                case PMF_TYPE_SAQUERY:
                {
                }
                break;
                case PMF_TYPE_AUTH:
                {
                }
                break;
                case PMF_TYPE_ASSOCREQ:
                {
                }
                break;
                case PMF_TYPE_REASSOCREQ:
                {
                }
                break;
            }
        }
        break;
        case PROG_TYPE_TDLS:
        {
        }
        break;
        case PROG_TYPE_VENT:
        {
            ventFrame_t *vent = &sf->frameType.vent;
            switch (vent->type)
            {
                case VENT_TYPE_NEIGREQ:
                    break;
                case VENT_TYPE_TRANSMGMT:
                    break;
            }
        }
        case PROG_TYPE_WFD:
        {
            wfdFrame_t *wfd = &sf->frameType.wfd;
            switch (wfd->eframe)
            {
                case WFD_FRAME_PRBREQ:
                {
                    /** send probe req */
                }
                break;

                case WFD_FRAME_PRBREQ_TDLS_REQ:
                {
                    /** send tunneled tdls probe req  */
                }
                break;

                case WFD_FRAME_11V_TIMING_MSR_REQ:
                {
                    /** send 11v timing measurement request */
                }
                break;

                case WFD_FRAME_RTSP:
                {
                    /** send WFD RTSP messages
         fetch the type of RTSP message and send it. */
                    switch (wfd->eRtspMsgType)
                    {
                        case WFD_RTSP_PAUSE:

                            break;
                        case WFD_RTSP_PLAY:

                            break;
                        case WFD_RTSP_TEARDOWN:

                            break;
                        case WFD_RTSP_TRIG_PAUSE:

                            break;
                        case WFD_RTSP_TRIG_PLAY:

                            break;
                        case WFD_RTSP_TRIG_TEARDOWN:

                            break;
                        case WFD_RTSP_SET_PARAMETER:
                            if (wfd->eSetParams == WFD_CAP_UIBC_KEYBOARD)
                            {
                                /** send RTSP SET PARAMETER message for UIBC keyboard */
                            }
                            if (wfd->eSetParams == WFD_CAP_UIBC_MOUSE)
                            {
                                /** send RTSP SET PARAMETER message for UIBC Mouse */
                            }
                            else if (wfd->eSetParams == WFD_CAP_RE_NEGO)
                            {
                                /** send RTSP SET PARAMETER message Capability re-negotiation */
                            }
                            else if (wfd->eSetParams == WFD_STANDBY)
                            {
                                /** send RTSP SET PARAMETER message for standby */
                            }
                            else if (wfd->eSetParams == WFD_UIBC_SETTINGS_ENABLE)
                            {
                                /** send RTSP SET PARAMETER message for UIBC settings enable */
                            }
                            else if (wfd->eSetParams == WFD_UIBC_SETTINGS_DISABLE)
                            {
                                /** send RTSP SET PARAMETER message for UIBC settings disable */
                            }
                            else if (wfd->eSetParams == WFD_ROUTE_AUDIO)
                            {
                                /** send RTSP SET PARAMETER message for route audio */
                            }
                            else if (wfd->eSetParams == WFD_3D_VIDEOPARAM)
                            {
                                /** send RTSP SET PARAMETER message for 3D video parameters */
                            }
                            else if (wfd->eSetParams == WFD_2D_VIDEOPARAM)
                            {
                                /** send RTSP SET PARAMETER message for 2D video parameters */
                            }
                            break;
                    }
                }
                break;
            }
        }
        case PROG_TYPE_VHT5G:
        {
            vht5gFrame_t *vht5g = &sf->frameType.vht5g;
            if (strcasecmp(vht5g->frameName, "Op_md_notif_frm") == 0)
            {
                // int width = vht5g->para.opt_md.channel_width;
                // int nss   = vht5g->para.opt_md.nss;
                // set_vht_nss_config(sta_interface,nss,width);
            }
            break;
        }

        case PROG_TYPE_GEN:
        {
            /** General frames */
        }

        case PROG_TYPE_HS2:
        {
            HS2_Frame_t *hs2 = &sf->frameType.hs2;
            if (hs2->ARPREPLY == 1)
            {
            }
            else if (hs2->DLSrequest)
            {
                DPRINT_INFO(WFA_OUT, "HS2 DLSrequest :%d", hs2->DLSrequest);
            }
            else if (hs2->neighSolicitReq)
            {
                // char ipv6addr[WFA_IP_V6_ADDR_STR_LEN];
            }
            else if (hs2->arpProbe)
            {
                // char ipv4addr[16] = {0};
            }
            else if (hs2->arpAnnounce)
            {
                // char ipv4addr[16];
            }
            else
            {
            }
        }
    }
    devSendResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_DEV_SEND_FRAME_RESP_TLV, 4, (BYTE *)devSendResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

/*
 * This is used to set a temporary MAC address of an interface
 */
int wfaStaSetMacAddr(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    wASSERT(0);

    // Uncomment it if needed
    // dutCommand_t *cmd = (dutCommand_t *)caCmdBuf;
    // char *ifname = cmd->intf;
    dutCmdResponse_t *staCmdResp = &gGenericResp;
    // Uncomment it if needed
    // char *macaddr = &cmd->cmdsu.macaddr[0];

    wfaEncodeTLV(WFA_STA_SET_MAC_ADDRESS_RESP_TLV, 4, (BYTE *)staCmdResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaStaDisconnect(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *disc = (dutCommand_t *)caCmdBuf;
    // char *intf = disc->intf;
    dutCmdResponse_t *staDiscResp = &gGenericResp;

    // stop the supplicant

    (void)wlan_disconnect();

    staDiscResp->status = STATUS_COMPLETE;

    wfaEncodeTLV(WFA_STA_DISCONNECT_RESP_TLV, 4, (BYTE *)staDiscResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/* Execute CLI, read the status from Environment variable */
int wfaExecuteCLI(char *CLI)
{
    char *retstr;

    sret = system(CLI);

    retstr = getenv("WFA_CLI_STATUS");
    PRINTF("cli status %s\n", retstr);
    return atoi(retstr);
}

/* Supporting Functions */

void wfaSendPing(tgPingStart_t *staPing, float *interval, int streamid)
{
    // tgStream_t *myStream;
    int tos = -1;
//    char cmdStr[256];
//    char *addr = staPing->dipaddr;
#ifdef WFA_PC_CONSOLE
    char addr[40];
    char bflag[] = "-b";
    char *tmpstr;
    int inum = 0;
#else
//    char bflag[] = "  ";
#endif
    uint16_t size    = PING_DEFAULT_SIZE;
    uint16_t count   = PING_DEFAULT_COUNT;
    uint32_t timeout = PING_DEFAULT_TIMEOUT_SEC;
    int intval       = PING_INTERVAL / staPing->frameRate;


    // totalpkts = (int)(staPing->duration * staPing->frameRate);

#ifdef WFA_PC_CONSOLE

    DPRINT_INFO(WFA_OUT, "\r\nwfa_cs.c wfaSendPing CS : The Stream ID is %d", streamid);

    strcpy(addr, staPing->dipaddr);
    DPRINT_INFO(WFA_OUT, "\r\nCS :the addr is %s ", addr);
    DPRINT_INFO(WFA_OUT, "\r\nCS :Inside the WFA_PC_CONSLE BLOCK");
    DPRINT_INFO(WFA_OUT, "\r\nCS :the addr is %s ", addr);
    if (staPing->iptype == 2)
    {
        memset(bflag, 0, strlen(bflag));
    }
    else
    {
        tmpstr = strtok(addr, ".");
        inum   = atoi(tmpstr);

        DPRINT_INFO(WFA_OUT, "interval %f\n", *interval);

        if (inum >= 224 && inum <= 239) // multicast
        {
        }
        else // if not MC, check if it is BC address
        {
            DPRINT_INFO(WFA_OUT, "\nCS :Inside the BC address BLOCK inum %d", inum);
            strtok(NULL, ".");
            // strtok(NULL, ".");
            tmpstr = strtok(NULL, ".");
            inum   = atoi(tmpstr);
            DPRINT_INFO(WFA_OUT, "\nCS : The string is %s", tmpstr);
            if (inum != 255)
                memset(bflag, 0, strlen(bflag));
        }
    }
#endif
    if (staPing->dscp >= 0)
    {
        tos = convertDscpToTos(staPing->dscp);
        if (tos < 0)
            DPRINT_INFO(WFA_OUT, "\r\nwfaSendPing invalid tos converted, dscp=%d\r\n", staPing->dscp);
    }

    count = staPing->duration * staPing->frameRate;
    size  = staPing->frameSize;

    return_flag = ping(count, intval, size, timeout, &staPing->dipaddr[0]);

#if 0
    if (staPing->iptype == 2)
    {
        if ( tos>0)
            sprintf(cmdStr, "echo streamid=%i > /tmp/spout_%d.txt;wfaping6.sh %s %s -i %f -c %i -Q %d -s %i -q >> /tmp/spout_%d.txt 2>/dev/null",
                    streamid,streamid,bflag, staPing->dipaddr, *interval, totalpkts, tos,  staPing->frameSize,streamid);
        else
            sprintf(cmdStr, "echo streamid=%i > /tmp/spout_%d.txt;wfaping6.sh %s %s -i %f -c %i -s %i -q >> /tmp/spout_%d.txt 2>/dev/null",
                    streamid,streamid,bflag, staPing->dipaddr, *interval, totalpkts, staPing->frameSize,streamid);
        sret = system(cmdStr);
        PRINTF("\nCS : The command string is %s",cmdStr);
    }
    else
    {
        if (tos > 0)
            sprintf(cmdStr, "echo streamid=%i > /tmp/spout_%d.txt;wfaping.sh %s %s -i %f -c %i  -Q %d -s %i -q >> /tmp/spout_%d.txt 2>/dev/null",
                    streamid,streamid,bflag, staPing->dipaddr, *interval, totalpkts, tos, staPing->frameSize,streamid);
        else
            sprintf(cmdStr, "echo streamid=%i > /tmp/spout_%d.txt;wfaping.sh %s %s -i %f -c %i -s %i -q >> /tmp/spout_%d.txt 2>/dev/null",
                    streamid,streamid,bflag, staPing->dipaddr, *interval, totalpkts, staPing->frameSize,streamid);
        sret = system(cmdStr);
        PRINTF("\nCS : The command string is %s",cmdStr);
    }
    sprintf(cmdStr, "updatepid.sh /tmp/spout_%d.txt",streamid);
#endif

    //    sret = system(cmdStr);
    //    PRINTF("\nCS : The command string is %s",cmdStr);
}

int wfaStopPing(dutCmdResponse_t *stpResp, int streamid)
{
#if 0
    sprintf(cmdStr, "getpid.sh /tmp/spout_%d.txt /tmp/pid.txt",streamid);
    sret = system(cmdStr);

    PRINTF("\nCS : The command string is %s",cmdStr);

    sret = system("stoping.sh /tmp/pid.txt ; sleep 2");

    sprintf(cmdStr, "getpstats.sh /tmp/spout_%d.txt",streamid);
    sret = system(cmdStr);

    PRINTF("\nCS : The command string is %s",cmdStr);

    tmpfile = fopen("/tmp/stpsta.txt", "r+");

    if(tmpfile == NULL)
    {
        return WFA_FAILURE;
    }

    if(fscanf(tmpfile, "%s", strout) != EOF)
    {
        if(*strout == '\0')
        {
            stpResp->cmdru.pingStp.sendCnt = 0;
        }

        else
            stpResp->cmdru.pingStp.sendCnt = atoi(strout);
    }

    PRINTF("\nwfaStopPing after scan sent count %i\n", stpResp->cmdru.pingStp.sendCnt);


    if(fscanf(tmpfile, "%s", strout) != EOF)
    {
        if(*strout == '\0')
        {
            stpResp->cmdru.pingStp.repliedCnt = 0;
        }
        else
            stpResp->cmdru.pingStp.repliedCnt = atoi(strout);
    }
    PRINTF("wfaStopPing after scan replied count %i\n", stpResp->cmdru.pingStp.repliedCnt);

    fclose(tmpfile);
#endif
    ping_stats(&stpResp->cmdru.pingStp.sendCnt, &stpResp->cmdru.pingStp.repliedCnt);

    return WFA_SUCCESS;
}

/*
 * wfaStaGetP2pDevAddress():
 */
int wfaStaGetP2pDevAddress(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* dutCommand_t *getInfo = (dutCommand_t *)caCmdBuf; */

    PRINTF("\n Entry wfaStaGetP2pDevAddress... ");

    // Fetch the device ID and store into infoResp->cmdru.devid
    // strcpy(infoResp->cmdru.devid, str);
    strcpy(&infoResp.cmdru.devid[0], "ABCDEFGH");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_GET_DEV_ADDRESS_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSetP2p():
 */
int wfaStaSetP2p(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaSetP2p_t *getStaSetP2p = (caStaSetP2p_t *)caCmdBuf; uncomment and use it*/

    PRINTF("\n Entry wfaStaSetP2p... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SETP2P_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}
/*
 * wfaStaP2pConnect():
 */
int wfaStaP2pConnect(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaP2pConnect_t *getStaP2pConnect = (caStaP2pConnect_t *)caCmdBuf; uncomment and use it */

    PRINTF("\n Entry wfaStaP2pConnect... ");

    // Implement the function and does not return anything.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_CONNECT_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaStartAutoGo():
 */
int wfaStaStartAutoGo(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    // caStaStartAutoGo_t *getStaStartAutoGo = (caStaStartAutoGo_t *)caCmdBuf;

    PRINTF("\n Entry wfaStaStartAutoGo... ");

    // Fetch the group ID and store into 	infoResp->cmdru.grpid
    strcpy(&infoResp.cmdru.grpid[0], "ABCDEFGH");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_START_AUTO_GO_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaP2pStartGrpFormation():
 */
int wfaStaP2pStartGrpFormation(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;

    PRINTF("\n Entry wfaStaP2pStartGrpFormation... ");

    strcpy(infoResp.cmdru.grpFormInfo.result, "CLIENT");
    strcpy(infoResp.cmdru.grpFormInfo.grpId, "AA:BB:CC:DD:EE:FF_DIRECT-SSID");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_START_GRP_FORMATION_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaP2pDissolve():
 */
int wfaStaP2pDissolve(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;

    PRINTF("\n Entry wfaStaP2pDissolve... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_DISSOLVE_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSendP2pInvReq():
 */
int wfaStaSendP2pInvReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaSendP2pInvReq_t *getStaP2pInvReq= (caStaSendP2pInvReq_t *)caCmdBuf; */

    PRINTF("\n Entry wfaStaSendP2pInvReq... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SEND_INV_REQ_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaAcceptP2pInvReq():
 */
int wfaStaAcceptP2pInvReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* uncomment and use it
     * caStaAcceptP2pInvReq_t *getStaP2pInvReq= (caStaAcceptP2pInvReq_t *)caCmdBuf;
     */

    PRINTF("\n Entry wfaStaAcceptP2pInvReq... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_ACCEPT_INV_REQ_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSendP2pProvDisReq():
 */
int wfaStaSendP2pProvDisReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* uncomment and use it
     * caStaSendP2pProvDisReq_t *getStaP2pProvDisReq= (caStaSendP2pProvDisReq_t *)caCmdBuf;
     */

    PRINTF("\n Entry wfaStaSendP2pProvDisReq... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SEND_PROV_DIS_REQ_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSetWpsPbc():
 */
int wfaStaSetWpsPbc(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* uncomment and use it
     * caStaSetWpsPbc_t *getStaSetWpsPbc= (caStaSetWpsPbc_t *)caCmdBuf;
     */

    PRINTF("\n Entry wfaStaSetWpsPbc... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_WPS_SETWPS_PBC_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaWpsReadPin():
 */
int wfaStaWpsReadPin(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* uncomment and use it
     * caStaWpsReadPin_t *getStaWpsReadPin= (caStaWpsReadPin_t *)caCmdBuf;
     */

    PRINTF("\n Entry wfaStaWpsReadPin... ");

    // Fetch the device PIN and put in 	infoResp->cmdru.wpsPin
    // strcpy(infoResp->cmdru.wpsPin, "12345678");
    strcpy(&infoResp.cmdru.wpsPin[0], "1234456");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_WPS_READ_PIN_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaWpsReadLabel():
 */
int wfaStaWpsReadLabel(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;

    PRINTF("\n Entry wfaStaWpsReadLabel... ");

    // Fetch the device Label and put in	infoResp->cmdru.wpsPin
    // strcpy(infoResp->cmdru.wpsPin, "12345678");
    strcpy(&infoResp.cmdru.wpsPin[0], "1234456");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_WPS_READ_PIN_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaWpsEnterPin():
 */
int wfaStaWpsEnterPin(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* uncomment and use it
     * caStaWpsEnterPin_t *getStaWpsEnterPin= (caStaWpsEnterPin_t *)caCmdBuf;
     */

    PRINTF("\n Entry wfaStaWpsEnterPin... ");

    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_WPS_ENTER_PIN_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaGetPsk():
 */
int wfaStaGetPsk(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaGetPsk_t *getStaGetPsk= (caStaGetPsk_t *)caCmdBuf; uncomment and use it */

    PRINTF("\n Entry wfaStaGetPsk... ");

    // Fetch the device PP and SSID  and put in 	infoResp->cmdru.pskInfo
    strcpy(&infoResp.cmdru.pskInfo.passPhrase[0], "1234456");
    strcpy(&infoResp.cmdru.pskInfo.ssid[0], "WIFI_DIRECT");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_GET_PSK_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaP2pReset():
 */
int wfaStaP2pReset(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* dutCommand_t *getStaP2pReset= (dutCommand_t *)caCmdBuf; */

    PRINTF("\n Entry wfaStaP2pReset... ");
    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_RESET_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaGetP2pIpConfig():
 */
int wfaStaGetP2pIpConfig(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaGetP2pIpConfig_t *staGetP2pIpConfig= (caStaGetP2pIpConfig_t *)caCmdBuf; */

    caStaGetIpConfigResp_t *ifinfo = &(infoResp.cmdru.getIfconfig);

    PRINTF("\n Entry wfaStaGetP2pIpConfig... ");

    ifinfo->isDhcp = 0;
    strcpy(&(ifinfo->ipaddr[0]), "192.165.100.111");
    strcpy(&(ifinfo->mask[0]), "255.255.255.0");
    strcpy(&(ifinfo->dns[0][0]), "192.165.100.1");
    strcpy(&(ifinfo->mac[0]), "ba:ba:ba:ba:ba:ba");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_GET_IP_CONFIG_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSendServiceDiscoveryReq():
 */
int wfaStaSendServiceDiscoveryReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;

    PRINTF("\n Entry wfaStaSendServiceDiscoveryReq... ");
    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SEND_SERVICE_DISCOVERY_REQ_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSendP2pPresenceReq():
 */
int wfaStaSendP2pPresenceReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SEND_PRESENCE_REQ_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSetSleepReq():
 */
int wfaStaSetSleepReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaSetSleep_t *staSetSleepReq= (caStaSetSleep_t *)caCmdBuf; */

    PRINTF("\n Entry wfaStaSetSleepReq... ");
    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SET_SLEEP_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaSetOpportunisticPsReq():
 */
int wfaStaSetOpportunisticPsReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;

    PRINTF("\n Entry wfaStaSetOpportunisticPsReq... ");
    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_SET_OPPORTUNISTIC_PS_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}
/*
 * wfaStaAddArpTableEntry():
 */
int wfaStaAddArpTableEntry(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaAddARPTableEntry_t *staAddARPTableEntry= (caStaAddARPTableEntry_t *)caCmdBuf; uncomment and use it */

    PRINTF("\n Entry wfastaAddARPTableEntry... ");
    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_ADD_ARP_TABLE_ENTRY_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaBlockICMPResponse():
 */
int wfaStaBlockICMPResponse(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    /* caStaBlockICMPResponse_t *staAddARPTableEntry= (caStaBlockICMPResponse_t *)caCmdBuf; uncomment and use it */

    PRINTF("\n Entry wfaStaBlockICMPResponse... ");
    // Implement the function and this does not return any thing back.

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_P2P_BLOCK_ICMP_RESPONSE_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaSetRadio():
 */

int wfaStaSetRadio(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCommand_t *setRadio       = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staCmdResp = &gGenericResp;
    caStaSetRadio_t *sr          = &setRadio->cmdsu.sr;

    if (sr->mode == WFA_OFF)
    {
        // turn radio off
    }
    else
    {
        // always turn the radio on
    }

    staCmdResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_RADIO_RESP_TLV, 4, (BYTE *)staCmdResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaSetRFeature():
 */

int wfaStaSetRFeature(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *caResp = &gGenericResp;
    //	dutCommand_t *cmd = (dutCommand_t *)caCmdBuf;
    //	caStaRFeat_t *rfeat = &cmd->cmdsu.rfeat;
    caStaRFeat_t *rfeat = (caStaRFeat_t *)caCmdBuf;

#if CONFIG_11AX
    uint8_t rxNss, channelWidth, ulMuDisable, txNSTS, ulMuDataDisable;
#endif

    uint32_t ant_mode;
    /** Evaluate Time */
    uint16_t evaluate_time;
    /** Current antenna*/
    uint16_t current_antenna;
    wifi_ds_rate txrate;
    (void)memset(&txrate, 0, sizeof(wifi_ds_rate));

    DPRINT_INFO(WFA_OUT, "\nInside wfaStaSetrfeature function ...\n");

    (void)wlan_get_antcfg(&ant_mode, &evaluate_time, &current_antenna);

    if (rfeat->LTF_Flag && is_sta_connected())
    {
        txrate.sub_command = 0;
#if CONFIG_11AX
        if (!strcasecmp(rfeat->prog, "HE"))
            txrate.param.rate_cfg.rate_format = MLAN_RATE_FORMAT_HE;
#endif
        txrate.param.rate_cfg.rate_index = 7;
#if CONFIG_11AX
        txrate.param.rate_cfg.nss = ant_mode;
#endif
        if ((!strcasecmp(rfeat->LTF, "6.4")) && (!strcasecmp(rfeat->GI, "0.8")) && width == 0)
            txrate.param.rate_cfg.rate_setting = 0x2020;
        if ((!strcasecmp(rfeat->LTF, "6.4")) && (!strcasecmp(rfeat->GI, "1.6")) && width == 0)
            txrate.param.rate_cfg.rate_setting = 0x2040;
        if ((!strcasecmp(rfeat->LTF, "12.8")) && (!strcasecmp(rfeat->GI, "3.2")) && width == 0)
            txrate.param.rate_cfg.rate_setting = 0x2060;
        if ((!strcasecmp(rfeat->LTF, "6.4")) && (!strcasecmp(rfeat->GI, "0.8")) && width == 2)
            txrate.param.rate_cfg.rate_setting = 0x2228;
        if ((!strcasecmp(rfeat->LTF, "6.4")) && (!strcasecmp(rfeat->GI, "1.6")) && width == 2)
            txrate.param.rate_cfg.rate_setting = 0x2248;
        if ((!strcasecmp(rfeat->LTF, "12.8")) && (!strcasecmp(rfeat->GI, "3.2")) && width == 2)
            txrate.param.rate_cfg.rate_setting = 0x2268;

        (void)wifi_set_txratecfg(txrate, 0);
    }

#if CONFIG_11AX
    if (rfeat->transmitOMI_Flag)
    {
        rxNss           = rfeat->OMCtrl_RxNSS;
        channelWidth    = rfeat->OMCtrl_ChnlWidth;
        ulMuDisable     = rfeat->OMCtrl_ULMUDisable;
        txNSTS          = rfeat->OMCtrl_TxNSTS;
        ulMuDataDisable = rfeat->OMCtrl_ULMUDataDisable;

        int ret = wlan_send_debug_htc(8, 1, 1, rxNss, channelWidth, ulMuDisable, txNSTS, 0, 0, ulMuDataDisable);

        if (ret != WM_SUCCESS)
        {
            caResp->status = STATUS_ERROR;
            wfaEncodeTLV(WFA_STA_SET_SECURITY_RESP_TLV, 4, (BYTE *)caResp, respBuf);
            *respLen = WFA_TLV_HDR_LEN + 4;
            DPRINT_ERR(WFA_ERR, "\nFailed to set HTC parameter\n");
            return WFA_FAILURE;
        }
    }

    if (!strcasecmp(rfeat->prog, "MBO"))
    {
#if !CONFIG_WPA_SUPP
#if CONFIG_DRIVER_MBO

        if (rfeat->Ch_Op_Class_Flag)
        {
            if (rfeat->Ch_Pref)
            {
                DPRINT_INFO(WFA_OUT, "\n Setting prefer channel parameters\n");
                wlan_mbo_peferch_cfg(Ch_Pref_Num_0, Ch_Pref_0, rfeat->Ch_Pref_Num, rfeat->Ch_Pref);
            }
            else
            {
                Ch_Op_Class_0    = rfeat->Ch_Op_Class;
                Ch_Pref_Num_0    = rfeat->Ch_Pref_Num;
                Ch_Pref_0        = rfeat->Ch_Pref;
                Ch_Reason_Code_0 = rfeat->Ch_Reason_Code;
            }
        }
        if (!rfeat->Ch_Op_Class_Flag && rfeat->Ch_Pref_Flag)
        {
            DPRINT_INFO(WFA_OUT, "\n Clear prefer channel parameters\n");
            wlan_mbo_peferch_cfg(0, 0, 0, 0);
        }
#endif
#endif
    }
#endif

    caResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_RFEATURE_RESP_TLV, 4, (BYTE *)caResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

/*
 * wfaStaStartWfdConnection():
 */
int wfaStaStartWfdConnection(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    // caStaStartWfdConn_t *staStartWfdConn= (caStaStartWfdConn_t *)caCmdBuf; //uncomment and use it

    PRINTF("\n Entry wfaStaStartWfdConnection... ");

    // Fetch the GrpId and WFD session and return
    strcpy(&infoResp.cmdru.wfdConnInfo.wfdSessionId[0], "1234567890");
    strcpy(&infoResp.cmdru.wfdConnInfo.p2pGrpId[0], "WIFI_DISPLAY");
    strcpy(&infoResp.cmdru.wfdConnInfo.result[0], "GO");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_START_WFD_CONNECTION_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}
/*
 * wfaStaCliCommand():
 */

int wfaStaCliCommand(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    wASSERT(0);
#if 0
    char cmdName[32];
    char *pcmdStr=NULL, *str;
    int  st = 1;
    char CmdStr[WFA_CMD_STR_SZ];
    FILE *wfaCliFd;
    char wfaCliBuff[64];
    char retstr[256];
    int CmdReturnFlag =0;
    char tmp[256];
    FILE * sh_pipe;
    caStaCliCmdResp_t infoResp;

    PRINTF("\nEntry wfaStaCliCommand; command Received: %s\n",caCmdBuf);
    memcpy(cmdName, strtok_r((char *)caCmdBuf, ",", (char **)&pcmdStr), 32);
    sprintf(CmdStr, "%s",cmdName);

    for(;;)
    {
        // construct CLI standard cmd string
        str = strtok_r(NULL, ",", &pcmdStr);
        if(str == NULL || str[0] == '\0')
            break;
        else
        {
            sprintf(CmdStr, "%s /%s",CmdStr,str);
            str = strtok_r(NULL, ",", &pcmdStr);
            sprintf(CmdStr, "%s %s",CmdStr,str);
        }
    }
    // check the return process
    wfaCliFd=fopen("/etc/WfaEndpoint/wfa_cli.txt","r");
    if(wfaCliFd!= NULL)
    {
        while(fgets(wfaCliBuff, 64, wfaCliFd) != NULL)
        {
            //printf("\nLine read from CLI file : %s",wfaCliBuff);
            if(ferror(wfaCliFd))
                break;

            str=strtok(wfaCliBuff,"-");
            if(strcmp(str,cmdName) == 0)
            {
                str=strtok(NULL,",");
                if (str != NULL)
                {
                    if(strcmp(str,"TRUE") == 0)
                        CmdReturnFlag =1;
                }
                else
                    PRINTF("ERR wfa_cli.txt, inside line format not end with , or missing TRUE/FALSE\n");
                break;
            }
        }
        fclose(wfaCliFd);
    }
    else
    {
        PRINTF("/etc/WfaEndpoint/wfa_cli.txt is not exist\n");
        goto cleanup;
    }

    //printf("\n Command Return Flag : %d",CmdReturnFlag);
    memset(&retstr[0],'\0',255);
    memset(&tmp[0],'\0',255);
    sprintf(gCmdStr, "%s",  CmdStr);
    PRINTF("\nCLI Command -- %s\n", gCmdStr);

    sh_pipe = popen(gCmdStr,"r");
    if(!sh_pipe)
    {
        PRINTF ("Error in opening pipe\n");
        goto cleanup;
    }

    sleep(5);
    //tmp_val=getdelim(&retstr,255,"\n",sh_pipe);
    if (fgets(&retstr[0], 255, sh_pipe) == NULL)
    {
        PRINTF("Getting NULL string in popen return\n");
        goto cleanup;
    }
    else
        PRINTF("popen return str=%s\n",retstr);

    sleep(2);
    if(pclose(sh_pipe) == -1)
    {
        PRINTF("Error in closing shell cmd pipe\n");
        goto cleanup;
    }
    sleep(2);

    // find status first in output
    str = strtok_r((char *)retstr, "-", (char **)&pcmdStr);
    if (str != NULL)
    {
        memset(tmp, 0, 10);
        memcpy(tmp, str,  2);
        PRINTF("cli status=%s\n",tmp);
        if(strlen(tmp) > 0)
            st = atoi(tmp);
        else PRINTF("Missing status code\n");
    }
    else
    {
        PRINTF("wfaStaCliCommand no return code found\n");
    }
    infoResp.resFlag=CmdReturnFlag;

cleanup:

    switch(st)
    {
    case 0:
        infoResp.status = STATUS_COMPLETE;
        if (CmdReturnFlag)
        {
            if((pcmdStr != NULL) && (strlen(pcmdStr) > 0) )
            {
                memset(&(infoResp.result[0]),'\0',WFA_CLI_CMD_RESP_LEN-1);
                strncpy(&infoResp.result[0], pcmdStr ,(strlen(pcmdStr) < WFA_CLI_CMD_RESP_LEN ) ? strlen(pcmdStr) : (WFA_CLI_CMD_RESP_LEN-2) );
                PRINTF("Return CLI result string to CA=%s\n", &(infoResp.result[0]));
            }
            else
            {
                strcpy(&infoResp.result[0], "No return string found\n");
            }
        }
        break;
    case 1:
        infoResp.status = STATUS_ERROR;
        break;
    case 2:
        infoResp.status = STATUS_INVALID;
        break;
    }

    wfaEncodeTLV(WFA_STA_CLI_CMD_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    PRINTF("Exit from wfaStaCliCommand\n");
#endif
    return TRUE;
}
/*
 * wfaStaConnectGoStartWfd():
 */

int wfaStaConnectGoStartWfd(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    //  caStaConnectGoStartWfd_t *staConnecGoStartWfd= (caStaConnectGoStartWfd_t *)caCmdBuf; //uncomment and use it

    PRINTF("\n Entry wfaStaConnectGoStartWfd... ");

    // connect the specified GO and then establish the wfd session

    // Fetch WFD session and return
    strcpy(&infoResp.cmdru.wfdConnInfo.wfdSessionId[0], "1234567890");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_CONNECT_GO_START_WFD_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaGenerateEvent():
 */

int wfaStaGenerateEvent(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    caStaGenEvent_t *staGenerateEvent = (caStaGenEvent_t *)caCmdBuf; // uncomment and use it
    caWfdStaGenEvent_t *wfdGenEvent;

    PRINTF("\n Entry wfaStaGenerateEvent... ");

    // Geneate the specified action and return with complete/error.
    if (staGenerateEvent->program == PROG_TYPE_WFD)
    {
        wfdGenEvent = &staGenerateEvent->wfdEvent;
        if (wfdGenEvent->type == eUibcGen)
        {
        }
        else if (wfdGenEvent->type == eUibcHid)
        {
        }
        else if (wfdGenEvent->type == eFrameSkip)
        {
        }
        else if (wfdGenEvent->type == eI2cRead)
        {
        }
        else if (wfdGenEvent->type == eI2cWrite)
        {
        }
        else if (wfdGenEvent->type == eInputContent)
        {
        }
        else if (wfdGenEvent->type == eIdrReq)
        {
        }
    }

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_GENERATE_EVENT_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

/*
 * wfaStaReinvokeWfdSession():
 */

int wfaStaReinvokeWfdSession(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    //  caStaReinvokeWfdSession_t *staReinvokeSession= (caStaReinvokeWfdSession_t *)caCmdBuf; //uncomment and use it

    PRINTF("\n Entry wfaStaReinvokeWfdSession... ");

    // Reinvoke the WFD session by accepting the p2p invitation   or sending p2p invitation

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_REINVOKE_WFD_SESSION_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

int wfaStaGetParameter(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t infoResp;
    // dutCmdResponse_t *getrssiResp      = &gGenericResp;
    // dutCommand_t *getrssi              = (dutCommand_t *)caCmdBuf;
    caStaGetParameter_t *staGetrssi    = (caStaGetParameter_t *)caCmdBuf; // uncomment and use it
    caStaGetParameterResp_t *paramList = &infoResp.cmdru.getParamValue;

    // int ret = -WM_FAIL;
    struct wlan_network net;

    PRINTF("\n Entry wfaStaGetParameter...\n");

    // Check the program type
    if (staGetrssi->program == PROG_TYPE_WFD)
    {
        if (staGetrssi->getParamValue == eDiscoveredDevList)
        {
            // Get the discovered devices, make space seperated list and return, check list is not bigger than 128
            // bytes.
            paramList->getParamType = eDiscoveredDevList;
            strcpy((char *)&paramList->devList, "11:22:33:44:55:66 22:33:44:55:66:77 33:44:55:66:77:88");
        }
    }

    if (is_sta_connected())
    {
        if (staGetrssi->rssi_flag)
        {
            DPRINT_INFO(WFA_OUT, "\nInfo: Fetch RSSI\n");
            wlan_get_current_network(&net);
            paramList->rssi_resp    = net.rssi;
            paramList->getParamType = 2;
        }
    }

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_GET_PARAMETER_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);

    return WFA_SUCCESS;
}

int wfaStaExecAction(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caStaExecAction_t *execAction    = (caStaExecAction_t *)caCmdBuf;
    dutCmdResponse_t *execActionResp = &gGenericResp;
    // int ret;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaExecAction ...\n");

    PRINTF("Interface = %s\n", execAction->intf);
    PRINTF("Dest Mac = %s\n", execAction->destmac);
    PRINTF("Trigger =%s\n", execAction->trigger);
    PRINTF("BurstsExponent =%d\n", execAction->BurstsExponent);
    PRINTF("asap =%d\n", execAction->asap);
    PRINTF("FormatBwFTM =%d\n", execAction->FormatBwFTM);
    PRINTF("askForLocCivic =%d\n", execAction->askForLocCivic);
    PRINTF("askForLCI =%d\n", execAction->askForLCI);

    execActionResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_EXEC_ACTION_RESP_TLV, 4, (BYTE *)execActionResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}

int wfaStaBssidPool(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *disc                 = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staBssidPoolResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaBssidPool ...\n");

    staBssidPoolResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_BSSID_POOL_RESP_TLV, 4, (BYTE *)staBssidPoolResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}

int wfaStaAddCredential(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *setHS2 = (dutCommand_t *)caCmdBuf;
    // caSetHS2_t *pHS2param;
    dutCmdResponse_t *staSetHS2Resp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaAddCredential ...\n");

    staSetHS2Resp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_ADD_CREDENTIAL_RESP_TLV, 4, (BYTE *)staSetHS2Resp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}

int wfaStaHS2Associate(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *assoc            = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staAssocResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaHS2Associate ...\n");

    staAssocResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_HS2_ASSOCIATE_RESP_TLV, sizeof(dutCmdResponse_t), (BYTE *)staAssocResp, respBuf);
    *respLen = sizeof(dutCmdResponse_t) + 4;
    return TRUE;
}

int wfaStascan(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *stascan = (dutCommand_t *)caCmdBuf;
    //  caStaScan_t  *pStaScanparam;
    //	dutCmdResponse_t * staStascanResp= &gGenericResp;

    // DD--R23-MBSSID Working PARAMS added
    dutCmdResponse_t *infoResp = &gGenericResp;
    //	caStaScan_t  *pStaScanparam = (caStaScan_t *)caCmdBuf;
    //	caStaMBSSSCANResp_t *paramList = &infoResp.cmdru.getMBSS_SCAN_RES;

    int ret = -WM_FAIL;
    // struct wlan_network network;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaScan ...\n");

    ret = wlan_scan(NULL);

    /*	if (!strcasecmp(SIGMA_PROG_NAME,NXP_HS2_PROG)) {
      set_hs2_network_type(nxp_WS_info->sta_ctrl_interface,stascan->cmdsu.Stascan_param.hessid,stascan->cmdsu.Stascan_param.accNetType);
     }

     else if (pStaScanparam->mbss_scan==1) {
      ret = fetch_mbss_scan_res(sta_interface,staStascanResp->cmdru.mbss_scan_res);
      staStascanResp->status = STATUS_COMPLETE;
      printf("\nThe returned SCAN LIST is in string MBSS_SCAN_RES and is
     ----%s----\n",staStascanResp->cmdru.mbss_scan_res);
      strcpy(paramList->mbss_scan_res_resp,staStascanResp->cmdru.mbss_scan_res);
      paramList->mbss_scan_flag=1;
      printf("\nThe ReturnedSCAN LIST Must BE \"%s\"\n",paramList->mbss_scan_res_resp);
      staStascanResp->status = STATUS_COMPLETE;
      infoResp.status = STATUS_COMPLETE;
         wfaEncodeTLV(WFA_STA_SCAN_RESP_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
      *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
      LEAVE( __func__ );
      return WFA_SUCCESS;
     }
     else if ( use_supplicant ) {
      supplicant_network_scan(nxp_WS_info->sta_ctrl_interface);
      sleep(2);
     }
     else {
      mlan_network_scan(sta_interface);
     }*/

    if (ret != WM_SUCCESS)
    {
        infoResp->status = STATUS_ERROR;
        wfaEncodeTLV(WFA_STA_RESET_DEFAULT_RESP_TLV, 4, (BYTE *)infoResp, respBuf);
        *respLen = WFA_TLV_HDR_LEN + 4;
        DPRINT_ERR(WFA_ERR, "Unable to scan\n");
        return WFA_FAILURE;
    }

    infoResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SCAN_RESP_TLV, sizeof(infoResp), (BYTE *)infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
    return WFA_SUCCESS;
}

int wfadevSetParameter(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *cmd = (dutCommand_t *)caCmdBuf;
    // cadevSetParm_t *pdevsetparm;
    dutCmdResponse_t *devsetparmResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfadevSetParameter ...\n");

    devsetparmResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_HS2_DEV_SET_PARAMETER_RESP_TLV, 4, (BYTE *)devsetparmResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}

int wfaStaResetParm(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *ResetParm            = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staResetParmResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaResetParm ...\n");

    staResetParmResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_RESET_PARM_RESP_TLV, 4, (BYTE *)staResetParmResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}

int wfaStaPolicyUpdate(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *policy_update        = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staResetParmResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaPolicyUpdate ...\n");

    staResetParmResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_POLICY_UPDATE_RESP_TLV, 4, (BYTE *)staResetParmResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}
int wfaStaDevConfigureIe(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // dutCommand_t *config_ie                 = (dutCommand_t *)caCmdBuf;
    dutCmdResponse_t *staDevConfigureIeResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaStaDevConfigureIe ...\n");

    staDevConfigureIeResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_DEV_CONFIGURE_IE_RESP_TLV, 4, (BYTE *)staDevConfigureIeResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return TRUE;
}

int wfaDevExecAction(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    caDevExecAction_t *execAction = (caDevExecAction_t *)caCmdBuf;
    dutCmdResponse_t infoResp;
    DPRINT_INFO(WFA_OUT, "Entering wfaDevExecAction ...\n");

    DPRINT_INFO(WFA_OUT, "\n Key Rotation value is ---\"%d\"----", execAction->keyrotation);

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_DEV_EXEC_ACTION_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
    return WFA_SUCCESS;
}

int wfaAPSet11h(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSet11h_t *apSet11h         = (caAPSet11h_t *)caCmdBuf;
    dutCmdResponse_t *apSet11hResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaAPSet11h ...\n");

    apSet11hResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_11H_TLV, 4, (BYTE *)apSet11hResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSetWireless(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetWireless_t *set_wireless_params = (caAPSetWireless_t *)caCmdBuf;
    dutCmdResponse_t *apSetWirelessResp = &gGenericResp;

    DPRINT_INFO(WFA_OUT, "Entering wfaAPSetWireless ...\n");

    apSetWirelessResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_WIRELESS_TLV, 4, (BYTE *)apSetWirelessResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSetSecurity(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetSecurity_t *apSecurity       = (caAPSetSecurity_t *)caCmdBuf;
    dutCmdResponse_t *apSetSecurityResp = &gGenericResp;

    printf("\nEntering wfaAPSetSecurity\n");

    apSetSecurityResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_SECURITY_TLV, 4, (BYTE *)apSetSecurityResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPConfigCommit(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPConfigCommit_t *apConfigCommit   = (caAPConfigCommit_t *)caCmdBuf;
    dutCmdResponse_t *apConfigCommitResp = &gGenericResp;

    printf("\nEntering wfaAPConfigCommit...\n");

    apConfigCommitResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_CONFIG_COMMIT_TLV, sizeof(dutCmdResponse_t), (BYTE *)apConfigCommitResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(dutCmdResponse_t);
    return WFA_SUCCESS;
}

int wfaAPReboot(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetSecurity_t *apSecurity  = (caAPSetSecurity_t *)caCmdBuf;
    // char *ifname                   = apSecurity->intf;
    dutCmdResponse_t *apRebootResp = &gGenericResp;

    printf("\nEntering wfaAPReboot\n");

    apRebootResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_REBOOT_TLV, 4, (BYTE *)apRebootResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSet11n(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSet11n_t *apSet11n         = (caAPSet11n_t *)caCmdBuf;
    dutCmdResponse_t *apSet11nResp = &gGenericResp;

    printf("\nEntering wfaAPSet11n\n");

    apSet11nResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_11N_TLV, 4, (BYTE *)apSet11nResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPResetDefault(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPResetDefault_t *apResetDefault   = (caAPResetDefault_t *)caCmdBuf;
    dutCmdResponse_t *apResetDefaultResp = &gGenericResp;
    apResetDefaultResp->status           = STATUS_COMPLETE;

    printf("\nEntering wfaAPResetDefault\n");

    wfaEncodeTLV(WFA_AP_RESET_DEFAULT_TLV, 4, (BYTE *)apResetDefaultResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSetStaQos(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetStaQos_t *apSetStaQos      = (caAPSetStaQos_t *)caCmdBuf;
    dutCmdResponse_t *apSetStaQosResp = &gGenericResp;

    printf("\nEntering wfaAPSetStaQos\n");

    apSetStaQosResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_STA_QOS_TLV, 4, (BYTE *)apSetStaQosResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSetAPQos(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetAPQos_t *apSetAPQos       = (caAPSetAPQos_t *)caCmdBuf;
    // char *ifname                     = apSetAPQos->intf;
    dutCmdResponse_t *apSetAPQosResp = &gGenericResp;

    printf("\nEntering wfaAPSetAPQos\n");

    apSetAPQosResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_AP_QOS_TLV, 4, (BYTE *)apSetAPQosResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSendADDBAReq(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSendADDBAReq_t *apSendADDBAReq   = (caAPSendADDBAReq_t *)caCmdBuf;
    // char *ifname                         = apSendADDBAReq->intf;
    dutCmdResponse_t *apSendADDBAReqResp = &gGenericResp;

    printf("\nEntering wfaAPSendADDBAReq\n");

    apSendADDBAReqResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SEND_ADDBA_REQ_TLV, 4, (BYTE *)apSendADDBAReqResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSetRfeature(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetRfeature_t *apSetRfeature    = (caAPSetRfeature_t *)caCmdBuf;
    dutCmdResponse_t *apSetRfeatureResp = &gGenericResp;

    printf("\nEntering wfaiAPSetRfeature\n");

    apSetRfeatureResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_RFEATURE_TLV, 4, (BYTE *)apSetRfeatureResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaAPSetRadius(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSetRadius_t *apSetRadius      = (caAPSetRadius_t *)caCmdBuf;
    dutCmdResponse_t *apSetRadiusResp = &gGenericResp;

    printf("\nEntering wfaAPSetRadius\n");

    apSetRadiusResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_RADIUS_TLV, 4, (BYTE *)apSetRadiusResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;

    return WFA_SUCCESS;
}

int wfaAPSet11d(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caAPSet11d_t *apSet11d         = (caAPSet11d_t *)caCmdBuf;
    dutCmdResponse_t *apSet11dResp = &gGenericResp;

    printf("\nEntering wfaAPSet11d\n");

    apSet11dResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_11D_TLV, 4, (BYTE *)apSet11dResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}

int wfaApSet11nWireless(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caApSet11nWireless_t *set11n = (caApSet11nWireless_t *)caCmdBuf;
    dutCmdResponse_t infoResp;
    printf("\nEntering wfaApSet11nWireless\n");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_11N_WIRELESS_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
    return WFA_SUCCESS;
}

int wfaApSetPmf(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caApSetPmf_t *setpmf = (caApSetPmf_t *)caCmdBuf;
    dutCmdResponse_t infoResp;
    printf("\nEntering wfaApSetPmf\n");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_SET_PMF_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
    return WFA_SUCCESS;
}

int wfaApGetMacAddress(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caApGetMacAddress_t *getMac = (caApGetMacAddress_t *)caCmdBuf;
    dutCmdResponse_t infoResp;
    printf("\nEntering wfaApGetMacAddress\n");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_GET_MAC_ADDRESS_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
    return WFA_SUCCESS;
}

int wfaApDeauthSta(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    // caApDeauthSta_t *deauthsta = (caApDeauthSta_t *)caCmdBuf;
    dutCmdResponse_t infoResp;
    printf("\nEntering wfaApDeauthSta\n");

    infoResp.status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_AP_DEAUTH_STA_TLV, sizeof(infoResp), (BYTE *)&infoResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + sizeof(infoResp);
    return WFA_SUCCESS;
}
#endif
