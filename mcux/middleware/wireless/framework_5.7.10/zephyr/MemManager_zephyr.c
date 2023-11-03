/**
 * 2023-11-03 - Created by Sendrato.com
 * SPDX-License-Identifier: Apache-2.0
 */

#include "MemManager.h"
#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(nxp_mem, LOG_LEVEL_NONE);

/**
 * @brief Bytes on Zephyr-heap to be allocated for MemManager
 */
K_HEAP_DEFINE(_memHeap, CONFIG_MCUX_MIDDLEWARE_MEMMANAGER_HEAP_SIZE);

/**
 * @brief   This function initializes the message module private variables.
 *          Must be called at boot time, or if device is reset.
 *
 * @return  MEM_SUCCESS_c if init is successful. (It's always successful).
*/
memStatus_t MEM_Init(void)
{
    return MEM_SUCCESS_c;
}


/**
 * @brief  Frees the given buffer.
 *
 * @param[in] buffer   Pointer to memory block to free
 * @return             MEM_SUCCESS_c if free is successful,
 *                     MEM_ALLOC_ERROR_c otherwise
 */
memStatus_t MEM_BufferFree(void* buffer)
{
    if( buffer == NULL ) {
        return MEM_FREE_ERROR_c;
    }
    LOG_INF("F:%p", buffer);

    k_heap_free(&_memHeap, buffer);
    return MEM_SUCCESS_c;
}


/**
 * @brief   Allocate a block from the memory pools. The function uses the
 *          numBytes argument to look up a pool with adequate block sizes.
 *
 * @param[in]  numBytes  Size of buffer to allocate
 * @param[in]  poolId    <not used>
 * @param[in]  pCaller   <not used>
 * @return               Pointer to the allocated buffer, NULL if failed.
 */
void* MEM_BufferAllocWithId(uint32_t numBytes, uint8_t poolId, void *pCaller)
{
    ARG_UNUSED(poolId);
    ARG_UNUSED(pCaller);
    void* ptr = k_heap_alloc(&_memHeap, numBytes, K_NO_WAIT);
    LOG_INF("A:%p [%d]", ptr, numBytes);
    return ptr;
}
