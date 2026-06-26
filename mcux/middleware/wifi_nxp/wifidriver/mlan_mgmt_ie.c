/** @file mlan_mgmt_ie.c
 *
 *  @brief  This file provides functions for MGMT IE management
 *
 *  Copyright 2026 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <mlan_api.h>
#include <osa.h>
#if defined(RW610)
#include "wifi-imu.h"
#else
#include "wifi-sdio.h"
#endif
#include "mlan_mgmt_ie.h"

/********************************************************
    Local Variables
********************************************************/

/** Custom IE header size */
#define MLAN_CUSTOM_IE_HDR_SIZE (sizeof(custom_ie) - MAX_IE_SIZE)

static mlan_buf_cfg s_mgmt_buf_cfgs[] = {
    {MLAN_MGMT_BUF_SM_SIZE, 0},
    {MLAN_MGMT_BUF_MD_SIZE, 0},
    {MLAN_MGMT_BUF_LG_SIZE, 0}
};

#define MGMT_BUFPOOL_NUM (sizeof(s_mgmt_buf_cfgs)/sizeof(s_mgmt_buf_cfgs[0]))

#define IE_MASK_WPS    0x0001
#define IE_MASK_P2P    0x0002
#define IE_MASK_WFD    0x0004
#define IE_MASK_VENDOR 0x0008
#define IE_MASK_EXTCAP 0x0010

static OSA_MUTEX_HANDLE_DEFINE(s_ie_mutex);

static mlan_buf_handle s_mgmt_buf_handle = {0};
static mlan_buf_class s_mlan_buf_class[MGMT_BUFPOOL_NUM] = {0};
static bool s_mgmt_ie_initialized = false;

/********************************************************
                Local Functions
********************************************************/

static void *wrapper_buffer_malloc(t_u32 size)
{
#if !CONFIG_MEM_POOLS
    return OSA_MemoryAllocate((uint32_t)size);
#else
    if (size <= 256U)
    {
        return OSA_MemoryPoolAllocate(buf_256_MemoryPool);
    }
    else if (size <= 512U)
    {
        return OSA_MemoryPoolAllocate(buf_512_MemoryPool);
    }
    else
    {
        return OSA_MemoryPoolAllocate(buf_2048_MemoryPool);
    }
#endif
}

static void wrapper_buffer_free(void *ptr)
{
    if (ptr == MNULL)
    {
        return;
    }

#if !CONFIG_MEM_POOLS
    OSA_MemoryFree(ptr);
#else
#define POOL_256_SZ     (256 * 8 + 8 * sizeof(uint32_t))
#define POOL_512_SZ     (512 * 4 + 4 * sizeof(uint32_t))
#define POOL_2048_SZ    (2048 * 4 + 4 * sizeof(uint32_t))
    if (ptr >= buf_256_MemoryPool && ptr < ((t_u8 *)buf_256_MemoryPool + POOL_256_SZ))
    {
        OSA_MemoryPoolFree(buf_256_MemoryPool, ptr);
    }
    else if (ptr >= buf_512_MemoryPool && ptr < ((t_u8 *)buf_512_MemoryPool + POOL_512_SZ))
    {
        OSA_MemoryPoolFree(buf_512_MemoryPool, ptr);
    }
    else if (ptr >= buf_2048_MemoryPool && ptr < ((t_u8 *)buf_2048_MemoryPool + POOL_2048_SZ))
    {
        OSA_MemoryPoolFree(buf_2048_MemoryPool, ptr);
    }
    else
    {
        wifi_e("Invalid pointer to free %p", ptr);
    }
#endif
}

static inline void wrapper_mgmt_ie_lock(void)
{
    (void)OSA_MutexLock((osa_mutex_handle_t)s_ie_mutex, osaWaitForever_c);
}

static inline void wrapper_mgmt_ie_unlock(void)
{
    (void)OSA_MutexUnlock((osa_mutex_handle_t)s_ie_mutex);
}

/**
 * @brief Initialize a tiered buffer pool.
 *
 * Allocates a single contiguous memory region and partitions it into
 * @p num buffer classes, each with a fixed block size and count as
 * described by @p cfgs[].  All free blocks within each class are linked
 * into a singly-linked free list.
 *
 * Memory layout (contiguous):
 *   [ class-0 blocks ... ][ class-1 blocks ... ] ... [ class-(num-1) blocks ]
 *
 * Each block = mlan_buf_block header + data area, 4-byte aligned.
 *
 * @param handle     Output handle that tracks the pool state
 * @param classes    Array of @p num mlan_buf_class descriptors to populate
 * @param cfgs       Array of @p num configuration entries (buf_size, buf_cnt)
 * @param num        Number of buffer classes
 * @param malloc_fn  Allocator used for the memory region
 * @param free_fn    Deallocator paired with @p malloc_fn
 *
 * @return  0 on success, -1 on invalid arguments or allocation failure
 */
static t_s8 util_buf_pool_init(pmlan_buf_handle handle,
                                pmlan_buf_class classes,
                                pmlan_buf_cfg cfgs,
                                t_u32 num,
                                void *(*malloc_fn)(t_u32),
                                void (*free_fn)(void *))
{
    t_u8 i;
    t_u16 j;
    t_u32 total_size = 0;
    t_u32 block_size = 0;
    t_u8 *pos           = MNULL;
    pmlan_buf_block blk = MNULL;

    if (!handle || !classes || !cfgs || num == 0 || !malloc_fn || !free_fn)
    {
        return -1;
    }

    (void)memset(handle, 0, sizeof(*handle));

    handle->classes   = classes;
    handle->class_num = num;
    handle->malloc_fn = malloc_fn;
    handle->free_fn   = free_fn;

    /* Pass 1: calculate the total memory required across all classes. */
    for (i = 0; i < num; i++)
    {
        if (cfgs[i].buf_size == 0)
        {
            return -1;
        }

        block_size = ALIGN_SZ((sizeof(mlan_buf_block) + cfgs[i].buf_size), 4);
        total_size += block_size * cfgs[i].buf_cnt;
    }

    if (total_size == 0)
    {
        return -1;
    }

    /* Allocate one contiguous region for all classes */
    handle->mem_base = (t_u8 *)malloc_fn(total_size);
    if (!handle->mem_base)
    {
        return -1;
    }
    handle->mem_size = total_size;

    pos = handle->mem_base;

    /* Pass 2: partition the region into classes and build each free list. */
    for (i = 0; i < num; i++)
    {
        classes[i].free_list = MNULL;
        classes[i].buf_size  = cfgs[i].buf_size;
        classes[i].total     = cfgs[i].buf_cnt;
        classes[i].class_id  = i;
        classes[i].base      = pos;

        block_size = ALIGN_SZ((sizeof(mlan_buf_block) + classes[i].buf_size), 4);

        for (j = 0; j < classes[i].total; j++)
        {
            blk = (pmlan_buf_block)(pos + j * block_size);
            blk->next     = classes[i].free_list;
            blk->class_id = i;
            blk->magic    = 0;
            classes[i].free_list = blk;
        }

        pos += block_size * classes[i].total;
    }

    return 0;
}

/**
 * @brief Deinitialize a buffer pool
 *
 * @param handle  Pool handle.
 */
static void util_buf_pool_deinit(pmlan_buf_handle handle)
{
    t_u8 i;

    if (!handle)
    {
        return;
    }

    if (handle->classes)
    {
        for (i = 0; i < handle->class_num; i++)
        {
            handle->classes[i].free_list = MNULL;
            handle->classes[i].buf_size  = 0;
            handle->classes[i].total     = 0;
            handle->classes[i].class_id  = 0;
            handle->classes[i].base      = MNULL;
        }
    }

    if (handle->mem_base)
    {
        handle->free_fn(handle->mem_base);
        handle->mem_base = MNULL;
    }

    handle->mem_size  = 0;
    handle->classes   = MNULL;
    handle->class_num = 0;
    handle->malloc_fn = MNULL;
    handle->free_fn   = MNULL;
}

/**
 * @brief Allocate a data buffer from the pool.
 *
 * Iterates the buffer classes in ascending size order and returns the data
 * area of the first free block whose buf_size >= @p size.  The block's magic
 * field is set to MLAN_BUF_MAGIC to mark it as allocated.
 *
 * @param handle  Pool handle
 * @param size    Minimum number of usable data bytes required
 *
 * @return  Pointer to the data area on success, NULL if no suitable free
 *          block is available or arguments are invalid
 */
static t_u8 *util_buf_pool_alloc(pmlan_buf_handle handle, t_u16 size)
{
    t_u8 i;
    pmlan_buf_class cls = MNULL;
    pmlan_buf_block blk = MNULL;

    if (!handle || size == 0)
    {
        return MNULL;
    }

    for (i = 0; i < handle->class_num; i++)
    {
        cls = &handle->classes[i];

        if (size <= cls->buf_size && cls->free_list != MNULL)
        {
            blk = cls->free_list;
            cls->free_list = blk->next;
            blk->magic = MLAN_BUF_MAGIC;
            return blk->data;
        }
    }

    return MNULL;
}

/**
 * @brief Free a data buffer back to the pool.
 *
 * @param handle  Pool handle.
 * @param ptr     Pointer to the data area of the buffer to free.
 */
static void util_buf_pool_free(pmlan_buf_handle handle, void *ptr)
{
    pmlan_buf_block blk = MNULL;
    pmlan_buf_class cls = MNULL;
    t_u32 block_size = 0;

    if (!handle || !ptr)
    {
        return;
    }

    blk = util_container_of(ptr, mlan_buf_block, data);
    if (blk->magic != MLAN_BUF_MAGIC)
    {
        return;
    }

    if (blk->class_id >= handle->class_num)
    {
        return;
    }

    cls = &handle->classes[blk->class_id];
    /* Bounds-check: ensure the block actually belongs to this class's region */
    block_size = ALIGN_SZ(sizeof(mlan_buf_block) + cls->buf_size, 4);
    if ((t_u8 *)blk < cls->base || (t_u8 *)blk >= (cls->base + block_size * cls->total))
    {
        return;
    }

    blk->next      = cls->free_list;
    blk->magic     = 0;
    cls->free_list = blk;
}

