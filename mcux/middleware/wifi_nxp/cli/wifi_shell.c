/*
 * Copyright 2022-2024 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "nxp_wifi.h"

#if CONFIG_WIFI_SHELL
#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>

#include "wifi_shell.h"
#include <wlan.h>
#include <wifi.h>

static struct
{
    const struct cli_command *commands[MAX_COMMANDS];
    unsigned int num_commands;
} cli;

int cli_register_command(const struct cli_command *command)
{
    unsigned int i;
    if (command->name == NULL || command->function == NULL)
    {
        return 1;
    }

    if (cli.num_commands < MAX_COMMANDS)
    {
        /* Check if the command has already been registered.
         * Return 0, if it has been registered.
         */
        for (i = 0; i < cli.num_commands; i++)
        {
            if (cli.commands[i] == command)
            {
                return 0;
            }
        }
        cli.commands[cli.num_commands++] = command;
        return 0;
    }

    return 1;
}

int cli_unregister_command(const struct cli_command *command)
{
    unsigned int i = 0;
    if (command->name == NULL || command->function == NULL)
    {
        return 1;
    }

    while (i < cli.num_commands)
    {
        if (cli.commands[i] == command)
        {
            cli.num_commands--;
            unsigned int remaining_cmds = cli.num_commands - i;
            if (remaining_cmds > 0U)
            {
                (void)memmove(&cli.commands[i], &cli.commands[i + 1U], (remaining_cmds * sizeof(struct cli_command *)));
            }
            cli.commands[cli.num_commands] = NULL;
            return 0;
        }
        i++;
    }

    return 1;
}

int cli_register_commands(const struct cli_command *commands, int num_commands)
{
    int i;
    for (i = 0; i < num_commands; i++)
    {
        if (cli_register_command(commands++) != 0)
        {
            return 1;
        }
    }
    return 0;
}

int cli_unregister_commands(const struct cli_command *commands, int num_commands)
{
    int i;
    for (i = 0; i < num_commands; i++)
    {
        if (cli_unregister_command(commands++) != 0)
        {
            return 1;
        }
    }

    return 0;
}

static const struct cli_command *lookup_command(char *name, int len)
{
    unsigned int i = 0;
    unsigned int n = 0;

    while (i < MAX_COMMANDS && n < cli.num_commands)
    {
        if (cli.commands[i]->name == NULL)
        {
            i++;
            continue;
        }
        /* See if partial or full match is expected */
        if (len != 0)
        {
            if (strncmp(cli.commands[i]->name, name, (size_t)len) == 0)
            {
                return cli.commands[i];
            }
        }
        else
        {
            if (strcmp(cli.commands[i]->name, name) == 0)
            {
                return cli.commands[i];
            }
        }

        i++;
        n++;
    }

    return NULL;
}

/* prints all registered commands and their help text string, if any. */
void help_command(int argc, char **argv)
{
    unsigned int i = 0, n = 0;

    while (i < MAX_COMMANDS && n < cli.num_commands)
    {
        if (cli.commands[i]->name != NULL)
        {
            (void)PRINTF("%s %s\r\n", (char *)cli.commands[i]->name + 5,
                         cli.commands[i]->help != NULL ? cli.commands[i]->help : "");
            n++;
        }
        i++;
    }
}

static char nxp_wifi_cmd_name[32];

/**
 *  wlan shell entry
 *  syntax: wlansh wlan-add ...
 */
int nxp_wifi_request(size_t argc, char **argv)
{
    const struct cli_command *command = NULL;

    if (argc < 2)
    {
        (void)PRINTF("nxp_wifi command too few arguments\r\n");
        return -1;
    }

    /* cmd name should be less than buff size */
    if (strlen(argv[1]) >= sizeof(nxp_wifi_cmd_name) - strlen("wlan-"))
    {
        (void)PRINTF("nxp_wifi command name too long\r\n");
        return -1;
    }

    if (strcmp(argv[1], "help") == 0)
    {
        help_command(argc, argv);
        return 0;
    }

    strcpy(nxp_wifi_cmd_name, "wlan-");
    strcat(nxp_wifi_cmd_name, argv[1]);

    command = lookup_command(nxp_wifi_cmd_name, strlen(nxp_wifi_cmd_name));
    if (command != NULL)
    {
        command->function(argc - 1, &argv[1]);
        (void)PRINTF("Command %s\r\n", command->name);
    }
    else
    {
        (void)PRINTF("Unknown comamnd %s\r\n", argv[1]);
    }

    return 0;
}
#endif
