/** @file wifi_ping.c
 *
 *  @brief  This file provides the support for network utility ping
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* wifi_ping.c: This file contains the support for network utility ping */

#include <string.h>
#include <wm_os.h>
#include <wm_net.h>
#include <cli.h>
#include <cli_utils.h>
#include <wlan.h>
#include <wifi_ping.h>

static int ptotal = 0, precvd = 0;

#if defined(SDK_OS_FREE_RTOS)

static struct netif *get_netif_up(void)
{
    struct netif *netif = netif_list;
    for (; netif != NULL; netif = netif->next)
    {
        if ((netif_is_up(netif) != 0U) && (!((netif->name[0] == 'e') && (netif->name[1] == 'n'))))
        {
            return netif;
        }
    }
    return NULL;
}

static int addr_af(const ip_addr_t *addr)
{
#ifdef CONFIG_IPV6
    return (addr->type == IPADDR_TYPE_V4) ? AF_INET : AF_INET6;
#else
    return AF_INET;
#endif
}

static const ip_addr_t *get_src_addr(const ip_addr_t *dst)
{
    static ip_addr_t ret;
    const ip_addr_t *addr = NULL;
    struct netif *netif   = get_netif_up();
#ifdef CONFIG_IPV6
    bool is_ip_type_valid = MTRUE;
#endif

    if (netif == NULL)
    {
        return NULL;
    }

#ifdef CONFIG_IPV6
    switch (dst->type)
    {
        case IPADDR_TYPE_V4:
            addr = netif_ip_addr4(netif);
            (void)memcpy(&ret.u_addr.ip4, &addr->u_addr.ip4, sizeof(ret.u_addr.ip4));
            break;
        case IPADDR_TYPE_V6:
            addr = ip6_select_source_address(netif, &addr->u_addr.ip6);
            (void)memcpy(&ret.u_addr.ip6, &addr->u_addr.ip6, sizeof(ret.u_addr.ip6));
            break;
        default:
            is_ip_type_valid = MFALSE;
            break;
    }

    if (is_ip_type_valid == MFALSE)
    {
        return NULL;
    }

    ret.type = dst->type;
#else
    addr = netif_ip_addr4(netif);
    memcpy(&ret, addr, sizeof(ip_addr_t));
#endif
    return &ret;
}

/* Converts IPv4 or IPv6 address into static buffer and returns its pointer */
static const char *ip_to_str(const ip_addr_t *ipaddr)
{
    static char ip_str[50];

    if (inet_ntop(addr_af(ipaddr), ipaddr, ip_str, sizeof(ip_str)) == NULL)
    {
        ip_str[0] = '?';
        ip_str[1] = '\0';
    }

    return ip_str;
}

/* Display the final result of ping */
static void display_ping_result(const ip_addr_t *addr, int total, int recvd)
{
    int dropped = total - recvd;

    ptotal = total;
    precvd = recvd;

    (void)PRINTF("\r\n--- %s ping statistics ---\r\n", ip_to_str(addr));
    (void)PRINTF("%d packets transmitted, %d received,", total, recvd);
    if (dropped != 0)
    {
        (void)PRINTF(" +%d errors,", dropped);
    }
    (void)PRINTF(" %d%% packet loss\r\n", (dropped * 100) / total);
}

/* Display the statistics of the current iteration of ping */
static void display_ping_stats(int status, uint32_t size, const ip_addr_t *ipaddr, u16_t seqno, int ttl, uint32_t time)
{
    const char *ip_str = ip_to_str(ipaddr);

    if (status == WM_SUCCESS)
    {
        (void)PRINTF("%u bytes from %s: icmp_req=%u ttl=%u time=%u ms\r\n", size, ip_str, seqno, ttl, time);
    }
    else
    {
        (void)PRINTF("From %s icmp_seq=%u Destination Host Unreachable\r\n", ip_str, seqno);
    }
}

/* Display the usage of ping */
static void display_ping_usage(void)
{
    (void)PRINTF("Usage:\r\n");
    (void)PRINTF(
        "\tping [-s <packet_size>] [-c <packet_count>] "
#ifdef CONFIG_IPV6
        "[-W <timeout in sec>] <ipv4/ipv6 address>\r\n");
#else
        "[-W <timeout in sec>] <ipv4 address>\r\n");