/**
 * @brief Resize a pool buffer migration to a different class.
 *
 * Three outcomes are possible:
 *  1. @p new_size > current class buf_size, allocate a larger block, copy
 *     MIN(@p data_len, old_buf_size) bytes, free the old block, return new ptr.
 *  2. @p new_size fits in a smaller class and a free block is available,
 *     migrate down, copy data, free old block, return new ptr.
 *  3. Neither upgrade nor downgrade is needed/possible, return @p ptr
 *     unchanged (no copy, no free).
 *
 * On allocation failure during upgrade, returns NULL.
 *
 * @param handle    Pool handle
 * @param ptr       Existing data pointer to resize
 * @param data_len  Number of valid bytes currently in @p ptr to preserve
 * @param new_size  New size
 *
 * @return  Pointer to the (possibly new) data area, or NULL on failure
 */
static void *util_buf_pool_renew(pmlan_buf_handle handle,
                            void *ptr,
                            t_u16 data_len,
                            t_u16 new_size)
{
    pmlan_buf_block blk      = MNULL;
    pmlan_buf_class cls      = MNULL;
    pmlan_buf_block new_blk  = MNULL;
    pmlan_buf_class best_cls = MNULL;
    void *new_ptr            = MNULL;
    t_u8 i;

    if (!handle || !ptr)
    {
        return MNULL;
    }

    blk = util_container_of(ptr, mlan_buf_block, data);

    if (blk->magic != MLAN_BUF_MAGIC)
    {
        return MNULL;
    }

    if (blk->class_id >= handle->class_num)
    {
        return MNULL;
    }

    cls = &handle->classes[blk->class_id];

    /* If current buffer is too small, allocate a larger one */
    if (new_size > cls->buf_size)
    {
        new_ptr = util_buf_pool_alloc(handle, new_size);
        if (!new_ptr)
        {
            return MNULL;
        }

        (void)memcpy(new_ptr, ptr, MIN(data_len, cls->buf_size));
        util_buf_pool_free(handle, ptr);
        return new_ptr;
    }

    /* Try to find a smaller class that can hold the data */
    for (i = 0; i < blk->class_id; i++)
    {
        best_cls = &handle->classes[i];

        if (best_cls->buf_size >= new_size && best_cls->free_list != MNULL)
        {
            new_blk             = best_cls->free_list;
            best_cls->free_list = new_blk->next;
            new_blk->magic      = MLAN_BUF_MAGIC;
            new_ptr             = new_blk->data;

            (void)memcpy(new_ptr, ptr, MIN(data_len, best_cls->buf_size));
            util_buf_pool_free(handle, ptr);
            return new_ptr;
        }
    }

    /* no class change required or possible — return as-is */
    return ptr;
}

/**
 * @brief Allocate an IE data buffer from the MGMT IE pool.
 *
 * @param size  Required buffer size
 * @return      Pointer to the data area, or NULL if the pool is exhausted
 */
static inline t_u8 *ie_buf_get(t_u16 size)
{
    return util_buf_pool_alloc(&s_mgmt_buf_handle, size);
}

/**
 * @brief Return an IE data buffer to the MGMT IE pool.
 *
 * @param buf   IE data buffer pointer to free
 */
static inline void ie_buf_put(t_u8 *buf)
{
    util_buf_pool_free(&s_mgmt_buf_handle, buf);
}

/**
 * @brief Resize an IE data buffer within the MGMT IE pool.
 *
 * @param buf       Existing IE buffer pointer
 * @param data_len  Number of valid bytes currently in @p buf to preserve
 * @param new_size  New size
 *
 * @return  Pointer to the (possibly reallocated) buffer, or NULL on failure
 */
static inline t_u8 *ie_buf_renew(t_u8 *buf, t_u16 data_len, t_u16 new_size)
{
    return util_buf_pool_renew(&s_mgmt_buf_handle, buf, data_len, new_size);
}

static inline void mgmt_ie_entry_clear(pmlan_adapter pmadapter, t_u16 idx)
{
    if (idx >= MAX_MGMT_IE_DRV_INDEX)
    {
        return;
    }

    pmadapter->mgmt_ie[idx].bss_type   = MLAN_BSS_TYPE_ANY;
    pmadapter->mgmt_ie[idx].cust_ie    = MNULL;
    pmadapter->mgmt_ie[idx].ie_offset  = 0;
    pmadapter->mgmt_ie[idx].cur_ie_len = 0;
}

static inline void mgmt_buffer_entry_clear(pmlan_adapter pmadapter, t_u16 idx)
{
    if (idx >= MAX_MGMT_IE_FW_INDEX)
    {
        return;
    }

    pmadapter->mgmt_buffer[idx].ie_index          = MLAN_MGMT_IE_INVALID_IDX;
    pmadapter->mgmt_buffer[idx].mgmt_subtype_mask = MLAN_MGMT_IE_INVALID_MASK;
    pmadapter->mgmt_buffer[idx].ie_length         = 0;
    pmadapter->mgmt_buffer[idx].dirty             = 0;
    if (pmadapter->mgmt_buffer[idx].ie_buf != MNULL)
    {
        ie_buf_put(pmadapter->mgmt_buffer[idx].ie_buf);
        pmadapter->mgmt_buffer[idx].ie_buf = MNULL;
    }
}

/**
 * @brief Append a custom IE to the TLV payload.
 *
 * @param pos           IN/OUT: current position in the custom IE buffer to append to
 * @param remain_len    IN/OUT: number of bytes remaining in the buffer after @p pos
 * @param total_len     IN/OUT: total length of valid data in the buffer after appending
 * @param src           Source IE header containing the IE to append
 *
 * @return              MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status append_custom_ie(custom_ie **pos, t_u32 *remain_len, t_u16 *total_len, custom_ie_hdr *src)
{
    t_u16 len;

    if (!src)
    {
        return MLAN_STATUS_SUCCESS;
    }

    len = MLAN_CUSTOM_IE_HDR_SIZE + src->ie_length;
    if (len > *remain_len)
    {
        return MLAN_STATUS_FAILURE;
    }

    (*pos)->ie_index = src->ie_index;
    (*pos)->mgmt_subtype_mask = src->mgmt_subtype_mask;
    (*pos)->ie_length = src->ie_length;

    memcpy((*pos)->ie_buffer, src->ie_buf, src->ie_length);

    *pos = (custom_ie *)((t_u8 *)(*pos) + len);
    *remain_len -= len;
    *total_len += len;

    return MLAN_STATUS_SUCCESS;
}

/**
 * @brief Download a list of mgmt buffer entries to FW.
 *
 * Serializes @p ies_list into one or more mlan_ds_misc_custom_ie TLV payloads
 * (batched at most MAX_MGMT_IE_INDEX_TO_FW entries per command).
 *
 * @param priv      Pointer to the mlan_private driver data struct
 * @param ies_list  Array of mgmt buffer entries to commit
 * @param ies_cnt   Number of entries in @p ies_list.
 *
 * @return          MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_commit(mlan_private *priv, custom_ie_hdr *ies_list, t_u8 ies_cnt)
{
    mlan_status status                 = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_custom_ie *pcustom_ie = MNULL;
    custom_ie *pos                     = MNULL;
    t_u16 len                          = 0;
    t_u32 remain_len                   = 0;
    HostCmd_DS_COMMAND *cmd            = MNULL;
    t_u8 batch_start = 0;
    t_u8 batch_size  = 0;
    t_u8 i;

    ENTER();

    if (!priv || !ies_list || ies_cnt == 0)
    {
        wifi_e("Invalid parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    pcustom_ie = wrapper_buffer_malloc(sizeof(mlan_ds_misc_custom_ie));
    if (!pcustom_ie)
    {
        wifi_e("Fail to allocate custome_ie\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    wifi_d("Total IEs to commit: %d, will download in batches of max %d",
            ies_cnt, MAX_MGMT_IE_INDEX_TO_FW);

    batch_start = 0;
    batch_size  = 0;

    /* Iterate over all IEs in chunks of at most MAX_MGMT_IE_INDEX_TO_FW
     * to stay within the firmware command buffer size limit. */
    while (batch_start < ies_cnt)
    {
        batch_size = MIN((ies_cnt - batch_start), MAX_MGMT_IE_INDEX_TO_FW);

        wifi_d("Batch: start_idx=%d, size=%d", batch_start, batch_size);

        /* Re-use the same buffer; reset all fields before building the payload */
        (void)memset(pcustom_ie, 0, sizeof(mlan_ds_misc_custom_ie));
        pcustom_ie->type = TLV_TYPE_MGMT_IE;
        pos        = pcustom_ie->ie_data_list;
        remain_len = sizeof(pcustom_ie->ie_data_list);
        len        = 0;

        for (i = 0; i < batch_size; i++)
        {
            /* Skip entries that carry no valid mask */
            if (ies_list[batch_start + i].mgmt_subtype_mask == MLAN_MGMT_IE_INVALID_MASK)
            {
                continue;
            }

            status = append_custom_ie(&pos, &remain_len, &len, &ies_list[batch_start + i]);
            if (status != MLAN_STATUS_SUCCESS)
            {
                wifi_e("Failed to append custom IE at num %d", batch_start + i);
                goto out;
            }
        }

        pcustom_ie->len = len;

        if (len == 0)
        {
            wifi_d("Batch has no valid IEs, skipping");
            batch_start += batch_size;
            continue;
        }

        wifi_d("Dumping custom IE batch to be committed to FW:");
        // dump_hex(pcustom_ie, pcustom_ie->len + 4);

        (void)wifi_get_command_lock();

        cmd = wifi_get_command_buffer();
        (void)memset(cmd, 0x00, sizeof(HostCmd_DS_COMMAND));

        cmd->seq_num = HostCmd_SET_SEQ_NO_BSS_INFO(0U /* seq_num */, 0U /* bss_num */, priv->bss_type);
        cmd->result  = 0x0;

    #if UAP_SUPPORT
        if (priv->bss_type == MLAN_BSS_TYPE_UAP
    #if CONFIG_WPA_SUPP_P2P
            || ((priv->bss_type == MLAN_BSS_TYPE_WIFIDIRECT) && (priv->bss_role == MLAN_BSS_ROLE_UAP))
    #endif
            )
        {
            wifi_d("[SET] Custom IE for UAP");
            status = wlan_ops_uap_prepare_cmd(priv, HOST_CMD_APCMD_SYS_CONFIGURE, HostCmd_ACT_GEN_SET, 0,
                                            MNULL, (void *)pcustom_ie, cmd);
        }
        else
    #endif
        {
            wifi_d("[SET] Custom IE for STA");
            status = wlan_ops_sta_prepare_cmd(priv, HostCmd_CMD_MGMT_IE_LIST, HostCmd_ACT_GEN_SET, 0,
                                            MNULL, (void *)pcustom_ie, cmd);
        }

        if (status != MLAN_STATUS_SUCCESS)
        {
            wifi_e("Failed to prepare cmd.");
            wm_wifi.cmd_resp_priv = NULL;
            (void)wifi_put_command_lock();
            goto out;
        }

        (void)wifi_wait_for_cmdresp(MNULL);
        if (wm_wifi.cmd_resp_status)
        {
            wifi_e("Failed to download custom ie to FW");
            status = MLAN_STATUS_FAILURE;
            goto out;
        }

        batch_start += batch_size;
    }

    wifi_d("All %d IEs downloaded successfully", ies_cnt);
    status = MLAN_STATUS_SUCCESS;

