/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include <wm_os.h>
#include <wm_net.h>

#include <cli.h>

#ifdef CONFIG_WIFI_SMOKE_TESTS

#if defined(SDK_OS_FREE_RTOS)

/*******************************************************************************
 * Includes
 ******************************************************************************/
/*${header:start}*/
#include "board.h"
#include "fsl_phyksz8081.h"

#include "ethernetif.h"
#include "lwip/netifapi.h"
#include "lwip/prot/dhcp.h"

#include "fsl_silicon_id.h"

#include "network_cfg.h"
#include "telnet_server.h"

/*${header:end}*/

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*${macro:start}*/
#ifndef EXAMPLE_NETIF_INIT_FN
/*! @brief Network interface initialization function. */
#define EXAMPLE_NETIF_INIT_FN ethernetif0_init
#endif /* EXAMPLE_NETIF_INIT_FN */
/*${macro:end}*/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*${prototype:start}*/
/*${prototype:end}*/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*${variable:start}*/
static phy_handle_t phyHandle;
static struct netif netif;
static int enet_init_done = 0;
/*${variable:end}*/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*${function:start}*/

void cmd_enet_info(int argc, char **argv)
{
    (void)PRINTF("\"%c%c%d\" : ", netif.name[0], netif.name[1], netif.num);
    if (netif_is_link_up(&netif) && netif_is_up(&netif))
    {
        (void)PRINTF("Connected\r\n");
        (void)PRINTF("\r\n\tIPv4 Address\r\n");
#ifdef IP_USE_DHCP
        (void)PRINTF("\taddress: DHCP");
#else
        (void)PRINTF("\taddress: Static");
#endif
        (void)PRINTF("\r\n\t\tIP:\t\t%s", ipaddr_ntoa(&netif.ip_addr));
        (void)PRINTF("\r\n\t\tgateway:\t%s", ipaddr_ntoa(&netif.gw));
        (void)PRINTF("\r\n\t\tnetmask:\t%s", ipaddr_ntoa(&netif.netmask));
        (void)PRINTF("\r\n");
#ifdef CONFIG_IPV6
        int i;
        char buf[128];
        // char *str;

        (void)PRINTF("\r\n\tIPv6 Addresses\r\n");
        for (i = 0; i < CONFIG_MAX_IPV6_ADDRESSES; i++)
        {
            if (ip6_addr_isvalid(netif_ip6_addr_state(&netif, i)))
            {
                memset(buf, 0x00, 128);

                // str = ip6addr_ntoa_r(ip_2_ip6(&netif.ip6_addr), buf, sizeof(buf));
                //(void)PRINTF("\t\t%s \r\n", str);
            }
        }
        (void)PRINTF("\r\n");
#endif
    }
    else
    {
        (void)PRINTF("Disconnected\r\n");
    }
}

