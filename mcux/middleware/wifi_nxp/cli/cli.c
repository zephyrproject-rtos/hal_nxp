/** @file cli.c
 *
 *  @brief This file provides  CLI: command-line interface
 *
 *  Copyright 2008-2023 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* cli.c: CLI: command-line interface
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <cli.h>
#include <cli_utils.h>
#include <wm_os.h>
#include <fsl_debug_console.h>
#include "board.h"

#include "cli_mem.h"
#ifdef CONFIG_UART_INTERRUPT
#include "fsl_usart_freertos.h"
#include "fsl_usart.h"
#endif
#define END_CHAR      '\r'
#define PROMPT        "\r\n# "
#define HALT_MSG      "CLI_HALT"
#define NUM_BUFFERS   1
#define MAX_COMMANDS  200U
#define IN_QUEUE_SIZE 4

#define RX_WAIT   OS_WAIT_FOREVER
#define SEND_WAIT OS_WAIT_FOREVER

#define CONFIG_CLI_STACK_SIZE (5376)

static os_mutex_t cli_mutex;
static os_queue_pool_define(queue_data, IN_QUEUE_SIZE);
static struct
{
    int input_enabled;
    bool initialized;

    unsigned int bp; /* buffer pointer */
    char *cli_inbuf;

    const struct cli_command *commands[MAX_COMMANDS];
    unsigned int num_commands;
    bool echo_disabled;

    os_queue_t input_queue;
    os_queue_pool_t in_queue_data;

} cli;

static os_thread_t cli_main_thread;
static os_thread_stack_define(cli_stack, CONFIG_CLI_STACK_SIZE);
#ifdef CONFIG_UART_INTERRUPT
static os_thread_t uart_thread;
static os_thread_stack_define(uart_stack, 1024);
#define USART_INPUT_SIZE 1
#define USART_NVIC_PRIO  5
uint8_t background_buffer[32];
uint8_t recv_buffer[USART_INPUT_SIZE];
static usart_rtos_handle_t ur_handle;
struct _usart_handle t_u_handle;

struct rtos_usart_config usart_config = {
    .baudrate    = BOARD_DEBUG_UART_BAUDRATE,
    .parity      = kUSART_ParityDisabled,
    .stopbits    = kUSART_OneStopBit,
    .buffer      = background_buffer,
    .buffer_size = sizeof(background_buffer),
};
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
extern bool usart_suspend_flag;
#endif
#endif
#endif
#ifdef CONFIG_APP_FRM_CLI_HISTORY
#define MAX_CMDS_IN_HISTORY 20
static char *cmd_hist_arr[MAX_CMDS_IN_HISTORY];
static int total_hist_cmds, last_cmd_num;
static int console_loop_num;
static bool hist_inited;

static char *cli_strdup(const char *s, int len)
{
    char *result = os_mem_alloc(len + 1);
    int i;

    if (result)
    {
        for (i = 0; i < len; i++)
        {
            result[i] = s[i] == '\0' ? ' ' : s[i];
        }

        result[len] = '\0';
    }
    return result;
}

static int get_cmd_from_hist(int cmd_no, char *buf, int max_len)
{
    if (!hist_inited)
        return -WM_FAIL;

    if (cmd_no >= MAX_CMDS_IN_HISTORY || cmd_no < 0)
        return -WM_FAIL;

    if (cmd_hist_arr[cmd_no])
    {
        if (strlen(cmd_hist_arr[cmd_no]) >= max_len)
            return -WM_FAIL;

        if (cmd_hist_arr[cmd_no][0] == (char)(0x20))
        {
            (void)PRINTF("");
            return -WM_FAIL;
        }
        else
        {
            strncpy(buf, cmd_hist_arr[cmd_no], max_len);
        }
        return WM_SUCCESS;
    }

    return WM_SUCCESS;
}

