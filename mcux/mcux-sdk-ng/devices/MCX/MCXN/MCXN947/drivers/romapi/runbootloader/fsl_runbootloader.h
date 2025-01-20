/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_RUN_BOOTLOADER_H_
#define FSL_RUN_BOOTLOADER_H_

#include "fsl_common.h"

/*!
 * @addtogroup runbootloader
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief ROMAPI_RUNBOOTLOADER driver version 2.0.0. */
#define FSL_ROMAPI_RUNBOOTLOADER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*   API prototype fields definition.
| 31 : 24   |    23 : 20        |     19 : 16        |  15 : 04  |  03 : 00        |
|    Tag    |   Boot mode       |   ISP interface    |  Reserved |  Image Index    |
|           |                   |                    |           |                 |
|           | 0: Master mode    | 0 - Auto detection |           | For boot mode 0 |
|           | 1: ISP mode       | 1 - UART           |           |                 |
|           |                   | 2 - SPI            |           |                 |
|           |                   | 3 - I2C            |           |                 |
|           |                   | 4 - USB FS HID     |           |                 |
|           |                   | 5 - USB HS HID     |           |                 |
|           |                   | 6 - CAN            |           |                 |
*/

typedef struct
{
    union
    {
        struct
        {
            uint32_t boot_image_index : 4;
            uint32_t reserved : 12;
            uint32_t boot_interface : 4;
            uint32_t mode : 4;
            uint32_t tag : 8;
        } B;
        uint32_t U;
    } option;
} user_app_boot_invoke_option_t;

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Run the Bootloader API  to force into the ISP mode base on the user arg
 *
 * @param arg Indicates API prototype fields definition. Refer to the above user_app_boot_invoke_option_t structure
 */
void bootloader_user_entry(void *arg);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* FSL_RUN_BOOTLOADER_H_ */
