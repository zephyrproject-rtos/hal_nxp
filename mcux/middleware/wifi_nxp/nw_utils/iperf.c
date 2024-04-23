/** @file iperf.c
 *
 *  @brief  This file provides the support for network utility iperf
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* iperf.c: This file contains the support for network utility iperf */

#include <string.h>
#include <wm_os.h>
#include <wm_net.h>
#include <cli.h>
#include <cli_utils.h>
#include <wlan.h>

#include "iperf.h"
#include "lwiperf.h"
#include "lwip/tcpip.h"

#ifndef IPERF_UDP_CLIENT_RATE
#define IPERF_UDP_CLIENT_RATE (1 * 1024 * 1024) /* 1 Mbit/s */
#endif

#ifndef IPERF_CLIENT_AMOUNT
#define IPERF_CLIENT_AMOUNT (-1000) /* 10 seconds */
#endif

#define IPERF_UDP_DEFAULT_FACTOR 100

struct iperf_test_context
{
    bool server_mode;
    bool tcp;
    enum lwiperf_client_type client_type;
    void *iperf_session;
};

static struct iperf_test_context ctx;
static os_timer_t ptimer = NULL;
static ip_addr_t server_address;
static ip_addr_t bind_address;
#ifdef CONFIG_IPV6
static bool ipv6;
#endif
static int amount                   = IPERF_CLIENT_AMOUNT;
static unsigned int udp_rate_factor = IPERF_UDP_DEFAULT_FACTOR;
unsigned int buffer_len             = 0;
unsigned int port                   = LWIPERF_TCP_PORT_DEFAULT;
#ifdef CONFIG_WMM
uint8_t qos = 0;
#endif
static uint8_t mcast_mac[6];
static bool mcast_mac_valid;

static void timer_poll_udp_client(TimerHandle_t timer);
#if defined(CONFIG_WIFI_BLE_COEX_APP) && (CONFIG_WIFI_BLE_COEX_APP == 1)
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
extern void APP_SetTicklessIdle(bool enable);
bool disable_tickless_hook = false;
#endif
#endif
#endif

/* Report state => string */
const char *report_type_str[] = {
    "TCP_DONE_SERVER (RX)", /* LWIPERF_TCP_DONE_SERVER_RX,*/
    "TCP_DONE_SERVER (TX)", /* LWIPERF_TCP_DONE_SERVER_TX,*/
    "TCP_DONE_CLIENT (TX)", /* LWIPERF_TCP_DONE_CLIENT_TX,*/
    "TCP_DONE_CLIENT (RX)", /* LWIPERF_TCP_DONE_CLIENT_RX,*/
    "TCP_ABORTED_LOCAL",           /* LWIPERF_TCP_ABORTED_LOCAL, */
    "TCP_ABORTED_LOCAL_DATAERROR", /* LWIPERF_TCP_ABORTED_LOCAL_DATAERROR, */
    "TCP_ABORTED_LOCAL_TXERROR",   /* LWIPERF_TCP_ABORTED_LOCAL_TXERROR, */
    "TCP_ABORTED_REMOTE",          /* LWIPERF_TCP_ABORTED_REMOTE, */
    "UDP_DONE_SERVER (RX)",        /* LWIPERF_UDP_DONE_SERVER_RX, */
    "UDP_DONE_SERVER (TX)", /* LWIPERF_UDP_DONE_SERVER_TX, */
    "UDP_DONE_CLIENT (TX)", /* LWIPERF_UDP_DONE_CLIENT_TX, */
    "UDP_DONE_CLIENT (RX)", /* LWIPERF_UDP_DONE_CLIENT_RX, */
    "UDP_ABORTED_LOCAL",           /* LWIPERF_UDP_ABORTED_LOCAL, */
    "UDP_ABORTED_LOCAL_DATAERROR", /* LWIPERF_UDP_ABORTED_LOCAL_DATAERROR, */
    "UDP_ABORTED_LOCAL_TXERROR",   /* LWIPERF_UDP_ABORTED_LOCAL_TXERROR, */
    "UDP_ABORTED_REMOTE",          /* LWIPERF_UDP_ABORTED_REMOTE, */
};