out:
    if (pcustom_ie != MNULL)
    {
        wrapper_buffer_free(pcustom_ie);
    }

    LEAVE();

    return status;
}

/**
 * @brief Collect all dirty mgmt buffers for @p priv and commit them to firmware.
 *
 * Scans the adapter's DRV IE table for entries belonging to @p priv whose
 * mgmt buffer is marked dirty.  Each unique dirty mgmt buffer is added
 * to a local list and passed to mgmt_ie_commit().
 *
 * @param priv  Pointer to the mlan_private driver data struct
 *
 * @return      MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_commit_dirty(mlan_private *priv)
{
    mlan_status status        = MLAN_STATUS_SUCCESS;
    mlan_adapter *pmadapter   = priv->adapter;
    custom_ie_entry *pmgmt_ie = pmadapter->mgmt_ie;
    custom_ie_hdr *pmgmt_buf  = MNULL;
    custom_ie_hdr ies_list[MAX_MGMT_IE_FW_INDEX] = {0};
    t_u16 fw_idx = MLAN_MGMT_IE_INVALID_IDX;
    t_u8 ies_cnt = 0;
    t_u8 i;
    /* bitmap to track which mgmt buffers are dirty */
    t_u32 mgmt_buf_dirty_bitmap = 0;
    /* bitmap to track which mgmt ies are marked for clearing */
    t_u32 mgmt_ie_clear_bitmap = 0;

    /* Pass 1: collect unique dirty FW buffers owned by this priv */
    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        /* Skip entries that don't belong to this interface or are empty */
        if (pmgmt_ie[i].bss_type != priv->bss_type ||
            pmgmt_ie[i].cust_ie == MNULL)
        {
            continue;
        }

        pmgmt_buf = pmgmt_ie[i].cust_ie;
        fw_idx = pmgmt_buf->ie_index;

        /* Skip clean buffers and buffers already captured in this pass */
        if (!pmgmt_buf->dirty || (mgmt_buf_dirty_bitmap & MBIT(fw_idx)))
        {
            continue;
        }

        ies_list[ies_cnt++] = *pmgmt_buf;
        mgmt_buf_dirty_bitmap |= MBIT(fw_idx);

        if (pmgmt_ie[i].cust_ie->mgmt_subtype_mask == MGMT_MASK_CLEAR)
        {
            /* Track this IE for clearing after commit */
            mgmt_ie_clear_bitmap |= MBIT(i);
        }
    }

    if (ies_cnt == 0)
    {
        return MLAN_STATUS_SUCCESS;
    }

    status = mgmt_ie_commit(priv, ies_list, ies_cnt);
    if (status != MLAN_STATUS_SUCCESS)
    {
        return status;
    }

    /* Pass 2: post-commit cleanup — clear dirty flags and free CLEAR-marked mgmt buffers */
    pmgmt_buf = pmadapter->mgmt_buffer;

    for (i = 0; i < pmadapter->max_mgmt_buf_count; i++)
    {
        if (!(mgmt_buf_dirty_bitmap & MBIT(i)))
        {
            continue;
        }

        pmgmt_buf[i].dirty = 0;
        /* If this buffer was a CLEAR command, release its IE data buffer and
         * mark the FW slot as free. */
        if (pmgmt_buf[i].mgmt_subtype_mask == MGMT_MASK_CLEAR)
        {
            mgmt_buffer_entry_clear(pmadapter, i);
        }
    }

    /* Pass 3: clear DRV IE entries marked for removal */
    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        if (!(mgmt_ie_clear_bitmap & MBIT(i)))
        {
            continue;
        }

        /* Clear the DRV IE entry */
        mgmt_ie_entry_clear(pmadapter, i);
    }

    return MLAN_STATUS_SUCCESS;
}

/**
 * @brief Get a mgmt buffer slot from firmware.
 *
 * @param priv   Pointer to the mlan_private driver data struct
 * @param buf    Buffer to receive the firmware response
 *               (must be at least sizeof(tlvbuf_custom_ie) + sizeof(custom_ie))
 * @param index  FW buffer index to query
 *
 * @return       MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_fetch(mlan_private *priv, void *buf, t_u16 index)
{
    mlan_status status                 = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_custom_ie *pcustom_ie = MNULL;
    custom_ie *pos                     = MNULL;
    HostCmd_DS_COMMAND *cmd            = MNULL;

    ENTER();

    pcustom_ie = wrapper_buffer_malloc(sizeof(mlan_ds_misc_custom_ie));
    if (!pcustom_ie)
    {
        wifi_e("Fail to allocate custome_ie\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    pcustom_ie->type = TLV_TYPE_MGMT_IE;

    pos = pcustom_ie->ie_data_list;
    pos->ie_index = index;
    pos->mgmt_subtype_mask = 0;
    pos->ie_length = 0;
    pcustom_ie->len = MLAN_CUSTOM_IE_HDR_SIZE;

    (void)wifi_get_command_lock();

    cmd = wifi_get_command_buffer();
    (void)memset(cmd, 0x00, sizeof(HostCmd_DS_COMMAND));

    cmd->seq_num = HostCmd_SET_SEQ_NO_BSS_INFO(0U /* seq_num */, 0U /* bss_num */, priv->bss_type);
    cmd->result  = 0x0;

#if UAP_SUPPORT
    if (priv->bss_type == MLAN_BSS_TYPE_UAP
#if CONFIG_WPA_SUPP_P2P
        || ((priv->bss_type == MLAN_BSS_TYPE_WIFIDIRECT) && (priv->bss_role == MLAN_BSS_ROLE_UAP))
#endif
        )
    {
        wifi_d("[GET] Custom IE for UAP");
        status = wlan_ops_uap_prepare_cmd(priv, HOST_CMD_APCMD_SYS_CONFIGURE, HostCmd_ACT_GEN_GET, 0,
                                          MNULL, (void *)pcustom_ie, cmd);
    }
    else
#endif
    {
        wifi_d("[GET] Custom IE for STA");
        status = wlan_ops_sta_prepare_cmd(priv, HostCmd_CMD_MGMT_IE_LIST, HostCmd_ACT_GEN_GET, 0,
                                          MNULL, (void *)pcustom_ie, cmd);
    }
    if (status != MLAN_STATUS_SUCCESS)
    {
        wifi_e("Failed to prepare cmd.");
        wm_wifi.cmd_resp_priv = NULL;
        (void)wifi_put_command_lock();
        goto out;
    }

    (void)wifi_wait_for_cmdresp(buf);
    if (wm_wifi.cmd_resp_status)
    {
        status = MLAN_STATUS_FAILURE;
    }

out:
    if (pcustom_ie != MNULL)
    {
        wrapper_buffer_free(pcustom_ie);
    }

    LEAVE();

    return status;
}

static inline t_u16 find_free_fw_idx(pmlan_adapter pmadapter)
{
    t_u16 i;

    for (i = 0; i < pmadapter->max_mgmt_buf_count; i++)
    {
        if (pmadapter->mgmt_buffer[i].mgmt_subtype_mask == MLAN_MGMT_IE_INVALID_MASK)
        {
            return i;
        }
    }

    wifi_e("No free FW index available");
    return MLAN_MGMT_IE_INVALID_IDX;
}

/**
 * @brief Allocate a DRV index and its associated mgmt buffer slot.
 *
 * @param priv    Pointer to the mlan_private driver data struct
 * @param ie_mask Management frame type mask
 * @param ie_len  Length of the IE data to be added
 * @param index   MLAN_MGMT_IE_INVALID_IDX for a new allocation,
 *                or an existing DRV index for an update
 *
 * @return        Allocated DRV index on success, MLAN_MGMT_IE_INVALID_IDX on failure
 */
