/** @file net.c
 *
 *  @brief  This file provides network porting code
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "wifi.h"
#include <osa.h>
#include "netif_decl.h"
#include <wm_net.h>
#if CONFIG_WIFI_NM_WPA_SUPPLICANT
#include <supp_events.h>
#endif

#define net_e(...) wmlog_e("net", ##__VA_ARGS__)

#if CONFIG_NET_DEBUG
#define net_d(...) wmlog("net", ##__VA_ARGS__)
#else
#define net_d(...)
#endif /* ! CONFIG_NET_DEBUG */

#if CONFIG_IPV6
#define IPV6_ADDR_STATE_TENTATIVE  "Tentative"
#define IPV6_ADDR_STATE_PREFERRED  "Preferred"
#define IPV6_ADDR_STATE_INVALID    "Invalid"
#define IPV6_ADDR_STATE_VALID      "Valid"
#define IPV6_ADDR_STATE_DEPRECATED "Deprecated"
#define IPV6_ADDR_TYPE_LINKLOCAL   "Link-Local"
#define IPV6_ADDR_TYPE_GLOBAL      "Global"
#define IPV6_ADDR_TYPE_UNIQUELOCAL "Unique-Local"
#define IPV6_ADDR_TYPE_SITELOCAL   "Site-Local"
#define IPV6_ADDR_UNKNOWN          "Unknown"
#endif

#if CONFIG_IPV6
#define DHCP_TIMEOUT (60 * 1000)
#else
#define DHCP_TIMEOUT (120 * 1000)
#endif

#ifdef RW610
#define TX_DATA_PAYLOAD_SIZE 1500
#else
// To do for other chips
#endif


/*******************************************************************************
 * Definitions
 ******************************************************************************/

enum netif_mac_filter_action
{
    /** Delete a filter entry */
    NET_IF_DEL_MAC_FILTER = 0,
    /** Add a filter entry */
    NET_IF_ADD_MAC_FILTER = 1
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static int igmp_mac_filter(struct netif *netif, const struct in_addr *group, enum netif_mac_filter_action action);

#if CONFIG_IPV6
static int mld_mac_filter(struct netif *netif, const struct in6_addr *group, enum netif_mac_filter_action action);
#endif

static int (*net_internal_rx_callback)(struct net_if *iface, struct net_pkt *pkt);
void nxp_wifi_internal_register_rx_cb(int (*rx_cb_fn)(struct net_if *iface, struct net_pkt *pkt))
{
    net_internal_rx_callback = rx_cb_fn;
}

uint16_t g_data_nf_last;
uint16_t g_data_snr_last;

static t_u8 rfc1042_eth_hdr[MLAN_MAC_ADDR_LENGTH] = {0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00};

static struct net_mgmt_event_callback net_event_v4_cb;
#define DHCPV4_MASK  (NET_EVENT_IPV4_DHCP_BOUND | NET_EVENT_IPV4_DHCP_STOP)
#define MCASTV4_MASK (NET_EVENT_IPV4_MADDR_ADD | NET_EVENT_IPV4_MADDR_DEL)

#if CONFIG_IPV6
static struct net_mgmt_event_callback net_event_v6_cb;
#define MCASTV6_MASK (NET_EVENT_IPV6_MADDR_ADD | NET_EVENT_IPV6_MADDR_DEL)
#define IPV6_MASK    (NET_EVENT_IPV6_DAD_SUCCEED | NET_EVENT_IPV6_ADDR_ADD)
#endif

#if CONFIG_WIFI_NM_WPA_SUPPLICANT
static struct net_mgmt_event_callback net_event_supp_cb;
#define NET_SUPP_MASK (NET_EVENT_SUPPLICANT_READY | NET_EVENT_SUPPLICANT_NOT_READY)
static bool g_supp_ready = 0;
#endif
interface_t g_mlan;
#if UAP_SUPPORT
interface_t g_uap;
#endif

static int net_wlan_init_done = 0;
OSA_TIMER_HANDLE_DEFINE(dhcp_timer);
static void dhcp_timer_cb(osa_timer_arg_t arg);
#if CONFIG_WIFI_NM_WPA_SUPPLICANT
static void set_supp_ready_state(bool ready)
{
    g_supp_ready = ready;
}

bool get_supp_ready_state(void)
{
    return g_supp_ready;
}
#endif

void deliver_packet_above(struct net_pkt *p, int recv_interface)
{
    int err = 0;
    /* points to packet payload, which starts with an Ethernet header */
    struct net_eth_hdr *ethhdr = NET_ETH_HDR(p);

    switch (htons(ethhdr->type))
    {
        case NET_ETH_PTYPE_IP:
#if CONFIG_IPV6
        case NET_ETH_PTYPE_IPV6:
#endif
        case NET_ETH_PTYPE_ARP:
        case NET_ETH_PTYPE_EAPOL:
            if (recv_interface >= MAX_INTERFACES_SUPPORTED)
            {
                while (true)
                {
                    ;
                }
            }

            if (net_internal_rx_callback == NULL)
            {
                net_e("Not registering rx callback");
                (void)net_pkt_unref(p);
                p = NULL;
                break;
            }
#if CONFIG_WIFI_SOFTAP_SUPPORT
            /* full packet send to tcpip_thread to process */
            if (recv_interface == WLAN_BSS_TYPE_UAP)
                err = net_internal_rx_callback(g_uap.netif, p);
            else
#endif
                err = net_internal_rx_callback(g_mlan.netif, p);
            if (err != 0)
            {
                net_e("Net input error");
                (void)net_pkt_unref(p);
                p = NULL;
            }
            break;
        default:
            /* drop the packet */
            (void)net_pkt_unref(p);
            p = NULL;
            break;
    }
}

#define MAX_RETRY_GEN_PKT 3
static struct net_pkt *gen_pkt_from_data(t_u8 interface, t_u8 *payload, t_u16 datalen)
{
    struct net_pkt *pkt = NULL;
    t_u8 retry_cnt      = MAX_RETRY_GEN_PKT;

retry:
    /* We allocate a network buffer */
#if CONFIG_WIFI_SOFTAP_SUPPORT
    if (interface == WLAN_BSS_TYPE_UAP)
        pkt = net_pkt_rx_alloc_with_buffer(g_uap.netif, datalen, AF_INET, 0, K_NO_WAIT);
    else
#endif
        pkt = net_pkt_rx_alloc_with_buffer(g_mlan.netif, datalen, AF_INET, 0, K_NO_WAIT);

    if (pkt == NULL)
    {
        if (retry_cnt)
        {
            retry_cnt--;
            k_yield();
            goto retry;
        }
        return NULL;
    }

    if (net_pkt_write(pkt, payload, datalen) < 0)
    {
        net_pkt_unref(pkt);
        pkt = NULL;
    }

