/*
 * Copyright 2018-2021,2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FSL_K4_FLASH_H_
#define FSL_K4_FLASH_H_

#include "fsl_k4_controller.h"
#include <stdio.h>
/*!
 * @addtogroup flash_driver
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name Flash version
 * @{
 */
/*! @brief Flash driver version for SDK*/
#define FSL_FLASH_DRIVER_VERSION (MAKE_VERSION(2, 4, 1)) /*!< Version 2.4.1. */

/*! @} */

/*! @brief Flash driver version for ROM*/
enum _flash_driver_version_constants
{
    kFLASH_DriverVersionName   = 'F', /*!< Flash driver version name.*/
    kFLASH_DriverVersionMajor  = 2,   /*!< Major flash driver version.*/
    kFLASH_DriverVersionMinor  = 4,   /*!< Minor flash driver version.*/
    kFLASH_DriverVersionBugfix = 1    /*!< Bugfix for flash driver version.*/
};

/*!
 * @brief Enumeration for various flash properties.
 */
typedef enum _flash_property_tag
{
    kFLASH_PropertyPflash0SectorSize         = 0x00U, /*!< Pflash sector size property.*/
    kFLASH_PropertyPflash0TotalSize          = 0x01U, /*!< Pflash total size property.*/
    kFLASH_PropertyPflash0BlockSize          = 0x02U, /*!< Pflash block size property.*/
    kFLASH_PropertyPflash0BlockCount         = 0x03U, /*!< Pflash block count property.*/
    kFLASH_PropertyPflash0BlockBaseAddr      = 0x04U, /*!< Pflash block base address property.*/
    kFLASH_PropertyPflash0FacSupport         = 0x05U, /*!< Pflash fac support property.*/
    kFLASH_PropertyPflash0AccessSegmentSize  = 0x06U, /*!< Pflash access segment size property.*/
    kFLASH_PropertyPflash0AccessSegmentCount = 0x07U, /*!< Pflash access segment count property.*/

    kFLASH_PropertyPflash1SectorSize         = 0x10U, /*!< Pflash sector size property.*/
    kFLASH_PropertyPflash1TotalSize          = 0x11U, /*!< Pflash total size property.*/
    kFLASH_PropertyPflash1BlockSize          = 0x12U, /*!< Pflash block size property.*/
    kFLASH_PropertyPflash1BlockCount         = 0x13U, /*!< Pflash block count property.*/
    kFLASH_PropertyPflash1BlockBaseAddr      = 0x14U, /*!< Pflash block base address property.*/
    kFLASH_PropertyPflash1FacSupport         = 0x15U, /*!< Pflash fac support property.*/
    kFLASH_PropertyPflash1AccessSegmentSize  = 0x16U, /*!< Pflash access segment size property.*/
    kFLASH_PropertyPflash1AccessSegmentCount = 0x17U, /*!< Pflash access segment count property.*/

    kFLASH_PropertyFlexRamBlockBaseAddr = 0x20U, /*!< FlexRam block base address property.*/
    kFLASH_PropertyFlexRamTotalSize     = 0x21U, /*!< FlexRam total size property.*/
} flash_property_tag_t;

#define FLASH_ADDR_MASK 0xEFFFFFFFu

/*!
 * @name Flash API key
 * @{
 */
/*!
 * @brief Enumeration for Flash driver API keys.
 *
 * @note The resulting value is built with a byte order such that the string
 * being readable in expected order when viewed in a hex editor, if the value
 * is treated as a 32-bit little endian value.
 */
enum _flash_driver_api_keys
{
    kFLASH_ApiEraseKey = FOUR_CHAR_CODE('l', 'f', 'e', 'k') /*!< Key value used to validate all flash erase APIs.*/
};
/*! @} */

/*!
 * @brief Flash memory descriptor.
 */
typedef struct _flash_mem_descriptor
{
    uint32_t blockBase;  /*!< Base address of the flash block */
    uint32_t totalSize;  /*!< The size of the flash block. */
    uint32_t blockCount; /*!< A number of flash blocks. */
} flash_mem_desc_t;

typedef struct _flash_ifr_desc
{
    uint32_t pflashIfr0Start;
    uint32_t pflashIfr0MemSize;
} flash_ifr_desc_t;