static t_u16 mgmt_ie_get_index(mlan_private *priv, t_u16 ie_mask, t_u16 ie_len, t_u16 index)
{
    mlan_adapter *pmadapter     = MNULL;
    custom_ie_entry *pmgmt_ie   = MNULL;
    custom_ie_hdr *pmgmt_buffer = MNULL;
    t_u8 *new_buf               = MNULL;
    t_u8 i = 0;
    t_u16 drv_idx = MLAN_MGMT_IE_INVALID_IDX, fw_idx = MLAN_MGMT_IE_INVALID_IDX;

    ENTER();

    if (!priv || ie_mask == 0 || ie_len == 0)
    {
        wifi_e("Invalid input parameters");
        LEAVE();
        return MLAN_MGMT_IE_INVALID_IDX;
    }

    pmadapter    = priv->adapter;
    pmgmt_ie     = pmadapter->mgmt_ie;
    pmgmt_buffer = pmadapter->mgmt_buffer;

    /* Re-use existing DRV index if updating */
    drv_idx = index;

    /*
     * Single pass over the DRV table:
     *  - Records the first empty DRV slot (for new-allocation path).
     *  - Looks for an existing mgmt buffer owned by the same bss_type with a
     *    matching ie_mask so the new IE can be appended (IE-merging path).
     */
    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        if (!pmgmt_ie[i].cust_ie)
        {
            if (drv_idx == MLAN_MGMT_IE_INVALID_IDX)
            {
                drv_idx = i;
                mgmt_ie_entry_clear(pmadapter, drv_idx);
            }
            continue;
        }

        if (fw_idx == MLAN_MGMT_IE_INVALID_IDX)
        {
            /* Try to find a shareable mgmt buffer (same interface + same IE mask) */
            if (pmgmt_ie[i].bss_type == priv->bss_type &&
                pmgmt_ie[i].cust_ie->mgmt_subtype_mask == ie_mask)
            {
                /* Grow the existing buffer to append the additional IE. */
                new_buf = ie_buf_renew(pmgmt_ie[i].cust_ie->ie_buf,
                                        pmgmt_ie[i].cust_ie->ie_length,
                                        pmgmt_ie[i].cust_ie->ie_length + ie_len);
                if (new_buf == MNULL)
                {
                    /* Buffer could not be grown; try the next candidate */
                    continue;
                }
                pmgmt_ie[i].cust_ie->ie_buf = new_buf;
                fw_idx = pmgmt_ie[i].cust_ie->ie_index;
            }
        }

        if (fw_idx != MLAN_MGMT_IE_INVALID_IDX && drv_idx != MLAN_MGMT_IE_INVALID_IDX)
        {
            break;
        }
    }

    if (drv_idx == MLAN_MGMT_IE_INVALID_IDX)
    {
        wifi_e("No free DRV index available");
        LEAVE();
        return MLAN_MGMT_IE_INVALID_IDX;
    }

    /* No shareable buffer was found — allocate a new mgmt buffer */
    if (fw_idx == MLAN_MGMT_IE_INVALID_IDX)
    {
        fw_idx = find_free_fw_idx(pmadapter);
        if (fw_idx == MLAN_MGMT_IE_INVALID_IDX)
        {
            wifi_e("No free FW index available");
            LEAVE();
            return MLAN_MGMT_IE_INVALID_IDX;
        }
        mgmt_buffer_entry_clear(pmadapter, fw_idx);
    }

    /* Link the DRV entry to its mgmt buffer */
    pmgmt_buffer[fw_idx].ie_index = fw_idx;
    pmgmt_ie[drv_idx].cust_ie = &pmgmt_buffer[fw_idx];

    LEAVE();

    return drv_idx;
}

/**
 * @brief Add a new IE entry to the mgmt ie/mgmt buffer tables.
 *
 * @param priv     Pointer to the mlan_private driver data struct
 * @param ie_mask  Management frame type mask
 * @param ie_buf   IE data to append
 * @param ie_len   Length of @p ie_buf in bytes
 * @param index    IN/OUT: DRV index on success
 *
 * @return         MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_add(mlan_private *priv, t_u16 ie_mask, t_u8 *ie_buf, t_u16 ie_len, t_u16 *index)
{
    mlan_status status          = MLAN_STATUS_SUCCESS;
    mlan_adapter *pmadapter     = MNULL;
    custom_ie_entry *pmgmt_ie   = MNULL;
    custom_ie_hdr *pmgmt_buffer = MNULL;
    t_u16 drv_idx = MLAN_MGMT_IE_INVALID_IDX;

    ENTER();

    if (!priv || ie_mask == MLAN_MGMT_IE_INVALID_MASK || !ie_buf || ie_len == 0 || !index)
    {
        wifi_e("Invalid input parameters");
        status = MLAN_STATUS_FAILURE;
        goto out;
    }

    drv_idx = mgmt_ie_get_index(priv, ie_mask, ie_len, *index);
    if (drv_idx == MLAN_MGMT_IE_INVALID_IDX || drv_idx >= MAX_MGMT_IE_DRV_INDEX)
    {
        wifi_e("Invalid DRV index");
        status = MLAN_STATUS_FAILURE;
        goto out;
    }

    pmadapter    = priv->adapter;
    pmgmt_ie     = pmadapter->mgmt_ie;
    pmgmt_buffer = pmgmt_ie[drv_idx].cust_ie;

    wifi_d("drv_idx=%d, fw_idx=%d", drv_idx, pmgmt_buffer->ie_index);

    if (pmgmt_buffer->mgmt_subtype_mask == MLAN_MGMT_IE_INVALID_MASK)
    {
        pmgmt_buffer->ie_buf = ie_buf_get(ie_len);
        if (pmgmt_buffer->ie_buf == MNULL)
        {
            wifi_e("Failed to allocate memory for IE buffer");
            /* Roll back the DRV entry */
            mgmt_ie_entry_clear(pmadapter, drv_idx);
            status = MLAN_STATUS_FAILURE;
            goto out;
        }
        pmgmt_buffer->mgmt_subtype_mask = ie_mask;
    }

    pmgmt_ie[drv_idx].ie_offset  = pmgmt_buffer->ie_length;
    pmgmt_ie[drv_idx].bss_type   = priv->bss_type;
    pmgmt_ie[drv_idx].cur_ie_len = ie_len;

     /* Append the IE data */
    (void)memcpy(pmgmt_buffer->ie_buf + pmgmt_buffer->ie_length, ie_buf, ie_len);
    pmgmt_buffer->ie_length += ie_len;
    /* Mark dirty for deferred FW download */
    pmgmt_buffer->dirty = 1;

    *index = drv_idx;

out:
    LEAVE();

    return status;
}

/**
 * @brief Remove one IE from a (possibly shared) mgmt buffer.
 *
 * @param priv     Pointer to the mlan_private driver data struct
 * @param drv_idx  DRV index of the IE to remove
 * @param fw_idx   mgmt buffer index that contains the IE
 *
 * @return         MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_remove(mlan_private *priv, t_u16 drv_idx, t_u16 fw_idx)
{
    mlan_adapter *pmadapter     = MNULL;
    custom_ie_entry *pmgmt_ie   = MNULL;
    custom_ie_hdr *pmgmt_buffer = MNULL;
    t_u8 *new_buf               = MNULL;
    t_u8 i = 0;

    ENTER();

    if (!priv ||
        drv_idx >= MAX_MGMT_IE_DRV_INDEX ||
        fw_idx >= priv->adapter->max_mgmt_buf_count)
    {
        wifi_e("Invalid input parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    pmadapter    = priv->adapter;
    pmgmt_ie     = pmadapter->mgmt_ie;
    pmgmt_buffer = pmadapter->mgmt_buffer;

    (void)memmove(pmgmt_buffer[fw_idx].ie_buf + pmgmt_ie[drv_idx].ie_offset,
                    pmgmt_buffer[fw_idx].ie_buf + pmgmt_ie[drv_idx].ie_offset + pmgmt_ie[drv_idx].cur_ie_len,
                    pmgmt_buffer[fw_idx].ie_length - (pmgmt_ie[drv_idx].ie_offset + pmgmt_ie[drv_idx].cur_ie_len));

    pmgmt_buffer[fw_idx].ie_length -= pmgmt_ie[drv_idx].cur_ie_len;

    /*
     * Fixup ie_offset for all DRV entries that share fw_idx and
     * whose data starts after the removed IE — they have all shifted left
     * by cur_ie_len bytes.
     */
    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        if (pmgmt_ie[i].cust_ie && (i != drv_idx) &&
            pmgmt_ie[i].cust_ie->ie_index == fw_idx &&
            pmgmt_ie[i].ie_offset > pmgmt_ie[drv_idx].ie_offset)
        {
            pmgmt_ie[i].ie_offset -= pmgmt_ie[drv_idx].cur_ie_len;
        }
    }

    /* Mark dirty for deferred FW download */
    pmgmt_buffer[fw_idx].dirty = 1;

    /*
     * Opportunistically migrate the buffer to a smaller pool class now that
     * its content is shorter.
     */
    new_buf = ie_buf_renew(pmgmt_buffer[fw_idx].ie_buf,
                            pmgmt_buffer[fw_idx].ie_length,
                            pmgmt_buffer[fw_idx].ie_length);
    if (new_buf)
    {
        pmgmt_buffer[fw_idx].ie_buf = new_buf;
    }

    /* Release the DRV slot; the mgmt buffer still be shared by other entries */
    mgmt_ie_entry_clear(pmadapter, drv_idx);

    LEAVE();

    return MLAN_STATUS_SUCCESS;
}

