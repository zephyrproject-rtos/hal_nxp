/****************************************************************************
 *
 * Copyright (c) 2016 Wi-Fi Alliance
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE
 * USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *****************************************************************************/

#ifndef WFA_DEBUG_H
#define WFA_DEBUG_H

#include "wfa_stdincs.h"

#define WFA_ERR 0x0001 /* error: can be redefined to a log file */
#define WFA_OUT 0x0002 /* info:  can be redefined to a log file */
#define WFA_WNG 0x0004 /* warning: can be redefined to a log file */

#define WFA_DEBUG_DEFAULT 0x0001
#define WFA_DEBUG_ERR     0x0001
#define WFA_DEBUG_INFO    0x0002
#define WFA_DEBUG_WARNING 0x0004

#define WFA_DEBUG 1

static inline void print_callback(int level, const char *fmt, ...)
{
    va_list ap;
    char buffer[128];

    va_start(ap, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, ap);
    va_end(ap);

    switch (level)
    {
        case WFA_ERR:
            PRINTF("Error: %s\r\n", buffer);
            break;
        case WFA_WNG:
            PRINTF("Warning: %s\r\n", buffer);
            break;
        case WFA_OUT:
            PRINTF("Info: %s\r\n", buffer);
            break;
        default:
            break;
    }
}

#define PRINTM_WFA_ERR(msg...)        \
    do                                \
    {                                 \
        print_callback(WFA_ERR, msg); \
    } while (0)
#define PRINTM_WFA_OUT(msg...)        \
    do                                \
    {                                 \
        print_callback(WFA_OUT, msg); \
    } while (0)
#define PRINTM_WFA_WNG(msg...)        \
    do                                \
    {                                 \
        print_callback(WFA_WNG, msg); \
    } while (0)

#define PRINTM(level, msg...) PRINTM_##level((char *)msg)

#define DPRINT_ERR                                                    \
    PRINTM(WFA_ERR, "File %s, Line %ld: ", __FILE__, (long)__LINE__); \
    PRINTM

#define DPRINT_INFO     \
    if (WFA_DEBUG_INFO) \
    PRINTM

#define DPRINT_WARNING     \
    if (WFA_DEBUG_WARNING) \
    PRINTM

#endif
