/*
 * Copyright 2018-2021,2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_k4_flash.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flash_k4"
#endif

#if defined(__IAR_SYSTEMS_ICC__)
#define __RAMFUNC __ramfunc
#elif defined(__GNUC__)
#define __RAMFUNC __attribute__((section(".ramfunc"))) __attribute__((__noinline__))
#endif

#if defined(FLASH_DRIVER_IS_FLASH_RESIDENT) && (FLASH_DRIVER_IS_FLASH_RESIDENT == 1)
#define FCT_PLACEMENT __RAMFUNC
#else
#define FCT_PLACEMENT
#endif

#if defined(FWK_UNIT_TEST)
#define FLASH_STATIC
#else
#if (!defined(GCOV_DO_COVERAGE) || (GCOV_DO_COVERAGE == 0))
#define FLASH_STATIC static
#else
#define FLASH_STATIC __WEAK
#endif
#endif

#if defined(FLASH_DRIVER_IS_FLASH_RESIDENT) && FLASH_DRIVER_IS_FLASH_RESIDENT
/*!
 * @brief Constants for execute-in-RAM flash function.
 */
enum _ftfx_ram_func_constants
{
    Flash_RunCommandCodeSize     = 6U,  /*!< The flash_run_command code size of execute-in-RAM.*/
    Flash_ErsSequenceCommandSize = 25U, /*!< The flash_erase_sequence func code size of execute-in-RAM.*/
    Flash_PgmSequenceCommandSize = 30U, /*!< The flash_program_sequence func size of execute-in-RAM.*/
};
#endif

/*******************************************************************************
 * Async Mode Includes and Definitions
 ******************************************************************************/

#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
/*!
 * @brief Invalid buffer pool index marker.
 */
#define FLASH_ASYNC_INVALID_BUFFER_INDEX    (0xFFU)

/*!
 * @brief Check if two memory regions overlap.
 */
#define FLASH_REGIONS_OVERLAP(start1, len1, start2, len2) \
    (((start1) < ((start2) + (len2))) && ((start2) < ((start1) + (len1))))

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */



/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*! @brief Check flash parameters for validity */
static status_t flash_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline);

/*! @brief Check pflash parameters and adjust start address */
static status_t pflash_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t *start, uint32_t lengthInBytes, uint32_t alignmentBaseline);

/*! @brief Check IFR parameters and adjust start address */
static status_t ifr_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t *start, uint32_t lengthInBytes, uint32_t alignmentBaseline);

/*! @brief Validate user-provided erase key */
static status_t flash_check_user_key(uint32_t key);

/*! @brief Common erase sector implementation */
static status_t flash_erase_sector_impl(FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*! @brief Common program phrase implementation */
static status_t flash_program_phrase_impl(FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes);

/*! @brief Common program page implementation */
static status_t flash_program_page_impl(FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes);

/*! @brief Common verify erase phrase implementation */
static status_t flash_verify_erase_phrase_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes);

/*! @brief Common verify erase page implementation */
static status_t flash_verify_erase_page_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes);

/*! @brief Common verify erase sector implementation */
static status_t flash_verify_erase_sector_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes);

/*! @brief Common verify erase IFR phrase implementation */
static status_t flash_verify_erase_ifr_phrase_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes);

/*! @brief Common verify erase IFR page implementation */
static status_t flash_verify_erase_ifr_page_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes);

/*! @brief Common verify erase IFR sector implementation */
static status_t flash_verify_erase_ifr_sector_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes);
/*******************************************************************************
 * Async Mode Prototypes
 ******************************************************************************/

#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)

/*! @brief Initialize the async context (queue, mutex, buffer pool) */
static status_t FLASH_AsyncContextInit(flash_config_t *config);

static void FLASH_BufferPoolInit(void);

/*! @brief Get available contiguous space in circular buffer. */
static uint32_t FLASH_BufferPoolAvailable(void);

/*! @brief Allocate a buffer from the pool */
static uint8_t *FLASH_BufferPoolAlloc(uint32_t size, uint32_t *pOffset, uint32_t *pAllocSize);

/*! @brief Free a buffer back to the pool */
static void FLASH_BufferPoolFree(uint32_t offset, uint32_t allocSize);

/*! @brief Queue a flash operation */
static status_t FLASH_QueueOperation(flash_async_op_t *pOp);

/*! @brief Peek at the first operation in the queue without removing it */
static status_t FLASH_QueuePeek(flash_async_op_t *pOp);

/*! @brief Get and remove the first operation from the queue */
static status_t FLASH_QueueGet(flash_async_op_t *pOp);

/*! @brief Get current queue count */
FLASH_STATIC uint32_t FLASH_QueueCount(void);

/*! @brief Execute a single flash operation synchronously */
static status_t FLASH_ExecuteOperation(flash_async_op_t *pOp);

/*! @brief Apply pending queue operations to a read buffer */
static void FLASH_ApplyPendingOpsToReadBuffer(uint32_t readAddr, uint8_t *pDst, uint32_t length);

/*! @brief Check if there are pending operations affecting a given address range. */
static status_t FLASH_CheckPendingOpsOnRange(uint32_t startAddr, uint32_t length, bool *pHasPendingErase, bool *pHasPendingProgram);

#if defined(CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES) && (CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES == 1)
/*! @brief Try to merge a write operation with the last queued write */
static bool FLASH_TryMergeWrite(uint32_t start, uint8_t *src, uint32_t length);
#endif /* CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES */

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)

/*! @brief Global async context instance (static allocation) */
static flash_async_context_t s_flashAsyncContext;

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */

/*! *********************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
********************************************************************************** */
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)

/*!
 * @brief Initialize the operation queue.
 */
static void FLASH_QueueInit(void)
{
    s_flashAsyncContext.opQueue.head  = 0U;
    s_flashAsyncContext.opQueue.tail  = 0U;
    s_flashAsyncContext.opQueue.count = 0U;
}

/*!
 * @brief Check if the queue is full.
 *
 * @retval true Queue is full.
 * @retval false Queue has space.
 */
static inline bool FLASH_QueueIsFull(void)
{
    return (FLASH_QueueCount() >= CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE);
}

/*!
 * @brief Check if the queue is empty.
 *
 * @retval true Queue is empty.
 * @retval false Queue has elements.
 */
static inline bool FLASH_QueueIsEmpty(void)
{
    return (FLASH_QueueCount() == 0U);
}

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */


/*******************************************************************************
 * Code
 ******************************************************************************/

status_t FLASH_Init(flash_config_t *config)
{
    status_t status = kStatus_Fail;

    if (config == NULL)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        /* CM33 flash */
        config->msf1Config[0].flashDesc.blockBase  = FLASH_FEATURE_PFLASH0_START_ADDRESS;
        config->msf1Config[0].flashDesc.blockCount = FLASH_FEATURE_PFLASH0_BLOCK_COUNT;

#if (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA) || defined(CPU_KW45B41Z83AFPA) || \
     defined(CPU_KW45B41Z83AFTA) || defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA) || \
     defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA) || defined(CPU_K32W1480VFTA))
        /* M33 flash size 1MB */
        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE;
#elif (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA) || defined(CPU_KW45B41Z53AFPA) || \
       defined(CPU_KW45B41Z53AFTA) || defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA) || \
       defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
        /* M33 flash size 512KB */
        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE_512KB;
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0) || defined(CPU_KW47B42ZB6AFTA_cm33_core0) || \
     defined(CPU_KW47B42Z97AFTA_cm33_core0) || defined(CPU_KW47B42Z96AFTA_cm33_core0) || \
     defined(CPU_KW47B42Z83AFTA_cm33_core0) || defined(CPU_KW47B42ZB3AFTA_cm33_core0) || \
     defined(CPU_KW47B42ZB2AFTA_cm33_core0) || defined(CPU_KW47Z420B2AFTA) || \
     defined(CPU_KW47Z420B3AFTA) || defined(CPU_KW47Z42092AFTA) || \
     defined(CPU_KW47Z42082AFTA) || defined(CPU_MCXW727DMFTA_cm33_core0) || \
     defined(CPU_MCXW727AMFTA_cm33_core0) || defined(CPU_MCXW727CMFTA_cm33_core0))
        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE;
#elif (defined(CPU_MCXW716CMFTA) || (CPU_MCXW716CMFPA) || (CPU_MCXW716AMFTA) || (CPU_MCXW716AMFPA))
        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE;
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1) || defined(CPU_KW47B42ZB6AFTA_cm33_core1) || \
     defined(CPU_KW47B42Z97AFTA_cm33_core1) || defined(CPU_KW47B42Z96AFTA_cm33_core1) || \
     defined(CPU_KW47B42Z83AFTA_cm33_core1) || defined(CPU_KW47B42ZB3AFTA_cm33_core1) || \
     defined(CPU_KW47B42ZB2AFTA_cm33_core1) || defined(CPU_MCXW727DMFTA_cm33_core1) || \
     defined(CPU_MCXW727AMFTA_cm33_core1) || defined(CPU_MCXW727CMFTA_cm33_core1))
        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE;
#elif (defined(KW43_core0_SERIES) || defined(MCXW70_core0_SERIES))
        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE;

/* Instead of matching a device type default to generic size definition based on block count and size */

#elif (defined(FLASH_FEATURE_PFLASH0_BLOCK_COUNT) && FLASH_FEATURE_PFLASH0_BLOCK_COUNT > 0)

        config->msf1Config[0].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH0_BLOCK_COUNT * FLASH_FEATURE_PFLASH0_BLOCK_SIZE;

#else
#error "No valid CPU defined!"
#endif

        config->msf1Config[0].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_PFLASH0_IFR0_START_ADDRESS;
        config->msf1Config[0].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_PFLASH0_IFR0_SIZE;

        /* RF flash */
#if (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA) || defined(CPU_KW45B41Z83AFPA) || \
     defined(CPU_KW45B41Z83AFTA) || defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA) || \
     defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA) || defined(CPU_K32W1480VFTA))
        config->msf1Config[1].flashDesc.blockBase  = FLASH_FEATURE_PFLASH1_START_ADDRESS;
        config->msf1Config[1].flashDesc.blockCount = FLASH_FEATURE_PFLASH1_BLOCK_COUNT;
        config->msf1Config[1].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH1_BLOCK_COUNT * FLASH_FEATURE_PFLASH1_BLOCK_SIZE;

        config->msf1Config[1].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_PFLASH1_IFR0_START_ADDRESS;
        config->msf1Config[1].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_PFLASH1_IFR0_SIZE;

#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA) || defined(CPU_KW45Z41083AFPA) || \
       defined(CPU_KW45Z41083AFTA) || defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA) || \
       defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
        config->msf1Config[1].flashDesc.blockBase  = FLASH_FEATURE_PFLASH1_START_ADDRESS;
        config->msf1Config[1].flashDesc.blockCount = 0U;
        config->msf1Config[1].flashDesc.totalSize  = 0U;

        config->msf1Config[1].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_PFLASH1_IFR0_START_ADDRESS;
        config->msf1Config[1].ifrDesc.pflashIfr0MemSize = 0U;
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0) || defined(CPU_KW47B42ZB6AFTA_cm33_core0) || \
     defined(CPU_KW47B42Z97AFTA_cm33_core0) || defined(CPU_KW47B42Z96AFTA_cm33_core0) || \
     defined(CPU_KW47B42Z83AFTA_cm33_core0) || defined(CPU_KW47B42ZB3AFTA_cm33_core0) || \
     defined(CPU_KW47B42ZB2AFTA_cm33_core0) || defined(CPU_KW47Z420B2AFTA) || \
     defined(CPU_KW47Z420B3AFTA) || defined(CPU_KW47Z42092AFTA) || \
     defined(CPU_KW47Z42082AFTA) || defined(CPU_MCXW727DMFTA_cm33_core0) || \
     defined(CPU_MCXW727AMFTA_cm33_core0) || defined(CPU_MCXW727CMFTA_cm33_core0))
        config->msf1Config[1].flashDesc.blockBase  = FLASH_FEATURE_PFLASH1_START_ADDRESS;
        config->msf1Config[1].flashDesc.blockCount = FLASH_FEATURE_PFLASH1_BLOCK_COUNT;
        config->msf1Config[1].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH1_BLOCK_COUNT * FLASH_FEATURE_PFLASH1_BLOCK_SIZE;

        config->msf1Config[1].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_PFLASH1_IFR0_START_ADDRESS;
        config->msf1Config[1].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_PFLASH1_IFR0_SIZE;