typedef struct _msf1_config
{
    flash_mem_desc_t flashDesc;
    flash_ifr_desc_t ifrDesc;
} msf1_config_t;

/*! @brief Flash driver state information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * passed into each of the driver APIs.
 */
typedef struct _flash_config
{
    msf1_config_t msf1Config[2];
} flash_config_t;

/*******************************************************************************
 * Async Mode Configuration
 ******************************************************************************/

/*!
 * @name Flash Async Mode Configuration
 * @{
 */

/*!
 * @brief Enable asynchronous flash operation mode.
 *
 * When set to 1, Write and Erase operations are queued and deferred to idle periods.
 * When set to 0 (default), operations execute synchronously (existing behavior).
 */
#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)

#include "fsl_os_abstraction.h"

/*! @brief Alignment for buffer allocations (must be power of 2). */
#ifndef FLASH_BUFFER_ALIGNMENT
#define FLASH_BUFFER_ALIGNMENT          (4U)
#endif

/*! @brief Align a value up to the specified alignment. */
#ifndef FLASH_ALIGN_UP
#define FLASH_ALIGN_UP(val, align)      (((val) + ((align) - 1U)) & ~((align) - 1U))
#endif

/*******************************************************************************
 * Async Mode Types
 ******************************************************************************/

/*!
 * @brief Enumeration for asynchronous flash operation types.
 */
typedef enum _flash_async_op_type
{
    kFlashAsyncOp_Erase = 0U,                /*!< Erase operation */
    kFlashAsyncOp_Program = 1U,              /*!< Program phrase operation */
    kFlashAsyncOp_ProgramPage = 2U,          /*!< Program page operation */
    kFlashAsyncOp_VerifyErasePhrase = 3U,    /*!< Verify erase phrase operation */
    kFlashAsyncOp_VerifyErasePage = 4U,      /*!< Verify erase page operation */
    kFlashAsyncOp_VerifyEraseSector = 5U,    /*!< Verify erase sector operation */
    kFlashAsyncOp_VerifyEraseIFRPhrase = 6U, /*!< Verify erase IFR phrase operation */
    kFlashAsyncOp_VerifyEraseIFRPage = 7U,   /*!< Verify erase IFR page operation */
    kFlashAsyncOp_VerifyEraseIFRSector = 8U, /*!< Verify erase IFR sector operation */
    kFlashAsyncOp_VerifyEraseAll = 9U,       /*!< Verify erase all operation */
    kFlashAsyncOp_VerifyEraseBlock = 10U,     /*!< Verify erase block operation */
    kFlashAsyncOp_ReadIntoMISR = 11U,         /*!< Read into MISR operation */
    kFlashAsyncOp_ReadIFRIntoMISR = 12U,      /*!< Read IFR into MISR operation */
} flash_async_op_type_t;

/*!
 * @brief Flash async operation descriptor.
 */
typedef struct _flash_async_op
{
    uint32_t              opType;          /*!< Type of flash operation */
    uint32_t              startAddress;    /*!< Start address for operation */
    uint32_t              lengthInBytes;   /*!< Length of operation in bytes */
    uint8_t              *pBuffer;         /*!< Pointer to data buffer (for program ops) */
    uint32_t              bufferOffset;    /*!< Offset in circular buffer (replaces bufferPoolIndex) */
    uint32_t              bufferSize;      /*!< Allocated size in circular buffer (aligned) */
    uint32_t              key;             /*!< Erase key (for erase operations) */
    uint32_t             *pSeed;           /*!< Pointer to MISR seed (for MISR operations) */
    uint32_t             *pSignature;      /*!< Pointer to MISR signature (for MISR operations) */
} flash_async_op_t;

/*!
 * @brief Invalid buffer offset marker.
 */
#define FLASH_ASYNC_INVALID_BUFFER_OFFSET    (0xFFFFFFFFU)

/*!
 * @brief Callback function type for getting LL idle duration.
 *
 * This callback is invoked by FLASH_Process() to determine if there is
 * sufficient idle time to execute a pending flash operation.
 *
 * @return Available idle duration in microseconds.
 */
typedef uint32_t (*flash_idle_duration_cb_t)(void);

/*!
 * @brief Flash async operation status enumeration.
 */