static int store_cmd_to_hist(int cmd_no, const char *buf, int len)
{
    if (cmd_no >= MAX_CMDS_IN_HISTORY || cmd_no < 0)
        return -WM_FAIL;

    if (cmd_hist_arr[cmd_no])
    {
        if (strcmp(cmd_hist_arr[cmd_no], buf) == 0U)
            return WM_SUCCESS; /* avoid rewrite. */
        else if (cmd_hist_arr[cmd_no][0] == (char)(0x20))
        {
            return WM_SUCCESS;
        }
        else
        {
            os_mem_free(cmd_hist_arr[cmd_no]);
            cmd_hist_arr[cmd_no] = NULL;
        }
    }


    cmd_hist_arr[cmd_no] = cli_strdup(buf, len); /* ignore failure silently */

#if 0 /* debug only */
	int i;
    PRINTF("\r\n");
	for (i = 0; i < MAX_CMDS_IN_HISTORY; i++)
		(void)PRINTF("ARR: %s\r\n", cmd_hist_arr[i]);
#endif

    return WM_SUCCESS;
}

/* This func has one more goal which is not obvious. To load the values
   into the ram cache maintained by history handling code in this file. This
   ensures that history operations are not done in idle thread (console loop)
*/
static int get_total_cmds()
{
    int cmd_no = 0;
    return cmd_no;
}

static int get_next_cmd_num_console()
{
    if (!hist_inited)
        return 0;

    if (console_loop_num < 0)
        return -1;

    return console_loop_num = ((console_loop_num + 1) % total_hist_cmds);
}

static int get_prev_cmd_num_console()
{
    if (!hist_inited)
        return 0;

    if (console_loop_num < 0)
        return -1;

    if ((console_loop_num - 1) < 0)
        return console_loop_num = total_hist_cmds - 1;
    else
        return --console_loop_num;
}

static int cmd_hist_is_duplicate(const char *cmd)
{
    if ((last_cmd_num == -1) || (last_cmd_num == 0))
        return false; /* No cmds */

    /* Allocate once */
    static char *tmpbuf;
    if (!tmpbuf)
    {
        tmpbuf = os_mem_alloc(INBUF_SIZE);
        if (!tmpbuf)
            return false; /* ignore silently */
    }

    int rv = get_cmd_from_hist(last_cmd_num, tmpbuf, INBUF_SIZE);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("%s: read cmd %d failed\r\n", __func__, last_cmd_num);
        return false;
    }

    if (strcmp(tmpbuf, cmd) == 0U)
    {
        return true; /* Duplicate */
    }

    return false;
}

int cmd_hist_init()
{
    console_loop_num = -1;
    last_cmd_num     = -1;

    hist_inited     = true;
    total_hist_cmds = get_total_cmds();
    if (total_hist_cmds >= 0)
    {
        last_cmd_num     = total_hist_cmds - 1;
        console_loop_num = 0;
    }

    return WM_SUCCESS;
}


static void cmd_hist_add(const char *cmd, int len)
{
    if (!hist_inited)
        return;

    if (!strlen(cmd))
        return;

    if (cmd_hist_is_duplicate(cmd))
        return;

    int new_cmd_num = (last_cmd_num + 1) % MAX_CMDS_IN_HISTORY;
    int rv          = store_cmd_to_hist(new_cmd_num, cmd, len);
    if (rv != WM_SUCCESS)
        return;

    if ((new_cmd_num + 1) > total_hist_cmds)
        total_hist_cmds = new_cmd_num + 1;
    last_cmd_num     = new_cmd_num;
    console_loop_num = (new_cmd_num + 1) % total_hist_cmds;
}
#endif /* CONFIG_APP_FRM_CLI_HISTORY */

/* Find the command 'name' in the cli commands table.
 * If len is 0 then full match will be performed else upto len bytes.
 * Returns: a pointer to the corresponding cli_command struct or NULL.
 */
#ifdef COEX_APP_SUPPORT
const struct cli_command *lookup_command(char *name, int len)
#else
static const struct cli_command *lookup_command(char *name, int len)
#endif
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

