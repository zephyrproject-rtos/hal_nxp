/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LLC_H_
#define FSL_LLC_H_

#include "fsl_common.h"

/*!
 * @addtogroup llc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief cache driver version. */
#define FSL_LLC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/* Helper: memory barrier order for cache control changes (DSB then ISB) */
#ifndef LLC_BARRIER
#if defined(__ARMCC_VERSION) || defined(__GNUC__) || defined(__ICCARM__)
#define LLC_BARRIER() __DSB()
#else
#define LLC_BARRIER()
#endif
#endif

/*! @brief LLC maintenance operation types. */
typedef enum _llc_maintenance_operation
{
    kLLC_MaintenanceInitValidEntries  = 0U, /*!< Initialize valid entries */
    kLLC_MaintenanceFlushValidEntries = 4U, /*!< Flush valid entries */
    kLLC_MaintenanceFlushEntrySetWay  = 5U, /*!< Flush entry at set and way */
    kLLC_MaintenanceFlushEntryAddress = 6U, /*!< Flush entry at address */
    kLLC_MaintenanceFlushAddressRange = 7U, /*!< Flush address range */
    kLLC_MaintenanceFlushSetWayRange  = 8U, /*!< Flush set way range */
} llc_maintenance_operation_t;

/*! @brief LLC cache override types. */
typedef enum _llc_cache_override
{
    kLLC_CacheOverrideWrite   = 0U,   /*!< Write channel cache override */
    kLLC_CacheOverrideRead    = 1U,   /*!< Read channel cache override */
    kLLC_CacheOverrideDisable = 0xFFU /*!< Disable cache override */
} llc_cache_override_t;

/*! @brief LLC error types. */
typedef enum _llc_error_type
{
    kLLC_ErrorCorrectable           = (1U << 0), /*!< Correctable error */
    kLLC_ErrorUncorrectableMemory   = (1U << 1), /*!< Uncorrectable memory error */
    kLLC_ErrorUncorrectableProtocol = (1U << 2), /*!< Uncorrectable protocol error */
} llc_error_type_t;

/*! @brief LLC event types. */
typedef enum _llc_event_type
{
    kLLC_EventMaintenanceComplete = 0x01U, /*!< Maintenance operation complete */
    kLLC_EventPerformanceMonitor  = 0x10U, /*!< Performance monitor event */
    kLLC_EventAll                 = kLLC_EventMaintenanceComplete | kLLC_EventPerformanceMonitor, /*!< All events */
} llc_event_type_t;

/*! @brief List of LLC interrupts. */
typedef enum _llc_interrupt_enable
{
    kLLC_CorrectableErrorInterruptEnable                        = (1U << 0), /*!< Correctable Error Interrupt */
    kLLC_UncorrectableErrorMemoryProtectionErrorInterruptEnable = (1U << 1), /*!< Uncorrectable Error Interrupt */
    kLLC_UncorrectableErrorProtocolErrorInterruptEnable         = (1U << 2), /*!< Uncorrectable Error Interrupt */
    kLLC_MaintenanceCompletionInterruptEnable                   = (1U << 3), /*!< Maintenance complete interrupt */
    kLLC_PerformanceMonitorInterruptEnable                      = (1U << 4), /*!< Performance monitor interrupt */
    kLLC_AllInterruptsEnable =
        kLLC_CorrectableErrorInterruptEnable | kLLC_UncorrectableErrorMemoryProtectionErrorInterruptEnable |
        kLLC_UncorrectableErrorProtocolErrorInterruptEnable | kLLC_MaintenanceCompletionInterruptEnable |
        kLLC_PerformanceMonitorInterruptEnable /*!< All interrupts */
} llc_interrupt_enable_t;

/*! @brief LLC status flags. */
typedef enum _llc_status_flags
{
    kLLC_CorrectableErrorValidFlag   = (1U << 0),    /*!< Correctable error detected */
    kLLC_UncorrectableErrorValidFlag = (1U << 1),    /*!< Uncorrectable error detected */
    kLLC_MaintenanceCompletionFlag   = (1U << 2),    /*!< Maintenance operation active */
    kLLC_PerformanceMonitorEventFlag = (1U << 3),    /*!< Performance monitor active */
    kLLC_AllFlags = kLLC_CorrectableErrorValidFlag | kLLC_UncorrectableErrorValidFlag | kLLC_MaintenanceCompletionFlag |
                    kLLC_PerformanceMonitorEventFlag /*!< All error valid flags */
} llc_status_flags_t;