typedef enum _flash_async_status
{
    kStatus_FLASH_Async_Success      = 0U,  /*!< Operation completed successfully */
    kStatus_FLASH_Async_Busy         = 1U,  /*!< Queue or buffer pool is full */
    kStatus_FLASH_Async_NotReady     = 2U,  /*!< Insufficient idle time available */
    kStatus_FLASH_Async_QueueEmpty   = 3U,  /*!< No pending operations */
    kStatus_FLASH_Async_NotInit      = 4U,  /*!< Async context not initialized */
    kStatus_FLASH_Async_InvalidParam = 5U,  /*!< Invalid parameter provided */
} flash_async_status_t;

/*!
 * @brief Circular queue for flash operations.
 *
 * Custom implementation to support peek without modifying order.
 */
typedef struct _flash_op_queue
{
    flash_async_op_t ops[CONFIG_FLASH_K4_ASYNC_QUEUE_SIZE]; /*!< Operation storage */
    uint32_t         head;                         /*!< Index of first element */
    uint32_t         tail;                         /*!< Index of next free slot */
    uint32_t         count;                        /*!< Number of elements in queue */
} flash_op_queue_t;

/*!
 * @brief Circular buffer pool structure for write data storage.
 *
 * Uses a single contiguous buffer with head/tail pointers for FIFO allocation.
 * More memory efficient than fixed-size buffer arrays for variable-length data.
 */
typedef struct _flash_circular_buffer_pool
{
    uint8_t  buffer[CONFIG_FLASH_K4_ASYNC_TOTAL_BUFFER_SIZE];  /*!< Single large circular buffer */
    uint32_t head;                                   /*!< Start of used region (free pointer) */
    uint32_t tail;                                   /*!< End of used region (alloc pointer) */
    uint32_t usedBytes;                              /*!< Total bytes currently allocated */
} flash_circular_buffer_pool_t;

/*!
 * @brief Async flash driver context with circular buffer.
 */
typedef struct _flash_async_context
{
    /* Custom circular queue */
    flash_op_queue_t opQueue;                                             /*!< Operation queue */

    /* Mutex handle and storage */
    osa_mutex_handle_t mutexHandle;                                       /*!< Mutex handle */
    uint32_t           mutexBuffer[OSA_MUTEX_HANDLE_SIZE / sizeof(uint32_t)]; /*!< Mutex handle buffer */

    /* Circular buffer pool (replaces fixed buffer array) */
    flash_circular_buffer_pool_t bufferPool;

    /* LL idle callback */
    flash_idle_duration_cb_t idleDurationCb;                           /*!< Callback for idle duration */

    /* Flash configuration reference */
    flash_config_t *flashConfig;                                          /*!< Pointer to flash config */

    /* FMU base address for operations */
    FMU_Type *fmuBase;                                                    /*!< FMU base address */

    /* State flags */
    bool initialized;                                                     /*!< Initialization flag */

    /* Statistics (optional, for debug) */
#if defined(CONFIG_FLASH_K4_ASYNC_ENABLE_STATS) && (CONFIG_FLASH_K4_ASYNC_ENABLE_STATS == 1)
    uint32_t totalOperationsQueued;
    uint32_t totalOperationsProcessed;
    uint32_t totalMergedOperations;
    uint32_t totalDeferredDueToIdle;
    uint32_t peakBufferUsage;           /*!< Peak buffer usage in bytes */
    uint32_t peakOperationsQueued;
#endif

} flash_async_context_t;

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization
 * @{
 */

/*!
 * @brief Initializes the global flash properties structure members.
 *
 * This function checks and initializes the Flash module for the other Flash APIs.
 * When async mode is enabled, this also initializes the async context including
 * the operation queue and buffer pool.
 *
 * @param config Pointer to the storage for the driver runtime state.
 *
 * @retval #kStatus_FLASH_Success API was executed successfully.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_CommandFailure Run-time error during the command execution.
 * @retval #kStatus_FLASH_CommandNotSupported Flash API is not supported.
 */
status_t FLASH_Init(flash_config_t *config);

/*! @} */

/*!
 * @name Erasing
 * @{
 */

/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function.
 *
 * In synchronous mode, this function blocks until the erase completes.
 * In asynchronous mode, this function queues the erase operation and returns
 * immediately. The operation will be executed later by FLASH_Process() when
 * sufficient LL idle time is available.
 *
 * @param config Pointer to the flash driver configuration.
 * @param base FMU peripheral base address.
 * @param start Start address of the region to erase.
 * @param lengthInBytes Size of the region to erase in bytes.
 * @param key Erase API key (kFLASH_ApiEraseKey).
 *
 * @retval #kStatus_FLASH_Success Operation completed or queued successfully.
 * @retval #kStatus_FLASH_InvalidArgument Invalid parameters.
 * @retval #kStatus_FLASH_Busy Queue or resources unavailable (async mode).
 */
status_t FLASH_Erase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t key);