#elif (defined(CPU_MCXW716CMFTA) || (CPU_MCXW716CMFPA) || (CPU_MCXW716AMFTA) || (CPU_MCXW716AMFPA))
        config->msf1Config[1].flashDesc.blockBase  = FLASH_FEATURE_PFLASH1_START_ADDRESS;
        config->msf1Config[1].flashDesc.blockCount = FLASH_FEATURE_PFLASH1_BLOCK_COUNT;
        config->msf1Config[1].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH1_BLOCK_COUNT * FLASH_FEATURE_PFLASH1_BLOCK_SIZE;

        config->msf1Config[1].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_PFLASH1_IFR0_START_ADDRESS;
        config->msf1Config[1].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_PFLASH1_IFR0_SIZE;
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1) || defined(CPU_KW47B42ZB6AFTA_cm33_core1) || \
     defined(CPU_KW47B42Z97AFTA_cm33_core1) || defined(CPU_KW47B42Z96AFTA_cm33_core1) || \
     defined(CPU_KW47B42Z83AFTA_cm33_core1) || defined(CPU_KW47B42ZB3AFTA_cm33_core1) || \
     defined(CPU_KW47B42ZB2AFTA_cm33_core1) || defined(CPU_MCXW727DMFTA_cm33_core1) || \
     defined(CPU_MCXW727AMFTA_cm33_core1) || defined(CPU_MCXW727CMFTA_cm33_core1))
        config->msf1Config[1].flashDesc.blockBase  = FLASH_FEATURE_PFLASH1_START_ADDRESS;
        config->msf1Config[1].flashDesc.blockCount = FLASH_FEATURE_PFLASH1_BLOCK_COUNT;
        config->msf1Config[1].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH1_BLOCK_COUNT * FLASH_FEATURE_PFLASH1_BLOCK_SIZE;

        config->msf1Config[1].ifrDesc.pflashIfr0Start   = FLASH_FEATURE_PFLASH1_IFR0_START_ADDRESS;
        config->msf1Config[1].ifrDesc.pflashIfr0MemSize = FLASH_FEATURE_PFLASH1_IFR0_SIZE;
#elif (defined(KW43_core0_SERIES) || defined(MCXW70_core0_SERIES))
        config->msf1Config[1].flashDesc.blockBase  = FLASH_FEATURE_PFLASH1_START_ADDRESS;
        config->msf1Config[1].flashDesc.blockCount = FLASH_FEATURE_PFLASH1_BLOCK_COUNT;
        config->msf1Config[1].flashDesc.totalSize =
            FLASH_FEATURE_PFLASH1_BLOCK_COUNT * FLASH_FEATURE_PFLASH1_BLOCK_SIZE;
#else
        /* PFLASH1 not present */
        config->msf1Config[1].flashDesc.blockBase  = 0U;
        config->msf1Config[1].flashDesc.blockCount = 0U;
        config->msf1Config[1].flashDesc.totalSize  = 0U;
#endif

        status = kStatus_FLASH_Success;
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Initialize async context when async mode is enabled */
        if (status == kStatus_FLASH_Success)
        {
            status = FLASH_AsyncContextInit(config);
        }
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }

    return status;
}

status_t FLASH_Read(uint8_t *dst, uint32_t start, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;

    if ((dst == NULL) || (lengthInBytes == 0U))
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Use pending-ops-aware read in async mode */
        status = FLASH_ReadWithPendingOps(start, dst, lengthInBytes);
#else
        /* Direct memory read in sync mode */
        (void)memcpy(dst, (const uint8_t *)(uintptr_t)start, lengthInBytes);
#endif
    }

    return status;
}


