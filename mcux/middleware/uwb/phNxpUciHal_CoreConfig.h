/*
 *
 * Copyright 2018-2020,2022 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PHNXPUCIHAL_RHODESCONFIG_H_
#define _PHNXPUCIHAL_RHODESCONFIG_H_

#include "phUwbTypes.h"

#define TYPE_VAL           0
#define TYPE_DATA          1
#define TYPE_STR           2
#define TYPE_EXTENDED_DATA 3

typedef struct
{
    unsigned char key;
    unsigned char type;
    const void *val;
} NxpParam_t;

#define CONFIG_VAL (void *)

typedef enum
{
#if UWBIOT_UWBD_SR1XXT_SR2XXT
    UWB_NXP_CORE_CONFIG_BLOCK_1,
    UWB_NXP_CORE_CONFIG_BLOCK_2,
    UWB_NXP_CORE_CONFIG_BLOCK_3,
    UWB_NXP_CORE_CONFIG_BLOCK_4,
    UWB_NXP_CORE_CONFIG_BLOCK_5,
    UWB_NXP_CORE_CONFIG_BLOCK_6,
    UWB_NXP_CORE_CONFIG_BLOCK_7,
    UWB_NXP_CORE_CONFIG_BLOCK_8,
    UWB_NXP_CORE_CONFIG_BLOCK_9,
    UWB_NXP_CORE_CONFIG_BLOCK_10,
#endif // UWBIOT_UWBD_SR1XXT_SR2XXT
    UWB_NXP_CORE_CONFIG_BLOCK_COUNT,
} NxpUwbConfig;

#endif //_PHNXPUCIHAL_RHODESCONFIG_H_
