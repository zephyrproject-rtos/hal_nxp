/*
 * Copyright 2018-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fwk_platform_flash.h"
#include "peripherals.h"
#include "fsl_os_abstraction.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/

struct lfs_mflash_ctx LittleFS_ctx = {LITTLEFS_START_ADDR};

static OSA_MUTEX_HANDLE_DEFINE(mLfsMutexId);

/*******************************************************************************
 * Code
 ******************************************************************************/

int lfs_mflash_read(const struct lfs_config *lfsc, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size)
{
    struct lfs_mflash_ctx *ctx;
    uint32_t               flash_addr;

    assert(lfsc);
    ctx = (struct lfs_mflash_ctx *)lfsc->context;
    assert(ctx);

    flash_addr = ctx->start_addr + block * lfsc->block_size + off;

    if (mflash_drv_read(flash_addr, buffer, size) != kStatus_Success)
        return LFS_ERR_IO;

    return LFS_ERR_OK;
}

int lfs_mflash_prog(
    const struct lfs_config *lfsc, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size)
{
    status_t               status = kStatus_Success;
    struct lfs_mflash_ctx *ctx;
    uint32_t               flash_addr;

    assert(lfsc);
    ctx = (struct lfs_mflash_ctx *)lfsc->context;
    assert(ctx);

    flash_addr = ctx->start_addr + block * lfsc->block_size + off;

    assert(mflash_drv_is_page_aligned(size));

    for (uint32_t page_ofs = 0; page_ofs < size; page_ofs += MFLASH_PAGE_SIZE)
    {
        status = mflash_drv_page_program(flash_addr + page_ofs, (void *)((uintptr_t)buffer + page_ofs));
        if (status != kStatus_Success)
            break;
    }

    if (status != kStatus_Success)
        return LFS_ERR_IO;

    return LFS_ERR_OK;
}

int lfs_mflash_erase(const struct lfs_config *lfsc, lfs_block_t block)
{
    status_t               status = kStatus_Success;
    struct lfs_mflash_ctx *ctx;
    uint32_t               flash_addr;

    assert(lfsc);
    ctx = (struct lfs_mflash_ctx *)lfsc->context;
    assert(ctx);

    flash_addr = ctx->start_addr + block * lfsc->block_size;

    for (uint32_t sector_ofs = 0; sector_ofs < lfsc->block_size; sector_ofs += MFLASH_SECTOR_SIZE)
    {
        status = mflash_drv_sector_erase(flash_addr + sector_ofs);
        if (status != kStatus_Success)
            break;
    }

    if (status != kStatus_Success)
        return LFS_ERR_IO;

    return LFS_ERR_OK;
}

int lfs_mflash_sync(const struct lfs_config *lfsc)
{
    return LFS_ERR_OK;
}

int lfs_get_default_config(struct lfs_config *lfsc)
{
    *lfsc = LittleFS_config; /* copy pre-initialized lfs config structure */
    return 0;
}

int lfs_storage_init(const struct lfs_config *lfsc)
{
    status_t status;

    /* Mutex create */
    (void)OSA_MutexCreate(mLfsMutexId);
    assert(NULL != mLfsMutexId);

    /* initialize mflash */
    status = mflash_drv_init();

    return status;
}

int lfs_mutex_lock(const struct lfs_config *lfsc)
{
    (void)OSA_MutexLock((osa_mutex_handle_t)mLfsMutexId, osaWaitForever_c);

    return LFS_ERR_OK;
}

int lfs_mutex_unlock(const struct lfs_config *lfsc)
{
    (void)OSA_MutexUnlock((osa_mutex_handle_t)mLfsMutexId);

    return LFS_ERR_OK;
}