/* Parse input line and locate arguments (if any), keeping count of the number
 * of arguments and their locations.  Look up and call the corresponding cli
 * function if one is found and pass it the argv array.
 *
 * Returns: 0 on success: the input line contained at least a function name and
 *          that function exists and was called.
 *          1 on lookup failure: there is no corresponding function for the
 *          input line.
 *          2 on invalid syntax: the arguments list couldn't be parsed
 */
int handle_input(char *handle_inbuf)
{
    struct
    {
        unsigned inArg : 1;
        unsigned inQuote : 1;
        unsigned done : 1;
    } stat;
    static char *argv[64];
    int argc = 0;
    int i    = 0;
#ifdef CONFIG_APP_FRM_CLI_HISTORY
    int len = 0;
#endif
    unsigned int j                    = 0;
    const struct cli_command *command = NULL;
    const char *p;

    (void)memset((void *)&argv, 0, sizeof(argv));
    (void)memset(&stat, 0, sizeof(stat));

    /*
     * Some terminals add CRLF to the input buffer.
     * Sometimes the CR and LF characters maybe misplaced (it maybe added at the
     * start or at the end of the buffer). Therefore, strip all CRLF (0x0d, 0x0a).
     */
    for (j = 0; j < INBUF_SIZE; j++)
    {
        if (handle_inbuf[j] == (char)0x0D || handle_inbuf[j] == (char)0x0A)
        {
            if (j < (INBUF_SIZE - 1U))
            {
                (void)memmove((handle_inbuf + j), handle_inbuf + j + 1, (INBUF_SIZE - 1 - j));
            }
            handle_inbuf[INBUF_SIZE - 1] = (char)(0x00);
        }
    }

    do
    {
        switch (handle_inbuf[i])
        {
            case '\0':
                if (stat.inQuote != 0U)
                {
                    return 2;
                }
                stat.done = 1;
                break;

            case '"':
                if (i > 0 && handle_inbuf[i - 1] == '\\' && (stat.inArg != 0U))
                {
                    (void)memcpy(&handle_inbuf[i - 1], &handle_inbuf[i], strlen(&handle_inbuf[i]) + 1U);
                    --i;
                    break;
                }
                if ((stat.inQuote == 0U) && (stat.inArg != 0U))
                {
                    break;
                }
                if ((stat.inQuote != 0U) && (stat.inArg == 0U))
                {
                    return 2;
                }

                if ((stat.inQuote == 0U) && (stat.inArg == 0U))
                {
                    stat.inArg   = 1;
                    stat.inQuote = 1;
                    argc++;
                    argv[argc - 1] = &handle_inbuf[i + 1];
                }
                else if ((stat.inQuote != 0U) && (stat.inArg != 0U))
                {
                    stat.inArg      = 0;
                    stat.inQuote    = 0;
                    handle_inbuf[i] = '\0';
                }
                else
                { /* Do Nothing */
                }
                break;

            case ' ':
                if (i > 0 && handle_inbuf[i - 1] == '\\' && (stat.inArg != 0U))
                {
                    (void)memcpy(&handle_inbuf[i - 1], &handle_inbuf[i], strlen(&handle_inbuf[i]) + 1U);
                    --i;
                    break;
                }
                if ((stat.inQuote == 0U) && (stat.inArg != 0U))
                {
                    stat.inArg      = 0;
                    handle_inbuf[i] = '\0';
                }
                break;

            default:
                if (stat.inArg == 0U)
                {
                    stat.inArg = 1;
                    argc++;
                    argv[argc - 1] = &handle_inbuf[i];
                }
                break;
        }
        i++;
    } while ((stat.done == 0U) && (unsigned int)i < INBUF_SIZE);

    if (stat.inQuote != 0U)
    {
        return 2;
    }

    if (argc < 1)
    {
        return 0;
    }

    if (!cli.echo_disabled)
    {
        (void)PRINTF("\r\n");
    }

#ifdef CONFIG_APP_FRM_CLI_HISTORY
    len = i - 1;
#endif

    /*
     * Some comamands can allow extensions like foo.a, foo.b and hence
     * compare commands before first dot.
     */
    i       = ((p = strchr(argv[0], (int)('.'))) == NULL) ? 0 : (p - argv[0]);
    command = lookup_command(argv[0], i);
    if (command == NULL)
    {
        return 1;
    }

#ifdef CONFIG_APP_FRM_CLI_HISTORY
    cmd_hist_add(handle_inbuf, len);
#endif

    command->function(argc, argv);

    return 0;
}

