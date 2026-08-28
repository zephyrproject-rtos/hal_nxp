/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#if defined(__ZEPHYR__) && defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER)

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <zephyr/sys/util.h>


#include "fsl_device_registers.h"
#include "ele_nvm_manager.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifndef CONFIG_ELE_NVM_MNG_MAX_CHUNK_SIZE
#define CONFIG_ELE_NVM_MNG_MAX_CHUNK_SIZE 1300u
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Create the filepath of chunk associated with blob_id_msb, blob_id_lsb and blob_ext */
static int get_chunk_file_path(
    char *path, uint8_t path_buf_sz, char *nvm_storage_dname,
    uint32_t blob_id_msb, uint32_t blob_id_lsb, uint32_t blob_ext,
    bool create_path)
{
    uint8_t path_len = 0;

    /* 1 extra byte in path_len is for accommodating null termination char
     * \0 in path string.Since fatfs is not enabled with Long file system
     * names (LFS) due to space limitation, we are only using blob_id_lsb as filename
     * and rest of the unique values like blob_id_msb and lsb are used in the file path.
     * Chunk file path will be named <blob_ext> and the path will be
     * <nvm_storage_dname>/blob_ext/blob_id_msb/blob_id_lsb
     */
    path_len = strlen(nvm_storage_dname) + 1 +  /* 1 additional byte for / after every name */
               sizeof(blob_id_msb) * 2 + 1 +
               sizeof(blob_id_lsb) * 2 + 1 +
               sizeof(blob_ext) * 2 + 1;
    if (path_buf_sz < path_len) {
        return -1;
    }

    snprintf(path, path_len - 1, "%s/%x/%x/%x",
             nvm_storage_dname,
             blob_ext, blob_id_msb, blob_id_lsb);

    return 0;
}

/* Create and write to a file identified by passed blob_id */
status_t zephyr_settings_write(uint32_t blob_id_msb,
                       uint32_t blob_id_lsb,
                       uint32_t blob_ext,
                       uint32_t *chunk,
                       size_t chunk_sz)
{
    char path[64];
    int ret;
    /* Get the filepath of chunk associated with blob ID and blob_ext. */
    if (get_chunk_file_path((char *) path, sizeof(path), "/ele_nvm",
                            blob_id_msb, blob_id_lsb, blob_ext, true)) {
        return kStatus_Fail;
    }

    ret = settings_save_one(path, chunk, chunk_sz);

    switch (ret) {
    case 0:
        return kStatus_Success;
    case -ENOMEM:
    case -ENOSPC:
        return 1;
    default:
        return 1;
    }

    return 0;
}

struct load_params {
    const size_t data_size;
    uint8_t *const data;
    ssize_t ret;
};

static int load_direct_setting(const char *key, size_t len, settings_read_cb read_cb,
                   void *cb_arg, void *param)
{
    (void)key;
    struct load_params *load_params = param;

    load_params->ret = read_cb(cb_arg, load_params->data, MIN(load_params->data_size, len));
    return 0;
}

uint32_t *zephyr_settings_read(uint32_t blob_id_msb,
                               uint32_t blob_id_lsb,
                               uint32_t blob_id_ext,
                               uint32_t *chunk,
                               size_t *sz)
{
    uint32_t *ret;
    char path[64];
    uint32_t *buffer = NULL;

    if (get_chunk_file_path((char *) path, sizeof(path), "/ele_nvm",
                            blob_id_msb, blob_id_lsb, blob_id_ext, false)) {
        return NULL;
    }

    uint32_t data_size = CONFIG_ELE_NVM_MNG_MAX_CHUNK_SIZE;

    /* If buffer for chunk is not passed, allocate based on sie of file */
    if (!chunk) {
        buffer = malloc(data_size);
        chunk  = buffer;
    }

    if (!buffer) {
        return NULL;
    }

    struct load_params load_params = {.data_size = data_size, .data = (uint8_t *const) chunk, .ret = -ENOENT};

    settings_load_subtree_direct(path, load_direct_setting, &load_params);
    if (load_params.ret > 0) {
        *sz = load_params.ret;
        ret = chunk;
    } else {
        ret = NULL;
    }

    return ret;
}

/* Initialize */
int ele_zephyr_settings_initialize(void)
{
    /* Setting init is done by secure-storage module backend */
    return kStatus_Success;
}

#endif /* #if defined(__ZEPHYR__) && defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) */