/**
 * @brief Update an existing IE entry in-place or via remove-then-add.
 *
 * Two paths depending on whether the DRV entry exclusively owns its mgmt buffer:
 *
 *  Exclusive path (mgmt buffer ie_length == DRV entry cur_ie_len):
 *   - Calls ie_buf_renew() to resize the buffer if needed.
 *   - Overwrites the buffer content with the new IE data.
 *   - Updates ie_length and cur_ie_len, marks dirty.
 *
 *  Shared path (mgmt buffer holds IEs from multiple DRV entries):
 *   - Calls mgmt_ie_remove() to excise the old IE from the shared buffer.
 *   - Calls mgmt_ie_add() to insert the new IE (may land in the same or a
 *     different mgmt buffer depending on available space).
 *
 * @param priv     Pointer to the mlan_private driver data struct
 * @param ie_mask  Management frame type mask (used only in the shared path
 *                 when re-adding the IE)
 * @param ie_buf   New IE data
 * @param ie_len   Length of @p ie_buf in bytes
 * @param index    IN/OUT: DRV index of the IE to update
 *
 * @return         MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_update(mlan_private *priv, t_u16 ie_mask, t_u8 *ie_buf, t_u16 ie_len, t_u16 *index)
{
    mlan_status status           = MLAN_STATUS_SUCCESS;
    mlan_adapter *pmadapter      = MNULL;
    custom_ie_entry *pmgmt_ie    = MNULL;
    custom_ie_hdr *pmgmt_buffer  = MNULL;
    t_u16 drv_idx = MLAN_MGMT_IE_INVALID_IDX;
    t_u16 fw_idx  = MLAN_MGMT_IE_INVALID_IDX;
    t_u8 *new_buf = MNULL;

    ENTER();

    if (!priv || !ie_buf || !index || *index == MLAN_MGMT_IE_INVALID_IDX || *index >= MAX_MGMT_IE_DRV_INDEX)
    {
        wifi_e("Invalid parameters");
        status = MLAN_STATUS_FAILURE;
        goto out;
    }

    pmadapter    = priv->adapter;
    pmgmt_ie     = pmadapter->mgmt_ie;
    drv_idx      = *index;
    pmgmt_buffer = pmgmt_ie[drv_idx].cust_ie;
    fw_idx       = pmgmt_buffer->ie_index;

    /*
     * If the mgmt buffer's total length equals the amount owned by this DRV
     * entry, no other DRV entry is sharing the buffer — safe to overwrite.
     */
    if (pmgmt_buffer->ie_length == pmgmt_ie[drv_idx].cur_ie_len)
    {
        /* Resize the pool buffer if the new IE is larger or smaller */
        new_buf = ie_buf_renew(pmgmt_buffer->ie_buf, pmgmt_buffer->ie_length, ie_len);
        if (new_buf == MNULL)
        {
            wifi_e("Failed to renew memory for IE buffer");
            status = MLAN_STATUS_FAILURE;
            goto out;
        }
        pmgmt_buffer->ie_buf = new_buf;
        (void)memcpy(pmgmt_buffer->ie_buf, ie_buf, ie_len);
        pmgmt_buffer->ie_length      = ie_len;
        pmgmt_ie[drv_idx].cur_ie_len = ie_len;
        pmgmt_buffer->dirty = 1;
    }
    else
    {
        /*
         * Shared-buffer path: excise the old bytes then re-insert the new
         * IE.  mgmt_ie_add() will try to merge into the same FW buffer if
         * capacity allows, or allocate a new one otherwise.
         */
        status = mgmt_ie_remove(priv, drv_idx, fw_idx);
        if (status != MLAN_STATUS_SUCCESS)
        {
            wifi_e("Failed to remove management IE");
            goto out;
        }

        /*
         * Keep the DRV index the same to simplify the caller's tracking logic,
         * but mgmt_ie_add() may link it to a different mgmt buffer if the IE size has changed.
         */
        status = mgmt_ie_add(priv, ie_mask, ie_buf, ie_len, &drv_idx);
        if (status != MLAN_STATUS_SUCCESS)
        {
            wifi_e("Failed to add management IE");
            goto out;
        }
    }

out:
    LEAVE();

    return status;
}

/**
 * @brief Mark an mgmt IE entry for removal
 *
 * Two paths depending on whether the DRV entry exclusively owns its mgmt buffer:
 *
 *  Exclusive path (mgmt buffer ie_length == DRV entry cur_ie_len):
 *   - Sets mgmt_subtype_mask to MGMT_MASK_CLEAR and ie_length to 0.
 *   - Marks the mgmt buffer dirty; mgmt_ie_commit_dirty() will send the CLEAR
 *     command and then call mgmt_buffer_entry_clear() to free the IE buffer.
 *
 *  Shared path (mgmt buffer holds IEs from multiple DRV entries):
 *   - Delegates to mgmt_ie_remove() which excises the IE bytes, adjusts
 *     offsets of sibling DRV entries, and clears this DRV entry.
 *
 * @param priv   Pointer to the mlan_private driver data struct
 * @param index  IN/OUT: DRV index to clear
 *
 * @return       MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status mgmt_ie_clear(mlan_private *priv, t_u16 *index)
{
    mlan_status status          = MLAN_STATUS_SUCCESS;
    mlan_adapter *pmadapter     = MNULL;
    custom_ie_entry *pmgmt_ie   = MNULL;
    custom_ie_hdr *pmgmt_buffer = MNULL;
    t_u16 drv_idx = MLAN_MGMT_IE_INVALID_IDX;
    t_u16 fw_idx  = MLAN_MGMT_IE_INVALID_IDX;

    ENTER();

    if (!priv || !index || *index == MLAN_MGMT_IE_INVALID_IDX || *index >= MAX_MGMT_IE_DRV_INDEX)
    {
        wifi_e("Invalid parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    pmadapter    = priv->adapter;
    pmgmt_ie     = pmadapter->mgmt_ie;
    drv_idx      = *index;
    pmgmt_buffer = pmgmt_ie[drv_idx].cust_ie;
    fw_idx       = pmgmt_buffer->ie_index;

    /*
     * This DRV entry owns the entire FW buffer.
     * Mark it for clearing and let mgmt_ie_commit_dirty() handle the FW update and buffer cleanup.
     */
    if (pmgmt_buffer->ie_length == pmgmt_ie[drv_idx].cur_ie_len)
    {
        pmgmt_buffer->mgmt_subtype_mask = MGMT_MASK_CLEAR;
        pmgmt_buffer->ie_length         = 0;
        pmgmt_buffer->dirty             = 1;
    }
    else
    {
        /*
         * Shared-buffer path: excise the IE from the FW buffer and clear this DRV entry
         */
        status = mgmt_ie_remove(priv, drv_idx, fw_idx);
        if (status != MLAN_STATUS_SUCCESS)
        {
            wifi_e("Failed to remove management IE");
            LEAVE();
            return status;
        }
    }

    /* Invalidate the caller's index to prevent accidental reuse */
    *index = MLAN_MGMT_IE_INVALID_IDX;

    LEAVE();

    return MLAN_STATUS_SUCCESS;
}

/**
 * @brief Filter a raw beacon IE buffer, retaining only driver-managed IEs.
 *
 * Parses the TLV-encoded IE stream at @p ie (length @p len) and copies
 * selected IEs into @p ie_out.
 *
 * @param priv        Pointer to the mlan_private driver data struct
 * @param ie          Input IE buffer
 * @param len         Length of @p ie in bytes
 * @param ie_out      Output buffer for filtered IEs
 * @param ie_out_len  Size of @p ie_out in bytes
 * @param wps_flag    Bitmask of IE_MASK_* flags controlling which vendor IEs
 *                    are filtered out
 *
 * @return            Number of bytes written to @p ie_out.
 */
static t_u16 mgmt_ie_filter_beacon(mlan_private *priv,
                                    const t_u8 *ie,
                                    int len,
                                    t_u8 *ie_out,
                                    t_u32 ie_out_len,
                                    t_u16 wps_flag)
{
    int left_len    = len;
    const t_u8 *pos = ie;
    int length;
    t_u8 id                                = 0;
    t_u16 out_len                          = 0;
    IEEEtypes_VendorSpecific_t *pvendor_ie = NULL;
    const t_u8 wps_oui[4]                  = {0x00, 0x50, 0xf2, 0x04};
    const t_u8 p2p_oui[4]                  = {0x50, 0x6f, 0x9a, 0x09};
    const t_u8 wfd_oui[4]                  = {0x50, 0x6f, 0x9a, 0x0a};
    const t_u8 wmm_oui[4]                  = {0x00, 0x50, 0xf2, 0x02};
    t_u8 find_p2p_ie                       = MFALSE;
#define WLAN_EID_ERP_INFO 42

    /* ERP_INFO/EXTENDED_SUPPORT_RATES/HT_CAPABILITY/HT_OPERATION/WMM
     * and WPS/P2P/WFD IE will be fileter out
     */
    while (left_len >= 2)
    {
        length = *(pos + 1);
        id     = *pos;
        if ((length + 2) > left_len)
            break;

        switch (id)
        {
            case COUNTRY_INFO:
                if ((out_len + length + 2) < (int)ie_out_len)
                {
                    (void)memcpy(ie_out + out_len, pos, length + 2);
                    out_len += (t_u16)(length + 2);
                }
                else
                {
                    wifi_d("IE too big, fail copy COUNTRY INFO IE");
                }
                break;
            case HT_CAPABILITY:
            case HT_OPERATION:
#if CONFIG_11AC
            case VHT_CAPABILITY:
            case VHT_OPERATION:
#endif
#if UAP_HOST_MLME
                if ((out_len + length + 2) < (int)ie_out_len)
                {
                    (void)memcpy(ie_out + out_len, pos, length + 2);
                    out_len += length + 2;
                }
                else
                {
                    wifi_d("IE too big, fail copy COUNTRY INFO IE");
                }
#endif
                break;
            case EXTENDED_SUPPORTED_RATES:
            case WLAN_EID_ERP_INFO:
                /* Fall Through */
            case REGULATORY_CLASS:
                /* Fall Through */
            case OVERLAPBSSSCANPARAM:
                break;
#if CONFIG_11AX
            case EXTENSION:
#if UAP_SUPPORT
#if CONFIG_11AX
                if ((*(pos + 2) == HE_CAPABILITY || *(pos + 2) == HE_OPERATION) && !IS_FW_SUPPORT_11AX(mlan_adap))
                {
                    /* Ignore HE-cap and HE-op if FW doesn't support HE */
                    break;
                }

                if (*(pos + 2) == HE_CAPABILITY)
                {
                    mlan_ds_11ax_he_cfg he_cfg;
                    IEEEtypes_HECap_t *hecap_ie = NULL;
                    (void)memset((void *)&he_cfg, 0, sizeof(mlan_ds_11ax_he_cfg));

                    if (priv->uap_channel <= 14)
                        he_cfg.band = MBIT(0);
                    else
                        he_cfg.band = MBIT(1);

                    wifi_d("Retrieve 11ax cfg by channel=%d band=%d", priv->uap_channel, he_cfg.band);

                    if (0 == wlan_cmd_11ax_cfg(priv, HostCmd_ACT_GEN_GET, &he_cfg))
                    {
                        t_u16 he_cap_len;
                        hecap_ie                      = (IEEEtypes_HECap_t *)&he_cfg.he_cap.len;
                        he_cap_len                    = he_cfg.he_cap.len;
                        hecap_ie->ieee_hdr.len        = he_cap_len;
                        hecap_ie->ieee_hdr.element_id = (IEEEtypes_ElementId_e)he_cfg.he_cap.id;

                        (void)memcpy(ie_out + out_len, hecap_ie, hecap_ie->ieee_hdr.len + 2);

                        out_len += hecap_ie->ieee_hdr.len + 2;
                    }
                    else
                    {
                        wifi_d("Fail to get 11ax he_cap parameters");
                    }
                }
                else
#endif
#endif
                {
                    if ((out_len + length + 2) < (int)ie_out_len)
                    {
                        (void)memcpy(ie_out + out_len, pos, length + 2);
                        out_len += length + 2;
                    }
                    else
                    {
                        wifi_d("IE too big, fail copy EXTENSION IE");
                    }
                }
                break;
#endif
            case EXT_CAPABILITY:
                /* filter out EXTCAP */
                if (wps_flag & IE_MASK_EXTCAP)
                {
                    break;
                }
                if ((out_len + length + 2) < (int)ie_out_len)
                {
                    (void)memcpy(ie_out + out_len, pos, length + 2);
                    out_len += length + 2;
                }
                else
                {
                    wifi_d("IE too big, fail copy EXTCAP IE");
                }
                break;
            case VENDOR_SPECIFIC_221:
                /* filter out wmm ie */
                pvendor_ie = (IEEEtypes_VendorSpecific_t *)pos;
                if (!memcmp(pvendor_ie->vend_hdr.oui, wmm_oui, sizeof(pvendor_ie->vend_hdr.oui)) &&
                    pvendor_ie->vend_hdr.oui_type == wmm_oui[3])
                {
                    break;
                }
                /* filter out wps ie */
                else if (!memcmp(pvendor_ie->vend_hdr.oui, wps_oui, sizeof(pvendor_ie->vend_hdr.oui)) &&
                        pvendor_ie->vend_hdr.oui_type == wps_oui[3])
                {
                    if (wps_flag & IE_MASK_WPS)
                        break;
                }
                /* filter out first p2p ie */
                else if (!memcmp(pvendor_ie->vend_hdr.oui, p2p_oui, sizeof(pvendor_ie->vend_hdr.oui)) &&
                        pvendor_ie->vend_hdr.oui_type == p2p_oui[3])
                {
                    if (!find_p2p_ie && (wps_flag & IE_MASK_P2P))
                    {
                        find_p2p_ie = MTRUE;
                        break;
                    }
                }
                /* filter out wfd ie */
                else if (!memcmp(pvendor_ie->vend_hdr.oui, wfd_oui, sizeof(pvendor_ie->vend_hdr.oui)) &&
                        pvendor_ie->vend_hdr.oui_type == wfd_oui[3])
                {
                    if (wps_flag & IE_MASK_WFD)
                        break;
                }
                else if (wps_flag & IE_MASK_VENDOR)
                {
                    // filter out vendor IE
                    break;
                }
                if ((out_len + length + 2) < (int)ie_out_len)
                {
                    (void)memcpy(ie_out + out_len, pos, length + 2);
                    out_len += length + 2;
                }
                else
                {
                    wifi_d("IE too big, fail copy VENDOR_SPECIFIC_221 IE");
                }
                break;
            default:
                if ((out_len + length + 2) < (int)ie_out_len)
                {
                    (void)memcpy(ie_out + out_len, pos, length + 2);
                    out_len += length + 2;
                }
                else
                {
                    wifi_d("IE too big, fail copy %d IE", id);
                }
                break;
        }

        pos += (length + 2);
        left_len -= (length + 2);
    }

    return out_len;
}