status_t FLASH_Erase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    status_t status = kStatus_Fail;

    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
        status = flash_check_user_key(key);
    }

    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: queue the erase operation */
        do
        {
            flash_async_op_t op;
            osa_status_t     osaStatus;

            /* Check if async context is initialized */
            if (!s_flashAsyncContext.initialized)
            {
                status = kStatus_FLASH_CommandFailure;
                break;
            }

            /* Acquire mutex for thread-safe access */
            osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
            assert(osaStatus == KOSA_StatusSuccess);
            (void)osaStatus;
            
            /* Check if there is enough space, if not try to flush one pending operations */
            if (FLASH_QueueIsFull())
            {
                status = FLASH_FlushPendingOperations(1U);
                if (status != kStatus_FLASH_Success)
                {
                    (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
                    break;
                }

                /* Re-check resources after flush */
                if (FLASH_QueueIsFull())
                {
                    /* Still not enough space - operation too large for async mode */
                    status = kStatus_FLASH_SizeError;
                    (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
                    break;
                }
            }

            /* Prepare the erase operation descriptor */
            op.opType          = kFlashAsyncOp_Erase;
            op.startAddress    = start;
            op.lengthInBytes   = lengthInBytes;
            op.pBuffer         = NULL;  /* No buffer needed for erase */
            op.key             = key;

            /* Store the FMU base for this operation */
            s_flashAsyncContext.fmuBase = base;

            /* Queue the operation */
            status = FLASH_QueueOperation(&op);

            if (status != kStatus_FLASH_Success)
            {
                /* Queue full or other error */
                (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
                break;
            }

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            s_flashAsyncContext.totalOperationsQueued++;
#endif
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
            status = kStatus_FLASH_Success;

        } while (false);

#else
        /* Sync mode: execute erase immediately */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_erase_sector_impl(base, start, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#if defined(SMSCM) || defined (SYSCON_FMC0_CTRL_DFC_MASK)
        /*
         * Data cache may contain stale values following a flash programming or erasing operation.
         * Data cache invalidation is only on KW43/MCXW70.
         */
        flash_cache_invalidate();
        flash_cache_speculation_control(true, base);

#endif
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_EraseAll(FMU_Type *base, uint32_t key)
{
    status_t status   = kStatus_Fail;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);
#if defined(RF_FMU)
    if (base == NULL || (baseTmp != FLASH && baseTmp != NBU_FLASH))
#else
    if (base == NULL || baseTmp != FLASH)
#endif
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        /* Validate the user key */
        status = flash_check_user_key(key);
    }

    if (kStatus_FLASH_Success == status)
    {
        uint32_t regPrimask = DisableGlobalIRQ();
        status = FLASH_CMD_EraseAll(base);
        EnableGlobalIRQ(regPrimask);
#if defined(SMSCM) || defined (SYSCON_FMC0_CTRL_DFC_MASK)
        /*
         * Data cache may contain stale values following a flash programming or erasing operation.
         * Data cache invalidation is only on KW43/MCXW70.
         */
        flash_cache_invalidate();
        flash_cache_speculation_control(true, base);

#endif
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_Program(flash_config_t *config, FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;

    /* Validate parameters first */
    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: allocate buffer, copy data, and queue the operation */
        do
        {
            flash_async_op_t op;
            uint32_t         bufferOffset = FLASH_ASYNC_INVALID_BUFFER_INDEX;
            uint32_t         allocSize    = 0U;
            uint8_t         *pBuffer      = NULL;

            /* Check if async context is initialized */
            if (!s_flashAsyncContext.initialized)
            {
                status = kStatus_FLASH_CommandFailure;
                break;
            }

            /* Validate source pointer */
            if (src == NULL)
            {
                status = kStatus_FLASH_InvalidArgument;
                break;
            }
            
            /* Check if there is enough space, if not try to flush pending operations */
            if ((FLASH_BufferPoolAvailable() < lengthInBytes) || FLASH_QueueIsFull())
            {
                status = FLASH_FlushPendingOperations(lengthInBytes);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                /* Re-check resources after flush */
                if ((FLASH_BufferPoolAvailable() < lengthInBytes) || FLASH_QueueIsFull())
                {
                    /* Still not enough space - operation too large for async mode */
                    status = kStatus_FLASH_SizeError;
                    break;
                }
            }

#if defined(CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES) && (CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES == 1)
            /* Try to merge with the last queued write operation */
            if (FLASH_TryMergeWrite(start, src, lengthInBytes))
            {
                /* Successfully merged - no need to queue new operation */
                status = kStatus_FLASH_Success;
                break;
            }
#endif /* CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES */

            /* Allocate buffer from pool */
            pBuffer = FLASH_BufferPoolAlloc(lengthInBytes, &bufferOffset, &allocSize);
            if (pBuffer == NULL)
            {
                /* No buffer available - should not happen after flush */
                status = kStatus_Busy;
                break;
            }

            /* Copy source data to allocated buffer */
            (void)memcpy(pBuffer, src, lengthInBytes);

            /* Prepare the program operation descriptor */
            op.opType        = kFlashAsyncOp_Program;
            op.startAddress  = start;
            op.lengthInBytes = lengthInBytes;
            op.pBuffer       = pBuffer;
            op.bufferOffset  = bufferOffset;
            op.bufferSize    = allocSize;
            op.key           = 0U;
            op.pSeed         = NULL;
            op.pSignature    = NULL;

            /* Store the FMU base for this operation */
            s_flashAsyncContext.fmuBase = base;

            /* Queue the operation */
            status = FLASH_QueueOperation(&op);

            if (status != kStatus_FLASH_Success)
            {
                /* Queue failed - free the buffer */
                FLASH_BufferPoolFree(op.bufferOffset, op.bufferSize);
                break;
            }

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            s_flashAsyncContext.totalOperationsQueued++;
#endif

            status = kStatus_FLASH_Success;
        } while (false);

#else
        /* Sync mode: execute program immediately */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_program_phrase_impl(base, start, src, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#if defined(SMSCM) || defined (SYSCON_FMC0_CTRL_DFC_MASK)
        /*
         * Data cache may contain stale values following a flash programming or erasing operation.
         * Data cache invalidation is only on KW43/MCXW70.
         */
        flash_cache_invalidate();
        flash_cache_speculation_control(true, base);
#endif
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_ProgramPage(flash_config_t *config, FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    status_t status = kStatus_Fail;

    /* Validate parameters first */
    status = flash_check_param(config, base, start, lengthInBytes, FLASH_FEATURE_PAGE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: allocate buffer, copy data, and queue the operation */
        do
        {
            flash_async_op_t op;
            uint32_t         bufferOffset = FLASH_ASYNC_INVALID_BUFFER_INDEX;
            uint32_t         allocSize    = 0U;
            uint8_t         *pBuffer      = NULL;

            /* Check if async context is initialized */
            if (!s_flashAsyncContext.initialized)
            {
                status = kStatus_FLASH_CommandFailure;
                break;
            }

            /* Validate source pointer */
            if (src == NULL)
            {
                status = kStatus_FLASH_InvalidArgument;
                break;
            }

            /* Check if there is enough space, if not try to flush pending operations */
            if ((FLASH_BufferPoolAvailable() < lengthInBytes) || FLASH_QueueIsFull())
            {
                status = FLASH_FlushPendingOperations(lengthInBytes);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                /* Re-check resources after flush */
                if ((FLASH_BufferPoolAvailable() < lengthInBytes) || FLASH_QueueIsFull())
                {
                    /* Still not enough space - operation too large for async mode */
                    status = kStatus_FLASH_SizeError;
                    break;
                }
            }

#if defined(CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES) && (CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES == 1)
            /* Try to merge with the last queued write operation */
            if (FLASH_TryMergeWrite(start, src, lengthInBytes))
            {
                /* Successfully merged - no need to queue new operation */
                status = kStatus_FLASH_Success;
                break;
            }
#endif /* CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES */

            /* Allocate buffer from pool */
            pBuffer = FLASH_BufferPoolAlloc(lengthInBytes, &bufferOffset, &allocSize);
            if (pBuffer == NULL)
            {
                /* No buffer available - should not happen after flush */
                status = kStatus_Busy;
                break;
            }

            /* Copy source data to allocated buffer */
            (void)memcpy(pBuffer, src, lengthInBytes);

            /* Prepare the program page operation descriptor */
            op.opType          = kFlashAsyncOp_ProgramPage;
            op.startAddress    = start;
            op.lengthInBytes   = lengthInBytes;
            op.pBuffer         = pBuffer;
            op.bufferOffset    = bufferOffset;
            op.bufferSize      = allocSize;
            op.key             = 0U;  /* Not used for program operations */
            op.pSeed           = NULL;
            op.pSignature      = NULL;

            /* Store the FMU base for this operation */
            s_flashAsyncContext.fmuBase = base;

            /* Queue the operation */
            status = FLASH_QueueOperation(&op);

            if (status != kStatus_FLASH_Success)
            {
                /* Queue failed - free the buffer */
                FLASH_BufferPoolFree(op.bufferOffset, op.bufferSize);
                break;
            }

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            s_flashAsyncContext.totalOperationsQueued++;
#endif

            status = kStatus_FLASH_Success;

        } while (false);
#else
        /* Sync mode: execute program page immediately */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_program_page_impl(base, start, src, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#if defined(SMSCM) || defined (SYSCON_FMC0_CTRL_DFC_MASK)
        /*
         * Data cache may contain stale values following a flash programming or erasing operation.
         * Data cache invalidation is only on KW43/MCXW70.
         */
        flash_cache_invalidate();
        flash_cache_speculation_control(true, base);

#endif

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; /* MISRA */
    }

    return status;
}

status_t FLASH_VerifyErasePhrase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status    = kStatus_Fail;
    uint32_t startaddr = start;

    status = pflash_check_param(config, base, &startaddr, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Synchronous mode with pending operations awareness */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            /* Check if async context is initialized */
            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                /* Check for pending operations on this range */
                status = FLASH_CheckPendingOpsOnRange(start, lengthInBytes,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                /* If there's a pending program on this area, verification should fail */
                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                /* If there's a pending erase that fully covers this range,
                 * return success (it will be erased) */
                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            /* No pending ops affecting this range - verify synchronously */
            uint32_t regPrimask = DisableGlobalIRQ();
            status = flash_verify_erase_phrase_impl(base, startaddr, lengthInBytes);
            EnableGlobalIRQ(regPrimask);

        } while (false);

#else
        /* Sync mode: execute verify erase phrase immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_verify_erase_phrase_impl(base, startaddr, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_VerifyErasePage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status    = kStatus_Fail;
    uint32_t startaddr = start;

    status = pflash_check_param(config, base, &startaddr, lengthInBytes, FLASH_FEATURE_PAGE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Synchronous mode with pending operations awareness */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(start, lengthInBytes,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            /* No pending ops affecting this range - verify synchronously */
            uint32_t regPrimask = DisableGlobalIRQ();
            status = flash_verify_erase_page_impl(base, startaddr, lengthInBytes);
            EnableGlobalIRQ(regPrimask);

        } while (false);
#else
        /* Sync mode: execute verify erase page immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_verify_erase_page_impl(base, startaddr, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_VerifyEraseSector(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status    = kStatus_Fail;
    uint32_t startaddr = start;

    status = pflash_check_param(config, base, &startaddr, lengthInBytes, FLASH_FEATURE_SECTOR_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: queue the verify erase sector operation */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            /* Check if async context is initialized */
            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(start, lengthInBytes,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            uint32_t regPrimask = DisableGlobalIRQ();
            status = flash_verify_erase_sector_impl(base, startaddr, lengthInBytes);
            EnableGlobalIRQ(regPrimask);

        } while (false);

#else
        /* Sync mode: execute verify erase sector immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_verify_erase_sector_impl(base, startaddr, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_VerifyEraseIFRPhrase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status    = kStatus_Fail;
    uint32_t startaddr = start;

    status = ifr_check_param(config, base, &startaddr, lengthInBytes, FLASH_FEATURE_PHRASE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(start, lengthInBytes,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            uint32_t regPrimask = DisableGlobalIRQ();
            status = flash_verify_erase_ifr_phrase_impl(base, startaddr, lengthInBytes);
            EnableGlobalIRQ(regPrimask);

        } while (false);

#else
        /* Sync mode: execute verify erase IFR phrase immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_verify_erase_ifr_phrase_impl(base, startaddr, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_VerifyEraseIFRPage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status    = kStatus_Fail;
    uint32_t startaddr = start;

    status = ifr_check_param(config, base, &startaddr, lengthInBytes, FLASH_FEATURE_PAGE_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: queue the verify erase IFR page operation */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(start, lengthInBytes,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            uint32_t regPrimask = DisableGlobalIRQ();
            status = flash_verify_erase_ifr_page_impl(base, startaddr, lengthInBytes);
            EnableGlobalIRQ(regPrimask);

        } while (false);

#else
        /* Sync mode: execute verify erase IFR page immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_verify_erase_ifr_page_impl(base, startaddr, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_VerifyEraseIFRSector(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status    = kStatus_Fail;
    uint32_t startaddr = start;

    status = ifr_check_param(config, base, &startaddr, lengthInBytes, FLASH_FEATURE_SECTOR_SIZE);
    if (status == kStatus_FLASH_Success)
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: queue the verify erase IFR sector operation */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(start, lengthInBytes,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            uint32_t regPrimask = DisableGlobalIRQ();
            status = flash_verify_erase_ifr_sector_impl(base, startaddr, lengthInBytes);
            EnableGlobalIRQ(regPrimask);

        } while (false);

#else
        /* Sync mode: execute verify erase IFR sector immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = flash_verify_erase_ifr_sector_impl(base, startaddr, lengthInBytes);
        EnableGlobalIRQ(regPrimask);

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }
    else
    {
        ; // MISRA
    }

    return status;
}

status_t FLASH_VerifyEraseAll(FMU_Type *base)
{
    status_t status   = kStatus_Fail;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);
#if defined(RF_FMU)
    if (base == NULL || ((baseTmp != FLASH) && (baseTmp != NBU_FLASH)))
#else
    if (base == NULL || baseTmp != FLASH)
#endif
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: queue the verify erase all operation */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(0, 0xFFFFFFFFU,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            {
                uint32_t regPrimask = DisableGlobalIRQ();
                status = FLASH_CMD_VerifyEraseAll(base);
                EnableGlobalIRQ(regPrimask);
            }
        } while (false);

#else
        /* Sync mode: execute verify erase all immediately (original behavior) */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = FLASH_CMD_VerifyEraseAll(base);
        EnableGlobalIRQ(regPrimask);
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }

    return status;
}

status_t FLASH_VerifyEraseBlock(flash_config_t *config, FMU_Type *base, uint32_t blockaddr)
{
    status_t status      = kStatus_Fail;
    uint32_t nsblockaddr = blockaddr & FLASH_ADDR_MASK;
    FMU_Type *baseTmp    = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

#if defined(RF_FMU)
    if (config == NULL || base == NULL || ((baseTmp != FLASH) && (baseTmp != NBU_FLASH)))
#else
    if (config == NULL || base == NULL || baseTmp != FLASH)
#endif
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((nsblockaddr != config->msf1Config[0].flashDesc.blockBase) &&
             (nsblockaddr != config->msf1Config[1].flashDesc.blockBase))
    {
        status = kStatus_FLASH_AddressError;
    }
    else
    {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
        /* Async mode: queue the verify erase block operation */
        do
        {
            bool hasPendingErase   = false;
            bool hasPendingProgram = false;

            if (!s_flashAsyncContext.initialized)
            {
                /* Fall through to sync verification */
            }
            else
            {
                status = FLASH_CheckPendingOpsOnRange(0, 0x80000u,
                                                       &hasPendingErase,
                                                       &hasPendingProgram);
                if (status != kStatus_FLASH_Success)
                {
                    break;
                }

                if (hasPendingProgram)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                if (hasPendingErase)
                {
                    status = kStatus_FLASH_Success;
                    break;
                }
            }

            {
                uint32_t regPrimask = DisableGlobalIRQ();
                status = FLASH_CMD_VerifyEraseBlock(base, 0U);
                EnableGlobalIRQ(regPrimask);
            }
        } while (false);

#else
        /* Sync mode: execute verify erase block immediately (original behavior) */
        /* K4W1 M33 and NBU flash both have only one block, so 0U is sufficient here */
        uint32_t regPrimask = DisableGlobalIRQ();
        status = FLASH_CMD_VerifyEraseBlock(base, 0U);
        EnableGlobalIRQ(regPrimask);
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
    }

    return status;
}

status_t Read_Into_MISR(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t ending, uint32_t *seed, uint32_t *signature)
{
    status_t status    = kStatus_Fail;
    uint32_t startAddr = start;

    if ((start >= ending) || (seed == NULL) ||
        (((ending + FLASH_FEATURE_PHRASE_SIZE) & (FLASH_FEATURE_PAGE_SIZE - 1U)) != 0u))
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((ending & (FLASH_FEATURE_PHRASE_SIZE - 1U)) != 0u)
    {
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        status = pflash_check_param(config, base, &startAddr, (ending - start), FLASH_FEATURE_PAGE_SIZE);
        if (status == kStatus_FLASH_Success)
        {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
            /* Async mode: queue the Read Into MISR operation */
            do
            {
                flash_async_op_t op;

                /* Check if async context is initialized */
                if (!s_flashAsyncContext.initialized)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                /* Validate signature pointer */
                if (signature == NULL)
                {
                    status = kStatus_FLASH_InvalidArgument;
                    break;
                }

                /* Prepare the Read Into MISR operation descriptor */
                op.opType          = kFlashAsyncOp_ReadIntoMISR;
                op.startAddress    = startAddr;
                op.lengthInBytes   = ending - start;  /* Store length for end address calculation */
                op.pBuffer         = NULL;            /* Not used for MISR */
                op.key             = 0U;
                op.pSeed           = seed;            /* Store seed pointer */
                op.pSignature      = signature;       /* Store signature pointer */

                /* Store the FMU base for this operation */
                s_flashAsyncContext.fmuBase = base;

                /* Queue the operation */
                status = FLASH_QueueOperation(&op);

                if (status != kStatus_FLASH_Success)
                {
                    /* Queue full or other error */
                    break;
                }
#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
                s_flashAsyncContext.totalOperationsQueued++;
#endif
                status = kStatus_FLASH_Success;
            } while (false);
#else
            /* Sync mode: execute Read Into MISR immediately (original behavior) */
            uint32_t endAddr;
            if (startAddr > UINT32_MAX - (ending - start))
            {
                return kStatus_FLASH_AddressError; // Handle overflow error
            }
            endAddr = startAddr + ending - start;
            uint32_t regPrimask = DisableGlobalIRQ();
            status  = FLASH_CMD_ReadIntoMISR(base, startAddr, endAddr, seed, signature);
            EnableGlobalIRQ(regPrimask);
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
        }
        else
        {
            ; // MISRA
        }
    }

    return status;
}

status_t Read_IFR_Into_MISR(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t ending, uint32_t *seed, uint32_t *signature)
{
    status_t status    = kStatus_Fail;
    uint32_t startAddr = start;

    if ((start >= ending) || (seed == NULL) ||
        (((ending + FLASH_FEATURE_PHRASE_SIZE) & (FLASH_FEATURE_PAGE_SIZE - 1U)) != 0U))
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((ending & (FLASH_FEATURE_PHRASE_SIZE - 1U)) != 0u)
    {
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        status = ifr_check_param(config, base, &startAddr, (ending - start), FLASH_FEATURE_PAGE_SIZE);
        if (status == kStatus_FLASH_Success)
        {
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)
            /* Async mode: queue the Read IFR Into MISR operation */
            do
            {
                flash_async_op_t op;

                /* Check if async context is initialized */
                if (!s_flashAsyncContext.initialized)
                {
                    status = kStatus_FLASH_CommandFailure;
                    break;
                }

                /* Validate signature pointer */
                if (signature == NULL)
                {
                    status = kStatus_FLASH_InvalidArgument;
                    break;
                }

                /* Prepare the Read IFR Into MISR operation descriptor */
                op.opType          = kFlashAsyncOp_ReadIFRIntoMISR;
                op.startAddress    = startAddr;
                op.lengthInBytes   = ending - start;  /* Store length for end address calculation */
                op.pBuffer         = NULL;            /* Not used for MISR */
                op.key             = 0U;
                op.pSeed           = seed;            /* Store seed pointer */
                op.pSignature      = signature;       /* Store signature pointer */

                /* Store the FMU base for this operation */
                s_flashAsyncContext.fmuBase = base;

                /* Queue the operation */
                status = FLASH_QueueOperation(&op);

                if (status != kStatus_FLASH_Success)
                {
                    /* Queue full or other error */
                    break;
                }

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
                s_flashAsyncContext.totalOperationsQueued++;
#endif

                status = kStatus_FLASH_Success;

            } while (false);

#else
            /* Sync mode: execute Read IFR Into MISR immediately (original behavior) */
            uint32_t endAddr;
            if (startAddr > UINT32_MAX - (ending - start))
            {
                return kStatus_FLASH_AddressError; // Handle overflow error
            }
            endAddr = startAddr + ending - start;
            uint32_t regPrimask = DisableGlobalIRQ();
            status  = FLASH_CMD_ReadIFRIntoMISR(base, startAddr, endAddr, seed, signature);
            EnableGlobalIRQ(regPrimask);
#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
        }
        else
        {
            ; // MISRA
        }
    }

    return status;
}

status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    status_t status = kStatus_FLASH_Success;

    switch (whichProperty)
    {
        case kFLASH_PropertyPflash0TotalSize:
            *value = config->msf1Config[0].flashDesc.totalSize;
            break;
        case kFLASH_PropertyPflash0BlockSize:
            *value = config->msf1Config[0].flashDesc.totalSize / config->msf1Config[0].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash0BlockCount:
            *value = config->msf1Config[0].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash0BlockBaseAddr:
            *value = config->msf1Config[0].flashDesc.blockBase;
            break;
        case kFLASH_PropertyPflash0SectorSize:
        case kFLASH_PropertyPflash1SectorSize:
            *value = FLASH_FEATURE_SECTOR_SIZE;
            break;
        case kFLASH_PropertyPflash1TotalSize:
            *value = config->msf1Config[1].flashDesc.totalSize;
            break;
        case kFLASH_PropertyPflash1BlockSize:
            *value = config->msf1Config[1].flashDesc.totalSize / config->msf1Config[1].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash1BlockCount:
            *value = config->msf1Config[1].flashDesc.blockCount;
            break;
        case kFLASH_PropertyPflash1BlockBaseAddr:
            *value = config->msf1Config[1].flashDesc.blockBase;
            break;
        default:
            status = kStatus_FLASH_UnknownProperty;
            /* To avoid MISRA-C 2012 rule 16.4 issue. */
            break;
    }
    return status;
}

#if defined(SMSCM)
FCT_PLACEMENT void flash_cache_disable(void)
{
    /* Clear flash cache */
    SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_FLASH_CACHE_CTRL_MASK)) | SMSCM_FLASH_CACHE_CTRL(0x1);
    /* disable flash cache once cache clear was applied */
    SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_FLASH_CACHE_CTRL_MASK)) | SMSCM_FLASH_CACHE_CTRL(0x8);
    /* disable flash speculation buffer and data prefetch */
    SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_FLASH_SPECULATION_CTRL_MASK)) | SMSCM_FLASH_SPECULATION_CTRL(0x3);
    __ISB();
    __DSB();
}

