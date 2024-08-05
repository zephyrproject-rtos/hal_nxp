/*
 *  Copyright 2023-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include "mem_pool.h"

#if CONFIG_MEM_POOLS
static int CalculateAndVerifyAlignment(int Alignment)
{
    /*********************************/
    int i;
    int alignmentBit = 0x1;
    /*********************************/

    /**
     *  Guarantee that the alignment is the size of a pointer.
     */
    if (Alignment < (int)sizeof(unsigned char *))
    {
        Alignment = (int)sizeof(unsigned char *);
    }

    for (i = 0; i < 31; i++)
    {
        if (Alignment == alignmentBit)
        {
            break;
        }
        alignmentBit <<= 1;
    }

    if (i >= 31)
    {
        return 0;
    }
    else
    {
        return Alignment;
    }
}

static int CalculateItemSize(int ItemSize, int Alignment)
{
    /*********************************/
    int alignmentCount;
    /*********************************/

    if (ItemSize <= Alignment)
    {
        /**
         *  The 2* accounts for the SList struct inside each memory block.
         */
        ItemSize = 2 * Alignment;
    }
    else
    {
        alignmentCount = ItemSize / Alignment;
        if (ItemSize % Alignment != 0)
        {
            alignmentCount++;
        }
        /**
         *  The +1 accounts for the SList struct inside each memory block.
         */
        ItemSize = ((alignmentCount + 1) * Alignment);
    }

    return ItemSize;
}

MemoryPool_t OSA_MemoryPoolCreate(
    MemPool_t *MemPool, int ItemSize, void *PreallocatedMemory, int PreallocatedMemorySize, int Alignment)
{
    /*********************************/
    unsigned char *ptr;
    SlNode_t *Node;
    osa_status_t status;
    /*********************************/

    Alignment = CalculateAndVerifyAlignment(Alignment);

    if (Alignment == 0)
    {
        return NULL;
    }

    ItemSize = CalculateItemSize(ItemSize, Alignment);

    status = OSA_MutexCreate((osa_mutex_handle_t)MemPool->Lock);
    if (status != KOSA_StatusSuccess)
    {
        return NULL;
    }

    InitStack(&MemPool->Stack);
    MemPool->ItemSize  = ItemSize;
    MemPool->Alignment = Alignment;

    ptr = (unsigned char *)PreallocatedMemory;

    while (PreallocatedMemorySize >= ItemSize)
    {
        Node = (SlNode_t *)ptr;

        PushOnStack(&MemPool->Stack, Node);
        ptr += MemPool->ItemSize;
        PreallocatedMemorySize -= MemPool->ItemSize;
    }

    return (MemoryPool_t)MemPool;
}

void *OSA_MemoryPoolAllocate(MemoryPool_t pool)
{
    /*********************************/
    MemPool_t *MemPool;
    SlNode_t *Node;
    unsigned char *ptr;
    /*********************************/

    MemPool = (MemPool_t *)pool;

    OSA_MutexLock((osa_mutex_handle_t)MemPool->Lock, osaWaitForever_c);

    if (MemPool->Stack.Count == 0)
    {
        OSA_MutexUnlock((osa_mutex_handle_t)MemPool->Lock);
        return NULL;
    }

    Node = PopOffStack(&MemPool->Stack);

    OSA_MutexUnlock((osa_mutex_handle_t)MemPool->Lock);

    ptr = ((unsigned char *)Node) + MemPool->Alignment;

    return (void *)ptr;
}

void OSA_MemoryPoolFree(MemoryPool_t pool, void *memory)
{
    /*********************************/
    MemPool_t *MemPool;
    SlNode_t *Node;
    unsigned char *ptr;
    /*********************************/

    MemPool = (MemPool_t *)pool;

    ptr = ((unsigned char *)memory) - MemPool->Alignment;

    Node = (SlNode_t *)ptr;

    OSA_MutexLock((osa_mutex_handle_t)MemPool->Lock, osaWaitForever_c);

    PushOnStack(&MemPool->Stack, Node);

    OSA_MutexUnlock((osa_mutex_handle_t)MemPool->Lock);
}

#endif