/* Perform basic tab-completion on the input buffer by string-matching the
 * current input line against the cli functions table.  The current input line
 * is assumed to be NULL-terminated. */
static void tab_complete(char *tab_inbuf, unsigned int *bp)
{
    unsigned int i = 0, n = 0, m = 0;
    const char *fm = NULL;

    (void)PRINTF("\r\n");

    /* show matching commands */
    while (i < MAX_COMMANDS && n < cli.num_commands)
    {
        if (cli.commands[i]->name != NULL)
        {
            if (strncmp(tab_inbuf, cli.commands[i]->name, *bp) == 0)
            {
                m++;
                if (m == 1U)
                {
                    fm = cli.commands[i]->name;
                }
                else if (m == 2U)
                {
                    (void)PRINTF("%s %s ", fm, cli.commands[i]->name);
                }
                else
                {
                    (void)PRINTF("%s ", cli.commands[i]->name);
                }
            }
            n++;
        }
        i++;
    }

    /* there's only one match, so complete the line */
    if (m == 1U && fm != NULL)
    {
        n = strlen(fm) - *bp;
        if (*bp + n < INBUF_SIZE)
        {
            (void)memcpy(tab_inbuf + *bp, fm + *bp, n);
            *bp += n;
            tab_inbuf[(*bp)++] = ' ';
            tab_inbuf[*bp]     = '\0';
        }
    }

    /* just redraw input line */
    (void)PRINTF("%s%s", PROMPT, tab_inbuf);
}

enum
{
    BASIC_KEY,
    EXT_KEY_FIRST_SYMBOL,
    EXT_KEY_SECOND_SYMBOL,
};

#ifdef CONFIG_APP_FRM_CLI_HISTORY
static void clear_line(unsigned int cnt)
{
    while (cnt--)
        (void)PRINTF("\b \b");
}
#endif /* CONFIG_APP_FRM_CLI_HISTORY */

/* Get an input line.
 *
 * Returns: 1 if there is input, 0 if the line should be ignored. */
