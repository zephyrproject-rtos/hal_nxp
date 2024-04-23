
/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/** @file netif.c
 *
 *  @brief  This file provides network interface initialization code
 *
 *  Copyright 2008-2021 NXP
 *
 */

/*------------------------------------------------------*/
#include <netif_decl.h>
/*------------------------------------------------------*/

#if defined(SDK_OS_FREE_RTOS)

uint16_t g_data_nf_last;
uint16_t g_data_snr_last;
static struct netif *netif_arr[MAX_INTERFACES_SUPPORTED];
static t_u8 rfc1042_eth_hdr[MLAN_MAC_ADDR_LENGTH] = {0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00};
#ifdef CONFIG_WPS2
void (*wps_rx_callback)(const t_u8 *buf, size_t len);
#endif

/*------------------------------------------------------*/
static err_t igmp_mac_filter(struct netif *netif, const ip4_addr_t *group, enum netif_mac_filter_action action);
#ifdef CONFIG_IPV6
static err_t mld_mac_filter(struct netif *netif, const ip6_addr_t *group, enum netif_mac_filter_action action);
#endif

err_t lwip_netif_uap_init(struct netif *netif);
err_t lwip_netif_init(struct netif *netif);
void handle_data_packet(const t_u8 interface, const t_u8 *rcvdata, const t_u16 datalen);
void handle_amsdu_data_packet(t_u8 interface, t_u8 *rcvdata, t_u16 datalen);
void handle_deliver_packet_above(t_void *rxpd, t_u8 interface, t_void *lwip_pbuf);
bool wrapper_net_is_ip_or_ipv6(const t_u8 *buffer);

#ifdef MGMT_RX
static int (*rx_mgmt_callback)(const enum wlan_bss_type bss_type, const wifi_mgmt_frame_t *frame, const size_t len);
void rx_mgmt_register_callback(int (*rx_mgmt_cb_fn)(const enum wlan_bss_type bss_type,
                                                    const wifi_mgmt_frame_t *frame,
                                                    const size_t len))
{
    rx_mgmt_callback = rx_mgmt_cb_fn;
}

void rx_mgmt_deregister_callback()
{
    rx_mgmt_callback = NULL;
}
#endif

static void register_interface(struct netif *iface, mlan_bss_type iface_type)
{
    netif_arr[iface_type] = iface;
}

#ifdef CONFIG_TX_RX_ZERO_COPY
void net_tx_zerocopy_process_cb(void *destAddr, void *srcAddr, uint32_t len)
{
    outbuf_t *buf    = (outbuf_t *)srcAddr;
    t_u16 header_len = INTF_HEADER_LEN + sizeof(TxPD) + ETH_HDR_LEN;
    // coverity[overrun-buffer-arg:SUPPRESS]
    (void)memcpy((t_u8 *)destAddr, &buf->intf_header[0], header_len);
    pbuf_copy_partial((struct pbuf *)(buf->buffer), (t_u8 *)destAddr + header_len, (t_u16)(len - header_len), 0);
}
#endif

static void deliver_packet_above(struct pbuf *p, int recv_interface)
{
    err_t lwiperr = ERR_OK;
    /* points to packet payload, which starts with an Ethernet header */
    struct eth_hdr *ethhdr = p->payload;
    t_u8 retry_cnt         = 1;


    w_pkt_d("Data RX: Driver=>Kernel, if %d, len %d %d", recv_interface, p->tot_len, p->len);
    switch (htons(ethhdr->type))
    {
        case ETHTYPE_IP:
#ifdef CONFIG_IPV6
        case ETHTYPE_IPV6:
#endif
        case ETHTYPE_ARP:
            LINK_STATS_INC(link.recv);

            if ((unsigned)recv_interface >= MAX_INTERFACES_SUPPORTED)
            {
                while (true)
                {
                    ;
                }
            }
        retry:
            /* full packet send to tcpip_thread to process */
            lwiperr = netif_arr[recv_interface]->input(p, netif_arr[recv_interface]);
            if (lwiperr != (s8_t)ERR_OK)
            {
                if (retry_cnt)
                {
                    retry_cnt--;
                    portYIELD();
                    goto retry;
                }
                LINK_STATS_INC(link.proterr);
                LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_input: IP input error\n"));
                (void)pbuf_free(p);
                p = NULL;
            }
            break;
        case ETHTYPE_EAPOL:
            LINK_STATS_INC(link.recv);
#ifdef CONFIG_WPS2
            if (wps_rx_callback)
                wps_rx_callback(p->payload, p->len);
#endif /* CONFIG_WPS2 */

            (void)pbuf_free(p);
            p = NULL;
            break;
        default:
            /* drop the packet */
            LINK_STATS_INC(link.drop);
            (void)pbuf_free(p);
            p = NULL;
            break;
    }
}

