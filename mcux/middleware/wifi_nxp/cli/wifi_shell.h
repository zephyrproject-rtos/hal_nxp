/*
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file wifi_shell.h
 *
 *  @brief WLAN CLI module
 *
 *  \section cli_usage Usage
 *  The CLI module lets you register commands with the CLI interface. Modules
 *  that wish to register the commands should initialize the struct cli_command
 *  structure and pass this to cli_register_command(). These commands will then
 *  be available on the CLI.
 *
 */

#ifndef __WIFI_SHELL_H__
#define __WIFI_SHELL_H__
#include <wmtypes.h>

#define MAX_COMMANDS  200U

/** Structure for registering CLI commands */
struct cli_command
{
    /** The name of the CLI command */
    const char *name;
    /** The help text associated with the command */
    const char *help;
    /** The function that should be invoked for this command. */
    void (*function)(int argc, char **argv);
};

/** Register a CLI command
 *
 * This function registers a command with the command-line interface.
 *
 * \param[in] command The structure to register one CLI command
 * \return 0 on success
 * \return 1 on failure
 */
int cli_register_command(const struct cli_command *command);

/** Unregister a CLI command
 *
 * This function unregisters a command from the command-line interface.
 *
 * \param[in] command The structure to unregister one CLI command
 * \return 0 on success
 * \return 1 on failure
 */
int cli_unregister_command(const struct cli_command *command);

/** Register a batch of CLI commands
 *
 * Often, a module will want to register several commands.
 *
 * \param[in] commands Pointer to an array of commands.
 * \param[in] num_commands Number of commands in the array.
 * \return 0 on success
 * \return 1 on failure
 */
int cli_register_commands(const struct cli_command *commands, int num_commands);

/** Unregister a batch of CLI commands
 *
 * \param[in] commands Pointer to an array of commands.
 * \param[in] num_commands Number of commands in the array.
 * \return 0 on success
 * \return 1 on failure
 */
int cli_unregister_commands(const struct cli_command *commands, int num_commands);

/*
 * @internal
 *
 * CLI help command to print all registered CLIs
 */
void help_command(int argc, char **argv);

int nxp_wifi_request(size_t argc, char **argv);

#endif /* __WIFI_SHELL_H__ */