#endif
    (void)PRINTF("Default values:\r\n");
    (void)PRINTF(
        "\tpacket_size: %u\r\n\tpacket_count: %u"
        "\r\n\ttimeout: %u sec\r\n",
        PING_DEFAULT_SIZE, PING_DEFAULT_COUNT, PING_DEFAULT_TIMEOUT_SEC);
}

/* Handle the ICMP echo response and extract required parameters */
static int ping_recv(int s, uint16_t seq_no, int *ttl)
{
    char buf[64];
    int fromlen = 0, len;
    struct sockaddr_in from;
    struct ip_hdr *iphdr;
    struct icmp_echo_hdr *iecho;
    int i = 0;

    while ((len = lwip_recvfrom(s, buf, sizeof(buf), 0, (struct sockaddr *)(void *)&from,
                                (socklen_t *)(void *)&fromlen)) > 0)
    {
        /* Received length should be greater than size of IP header and
         * size of ICMP header */
        if (len >= (int)(sizeof(struct ip_hdr) + sizeof(struct icmp_echo_hdr)))
        {
            iphdr = (struct ip_hdr *)(void *)buf;
            /* Calculate the offset of ICMP header */
            iecho = (struct icmp_echo_hdr *)(void *)(buf + (IPH_HL(iphdr) * 4U));

            /* Verify that the echo response is for the echo request
             * we sent by checking PING_ID and sequence number */
            if ((iecho->id == PING_ID) && (iecho->seqno == htons(seq_no)))
            {
                /* Extract TTL and send back so that it can be
                 * displayed in ping statistics */
                *ttl = (int)(iphdr->_ttl);
                return WM_SUCCESS;
            }
            else
            {
                /* Function raw_input may put multiple pieces of data in conn->recvmbox,
                 * waiting to select the data we want */
                i++;
                if (i > 10)
                {
                    return -WM_FAIL;
                }
            }
        }
    }
    /* Either len < 0 or the echo response verification unsuccessful */
    return -WM_FAIL;
}

#ifdef CONFIG_IPV6
/* Handle the ICMP6 echo response and extract required parameters */
static int ping6_recv(int s, uint16_t seq_no, int *ttl)
{
    char buf[64];
    int fromlen = 0, len;
    struct sockaddr_in6 from;
    struct ip6_hdr *iphdr;
    struct icmp_echo_hdr *iecho;

    while ((len = lwip_recvfrom(s, buf, sizeof(buf), 0, (struct sockaddr *)(void *)&from,
                                (socklen_t *)(void *)&fromlen)) > 0)
    {
        /* Received length should be greater than size of IP header and
         * size of ICMP header */
        if (len >= (int)(sizeof(struct ip6_hdr) + sizeof(struct icmp_echo_hdr)))
        {
            iphdr = (struct ip6_hdr *)(void *)buf;
            if (IP6H_NEXTH(iphdr) == IP6_NEXTH_ICMP6)
            {
                /* Calculate the offset of ICMP header */
                iecho = (struct icmp_echo_hdr *)(void *)(buf + sizeof(struct ip6_hdr));

                /* Verify that the echo response is for the echo request
                 * we sent by checking PING_ID, sequence number and ICMP type*/
                if ((iecho->id == PING_ID) && (iecho->seqno == htons(seq_no)) && (iecho->type == ICMP6_TYPE_EREP))
                {
                    /* Extract TTL and send back so that it can be
                     * displayed in ping statistics */
                    *ttl = IP6H_HOPLIM(iphdr);
                    return WM_SUCCESS;
                }
            }
        }
    }
    /* Either len < 0 or the echo response verification unsuccessful */
    return -WM_FAIL;
}
#endif