FCT_PLACEMENT void flash_cache_speculation_control(bool isPreProcess, FMU_Type *base)
{
    if (base == FLASH)
    {
        if (isPreProcess == false)
        {
            SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_FLASH_CACHE_CTRL_MASK)) | SMSCM_FLASH_CACHE_CTRL(0x1);
            SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_FLASH_SPECULATION_CTRL_MASK)) | SMSCM_FLASH_SPECULATION_CTRL(0x0);
        }
        else
        {
            SMSCM->OCMDR0 = (SMSCM->OCMDR0 & (~SMSCM_FLASH_SPECULATION_CTRL_MASK)) | SMSCM_FLASH_SPECULATION_CTRL(0x3);
        }
    }
#if defined(RF_FMU)
    else if (base == NBU_FLASH)
    {
        if (isPreProcess == false)
        {
            RF_FMCCFG->RFMCCFG = (RF_FMCCFG->RFMCCFG & (~NBU_FLASH_CACHE_CTRL_MASK)) | NBU_FLASH_CACHE_CTRL(0x1);
            RF_FMCCFG->RFMCCFG =
                (RF_FMCCFG->RFMCCFG & (~NBU_FLASH_SPECULATION_CTRL_MASK)) | NBU_FLASH_SPECULATION_CTRL(0x0);
        }
        else
        {
            RF_FMCCFG->RFMCCFG =
                (RF_FMCCFG->RFMCCFG & (~NBU_FLASH_SPECULATION_CTRL_MASK)) | NBU_FLASH_SPECULATION_CTRL(0x3);
        }
    }
#endif
    else
    {
        ; /* No action required */
    }
    /* Memory barriers for good measure.
     * All Cache, Branch predictor and TLB maintenance operations before this instruction complete */
    __ISB();
    __DSB();
}

void flash_cache_invalidate(void)
{
    /* save previous OCMDR0 value */
    uint32_t reg_sav = SMSCM->OCMDR0;
    /* Disable flash cache : in the absence of specific cache invalidation function */
    flash_cache_disable();
    __ISB();
    __DSB();
    /* Re-enable Flash cache by restoring previous configuration */
    SMSCM->OCMDR0 = reg_sav;

}

#else

#if defined SYSCON_FMC0_CTRL_DFC_MASK

FCT_PLACEMENT void flash_cache_invalidate(void)
{
    SYSCON->AUTHENTICATE = 0xaaaaaaaa;
    __ISB();
    __DSB();
    SYSCON->FMC0_CTRL |= SYSCON_FMC0_CTRL_ECFC_MASK; /* Execute clear cache */
    __ISB();
    __DSB();
    SYSCON->FMC0_CTRL |= (SYSCON_FMC0_CTRL_DFDC_MASK|SYSCON_FMC0_CTRL_DFS_MASK|SYSCON_FMC0_CTRL_DDP_MASK); /* Disable Data Cache - Disable Data Prefetch - Disable Flash Speculation */
    __ISB();
    __DSB();
    SYSCON->FMC0_CTRL &= ~(SYSCON_FMC0_CTRL_DFDC_MASK|SYSCON_FMC0_CTRL_ECFC_MASK|SYSCON_FMC0_CTRL_DFS_MASK|SYSCON_FMC0_CTRL_DDP_MASK); /* re-enable all the disabled bits */
    __ISB();
    __DSB();
}

FCT_PLACEMENT void flash_cache_disable(void)
{
    SYSCON->AUTHENTICATE = 0xaaaaaaaa;
    SYSCON->FMC0_CTRL |= (SYSCON_FMC0_CTRL_DFDC_MASK | SYSCON_FMC0_CTRL_DFC_MASK | SYSCON_FMC0_CTRL_DFIC_MASK);
    SYSCON->FMC0_CTRL |= SYSCON_FMC0_CTRL_ECFC_MASK;
    /* Memory barriers for good measure.
     * All Cache, Branch predictor and TLB maintenance operations before this instruction complete */
    __ISB();
    __DSB();
}
FCT_PLACEMENT void flash_cache_enable(void)
{
    SYSCON->AUTHENTICATE = 0xaaaaaaaa;
    SYSCON->FMC0_CTRL &= ~(SYSCON_FMC0_CTRL_DFDC_MASK | SYSCON_FMC0_CTRL_DFC_MASK | SYSCON_FMC0_CTRL_DFIC_MASK);
    /* Memory barriers for good measure.
     * All Cache, Branch predictor and TLB maintenance operations before this instruction complete */
    __ISB();
    __DSB();
}

#endif

#if defined SYSCON_FMC0_CTRL_DFS_MASK

FCT_PLACEMENT void flash_cache_speculation_control(bool isPreProcess, FMU_Type *base)
{
    (void)base;
    SYSCON->AUTHENTICATE = 0xaaaaaaaa;

    if (isPreProcess == false)
    {
         SYSCON->FMC0_CTRL |=  SYSCON_FMC0_CTRL_DFS_MASK;
    }
    else
    {
         SYSCON->FMC0_CTRL &= ~SYSCON_FMC0_CTRL_DFS_MASK;
    }
    /* Memory barriers for good measure.
     * All Cache, Branch predictor and TLB maintenance operations before this instruction complete */
    __ISB();
    __DSB();
}
#endif
#endif

static status_t flash_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline)
{
    status_t status   = kStatus_FLASH_InvalidArgument;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

    if (lengthInBytes == 0U)
    {
        status = kStatus_FLASH_Success;
    }
#if defined(RF_FMU)
    else if (config == NULL || base == NULL || ((baseTmp != FLASH) && (baseTmp != NBU_FLASH)))
#else
    else if (config == NULL || base == NULL || baseTmp != FLASH)
#endif
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((alignmentBaseline > 0U) && ((start & (alignmentBaseline - 1U)) != 0u))
    {
        /* Verify the start is alignmentBaseline aligned. */
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        start = start & FLASH_ADDR_MASK;

        if (baseTmp == FLASH)
        {
            /* Validates the range of the given address */
            if ((start >= config->msf1Config[0].flashDesc.blockBase) &&
                ((start + lengthInBytes) <=
                 (config->msf1Config[0].flashDesc.blockBase + config->msf1Config[0].flashDesc.totalSize)))
            {
                status = kStatus_FLASH_Success;
            }
            else

                if ((start >= config->msf1Config[0].ifrDesc.pflashIfr0Start) &&
                    ((start + lengthInBytes) <=
                     (config->msf1Config[0].ifrDesc.pflashIfr0Start + config->msf1Config[0].ifrDesc.pflashIfr0MemSize)))
            {
                status = kStatus_FLASH_Success;
            }
            else
            {
                status = kStatus_FLASH_AddressError;
            }
        }
        else // if (base == NBU_FLASH || base == NBU_FLASH_NS)
        {
            /* Validates the range of the given address */
            if ((start >= config->msf1Config[1].flashDesc.blockBase) &&
                ((start + lengthInBytes) <=
                 (config->msf1Config[1].flashDesc.blockBase + config->msf1Config[1].flashDesc.totalSize)))
            {
                status = kStatus_FLASH_Success;
            }
            else

                if ((start >= config->msf1Config[1].ifrDesc.pflashIfr0Start) &&
                    ((start + lengthInBytes) <=
                     (config->msf1Config[1].ifrDesc.pflashIfr0Start + config->msf1Config[1].ifrDesc.pflashIfr0MemSize)))
            {
                status = kStatus_FLASH_Success;
            }
            else
            {
                status = kStatus_FLASH_AddressError;
            }
        }
    }

    return status;
}

static status_t pflash_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t *start, uint32_t lengthInBytes, uint32_t alignmentBaseline)
{
    status_t status   = kStatus_FLASH_InvalidArgument;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

    if (lengthInBytes == 0U)
    {
        status = kStatus_FLASH_Success;
    }
#if defined(RF_FMU)
    else if ((config == NULL) || (base == NULL) || ((baseTmp != FLASH) && (baseTmp != NBU_FLASH)))
#else
    else if ((config == NULL) || (base == NULL) || (baseTmp != FLASH))
#endif
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((alignmentBaseline > 0U) && ((*start & (alignmentBaseline - 1U)) != 0u))
    {
        /* Verify the start is alignmentBaseline aligned. */
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        *start &= FLASH_ADDR_MASK;

        if (baseTmp == FLASH)
        {
            /* Validates the range of the given address */
            if ((*start >= config->msf1Config[0].flashDesc.blockBase) &&
                ((*start + lengthInBytes) <=
                 (config->msf1Config[0].flashDesc.blockBase + config->msf1Config[0].flashDesc.totalSize)))
            {
                *start -= config->msf1Config[0].flashDesc.blockBase;
                status = kStatus_FLASH_Success;
            }
            else
            {
                status = kStatus_FLASH_AddressError;
            }
        }
        else // if (base == NBU_FLASH || base == NBU_FLASH_NS)
        {
            /* Validates the range of the given address */
            if ((*start >= config->msf1Config[1].flashDesc.blockBase) &&
                ((*start + lengthInBytes) <=
                 (config->msf1Config[1].flashDesc.blockBase + config->msf1Config[1].flashDesc.totalSize)))
            {
                *start -= config->msf1Config[1].flashDesc.blockBase;
                status = kStatus_FLASH_Success;
            }
            else
            {
                status = kStatus_FLASH_AddressError;
            }
        }
    }

    return status;
}