/*!
 * @brief Erases entire flash and ifr
 *
 * @note This function always executes synchronously regardless of async mode setting.
 *
 * @param base FMU peripheral base address.
 * @param key Erase API key.
 *
 * @retval #kStatus_FLASH_Success Operation completed successfully.
 */
status_t FLASH_EraseAll(FMU_Type *base, uint32_t key);

/*! @} */

/*!
 * @name Programming
 * @{
 */

/*!
 * @brief Programs flash phrases with data at locations passed in through parameters.
 *
 * In synchronous mode, this function blocks until programming completes.
 * In asynchronous mode, this function copies the source data to an internal
 * buffer, queues the operation, and returns immediately. The operation will
 * be executed later by FLASH_Process() when sufficient LL idle time is available.
 *
 * @param config Pointer to the flash driver configuration.
 * @param base FMU peripheral base address.
 * @param start Target flash address for programming.
 * @param src Pointer to source data buffer.
 * @param lengthInBytes Number of bytes to program.
 *
 * @retval #kStatus_FLASH_Success Operation completed or queued successfully.
 * @retval #kStatus_FLASH_InvalidArgument Invalid parameters.
 * @retval #kStatus_FLASH_Busy Queue or buffer pool exhausted (async mode).
 */
status_t FLASH_Program(flash_config_t *config, FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes);

/*!
 * @brief Programs flash pages with data at locations passed in through parameters.
 *
 * @note In async mode, this function behaves the same as FLASH_Program().
 *
 * @param config Pointer to the flash driver configuration.
 * @param base FMU peripheral base address.
 * @param start Target flash address for programming.
 * @param src Pointer to source data buffer.
 * @param lengthInBytes Number of bytes to program.
 *
 * @retval #kStatus_FLASH_Success Operation completed or queued successfully.
 */
status_t FLASH_ProgramPage(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes);

/*! @} */

/*!
 * @name Reading
 * @{
 */

/*!
 * @brief Reads data from flash memory.
 *
 * This function always executes synchronously. In async mode, it checks the
 * pending operation queue and applies any queued writes or erases to the
 * returned data to ensure consistency.
 *
 * @param config Pointer to the flash driver configuration.
 * @param start Source flash address to read from.
 * @param dst Pointer to destination buffer.
 * @param lengthInBytes Number of bytes to read.
 *
 * @retval #kStatus_FLASH_Success Read completed successfully.
 * @retval #kStatus_FLASH_InvalidArgument Invalid parameters.
 */
status_t FLASH_Read(uint8_t *dst, uint32_t start, uint32_t lengthInBytes);

/*! @} */

/*!
 * @name Verification
 * @{
 */

/*!
 * @brief Verify that the flash phrases are erased
 */
status_t FLASH_VerifyErasePhrase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*!
 * @brief Verify that the flash pages are erased
 */
status_t FLASH_VerifyErasePage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*!
 * @brief Verify that the flash sectors are erased
 */
