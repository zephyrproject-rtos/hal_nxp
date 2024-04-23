/** @file wps_l2.c
 *
 *  @brief This file contains functions handling layer 2 socket read/write
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>
#include "wifi_nxp_wps.h"
#include <lwip/sys.h>
#include <lwip/inet.h>
#include <wlan.h>

#include "wps_mem.h"
#include "wps_def.h"
#include "wps_l2.h"
#include "wps_os.h"
#include "wps_eapol.h"
#include "wps_msg.h"

/********************************************************
        Local Variables
********************************************************/

/********************************************************
        Global Variables
********************************************************/
/** Global pwps information */
extern PWPS_INFO gpwps_info;
/** wps global */
extern WPS_DATA wps_global;

/********************************************************
        Local Functions
********************************************************/
/**
 *  @brief Process Layer 2 socket receive function
 *
 *  @param sock         Socket number for receiving
 *  @param l2_ctx       A pointer to user private information
 *  @return             None
 */
void wps_l2_receive(const u8 *src_addr, const u8 *buf, size_t len)
{
    ENTER();

    wps_rx_eapol(src_addr, buf, len);

    LEAVE();
}

/********************************************************
        Global Functions
********************************************************/
/**
 *  @brief Get Layer 2 MAC Address
 *
 *  @param l2           A pointer to structure of layer 2 information
 *  @param addr         A pointer to returned buffer
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_l2_get_mac(WPS_L2_INFO *l2, u8 *addr)
{
    ENTER();
    (void)memcpy(addr, l2->my_mac_addr, ETH_ALEN);
    LEAVE();
    return WPS_STATUS_SUCCESS;
}

extern int wps_low_level_output(const uint8_t interface, const uint8_t *buf, const uint16_t len);
/**
 *  @brief Process Layer 2 socket send function
 *
 *  @param l2           A pointer to structure of layer 2 information
 *  @param dst_addr     Destination address to send
 *  @param proto        Protocol number for layer 2 packet
 *  @param buf          A pointer to sending packet buffer
 *  @param len          Packet length
 *  @return             WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_l2_send(WPS_L2_INFO *l2, const u8 *dst_addr, u16 proto, const u8 *buf, size_t len)
{
    int ret                  = WPS_STATUS_SUCCESS, retry_cnt;
    void *buffer             = (void *)wps_mem_malloc(ETH_FRAME_LEN);
    unsigned char *etherhead = (unsigned char *)buffer;
    unsigned char *data      = (unsigned char *)buffer + 14;
    struct l2_ethhdr *eh     = (struct l2_ethhdr *)etherhead;
    u16 protocol;

    ENTER();

    if (l2 == NULL || buffer == NULL)
    {
        LEAVE();
        return WPS_STATUS_FAIL;
    }

    (void)memcpy((void *)(buffer), (void *)dst_addr, ETH_ALEN);
    (void)memcpy((void *)((unsigned char *)buffer + ETH_ALEN), (void *)l2->my_mac_addr, ETH_ALEN);
    protocol    = (proto >> 8) | (proto << 8);
    eh->h_proto = protocol;
    (void)memcpy(data, buf, len);
    len += 14;

    retry_cnt = 5;

    do
    {
        if (gpwps_info->role == WFD_ROLE)
            ret = wps_low_level_output(BSS_TYPE_WFD, (const u8_t *)buffer, len);
        else if (gpwps_info->role == WPS_REGISTRAR)
            ret = wps_low_level_output(BSS_TYPE_UAP, (const u8_t *)buffer, len);
        else
            ret = wps_low_level_output(BSS_TYPE_STA, (const u8_t *)buffer, len);

        if (ret < 0)
        {
            wps_d("wps_l2_send failed... retrying\r\n", ret);
            retry_cnt--;
        }
        else
            retry_cnt = 0;

        os_thread_sleep(200);

    } while (retry_cnt != 0);

    if (buffer)
        wps_mem_free(buffer);

    LEAVE();
    return ret;
}

/**
 *  @brief Process Layer 2 socket initialization
 *
 *  @param ifname       Interface name
 *  @param protocol     Ethernet protocol number in host byte order
 *  @param rx_callback  Callback function that will be called for each received packet
 *  @param l2_hdr       1 = include layer 2 header, 0 = do not include header
 *  @return             A pointer to l2 structure
 */
WPS_L2_INFO *wps_l2_init(const char *ifname,
                         unsigned short protocol,
                         void (*rx_callback)(const u8 *src_addr, const u8 *buf, size_t len))
{
    WPS_L2_INFO *l2;
    uint8_t mac[6];

    ENTER();

    l2 = wps_mem_malloc(sizeof(WPS_L2_INFO));
    if (l2 == NULL)
    {
        LEAVE();
        return NULL;
    }

    (void)memset(l2, 0, sizeof(*l2));
    strncpy(l2->ifname, ifname, sizeof(l2->ifname));
    l2->ifname[(sizeof(l2->ifname) / sizeof(l2->ifname[0])) - 1] = '\0';
    if (wlan_get_mac_address(mac))
    {
        wps_d("Error: unable to retrieve MAC address\r\n");
        wps_mem_free(l2);
        return NULL;
    }
    else
        wps_d("%02X:%02X:%02X:%02X:%02X:%02X\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);


    (void)memcpy(l2->my_mac_addr, mac, ETH_ALEN);

    LEAVE();
    return l2;
}

/**
 *  @brief Process Layer 2 socket free
 *
 *  @param l2       A pointer to user private information
 *  @return         None
 */
void wps_l2_deinit(WPS_L2_INFO *l2)
{
    ENTER();

    if (l2 == NULL)
    {
        LEAVE();
        return;
    }

    wps_mem_free(l2);

    LEAVE();
}