#if defined(CONFIG_WIFI_BLE_COEX_APP) && (CONFIG_WIFI_BLE_COEX_APP == 1)
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
static void iperf_disable_tickless_hook(bool disable)
{
    if (disable == true)
    {
        if (disable_tickless_hook == false)
        {
            APP_SetTicklessIdle(false);
            disable_tickless_hook = true;
        }
    }
    else
    {
        if (disable_tickless_hook == true)
        {
            APP_SetTicklessIdle(true);
            disable_tickless_hook = false;
        }
    }
}

/**
 *  For server mode, we do not re-enable tickless idle in case client runs continuous multiple tests.
 *  For client mode, we re-enable tickless idle except for one case:
 *  We start a bidirectional test individually, first TX and then RX. In this case, for the first TX,
 *  we do not re-enable tickless idle and re-enable it after latter RX is done.
 */
static bool iperf_need_enable_tickless_idle(void *arg, enum lwiperf_report_type report_type)
{
    struct iperf_test_context *ctx = (struct iperf_test_context *)arg;

    if (!ctx)
        return true;

    if (ctx->server_mode)
        return false;
    else if (ctx->client_type == LWIPERF_TRADEOFF &&
             (report_type == LWIPERF_TCP_DONE_CLIENT_TX || report_type == LWIPERF_UDP_DONE_CLIENT_TX))
        return false;

    return true;
}
#endif
#endif
#endif

static void iperf_free_ctx_iperf_session(void *arg, enum lwiperf_report_type report_type)
{
    struct iperf_test_context *ctx = (struct iperf_test_context *)arg;

    if (!ctx || ctx->server_mode ||
        (ctx->client_type == LWIPERF_TRADEOFF &&
         (report_type == LWIPERF_TCP_DONE_CLIENT_TX || report_type == LWIPERF_UDP_DONE_CLIENT_TX)))
        return;

    ctx->iperf_session = NULL;
}

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
    if (arg == NULL)
    {
        (void)PRINTF("Unable to print iperf report\r\n");
        return;
    }
    (void)PRINTF("-------------------------------------------------\r\n");
    if (report_type < (enum lwiperf_report_type)(sizeof(report_type_str) / sizeof(report_type_str[0])))
    {
        (void)PRINTF(" %s \r\n", report_type_str[report_type]);
        if (local_addr != NULL && remote_addr != NULL)
        {
#ifdef CONFIG_IPV6
            if (ipv6)
            {
                (void)PRINTF(" Local address : %s ", inet6_ntoa(local_addr->u_addr.ip6));
            }
            else
#endif
            {
                (void)PRINTF(" Local address : %u.%u.%u.%u ", ((const u8_t *)local_addr)[0],
                             ((const u8_t *)local_addr)[1], ((const u8_t *)local_addr)[2],
                             ((const u8_t *)local_addr)[3]);
            }
            (void)PRINTF(" Port %d \r\n", local_port);
#ifdef CONFIG_IPV6
            if (ipv6)
            {
                (void)PRINTF(" Remote address : %s ", inet6_ntoa(remote_addr->u_addr.ip6));
            }
            else
#endif
            {
                (void)PRINTF(" Remote address : %u.%u.%u.%u ", ((const u8_t *)remote_addr)[0],
                             ((const u8_t *)remote_addr)[1], ((const u8_t *)remote_addr)[2],
                             ((const u8_t *)remote_addr)[3]);
            }
            (void)PRINTF(" Port %d \r\n", remote_port);
            (void)PRINTF(" Bytes Transferred %llu \r\n", bytes_transferred);
            (void)PRINTF(" Duration (ms) %d \r\n", ms_duration);
#if defined(RW610)
            (void)PRINTF(" Bandwidth (Mbitpsec) %.2f \r\n", (double)bandwidth_kbitpsec / 1000U);
#else
            (void)PRINTF(" Bandwidth (Mbitpsec) %d \r\n", bandwidth_kbitpsec / 1000U);
#endif
        }
    }
    else
    {
        (void)PRINTF(" IPERF Report error\r\n");
    }
    struct iperf_test_context *test_ctx = (struct iperf_test_context *)arg;
    if (test_ctx->server_mode == 0 && test_ctx->client_type != LWIPERF_DUAL)
    {
        os_timer_deactivate(&ptimer);
    }
    (void)PRINTF("\r\n");
    /*When test UDP individual bidirectional test,  DUT server should active ptimer to send packages after RX done.*/
    if (test_ctx->server_mode != 0 && test_ctx->client_type == LWIPERF_TRADEOFF)
    {
        if (report_type == LWIPERF_UDP_DONE_SERVER_RX)
        {
            os_timer_activate(&ptimer);
        }
        else
        {
            os_timer_deactivate(&ptimer);
        }
    }

    iperf_free_ctx_iperf_session(arg, report_type);