/*! @brief LLC cache line size capability. */
typedef enum _llc_cache_line_size
{
    kLLC_CacheLineSize128B = 1U, /*!< 128 bytes */
} llc_cache_line_size_t;

/*! @brief LLC AXI data width capability. */
typedef enum _llc_axi_data_width
{
    kLLC_AxiDataWidth128b  = 2U, /*!< 128 bits */
    kLLC_AxiDataWidth256b  = 3U, /*!< 256 bits */
    kLLC_AxiDataWidth512b  = 4U, /*!< 512 bits */
    kLLC_AxiDataWidth1024b = 5U, /*!< 1024 bits */
} llc_axi_data_width_t;

/*! @brief LLC feature capabilities. */
typedef struct _llc_feature_capability
{
    llc_cache_line_size_t cacheLineSize; /*!< Cache line size capability */
    llc_axi_data_width_t axiDataWidth;   /*!< AXI data width capability */
    bool freeRun;                        /*!< Free run mode capability */
    uint8_t counterWidth;                /*!< Performance counter width capability */
} llc_feature_capability_t;

/*! @brief Version information structure. */
typedef struct _llc_version_info
{
    uint8_t patch; /*!< Patch Version Number. */
    uint8_t minor; /*!< Minor Version Number. */
    uint8_t major; /*!< Major Version Number. */
} llc_version_info_t;

/*! @brief LLC scratchpad configuration structure. */
typedef struct _llc_scratchpad_config
{
    bool enable;          /*!< Enable scratchpad */
    uint8_t numberOfWays; /*!< Number of ways for scratchpad (actual value, not minus 1) */
    uint32_t baseAddress; /*!< Scratchpad base address (cache line aligned) */
    uint32_t size;        /*!< Scratchpad size in cache lines (actual value, not minus 1) */
} llc_scratchpad_config_t;

/*! @brief LLC way partitioning configuration structure. */
typedef struct _llc_way_partition_config
{
    bool enable;       /*!< Enable way partitioning */
    uint8_t agentId;   /*!< Agent ID for way partitioning */
    uint8_t wayVector; /*!< Way enable vector (bit mask) */
} llc_way_partition_config_t;

/*! @brief LLC performance monitor configuration structure. */
typedef struct _llc_performance_config
{
    bool enable;          /*!< Enable performance monitor */
    bool hardwareTrigger; /*!< Enable hardware trigger */
    uint32_t duration;    /*!< Monitor duration in cycles (multiples of 256) */
    uint8_t rttThreshold; /*!< Read transaction table threshold */
    uint8_t wttThreshold; /*!< Write transaction table threshold */
} llc_performance_config_t;

/*! @brief LLC configuration structure. */
typedef struct _llc_config
{
    bool enableErrorDetection;                 /*!< Enable error detection */
    bool enableWriteAllocPartial;              /*!< Enable partial write allocation */
    llc_scratchpad_config_t *scratchpadConfig; /*!< Scratchpad configuration (NULL if not used) */
} llc_config_t;

/*! @brief LLC error status structure. */
typedef struct _llc_error_status
{
    /* Correctable error status */
    bool correctableErrorValid;    /*!< Correctable error detected */
    uint8_t correctableErrorType;  /*!< Correctable error type */
    uint16_t correctableErrorInfo; /*!< Correctable error info */
    uint32_t correctableErrorLoc0; /*!< Correctable error location 0 */
    uint32_t correctableErrorLoc1; /*!< Correctable error location 1 */

    /* Uncorrectable error status */
    bool uncorrectableErrorValid;    /*!< Uncorrectable error detected */
    uint8_t uncorrectableErrorType;  /*!< Uncorrectable error type */
    uint32_t uncorrectableErrorInfo; /*!< Uncorrectable error info */
    uint32_t uncorrectableErrorLoc0; /*!< Uncorrectable error location 0 */
    uint32_t uncorrectableErrorLoc1; /*!< Uncorrectable error location 1 */
} llc_error_status_t;

/*! @brief LLC performance monitor counters structure. */
typedef struct _llc_performance_counters
{
    uint32_t cycleCounter;             /*!< Cycle counter */
    uint32_t readRequestCounter;       /*!< Read request counter */
    uint32_t writeRequestCounter;      /*!< Write request counter */
    uint32_t cacheableReadCounter;     /*!< Cacheable read request counter */
    uint32_t cacheableWriteCounter;    /*!< Cacheable write request counter */
    uint32_t readHitCounter;           /*!< Read hit counter */
    uint32_t writeHitCounter;          /*!< Write hit counter */
    uint32_t evictionCounter;          /*!< Eviction counter */
    uint32_t readBeatCounter;          /*!< Read beat counter */
    uint32_t writeBeatCounter;         /*!< Write beat counter */
    uint32_t rttAboveThresholdCounter; /*!< RTT above threshold counter */
    uint32_t wttAboveThresholdCounter; /*!< WTT above threshold counter */
} llc_performance_counters_t;