static struct cli_command enet_cli[] = {
    {"enet-info", NULL, cmd_enet_info},
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

extern phy_ksz8081_resource_t g_phy_resource;

int initNetwork(void)
{
    ip4_addr_t netif_ipaddr, netif_netmask, netif_gw;
    ethernetif_config_t enet_config = {
        .phyHandle   = &phyHandle,
        .phyAddr     = BOARD_ENET0_PHY_ADDRESS,
        .phyOps      = &phyksz8081_ops,
        .phyResource = &g_phy_resource,
        .srcClockHz  = CLOCK_GetFreq(kCLOCK_IpgClk),
#ifdef configMAC_ADDR
        .macAddress = configMAC_ADDR,
#endif
    };
    int ret = 0, retry = 0;

#ifndef configMAC_ADDR
    /* Set special address for each chip. */
    (void)SILICONID_ConvertToMacAddr(&enet_config.macAddress);
#endif
#ifdef IP_USE_DHCP
    IP4_ADDR(&netif_ipaddr, 0, 0, 0, 0);
    IP4_ADDR(&netif_netmask, 0, 0, 0, 0);
    IP4_ADDR(&netif_gw, 0, 0, 0, 0);
#else
    ip4addr_aton(IP_ADDR, &netif_ipaddr);
    ip4addr_aton(IP_MASK, &netif_netmask);
    ip4addr_aton(GW_ADDR, &netif_gw);
#endif
    if (enet_init_done == 0)
    {
        netifapi_netif_add(&netif, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, EXAMPLE_NETIF_INIT_FN,
                           tcpip_input);
        netifapi_netif_set_default(&netif);
        netifapi_netif_set_up(&netif);

        while ((ret = ethernetif_wait_linkup(&netif, 5000)) != ERR_OK)
        {
            PRINTF("PHY Auto-negotiation failed. Please check the cable connection and link partner setting.\r\n");
            if (retry == 5)
            {
                break;
            }
            retry++;
        }

        if (ret == ERR_OK)
        {
#ifdef IP_USE_DHCP
            PRINTF("Obtaining IP address from DHCP...\r\n");
            netifapi_dhcp_start(&netif);

            struct dhcp *dhcp;
            dhcp = netif_dhcp_data(&netif);

            while (dhcp->state != DHCP_STATE_BOUND)
            {
                vTaskDelay(100);
            }
            PRINTF("DHCP OK\r\n");
#endif
            (void)ethernetif_wait_ipv4_valid(&netif, ETHERNETIF_WAIT_FOREVER);
            PRINTF("IPv4 Address: %s\r\n", ipaddr_ntoa(&netif.ip_addr));

            enet_cli_init();

            // Initialize a socket Telnet server
            sys_thread_new("LwIP Telnet Server", SocketTelnetServer, NULL, 512, 1);
        }
        enet_init_done = 1;
    }
    return WM_SUCCESS;
}
/*${function:end}*/

#elif __ZEPHYR__

static struct net_if *iface;

static int enet_init_done = 0;

#ifdef IP_USE_DHCP
static struct net_mgmt_event_callback mgmt_cb;
#endif

void cmd_enet_info(int argc, char **argv)
{
    char buf[NET_IPV4_ADDR_LEN];

#if defined(CONFIG_NET_INTERFACE_NAME)
	char ifname[CONFIG_NET_INTERFACE_NAME_LEN + 1] = { 0 };
	int ret_name;

	ret_name = net_if_get_name(iface, ifname, sizeof(ifname) - 1);
	if (ret_name < 1 || ifname[0] == '\0') {
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
#ifdef IP_USE_DHCP
        (void)PRINTF("\taddress: DHCP");
#else
        (void)PRINTF("\taddress: Static");
#endif
        (void)PRINTF("\r\n\t\tIP:\t\t%s", net_addr_ntop(AF_INET,
			    &iface->config.ip.ipv4->unicast[0].address.in_addr,
						  buf, sizeof(buf)));
        (void)PRINTF("\r\n\t\tgateway:\t%s", net_addr_ntop(AF_INET,
						 &iface->config.ip.ipv4->gw,
						 buf, sizeof(buf)));
        (void)PRINTF("\r\n\t\tnetmask:\t%s", net_addr_ntop(AF_INET,
				       &iface->config.ip.ipv4->netmask,
				       buf, sizeof(buf)));
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

#ifdef IP_USE_DHCP

static void handler(struct net_mgmt_event_callback *cb,
		    uint32_t mgmt_event,
		    struct net_if *iface)
{
	int i = 0;

	if (mgmt_event != NET_EVENT_IPV4_ADDR_ADD) {
		return;
	}

	for (i = 0; i < NET_IF_MAX_IPV4_ADDR; i++) {
		char buf[NET_IPV4_ADDR_LEN];

		if (iface->config.ip.ipv4->unicast[i].addr_type !=
							NET_ADDR_DHCP) {
			continue;
		}

		PRINTF("   Address[%d]: %s\r\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
			    &iface->config.ip.ipv4->unicast[i].address.in_addr,
						  buf, sizeof(buf)));
		PRINTF("    Subnet[%d]: %s\r\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
				       &iface->config.ip.ipv4->netmask,
				       buf, sizeof(buf)));
		PRINTF("    Router[%d]: %s\r\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
						 &iface->config.ip.ipv4->gw,
						 buf, sizeof(buf)));

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

#ifdef IP_USE_DHCP

        net_mgmt_init_event_callback(&mgmt_cb, handler,
                NET_EVENT_IPV4_ADDR_ADD);
        net_mgmt_add_event_callback(&mgmt_cb);

        net_dhcpv4_start(iface);
#else
        struct in_addr addr;
        struct in_addr gw;
        struct in_addr nmask;
		char buf[NET_IPV4_ADDR_LEN];

        if (net_addr_pton(AF_INET, CONFIG_NXP_WIFI_SM_IP_ADDRESS, &addr)) {
            PRINTF("Invalid address: %s", CONFIG_NXP_WIFI_SM_IP_ADDRESS);
            return -WM_FAIL;
        }
        if (net_addr_pton(AF_INET, CONFIG_NXP_WIFI_SM_IP_GATEWAY, &gw)) {
            PRINTF("Invalid gateway: %s", CONFIG_NXP_WIFI_SM_IP_GATEWAY);
            return -WM_FAIL;
        }
        if (net_addr_pton(AF_INET, CONFIG_NXP_WIFI_SM_IP_MASK, &nmask)) {
            PRINTF("Invalid nmask: %s", CONFIG_NXP_WIFI_SM_IP_MASK);
            return -WM_FAIL;
        }

        net_if_ipv4_addr_add(iface, &addr, NET_ADDR_MANUAL, 0);
        net_if_ipv4_set_gw(iface, &gw);
        net_if_ipv4_set_netmask(iface, &nmask);

        net_if_carrier_on(iface);

        net_if_up(iface);

        PRINTF("   Address[%d]: %s\r\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
			    &iface->config.ip.ipv4->unicast[0].address.in_addr,
						  buf, sizeof(buf)));
		PRINTF("    Subnet[%d]: %s\r\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
				       &iface->config.ip.ipv4->netmask,
				       buf, sizeof(buf)));
		PRINTF("    Router[%d]: %s\r\n", net_if_get_by_iface(iface),
			net_addr_ntop(AF_INET,
						 &iface->config.ip.ipv4->gw,
						 buf, sizeof(buf)));

        enet_cli_init();
#endif
        enet_init_done = 1;
    }

    return WM_SUCCESS;
}

#endif
#endif