    return pkt;
}

#if CONFIG_WIFI_PKT_FWD
struct net_pkt *gen_tx_pkt_from_data(uint8_t interface, uint8_t *payload, uint16_t datalen)
{
    struct net_pkt *pkt = NULL;
    uint8_t retry_cnt      = MAX_RETRY_GEN_PKT;

retry:
    /* We allocate a network buffer */
#if CONFIG_WIFI_SOFTAP_SUPPORT
    if (interface == WLAN_BSS_TYPE_UAP)
        pkt = net_pkt_alloc_with_buffer(g_uap.netif, datalen, AF_INET, 0, K_NO_WAIT);
    else
#endif
        pkt = net_pkt_alloc_with_buffer(g_mlan.netif, datalen, AF_INET, 0, K_NO_WAIT);

    if (pkt == NULL)
    {
        if (retry_cnt)
        {
            retry_cnt--;
            k_yield();
            goto retry;
        }
        return NULL;
    }

    if (net_pkt_write(pkt, payload, datalen) < 0)
    {
        net_pkt_unref(pkt);
        pkt = NULL;
    }

    net_pkt_cursor_init(pkt);
    return pkt;
}
#endif
#if CONFIG_TX_RX_ZERO_COPY
static struct net_pkt *gen_pkt_from_data_for_zerocopy(t_u8 interface, t_u8 *payload, t_u16 datalen)
{
    struct net_pkt *pkt = NULL;
    t_u8 retry_cnt      = MAX_RETRY_GEN_PKT;

retry:
    /* We allocate a network buffer */
#if CONFIG_WIFI_SOFTAP_SUPPORT
    if (interface == WLAN_BSS_TYPE_UAP)
        pkt = net_pkt_rx_alloc_with_buffer(g_uap.netif, datalen, AF_INET, 0, K_NO_WAIT);
    else
#endif
        pkt = net_pkt_rx_alloc_with_buffer(g_mlan.netif, datalen, AF_INET, 0, K_NO_WAIT);

    if (pkt == NULL)
    {
        if (retry_cnt)
        {
            retry_cnt--;
            k_yield();
            goto retry;
        }
        return NULL;
    }

    /* Reserve space for mlan_buffer */
    net_pkt_memset(pkt, 0, sizeof(mlan_buffer));
    net_buf_pull(pkt->frags, sizeof(mlan_buffer));
    net_pkt_cursor_init(pkt);
    if (net_pkt_write(pkt, payload, datalen - sizeof(mlan_buffer)) < 0)
    {
        net_pkt_unref(pkt);
        pkt = NULL;
    }