/*! @brief Callback type when registering for a callback. */
typedef enum
{
    kLLC_CorrectableErrorCallback,      /*!< Correctable error interrupt callback */
    kLLC_UncorrectableErrorCallback,    /*!< Uncorrectable error interrupt callback */
    kLLC_MaintenanceCompletionCallback, /*!< Maintenance completion interrupt callback */
    kLLC_PerformanceMonitorCallback,    /*!< Performance monitor interrupt callback */
} llc_callback_type_t;

/*!
 * @brief LLC callback function.
 *
 * The registered callback is invoked once for each asserted event flag
 * detected in the LLC interrupt handler. If multiple events occur in the
 * same interrupt (e.g. a correctable error and a maintenance completion),
 * the handler will call the callback multiple times sequentially—one call
 * per @ref llc_callback_type_t value—using the following order of
 * precedence:
 * 1. kLLC_CorrectableErrorCallback
 * 2. kLLC_UncorrectableErrorCallback
 * 3. kLLC_MaintenanceCompletionCallback
 * 4. kLLC_PerformanceMonitorCallback
 *
 * This preserves backward compatibility for simple single-event users
 * while eliminating silent loss of additional simultaneous events.
 */
typedef void (*llc_callback_t)(llc_callback_type_t type);

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name LLC Control
 * @{
 */

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the LLC configuration structure to default values.
 * The default values are:
 * @code
 *  config->enableErrorDetection    = true;
 *  config->enableWriteAllocPartial = true;
 *  config->scratchpadConfig        = NULL;
 * @endcode
 *
 * @param config Pointer to configuration structure.
 */
void LLC_GetDefaultConfig(llc_config_t *config);

/*!
 * @brief Initializes the LLC module.
 *
 * This function configures the LLC module with user-defined settings.
 * It initializes the tag and data arrays and configures basic settings.
 *
 * @param base LLC peripheral base address.
 * @param config Pointer to configuration structure.
 * @return kStatus_Success LLC initialization succeeded.
 * @return kStatus_InvalidArgument Invalid argument provided.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_Init(LLC_Type *base, const llc_config_t *config);

/*!
 * @brief Enables the LLC.
 *
 * This function enables cache lookup and fill operations.
 *
 * @param base LLC peripheral base address.
 */
void LLC_EnableCache(LLC_Type *base);

/*!
 * @brief Disables the LLC.
 *
 * This function disables cache lookup and fill operations.
 *
 * @param base LLC peripheral base address.
 */
void LLC_DisableCache(LLC_Type *base);

/*!
 * @brief Gets the LLC version.
 *
 * @param base LLC peripheral base address.
 * @param versionInfo Pointer to version information structure.
 */
void LLC_GetVersion(LLC_Type *base, llc_version_info_t *versionInfo);

/*!
 * @brief Gets LLC feature capabilities.
 *
 * @param base LLC peripheral base address.
 * @param feature Pointer to feature capability to query.
 */
void LLC_GetCapabilities(LLC_Type *base, llc_feature_capability_t *feature);

/*! @} */

/*!
 * @name LLC Cache Operations
 * @{
 */

/*!
 * @brief Cleans and invalidates the entire cache.
 *
 * This operation evicts all dirty line and invalidates all lines from ways designed as valid
 * by the CCUCMWVR register in the cache and leaves all entries of these valid ways in an invalid state.
 *
 * @param base LLC peripheral base address.
 * @return kStatus_Success Cache invalidation succeeded.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCache(LLC_Type *base);

/*!
 * @brief Cleans and invalidates cache at specific set and way.
 *
 * This API evicts a dirty line. It invalidates all lines at the specified physical set and way in the cache.
 * It leaves the entry in the invalid state.
 *
 * @param base LLC peripheral base address.
 * @param set Cache set index, starting from 0.
 * @param way Cache way index, starting from 0.
 * @return kStatus_Success Cache invalidation succeeded.
 * @return kStatus_InvalidArgument Invalid set or way.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtSetAndWay(LLC_Type *base, uint16_t set, uint8_t way);

/*!
 * @brief Cleans and invalidates cache at address.
 *
 * This operation evicts a dirty line and invalidates all lines matching the specified address,
 * if any, in the cache and leaves the entry in the invalid state.
 *
 * @param base LLC peripheral base address.
 * @param address Low 32 bits cache line address to invalidate.
 * @return kStatus_Success Cache invalidation succeeded.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtAddress(LLC_Type *base, uint32_t address);

/*!
 * @brief Cleans and invalidates cache at address range.
 *
 * This operation evicts a dirty line and invalidates all lines matching the specified address,
 * if any, in the cache and leaves the entry in the invalid state.
 *
 * @param base LLC peripheral base address.
 * @param address Low 32 bits starting cache line address to invalidate.
 * @param sizeInCacheLines Number of cache lines to invalidate.
 * @return kStatus_Success Cache invalidation succeeded.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtAddressRange(LLC_Type *base, uint32_t address, uint16_t sizeInCacheLines);

/*!
 * @brief Cleans and invalidates cache at set and way range.
 *
 * This operation evicts all dirty lines and invalidates all lines within the specified physical
 * set and way range in the cache.
 *
 * @param base LLC peripheral base address.
 * @param set Starting cache set index.
 * @param way Starting cache way index.
 * @param sizeInCacheLines Number of cache lines to invalidate.
 * @return kStatus_Success Cache invalidation succeeded.
 * @return kStatus_InvalidArgument Invalid parameters.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheAtSetWayRange(LLC_Type *base, uint16_t set, uint8_t way, uint16_t sizeInCacheLines);

/*!
 * @brief Cleans and invalidates cache by range using physical address.
 *
 * This API uses the physical address to locate the corresponding LLC instance,
 * aligns the range to cache line boundaries, and issues one or more address-range
 * maintenance operations to invalidate the requested memory region.
 *
 * The operation evicts any dirty lines in the affected range (write-back) and
 * invalidates them.
 *
 * @param address   The physical start address.
 * @param sizeByte  Size of the memory to be invalidated in bytes. Must be > 0. Better to align to cache line size.
 * @return kStatus_Success Cache invalidation succeeded.
 * @return kStatus_InvalidArgument Invalid parameters.
 * @return kStatus_Timeout Maintenance operation timeout.
 */
status_t LLC_CleanInvalidateCacheByRange(uint32_t address, uint32_t sizeByte);

/*! @} */

/*!
 * @name LLC Scratchpad Operations
 * @{
 */

/*!
 * @brief Configures the scratchpad.
 *
 * @param base LLC peripheral base address.
 * @param config Pointer to scratchpad configuration.
 * @return kStatus_Success Scratchpad configuration succeeded.
 * @return kStatus_InvalidArgument Invalid configuration.
 */
status_t LLC_ConfigScratchpad(LLC_Type *base, const llc_scratchpad_config_t *config);

/*! @} */

/*!
 * @name LLC Cache Override Operations
 * @{
 */

/*!
 * @brief Sets cache override configuration.
 *
 * @param base LLC peripheral base address.
 * @param overrideType Type of cache override to configure.
 * @param overrideValue Cache override value (AxCACHE bits).
 * @return kStatus_Success Cache override configuration succeeded.
 * @return kStatus_InvalidArgument Invalid parameters.
 */
status_t LLC_SetCacheOverride(LLC_Type *base, llc_cache_override_t overrideType, uint8_t overrideValue);

/*! @} */

/*!
 * @name LLC Way Partitioning Operations
 * @{
 */

/*!
 * @brief Configures way partitioning.
 *
 * @param base LLC peripheral base address.
 * @param partitionIndex Way partition control register set index (0-7).
 * @param config Pointer to way partitioning configuration.
 * @return kStatus_Success Way partitioning configuration succeeded.
 * @return kStatus_InvalidArgument Invalid parameters.
 */
status_t LLC_ConfigWayPartition(LLC_Type *base, uint8_t partitionIndex, const llc_way_partition_config_t *config);

/*! @} */

/*!
 * @name LLC Error Management
 * @{
 */

/*!
 * @brief Enables or disables error detection.
 *
 * @param base LLC peripheral base address.
 * @param errorType Type of error detection to configure.
 * @param enable True to enable, false to disable.
 * @return kStatus_Success Error detection configuration succeeded.
 * @return kStatus_InvalidArgument Invalid error type.
 */
status_t LLC_EnableErrorDetection(LLC_Type *base, llc_error_type_t errorType, bool enable);

/*!
 * @brief Gets error status.
 *
 * Note: errorStatus->correctableErrorValid and errorStatus->uncorrectableErrorValid
 * reflect the same hardware bits exposed as status flags by LLC_GetStatusFlags().
 * Prefer LLC_GetStatusFlags() for quick checks; use this API for full details.
 *
 * @param base LLC peripheral base address.
 * @param errorStatus Pointer to error status structure.
 * @return kStatus_Success Error status retrieved successfully.
 * @return kStatus_InvalidArgument Invalid argument.
 */
status_t LLC_GetErrorStatus(LLC_Type *base, llc_error_status_t *errorStatus);

/*! @} */

/*!
 * @name LLC Interrupt Interfaces
 * @{
 */

/*!
 * @brief Set Error Threshold
 *
 * Set the number of correctable errors that must be corrected before the correctable
 * error interrupt output signal (IRQ_C_LEVEL) is asserted.
 */
void LLC_SetCorrectableErrorInterruptThreshold(LLC_Type *base, uint8_t threshold)
{
    assert(base != NULL);
    base->CCUCECR = (base->CCUCECR & ~LLC_CCUCECR_ERRTHRESHOLD_MASK) | LLC_CCUCECR_ERRTHRESHOLD(threshold);
}

/*!
 * @brief Enable LLC interrupts.
 *
 * @param base LLC peripheral base address.
 * @param mask Mask of interrupts to enable. This is a logical OR of members of the
 *             enumeration ::llc_interrupt_enable_t
 */
void LLC_EnableInterrupts(LLC_Type *base, uint32_t mask);

/*!
 * @brief Disable LLC interrupts.
 *
 * @param base LLC peripheral base address.
 * @param mask Mask of interrupts to disable. This is a logical OR of members of the
 *             enumeration ::llc_interrupt_enable_t
 */
void LLC_DisableInterrupts(LLC_Type *base, uint32_t mask);

/*!
 * @brief Gets enabled LLC interrupts.
 *
 * @param base LLC peripheral base address.
 * @return Mask of enabled interrupts. This is a logical OR of members of the
 *         enumeration ::llc_interrupt_enable_t
 */
uint32_t LLC_GetEnabledInterrupts(LLC_Type *base);

/*! @} */

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Gets LLC status flags.
 *
 * Note: The error-valid flags reported here (kLLC_CorrectableErrorValidFlag and
 * kLLC_UncorrectableErrorValidFlag) mirror the corresponding fields returned by
 * LLC_GetErrorStatus(). Use this function for a quick poll; call LLC_GetErrorStatus()
 * when you need detailed error information.
 *
 * @param base LLC peripheral base address.
 * @return LLC status flags. This is a logical OR of members of the
 *         enumeration ::llc_status_flags_t
 */
uint32_t LLC_GetStatusFlags(LLC_Type *base);

/*!
 * @brief Clears LLC status flags.
 *
 * @param base LLC peripheral base address.
 * @param mask Mask of status flags to clear. This is a logical OR of members of the
 *             enumeration ::llc_status_flags_t
 */
void LLC_ClearStatusFlags(LLC_Type *base, uint32_t mask);

/*! @} */

/*!
 * @name LLC Performance Monitor Operations
 * @{
 */

/*!
 * @brief Initializes performance monitor.
 *
 * @param base LLC peripheral base address.
 * @param config Pointer to performance monitor configuration.
 * @return kStatus_Success Performance monitor initialization succeeded.
 * @return kStatus_InvalidArgument Invalid configuration.
 */
status_t LLC_InitPerformanceMonitor(LLC_Type *base, const llc_performance_config_t *config);

/*!
 * @brief Starts performance monitoring.
 *
 * @param base LLC peripheral base address.
 */
void LLC_StartPerformanceMonitor(LLC_Type *base);

/*!
 * @brief Stops performance monitoring.
 *
 * @param base LLC peripheral base address.
 */
void LLC_StopPerformanceMonitor(LLC_Type *base);

/*!
 * @brief Resets performance monitor counters.
 *
 * @param base LLC peripheral base address.
 */
void LLC_ResetPerformanceCounters(LLC_Type *base);

/*!
 * @brief Gets performance monitor counters.
 *
 * @param base LLC peripheral base address.
 * @param counters Pointer to performance counters structure.
 * @return kStatus_Success Performance counters retrieved successfully.
 * @return kStatus_InvalidArgument Invalid argument.
 */
status_t LLC_GetPerformanceCounters(LLC_Type *base, llc_performance_counters_t *counters);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_LLC_H_ */