/* Prepare a ICMP echo request */
static void ping_prepare_echo(struct icmp_echo_hdr *iecho, const ip_addr_t *dest, uint16_t len, uint16_t seq_no)
{
    uint32_t i;
    uint32_t data_len = len - sizeof(struct icmp_echo_hdr);

#ifdef CONFIG_IPV6
    ICMPH_TYPE_SET(iecho, (dest->type == IPADDR_TYPE_V4) ? ICMP_ECHO : ICMP6_TYPE_EREQ);
#else
    ICMPH_TYPE_SET(iecho, ICMP_ECHO);
#endif
    ICMPH_CODE_SET(iecho, 0);
    iecho->chksum = 0;
    iecho->id     = PING_ID;
    iecho->seqno  = htons(seq_no);

    /* Fill the additional data buffer with some data */
    for (i = 0; i < data_len; i++)
    {
        ((char *)iecho)[sizeof(struct icmp_echo_hdr) + i] = (char)i;
    }
}

void ping_stats(int *total, int *recvd)
{
    *total = ptotal;
    *recvd = precvd;
}

/* Send an ICMP echo request, receive its response and print its statistics and
 * result */
int ping(u16_t count, int interval, unsigned short size, unsigned int r_timeout, ip_addr_t *addr)
{
    int ret = WM_SUCCESS, s, recvd = 0;
    u16_t i = 1;
    struct icmp_echo_hdr *iecho;
    unsigned int ping_time, ping_size;
    const ip_addr_t *ip_addr, *src_ip_addr;
    struct timeval timeout;

#ifdef CONFIG_IPV6
    struct netif *netif     = get_netif_up();
    const unsigned scope_id = netif_get_index(netif);
#endif
    const char *ip_str = ip_to_str(addr);

    (void)PRINTF("PING %s (%s) %u(%u) bytes of data\r\n", ip_str, ip_str, size,
                 size + sizeof(struct ip_hdr) + sizeof(struct icmp_echo_hdr));

    /* Create a raw socket */
#ifdef CONFIG_IPV6
    s = socket(addr_af(addr), SOCK_RAW, (addr->type == IPADDR_TYPE_V4) ? IPPROTO_ICMP : IPPROTO_ICMPV6);
#else
    s              = socket(addr_af(addr), SOCK_RAW, IPPROTO_ICMP);
#endif
    if (s < 0)
    {
        ping_e("Failed to create raw socket for ping %d", s);
        return -WM_FAIL;
    }
/* Convert timeout to milliseconds */
#if defined(__MCUXPRESSO)
    timeout.tv_sec = (time_t)(r_timeout);
#else
    timeout.tv_sec = (long)(r_timeout);
#endif

    timeout.tv_usec = 0;

    /* Set the socket timeout */
    ret = setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if (ret < 0)
    {
        ping_e("Failed to set socket options for ping");
        ret = -WM_FAIL;
        goto end;
    }

    /* Get the source IP address */
    src_ip_addr = get_src_addr(addr);

    /* Ping size is: size of ICMP header + size of payload */
    ping_size = sizeof(struct icmp_echo_hdr) + size;

    iecho = (struct icmp_echo_hdr *)os_mem_alloc(ping_size);
    if (iecho == NULL)
    {
        ping_e("Failed to allocate memory for ping packet");
        ret = -WM_FAIL;
        goto end;
    }

    while (i <= count)
    {
        ping_prepare_echo(iecho, addr, (uint16_t)ping_size, i);
#ifdef CONFIG_IPV6
        if (addr->type == IPADDR_TYPE_V4)
#endif
        {
            struct sockaddr_in to;
            to.sin_len    = (u8_t)sizeof(to);
            to.sin_family = AF_INET;
            inet_addr_from_ip4addr(&to.sin_addr, ip_2_ip4(addr));

            iecho->chksum = inet_chksum(iecho, ping_size);

            /* Send the ICMP echo request */
            ret = lwip_sendto(s, iecho, ping_size, 0, (struct sockaddr *)(void *)&to, sizeof(to));
        }
#ifdef CONFIG_IPV6
        else
        {
            struct sockaddr_in6 to;
            to.sin6_len      = sizeof(to);
            to.sin6_family   = AF_INET6;
            to.sin6_scope_id = scope_id;

            inet6_addr_from_ip6addr(&to.sin6_addr, ip_2_ip6(addr));

            /* Send the ICMP6 echo request */
            ret = lwip_sendto(s, iecho, ping_size, 0, (struct sockaddr *)(void *)&to, sizeof(to));
        }
#endif

        /* Get the current ticks as the start time */
        ping_time = os_ticks_get();

        if (ret > 0)
        {
            int ttl = 0;
            /* Receive the ICMP echo response */
#ifdef CONFIG_IPV6
            if (addr->type == IPADDR_TYPE_V4)
#endif
            {
                ret = ping_recv(s, (uint16_t)i, &ttl);
            }
#ifdef CONFIG_IPV6
            else
            {
                ret = ping6_recv(s, (uint16_t)i, &ttl);
            }
#endif

            /* Calculate the round trip time */
            ping_time = os_ticks_get() - ping_time;

            if (ret == WM_SUCCESS)
            {
                /* Increment the receive counter */
                recvd++;
                /* To display successful ping stats, destination
                 * IP address is required */
                ip_addr = addr;
            }
            else
            {
                /* To display unsuccessful ping stats, source
                 * IP address is required */
                ip_addr = src_ip_addr;
            }

            display_ping_stats(ret, ping_size, ip_addr, i, ttl, ping_time);
        }
        else
        {
            ping_e("Failed to send ping echo request");
            os_mem_free(iecho);
            ret = -WM_FAIL;
            goto end;
        }
        i++;
        os_thread_sleep(os_msec_to_ticks(interval));
    }
    os_mem_free(iecho);
    display_ping_result(src_ip_addr, (int)count, recvd);
end:
    (void)close(s);
    return ret;
}

