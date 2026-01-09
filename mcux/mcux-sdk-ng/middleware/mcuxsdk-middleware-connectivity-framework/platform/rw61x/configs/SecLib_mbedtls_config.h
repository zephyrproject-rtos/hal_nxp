/* -------------------------------------------------------------------------- */
/*                          Copyright 2023-2024 NXP                           */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef SECLIBAPP_MBEDTLS_CONFIG_H
#define SECLIBAPP_MBEDTLS_CONFIG_H

#define MCUX_ENABLE_TRNG_AS_ENTROPY_SEED

#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#define MBEDTLS_MCUX_FREERTOS_THREADING_ALT
#define MBEDTLS_THREADING_C
#define MBEDTLS_THREADING_ALT
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_STD_CALLOC pvPortCalloc
#define MBEDTLS_PLATFORM_STD_FREE   vPortFree
#endif /* USE_RTOS*/

/* SDK mbedtls config include */
#include "els_pkc_mbedtls_config.h"

/* Undef this flag to make sure to use hardware entropy */
#undef MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES

#endif // SECLIBAPP_MBEDTLS_CONFIG_H