static int get_input(char *get_inbuf, unsigned int *bp)
{
    static int state = BASIC_KEY;
    static char second_char;
#ifdef CONFIG_APP_FRM_CLI_HISTORY
    int rv = -WM_FAIL;
#endif /* CONFIG_APP_FRM_CLI_HISTORY */
#ifdef CONFIG_UART_INTERRUPT
    int ret;
    size_t n;
#endif
    if (get_inbuf == NULL)
    {
        return 0;
    }

    // wmstdio_flush();

    while (true)
    {
#ifdef CONFIG_UART_INTERRUPT
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
        if (usart_suspend_flag)
        {
            os_thread_sleep(os_msec_to_ticks(1000));
            continue;
        }
#endif
#endif
        ret = USART_RTOS_Receive(&ur_handle, recv_buffer, sizeof(recv_buffer), &n);
        if (ret == kStatus_USART_RxRingBufferOverrun)
        {
            /* Notify about hardware buffer overrun and un-received buffer content */
            background_buffer[31] = 0;
            PRINTF("\r\nRing buffer overrun: %s\r\n", background_buffer);
            PRINTF("\r\nPlease do not input during throughput tests\r\n");
            vTaskSuspend(NULL);
        }
        get_inbuf[*bp] = recv_buffer[0];
#else
        get_inbuf[*bp] = (char)GETCHAR();
#endif

        if (state == EXT_KEY_SECOND_SYMBOL)
        {
            if (second_char == (char)(0x4F))
            {
                if (get_inbuf[*bp] == (char)(0x4D))
                {
                    /* Num. keypad ENTER */
                    get_inbuf[*bp] = '\0';
                    *bp            = 0;
                    state          = BASIC_KEY;
                    return 1;
                }
            }
#ifdef CONFIG_APP_FRM_CLI_HISTORY
            if (second_char == 0x5B)
            {
                if (get_inbuf[*bp] == 0x41)
                {
                    /* UP key */
                    clear_line(*bp);
                    *bp = 0;
                    rv  = get_cmd_from_hist(get_prev_cmd_num_console(), get_inbuf, INBUF_SIZE);
                    if (rv == WM_SUCCESS)
                    {
                        *bp = strlen(get_inbuf);
                        (void)PRINTF("%s", get_inbuf);
                    }
                    state = BASIC_KEY;
                    continue;
                }
                if (get_inbuf[*bp] == 0x42)
                {
                    /* Down key */
                    clear_line(*bp);
                    *bp = 0;
                    rv  = get_cmd_from_hist(get_next_cmd_num_console(), get_inbuf, INBUF_SIZE);
                    if (rv == WM_SUCCESS)
                    {
                        *bp = strlen(get_inbuf);
                        (void)PRINTF("%s", get_inbuf);
                    }
                    state = BASIC_KEY;
                    continue;
                }
                if (get_inbuf[*bp] == 0x44)
                {
                    /* Ignoring left key */
                    state = BASIC_KEY;
                    continue;
                }
                if (get_inbuf[*bp] == 0x43)
                {
                    /* Ignoring right key */
                    state = BASIC_KEY;
                    continue;
                }
            }
#endif /* CONFIG_APP_FRM_CLI_HISTORY */
        }

        if (state == EXT_KEY_FIRST_SYMBOL)
        {
            second_char = get_inbuf[*bp];
            if (get_inbuf[*bp] == (char)(0x4F))
            {
                state = EXT_KEY_SECOND_SYMBOL;
                continue;
            }
            if (get_inbuf[*bp] == (char)(0x5B))
            {
                state = EXT_KEY_SECOND_SYMBOL;
                continue;
            }
        }
        if (get_inbuf[*bp] == (char)(0x1B))
        {
            /* We may be seeing a first character from a
               extended key */
            state = EXT_KEY_FIRST_SYMBOL;
            continue;
        }
        state = BASIC_KEY;

        if (get_inbuf[*bp] == END_CHAR)
        { /* end of input line */
            get_inbuf[*bp] = '\0';
            *bp            = 0;
            return 1;
        }

        if ((get_inbuf[*bp] == (char)(0x08)) || /* backspace */
            (get_inbuf[*bp] == (char)(0x7f)))
        { /* DEL */
            if (*bp > (unsigned int)(0))
            {
                (*bp)--;
                if (!cli.echo_disabled)
                {
                    (void)PRINTF("%c %c", 0x08, 0x08);
                }
            }
            continue;
        }

        if (get_inbuf[*bp] == '\t')
        {
            get_inbuf[*bp] = '\0';
            tab_complete(get_inbuf, bp);
            continue;
        }

        if (!cli.echo_disabled)
        {
            (void)PRINTF("%c", get_inbuf[*bp]);
        }

        (*bp)++;
        if (*bp >= (unsigned int)(INBUF_SIZE))
        {
            (void)PRINTF("Error: input buffer overflow\r\n");
            (void)PRINTF(PROMPT);
            *bp = 0;
            return 0;
        }
    }
}

/* Print out a bad command string, including a hex
 * representation of non-printable characters.
 * Non-printable characters show as "\0xXX".
 */