status_t FLASH_VerifyEraseSector(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*!
 * @brief Verify that all flash and IFR space is erased
 */
status_t FLASH_VerifyEraseAll(FMU_Type *base);

/*!
 * @brief Verify that a flash block is erased
 */
status_t FLASH_VerifyEraseBlock(flash_config_t *config, FMU_Type *base, uint32_t blockaddr);

/*!
 * @brief Verify that the ifr phrases are erased
 */
status_t FLASH_VerifyEraseIFRPhrase(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*!
 * @brief Verify that the ifr pages are erased
 */
status_t FLASH_VerifyEraseIFRPage(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*!
 * @brief Verify that the ifr sectors are erased
 */
status_t FLASH_VerifyEraseIFRSector(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);

/*! @} */

/*!
 * @name Properties
 * @{
 */

/*!
 * @brief Returns the desired flash property.
 */
status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);

/*! @} */

/*!
 * @name Read (Main Array or IFR) Into MISR
 * @{
 */

/*!
 * @brief Read into MISR
 *
 * The Read into MISR operation generates a signature based on the contents of the selected
 * flash memory using an embedded MISR.
 */
status_t Read_Into_MISR(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t ending, uint32_t *seed, uint32_t *signature);

/*!
 * @brief Read IFR into MISR
 *
 * The Read IFR into MISR operation generates a signature based on the contents of the
 * selected IFR space using an embedded MISR.
 */
status_t Read_IFR_Into_MISR(
    flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t ending, uint32_t *seed, uint32_t *signature);

/*! @} */

#if defined(SMSCM) || defined(SYSCON_FMC0_CTRL_DFC_MASK)
void flash_cache_disable(void);
void flash_cache_invalidate(void);
#endif
#if defined(SYSCON_FMC0_CTRL_DFC_MASK)
void flash_cache_enable(void);
#endif

#if defined(SMSCM) || defined(SYSCON_FMC0_CTRL_DFS_MASK)
void flash_cache_speculation_control(bool isPreProcess, FMU_Type *base);
#endif

/*******************************************************************************
 * Async Mode API
 ******************************************************************************/

#if defined(CONFIG_FLASH_K4_ASYNC_MODE) && (CONFIG_FLASH_K4_ASYNC_MODE == 1)

/*!
 * @name Async Mode Operations
 * @{
 */

/*!
 * @brief Process pending flash operations.
 *
 * This function should be called from the application's idle task or a low-priority
 * background task. It checks if there are pending operations in the queue and
 * executes them if sufficient LL idle time is available.
 *
 * The function processes at most one operation per call to avoid blocking the
 * idle task for too long.
 *
 * @retval #kStatus_FLASH_Success An operation was processed successfully, or queue is empty.
 * @retval #kStatus_FLASH_Async_NotReady Insufficient idle time; operation deferred.
 * @retval #kStatus_FLASH_Async_NotInit Async context not initialized.
 * @retval Other Flash hardware error codes.
 */
status_t FLASH_Process(void);

/*!
 * @brief Register the LL idle duration callback.
 *
 * This callback is invoked by FLASH_Process() to determine available idle time.
 * Must be registered before any async flash operations can be processed.
 *
 * @param callback Function pointer to the idle duration callback.
 *
 * @retval #kStatus_FLASH_Success Callback registered successfully.
 * @retval #kStatus_FLASH_InvalidArgument NULL callback provided.
 * @retval #kStatus_FLASH_Async_NotInit Async context not initialized.
 */
status_t FLASH_RegisterIdleDurationCB(flash_idle_duration_cb_t callback);

/*!
 * @brief Flush pending operations to make room for a new operation.
 *
 * @param requiredSize Size in bytes required in the buffer pool for the next operation.
 *                     Set to 0 to flush all pending operations.
 *
 * @retval kStatus_FLASH_Success Required space available or all operations flushed.
 * @retval kStatus_FLASH_CommandFailure Async context not initialized.
 * @retval kStatus_FLASH_SizeError Required size exceeds total buffer pool capacity.
 * @retval Other Error from flash operation execution.
 */
status_t FLASH_FlushPendingOperations(uint32_t requiredSize);

/*!
 * @brief Read from flash with pending operation awareness.
 *
 * Reads data from flash and applies any pending write/erase operations
 * to ensure read-after-write consistency.
 *
 * @param address Start address to read from.
 * @param pDst    Pointer to destination buffer.
 * @param length  Number of bytes to read.
 *
 * @retval kStatus_FLASH_Success Read completed successfully.
 * @retval kStatus_FLASH_InvalidArgument Invalid parameters.
 */
status_t FLASH_ReadWithPendingOps(uint32_t address, uint8_t *pDst, uint32_t length);

/*!
 * @brief Deinitialize the async flash context.
 *
 * This function flushes any pending operations and releases async resources.
 * Should be called during system shutdown if needed.
 *
 * @retval #kStatus_FLASH_Success Deinitialization completed successfully.
 */
status_t FLASH_AsyncDeinit(void);

/*! @} */

#endif /* CONFIG_FLASH_K4_ASYNC_MODE */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_K4_FLASH_H_ */