#ifdef CONFIG_TX_RX_ZERO_COPY
static struct pbuf *gen_pbuf_from_data_for_zerocopy(t_u8 *payload, t_u16 datalen)
{
    t_u8 retry_cnt = 3;
    struct pbuf *p = NULL;

retry:
    /* We allocate a pbuf chain of pbufs from the pool. */
    p = pbuf_alloc(PBUF_RAW, datalen, PBUF_POOL);
    if (p == NULL)
    {
        if (retry_cnt)
        {
            retry_cnt--;
            portYIELD();
            goto retry;
        }
        return NULL;
    }

    /* Reserve space for mlan_buffer */
    pbuf_header(p, -(s16_t)(sizeof(mlan_buffer)));
    if (pbuf_take(p, payload, datalen - sizeof(mlan_buffer)) != 0)
    {
        (void)pbuf_free(p);
        p = NULL;
    }

    return p;
}
#endif

static struct pbuf *gen_pbuf_from_data(t_u8 *payload, t_u16 datalen)
{
    t_u8 retry_cnt = 3;
    struct pbuf *p = NULL;

retry:
    /* We allocate a pbuf chain of pbufs from the pool. */
    p = pbuf_alloc(PBUF_RAW, datalen, PBUF_POOL);
    if (p == NULL)
    {
        if (retry_cnt)
        {
            retry_cnt--;
            portYIELD();
            goto retry;
        }
        return NULL;
    }

    if (pbuf_take(p, payload, datalen) != 0)
    {
        (void)pbuf_free(p);
        p = NULL;
    }

    return p;
}

static void process_data_packet(const t_u8 *rcvdata, const t_u16 datalen)
{
    RxPD *rxpd                   = (RxPD *)(void *)((t_u8 *)rcvdata + INTF_HEADER_LEN);
    mlan_bss_type recv_interface = (mlan_bss_type)(rxpd->bss_type);
    u16_t header_type;

#ifndef CONFIG_WPA_SUPP
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_1AS)
    wlan_mgmt_pkt *pmgmt_pkt_hdr      = MNULL;
    wlan_802_11_header *pieee_pkt_hdr = MNULL;
    t_u16 sub_type                    = 0;
    t_u8 category                     = 0;
#endif
#endif

    t_u8 *payload     = NULL;
    t_u16 payload_len = (t_u16)0U;
    struct pbuf *p    = NULL;

    if (rxpd->rx_pkt_type == PKT_TYPE_AMSDU)
    {
        Eth803Hdr_t *eth803hdr = (Eth803Hdr_t *)((t_u8 *)rxpd + rxpd->rx_pkt_offset);
        /* If the AMSDU packet is unicast and is not for us, drop it */
        if (memcmp(mlan_adap->priv[recv_interface]->curr_addr, eth803hdr->dest_addr, MLAN_MAC_ADDR_LENGTH) &&
            ((eth803hdr->dest_addr[0] & 0x01) == 0))
        {
            return;
        }
    }

    if (recv_interface == MLAN_BSS_TYPE_STA || recv_interface == MLAN_BSS_TYPE_UAP)
    {
        g_data_nf_last  = rxpd->nf;
        g_data_snr_last = rxpd->snr;
    }

