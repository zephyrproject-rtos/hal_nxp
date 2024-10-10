/** @file cli_utils.c
 *
 *  @brief This file provides  Convenience functions for the CLI
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* cli_utils.c: Convenience functions for the CLI
 *
 */
#include <string.h>
#include <stdlib.h>
#include <wm_utils.h>
#include <cli_utils.h>
#include <ctype.h>
#include <wm_net.h> /* for errno */

bool string_equal(const char *s1, const char *s2)
{
    size_t len = strlen(s1);

    if (len == strlen(s2) && (strncmp(s1, s2, len) == 0))
    {
        return true;
    }
    return false;
}

/**
 *@brief convert char to hex integer
 *
 *@param chr          char
 *@return             hex integer
 **/
unsigned char hexc2bin(char chr)
{
    if (chr >= '0' && chr <= '9')
    {
        chr -= '0';
    }
    else if (chr >= 'A' && chr <= 'F')
    {
        chr -= ('A' - 10);
    }
    else if (chr >= 'a' && chr <= 'f')
    {
        chr -= ('a' - 10);
    }
    else
    { /* Do Nothing */
    }
    return (uint8_t)chr;
}

/**
 *@brief convert string to hex integer
 *
 *@param s            A pointer string buffer
 *@return             hex integer
 **/
unsigned int a2hex(const char *s)
{
    uint32_t val = 0;

    if (strncmp("0x", s, 2) == 0 || strncmp("0X", s, 2) == 0)
    {
        s += 2;
    }

    while ((*s != '\0') && (isxdigit((unsigned char)(*s)) != 0))
    {
        val = (val << 4) + hexc2bin(*s++);
    }
    return val;
}

/*
 * @brief convert String to integer
 *
 *@param value        A pointer to string
 *@return             integer
 **/
unsigned int a2hex_or_atoi(char *value)
{
    unsigned int ret = 0;

    if (value[0] == '0' && (value[1] == 'X' || value[1] == 'x'))
    {
        ret = a2hex(value + 2);
    }
    else if (isdigit((unsigned char)*value) != 0)
    {
        errno = 0;
        ret   = (uint32_t)strtol(value, NULL, 10);
        if (errno != 0)
        {
            (void)PRINTF("Error during strtoul errno:%d", errno);
        }
    }
    else
    {
        ret = (uint32_t)(*value);
    }
    return ret;
}

bool get_uint(const char *arg, unsigned int *dest, unsigned int len)
{
    unsigned int i;
    unsigned int val = 0;

    for (i = 0; i < len; i++)
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            return true;
        }
        val *= 10U;
        val += (unsigned int)arg[i] - (unsigned int)'0';
    }

    *dest = val;
    return false;
}

/* Parse string 'arg' formatted "AA:BB:CC:DD:EE:FF" (assuming 'sep' is ':')
 * into a 6-byte array 'dest' such that dest = {0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}
 * set 'sep' accordingly. */
bool get_mac(const char *arg, char *dest, char sep)
{
    unsigned char n;
    int i, j, k = 0;
    int l = 0;

    if (strlen(arg) < 17U)
    {
        return true;
    }

    (void)memset(dest, 0, 6);

    for (i = 0; i < 17; i += 3)
    {
        for (j = 0; j < 2; j++)
        {
            if (arg[i + j] >= '0' && arg[i + j] <= '9')
            {
                n = (unsigned char)(arg[i + j]) - (unsigned char)'0';
            }
            else if (arg[i + j] >= 'A' && arg[i + j] <= 'F')
            {
                n = (unsigned char)(arg[i + j]) - (unsigned char)'A' + (unsigned char)10;
            }
            else if (arg[i + j] >= 'a' && arg[i + j] <= 'f')
            {
                n = (unsigned char)(arg[i + j]) - (unsigned char)'a' + (unsigned char)10;
            }
            else
            {
                return true;
            }

            l = 1 - j;

            n <<= (unsigned int)4 * (unsigned int)l;
            dest[k] += n;
        }
        if (i < 15 && arg[i + 2] != sep)
        {
            return true;
        }
        k++;
    }

    return false;
}

#if defined(RW610) && (CONFIG_ANT_DETECT)
bool get_channel_list(const char *arg, uint8_t *num_channels, uint8_t *chan_number, char sep)
{
    unsigned int len = 0;
    unsigned int i;
    uint8_t count = 0;
    uint8_t val   = 0;

    len = strlen(arg);

    if (len == 0U)
    {
        (void)PRINTF("Error: len == 0\r\n");
        return true;
    }

    for (i = 0; i < len; i++)
    {
        if (arg[i] == sep)
        {
            chan_number[count] = val;
            count++;
            val = 0;
            continue;
        }

        if (arg[i] < '0' || arg[i] > '9')
        {
            return true;
        }
        val *= 10U;
        val += (uint8_t)arg[i] - (uint8_t)'0';

        if (i == len - 1)
        {
            chan_number[count] = val;
        }
    }

    *num_channels = count + 1;
    return false;
}
#endif

/* Non-reentrant getopt implementation */
int cli_optind   = 0;
char *cli_optarg = NULL;
int cli_getopt(int argc, char **argv, const char *fmt)
{
    char *opt, *c;

    if (cli_optind == argc)
    {
        return -1;
    }
    cli_optarg = NULL;
    opt        = argv[cli_optind];
    if (opt[0] != '-')
    {
        return -1;
    }
    if (opt[0] == '\0' || opt[1] == '\0')
    {
        return (int)'?';
    }
    cli_optind++;
    c = strchr(fmt, (int)opt[1]);
    if (c == NULL)
    {
        return (int)opt[1];
    }
    if (c[1] == ':')
    {
        if (cli_optind < argc)
        {
            cli_optarg = argv[cli_optind++];
        }
    }
    return (int)c[0];
}

/* allocate a copy of a string */
char *string_dup(const char *s)
{
    char *snew = (char *)OSA_MemoryAllocate(strlen(s) + 1);
    if (snew)
        (void)strcpy(snew, s);
    return snew;
}