/********************************************************
                Global Functions
********************************************************/

void wlan_init_mgmt_ie_param(pmlan_adapter pmadapter)
{
    t_u8 i = 0;

    ENTER();

    pmadapter->max_mgmt_buf_count = 0;
    pmadapter->mgmt_ie_cnt_sm = 0;
    pmadapter->mgmt_ie_cnt_md = 0;
    pmadapter->mgmt_ie_cnt_lg = 0;

    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        mgmt_ie_entry_clear(pmadapter, i);
    }

    for (i = 0; i < MAX_MGMT_IE_FW_INDEX; i++)
    {
        mgmt_buffer_entry_clear(pmadapter, i);
    }

    LEAVE();
}

mlan_status wifi_mgmt_ie_init(void)
{
    ENTER();

    if (s_mgmt_ie_initialized == MTRUE)
    {
        return MLAN_STATUS_SUCCESS;
    }

    s_mgmt_buf_cfgs[0].buf_cnt = MLAN_MGMT_BUF_SM_CNT; // mlan_adap->mgmt_ie_cnt_sm;
    s_mgmt_buf_cfgs[1].buf_cnt = MLAN_MGMT_BUF_MD_CNT; // mlan_adap->mgmt_ie_cnt_md;
    s_mgmt_buf_cfgs[2].buf_cnt = MLAN_MGMT_BUF_LG_CNT; // mlan_adap->mgmt_ie_cnt_lg;

    if (util_buf_pool_init(&s_mgmt_buf_handle, s_mlan_buf_class, s_mgmt_buf_cfgs,
                        MGMT_BUFPOOL_NUM, wrapper_buffer_malloc, wrapper_buffer_free) != 0)
    {
        wifi_e("Failed to init mgmt buffer pool");
        return MLAN_STATUS_FAILURE;
    }

    if (OSA_MutexCreate((osa_mutex_handle_t)s_ie_mutex) != KOSA_StatusSuccess)
    {
        wifi_e("Failed to create IE mutex");
        util_buf_pool_deinit(&s_mgmt_buf_handle);
        return MLAN_STATUS_FAILURE;
    }

    s_mgmt_ie_initialized = MTRUE;

    LEAVE();

    return MLAN_STATUS_SUCCESS;
}

void wifi_mgmt_ie_deinit(void)
{
    ENTER();

    if (s_mgmt_ie_initialized == MTRUE)
    {
        util_buf_pool_deinit(&s_mgmt_buf_handle);

        if (OSA_MutexDestroy((osa_mutex_handle_t)s_ie_mutex) != KOSA_StatusSuccess)
        {
            wifi_e("Failed to destroy IE mutex");
            return;
        }

        s_mgmt_ie_initialized = MFALSE;
    }

    LEAVE();
}

/**
 * @brief Set (add or update) a mgmt IE
 *
 * Dispatch logic based on *@p index:
 *  - MLAN_MGMT_IE_INVALID_IDX  →  mgmt_ie_add()    (new IE)
 *  - valid DRV index           →  mgmt_ie_update() (replace existing IE)
 *
 * @param priv     Pointer to the mlan_private driver data struct
 * @param ie_mask  Management frame type mask
 * @param ie_buf   IE data buffer
 * @param ie_len   Length of @p ie_buf in bytes
 * @param index    IN/OUT: MLAN_MGMT_IE_INVALID_IDX for adding a new IE,
 *                 or a valid DRV index for updating an existing IE
 *
 * @return         MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wifi_mgmt_ie_set(mlan_private *priv, t_u16 ie_mask, t_u8 *ie_buf, t_u16 ie_len, t_u16 *index)
{
    mlan_status status = MLAN_STATUS_FAILURE;

    ENTER();

    if (!priv || ie_mask == MLAN_MGMT_IE_INVALID_MASK || !ie_buf || ie_len == 0 || !index)
    {
        wifi_e("Invalid parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    wrapper_mgmt_ie_lock();

    if (*index == MLAN_MGMT_IE_INVALID_IDX)
    {
        status = mgmt_ie_add(priv, ie_mask, ie_buf, ie_len, index);
    }
    else
    {
        status = mgmt_ie_update(priv, ie_mask, ie_buf, ie_len, index);
    }

    if (status == MLAN_STATUS_SUCCESS)
    {
        status = mgmt_ie_commit_dirty(priv);
    }

    wrapper_mgmt_ie_unlock();

    LEAVE();
    return status;
}

/**
 * @brief Apply multiple IE set/clear operations atomically in a single batch.
 *
 * Iterates @p reqs[0..req_cnt-1] and for each entry:
 *  - MGMT_IE_BATCH_SET:   calls mgmt_ie_add() or mgmt_ie_update() depending
 *                         on whether *reqs[i].index is MLAN_MGMT_IE_INVALID_IDX.
 *  - MGMT_IE_BATCH_CLEAR: calls mgmt_ie_clear().
 *
 * @param priv     Pointer to the mlan_private driver data struct
 * @param reqs     Array of batch request descriptors
 * @param req_cnt  Number of entries in @p reqs
 *
 * @return         MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wifi_mgmt_ie_set_batch(mlan_private *priv, mgmt_ie_batch_req *reqs, t_u8 req_cnt)
{
    mlan_status status = MLAN_STATUS_SUCCESS;
    t_u8 i = 0;

    ENTER();

    if (!priv || !reqs || req_cnt == 0)
    {
        wifi_e("Invalid parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    wrapper_mgmt_ie_lock();

    for (i = 0; i < req_cnt; i++)
    {
        if (reqs[i].op == MGMT_IE_BATCH_SET)
        {
            if (*reqs[i].index == MLAN_MGMT_IE_INVALID_IDX)
            {
                status = mgmt_ie_add(priv, reqs[i].ie_mask, reqs[i].ie_buf,
                                        reqs[i].ie_len, reqs[i].index);
            }
            else
            {
                status = mgmt_ie_update(priv, reqs[i].ie_mask, (t_u8 *)reqs[i].ie_buf,
                                        reqs[i].ie_len, reqs[i].index);
            }
        }
        else /* MGMT_IE_BATCH_CLEAR */
        {
            status = mgmt_ie_clear(priv, reqs[i].index);
        }

        if (status != MLAN_STATUS_SUCCESS)
        {
            wifi_e("Failed to process request for index %d", i);
            goto out;
        }
    }

    status = mgmt_ie_commit_dirty(priv);
    if (status != MLAN_STATUS_SUCCESS)
    {
        wifi_e("Failed to commit management IE changes");
        goto out;
    }

out:
    wrapper_mgmt_ie_unlock();

    LEAVE();
    return status;
}