#ifndef CONFIG_WPA_SUPP
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_1AS)
    if ((rxpd->rx_pkt_type == PKT_TYPE_MGMT_FRAME) && (recv_interface == MLAN_BSS_TYPE_STA))
    {
        pmgmt_pkt_hdr = (wlan_mgmt_pkt *)(void *)((t_u8 *)rxpd + rxpd->rx_pkt_offset);
        pieee_pkt_hdr = (wlan_802_11_header *)(void *)&pmgmt_pkt_hdr->wlan_header;

        sub_type = IEEE80211_GET_FC_MGMT_FRAME_SUBTYPE(pieee_pkt_hdr->frm_ctl);
        // coverity[overrun-local:SUPPRESS]
        category = *((t_u8 *)pieee_pkt_hdr + sizeof(wlan_802_11_header));
        if (sub_type == (t_u16)SUBTYPE_ACTION)
        {
            if (category != (t_u8)IEEE_MGMT_ACTION_CATEGORY_RADIO_RSRC &&
                category != (t_u8)IEEE_MGMT_ACTION_CATEGORY_WNM &&
                category != (t_u8)IEEE_MGMT_ACTION_CATEGORY_UNPROTECT_WNM)
            {
                return;
            }
        }

        payload     = (t_u8 *)rxpd;
        payload_len = datalen - INTF_HEADER_LEN;
    }
    else
#endif
#endif
    {
        payload     = (t_u8 *)rxpd + rxpd->rx_pkt_offset;
        payload_len = rxpd->rx_pkt_length;
    }

#ifdef CONFIG_TX_RX_ZERO_COPY
    u16_t header_len = INTF_HEADER_LEN + rxpd->rx_pkt_offset;
    payload_len      = rxpd->rx_pkt_length + header_len + sizeof(mlan_buffer);
    p                = gen_pbuf_from_data_for_zerocopy((t_u8 *)rcvdata, payload_len);
#else
    p = gen_pbuf_from_data(payload, payload_len);
#endif

    /* If there are no more buffers, we do nothing, so the data is
       lost. We have to go back and read the other ports */
    if (p == NULL)
    {
        LINK_STATS_INC(link.memerr);
        LINK_STATS_INC(link.drop);
        return;
    }

#ifndef CONFIG_WPA_SUPP
    if (rxpd->rx_pkt_type == PKT_TYPE_MGMT_FRAME)
    {
#ifdef CONFIG_TX_RX_ZERO_COPY
        /* Skip interface header */
        pbuf_header(p, -(s16_t)(INTF_HEADER_LEN));
#endif
        /* Bypass the management frame about Add Block Ack Request or Add Block Ack Response*/
        if (wlan_bypass_802dot11_mgmt_pkt(p->payload) == WM_SUCCESS)
        {
            pbuf_free(p);
            p = NULL;
            return;
        }

#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_1AS)
        if (sub_type == (t_u16)SUBTYPE_ACTION && recv_interface == MLAN_BSS_TYPE_STA)
        {
            if (wifi_event_completion(WIFI_EVENT_MGMT_FRAME, WIFI_EVENT_REASON_SUCCESS, p) != WM_SUCCESS)
            {
                pbuf_free(p);
                p = NULL;
            }
        }
#endif
#ifdef MGMT_RX
        if (rx_mgmt_callback)
        {
            wifi_mgmt_frame_t *frame = (wifi_mgmt_frame_t *)(void *)((uint8_t *)rxpd + rxpd->rx_pkt_offset);

            if (rx_mgmt_callback((enum wlan_bss_type)rxpd->bss_type, frame, rxpd->rx_pkt_length) == WM_SUCCESS)
            {
                pbuf_free(p);
                p = NULL;
                return;
            }
        }
#endif
        return;
    }
#endif

#ifdef CONFIG_TX_RX_ZERO_COPY
    /* Directly use rxpd from pbuf */
    rxpd = (RxPD *)(void *)((t_u8 *)p->payload + INTF_HEADER_LEN);
    /* Skip interface header and RxPD */
    pbuf_header(p, -(s16_t)header_len);
