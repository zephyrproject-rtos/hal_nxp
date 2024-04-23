/*
 * AES functions
 * Copyright (c) 2003-2006, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef AES_H
#define AES_H

#include <type_def.h>
#ifndef AES_MACROS_DEFINED
enum
{
    AES_ENC_TYPE   = 1, /* cipher unique type */
    AES_ENCRYPTION = 0,
    AES_DECRYPTION = 1,
    AES_BLOCK_SIZE = 16
};
#define AES_MACROS_DEFINED
#endif

#define os_memcpy   (void)memcpy
#define os_memset   (void)memset
#define os_memcmp   memcmp
#define TEST_FAIL() 0

#endif /* AES_H */
