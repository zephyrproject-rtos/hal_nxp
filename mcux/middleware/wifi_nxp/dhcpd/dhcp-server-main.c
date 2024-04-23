/** @file dhcp-server-main.c
 *
 *  @brief This file provides CLI based APIs for the DHCP Server
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** dhcp-server-main.c: CLI based APIs for the DHCP Server
 */
#include <string.h>

#include <wm_os.h>
#include <wm_net.h>
#include <dhcp-server.h>

#include "dhcp-priv.h"

#ifndef CONFIG_DHCP_SERVER_STACK_SIZE
#define CONFIG_DHCP_SERVER_STACK_SIZE 2048
#endif

static os_thread_t dhcpd_thread;
static os_thread_stack_define(dhcp_stack, CONFIG_DHCP_SERVER_STACK_SIZE);
static bool dhcpd_running;
/*
 * API
 */

int dhcp_server_start(void *intrfc_handle)
{
    int ret;

    dhcp_d("DHCP server start request");
    if (dhcpd_running)
    {
        return -WM_E_DHCPD_SERVER_RUNNING;
    }
    ret = dhcp_server_init(intrfc_handle);
    if (ret != WM_SUCCESS)
    {
        dhcp_e("Failed to initialize dhcp server");
        return ret;
    }

    ret = os_thread_create(&dhcpd_thread, "dhcp-server", dhcp_server, NULL, &dhcp_stack, OS_PRIO_3);
    if (ret != 0)
    {
        (void)dhcp_free_allocations();
        return -WM_E_DHCPD_THREAD_CREATE;
    }

    dhcpd_running = 1;
    return WM_SUCCESS;
}

void dhcp_server_stop(void)
{
    dhcp_d("DHCP server stop request");
    if (dhcpd_running)
    {
        if (dhcp_send_halt() != WM_SUCCESS)
        {
            dhcp_w("failed to send halt to DHCP thread");
            return;
        }

        os_thread_sleep(os_msec_to_ticks(50));

        if (os_thread_delete(&dhcpd_thread) != WM_SUCCESS)
        {
            dhcp_w("failed to delete thread");
        }
        dhcpd_running = 0;
    }
    else
    {
        dhcp_w("server not dhcpd_running.");
    }
}