void print_bad_command(char *cmd_string)
{
    if (cmd_string != NULL)
    {
        unsigned char *c = (unsigned char *)cmd_string;
        (void)PRINTF("command '");
        while (*c != (unsigned char)'\0')
        {
            if (isprint(*c) != 0)
            {
                (void)PRINTF("%c", *c);
            }
            else
            {
                (void)PRINTF("\\0x%x", *c);
            }
            ++c;
        }
        (void)PRINTF("' not found\r\n");
    }
}

/* Ticker function for polling the UART for character input. */
static void console_tick(void)
{
    int ret;

    if (cli.cli_inbuf == NULL)
    {
        ret = cli_get_cmd_buffer(&cli.cli_inbuf);
        if (ret != WM_SUCCESS)
        {
            return;
        }
        cli.bp = 0;
    }

    if (cli.input_enabled == 1)
    {
        ret = get_input(cli.cli_inbuf, &cli.bp);
        if (ret == 1)
        {
            cli.input_enabled = 0;
            ret               = cli_submit_cmd_buffer(&cli.cli_inbuf);
            cli.cli_inbuf     = NULL;
            if (ret != WM_SUCCESS)
            {
                (void)PRINTF(
                    "Error: problem sending cli message"
                    "\r\n");
            }
            cli.input_enabled = 1;
        }
    }
}

/* Main CLI processing thread
 *
 * Waits to receive a command buffer pointer from an input collector, and
 * then processes.  Note that it must cleanup the buffer when done with it.
 *
 * Input collectors handle their own lexical analysis and must pass complete
 * command lines to CLI.
 */
static void cli_main(os_thread_arg_t data)
{
    while (true)
    {
        int ret;
        char *msg;

        msg = NULL;
        ret = os_queue_recv(&cli.input_queue, &msg, RX_WAIT);
        if (ret != WM_SUCCESS)
        {
            if (ret == (int)WM_E_BADF)
            {
                (void)PRINTF(
                    "Error: CLI fatal queue error."
                    "\r\n");
                /* Special case fatal errors.  Shouldn't happen. If it does
                 * it means CLI is fatally corrupted, so end the thread.
                 */
                return;
            }
            /* A number of other non-fatal conditions can cause us to get here]
             * without a message to process, if so, just go back and wait.
             */
            continue;
        }

        /* HALT message indicates that this thread will be deleted
         * shortly. Hence this function need to do necessary actions
         * required before getting deleted.
         * HALT message is not dynamically allocated,
         * hence msg doesn't need to be freed up in that case.
         */
        if (msg != NULL)
        {
            if (strcmp(msg, HALT_MSG) == 0)
            {
                break;
            }
            ret = handle_input(msg);
            if (ret == 1)
            {
                print_bad_command(msg);
            }
            else if (ret == 2)
            {
                (void)PRINTF("syntax error\r\n");
            }
            else
            { /* Do Nothing */
            }
            (void)PRINTF(PROMPT);
            /* done with it, clean up the message (we own it) */
            (void)cli_mem_free(&msg);
        }
    }
    os_thread_self_complete(NULL);
}

#ifndef CONFIG_UART_INTERRUPT
/* Automatically bind an input processor to the console */
static int cli_install_UART_Tick(void)
{
    return os_setup_idle_function(console_tick);
}

static int cli_remove_UART_Tick(void)
{
    return os_remove_idle_function(console_tick);
}
#endif

/* Internal cleanup function. */
static int __cli_cleanup(void)
{
    int ret, final = WM_SUCCESS;
    char *halt_msg = HALT_MSG;

#ifndef CONFIG_UART_INTERRUPT
    if (cli_remove_UART_Tick() != WM_SUCCESS)
    {
        (void)PRINTF(
            "Error: could not remove UART Tick function."
            "\r\n");
        final = -WM_FAIL;
    }
#endif

    ret = cli_submit_cmd_buffer(&halt_msg);
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF(
            "Error: problem sending cli message"
            "\r\n");
    }
    (void)os_mutex_get(&cli_mutex, OS_WAIT_FOREVER);
    ret = os_queue_delete(&cli.input_queue);
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Warning: failed to delete queue.\r\n");
        final = -WM_FAIL;
    }

    if (cli.cli_inbuf != NULL)
    {
        (void)cli_mem_free(&cli.cli_inbuf);
    }

    ret = cli_mem_cleanup();
    if (ret != WM_SUCCESS)
    {
        final = -WM_FAIL;
    }

    ret = os_thread_delete(&cli_main_thread);
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Warning: failed to delete thread.\r\n");
        final = -WM_FAIL;
    }
    (void)os_mutex_put(&cli_mutex);
    (void)os_mutex_delete(&cli_mutex);
    cli.initialized = false;
    return final;
}