#if defined(CONFIG_WIFI_BLE_COEX_APP) || (CONFIG_WIFI_BLE_COEX_APP == 1)
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
    /* Re-enable Tickless Idle */
    if (iperf_need_enable_tickless_idle(arg, report_type))
        iperf_disable_tickless_hook(false);
#endif
#endif
#endif
}

/*!
 * @brief Function to start iperf test.
 */
static void iperf_test_start(void *arg)
{
    struct iperf_test_context *ctx = (struct iperf_test_context *)arg;
#ifdef CONFIG_IPV6
    struct netif *netiftmp  = NULL;
    struct netif *netifbind = NULL;
#endif

    if (ctx->iperf_session != NULL)
    {
        (void)PRINTF("Abort ongoing IPERF session\r\n");
        lwiperf_abort(ctx->iperf_session);
        ctx->iperf_session = NULL;
    }

#if defined(CONFIG_WIFI_BLE_COEX_APP) && (CONFIG_WIFI_BLE_COEX_APP == 1)
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
    /* Disable tickless idle when running iperf test */
    if (ctx->server_mode)
        (void)PRINTF("Please use iperf -a to close iperf after iperf server mode done\r\n");
    iperf_disable_tickless_hook(true);
#endif
#endif
#endif

    if ((ctx->server_mode == false) ||
        ((ctx->server_mode == true) && ((ctx->client_type == LWIPERF_REVERSE) || (ctx->client_type == LWIPERF_DUAL))))
    {
        os_timer_activate(&ptimer);
    }

    if (ctx->server_mode)
    {
        if (ctx->tcp)
        {
#ifdef CONFIG_IPV6
            if (ipv6)
            {
                ctx->iperf_session = lwiperf_start_tcp_server(IP6_ADDR_ANY, port, lwiperf_report, ctx);
            }
            else
#endif
            {
                ctx->iperf_session = lwiperf_start_tcp_server(IP_ADDR_ANY, port, lwiperf_report, ctx);
            }
        }
        else
        {
#ifdef CONFIG_IPV6
            if (ipv6)
            {
                ctx->iperf_session = lwiperf_start_udp_server(IP6_ADDR_ANY, port, lwiperf_report, ctx);
            }
            else
#endif
            {
                ctx->iperf_session = lwiperf_start_udp_server(&bind_address, port, lwiperf_report, ctx);
            }
        }
    }
    else
    {
        if (ctx->tcp)
        {
#ifdef CONFIG_IPV6
            if (ipv6)
            {
                NETIF_FOREACH(netiftmp)
                {
                    if ((netif_get_ip6_addr_match(netiftmp, ip_2_ip6(&bind_address)) >= 0) && netif_is_up(netiftmp))
                    {
                        netifbind = netiftmp;
                        break;
                    }
                }
                if (!netifbind)
                {
                    (void)PRINTF("Could not find correspinding netif by bind_address\r\n");
                    lwiperf_abort(ctx->iperf_session);
                    ctx->iperf_session = NULL;
                    return;
                }
                ip6_addr_assign_zone(ip_2_ip6(&server_address), IP6_UNICAST, netifbind);
            }
#endif
            ctx->iperf_session = lwiperf_start_tcp_client(&server_address, port, ctx->client_type, amount, buffer_len,
#ifdef CONFIG_WMM
                                                          qos,
#else
                                                          0,
#endif
                                                          lwiperf_report, ctx);
        }
        else
        {
#ifdef CONFIG_IPV6
            if (ipv6)
            {
                ctx->iperf_session =
                    lwiperf_start_udp_client(&bind_address, port, &server_address, port, ctx->client_type, amount,
                                             buffer_len, IPERF_UDP_CLIENT_RATE * udp_rate_factor,
#ifdef CONFIG_WMM
                                             qos,
#else
                                             0,
#endif

                                             lwiperf_report, ctx);
            }
            else
            {
#endif
                ctx->iperf_session =
                    lwiperf_start_udp_client(&bind_address, port, &server_address, port, ctx->client_type, amount,
                                             buffer_len, IPERF_UDP_CLIENT_RATE * udp_rate_factor,
#ifdef CONFIG_WMM
                                             qos,
#else
                                         0,
#endif

                                             lwiperf_report, ctx);
#ifdef CONFIG_IPV6
            }
#endif
        }
    }

    if (ctx->iperf_session == NULL)
    {
        (void)PRINTF("IPERF initialization failed!\r\n");
    }
    else
    {
        (void)PRINTF("IPERF initialization successful\r\n");
    }
}

