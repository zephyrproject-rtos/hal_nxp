/*
 * Copyright 2020, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/* Configuration file for mbedtls for Application */

#ifndef SECLIBAPP_MBEDTLS_CONFIG_H
#define SECLIBAPP_MBEDTLS_CONFIG_H

#include "fsl_component_mem_manager.h"

#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_FREE_MACRO   MEM_BufferFree
#define MBEDTLS_PLATFORM_CALLOC_MACRO MEM_CallocAlt

#define MBEDTLS_NXP_SSSAPI      1
#define MBEDTLS_NXP_SENTINEL200 1

#if !defined gSecLibSha1Enable_d || (gSecLibSha1Enable_d == 0)
#undef MBEDTLS_SHA1_C
#endif

#define MBEDTLS_ECDH_ALT
#undef MBEDTLS_BLOWFISH_C
#undef MBEDTLS_MD5_C
#undef MBEDTLS_CAMELLIA_C
#undef MBEDTLS_DES_C
#undef MBEDTLS_ARIA_C
#undef MBEDTLS_PK_RSA_ALT_SUPPORT
#undef MBEDTLS_PKCS12_C
#undef MBEDTLS_CHACHAPOLY_C
#undef MBEDTLS_CHACHA20_C
#undef MBEDTLS_GCM_C
#undef MBEDTLS_ARC4_C
#undef MBEDTLS_AESNI_C
//#define MBEDTLS_ECDH_GEN_PUBLIC_ALT TODO

#undef MBEDTLS_SSL_CBC_RECORD_SPLITTING
#undef MBEDTLS_SSL_PROTO_TLS1
#undef MBEDTLS_SSL_PROTO_TLS1_1

#endif