/**
 * @brief Clear a mgmt IE entry
 *
 * On success *@p index is set to MLAN_MGMT_IE_INVALID_IDX.
 *
 * @param priv   Pointer to the mlan_private driver data struct
 * @param index  IN/OUT: DRV index of the IE to clear
 *
 * @return       MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wifi_mgmt_ie_clear(mlan_private *priv, t_u16 *index)
{
    mlan_status status = MLAN_STATUS_SUCCESS;

    ENTER();

    if (!priv || !index || *index == MLAN_MGMT_IE_INVALID_IDX || *index >= MAX_MGMT_IE_DRV_INDEX)
    {
        wifi_e("Invalid parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    wrapper_mgmt_ie_lock();

    status = mgmt_ie_clear(priv, index);
    if (status == MLAN_STATUS_SUCCESS)
    {
        status = mgmt_ie_commit_dirty(priv);
    }

    wrapper_mgmt_ie_unlock();

    LEAVE();
    return status;
}

/**
 * @brief Replace a specific IE element within the stored MGMT IEs of an interface.
 *
 * Scans all DRV IE entries belonging to @p priv's bss_type.  For each entry,
 * parses the IE byte stream looking for an element whose element_id matches
 * @p ie_id.  For VENDOR_SPECIFIC_221 (0xDD), additionally checks that the OUI
 * and OUI type match @p oui[0..3].
 *
 * On match, one of three replacement strategies is applied:
 *
 *  1. COUNTRY_INFO (special path):
 *     - Fetches the current FW buffer content from firmware via mgmt_ie_fetch().
 *     - Filters it through mgmt_ie_filter_beacon() to strip WPS/P2P/WFD/vendor IEs.
 *     - Rebuilds the IE stream, substituting the new COUNTRY_INFO element.
 *     - Calls mgmt_ie_update() with the reconstructed buffer.
 *
 *  2. Same-length replacement (cur_ie_len == ie_len):
 *     - Overwrites the IE bytes in-place with memcpy().
 *     - Marks the FW buffer dirty.
 *
 *  3. Different-length replacement:
 *     - Reconstructs the DRV entry's IE stream in a temporary buffer
 *       (prefix + new IE + suffix).
 *     - Calls mgmt_ie_update() with the reconstructed buffer.
 *
 * After processing all matching entries, calls mgmt_ie_commit_dirty() to
 * download all dirty FW buffers to firmware.
 *
 * @param priv    Pointer to the mlan_private driver data struct
 * @param ie_buf  New IE data
 * @param ie_len  Length of @p ie_buf in bytes
 * @param ie_id   IEEE 802.11 element ID of the IE to replace
 * @param oui     4-byte OUI+type array for VENDOR_SPECIFIC_221 matching;
 *                ignored (may be NULL) for non-vendor IEs
 *
 * @return        MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wifi_mgmt_ie_replace_elem(mlan_private *priv, t_u8 *ie_buf, t_u16 ie_len, IEEEtypes_ElementId_e ie_id, t_u8 *oui)
{
    mlan_status status          = MLAN_STATUS_SUCCESS;
    mlan_adapter *pmadapter     = MNULL;
    custom_ie_entry *pmgmt_ie   = MNULL;
    custom_ie_hdr *pmgmt_buffer = MNULL;
    t_u16 drv_idx    = MLAN_MGMT_IE_INVALID_IDX;
    t_u16 cur_fw_idx = MLAN_MGMT_IE_INVALID_IDX;
    t_u8 *cur_mgmt_ie_buf = MNULL;
    t_u16 cur_mgmt_ie_len = 0;
    t_u8 *tmp_ie_buf    = MNULL;
    t_u16 tmp_ie_len    = 0;
    t_u16 tmp_ie_offset = 0;
    IEEEtypes_Header_t *cur_ie              = MNULL;
    IEEEtypes_VendorHeader_t *cur_vendor_ie = MNULL;
    t_u16 cur_ie_len = 0;
    t_u8 i = 0;

    ENTER();

    if (!priv || !ie_buf || ie_len == 0)
    {
        wifi_e("Invalid parameters");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    wrapper_mgmt_ie_lock();

    tmp_ie_buf = wrapper_buffer_malloc(sizeof(tlvbuf_custom_ie) + sizeof(custom_ie));
    if (!tmp_ie_buf)
    {
        wifi_e("Failed to allocate memory for IE buffer");
        status = MLAN_STATUS_FAILURE;
        goto out;
    }

    pmadapter = priv->adapter;
    pmgmt_ie  = pmadapter->mgmt_ie;

    /* Scan every DRV IE entry that belongs to this interface */
    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        if ((pmgmt_ie[i].bss_type == priv->bss_type) &&
            (pmgmt_ie[i].cust_ie != MNULL))
        {
            t_u8 match_found = 0;
            pmgmt_buffer    = pmgmt_ie[i].cust_ie;
            cur_fw_idx      = pmgmt_buffer->ie_index;
            /* Narrow the search to the byte range owned by this DRV entry */
            cur_mgmt_ie_buf = pmgmt_buffer->ie_buf + pmgmt_ie[i].ie_offset;
            cur_mgmt_ie_len = pmgmt_ie[i].cur_ie_len;

            tmp_ie_offset = 0;

             /* Walk the sub-IE TLV stream within this DRV entry's range */
            while (tmp_ie_offset < cur_mgmt_ie_len)
            {
                cur_ie = (IEEEtypes_Header_t *)(cur_mgmt_ie_buf + tmp_ie_offset);
                cur_ie_len = cur_ie->len + 2U;

                if (cur_ie->element_id == ie_id)
                {
                    wifi_d("Found matching IE [%d] at offset %d", i, tmp_ie_offset);
                    if (ie_id == VENDOR_SPECIFIC_221)
                    {
                        /* For vendor IEs, also verify OUI and OUI type */
                        cur_vendor_ie = (IEEEtypes_VendorHeader_t *)cur_ie;
                        if (!memcmp(cur_vendor_ie->oui, oui, 3) &&
                            (cur_vendor_ie->oui_type == oui[3]))
                        {
                            match_found = 1;
                        }
                    }
                    else
                    {
                        match_found = 1;
                    }

                    if (match_found)
                    {
                        wifi_d("Matched IE found, replacing IE");
                        drv_idx = i;
                        //TODO: ECSA improvement
                        if (cur_ie->element_id == COUNTRY_INFO)
                        {
                            wifi_d("Update COUNTRY_INFO IE");
                            /*
                             * Fetch the current FW buffer so we can rebuild the
                             * entire beacon IE stream with the new COUNTRY_INFO
                             * element substituted in place.
                             */
                            status = mgmt_ie_fetch(priv, tmp_ie_buf, cur_fw_idx);
                            if (status != MLAN_STATUS_SUCCESS)
                            {
                                wifi_e("Failed to get custom ie, index = %d", cur_fw_idx);
                                goto out;
                            }

                            tmp_ie_len = ((tlvbuf_custom_ie *)tmp_ie_buf)->length + sizeof(tlvbuf_custom_ie);
                            if ((tmp_ie_len < (sizeof(tlvbuf_custom_ie) + MLAN_CUSTOM_IE_HDR_SIZE)) ||
                                tmp_ie_len > sizeof(tlvbuf_custom_ie) + sizeof(custom_ie))
                            {
                                wifi_e("%s: get_mgmt_ie index=%d invalid len=%d", __FUNCTION__, cur_fw_idx, tmp_ie_len);
                                goto out;
                            }
                            else
                            {
                                wifi_d("Custom IE data from FW:");
                                // dump_hex(tmp_ie_buf, tmp_ie_len);

                                custom_ie *cu_ie = (custom_ie *)(tmp_ie_buf + sizeof(tlvbuf_custom_ie));
                                t_u8 *cu_ie_buf = (t_u8 *)cu_ie + MLAN_CUSTOM_IE_HDR_SIZE;

                                t_u8 beacon_ie_buf[MAX_IE_SIZE] = {0};
                                t_u16 beacon_ie_len             = 0;
                                t_u8 new_ie_buf[MAX_IE_SIZE]    = {0};
                                t_u16 new_ie_len                = 0;
                                t_u8 *new_ie_ptr                = new_ie_buf;
                                bool country_ie_in_beacon       = false;

                                beacon_ie_len = mgmt_ie_filter_beacon(priv, cu_ie_buf, cu_ie->ie_length, beacon_ie_buf, MAX_IE_SIZE,
                                                                    IE_MASK_WPS | IE_MASK_WFD | IE_MASK_P2P | IE_MASK_VENDOR);
                                t_u8 *ptr  = beacon_ie_buf;
                                t_u16 left = beacon_ie_len;
                                /*
                                 * Rebuild the IE stream: copy every element
                                 * unchanged except COUNTRY_INFO, which is
                                 * replaced with the new ie_buf.
                                 */
                                while (left >= sizeof(IEEEtypes_Header_t))
                                {
                                    IEEEtypes_Header_t *cu_ieee_hdr = (IEEEtypes_Header_t *)ptr;
                                    if (cu_ieee_hdr->element_id != COUNTRY_INFO)
                                    {
                                        (void)memcpy(new_ie_ptr, (t_u8 *)cu_ieee_hdr, cu_ieee_hdr->len + 2U);
                                        new_ie_ptr += (cu_ieee_hdr->len + 2U);
                                        new_ie_len += (cu_ieee_hdr->len + 2U);
                                    }
                                    else
                                    {
                                        country_ie_in_beacon = true;
                                        (void)memcpy(new_ie_ptr, ie_buf, ie_len);
                                        new_ie_ptr += ie_len;
                                        new_ie_len += ie_len;
                                    }
                                    left -= (cu_ieee_hdr->len + 2U);
                                    ptr += cu_ieee_hdr->len + 2U;
                                }
                                /*
                                 * If COUNTRY_INFO was not present in the
                                 * beacon, append it at the end.
                                 */
                                if (!country_ie_in_beacon)
                                {
                                    (void)memcpy(new_ie_ptr, ie_buf, ie_len);
                                    new_ie_ptr += ie_len;
                                    new_ie_len += ie_len;
                                }
                                status = mgmt_ie_update(priv, pmgmt_buffer->mgmt_subtype_mask, new_ie_buf, new_ie_len, &drv_idx);
                                if (status != MLAN_STATUS_SUCCESS)
                                {
                                    wifi_e("Failed to update COUNTRY_INFO IE");
                                    goto out;
                                }
                            }
                        }
                        else if (cur_ie_len == ie_len)
                        {
                            wifi_d("IE length matches, replacing in-place");
                            /*
                             * Direct overwrite is safe because the buffer
                             * capacity and the mgmt buffer layout are unchanged.
                             */
                            (void)memcpy(cur_ie, ie_buf, ie_len);
                            pmgmt_buffer->dirty = 1;
                        }
                        else
                        {
                            wifi_d("IE length differs, reconstructing IE buffer");
                            t_u16 new_len = pmgmt_ie[i].cur_ie_len - cur_ie_len + ie_len;
                            t_u8 *dst = tmp_ie_buf;
                            t_u8 *src = pmgmt_buffer->ie_buf + pmgmt_ie[i].ie_offset;
                            /** copy prefix */
                            (void)memcpy(dst, src, tmp_ie_offset);
                            dst += tmp_ie_offset;
                            /** insert new IE */
                            (void)memcpy(dst, ie_buf, ie_len);
                            dst += ie_len;
                            /** copy suffix */
                            (void)memcpy(dst,
                                         src + tmp_ie_offset + cur_ie_len,
                                         pmgmt_ie[i].cur_ie_len - (tmp_ie_offset + cur_ie_len));
                            status = mgmt_ie_update(priv, pmgmt_buffer->mgmt_subtype_mask, tmp_ie_buf, new_len, &drv_idx);
                            if (status != MLAN_STATUS_SUCCESS)
                            {
                                wifi_e("Failed to update management IE");
                                status = MLAN_STATUS_FAILURE;
                                goto out;
                            }
                        }
                        break;
                    }
                }
                tmp_ie_offset += cur_ie_len;
            }
        }
    }

    /* Flush all dirty mgmt buffers accumulated during the replace operations */
    status = mgmt_ie_commit_dirty(priv);
    if (status != MLAN_STATUS_SUCCESS)
    {
        wifi_e("Failed to commit management IE changes");
        goto out;
    }

