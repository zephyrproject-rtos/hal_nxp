/** @file dhcp-server-cli.c
 *
 *  @brief This file provides CLI based APIs for the DHCP Server
 *
 *  Copyright 2008-2020 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** dhcp-server-main.c: CLI based APIs for the DHCP Server
 */
#include <string.h>

#include <wm_os.h>
#include <wm_net.h>
#include <cli.h>
#include <cli_utils.h>
#include <dhcp-server.h>

#include "dhcp-priv.h"

/*
 * Command-Line Interface
 */
static void test_dhcp_stat(int argc, char **argv)
{
    dhcp_stat();
}

static struct cli_command dhcp_cmds[] = {
    {"dhcp-stat", NULL, test_dhcp_stat},
};

int dhcpd_cli_init(void)
{
    uint8_t i;

    for (i = 0; i < sizeof(dhcp_cmds) / sizeof(struct cli_command); i++)
    {
        if (cli_register_command(&dhcp_cmds[i]) != 0)
        {
            return -WM_E_DHCPD_REGISTER_CMDS;
        }
    }

    return WM_SUCCESS;
}

int dhcpd_cli_deinit(void)
{
    uint8_t i;

    for (i = 0; i < sizeof(dhcp_cmds) / sizeof(struct cli_command); i++)
    {
        if (cli_unregister_command(&dhcp_cmds[i]) != 0)
        {
            return -WM_E_DHCPD_REGISTER_CMDS;
        }
    }

    return WM_SUCCESS;
}