#endif

    /* points to packet payload, which starts with an Ethernet header */
    struct eth_hdr *ethhdr = p->payload;

#ifdef CONFIG_FILTER_LOCALLY_ADMINISTERED_AND_SELF_MAC_ADDR
    if ((ISLOCALLY_ADMINISTERED_ADDR(ethhdr->src.addr[0]) &&
         (!memcmp(&ethhdr->src.addr[3], &netif_arr[recv_interface]->hwaddr[3], 3))) ||
        (!memcmp(&ethhdr->src.addr, &netif_arr[recv_interface]->hwaddr, ETHARP_HWADDR_LEN)))
    {
        pbuf_free(p);
        p = NULL;
        return;
    }
#endif

    header_type = htons(ethhdr->type);

    if (!memcmp((t_u8 *)p->payload + SIZEOF_ETH_HDR, rfc1042_eth_hdr, sizeof(rfc1042_eth_hdr)))
    {
        struct eth_llc_hdr *ethllchdr = (struct eth_llc_hdr *)(void *)((t_u8 *)p->payload + SIZEOF_ETH_HDR);

        if (rxpd->rx_pkt_type == PKT_TYPE_AMSDU)
        {
            header_type = htons(ethllchdr->type);
        }
        else
        {
            ethhdr->type = ethllchdr->type;
            p->len -= SIZEOF_ETH_LLC_HDR;
            (void)memcpy((t_u8 *)p->payload + SIZEOF_ETH_HDR, (t_u8 *)p->payload + SIZEOF_ETH_HDR + SIZEOF_ETH_LLC_HDR,
                         p->len - SIZEOF_ETH_LLC_HDR);
            header_type = htons(ethhdr->type);
        }
    }

    switch (header_type)
    {
        case ETHTYPE_IP:
#ifdef CONFIG_IPV6
        case ETHTYPE_IPV6:
#endif
        /* Unicast ARP also need do rx reorder */
        case ETHTYPE_ARP:
            if (recv_interface == MLAN_BSS_TYPE_STA || recv_interface == MLAN_BSS_TYPE_UAP)
            {
                int rv = wrapper_wlan_handle_rx_packet(datalen, rxpd, p, payload);
                if (rv != WM_SUCCESS)
                {
                    /* mlan was unsuccessful in delivering the
                       packet */
                    LINK_STATS_INC(link.drop);
                    (void)pbuf_free(p);
                }
            }
            else
            {
                wrapper_wlan_update_uap_rxrate_info(rxpd);
                deliver_packet_above(p, recv_interface);
            }
            p = NULL;
            break;
        case ETHTYPE_EAPOL:
            deliver_packet_above(p, recv_interface);
            break;
        default:
#ifdef CONFIG_NET_MONITOR
            /*If rx_pkt_type is 802.11, and in monitor mode, deliver data to user*/
            if ((rxpd->rx_pkt_type == PKT_TYPE_802DOT11) && (true == get_monitor_flag()))
            {
                wifi_frame_t *frame = (wifi_frame_t *)(uint8_t *)p->payload;

                if (frame->frame_type == BEACON_FRAME || frame->frame_type == DATA_FRAME ||
                    frame->frame_type == AUTH_FRAME || frame->frame_type == PROBE_REQ_FRAME ||
                    frame->frame_type == QOS_DATA_FRAME)
                {
                    user_recv_monitor_data(rcvdata);
                }
            }
#endif
            /* fixme: avoid pbuf allocation in this case */
            LINK_STATS_INC(link.drop);
            (void)pbuf_free(p);
            p = NULL;
            break;
    }
}

/* Callback function called from the wifi module */
void handle_data_packet(const t_u8 interface, const t_u8 *rcvdata, const t_u16 datalen)
{
    if (interface < MAX_INTERFACES_SUPPORTED && netif_arr[interface] != NULL)
    {
        process_data_packet(rcvdata, datalen);
    }
}

