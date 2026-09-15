/*
 * Copyright 2024-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_xspi_nor_boot.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xip_device"
#endif

#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)

#if defined(__ARMCC_VERSION) || defined(__GNUC__)
__attribute__((section(".boot_hdr.container"), used))
#elif defined(__ICCARM__)
#pragma location = ".boot_hdr.container"
#endif

/* clang-format off */
const boot_container_t container_data =
{
    /* Container Header */
    {
        CONTAINER_VER,                           /* version                */
        CONTAINER_SIZE,                          /* length                 */
        CONTAINER_HEADER_TAG,                    /* tag                    */
        CONTAINER_FLAGS,                         /* flags                  */
        CONTAINER_SW_VER,                        /* sw_ver                 */
        CONTAINER_FUSE_VER,                      /* fuse_ver               */
        CONTAINER_NUM_IMG,                       /* num_images             */
        CONTAINER_SIGNATURE_BLOCK_OFFSET,        /* signature_block_offset */
        CONTAINER_CERT_VER,                      /* cert_ver               */
        0                                        /* reserved1              */
    },
    /* Image Array */
    {{
        IMAGE_OFFSET,                            /* offset         */
        IMAGE_SIZE,                              /* size           */
        IMAGE_LOAD_ADDRESS,                      /* load_addr      */
        0,                                       /* load_addr_high */
        IMAGE_ENTRY_ADDRESS,                     /* entry          */
        0,                                       /* entry_high     */
        IMG_FLAGS,                               /* flags          */
        0,                                       /* metadata       */
        {0},                                     /* hash[64]       */
        {0}                                      /* iv[32]         */
    }},
    /* Signature Block */
    {
        SIGNATURE_BLOCK_VER,                     /* version                */
        SIGNATURE_BLOCK_SIZE,                    /* length                 */
        SIGNATURE_BLOCK_TAG,                     /* tag                    */
        0,                                       /* cert_offset            */
        0,                                       /* srk_table_array_offset */
        0,                                       /* signature_offset       */
        0,                                       /* blob_offset            */
        0                                        /* key_identifier         */
    }
};
/* clang-format on */

#endif