static void cmd_ping(int argc, char **argv)
{
    ip_addr_t addr;
    int c;
    uint16_t size  = PING_DEFAULT_SIZE;
    uint16_t count = PING_DEFAULT_COUNT;
    uint32_t cnt, temp;
    uint32_t timeout = PING_DEFAULT_TIMEOUT_SEC;
    bool goto_end    = MFALSE;

    (void)memset(&addr, 0, sizeof(addr));

    /* If number of arguments is odd then print error */
    if ((argc & 0x01) != 0)
    {
        goto end;
    }

    cli_optind = 1;
    while ((c = cli_getopt(argc, argv, "c:s:W:")) != -1)
    {
        errno = 0;
        switch (c)
        {
            case 'c':
                cnt = strtoul(cli_optarg, NULL, 10);
                if (cnt > PING_MAX_COUNT)
                {
                    if (errno != 0)
                    {
                        (void)PRINTF("Error during strtoul errno:%d", errno);
                    }
                    (void)PRINTF(
                        "ping: count size too large: %u."
                        " Maximum is %u\r\n",
                        cnt, PING_MAX_COUNT);
                    return;
                }
                count = cnt;
                break;
            case 's':
                temp = strtoul(cli_optarg, NULL, 10);
                if (temp > PING_MAX_SIZE)
                {
                    if (errno != 0)
                    {
                        (void)PRINTF("Error during strtoul errno:%d", errno);
                    }
                    (void)PRINTF(
                        "ping: packet size too large: %u."
                        " Maximum is %u\r\n",
                        temp, PING_MAX_SIZE);
                    return;
                }
                size = (uint16_t)temp;
                break;
            case 'W':
                timeout = strtoul(cli_optarg, NULL, 10);
                break;
            default:
                goto_end = MTRUE;
                break;
        }
        if (goto_end == MTRUE)
        {
            goto end;
        }
        if (errno != 0)
        {
            (void)PRINTF("Error during strtoul errno:%d", errno);
        }
    }
    if (cli_optind == argc)
    {
        goto end;
    }

    /* Extract the destination IP address. This function returns non zero on
     * success, zero on failure */
    if (inet_pton(AF_INET, argv[cli_optind], &addr) != 0)
    {
#ifdef CONFIG_IPV6
        addr.type = IPADDR_TYPE_V4;
#endif
        (void)ping(count, PING_INTERVAL, size, timeout, &addr);
        return;
    }
#ifdef CONFIG_IPV6
    else if (inet_pton(AF_INET6, argv[cli_optind], &addr) != 0)
    {
        addr.type = IPADDR_TYPE_V6;
        (void)ping(count, PING_INTERVAL, size, timeout, &addr);
        return;
    }
#endif
    else
    {
        /*Do Nothing*/
    }

end:
    (void)PRINTF("Incorrect usage\r\n");
    display_ping_usage();
}
#elif __ZEPHYR__