void handle_amsdu_data_packet(t_u8 interface, t_u8 *rcvdata, t_u16 datalen)
{

    struct pbuf *p = gen_pbuf_from_data(rcvdata, datalen);
    if (p == NULL)
    {
        w_pkt_e("[amsdu] No pbuf available. Dropping packet");
        LINK_STATS_INC(link.memerr);
        LINK_STATS_INC(link.drop);
        return;
    }
    deliver_packet_above(p, interface);
}

void handle_deliver_packet_above(t_void *rxpd, t_u8 interface, t_void *lwip_pbuf)
{
    struct pbuf *p = (struct pbuf *)lwip_pbuf;

    (void)rxpd;
    deliver_packet_above(p, interface);
}

bool wrapper_net_is_ip_or_ipv6(const t_u8 *buffer)
{
    return net_is_ip_or_ipv6(buffer);
}

/**
 * Should be called at the beginning of the program to set up the
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void low_level_init(struct netif *netif)
{
    /* set MAC hardware address length */
    netif->hwaddr_len = ETHARP_HWADDR_LEN;

    /* maximum transfer unit */
    netif->mtu = 1500;

    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

    netif_set_igmp_mac_filter(netif, igmp_mac_filter);
    netif->flags |= NETIF_FLAG_IGMP;
#ifdef CONFIG_IPV6
    netif_set_mld_mac_filter(netif, mld_mac_filter);
    netif->flags |= NETIF_FLAG_MLD6;

    /*
     * For hardware/netifs that implement MAC filtering.
     * All-nodes link-local is handled by default, so we must let the hardware know
     * to allow multicast packets in.
     * Should set mld_mac_filter previously. */
    if (netif->mld_mac_filter != NULL)
    {
        ip6_addr_t ip6_allnodes_ll;
        ip6_addr_set_allnodes_linklocal(&ip6_allnodes_ll);
        (void)netif->mld_mac_filter(netif, &ip6_allnodes_ll, NETIF_ADD_MAC_FILTER);
    }
#endif
}

extern int retry_attempts;

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become availale since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */

static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
    int ret;
    struct ethernetif *ethernetif = netif->state;
    u32_t pkt_len, outbuf_len;
#ifndef CONFIG_TX_RX_ZERO_COPY
    u16_t uCopied;
#endif
    t_u8 interface   = ethernetif->interface;
    t_u8 *wmm_outbuf = NULL;

#ifdef CONFIG_WMM
    t_u8 tid                      = 0;
    int retry                     = 0;
    t_u8 ra[MLAN_MAC_ADDR_LENGTH] = {0};
    bool is_tx_pause              = false;

    t_u32 pkt_prio = wifi_wmm_get_pkt_prio(p, &tid);
    if (pkt_prio == -WM_FAIL)
    {
        return ERR_MEM;
    }

    if (interface > WLAN_BSS_TYPE_UAP)
    {
        wifi_wmm_drop_no_media(interface);
        return ERR_MEM;
    }

    if (wifi_tx_status == WIFI_DATA_BLOCK)
    {
        wifi_tx_block_cnt++;
        return ERR_OK;
    }

    if (interface == WLAN_BSS_TYPE_STA)
    {
        if (wifi_add_to_bypassq(interface, p, p->tot_len) == WM_SUCCESS)
        {
            LINK_STATS_INC(link.xmit);
            return ERR_OK;
        }
    }

    wifi_wmm_da_to_ra(p->payload, ra);

    do
    {
        if (retry != 0)
        {
            send_wifi_driver_tx_data_event(interface);
        }
        else
        {
            retry = retry_attempts;
        }

        wmm_outbuf = wifi_wmm_get_outbuf_enh(&outbuf_len, (mlan_wmm_ac_e)pkt_prio, interface, ra, &is_tx_pause);
        ret        = (wmm_outbuf == NULL) ? true : false;

        if (ret == true && is_tx_pause == true)
        {
            os_thread_sleep(os_msec_to_ticks(1));
        }

        retry--;
    } while (ret == true && retry > 0);

    if (ret == true)
    {
        wifi_wmm_drop_retried_drop(interface);
        return ERR_MEM;
    }
