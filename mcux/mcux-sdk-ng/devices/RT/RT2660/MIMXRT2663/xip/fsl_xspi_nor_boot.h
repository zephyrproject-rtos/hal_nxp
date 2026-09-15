/*
 * Copyright 2024-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __XSPI_NOR_BOOT_H__
#define __XSPI_NOR_BOOT_H__

#include <stdint.h>

/* Container header definition */
#define CONTAINER_VER                    0x02
#define CONTAINER_SIZE                   ((uint16_t)sizeof(boot_container_t))
#define CONTAINER_HEADER_TAG             0x87
#define CONTAINER_FLAGS                  0x00000000
#define CONTAINER_SW_VER                 0
#define CONTAINER_FUSE_VER               1
#define CONTAINER_NUM_IMG                1
#define CONTAINER_SIGNATURE_BLOCK_OFFSET ((uint16_t)(sizeof(boot_container_header_t) + CONTAINER_NUM_IMG * sizeof(boot_image_entry_t)))
#define CONTAINER_CERT_VER               1
typedef struct __attribute__((packed))
{
    uint8_t  version;
    uint16_t length;
    uint8_t  tag;

    uint32_t flags;

    uint16_t sw_ver;
    uint8_t  fuse_ver;
    uint8_t  num_images;

    uint16_t signature_block_offset;
    uint8_t  cert_ver;
    uint8_t  reserved1;
} boot_container_header_t;

/* Image array definition */
#define IMG_FLAGS 0x00000213  /* Type=Executable (0x3) | Core ID=0x1 (CM85) | Hash Type=SHA2_512 (0x2) */
typedef struct __attribute__((packed))
{
    uint32_t offset;
    uint32_t size;
    uint32_t load_addr;
    uint32_t load_addr_high;
    uint32_t entry;
    uint32_t entry_high;
    uint32_t flags;
    uint32_t metadata;  /* Reserved for NXP firmware; OEM images must write 0 */
    uint8_t  hash[64];
    uint8_t  iv[32];
} boot_image_entry_t;

/* Signature block definition */
#define SIGNATURE_BLOCK_VER     0x01
#define SIGNATURE_BLOCK_SIZE    ((uint16_t)sizeof(boot_signature_block_t))
#define SIGNATURE_BLOCK_TAG     0x90
typedef struct __attribute__((packed))
{
    uint8_t  version;
    uint16_t length;
    uint8_t  tag;

    uint16_t cert_offset;
    uint16_t srk_table_array_offset;

    uint16_t signature_offset;
    uint16_t blob_offset;

    uint32_t key_identifier;
} boot_signature_block_t;

/* Container layout */
typedef struct __attribute__((packed))
{
    boot_container_header_t header;
    boot_image_entry_t      image_array[CONTAINER_NUM_IMG];
    boot_signature_block_t  signature_block;
} boot_container_t;

#if defined(__ICCARM__)
#pragma section = "RO"
extern uint32_t __CONTAINER_IMG_OFFSET[];
extern uint32_t __CONTAINER_IMG_LOAD_ADDR[];
extern uint32_t __CONTAINER_IMG_ENTRY_ADDR[];
#define IMAGE_OFFSET        ((uint32_t)__CONTAINER_IMG_OFFSET)
#define IMAGE_SIZE          ((uint32_t)__section_size("RO"))
#define IMAGE_LOAD_ADDRESS  ((uint32_t)__CONTAINER_IMG_LOAD_ADDR)
#define IMAGE_ENTRY_ADDRESS ((uint32_t)__CONTAINER_IMG_ENTRY_ADDR)

#elif defined(__ARMCC_VERSION)
extern uint32_t Image$$ER_m_container_image_offset$$ZI$$Base[];
extern uint32_t Image$$VECTOR_ROM$$Base[];
extern uint32_t Load$$LR$$LR_m_text$$Length[];
#define IMAGE_OFFSET        ((uint32_t)Image$$ER_m_container_image_offset$$ZI$$Base)
#define IMAGE_SIZE          ((uint32_t)Load$$LR$$LR_m_text$$Length)
#define IMAGE_LOAD_ADDRESS  ((uint32_t)Image$$VECTOR_ROM$$Base)
#define IMAGE_ENTRY_ADDRESS ((uint32_t)Image$$VECTOR_ROM$$Base)

#elif defined(__GNUC__)
extern uint32_t __CONTAINER_IMG_OFFSET[];
extern uint32_t __CONTAINER_IMG_SIZE[];
extern uint32_t __VECTOR_TABLE[];
#define IMAGE_OFFSET        ((uint32_t)__CONTAINER_IMG_OFFSET)
#define IMAGE_SIZE          ((uint32_t)__CONTAINER_IMG_SIZE)
#define IMAGE_LOAD_ADDRESS  ((uint32_t)__VECTOR_TABLE)
#define IMAGE_ENTRY_ADDRESS ((uint32_t)__VECTOR_TABLE)
#endif

#endif /* __XSPI_NOR_BOOT_H__ */