/*!
 * @brief Function to abort iperf test.
 */
static void iperf_test_abort(void *arg)
{
    struct iperf_test_context *test_ctx = (struct iperf_test_context *)arg;

    if (test_ctx->iperf_session != NULL)
    {
        lwiperf_abort(test_ctx->iperf_session);
        test_ctx->iperf_session = NULL;
    }
    (void)PRINTF("IPERF ABORT DONE\r\n");
    (void)memset(&ctx, 0, sizeof(struct iperf_test_context));

    os_timer_deactivate(&ptimer);
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

    (void)tcpip_try_callback(poll_udp_client, NULL);
}

static void TESTAbort(void)
{
    (void)tcpip_callback(iperf_test_abort, (void *)&ctx);
}

static void TCPServer(void)
{
    ctx.server_mode = true;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_CLIENT;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void TCPClient(void)
{
    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_CLIENT;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void TCPClientDual(void)
{
    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_DUAL;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void TCPClientTradeOff(void)
{
    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_TRADEOFF;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void TCPClientReverse(void)
{
    ctx.server_mode = false;
    ctx.tcp         = true;
    ctx.client_type = LWIPERF_REVERSE;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPServer(void)
{
    ctx.server_mode = true;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_CLIENT;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPServerDual(void)
{
    ctx.server_mode = true;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_DUAL;

    (void)PRINTF("Bidirectional UDP test simultaneously as server, please add -d with external iperf client\r\n");
    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPServerReverse(void)
{
    ctx.server_mode = true;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_REVERSE;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPServerTradeOff(void)
{
    ctx.server_mode = true;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_TRADEOFF;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPClient(void)
{
    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_CLIENT;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPClientDual(void)
{
    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_DUAL;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPClientTradeOff(void)
{
    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_TRADEOFF;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

static void UDPClientReverse(void)
{
    ctx.server_mode = false;
    ctx.tcp         = false;
    ctx.client_type = LWIPERF_REVERSE;

    (void)tcpip_callback(iperf_test_start, (void *)&ctx);
}

/* Display the usage of iperf */
static void display_iperf_usage(void)
{
    (void)PRINTF("Usage:\r\n");
    (void)PRINTF("\tiperf [-s|-c <host>|-a] [options]\r\n");
    (void)PRINTF("\tiperf [-h]\r\n");
    (void)PRINTF("\r\n");
    (void)PRINTF("\tClient/Server:\r\n");
    (void)PRINTF("\t   -u             use UDP rather than TCP\r\n");
    (void)PRINTF("\t   -B    <host>   bind to <host> (including multicast address)\r\n");
#ifdef CONFIG_IPV6
    (void)PRINTF("\t   -V             Set the domain to IPv6 (send packets over IPv6)\r\n");
#endif
    (void)PRINTF("\t   -a             abort ongoing iperf session\r\n");
    (void)PRINTF("\t   -p             server port to listen on/connect to\r\n");
    (void)PRINTF("\t   -r             Do a bidirectional UDP test individually\r\n");
    (void)PRINTF("\tServer specific:\r\n");
    (void)PRINTF("\t   -s             run in server mode. Support 8 parallel traffic(-P) maximum from client side\r\n");
    (void)PRINTF(
        "\t   -D             Do a bidirectional UDP test simultaneously and with -d from external iperf client\r\n");
    (void)PRINTF("\tClient specific:\r\n");
    (void)PRINTF("\t   -c    <host>   run in client mode, connecting to <host>\r\n");
    (void)PRINTF("\t   -d             Do a bidirectional test simultaneously\r\n");
    (void)PRINTF("\t   -R             reverse the test (client receives, server sends)\r\n");
    (void)PRINTF("\t   -t    #        time in seconds to transmit for (default 10 secs)\r\n");
    (void)PRINTF(
        "\t   -b    #        for UDP, bandwidth to send at in Mbps, default 100Mbps without the parameter\r\n");
#ifdef CONFIG_WMM
    (void)PRINTF("\t   -S    #        QoS for udp traffic (default 0(Best Effort))\r\n");
#endif
    (void)PRINTF(
        "\t   -l             length of buffer in bytes to write (Defaults: v4 TCP=1460, v6 TCP=1440, v4 UDP=1470, v6 UDP=1450)\r\n \
         \t                  Note: Limit length is smaller than default size.\r\n");
}

static void cmd_iperf(int argc, char **argv)
{
    int arg                = 1;
    char ip_addr[128]      = {0};
    char ip_addr_bind[128] = {0};

    struct
    {
        unsigned help : 1;
        unsigned udp : 1;
        unsigned bind : 1;
        unsigned bhost : 1;
        unsigned abort : 1;
        unsigned server : 1;
        unsigned client : 1;
        unsigned chost : 1;
        unsigned dual : 1;
        unsigned tradeoff : 1;
        unsigned reverse : 1;
        unsigned time : 1;
#ifdef CONFIG_WMM
        unsigned tos : 1;
#endif
        unsigned dserver : 1;
#ifdef CONFIG_IPV6
        unsigned ipv6 : 1;
#endif
        unsigned buflen : 1;
        unsigned port : 1;
    } info;

    amount          = IPERF_CLIENT_AMOUNT;
    udp_rate_factor = IPERF_UDP_DEFAULT_FACTOR;
#ifdef CONFIG_WMM
    qos = 0;
#endif
#ifdef CONFIG_IPV6
    ipv6 = false;
#endif
    buffer_len = 0;
    port       = LWIPERF_TCP_PORT_DEFAULT;

    if (mcast_mac_valid)
    {
        (void)wifi_remove_mcast_filter(mcast_mac);
        mcast_mac_valid = false;
    }

    (void)memset(&info, 0, sizeof(info));
    (void)memset(ip_addr, 0, sizeof(ip_addr));
    (void)memset(ip_addr_bind, 0, sizeof(ip_addr_bind));

    if (argc < 2)
    {
        (void)PRINTF("Incorrect usage\r\n");
        display_iperf_usage();
        return;
    }

    do
    {
        if ((info.help == 0U) && string_equal("-h", argv[arg]))
        {
            display_iperf_usage();
            return;
        }
        else if ((info.udp == 0U) && string_equal("-u", argv[arg]))
        {
            arg += 1;
            info.udp = 1;
        }
        else if ((info.abort == 0U) && string_equal("-a", argv[arg]))
        {
            arg += 1;
            info.abort = 1;
        }
        else if ((info.server == 0U) && string_equal("-s", argv[arg]))
        {
            arg += 1;
            info.server = 1;
        }
        else if ((info.client == 0U) && string_equal("-c", argv[arg]))
        {
            arg += 1;
            info.client = 1;

            if ((info.chost == 0U) && argv[arg] != NULL)
            {
                if (strlen(argv[arg]) < sizeof(ip_addr))
                {
                    (void)strncpy(ip_addr, argv[arg], strlen(argv[arg]));

                    arg += 1;
                    info.chost = 1;
                }
            }
            else
            {
                PRINTF("Invalid ip addr, length exceeded max ip_addr bytes\r\n");
                return;
            }
        }
        else if ((info.bind == 0U) && string_equal("-B", argv[arg]))
        {
            arg += 1;
            info.bind = 1;

            if (!info.bhost && argv[arg] != NULL)
            {
                if (strlen(argv[arg]) < sizeof(ip_addr_bind))
                {
                    strncpy(ip_addr_bind, argv[arg], strlen(argv[arg]));
                    arg += 1;
                }
                else
                {
                    PRINTF("Invalid bind ip addr, length exceeded max ip_addr bytes\r\n");
                    return;
                }
            }
        }
        else if ((info.time == 0U) && string_equal("-t", argv[arg]))
        {
            arg += 1;
            info.time = 1;
            errno     = 0;
            amount    = -(100 * strtol(argv[arg], NULL, 10));
            if (errno != 0)
            {
                (void)PRINTF("Invalid time, error during strtoul errno:%d", errno);
                return;
            }
            arg += 1;
        }
#ifdef CONFIG_WMM
        else if (!info.tos && string_equal("-S", argv[arg]))
        {
            arg += 1;
            info.tos = 1;
            errno    = 0;
            qos      = strtoul(argv[arg], NULL, 10);
            if (errno != 0)
            {
                (void)PRINTF("Invalid Qos, error during strtoul errno:%d", errno);
                return;
            }
            arg += 1;
        }
#endif
#ifdef CONFIG_IPV6
        else if ((info.ipv6 == 0U) && string_equal("-V", argv[arg]))
        {
            arg += 1;
            info.ipv6 = 1;
            ipv6      = true;
        }
#endif
        else if ((info.dual == 0U) && string_equal("-d", argv[arg]))
        {
            arg += 1;
            info.dual = 1;
        }
        else if ((info.tradeoff == 0U) && string_equal("-r", argv[arg]))
        {
            arg += 1;
            info.tradeoff = 1;
        }
        else if (!info.reverse && string_equal("-R", argv[arg]))
        {
            arg += 1;
            info.reverse = 1;
        }
        else if (string_equal("-b", argv[arg]))
        {
            if (arg + 1 >= argc || (get_uint(argv[arg + 1], &udp_rate_factor, strlen(argv[arg + 1])) != 0))
            {
                (void)PRINTF(
                    "Error: invalid bandwidth"
                    " argument\n");
                return;
            }
            arg += 2;
        }
        else if (string_equal("-D", argv[arg]))
        {
            arg += 1;
            info.dserver = 1;
        }
        else if (string_equal("-l", argv[arg]))
        {
            if (arg + 1 >= argc || get_uint(argv[arg + 1], &buffer_len, strlen(argv[arg + 1])))
            {
                (void)PRINTF("Error: invalid length argument\r\n");
                return;
            }

            if (buffer_len == 0)
            {
                (void)PRINTF("Error: invalid length argument\r\n");
                return;
            }
            arg += 2;
            info.buflen = 1;
        }
        else if (string_equal("-p", argv[arg]))
        {
            if (arg + 1 >= argc || get_uint(argv[arg + 1], &port, strlen(argv[arg + 1])))
            {
                (void)PRINTF("Error: invalid port argument\r\n");
                return;
            }

            if (port == 0)
            {
                (void)PRINTF("Error: invalid port argument\r\n");
                return;
            }
            arg += 2;
            info.port = 1;
        }
        else
        {
            (void)PRINTF("Incorrect usage\r\n");
            display_iperf_usage();
            (void)PRINTF("Error: argument %d is invalid\r\n", arg);
            return;
        }
    } while (arg < argc);

#ifdef CONFIG_IPV6
    if (ipv6)
    {
        (void)inet6_aton(ip_addr, ip_2_ip6(&server_address));
        server_address.type = IPADDR_TYPE_V6;
    }
    else
    {
#endif
        (void)inet_aton(ip_addr, ip_2_ip4(&server_address));
#ifdef CONFIG_IPV6
        server_address.type = IPADDR_TYPE_V4;
    }
#endif

    if (info.bind)
    {
#ifdef CONFIG_IPV6
        if (ipv6)
        {
            inet6_aton(ip_addr_bind, ip_2_ip6(&bind_address));
            bind_address.type = IPADDR_TYPE_V6;
            if (IP_IS_V6(&bind_address) != 0)
                info.bhost = 1;
        }
        else
        {
#endif
            inet_aton(ip_addr_bind, ip_2_ip4(&bind_address));
#ifdef CONFIG_IPV6
            bind_address.type = IPADDR_TYPE_V4;
#endif
            if (IP_IS_V4(&bind_address) != 0)
                info.bhost = 1;
#ifdef CONFIG_IPV6
        }
#endif
    }

    if (((info.abort == 0U) && (info.server == 0U) && (info.client == 0U)) ||
        ((info.client != 0U) && (info.chost == 0U)) || ((info.server != 0U) && (info.client != 0U)) ||
        ((info.udp != 0U)
#ifdef CONFIG_IPV6
         && (info.ipv6 == 0U)
#endif
         && ((info.bind == 0U) || (info.bhost == 0U))) ||
        (((info.dual != 0U)
          || (info.reverse != 0U)
              ) &&
         (info.client == 0U)) ||
        ((info.dual != 0U) && (info.tradeoff != 0U)) ||
        ((info.dual != 0U) && (info.reverse != 0U)) || ((info.tradeoff != 0U) && (info.reverse != 0U)) ||
        ((info.dserver != 0U) && (info.server == 0U || info.udp == 0U))
#ifdef CONFIG_IPV6
        || ((info.ipv6 != 0U) && (info.client != 0U) && ((info.bind == 0U) || (info.bhost == 0U)))
#endif
    )
    {
        (void)PRINTF("Incorrect usage\r\n");
#ifdef CONFIG_IPV6
        if ((info.ipv6 != 0U) && (info.client != 0U) && ((info.bind == 0U) || (info.bhost == 0U)))
        {
            (void)PRINTF("IPv6: For client please specify local interface ip address using -B option\r\n");
        }
        else if ((info.ipv6 != 0U) && (IP_IS_V4(&server_address)))
        {
            (void)PRINTF("IPv6: Address family for host not supported\r\n");
        }
        else
#endif
        {
            if ((info.udp != 0U)
#ifdef CONFIG_IPV6
                && (info.ipv6 == 0U)
#endif
                && ((info.bind == 0U) || (info.bhost == 0U)))
            {
                (void)PRINTF("For UDP tests please specify local interface ip address using -B option\r\n");
            }
        }
        display_iperf_usage();
        return;
    }

    if (info.abort != 0U)
    {
        TESTAbort();
    }
    else if (info.server != 0U)
    {
        if (info.udp != 0U)
        {
            if (info.dserver != 0U)
            {
                UDPServerDual();
            }
            else if (info.reverse != 0U)
            {
                UDPServerReverse();
            }
            else if (info.tradeoff != 0U)
            {
                UDPServerTradeOff();
            }
            else
            {
                UDPServer();
            }
        }
        else
        {
            TCPServer();
        }
    }
    else if (info.client != 0U)
    {
        if (info.udp != 0U)
        {
            if (info.dual != 0U)
            {
                UDPClientDual();
            }
            else if (info.tradeoff != 0U)
            {
                UDPClientTradeOff();
            }
            else if (info.reverse != 0U)
            {
                UDPClientReverse();
            }
            else
            {
                UDPClient();
            }
        }
        else
        {
            if (info.dual != 0U)
            {
                TCPClientDual();
            }
            else if (info.tradeoff != 0U)
            {
                TCPClientTradeOff();
            }
            else if (info.reverse != 0U)
            {
                TCPClientReverse();
            }
            else
            {
                TCPClient();
            }
        }
    }
    else
    { /* Do Nothing */
    }
}

static struct cli_command iperf[] = {
    {"iperf", "[-s|-c <host>|-a|-h] [options]", cmd_iperf},
};

int iperf_cli_init(void)
{
    u8_t i;
    int rv = WM_SUCCESS;

    for (i = 0; i < sizeof(iperf) / sizeof(struct cli_command); i++)
    {
        if (cli_register_command(&iperf[i]) != 0)
        {
            return -WM_FAIL;
        }
    }

    if (ctx.iperf_session != NULL)
    {
        lwiperf_abort(ctx.iperf_session);
    }

    (void)memset(&ctx, 0, sizeof(struct iperf_test_context));

    if (ptimer == NULL)
        rv = os_timer_create(&ptimer, "UDP Poll Timer", 1U / portTICK_PERIOD_MS, timer_poll_udp_client, (void *)0,
                             OS_TIMER_PERIODIC, OS_TIMER_NO_ACTIVATE);

    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to create iperf timer rv(%d)\r\n", rv);
        while (true)
        {
            ;
        }
    }

    return WM_SUCCESS;
}

int iperf_cli_deinit(void)
{
    u8_t i;

    if (ctx.iperf_session != NULL)
    {
        (void)PRINTF("Abort ongoing IPERF session\r\n");
        lwiperf_abort(ctx.iperf_session);
        ctx.iperf_session = NULL;
    }

    for (i = 0; i < sizeof(iperf) / sizeof(struct cli_command); i++)
    {
        if (cli_unregister_command(&iperf[i]) != 0)
        {
            return -WM_FAIL;
        }
    }
    return WM_SUCCESS;
}