#else
    wmm_outbuf = wifi_get_outbuf((uint32_t *)(&outbuf_len));

    if (wmm_outbuf == NULL)
    {
        return ERR_MEM;
    }
#endif

    pkt_len =
#ifdef CONFIG_WMM
        sizeof(mlan_linked_list) +
#endif
        sizeof(TxPD) + INTF_HEADER_LEN;

#ifndef CONFIG_WMM
#if LWIP_NETIF_TX_SINGLE_PBUF
    if ((p->len == p->tot_len) && (pbuf_header(p, pkt_len) == 0))
    {
        wmm_outbuf = p->payload;
        memset(wmm_outbuf, 0x00, pkt_len);
        pkt_len = p->tot_len;
    }
    else
#endif
#endif
    {
#ifdef CONFIG_TX_RX_ZERO_COPY
        pkt_len += ETH_HDR_LEN;
        memset(wmm_outbuf, 0x00, pkt_len);
        /* Save the ethernet header */
        pbuf_copy_partial(p, ((outbuf_t *)wmm_outbuf)->eth_header, ETH_HDR_LEN, 0);
        /* Skip ethernet header */
        pbuf_header(p, -(s16_t)ETH_HDR_LEN);
        ((outbuf_t *)wmm_outbuf)->buffer = p;
        /* Save the data payload pointer without ethernet header */
        ((outbuf_t *)wmm_outbuf)->payload = (t_u8 *)p->payload;
        pkt_len += p->tot_len;
        /* Driver will free this pbuf */
        pbuf_ref(p);
#else
        memset(wmm_outbuf, 0x00, pkt_len);

        uCopied = pbuf_copy_partial(p, wmm_outbuf + pkt_len, p->tot_len, 0);

        LWIP_ASSERT("uCopied != p->tot_len", uCopied == p->tot_len);
        pkt_len += p->tot_len;
#endif
    }

    ret = wifi_low_level_output(interface, wmm_outbuf, pkt_len
#ifdef CONFIG_WMM
                                ,
                                pkt_prio, tid
#endif
    );

#ifndef CONFIG_WMM
#if LWIP_NETIF_TX_SINGLE_PBUF
    pkt_len = sizeof(TxPD) + INTF_HEADER_LEN;

    pbuf_header(p, -pkt_len);
#endif
#endif

    if (ret == WM_SUCCESS)
    {
        LINK_STATS_INC(link.xmit);
        return ERR_OK;
    }

    if (ret == -WM_E_NOMEM)
    {
        LINK_STATS_INC(link.err);
        ret = ERR_MEM;
    }
    else if (ret == -WM_E_BUSY)
    {
        LINK_STATS_INC(link.err);
        ret = ERR_TIMEOUT;
    }
    else
    { /* Do Nothing */
    }

    return ret;
}

#ifdef CONFIG_WPS2
void wps_register_rx_callback(void (*WPSEAPoLRxDataHandler)(const t_u8 *buf, const size_t len))
{
    wps_rx_callback = WPSEAPoLRxDataHandler;
}

void wps_deregister_rx_callback()
{
    wps_rx_callback = NULL;
}
#endif /* CONFIG_WPS2 */


/* Below struct is used for creating IGMP IPv4 multicast list */
typedef struct group_ip4_addr
{
    struct group_ip4_addr *next;
    uint32_t group_ip;
} group_ip4_addr_t;

/* Head of list that will contain IPv4 multicast IP's */
static group_ip4_addr_t *igmp_ip4_list;