    return pkt;
}
#endif

#if !CONFIG_WIFI_NM_WPA_SUPPLICANT
/** Check if packet is mgmt and try to consume it.
 *
 * Return MLAN_STATUS_RESOURCE if not intrest in it.
 * Return MLAN_STATUS_SUCCESS if packet is consumed.
 * Return MLAN_STATUS_FAILURE if error happens and needs to drop it.
 */
static mlan_status process_mgmt_packet(t_u8 *data)
{
    RxPD *rxpd = (RxPD *)(void *)data;
    struct net_pkt *p = NULL;
    t_u16 plen;

    if (rxpd->bss_type != MLAN_BSS_TYPE_STA || rxpd->rx_pkt_type != PKT_TYPE_MGMT_FRAME)
    {
        return MLAN_STATUS_RESOURCE;
    }

    if (wlan_bypass_802dot11_mgmt_pkt(data) == MLAN_STATUS_SUCCESS)
    {
        return MLAN_STATUS_RESOURCE;
    }

#if (CONFIG_TX_RX_ZERO_COPY) || (FSL_USDHC_ENABLE_SCATTER_GATHER_TRANSFER)
    plen = rxpd->rx_pkt_offset + rxpd->rx_pkt_length + sizeof(mlan_buffer);
    p = gen_pkt_from_data_for_zerocopy(MLAN_BSS_TYPE_STA, data, plen);
#else
    plen = rxpd->rx_pkt_offset + rxpd->rx_pkt_length;
    p = gen_pkt_from_data(MLAN_BSS_TYPE_STA, data, plen);
#endif
    if (!p)
    {
        net_d("process_mgmt_packet gen_pkt_from_data fail");
        return MLAN_STATUS_FAILURE;
    }

    if (wifi_event_completion(WIFI_EVENT_MGMT_FRAME, WIFI_EVENT_REASON_SUCCESS, p) != WM_SUCCESS)
    {
        net_d("process_mgmt_packet send mgmt packet fail");
        net_stack_buffer_free(p);
        return MLAN_STATUS_FAILURE;
    }

    return MLAN_STATUS_SUCCESS;
}
#endif

static void process_data_packet(const t_u8 *rcvdata, const t_u16 datalen)
{
    RxPD *rxpd                   = (RxPD *)(void *)((t_u8 *)rcvdata + INTF_HEADER_LEN);
    mlan_bss_type recv_interface = (mlan_bss_type)(rxpd->bss_type);
    t_u16 header_type;

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

#if !CONFIG_WIFI_NM_WPA_SUPPLICANT
    mlan_status status = process_mgmt_packet((t_u8 *)rcvdata + INTF_HEADER_LEN);
    if (status != MLAN_STATUS_RESOURCE)
    {
        return;
    }
#endif

    t_u8 *payload     = (t_u8 *)rxpd + rxpd->rx_pkt_offset;
#if CONFIG_TX_RX_ZERO_COPY
    t_u16 header_len  = INTF_HEADER_LEN + rxpd->rx_pkt_offset;
    struct net_pkt *p = gen_pkt_from_data_for_zerocopy(recv_interface, (t_u8 *)rcvdata,
                                                       rxpd->rx_pkt_length + header_len + sizeof(mlan_buffer));
#else
    struct net_pkt *p = gen_pkt_from_data(recv_interface, payload, rxpd->rx_pkt_length);
#endif
    /* If there are no more buffers, we do nothing, so the data is
       lost. We have to go back and read the other ports */
    if (p == NULL)
    {
        return;
    }

#if CONFIG_TX_RX_ZERO_COPY
    /* Directly use rxpd from net_pkt */
    rxpd = (RxPD *)(void *)(net_pkt_data(p) + INTF_HEADER_LEN);
    /* Skip interface header and RxPD */
    net_buf_pull(p->frags, header_len);
    net_pkt_cursor_init(p);
#endif

    /* points to packet payload, which starts with an Ethernet header */
    struct net_eth_hdr *ethhdr = NET_ETH_HDR(p);

#if CONFIG_FILTER_LOCALLY_ADMINISTERED_AND_SELF_MAC_ADDR
    /* TODO: port wifi_netif.c */
    if ((ISLOCALLY_ADMINISTERED_ADDR(ethhdr->src.addr[0]) &&
         (!memcmp(&ethhdr->src.addr[3], &iw416_data.mac_addr[3], 3))) ||
        (!memcmp(&ethhdr->src.addr, &iw416_data.mac_addr[0], ETHARP_HWADDR_LEN)))
    {
        net_pkt_unref(p);
        p = NULL;
        return;
    }
#endif

    header_type = htons(ethhdr->type);

    if (!memcmp(payload + SIZEOF_ETH_HDR, rfc1042_eth_hdr, sizeof(rfc1042_eth_hdr)))
    {
        struct eth_llc_hdr *ethllchdr = (struct eth_llc_hdr *)(void *)(payload + SIZEOF_ETH_HDR);

        if (rxpd->rx_pkt_type == PKT_TYPE_AMSDU)
        {
            header_type = htons(ethllchdr->type);
        }
        else
        {
            /* Remove the LLC header if not the AMSDU packet */
            ethhdr->type = ethllchdr->type;
            (void)memmove(payload + SIZEOF_ETH_LLC_HDR, payload, SIZEOF_ETH_HDR);
            net_buf_pull(p->frags, SIZEOF_ETH_LLC_HDR);
            net_pkt_cursor_init(p);
            header_type = htons(ethhdr->type);
        }
    }

    switch (header_type)
    {
        case NET_ETH_PTYPE_IP:
#if CONFIG_IPV6
        case NET_ETH_PTYPE_IPV6:
#endif
        /* Unicast ARP also need do rx reorder */
        case NET_ETH_PTYPE_ARP:
            /* To avoid processing of unwanted udp broadcast packets, adding
             * filter for dropping packets received on ports other than
             * pre-defined ports.
             */

            if (recv_interface == MLAN_BSS_TYPE_STA || recv_interface == MLAN_BSS_TYPE_UAP)
            {
                int rv = wrapper_wlan_handle_rx_packet(datalen, rxpd, p, payload);
                if (rv != WM_SUCCESS)
                {
                    /* mlan was unsuccessful in delivering the
                       packet */

                    (void)net_pkt_unref(p);
                }
            }
            else
            {
                deliver_packet_above(p, recv_interface);
            }
            p = NULL;
            break;
        case NET_ETH_PTYPE_EAPOL:
            deliver_packet_above(p, recv_interface);
            break;
        default:
#if CONFIG_NET_MONITOR
            /* If rx_pkt_type is 802.11, and in monitor mode, deliver data to user */
            if ((rxpd->rx_pkt_type == PKT_TYPE_802DOT11) && (true == get_monitor_flag()))
            {
                wifi_frame_t *frame = (wifi_frame_t *)payload;

                if (frame->frame_type == BEACON_FRAME || frame->frame_type == DATA_FRAME ||
                    frame->frame_type == AUTH_FRAME || frame->frame_type == PROBE_REQ_FRAME ||
                    frame->frame_type == QOS_DATA_FRAME)
                {
                    user_recv_monitor_data(rcvdata);
                }
            }
#endif
            /* fixme: avoid pbuf allocation in this case */

            (void)net_pkt_unref(p);
            break;
    }
}

/* Callback function called from the wifi module */
void handle_data_packet(const t_u8 interface, const t_u8 *rcvdata, const t_u16 datalen)
{
    process_data_packet(rcvdata, datalen);
}

void handle_amsdu_data_packet(t_u8 interface, t_u8 *rcvdata, t_u16 datalen)
{
    struct net_pkt *p = gen_pkt_from_data(interface, rcvdata, datalen);
    if (p == NULL)
    {
        w_pkt_e("[amsdu] No pbuf available. Dropping packet");
        return;
    }

    deliver_packet_above(p, interface);
}

void handle_deliver_packet_above(t_void *rxpd, t_u8 interface, t_void *pkt)
{
    struct net_pkt *p = (struct net_pkt *)pkt;

#if !CONFIG_WIFI_RX_REORDER
    (void)rxpd;
    deliver_packet_above(p, interface);
#else
    RxPD *prxpd       = (RxPD *)rxpd;
    deliver_packet_above(prxpd, p, interface);
#endif
}

bool wrapper_net_is_ip_or_ipv6(const t_u8 *buffer)
{
    struct net_eth_hdr *hdr = (struct net_eth_hdr *)buffer;
    uint16_t type           = ntohs(hdr->type);
    if ((type == NET_ETH_PTYPE_IP) || type == NET_ETH_PTYPE_IPV6)
    {
        return true;
    }
    return false;
}

extern int retry_attempts;
#define MAX_RETRY_PKT_FWD 3
int nxp_wifi_internal_tx(const struct device *dev, struct net_pkt *pkt, bool pkt_fwd)
{
    int ret;
    interface_t *if_handle = (interface_t *)dev->data;
    t_u8 interface         = if_handle->state.interface;
    t_u16 net_pkt_len      = net_pkt_get_len(pkt);
    t_u32 pkt_len, outbuf_len;
    t_u8 *wmm_outbuf              = NULL;
#if CONFIG_WMM
    t_u8 *payload                 = net_pkt_data(pkt);
    t_u8 tid                      = 0;
    int retry                     = 0;
    t_u8 ra[MLAN_MAC_ADDR_LENGTH] = {0};
    bool is_tx_pause              = false;
    t_u32 pkt_prio                = WMM_AC_BE;
#endif

    t_u16 mtu = net_if_get_mtu(net_pkt_iface(pkt));
#ifdef RW610
    mtu       = MIN(TX_DATA_PAYLOAD_SIZE, mtu);
#endif
    if (net_pkt_len - ETH_HDR_LEN > mtu)
    {
        return -ENOMEM;
    }

#if !UAP_SUPPORT
    if (interface > WLAN_BSS_ROLE_STA)
    {
        return -ENOMEM;
    }
#endif

#if CONFIG_WMM
    if (net_pkt_len > ETH_HDR_LEN)
    {
        pkt_prio = wifi_wmm_get_pkt_prio(pkt, &tid);
        if (pkt_prio == -WM_FAIL)
        {
            return -ENOMEM;
        }
    }

    if (interface > WLAN_BSS_TYPE_UAP)
    {
        wifi_wmm_drop_no_media(interface);
        return -ENOMEM;
    }

    if (wifi_tx_status == WIFI_DATA_BLOCK)
    {
        wifi_tx_block_cnt++;
        return 0;
    }

    if (wifi_add_to_bypassq(interface, pkt, net_pkt_len) == WM_SUCCESS)
    {
        return 0;
    }

    wifi_wmm_da_to_ra(payload, ra);

    do
    {
        if (retry != 0)
        {
            send_wifi_driver_tx_data_event(interface);
            k_yield();
        }
        else
        {
            if (pkt_fwd)
            {
                retry = MAX_RETRY_PKT_FWD;
            }
            else
            {
                retry = retry_attempts;
            }
        }

        wmm_outbuf = wifi_wmm_get_outbuf_enh(&outbuf_len, (mlan_wmm_ac_e)pkt_prio, interface, ra, &is_tx_pause);
        ret        = (wmm_outbuf == NULL) ? true : false;

        /* In packet forward case, this function is called by RX thread,
         * so the time delay is not allowed */
        if (!pkt_fwd)
        {
            if (ret == true && is_tx_pause == true)
            {
                OSA_TimeDelay(1);
            }
        }
        retry--;
    } while (ret == true && retry > 0);

    if (ret == true)
    {
        wifi_wmm_drop_retried_drop(interface);
        return -ENOMEM;
    }
#else
    wmm_outbuf = wifi_get_outbuf((uint32_t *)(&outbuf_len));

    if (wmm_outbuf == NULL)
    {
        return -ENOMEM;
    }
#endif

    pkt_len =
#if CONFIG_WMM
        sizeof(mlan_linked_list) +
#endif
        sizeof(TxPD) + INTF_HEADER_LEN;

#if CONFIG_TX_RX_ZERO_COPY
    memset(wmm_outbuf, 0x00, pkt_len + ETH_HDR_LEN);
    /* Save the ethernet header */
    net_pkt_set_overwrite(pkt, false);
    net_pkt_read(pkt, ((outbuf_t *)wmm_outbuf)->eth_header, ETH_HDR_LEN);
    ((outbuf_t *)wmm_outbuf)->buffer = pkt;
    /* Save the data payload pointer without ethernet header */
    if (net_pkt_len > ETH_HDR_LEN)
    {
        ((outbuf_t *)wmm_outbuf)->payload = pkt->cursor.pos;
    }
    else
    {
        ((outbuf_t *)wmm_outbuf)->payload = NULL;
    }
    /* Driver will free this pbuf */
    net_pkt_ref(pkt);
#else
    assert(pkt_len + net_pkt_len <= outbuf_len);

    memset(wmm_outbuf, 0x00, pkt_len);

    if (net_pkt_read(pkt, wmm_outbuf + pkt_len, net_pkt_len))
        return -EIO;
#endif
    pkt_len += net_pkt_len;

    ret = wifi_low_level_output(interface, wmm_outbuf, pkt_len
#if CONFIG_WMM
                                ,
                                pkt_prio, tid
#endif
    );

    if (ret == WM_SUCCESS)
    {
        ret = 0;
    }
    else if (ret == -WM_E_NOMEM)
    {
        net_e("Wifi Net NOMEM");
        ret = -ENOMEM;
    }
    else if (ret == -WM_E_BUSY)
    {
        net_d("Wifi Net Busy");
        ret = -ETIMEDOUT;
    }
    else
    { /* Do Nothing */
    }

    return ret;
}

#if CONFIG_WIFI_PKT_FWD
int net_wifi_packet_send(uint8_t interface, void *stack_buffer)
{
    if (interface == WLAN_BSS_TYPE_UAP)
        return nxp_wifi_internal_tx(net_if_get_device((void *)g_uap.netif), (struct net_pkt *)stack_buffer, 1);
    else
        return nxp_wifi_internal_tx(net_if_get_device((void *)g_mlan.netif), (struct net_pkt *)stack_buffer, 1);
}
#endif

/* Below struct is used for creating IGMP IPv4 multicast list */
typedef struct group_ip4_addr
{
    struct group_ip4_addr *next;
    uint32_t group_ip;
} group_ip4_addr_t;

/* Head of list that will contain IPv4 multicast IP's */
static group_ip4_addr_t *igmp_ip4_list;

/* Callback called by net_mgmt to add or delete an entry in the multicast filter table */
static int igmp_mac_filter(struct netif *netif, const struct in_addr *group, enum netif_mac_filter_action action)
{
    uint8_t mcast_mac[6];
    int result;
    int error;

    /* IPv4 to MAC conversion as per section 6.4 of rfc1112 */
    wifi_get_ipv4_multicast_mac(ntohl(group->s_addr), mcast_mac);
    group_ip4_addr_t *curr, *prev;

    switch (action)
    {
        case NET_IF_ADD_MAC_FILTER:
            /* TCP/IP stack takes care of duplicate IP addresses and it always send
             * unique IP address. Simply add IP to top of list*/
#if !CONFIG_MEM_POOLS
            curr = (group_ip4_addr_t *)OSA_MemoryAllocate(sizeof(group_ip4_addr_t));
#else
            curr = (group_ip4_addr_t *)OSA_MemoryPoolAllocate(buf_32_MemoryPool);
#endif
            if (curr == NULL)
            {
                result = -WM_FAIL;
                goto done;
            }
            curr->group_ip = group->s_addr;
            curr->next     = igmp_ip4_list;
            igmp_ip4_list  = curr;
            /* Add multicast MAC filter */
            error = wifi_add_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = WM_SUCCESS;
            }
            else if (error == -WM_E_EXIST)
            {
                result = WM_SUCCESS;
            }
            else
            {
                /* In case of failure remove IP from list */
                curr          = igmp_ip4_list;
                igmp_ip4_list = curr->next;
#if !CONFIG_MEM_POOLS
                OSA_MemoryFree(curr);
#else
                OSA_MemoryPoolFree(buf_32_MemoryPool, curr);
#endif
                curr   = NULL;
                result = -WM_FAIL;
            }
            break;
        case NET_IF_DEL_MAC_FILTER:
            /* Remove multicast IP address from list */
            curr = igmp_ip4_list;
            prev = curr;
            while (curr != NULL)
            {
                if (curr->group_ip == group->s_addr)
                {
                    if (prev == curr)
                    {
                        igmp_ip4_list = curr->next;
#if !CONFIG_MEM_POOLS
                        OSA_MemoryFree(curr);
#else
                        OSA_MemoryPoolFree(buf_32_MemoryPool, curr);
#endif
                    }
                    else
                    {
                        prev->next = curr->next;
#if !CONFIG_MEM_POOLS
                        OSA_MemoryFree(curr);
#else
                        OSA_MemoryPoolFree(buf_32_MemoryPool, curr);
#endif
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
                if ((ntohl(curr->group_ip) & 0x7FFFFFU) == (ntohl(group->s_addr) & 0x7FFFFFU))
                {
                    result = WM_SUCCESS;
                    goto done;
                }
                curr = curr->next;
            }
            /* Remove Multicast MAC filter */
            error = wifi_remove_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = WM_SUCCESS;
            }
            else
            {
                result = -WM_FAIL;
            }
            break;
        default:
            result = -WM_FAIL;
            break;
    }
done:
    return result;
}

#if CONFIG_IPV6
/* Below struct is used for creating IGMP IPv6 multicast list */
typedef struct group_ip6_addr
{
    struct group_ip6_addr *next;
    uint32_t group_ip;
} group_ip6_addr_t;

/* Head of list that will contain IPv6 multicast IP's */
static group_ip6_addr_t *mld_ip6_list;

/* Callback called by net_mgmt to add or delete an entry in the IPv6 multicast filter table */
static int mld_mac_filter(struct netif *netif, const struct in6_addr *group, enum netif_mac_filter_action action)
{
    uint8_t mcast_mac[6];
    int result;
    int error;

    /* IPv6 to MAC conversion as per section 7 of rfc2464 */
    wifi_get_ipv6_multicast_mac(ntohl(group->s6_addr32[3]), mcast_mac);
    group_ip6_addr_t *curr, *prev;

    switch (action)
    {
        case NET_IF_ADD_MAC_FILTER:
            /* TCP/IP stack takes care of duplicate IP addresses and it always send
             * unique IP address. Simply add IP to top of list*/
#if !CONFIG_MEM_POOLS
            curr = (group_ip6_addr_t *)OSA_MemoryAllocate(sizeof(group_ip6_addr_t));
#else
            curr = (group_ip6_addr_t *)OSA_MemoryPoolAllocate(buf_32_MemoryPool);
#endif
            if (curr == NULL)
            {
                result = -WM_FAIL;
                goto done;
            }
            curr->group_ip = group->s6_addr32[3];
            curr->next     = mld_ip6_list;
            mld_ip6_list   = curr;
            /* Add multicast MAC filter */
            error = wifi_add_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = WM_SUCCESS;
            }
            else if (error == -WM_E_EXIST)
            {
                result = WM_SUCCESS;
            }
            else
            {
                /* In case of failure remove IP from list */
                curr         = mld_ip6_list;
                mld_ip6_list = mld_ip6_list->next;
#if !CONFIG_MEM_POOLS
                OSA_MemoryFree(curr);
#else
                OSA_MemoryPoolFree(buf_32_MemoryPool, curr);
#endif
                curr   = NULL;
                result = -WM_FAIL;
            }
            break;
        case NET_IF_DEL_MAC_FILTER:
            /* Remove multicast IP address from list */
            curr = mld_ip6_list;
            prev = curr;
            while (curr != NULL)
            {
                if (curr->group_ip == group->s6_addr32[3])
                {
                    if (prev == curr)
                    {
                        mld_ip6_list = curr->next;
#if !CONFIG_MEM_POOLS
                        OSA_MemoryFree(curr);
#else
                        OSA_MemoryPoolFree(buf_32_MemoryPool, curr);
#endif
                    }
                    else
                    {
                        prev->next = curr->next;
#if !CONFIG_MEM_POOLS
                        OSA_MemoryFree(curr);
#else
                        OSA_MemoryPoolFree(buf_32_MemoryPool, curr);
#endif
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
                if ((ntohl(curr->group_ip) & 0xFFFFFF) == (ntohl(group->s6_addr32[3]) & 0xFFFFFF))
                {
                    result = WM_SUCCESS;
                    goto done;
                }
                curr = curr->next;
            }
            /* Remove Multicast MAC filter */
            error = wifi_remove_mcast_filter(mcast_mac);
            if (error == 0)
            {
                result = WM_SUCCESS;
            }
            else
            {
                result = -WM_FAIL;
            }
            break;
        default:
            result = -WM_FAIL;
            break;
    }
done:
    return result;
}
#endif /* #if CONFIG_IPV6 */

void *net_get_sta_handle(void)
{
    return &g_mlan;
}

#if UAP_SUPPORT
void *net_get_uap_handle(void)
{
    return &g_uap;
}
#endif

struct netif *net_get_sta_interface(void)
{
    return (struct netif *)g_mlan.netif;
}

#if UAP_SUPPORT
struct netif *net_get_uap_interface(void)
{
    return (struct netif *)g_uap.netif;
}
#endif

int net_get_if_name_netif(char *pif_name, struct netif *iface)
{
    strncpy(pif_name, iface->if_dev->dev->name, NETIF_NAMESIZE);
    return WM_SUCCESS;
}

void net_stop_dhcp_timer(void)
{
    (void)OSA_TimerDeactivate((osa_timer_handle_t)dhcp_timer);
}

static void stop_cb(void *ctx)
{
    interface_t *if_handle = (interface_t *)net_get_mlan_handle();

    net_dhcpv4_stop(if_handle->netif);
#if CONFIG_IPV6
    if (!is_sta_ipv6_connected())
#endif
        (void)net_if_dormant_on(if_handle->netif);
}

static void dhcp_timer_cb(osa_timer_arg_t arg)
{
    stop_cb(NULL);

    (void)wlan_wlcmgr_send_msg(WIFI_EVENT_NET_DHCP_CONFIG, WIFI_EVENT_REASON_FAILURE, NULL);
}

void net_interface_up(void *intrfc_handle)
{
    /* case 1: start uap/ connect to uap firstly.
    When init sta/uap interface, the flag of iface->if_dev->flags is initialized to NET_IF_LOWER_UP.
    Function update_operational_state()(zephyr function) will be called by net_if_up(). Only iface->if_dev->flags
    is NET_IF_LOWER_UP, can call notify_iface_up() to start interface.
    iface->if_dev->oper_state will be set to NET_IF_OPER_UP.
    Function net_eth_carrier_on() will submit carrier_work to work queue, then net_if_carrier_on() is called.
    net_if_carrier_on() also call update_operational_state(), but don't start interface repeatedly because
    iface->if_dev->oper_state has been NET_IF_OPER_UP.

    case 2: stop uap then start uap again / disconnect to uap then connect to uap.
    When stop uap or disconnect to uap,  net_eth_carrier_off() will be called in zephyr wifi drvier glue
    file(nxp_wifi_drv.c). The flag of iface->if_dev->flags will be cleared. If only call net_if_up(),
    update_operational_state() will return early. So can't start interface.
    We can set iface->if_dev->flags to NET_IF_LOWER_UP by calling net_eth_carrier_on() to start interface.

    Can't delete net_if_up() here, beacuse in addtion to start interface, net_if_up() will also perform other
    initilization work.*/

    net_if_dormant_off(((interface_t *)intrfc_handle)->netif);
}

void net_interface_down(void *intrfc_handle)
{
    /** includes dhcpv4 stop and ipv6 clear,
     *  for static IP case, we do not clear IP addr
     */
    net_if_dormant_on(((interface_t *)intrfc_handle)->netif);
}

void net_interface_dhcp_stop(void *intrfc_handle)
{
    net_dhcpv4_stop(((interface_t *)intrfc_handle)->netif);
}

static void ipv4_mcast_add(struct net_mgmt_event_callback *cb, struct net_if *iface)
{
    igmp_mac_filter((struct netif *)iface, cb->info, NET_IF_ADD_MAC_FILTER);
}

static void ipv4_mcast_delete(struct net_mgmt_event_callback *cb, struct net_if *iface)
{
    igmp_mac_filter((struct netif *)iface, cb->info, NET_IF_DEL_MAC_FILTER);
}

#if CONFIG_IPV6
static void ipv6_mcast_add(struct net_mgmt_event_callback *cb, struct net_if *iface)
{
    mld_mac_filter((struct netif *)iface, cb->info, NET_IF_ADD_MAC_FILTER);
}

static void ipv6_mcast_delete(struct net_mgmt_event_callback *cb, struct net_if *iface)
{
    mld_mac_filter((struct netif *)iface, cb->info, NET_IF_DEL_MAC_FILTER);
}
#endif

static void wifi_net_event_handler(struct net_mgmt_event_callback *cb, uint64_t mgmt_event, struct net_if *iface)
{
    // const struct wifi_status *status = (const struct wifi_status *)cb->info;
    enum wifi_event_reason wifi_event_reason;

    switch (mgmt_event)
    {
        case NET_EVENT_IPV4_DHCP_BOUND:
            wifi_event_reason = WIFI_EVENT_REASON_SUCCESS;
            wlan_wlcmgr_send_msg(WIFI_EVENT_NET_DHCP_CONFIG, wifi_event_reason, NULL);
            break;
        case NET_EVENT_IPV4_MADDR_ADD:
            ipv4_mcast_add(cb, iface);
            break;
        case NET_EVENT_IPV4_MADDR_DEL:
            ipv4_mcast_delete(cb, iface);
            break;
#if CONFIG_IPV6
        case NET_EVENT_IPV6_MADDR_ADD:
            ipv6_mcast_add(cb, iface);
            break;
        case NET_EVENT_IPV6_MADDR_DEL:
            ipv6_mcast_delete(cb, iface);
            break;
        case NET_EVENT_IPV6_DAD_SUCCEED:
            net_d("Receive zephyr ipv6 dad finished event.");
#if UAP_SUPPORT && !CONFIG_WIFI_NM_HOSTAPD_AP
            /*Wi-Fi driver will recevie NET_EVENT_IPV6_DAD_SUCCEED from zephyr kernel after IPV6 DAD finished.
            Can notify wlcmgr_task task to get address.*/
            (void)wlan_wlcmgr_send_msg(WIFI_EVENT_UAP_NET_ADDR_CONFIG, WIFI_EVENT_REASON_SUCCESS, NULL);
#endif
            break;
        case NET_EVENT_IPV6_ADDR_ADD:
            net_d("Receive zephyr ipv6 address added event.");
            break;
#endif
#if CONFIG_WIFI_NM_WPA_SUPPLICANT
        case NET_EVENT_SUPPLICANT_READY:
            set_supp_ready_state(1);
            break;
        case NET_EVENT_SUPPLICANT_NOT_READY:
            set_supp_ready_state(0);
            break;
#endif
        default:
            net_d("Unhandled net event: %x", mgmt_event);
            break;
    }
}

int net_configure_address(struct net_ip_config *addr, void *intrfc_handle)
{
    if (addr == NULL)
    {
        return -WM_E_INVAL;
    }
    if (intrfc_handle == NULL)
    {
        return -WM_E_INVAL;
    }

    interface_t *if_handle = (interface_t *)intrfc_handle;

#if CONFIG_P2P
    net_d("configuring interface %s (with %s)", (if_handle == &g_mlan) ? "mlan" : (if_handle == &g_uap) ? "uap" : "wfd",
          (addr->ipv4.addr_type == NET_ADDR_TYPE_DHCP) ? "DHCP client" : "Static IP");
#else
    net_d("configuring interface %s (with %s)", (if_handle == &g_mlan) ? "mlan" : "uap",
          (addr->ipv4.addr_type == NET_ADDR_TYPE_DHCP) ? "DHCP client" : "Static IP");
#endif

    if (if_handle == &g_mlan)
    {
        net_if_set_default(if_handle->netif);
    }

    switch (addr->ipv4.addr_type)
    {
        case NET_ADDR_TYPE_STATIC:
            NET_IPV4_ADDR_U32(if_handle->ipaddr) = addr->ipv4.address;
            NET_IPV4_ADDR_U32(if_handle->nmask)  = addr->ipv4.netmask;
            NET_IPV4_ADDR_U32(if_handle->gw)     = addr->ipv4.gw;
            net_if_ipv4_addr_add(if_handle->netif, &if_handle->ipaddr.in_addr, NET_ADDR_MANUAL, 0);
            net_if_ipv4_set_gw(if_handle->netif, &if_handle->gw.in_addr);
            net_if_ipv4_set_netmask_by_addr(if_handle->netif, &if_handle->ipaddr.in_addr, &if_handle->nmask.in_addr);
            break;
        case NET_ADDR_TYPE_DHCP:
            (void)OSA_TimerActivate((osa_timer_handle_t)dhcp_timer);
            net_dhcpv4_restart(if_handle->netif);
            break;
        case NET_ADDR_TYPE_LLA:
            /* For dhcp, instead of netifapi_netif_set_up, a
               netifapi_dhcp_start() call will be used */
            net_e("Not supported as of now...");
            break;
        default:
            net_d("Unexpected addr type");
            break;
    }
    /* Finally this should send the following event. */
    if ((if_handle == &g_mlan)
#if CONFIG_P2P
        || ((if_handle == &g_wfd) && (netif_get_bss_type() == BSS_TYPE_STA))
#endif
    )
    {
#if CONFIG_IPV6
        (void)wlan_wlcmgr_send_msg(WIFI_EVENT_NET_IPV6_CONFIG, WIFI_EVENT_REASON_SUCCESS, NULL);
#endif
        (void)wlan_wlcmgr_send_msg(WIFI_EVENT_NET_STA_ADDR_CONFIG, WIFI_EVENT_REASON_SUCCESS, NULL);

        /* XXX For DHCP, the above event will only indicate that the
         * DHCP address obtaining process has started. Once the DHCP
         * address has been obtained, another event,
         * WD_EVENT_NET_DHCP_CONFIG, should be sent to the wlcmgr.
         */
    }
#if UAP_SUPPORT
    else if (if_handle == &g_uap
#if CONFIG_P2P
        || ((if_handle == &g_wfd) && (netif_get_bss_type() == BSS_TYPE_UAP))
#endif
    )
    {
        /*For g_uap interface, notify wlcmgr_task task to get address only after receiving DAD finished event from
         * zephyr.*/
        net_if_dormant_off(if_handle->netif);
    }
#endif
    else
    { /* Do Nothing */
    }

    return WM_SUCCESS;
}

int net_get_if_addr(struct net_ip_config *addr, void *intrfc_handle)
{
    interface_t *if_handle   = (interface_t *)intrfc_handle;
    struct net_if_ipv4 *ipv4 = if_handle->netif->config.ip.ipv4;

    addr->ipv4.address = NET_IPV4_ADDR_U32(ipv4->unicast[0].ipv4.address);
    addr->ipv4.netmask = ipv4->unicast[0].netmask.s_addr;
    addr->ipv4.gw      = ipv4->gw.s_addr;

#if (CONFIG_DNS_RESOLVER)
    struct dns_resolve_context *ctx;

    /* DNS status */
    ctx = dns_resolve_get_default();
    if (ctx)
    {
        int i;

        for (i = 0; i < CONFIG_DNS_RESOLVER_MAX_SERVERS; i++)
        {
            if (ctx->servers[i].dns_server.sa_family == AF_INET)
            {
                if (i == 0)
                {
                    addr->ipv4.dns1 = net_sin(&ctx->servers[i].dns_server)->sin_addr.s_addr;
                }
                if (i == 1)
                {
                    addr->ipv4.dns2 = net_sin(&ctx->servers[i].dns_server)->sin_addr.s_addr;
                }
            }
        }
    }
#endif

    return WM_SUCCESS;
}

#if CONFIG_IPV6
char *ipv6_addr_state_to_desc(unsigned char addr_state)
{
    if (addr_state == NET_ADDR_TENTATIVE)
    {
        return IPV6_ADDR_STATE_TENTATIVE;
    }
    else if (addr_state == NET_ADDR_PREFERRED)
    {
        return IPV6_ADDR_STATE_PREFERRED;
    }
    else if (addr_state == NET_ADDR_DEPRECATED)
    {
        return IPV6_ADDR_STATE_DEPRECATED;
    }
    else
    {
        return IPV6_ADDR_UNKNOWN;
    }
}

char *info = NULL;
char extra_info[NET_IPV6_ADDR_LEN];

char *ipv6_addr_addr_to_desc(struct net_ipv6_config *ipv6_conf)
{
    struct in6_addr ip6_addr;

    (void)memcpy((void *)&ip6_addr, (const void *)ipv6_conf->address, sizeof(ip6_addr));

    info = net_addr_ntop(AF_INET6, &ip6_addr, extra_info, NET_IPV6_ADDR_LEN);

    return info;
}

char *ipv6_addr_type_to_desc(struct net_ipv6_config *ipv6_conf)
{
    struct in6_addr ip6_addr;

    (void)memcpy((void *)&ip6_addr, (const void *)ipv6_conf->address, sizeof(ip6_addr));

    if (net_ipv6_is_ll_addr(&ip6_addr))
    {
        return IPV6_ADDR_TYPE_LINKLOCAL;
    }
    else if (net_ipv6_is_global_addr(&ip6_addr))
    {
        return IPV6_ADDR_TYPE_GLOBAL;
    }
    else if (net_ipv6_is_ula_addr(&ip6_addr))
    {
        return IPV6_ADDR_TYPE_UNIQUELOCAL;
    }
    else if (net_ipv6_is_ll_addr(&ip6_addr))
    {
        return IPV6_ADDR_TYPE_SITELOCAL;
    }
    else
    {
        return IPV6_ADDR_UNKNOWN;
    }
}

int net_get_if_ipv6_addr(struct net_ip_config *addr, void *intrfc_handle)
{
    interface_t *if_handle = (interface_t *)intrfc_handle;
    int i;
    struct net_if_ipv6 *ipv6;
    struct net_if_addr *unicast;

    ipv6 = if_handle->netif->config.ip.ipv6;

    addr->ipv6_count = 0;

    for (i = 0; ipv6 && i < CONFIG_MAX_IPV6_ADDRESSES; i++)
    {
        unicast = &ipv6->unicast[i];

        if (!unicast->is_used)
        {
            continue;
        }

        (void)memcpy(addr->ipv6[i].address, &unicast->address.in6_addr, 16);
        addr->ipv6[i].addr_type  = unicast->addr_type;
        addr->ipv6[i].addr_state = unicast->addr_state;
        addr->ipv6_count++;
    }
    /* TODO carry out more processing based on IPv6 fields in netif */
    return WM_SUCCESS;
}

int net_get_if_ipv6_pref_addr(struct net_ip_config *addr, void *intrfc_handle)
{
    int i, ret = 0;
    interface_t *if_handle = (interface_t *)intrfc_handle;
    struct net_if_ipv6 *ipv6;
    struct net_if_addr *unicast;
    // struct net_if_mcast_addr *mcast;

    ipv6 = if_handle->netif->config.ip.ipv6;

    addr->ipv6_count = 0;

    for (i = 0; ipv6 && i < CONFIG_MAX_IPV6_ADDRESSES; i++)
    {
        unicast = &ipv6->unicast[i];

        if (!unicast->is_used)
        {
            continue;
        }

        if (unicast->addr_state == NET_ADDR_PREFERRED)
        {
            (void)memcpy(addr->ipv6[ret++].address, &unicast->address.in6_addr, 16);
            addr->ipv6_count++;
        }
    }
    return ret;
}

static void net_clear_ipv6_ll_address(void *intrfc_handle)
{
    struct net_if *iface = ((interface_t *)intrfc_handle)->netif;

    if (iface == NULL)
    {
        return;
    }

    /* We need to remove the old IPv6 link layer address, that is
     * generated from old MAC address, from network interface if
     * needed.
     */
    if (IS_ENABLED(CONFIG_NET_NATIVE_IPV6))
    {
        struct in6_addr iid;

        net_ipv6_addr_create_iid(&iid, net_if_get_link_addr(iface));

        /* No need to check the return value in this case. It
         * is not an error if the address is not found atm.
         */
        (void)net_if_ipv6_addr_rm(iface, &iid);
    }
}
#endif /* CONFIG_IPV6 */

int net_get_if_name(char *pif_name, void *intrfc_handle)
{
    interface_t *if_handle   = (interface_t *)intrfc_handle;
    const struct device *dev = NULL;
    dev                      = net_if_get_device((struct net_if *)if_handle->netif);
    strncpy(pif_name, dev->name, NETIF_NAMESIZE - 1);
    pif_name[NETIF_NAMESIZE - 1] = '\0';

    return WM_SUCCESS;
}

int net_get_if_ip_addr(uint32_t *ip, void *intrfc_handle)
{
    interface_t *if_handle   = (interface_t *)intrfc_handle;
    struct net_if_ipv4 *ipv4 = if_handle->netif->config.ip.ipv4;

    *ip = NET_IPV4_ADDR_U32(ipv4->unicast[0].ipv4.address);
    return WM_SUCCESS;
}

int net_get_if_ip_mask(uint32_t *nm, void *intrfc_handle)
{
    interface_t *if_handle   = (interface_t *)intrfc_handle;
    struct net_if_ipv4 *ipv4 = if_handle->netif->config.ip.ipv4;

    *nm = ipv4->unicast[0].netmask.s_addr;
    return WM_SUCCESS;
}

void net_configure_dns(struct net_ip_config *ip, unsigned int role)
{
    if (ip->ipv4.addr_type == NET_ADDR_TYPE_STATIC)
    {
        if (role != WLAN_BSS_ROLE_UAP)
        {
            if (ip->ipv4.dns1 == 0U)
            {
                ip->ipv4.dns1 = ip->ipv4.gw;
            }
            if (ip->ipv4.dns2 == 0U)
            {
                ip->ipv4.dns2 = ip->ipv4.dns1;
            }
        }
        /* TODO: DNS server */
#if 0
        ip4_addr_t tmp;

        tmp.addr = ip->ipv4.dns1;
        dns_setserver(0, (ip_addr_t *)(void *)&tmp);
        tmp.addr = ip->ipv4.dns2;
        dns_setserver(1, (ip_addr_t *)(void *)&tmp);
#endif
    }
}

void net_stat(void)
{
    // net_print_statistics();
}

static void setup_mgmt_events(void)
{
    net_mgmt_init_event_callback(&net_event_v4_cb, wifi_net_event_handler, MCASTV4_MASK | DHCPV4_MASK);

    net_mgmt_add_event_callback(&net_event_v4_cb);

#if CONFIG_IPV6
    net_mgmt_init_event_callback(&net_event_v6_cb, wifi_net_event_handler, MCASTV6_MASK | IPV6_MASK);

    net_mgmt_add_event_callback(&net_event_v6_cb);
#endif

#if CONFIG_WIFI_NM_WPA_SUPPLICANT
    net_mgmt_init_event_callback(&net_event_supp_cb, wifi_net_event_handler, NET_SUPP_MASK);

    net_mgmt_add_event_callback(&net_event_supp_cb);
#endif
}

static void cleanup_mgmt_events(void)
{
    net_mgmt_del_event_callback(&net_event_v4_cb);

#if CONFIG_IPV6
    net_mgmt_del_event_callback(&net_event_v6_cb);
#endif

#if CONFIG_WIFI_NM_WPA_SUPPLICANT
    net_mgmt_del_event_callback(&net_event_supp_cb);
#endif

}

int net_wlan_init(void)
{
    int ret;
    osa_status_t status;

    wifi_register_data_input_callback(&handle_data_packet);
    wifi_register_amsdu_data_input_callback(&handle_amsdu_data_packet);
    wifi_register_deliver_packet_above_callback(&handle_deliver_packet_above);
    wifi_register_wrapper_net_is_ip_or_ipv6_callback(&wrapper_net_is_ip_or_ipv6);

    if (!net_wlan_init_done)
    {
        wifi_mac_addr_t mac_addr = {0};

        wifi_get_device_mac_addr(&mac_addr);
        wlan_set_mac_addr(&mac_addr.mac[0]);

        /* init STA netif */
        ret = wlan_get_mac_address(g_mlan.state.ethaddr.addr);
        if (ret != 0)
        {
            net_e("could not get STA wifi mac addr");
            return ret;
        }

        net_if_set_link_addr(g_mlan.netif, g_mlan.state.ethaddr.addr, NET_MAC_ADDR_LEN, NET_LINK_ETHERNET);
        ethernet_init(g_mlan.netif);

#if CONFIG_WIFI_SOFTAP_SUPPORT
        /* init uAP netif */
        ret = wlan_get_mac_address_uap(g_uap.state.ethaddr.addr);
        if (ret != 0)
        {
            net_e("could not get uAP wifi mac addr");
            return ret;
        }

        net_if_set_link_addr(g_uap.netif, g_uap.state.ethaddr.addr, NET_MAC_ADDR_LEN, NET_LINK_ETHERNET);
        ethernet_init(g_uap.netif);
#endif
        net_wlan_init_done = 1;

        status = OSA_TimerCreate((osa_timer_handle_t)dhcp_timer, MSEC_TO_TICK(DHCP_TIMEOUT), &dhcp_timer_cb, NULL, KOSA_TimerOnce,
                                 OSA_TIMER_NO_ACTIVATE);
        if (status != KOSA_StatusSuccess)
        {
            net_e("Unable to start dhcp timer");
            return -WM_FAIL;
        }
    }

    setup_mgmt_events();

    net_d("Initialized TCP/IP networking stack");
    wlan_wlcmgr_send_msg(WIFI_EVENT_NET_INTERFACE_CONFIG, WIFI_EVENT_REASON_SUCCESS, NULL);
    return WM_SUCCESS;
}

void net_wlan_set_mac_address(unsigned char *sta_mac, unsigned char *uap_mac)
{
    if (sta_mac != NULL)
    {
#if CONFIG_IPV6
        net_clear_ipv6_ll_address(&g_mlan);
#endif
        (void)memcpy(g_mlan.state.ethaddr.addr, &sta_mac[0], MLAN_MAC_ADDR_LENGTH);
        net_if_set_link_addr(g_mlan.netif, g_mlan.state.ethaddr.addr, NET_MAC_ADDR_LEN, NET_LINK_ETHERNET);
    }

#if CONFIG_WIFI_SOFTAP_SUPPORT
    if (uap_mac != NULL)
    {
#if CONFIG_IPV6
        net_clear_ipv6_ll_address(&g_uap);
#endif
        (void)memcpy(g_uap.state.ethaddr.addr, &uap_mac[0], MLAN_MAC_ADDR_LENGTH);
        net_if_set_link_addr(g_uap.netif, g_uap.state.ethaddr.addr, NET_MAC_ADDR_LEN, NET_LINK_ETHERNET);
    }
#endif
}

static int net_netif_deinit(struct net_if *netif)
{
#if 0
    int ret;
#if CONFIG_IPV6
    if (netif->mld_mac_filter != NULL)
    {
        ip6_addr_t ip6_allnodes_ll;
        ip6_addr_set_allnodes_linklocal(&ip6_allnodes_ll);
        (void)netif->mld_mac_filter(netif, &ip6_allnodes_ll, NETIF_DEL_MAC_FILTER);
    }
#endif
    ret = netifapi_netif_remove(netif);

    if (ret != WM_SUCCESS)
    {
        net_e("Interface remove failed");
        return -WM_FAIL;
    }

    if (netif->state != NULL)
    {
#if !CONFIG_WPA_SUPP
        mem_free(netif->state);
#endif
        netif->state = NULL;
    }
#endif
#if CONFIG_NET_STATISTICS_WIFI
    const struct device *dev = net_if_get_device(netif);
    struct interface *if_handle = (struct interface *)dev->data;

    if (dev && if_handle)
    {
        memset(&if_handle->stats, 0, sizeof(if_handle->stats));
    }
#endif
    return WM_SUCCESS;
}

int net_wlan_deinit(void)
{
    int ret;
    osa_status_t status;

    if (net_wlan_init_done != 1)
    {
        return -WM_FAIL;
    }

    ret = net_netif_deinit(g_mlan.netif);
    if (ret != WM_SUCCESS)
    {
        net_e("MLAN interface deinit failed");
        return -WM_FAIL;
    }

#if CONFIG_WIFI_SOFTAP_SUPPORT
    ret = net_netif_deinit(g_uap.netif);
    if (ret != WM_SUCCESS)
    {
        net_e("UAP interface deinit failed");
        return -WM_FAIL;
    }
#endif
    status = OSA_TimerDestroy((osa_timer_handle_t)dhcp_timer);
    if (status != KOSA_StatusSuccess)
    {
        net_e("DHCP timer deletion failed");
        return -WM_FAIL;
    }

    cleanup_mgmt_events();

    net_wlan_init_done = 0;

    net_d("DeInitialized TCP/IP networking stack");

    return WM_SUCCESS;
}

const struct netif *net_if_get_binding(const char *ifname)
{
    struct netif *iface      = NULL;
    const struct device *dev = NULL;

    dev = device_get_binding(ifname);
    if (!dev)
    {
        return NULL;
    }

    iface = (struct netif *)net_if_lookup_by_dev(dev);
    if (!iface)
    {
        return NULL;
    }

    return iface;
}

int net_stack_buffer_copy_partial(void *stack_buffer, void *dst, uint16_t len, uint16_t offset)
{
    struct net_buf *frag = NULL;
    uint16_t left = 0, total_copied = 0, copy_buf_len;

    for (frag = ((struct net_pkt *)stack_buffer)->frags; len != 0 && frag != NULL; frag = frag->frags)
    {
        if ((offset != 0) && (offset >= frag->len))
        {
            offset = offset - frag->len;
        }
        else
        {
            copy_buf_len = frag->len - offset;
            if (copy_buf_len > len)
                copy_buf_len = len;

            memcpy(&((char *)dst)[left], &((char *)frag->data)[offset], copy_buf_len);
            total_copied = total_copied + copy_buf_len;
            left         = left + copy_buf_len;
            len          = len - copy_buf_len;
            offset       = 0;
        }
    }

    return total_copied;
}

#if CONFIG_TX_RX_ZERO_COPY
void net_tx_zerocopy_process_cb(void *destAddr, void *srcAddr, uint32_t len)
{
    outbuf_t *buf    = (outbuf_t *)srcAddr;
    t_u16 header_len = INTF_HEADER_LEN + sizeof(TxPD) + ETH_HDR_LEN;

    (void)memcpy((t_u8 *)destAddr, &buf->intf_header[0], header_len);
    net_pkt_read((struct net_pkt *)(buf->buffer), (t_u8 *)destAddr + header_len, (t_u16)(len - header_len));
}
#endif