out:
    if (tmp_ie_buf != MNULL)
    {
        wrapper_buffer_free(tmp_ie_buf);
    }

    wrapper_mgmt_ie_unlock();

    LEAVE();

    return status;
}

/**
 * @brief Populate a single mgmt_ie_batch_req entry for use with wifi_mgmt_ie_set_batch().
 *
 * Convenience helper that encodes the SET-or-CLEAR decision into a batch
 * request struct.
 *
 * @param req      Output batch request entry to fill
 * @param ie_mask  Management frame type mask
 * @param ie_buf   IE data pointer
 * @param ie_len   IE data length
 * @param index    IN/OUT pointer to the DRV index
 *
 * @return         MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wifi_mgmt_ie_req_fill(mgmt_ie_batch_req *req, t_u16 ie_mask, t_u8 *ie_buf, t_u16 ie_len, t_u16 *index)
{
    if (!req || !index)
    {
        return MLAN_STATUS_FAILURE;
    }

    if (*index != MLAN_MGMT_IE_INVALID_IDX && !ie_len)
    {
        /*
         * The IE was previously installed (valid index) and the caller
         * supplies no data (len == 0), interpret as a CLEAR request.
         */
        req->op      = MGMT_IE_BATCH_CLEAR;
        req->index   = index;
        req->ie_mask = MGMT_MASK_CLEAR;
        req->ie_buf  = MNULL;
        req->ie_len  = 0;
        return MLAN_STATUS_SUCCESS;
    }
    else if (ie_len)
    {
        /*
         * Non-zero data length, SET (add or update).
         * *index == MLAN_MGMT_IE_INVALID_IDX triggers mgmt_ie_add(),
         * a valid *index triggers mgmt_ie_update().
         */
        req->op      = MGMT_IE_BATCH_SET;
        req->index   = index;
        req->ie_mask = ie_mask;
        req->ie_buf  = ie_buf;
        req->ie_len  = ie_len;
        return MLAN_STATUS_SUCCESS;
    }

    /*
     * *index is INVALID and ie_len == 0: nothing to do.
     * The caller should check the return value and skip this entry.
     */
    return MLAN_STATUS_FAILURE;
}

/* -----------------------------------------------------------------------
 * Debug helpers
 * ----------------------------------------------------------------------- */

static void ie_dump_hex(const char *title, const t_u8 *buf, t_u16 len)
{
    t_u16 i;

    if (!buf || !len)
    {
        return;
    }

    (void)PRINTF("%s (len=%u):\n", title, len);

    for (i = 0; i < len; i++)
    {
        if (i % 16 == 0)
        {
            (void)PRINTF("%04x: ", i);
        }

        (void)PRINTF("%02x ", buf[i]);

        if ((i % 16 == 15) || (i == len - 1))
        {
            (void)PRINTF("\n");
        }
    }
}

static void ie_dump_mgmt_buffer(pmlan_adapter pmadapter)
{
    t_u16 i;

    (void)PRINTF("=========== MGMT BUFFER DUMP ===========\n");

    for (i = 0; i < pmadapter->max_mgmt_buf_count; i++)
    {
        custom_ie_hdr *buf = &pmadapter->mgmt_buffer[i];

        if (buf->mgmt_subtype_mask == MLAN_MGMT_IE_INVALID_MASK)
            continue;

        (void)PRINTF("FW_IDX=%u\n", i);
        (void)PRINTF("  mask       = 0x%04x\n", buf->mgmt_subtype_mask);
        (void)PRINTF("  ie_length  = %u\n", buf->ie_length);
        (void)PRINTF("  ie_buf     = %p\n", buf->ie_buf);

        if (buf->ie_buf && buf->ie_length > 0)
        {
            ie_dump_hex("  IE DATA", buf->ie_buf, buf->ie_length);
        }
    }
}

static void ie_dump_mgmt_ie(pmlan_adapter pmadapter)
{
    t_u16 i;

    (void)PRINTF("\n=========== MGMT IE (DRV) DUMP ===========\n");

    (void)PRINTF("--------------------------------------------------------------------------------\n");
    (void)PRINTF("| %-7s | %-7s | %-10s | %-10s | %-8s | %-8s |\n",
           "DRV_IDX", "FW_IDX", "MASK", "BSS_TYPE", "OFFSET", "LEN");
    (void)PRINTF("--------------------------------------------------------------------------------\n");

    for (i = 0; i < MAX_MGMT_IE_DRV_INDEX; i++)
    {
        custom_ie_entry *ie = &pmadapter->mgmt_ie[i];

        if (!ie->cust_ie)
        {
            continue;
        }

        (void)PRINTF("| %-7u | %-7u | 0x%08x | %-10u | %-8u | %-8u |\n",
               i,
               ie->cust_ie->ie_index,
               ie->cust_ie->mgmt_subtype_mask,
               ie->bss_type,
               ie->ie_offset,
               ie->cur_ie_len);
    }

    (void)PRINTF("--------------------------------------------------------------------------------\n\n");
}

static void ie_dump_buf_pool(pmlan_buf_handle handle)
{
    t_u32 i;
    pmlan_buf_class cls;
    pmlan_buf_block blk;
    t_u32 free_cnt;

    (void)PRINTF("=========== BUF POOL DUMP ===========\n");

    if (!handle)
        return;

    (void)PRINTF("mem_base=%p size=%u\n", handle->mem_base, handle->mem_size);

    for (i = 0; i < handle->class_num; i++)
    {
        cls = &handle->classes[i];
        free_cnt = 0;

        blk = cls->free_list;
        while (blk)
        {
            free_cnt++;
            blk = blk->next;
        }

        (void)PRINTF("CLASS[%u]\n", i);
        (void)PRINTF("  buf_size   = %u\n", cls->buf_size);
        (void)PRINTF("  total      = %u\n", cls->total);
        (void)PRINTF("  free       = %u\n", free_cnt);
        (void)PRINTF("  used       = %u\n", cls->total - free_cnt);
    }
}

static void ie_dump_map(pmlan_adapter pmadapter)
{
    t_u16 fw, drv;
    t_u8 has_ref;

    (void)PRINTF("=========== MGMT IE MAP (VISUAL) ===========\n\n");

    for (fw = 0; fw < pmadapter->max_mgmt_buf_count; fw++)
    {
        custom_ie_hdr *buf = &pmadapter->mgmt_buffer[fw];

        if (buf->mgmt_subtype_mask == MLAN_MGMT_IE_INVALID_MASK)
        {
            continue;
        }

        (void)PRINTF("FW[%02u]\n", fw);
        has_ref = 0;
        for (drv = 0; drv < MAX_MGMT_IE_DRV_INDEX; drv++)
        {
            custom_ie_entry *ie = &pmadapter->mgmt_ie[drv];

            if (ie->cust_ie &&
                ie->cust_ie->ie_index == fw)
            {
                (void)PRINTF("   └── DRV[%02u]\n", drv);
                has_ref = 1;
            }
        }

        if (!has_ref)
        {
            (void)PRINTF("   └── (no drv)\n");
        }

        (void)PRINTF("\n");
    }
}

/**
 * @brief Dump all MGMT IE entries for debugging purposes.
 *
 * Prints the contents of the MGMT IE table for all interfaces managed by
 * the given mlan adapter. Intended for debug use only.
 *
 * @param pmadapter    Pointer to the mlan adapter structure
 */
void wifi_mgmt_ie_dump(pmlan_adapter pmadapter)
{
    if (!pmadapter)
        return;

    (void)PRINTF("\n\n========== WIFI MGMT IE DUMP ==========\n");
    ie_dump_buf_pool(&s_mgmt_buf_handle);
    ie_dump_mgmt_buffer(pmadapter);
    ie_dump_mgmt_ie(pmadapter);
    ie_dump_map(pmadapter);
    (void)PRINTF("=============================================\n\n");
}