/* Callback called by LwiP to add or delete an entry in the multicast filter table */
static err_t igmp_mac_filter(struct netif *netif, const ip4_addr_t *group, enum netif_mac_filter_action action)
{
    uint8_t mcast_mac[6];
    err_t result;
    int error;

    /* IPv4 to MAC conversion as per section 6.4 of rfc1112 */
    wifi_get_ipv4_multicast_mac(ntohl(group->addr), mcast_mac);
    group_ip4_addr_t *curr, *prev;

    switch (action)
    {
        case NETIF_ADD_MAC_FILTER:
            /* LwIP takes care of duplicate IP addresses and it always send
             * unique IP address. Simply add IP to top of list*/
            curr = (group_ip4_addr_t *)os_mem_alloc(sizeof(group_ip4_addr_t));
            if (curr == NULL)
            {
                result = ERR_IF;
                goto done;
            }
            curr->group_ip = group->addr;
            curr->next     = igmp_ip4_list;
            igmp_ip4_list  = curr;
            /* Add multicast MAC filter */
            error = wifi_add_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = ERR_OK;
            }
            else if (error == -WM_E_EXIST)
            {
                result = ERR_OK;
            }
            else
            {
                /* In case of failure remove IP from list */
                curr          = igmp_ip4_list;
                igmp_ip4_list = curr->next;
                os_mem_free(curr);
                curr   = NULL;
                result = ERR_IF;
            }
            break;
        case NETIF_DEL_MAC_FILTER:
            /* Remove multicast IP address from list */
            curr = igmp_ip4_list;
            prev = curr;
            while (curr != NULL)
            {
                if (curr->group_ip == group->addr)
                {
                    if (prev == curr)
                    {
                        igmp_ip4_list = curr->next;
                        os_mem_free(curr);
                    }
                    else
                    {
                        prev->next = curr->next;
                        os_mem_free(curr);
                    }
                    curr = NULL;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            /* Check if other IP is mapped to same MAC */
            curr = igmp_ip4_list;
            while (curr != NULL)
            {
                /* If other IP is mapped to same MAC than skip Multicast MAC removal */
                if ((ntohl(curr->group_ip) & 0x7FFFFFU) == (ntohl(group->addr) & 0x7FFFFFU))
                {
                    result = ERR_OK;
                    goto done;
                }
                curr = curr->next;
            }
            /* Remove Multicast MAC filter */
            error = wifi_remove_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = ERR_OK;
            }
            else
            {
                result = ERR_IF;
            }
            break;
        default:
            result = ERR_IF;
            break;
    }
done:
    return result;
}

#ifdef CONFIG_IPV6
/* Below struct is used for creating IGMP IPv6 multicast list */
typedef struct group_ip6_addr
{
    struct group_ip6_addr *next;
    uint32_t group_ip;
} group_ip6_addr_t;

/* Head of list that will contain IPv6 multicast IP's */
static group_ip6_addr_t *mld_ip6_list;