static status_t ifr_check_param(
    flash_config_t *config, FMU_Type *base, uint32_t *start, uint32_t lengthInBytes, uint32_t alignmentBaseline)
{
    status_t status   = kStatus_FLASH_InvalidArgument;
    FMU_Type *baseTmp = (FMU_Type *)((uint32_t)base & FLASH_ADDR_MASK);

    if (lengthInBytes == 0U)
    {
        status = kStatus_FLASH_Success;
    }
#if defined(RF_FMU)
    else if (config == NULL || base == NULL || ((baseTmp != FLASH) && (baseTmp != NBU_FLASH)))
#else
    else if (config == NULL || base == NULL || baseTmp != FLASH)
#endif
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else if ((alignmentBaseline > 0U) && ((*start & (alignmentBaseline - 1U)) != 0u))
    {
        /* Verify the start is alignmentBaseline aligned. */
        status = kStatus_FLASH_AlignmentError;
    }
    else
    {
        *start &= FLASH_ADDR_MASK;

        if (baseTmp == FLASH)
        {
            if ((*start >= config->msf1Config[0].ifrDesc.pflashIfr0Start) &&
                ((*start + lengthInBytes) <=
                 (config->msf1Config[0].ifrDesc.pflashIfr0Start + config->msf1Config[0].ifrDesc.pflashIfr0MemSize)))
            {
                *start -= config->msf1Config[0].ifrDesc.pflashIfr0Start;
                status = kStatus_FLASH_Success;
            }
            else
            {
                status = kStatus_FLASH_AddressError;
            }
        }
        else // if (base == NBU_FLASH || base == NBU_FLASH_NS)
        {
            if ((*start >= config->msf1Config[1].ifrDesc.pflashIfr0Start) &&
                ((*start + lengthInBytes) <=
                 (config->msf1Config[1].ifrDesc.pflashIfr0Start + config->msf1Config[1].ifrDesc.pflashIfr0MemSize)))
            {
                *start -= config->msf1Config[1].ifrDesc.pflashIfr0Start;
                status = kStatus_FLASH_Success;
            }
            else
            {
                status = kStatus_FLASH_AddressError;
            }
        }
    }

    return status;
}

/*! @brief Validates the given user key for flash erase APIs.*/
static status_t flash_check_user_key(uint32_t key)
{
    status_t status = kStatus_Fail;

    /* Validate the user key */
    if (key != (uint32_t)kFLASH_ApiEraseKey)
    {
        status = kStatus_FLASH_EraseKeyError;
    }
    else
    {
        status = kStatus_FLASH_Success;
    }

    return status;
}

/*!
 * @brief Common erase sector implementation.
 *
 * @param base Flash controller base address.
 * @param start Start address (already validated).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_erase_sector_impl(FMU_Type *base, uint32_t start, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    if (start > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    uint32_t endAddress = start + lengthInBytes - 1U;

    while (start <= endAddress)
    {
        status = FLASH_CMD_EraseSector(base, start);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        start += FLASH_FEATURE_SECTOR_SIZE;
    }

    return status;
}

/*!
 * @brief Common program phrase implementation.
 *
 * @param base Flash controller base address.
 * @param start Start address (already validated).
 * @param src Source data pointer.
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_program_phrase_impl(FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t alignedLength = ALIGN_DOWN(lengthInBytes, sizeof(uint8_t) * FLASH_FEATURE_PHRASE_SIZE);
    uint32_t extraBytes = 0U;
    uint32_t *srcWord = (uint32_t *)(uintptr_t)src;

    if (lengthInBytes >= alignedLength)
    {
        extraBytes = lengthInBytes - alignedLength;
    }
    else
    {
        return kStatus_FLASH_AddressError;
    }

    if (alignedLength > 0U)
    {
        uint32_t endAddress;
        if (start > UINT32_MAX - alignedLength)
        {
            return kStatus_FLASH_AddressError;
        }
        endAddress = start + alignedLength - 1U;
        
        while (start <= endAddress)
        {
            status = FLASH_CMD_ProgramPhrase(base, start, srcWord);
            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            start += FLASH_FEATURE_PHRASE_SIZE;
            srcWord += FLASH_FEATURE_PHRASE_SIZE_IN_WORD;
        }
    }

    if ((kStatus_FLASH_Success == status) && (extraBytes > 0U))
    {
        uint32_t extraData[4] = {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu};

        union
        {
            uint32_t *src;
            const void *srcVoid;
        } srcPtr;
        srcPtr.src = srcWord;

        union
        {
            uint32_t *xData;
            void *xDataVoid;
        } xDataPtr;
        xDataPtr.xData = (uint32_t *)&extraData[0];

        (void)memcpy(xDataPtr.xDataVoid, srcPtr.srcVoid, extraBytes);
        status = FLASH_CMD_ProgramPhrase(base, start, extraData);
    }

    return status;
}

/*!
 * @brief Common program page implementation.
 *
 * @param base Flash controller base address.
 * @param start Start address (already validated).
 * @param src Source data pointer.
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_program_page_impl(FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t alignedLength = ALIGN_DOWN(lengthInBytes, sizeof(uint8_t) * FLASH_FEATURE_PAGE_SIZE);
    uint32_t extraBytes = 0U;
    uint32_t *srcWord = (uint32_t *)(uintptr_t)src;

    if (lengthInBytes >= alignedLength)
    {
        extraBytes = lengthInBytes - alignedLength;
    }
    else
    {
        return kStatus_FLASH_AddressError;
    }

    if (alignedLength > 0U)
    {
        uint32_t endAddress;
        if (start > UINT32_MAX - alignedLength)
        {
            return kStatus_FLASH_AddressError;
        }
        endAddress = start + alignedLength - 1U;
        
        while (start <= endAddress)
        {
            status = FLASH_CMD_ProgramPage(base, start, srcWord);
            if (kStatus_FLASH_Success != status)
            {
                break;
            }
            start += FLASH_FEATURE_PAGE_SIZE;
            srcWord += FLASH_FEATURE_PAGE_SIZE_IN_WORD;
        }
    }

    if ((kStatus_FLASH_Success == status) && (extraBytes > 0U))
    {
        uint32_t extraData[32];
        (void)memset(extraData, 0xFF, sizeof(extraData));
        if (extraBytes <= sizeof(extraData))
        {
            (void)memcpy((void *)extraData, (const void *)srcWord, extraBytes);
            status = FLASH_CMD_ProgramPage(base, start, extraData);
        }
        else
        {
            status = kStatus_FLASH_SizeError;
        }
    }

    return status;
}

/*!
 * @brief Common verify erase phrase implementation.
 *
 * @param base Flash controller base address.
 * @param startAddr Start address (already validated and adjusted).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_verify_erase_phrase_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t endAddress;
    
    if (startAddr > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    
    endAddress = startAddr + lengthInBytes - 1U;
    
    while (startAddr <= endAddress)
    {
        status = FLASH_CMD_VerifyErasePhrase(base, startAddr);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        startAddr += FLASH_FEATURE_PHRASE_SIZE;
    }
    
    return status;
}

/*!
 * @brief Common verify erase page implementation.
 *
 * @param base Flash controller base address.
 * @param startAddr Start address (already validated and adjusted).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_verify_erase_page_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t endAddress;
    
    if (startAddr > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    
    endAddress = startAddr + lengthInBytes - 1U;
    
    while (startAddr <= endAddress)
    {
        status = FLASH_CMD_VerifyErasePage(base, startAddr);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        startAddr += FLASH_FEATURE_PAGE_SIZE;
    }
    
    return status;
}

/*!
 * @brief Common verify erase IFR phrase implementation.
 *
 * @param base Flash controller base address.
 * @param startAddr Start address (already validated and adjusted).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_verify_erase_ifr_phrase_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t endAddress;
    
    if (startAddr > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    
    endAddress = startAddr + lengthInBytes - 1U;
    
    while (startAddr <= endAddress)
    {
        status = FLASH_CMD_VerifyEraseIFRPhrase(base, startAddr);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        startAddr += FLASH_FEATURE_PHRASE_SIZE;
    }
    
    return status;
}

/*!
 * @brief Common verify erase IFR page implementation.
 *
 * @param base Flash controller base address.
 * @param startAddr Start address (already validated and adjusted).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_verify_erase_ifr_page_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t endAddress;
    
    if (startAddr > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    
    endAddress = startAddr + lengthInBytes - 1U;
    
    while (startAddr <= endAddress)
    {
        status = FLASH_CMD_VerifyEraseIFRPage(base, startAddr);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        startAddr += FLASH_FEATURE_PAGE_SIZE;
    }
    
    return status;
}


/*!
 * @brief Common verify erase IFR sector implementation.
 *
 * @param base Flash controller base address.
 * @param startAddr Start address (already validated and adjusted).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_verify_erase_ifr_sector_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t endAddress;
    
    if (startAddr > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    
    endAddress = startAddr + lengthInBytes - 1U;
    
    while (startAddr <= endAddress)
    {
        status = FLASH_CMD_VerifyEraseIFRSector(base, startAddr);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        startAddr += FLASH_FEATURE_SECTOR_SIZE;
    }
    
    return status;
}

/*!
 * @brief Common verify erase sector implementation.
 *
 * @param base Flash controller base address.
 * @param startAddr Start address (already validated and adjusted).
 * @param lengthInBytes Length in bytes (already validated).
 *
 * @return Status of the operation.
 */
static status_t flash_verify_erase_sector_impl(FMU_Type *base, uint32_t startAddr, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t endAddress;
    
    if (startAddr > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }
    
    endAddress = startAddr + lengthInBytes - 1U;
    
    while (startAddr <= endAddress)
    {
        status = FLASH_CMD_VerifyEraseSector(base, startAddr);
        if (kStatus_FLASH_Success != status)
        {
            break;
        }
        startAddr += FLASH_FEATURE_SECTOR_SIZE;
    }
    
    return status;
}


#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)

/*!
 * @brief Process pending flash operations from the queue.
 *
 * This function should be called from the idle task or a low-priority task
 * to process queued flash operations. It checks if there is sufficient idle
 * time available (via the registered callback) before executing operations.
 *
 * @retval kStatus_FLASH_Success       Operation processed successfully or queue empty.
 * @retval kStatus_FLASH_Busy          Not enough idle time or operation in progress.
 * @retval kStatus_FLASH_CommandFailure Async context not initialized.
 * @retval Other                       Error from flash operation execution.
 */
status_t FLASH_Process(void)
{
    status_t         status       = kStatus_FLASH_Success;
    uint32_t         opsProcessed = 0U;
    flash_async_op_t op;

    do
    {
        /* Check if async context is initialized */
        if (!s_flashAsyncContext.initialized)
        {
            status = kStatus_FLASH_CommandFailure;
            break;
        }

        /* Process operations while queue is not empty */
        while (!FLASH_QueueIsEmpty())
        {
            uint32_t requiredTime_us = 0U;
            uint32_t availableTime_us = 0U;

            /* Peek at the next operation to determine timing requirements */
            status = FLASH_QueuePeek(&op);
            if (status != kStatus_FLASH_Success)
            {
                /* Queue became empty or error */
                break;
            }

            /* Estimate required time based on operation type */
            switch (op.opType)
            {
                case kFlashAsyncOp_Erase:
                {
                    /* Sector erase typically takes longer */
                    uint32_t numSectors = (op.lengthInBytes + FLASH_FEATURE_SECTOR_SIZE - 1U) / FLASH_FEATURE_SECTOR_SIZE;
                    requiredTime_us = numSectors * CONFIG_FLASH_K4_SECTOR_ERASE_TIME_US;
                    break;
                }

                case kFlashAsyncOp_Program:
                {
                    uint32_t numPhrases = (op.lengthInBytes + FLASH_FEATURE_PHRASE_SIZE - 1U) / FLASH_FEATURE_PHRASE_SIZE;
                    requiredTime_us = numPhrases * CONFIG_FLASH_K4_PHRASE_PROG_TIME_US;
                    break;
                }

                case kFlashAsyncOp_ProgramPage:
                {
                    uint32_t numPages = (op.lengthInBytes + FLASH_FEATURE_PAGE_SIZE - 1U) / FLASH_FEATURE_PAGE_SIZE;
                    requiredTime_us = numPages * CONFIG_FLASH_K4_PAGE_PROG_TIME_US;
                    break;
                }

                case kFlashAsyncOp_VerifyErasePhrase:
                case kFlashAsyncOp_VerifyEraseIFRPhrase:
                {
                    uint32_t numPhrases = (op.lengthInBytes + FLASH_FEATURE_PHRASE_SIZE - 1U) / FLASH_FEATURE_PHRASE_SIZE;
                    requiredTime_us = numPhrases * CONFIG_FLASH_K4_VERIFY_TIME_US;
                    break;
                }

                case kFlashAsyncOp_VerifyErasePage:
                case kFlashAsyncOp_VerifyEraseIFRPage:
                {
                    uint32_t numPages = (op.lengthInBytes + FLASH_FEATURE_PAGE_SIZE - 1U) / FLASH_FEATURE_PAGE_SIZE;
                    requiredTime_us = numPages * CONFIG_FLASH_K4_VERIFY_TIME_US;
                    break;
                }

                case kFlashAsyncOp_VerifyEraseSector:
                case kFlashAsyncOp_VerifyEraseIFRSector:
                {
                    uint32_t numSectors = (op.lengthInBytes + FLASH_FEATURE_SECTOR_SIZE - 1U) / FLASH_FEATURE_SECTOR_SIZE;
                    requiredTime_us = numSectors * CONFIG_FLASH_K4_VERIFY_TIME_US;
                    break;
                }

                case kFlashAsyncOp_VerifyEraseAll:
                case kFlashAsyncOp_VerifyEraseBlock:
                {
                    requiredTime_us = CONFIG_FLASH_K4_VERIFY_BLOCK_TIME_US;
                    break;
                }

                case kFlashAsyncOp_ReadIntoMISR:
                case kFlashAsyncOp_ReadIFRIntoMISR:
                {
                    requiredTime_us = CONFIG_FLASH_K4_MISR_TIME_US;
                    break;
                }

                default:
                    requiredTime_us = CONFIG_FLASH_K4_DEFAULT_OP_TIME_US;
                    break;
            }

            /* Check available idle time if callback is registered */
            if (s_flashAsyncContext.idleDurationCb != NULL)
            {
                availableTime_us = s_flashAsyncContext.idleDurationCb();

                /* Check if we have enough time for this operation */
                if (availableTime_us < requiredTime_us)
                {
#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
                    s_flashAsyncContext.totalDeferredDueToIdle++;
#endif
                    /* Not enough time - defer operation */
                    status = kStatus_Busy;
                    break;
                }
            }

            /* Remove the operation from the queue */
            status = FLASH_QueueGet(&op);
            if (status != kStatus_FLASH_Success)
            {
                break;
            }

            /* Execute the operation */
            status = FLASH_ExecuteOperation(&op);

            /* Free buffer if this was a program operation */
            if ((op.opType == kFlashAsyncOp_Program) || (op.opType == kFlashAsyncOp_ProgramPage))
            {
                FLASH_BufferPoolFree(op.bufferOffset, op.bufferSize);
            }
            
#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            s_flashAsyncContext.totalOperationsProcessed++;
#endif

            opsProcessed++;

            /* If operation failed, stop processing */
            if (status != kStatus_FLASH_Success)
            {
                break;
            }

            /* Limit operations per call to avoid starving other tasks or if erase operation */
            if (opsProcessed >= CONFIG_FLASH_K4_ASYNC_MAX_OPS_PER_PROCESS)
            {
                break;
            }
        }

    } while (false);

    return status;
}