/* Initialize and start the main thread */
static int cli_start(void)
{
    int ret;

    if (cli.initialized == true)
    {
        return WM_SUCCESS;
    }

    ret = os_mutex_create(&cli_mutex, "cli", OS_MUTEX_INHERIT);
    if (ret != WM_SUCCESS)
    {
        return -WM_FAIL;
    }

    ret = os_queue_create(&cli.input_queue, "cli_queue", (int)sizeof(void *), &cli.in_queue_data);
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Error: Failed to create cli queue: %d\r\n", ret);
        return -WM_FAIL;
    }

#ifdef CONFIG_UART_INTERACTIVE
    ret = os_thread_create(&cli_main_thread, "cli", cli_main, 0, &cli_stack, OS_PRIO_1);
#else
    ret = os_thread_create(&cli_main_thread, "cli", cli_main, 0, &cli_stack, OS_PRIO_3);
#endif
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Error: Failed to create cli thread: %d\r\n", ret);
        return -WM_FAIL;
    }

#ifdef CONFIG_APP_FRM_CLI_HISTORY
    cmd_hist_init();
    cmd_hist_add(" ", 1);
#endif

    ret = cli_mem_init();

    if (ret != WM_SUCCESS)
    {
        return -WM_FAIL;
    }

    cli.initialized = true;

    return WM_SUCCESS;
}

/* Stop the thread and cleanup */
int cli_stop(void)
{
    if (cli.initialized == false)
    {
        return -WM_FAIL;
    }

    return __cli_cleanup();
}

/*
 *  Command buffer API
 */

/* Get a command buffer */
int cli_get_cmd_buffer(char **buff)
{
    *buff = cli_mem_malloc((int)INBUF_SIZE);
    if (*buff == NULL)
    {
        return -WM_FAIL;
    }

    return WM_SUCCESS;
}

/* Submit a command buffer to the main thread for processing */
int cli_submit_cmd_buffer(char **buff)
{
    int ret   = -WM_FAIL;
    int final = WM_SUCCESS;

    if (buff == NULL)
    {
        (void)PRINTF("Error: release_cmd_buffer given NULL buff\r\n");
        return -WM_FAIL;
    }

    if (cli.initialized != false)
    {
        ret = os_queue_send(&cli.input_queue, (void *)buff, SEND_WAIT);
    }

    if (ret != WM_SUCCESS)
    {
        final = -WM_FAIL;
    }
    return final;
}

/* Built-in "help" command: prints all registered commands and their help
 * text string, if any. */
void help_command(int argc, char **argv)
{
    unsigned int i = 0, n = 0;

    (void)PRINTF("\r\n");
    while (i < MAX_COMMANDS && n < cli.num_commands)
    {
        if (cli.commands[i]->name != NULL)
        {
            (void)PRINTF("%s %s\r\n", cli.commands[i]->name,
                         cli.commands[i]->help != NULL ? cli.commands[i]->help : "");
            n++;
        }
        i++;
    }
}

#if defined(__ICCARM__)
#pragma diag_suppress = Pe192
#endif

static void clear_command(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    PRINTF("\e[1;1H\e[2J");
}