/* Callback called by LwiP to add or delete an entry in the IPv6 multicast filter table */
static err_t mld_mac_filter(struct netif *netif, const ip6_addr_t *group, enum netif_mac_filter_action action)
{
    uint8_t mcast_mac[6];
    err_t result;
    int error;

    /* IPv6 to MAC conversion as per section 7 of rfc2464 */
    wifi_get_ipv6_multicast_mac(ntohl(group->addr[3]), mcast_mac);
    group_ip6_addr_t *curr, *prev;

    switch (action)
    {
        case NETIF_ADD_MAC_FILTER:
            /* LwIP takes care of duplicate IP addresses and it always send
             * unique IP address. Simply add IP to top of list*/
            curr = (group_ip6_addr_t *)os_mem_alloc(sizeof(group_ip6_addr_t));
            if (curr == NULL)
            {
                result = ERR_IF;
                goto done;
            }
            curr->group_ip = group->addr[3];
            curr->next     = mld_ip6_list;
            mld_ip6_list   = curr;
            /* Add multicast MAC filter */
            error = wifi_add_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = ERR_OK;
            }
            else if (error == -WM_E_EXIST)
            {
                result = ERR_OK;
            }
            else
            {
                /* In case of failure remove IP from list */
                curr         = mld_ip6_list;
                mld_ip6_list = mld_ip6_list->next;
                os_mem_free(curr);
                curr   = NULL;
                result = ERR_IF;
            }
            break;
        case NETIF_DEL_MAC_FILTER:
            /* Remove multicast IP address from list */
            curr = mld_ip6_list;
            prev = curr;
            while (curr != NULL)
            {
                if (curr->group_ip == group->addr[3])
                {
                    if (prev == curr)
                    {
                        mld_ip6_list = curr->next;
                        os_mem_free(curr);
                    }
                    else
                    {
                        prev->next = curr->next;
                        os_mem_free(curr);
                    }
                    curr = NULL;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            /* Check if other IP is mapped to same MAC */
            curr = mld_ip6_list;
            while (curr != NULL)
            {
                /* If other IP is mapped to same MAC than skip Multicast MAC removal */
                if ((ntohl(curr->group_ip) & 0xFFFFFF) == (ntohl(group->addr[3]) & 0xFFFFFF))
                {
                    result = ERR_OK;
                    goto done;
                }
                curr = curr->next;
            }
            /* Remove Multicast MAC filter */
            error = wifi_remove_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = ERR_OK;
            }
            else
            {
                result = ERR_IF;
            }
            break;
        default:
            result = ERR_IF;
            break;
    }
done:
    return result;
}
#endif /* #ifdef CONFIG_IPV6 */

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netifapi_netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t lwip_netif_init(struct netif *netif)
{
    struct ethernetif *ethernetif;

    LWIP_ASSERT("netif != NULL", (netif != NULL));

    ethernetif = mem_malloc(sizeof(struct ethernetif));
    if (ethernetif == NULL)
    {
        LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_init: out of memory\n"));
        return ERR_MEM;
    }

    /*
     * Initialize the snmp variables and counters inside the struct netif.
     * The last argument should be replaced with your link speed, in units
     * of bits per second.
     */
    NETIF_INIT_SNMP(netif, snmp_ifType_ethernet_csmacd, LINK_SPEED_OF_YOUR_NETIF_IN_BPS);

    ethernetif->interface = MLAN_BSS_TYPE_STA;
    netif->state          = ethernetif;
    netif->name[0]        = IFNAME0;
    netif->name[1]        = IFNAME1;
    /* We directly use etharp_output() here to save a function call.
     * You can instead declare your own function an call etharp_output()
     * from it if you have to do some checks before sending (e.g. if link
     * is available...) */
    netif->output     = etharp_output;
    netif->linkoutput = low_level_output;
#ifdef CONFIG_IPV6
    netif->output_ip6 = ethip6_output;
#endif

    ethernetif->ethaddr = (struct eth_addr *)(void *)&(netif->hwaddr[0]);

    /* initialize the hardware */
    low_level_init(netif);

    /* set sta MAC hardware address */
    (void)wlan_get_mac_address(netif->hwaddr);

    register_interface(netif, MLAN_BSS_TYPE_STA);
    return ERR_OK;
}

err_t lwip_netif_uap_init(struct netif *netif)
{
    struct ethernetif *ethernetif;

    LWIP_ASSERT("netif != NULL", (netif != NULL));

    ethernetif = mem_malloc(sizeof(struct ethernetif));
    if (ethernetif == NULL)
    {
        LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_init: out of memory\n"));
        return ERR_MEM;
    }

    ethernetif->interface = MLAN_BSS_TYPE_UAP;
    netif->state          = ethernetif;
    netif->name[0]        = 'u';
    netif->name[1]        = 'a';
    /* We directly use etharp_output() here to save a function call.
     * You can instead declare your own function an call etharp_output()
     * from it if you have to do some checks before sending (e.g. if link
     * is available...) */
    netif->output     = etharp_output;
    netif->linkoutput = low_level_output;
#ifdef CONFIG_IPV6
    netif->output_ip6 = ethip6_output;
#endif

    ethernetif->ethaddr = (struct eth_addr *)(void *)&(netif->hwaddr[0]);

    /* initialize the hardware */
    low_level_init(netif);

    /* set uap MAC hardware address */
    (void)wlan_get_mac_address_uap(netif->hwaddr);

    register_interface(netif, MLAN_BSS_TYPE_UAP);

    return ERR_OK;
}


#endif
