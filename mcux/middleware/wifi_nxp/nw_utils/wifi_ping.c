/** @file wifi_ping.c
 *
 *  @brief  This file provides the support for network utility ping
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* wifi_ping.c: This file contains the support for network utility ping */

#include <string.h>
#include <osa.h>
#include <wm_net.h>
#include <cli.h>
#include <cli_utils.h>
#include <wlan.h>
#include <wifi_ping.h>

static int ptotal = 0, precvd = 0;

#include <stdlib.h>
#include <stdio.h>
#include <zephyr/random/random.h>
#include <zephyr/net/icmp.h>

#include <ipv6.h>
#include <icmpv6.h>
#include <icmpv4.h>
#include <route.h>

extern char *net_sprint_addr(sa_family_t af, const void *addr);

#if (CONFIG_NET_IP)

static struct ping_context
{
    struct k_work_delayable work;
    struct net_icmp_ctx icmp;
    union
    {
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

#if (CONFIG_NET_NATIVE_IPV6)

static int handle_ipv6_echo_reply(struct net_icmp_ctx *ctx,
                                  struct net_pkt *pkt,
                                  struct net_icmp_ip_hdr *hdr,
                                  struct net_icmp_hdr *icmp_hdr,
                                  void *user_data)
{
    NET_PKT_DATA_ACCESS_CONTIGUOUS_DEFINE(icmp_access, struct net_icmpv6_echo_req);
    struct net_ipv6_hdr *ip_hdr = hdr->ipv6;
    struct net_icmpv6_echo_req *icmp_echo;
    uint32_t cycles;
    char time_buf[16] = {0};

    icmp_echo = (struct net_icmpv6_echo_req *)net_pkt_get_data(pkt, &icmp_access);
    if (icmp_echo == NULL)
    {
        return -EIO;
    }

    net_pkt_skip(pkt, sizeof(*icmp_echo));

    if (net_pkt_remaining_data(pkt) >= sizeof(uint32_t))
    {
        if (net_pkt_read_be32(pkt, &cycles))
        {
            return -EIO;
        }

        cycles = k_cycle_get_32() - cycles;

        snprintf(time_buf, sizeof(time_buf),
#if CONFIG_FPU
                 "time=%.2f ms", (double)((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000.f)
#else
                 "time=%d ms", ((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000)
#endif
        );
    }

    PRINTF(
        "%d bytes from %s to %s: icmp_seq=%d ttl=%d "
#if CONFIG_IEEE802154
        "rssi=%d "
#endif
        "%s\r\n",
        ntohs(ip_hdr->len) - net_pkt_ipv6_ext_len(pkt) - NET_ICMPH_LEN, net_sprint_addr(AF_INET6, &ip_hdr->src),
        net_sprint_addr(AF_INET6, &ip_hdr->dst), ntohs(icmp_echo->sequence), ip_hdr->hop_limit,
#if CONFIG_IEEE802154
        net_pkt_ieee802154_rssi_dbm(pkt),
#endif
        time_buf);

    if (ntohs(icmp_echo->sequence) == ping_ctx.count)
    {
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

#if (CONFIG_NET_NATIVE_IPV4)

static int handle_ipv4_echo_reply(struct net_icmp_ctx *ctx,
                                  struct net_pkt *pkt,
                                  struct net_icmp_ip_hdr *hdr,
                                  struct net_icmp_hdr *icmp_hdr,
                                  void *user_data)
{
    NET_PKT_DATA_ACCESS_CONTIGUOUS_DEFINE(icmp_access, struct net_icmpv4_echo_req);
    struct net_ipv4_hdr *ip_hdr = hdr->ipv4;
    uint32_t cycles;
    struct net_icmpv4_echo_req *icmp_echo;
    char time_buf[16] = {0};

    icmp_echo = (struct net_icmpv4_echo_req *)net_pkt_get_data(pkt, &icmp_access);
    if (icmp_echo == NULL)
    {
        return -EIO;
    }

    net_pkt_skip(pkt, sizeof(*icmp_echo));

    if (net_pkt_remaining_data(pkt) >= sizeof(uint32_t))
    {
        if (net_pkt_read_be32(pkt, &cycles))
        {
            return -EIO;
        }

        cycles = k_cycle_get_32() - cycles;

        snprintf(time_buf, sizeof(time_buf),
#if CONFIG_FPU
                 "time=%.2f ms", (double)((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000.f)
#else
                 "time=%d ms", ((uint32_t)k_cyc_to_ns_floor64(cycles) / 1000000)
#endif
        );
    }

    precvd++;

    PRINTF(
        "%d bytes from %s to %s: icmp_seq=%d ttl=%d "
        "%s\r\n",
        ntohs(ip_hdr->len) - net_pkt_ipv6_ext_len(pkt) - NET_ICMPH_LEN, net_sprint_addr(AF_INET, &ip_hdr->src),
        net_sprint_addr(AF_INET, &ip_hdr->dst), ntohs(icmp_echo->sequence), ip_hdr->ttl, time_buf);

    if (ntohs(icmp_echo->sequence) == ping_ctx.count)
    {
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
    int res         = -1;
    const char *str = argv[*i] + 2;
    char *endptr;

    if (*str == 0)
    {
        if (*i + 1 >= argc)
        {
            return -1;
        }

        *i += 1;
        str = argv[*i];
    }

    errno = 0;
    if (strncmp(str, "0x", 2) == 0)
    {
        res = strtol(str, &endptr, 16);
    }
    else
    {
        res = strtol(str, &endptr, 10);
    }

    if (errno || (endptr == str))
    {
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
    struct ping_context *ctx       = CONTAINER_OF(dwork, struct ping_context, work);
    struct net_icmp_ping_params params;
    int ret;

    ctx->sequence++;

    if (ctx->sequence > ctx->count)
    {
        PRINTF("Ping timeout\r\n");
        ping_done(ctx);
        return;
    }

    if (ctx->sequence < ctx->count)
    {
        k_work_reschedule(&ctx->work, K_MSEC(ctx->interval));
    }
    else
    {
        k_work_reschedule(&ctx->work, K_SECONDS(2));
    }

    params.identifier = sys_rand32_get();
    params.sequence   = ctx->sequence;
    params.tc_tos     = ctx->tos;
    params.priority   = ctx->priority;
    params.data       = NULL;
    params.data_size  = ctx->payload_size;

    ptotal++;
    ret = net_icmp_send_echo_request(&ctx->icmp, ctx->iface, &ctx->addr, &params, ctx);
    if (ret != 0)
    {
        PRINTF("Failed to send ping, err: %d\r\n", ret);
        ping_done(ctx);
        return;
    }
}

#define ASCII_CTRL_C 0x03

static struct net_if *ping_select_iface(int id, struct sockaddr *target)
{
    struct net_if *iface = net_if_get_by_index(id);

    if (iface != NULL)
    {
        goto out;
    }

    if (IS_ENABLED(CONFIG_NET_IPV4) && target->sa_family == AF_INET)
    {
        iface = net_if_ipv4_select_src_iface(&net_sin(target)->sin_addr);
        if (iface != NULL)
        {
            goto out;
        }

        iface = net_if_get_default();
        goto out;
    }

    if (IS_ENABLED(CONFIG_NET_IPV6) && target->sa_family == AF_INET6)
    {
        struct net_nbr *nbr;
#if (CONFIG_NET_ROUTE)
        struct net_route_entry *route;
#endif

        iface = net_if_ipv6_select_src_iface(&net_sin6(target)->sin6_addr);
        if (iface != NULL)
        {
            goto out;
        }

        nbr = net_ipv6_nbr_lookup(NULL, &net_sin6(target)->sin6_addr);
        if (nbr)
        {
            iface = nbr->iface;
            goto out;
        }

#if (CONFIG_NET_ROUTE)
        route = net_route_lookup(NULL, &net_sin6(target)->sin6_addr);
        if (route)
        {
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
#if !(CONFIG_NET_IPV4) && !(CONFIG_NET_IPV6)
    ARG_UNUSED(sh);
    ARG_UNUSED(argc);
    ARG_UNUSED(argv);

    return;
#else
    char *host = NULL;

    int count        = 10;
    int interval     = 1000;
    int iface_idx    = -1;
    int tos          = 0;
    int payload_size = 4;
    int priority     = -1;
    int ret;

    for (size_t i = 1; i < argc; ++i)
    {
        if (*argv[i] != '-')
        {
            host = argv[i];
            continue;
        }

        switch (argv[i][1])
        {
            case 'c':
                count = parse_arg(&i, argc, argv);
                if (count < 0)
                {
                    PRINTF("Parse error: %s\r\n", argv[i]);
                    return;
                }

                break;
            case 'i':
                interval = parse_arg(&i, argc, argv);
                if (interval < 0)
                {
                    PRINTF("Parse error: %s\r\n", argv[i]);
                    return;
                }

                break;

            case 'I':
                iface_idx = parse_arg(&i, argc, argv);
                if (iface_idx < 0 || !net_if_get_by_index(iface_idx))
                {
                    PRINTF("Parse error: %s\r\n", argv[i]);
                    return;
                }
                break;

            case 'p':
                priority = parse_arg(&i, argc, argv);
                if (priority < 0 || priority > UINT8_MAX)
                {
                    PRINTF("Parse error: %s\r\n", argv[i]);
                    return;
                }
                break;

            case 'Q':
                tos = parse_arg(&i, argc, argv);
                if (tos < 0 || tos > UINT8_MAX)
                {
                    PRINTF("Parse error: %s\r\n", argv[i]);
                    return;
                }

                break;

            case 's':
                payload_size = parse_arg(&i, argc, argv);
                if (payload_size < 0 || payload_size > UINT16_MAX)
                {
                    PRINTF("Parse error: %s\r\n", argv[i]);
                    return;
                }

                break;

            default:
                PRINTF("Unrecognized argument: %s\r\n", argv[i]);
                return;
        }
    }

    if (!host)
    {
        PRINTF("Target host missing\r\n");
        return;
    }

    memset(&ping_ctx, 0, sizeof(ping_ctx));

    k_work_init_delayable(&ping_ctx.work, ping_work);

    ping_ctx.count        = count;
    ping_ctx.interval     = interval;
    ping_ctx.priority     = priority;
    ping_ctx.tos          = tos;
    ping_ctx.payload_size = payload_size;

    if (IS_ENABLED(CONFIG_NET_IPV6) && net_addr_pton(AF_INET6, host, &ping_ctx.addr6.sin6_addr) == 0)
    {
        ping_ctx.addr6.sin6_family = AF_INET6;

        ret = net_icmp_init_ctx(&ping_ctx.icmp, NET_ICMPV6_ECHO_REPLY, 0, handle_ipv6_echo_reply);
        if (ret < 0)
        {
            PRINTF("Cannot initialize ICMP context for %s\r\n", "IPv6");
            return;
        }
    }
    else if (IS_ENABLED(CONFIG_NET_IPV4) && net_addr_pton(AF_INET, host, &ping_ctx.addr4.sin_addr) == 0)
    {
        ping_ctx.addr4.sin_family = AF_INET;

        ret = net_icmp_init_ctx(&ping_ctx.icmp, NET_ICMPV4_ECHO_REPLY, 0, handle_ipv4_echo_reply);
        if (ret < 0)
        {
            PRINTF("Cannot initialize ICMP context for %s\r\n", "IPv4");
            return;
        }
    }
    else
    {
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

static struct cli_command ping_cli[] = {
#if CONFIG_IPV6
    {"wlan-ping", "[-s <packet_size>] [-c <packet_count>] [-W <timeout in sec>] <ipv4/ipv6 address>", cmd_ping},
#else
    {"wlan-ping", "[-s <packet_size>] [-c <packet_count>] [-W <timeout in sec>] <ipv4 address>", cmd_ping},
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