#if 0
static void echo_cmd_handler(int argc, char **argv)
{
	if (argc == 1) {
		(void)PRINTF("Usage: echo on/off. Echo is currently %s\r\n",
			 cli.echo_disabled ? "Disabled" : "Enabled");
		return;
	}

	if (!strcasecmp(argv[1], "on")) {
		(void)PRINTF("Enable echo\r\n");
		cli.echo_disabled = false;
	} else if (!strcasecmp(argv[1], "off")) {
		(void)PRINTF("Disable echo\r\n");
		cli.echo_disabled = true;
	} else
		(void)PRINTF("Usage: echo on/off. Echo is currently %s\r\n",
			 cli.echo_disabled ? "Disabled" : "Enabled");
}
#endif



static struct cli_command built_ins[] = {
    {"help", NULL, help_command},
    {"clear", NULL, clear_command},
};

/*
 * NXP Test Framework API
 */

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

#ifdef CONFIG_UART_INTERRUPT
static void uart_task(void *pvParameters)
{
    usart_config.srcclk = BOARD_DEBUG_UART_CLK_FREQ;
    usart_config.base   = BOARD_DEBUG_UART;

    NVIC_SetPriority(BOARD_UART_IRQ, USART_NVIC_PRIO);

    if (USART_RTOS_Init(&ur_handle, &t_u_handle, &usart_config) != WM_SUCCESS)
    {
        vTaskSuspend(NULL);
    }

    /* Receive user input and send it back to terminal. */
    while (1)
    {
        console_tick();
    }
}

#ifdef CONFIG_HOST_SLEEP
int cli_uart_reinit()
{
    return USART_RTOS_Init(&ur_handle, &t_u_handle, &usart_config);
}

int cli_uart_deinit()
{
    return USART_RTOS_Deinit(&ur_handle);
}

void cli_uart_notify()
{
    xEventGroupSetBits(ur_handle.rxEvent, RTOS_USART_COMPLETE);
}
#endif
#endif

int cli_init(void)
{
    static bool cli_init_done;
    if (cli_init_done)
    {
        return WM_SUCCESS;
    }

    (void)PRINTF("CLI Build: %s [%s]", __DATE__, __TIME__);
    (void)PRINTF("\r\nCopyright  2024  NXP\r\n");

    (void)memset((void *)&cli, 0, sizeof(cli));
    cli.input_enabled = 1;
    cli.in_queue_data = queue_data;

    /* add our built-in commands */
    if (cli_register_commands(&built_ins[0], (int)(sizeof(built_ins) / sizeof(struct cli_command))) != 0)
    {
        return -WM_FAIL;
    }
#ifndef CONFIG_UART_INTERRUPT
    if (cli_install_UART_Tick() != WM_SUCCESS)
    {
        (void)PRINTF(
            "Error: could not install UART Tick function."
            "\r\n");
        return -WM_FAIL;
    }
#endif
    int ret = cli_start();
    if (ret == WM_SUCCESS)
    {
        cli_init_done = true;
    }
#ifdef CONFIG_UART_INTERRUPT
#ifdef CONFIG_UART_INTERACTIVE
    ret = os_thread_create(&uart_thread, "Uart_task", uart_task, 0, &uart_stack, OS_PRIO_1);
#else
#ifdef CONFIG_NCP_BRIDGE
    ret = os_thread_create(&uart_thread, "Uart_task", uart_task, 0, &uart_stack, OS_PRIO_3);
#else
    ret = os_thread_create(&uart_thread, "Uart_task", uart_task, 0, &uart_stack, OS_PRIO_4);
#endif
#endif
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Error: Failed to create uart thread: %d\r\n", ret);
        return -WM_FAIL;
    }
#endif

#ifdef BOARD_NAME
    PRINTF("MCU Board: %s\r\n", BOARD_NAME);
    PRINTF("========================================\r\n");
#endif

    return ret;
}

int cli_deinit(void)
{
    /*Remove our built-in commands */
    if (cli_unregister_commands(&built_ins[0], (int)(sizeof(built_ins) / sizeof(struct cli_command))) != 0)
    {
        return -WM_FAIL;
    }

    return WM_SUCCESS;
}
