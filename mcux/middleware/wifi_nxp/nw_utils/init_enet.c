/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#if CONFIG_WIFI_SMOKE_TESTS
static struct net_if *iface;

static int enet_init_done = 0;

#if IP_USE_DHCP
static struct net_mgmt_event_callback mgmt_cb;
#endif

void cmd_enet_info(int argc, char **argv)
{
    char buf[NET_IPV4_ADDR_LEN];

#if defined(CONFIG_NET_INTERFACE_NAME)
    char ifname[CONFIG_NET_INTERFACE_NAME_LEN + 1] = {0};
    int ret_name;

    ret_name = net_if_get_name(iface, ifname, sizeof(ifname) - 1);
    if (ret_name < 1 || ifname[0] == '\0')
    {
        snprintk(ifname, sizeof(ifname), "?");
    }
    (void)PRINTF("\"%s\" : ", ifname);
#else
    (void)PRINTF("\"na\" : ");
#endif
    if (net_if_is_carrier_ok(iface) && net_if_is_up(iface))
    {
        (void)PRINTF("Connected\r\n");
        (void)PRINTF("\r\n\tIPv4 Address\r\n");
#if IP_USE_DHCP
        (void)PRINTF("\taddress: DHCP");
#else
        (void)PRINTF("\taddress: Static");
#endif
        (void)PRINTF("\r\n\t\tIP:\t\t%s",
                     net_addr_ntop(AF_INET, &iface->config.ip.ipv4->unicast[0].address.in_addr, buf, sizeof(buf)));
        (void)PRINTF("\r\n\t\tgateway:\t%s", net_addr_ntop(AF_INET, &iface->config.ip.ipv4->gw, buf, sizeof(buf)));
        (void)PRINTF("\r\n\t\tnetmask:\t%s", net_addr_ntop(AF_INET, &iface->config.ip.ipv4->netmask, buf, sizeof(buf)));
        (void)PRINTF("\r\n");
    }
    else
    {
        (void)PRINTF("Disconnected\r\n");
    }
}

static struct cli_command enet_cli[] = {
    {"wlan-enet-info", NULL, cmd_enet_info},
};

static int enet_cli_init(void)
{
    unsigned int i;
    for (i = 0; i < sizeof(enet_cli) / sizeof(struct cli_command); i++)
    {
        if (cli_register_command(&enet_cli[i]) != 0)
        {
            return -WM_FAIL;
        }
    }
    return WM_SUCCESS;
}

#if IP_USE_DHCP

static void handler(struct net_mgmt_event_callback *cb, uint32_t mgmt_event, struct net_if *iface)
{
    int i = 0;

    if (mgmt_event != NET_EVENT_IPV4_ADDR_ADD)
    {
        return;
    }

    for (i = 0; i < NET_IF_MAX_IPV4_ADDR; i++)
    {
        char buf[NET_IPV4_ADDR_LEN];

        if (iface->config.ip.ipv4->unicast[i].addr_type != NET_ADDR_DHCP)
        {
            continue;
        }

        PRINTF("   Address[%d]: %s\r\n", net_if_get_by_iface(iface),
               net_addr_ntop(AF_INET, &iface->config.ip.ipv4->unicast[i].address.in_addr, buf, sizeof(buf)));
        PRINTF("    Subnet[%d]: %s\r\n", net_if_get_by_iface(iface),
               net_addr_ntop(AF_INET, &iface->config.ip.ipv4->netmask, buf, sizeof(buf)));
        PRINTF("    Router[%d]: %s\r\n", net_if_get_by_iface(iface),
               net_addr_ntop(AF_INET, &iface->config.ip.ipv4->gw, buf, sizeof(buf)));

        enet_cli_init();
    }
}

#endif

int initNetwork(void)
{
    if (enet_init_done == 0)
    {
        iface = net_if_get_first_by_type(&NET_L2_GET_NAME(ETHERNET));
        if (iface == NULL)
        {
            PRINTF("No ethernet interfaces found.\r\n");
            return -WM_FAIL;
        }

#if IP_USE_DHCP

        net_mgmt_init_event_callback(&mgmt_cb, handler, NET_EVENT_IPV4_ADDR_ADD);
        net_mgmt_add_event_callback(&mgmt_cb);

        net_dhcpv4_start(iface);
#else
        struct in_addr addr;
        struct in_addr gw;
        struct in_addr nmask;
        char buf[NET_IPV4_ADDR_LEN];

        if (net_addr_pton(AF_INET, CONFIG_NXP_WIFI_SM_IP_ADDRESS, &addr))
        {
            PRINTF("Invalid address: %s", CONFIG_NXP_WIFI_SM_IP_ADDRESS);
            return -WM_FAIL;
        }
        if (net_addr_pton(AF_INET, CONFIG_NXP_WIFI_SM_IP_GATEWAY, &gw))
        {
            PRINTF("Invalid gateway: %s", CONFIG_NXP_WIFI_SM_IP_GATEWAY);
            return -WM_FAIL;
        }
        if (net_addr_pton(AF_INET, CONFIG_NXP_WIFI_SM_IP_MASK, &nmask))
        {
            PRINTF("Invalid nmask: %s", CONFIG_NXP_WIFI_SM_IP_MASK);
            return -WM_FAIL;
        }

        net_if_ipv4_addr_add(iface, &addr, NET_ADDR_MANUAL, 0);
        net_if_ipv4_set_gw(iface, &gw);
        net_if_ipv4_set_netmask_by_addr(iface, &addr, &nmask);

        net_if_carrier_on(iface);

        net_if_up(iface);

        PRINTF("   Address[%d]: %s\r\n", net_if_get_by_iface(iface),
               net_addr_ntop(AF_INET, &iface->config.ip.ipv4->unicast[0].address.in_addr, buf, sizeof(buf)));
        PRINTF("    Subnet[%d]: %s\r\n", net_if_get_by_iface(iface),
               net_addr_ntop(AF_INET, &iface->config.ip.ipv4->netmask, buf, sizeof(buf)));
        PRINTF("    Router[%d]: %s\r\n", net_if_get_by_iface(iface),
               net_addr_ntop(AF_INET, &iface->config.ip.ipv4->gw, buf, sizeof(buf)));

        enet_cli_init();
#endif
        enet_init_done = 1;
    }

    return WM_SUCCESS;
}

#endif