#include <stdlib.h>
#include <stdio.h>
#include <zephyr/random/random.h>
#include <zephyr/net/icmp.h>

#include <ipv6.h>
#include <icmpv6.h>
#include <icmpv4.h>
#include <route.h>

extern char *net_sprint_addr(sa_family_t af, const void *addr);

#if defined(CONFIG_NET_IP)

static struct ping_context {
	struct k_work_delayable work;
	struct net_icmp_ctx icmp;
	union {
		struct sockaddr_in addr4;
		struct sockaddr_in6 addr6;
		struct sockaddr addr;
	};
	struct net_if *iface;

	/* Ping parameters */
	uint32_t count;
	uint32_t interval;
	uint32_t sequence;
	uint16_t payload_size;
	uint8_t tos;
	int priority;
} ping_ctx;

static void ping_done(struct ping_context *ctx);

#if defined(CONFIG_NET_NATIVE_IPV6)

static int handle_ipv6_echo_reply(struct net_icmp_ctx *ctx,
				  struct net_pkt *pkt,
				  struct net_icmp_ip_hdr *hdr,
				  struct net_icmp_hdr *icmp_hdr,
				  void *user_data)
{
	NET_PKT_DATA_ACCESS_CONTIGUOUS_DEFINE(icmp_access,
					      struct net_icmpv6_echo_req);
	struct net_ipv6_hdr *ip_hdr = hdr->ipv6;
	struct net_icmpv6_echo_req *icmp_echo;
	uint32_t cycles;
	char time_buf[16] = { 0 };

	icmp_echo = (struct net_icmpv6_echo_req *)net_pkt_get_data(pkt,
								&icmp_access);
	if (icmp_echo == NULL) {
		return -EIO;
	}

	net_pkt_skip(pkt, sizeof(*icmp_echo));

	if (net_pkt_remaining_data(pkt) >= sizeof(uint32_t)) {
		if (net_pkt_read_be32(pkt, &cycles)) {
			return -EIO;
		}

		cycles = k_cycle_get_32() - cycles;

		snprintf(time_buf, sizeof(time_buf),
#ifdef CONFIG_FPU
			 "time=%.2f ms",
			 (double)((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000.f)
#else
			 "time=%d ms",
			 ((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000)
#endif
			);
	}

	PRINTF("%d bytes from %s to %s: icmp_seq=%d ttl=%d "
#ifdef CONFIG_IEEE802154
		 "rssi=%d "
#endif
		 "%s\r\n",
		 ntohs(ip_hdr->len) - net_pkt_ipv6_ext_len(pkt) -
								NET_ICMPH_LEN,
		 net_sprint_addr(AF_INET6, &ip_hdr->src),
		 net_sprint_addr(AF_INET6, &ip_hdr->dst),
		 ntohs(icmp_echo->sequence),
		 ip_hdr->hop_limit,
#ifdef CONFIG_IEEE802154
		 net_pkt_ieee802154_rssi_dbm(pkt),
#endif
		 time_buf);

	if (ntohs(icmp_echo->sequence) == ping_ctx.count) {
		ping_done(&ping_ctx);
	}

	return 0;
}
#else
static int handle_ipv6_echo_reply(struct net_icmp_ctx *ctx,
				  struct net_pkt *pkt,
				  struct net_icmp_ip_hdr *hdr,
				  struct net_icmp_hdr *icmp_hdr,
				  void *user_data)
{
	ARG_UNUSED(ctx);
	ARG_UNUSED(pkt);
	ARG_UNUSED(hdr);
	ARG_UNUSED(icmp_hdr);
	ARG_UNUSED(user_data);

	return -ENOTSUP;
}
#endif /* CONFIG_NET_IPV6 */

#if defined(CONFIG_NET_NATIVE_IPV4)

static int handle_ipv4_echo_reply(struct net_icmp_ctx *ctx,
				  struct net_pkt *pkt,
				  struct net_icmp_ip_hdr *hdr,
				  struct net_icmp_hdr *icmp_hdr,
				  void *user_data)
{
	NET_PKT_DATA_ACCESS_CONTIGUOUS_DEFINE(icmp_access,
					      struct net_icmpv4_echo_req);
	struct net_ipv4_hdr *ip_hdr = hdr->ipv4;
	uint32_t cycles;
	struct net_icmpv4_echo_req *icmp_echo;
	char time_buf[16] = { 0 };

	icmp_echo = (struct net_icmpv4_echo_req *)net_pkt_get_data(pkt,
								&icmp_access);
	if (icmp_echo == NULL) {
		return -EIO;
	}

	net_pkt_skip(pkt, sizeof(*icmp_echo));

	if (net_pkt_remaining_data(pkt) >= sizeof(uint32_t)) {
		if (net_pkt_read_be32(pkt, &cycles)) {
			return -EIO;
		}

		cycles = k_cycle_get_32() - cycles;

		snprintf(time_buf, sizeof(time_buf),
#ifdef CONFIG_FPU
			 "time=%.2f ms",
			 (double)((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000.f)
#else
			 "time=%d ms",
			 ((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000)
#endif
			);
	}

    precvd++;

	PRINTF("%d bytes from %s to %s: icmp_seq=%d ttl=%d "
		 "%s\r\n",
		 ntohs(ip_hdr->len) - net_pkt_ipv6_ext_len(pkt) -
								NET_ICMPH_LEN,
		 net_sprint_addr(AF_INET, &ip_hdr->src),
		 net_sprint_addr(AF_INET, &ip_hdr->dst),
		 ntohs(icmp_echo->sequence),
		 ip_hdr->ttl,
		 time_buf);

	if (ntohs(icmp_echo->sequence) == ping_ctx.count) {
		ping_done(&ping_ctx);
	}

	return 0;
}
#else
static int handle_ipv4_echo_reply(struct net_icmp_ctx *ctx,
				  struct net_pkt *pkt,
				  struct net_icmp_ip_hdr *hdr,
				  struct net_icmp_hdr *icmp_hdr,
				  void *user_data)
{
	ARG_UNUSED(ctx);
	ARG_UNUSED(pkt);
	ARG_UNUSED(hdr);
	ARG_UNUSED(icmp_hdr);
	ARG_UNUSED(user_data);

	return -ENOTSUP;
}
#endif /* CONFIG_NET_IPV4 */

static int parse_arg(size_t *i, size_t argc, char *argv[])
{
	int res = -1;
	const char *str = argv[*i] + 2;
	char *endptr;

	if (*str == 0) {
		if (*i + 1 >= argc) {
			return -1;
		}

		*i += 1;
		str = argv[*i];
	}

	errno = 0;
	if (strncmp(str, "0x", 2) == 0) {
		res = strtol(str, &endptr, 16);
	} else {
		res = strtol(str, &endptr, 10);
	}

	if (errno || (endptr == str)) {
		return -1;
	}

	return res;
}

static void ping_cleanup(struct ping_context *ctx)
{
	(void)net_icmp_cleanup_ctx(&ctx->icmp);
}

static void ping_done(struct ping_context *ctx)
{
	k_work_cancel_delayable(&ctx->work);
	ping_cleanup(ctx);
}

void ping_stats(int *total, int *recvd)
{
    *total = ptotal;
    *recvd = precvd;
}

static void ping_work(struct k_work *work)
{
	struct k_work_delayable *dwork = k_work_delayable_from_work(work);
	struct ping_context *ctx =
			CONTAINER_OF(dwork, struct ping_context, work);
	struct net_icmp_ping_params params;
	int ret;

	ctx->sequence++;

	if (ctx->sequence > ctx->count) {
		PRINTF("Ping timeout\r\n");
		ping_done(ctx);
		return;
	}

	if (ctx->sequence < ctx->count) {
		k_work_reschedule(&ctx->work, K_MSEC(ctx->interval));
	} else {
		k_work_reschedule(&ctx->work, K_SECONDS(2));
	}

	params.identifier = sys_rand32_get();
	params.sequence = ctx->sequence;
	params.tc_tos = ctx->tos;
	params.priority = ctx->priority;
	params.data = NULL;
	params.data_size = ctx->payload_size;

    ptotal++;
	ret = net_icmp_send_echo_request(&ctx->icmp,
					 ctx->iface,
					 &ctx->addr,
					 &params,
					 ctx);
	if (ret != 0) {
		PRINTF("Failed to send ping, err: %d\r\n", ret);
		ping_done(ctx);
		return;
	}
}

#define ASCII_CTRL_C 0x03

static struct net_if *ping_select_iface(int id, struct sockaddr *target)
{
	struct net_if *iface = net_if_get_by_index(id);

	if (iface != NULL) {
		goto out;
	}

	if (IS_ENABLED(CONFIG_NET_IPV4) && target->sa_family == AF_INET) {
		iface = net_if_ipv4_select_src_iface(&net_sin(target)->sin_addr);
		if (iface != NULL) {
			goto out;
		}

		iface = net_if_get_default();
		goto out;
	}

	if (IS_ENABLED(CONFIG_NET_IPV6) && target->sa_family == AF_INET6) {
		struct net_nbr *nbr;
#if defined(CONFIG_NET_ROUTE)
		struct net_route_entry *route;
#endif

		iface = net_if_ipv6_select_src_iface(&net_sin6(target)->sin6_addr);
		if (iface != NULL) {
			goto out;
		}

		nbr = net_ipv6_nbr_lookup(NULL, &net_sin6(target)->sin6_addr);
		if (nbr) {
			iface = nbr->iface;
			goto out;
		}

#if defined(CONFIG_NET_ROUTE)
		route = net_route_lookup(NULL, &net_sin6(target)->sin6_addr);
		if (route) {
			iface = route->iface;
			goto out;
		}
#endif

		iface = net_if_get_default();
	}

out:
	return iface;
}

#endif /* CONFIG_NET_IP */

static void cmd_ping(int argc, char **argv)
{
#if !defined(CONFIG_NET_IPV4) && !defined(CONFIG_NET_IPV6)
	ARG_UNUSED(sh);
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	return;
#else
	char *host = NULL;

	int count = 10;
	int interval = 1000;
	int iface_idx = -1;
	int tos = 0;
	int payload_size = 4;
	int priority = -1;
	int ret;

	for (size_t i = 1; i < argc; ++i) {

		if (*argv[i] != '-') {
			host = argv[i];
			continue;
		}

		switch (argv[i][1]) {
		case 'c':
			count = parse_arg(&i, argc, argv);
			if (count < 0) {
				PRINTF("Parse error: %s\r\n", argv[i]);
				return;
			}


			break;
		case 'i':
			interval = parse_arg(&i, argc, argv);
			if (interval < 0) {
				PRINTF("Parse error: %s\r\n", argv[i]);
				return;
			}

			break;

		case 'I':
			iface_idx = parse_arg(&i, argc, argv);
			if (iface_idx < 0 || !net_if_get_by_index(iface_idx)) {
				PRINTF("Parse error: %s\r\n", argv[i]);
				return;
			}
			break;

		case 'p':
			priority = parse_arg(&i, argc, argv);
			if (priority < 0 || priority > UINT8_MAX) {
				PRINTF("Parse error: %s\r\n", argv[i]);
				return;
			}
			break;

		case 'Q':
			tos = parse_arg(&i, argc, argv);
			if (tos < 0 || tos > UINT8_MAX) {
				PRINTF("Parse error: %s\r\n", argv[i]);
				return;
			}

			break;

		case 's':
			payload_size = parse_arg(&i, argc, argv);
			if (payload_size < 0 || payload_size > UINT16_MAX) {
				PRINTF("Parse error: %s\r\n", argv[i]);
				return;
			}

			break;

		default:
			PRINTF("Unrecognized argument: %s\r\n", argv[i]);
			return;
		}
	}

	if (!host) {
		PRINTF("Target host missing\r\n");
		return;
	}

	memset(&ping_ctx, 0, sizeof(ping_ctx));

	k_work_init_delayable(&ping_ctx.work, ping_work);

	ping_ctx.count = count;
	ping_ctx.interval = interval;
	ping_ctx.priority = priority;
	ping_ctx.tos = tos;
	ping_ctx.payload_size = payload_size;

	if (IS_ENABLED(CONFIG_NET_IPV6) &&
	    net_addr_pton(AF_INET6, host, &ping_ctx.addr6.sin6_addr) == 0) {
		ping_ctx.addr6.sin6_family = AF_INET6;

		ret = net_icmp_init_ctx(&ping_ctx.icmp, NET_ICMPV6_ECHO_REPLY, 0,
					handle_ipv6_echo_reply);
		if (ret < 0) {
			PRINTF("Cannot initialize ICMP context for %s\r\n", "IPv6");
			return;
		}
	} else if (IS_ENABLED(CONFIG_NET_IPV4) &&
		   net_addr_pton(AF_INET, host, &ping_ctx.addr4.sin_addr) == 0) {
		ping_ctx.addr4.sin_family = AF_INET;

		ret = net_icmp_init_ctx(&ping_ctx.icmp, NET_ICMPV4_ECHO_REPLY, 0,
					handle_ipv4_echo_reply);
		if (ret < 0) {
			PRINTF("Cannot initialize ICMP context for %s\r\n", "IPv4");
			return;
		}
	} else {
		PRINTF("Invalid IP address\r\n");
		return;
	}

	ping_ctx.iface = ping_select_iface(iface_idx, &ping_ctx.addr);

	PRINTF("PING %s\r\n", host);

    ptotal = 0;
    precvd = 0;

	k_work_reschedule(&ping_ctx.work, K_NO_WAIT);
#endif
}

int ping(uint16_t count, int interval, unsigned short size, unsigned int r_timeout, const char *addr)
{
    int argc = 0;
    char argv[8][32];

    (void)r_timeout;

    strcpy(argv[argc++], "ping");

    if (count != 0)
    {
        strcpy(argv[argc++], "-c");
        sprintf(argv[argc++], "%d", count);
    }

    if (interval != 0)
    {
        strcpy(argv[argc++], "-i");
        sprintf(argv[argc++], "%d", interval);
    }

    if (size != 0)
    {
        strcpy(argv[argc++], "-s");
        sprintf(argv[argc++], "%d", size);
    }

    strcpy(argv[argc++], addr);

    cmd_ping(argc, (char **)argv);

    return WM_SUCCESS;
}

#if 0
SHELL_STATIC_SUBCMD_SET_CREATE(net_cmd_ping,
	SHELL_CMD(--help, NULL,
		  "'net ping [-c count] [-i interval ms] [-I <iface index>] "
		  "[-Q tos] [-s payload size] [-p priority] <host>' "
		  "Send ICMPv4 or ICMPv6 Echo-Request to a network host.",
		  cmd_net_ping),
	SHELL_SUBCMD_SET_END
);

SHELL_SUBCMD_ADD((net), ping, &net_cmd_ping,
		 "Ping a network host.",
		 cmd_net_ping, 1, 13);
#endif
#endif

static struct cli_command ping_cli[] = {
#if defined(SDK_OS_FREE_RTOS)
#ifdef CONFIG_IPV6
    {"ping", "[-s <packet_size>] [-c <packet_count>] [-W <timeout in sec>] <ipv4/ipv6 address>", cmd_ping},
#else
    {"ping", "[-s <packet_size>] [-c <packet_count>] [-W <timeout in sec>] <ipv4 address>", cmd_ping},
#endif
#elif __ZEPHYR__
#ifdef CONFIG_IPV6
    {"wlan-ping", "[-s <packet_size>] [-c <packet_count>] [-W <timeout in sec>] <ipv4/ipv6 address>", cmd_ping},
#else
    {"wlan-ping", "[-s <packet_size>] [-c <packet_count>] [-W <timeout in sec>] <ipv4 address>", cmd_ping},
#endif
#endif
};

int ping_cli_init(void)
{
    unsigned int i;
    for (i = 0; i < sizeof(ping_cli) / sizeof(struct cli_command); i++)
    {
        if (cli_register_command(&ping_cli[i]) != 0)
        {
            return -WM_FAIL;
        }
    }
    return WM_SUCCESS;
}

int ping_cli_deinit(void)
{
    unsigned int i;

    for (i = 0; i < sizeof(ping_cli) / sizeof(struct cli_command); i++)
    {
        if (cli_unregister_command(&ping_cli[i]) != 0)
        {
            return -WM_FAIL;
        }
    }
    return WM_SUCCESS;
}