/*!
 * @brief Flush pending operations to make room for a new operation.
 *
 * This function processes pending operations until there is enough space
 * in both the queue (at least 1 slot) and the buffer pool for the specified
 * operation size. Useful before queuing new operations when resources might
 * be exhausted, or before entering low power mode.
 *
 * @param requiredSize Size in bytes required in the buffer pool for the next operation.
 *                     Set to 0 to flush all pending operations.
 *
 * @retval kStatus_FLASH_Success Required space available or all operations flushed.
 * @retval kStatus_FLASH_CommandFailure Async context not initialized.
 * @retval kStatus_FLASH_SizeError Required size exceeds total buffer pool capacity.
 * @retval Other                 Error from flash operation execution.
 */
status_t FLASH_FlushPendingOperations(uint32_t requiredSize)
{
    status_t         status = kStatus_FLASH_Success;
    flash_async_op_t op;

    do
    {
        /* Check if async context is initialized */
        if (!s_flashAsyncContext.initialized)
        {
            status = kStatus_FLASH_CommandFailure;
            break;
        }

        /* If requiredSize exceeds total buffer capacity, return error */
        if (requiredSize > CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
        {
            status = kStatus_FLASH_SizeError;
            break;
        }
            
        /* Process operations until we have enough resources (0 means flush all) */
        while (!FLASH_QueueIsEmpty())
        {
            /* Check if we have enough resources for the new operation */
            if (requiredSize != 0U)
            {
                bool hasQueueSlot    = !FLASH_QueueIsFull();
                bool hasBufferSpace  = (FLASH_BufferPoolAvailable() >= requiredSize);

                if (hasQueueSlot && hasBufferSpace)
                {
                    /* Enough resources available */
                    break;
                }
            }

            /* Get the operation from the queue */
            status = FLASH_QueueGet(&op);
            if (status != kStatus_FLASH_Success)
            {
                break;
            }

            /* Execute the operation */
            status = FLASH_ExecuteOperation(&op);

            /* Free buffer if this was a program operation */
            if ((op.opType == kFlashAsyncOp_Program) || (op.opType == kFlashAsyncOp_ProgramPage))
            {
                FLASH_BufferPoolFree(op.bufferOffset, op.bufferSize);
            }

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            s_flashAsyncContext.totalOperationsProcessed++;
#endif

            /* If operation failed, stop processing */
            if (status != kStatus_FLASH_Success)
            {
                break;
            }
        }

    } while (false);

    return status;
}


static status_t FLASH_AsyncContextInit(flash_config_t *config)
{
    status_t     status = kStatus_FLASH_Success;
    osa_status_t osaStatus;

    do
    {
        if (config == NULL)
        {
            status = kStatus_FLASH_InvalidArgument;
            break;
        }

        if (s_flashAsyncContext.initialized)
        {
            s_flashAsyncContext.flashConfig = config;
            break;
        }

        /* Clear the entire context structure */
        (void)memset(&s_flashAsyncContext, 0, sizeof(flash_async_context_t));

        /* Store flash configuration reference */
        s_flashAsyncContext.flashConfig = config;
        s_flashAsyncContext.fmuBase     = FLASH;

        s_flashAsyncContext.mutexHandle = (osa_mutex_handle_t)s_flashAsyncContext.mutexBuffer;

        /* Initialize the mutex for thread-safe access */
        osaStatus = OSA_MutexCreate(s_flashAsyncContext.mutexHandle);
        if (osaStatus != KOSA_StatusSuccess)
        {
            status = kStatus_Fail;
            break;
        }

        /* Initialize the custom ring buffer queue */
        FLASH_QueueInit();

        /* Initialize circular buffer pool */
        FLASH_BufferPoolInit();

        /* Callback must be registered by application */
        s_flashAsyncContext.idleDurationCb = NULL;

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
        s_flashAsyncContext.totalOperationsQueued    = 0U;
        s_flashAsyncContext.totalOperationsProcessed = 0U;
        s_flashAsyncContext.totalMergedOperations    = 0U;
        s_flashAsyncContext.totalDeferredDueToIdle   = 0U;
        s_flashAsyncContext.peakBufferUsage          = 0U;
        s_flashAsyncContext.peakOperationsQueued     = 0U;
#endif

        s_flashAsyncContext.initialized = true;

    } while (false);

    return status;
}

status_t FLASH_AsyncDeinit(void)
{
    status_t status = kStatus_FLASH_Success;

    do
    {
        /* Check if context is initialized */
        if (!s_flashAsyncContext.initialized)
        {
            status = kStatus_FLASH_CommandFailure;
            break;
        }

        /* Flush all pending operations before deinit */
        status = FLASH_FlushPendingOperations(0U);
        if (status != kStatus_FLASH_Success)
        {
            break;
        }

        /* Clear the context */
        s_flashAsyncContext.initialized    = false;
        s_flashAsyncContext.idleDurationCb = NULL;
        s_flashAsyncContext.flashConfig    = NULL;
        s_flashAsyncContext.fmuBase        = NULL;

        /* Reset queue */
        FLASH_QueueInit();

        /* Reset buffer pool */
        (void)memset(&s_flashAsyncContext.bufferPool, 0, sizeof(flash_circular_buffer_pool_t));

        /* Destroy the mutex */
        (void)OSA_MutexDestroy(s_flashAsyncContext.mutexHandle);
    } while (false);

    return status;
}

/*!
 * @brief Get available contiguous space in circular buffer.
 *
 * @return Available bytes for next allocation.
 */
static uint32_t FLASH_BufferPoolAvailable(void)
{
    uint32_t available;

    if (s_flashAsyncContext.bufferPool.usedBytes == 0U)
    {
        /* Buffer is empty - full size available */
        available = CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE;
    }
    else if (s_flashAsyncContext.bufferPool.usedBytes >= CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
    {
        /* Buffer is full - no space available */
        available = 0U;
    }
    else if (s_flashAsyncContext.bufferPool.tail >= s_flashAsyncContext.bufferPool.head)
    {
        /* Tail is after head: space at end + space at beginning */
        uint32_t spaceAtEnd = CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE - s_flashAsyncContext.bufferPool.tail;
        uint32_t spaceAtBegin = s_flashAsyncContext.bufferPool.head;

        /* Return larger contiguous block */
        available = (spaceAtEnd >= spaceAtBegin) ? spaceAtEnd : spaceAtBegin;
    }
    else
    {
        /* Tail is before head: contiguous space between them */
        available = s_flashAsyncContext.bufferPool.head - s_flashAsyncContext.bufferPool.tail;
    }

    return available;
}

/*!
 * @brief Allocate memory from the circular buffer pool.
 *
 * @param size      Number of bytes to allocate.
 * @param pOffset   Pointer to store the allocation offset.
 * @param pAllocSize Pointer to store actual allocated size (aligned).
 *
 * @return Pointer to allocated memory, or NULL if insufficient space.
 */
static uint8_t *FLASH_BufferPoolAlloc(uint32_t size, uint32_t *pOffset, uint32_t *pAllocSize)
{
    uint8_t     *pBuffer = NULL;
    osa_status_t osaStatus;
    uint32_t     alignedSize;
    uint32_t     allocOffset;

    do
    {
        /* Validate parameters, 0 size is allowed */
        if ((pOffset == NULL) || (pAllocSize == NULL))
        {
            break;
        }

        /* Initialize output parameters */
        *pOffset = FLASH_ASYNC_INVALID_BUFFER_OFFSET;
        *pAllocSize = 0U;

        /* Align size for proper memory alignment */
        alignedSize = FLASH_ALIGN_UP(size, FLASH_BUFFER_ALIGNMENT);

        /* Check if request exceeds total buffer size */
        if (alignedSize > CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
        {
            break;
        }

        /* Acquire mutex for thread-safe access */
        osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
        assert(osaStatus == KOSA_StatusSuccess);
        (void)osaStatus;

        /* Check if enough total space is available */
        if ((CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE - s_flashAsyncContext.bufferPool.usedBytes) < alignedSize)
        {
            /* Not enough space */
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
            break;
        }

        /* Try to allocate at tail position */
        allocOffset = s_flashAsyncContext.bufferPool.tail;

        if (s_flashAsyncContext.bufferPool.usedBytes == 0U)
        {
            /* Buffer empty - reset pointers and allocate from start */
            s_flashAsyncContext.bufferPool.head = 0U;
            s_flashAsyncContext.bufferPool.tail = 0U;
            allocOffset = 0U;
        }
        else if ((allocOffset + alignedSize) > CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
        {
            /* Not enough space at end - check if we can wrap to beginning */
            if (alignedSize <= s_flashAsyncContext.bufferPool.head)
            {
                /* Wrap to beginning - waste remaining space at end */
                /* Note: This fragmentation is acceptable for FIFO usage pattern */
                allocOffset = 0U;
                uint32_t wastedAtEnd = CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE - s_flashAsyncContext.bufferPool.tail;
                s_flashAsyncContext.bufferPool.usedBytes += wastedAtEnd;
            }
            else
            {
                /* Not enough contiguous space */
                (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
                break;
            }
        }

        /* Perform allocation */
        pBuffer = &s_flashAsyncContext.bufferPool.buffer[allocOffset];
        
        /* Update tail pointer */
        s_flashAsyncContext.bufferPool.tail = allocOffset + alignedSize;
        if (s_flashAsyncContext.bufferPool.tail >= CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
        {
            s_flashAsyncContext.bufferPool.tail = 0U;
        }

        /* Update used bytes */
        s_flashAsyncContext.bufferPool.usedBytes += alignedSize;

        /* Return allocation info */
        *pOffset = allocOffset;
        *pAllocSize = alignedSize;

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
        if (s_flashAsyncContext.bufferPool.usedBytes > s_flashAsyncContext.peakBufferUsage)
        {
            s_flashAsyncContext.peakBufferUsage = s_flashAsyncContext.bufferPool.usedBytes;
        }
#endif

        /* Release mutex */
        (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
    } while (false);

    return pBuffer;
}

/*!
 * @brief Free memory back to the circular buffer pool.
 *
 * @note Buffers MUST be freed in FIFO order (same order as allocated).
 *       This is guaranteed by the operation queue processing order.
 *
 * @param offset    The buffer offset returned by FLASH_BufferPoolAlloc.
 * @param allocSize The allocated size returned by FLASH_BufferPoolAlloc.
 */
static void FLASH_BufferPoolFree(uint32_t offset, uint32_t allocSize)
{
    osa_status_t osaStatus;

    /* Validate parameters */
    assert(offset != FLASH_ASYNC_INVALID_BUFFER_OFFSET);

    /* Acquire mutex for thread-safe access */
    osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
    assert(osaStatus == KOSA_StatusSuccess);
    (void)osaStatus;

    /* Verify this is the head allocation (FIFO order) */
    if (offset == s_flashAsyncContext.bufferPool.head)
    {
        /* Advance head pointer */
        s_flashAsyncContext.bufferPool.head += allocSize;
        if (s_flashAsyncContext.bufferPool.head >= CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
        {
            s_flashAsyncContext.bufferPool.head = 0U;
        }

        /* Decrease used bytes */
        if (s_flashAsyncContext.bufferPool.usedBytes >= allocSize)
        {
            s_flashAsyncContext.bufferPool.usedBytes -= allocSize;
        }
        else
        {
            /* Should not happen - reset to safe state */
            s_flashAsyncContext.bufferPool.usedBytes = 0U;
            assert(0);
        }

        /* If buffer is now empty, reset pointers */
        if (s_flashAsyncContext.bufferPool.usedBytes == 0U)
        {
            s_flashAsyncContext.bufferPool.head = 0U;
            s_flashAsyncContext.bufferPool.tail = 0U;
        }
    }
    else
    {
        /* Out-of-order free detected - this should not happen with FIFO queue */
        /* Log error or assert in debug builds */
#if defined(DEBUG) || defined(_DEBUG)
        /* Assert or log error */
        assert(0);
#endif
    }

    /* Release mutex */
    (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
}

/*!
 * @brief Initialize the circular buffer pool.
 */
static void FLASH_BufferPoolInit(void)
{
    s_flashAsyncContext.bufferPool.head = 0U;
    s_flashAsyncContext.bufferPool.tail = 0U;
    s_flashAsyncContext.bufferPool.usedBytes = 0U;
    /* No need to clear buffer contents */
}

/*!
 * @brief Queue a flash operation for deferred execution.
 *
 * This function adds a flash operation (erase or program) to the pending
 * operations queue. The operation will be executed later by FLASH_Process()
 * when sufficient idle time is available.
 *
 * @param pOp Pointer to the operation descriptor to queue.
 *
 * @retval kStatus_FLASH_Success Operation queued successfully.
 */
static status_t FLASH_QueueOperation(flash_async_op_t *pOp)
{
    status_t     status = kStatus_FLASH_Success;
    osa_status_t osaStatus;

    do
    {
        /* Validate input parameter */
        if (pOp == NULL)
        {
            status = kStatus_FLASH_InvalidArgument;
            break;
        }

        /* Acquire mutex for thread-safe queue access */
        osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
        assert(osaStatus == KOSA_StatusSuccess);
        (void)osaStatus;

        /* Check if queue is full */
        if (FLASH_QueueIsFull())
        {
            status = kStatus_Busy;
        }
        else
        {
            /* Copy operation to queue at tail position */
            (void)memcpy(&s_flashAsyncContext.opQueue.ops[s_flashAsyncContext.opQueue.tail],
                         pOp,
                         sizeof(flash_async_op_t));

            /* Advance tail with wrap-around */
            s_flashAsyncContext.opQueue.tail = (s_flashAsyncContext.opQueue.tail + 1U) % CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE;
            s_flashAsyncContext.opQueue.count++;
#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            s_flashAsyncContext.totalOperationsQueued++;
            if (s_flashAsyncContext.opQueue.count > s_flashAsyncContext.peakOperationsQueued)
            {
                s_flashAsyncContext.peakOperationsQueued = s_flashAsyncContext.opQueue.count;
            }
#endif

            status = kStatus_FLASH_Success;
        }

        /* Release mutex */
        (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);

    } while (false);

    return status;
}


/*!
 * @brief Peek at the first operation in the queue without removing it.
 *
 * This function retrieves a copy of the first pending operation without
 * removing it from the queue. Useful for checking timing requirements
 * before deciding to process the operation.
 *
 * @param pOp Pointer to store the operation descriptor.
 *
 * @retval kStatus_FLASH_Success Operation retrieved successfully.
 */
static status_t FLASH_QueuePeek(flash_async_op_t *pOp)
{
    status_t     status = kStatus_FLASH_Success;
    osa_status_t osaStatus;

    do
    {
        /* Validate input parameter */
        if (pOp == NULL)
        {
            status = kStatus_FLASH_InvalidArgument;
            break;
        }

        /* Acquire mutex for thread-safe queue access */
        osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
        assert(osaStatus == KOSA_StatusSuccess);
        (void)osaStatus;

        /* Check if queue is empty */
        if (FLASH_QueueIsEmpty())
        {
            status = kStatus_Busy;
        }
        else
        {
            /* Copy operation from head position (do NOT modify head/count) */
            (void)memcpy(pOp,
                         &s_flashAsyncContext.opQueue.ops[s_flashAsyncContext.opQueue.head],
                         sizeof(flash_async_op_t));

            status = kStatus_FLASH_Success;
        }

        /* Release mutex */
        (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);

    } while (false);

    return status;
}

/*!
 * @brief Get and remove the first operation from the queue.
 *
 * This function retrieves and removes the first pending operation from
 * the queue. The caller is responsible for processing the operation
 * and freeing any associated buffer.
 *
 * @param pOp Pointer to store the operation descriptor.
 *
 * @retval kStatus_FLASH_Success Operation retrieved successfully.
 */
static status_t FLASH_QueueGet(flash_async_op_t *pOp)
{
    status_t     status = kStatus_FLASH_Success;
    osa_status_t osaStatus;

    do
    {
        /* Validate input parameter */
        if (pOp == NULL)
        {
            status = kStatus_FLASH_InvalidArgument;
            break;
        }

        /* Acquire mutex for thread-safe queue access */
        osaStatus = OSA_MutexLock((osa_mutex_handle_t)s_flashAsyncContext.mutexHandle, osaWaitForever_c);
        assert(osaStatus == KOSA_StatusSuccess);
        (void)osaStatus;

        /* Check if queue is empty */
        if (FLASH_QueueIsEmpty())
        {
            status = kStatus_Busy;
        }
        else
        {
            /* Copy operation from head position */
            (void)memcpy(pOp,
                         &s_flashAsyncContext.opQueue.ops[s_flashAsyncContext.opQueue.head],
                         sizeof(flash_async_op_t));

            /* Advance head with wrap-around */
            s_flashAsyncContext.opQueue.head = (s_flashAsyncContext.opQueue.head + 1U) % CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE;
            s_flashAsyncContext.opQueue.count--;

            status = kStatus_FLASH_Success;
        }

        /* Release mutex */
        (void)OSA_MutexUnlock((osa_mutex_handle_t)s_flashAsyncContext.mutexHandle);

    } while (false);

    return status;
}

/*!
 * @brief Get the number of pending operations in the queue.
 *
 * @return Number of pending operations in the queue.
 */
FLASH_STATIC uint32_t FLASH_QueueCount(void)
{
    uint32_t     count = 0U;

    if (s_flashAsyncContext.initialized)
    {
        count = s_flashAsyncContext.opQueue.count;
    }
    return count;
}

/*!
 * @brief Read from flash with pending operation awareness.
 *
 * This function reads data from flash and applies any pending write or erase
 * operations to ensure the caller gets the most up-to-date view of the data.
 *
 * @param address Start address to read from.
 * @param pDst    Pointer to destination buffer.
 * @param length  Number of bytes to read.
 *
 * @retval kStatus_FLASH_Success Read completed successfully.
 * @retval kStatus_FLASH_InvalidArgument Invalid parameters.
 */
status_t FLASH_ReadWithPendingOps(uint32_t address, uint8_t *pDst, uint32_t length)
{
    status_t status = kStatus_FLASH_Success;

    do
    {
        /* Validate parameters */
        if ((pDst == NULL) || (length == 0U))
        {
            status = kStatus_FLASH_InvalidArgument;
            break;
        }

        /* First, read actual flash content */
        (void)memcpy(pDst, (const void *)(uintptr_t)address, length);

        /* Then apply any pending operations */
        if (s_flashAsyncContext.initialized)
        {
            FLASH_ApplyPendingOpsToReadBuffer(address, pDst, length);
        }

    } while (false);

    return status;
}

status_t FLASH_RegisterIdleDurationCB(flash_idle_duration_cb_t callback)
{
    status_t status = kStatus_FLASH_Success;

    if (!s_flashAsyncContext.initialized)
    {
        status = kStatus_FLASH_CommandFailure;
    }
    else if (callback == NULL)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        s_flashAsyncContext.idleDurationCb = callback;
    }

    return status;
}

static status_t FLASH_ExecuteOperation(flash_async_op_t *pOp)
{
    status_t status = kStatus_FLASH_Success;
    uint32_t regPrimask;

    if (pOp == NULL)
    {
        status = kStatus_FLASH_InvalidArgument;
    }
    else
    {
        switch (pOp->opType)
        {
            case kFlashAsyncOp_Erase:
            {
                regPrimask = DisableGlobalIRQ();
                status = flash_erase_sector_impl(s_flashAsyncContext.fmuBase, pOp->startAddress, pOp->lengthInBytes);
                EnableGlobalIRQ(regPrimask);
                break;
            }

            case kFlashAsyncOp_Program:
            {
                regPrimask = DisableGlobalIRQ();
                status = flash_program_phrase_impl(s_flashAsyncContext.fmuBase, pOp->startAddress, pOp->pBuffer, pOp->lengthInBytes);
                EnableGlobalIRQ(regPrimask);
                break;
            }

            case kFlashAsyncOp_ProgramPage:
            {
                regPrimask = DisableGlobalIRQ();
                status = flash_program_page_impl(s_flashAsyncContext.fmuBase, pOp->startAddress, pOp->pBuffer, pOp->lengthInBytes);
                EnableGlobalIRQ(regPrimask);
                break;
            }

            case kFlashAsyncOp_ReadIntoMISR:
            {
                uint32_t startaddr = pOp->startAddress;
                uint32_t endAddr = startaddr + pOp->lengthInBytes;
                uint32_t regPrimask = DisableGlobalIRQ();

                status = FLASH_CMD_ReadIntoMISR(s_flashAsyncContext.fmuBase, 
                                                startaddr, 
                                                endAddr, 
                                                pOp->pSeed, 
                                                pOp->pSignature);
                EnableGlobalIRQ(regPrimask);
                break;
            }

            case kFlashAsyncOp_ReadIFRIntoMISR:
            {
                uint32_t startaddr = pOp->startAddress;
                uint32_t endAddr = startaddr + pOp->lengthInBytes;
                uint32_t regPrimask = DisableGlobalIRQ();

                status = FLASH_CMD_ReadIFRIntoMISR(s_flashAsyncContext.fmuBase, 
                                                   startaddr, 
                                                   endAddr, 
                                                   pOp->pSeed, 
                                                   pOp->pSignature);
                EnableGlobalIRQ(regPrimask);
                break;
            }


            default:
                status = kStatus_FLASH_InvalidArgument;
                break;
        }

#if defined(SMSCM) || defined(SYSCON_FMC0_CTRL_DFC_MASK)
        /* Invalidate cache after flash operations */
        if ((pOp->opType == kFlashAsyncOp_Erase) || 
            (pOp->opType == kFlashAsyncOp_Program) || 
            (pOp->opType == kFlashAsyncOp_ProgramPage))
        {
            flash_cache_invalidate();
        }
#endif
    }

    return status;
}

/*!
 * @brief Apply pending write operations to a read buffer.
 *
 * This function ensures read-after-write consistency by applying any pending
 * write operations that overlap with the read address range. This creates
 * a "read-through" behavior similar to a write-back cache.
 *
 * Must be called when reading from flash to get the most up-to-date data,
 * including data that has been queued for writing but not yet committed.
 *
 * @param readAddr Start address of the read operation.
 * @param pDst     Pointer to destination buffer containing flash data.
 * @param length   Length of the read in bytes.
 */
static void FLASH_ApplyPendingOpsToReadBuffer(uint32_t readAddr, uint8_t *pDst, uint32_t length)
{
    osa_status_t osaStatus;
    uint32_t     i;
    uint32_t     idx;
    uint32_t     readEnd;

    /* Validate parameters */
    if ((pDst == NULL) || (length == 0U))
    {
        /* Do nothing - invalid parameters */
    }
    else
    {
        /* Calculate read end address */
        readEnd = readAddr + length;
        /* If queue is empty, nothing to apply */
        if (!FLASH_QueueIsEmpty())
        {
            /* Acquire mutex for thread-safe queue access */
            osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
            assert(osaStatus == KOSA_StatusSuccess);
            (void)osaStatus;

            /* Iterate through all pending operations in queue order (head to tail) */
            idx = s_flashAsyncContext.opQueue.head;
            for (i = 0U; i < s_flashAsyncContext.opQueue.count; i++)
            {
                flash_async_op_t *pOp = &s_flashAsyncContext.opQueue.ops[idx];

                /* Only process program operations */
                if ((pOp->opType == kFlashAsyncOp_Program) || (pOp->opType == kFlashAsyncOp_ProgramPage))
                {
                    /* Check if operation has valid buffer */
                    if ((pOp->pBuffer != NULL) && (pOp->lengthInBytes > 0U))
                    {
                        uint32_t opStart = pOp->startAddress;
                        uint32_t opEnd   = opStart + pOp->lengthInBytes;

                        /* Check if this operation overlaps with the read range */
                        if (FLASH_REGIONS_OVERLAP(readAddr, length, opStart, pOp->lengthInBytes))
                        {
                            uint32_t overlapStart;
                            uint32_t overlapEnd;
                            uint32_t overlapLen;
                            uint32_t srcOffset;
                            uint32_t dstOffset;

                            /* Calculate overlap region */
                            overlapStart = (readAddr > opStart) ? readAddr : opStart;
                            overlapEnd   = (readEnd < opEnd) ? readEnd : opEnd;
                            overlapLen   = overlapEnd - overlapStart;

                            /* Calculate offsets into source (pending write) and destination (read) buffers */
                            srcOffset = overlapStart - opStart;
                            dstOffset = overlapStart - readAddr;

                            /* Apply pending write data to read buffer */
                            (void)memcpy(&pDst[dstOffset], &pOp->pBuffer[srcOffset], overlapLen);
                        }
                    }
                }
                else if (pOp->opType == kFlashAsyncOp_Erase)
                {
                    /* For erase operations, fill overlapping region with 0xFF */
                    uint32_t opStart = pOp->startAddress;
                    uint32_t opEnd   = opStart + pOp->lengthInBytes;

                    /* Check if this erase overlaps with the read range */
                    if (FLASH_REGIONS_OVERLAP(readAddr, length, opStart, pOp->lengthInBytes))
                    {
                        uint32_t overlapStart;
                        uint32_t overlapEnd;
                        uint32_t overlapLen;
                        uint32_t dstOffset;

                        /* Calculate overlap region */
                        overlapStart = (readAddr > opStart) ? readAddr : opStart;
                        overlapEnd   = (readEnd < opEnd) ? readEnd : opEnd;
                        overlapLen   = overlapEnd - overlapStart;

                        /* Calculate offset into destination buffer */
                        dstOffset = overlapStart - readAddr;

                        /* Fill with erased value (0xFF) */
                        (void)memset(&pDst[dstOffset], 0xFF, overlapLen);
                    }
                }
                else
                {
                    /* Other operation types don't affect read data */
                    ; /* MISRA */
                }

                /* Move to next operation in queue (circular) */
                idx = (idx + 1U) % CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE;
            }
            /* Release mutex */
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
        }
    }
}

/*!
 * @brief Check if there are pending operations affecting a given address range.
 *
 * @param startAddr Start address of the range to check.
 * @param length    Length of the range in bytes.
 * @param pHasPendingErase   Output: true if there's a pending erase covering this range.
 * @param pHasPendingProgram Output: true if there's a pending program in this range.
 *
 * @retval kStatus_FLASH_Success Check completed.
 * @retval kStatus_Fail          Mutex error.
 */
static status_t FLASH_CheckPendingOpsOnRange(uint32_t startAddr,
                                              uint32_t length,
                                              bool *pHasPendingErase,
                                              bool *pHasPendingProgram)
{
    status_t     status = kStatus_FLASH_Success;
    osa_status_t osaStatus;
    uint32_t     i;
    uint32_t     idx;
    uint32_t     rangeEnd;
    bool         hasPendingProgram = false;
    bool         eraseCoversRange  = false;

    do
    {
        if ((pHasPendingErase == NULL) || (pHasPendingProgram == NULL))
        {
            status = kStatus_FLASH_InvalidArgument;
            break;
        }

        *pHasPendingErase   = false;
        *pHasPendingProgram = false;

        if (!s_flashAsyncContext.initialized)
        {
            break; /* No async context, no pending ops */
        }

        rangeEnd = startAddr + length;

        if (FLASH_QueueIsEmpty())
        {
            break;
        }

        /* Acquire mutex for thread-safe queue access */
        osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
        assert(osaStatus == KOSA_StatusSuccess);
        (void)osaStatus;

        /* Iterate through all pending operations in queue order */
        idx = s_flashAsyncContext.opQueue.head;
        for (i = 0U; i < s_flashAsyncContext.opQueue.count; i++)
        {
            flash_async_op_t *pOp = &s_flashAsyncContext.opQueue.ops[idx];
            uint32_t opStart = pOp->startAddress;
            uint32_t opEnd   = opStart + pOp->lengthInBytes;

            if (pOp->opType == kFlashAsyncOp_Erase)
            {
                /* Check if erase fully covers the verification range */
                if ((opStart <= startAddr) && (opEnd >= rangeEnd))
                {
                    eraseCoversRange = true;
                    hasPendingProgram = false;
                }
            }
            else if ((pOp->opType == kFlashAsyncOp_Program) || (pOp->opType == kFlashAsyncOp_ProgramPage))
            {
                /* Check if program operation overlaps with the range */
                if (FLASH_REGIONS_OVERLAP(startAddr, length, opStart, pOp->lengthInBytes))
                {
                    hasPendingProgram = true;
                }
            }
            else
            {
                ; /* Other operations don't affect erase verification */
            }

            idx = (idx + 1U) % CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE;
        }

        /* Release mutex */
        (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);

        /* Report results - only report erase if it fully covers the range */
        *pHasPendingErase   = eraseCoversRange;
        *pHasPendingProgram = hasPendingProgram;

    } while (false);

    return status;
}

#if defined(CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES) && (CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES == 1)
/*!
 * @brief Try to merge a write operation with the last queued write.
 *
 * This function attempts to merge a new write operation with the last
 * operation in the queue if they are contiguous and there is room in
 * the buffer. This optimization reduces the number of flash transactions.
 *
 * @param start        Start address of the new write.
 * @param src          Pointer to source data.
 * @param length       Length of data to write.
 * @param pBufferIndex Pointer to store buffer index (unchanged if merged).
 *
 * @retval true  Write was merged with existing operation.
 * @retval false Merge not possible, caller should queue new operation.
 */
static bool FLASH_TryMergeWrite(uint32_t start, uint8_t *src, uint32_t length)
{
    bool         merged = false;
    osa_status_t osaStatus;

    do
    {
        flash_async_op_t *pLastOp;
        uint32_t          lastOpEnd;
        uint32_t          newTotalLength;
        uint32_t          tailIdx;
        uint32_t          alignedExtension;
        uint32_t          currentAllocEnd;

        /* Validate parameters */
        if ((src == NULL) || (length == 0U))
        {
            break;
        }

        /* Check if queue has any operations */
        if (FLASH_QueueIsEmpty())
        {
            break;
        }

        /* Acquire mutex for thread-safe queue access */
        osaStatus = OSA_MutexLock(s_flashAsyncContext.mutexHandle, osaWaitForever_c);
        assert(osaStatus == KOSA_StatusSuccess);
        (void)osaStatus;

        /* Get pointer to the last operation in queue (at tail - 1) */
        if (s_flashAsyncContext.opQueue.tail == 0U)
        {
            tailIdx = CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE - 1U;
        }
        else
        {
            tailIdx = s_flashAsyncContext.opQueue.tail - 1U;
        }
        pLastOp = &s_flashAsyncContext.opQueue.ops[tailIdx];

        /* Check if last operation is a program operation */
        if ((pLastOp->opType != kFlashAsyncOp_Program) && (pLastOp->opType != kFlashAsyncOp_ProgramPage))
        {
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
            break;
        }

        /* Check if buffer is valid */
        if ((pLastOp->pBuffer == NULL) || (pLastOp->bufferOffset == FLASH_ASYNC_INVALID_BUFFER_OFFSET))
        {
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
            break;
        }

        /* Calculate end address of last operation */
        lastOpEnd = pLastOp->startAddress + pLastOp->lengthInBytes;

        /* Check if new write is contiguous with last operation */
        if (start != lastOpEnd)
        {
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
            break;
        }

        /* Calculate total length after merge */
        newTotalLength = pLastOp->lengthInBytes + length;

        /* Calculate aligned extension needed */
        alignedExtension = FLASH_ALIGN_UP(newTotalLength, FLASH_BUFFER_ALIGNMENT) - pLastOp->bufferSize;

        /* Check if the last allocation is at the current buffer tail position */
        /* This ensures we can extend it without affecting other allocations */
        currentAllocEnd = pLastOp->bufferOffset + pLastOp->bufferSize;
        if (currentAllocEnd >= CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
        {
            currentAllocEnd = 0U;
        }

        if (currentAllocEnd != s_flashAsyncContext.bufferPool.tail)
        {
            /* Last allocation is not at tail - cannot extend (another allocation happened) */
            (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
            break;
        }

        /* Check if extension is needed */
        if (alignedExtension > 0U)
        {
            uint32_t availableAtTail;

            /* Calculate available space at current tail position */
            if (s_flashAsyncContext.bufferPool.tail >= s_flashAsyncContext.bufferPool.head)
            {
                /* Tail is after head */
                if (s_flashAsyncContext.bufferPool.usedBytes == 0U)
                {
                    availableAtTail = CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE - s_flashAsyncContext.bufferPool.tail;
                }
                else
                {
                    availableAtTail = CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE - s_flashAsyncContext.bufferPool.tail;
                }
            }
            else
            {
                /* Tail wrapped around - space between tail and head */
                availableAtTail = s_flashAsyncContext.bufferPool.head - s_flashAsyncContext.bufferPool.tail;
            }

            /* Check if we have enough contiguous space to extend */
            if (alignedExtension > availableAtTail)
            {
                /* Not enough contiguous space to extend */
                (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
                break;
            }

            /* Check total buffer capacity */
            if ((s_flashAsyncContext.bufferPool.usedBytes + alignedExtension) > CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
            {
                (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);
                break;
            }

            /* Extend the allocation */
            s_flashAsyncContext.bufferPool.tail += alignedExtension;
            if (s_flashAsyncContext.bufferPool.tail >= CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE)
            {
                /* This shouldn't happen if we checked correctly, but handle wrap */
                s_flashAsyncContext.bufferPool.tail -= CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE;
            }
            s_flashAsyncContext.bufferPool.usedBytes += alignedExtension;

            /* Update operation's buffer size */
            pLastOp->bufferSize += alignedExtension;

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
            if (s_flashAsyncContext.bufferPool.usedBytes > s_flashAsyncContext.peakBufferUsage)
            {
                s_flashAsyncContext.peakBufferUsage = s_flashAsyncContext.bufferPool.usedBytes;
            }
#endif
        }

        /* Append new data to existing buffer */
        (void)memcpy(&pLastOp->pBuffer[pLastOp->lengthInBytes], src, length);

        /* Update operation length */
        pLastOp->lengthInBytes = newTotalLength;

        merged = true;

#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
        s_flashAsyncContext.totalMergedOperations++;
#endif

        /* Release mutex */
        (void)OSA_MutexUnlock(s_flashAsyncContext.mutexHandle);

    } while (false);

    return merged;
}
#endif /* CONFIG_FLASH_K4_ASYNC_MERGE_CONTIGUOUS_WRITES */

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */
